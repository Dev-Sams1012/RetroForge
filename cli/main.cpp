#include "retroforge/bootstrap/CompressionEngineFactory.hpp"
#include "retroforge/bootstrap/IdentificationEngineFactory.hpp"
#include "retroforge/models/ConversionJob.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace retroforge;

std::string nome_do_console(models::Console c) {
    switch (c) {
    case models::Console::PS1:
        return "PS1";
    case models::Console::PS2:
        return "PS2";
    case models::Console::PSP:
        return "PSP";
    case models::Console::PSP_PBP:
        return "PSP (EBOOT.PBP)";
    case models::Console::GameCube:
        return "GameCube";
    case models::Console::Dreamcast:
        return "Dreamcast (Limpo)";
    case models::Console::DreamcastModificado:
        return "Dreamcast (Modificado)";
    case models::Console::Genesis:
        return "Mega Drive / Genesis";
    case models::Console::SNES:
        return "SNES";
    case models::Console::SegaCD:
        return "Sega CD";
    case models::Console::Saturn:
        return "Sega Saturn";
    case models::Console::Desconhecido:
        return "Desconhecido";
    default:
        return "Outro";
    }
}

int main() {
    auto identificador = bootstrap::IdentificationEngineFactory::criar();
    auto roteador = bootstrap::CompressionEngineFactory::criar();

    std::vector<std::string> arquivos_para_testar = {};

    std::cout << "============================================\n";
    std::cout << " PROTÓTIPO FUNCIONAL - MAIN RETROFORGE \n";
    std::cout << "============================================\n\n";

    for (const auto &caminho : arquivos_para_testar) {
        std::cout << "[ARQUIVO] " << caminho << "\n";

        auto console = identificador.identify(caminho);
        std::cout << "  -> Identificado como: " << nome_do_console(console) << "\n";

        if (console == models::Console::Desconhecido) {
            std::cout << "  -> Ignorando arquivo. Nao reconhecido pelos detectores.\n\n";
            continue;
        }

        auto job = std::make_shared<models::ConversionJob>(caminho, console);
        auto resultado = roteador.rotear(job);

        std::cout << "  -> Status do Roteador: ";
        switch (resultado) {
        case compression::ResultadoRoteamento::ConversaoIniciada:
            std::cout << "Conversao iniciada/concluida com sucesso.\n";
            break;
        case compression::ResultadoRoteamento::BloqueadoPorSeguranca:
            std::cout << "BLOQUEADO por seguranca (Trava do Smart Context ativada).\n";
            break;
        case compression::ResultadoRoteamento::ConsoleNaoSuportado:
            std::cout << "Falha na compressao ou sem rota registrada.\n";
            break;
        }
        std::cout << "\n";
    }

    return 0;
}