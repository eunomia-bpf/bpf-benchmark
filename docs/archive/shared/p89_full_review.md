# P89 Full Review

Scope: read-only review of bpfopt plus benchmark framework at HEAD `26f1a702`.

Constraints followed:
- Did not edit production code.
- Did not touch `vendor/linux-framework` or `module/`.
- Did not run `cargo test`.
- Scanned the required areas: `daemon/`, all six `bpfopt/crates/*` CLI/library crates, `runner/libs/`, `runner/suites/`, `corpus/driver.py`, `e2e/driver.py`, `micro/driver.py`, `runner/containers/*.Dockerfile`, `runner/mk/build.mk`, and root `Makefile`.
- Existing uncommitted corpus result artifacts were left untouched.

Review stance: prioritize delete/reduce findings over adding compatibility. The highest-value deletes are warning-and-continue paths, duplicated protocol code, one-implementation abstractions, and host bind mounts that exceed the documented container boundary.

## Findings

### corpus/driver.py:392 - tracked program IDs can still be replaced after a warning
- 严重度：HIGH
- 类别：fail-soft
- 建议：DELETE 这一段 rediscovery replacement path. If any originally tracked program ID disappears before baseline/post-ReJIT measurement, raise immediately instead of logging `session_warning` and rewriting `session.state.prog_ids` to a refreshed same-count set. The current code fixed the fewer-program partial accept case, but still allows identity drift when the count is not lower.

### runner/libs/suite_commands.py:149 - runtime tmp is bind-mounted from the host workspace
- 严重度：HIGH
- 类别：design violation
- 建议：DELETE the `docs/tmp/runtime-container-tmp` host bind mount from the runtime container path, or make it an explicit result-output directory if artifacts must survive. Current mounts at lines 149-153 exceed the rule that runtime containers should use image layers plus system mounts and result mounts only.

### runner/libs/aws_executor.py:424 - AWS kernel installer container bind-mounts the full host root
- 严重度：HIGH
- 类别：design violation
- 建议：DELETE the full `-v /:/host` installer-container pattern, or narrow it to the documented system paths needed for kernel/module installation. The current root mount plus `/dev`, `/proc`, `/sys`, `/run` chroot flow is much broader than the no-host-bind-mount design rule.

### bpfopt/crates/bpfopt/src/pass.rs:990 - missing required analysis names are ignored
- 严重度：MEDIUM
- 类别：fail-soft
- 建议：DELETE the string-keyed precompute registry, or make unknown `required_analyses()` names a hard error. Today `run_required_analyses()` silently does nothing when a pass declares an unregistered analysis name, while most passes also request typed analyses directly from `AnalysisCache`, making this both redundant and fail-soft.

### bpfopt/crates/bpfopt/src/main.rs:935 - unknown target CPU features are silently ignored
- 严重度：MEDIUM
- 类别：fail-soft
- 建议：DELETE the `_ => {}` arm in `apply_features()` and return `Result<()>` so target JSON schema drift exits 1. A misspelled feature currently degrades pass gating without surfacing a defect.

### bpfopt/crates/bpfopt/src/main.rs:994 - unknown kinsn encoding names collapse to zero bits
- 严重度：MEDIUM
- 类别：fail-soft
- 建议：重构 `parse_supported_encodings()` to return `Result<u32>` and reject unknown names. The current fold only recognizes `packed`/`packed_call`; every other string is ignored, which can silently disable a target capability.

### bpfopt/crates/bpfopt/src/passes/map_inline.rs:1400 - pseudo-map-value resolver downgrades provider errors to diagnostics
- 严重度：MEDIUM
- 类别：fail-soft
- 建议：DELETE the diagnostic-and-`None` fallback for non-concrete resolver errors. Map provider, metadata, and lookup failures should propagate except for explicit, well-defined ineligible cases such as non-frozen maps or hash-like null snapshots.

### bpfopt/crates/bpfopt/src/passes/prefetch.rs:189 - prefetch budget drops candidates without accounting
- 严重度：MEDIUM
- 类别：complexity
- 建议：DELETE the global `PREFETCH_SITE_BUDGET` path or report every budgeted-away candidate as `sites_skipped` with a reason. `dedup_and_budget()` keeps at most eight candidates and silently breaks at line 728, so pass reports undercount matched structural sites.

