// SPDX-License-Identifier: MIT

#include "bpf_jit_scanner/policy_config.hpp"

#include <yaml-cpp/yaml.h>

#include <algorithm>
#include <cctype>
#include <cstdint>
#include <iomanip>
#include <optional>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unordered_map>

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

std::optional<int32_t> binding_const(const V5PolicyRule &rule,
                                     uint8_t canonical_param)
{
    for (const auto &binding : rule.bindings) {
        if (binding.canonical_param == canonical_param &&
            binding.source_type == BPF_JIT_BIND_SOURCE_CONST) {
            return binding.inline_const;
        }
    }
    return std::nullopt;
}

std::string rule_pattern_kind(const V5PolicyRule &rule)
{
    switch (rule.family) {
    case V5Family::Cmov: {
        const auto width = binding_const(rule, BPF_JIT_SEL_PARAM_WIDTH);
        return width.has_value() ? "cond-select-" + std::to_string(*width)
                                 : "cond-select";
    }
    case V5Family::WideMem: {
        const auto encoded_width = binding_const(rule, BPF_JIT_WMEM_PARAM_WIDTH);
        if (!encoded_width.has_value()) {
            return "wide-load";
        }
        const bool big_endian =
            (*encoded_width & static_cast<int32_t>(BPF_JIT_WMEM_F_BIG_ENDIAN)) != 0;
        const int32_t width =
            *encoded_width & static_cast<int32_t>(BPF_JIT_WMEM_WIDTH_MASK);
        return "wide-load-" + std::to_string(width) +
               (big_endian ? "-be" : "");
    }
    case V5Family::Rotate: {
        const auto width = binding_const(rule, BPF_JIT_ROT_PARAM_WIDTH);
        return width.has_value() ? "rotate-" + std::to_string(*width)
                                 : "rotate";
    }
    case V5Family::AddrCalc: {
        const auto scale = binding_const(rule, BPF_JIT_ACALC_PARAM_SCALE);
        return scale.has_value() ? "addr-calc-scale-" + std::to_string(*scale)
                                 : "addr-calc";
    }
    case V5Family::BitfieldExtract: {
        std::string kind = "bitfield-extract";
        if (const auto width = binding_const(rule, BPF_JIT_BFX_PARAM_WIDTH);
            width.has_value()) {
            kind += "-" + std::to_string(*width);
        }
        if (const auto order = binding_const(rule, BPF_JIT_BFX_PARAM_ORDER);
            order.has_value()) {
            if (*order == BPF_JIT_BFX_ORDER_MASK_SHIFT) {
                kind += "-mask-shift";
            } else if (*order == BPF_JIT_BFX_ORDER_SHIFT_MASK) {
                kind += "-shift-mask";
            }
        }
        return kind;
    }
    case V5Family::ZeroExtElide:
        return "zero-ext-elide";
    case V5Family::EndianFusion: {
        std::string kind = "endian";
        if (const auto direction =
                binding_const(rule, BPF_JIT_ENDIAN_PARAM_DIRECTION);
            direction.has_value()) {
            kind += (*direction == BPF_JIT_ENDIAN_SWAP_STORE)
                        ? "-swap-store"
                        : "-load-swap";
        } else {
            kind += "-fusion";
        }
        if (const auto width = binding_const(rule, BPF_JIT_ENDIAN_PARAM_WIDTH);
            width.has_value()) {
            kind += "-" + std::to_string(*width);
        }
        return kind;
    }
    case V5Family::BranchFlip:
        return "branch-flip";
    default:
        return "pattern";
    }
}

std::string rule_site_id(const V5PolicyRule &rule)
{
    return std::string(v5_family_name(rule.family)) + ":" +
           std::to_string(rule.site_start) + ":" + rule_pattern_kind(rule);
}

bool parse_selection_mode(const YAML::Node &selection_node,
                          const std::string &source_name,
                          V5PolicySelection *selection)
{
    const YAML::Node mode_node = selection_node["mode"];
    if (!mode_node || !mode_node.IsScalar()) {
        return false;
    }

    const std::string mode = lower_ascii(mode_node.as<std::string>());
    if (mode == "allowlist") {
        selection->mode = V5PolicySelectionMode::Allowlist;
        return true;
    }
    if (mode == "denylist") {
        selection->mode = V5PolicySelectionMode::Denylist;
        return true;
    }

    throw_policy_error(source_name,
                       "selection.mode must be 'allowlist' or 'denylist'");
}

std::vector<V5Family> parse_family_list(const YAML::Node &families_node,
                                        const std::string &source_name)
{
    std::vector<V5Family> families;
    auto append_family = [&](const YAML::Node &node) {
        if (!node.IsScalar()) {
            throw_policy_error(source_name,
                               "selection.families entries must be scalars");
        }
        const std::string raw_name = node.as<std::string>();
        const auto family = parse_v5_family_name(raw_name);
        if (!family.has_value()) {
            throw_policy_error(source_name,
                               "unknown family '" + raw_name +
                                   "' in selection.families");
        }
        if (std::find(families.begin(), families.end(), *family) ==
            families.end()) {
            families.push_back(*family);
        }
    };

    if (!families_node || families_node.IsNull()) {
        return families;
    }
    if (families_node.IsSequence()) {
        for (const auto &family_node : families_node) {
            append_family(family_node);
        }
        return families;
    }
    if (families_node.IsScalar()) {
        append_family(families_node);
        return families;
    }

    throw_policy_error(source_name,
                       "selection.families must be a sequence or scalar");
}

