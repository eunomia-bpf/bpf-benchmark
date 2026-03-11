/* SPDX-License-Identifier: MIT */
#ifndef BPF_JIT_SCANNER_PATTERN_V5_HPP
#define BPF_JIT_SCANNER_PATTERN_V5_HPP

#include "types.h"

#include <cstdint>
#include <vector>

#ifndef BPF_JIT_POLICY_VERSION_2
#define BPF_JIT_POLICY_VERSION_2 2
#endif

#ifndef BPF_JIT_RK_PATTERN
#define BPF_JIT_RK_PATTERN 6
#endif

#ifndef BPF_JIT_CF_ROTATE
#define BPF_JIT_CF_ROTATE 1
#define BPF_JIT_CF_WIDE_MEM 2
#define BPF_JIT_CF_ADDR_CALC 3
#define BPF_JIT_CF_COND_SELECT 4
#define BPF_JIT_CF_BITFIELD_EXTRACT 5
#endif

#ifndef BPF_JIT_MAX_PATTERN_LEN
#define BPF_JIT_MAX_PATTERN_LEN 24
#define BPF_JIT_MAX_PATTERN_VARS 15
#define BPF_JIT_MAX_CONSTRAINTS 16
#define BPF_JIT_MAX_BINDINGS 12
#define BPF_JIT_MAX_CANONICAL_PARAMS 12
#endif

#ifndef BPF_JIT_PATTERN_F_EXPECT_IMM
#define BPF_JIT_PATTERN_F_EXPECT_IMM (1U << 0)
#define BPF_JIT_PATTERN_F_EXPECT_DST_REG (1U << 1)
#define BPF_JIT_PATTERN_F_EXPECT_SRC_REG (1U << 2)
#define BPF_JIT_PATTERN_F_EXPECT_OFF (1U << 3)
#endif

#ifndef BPF_JIT_CSTR_EQUAL
#define BPF_JIT_CSTR_EQUAL 1
#define BPF_JIT_CSTR_SUM_CONST 2
#define BPF_JIT_CSTR_IMM_RANGE 3
#define BPF_JIT_CSTR_NOT_ZERO 4
#define BPF_JIT_CSTR_MASK_BITS 5
#define BPF_JIT_CSTR_DIFF_CONST 6
#define BPF_JIT_CSTR_NOT_EQUAL 7
#endif

#ifndef BPF_JIT_BIND_SOURCE_REG
#define BPF_JIT_BIND_SOURCE_REG 0
#define BPF_JIT_BIND_SOURCE_IMM 1
#define BPF_JIT_BIND_SOURCE_CONST 2
#endif

#ifndef BPF_JIT_ROT_PARAM_DST_REG
#define BPF_JIT_ROT_PARAM_DST_REG 0
#define BPF_JIT_ROT_PARAM_SRC_REG 1
#define BPF_JIT_ROT_PARAM_AMOUNT 2
#define BPF_JIT_ROT_PARAM_WIDTH 3
#endif

#ifndef BPF_JIT_WMEM_PARAM_DST_REG
#define BPF_JIT_WMEM_PARAM_DST_REG 0
#define BPF_JIT_WMEM_PARAM_BASE_REG 1
#define BPF_JIT_WMEM_PARAM_BASE_OFF 2
#define BPF_JIT_WMEM_PARAM_WIDTH 3
#endif

#ifndef BPF_JIT_WMEM_WIDTH_MASK
#define BPF_JIT_WMEM_WIDTH_MASK 0xffU
#define BPF_JIT_WMEM_F_BIG_ENDIAN (1U << 8)
#endif

#ifndef BPF_JIT_ACALC_PARAM_DST_REG
#define BPF_JIT_ACALC_PARAM_DST_REG 0
#define BPF_JIT_ACALC_PARAM_BASE_REG 1
#define BPF_JIT_ACALC_PARAM_INDEX_REG 2
#define BPF_JIT_ACALC_PARAM_SCALE 3
#endif

#ifndef BPF_JIT_BFX_EXTRACT
#define BPF_JIT_BFX_EXTRACT 1
#endif

#ifndef BPF_JIT_BFX_PARAM_DST_REG
#define BPF_JIT_BFX_PARAM_DST_REG 0
#define BPF_JIT_BFX_PARAM_SRC_REG 1
#define BPF_JIT_BFX_PARAM_SHIFT 2
#define BPF_JIT_BFX_PARAM_MASK 3
#define BPF_JIT_BFX_PARAM_WIDTH 4
#define BPF_JIT_BFX_PARAM_ORDER 5
#endif

#ifndef BPF_JIT_BFX_ORDER_SHIFT_MASK
#define BPF_JIT_BFX_ORDER_SHIFT_MASK 0
#define BPF_JIT_BFX_ORDER_MASK_SHIFT 1
#endif

