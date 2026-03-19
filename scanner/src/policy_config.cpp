// SPDX-License-Identifier: MIT

#include "bpf_jit_scanner/policy_config.hpp"

#include <yaml-cpp/yaml.h>

#include <algorithm>
#include <cctype>
#include <cstdint>
#include <functional>
#include <iomanip>
#include <optional>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <unordered_set>

namespace bpf_jit_scanner {

namespace {

[[noreturn]] void throw_policy_error(const std::string &source_name,
                                     const std::string &message)
{
    if (source_name.empty()) {
        throw std::runtime_error(message);
    }
    throw std::runtime_error(source_name + ": " + message);
}

std::string lower_ascii(std::string value)
{
    std::transform(value.begin(), value.end(), value.begin(),
                   [](unsigned char ch) {
                       return static_cast<char>(std::tolower(ch));
                   });
    return value;
}

std::string json_escape(const std::string &value)
{
    std::ostringstream out;
    for (const unsigned char ch : value) {
        switch (ch) {
        case '\\':
            out << "\\\\";
            break;
        case '"':
            out << "\\\"";
            break;
        case '\b':
            out << "\\b";
            break;
        case '\f':
            out << "\\f";
            break;
        case '\n':
            out << "\\n";
            break;
        case '\r':
            out << "\\r";
            break;
        case '\t':
            out << "\\t";
            break;
        default:
            if (ch < 0x20U) {
                out << "\\u"
                    << std::hex << std::setw(4) << std::setfill('0')
                    << static_cast<unsigned int>(ch)
                    << std::dec << std::setfill(' ');
            } else {
                out << static_cast<char>(ch);
            }
            break;
        }
    }
    return out.str();
}

std::string prog_tag_to_hex(const std::array<uint8_t, 8> &prog_tag)
{
    std::ostringstream out;
    out << std::hex << std::setfill('0');
    for (const uint8_t byte : prog_tag) {
        out << std::setw(2) << static_cast<unsigned int>(byte);
    }
    return out.str();
}

std::string rule_pattern_kind(const V5PolicyRule &rule)
{
    return rule.pattern_kind.empty() ? "pattern" : rule.pattern_kind;
}

std::string rule_site_id(const V5PolicyRule &rule)
{
    return std::string(v5_family_name(rule.family)) + ":" +
           std::to_string(rule.site_start) + ":" + rule_pattern_kind(rule);
}

struct V5PolicySiteKey {
    uint32_t insn = 0;
    V5Family family = V5Family::Cmov;
    std::string pattern_kind = "pattern";

