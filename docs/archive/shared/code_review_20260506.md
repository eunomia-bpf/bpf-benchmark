# Code Review Report 2026-05-06

Scope: recent map_inline value-stability work, bpf_writable map snapshot detection, bcc/set, untracked bpftrace/set, and the rejit_plan debug wrapper. Constraints followed: no cargo/pytest/make/smoke commands run; report-only review plus this markdown file.

## Per-Commit Findings

### 9bc5ba11 - bpf_writable detection

| Severity | File:line | Finding | Suggested fix |
|---|---:|---|---|
| P1 | `daemon/src/bpf.rs:125-145`, `daemon/src/bpf.rs:568-614` | `detect_bpf_writable_maps()` is infallible and the scanner records conservative guesses instead of surfacing detector gaps. A malformed/truncated LD_IMM64 map reference marks all target maps writable and returns, so the daemon silently downgrades value-stability coverage rather than reporting the bad bytecode/snapshot. | Delete the infallible scanner shape. Make write detection return `Result<HashSet<u32>>` and propagate malformed bytecode or unsupported scan states. |
| P1 | `daemon/src/bpf.rs:616-646`, `daemon/src/bpf.rs:827-829` | `TrackedPtr::UnknownMap` / `UnknownMapValue` are fallback states. Production bytecode is canonicalized to map indexes before scanning, so FD-form and out-of-range pseudo refs should be defects, not "mark everything writable and continue." | Delete the unknown pointer states and fail when canonicalized map refs cannot resolve to a map id. |
| P1 | `daemon/src/bpf.rs:670-672` | Unknown helper IDs are handled by marking all target maps writable and continuing. That hides missing helper semantics and makes paper-perf under-apply without an error. | Delete the unknown-helper fallback; fail with helper id and program id so the detector can be fixed explicitly. |
| P2 | `daemon/src/bpf.rs:857-859` | `store_width()` uses `unwrap_or(8)` for invalid store sizes. That is a silent fallback in BPF bytecode analysis. | Delete the default; propagate invalid width as an error from the scanner. |
| P1 | `daemon/src/commands.rs:350-385`, `daemon/src/commands.rs:970-989`, `daemon/src/commands.rs:1051-1086`; `bpfopt/crates/bpfopt/src/pass.rs:121-123`, `bpfopt/crates/bpfopt/src/pass.rs:232-234`; `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1332-1339`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1702-1708`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1797-1804`, `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2071-2077` | `entries_partial` is a leftover full-snapshot/entry-count escape hatch. The daemon emits partial snapshot metadata and bpfopt turns missing entries into site vetoes or `Ok(None)`, so incomplete live map capture becomes a skip path instead of an error. | Delete `entries_partial`, `MapKeySnapshot.entries_partial`, `map_entries_partial`, and the partial-snapshot helper errors. If map_inline needs a concrete snapshot and cannot get it, fail that pass. |
| P2 | `bpfopt/crates/bpfopt/src/pass.rs:331-332` | Missing `map_bpf_writable` defaults to writable. This is a compatibility fallback that hides missing side-input wiring. | Delete the default for maps present in `map-values.json`; missing mutability metadata should be an error when value-stability logic consults it. |

### d24e4980 - value-stability map_inline emitter

| Severity | File:line | Finding | Suggested fix |
|---|---:|---|---|
| P1 | `bpfopt/crates/bpfopt/src/passes/map_inline.rs:954-975` | Runtime-key rewrite errors are all converted into skip reasons. Only `site_level_inline_veto` is a candidate rejection; other errors include emitter/analysis defects and should fail the pass. | Delete the catch-all `unwrap_or_else(|| format!("runtime-key inline failed..."))` path and propagate non-veto errors. |
| P1 | `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1040-1065` | Non-concrete provider errors from `build_site_rewrite()` are recorded as `"map lookup failed"` skips. That is warning-and-continue for live snapshot IO/parse/provider failures. | Keep explicit site vetoes for real ineligible shapes; propagate all other map lookup/provider errors. |
| P2 | `bpfopt/crates/bpfopt/src/passes/map_inline.rs:524-542` | `materialization_for_snapshot_key()` uses `.ok()?` and silently drops materialization recovery. That can leave setup code in place without surfacing why key materialization could not be proven. | Delete the best-effort `.ok()?` fallback; either require materialization when deleting setup or do not attempt setup deletion. |
| P2 | `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2202-2210` | `site_level_inline_veto` is stringly-typed control flow through an `anyhow` prefix and later `strip_prefix`. This is redundant error handling and makes real errors easy to accidentally downgrade. | Delete the sentinel-string pattern; return site-veto reasons directly from candidate-check helpers and propagate ordinary errors. |

### c75bf9d5 / ad5fbf20 - bcc/set merged runner

| Severity | File:line | Finding | Suggested fix |
|---|---:|---|---|
| P0 | `runner/libs/app_runners/bcc_set.py:225-238`; `runner/libs/app_runners/bcc.py:365-389` | No App-Level Loader violation found. The runner starts real distro BCC tool binaries; `bpftool` is used only for discovery, not for loading `.bpf.o` files. | No deletion needed for app-level loading. |
| P1 | `runner/libs/app_runners/bcc_set.py@c75bf9d5:137-187` | The original c75 runner allowed partial tool startup: individual spawn/attach failures were recorded, but the app only failed if no BCC tool survived. That violates fail-fast and can silently change the app's BPF-program population. | Fixed forward by ad5fbf20 for startup completeness; do not restore the partial-run behavior. |
| P1 | `runner/libs/app_runners/bcc_set.py:64-74`, `runner/libs/app_runners/bcc_set.py:169-175`, `runner/libs/app_runners/bcc_set.py:295-303` | The current ad5 readiness fix uses child fdinfo IDs as the source of truth for `self.programs`. If a real BCC tool loads a program and then only keeps an attach/link/perf fd without a `prog_id` fdinfo entry, that program is excluded from ReJIT. That is a runner-side program-selection filter. | Delete `_program_records_for_ids()` as the program source of truth. Use fdinfo only as readiness/accounting, not to narrow the ReJIT program set. |

