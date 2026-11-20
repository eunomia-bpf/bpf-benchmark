#include "../../libnativeloader/src/native_loader_lto.hpp"
#include <iostream>
int main(int argc, char **argv)
{
    if (argc != 2) return 1;
    std::unique_ptr<btf, decltype(&btf__free)> types(btf__parse(argv[1], nullptr), btf__free);
    if (!types) return 1;
    const auto base = native_lto::offset(types.get(), "lpm_trie", "map");
    std::cout << '{';
    bool separator = false;
    for (const auto &[structure, name, label] : {
        std::tuple{"lpm_trie", "root", "ROOT"}, {"lpm_trie", "data_size", "SIZE"},
        {"lpm_trie", "max_prefixlen", "MAX"}, {"lpm_trie_node", "child", "CHILD"},
        {"lpm_trie_node", "prefixlen", "PREFIX"}, {"lpm_trie_node", "flags", "FLAGS"},
        {"lpm_trie_node", "data", "DATA"}}) {
        if (separator) std::cout << ',';
        std::cout << '"' << label << "_OFF\":" << native_lto::offset(types.get(), structure, name) -
            (std::string(structure) == "lpm_trie" ? base : 0);
        separator = true;
    }
    std::cout << "}\n";
}
