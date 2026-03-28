#include "json_parser.hpp"

#include <cctype>
#include <exception>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

namespace {

size_t skip_json_whitespace(const std::string &json, size_t pos)
{
    while (pos < json.size() &&
           std::isspace(static_cast<unsigned char>(json[pos])) != 0) {
        ++pos;
    }
    return pos;
}

[[noreturn]] void fail_missing_json_key(const std::string &key)
{
    fail("missing JSON key: " + key);
}

[[noreturn]] void fail_invalid_json_value(
    std::string_view value_kind,
    const std::string &key)
{
    fail("invalid JSON " + std::string(value_kind) + " for key: " + key);
}

size_t find_json_string_end(const std::string &json, size_t quote_pos)
{
    if (quote_pos >= json.size() || json[quote_pos] != '"') {
        return std::string::npos;
    }
    for (size_t index = quote_pos + 1; index < json.size(); ++index) {
        if (json[index] == '"' && !json_char_escaped(json, index)) {
            return index;
        }
    }
    return std::string::npos;
}

bool is_json_value_terminated(const std::string &json, size_t pos)
{
    if (pos >= json.size()) {
        return true;
    }
    switch (json[pos]) {
    case ',':
    case '}':
    case ']':
        return true;
    default:
        return std::isspace(static_cast<unsigned char>(json[pos])) != 0;
    }
}

size_t find_json_key_value_start(const std::string &json, const std::string &key)
{
    int object_depth = 0;
    int array_depth = 0;
    for (size_t index = 0; index < json.size(); ++index) {
        const char ch = json[index];
        if (ch == '"') {
            const size_t string_end = find_json_string_end(json, index);
            if (string_end == std::string::npos) {
                fail("unterminated JSON string while scanning for key: " + key);
            }
            if (object_depth == 1 && array_depth == 0) {
                const std::string_view token(
                    json.data() + index + 1,
                    string_end - index - 1);
                const size_t after_string = skip_json_whitespace(json, string_end + 1);
                if (token == key &&
                    after_string < json.size() &&
                    json[after_string] == ':') {
                    return skip_json_whitespace(json, after_string + 1);
                }
            }
            index = string_end;
            continue;
        }

        switch (ch) {
        case '{':
            ++object_depth;
            break;
        case '}':
            --object_depth;
            break;
        case '[':
            ++array_depth;
            break;
        case ']':
            --array_depth;
            break;
        default:
            break;
        }
    }
    return std::string::npos;
}

size_t require_json_key_value_start(const std::string &json, const std::string &key)
{
    const size_t value_start = find_json_key_value_start(json, key);
    if (value_start == std::string::npos) {
        fail_missing_json_key(key);
    }
    return value_start;
}

std::string parse_json_string_at(
    const std::string &json,
    size_t value_start,
    const std::string &key)
{
    if (value_start >= json.size() || json[value_start] != '"') {
        fail_invalid_json_value("string value", key);
    }
    const size_t value_end = find_json_string_end(json, value_start);
    if (value_end == std::string::npos) {
        fail_invalid_json_value("string value", key);
    }
    return json.substr(value_start + 1, value_end - value_start - 1);
}

std::optional<std::string> maybe_extract_json_string(
    const std::string &json,
    const std::string &key)
{
    const size_t value_start = find_json_key_value_start(json, key);
    if (value_start == std::string::npos) {
        return std::nullopt;
    }
    if (json.compare(value_start, 4, "null") == 0 &&
        is_json_value_terminated(json, value_start + 4)) {
        return std::nullopt;
    }
    return parse_json_string_at(json, value_start, key);
}

std::optional<int64_t> maybe_extract_json_int(
    const std::string &json,
    const std::string &key)
{
    const size_t value_start = find_json_key_value_start(json, key);
    if (value_start == std::string::npos) {
        return std::nullopt;
    }
    if (json.compare(value_start, 4, "null") == 0 &&
        is_json_value_terminated(json, value_start + 4)) {
        return std::nullopt;
    }

    size_t value_end = value_start;
    if (value_end < json.size() && json[value_end] == '-') {
        ++value_end;
    }
    if (value_end >= json.size() ||
        std::isdigit(static_cast<unsigned char>(json[value_end])) == 0) {
        fail_invalid_json_value("integer value", key);
    }
    while (value_end < json.size() &&
           std::isdigit(static_cast<unsigned char>(json[value_end])) != 0) {
        ++value_end;
    }
    if (!is_json_value_terminated(json, value_end)) {
        fail_invalid_json_value("integer value", key);
    }

    try {
        return std::stoll(json.substr(value_start, value_end - value_start));
    } catch (const std::exception &) {
        fail_invalid_json_value("integer value", key);
    }
}

}  // namespace

