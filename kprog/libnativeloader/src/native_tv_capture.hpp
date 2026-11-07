#pragma once

/* Included after LinkedBlob, with the existing binary IO/load helpers in scope.
 * Caller holds NativeLabUploadLock through the successful load and capture. */
void capture_bound_artifact(const LinkedBlob &linked, const std::vector<bpf_insn> &proof,
    const std::vector<uint32_t> &generations, const std::vector<NativeBlobChunk> &chunks,
    const StubLoadAttrs &attrs, int fd)
{
    const char *directory = std::getenv("BPFREJIT_NATIVE_LOADER_TV_DIR");
    if (!directory || !directory[0] || generations.empty()) return;
    const auto path = std::filesystem::path(kNativeLabTarget.debugfs_dir) / "checked_proof";
    std::ifstream input(path, std::ios::binary);
    if (!input) fail("open verifier artifact " + path.string() + ": " + std::strerror(errno));
    std::vector<uint8_t> snapshot{std::istreambuf_iterator<char>(input), {}};
    if (input.bad() || snapshot.size() < sizeof(native_lab_checked_header))
        fail("read complete verifier artifact " + path.string());
    native_lab_checked_header head;
    std::memcpy(&head, snapshot.data(), sizeof(head));
    const size_t extent = sizeof(head) + size_t(head.prog_insns) * sizeof(bpf_insn) +
        size_t(head.regions) * sizeof(native_lab_checked_region) +
        size_t(head.map_refs) * sizeof(native_lab_checked_map) +
        size_t(head.helper_refs) * sizeof(native_lab_checked_helper);
#if defined(__aarch64__)
    constexpr uint32_t arch = NATIVE_LAB_ARCH_ARM64;
#else
    constexpr uint32_t arch = NATIVE_LAB_ARCH_X86;
#endif
    if (head.version != 1 || extent != snapshot.size() ||
        native_lab_binding_use(&head.binding, arch, generations.size()-1,
            chunks.back().len, chunk_reloc_bytes(parse_native_lab_relocs(linked.relocs,
                linked.blob.size()), chunks.back()).size()/16,
            bound_proof_sequence(proof).size(), generations.back(), linked.callee_saved_mask) ||
        head.binding.chunk_offset != chunks.back().offset ||
        head.actual_generation != generations.back() || head.regions != generations.size() ||
        head.binding.source_prog_id != attrs.source_prog_id ||
        head.binding.expected_attach_type != attrs.expected_attach_type ||
        head.binding.prog_flags != attrs.prog_flags ||
        head.binding.attach_btf_id != attrs.attach_btf_id ||
        head.binding.attach_btf_obj_id != attrs.attach_btf_obj_id ||
        head.binding.attach_prog_id != attrs.attach_prog_id ||
        head.binding.prog_ifindex != attrs.prog_ifindex ||
        head.binding.gpl_compatible != attrs.gpl_compatible ||
        head.binding.total_native_size != linked.blob.size() ||
        head.binding.abi_mask != linked.callee_saved_mask)
        fail("verifier artifact differs from this successful generation-bound load");
    bpf_prog_info info = load_prog_info(fd);
    if (info.type != head.binding.prog_type || !info.jited_prog_len ||
        !info.nr_jited_ksyms || info.nr_jited_func_lens != info.nr_jited_ksyms)
        fail("successful bound artifact lacks actual JIT bytes/address/layout");
    std::vector<uint8_t> jit(info.jited_prog_len);
    std::vector<uint64_t> addresses(info.nr_jited_ksyms);
    std::vector<uint32_t> lengths(info.nr_jited_func_lens);
    bpf_prog_info actual{};
    actual.jited_prog_len = jit.size(); actual.jited_prog_insns = ptr_to_u64(jit.data());
    actual.nr_jited_ksyms = addresses.size(); actual.jited_ksyms = ptr_to_u64(addresses.data());
    actual.nr_jited_func_lens = lengths.size(); actual.jited_func_lens = ptr_to_u64(lengths.data());
    uint32_t size = sizeof(actual);
    if (bpf_obj_get_info_by_fd(fd, &actual, &size) || actual.jited_prog_len != jit.size() ||
        actual.nr_jited_ksyms != addresses.size() || actual.nr_jited_func_lens != lengths.size() ||
        !addresses.front())
        fail("read actual bound JIT bytes/address/layout: " + std::string(std::strerror(errno)));
    const auto emitted_path = std::filesystem::path(kNativeLabTarget.debugfs_dir) / "emitted_native";
    std::ifstream emitted_input(emitted_path, std::ios::binary);
    if (!emitted_input) fail("open emitted native sites " + emitted_path.string());
    std::vector<uint8_t> emitted{std::istreambuf_iterator<char>(emitted_input), {}};
    if (emitted_input.bad() || emitted.size() < sizeof(native_lab_emitted_header))
        fail("read complete emitted native sites");
    native_lab_emitted_header emitted_head;
    std::memcpy(&emitted_head, emitted.data(), sizeof(emitted_head));
    if (emitted_head.version != 1 || emitted_head.reserved || emitted_head.sites != chunks.size() ||
        emitted_head.source_prog_id != attrs.source_prog_id ||
        emitted.size() != sizeof(emitted_head) + chunks.size()*sizeof(native_lab_emitted_site))
        fail("emitted native sites differ from the bound load");
    size_t total_image_bytes = 0;
    for (uint32_t length : lengths) {
        if (!length || length > jit.size()-total_image_bytes)
            fail("actual JIT function lengths exceed the captured image");
        total_image_bytes += length;
    }
    if (total_image_bytes != jit.size())
        fail("actual JIT function lengths do not cover the captured image");
    for (size_t i = 0; i < chunks.size(); ++i) {
        native_lab_emitted_site site;
        std::memcpy(&site, emitted.data()+sizeof(emitted_head)+i*sizeof(site), sizeof(site));
        if (site.blob_id != i || site.generation != generations[i] ||
            site.native_size != chunks[i].len || site.abi_mask != linked.callee_saved_mask || !site.address)
            fail("emitted native site differs from its bound generation/ABI/extent");
        size_t image_offset = 0, matches = 0;
        for (size_t f = 0; f < addresses.size(); ++f) {
            if (site.address >= addresses[f] && site.address-addresses[f] <= lengths[f] &&
                site.native_size <= lengths[f]-(site.address-addresses[f])) {
                ++matches;
                const auto begin = image_offset + size_t(site.address-addresses[f]);
                if (linked.relocs.empty() &&
                    std::memcmp(jit.data()+begin, linked.blob.data()+chunks[i].offset, site.native_size))
                    fail("actual JIT native bytes differ at the reported entry");
            }
            image_offset += lengths[f];
        }
        if (matches != 1 || image_offset != jit.size())
            fail("reported native entry is not contained in one actual JIT function");
    }
    const auto output = std::filesystem::path(directory) /
        (std::to_string(attrs.source_prog_id) + "-" + std::to_string(info.id));
    std::filesystem::create_directories(output.parent_path());
    if (!std::filesystem::create_directory(output))
        fail("bound artifact destination already exists: " + output.string());
    auto save = [&](const char *name, const void *bytes, size_t count) {
        write_binary_file(output/name, static_cast<const uint8_t *>(bytes), count);
    };
    save("emitted.bin", emitted.data(), emitted.size());
    save("checked.snapshot.bin", snapshot.data(), snapshot.size());
    save("native.bin", linked.blob.data(), linked.blob.size());
    save("native.relocs", linked.relocs.data(), linked.relocs.size());
    save("proof-input.bin", proof.data(), proof.size()*sizeof(bpf_insn));
    save("jit.bin", jit.data(), jit.size());
    save("jit-addresses.bin", addresses.data(), addresses.size()*sizeof(uint64_t));
    save("jit-lengths.bin", lengths.data(), lengths.size()*sizeof(uint32_t));
    auto stub = load_xlated_program(fd, info.xlated_prog_len);
    save("stub.bin", stub.data(), stub.size());
    std::string identity = "{\"version\":1,\"source_prog_id\":" + std::to_string(attrs.source_prog_id) +
        ",\"native_prog_id\":" + std::to_string(info.id) + ",\"prog_type\":" + std::to_string(info.type) +
        ",\"generation\":" + std::to_string(head.actual_generation) + "}\n";
    /* Written last: without this success record a partial directory is evidence
     * of an IO failure, never a completed per-program capture. */
    save("load.json", identity.data(), identity.size());
}
