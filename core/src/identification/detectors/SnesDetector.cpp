#include "retroforge/identification/detectors/SnesDetector.hpp"

namespace retroforge::identification::detectors {

bool SnesDetector::matches(const std::filesystem::path &caminho) const {
    std::string ext = caminho.extension().string();
    return ext == ".smc" || ext == ".sfc";
}

} // namespace retroforge::identification::detectors