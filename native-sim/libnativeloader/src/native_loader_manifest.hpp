#pragma once

#include <linux/bpf.h>

#include <cctype>
#include <cstdint>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <limits>
#include <optional>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

struct NativeMapShape {
    int type = -1;
    uint32_t key_size = 0;
    uint32_t value_size = 0;
    uint32_t max_entries = 0;
};

enum class NativeMapRuleMatch {
    Exact,
    Prefix,
    Suffix,
};

struct NativeMapRule {
    NativeMapRuleMatch match = NativeMapRuleMatch::Exact;
    std::string pattern;
    std::string exclude;
    std::string native_symbol;
    NativeMapShape shape;
    NativeMapShape inner_shape;
    bool object_scoped = false;
};

struct ManifestResolution {
    std::filesystem::path native_object_path;
    std::string symbol_name;
    std::vector<NativeMapRule> map_rules;
};

[[noreturn]] inline void manifest_fail(const std::string &message)
{
    throw std::runtime_error(message);
}

inline bool ends_with(const std::string &value, const std::string &suffix)
{
    return value.size() >= suffix.size() &&
           value.compare(value.size() - suffix.size(), suffix.size(), suffix) == 0;
}

inline bool starts_with(const std::string &value, const std::string &prefix)
{
    return value.size() >= prefix.size() &&
           value.compare(0, prefix.size(), prefix) == 0;
}

inline bool native_map_rule_matches(const NativeMapRule &rule,
                                    const std::string &name)
{
    if (!rule.exclude.empty() && name == rule.exclude) {
        return false;
    }
    switch (rule.match) {
    case NativeMapRuleMatch::Exact:
        return name == rule.pattern;
    case NativeMapRuleMatch::Prefix:
        return starts_with(name, rule.pattern);
    case NativeMapRuleMatch::Suffix:
        return ends_with(name, rule.pattern);
    }
    manifest_fail("native_loader: unknown manifest map rule match kind");
}

inline bool native_map_shape_equal(const NativeMapShape &a,
                                   const NativeMapShape &b)
{
    return a.type == b.type &&
           a.key_size == b.key_size &&
           a.value_size == b.value_size &&
           a.max_entries == b.max_entries;
}

inline const NativeMapRule *find_native_map_rule(
    const std::vector<NativeMapRule> &rules,
    const std::string &name)
{
    const NativeMapRule *match = nullptr;
    for (const NativeMapRule &rule : rules) {
        if (!native_map_rule_matches(rule, name)) {
            continue;
        }
        if (match &&
            (!native_map_shape_equal(match->shape, rule.shape) ||
             !native_map_shape_equal(match->inner_shape, rule.inner_shape) ||
             match->native_symbol != rule.native_symbol ||
             match->object_scoped != rule.object_scoped)) {
            manifest_fail("native_loader: manifest map_rules are ambiguous for map " + name);
        }
        match = &rule;
    }
    return match;
}

inline NativeMapShape expected_native_map_shape(
    const std::vector<NativeMapRule> &rules,
    const std::string &name)
{
    const NativeMapRule *rule = find_native_map_rule(rules, name);
    if (!rule) {
        return NativeMapShape{};
    }
    return rule->shape;
}

inline bool native_map_symbol_is_object_scoped(
    const std::vector<NativeMapRule> &rules,
    const std::string &name)
{
    const NativeMapRule *rule = find_native_map_rule(rules, name);
    return rule && rule->object_scoped;
}

inline size_t json_skip_ws(const std::string &text, size_t pos)
{
    while (pos < text.size() &&
           std::isspace(static_cast<unsigned char>(text[pos]))) {
        pos++;
    }
    return pos;
}

[[noreturn]] inline void json_fail(const std::string &message)
{
    manifest_fail("native_loader manifest JSON: " + message);
}

