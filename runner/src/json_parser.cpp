#include "json_parser.hpp"

#include <string>
#include <utility>
#include <vector>

std::string extract_json_string(const std::string &json, const std::string &key)
{
    const std::string pattern1 = "\"" + key + "\":\"";
    const std::string pattern2 = "\"" + key + "\": \"";
    auto pos = json.find(pattern1);
    size_t value_start = std::string::npos;
    if (pos != std::string::npos) {
        value_start = pos + pattern1.size();
    } else {
        pos = json.find(pattern2);
        if (pos != std::string::npos) {
            value_start = pos + pattern2.size();
        }
    }
    if (value_start == std::string::npos) {
        return {};
    }
    const auto value_end = json.find('"', value_start);
    if (value_end == std::string::npos) {
        return {};
    }
    return json.substr(value_start, value_end - value_start);
}

int64_t extract_json_int(const std::string &json, const std::string &key)
{
    const std::string pattern1 = "\"" + key + "\":";
    const std::string pattern2 = "\"" + key + "\": ";
    size_t value_start = std::string::npos;
    auto pos = json.find(pattern1);
    if (pos != std::string::npos) {
        value_start = pos + pattern1.size();
    } else {
        pos = json.find(pattern2);
        if (pos != std::string::npos) {
            value_start = pos + pattern2.size();
        }
    }
    if (value_start == std::string::npos) {
        return 0;
    }
    while (value_start < json.size() && json[value_start] == ' ') {
        ++value_start;
    }
    if (value_start >= json.size()) {
        return 0;
    }
    try {
        return std::stoll(json.substr(value_start));
    } catch (...) {
        return 0;
    }
}

bool extract_json_bool(const std::string &json, const std::string &key)
{
    const std::string pattern1 = "\"" + key + "\":true";
    const std::string pattern2 = "\"" + key + "\": true";
    return json.find(pattern1) != std::string::npos ||
           json.find(pattern2) != std::string::npos;
}

bool json_char_escaped(const std::string &json, size_t pos)
{
    if (pos == 0 || pos > json.size()) {
        return false;
    }

    size_t backslash_count = 0;
    size_t cursor = pos;
    while (cursor > 0 && json[--cursor] == '\\') {
        ++backslash_count;
    }
    return (backslash_count % 2) != 0;
}

size_t find_matching_json_delim(
    const std::string &json,
    size_t open_pos,
    char open_ch,
    char close_ch)
{
    if (open_pos >= json.size() || json[open_pos] != open_ch) {
        return std::string::npos;
    }

    int depth = 0;
    bool in_string = false;
    for (size_t index = open_pos; index < json.size(); ++index) {
        const char ch = json[index];
        if (ch == '"' && !json_char_escaped(json, index)) {
            in_string = !in_string;
            continue;
        }
        if (in_string) {
            continue;
        }
        if (ch == open_ch) {
            ++depth;
        } else if (ch == close_ch) {
            --depth;
            if (depth == 0) {
                return index;
            }
        }
    }

    return std::string::npos;
}

std::string extract_json_compound(
    const std::string &json,
    const std::string &key,
    char open_ch,
    char close_ch)
{
    const std::string pattern = "\"" + key + "\"";
    size_t key_pos = json.find(pattern);
    while (key_pos != std::string::npos) {
        const auto colon_pos = json.find(':', key_pos + pattern.size());
        if (colon_pos == std::string::npos) {
            return {};
        }
        size_t value_start = colon_pos + 1;
        while (value_start < json.size() && json[value_start] == ' ') {
            ++value_start;
        }
        if (value_start < json.size() && json[value_start] == open_ch) {
            const auto value_end =
                find_matching_json_delim(json, value_start, open_ch, close_ch);
            if (value_end == std::string::npos) {
                return {};
            }
            return json.substr(value_start, value_end - value_start + 1);
        }
        key_pos = json.find(pattern, key_pos + pattern.size());
    }

    return {};
}

std::vector<std::string> extract_json_string_array(
    const std::string &json,
    const std::string &key)
{
    std::vector<std::string> values;
    const std::string pattern1 = "\"" + key + "\":[";
    const std::string pattern2 = "\"" + key + "\": [";
    size_t array_start = std::string::npos;
    auto pos = json.find(pattern1);
    if (pos != std::string::npos) {
        array_start = pos + pattern1.size();
    } else {
        pos = json.find(pattern2);
        if (pos != std::string::npos) {
            array_start = pos + pattern2.size();
        }
    }
    if (array_start == std::string::npos) {
        return values;
    }
    const auto array_end = json.find(']', array_start);
    if (array_end == std::string::npos) {
        return values;
    }
    const std::string content = json.substr(array_start, array_end - array_start);
    size_t cursor = 0;
    while (true) {
        const auto q1 = content.find('"', cursor);
        if (q1 == std::string::npos) {
            break;
        }
        const auto q2 = content.find('"', q1 + 1);
        if (q2 == std::string::npos) {
            break;
        }
        values.push_back(content.substr(q1 + 1, q2 - q1 - 1));
        cursor = q2 + 1;
    }
    return values;
}

std::vector<daemon_pass_detail> extract_pass_details(const std::string &json)
{
    std::vector<daemon_pass_detail> details;
    const std::string passes_json = extract_json_compound(json, "passes", '[', ']');
    if (passes_json.size() < 2) {
        return details;
    }

    size_t cursor = 1;
    while (cursor + 1 < passes_json.size()) {
        const auto object_start = passes_json.find('{', cursor);
        if (object_start == std::string::npos || object_start + 1 >= passes_json.size()) {
            break;
        }
        const auto object_end =
            find_matching_json_delim(passes_json, object_start, '{', '}');
        if (object_end == std::string::npos) {
            break;
        }

        const std::string pass_object =
            passes_json.substr(object_start, object_end - object_start + 1);
        daemon_pass_detail detail;
        detail.pass_name = extract_json_string(pass_object, "pass_name");
        detail.changed = extract_json_bool(pass_object, "changed");
        detail.sites_applied = static_cast<uint32_t>(
            extract_json_int(pass_object, "sites_applied"));
        detail.sites_skipped = static_cast<uint32_t>(
            extract_json_int(pass_object, "sites_skipped"));
        detail.sites_found = detail.sites_applied + detail.sites_skipped;
        detail.insns_before = extract_json_int(pass_object, "insns_before");
        detail.insns_after = extract_json_int(pass_object, "insns_after");
        detail.insn_delta = extract_json_int(pass_object, "insn_delta");
        if (const auto skip_reasons =
                extract_json_compound(pass_object, "skip_reasons", '{', '}');
            !skip_reasons.empty()) {
            detail.skip_reasons_json = skip_reasons;
        }
        if (const auto diagnostics =
                extract_json_compound(pass_object, "diagnostics", '[', ']');
            !diagnostics.empty()) {
            detail.diagnostics_json = diagnostics;
        }
        details.push_back(std::move(detail));
        cursor = object_end + 1;
    }

    return details;
}

std::vector<std::string> changed_pass_names(
    const std::vector<daemon_pass_detail> &details)
{
    std::vector<std::string> values;
    values.reserve(details.size());
    for (const auto &detail : details) {
        if (detail.changed && !detail.pass_name.empty()) {
            values.push_back(detail.pass_name);
        }
    }
    return values;
}
