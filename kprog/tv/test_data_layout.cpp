#include "../libnativeloader/src/native_data_layout.hpp"
#include <cassert>
#include <cstdio>
#include <memory>

struct Layout {
    std::unique_ptr<btf, decltype(&btf__free)> types{btf__new_empty(), btf__free};
    int id;

    Layout(const char *section, const char *variable, int offset, int size)
    {
        assert(types);
        int integer = btf__add_int(types.get(), "integer", size, BTF_INT_SIGNED);
        assert(integer > 0);
        int var = btf__add_var(types.get(), variable, BTF_VAR_STATIC, integer);
        assert(var > 0);
        id = btf__add_datasec(types.get(), section, 16);
        assert(id > 0);
        assert(!btf__add_datasec_var_info(types.get(), var, offset, size));
    }
};

int main()
{
    Layout original(".bss", "counter", 0, 4);
    Layout same(".bss", "counter", 0, 4);
    Layout name(".bss", "different", 0, 4);
    Layout offset(".bss", "counter", 4, 4);
    Layout size(".bss", "counter", 0, 8);
    Layout section(".data", "counter", 0, 4);
    assert(same_data_layout(same.types.get(), same.id, original.types.get(), original.id));
    for (const Layout *wrong : {&name, &offset, &size, &section})
        assert(!same_data_layout(wrong->types.get(), wrong->id, original.types.get(), original.id));
    assert(!same_data_layout(nullptr, 0, original.types.get(), original.id));
    NativeDataSymbolLayout no_datasec{};
    // Tracee's "unknown" exists in both pools, at238 vs253. Native offset
    // must not alias the app map, even when a different literal fits in bounds.
    for (uint64_t native_offset : {16u,253u}) {
        auto private_data=resolve_source_data_symbol_offset(no_datasec,8,native_offset,246,true);
        assert(private_data.kind==NativeDataSymbolOffsetKind::Absent);
        auto ordinary_data=resolve_source_data_symbol_offset(no_datasec,8,native_offset,246);
        assert(ordinary_data.kind==NativeDataSymbolOffsetKind::NativeOffset);
        assert(ordinary_data.offset==native_offset);
    }
    auto declared=find_source_data_symbol_layout(original.types.get(),original.id,".bss","counter");
    auto exact=resolve_source_data_symbol_offset(declared,4,12,16,true);
    assert(exact.kind==NativeDataSymbolOffsetKind::SourceOffset && exact.offset==0);
    assert(resolve_source_data_symbol_offset(declared,8,0,16,true).kind==NativeDataSymbolOffsetKind::SizeMismatch);
    assert(resolve_source_data_symbol_offset(declared,4,0,2,true).kind==NativeDataSymbolOffsetKind::OutOfBounds);
    std::puts("private readonly/source BTF symbol identity and relocated string pools: PASS");
    std::puts("internal map BTF names/offsets/sizes/sections: PASS");
}
