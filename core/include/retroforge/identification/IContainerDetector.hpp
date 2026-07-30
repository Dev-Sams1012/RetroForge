#pragma once

#include "retroforge/models/Console.hpp"

#include <filesystem>

namespace retroforge::identification {

using retroforge::models::Console;

class IContainerDetector {
  public:
    virtual ~IContainerDetector() = default;
    virtual bool matches(const std::filesystem::path &caminho) const = 0;
    virtual Console console() const = 0;
};

} // namespace retroforge::identification