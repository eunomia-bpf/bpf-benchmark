# P76 Review: P64+P66, P71, P75

Date: 2026-04-29

Scope:

- `f5235b19` `refactor(bpfopt-suite): P63 critical fixes + remove dead code + audit tests`
- `8809c766` `refactor(bpfopt): DI map provider + audit tests + remove trivial`
- `0bdcac52` `perf(docker): split kernel-fork into independent image tag`
- `1b85ad59` / `c6a02bf8` are docs-only review commits and were not source-reviewed.

Method: read-only source audit with `git show HEAD:path`, `git grep`, and commit diffs. I did not run cargo, Docker, KVM, or AWS. The active worktree has unrelated modified source files from parallel work, so all source line references below are from committed `HEAD`/the named commits, not from the dirty worktree.

## Summary

P64/P66 fixes are real: the P63 criticals for `bpfget`, `bpfrejit --dry-run`, `bpfverify --report`, and the unused `kernel-sys` dry-run wrapper are fixed in committed code.

P71 DI cleanup is also real: production `SnapshotMapProvider` no longer has implicit `cfg(test)` mock fallback, and tests explicitly install `MockMapProvider`. The test deletion looks mostly like duplicate/trivial coverage removal, not meaningful coverage loss.

P75 kernel image split is structurally correct for the vendor kernel: `kernel-fork.Dockerfile` has the needed kernel deps, arm64 kernel builds on `linux/amd64` with `gcc-aarch64-linux-gnu`, kinsn modules build from exported headers, and ordinary runtime image builds automatically depend on the kernel-fork image tar. There is one caveat: non-kernel arm64 image targets still use `--platform linux/arm64`, so P75 removed qemu pressure from the kernel build, not from the entire arm64 image pipeline.

None of the five P74 critical architecture findings were fixed by these commits.

## A. P64+P66 Fail-Fast Fixes

| Item | Status | Evidence | Notes |
| --- | --- | --- | --- |
| `bpfget --info/--full` exits 1 when required metadata is missing | ✅ | `bpfopt/crates/bpfget/src/main.rs:171`, `:173`, `:174`, `:257`, `:262` | `--info` and `--full` both construct `ProgInfoJson::from_info(...)`; `validate_required_load_metadata()` bails for missing `btf_id`, `attach_btf_id`, or `expected_attach_type`. |
| Required prog BTF metadata covers kprobe/tracing/lsm/ext | ✅ | `bpfopt/crates/bpfget/src/main.rs:288` | `prog_type_requires_prog_btf()` matches `KPROBE`, `TRACING`, `LSM`, `EXT`. |
| Required attach BTF metadata covers tracing/lsm/struct_ops/ext | ✅ | `bpfopt/crates/bpfget/src/main.rs:298` | `attach_btf_id == 0` now fails before JSON write. |
| Required expected attach type covers tracing/lsm | ✅ | `bpfopt/crates/bpfget/src/main.rs:308` | Unsupported matching links for required types also fail in `kernel-sys`: `bpfopt/crates/kernel-sys/src/lib.rs:380`. |
| `bpfrejit --dry-run` keeps `prog_btf_fd` alive through syscall | ✅ | `bpfopt/crates/bpfrejit/src/main.rs:122`, `:126`, `:139`, `:142` | The `OwnedFd` lives in `prog_btf_fd` until after `prog_load_dryrun_report(...)` returns; the raw fd is passed with `as_ref().map(...)`. |
| `bpfverify --report` writes report but exits 1 on verifier rejection | ✅ | `bpfopt/crates/bpfverify/src/main.rs:214`, `:225`, `:239`, `:244` | Report JSON is written before the success/failure branch; rejected dry-run returns `ExitCode::FAILURE`. |
| daemon report handling reads nonzero `bpfverify --report` output | ✅ | `daemon/src/commands.rs:1590`, `:1596`, `:1600`, `:1623`, `:1633` | `run_bpfverify_report_command()` reads the report even if subprocess status is nonzero, then `run_bpfverify_reported()` propagates verifier failure. |
| `elf_parser.rs` deletion complete | ✅ | `bpfopt/crates/bpfopt/src/lib.rs:8`, `bpfopt/crates/bpfopt/Cargo.toml:11` | `lib.rs` no longer declares `elf_parser`; `goblin` is gone from crate deps. `git grep 'elf_parser\|goblin\|from_elf'` under `bpfopt/crates/bpfopt` has no hits. |
| `test_utils.rs` deletion complete | ✅ | `bpfopt/crates/bpfopt/src/lib.rs:8` | `lib.rs` only exposes `analysis`, test-gated `bpf`/`mock_maps`, `insn`, `pass`, `passes`; `git grep test_utils HEAD -- bpfopt/crates/bpfopt` has no hits. |
| `kernel_sys::prog_load_dryrun_with_fd_array` removed | ✅ | `bpfopt/crates/kernel-sys/src/lib.rs:181` | Only `prog_load_dryrun_report()` remains in that dry-run API area; `git grep prog_load_dryrun_with_fd_array HEAD` has no hits. |
| Remaining tests after deleting 17 trivial tests have value | ✅ | `docs/tmp/p66_consolidation.md:63`, `bpfopt/crates/bpfopt/src/insn.rs:522`, `bpfopt/crates/kernel-sys/src/lib.rs:664`, `bpfopt/crates/bpfopt/tests/cli_pipeline.rs:191` | Retained examples cover ABI offsets/raw encoding, fork UAPI offsets, CLI fail-fast side-input contracts, and pass behavior. I found no obvious replacement with pure getter/std-lib tautology tests in the sampled areas. |
| P66 reported build/clippy/test | ✅ | `docs/tmp/p66_consolidation.md:69` | Self-reported only; not rerun per task constraint. |

