// SPDX-License-Identifier: MIT

#include "bpf_jit_scanner/engine.hpp"
#include "bpf_jit_scanner/pattern_v5.hpp"
#include "bpf_jit_scanner/policy.h"
#include "bpf_jit_scanner/scanner.h"

#include <cstdio>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <string>
#include <unistd.h>
#include <vector>

using bpf_jit_scanner::DecisionSource;
using bpf_jit_scanner::PatternFamily;
using bpf_jit_scanner::PatternRegistry;
using bpf_jit_scanner::PolicyConfig;
using bpf_jit_scanner::PolicyEngine;
using bpf_jit_scanner::ScanOptions;

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
constexpr uint8_t BPF_JEQ_X = 0x1d;
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
constexpr uint8_t BPF_LDXB = 0x71;
constexpr uint8_t BPF_ADD64_X = 0x0f;

std::string write_temp_policy(const std::string &contents)
{
    const auto path = std::filesystem::temp_directory_path() /
                      ("bpf_jit_scanner_test_" + std::to_string(::getpid()) + ".yaml");
    std::ofstream output(path);
    output << contents;
    output.close();
    return path.string();
}

void test_c_api_scanners()
{
    auto cmov = encode({
        {BPF_JEQ_X, regs(0, 1), 2, 0},
        {BPF_MOV64_X, regs(2, 3), 0, 0},
        {BPF_JMP_JA, 0, 1, 0},
        {BPF_MOV64_X, regs(2, 4), 0, 0},
    });
    auto rotate = encode({
        {BPF_MOV64_X, regs(2, 1), 0, 0},
        {BPF_LSH64_K, regs(1, 0), 0, 17},
        {BPF_RSH64_K, regs(2, 0), 0, 47},
        {BPF_OR64_X, regs(1, 2), 0, 0},
    });
    auto wide = encode({
        {BPF_LDXB, regs(1, 2), 0, 0},
        {BPF_LDXB, regs(3, 2), 1, 0},
        {BPF_LSH64_K, regs(3, 0), 0, 8},
        {BPF_OR64_X, regs(1, 3), 0, 0},
    });
    auto lea = encode({
        {BPF_MOV64_X, regs(2, 3), 0, 0},
        {BPF_LSH64_K, regs(2, 0), 0, 2},
        {BPF_ADD64_X, regs(2, 4), 0, 0},
    });

    bpf_jit_scan_rule rules[8];
    CHECK_EQ(bpf_jit_scan_cmov(cmov.data(), static_cast<uint32_t>(cmov.size()), rules, 8), 1);
    CHECK_EQ(bpf_jit_scan_rotate(rotate.data(), static_cast<uint32_t>(rotate.size()),
                                 false, rules, 8), 1);
    CHECK_EQ(bpf_jit_scan_wide_mem(wide.data(), static_cast<uint32_t>(wide.size()), rules, 8), 1);
    CHECK_EQ(bpf_jit_scan_addr_calc(lea.data(), static_cast<uint32_t>(lea.size()), rules, 8), 1);
}

void test_engine_static_cmov_policy()
{
    PolicyEngine engine;

    auto simple = encode({
        {BPF_JEQ_X, regs(0, 1), 2, 0},
        {BPF_MOV64_X, regs(2, 3), 0, 0},
        {BPF_JMP_JA, 0, 1, 0},
        {BPF_MOV64_X, regs(2, 4), 0, 0},
    });
    auto simple_report = engine.scan(simple.data(), static_cast<uint32_t>(simple.size()),
                                     ScanOptions {.families = {"cmov"}});
    auto simple_decisions = engine.decide(simple_report, "simple_case");
    CHECK_EQ(simple_decisions.size(), 1u);
    CHECK_EQ(simple_decisions[0].native_choice, static_cast<uint32_t>(BPF_JIT_SEL_BRANCH));
    CHECK_EQ(simple_decisions[0].source, DecisionSource::StaticHeuristic);

    auto looped = encode({
        {BPF_JEQ_X, regs(0, 1), 2, 0},
        {BPF_MOV64_X, regs(2, 3), 0, 0},
        {BPF_JMP_JA, 0, 1, 0},
        {BPF_MOV64_X, regs(2, 4), 0, 0},
        {BPF_JEQ_X, regs(5, 6), 0, 0},
        {BPF_JMP_JA, 0, -6, 0},
    });
    auto loop_report = engine.scan(looped.data(), static_cast<uint32_t>(looped.size()),
                                   ScanOptions {.families = {"cmov"}});
    auto loop_decisions = engine.decide(loop_report, "loop_case");
    CHECK_EQ(loop_decisions.size(), 1u);
    CHECK_EQ(loop_decisions[0].native_choice, static_cast<uint32_t>(BPF_JIT_SEL_CMOVCC));
}

