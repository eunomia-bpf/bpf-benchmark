#include "../../kprog/libnativeloader/src/native_data_layout.hpp"

#include <bpf/btf.h>

#include <cassert>
#include <cstdio>

int main()
{
    btf *types = btf__new_empty();
    assert(types);

    const int u16_id = btf__add_int(types, "u16", 2, 0);
    assert(u16_id > 0);
    const int endpoint_id = btf__add_var(
        types, "__config_endpoint_id", BTF_VAR_GLOBAL_ALLOCATED, u16_id);
    assert(endpoint_id > 0);
    const int datasec_id = btf__add_datasec(types, ".rodata.config", 192);
    assert(datasec_id > 0);
    assert(btf__add_datasec_var_info(types, endpoint_id, 164, 2) == 0);

    const NativeDataSymbolLayout found = find_source_data_symbol_layout(
        types, datasec_id, ".rodata.config", "__config_endpoint_id");
    assert(found.is_datasec);
    assert(found.section_matches);
    assert(found.found);
    assert(found.offset == 164);
    assert(found.size == 2);

    const NativeDataSymbolLayout missing = find_source_data_symbol_layout(
        types, datasec_id, ".rodata.config", "__config_security_label");
    assert(missing.is_datasec);
    assert(missing.section_matches);
    assert(!missing.found);

    const NativeDataSymbolLayout wrong_section = find_source_data_symbol_layout(
        types, datasec_id, ".data", "__config_endpoint_id");
    assert(wrong_section.is_datasec);
    assert(!wrong_section.section_matches);

    const NativeDataSymbolLayout not_datasec = find_source_data_symbol_layout(
        types, u16_id, ".rodata.config", "__config_endpoint_id");
    assert(!not_datasec.is_datasec);

    btf__free(types);
    std::puts("native data layout: PASS");
    return 0;
}
