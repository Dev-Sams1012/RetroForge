#pragma once

#include "retroforge/identification/IConsoleDetector.hpp"

namespace retroforge::identification::detectors {

class PbpDetector : public IConsoleDetector {
  public:
    bool matches(const std::vector<uint8_t> &cabecalho) const override;
    Console console() const override { return Console::PSP_PBP; }
};

} // namespace retroforge::identification::detectors
