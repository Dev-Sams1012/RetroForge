#pragma once

#include "retroforge/identification/IConsoleDetector.hpp"

namespace retroforge::identification::detectors {

class GameCubeDetector : public IConsoleDetector {
  public:
    bool matches(const std::vector<uint8_t> &cabecalho) const override;
    Console console() const override { return Console::GameCube; }
};

} // namespace retroforge::identification::detectors