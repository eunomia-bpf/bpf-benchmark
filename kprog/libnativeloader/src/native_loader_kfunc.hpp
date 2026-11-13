#pragma once
#include <bpf/btf.h>
#include <cstdint>
#include <stdexcept>
#include <string>
extern "C" {
#include "../../../vendor/libbpf/src/relo_core.h"
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
