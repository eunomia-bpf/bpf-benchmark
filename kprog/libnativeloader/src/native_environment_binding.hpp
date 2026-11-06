#pragma once

#include "native_loader_manifest.hpp"
#include "../../../kinsn/module/include/native_lab_binding.h"
#include "../../../kinsn/module/include/native_lab_exclusive.h"

struct NativeExclusiveSite {
    uint32_t source_pc;
    uint32_t offset;
};

inline std::vector<NativeExclusiveSite> parse_native_environment_layout(
    const std::string &text, const std::vector<uint8_t> &native)
{
    json_require_object_fields(text, {"version", "sites"}, "native environment");
    if (json_required_u32(text, "version") != 1)
        json_fail("unknown native environment layout version");
    std::vector<NativeExclusiveSite> sites;
    std::set<uint32_t> pcs, offsets;
    for (const auto &entry : json_array_objects(text, "sites")) {
        json_require_object_fields(entry, {"source_pc", "offset", "width", "release"},
            "exclusive environment site");
        NativeExclusiveSite site{json_required_u32(entry, "source_pc"),
            json_required_u32(entry, "offset")};
        const uint32_t width = json_required_u32(entry, "width");
        const auto release = json_object_bool(entry, "release");
        const bpf_insn marker{.code = BPF_ALU64 | BPF_MOV | BPF_K,
            .dst_reg = 0, .src_reg = NATIVE_LAB_INPUT_SRC,
            .off = NATIVE_LAB_INPUT_EXCLUSIVE_FAILURE, .imm = static_cast<int32_t>(site.source_pc)};
        if (!release || !pcs.insert(site.source_pc).second || !offsets.insert(site.offset).second ||
            native.size() > UINT32_MAX || !native_lab_exclusive_match(native.data(), native.size(),
                site.offset, &marker, 1, 0, site.source_pc))
            json_fail("invalid/duplicate native exclusive site");
        const uint32_t word = static_cast<uint32_t>(native[site.offset]) |
            (static_cast<uint32_t>(native[site.offset + 1]) << 8) |
            (static_cast<uint32_t>(native[site.offset + 2]) << 16) |
            (static_cast<uint32_t>(native[site.offset + 3]) << 24);
        if (width != ((word >> 30 & 1) ? 8U : 4U) || *release != bool(word >> 15 & 1))
            json_fail("exclusive width/order differs from actual native opcode");
        sites.push_back(site);
    }
    return sites;
}

/* A compiler may clone a volatile marker when unrolling. Each compiled
 * occurrence gets its own exact descriptor for the same original native site.
 */
inline std::vector<std::pair<uint32_t, uint64_t>> bind_exclusive_environment(
    const std::vector<NativeExclusiveSite> &sites, const std::vector<uint8_t> &native,
    const std::vector<bpf_insn> &proof)
{
    std::vector<std::pair<uint32_t, uint64_t>> descriptors;
    std::set<uint32_t> used;
    for (size_t i = 0; i < proof.size(); i++) {
        if (proof[i].code == (BPF_LD | BPF_DW | BPF_IMM)) { i++; continue; }
        if (!native_lab_exclusive_marker(&proof[i])) continue;
        bool found = false;
        for (const auto &site : sites) {
            if (site.source_pc != static_cast<uint32_t>(proof[i].imm)) continue;
            if (i > UINT32_MAX || !native_lab_exclusive_match(native.data(), native.size(),
                site.offset, proof.data(), proof.size(), i, site.source_pc))
                json_fail("exclusive marker does not match the actual native site");
            descriptors.emplace_back(site.offset, (uint64_t(site.source_pc) << 32) | i);
            used.insert(site.source_pc);
            found = true;
        }
        if (!found) json_fail("exclusive marker has no native environment site");
    }
    if (used.size() != sites.size()) json_fail("native exclusive site has no compiled proof marker");
    return descriptors;
}
