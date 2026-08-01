#pragma once

#include "retroforge/compression/ICompressionStrategy.hpp"

namespace retroforge::compression::converters {

class DolphinToolConverter : public ICompressionStrategy {
  public:
    bool comprimir(const std::shared_ptr<models::ConversionJob> &job) override;
    std::string extensao_saida() const override { return ".rvz"; }
};

} // namespace retroforge::compression::converters