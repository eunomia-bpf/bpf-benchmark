# Arm64 Native-Kernel Corpus Bring-Up Plan

Date: 2026-05-29

Scope: make all six supported corpus apps run on arm64 with the
native-kernel path (`native_kernel` / native-post) through the normal app
startup path:

- `bcc/set`
- `otelcol-ebpf-profiler/profiling`
- `cilium/agent`
- `tetragon/observer`
- `katran`
- `tracee/monitor`

This plan keeps the existing benchmark contract: the apps load their own BPF
programs, the shim/native-loader swaps matching live programs to native sidecar
objects, and all benchmark execution goes through `make <target>`. It must not
add app/program filters, direct `.bpf.o` framework loaders, custom replacement
app binaries, fallback-to-BPF behavior, or framework-side performance
summaries.

## Hard Constraints

These constraints are mandatory for implementation:

- Do not ask for confirmation during bring-up. If the active code path is wrong
  and the fix is local, implement the smallest forward fix and record it.
- Build arm64 artifacts only on the host via cross-build. QEMU is a
  runtime-only validation environment.
- Never compile inside QEMU. QEMU runs must consume the host-built runtime image
  and staged artifacts.
- Do correctness before performance. Each app must first pass functional
  native-post validation by itself.
- Bring up exactly one corpus app at a time. Do not run all six apps until all
  individual app smokes pass.
- Run a final arm64 micro regression after corpus bring-up. The work is not
  complete until `native_kernel` micro still passes, proving the corpus changes
  did not break the existing micro path.
- Keep code changes as small as possible. Every step must report the exact
  files changed, why each change was needed, and how it was validated.
- Keep loader/shim unchanged by default. Loader/shim edits are allowed only for
  architecture-independent x86-parity bugs already required by the working x86
  path. Do not add arm64-specific loader/shim behavior unless there is no
  smaller correct option, and record the proof.
- Put arm64-specific runtime mechanics in native-link whenever possible:
  AArch64 instruction lowering, relocation patching, helper ABI handling,
  map-site lowering, and tail-call lowering belong there.
- Build plumbing may be arch-parametric in `runner/mk/build.mk` and
  `vendor/bpf/Makefile`; tracing compile compatibility may be arch-parametric
  in `vendor/bpf/native_compat.h`. Those changes must stay narrow.
- Preserve fail-fast behavior. Missing helper/map/tail-call/instruction support
  must fail the host build, proof-link, or QEMU run visibly; do not add silent
  fallbacks.
- Preserve performance as a design constraint. Do not add permanent debug-only
  syscalls, logging, sleeps, broad symbol scans, or extra runtime work on hot
  paths. Temporary instrumentation must be removed or guarded before the step is
  considered complete.
- Every step must leave test data in the repo's normal result/artifact
  locations and add a written record to this document or a linked
  `docs/tmp/...` note. Record raw data and artifact paths, not framework-side
  summaries.

## Required Step Record

After every implementation step, append a record with this information:

```text
Step:
Date:
Goal:
Files changed:
Technical decision:
Implementation approach:
Why this is the smallest correct change:
Host cross-build command:
Host build artifact paths:
QEMU runtime command:
QEMU result path:
Raw correctness data:
Raw workload/BPF data, if collected:
Failures observed:
Follow-up:
```

`Raw correctness data` must include at least app status, baseline/post status,
native-loader replacement/failure lines or counts, workload error fields where
available, and the result directory. Performance data must remain raw workload
payloads or raw BPF counter deltas; do not add framework-side ratios or
rollups.

## Current State

### x86 baseline

x86 KVM is the working reference:

- `docs/eval_native.md` records complete native-post corpus runs for all six
  apps.
- `corpus/results/x86_kvm_corpus_20260527_015711_134639/metadata.json` is a
  completed six-app native-post workload run with `BPFREJIT_CORPUS_BPF_STATS=0`.
- x86 native sidecars are staged under
  `vendor/build/native-bpf/x86/stage/<app>/manifest.json`.
