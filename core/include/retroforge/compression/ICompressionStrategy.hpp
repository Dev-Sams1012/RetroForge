#pragma once

#include "retroforge/models/ConversionJob.hpp"

#include <memory>

namespace retroforge::compression {

class ICompressionStrategy {
  public:
    virtual ~ICompressionStrategy() = default;

    virtual bool comprimir(const std::shared_ptr<models::ConversionJob> &job) = 0;

    virtual std::string extensao_saida() const = 0;
};

} // namespace retroforge::compression