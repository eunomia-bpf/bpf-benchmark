/* Capture the actual production loader's verifier-visible simple-family artifact. */
#include "../libnativeloader/include/native_loader.hpp"
#include "../../kinsn/module/include/native_lab_checked_wire.h"
#include <bpf/bpf.h>
#include <bpf/libbpf.h>
#include <cerrno>
#include <cstdio>
#include <cstring>
#include <fcntl.h>
#include <fstream>
#include <filesystem>
#include <cstdlib>
#include <iterator>
#include <memory>
#include <stdexcept>
#include <sys/mount.h>
#include <sys/reboot.h>
#include <sys/syscall.h>
#include <unistd.h>

static void require(bool ok, const char *what)
{
    if (!ok) throw std::runtime_error(std::string(what) + ": " + std::strerror(errno));
}
static void run(int fd, const char *name)
{
    unsigned char input[128], output[128];
    std::memset(input, 0x5a, sizeof(input));
    bpf_test_run_opts test{};
    test.sz = sizeof(test); test.data_in = input; test.data_size_in = sizeof(input);
    test.data_out = output; test.data_size_out = sizeof(output); test.repeat = 1;
    require(!bpf_prog_test_run_opts(fd, &test), "run simple program");
    const unsigned char expected[] = {0x4e, 0x61, 0xbc, 0, 0, 0, 0, 0};
    require(test.retval == 2 && test.data_size_out == sizeof(output) &&
        !std::memcmp(output, expected, sizeof(expected)) &&
        !std::memcmp(output + 8, input + 8, sizeof(input) - 8), "simple packet/return mismatch");
    std::printf("%s: retval2, exact8-byte stores,120 untouched bytes: PASS\n", name);
}
int main(int argc, char **argv)
{
    try {
        require(argc <= 2, "capture accepts one native entry symbol");
        const char *symbol = argc == 2 ? argv[1] : "simple_xdp";
        for (const auto &item : {std::pair{"sysfs", "/sys"}, {"proc", "/proc"},
                {"debugfs", "/sys/kernel/debug"}})
            require(!mount(item.first, item.second, item.first, 0, nullptr), "mount capture filesystems");
        int module = open("/module.ko", O_RDONLY);
        require(module >= 0 && !syscall(SYS_finit_module, module, "capture_checked=1", 0), "insert capture module");
        require(!close(module), "close module");
        std::unique_ptr<bpf_object, decltype(&bpf_object__close)> object(
            bpf_object__open_file("/simple.bpf.o", nullptr), bpf_object__close);
        require(object && !libbpf_get_error(object.get()), "open actual clang proof");
        require(!bpf_object__load(object.get()), "load original context program");
        bpf_program *program = bpf_object__next_program(object.get(), nullptr);
        require(program && !bpf_object__next_program(object.get(), program), "single entry");
        native_loader::FdLoadOptions options{};
        options.original_prog_fd = bpf_program__fd(program);
        options.source_insns.assign(bpf_program__insns(program),
            bpf_program__insns(program) + bpf_program__insn_cnt(program));
        options.proof_insns = options.source_insns;
        options.proof_object_path = "/simple.bpf.o";
        options.expected_attach_type = bpf_program__expected_attach_type(program);
        options.prog_flags = bpf_program__flags(program);
        options.native_object_path = "/simple.o";
        options.symbol_name = symbol;
        options.native_link_path = "/native-link";
        require(!setenv("BPFREJIT_NATIVE_LOADER_TV_DIR", "/capture", 1), "enable per-program capture");
        auto loaded = native_loader::load_from_fd(options);
        require(loaded.replaced && loaded.prog_fd >= 0, "actual generation-bound replacement");
        std::ifstream capture("/sys/kernel/debug/bpf_arm64_native_lab/checked_proof", std::ios::binary);
        require(bool(capture), "open checked snapshot");
        std::vector<unsigned char> bytes{std::istreambuf_iterator<char>(capture), {}};
        require(!capture.bad() && bytes.size() >= sizeof(native_lab_checked_header), "read checked snapshot");
        native_lab_checked_header head;
        std::memcpy(&head, bytes.data(), sizeof(head));
        require(head.version == 1 && head.prog_insns == options.proof_insns.size() + 1 &&
            head.regions == 1 && !head.map_refs && !head.helper_refs && head.actual_generation &&
            head.binding.proof_insns == options.proof_insns.size() && head.binding.abi_mask == 0 &&
            head.binding.native_size && head.binding.expected_attach_type == options.expected_attach_type &&
            head.binding.source_prog_id == loaded.original_prog_id, "actual artifact identity/extent");
        auto saved = [&](const std::filesystem::path &path) {
            std::ifstream input(path, std::ios::binary);
            require(bool(input), "open exported artifact");
            std::vector<unsigned char> value{std::istreambuf_iterator<char>(input), {}};
            require(!input.bad(), "read exported artifact");
            return value;
        };
        auto record = [&](const native_loader::LoadedProgram &item) {
            return std::filesystem::path("/capture") /
                (std::to_string(item.original_prog_id) + "-" + std::to_string(item.native_prog_id));
        };
        auto print_record = [&](const std::filesystem::path &path) {
            for (auto name : {"emitted.bin", "checked.snapshot.bin", "native.bin", "native.relocs", "proof-input.bin",
                    "jit.bin", "stub.bin", "jit-addresses.bin", "jit-lengths.bin", "load.json"}) {
                std::printf("TV_EXPORT %s/%s ", path.filename().c_str(), name);
                for (unsigned char byte : saved(path / name)) std::printf("%02x", byte);
                std::puts("");
            }
        };
        auto first = record(loaded);
        require(saved(first / "checked.snapshot.bin") == bytes, "automatic/direct snapshot equality");
        auto proof = saved(first / "proof-input.bin");
        require(proof.size() == options.proof_insns.size() * sizeof(bpf_insn) &&
            !std::memcmp(proof.data(), options.proof_insns.data(), proof.size()), "exact linked proof input");
        require(saved(first / "native.bin").size() == head.binding.native_size && saved(first / "native.relocs").empty(),
            "exact linked native extent");
        for (auto name : {"jit.bin", "stub.bin", "jit-addresses.bin", "jit-lengths.bin", "load.json"})
            require(!saved(first / name).empty(), "complete successful export");
        auto next = native_loader::load_from_fd(options);
        require(next.replaced && next.prog_fd >= 0 && record(next) != first,
            "second load has a distinct program record");
        require(saved(first / "checked.snapshot.bin") == bytes &&
            saved(first / "emitted.bin") != saved(record(next) / "emitted.bin") &&
            saved(record(next) / "checked.snapshot.bin") != bytes,
            "first snapshot retained after next generation");
        print_record(first);
        print_record(record(next));
        run(next.prog_fd, "second exported bound native");
        native_loader::close_loaded_program(&next);
        std::ofstream blocked("/capture-blocked");
        blocked << "existing file";
        blocked.close();
        require(bool(blocked), "write capture IO failure fixture");
        require(!setenv("BPFREJIT_NATIVE_LOADER_TV_DIR", "/capture-blocked", 1), "select failed export");
        bool rejected = false;
        try {
            auto failed = native_loader::load_from_fd(options);
            native_loader::close_loaded_program(&failed);
        } catch (const std::exception &error) {
            rejected = std::string(error.what()).find("capture-blocked") != std::string::npos;
        }
        require(rejected && !std::filesystem::is_directory("/capture-blocked"),
            "capture IO failure propagates without success record");
        require(!unsetenv("BPFREJIT_NATIVE_LOADER_TV_DIR"), "disable per-program capture");
        std::puts("per-program capture: exact bytes, distinct IDs/generations, stable history, IO failure: PASS");
        std::printf("TV_CHECKED ");
        for (unsigned char byte : bytes) std::printf("%02x", byte);
        std::puts("");
        run(options.original_prog_fd, "original actual clang proof");
        run(loaded.prog_fd, "actual bound native");
        native_loader::close_loaded_program(&loaded);
        std::puts("actual bound expanded artifact capture: PASS");
        require(!std::fflush(stdout), "flush capture");
        require(!reboot(RB_POWER_OFF), "capture poweroff");
    } catch (const std::exception &error) {
        std::fprintf(stderr, "capture-checked: %s\n", error.what());
        return 1;
    }
    return 0;
}
