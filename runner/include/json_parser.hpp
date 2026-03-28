#ifndef JSON_PARSER_HPP
#define JSON_PARSER_HPP

#include "micro_exec.hpp"

#include <cstddef>
#include <cstdint>
#include <optional>
#include <string>
#include <vector>

std::string extract_json_string(const std::string &json, const std::string &key);
std::optional<std::string> extract_json_string_optional(
    const std::string &json,
    const std::string &key);
int64_t extract_json_int(const std::string &json, const std::string &key);
std::optional<int64_t> extract_json_int_optional(
    const std::string &json,
    const std::string &key);
bool extract_json_bool(const std::string &json, const std::string &key);
bool json_char_escaped(const std::string &json, size_t pos);
size_t find_matching_json_delim(
    const std::string &json,
    size_t open_pos,
    char open_ch,
    char close_ch);
std::string extract_json_compound(
    const std::string &json,
    const std::string &key,
    char open_ch,
    char close_ch);
std::vector<std::string> extract_json_string_array(
    const std::string &json,
    const std::string &key);
std::vector<daemon_pass_detail> extract_pass_details(const std::string &json);
std::vector<std::string> changed_pass_names(
    const std::vector<daemon_pass_detail> &details);

#endif
