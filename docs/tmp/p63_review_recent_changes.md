# P63 Review: Recent Changes

## Scope

Reviewed commits:

- `24f4a623` as the current P56 state. At review start P56 appeared staged/uncommitted, but the tree later became clean with `24f4a623` at `HEAD`/`origin/main`.
- `f3f95cbe` KVM bench CPU default `12 -> 16`.
- `4700ad38` daemon cross-program rayon parallelism and KVM defaults.
- `d065c46c` daemon failure workdir export.

Per instruction, I did not modify source code and did not rerun `cargo build`, `cargo clippy`, or `cargo test`.

## Findings

1. ❌ `bpfget` can still emit incomplete load metadata instead of failing fast.
   - `bpfopt/crates/bpfget/src/main.rs:172` and `:284` call `expected_attach_type_json`, then serialize `ProgInfoJson` without validating required metadata.
   - `bpfopt/crates/bpfget/src/main.rs:262` returns `Ok(None)` when no expected attach type is recovered.
   - `bpfopt/crates/bpfget/src/main.rs:254` / `:256` serialize zero `btf_id` / `attach_btf_id` as normal values.
   - Impact: `bpfget --info` / `--full` can exit 0 with metadata that `bpfverify` later rejects. P56's goal was metadata replay; the producer should fail at the point the metadata is known missing.
   - Fix: add a `bpfget` validation step equivalent to `bpfverify`'s required metadata check before writing `prog_info.json`; for required types, zero/missing `btf_id`, `attach_btf_id`, or `expected_attach_type` must be an error.

2. ❌ `bpfrejit --dry-run` does not replay `prog_btf_fd`.
   - `bpfopt/crates/bpfrejit/src/main.rs:131` builds `ProgLoadDryRunOptions`, but `:134` hard-codes `prog_btf_fd: None`.
   - Impact: dry-run `BPF_PROG_LOAD` is not equivalent to the original load for BTF-bearing kprobe/tracing/LSM/ext programs.
   - Fix: when `info.btf_id != 0`, open it with `kernel_sys::btf_get_fd_by_id`, keep the `OwnedFd` alive, and pass `Some(fd.as_raw_fd())`.

3. ❌ `bpfverify --report` exits 0 for verifier rejection.
   - `bpfopt/crates/bpfverify/src/main.rs:244` returns success when `--report` is present and `--verifier-states-out` is absent, even if `dryrun.accepted == false`.
   - This was pre-existing before the reviewed commits, but it is still active and P57 relies on compensating logic in `daemon/src/commands.rs:1596`.
   - Design says verifier failure should exit 1 while still producing the report file. Fix `bpfverify` exit semantics and update daemon's post-failure capture path to read the report after a nonzero exit where appropriate.

4. ❌ `kernel-sys` still exposes an unused public verifier wrapper.
   - `bpfopt/crates/kernel-sys/src/lib.rs:188` defines `pub fn prog_load_dryrun_with_fd_array`.
   - Repo grep found no callers except its own call into `prog_load_dryrun_report`.
   - This was pre-existing, but it violates the no-unused-public-API rule. Fix by deleting it or making a real caller use it.

5. ⚠️ `expected_attach_type_for_prog` conflict handling is good, but unsupported matching links are ignored.
   - Conflicting mapped attach types fail fast at `bpfopt/crates/kernel-sys/src/lib.rs:424`.
   - A matching program link with an unmapped link type is skipped at `bpfopt/crates/kernel-sys/src/lib.rs:421`.
   - Recommendation: for program types where expected attach type is required, treat an unsupported matching link type as an error instead of returning `None`.

## Checklist

### A. Design Principles

- ✅ kernel-sys remains the only direct `SYS_bpf` entry for bpfopt-suite Rust code. Scoped grep found no direct `libc::syscall(SYS_bpf, ...)` in CLI crates or daemon; direct `sys_bpf` use is in `kernel-sys` for `BPF_PROG_REJIT`.
- ✅ CLI crates do not path-depend on each other. `daemon/Cargo.toml` and the six CLI crates depend on `kernel-sys`, not on `bpfopt`/`bpfverify`/`bpfprof`/`bpfget`/`bpfrejit`.
- ✅ Benchmark framework code was not refactored. Reviewed changes touch `runner/targets/x86-kvm.env`, `runner/containers/runner-runtime.Dockerfile`, `e2e/results/**`, and `tests/results/**`; not `runner/libs/`, `corpus/`, `e2e/cases/`, or `micro/driver.py`.
- ✅ `kernel-sys` uses libbpf/libbpf-sys for standard BPF commands. No new hand-written standard BPF syscall wrapper was introduced; `BPF_PROG_REJIT` remains the fork-only direct syscall.
- ✅ The daemon remains a socket-to-CLI adapter. No internal `PassManager`, pass implementation, verifier log parser, bytecode transform, or in-process profiler was reintroduced.

### B. Fail-Fast Rules

