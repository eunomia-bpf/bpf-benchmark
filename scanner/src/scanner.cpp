// SPDX-License-Identifier: MIT
//
// scanner.cpp — BPF JIT policy scanner implementation
//
// scanner.cpp is the authoritative home of the userspace pattern-matching
// logic. Consumers such as micro/runner should call the exported C API rather
// than carrying private copies of these matchers.

#include "bpf_jit_scanner/scanner.h"

#include <cerrno>
#include <cstdio>
#include <cstring>
#include <vector>

// ---------------------------------------------------------------------------
// Internal helpers
// ---------------------------------------------------------------------------

namespace {

constexpr uint8_t BPF_CLASS_MASK = 0x07;
constexpr uint8_t BPF_JMP        = 0x05;
constexpr uint8_t BPF_JMP32      = 0x06;
constexpr uint8_t BPF_ALU        = 0x04;
constexpr uint8_t BPF_ALU64      = 0x07;
constexpr uint8_t BPF_SRC_X      = 0x08;
constexpr uint8_t BPF_MOV_OP     = 0xb0;
constexpr uint8_t BPF_END_OP     = 0xd0;
constexpr uint8_t BPF_JA_CODE    = 0x05;

// Raw 8-byte BPF instruction layout (little-endian host).
struct bpf_insn_raw {
    uint8_t  code;
    uint8_t  regs;  // dst_reg = regs & 0x0f, src_reg = (regs >> 4) & 0x0f
    int16_t  off;
    int32_t  imm;
};

struct wide_mem_match_raw {
    bool matched = false;
    bool big_endian = false;
    uint32_t site_len = 0;
    uint8_t dst_reg = 0;
    uint8_t base_reg = 0;
    int16_t base_off = 0;
    uint8_t width = 0;
};

constexpr uint8_t raw_dst_reg(const bpf_insn_raw &insn)
{
    return insn.regs & 0x0f;
}

constexpr uint8_t raw_src_reg(const bpf_insn_raw &insn)
{
    return static_cast<uint8_t>((insn.regs >> 4) & 0x0f);
}

static void parse_insns(const uint8_t *data, uint32_t byte_len,
                        std::vector<bpf_insn_raw> &insns)
{
    uint32_t cnt = byte_len / 8;
    insns.resize(cnt);
    for (uint32_t i = 0; i < cnt; i++) {
        std::memcpy(&insns[i], data + i * 8, 8);
    }
}

// Returns true when insn is a conditional jump (any variant of BPF_JMP / BPF_JMP32).
static bool is_cond_jump_raw(const bpf_insn_raw &insn)
{
    uint8_t cls = insn.code & BPF_CLASS_MASK;
    if (cls != BPF_JMP && cls != BPF_JMP32)
        return false;
    uint8_t op = insn.code & 0xf0;
    switch (op) {
    case 0x10: case 0x20: case 0x30: case 0x40: case 0x50: case 0x60:
    case 0x70: case 0xa0: case 0xb0: case 0xc0: case 0xd0:
        return true;
    default:
        return false;
    }
}

static bool is_uncond_ja_raw(const bpf_insn_raw &insn)
{
    return insn.code == BPF_JA_CODE && raw_dst_reg(insn) == 0 &&
           raw_src_reg(insn) == 0 && insn.imm == 0;
}

static bool is_pure_value_op_raw(const bpf_insn_raw &insn)
{
    const uint8_t cls = insn.code & BPF_CLASS_MASK;
    if (cls != BPF_ALU && cls != BPF_ALU64)
        return false;
    if (insn.off != 0)
        return false;
    if ((insn.code & 0xf0) == BPF_END_OP)
        return false;

    const uint8_t src = insn.code & BPF_SRC_X;
    if (src == BPF_SRC_X)
        return insn.imm == 0;
    return raw_src_reg(insn) == 0;
}

static bool targets_same(uint32_t from_a, int16_t off_a,
                         uint32_t from_b, int16_t off_b)
{
    return static_cast<int64_t>(from_a) + 1 + off_a ==
           static_cast<int64_t>(from_b) + 1 + off_b;
}

// Returns true when insn is a register or immediate MOV with no side effects.
static bool is_simple_mov_raw(const bpf_insn_raw &insn)
{
    uint8_t cls = insn.code & BPF_CLASS_MASK;
    if (cls != BPF_ALU && cls != BPF_ALU64)
        return false;
    if ((insn.code & 0xf0) != BPF_MOV_OP)
        return false;
    if (insn.off != 0)
        return false;
    uint8_t src = insn.code & BPF_SRC_X;
    if (src == BPF_SRC_X)
        return insn.imm == 0;
    return raw_src_reg(insn) == 0;
}

static bool match_value_arm(const std::vector<bpf_insn_raw> &insns,
                            uint32_t start, uint32_t arm_len,
                            uint8_t dst_reg)
{
    if (arm_len == 0 || start + arm_len > insns.size())
        return false;
    if (!is_simple_mov_raw(insns[start + arm_len - 1]) ||
        raw_dst_reg(insns[start + arm_len - 1]) != dst_reg)
        return false;

    for (uint32_t i = start; i + 1 < start + arm_len; ++i) {
        if (!is_pure_value_op_raw(insns[i]) || raw_dst_reg(insns[i]) == dst_reg)
            return false;
    }
    return true;
}

// Append a rule to the output buffer.  Returns false if buffer is full.
static bool emit_rule(struct bpf_jit_scan_rule *rules, uint32_t max_rules,
                      uint32_t &count,
                      uint32_t site_start, uint32_t site_len,
                      uint32_t rule_kind, uint32_t native_choice,
                      uint32_t cpu_feat, uint32_t priority = 0)
{
    if (count >= max_rules)
        return false;
    rules[count].site_start            = site_start;
    rules[count].site_len              = site_len;
    rules[count].rule_kind             = rule_kind;
    rules[count].native_choice         = native_choice;
    rules[count].cpu_features_required = cpu_feat;
    rules[count].priority              = priority;
    count++;
    return true;
}

} // namespace

