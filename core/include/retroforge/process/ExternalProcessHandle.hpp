#pragma once

#include <memory>
#include <string>

namespace retroforge::process {

class ExternalProcessHandle {
  public:
    ExternalProcessHandle(const std::string &comando);

    bool read_line(std::string &linha_destino);

  private:
    struct FechadorDeProcesso {
        void operator()(FILE *file_proc) {
            if (file_proc) {
                pclose(file_proc);
            }
        }
    };

    std::unique_ptr<FILE, FechadorDeProcesso> handle_;
};
} // namespace retroforge::process