- The runtime image copies that stage through
  `runner-runtime-host-native-bpf` into
  `/artifacts/user/native-bpf/x86_64/`.

The x86 path is also the source of several required corpus behaviors:

- no-match live programs must pass through unless they are real errors;
- original program fds must remain available for app-side metadata and
  `BPF_OBJ_GET_INFO_BY_FD` expectations;
- fd reuse must not corrupt shim bookkeeping;
- Tetragon runtime helper programs and map-id disambiguation must remain
  handled without excluding benchmark programs.

One audit item is already visible: `docs/eval_native.md` describes the
no-match pass-through fix, but current `bpfopt/shim/shim_native_loader.h` still
calls `shim_native_loader_fatal()` when `result.replaced == 0`. During bring-up,
audit whether that is the active code path. If it is active and contradicts the
working x86 semantics, fix it forward with the smallest architecture-neutral
change and record the test data. Do not stop to request confirmation.

### arm64 baseline

arm64 has the lower native-kernel machinery, but not the corpus app sidecar
pipeline:

- `docs/micro-bench-status.md` records successful arm64 AWS micro results for
  `kernel` vs `native_kernel` on both pure-bytecode and helper/map suites with
  zero expected-result mismatches.
- `module/arm64/bpf_arm64_native_lab.c` provides the arm64 native-lab kernel
  module. It uses debugfs blob upload, arm64 register ABI glue, and no `.relocs`
  sidecar path.
- `native-sim/libnativeloader/src/native_loader.cpp` has arm64 runtime support
  and passes `__native_arm64_thread_info_cpu_offset` into native-link.
- `native-sim/x86/native_lab/native_link` supports both x86_64 and AArch64 ELF
  inputs; the arm64 binary is cross-built at
  `native-sim/x86/native_lab/native_link/target/aarch64-unknown-linux-gnu/release/native-link`.
- `runner/mk/build.mk` already builds arm64 kernel, kinsn module, shim, runner,
  native-loader shared library, micro programs, stage2 programs, sim proofs,
  bpfopt, and app binaries/BPF objects for the arm64 runtime image.

The missing piece is corpus native sidecars. Today:

- `NATIVE_BPF_ARTIFACTS_ARM64 := $(RUNNER_DIR)/build-native-bpf-arm64`.
- `host-native-bpf-arm64` only runs `install -d`.
- `arm64-runner-runtime-image-tar` copies that empty directory into
  `/artifacts/user/native-bpf/arm64/`.
- `runner/libs/app_runners/native_loader_env.py` expects
  `/opt/bpf-benchmark/native-bpf/arm64/<app>/manifest.json` when native loader
  is enabled.

So an arm64 native-post corpus run cannot currently find any app manifests.
This is the first hard blocker.

## x86 vs arm64 Gap Table

| Layer | x86 status | arm64 status | Gap |
| --- | --- | --- | --- |
| App startup model | Real upstream apps, shim/native-loader sidecars | Same app model available | Keep unchanged; no framework loaders |
| Runtime image | Stages six native manifest bundles | Copies an empty native-bpf dir | Build and stage arm64 manifests |
| App binaries/BPF objects | Built under `vendor/build/x86` | Built under `vendor/build/arm64` | App artifacts mostly exist |
| Native sidecar Makefile | Produces x86 sidecars for six apps | `vendor/bpf/Makefile` has many x86 literals | Generalize arch-specific headers, includes, source roots, and target flags |
| vmlinux headers | `targets/x86/.../vmlinux.h`, BCC x86 header, Tetragon x86 header | Tetragon arm64 generated header exists, but Makefile still wires x86; no arm64 BCC target header | Generate/use arm64 headers from target kernel BTF |
| `native_compat.h` | x86 `pt_regs` fields | Defines `bpf_target_arm64` but still uses x86 `pt_regs` fields | Add real arm64 `PT_REGS_*` mappings |
| native-link | Mature x86 path, including tail-call inline lowering | AArch64 path handles core rewrite/helper/map cases, but no observed arm64 tail-call lowering | Implement/verify arm64 tail-call lowering and real-app instruction forms |
| native-lab module | x86 module with relocs sidecar support | arm64 module works for micro, no relocs sidecar | Keep arm64 no-relocs contract; lower/patch all runtime sites in native-link |
| Corpus validation | Six-app native-post completed | Only micro `native_kernel` completed | App-by-app arm64 corpus bring-up |

