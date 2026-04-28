# Low Apply Debug - 2026-04-28

Source artifact:
`corpus/results/x86_kvm_corpus_20260428_070851_973550/details/result.json`

## Summary

The main bug is an observability/statistics bug, not a ReJIT filtering bug.
The daemon was returning `summary.applied=true` even when the pass pipeline made
no final change and skipped the final `BPF_PROG_REJIT` syscall. The runner then
counted those clean no-op programs as `program_counts.applied`.

This explains the confusing case:

- `tetragon/observer`: `program_counts.applied=287/287`, but app
  `rejit_result.changed=false` and all 287 common programs have
  `bytes_jited_delta=0` and `bytes_xlated_delta=0`.
- The same applies to `cilium/agent`, `calico/felix`,
  `otelcol-ebpf-profiler/profiling`, `katran`, and all bpftrace cases.

After the fix, no-change programs report `summary.applied=false`, so app
`program_counts.applied` means "a final optimized program was actually
submitted to REJIT", not "the optimize request completed successfully".

## Enabled Passes

`daemon/src/passes/mod.rs` registers 12 passes in canonical order:

1. `map_inline`
2. `const_prop`
3. `dce`
4. `skb_load_bytes_spec`
5. `bounds_check_merge`
6. `wide_mem`
7. `bulk_memory`
8. `rotate`
9. `cond_select`
10. `extract`
11. `endian_fusion`
12. `branch_flip`

Corpus does not use the daemon default list. `runner/libs/rejit.py` sends an
explicit `enabled_passes` list from `corpus/config/benchmark_config.yaml`.
The 2026-04-28 run enabled these 11 passes:

`wide_mem`, `rotate`, `cond_select`, `extract`, `endian_fusion`, `map_inline`,
`const_prop`, `dce`, `bounds_check_merge`, `skb_load_bytes_spec`,
`bulk_memory`.

`branch_flip` was not attempted in this corpus run. That is an intentional
policy/config choice: it is profile-sensitive and not part of the default corpus
pass list. I did not find per-app or per-prog_type pass exclusions.

## Result Reclassification

Current artifact, using the existing compact result:

| app | requested | old daemon applied | daemon changed | common programs | bytes-jited changed | bytes-xlated changed |
|---|---:|---:|---:|---:|---:|---:|
| `bcc/capable` | 1 | 1 | true | 1 | 1 | 0 |
| `bcc/execsnoop` | 2 | 2 | false | 2 | 0 | 0 |
| `bcc/bindsnoop` | 3 | 3 | true | 3 | 2 | 0 |
| `bcc/biosnoop` | 3 | 3 | true | 3 | 1 | 1 |
| `bcc/vfsstat` | 5 | 5 | false | 5 | 0 | 0 |
| `bcc/opensnoop` | 3 | 3 | false | 3 | 0 | 0 |
| `bcc/syscount` | 2 | 2 | false | 2 | 0 | 0 |
| `bcc/tcpconnect` | 3 | 3 | false | 3 | 0 | 0 |
| `bcc/tcplife` | 1 | 1 | false | 1 | 0 | 0 |
| `bcc/runqlat` | 3 | 3 | true | 3 | 1 | 1 |
| `calico/felix` | 6 | 6 | false | 6 | 0 | 0 |
| `otelcol-ebpf-profiler/profiling` | 13 | 13 | false | 13 | 0 | 0 |
| `cilium/agent` | 16 | 16 | false | 16 | 0 | 0 |
| `tetragon/observer` | 287 | 287 | false | 287 | 0 | 0 |
| `katran` | 3 | 3 | false | 3 | 0 | 0 |
| `tracee/monitor` | 158 | 157 | true | 158 | 121 | 111 |
| `bpftrace/*` | 10 | 10 | false | 10 | 0 | 0 |

The "21/22 apps but only 5 have applied programs" observation matches
`rejit_result.changed=true` at app level: `bcc/capable`, `bcc/bindsnoop`,
`bcc/biosnoop`, `bcc/runqlat`, and `tracee/monitor`. The old
`program_counts.applied` field was inflated by clean no-op daemon responses.

## Why Tetragon Said Applied But JIT Size Did Not Change

Before the fix, `daemon/src/commands.rs` did this:

- pipeline ended with `program_changed=false`;
- daemon skipped final REJIT and recorded warning
  `"final optimized program was unchanged; skipping final REJIT"`;
- but it still built the result with `applied=true`.