void test_config_defaults_and_overrides()
{
    const std::string path = write_temp_policy(
        "default_cmov: branch\n"
        "overrides:\n"
        "  - program: \"hot_*\"\n"
        "    cmov: cmovcc\n");
    PolicyConfig config = PolicyConfig::parse_file(path);
    std::filesystem::remove(path);

    PolicyEngine engine(PatternRegistry::builtin(), config);
    auto code = encode({
        {BPF_JEQ_X, regs(0, 1), 2, 0},
        {BPF_MOV64_X, regs(2, 3), 0, 0},
        {BPF_JMP_JA, 0, 1, 0},
        {BPF_MOV64_X, regs(2, 4), 0, 0},
    });
    auto report = engine.scan(code.data(), static_cast<uint32_t>(code.size()),
                              ScanOptions {.families = {"cmov"}});

    auto cold = engine.decide(report, "cold_program");
    CHECK_EQ(cold[0].native_choice, static_cast<uint32_t>(BPF_JIT_SEL_BRANCH));
    CHECK_EQ(cold[0].source, DecisionSource::ConfigDefault);

    auto hot = engine.decide(report, "hot_program");
    CHECK_EQ(hot[0].native_choice, static_cast<uint32_t>(BPF_JIT_SEL_CMOVCC));
    CHECK_EQ(hot[0].source, DecisionSource::ConfigOverride);
}

void test_profile_placeholder_fallback()
{
    const std::string path = write_temp_policy("default_cmov: profile\n");
    PolicyConfig config = PolicyConfig::parse_file(path);
    std::filesystem::remove(path);

    PolicyEngine engine(PatternRegistry::builtin(), config);
    auto code = encode({
        {BPF_JEQ_X, regs(0, 1), 2, 0},
        {BPF_MOV64_X, regs(2, 3), 0, 0},
        {BPF_JMP_JA, 0, 1, 0},
        {BPF_MOV64_X, regs(2, 4), 0, 0},
    });
    auto report = engine.scan(code.data(), static_cast<uint32_t>(code.size()),
                              ScanOptions {.families = {"cmov"}});
    auto decisions = engine.decide(report, "profile_case");
    CHECK_EQ(decisions[0].source, DecisionSource::ProfileFallback);
    CHECK_EQ(decisions[0].native_choice, static_cast<uint32_t>(BPF_JIT_SEL_BRANCH));
}

void test_rotate_config_sets_bmi2()
{
    const std::string path = write_temp_policy("default_rotate: rorx\n");
    PolicyConfig config = PolicyConfig::parse_file(path);
    std::filesystem::remove(path);

    PolicyEngine engine(PatternRegistry::builtin(), config);
    auto code = encode({
        {BPF_MOV32_X, regs(2, 1), 0, 0},
        {BPF_LSH32_K, regs(1, 0), 0, 8},
        {BPF_RSH32_K, regs(2, 0), 0, 24},
        {BPF_OR32_X, regs(1, 2), 0, 0},
    });
    auto report = engine.scan(code.data(), static_cast<uint32_t>(code.size()),
                              ScanOptions {.families = {"rotate"}});
    auto decisions = engine.decide(report, "rotate_case");
    auto rules = engine.materialize(decisions);
    CHECK_EQ(rules.size(), 1u);
    CHECK_EQ(rules[0].native_choice, static_cast<uint32_t>(BPF_JIT_ROT_RORX));
    CHECK_EQ(rules[0].cpu_features_required, static_cast<uint32_t>(BPF_JIT_X86_BMI2));
}

