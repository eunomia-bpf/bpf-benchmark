/* A data symbol the app's DATASEC does not declare, and a private readonly
 * constant, belong to the native linker rather than to the app's map: the
 * loader skipped both before the 2026-05-29 restart and failed on them after
 * it. Cilium's tail_no_service is the recorded case -- 'BPF DATASEC
 * .rodata.config lacks native symbol __config_endpoint_id' in
 * x86_kvm_corpus_20261113_235107_777988 -- for a GLOBAL symbol the app's
 * config map does not carry. */
#include "../libnativeloader/src/native_loader.cpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2) throw std::runtime_error("expected native object path");
    struct btf *types = btf__new_empty();
    if (!types || libbpf_get_error(types)) throw std::runtime_error("empty BTF");
    const int int_type = btf__add_int(types, "int", 4, 0);
    const int declared = btf__add_var(types, "declared", BTF_VAR_GLOBAL_ALLOCATED, int_type);
    const int datasec = btf__add_datasec(types, ".rodata.config", 16);
    btf__add_datasec_var_info(types, declared, 4, 4);

    CompanionLoad load{};
    load.maps.push_back(MapMeta{
        .name = ".rodata.config",
        .fd = 1,
        .kernel_id = 1,
        .type = BPF_MAP_TYPE_ARRAY,
        .key_size = 4,
        .value_size = 16,
        .max_entries = 1,
        .kernel_addr = 0x1000,
        .value_addr = 0x2000,
        .btf_id = 1,
        .btf_value_type_id = static_cast<uint32_t>(datasec),
    });
    // The symbol is absent from the DATASEC: the helper returns nothing
    // rather than throwing, and a private readonly one does the same.
    if (native_data_symbol_offset(types, datasec, ".rodata.config",
                                  "undeclared", 8, false).has_value())
        throw std::runtime_error("undeclared symbol resolved to a map offset");
    if (native_data_symbol_offset(types, datasec, ".rodata.config",
                                  "undeclared", 8, true).has_value())
        throw std::runtime_error("undeclared readonly symbol resolved to a map offset");
    const auto declared_offset = native_data_symbol_offset(
        types, datasec, ".rodata.config", "declared", 4, false);
    if (!declared_offset || *declared_offset != 4)
        throw std::runtime_error("declared symbol lost its DATASEC offset");

    // A section with no DATASEC at all keeps the native offset for a global
    // and belongs to the linker for a private readonly constant.
    const auto native_global = native_data_symbol_offset(
        types, 0, ".rodata.config", "external", 12, false);
    if (!native_global || *native_global != 12)
        throw std::runtime_error("global from a non-DATASEC map lost its native offset");
    if (native_data_symbol_offset(types, 0, ".rodata.config",
                                  "private", 12, true).has_value())
        throw std::runtime_error("private readonly constant claimed a map offset");

    btf__free(types);
    std::cout << "absent and private readonly data symbols left to the linker, "
                 "declared ones bound to their DATASEC offset\n";
}