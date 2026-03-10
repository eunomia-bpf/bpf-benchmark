// SPDX-License-Identifier: MIT

#include "bpf_jit_scanner/engine.hpp"

#include "bpf_jit_scanner/scanner.h"

#include <algorithm>
#include <cerrno>
#include <cctype>
#include <cstring>
#include <fstream>
#include <functional>
#include <optional>
#include <sstream>
#include <stdexcept>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

#include <fnmatch.h>

namespace bpf_jit_scanner {
namespace {

struct bpf_insn_raw {
    uint8_t code;
    uint8_t regs;
    int16_t off;
    int32_t imm;
};

constexpr uint8_t BPF_CLASS_MASK = 0x07;
constexpr uint8_t BPF_JMP = 0x05;
constexpr uint8_t BPF_JMP32 = 0x06;
constexpr uint8_t BPF_ALU = 0x04;
constexpr uint8_t BPF_ALU64 = 0x07;
constexpr uint8_t BPF_SRC_X = 0x08;
constexpr uint8_t BPF_MOV_OP = 0xb0;

std::string trim(std::string value)
{
    const auto first = value.find_first_not_of(" \t\r\n");
    if (first == std::string::npos) {
        return {};
    }
    const auto last = value.find_last_not_of(" \t\r\n");
    return value.substr(first, last - first + 1);
}

std::string strip_quotes(std::string value)
{
    value = trim(std::move(value));
    if (value.size() >= 2 &&
        ((value.front() == '"' && value.back() == '"') ||
         (value.front() == '\'' && value.back() == '\''))) {
        return value.substr(1, value.size() - 2);
    }
    return value;
}

std::string strip_comment(const std::string &line)
{
    bool in_single = false;
    bool in_double = false;

    for (size_t i = 0; i < line.size(); ++i) {
        const char ch = line[i];
        if (ch == '\'' && !in_double) {
            in_single = !in_single;
            continue;
        }
        if (ch == '"' && !in_single) {
            in_double = !in_double;
            continue;
        }
        if (ch == '#' && !in_single && !in_double) {
            return line.substr(0, i);
        }
    }
    return line;
}

std::string lower_ascii(std::string value)
{
    for (char &ch : value) {
        ch = static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
    }
    return value;
}

std::string canonical_family_name(std::string_view value)
{
    std::string normalized;
    normalized.reserve(value.size());
    for (char ch : value) {
        if (ch == '_') {
            normalized.push_back('-');
        } else {
            normalized.push_back(static_cast<char>(
                std::tolower(static_cast<unsigned char>(ch))));
        }
    }

    if (normalized == "cond-select") {
        return "cmov";
    }
    if (normalized == "wide" || normalized == "wide-mem") {
        return "wide-mem";
    }
    if (normalized == "addr-calc" || normalized == "addrcalc") {
        return "lea";
    }
    return normalized;
}

std::optional<std::pair<std::string, std::string>>
split_key_value(const std::string &line)
{
    const auto pos = line.find(':');
    if (pos == std::string::npos) {
        return std::nullopt;
    }
    return std::make_pair(trim(line.substr(0, pos)), trim(line.substr(pos + 1)));
}

void parse_insns(const uint8_t *xlated, uint32_t len, std::vector<bpf_insn_raw> &insns)
{
    insns.resize(len / 8);
    for (uint32_t i = 0; i < len / 8; ++i) {
        std::memcpy(&insns[i], xlated + i * 8, sizeof(bpf_insn_raw));
    }
}

bool is_cond_jump_raw(const bpf_insn_raw &insn)
{
    const uint8_t cls = insn.code & BPF_CLASS_MASK;
    if (cls != BPF_JMP && cls != BPF_JMP32) {
        return false;
    }

    switch (insn.code & 0xf0) {
    case 0x10:
    case 0x20:
    case 0x30:
    case 0x50:
    case 0x60:
    case 0x70:
    case 0xa0:
    case 0xb0:
    case 0xc0:
    case 0xd0:
        return true;
    default:
        return false;
    }
}

bool is_jump_raw(const bpf_insn_raw &insn)
{
    const uint8_t cls = insn.code & BPF_CLASS_MASK;
    return cls == BPF_JMP || cls == BPF_JMP32;
}

bool is_simple_mov_raw(const bpf_insn_raw &insn)
{
    const uint8_t cls = insn.code & BPF_CLASS_MASK;
    if (cls != BPF_ALU && cls != BPF_ALU64) {
        return false;
    }
    if ((insn.code & 0xf0) != BPF_MOV_OP || insn.off != 0) {
        return false;
    }

    if ((insn.code & BPF_SRC_X) == BPF_SRC_X) {
        return insn.imm == 0;
    }
    return (insn.regs >> 4) == 0;
}

bool is_imm_move(const bpf_insn_raw &insn)
{
    return is_simple_mov_raw(insn) && ((insn.code & BPF_SRC_X) == 0);
}

template <typename Fn>
std::vector<bpf_jit_scan_rule> run_scan(uint32_t max_rules, Fn &&fn)
{
    std::vector<bpf_jit_scan_rule> rules(max_rules);
    int rc = fn(rules.data(), max_rules);
    if (rc < 0) {
        throw std::runtime_error("scan failed with errno " + std::to_string(-rc));
    }
    rules.resize(static_cast<size_t>(rc));
    return rules;
}

uint32_t arbitration_priority_for_kind(uint32_t rule_kind)
{
    switch (rule_kind) {
    case BPF_JIT_RK_ROTATE:
        return 400;
    case BPF_JIT_RK_WIDE_MEM:
        return 300;
    case BPF_JIT_RK_ADDR_CALC:
        return 200;
    case BPF_JIT_RK_COND_SELECT:
        return 100;
    default:
        return 0;
    }
}

bool overlaps(const CandidateSite &lhs, const CandidateSite &rhs)
{
    const uint32_t lhs_end = lhs.rule.site_start + lhs.rule.site_len;
    const uint32_t rhs_end = rhs.rule.site_start + rhs.rule.site_len;
    return lhs.rule.site_start < rhs_end && rhs.rule.site_start < lhs_end;
}

std::tuple<uint32_t, uint32_t, int32_t, uint32_t> candidate_rank(const CandidateSite &site)
{
    return std::make_tuple(site.arbitration_priority,
                           site.rule.site_len,
                           -static_cast<int32_t>(site.rule.site_start),
                           site.rule.rule_kind);
}

bool better_candidate(const CandidateSite &lhs, const CandidateSite &rhs)
{
    return candidate_rank(lhs) > candidate_rank(rhs);
}

int32_t estimate_code_delta(const bpf_jit_scan_rule &rule)
{
    switch (rule.rule_kind) {
    case BPF_JIT_RK_COND_SELECT:
        return 4;
    case BPF_JIT_RK_WIDE_MEM:
        return -static_cast<int32_t>(rule.site_len * 2);
    case BPF_JIT_RK_ROTATE:
        return rule.native_choice == BPF_JIT_ROT_RORX ? -4 : -3;
    case BPF_JIT_RK_ADDR_CALC:
        return -6;
    default:
        return 0;
    }
}

bool operand_is_imm(const std::vector<bpf_insn_raw> &insns, const bpf_jit_scan_rule &rule)
{
    if (rule.rule_kind != BPF_JIT_RK_COND_SELECT) {
        return false;
    }

    const uint32_t start = rule.site_start;
    const uint32_t end = std::min<uint32_t>(start + rule.site_len, insns.size());
    for (uint32_t i = start; i < end; ++i) {
        if (is_imm_move(insns[i])) {
            return true;
        }
    }
    return false;
}

uint32_t compute_loop_depth(const std::vector<bpf_insn_raw> &insns,
                            const bpf_jit_scan_rule &rule)
{
    uint32_t depth = 0;
    const uint32_t site_start = rule.site_start;
    const uint32_t site_end = rule.site_start + rule.site_len - 1;

    for (uint32_t i = 0; i < insns.size(); ++i) {
        if (!is_jump_raw(insns[i]) || insns[i].off >= 0) {
            continue;
        }

        const int64_t target = static_cast<int64_t>(i) + 1 + insns[i].off;
        if (target < 0 || target >= static_cast<int64_t>(insns.size())) {
            continue;
        }
        if (static_cast<uint32_t>(target) <= site_start && site_end <= i) {
            ++depth;
        }
    }

    return depth;
}

double compute_branch_density(const std::vector<bpf_insn_raw> &insns,
                              const bpf_jit_scan_rule &rule)
{
    if (insns.empty()) {
        return 0.0;
    }

    const uint32_t window_before = 8;
    const uint32_t window_after = 8;
    const uint32_t start = (rule.site_start > window_before)
                               ? (rule.site_start - window_before)
                               : 0;
    const uint32_t end = std::min<uint32_t>(insns.size(),
                                            rule.site_start + rule.site_len + window_after);

    uint32_t branches = 0;
    for (uint32_t i = start; i < end; ++i) {
        if (is_cond_jump_raw(insns[i])) {
            ++branches;
        }
    }

    const uint32_t window_size = end - start;
    return window_size == 0 ? 0.0
                            : static_cast<double>(branches) / static_cast<double>(window_size);
}

uint32_t compute_nearby_site_count(const std::vector<bpf_jit_scan_rule> &all_rules,
                                   const bpf_jit_scan_rule &rule)
{
    uint32_t count = 0;
    for (const auto &other : all_rules) {
        if (other.site_start == rule.site_start &&
            other.site_len == rule.site_len &&
            other.rule_kind == rule.rule_kind) {
            continue;
        }
        const uint32_t delta = (other.site_start > rule.site_start)
                                   ? (other.site_start - rule.site_start)
                                   : (rule.site_start - other.site_start);
        if (delta <= 16) {
            ++count;
        }
    }
    return count;
}

SiteFeatures extract_features(const std::vector<bpf_insn_raw> &insns,
                              const std::vector<bpf_jit_scan_rule> &all_rules,
                              const bpf_jit_scan_rule &rule)
{
    SiteFeatures features = {};
    features.site_start = rule.site_start;
    features.site_len = rule.site_len;
    features.rule_kind = rule.rule_kind;
    features.loop_depth = compute_loop_depth(insns, rule);
    features.branch_density = compute_branch_density(insns, rule);
    features.nearby_site_count = compute_nearby_site_count(all_rules, rule);
    features.estimated_code_delta = estimate_code_delta(rule);
    features.operand_is_imm = operand_is_imm(insns, rule);
    return features;
}

ProgramFeatures build_program_features(uint32_t insn_count,
                                       const std::vector<bpf_jit_scan_rule> &all_rules)
{
    ProgramFeatures features = {};
    features.insn_count = insn_count;
    for (const auto &rule : all_rules) {
        if (rule.rule_kind < features.candidate_count.size()) {
            ++features.candidate_count[rule.rule_kind];
        }
    }
    return features;
}

Preference parse_choice_value(const std::string &family_key, std::string value)
{
    value = lower_ascii(strip_quotes(std::move(value)));
    const std::string canonical_family = canonical_family_name(family_key);

    if (value == "profile") {
        return Preference::Profile;
    }
    if (value == "skip") {
        return Preference::Skip;
    }

    if (canonical_family == "cmov") {
        if (value == "branch") {
            return Preference::Branch;
        }
        if (value == "cmovcc" || value == "cmov") {
            return Preference::Cmovcc;
        }
    } else if (canonical_family == "rotate") {
        if (value == "ror") {
            return Preference::Ror;
        }
        if (value == "rorx") {
            return Preference::Rorx;
        }
    } else if (canonical_family == "wide-mem") {
        if (value == "wide" || value == "wide-load") {
            return Preference::Wide;
        }
    } else if (canonical_family == "lea") {
        if (value == "lea") {
            return Preference::Lea;
        }
    }

    throw std::runtime_error("unsupported value '" + value + "' for " + family_key);
}

std::optional<Preference> *preference_slot(FamilyPreferences &prefs, std::string_view key)
{
    const std::string canonical = canonical_family_name(key);
    if (canonical == "cmov") {
        return &prefs.cmov;
    }
    if (canonical == "rotate") {
        return &prefs.rotate;
    }
    if (canonical == "wide-mem") {
        return &prefs.wide_mem;
    }
    if (canonical == "lea") {
        return &prefs.lea;
    }
    return nullptr;
}

const std::optional<Preference> *preference_slot(const FamilyPreferences &prefs,
                                                 uint32_t rule_kind)
{
    switch (rule_kind) {
    case BPF_JIT_RK_COND_SELECT:
        return &prefs.cmov;
    case BPF_JIT_RK_ROTATE:
        return &prefs.rotate;
    case BPF_JIT_RK_WIDE_MEM:
        return &prefs.wide_mem;
    case BPF_JIT_RK_ADDR_CALC:
        return &prefs.lea;
    default:
        return nullptr;
    }
}

std::pair<uint32_t, std::string> default_static_choice(const CandidateSite &site)
{
    switch (site.rule.rule_kind) {
    case BPF_JIT_RK_COND_SELECT: {
        unsigned score = 0;
        if (site.features.loop_depth > 0) {
            score += 2;
        }
        if (site.features.branch_density >= 0.20) {
            score += 1;
        }
        if (site.features.nearby_site_count >= 2) {
            score += 1;
        }
        if (score >= 2) {
            std::ostringstream rationale;
            rationale << "static heuristic prefers cmovcc"
                      << " (loop_depth=" << site.features.loop_depth
                      << ", branch_density=" << site.features.branch_density
                      << ", nearby_sites=" << site.features.nearby_site_count << ")";
            return {BPF_JIT_SEL_CMOVCC, rationale.str()};
        }

        std::ostringstream rationale;
        rationale << "static heuristic keeps branch"
                  << " (loop_depth=" << site.features.loop_depth
                  << ", branch_density=" << site.features.branch_density
                  << ", nearby_sites=" << site.features.nearby_site_count << ")";
        return {BPF_JIT_SEL_BRANCH, rationale.str()};
    }
    case BPF_JIT_RK_ROTATE:
        return {site.rule.native_choice,
                site.rule.native_choice == BPF_JIT_ROT_RORX
                    ? "static heuristic uses RORX because the scan requested BMI2 lowering"
                    : "static heuristic uses canonical rotate lowering"};
    case BPF_JIT_RK_WIDE_MEM:
        return {BPF_JIT_WMEM_WIDE_LOAD,
                "static heuristic fuses byte ladders into wide loads"};
    case BPF_JIT_RK_ADDR_CALC:
        return {BPF_JIT_ACALC_LEA,
                "static heuristic enables LEA fusion"};
    default:
        return {site.rule.native_choice, "static heuristic keeps scan-native choice"};
    }
}

std::optional<uint32_t> choice_for_preference(const CandidateSite &site, Preference preference)
{
    switch (site.rule.rule_kind) {
    case BPF_JIT_RK_COND_SELECT:
        if (preference == Preference::Branch) {
            return BPF_JIT_SEL_BRANCH;
        }
        if (preference == Preference::Cmovcc) {
            return BPF_JIT_SEL_CMOVCC;
        }
        break;
    case BPF_JIT_RK_ROTATE:
        if (preference == Preference::Ror) {
            return BPF_JIT_ROT_ROR;
        }
        if (preference == Preference::Rorx) {
            return BPF_JIT_ROT_RORX;
        }
        break;
    case BPF_JIT_RK_WIDE_MEM:
        if (preference == Preference::Wide) {
            return BPF_JIT_WMEM_WIDE_LOAD;
        }
        break;
    case BPF_JIT_RK_ADDR_CALC:
        if (preference == Preference::Lea) {
            return BPF_JIT_ACALC_LEA;
        }
        break;
    default:
        break;
    }
    return std::nullopt;
}

bool matches_program(const PolicyOverride &override_rule, std::string_view program_name)
{
    if (override_rule.program_glob.empty() || program_name.empty()) {
        return false;
    }
    return fnmatch(override_rule.program_glob.c_str(),
                   std::string(program_name).c_str(), 0) == 0;
}

} // namespace

PolicyConfig PolicyConfig::parse_file(const std::string &path)
{
    std::ifstream input(path);
    if (!input) {
        throw std::runtime_error("unable to open policy file: " + path);
    }

    PolicyConfig config;
    std::optional<PolicyOverride> current_override;
    bool in_overrides = false;
    std::string line;

    while (std::getline(input, line)) {
        line = trim(strip_comment(line));
        if (line.empty()) {
            continue;
        }

        if (line == "overrides:") {
            if (current_override) {
                config.overrides.push_back(*current_override);
                current_override.reset();
            }
            in_overrides = true;
            continue;
        }

        if (in_overrides && line.rfind("- ", 0) == 0) {
            if (current_override) {
                config.overrides.push_back(*current_override);
            }
            current_override = PolicyOverride {};
            line = trim(line.substr(2));
            if (line.empty()) {
                continue;
            }
        }

        const auto kv = split_key_value(line);
        if (!kv) {
            throw std::runtime_error("invalid policy line: " + line);
        }

        const std::string key = lower_ascii(kv->first);
        const std::string value = kv->second;

        if (!in_overrides) {
            if (key.rfind("default_", 0) != 0) {
                throw std::runtime_error("unsupported top-level key: " + key);
            }
            auto *slot = preference_slot(config.defaults, key.substr(8));
            if (!slot) {
                throw std::runtime_error("unsupported default key: " + key);
            }
            *slot = parse_choice_value(key.substr(8), value);
            continue;
        }

        if (!current_override) {
            current_override = PolicyOverride {};
        }
        if (key == "program") {
            current_override->program_glob = strip_quotes(value);
            continue;
        }

        auto *slot = preference_slot(current_override->choices, key);
        if (!slot) {
            throw std::runtime_error("unsupported override key: " + key);
        }
        *slot = parse_choice_value(key, value);
    }

    if (current_override) {
        config.overrides.push_back(*current_override);
    }

    return config;
}

void PatternRegistry::register_family(PatternFamily family)
{
    const std::string key = canonical_family_name(family.name);
    auto it = std::find_if(families_.begin(), families_.end(),
                           [&](const PatternFamily &existing) {
                               return canonical_family_name(existing.name) == key;
                           });
    if (it == families_.end()) {
        families_.push_back(std::move(family));
    } else {
        *it = std::move(family);
    }
}

const std::vector<PatternFamily> &PatternRegistry::families() const
{
    return families_;
}

const PatternFamily *PatternRegistry::find_family(std::string_view name) const
{
    const std::string key = canonical_family_name(name);
    auto it = std::find_if(families_.begin(), families_.end(),
                           [&](const PatternFamily &family) {
                               return canonical_family_name(family.name) == key;
                           });
    return it == families_.end() ? nullptr : &*it;
}

PatternRegistry PatternRegistry::builtin()
{
    PatternRegistry registry;
    registry.register_family({
        .name = "cmov",
        .rule_kind = BPF_JIT_RK_COND_SELECT,
        .arbitration_priority = arbitration_priority_for_kind(BPF_JIT_RK_COND_SELECT),
        .scanner = [](const uint8_t *xlated, uint32_t len, const ScanOptions &options) {
            return run_scan(options.max_rules_per_family,
                            [&](bpf_jit_scan_rule *rules, uint32_t max_rules) {
                                return bpf_jit_scan_cmov(xlated, len, rules, max_rules);
                            });
        },
    });
    registry.register_family({
        .name = "wide-mem",
        .rule_kind = BPF_JIT_RK_WIDE_MEM,
        .arbitration_priority = arbitration_priority_for_kind(BPF_JIT_RK_WIDE_MEM),
        .scanner = [](const uint8_t *xlated, uint32_t len, const ScanOptions &options) {
            return run_scan(options.max_rules_per_family,
                            [&](bpf_jit_scan_rule *rules, uint32_t max_rules) {
                                return bpf_jit_scan_wide_mem(xlated, len, rules, max_rules);
                            });
        },
    });
    registry.register_family({
        .name = "rotate",
        .rule_kind = BPF_JIT_RK_ROTATE,
        .arbitration_priority = arbitration_priority_for_kind(BPF_JIT_RK_ROTATE),
        .scanner = [](const uint8_t *xlated, uint32_t len, const ScanOptions &options) {
            return run_scan(options.max_rules_per_family,
                            [&](bpf_jit_scan_rule *rules, uint32_t max_rules) {
                                return bpf_jit_scan_rotate(xlated, len, options.use_rorx,
                                                           rules, max_rules);
                            });
        },
    });
    registry.register_family({
        .name = "lea",
        .rule_kind = BPF_JIT_RK_ADDR_CALC,
        .arbitration_priority = arbitration_priority_for_kind(BPF_JIT_RK_ADDR_CALC),
        .scanner = [](const uint8_t *xlated, uint32_t len, const ScanOptions &options) {
            return run_scan(options.max_rules_per_family,
                            [&](bpf_jit_scan_rule *rules, uint32_t max_rules) {
                                return bpf_jit_scan_addr_calc(xlated, len, rules, max_rules);
                            });
        },
    });
    return registry;
}

PolicyEngine::PolicyEngine(PatternRegistry registry, PolicyConfig config)
    : registry_(std::move(registry)), config_(std::move(config))
{
}

void PolicyEngine::set_profile_provider(std::shared_ptr<const ProfileProvider> provider)
{
    profile_provider_ = std::move(provider);
}

const PatternRegistry &PolicyEngine::registry() const
{
    return registry_;
}

const PolicyConfig &PolicyEngine::config() const
{
    return config_;
}

ScanReport PolicyEngine::scan(const uint8_t *xlated, uint32_t len, const ScanOptions &options) const
{
    if (!xlated || len % 8 != 0) {
        throw std::invalid_argument("xlated bytecode must be non-null and 8-byte aligned");
    }

    std::vector<const PatternFamily *> selected_families;
    if (options.families.empty()) {
        for (const auto &family : registry_.families()) {
            selected_families.push_back(&family);
        }
    } else {
        for (const auto &requested : options.families) {
            const PatternFamily *family = registry_.find_family(requested);
            if (!family) {
                throw std::invalid_argument("unknown pattern family: " + requested);
            }
            selected_families.push_back(family);
        }
    }

    std::vector<bpf_jit_scan_rule> flat_rules;
    std::vector<CandidateSite> raw_sites;

    for (const PatternFamily *family : selected_families) {
        auto rules = family->scanner(xlated, len, options);
        flat_rules.insert(flat_rules.end(), rules.begin(), rules.end());
        for (auto &rule : rules) {
            raw_sites.push_back({
                .rule = rule,
                .family = family->name,
                .arbitration_priority = family->arbitration_priority,
            });
        }
    }

    std::vector<bpf_insn_raw> insns;
    parse_insns(xlated, len, insns);

    ScanReport report = {};
    report.program_features = build_program_features(static_cast<uint32_t>(insns.size()),
                                                     flat_rules);

    for (size_t i = 0; i < raw_sites.size(); ++i) {
        raw_sites[i].features = extract_features(insns, flat_rules, raw_sites[i].rule);
    }
    report.raw_sites = raw_sites;

    std::vector<size_t> order(raw_sites.size());
    for (size_t i = 0; i < raw_sites.size(); ++i) {
        order[i] = i;
    }
    std::sort(order.begin(), order.end(),
              [&](size_t lhs, size_t rhs) {
                  if (better_candidate(raw_sites[lhs], raw_sites[rhs])) {
                      return true;
                  }
                  if (better_candidate(raw_sites[rhs], raw_sites[lhs])) {
                      return false;
                  }
                  return lhs < rhs;
              });

    std::vector<size_t> accepted_indices;
    for (size_t index : order) {
        bool rejected = false;
        for (size_t accepted : accepted_indices) {
            if (!overlaps(raw_sites[index], raw_sites[accepted])) {
                continue;
            }
            report.conflicts.push_back({
                .winner = raw_sites[accepted],
                .loser = raw_sites[index],
                .reason = "overlapping site rejected by arbitration",
            });
            rejected = true;
            break;
        }
        if (!rejected) {
            accepted_indices.push_back(index);
        }
    }

    std::sort(accepted_indices.begin(), accepted_indices.end(),
              [&](size_t lhs, size_t rhs) {
                  return raw_sites[lhs].rule.site_start < raw_sites[rhs].rule.site_start;
              });
    report.merged_sites.reserve(accepted_indices.size());
    for (size_t index : accepted_indices) {
        report.merged_sites.push_back(raw_sites[index]);
    }

    return report;
}

std::vector<PolicyDecision> PolicyEngine::decide(const ScanReport &report,
                                                 std::string_view program_name) const
{
    std::vector<PolicyDecision> decisions;
    decisions.reserve(report.merged_sites.size());

    for (const auto &site : report.merged_sites) {
        const auto [static_choice, static_rationale] = default_static_choice(site);
        PolicyDecision static_decision = {
            .site = site,
            .emit_rule = true,
            .native_choice = static_choice,
            .source = DecisionSource::StaticHeuristic,
            .rationale = static_rationale,
        };
        PolicyDecision decision = static_decision;

        auto apply_preference = [&](Preference preference,
                                    DecisionSource source,
                                    const std::string &label) {
            if (preference == Preference::Profile) {
                if (profile_provider_) {
                    auto profiled = profile_provider_->decide(site, report.program_features);
                    if (profiled) {
                        profiled->site = site;
                        profiled->source = DecisionSource::ProfileProvider;
                        if (profiled->rationale.empty()) {
                            profiled->rationale = label + " selected profile-guided decision";
                        }
                        decision = *profiled;
                        return;
                    }
                }
                decision = static_decision;
                decision.source = DecisionSource::ProfileFallback;
                decision.rationale = label + " requested profile guidance, but no provider "
                                     "decision was available; " + static_decision.rationale;
                return;
            }

            if (preference == Preference::Skip) {
                decision.emit_rule = false;
                decision.native_choice = 0;
                decision.source = source;
                decision.rationale = label + " selected skip";
                return;
            }

            const auto native_choice = choice_for_preference(site, preference);
            if (!native_choice) {
                throw std::runtime_error("invalid preference for " + site.family);
            }
            decision.emit_rule = true;
            decision.native_choice = *native_choice;
            decision.source = source;
            decision.rationale = label + " selected "
                                 + native_choice_name(site.rule.rule_kind, *native_choice);
        };

        if (const auto *default_pref = preference_slot(config_.defaults, site.rule.rule_kind);
            default_pref && default_pref->has_value()) {
            apply_preference(**default_pref, DecisionSource::ConfigDefault,
                             "config default");
        }

        for (const auto &override_rule : config_.overrides) {
            if (!matches_program(override_rule, program_name)) {
                continue;
            }
            if (const auto *override_pref = preference_slot(override_rule.choices,
                                                            site.rule.rule_kind);
                override_pref && override_pref->has_value()) {
                apply_preference(**override_pref, DecisionSource::ConfigOverride,
                                 "config override '" + override_rule.program_glob + "'");
            }
        }

        decisions.push_back(std::move(decision));
    }

    return decisions;
}

std::vector<bpf_jit_scan_rule> PolicyEngine::materialize(
    const std::vector<PolicyDecision> &decisions) const
{
    std::vector<bpf_jit_scan_rule> rules;
    rules.reserve(decisions.size());

    for (const auto &decision : decisions) {
        if (!decision.emit_rule) {
            continue;
        }

        bpf_jit_scan_rule rule = decision.site.rule;
        rule.native_choice = decision.native_choice;
        rule.priority = decision.site.arbitration_priority;

        if (rule.rule_kind == BPF_JIT_RK_ROTATE &&
            rule.native_choice == BPF_JIT_ROT_RORX) {
            rule.cpu_features_required = BPF_JIT_X86_BMI2;
        } else {
            rule.cpu_features_required = 0;
        }

        rules.push_back(rule);
    }

    std::sort(rules.begin(), rules.end(),
              [](const bpf_jit_scan_rule &lhs, const bpf_jit_scan_rule &rhs) {
                  return lhs.site_start < rhs.site_start;
              });
    return rules;
}

std::string rule_kind_name(uint32_t rule_kind)
{
    switch (rule_kind) {
    case BPF_JIT_RK_COND_SELECT:
        return "COND_SELECT";
    case BPF_JIT_RK_WIDE_MEM:
        return "WIDE_MEM";
    case BPF_JIT_RK_ROTATE:
        return "ROTATE";
    case BPF_JIT_RK_ADDR_CALC:
        return "ADDR_CALC";
    default:
        return "UNKNOWN";
    }
}

std::string native_choice_name(uint32_t rule_kind, uint32_t native_choice)
{
    switch (rule_kind) {
    case BPF_JIT_RK_COND_SELECT:
        return native_choice == BPF_JIT_SEL_CMOVCC ? "CMOVCC" :
               native_choice == BPF_JIT_SEL_BRANCH ? "BRANCH" : "UNKNOWN";
    case BPF_JIT_RK_WIDE_MEM:
        return native_choice == BPF_JIT_WMEM_WIDE_LOAD ? "WIDE_LOAD" :
               native_choice == BPF_JIT_WMEM_BYTE_LOADS ? "BYTE_LOADS" : "UNKNOWN";
    case BPF_JIT_RK_ROTATE:
        return native_choice == BPF_JIT_ROT_ROR ? "ROR" :
               native_choice == BPF_JIT_ROT_RORX ? "RORX" :
               native_choice == BPF_JIT_ROT_SHIFT ? "SHIFT" : "UNKNOWN";
    case BPF_JIT_RK_ADDR_CALC:
        return native_choice == BPF_JIT_ACALC_LEA ? "LEA" :
               native_choice == BPF_JIT_ACALC_SHIFT_ADD ? "SHIFT_ADD" : "UNKNOWN";
    default:
        return "UNKNOWN";
    }
}

std::string decision_source_name(DecisionSource source)
{
    switch (source) {
    case DecisionSource::StaticHeuristic:
        return "static";
    case DecisionSource::ConfigDefault:
        return "config-default";
    case DecisionSource::ConfigOverride:
        return "config-override";
    case DecisionSource::ProfileProvider:
        return "profile";
    case DecisionSource::ProfileFallback:
        return "profile-fallback";
    default:
        return "unknown";
    }
}

} // namespace bpf_jit_scanner
