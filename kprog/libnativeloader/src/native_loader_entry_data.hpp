#pragma once

// Read names from the linker's selected-entry ELF, rather than inventing a
// second native reachability analysis in the loader. Defined literal data and
// undefined map/global relocations both retain their original symbol names.
std::unordered_set<std::string> native_entry_symbol_names(const std::filesystem::path &path)
{
    ScopedFd fd(open(path.c_str(), O_RDONLY | O_CLOEXEC));
    if (fd.get() < 0) fail("open native entry " + path.string() + ": " + std::strerror(errno));
    if (elf_version(EV_CURRENT) == EV_NONE) fail("libelf initialization failed");
    std::unique_ptr<Elf, decltype(&elf_end)> elf(elf_begin(fd.get(), ELF_C_READ, nullptr), elf_end);
    if (!elf) fail("elf_begin native entry " + path.string() + ": " + elf_errmsg(-1));
    std::unordered_set<std::string> names;
    Elf_Scn *section = nullptr;
    while ((section = elf_nextscn(elf.get(), section))) {
        GElf_Shdr header{};
        if (!gelf_getshdr(section, &header)) fail("native entry section header: " + std::string(elf_errmsg(-1)));
        if (header.sh_type != SHT_SYMTAB && header.sh_type != SHT_DYNSYM) continue;
        Elf_Data *data = elf_getdata(section, nullptr);
        if (!data || !header.sh_entsize) fail("native entry lacks symbol table data");
        for (size_t i = 0; i < header.sh_size / header.sh_entsize; ++i) {
            GElf_Sym symbol{};
            if (!gelf_getsym(data, static_cast<int>(i), &symbol))
                fail("native entry symbol: " + std::string(elf_errmsg(-1)));
            const char *name = elf_strptr(elf.get(), header.sh_link, symbol.st_name);
            if (!name) fail("native entry symbol name: " + std::string(elf_errmsg(-1)));
            if (name[0]) names.insert(name);
        }
    }
    return names;
}

void write_native_entry_proof(const std::filesystem::path &linker,
                              const std::filesystem::path &elf_path,
                              const std::string &symbol_name,
                              const std::filesystem::path &output,
                              const std::filesystem::path &stderr_path)
{
    const std::vector<std::string> argv = {
        linker.string(), "--input", elf_path.string(), "--symbol", symbol_name,
        "--output", output.string(), "--mode", "proof",
    };
    const int rc = native_loader_detail::run_subprocess(argv, stderr_path);
    const int saved_errno = errno;
    if (rc != 0) {
        std::ostringstream message;
        const auto stderr_text = read_text_file_limited(stderr_path, 2048);
        message << "native-link proof failed (rc=" << rc << ")";
        if (rc < 0) message << ": " << std::strerror(saved_errno);
        if (!stderr_text.empty()) message << "\nstderr:\n" << stderr_text;
        message << "\ncommand: " << format_command_limited(argv, 4096);
        fail(message.str());
    }
    // Like the existing linker pipeline, keep failed diagnostics and retire
    // only the successful invocation's rebuildable stderr cache.
    std::error_code ec;
    std::filesystem::remove(stderr_path, ec);
}

std::filesystem::path cached_native_entry_proof(const std::filesystem::path &native_link_path,
                                                const std::filesystem::path &elf_path,
                                                const std::string &symbol_name)
{
    const auto linker = native_link_binary(native_link_path);
    Hash64 hash;
    hash.add_string(kNativeLinkCacheVersion);
    hash.add_string("entry-data-symbols");
    hash_file_contents(hash, elf_path, "native_elf");
    hash_file_identity(hash, linker, "native_linker");
    hash.add_string(symbol_name);
    const std::filesystem::path directory = kNativeLinkCacheDir;
    std::error_code ec;
    std::filesystem::create_directories(directory, ec);
    if (ec) fail("create native entry cache: " + ec.message());
    const auto output = directory / (hash.hex() + ".entry.proof.o");
    const bool exists = std::filesystem::exists(output, ec);
    if (ec) fail("read native entry cache: " + ec.message());
    if (!exists) {
        const auto base = output.string() + ".tmp." + std::to_string(getpid());
        write_native_entry_proof(linker, elf_path, symbol_name, base, base + ".stderr.txt");
        publish_cache_file(base, output);
    }
    return output;
}
