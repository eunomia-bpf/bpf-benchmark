# Daemon execute_plan Refactor Review

Review target:
- `d2e90290` Replace daemon optimize protocol with execute_plan step executor
- `83e4b48c` Add runner-side adapter that translates legacy apply_rejit to execute_plan

Method: source review only. I did not run benchmarks or spawn the daemon.

## Must-Fix Findings

### 1. bpfopt report read/parse failures are silently converted to `null`

`daemon/src/commands.rs:609-613` treats the report as optional by checking `report_path.exists()` and then using `read_json_file(...).unwrap_or(Value::Null)`. That swallows corrupt JSON, unreadable report files, and missing reports for adapter-generated bpfopt steps. This is a direct fail-fast violation: `CLAUDE.md:70-74` says IO and parse errors must propagate and `unwrap_or_default`-style silencing is forbidden.

Impact: a bpfopt step can exit 0 but write a truncated or invalid `${REPORT}`; the daemon will still run ReJIT, return `status: ok`, and lose the pass report. Since the runner adapter always emits `--report ${REPORT}` for bpfopt steps (`runner/libs/rejit_plan.py:54-60`), missing or invalid report JSON should be a pass failure for those steps, not `Value::Null`.

Relevant code:
- `daemon/src/commands.rs:609-613`
- `daemon/src/commands.rs:1149-1152`
- `runner/libs/rejit_plan.py:54-60`
- `CLAUDE.md:70-74`

### 2. State-dependent passes can run against an empty verifier-state placeholder

The daemon always writes `verifier_states_initial.json` as `{ insns: [] }` before the first step (`daemon/src/commands.rs:548-554`) and passes that path into every step via `${VERIFIER_STATES}` (`daemon/src/commands.rs:570-581`). The adapter adds `--verifier-states ${VERIFIER_STATES}` whenever metadata says a pass needs verifier states (`runner/libs/rejit_plan.py:64-65`).

That no longer enforces the v3 contract that verifier states come only from a previous successful `BPF_PROG_REJIT(log_level=2)`: `CLAUDE.md:96-100` and `docs/kernel-jit-optimization-plan.md:396-404` both require previous successful ReJIT verifier logs, and `docs/kernel-jit-optimization-plan.md:346` says missing states should become `skipped_missing_states`, not an empty-state fallback.

This is not just cosmetic. `bpfopt` validates only that `--verifier-states` was provided (`bpfopt/crates/bpfopt/src/main.rs:405-424`), then accepts an empty `insns` array (`bpfopt/crates/bpfopt/src/main.rs:917-935`). `map_inline` turns empty states into a site-level skip (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:220-228`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:765-787`), so a missing-state bug can surface as a successful no-op pass instead of a visible daemon skip/error.

Relevant code:
- `daemon/src/commands.rs:548-554`
- `daemon/src/commands.rs:570-581`
- `runner/libs/rejit_plan.py:64-65`
- `bpfopt/crates/bpfopt/src/main.rs:405-424`
- `bpfopt/crates/bpfopt/src/main.rs:917-935`
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:220-228`
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:765-787`
- `CLAUDE.md:96-100`
- `docs/kernel-jit-optimization-plan.md:346`
- `docs/kernel-jit-optimization-plan.md:396-404`

### 3. Empty `programs` and empty/missing per-program `steps` are accepted as successful no-ops

The new protocol explicitly treats an empty `steps` list as a deliberate skip (`daemon/src/commands.rs:396-399`) and returns a status-`ok` result without snapshotting or ReJIT (`daemon/src/commands.rs:431-432`, `daemon/src/commands.rs:466-480`). The server also accepts missing `steps` as `Vec::new()` (`daemon/src/server.rs:127-145`) and has tests locking in both empty and missing steps as accepted (`daemon/src/server.rs:413-433`). Empty top-level `programs` are also accepted by parser tests (`daemon/src/server.rs:366-375`) and then `try_execute_plan` returns `Ok(Vec::new())` (`daemon/src/commands.rs:406-412`).

That creates a protocol-level skip path in a codebase whose benchmark rule says never skip or exclude BPF programs from ReJIT (`CLAUDE.md:5-10`). The runner adapter currently sends non-empty steps because `apply_daemon_rejit` requires non-empty passes (`runner/libs/rejit.py:379-386`), but the daemon protocol itself now has a successful no-op surface for malformed or future callers.

Relevant code:
- `daemon/src/commands.rs:396-399`
- `daemon/src/commands.rs:406-412`
- `daemon/src/commands.rs:431-432`
- `daemon/src/commands.rs:466-480`
- `daemon/src/server.rs:127-145`
- `daemon/src/server.rs:366-375`
- `daemon/src/server.rs:413-433`
- `runner/libs/rejit.py:379-386`
- `CLAUDE.md:5-10`

