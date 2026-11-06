/* Catch dropped/misparsed kernel-symbol names or addresses in the fast scanner. */
#include "../libnativeloader/src/native_loader.cpp"
#include <iostream>
int main(int argc, char **argv)
{
    if (argc != 2) throw std::runtime_error("expected native-link path");
    const bpf_insn exit = { .code = BPF_JMP | BPF_EXIT };
    const bpf_insn local = { .code = BPF_JMP | BPF_CALL,
                            .src_reg = BPF_PSEUDO_CALL, .imm = 1 };
    const bpf_insn helper = { .code = BPF_JMP | BPF_CALL,
                             .imm = BPF_FUNC_get_current_uid_gid };
    const bpf_insn kfunc = { .code = BPF_JMP | BPF_CALL,
                            .src_reg = BPF_PSEUDO_KFUNC_CALL, .imm = 1 };
    if (!proof_needs_kernel_symbols({}) ||
        proof_needs_kernel_symbols({exit}) ||
        proof_needs_kernel_symbols({local,exit}) ||
        !proof_needs_kernel_symbols({local,helper,exit}) ||
        !proof_needs_kernel_symbols({kfunc,exit})) {
        throw std::runtime_error("proof call classification lost local/helper/kfunc distinction");
    }
    CompanionLoad pure{};
    pure.prog_type = BPF_PROG_TYPE_XDP;
    const NativeLinkArgs args = build_native_link_args(argv[1], {}, pure);
    for (const auto &entry : args.helpers) {
        if (entry.name.rfind("__native_", 0) != 0 ||
            entry.name == kX86CpuNumberHelperKey ||
            entry.name == kX86ThisCpuOffHelperKey) {
            throw std::runtime_error("pure link requested a kernel symbol: " + entry.name);
        }
    }
    std::unordered_set<std::string> wanted;
#if defined(__x86_64__)
    wanted.insert("cpu_number");
    wanted.insert("this_cpu_off");
#endif
    for (const auto &helper : kSupportedHelpers) wanted.insert(helper.symbol);
    for (const char *name : kTypedHelperSymbols) wanted.insert(name);
    for (const char *name : kRuntimeCallSymbols) wanted.insert(name);
    wanted.insert(kHtabLookupElemSymbol);
    wanted.insert(kArrayOfMapLookupElemSymbol);
    wanted.insert(kHtabLruPercpuMapLookupElemSymbol);
    std::ifstream input("/proc/kallsyms");
    if (!input) throw std::runtime_error("open reference kallsyms");
    std::unordered_map<std::string,uint64_t> expected;
    std::string line;
    while (std::getline(input,line)) {
        std::istringstream row(line);
        uint64_t address;
        char type;
        std::string name;
        if (!(row >> std::hex >> address >> type >> name)) throw std::runtime_error("parse reference kallsyms");
        if (wanted.count(name)) expected.emplace(name,address);
    }
    if (input.bad()) throw std::runtime_error("read reference kallsyms");
    const auto &actual = kallsyms_table();
    if (actual != expected) {
        std::cerr << "symbol table mismatch: actual=" << actual.size() << " expected=" << expected.size() << '\n';
        return 1;
    }
    std::cout << "pure link needs no kernel symbols; kallsyms names and addresses agree: " << actual.size() << " symbols\n";
}
