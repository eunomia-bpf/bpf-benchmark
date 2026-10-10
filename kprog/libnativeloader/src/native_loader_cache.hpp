#ifndef BPFREJIT_NATIVE_LOADER_CACHE_HPP
#define BPFREJIT_NATIVE_LOADER_CACHE_HPP

#include <filesystem>
#include <string>

inline std::filesystem::path native_link_temporary_base(
    const std::filesystem::path &cache_dir,
    const std::string &key,
    long process_id,
    long thread_id)
{
    return cache_dir / (key + ".tmp." + std::to_string(process_id) + "." +
                        std::to_string(thread_id));
}

#endif
