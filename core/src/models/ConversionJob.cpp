#include "retroforge/models/ConversionJob.hpp"

namespace retroforge::models {

ConversionJob::ConversionJob(std::string caminho_origem, Console console_alvo)
    : caminho_origem_(std::move(caminho_origem)), console_alvo_(console_alvo) {}

} // namespace retroforge::models