/* SPDX-License-Identifier: MIT */
#ifndef BPF_JIT_SCANNER_POLICY_CONFIG_HPP
#define BPF_JIT_SCANNER_POLICY_CONFIG_HPP

#include "pattern_v5.hpp"

#include <array>
#include <string>
#include <vector>

namespace bpf_jit_scanner {

enum class V5PolicySelectionMode {
    Allowlist,
    Denylist,
};

struct V5PolicySelection {
    V5PolicySelectionMode mode = V5PolicySelectionMode::Allowlist;
    std::vector<V5Family> families;
};

struct V5PolicySiteOverride {
    std::string site_id;
    bool enabled = true;
};

struct V5PolicyConfig {
    uint32_t version = 1;
    V5PolicySelection selection;
    std::vector<V5PolicySiteOverride> site_overrides;
};

struct V5ProgramInfo {
    std::string name;
    uint32_t insn_cnt = 0;
    std::array<uint8_t, 8> prog_tag = {};
};

struct V5ScanManifestSite {
    std::string site_id;
    V5Family family = V5Family::Cmov;
    uint32_t start_insn = 0;
    std::string pattern_kind = "pattern";
    uint16_t site_len = 0;
    uint16_t canonical_form = 0;
    uint16_t native_choice = 0;
};

struct V5ScanManifest {
    V5ProgramInfo program;
    V5ScanSummary summary;
    std::vector<V5ScanManifestSite> sites;
};

V5PolicyConfig load_policy_config_file(const std::string &path);
V5PolicyConfig parse_policy_config_text(const std::string &text,
                                        const std::string &source_name = {});

bool v5_policy_allows_family(const V5PolicyConfig &config, V5Family family);
std::vector<V5PolicyRule> filter_rules_by_policy(
    const std::vector<V5PolicyRule> &rules,
    const V5PolicyConfig &config);
V5ScanSummary summarize_rules(const std::vector<V5PolicyRule> &rules);

V5ScanManifest build_scan_manifest(const V5ProgramInfo &program,
                                   const V5ScanSummary &summary);
std::string scan_manifest_to_json(const V5ScanManifest &manifest);

} // namespace bpf_jit_scanner

#endif /* BPF_JIT_SCANNER_POLICY_CONFIG_HPP */
