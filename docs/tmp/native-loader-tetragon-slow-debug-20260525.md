# Native Loader Tetragon Slowdown Debug Notes - 2026-05-25

## Scope

Tetragon `native_kernel` is still much slower than baseline BPF JIT after the helper-slot patching fixes. This note records the concrete evidence, current hypotheses, and fixes attempted so the investigation does not live only in chat.

## Current Reproduction

Command:

```sh
BPFREJIT_CORPUS_APPS=tetragon/observer SAMPLES=1 WORKLOAD_DURATION=5 SKIP_REJIT=norejit BPFREJIT_SHIM_NATIVE_LOADER=post BPFREJIT_SHIM_NATIVE_JIT_DUMP_LIMIT=32768 TIMEOUT=1200 make corpus
```

Latest result inspected:

```text
corpus/results/x86_kvm_corpus_20260525_221544_877651
```

Post-native throughput is still far below baseline:

```text
eventfd  79690 -> 21133 ops/s
udp     148950 -> 63151 ops/s
sockfd  169211 -> 99656 ops/s
sockpair 71136 -> 20915 ops/s
```

Hot BPF counters show the real problem is per-run cost, not only workload noise:

```text
baseline generic_tracepo id=211: 14938B, runs=17123176, avg 444 ns/run
post native tracepoint id=714: 14978B, runs=1030385, avg 5264 ns/run

baseline fd_install kprobe id=130: 1875B, avg 212 ns/run
post native fd_install id=544: 2058B, avg 5093 ns/run
```

## Confirmed Non-Causes

Helper call patching is not the current main cause for these hot programs. The linked hot Tetragon dumps have helper calls patched to direct `call rel32`; the linked hot dump has no helper `call *%rax`. The remaining `jmp *%rcx` is the tail-call target jump.

The earlier 128-byte chunk bug is also not the current main cause. The chunk planner now avoids splitting relocation slots, and the hot Tetragon dump has direct helper calls.

Code size alone is not enough to explain the regression. The hot fd_install program only grows from 1875B to 2058B, but avg runtime grows from about 212 ns to about 5093 ns.

## Implementation Facts

The loader creates per-call-site metadata for `bpf_map_lookup_elem`. For arrays and percpu arrays it can inline the lookup. For hash, LRU hash, and percpu hash it redirects the call to `__htab_map_lookup_elem` and emits the same postprocess that the kernel BPF JIT emits.

Map-in-map types are not currently classified as hash in `lookup_site_for_map_meta()` or the source-helper loops. They remain `LookupKind::Call`, targeting `bpf_map_lookup_elem`. This preserves helper semantics, but it is slower than the kernel JIT's verifier rewrite for map-in-map:

```text
HASH_OF_MAPS: __htab_map_lookup_elem; if non-null add value offset; load inner map pointer
ARRAY_OF_MAPS: array bounds/value address; load inner map pointer
```

Kernel references:

```text
vendor/linux-framework/kernel/bpf/hashtab.c: htab_of_map_gen_lookup()
vendor/linux-framework/kernel/bpf/arraymap.c: array_of_map_gen_lookup()
```

The Tetragon hot path uses this heavily through `policy_filter_check()`:

```text
generic_start_process_filter()
  process_call_heap lookup
  config_map lookup
  policy_filter_check(config->policy_id)
    policy_filter_maps HASH_OF_MAPS lookup
    inner policy map HASH lookup(s)
```

## Current Leading Hypothesis

The remaining 5us shape looks like the native path is executing much more of the Tetragon policy/filter/tail-call chain per hook than the baseline hot path. That can come from either:

1. map lookup lowering not matching the verifier's per-map rewrite for map-in-map/policy maps, adding enough helper/indirect-call overhead on a very hot path; or
2. call-site metadata being matched to the wrong native lookup call, which would silently route a call to the wrong map lookup shape/target and change early-exit behavior.

The next checks are:

1. resolve call targets in the hot dump against the runtime ksym base to see whether map-in-map sites call `bpf_map_lookup_elem`, `htab_of_map_lookup_elem`, or `__htab_map_lookup_elem`;
2. audit native linker lookup-site matching for functions with inlined source helpers and split/reordered subprograms;
3. implement the smallest safe fix and rerun Tetragon plus `make micro`.

## 2026-05-25 Update: Dynamic Inner-Map Lookup Gap

Resolved hot fd_install call targets against `vendor/build/x86/linux/System.map` plus the runtime KASLR offset:

```text
baseline 0x111 -> __htab_map_lookup_elem
native   0x0d0 -> bpf_map_lookup_elem

baseline inner policy lookups -> __htab_map_lookup_elem + value postprocess
native   inner policy lookups -> bpf_map_lookup_elem
```

This is a concrete design/performance bug. The native loader only knew the map shape when the source helper's map argument was a static pseudo map fd. In Tetragon `policy_filter_check()`, the outer `policy_filter_maps` lookup returns an inner map pointer in a register (`r8`/`r0`), and later calls use that dynamic pointer:

```text
policy_map = map_lookup_elem(&policy_filter_maps, &policy_id);
map_lookup_elem(policy_map, &cgroupid);
map_lookup_elem(policy_map, &HOST_SELECTOR_MODE);
```

The kernel verifier tracks this inner-map type and the normal BPF JIT lowers those dynamic inner lookups to direct hash lookup (`__htab_map_lookup_elem` plus value offset). Native loader dropped that type information, so the linked native code called the generic helper, which then performed `map->ops->map_lookup_elem` indirect dispatch on a very hot path.

Patch in progress:

- track map-in-map lookup return shape through simple source-BPF register moves;
- recognize Tetragon policy-filter outer map shapes despite kernel map-name truncation;
- lower dynamic inner HASH lookups as direct hash lookup sites;
- lower static `HASH_OF_MAPS` / `ARRAY_OF_MAPS` outer lookups to direct map-op functions instead of generic `bpf_map_lookup_elem`;
- bump native-link cache key to v36.

Build check:

```text
cmake --build runner/build-llvmbpf --target native_loader_shared native_loader -j24
passed
```

## 2026-05-26 Update: Forcing cgroup-id Helper Still Does Not Fix It

Temporary experiment kept the previous branch isolation (`hostSelector`
disabled and tracker substitution skipped), and additionally forced
`policy_filter_check()` to use `get_current_cgroup_id()` directly instead of
`tg_get_current_cgroup_id()`:

```text
MICRO_NATIVE_TETRAGON_POLICY_NO_HOST_SELECTOR
MICRO_NATIVE_TETRAGON_POLICY_NO_TRACKER
MICRO_NATIVE_TETRAGON_POLICY_FORCE_HELPER_CGROUP
```

Result:

```text
corpus/results/x86_kvm_corpus_20260526_010703_474937
```

Workload throughput remains slow:

```text
baseline:
  eventfd   74118 ops/s
  udp      147007 ops/s
  sockfd   183005 ops/s
  sockpair  61413 ops/s

post native with forced helper cgroup:
  eventfd   21363 ops/s
  udp       66758 ops/s
  sockfd   117863 ops/s
  sockpair  20495 ops/s
```

Hot counters are still in the same 5us range:

```text
baseline sys_enter id=214:      462.0 ns/run, runs=17.50M
post native sys_enter id=714:  5400.8 ns/run, runs=0.60M

baseline fd_install id=234:    3128.1 ns/run, runs=55.5K
post native fd_install id=548: 5237.2 ns/run, runs=1.48M
```

The helper cgroup experiment rules out the current `tg_get_current_cgroup_id()`
fallback/CO-RE path as the reason this isolated native build still reaches the
direct policy-map match. The raw helper cgroup id itself is enough for native
to take:

```text
if (map_lookup_elem(policy_map, &cgroupid))
    return true;
```

