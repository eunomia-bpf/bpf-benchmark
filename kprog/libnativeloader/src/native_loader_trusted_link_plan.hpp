#pragma once

#include <cstdio>
#include <filesystem>
#include <fstream>
#include <ostream>
#include <string>
#include <vector>
#include <memory>
#include <sstream>
#include "native_loader_lto.hpp"

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

// A map symbol that starts with ".L" is an assembler temporary to LLVM: the
// generated C declares it as `extern __u8 x[] __asm__(".L.str.2") __ksym`, and
// llc-18 rejects the reference with "Undefined temporary symbol .L.str.2". The
// metadata name is only a label - the kernel addresses maps by id and value
// offset - so the submission carries an equivalent non-temporary spelling.
inline std::string native_map_label(const std::string &name)
{
    if (name.compare(0, 2, ".L") != 0) {
        return name;
    }
    std::string label = "kprog";
    for (unsigned char ch : name) {
        const bool plain = (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ||
            (ch >= '0' && ch <= '9') || ch == '_' || ch == '.';
        if (plain) {
            label.push_back(static_cast<char>(ch));
        } else {
            char buf[8];
            std::snprintf(buf, sizeof(buf), "_%02x", ch);
            label += buf;
        }
    }
    return label;
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

inline void write_json_map_ops(std::ostream &out,
                               const NativeLinkArgs::MapOps &ops)
{
    out << "{\"name\":";
    write_json_string(out, ops.name);
    out << ",\"update\":" << ops.update
        << ",\"remove\":" << ops.remove
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

#if defined(__x86_64__)
inline const std::string &native_kernel_lto_layout()
{
    static const std::string kernel_layout = [] {
        btf *loaded = btf__load_vmlinux_btf();
        if (!loaded || libbpf_get_error(loaded)) {
            fail("load running kernel BTF for native LTO");
        }
        std::unique_ptr<btf, decltype(&btf__free)> types(loaded, btf__free);
        std::ostringstream facts;
        native_lto::write_layout(facts, types.get());
        return facts.str();
    }();
    return kernel_layout;
}
#endif

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
    out << ",\"helpers\":";
    write_json_array(out, link_args.helpers, write_json_name_addr);
    out << ",\"maps\":";
    write_json_array(out, link_args.maps, write_json_name_addr);
    out << ",\"lookup_sites\":";
    write_json_array(out, link_args.lookup_sites, write_json_lookup_site);
    out << ",\"lookup_maps\":";
    write_json_array(out, link_args.lookup_maps, write_json_lookup_map);
    out << ",\"map_ops\":";
    write_json_array(out, link_args.map_ops, write_json_map_ops);
#if defined(__x86_64__)
    out << ",\"kernel_layout\":" << native_kernel_lto_layout();
#endif
    out << "}\n";
    out.close();
    if (!out) {
        fail("write native-link plan " + path.string());
    }
    return path;
}
