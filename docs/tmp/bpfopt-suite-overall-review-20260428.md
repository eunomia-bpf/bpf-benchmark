# bpfopt-suite overall review

Date: 2026-04-28

Scope: read-only review of `bpfopt/crates/bpfopt`, `bpfopt/crates/bpfget`, `bpfopt/crates/bpfrejit`, `bpfopt/crates/bpfverify`, `bpfopt/crates/bpfprof`, `bpfopt/crates/kernel-sys`, `scripts/per-pass-verify.sh`, and the bpfopt-suite portions of `runner/containers/runner-runtime.Dockerfile` and `runner/mk/build.mk`.

Out of scope: daemon implementation internals and benchmark runner Python. I only used `daemon/Cargo.toml` and build failures as migration-status evidence because `bpfrejit-daemon` is one of the six v3 tools.

## Baseline evidence

| Check | Result |
| --- | --- |
| `cd bpfopt && cargo build --workspace` | PASS |
| `cd bpfopt && cargo test --workspace` | PASS: all bpfopt-suite workspace tests passed; no ignored tests observed |
| `cd bpfopt && cargo doc --no-deps -p bpfopt -p bpfget -p bpfrejit -p bpfverify -p bpfprof -p kernel-sys` | PASS with 4 rustdoc broken-link warnings |
| `cd bpfopt && cargo +nightly udeps --workspace --all-targets` | NOT RUN: `nightly-x86_64-unknown-linux-gnu` is not installed |
| `cargo build --manifest-path daemon/Cargo.toml` | FAIL, treated as daemon in-flight: missing `kernel_sys` dependency and stale server/command signatures |
| `cargo test --manifest-path daemon/Cargo.toml` | FAIL for the same daemon in-flight compile errors |
| `rg "libc::syscall\|SYS_bpf\|__NR_bpf"` in reviewed crate `src/` | Only `kernel-sys` calls direct `bpf(2)` |
| `rg "#\[allow(dead_code)\]"` in reviewed scope | 6 hits, all in `bpfopt/src/insn.rs` and `bpfopt/src/pass.rs` |
| `rg "// TODO\|// FIXME\|// HACK"` in reviewed scope | No hits |

Existing dirty daemon worktree changes were not touched. The daemon was being refactored concurrently, so daemon build/test failures are recorded only as in-flight migration status.

## v3 conformance matrix

