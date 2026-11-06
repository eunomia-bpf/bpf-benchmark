#include "../libnativeloader/include/native_loader.hpp"
#include <bpf/bpf.h>
#include <cassert>
#include <cstdio>
#include <exception>
#include <fstream>
#include <unistd.h>

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
    try {
        for (const char *symbol : {"tv_short_entry", "tv_long_entry", "tv_helper_entry", "tv_map_entry", "tv_hash_entry", "tv_large_entry"}) {
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
            if (std::string(symbol) == "tv_helper_entry" || std::string(symbol) == "tv_map_entry" || std::string(symbol) == "tv_hash_entry") {
                const char *entry = std::string(symbol) == "tv_map_entry" ? "tv_proof_map" :
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
                if (close(result.prog_fd)) return 1;
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
    } catch (const std::exception &error) {
        std::fprintf(stderr, "shared loader: %s\n", error.what());
        return 1;
    }
    if (close(map_fd) || close(hash_fd)) {
        std::perror("close fixture map");
        return 1;
    }
    return 0;
}
