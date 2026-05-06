# Daemon residual OOM after bpftool map snapshot change - 2026-05-06

## 1. Eliminated hypothesis: map values are no longer daemon-resident

The dirty working tree has removed the old daemon-side map entry materialization path. There is no remaining `write_live_map_values`, `MapKeySnapshot`, `MapValueSnapshotEntry`, `entries_by_map`, or recursive daemon-owned map-value structure under `daemon/src`.

Current dirty code writes bpftool output to per-program workdir files:

- `daemon/src/commands.rs:23-26` defines `MAP_SNAPSHOT_MAX_BYTES = 64 * 1024`.
- `daemon/src/commands.rs:842-887` creates the map snapshot directory and iterates only over `bpf::MapInfo` metadata.
- `daemon/src/commands.rs:858-869` dumps each map to `map-<id>.dump.json`, stats the file, and removes it when over 64 KiB.
- `daemon/src/commands.rs:890-901` runs `bpftool` as a subprocess with stdout redirected directly to the output file through `Stdio::from(file)`. It only captures stderr for failure reporting.
- `daemon/src/bpf.rs:30-38` shows `MapInfo` contains only `map_id`, `name`, `map_type`, `key_size`, `value_size`, and `max_entries`. It has no key/value payload fields.
- `daemon/src/bpf.rs:40-45` shows `ProgramSnapshot` holds `ProgramInfo`, `Vec<MapInfo>`, and original instructions only.

The Tetragon OOM artifact confirms the filter was active. `corpus/results/x86_kvm_corpus_20260506_203818_272133/details/daemon.stderr.log` contains 3550 map snapshot decisions across 287 unique program IDs:

```text
dumped: 2123
skip_size: 827
skip_type: 600
unique prog_ids with skip_size: 287
```

So the old "daemon deep-copies live map values into Rust Vecs" explanation is eliminated for the dirty source state. Map values are now mostly child-process and file-system pressure, not daemon RSS.

Important residual edge: the 64 KiB removal is not memory-free behaviorally. `bpfopt` still expects a dump file for every dumpable map:

- `bpfopt/crates/bpfopt/src/main.rs:1080-1117` loops over all passed `map_ids` and, for dumpable map types, calls `read_bpftool_map_dump`.
- `bpfopt/crates/bpfopt/src/main.rs:1142-1145` unconditionally reads `map-<id>.dump.json`.
- `bpfopt/crates/bpfopt/src/main.rs:1301-1304` uses `fs::read`; a removed dump file is a hard error.

Because all 287 Tetragon programs had at least one `skip_size`, the current dirty run almost certainly makes every `map_inline` bpfopt invocation fail after the preceding `noop` step has already generated verifier artifacts.

## 2. Per-program daemon state inventory

This is the daemon-owned state that can live during one program's optimize lifetime.

Small or bounded per-program state:

- `ProgramSnapshot` from `daemon/src/bpf.rs:40-45`: original instructions plus small program/map metadata.
- `orig_bytes`, `current_bytes`, `pass_bytes`, and `pass_insns` in `daemon/src/commands.rs:449-500` and `635-659`: bytecode-sized buffers, generally KiB to low MiB, not a 50 GiB candidate.
- `RejitFdArray` in `daemon/src/commands.rs:483-485`: map and BTF fds, small vectors.
- `target.json` state in `daemon/src/commands.rs:456-475`: only built when a step references `${TARGET}`. The 2026-05-06 OOM metadata enabled only `noop` and `map_inline`, so this path is not relevant.
- `cmd_output` from `Command::output()` in `daemon/src/commands.rs:535-551`: captures full stdout/stderr for a bpfopt step while that loop iteration is active. The stored failure message is truncated to 40 lines in `daemon/src/commands.rs:577-605`, so final result retention is small unless the subprocess itself emits huge output before exit.
- `bpfopt_summary: serde_json::Value` in `PassDetail` (`daemon/src/commands.rs:167-175`) read at `daemon/src/commands.rs:557-575`. This is retained in `step_details` and later in `OptimizeOneResult`, but prior successful Tetragon `noop,map_inline` artifacts were about 1.4 MiB total for 287 programs, so this is not a 53 GiB match by itself.

Large transient verifier state:

