#include "../libnativeloader/src/native_loader_lto.hpp"
#include <bpf/libbpf.h>
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <utility>
#include <vector>

int main(int argc, char **argv)
{
    try {
        if (argc != 3) throw std::runtime_error("expected target vmlinux and System.map");
        btf *loaded = btf__parse(argv[1], nullptr);
        if (!loaded || libbpf_get_error(loaded)) throw std::runtime_error("parse target kernel BTF");
        std::unique_ptr<btf, decltype(&btf__free)> types(loaded, btf__free);
        std::ifstream input(argv[2]);
        if (!input) throw std::runtime_error("open target System.map");
        std::vector<std::pair<std::string, uint64_t>> symbols;
        std::string line;
        while (std::getline(input, line)) {
            uint64_t address;
            char kind;
            std::string name;
            std::istringstream fields(line);
            if (!(fields >> std::hex >> address >> kind >> name))
                throw std::runtime_error("parse target System.map");
            symbols.emplace_back(name, address);
        }
        if (!input.eof()) throw std::runtime_error("read target System.map");
        std::ostringstream output;
        native_lto::write_layout(output, types.get(), [&](const char *wanted) {
            uint64_t result = 0;
            unsigned found = 0;
            for (const auto &[name, address] : symbols)
                if (name == wanted) { result = address; ++found; }
            if (found != 1) throw std::runtime_error(std::string("ambiguous/missing symbol ") + wanted);
            return result;
        });
        std::cout << output.str() << '\n';
        if (!std::cout) throw std::runtime_error("write layout JSON");
        return 0;
    } catch (const std::exception &error) {
        std::cerr << error.what() << '\n';
        return 1;
    }
}
