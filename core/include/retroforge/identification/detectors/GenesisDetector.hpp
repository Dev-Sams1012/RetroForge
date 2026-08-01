#pragma once

#include "retroforge/identification/IConsoleDetector.hpp"

namespace retroforge::identification::detectors {

class GenesisDetector : public IConsoleDetector {
  public:
    bool matches(const std::vector<uint8_t> &cabecalho) const override;
    Console console() const override { return Console::Genesis; }
};

} // namespace retroforge::identification::detectors
