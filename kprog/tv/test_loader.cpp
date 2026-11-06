#include "../libnativeloader/include/native_loader.hpp"
#include <bpf/bpf.h>
#include <bpf/btf.h>
#include <bpf/libbpf.h>
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <exception>
#include <fstream>
#include <memory>
#include <unistd.h>

struct ProofFixture {
    std::unique_ptr<bpf_object, decltype(&bpf_object__close)> object;
    bpf_program *program;
};

static ProofFixture load_fixture(const char *path, const char *entry)
{
    std::unique_ptr<bpf_object, decltype(&bpf_object__close)> object(
        bpf_object__open_file(path, nullptr), bpf_object__close);
    if (libbpf_get_error(object.get()) || !object) throw std::runtime_error("open proof fixture");
    bpf_program *selected = bpf_object__find_program_by_name(object.get(), entry);
    if (!selected) throw std::runtime_error("find proof fixture entry");
    bpf_program *program;
    bpf_object__for_each_program(program, object.get())
        if (bpf_program__set_autoload(program, program == selected))
            throw std::runtime_error("select proof fixture entry");
    if (int error = bpf_object__load(object.get()))
        throw std::runtime_error("load proof fixture: " + std::to_string(error));
    return {std::move(object), selected};
}

static void btf_manifest_regressions()
{
    const char *entries[] = {"tv_collision_entry_alpha", "tv_collision_entry_beta"};
    for (unsigned which = 0; which < 2; which++) {
        auto fixture = load_fixture("build/simulator.bpf.o", entries[which]);
        bpf_prog_info info{};
        uint32_t length = sizeof(info);
        if (bpf_obj_get_info_by_fd(bpf_program__fd(fixture.program), &info, &length))
            throw std::runtime_error("query collision program");
        assert(info.btf_id && info.nr_func_info);
        assert(std::string(info.name) == std::string(entries[0]).substr(0, BPF_OBJ_NAME_LEN - 1));
        std::ofstream manifest("build/collision-manifest.json");
        manifest << "{\"objects\":[";
        for (unsigned i = 0; i < 2; i++) {
            if (i) manifest << ',';
            manifest << "{\"program\":\"" << info.name << "\",\"native_object\":\"native-entry.o\","
                "\"source_btf_symbol\":\"" << entries[i] << "\",\"symbol\":\""
                << (i ? "tv_long_entry" : "tv_short_entry") << "\",\"simulator_object\":\"simulator.bpf.o\","
                "\"simulator_program\":\"" << entries[i] << "\"}";
        }
        manifest << "]}";
        manifest.close();
        if (!manifest) throw std::runtime_error("write collision manifest");
        for (bool supplied : {false, true}) {
            native_loader::FdLoadOptions options{};
            options.original_prog_fd = bpf_program__fd(fixture.program);
            options.expected_attach_type = bpf_program__expected_attach_type(fixture.program);
            options.manifest_path = std::filesystem::absolute("build/collision-manifest.json");
            options.source_insns.assign(bpf_program__insns(fixture.program),
                bpf_program__insns(fixture.program) + bpf_program__insn_cnt(fixture.program));
            options.native_link_path = std::filesystem::absolute(
                "../x86/native_lab/native_link/target/release/native-link");
            if (supplied) {
                options.source_btf_id = info.btf_id;
                options.source_func_info_rec_size = sizeof(bpf_func_info);
                const auto *records = reinterpret_cast<const uint8_t *>(bpf_program__func_info(fixture.program));
                options.source_func_info.assign(records, records +
                    sizeof(bpf_func_info) * bpf_program__func_info_cnt(fixture.program));
            }
            auto loaded = native_loader::load_from_fd(options);
            assert(loaded.replaced && loaded.prog_fd >= 0);
            assert(loaded.selected_symbol == (which ? "tv_long_entry" : "tv_short_entry"));
            unsigned char packet[64]{};
            bpf_test_run_opts run{};
            run.sz = sizeof(run);
            run.data_in = packet;
            run.data_size_in = sizeof(packet);
            if (bpf_prog_test_run_opts(loaded.prog_fd, &run))
                throw std::runtime_error("run full BTF selected native program");
            assert(run.retval == 2);
            native_loader::close_loaded_program(&loaded);
            std::printf("full BTF %s (%s): PASS (exact native entry, bound execution)\n",
                entries[which], supplied ? "captured metadata" : "original FD");
            if (supplied) {
                bpf_func_info wrong{};
                std::memcpy(&wrong, options.source_func_info.data(), sizeof(wrong));
                int type = btf__find_by_name_kind(bpf_object__btf(fixture.object.get()),
                    entries[1 - which], BTF_KIND_FUNC);
                assert(type > 0);
                wrong.type_id = type;
                std::memcpy(options.source_func_info.data(), &wrong, sizeof(wrong));
                bool rejected = false;
                try {
                    auto mismatched = native_loader::load_from_fd(options);
                    native_loader::close_loaded_program(&mismatched);
                } catch (const std::exception &error) {
                    assert(std::string(error.what()).find("source BTF entry differs from original") != std::string::npos);
                    rejected = true;
                }
                assert(rejected);
                std::puts("caller BTF full-entry swap despite identical short name: PASS (rejected)");
            }
        }
    }
    std::vector<bpf_insn> no_btf(2);
    no_btf[0].code = BPF_ALU64 | BPF_MOV | BPF_K;
    no_btf[0].imm = 2;
    no_btf[1].code = BPF_JMP | BPF_EXIT;
    int fd = bpf_prog_load(BPF_PROG_TYPE_XDP, "tv_collision_en", "GPL",
        no_btf.data(), no_btf.size(), nullptr);
    if (fd < 0) throw std::runtime_error("load no-BTF collision program");
    native_loader::FdLoadOptions options{};
    options.original_prog_fd = fd;
    options.source_insns = no_btf;
    options.manifest_path = std::filesystem::absolute("build/collision-manifest.json");
    bool rejected = false;
    try {
        auto invalid = native_loader::load_from_fd(options);
        native_loader::close_loaded_program(&invalid);
    } catch (const std::exception &error) {
        assert(std::string(error.what()).find("source_btf_symbol requires source entry BTF") != std::string::npos);
        rejected = true;
    }
    if (close(fd)) throw std::runtime_error("close no-BTF collision program");
    assert(rejected);
    std::puts("full BTF selector cannot use a truncated no-BTF program name: PASS (rejected)");
}