    bool operator==(const V5PolicySiteKey &other) const
    {
        return insn == other.insn && family == other.family &&
               pattern_kind == other.pattern_kind;
    }
};

struct V5PolicySiteKeyHash {
    size_t operator()(const V5PolicySiteKey &key) const
    {
        size_t seed = (static_cast<size_t>(key.insn) << 8) ^
                      static_cast<size_t>(key.family);
        seed ^= std::hash<std::string> {}(key.pattern_kind) + 0x9e3779b9U +
                (seed << 6) + (seed >> 2);
        return seed;
    }
};

std::optional<V5Family> parse_policy_family_name(std::string value)
{
    value = lower_ascii(std::move(value));
    if (value == "cmov") {
        return V5Family::Cmov;
    }
    if (value == "wide") {
        return V5Family::WideMem;
    }
    if (value == "rotate") {
        return V5Family::Rotate;
    }
    if (value == "lea") {
        return V5Family::AddrCalc;
    }
    if (value == "extract") {
        return V5Family::BitfieldExtract;
    }
    if (value == "zero-ext") {
        return V5Family::ZeroExtElide;
    }
    if (value == "endian") {
        return V5Family::EndianFusion;
    }
    if (value == "branch-flip") {
        return V5Family::BranchFlip;
    }
    return std::nullopt;
}

std::string yaml_single_quoted(const std::string &value)
{
    std::ostringstream out;
    out << '\'';
    for (const char ch : value) {
        if (ch == '\'') {
            out << "''";
        } else {
            out << ch;
        }
    }
    out << '\'';
    return out.str();
}

std::string describe_site_key(const V5PolicySiteKey &site)
{
    return std::string(v5_family_name(site.family)) + " insn " +
           std::to_string(site.insn) + " pattern_kind " + site.pattern_kind;
}

V5PolicySiteKey policy_site_key(const V5PolicySite &site)
{
    return V5PolicySiteKey {
        .insn = site.insn,
        .family = site.family,
        .pattern_kind = site.pattern_kind,
    };
}

void reject_unknown_policy_fields(const YAML::Node &root,
                                  const std::string &source_name)
{
    for (const auto &field : root) {
        const YAML::Node key_node = field.first;
        if (!key_node || !key_node.IsScalar()) {
            throw_policy_error(source_name, "policy field names must be scalars");
        }
        const auto key = key_node.as<std::string>();
        if (key != "version" && key != "program" && key != "sites") {
            throw_policy_error(source_name,
                               "unknown policy field '" + key + "'");
        }
    }
}

void reject_unknown_site_fields(const YAML::Node &site_node,
                                const std::string &source_name)
{
    for (const auto &field : site_node) {
        const YAML::Node key_node = field.first;
        if (!key_node || !key_node.IsScalar()) {
            throw_policy_error(source_name,
                               "site field names must be scalars");
        }
        const auto key = key_node.as<std::string>();
        if (key != "insn" && key != "family" && key != "pattern_kind") {
            throw_policy_error(source_name,
                               "unknown policy site field '" + key + "'");
        }
    }
}

std::vector<V5PolicySite> parse_v3_sites(const YAML::Node &sites_node,
                                         const std::string &source_name)
{
    std::vector<V5PolicySite> sites;
    if (!sites_node.IsSequence()) {
        throw_policy_error(source_name, "sites must be a sequence");
    }

    std::unordered_set<V5PolicySiteKey, V5PolicySiteKeyHash> seen;
    seen.reserve(sites_node.size());
    for (const auto &site_node : sites_node) {
        if (!site_node.IsMap()) {
            throw_policy_error(source_name, "sites entries must be mappings");
        }
        reject_unknown_site_fields(site_node, source_name);

        const YAML::Node insn_node = site_node["insn"];
        const YAML::Node family_node = site_node["family"];
        const YAML::Node pattern_kind_node = site_node["pattern_kind"];
        if (!insn_node || !insn_node.IsScalar()) {
            throw_policy_error(source_name, "sites.insn must be a scalar");
        }
        if (!family_node || !family_node.IsScalar()) {
            throw_policy_error(source_name, "sites.family must be a scalar");
        }
        if (!pattern_kind_node || !pattern_kind_node.IsScalar()) {
            throw_policy_error(source_name,
                               "sites.pattern_kind must be a scalar");
        }

        const auto family =
            parse_policy_family_name(family_node.as<std::string>());
        if (!family.has_value()) {
            throw_policy_error(source_name,
                               "unknown family '" +
                                   family_node.as<std::string>() +
                                   "' in sites.family");
        }

        V5PolicySite site = {};
        site.insn = insn_node.as<uint32_t>();
        site.family = *family;
        site.pattern_kind = pattern_kind_node.as<std::string>();
        if (site.pattern_kind.empty()) {
            throw_policy_error(source_name,
                               "sites.pattern_kind must not be empty");
        }

        const V5PolicySiteKey key {
            .insn = site.insn,
            .family = site.family,
            .pattern_kind = site.pattern_kind,
        };
        if (!seen.insert(key).second) {
            throw_policy_error(source_name,
                               "duplicate sites entry for " +
                                   describe_site_key(key));
        }
        sites.push_back(site);
    }
    return sites;
}

V5PolicyConfig parse_policy_node(const YAML::Node &root,
                                 const std::string &source_name)
{
    if (!root || !root.IsMap()) {
        throw_policy_error(source_name, "policy document must be a mapping");
    }

    V5PolicyConfig config = {};
    reject_unknown_policy_fields(root, source_name);
    const YAML::Node version_node = root["version"];
    if (!version_node || !version_node.IsScalar()) {
        throw_policy_error(source_name, "version is required and must be a scalar");
    }
    config.version = version_node.as<uint32_t>();
    if (config.version != 3U) {
        throw_policy_error(source_name,
                           "unsupported policy version " +
                               std::to_string(config.version));
    }

    if (const YAML::Node program_node = root["program"];
        program_node && !program_node.IsNull()) {
        if (!program_node.IsScalar()) {
            throw_policy_error(source_name, "program must be a scalar");
        }
        config.program = program_node.as<std::string>();
    }

    const YAML::Node sites_node = root["sites"];
    if (sites_node) {
        config.sites = parse_v3_sites(sites_node, source_name);
    }
    return config;
}

} // namespace

V5PolicyConfig load_policy_config_file(const std::string &path)
{
    try {
        return parse_policy_node(YAML::LoadFile(path), path);
    } catch (const YAML::Exception &ex) {
        throw std::runtime_error(path + ": " + ex.what());
    }
}

V5PolicyConfig parse_policy_config_text(const std::string &text,
                                        const std::string &source_name)
{
    try {
        return parse_policy_node(YAML::Load(text), source_name);
    } catch (const YAML::Exception &ex) {
        if (source_name.empty()) {
            throw std::runtime_error(ex.what());
        }
        throw std::runtime_error(source_name + ": " + ex.what());
    }
}

bool v5_policy_allows_family(const V5PolicyConfig &config, V5Family family)
{
    return std::any_of(config.sites.begin(), config.sites.end(),
                       [family](const V5PolicySite &site) {
                           return site.family == family;
                       });
}

V5PolicyFilterResult filter_rules_by_policy_detailed(
    const std::vector<V5PolicyRule> &rules,
    const V5PolicyConfig &config)
{
    V5PolicyFilterResult result;
    std::unordered_multimap<V5PolicySiteKey, size_t, V5PolicySiteKeyHash>
        explicit_sites;
    std::unordered_set<size_t> matched_site_indices;
    explicit_sites.reserve(config.sites.size());
    matched_site_indices.reserve(config.sites.size());

    for (size_t index = 0; index < config.sites.size(); ++index) {
        const auto &site = config.sites[index];
        explicit_sites.emplace(policy_site_key(site), index);
    }

    result.rules.reserve(rules.size());
    for (const auto &rule : rules) {
        const V5PolicySiteKey key {
            .insn = rule.site_start,
            .family = rule.family,
            .pattern_kind = rule_pattern_kind(rule),
        };
        const auto [begin, end] = explicit_sites.equal_range(key);
        if (begin == end) {
            continue;
        }
        result.rules.push_back(rule);
        for (auto it = begin; it != end; ++it) {
            if (matched_site_indices.insert(it->second).second) {
                result.matched_site_count++;
            }
        }
    }

    result.unmatched_site_count =
        config.sites.size() >= matched_site_indices.size()
            ? config.sites.size() - matched_site_indices.size()
            : 0;
    if (result.unmatched_site_count != 0) {
        result.warnings.reserve(result.unmatched_site_count);
        for (size_t index = 0; index < config.sites.size(); ++index) {
            if (matched_site_indices.find(index) != matched_site_indices.end()) {
                continue;
            }
            const auto key = policy_site_key(config.sites[index]);
            result.warnings.push_back(
                "policy site " + describe_site_key(key) +
                " was not found in the live program; skipping");
        }
    }
    return result;
}

std::vector<V5PolicyRule> filter_rules_by_policy(
    const std::vector<V5PolicyRule> &rules,
    const V5PolicyConfig &config)
{
    return filter_rules_by_policy_detailed(rules, config).rules;
}

V5ScanSummary summarize_rules(const std::vector<V5PolicyRule> &rules)
{
    V5ScanSummary summary = {};
    summary.rules = rules;
    for (const auto &rule : rules) {
        switch (rule.family) {
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
        case V5Family::ZeroExtElide:
            summary.zero_ext_sites++;
            break;
        case V5Family::EndianFusion:
            summary.endian_sites++;
            break;
        case V5Family::BranchFlip:
            summary.branch_flip_sites++;
            break;
        }
    }
    return summary;
}

V5ScanManifest build_scan_manifest(const V5ProgramInfo &program,
                                   const V5ScanSummary &summary)
{
    V5ScanManifest manifest;
    manifest.program = program;
    manifest.summary = summary;
    manifest.sites.reserve(summary.rules.size());
    for (const auto &rule : summary.rules) {
        manifest.sites.push_back(V5ScanManifestSite{
            .site_id = rule_site_id(rule),
            .family = rule.family,
            .start_insn = rule.site_start,
            .pattern_kind = rule_pattern_kind(rule),
            .site_len = rule.site_len,
            .canonical_form = rule.canonical_form,
            .native_choice = rule.native_choice,
        });
    }
    return manifest;
}

std::string scan_manifest_to_json(const V5ScanManifest &manifest)
{
    std::ostringstream out;
    out << "{"
        << "\"program\":{"
        << "\"name\":\"" << json_escape(manifest.program.name) << "\","
        << "\"insn_cnt\":" << manifest.program.insn_cnt << ","
        << "\"prog_tag\":\"" << prog_tag_to_hex(manifest.program.prog_tag)
        << "\""
        << "},"
        << "\"summary\":{"
        << "\"total_sites\":" << manifest.summary.rules.size() << ","
        << "\"cmov_sites\":" << manifest.summary.cmov_sites << ","
        << "\"wide_sites\":" << manifest.summary.wide_sites << ","
        << "\"rotate_sites\":" << manifest.summary.rotate_sites << ","
        << "\"lea_sites\":" << manifest.summary.lea_sites << ","
        << "\"extract_sites\":" << manifest.summary.bitfield_sites << ","
        << "\"bitfield_sites\":" << manifest.summary.bitfield_sites << ","
        << "\"zero_ext_sites\":" << manifest.summary.zero_ext_sites << ","
        << "\"endian_sites\":" << manifest.summary.endian_sites << ","
        << "\"branch_flip_sites\":" << manifest.summary.branch_flip_sites
        << "},"
        << "\"sites\":[";
    for (size_t i = 0; i < manifest.sites.size(); ++i) {
        const auto &site = manifest.sites[i];
        if (i != 0) {
            out << ",";
        }
        out << "{"
            << "\"site_id\":\"" << json_escape(site.site_id) << "\","
            << "\"family\":\"" << v5_family_name(site.family) << "\","
            << "\"insn\":" << site.start_insn << ","
            << "\"start_insn\":" << site.start_insn << ","
            << "\"pattern_kind\":\"" << json_escape(site.pattern_kind) << "\","
            << "\"site_len\":" << site.site_len << ","
            << "\"canonical_form\":" << site.canonical_form << ","
            << "\"native_choice\":" << site.native_choice
            << "}";
    }
    out << "]"
        << "}\n";
    return out.str();
}

std::string render_policy_v3_yaml(const V5ProgramInfo &program,
                                  const V5ScanSummary &summary)
{
    std::ostringstream out;
    out << "version: 3\n";
    out << "program: " << yaml_single_quoted(program.name) << "\n";
    if (summary.rules.empty()) {
        out << "sites: []\n";
        return out.str();
    }

    out << "sites:\n";
    for (const auto &rule : summary.rules) {
        out << "  - insn: " << rule.site_start << "\n";
        out << "    family: " << v5_family_name(rule.family) << "\n";
        out << "    pattern_kind: "
            << yaml_single_quoted(rule_pattern_kind(rule)) << "\n";
    }
    return out.str();
}

} // namespace bpf_jit_scanner
