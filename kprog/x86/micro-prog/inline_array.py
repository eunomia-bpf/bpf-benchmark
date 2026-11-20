"""C lookup bodies for native LTO through the installed lookup-helper ABI."""
import ctypes as c
import json
from pathlib import Path
from kernel_function_abi import KernelTypes, Type


def field_offset(types, identity, field):
    _, ty = types.base(identity)
    members = (c.c_uint32 * (3 * (ty.info & 0xffff))).from_address(
        c.addressof(ty) + c.sizeof(Type))
    for i in range(ty.info & 0xffff):
        name, child, bits = members[3*i:3*i+3]
        name = types.lib.btf__name_by_offset(types.btf, name).decode()
        bits = bits & 0xffffff if ty.info >> 31 else bits
        if name == field:
            return bits // 8
        if not name:
            nested = field_offset(types, child, field)
            if nested is not None:
                return bits // 8 + nested
    return None


def lookup_source(kernel_btf, lpms=()):
    types = KernelTypes(kernel_btf)

    try:
        array = types.lib.btf__find_by_name_kind(types.btf, b'bpf_array', 4)
        map_type = types.lib.btf__find_by_name_kind(types.btf, b'bpf_map', 4)
        base = field_offset(types, array, 'map')
        fields = dict(limit=field_offset(types, map_type, 'max_entries'),
                      stride=field_offset(types, array, 'elem_size') - base,
                      mask=field_offset(types, array, 'index_mask') - base,
                      values=field_offset(types, array, 'value') - base)
    finally:
        types.close()
    # kernel/bpf/arraymap.c:array_map_lookup_elem. The map type is selected
    # at link time; no runtime type dispatch or extra helper check is added.
    preamble = ''
    choices = ''
    if lpms:
        offsets = lpm_layout(kernel_btf)
        preamble = '#include ' + json.dumps(str(Path(__file__).with_name('native_lpm.h'))) + '\n__KPROG_LPM_CODE\n'
        for index, (name, key_size) in enumerate(lpms):
            alias = f'__kprog_lpm_map_{index}'
            preamble += f'extern unsigned char {alias}[] __asm__({json.dumps(name)});\n'
            choices += (f'    if (map == {alias}) return __kprog_lpm_lookup(map,key,'
                        f'{key_size-4},{(key_size-4)*8},{offsets});\n')
    # __kprog_array_lookup is the installed compiler's native C lookup ABI.
    # Exact named LPM operands select their C body before the ARRAY body;
    # LLVM folds the matching global-pointer identity after inlining.
    return preamble + '''__attribute__((always_inline))
void *__kprog_array_lookup(void *map, const void *key) {
''' + choices + '''
    unsigned index = *(const unsigned *)key;
    if (index >= *(const unsigned *)((const char *)map + %(limit)d))
        return (void *)0;
    unsigned stride = *(const unsigned *)((const char *)map + %(stride)d);
    unsigned mask = *(const unsigned *)((const char *)map + %(mask)d);
    return (char *)map + %(values)d + (unsigned long)stride * (index & mask);
}
''' % fields


def lpm_layout(kernel_btf):
    types = KernelTypes(kernel_btf)
    try:
        trie = types.lib.btf__find_by_name_kind(types.btf, b'lpm_trie', 4)
        node = types.lib.btf__find_by_name_kind(types.btf, b'lpm_trie_node', 4)
        base = field_offset(types, trie, 'map')
        fields = [field_offset(types, trie, 'root') - base,
                  *[field_offset(types, node, name) for name in ('child', 'prefixlen', 'flags', 'data')]]
        return ','.join(str(value) for value in fields)
    finally:
        types.close()