void test_overlap_resolution()
{
    PatternRegistry registry = PatternRegistry::builtin();
    registry.register_family(PatternFamily {
        .name = "synthetic-rotate",
        .rule_kind = BPF_JIT_RK_ROTATE,
        .arbitration_priority = 999,
        .scanner = [](const uint8_t *, uint32_t, const ScanOptions &) {
            return std::vector<bpf_jit_scan_rule> {{
                .site_start = 0,
                .site_len = 4,
                .rule_kind = BPF_JIT_RK_ROTATE,
                .native_choice = BPF_JIT_ROT_ROR,
                .cpu_features_required = 0,
                .priority = 0,
            }};
        },
    });

    PolicyEngine engine(registry, {});
    auto code = encode({
        {BPF_JEQ_X, regs(0, 1), 2, 0},
        {BPF_MOV64_X, regs(2, 3), 0, 0},
        {BPF_JMP_JA, 0, 1, 0},
        {BPF_MOV64_X, regs(2, 4), 0, 0},
    });
    auto report = engine.scan(code.data(), static_cast<uint32_t>(code.size()),
                              ScanOptions {.families = {"cmov", "synthetic-rotate"}});
    CHECK_EQ(report.raw_sites.size(), 2u);
    CHECK_EQ(report.merged_sites.size(), 1u);
    CHECK_EQ(report.conflicts.size(), 1u);
    CHECK(report.merged_sites[0].family == "synthetic-rotate");
}

void test_policy_blob_build_and_patch()
{
    bpf_jit_scan_rule rule = {};
    rule.site_start = 5;
    rule.site_len = 4;
    rule.rule_kind = BPF_JIT_RK_COND_SELECT;
    rule.native_choice = BPF_JIT_SEL_CMOVCC;

    uint8_t tag[8] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88};
    uint8_t *blob = nullptr;
    uint32_t blob_len = 0;

    CHECK_EQ(bpf_jit_build_policy_blob(&rule, 1, 100, tag, &blob, &blob_len), 0);
    CHECK(blob != nullptr);
    CHECK_EQ(blob_len, 48u);

    if (blob) {
        uint32_t insn_cnt = 0;
        std::memcpy(&insn_cnt, blob + 16, sizeof(insn_cnt));
        CHECK_EQ(insn_cnt, 100u);

        uint8_t new_tag[8] = {0xaa, 0xbb, 0xcc};
        CHECK_EQ(bpf_jit_patch_policy_blob(blob, blob_len, 200, new_tag), 0);
        std::memcpy(&insn_cnt, blob + 16, sizeof(insn_cnt));
        CHECK_EQ(insn_cnt, 200u);
        bpf_jit_free_policy_blob(blob);
    }
}

void test_v5_cmov_scan_and_blob()
{
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
    bpf_jit_scanner::V5RuleWire wire_rule = {};
    std::memcpy(&version, blob.data() + 4, sizeof(version));
    std::memcpy(&rule_cnt, blob.data() + 12, sizeof(rule_cnt));
    std::memcpy(&wire_rule, blob.data() + 32, sizeof(wire_rule));
    CHECK_EQ(version, static_cast<uint16_t>(BPF_JIT_POLICY_VERSION_2));
    CHECK_EQ(rule_cnt, 1u);
    CHECK_EQ(wire_rule.binding_count,
             static_cast<uint16_t>(diamond_summary.rules[0].bindings.size()));
}

} // namespace

int main()
{
    test_c_api_scanners();
    test_engine_static_cmov_policy();
    test_config_defaults_and_overrides();
    test_profile_placeholder_fallback();
    test_rotate_config_sets_bmi2();
    test_overlap_resolution();
    test_policy_blob_build_and_patch();
    test_v5_cmov_scan_and_blob();

    std::printf("\n%s: %d passed, %d failed\n",
                g_fail == 0 ? "OK" : "FAIL", g_pass, g_fail);
    return g_fail == 0 ? 0 : 1;
}
