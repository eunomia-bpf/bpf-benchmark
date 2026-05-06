# Katran ARM64 kinsn matched-count gap - 2026-05-06

## Scope notes

- This is a read-only investigation of code and result artifacts, except for this requested report file.
- Code citations below are from `git show HEAD:<path>`. The prompt said `HEAD = e3c3388b`, but the workspace `HEAD` observed during this investigation was `88e43e83b87bc5cc406110de50de77e3450021de`.
- The three referenced `details/` directories contain `result.json` and `progress.json`; no `details/apps/katran.json`, `details/apps/*.json`, or persisted `target.json` was present. Target contents below are therefore separated into persisted module evidence and target-name evidence inferred from HEAD code plus successful `bpfopt` validation.

## 1. Per-pass observations

### Aggregate pass summaries

`sites_matched` in these reports is `sites_applied + sites_skipped`, emitted by `bpfopt` only for a pass invocation that actually ran.

| Run | App | Pass invocations contributing to kinsn counts | prefetch | cond_select | endian_fusion | bulk_memory | extract | rotate | wide_mem | ccmp |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| x86 `x86_kvm_corpus_20260506_073134_900272` | katran | `xdp_root`, `balancer_ingres` through prefetch, `healthcheck_enc` | 43/43 | 7/7 | 6/6 | 0/0 | 0/0 | 0/0 | n/a | n/a |
| ARM64 `aws_arm64_corpus_20260506_194818_115918` | katran | `xdp_root`, `healthcheck_enc`; `balancer_ingres` only reached `noop` | 1/1 | 0/0 | 0/0 | 0/0 | 0/0 | 0/0 | 0/0 | 0/0 |
| ARM64 `aws_arm64_corpus_20260506_193211_995298` | otel | all 12 programs reached the kinsn pass pipeline | 372/372 | 31/0 | 0/0 | 0/0 | 0/0 | 0/0 | 137/132 | 0/0 |

### Katran per-program split

The x86 katran matches are concentrated in the large `balancer_ingres` program:

| Arch | Program | ReJIT status | Passes reached | Relevant matches |
| --- | --- | --- | --- | --- |
| x86 | `xdp_root` | ok | rotate, cond_select, endian_fusion, prefetch, extract, bulk_memory | all 0 |
| x86 | `balancer_ingres` | error at prefetch ReJIT, after report | rotate, cond_select, endian_fusion, prefetch | cond_select 7/7, endian_fusion 6/6, prefetch 42/42 |
| x86 | `healthcheck_enc` | ok | all configured x86 passes | prefetch 1/1 |
| ARM64 | `xdp_root` | ok | noop, rotate, cond_select, prefetch, extract, endian_fusion, wide_mem, bulk_memory, ccmp | all 0 |
| ARM64 | `balancer_ingres` | error at initial noop ReJIT | noop only | no kinsn matcher ran |
| ARM64 | `healthcheck_enc` | ok | noop, rotate, cond_select, prefetch, extract, endian_fusion, wide_mem, bulk_memory, ccmp | prefetch 1/1 |

The ARM64 `balancer_ingres` failure is:

```text
kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 95: Operation not supported (os error 95)
```

The x86 `balancer_ingres` failure happened later:

```text
kernel rejected BPF_PROG_REJIT: BPF_PROG_REJIT errno 7: Argument list too long (os error 7)
```

That difference explains the apparent matched-count gap. On x86, `balancer_ingres` contributed 42 prefetch, 7 cond_select, and 6 endian_fusion matches before failing on the prefetch ReJIT. On ARM64, the same large program failed the bootstrap `noop` ReJIT, so none of its target-dependent matchers were invoked. The remaining two ARM64 katran programs genuinely contribute only the single healthcheck prefetch match.

### Genuine zero vs suspicious zero on ARM64

