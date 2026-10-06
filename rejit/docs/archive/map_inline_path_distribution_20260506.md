# map_inline path distribution, x86 KVM smoke, 2026-05-06

Data source: six requested app result payloads under `corpus/results/x86_kvm_corpus_20260506_*`:
`otelcol-ebpf-profiler__profiling.json`, `bcc__set.json`, `bpftrace__set.json`,
`tracee__monitor.json`, `katran.json`, and `cilium__agent.json`.

Counting unit: applied counts use `bpfopt_summary.sites_applied`. In current
`map_inline`, pseudo-map-value direct load counts one rewritten load PC; the other
paths count one lookup-site rewrite. Per-round tables are diagnostic site-attempts:
R1 diagnostics are unprefixed, and R2+ diagnostics carry `round N:`. If the same
`prog_id`/PC is attempted in more than one round, it is counted once per round in
the per-round table.

Important caveat: `bpfopt_summary.skip_reasons` is final-round only. The pass
accumulates `sites_applied` across fixed-point rounds, but replaces
`final_skipped` on each round before building `skip_reasons`.

Diagnostic classification used:

| path | diagnostic/source pattern |
|---|---|
| direct constant inline | `site at PC=...: inlined successfully, value=...`; emitted at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1156`, scalar value formatter at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2838` |
| pseudo-map-value direct load | `constantized pseudo-map-value load ...`; emitted at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2012` |
| map-in-map specialization | applied diagnostic value contains `outer_map_id=... inner_map_id=...`; built at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1884` |
| runtime-key chain rewrite | applied diagnostic value contains `runtime-key entries=...`; built at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1486` and `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1491` |

## Per-app applied distribution

| app | total sites_applied | direct_const | pseudo_map_value | map_in_map | runtime_key | other |
|---|---:|---:|---:|---:|---:|---:|
| otel | 1192 | 0 | 1192 | 0 | 0 | 0 |
| bcc | 0 | 0 | 0 | 0 | 0 | 0 |
| bpftrace | 0 | 0 | 0 | 0 | 0 | 0 |
| tracee | 133 | 0 | 133 | 0 | 0 | 0 |
| katran | 0 | 0 | 0 | 0 | 0 | 0 |
| cilium | 1255 | 0 | 1255 | 0 | 0 | 0 |
| total | 2580 | 0 | 2580 | 0 | 0 | 0 |

Overall path share among applied sites:

| path | applied sites | share |
|---|---:|---:|
| direct_const | 0 | 0.00% |
| pseudo_map_value | 2580 | 100.00% |
| map_in_map | 0 | 0.00% |
| runtime_key | 0 | 0.00% |
| other | 0 | 0.00% |

## Per-app per-round distribution

`vetoed subset` is a subset of skipped diagnostics bucketed to explicit
map-in-map/runtime-key veto reasons; it is not an extra category.

| app | R1 applied | R1 skipped | R1 vetoed subset | R2+ applied | R2+ skipped | R2+ vetoed subset | R2+ path catch |
|---|---:|---:|---:|---:|---:|---:|---|
| otel | 1192 | 72 | 4 | 0 | 72 | 4 | none |
| bcc | 0 | 12 | 0 | 0 | 0 | 0 | none |
| bpftrace | 0 | 16 | 0 | 0 | 0 | 0 | none |
| tracee | 133 | 1921 | 1306 | 0 | 200 | 53 | none |
| katran | 0 | 18 | 4 | 0 | 0 | 0 | none |
| cilium | 1255 | 312 | 1 | 0 | 310 | 1 | none |

R2+ did not catch any additional applied site in any of the six apps. R2+ only
re-reported remaining skips after an R1 rewrite changed the bytecode.

## Lookup-key-unavailable skip rate

`final %` uses `bpfopt_summary.skip_reasons` over `bpfopt_summary.sites_matched`
summed per app. `diagnostic %` counts all diagnostic site-attempts, including
R2+ repeated attempts.

| app | final lookup-key skips / summary matched | final % | diagnostic attempts lookup-key skips / attempts | diagnostic % |
|---|---:|---:|---:|---:|
| otel | 38/1264 | 3.01% | 76/1336 | 5.69% |
| bcc | 12/12 | 100.00% | 12/12 | 100.00% |
| bpftrace | 14/16 | 87.50% | 14/16 | 87.50% |
| tracee | 615/2054 | 29.94% | 762/2254 | 33.81% |
| katran | 14/18 | 77.78% | 14/18 | 77.78% |
| cilium | 118/1567 | 7.53% | 236/1877 | 12.57% |
| total | 811/4931 | 16.45% | 1114/5513 | 20.21% |

## Per-app final-round skip reasons top 10

### otel

| rank | final-round skip reason | count | path bucket |
|---:|---|---:|---|
| 1 | `lookup key is not available from verifier-guided state` | 38 | direct_const |
| 2 | `map type 11 not inlineable` | 30 | direct_const |
| 3 | `map-in-map outer key unavailable: verifier-guided key extraction is unavailable after a prior map_inline rewrite` | 4 | map_in_map |

### bcc

| rank | final-round skip reason | count | path bucket |
|---:|---|---:|---|
| 1 | `lookup key is not available from verifier-guided state` | 12 | direct_const |

### bpftrace

| rank | final-round skip reason | count | path bucket |
|---:|---|---:|---|
| 1 | `lookup key is not available from verifier-guided state` | 14 | direct_const |
| 2 | `map type 5 not inlineable` | 2 | direct_const |

### tracee

| rank | final-round skip reason | count | path bucket |
|---:|---|---:|---|
| 1 | `lookup key is not available from verifier-guided state` | 615 | direct_const |
| 2 | `map-in-map outer key unavailable: verifier-guided key extraction is unavailable after a prior map_inline rewrite` | 53 | map_in_map |
| 3 | `map-in-map outer key unavailable: verifier-guided key extraction failed: verifier log did not expose r2 stack pointer at call pc 1208` | 12 | map_in_map |
| 4 | `map-in-map outer key unavailable: verifier-guided key extraction failed: verifier log did not expose r2 stack pointer at call pc 1238` | 9 | map_in_map |
| 5 | `map-in-map outer key unavailable: verifier-guided key extraction failed: verifier log has no state snapshot at call pc 736` | 9 | map_in_map |
| 6 | `map-in-map outer key unavailable: verifier-guided key extraction failed: verifier log did not expose r2 stack pointer at call pc 1168` | 9 | map_in_map |
| 7 | `map-in-map outer key unavailable: verifier-guided key extraction failed: verifier log did not expose r2 stack pointer at call pc 1178` | 8 | map_in_map |
| 8 | `map-in-map outer key unavailable: verifier-guided key extraction failed: verifier log did not expose r2 stack pointer at call pc 1230` | 8 | map_in_map |
| 9 | `map-in-map outer key unavailable: verifier-guided key extraction failed: verifier log has no state snapshot at call pc 729` | 8 | map_in_map |
| 10 | `map-in-map outer key unavailable: verifier-guided key extraction failed: verifier log did not expose r2 stack pointer at call pc 1000` | 7 | map_in_map |

### katran

| rank | final-round skip reason | count | path bucket |
|---:|---|---:|---|
| 1 | `lookup key is not available from verifier-guided state` | 14 | direct_const |
| 2 | `map-in-map chain is not inlineable` | 2 | map_in_map |
| 3 | `map-in-map outer key unavailable: verifier-guided key extraction failed: verifier log has no state snapshot at call pc 1065` | 1 | map_in_map |
| 4 | `map-in-map outer key unavailable: verifier-guided key extraction failed: verifier log has no state snapshot at call pc 1770` | 1 | map_in_map |

### cilium

| rank | final-round skip reason | count | path bucket |
|---:|---|---:|---|
| 1 | `map type 5 not inlineable` | 151 | direct_const |
| 2 | `lookup key is not available from verifier-guided state` | 118 | direct_const |
| 3 | `map type 11 not inlineable` | 32 | direct_const |
| 4 | `map type 10 not inlineable` | 10 | direct_const |
| 5 | `runtime_key_lookup_result_has_no_scalar_loads` | 1 | runtime_key |

## Diagnostic examples

Observed applied diagnostics are all Path 2:

- Path 2, otel `prog_id=6`:
  `corpus/results/x86_kvm_corpus_20260506_223040_471337/details/apps/otelcol-ebpf-profiler__profiling.json:401`
  `site at PC=23: constantized pseudo-map-value load from map_id=38 off=40 value=0x0`
- Path 2, tracee `prog_id=43`:
  `corpus/results/x86_kvm_corpus_20260506_223933_808849/details/apps/tracee__monitor.json:8904`
  `site at PC=1507: constantized pseudo-map-value load from map_id=231 off=18 value=0x1`
- Path 2, cilium `prog_id=106`:
  `corpus/results/x86_kvm_corpus_20260506_231737_864379/details/apps/cilium__agent.json:1422`
  `site at PC=3: constantized pseudo-map-value load from map_id=61 off=85 value=0x0`

No Path 1, Path 3, or Path 4 applied diagnostic was present in these six files.
Relevant veto/skip instances:

- Direct-constant prerequisite miss, otel `prog_id=6`:
  `corpus/results/x86_kvm_corpus_20260506_223040_471337/details/apps/otelcol-ebpf-profiler__profiling.json:441`
  `site at PC=18: skip reason: lookup key is not available from verifier-guided state`
- Map-in-map veto, tracee `prog_id=20`:
  `corpus/results/x86_kvm_corpus_20260506_223933_808849/details/apps/tracee__monitor.json:3575`
  `site at PC=759: skip reason: map-in-map outer key unavailable: verifier-guided key extraction failed: verifier log has no state snapshot at call pc 759`
- Runtime-key veto, cilium `prog_id=106`:
  `corpus/results/x86_kvm_corpus_20260506_231737_864379/details/apps/cilium__agent.json:1429`
  `site at PC=206: skip reason: runtime_key_lookup_result_has_no_scalar_loads`

## Core findings

1. All 2580 applied sites are Path 2 pseudo-map-value direct loads. Path 1 direct
   constant inline, Path 3 map-in-map specialization, and Path 4 runtime-key
   chain rewrite have 0 applied sites in this x86 KVM smoke set.
2. Path 2 is concentrated in cilium (1255), otel (1192), and tracee (133).
   bcc, bpftrace, and katran have no applied `map_inline` sites.
3. Path 4 is not common here: it has 0 applied sites and only one final-round
   veto, in cilium `prog_id=106`.
4. cilium and tracee are not Path 4-heavy. cilium's applied sites are all Path 2;
   tracee's applied sites are also all Path 2, while many tracee skips bucket to
   map-in-map verifier-key unavailability.
5. The overall final-round `lookup key is not available from verifier-guided state`
   rate is 811/4931 = 16.45%. Counting all diagnostic attempts including R2+
   repeats, it is 1114/5513 = 20.21%.
6. otel has 13 `map_inline` programs and 1192 applied sites because individual
   programs contain many pseudo-map-value load PCs, not because R2+ added catches.
   Top otel applied counts are `prog_id=9` 189, `prog_id=8` 178,
   `prog_id=13` 169, `prog_id=10` 153, and `prog_id=14` 141; R2+ applied is 0.