## B. P71 DI Refactor

| Item | Status | Evidence | Notes |
| --- | --- | --- | --- |
| `pass.rs` production no longer has implicit `cfg(test)` mock fallback in map provider | ✅ | `bpfopt/crates/bpfopt/src/pass.rs:201`, `:205`, `:228`, `:267` | `SnapshotMapProvider` now errors on missing snapshot metadata/value instead of looking into thread-local mock maps. Remaining `#[cfg(test)]` in `pass.rs` is for test-only helper methods/types, not map fallback. |
| `MockMapProvider` encapsulates mock logic | ✅ | `bpfopt/crates/bpfopt/src/mock_maps.rs:39`, `:42`, `:56`, `:95`, `:103` | `MockMapProvider` implements both map traits and falls back to `SnapshotMapProvider` only after test mock lookup misses. |
| Tests explicitly inject mock provider | ✅ | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:263`, `:272`, `bpfopt/crates/bpfopt/src/passes/mod_tests.rs:85`, `bpfopt/crates/bpfopt/src/passes/const_prop.rs:1086` | Test setup calls `use_mock_maps(...)`; production `BpfProgram::new()` defaults to `SnapshotMapProvider`: `bpfopt/crates/bpfopt/src/pass.rs:332`. |
| `mock_maps.rs` remains test-gated | ✅ | `bpfopt/crates/bpfopt/src/lib.rs:9`, `:14` | Both the compatibility `bpf` module and `mock_maps` module are under `#[cfg(test)]`. |
| `map_inline_tests.rs` 800 LOC removal did not obviously drop unique coverage | ✅ | `bpfopt/crates/bpfopt/src/passes/map_inline_tests.rs:445`, `:516`, `:774`, `:812`, `:1807` | Sampled removals: `extract_constant_key_from_r2_add_reg_constant` was weaker than retained copy-chain/fp-alias/verifier-guided key extraction; alias load rewrite was covered by retained lookup+scalar and fp-alias offset rewrite tests; two per-cpu hash tests were merged into table-driven `map_inline_pass_skips_percpu_hash_family_maps()`. |
| `cli_pipeline.rs` 83/162 LOC removal did not remove e2e smoke coverage | ✅ | `bpfopt/crates/bpfopt/tests/cli_pipeline.rs:191`, `:237`, `:315`, `:348`, `:429` | Removed tests were duplicate CLI report shape or explicit-pass missing-side-input variants. Retained tests still cover default pipeline fail-fast, full 12-pass report, invalid bytecode, map-inline missing/null snapshots, and missing kinsn target failure. This is not the benchmark e2e suite. |
| Missing semantic coverage after deletion | ⚠️ | `docs/tmp/p71_test_mock_audit.md:151`, `:166` | P71 self-report says retained coverage is meaningful and `cargo test` passed. I did not rerun tests. The only residual risk is the normal one from deleting duplicate permutations: fewer exact input-shape regressions, but the sampled stricter cases remain. |

