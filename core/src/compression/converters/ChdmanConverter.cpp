#include "retroforge/compression/converters/ChdmanConverter.hpp"

#include "retroforge/process/ExternalProcessHandle.hpp"

#include <exception>
#include <filesystem>
#include <iostream>

namespace retroforge::compression::converters {

namespace fs = std::filesystem;

bool ChdmanConverter::comprimir(const std::shared_ptr<models::ConversionJob> &job) {
    fs::path origem(job->caminho_origem());
    fs::path destino = origem;
    destino.replace_extension(".chd");

    std::string comando =
        "chdman createcd -i \"" + origem.string() + "\" -o \"" + destino.string() + "\"";

    try {
        process::ExternalProcessHandle processo(comando);

        std::string linha;
        while (processo.read_line(linha)) {
            if (job->is_cancelado()) {
                return false;
            }
        }

        job->set_progresso(100);
        return true;

    } catch (const std::exception &erro) {
        std::cerr << "Falha ao converter via chdman: " << erro.what() << "\n";
        return false;
    }
}

} // namespace retroforge::compression::converters