// ---------------------------------------------------------------------------
// bpf_jit_scan_cmov
// ---------------------------------------------------------------------------

int bpf_jit_scan_cmov(const uint8_t *xlated, uint32_t len,
                      struct bpf_jit_scan_rule *rules, uint32_t max_rules)
{
    if (!xlated || len % 8 != 0)
        return -EINVAL;

    std::vector<bpf_insn_raw> insns;
    parse_insns(xlated, len, insns);
    uint32_t insn_cnt = static_cast<uint32_t>(insns.size());

    if (insn_cnt < 3)
        return 0;

    uint32_t count = 0;
    uint32_t idx   = 0;

    while (idx < insn_cnt) {
        // Switch-style two-case chain:
        //   mov false
        //   guard-jcc -> join
        //   select-jcc +1
        //   ja else/default
        //   mov true
        //   ja join
        if (idx + 5 < insn_cnt &&
            is_simple_mov_raw(insns[idx]) &&
            is_cond_jump_raw(insns[idx + 1]) &&
            is_cond_jump_raw(insns[idx + 2]) && insns[idx + 2].off == 1 &&
            is_uncond_ja_raw(insns[idx + 3]) &&
            is_simple_mov_raw(insns[idx + 4]) &&
            is_uncond_ja_raw(insns[idx + 5]) &&
            raw_dst_reg(insns[idx]) == raw_dst_reg(insns[idx + 4]) &&
            (insns[idx + 1].code & 0xf8) == (insns[idx + 2].code & 0xf8) &&
            raw_dst_reg(insns[idx + 1]) == raw_dst_reg(insns[idx + 2]) &&
            ((insns[idx + 1].code & BPF_SRC_X) ==
             (insns[idx + 2].code & BPF_SRC_X)) &&
            targets_same(idx + 1, insns[idx + 1].off,
                         idx + 5, insns[idx + 5].off))
        {
            if (!emit_rule(rules, max_rules, count,
                           idx, 6, BPF_JIT_RK_COND_SELECT, BPF_JIT_SEL_CMOVCC, 0))
                return -ENOBUFS;
            idx += 6;
            continue;
        }

        // Generalized diamond: jcc+(2..4), [pure value prep]*, mov, ja+1, mov.
        if (is_cond_jump_raw(insns[idx]) &&
            insns[idx].off >= 2 && insns[idx].off <= 4) {
            const uint32_t false_arm_len = static_cast<uint32_t>(insns[idx].off - 1);
            const uint32_t ja_idx = idx + false_arm_len + 1;
            const uint32_t true_idx = ja_idx + 1;

            if (true_idx < insn_cnt &&
                match_value_arm(insns, idx + 1, false_arm_len,
                                raw_dst_reg(insns[idx + false_arm_len])) &&
                is_uncond_ja_raw(insns[ja_idx]) && insns[ja_idx].off == 1 &&
                is_simple_mov_raw(insns[true_idx]) &&
                raw_dst_reg(insns[idx + false_arm_len]) ==
                    raw_dst_reg(insns[true_idx]))
            {
                if (!emit_rule(rules, max_rules, count,
                               idx, false_arm_len + 3,
                               BPF_JIT_RK_COND_SELECT, BPF_JIT_SEL_CMOVCC, 0))
                    return -ENOBUFS;
                idx += false_arm_len + 3;
                continue;
            }
        }

        // Branch-guarded update with shared join:
        //   jcc -> join
        //   [pure value prep]*, mov dst, val
        //   ja -> join
        for (uint32_t arm_len = 1; arm_len <= 3; ++arm_len) {
            const uint32_t mov_idx = idx + arm_len;
            const uint32_t ja_idx = mov_idx + 1;

            if (ja_idx >= insn_cnt || !is_cond_jump_raw(insns[idx]) ||
                !is_uncond_ja_raw(insns[ja_idx]) ||
                !is_simple_mov_raw(insns[mov_idx])) {
                continue;
            }

            const uint8_t dst_reg = raw_dst_reg(insns[mov_idx]);
            if (!match_value_arm(insns, idx + 1, arm_len, dst_reg) ||
                !targets_same(idx, insns[idx].off, ja_idx, insns[ja_idx].off)) {
                continue;
            }

            if (!emit_rule(rules, max_rules, count,
                           idx, arm_len + 2,
                           BPF_JIT_RK_COND_SELECT, BPF_JIT_SEL_CMOVCC, 0))
                return -ENOBUFS;
            idx += arm_len + 2;
            goto matched_site;
        }

        // Forward guarded update:
        //   jcc +N
        //   [pure value prep]*, mov dst, val
        for (uint32_t arm_len = 1; arm_len <= 3; ++arm_len) {
            if (idx + arm_len >= insn_cnt || !is_cond_jump_raw(insns[idx]) ||
                insns[idx].off != static_cast<int16_t>(arm_len)) {
                continue;
            }

            const uint8_t dst_reg = raw_dst_reg(insns[idx + arm_len]);
            if (!match_value_arm(insns, idx + 1, arm_len, dst_reg)) {
                continue;
            }

            if (!emit_rule(rules, max_rules, count,
                           idx, arm_len + 1,
                           BPF_JIT_RK_COND_SELECT, BPF_JIT_SEL_CMOVCC, 0))
                return -ENOBUFS;
            idx += arm_len + 1;
            goto matched_site;
        }

        // Compact: mov, jcc+1, mov  (3 insns — anchored at the jcc)
        if (idx > 0 && idx + 1 < insn_cnt &&
            is_simple_mov_raw(insns[idx - 1]) &&
            is_cond_jump_raw(insns[idx]) && insns[idx].off == 1 &&
            is_simple_mov_raw(insns[idx + 1]) &&
            raw_dst_reg(insns[idx - 1]) == raw_dst_reg(insns[idx + 1]))
        {
            if (!emit_rule(rules, max_rules, count,
                           idx - 1, 3, BPF_JIT_RK_COND_SELECT, BPF_JIT_SEL_CMOVCC, 0))
                return -ENOBUFS;
            idx += 2;
            continue;
        }

        idx++;
matched_site:
        continue;
    }

