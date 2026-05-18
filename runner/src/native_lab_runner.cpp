// Native-lab kernel runner.
//
// Mirrors run_kernel's measurement contract but loads a userspace-linked
// x86 byte blob (produced by ebpf-vm/x86/native_lab/native_link) into a
// minimal BPF stub via the `bpf_x86_native_lab` kinsn. The kinsn splats
// the blob bytes into the JIT image so the native function runs in place
// of the BPF body. Input prep, packet construction, and result extraction
// reuse the shared kernel_test_run helpers; the only logic that lives in
// this file is the parts that are genuinely native_lab-specific:
//   * locate the module's kernel BTF fd and the emit kfunc's btf_id,
//   * upload the blob in <=128-byte chunks through debugfs,
//   * construct the tiny `(sidecar; call kinsn)*N; exit` stub program.

#include "micro_exec.hpp"
#include "kernel_test_run.hpp"

#include <bpf/bpf.h>
#include <bpf/btf.h>
#include <bpf/libbpf.h>
#include <linux/bpf.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/mount.h>
#include <sys/syscall.h>
#include <sys/stat.h>
#include <unistd.h>

#include <algorithm>
#include <chrono>
#include <cstdint>
#include <cstring>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>

namespace {

constexpr const char *kModuleName = "bpf_x86_native_lab";
constexpr const char *kKfuncName = "bpf_x86_native_lab_emit";
constexpr const char *kModuleBtfPath = "/sys/kernel/btf/bpf_x86_native_lab";
constexpr const char *kVmlinuxBtfPath = "/sys/kernel/btf/vmlinux";
constexpr const char *kDebugfsDir = "/sys/kernel/debug";
constexpr const char *kBlobPathFmt = "/sys/kernel/debug/bpf_x86_native_lab/blob%u";
constexpr uint32_t kChunkBytes = 128;
constexpr uint32_t kMaxBlobs = 64;

#ifndef BPF_PSEUDO_KINSN_SIDECAR
#define BPF_PSEUDO_KINSN_SIDECAR 3
#endif
#ifndef BPF_PSEUDO_KINSN_CALL
#define BPF_PSEUDO_KINSN_CALL 4
#endif

void ensure_debugfs_mounted()
{
    struct stat st = {};
    if (stat("/sys/kernel/debug/bpf_x86_native_lab", &st) == 0 && S_ISDIR(st.st_mode)) {
        return;
    }
    (void)mount("none", kDebugfsDir, "debugfs", 0, nullptr);
}

uint32_t upload_blob(const std::vector<uint8_t> &blob)
{
    if (blob.empty()) {
        fail("native blob is empty");
    }
    uint32_t chunks = static_cast<uint32_t>((blob.size() + kChunkBytes - 1) / kChunkBytes);
    if (chunks > kMaxBlobs) {
        fail("native blob requires " + std::to_string(chunks) +
             " chunks but module only supports " + std::to_string(kMaxBlobs));
    }
    for (uint32_t i = 0; i < chunks; i++) {
        char path[128];
        snprintf(path, sizeof(path), kBlobPathFmt, i);
        int fd = open(path, O_WRONLY | O_TRUNC);
        if (fd < 0) {
            fail(std::string("open ") + path + ": " + std::strerror(errno));
        }
        size_t off = static_cast<size_t>(i) * kChunkBytes;
        size_t l = std::min<size_t>(kChunkBytes, blob.size() - off);
        ssize_t n = write(fd, blob.data() + off, l);
        int saved = errno;
        close(fd);
        if (n != static_cast<ssize_t>(l)) {
            fail(std::string("write ") + path + ": " + std::strerror(saved));
        }
    }
    return chunks;
}

// Walk every loaded kernel BTF and return an fd pointing at the one named
// `bpf_x86_native_lab`. The caller owns the fd. libbpf doesn't expose a
// direct "find module btf by name" helper, so we iterate BPF_BTF_GET_NEXT_ID.
int find_module_btf_fd()
{
    uint32_t id = 0;
    for (;;) {
        uint32_t next = 0;
        if (bpf_btf_get_next_id(id, &next) < 0) {
            if (errno == ENOENT) {
                break;
            }
            fail(std::string("bpf_btf_get_next_id: ") + std::strerror(errno));
        }
        id = next;
        int fd = bpf_btf_get_fd_by_id(id);
        if (fd < 0) {
            continue;
        }
        bpf_btf_info info = {};
        char name[64] = {};
        info.name = reinterpret_cast<uintptr_t>(name);
        info.name_len = sizeof(name);
        uint32_t info_len = sizeof(info);
        if (bpf_obj_get_info_by_fd(fd, &info, &info_len) == 0
            && std::strcmp(name, kModuleName) == 0) {
            return fd;
        }
        close(fd);
    }
    fail(std::string("BTF for module ") + kModuleName +
         " is not loaded (insmod " + kModuleName + ".ko)");
    return -1;
}

int find_kfunc_btf_id()
{
    struct btf *vmlinux = btf__parse(kVmlinuxBtfPath, nullptr);
    if (libbpf_get_error(vmlinux)) {
        fail(std::string("btf__parse vmlinux: ")
             + std::strerror(static_cast<int>(-libbpf_get_error(vmlinux))));
    }
    struct btf *mod = btf__parse_split(kModuleBtfPath, vmlinux);
    if (libbpf_get_error(mod)) {
        btf__free(vmlinux);
        fail(std::string("btf__parse_split module: ")
             + std::strerror(static_cast<int>(-libbpf_get_error(mod))));
    }
    int id = btf__find_by_name_kind(mod, kKfuncName, BTF_KIND_FUNC);
    btf__free(mod);
    btf__free(vmlinux);
    if (id < 0) {
        fail(std::string("kfunc ") + kKfuncName + " not found in module BTF");
    }
    return id;
}

// Build the (sidecar; call kinsn)*N; exit stub and BPF_PROG_LOAD it via
// libbpf's bpf_prog_load + bpf_prog_load_opts.fd_array. Returns prog fd.
int load_stub_prog(int kfunc_btf_id, int mod_btf_fd, uint32_t chunks,
                   uint32_t prog_type_value)
{
    if (chunks == 0) {
        fail("chunks must be > 0");
    }
    std::vector<bpf_insn> insns;
    insns.reserve(static_cast<size_t>(2) * chunks + 1);
    for (uint32_t i = 0; i < chunks; i++) {
        bpf_insn sidecar = {
            .code = BPF_ALU64 | BPF_MOV | BPF_K,
            .dst_reg = 0,
            .src_reg = BPF_PSEUDO_KINSN_SIDECAR,
            .off = 0,
            .imm = static_cast<int32_t>(i),
        };
        insns.push_back(sidecar);
        bpf_insn call = {
            .code = BPF_JMP | BPF_CALL,
            .dst_reg = 0,
            .src_reg = BPF_PSEUDO_KINSN_CALL,
            .off = 1, // fd_array slot for module BTF
            .imm = kfunc_btf_id,
        };
        insns.push_back(call);
    }
    insns.push_back(bpf_insn{
        .code = BPF_JMP | BPF_EXIT, .dst_reg = 0, .src_reg = 0, .off = 0, .imm = 0,
    });

    // fd_array[0] is the verifier's pre-scan slot; daemon convention is to
    // duplicate the module BTF fd there. fd_array[1] is what `off=1` in the
    // kinsn call insn resolves to.
    int fd_array[2] = {mod_btf_fd, mod_btf_fd};
    std::vector<char> log_buf(32 * 1024, '\0');

    LIBBPF_OPTS(bpf_prog_load_opts, opts,
        .fd_array = fd_array,
        .log_level = 1,
        .log_size = static_cast<uint32_t>(log_buf.size()),
        .log_buf = log_buf.data(),
    );
    int fd = bpf_prog_load(static_cast<bpf_prog_type>(prog_type_value),
                           "native_lab_stub", "GPL",
                           insns.data(), insns.size(), &opts);
    if (fd < 0) {
        fail(std::string("bpf_prog_load (native_lab stub): ")
             + std::strerror(errno) + "\nverifier log:\n" + log_buf.data());
    }
    return fd;
}

std::vector<uint8_t> read_blob_file(const std::filesystem::path &path)
{
    std::ifstream f(path, std::ios::binary);
    if (!f) {
        fail("read native blob: " + path.string());
    }
    return std::vector<uint8_t>((std::istreambuf_iterator<char>(f)),
                                std::istreambuf_iterator<char>());
}

uint32_t prog_type_from_option(const std::string &name)
{
    if (name == "xdp") return BPF_PROG_TYPE_XDP;
    if (name == "sched_cls") return BPF_PROG_TYPE_SCHED_CLS;
    if (name == "cgroup_skb") return BPF_PROG_TYPE_CGROUP_SKB;
    fail("unsupported --native-lab-prog-type: " + name);
    return 0; // unreachable
}

} // namespace

