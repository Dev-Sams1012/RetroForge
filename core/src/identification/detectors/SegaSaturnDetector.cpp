#include "retroforge/identification/detectors/SegaSaturnDetector.hpp"

#include <algorithm>
#include <string_view>

namespace retroforge::identification::detectors {

bool SegaSaturnDetector::matches(const std::vector<uint8_t> &cabecalho) const {
    static constexpr std::string_view ASSINATURA = "SEGASATURN";

    if (cabecalho.empty()) {
        return false;
    }

    return std::search(cabecalho.begin(), cabecalho.end(), ASSINATURA.begin(), ASSINATURA.end()) !=
           cabecalho.end();
}

} // namespace retroforge::identification::detectors