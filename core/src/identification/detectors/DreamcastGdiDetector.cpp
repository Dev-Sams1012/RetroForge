#include "retroforge/identification/detectors/DreamcastGdiDetector.hpp"

namespace retroforge::identification::detectors {

bool DreamcastGdiDetector::matches(const std::filesystem::path &caminho) const {
    return caminho.extension() == ".gdi";
}

} // namespace retroforge::identification::detectors