# tetragon map_inline verifier state missing, 2026-05-05

## Inputs

Run analyzed: `corpus/results/x86_kvm_corpus_20260505_173741_854355`. The run used `SAMPLES=1` and pass chain `noop,map_inline` (`metadata.json:4-7`, `metadata.json:18-22`).

No benchmarks were rerun. This is an artifact/code-path investigation only.

## Symptom

For tetragon prog 176, `noop` succeeded (`details/apps/tetragon__observer.json:5265-5279`), then `map_inline` reported matched lookup sites but skipped all of them (`details/apps/tetragon__observer.json:5325-5334`). The same example appears in the aggregate `result.json`: `map_inline` says `sites_applied=0`, `sites_matched=20`, `sites_skipped=20`, with 19 skips from `lookup key is not available from verifier-guided state` and one unsupported map type (`details/result.json:20493-20503`).

Concrete PCs for prog 176:

- Missing verifier-state lookup-key PCs: `32, 57, 82, 107, 119, 129, 260, 269, 278, 924, 1017, 1053, 1130, 1179, 1201, 1231, 1274, 1297, 1329` (`details/apps/tetragon__observer.json:5284-5323`).
- Unsupported-map PC: `1062`, `map type 5 not inlineable` (`details/apps/tetragon__observer.json:5308-5309`).
- Example diagnostic in the required `result.json`: `site at PC=32: verifier-guided key extraction failed: verifier log has no state snapshot at call pc 32` (`details/result.json:20452-20453`).

## Code Path

`map_inline` finds helper-call sites with `find_map_lookup_sites`, then runs `extract_site_constant_key` for each candidate (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:691-706`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:765-785`). The verifier-guided path calls `try_extract_constant_key_verifier_guided` with `program.verifier_states` and the lookup `call_pc` (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:1036-1048`).

The critical assumption is exact-PC state availability: `try_extract_constant_key_verifier_guided` filters parsed verifier states with `state.pc == call_pc`, and emits `verifier log has no state snapshot at call pc ...` if the filtered list is empty (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:242-251`). After it has an exact call-PC occurrence, it looks backward for the latest `r2` frame-pointer offset and stack store (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:287-318`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:522-590`).

`bpfopt` receives verifier states through the CLI side input, not by reading raw verifier logs. `map_inline` requires `--verifier-states`, `--map-values`, and `--map-ids` (`bpfopt/crates/bpfopt/src/main.rs:425-430`). The CLI reads `verifier-states.json` and constructs `VerifierInsn` records from JSON only (`bpfopt/crates/bpfopt/src/main.rs:963-984`), then attaches them to `BpfProgram.verifier_states` (`bpfopt/crates/bpfopt/src/pass.rs:108-109`, `bpfopt/crates/bpfopt/src/pass.rs:372-375`).

## Noop Verifier Log Capture

The daemon allocates a per-program temp workdir under `std::env::temp_dir()` named `bpfrejit-daemon-optimize-{pid}-{id}` (`daemon/src/commands.rs:58-70`). Inside that workdir, pass artifacts are named from `pass_file_stem`, so the noop raw log path is `pass-00-noop.verifier.log` (`daemon/src/commands.rs:463-467`, `daemon/src/commands.rs:599-600`).

For every pass, the daemon calls `BPF_PROG_REJIT` with a log buffer (`daemon/src/commands.rs:539-555`). `kernel-sys` sets `attr.log_level = 2` whenever a log buffer is supplied (`bpfopt/crates/kernel-sys/src/lib.rs:1298-1327`, `bpfopt/crates/kernel-sys/src/lib.rs:1386-1403`). On successful ReJIT, the daemon writes the raw verifier log to the per-pass `.verifier.log`, then parses it into `VerifierStatesJson` (`daemon/src/commands.rs:209-219`). It writes the parsed states to `verifier-states.json` for the next pass, removing any stale copy first (`daemon/src/commands.rs:551-552`, `daemon/src/commands.rs:647-653`).