### 4. bpfopt subprocess timeout was removed; only kernel ReJIT hangs are documented as accepted

The old daemon path ran bpfopt through `run_stage_with_file_io` and killed a bpfopt pass after `OPTIMIZE_CLI_STAGE_TIMEOUT` of 60 seconds (`git show d2e90290^:daemon/src/commands.rs`: lines 32-34 and 1109-1175). The new executor runs `sh -c` with `.status()` and no timeout (`daemon/src/commands.rs:596-607`). The adapter-generated command is a bare `bpfopt ...` with no `timeout` wrapper (`runner/libs/rejit_plan.py:54-69`).

The design explicitly accepts no daemon-side watchdog for the synchronous kernel `BPF_PROG_REJIT` syscall (`CLAUDE.md:99-100`, `docs/kernel-jit-optimization-plan.md:404`). It does not grant the same exception to user-space `bpfopt`. A hung bpfopt now hangs the request indefinitely and can stall a paper run.

Relevant code:
- `daemon/src/commands.rs:596-607`
- `runner/libs/rejit_plan.py:54-69`
- `CLAUDE.md:99-100`
- `docs/kernel-jit-optimization-plan.md:404`

## Nice-To-Have / Contract Findings

### 5. Pass metadata duplicates are silently overwritten in the runner adapter

`load_pass_metadata` builds `metadata[canonical] = entry` without rejecting duplicate `canonical_name` entries (`runner/libs/rejit_plan.py:35-45`). The deleted daemon-side loader explicitly rejected duplicate or blank pass names (`git show d2e90290^:daemon/src/commands.rs`: lines 699-704). Blank names are still rejected, but duplicates are not.

Impact is low with the current static bpfopt registry, but this is a fail-fast contract gap: corrupted `list-passes --json` output should not silently choose the last entry.

Relevant code:
- `runner/libs/rejit_plan.py:35-45`

### 6. Unknown enabled pass errors are less useful than before

`build_execute_plan_payload` indexes `pass_metas[p]` before `build_kinsn_probes` can produce its explicit `"pass ... not found"` error (`runner/libs/rejit_plan.py:116-127`, `runner/libs/rejit_plan.py:80-85`). Unknown pass names therefore raise a raw Python `KeyError`, which is fail-fast but poor for runner debugging.

Relevant code:
- `runner/libs/rejit_plan.py:80-85`
- `runner/libs/rejit_plan.py:116-127`

### 7. Adapter-generated pass details lose canonical pass names

The daemon records every step as `step_{idx}` (`daemon/src/commands.rs:561-564`) and passes that as the serialized `"pass"` field (`daemon/src/commands.rs:710-715`, `daemon/src/commands.rs:840-851`). Since the adapter-generated bpfopt report also contains the real pass name, the data is recoverable, but downstream per-pass analysis currently prefers `ps["pass"]` before `bpfopt_summary["pass"]` (`analysis/corpus_analyze.py:127-130`). That means per-pass columns can become `step_0`, `step_1`, etc.

This is not a ReJIT correctness bug, but it degrades external analysis and debugging. The protocol needs either an explicit step name from the runner or downstream analysis should prefer `bpfopt_summary.pass` for bpfopt steps.

Relevant code:
- `daemon/src/commands.rs:561-564`
- `daemon/src/commands.rs:710-715`
- `daemon/src/commands.rs:840-851`
- `analysis/corpus_analyze.py:127-130`

### 8. `bpfopt list-passes` failure is fail-fast but not friendly

The adapter calls `subprocess.run(..., check=True, capture_output=True)` directly (`runner/libs/rejit_plan.py:21-32`). If bpfopt exits nonzero, Python raises `CalledProcessError` whose default string omits captured stderr; if bpfopt is missing, the caller sees a raw `FileNotFoundError`. This is not silent, but it is weaker than the runner's normal `run_command` error path, which includes command text and stderr/stdout tail (`runner/libs/__init__.py:106-130`).

The runtime image does install bpfopt and bpfprof in `/usr/local/bin` (`runner/containers/runner-runtime.Dockerfile:396-408`, `runner/containers/runner-runtime.Dockerfile:428-438`) and includes `/usr/local/bin` on PATH (`runner/containers/runner-runtime.Dockerfile:473-477`), so the Docker compatibility surface looks correct.

