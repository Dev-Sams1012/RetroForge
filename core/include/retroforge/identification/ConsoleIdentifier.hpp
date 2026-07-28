#pragma once

#include "retroforge/identification/IConsoleDetector.hpp"
#include "retroforge/io/BinaryFileReader.hpp"

#include <memory>

namespace retroforge::identification {

class ConsoleIdentifier {
  public:
    void register_detector(std::unique_ptr<IConsoleDetector> detector);
    Console identify(retroforge::io::BinaryFileReader &leitor) const;

  private:
    static constexpr size_t TAMANHO_CABECALHO = 32;
    std::vector<std::unique_ptr<IConsoleDetector>> detectores_;
};

} // namespace retroforge::identification