inline std::string json_parse_string_value(const std::string &text, size_t &pos)
{
    pos = json_skip_ws(text, pos);
    if (pos >= text.size() || text[pos] != '"') {
        json_fail("expected string");
    }
    pos++;
    std::string out;
    while (pos < text.size()) {
        char ch = text[pos++];
        if (ch == '"') {
            return out;
        }
        if (ch == '\\') {
            if (pos >= text.size()) {
                json_fail("unterminated escape");
            }
            char esc = text[pos++];
            switch (esc) {
            case '"':
            case '\\':
            case '/':
                out.push_back(esc);
                break;
            case 'b':
                out.push_back('\b');
                break;
            case 'f':
                out.push_back('\f');
                break;
            case 'n':
                out.push_back('\n');
                break;
            case 'r':
                out.push_back('\r');
                break;
            case 't':
                out.push_back('\t');
                break;
            case 'u':
                if (pos + 4 > text.size()) {
                    json_fail("short unicode escape");
                }
                out.push_back('?');
                pos += 4;
                break;
            default:
                json_fail("invalid string escape");
            }
        } else {
            out.push_back(ch);
        }
    }
    json_fail("unterminated string");
}

inline size_t json_skip_value(const std::string &text, size_t pos);

inline size_t json_skip_array(const std::string &text, size_t pos)
{
    if (pos >= text.size() || text[pos] != '[') {
        json_fail("expected array");
    }
    pos++;
    for (;;) {
        pos = json_skip_ws(text, pos);
        if (pos >= text.size()) {
            json_fail("unterminated array");
        }
        if (text[pos] == ']') {
            return pos + 1;
        }
        pos = json_skip_value(text, pos);
        pos = json_skip_ws(text, pos);
        if (pos < text.size() && text[pos] == ',') {
            pos++;
            continue;
        }
        if (pos < text.size() && text[pos] == ']') {
            return pos + 1;
        }
        json_fail("expected array separator");
    }
}

inline size_t json_skip_object(const std::string &text, size_t pos)
{
    if (pos >= text.size() || text[pos] != '{') {
        json_fail("expected object");
    }
    pos++;
    for (;;) {
        pos = json_skip_ws(text, pos);
        if (pos >= text.size()) {
            json_fail("unterminated object");
        }
        if (text[pos] == '}') {
            return pos + 1;
        }
        (void)json_parse_string_value(text, pos);
        pos = json_skip_ws(text, pos);
        if (pos >= text.size() || text[pos] != ':') {
            json_fail("expected object colon");
        }
        pos = json_skip_value(text, pos + 1);
        pos = json_skip_ws(text, pos);
        if (pos < text.size() && text[pos] == ',') {
            pos++;
            continue;
        }
        if (pos < text.size() && text[pos] == '}') {
            return pos + 1;
        }
        json_fail("expected object separator");
    }
}

inline size_t json_skip_value(const std::string &text, size_t pos)
{
    pos = json_skip_ws(text, pos);
    if (pos >= text.size()) {
        json_fail("expected value");
    }
    if (text[pos] == '"') {
        (void)json_parse_string_value(text, pos);
        return pos;
    }
    if (text[pos] == '{') {
        return json_skip_object(text, pos);
    }
    if (text[pos] == '[') {
        return json_skip_array(text, pos);
    }
    if (std::strncmp(text.c_str() + pos, "true", 4) == 0) {
        return pos + 4;
    }
    if (std::strncmp(text.c_str() + pos, "false", 5) == 0) {
        return pos + 5;
    }
    if (std::strncmp(text.c_str() + pos, "null", 4) == 0) {
        return pos + 4;
    }
    if (text[pos] == '-' || std::isdigit(static_cast<unsigned char>(text[pos]))) {
        pos++;
        while (pos < text.size() &&
               (std::isdigit(static_cast<unsigned char>(text[pos])) ||
                text[pos] == '.' || text[pos] == 'e' || text[pos] == 'E' ||
                text[pos] == '+' || text[pos] == '-')) {
            pos++;
        }
        return pos;
    }
    json_fail("invalid value");
}

