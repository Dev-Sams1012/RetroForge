#include "retroforge/identification/detectors/CueSheetResolver.hpp"

#include <fstream>
#include <optional>
#include <string>

namespace retroforge::identification::detectors {

std::optional<std::filesystem::path>
CueSheetResolver::resolve(const std::filesystem::path &caminho) const {
    if (caminho.extension() != ".cue" && caminho.extension() != ".CUE") {
        return std::nullopt;
    };

    std::ifstream cue_sheet(caminho);

    if (!cue_sheet.is_open()) {
        return std::nullopt;
    }

    std::string linha;
    while (std::getline(cue_sheet, linha)) {
        auto pos_file = linha.find("FILE");

        if (pos_file == std::string::npos) {
            continue;
        };

        auto primeira_aspa = linha.find('"');

        if (primeira_aspa == std::string::npos) {
            continue;
        };

        auto segunda_aspa = linha.find('"', primeira_aspa + 1);

        if (segunda_aspa == std::string::npos) {
            continue;
        };

        std::string nome_bin = linha.substr(primeira_aspa + 1, segunda_aspa - primeira_aspa - 1);

        return caminho.parent_path() / nome_bin;
    }

    return std::nullopt;
}

} // namespace retroforge::identification::detectors