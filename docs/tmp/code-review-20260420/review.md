# Code review (2026-04-20)

## 1. Dead code (delete candidates)
- bpfopt-suite/crates/bpfget/src/main.rs:4 — `bpfget` is a declared binary but only prints "not yet implemented" and exits 1; no runner/Makefile path invokes it. Safe to delete? N if the #646 public CLI contract is still claimed; otherwise Y with the corresponding Cargo/workspace/docs contract removed.
- bpfopt-suite/crates/bpfverify/src/main.rs:4 — `bpfverify` is the same non-functional stub, while the active verifier-in-loop path remains inside `daemon/`. Safe to delete? N if the paper says per-pass verify is external; otherwise Y.
- bpfopt-suite/crates/bpfprof/src/main.rs:4 — `bpfprof` is a stub and does not reference the copied profiler module. Safe to delete? N if the profiler CLI is part of the camera-ready artifact; otherwise Y.
- bpfopt-suite/crates/bpfrejit/src/main.rs:4 — `bpfrejit` is a stub for the final submit step, but benchmark apply still uses daemon JSON over Unix socket. Safe to delete? N if `bpfget | bpfopt | bpfverify | bpfrejit` remains the stated architecture; otherwise Y.
- bpfopt-suite/crates/bpfrejit-daemon/src/main.rs:4 — `bpfrejit-daemon` is a stub even though `daemon/target/.../bpfrejit-daemon` is the binary actually built and launched. Safe to delete? N if it is meant to replace `daemon/`; otherwise Y.
- bpfopt-suite/crates/kernel-sys/src/lib.rs:37 — `kernel-sys` exposes only `placeholder()`, so the kernel-facing CLI crates cannot currently use the raw syscall layer described by the plan. Safe to delete? N if the CLI crates are to be implemented now; otherwise Y along with those stubs.
- bpfopt-suite/crates/bpfget/src/kfunc_discovery.rs:1 — copied kinsn discovery code is not reachable from the stub `bpfget` main. Safe to delete? Y unless `bpfget` is implemented before camera-ready.
- bpfopt-suite/crates/bpfprof/src/profiler.rs:1 — full profiler copy is not reachable from the stub `bpfprof` main. Safe to delete? Y unless `bpfprof` is implemented before camera-ready.
- bpfopt-suite/crates/bpfrejit-daemon/src/commands_ref.rs:1 — copied daemon command code is not referenced by `main.rs`; `server_ref.rs`, `commands_tests_ref.rs`, and `invalidation.rs` are the same dead reference set. Safe to delete? Y; keep history in git, not in the active crate.
- corpus/driver.py:626 — `_app_measurement_row()` is currently dead: `runner/libs/app_runners/base.py:49` is the only `corpus_measurement_mode()` implementation in the tree and it returns `"program"`. Safe to delete? Y if corpus remains per-program `exec_ns` only.
- corpus/driver.py:679 — the `measurement_mode == "app"` comparison-row path is unreachable for the same reason. Safe to delete? Y with the app-measurement helper.
- e2e/driver.py:469 — after lines 467-468 replace an empty `selected_rejit_passes` with `requested_rejit_passes`, the `if not selected_rejit_passes` branch at 471 can never run. Safe to delete? Y.

