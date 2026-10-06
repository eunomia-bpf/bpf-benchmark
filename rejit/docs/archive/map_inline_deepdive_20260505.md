# map_inline deep-dive: coverage, speedup, and errors - 2026-05-05

Run under investigation:

- Artifact: `corpus/results/x86_kvm_corpus_20260505_173741_854355/`
- Metadata: `samples=1`, `workload_seconds=3.0`, enabled passes `["noop","map_inline"]`
  from `corpus/results/x86_kvm_corpus_20260505_173741_854355/metadata.json`.
- Analysis command run for this report:
  `python3 analysis/corpus_analyze.py corpus/results/x86_kvm_corpus_20260505_173741_854355 --per-app --per-pass --verbose`
- Analyzer output: 127 retained programs at `min(baseline_runs, post_rejit_runs) >= 100`,
  Method B `0.9930`, `64/63/0` W/L/T, ratio CV `12.3%`.
  These are post-hoc analysis metrics, not framework payload fields.

Design constraints read before analysis:

- `docs/kernel-jit-optimization-plan.md` says `BPF_PROG_REJIT` accepts complete bytecode and
  re-verifies/re-JITs in kernel (`docs/kernel-jit-optimization-plan.md:120-132`).
- The plan requires each pass to go through `BPF_PROG_REJIT`; daemon does not do dry-run
  fallback (`docs/kernel-jit-optimization-plan.md:184-190`).
- Dynamic map inlining's intended model is snapshot once, inline, ReJIT, measure, with map
  values as bpfopt side input (`docs/kernel-jit-optimization-plan.md:230`).
- v3 says `bpfopt` is a pure bytecode CLI and daemon owns kernel-facing state and ReJIT
  (`docs/kernel-jit-optimization-plan.md:398-406`).
- `CLAUDE.md` forbids ReJIT filtering (`CLAUDE.md:5-10`), forbids in-framework aggregation
  (`CLAUDE.md:15-28`), and requires fail-fast/no fallback (`CLAUDE.md:70-74`).
- `map_inline` requires verifier states and map values in current pass metadata, but not
  `target.json`: `META_MAP_INLINE` sets `NEEDS_VERIFIER_STATES | PRODUCES_VERIFIER_STATES |
  NEEDS_MAP_VALUES`, with no `NEEDS_TARGET` bit (`bpfopt/crates/bpfopt/src/passes/mod.rs:108-120`).
- Daemon prepares `target.json` only for passes whose metadata needs target, and prepares
  `map-values.json` only when a pass needs map values (`daemon/src/commands.rs:457-496`).
- Daemon invokes `bpfopt --pass <pass> --report <file>` and appends `--verifier-states`,
  `--map-values`, and `--map-ids` for map_inline (`daemon/src/commands.rs:797-827`).
- A pass that produces verifier states is ReJITed with `log_level=2`; failed ReJIT becomes
  pass status `failed_rejit` with the bpfopt report retained in the pass detail
  (`daemon/src/commands.rs:611-633`).

Data conventions:

- `bpfopt_summary.sites_matched` is not a raw scanner count. The current report builder sets
  it to `sites_applied + sites_skipped.len()` (`bpfopt/crates/bpfopt/src/main.rs:1109-1123`).
- In this artifact, every successful apply has diagnostic text
  `constantized pseudo-map-value load`; no pass report contains the helper path diagnostic
  `inlined successfully`.
- Therefore this run has 1,604 direct pseudo-map-value applies and zero successful helper
  `bpf_map_lookup_elem()` removals/replacements.
- Data paths below use per-app files under
  `corpus/results/x86_kvm_corpus_20260505_173741_854355/details/apps/`.

## 1. Coverage gap - why only 3/18 apps apply at all?

### 1.1 Short answer

Only 3 apps apply because the only working apply path in this run is direct global-data
constantization from `BPF_PSEUDO_MAP_VALUE` / `BPF_PSEUDO_MAP_IDX_VALUE`, not helper lookup
inlining.

The pass has two paths:

- Helper lookup path: scan `bpf_map_lookup_elem()` calls via `find_map_lookup_sites()`
  (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:123-137`), resolve map info, recover a
  constant key from verifier states, classify `r0` uses, and build a lookup-site rewrite
  (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:691-904`).
