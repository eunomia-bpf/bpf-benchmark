// SPDX-License-Identifier: MIT
//
// policy.cpp — build v4 JIT policy blobs from scan rules
//
// The blob format is documented in types.h.  This module only builds and
// patches the binary blob; issuing the BPF_PROG_JIT_RECOMPILE syscall is the
// caller's responsibility.

#include "bpf_jit_scanner/policy.h"

#include <cerrno>
#include <cstddef>
#include <cstdlib>
#include <cstring>

// Policy blob header — 32 bytes, packed, little-endian.
struct __attribute__((packed)) policy_hdr {
    uint32_t magic;       // BPF_JIT_POLICY_MAGIC
    uint16_t version;     // BPF_JIT_POLICY_VERSION
    uint16_t hdr_len;     // sizeof(policy_hdr) = 32
    uint32_t total_len;   // sizeof(hdr) + rule_cnt * sizeof(rule_entry)
    uint32_t rule_cnt;
    uint32_t insn_cnt;    // xlated_prog_len / 8
    uint8_t  prog_tag[8]; // bpf_prog_info.tag
    uint16_t arch_id;     // BPF_JIT_ARCH_X86_64
    uint16_t flags;       // 0
};
static_assert(sizeof(policy_hdr) == 32, "policy_hdr must be 32 bytes");

// One rule entry — 16 bytes, packed, little-endian.
struct __attribute__((packed)) policy_rule_entry {
    uint32_t site_start;
    uint16_t site_len;
    uint16_t rule_kind;
    uint16_t native_choice;
    uint16_t priority;
    uint32_t cpu_features_required;
};
static_assert(sizeof(policy_rule_entry) == 16, "policy_rule_entry must be 16 bytes");

// Byte offset of insn_cnt field in the header.
static constexpr uint32_t HDR_INSN_CNT_OFFSET = offsetof(policy_hdr, insn_cnt);
// Byte offset of prog_tag field in the header.
static constexpr uint32_t HDR_PROG_TAG_OFFSET  = offsetof(policy_hdr, prog_tag);

// Minimum valid header size.
static constexpr uint32_t MIN_HDR_LEN = 32;

// -------------------------------------------------------------------------

int bpf_jit_build_policy_blob(const struct bpf_jit_scan_rule *rules,
                              uint32_t rule_cnt,
                              uint32_t insn_cnt,
                              const uint8_t prog_tag[8],
                              uint8_t **out_blob,
                              uint32_t *out_blob_len)
{
    if (!out_blob || !out_blob_len)
        return -EINVAL;
    if (rule_cnt > 0 && !rules)
        return -EINVAL;

    uint32_t total_len = static_cast<uint32_t>(sizeof(policy_hdr)) +
                         rule_cnt * static_cast<uint32_t>(sizeof(policy_rule_entry));

    uint8_t *blob = static_cast<uint8_t *>(std::calloc(1, total_len));
    if (!blob)
        return -ENOMEM;

    // Fill header.
    policy_hdr hdr = {};
    hdr.magic    = BPF_JIT_POLICY_MAGIC;
    hdr.version  = BPF_JIT_POLICY_VERSION;
    hdr.hdr_len  = static_cast<uint16_t>(sizeof(policy_hdr));
    hdr.total_len = total_len;
    hdr.rule_cnt = rule_cnt;
    hdr.insn_cnt = insn_cnt;
    if (prog_tag)
        std::memcpy(hdr.prog_tag, prog_tag, 8);
    hdr.arch_id  = BPF_JIT_ARCH_X86_64;
    hdr.flags    = 0;
    std::memcpy(blob, &hdr, sizeof(hdr));

    // Fill rule entries.
    for (uint32_t i = 0; i < rule_cnt; i++) {
        policy_rule_entry entry = {};
        entry.site_start            = rules[i].site_start;
        entry.site_len              = static_cast<uint16_t>(rules[i].site_len);
        entry.rule_kind             = static_cast<uint16_t>(rules[i].rule_kind);
        entry.native_choice         = static_cast<uint16_t>(rules[i].native_choice);
        entry.priority              = static_cast<uint16_t>(rules[i].priority);
        entry.cpu_features_required = rules[i].cpu_features_required;
        std::memcpy(blob + sizeof(hdr) + i * sizeof(entry), &entry, sizeof(entry));
    }

    *out_blob     = blob;
    *out_blob_len = total_len;
    return 0;
}

void bpf_jit_free_policy_blob(uint8_t *blob)
{
    std::free(blob);
}

int bpf_jit_patch_policy_blob(uint8_t *blob, uint32_t blob_len,
                              uint32_t insn_cnt,
                              const uint8_t prog_tag[8])
{
    if (!blob || blob_len < MIN_HDR_LEN)
        return -EINVAL;
    std::memcpy(blob + HDR_INSN_CNT_OFFSET, &insn_cnt, sizeof(insn_cnt));
    if (prog_tag)
        std::memcpy(blob + HDR_PROG_TAG_OFFSET, prog_tag, 8);
    return 0;
}
