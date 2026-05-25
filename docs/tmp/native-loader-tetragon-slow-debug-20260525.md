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
