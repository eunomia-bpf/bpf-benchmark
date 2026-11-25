# Direct-native ARRAY_OF_MAPS lookup inlined as the verifier does (coordinator, 2026-11-25)

Operator 2026-11-25T09:59Z: "我们之前说的一些不符合设计的都改掉了吗". design.md (编译流水线) has the direct-native
configuration inline array/percpu lookups and turn the hash family into direct calls, one for one with the kernel's
do_misc_fixups. The kernel also inlines ARRAY_OF_MAPS lookups (kernel/bpf/arraymap.c array_of_map_gen_lookup: the
array element address, then the inner map pointer stored there), while the direct-native loader called
array_of_map_lookup_elem (/workspaces/kprog-raw/coordinator/sa-20261124/inline-more/README.md, C1). Katran's
lru_mapping is the one ARRAY_OF_MAPS on a per-packet path.

## Change

- kprog/libnativeloader/src/native_loader.cpp: lookup kind ArrayOfMaps with the array fields (max_entries,
  elem_size = sizeof(void *), index_mask, value_offset = offsetof(struct bpf_array, value)); link cache version v42.
- native_loader_link_schema.hpp: the kind's name "array_of_maps".
- native-link main.rs and x86.rs: the kind parses, takes the inline array path, and after the element address loads
  the inner map pointer (x86 `mov rax,[rax]`, arm64 `ldr x0,[x0]`). The inner map keeps the outer map's
  inner-template form (`<map>#inner`), as for the other map-in-map path.

## Evidence

native-link release build and loader build pass; native-link's 9 unit tests pass. The guest functional check of
Katran on the rebuilt image follows (chain.sh in this directory); its result goes here.