- Consistently zero in the ARM64 programs that actually reached the passes: rotate, extract, endian_fusion, bulk_memory, and ccmp are 0 in ARM64 katran's reached programs and in ARM64 otel. This is a real no-match observation for those reached programs, not for ARM64 katran `balancer_ingres`.
- Suspicious only if program coverage is ignored: ARM64 katran cond_select is 0 while ARM64 otel cond_select is 31. This does not show `bpf_select64` invisibility; it shows that ARM64 katran's large candidate-bearing program did not reach cond_select.
- Prefetch is the clearest non-cond_select explanation: x86 katran's 43 is `balancer_ingres` 42 plus `healthcheck_enc` 1. ARM64 katran keeps the `healthcheck_enc` 1 and loses the `balancer_ingres` 42 because `balancer_ingres` stops at `noop`.

## 2. kinsn registration evidence

### Persisted module evidence

All expected modules were resident after loader completion in all three runs.

| Run | Expected/resident modules |
| --- | --- |
| x86 katran | `bpf_bulk_memory`, `bpf_endian`, `bpf_extract`, `bpf_prefetch`, `bpf_rotate`, `bpf_select` |
| ARM64 katran | `bpf_bulk_memory`, `bpf_ccmp`, `bpf_endian`, `bpf_extract`, `bpf_ldp`, `bpf_prefetch`, `bpf_rotate`, `bpf_select` |
| ARM64 otel | `bpf_bulk_memory`, `bpf_ccmp`, `bpf_endian`, `bpf_extract`, `bpf_ldp`, `bpf_prefetch`, `bpf_rotate`, `bpf_select` |

The ARM64 katran and ARM64 otel module snapshots are materially identical: both started with the expected modules absent, loaded all 8, and had `missing_expected_modules: []` afterward. This weakens the per-instance sparse-module hypothesis.

### Target kinsn names expected from the pass plan

The daemon target file is per-program and temporary. It is written into the daemon workdir as `target.json` when any step references `${TARGET}`, and that workdir is not present in these result artifacts.

From HEAD pass metadata and enabled-pass configs, the target-dependent kinsn names are:

| Run | Enabled target-dependent passes | Target kinsn names expected in `target.json` |
| --- | --- | --- |
| x86 katran | rotate, cond_select, endian_fusion, prefetch, extract, bulk_memory | `bpf_rotate64`, `bpf_rotate32`, `bpf_select64`, `bpf_endian_load16`, `bpf_endian_load32`, `bpf_endian_load64`, `bpf_prefetch`, `bpf_extract64`, `bpf_memcpy_bulk`, `bpf_memset_bulk` |
| ARM64 katran | rotate, cond_select, prefetch, extract, endian_fusion, bulk_memory, ccmp | same as x86 plus `bpf_ccmp64` |
| ARM64 otel | rotate, cond_select, prefetch, extract, endian_fusion, bulk_memory, ccmp | same as ARM64 katran |

`wide_mem` has `META_NONE` in HEAD and does not request `${TARGET}`. The ARM64 `bpf_ldp` module is loaded by the module loader, but no HEAD pass metadata in this plan uses it as a target kinsn.

### Evidence the ARM64 target was not sparse

- ARM64 katran `xdp_root` and `healthcheck_enc` both successfully invoked all target-dependent bpfopt passes, including rotate, cond_select, prefetch, extract, endian_fusion, bulk_memory, and ccmp. Since `bpfopt` validates required kinsns before running each single pass, these successes imply the relevant target names were present for those per-program target files.
- ARM64 otel also successfully invoked all target-dependent passes, and produced 31 cond_select matches plus 372 prefetch matches. This directly shows `bpf_select64` and `bpf_prefetch` were visible and usable to `bpfopt` on ARM64.
- ARM64 katran `balancer_ingres` cannot prove or disprove its exact target file content from the artifact because it failed during `noop`, before any target-consuming pass invocation. However, target probing occurs before the step loop when `${TARGET}` appears anywhere in the plan, so failure at `noop` is not evidence of sparse target registration.