## Primary Blockers

1. Arm64 native app artifacts are not built or staged.

   `runner/mk/build.mk` intentionally builds many arm64 components, but
   `host-native-bpf-arm64` is currently a placeholder. The container therefore
   lacks all six `/opt/bpf-benchmark/native-bpf/arm64/<app>/manifest.json`
   files.

2. `vendor/bpf/Makefile` is still x86-centric.

   It has useful arch knobs (`ARCH`, `GOARCH`, `NATIVE_TARGET_FLAGS`,
   `NATIVE_ARCH_CFLAGS`) but many rules hardcode:

   - `bcc/libbpf-tools/x86/vmlinux.h`
   - `tetragon/bpf/include/vmlinux_generated_x86.h`
   - `-D__TARGET_ARCH_x86`
   - `-I/usr/include/x86_64-linux-gnu`
   - `--source-object-root "$(VENDOR)/build/x86/tetragon"`
   - x86 host `NATIVE_LINK` default

3. Arm64 native tracing compatibility is incomplete.

   `vendor/bpf/native_compat.h` sets `bpf_target_arm64`, but `PT_REGS_PARM*`,
   `PT_REGS_RC`, `PT_REGS_SP`, and `PT_REGS_IP` still use x86 fields such as
   `di`, `si`, `dx`, `ax`, and `ip`. This can either fail compilation or load
   native tracing code that reads the wrong context fields.

4. Arm64 native-link lacks x86-equivalent tail-call lowering.

   x86 native-link has explicit `bpf_tail_call` detection, frame planning, and
   inline lowering using `__native_x86_bpf_prog_bpf_func_offset` plus
   `__native_x86_tail_call_offset`. The arm64 link schema currently only passes
   `__native_arm64_thread_info_cpu_offset`. Tail calls are central for OTEL,
   Cilium, Tetragon, and Tracee, so arm64 all-app support should not be called
   complete until this is implemented or proven unnecessary by a real-app run.

5. Real app AArch64 codegen is not proven.

   Micro objects do not cover every instruction/relocation pattern emitted by
   the corpus app native builds. AArch64 native-link already fails fast on
   unsupported forms such as unhandled ADR/ADRP/LDR literal patterns. The right
   implementation is to add the missing lowering/patching support, not to
   suppress app codegen or fall back at runtime.

## Implementation Plan

### Complete TODO Checklist

Work through this checklist in order. Do not skip ahead to all-app or
performance runs.

1. Record initial state.
   - Capture `git status --short`.
   - Record the current x86 reference artifact paths.
   - Record current arm64 micro `native_kernel` artifact paths.
   - Verify locally that `PLATFORM=qemu ARCH=arm64 make test` is the intended
     local runtime-only correctness entrypoint.

2. Host cross-build prerequisites.
   - Build arm64 kernel/runtime image from the host only.
   - Build arm64 shim/native-loader shared library from the host only.
   - Build arm64 native-link from the host only.
   - Build arm64 app binaries/BPF objects from the host only.
   - Build arm64 native sidecar artifacts from the host only.
   - Record all commands and artifact paths.

3. QEMU runtime-only smoke.
   - Run `PLATFORM=qemu ARCH=arm64 make test`.
   - Run `PLATFORM=qemu ARCH=arm64 make micro` only after the test suite
     passes.
   - Record result directories and raw pass/fail data.
   - If QEMU invokes a compiler or build command, stop and fix the host-build
     plumbing before continuing.

