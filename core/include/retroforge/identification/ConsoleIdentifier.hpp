#pragma once

#include "retroforge/identification/IConsoleDetector.hpp"
#include "retroforge/identification/IContainerDetector.hpp"
#include "retroforge/identification/IContainerResolver.hpp"

#include <filesystem>
#include <memory>

namespace retroforge::identification {

class ConsoleIdentifier {
  public:
    void register_detector(std::unique_ptr<IConsoleDetector> detector);
    void register_container_detector(std::unique_ptr<IContainerDetector> detector);
    void register_container_resolver(std::unique_ptr<IContainerResolver> resolver);

    Console identify(const std::filesystem::path &caminho) const;

  private:
    static constexpr size_t TAMANHO_CABECALHO = 4 * 1024 * 1024;
    std::vector<std::unique_ptr<IConsoleDetector>> detectores_binarios_;
    std::vector<std::unique_ptr<IContainerDetector>> detectores_de_conteiner_;
    std::vector<std::unique_ptr<IContainerResolver>> resolvedores_de_conteiner_;
};

} // namespace retroforge::identification
