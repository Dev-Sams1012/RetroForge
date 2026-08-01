#pragma once

#include "retroforge/models/Console.hpp"

#include <atomic>
#include <string>

namespace retroforge::models {

class ConversionJob {
  public:
    ConversionJob(std::string caminho_origem, Console console_alvo);

    const std::string &caminho_origem() const { return caminho_origem_; };
    Console console_alvo() const { return console_alvo_; }

    void set_progresso(int progresso) { progresso_.store(progresso); };
    int progresso() { return progresso_.load(); };

    void cancelar() { cancelado_.store(true); };
    bool is_cancelado() { return cancelado_.load(); };

  private:
    std::string caminho_origem_;
    Console console_alvo_;
    std::atomic<int> progresso_{0};
    std::atomic<bool> cancelado_{false};
};

} // namespace retroforge::models