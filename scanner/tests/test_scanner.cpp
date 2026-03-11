// SPDX-License-Identifier: MIT

#include "bpf_jit_scanner/pattern_v5.hpp"

#include <cstdio>
#include <cstring>
#include <vector>

namespace {

int g_pass = 0;
int g_fail = 0;

#define CHECK(expr) do { \
    if (!(expr)) { \
        std::fprintf(stderr, "FAIL  %s:%d: %s\n", __FILE__, __LINE__, #expr); \
        ++g_fail; \
    } else { \
        ++g_pass; \
    } \
} while (0)

#define CHECK_EQ(a, b) do { \
    auto _a = (a); auto _b = (b); \
    if (_a != _b) { \
        std::fprintf(stderr, "FAIL  %s:%d: %s == %s  (%lld != %lld)\n", \
                     __FILE__, __LINE__, #a, #b, \
                     static_cast<long long>(_a), static_cast<long long>(_b)); \
        ++g_fail; \
    } else { \
        ++g_pass; \
    } \
} while (0)

struct insn8 {
    uint8_t code;
    uint8_t regs;
    int16_t off;
    int32_t imm;
};

std::vector<uint8_t> encode(std::initializer_list<insn8> insns)
{
    std::vector<uint8_t> bytes;
    bytes.reserve(insns.size() * 8);
    for (const auto &insn : insns) {
        const auto *ptr = reinterpret_cast<const uint8_t *>(&insn);
        bytes.insert(bytes.end(), ptr, ptr + 8);
    }
    return bytes;
}

uint8_t regs(uint8_t dst, uint8_t src = 0)
{
    return static_cast<uint8_t>(dst | (src << 4));
}

constexpr uint8_t BPF_JMP_JA = 0x05;
constexpr uint8_t BPF_JEQ_K = 0x15;
constexpr uint8_t BPF_JEQ_X = 0x1d;
constexpr uint8_t BPF_JSET_K = 0x45;
constexpr uint8_t BPF_JNE_K = 0x55;
constexpr uint8_t BPF_MOV64_X = 0xbf;
constexpr uint8_t BPF_MOV64_K = 0xb7;
constexpr uint8_t BPF_MOV32_X = 0xbc;
constexpr uint8_t BPF_LSH64_K = 0x67;
constexpr uint8_t BPF_LSH32_K = 0x64;
constexpr uint8_t BPF_RSH64_K = 0x77;
constexpr uint8_t BPF_RSH32_K = 0x74;
constexpr uint8_t BPF_OR64_X = 0x4f;
constexpr uint8_t BPF_OR32_X = 0x4c;
constexpr uint8_t BPF_AND64_K = 0x57;
constexpr uint8_t BPF_AND32_K = 0x54;
constexpr uint8_t BPF_AND64_X = 0x5f;
constexpr uint8_t BPF_XOR64_X = 0xaf;
constexpr uint8_t BPF_LDXB = 0x71;
constexpr uint8_t BPF_ADD64_X = 0x0f;
constexpr uint8_t BPF_ADD32_K = 0x04;
constexpr uint8_t BPF_NEG32 = 0x84;
constexpr uint8_t BPF_LDXH = 0x69;
constexpr uint8_t BPF_LDXW = 0x61;
constexpr uint8_t BPF_STXH = 0x6b;
constexpr uint8_t BPF_STXW = 0x63;
constexpr uint8_t BPF_ENDIAN_BE = 0xdc;
constexpr uint8_t BPF_BSWAP = 0xd7;