### Startup vs per-program target behavior

The daemon does not build one startup target.json. The runner sends one `kinsn_probes` list per execute-plan request, built as the union of kinsns used by the selected passes. The daemon then re-probes kernel BTF and writes a target file per program workdir if `${TARGET}` is referenced. The names should be stable within a run unless kernel BTF/module state changes; per-program `call_offset` values can differ because the daemon shifts module call offsets after the program's map-fd prefix.

## 3. Code citations

### Target and probe construction

- `runner/libs/rejit_plan.py:102-130` builds `kinsn_probes` from the union of selected pass metadata.
- `runner/libs/rejit_plan.py:151-157` puts the same step list and `kinsn_probes` list into the daemon `execute_plan` payload.
- `daemon/src/server.rs:207-262` parses the request's `kinsn_probes`.
- `daemon/src/commands.rs:456-475` creates `target.json` inside the per-program workdir when any step references `${TARGET}`.
- `daemon/src/commands.rs:460-475` probes target kinsns before the pass loop and stores the probed kinsns for the ReJIT fd array.
- `daemon/src/commands.rs:502-686` executes steps sequentially and breaks on bpfopt or ReJIT failure.
- `daemon/src/commands.rs:670-686` records `FailedRejit` and breaks after a kernel ReJIT error.
- `daemon/src/bpf.rs:84-98` builds the target JSON from detected arch, features, and probed kinsns.
- `daemon/src/bpf.rs:166-214` enumerates kernel BTF objects to find kinsn functions.
- `daemon/src/bpf.rs:224-268` maps found BTF functions into target JSON entries.
- `daemon/src/bpf.rs:494-521` emits x86 CPU feature tokens but intentionally emits no ARM64 feature tokens.

### bpfopt target and feature handling

- `bpfopt/crates/bpfopt/src/passes/mod.rs:90-96` declares target kinsns for rotate, cond_select, ccmp, extract, endian_fusion, bulk_memory, and prefetch.
- `bpfopt/crates/bpfopt/src/passes/mod.rs:102-118` shows `wide_mem` uses `META_NONE`, while target-dependent passes use target metadata.
- `bpfopt/crates/bpfopt/src/main.rs:340-350` runs one pass by building a context, validating required kinsns, then executing the pass pipeline.
- `bpfopt/crates/bpfopt/src/main.rs:451-470` validates required kinsns for target-dependent passes before matcher execution.
- `bpfopt/crates/bpfopt/src/main.rs:647-665` reads `target.json`, applies target features, and builds the kinsn registry.
- `bpfopt/crates/bpfopt/src/main.rs:749-780` resets feature booleans from target features and maps target kinsn entries into registry IDs/call offsets.
- `bpfopt/crates/bpfopt/src/main.rs:1307-1316` defines reported `sites_matched` as applied plus skipped sites.

### Matcher gates that can short-circuit

- Prefetch: `bpfopt/crates/bpfopt/src/passes/prefetch.rs:124-145` gates only on `bpf_prefetch` kfunc/packed ABI availability before analysis; there is no platform-feature gate.
- Cond select: `bpfopt/crates/bpfopt/src/passes/cond_select.rs:99-113` checks branchless-select support before analysis, but `bpfopt/crates/bpfopt/src/pass.rs:994-1000` defines that support as `has_cmov || bpf_select64 registered`. ARM64 does not need a `cmov` feature if `bpf_select64` is present.
- Endian fusion: `bpfopt/crates/bpfopt/src/passes/endian.rs:366-399` gates on endian kfunc/packed ABI availability, then scans sites; no ARM64 CPU feature gate short-circuits site enumeration.
- Extract: `bpfopt/crates/bpfopt/src/passes/extract.rs:114-129` gates on `bpf_extract64` availability, then scans sites; no BMI feature gate short-circuits enumeration.
- Rotate: `bpfopt/crates/bpfopt/src/passes/rotate.rs:33-49` gates on rotate kfunc availability, then scans sites; no RORX feature gate short-circuits enumeration.
- Bulk memory: `bpfopt/crates/bpfopt/src/passes/bulk_memory.rs:113-130` starts analysis and site scanning before checking specific memcpy/memset target IDs per site; no platform-feature gate.
- CCMP: `bpfopt/crates/bpfopt/src/passes/ccmp.rs:137-155` is intentionally Aarch64-only and requires `bpf_ccmp64`; it is not involved in the x86 katran comparison.

