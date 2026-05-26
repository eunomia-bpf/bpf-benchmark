#ifndef USERSPACE_BPF_RUNTIME_HPP
#define USERSPACE_BPF_RUNTIME_HPP

#include "micro_exec.hpp"

#include <cstdint>
#include <string>
#include <unordered_map>
#include <vector>

struct userspace_bpf_map {
    map_spec spec;
    std::vector<uint8_t> storage;
    std::unordered_map<std::string, std::vector<uint8_t>> hash_storage;
};

struct userspace_bpf_map_state {
    std::unordered_map<uint32_t, userspace_bpf_map> maps_by_id;
    std::unordered_map<uintptr_t, uint32_t> map_ids_by_native_symbol;

    userspace_bpf_map *find_by_name(const std::string &name);
    const userspace_bpf_map *find_by_name(const std::string &name) const;
};

userspace_bpf_map_state initialize_userspace_bpf_map_state(
    const program_image &image,
    const std::vector<uint8_t> &input_bytes);
void bind_native_map_symbols(userspace_bpf_map_state &state, void *dl_handle);
void set_active_userspace_bpf_map_state(userspace_bpf_map_state *state);
uint64_t read_userspace_bpf_result_value(const userspace_bpf_map_state &state);

uint64_t llvmbpf_helper_bpf_map_lookup_elem(
    uint64_t map_id,
    uint64_t key_ptr,
    uint64_t,
    uint64_t,
    uint64_t);
uint64_t llvmbpf_helper_bpf_map_update_elem(
    uint64_t map_id,
    uint64_t key_ptr,
    uint64_t value_ptr,
    uint64_t,
    uint64_t);
uint64_t llvmbpf_helper_bpf_map_delete_elem(
    uint64_t map_id,
    uint64_t key_ptr,
    uint64_t,
    uint64_t,
    uint64_t);
uint64_t llvmbpf_helper_bpf_probe_read_kernel(
    uint64_t dst_ptr,
    uint64_t size,
    uint64_t src_ptr,
    uint64_t,
    uint64_t);
uint64_t llvmbpf_helper_bpf_ktime_get_ns(uint64_t, uint64_t, uint64_t, uint64_t, uint64_t);
uint64_t llvmbpf_helper_noop(uint64_t, uint64_t, uint64_t, uint64_t, uint64_t);

extern "C" void *micro_native_bpf_map_lookup_elem(void *map, const void *key);
extern "C" long micro_native_bpf_map_update_elem(
    void *map,
    const void *key,
    const void *value,
    unsigned long long flags);
extern "C" long micro_native_bpf_map_delete_elem(void *map, const void *key);
extern "C" unsigned long long micro_native_bpf_ktime_get_ns(void);
extern "C" unsigned long long micro_native_bpf_ktime_get_boot_ns(void);
extern "C" unsigned long long micro_native_bpf_get_current_pid_tgid(void);
extern "C" unsigned int micro_native_bpf_get_smp_processor_id(void);
extern "C" unsigned long long micro_native_bpf_get_current_uid_gid(void);
extern "C" unsigned int micro_native_bpf_get_prandom_u32(void);
extern "C" long micro_native_bpf_probe_read_kernel(void *dst, unsigned int size, const void *unsafe_ptr);

#endif