inline std::optional<size_t> json_find_key_value(const std::string &object,
                                                 const std::string &key)
{
    size_t pos = json_skip_ws(object, 0);
    if (pos >= object.size() || object[pos] != '{') {
        json_fail("root is not an object");
    }
    pos++;
    for (;;) {
        pos = json_skip_ws(object, pos);
        if (pos >= object.size()) {
            json_fail("unterminated object while finding key " + key);
        }
        if (object[pos] == '}') {
            return std::nullopt;
        }
        std::string parsed_key = json_parse_string_value(object, pos);
        pos = json_skip_ws(object, pos);
        if (pos >= object.size() || object[pos] != ':') {
            json_fail("expected colon after key " + parsed_key);
        }
        pos = json_skip_ws(object, pos + 1);
        if (parsed_key == key) {
            return pos;
        }
        pos = json_skip_value(object, pos);
        pos = json_skip_ws(object, pos);
        if (pos < object.size() && object[pos] == ',') {
            pos++;
            continue;
        }
        if (pos < object.size() && object[pos] == '}') {
            return std::nullopt;
        }
        json_fail("expected separator after key " + parsed_key);
    }
}

inline std::optional<std::string> json_object_string(
    const std::string &object,
    const std::string &key)
{
    std::optional<size_t> pos = json_find_key_value(object, key);
    if (!pos) {
        return std::nullopt;
    }
    size_t value_pos = *pos;
    return json_parse_string_value(object, value_pos);
}

inline std::string json_required_string(const std::string &object,
                                        const std::string &key)
{
    std::optional<std::string> value = json_object_string(object, key);
    if (!value || value->empty()) {
        json_fail("object missing required string key " + key);
    }
    return *value;
}

inline std::optional<uint64_t> json_object_u64(const std::string &object,
                                               const std::string &key)
{
    std::optional<size_t> found = json_find_key_value(object, key);
    if (!found) {
        return std::nullopt;
    }
    size_t pos = json_skip_ws(object, *found);
    if (pos >= object.size() || !std::isdigit(static_cast<unsigned char>(object[pos]))) {
        json_fail("key " + key + " must be a non-negative integer");
    }
    uint64_t value = 0;
    while (pos < object.size() &&
           std::isdigit(static_cast<unsigned char>(object[pos]))) {
        uint64_t digit = static_cast<uint64_t>(object[pos] - '0');
        if (value > (std::numeric_limits<uint64_t>::max() - digit) / 10) {
            json_fail("integer overflow for key " + key);
        }
        value = value * 10 + digit;
        pos++;
    }
    return value;
}

inline uint32_t json_required_u32(const std::string &object,
                                  const std::string &key)
{
    std::optional<uint64_t> value = json_object_u64(object, key);
    if (!value || *value > std::numeric_limits<uint32_t>::max()) {
        json_fail("object missing required u32 key " + key);
    }
    return static_cast<uint32_t>(*value);
}

inline std::optional<bool> json_object_bool(const std::string &object,
                                            const std::string &key)
{
    std::optional<size_t> found = json_find_key_value(object, key);
    if (!found) {
        return std::nullopt;
    }
    size_t pos = json_skip_ws(object, *found);
    if (std::strncmp(object.c_str() + pos, "true", 4) == 0) {
        return true;
    }
    if (std::strncmp(object.c_str() + pos, "false", 5) == 0) {
        return false;
    }
    json_fail("key " + key + " must be boolean");
}

inline std::vector<std::string> json_array_objects(
    const std::string &manifest,
    const std::string &key)
{
    std::optional<size_t> found = json_find_key_value(manifest, key);
    if (!found) {
        return {};
    }
    size_t pos = json_skip_ws(manifest, *found);
    if (pos >= manifest.size() || manifest[pos] != '[') {
        json_fail("key " + key + " must be an array");
    }
    pos++;
    std::vector<std::string> out;
    for (;;) {
        pos = json_skip_ws(manifest, pos);
        if (pos >= manifest.size()) {
            json_fail("unterminated array " + key);
        }
        if (manifest[pos] == ']') {
            return out;
        }
        if (manifest[pos] != '{') {
            json_fail("array " + key + " contains non-object value");
        }
        const size_t start = pos;
        pos = json_skip_object(manifest, pos);
        out.push_back(manifest.substr(start, pos - start));
        pos = json_skip_ws(manifest, pos);
        if (pos < manifest.size() && manifest[pos] == ',') {
            pos++;
            continue;
        }
        if (pos < manifest.size() && manifest[pos] == ']') {
            return out;
        }
        json_fail("expected separator in array " + key);
    }
}