std::vector<sample_result> run_kernel_native_lab(const cli_options &options)
{
    initialize_micro_exec_process();

    const auto memory_prepare_start = std::chrono::steady_clock::now();
    auto input_bytes = materialize_memory(options.memory, options.input_size);
    if (options.input_size != 0 && input_bytes.size() < options.input_size) {
        input_bytes.resize(options.input_size, 0);
    }
    const auto memory_prepare_end = std::chrono::steady_clock::now();

    const uint32_t prog_type_value = prog_type_from_option(options.native_lab_prog_type);

    // Packet layout matches what kernel_runner builds for the same prog
    // type (8-byte result prefix for staged/packet xdp, ethernet prefix
    // for skb-context programs).
    const auto pkt_prepare_start = std::chrono::steady_clock::now();
    std::vector<uint8_t> packet = build_packet_input(input_bytes, prog_type_value);
    std::vector<uint8_t> packet_out(packet_output_capacity(options, packet.size()), 0);
    const auto pkt_prepare_end = std::chrono::steady_clock::now();

    const auto blob_read_start = std::chrono::steady_clock::now();
    auto blob = read_blob_file(options.program);
    const auto blob_read_end = std::chrono::steady_clock::now();

    const auto upload_start = std::chrono::steady_clock::now();
    ensure_debugfs_mounted();
    uint32_t chunks = upload_blob(blob);
    const auto upload_end = std::chrono::steady_clock::now();

    const auto prog_load_start = std::chrono::steady_clock::now();
    int mod_btf_fd = find_module_btf_fd();
    int kfunc_id = find_kfunc_btf_id();
    int prog_fd = load_stub_prog(kfunc_id, mod_btf_fd, chunks, prog_type_value);
    const auto prog_load_end = std::chrono::steady_clock::now();
    close(mod_btf_fd);

    // Warmup (1 iteration to populate caches + verify mechanism).
    bpf_test_run_opts warm = {};
    warm.sz = sizeof(warm);
    warm.repeat = 1;
    warm.data_in = packet.data();
    warm.data_size_in = packet.size();
    warm.data_out = packet_out.data();
    warm.data_size_out = packet_out.size();
    if (bpf_prog_test_run_opts(prog_fd, &warm) < 0) {
        close(prog_fd);
        fail(std::string("warmup test_run failed: ") + std::strerror(errno));
    }

    // Measured run.
    bpf_test_run_opts test_opts = {};
    test_opts.sz = sizeof(test_opts);
    test_opts.repeat = options.repeat;
    test_opts.data_in = packet.data();
    test_opts.data_size_in = packet.size();
    test_opts.data_out = packet_out.data();
    test_opts.data_size_out = packet_out.size();
    const auto run_start = std::chrono::steady_clock::now();
    const int run_err = bpf_prog_test_run_opts(prog_fd, &test_opts);
    const auto run_end = std::chrono::steady_clock::now();
    if (run_err) {
        close(prog_fd);
        fail(std::string("bpf_prog_test_run_opts failed: ") + std::strerror(errno));
    }

    // Extract the u64 result from packet_out. For XDP/sched_cls the BPF
    // program sees skb->data at offset 0 of the user packet, so native_lab
    // writes (and we read) at offset 0. For cgroup_skb the kernel
    // bpf_prog_test_run_skb path strips the L2 header during prog setup
    // (`is_l2 = false`) and pushes it back afterwards -- both runtimes write
    // their u64 at byte 14 of the returned packet buffer, which is the
    // start of the L3 payload `build_packet_input` reserves for the result.
    size_t result_off = 0;
    if (prog_type_value == BPF_PROG_TYPE_CGROUP_SKB) {
        result_off = 14; /* kEthernetHeaderSize */
    }
    if (packet_out.size() < result_off + sizeof(uint64_t)) {
        close(prog_fd);
        fail("native_lab: packet_out too small to hold u64 result at offset "
             + std::to_string(result_off));
    }
    uint64_t result_word = 0;
    std::memcpy(&result_word, packet_out.data() + result_off, sizeof(result_word));

    close(prog_fd);

    sample_result sample;
    sample.compile_ns = elapsed_ns(blob_read_start, blob_read_end)
                      + elapsed_ns(upload_start, upload_end)
                      + elapsed_ns(prog_load_start, prog_load_end);
    sample.exec_ns = test_opts.duration;  // kernel reports per-iter ns
    sample.timing_source = "ktime";
    sample.timing_source_wall = "wall_steady";
    sample.wall_exec_ns = elapsed_ns(run_start, run_end);
    sample.result = result_word;
    sample.retval = test_opts.retval;
    sample.code_size = { .bpf_bytecode_bytes = 0, .native_code_bytes = blob.size() };
    sample.phases_ns = {
        {"memory_prepare_ns", elapsed_ns(memory_prepare_start, memory_prepare_end)},
        {"packet_prepare_ns", elapsed_ns(pkt_prepare_start, pkt_prepare_end)},
        {"blob_read_ns", elapsed_ns(blob_read_start, blob_read_end)},
        {"blob_upload_ns", elapsed_ns(upload_start, upload_end)},
        {"prog_load_ns", elapsed_ns(prog_load_start, prog_load_end)},
        {"prog_run_wall_ns", elapsed_ns(run_start, run_end)},
    };
    return {std::move(sample)};
}
