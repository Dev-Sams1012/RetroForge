#pragma once

#include <cstdint>
#include <fstream>
#include <string>
#include <vector>

namespace retroforge::io {

class BinaryFileReader {
  public:
    explicit BinaryFileReader(const std::string &caminho);

    std::vector<uint8_t> read_at(std::streamoff offset, size_t quantidade);

    std::vector<uint8_t> read_next_chunk(size_t tamanho_maximo);

    bool eof() const;
    std::uintmax_t tamanho_total() const { return tamanho_total_; }

  private:
    std::ifstream arquivo_;
    std::uintmax_t tamanho_total_;
};

} // namespace retroforge::io