## C. P75 Kernel-Fork Image Split

| Item | Status | Evidence | Notes |
| --- | --- | --- | --- |
| `kernel-fork.Dockerfile` has required kernel build deps | ✅ | `runner/containers/kernel-fork.Dockerfile:12`, `:21`, `:29`, `:30`, `:31`, `:41` | Includes `dwarves`, `libdw-dev`, `libdwarf-dev`, `libelf-dev`, `bc`, `bison`, `flex`, `openssl`, etc.; arm64 installs `gcc-aarch64-linux-gnu`. |
| Kernel artifacts exported with expected content | ✅ | `runner/containers/kernel-fork.Dockerfile:112`, `:121`, `:123`, `:138`, `:144`, `:145`, `:149` | Validates and installs kernel image, `System.map`, `Module.symvers`, `.config`, modules, headers, and manifest under `/artifacts`. |
| `runner-runtime.Dockerfile` consumes kernel-fork image by tag | ✅ | `runner/containers/runner-runtime.Dockerfile:253`, `runner/mk/build.mk:197`, `:212` | Runtime build passes `VENDOR_LINUX_FRAMEWORK_COMMIT` and uses `bpf-benchmark/kernel-fork:${RUN_TARGET_ARCH}-${commit}`. |
| Runtime artifact paths are compatible | ✅ | `runner/containers/runner-runtime.Dockerfile:261`, `:262`, `:263`, `:264` | Runtime copies `/artifacts/kernel`, `/artifacts/modules`, and manifest. Headers are copied to `/usr/src/linux-headers-fork` for the runtime artifact stage; the kinsn stage reads `/artifacts/headers` directly from the kernel-fork image. |
| Kinsn module builds from exported headers, not kernel source | ✅ | `runner/containers/runner-runtime.Dockerfile:371`, `:380`, `:422` | `runner-runtime-kinsn-artifacts` is `FROM runner-runtime-kernel-base` and runs `make -C /artifacts/headers ... M=...`, avoiding vendor kernel rebuild. |
| `image-kernel-fork-image-tar` builds when local image is absent and saves when present | ✅ | `runner/mk/build.mk:141`, `:143`, `:146`, `:152`, `:154`, `:156`, `:159`, `:165`, `:217`, `:218` | This is local inspect-or-build, not registry pull. That matches P75 doc: local tag first, no automatic push/pull. |
| Commit hash integration triggers new image tag when vendor HEAD changes | ✅ | `runner/mk/build.mk:47`, `:51`, `:57`, `:197` | Tags and tar names include `git rev-parse --short HEAD`, so committed vendor HEAD changes produce a new image name and tar path. Same HEAD reuses the existing local tag. |
| Dirty vendor source with same HEAD would not rebuild an existing local tag | ⚠️ | `runner/mk/build.mk:115`, `:141`, `:143` | Make source deps can notice file timestamp changes, but the recipe short-circuits on existing tag. This is acceptable if vendor changes are always committed first; otherwise local dirty kernel edits can be hidden by tag reuse. |
| arm64 kernel-fork build uses cross compiler rather than qemu | ✅ | `runner/containers/kernel-fork.Dockerfile:41`, `:78`, `:81`, `:94`, `runner/mk/build.mk:64`, `:159` | Kernel-fork arm64 builds under `linux/amd64` and uses `CROSS_COMPILE=aarch64-linux-gnu-`. |
| No `qemu-binfmt` and no kernel-fork `--platform linux/arm64` | ✅ | `runner/containers/kernel-fork.Dockerfile:1`, `runner/mk/build.mk:159` | No `qemu-binfmt` hit. Kernel-fork build uses `$(KERNEL_FORK_BUILD_PLATFORM)` default `linux/amd64`. |
| No `--platform linux/arm64` anywhere in Docker/Makefile | ⚠️ | `runner/mk/build.mk:179`, `:206` | Residual `linux/arm64` remains for arm64 Katran artifacts and arm64 runtime image. P75 removes qemu from the vendor kernel build, not from the entire arm64 runtime image build. |
| BuildKit cache mounts remain | ✅ | `runner/containers/kernel-fork.Dockerfile:52`, `runner/containers/runner-runtime.Dockerfile:380`, `:438`, `:464` | Kernel-fork, kinsn, daemon Cargo, and bpfopt Cargo stages all retain cache mounts. |
| AWS runtime image tar path remains usable | ✅ | `runner/mk/build.mk:55`, `:56`, `:187`, `:202`, `runner/libs/workspace_layout.py:74`, `runner/libs/aws_executor.py:202` | Runtime tar path remains `.cache/container-images/{arch}-runner-runtime.image.tar`; AWS executor still requests `image-runner-runtime-image-tar` if missing. |
| Ordinary first runtime build auto-triggers kernel-fork image tar | ✅ | `runner/mk/build.mk:187`, `:202`, `:220` | Both x86 and arm64 runtime tar targets depend on their corresponding kernel-fork image tar; users do not need to manually run `image-kernel-fork-image-tar`. |

