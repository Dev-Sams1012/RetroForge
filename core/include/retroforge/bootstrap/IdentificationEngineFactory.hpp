#pragma once

#include "retroforge/identification/ConsoleIdentifier.hpp"

namespace retroforge::bootstrap {

class IdentificationEngineFactory {
  public:
    static identification::ConsoleIdentifier criar();
};

} // namespace retroforge::bootstrap