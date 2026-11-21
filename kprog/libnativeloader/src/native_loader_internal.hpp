#pragma once
#include "native_loader.hpp"
#include <unistd.h>
#include <chrono>
#include <cstdio>
#include <string>
#include <unordered_map>
#include <utility>


namespace native_loader::internal {

struct ScopedFd {
    int fd = -1;

    ScopedFd() = default;
    explicit ScopedFd(int value) : fd(value) {}
    ScopedFd(const ScopedFd &) = delete;
    ScopedFd &operator=(const ScopedFd &) = delete;
    ~ScopedFd()
    {
        if (fd >= 0) {
            close(fd);
        }
    }

    int get() const { return fd; }
};

struct Hash64 {
    uint64_t value = 1469598103934665603ULL;

    void add_byte(uint8_t byte)
    {
        value ^= byte;
        value *= 1099511628211ULL;
    }

    void add_u64(uint64_t word)
    {
        for (unsigned i = 0; i < 8; i++) {
            add_byte(static_cast<uint8_t>((word >> (i * 8)) & 0xff));
        }
    }

    void add_bytes(const uint8_t *data, size_t size)
    {
        add_u64(size);
        for (size_t i = 0; i < size; i++) {
            add_byte(data[i]);
        }
    }

    void add_string(const std::string &text)
    {
        add_u64(text.size());
        for (unsigned char ch : text) {
            add_byte(ch);
        }
    }

    std::string hex() const
    {
        char buf[17];
        std::snprintf(buf, sizeof(buf), "%016llx",
                      static_cast<unsigned long long>(value));
        return std::string(buf);
    }
};

void append_u32_le(std::vector<uint8_t> &out, uint32_t v);

void append_u64_le(std::vector<uint8_t> &out, uint64_t v);

std::string bpf_obj_name_truncation(const std::string &name);

template <typename Clock, typename Duration>
inline uint64_t elapsed_ns(
    const std::chrono::time_point<Clock, Duration> &start,
    const std::chrono::time_point<Clock, Duration> &end)
{
    return static_cast<uint64_t>(
        std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
}

[[noreturn]] void fail(const std::string &message);

bool fd_is_bpf_map(int fd);

std::string format_command_limited(const std::vector<std::string> &argv, size_t limit);

void hash_file_contents(Hash64 &hash,
                        const std::filesystem::path &path,
                        const std::string &label);

void hash_file_identity(Hash64 &hash,
                        const std::filesystem::path &path,
                        const std::string &label);

std::string libbpf_error_string(int error_code);

bpf_map_info load_map_info(int map_fd);

std::string load_prog_btf_symbol_name(int program_fd,
                                      const bpf_prog_info &base_info);

bpf_prog_info load_prog_info(int program_fd);

std::vector<uint32_t> load_prog_map_ids(int program_fd, uint32_t count);

std::vector<uint32_t> load_prog_map_ids(int program_fd);

std::vector<uint8_t> load_xlated_program(
    int program_fd,
    uint32_t xlated_prog_len,
    bool require_non_empty);

bool native_data_section_supported(const std::string &section_name);

int open_btf_fd_by_id_required(uint32_t id, const char *field_name);

int open_prog_fd_by_id_required(uint32_t id, const char *field_name);

uint64_t parse_decimal_u64(const std::string &text, const std::string &context);

std::string prog_info_name_or_stub(const bpf_prog_info &info);

template <typename T>
inline __u64 ptr_to_u64(T *ptr)
{
    return static_cast<__u64>(reinterpret_cast<uintptr_t>(ptr));
}

void publish_cache_file(const std::filesystem::path &tmp,
                        const std::filesystem::path &dst);

std::vector<uint8_t> read_binary_file(const std::filesystem::path &path);

std::vector<bpf_insn> read_bpf_insn_file(const std::filesystem::path &path);

std::string read_text_file_limited(const std::filesystem::path &path, size_t limit);

uint32_t read_u32_le(const uint8_t *p);

uint64_t read_u64_le(const uint8_t *p);

std::vector<int> reopen_relocated_map_fds(const std::vector<uint32_t> &map_ids);

uint32_t roundup_pow2_mask(uint32_t max_entries);

void write_binary_file(const std::filesystem::path &path, const uint8_t *data, size_t size);

bool requires_bound_proof();

LoadedProgram load_checked(const FdLoadOptions &options);

} // namespace native_loader::internal