The raw noop log is not preserved after a successful program optimization. `WorkDir::drop` removes the whole temp directory (`daemon/src/commands.rs:84-90`), and this run's daemon logs only show daemon startup/shutdown, not per-pass artifact paths (`details/daemon.stdout.log:1-2`). Therefore, for this run, I could not inspect raw `frame`, `regs`, or `stack` text near tetragon PC 32 or otelcol PC 7/18.

## Hypothesis Tree

### a. Kernel verifier does not emit state at every call PC: SUSPECT

The observable failure is exactly "no parsed state whose `pc` equals the map lookup call PC" (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:242-251`, `details/result.json:20452-20453`). That is consistent with the kernel emitting verifier state only at selected points rather than every helper call. The same exact-PC assumption fails broadly for tetragon and tracee helper-call sites (`details/apps/tetragon__observer.json:5284-5323`, `details/apps/tracee__monitor.json:2899-2910`).

This is not CONFIRMED because the raw noop verifier log for prog 176 was deleted (`daemon/src/commands.rs:84-90`). The artifact only proves the parsed `verifier-states.json` did not contain those call PCs.

### b. bpfopt/kernel-sys misses or drops snapshots: SUSPECT

There is a concrete lossy conversion path. `kernel-sys` parses raw log lines into state kinds, but `convert_verifier_states` drops branch-delta states and, if any instruction-delta state exists, drops non-instruction full states (`bpfopt/crates/kernel-sys/src/lib.rs:361-375`). The parser itself recognizes full-state formats like `from <prev> to <pc>: ...`, `<pc>: R...`, and instruction-state lines (`bpfopt/crates/kernel-sys/src/verifier_log.rs:1-12`, `bpfopt/crates/kernel-sys/src/verifier_log.rs:82-90`). Its tests include `frame1:` and stack tokens (`bpfopt/crates/kernel-sys/src/verifier_log.rs:652-659`, `bpfopt/crates/kernel-sys/src/verifier_log.rs:696-709`).

So if tetragon's raw noop log had a full/edge snapshot at a lookup call PC, the current conversion could drop it before `bpfopt` sees it. This remains SUSPECT rather than CONFIRMED because the raw log is not preserved for this run.

### c. map_inline reads a stale or wrong log: RULED OUT

The daemon uses one workdir per program (`daemon/src/commands.rs:389-391`) and passes the same `verifier-states.json` path into any pass that needs states (`daemon/src/commands.rs:471-484`, `daemon/src/commands.rs:632-640`). It refuses state-consuming passes until a previous pass has successfully ReJITed and produced states (`daemon/src/commands.rs:460-483`). After each successful pass, it removes any existing verifier-state file before writing the new one (`daemon/src/commands.rs:647-653`). For prog 176, `noop` is `ok` and `map_inline` is `ok`, so `map_inline` ran after a successful state-producing noop (`details/apps/tetragon__observer.json:5265-5279`, `details/apps/tetragon__observer.json:5337-5339`).

## tetragon Prog 176 vs otelcol Prog 43

Tetragon prog 176:

- Result name/type: `event_wake_up_new_task`, `kprobe`; baseline `bytes_jited=7335`, `bytes_xlated=11312` (`details/apps/tetragon__observer.json:14-21`).
- Daemon metadata: `prog_name=event_wake_up_n`, `prog_type=2`, `orig_insn_count=1365`, `final_insn_count=1365` (`details/apps/tetragon__observer.json:5342-5349`).
- `map_inline`: 0 applied, 20 matched, 20 skipped (`details/apps/tetragon__observer.json:5328-5334`).
- It has no preserved raw noop verifier log, for the workdir-deletion reason above (`daemon/src/commands.rs:84-90`, `daemon/src/commands.rs:463-467`).

Otelcol prog 43:

- Result name/type: `perf_unwind_stop`, `perf_event`; baseline `bytes_jited=3721`, `bytes_xlated=6232` (`details/apps/otelcol-ebpf-profiler__profiling.json:5-12`).
- Daemon metadata: `prog_name=perf_unwind_sto`, `prog_type=7`, `orig_insn_count=1634`, `final_insn_count=1634` (`details/apps/otelcol-ebpf-profiler__profiling.json:628-635`).
- `map_inline`: 40 applied, 60 matched, 20 skipped (`details/apps/otelcol-ebpf-profiler__profiling.json:615-620`).
- The 40 successes are not evidence that verifier-guided helper lookup extraction works. They are `constantized pseudo-map-value load ...` diagnostics (`details/apps/otelcol-ebpf-profiler__profiling.json:289-328`), produced by `build_direct_map_value_load_rewrites`, which scans direct pseudo-map-value loads and does not use `try_extract_constant_key_verifier_guided` (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:1235-1336`).
- Otelcol prog 43 still has the same exact-PC verifier-state failure for helper lookup PCs such as 7, 18, 86, and others (`details/apps/otelcol-ebpf-profiler__profiling.json:329-368`).

