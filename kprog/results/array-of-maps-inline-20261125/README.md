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

## bpf_get_current_task(_btf) in the same change set

The kernel's x86-64 fixup inlines bpf_get_current_task and bpf_get_current_task_btf (`mov r0, &current_task;
r0 = this_cpu_ptr(r0); r0 = *(u64 *)r0`); the direct-native linker called the helper. native-link x86.rs now emits
the same three instructions (`mov rax, sign_extend32(&current_task)`, `add rax, gs:[this_cpu_off]`,
`mov rax, [rax]`) when the loader supplies `__native_x86_current_task` (kallsyms `current_task`), next to the
existing bpf_get_smp_processor_id inline; link cache v43. The inline writes rax only, a subset of what the call
clobbers. The 11-20 gs-load version lived in P's header code and was reverted after a Tracee guest crash
(3b5fa4b40); this one is in the linker, the form the verifier uses. arm64 keeps the helper call.

Build: native-link release and loader build pass; 9 native-link tests pass. Guest: `make -C kprog/perf/one-image
check` (default, six apps, 1 x 10 s each) on the image rebuilt from this commit, then the Cilium, Tetragon and
Tracee checked corpus (chain.sh).
