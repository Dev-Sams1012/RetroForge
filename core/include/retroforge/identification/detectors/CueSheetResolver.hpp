#pragma once

#include "retroforge/identification/IContainerResolver.hpp"

namespace retroforge::identification::detectors {

class CueSheetResolver : public IContainerResolver {
  public:
    std::optional<std::filesystem::path>
    resolve(const std::filesystem::path &caminho) const override;
};

} // namespace retroforge::identification::detectors