# bpfopt Merge Review - 2026-04-28

Review target: `git diff 7d34960ee556^..7d34960ee556`

Scope checked:
- Full target commit diff.
- Current `bpfopt/crates/bpfopt/Cargo.toml` and directory structure.
- `daemon/Cargo.toml`, `daemon/src/main.rs`, and `daemon/src/pipeline.rs`.
- `runner/mk/build.mk` and `runner/containers/runner-runtime.Dockerfile`.
- `docs/kernel-jit-optimization-plan.md`, especially `bpfopt-core` removal and section 4.6.
- Top-level `CLAUDE.md` rules and `docs/tmp/bpfopt_design_v3.md` as the v3 authority.

## Findings

### HIGH - `bpfrejit-daemon` now depends on the `bpfopt` CLI crate, contradicting the active cross-CLI rule

Location:
- `daemon/Cargo.toml:13`
- `bpfopt/crates/bpfopt/Cargo.toml:7`
- `CLAUDE.md:35`
- `docs/kernel-jit-optimization-plan.md:367`
- `docs/kernel-jit-optimization-plan.md:381`

Description:
The merge intentionally collapses `bpfopt-core` into a single `bpfopt` package with both lib and bin targets, then changes daemon to `bpfopt = { path = "../bpfopt/crates/bpfopt" }`. However, `CLAUDE.md` still says the six bpfopt-suite CLI binary crates must not have compile-time path dependencies on each other, and plan section 4.6 repeats that shared code must not live in the lib portion of a CLI crate for another CLI to import.

The plan doc adds the requested errata at lines 367-369, but line 381 still states the opposite rule. That makes the plan internally inconsistent and leaves the implementation in direct conflict with `CLAUDE.md`.

Recommendation:
Resolve this before Phase 1.2. Either:
- keep a separate shared library crate under a non-`bpfopt-core` name and make both daemon and the CLI depend on it; or
- explicitly update `CLAUDE.md` and plan section 4.6 to allow `bpfopt` as the one dual lib+bin exception, including why daemon may depend on it during the migration.

### MEDIUM - daemon still has pure re-export shell modules instead of direct `bpfopt` imports

Location:
- `daemon/src/main.rs:15`
- `daemon/src/main.rs:18`
- `daemon/src/main.rs:21`
- `daemon/src/main.rs:24`
- `daemon/src/main.rs:27`

Description:
`daemon/src/main.rs` preserves `mod analysis`, `mod insn`, `mod pass`, `mod passes`, and `mod verifier_log` as modules that only `pub use bpfopt::*`. There is no daemon-specific logic in these modules. They keep old `crate::pass`-style paths working, but also hide where code is really coming from and add dead indirection after the merge.

Recommendation:
Delete these shell modules and update daemon modules to import directly from `bpfopt`, for example `use bpfopt::{insn, pass};` or narrower item imports. If keeping compatibility aliases is required temporarily, prefer explicit crate-root `pub(crate) use bpfopt::pass;` style aliases with a TODO and removal target.

### MEDIUM - `bpfopt` still contains live-host CPU detection via `/proc/cpuinfo`

Location:
- `bpfopt/crates/bpfopt/src/pass.rs:721`
- `bpfopt/crates/bpfopt/src/pass.rs:746`
- `bpfopt/crates/bpfopt/src/pass.rs:749`
- `daemon/src/main.rs:60`

Description:
I did not find `libc`, raw BPF syscalls, `ioctl`, or `libbpf` dependencies inside the `bpfopt` crate. `cargo tree -p bpfopt` only shows `anyhow`, `clap`, `goblin`, `serde`, and `serde_json`.

However, `bpfopt::pass::PlatformCapabilities::detect()` still reads `/proc/cpuinfo`. That is not a raw BPF syscall, but it is a live-host dependency inside the supposedly pure bytecode optimizer. v3 and plan section 4.6 describe target/profile/verifier/map data as side-input files such as `--target target.json`, not implicit probing of the current host.

Recommendation:
Move host/platform discovery to daemon, `bpfget`, or a future target-generation CLI, and pass an explicit `PlatformCapabilities`/target JSON into `bpfopt`. Keep `bpfopt` transforms deterministic from bytecode plus file side-inputs.