### bpfopt/crates/bpfverify/src/verifier_log.rs:21 - verifier-state model is duplicated with bpfopt pass input model
- 严重度：MEDIUM
- 类别：complexity
- 建议：重构 into a shared non-CLI library crate, or reduce one side to a pure serialization DTO. `VerifierInsnKind`, `VerifierValueWidth`, `Tnum`, `ScalarRange`, `VerifierInsn`, `RegState`, `StackState`, and exact-value helpers are duplicated against `bpfopt/crates/bpfopt/src/pass.rs:55`, increasing ABI drift risk while respecting the no-CLI-cross-dependency rule.

### bpfopt/crates/bpfrejit/src/main.rs:42 - fd_array JSON parsing is duplicated with bpfverify
- 严重度：MEDIUM
- 类别：complexity
- 建议：重构 `FdArrayEntry`, slot-density checks, BTF fd resolution, and owned-fd storage into shared library code. `bpfverify/src/main.rs:177` and `bpfverify/src/main.rs:831` duplicate the same contract and error policy almost line-for-line.

### runner/libs/environment.py:57 - strict publication checks still warn for perf_event_paranoid
- 严重度：MEDIUM
- 类别：fail-soft
- 建议：DELETE the unconditional warning path and route `perf_event_paranoid > 1` through `report_publication_issue()`. In strict mode this should fail, especially because PMU availability is a hard requirement for profile-guided paths.

### runner/libs/rejit.py:454 - malformed ReJIT aggregate results become zero site counts
- 严重度：MEDIUM
- 类别：fail-soft
- 建议：DELETE the non-mapping zero return and the per-program non-mapping `continue` path around line 526. Schema drift in `per_program` should raise, not make aggregate site counts look like a clean no-op.

### bpfopt/crates/bpfopt/src/pass.rs:795 - KinsnCallResolver is a one-implementation trait
- 严重度：LOW
- 类别：complexity
- 建议：DELETE the trait object and `Arc<dyn KinsnCallResolver>` until a real second resolver exists. `StaticKinsnCallResolver` only forwards to `KinsnRegistry::call_off_for_target_name()`, so the wrapper adds indirection without policy.

### bpfopt/crates/bpfopt/src/passes/wide_mem.rs:21 - wide_mem carries old generic matcher shapes as public structs
- 严重度：LOW
- 类别：complexity
- 建议：DELETE the `Binding` vector/string lookup abstraction and make a typed private `WideMemSite`. The comments still mention "absorbed from matcher.rs" and "found by the daemon"; current v3 code is a pure bpfopt pass, so this is legacy shape and over-abstraction.

### bpfopt/crates/kernel-sys/src/lib.rs:996 - prog_func_infos is public but has no external caller
- 严重度：LOW
- 类别：dead code
- 建议：DELETE the public API surface by folding it into `prog_main_func_btf_id()` or making it private. Current non-test callers outside `kernel-sys` use `prog_main_func_btf_id()`, not raw func_info decoding.

### micro/driver.py:112 - provenance git failures are converted to "unknown" or clean
- 严重度：LOW
- 类别：fail-soft
- 建议：DELETE the fallback provenance values or fail only the provenance collection step explicitly. `_git_rev_parse()` returns `"unknown"` and `_git_is_dirty()` returns `False` on command errors, which can make result metadata look cleaner than the run environment was.

### Makefile:192 - clean-results is a no-op target advertised in help
- 严重度：LOW
- 类别：dead code
- 建议：DELETE the target/help entry or implement a concrete cleanup command. A phony target that only prints "manual" adds surface area without behavior.

### bpfopt/crates/bpfopt/src/passes/bulk_memory_tests.rs:356 - empty/no-site pass tests repeat trivial coverage
- 严重度：LOW
- 类别：unit test
- 建议：DELETE duplicate empty-program/no-sites tests where they only assert unchanged input and zero sites. Similar examples exist at `bounds_check_merge.rs:993`, `skb_load_bytes.rs:651`, and `wide_mem_tests.rs:263`; keep tests that cover pass-specific boundaries, branch fixups, verifier metadata, and skip reasons.

### docs/kernel-jit-optimization-plan.md:418 - default pass-count text is stale after PrefetchV2
- 严重度：LOW
- 类别：complexity
- 建议：DELETE or update the "default optimize pass list still 11" sentence. Code now has `prefetch` in `DEFAULT_OPTIMIZE_PASS_ORDER` at `bpfopt/crates/bpfopt/src/main.rs:40`, so this doc contradicts the implementation and the newer PrefetchV2 note at line 226.

## Confirmed KEEP Checks

### daemon/src/commands.rs:813 - daemon profile lifecycle delegates to bpfprof
- 严重度：LOW
- 类别：design violation
- 建议：KEEP. This matches v3 Option B: the daemon starts/stops an external `bpfprof --all --per-site` process and does not profile internally.