## 4. Verdict

Dominant cause: ARM64 katran's large `balancer_ingres` program fails the initial `noop` ReJIT, so the kinsn matchers never run on the program that produces almost all x86 katran matches. Confidence: high.

This is a pass-coverage gap, not primarily a matcher-enumeration or kinsn-registration gap. The x86 aggregate includes `balancer_ingres` matcher reports before a later prefetch ReJIT failure. The ARM64 aggregate excludes all target-dependent reports for `balancer_ingres` because it stops at `noop` with `EOPNOTSUPP`.

Hypotheses ranked by evidence:

1. Earlier ARM64 `balancer_ingres` no-op ReJIT failure, not in the original list: strongest. It directly accounts for prefetch 43 to 1, cond_select 7 to 0, and endian_fusion 6 to 0.
2. Hypothesis 4, daemon hands different bytecode shape to bpfopt: weak for the matched-count observation because bpfopt never receives the ARM64 `balancer_ingres` bytecode for target-dependent matchers. It remains a possible axis for why the ARM64 no-op ReJIT itself fails.
3. Hypotheses 1 and 5, per-instance or katran-vs-otel probe mismatch: weak for registration. ARM64 katran and ARM64 otel module snapshots both show all 8 expected modules loaded, and ARM64 otel proves select/prefetch visibility. Per-instance kernel differences could still matter for the `noop` ReJIT failure, but not for the observed sparse matched counts.
4. Hypothesis 2, target.json kinsn list differs per app/prog: weak. Target files are not persisted, but successful target-dependent pass validation on ARM64 katran's reached programs and all ARM64 otel programs implies the target was not globally sparse.
5. Hypothesis 3, ARM64 platform-feature matcher gate: weakest for the broad gap. Prefetch, endian_fusion, extract, rotate, and bulk_memory do not use ARM64 feature gates before enumeration. Cond_select has a gate, but registered `bpf_select64` satisfies it, and ARM64 otel's 31 matched sites demonstrate that path works.

The exact kernel-side reason for `BPF_PROG_REJIT` returning `EOPNOTSUPP` on ARM64 katran `balancer_ingres` is not determined from these artifacts. The result is sufficient to explain the matched-count gap, but not to root-cause the no-op ReJIT rejection.

## 5. Fix dimensions

- ReJIT compatibility axis: investigate why ARM64 `BPF_PROG_REJIT` rejects the unchanged katran `balancer_ingres` program at the bootstrap `noop` step, including XDP program shape, subprograms, map fd-array layout, verifier-state capture, and ARM64 kernel support paths.
- Measurement/accounting axis: treat "pass did not run because an earlier ReJIT step failed" separately from "pass ran and matched zero sites" when comparing matched counts across architectures.
- Artifact/provenance axis: make future investigations able to distinguish target-name absence, target call-offset differences, and pass-not-run cases from the persisted artifacts.
- Target/probe stability axis: compare module BTF discovery, target kinsn names, and feature lists across EC2 instances and apps when investigating true registration drift.
- Matcher-gate axis: keep ARM64 feature-gate audits focused on passes that actually have platform gates. In HEAD, cond_select is the only listed pass with a relevant pre-analysis capability gate, and `bpf_select64` registration is sufficient to pass it.