## D. Cumulative Cross-Cutting Review

| Item | Status | Evidence | Notes |
| --- | --- | --- | --- |
| daemon/bpfopt-suite responsibility boundary is clearer | ✅ | `bpfopt/crates/bpfopt/src/lib.rs:8`, `bpfopt/crates/bpfopt/Cargo.toml:11`, `daemon/src/commands.rs:1339` | ELF parser/test fixture deletion and DI cleanup push bpfopt toward raw bytecode + explicit side-inputs; daemon still shells out to CLI. |
| New dead public API or cfg-test-only public surface | ⚠️ | `bpfopt/crates/bpfopt/src/lib.rs:9`, `:14`, `bpfopt/crates/bpfopt/src/mock_maps.rs:39`, `bpfopt/crates/bpfopt/src/pass.rs:944` | P71's new `MockMapProvider` is public only inside a test-gated module, which is fine. Existing P74 dead/oversized public APIs remain (`pass_at`, `available_passes_help`, `validate_pass_names`, `build_full_pipeline`, unused `BpfInsn` helpers). |
| `kernel-sys` remains the only direct BPF syscall boundary | ✅ | `bpfopt/crates/kernel-sys/src/lib.rs:170`, `:172` | `git grep 'libc::syscall\|SYS_bpf' HEAD -- bpfopt/crates daemon/src` finds direct syscall only in `kernel-sys`. |
| 6 CLI crates do not path-depend on each other | ✅ | `bpfopt/crates/bpfopt/Cargo.toml:11`, `bpfopt/crates/bpfget/Cargo.toml:11`, `bpfopt/crates/bpfverify/Cargo.toml:11`, `bpfopt/crates/bpfprof/Cargo.toml:11`, `bpfopt/crates/bpfrejit/Cargo.toml:11`, `daemon/Cargo.toml:11` | CLI crates depend on `kernel-sys`, not each other. |
| benchmark framework Python/YAML not changed by reviewed commits | ✅ | `git diff-tree --name-only f5235b19`, `8809c766`, `0bdcac52` | Reviewed commits touched Rust, tests, Dockerfile/Makefile, and docs; not `runner/libs/`, `corpus/`, `e2e/cases/`, or `micro/driver.py`. |
| No AWS instance-size rule regression in reviewed commits | ✅ | `git diff-tree --name-only 0bdcac52` | P75 touched Docker/Makefile only; no `runner/targets/*.env` AWS instance defaults changed. |
| `cargo clippy --all-targets -D warnings` | ✅ | `docs/tmp/p66_consolidation.md:71`, `docs/tmp/p71_test_mock_audit.md:172` | Self-reported by P66/P71. Not rerun per task constraint. |