void test_v5_cmov_scan_and_blob()
{
    using bpf_jit_scanner::V5RuleWire;
    using bpf_jit_scanner::V5ScanOptions;

    auto diamond = encode({
        {BPF_JEQ_X, regs(0, 1), 2, 0},
        {BPF_MOV64_X, regs(2, 3), 0, 0},
        {BPF_JMP_JA, 0, 1, 0},
        {BPF_MOV64_X, regs(2, 4), 0, 0},
    });
    auto compact = encode({
        {BPF_MOV64_X, regs(2, 3), 0, 0},
        {BPF_JEQ_X, regs(0, 1), 1, 0},
        {BPF_MOV64_X, regs(2, 4), 0, 0},
    });

    auto diamond_summary = bpf_jit_scanner::scan_v5_builtin(
        diamond.data(), static_cast<uint32_t>(diamond.size()),
        V5ScanOptions {.scan_cmov = true});
    CHECK_EQ(diamond_summary.rules.size(), 1u);
    CHECK_EQ(diamond_summary.cmov_sites, 1u);
    CHECK_EQ(diamond_summary.rules[0].canonical_form,
             static_cast<uint16_t>(BPF_JIT_CF_COND_SELECT));
    CHECK_EQ(diamond_summary.rules[0].native_choice,
             static_cast<uint16_t>(BPF_JIT_SEL_CMOVCC));
    CHECK_EQ(diamond_summary.rules[0].pattern.size(), 4u);
    CHECK_EQ(diamond_summary.rules[0].bindings.size(), 7u);

    auto compact_summary = bpf_jit_scanner::scan_v5_builtin(
        compact.data(), static_cast<uint32_t>(compact.size()),
        V5ScanOptions {.scan_cmov = true});
    CHECK_EQ(compact_summary.rules.size(), 1u);
    CHECK_EQ(compact_summary.cmov_sites, 1u);
    CHECK_EQ(compact_summary.rules[0].pattern.size(), 3u);
    CHECK_EQ(compact_summary.rules[0].bindings.size(), 7u);

    uint8_t tag[8] = {0xde, 0xad, 0xbe, 0xef, 0x12, 0x34, 0x56, 0x78};
    auto blob = bpf_jit_scanner::build_policy_blob_v5(
        static_cast<uint32_t>(diamond.size() / 8), tag, diamond_summary.rules);

    uint16_t version = 0;
    uint32_t rule_cnt = 0;
    V5RuleWire wire_rule = {};
    std::memcpy(&version, blob.data() + 4, sizeof(version));
    std::memcpy(&rule_cnt, blob.data() + 12, sizeof(rule_cnt));
    std::memcpy(&wire_rule, blob.data() + 32, sizeof(wire_rule));
    CHECK_EQ(version, static_cast<uint16_t>(BPF_JIT_POLICY_VERSION_2));
    CHECK_EQ(rule_cnt, 1u);
    CHECK_EQ(wire_rule.rule_kind, static_cast<uint16_t>(BPF_JIT_RK_PATTERN));
    CHECK_EQ(wire_rule.canonical_form, static_cast<uint16_t>(BPF_JIT_CF_COND_SELECT));
}

void test_v5_cmov_broadening_scan()
{
    using bpf_jit_scanner::V5ScanOptions;

    auto guarded_update = encode({
        {BPF_JNE_K, regs(2, 0), 3, 0},
        {BPF_ADD64_X, regs(5, 6), 0, 0},
        {BPF_MOV64_X, regs(1, 5), 0, 0},
        {BPF_JMP_JA, 0, 0, 0},
        {BPF_MOV64_X, regs(7, 8), 0, 0},
    });
    auto jset_guarded = encode({
        {BPF_JSET_K, regs(2, 0), 3, 1},
        {BPF_RSH64_K, regs(5, 0), 0, 5},
        {BPF_XOR64_X, regs(6, 5), 0, 0},
        {BPF_MOV64_X, regs(1, 6), 0, 0},
    });
    auto switch_chain = encode({
        {BPF_MOV64_K, regs(1, 0), 0, 10},
        {BPF_JEQ_K, regs(2, 0), 4, 0},
        {BPF_JEQ_K, regs(2, 0), 1, 1},
        {BPF_JMP_JA, 0, 3, 0},
        {BPF_MOV64_K, regs(1, 0), 0, 20},
        {BPF_JMP_JA, 0, 0, 0},
        {BPF_MOV64_X, regs(7, 8), 0, 0},
        {BPF_MOV64_X, regs(9, 10), 0, 0},
    });

    auto guarded_summary = bpf_jit_scanner::scan_v5_builtin(
        guarded_update.data(), static_cast<uint32_t>(guarded_update.size()),
        V5ScanOptions {.scan_cmov = true});
    CHECK_EQ(guarded_summary.cmov_sites, 1u);
    CHECK_EQ(guarded_summary.rules[0].pattern.size(), 4u);

    auto jset_summary = bpf_jit_scanner::scan_v5_builtin(
        jset_guarded.data(), static_cast<uint32_t>(jset_guarded.size()),
        V5ScanOptions {.scan_cmov = true});
    CHECK_EQ(jset_summary.cmov_sites, 1u);
    CHECK_EQ(jset_summary.rules[0].pattern.size(), 4u);

    auto switch_summary = bpf_jit_scanner::scan_v5_builtin(
        switch_chain.data(), static_cast<uint32_t>(switch_chain.size()),
        V5ScanOptions {.scan_cmov = true});
    CHECK_EQ(switch_summary.cmov_sites, 1u);
    CHECK_EQ(switch_summary.rules[0].pattern.size(), 6u);
}