The result payload does not preserve subprog count or verifier complexity metrics such as `processed`, `total_states`, or `peak_states`. The daemon result `ProgramInfo` only serializes `prog_id`, `prog_name`, `prog_type`, `orig_insn_count`, and `final_insn_count` (`daemon/src/commands.rs:155-162`). Without raw verifier logs or bytecode artifacts from this successful run, subprog-count and processed-state comparisons cannot be made from this artifact.

## Verdict

The root cause proven by this artifact is a bpfopt-side precondition mismatch: `map_inline` requires an exact parsed verifier-state entry at each `bpf_map_lookup_elem` call PC, but the parsed state JSON produced after noop lacks those PCs (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:242-251`, `details/result.json:20452-20503`).

The artifact does not prove whether the raw kernel verifier log lacked those call-PC states or whether `kernel-sys` dropped/failed to parse them. The stale/wrong-log hypothesis is ruled out by the daemon pass-chain and stale-file removal code (`daemon/src/commands.rs:460-484`, `daemon/src/commands.rs:647-653`).

## Aggregate Impact

Computed from the same result/app JSON files:

- tetragon: 287 programs total; 44 noop `failed_rejit`; 243 programs had `noop=ok`, `map_inline=ok`, and the lookup-key verifier-state skip; 2832 lookup-key skips; 0 applied map-inline sites (`details/apps/tetragon__observer.json:1-4`, example at `details/apps/tetragon__observer.json:5284-5334`).
- tracee: 117 successful `map_inline` programs hit the same skip reason, with 1261 such skipped sites; including failed-ReJIT summaries, 119 programs and 1287 skipped sites hit it (`details/apps/tracee__monitor.json:1-4`, example at `details/apps/tracee__monitor.json:2899-2910`).
- cilium: 1 successful `map_inline` program hit the same skip reason, with 1 such skipped site; including failed-ReJIT summaries, 2 programs and 2 skipped sites hit it (`details/apps/cilium__agent.json:1-4`, example at `details/apps/cilium__agent.json:917-964`).

For reproducibility, the counts above were produced by counting per-program `passes[].bpfopt_summary.skip_reasons["lookup key is not available from verifier-guided state"]` in the listed app JSON files. The successful-only counts additionally require the `map_inline` pass status to be `ok`.

## Proposed Fix

First fix the observability gap for one diagnostic run: preserve `pass-00-noop.verifier.log` and `verifier-states.json` for successful programs when requested by an explicit debug/export knob. The minimal implementation point is the daemon workdir lifecycle and per-pass artifact creation: `WorkDir::drop` currently deletes the temp tree (`daemon/src/commands.rs:84-90`), and the raw log path is already known at `pass_verifier_log` (`daemon/src/commands.rs:463-467`). This is required to distinguish kernel emission from parser/conversion loss without rerunning blind.

If the preserved raw log shows full/edge snapshots at lookup call PCs, fix `kernel-sys` conversion at `bpfopt/crates/kernel-sys/src/lib.rs:366-375` to retain full/edge states instead of discarding them when any instruction-delta state exists. If the preserved raw log truly has no call-PC state, fix `map_inline` at `bpfopt/crates/bpfopt/src/passes/map_inline.rs:242-251` so verifier-guided key extraction can anchor on the latest verifier state before the call in the same frame/path, requiring all candidate anchors to agree before rewriting.
