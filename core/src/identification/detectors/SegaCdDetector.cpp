#include "retroforge/identification/detectors/SegaCdDetector.hpp"

#include <algorithm>
#include <string_view>

namespace retroforge::identification::detectors {

bool SegaCdDetector::matches(const std::vector<uint8_t> &cabecalho) const {
    static constexpr std::string_view ASSINATURA = "SEGADISCSYSTEM";

    if (cabecalho.empty()) {
        return false;
    }

    return std::search(cabecalho.begin(), cabecalho.end(), ASSINATURA.begin(), ASSINATURA.end()) !=
           cabecalho.end();
}

} // namespace retroforge::identification::detectors
