#include "retroforge/identification/detectors/PspDetector.hpp"

#include <algorithm>
#include <string_view>

namespace retroforge::identification::detectors {

bool PspDetector::matches(const std::vector<uint8_t> &cabecalho) const {
    static constexpr std::string_view UMD_DATA = "UMD_DATA.BIN";

    if (cabecalho.empty()) {
        return false;
    };

    bool tem_umd_data = std::search(cabecalho.begin(), cabecalho.end(), UMD_DATA.begin(),
                                    UMD_DATA.end()) != cabecalho.end();

    return tem_umd_data;
}

} // namespace retroforge::identification::detectors