4. One-app corpus correctness ladder.
   - Run exactly one app per QEMU corpus command.
   - Use `SAMPLES=1` and short `WORKLOAD_DURATION` for initial correctness.
   - Record baseline/post status, app status/error, native-loader replacement
     evidence, and raw workload error fields.
   - Do not run the next app until the current app has a clean correctness
     record.

5. Native-linker-first fixes.
   - For AArch64 instruction, relocation, helper, map-site, or tail-call
     failures, fix native-link first.
   - If a build Makefile or `native_compat.h` change is needed, keep it
     arch-parametric and local.
   - Do not add app filters, loader fallback, or shim arm64 special cases.

6. Loader/shim parity fixes.
   - If loader/shim behavior differs from the proven x86 behavior, fix the
     architecture-neutral bug with the smallest change.
   - Record before/after test data on x86 if the behavior can affect x86.
   - Record QEMU arm64 data for the app that exposed the issue.

7. App order.
   - `bcc/set`
   - `katran`
   - `otelcol-ebpf-profiler/profiling`
   - `cilium/agent`
   - `tetragon/observer`
   - `tracee/monitor`

8. All-app QEMU run.
   - Run only after all six individual app records pass.
   - Keep this as functional validation first, not performance interpretation.
   - Record raw result paths and status data.

9. Final micro regression.
   - Run `PLATFORM=qemu ARCH=arm64 make micro` after all app fixes and all-app
     qemu corpus validation.
   - Record the micro result directory, runtime list, sample count, and raw
     expected-result mismatch data.
   - If the micro result regresses or fails, fix that before any AWS or
     performance run.

10. Performance validation.
   - Run only after correctness is stable.
   - Keep performance-sensitive implementation choices documented.
   - Store raw BPF counters and raw workload payloads only. Analysis can happen
     outside the framework.

### Phase 0: freeze x86 parity requirements

Goal: make sure arm64 is porting the working x86 semantics, not an older broken
state.

Tasks:

- Audit the current shim/native-loader tree against the x86 native evaluation
  fixes listed in `docs/eval_native.md`:
  no-match pass-through, original fd preservation/prog-info redirect, fd reuse,
  and Tetragon runtime helper/map-id handling.
- Fix the visible no-match fatal path in
  `bpfopt/shim/shim_native_loader.h` if it is still the active code path.
- Add only behavior tests or focused smoke coverage that catch real regressions
  in those semantics. Do not add tautological unit tests.
- Do not ask for confirmation when a minimal x86-parity fix is clear.

Acceptance:

- Existing x86 native-post app smokes still pass through `make corpus` with the
  native loader enabled.
- The shim does not invent app/program exclusions. Only explicitly documented
  x86-parity runtime/probe helper cases may pass through; unexpected manifest
  mismatches and native-loader failures must fail visibly.
- The step record includes changed files, commands, result paths, and raw
  before/after evidence.

### Phase 1: build and stage arm64 native sidecars

Goal: `arm64-runner-runtime-image-tar` contains the same six manifest bundle
shape that x86 has today.

Tasks:

- Change `NATIVE_BPF_ARTIFACTS_ARM64` to mirror x86, preferably:

  ```make
  NATIVE_BPF_ARTIFACTS_ARM64 := $(VENDOR_BUILD_DIR)/native-bpf/arm64/stage
  ```

- Replace the placeholder `host-native-bpf-arm64` rule with a real
  `vendor/bpf` build invocation. It should depend on the arm64 Rust/native-link
  build, arm64 kernel BTF, app artifacts, and sysroot inputs already owned by
  `build.mk`.
- Pass target-specific knobs into `vendor/bpf` rather than adding a second
  side pipeline:

  ```sh
  ARCH=arm64
  GOARCH=arm64
  VMLINUX_BTF=$(HOST_KERNEL_VMLINUX_ARM64)
  BPFTOOL=$(VENDOR_BUILD_DIR)/x86/bpftool/bin/bpftool
  NATIVE_LINK=$(NATIVE_LINK_DIR)/target/$(ARM64_RUST_TARGET)/release/native-link
  NATIVE_SYS_INCLUDE_FLAGS="$(ARM64_SYS_INCLUDE_FLAGS)"
  ```