This makes the next target narrower: either the direct policy lookup is using a
different key/map/value than the original JIT despite matching map literals, or
the slow native counter is not the same dynamic policy state as the baseline
counter. The next concrete check is to inspect the shim logs and disassembly for
`policy_filter_maps`/`tg_cgtracker_map` updates and for the exact direct-lookup
branch in both original and native dumps.

## 2026-05-26 Update: Found Another Tetragon CO-RE Flavor Bug in cgtracker

The normal fd_install native/original disassembly shows both sides use the same
direct policy lookup structure after the recent `HASH_OF_MAPS` fix:

```text
tracker map lookup:
  call __htab_map_lookup_elem
  if rax != 0: rax += 0x38; trackerid = *(u64 *)rax

direct policy lookup:
  call __htab_map_lookup_elem
  if rax != 0: rax += 0x38
  if rax != 0: enter event initialization
```

So the remaining divergence is not an obvious wrong map pointer or missing hash
value postprocess in `policy_filter_check()`.

The next concrete correctness bug is in the program that maintains
`tg_cgtracker_map`. `bpf_cgtracker.c` defines a CO-RE flavor type:

```c
struct cgroup___new {
    int level;
    struct cgroup *ancestors[];
} __attribute__((preserve_access_index));
```

Normal eBPF relies on libbpf CO-RE relocation for:

```c
bpf_core_field_exists(cgrp_new->ancestors)
BPF_CORE_READ(cgrp_new, ancestors[level - 1], kn, id)
```

Native C currently disables preserve-access-index and previously folded
`bpf_core_field_exists(...)` to true for almost everything. That makes native
read `level` at synthetic offset 0 and `ancestors` at synthetic offset 8. In the
generated x86 target header, real `struct cgroup` has `level` after
`self + flags`, and `ancestors[0]` near the end of the struct. Therefore native
cgtracker can compute the wrong parent id and fail to propagate the tracker id
entry that `policy_filter_check()` later needs.

Patch: the Tetragon-only native field-exists shim now also treats
`cgrp_new->ancestors` as false, forcing `cgroup_get_parent_id()` to use the
fallback `cgrp->self.parent` path. That fallback reads real generated
`struct cgroup` fields and does not require flavor-type CO-RE offsets.

Cleaned up the temporary policy-filter experiment macros after this fix:

```text
MICRO_NATIVE_TETRAGON_POLICY_NO_HOST_SELECTOR
MICRO_NATIVE_TETRAGON_POLICY_NO_TRACKER
MICRO_NATIVE_TETRAGON_POLICY_FORCE_HELPER_CGROUP
```

Next steps: rebuild native Tetragon, verify the cgtracker native object no
longer contains the synthetic `cgroup___new` ancestors path, then rerun the
normal Tetragon corpus.

## 2026-05-26 Update: Early-Exit Experiment Proves the 5us Cost Is Behind Policy

Temporarily changed native Tetragon to return immediately after
`policy_filter_check(config->policy_id)` succeeds, before the generic
event-building block. Command:

```sh
BPFREJIT_CORPUS_APPS=tetragon/observer SAMPLES=1 WORKLOAD_DURATION=5 SKIP_REJIT=norejit BPFREJIT_SHIM_NATIVE_LOADER=post BPFREJIT_SHIM_NATIVE_JIT_DUMP_LIMIT=32768 TIMEOUT=1200 make corpus
```

Result:

```text
corpus/results/x86_kvm_corpus_20260526_003928_172156
```

Workload throughput:

```text
baseline:
  eventfd   78927 ops/s
  udp      159219 ops/s
  sockfd   184534 ops/s
  sockpair  55866 ops/s

post native early-exit:
  eventfd  184662 ops/s
  udp      560096 ops/s
  sockfd   326505 ops/s
  sockpair 137924 ops/s
```

Hot counters:

```text
baseline fd_install id=128:     210.1 ns/run, runs=2.81M
post native fd_install id=546:   33.5 ns/run, runs=5.61M

baseline sys_enter id=211:      430.0 ns/run, runs=17.76M
post native sys_enter id=708:    26.2 ns/run, runs=13.47M
```

This rules out native-lab stub/prologue/helper-direct-call fixed cost as the
primary explanation for the 5 us/run Tetragon regression. The native path is
fast when it exits immediately after policy. Therefore the remaining slowdown
comes from native reaching the expensive event initialization path on hot hooks
where the original BPF JIT usually exits earlier. The next target is semantic
divergence in `policy_filter_check()` or in the data it consumes, especially
which of these branches returns true in native:

```text
1. direct pod/container cgroup match:
   map_lookup_elem(policy_map, &cgroupid)

2. hostSelector mode:
   map_lookup_elem(policy_map, &HOST_SELECTOR_MODE)
   policy_map = map_lookup_elem(&policy_filter_maps, &ALL_PODS_POLICY_ID)
   !map_lookup_elem(policy_map, &cgroupid)
```

## 2026-05-26 Update: Disabling HostSelector Does Not Fix the Slow Path

Next temporary experiment removed the post-policy early exit and instead made
native `policy_filter_check()` return false before the hostSelector block:

```text
MICRO_NATIVE_TETRAGON_POLICY_NO_HOST_SELECTOR
```

Result:

```text
corpus/results/x86_kvm_corpus_20260526_004848_076907
```

Workload throughput is still in the same slow range:

```text
baseline:
  eventfd   78608 ops/s
  udp      133500 ops/s
  sockfd   177860 ops/s
  sockpair  57835 ops/s

post native with hostSelector disabled:
  eventfd   19269 ops/s
  udp       59652 ops/s
  sockfd   100733 ops/s
  sockpair  20144 ops/s
```

Hot counters also remain about 5 us/run:

```text
baseline sys_enter id=211:      451.1 ns/run, runs=17.87M
post native sys_enter id=714:  5255.0 ns/run, runs=1.41M

baseline fd_install id=131:     214.3 ns/run, runs=2.71M
post native fd_install id=540: 5081.6 ns/run, runs=1.27M
```

Conclusion: the hostSelector half is not the root cause. Since forcing a false
return after policy made these same hooks tens of ns/run, but disabling
hostSelector leaves them at ~5 us/run, native is taking the direct cgroup match
branch:

```text
if (map_lookup_elem(policy_map, &cgroupid))
    return true;
```

The next isolation target is the value used for that lookup: raw
`tg_get_current_cgroup_id()` versus `cgrp_get_tracker_id()` substitution. If
disabling tracker substitution fixes the slowdown, the bug is in
`tg_cgtracker_map` lookup/key computation or its native map-op lowering. If it
does not, native is using a raw cgroup id that the original path does not use
for the same hot workload.

## 2026-05-26 Update: Disabling Tracker Substitution Also Does Not Fix It

Next temporary experiment kept hostSelector disabled and also skipped
`cgrp_get_tracker_id()`:

```text
MICRO_NATIVE_TETRAGON_POLICY_NO_HOST_SELECTOR
MICRO_NATIVE_TETRAGON_POLICY_NO_TRACKER
```

Result:

```text
corpus/results/x86_kvm_corpus_20260526_005706_219375
```

Workload throughput remains slow:

```text
baseline:
  eventfd   79990 ops/s
  udp      181640 ops/s
  sockfd   152624 ops/s
  sockpair  68107 ops/s

post native with hostSelector+tracker disabled:
  eventfd   21014 ops/s
  udp       70005 ops/s
  sockfd   114984 ops/s
  sockpair  20049 ops/s
```

Hot counters:

```text
baseline sys_enter id=212:      460.4 ns/run, runs=17.99M
post native sys_enter id=710:  5106.3 ns/run, runs=0.78M

baseline fd_install id=128:     209.3 ns/run, runs=2.45M
post native fd_install id=546: 4874.5 ns/run, runs=1.44M
```

