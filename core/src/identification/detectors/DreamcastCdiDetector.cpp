#include "retroforge/identification/detectors/DreamcastCdiDetector.hpp"

namespace retroforge::identification::detectors {

bool DreamcastCdiDetector::matches(const std::filesystem::path &caminho) const {
    return caminho.extension() == ".cdi";
}

} // namespace retroforge::identification::detectors