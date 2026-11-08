// Trusted service bridge: kernel identity inspection and capability-bound loading.
#include "libnativeloader/include/native_loader.hpp"
#include "../kinsn/module/include/native_lab_trusted_wire.h"
#include <bpf/bpf.h>
#include <charconv>
#include <cerrno>
#include <cstring>
#include <iostream>
#include <limits>
#include <memory>
#include <stdexcept>
#include <string>
#include <sys/ioctl.h>
#include <unistd.h>

struct Fd {
    int value;
    explicit Fd(int v): value(v) { if (v < 0) throw std::runtime_error(std::strerror(errno)); }
    ~Fd() { close(value); }
    Fd(const Fd &) = delete;
    Fd &operator=(const Fd &) = delete;
};
uint64_t number(const char *s) {
    uint64_t n = 0;
    const char *end = s + std::strlen(s);
    auto parsed = std::from_chars(s, end, n);
    if (parsed.ec != std::errc{} || parsed.ptr != end) throw std::runtime_error("invalid unsigned integer");
    return n;
}
uint32_t u32(const char *s) {
    auto n = number(s);
    if (n > UINT32_MAX) throw std::runtime_error("integer exceeds u32");
    return n;
}
template<class T> T info(int fd) {
    T out{}; __u32 size = sizeof(out);
    if (bpf_obj_get_info_by_fd(fd, &out, &size)) throw std::runtime_error(std::strerror(errno));
    return out;
}

void load(int argc, char **argv) {
    const int fixed = argc > 4 && u32(argv[4]) == 0 ? 21 : 17;
    if (argc < fixed || (argc - fixed) % 3) throw std::runtime_error("load requires fixed service fields and map triples");
    uint32_t service = u32(argv[2]);
    if (service > std::numeric_limits<int>::max()) throw std::runtime_error("service FD exceeds int");
    std::unique_ptr<Fd> source;
    if (const auto id = u32(argv[4])) source = std::make_unique<Fd>(bpf_prog_get_fd_by_id(id));
    native_loader::FdLoadOptions o;
    if (source) o.original_prog_fd = source->value;
    o.trusted_service_fd = service; o.trusted_request_id = number(argv[3]);
    o.native_object_path = argv[5]; o.symbol_name = argv[6];
    o.trusted_native_proof_path = argv[7]; o.proof_object_path = argv[8];
    o.trusted_simulator_program = argv[9]; o.native_link_path = argv[10];
    o.expected_attach_type = u32(argv[11]); o.prog_flags = u32(argv[12]);
    o.attach_btf_id = u32(argv[13]); o.attach_btf_obj_id = u32(argv[14]); o.attach_prog_id = u32(argv[15]);
    u32(argv[16]);
    if (!source) {
        bpf_prog_info context{};
        context.ifindex = u32(argv[16]); context.type = u32(argv[17]);
        context.gpl_compatible = u32(argv[18]);
        std::strncpy(context.name, argv[6], sizeof(context.name) - 1);
        o.native_context = context; o.source_btf_id = u32(argv[19]);
        if (const auto type_id = u32(argv[20])) o.native_entry_function = bpf_func_info{0, type_id};
    }
    for (int i = fixed; i < argc; i += 3) {
        native_loader::TrustedMapBinding map;
        map.native_symbol = argv[i]; map.map_id = u32(argv[i+1]);
        if (std::string(argv[i+2]) != "null") map.value_offset = u32(argv[i+2]);
        o.trusted_maps.push_back(map);
    }
    auto program = native_loader::load_from_fd(o);
    const auto id = program.native_prog_id;
    // load_from_fd already COMPLETEs success before returning; never do it twice.
    native_loader::close_loaded_program(&program);
    if (!id) throw std::runtime_error("trusted loader returned no program identity");
    std::cout << "{\"request_id\":" << o.trusted_request_id << ",\"prog_id\":" << id << ",\"status\":0}" << std::endl;
}
void abi() {
    std::cout << sizeof(native_lab_trusted_request) << ' ' << sizeof(native_lab_trusted_result)
        << ' ' << offsetof(native_lab_trusted_request, request_id)
        << ' ' << offsetof(native_lab_trusted_request, native_size)
        << ' ' << offsetof(native_lab_trusted_request, native_user)
        << ' ' << offsetof(native_lab_trusted_request, entry_user)
        << ' ' << offsetof(native_lab_trusted_request, metadata_user)
        << ' ' << offsetof(native_lab_trusted_result, status)
        << ' ' << offsetof(native_lab_trusted_result, prog_id)
        << ' ' << offsetof(native_lab_trusted_result, reserved)
        << ' ' << NATIVE_LAB_TRUSTED_NEXT << ' ' << NATIVE_LAB_TRUSTED_COMPLETE
        << ' ' << sizeof(native_lab_trusted_context) << ' ' << sizeof(native_lab_trusted_map)
        << ' ' << offsetof(native_lab_trusted_context, prog_flags)
        << ' ' << offsetof(native_lab_trusted_map, map_type)
        << ' ' << NATIVE_LAB_TRUSTED_CONTEXT << ' ' << NATIVE_LAB_TRUSTED_MAP << std::endl;
}

int main(int argc, char **argv) {
    try {
        if (argc == 2 && std::string(argv[1]) == "abi") abi();
        else if (argc > 1 && std::string(argv[1]) == "load") load(argc, argv);
        else throw std::runtime_error("usage: trusted-native-loader abi | load SERVICE_FIELDS MAP_TRIPLES");
        return 0;
    } catch (const std::exception &e) { std::cerr << "trusted-native-loader: " << e.what() << '\n'; return 1; }
}