    return static_cast<int>(count);
}

// ---------------------------------------------------------------------------
// bpf_jit_scan_wide_mem
// ---------------------------------------------------------------------------

int bpf_jit_scan_wide_mem(const uint8_t *xlated, uint32_t len,
                          struct bpf_jit_scan_rule *rules, uint32_t max_rules)
{
    if (!xlated || len % 8 != 0)
        return -EINVAL;

    std::vector<bpf_insn_raw> insns;
    parse_insns(xlated, len, insns);
    uint32_t insn_cnt = static_cast<uint32_t>(insns.size());

    if (insn_cnt < 4)
        return 0;

    constexpr uint8_t LDXB_CODE  = 0x71; // BPF_LDX | BPF_MEM | BPF_B
    constexpr uint8_t LSH64_CODE = 0x67; // BPF_ALU64 | BPF_LSH | BPF_K
    constexpr uint8_t OR64_CODE  = 0x4f; // BPF_ALU64 | BPF_OR  | BPF_X

    uint32_t count = 0;
    uint32_t idx   = 0;

    while (idx < insn_cnt) {
        if (insns[idx].code != LDXB_CODE) {
            idx++;
            continue;
        }

        uint8_t base_reg = (insns[idx].regs >> 4) & 0x0f;
        int16_t base_off =  insns[idx].off;
        uint8_t dst_reg  =  insns[idx].regs & 0x0f;

        // High-byte-first 2-byte pattern (clang):
        //   [0] ldxb tmp, [base+off+1]    (high byte — the first load IS the high byte)
        //   [1] lsh64 tmp, 8
        //   [2] ldxb dst2, [base+off]     (low byte — offset is base_off - 1)
        //   [3] or64 tmp, dst2
        if (idx + 3 < insn_cnt) {
            const auto &shift_insn = insns[idx + 1];
            const auto &lo_load    = insns[idx + 2];
            const auto &or_insn    = insns[idx + 3];

            if (shift_insn.code == LSH64_CODE &&
                shift_insn.imm == 8 &&
                (shift_insn.regs & 0x0f) == dst_reg &&
                lo_load.code == LDXB_CODE &&
                ((lo_load.regs >> 4) & 0x0f) == base_reg &&
                lo_load.off == base_off - 1 &&
                or_insn.code == OR64_CODE &&
                (or_insn.regs & 0x0f) == dst_reg &&
                ((or_insn.regs >> 4) & 0x0f) == (lo_load.regs & 0x0f))
            {
                if (!emit_rule(rules, max_rules, count,
                               idx, 4, BPF_JIT_RK_WIDE_MEM, BPF_JIT_WMEM_WIDE_LOAD, 0))
                    return -ENOBUFS;
                idx += 4;
                continue;
            }
        }

        // Low-byte-first pattern (generic):
        //   [0]           ldxb dst,  [base+off]
        //   [1]           ldxb tmp,  [base+off+1]
        //   [2]           lsh64 tmp, 8
        //   [3]           or64  dst, tmp
        //   [4]           ldxb tmp,  [base+off+2]
        //   [5]           lsh64 tmp, 16
        //   [6]           or64  dst, tmp
        //   ...
        uint32_t n_extra = 0;
        while (idx + 1 + n_extra * 3 + 2 < insn_cnt) {
            uint32_t g = idx + 1 + n_extra * 3;
            const auto &load_insn  = insns[g];
            const auto &shift_insn = insns[g + 1];
            const auto &or_insn    = insns[g + 2];

            uint8_t load_src  = (load_insn.regs >> 4) & 0x0f;
            uint8_t load_dst  =  load_insn.regs & 0x0f;
            uint8_t shift_dst =  shift_insn.regs & 0x0f;
            uint8_t or_dst    =  or_insn.regs & 0x0f;
            uint8_t or_src    = (or_insn.regs >> 4) & 0x0f;

            if (load_insn.code != LDXB_CODE) break;
            if (load_src != base_reg) break;
            if (load_insn.off != base_off + static_cast<int16_t>(n_extra + 1)) break;
            if (shift_insn.code != LSH64_CODE) break;
            if (shift_dst != load_dst) break;
            if (shift_insn.imm != static_cast<int32_t>((n_extra + 1) * 8)) break;
            if (or_insn.code != OR64_CODE) break;
            if (or_dst != dst_reg) break;
            if (or_src != load_dst) break;

            n_extra++;
            if (n_extra == 7) break; // max 8 bytes total
        }

        if (n_extra == 0) {
            idx++;
            continue;
        }

        uint32_t total_bytes = n_extra + 1;
        if (total_bytes == 2 || total_bytes == 4 || total_bytes == 8) {
            uint32_t site_len = 1 + n_extra * 3;
            if (!emit_rule(rules, max_rules, count,
                           idx, site_len, BPF_JIT_RK_WIDE_MEM, BPF_JIT_WMEM_WIDE_LOAD, 0))
                return -ENOBUFS;
            idx += site_len;
        } else {
            idx++; // unsupported width — skip first insn and retry
        }
    }

