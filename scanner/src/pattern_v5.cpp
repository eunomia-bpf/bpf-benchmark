// SPDX-License-Identifier: MIT

#include "bpf_jit_scanner/pattern_v5.hpp"

#include <cstring>
#include <utility>

namespace bpf_jit_scanner {

namespace {

struct bpf_insn_raw {
    uint8_t code;
    uint8_t regs;
    int16_t off;
    int32_t imm;
};

struct V5PatternVar {
    bool bound = false;
    uint8_t type = 0;
    int64_t value = 0;
};

constexpr uint8_t kPatternVarReg = 1;
constexpr uint8_t kPatternVarImm = 2;
constexpr uint8_t kPatternVarOff = 3;

constexpr uint8_t raw_dst_reg(const bpf_insn_raw &insn)
{
    return insn.regs & 0x0f;
}

constexpr uint8_t raw_src_reg(const bpf_insn_raw &insn)
{
    return static_cast<uint8_t>((insn.regs >> 4) & 0x0f);
}

V5PatternInsn make_pattern_insn(uint8_t opcode,
                                uint8_t dst_binding = 0,
                                uint8_t src_binding = 0,
                                uint8_t imm_binding = 0,
                                uint8_t off_binding = 0,
                                uint8_t flags = 0,
                                uint8_t expected_dst_reg = 0,
                                uint8_t expected_src_reg = 0,
                                int16_t expected_off = 0,
                                int32_t expected_imm = 0)
{
    V5PatternInsn insn = {};
    insn.opcode = opcode;
    insn.dst_binding = dst_binding;
    insn.src_binding = src_binding;
    insn.imm_binding = imm_binding;
    insn.off_binding = off_binding;
    insn.flags = flags;
    insn.expected_dst_reg = expected_dst_reg;
    insn.expected_src_reg = expected_src_reg;
    insn.expected_off = expected_off;
    insn.expected_imm = expected_imm;
    return insn;
}

V5PatternConstraint make_constraint(uint8_t type,
                                    uint8_t var_a,
                                    uint8_t var_b = 0,
                                    int32_t constant = 0,
                                    int32_t constant_hi = 0)
{
    V5PatternConstraint constraint = {};
    constraint.type = type;
    constraint.var_a = var_a;
    constraint.var_b = var_b;
    constraint.constant = constant;
    constraint.constant_hi = constant_hi;
    return constraint;
}

V5Binding make_var_binding(uint8_t canonical_param,
                           uint8_t source_var,
                           uint8_t source_type)
{
    V5Binding binding = {};
    binding.canonical_param = canonical_param;
    binding.source_var = source_var;
    binding.source_type = source_type;
    return binding;
}

V5Binding make_const_binding(uint8_t canonical_param, int32_t value)
{
    V5Binding binding = {};
    binding.canonical_param = canonical_param;
    binding.source_type = BPF_JIT_BIND_SOURCE_CONST;
    binding.inline_const = value;
    return binding;
}

V5PatternDesc make_v5_desc(V5Family family,
                           uint16_t canonical_form,
                           uint16_t native_choice,
                           uint32_t cpu_features_required,
                           std::vector<V5PatternInsn> pattern,
                           std::vector<V5PatternConstraint> constraints,
                           std::vector<V5Binding> bindings)
{
    V5PatternDesc desc;
    desc.family = family;
    desc.canonical_form = canonical_form;
    desc.native_choice = native_choice;
    desc.cpu_features_required = cpu_features_required;
    desc.pattern = std::move(pattern);
    desc.constraints = std::move(constraints);
    desc.bindings = std::move(bindings);
    return desc;
}

V5PolicyRule make_v5_policy_rule(uint32_t site_start, const V5PatternDesc &desc)
{
    V5PolicyRule rule;
    rule.family = desc.family;
    rule.site_start = site_start;
    rule.canonical_form = desc.canonical_form;
    rule.native_choice = desc.native_choice;
    rule.priority = 0;
    rule.cpu_features_required = desc.cpu_features_required;
    rule.pattern = desc.pattern;
    rule.constraints = desc.constraints;
    rule.bindings = desc.bindings;
    return rule;
}

std::vector<bpf_insn_raw> parse_xlated_insns(const uint8_t *xlated_data,
                                             uint32_t xlated_len)
{
    const uint32_t insn_cnt = xlated_len / sizeof(bpf_insn_raw);
    std::vector<bpf_insn_raw> insns(insn_cnt);
    for (uint32_t i = 0; i < insn_cnt; ++i) {
        std::memcpy(&insns[i], xlated_data + i * sizeof(bpf_insn_raw),
                    sizeof(bpf_insn_raw));
    }
    return insns;
}

bool bind_v5_pattern_var(std::vector<V5PatternVar> &vars,
                         uint8_t var_id,
                         uint8_t type,
                         int64_t value)
{
    if (var_id == 0) {
        return true;
    }
    if (var_id > BPF_JIT_MAX_PATTERN_VARS) {
        return false;
    }

    auto &var = vars[var_id];
    if (!var.bound) {
        var.bound = true;
        var.type = type;
        var.value = value;
        return true;
    }

    return var.type == type && var.value == value;
}

bool check_v5_constraints(const std::vector<V5PatternConstraint> &constraints,
                          const std::vector<V5PatternVar> &vars)
{
    for (const auto &constraint : constraints) {
        if (constraint.var_a == 0 || constraint.var_a > BPF_JIT_MAX_PATTERN_VARS ||
            !vars[constraint.var_a].bound) {
            return false;
        }

        const int64_t var_a = vars[constraint.var_a].value;
        switch (constraint.type) {
        case BPF_JIT_CSTR_EQUAL:
            if (constraint.var_b == 0 || constraint.var_b > BPF_JIT_MAX_PATTERN_VARS ||
                !vars[constraint.var_b].bound ||
                var_a != vars[constraint.var_b].value) {
                return false;
            }
            break;
        case BPF_JIT_CSTR_SUM_CONST:
            if (constraint.var_b == 0 || constraint.var_b > BPF_JIT_MAX_PATTERN_VARS ||
                !vars[constraint.var_b].bound ||
                var_a + vars[constraint.var_b].value != constraint.constant) {
                return false;
            }
            break;
        case BPF_JIT_CSTR_IMM_RANGE:
            if (var_a < constraint.constant || var_a > constraint.constant_hi) {
                return false;
            }
            break;
        case BPF_JIT_CSTR_NOT_ZERO:
            if (var_a == 0) {
                return false;
            }
            break;
        case BPF_JIT_CSTR_MASK_BITS:
            if ((var_a & constraint.constant) == 0) {
                return false;
            }
            break;
        case BPF_JIT_CSTR_DIFF_CONST:
            if (constraint.var_b == 0 || constraint.var_b > BPF_JIT_MAX_PATTERN_VARS ||
                !vars[constraint.var_b].bound ||
                var_a - vars[constraint.var_b].value != constraint.constant) {
                return false;
            }
            break;
        case BPF_JIT_CSTR_NOT_EQUAL:
            if (constraint.var_b == 0 || constraint.var_b > BPF_JIT_MAX_PATTERN_VARS ||
                !vars[constraint.var_b].bound ||
                var_a == vars[constraint.var_b].value) {
                return false;
            }
            break;
        default:
            return false;
        }
    }

    return true;
}

bool match_v5_pattern_at(const std::vector<bpf_insn_raw> &insns,
                         uint32_t idx,
                         const V5PatternDesc &desc)
{
    if (idx + desc.pattern.size() > insns.size()) {
        return false;
    }

    std::vector<V5PatternVar> vars(BPF_JIT_MAX_PATTERN_VARS + 1);
    for (size_t i = 0; i < desc.pattern.size(); ++i) {
        const auto &pattern = desc.pattern[i];
        const auto &insn = insns[idx + i];

        if (insn.code != pattern.opcode) {
            return false;
        }
        if ((pattern.flags & BPF_JIT_PATTERN_F_EXPECT_IMM) &&
            insn.imm != pattern.expected_imm) {
            return false;
        }
        if ((pattern.flags & BPF_JIT_PATTERN_F_EXPECT_DST_REG) &&
            raw_dst_reg(insn) != pattern.expected_dst_reg) {
            return false;
        }
        if ((pattern.flags & BPF_JIT_PATTERN_F_EXPECT_SRC_REG) &&
            raw_src_reg(insn) != pattern.expected_src_reg) {
            return false;
        }
        if ((pattern.flags & BPF_JIT_PATTERN_F_EXPECT_OFF) &&
            insn.off != pattern.expected_off) {
            return false;
        }

        if (!bind_v5_pattern_var(vars, pattern.dst_binding, kPatternVarReg,
                                 raw_dst_reg(insn)) ||
            !bind_v5_pattern_var(vars, pattern.src_binding, kPatternVarReg,
                                 raw_src_reg(insn)) ||
            !bind_v5_pattern_var(vars, pattern.imm_binding, kPatternVarImm,
                                 insn.imm) ||
            !bind_v5_pattern_var(vars, pattern.off_binding, kPatternVarOff,
                                 insn.off)) {
            return false;
        }
    }

    return check_v5_constraints(desc.constraints, vars);
}

void append_blob_bytes(std::vector<uint8_t> &blob, const void *data, size_t size)
{
    const auto *bytes = static_cast<const uint8_t *>(data);
    blob.insert(blob.end(), bytes, bytes + size);
}

V5PatternInsn make_simple_mov_pattern(uint8_t opcode,
                                      uint8_t dst_binding,
                                      uint8_t value_binding)
{
    constexpr uint8_t kExpectOffImm = BPF_JIT_PATTERN_F_EXPECT_OFF |
                                      BPF_JIT_PATTERN_F_EXPECT_IMM;
    constexpr uint8_t kExpectOffSrc = BPF_JIT_PATTERN_F_EXPECT_OFF |
                                      BPF_JIT_PATTERN_F_EXPECT_SRC_REG;

    if ((opcode & 0x08U) != 0) {
        return make_pattern_insn(opcode, dst_binding, value_binding, 0, 0,
                                 kExpectOffImm, 0, 0, 0, 0);
    }

    return make_pattern_insn(opcode, dst_binding, 0, value_binding, 0,
                             kExpectOffSrc, 0, 0, 0, 0);
}

V5PatternInsn make_jump_pattern(uint8_t opcode,
                                uint8_t lhs_binding,
                                uint8_t rhs_binding,
                                int16_t expected_off)
{
    constexpr uint8_t kExpectOffImm = BPF_JIT_PATTERN_F_EXPECT_OFF |
                                      BPF_JIT_PATTERN_F_EXPECT_IMM;
    constexpr uint8_t kExpectOffSrc = BPF_JIT_PATTERN_F_EXPECT_OFF |
                                      BPF_JIT_PATTERN_F_EXPECT_SRC_REG;

    if ((opcode & 0x08U) != 0) {
        return make_pattern_insn(opcode, lhs_binding, rhs_binding, 0, 0,
                                 kExpectOffImm, 0, 0, expected_off, 0);
    }

    return make_pattern_insn(opcode, lhs_binding, 0, rhs_binding, 0,
                             kExpectOffSrc, 0, 0, expected_off, 0);
}

V5PatternInsn make_jump_pattern_var_off(uint8_t opcode,
                                        uint8_t lhs_binding,
                                        uint8_t rhs_binding,
                                        uint8_t off_binding)
{
    constexpr uint8_t kExpectImm = BPF_JIT_PATTERN_F_EXPECT_IMM;
    constexpr uint8_t kExpectSrc = BPF_JIT_PATTERN_F_EXPECT_SRC_REG;

    if ((opcode & 0x08U) != 0) {
        return make_pattern_insn(opcode, lhs_binding, rhs_binding, 0, off_binding,
                                 kExpectImm, 0, 0, 0, 0);
    }

    return make_pattern_insn(opcode, lhs_binding, 0, rhs_binding, off_binding,
                             kExpectSrc, 0, 0, 0, 0);
}

V5PatternInsn make_simple_alu_pattern(uint8_t opcode,
                                      uint8_t dst_binding,
                                      uint8_t value_binding)
{
    constexpr uint8_t kExpectOffImm = BPF_JIT_PATTERN_F_EXPECT_OFF |
                                      BPF_JIT_PATTERN_F_EXPECT_IMM;
    constexpr uint8_t kExpectOffSrc = BPF_JIT_PATTERN_F_EXPECT_OFF |
                                      BPF_JIT_PATTERN_F_EXPECT_SRC_REG;

    if ((opcode & 0x08U) != 0) {
        return make_pattern_insn(opcode, dst_binding, value_binding, 0, 0,
                                 kExpectOffImm, 0, 0, 0, 0);
    }

    return make_pattern_insn(opcode, dst_binding, 0, value_binding, 0,
                             kExpectOffSrc, 0, 0, 0, 0);
}

V5PatternInsn make_ja_pattern_var_off(uint8_t off_binding)
{
    constexpr uint8_t kJa = 0x05;
    constexpr uint8_t kJaFlags = BPF_JIT_PATTERN_F_EXPECT_IMM |
                                 BPF_JIT_PATTERN_F_EXPECT_DST_REG |
                                 BPF_JIT_PATTERN_F_EXPECT_SRC_REG;

    return make_pattern_insn(kJa, 0, 0, 0, off_binding, kJaFlags, 0, 0, 0, 0);
}

std::vector<V5Binding> make_select_bindings(uint8_t jump_opcode,
                                            int32_t width,
                                            uint8_t true_value_var,
                                            uint8_t true_source_type,
                                            uint8_t false_value_var,
                                            uint8_t false_source_type)
{
    const bool jump_is_x = (jump_opcode & 0x08U) != 0;
    return {
        make_var_binding(BPF_JIT_SEL_PARAM_DST_REG, 1,
                         BPF_JIT_BIND_SOURCE_REG),
        make_const_binding(BPF_JIT_SEL_PARAM_COND_OP, jump_opcode & 0xf0U),
        make_var_binding(BPF_JIT_SEL_PARAM_COND_A, 2,
                         BPF_JIT_BIND_SOURCE_REG),
        make_var_binding(BPF_JIT_SEL_PARAM_COND_B, 3,
                         jump_is_x ? BPF_JIT_BIND_SOURCE_REG
                                   : BPF_JIT_BIND_SOURCE_IMM),
        make_var_binding(BPF_JIT_SEL_PARAM_TRUE_VAL, true_value_var,
                         true_source_type),
        make_var_binding(BPF_JIT_SEL_PARAM_FALSE_VAL, false_value_var,
                         false_source_type),
        make_const_binding(BPF_JIT_SEL_PARAM_WIDTH, width),
    };
}

void add_v5_cond_select_descs_for_jump(std::vector<V5PatternDesc> &descs,
                                       uint8_t jump_opcode,
                                       uint8_t mov_x_opcode,
                                       uint8_t mov_k_opcode)
{
    constexpr uint8_t kJa = 0x05;
    constexpr uint8_t kJaFlags = BPF_JIT_PATTERN_F_EXPECT_OFF |
                                 BPF_JIT_PATTERN_F_EXPECT_IMM |
                                 BPF_JIT_PATTERN_F_EXPECT_DST_REG |
                                 BPF_JIT_PATTERN_F_EXPECT_SRC_REG;
    const bool is_jmp32 = (jump_opcode & 0x07U) == 0x06U;
    const bool jump_is_x = (jump_opcode & 0x08U) != 0;
    const int32_t width = is_jmp32 ? 32 : 64;

    const uint8_t move_opcodes[2] = {mov_x_opcode, mov_k_opcode};
    for (const uint8_t true_opcode : move_opcodes) {
        for (const uint8_t false_opcode : move_opcodes) {
            const bool true_is_x = (true_opcode & 0x08U) != 0;
            const bool false_is_x = (false_opcode & 0x08U) != 0;

            descs.push_back(make_v5_desc(
                V5Family::Cmov,
                BPF_JIT_CF_COND_SELECT,
                BPF_JIT_SEL_CMOVCC,
                0,
                {
                    make_jump_pattern(jump_opcode, 2, 3, 2),
                    make_simple_mov_pattern(false_opcode, 1, 4),
                    make_pattern_insn(kJa, 0, 0, 0, 0, kJaFlags, 0, 0, 1, 0),
                    make_simple_mov_pattern(true_opcode, 1, 5),
                },
                {},
                {
                    make_var_binding(BPF_JIT_SEL_PARAM_DST_REG, 1,
                                     BPF_JIT_BIND_SOURCE_REG),
                    make_const_binding(BPF_JIT_SEL_PARAM_COND_OP,
                                       jump_opcode & 0xf0U),
                    make_var_binding(BPF_JIT_SEL_PARAM_COND_A, 2,
                                     BPF_JIT_BIND_SOURCE_REG),
                    make_var_binding(BPF_JIT_SEL_PARAM_COND_B, 3,
                                     jump_is_x ? BPF_JIT_BIND_SOURCE_REG
                                               : BPF_JIT_BIND_SOURCE_IMM),
                    make_var_binding(BPF_JIT_SEL_PARAM_TRUE_VAL, 5,
                                     true_is_x ? BPF_JIT_BIND_SOURCE_REG
                                               : BPF_JIT_BIND_SOURCE_IMM),
                    make_var_binding(BPF_JIT_SEL_PARAM_FALSE_VAL, 4,
                                     false_is_x ? BPF_JIT_BIND_SOURCE_REG
                                                : BPF_JIT_BIND_SOURCE_IMM),
                    make_const_binding(BPF_JIT_SEL_PARAM_WIDTH, width),
                }));

            descs.push_back(make_v5_desc(
                V5Family::Cmov,
                BPF_JIT_CF_COND_SELECT,
                BPF_JIT_SEL_CMOVCC,
                0,
                {
                    make_simple_mov_pattern(true_opcode, 1, 5),
                    make_jump_pattern(jump_opcode, 2, 3, 1),
                    make_simple_mov_pattern(false_opcode, 1, 4),
                },
                {},
                {
                    make_var_binding(BPF_JIT_SEL_PARAM_DST_REG, 1,
                                     BPF_JIT_BIND_SOURCE_REG),
                    make_const_binding(BPF_JIT_SEL_PARAM_COND_OP,
                                       jump_opcode & 0xf0U),
                    make_var_binding(BPF_JIT_SEL_PARAM_COND_A, 2,
                                     BPF_JIT_BIND_SOURCE_REG),
                    make_var_binding(BPF_JIT_SEL_PARAM_COND_B, 3,
                                     jump_is_x ? BPF_JIT_BIND_SOURCE_REG
                                               : BPF_JIT_BIND_SOURCE_IMM),
                    make_var_binding(BPF_JIT_SEL_PARAM_TRUE_VAL, 5,
                                     true_is_x ? BPF_JIT_BIND_SOURCE_REG
                                               : BPF_JIT_BIND_SOURCE_IMM),
                    make_var_binding(BPF_JIT_SEL_PARAM_FALSE_VAL, 4,
                                     false_is_x ? BPF_JIT_BIND_SOURCE_REG
                                                : BPF_JIT_BIND_SOURCE_IMM),
                    make_const_binding(BPF_JIT_SEL_PARAM_WIDTH, width),
                }));
        }
    }
}

void add_v5_guarded_update_descs_for_jump(std::vector<V5PatternDesc> &descs,
                                          uint8_t jump_opcode,
                                          uint8_t mov_x_opcode,
                                          uint8_t mov_k_opcode)
{
    const bool is_jmp32 = (jump_opcode & 0x07U) == 0x06U;
    const int32_t width = is_jmp32 ? 32 : 64;
    const uint8_t move_opcodes[2] = {mov_x_opcode, mov_k_opcode};
    const uint8_t add_x_opcode = is_jmp32 ? 0x0c : 0x0f;
    const uint8_t xor_x_opcode = is_jmp32 ? 0xac : 0xaf;
    const uint8_t lsh_k_opcode = is_jmp32 ? 0x64 : 0x67;
    const uint8_t rsh_k_opcode = is_jmp32 ? 0x74 : 0x77;

    for (const uint8_t true_opcode : move_opcodes) {
        const uint8_t true_source_type = (true_opcode & 0x08U) != 0
                                             ? BPF_JIT_BIND_SOURCE_REG
                                             : BPF_JIT_BIND_SOURCE_IMM;

        descs.push_back(make_v5_desc(
            V5Family::Cmov,
            BPF_JIT_CF_COND_SELECT,
            BPF_JIT_SEL_CMOVCC,
            0,
            {
                make_jump_pattern(jump_opcode, 2, 3, 1),
                make_simple_mov_pattern(true_opcode, 1, 5),
            },
            {},
            make_select_bindings(jump_opcode, width, 5, true_source_type,
                                 1, BPF_JIT_BIND_SOURCE_REG)));

        descs.push_back(make_v5_desc(
            V5Family::Cmov,
            BPF_JIT_CF_COND_SELECT,
            BPF_JIT_SEL_CMOVCC,
            0,
            {
                make_jump_pattern_var_off(jump_opcode, 2, 3, 6),
                make_simple_mov_pattern(true_opcode, 1, 5),
                make_ja_pattern_var_off(7),
            },
            {
                make_constraint(BPF_JIT_CSTR_DIFF_CONST, 6, 7, 2),
            },
            make_select_bindings(jump_opcode, width, 5, true_source_type,
                                 1, BPF_JIT_BIND_SOURCE_REG)));
    }

    descs.push_back(make_v5_desc(
        V5Family::Cmov,
        BPF_JIT_CF_COND_SELECT,
        BPF_JIT_SEL_CMOVCC,
        0,
        {
            make_jump_pattern_var_off(jump_opcode, 2, 3, 6),
            make_simple_alu_pattern(add_x_opcode, 5, 7),
            make_simple_mov_pattern(mov_x_opcode, 1, 5),
            make_ja_pattern_var_off(8),
        },
        {
            make_constraint(BPF_JIT_CSTR_DIFF_CONST, 6, 8, 3),
        },
        make_select_bindings(jump_opcode, width, 5, BPF_JIT_BIND_SOURCE_REG,
                             1, BPF_JIT_BIND_SOURCE_REG)));

    for (const uint8_t shift_opcode : {rsh_k_opcode, lsh_k_opcode}) {
        descs.push_back(make_v5_desc(
            V5Family::Cmov,
            BPF_JIT_CF_COND_SELECT,
            BPF_JIT_SEL_CMOVCC,
            0,
            {
                make_jump_pattern(jump_opcode, 2, 3, 3),
                make_simple_alu_pattern(shift_opcode, 6, 7),
                make_simple_alu_pattern(xor_x_opcode, 5, 6),
                make_simple_mov_pattern(mov_x_opcode, 1, 5),
            },
            {},
            make_select_bindings(jump_opcode, width, 5, BPF_JIT_BIND_SOURCE_REG,
                                 1, BPF_JIT_BIND_SOURCE_REG)));

        descs.push_back(make_v5_desc(
            V5Family::Cmov,
            BPF_JIT_CF_COND_SELECT,
            BPF_JIT_SEL_CMOVCC,
            0,
            {
                make_jump_pattern_var_off(jump_opcode, 2, 3, 8),
                make_simple_alu_pattern(shift_opcode, 6, 7),
                make_simple_alu_pattern(xor_x_opcode, 5, 6),
                make_simple_mov_pattern(mov_x_opcode, 1, 5),
                make_ja_pattern_var_off(9),
            },
            {
                make_constraint(BPF_JIT_CSTR_DIFF_CONST, 8, 9, 4),
            },
            make_select_bindings(jump_opcode, width, 5, BPF_JIT_BIND_SOURCE_REG,
                                 1, BPF_JIT_BIND_SOURCE_REG)));
    }
}

void add_v5_wide_diamond_descs_for_jump(std::vector<V5PatternDesc> &descs,
                                        uint8_t jump_opcode,
                                        uint8_t mov_x_opcode,
                                        uint8_t mov_k_opcode)
{
    constexpr uint8_t kJa = 0x05;
    constexpr uint8_t kJaFlags = BPF_JIT_PATTERN_F_EXPECT_OFF |
                                 BPF_JIT_PATTERN_F_EXPECT_IMM |
                                 BPF_JIT_PATTERN_F_EXPECT_DST_REG |
                                 BPF_JIT_PATTERN_F_EXPECT_SRC_REG;
    const bool is_jmp32 = (jump_opcode & 0x07U) == 0x06U;
    const int32_t width = is_jmp32 ? 32 : 64;
    const uint8_t add_x_opcode = is_jmp32 ? 0x0c : 0x0f;
    const uint8_t xor_x_opcode = is_jmp32 ? 0xac : 0xaf;
    const uint8_t lsh_k_opcode = is_jmp32 ? 0x64 : 0x67;
    const uint8_t rsh_k_opcode = is_jmp32 ? 0x74 : 0x77;
    const uint8_t move_opcodes[2] = {mov_x_opcode, mov_k_opcode};

    for (const uint8_t true_opcode : move_opcodes) {
        const uint8_t true_source_type = (true_opcode & 0x08U) != 0
                                             ? BPF_JIT_BIND_SOURCE_REG
                                             : BPF_JIT_BIND_SOURCE_IMM;

        descs.push_back(make_v5_desc(
            V5Family::Cmov,
            BPF_JIT_CF_COND_SELECT,
            BPF_JIT_SEL_CMOVCC,
            0,
            {
                make_jump_pattern(jump_opcode, 2, 3, 3),
                make_simple_alu_pattern(add_x_opcode, 6, 7),
                make_simple_mov_pattern(mov_x_opcode, 1, 6),
                make_pattern_insn(kJa, 0, 0, 0, 0, kJaFlags, 0, 0, 1, 0),
                make_simple_mov_pattern(true_opcode, 1, 5),
            },
            {},
            make_select_bindings(jump_opcode, width, 5, true_source_type,
                                 6, BPF_JIT_BIND_SOURCE_REG)));

        for (const uint8_t shift_opcode : {rsh_k_opcode, lsh_k_opcode}) {
            descs.push_back(make_v5_desc(
                V5Family::Cmov,
                BPF_JIT_CF_COND_SELECT,
                BPF_JIT_SEL_CMOVCC,
                0,
                {
                    make_jump_pattern(jump_opcode, 2, 3, 4),
                    make_simple_alu_pattern(shift_opcode, 6, 7),
                    make_simple_alu_pattern(xor_x_opcode, 4, 6),
                    make_simple_mov_pattern(mov_x_opcode, 1, 4),
                    make_pattern_insn(kJa, 0, 0, 0, 0, kJaFlags, 0, 0, 1, 0),
                    make_simple_mov_pattern(true_opcode, 1, 5),
                },
                {},
                make_select_bindings(jump_opcode, width, 5, true_source_type,
                                     4, BPF_JIT_BIND_SOURCE_REG)));
        }
    }
}

void add_v5_switch_chain_descs_for_jump(std::vector<V5PatternDesc> &descs,
                                        uint8_t jump_opcode,
                                        uint8_t mov_x_opcode,
                                        uint8_t mov_k_opcode)
{
    const bool is_jmp32 = (jump_opcode & 0x07U) == 0x06U;
    const bool jump_is_x = (jump_opcode & 0x08U) != 0;
    const int32_t width = is_jmp32 ? 32 : 64;
    const uint8_t move_opcodes[2] = {mov_x_opcode, mov_k_opcode};

    for (const uint8_t true_opcode : move_opcodes) {
        const uint8_t true_source_type = (true_opcode & 0x08U) != 0
                                             ? BPF_JIT_BIND_SOURCE_REG
                                             : BPF_JIT_BIND_SOURCE_IMM;
        for (const uint8_t false_opcode : move_opcodes) {
            const uint8_t false_source_type = (false_opcode & 0x08U) != 0
                                                  ? BPF_JIT_BIND_SOURCE_REG
                                                  : BPF_JIT_BIND_SOURCE_IMM;

            descs.push_back(make_v5_desc(
                V5Family::Cmov,
                BPF_JIT_CF_COND_SELECT,
                BPF_JIT_SEL_CMOVCC,
                0,
                {
                    make_simple_mov_pattern(false_opcode, 1, 4),
                    make_jump_pattern_var_off(jump_opcode, 2, 6, 7),
                    make_jump_pattern(jump_opcode, 2, 3, 1),
                    make_ja_pattern_var_off(8),
                    make_simple_mov_pattern(true_opcode, 1, 5),
                    make_ja_pattern_var_off(9),
                },
                {
                    make_constraint(BPF_JIT_CSTR_DIFF_CONST, 7, 9, 4),
                    make_constraint(BPF_JIT_CSTR_NOT_EQUAL, 3, 6),
                },
                {
                    make_var_binding(BPF_JIT_SEL_PARAM_DST_REG, 1,
                                     BPF_JIT_BIND_SOURCE_REG),
                    make_const_binding(BPF_JIT_SEL_PARAM_COND_OP,
                                       jump_opcode & 0xf0U),
                    make_var_binding(BPF_JIT_SEL_PARAM_COND_A, 2,
                                     BPF_JIT_BIND_SOURCE_REG),
                    make_var_binding(BPF_JIT_SEL_PARAM_COND_B, 3,
                                     jump_is_x ? BPF_JIT_BIND_SOURCE_REG
                                               : BPF_JIT_BIND_SOURCE_IMM),
                    make_var_binding(BPF_JIT_SEL_PARAM_TRUE_VAL, 5,
                                     true_source_type),
                    make_var_binding(BPF_JIT_SEL_PARAM_FALSE_VAL, 4,
                                     false_source_type),
                    make_const_binding(BPF_JIT_SEL_PARAM_WIDTH, width),
                }));
        }
    }
}

} // namespace

const char *v5_family_name(V5Family family)
{
    switch (family) {
    case V5Family::Cmov:
        return "cmov";
    case V5Family::WideMem:
        return "wide_load";
    case V5Family::Rotate:
        return "rotate";
    case V5Family::AddrCalc:
        return "addr_calc";
    case V5Family::BitfieldExtract:
        return "bitfield_extract";
    default:
        return "unknown";
    }
}

std::vector<V5PatternDesc> build_v5_cond_select_descriptors()
{
    constexpr uint8_t kJumpOpcodes[] = {
        0x15, 0x1d, 0x25, 0x2d, 0x35, 0x3d, 0x45, 0x4d, 0x55, 0x5d,
        0x65, 0x6d, 0x75, 0x7d, 0xa5, 0xad, 0xb5, 0xbd, 0xc5, 0xcd,
        0xd5, 0xdd, 0x16, 0x1e, 0x26, 0x2e, 0x36, 0x3e, 0x46, 0x4e,
        0x56, 0x5e, 0x66, 0x6e, 0x76, 0x7e, 0xa6, 0xae, 0xb6, 0xbe,
        0xc6, 0xce, 0xd6, 0xde,
    };

    std::vector<V5PatternDesc> descs;
    descs.reserve(2048);
    for (const uint8_t jump_opcode : kJumpOpcodes) {
        const bool is_jmp32 = (jump_opcode & 0x07U) == 0x06U;
        const uint8_t mov_x_opcode = is_jmp32 ? 0xbc : 0xbf;
        const uint8_t mov_k_opcode = is_jmp32 ? 0xb4 : 0xb7;

        add_v5_switch_chain_descs_for_jump(descs, jump_opcode,
                                           mov_x_opcode, mov_k_opcode);
        add_v5_wide_diamond_descs_for_jump(descs, jump_opcode,
                                           mov_x_opcode, mov_k_opcode);
        add_v5_guarded_update_descs_for_jump(descs, jump_opcode,
                                             mov_x_opcode, mov_k_opcode);
        add_v5_cond_select_descs_for_jump(descs, jump_opcode,
                                          mov_x_opcode, mov_k_opcode);
    }
    return descs;
}

std::vector<V5PatternDesc> build_v5_wide_descriptors()
{
    constexpr uint8_t kLdxb = 0x71;
    constexpr uint8_t kLsh64 = 0x67;
    constexpr uint8_t kOr64 = 0x4f;
    constexpr uint8_t kExpectZero = BPF_JIT_PATTERN_F_EXPECT_IMM;
    constexpr uint8_t kExpectZeroOffImm = BPF_JIT_PATTERN_F_EXPECT_OFF |
                                          BPF_JIT_PATTERN_F_EXPECT_IMM;

    auto build_wide_low_first_pattern = [&](uint32_t total_bytes) {
        std::vector<V5PatternInsn> pattern;
        pattern.reserve(1 + (total_bytes - 1) * 3);
        pattern.push_back(make_pattern_insn(kLdxb, 1, 2, 0, 3, kExpectZero,
                                            0, 0, 0, 0));

        for (uint32_t i = 1; i < total_bytes; ++i) {
            const uint8_t tmp_reg_var = static_cast<uint8_t>(3 + i);
            const uint8_t off_var = static_cast<uint8_t>(6 + i);

            pattern.push_back(make_pattern_insn(kLdxb, tmp_reg_var, 2, 0,
                                                off_var, kExpectZero, 0, 0, 0, 0));
            pattern.push_back(make_pattern_insn(kLsh64, tmp_reg_var, 0, 0, 0,
                                                kExpectZeroOffImm, 0, 0, 0,
                                                static_cast<int32_t>(i * 8)));
            pattern.push_back(make_pattern_insn(kOr64, 1, tmp_reg_var, 0, 0,
                                                kExpectZeroOffImm, 0, 0, 0, 0));
        }

        return pattern;
    };

    auto build_wide_low_first_constraints = [&](uint32_t total_bytes) {
        std::vector<V5PatternConstraint> constraints;
        constraints.reserve(total_bytes > 0 ? total_bytes - 1 : 0);

        for (uint32_t i = 1; i < total_bytes; ++i) {
            constraints.push_back(make_constraint(BPF_JIT_CSTR_DIFF_CONST,
                                                  static_cast<uint8_t>(6 + i),
                                                  3,
                                                  static_cast<int32_t>(i)));
        }

        return constraints;
    };

    auto build_wide_bindings = [&](uint32_t total_bytes) {
        return std::vector<V5Binding>{
            make_var_binding(BPF_JIT_WMEM_PARAM_DST_REG, 1,
                             BPF_JIT_BIND_SOURCE_REG),
            make_var_binding(BPF_JIT_WMEM_PARAM_BASE_REG, 2,
                             BPF_JIT_BIND_SOURCE_REG),
            make_var_binding(BPF_JIT_WMEM_PARAM_BASE_OFF, 3,
                             BPF_JIT_BIND_SOURCE_IMM),
            make_const_binding(BPF_JIT_WMEM_PARAM_WIDTH,
                               static_cast<int32_t>(total_bytes)),
        };
    };

    auto build_wide_be_high_first_pattern = [&](uint32_t total_bytes) {
        std::vector<V5PatternInsn> pattern;
        pattern.reserve(3 * total_bytes - 2);
        pattern.push_back(make_pattern_insn(kLdxb, 1, 2, 0, 3, kExpectZero,
                                            0, 0, 0, 0));
        if (total_bytes > 1) {
            pattern.push_back(make_pattern_insn(
                kLsh64, 1, 0, 0, 0, kExpectZeroOffImm, 0, 0, 0,
                static_cast<int32_t>((total_bytes - 1) * 8)));
        }

        for (uint32_t i = 1; i < total_bytes; ++i) {
            const uint8_t tmp_reg_var = static_cast<uint8_t>(3 + i);
            const uint8_t off_var = static_cast<uint8_t>(6 + i);

            pattern.push_back(make_pattern_insn(kLdxb, tmp_reg_var, 2, 0,
                                                off_var, kExpectZero, 0, 0, 0, 0));
            if (i + 1 != total_bytes) {
                pattern.push_back(make_pattern_insn(
                    kLsh64, tmp_reg_var, 0, 0, 0, kExpectZeroOffImm,
                    0, 0, 0,
                    static_cast<int32_t>((total_bytes - i - 1) * 8)));
            }
            pattern.push_back(make_pattern_insn(kOr64, 1, tmp_reg_var, 0, 0,
                                                kExpectZeroOffImm, 0, 0, 0, 0));
        }

        return pattern;
    };

    auto build_wide_be_bindings = [&](uint32_t total_bytes) {
        return std::vector<V5Binding>{
            make_var_binding(BPF_JIT_WMEM_PARAM_DST_REG, 1,
                             BPF_JIT_BIND_SOURCE_REG),
            make_var_binding(BPF_JIT_WMEM_PARAM_BASE_REG, 2,
                             BPF_JIT_BIND_SOURCE_REG),
            make_var_binding(BPF_JIT_WMEM_PARAM_BASE_OFF, 3,
                             BPF_JIT_BIND_SOURCE_IMM),
            make_const_binding(BPF_JIT_WMEM_PARAM_WIDTH,
                               static_cast<int32_t>(total_bytes |
                                                    BPF_JIT_WMEM_F_BIG_ENDIAN)),
        };
    };

    std::vector<V5PatternDesc> descs;
    for (const uint32_t width : {8U, 7U, 6U, 5U, 4U, 3U, 2U}) {
        descs.push_back(make_v5_desc(V5Family::WideMem, BPF_JIT_CF_WIDE_MEM,
                                     BPF_JIT_WMEM_WIDE_LOAD, 0,
                                     build_wide_low_first_pattern(width),
                                     build_wide_low_first_constraints(width),
                                     build_wide_bindings(width)));
        descs.push_back(make_v5_desc(V5Family::WideMem, BPF_JIT_CF_WIDE_MEM,
                                     BPF_JIT_WMEM_WIDE_LOAD, 0,
                                     build_wide_be_high_first_pattern(width),
                                     build_wide_low_first_constraints(width),
                                     build_wide_be_bindings(width)));
    }
    descs.push_back(make_v5_desc(
        V5Family::WideMem, BPF_JIT_CF_WIDE_MEM, BPF_JIT_WMEM_WIDE_LOAD, 0,
        {
            make_pattern_insn(kLdxb, 1, 2, 0, 3, BPF_JIT_PATTERN_F_EXPECT_IMM,
                              0, 0, 0, 0),
            make_pattern_insn(kLsh64, 1, 0, 0, 0,
                              BPF_JIT_PATTERN_F_EXPECT_OFF |
                                  BPF_JIT_PATTERN_F_EXPECT_IMM,
                              0, 0, 0, 8),
            make_pattern_insn(kLdxb, 4, 2, 0, 5, BPF_JIT_PATTERN_F_EXPECT_IMM,
                              0, 0, 0, 0),
            make_pattern_insn(kOr64, 1, 4, 0, 0,
                              BPF_JIT_PATTERN_F_EXPECT_OFF |
                                  BPF_JIT_PATTERN_F_EXPECT_IMM,
                              0, 0, 0, 0),
        },
        {
            make_constraint(BPF_JIT_CSTR_DIFF_CONST, 3, 5, 1),
        },
        {
            make_var_binding(BPF_JIT_WMEM_PARAM_DST_REG, 1,
                             BPF_JIT_BIND_SOURCE_REG),
            make_var_binding(BPF_JIT_WMEM_PARAM_BASE_REG, 2,
                             BPF_JIT_BIND_SOURCE_REG),
            make_var_binding(BPF_JIT_WMEM_PARAM_BASE_OFF, 5,
                             BPF_JIT_BIND_SOURCE_IMM),
            make_const_binding(BPF_JIT_WMEM_PARAM_WIDTH, 2),
        }));

    return descs;
}

std::vector<V5PatternDesc> build_v5_rotate_descriptors(bool use_rorx)
{
    constexpr uint8_t kMov64X = 0xbf;
    constexpr uint8_t kMov32X = 0xbc;
    constexpr uint8_t kLsh64K = 0x67;
    constexpr uint8_t kLsh32K = 0x64;
    constexpr uint8_t kRsh64K = 0x77;
    constexpr uint8_t kRsh32K = 0x74;
    constexpr uint8_t kOr64X = 0x4f;
    constexpr uint8_t kOr32X = 0x4c;
    constexpr uint8_t kAnd64K = 0x57;
    constexpr uint8_t kAnd64X = 0x5f;
    const uint16_t native_choice = use_rorx ? BPF_JIT_ROT_RORX : BPF_JIT_ROT_ROR;
    const uint32_t cpu_features = use_rorx ? BPF_JIT_X86_BMI2 : 0;
    const uint8_t zero_off_imm = BPF_JIT_PATTERN_F_EXPECT_OFF |
                                 BPF_JIT_PATTERN_F_EXPECT_IMM;
    const uint8_t zero_off = BPF_JIT_PATTERN_F_EXPECT_OFF;

    auto rotate4 = [&](uint8_t mov, uint8_t lsh, uint8_t rsh, uint8_t ior,
                       int32_t width, bool commuted) {
        std::vector<V5PatternInsn> pattern;
        pattern.push_back(make_pattern_insn(mov, 1, 2, 0, 0, zero_off_imm,
                                            0, 0, 0, 0));
        if (commuted) {
            pattern.push_back(make_pattern_insn(rsh, 1, 0, 3, 0, zero_off,
                                                0, 0, 0, 0));
            pattern.push_back(make_pattern_insn(lsh, 2, 0, 4, 0, zero_off,
                                                0, 0, 0, 0));
        } else {
            pattern.push_back(make_pattern_insn(lsh, 2, 0, 4, 0, zero_off,
                                                0, 0, 0, 0));
            pattern.push_back(make_pattern_insn(rsh, 1, 0, 3, 0, zero_off,
                                                0, 0, 0, 0));
        }
        pattern.push_back(make_pattern_insn(ior, 2, 1, 0, 0, zero_off_imm,
                                            0, 0, 0, 0));

        return make_v5_desc(V5Family::Rotate, BPF_JIT_CF_ROTATE, native_choice,
                            cpu_features, std::move(pattern),
                            {
                                make_constraint(BPF_JIT_CSTR_SUM_CONST, 3, 4, width),
                                make_constraint(BPF_JIT_CSTR_IMM_RANGE, 4, 0,
                                                1, width - 1),
                                make_constraint(BPF_JIT_CSTR_NOT_EQUAL, 1, 2),
                            },
                            {
                                make_var_binding(BPF_JIT_ROT_PARAM_DST_REG, 2,
                                                 BPF_JIT_BIND_SOURCE_REG),
                                make_var_binding(BPF_JIT_ROT_PARAM_SRC_REG, 2,
                                                 BPF_JIT_BIND_SOURCE_REG),
                                make_var_binding(BPF_JIT_ROT_PARAM_AMOUNT, 4,
                                                 BPF_JIT_BIND_SOURCE_IMM),
                                make_const_binding(BPF_JIT_ROT_PARAM_WIDTH, width),
                            });
    };

    auto rotate5_two_copy = [&]() {
        return make_v5_desc(V5Family::Rotate, BPF_JIT_CF_ROTATE, native_choice,
                            cpu_features,
                            {
                                make_pattern_insn(kMov64X, 1, 2, 0, 0,
                                                  zero_off_imm, 0, 0, 0, 0),
                                make_pattern_insn(kRsh64K, 1, 0, 3, 0,
                                                  zero_off, 0, 0, 0, 0),
                                make_pattern_insn(kMov64X, 4, 2, 0, 0,
                                                  zero_off_imm, 0, 0, 0, 0),
                                make_pattern_insn(kLsh64K, 4, 0, 5, 0,
                                                  zero_off, 0, 0, 0, 0),
                                make_pattern_insn(kOr64X, 4, 1, 0, 0,
                                                  zero_off_imm, 0, 0, 0, 0),
                            },
                            {
                                make_constraint(BPF_JIT_CSTR_SUM_CONST, 3, 5, 64),
                                make_constraint(BPF_JIT_CSTR_IMM_RANGE, 5, 0, 1, 63),
                                make_constraint(BPF_JIT_CSTR_NOT_EQUAL, 1, 2),
                                make_constraint(BPF_JIT_CSTR_NOT_EQUAL, 1, 4),
                            },
                            {
                                make_var_binding(BPF_JIT_ROT_PARAM_DST_REG, 4,
                                                 BPF_JIT_BIND_SOURCE_REG),
                                make_var_binding(BPF_JIT_ROT_PARAM_SRC_REG, 2,
                                                 BPF_JIT_BIND_SOURCE_REG),
                                make_var_binding(BPF_JIT_ROT_PARAM_AMOUNT, 5,
                                                 BPF_JIT_BIND_SOURCE_IMM),
                                make_const_binding(BPF_JIT_ROT_PARAM_WIDTH, 64),
                            });
    };

    auto rotate5_masked = [&](uint8_t and_opcode, bool lsh_first) {
        std::vector<V5PatternInsn> pattern = {
            make_pattern_insn(kMov64X, 1, 2, 0, 0, zero_off_imm, 0, 0, 0, 0),
            make_pattern_insn(and_opcode, 1, and_opcode == kAnd64X ? 7 : 0,
                              and_opcode == kAnd64K ? 3 : 0, 0,
                              and_opcode == kAnd64X ? zero_off_imm : zero_off,
                              0, 0, 0, 0),
        };

        if (lsh_first) {
            pattern.push_back(make_pattern_insn(kLsh64K, 2, 0, 4, 0, zero_off,
                                                0, 0, 0, 0));
            pattern.push_back(make_pattern_insn(kRsh64K, 1, 0, 5, 0, zero_off,
                                                0, 0, 0, 0));
        } else {
            pattern.push_back(make_pattern_insn(kRsh64K, 1, 0, 5, 0, zero_off,
                                                0, 0, 0, 0));
            pattern.push_back(make_pattern_insn(kLsh64K, 2, 0, 4, 0, zero_off,
                                                0, 0, 0, 0));
        }
        pattern.push_back(make_pattern_insn(kOr64X, 2, 1, 0, 0, zero_off_imm,
                                            0, 0, 0, 0));

        std::vector<V5PatternConstraint> constraints = {
            make_constraint(BPF_JIT_CSTR_SUM_CONST, 4, 5, 32),
            make_constraint(BPF_JIT_CSTR_IMM_RANGE, 4, 0, 1, 31),
            make_constraint(BPF_JIT_CSTR_NOT_EQUAL, 1, 2),
        };
        if (and_opcode == kAnd64K) {
            constraints.push_back(make_constraint(BPF_JIT_CSTR_NOT_ZERO, 3));
        }

        return make_v5_desc(V5Family::Rotate, BPF_JIT_CF_ROTATE, native_choice,
                            cpu_features, std::move(pattern),
                            std::move(constraints),
                            {
                                make_var_binding(BPF_JIT_ROT_PARAM_DST_REG, 2,
                                                 BPF_JIT_BIND_SOURCE_REG),
                                make_var_binding(BPF_JIT_ROT_PARAM_SRC_REG, 2,
                                                 BPF_JIT_BIND_SOURCE_REG),
                                make_var_binding(BPF_JIT_ROT_PARAM_AMOUNT, 4,
                                                 BPF_JIT_BIND_SOURCE_IMM),
                                make_const_binding(BPF_JIT_ROT_PARAM_WIDTH, 32),
                            });
    };

    auto rotate6_masked = [&](uint8_t and_opcode) {
        std::vector<V5PatternInsn> pattern = {
            make_pattern_insn(kMov64X, 1, 2, 0, 0, zero_off_imm, 0, 0, 0, 0),
            make_pattern_insn(and_opcode, 1, and_opcode == kAnd64X ? 7 : 0,
                              and_opcode == kAnd64K ? 3 : 0, 0,
                              and_opcode == kAnd64X ? zero_off_imm : zero_off,
                              0, 0, 0, 0),
            make_pattern_insn(kRsh64K, 1, 0, 4, 0, zero_off, 0, 0, 0, 0),
            make_pattern_insn(kMov64X, 5, 2, 0, 0, zero_off_imm, 0, 0, 0, 0),
            make_pattern_insn(kLsh64K, 5, 0, 6, 0, zero_off, 0, 0, 0, 0),
            make_pattern_insn(kOr64X, 5, 1, 0, 0, zero_off_imm, 0, 0, 0, 0),
        };

        std::vector<V5PatternConstraint> constraints = {
            make_constraint(BPF_JIT_CSTR_SUM_CONST, 4, 6, 32),
            make_constraint(BPF_JIT_CSTR_IMM_RANGE, 6, 0, 1, 31),
            make_constraint(BPF_JIT_CSTR_NOT_EQUAL, 1, 2),
            make_constraint(BPF_JIT_CSTR_NOT_EQUAL, 1, 5),
        };
        if (and_opcode == kAnd64K) {
            constraints.push_back(make_constraint(BPF_JIT_CSTR_NOT_ZERO, 3));
        }

        return make_v5_desc(V5Family::Rotate, BPF_JIT_CF_ROTATE, native_choice,
                            cpu_features, std::move(pattern),
                            std::move(constraints),
                            {
                                make_var_binding(BPF_JIT_ROT_PARAM_DST_REG, 5,
                                                 BPF_JIT_BIND_SOURCE_REG),
                                make_var_binding(BPF_JIT_ROT_PARAM_SRC_REG, 2,
                                                 BPF_JIT_BIND_SOURCE_REG),
                                make_var_binding(BPF_JIT_ROT_PARAM_AMOUNT, 6,
                                                 BPF_JIT_BIND_SOURCE_IMM),
                                make_const_binding(BPF_JIT_ROT_PARAM_WIDTH, 32),
                            });
    };

    std::vector<V5PatternDesc> descs;
    descs.push_back(rotate6_masked(kAnd64X));
    descs.push_back(rotate6_masked(kAnd64K));
    descs.push_back(rotate5_masked(kAnd64X, false));
    descs.push_back(rotate5_masked(kAnd64K, false));
    descs.push_back(rotate5_masked(kAnd64X, true));
    descs.push_back(rotate5_masked(kAnd64K, true));
    descs.push_back(rotate5_two_copy());
    descs.push_back(rotate4(kMov64X, kLsh64K, kRsh64K, kOr64X, 64, true));
    descs.push_back(rotate4(kMov64X, kLsh64K, kRsh64K, kOr64X, 64, false));
    descs.push_back(rotate4(kMov32X, kLsh32K, kRsh32K, kOr32X, 32, true));
    descs.push_back(rotate4(kMov32X, kLsh32K, kRsh32K, kOr32X, 32, false));
    return descs;
}

std::vector<V5PatternDesc> build_v5_lea_descriptors()
{
    constexpr uint8_t kMov64X = 0xbf;
    constexpr uint8_t kLsh64K = 0x67;
    constexpr uint8_t kAdd64X = 0x0f;

    return {
        make_v5_desc(V5Family::AddrCalc, BPF_JIT_CF_ADDR_CALC,
                     BPF_JIT_ACALC_LEA, 0,
                     {
                         make_pattern_insn(kMov64X, 1, 2, 0, 0,
                                           BPF_JIT_PATTERN_F_EXPECT_OFF |
                                               BPF_JIT_PATTERN_F_EXPECT_IMM,
                                           0, 0, 0, 0),
                         make_pattern_insn(kLsh64K, 1, 0, 3, 0,
                                           BPF_JIT_PATTERN_F_EXPECT_OFF,
                                           0, 0, 0, 0),
                         make_pattern_insn(kAdd64X, 1, 4, 0, 0,
                                           BPF_JIT_PATTERN_F_EXPECT_OFF |
                                               BPF_JIT_PATTERN_F_EXPECT_IMM,
                                           0, 0, 0, 0),
                     },
                     {
                         make_constraint(BPF_JIT_CSTR_IMM_RANGE, 3, 0, 1, 3),
                     },
                     {
                         make_var_binding(BPF_JIT_ACALC_PARAM_DST_REG, 1,
                                          BPF_JIT_BIND_SOURCE_REG),
                         make_var_binding(BPF_JIT_ACALC_PARAM_BASE_REG, 4,
                                          BPF_JIT_BIND_SOURCE_REG),
                         make_var_binding(BPF_JIT_ACALC_PARAM_INDEX_REG, 2,
                                          BPF_JIT_BIND_SOURCE_REG),
                         make_var_binding(BPF_JIT_ACALC_PARAM_SCALE, 3,
                                          BPF_JIT_BIND_SOURCE_IMM),
                     }),
    };
}

std::vector<V5PatternDesc> build_v5_bitfield_extract_descriptors()
{
    constexpr uint8_t kMov64X = 0xbf;
    constexpr uint8_t kMov32X = 0xbc;
    constexpr uint8_t kRsh64K = 0x77;
    constexpr uint8_t kRsh32K = 0x74;
    constexpr uint8_t kAnd64K = 0x57;
    constexpr uint8_t kAnd32K = 0x54;
    constexpr uint8_t kExpectZeroOff = BPF_JIT_PATTERN_F_EXPECT_OFF;
    constexpr uint8_t kExpectZeroOffImm = BPF_JIT_PATTERN_F_EXPECT_OFF |
                                          BPF_JIT_PATTERN_F_EXPECT_IMM;

    auto build_extract_desc = [&](bool with_copy,
                                  bool mask_first,
                                  uint8_t mov_opcode,
                                  uint8_t rsh_opcode,
                                  uint8_t and_opcode,
                                  int32_t width) {
        std::vector<V5PatternInsn> pattern;
        std::vector<V5PatternConstraint> constraints;
        std::vector<V5Binding> bindings;
        uint8_t shift_var;
        uint8_t mask_var;

        if (with_copy) {
            pattern.push_back(make_pattern_insn(mov_opcode, 1, 2, 0, 0,
                                                kExpectZeroOffImm, 0, 0, 0, 0));
            if (mask_first) {
                pattern.push_back(make_pattern_insn(and_opcode, 1, 0, 3, 0,
                                                    kExpectZeroOff, 0, 0, 0, 0));
                pattern.push_back(make_pattern_insn(rsh_opcode, 1, 0, 4, 0,
                                                    kExpectZeroOff, 0, 0, 0, 0));
                mask_var = 3;
                shift_var = 4;
            } else {
                pattern.push_back(make_pattern_insn(rsh_opcode, 1, 0, 3, 0,
                                                    kExpectZeroOff, 0, 0, 0, 0));
                pattern.push_back(make_pattern_insn(and_opcode, 1, 0, 4, 0,
                                                    kExpectZeroOff, 0, 0, 0, 0));
                shift_var = 3;
                mask_var = 4;
            }
            bindings = {
                make_var_binding(BPF_JIT_BFX_PARAM_DST_REG, 1,
                                 BPF_JIT_BIND_SOURCE_REG),
                make_var_binding(BPF_JIT_BFX_PARAM_SRC_REG, 2,
                                 BPF_JIT_BIND_SOURCE_REG),
                make_var_binding(BPF_JIT_BFX_PARAM_SHIFT, shift_var,
                                 BPF_JIT_BIND_SOURCE_IMM),
                make_var_binding(BPF_JIT_BFX_PARAM_MASK, mask_var,
                                 BPF_JIT_BIND_SOURCE_IMM),
                make_const_binding(BPF_JIT_BFX_PARAM_WIDTH, width),
                make_const_binding(BPF_JIT_BFX_PARAM_ORDER,
                                   mask_first ? BPF_JIT_BFX_ORDER_MASK_SHIFT
                                              : BPF_JIT_BFX_ORDER_SHIFT_MASK),
            };
        } else {
            if (mask_first) {
                pattern.push_back(make_pattern_insn(and_opcode, 1, 0, 2, 0,
                                                    kExpectZeroOff, 0, 0, 0, 0));
                pattern.push_back(make_pattern_insn(rsh_opcode, 1, 0, 3, 0,
                                                    kExpectZeroOff, 0, 0, 0, 0));
                mask_var = 2;
                shift_var = 3;
            } else {
                pattern.push_back(make_pattern_insn(rsh_opcode, 1, 0, 2, 0,
                                                    kExpectZeroOff, 0, 0, 0, 0));
                pattern.push_back(make_pattern_insn(and_opcode, 1, 0, 3, 0,
                                                    kExpectZeroOff, 0, 0, 0, 0));
                shift_var = 2;
                mask_var = 3;
            }
            bindings = {
                make_var_binding(BPF_JIT_BFX_PARAM_DST_REG, 1,
                                 BPF_JIT_BIND_SOURCE_REG),
                make_var_binding(BPF_JIT_BFX_PARAM_SRC_REG, 1,
                                 BPF_JIT_BIND_SOURCE_REG),
                make_var_binding(BPF_JIT_BFX_PARAM_SHIFT, shift_var,
                                 BPF_JIT_BIND_SOURCE_IMM),
                make_var_binding(BPF_JIT_BFX_PARAM_MASK, mask_var,
                                 BPF_JIT_BIND_SOURCE_IMM),
                make_const_binding(BPF_JIT_BFX_PARAM_WIDTH, width),
                make_const_binding(BPF_JIT_BFX_PARAM_ORDER,
                                   mask_first ? BPF_JIT_BFX_ORDER_MASK_SHIFT
                                              : BPF_JIT_BFX_ORDER_SHIFT_MASK),
            };
        }

        constraints.push_back(make_constraint(BPF_JIT_CSTR_IMM_RANGE, shift_var, 0,
                                              0, width - 1));

        return make_v5_desc(V5Family::BitfieldExtract,
                            BPF_JIT_CF_BITFIELD_EXTRACT,
                            BPF_JIT_BFX_EXTRACT,
                            0,
                            std::move(pattern),
                            std::move(constraints),
                            std::move(bindings));
    };

    std::vector<V5PatternDesc> descs;
    descs.reserve(8);
    descs.push_back(build_extract_desc(true, false, kMov64X, kRsh64K, kAnd64K, 64));
    descs.push_back(build_extract_desc(true, true,  kMov64X, kRsh64K, kAnd64K, 64));
    descs.push_back(build_extract_desc(false, false, kMov64X, kRsh64K, kAnd64K, 64));
    descs.push_back(build_extract_desc(false, true,  kMov64X, kRsh64K, kAnd64K, 64));
    descs.push_back(build_extract_desc(true, false, kMov32X, kRsh32K, kAnd32K, 32));
    descs.push_back(build_extract_desc(true, true,  kMov32X, kRsh32K, kAnd32K, 32));
    descs.push_back(build_extract_desc(false, false, kMov32X, kRsh32K, kAnd32K, 32));
    descs.push_back(build_extract_desc(false, true,  kMov32X, kRsh32K, kAnd32K, 32));
    return descs;
}

V5ScanSummary scan_v5_builtin(const uint8_t *xlated_data,
                              uint32_t xlated_len,
                              const V5ScanOptions &options)
{
    V5ScanSummary summary;

    if (!xlated_data || xlated_len % sizeof(bpf_insn_raw) != 0) {
        return summary;
    }

    std::vector<V5PatternDesc> descs;
    if (options.scan_cmov) {
        auto cmov_descs = build_v5_cond_select_descriptors();
        descs.insert(descs.end(), cmov_descs.begin(), cmov_descs.end());
    }
    if (options.scan_wide) {
        auto wide_descs = build_v5_wide_descriptors();
        descs.insert(descs.end(), wide_descs.begin(), wide_descs.end());
    }
    if (options.scan_rotate) {
        auto rotate_descs = build_v5_rotate_descriptors(options.use_rorx);
        descs.insert(descs.end(), rotate_descs.begin(), rotate_descs.end());
    }
    if (options.scan_lea) {
        auto lea_descs = build_v5_lea_descriptors();
        descs.insert(descs.end(), lea_descs.begin(), lea_descs.end());
    }
    if (options.scan_extract) {
        auto extract_descs = build_v5_bitfield_extract_descriptors();
        descs.insert(descs.end(), extract_descs.begin(), extract_descs.end());
    }

    if (descs.empty()) {
        return summary;
    }

    const auto insns = parse_xlated_insns(xlated_data, xlated_len);
    for (uint32_t idx = 0; idx < insns.size();) {
        bool matched = false;

        for (const auto &desc : descs) {
            if (!match_v5_pattern_at(insns, idx, desc)) {
                continue;
            }

            summary.rules.push_back(make_v5_policy_rule(idx, desc));
            switch (desc.family) {
            case V5Family::Cmov:
                summary.cmov_sites++;
                break;
            case V5Family::WideMem:
                summary.wide_sites++;
                break;
            case V5Family::Rotate:
                summary.rotate_sites++;
                break;
            case V5Family::AddrCalc:
                summary.lea_sites++;
                break;
            case V5Family::BitfieldExtract:
                summary.bitfield_sites++;
                break;
            }

            idx += static_cast<uint32_t>(desc.pattern.size());
            matched = true;
            break;
        }

        if (!matched) {
            ++idx;
        }
    }

    return summary;
}

std::vector<uint8_t> build_policy_blob_v5(uint32_t insn_cnt,
                                          const uint8_t prog_tag[8],
                                          const std::vector<V5PolicyRule> &rules)
{
    struct __attribute__((packed)) policy_hdr_v5 {
        uint32_t magic;
        uint16_t version;
        uint16_t hdr_len;
        uint32_t total_len;
        uint32_t rule_cnt;
        uint32_t insn_cnt;
        uint8_t prog_tag[8];
        uint16_t arch_id;
        uint16_t flags;
    } hdr = {};

    uint32_t total_len = sizeof(hdr);
    for (const auto &rule : rules) {
        total_len += static_cast<uint32_t>(sizeof(V5RuleWire) +
            rule.pattern.size() * sizeof(V5PatternInsn) +
            rule.constraints.size() * sizeof(V5PatternConstraint) +
            rule.bindings.size() * sizeof(V5Binding));
    }

    hdr.magic = BPF_JIT_POLICY_MAGIC;
    hdr.version = BPF_JIT_POLICY_VERSION_2;
    hdr.hdr_len = sizeof(hdr);
    hdr.total_len = total_len;
    hdr.rule_cnt = static_cast<uint32_t>(rules.size());
    hdr.insn_cnt = insn_cnt;
    if (prog_tag != nullptr) {
        std::memcpy(hdr.prog_tag, prog_tag, sizeof(hdr.prog_tag));
    }
    hdr.arch_id = BPF_JIT_ARCH_X86_64;
    hdr.flags = 0;

    std::vector<uint8_t> blob;
    blob.reserve(total_len);
    append_blob_bytes(blob, &hdr, sizeof(hdr));

    for (const auto &rule : rules) {
        V5RuleWire wire_rule = {};
        wire_rule.site_start = rule.site_start;
        wire_rule.cpu_features_required = rule.cpu_features_required;
        wire_rule.site_len = static_cast<uint16_t>(rule.pattern.size());
        wire_rule.rule_kind = BPF_JIT_RK_PATTERN;
        wire_rule.canonical_form = rule.canonical_form;
        wire_rule.native_choice = rule.native_choice;
        wire_rule.priority = rule.priority;
        wire_rule.pattern_count = static_cast<uint16_t>(rule.pattern.size());
        wire_rule.constraint_count = static_cast<uint16_t>(rule.constraints.size());
        wire_rule.binding_count = static_cast<uint16_t>(rule.bindings.size());
        wire_rule.rule_len = static_cast<uint16_t>(sizeof(wire_rule) +
            rule.pattern.size() * sizeof(V5PatternInsn) +
            rule.constraints.size() * sizeof(V5PatternConstraint) +
            rule.bindings.size() * sizeof(V5Binding));

        append_blob_bytes(blob, &wire_rule, sizeof(wire_rule));
        if (!rule.pattern.empty()) {
            append_blob_bytes(blob, rule.pattern.data(),
                              rule.pattern.size() * sizeof(V5PatternInsn));
        }
        if (!rule.constraints.empty()) {
            append_blob_bytes(blob, rule.constraints.data(),
                              rule.constraints.size() * sizeof(V5PatternConstraint));
        }
        if (!rule.bindings.empty()) {
            append_blob_bytes(blob, rule.bindings.data(),
                              rule.bindings.size() * sizeof(V5Binding));
        }
    }

    return blob;
}

} // namespace bpf_jit_scanner
