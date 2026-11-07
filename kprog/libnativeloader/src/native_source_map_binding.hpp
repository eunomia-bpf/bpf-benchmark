#pragma once

#include <linux/bpf.h>
#include <cstdint>
#include <bit>
#include <optional>
#include <stdexcept>
#include <vector>

struct NativeSourceMapReference {
    int fd;
    bool value;
    uint32_t offset;
};

/* The source instruction, rather than an ELF symbol spelling or process-wide
 * map name, determines object/value kind, original FD and value displacement.
 */
inline NativeSourceMapReference source_map_reference(
    const std::vector<bpf_insn> &source, uint32_t site)
{
    size_t position = 0;
    while (position < site && position < source.size())
        position += source[position].code == (BPF_LD | BPF_DW | BPF_IMM) ? 2 : 1;
    if (position != site || position >= source.size() || source.size() - position < 2)
        throw std::runtime_error("source map binding is not a complete instruction site");
    const bpf_insn &low = source[position], &high = source[position + 1];
    if (low.code != (BPF_LD | BPF_DW | BPF_IMM) || low.dst_reg >= BPF_REG_10 ||
        low.off || low.imm < 0 ||
        (low.src_reg != BPF_PSEUDO_MAP_FD && low.src_reg != BPF_PSEUDO_MAP_VALUE) ||
        high.code || high.dst_reg || high.src_reg || high.off || high.imm < 0 ||
        (low.src_reg == BPF_PSEUDO_MAP_FD && high.imm))
        throw std::runtime_error("source map binding has invalid LDDW kind, FD or continuation");
    return {low.imm, low.src_reg == BPF_PSEUDO_MAP_VALUE, static_cast<uint32_t>(high.imm)};
}

/* A trusted extern denotes its already-bound native symbol address. REL's
 * encoded LDDW value or RELA's explicit A is relative to that symbol; it is
 * never an absolute offset that must already contain the capsule base.
 * Wider arithmetic prevents wrapping a far native address into a safe value.
 */
inline uint32_t trusted_map_relocation_offset(std::optional<uint32_t> base,
    uint64_t encoded, int64_t explicit_addend, bool rela, uint32_t value_size)
{
    const int64_t relative = rela ? explicit_addend : std::bit_cast<int64_t>(encoded);
    const __int128 offset = static_cast<__int128>(base.value_or(0)) + relative;
    if ((!base && relative) || offset < 0 || offset > UINT32_MAX ||
        (base && offset >= value_size))
        throw std::runtime_error("trusted proof map addend exceeds original object/value");
    return static_cast<uint32_t>(offset);
}