### untracked runner/libs/app_runners/bpftrace_set.py

| Severity | File:line | Finding | Suggested fix |
|---|---:|---|---|
| P0 | `runner/libs/app_runners/bpftrace_set.py:218-227` | No App-Level Loader violation found. It starts the real `bpftrace` binary with repo scripts; no framework `.bpf.o` loader is introduced. | No deletion needed for app-level loading. |
| P1 | `runner/libs/app_runners/bpftrace_set.py:120-129`, `runner/libs/app_runners/bpftrace_set.py:151-171` | The runner is fail-soft: spawn failures are recorded and ignored, and startup succeeds as long as one script remains alive. It also increments `live_scripts` even when that script reports zero fdinfo program IDs. | Delete the untracked runner until it has bcc/set-style all-child readiness, or delete the partial-run paths before landing it. |
| P1 | `runner/libs/app_runners/bpftrace_set.py:132-144`, `runner/libs/app_runners/bpftrace_set.py:166-174` | It returns the global stable post-start program set, not a per-script verified set. This can include unrelated new programs and can also mask a script with no attached programs. | Delete the global-set-as-success path; do not land `bpftrace/set` catalog entries while this is the source of truth. |

### runner/libs/rejit_plan.py debug capture wrapper

| Severity | File:line | Finding | Suggested fix |
|---|---:|---|---|
| P1 | `runner/libs/rejit_plan.py:83-94` | The `BPFREJIT_DAEMON_KEEP_ALL_WORKDIRS` block mutates every bpfopt command by copying input and appending `&& false`. A "keep workdirs" debug env var now changes benchmark semantics and forces artificial pass failures so failure artifacts are exported. | Delete lines 83-94 and return the real command. Debug capture must not be implemented by manufacturing failures. |

## DELETE LIST

- `runner/libs/rejit_plan.py:83-94` - delete the env-var-triggered `cp ... && false` command wrapper.
- `runner/libs/app_runners/bpftrace_set.py` - delete the untracked file until all-script fail-fast readiness is implemented; also delete pending `bpftrace_set` registry/catalog/manifest entries that depend on it.
- `runner/libs/app_runners/bcc_set.py:64-74` - delete `_program_records_for_ids()` as a ReJIT program selector.
- `daemon/src/bpf.rs:545-550`, `daemon/src/bpf.rs:616-646`, `daemon/src/bpf.rs:827-829` - delete `UnknownMap` / `UnknownMapValue` fallback handling.
- `daemon/src/bpf.rs:857-859` - delete `store_width()`'s invalid-width fallback.
- `daemon/src/commands.rs:261-265`, `daemon/src/commands.rs:350-385`, `daemon/src/commands.rs:970-989`, `daemon/src/commands.rs:1051-1086`; `bpfopt/crates/bpfopt/src/pass.rs:121-123`, `bpfopt/crates/bpfopt/src/pass.rs:262-280`, `bpfopt/crates/bpfopt/src/main.rs:252`, `bpfopt/crates/bpfopt/src/main.rs:1067`, `bpfopt/crates/bpfopt/src/main.rs:1082-1085` - delete the `entries_partial` / partial snapshot machinery.
- `bpfopt/crates/bpfopt/src/passes/map_inline.rs:2202-2210` - delete string-prefix `site_level_inline_veto` control flow.

## DESIGN VIOLATIONS

- P1: Debug env var forces pass failure (`runner/libs/rejit_plan.py:83-94`).
- P1: bpf_writable detector uses fallback states instead of failing on missing capability (`daemon/src/bpf.rs:616-646`, `daemon/src/bpf.rs:670-672`, `daemon/src/bpf.rs:827-829`).
- P1: Partial map snapshots become skip/none paths instead of concrete errors (`daemon/src/commands.rs:350-385`; `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1332-1339`, `:2071-2077`).
- P1: map_inline runtime-key and provider errors are downgraded to skipped sites (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:954-975`, `:1040-1065`).
- P1: bcc/set current readiness can narrow ReJIT to fdinfo-visible programs only (`runner/libs/app_runners/bcc_set.py:169-175`).
- P1: untracked bpftrace/set allows partial script startup and unverified zero-program children (`runner/libs/app_runners/bpftrace_set.py:120-129`, `:151-171`).
- P2: String-prefix sentinel errors in map_inline are over-engineered and make fail-fast behavior fragile (`bpfopt/crates/bpfopt/src/passes/map_inline.rs:2202-2210`).

## Unit Test Quality

Reviewed recently added `map_inline_tests.rs` tests:

- `map_inline_runtime_key_readonly_small_snapshot_emits_chain()` at `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:1211`.
- `map_inline_runtime_key_readonly_large_snapshot_has_no_entry_limit()` at `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:1253`.
- `map_inline_runtime_key_ignores_bpf_writable_map()` at `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:1291`.

Failing Unit Test Quality count: **0**.

These are not trivial getter/std/mock-only tests. They cover runtime-key emission, the no-entry-limit regression, and the writable-map safety gate. I do not recommend deleting them.