| v3 section | Status | Evidence and notes |
| --- | --- | --- |
| §1 tool list | GAP | Five CLI tools exist in the `bpfopt` workspace: `bpfopt`, `bpfget`, `bpfrejit`, `bpfverify`, `bpfprof` (`bpfopt/Cargo.toml:1-9`). `bpfrejit-daemon` exists as the separate `daemon` crate, but it is not in the `bpfopt` workspace and currently does not compile. |
| §2.1 `bpfopt` commands/flags | DEVIATION | All 12 pass subcommands, `optimize`, `analyze`, and `list-passes` are present. Common flags are present. However `optimize` defaults to only `dce, skb-load-bytes, bounds-check-merge, wide-mem` (`bpfopt/crates/bpfopt/src/main.rs:41-46`, `:462-480`), not the 12-pass v3 default order. |
| §2.2 `bpfverify` | CONFORMANT with minor question | Required `--prog-type`, optional attach type, `--map-fds`, `--fd-array`, `--log-level`, `--report`, and `--verifier-states-out` exist. It pipes accepted bytecode through stdout. Report mode returns exit 0 for verifier failure when `--report` is present; decide whether v3 treats a structured fail report as command success or as exit 1. |
| §2.3 `bpfprof` | GAP | It captures BPF run counters, but PMU branch counters are host-window availability checks only; branch counts are discarded and per-program `branch_miss_rate`, `branch_misses`, `branch_instructions` are always `null` (`bpfopt/crates/bpfprof/src/main.rs:210-223`, `:409-412`). |
| §2.4 `bpfget` | GAP | Basic bytecode, info, full, list, and target modes exist. `--target` warns that kinsn BTF probing is not implemented and emits empty `kinsns` by default (`bpfopt/crates/bpfget/src/main.rs:273-284`). `--full` writes `prog.bin`, `prog_info.json`, and `map_fds.json`, but not `map-values.json`, so it cannot prepare all inputs needed by `bpfopt map-inline` (`bpfopt/crates/bpfget/src/main.rs:211-230`). |
| §2.5 `bpfrejit` | CONFORMANT with limitation | Reads file/stdin, supports `--fd-array` and `--dry-run`, calls `kernel_sys::prog_rejit`, and writes success summary to stderr. `fd_array` currently accepts inherited `btf_fd` only and rejects `btf_id`/module descriptors. |
| §2.6 `bpfrejit-daemon` | GAP / in-flight | The separate daemon crate exists but currently fails to compile. Runner still uses `serve --socket` and socket `optimize`/`profile-*` paths, so v3 daemon migration is not complete. |
| §3 bytecode binary | CONFORMANT | Raw `struct bpf_insn[]` little-endian parsing/serialization exists in bpfopt, bpfget, bpfverify, and bpfrejit. `bpfopt::BpfInsn` is a transparent wrapper over `kernel_sys::bpf_insn` with ABI/raw-byte tests. |
| §3 `target.json` | GAP | Shape is accepted by bpfopt, with useful extensions (`call_offset`, `supported_encodings`). Producer side is incomplete because `bpfget --target` cannot discover kinsn BTF IDs. |
| §3 `map-values.json` | DEVIATION | bpfopt consumes a compatible schema but adds `frozen` with default `true` (`bpfopt/crates/bpfopt/src/main.rs:314-333`, `:977-1012`). No reviewed tool produces this file. |
| §3 `profile.json` | DEVIATION | Current schema adds `pmu_available`, emits nullable branch fields, and always includes `per_insn: {}` (`bpfopt/crates/bpfprof/src/main.rs:60-70`). This conflicts with v3 and the "No Redundant Informational Fields" rule. |
| §3 `verifier-states.json` | CONFORMANT | bpfverify emits `{ "insns": [...] }`; bpfopt consumes the same shape. |
| §3 `pass-report.json` | PARTIAL | Single-pass `--report` matches the v3 fields. `optimize --report` emits `{ "passes": [...] }`, which is sensible for batch mode but not the single-object schema in §3.6. |
| §4 pipeline protocol | CONFORMANT for implemented paths | bpfopt/bpfverify/bpfget/bpfrejit keep bytecode on stdin/stdout and side inputs in files. Errors go to stderr. `bpfprof` schema/error behavior is the main protocol deviation. |
| §5 pass list/default order | DEVIATION | `PASS_REGISTRY` has all 12 passes in v3 order (`bpfopt/crates/bpfopt/src/passes/mod.rs:52-119`). `list-passes` exposes 12 CLI names. `bpfopt optimize` and `scripts/per-pass-verify.sh` default to only 4 passes. |
| §6 repo structure/dependencies | DEVIATION but documented transition | `bpfopt-core` has been merged into `bpfopt`. `bpfopt` depends on `kernel-sys` (`bpfopt/crates/bpfopt/Cargo.toml:11-17`) despite the library doc saying "Zero kernel dependency" (`bpfopt/crates/bpfopt/src/lib.rs:1-6`). Local rules now allow this for data APIs/constants, provided bpfopt does not invoke syscalls. |
| §7 daemon migration | GAP / in-flight | Reviewed CLI crates contain migrated pieces: passes/analysis in bpfopt, verifier-log parser in bpfverify, syscall wrappers in kernel-sys, profile CLI in bpfprof. Remaining daemon/runner boundary is not migrated; daemon build is currently broken. |
| §11 exclusions/libbpf-rs deviation | CONFORMANT with local rules | `kernel-sys` uses libbpf-rs/libbpf-sys for standard commands and `libc::syscall` only for fork-only REJIT. The CLAUDE rule supersedes v3's early "no direct libbpf linking" exclusion. |

## Architecture issues

### HIGH: `bpfopt optimize` default pipeline is not the v3 default

Location: `bpfopt/crates/bpfopt/src/main.rs:26-46`, `:462-480`; `scripts/per-pass-verify.sh:32`.

Impact: `bpfopt list-passes` and `PASS_REGISTRY` show the correct 12-pass order, but `bpfopt optimize` silently runs only 4 zero-side-input passes. This makes the default CLI behavior materially different from v3 §5 and can hide pass regressions in pipeline-level tests.

Recommendation: either make default `optimize` use the 12-pass v3 order and fail fast when required side inputs are missing, or explicitly amend the design to define a "zero-side-input default" and require callers to pass the full list. If retaining a safe subset, rename/report it as a preset, not the v3 default.

### HIGH: `bpfprof` does not produce v3 branch profile data

Location: `bpfopt/crates/bpfprof/src/main.rs:60-70`, `:210-223`, `:377-384`, `:409-412`.

Impact: v3 expects `branch_miss_rate`, `branch_misses`, and `branch_instructions` in `profile.json`. Current code only checks whether PMU counters can open, discards the actual counts, and emits branch fields as `null` for every program. `branch-flip` therefore cannot receive useful v3 PGO output from `bpfprof`.

Recommendation: either implement real program-attributed branch counters or narrow v3/bpfprof to run-counter-only profiles. Remove `pmu_available`; if PMU is required for a requested field and unavailable, return an error or omit optional fields according to the schema, not an informational metadata flag.

