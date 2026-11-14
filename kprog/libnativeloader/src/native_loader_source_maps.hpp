#pragma once

struct SourceMapRelocation {
    std::string symbol;
    int fd;
    size_t loaded_slot;
};

// The original ELF supplies symbol/slot correspondence. The intercepted final
// instructions supply resource FDs, including user-loader map substitutions.
class SourceBpfMaps {
    struct Function { std::string name; size_t section; uint64_t start, size; };
    struct Relocation { GElf_Sym target; std::string name, section; uint32_t type; int64_t addend; bool rela; };
    struct Code { std::vector<bpf_insn> insns; std::map<size_t, Relocation> relocs; };
    ScopedFd fd_;
    std::unique_ptr<Elf, decltype(&elf_end)> elf_{nullptr, elf_end};
    std::vector<Function> functions_;
    std::map<size_t, Code> code_;

    const Function &function(size_t section, uint64_t address) const {
        for (const auto &f : functions_)
            if (f.section == section && f.start == address) return f;
        fail("original BPF call has no function at section/offset " +
             std::to_string(section) + "/" + std::to_string(address));
    }
public:
    explicit SourceBpfMaps(const std::filesystem::path &path)
        : fd_(open(path.c_str(), O_RDONLY | O_CLOEXEC)) {
        if (fd_.get() < 0) fail("open original BPF object " + path.string() + ": " + std::strerror(errno));
        if (elf_version(EV_CURRENT) == EV_NONE) fail("libelf initialization failed");
        elf_.reset(elf_begin(fd_.get(), ELF_C_READ, nullptr));
        GElf_Ehdr header{};
        if (!elf_ || !gelf_getehdr(elf_.get(), &header) || header.e_machine != EM_BPF)
            fail("original source object is not BPF ELF: " + path.string());
        size_t strings;
        if (elf_getshdrstrndx(elf_.get(), &strings)) fail("read original BPF section strings");
        Elf_Scn *section = nullptr;
        while ((section = elf_nextscn(elf_.get(), section))) {
            GElf_Shdr h{};
            if (!gelf_getshdr(section, &h)) fail("read original BPF section header");
            Elf_Data *data = elf_getdata(section, nullptr);
            if (h.sh_type == SHT_PROGBITS && (h.sh_flags & SHF_EXECINSTR)) {
                if (h.sh_size % sizeof(bpf_insn) || (h.sh_size && (!data || data->d_size != h.sh_size)))
                    fail("original BPF code is not whole instructions");
                Code code;
                code.insns.resize(h.sh_size / sizeof(bpf_insn));
                if (h.sh_size) std::memcpy(code.insns.data(), data->d_buf, h.sh_size);
                code_.emplace(elf_ndxscn(section), std::move(code));
            }
            if (h.sh_type != SHT_SYMTAB) continue;
            if (!data || !h.sh_entsize) fail("original BPF symbol table is unreadable");
            for (size_t i = 0; i < h.sh_size / h.sh_entsize; ++i) {
                GElf_Sym sym{};
                if (!gelf_getsym(data, i, &sym)) fail("read original BPF symbol");
                if (GELF_ST_TYPE(sym.st_info) != STT_FUNC || sym.st_shndx == SHN_UNDEF) continue;
                const char *name = elf_strptr(elf_.get(), h.sh_link, sym.st_name);
                if (!name) fail("read original BPF function name");
                functions_.push_back({name, sym.st_shndx, sym.st_value, sym.st_size});
            }
        }
        section = nullptr;
        while ((section = elf_nextscn(elf_.get(), section))) {
            GElf_Shdr h{};
            if (!gelf_getshdr(section, &h)) fail("read original BPF relocation header");
            if ((h.sh_type != SHT_REL && h.sh_type != SHT_RELA) || !code_.contains(h.sh_info)) continue;
            auto *data = elf_getdata(section, nullptr);
            auto *symbols = elf_getscn(elf_.get(), h.sh_link);
            GElf_Shdr sh{};
            if (!data || !h.sh_entsize || !symbols || !gelf_getshdr(symbols, &sh))
                fail("read original BPF relocation symbols");
            auto *symbol_data = elf_getdata(symbols, nullptr);
            for (size_t i = 0; i < h.sh_size / h.sh_entsize; ++i) {
                GElf_Rela r{};
                if (h.sh_type == SHT_RELA) {
                    if (!gelf_getrela(data, i, &r)) fail("read original BPF RELA");
                } else {
                    GElf_Rel rel{};
                    if (!gelf_getrel(data, i, &rel)) fail("read original BPF REL");
                    r.r_offset = rel.r_offset; r.r_info = rel.r_info;
                }
                GElf_Sym target{};
                if (!symbol_data || !gelf_getsym(symbol_data, GELF_R_SYM(r.r_info), &target))
                    fail("read original BPF relocation target");
                const char *name = elf_strptr(elf_.get(), sh.sh_link, target.st_name);
                if (!name) fail("read original BPF relocation name");
                std::string target_section;
                if (target.st_shndx != SHN_UNDEF && target.st_shndx < SHN_LORESERVE) {
                    GElf_Shdr th{};
                    auto *ts = elf_getscn(elf_.get(), target.st_shndx);
                    if (!ts || !gelf_getshdr(ts, &th)) fail("read original BPF target section");
                    const char *n = elf_strptr(elf_.get(), strings, th.sh_name);
                    if (!n) fail("read original BPF target section name");
                    target_section = n;
                }
                if (r.r_offset % sizeof(bpf_insn)) fail("original BPF relocation is not instruction aligned");
                code_.at(h.sh_info).relocs.emplace(r.r_offset / sizeof(bpf_insn),
                    Relocation{target, name, target_section, static_cast<uint32_t>(GELF_R_TYPE(r.r_info)),
                               r.r_addend, h.sh_type == SHT_RELA});
            }
        }
    }