static void load_context_regressions()
{
    static_assert(sizeof(native_loader_source_load_context) == 16);
    static_assert(offsetof(native_loader_source_load_context, version) == 0);
    static_assert(offsetof(native_loader_source_load_context, prog_flags) == 4);
    static_assert(offsetof(native_loader_source_load_context, prog_token_fd) == 8);
    static_assert(offsetof(native_loader_source_load_context, reserved) == 12);
    std::vector<bpf_insn> body(2);
    body[0].code = BPF_ALU64 | BPF_MOV | BPF_K;
    body[0].imm = 2;
    body[1].code = BPF_JMP | BPF_EXIT;
    bpf_prog_load_opts attrs{};
    attrs.sz = sizeof(attrs);
    attrs.prog_flags = BPF_F_TEST_STATE_FREQ;
    int original = bpf_prog_load(BPF_PROG_TYPE_XDP, "tv_ctx_flags", "GPL", body.data(), body.size(), &attrs);
    if (original < 0) throw std::runtime_error("load flagged original");
    native_loader::FdLoadOptions options{};
    options.original_prog_fd = original;
    options.source_insns = options.proof_insns = body;
    options.native_object_path = std::filesystem::absolute("build/native-entry.o");
    options.symbol_name = "tv_short_entry";
    options.native_link_path = std::filesystem::absolute("../x86/native_lab/native_link/target/release/native-link");
    bool rejected = false;
    try {
        auto invalid = native_loader::load_from_fd(options);
        native_loader::close_loaded_program(&invalid);
    } catch (const std::exception &error) {
        assert(std::string(error.what()).find("seal binding") != std::string::npos);
        rejected = true;
    }
    assert(rejected);
    std::puts("loader cannot silently omit original flags: PASS (rejected)");
    std::ofstream manifest("build/context-manifest.json");
    manifest << "{\"objects\":[{\"program\":\"tv_ctx_flags\",\"native_object\":\"native-entry.o\","
        "\"symbol\":\"tv_short_entry\",\"simulator_object\":\"simulator.bpf.o\","
        "\"simulator_program\":\"tv_collision_entry_alpha\"}]}";
    manifest.close();
    std::ofstream source("build/context-source.bin", std::ios::binary);
    source.write(reinterpret_cast<const char *>(body.data()), body.size() * sizeof(body[0]));
    source.close();
    if (!manifest || !source) throw std::runtime_error("write context fixture");
    if (setenv("BPFREJIT_NATIVE_LINK_BINARY", options.native_link_path.c_str(), 1))
        throw std::runtime_error("set native link path");
    native_loader_source_load_context context{1, BPF_F_TEST_STATE_FREQ, -1, 0};
    for (unsigned invalid = 0; invalid < 3; invalid++) {
        context.version = invalid == 1 ? 2 : 1;
        context.reserved = invalid == 2 ? 1 : 0;
        native_loader_c_result result{};
        int status = native_loader_load_from_fd_with_manifest_path_btf_and_context(original,
            "build/context-manifest.json", "build/context-source.bin", nullptr, 0,
            0, nullptr, 0, 0, 0, 0, 0, 0, &context, &result);
        if (invalid) {
            assert(status == -1 && errno == EINVAL && result.prog_fd == -1);
            assert(std::string(result.error).find("invalid source load context version/reserved") != std::string::npos);
            std::puts("C source context rejects ABI/reserved mismatch: PASS");
        } else {
            if (status) throw std::runtime_error(result.error);
            unsigned char packet[64]{};
            bpf_test_run_opts run{};
            run.sz = sizeof(run); run.data_in = packet; run.data_size_in = sizeof(packet);
            if (bpf_prog_test_run_opts(result.prog_fd, &run)) throw std::runtime_error("run captured C context");
            assert(run.retval == 2 && result.replaced);
            if (close(result.prog_fd)) throw std::runtime_error("close C context result");
            std::puts("C captured source flags survive sealing/verifier/native JIT: PASS");
        }
    }
    if (close(original)) throw std::runtime_error("close flagged source");
    original = bpf_prog_load(BPF_PROG_TYPE_XDP, "tv_ctx_bsd", "BSD", body.data(), body.size(), nullptr);
    if (original < 0) throw std::runtime_error("load BSD original");
    options.original_prog_fd = original;
    auto loaded = native_loader::load_from_fd(options);
    bpf_prog_info info{};
    uint32_t size = sizeof(info);
    if (bpf_obj_get_info_by_fd(loaded.prog_fd, &info, &size)) throw std::runtime_error("query native GPL status");
    assert(!info.gpl_compatible);
    native_loader::close_loaded_program(&loaded);
    if (close(original)) throw std::runtime_error("close BSD original");
    std::puts("loader preserves original non-GPL status: PASS");
}

