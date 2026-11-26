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

## arm64 bpf_get_current_task(_btf)

The arm64 JIT inlines bpf_get_current_task and bpf_get_current_task_btf as `mrs x0, sp_el0`
(vendor/linux-framework arch/arm64/net/bpf_jit_comp.c:1608 and bpf_jit_inlines_helper_call). native-link's
arm64 path now emits the same instruction for both calls (main.rs, next to the arm64 get_smp_processor_id inline).
Build and the 9 native-link tests pass. chain-arm64.sh rebuilds the arm64 image and runs the arm64 functional check
(qemu, `make -C kprog/perf/one-image-arm64 check`) after the queued OTel profile.

## arm64 functional check, 2026-11-26

The arm64 image one-image-arm64-20261126T0319Z was built from 24bbf8b89, which contains the ARRAY_OF_MAPS and
get_current_task changes above (make rc 0). `make -C kprog/perf/one-image-arm64 check` then ran qemu TCG
(cortex-a57, 4 vCPUs, 8G), one 10 s sample per app with bpf stats on. All six apps returned rc 0 and their run
metadata say `completed`:

| app | end (UTC) | run |
|---|---|---|
| otelcol-ebpf-profiler/profiling | 04:04:05 | corpus/results/arm64_qemu_corpus_19700101_000013_988050 |
| bcc/set | 04:06:36 | corpus/results/arm64_qemu_corpus_19700101_000012_898849 |
| cilium/agent | 04:17:02 | corpus/results/arm64_qemu_corpus_19700101_000015_309957 |
| tetragon/observer | 04:37:19 | corpus/results/arm64_qemu_corpus_19700101_000013_198696 |
| tracee/monitor | 04:50:13 | corpus/results/arm64_qemu_corpus_19700101_000014_067643 |
| katran | 04:53:24 | corpus/results/arm64_qemu_corpus_19700101_000016_838766 |

Logs: /workspaces/kprog-raw/coordinator/arm64-check-20261125.log, /workspaces/kprog-raw/one-image-arm64-runs/check.log
and the build log /workspaces/kprog-raw/builds/one-image-arm64-20261126T0319Z.log. TCG times serve the functional
check only; arm64 timing runs on the Spark.
