# map_inline other-app opportunity analysis

Date: 2026-05-14

Scope: read-only analysis of non-Katran `map_inline` opportunities using the
latest complete 7-app `noop,map_inline` run:

```text
corpus/results/x86_kvm_corpus_20260514_030512_558263
SAMPLES=1, WORKLOAD_DURATION=10
```

This note uses raw per-app pass reports only. It does not add framework-side
summary logic.

## Current map_inline State

| app | map_inline attempts | status mix | matched | applied | skipped | apply kind |
| --- | ---: | --- | ---: | ---: | ---: | --- |
| `bcc/set` | 21 | ok 21 | 16 | 0 | 16 | none |
| `bpftrace/set` | 9 | ok 9 | 22 | 0 | 22 | none |
| `cilium/agent` | 53 | ok 51, failed_bpfopt 2 | 1,868 | 1,456 | 412 | pseudo-map-value |
| `otelcol-ebpf-profiler/profiling` | 13 | ok 13 | 1,593 | 1,192 | 401 | pseudo-map-value |
| `tetragon/observer` | 287 | ok 164, failed_bpfopt 123 | 1,475 | 0 | 1,475 | none |
| `tracee/monitor` | 158 | ok 148, failed_bpfopt 8, failed_rejit 2 | 2,624 | 5 | 2,619 | pseudo-map-value |

Important distinction:

- `cilium`, `otel`, and `tracee` current applies are direct
  `BPF_PSEUDO_MAP_VALUE` constantizations.
- They are not helper-call `bpf_map_lookup_elem()` removal in the Katran sense.
- Outside Katran, helper lookup elimination is still essentially unexercised.

## Current Skip Classes

| app | key unavailable | mutable | skipped by size | map-in-map | LPM/type | pass errors |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| `bcc/set` | 6 | 9 | 1 | 0 | 0 | 0 |
| `bpftrace/set` | 10 | 12 | 0 | 0 | 0 | 0 |
| `cilium/agent` | 107 | 267 | 0 | 0 | 38 LPM | 2 |
| `otelcol-ebpf-profiler/profiling` | 34 | 4 | 358 | 4 | 1 LPM | 0 |
| `tetragon/observer` | 490 | 348 | 602 | 35 | 0 | 123 |
| `tracee/monitor` | 634 | 533 | 174 | 1,278 | 0 | 10 |

`failed_bpfopt` is mostly:

```text
failed to read verifier states ... verifier_log_initial.log: No such file or directory
```

That is a coverage blocker, especially for Tetragon, but it is not itself an
inline opportunity.

## App-by-App Opportunity

### Tracee

Tracee is the strongest non-Katran candidate.

Current report:

```text
matched 2624
applied 5
skipped 2619
map-in-map chain is not inlineable: 1278
lookup key unavailable: 634
mutable: 533
skipped by size: 174
```

The large opportunity is the versioned map-of-maps family:

- `events_map_version`
- `process_tree_map_version`
- `binary_filter_version`
- `cgroup_id_filter_version`
- `comm_filter_version`
- `mnt_ns_filter_version`
- `pid_ns_filter_version`
- `uid_filter_version`
- `uts_ns_filter_version`
- `pid_filter_version`
- `data_filter_*_version`

This is not solved by simply adding `HASH_OF_MAPS` as a normal map type. The
outer value is an inner-map reference. A safe transform needs:

1. outer key proof or explicit outer hint;
2. outer entry to live inner map id;
3. inner map metadata and snapshot;
4. inner key proof;
5. inner value-load rewrite;
6. no mutation of the selected inner map by BPF.

Expected value: high coverage potential, but the implementation must be
generic map-in-map chain support with code-size gating. Tracee owns the largest
map-in-map skip count, so this is the best app to justify that work.

Non-opportunities:

- `task_info_map`, `proc_info_map`, `containers_map`, `args_map`, `logs_count`,
  `netflowmap`, and similar state maps are BPF-written and should stay rejected.
- Large static-ish hash tables like syscall/filter maps may only be worth
  small-snapshot runtime-key scalarization if live entry count is tiny.

### Tetragon

Tetragon has high surface area but lower clean ROI than Tracee.

Current report:

```text
matched 1475
applied 0
skipped 1475
failed_bpfopt 123 programs
lookup key unavailable: 490
skipped by size: 602
mutable: 348
map-in-map: 35
```

The first blocker is not a map pattern: many programs never reach a useful
`map_inline` report because verifier-state input is missing after `noop`.

After that, the plausible map_inline work is:

- map-in-map chains for filter maps such as arg/string/policy filter families;
- small read-only HASH scalarization for tiny test-like maps (`m1`, `m2`);
- maybe `tg_mbset_map` only if live snapshot is tiny, but its 256-byte key makes
  code size unattractive.

Most high-count maps are not safe:

- `execve_map`, `tg_errmetrics_map`, `retprobe_map`, `fdinstall_map`,
  `enforcer_*`, rate-limit maps, and tracking maps are BPF-written.
- many array/percpu-array maps are scratch/config pointers where map_inline
  should not pretend the value pointer semantics are a scalar constant.

Expected value: fix verifier-state coverage first, then map-in-map. Do not
expect a Katran-like immediate hot-path win from generic helper inlining.

### Cilium

Cilium already applies heavily, but mostly through pseudo-map-value
constantization:

```text
matched 1868
applied 1456
skipped 412
direct pseudo-map-value diagnostics: 1456
```

Remaining skips:

```text
mutable: 267
lookup key unavailable: 107
LPM_TRIE: 38
failed_bpfopt: 2
```

Most skipped hot maps use packet/runtime keys:

- service maps (`cilium_lb{4,6}_services_v2`);
- backend maps (`cilium_lb{4,6}_backends_v3`);
- endpoint/LXC/node maps;
- policy/source-range LPM tries;
- conntrack/NAT/LRU maps.

Safe remaining candidates are narrower:

- small read-only HASH runtime-key scalarization if live snapshot is tiny:
  `cilium_vtep_map`, `cilium_skip_lb4`, `cilium_skip_lb6`, small CIDR/fix maps;
- LPM support only for constant/small live snapshots, with longest-prefix
  semantics preserved;
- no per-cpu hash shortcut for `cilium_metrics`: it is BPF-written.

Expected value: moderate-low. The current 1,456 applies are already the easy
constant config class. The remaining hot maps are mostly runtime lookup
semantics, not constant inline.

### Otel eBPF Profiler

Otel already has a large direct constantization count:

```text
matched 1593
applied 1192
skipped 401
```

Remaining skips:

```text
skipped by size: 358
lookup key unavailable: 34
map-in-map: 4
mutable: 4
LPM/type: 1
```

Plausible candidates:

- `interpreter_offsets`: small HASH candidate if live entries are small;
- `stack_delta_page_to_info`: possible but declared large and likely not worth
  broad scalarization without live-entry gating;
- `exe_id_to_22_stack_deltas`: map-in-map, small count.

Not good candidates:

- `metrics`: BPF increments returned map values;
- `reported_pids`: BPF update/delete path;
- huge unwind/stack maps unless a sparse overlay or exact hinted key is
  available.

Expected value: low to moderate. The remaining skipped-by-size class needs
either sparse/partial snapshot support or explicit hints; generic snapshot-size
raising is the wrong fix.

### BCC and bpftrace

Current supported benchmark set has tiny map_inline surface:

```text
bcc/set:      matched 16, applied 0
bpftrace/set: matched 22, applied 0
```

Skips are mostly mutable maps and missing key proof. These tools are not worth
targeting before Tracee/Tetragon/Cilium/Otel.

## Cross-App Priority

1. **Tracee map-in-map chain support.**
   This is the largest non-Katran opportunity by count: 1,278 current skips.
   It needs real outer/inner map modeling and code-size gates.

2. **Tetragon verifier-state coverage, then Tetragon map-in-map.**
   The 123 `failed_bpfopt` cases must be made reportable first. After that,
   map-in-map filters are the only broadly plausible helper-inline class.

3. **Small read-only HASH runtime-key scalarization.**
   Useful for Cilium small maps and a few Otel/Tetragon/Tracee maps. This is
   not constant-key inline; it emits a tiny key-comparison chain and replaces
   value loads with constants. It must be gated by live entry count and value
   use shape.

4. **Skipped-by-size sparse/partial snapshots.**
   Useful mostly for Otel and Tetragon. Do not raise the global snapshot size.
   Add sparse/uniform/explicit-key snapshot support instead.

5. **LPM_TRIE support.**
   Current count is small in this run: Cilium 38, Otel 1. It is lower priority
   because longest-prefix semantics make it more than exact-key hash lookup.

## Bottom Line

Outside Katran, the biggest map_inline opportunity is **Tracee map-in-map**,
not `reals`-style array lookup. The second is **Tetragon after verifier-state
coverage is fixed**. Cilium and Otel already get many direct constantizations;
their remaining opportunities are smaller and need runtime-key/snapshot-size
gating rather than simple constant-key helper removal.