void test_v5_rotate_scan()
{
    using bpf_jit_scanner::V5ScanOptions;

    auto masked_rotate = encode({
        {BPF_MOV64_X, regs(3, 5), 0, 0},
        {BPF_AND64_X, regs(3, 4), 0, 0},
        {BPF_RSH64_K, regs(3, 0), 0, 28},
        {BPF_MOV64_X, regs(7, 5), 0, 0},
        {BPF_LSH64_K, regs(7, 0), 0, 4},
        {BPF_OR64_X, regs(7, 3), 0, 0},
    });

    auto summary = bpf_jit_scanner::scan_v5_builtin(
        masked_rotate.data(), static_cast<uint32_t>(masked_rotate.size()),
        V5ScanOptions {.scan_rotate = true});

    CHECK_EQ(summary.rules.size(), 1u);
    CHECK_EQ(summary.rotate_sites, 1u);
    CHECK_EQ(summary.rules[0].canonical_form,
             static_cast<uint16_t>(BPF_JIT_CF_ROTATE));
    CHECK_EQ(summary.rules[0].native_choice,
             static_cast<uint16_t>(BPF_JIT_ROT_ROR));
    CHECK_EQ(summary.rules[0].bindings.size(), 4u);

    auto rorx_summary = bpf_jit_scanner::scan_v5_builtin(
        masked_rotate.data(), static_cast<uint32_t>(masked_rotate.size()),
        V5ScanOptions {.scan_rotate = true, .use_rorx = true});
    CHECK_EQ(rorx_summary.rules.size(), 1u);
    CHECK_EQ(rorx_summary.rules[0].native_choice,
             static_cast<uint16_t>(BPF_JIT_ROT_RORX));
    CHECK_EQ(rorx_summary.rules[0].cpu_features_required,
             static_cast<uint32_t>(BPF_JIT_X86_BMI2));
}

void test_v5_wide_scan_variants()
{
    using bpf_jit_scanner::V5ScanOptions;

    auto wide3 = encode({
        {BPF_LDXB, regs(1, 2), 0, 0},
        {BPF_LDXB, regs(3, 2), 1, 0},
        {BPF_LSH64_K, regs(3, 0), 0, 8},
        {BPF_OR64_X, regs(1, 3), 0, 0},
        {BPF_LDXB, regs(4, 2), 2, 0},
        {BPF_LSH64_K, regs(4, 0), 0, 16},
        {BPF_OR64_X, regs(1, 4), 0, 0},
    });
    auto wide3_summary = bpf_jit_scanner::scan_v5_builtin(
        wide3.data(), static_cast<uint32_t>(wide3.size()),
        V5ScanOptions {.scan_wide = true});
    CHECK_EQ(wide3_summary.rules.size(), 1u);
    CHECK_EQ(wide3_summary.wide_sites, 1u);
    CHECK_EQ(wide3_summary.rules[0].pattern.size(), 7u);
    CHECK_EQ(wide3_summary.rules[0].bindings.back().inline_const, 3);

    auto packet_be = encode({
        {BPF_LDXB, regs(1, 2), 0x22, 0},
        {BPF_LSH64_K, regs(1, 0), 0, 24},
        {BPF_LDXB, regs(3, 2), 0x23, 0},
        {BPF_LSH64_K, regs(3, 0), 0, 16},
        {BPF_OR64_X, regs(1, 3), 0, 0},
        {BPF_LDXB, regs(4, 2), 0x24, 0},
        {BPF_LSH64_K, regs(4, 0), 0, 8},
        {BPF_OR64_X, regs(1, 4), 0, 0},
        {BPF_LDXB, regs(5, 2), 0x25, 0},
        {BPF_OR64_X, regs(1, 5), 0, 0},
    });
    auto packet_summary = bpf_jit_scanner::scan_v5_builtin(
        packet_be.data(), static_cast<uint32_t>(packet_be.size()),
        V5ScanOptions {.scan_wide = true});
    CHECK_EQ(packet_summary.rules.size(), 1u);
    CHECK_EQ(packet_summary.wide_sites, 1u);
    CHECK_EQ(packet_summary.rules[0].pattern.size(), 10u);
    CHECK_EQ(packet_summary.rules[0].bindings.back().inline_const,
             static_cast<int32_t>(4 | BPF_JIT_WMEM_F_BIG_ENDIAN));
}