#ifndef BPF_JIT_SEL_PARAM_DST_REG
#define BPF_JIT_SEL_PARAM_DST_REG 0
#define BPF_JIT_SEL_PARAM_COND_OP 1
#define BPF_JIT_SEL_PARAM_COND_A 2
#define BPF_JIT_SEL_PARAM_COND_B 3
#define BPF_JIT_SEL_PARAM_TRUE_VAL 4
#define BPF_JIT_SEL_PARAM_FALSE_VAL 5
#define BPF_JIT_SEL_PARAM_WIDTH 6
#endif

namespace bpf_jit_scanner {

enum class V5Family {
    Cmov,
    WideMem,
    Rotate,
    AddrCalc,
    BitfieldExtract,
};

struct __attribute__((packed)) V5PatternInsn {
    uint8_t opcode = 0;
    uint8_t dst_binding = 0;
    uint8_t src_binding = 0;
    uint8_t imm_binding = 0;
    uint8_t off_binding = 0;
    uint8_t flags = 0;
    uint8_t expected_dst_reg = 0;
    uint8_t expected_src_reg = 0;
    int16_t expected_off = 0;
    uint16_t reserved = 0;
    int32_t expected_imm = 0;
};
static_assert(sizeof(V5PatternInsn) == 16, "V5PatternInsn must match kernel ABI");

struct __attribute__((packed)) V5PatternConstraint {
    uint8_t type = 0;
    uint8_t var_a = 0;
    uint8_t var_b = 0;
    uint8_t reserved = 0;
    int32_t constant = 0;
    int32_t constant_hi = 0;
    uint32_t reserved2 = 0;
};
static_assert(sizeof(V5PatternConstraint) == 16,
              "V5PatternConstraint must match kernel ABI");

struct __attribute__((packed)) V5Binding {
    uint8_t canonical_param = 0;
    uint8_t source_var = 0;
    uint8_t source_type = 0;
    uint8_t reserved = 0;
    int32_t inline_const = 0;
};
static_assert(sizeof(V5Binding) == 8, "V5Binding must match kernel ABI");

struct __attribute__((packed)) V5RuleWire {
    uint32_t site_start = 0;
    uint32_t cpu_features_required = 0;
    uint16_t site_len = 0;
    uint16_t rule_kind = 0;
    uint16_t canonical_form = 0;
    uint16_t native_choice = 0;
    uint16_t priority = 0;
    uint16_t pattern_count = 0;
    uint16_t constraint_count = 0;
    uint16_t binding_count = 0;
    uint16_t rule_len = 0;
    uint16_t reserved = 0;
};
static_assert(sizeof(V5RuleWire) == 28, "V5RuleWire must match kernel ABI");

struct V5PatternDesc {
    V5Family family = V5Family::Cmov;
    uint16_t canonical_form = 0;
    uint16_t native_choice = 0;
    uint32_t cpu_features_required = 0;
    std::vector<V5PatternInsn> pattern;
    std::vector<V5PatternConstraint> constraints;
    std::vector<V5Binding> bindings;
};

struct V5PolicyRule {
    V5Family family = V5Family::Cmov;
    uint32_t site_start = 0;
    uint16_t canonical_form = 0;
    uint16_t native_choice = 0;
    uint16_t priority = 0;
    uint32_t cpu_features_required = 0;
    std::vector<V5PatternInsn> pattern;
    std::vector<V5PatternConstraint> constraints;
    std::vector<V5Binding> bindings;
};

struct V5ScanOptions {
    bool scan_cmov = false;
    bool scan_wide = false;
    bool scan_rotate = false;
    bool scan_lea = false;
    bool scan_extract = false;
    bool use_rorx = false;
};

struct V5ScanSummary {
    std::vector<V5PolicyRule> rules;
    uint64_t cmov_sites = 0;
    uint64_t wide_sites = 0;
    uint64_t rotate_sites = 0;
    uint64_t lea_sites = 0;
    uint64_t bitfield_sites = 0;
};

const char *v5_family_name(V5Family family);

std::vector<V5PatternDesc> build_v5_cond_select_descriptors();
std::vector<V5PatternDesc> build_v5_wide_descriptors();
std::vector<V5PatternDesc> build_v5_rotate_descriptors(bool use_rorx);
std::vector<V5PatternDesc> build_v5_lea_descriptors();
std::vector<V5PatternDesc> build_v5_bitfield_extract_descriptors();

V5ScanSummary scan_v5_builtin(const uint8_t *xlated_data,
                              uint32_t xlated_len,
                              const V5ScanOptions &options);

std::vector<uint8_t> build_policy_blob_v5(uint32_t insn_cnt,
                                          const uint8_t prog_tag[8],
                                          const std::vector<V5PolicyRule> &rules);

} // namespace bpf_jit_scanner

#endif /* BPF_JIT_SCANNER_PATTERN_V5_HPP */