V5PolicyConfig parse_family_action_map(const YAML::Node &families_node,
                                       const std::string &source_name)
{
    if (!families_node.IsMap()) {
        throw_policy_error(source_name, "families must be a mapping");
    }

    V5PolicyConfig config = {};
    config.selection.mode = V5PolicySelectionMode::Allowlist;

    for (const auto &entry : families_node) {
        if (!entry.first.IsScalar()) {
            throw_policy_error(source_name,
                               "families keys must be scalar family names");
        }

        const std::string raw_name = entry.first.as<std::string>();
        const auto family = parse_v5_family_name(raw_name);
        if (!family.has_value()) {
            throw_policy_error(source_name,
                               "unknown family '" + raw_name +
                                   "' in families mapping");
        }

        const YAML::Node action_node = entry.second;
        bool enabled = true;
        if (action_node.IsScalar()) {
            const std::string action = lower_ascii(action_node.as<std::string>());
            if (action == "apply" || action == "enable" || action == "enabled" ||
                action == "keep" || action == "on" || action == "true") {
                enabled = true;
            } else if (action == "skip" || action == "disable" ||
                       action == "disabled" || action == "drop" ||
                       action == "off" || action == "false") {
                enabled = false;
            } else {
                throw_policy_error(source_name,
                                   "families." + raw_name +
                                       " must be apply/skip (or enable/disable)");
            }
        } else if (action_node.IsDefined() && !action_node.IsNull()) {
            throw_policy_error(source_name,
                               "families." + raw_name +
                                   " must be a scalar apply/skip value");
        }

        if (enabled &&
            std::find(config.selection.families.begin(),
                      config.selection.families.end(),
                      *family) == config.selection.families.end()) {
            config.selection.families.push_back(*family);
        }
    }

    return config;
}

std::vector<V5PolicySiteOverride> parse_site_overrides(
    const YAML::Node &site_overrides_node,
    const std::string &source_name)
{
    std::vector<V5PolicySiteOverride> overrides;
    if (!site_overrides_node || site_overrides_node.IsNull()) {
        return overrides;
    }
    if (!site_overrides_node.IsSequence()) {
        throw_policy_error(source_name, "site_overrides must be a sequence");
    }

    for (const auto &override_node : site_overrides_node) {
        if (!override_node.IsMap()) {
            throw_policy_error(source_name,
                               "site_overrides entries must be mappings");
        }

        const YAML::Node site_id_node = override_node["site_id"];
        const YAML::Node action_node = override_node["action"];
        if (!site_id_node || !site_id_node.IsScalar()) {
            throw_policy_error(source_name,
                               "site_overrides.site_id must be a scalar");
        }
        if (!action_node || !action_node.IsScalar()) {
            throw_policy_error(source_name,
                               "site_overrides.action must be a scalar");
        }

        const std::string action = lower_ascii(action_node.as<std::string>());
        if (action != "enable" && action != "disable") {
            throw_policy_error(source_name,
                               "site_overrides.action must be 'enable' or 'disable'");
        }

        overrides.push_back(V5PolicySiteOverride{
            .site_id = site_id_node.as<std::string>(),
            .enabled = action == "enable",
        });
    }
    return overrides;
}

V5PolicyConfig parse_policy_node(const YAML::Node &root,
                                 const std::string &source_name)
{
    if (!root || !root.IsMap()) {
        throw_policy_error(source_name, "policy document must be a mapping");
    }

    V5PolicyConfig config = {};
    const YAML::Node version_node = root["version"];
    if (version_node) {
        if (!version_node.IsScalar()) {
            throw_policy_error(source_name, "version must be a scalar");
        }
        config.version = version_node.as<uint32_t>();
        if (config.version != 1U) {
            throw_policy_error(source_name,
                               "unsupported policy version " +
                                   std::to_string(config.version));
        }
    }

    const YAML::Node selection_node =
        root["selection"] ? root["selection"] : root;
    if (!selection_node.IsMap()) {
        throw_policy_error(source_name, "selection must be a mapping");
    }

    const YAML::Node families_node = selection_node["families"];
    if (families_node && families_node.IsMap()) {
        const auto shorthand = parse_family_action_map(families_node, source_name);
        config.selection = shorthand.selection;
    } else {
        if (!parse_selection_mode(selection_node, source_name, &config.selection)) {
            throw_policy_error(source_name, "selection.mode is required");
        }
        config.selection.families =
            parse_family_list(families_node, source_name);
    }
    config.site_overrides =
        parse_site_overrides(root["site_overrides"], source_name);
    return config;
}

bool family_in_list(const std::vector<V5Family> &families, V5Family family)
{
    return std::find(families.begin(), families.end(), family) !=
           families.end();
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
    const bool listed = family_in_list(config.selection.families, family);
    return config.selection.mode == V5PolicySelectionMode::Allowlist
               ? listed
               : !listed;
}

std::vector<V5PolicyRule> filter_rules_by_policy(
    const std::vector<V5PolicyRule> &rules,
    const V5PolicyConfig &config)
{
    std::unordered_map<std::string, bool> overrides;
    overrides.reserve(config.site_overrides.size());
    for (const auto &site_override : config.site_overrides) {
        overrides[site_override.site_id] = site_override.enabled;
    }

    std::vector<V5PolicyRule> filtered;
    filtered.reserve(rules.size());
    for (const auto &rule : rules) {
        bool keep = v5_policy_allows_family(config, rule.family);
        const auto override_it = overrides.find(rule_site_id(rule));
        if (override_it != overrides.end()) {
            keep = override_it->second;
        }
        if (keep) {
            filtered.push_back(rule);
        }
    }
    return filtered;
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
            .site_len = static_cast<uint16_t>(rule.pattern.size()),
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

} // namespace bpf_jit_scanner
