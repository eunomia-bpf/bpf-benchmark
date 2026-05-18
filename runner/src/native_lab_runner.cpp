// Native-lab kernel runner.
//
// Mirrors run_kernel's measurement contract but loads a userspace-linked
// x86 byte blob (produced by ebpf-vm/x86/native_lab/native_link) into a
// minimal BPF stub via the `bpf_x86_native_lab` kinsn. The kinsn splats
// the blob bytes into the JIT image so the native function runs in place
// of the BPF body. Everything else (TEST_RUN, input/output buffers, retval
// reporting) uses the same kernel surface as the existing kernel runner.

#include "micro_exec.hpp"

#include <bpf/bpf.h>
#include <bpf/btf.h>
#include <bpf/libbpf.h>
#include <linux/bpf.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <sys/mount.h>
#include <sys/stat.h>
#include <unistd.h>

#include <algorithm>
#include <chrono>
#include <cstdint>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
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

constexpr uint8_t kAlu64 = 0x07;
constexpr uint8_t kMov = 0xb0;
constexpr uint8_t kImmSrc = 0x00;
constexpr uint8_t kJmp = 0x05;
constexpr uint8_t kCall = 0x80;
constexpr uint8_t kExit = 0x90;

struct __attribute__((packed)) raw_bpf_insn {
    uint8_t code;
    uint8_t dst_src;
    int16_t off;
    int32_t imm;
};
static_assert(sizeof(raw_bpf_insn) == 8, "bpf insn must be 8 bytes");

int sys_bpf(enum bpf_cmd cmd, union bpf_attr *attr, unsigned int size)
{
    return syscall(__NR_bpf, cmd, attr, size);
}

void ensure_debugfs_mounted()
{
    // If /sys/kernel/debug is already a debugfs mount, the blob nodes exist.
    struct stat st = {};
    if (stat("/sys/kernel/debug/bpf_x86_native_lab", &st) == 0 && S_ISDIR(st.st_mode)) {
        return;
    }
    // Best effort: try mounting; failures are deferred until the open() below.
    (void)mount("none", kDebugfsDir, "debugfs", 0, nullptr);
}

void upload_chunk(uint32_t id, const uint8_t *bytes, size_t len)
{
    char path[128];
    snprintf(path, sizeof(path), kBlobPathFmt, id);
    int fd = open(path, O_WRONLY | O_TRUNC);
    if (fd < 0) {
        fail(std::string("open ") + path + ": " + std::strerror(errno));
    }
    ssize_t n = write(fd, bytes, len);
    int saved = errno;
    close(fd);
    if (n != static_cast<ssize_t>(len)) {
        fail(std::string("write ") + path + ": " + std::strerror(saved));
    }
}

uint32_t upload_blob(const std::vector<uint8_t> &blob)
{
    if (blob.empty()) {
        fail("native blob is empty");
    }
    uint32_t chunks = static_cast<uint32_t>((blob.size() + kChunkBytes - 1) / kChunkBytes);
    if (chunks == 0) {
        chunks = 1;
    }
    if (chunks > kMaxBlobs) {
        fail("native blob requires " + std::to_string(chunks) +
             " chunks but module only supports " + std::to_string(kMaxBlobs));
    }
    for (uint32_t i = 0; i < chunks; i++) {
        size_t off = static_cast<size_t>(i) * kChunkBytes;
        size_t l = std::min<size_t>(kChunkBytes, blob.size() - off);
        upload_chunk(i, blob.data() + off, l);
    }
    return chunks;
}