- `daemon/src/commands.rs:182-220` is the critical per-step ReJIT path.
- `daemon/src/commands.rs:192` allocates the verifier log buffer.
- `daemon/src/commands.rs:193-198` passes that buffer to `kernel_sys::prog_rejit`.
- `daemon/src/commands.rs:205-207` converts the log buffer to a `String` and writes the verifier log file.
- `daemon/src/commands.rs:216` parses the log into `kernel_sys::VerifierStatesJson`.
- `daemon/src/commands.rs:690-692` writes the structured verifier states JSON to disk.

The apparent 16 MiB cap is not a real cap. `daemon/src/commands.rs:23-25` starts log-level-2 calls at 16 MiB, but `bpfopt/crates/kernel-sys/src/lib.rs:43` defines a 256 MiB maximum and `bpfopt/crates/kernel-sys/src/lib.rs:1369-1389` doubles the caller's `Vec<u8>` on `ENOSPC` until the max. The actual log buffer can therefore be 256 MiB per active ReJIT.

The parser then expands text into owned Rust structures:

- `bpfopt/crates/kernel-sys/src/lib.rs:126-134` has `VerifierInsn` with per-insn `HashMap`s for regs and stack.
- `bpfopt/crates/kernel-sys/src/lib.rs:136-185` stores owned `String`s and nested states for regs/stack.
- `bpfopt/crates/kernel-sys/src/lib.rs:188-226` defines the serialized JSON form with `Vec`, `BTreeMap`, and owned strings.
- `bpfopt/crates/kernel-sys/src/lib.rs:360-371` parses the raw log into `Vec<VerifierInsn>` and converts it to `VerifierStatesJson`, so parsed and serialized forms coexist.
- `bpfopt/crates/kernel-sys/src/lib.rs:374-444` allocates BTreeMap keys like `rN` and `fpN`, clones reg type strings, and formats tnums/kinds.

Large retained failure artifact state:

- `daemon/src/commands.rs:280-294` runs `tar -czf -` over the whole workdir and captures the entire compressed tarball in memory with `Command::output()`.
- `daemon/src/commands.rs:257-264` base64-encodes that tarball into a `String`.
- `daemon/src/commands.rs:119-128` stores the base64 string in `OptimizeOneResult.workdir_tar_b64`.
- `daemon/src/commands.rs:401-409` attaches a tarball whenever the result status is not ok or any pass failed.
- `daemon/src/commands.rs:413-414` also attaches a tarball for hard errors.

For the dirty run, `skip_size` makes `map_inline` fail after `noop`. That means the tarred workdir includes at least:

- `input_step0.bin`
- `output_step0.bin`
- `report_step0.json`
- `verifier_log_step0.log`
- `verifier_states_step0.json`
- `map-values/map-*.show.json`
- small `map-values/map-*.dump.json` files

The verifier log and verifier states files are the large members.

Batch-level retention:

- `daemon/src/commands.rs:237-247` caps default worker count at 16 on this 24-CPU host.
- `daemon/src/commands.rs:320-333` runs `prog_ids.par_iter()` under Rayon and collects all `ApplyProgramOutcome` values into one `Vec`.
- `daemon/src/server.rs:292-309` consumes that Vec only after all programs finish and converts each result to `serde_json::Value`.
- `daemon/src/server.rs:85` then serializes the entire response to one `String`.

So the daemon does not stream per-program results. Completed failed results, including `workdir_tar_b64`, accumulate until the whole 287-program request completes.

Runner-side `CaseLifecycleState` is not the daemon problem. `runner/libs/case_common.py:129-133` stores only runtime, `prog_ids`, and `artifacts`; the 53 GiB RSS belonged to `bpfrejit-daemon`.

## 3. Memory math

Observed OOM:

```text
anon-rss: 53285428 kB = 50.82 GiB
287 Tetragon programs
default daemon workers on this host: 16
enabled passes: noop,map_inline
```

If the memory were evenly retained across all programs, the required average would be:

```text
50.82 GiB / 287 = 181 MiB per program
```

That is too high for source bytecode, target.json, MapInfo metadata, bpfopt summaries, or small map dump JSON. It is plausible for per-program failure tarballs that include compressed/base64 verifier logs and verifier states.

If the memory were only active-worker transient state, the required peak would be:

```text
50.82 GiB / 16 = 3.18 GiB per active worker
```

That is also plausible for verifier processing:

