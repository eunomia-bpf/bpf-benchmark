#pragma once
#include "../../stock-path/module/native_lab_helper_query.h"
#include <cstdint>
#include <cstring>
#include <stdexcept>
#include <vector>

inline std::vector<uint8_t> encode_helper_query(
    uint64_t verifier_ops, uint32_t program_fd, uint32_t program_type,
    const std::vector<uint32_t> &ids)
{
    native_lab_helper_query header{verifier_ops, program_fd, program_type};
    std::vector<uint8_t> bytes(sizeof(header) + ids.size() * sizeof(uint32_t));
    std::memcpy(bytes.data(), &header, sizeof(header));
    if (!ids.empty())
        std::memcpy(bytes.data() + sizeof(header), ids.data(), ids.size() * sizeof(uint32_t));
    return bytes;
}

inline std::vector<uint64_t> decode_helper_targets(
    const std::vector<uint8_t> &bytes, size_t count)
{
    if (bytes.size() != count * sizeof(uint64_t))
        throw std::runtime_error("native_loader: incomplete helper_targets response");
    std::vector<uint64_t> targets(count);
    if (!bytes.empty())
        std::memcpy(targets.data(), bytes.data(), bytes.size());
    return targets;
}
