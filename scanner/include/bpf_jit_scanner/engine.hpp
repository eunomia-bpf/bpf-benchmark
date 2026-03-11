/* SPDX-License-Identifier: MIT */
#ifndef BPF_JIT_SCANNER_ENGINE_HPP
#define BPF_JIT_SCANNER_ENGINE_HPP

#include "types.h"

#include <array>
#include <cstdint>
#include <functional>
#include <memory>
#include <optional>
#include <string>
#include <string_view>
#include <vector>

namespace bpf_jit_scanner {

enum class DecisionSource {
    StaticHeuristic,
    ConfigDefault,
    ConfigOverride,
    ProfileProvider,
    ProfileFallback,
};

enum class Preference {
    Unspecified,
    Skip,
    Profile,
    Branch,
    Cmovcc,
    Ror,
    Rorx,
    Wide,
    Lea,
    Extract,
};

struct SiteFeatures {
    uint32_t site_start = 0;
    uint32_t site_len = 0;
    uint32_t rule_kind = 0;
    uint32_t loop_depth = 0;
    double branch_density = 0.0;
    uint32_t nearby_site_count = 0;
    int32_t estimated_code_delta = 0;
    bool operand_is_imm = false;
};

struct ProgramFeatures {
    uint32_t insn_count = 0;
    uint32_t subprogram_count = 1;
    std::array<uint32_t, 7> candidate_count = {};
};

struct ScanOptions {
    std::vector<std::string> families;
    bool use_rorx = false;
    uint32_t max_rules_per_family = 4096;
};

struct CandidateSite {
    bpf_jit_scan_rule rule = {};
    std::string family;
    SiteFeatures features = {};
    uint32_t arbitration_priority = 0;
};

struct OverlapConflict {
    CandidateSite winner;
    CandidateSite loser;
    std::string reason;
};

struct ScanReport {
    ProgramFeatures program_features = {};
    std::vector<CandidateSite> raw_sites;
    std::vector<CandidateSite> merged_sites;
    std::vector<OverlapConflict> conflicts;
};

struct FamilyPreferences {
    std::optional<Preference> cmov;
    std::optional<Preference> rotate;
    std::optional<Preference> wide_mem;
    std::optional<Preference> lea;
    std::optional<Preference> bitfield_extract;
};

struct PolicyOverride {
    std::string program_glob;
    FamilyPreferences choices;
};

struct PolicyConfig {
    FamilyPreferences defaults;
    std::vector<PolicyOverride> overrides;

    static PolicyConfig parse_file(const std::string &path);
};

struct PolicyDecision {
    CandidateSite site;
    bool emit_rule = true;
    uint32_t native_choice = 0;
    DecisionSource source = DecisionSource::StaticHeuristic;
    std::string rationale;
};

class ProfileProvider {
public:
    virtual ~ProfileProvider() = default;

    virtual std::optional<PolicyDecision> decide(const CandidateSite &site,
                                                 const ProgramFeatures &program) const = 0;
};

struct PatternFamily {
    std::string name;
    uint32_t rule_kind = 0;
    uint32_t arbitration_priority = 0;
    std::function<std::vector<bpf_jit_scan_rule>(const uint8_t *xlated,
                                                 uint32_t len,
                                                 const ScanOptions &options)> scanner;
};

class PatternRegistry {
public:
    void register_family(PatternFamily family);
    const std::vector<PatternFamily> &families() const;
    const PatternFamily *find_family(std::string_view name) const;

    static PatternRegistry builtin();

private:
    std::vector<PatternFamily> families_;
};

class PolicyEngine {
public:
    explicit PolicyEngine(PatternRegistry registry = PatternRegistry::builtin(),
                          PolicyConfig config = {});

    void set_profile_provider(std::shared_ptr<const ProfileProvider> provider);

    const PatternRegistry &registry() const;
    const PolicyConfig &config() const;

    ScanReport scan(const uint8_t *xlated, uint32_t len,
                    const ScanOptions &options = {}) const;

    std::vector<PolicyDecision> decide(const ScanReport &report,
                                       std::string_view program_name = {}) const;

    std::vector<bpf_jit_scan_rule> materialize(
        const std::vector<PolicyDecision> &decisions) const;

private:
    PatternRegistry registry_;
    PolicyConfig config_;
    std::shared_ptr<const ProfileProvider> profile_provider_;
};

std::string rule_kind_name(uint32_t rule_kind);
std::string native_choice_name(uint32_t rule_kind, uint32_t native_choice);
std::string decision_source_name(DecisionSource source);

} // namespace bpf_jit_scanner

#endif /* BPF_JIT_SCANNER_ENGINE_HPP */
