#include "retroforge/identification/ConsoleIdentifier.hpp"
#include "retroforge/io/BinaryFileReader.hpp"

namespace retroforge::identification {

void ConsoleIdentifier::register_detector(std::unique_ptr<IConsoleDetector> detector) {
    detectores_binarios_.push_back(std::move(detector));
}

void ConsoleIdentifier::register_container_detector(std::unique_ptr<IContainerDetector> detector) {
    detectores_de_conteiner_.push_back(std::move(detector));
}

void ConsoleIdentifier::register_container_resolver(std::unique_ptr<IContainerResolver> detector) {
    resolvedores_de_conteiner_.push_back(std::move(detector));
}

Console ConsoleIdentifier::identify(const std::filesystem::path &caminho) const {
    for (const auto &detector : detectores_de_conteiner_) {
        if (detector->matches(caminho)) {
            return detector->console();
        }
    }

    std::filesystem::path caminho_binario = caminho;
    for (const auto &resolver : resolvedores_de_conteiner_) {
        if (auto resolvido = resolver->resolve(caminho)) {
            caminho_binario = *resolvido;
            break;
        }
    }

    try {
        retroforge::io::BinaryFileReader leitor(caminho_binario.string());
        auto cabecalho = leitor.read_at(0, TAMANHO_CABECALHO);

        for (const auto &detector : detectores_binarios_) {
            if (detector->matches(cabecalho)) {
                return detector->console();
            }
        }
    } catch (const std::exception &) {
        return Console::Desconhecido;
    }

    return Console::Desconhecido;
}

} // namespace retroforge::identification
