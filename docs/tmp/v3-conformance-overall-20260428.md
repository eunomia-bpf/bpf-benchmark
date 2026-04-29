# bpfopt-suite v3 Overall Conformance Audit

Date: 2026-04-28

Scope: Phase 1 implementation plus shared daemon state. Phase 2 crates `bpfverify` and `bpfprof`, and the moving `verifier_log.rs`, were intentionally not audited.

Working tree note: the repo was already dirty before this audit, including Phase 2 work. This report only adds this file. `cargo build/test` did trigger an incremental rebuild despite `--frozen --offline`; the temporary `bpfopt/Cargo.lock` side effect was restored.

## Summary

Phase 1 is **CONFORMANT WITH DEVIATION** overall. The implemented Phase 1 CLIs follow the v3 Unix bytecode pipeline model: raw `struct bpf_insn[]` on stdin/stdout, side inputs via files, `kernel-sys` as the syscall boundary for Phase 1 tools, and no public C ABI/library artifact. Deviations are mostly documented implementation decisions in `docs/kernel-jit-optimization-plan.md` and `CLAUDE.md`: merged `bpfopt-core`, `bpfopt` using `kernel-sys` data types, `bpfopt optimize` defaulting to zero-side-input passes, direct libbpf linking through `kernel-sys`, and daemon slimming deferred to Phase 3.

## Section Ratings

### v3 §1 Overview - Tool List

Rating: **CONFORMANT WITH DEVIATION**

The six-tool architecture is present or explicitly staged: `bpfopt`, `bpfget`, and `bpfrejit` are implemented; `bpfverify` and `bpfprof` are Phase 2 in progress and skipped; `bpfrejit-daemon` exists as the top-level `daemon/` binary rather than a `bpfopt/crates/` member. The responsibility split matches the plan (`docs/kernel-jit-optimization-plan.md:370-378`), with daemon slimming still deferred.

### v3 §2.1 bpfopt

Rating: **CONFORMANT WITH DEVIATION**

`bpfopt` implements all 12 top-level pass subcommands, `optimize`, `analyze`, and `list-passes`; global flags cover `--input`, `--output`, `--report`, `--platform`, `--kinsns`, `--target`, `--profile`, `--verifier-states`, `--map-values`, and `--map-ids` (`bpfopt/crates/bpfopt/src/main.rs:107-138`, `:141-177`). Required side inputs and target kinsns are rejected with exit 1 (`:552-607`). Bytecode parsing and writing use 8-byte little-endian records (`:646-667`).

Deviation: `optimize` defaults to the zero-side-input subset `dce, skb-load-bytes, bounds-check-merge, wide-mem`, not the full v3 §5 order (`bpfopt/crates/bpfopt/src/main.rs:41-46`). This matches the implementation-level constraint that default invocations must not require side inputs.

### v3 §2.4 bpfget

Rating: **CONFORMANT WITH DEVIATION**

The CLI surface covers default `PROG_ID` bytecode output, `--info`, `--full --outdir`, `--list`, `--list --json`, and `--target` (`bpfopt/crates/bpfget/src/main.rs:24-51`). It uses `kernel-sys` for live program enumeration, info, original bytecode, and map metadata (`:235-260`, `:387-422`).

Deviation: `--target` currently emits arch/features and accepts manual `--kinsns`, but automatic kinsn BTF probing is explicitly not implemented and emits a warning (`bpfopt/crates/bpfget/src/main.rs:273-284`). The plan records this as TODO (`docs/kernel-jit-optimization-plan.md:413`, `:424`).

### v3 §2.5 bpfrejit

Rating: **CONFORMANT**

`bpfrejit` supports positional `PROG_ID [FILE]`, stdin input, `--fd-array`, and `--dry-run` (`bpfopt/crates/bpfrejit/src/main.rs:17-33`). Dry-run calls `kernel_sys::prog_load_dryrun_with_fd_array`; normal mode calls `kernel_sys::prog_rejit`; summaries go to stderr (`:65-106`). Bytecode parsing enforces non-empty 8-byte instruction alignment (`:138-164`).

### v3 §3 Data Formats

Rating: **CONFORMANT WITH DEVIATION**

`bytecode`: conformant. `bpfopt`, `bpfget`, and `bpfrejit` encode/decode raw 8-byte little-endian `struct bpf_insn[]`.

`target.json`: conformant for `bpfopt --target` input and simplified `bpfget --target` output; automatic kinsn probing is pending as above.

