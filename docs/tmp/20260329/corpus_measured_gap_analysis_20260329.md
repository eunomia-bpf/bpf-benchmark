# Corpus Measured Gap Analysis (2026-03-29)

## Scope

This note answers one narrow question: why the corpus currently reports `measured=0` or very low coverage for `tracee(169)`, `scx(85)`, `KubeArmor(63)`, and `tetragon(90)`, and whether the blocker is:

- real kernel `7.0.0-rc2+` lack of support,
- a fixable generic-loader problem,
- or the absence of the original application loader / attach-trigger path.

Two artifacts must be separated:

1. Latest perf corpus run: `runner/corpus/results/vm_corpus_20260329_091745/metadata.json`
   - This is the latest `measured_pairs` artifact.
   - It ran in `mode="packet"`, so its `compile_pairs` / `measured_pairs` numbers are biased toward packet-style `test_run` or simple attach+trigger paths.
2. Load-only census: `corpus/results/code_size_full_vm_20260312.json`
   - This is the best artifact for isolating raw object-load failures.
   - It is not the same thing as "honest runtime measured coverage".

One naming subtlety matters:

- `tracee(169)` in the latest perf artifact refers to `tracee.bpf.o` only.
- The older load-only census reports `170` Tracee programs because it also includes `lsm_check.bpf.o`.

## Executive Verdict

| Repo | Latest perf corpus (`compile_pairs` / `measured_pairs` / `programs`) | Load-only census | Main reason for `measured=0/low` | Kernel `7.0-rc2` unsupported? | Generic loader fixable? | Use original app loader? |
| --- | --- | --- | --- | --- | --- | --- |
| `tracee` | `0 / 0 / 169` | `147 applied`, `23 no_sites`, `0 load_failed` | Generic packet-mode harness mismatch; not a raw load problem | No evidence of a kernel blocker | Not with packet-mode alone; needs real attach+trigger semantics | Yes |
| `scx` | `25 / 0 / 85` | `60 load_failed`, `10 recompile_load_failed`, `7 applied`, `8 no_sites` | `struct_ops` / `sched_ext` registration semantics, not just object load | Not fundamentally; `scx_rusty` works on this kernel | Partly, but only with scheduler-specific bring-up | Yes, preferred |
| `KubeArmor` | `0 / 0 / 63` | `63 load_failed` | CO-RE target BTF / loader environment failure before verifier | No evidence of a kernel blocker | Yes, probably | Likely yes |
| `tetragon` | `82 / 13 / 90` | `76 load_failed`, `7 applied`, `7 no_sites` | Older BTF-path load failure was loader-side; remaining gap is attach-trigger coverage | Mostly no; one `seccomp` edge remains | Yes, and much of it is already fixed | Yes |

## Important Distinction

For these four repos, "measured coverage is low" and "objects cannot load" are different problems:

- `tracee`: mostly a measurement-harness problem.
- `scx`: mostly a loader / lifecycle / scheduler-registration problem.
- `KubeArmor`: a true object-load problem in the generic path.
- `tetragon`: used to be mostly a load problem; in the latest perf run it is now mostly an attach-trigger problem.

## Repo-by-Repo Analysis

### 1. Tracee

Top-line facts:

- Latest perf corpus: `169` programs, `compile_pairs=0`, `measured_pairs=0`.
- Older load-only census: `170` programs total (`tracee.bpf.o` + `lsm_check.bpf.o`), with `147 applied`, `23 no_sites`, and no `load_failed`.
- Program mix in the load-only census is overwhelmingly non-packet: `133 kprobe`, `33 raw_tracepoint`, `2 lsm`, and only `2 cgroup_skb`.

What this means:

- Tracee is not failing because the object cannot load on kernel `7.0-rc2`.
- The failure is that the latest perf corpus is still packet-oriented, while Tracee is a large tracing/security object whose real hooks are `kprobe`, `raw_tracepoint`, `uprobe`, and `lsm`.
- The earlier note `docs/tmp/2026-03-11/non-networking-evaluation-plan.md` already called this out: historically only the two `cgroup_skb` fallback programs had any measured path at all.

So why is `measured=0` now?

- In the latest packet-mode corpus artifact, the generic measurement path does not provide an honest Tracee attach+trigger path for the monolithic `tracee.bpf.o` object.
- That is a harness mismatch, not evidence that kernel `7.0-rc2` lacks Tracee support.

Original loader evidence:

- Tracee embeds `dist/tracee.bpf.o` directly in `runner/repos/tracee/embedded-ebpf.go:10-13`.
- It builds a module from the embedded object with `bpf.NewModuleFromBufferArgs(...)` and then calls `BPFLoadObject()` in `runner/repos/tracee/pkg/ebpf/tracee.go:1677-1709`.
- The local authoritative e2e path already uses the real daemon loader: `e2e/cases/tracee/case.py:1914-1926` reports mode `tracee_daemon_same_image_paired_with_control`.
- The corresponding result `e2e/results/tracee_authoritative_20260329.json` contains `13` loaded Tracee programs, showing that the original app loader is viable on this kernel.

Verdict:

- Root cause: generic corpus harness mismatch, not kernel support.
- Fix direction: do not spend time trying to force this through the packet generic loader.
- Recommended loader: use the original Tracee daemon loader or a dedicated attach+trigger harness.

### 2. scx

Top-line facts:

- Latest perf corpus: `85` programs, `compile_pairs=25`, `measured_pairs=0`.
- Older load-only census: `60 load_failed`, `10 recompile_load_failed`, `7 applied`, `8 no_sites`.
- Program mix in the load-only census: `60 struct_ops`, `11 syscall`, `7 tracepoint`, `7 tracing`.

Representative object-load failures:

- `scx_flash_main.bpf.o` and `scx_lavd_main.bpf.o` fail after `struct_ops` relocation, then report:
  - `failed to open system Kconfig`
  - `bpf_object__load failed: Invalid argument`
- `scx_rusty_main.bpf.o` is better behaved, but the older load-only census still shows `10 recompile_load_failed` programs in the recompile lane.

What this means:

- `scx` is not an ordinary `test_run` target. The important objects are `sched_ext` `struct_ops` schedulers.
- Even when the object loads, the honest measurement path requires scheduler registration, activation, health checks, and a real scheduler workload.
- That is why the latest perf corpus can compile/load `25` programs but still measures `0`: compile success is not enough for `sched_ext`.

Kernel support vs loader issue:

- This is not a simple "kernel `7.0-rc2` does not support `scx`" story.
- The local authoritative e2e result uses `scx_rusty_loader`, not the generic path:
  - `e2e/cases/scx/case.py:753-771`
  - `e2e/results/scx_authoritative_20260329.json:180-184`
- That same result explicitly states that raw `bpftool struct_ops register` is not a usable end-to-end loader here.
- The same result also shows the kernel registering `sched_ext_ops rusty` successfully in the authoritative path: `e2e/results/scx_authoritative_20260329.json:340-343`.

Verdict:

- Root cause: mostly loader / lifecycle / scheduler-registration semantics.
- Kernel support: sufficient for at least `scx_rusty`; not fundamentally blocked by `7.0-rc2`.
- Generic loader repair: only partly. It may be possible to grow scheduler-specific bring-up, but that is no longer "generic".
- Recommended loader: use the original scheduler binaries (`scx_rusty`, and similarly per-scheduler app loaders if needed).

### 3. KubeArmor

Top-line facts:

- Latest perf corpus: `63` programs, `compile_pairs=0`, `measured_pairs=0`.
- Older load-only census: all `63` programs are `load_failed`.
- Program mix in the load-only census: `51 kprobe`, `8 lsm`, `4 tracepoint`.

Representative object-load failure:

- All three KubeArmor objects (`system_monitor.bpf.o`, `enforcer.bpf.o`, `protectproc.bpf.o`) fail with the same pattern:
  - libbpf tries to use `/home/yunwei37/workspace/bpf-benchmark/vendor/linux/vmlinux` as the target BTF,
  - that file does not contain a `.BTF` section,
  - CO-RE relocation fails with `-ENODATA`,
  - then `bpf_object__load failed: No data available`.

This is the key conclusion:

- KubeArmor is failing before verifier policy or hook semantics even matter.
- The failure is a generic loader / CO-RE target-BTF problem, not evidence that kernel `7.0-rc2` lacks support for KubeArmor's `kprobe` / `lsm` / `tracepoint` hooks.

Original loader evidence:

- `system_monitor` loads its own object file via `LoadCollectionSpec(...)` and `NewCollectionWithOptions(...)` in `runner/repos/KubeArmor/KubeArmor/monitor/systemMonitor.go:556-567`.
- `enforcer` uses a `bpf2go`-generated embedded `CollectionSpec` and `LoadAndAssign(...)` in `runner/repos/KubeArmor/KubeArmor/enforcer/bpflsm/enforcer_bpfel.go:49-75`.
- The enforcer then attaches the resulting programs via `AttachLSM(...)` in `runner/repos/KubeArmor/KubeArmor/enforcer/bpflsm/enforcer.go:133-183`.
- `protectproc` does the same pattern in `runner/repos/KubeArmor/KubeArmor/presets/protectproc/preset.go:100-110`.