std::string extract_json_string(const std::string &json, const std::string &key)
{
    const size_t value_start = require_json_key_value_start(json, key);
    return parse_json_string_at(json, value_start, key);
}

std::optional<std::string> extract_json_string_optional(
    const std::string &json,
    const std::string &key)
{
    return maybe_extract_json_string(json, key);
}

int64_t extract_json_int(const std::string &json, const std::string &key)
{
    const size_t value_start = require_json_key_value_start(json, key);
    if (json.compare(value_start, 4, "null") == 0 &&
        is_json_value_terminated(json, value_start + 4)) {
        fail_invalid_json_value("integer value", key);
    }

    size_t value_end = value_start;
    if (value_end < json.size() && json[value_end] == '-') {
        ++value_end;
    }
    if (value_end >= json.size() ||
        std::isdigit(static_cast<unsigned char>(json[value_end])) == 0) {
        fail_invalid_json_value("integer value", key);
    }
    while (value_end < json.size() &&
           std::isdigit(static_cast<unsigned char>(json[value_end])) != 0) {
        ++value_end;
    }
    if (!is_json_value_terminated(json, value_end)) {
        fail_invalid_json_value("integer value", key);
    }

    try {
        return std::stoll(json.substr(value_start, value_end - value_start));
    } catch (const std::exception &) {
        fail_invalid_json_value("integer value", key);
    }
}

std::optional<int64_t> extract_json_int_optional(
    const std::string &json,
    const std::string &key)
{
    return maybe_extract_json_int(json, key);
}

bool extract_json_bool(const std::string &json, const std::string &key)
{
    const size_t value_start = require_json_key_value_start(json, key);
    if (json.compare(value_start, 4, "true") == 0 &&
        is_json_value_terminated(json, value_start + 4)) {
        return true;
    }
    if (json.compare(value_start, 5, "false") == 0 &&
        is_json_value_terminated(json, value_start + 5)) {
        return false;
    }
    fail_invalid_json_value("boolean value", key);
}

bool json_char_escaped(const std::string &json, size_t pos)
{
    if (pos == 0 || pos >= json.size()) {
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
    const size_t value_start = require_json_key_value_start(json, key);
    if (value_start >= json.size() || json[value_start] != open_ch) {
        fail_invalid_json_value("compound value", key);
    }
    const auto value_end =
        find_matching_json_delim(json, value_start, open_ch, close_ch);
    if (value_end == std::string::npos) {
        fail_invalid_json_value("compound value", key);
    }
    return json.substr(value_start, value_end - value_start + 1);
}

std::vector<std::string> extract_json_string_array(
    const std::string &json,
    const std::string &key)
{
    std::vector<std::string> values;
    size_t cursor = require_json_key_value_start(json, key);
    if (cursor >= json.size() || json[cursor] != '[') {
        fail_invalid_json_value("string array", key);
    }
    ++cursor;
    cursor = skip_json_whitespace(json, cursor);
    if (cursor < json.size() && json[cursor] == ']') {
        return values;
    }

    while (cursor < json.size()) {
        cursor = skip_json_whitespace(json, cursor);
        values.push_back(parse_json_string_at(json, cursor, key));
        const size_t value_end = find_json_string_end(json, cursor);
        if (value_end == std::string::npos) {
            fail_invalid_json_value("string array", key);
        }
        cursor = skip_json_whitespace(json, value_end + 1);
        if (cursor >= json.size()) {
            fail_invalid_json_value("string array", key);
        }
        if (json[cursor] == ']') {
            return values;
        }
        if (json[cursor] != ',') {
            fail_invalid_json_value("string array", key);
        }
        ++cursor;
    }

    fail_invalid_json_value("string array", key);
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
