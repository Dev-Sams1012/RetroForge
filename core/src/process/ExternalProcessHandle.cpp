#include "retroforge/process/ExternalProcessHandle.hpp"

#include <array>
#include <stdexcept>

namespace retroforge::process {

ExternalProcessHandle::ExternalProcessHandle(const std::string &comando)
    : handle_(popen(comando.c_str(), "r"), FechadorDeProcesso{}) {

    if (!handle_) {
        throw std::runtime_error("Falha ao iniciar o processo: " + comando);
    }
}

bool ExternalProcessHandle::read_line(std::string &linha_destino) {
    constexpr int buffer_size = 256;

    std::array<char, buffer_size> buffer{};

    if (!fgets(buffer.data(), buffer_size, handle_.get())) {
        return false;
    }

    linha_destino.assign(buffer.data());
    return true;
}

} // namespace retroforge::process