    return static_cast<int>(count);
}

// ---------------------------------------------------------------------------
// bpf_jit_scan_rotate
// ---------------------------------------------------------------------------

int bpf_jit_scan_rotate(const uint8_t *xlated, uint32_t len,
                        bool use_rorx,
                        struct bpf_jit_scan_rule *rules, uint32_t max_rules)
{
    if (!xlated || len % 8 != 0)
        return -EINVAL;

    std::vector<bpf_insn_raw> insns;
    parse_insns(xlated, len, insns);
    uint32_t insn_cnt = static_cast<uint32_t>(insns.size());

    if (insn_cnt < 4)
        return 0;

    constexpr uint8_t MOV64_X = 0xbf; // BPF_ALU64 | BPF_MOV | BPF_X
    constexpr uint8_t MOV32_X = 0xbc; // BPF_ALU   | BPF_MOV | BPF_X
    constexpr uint8_t LSH64_K = 0x67; // BPF_ALU64 | BPF_LSH | BPF_K
    constexpr uint8_t LSH32_K = 0x64; // BPF_ALU   | BPF_LSH | BPF_K
    constexpr uint8_t RSH64_K = 0x77; // BPF_ALU64 | BPF_RSH | BPF_K
    constexpr uint8_t RSH32_K = 0x74; // BPF_ALU   | BPF_RSH | BPF_K
    constexpr uint8_t OR64_X  = 0x4f; // BPF_ALU64 | BPF_OR  | BPF_X
    constexpr uint8_t OR32_X  = 0x4c; // BPF_ALU   | BPF_OR  | BPF_X
    constexpr uint8_t AND64_K = 0x57; // BPF_ALU64 | BPF_AND | BPF_K
    constexpr uint8_t AND64_X = 0x5f; // BPF_ALU64 | BPF_AND | BPF_X