- ❌ Dead code/public API: `kernel-sys::prog_load_dryrun_with_fd_array` is public and unused (`bpfopt/crates/kernel-sys/src/lib.rs:188`).
- ❌ Fallback/incomplete capability: `bpfget` can output incomplete attach metadata instead of failing (`bpfopt/crates/bpfget/src/main.rs:262`), and `bpfverify --report` exits 0 on verifier reject (`bpfopt/crates/bpfverify/src/main.rs:244`).
- ✅ No new production `.ok()`, `let _ = result`, or empty `if let Err(_)` swallowing patterns found in reviewed Rust code.
- ✅ No new production `panic!` / `unreachable!` requiring justification found. Existing test panics are test assertions.

### C. Unit Test Quality

- ✅ New meaningful tests cover verifier-state invalidation after transforms, fd-array slot/call-offset contracts, failure artifact export, and ABI field offsets.
- ⚠️ Minor: `panic_payload_message_*` tests in `daemon/src/server.rs:943` are shallow formatting tests. They are not harmful, but they have lower bug-detection value than the failure-path and concurrency tests.
- ✅ ABI/layout tests verify field offsets, not just `size_of` (`bpfopt/crates/kernel-sys/src/lib.rs:695` and `:713`).

### D. Rayon Concurrency

- ✅ `reoptimization_state` is `Arc<Mutex<ReoptimizationState>>`; all reads/writes go through lock helpers (`daemon/src/server.rs:146`, `:152`, `:166`).
- ✅ `applied` is `AtomicU32` and uses `Relaxed` only as a post-join counter (`daemon/src/server.rs:580`, `:613`, `:659`). No ordering dependency exists beyond the rayon join.
- ✅ Failure collection uses `Mutex<Vec<(u32, String)>>` in both invalidation and `optimize-all` (`daemon/src/server.rs:46`, `:581`).
- ✅ `try_for_each` is fail-fast. It aborts after the first returned error while preserving any failures already pushed by concurrently running jobs. This matches the P61 doc's bounded fail-fast design; it does not promise all failures.
- ⚠️ `BPFREJIT_DAEMON_JOBS`: `0` is rejected and negative values fail `usize` parsing (`daemon/src/main.rs:35`). Very large positive values are passed to rayon and rely on thread-pool initialization failure; consider a friendly upper bound if operator error is likely.

### E. P56 Attach Metadata Replay

- ❌ Missing metadata is not uniformly exit 1. `bpfverify` validates required flags (`bpfopt/crates/bpfverify/src/main.rs:791`), but `bpfget --info/--full` can emit incomplete JSON with exit 0.
- ⚠️ Required-type lists are explicit but should be reconciled with link recovery:
  - prog BTF required: kprobe, tracing, lsm, ext (`bpfopt/crates/bpfverify/src/main.rs:825`).
  - attach BTF required: tracing, lsm, struct_ops, ext (`bpfopt/crates/bpfverify/src/main.rs:835`).
  - expected attach type required: tracing, lsm (`bpfopt/crates/bpfverify/src/main.rs:845`).
  - The link mapper can recover kprobe-multi/uprobe-multi expected attach types, but validation does not require them for kprobe. Confirm whether this should be fail-fast before kernel rejection.
- ❌ `PROG_LOAD` attrs are not complete in all paths. `bpfverify` fills expected attach, prog BTF fd, attach BTF id, and attach BTF object fd when provided (`bpfopt/crates/bpfverify/src/main.rs:198`); `bpfrejit --dry-run` omits prog BTF (`bpfopt/crates/bpfrejit/src/main.rs:134`).
- ✅ Multiple-link conflict handling is fail-fast for conflicting mapped attach types (`bpfopt/crates/kernel-sys/src/lib.rs:424`).

### F. P57 Failure Workdir Export

- ✅ Docker entrypoint does not overwrite user-provided `BPFREJIT_DAEMON_FAILURE_ROOT`; it only sets the root when it is unset (`runner/containers/runner-runtime.Dockerfile:520`).
- ✅ `active-run-details` scans `metadata.json` with `status == "running"` and requires exactly one active run (`daemon/src/commands.rs:212`). `launcher_pid` is optional: if present it must match parent pid, otherwise the run is accepted only if it is the sole active candidate (`daemon/src/commands.rs:292`).
- ✅ Failure path matches the requested contract: `<run_dir>/details/failures/<prog_id>/...` (`daemon/src/commands.rs:235`, `:314`).
- ✅ Failure root validation uses create/write/remove probes at daemon startup and export time (`daemon/src/commands.rs:184`, `:188`). Probe names include pid plus an atomic counter; no intentional residue path remains.

### G. Clippy / Build / Test

- ⚠️ `cargo clippy --all-targets -- -D warnings`: not rerun per instruction.
- ⚠️ `cargo build --all-targets`: not rerun per instruction.
- ⚠️ `cargo test --all-targets`: not rerun per instruction.

The reviewed docs for P57/P61 claim narrower daemon build/clippy/test checks were run, but this review did not independently verify them.

## Must Fix Immediately

1. Fix `bpfget --info/--full` to fail when required load metadata is missing.
2. Fix `bpfrejit --dry-run` to replay `prog_btf_fd`.
3. Fix `bpfverify --report` exit semantics and update daemon report-capture handling.
4. Remove the unused public `kernel-sys::prog_load_dryrun_with_fd_array` wrapper.