Relevant code:
- `runner/libs/rejit_plan.py:21-32`
- `runner/libs/__init__.py:106-130`
- `runner/containers/runner-runtime.Dockerfile:396-408`
- `runner/containers/runner-runtime.Dockerfile:428-438`
- `runner/containers/runner-runtime.Dockerfile:473-477`

### 9. Step template substitutions are unquoted shell text

The adapter emits paths as unquoted `${INPUT}`, `${OUTPUT}`, `${REPORT}`, etc. (`runner/libs/rejit_plan.py:54-69`), and the daemon substitutes raw strings before passing the result to `sh -c` (`daemon/src/commands.rs:780-819`, `daemon/src/commands.rs:596-607`). The current daemon workdir prefix is safe under normal `/tmp`, but a `TMPDIR` containing spaces or shell metacharacters would break the generated command or worse.

This is lower priority because benchmark containers normally use simple temp paths, but the protocol should either shell-quote substituted values or the adapter should quote its placeholders.

Relevant code:
- `runner/libs/rejit_plan.py:54-69`
- `daemon/src/commands.rs:596-607`
- `daemon/src/commands.rs:780-819`

### 10. Generic execute_plan does not model future profile side-inputs

`build_step_command` only knows target, verifier states, and map values (`runner/libs/rejit_plan.py:48-69`). `bpfopt` still has a pass-specific `branch_flip` requirement for `--profile` (`bpfopt/crates/bpfopt/src/main.rs:405-424`), while `list-passes --json` exposes no `needs_profile` field (`bpfopt/crates/bpfopt/src/main.rs:293-308`). Default benchmark policy does not include `branch_flip` (`corpus/config/benchmark_config.yaml:1-16`), so this is not a current default-run bug. It is a real contract to document: adding a new bpfopt side-input requires a schema change plus adapter support, or a custom plan generator that bypasses this legacy adapter.

Relevant code:
- `runner/libs/rejit_plan.py:48-69`
- `bpfopt/crates/bpfopt/src/main.rs:293-308`
- `bpfopt/crates/bpfopt/src/main.rs:405-424`
- `corpus/config/benchmark_config.yaml:1-16`

## A-G Coverage Notes

### A. Dead code / leftover from old protocol

No remaining daemon callers for the deleted `CliConfig`, `init_cli_dir`, `PASS_METADATA`, `pass_metadata_map`, `load_pass_metadata`, `subprocess_failure_message`, or `Stdio` path were found. Current `rg` only finds the new runner-side `_PASS_METADATA` cache and `load_pass_metadata` adapter (`runner/libs/rejit.py:265-273`, `runner/libs/rejit_plan.py:21-45`).

The helpers called out in the prompt still have real callers:
- `MapValuesJson` is used by `write_map_values_snapshot` (`daemon/src/commands.rs:902-934`).
- `RejitReport` is returned by `rejit_program` and consumed after successful ReJIT (`daemon/src/commands.rs:174-218`, `daemon/src/commands.rs:682-704`).
- `c_log_string` is used by `rejit_program` on both success and error (`daemon/src/commands.rs:197-204`, `daemon/src/commands.rs:220-223`).

The test `try_apply_programs_converts_failures_to_program_results` still covers the shared batch wrapper behavior used by `try_execute_plan` (`daemon/src/commands.rs:368-393`, `daemon/src/commands.rs:420-423`, `daemon/src/commands.rs:1408-1436`). Its name is stale but the behavior is still relevant.

### B. Fail-fast / silent errors

`substitute_vars` behaves correctly for the edge cases in the prompt:
- Unknown `${UNKNOWN}` returns `Err` through the var lookup (`daemon/src/commands.rs:811-814`).
- Unterminated `${` returns `Err` (`daemon/src/commands.rs:808-810`).
- `$NAME`, `$(cmd)`, and `$$` preserve the `$` and leave shell expansion to `sh -c` (`daemon/src/commands.rs:796-817`).
- Empty `${}` becomes `unknown var ${}` (`daemon/src/commands.rs:799-814`).

`OUTPUT` detection propagates non-`NotFound` metadata errors and the read-after-stat race becomes a failed step, not a swallowed error (`daemon/src/commands.rs:632-667`). The report handling is the main silent-error defect; see finding 1.

### C. Design rules

`daemon/src/server.rs` references `crate::bpf::KinsnProbeTarget` only to parse runner-supplied target probe requests (`daemon/src/server.rs:157-211`). That is still inside the daemon-owned live discovery/target probing boundary described by `daemon/src/bpf.rs:1-7`.

