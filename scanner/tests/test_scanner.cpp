// SPDX-License-Identifier: MIT

#include "bpf_jit_scanner/pattern_v5.hpp"
#include "bpf_jit_scanner/policy_config.hpp"

#include <array>
#include <cstdio>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <stdexcept>
#include <string>
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

std::filesystem::path golden_policy_dir()
{
    return std::filesystem::path(__FILE__).parent_path() /
           "policy_v3_golden";
}

std::string read_text_file(const std::filesystem::path &path)
{
    std::ifstream input(path);
    if (!input) {
        throw std::runtime_error("failed to open " + path.string());
    }
    return std::string(std::istreambuf_iterator<char>(input),
                       std::istreambuf_iterator<char>());
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
    CHECK_EQ(diamond_summary.rules[0].site_len, 4u);
    CHECK(diamond_summary.rules[0].pattern_kind == "cond-select-64");

    auto compact_summary = bpf_jit_scanner::scan_v5_builtin(
        compact.data(), static_cast<uint32_t>(compact.size()),
        V5ScanOptions {.scan_cmov = true});
    CHECK_EQ(compact_summary.rules.size(), 1u);
    CHECK_EQ(compact_summary.cmov_sites, 1u);
    CHECK_EQ(compact_summary.rules[0].site_len, 3u);
    CHECK(compact_summary.rules[0].pattern_kind == "cond-select-64");

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
    CHECK_EQ(wire_rule.site_len, 4u);
    CHECK_EQ(wire_rule.canonical_form, static_cast<uint16_t>(BPF_JIT_CF_COND_SELECT));
    CHECK_EQ(wire_rule.native_choice, static_cast<uint16_t>(BPF_JIT_SEL_CMOVCC));
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
    CHECK_EQ(guarded_summary.rules[0].site_len, 4u);

    auto jset_summary = bpf_jit_scanner::scan_v5_builtin(
        jset_guarded.data(), static_cast<uint32_t>(jset_guarded.size()),
        V5ScanOptions {.scan_cmov = true});
    CHECK_EQ(jset_summary.cmov_sites, 1u);
    CHECK_EQ(jset_summary.rules[0].site_len, 4u);

    auto switch_summary = bpf_jit_scanner::scan_v5_builtin(
        switch_chain.data(), static_cast<uint32_t>(switch_chain.size()),
        V5ScanOptions {.scan_cmov = true});
    CHECK_EQ(switch_summary.cmov_sites, 1u);
    CHECK_EQ(switch_summary.rules[0].site_len, 6u);
}

