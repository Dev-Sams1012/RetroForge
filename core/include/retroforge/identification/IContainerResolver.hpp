#pragma once

#include <filesystem>
#include <optional>

namespace retroforge::identification {

class IContainerResolver {
  public:
    virtual ~IContainerResolver() = default;
    virtual std::optional<std::filesystem::path>
    resolve(const std::filesystem::path &caminho) const = 0;
};

} // namespace retroforge::identification