#pragma once

#include "retroforge/identification/IConsoleDetector.hpp"

namespace retroforge::identification::detectors {

class Ps1Detector : public IConsoleDetector {
  public:
    bool matches(const std::vector<uint8_t> &cabecalho) const override;
    Console console() const override { return Console::PS1; }
};

} // namespace retroforge::identification::detectors
