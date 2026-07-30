#include "retroforge/identification/detectors/GameCubeDetector.hpp"

namespace retroforge::identification::detectors {

bool GameCubeDetector::matches(const std::vector<uint8_t> &cabecalho) const {
    constexpr size_t OFFSET_ASSINATURA = 0x1C;
    constexpr uint32_t MAGIC_GAMECUBE = 0xC2339F3D;

    if (cabecalho.empty()) {
        return false;
    };

    if (cabecalho.size() < OFFSET_ASSINATURA + 4) {
        return false;
    }

    uint32_t valor = (static_cast<uint32_t>(cabecalho[OFFSET_ASSINATURA]) << 24) |
                     (static_cast<uint32_t>(cabecalho[OFFSET_ASSINATURA + 1]) << 16) |
                     (static_cast<uint32_t>(cabecalho[OFFSET_ASSINATURA + 2]) << 8) |
                     (static_cast<uint32_t>(cabecalho[OFFSET_ASSINATURA + 3]));

    return valor == MAGIC_GAMECUBE;
}

} // namespace retroforge::identification::detectors