`map-values.json`: conformant for `bpfopt --map-values`; implementation accepts v3 fields and an additional `frozen` default.

`profile.json`: Phase 2 `bpfprof` output skipped. `bpfopt --profile` input for branch data is implemented.

`verifier-states.json`: Phase 2 `bpfverify` output skipped. `bpfopt --verifier-states` input uses plain serde JSON and maps `pc/regs/const_val/min/max/tnum` into pass state.

`pass-report.json`: single-pass `--report` matches v3 fields (`bpfopt/crates/bpfopt/src/main.rs:1074-1094`). `optimize --report` wraps per-pass reports in `{ "passes": [...] }`, an implementation extension.

### v3 §4 Pipeline Protocol

Rating: **CONFORMANT WITH DEVIATION**

The basic protocol is implemented for Phase 1 CLIs: bytecode on stdin/stdout, side inputs through files, stderr for diagnostics, and exit 1 on malformed bytecode or missing side input. Dry-run checks confirmed `bpfopt list-passes` emits 12 v3 names, `wide-mem` and `optimize --passes wide-mem,dce` preserve a minimal 16-byte program, and reports remain side files.

Deviation: full live examples containing `bpfverify` are Phase 2 pending. The plan still lists `bpfget | bpfopt | bpfrejit` live minimal pipeline validation as pending (`docs/kernel-jit-optimization-plan.md:415`).

### v3 §4.3 Per-Pass Verify Script

Rating: **GAP**

The loop structure is in bash and matches the high-level accept/rollback protocol: `bpfget`, per-pass `bpfopt`, `diff`, `bpfverify`, `cp`, final `bpfrejit` (`scripts/per-pass-verify.sh:137-163`). However, the default pass list is the full v3 §5 list (`:23`) while the script has no side-input plumbing for `--target`, `--profile`, `--verifier-states`, `--map-values`, or `--map-ids`; it invokes `bpfopt "$pass"` with no pass-specific flags (`:99-103`, `:141-143`). In real execution, side-input-required passes will fail and roll back rather than run the intended v3 examples.

### v3 §5 Pass List

Rating: **CONFORMANT WITH DEVIATION**

The 12 pass subcommand names match v3: `map-inline`, `const-prop`, `dce`, `skb-load-bytes`, `bounds-check-merge`, `wide-mem`, `bulk-memory`, `rotate`, `cond-select`, `extract`, `endian`, `branch-flip` (`bpfopt/crates/bpfopt/src/main.rs:26-39`). Default `optimize` order intentionally differs as noted in §2.1.

### v3 §6 Repository Structure

Rating: **CONFORMANT WITH DEVIATION**

`bpfopt/crates/` contains `kernel-sys`, `bpfopt`, `bpfget`, `bpfrejit`, plus Phase 2 `bpfverify`/`bpfprof` work. The original `bpfopt-core` split is intentionally collapsed into a single `bpfopt` lib+bin crate (`docs/kernel-jit-optimization-plan.md:368`, `:409`). `daemon/` remains top-level, not under `bpfopt/crates/`.

### v3 §7 Migration Mapping

Rating: **PHASE_PENDING**

Daemon still contains the pre-slim pipeline surface: `daemon/src/commands.rs` builds and runs `bpfopt::passes::build_full_pipeline()`, `daemon/src/pipeline.rs` wraps `PassManager`, `daemon/src/profiler.rs` remains active, and `daemon/Cargo.toml` depends on `bpfopt`. This is not counted as a Phase 1 gap because the plan records the daemon dependency as a transition exception until Task #45 / Phase 3 (`docs/kernel-jit-optimization-plan.md:384`, `:426-429`; `CLAUDE.md:47`).

### v3 §8 Daemon Slimming

Rating: **PHASE_PENDING**

Not audited as implementation conformance. Phase 3 has not started.

### v3 §9 Typical Usage Scenarios

Rating: **CONFORMANT WITH DEVIATION**

Scenarios that require only Phase 1 CLIs are supported by CLI shape: single pass optimization, precompiled replacement via `bpfrejit`, and offline `bpfopt analyze`. Scenarios requiring `bpfverify` or `bpfprof` are Phase 2 pending. Daemon automatic optimization and benchmark-runner direct CLI migration are Phase 3 pending. The per-pass script dry-run prints the expected command skeleton, but has the side-input gap described in §4.3.

### v3 §10 Implementation Priority

Rating: **CONFORMANT WITH DEVIATION**

