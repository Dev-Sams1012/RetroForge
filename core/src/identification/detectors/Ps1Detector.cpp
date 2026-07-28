#include "retroforge/identification/detectors/Ps1Detector.hpp"
#include <algorithm>
#include <string>

namespace retroforge::identification::detectors {

bool Ps1Detector::matches(const std::vector<uint8_t> &cabecalho) const {
    if (cabecalho.empty()) {
        return false;
    }

    std::string conteudo(cabecalho.begin(), cabecalho.end());

    std::transform(conteudo.begin(), conteudo.end(), conteudo.begin(), ::toupper);

    bool temFile = conteudo.find("FILE") != std::string::npos;
    bool temMode2 = conteudo.find("MODE2/2352") != std::string::npos;

    return temFile && temMode2;
}

} // namespace retroforge::identification::detectors