int find_module_btf_fd()
{
    uint32_t id = 0;
    for (;;) {
        union bpf_attr attr = {};
        attr.start_id = id;
        if (sys_bpf(BPF_BTF_GET_NEXT_ID, &attr,
                    sizeof(attr.start_id) + sizeof(attr.next_id)) < 0) {
            if (errno == ENOENT) {
                break;
            }
            fail(std::string("BPF_BTF_GET_NEXT_ID: ") + std::strerror(errno));
        }
        id = attr.next_id;

        memset(&attr, 0, sizeof(attr));
        attr.btf_id = id;
        int fd = sys_bpf(BPF_BTF_GET_FD_BY_ID, &attr, sizeof(attr));
        if (fd < 0) {
            continue;
        }
        struct bpf_btf_info info = {};
        char name[64] = {};
        info.name = reinterpret_cast<uintptr_t>(name);
        info.name_len = sizeof(name);
        memset(&attr, 0, sizeof(attr));
        attr.info.bpf_fd = fd;
        attr.info.info_len = sizeof(info);
        attr.info.info = reinterpret_cast<uintptr_t>(&info);
        if (sys_bpf(BPF_OBJ_GET_INFO_BY_FD, &attr, sizeof(attr)) == 0
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
        fail(std::string("btf__parse vmlinux: ") +
             std::strerror(-libbpf_get_error(vmlinux)));
    }
    struct btf *mod = btf__parse_split(kModuleBtfPath, vmlinux);
    if (libbpf_get_error(mod)) {
        btf__free(vmlinux);
        fail(std::string("btf__parse_split module: ") +
             std::strerror(-libbpf_get_error(mod)));
    }
    int id = btf__find_by_name_kind(mod, kKfuncName, BTF_KIND_FUNC);
    btf__free(mod);
    btf__free(vmlinux);
    if (id < 0) {
        fail(std::string("kfunc ") + kKfuncName + " not found in module BTF");
    }
    return id;
}

int load_stub_prog(int kfunc_btf_id, int mod_btf_fd, uint32_t chunks,
                   uint32_t prog_type_value)
{
    if (chunks == 0) {
        fail("chunks must be > 0");
    }
    std::vector<raw_bpf_insn> insns;
    insns.reserve(static_cast<size_t>(2) * chunks + 1);
    for (uint32_t i = 0; i < chunks; i++) {
        raw_bpf_insn sidecar = {};
        sidecar.code = kAlu64 | kMov | kImmSrc;
        sidecar.dst_src = static_cast<uint8_t>((BPF_PSEUDO_KINSN_SIDECAR & 0xf) << 4);
        sidecar.imm = static_cast<int32_t>(i);
        insns.push_back(sidecar);
        raw_bpf_insn call = {};
        call.code = kJmp | kCall;
        call.dst_src = static_cast<uint8_t>((BPF_PSEUDO_KINSN_CALL & 0xf) << 4);
        call.off = 1; /* fd_array slot for module BTF */
        call.imm = kfunc_btf_id;
        insns.push_back(call);
    }
    raw_bpf_insn exit_insn = {};
    exit_insn.code = kJmp | kExit;
    insns.push_back(exit_insn);

    /* fd_array[0] is the verifier pre-scan slot; mirror daemon convention
     * of duplicating the module BTF fd. fd_array[1] is the slot off=1
     * resolves to for the kinsn call.
     */
    int fd_array[2] = {mod_btf_fd, mod_btf_fd};
    std::vector<char> log_buf(32 * 1024, '\0');
    union bpf_attr attr = {};
    attr.prog_type = prog_type_value;
    attr.insn_cnt = static_cast<uint32_t>(insns.size());
    attr.insns = reinterpret_cast<uintptr_t>(insns.data());
    attr.license = reinterpret_cast<uintptr_t>("GPL");
    attr.log_level = 1;
    attr.log_size = log_buf.size();
    attr.log_buf = reinterpret_cast<uintptr_t>(log_buf.data());
    attr.fd_array = reinterpret_cast<uintptr_t>(fd_array);
    int fd = sys_bpf(BPF_PROG_LOAD, &attr, sizeof(attr));
    if (fd < 0) {
        std::ostringstream msg;
        msg << "BPF_PROG_LOAD (native_lab stub) failed: " << std::strerror(errno);
        msg << "\nverifier log:\n" << log_buf.data();
        fail(msg.str());
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

    /* Packet for XDP TEST_RUN: 8-byte result prefix + input bytes. The
     * micro `DEFINE_*_XDP_BENCH` macros expect this layout: result is
     * written to data[0..8] and the function body reads from data[8..]. */
    const auto pkt_prepare_start = std::chrono::steady_clock::now();
    std::vector<uint8_t> packet;
    packet.resize(8 + input_bytes.size(), 0);
    std::memcpy(packet.data() + 8, input_bytes.data(), input_bytes.size());
    std::vector<uint8_t> packet_out(packet.size(), 0);
    const auto pkt_prepare_end = std::chrono::steady_clock::now();

    const auto blob_read_start = std::chrono::steady_clock::now();
    auto blob = read_blob_file(options.program);
    const auto blob_read_end = std::chrono::steady_clock::now();

    const auto upload_start = std::chrono::steady_clock::now();
    ensure_debugfs_mounted();
    uint32_t chunks = upload_blob(blob);
    const auto upload_end = std::chrono::steady_clock::now();

    uint32_t prog_type_value = BPF_PROG_TYPE_XDP;
    if (options.native_lab_prog_type == "xdp") {
        prog_type_value = BPF_PROG_TYPE_XDP;
    } else if (options.native_lab_prog_type == "sched_cls") {
        prog_type_value = BPF_PROG_TYPE_SCHED_CLS;
    } else if (options.native_lab_prog_type == "cgroup_skb") {
        prog_type_value = BPF_PROG_TYPE_CGROUP_SKB;
    } else {
        fail("unsupported --native-lab-prog-type: " + options.native_lab_prog_type);
    }

    const auto prog_load_start = std::chrono::steady_clock::now();
    int mod_btf_fd = find_module_btf_fd();
    int kfunc_id = find_kfunc_btf_id();
    int prog_fd = load_stub_prog(kfunc_id, mod_btf_fd, chunks, prog_type_value);
    const auto prog_load_end = std::chrono::steady_clock::now();
    close(mod_btf_fd);

    /* Warm cache + verify mechanism. */
    {
        bpf_test_run_opts warm = {};
        warm.sz = sizeof(warm);
        warm.repeat = 1;
        warm.data_in = packet.data();
        warm.data_size_in = packet.size();
        warm.data_out = packet_out.data();
        warm.data_size_out = packet_out.size();
        const int err = bpf_prog_test_run_opts(prog_fd, &warm);
        if (err) {
            close(prog_fd);
            fail(std::string("warmup test_run failed: ") + std::strerror(errno));
        }
    }

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

    /* Kernel reports `duration` as the average per-iteration ns; the
     * existing kernel_runner reports exec_ns in the same unit so the
     * micro driver's downstream comparison stays apples-to-apples. */
    const uint64_t exec_ns = test_opts.duration;

    /* Many micro programs write a u64 LE result to packet[0..8]; read it
     * out so paper-side analysis can confirm output identity against the
     * BPF baseline. */
    uint64_t result_word = 0;
    if (packet_out.size() >= 8) {
        for (int i = 0; i < 8; i++) {
            result_word |= static_cast<uint64_t>(packet_out[i]) << (i * 8);
        }
    }

    close(prog_fd);

    sample_result sample;
    sample.compile_ns =
        elapsed_ns(blob_read_start, blob_read_end) +
        elapsed_ns(upload_start, upload_end) +
        elapsed_ns(prog_load_start, prog_load_end);
    sample.exec_ns = exec_ns;
    sample.timing_source = "ktime";
    sample.timing_source_wall = "wall_steady";
    sample.wall_exec_ns = elapsed_ns(run_start, run_end);
    sample.result = result_word;
    sample.retval = test_opts.retval;
    sample.code_size = {
        .bpf_bytecode_bytes = 0,
        .native_code_bytes = blob.size(),
    };
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
