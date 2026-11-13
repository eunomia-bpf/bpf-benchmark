#pragma once
#include <bpf/btf.h>
#include <cerrno>
#include <cstdint>
#include <stdexcept>
#include <string>
#include <unordered_set>
extern "C" {
#include "../../../vendor/libbpf/src/relo_core.h"
}

inline std::unordered_set<uint32_t> native_kfunc_declarations(const btf *local)
{
    if (!local) throw std::runtime_error("kernel functions require original object BTF");
    const int section_id = btf__find_by_name_kind(local, ".ksyms", BTF_KIND_DATASEC);
    if (section_id == -ENOENT) return {};
    if (section_id < 0) throw std::runtime_error("read original BTF .ksyms section");
    const auto *section = btf__type_by_id(local, section_id);
    const auto *entries = btf_var_secinfos(section);
    std::unordered_set<uint32_t> functions;
    for (uint32_t i = 0; i < btf_vlen(section); ++i) {
        const auto *type = btf__type_by_id(local, entries[i].type);
        if (!type) throw std::runtime_error("read original .ksyms declaration");
        if (btf_kind(type) == BTF_KIND_FUNC) functions.insert(entries[i].type);
    }
    return functions;
}

inline uint32_t native_kfunc_type_id(const btf *local, const btf *kernel,
                                     const std::string &name, bool weak)
{
    if (!local || !kernel)
        throw std::runtime_error("kfunc requires original/vmlinux BTF: " + name);
    const int local_id = btf__find_by_name_kind(local, name.c_str(), BTF_KIND_FUNC);
    if (local_id <= 0)
        throw std::runtime_error("kfunc lacks original BTF declaration: " + name);
    const auto *declaration = btf__type_by_id(local, local_id);
    if (btf_vlen(declaration) != BTF_FUNC_EXTERN)
        throw std::runtime_error("kfunc original BTF is not an extern declaration: " + name);
    const int kernel_id = btf__find_by_name_kind(kernel, name.c_str(), BTF_KIND_FUNC);
    if (kernel_id <= 0) {
        if (weak) return 0;
        throw std::runtime_error("kfunc absent from vmlinux BTF: " + name);
    }
    const auto *target = btf__type_by_id(kernel, kernel_id);
    if (bpf_core_types_are_compat(local, declaration->type, kernel, target->type) <= 0)
        throw std::runtime_error("kfunc prototype differs from vmlinux: " + name);
    return kernel_id;
}
