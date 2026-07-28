#include "retroforge/io/BinaryFileReader.hpp"

#include <filesystem>
#include <stdexcept>

namespace retroforge::io {

BinaryFileReader::BinaryFileReader(const std::string &caminho)
    : arquivo_(caminho, std::ios::in | std::ios::binary), tamanho_total_(0) {

    if (!arquivo_.is_open()) {
        throw std::runtime_error(" Nao foi possivel abrir : " + caminho);
    }

    tamanho_total_ = std::filesystem::file_size(caminho);
}

std::vector<uint8_t> BinaryFileReader::read_at(std::streamoff offset, size_t quantidade) {
    arquivo_.clear();
    arquivo_.seekg(offset, std::ios::beg);

    std::vector<uint8_t> buffer(quantidade);

    arquivo_.read(reinterpret_cast<char *>(buffer.data()),
                  static_cast<std::streamsize>(quantidade));
    buffer.resize(static_cast<size_t>(arquivo_.gcount()));

    return buffer;
}

std::vector<uint8_t> BinaryFileReader::read_next_chunk(size_t tamanho_maximo) {
    std::vector<uint8_t> buffer(tamanho_maximo);

    arquivo_.read(reinterpret_cast<char *>(buffer.data()),
                  static_cast<std::streamsize>(tamanho_maximo));
    buffer.resize(static_cast<size_t>(arquivo_.gcount()));

    return buffer;
}

bool BinaryFileReader::eof() const { return arquivo_.eof(); }

} // namespace retroforge::io
