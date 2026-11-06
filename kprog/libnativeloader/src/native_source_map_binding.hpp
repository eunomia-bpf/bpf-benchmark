#pragma once

#include <linux/bpf.h>
#include <cstdint>
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