### daemon/src/commands.rs:1067 - daemon optimize path delegates to bpfopt CLI
- 严重度：LOW
- 类别：design violation
- 建议：KEEP. The daemon adapts socket JSON to external `bpfget`, `bpfopt`, `bpfverify`, and `bpfrejit` subprocesses; no daemon-side `PassManager` or in-process bytecode transform was found.

### bpfopt/crates/kernel-sys/src/lib.rs:268 - SYS_bpf syscall boundary is contained in kernel-sys
- 严重度：LOW
- 类别：design violation
- 建议：KEEP. `libc::syscall(SYS_bpf, ...)` was found only in `kernel-sys`; CLI crates and daemon call through `kernel-sys`. The separate `perf_event_open` syscall at line 926 is not a BPF syscall boundary violation.

### bpfopt/crates/bpfopt/Cargo.toml:16 - bpfopt depends only on kernel-sys, not another CLI crate
- 严重度：LOW
- 类别：design violation
- 建议：KEEP. All five CLI binaries depend on `kernel-sys`; no CLI crate path-depends on another CLI crate. This respects the no CLI cross-dependency rule.

### runner/mk/build.mk:136 - runtime Python/YAML are separated from compile-trigger source inputs
- 严重度：LOW
- 类别：complexity
- 建议：KEEP. `RUNNER_RUNTIME_IMAGE_SOURCE_FILES` excludes Python/YAML runtime layers and `RUNNER_RUNTIME_IMAGE_LAYER_FILES` adds them later, matching the Docker layering rule that Python changes should not rebuild apps/kernel/daemon.

### runner/containers/runner-runtime.Dockerfile:441 - Rust daemon and bpfopt artifacts are upper layers
- 严重度：LOW
- 类别：complexity
- 建议：KEEP. The runtime Dockerfile keeps app artifacts, kernel artifacts, kinsn/test artifacts, Rust daemon/CLI artifacts, then Python/config layers in the expected order.

### corpus/driver.py:188 - corpus summary is per-program avg_ns_per_run
- 严重度：LOW
- 类别：complexity
- 建议：KEEP. Summary construction uses per-program baseline/post-ReJIT `avg_ns_per_run`, requires positive run deltas for mathematical comparability, and produces `per_program_geomean`, `program_count`, `wins`, and `losses`.

### bpfopt/crates/bpfopt/src/passes/branch_flip.rs:80 - branch_flip fails on missing real PMU profile
- 严重度：LOW
- 类别：design violation
- 建议：KEEP. Missing program-level branch miss rate and missing per-site profile data both bail, and profile parsing requires `branch_count`, `branch_misses`, `miss_rate`, `taken`, and `not_taken`.

### bpfopt/crates/bpfopt/src/passes/prefetch.rs:38 - PrefetchV2 structural emit matches current policy
- 严重度：LOW
- 类别：design violation
- 建议：KEEP with the budget-reporting caveat above. Packet/map-value structural detection and optional PMU admission filtering match the current PrefetchV2 policy: missing PMU data does not block structural emit.

## Top Immediate Delete List

1. `corpus/driver.py:392`: delete program-ID rediscovery warning-and-replace behavior; fail if tracked IDs disappear.
2. `runner/libs/suite_commands.py:149`: delete runtime tmp host bind mount, or move it under explicit result output handling.
3. `runner/libs/aws_executor.py:424`: delete full host-root installer bind mount; narrow to required system paths.
4. `bpfopt/crates/bpfopt/src/pass.rs:990`: delete string-keyed required-analysis precompute, or make missing analysis names fatal.
5. `bpfopt/crates/bpfopt/src/main.rs:935` and `:994`: delete silent ignore for unknown target features/encodings.
6. `bpfopt/crates/bpfopt/src/passes/map_inline.rs:1400`: delete diagnostic-and-continue for map provider resolver errors.
7. `bpfopt/crates/bpfopt/src/pass.rs:795`: delete `KinsnCallResolver` trait until a second real resolver exists.
8. `bpfopt/crates/bpfrejit/src/main.rs:42` plus `bpfverify/src/main.rs:177`: delete duplicate fd-array parser copies via a shared library module.
9. `bpfopt/crates/bpfopt/src/passes/wide_mem.rs:21`: delete generic `Binding` matcher leftovers and use a typed private site.
10. `Makefile:192`: delete the advertised no-op `clean-results` target or implement it.
