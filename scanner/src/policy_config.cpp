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
#include <utility>

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

bool parse_selection_mode(const YAML::Node &selection_node,
                          const std::string &source_name,
                          V5PolicySelection *selection)
{
    const YAML::Node mode_node = selection_node["mode"];
    if (!mode_node || !mode_node.IsScalar()) {
        return false;
    }

    std::string mode = mode_node.as<std::string>();
    std::transform(mode.begin(), mode.end(), mode.begin(),
                   [](unsigned char ch) {
                       return static_cast<char>(std::tolower(ch));
                   });
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
        const auto family = parse_v5_family_name(node.as<std::string>());
        if (!family.has_value()) {
            throw_policy_error(
                source_name,
                "unknown family '" + node.as<std::string>() +
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
    if (!parse_selection_mode(selection_node, source_name, &config.selection)) {
        throw_policy_error(source_name, "selection.mode is required");
    }
    config.selection.families =
        parse_family_list(selection_node["families"], source_name);
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
    std::vector<V5PolicyRule> filtered;
    filtered.reserve(rules.size());
    for (const auto &rule : rules) {
        if (v5_policy_allows_family(config, rule.family)) {
            filtered.push_back(rule);
        }
    }
    return filtered;
}

V5ScanManifest build_scan_manifest(const V5ProgramInfo &program,
                                   const V5ScanSummary &summary)
{
    V5ScanManifest manifest;
    manifest.program = program;
    manifest.summary = summary;
    manifest.sites.reserve(summary.rules.size());
    for (const auto &rule : summary.rules) {
        V5ScanManifestSite site;
        site.family = rule.family;
        site.start_insn = rule.site_start;
        site.site_len = static_cast<uint16_t>(rule.pattern.size());
        site.canonical_form = rule.canonical_form;
        site.native_choice = rule.native_choice;

        std::ostringstream site_id;
        site_id << v5_family_name(rule.family) << ':' << rule.site_start << ':'
                << site.site_len << ':' << rule.canonical_form << ':'
                << rule.native_choice;
        site.site_id = site_id.str();

        manifest.sites.push_back(std::move(site));
    }
    return manifest;
}

std::string scan_manifest_to_json(const V5ScanManifest &manifest)
{
    std::ostringstream out;
    out << "{\n";
    out << "  \"program\": {\n";
    out << "    \"name\": \"" << json_escape(manifest.program.name) << "\",\n";
    out << "    \"insn_cnt\": " << manifest.program.insn_cnt << ",\n";
    out << "    \"prog_tag\": \"" << prog_tag_to_hex(manifest.program.prog_tag)
        << "\"\n";
    out << "  },\n";
    out << "  \"summary\": {\n";
    out << "    \"total_sites\": " << manifest.summary.rules.size() << ",\n";
    out << "    \"cmov_sites\": " << manifest.summary.cmov_sites << ",\n";
    out << "    \"wide_sites\": " << manifest.summary.wide_sites << ",\n";
    out << "    \"rotate_sites\": " << manifest.summary.rotate_sites << ",\n";
    out << "    \"lea_sites\": " << manifest.summary.lea_sites << ",\n";
    out << "    \"extract_sites\": " << manifest.summary.bitfield_sites
        << ",\n";
    out << "    \"zero_ext_sites\": " << manifest.summary.zero_ext_sites
        << ",\n";
    out << "    \"endian_sites\": " << manifest.summary.endian_sites << ",\n";
    out << "    \"branch_flip_sites\": " << manifest.summary.branch_flip_sites
        << "\n";
    out << "  },\n";
    out << "  \"sites\": [\n";
    for (size_t i = 0; i < manifest.sites.size(); ++i) {
        const auto &site = manifest.sites[i];
        out << "    {\n";
        out << "      \"site_id\": \"" << json_escape(site.site_id) << "\",\n";
        out << "      \"family\": \"" << v5_family_name(site.family)
            << "\",\n";
        out << "      \"start_insn\": " << site.start_insn << ",\n";
        out << "      \"pattern_kind\": \"" << json_escape(site.pattern_kind)
            << "\",\n";
        out << "      \"site_len\": " << site.site_len << ",\n";
        out << "      \"canonical_form\": " << site.canonical_form << ",\n";
        out << "      \"native_choice\": " << site.native_choice << "\n";
        out << "    }";
        if (i + 1 != manifest.sites.size()) {
            out << ',';
        }
        out << '\n';
    }
    out << "  ]\n";
    out << "}\n";
    return out.str();
}

} // namespace bpf_jit_scanner
