#include "retroforge/identification/detectors/PbpDetector.hpp"

namespace retroforge::identification::detectors {

bool PbpDetector::matches(const std::vector<uint8_t> &cabecalho) const {
    if (cabecalho.size() < 4) {
        return false;
    }

    return cabecalho[0] == 0x00 && cabecalho[1] == 0x50 && // 'P'
           cabecalho[2] == 0x42 &&                         // 'B'
           cabecalho[3] == 0x50;                           // 'P'
}

} // namespace retroforge::identification::detectors