No daemon compile-time dependency on bpfopt was found. The Cargo dependencies point standalone CLIs only at `kernel-sys`, not each other (`daemon/Cargo.toml:24-27`, `bpfopt/crates/bpfopt/Cargo.toml:11-16`, `bpfopt/crates/bpfprof/Cargo.toml:11-19`). BPF syscall access from daemon code goes through `kernel_sys` (`daemon/src/bpf.rs:67-81`, `daemon/src/commands.rs:187-200`), matching the syscall-boundary rule in `CLAUDE.md:118-123`.

The new `runner/libs/rejit_plan.py` is a runner-side adapter at the existing socket boundary, not a broad corpus/e2e/micro refactor. It is still a policy-bearing adapter, so the side-input metadata contract in findings 5 and 10 matters.

### D. Protocol corner cases

`sh -c` can execute multiline step strings because the whole substituted command is passed as one `-c` argument (`daemon/src/commands.rs:596-607`). A signal-terminated step is reported as `exit signal` because `ExitStatus::code()` returns `None` (`daemon/src/commands.rs:615-624`); that is acceptable but not very detailed.

If a step writes `${OUTPUT}` and exits nonzero, the daemon checks status first and stops without using the output (`daemon/src/commands.rs:615-627`). That is fail-fast and reasonable.

If a step succeeds without non-empty `${OUTPUT}`, the daemon records `ok` and leaves input and verifier states unchanged (`daemon/src/commands.rs:629-654`). A step cannot update the verifier-state chain this way; current design says verifier states come from successful ReJIT logs, so that is consistent.

`kinsn_probes` are request-global and passed to every program (`daemon/src/server.rs:150-154`, `daemon/src/commands.rs:406-423`). That is reasonable because kernel BTF/module kinsn availability is global for the daemon session.

The initial verifier-state placeholder is not reasonable for state-dependent passes; see finding 2.

### E. Test coverage gaps

Do not add trivial tests, but these would catch real bugs:
- `substitute_vars` contract tests for unknown vars, unterminated braces, shell `$NAME` preservation, and `${}` rejection. Those are security/fail-fast behaviors, not getter-style tests (`daemon/src/commands.rs:780-819`).
- A report-handling test where a step references `${REPORT}` and writes corrupt JSON. Current code would silently return `null` (`daemon/src/commands.rs:609-613`).
- A state-readiness test for a first step requiring verifier states or a prior successful non-output step followed by `map_inline`; current code feeds the empty placeholder (`daemon/src/commands.rs:548-554`, `daemon/src/commands.rs:570-581`).

`parse_execute_plan_parses_kinsn_probes` covers the basic happy path but not duplicate/malformed alias payloads beyond empty aliases (`daemon/src/server.rs:436-460`). That is adequate for now; the more meaningful parser gap is empty programs/steps being accepted, which is covered but codifies the wrong behavior.

### F. Adapter quality

The global `_PASS_METADATA` cache is acceptable for a single runner process/session, and the GIL makes the simple assignment safe enough (`runner/libs/rejit.py:265-273`). The cache can go stale if a long-lived process swaps bpfopt binaries, but benchmark runners do not normally do that.

The adapter flags match the old daemon bpfopt invocation for the default passes: `--pass`, `--report`, `--prog-type`, optional `--target`, optional `--verifier-states`, optional `--map-values`, and optional `--map-ids` (`git show d2e90290^:daemon/src/commands.rs`: lines 736-766; `runner/libs/rejit_plan.py:48-69`). New code uses `--input`/`--output` files instead of stdin/stdout, which bpfopt supports (`bpfopt/crates/bpfopt/src/main.rs:92-102`).

Open adapter issues are findings 5, 6, 8, 9, and 10.

### G. Compatibility surface

The runtime image installs `bpfopt` and `bpfprof` into `/usr/local/bin` and verifies both are executable (`runner/containers/runner-runtime.Dockerfile:396-408`, `runner/containers/runner-runtime.Dockerfile:428-438`). `/usr/local/bin` is on the runtime PATH (`runner/containers/runner-runtime.Dockerfile:473-477`). `runner/mk/build.mk` also makes the runner runtime image depend on the bpfopt binaries (`runner/mk/build.mk:277-293`, `runner/mk/build.mk:296-312`).

`PROG_TYPE` looks compatible for supported app types: daemon names such as `xdp`, `tracing`, `sched_cls`, and `cgroup_skb` come from `daemon/src/bpf.rs:699-735`, and bpfopt accepts the same names (`bpfopt/crates/bpfopt/src/main.rs:679-724`). Unknown future program types become `"unknown"` in the daemon and would fail in bpfopt; current supported apps do not depend on those.

The old bpfopt subprocess timeout deletion is the main compatibility regression; see finding 4.
