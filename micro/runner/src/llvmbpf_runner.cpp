#include "micro_exec.hpp"

#include <llvmbpf.hpp>

#include <chrono>
#include <cstring>
#include <unordered_map>

namespace {

using clock_type = std::chrono::steady_clock;

struct userspace_array_map {
    map_spec spec;
    std::vector<uint8_t> storage;
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
    const auto image = load_program_image(options.program);
    auto input_bytes = materialize_memory(options.memory, options.input_size);
    auto map_state = initialize_map_state(image, input_bytes);

    bpftime::llvmbpf_vm vm;
    if (vm.load_code(image.code.data(), image.code.size()) < 0) {
        fail("llvmbpf load_code failed: " + vm.get_error_message());
    }
    vm.register_external_function(1, "bpf_map_lookup_elem", (void *)helper_bpf_map_lookup_elem);
    vm.register_external_function(2, "bpf_map_update_elem", (void *)helper_bpf_map_update_elem);

    const auto compile_start = clock_type::now();
    auto compiled = vm.compile();
    const auto compile_end = clock_type::now();
    if (!compiled.has_value()) {
        fail("llvmbpf compile failed: " + vm.get_error_message());
    }

    uint64_t retval = 0;
    uint8_t dummy_ctx[8] = {};
    active_map_state = &map_state;
    const auto exec_start = clock_type::now();
    for (uint32_t index = 0; index < options.repeat; ++index) {
        if (vm.exec(dummy_ctx, sizeof(dummy_ctx), retval) < 0) {
            active_map_state = nullptr;
            fail("llvmbpf exec failed: " + vm.get_error_message());
        }
    }
    const auto exec_end = clock_type::now();
    active_map_state = nullptr;

    sample_result sample;
    sample.compile_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(compile_end - compile_start).count();
    sample.exec_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(exec_end - exec_start).count() / options.repeat;
    sample.result = read_result_value(map_state);
    sample.retval = static_cast<uint32_t>(retval);
    return sample;
}