- Keep the Docker image layering contract: native sidecars belong in the app
  artifact layer, not in Python/runtime layers.
- The host cross-build entrypoint for a full runtime image is:

  ```sh
  make arm64-runner-runtime-image-tar
  ```

  This target must complete before any qemu corpus correctness run is counted.

Acceptance:

- Host build produces:

  ```text
  vendor/build/native-bpf/arm64/stage/bcc/manifest.json
  vendor/build/native-bpf/arm64/stage/katran/manifest.json
  vendor/build/native-bpf/arm64/stage/otelcol-ebpf-profiler/manifest.json
  vendor/build/native-bpf/arm64/stage/cilium/manifest.json
  vendor/build/native-bpf/arm64/stage/tetragon/manifest.json
  vendor/build/native-bpf/arm64/stage/tracee/manifest.json
  ```

- The arm64 runtime image contains those files under
  `/opt/bpf-benchmark/native-bpf/arm64/<app>/manifest.json`.
- No compiler, linker, Cargo, Go, CMake, or app build command runs inside QEMU.
- The step record includes the host cross-build command, the runtime image tar,
  and staged manifest paths.

### Phase 2: make `vendor/bpf` truly arch-parametric

Goal: the same `native-artifacts` target works for x86 and arm64.

Tasks:

- Introduce local Makefile variables for the target arch define and system
  include directory:

  ```make
  TARGET_ARCH_DEFINE := $(if $(filter arm64 aarch64,$(ARCH)),__TARGET_ARCH_arm64,__TARGET_ARCH_x86)
  BPF_TARGET_ARCH := $(if $(filter arm64 aarch64,$(ARCH)),arm64,x86)
  NATIVE_SYS_INCLUDE_FLAGS ?= -I/usr/include -I/usr/include/x86_64-linux-gnu
  ```

  Wire arm64 callers to pass
  `-I/usr/aarch64-linux-gnu/include` and the extracted aarch64 sysroot include
  paths.

- Generalize vmlinux header targets:

  - `targets/$(ARCH)/$(KERNEL_RELEASE)/vmlinux.h`
  - `bcc/libbpf-tools/$(ARCH)/vmlinux.h`
  - `tetragon/bpf/include/vmlinux_generated_$(ARCH).h`

- Use target-kernel BTF from `$(HOST_KERNEL_VMLINUX_ARM64)` for arm64 header
  generation. Do not use host `/sys/kernel/btf/vmlinux` for arm64 cross builds.
- Replace `-D__TARGET_ARCH_x86` with `-D$(TARGET_ARCH_DEFINE)` in native
  Tracee/Tetragon/BCC app compiles.
- Replace `BPF_TARGET_ARCH=x86` with `BPF_TARGET_ARCH=$(BPF_TARGET_ARCH)`.
- Use `$(VENDOR)/build/$(ARCH)/tetragon` for Tetragon manifest
  source-object-root.
- Keep Makefile edits minimal and local. Use the existing `install -d` pattern
  for output directories.

Acceptance:

- `ARCH=x86 make -C vendor/bpf native-artifacts` remains compatible with the
  current x86 artifact layout.
- The arm64 invocation reaches native compile/proof-link for each app instead
  of failing on x86 header paths.
- The step record includes exact Makefile variable choices and the host
  cross-build output paths.

### Phase 3: add real arm64 tracing compatibility

Goal: native tracing/security apps compile and read arm64 contexts correctly.

Tasks:

- Split `vendor/bpf/native_compat.h` `PT_REGS_*` fields by target arch.
- For arm64, map parameters and return state to the target kernel's generated
  `struct pt_regs` layout:

  ```c
  PT_REGS_PARM1(ctx) -> regs[0]
  PT_REGS_PARM2(ctx) -> regs[1]
  PT_REGS_PARM3(ctx) -> regs[2]
  PT_REGS_PARM4(ctx) -> regs[3]
  PT_REGS_PARM5(ctx) -> regs[4]
  PT_REGS_PARM6(ctx) -> regs[5]
  PT_REGS_RC(ctx)    -> regs[0]
  PT_REGS_SP(ctx)    -> sp
  PT_REGS_IP(ctx)    -> pc
  PT_REGS_FP(ctx)    -> regs[29]
  PT_REGS_RET(ctx)   -> regs[30]
  ```

- Verify those field names against the arm64 generated `vmlinux.h` before
  committing the mapping.
- Keep the helper-call placeholder macros fail-fast. Missing helper support
  should stop native-link or load, not silently route through another path.

Acceptance:

- Tracee and Tetragon native objects compile for arm64 with
  `-D__TARGET_ARCH_arm64`.
- The generated native code no longer references x86 `pt_regs` fields.
- The step record includes the generated arm64 `vmlinux.h` field evidence and
  the native object paths that proved the mapping.

### Phase 4: close arm64 native-link gaps with proof-link first

Goal: every arm64 sidecar symbol needed by the six apps can be proof-linked
before runtime image assembly.

Tasks:

- Run the per-object proof-link markers already used by `vendor/bpf/Makefile`;
  let unsupported AArch64 forms fail the build.
- Add AArch64 lowering only for real failures encountered in app sidecars.
  Expected areas:

  - ADRP+ADD / ADRP+LDR sequences for local data or compiler-emitted literals;
  - LDR literal forms not covered by micro;
  - conditional branches that target return trampolines;
  - direct calls to compiler builtins or lowered memory ops;
  - map lookup/update site shapes beyond current micro coverage;
  - helper call argument/return ABI mismatches.

- Implement x86-equivalent arm64 tail-call lowering if proof-link/runtime
  evidence confirms `bpf_tail_call` sites are present. The design should:

  - pass arm64 `struct bpf_prog::bpf_func` offset and arm64 tail-call entry
    offset through the link schema;
  - enforce the kernel max tail-call count;
  - jump to the callee native entry after restoring the caller frame as needed;
  - keep caller accounting semantics intact.

- Preserve the arm64 native-lab no-relocs contract. If a native object emits
  relocations that the current arm64 module cannot upload, native-link should
  lower or patch them into the final blob, not introduce a fallback path.

Acceptance:

- `native-link --mode proof` succeeds for every staged arm64 native sidecar
  symbol included in the manifest.
- Tail-call-heavy app objects either have correct arm64 lowering or fail before
  runtime image creation with a clear error.
- The step record lists each unsupported AArch64 form encountered, the selected
  lowering strategy, the proof-link command, and the produced proof object.

### Phase 5: app-by-app arm64 corpus bring-up

Bring apps up one at a time. Use short smokes first, then paper-grade settings
after all functional issues are fixed. Always use the repository Makefile for
benchmark execution. The first correctness pass must use qemu arm64, not AWS,
and qemu must run only host-built artifacts.

Before each app:

- run or reuse the host arm64 cross-build that produces the runtime image tar;
- verify the app's arm64 native manifest exists in the staged native-bpf tree;
- verify the qemu root comes from the host-built runtime image;
- record the host build command and artifact paths.

Recommended order:

1. `bcc/set`

   Lowest-risk tracing subset. It validates arm64 headers, BCC include paths,
   native manifest lookup, shim replacement, and basic helper calls without the
   heaviest tail-call graph.

   QEMU correctness smoke:

   ```sh
   PLATFORM=qemu ARCH=arm64 \
   BPFREJIT_CORPUS_APPS=bcc/set \
   BPFREJIT_SHIM_NATIVE_LOADER=post SKIP_REJIT=norejit \
   SAMPLES=1 WORKLOAD_DURATION=10 TIMEOUT=3600 \
   make corpus
   ```