void test_v5_rotate_scan()
{
    using bpf_jit_scanner::V5ScanOptions;

    auto masked_rotate = encode({
        {BPF_MOV64_X, regs(3, 5), 0, 0},
        {BPF_AND64_K, regs(3, 0), 0, static_cast<int32_t>(0xf0000000U)},
        {BPF_RSH64_K, regs(3, 0), 0, 28},
        {BPF_MOV64_X, regs(7, 5), 0, 0},
        {BPF_LSH64_K, regs(7, 0), 0, 4},
        {BPF_OR64_X, regs(7, 3), 0, 0},
    });
    auto masked_rotate_low_mask = encode({
        {BPF_MOV64_X, regs(3, 5), 0, 0},
        {BPF_AND64_K, regs(3, 0), 0, 0x0fffffff},
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
    CHECK_EQ(summary.rules[0].site_len, 6u);
    CHECK(summary.rules[0].pattern_kind == "rotate-32");

    auto rorx_summary = bpf_jit_scanner::scan_v5_builtin(
        masked_rotate.data(), static_cast<uint32_t>(masked_rotate.size()),
        V5ScanOptions {.scan_rotate = true, .use_rorx = true});
    CHECK_EQ(rorx_summary.rules.size(), 1u);
    CHECK_EQ(rorx_summary.rules[0].native_choice,
             static_cast<uint16_t>(BPF_JIT_ROT_RORX));
    CHECK(rorx_summary.rules[0].pattern_kind == "rotate-32");

    auto low_mask_summary = bpf_jit_scanner::scan_v5_builtin(
        masked_rotate_low_mask.data(),
        static_cast<uint32_t>(masked_rotate_low_mask.size()),
        V5ScanOptions {.scan_rotate = true});
    CHECK_EQ(low_mask_summary.rules.size(), 0u);
    CHECK_EQ(low_mask_summary.rotate_sites, 0u);

    auto masked_rotate_in_place = encode({
        {BPF_MOV64_X, regs(3, 5), 0, 0},
        {BPF_AND64_K, regs(3, 0), 0, static_cast<int32_t>(0xf0000000U)},
        {BPF_RSH64_K, regs(3, 0), 0, 28},
        {BPF_LSH64_K, regs(5, 0), 0, 4},
        {BPF_OR64_X, regs(5, 3), 0, 0},
    });
    auto in_place_summary = bpf_jit_scanner::scan_v5_builtin(
        masked_rotate_in_place.data(),
        static_cast<uint32_t>(masked_rotate_in_place.size()),
        V5ScanOptions {.scan_rotate = true});
    CHECK_EQ(in_place_summary.rules.size(), 1u);
    CHECK_EQ(in_place_summary.rotate_sites, 1u);
    CHECK_EQ(in_place_summary.rules[0].site_len, 5u);
    CHECK(in_place_summary.rules[0].pattern_kind == "rotate-32");

    auto masked_rotate_in_place_low_mask = encode({
        {BPF_MOV64_X, regs(3, 5), 0, 0},
        {BPF_AND64_K, regs(3, 0), 0, 0x0fffffff},
        {BPF_RSH64_K, regs(3, 0), 0, 28},
        {BPF_LSH64_K, regs(5, 0), 0, 4},
        {BPF_OR64_X, regs(5, 3), 0, 0},
    });
    auto in_place_low_mask_summary = bpf_jit_scanner::scan_v5_builtin(
        masked_rotate_in_place_low_mask.data(),
        static_cast<uint32_t>(masked_rotate_in_place_low_mask.size()),
        V5ScanOptions {.scan_rotate = true});
    CHECK_EQ(in_place_low_mask_summary.rules.size(), 0u);
    CHECK_EQ(in_place_low_mask_summary.rotate_sites, 0u);
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
    CHECK_EQ(wide3_summary.rules[0].site_len, 7u);
    CHECK(wide3_summary.rules[0].pattern_kind == "wide-load-3");

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
    CHECK_EQ(packet_summary.rules[0].site_len, 10u);
    CHECK(packet_summary.rules[0].pattern_kind == "wide-load-4-be");
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
    CHECK_EQ(extract_summary.rules[0].site_len, 3u);
    CHECK(extract_summary.rules[0].pattern_kind ==
          "bitfield-extract-64-shift-mask");

    auto mask_shift_summary = bpf_jit_scanner::scan_v5_builtin(
        mask_then_shift.data(), static_cast<uint32_t>(mask_then_shift.size()),
        V5ScanOptions {.scan_extract = true});
    CHECK_EQ(mask_shift_summary.rules.size(), 1u);
    CHECK_EQ(mask_shift_summary.bitfield_sites, 1u);
    CHECK_EQ(mask_shift_summary.rules[0].site_len, 2u);
    CHECK(mask_shift_summary.rules[0].pattern_kind ==
          "bitfield-extract-32-mask-shift");
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
    CHECK_EQ(load_summary.rules[0].site_len, 2u);
    CHECK(load_summary.rules[0].pattern_kind == "endian-load-swap-32");

    auto store_summary = bpf_jit_scanner::scan_v5_builtin(
        swap_store.data(), static_cast<uint32_t>(swap_store.size()),
        V5ScanOptions {.scan_endian = true});
    CHECK_EQ(store_summary.rules.size(), 1u);
    CHECK_EQ(store_summary.endian_sites, 1u);
    CHECK_EQ(store_summary.rules[0].site_len, 2u);
    CHECK(store_summary.rules[0].pattern_kind == "endian-swap-store-16");
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
    CHECK_EQ(summary.rules[0].site_len, 6u);
    CHECK(summary.rules[0].pattern_kind == "branch-flip");
}

void test_v5_abi_limits()
{
    CHECK_EQ(sizeof(bpf_jit_scanner::V5RuleWire), 12u);
    CHECK_EQ(static_cast<unsigned int>(BPF_JIT_POLICY_VERSION_2), 2u);
}

void test_v5_policy_filter()
{
    using bpf_jit_scanner::V5ScanOptions;

    auto mixed = encode({
        {BPF_JEQ_X, regs(0, 1), 2, 0},
        {BPF_MOV64_X, regs(2, 3), 0, 0},
        {BPF_JMP_JA, 0, 1, 0},
        {BPF_MOV64_X, regs(2, 4), 0, 0},
        {BPF_MOV64_X, regs(3, 5), 0, 0},
        {BPF_AND64_X, regs(3, 4), 0, 0},
        {BPF_RSH64_K, regs(3, 0), 0, 28},
        {BPF_MOV64_X, regs(7, 5), 0, 0},
        {BPF_LSH64_K, regs(7, 0), 0, 4},
        {BPF_OR64_X, regs(7, 3), 0, 0},
    });

    auto summary = bpf_jit_scanner::scan_v5_builtin(
        mixed.data(), static_cast<uint32_t>(mixed.size()),
        V5ScanOptions {.scan_cmov = true, .scan_rotate = true});
    CHECK_EQ(summary.rules.size(), 1u);
    CHECK_EQ(summary.cmov_sites, 1u);
    CHECK_EQ(summary.rotate_sites, 0u);

    const auto branch_flip = bpf_jit_scanner::parse_v5_family_name("branch_flip");
    CHECK(branch_flip.has_value());
    if (branch_flip.has_value()) {
        CHECK_EQ(*branch_flip, bpf_jit_scanner::V5Family::BranchFlip);
    }

    auto rotate_only = bpf_jit_scanner::parse_policy_config_text(
        "version: 3\n"
        "program: mixed-demo\n"
        "sites:\n"
        "  - insn: 4\n"
        "    family: rotate\n"
        "    pattern_kind: rotate-32\n"
        "  - insn: 99\n"
        "    family: cmov\n"
        "    pattern_kind: cond-select-64\n",
        "per-site.yaml");
    auto rotate_only_result = bpf_jit_scanner::filter_rules_by_policy_detailed(
        summary.rules, rotate_only);
    CHECK_EQ(rotate_only_result.rules.size(), 0u);
    CHECK_EQ(rotate_only_result.matched_site_count, 0u);
    CHECK_EQ(rotate_only_result.unmatched_site_count, 2u);
    CHECK_EQ(rotate_only_result.warnings.size(), 2u);
    CHECK(rotate_only_result.warnings[0].find(
              "rotate insn 4 pattern_kind rotate-32") !=
          std::string::npos);
    CHECK(rotate_only_result.warnings[1].find(
              "cmov insn 99 pattern_kind cond-select-64") !=
          std::string::npos);

    auto all_sites = bpf_jit_scanner::parse_policy_config_text(
        "version: 3\n"
        "program: mixed-demo\n"
        "sites:\n"
        "  - insn: 0\n"
        "    family: cmov\n"
        "    pattern_kind: cond-select-64\n"
        "  - insn: 4\n"
        "    family: rotate\n"
        "    pattern_kind: rotate-32\n",
        "all-sites.yaml");
    auto all_site_rules = bpf_jit_scanner::filter_rules_by_policy(
        summary.rules, all_sites);
    CHECK_EQ(all_site_rules.size(), 1u);

    auto cmov_only = bpf_jit_scanner::parse_policy_config_text(
        "version: 3\n"
        "program: mixed-demo\n"
        "sites:\n"
        "  - insn: 0\n"
        "    family: cmov\n"
        "    pattern_kind: cond-select-64\n",
        "cmov-only.yaml");
    auto cmov_only_rules = bpf_jit_scanner::filter_rules_by_policy(
        summary.rules, cmov_only);
    CHECK_EQ(cmov_only_rules.size(), 1u);
    CHECK_EQ(cmov_only_rules[0].family, bpf_jit_scanner::V5Family::Cmov);
    CHECK(bpf_jit_scanner::v5_policy_allows_family(
        cmov_only, bpf_jit_scanner::V5Family::Cmov));
    CHECK(!bpf_jit_scanner::v5_policy_allows_family(
        cmov_only, bpf_jit_scanner::V5Family::Rotate));

    auto valid_rotate = encode({
        {BPF_MOV64_X, regs(3, 5), 0, 0},
        {BPF_AND64_K, regs(3, 0), 0, static_cast<int32_t>(0xf0000000U)},
        {BPF_RSH64_K, regs(3, 0), 0, 28},
        {BPF_MOV64_X, regs(7, 5), 0, 0},
        {BPF_LSH64_K, regs(7, 0), 0, 4},
        {BPF_OR64_X, regs(7, 3), 0, 0},
    });
    auto rotate_summary = bpf_jit_scanner::scan_v5_builtin(
        valid_rotate.data(), static_cast<uint32_t>(valid_rotate.size()),
        V5ScanOptions {.scan_rotate = true});
    bool found_rotate_rule = !rotate_summary.rules.empty();
    CHECK(found_rotate_rule);
    if (found_rotate_rule) {
        auto rotate32_rule = rotate_summary.rules[0];
        rotate32_rule.site_start = 4;
        bpf_jit_scanner::V5PolicyRule rotate64_variant = rotate32_rule;
        rotate64_variant.pattern_kind = "rotate-64";
        std::vector<bpf_jit_scanner::V5PolicyRule> colliding_rules = summary.rules;
        colliding_rules.push_back(rotate32_rule);
        colliding_rules.push_back(rotate64_variant);

        auto rotate64_only = bpf_jit_scanner::parse_policy_config_text(
            "version: 3\n"
            "program: mixed-demo\n"
            "sites:\n"
            "  - insn: 4\n"
            "    family: rotate\n"
            "    pattern_kind: rotate-64\n",
            "rotate64-only.yaml");
        auto rotate64_only_result =
            bpf_jit_scanner::filter_rules_by_policy_detailed(
                colliding_rules, rotate64_only);
        CHECK_EQ(rotate64_only_result.rules.size(), 1u);
        CHECK_EQ(rotate64_only_result.matched_site_count, 1u);
        CHECK_EQ(rotate64_only_result.unmatched_site_count, 0u);
        CHECK_EQ(rotate64_only_result.warnings.size(), 0u);
        if (!rotate64_only_result.rules.empty()) {
            CHECK(rotate64_only_result.rules[0].pattern_kind == "rotate-64");
        }

        auto distinct_rotate_sites = bpf_jit_scanner::parse_policy_config_text(
            "version: 3\n"
            "program: mixed-demo\n"
            "sites:\n"
            "  - insn: 4\n"
            "    family: rotate\n"
            "    pattern_kind: rotate-32\n"
            "  - insn: 4\n"
            "    family: rotate\n"
            "    pattern_kind: rotate-64\n",
            "distinct-rotate-sites.yaml");
        auto distinct_rotate_result =
            bpf_jit_scanner::filter_rules_by_policy_detailed(
                colliding_rules, distinct_rotate_sites);
        CHECK_EQ(distinct_rotate_result.rules.size(), 2u);
        CHECK_EQ(distinct_rotate_result.matched_site_count, 2u);
        CHECK_EQ(distinct_rotate_result.unmatched_site_count, 0u);
        CHECK_EQ(distinct_rotate_result.warnings.size(), 0u);
        bool saw_rotate64 = false;
        bool saw_rotate32 = false;
        for (const auto &rule : distinct_rotate_result.rules) {
            saw_rotate64 = saw_rotate64 || rule.pattern_kind == "rotate-64";
            saw_rotate32 = saw_rotate32 || rule.pattern_kind == "rotate-32";
        }
        CHECK(saw_rotate64);
        CHECK(saw_rotate32);
    }

    auto pattern_kind_mismatch = bpf_jit_scanner::parse_policy_config_text(
        "version: 3\n"
        "program: mixed-demo\n"
        "sites:\n"
        "  - insn: 4\n"
        "    family: rotate\n"
        "    pattern_kind: mismatch-pattern\n",
        "pattern-kind-mismatch.yaml");
    auto mismatch_result = bpf_jit_scanner::filter_rules_by_policy_detailed(
        summary.rules, pattern_kind_mismatch);
    CHECK_EQ(mismatch_result.rules.size(), 0u);
    CHECK_EQ(mismatch_result.matched_site_count, 0u);
    CHECK_EQ(mismatch_result.unmatched_site_count, 1u);
    CHECK_EQ(mismatch_result.warnings.size(), 1u);
    CHECK(mismatch_result.warnings[0].find(
              "rotate insn 4 pattern_kind mismatch-pattern") !=
          std::string::npos);
}

void test_v5_policy_config_validation()
{
    bool threw = false;
    try {
        static_cast<void>(bpf_jit_scanner::parse_policy_config_text(
            "version: 2\n"
            "default: skip\n"
            "sites: []\n",
            "bad-version.yaml"));
    } catch (const std::runtime_error &) {
        threw = true;
    }
    CHECK(threw);

    threw = false;
    try {
        static_cast<void>(bpf_jit_scanner::parse_policy_config_text(
            "version: 3\n"
            "sites:\n"
            "  - insn: 0\n"
            "    family: cmov\n",
            "missing-pattern-kind.yaml"));
    } catch (const std::runtime_error &) {
        threw = true;
    }
    CHECK(threw);

    threw = false;
    try {
        static_cast<void>(bpf_jit_scanner::parse_policy_config_text(
            "version: 3\n"
            "sites:\n"
            "  - insn: 0\n"
            "    family: not-a-family\n"
            "    pattern_kind: cond-select-64\n",
            "bad.yaml"));
    } catch (const std::runtime_error &) {
        threw = true;
    }
    CHECK(threw);

    threw = false;
    try {
        static_cast<void>(bpf_jit_scanner::parse_policy_config_text(
            "version: 3\n"
            "default: skip\n"
            "sites: []\n",
            "unexpected-default.yaml"));
    } catch (const std::runtime_error &) {
        threw = true;
    }
    CHECK(threw);

    threw = false;
    try {
        static_cast<void>(bpf_jit_scanner::parse_policy_config_text(
            "version: 3\n"
            "families:\n"
            "  cmov: apply\n"
            "sites: []\n",
            "unexpected-families.yaml"));
    } catch (const std::runtime_error &) {
        threw = true;
    }
    CHECK(threw);

    threw = false;
    try {
        static_cast<void>(bpf_jit_scanner::parse_policy_config_text(
            "version: 3\n"
            "sites:\n"
            "  - insn: 0\n"
            "    family: cmov\n"
            "    pattern_kind: cond-select-64\n"
            "    action: apply\n",
            "unexpected-action.yaml"));
    } catch (const std::runtime_error &) {
        threw = true;
    }
    CHECK(threw);

    threw = false;
    try {
        static_cast<void>(bpf_jit_scanner::parse_policy_config_text(
            "version: 3\n"
            "sites:\n"
            "  - insn: 4\n"
            "    family: rotate\n"
            "    pattern_kind: rotate-32\n"
            "  - insn: 4\n"
            "    family: rotate\n"
            "    pattern_kind: rotate-32\n",
            "duplicate-site.yaml"));
    } catch (const std::runtime_error &) {
        threw = true;
    }
    CHECK(threw);
}

void test_v5_policy_parser_golden()
{
    using bpf_jit_scanner::V5Family;
    using bpf_jit_scanner::V5ScanOptions;

    auto mixed = encode({
        {BPF_JEQ_X, regs(0, 1), 2, 0},
        {BPF_MOV64_X, regs(2, 3), 0, 0},
        {BPF_JMP_JA, 0, 1, 0},
        {BPF_MOV64_X, regs(2, 4), 0, 0},
        {BPF_MOV64_X, regs(3, 5), 0, 0},
        {BPF_AND64_X, regs(3, 4), 0, 0},
        {BPF_RSH64_K, regs(3, 0), 0, 28},
        {BPF_MOV64_X, regs(7, 5), 0, 0},
        {BPF_LSH64_K, regs(7, 0), 0, 4},
        {BPF_OR64_X, regs(7, 3), 0, 0},
    });
    auto summary = bpf_jit_scanner::scan_v5_builtin(
        mixed.data(), static_cast<uint32_t>(mixed.size()),
        V5ScanOptions {.scan_cmov = true, .scan_rotate = true});
    CHECK_EQ(summary.rules.size(), 1u);

    const auto golden_dir = golden_policy_dir();

    {
        const auto path = golden_dir / "01-valid-empty.yaml";
        const auto config = bpf_jit_scanner::parse_policy_config_text(
            read_text_file(path), path.string());
        CHECK_EQ(config.version, 3u);
        CHECK(config.program == "mixed-demo");
        CHECK_EQ(config.sites.size(), 0u);
        auto result =
            bpf_jit_scanner::filter_rules_by_policy_detailed(summary.rules, config);
        CHECK_EQ(result.rules.size(), 0u);
        CHECK_EQ(result.matched_site_count, 0u);
        CHECK_EQ(result.unmatched_site_count, 0u);
    }

    {
        const auto path = golden_dir / "02-valid-rotate-only.yaml";
        const auto config = bpf_jit_scanner::parse_policy_config_text(
            read_text_file(path), path.string());
        CHECK(config.program == "mixed-demo");
        CHECK_EQ(config.sites.size(), 1u);
        CHECK_EQ(config.sites[0].family, V5Family::Rotate);
        CHECK(config.sites[0].pattern_kind == "rotate-32");
        auto result =
            bpf_jit_scanner::filter_rules_by_policy_detailed(summary.rules, config);
        CHECK_EQ(result.rules.size(), 0u);
        CHECK_EQ(result.matched_site_count, 0u);
        CHECK_EQ(result.unmatched_site_count, 1u);
        CHECK_EQ(result.warnings.size(), 1u);
    }

    {
        const auto path = golden_dir / "03-valid-both-sites.yaml";
        const auto config = bpf_jit_scanner::parse_policy_config_text(
            read_text_file(path), path.string());
        CHECK_EQ(config.sites.size(), 2u);
        auto result =
            bpf_jit_scanner::filter_rules_by_policy_detailed(summary.rules, config);
        CHECK_EQ(result.rules.size(), 1u);
        CHECK_EQ(result.matched_site_count, 1u);
        CHECK_EQ(result.unmatched_site_count, 1u);
    }

    {
        const auto path = golden_dir / "04-valid-programless-cmov.yaml";
        const auto config = bpf_jit_scanner::parse_policy_config_text(
            read_text_file(path), path.string());
        CHECK(config.program.empty());
        CHECK_EQ(config.sites.size(), 1u);
        CHECK_EQ(config.sites[0].family, V5Family::Cmov);
        CHECK(config.sites[0].pattern_kind == "cond-select-64");
        auto result =
            bpf_jit_scanner::filter_rules_by_policy_detailed(summary.rules, config);
        CHECK_EQ(result.rules.size(), 1u);
        CHECK_EQ(result.rules[0].family, V5Family::Cmov);
    }

    {
        const auto path = golden_dir / "05-valid-rotate-then-cmov.yaml";
        const auto config = bpf_jit_scanner::parse_policy_config_text(
            read_text_file(path), path.string());
        CHECK(config.program == "mixed-demo");
        CHECK_EQ(config.sites.size(), 2u);
        CHECK_EQ(config.sites[0].family, V5Family::Rotate);
        CHECK(config.sites[0].pattern_kind == "rotate-32");
        CHECK_EQ(config.sites[1].family, V5Family::Cmov);
        CHECK(config.sites[1].pattern_kind == "cond-select-64");
        auto result =
            bpf_jit_scanner::filter_rules_by_policy_detailed(summary.rules, config);
        CHECK_EQ(result.rules.size(), 1u);
        CHECK_EQ(result.matched_site_count, 1u);
        CHECK_EQ(result.unmatched_site_count, 1u);
    }

    for (const char *filename : {
             "06-invalid-version-2.yaml",
             "07-invalid-missing-pattern-kind.yaml",
             "08-invalid-duplicate-site.yaml",
             "09-invalid-noncanonical-family.yaml",
             "10-invalid-unknown-site-field.yaml",
         }) {
        bool threw = false;
        try {
            const auto path = golden_dir / filename;
            static_cast<void>(bpf_jit_scanner::parse_policy_config_text(
                read_text_file(path), path.string()));
        } catch (const std::runtime_error &) {
            threw = true;
        }
        CHECK(threw);
    }
}

void test_v5_scan_manifest_json()
{
    using bpf_jit_scanner::V5ProgramInfo;
    using bpf_jit_scanner::V5ScanOptions;

    auto diamond = encode({
        {BPF_JEQ_X, regs(0, 1), 2, 0},
        {BPF_MOV64_X, regs(2, 3), 0, 0},
        {BPF_JMP_JA, 0, 1, 0},
        {BPF_MOV64_X, regs(2, 4), 0, 0},
    });
    auto summary = bpf_jit_scanner::scan_v5_builtin(
        diamond.data(), static_cast<uint32_t>(diamond.size()),
        V5ScanOptions {.scan_cmov = true});

    V5ProgramInfo program = {};
    program.name = "demo-program";
    program.insn_cnt = static_cast<uint32_t>(diamond.size() / 8);
    program.prog_tag = std::array<uint8_t, 8> {
        0xde, 0xad, 0xbe, 0xef, 0x12, 0x34, 0x56, 0x78,
    };

    const auto manifest = bpf_jit_scanner::build_scan_manifest(program, summary);
    const std::string json = bpf_jit_scanner::scan_manifest_to_json(manifest);

    CHECK(json.find("\"name\":\"demo-program\"") != std::string::npos);
    CHECK(json.find("\"prog_tag\":\"deadbeef12345678\"") != std::string::npos);
    CHECK(json.find("\"total_sites\":1") != std::string::npos);
    CHECK(json.find("\"cmov_sites\":1") != std::string::npos);
    CHECK(json.find("\"family\":\"cmov\"") != std::string::npos);
    CHECK(json.find("\"site_id\":\"cmov:0:cond-select-64\"") != std::string::npos);
    CHECK(json.find("\"insn\":0") != std::string::npos);
    CHECK(json.find("\"start_insn\":0") != std::string::npos);
    CHECK(json.find("\"pattern_kind\":\"cond-select-64\"") != std::string::npos);
    CHECK(json.find("\"site_len\":4") != std::string::npos);
    CHECK(json.find("\"canonical_form\":4") != std::string::npos);
    CHECK(json.find("\"native_choice\":1") != std::string::npos);

    const std::string yaml = bpf_jit_scanner::render_policy_v3_yaml(
        program, summary);
    CHECK(yaml.find("version: 3") != std::string::npos);
    CHECK(yaml.find("program: 'demo-program'") != std::string::npos);
    CHECK(yaml.find("insn: 0") != std::string::npos);
    CHECK(yaml.find("family: cmov") != std::string::npos);
    CHECK(yaml.find("pattern_kind: 'cond-select-64'") != std::string::npos);
    CHECK(yaml.find("default:") == std::string::npos);
    CHECK(yaml.find("action:") == std::string::npos);
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
    test_v5_endian_fusion_scan();
    test_v5_branch_flip_scan();
    test_v5_abi_limits();
    test_v5_policy_filter();
    test_v5_policy_config_validation();
    test_v5_policy_parser_golden();
    test_v5_scan_manifest_json();

    std::printf("PASS %d\n", g_pass);
    if (g_fail) {
        std::printf("FAIL %d\n", g_fail);
        return 1;
    }
    return 0;
}
