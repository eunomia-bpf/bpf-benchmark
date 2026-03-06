#include "micro_exec.hpp"

#include <llvmbpf.hpp>

#include <algorithm>
#include <chrono>
#include <cstring>
#include <memory>
#include <sys/mman.h>
#include <unordered_map>

namespace {

using clock_type = std::chrono::steady_clock;

struct userspace_array_map {
    map_spec spec;
    std::vector<uint8_t> storage;
};

struct xdp_md_ctx {
    uint32_t data = 0;
    uint32_t data_end = 0;
    uint32_t data_meta = 0;
    uint32_t ingress_ifindex = 0;
    uint32_t rx_queue_index = 0;
    uint32_t egress_ifindex = 0;
};

struct userspace_map_state {
    std::unordered_map<uint32_t, userspace_array_map> maps_by_id;

    userspace_array_map *find_by_name(const std::string &name)
    {
        for (auto &[id, map] : maps_by_id) {
            (void)id;
            if (map.spec.name == name) {
                return &map;
            }
        }
        return nullptr;
    }
};

thread_local userspace_map_state *active_map_state = nullptr;

userspace_array_map *lookup_map(uint64_t map_id)
{
    if (active_map_state == nullptr) {
        return nullptr;
    }
    const auto iter = active_map_state->maps_by_id.find(static_cast<uint32_t>(map_id));
    if (iter == active_map_state->maps_by_id.end()) {
        return nullptr;
    }
    return &iter->second;
}

uint8_t *lookup_slot(userspace_array_map *map, uint64_t key_ptr)
{
    if (map == nullptr || key_ptr == 0 || map->spec.key_size != sizeof(uint32_t)) {
        return nullptr;
    }
    uint32_t key = 0;
    std::memcpy(&key, reinterpret_cast<const void *>(key_ptr), sizeof(key));
    if (key >= map->spec.max_entries) {
        return nullptr;
    }
    return map->storage.data() + static_cast<size_t>(key) * map->spec.value_size;
}

uint64_t helper_bpf_map_lookup_elem(
    uint64_t map_id,
    uint64_t key_ptr,
    uint64_t,
    uint64_t,
    uint64_t)
{
    auto *map = lookup_map(map_id);
    auto *slot = lookup_slot(map, key_ptr);
    return reinterpret_cast<uint64_t>(slot);
}

uint64_t helper_bpf_map_update_elem(
    uint64_t map_id,
    uint64_t key_ptr,
    uint64_t value_ptr,
    uint64_t,
    uint64_t)
{
    auto *map = lookup_map(map_id);
    auto *slot = lookup_slot(map, key_ptr);
    if (slot == nullptr || value_ptr == 0) {
        return static_cast<uint64_t>(-1);
    }
    std::memcpy(slot, reinterpret_cast<const void *>(value_ptr), map->spec.value_size);
    return 0;
}

class lowmem_buffer {
public:
    explicit lowmem_buffer(size_t size)
        : size_(size)
    {
        int flags = MAP_PRIVATE | MAP_ANONYMOUS;
#ifdef MAP_32BIT
        flags |= MAP_32BIT;
#endif
        void *mapping = mmap(nullptr, size_, PROT_READ | PROT_WRITE, flags, -1, 0);
        if (mapping == MAP_FAILED) {
            fail("mmap failed while preparing llvmbpf packet buffer");
        }
        data_ = static_cast<uint8_t *>(mapping);

        const auto address = reinterpret_cast<uintptr_t>(data_);
        if (address > UINT32_MAX || (size_ != 0 && address + size_ - 1 > UINT32_MAX)) {
            munmap(data_, size_);
            fail("llvmbpf packet buffer address exceeds 32-bit xdp_md range");
        }
    }

    ~lowmem_buffer()
    {
        if (data_ != nullptr) {
            munmap(data_, size_);
        }
    }

    lowmem_buffer(const lowmem_buffer &) = delete;
    lowmem_buffer &operator=(const lowmem_buffer &) = delete;

    uint8_t *data() { return data_; }
    const uint8_t *data() const { return data_; }
    size_t size() const { return size_; }

private:
    uint8_t *data_ = nullptr;
    size_t size_ = 0;
};

std::vector<uint8_t> build_packet_input(const std::vector<uint8_t> &input_bytes)
{
    std::vector<uint8_t> packet(input_bytes.size() + sizeof(uint64_t), 0);
    std::copy(input_bytes.begin(), input_bytes.end(), packet.begin() + sizeof(uint64_t));
    return packet;
}

uint64_t read_u64_result(const uint8_t *data, size_t length)
{
    if (length < sizeof(uint64_t)) {
        fail("result buffer shorter than 8 bytes");
    }
    uint64_t result = 0;
    std::memcpy(&result, data, sizeof(result));
    return result;
}

std::vector<uint8_t> build_result_packet()
{
    return std::vector<uint8_t>(64, 0);
}

userspace_map_state initialize_map_state(const program_image &image, const std::vector<uint8_t> &input_bytes)
{
    userspace_map_state state;
    for (const auto &spec : image.maps) {
        userspace_array_map map;
        map.spec = spec;
        map.storage.assign(static_cast<size_t>(spec.value_size) * spec.max_entries, 0);
        state.maps_by_id.emplace(spec.id, std::move(map));
    }

    if (auto *input_map = state.find_by_name("input_map"); input_map != nullptr) {
        const size_t copy_len = std::min(input_map->storage.size(), input_bytes.size());
        std::memcpy(input_map->storage.data(), input_bytes.data(), copy_len);
    }
    if (auto *result_map = state.find_by_name("result_map"); result_map != nullptr) {
        std::fill(result_map->storage.begin(), result_map->storage.end(), 0);
    }
    return state;
}

uint64_t read_result_value(const userspace_map_state &state)
{
    for (const auto &[id, map] : state.maps_by_id) {
        (void)id;
        if (map.spec.name != "result_map") {
            continue;
        }
        uint64_t result = 0;
        const size_t copy_len = std::min(sizeof(result), map.storage.size());
        std::memcpy(&result, map.storage.data(), copy_len);
        return result;
    }
    fail("result_map not found in llvmbpf map state");
}

} // namespace

