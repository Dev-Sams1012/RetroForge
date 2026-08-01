#pragma once

#include "retroforge/compression/ICompressionStrategy.hpp"

namespace retroforge::compression::converters {

class MaxcsoConverter : public ICompressionStrategy {
  public:
    bool comprimir(const std::shared_ptr<models::ConversionJob> &job) override;
    std::string extensao_saida() const override { return ".cso"; }
};

} // namespace retroforge::compression::converters