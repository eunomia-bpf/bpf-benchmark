/* SPDX-License-Identifier: MIT */
#ifndef BPF_JIT_SCANNER_PATTERN_V5_HPP
#define BPF_JIT_SCANNER_PATTERN_V5_HPP

#include "types.h"

#include <cstdint>
#include <optional>
#include <string>
#include <string_view>
#include <vector>

namespace bpf_jit_scanner {

enum class V5Family {
    Cmov,
    WideMem,
    Rotate,
    AddrCalc,
    BitfieldExtract,
    ZeroExtElide,
    EndianFusion,
    BranchFlip,
};

struct V5RuleWire {
    uint32_t site_start = 0;
    uint16_t site_len = 0;
    uint16_t canonical_form = 0;
    uint16_t native_choice = 0;
};
static_assert(sizeof(V5RuleWire) == 12, "V5RuleWire must match kernel ABI");

struct V5PolicyRule {
    V5Family family = V5Family::Cmov;
    uint32_t site_start = 0;
    uint16_t site_len = 0;
    uint16_t canonical_form = 0;
    uint16_t native_choice = 0;
    std::string pattern_kind = "pattern";
};

struct V5ScanOptions {
    bool scan_cmov = false;
    bool scan_wide = false;
    bool scan_rotate = false;
    bool scan_lea = false;
    bool scan_extract = false;
    bool scan_zero_ext = false;
    bool scan_endian = false;
    bool scan_branch_flip = false;
    bool use_rorx = false;
};

struct V5ScanSummary {
    std::vector<V5PolicyRule> rules;
    uint64_t cmov_sites = 0;
    uint64_t wide_sites = 0;
    uint64_t rotate_sites = 0;
    uint64_t lea_sites = 0;
    uint64_t bitfield_sites = 0;
    uint64_t zero_ext_sites = 0;
    uint64_t endian_sites = 0;
    uint64_t branch_flip_sites = 0;
};

const char *v5_family_name(V5Family family);
std::optional<V5Family> parse_v5_family_name(std::string_view name);

V5ScanSummary scan_v5_builtin(const uint8_t *xlated_data,
                              uint32_t xlated_len,
                              const V5ScanOptions &options);

std::vector<uint8_t> build_policy_blob_v5(uint32_t insn_cnt,
                                          const uint8_t prog_tag[8],
                                          const std::vector<V5PolicyRule> &rules);

} // namespace bpf_jit_scanner

#endif /* BPF_JIT_SCANNER_PATTERN_V5_HPP */
