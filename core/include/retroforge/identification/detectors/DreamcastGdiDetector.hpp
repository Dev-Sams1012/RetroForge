#pragma once

#include "retroforge/identification/IContainerDetector.hpp"

namespace retroforge::identification::detectors {

class DreamcastGdiDetector : public IContainerDetector {
  public:
    bool matches(const std::filesystem::path &caminho) const override;
    Console console() const override { return Console::Dreamcast; }
};

} // namespace retroforge::identification::detectors
