"""C ARRAY helper for native LTO of the checked simulator frontend."""
import ctypes as c
from kernel_function_abi import KernelTypes, Type


def lookup_source(kernel_btf):
    types = KernelTypes(kernel_btf)

    def offset(identity, field):
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
                nested = offset(child, field)
                if nested is not None:
                    return bits // 8 + nested
        return None

    try:
        array = types.lib.btf__find_by_name_kind(types.btf, b'bpf_array', 4)
        map_type = types.lib.btf__find_by_name_kind(types.btf, b'bpf_map', 4)
        base = offset(array, 'map')
        fields = dict(limit=offset(map_type, 'max_entries'),
                      stride=offset(array, 'elem_size') - base,
                      mask=offset(array, 'index_mask') - base,
                      values=offset(array, 'value') - base)
    finally:
        types.close()
    # kernel/bpf/arraymap.c:array_map_lookup_elem. The map type is selected
    # at link time; no runtime type dispatch or extra helper check is added.
    return '''__attribute__((always_inline))
void *__kprog_array_lookup(void *map, const void *key) {
    unsigned index = *(const unsigned *)key;
    if (index >= *(const unsigned *)((const char *)map + %(limit)d))
        return (void *)0;
    unsigned stride = *(const unsigned *)((const char *)map + %(stride)d);
    unsigned mask = *(const unsigned *)((const char *)map + %(mask)d);
    return (char *)map + %(values)d + (unsigned long)stride * (index & mask);
}
''' % fields
