#include "retroforge/identification/detectors/Ps2Detector.hpp"

#include <algorithm>
#include <string_view>

namespace retroforge::identification::detectors {

bool Ps2Detector::matches(const std::vector<uint8_t> &cabecalho) const {
    static constexpr std::string_view SYSTEM_CNF = "SYSTEM.CNF";
    static constexpr std::string_view BOOT2 = "BOOT2";

    if (cabecalho.empty()) {
        return false;
    };

    bool tem_system_cnf = std::search(cabecalho.begin(), cabecalho.end(), SYSTEM_CNF.begin(),
                                      SYSTEM_CNF.end()) != cabecalho.end();

    bool tem_boot2 = std::search(cabecalho.begin(), cabecalho.end(), BOOT2.begin(), BOOT2.end()) !=
                     cabecalho.end();

    return tem_system_cnf && tem_boot2;
}

} // namespace retroforge::identification::detectors