sample_result run_llvmbpf(const cli_options &options)
{
    const auto program_image_start = clock_type::now();
    const auto image = load_program_image(options.program);
    const auto program_image_end = clock_type::now();

    const auto memory_prepare_start = clock_type::now();
    auto input_bytes = materialize_memory(options.memory, options.input_size);
    const auto memory_prepare_end = clock_type::now();

    const auto exec_input_prepare_start = clock_type::now();
    auto map_state = userspace_map_state {};
    auto packet_input = std::vector<uint8_t> {};
    if (options.io_mode == "map") {
        map_state = initialize_map_state(image, input_bytes);
    } else if (options.io_mode == "staged") {
        map_state = initialize_map_state(image, input_bytes);
        packet_input = build_result_packet();
    } else {
        packet_input = build_packet_input(input_bytes);
    }
    const auto exec_input_prepare_end = clock_type::now();

    bpftime::llvmbpf_vm vm;
    const auto load_code_start = clock_type::now();
    if (vm.load_code(image.code.data(), image.code.size()) < 0) {
        fail("llvmbpf load_code failed: " + vm.get_error_message());
    }
    const auto load_code_end = clock_type::now();
    vm.register_external_function(1, "bpf_map_lookup_elem", (void *)helper_bpf_map_lookup_elem);
    vm.register_external_function(2, "bpf_map_update_elem", (void *)helper_bpf_map_update_elem);

    const auto compile_start = clock_type::now();
    auto compiled = vm.compile();
    const auto compile_end = clock_type::now();
    if (!compiled.has_value()) {
        fail("llvmbpf compile failed: " + vm.get_error_message());
    }

    uint64_t retval = 0;
    uint64_t result = 0;
    active_map_state = &map_state;
    clock_type::time_point exec_start {};
    clock_type::time_point exec_end {};
    auto perf_counters = measure_perf_counters(
        {.enabled = options.perf_counters, .include_kernel = false, .scope = "exec_window"},
        [&]() {
            exec_start = clock_type::now();
            if (options.io_mode == "map") {
                uint8_t dummy_ctx[8] = {};
                for (uint32_t index = 0; index < options.repeat; ++index) {
                    if (vm.exec(dummy_ctx, sizeof(dummy_ctx), retval) < 0) {
                        fail("llvmbpf exec failed: " + vm.get_error_message());
                    }
                }
            } else {
                lowmem_buffer packet_buffer(packet_input.size());
                std::memcpy(packet_buffer.data(), packet_input.data(), packet_input.size());

                xdp_md_ctx ctx = {};
                const auto packet_address = reinterpret_cast<uintptr_t>(packet_buffer.data());
                ctx.data = static_cast<uint32_t>(packet_address);
                ctx.data_end = static_cast<uint32_t>(packet_address + packet_input.size());

                for (uint32_t index = 0; index < options.repeat; ++index) {
                    if (vm.exec(&ctx, sizeof(ctx), retval) < 0) {
                        fail("llvmbpf exec failed: " + vm.get_error_message());
                    }
                }
                result = read_u64_result(
                    packet_buffer.data(),
                    packet_buffer.size());
            }
            exec_end = clock_type::now();
        });
    active_map_state = nullptr;

    sample_result sample;
    sample.compile_ns = elapsed_ns(compile_start, compile_end);
    sample.exec_ns = elapsed_ns(exec_start, exec_end) / options.repeat;
    sample.result = options.io_mode == "map" ? read_result_value(map_state) : result;
    sample.retval = static_cast<uint32_t>(retval);
    sample.phases_ns = {
        {"program_image_ns", elapsed_ns(program_image_start, program_image_end)},
        {"memory_prepare_ns", elapsed_ns(memory_prepare_start, memory_prepare_end)},
        {options.io_mode == "packet" ? "packet_prepare_ns"
                                     : (options.io_mode == "staged" ? "input_stage_ns" : "map_prepare_ns"),
         elapsed_ns(exec_input_prepare_start, exec_input_prepare_end)},
        {"vm_load_code_ns", elapsed_ns(load_code_start, load_code_end)},
        {"jit_compile_ns", sample.compile_ns},
    };
    sample.perf_counters = std::move(perf_counters);
    return sample;
}