inline std::string read_text_file_required(const std::filesystem::path &path)
{
    std::ifstream input(path, std::ios::binary);
    if (!input) {
        manifest_fail("unable to open file: " + path.string());
    }
    input.seekg(0, std::ios::end);
    std::streamoff size = input.tellg();
    if (size < 0) {
        manifest_fail("unable to read file size: " + path.string());
    }
    input.seekg(0, std::ios::beg);
    std::string data(static_cast<size_t>(size), '\0');
    if (!data.empty()) {
        input.read(data.data(), static_cast<std::streamsize>(data.size()));
        if (!input) {
            manifest_fail("unable to read file: " + path.string());
        }
    }
    return data;
}

inline void canonicalize_source_fd_array(std::vector<bpf_insn> &insns,
                                         const std::vector<int> &fd_array)
{
    for (size_t i = 0; i < insns.size(); i++) {
        bpf_insn &insn = insns[i];
        if (insn.code != (BPF_LD | BPF_DW | BPF_IMM)) {
            continue;
        }
        if (insn.src_reg == BPF_PSEUDO_MAP_IDX ||
            insn.src_reg == BPF_PSEUDO_MAP_IDX_VALUE) {
            if (insn.imm < 0 ||
                static_cast<size_t>(insn.imm) >= fd_array.size() ||
                fd_array[static_cast<size_t>(insn.imm)] < 0) {
                manifest_fail("native_loader: source bytecode references invalid fd_array index " +
                              std::to_string(insn.imm));
            }
            const bool value_ref = insn.src_reg == BPF_PSEUDO_MAP_IDX_VALUE;
            insn.imm = fd_array[static_cast<size_t>(insn.imm)];
            insn.src_reg = value_ref ? BPF_PSEUDO_MAP_VALUE : BPF_PSEUDO_MAP_FD;
        }
        i++;
    }
}

inline bool source_has_helper(const std::vector<bpf_insn> &source_insns,
                              int helper_id)
{
    for (const bpf_insn &insn : source_insns) {
        if (insn.code == (BPF_JMP | BPF_CALL) &&
            insn.src_reg == 0 &&
            insn.imm == helper_id) {
            return true;
        }
    }
    return false;
}

template <typename LoadMapInfo>
bool source_has_map_prefix(const std::vector<bpf_insn> &source_insns,
                           const std::string &prefix,
                           LoadMapInfo load_map_info)
{
    if (prefix.empty()) {
        return false;
    }
    for (size_t i = 0; i < source_insns.size(); i++) {
        const bpf_insn &insn = source_insns[i];
        if (insn.code != (BPF_LD | BPF_DW | BPF_IMM)) {
            continue;
        }
        if (insn.src_reg == BPF_PSEUDO_MAP_FD ||
            insn.src_reg == BPF_PSEUDO_MAP_VALUE) {
            bpf_map_info info = load_map_info(static_cast<int>(insn.imm));
            char name[sizeof(info.name) + 1] = {};
            std::memcpy(name, info.name, sizeof(info.name));
            if (starts_with(name, prefix)) {
                return true;
            }
        }
        i++;
    }
    return false;
}

inline std::filesystem::path manifest_relative_path(
    const std::filesystem::path &manifest_path,
    const std::string &native_object)
{
    std::filesystem::path object_path(native_object);
    if (object_path.is_absolute()) {
        return object_path;
    }
    return manifest_path.parent_path() / object_path;
}

