// Arquivo : core / src / compression / converters / LibzipPacker . cpp
#include "retroforge/compression/converters/LibzipPacker.hpp"

#include <filesystem>
#include <iostream>
#include <memory>

#include <zip.h>

namespace retroforge::compression::converters {

namespace fs = std::filesystem;

namespace {

struct ZipDiscardDeleter {
    void operator()(zip_t *z) const {
        if (z) {
            zip_discard(z);
        }
    }
};
using ScopedZipHandle = std::unique_ptr<zip_t, ZipDiscardDeleter>;

} // namespace

bool LibzipPacker::comprimir(const std::shared_ptr<models::ConversionJob> &job) {
    fs::path origem(job->caminho_origem());
    fs::path destino = origem;

    destino.replace_extension(".zip");

    int codigo_erro = 0;

#if defined(_WIN32)
    std::string str_destino = reinterpret_cast<const char *>(destino.u8string().c_str());
    std::string str_origem = reinterpret_cast<const char *>(origem.u8string().c_str());
    std::string str_nome_arquivo =
        reinterpret_cast<const char *>(origem.filename().u8string().c_str());
#else
    std::string str_destino = destino.string();
    std::string str_origem = origem.string();
    std::string str_nome_arquivo = origem.filename().string();
#endif

    ScopedZipHandle zip_guard(
        zip_open(str_destino.c_str(), ZIP_CREATE | ZIP_TRUNCATE, &codigo_erro));

    if (!zip_guard) {
        std::cerr << "Falha ao criar .zip (codigo libzip: " << codigo_erro << ")\n";
        return false;
    }

    auto *fonte = zip_source_file(zip_guard.get(), str_origem.c_str(), 0, 0);

    if (!fonte) {
        std::cerr << "Falha ao ler arquivo de origem para empacotamento.\n";
        return false;
    }

    if (zip_file_add(zip_guard.get(), str_nome_arquivo.c_str(), fonte, ZIP_FL_OVERWRITE) < 0) {
        zip_source_free(fonte);
        std::cerr << "Falha ao adicionar arquivo dentro do .zip.\n";
        return false;
    }

    zip_t *zip_raw = zip_guard.release();

    if (zip_close(zip_raw) < 0) {
        std::cerr << "Falha ao gravar arquivo .zip no disco.\n";
        return false;
    }

    job->set_progresso(100);
    return true;
}

} // namespace retroforge::compression::converters