This means the native path still returns true from the direct policy-map lookup
when using raw `tg_get_current_cgroup_id()` and with the later policy branches
removed. It does not fully rule out the tracker path as part of the original
semantic difference: the original BPF may replace the raw cgroup id with a
tracker id that does not match the policy map, while native may fail to do so
or may compute a different raw id. The next experiment should force native to
use `get_current_cgroup_id()` directly inside `policy_filter_check()` and keep
hostSelector/tracker disabled. If that remains slow, the raw helper cgroup id
itself matches the policy map in native. If it becomes fast, the bug is in the
native lowering/CO-RE path inside `tg_get_current_cgroup_id()`.

## 2026-05-26 Update: HASH_OF_MAPS Parity Landed, Slowdown Remains

Reran Tetragon after changing static `BPF_MAP_TYPE_HASH_OF_MAPS` lookup
lowering from the wrapper path to the same lower-level shape used by the
original x86 JIT:

```text
corpus/results/x86_kvm_corpus_20260526_002557_028357
```

Workload result is still slow:

```text
eventfd   80095 -> 22168 ops/s
udp      153056 -> 70416 ops/s
sockfd   180642 -> 100584 ops/s
sockpair  64478 -> 19741 ops/s
```

Hot counter result:

```text
baseline fd_install id=128:      209 ns/run, 2.77M runs
post native fd_install id=548:  5338 ns/run, 1.31M runs
baseline sys_enter id=213:       442 ns/run, 17.30M runs
post native sys_enter id=712:   5231 ns/run, 0.80M runs
```

The new fd_install native dump confirms the `HASH_OF_MAPS` fix took effect:

```text
/tmp/tetragon_002557_native_id548_fd539.bin
calls:
  __htab_map_lookup_elem: 6
  htab_of_map_lookup_elem: 0
  bpf_probe_read_compat: 21
  bpf_probe_read_kernel: 5
  bpf_get_current_task: 2
  bpf_get_current_cgroup_id: 1
```

The original shadow dump for the same post replacement has the same htab and
probe-read helper counts except for the extra native `bpf_get_current_task`
calls:

```text
/tmp/tetragon_002557_original_id547_fd521.bin
calls:
  __htab_map_lookup_elem: 6
  bpf_probe_read_compat: 21
  bpf_probe_read_kernel: 5
  bpf_get_current_cgroup_id: 1
```

Static code size is also not a sufficient explanation for fd_install:

```text
original shadow id=547: jited_len=1875
native id=548:          jited_len=1885
```

Current interpretation: the hot cost is almost certainly dynamic path
divergence before the generic tail-call site, not helper call patching or
`HASH_OF_MAPS` wrapper overhead. The native fd_install code has the same map
literal pointers for the early `process_call_heap`, `config_map`, and
`policy_filter_maps` accesses, and the policy-map lookup sequence is now the
same `__htab_map_lookup_elem + value-offset` shape as the original JIT. If the
native path reaches the event-initialization block on most invocations, it will
execute the 20+ `probe_read_compat` calls for namespace/capability collection,
which matches the observed ~5 us/run. The next controlled experiment is to
force a native early-exit immediately before event initialization; if that
returns fd_install to the ~hundreds-of-ns range, the remaining bug is a policy
filter semantic divergence rather than a generic native-lab dispatch cost.

## 2026-05-26 Update: CO-RE Fix Was Correct but Not the 5us Root Cause

Reran Tetragon after the scoped `kernfs_node___old` field-exists fix:

```text
corpus/results/x86_kvm_corpus_20260526_000219_515057
```

The generated native code now reads the current kernel layout for cgroup id
(`cgrp->kn` at `+0x100`, then `kn->id` at `+0x60`), so the old-CO-RE branch
bug is fixed. Runtime did not improve:

```text
baseline workload:
  eventfd  75955 ops/s
  udp     176730 ops/s
  sockfd  155868 ops/s
  sockpair 70457 ops/s

post native workload:
  eventfd  19444 ops/s
  udp      57219 ops/s
  sockfd   84029 ops/s
  sockpair 20767 ops/s

baseline hot tracepoint generic_tracepo id=213:
  453.8 ns/run, runs=17990558

post native hot tracepoint native_lab_stub id=704:
  5386.2 ns/run, runs=1643418

baseline fd_install generic_kprobe_ id=131:
  214.4 ns/run, runs=2528443

post native fd_install native_lab_stub id=548:
  5280.8 ns/run, runs=1098521
```

Conclusion: the CO-RE fix is still required for correctness, but it is not the
main Tetragon slowdown. The next target is native/runtime path divergence:
verify whether map symbols such as `config_map`, `policy_filter_maps`,
`policy_filter_cgroup_maps`, and `process_call_heap` are bound to the exact
maps used by the source program, and whether native reads a different filter
state that causes it to enter the event-building path much more often than the
original JIT.

## 2026-05-26 Update: Fixed HASH_OF_MAPS Lowering Shape

While comparing the hot `fd_install` original/native dumps, the outer
`policy_filter_maps` lookup had a concrete implementation mismatch:

```text
original JIT:
  call __htab_map_lookup_elem
  if rax != 0: rax += htab_value_offset; rax = *(u64 *)rax

native before fix:
  call htab_of_map_lookup_elem
```

The native call is semantically equivalent because `htab_of_map_lookup_elem()`
does the same inner-map extraction in C, but it adds an extra non-inlined
function layer on a very hot policy path and prevents native-link from matching
the verifier/JIT lowering exactly.

Patch: `BPF_MAP_TYPE_HASH_OF_MAPS` lookup sites now use a new native-link
`hash_of_maps` kind. The loader targets `__htab_map_lookup_elem` and passes the
same htab value offset used for normal hash lookups; x86 and arm64 native-link
postprocess the non-null return with `add value_offset; load inner_map`.

Build checks:

```text
cargo build --release --manifest-path native-sim/x86/native_lab/native_link/Cargo.toml
passed

cmake --build runner/build-llvmbpf --target native_loader_shared native_loader -j24
passed
```

Next check: rerun the Tetragon corpus and verify the hot native dump no longer
contains calls to `htab_of_map_lookup_elem` for `policy_filter_maps`; it should
call `__htab_map_lookup_elem` and load the returned inner map pointer inline.

## 2026-05-25 Update: Scoped CO-RE Fix Rebuilt and Verified

After narrowing the field-exists override to `MICRO_NATIVE_TETRAGON`, rebuilt:

```text
make -C vendor/bpf native-tetragon
passed
```

Static dump verification still shows the intended cgroup-id offset in both hot
native Tetragon objects:

```text
bpf_generic_kprobe_v61.native.o:
  addq $0x100, %rdx   # cgrp->kn
  addq $0x60, %rdx    # kn->id

bpf_generic_tracepoint_v61.native.o:
  addq $0x100, %rdx   # cgrp->kn
  addq $0x60, %rdx    # kn->id
```

So the build is now app-scoped and the native object no longer reads the
synthetic `kernfs_node___old` offset 0 path. Next step is the Tetragon corpus
run to test whether this semantic fix removes the 5 us/run behavior.

## 2026-05-25 Update: Fixed BCC Capable Proof Decode Bug

The Tetragon corpus run still failed in the `host-native-bpf-x86` prerequisite,
but the failure was not the Tetragon-specific field-exists macro:

```text
native-link: entry=kprobe__cap_capable_entry ...
Error: iced bailed decoding targ_pid at IP 0xc
```

Root cause: native-link's x86 reachability scanner had a cross-section fallback
that searched by raw VMA address. BPF ELF sections often all start at VMA 0, so
the fallback could treat `.rodata` objects such as `targ_pid` as reachable code
when analyzing another text section. Decoding that 4-byte data object failed.

Patch: decoded direct-call reachability now resolves only text symbols in the
caller section. Relocation-driven reachability still handles defined local
calls, but also resolves to a text symbol at the relocation target instead of a
data symbol.

Manual proof checks after rebuilding native-link:

```text
native-link --input .../bcc/capable.native.o --symbol kprobe__cap_capable_entry --mode proof
  passed, reachable symbols: kprobe__cap_capable_entry

native-link --input .../bcc/capable.native.o --symbol kprobe__cap_capable_exit --mode proof
  passed, reachable symbols: kprobe__cap_capable_exit

native-link --input .../tetragon/bpf_generic_kprobe_v61.native.o --symbol generic_kprobe_event --mode proof
  passed
```

## 2026-05-25 Update: CO-RE Field-Exists Fix Must Be Tetragon-Only

The first implementation made the `kernfs_node___old` field-exists special case
global in `native_compat.h`. That was too broad: a subsequent Tetragon corpus
run rebuilt all native artifacts and failed during the BCC capable proof step:

```text
Error: iced bailed decoding targ_pid at IP 0xc
make[1]: *** [vendor/bpf/Makefile:277: .../native/bcc/capable.proof.ok] Error 1
```

This confirms the CO-RE field-exists override must not affect other apps. The
fix is now scoped behind `MICRO_NATIVE_TETRAGON`, and only the
`native-tetragon` Makefile target defines that flag. Other native corpus apps
keep the existing compile-time `bpf_core_field_exists(...) == true` behavior.

## 2026-05-25 Update: Why Tail-Call No-Op Was Restored

The no-op tail-call experiment was only a diagnostic. Leaving it in place would
make Tetragon semantically wrong: every successful `tail_call(ctx, calls, key)`
would instead fall through as a failed tail call. That can hide downstream work,
but it is not a valid optimization.

The real tail-call correctness/performance gap is different:

- original x86 BPF JIT rewrites helper 12 to `BPF_JMP | BPF_TAIL_CALL` and can
  use poke descriptors for direct tail calls when the verifier knows the prog
  array and key;
- native-link currently sees the C helper call and always emits the indirect
  runtime path (`array->ptrs[key]`, `prog->bpf_func + X86_TAIL_CALL_OFFSET`,
  `jmp *%rcx`);
- matching direct/poke parity needs source-BPF tail-call descriptor metadata or
  kernel-side support for native replacement stubs to participate in poke
  updates. It is a real fix item, but the no-op patch is not that fix.

The negative no-op result also narrowed the Tetragon 5 us/run root cause: the
large cost is paid before the tail-call site. The hot native kprobe/tracepoint
dumps are already in the full event-building path before the final tail call,
so the next target remains the early policy/filter path and native-vs-original
semantic drift there.

## 2026-05-25 Update: Tail-Call No-Op Experiment Was Negative

Patched x86 native-link to treat `bpf_tail_call` as failure fallthrough/no-op
and bumped the cache key to v38, then reran:

```text
BPFREJIT_CORPUS_APPS=tetragon/observer SAMPLES=1 WORKLOAD_DURATION=5 \
  SKIP_REJIT=norejit BPFREJIT_SHIM_NATIVE_LOADER=post \
  BPFREJIT_SHIM_NATIVE_JIT_DUMP_LIMIT=32768 TIMEOUT=1200 make corpus

corpus/results/x86_kvm_corpus_20260525_231339_668528
```

The dump confirmed the experiment took effect:

```text
native id=546 kprobe:     indirect_jmp=0
native id=710 tracepoint: indirect_jmp=0
```

But runtime did not improve:

```text
eventfd  77011 -> 19885 ops/s
udp     162936 -> 63323 ops/s
sockfd  158620 -> 101669 ops/s
sockpair 61925 -> 19695 ops/s

post native kprobe id=546:     avg 5223 ns/run
post native tracepoint id=710: avg 5187 ns/run
```

Conclusion: unconditional native indirect tail-call lowering is still a real
design mismatch that should be fixed before claiming tail-call parity, but it
is not the current 5 us/run Tetragon slowdown. Restoring the prior tail-call
lowering after this experiment; the next investigation target is dynamic path
divergence before the tail-call site, especially whether native C reaches the
full event-building path much more often than the original JIT.

## 2026-05-25 Update: Baseline/Post Pairing Is Correct

Checked the 20260525_225908 Tetragon run to rule out a bad comparison between
different hooks.

For `fd_install`, baseline id=131 is the original `generic_kprobe_` program:

```text
baseline log:
  BPF_PROG_LOAD type=2 name=generic_kprobe_ insn_cnt=421 hash=741cceeefc4e79c6 -> kernel_prog_id=131
  BPF_TASK_FD_QUERY ... prog_id=131 ... symbol=fd_install
metrics:
  bytes_jited=1875 bytes_xlated=3304 avg=211 ns/run
```

Post-native id=548 is the replacement for the same original fd=521/id=547 and
the same `fd_install` attach point:

```text
post log:
  BPF_PROG_LOAD type=2 name=generic_kprobe_ insn_cnt=421 hash=e3bf66d1401bde8b
  native-loader jit-info original fd=521 id=547 type=2 name=generic_kprobe_ jited_len=1875 xlated_len=3304
  native-loader jit-info native fd=539 id=548 jited_len=1840 xlated_len=264
  BPF_TASK_FD_QUERY target_fd=521 ... prog_id=548 ... symbol=fd_install
metrics:
  avg=5043 ns/run
```

For `sys_enter`, baseline id=213 and post-native id=714 are likewise the same
`generic_tracepo` program attached to `sys_enter`:

```text
baseline id=213: insn_cnt=3343, bytes_jited=14938, symbol=sys_enter, avg=412 ns/run
post id=714: original id=713 jited_len=14938 xlated_len=26568,
             native id=714 jited_len=13416 xlated_len=1704,
             symbol=sys_enter, avg=5235 ns/run
```

The source hashes differ between baseline and post because Tetragon is started
twice and map fd immediates differ. Pairing by attach symbol, program type,
instruction count, and original jited/xlated length is the right comparison.

Also checked the key fd_install map literal addresses in the original and
native dumps. `process_call_heap`, `config_map`, `policy_filter_maps`,
`tg_conf_map`, `tg_cgtracker_map`, and the `kprobe_calls` tail-call map resolve
to the same kernel map pointers in both dumps. That weakens the "wrong map
instance" hypothesis for the hot fd_install path.

## 2026-05-25 Update: Found CO-RE Field-Exists Semantic Bug

The fd_install native dump has a concrete semantic difference in
`tg_get_current_cgroup_id()` / `get_cgroup_id()`:

```text
original BPF JIT:
  read cgrp->kn at cgrp + 0x100
  read kn->id at kn + 0x60

native C:
  read cgrp->kn at cgrp + 0x100
  read from kn + 0x0
```

The bad native path comes from Tetragon's compatibility branch:

```c
if (bpf_core_field_exists(((struct kernfs_node___old *)0)->id.id)) {
    struct kernfs_node___old *old_kn = (void *)kn;
    BPF_CORE_READ_INTO(&id, old_kn, id.id);
} else {
    probe_read_kernel(&id, sizeof(id), _(&kn->id));
}
```

In normal BPF, libbpf CO-RE relocates this flavor type check/read against the
target kernel BTF. In native C, `native_compat.h` had hard-coded
`bpf_core_field_exists(...)` to true and disabled preserve-access-index
relocations. That made native compile the synthetic `kernfs_node___old` layout
literally, so `old_kn->id.id` is offset 0. The original JIT uses the real target
layout and reads `struct kernfs_node::id` at offset 0x60.

Why this matches the slowdown: `policy_filter_check()` uses the cgroup id to
probe policy maps and the all-pods map. A bogus id can miss those maps and make
native incorrectly classify the event as a host workload, entering the full
event-building path. That explains why tail-call no-op and map-op dispatch fixes
did not move the 5 us/run cost: the expensive work is reached before tail-call.

Patch applied: `vendor/bpf/native_compat.h` now special-cases the stringified
`((struct kernfs_node___old *)0)->id.id` field-exists probe to false, so native
Tetragon uses the real generated `kn->id` field offset instead of the synthetic
flavor offset.

Build/dump verification:

