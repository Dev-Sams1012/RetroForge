#include "retroforge/identification/detectors/GenesisDetector.hpp"

#include <cstring>
#include <vector>

namespace retroforge::identification::detectors {

bool GenesisDetector::matches(const std::vector<uint8_t> &cabecalho) const {
    static constexpr size_t OFFSET_PADRAO = 0x0100;
    static constexpr size_t TAMANHO_MAGICO = 16;

    if (cabecalho.size() < OFFSET_PADRAO + TAMANHO_MAGICO) {
        return false;
    }

    const auto *ptr = cabecalho.data() + OFFSET_PADRAO;

    return std::memcmp(ptr, "SEGA MEGA DRIVE", 15) == 0 ||
           std::memcmp(ptr, "SEGA GENESIS", 12) == 0 || std::memcmp(ptr, "SEGA 32X", 8) == 0 ||
           std::memcmp(ptr, "SEGA SSF", 8) == 0;
}

} // namespace retroforge::identification::detectors