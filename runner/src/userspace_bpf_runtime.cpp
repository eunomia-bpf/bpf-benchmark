#include "userspace_bpf_runtime.hpp"

#include <algorithm>
#include <chrono>
#include <cstring>
#include <dlfcn.h>
#include <sched.h>
#include <unistd.h>

namespace {

constexpr uint32_t kMapTypeHash = 1;
constexpr uint32_t kMapTypeArray = 2;
constexpr uint32_t kMapTypePercpuHash = 5;
constexpr uint32_t kMapTypePercpuArray = 6;
constexpr uint32_t kMapTypeLruHash = 9;
constexpr uint32_t kMapTypeLruPercpuHash = 10;

thread_local userspace_bpf_map_state *active_map_state = nullptr;

bool is_hash_map(uint32_t type)
{
    return type == kMapTypeHash ||
           type == kMapTypePercpuHash ||
           type == kMapTypeLruHash ||
           type == kMapTypeLruPercpuHash;
}

bool is_array_map(uint32_t type)
{
    return type == kMapTypeArray || type == kMapTypePercpuArray;
}

std::string key_bytes(const userspace_bpf_map &map, const void *key)
{
    if (key == nullptr) {
        return {};
    }
    return std::string(
        static_cast<const char *>(key),
        static_cast<size_t>(map.spec.key_size));
}

userspace_bpf_map *lookup_map_by_id(uint64_t map_id)
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

userspace_bpf_map *lookup_map_by_native_symbol(const void *symbol)
{
    if (active_map_state == nullptr || symbol == nullptr) {
        return nullptr;
    }
    const auto id_iter =
        active_map_state->map_ids_by_native_symbol.find(reinterpret_cast<uintptr_t>(symbol));
    if (id_iter == active_map_state->map_ids_by_native_symbol.end()) {
        return nullptr;
    }
    return lookup_map_by_id(id_iter->second);
}

uint8_t *lookup_slot(userspace_bpf_map *map, const void *key)
{
    if (map == nullptr || key == nullptr) {
        return nullptr;
    }

    if (is_array_map(map->spec.type)) {
        if (map->spec.key_size != sizeof(uint32_t)) {
            fail("userspace BPF array map key_size is not u32: " + map->spec.name);
        }
        uint32_t index = 0;
        std::memcpy(&index, key, sizeof(index));
        if (index >= map->spec.max_entries) {
            return nullptr;
        }
        return map->storage.data() + static_cast<size_t>(index) * map->spec.value_size;
    }
    if (is_hash_map(map->spec.type)) {
        const auto iter = map->hash_storage.find(key_bytes(*map, key));
        if (iter == map->hash_storage.end()) {
            return nullptr;
        }
        return iter->second.data();
    }

    fail("unsupported userspace BPF map type: " + std::to_string(map->spec.type));
}

bool update_slot(userspace_bpf_map *map, const void *key, const void *value)
{
    if (map == nullptr || key == nullptr || value == nullptr) {
        return false;
    }

    if (is_array_map(map->spec.type)) {
        auto *slot = lookup_slot(map, key);
        if (slot == nullptr) {
            return false;
        }
        std::memcpy(slot, value, map->spec.value_size);
        return true;
    }
    if (is_hash_map(map->spec.type)) {
        const auto bytes = key_bytes(*map, key);
        if (map->hash_storage.find(bytes) == map->hash_storage.end() &&
            map->hash_storage.size() >= map->spec.max_entries) {
            return false;
        }
        auto &slot = map->hash_storage[bytes];
        slot.resize(map->spec.value_size);
        std::memcpy(slot.data(), value, map->spec.value_size);
        return true;
    }

    fail("unsupported userspace BPF map type: " + std::to_string(map->spec.type));
}

bool delete_slot(userspace_bpf_map *map, const void *key)
{
    if (map == nullptr || key == nullptr) {
        return false;
    }
    if (is_hash_map(map->spec.type)) {
        map->hash_storage.erase(key_bytes(*map, key));
        return true;
    }
    if (is_array_map(map->spec.type)) {
        return false;
    }
    fail("unsupported userspace BPF map type: " + std::to_string(map->spec.type));
}

uint64_t steady_time_ns()
{
    const auto now = std::chrono::steady_clock::now().time_since_epoch();
    return static_cast<uint64_t>(
        std::chrono::duration_cast<std::chrono::nanoseconds>(now).count());
}

} // namespace

userspace_bpf_map *userspace_bpf_map_state::find_by_name(const std::string &name)
{
    for (auto &[id, map] : maps_by_id) {
        (void)id;
        if (map.spec.name == name) {
            return &map;
        }
    }
    return nullptr;
}

const userspace_bpf_map *userspace_bpf_map_state::find_by_name(const std::string &name) const
{
    for (const auto &[id, map] : maps_by_id) {
        (void)id;
        if (map.spec.name == name) {
            return &map;
        }
    }
    return nullptr;
}