```text
make -C vendor/bpf native-tetragon
passed

new bpf_generic_kprobe_v61.native.o:
  read cgrp->kn at cgrp + 0x100
  addq $0x60, %rdx
  read kn->id at kn + 0x60
```

So the static native object now matches the original JIT's cgroup-id offset for
this path. Next step is rerunning Tetragon corpus to see whether the 5 us/run
runtime collapse disappears or whether another semantic gap remains.

## 2026-05-25 Update: LRU Per-CPU Direct Map-Op Fix Did Not Move Runtime

Reran Tetragon after the LRU percpu hash lowering patch:

```text
BPFREJIT_CORPUS_APPS=tetragon/observer SAMPLES=1 WORKLOAD_DURATION=5 \
  SKIP_REJIT=norejit BPFREJIT_SHIM_NATIVE_LOADER=post \
  BPFREJIT_SHIM_NATIVE_JIT_DUMP_LIMIT=32768 TIMEOUT=1200 make corpus

corpus/results/x86_kvm_corpus_20260525_225908_703507
```

Workload throughput is still slow:

```text
eventfd  80670 -> 21106 ops/s
udp     155831 -> 69131 ops/s
sockfd  187595 -> 112712 ops/s
sockpair 65436 -> 19934 ops/s
```

Hot BPF counters are still about 5 us/run:

```text
baseline generic_tracepo id=213: 14938B, avg 412 ns/run
post native tracepoint id=714:  13416B, avg 5235 ns/run
post native kprobe id=548:       1840B, avg 5043 ns/run
```

The call-target dump confirms the LRU patch itself did apply:

```text
original id=713:
  htab_lru_percpu_map_lookup_elem: 70
  htab_lru_percpu_map_update_elem: 40
  bpf_map_lookup_elem: 0
  bpf_map_update_elem: 0

native id=714:
  htab_lru_percpu_map_lookup_elem: 70
  htab_lru_percpu_map_update_elem: 40
  bpf_map_lookup_elem: 0
  bpf_map_update_elem: 0
```

The smaller hot fd_install kprobe also no longer has generic map lookup calls:

```text
native id=548:
  htab_of_map_lookup_elem: 2
  __htab_map_lookup_elem: 4
  bpf_map_lookup_elem: 0
```

Conclusion: the generic-helper/map-op lowering bugs were real and worth fixing,
but they are not the main 5 us/run cause. The remaining root cause must be a
larger fixed overhead or semantic mismatch in the native execution/attach path.
Next checks:

1. compare native stub entry/exit code against original JIT for the hot 1840B
   kprobe;
2. inspect the native lab module replacement path for per-run work outside the
   dumped BPF body;
3. check whether BPF stats time includes native wrapper/module trampoline work
   that does not appear in the `jited_len` body;
4. isolate with micro again after the next fix to make sure earlier micro stage
   1/2 did not regress.

## 2026-05-25 Update: Tail-Call Lowering Is the Next Concrete Mismatch

The hot native dumps contain exactly one indirect jump:

```text
native id=548 kprobe:     0x69e:  jmp *%rcx
native id=714 tracepoint: 0x344b: jmp *%rcx
```

This is not a helper call. It is native-link's manual lowering for
`bpf_tail_call(ctx, map, key)`: bounds check `map->max_entries`, check the
tail-call counter, read `array->ptrs[key]`, then jump to
`prog->bpf_func + X86_TAIL_CALL_OFFSET`.

The original x86 BPF JIT site for the same hot tracepoint currently looks like
the direct/poke tail-call template in its unpatched state:

```text
3a24: mov -0xa8(%rbp),%rax
3a2b: cmpq $0x21,(%rax)
3a2f: jae 0x3a4f
3a31: jmp 0x3a4f
3a36: addq $0x1,(%rax)
...
3a4a: nopl 0x0(%rax,%rax,1)
3a4f: xor %eax,%eax
```

So the native path is not mirroring the verifier/JIT tail-call lowering. The
kernel JIT uses `BPF_JMP|BPF_TAIL_CALL` plus poke descriptors; native-link
sees a C helper call and always emits the indirect runtime path. That can:

- add a runtime prog-array lookup where the original site would be a direct
  patched branch or a no-op bypass;
- tail-call into a different replacement state than the original JIT's poke
  descriptors;
- make the caller's BPF stats include a much larger descendant chain.

This is now a stronger explanation for the 200-400 ns -> 5 us gap than map-op
dispatch. Next experiment: temporarily lower x86 native `bpf_tail_call` as
fail/no-op and rerun Tetragon. If the 5 us cost disappears, the fix direction
is to stop using native-link's unconditional indirect tail-call lowering and
instead either mirror the oracle `BPF_JMP|BPF_TAIL_CALL`/poke behavior or
conservatively leave tail-call programs out of native-lab replacement until
that is implemented.

## 2026-05-25 Update: First Dynamic-Inner Fix Was Not Enough

Reran the same Tetragon workload after the dynamic inner-map patch:

```text
corpus/results/x86_kvm_corpus_20260525_224543_549336
```

The result is still slow:

```text
eventfd  79066 -> 21305 ops/s
udp     152243 -> 67002 ops/s
sockfd  155240 -> 107267 ops/s
sockpair 66395 -> 20188 ops/s

post native fd_install id=540: avg 4896 ns/run
post native sys_enter id=712:  avg 5204 ns/run
```

The patch did change the small fd_install program in the intended direction:

```text
native id=540 calls:
  htab_of_map_lookup_elem: 2
  __htab_map_lookup_elem: 4
  bpf_map_lookup_elem: 0
```

So the map-in-map/dynamic inner lookup gap was real, but it is not the full
root cause.

The larger hot `generic_tracepo`/`sys_enter` dump shows the next concrete gap.
Original BPF JIT direct-call targets:

```text
original id=711:
  htab_lru_percpu_map_lookup_elem: 70
  htab_lru_percpu_map_update_elem: 40
  bpf_map_lookup_elem: 0
  bpf_map_update_elem: 0
```

Native linked code:

```text
native id=712:
  bpf_map_lookup_elem: 70
  bpf_map_update_elem: 40
  htab_lru_percpu_map_lookup_elem: 0
  htab_lru_percpu_map_update_elem: 0
```

This is a bigger design/performance issue than helper indirect calls. The
helper slot is still patched to a direct call, but the direct call target is the
generic helper. The generic helper then performs `map->ops` dispatch for every
hot LRU percpu hash access. The original verifier/JIT has already resolved
those sites to the concrete map-op functions.

Patch in progress:

- add kallsyms targets for `htab_lru_percpu_map_lookup_elem` and
  `htab_lru_percpu_map_update_elem`;
- lower `BPF_MAP_TYPE_LRU_PERCPU_HASH` lookup sites to a direct map-op call;
- lower `BPF_MAP_TYPE_LRU_PERCPU_HASH` update sites to a direct map-op call;
- bump native-link cache key to v37.

Build check:

```text
cmake --build runner/build-llvmbpf --target native_loader_shared native_loader -j24
passed
```

## 2026-05-26 Update: cgroup___new Field-Exists Fix Rebuild Verification

Rebuilt the native Tetragon objects after extending the native CO-RE
field-exists shim:

```text
make -C vendor/bpf native-tetragon
passed
```

The temporary policy-filter experiment macros are cleaned from the Makefile and
policy-filter source; the only remaining relevant string matches are the
intentional native compatibility checks:

```text
vendor/bpf/native_compat.h:
  kernfs_node___old id.id => false
  cgrp_new->ancestors    => false
```

Static dump of `bpf_cgtracker.native.o` now shows
`tg_cgtracker_cgroup_mkdir()` taking the fallback parent-pointer path:

```text
movq (%rdi), %rbx
leaq 0x100(%rbx), %rdx      # cgrp->self.parent
...
addq $0x60, %rdx            # parent->kn->id
...
addq $0xc0, %rbx            # cgrp->kn
...
addq $0x100, %rdx           # cgrp->self.parent
...
addq $0x60, %rdx            # parent->kn->id
```