    uint16_t native_choice = use_rorx ? BPF_JIT_ROT_RORX : BPF_JIT_ROT_ROR;
    uint32_t cpu_feat      = use_rorx ? BPF_JIT_X86_BMI2  : 0;

    uint32_t count = 0;

    for (uint32_t idx = 0; idx < insn_cnt; idx++) {

        // ----------------------------------------------------------------
        // 6-insn masked 32-bit rotate (most specific — check first)
        //   [0] mov64 tmp, src
        //   [1] and64 tmp, mask   (AND64_K or AND64_X)
        //   [2] rsh64 tmp, (32-N)
        //   [3] mov64 dst, src
        //   [4] lsh64 dst, N
        //   [5] or64  dst, tmp
        // ----------------------------------------------------------------
        if (idx + 5 < insn_cnt) {
            const auto &mov1  = insns[idx];
            const auto &and_i = insns[idx + 1];
            const auto &rsh   = insns[idx + 2];
            const auto &mov2  = insns[idx + 3];
            const auto &lsh   = insns[idx + 4];
            const auto &ior   = insns[idx + 5];

            bool and_ok = (and_i.code == AND64_K && and_i.imm != 0) ||
                          (and_i.code == AND64_X);

            if (mov1.code == MOV64_X && mov1.off == 0 && mov1.imm == 0 &&
                and_ok &&
                rsh.code  == RSH64_K &&
                mov2.code == MOV64_X && mov2.off == 0 && mov2.imm == 0 &&
                lsh.code  == LSH64_K &&
                ior.code  == OR64_X)
            {
                uint8_t tmp_reg  = mov1.regs & 0x0f;
                uint8_t src_reg1 = (mov1.regs >> 4) & 0x0f;
                uint8_t src_reg2 = (mov2.regs >> 4) & 0x0f;
                uint8_t dst_reg  = mov2.regs & 0x0f;

                if (src_reg1 == src_reg2 &&
                    (and_i.regs & 0x0f) == tmp_reg &&
                    (rsh.regs   & 0x0f) == tmp_reg &&
                    (lsh.regs   & 0x0f) == dst_reg &&
                    (ior.regs   & 0x0f) == dst_reg &&
                    ((ior.regs >> 4) & 0x0f) == tmp_reg)
                {
                    int32_t rot_amount = lsh.imm;
                    int32_t rsh_amount = rsh.imm;
                    if (rot_amount > 0 && rot_amount < 32 &&
                        rsh_amount > 0 && rsh_amount < 32 &&
                        rot_amount + rsh_amount == 32)
                    {
                        if (!emit_rule(rules, max_rules, count,
                                       idx, 6, BPF_JIT_RK_ROTATE, native_choice, cpu_feat))
                            return -ENOBUFS;
                        idx += 5; // loop will increment once more
                        goto next_iter;
                    }
                }
            }
        }

        // ----------------------------------------------------------------
        // 5-insn masked 32-bit rotate (no second mov):
        //   [0] mov64 tmp, src
        //   [1] and64 tmp, mask
        //   [2] rsh64 tmp, (32-N)  -- or lsh first; both orderings allowed
        //   [3] lsh64 src, N
        //   [4] or64  src, tmp
        // ----------------------------------------------------------------
        if (idx + 4 < insn_cnt) {
            const auto &mov_i = insns[idx];
            const auto &and_i = insns[idx + 1];
            const auto &insn2 = insns[idx + 2];
            const auto &insn3 = insns[idx + 3];
            const auto &ior   = insns[idx + 4];

            bool and_ok = (and_i.code == AND64_K) || (and_i.code == AND64_X);

            if (mov_i.code == MOV64_X && mov_i.off == 0 && mov_i.imm == 0 &&
                and_ok && ior.code == OR64_X)
            {
                uint8_t tmp_reg = mov_i.regs & 0x0f;
                uint8_t src_reg = (mov_i.regs >> 4) & 0x0f;

                const bpf_insn_raw *lsh_p = nullptr;
                const bpf_insn_raw *rsh_p = nullptr;
                if (insn2.code == RSH64_K && insn3.code == LSH64_K) {
                    rsh_p = &insn2; lsh_p = &insn3;
                } else if (insn2.code == LSH64_K && insn3.code == RSH64_K) {
                    lsh_p = &insn2; rsh_p = &insn3;
                }

                if (lsh_p && rsh_p &&
                    (and_i.regs & 0x0f) == tmp_reg &&
                    (rsh_p->regs & 0x0f) == tmp_reg &&
                    (lsh_p->regs & 0x0f) == src_reg &&
                    (ior.regs & 0x0f) == src_reg &&
                    ((ior.regs >> 4) & 0x0f) == tmp_reg)
                {
                    int32_t rot_amount = lsh_p->imm;
                    int32_t rsh_amount = rsh_p->imm;
                    if (rot_amount > 0 && rot_amount < 32 &&
                        rsh_amount > 0 && rsh_amount < 32 &&
                        rot_amount + rsh_amount == 32)
                    {
                        if (!emit_rule(rules, max_rules, count,
                                       idx, 5, BPF_JIT_RK_ROTATE, native_choice, cpu_feat))
                            return -ENOBUFS;
                        idx += 4;
                        goto next_iter;
                    }
                }
            }
        }

        // ----------------------------------------------------------------
        // 5-insn 64-bit two-copy rotate:
        //   [0] mov64 tmp, src
        //   [1] rsh64 tmp, (64-N)
        //   [2] mov64 dst, src
        //   [3] lsh64 dst, N
        //   [4] or64  dst, tmp
        // ----------------------------------------------------------------
        if (idx + 4 < insn_cnt) {
            const auto &mov1 = insns[idx];
            const auto &rsh  = insns[idx + 1];
            const auto &mov2 = insns[idx + 2];
            const auto &lsh  = insns[idx + 3];
            const auto &ior  = insns[idx + 4];

            if (mov1.code == MOV64_X && mov1.off == 0 && mov1.imm == 0 &&
                rsh.code  == RSH64_K &&
                mov2.code == MOV64_X && mov2.off == 0 && mov2.imm == 0 &&
                lsh.code  == LSH64_K &&
                ior.code  == OR64_X)
            {
                uint8_t tmp_reg  = mov1.regs & 0x0f;
                uint8_t src_reg1 = (mov1.regs >> 4) & 0x0f;
                uint8_t src_reg2 = (mov2.regs >> 4) & 0x0f;
                uint8_t dst_reg  = mov2.regs & 0x0f;
                int32_t rot_amount = lsh.imm;
                int32_t rsh_amount = rsh.imm;

                if (src_reg1 == src_reg2 &&
                    (rsh.regs & 0x0f) == tmp_reg &&
                    (lsh.regs & 0x0f) == dst_reg &&
                    (ior.regs & 0x0f) == dst_reg &&
                    ((ior.regs >> 4) & 0x0f) == tmp_reg &&
                    rot_amount > 0 && rot_amount < 64 &&
                    rsh_amount > 0 && rsh_amount < 64 &&
                    rot_amount + rsh_amount == 64)
                {
                    if (!emit_rule(rules, max_rules, count,
                                   idx, 5, BPF_JIT_RK_ROTATE, native_choice, cpu_feat))
                        return -ENOBUFS;
                    idx += 4;
                    goto next_iter;
                }
            }
        }

        // ----------------------------------------------------------------
        // 4-insn 64-bit commuted rotate (rsh before lsh):
        //   [0] mov64 tmp, src
        //   [1] rsh64 tmp, (64-N)
        //   [2] lsh64 src, N
        //   [3] or64  src, tmp
        // ----------------------------------------------------------------
        if (idx + 3 < insn_cnt) {
            const auto &mov = insns[idx];
            const auto &rsh = insns[idx + 1];
            const auto &lsh = insns[idx + 2];
            const auto &ior = insns[idx + 3];

            if (mov.code == MOV64_X && mov.off == 0 && mov.imm == 0 &&
                rsh.code == RSH64_K &&
                lsh.code == LSH64_K &&
                ior.code == OR64_X)
            {
                uint8_t tmp_reg = mov.regs & 0x0f;
                uint8_t src_reg = (mov.regs >> 4) & 0x0f;
                int32_t rot_amount = lsh.imm;
                int32_t rsh_amount = rsh.imm;

                if ((rsh.regs & 0x0f) == tmp_reg &&
                    (lsh.regs & 0x0f) == src_reg &&
                    (ior.regs & 0x0f) == src_reg &&
                    ((ior.regs >> 4) & 0x0f) == tmp_reg &&
                    rot_amount > 0 && rot_amount < 64 &&
                    rsh_amount > 0 && rsh_amount < 64 &&
                    rot_amount + rsh_amount == 64)
                {
                    if (!emit_rule(rules, max_rules, count,
                                   idx, 4, BPF_JIT_RK_ROTATE, native_choice, cpu_feat))
                        return -ENOBUFS;
                    idx += 3;
                    goto next_iter;
                }
            }
        }

        // ----------------------------------------------------------------
        // 4-insn classic rotate (lsh before rsh):
        //   [0] mov64/mov32 tmp, src
        //   [1] lsh dst, N
        //   [2] rsh tmp, (W-N)
        //   [3] or  dst, tmp
        // ----------------------------------------------------------------
        if (idx + 3 < insn_cnt) {
            const auto &mov = insns[idx];
            const auto &lsh = insns[idx + 1];
            const auto &rsh = insns[idx + 2];
            const auto &ior = insns[idx + 3];

            bool is64;
            uint32_t width;
            if (mov.code == MOV64_X) {
                is64 = true; width = 64;
            } else if (mov.code == MOV32_X) {
                is64 = false; width = 32;
            } else {
                goto next_iter;
            }

            if (mov.off != 0 || mov.imm != 0)
                goto next_iter;

            uint8_t tmp_reg = mov.regs & 0x0f;
            uint8_t src_reg = (mov.regs >> 4) & 0x0f;

            uint8_t expected_lsh = is64 ? LSH64_K : LSH32_K;
            if (lsh.code != expected_lsh) goto next_iter;
            if ((lsh.regs & 0x0f) != src_reg) goto next_iter;
            int32_t rot_amount = lsh.imm;
            if (rot_amount <= 0 || rot_amount >= static_cast<int32_t>(width))
                goto next_iter;

            uint8_t expected_rsh = is64 ? RSH64_K : RSH32_K;
            if (rsh.code != expected_rsh) goto next_iter;
            if ((rsh.regs & 0x0f) != tmp_reg) goto next_iter;
            if (rsh.imm != static_cast<int32_t>(width - rot_amount))
                goto next_iter;

            uint8_t expected_or = is64 ? OR64_X : OR32_X;
            if (ior.code != expected_or) goto next_iter;
            if ((ior.regs & 0x0f) != src_reg) goto next_iter;
            if (((ior.regs >> 4) & 0x0f) != tmp_reg) goto next_iter;

            if (!emit_rule(rules, max_rules, count,
                           idx, 4, BPF_JIT_RK_ROTATE, native_choice, cpu_feat))
                return -ENOBUFS;
            idx += 3;
        }

    next_iter:;
    }