Phase 1 items are implemented beyond the minimum: `bpfopt` has all 12 passes, not just `wide-mem`; `kernel-sys`, `bpfget`, and `bpfrejit` exist; per-pass verify bash was completed early (`docs/kernel-jit-optimization-plan.md:407-416`). Residual issue: live minimal pipeline validation remains pending (`:415`). Phase 2 is in progress and excluded from this audit.

### v3 §11 Explicit Exclusions

Rating: **CONFORMANT WITH DEVIATION**

No public C FFI, `.a`, `.so`, public Rust API publishing, `ValidationOracle`, `KinsnRequirement`, custom pipe framing, or binary headers were introduced in audited Phase 1 code. Direct libbpf linking is allowed by the newer CLAUDE/plan rule (`CLAUDE.md:49-55`, `docs/kernel-jit-optimization-plan.md:386-392`). The daemon still has internal `PassManager`, pass pipeline, profiler, and direct syscall code; this is Phase 3 pending, not a Phase 1 conformance failure.

## GAPs

1. **MEDIUM - `scripts/per-pass-verify.sh` cannot run its default full pass list as a real v3 pipeline.** It defaults to all side-input and zero-side-input passes, but invokes each pass without the side-input flags required by `bpfopt`. Result: side-input passes fail and roll back rather than being verified. Files: `scripts/per-pass-verify.sh:23`, `:99-103`, `:141-143`; `bpfopt/crates/bpfopt/src/main.rs:552-607`.

2. **LOW - Phase 1 live minimal pipeline validation is still pending.** Package tests and dry-runs pass, but the plan still records `bpfget | bpfopt | bpfrejit` as not yet run. Reference: `docs/kernel-jit-optimization-plan.md:415`.

## Documented Deviations

1. `bpfopt-core` is merged into the single `bpfopt` crate. References: `docs/kernel-jit-optimization-plan.md:368`, `:409`.

2. `bpfopt` may depend on `kernel-sys` for pure data APIs, while still not invoking syscalls directly. References: `CLAUDE.md:57-62`, `docs/kernel-jit-optimization-plan.md:390-392`.

3. `bpfopt optimize` default is the zero-side-input subset, not all 12 v3 §5 passes. Reference: `bpfopt/crates/bpfopt/src/main.rs:41-46`.

4. `bpfget --target` kinsn BTF probing is simplified/TODO; manual `--kinsns` is available. References: `bpfopt/crates/bpfget/src/main.rs:273-284`, `docs/kernel-jit-optimization-plan.md:413`, `:424`.

5. `bpfrejit-daemon` remains top-level `daemon/` and temporarily depends on `bpfopt` while retaining pipeline/profiler code. References: `docs/kernel-jit-optimization-plan.md:384`, `:426-429`, `CLAUDE.md:47`.

6. v3's early libbpf-direct-linking exclusion is superseded; `kernel-sys` uses libbpf-rs/libbpf-sys for standard commands and raw syscall only for fork-only commands. References: `CLAUDE.md:49-55`, `docs/kernel-jit-optimization-plan.md:388-392`, `bpfopt/crates/kernel-sys/src/lib.rs:1-5`.

7. `optimize --report` emits an aggregate `{ "passes": [...] }` wrapper instead of a single pass-report object. Single-pass reports match v3 exactly.

## Verification

Commands run:

- `cargo build --frozen --offline -p kernel-sys -p bpfopt -p bpfget -p bpfrejit` - passed, but cargo rebuilt the packages instead of only reading existing target artifacts.
- `cargo test --frozen --offline -p kernel-sys -p bpfopt -p bpfget -p bpfrejit` - passed: 422 tests, 0 failed.
- CLI dry-runs: `bpfopt list-passes`, `bpfopt list-passes --json`, `bpfopt wide-mem --report`, `bpfopt optimize --passes wide-mem,dce --report`, `bpfopt analyze`, `bpfget --target`, and `BPFOPT_DRY_RUN=1 scripts/per-pass-verify.sh 123 xdp`.

## Conclusion

Phase 1 overall rating: **CONFORMANT WITH DEVIATION**.

The Phase 1 CLI/tool boundary matches v3's Unix pipeline architecture and passes package tests. The remaining Phase 1-level fixes are operational rather than architectural: add side-input plumbing or a zero-side-input default to `scripts/per-pass-verify.sh`, and run/record the live `bpfget | bpfopt | bpfrejit` minimal pipeline. Phase 2 and Phase 3 conformance should be re-audited after `bpfverify`/`bpfprof` stabilize and daemon slimming lands.
