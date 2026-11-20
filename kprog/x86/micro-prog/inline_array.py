"""C lookup bodies for native LTO through the installed lookup-helper ABI."""
import ctypes as c
import json
from itertools import groupby
from pathlib import Path
from kernel_function_abi import KernelTypes, Type


def field_info(types, identity, field):
    _, ty = types.base(identity)
    members = (c.c_uint32 * (3 * (ty.info & 0xffff))).from_address(
        c.addressof(ty) + c.sizeof(Type))
    for i in range(ty.info & 0xffff):
        name, child, bits = members[3*i:3*i+3]
        name = types.lib.btf__name_by_offset(types.btf, name).decode()
        bits = bits & 0xffffff if ty.info >> 31 else bits
        if name == field:
            return bits // 8, child
        if not name:
            nested = field_info(types, child, field)
            if nested is not None:
                return bits // 8 + nested[0], nested[1]
    return None


def field_offset(types, identity, field):
    member = field_info(types, identity, field)
    return None if member is None else member[0]


def lookup_source(kernel_btf, lpms=(), hashes=(), percpu_arrays=()):
    types = KernelTypes(kernel_btf)

    try:
        array = types.lib.btf__find_by_name_kind(types.btf, b'bpf_array', 4)
        map_type = types.lib.btf__find_by_name_kind(types.btf, b'bpf_map', 4)
        base = field_offset(types, array, 'map')
        fields = dict(limit=field_offset(types, map_type, 'max_entries'),
                      stride=field_offset(types, array, 'elem_size') - base,
                      mask=field_offset(types, array, 'index_mask') - base,
                      values=field_offset(types, array, 'value') - base)
        if percpu_arrays:
            fields['pptrs'] = field_offset(types, array, 'pptrs') - base
    finally:
        types.close()
    # kernel/bpf/arraymap.c:array_map_lookup_elem. The map type is selected
    # at link time; no runtime type dispatch or extra helper check is added.
    preamble = ''
    choices = ''
    if lpms:
        offsets = lpm_layout(kernel_btf)
        preamble = '#include ' + json.dumps(str(Path(__file__).with_name('native_lpm.h'))) + '\n__KPROG_LPM_CODE\n'
        for key_size in sorted({size for _, size in lpms}):
            preamble += (f'static __attribute__((noinline)) void *__kprog_lpm_key_{key_size}(void *map,const void *key) {{ '
                         f'return __kprog_lpm_lookup(map,key,{key_size-4},{(key_size-4)*8},{offsets}); }}\n')
        # Adjacent identical workers share a condition. Preserve first-match
        # order, including when two symbols bind the same physical map.
        for key_size, group in groupby(enumerate(lpms), key=lambda row: row[1][1]):
            aliases = []
            for index, (name, _) in group:
                alias = f'__kprog_lpm_map_{index}'
                preamble += f'extern unsigned char {alias}[] __asm__({json.dumps(name)});\n'
                aliases.append(f'map == {alias}')
            choices += f'    if ({" || ".join(aliases)}) return __kprog_lpm_key_{key_size}(map,key);\n'
    if hashes:
        offsets = ','.join(str(value) for value in hash_layout(kernel_btf).values())
        preamble += '#include ' + json.dumps(str(Path(__file__).with_name('native_hash.h'))) + '\n__KPROG_HASH_CODE\n'
        for key_size in sorted({size for _, size in hashes}):
            preamble += (f'static __attribute__((noinline)) void *__kprog_hash_key_{key_size}(void *map,const void *key) {{ '
                         f'return __kprog_hash_lookup(map,key,{key_size},{offsets}); }}\n')
        for key_size, group in groupby(enumerate(hashes), key=lambda row: row[1][1]):
            aliases = []
            for index, (name, _) in group:
                alias = f'__kprog_hash_map_{index}'
                preamble += f'extern unsigned char {alias}[] __asm__({json.dumps(name)});\n'
                aliases.append(f'map == {alias}')
            choices += f'    if ({" || ".join(aliases)}) return __kprog_hash_key_{key_size}(map,key);\n'
    if percpu_arrays:
        # kernel/bpf/arraymap.c:percpu_array_map_lookup_elem. Keep CPU-address
        # translation in its existing kernel helper, including NMI context.
        preamble += '''
extern void *bpf_this_cpu_ptr(const void *);
typedef unsigned __kprog_percpu_u32 __attribute__((aligned(1),may_alias));
static __attribute__((always_inline)) inline void *
__kprog_percpu_array_lookup(void *map,const void *key) {
    unsigned index=*(const __kprog_percpu_u32 *)key;
    if (index>=*(const unsigned *)((const char *)map+%(limit)d)) return (void *)0;
    unsigned mask=*(const unsigned *)((const char *)map+%(mask)d);
    const void *base=*(void *const *)((const char *)map+%(pptrs)d+
        (unsigned long)(index&mask)*sizeof(void *));
    return bpf_this_cpu_ptr(base);
}
''' % fields
        aliases = []
        for index, name in enumerate(percpu_arrays):
            alias = f'__kprog_percpu_map_{index}'
            preamble += f'extern unsigned char {alias}[] __asm__({json.dumps(name)});\n'
            aliases.append(f'map == {alias}')
        choices = f'    if ({" || ".join(aliases)}) return __kprog_percpu_array_lookup(map,key);\n' + choices
    # __kprog_array_lookup is the installed compiler's native C lookup ABI.
    # Exact named LPM/HASH operands select their C body before the ARRAY body;
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


def hash_layout(kernel_btf):
    types = KernelTypes(kernel_btf)
    try:
        htab = types.lib.btf__find_by_name_kind(types.btf, b'bpf_htab', 4)
        elem = types.lib.btf__find_by_name_kind(types.btf, b'htab_elem', 4)
        # "bucket" is not a unique kernel struct name. Follow the actual
        # htab member's pointer rather than selecting another bucket type.
        _, pointer = types.base(field_info(types, htab, 'buckets')[1])
        bucket = pointer.value
        head = field_info(types, bucket, 'head')[1]
        node = field_info(types, elem, 'hash_node')[1]
        base = field_offset(types, htab, 'map')
        return dict(buckets=field_offset(types, htab, 'buckets')-base,
                    count=field_offset(types, htab, 'n_buckets')-base,
                    seed=field_offset(types, htab, 'hashrnd')-base,
                    stride=types.lib.btf__resolve_size(types.btf, bucket),
                    head=field_offset(types, bucket, 'head')+field_offset(types, head, 'first'),
                    hash_node=field_offset(types, elem, 'hash_node'),
                    next=field_offset(types, node, 'next'),
                    hash_offset=field_offset(types, elem, 'hash'),
                    key_offset=field_offset(types, elem, 'key'))
    finally:
        types.close()