So for Tetragon the daemon did not apply same-size optimizations. It applied no
final bytecode changes. The artifact confirms this because both BPF bytecode
size and native JIT size stayed identical for all 287 common programs, and
app-level `changed=false`.

This is case (a), "no kept pass matched", or possibly "a pass was attempted and
rolled back", but not case (b), "same-size optimized native code". The compact
artifact does not retain enough per-pass data to distinguish no-match from
rolled-back for each successful no-op program.

## Why The Other Zero-Byte Apps Have 0 Applied Programs

The same app-level signal applies to:

- `cilium/agent`: 16 programs, `changed=false`, 0 bytecode/JIT size deltas.
- `calico/felix`: 6 programs, `changed=false`, 0 bytecode/JIT size deltas.
- `otelcol-ebpf-profiler/profiling`: 13 programs, `changed=false`, 0 deltas.
- `katran`: 3 programs, `changed=false`, 0 deltas.
- `bpftrace/*`: 10 programs, `changed=false`, 0 deltas.
- most BCC tools: `changed=false`, 0 deltas except `capable`, `bindsnoop`,
  `biosnoop`, and `runqlat`.

The likely pass-level reasons from the current matcher code are:

- Networking apps (`cilium`, `calico`, `katran`) are mostly `sched_cls`/`xdp`.
  `wide_mem` intentionally skips likely packet-pointer byte ladders in packet
  program types; `skb_load_bytes_spec` only handles `skb_load_bytes` with
  constant offset/len <= 8 in TC programs; `bounds_check_merge` requires a
  specific mergeable direct-packet guard ladder; map inlining does not support
  prog arrays, perf/ringbuf maps, per-CPU hash maps, dynamic keys, or lookup
  results that escape fixed scalar loads.
- `otelcol-ebpf-profiler` is mostly `perf_event` stack/unwind code. The enabled
  passes are currently narrow peepholes and map-specialization passes; this
  artifact shows none survived to a final rewrite.
- `bpftrace` and most `bcc` cases are small tracing programs. They generally use
  dynamic map keys and helper-heavy event paths, not the exact byte-ladder,
  rotate, extract, endian, bulk-memory, packet-guard, or map-inline patterns
  currently implemented. The few BCC changes are tiny native-size changes in
  `capable`, `bindsnoop`, `biosnoop`, and `runqlat`.
- `tetragon` loads many tracing/kprobe programs, but this run has zero final
  rewrites. The old "all applied" count was entirely the no-op accounting bug.

Because the compact artifact drops successful per-program pass details, the
above is the code-based diagnosis plus final-size evidence. To prove the exact
skip reason for each program, the next diagnostic run must preserve
`debug_result.passes[]` or a compact per-pass skip summary for successful
no-op programs.

## Logging And Diagnostics

There is no general `RUST_LOG`/log-level path in the daemon. Current diagnostic
channels are:

- `passes[]` in the daemon socket response. Each pass has `changed`,
  `sites_applied`, `sites_skipped`, `skip_reasons`, `skipped_sites`, and
  `diagnostics`.
- `attempts[].debug` exists in memory, but `daemon/src/commands.rs` deliberately
  omits the large debug payload from socket JSON.
- `runner/libs/rejit.py` stores the full daemon response in `debug_result`
  before artifact compaction.
- `compact_rejit_results_for_artifact()` currently drops successful
  per-program `debug_result`, which is why this artifact cannot answer every
  per-program skip reason after the fact.
- `BPFREJIT_MAP_INLINE_DEBUG=1` enables extra stderr logging for map_inline
  only. Other passes rely on structured `passes[]` details rather than stderr.

## Fix

Changed:

- `daemon/src/commands.rs`: no-final-change path now returns
  `summary.applied=false` while keeping `changed=false` and status `ok`.
- `runner/libs/rejit.py`: compact artifact logic now records only real
  per-program errors in `error_programs`; clean not-applied programs are not
  mislabeled as errors after the daemon fix.

Expected effect:

- No ReJIT program is filtered or skipped by the framework.
- Programs that fail ReJIT still surface as errors.
- Programs with no kept rewrite are counted as `not_applied`.
- Programs with a kept rewrite and final REJIT success are counted as
  `applied`, even if a future same-size optimization leaves
  `bytes_jited_delta=0`.

## Next Debugging Step

After this fix, `make vm-corpus SAMPLES=1` should produce app
`program_counts.applied` values that line up with `rejit_result.changed` and
actual bytecode/JIT changes. If coverage remains low, run a diagnostic variant
that preserves per-program `passes[]` summaries for clean no-op programs, then
aggregate `skip_reasons` by app and pass.