2. `katran`

   XDP app with a smaller object set. It validates arm64 XDP context handling,
   map lookup/update lowering, and standalone attach mode.

   QEMU correctness smoke:

   ```sh
   PLATFORM=qemu ARCH=arm64 \
   BPFREJIT_CORPUS_APPS=katran \
   BPFREJIT_SHIM_NATIVE_LOADER=post SKIP_REJIT=norejit \
   SAMPLES=1 WORKLOAD_DURATION=10 TIMEOUT=3600 \
   make corpus
   ```

3. `otelcol-ebpf-profiler/profiling`

   This is the first tail-call-critical app. It should not be treated as passed
   unless `native_tracer_entry` runs and the unwind chain behavior is
   consistent with x86 native-post expectations.

4. `cilium/agent`

   Validates map-in-map/prog-array-heavy datapath behavior, no-match
   pass-through, and manifest disambiguation. It is likely to expose missing
   arm64 tail-call lowering or map helper shape issues.

5. `tetragon/observer`

   Validates the broadest tracing-program matrix, arm64 `pt_regs`, runtime
   helper pass-through, and Tetragon source-object-root disambiguation.

6. `tracee/monitor`

   Largest tracing/security corpus. Run after Tracee native compile, arm64
   helper coverage, and tail-call handling are stable.

For apps 3-6, use the same smoke shape as above with
`BPFREJIT_CORPUS_APPS=<app>`.

Acceptance per app:

- app status is `ok`;
- baseline and post workload phases both complete;
- native loader reports real replacements for manifest-backed programs;
- no native-loader failure/no-manifest/reloc/fallback errors;
- workload `error_count`-style raw fields remain zero where the app reports
  them;
- no framework-side app or program exclusions were added.
- the step record includes host build command, qemu command, result directory,
  app raw status/error fields, native-loader evidence, workload raw data, and
  any BPF counter raw data collected.

### Phase 6: all-app arm64 validation

After all per-app qemu smokes pass, run the full arm64 corpus in qemu first.
AWS runs are only for later authoritative validation, not the first functional
bring-up.

QEMU functional all-app run:

```sh
PLATFORM=qemu ARCH=arm64 \
BPFREJIT_SHIM_NATIVE_LOADER=post SKIP_REJIT=norejit \
BPFREJIT_CORPUS_BPF_STATS=1 \
SAMPLES=1 WORKLOAD_DURATION=30 TIMEOUT=7200 \
make corpus
```

QEMU workload-overhead run without BPF stats:

```sh
PLATFORM=qemu ARCH=arm64 \
BPFREJIT_SHIM_NATIVE_LOADER=post SKIP_REJIT=norejit \
BPFREJIT_CORPUS_BPF_STATS=0 \
SAMPLES=1 WORKLOAD_DURATION=30 TIMEOUT=7200 \
make corpus
```

AWS authoritative run, only after qemu correctness is stable:

```sh
PLATFORM=aws ARCH=arm64 \
BPFREJIT_SHIM_NATIVE_LOADER=post SKIP_REJIT=norejit \
BPFREJIT_CORPUS_BPF_STATS=0 \
SAMPLES=3 WORKLOAD_DURATION=180 TIMEOUT=7200 \
make corpus
```

Use the documented AWS defaults: `t4g.small` for corpus. Escalate only to
`t4g.medium` for documented OOM mitigation, never for variance or throughput.

Acceptance:

- QEMU all-app result completes before any AWS all-app result is treated as
  meaningful.
- The record includes qemu raw result paths and, later, AWS raw result paths.
- No implementation step is marked complete without test data.

### Phase 7: performance guardrails

Goal: keep the arm64 path fast while preserving correctness and the raw-result
framework contract.

Tasks:

- Prefer native-link lowering that produces direct AArch64 code over adding
  runtime helper indirection when the x86 path already emits inline native
  logic.
- Do not add permanent hot-path logging in shim, native-loader, or native-lab
  execution.
- Do not add per-load broad scans that can be replaced by manifest identity,
  existing map metadata, or link-time records.