- Up to 256 MiB mutable log buffer after silent `ENOSPC` growth.
- Up to another 256 MiB `verifier_log` String.
- Potentially hundreds of MiB to multiple GiB in parsed `Vec<VerifierInsn>` due to HashMap nodes, BTreeMap nodes, owned strings, and nested reg/stack states.
- Another structured `VerifierStatesJson` coexisting with the parsed representation before it is written.
- Allocator high-water retention across repeated large allocations on Rayon worker threads.

The best fit is the combination:

1. `noop` produces huge log-level-2 verifier artifacts.
2. `map_inline` fails for every program because `skip_size` removed required bpftool dump files.
3. Each failure causes `tar_workdir` to capture and base64-retain the whole workdir in `OptimizeOneResult`.
4. Rayon `collect()` holds all completed results until all 287 programs finish.
5. Active workers simultaneously carry verifier log parse/convert peaks.

This explains why RSS can still reach the old 53 GiB range even after map values moved to disk.

Rejected or secondary hypotheses:

- H1, direct "noop verifier_states cached in daemon RAM across the entire run": false in direct form. The daemon writes states to disk and only carries the path forward. True indirectly through failure workdir tarballs and active ReJIT parsing.
- H2, target.json buffering: not relevant for this run. `noop,map_inline` does not reference `${TARGET}`.
- H3, daemon MapInfo deep-copy still holding key/value bytes: eliminated. `MapInfo` has no values and bpftool stdout goes to files.
- H4, kernel ReJIT response/verifier log: true and important. The real cap is 256 MiB, not 16 MiB, and parsing expands it heavily.
- H5, workdir tar retained on success: false for success, true for failures. The current filter likely makes all 287 programs fail at `map_inline`, and failed workdir tars are retained.
- H6, Rayon result accumulator: true. The accumulator is not large by itself, but it retains the large `workdir_tar_b64` strings and `bpfopt_summary` values.
- Other: bpfopt child memory is real system pressure because bpfopt reads map dumps and verifier states into its own process, but it does not explain the daemon's own 53 GiB RSS.

## 4. Verdict

Dominant cause: failed-program result accumulation of base64 workdir tarballs containing giant `noop` verifier logs and verifier-state JSON, triggered by the 64 KiB bpftool dump removal making `map_inline` fail for every Tetragon program. The underlying large data source is the log-level-2 verifier output path, whose buffer can grow to 256 MiB and whose parser materially expands the log in daemon memory.

Confidence: high for the failure-tar retention mechanism, high that map values are no longer directly daemon-resident, medium-high that verifier logs/states are the dominant payload inside the tarballs and transient active-worker peaks.

The key evidence is that every one of the 287 Tetragon programs had at least one `skip_size` event, while bpfopt still treats a missing dump JSON as an error. The daemon then intentionally tars failed workdirs and stores them in every per-program result, and it does not stream or drop those results until the full Rayon batch completes.

## 5. Fix dimensions

No code patch is proposed here. Concrete dimensions to attack:

- Failure artifact policy: do not keep full per-program workdir archives in daemon RAM for large 287-program batches. Spool artifacts to disk, stream them, cap them with an explicit error, or return paths/manifest metadata instead of base64 payloads.
- Verifier artifact lifecycle: avoid storing both raw verifier log and structured verifier states in failed workdir archives by default; keep the minimum diagnostic surface needed to explain the failure.
- Verifier parsing memory: stream `verifier_states` to disk or parse only the state facts needed by the next pass instead of building full parsed and JSON forms in memory at once.
- Log buffer growth: make the 256 MiB auto-growth visible and bounded by an explicit daemon policy for benchmark runs, especially for log-level-2 bootstrap passes.
- Map snapshot contract: either make oversized map snapshots a visible per-program optimization error before running `noop`, or make bpfopt understand an explicit skipped-dump marker. Do not remove dump files silently when the consumer treats absence as corruption.
- Rayon backpressure: control memory by bytes in flight, not just by worker count. A 16-worker cap is insufficient when each worker can carry multi-GiB verifier parse state.
- Response shape: stream per-program results or flush completed results out of daemon memory instead of collecting all 287 outcomes and serializing one giant response.
- Child process accounting: bpfopt map/verifier JSON deserialization is not the daemon RSS source, but it increases total system memory pressure and should be included in any concurrency budget.