## E. P74 Criticals After These Commits

| P74 critical | Status | Current evidence | Notes |
| --- | --- | --- | --- |
| 1. daemon bare `optimize` / `optimize-all` incompatible with 12-pass default | ❌ Still open | `daemon/src/commands.rs:1245`, `:1342`; `bpfopt/crates/bpfopt/src/main.rs:623`, `:633`, `:722` | Missing `enabled_passes` still means daemon prepares no side-inputs, then calls bare `bpfopt optimize`, whose default 12-pass path requires side-inputs. |
| 2. `ProgramWatcher` swallows BPF errors | ❌ Still open | `daemon/src/server.rs:228`, `:236`, `:244`, `:252` | Still logs and `break`s instead of returning `Result`/hard failure. |
| 3. `status` silences `bpfopt list-passes` failure | ❌ Still open | `daemon/src/server.rs:745`, `:749`, `:751`, `:753` | Error becomes `"unavailable: ..."` while JSON still says `"status": "ok"`. |
| 4. `disabled_passes` exclusion surface remains | ❌ Still open | `daemon/src/server.rs:448`, `:452`, `:456`; `bpfopt/crates/bpfopt/src/pass.rs:821`, `:1123` | Negative pass filtering still exists in daemon request processing and bpfopt policy. |
| 5. `branch_flip` heuristic fallback remains | ❌ Still open | `bpfopt/crates/bpfopt/src/passes/branch_flip.rs:153`, `:161`, `:163` | Missing per-site branch profile can still flip based on heuristic. |

## Must Fix Immediately

1. ❌ Fix daemon bare `optimize` / `optimize-all` API. Minimum safe patch: reject missing `enabled_passes` before forking `bpfopt` and update README/tests. Full patch: prepare all default 12-pass side-inputs and require profile for `branch-flip`.
2. ❌ Propagate watcher/status failures. `ProgramWatcher::from_live()` / `tick()` should return `Result`; `status` should return error JSON if `bpfopt list-passes` fails.
3. ❌ Remove `disabled_passes` end-to-end from daemon request/result schema and bpfopt `PolicyConfig`.
4. ❌ Remove `branch_flip` per-site heuristic fallback; make missing branch profile a skip/error, not a transform trigger.
5. ⚠️ Decide whether the P75 arm64 goal is "kernel-fork only" or "entire arm64 image pipeline no qemu". If it is the latter, `runner/mk/build.mk:179` and `:206` remain blockers.
6. ⚠️ Continue P74 dead public API cleanup: `pass_at`, pass registry public helpers, unused `BpfInsn` helpers/constants, and daemon over-wide `pub` surface.

## LOC Delta Estimate For Follow-Up

| Fix area | Estimated LOC delta |
| --- | ---: |
| Reject bare daemon `optimize` / `optimize-all` + README/tests | -10 to +40 |
| Full daemon default 12-pass side-input support | +80 to +180 |
| Watcher/status fail-fast | +20 to +60 |
| Remove `disabled_passes` request/result/policy/tests | -70 to -140 |
| Remove `branch_flip` heuristic fallback | -15 to -35 |
| Dead public API cleanup from P74 | -80 to -180 |
| Full no-qemu arm64 runtime build conversion, if required | unknown; likely broad Docker/Makefile work, not a small patch |

## Verification Not Run

Per instruction, I did not run:

- `cargo build`
- `cargo test`
- `cargo clippy`
- Docker builds
- KVM or AWS

I relied on P66/P71/P75 self-reported verification where cited above.
