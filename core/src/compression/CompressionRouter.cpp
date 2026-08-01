#include "retroforge/compression/CompressionRouter.hpp"

namespace retroforge::compression {

using models::Console;

void CompressionRouter::register_strategy(Console console,
                                          std::shared_ptr<ICompressionStrategy> estrategia) {
    estrategias_[console] = std::move(estrategia);
}

ResultadoRoteamento CompressionRouter::rotear(const std::shared_ptr<models::ConversionJob> &job) {
    if (job->console_alvo() == Console::DreamcastModificado ||
        job->console_alvo() == Console::PSP_PBP) {
        return ResultadoRoteamento::BloqueadoPorSeguranca;
    }

    auto encontrado = estrategias_.find(job->console_alvo());
    if (encontrado == estrategias_.end()) {
        return ResultadoRoteamento::ConsoleNaoSuportado;
    }

    bool sucesso = encontrado->second->comprimir(job);
    return sucesso ? ResultadoRoteamento::ConversaoIniciada
                   : ResultadoRoteamento::ConsoleNaoSuportado;
}

} // namespace retroforge::compression