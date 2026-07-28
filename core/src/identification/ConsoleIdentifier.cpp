#include "retroforge/identification/ConsoleIdentifier.hpp"

namespace retroforge::identification {
void ConsoleIdentifier::register_detector(std::unique_ptr<IConsoleDetector> detector) {
    detectores_.push_back(std ::move(detector));
}

Console ConsoleIdentifier::identify(retroforge::io::BinaryFileReader &leitor) const {
    auto cabecalho = leitor.read_at(0, TAMANHO_CABECALHO);

    for (const auto &detector : detectores_) {
        if (detector->matches(cabecalho)) {
            return detector->console();
        }
    }

    return Console::Desconhecido;
}

} // namespace retroforge::identification