- If temporary debug output is needed, guard it behind an explicit debug knob
  and remove it from the normal path before the step is complete.
- For each app after correctness passes, collect raw workload payloads with
  `BPFREJIT_CORPUS_BPF_STATS=0` and raw BPF counters with
  `BPFREJIT_CORPUS_BPF_STATS=1` before calling the app performance-ready.
- Keep all performance interpretation outside the benchmark framework.

Acceptance:

- The step record names every performance-sensitive choice made in native-link,
  build plumbing, or compatibility code.
- Raw qemu or AWS result paths are recorded for stats-on and stats-off runs
  when performance validation is performed.
- No framework code computes ratios, geomeans, win/loss counts, or summaries.

### Phase 8: final micro regression

Goal: prove the corpus arm64 changes did not break the already-working arm64
micro `native_kernel` path.

Tasks:

- Run this after all per-app qemu corpus smokes and the qemu all-app corpus run:

  ```sh
  PLATFORM=qemu ARCH=arm64 SAMPLES=1 WARMUPS=0 INNER_REPEAT=100000 make micro
  ```

- Record the raw result directory under `micro/results`.
- Record runtime names, sample count, benchmark count, app-independent
  correctness status, and expected-result mismatch count.
- If this fails, stop all corpus performance work and fix the micro regression
  first.
- After qemu micro passes, an AWS arm64 micro run may be collected as an
  authoritative portability/performance check:

  ```sh
  PLATFORM=aws ARCH=arm64 SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000 make micro
  ```

Acceptance:

- QEMU arm64 micro completes after the corpus work with zero expected-result
  mismatches.
- The micro step record includes the host-built image artifact path and the raw
  `micro/results/...` path.
- Any AWS micro result is recorded only after qemu micro has passed.

## Definition of Done

Arm64 native-kernel all-app support is complete when:

- `make arm64-runner-runtime-image-tar` can build the runtime image with arm64
  native sidecars staged for all six apps.
- Each supported app can run through native-post mode with
  `PLATFORM=qemu ARCH=arm64 BPFREJIT_SHIM_NATIVE_LOADER=post
  SKIP_REJIT=norejit make corpus`.
- Each app has an individual qemu correctness record before the final all-app
  qemu run.
- The final six-app qemu arm64 run completes with status `completed` and
  per-app status `ok`.
- Final qemu arm64 micro regression completes after corpus validation with zero
  expected-result mismatches.
- AWS arm64 performance/authoritative runs, if collected, happen only after the
  qemu correctness ladder is complete.
- The result payload stays raw: BPF counter deltas, workload stdout/stderr,
  lifecycle logs, app status/error, and raw app workload metrics only.
- No ReJIT/native-loader filtering, per-app pass exclusions, fallback loaders,
  or framework-side performance summaries are introduced.
- Every completed implementation step has a written step record with tests,
  technical decisions, selected approach, and raw test data.

## Expected Work Items

1. Fix-forward current x86 native-loader parity gaps.
2. Generalize `runner/mk/build.mk` arm64 native sidecar staging.
3. Generalize `vendor/bpf/Makefile` arch variables and header targets.
4. Add arm64 `PT_REGS_*` support in `vendor/bpf/native_compat.h`.
5. Extend AArch64 native-link for corpus proof-link failures.
6. Add arm64 tail-call lowering if current helper-call handling is not enough
   for OTEL/Cilium/Tetragon/Tracee.
7. Host cross-build `make arm64-runner-runtime-image-tar`.
8. Run qemu runtime-only correctness tests.
9. Bring up apps in the order BCC, Katran, OTEL, Cilium, Tetragon, Tracee.
10. Run all-app arm64 native-post validation through
    `PLATFORM=qemu ARCH=arm64 make corpus`.
11. Run final arm64 qemu micro regression through
    `PLATFORM=qemu ARCH=arm64 make micro`.
12. Run AWS arm64 authoritative/performance validation only after qemu
    correctness is complete.