int main()
{
    std::setvbuf(stdout, nullptr, _IONBF, 0);
    const std::vector<bpf_insn> constant{
        {.code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = 0,
         .src_reg = 0, .off = 0, .imm = 2},
        {.code = BPF_JMP | BPF_EXIT, .dst_reg = 0,
         .src_reg = 0, .off = 0, .imm = 0},
    };
    const std::vector<bpf_insn> helper{
        {.code = BPF_JMP | BPF_CALL, .dst_reg = 0, .src_reg = 0,
         .off = 0, .imm = BPF_FUNC_get_prandom_u32}, constant[0], constant[1],
    };
    std::vector<bpf_insn> large{helper[0],
        {.code = BPF_JMP | BPF_JNE | BPF_K, .dst_reg = 0, .src_reg = 0, .off = 2, .imm = 0},
        constant[0], constant[1]};
    large.insert(large.end(), 70000, constant[0]);
    large.push_back(constant[1]);
    int map_fd = bpf_map_create(BPF_MAP_TYPE_ARRAY, "tv_map", 4, 4, 1, nullptr);
    if (map_fd < 0) { std::perror("create fixture map"); return 1; }
    int key = 0, value = 2;
    if (bpf_map_update_elem(map_fd, &key, &value, BPF_ANY)) {
        std::perror("initialize fixture map"); return 1;
    }
    int hash_fd = bpf_map_create(BPF_MAP_TYPE_HASH, "tv_hash_map", 4, 4, 1, nullptr);
    if (hash_fd < 0 || bpf_map_update_elem(hash_fd, &key, &value, BPF_ANY)) {
        std::perror("initialize hash fixture map"); return 1;
    }
    const std::vector<bpf_insn> map{
        {.code = BPF_LD | BPF_DW | BPF_IMM, .dst_reg = 1, .src_reg = BPF_PSEUDO_MAP_FD,
         .off = 0, .imm = map_fd}, {},
        {.code = BPF_ST | BPF_W | BPF_MEM, .dst_reg = 10, .src_reg = 0, .off = -4, .imm = 0},
        {.code = BPF_ALU64 | BPF_MOV | BPF_X, .dst_reg = 2, .src_reg = 10, .off = 0, .imm = 0},
        {.code = BPF_ALU64 | BPF_ADD | BPF_K, .dst_reg = 2, .src_reg = 0, .off = 0, .imm = -4},
        {.code = BPF_JMP | BPF_CALL, .dst_reg = 0, .src_reg = 0, .off = 0, .imm = BPF_FUNC_map_lookup_elem},
        {.code = BPF_JMP | BPF_JEQ | BPF_K, .dst_reg = 0, .src_reg = 0, .off = 1, .imm = 0},
        {.code = BPF_LDX | BPF_W | BPF_MEM, .dst_reg = 0, .src_reg = 0, .off = 0, .imm = 0},
        constant[1],
    };
    auto hash = map;
    hash[0].imm = hash_fd;
    int separate_map = bpf_map_create(BPF_MAP_TYPE_ARRAY, "tv_map", 4, 4, 1, nullptr);
    int separate_value = 13;
    if (separate_map < 0 || bpf_map_update_elem(separate_map, &key, &separate_value, BPF_ANY)) {
        std::perror("separate simulator map"); return 1;
    }
    try {
        load_context_regressions();
        btf_manifest_regressions();
        for (const char *symbol : {"tv_short_entry", "tv_long_entry", "tv_helper_entry", "tv_map_entry", "tv_hash_entry", "tv_large_entry", "tv_readonly_entry"}) {
            const auto &proof = std::string(symbol) == "tv_helper_entry" ? helper :
                std::string(symbol) == "tv_large_entry" ? large :
                std::string(symbol) == "tv_map_entry" ? map :
                std::string(symbol) == "tv_hash_entry" ? hash : constant;
            int original = bpf_prog_load(BPF_PROG_TYPE_XDP, "tv_loader", "GPL",
                                         proof.data(), proof.size(), nullptr);
            if (original < 0) { std::perror("original BPF load"); return 1; }
            native_loader::FdLoadOptions options{};
            options.original_prog_fd = original;
            options.native_object_path = std::filesystem::absolute("build/native-entry.o");
            options.symbol_name = symbol;
            options.source_insns = proof;
            options.proof_insns = proof;
            options.native_link_path = std::filesystem::absolute(
                "../x86/native_lab/native_link/target/release/native-link");
            auto loaded = native_loader::load_from_fd(options);
            assert(loaded.prog_fd >= 0);
            assert(loaded.native_chunk_count > 0);
            if (options.symbol_name == "tv_long_entry")
                assert(loaded.native_chunk_count > 1);
            unsigned char packet[64] = {};
            bpf_test_run_opts run{};
            run.sz = sizeof(run);
            run.data_in = packet;
            run.data_size_in = sizeof(packet);
            run.repeat = 1;
            if (bpf_prog_test_run_opts(loaded.prog_fd, &run)) {
                std::perror("bound loader test run");
                return 1;
            }
            if (run.retval != 2) {
                std::fprintf(stderr, "%s native retval=%u expected=2\n", symbol, run.retval);
                std::fprintf(stderr, "%s\n", loaded.native_link_summary.c_str());
                return 1;
            }
            std::printf("shared loader %s: PASS (%u chunks, native returned 2)\n",
                        symbol, loaded.native_chunk_count);
            native_loader::close_loaded_program(&loaded);
            if (std::string(symbol) == "tv_helper_entry") {
                options.proof_insns[0].imm = BPF_FUNC_ktime_get_ns;
                bool rejected = false;
                try {
                    auto wrong = native_loader::load_from_fd(options);
                    native_loader::close_loaded_program(&wrong);
                } catch (const std::exception &error) {
                    assert(std::string(error.what()).find("BPF_PROG_LOAD native_lab stub:") != std::string::npos);
                    rejected = true;
                }
                assert(rejected);
                std::puts("different valid kernel helper target: PASS (rejected)");
            }
            if (std::string(symbol) == "tv_map_entry") {
                options.proof_insns[0].imm = separate_map;
                auto paired = native_loader::load_from_fd(options);
                if (bpf_prog_test_run_opts(paired.prog_fd, &run)) return 1;
                assert(run.retval == 2);
                uint32_t ids[2]{};
                bpf_prog_info info{};
                info.nr_map_ids = 2; info.map_ids = reinterpret_cast<uintptr_t>(ids);
                uint32_t length = sizeof(info);
                if (bpf_obj_get_info_by_fd(paired.prog_fd, &info, &length)) return 1;
                bpf_map_info original_map{};
                length = sizeof(original_map);
                if (bpf_obj_get_info_by_fd(map_fd, &original_map, &length)) return 1;
                assert(info.nr_map_ids == 1 && ids[0] == original_map.id);
                native_loader::close_loaded_program(&paired);
                std::puts("separately loaded proof map relinked to original: PASS");
                int wrong_shape = bpf_map_create(BPF_MAP_TYPE_ARRAY, "tv_map", 4, 8, 1, nullptr);
                if (wrong_shape < 0) return 1;
                options.proof_insns[0].imm = wrong_shape;
                bool rejected = false;
                try {
                    auto wrong = native_loader::load_from_fd(options);
                    native_loader::close_loaded_program(&wrong);
                } catch (const std::exception &error) {
                    assert(std::string(error.what()).find("raw proof map layout differs from original program:") != std::string::npos);
                    rejected = true;
                }
                assert(rejected);
                if (close(wrong_shape)) return 1;
                std::puts("separate proof map layout mismatch: PASS (rejected)");
            }
            if (std::string(symbol) == "tv_helper_entry" || std::string(symbol) == "tv_map_entry" ||
                std::string(symbol) == "tv_hash_entry" || std::string(symbol) == "tv_readonly_entry") {
                const char *entry = std::string(symbol) == "tv_map_entry" ? "tv_proof_map" :
                    std::string(symbol) == "tv_readonly_entry" ? "tv_proof_readonly" :
                    std::string(symbol) == "tv_hash_entry" ? "tv_proof_hash" : "tv_proof_helper";
                std::ofstream manifest("build/fixture-manifest.json");
                manifest << "{\"objects\":[{\"program\":\"tv_loader\",\"native_object\":\"native-entry.o\","
                    "\"symbol\":\"" << symbol << "\",\"simulator_object\":\"simulator.bpf.o\","
                    "\"simulator_program\":\"" << entry << "\"}]}";
                manifest.close();
                if (!manifest) return 1;
                std::ofstream source("build/fixture-source.bin", std::ios::binary);
                source.write(reinterpret_cast<const char *>(proof.data()), proof.size() * sizeof(proof[0]));
                source.close();
                if (!source) return 1;
                if (setenv("BPFREJIT_NATIVE_LINK_BINARY", options.native_link_path.c_str(), 1)) return 1;
                native_loader_c_result result{};
                if (native_loader_load_from_fd_with_manifest_path_btf_and_attach(original,
                        "build/fixture-manifest.json", "build/fixture-source.bin", nullptr, 0,
                        0, nullptr, 0, 0, 0, 0, 0, 0, &result)) {
                    std::fprintf(stderr, "manifest simulator: %s\n", result.error);
                    return 1;
                }
                assert(result.replaced && result.prog_fd >= 0);
                if (bpf_prog_test_run_opts(result.prog_fd, &run)) {
                    std::perror("manifest simulator test run"); return 1;
                }
                assert(run.retval == 2);
                if (std::string(symbol) == "tv_map_entry" || std::string(symbol) == "tv_hash_entry") {
                    uint32_t ids[2]{};
                    bpf_prog_info info{};
                    info.nr_map_ids = 2; info.map_ids = reinterpret_cast<uintptr_t>(ids);
                    uint32_t length = sizeof(info);
                    if (bpf_obj_get_info_by_fd(result.prog_fd, &info, &length)) return 1;
                    bpf_map_info map_info{};
                    length = sizeof(map_info);
                    if (bpf_obj_get_info_by_fd(std::string(symbol) == "tv_hash_entry" ? hash_fd : map_fd, &map_info, &length)) return 1;
                    assert(info.nr_map_ids == 1 && ids[0] == map_info.id);
                }
                std::printf("manifest simulator %s: PASS (clang proof, original maps, bound native)\n", entry);
                if (std::string(symbol) == "tv_map_entry") {
                    for (bool wrong : {false, true}) {
                        std::ofstream configured("build/configured-map-manifest.json");
                        configured << "{\"objects\":[{\"program\":\"tv_loader\",\"native_object\":\"native-entry.o\","
                            "\"symbol\":\"tv_map_entry\",\"simulator_program\":\"tv_proof_map\","
                            "\"simulator_object\":\"" << (wrong ? "wrong-capacity/" : "runtime-config/")
                            << "simulator.bpf.o\"}]}";
                        configured.close();
                        if (!configured) return 1;
                        native_loader_c_result candidate{};
                        int status = native_loader_load_from_fd_with_manifest_path_btf_and_attach(original,
                            "build/configured-map-manifest.json", "build/fixture-source.bin", nullptr, 0,
                            0, nullptr, 0, 0, 0, 0, 0, 0, &candidate);
                        if (wrong) {
                            assert(status == -1 && candidate.prog_fd == -1);
                            assert(std::string(candidate.error).find("simulator proof map layout does not match source map") != std::string::npos);
                            std::puts("nonzero simulator map capacity mismatch: PASS (rejected)");
                        } else {
                            if (status) throw std::runtime_error(candidate.error);
                            if (bpf_prog_test_run_opts(candidate.prog_fd, &run)) return 1;
                            assert(run.retval == 2);
                            uint32_t id{};
                            bpf_prog_info configured_info{};
                            configured_info.nr_map_ids = 1;
                            configured_info.map_ids = reinterpret_cast<uintptr_t>(&id);
                            uint32_t size = sizeof(configured_info);
                            if (bpf_obj_get_info_by_fd(candidate.prog_fd, &configured_info, &size)) return 1;
                            bpf_map_info original_map{};
                            size = sizeof(original_map);
                            if (bpf_obj_get_info_by_fd(map_fd, &original_map, &size)) return 1;
                            assert(configured_info.nr_map_ids == 1 && id == original_map.id);
                            if (close(candidate.prog_fd)) return 1;
                            std::puts("runtime-configured simulator map capacity: PASS (original identity, native returned 2)");
                        }
                    }
                }
                if (close(result.prog_fd)) return 1;
                if (std::string(symbol) == "tv_readonly_entry") {
                    for (bool wrong : {false, true}) {
                        auto fixture = load_fixture(wrong ? "build/wrong-readonly/simulator.bpf.o" :
                            "build/simulator.bpf.o", "tv_proof_readonly");
                        options.proof_insns.assign(bpf_program__insns(fixture.program),
                            bpf_program__insns(fixture.program) + bpf_program__insn_cnt(fixture.program));
                        bool rejected = false;
                        try {
                            auto paired = native_loader::load_from_fd(options);
                            if (!wrong && bpf_prog_test_run_opts(paired.prog_fd, &run))
                                throw std::runtime_error("run readonly raw proof");
                            if (!wrong) assert(run.retval == 2);
                            native_loader::close_loaded_program(&paired);
                        } catch (const std::exception &error) {
                            if (!wrong) throw;
                            assert(std::string(error.what()).find("readonly proof data does not match native bytes") != std::string::npos);
                            rejected = true;
                        }
                        assert(rejected == wrong);
                        std::puts(wrong ? "raw readonly data mutation: PASS (rejected)" :
                            "raw readonly data: PASS (bound native returned 2)");
                    }
                }
                if (std::string(symbol) == "tv_helper_entry") {
                    std::ofstream negative("build/fixture-manifest.json");
                    negative << "{\"objects\":[{\"program\":\"tv_loader\",\"native_object\":\"native-entry.o\","
                        "\"symbol\":\"tv_helper_entry\",\"simulator_object\":\"simulator.bpf.o\","
                        "\"simulator_program\":\"tv_proof_private\"}]}";
                    negative.close();
                    if (!negative) return 1;
                    const int invalid = native_loader_load_from_fd_with_manifest_path_btf_and_attach(original,
                        "build/fixture-manifest.json", "build/fixture-source.bin", nullptr, 0,
                        0, nullptr, 0, 0, 0, 0, 0, 0, &result);
                    assert(invalid != 0 && result.prog_fd < 0);
                    std::puts("manifest invented internal-map state: PASS (rejected)");
                }
            }
            if (close(original)) { std::perror("close original"); return 1; }
        }
        // Same-sized DATASEC maps must preserve the original variable identities.
        auto data_fixture = load_fixture("build/simulator.bpf.o", "tv_proof_private");
        bpf_program *data_program = data_fixture.program;
        bpf_prog_info original_info{};
        uint32_t info_size = sizeof(original_info);
        if (bpf_obj_get_info_by_fd(bpf_program__fd(data_program), &original_info, &info_size))
            throw std::runtime_error("query original DATASEC program");
        uint32_t writable_data_id = 0;
        bpf_map *data_map;
        bpf_object__for_each_map(data_map, data_fixture.object.get()) {
            if (!bpf_map__is_internal(data_map) || (bpf_map__map_flags(data_map) & BPF_F_RDONLY_PROG)) continue;
            bpf_map_info map_info{};
            info_size = sizeof(map_info);
            if (bpf_obj_get_info_by_fd(bpf_map__fd(data_map), &map_info, &info_size))
                throw std::runtime_error("query original writable DATASEC");
            assert(!writable_data_id);
            writable_data_id = map_info.id;
        }
        assert(writable_data_id);
        for (bool wrong_layout : {false, true}) {
            std::ofstream manifest("build/data-manifest.json");
            manifest << "{\"objects\":[{\"program\":\"" << original_info.name
                << "\",\"native_object\":\"native-entry.o\",\"symbol\":\"tv_short_entry\","
                "\"simulator_program\":\"tv_proof_private\",\"simulator_object\":\""
                << (wrong_layout ? "wrong-layout/" : "") << "simulator.bpf.o\"}]}";
            manifest.close();
            if (!manifest) return 1;
            native_loader::FdLoadOptions options{};
            options.original_prog_fd = bpf_program__fd(data_program);
            options.expected_attach_type = bpf_program__expected_attach_type(data_program);
            options.source_insns.assign(bpf_program__insns(data_program),
                bpf_program__insns(data_program) + bpf_program__insn_cnt(data_program));
            options.manifest_path = std::filesystem::absolute("build/data-manifest.json");
            options.native_link_path = std::filesystem::absolute(
                "../x86/native_lab/native_link/target/release/native-link");
            bool rejected = false;
            try {
                auto loaded = native_loader::load_from_fd(options);
                assert(loaded.replaced && loaded.prog_fd >= 0);
                uint32_t original_ids[2]{}, loaded_ids[2]{};
                bpf_prog_info info{};
                info.nr_map_ids = 2; info.map_ids = reinterpret_cast<uintptr_t>(original_ids);
                info_size = sizeof(info);
                if (bpf_obj_get_info_by_fd(options.original_prog_fd, &info, &info_size))
                    throw std::runtime_error("query original DATASEC map IDs");
                assert(info.nr_map_ids && info.nr_map_ids <= 2);
                uint32_t original_count = info.nr_map_ids;
                info = {};
                info.nr_map_ids = 2; info.map_ids = reinterpret_cast<uintptr_t>(loaded_ids);
                info_size = sizeof(info);
                if (bpf_obj_get_info_by_fd(loaded.prog_fd, &info, &info_size))
                    throw std::runtime_error("query bound DATASEC map IDs");
                assert(info.nr_map_ids && info.nr_map_ids <= 2);
                bool retains_writable_data = false;
                for (uint32_t index = 0; index < info.nr_map_ids; index++) {
                    assert(std::find(original_ids, original_ids + original_count, loaded_ids[index]) != original_ids + original_count);
                    retains_writable_data |= loaded_ids[index] == writable_data_id;
                }
                assert(retains_writable_data);
                native_loader::close_loaded_program(&loaded);
            } catch (const std::exception &error) {
                if (!wrong_layout) throw;
                assert(std::string(error.what()).find("simulator internal map BTF layout differs") != std::string::npos);
                rejected = true;
            }
            assert(rejected == wrong_layout);
            std::puts(wrong_layout ? "same-sized wrong BTF variable: PASS (rejected)" :
                "manifest internal DATASEC: PASS (original map ID retained)");
            auto raw_fixture = load_fixture(wrong_layout ? "build/wrong-layout/simulator.bpf.o" :
                "build/simulator.bpf.o", "tv_proof_private");
            bpf_program *raw_program = raw_fixture.program;
            options.native_object_path = std::filesystem::absolute("build/native-entry.o");
            options.symbol_name = "tv_short_entry";
            options.proof_insns.assign(bpf_program__insns(raw_program),
                bpf_program__insns(raw_program) + bpf_program__insn_cnt(raw_program));
            rejected = false;
            try {
                auto loaded = native_loader::load_from_fd(options);
                native_loader::close_loaded_program(&loaded);
            } catch (const std::exception &error) {
                if (!wrong_layout) throw;
                assert(std::string(error.what()).find("simulator internal map BTF layout differs") != std::string::npos);
                rejected = true;
            }
            assert(rejected == wrong_layout);
            std::puts(wrong_layout ? "raw proof wrong BTF variable: PASS (rejected)" :
                "raw proof matching DATASEC: PASS (relinked)");
        }
    } catch (const std::exception &error) {
        std::fprintf(stderr, "shared loader: %s\n", error.what());
        return 1;
    }
    if (close(map_fd) || close(hash_fd) || close(separate_map)) {
        std::perror("close fixture map");
        return 1;
    }
    return 0;
}