### LOW - `bpfopt` test fixtures are an absolute symlink into `daemon/tests/fixtures`

Location:
- `bpfopt/crates/bpfopt/tests/fixtures`

Description:
The new crate keeps `tests/fixtures` as an absolute symlink to `/home/yunwei37/workspace/bpf-benchmark/daemon/tests/fixtures`. This was inherited from the old `bpfopt-core` layout, but the merge recreates it under the new crate. It works in the current checkout and Docker default path, but it is brittle for a different checkout path or any build that changes `IMAGE_WORKSPACE`.

Recommendation:
Use a relative symlink such as `../../../../daemon/tests/fixtures`, or copy/move the fixtures into the bpfopt crate if the crate is meant to stand alone.

### LOW - public surface is wider than needed after the merge

Location:
- `bpfopt/crates/bpfopt/src/lib.rs:8`
- `bpfopt/crates/bpfopt/src/lib.rs:13`
- `bpfopt/crates/bpfopt/src/lib.rs:17`
- `bpfopt/crates/bpfopt/src/lib.rs:18`
- `bpfopt/crates/bpfopt/src/lib.rs:21`
- `bpfopt/crates/bpfopt/src/passes/mod.rs:6`
- `bpfopt/crates/bpfopt/src/passes/mod.rs:17`

Description:
The crate exposes broad modules (`analysis`, `elf_parser`, `insn`, `pass`, `passes`, `verifier_log`) and also exposes `passes::bounds_check_merge` and `passes::utils` as public modules while other pass implementation modules are private. This mostly preserves the old internal API, but it is more surface than the daemon and CLI currently need. `rg` found daemon callers using `validate_pass_names`, `available_passes_help`, `build_full_pipeline`, pass types, and the top-level modules, but no external need for `passes::utils` or the `bounds_check_merge` module itself.

Recommendation:
Keep only the intended workspace-internal API public. Make `bounds_check_merge` and `utils` private if callers only need the existing `pub use BoundsCheckMergePass` and registry helpers. Consider documenting the intended public/internal boundary in `lib.rs`.

## Non-Findings

- No relevant `bpfopt-core`, `bpfopt_core`, or `bpfopt core` residuals were found outside `docs/tmp/**`, `target/**`, and `Cargo.lock`.
- `runner/mk/build.mk:70` now points at `bpfopt/crates/bpfopt/src` and the new Cargo manifests. It covers all compile-participating bpfopt source files.
- `runner/containers/runner-runtime.Dockerfile:346` copies `bpfopt` and `runner/containers/runner-runtime.Dockerfile:347` copies `daemon`, so the new daemon path dependency is present in the image layer before `make image-daemon-artifact`.
- `bpfopt/crates/bpfopt/src/main.rs` is a reasonable placeholder: `list-passes` only, no unused imports or dead CLI branches found.
- Existing daemon tests were not lost: `daemon/src/bpf.rs:1771` still includes `bpf_tests.rs`, and `daemon/src/commands.rs:961` still includes `commands_tests.rs`.
- The daemon still runs `PassManager` and per-pass verification in `daemon/src/pipeline.rs`; that remains a known pre-slimming v3 violation, but I did not count it as a merge blocker because this step was scoped to consolidation, not daemon thinning.

## Verification

- `cargo build --workspace` in `bpfopt`: passed.
- `cargo build --workspace` in `daemon`: passed.
- `cargo test --workspace` in `bpfopt`: 415 passed, 0 failed, 0 ignored.
- `cargo test --workspace` in `daemon`: 84 passed, 0 failed, 0 ignored.
- `git diff --check 7d34960ee556^..7d34960ee556`: passed.

The repository root is not a Cargo workspace, so I ran the requested workspace commands in both Rust workspace roots: `bpfopt/` and `daemon/`.

## Phase 1.2 Readiness

Not ready for Phase 1.2 until the HIGH finding is resolved. The code compiles and tests pass, and there are no old-name residuals, but the current lib+bin consolidation conflicts with the active no-cross-CLI rule exactly where Phase 1.2 will add more tool/crate boundaries. The MEDIUM findings should also be addressed soon to keep daemon migration and zero-kernel-dependency semantics clean.