inline NativeMapRule parse_native_map_rule(const std::string &entry)
{
    const std::string match = json_required_string(entry, "match");
    NativeMapRule rule{};
    if (match == "exact") {
        rule.match = NativeMapRuleMatch::Exact;
    } else if (match == "prefix") {
        rule.match = NativeMapRuleMatch::Prefix;
    } else if (match == "suffix") {
        rule.match = NativeMapRuleMatch::Suffix;
    } else {
        json_fail("unsupported map rule match " + match);
    }
    rule.pattern = json_required_string(entry, "pattern");
    if (std::optional<std::string> exclude = json_object_string(entry, "exclude")) {
        rule.exclude = *exclude;
    }
    if (std::optional<std::string> native_symbol =
            json_object_string(entry, "native_symbol")) {
        rule.native_symbol = *native_symbol;
    }
    rule.shape.type = static_cast<int>(json_required_u32(entry, "type"));
    rule.shape.key_size = static_cast<uint32_t>(json_object_u64(entry, "key_size").value_or(0));
    rule.shape.value_size = static_cast<uint32_t>(json_object_u64(entry, "value_size").value_or(0));
    rule.shape.max_entries = static_cast<uint32_t>(json_object_u64(entry, "max_entries").value_or(0));
    if (std::optional<uint64_t> inner_type = json_object_u64(entry, "inner_type")) {
        rule.inner_shape.type = static_cast<int>(*inner_type);
        rule.inner_shape.key_size =
            static_cast<uint32_t>(json_object_u64(entry, "inner_key_size").value_or(0));
        rule.inner_shape.value_size =
            static_cast<uint32_t>(json_object_u64(entry, "inner_value_size").value_or(0));
        rule.inner_shape.max_entries =
            static_cast<uint32_t>(json_object_u64(entry, "inner_max_entries").value_or(0));
    }
    rule.object_scoped = json_object_bool(entry, "object_scoped").value_or(false);
    return rule;
}

inline std::vector<NativeMapRule> parse_manifest_map_rules(
    const std::string &manifest)
{
    std::vector<NativeMapRule> rules;
    for (const std::string &entry : json_array_objects(manifest, "map_rules")) {
        rules.push_back(parse_native_map_rule(entry));
    }
    return rules;
}

template <typename LoadMapInfo>
std::optional<ManifestResolution> resolve_native_manifest(
    const std::filesystem::path &manifest_path,
    const bpf_prog_info &prog_info,
    const std::vector<bpf_insn> &source_insns,
    LoadMapInfo load_map_info)
{
    const std::string manifest = read_text_file_required(manifest_path);
    std::vector<std::string> objects = json_array_objects(manifest, "objects");
    if (objects.empty()) {
        manifest_fail("native_loader: manifest has no objects: " + manifest_path.string());
    }

    char prog_name_buf[sizeof(prog_info.name) + 1] = {};
    std::memcpy(prog_name_buf, prog_info.name, sizeof(prog_info.name));
    const std::string prog_name(prog_name_buf);

    std::optional<ManifestResolution> selected;
    for (const std::string &entry : objects) {
        const std::string entry_program = json_required_string(entry, "program");
        if (entry_program != prog_name) {
            continue;
        }
        std::optional<uint64_t> prog_type = json_object_u64(entry, "prog_type");
        if (prog_type && *prog_type != prog_info.type) {
            continue;
        }
        std::optional<uint64_t> source_xlated_len =
            json_object_u64(entry, "source_xlated_len");
        if (source_xlated_len && *source_xlated_len != prog_info.xlated_prog_len) {
            continue;
        }
        std::optional<std::string> map_prefix =
            json_object_string(entry, "source_map_prefix");
        if (map_prefix && !map_prefix->empty() &&
            !source_has_map_prefix(source_insns, *map_prefix, load_map_info)) {
            continue;
        }
        std::optional<uint64_t> required_helper =
            json_object_u64(entry, "source_has_helper");
        if (required_helper &&
            !source_has_helper(source_insns, static_cast<int>(*required_helper))) {
            continue;
        }
        std::optional<uint64_t> forbidden_helper =
            json_object_u64(entry, "source_lacks_helper");
        if (forbidden_helper &&
            source_has_helper(source_insns, static_cast<int>(*forbidden_helper))) {
            continue;
        }

        ManifestResolution candidate{};
        candidate.native_object_path =
            manifest_relative_path(manifest_path,
                                   json_required_string(entry, "native_object"));
        candidate.symbol_name = json_object_string(entry, "symbol").value_or("");
        if (selected &&
            (selected->native_object_path != candidate.native_object_path ||
             selected->symbol_name != candidate.symbol_name)) {
            manifest_fail("native_loader: manifest has ambiguous entries for prog=" +
                          prog_name);
        }
        selected = std::move(candidate);
    }

    if (!selected) {
        return std::nullopt;
    }
    std::error_code ec;
    if (!std::filesystem::exists(selected->native_object_path, ec) || ec) {
        manifest_fail("native_loader: manifest native object is unreadable: " +
                      selected->native_object_path.string());
    }
    selected->map_rules = parse_manifest_map_rules(manifest);
    return *selected;
}