Verdict:

- Root cause: loader environment bug, specifically wrong target BTF / CO-RE setup.
- Kernel support: no evidence that `7.0-rc2` is the blocker.
- Generic loader repair: likely yes, if the CO-RE target BTF is fixed for KubeArmor's path.
- Recommended loader: the original KubeArmor loader is probably the right replacement, because the repo already has app-specific load and attach logic. However, unlike Tracee/scx/Tetragon, this tree does not yet contain a local authoritative KubeArmor e2e result, so "works end-to-end here" is still unvalidated.

### 4. Tetragon

Top-line facts:

- Latest perf corpus: `90` programs, `compile_pairs=82`, `measured_pairs=13`, `comparable_pairs=4`.
- Older load-only census: `76 load_failed`, `7 applied`, `7 no_sites`.
- Program mix in the load-only census: `52 kprobe`, `15 raw_tracepoint`, `11 tracepoint`, `8 lsm`, `3 tracing`, `1 unspec`.

Older object-load failures:

- Most older failures match the KubeArmor pattern exactly:
  - generic objects such as `bpf_execve_event.bpf.o`, `bpf_generic_kprobe.bpf.o`, `bpf_generic_lsm_core.bpf.o`, `bpf_generic_uprobe.bpf.o`, and others fail CO-RE relocation because `vendor/linux/vmlinux` lacks `.BTF`.
- One separate edge remains:
  - `bpf_execve_map_update.bpf.o` reports `missing BPF prog type, check ELF section name 'seccomp'` and then `Invalid argument`.

The important cross-check is the latest perf run:

- The latest perf corpus already compiles `82/90` Tetragon programs on the same kernel.
- Therefore the older "cannot load" picture was mostly a loader-side BTF-path bug, not a hard kernel limitation.
- What remains is mostly attach-trigger coverage: many Tetragon objects now compile, but the generic harness still does not fire them honestly or frequently enough to become measured/comparable.

Original loader evidence:

- The authoritative e2e path explicitly uses `mode = tetragon_daemon` in `e2e/cases/tetragon/case.py:1155-1170`.
- The result file `e2e/results/tetragon_authoritative_20260329.json` shows `/usr/local/bin/tetragon` loading real sensors, including:
  - `Loaded generic kprobe sensor: /usr/local/lib/tetragon/bpf/bpf_multi_kprobe_v612.o -> kprobe_multi`
  - `Loaded generic tracepoint program: /usr/local/lib/tetragon/bpf/bpf_generic_tracepoint_v612.o -> syscalls/sys_enter_execve`
- The same authoritative result contains `8` loaded Tetragon programs and `2` selected measured programs, which is already a better fit than the generic packet corpus for honest end-to-end measurement.

Verdict:

- Root cause: mostly attach-trigger coverage, not raw load support, in the current state.
- Kernel support: mostly present on `7.0-rc2`; the remaining obvious exception is the `seccomp`-named object that the generic path still cannot classify/load.
- Generic loader repair: yes, and a large part of that repair has effectively already happened between the older load-only census and the latest perf corpus.
- Recommended loader: use the real Tetragon daemon for honest measurement; keep the generic loader only for auxiliary load-only or narrow attach cases.

## Practical Recommendation

If the goal is to raise honest measured coverage rather than just "compile/load" counts:

1. `tracee`: stop treating it as a packet corpus target; use the Tracee daemon loader.
2. `scx`: do not try to measure `sched_ext` through a generic packet loader; use scheduler-native binaries.
3. `KubeArmor`: first fix the generic CO-RE target BTF issue; then prefer the app-native loader because the repo already has explicit `LoadCollectionSpec` / `LoadAndAssign` / `AttachLSM` logic.
4. `tetragon`: keep the improved generic load path, but do actual performance measurement through the Tetragon daemon and tracing policies.

## Bottom Line

For these four repos, the dominant story is not "kernel `7.0-rc2` is missing support".

- `tracee`: measured gap is almost entirely a generic-harness mismatch.
- `scx`: measured gap is a `struct_ops` / `sched_ext` lifecycle problem.
- `KubeArmor`: measured gap is a concrete loader/BTF bug.
- `tetragon`: old load failures were mostly loader-side and are already largely fixable; the remaining gap is attach-trigger coverage.

So the highest-value next step is not patching `vendor/linux-framework`. It is choosing the right loader model per repo:

- app-native loader for `tracee`, `scx`, and `tetragon`,
- and probably app-native loader plus BTF-path cleanup for `KubeArmor`.
