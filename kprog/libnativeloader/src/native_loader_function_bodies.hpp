#pragma once

// Original func_info offsets describe the intercepted source bytes. Kernel
// verifier-adjusted offsets are deliberately not used to slice that source.
std::string native_function_body_facts(
    const std::filesystem::path &native_object, const std::vector<bpf_insn> &source,
    const btf *types, const std::vector<bpf_func_info> &functions)
{
    if (elf_version(EV_CURRENT) == EV_NONE) fail("initialize generated-function ELF reader");
    auto bytes = read_binary_file(native_object);
    std::unique_ptr<Elf, decltype(&elf_end)> elf(
        elf_memory(reinterpret_cast<char *>(bytes.data()), bytes.size()), elf_end);
    if (!elf) fail("read native generated-function symbols: " + native_object.string());
    std::set<std::string> undefined;
    Elf_Scn *section = nullptr;
    while ((section = elf_nextscn(elf.get(), section))) {
        GElf_Shdr header{};
        if (!gelf_getshdr(section, &header)) fail("read generated-function symbol table header");
        if (header.sh_type != SHT_SYMTAB && header.sh_type != SHT_DYNSYM) continue;
        Elf_Data *data = elf_getdata(section, nullptr);
        if (!data || !header.sh_entsize) fail("empty generated-function symbol table");
        for (size_t i = 0; i < header.sh_size / header.sh_entsize; ++i) {
            GElf_Sym symbol{};
            if (!gelf_getsym(data, i, &symbol)) fail("read generated-function symbol");
            if (symbol.st_shndx != SHN_UNDEF) continue;
            const char *name = elf_strptr(elf.get(), header.sh_link, symbol.st_name);
            if (!name) fail("read generated-function name");
            if (*name) undefined.insert(name);
        }
    }
    constexpr char hex[] = "0123456789abcdef";
    std::string facts;
    for (size_t i = 0; i < functions.size(); ++i) {
        const auto &function = functions[i];
        const auto *type = btf__type_by_id(types, function.type_id);
        if (!type || !btf_is_func(type)) fail("original func_info does not name a BTF function");
        const char *name = btf__name_by_offset(types, type->name_off);
        if (!name) fail("read original BTF function name");
        if (!undefined.contains(name)) continue;
        const size_t begin = function.insn_off;
        const size_t end = i + 1 < functions.size() ? functions[i + 1].insn_off : source.size();
        if (begin >= end || end > source.size()) fail("original function offsets exceed captured bytecode");
        if (!facts.empty()) facts += ',';
        facts += '"';
        for (const auto *p = reinterpret_cast<const unsigned char *>(name); *p; ++p) {
            if (*p == '"' || *p == '\\') { facts += '\\'; facts += char(*p); }
            else if (*p < 32) { facts += "\\u00"; facts += hex[*p >> 4]; facts += hex[*p & 15]; }
            else facts += char(*p);
        }
        facts += "\":\"";
        const auto *code = reinterpret_cast<const uint8_t *>(source.data() + begin);
        for (size_t j = 0; j < (end - begin) * sizeof(bpf_insn); ++j) {
            facts += hex[code[j] >> 4]; facts += hex[code[j] & 15];
        }
        facts += '"';
    }
    return facts.empty() ? std::string{} : "{\"functions\":{" + facts + "}}\n";
}

std::string native_source_function_bodies(
    const std::filesystem::path &native_object, const std::filesystem::path &source_path,
    const bpf_prog_info &program, const std::vector<bpf_insn> &source)
{
    if (source_path.empty()) return {};
    const auto path = source_path.string() + ".functions." + std::to_string(program.id) + ".json";
    std::error_code ec;
    const bool present = std::filesystem::exists(path, ec);
    if (ec) fail("read original function metadata: " + ec.message());
    if (!present) return {};
    const auto bytes = read_binary_file(path);
    const std::string document(bytes.begin(), bytes.end());
    if (json_required_u32(document, "version") != 1 ||
        json_required_u32(document, "prog_id") != program.id ||
        json_required_u32(document, "btf_id") != program.btf_id)
        fail("original function metadata differs from loaded program identity");
    std::vector<bpf_func_info> functions;
    for (const auto &entry : json_array_objects(document, "functions"))
        functions.push_back({json_required_u32(entry, "insn_off"), json_required_u32(entry, "type_id")});
    if (functions.empty()) return {};
    std::unique_ptr<btf, decltype(&btf__free)> types(
        btf__load_from_kernel_by_id(program.btf_id), btf__free);
    if (!types) fail("read original generated-function BTF: " + std::string(std::strerror(errno)));
    return native_function_body_facts(native_object, source, types.get(), functions);
}
