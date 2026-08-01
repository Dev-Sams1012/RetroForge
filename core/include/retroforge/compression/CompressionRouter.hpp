#pragma once

#include "retroforge/compression/ICompressionStrategy.hpp"
#include "retroforge/models/Console.hpp"
#include "retroforge/models/ConversionJob.hpp"
#include <memory>
#include <unordered_map>

namespace retroforge::compression {

enum class ResultadoRoteamento { ConversaoIniciada, BloqueadoPorSeguranca, ConsoleNaoSuportado };

class CompressionRouter {
  public:
    void register_strategy(models::Console console,
                           std::shared_ptr<ICompressionStrategy> estrategia);
    ResultadoRoteamento rotear(const std::shared_ptr<models::ConversionJob> &job);

  private:
    std::unordered_map<models::Console, std::shared_ptr<ICompressionStrategy>> estrategias_;
};

} // namespace retroforge::compression