#pragma once

#include "retroforge/models/Console.hpp"

#include <cstdint>
#include <vector>

namespace retroforge::identification {

using retroforge::models::Console;

class IConsoleDetector {

  public:
    virtual ~IConsoleDetector() = default;
    virtual bool matches(const std::vector<uint8_t> &cabecalho) const = 0;
    virtual Console console() const = 0;
};

} // namespace retroforge::identification