## 2. Silent fallbacks / bug-masking branches
- runner/libs/rejit.py:70 — `BPFREJIT_DAEMON_TMPDIR` falls through `/var/tmp`, `/tmp`, then `tempfile.gettempdir()` if mkdir/access fails; this hides a bad explicit temp-dir contract. Correct fix: fail when an explicit tmpdir is unusable, and validate the final implicit dir before using it.
- runner/libs/rejit.py:211 — malformed or missing pass site counts return `0`; a daemon schema drift or bad counter type silently disables policy rules such as `has_sites`. Correct fix: in benchmark paths, treat malformed counters for known passes as an error.
- runner/libs/rejit.py:249 — pass selection falls through policy default, active list, named list, performance list, then `_DEFAULT_REJIT_ENABLED_PASSES`; a missing/misspelled benchmark config can silently run the old 3-pass set. Correct fix: require a valid active paper profile/config unless an explicit env override is supplied.
- runner/libs/rejit.py:354 — `_accumulate_pass_site_counts()` ignores non-list pass payloads, non-mapping entries, unknown pass names, and bad counts; aggregate applied-site totals can undercount without failing. Correct fix: reject malformed pass records from daemon responses in benchmark/e2e result processing.
- runner/libs/rejit.py:465 — `_apply_result_from_response()` treats a missing `summary.applied` as true when exit code is 0. Correct fix: require `summary.applied` and explicit changed/apply counters from daemon responses, otherwise mark the apply result invalid.
- daemon/src/server.rs:46 — map-invalidation reoptimization failures are only printed to stderr and `process_invalidation_tick()` still returns `Ok(invalidated)`. Correct fix: surface invalidation failures in daemon status/results or fail the daemon so benchmark state cannot look clean.
- daemon/src/server.rs:111 — `collect_live_program_candidates()` falls back from empty `orig_insns` to `info.orig_prog_len`; that hides a broken `BPF_PROG_GET_ORIGINAL` path. Correct fix: fail the candidate collection when original bytecode is missing.
- daemon/src/server.rs:202 — stale socket removal uses `let _ = remove_file(...)`; permission/path problems are ignored until bind behavior changes later. Correct fix: ignore only `NotFound`, propagate every other removal error.
- runner/libs/aws_executor.py:55 — `_describe_instance_type()` returns `""` on AWS CLI failure. Correct fix: require successful `describe-instances` and include stderr in the failure.
- runner/libs/aws_executor.py:62 — `_describe_instance_launch_contract()` returns an all-empty contract tuple on AWS CLI failure. Correct fix: fail; otherwise setup can replace an instance because metadata lookup failed, not because the contract changed.
- runner/libs/aws_executor.py:72 — `_lookup_existing_instance()` returns empty instance fields on AWS CLI failure, which can launch a duplicate. Correct fix: distinguish "no instance" from "describe failed".
- runner/libs/aws_common.py:61 — `_describe_instance()` returns empty fields on AWS describe failure. Correct fix: propagate the AWS error to callers that wait, terminate, or reuse instances.
- runner/libs/aws_common.py:70 — `_lookup_target_instance_ids()` returns `[]` on AWS describe failure, so terminate/status flows can report no instances while AWS was unreachable. Correct fix: fail the action unless the query succeeded.
- runner/libs/aws_executor.py:270 — `_remote_root_volume_size_gb()` returns `None` when the SSH/lsblk probe fails, which disables root-volume validation. Correct fix: fail setup when the probe fails, or record an explicit unsupported state that blocks benchmark mode.
- runner/libs/aws_executor.py:574 — `_sync_remote_results()` returns `None` if the remote result directory is absent. Correct fix: if the remote suite command exited 0, missing results should be a hard error.
- runner/libs/aws_executor.py:654 — failed-run cleanup catches termination exceptions and only warns. Correct fix: preserve the original failure but also return/report cleanup failure in the executor result.
- corpus/driver.py:1411 — if an app start fails, `runner.stop()` exceptions are swallowed with `except Exception: pass`. Correct fix: include stop failure in the app error record.
- corpus/driver.py:1694 — run metadata substitutes requested passes when no effective passes are found. Correct fix: report empty selected passes as empty and add an error/warning that provenance was missing.
- e2e/driver.py:548 — invalid payload status is overwritten with `"error"` before the error message is built, so the message reports the replacement rather than the original invalid status. Correct fix: save the original value first.
- e2e/driver.py:645 — `all` expansion removes every argv token equal to `"all"`, even if it is a value for another flag. Correct fix: remove only the positional case token.
- e2e/cases/bcc/case.py:582 — BCC e2e metadata falls back to default requested passes when no effective passes are found. Correct fix: keep selected passes empty and mark provenance missing.