### HIGH: `bpfget --target` cannot generate usable kinsn target descriptors

Location: `bpfopt/crates/bpfget/src/main.rs:273-284`.

Impact: kinsn passes (`rotate`, `cond-select`, `extract`, `endian`, `bulk-memory`) require target kinsn BTF IDs. The current producer emits an empty `kinsns` object unless users hand-write `--kinsns name:btf_func_id`, so the toolchain cannot produce a self-contained `target.json`.

Recommendation: implement target probing or add a separate generator that discovers loaded kinsn module BTF IDs and writes v3 `target.json`. Until then, document that kinsn pass integration is manual and not Phase 4 ready.

### HIGH: `bpfget --full` does not produce map-values side input for `map-inline`

Location: `bpfopt/crates/bpfget/src/main.rs:211-230`; consumer requirement at `bpfopt/crates/bpfopt/src/main.rs:574-575`.

Impact: v3 says `bpfget --full` prepares bytecode, metadata, and side inputs. Current `--full` writes map metadata/bindings only; it does not snapshot map lookup keys/values. That leaves `map-inline` unusable in a fully generated CLI pipeline unless an external component creates `map-values.json`.

Recommendation: define ownership for map snapshot generation. Either extend `bpfget --full` to emit `map_values.json` for the keys the optimizer can discover, or split this into a named tool/step and update v3 accordingly.

### MEDIUM: `bpfopt`'s kernel-sys dependency is allowed by local rules but contradicts in-code docs and v3 §6 text

Location: `bpfopt/crates/bpfopt/Cargo.toml:11-17`; `bpfopt/crates/bpfopt/src/lib.rs:1-6`.

Impact: The actual dependency graph is clean for syscall boundaries, but confusing for reviewers: `bpfopt` now links `kernel-sys` for ABI types/constants. This is intentionally allowed by the local rule, but the library still claims zero kernel dependency and v3 §6 says bpfopt does not depend on kernel-sys.

Recommendation: update non-authoritative implementation docs/comments after the design owner confirms the intended wording. Keep syscall grep in CI to preserve the important boundary.

### MEDIUM: `kernel-sys::prog_get_original` does not wrap a named `BPF_PROG_GET_ORIGINAL` command

Location: `bpfopt/crates/kernel-sys/src/lib.rs:454-477`; rules in `CLAUDE.md:60-68`; v3 §2.4.

Impact: `bpfget` uses `kernel_sys::prog_get_original`, but that helper reads fork-extended `bpf_prog_info.orig_prog_*` through `BPF_OBJ_GET_INFO_BY_FD`, not a custom `BPF_PROG_GET_ORIGINAL` syscall command. This may be correct for the current fork, but it conflicts with the stated syscall-boundary wording.

Recommendation: decide whether the fork contract is "orig_prog fields on GET_INFO" or a true `BPF_PROG_GET_ORIGINAL` command. Then align the helper name, constants, tests, and docs. If a true command exists, add the wrapper in `kernel-sys`.

### MEDIUM: Docker image still builds daemon and CLI in one upper Rust layer

Location: `runner/containers/runner-runtime.Dockerfile:347-364`; `runner/mk/build.mk:116-120`, `:278-280`.

Impact: The Dockerfile correctly puts Rust after kernel/runner artifacts and before Python. But it copies/builds `bpfopt` and `daemon` in the same layer. During daemon refactors, any daemon source churn rebuilds the layer that also installs CLIs, even if bpfopt-suite did not change.

Recommendation: after daemon slims, split CLI and daemon layers or remove daemon from the benchmark runtime path if runner moves to direct CLI. Keep Python/YAML in the final runtime layer; current `RUNNER_RUNTIME_IMAGE_SOURCE_FILES` correctly excludes runtime Python/YAML from compile inputs.

### LOW: `scripts/per-pass-verify.sh` is useful but not installed into runner runtime

Location: script at `scripts/per-pass-verify.sh`; Docker CLI install at `runner/containers/runner-runtime.Dockerfile:358-364`.

Impact: The Phase 4 helper script exists and supports dry-run, side-input env vars, and per-pass rollback. The runtime image installs the five CLI binaries but not this script, so VM users cannot rely on it unless another copy path exists.

Recommendation: if this script is intended as a supported Phase 4 artifact, copy it to `/usr/local/bin` or `/opt/bpf-benchmark/scripts` in the runtime image and add it to the relevant make input list.

### LOW: rustdoc warnings should be cleaned up

Location: `bpfopt/crates/bpfopt/src/insn.rs:419-421`; `bpfopt/crates/bpfopt/src/pass.rs:371-376`.

Impact: `cargo doc --no-deps` succeeds but warns because `[3:0]`, `[19:4]`, `[51:20]`, and `addr_map[old_pc]` are parsed as intra-doc links.