    return static_cast<int>(count);
}

// ---------------------------------------------------------------------------
// bpf_jit_scan_addr_calc
// ---------------------------------------------------------------------------

int bpf_jit_scan_addr_calc(const uint8_t *xlated, uint32_t len,
                           struct bpf_jit_scan_rule *rules, uint32_t max_rules)
{
    if (!xlated || len % 8 != 0)
        return -EINVAL;

    std::vector<bpf_insn_raw> insns;
    parse_insns(xlated, len, insns);
    uint32_t insn_cnt = static_cast<uint32_t>(insns.size());

    if (insn_cnt < 3)
        return 0;

    constexpr uint8_t MOV64_X = 0xbf; // BPF_ALU64 | BPF_MOV | BPF_X
    constexpr uint8_t LSH64_K = 0x67; // BPF_ALU64 | BPF_LSH | BPF_K
    constexpr uint8_t ADD64_X = 0x0f; // BPF_ALU64 | BPF_ADD | BPF_X

    uint32_t count = 0;

    for (uint32_t idx = 0; idx + 2 < insn_cnt; idx++) {
        const auto &mov = insns[idx];
        const auto &lsh = insns[idx + 1];
        const auto &add = insns[idx + 2];

        // [0] mov64 dst, idx_reg
        if (mov.code != MOV64_X) continue;
        if (mov.off != 0 || mov.imm != 0) continue;
        uint8_t dst_reg = mov.regs & 0x0f;

        // [1] lsh64 dst, K  where K in {1, 2, 3}
        if (lsh.code != LSH64_K) continue;
        if ((lsh.regs & 0x0f) != dst_reg) continue;
        if (lsh.imm < 1 || lsh.imm > 3) continue;

        // [2] add64 dst, base_reg
        if (add.code != ADD64_X) continue;
        if ((add.regs & 0x0f) != dst_reg) continue;

        if (!emit_rule(rules, max_rules, count,
                       idx, 3, BPF_JIT_RK_ADDR_CALC, BPF_JIT_ACALC_LEA, 0))
            return -ENOBUFS;
        idx += 2; // loop will increment once more
    }

