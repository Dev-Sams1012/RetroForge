#pragma once

#include "retroforge/compression/CompressionRouter.hpp"

namespace retroforge::bootstrap {

class CompressionEngineFactory {
  public:
    static compression::CompressionRouter criar();
};

} // namespace retroforge::bootstrap