## 3. Arch splits that should be unified
- runner/libs/aws_executor.py:423 — AWS setup splits `aws-arm64` into runtime-image extraction but `aws-x86` into `_build_x86_kernel_artifacts()` host cache build. After runtime image consolidation, both AWS arches should use the same image-tar extraction/deploy path with only image name and kernel filename varying.
- runner/libs/aws_executor.py:129 — x86 AWS kernel artifacts still target `.cache/x86-kernel-build` and `.cache/repo-artifacts/x86_64/kernel-modules`, bypassing the runtime image tar that KVM x86 and AWS arm64 now rely on. Unify on the runtime image artifact manifest to avoid cache-dependent green runs.
- runner/libs/workspace_layout.py:75 — `kinsn_module_dir()` chooses `/artifacts/kinsn` whenever that directory exists, even outside the runtime image and regardless of `target_arch`. It should only use the runtime path inside the runtime image, or require an explicit override.
- runner/libs/workspace_layout.py:80 — `kernel_modules_root()` deletes `target_arch` and hardcodes x86 modules for all KVM executions. Either assert KVM is x86-only at the call boundary or use the target arch to keep the helper contract honest.
- Makefile:202 — legacy `aws-e2e`/`aws-corpus` dispatch on `RUN_TARGET_ARCH`, while canonical targets are already arch-specific (`aws-arm64-*`, `aws-x86-*`). Delete the aliases or make them thin wrappers around the canonical names to avoid a third AWS selection surface.

## 4. Duplicated logic (consolidation candidates)
- runner/suites/corpus.py:34 and runner/suites/e2e.py:45 — standalone suite entrypoints duplicate parsing for workspace/daemon/native repos/scx packages/remainder argv. Consolidate common parser construction and remainder handling.
- runner/suites/corpus.py:84 and runner/suites/e2e.py:85 — both wrappers scrape `--rejit-passes` out of passthrough argv and re-export `BPFREJIT_BENCH_PASSES`. Consolidate this into one helper, or pass explicit enabled passes through the driver API.
- runner/suites/corpus.py:116 and runner/suites/e2e.py:108 — runtime setup repeats Python/bpftool resolution, loop setup, bpf_stats enabling, SCX validation, and daemon resolution. Consolidate into a shared `prepare_runtime_suite()` helper.
- runner/libs/suite_commands.py:149 and runner/libs/suite_commands.py:179 — corpus and e2e suite argv builders duplicate native repo and SCX package loops. Extract shared artifact-argument appenders.
- runner/libs/kvm_executor.py:90 and runner/libs/aws_executor.py:599 — both executors build runtime-container commands and required host result dirs, then differ only in local-vs-remote transport. Share command/result-dir construction so KVM and AWS cannot drift.
- runner/libs/kvm_executor.py:95 and runner/libs/aws_executor.py:613 — result-dir `mkdir -p` logic is duplicated with different helpers. Consolidate around `runtime_container_host_dirs()`.
- e2e/driver.py:302 and e2e/driver.py:328 — Tracee and Tetragon suite config filtering are copy-pasted except labels and temp-prefix. Extract a `filter_workloads_config(args, suite_apps, label, temp_prefix)` helper.
- daemon/src/passes/mod.rs:1 and bpfopt-suite/crates/bpfopt-core/src/passes/mod.rs:1 — pass registry and implementations are duplicated between active daemon and `bpfopt-core`. Pick one implementation source before camera-ready; otherwise fixes can land in one optimizer but not the other.
- daemon/src/profiler.rs:1 and bpfopt-suite/crates/bpfprof/src/profiler.rs:1 — profiler code is duplicated byte-for-byte, but the bpfprof CLI is a stub. Either move the active code into a shared crate or delete the dead copy.
- daemon/src/invalidation.rs:1 and bpfopt-suite/crates/bpfrejit-daemon/src/invalidation.rs:1 — invalidation tracking is duplicated while only `daemon/` uses it. Share it only if the new daemon is implemented; otherwise remove the unused copy.