This is no longer the synthetic `struct cgroup___new` path that reads `level`
at offset 0 and `ancestors` at offset 8. The fix therefore changes codegen in
the intended way. Next step is a normal Tetragon corpus run to check whether
the tracker map now has the same contents as the baseline path and whether the
hot fd_install/sys_enter programs stop entering the 5 us event-building path.

## 2026-05-26 Update: Normal Run After cgtracker Fix Still Slow

Reran the normal Tetragon workload after the `cgroup___new->ancestors`
field-exists fix:

```text
BPFREJIT_CORPUS_APPS=tetragon/observer SAMPLES=1 WORKLOAD_DURATION=5 \
  SKIP_REJIT=norejit BPFREJIT_SHIM_NATIVE_LOADER=post \
  BPFREJIT_SHIM_NATIVE_JIT_DUMP_LIMIT=32768 TIMEOUT=1200 make corpus

corpus/results/x86_kvm_corpus_20260526_012626_555056
```

Workload throughput remains in the same slow range:

```text
baseline:
  eventfd   79056 ops/s
  udp      142136 ops/s
  sockfd   148093 ops/s
  sockpair  57852 ops/s

post native:
  eventfd   20296 ops/s
  udp       62556 ops/s
  sockfd   101046 ops/s
  sockpair  19682 ops/s
```

Hot BPF counters:

```text
baseline fd_install id=128: 209 ns/run, runs=2.42M
baseline sys_enter  id=214: 479 ns/run, runs=17.18M

post native fd_install                  id=544: 4913 ns/run, runs=1.29M
post native security_file_permission    id=560: 5195 ns/run, runs=0.84M
post native sys_enter                   id=708: 5154 ns/run, runs=1.23M
```

So the two CO-RE flavor fixes are real correctness fixes, but they are not the
5 us root cause.

The latest `fd_install` native dump changes the current hypothesis. The hot
entry first looks up `config_map`, reads `config->policy_id` at offset `0x64`,
and branches around `policy_filter_check()` when the value is zero:

```text
mov 0x64(%rax), %ecx
test %ecx, %ecx
je <event setup block>
```

The bundled benchmark policies mostly do not use pod/container/host selectors.
For those hooks, Tetragon's documented meaning of `policy_id == 0` is "always
applies and no check will be performed." That means the previous
hostSelector/tracker/cgroup-id experiments probably did not exercise the hot
path that dominates this run. They were still useful for ruling out bugs in
those branches, but not sufficient to explain `fd_install`/`sys_enter`.

The current suspect is the generic entry setup block after the policy bypass:

```text
selector zeroing
generic_path_init()
task = get_current_task()
get_namespaces(&msg->ns, task)
get_current_subj_caps(&msg->caps, task)
tail_call(ctx, calls, TAIL_CALL_FILTER)
```

This is also why the earlier post-policy early-exit experiment was fast, and
why the tail-call no-op experiment stayed slow: both results are consistent
with the expensive work happening before the first tail-call site. However, if
`policy_id == 0`, the original JIT should enter the same setup block. Therefore
the next question is not just "does native take the wrong branch?", but whether
the same namespace/capability helper sequence is much more expensive under the
native-lab wrapper or whether native and original still diverge inside that
setup. Next experiments isolate `get_namespaces()` and
`get_current_subj_caps()` separately with temporary native-only macros.

## 2026-05-26 Update: Entry Context Skip Experiment Started

Temporary diagnostic macro added only to the native Tetragon build:

```text
MICRO_NATIVE_TETRAGON_SKIP_ENTRY_CONTEXT
```

It skips the two calls below in both generic kprobe/rawtp/uprobe/fentry entry
via `generic_start_process_filter()` and `generic_tracepoint_event()`:

```c
get_namespaces(&msg->ns, task);
get_current_subj_caps(&msg->caps, task);
```

This is intentionally not a valid final optimization because namespace and
capability selectors consume `msg->ns` and `msg->caps`. It is only to identify
whether the ~5 us native cost is concentrated in this helper-heavy entry context
collection block.

## 2026-05-26 Update: Entry Context Skip Result

Run:

```bash
BPFREJIT_CORPUS_APPS=tetragon/observer SAMPLES=1 WORKLOAD_DURATION=5 \
  SKIP_REJIT=norejit BPFREJIT_SHIM_NATIVE_LOADER=post \
  BPFREJIT_SHIM_NATIVE_JIT_DUMP_LIMIT=32768 TIMEOUT=1200 make corpus
```

Artifact:

```text
corpus/results/x86_kvm_corpus_20260526_014650_314273
```

Workload counters:

```text
baseline:
  eventfd   81365 ops/s
  udp      159510 ops/s
  sockfd   155736 ops/s
  sockpair  64837 ops/s

post native with entry context skipped:
  eventfd  176286 ops/s
  udp      363413 ops/s
  sockfd   317206 ops/s
  sockpair 142639 ops/s
```

Hot BPF counters:

```text
baseline sys_enter generic_tracepo id=211: 427 ns/run, runs=17.47M
post native sys_enter native_lab_stub id=714: 635 ns/run, runs=1.77M

post native fd_install native_lab_stub id=538: 61 ns/run, runs=5.49M
```

Conclusion: the 5 us/run cliff is concentrated in the namespace/capability
entry context block, not in helper-call patching, map lookup lowering, or tail
call dispatch by itself. The skip is still semantically invalid, so it was
removed and replaced with a forward native-only implementation for the same
data: under `MICRO_NATIVE_TETRAGON`, `get_namespaces()` and
`get_current_subj_caps()` now read current-task kernel fields directly with
null checks instead of issuing many `probe_read` helper calls. The original BPF
build keeps the upstream helper-based code. Next step is to rebuild and rerun
Tetragon with that direct-read implementation.

## 2026-05-26 Update: Direct Current-Context Result

Run after removing the temporary entry-context skip and keeping the native-only
direct current-context implementation:

```bash
BPFREJIT_CORPUS_APPS=tetragon/observer SAMPLES=1 WORKLOAD_DURATION=5 \
  SKIP_REJIT=norejit BPFREJIT_SHIM_NATIVE_LOADER=post \
  BPFREJIT_SHIM_NATIVE_JIT_DUMP_LIMIT=32768 TIMEOUT=1200 make corpus
```

Artifact:

```text
corpus/results/x86_kvm_corpus_20260526_020106_830128
```

Workload counters:

```text
baseline:
  eventfd   77016 ops/s
  udp      129293 ops/s
  sockfd   153130 ops/s
  sockpair  56141 ops/s

post native with direct current-context reads:
  eventfd  155324 ops/s
  udp      342882 ops/s
  sockfd   274564 ops/s
  sockpair 118251 ops/s
```

Hot BPF counters:

```text
baseline sys_enter generic_tracepo id=215: 505 ns/run, runs=16.89M
baseline fd_install generic_kprobe_ id=135: 541 ns/run, runs=2.89M

post native sys_enter native_lab_stub id=704: 553 ns/run, runs=8.84M
post native fd_install native_lab_stub id=538: 61 ns/run, runs=4.67M
post native security_file_permission native_lab_stub id=558: 53 ns/run, runs=5.91M
```

Conclusion: the real 5 us/run regression is fixed by avoiding helper-based
`probe_read` collection for fields that come from the current task context in
the native Tetragon build. The direct implementation keeps null checks and only
applies under `MICRO_NATIVE_TETRAGON`; the BPF object still uses the upstream
helper/CO-RE path. Remaining slow rows in this run have tiny run counts
(for example 27 or 72 runs) and are not the throughput bottleneck. The next
guardrail is to run the micro suite to catch any native loader regression caused
by the map/lowering changes made during this investigation.

## 2026-05-26 Update: Micro Smoke After Tetragon Fix

Run:

```bash
SAMPLES=1 WARMUPS=0 INNER_REPEAT=10 make micro
```

Artifact:

```text
micro/results/x86_kvm_micro_20260526_020825_895020
```

Build/proof status:

```text
native-sim x86 micro proof build: 29/29 ok
make micro exit status: 0
metadata.json status: completed
```

Result check from `details/result.json`:

```text
benchmarks: 29
runtime samples: 87
result/retval mismatches: 0
native compile_ns range: 29045 .. 47936
native exec_ns range: 10 .. 15242
```

Selected raw rows:

```text
simple:
  native  compile=29045 ns exec=10 ns
  kernel  compile=247562 ns exec=37 ns
  llvmbpf compile=6490446 ns exec=52 ns

simple_packet:
  native  compile=42518 ns exec=12 ns
  kernel  compile=331665 ns exec=32 ns
  llvmbpf compile=6124698 ns exec=51 ns

tetragon_process_event_arg_filter:
  native  compile=32511 ns exec=278 ns
  kernel  compile=12706069 ns exec=545 ns
  llvmbpf compile=18950218 ns exec=301 ns

tc_packet_checksum_fold:
  native  compile=32036 ns exec=15242 ns
  kernel  compile=33293986 ns exec=17655 ns
  llvmbpf compile=11038457 ns exec=15418 ns
```

Conclusion: the Tetragon-specific direct current-context change and the map
lowering fixes did not break the existing x86 micro smoke. This does not replace
the full corpus methodology, but it is a useful guardrail that stage1/stage2
native code generation still builds, proves, runs, and returns the expected
values after the Tetragon fix.

## 2026-05-26 Update: Stage2 Native-Kernel Hash Lookup Failure

The default micro smoke above did not exercise the `native_kernel` runtime, so I
ran the stage2 maps/helpers suite explicitly through the Makefile:

```bash
SUITE=micro/config/micro_stage2.yaml RUNTIMES="native_kernel kernel" \
  SAMPLES=1 WARMUPS=0 INNER_REPEAT=10 make micro
```

Artifact:

```text
micro/results/x86_kvm_micro_20260526_021759_530068
```

Status:

```text
metadata.json status: error
proof build: 13/13 ok
passing native_kernel rows before failure:
  helper_only_uid_gid
  map_array_lookup
  map_array_index_packet
  map_percpu_array
  combined_helper_map
first failing class:
  helper_chain_simple / map_hash_lookup / map_hash_str_key / lru/percpu hash
```

The pattern was specific to hash-like map lookup lowering. The emitted
`native-link` command for `map_hash_lookup` carried a lowered lookup site:

```text
--lookup-site 0=hash,<__htab_map_lookup_elem>,56,...,test_hash
```

but the companion JIT oracle still describes the original BPF helper call target
for `bpf_map_lookup_elem`. The old `resolve_site_target()` path treated those as
conflicting addresses. That check is correct for ordinary helper calls, but
wrong for hash/lru/percpu/hash-of-maps lowerings where native-link deliberately
replaces the helper target with a map implementation function and then applies a
postprocess step (`+ key_offset`, percpu base, LRU ref bit, or inner-map load).

Fix applied:

```text
native-sim/x86/native_lab/native_link/src/main.rs
native-sim/x86/native_lab/native_link/src/x86.rs
```

`resolve_lookup_site_target()` now keeps the oracle call stream aligned and uses
the explicit lowered target address for hash-like lookup kinds. Array/percpu-
array lookup remains fully inlined and should not resolve a call target.

Local build guardrail:

```bash
cargo check --manifest-path native-sim/x86/native_lab/native_link/Cargo.toml
```

Status:

```text
ok
```

Next step: rerun the focused stage2 map/hash benchmark, then the full stage2
native-kernel suite if the focused run passes.

## 2026-05-26 Update: Focused Stage2 Rerun Still Fails, Need Full Stderr

Focused rerun:

```bash
SUITE=micro/config/micro_stage2.yaml RUNTIMES="native_kernel kernel" \
  BENCH=map_hash_lookup SAMPLES=1 WARMUPS=0 INNER_REPEAT=10 make micro
```

Artifact:

```text
micro/results/x86_kvm_micro_20260526_022657_953547
```

Status:

```text
metadata.json status: error
benchmark: map_hash_lookup
runs: none
```

The result still fails before a native-kernel sample is recorded, but the
artifact only preserves the tail of the native-loader error. Because
`native_loader.cpp` appended the very long native-link command after stderr, the
micro driver's tail captured only the command tail:

```text
--lookup-site 0=hash,<__htab_map_lookup_elem>,56,...,test_hash
--update-site 0=call,<bpf_map_update_elem>,...
```

Manual native-link reproduction outside the benchmark with the current patched
binary, the generated proof object, and an oracle file from an older successful
run confirmed that the lookup-target/oracle mismatch itself is no longer the
blocking error: hash lookup kernel linking succeeds and emits the expected
postprocess sequence:

```text
call <update>
call <lowered hash lookup>
test rax, rax
je ...
add rax, 0x38
```

Diagnostic fix applied:

```text
native-sim/libnativeloader/src/native_loader.cpp
```

For native-link kernel failures, the native-loader now prints the command before
the captured stderr, so the micro driver's tail keeps the actionable native-link
error instead of losing it behind the long argument list. This is a fail-fast
diagnostic fix, not a benchmark summary change.

Next step: rerun the focused `map_hash_lookup` stage2 case and inspect the real
native-link stderr.

## 2026-05-26 Update: Map Update Oracle Target Mismatch

Focused rerun after moving stderr to the tail:

```text
micro/results/x86_kvm_micro_20260526_023341_506770
```

The real native-link error is:

```text
Error: x86 update-site 0 target 0xffffffff904b90c0 conflicts with companion JIT oracle target 0xffffffff904c9960
```

This is the same design class as lookup, but for `bpf_map_update_elem`: the
companion BPF JIT is not necessarily calling the generic helper address. It can
patch a map helper call to a map-specific implementation target. Native-link
therefore must treat the companion JIT oracle as the authoritative target for
map helper call sites. The encoded generic helper address is only a fallback
when no oracle is available.

Fix applied:

```text
native-sim/x86/native_lab/native_link/src/main.rs
native-sim/x86/native_lab/native_link/src/x86.rs
```

`resolve_oracle_preferred_site_target()` now resolves map lookup `call` sites,
map update `call` sites, and `bpf_map_delete_elem` helper calls by consuming the
oracle target when available and only falling back to the encoded helper target
without an oracle. Lowered hash-like lookup sites still consume the oracle for
ordering but use their explicit lowered implementation target. The old strict
`resolve_site_target()` helper became dead code and was removed.

Local build guardrail:

```bash
cargo check --manifest-path native-sim/x86/native_lab/native_link/Cargo.toml
```

Status:

```text
ok, after removing the unused resolver
```

Next step: rerun focused `map_hash_lookup`, then full stage2 native-kernel.

## 2026-05-26 Update: Focused Hash Stage2 Passes

Focused rerun after the lookup/update oracle-target fix:

```bash
SUITE=micro/config/micro_stage2.yaml RUNTIMES="native_kernel kernel" \
  BENCH=map_hash_lookup SAMPLES=1 WARMUPS=0 INNER_REPEAT=10 make micro
```

Artifact:

```text
micro/results/x86_kvm_micro_20260526_023926_163406
```

Result:

```text
status: completed
native_kernel result: 1234605616436508552, retval: 2
kernel        result: 1234605616436508552, retval: 2
```

This confirms the focused hash lookup case no longer fails in native-link and
the native result matches the kernel JIT result. The relevant hard failure was
not the hash lookup lowering alone; map update call-site target resolution also
had to prefer the companion JIT oracle because the kernel JIT may patch generic
map helpers to map-specific implementation functions.

Next step: run the full stage2 `native_kernel kernel` suite to expose the next
map/helper lowering issue, if any.

## 2026-05-26 Update: Full Stage2 Native-Kernel Passes

Full stage2 rerun:

