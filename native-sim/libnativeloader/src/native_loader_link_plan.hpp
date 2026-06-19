#pragma once

#include <cstdio>
#include <filesystem>
#include <fstream>
#include <ostream>
#include <string>
#include <vector>

inline void write_json_string(std::ostream &out, const std::string &value)
{
    out << '"';
    for (unsigned char ch : value) {
        switch (ch) {
        case '"':
            out << "\\\"";
            break;
        case '\\':
            out << "\\\\";
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
            if (ch < 0x20) {
                char buf[7];
                std::snprintf(buf, sizeof(buf), "\\u%04x", ch);
                out << buf;
            } else {
                out << static_cast<char>(ch);
            }
            break;
        }
    }
    out << '"';
}

inline void write_json_name_addr(std::ostream &out,
                                 const NativeLinkArgs::NameAddr &item)
{
    out << "{\"name\":";
    write_json_string(out, item.name);
    out << ",\"addr\":" << item.addr << "}";
}

inline void write_json_lookup_site_fields(
    std::ostream &out,
    const NativeLinkArgs::LookupSite &site)
{
    out << "\"kind\":";
    write_json_string(out, site.kind);
    out << ",\"target_addr\":" << site.target_addr
        << ",\"key_offset\":" << site.key_offset
        << ",\"max_entries\":" << site.max_entries
        << ",\"elem_size\":" << site.elem_size
        << ",\"index_mask\":" << site.index_mask
        << ",\"value_offset\":" << site.value_offset
        << ",\"percpu_base_addr\":" << site.percpu_base_addr;
    if (!site.map_name.empty()) {
        out << ",\"map_name\":";
        write_json_string(out, site.map_name);
    }
}

inline void write_json_lookup_site(std::ostream &out,
                                   const NativeLinkArgs::LookupSite &site)
{
    out << "{";
    write_json_lookup_site_fields(out, site);
    out << "}";
}

inline void write_json_lookup_map(std::ostream &out,
                                  const NativeLinkArgs::LookupMap &item)
{
    out << "{\"name\":";
    write_json_string(out, item.name);
    out << ",";
    write_json_lookup_site_fields(out, item.site);
    out << "}";
}

inline void write_json_update_site(std::ostream &out,
                                   const NativeLinkArgs::UpdateSite &site)
{
    out << "{\"kind\":";
    write_json_string(out, site.kind);
    out << ",\"target_addr\":" << site.target_addr
        << ",\"max_entries\":" << site.max_entries
        << ",\"elem_size\":" << site.elem_size
        << ",\"value_size\":" << site.value_size
        << ",\"value_offset\":" << site.value_offset
        << ",\"percpu_base_addr\":" << site.percpu_base_addr
        << "}";
}

template <typename T, typename Writer>
inline void write_json_array(std::ostream &out,
                             const std::vector<T> &items,
                             Writer writer)
{
    out << "[";
    for (size_t i = 0; i < items.size(); i++) {
        if (i != 0) {
            out << ",";
        }
        writer(out, items[i]);
    }
    out << "]";
}

inline std::filesystem::path write_native_link_plan(
    const NativeLinkArgs &link_args,
    const std::filesystem::path &base)
{
    const std::filesystem::path path = base.string() + ".link-plan.json";
    std::ofstream out(path, std::ios::binary | std::ios::trunc);
    if (!out) {
        fail("open native-link plan " + path.string());
    }
    out << "{\"version\":1";
    out << ",\"arm64_helper_call_slot\":";
    write_json_string(out, link_args.arm64_helper_call_slot);
    out << ",\"helpers\":";
    write_json_array(out, link_args.helpers, write_json_name_addr);
    out << ",\"maps\":";
    write_json_array(out, link_args.maps, write_json_name_addr);
    out << ",\"tail_call_maps\":";
    write_json_array(out, link_args.tail_call_maps, write_json_string);
    out << ",\"lookup_sites\":";
    write_json_array(out, link_args.lookup_sites, write_json_lookup_site);
    out << ",\"lookup_maps\":";
    write_json_array(out, link_args.lookup_maps, write_json_lookup_map);
    out << ",\"update_sites\":";
    write_json_array(out, link_args.update_sites, write_json_update_site);
    out << "}\n";
    out.close();
    if (!out) {
        fail("write native-link plan " + path.string());
    }
    return path;
}