void test_v5_lea_scan()
{
    using bpf_jit_scanner::V5ScanOptions;

    auto lea = encode({
        {BPF_MOV64_X, regs(2, 3), 0, 0},
        {BPF_LSH64_K, regs(2, 0), 0, 2},
        {BPF_ADD64_X, regs(2, 4), 0, 0},
    });

    auto summary = bpf_jit_scanner::scan_v5_builtin(
        lea.data(), static_cast<uint32_t>(lea.size()),
        V5ScanOptions {.scan_lea = true});

    CHECK_EQ(summary.rules.size(), 1u);
    CHECK_EQ(summary.lea_sites, 1u);
    CHECK_EQ(summary.rules[0].canonical_form,
             static_cast<uint16_t>(BPF_JIT_CF_ADDR_CALC));
    CHECK_EQ(summary.rules[0].native_choice,
             static_cast<uint16_t>(BPF_JIT_ACALC_LEA));
}

void test_v5_bitfield_extract_scan()
{
    using bpf_jit_scanner::V5ScanOptions;

    auto extract = encode({
        {BPF_MOV64_X, regs(2, 1), 0, 0},
        {BPF_RSH64_K, regs(2, 0), 0, 13},
        {BPF_AND64_K, regs(2, 0), 0, 0x1ff},
    });
    auto mask_then_shift = encode({
        {BPF_AND32_K, regs(3, 0), 0, 0x03f8},
        {BPF_RSH32_K, regs(3, 0), 0, 3},
    });

    auto extract_summary = bpf_jit_scanner::scan_v5_builtin(
        extract.data(), static_cast<uint32_t>(extract.size()),
        V5ScanOptions {.scan_extract = true});
    CHECK_EQ(extract_summary.rules.size(), 1u);
    CHECK_EQ(extract_summary.bitfield_sites, 1u);
    CHECK_EQ(extract_summary.rules[0].canonical_form,
             static_cast<uint16_t>(BPF_JIT_CF_BITFIELD_EXTRACT));
    CHECK_EQ(extract_summary.rules[0].native_choice,
             static_cast<uint16_t>(BPF_JIT_BFX_EXTRACT));
    CHECK_EQ(extract_summary.rules[0].pattern.size(), 3u);
    CHECK_EQ(extract_summary.rules[0].bindings.size(), 6u);

    auto mask_shift_summary = bpf_jit_scanner::scan_v5_builtin(
        mask_then_shift.data(), static_cast<uint32_t>(mask_then_shift.size()),
        V5ScanOptions {.scan_extract = true});
    CHECK_EQ(mask_shift_summary.rules.size(), 1u);
    CHECK_EQ(mask_shift_summary.bitfield_sites, 1u);
    CHECK_EQ(mask_shift_summary.rules[0].pattern.size(), 2u);
    CHECK_EQ(mask_shift_summary.rules[0].bindings.size(), 6u);
}

void test_v5_zero_ext_elide_scan()
{
    using bpf_jit_scanner::V5ScanOptions;

    auto self_mov = encode({
        {BPF_ADD32_K, regs(3, 0), 0, 7},
        {BPF_MOV64_X, regs(3, 3), 0, 0},
    });
    auto and_mask = encode({
        {BPF_NEG32, regs(4, 0), 0, 0},
        {BPF_AND64_K, regs(4, 0), 0, -1},
    });

    auto mov_summary = bpf_jit_scanner::scan_v5_builtin(
        self_mov.data(), static_cast<uint32_t>(self_mov.size()),
        V5ScanOptions {.scan_zero_ext = true});
    CHECK_EQ(mov_summary.rules.size(), 1u);
    CHECK_EQ(mov_summary.zero_ext_sites, 1u);
    CHECK_EQ(mov_summary.rules[0].canonical_form,
             static_cast<uint16_t>(BPF_JIT_CF_ZERO_EXT_ELIDE));
    CHECK_EQ(mov_summary.rules[0].native_choice,
             static_cast<uint16_t>(BPF_JIT_ZEXT_ELIDE));
    CHECK_EQ(mov_summary.rules[0].pattern.size(), 2u);
    CHECK_EQ(mov_summary.rules[0].bindings.size(), 1u);

    auto and_summary = bpf_jit_scanner::scan_v5_builtin(
        and_mask.data(), static_cast<uint32_t>(and_mask.size()),
        V5ScanOptions {.scan_zero_ext = true});
    CHECK_EQ(and_summary.rules.size(), 1u);
    CHECK_EQ(and_summary.zero_ext_sites, 1u);
    CHECK_EQ(and_summary.rules[0].pattern.size(), 2u);
    CHECK_EQ(and_summary.rules[0].bindings.size(), 1u);
}