    std::vector<SourceMapRelocation> bind(const std::string &entry,
                                      const std::vector<bpf_insn> &loaded,
                                      const std::unordered_set<std::string> *needed = nullptr) const {
        const Function *root = nullptr;
        for (const auto &f : functions_) if (f.name == entry) root = &f;
        if (!root) fail("original BPF object lacks entry " + entry);
        std::vector<std::pair<const Function *, size_t>> pending{{root, 0}};
        std::set<std::tuple<size_t, uint64_t, size_t>> seen;
        std::vector<SourceMapRelocation> bindings;
        while (!pending.empty()) {
            const auto [f, base] = pending.back(); pending.pop_back();
            if (!seen.emplace(f->section, f->start, base).second) continue;
            const auto &code = code_.at(f->section);
            if (f->start % sizeof(bpf_insn) || f->size % sizeof(bpf_insn))
                fail("original BPF function is not instruction aligned");
            for (size_t i = 0; i < f->size / sizeof(bpf_insn); ++i) {
                const size_t slot = f->start / sizeof(bpf_insn) + i;
                const auto &original = code.insns.at(slot);
                const auto r = code.relocs.find(slot);
                if (r != code.relocs.end() && r->second.type == R_BPF_64_64 &&
                    (r->second.section == ".maps" || r->second.section == "maps") &&
                    (!needed || needed->contains(r->second.name))) {
                    const auto &actual = loaded.at(base + i);
                    if (actual.code != (BPF_LD | BPF_DW | BPF_IMM) || actual.src_reg != BPF_PSEUDO_MAP_FD)
                        fail("original map relocation lacks a current map FD at instruction " + std::to_string(base + i));
                    bindings.push_back({r->second.name, actual.imm, base + i});
                }
                if (original.code != (BPF_JMP | BPF_CALL)) continue;
                const Function *callee = nullptr;
                if (r != code.relocs.end() && r->second.type == R_BPF_64_32) {
                    if (code_.contains(r->second.target.st_shndx)) {
                        const auto &rel = r->second;
                        const int64_t offset = rel.rela ? rel.addend : (static_cast<int64_t>(original.imm) + 1) * 8;
                        callee = &function(rel.target.st_shndx, rel.target.st_value + offset);
                    }
                } else if (original.src_reg == BPF_PSEUDO_CALL) {
                    callee = &function(f->section, (static_cast<int64_t>(slot) + 1 + original.imm) * 8);
                }
                if (!callee) continue;
                const auto &actual = loaded.at(base + i);
                if (actual.code != (BPF_JMP | BPF_CALL) || actual.src_reg != BPF_PSEUDO_CALL)
                    fail("original BPF subprogram lacks a current call at instruction " + std::to_string(base + i));
                const int64_t target = static_cast<int64_t>(base + i) + 1 + actual.imm;
                if (target < 0 || static_cast<size_t>(target) >= loaded.size()) fail("current BPF call target is outside its code");
                pending.emplace_back(callee, static_cast<size_t>(target));
            }
        }
        return bindings;
    }
};

void bind_original_source_maps(const std::filesystem::path &object, const std::string &entry,
                               const std::vector<bpf_insn> &insns, CompanionLoad &load,
                               const std::unordered_set<std::string> *needed = nullptr)
{
    std::map<std::string, uint32_t> identities;
    for (const auto &binding : SourceBpfMaps(object).bind(entry, insns, needed)) {
        const auto found = load.source_maps_by_fd.find(binding.fd);
        if (found == load.source_maps_by_fd.end())
            fail("source map FD is unavailable at instruction " + std::to_string(binding.loaded_slot));
        const auto &meta = found->second;
        auto [id, inserted] = identities.emplace(binding.symbol, meta.kernel_id);
        if (!inserted && id->second != meta.kernel_id)
            fail("original map symbol has different current resource identities: " + binding.symbol);
        load.map_addrs[binding.symbol] = meta.kernel_addr;
        load.map_addr_ids[binding.symbol] = meta.kernel_id;
        load.native_map_symbols[binding.symbol] = meta.name;
    }
}
