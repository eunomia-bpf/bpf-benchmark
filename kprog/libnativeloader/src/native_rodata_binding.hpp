#pragma once

#include "native_loader_manifest.hpp"
#include <charconv>
#include <set>

struct NativeReadonlyExtent {
    std::string native_symbol;
    uint64_t offset;
    uint64_t size;
};

struct ProofReadonlyBinding {
    std::string proof_section;
    std::string proof_symbol;
    std::string native_symbol;
    uint64_t size;
};

/* Strict field sets prevent duplicate/unknown specialization inputs from
 * being interpreted differently by the producer and loader.
 */
inline void readonly_json_fields(const std::string &text, std::set<std::string> required)
{
    json_require_object_fields(text, std::move(required), "readonly");
}

inline uint64_t readonly_json_integer(const std::string &text, const std::string &key)
{
    const auto found = json_find_key_value(text, key);
    if (!found) json_fail("missing readonly integer " + key);
    const size_t begin = json_skip_ws(text, *found);
    size_t end = begin;
    while (end < text.size() && std::isdigit(static_cast<unsigned char>(text[end]))) end++;
    const size_t next = json_skip_ws(text, end);
    uint64_t value;
    if (begin == end || (text[begin] == '0' && end - begin != 1) || next == text.size() ||
        (text[next] != ',' && text[next] != '}') ||
        std::from_chars(text.data() + begin, text.data() + end, value).ec != std::errc{})
        json_fail("invalid readonly integer " + key);
    return value;
}

inline std::vector<std::string> readonly_json_objects(const std::string &text)
{
    const auto found = json_find_key_value(text, "objects");
    if (!found) json_fail("missing readonly objects");
    size_t pos = json_skip_ws(text, *found);
    if (pos == text.size() || text[pos++] != '[') json_fail("readonly objects is not an array");
    std::vector<std::string> result;
    for (;;) {
        pos = json_skip_ws(text, pos);
        if (pos == text.size()) json_fail("unterminated readonly objects");
        if (text[pos] == ']') return result;
        const size_t begin = pos;
        pos = json_skip_object(text, pos);
        result.push_back(text.substr(begin, pos - begin));
        pos = json_skip_ws(text, pos);
        if (pos < text.size() && text[pos] == ']') return result;
        if (pos == text.size() || text[pos++] != ',') json_fail("missing readonly object separator");
        pos = json_skip_ws(text, pos);
        if (pos == text.size() || text[pos] == ']') json_fail("trailing readonly objects comma");
    }
}

inline std::vector<NativeReadonlyExtent> parse_native_readonly_layout(const std::string &text,
    uint64_t blob_size)
{
    readonly_json_fields(text, {"version", "objects"});
    if (readonly_json_integer(text, "version") != 1) json_fail("unknown native readonly layout version");
    std::vector<NativeReadonlyExtent> result;
    std::set<std::string> symbols;
    for (const std::string &entry : readonly_json_objects(text)) {
        readonly_json_fields(entry, {"native_symbol", "offset", "size"});
        NativeReadonlyExtent extent{json_required_string(entry, "native_symbol"),
            readonly_json_integer(entry, "offset"), readonly_json_integer(entry, "size")};
        if (!symbols.insert(extent.native_symbol).second) json_fail("duplicate native readonly symbol");
        if (!extent.size || extent.offset > blob_size || extent.size > blob_size - extent.offset)
            json_fail("native readonly extent exceeds blob");
        result.push_back(std::move(extent));
    }
    return result;
}

inline std::vector<ProofReadonlyBinding> parse_proof_readonly_bindings(std::string text)
{
    if (!text.empty() && text.back() == '\0') text.pop_back();
    readonly_json_fields(text, {"version", "objects"});
    if (readonly_json_integer(text, "version") != 1) json_fail("unknown proof readonly layout version");
    std::vector<ProofReadonlyBinding> result;
    std::set<std::string> sections, symbols;
    for (const std::string &entry : readonly_json_objects(text)) {
        readonly_json_fields(entry, {"proof_section", "proof_symbol", "native_symbol", "size"});
        ProofReadonlyBinding binding{json_required_string(entry, "proof_section"),
            json_required_string(entry, "proof_symbol"), json_required_string(entry, "native_symbol"),
            readonly_json_integer(entry, "size")};
        if (!binding.size || !starts_with(binding.proof_section, ".rodata.native.") ||
            !sections.insert(binding.proof_section).second || !symbols.insert(binding.proof_symbol).second)
            json_fail("invalid/duplicate proof readonly extent");
        result.push_back(std::move(binding));
    }
    return result;
}

inline const NativeReadonlyExtent &resolve_readonly_extent(const ProofReadonlyBinding &binding,
    const std::vector<NativeReadonlyExtent> &layout, uint64_t map_size)
{
    if (map_size != binding.size) json_fail("proof readonly map size differs from metadata");
    for (const auto &extent : layout) {
        if (extent.native_symbol != binding.native_symbol) continue;
        if (extent.size != binding.size) json_fail("proof/native readonly object sizes differ");
        return extent;
    }
    json_fail("proof readonly native symbol is absent: " + binding.native_symbol);
}
