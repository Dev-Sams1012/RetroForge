#include "retroforge/bootstrap/CompressionEngineFactory.hpp"

#include "retroforge/compression/converters/ChdmanConverter.hpp"
#include "retroforge/compression/converters/DolphinToolConverter.hpp"
#include "retroforge/compression/converters/LibzipPacker.hpp"
#include "retroforge/compression/converters/MaxcsoConverter.hpp"

namespace retroforge::bootstrap {

using models::Console;

compression::CompressionRouter CompressionEngineFactory::criar() {
    compression::CompressionRouter roteador;

    auto chdman = std::make_shared<compression::converters::ChdmanConverter>();

    roteador.register_strategy(Console::PS1, chdman);
    roteador.register_strategy(Console::PS2, chdman);
    roteador.register_strategy(Console::SegaCD, chdman);
    roteador.register_strategy(Console::Saturn, chdman);
    roteador.register_strategy(Console::Dreamcast, chdman);

    auto dolphin_tool = std::make_shared<compression::converters::DolphinToolConverter>();

    roteador.register_strategy(Console::GameCube, dolphin_tool);

    auto maxcso = std::make_shared<compression::converters::MaxcsoConverter>();

    roteador.register_strategy(Console::PSP, maxcso);

    auto libzip = std::make_shared<compression::converters::LibzipPacker>();

    roteador.register_strategy(Console::SNES, libzip);
    roteador.register_strategy(Console::Genesis, libzip);

    return roteador;
}

} // namespace retroforge::bootstrap