Recommendation: escape the brackets or wrap the bit ranges/index expression in backticks.

## Dead code cleanup list

1. `kernel_sys::prog_load_dryrun` appears to be a legacy wrapper. It is only used by `prog_load_dryrun_with_fd_array` internally (`bpfopt/crates/kernel-sys/src/lib.rs:176-196`); reviewed CLIs call `prog_load_dryrun_report` or `prog_load_dryrun_with_fd_array` directly. Prefer removing it or marking it test-only if no external caller exists.

2. `kernel_sys::map_get_next_id` is public but unused by reviewed CLIs (`bpfopt/crates/kernel-sys/src/lib.rs:369-380`). Keep only if the slim daemon will consume it soon; otherwise remove until needed.

3. `#[allow(dead_code)]` helpers in `BpfInsn` are production-visible test conveniences: `stx_mem`, `alu64_imm`, `alu64_reg` (`bpfopt/crates/bpfopt/src/insn.rs:431-445`). They are heavily useful in tests but not in production code. Consider `#[cfg(test)]` test builders or move fixture constructors to test utilities.

4. `BpfProgram::has_transforms`, `PassManager::pass_count`, and `PassManager::pass_names` have `#[allow(dead_code)]` (`bpfopt/crates/bpfopt/src/pass.rs:426-429`, `:929-938`). `pass_names` is still used by tests and daemon in-flight code, but after daemon migration it should either be test-only or kept as a real diagnostic API without `allow(dead_code)`.

5. `bpfverify/src/verifier_log.rs` still has a top-level comment saying it is used by `bpf_prog_rejit()` in the serve optimize flow. The module now belongs to the verifier CLI; update the comment when touching that file.

6. `bpfopt` no longer has a `verifier_log` module, and reviewed `bpfopt` references only verifier-state data structs used by `const_prop` and `map_inline`. No dead `bpfopt::verifier_log` code remains in the scoped crate.

7. All 12 pass modules are registered in `PASS_REGISTRY`; I did not find an unregistered pass implementation in the reviewed scope.

8. No large commented-out code blocks, `TODO`, `FIXME`, or `HACK` markers were found in the reviewed scope.

## Test quality issues

1. The current `optimize_default_pipeline_writes_json_report_array` test encodes the 4-pass default (`bpfopt/crates/bpfopt/tests/cli_pipeline.rs:112-139`). That test is useful as a regression test for today's behavior, but it protects a v3 deviation. When fixing the default pipeline, update this test to assert the v3 12-pass order or the explicitly chosen preset.

2. `bpfprof` tests assert the non-v3 profile behavior: `pmu_available` exists and branch fields are null (`bpfopt/crates/bpfprof/tests/cli.rs:34-59`; unit tests in `bpfopt/crates/bpfprof/src/main.rs:502-595`). These tests should be replaced with schema/behavior tests that catch real PMU/profile regressions after the schema is corrected.

3. `bpfget::prog_info_json_schema_round_trips_requested_fields` includes a round-trip self-equality assertion, but it also checks concrete JSON field names and values. Keep the schema checks; the round-trip equality alone would not satisfy the unit-test quality guideline.

4. ABI/layout tests in `kernel-sys` and `bpfopt::insn` are good quality: they verify field offsets and raw encoding, not just `size_of`.

5. CLI integration coverage is meaningful for stdin/stdout bytecode, missing side inputs, invalid bytecode alignment, verifier report/states output, fd_array parsing, and kernel-permission-tolerant live tests. Missing coverage remains for full v3 multi-tool pipeline with generated `target.json`, `map-values.json`, and profile data.

## Summary and Phase 4 readiness

The scoped CLI crates are in a much better state than the daemon: they build, test, expose the five expected binaries, keep direct BPF syscalls inside `kernel-sys`, and avoid CLI-to-CLI compile-time dependencies. The pass registry is complete, raw bytecode protocol is mostly implemented, and Docker/build.mk track the CLI source files correctly.

Not ready for Phase 4 yet. Must-fix items before Phase 4:

1. Align `bpfopt optimize` default behavior with v3 §5 or explicitly change the design.
2. Make `bpfprof` produce conformant profile data or narrow/remove branch PMU schema fields.
3. Implement usable kinsn target discovery for `target.json`.
4. Define and implement the map-values producer path for `map-inline`.
5. Finish daemon/runner migration enough that `bpfrejit-daemon` builds and the benchmark runner no longer depends on legacy socket optimize/profile behavior.
6. Resolve the `BPF_PROG_GET_ORIGINAL` contract mismatch between rules/design and `kernel-sys`.

The lower-priority cleanup is straightforward: remove or gate stale dead-code helpers, clean rustdoc links, and update tests that currently lock in known v3 deviations.