- Direct pseudo-map-value path: scan `LDX` memory loads whose source resolves to a
  pseudo-map-value pointer, read key `0`, and replace the load with a constant
  (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:1234-1336`).

All 1,604 applies in the run are from the direct path:

- `cilium/agent`: 279 direct pseudo-map-value constantizations.
- `otelcol-ebpf-profiler/profiling`: 1,192 direct pseudo-map-value constantizations.
- `tracee/monitor`: 133 direct pseudo-map-value constantizations.
- `lookup inlined successfully`: 0 diagnostics across all apps.

The helper lookup path matched/skipped 6,277 sites but applied 0:

- `lookup key is not available from verifier-guided state`: 4,588 sites.
- `map type 13 not inlineable` (`HASH_OF_MAPS`): 1,143 sites.
- `map type 10 not inlineable` (`LRU_PERCPU_HASH`): 344 sites.
- `map type 12 not inlineable` (`ARRAY_OF_MAPS`): 107 sites.
- `map type 5 not inlineable` (`PERCPU_HASH`): 57 sites.
- `map type 11 not inlineable` (`LPM_TRIE`): 38 sites.

Map type ids come from the kernel UAPI enum:

- 5 = `BPF_MAP_TYPE_PERCPU_HASH`
- 10 = `BPF_MAP_TYPE_LRU_PERCPU_HASH`
- 11 = `BPF_MAP_TYPE_LPM_TRIE`
- 12 = `BPF_MAP_TYPE_ARRAY_OF_MAPS`
- 13 = `BPF_MAP_TYPE_HASH_OF_MAPS`
- Citation: `vendor/linux-framework/include/uapi/linux/bpf.h:1000-1014`.

### 1.2 Current type policy explains part, but not most, of the gap

Current `MapInfo` support:

- Direct value access is allowed only for `HASH`, `ARRAY`, `PERCPU_ARRAY`, and `LRU_HASH`
  (`bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:47-55`).
- Lookup/null-check elimination is unconditional only for `ARRAY` and `PERCPU_ARRAY`
  (`bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:62-68`).
- `HASH` and `LRU_HASH` require an entry-presence/null-check proof
  (`bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:70-73`).
- `PERCPU_HASH` and `LRU_PERCPU_HASH` are deliberately excluded because userspace lookup
  returns a concatenated per-CPU blob while the running program observes the current CPU slot
  (`bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:42-46`).
- `PERCPU_ARRAY` is allowed only if all per-CPU slots are byte-identical
  (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:1409-1447`).
- Tests lock in the exclusion for per-CPU hash families
  (`bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:1638-1672`).

Type policy blocks important apps:

- Tetragon has 344 `LRU_PERCPU_HASH`, 105 `ARRAY_OF_MAPS`, 35 `HASH_OF_MAPS`, and
  2 `PERCPU_HASH` unsupported sites.
- Tracee has 1,102 `HASH_OF_MAPS` unsupported sites.
- Katran has 2 `ARRAY_OF_MAPS` and 2 `HASH_OF_MAPS` unsupported sites.
- Cilium has 53 `PERCPU_HASH` and 8 `LPM_TRIE` unsupported sites.
- Otelcol has 30 `LPM_TRIE` and 4 `HASH_OF_MAPS` unsupported sites.

However, unsupported map types are not the dominant zero-apply reason. The dominant reason is
verifier-guided key extraction:

- 4,588 skipped sites say `lookup key is not available from verifier-guided state`.
- That reason appears even for supported map types because diagnostics only print map type for
  unsupported maps (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:746-762`).
- For supported map types that fail key extraction, the pass records only the key-state reason
  and optional detail text (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:765-787`).

### 1.3 Verifier-state key extraction is very narrow

The helper path uses only verifier-guided extraction in production:

- `map_inline` calls `extract_site_constant_key(..., use_verifier_guided_keys)` for every
  helper lookup site (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:765-787`).
- If verifier-guided extraction is enabled, it delegates to
  `try_extract_constant_key_verifier_guided()` (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:1036-1073`).
- If the pass has already rewritten once and no fresh verifier states exist for the rewritten
  bytecode, it refuses fallback extraction with
  `verifier-guided key extraction is unavailable after a prior map_inline rewrite`
  (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:1074-1080`).
- The verifier-guided extractor rejects empty verifier states, key size zero, and keys larger
  than 8 bytes (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:220-237`).