    return static_cast<int>(count);
}

// ---------------------------------------------------------------------------
// bpf_jit_scan_all
// ---------------------------------------------------------------------------

int bpf_jit_scan_all(const uint8_t *xlated, uint32_t len,
                     uint32_t scan_flags, bool use_rorx,
                     struct bpf_jit_scan_rule *rules, uint32_t max_rules)
{
    if (!xlated || len % 8 != 0)
        return -EINVAL;

    uint32_t total = 0;

    if (scan_flags & BPF_JIT_SCAN_CMOV) {
        int n = bpf_jit_scan_cmov(xlated, len, rules + total, max_rules - total);
        if (n < 0) return n;
        total += static_cast<uint32_t>(n);
    }
    if (scan_flags & BPF_JIT_SCAN_WIDE_MEM) {
        if (total >= max_rules && max_rules > 0) return -ENOBUFS;
        int n = bpf_jit_scan_wide_mem(xlated, len, rules + total, max_rules - total);
        if (n < 0) return n;
        total += static_cast<uint32_t>(n);
    }
    if (scan_flags & BPF_JIT_SCAN_ROTATE) {
        if (total >= max_rules && max_rules > 0) return -ENOBUFS;
        int n = bpf_jit_scan_rotate(xlated, len, use_rorx, rules + total, max_rules - total);
        if (n < 0) return n;
        total += static_cast<uint32_t>(n);
    }
    if (scan_flags & BPF_JIT_SCAN_ADDR_CALC) {
        if (total >= max_rules && max_rules > 0) return -ENOBUFS;
        int n = bpf_jit_scan_addr_calc(xlated, len, rules + total, max_rules - total);
        if (n < 0) return n;
        total += static_cast<uint32_t>(n);
    }

    return static_cast<int>(total);
}