```bash
SUITE=micro/config/micro_stage2.yaml RUNTIMES="native_kernel kernel" \
  SAMPLES=1 WARMUPS=0 INNER_REPEAT=10 make micro
```

Artifact:

```text
micro/results/x86_kvm_micro_20260526_024346_831564
```

Result:

```text
status: completed
benchmarks: 13/13
native/kernel result mismatches: 0
```

Covered classes include simple helpers, helper chains, array lookup, packet
indexing, hash lookup, string-key hash lookup, percpu array, LRU hash counter,
percpu hash counter, combined helper/map, map-in-map policy, packet classifier,
and mixed stats helpers. This validates the current map lookup/update/delete
target-resolution fixes across the stage2 native-kernel surface.

One performance note remains from this smoke: `stats_mixed_helpers` reported
`native_kernel exec_ns=319` vs `kernel exec_ns=271` in this single-sample run,
while all other stage2 cases were equal or faster for native. That is not a
correctness blocker, but it should stay visible as a follow-up micro perf point
if the mixed helper path becomes important.

Next verification: rerun the Tetragon corpus smoke after the native-link fixes,
then rerun the default micro smoke to guard the non-stage2 suite.

## 2026-05-26 Update: Tetragon Smoke Still Fixed After Native-Link Changes

Rerun:

```bash
BPFREJIT_CORPUS_APPS=tetragon/observer SAMPLES=1 WORKLOAD_DURATION=5 \
  SKIP_REJIT=norejit BPFREJIT_SHIM_NATIVE_LOADER=post \
  BPFREJIT_SHIM_NATIVE_JIT_DUMP_LIMIT=32768 TIMEOUT=1200 make corpus
```

Artifact:

```text
corpus/results/x86_kvm_corpus_20260526_024856_120489
```

App status:

```text
tetragon/observer: ok
```

Raw workload counters from stress-ng:

```text
baseline eventfd:  79198.93 ops/s
baseline udp:     206506.18 ops/s
baseline sockfd:  159536.27 ops/s
baseline sockpair: 71876.34 ops/s

post eventfd:     155695.52 ops/s
post udp:         391216.64 ops/s
post sockfd:      263337.59 ops/s
post sockpair:    129673.31 ops/s
```

Hot BPF counters:

```text
baseline generic_tracepo: bytes_jited=14938, runs=17669904,
  run_time_ns=8111077127, avg ~= 459 ns/run
post native_lab_stub tracepoint: bytes_jited=12995, runs=9663393,
  run_time_ns=5085429176, avg ~= 526 ns/run

baseline hot kprobe: bytes_jited=1875, runs=3052768,
  run_time_ns=1644284529, avg ~= 539 ns/run
post hot native kprobe: bytes_jited=1566, runs=6060137,
  run_time_ns=320469402, avg ~= 53 ns/run
```

This reconfirms that the original Tetragon 5 us/run regression is fixed after
the later native-link map-helper target changes. The post-native tracepoint is
back in the same sub-microsecond range as the original JIT instead of the old
multi-microsecond path, and hot kprobe stubs stay in the tens-of-nanoseconds
range in this smoke.

Next verification: default micro smoke after all changes.

## 2026-05-26 Update: Default Micro Smoke Passes After All Changes

Rerun:

```bash
SAMPLES=1 WARMUPS=0 INNER_REPEAT=10 make micro
```

Artifact:

```text
micro/results/x86_kvm_micro_20260526_025556_589778
```

Result:

```text
status: completed
suite: micro_staged_codegen
benchmarks: 29/29
result/retval mismatches across runtimes: 0
```

This guards the default non-stage2 micro suite after the Tetragon compatibility
fixes and native-link map-helper target fixes. The run is a smoke only
(`SAMPLES=1`, `INNER_REPEAT=10`), so individual ns values should not be treated
as paper-grade performance numbers, but it confirms no functional regression in
the default micro surface.

## 2026-05-26 Update: Retained-Map Stub Register Fix

Follow-up from the bcc/set dump analysis: native-loader retained-map-reference
bookkeeping used a runtime-true `r9 = 1; if r9 == 1 jump over map refs`
sequence before the dummy `LD_IMM64 BPF_PSEUDO_MAP_FD` records. On x86, BPF
`r9` maps to host `%r15`, so even tiny native stubs could pick up `push r15` /
`pop r15` frame overhead just to keep relocated maps alive.

The safe local fix is to keep the same conditional shape, but use BPF `r1`
instead. `r1` is caller-saved on the x86 BPF JIT path and the dummy branch is
emitted after the native kfunc chunks, just before `exit`, so it does not
clobber the return value in `r0`. This preserves the verifier-visible map-fd
records while removing the artificial `%r15` callee-saved pressure.

Changed `append_dummy_map_refs()` in
`native-sim/libnativeloader/src/native_loader.cpp` from `BPF_REG_9` to
`BPF_REG_1`. Next validation is a native-loader smoke that exercises retained
map refs and a default micro rerun.

## 2026-05-26 Update: Retained-Map Register Fix Validation

Focused stage2 micro:

```bash
SUITE=micro/config/micro_stage2.yaml RUNTIMES="native_kernel kernel" \
  BENCH=map_hash_lookup SAMPLES=1 WARMUPS=0 INNER_REPEAT=10 make micro
```

Artifact:

```text
micro/results/x86_kvm_micro_20260526_030443_629282
```

Result: completed successfully; `native_kernel` and `kernel` both returned
`1234605616436508552`.

Focused bcc/set native-loader smoke:

```bash
BPFREJIT_CORPUS_APPS=bcc/set BPFREJIT_SHIM_NATIVE_LOADER=post \
  BPFREJIT_CORPUS_BPF_STATS=0 SKIP_REJIT=norejit \
  BPFREJIT_SHIM_NATIVE_JIT_DUMP_LIMIT=32768 \
  SAMPLES=1 WARMUPS=0 WORKLOAD_DURATION=5 KEEP_WORKDIRS=1 \
  TIMEOUT=2400 make corpus
```

Artifact:

```text
corpus/results/x86_kvm_corpus_20260526_030917_287805
```

Result: app status `ok`; shim log has zero `native-loader failed`, zero stale
reloc-bounds failures, zero `ff d0`, and zero legacy helper-slot padding hits.
The dump confirms 25 original/native JIT pairs were captured. The tiny
retained-map cases that previously grew from the dummy `r9` branch are now no
longer forced to pay `%r15` save/restore:

```text
fentry_vfs_read:  original 36B -> native 35B
fentry_vfs_writ:  original 36B -> native 36B
fentry_vfs_fsyn:  original 36B -> native 36B
fentry_vfs_open:  original 36B -> native 36B
fentry_vfs_crea:  original 36B -> native 36B
```

Raw workload smoke counters with stats disabled:

```text
baseline syscall 101.80, cap 409458.45, set 31175.64, sockfd 261453.00
post     syscall 91.30,  cap 414402.13, set 32190.44, sockfd 264212.37
```

The syscall stressor in this short smoke is noisy and ran longer in the post
phase; the cap/set/sockfd raw counters show no obvious regression. The main
validated point is that retained-map bookkeeping no longer creates artificial
host `%r15` pressure in the smallest native stubs.

## 2026-05-26 Update: Default Micro Smoke After Retained-Map Register Fix

Final default micro rerun after the retained-map dummy branch changed from BPF
`r9` to BPF `r1`:

```bash
SAMPLES=1 WARMUPS=0 INNER_REPEAT=10 make micro
```

Artifact:

```text
micro/results/x86_kvm_micro_20260526_031613_695005
```

Result:

```text
status: completed
suite: micro_staged_codegen
benchmarks: 29/29
result/retval mismatches across runtimes: 0
```

This keeps the default micro guard green after the last native-loader cleanup.
It is still a smoke (`SAMPLES=1`, `INNER_REPEAT=10`), so the important signal is
functional parity across runtimes, not paper-grade timing.