- It then requires at least one verifier state whose `pc == call_pc`; otherwise it returns
  `verifier log has no state snapshot at call pc N`
  (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:242-251`).
- Tests explicitly assert no non-verifier fallback after a map_inline fixpoint rewrite
  (`bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:1372-1420`).

This exactly matches common artifact diagnostics:

- BCC/vfsstat:
  `site at PC=6: verifier-guided key extraction failed: verifier log has no state snapshot at call pc 6`
  from `details/apps/bcc__vfsstat.json`.
- Katran:
  `verifier-guided constant-key extraction currently supports up to 8-byte keys (got 20)`
  from `details/apps/katran.json`.
- Tetragon:
  repeated `verifier log has no state snapshot at call pc N`, plus key sizes 16 and 256 in
  some diagnostics, from `details/apps/tetragon__observer.json`.

### 1.4 Per-app pass outcomes

The table below is from per-app `rejit_result.per_program[*].passes[*].bpfopt_summary`.
`matched` means bpfopt report `sites_matched`, which is `applied + skipped`.
`direct_apply` counts diagnostics containing `constantized pseudo-map-value load`.
`helper_success` counts diagnostics containing `inlined successfully`.

| app | progs in ReJIT result | matched | applied | direct_apply | helper_success | skipped | primary skip reasons |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | --- |
| bcc/biosnoop | 3 | 2 | 0 | 0 | 0 | 2 | key-state 2 |
| bcc/capable | 1 | 0 | 0 | 0 | 0 | 0 | no matched sites |
| bcc/opensnoop | 3 | 0 | 0 | 0 | 0 | 0 | no matched sites |
| bcc/runqlat | 3 | 2 | 0 | 0 | 0 | 2 | key-state 2 |
| bcc/syscount | 2 | 3 | 0 | 0 | 0 | 3 | key-state 3 |
| bcc/tcpconnect | 3 | 2 | 0 | 0 | 0 | 2 | key-state 2 |
| bcc/tcplife | 1 | 2 | 0 | 0 | 0 | 2 | key-state 2 |
| bcc/vfsstat | 5 | 5 | 0 | 0 | 0 | 5 | key-state 5 |
| bpftrace/biosnoop | 2 | 6 | 0 | 0 | 0 | 6 | key-state 6 |
| bpftrace/capable | 1 | 3 | 0 | 0 | 0 | 3 | key-state 3 |
| bpftrace/runqlat | 3 | 2 | 0 | 0 | 0 | 2 | key-state 1; PERCPU_HASH 1 |
| bpftrace/tcplife | 1 | 7 | 0 | 0 | 0 | 7 | key-state 7 |
| bpftrace/vfsstat | 2 | 4 | 0 | 0 | 0 | 4 | key-state 3; PERCPU_HASH 1 |
| cilium/agent | 25 | 342 | 279 | 279 | 0 | 63 | PERCPU_HASH 53; LPM_TRIE 8; key-state 2 |
| katran | 3 | 68 | 0 | 0 | 0 | 68 | key-state 64; ARRAY_OF_MAPS 2; HASH_OF_MAPS 2 |
| otelcol-ebpf-profiler/profiling | 13 | 1,593 | 1,192 | 1,192 | 0 | 401 | key-state 367; LPM_TRIE 30; HASH_OF_MAPS 4 |
| tetragon/observer | 287 | 3,318 | 0 | 0 | 0 | 3,318 | key-state 2,832; LRU_PERCPU_HASH 344; ARRAY_OF_MAPS 105; HASH_OF_MAPS 35; PERCPU_HASH 2 |
| tracee/monitor | 158 | 2,522 | 133 | 133 | 0 | 2,389 | key-state 1,287; HASH_OF_MAPS 1,102 |

### 1.5 Zero-apply apps by category

No matched sites:

- `bcc/capable`: no `map_inline` matched/applied/skipped sites in the result.
- `bcc/opensnoop`: no `map_inline` matched/applied/skipped sites in the result.

Only key-state failures, no unsupported type diagnostics:

- `bcc/biosnoop`: 2 key-state skips.
- `bcc/runqlat`: 2 key-state skips.
- `bcc/syscount`: 3 key-state skips.
- `bcc/tcpconnect`: 2 key-state skips.
- `bcc/tcplife`: 2 key-state skips.
- `bcc/vfsstat`: 5 key-state skips.
- `bpftrace/biosnoop`: 6 key-state skips.
- `bpftrace/capable`: 3 key-state skips.
- `bpftrace/tcplife`: 7 key-state skips.

Mixed key-state and unsupported per-CPU hash:

- `bpftrace/runqlat`: 1 key-state skip, 1 `PERCPU_HASH` skip.
- `bpftrace/vfsstat`: 3 key-state skips, 1 `PERCPU_HASH` skip.

Mixed key-state and map-in-map:

- `katran`: 64 key-state skips, 2 `ARRAY_OF_MAPS`, 2 `HASH_OF_MAPS`.

Tetragon-specific:

- `tetragon/observer`: 3,318 matched/skipped sites and 0 applies.
- The non-error pass reports are mostly key-state and unsupported map families.
- In addition, 44 programs fail `noop` ReJIT and then 44 `map_inline` passes are
  `skipped_missing_states`, producing the 88 pass errors discussed in section 4.

### 1.6 Data caveat: map type dump is a lower bound

The result JSON does not store a full map inventory per program. It stores:

- BPF counter metadata under `baseline.bpf` / `post_rejit.bpf`.
- Per-program pass details under `rejit_result.per_program`.
- `bpfopt_summary.skip_reasons` and diagnostics.

The pass emits `map_type=N` diagnostics only on unsupported map types
(`bpfopt/crates/bpfopt/src/passes/map_inline.rs:746-762`). Supported-map key extraction
failures do not retain map type in the report. Therefore the unsupported map-type table is a
precise count of printed unsupported-type skips, not a full census of all maps used by the
zero-apply apps.

### 1.7 No surviving forbidden summary fields in this artifact

I recursively checked `details/result.json` and `details/apps/*.json` for forbidden result keys:

- `avg_ns_per_run`
- `ratio`
- `per_program_geomean`
- `program_count`
- `wins`
- `losses`
- `summary`
- `optimization_summary`
- `comparison_summary`

None were present in this run's result/app JSON files. `analysis/corpus_analyze.py` computes
ratios/geomeans/wins as post-hoc analysis, which is allowed by `CLAUDE.md:15-31`.

## 2. otelcol 1192 apply / 0 speedup mystery

### 2.1 The "one hot program absorbed 1192 sites" hypothesis is false

Data file:

- `corpus/results/x86_kvm_corpus_20260505_173741_854355/details/apps/otelcol-ebpf-profiler__profiling.json`

The 1,192 applies are distributed across 13 programs, not concentrated in one hot program.
Only one retained/hot program, `native_tracer_entry`, executed meaningfully in this workload.

| prog id | name | applied | matched | skipped | insn_delta | base bytes_xlated | post bytes_xlated | delta xlated | base bytes_jited | post bytes_jited | delta jited | baseline runs | post runs |
| ---: | --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| 43 | perf_unwind_stop | 40 | 60 | 20 | 0 | 6,232 | 6,232 | 0 | 3,721 | 3,698 | -23 | 0 | 0 |
| 44 | perf_unwind_native | 106 | 148 | 42 | 0 | 37,232 | 37,232 | 0 | 22,575 | 22,489 | -86 | 0 | 0 |
| 45 | perf_unwind_hotspot | 178 | 217 | 39 | 0 | 28,048 | 28,048 | 0 | 18,290 | 18,135 | -155 | 0 | 0 |
| 46 | perf_unwind_perl | 189 | 238 | 49 | 0 | 29,144 | 29,144 | 0 | 17,737 | 17,585 | -152 | 0 | 0 |
| 47 | perf_unwind_php | 153 | 182 | 29 | 0 | 25,032 | 25,032 | 0 | 15,178 | 15,046 | -132 | 0 | 0 |
| 48 | perf_unwind_python | 78 | 119 | 41 | 0 | 33,264 | 33,264 | 0 | 19,909 | 19,870 | -39 | 0 | 0 |
| 49 | perf_unwind_ruby | 81 | 123 | 42 | 0 | 28,000 | 28,000 | 0 | 16,540 | 16,499 | -41 | 0 | 0 |
| 50 | perf_unwind_v8 | 169 | 230 | 61 | 0 | 33,712 | 33,712 | 0 | 20,050 | 19,930 | -120 | 0 | 0 |
| 51 | perf_unwind_dotnet | 141 | 189 | 48 | 0 | 34,248 | 34,248 | 0 | 22,565 | 22,434 | -131 | 0 | 0 |
| 52 | perf_go_labels | 15 | 18 | 3 | 0 | 2,496 | 2,496 | 0 | 1,580 | 1,566 | -14 | 0 | 0 |
| 53 | perf_unwind_beam | 6 | 11 | 5 | 0 | 1,088 | 1,088 | 0 | 696 | 691 | -5 | 0 | 0 |
| 54 | tracepoint__sched_process_free | 6 | 12 | 6 | 0 | 1,320 | 1,320 | 0 | 788 | 783 | -5 | 6 | 6 |
| 55 | native_tracer_entry | 30 | 46 | 16 | 0 | 5,496 | 5,496 | 0 | 3,532 | 3,517 | -15 | 7,952 | 7,943 |

### 2.2 What actually changed

The applied sites are direct pseudo-map-value loads:

- The diagnostics are `site at PC=N: constantized pseudo-map-value load from map_id=40 off=...`.
- `map_inline` replaces an `LDX` scalar load from a pseudo-map-value pointer with a constant
  load (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:1294-1331`).
- Each replacement is usually one BPF instruction before and one BPF instruction after.
- `insn_delta` is 0 for every otelcol program.
- `bytes_xlated` is unchanged for every otelcol program.
- `bytes_jited` shrinks by only 5-155 bytes in cold unwind programs and by 15 bytes in the
  hot `native_tracer_entry` program.

The report requested `bpfopt_summary.delta_jit_size`, but this field is not present in the
artifact or current `PassReport`. The current report fields are pass, sites, skip reasons,
diagnostics, instruction counts, `insn_delta`, and inlined map entries
(`bpfopt/crates/bpfopt/src/main.rs:155-168`, `bpfopt/crates/bpfopt/src/main.rs:1109-1128`).
The closest available raw data is per-phase `bytes_jited` / `bytes_xlated`.

### 2.3 Why this gives essentially zero speedup

The apply count is misleading because most changed code did not run:

- 11 unwind programs with 1,156 combined applies had zero baseline and post run deltas.
- `tracepoint__sched_process_free` had 6 applies and 6 runs.
- The only retained program, `native_tracer_entry`, had only 30 applies, `insn_delta=0`,
  `bytes_xlated` unchanged, and `bytes_jited=-15`.

The measured otelcol retained-program ratio from the analyzer was `0.9977`:

- Baseline: 7,952 runs, 15,482,495 ns, about 1,946.99 ns/run.
- Post-ReJIT: 7,943 runs, 15,430,068 ns, about 1,942.60 ns/run.
- Delta: about -4.39 ns/run.

That delta is compatible with tiny codegen differences and noise. It is not evidence that
1,192 hot helper calls were removed. They were not helper calls, and almost all were cold.

### 2.4 Secondary coverage signal in otelcol

Otelcol still had 401 skipped helper/map sites:

- 367 key-state skips.
- 30 `LPM_TRIE` unsupported skips.
- 4 `HASH_OF_MAPS` unsupported skips.

Those are the real remaining map_inline coverage opportunities in this app. The 1,192 direct
global constantizations are not the same optimization as helper lookup removal.

## 3. tracee 1.6% regression

### 3.1 The code-bloat hypothesis is not supported by this run's per-program data

Data file:

- `corpus/results/x86_kvm_corpus_20260505_173741_854355/details/apps/tracee__monitor.json`

Analyzer output for Tracee:

- `Method B = 1.0160` for 70 retained programs.
- 133 applies, 2 pass errors.

The requested hypothesis was:

- Each inlined site replaces about 3 helper-call instructions with a larger inline body.
- Total size increases significantly.
- I-cache pressure regresses the app with 70 co-resident programs.

The pass data does not fit that:

- All 133 applies are direct pseudo-map-value constantizations, not helper lookup inlines.
- No helper lookup site says `inlined successfully`.
- Only 7 Tracee programs have any applied sites.
- The hottest retained Tracee programs have zero applies.
- `bytes_xlated` / `bytes_jited` generally do not increase on applied programs.

### 3.2 Applied Tracee programs

| prog id | name | applied | matched | skipped | insn_delta | base xlated | post xlated | delta xlated | base jited | post jited | delta jited | baseline runs | post runs |
| ---: | --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| 518 | tracepoint__sched__sched_process_fork | 1 | 50 | 49 | 0 | 32,248 | 31,216 | -1,032 | 19,722 | 19,125 | -597 | 7,752 | 7,486 |
| 519 | lkm_seeker_modtree_loop | 40 | 87 | 47 | +20 | 108,072 | 108,024 | -48 | 59,266 | 59,137 | -129 | 0 | 0 |
| 521 | uprobe_lkm_seeker | 1 | 17 | 16 | 0 | 7,784 | 7,784 | 0 | 4,339 | 4,339 | 0 | 0 | 0 |
| 522 | lkm_seeker_kset_tail | 44 | 97 | 53 | +22 | 111,768 | 111,752 | -16 | 62,309 | 62,193 | -116 | 0 | 0 |
| 524 | lkm_seeker_proc_tail | 44 | 75 | 31 | +22 | 102,120 | 102,296 | +176 | 57,791 | 57,879 | +88 | 0 | 0 |
| 626 | trace_exec_binprm | 1 | 22 | 21 | 0 | 28,960 | 28,960 | 0 | 16,503 | 16,503 | 0 | 2 | 2 |
| 635 | syscall_checker | 2 | 50 | 48 | 0 | 24,112 | 22,080 | -2,032 | 14,930 | 13,768 | -1,162 | 0 | 0 |

Only one applied program has retained-level run counts:

- `tracepoint__sched__sched_process_fork`: 1 apply, 7,486 post runs, code size shrank.

The only applied program with a positive JIT-size delta:

- `lkm_seeker_proc_tail`: +88 JIT bytes, but it had zero runs in both phases.

### 3.3 Hottest Tracee programs had no applies

Top retained Tracee programs by baseline run count:

| prog id | name | baseline runs | ratio | applied | matched | skipped | xlated delta | jited delta |
| ---: | --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| 500 | trace_sys_exit | 35,268,032 | 1.0011 | 0 | 21 | 21 | 0 | 0 |
| 496 | tracepoint__raw_syscalls__sys_exit | 35,268,032 | 0.9853 | 0 | 1 | 1 | 0 | 0 |
| 499 | trace_sys_enter | 35,267,696 | 1.0074 | 0 | 21 | 21 | 0 | 0 |
| 493 | tracepoint__raw_syscalls__sys_enter | 35,267,696 | 1.0102 | 0 | 1 | 1 | 0 | 0 |
| 538 | trace_security_file_ioctl | 3,064,728 | 0.9788 | 0 | 21 | 21 | 0 | 0 |
| 642 | cgroup_bpf_run_filter_skb | 2,717,562 | 1.0762 | 0 | 13 | 13 | 0 | 0 |
| 608 | trace_security_file_permission | 2,668,145 | 1.0384 | 0 | 22 | 22 | 0 | 0 |
| 587 | trace_security_file_mprotect | 2,575,437 | 1.0106 | 0 | 32 | 32 | 0 | 0 |
| 549 | trace_cap_capable | 2,298,417 | 1.0737 | 0 | 20 | 20 | 0 | 0 |
| 641 | trace_security_socket_sendmsg | 2,036,918 | 0.8317 | 0 | 19 | 19 | 0 | 0 |

The app-level Method B regression is therefore not explained by map_inline code bloat in
hot programs. The hot programs were still ReJITed by `noop` and then had map_inline skip all
matched sites. A plausible interpretation is "paired run / ReJIT / layout noise across many
unchanged hot programs", not "map_inline inflated hot bytecode".

This matters for policy:

- A skip-when-not-profitable heuristic based on `delta_jit_size` would not have prevented the
  observed Tracee app-level regression, because the hot regressing programs had no applied
  `map_inline` transformations and no code-size deltas.
- A direct pseudo-map-value profitability policy would reduce low-value applies in cold code,
  but it is not sufficient to explain or fix this Tracee number.

### 3.4 Tracee skipped sites are still a coverage problem

Tracee had 2,522 matched map_inline sites:

- 133 applied direct pseudo-map-value sites.
- 1,287 key-state skips.
- 1,102 `HASH_OF_MAPS` skips.
- 2 `map_inline` `failed_rejit` errors.

The skipped hot programs above show many helper/map sites in hot code, but current map_inline
cannot act on them:

- `trace_sys_enter`: 21 matched, 0 applied, 21 skipped.
- `trace_sys_exit`: 21 matched, 0 applied, 21 skipped.
- `cgroup_skb_egress`: 56 matched, 0 applied, 56 skipped.
- `cgroup_skb_ingress`: 56 matched, 0 applied, 56 skipped.

So Tracee's actionable map_inline issue is coverage, not code bloat from the 133 direct applies.

## 4. tetragon 88 errors blocker

### 4.1 What the 88 errors are

Data file:

- `corpus/results/x86_kvm_corpus_20260505_173741_854355/details/apps/tetragon__observer.json`

Pass-status clusters:

| pass | status | count | root |
| --- | --- | ---: | --- |
| noop | failed_rejit | 44 | kernel rejected `BPF_PROG_REJIT` with errno 28 / ENOSPC |
| map_inline | skipped_missing_states | 44 | previous `noop` failed, so no verifier states were available |

This exactly sums to 88 pass errors.

The `map_inline` errors are secondary. Daemon refuses to run a pass that needs verifier states
when `verifier_states_ready == false`:

- It returns `PassStatus::SkippedMissingStates`.
- It emits the message telling the caller to insert a `noop` before map_inline.
- Citation: `daemon/src/commands.rs:550-559`.

In this run, `noop` was already present but failed ReJIT for those 44 Tetragon programs, so it
could not produce verifier states.

### 4.2 noop failure root

Representative Tetragon `noop` error from program 184:

```text
kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)
verifier log summary:
precise: frame2: regs= stack= before 2041: (0f) r2 += r1
mark_precise: frame2: regs= stack= before 2040: (bf) r2 = r0
...
```

Representative Tetragon `noop` error from program 215:

```text
kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 28: No space left on device (os error 28)
verifier log summary:
+= -1
mark_precise: frame2: regs=r1 stack= before 2009: (15) if r1 == 0x83 goto pc+11
...
```

Observations:

- All 44 first-pass failures are `noop failed_rejit`, not bpfopt failures.
- All carry errno 28 / ENOSPC.
- The verifier logs are dominated by `mark_precise` output on large Tetragon programs.
- Because `noop` is a verifier-state bootstrap pass, this blocks map_inline from even getting
  a bpfopt report on those 44 programs.

### 4.3 Cross-reference with map_inline.rs error paths

The Tetragon 88 pass errors are not caused by the map_inline pass rejecting map type/opcode/BTF
internally.

What map_inline does for unsupported maps:

- It records a skip reason `map type N not inlineable`.
- It appends an unsupported map-type diagnostic.
- It continues to the next site.
- Citation: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:746-762`.

What map_inline does for key extraction failure:

- It records `lookup key is not available from verifier-guided state`.
- It appends the concrete extraction detail.
- It continues to the next site.
- Citation: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:765-787`.

What map_inline does for missing concrete snapshot values:

- It hard-errors if a supported lookup needs a concrete snapshot and the snapshot is missing/null
  in a way that would make the rewrite unsound
  (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:773-779`,
  `bpfopt/crates/bpfopt/src/passes/map_inline.rs:843-868`,
  `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1101-1113`).

What map_inline does for `PERCPU_ARRAY`:

- It collapses only uniform per-CPU values.
- It site-vetoes mixed per-CPU values with a precise reason.
- Citation: `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1409-1447`.

None of those are the 88 Tetragon errors. The 88 errors are a daemon/kernel ReJIT bootstrap
failure:

- `noop` ReJIT fails with ENOSPC.
- Daemon has no verifier states.
- Daemon marks `map_inline` as `skipped_missing_states`.

### 4.4 Tetragon non-error coverage is also blocked

For programs where `noop` succeeded and map_inline ran, the app still had zero applies:

- 3,318 matched/skipped sites.
- 2,832 key-state skips.
- 344 `LRU_PERCPU_HASH` skips.
- 105 `ARRAY_OF_MAPS` skips.
- 35 `HASH_OF_MAPS` skips.
- 2 `PERCPU_HASH` skips.

So Tetragon has two separate blockers:

- Error blocker: 44 programs cannot bootstrap verifier states due `noop` ReJIT ENOSPC.
- Coverage blocker: remaining programs have thousands of key-state and unsupported map-family
  skips.

Fixing the ENOSPC bootstrap alone will turn the 88 pass errors into real map_inline reports,
but it will not automatically produce applies unless the key-state and map-type blockers are
also addressed.

## 5. Code-side improvement directions

### 5.1 Highest-value coverage improvement: verifier-state/key extraction

Problem:

- 4,588 skipped sites across the run are `lookup key is not available from verifier-guided state`.
- This is the largest single blocker.
- It affects nearly every app with helper lookup sites.

Minimal-change directions:

- Improve verifier-state capture/parser so helper call PCs actually have usable state snapshots.
- Keep fail-fast behavior: parser errors should remain errors, not empty-state success.
- Extend key extraction beyond the current 8-byte limit when verifier states prove a constant
  stack byte range.
- Preserve the current no-fallback design unless a replacement is verifier-backed. The tests
  intentionally reject non-verifier fallback after rewrite (`bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:1372-1420`).

Expected coverage gain from this run:

- Up to 4,588 helper lookup sites move from "uninspectable key" to either apply or a more
  precise reason.
- Largest app gains:
  - Tetragon: 2,832 sites.
  - Tracee: 1,287 sites.
  - Otelcol: 367 sites.
  - Katran: 64 sites.
  - bpftrace/BCC small tools: dozens of sites combined.

Risk:

- This may reveal many non-constant keys rather than applying. That is still a useful coverage
  gain because failures become precise instead of collapsing into `no state snapshot at call pc`.

### 5.2 Fix Tetragon verifier-state bootstrap ENOSPC

Problem:

- 44 Tetragon programs fail `noop` ReJIT with errno 28.
- That directly produces 44 `map_inline skipped_missing_states` errors.
- Total pass errors: 88.

Minimal-change directions:

- Investigate whether `REJIT_VERBOSE_LOG_BUF_SIZE` is too small for Tetragon verifier logs or
  whether the kernel returns ENOSPC for another verifier resource.
- If the log buffer is the issue, increase or chunk the verifier-state capture path in daemon /
  kernel-sys without adding fallback or silencing parse failures.
- Keep synchronous ReJIT semantics; do not add a daemon-side timeout or dry-run path, per v3
  design (`docs/kernel-jit-optimization-plan.md:398-406`, `CLAUDE.md:86-100`).

Expected coverage gain:

- Eliminates the 88 Tetragon pass errors.
- Unblocks map_inline reporting for 44 currently opaque Tetragon programs.
- Rough site estimate: non-error Tetragon programs average about 13.7 matched/skipped sites
  over 243 map_inline reports; 44 additional programs could expose on the order of 600 more
  Tetragon sites. This is an estimate from the same result, not a framework metric.

### 5.3 Unsupported map type expansion

Current supported direct-value map types are only `HASH`, `ARRAY`, `PERCPU_ARRAY`, and
`LRU_HASH` (`bpfopt/crates/bpfopt/src/passes/map_inline/map_info.rs:47-55`).

Potential expansions, ordered by observed blocked sites:

| blocker | blocked sites | apps | direction | caveat |
| --- | ---: | --- | --- | --- |
| `HASH_OF_MAPS` | 1,143 | Tracee 1,102; Tetragon 35; Otelcol 4; Katran 2 | map-in-map / inner-map support | value is an inner map reference, not ordinary scalar value bytes |
| `LRU_PERCPU_HASH` | 344 | Tetragon | per-CPU hash support | userspace gets per-CPU blob; running program observes current CPU slot |
| `ARRAY_OF_MAPS` | 107 | Tetragon 105; Katran 2 | map-in-map / inner-map support | needs inner map id/fd semantics |
| `PERCPU_HASH` | 57 | Cilium 53; bpftrace 2; Tetragon 2 | per-CPU hash support | same current-CPU slot problem |
| `LPM_TRIE` | 38 | Otelcol 30; Cilium 8 | trie lookup support | key encoding and longest-prefix semantics; not an array/hash direct value |

Minimal-change recommendations:

- Do not simply add these types to `supports_direct_value_access()`.
- Add separate implementations per semantic family:
  - map-in-map: resolve snapshot value to an inner map id/fd and define what can be inlined.
  - per-CPU hash: only inline if all per-CPU slots are uniform, analogous to current
    `PERCPU_ARRAY`, or if the pass has a correct current-CPU specialization model.
  - LPM trie: support only exact verifier-proven keys and preserve longest-prefix semantics.
- Keep missing map/inner-map metadata fail-fast. `inner_map_fd` or inner map metadata absence
  should be an error for a candidate that claims support, not a silent skip.

Expected coverage gain:

- Map-in-map support is the largest type expansion: up to 1,250 sites if `HASH_OF_MAPS` and
  `ARRAY_OF_MAPS` can be handled.
- Per-CPU hash support could expose up to 401 sites, mostly Tetragon plus Cilium.
- LPM trie support could expose 38 sites.

### 5.4 Direct pseudo-map-value profitability policy

Problem:

- 1,604 direct pseudo-map-value applies produce little visible speedup.
- Otelcol's 1,192 applies mostly hit cold unwind programs.
- Tracee's 133 applies do not explain the app-level regression.
- Cilium's measured speedup comes from one retained program with only 1,164 min_runs and
  no `bytes_xlated` delta; it is promising but not a strong policy signal by itself.

Minimal-change directions:

- Treat direct pseudo-map-value constantization as an enabling transform, not a standalone
  performance pass, unless it enables follow-on `const_prop`/DCE or removes a branch.
- If running `map_inline` alone, consider a conservative policy gate for direct global loads:
  skip direct constantization when it is a one-insn load to one-insn immediate replacement and
  no follow-on pass can consume the constant.
- Do not add benchmark-framework summary fields to decide this. Use bpfopt-local facts
  (`insn_delta`, replacement class, maybe pass-local branch fold opportunity) or external
  analysis.

Expected effect:

- Reduces misleading apply counts in Otelcol/Tracee.
- Avoids paper claims based on cold direct-global rewrites.
- Does not fix helper lookup coverage by itself.

### 5.5 Tracee-specific regression handling

The requested "skip when code grows" heuristic is not supported by this Tracee run:

- Hot regressing programs had zero applies and zero code-size delta.
- Applied programs were mostly cold and did not show broad code-size growth.

Better next step:

- Use a noop-only control result or compare against a run where map_inline is disabled but noop
  is still present. This is analysis guidance only; no benchmark was run for this report.
- If the regression remains in noop-only, it belongs to ReJIT/layout/verifier/JIT placement
  behavior, not map_inline.
- If the regression appears only with map_inline enabled, inspect pass failures and changed cold
  programs as possible indirect app/runtime effects.

### 5.6 Error reporting improvements

Current reporting is mostly fail-fast and useful, but two gaps slow diagnosis:

- Supported-map key-state failures omit map type/id in non-debug diagnostics. The pass already
  has `info.map_id`, `info.map_type`, `key_size`, `value_size`, and `max_entries` at the site
  (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:737-745`), but only debug logs print them.
  Add these fields to skip diagnostics or structured report entries without adding aggregates.
- The artifact's bpfopt summary lacks JIT-size deltas. bpfopt cannot know final JIT size, but
  daemon/result already records raw per-phase `bytes_jited` / `bytes_xlated` per program.
  Keep using those raw fields; do not add computed ratios or rollups.

Expected benefit:

- Zero-apply app triage can distinguish supported map/key-state gaps from unsupported map
  families without rerunning with debug logs.
- Tetragon and Tracee reports become more actionable without violating the no-summary rule.

### 5.7 Top expected coverage gains

1. Verifier-state/key extraction:
   up to 4,588 currently skipped helper sites; largest gains in Tetragon, Tracee, Otelcol, Katran.

2. Map-in-map support:
   up to 1,250 unsupported sites (`HASH_OF_MAPS` + `ARRAY_OF_MAPS`), mostly Tracee and Tetragon.

3. Tetragon noop ENOSPC bootstrap:
   eliminates 88 pass errors and likely exposes roughly hundreds more Tetragon map_inline sites
   for real skip/apply classification.

Secondary gains:

- Per-CPU hash support: up to 401 unsupported sites, mostly Tetragon and Cilium.
- LPM trie support: 38 unsupported sites, mostly Otelcol and Cilium.
- Direct pseudo-map-value profitability: improves signal quality more than coverage.

### 5.8 Bottom-line findings

- Coverage is narrow because current successful applies are direct global-data load
  constantizations, and only Cilium/Otelcol/Tracee have those in this run.
- Helper lookup inlining has zero successful applications despite thousands of matched/skipped
  sites.
- Otelcol's massive apply count is cold and one-insn-for-one-insn; the hot program only gets
  30 tiny direct rewrites.
- Tracee's app-level regression is not supported by the code-bloat hypothesis in this run.
  The changed programs are mostly cold; the hottest regressions have zero applies.
- Tetragon's 88 errors are a `noop` verifier-state bootstrap failure plus downstream
  `skipped_missing_states`, not a map_inline map-type error.