## 5. Unused contract surface
- corpus/driver.py:70 — `--rejit-passes` is parsed by the driver but `run_suite()` calls `_resolve_scan_pass_selection(None)` at corpus/driver.py:1503, so direct `corpus/driver.py --rejit-passes ...` does not select passes. Fix by wiring `args.rejit_passes` into scan/apply selection or remove the driver flag and keep the wrapper env contract only.
- e2e/driver.py:194 — top-level e2e `--rejit-passes` is parsed but the case lifecycle paths use `BPFREJIT_BENCH_PASSES`/benchmark config, not `args.rejit_passes`. Fix by threading it into case calls or remove the direct driver flag.
- e2e/cases/katran/case.py:92 — Katran has its own `--rejit-passes` flag, but the case calls `run_app_runner_lifecycle()` without `enabled_passes`. Fix or remove the flag.
- runner/suites/corpus.py:43 — `--warmups` is documented as ignored, yet runner/libs/suite_args.py:112 still emits it for corpus. Remove the corpus warmup surface unless there is a real warmup phase.
- Makefile:46 — root `PROFILE` is declared and help mentions it for `vm-e2e` at Makefile:108, but AWS profile resolution only reads prefixed variables via runner/libs/run_contract.py:209. Remove `PROFILE` or map it explicitly to `AWS_ARM64_PROFILE`/`AWS_X86_PROFILE` for legacy aliases.
- Makefile:64 — `KALLSYMS_EXTRA_PASS` is declared but not referenced anywhere outside the declaration. Delete it.
- Makefile:202 — `aws-e2e` and `aws-corpus` are overlapping public entrypoints beside `aws-arm64-benchmark`/`aws-x86-benchmark`, and require unadvertised `RUN_TARGET_ARCH`. Delete or document/validate them as supported aliases.
- bpfopt-suite/Cargo.toml:5 — workspace declares kernel-facing CLI crates (`bpfverify`, `bpfprof`, `bpfget`, `bpfrejit`, `bpfrejit-daemon`) that are not functional and are not included in the active runtime build. Either implement/hook them up or remove the public binaries for camera-ready.

## 6. Design drift vs plan doc
- daemon/src/commands.rs:252 — active daemon still builds the optimization pipeline internally, conflicting with docs/kernel-jit-optimization-plan.md:363 where the daemon is only a REJIT proxy/watch shell and the pipeline is external `bpfget | bpfopt | bpfverify | bpfrejit`.
- daemon/src/main.rs:7 — the active daemon still imports analysis/pass/passes/profiler modules directly, so optimization policy and profiling remain in the daemon rather than in extracted tools.
- runner/libs/rejit.py:492 — benchmark code still starts `daemon serve` and sends JSON optimize/apply requests; it does not invoke the bpfopt-suite pipeline described in docs/kernel-jit-optimization-plan.md:363.
- runner/mk/build.mk:230 — runtime builds `daemon/target/.../bpfrejit-daemon`, while `bpfopt-suite/crates/bpfrejit-daemon/src/main.rs:4` is a stub. This makes the extracted daemon architecture non-operative.
- runner/mk/build.mk:102 — runtime image source inputs include `DAEMON_SOURCE_FILES` but not `bpfopt-suite/`, so the consolidated runtime image cannot be exercising the extracted toolchain.
- daemon/src/server.rs:117 — falling back from missing original bytecode to `orig_prog_len` violates the syscall component contract implied by `BPF_PROG_GET_ORIGINAL`; daemon should not fabricate enough metadata to continue.
- corpus/driver.py:626 — corpus still contains app-level measurement code even though docs/kernel-jit-optimization-plan.md:402 and 425 say corpus is per-program `exec_ns` and app metrics belong to E2E.
- runner/libs/rejit.py:249 — the hard-coded pass fallback preserves the old default-pass contract even though docs/kernel-jit-optimization-plan.md:1020 says the default benchmark set is the full in-scope performance set from config.
- runner/libs/aws_executor.py:129 — AWS x86 still prepares kernel/modules through host cache paths rather than the single consolidated runtime image artifact described in the prior context; this is an implementation drift from the runtime-image consolidation.
- daemon/src/server.rs:46 — invalidation reoptimization errors are logged and swallowed, conflicting with docs/kernel-jit-optimization-plan.md:18 zero-silent-failure guidance.

## 7. Ranked top-5 things to act on
(1) daemon/src/commands.rs:252 — resolve the `daemon/` vs `bpfopt-suite/` split first; the current code and the plan describe different architectures.

(2) runner/libs/rejit.py:459 — make daemon apply/scan response schemas strict; defaulting missing `applied`, pass counts, and selected-pass provenance can directly corrupt paper numbers.

(3) runner/libs/aws_executor.py:423 — unify AWS x86 and arm64 artifact setup on the runtime image tar so validated AWS results are testing the consolidated image path.

(4) corpus/driver.py:626 — delete the dead corpus app-measurement mode and unused pass/warmup flags; this shrinks the public contract to what the benchmark actually supports.

(5) runner/suites/corpus.py:34 — consolidate corpus/e2e wrappers and KVM/AWS runtime-command setup; duplicated orchestration is now the main source of stale branches and inconsistent behavior.