userspace_bpf_map_state initialize_userspace_bpf_map_state(
    const program_image &image,
    const std::vector<uint8_t> &input_bytes)
{
    userspace_bpf_map_state state;
    for (const auto &spec : image.maps) {
        userspace_bpf_map map;
        map.spec = spec;
        if (is_array_map(spec.type)) {
            map.storage.assign(static_cast<size_t>(spec.value_size) * spec.max_entries, 0);
        } else if (is_hash_map(spec.type)) {
            map.hash_storage.reserve(spec.max_entries);
        } else {
            fail("unsupported userspace BPF map type: " + std::to_string(spec.type));
        }
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

void bind_native_map_symbols(userspace_bpf_map_state &state, void *dl_handle)
{
    for (const auto &[id, map] : state.maps_by_id) {
        if (map.spec.internal) {
            continue;
        }
        dlerror();
        void *symbol = dlsym(dl_handle, map.spec.name.c_str());
        const char *error = dlerror();
        if (error != nullptr || symbol == nullptr) {
            fail("dlsym failed for native map symbol " + map.spec.name + ": " +
                 (error == nullptr ? "missing symbol" : error));
        }
        state.map_ids_by_native_symbol.emplace(reinterpret_cast<uintptr_t>(symbol), id);
    }
}

void set_active_userspace_bpf_map_state(userspace_bpf_map_state *state)
{
    active_map_state = state;
}

uint64_t read_userspace_bpf_result_value(const userspace_bpf_map_state &state)
{
    const auto *result_map = state.find_by_name("result_map");
    if (result_map == nullptr) {
        fail("result_map not found in userspace BPF map state");
    }
    uint64_t result = 0;
    const size_t copy_len = std::min(sizeof(result), result_map->storage.size());
    std::memcpy(&result, result_map->storage.data(), copy_len);
    return result;
}

uint64_t llvmbpf_helper_bpf_map_lookup_elem(
    uint64_t map_id,
    uint64_t key_ptr,
    uint64_t,
    uint64_t,
    uint64_t)
{
    auto *slot = lookup_slot(lookup_map_by_id(map_id), reinterpret_cast<const void *>(key_ptr));
    return reinterpret_cast<uint64_t>(slot);
}

uint64_t llvmbpf_helper_bpf_map_update_elem(
    uint64_t map_id,
    uint64_t key_ptr,
    uint64_t value_ptr,
    uint64_t,
    uint64_t)
{
    return update_slot(
        lookup_map_by_id(map_id),
        reinterpret_cast<const void *>(key_ptr),
        reinterpret_cast<const void *>(value_ptr)) ? 0 : static_cast<uint64_t>(-1);
}

uint64_t llvmbpf_helper_bpf_map_delete_elem(
    uint64_t map_id,
    uint64_t key_ptr,
    uint64_t,
    uint64_t,
    uint64_t)
{
    return delete_slot(
        lookup_map_by_id(map_id),
        reinterpret_cast<const void *>(key_ptr)) ? 0 : static_cast<uint64_t>(-1);
}

uint64_t llvmbpf_helper_bpf_probe_read_kernel(
    uint64_t dst_ptr,
    uint64_t size,
    uint64_t src_ptr,
    uint64_t,
    uint64_t)
{
    return micro_native_bpf_probe_read_kernel(
        reinterpret_cast<void *>(dst_ptr),
        static_cast<unsigned int>(size),
        reinterpret_cast<const void *>(src_ptr));
}

uint64_t llvmbpf_helper_bpf_ktime_get_ns(uint64_t, uint64_t, uint64_t, uint64_t, uint64_t)
{
    return micro_native_bpf_ktime_get_ns();
}

uint64_t llvmbpf_helper_noop(uint64_t, uint64_t, uint64_t, uint64_t, uint64_t)
{
    return 0;
}

extern "C" void *micro_native_bpf_map_lookup_elem(void *map, const void *key)
{
    return lookup_slot(lookup_map_by_native_symbol(map), key);
}

extern "C" long micro_native_bpf_map_update_elem(
    void *map,
    const void *key,
    const void *value,
    unsigned long long flags)
{
    (void)flags;
    return update_slot(lookup_map_by_native_symbol(map), key, value) ? 0 : -1;
}

extern "C" long micro_native_bpf_map_delete_elem(void *map, const void *key)
{
    return delete_slot(lookup_map_by_native_symbol(map), key) ? 0 : -1;
}

extern "C" unsigned long long micro_native_bpf_ktime_get_ns(void)
{
    return steady_time_ns();
}

extern "C" unsigned long long micro_native_bpf_ktime_get_boot_ns(void)
{
    return steady_time_ns();
}

extern "C" unsigned long long micro_native_bpf_get_current_pid_tgid(void)
{
    const auto pid = static_cast<unsigned long long>(getpid());
    return (pid << 32) | pid;
}

extern "C" unsigned int micro_native_bpf_get_smp_processor_id(void)
{
    const int cpu = sched_getcpu();
    return cpu < 0 ? 0U : static_cast<unsigned int>(cpu);
}

extern "C" unsigned long long micro_native_bpf_get_current_uid_gid(void)
{
    return (static_cast<unsigned long long>(getgid()) << 32) |
           static_cast<unsigned long long>(getuid());
}

extern "C" unsigned int micro_native_bpf_get_prandom_u32(void)
{
    return 0;
}

extern "C" long micro_native_bpf_probe_read_kernel(void *dst, unsigned int size, const void *unsafe_ptr)
{
    if (dst == nullptr || unsafe_ptr == nullptr) {
        return -1;
    }
    std::memcpy(dst, unsafe_ptr, size);
    return 0;
}