void test_v5_endian_fusion_scan()
{
    using bpf_jit_scanner::V5ScanOptions;

    auto load_swap = encode({
        {BPF_LDXW, regs(3, 5), 12, 0},
        {BPF_BSWAP, regs(3, 0), 0, 32},
    });
    auto swap_store = encode({
        {BPF_ENDIAN_BE, regs(4, 0), 0, 16},
        {BPF_STXH, regs(5, 4), 8, 0},
    });

    auto load_summary = bpf_jit_scanner::scan_v5_builtin(
        load_swap.data(), static_cast<uint32_t>(load_swap.size()),
        V5ScanOptions {.scan_endian = true});
    CHECK_EQ(load_summary.rules.size(), 1u);
    CHECK_EQ(load_summary.endian_sites, 1u);
    CHECK_EQ(load_summary.rules[0].canonical_form,
             static_cast<uint16_t>(BPF_JIT_CF_ENDIAN_FUSION));
    CHECK_EQ(load_summary.rules[0].native_choice,
             static_cast<uint16_t>(BPF_JIT_ENDIAN_MOVBE));
    CHECK_EQ(load_summary.rules[0].cpu_features_required,
             static_cast<uint32_t>(BPF_JIT_X86_MOVBE));
    CHECK_EQ(load_summary.rules[0].bindings.size(), 5u);

    auto store_summary = bpf_jit_scanner::scan_v5_builtin(
        swap_store.data(), static_cast<uint32_t>(swap_store.size()),
        V5ScanOptions {.scan_endian = true});
    CHECK_EQ(store_summary.rules.size(), 1u);
    CHECK_EQ(store_summary.endian_sites, 1u);
    CHECK_EQ(store_summary.rules[0].bindings.size(), 5u);
}

void test_v5_branch_flip_scan()
{
    using bpf_jit_scanner::V5ScanOptions;

    auto diamond = encode({
        {BPF_JEQ_K, regs(1, 0), 3, 0},
        {BPF_MOV64_X, regs(4, 5), 0, 0},
        {BPF_ADD64_X, regs(4, 6), 0, 0},
        {BPF_JMP_JA, 0, 2, 0},
        {BPF_MOV64_K, regs(4, 0), 0, 9},
        {BPF_ADD64_X, regs(4, 7), 0, 0},
    });

    auto summary = bpf_jit_scanner::scan_v5_builtin(
        diamond.data(), static_cast<uint32_t>(diamond.size()),
        V5ScanOptions {.scan_branch_flip = true});
    CHECK_EQ(summary.rules.size(), 1u);
    CHECK_EQ(summary.branch_flip_sites, 1u);
    CHECK_EQ(summary.rules[0].canonical_form,
             static_cast<uint16_t>(BPF_JIT_CF_BRANCH_FLIP));
    CHECK_EQ(summary.rules[0].native_choice,
             static_cast<uint16_t>(BPF_JIT_BFLIP_FLIPPED));
    CHECK_EQ(summary.rules[0].pattern.size(), 6u);
    CHECK_EQ(summary.rules[0].bindings.size(), 6u);
}

void test_v5_abi_limits()
{
    CHECK_EQ(BPF_JIT_MAX_PATTERN_LEN, 64);
    CHECK_EQ(BPF_JIT_MAX_BINDINGS, 16);
    CHECK_EQ(BPF_JIT_MAX_CANONICAL_PARAMS, 16);
}

} // namespace

int main()
{
    test_v5_cmov_scan_and_blob();
    test_v5_cmov_broadening_scan();
    test_v5_rotate_scan();
    test_v5_wide_scan_variants();
    test_v5_lea_scan();
    test_v5_bitfield_extract_scan();
    test_v5_zero_ext_elide_scan();
    test_v5_endian_fusion_scan();
    test_v5_branch_flip_scan();
    test_v5_abi_limits();

    std::printf("PASS %d\n", g_pass);
    if (g_fail) {
        std::printf("FAIL %d\n", g_fail);
        return 1;
    }
    return 0;
}
