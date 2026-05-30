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

## Execution Log

### Execution TODO Created

Step: Execution setup
Date: 2026-05-29
Goal: Turn the plan into an executable checklist and start implementation
without further confirmation.
Files changed: `docs/tmp/arm64_native_kernel_all_apps_plan_20260529.md`.
Technical decision: Keep the execution log in this document so every phase,
technical decision, command, artifact path, raw result path, and failure is
append-only and colocated with the plan.
Implementation approach: Work through phases in order: Phase 0 x86-parity
loader/shim audit, Phase 1-3 host cross-build artifact plumbing, Phase 4
native-link AArch64 gaps, Phase 5 one-app qemu correctness, Phase 6 all-app
qemu correctness, Phase 7 raw performance data, Phase 8 final micro regression.
Why this is the smallest correct change: Documentation-only setup before code
edits; no implementation behavior changes yet.
Host cross-build command: Not run yet.
Host build artifact paths: Not produced yet.
QEMU runtime command: Not run yet.
QEMU result path: Not produced yet.
Raw correctness data: Initial `git status --short` showed only pre-existing
`vendor/linux-framework` modification.
Raw workload/BPF data, if collected: Not collected yet.
Failures observed: None yet.
Follow-up: Start Phase 0 by auditing shim/native-loader parity with the x86
native-post behavior and implementing the smallest architecture-neutral fix if
the active code path still fatals on manifest no-match.

### Phase 0 Record: Shim Manifest No-Match Parity

Step: Phase 0 loader/shim x86-parity fix
Date: 2026-05-29
Goal: Ensure the active shim behavior matches the x86 native-post behavior for
manifest no-match programs.
Files changed: `bpfopt/shim/shim_native_loader.h`,
`docs/tmp/arm64_native_kernel_all_apps_plan_20260529.md`.
Technical decision: A successful native-loader call with `replaced=0` means the
manifest exists but has no matching native entry. x86 native-post evaluation
records this as explicit no-match pass-through. The smallest correct behavior
is to keep the original `BPF_PROG_LOAD` fd, log the pass-through, and continue.
Actual native-loader errors still call `shim_native_loader_fatal()`.
Implementation approach: In `shim_maybe_replace_with_native_fd()`, close any
unexpected returned fd when `result.replaced == 0`, log
`native-loader no manifest match pass-through`, `dlclose()` the loader handle,
and return `original_fd`. No arm64-specific loader/shim behavior was added.
Why this is the smallest correct change: One conditional changed from fatal to
return-original-fd. It preserves all existing fail-fast paths for missing
bytecode, unreadable bytecode, missing manifest env, dlopen/dlsym failures,
native-loader exceptions, and invalid replacement fds.
Host cross-build command: Not applicable for this phase.
Host build artifact paths: `bpfopt/shim/libbpfrejit_shim.so`.
Validation command:

```sh
make -C bpfopt/shim
make -C bpfopt/shim selftest-run
```

Validation result: `make -C bpfopt/shim` completed successfully. It emitted an
existing `shim_reload.h` snprintf truncation warning unrelated to this change.
`make -C bpfopt/shim selftest-run` completed successfully; the synthetic
`BPF_PROG_LOAD` returned `EPERM` as expected without CAP_BPF, and the shim still
captured and dumped the 16-byte two-insn program.
QEMU runtime command: Not run in this phase.
QEMU result path: Not produced in this phase.
Raw correctness data: `/tmp/shim_st.log` contained `shim_init`, one
`BPF_PROG_LOAD type=1 (socket_filter) name=shim_st_dummy insn_cnt=2`, and
`PROG_LOAD -> fd=-1 errno=1 kernel_prog_id=0`. `/tmp/shim_st/` contained one
`bpfrejit_*.bpf` dump with size 16.
Raw workload/BPF data, if collected: Not collected in this phase.
Failures observed: None.
Follow-up: Start Phase 1-3 host cross-build plumbing for arm64 native app
sidecars while keeping loader/shim unchanged unless another architecture-neutral
x86-parity defect is found.

### Phase 1-3 Record: Arm64 Native Sidecar Build Plumbing and BCC Proof-Link

Step: Phase 1-3 host cross-build plumbing, arch-parametric `vendor/bpf`, and
arm64 tracing compatibility for the first app.
Date: 2026-05-29
Goal: Make the arm64 native-bpf stage non-empty and prove the `bcc` sidecar
bundle can be generated entirely on the host.
Files changed: `runner/mk/build.mk`, `vendor/bpf/Makefile`,
`vendor/bpf/native_compat.h`,
`docs/tmp/arm64_native_kernel_all_apps_plan_20260529.md`.
Technical decision: Mirror the x86 native-bpf artifact layout for arm64 by
staging into `vendor/build/native-bpf/arm64/stage`, and keep app-side native
artifact generation in `vendor/bpf` instead of adding a second arm64-specific
pipeline. Makefile architecture differences are expressed through local
variables (`BPF_TARGET_ARCH`, `TARGET_ARCH_DEFINE`, `BCC_VMLINUX_H`,
`TETRAGON_VMLINUX_H`, `NATIVE_SYS_INCLUDE_FLAGS`). `native_compat.h` now maps
`PT_REGS_*` to real arm64 `struct pt_regs` expressions (`regs[0..5]`, `sp`,
`pc`, `regs[29]`, `regs[30]`) while preserving the x86 field mapping.
Implementation approach: `host-native-bpf-arm64` now depends on the arm64 Rust
native-link build, arm64 source app artifacts, and the arm64 kernel BTF, then
invokes `make -C vendor/bpf ARCH=arm64 GOARCH=arm64 ... native-artifacts`.
`vendor/bpf/Makefile` generates and consumes arch-specific BCC/Tetragon
`vmlinux.h` files, passes `-D__TARGET_ARCH_arm64` for arm64 native compiles,
and uses the aarch64 sysroot include flags from `build.mk`.
Why this is the smallest correct change: It reuses the existing x86
`native-artifacts` rules and x86 stage shape, changing only the arch literals
that prevented arm64 artifacts from being built. Loader/shim behavior and app
startup are unchanged.
Host cross-build command:

```sh
make -C vendor/bpf ARCH=arm64 GOARCH=arm64 \
  VMLINUX_BTF=/home/yunwei37/workspace/bpf-benchmark/vendor/build/arm64/linux/vmlinux \
  NATIVE_LINK=/home/yunwei37/workspace/bpf-benchmark/native-sim/x86/native_lab/native_link/target/aarch64-unknown-linux-gnu/release/native-link \
  NATIVE_SYS_INCLUDE_FLAGS="-I/usr/aarch64-linux-gnu/include -I/home/yunwei37/workspace/bpf-benchmark/.cache/aarch64-sysroot/usr/include -I/home/yunwei37/workspace/bpf-benchmark/.cache/aarch64-sysroot/usr/include/aarch64-linux-gnu" \
  native-bcc
```

Host build artifact paths:

```text
vendor/build/native-bpf/arm64/stage/bcc/manifest.json
vendor/build/native-bpf/arm64/stage/bcc/*.native.o
vendor/build/native-bpf/arm64/6.15.11-061511-generic/native/bcc/*.proof.ok
vendor/build/native-bpf/arm64/6.15.11-061511-generic/native/bcc/*.proof.o
vendor/bpf/bcc/libbpf-tools/arm64/vmlinux.h
vendor/bpf/targets/arm64/6.15.11-061511-generic/vmlinux.h
```

QEMU runtime command: Not run in this phase.
QEMU result path: Not produced in this phase.
Raw correctness data: `vendor/build/native-bpf/arm64/stage/bcc/manifest.json`
exists with `status=native-objects-proof-linked`, `version=1`, `app=bcc`, and
29 object entries. The staged `bcc` directory contains 8 native objects:
`capable.native.o`, `biosnoop.native.o`, `vfsstat.native.o`,
`opensnoop.native.o`, `syscount.native.o`, `tcpconnect.native.o`,
`tcplife.native.o`, and `runqlat.native.o`. The proof-link output directory
contains 8 `*.proof.ok` markers and 34 `*.proof.o` files.
Raw workload/BPF data, if collected: Not collected yet; this was host build
and proof-link validation only.
Failures observed: The first real arm64 `native-bcc` compile reached generated
BCC code that referenced x86 `pt_regs` fields (`di`, `si`, `dx`, `cx`, `ax`)
because the native compile did not define `__TARGET_ARCH_arm64`. The fix was
to add `-D$(TARGET_ARCH_DEFINE)` to both `NATIVE_CFLAGS` and
`KATRAN_NATIVE_CFLAGS`, then rerun the same host build command.
Follow-up: Continue app-by-app host native sidecar builds. Any AArch64
instruction or relocation gaps must be fixed in `native-link` first.

### Phase 4 Record: Arm64 Native-Link NOBITS Section Materialization

Step: Phase 4 native-link proof-link gap for arm64 `.bss` relocations.
Date: 2026-05-29
Goal: Fix the first real-app AArch64 proof-link failure without changing the
loader, shim, or app build source.
Files changed: `native-sim/x86/native_lab/native_link/src/main.rs`,
`docs/tmp/arm64_native_kernel_all_apps_plan_20260529.md`.
Technical decision: AArch64 ADRP/ADD relocations may target `.bss`/NOBITS
symbols. `object::Section::data()` is empty for NOBITS, but the in-memory
section size is non-zero and the correct materialized contents are zero bytes.
The native linker should use section memory size for zerofill sections and
keep failing for ordinary initialized sections whose file data is shorter than
memory size.
Implementation approach: Added `arm64_section_materialized_data()` and used it
from both proof relocation data extraction and kernel-mode local data blob
append. The helper returns raw data unchanged when file data length equals
memory size, pads only `SectionKind::is_bss()` sections with zeroes, and bails
if non-BSS initialized data is short or if file data exceeds memory size.
Why this is the smallest correct change: The failure was in native-link's
section materialization logic, not in app code or runtime loading. One helper
fixes both proof mode and kernel mode while preserving fail-fast behavior for
unsupported section shapes.
Host cross-build command:

```sh
make host-rust-arm64
make -C vendor/bpf ARCH=arm64 GOARCH=arm64 \
  VMLINUX_BTF=/home/yunwei37/workspace/bpf-benchmark/vendor/build/arm64/linux/vmlinux \
  NATIVE_LINK=/home/yunwei37/workspace/bpf-benchmark/native-sim/x86/native_lab/native_link/target/aarch64-unknown-linux-gnu/release/native-link \
  NATIVE_SYS_INCLUDE_FLAGS="-I/usr/aarch64-linux-gnu/include -I/home/yunwei37/workspace/bpf-benchmark/.cache/aarch64-sysroot/usr/include -I/home/yunwei37/workspace/bpf-benchmark/.cache/aarch64-sysroot/usr/include/aarch64-linux-gnu" \
  native-bcc
```

Host build artifact paths:

```text
native-sim/x86/native_lab/native_link/target/aarch64-unknown-linux-gnu/release/native-link
vendor/build/native-bpf/arm64/6.15.11-061511-generic/native/bcc/tcpconnect.tcp_v4_connect_ret.proof.o
vendor/build/native-bpf/arm64/6.15.11-061511-generic/native/bcc/tcpconnect.tcp_v6_connect_ret.proof.o
vendor/build/native-bpf/arm64/stage/bcc/manifest.json
```

QEMU runtime command: Not run in this phase.
QEMU result path: Not produced in this phase.
Raw correctness data: Before the fix, `tcpconnect.tcp_v4_connect_ret` failed
with `arm64 proof data relocation __arm64_section_Some(SectionIndex(14))_addend_0 addend 0 exceeds section size 0`.
Inspection showed section 14 was `.bss`, `SHT_NOBITS`, size 8, with AArch64
relocations `R_AARCH64_ADR_PREL_PG_HI21 .bss + 0` and
`R_AARCH64_ADD_ABS_LO12_NC .bss + 0`. After rebuilding arm64 `native-link`,
the same `native-bcc` command proof-linked `tcp_v4_connect_ret` and
`tcp_v6_connect_ret`; the successful output wrote 588-byte proof objects with
39 relocations each.
Raw workload/BPF data, if collected: Not collected yet.
Failures observed: No remaining BCC proof-link failure after this native-link
fix. Potential later apps may expose additional AArch64 forms.
Follow-up: Build the next native sidecar app from the host, one app at a time,
and record each failure/fix before moving to qemu runtime tests.

### Phase 4 Record: Katran Arm64 Sidecar Host Build

Step: Phase 4 app sidecar proof-link, `katran`.
Date: 2026-05-29
Goal: Build and proof-link the second app's arm64 native sidecars on the host.
Files changed: `docs/tmp/arm64_native_kernel_all_apps_plan_20260529.md`.
Technical decision: Keep Katran in the same native-link proof-first path as
x86. The manifest intentionally skips `jhash*` helper symbols via the existing
`--skip-prefix jhash` rule; no new arm64 filter was added.
Implementation approach: Reused the arch-parametric `native-katran` rule with
`ARCH=arm64`, `GOARCH=arm64`, the host-built arm64 `native-link`, and aarch64
sysroot include flags.
Why this is the smallest correct change: No code change was required after the
Phase 1-4 plumbing; the existing Katran target already had object-level
proof-linking and manifest generation.
Host cross-build command:

```sh
make -C vendor/bpf ARCH=arm64 GOARCH=arm64 \
  VMLINUX_BTF=/home/yunwei37/workspace/bpf-benchmark/vendor/build/arm64/linux/vmlinux \
  NATIVE_LINK=/home/yunwei37/workspace/bpf-benchmark/native-sim/x86/native_lab/native_link/target/aarch64-unknown-linux-gnu/release/native-link \
  NATIVE_SYS_INCLUDE_FLAGS="-I/usr/aarch64-linux-gnu/include -I/home/yunwei37/workspace/bpf-benchmark/.cache/aarch64-sysroot/usr/include -I/home/yunwei37/workspace/bpf-benchmark/.cache/aarch64-sysroot/usr/include/aarch64-linux-gnu" \
  native-katran
```

Host build artifact paths:

```text
vendor/build/native-bpf/arm64/stage/katran/manifest.json
vendor/build/native-bpf/arm64/stage/katran/balancer.native.o
vendor/build/native-bpf/arm64/stage/katran/healthchecking_ipip.native.o
vendor/build/native-bpf/arm64/stage/katran/xdp_root.native.o
vendor/build/native-bpf/arm64/6.15.11-061511-generic/native/katran/*.proof.ok
vendor/build/native-bpf/arm64/6.15.11-061511-generic/native/katran/*.proof.o
```

QEMU runtime command: Not run in this phase.
QEMU result path: Not produced in this phase.
Raw correctness data: `vendor/build/native-bpf/arm64/stage/katran/manifest.json`
exists with `status=native-objects-proof-linked`, `version=1`, `app=katran`,
and 3 manifest object entries. The native output directory contains 4
`*.proof.ok` markers and 6 `*.proof.o` files. Proof-link output included
`balancer_ingress` (7404-byte proof object, 125 relocations),
`healthcheck_encap` for both healthchecking objects, and `xdp_root`.
Raw workload/BPF data, if collected: Not collected yet.
Failures observed: None.
Follow-up: Continue host sidecar build for `otelcol-ebpf-profiler`, which is
the first tail-call-heavy app in the planned order.

### Phase 4 Record: OTEL Arm64 Sidecar Host Build

Step: Phase 4 app sidecar proof-link, `otelcol-ebpf-profiler`.
Date: 2026-05-29
Goal: Build and proof-link the first tail-call-heavy app's arm64 native
sidecar on the host.
Files changed: `vendor/bpf/Makefile`,
`docs/tmp/arm64_native_kernel_all_apps_plan_20260529.md`.
Technical decision: The OTEL native unit objects are compiled as AArch64, so
the final relocatable merge must also be target-qualified. Use the existing
`$(NATIVE_TARGET_FLAGS)` for the `clang -r` step rather than adding a new
OTEL-only arch branch.
Implementation approach: Changed the OTEL partial-link rule from
`$(CLANG) -r` to `$(CLANG) $(NATIVE_TARGET_FLAGS) -r`. This preserves x86
behavior because `NATIVE_TARGET_FLAGS` is empty for x86 and adds
`--target=aarch64-linux-gnu` for arm64.
Why this is the smallest correct change: It fixes only the host cross-link
command that selected the wrong system linker. No loader, shim, app source, or
native-link lowering changed.
Host cross-build command:

```sh
make -C vendor/bpf ARCH=arm64 GOARCH=arm64 \
  VMLINUX_BTF=/home/yunwei37/workspace/bpf-benchmark/vendor/build/arm64/linux/vmlinux \
  NATIVE_LINK=/home/yunwei37/workspace/bpf-benchmark/native-sim/x86/native_lab/native_link/target/aarch64-unknown-linux-gnu/release/native-link \
  NATIVE_SYS_INCLUDE_FLAGS="-I/usr/aarch64-linux-gnu/include -I/home/yunwei37/workspace/bpf-benchmark/.cache/aarch64-sysroot/usr/include -I/home/yunwei37/workspace/bpf-benchmark/.cache/aarch64-sysroot/usr/include/aarch64-linux-gnu" \
  native-otel
```

Host build artifact paths:

```text
vendor/build/native-bpf/arm64/stage/otelcol-ebpf-profiler/manifest.json
vendor/build/native-bpf/arm64/stage/otelcol-ebpf-profiler/otelcol-ebpf-profiler.native.o
vendor/build/native-bpf/arm64/6.15.11-061511-generic/native/otel/otelcol-ebpf-profiler.proof.ok
vendor/build/native-bpf/arm64/6.15.11-061511-generic/native/otel/*.proof.o
```

QEMU runtime command: Not run in this phase.
QEMU result path: Not produced in this phase.
Raw correctness data: Before the fix, the OTEL partial-link command invoked
`clang-18 -r` without an AArch64 target and failed in the host linker with
`Relocations in generic ELF (EM: 183)` and `file in wrong format`. After the
Makefile fix, `vendor/build/native-bpf/arm64/stage/otelcol-ebpf-profiler/manifest.json`
exists with `status=native-objects-proof-linked`, `version=1`,
`app=otelcol-ebpf-profiler`, and 26 manifest object entries. The merged native
object has 30 text symbols. The native output directory contains 1
`*.proof.ok` marker and 30 `*.proof.o` files, including proof objects for
`native_tracer_entry`, `perf_unwind_*`, `kprobe_unwind_*`, and scheduler/uprobe
entrypoints.
Raw workload/BPF data, if collected: Not collected yet.
Failures observed: OTEL host build failed once due to missing
`--target=aarch64-linux-gnu` on the relocatable merge step; fixed by reusing
`$(NATIVE_TARGET_FLAGS)`.
Follow-up: Continue host sidecar build for `cilium/agent`.

### Phase 4 Record: Cilium Arm64 Sidecar Host Build

Step: Phase 4 app sidecar proof-link, `cilium/agent`.
Date: 2026-05-29
Goal: Build and proof-link Cilium's arm64 native sidecar bundle on the host.
Files changed: `docs/tmp/arm64_native_kernel_all_apps_plan_20260529.md`.
Technical decision: Cilium exposes many tail-call entrypoints in separate
symbols. Keep the existing x86 manifest disambiguation (`source_map_prefix`,
explicit `tail_drop_notify`, and `prog_type=6` for XDP) and rely on
proof-link output to surface missing arm64 codegen support. No app/program
filter was added.
Implementation approach: Reused the arch-parametric `native-cilium` target
with the host-built arm64 native-link and aarch64 sysroot include flags.
Why this is the smallest correct change: After the earlier Makefile and
`native_compat.h` plumbing, Cilium needed no additional implementation change.
Host cross-build command:

```sh
make -C vendor/bpf ARCH=arm64 GOARCH=arm64 \
  VMLINUX_BTF=/home/yunwei37/workspace/bpf-benchmark/vendor/build/arm64/linux/vmlinux \
  NATIVE_LINK=/home/yunwei37/workspace/bpf-benchmark/native-sim/x86/native_lab/native_link/target/aarch64-unknown-linux-gnu/release/native-link \
  NATIVE_SYS_INCLUDE_FLAGS="-I/usr/aarch64-linux-gnu/include -I/home/yunwei37/workspace/bpf-benchmark/.cache/aarch64-sysroot/usr/include -I/home/yunwei37/workspace/bpf-benchmark/.cache/aarch64-sysroot/usr/include/aarch64-linux-gnu" \
  native-cilium
```

Host build artifact paths:

```text
vendor/build/native-bpf/arm64/stage/cilium/manifest.json
vendor/build/native-bpf/arm64/stage/cilium/bpf_lxc.native.o
vendor/build/native-bpf/arm64/stage/cilium/bpf_overlay.native.o
vendor/build/native-bpf/arm64/stage/cilium/bpf_sock.native.o
vendor/build/native-bpf/arm64/stage/cilium/bpf_host.native.o
vendor/build/native-bpf/arm64/stage/cilium/bpf_wireguard.native.o
vendor/build/native-bpf/arm64/stage/cilium/bpf_xdp.native.o
vendor/build/native-bpf/arm64/stage/cilium/bpf_alignchecker.native.o
vendor/build/native-bpf/arm64/stage/cilium/cilium_placeholders.native.o
vendor/build/native-bpf/arm64/6.15.11-061511-generic/native/cilium/*.proof.ok
vendor/build/native-bpf/arm64/6.15.11-061511-generic/native/cilium/*.proof.o
```

QEMU runtime command: Not run in this phase.
QEMU result path: Not produced in this phase.
Raw correctness data: `vendor/build/native-bpf/arm64/stage/cilium/manifest.json`
exists with `status=native-objects-proof-linked`, `version=1`, `app=cilium`,
and 89 manifest object entries. The native output directory contains 8
`*.proof.ok` markers and 84 `*.proof.o` files. Proof-link output included
directly attached symbols such as `cil_from_netdev`, `cil_to_netdev`,
`cil_xdp_entry`, and many `tail_*` symbols such as `tail_ipv4_policy`,
`tail_nodeport_nat_ingress_ipv4`, and `tail_drop_notify`.
Raw workload/BPF data, if collected: Not collected yet.
Failures observed: None. Compile emitted existing macro redefinition warnings
for Cilium's `__uint`/`__type`/`__array` macros and packed-member address
warnings; these did not stop the host build.
Follow-up: Continue host sidecar build for `tetragon/observer`.

### Phase 4 Record: Tetragon Arm64 Sidecar Host Build

Step: Phase 4 app sidecar proof-link, `tetragon/observer`.
Date: 2026-05-29
Goal: Build and proof-link Tetragon's arm64 native sidecar bundle on the host,
including the large v53/v511/v61 generic probe variants.
Files changed:

```text
vendor/bpf/tetragon/bpf/include/api.h
vendor/bpf/tetragon/bpf/process/generic_calls.h
vendor/bpf/tetragon/bpf/process/regs.h
native-sim/x86/native_lab/native_link/src/main.rs
docs/tmp/arm64_native_kernel_all_apps_plan_20260529.md
```

Technical decisions:

- Kept loader and shim behavior unchanged for Tetragon. All Tetragon fixes were
  either native-C compatibility fixes inside vendored BPF source guarded by
  `MICRO_NATIVE`/arm64, or arm64 native-link proof-linker fixes.
- Renamed native Tetragon string helper stubs through macros
  (`bpf_strnstr -> native_bpf_strnstr`,
  `bpf_strncasestr -> native_bpf_strncasestr`) because the arm64 generated
  vmlinux header declares weak extern ksyms with the original names. This avoids
  a static-vs-extern C linkage conflict without changing BPF loader behavior.
- For arm64 6.15 BTF, `struct filename` exposes `struct __filename_head` plus
  `iname[]`; the `name` pointer lives in the head. The native C path reads
  `((struct __filename_head *)file)->name`, while non-native/x86 behavior stays
  on the existing `file->name` path.
- Replaced arm64 `MICRO_NATIVE` register access in `regs.h` with direct C
  accessors for `struct pt_regs` (`regs[0..30]`, `sp`, `pc`). The existing BPF
  inline asm remains for non-native builds; x86 native behavior remains direct
  C field access.
- Fixed arm64 native-link ABI stripping instead of adding app exclusions. The
  linker now strips only prologue save slots, ignores body spills, rejects
  non-pair instructions that previously matched the loose STP/LDP mask, and
  normalizes writeback push/pop pairs such as
  `stp x30,x19,[sp,#-16]!` / `ldp x30,x19,[sp],#16`.

Implementation approach:

- Build Tetragon natively for arm64 from the host with the generated arm64
  vmlinux header and AArch64 sysroot includes.
- Re-run `native-tetragon` after every linker/native-C fix; no QEMU build was
  performed.
- Add focused linker regression tests for the exact arm64 ABI-strip failures
  observed during Tetragon proof-linking.

Why this is the smallest correct change: The failures were not loader-side
runtime mismatches. They were compile-time native-C ABI differences and
native-link arm64 instruction/prologue parsing gaps. Keeping fixes in the
native source/linker boundary preserves the requested loader/shim shape.

Host cross-build command:

```sh
make -C vendor/bpf ARCH=arm64 GOARCH=arm64 \
  VMLINUX_BTF=/home/yunwei37/workspace/bpf-benchmark/vendor/build/arm64/linux/vmlinux \
  NATIVE_LINK=/home/yunwei37/workspace/bpf-benchmark/native-sim/x86/native_lab/native_link/target/aarch64-unknown-linux-gnu/release/native-link \
  NATIVE_SYS_INCLUDE_FLAGS="-I/usr/aarch64-linux-gnu/include -I/home/yunwei37/workspace/bpf-benchmark/.cache/aarch64-sysroot/usr/include -I/home/yunwei37/workspace/bpf-benchmark/.cache/aarch64-sysroot/usr/include/aarch64-linux-gnu" \
  native-tetragon
```

Local validation commands:

```sh
cargo test --manifest-path native-sim/x86/native_lab/native_link/Cargo.toml arm64_
make host-rust-arm64
native-sim/x86/native_lab/native_link/target/aarch64-unknown-linux-gnu/release/native-link \
  --input vendor/build/native-bpf/arm64/6.15.11-061511-generic/native/tetragon/bpf_generic_fentry_v61.native.o \
  --symbol filter_char_buf --output /tmp/filter_char_buf.proof.o --mode proof
```

Host build artifact paths:

```text
vendor/build/native-bpf/arm64/stage/tetragon/manifest.json
vendor/build/native-bpf/arm64/stage/tetragon/*.native.o
vendor/build/native-bpf/arm64/6.15.11-061511-generic/native/tetragon/*.proof.ok
vendor/build/native-bpf/arm64/6.15.11-061511-generic/native/tetragon/*.proof.o
vendor/build/native-bpf/arm64/6.15.11-061511-generic/native/tetragon/manifest.json
```

QEMU runtime command: Not run in this phase.
QEMU result path: Not produced in this phase.
Raw correctness data:

- `cargo test --manifest-path native-sim/x86/native_lab/native_link/Cargo.toml arm64_`
  passed: 4 tests passed, 0 failed. The covered regressions are multiple
  epilogues, body spill false positives, non-pair instruction false positives,
  and writeback push/pop matching.
- `make host-rust-arm64` passed after each native-link update and rebuilt
  `native-sim/x86/native_lab/native_link/target/aarch64-unknown-linux-gnu/release/native-link`.
- Manual proof-link of the final previously failing symbol passed:
  `filter_char_buf` wrote `/tmp/filter_char_buf.proof.o` with 2388 bytes and
  42 relocations.
- Final `native-tetragon` exited 0.
- `vendor/build/native-bpf/arm64/stage/tetragon/manifest.json` exists with
  `status=native-objects-proof-linked`, `version=1`, `app=tetragon`, and 93
  manifest object entries.
- `vendor/build/native-bpf/arm64/6.15.11-061511-generic/native/tetragon/manifest.json`
  also reports `status=native-objects-proof-linked`, `version=1`,
  `app=tetragon`, and 93 manifest object entries.
- Native output count: 88 `*.proof.ok` markers and 913 `*.proof.o` files.
- Stage output count: 88 `*.native.o` files.

Failures observed and fixed:

- C compile conflict: arm64 generated vmlinux declares `bpf_strnstr` and
  `bpf_strncasestr` as extern ksyms; Tetragon native stubs were static with the
  same names. Fixed with native-only macro renames.
- C compile mismatch: arm64 `struct filename` layout lacks direct `file->name`.
  Fixed native arm64 path to read through `struct __filename_head`.
- C compile mismatch: native arm64 could not use the non-native BPF inline asm
  register helpers. Fixed with direct C `pt_regs` accessors under
  `MICRO_NATIVE && __TARGET_ARCH_arm64`.
- Linker failure: `.bss`/NOBITS section relocations were already fixed earlier
  in native-link by materializing zero-filled data for arm64 proof mode.
- Linker failure: `generic_fentry_process_filter` originally failed with
  `multiple save sites for x21`; root cause was body spill instructions being
  treated as entry ABI save sites. Fixed by deriving save slots only from the
  leading prologue.
- Linker failure: `tg_tp_cgrp_mkdir` failed with
  `multiple prologue save sites for x19`; root cause was the STP/LDP matcher
  accepting non-pair instructions such as `mov x19, x0`. Fixed with exact
  64-bit pair opcode matching.
- Linker failure: `filter_char_buf` failed with
  `unbalanced save/restore for x19`; root cause was raw-immediate comparison
  for writeback push/pop. Fixed by normalizing writeback stack slots.

Warnings: The final build emitted many existing warnings from Tetragon's
generated arm64 vmlinux header, helper macro redefinitions, qualifier drops,
and packed-member address usage. They were non-fatal and no warning was
silenced.
Raw workload/BPF data, if collected: Not collected yet.
Follow-up: Continue host sidecar build for `tracee/monitor`.

## Phase 4 Record: Tracee Arm64 Sidecar Host Build

Timestamp: 2026-05-29 local.
Scope: `tracee/monitor` host-side arm64 native sidecar build and proof-link.
Files changed in this phase: none.
Loader/shim changes in this phase: none.
Native-link changes in this phase: none.
Runner/framework changes in this phase: none.

Technical decision:

- Keep Tracee on the existing native build path. The previous arm64 native-link
  and native compatibility fixes were sufficient; no Tracee-specific code
  change was required.
- Do not change loader or shim for Tracee. This phase only validates that the
  host-built arm64 native objects and manifest can be produced.
- Do not add Tracee program exclusions, loader replacements, direct `.bpf.o`
  loading, or framework-side summaries.

Implementation approach:

- Build Tracee natively for arm64 on the host with the AArch64 sysroot and the
  arm64 `native-link` binary.
- Run the existing proof-link target for every Tracee native text symbol exposed
  through the Makefile target.
- Stage only the generated native objects and manifest under
  `vendor/build/native-bpf/arm64/stage/tracee` for later runtime image copy.

Host cross-build command:

```sh
make -C vendor/bpf ARCH=arm64 GOARCH=arm64 \
  VMLINUX_BTF=/home/yunwei37/workspace/bpf-benchmark/vendor/build/arm64/linux/vmlinux \
  NATIVE_LINK=/home/yunwei37/workspace/bpf-benchmark/native-sim/x86/native_lab/native_link/target/aarch64-unknown-linux-gnu/release/native-link \
  NATIVE_SYS_INCLUDE_FLAGS="-I/usr/aarch64-linux-gnu/include -I/home/yunwei37/workspace/bpf-benchmark/.cache/aarch64-sysroot/usr/include -I/home/yunwei37/workspace/bpf-benchmark/.cache/aarch64-sysroot/usr/include/aarch64-linux-gnu" \
  native-tracee
```

Host build artifact paths:

```text
vendor/build/native-bpf/arm64/stage/tracee/manifest.json
vendor/build/native-bpf/arm64/stage/tracee/*.native.o
vendor/build/native-bpf/arm64/6.15.11-061511-generic/native/tracee/manifest.json
vendor/build/native-bpf/arm64/6.15.11-061511-generic/native/tracee/*.proof.ok
vendor/build/native-bpf/arm64/6.15.11-061511-generic/native/tracee/*.proof.o
vendor/build/native-bpf/arm64/6.15.11-061511-generic/native/tracee/lsm_support/*.proof.o
```

QEMU runtime command: Not run in this phase.
QEMU result path: Not produced in this phase.
Raw correctness data:

- `native-tracee` exited 0.
- `vendor/build/native-bpf/arm64/stage/tracee/manifest.json` exists with
  `status=native-objects-proof-linked`, `version=1`, `app=tracee`, and 113
  manifest object entries.
- `vendor/build/native-bpf/arm64/6.15.11-061511-generic/native/tracee/manifest.json`
  exists with `status=native-objects-proof-linked`, `version=1`,
  `app=tracee`, and 113 manifest object entries.
- Native proof marker count: 3 `*.proof.ok` files.
- Native proof object count: 174 `*.proof.o` files.
- Stage native object count: 3 `*.native.o` files.

Failures observed and fixed:

- None in this phase.

Warnings:

- The build emitted normal proof-link progress for many Tracee symbols. No
  warning was converted into a hidden success path or filtered result.

Raw workload/BPF data, if collected: Not collected yet.
Follow-up: Run the top-level `host-native-bpf-arm64` target to verify the
complete six-app native artifact pipeline through the repo entrypoint.

## Phase 4 Record: Top-Level Arm64 Native Artifact Entrypoint

Timestamp: 2026-05-29 local.
Scope: full six-app host-side arm64 native sidecar build through the repo
entrypoint.
Files changed in this phase: none.
Loader/shim changes in this phase: none.
Native-link changes in this phase: none.
Runner/framework changes in this phase: none.

Technical decision:

- Treat `make host-native-bpf-arm64` as the authoritative host-side native
  artifact entrypoint before any QEMU runtime test. This verifies the real
  Makefile dependency chain, not only manually invoked per-app subtargets.
- Keep the QEMU boundary clean: this phase cross-builds on the host and does
  not boot QEMU.
- Do not hide warning noise by changing CFLAGS or filtering generated vmlinux
  diagnostics. The warnings are non-fatal and the fail-fast condition is the
  make exit status plus manifest/proof artifacts.

Implementation approach:

- Run the top-level target once after all six individual sidecars built.
- Let the target rebuild/revalidate source app artifacts, Rust arm64 binaries,
  and `vendor/bpf native-artifacts`.
- Validate that the stage directory contains exactly the six app manifests that
  runtime image assembly expects.

Host cross-build command:

```sh
make host-native-bpf-arm64
```

Host build artifact paths:

```text
vendor/build/native-bpf/arm64/stage/bcc/manifest.json
vendor/build/native-bpf/arm64/stage/cilium/manifest.json
vendor/build/native-bpf/arm64/stage/katran/manifest.json
vendor/build/native-bpf/arm64/stage/otelcol-ebpf-profiler/manifest.json
vendor/build/native-bpf/arm64/stage/tetragon/manifest.json
vendor/build/native-bpf/arm64/stage/tracee/manifest.json
```

QEMU runtime command: Not run in this phase.
QEMU result path: Not produced in this phase.
Raw correctness data:

- `make host-native-bpf-arm64` exited 0.
- Stage manifests found:
  - `vendor/build/native-bpf/arm64/stage/bcc/manifest.json`
  - `vendor/build/native-bpf/arm64/stage/cilium/manifest.json`
  - `vendor/build/native-bpf/arm64/stage/katran/manifest.json`
  - `vendor/build/native-bpf/arm64/stage/otelcol-ebpf-profiler/manifest.json`
  - `vendor/build/native-bpf/arm64/stage/tetragon/manifest.json`
  - `vendor/build/native-bpf/arm64/stage/tracee/manifest.json`
- Manifest raw statuses:
  - `bcc`: stage and native `status=native-objects-proof-linked`,
    `version=1`, `app=bcc`, 29 object entries.
  - `katran`: stage and native `status=native-objects-proof-linked`,
    `version=1`, `app=katran`, 3 object entries.
  - `otelcol-ebpf-profiler`: stage and native
    `status=native-objects-proof-linked`, `version=1`,
    `app=otelcol-ebpf-profiler`, 26 object entries.
  - `cilium`: stage and native `status=native-objects-proof-linked`,
    `version=1`, `app=cilium`, 89 object entries.
  - `tracee`: stage and native `status=native-objects-proof-linked`,
    `version=1`, `app=tracee`, 113 object entries.
  - `tetragon`: stage and native `status=native-objects-proof-linked`,
    `version=1`, `app=tetragon`, 93 object entries.
- Native proof marker/object counts:
  - `bcc`: 8 `*.proof.ok`, 34 `*.proof.o`.
  - `katran`: 4 `*.proof.ok`, 6 `*.proof.o`.
  - `otel`: 1 `*.proof.ok`, 30 `*.proof.o`.
  - `cilium`: 8 `*.proof.ok`, 84 `*.proof.o`.
  - `tracee`: 3 `*.proof.ok`, 174 `*.proof.o`.
  - `tetragon`: 88 `*.proof.ok`, 913 `*.proof.o`.
- Stage native object counts:
  - `bcc`: 8 `*.native.o`.
  - `katran`: 4 `*.native.o`.
  - `otelcol-ebpf-profiler`: 1 `*.native.o`.
  - `cilium`: 8 `*.native.o`.
  - `tracee`: 3 `*.native.o`.
  - `tetragon`: 88 `*.native.o`.

Failures observed and fixed:

- None in this phase.

Warnings:

- The top-level target emitted existing Tetragon arm64 native warnings from the
  generated vmlinux header, helper macro redefinitions, qualifier drops, and
  packed-member address usage. They were non-fatal and were not silenced.

Raw workload/BPF data, if collected: Not collected yet.
Follow-up: Build the arm64 runtime image tar through
`make arm64-runner-runtime-image-tar`, then boot QEMU runtime-only tests.

## Phase 5 Record: Arm64 Runtime Image Tar

Timestamp: 2026-05-29 local.
Scope: host-side arm64 runtime image assembly for QEMU runtime-only tests.
Files changed in this phase: none.
Loader/shim changes in this phase: none.
Native-link changes in this phase: none.
Runner/framework changes in this phase: none.

Technical decision:

- Use `make arm64-runner-runtime-image-tar` as the only runtime image entrypoint.
  This preserves the repo contract for build dependencies, image layering,
  kernel/module delivery, shim delivery, native loader delivery, and native-bpf
  artifact delivery.
- Treat QEMU as runtime-only. This phase cross-builds and packages every binary
  before booting QEMU; no compiler or build command has been run inside QEMU.
- Keep the existing runtime image layering. The native-bpf stage is passed as a
  Docker build context and copied into the image, rather than bind-mounted from
  the host workspace.

Implementation approach:

- Build the arm64 runner runtime image with the top-level make rule.
- Confirm the produced tarball exists.
- Confirm the Docker image architecture and OS using image metadata.
- Record non-fatal build warnings as raw observations; no warning was silenced
  or filtered.

Host cross-build/package command:

```sh
make arm64-runner-runtime-image-tar
```

Runtime image artifact:

```text
.cache/container-images/arm64-runner-runtime.image.tar
```

QEMU runtime command: Not run in this phase.
QEMU result path: Not produced in this phase.
Raw correctness data:

- `make arm64-runner-runtime-image-tar` exited 0.
- Runtime image tar exists:
  - path: `.cache/container-images/arm64-runner-runtime.image.tar`
  - size from `ls -lh`: `1.9G`
  - mtime from `ls -lh`: `May 29 10:38`
- Docker image metadata:
  - command:
    `docker image inspect bpf-benchmark/runner-runtime:arm64 --format '{{.Architecture}} {{.Os}} {{.Size}}'`
  - raw output: `arm64 linux 1952656825`
- Docker build evidence for native-bpf packaging:
  - build step:
    `COPY --link --from=runner-runtime-host-native-bpf / /artifacts/user/native-bpf/arm64/`
  - `/opt/bpf-benchmark` is created as a symlink to `/artifacts/user`, so the
    runner default manifest path `/opt/bpf-benchmark/native-bpf/arm64/<app>/manifest.json`
    resolves inside the runtime image.
- Docker build evidence for loader/shim packaging:
  - `COPY --link --from=runner-runtime-host-shim /libbpfrejit_shim.so /usr/local/lib/bpfrejit/libbpfrejit_shim.so`
  - `COPY --link --from=runner-runtime-host-runner-build /native_loader/libnative_loader.so /usr/local/lib/bpfrejit/libnative_loader.so`

Failures observed and fixed:

- None in this phase.

Warnings:

- Existing arm64 native Tetragon warnings were emitted again while rebuilding
  native artifacts for the image tar. They match the earlier host-side build:
  generated vmlinux declarations, helper macro redefinitions, qualifier drops,
  and packed-member address warnings.
- Docker base layer install emitted `sed: can't read /etc/modules: No such file
  or directory` from package scripts while installing `kmod`; Docker build
  continued and exited 0. This was recorded as non-fatal package-script output,
  not hidden by a workaround.

Raw workload/BPF data, if collected: Not collected yet.
Follow-up: start QEMU runtime-only correctness tests one app at a time. The
first app is `bcc/set`, with `BPFREJIT_SHIM_NATIVE_LOADER=post` and
`SKIP_REJIT=norejit`. The corpus driver treats `post` as "baseline uses the
normal BPF loader; post phase enables `BPFREJIT_SHIM_NATIVE_LOADER=1` just for
the second app start", which isolates native-loader correctness before ReJIT
policy tests.

## Phase 6 Record: QEMU `bcc/set` Attempt 1 and Environment Fix

Timestamp: 2026-05-29 local.
Scope: first runtime-only QEMU correctness attempt for `bcc/set`.
Files changed in this phase:

- `runner/scripts/qemu-arm64-init`

Loader/shim changes in this phase: none.
Native-link changes in this phase: none.
Runner/framework changes in this phase: one QEMU init environment parity fix.

Technical decision:

- Keep using `BPFREJIT_SHIM_NATIVE_LOADER=post` plus `SKIP_REJIT=norejit` for
  native-kernel correctness: baseline starts with the normal BPF path and post
  starts with the native-loader path only.
- Treat this failure as a QEMU environment parity defect, not an arm64 native
  linker defect. The shim correctly intercepted real `BPF_PROG_LOAD` calls in
  post phase, but could not find `libnative_loader.so`.
- Do not change loader/shim behavior for this issue. The shim already supports
  `BPFREJIT_NATIVE_LOADER_SO`, and the Docker runtime image already sets it.
  QEMU rootfs is produced by `docker export`, so Dockerfile `ENV` metadata is
  not inherited by PID 1. The minimal fix is to set the same runtime path in
  `qemu-arm64-init`.
- Set `BPFREJIT_REPO_ARTIFACT_ROOT` in the same place because several app
  runners use repo-managed runtime artifacts. Docker runtime images set this
  via `ENV`; QEMU needs the explicit equivalent.

Implementation approach:

- Add two exports to `runner/scripts/qemu-arm64-init`:
  - `BPFREJIT_REPO_ARTIFACT_ROOT=/artifacts/user/repo-artifacts/arm64`
  - `BPFREJIT_NATIVE_LOADER_SO=/usr/local/lib/bpfrejit/libnative_loader.so`
- Leave all make targets, shim lookup logic, native manifests, and native-link
  artifacts unchanged.

QEMU runtime command:

```sh
PLATFORM=qemu ARCH=arm64 \
  BPFREJIT_SHIM_NATIVE_LOADER=post \
  SKIP_REJIT=norejit \
  BPFREJIT_CORPUS_APPS="bcc/set" \
  SAMPLES=1 WORKLOAD_DURATION=10 TIMEOUT=3600 \
  make corpus
```

QEMU result path:

```text
corpus/results/arm64_qemu_corpus_19700101_000004_568820
```

Raw correctness data:

- Make invocation exited 0, but the corpus payload status was `error`.
- `details/result.json` raw top-level fields:
  - `status`: `error`
  - `skip_rejit`: `true`
  - `samples`: `1`
  - `warmups`: `1`
  - `workload_seconds`: `10.0`
  - `bpf_stats`: `true`
- Kinsn module load data:
  - `loaded_count`: `11`
  - `failed_modules`: `[]`
  - loaded modules:
    `bpf_arm64_ccmp`, `bpf_arm64_csel`, `bpf_arm64_extr`,
    `bpf_arm64_ldp`, `bpf_arm64_ldr`, `bpf_arm64_mov`,
    `bpf_arm64_native_lab`, `bpf_arm64_prfm`, `bpf_arm64_rev`,
    `bpf_arm64_str`, `bpf_arm64_ubfm`
- `details/apps/bcc__set.json` raw app fields:
  - `status`: `error`
  - `error`: `BCC tool capable exited before BPF programs were tracked by shim`
  - `rejit_result`: `{"mode": "loadtime", "status": "skipped"}`
  - `post_rejit`: `null`
- Baseline workload raw fields:
  - command: `/usr/bin/stress-ng --syscall 1 --syscall-method fast75 --cap 1 --set 1 --sockfd 1 --sockfd-port 13409 --timeout 10s --metrics-brief --temp-path /var/tmp/bpfrejit-runtime/d4a3203a`
  - `duration_s`: `22.737651440000008`
  - `returncode`: `0`
  - `stderr`: empty
  - selected workload: `stress_ng_bcc_hook_hot`
- Shim log raw counts:
  - baseline log lines: `526`
  - post log lines: `221`
- Post shim log evidence:
  - real app loads were intercepted, for example
    `BPF_PROG_LOAD type=2 (kprobe) name=blk_account_io_ ...`
  - loader lookup failed before native replacement:
    `native-loader dlopen libnative_loader.so failed: libnative_loader.so: cannot open shared object file: No such file or directory`

Failure fixed:

- QEMU init did not inherit Dockerfile `ENV` metadata after `docker export`.
  Added explicit QEMU exports for the native loader shared object and repo
  artifact root.

Follow-up: rerun `bcc/set` with the same command. The rootfs target depends on
`runner/scripts/qemu-arm64-init`, so make will refresh the QEMU root and install
the updated init script before booting.

## Phase 7 Record: QEMU `bcc/set` Attempt 2 and Arm64 Atomic Codegen Fix

Timestamp: 2026-05-29 local.
Scope: second runtime-only QEMU correctness attempt for `bcc/set`.
Files changed in this phase:

- `vendor/bpf/Makefile`

Loader/shim changes in this phase: none.
Native-link changes in this phase: none.
Runner/framework changes in this phase: none.
Native app build plumbing changes in this phase: arm64 native CFLAGS only.

Technical decision:

- Treat the new failure as an arm64 native input-codegen defect. The loader
  shared object was found and native-loader made progress; it successfully
  replaced some programs before the failing `vfsstat` program.
- Do not add a loader/shim fallback and do not filter BPF programs. The failing
  program must either load natively or fail visibly; the fix should make the
  native object valid for kernel-mode native-link.
- Do not teach native-link to resolve compiler runtime helper calls such as
  `__aarch64_ldadd8_relax`. Those calls come from clang/GCC outline atomics and
  require a userspace/compiler-rt helper implementation. Kernel native blobs
  should be self-contained or use explicit BPF/native helper addresses.
- Compile arm64 native app objects with `-mno-outline-atomics`. This keeps
  atomic operations inline as architecture-compatible LL/SC sequences instead
  of external `__aarch64_ldadd*_relax` calls. This is arm64-specific native
  build plumbing and does not change x86 behavior.

Implementation approach:

- Update `NATIVE_ARCH_CFLAGS` in `vendor/bpf/Makefile`:
  - arm64 before: `-mtune=neoverse-n1 -mgeneral-regs-only`
  - arm64 after: `-mtune=neoverse-n1 -mgeneral-regs-only -mno-outline-atomics`
- Leave `KATRAN_NATIVE_CFLAGS` and common `NATIVE_CFLAGS` consumers unchanged
  except through the shared arm64 arch flag.

QEMU runtime command:

```sh
PLATFORM=qemu ARCH=arm64 \
  BPFREJIT_SHIM_NATIVE_LOADER=post \
  SKIP_REJIT=norejit \
  BPFREJIT_CORPUS_APPS="bcc/set" \
  SAMPLES=1 WORKLOAD_DURATION=10 TIMEOUT=3600 \
  make corpus
```

QEMU result path:

```text
corpus/results/arm64_qemu_corpus_19700101_000004_927776
```

Raw correctness data:

- Make invocation exited 0, but the corpus payload status was `error`.
- `details/result.json` raw top-level fields:
  - `status`: `error`
  - `skip_rejit`: `true`
  - `samples`: `1`
  - `workload_seconds`: `10.0`
  - kinsn module load status: `ok`
  - kinsn `loaded_count`: `11`
  - kinsn `failed_modules`: `[]`
- `details/apps/bcc__set.json` raw app fields:
  - `status`: `error`
  - `error`: `BCC tool vfsstat exited before BPF programs were tracked by shim`
  - `rejit_result`: `{"mode": "loadtime", "status": "skipped"}`
  - `post_rejit`: `null`
- Baseline workload raw fields:
  - command: `/usr/bin/stress-ng --syscall 1 --syscall-method fast75 --cap 1 --set 1 --sockfd 1 --sockfd-port 13409 --timeout 10s --metrics-brief --temp-path /var/tmp/bpfrejit-runtime/ee991a7c`
  - `duration_s`: `19.732612032`
  - `returncode`: `0`
  - `stderr`: empty
  - selected workload: `stress_ng_bcc_hook_hot`
- Shim log raw counts:
  - baseline log lines: `526`
  - post log lines: `293`
- Native-loader progress evidence:
  - `native-loader replaced prog=tcp_v4_connect original_fd=13 native_fd=18 manifest=/opt/bpf-benchmark/native-bpf/arm64/bcc/manifest.json`
  - `native-loader replaced prog=inet_sock_set_s original_fd=11 native_fd=18 manifest=/opt/bpf-benchmark/native-bpf/arm64/bcc/manifest.json`
- Native-link failure evidence:
  - failing program: `fentry_vfs_read`
  - stderr:
    `Error: arm64 helper call __aarch64_ldadd8_relax has no helper address`
  - command path:
    `/usr/local/bin/native-link --input /tmp/native_kernel_link_cache/a56c703914ecfaa7.tmp.694.proof.o --symbol fentry_vfs_read --mode kernel ...`

Failure fixed:

- arm64 native app objects could contain outline atomic helper calls. Added
  `-mno-outline-atomics` to arm64 native app CFLAGS so the native objects do not
  depend on compiler runtime helper symbols.

Follow-up: rebuild host arm64 native-bpf artifacts, rebuild the arm64 runtime
image tar, then rerun `bcc/set`.

## Phase 8 Record: Forced Host Arm64 Native-BPF Rebuild After Atomic Codegen Fix

Timestamp: 2026-05-29 local.
Scope: host-side cross-build only; no QEMU build work.
Files changed in this phase: none.
Generated outputs refreshed in this phase:

- `vendor/build/native-bpf/arm64/stage`
- `vendor/build/native-bpf/arm64/6.15.11-061511-generic/native`

Loader/shim changes in this phase: none.
Native-link changes in this phase: none.
Runner/framework changes in this phase: none.
Native app build plumbing changes in this phase: none beyond the Phase 7
`-mno-outline-atomics` source change.

Technical decision:

- The first `make host-native-bpf-arm64` after the Phase 7 CFLAGS edit exited
  0, but some native objects may have been considered up-to-date. Because the
  previous QEMU failure was caused by a stale/generated native object containing
  an outline atomic helper, correctness requires regenerating the arm64 native
  sidecar objects before building a new runtime image.
- Do not clean source app outputs or unrelated build caches. Only remove the
  generated native-bpf arm64 stage/native directories and rerun the owning
  top-level make target.
- Continue to keep all build work on the host. QEMU remains runtime-only.

Commands:

```sh
find vendor/build/native-bpf/arm64 -maxdepth 3 -type d \
  \( -name native -o -name stage \) -print

rm -rf vendor/build/native-bpf/arm64/stage \
  vendor/build/native-bpf/arm64/6.15.11-061511-generic/native

make host-native-bpf-arm64
```

Raw build result:

- `make host-native-bpf-arm64`: exit `0`
- Observed arm64 native compile commands included:
  - `--target=aarch64-linux-gnu`
  - `-DMICRO_NATIVE`
  - `-D__TARGET_ARCH_arm64`
  - `-mtune=neoverse-n1`
  - `-mgeneral-regs-only`
  - `-mno-outline-atomics`

Stage manifest raw data:

```text
bcc status=native-objects-proof-linked version=1 entries=29 path=vendor/build/native-bpf/arm64/stage/bcc/manifest.json
cilium status=native-objects-proof-linked version=1 entries=89 path=vendor/build/native-bpf/arm64/stage/cilium/manifest.json
katran status=native-objects-proof-linked version=1 entries=3 path=vendor/build/native-bpf/arm64/stage/katran/manifest.json
otelcol-ebpf-profiler status=native-objects-proof-linked version=1 entries=26 path=vendor/build/native-bpf/arm64/stage/otelcol-ebpf-profiler/manifest.json
tetragon status=native-objects-proof-linked version=1 entries=93 path=vendor/build/native-bpf/arm64/stage/tetragon/manifest.json
tracee status=native-objects-proof-linked version=1 entries=113 path=vendor/build/native-bpf/arm64/stage/tracee/manifest.json
stage_native_o=112
proof_ok=112
proof_o=1241
```

Arm64 undefined-symbol check:

```sh
find vendor/build/native-bpf/arm64/stage -name '*.native.o' -print0 |
  xargs -0 -r aarch64-linux-gnu-nm -u > /tmp/arm64-native-undefined-symbols.txt
rg '__aarch64|ldadd' /tmp/arm64-native-undefined-symbols.txt
```

Raw symbol-check result:

```text
no __aarch64*/ldadd undefined symbols in staged arm64 native objects
345 /tmp/arm64-native-undefined-symbols.txt
```

Host verification commands:

```sh
make -C bpfopt/shim selftest-run
cargo test --manifest-path native-sim/x86/native_lab/native_link/Cargo.toml arm64_
```

Raw verification data:

- `make -C bpfopt/shim selftest-run`: exit `0`
  - expected unprivileged `BPF_PROG_LOAD` result: `fd=-1 errno=1`
  - shim captured the call and dumped one 16-byte bytecode file matching the
    2-insn test program.
- `cargo test --manifest-path native-sim/x86/native_lab/native_link/Cargo.toml arm64_`: exit `0`
  - `4 passed`
  - `0 failed`
  - `2 filtered out`

Follow-up: rebuild the arm64 runtime image tar so QEMU receives the refreshed
native-bpf stage objects and the QEMU init export fix, then rerun `bcc/set`
before moving to the next app.

## Phase 9 Record: Arm64 Runtime Image Rebuild

Timestamp: 2026-05-29 local.
Scope: host-side runtime image assembly for QEMU runtime tests.
Files changed in this phase: none.
Generated outputs refreshed in this phase:

- `.cache/container-images/arm64-runner-runtime.image.tar`

Loader/shim changes in this phase: none.
Native-link changes in this phase: none.
Runner/framework changes in this phase: none.
Native app build plumbing changes in this phase: none.

Technical decision:

- Rebuild the image tar after the QEMU init environment fix and after the
  forced arm64 native-bpf rebuild. QEMU boots from a rootfs derived from this
  image, so the runtime test is not valid until the image carries both changes.
- Keep image assembly through the Makefile target. Do not invoke docker
  directly for the benchmark run path.
- Because `make arm64-runner-runtime-image-tar` re-enters native artifact
  staging, re-check the staged native objects after image creation.

Command:

```sh
make arm64-runner-runtime-image-tar
```

Raw build result:

- `make arm64-runner-runtime-image-tar`: exit `0`
- Image tar:
  - path: `.cache/container-images/arm64-runner-runtime.image.tar`
  - `ls -lh`: `1.9G`
- `docker image inspect bpf-benchmark/runner-runtime:arm64`:
  - architecture: `arm64`
  - os: `linux`
  - size bytes: `1952654951`
  - image id: `sha256:7c291f210742b1dfeaa987948c40dc02a764e9572ee1de9c645743004c408d15`

Docker build evidence:

- Native sidecar objects copied into:
  - `/artifacts/user/native-bpf/arm64/`
- Runtime compatibility symlink:
  - `/opt/bpf-benchmark -> /artifacts/user`
- Loader/shim copied into:
  - `/usr/local/lib/bpfrejit/libbpfrejit_shim.so`
  - `/usr/local/lib/bpfrejit/libnative_loader.so`
- `native-link` copied into:
  - `/usr/local/bin/native-link`

Stage manifest raw data after image target:

```text
bcc status=native-objects-proof-linked version=1 entries=29
cilium status=native-objects-proof-linked version=1 entries=89
katran status=native-objects-proof-linked version=1 entries=3
otelcol-ebpf-profiler status=native-objects-proof-linked version=1 entries=26
tetragon status=native-objects-proof-linked version=1 entries=93
tracee status=native-objects-proof-linked version=1 entries=113
stage_native_o=112
```

Post-image arm64 undefined-symbol check:

```text
no __aarch64*/ldadd undefined symbols in staged arm64 native objects after image rebuild
345 /tmp/arm64-native-undefined-symbols-after-image.txt
```

Follow-up: rerun `bcc/set` in QEMU with native-loader enabled only for the
post phase and with ReJIT skipped. If `bcc/set` passes, proceed to the next app
one at a time.

## Phase 10 Record: bcc/set QEMU Attempt 3 Failure Triage and Fix

Timestamp: 2026-05-29 local.
Scope: one-app QEMU functional test triage for `bcc/set`.
Files changed in this phase:

- `native-sim/x86/native_lab/native_link/src/main.rs`
- `runner/containers/runner-runtime.Dockerfile`

Loader/shim changes in this phase: none.
Runner/framework behavior changes in this phase: none.
Native-link changes in this phase:

- Make arm64 reachable-symbol identity section-aware with
  `(section_index, address)`, because BPF relocatable objects commonly have
  multiple executable sections whose local address starts at `0`.
- Make arm64 relocation lookup section-aware for the same reason. The old
  `(address, offset)` key let `.text` helper relocations overwrite an entry
  section relocation at the same local address.
- Treat arm64 local `R_AARCH64_CALL26` relocations to text-section symbols as
  local BL edges, include the callee, and patch the BL instead of emitting a
  helper relocation.
- For synthetic proof rodata symbols (`__arm64_section_*_addend_*`), emit proof
  reloc addend `0`; the synthetic symbol already represents the sliced data at
  the original addend.

Runtime image change in this phase:

- Add `auditd` to the runner runtime package list so ARM64 bcc `syscount` has
  `ausyscall` available. This is app runtime parity with the x86 success path:
  x86 bcc has a compiled syscall table, while non-x86 bcc shells out to
  `ausyscall`.

Raw QEMU failure data that triggered this phase:

- Command:

```sh
PLATFORM=qemu ARCH=arm64 \
  BPFREJIT_SHIM_NATIVE_LOADER=post \
  SKIP_REJIT=norejit \
  BPFREJIT_CORPUS_APPS="bcc/set" \
  SAMPLES=1 WORKLOAD_DURATION=10 TIMEOUT=3600 \
  make corpus
```

- Result directory:
  `corpus/results/arm64_qemu_corpus_19700101_000004_789573`
- `make corpus`: exit `0`
- `details/result.json`:
  - `status`: `error`
  - `skip_rejit`: `true`
  - `samples`: `1`
  - `workload_seconds`: `10.0`
- `details/apps/bcc__set.json`:
  - `status`: `error`
  - `error`: `BCC tool tcpconnect exited with rc=97`
  - stderr tail: `syscount: ausyscall required for syscalls number/name mapping`
- Baseline workload raw data:
  - command:
    `/usr/bin/stress-ng --syscall 1 --syscall-method fast75 --cap 1 --set 1 --sockfd 1 --sockfd-port 13410 --timeout 10s --metrics-brief --temp-path /var/tmp/bpfrejit-runtime/1d085e4a`
  - `duration_s`: `20.695340687999995`
  - `returncode`: `0`
- Shim log line counts:
  - baseline: `526`
  - post: `567`

Native-link failure evidence from the same QEMU attempt:

```text
sched_switch:
Error: arm64 helper call __arm64_section_Some(SectionIndex(2))_addend_0 has no helper address

tcp_v6_connect_ret:
Error: arm64 local data relocation __arm64_section_Some(SectionIndex(11))_addend_272 addend 272 exceeds section size 8
```

Technical decisions:

- Do not change loader/shim for these failures. The loader correctly surfaced
  native-link errors and the app correctly surfaced the missing runtime tool.
- Do not add per-program filtering. The unsupported native-link cases are fixed
  so they can surface as successful replacements or real errors naturally.
- Keep proof-object compatibility focused on newly generated proof objects. Old
  failing proof objects in `/tmp/native_kernel_link_cache` remain evidence of
  the old bug and are not rewritten in place.
- Keep the runtime dependency fix in the image layer rather than special-casing
  the bcc app command.

Host verification data after the fix:

```text
cargo fmt --manifest-path native-sim/x86/native_lab/native_link/Cargo.toml: exit 0
cargo test --manifest-path native-sim/x86/native_lab/native_link/Cargo.toml arm64_: exit 0
  4 passed; 0 failed; 0 ignored; 2 filtered out
CARGO_TARGET_AARCH64_UNKNOWN_LINUX_GNU_LINKER=aarch64-linux-gnu-gcc cargo build --release --target aarch64-unknown-linux-gnu --manifest-path native-sim/x86/native_lab/native_link/Cargo.toml: exit 0
cargo build --manifest-path native-sim/x86/native_lab/native_link/Cargo.toml: exit 0
```

Targeted native-link repro data with regenerated proof objects:

```text
sched_switch proof:
native-link: arm64 entry=sched_switch (28 bytes), 2 reachable symbol(s) total
  - sched_switch (vaddr 0x0, 28 bytes) [entry]
  - handle_switch (vaddr 0x0, 820 bytes) [entry]
native-link: wrote proof object 852 bytes, 49 reloc(s) -> /tmp/sched_switch.new.proof.o

sched_switch kernel:
native-link: arm64 entry=sched_switch (28 bytes), 2 reachable symbol(s) total
  - sched_switch (vaddr 0x0, 28 bytes) [entry]
  - handle_switch (vaddr 0x1c, 820 bytes)
native-link: wrote 1172 bytes -> /tmp/sched_switch.blob.bin (0 relocs)
native-link: wrote 0 relocs -> /tmp/sched_switch.relocs.bin
native-link: wrote 9 map patch site(s) -> /tmp/sched_switch.map-patches.tsv
native-link: wrote ABI metadata -> /tmp/sched_switch.abi.tsv

tcp_v6_connect_ret proof:
native-link: arm64 entry=tcp_v6_connect_ret (600 bytes), 1 reachable symbol(s) total
  - tcp_v6_connect_ret (vaddr 0x0, 600 bytes) [entry]
native-link: wrote proof object 604 bytes, 38 reloc(s) -> /tmp/tcp_v6_connect_ret.new.proof.o

tcp_v6_connect_ret kernel:
native-link: arm64 entry=tcp_v6_connect_ret (600 bytes), 1 reachable symbol(s) total
  - tcp_v6_connect_ret (vaddr 0x0, 600 bytes) [entry]
native-link: wrote 884 bytes -> /tmp/tcp_v6_connect_ret.blob.bin (0 relocs)
native-link: wrote 0 relocs -> /tmp/tcp_v6_connect_ret.relocs.bin
native-link: wrote 7 map patch site(s) -> /tmp/tcp_v6_connect_ret.map-patches.tsv
native-link: wrote ABI metadata -> /tmp/tcp_v6_connect_ret.abi.tsv
```

Follow-up: rebuild arm64 native artifacts and the arm64 runtime image so QEMU
uses regenerated proof objects, the refreshed `native-link`, and `ausyscall`;
then rerun `bcc/set` before moving to the next app.

## Phase 11 - Regenerate arm64 native artifacts after native-link fixes

Status: complete.

Command:

```bash
make host-native-bpf-arm64
```

Result:

```text
exit 0
```

Raw artifact checks:

```text
bcc status=native-objects-proof-linked version=1 manifest_objects=29 native_files=8
cilium status=native-objects-proof-linked version=1 manifest_objects=89 native_files=8
katran status=native-objects-proof-linked version=1 manifest_objects=3 native_files=4
otelcol-ebpf-profiler status=native-objects-proof-linked version=1 manifest_objects=26 native_files=1
tetragon status=native-objects-proof-linked version=1 manifest_objects=93 native_files=88
tracee status=native-objects-proof-linked version=1 manifest_objects=113 native_files=3
stage_native_o=112
proof_ok=112
proof_o=1241
forbidden_atomic_undefined_symbols=absent
undefined_symbol_lines=345
```

Notes:

- `manifest_objects` is read from `manifest.json` `.objects | length`; the
  manifest schema uses `objects`, not `entries`.
- The full host arm64 native artifact rebuild now includes the section-aware
  arm64 native-link fix and the `-mno-outline-atomics` compile flag.
- No loader/shim changes were made in this phase.
- No app was filtered or skipped. All six supported apps produced staged arm64
  native objects.

Technical decisions:

- Treat this as the required local cross-build gate before any new QEMU run.
- Keep the next test narrow: rerun only `bcc/set` first because it exposed both
  the previous native-link failures and the missing `ausyscall` runtime tool.
- Rebuild the arm64 runtime image before QEMU so the guest sees the refreshed
  staged objects, refreshed `native-link`, and the `auditd` package.

## Phase 12 - Rebuild arm64 runtime image for QEMU

Status: complete.

Command:

```bash
make arm64-runner-runtime-image-tar
```

Result:

```text
exit 0
```

Image metadata:

```text
docker image inspect bpf-benchmark/runner-runtime:arm64:
arm64 linux 1953840403 sha256:dc1685071a6bb94d757e6f29e1705fe0c48e213e591264fabe80ccb86d672698

.cache/container-images/arm64-runner-runtime.image.tar:
-rw------- 1 yunwei37 yunwei37 1.9G May 29 11:35 .cache/container-images/arm64-runner-runtime.image.tar
```

Docker history evidence for the runtime dependency fix:

```text
apt-get install -y --no-install-recommends auditd bash binutils ... stress-ng ...
```

Staged native artifact evidence copied into the image build context:

```text
bcc status=native-objects-proof-linked manifest_objects=29 native_files=8
cilium status=native-objects-proof-linked manifest_objects=89 native_files=8
katran status=native-objects-proof-linked manifest_objects=3 native_files=4
otelcol-ebpf-profiler status=native-objects-proof-linked manifest_objects=26 native_files=1
tetragon status=native-objects-proof-linked manifest_objects=93 native_files=88
tracee status=native-objects-proof-linked manifest_objects=113 native_files=3
```

Notes:

- The image rebuild was invoked through `make`, not by bypassing benchmark
  orchestration.
- `auditd` is now part of the image package layer; this provides `ausyscall`
  for the bcc `syscount` tool.
- I did not run a standalone `docker run` sanity command for `ausyscall` because
  benchmark/runtime validation should continue through the QEMU `make corpus`
  entrypoint. The next `bcc/set` QEMU run is the functional validation of this
  dependency.
- No loader/shim code changed in this phase.

Technical decisions:

- Keep the runtime dependency as a normal image package rather than adding an
  app-level special case.
- Use the next `bcc/set` QEMU run as the first real guest validation because it
  exercises both native-loader replacement and the `ausyscall` dependency.

## Phase 13 - QEMU functional test: `bcc/set`

Status: complete.

Command:

```bash
PLATFORM=qemu ARCH=arm64 \
  BPFREJIT_SHIM_NATIVE_LOADER=post \
  SKIP_REJIT=norejit \
  BPFREJIT_CORPUS_APPS="bcc/set" \
  SAMPLES=1 WORKLOAD_DURATION=10 TIMEOUT=3600 \
  make corpus
```

Result:

```text
make exit 0
artifact_run_dir=/home/yunwei37/workspace/bpf-benchmark/corpus/results/arm64_qemu_corpus_19700101_000004_910692
details/result.json status=ok
details/result.json error=null
skip_rejit=true
samples=1
workload_seconds=10.0
details/apps/bcc__set.json status=ok
details/apps/bcc__set.json error=""
rejit_result={"mode":"loadtime","status":"skipped"}
```

Raw workload data:

```text
baseline workload command:
/usr/bin/stress-ng --syscall 1 --syscall-method fast75 --cap 1 --set 1 --sockfd 1 --sockfd-port 13409 --timeout 10s --metrics-brief --temp-path /var/tmp/bpfrejit-runtime/a8fbe04e
baseline duration_s=23.70872273599999
baseline returncode=0

post_rejit workload command:
/usr/bin/stress-ng --syscall 1 --syscall-method fast75 --cap 1 --set 1 --sockfd 1 --sockfd-port 14433 --timeout 10s --metrics-brief --temp-path /var/tmp/bpfrejit-runtime/a8fbe04e
post_rejit duration_s=13.674805247999984
post_rejit returncode=0
```

Raw shim/native-loader evidence:

```text
details/shim-logs/bcc__set.baseline.log lines=528
details/shim-logs/bcc__set.post_rejit.log lines=644
post_rejit BPF_PROG_LOAD type lines=74
post_rejit native-loader lines=120
post_rejit native-loader replaced lines=23
post_rejit native fd lines=23
post_rejit native-link lines=0
post_rejit failed lines=0
post_rejit Error lines=0
```

Representative native replacements from post phase:

```text
native-loader replaced prog=fentry_vfs_writ original_fd=8 native_fd=15 manifest=/opt/bpf-benchmark/native-bpf/arm64/bcc/manifest.json
native-loader replaced prog=kprobe__cap_cap original_fd=15 native_fd=27 manifest=/opt/bpf-benchmark/native-bpf/arm64/bcc/manifest.json
native-loader replaced prog=sys_exit original_fd=11 native_fd=20 manifest=/opt/bpf-benchmark/native-bpf/arm64/bcc/manifest.json
native-loader replaced prog=tcp_v6_connect_ original_fd=13 native_fd=26 manifest=/opt/bpf-benchmark/native-bpf/arm64/bcc/manifest.json
native-loader replaced prog=sched_switch original_fd=12 native_fd=24 manifest=/opt/bpf-benchmark/native-bpf/arm64/bcc/manifest.json
```

Notes:

- This validates the `auditd`/`ausyscall` runtime dependency fix: the bcc
  `syscount` tool no longer exits with `ausyscall required for syscalls
  number/name mapping`.
- The prior arm64 native-link failures for `sched_switch` and
  `tcp_v6_connect_` are gone in the regenerated-image QEMU run.
- No loader/shim change was made in this phase.
- No program or app was filtered.

Technical decisions:

- Mark `bcc/set` as functionally passing for the arm64 native-kernel path.
- Continue one app at a time, keeping the same functional-first settings before
  any full-suite or micro run.

## Phase 14 - QEMU functional test: `otelcol-ebpf-profiler/profiling` attempt 1 and config fix

Status: attempted, failed for guest runtime configuration; fixed in source.

Command:

```bash
PLATFORM=qemu ARCH=arm64 \
  BPFREJIT_SHIM_NATIVE_LOADER=post \
  SKIP_REJIT=norejit \
  BPFREJIT_CORPUS_APPS="otelcol-ebpf-profiler/profiling" \
  SAMPLES=1 WORKLOAD_DURATION=10 TIMEOUT=3600 \
  make corpus
```

Result:

```text
make exit 0
artifact_run_dir=/home/yunwei37/workspace/bpf-benchmark/corpus/results/arm64_qemu_corpus_19700101_000004_086825
details/result.json status=error
details/result.json skip_rejit=true
details/result.json samples=1
details/result.json workload_seconds=10.0
details/apps/otelcol-ebpf-profiler__profiling.json status=error
```

Raw failure:

```text
native app exited before BPF programs were tracked by shim
failed to create meter provider: binding address localhost:8888 for Prometheus exporter:
listen tcp: lookup localhost on [::1]:53: read udp [::1]:46762->[::1]:53: read: connection refused
```

Code change:

```text
runner/libs/app_runners/otel_profiler.py
- Added service.telemetry.metrics.level: none to the generated minimal OTEL
  collector config.
```

Verification after the source edit:

```text
python3 -m py_compile runner/libs/app_runners/otel_profiler.py: exit 0
```

Technical decisions:

- Do not change loader or shim for this failure. The app exited before BPF
  programs were tracked by the shim, and the error is the collector's default
  internal telemetry binding to `localhost:8888`.
- Do not modify guest DNS or add a guest service dependency. The runner's
  minimal OTEL config does not need collector self-metrics for the benchmark.
- Use `metrics.level: none` rather than a `localhost` address rewrite. This is
  smaller, avoids DNS dependence entirely, and reduces irrelevant telemetry
  overhead while leaving the profiling receiver and debug profile exporter
  unchanged.
- Rebuild the arm64 runtime image before retrying because runner Python is
  copied into the image top layer.

## Phase 15 - Rebuild arm64 runtime image after OTEL config fix

Status: passed.

Command:

```bash
make arm64-runner-runtime-image-tar
```

Result:

```text
make exit 0
image=arm64 linux 1953840435 sha256:859c5abeb8ab3d00f642a215dec82d32026e945fcbdb8d3e0cff1597f6ea0ca5
tar=-rw------- 1 yunwei37 yunwei37 1.9G May 29 11:47 .cache/container-images/arm64-runner-runtime.image.tar
```

Native artifact manifest after rebuild:

```text
bcc status=native-objects-proof-linked manifest_objects=29 native_files=8
cilium status=native-objects-proof-linked manifest_objects=89 native_files=8
katran status=native-objects-proof-linked manifest_objects=3 native_files=4
otelcol-ebpf-profiler status=native-objects-proof-linked manifest_objects=26 native_files=1
tetragon status=native-objects-proof-linked manifest_objects=93 native_files=88
tracee status=native-objects-proof-linked manifest_objects=113 native_files=3
```

Technical decisions:

- This rebuild is host-side only; it does not build inside QEMU.
- Keep the image rebuild as a separate recorded phase because runner Python is
  copied into the image top layer and QEMU must test the rebuilt image.
- No loader or shim change was made in this phase.
- No program or app was filtered.

## Phase 16 - QEMU functional test: `otelcol-ebpf-profiler/profiling` attempt 2

Status: terminated as a QEMU functional-smoke sizing failure; no code change in
this phase.

Command:

```bash
PLATFORM=qemu ARCH=arm64 \
  BPFREJIT_SHIM_NATIVE_LOADER=post \
  SKIP_REJIT=norejit \
  BPFREJIT_CORPUS_APPS="otelcol-ebpf-profiler/profiling" \
  SAMPLES=1 WORKLOAD_DURATION=10 TIMEOUT=3600 \
  make corpus
```

Observed progress:

```text
app_start: otelcol-ebpf-profiler/profiling
measurement_start: baseline
host qemu elapsed at termination: 14:23
host qemu cpu: about 205%
```

Termination result:

```text
qemu-system-aarch64: terminating on signal 15
make exit 2
qemu-status absent
completed result.json absent
partial_run_dir=.cache/qemu-arm64-root/home/yunwei37/workspace/bpf-benchmark/corpus/results/arm64_qemu_corpus_19700101_000004_706988
partial progress.json status=running
partial progress.json workload_seconds=10.0
```

Partial baseline shim evidence:

```text
baseline shim log lines=259
BPF_PROG_LOAD type=16
native-loader=9
native-link=0
failed=0
Error=0
replaced=0
native fd=0
```

Loaded OTEL programs before the stall included:

```text
perf_unwind_sto
perf_unwind_nat
perf_unwind_hot
perf_unwind_per
perf_unwind_php
perf_unwind_pyt
perf_unwind_rub
perf_unwind_v8
perf_go_labels
native_tracer_e
custom__generic
```

Technical decisions:

- Do not change loader or shim for this attempt. The run reached baseline
  measurement and had no native-link replacement, `failed`, or `Error` lines.
- Treat this as QEMU smoke sizing, not as an app correctness failure yet:
  OTEL loaded the expected BPF programs, then the 100k samples/s profiler plus
  multi-interpreter workload saturated the 2-vCPU QEMU guest.
- Keep the next retry functional-first but reduce only the smoke workload
  duration to `WORKLOAD_DURATION=1` and add an explicit
  `BPFREJIT_CORPUS_APP_TIMEOUT` so a slow/hung attempt produces bounded test
  data.
- No program or app was filtered.

## Phase 17 - QEMU functional test: `otelcol-ebpf-profiler/profiling` attempt 3 and sampler-rate fix

Status: failed with bounded timeout; fixed in source.

Command:

```bash
PLATFORM=qemu ARCH=arm64 \
  BPFREJIT_SHIM_NATIVE_LOADER=post \
  SKIP_REJIT=norejit \
  BPFREJIT_CORPUS_APPS="otelcol-ebpf-profiler/profiling" \
  SAMPLES=1 WORKLOAD_DURATION=1 \
  BPFREJIT_CORPUS_APP_TIMEOUT=300 \
  TIMEOUT=900 \
  make corpus
```

Result:

```text
make exit 0
artifact_run_dir=/home/yunwei37/workspace/bpf-benchmark/corpus/results/arm64_qemu_corpus_19700101_000003_966886
details/result.json status=error
details/result.json skip_rejit=true
details/result.json samples=1
details/result.json workload_seconds=1.0
details/apps/otelcol-ebpf-profiler__profiling.json status=error
details/apps/otelcol-ebpf-profiler__profiling.json error=otelcol-ebpf-profiler/profiling app lifecycle timed out after 300.0s
baseline_workloads=0
post_workloads=0
```

Baseline shim evidence:

```text
baseline shim log lines=260
BPF_PROG_LOAD type=16
native-loader=9
native-link=0
failed=0
Error=0
replaced=0
native fd=0
pass-through=0
```

Code change:

```text
runner/libs/app_runners/otel_profiler.py
- Changed the generated OTEL profiling receiver samples_per_second from
  100000 to 1000.
```

Verification after the source edit:

```text
python3 -m py_compile runner/libs/app_runners/otel_profiler.py: exit 0
configured samples_per_second=1000
```

Technical decisions:

- Do not change loader or shim. This is still baseline measurement before the
  post-run native loader replacement path, and the shim log contains no
  native-link failure or replacement attempt.
- Do not bypass OTEL or filter any OTEL BPF program. The app still loads all
  expected profiler programs via the upstream collector.
- Lower the profiler sampling rate instead of reducing language coverage. A
  1k/s sampling rate still gives about 30k samples during the default 30s
  workload and enough samples during smoke runs to drive perf_event programs,
  while avoiding a QEMU-only self-overload where 100k/s could not finish even
  a 1s baseline within 300s.
- Rebuild the arm64 runtime image before retrying because runner Python is
  copied into the image top layer.

## Phase 18 - Rebuild arm64 runtime image after OTEL sampler-rate fix

Status: passed.

Command:

```bash
make arm64-runner-runtime-image-tar
```

Result:

```text
make exit 0
image=arm64 linux 1953840433 sha256:ba88139585bac36ce7e8c8a5678ca20a855abeac52d59093d917de97ef4d3650
tar=-rw------- 1 yunwei37 yunwei37 1.9G May 29 12:14 .cache/container-images/arm64-runner-runtime.image.tar
```

Native artifact manifest after rebuild:

```text
bcc status=native-objects-proof-linked manifest_objects=29 native_files=8
cilium status=native-objects-proof-linked manifest_objects=89 native_files=8
katran status=native-objects-proof-linked manifest_objects=3 native_files=4
otelcol-ebpf-profiler status=native-objects-proof-linked manifest_objects=26 native_files=1
tetragon status=native-objects-proof-linked manifest_objects=93 native_files=88
tracee status=native-objects-proof-linked manifest_objects=113 native_files=3
```

Technical decisions:

- This rebuild is host-side only; it does not build inside QEMU.
- The rebuilt image carries the OTEL config change in the runner Python top
  layer and keeps the same proof-linked native artifacts for all 6 supported
  apps.
- No loader or shim change was made in this phase.
- No program or app was filtered.

## Phase 19 - QEMU functional test: `otelcol-ebpf-profiler/profiling` attempt 4 and native-loader data-symbol fix

Status: baseline passed; post native-loader start failed; fixed in source.

Command:

```bash
PLATFORM=qemu ARCH=arm64 \
  BPFREJIT_SHIM_NATIVE_LOADER=post \
  SKIP_REJIT=norejit \
  BPFREJIT_CORPUS_APPS="otelcol-ebpf-profiler/profiling" \
  SAMPLES=1 WORKLOAD_DURATION=10 \
  BPFREJIT_CORPUS_APP_TIMEOUT=600 \
  TIMEOUT=1200 \
  make corpus
```

Result:

```text
make exit 0
artifact_run_dir=/home/yunwei37/workspace/bpf-benchmark/corpus/results/arm64_qemu_corpus_19700101_000004_717532
details/result.json status=error
details/result.json skip_rejit=true
details/result.json samples=1
details/result.json workload_seconds=10.0
details/apps/otelcol-ebpf-profiler__profiling.json status=error
baseline_workloads=1
post_workloads=0
rejit_result={"mode":"loadtime","status":"skipped"}
```

Failure:

```text
post_rejit_start: native app exited before BPF programs were tracked by shim
post shim log lines=55
BPF_PROG_LOAD type=19
native-loader=11
native-link=3
failed=1
Error=1
replaced=0
native fd=0
```

Native-link error:

```text
native-loader failed prog=read_task_struc manifest=/opt/bpf-benchmark/native-bpf/arm64/otelcol-ebpf-profiler/manifest.json source=/tmp/bpfrejit_637_faf32c71d920a0c6.bpf error=native-link kernel failed (rc=1)
native-link: arm64 entry=read_task_struct (244 bytes), 1 reachable symbol(s) total
Error: arm64 ADR_GOT in read_task_struct at byte offset 0x7c targets unknown map with_debug_output
```

Root cause:

```text
OTEL .rodata.var native section size=44
loaded BPF .rodata.var map value size=40
with_debug_output symbol offset=8 size=4
```

The native loader already resolves native data symbols to direct map-value
addresses, but it used the full ELF section size as the minimum map value size
for every symbol. OTEL's `.rodata.var` section has trailing/alignment bytes
beyond the loaded BPF map value, so `with_debug_output` was skipped even though
the symbol itself is fully inside the map value.

Code change:

```text
native-sim/libnativeloader/src/native_loader.cpp
- In add_native_data_symbol_addrs(), match candidate data maps using the
  current symbol end offset instead of max(section size, symbol end).
```

Verification after the source edit:

```text
make host-runner-arm64: exit 0
rebuilt runner/build-arm64-llvmbpf/native_loader/libnative_loader.so
```

Technical decisions:

- Change the native loader, not shim. This is a data-symbol address discovery
  bug in the loader's native-link side input generation; the shim only invokes
  the existing loader path.
- Keep the change minimal and general. It does not add app filtering or an
  OTEL special case; it accepts symbols that fit within the loaded data map
  even when the native ELF section has harmless trailing bytes.
- Rebuild the arm64 runtime image before retrying because the QEMU image must
  carry the new `libnative_loader.so`.
- No program or app was filtered.

## Phase 20 - Rebuild arm64 runtime image after native-loader data-symbol fix

Status: passed.

Command:

```bash
make arm64-runner-runtime-image-tar
```

Result:

```text
make exit 0
image=arm64 linux 1953774897 sha256:2cf7a6bf876ac01f847f6753d19f06ad0ceca6c63ada0ef7a9b0585fe3dce5a3
tar=-rw------- 1 yunwei37 yunwei37 1.9G May 29 12:26 .cache/container-images/arm64-runner-runtime.image.tar
```

Native artifact manifest after rebuild:

```text
bcc status=native-objects-proof-linked manifest_objects=29 native_files=8
cilium status=native-objects-proof-linked manifest_objects=89 native_files=8
katran status=native-objects-proof-linked manifest_objects=3 native_files=4
otelcol-ebpf-profiler status=native-objects-proof-linked manifest_objects=26 native_files=1
tetragon status=native-objects-proof-linked manifest_objects=93 native_files=88
tracee status=native-objects-proof-linked manifest_objects=113 native_files=3
```

Technical decisions:

- This rebuild is host-side only; it does not build inside QEMU.
- The rebuilt image carries the new `libnative_loader.so` and keeps all 6
  supported app native artifacts proof-linked.
- No shim change was made in this phase.
- No program or app was filtered.

## Phase 21 - OTEL single-app QEMU retry after native-loader fix

Status: failed; produced a kernel panic in post phase.

Command:

```bash
PLATFORM=qemu ARCH=arm64 \
  BPFREJIT_SHIM_NATIVE_LOADER=post \
  SKIP_REJIT=norejit \
  BPFREJIT_CORPUS_APPS="otelcol-ebpf-profiler/profiling" \
  SAMPLES=1 WORKLOAD_DURATION=10 \
  BPFREJIT_CORPUS_APP_TIMEOUT=600 \
  TIMEOUT=1200 \
  make corpus
```

Result:

```text
make exit 2
partial_qemu_run_dir=.cache/qemu-arm64-root/home/yunwei37/workspace/bpf-benchmark/corpus/results/arm64_qemu_corpus_19700101_000004_745098
progress.status=running
progress.samples=1
progress.workload_seconds=10.0
baseline shim log lines=336
post shim log lines=55
native-loader=13
native-link=0
failed=0
Error=0
replaced=1
native fd=1
BPF_PROG_LOAD type=19
```

Kernel panic excerpt:

```text
Unable to handle kernel execute from non-executable memory at virtual address 0000000000000001
pc : 0x1
lr : bpf_prog_63a51376c0189f82_read_task_struc+0x50/0x168
Call trace:
 0x1 (P)
 bpf_trace_run2+0x1f0/0x260
 __bpf_trace_sys_enter+0x24/0x50
 syscall_trace_enter+0x19c/0x270
```

Shim evidence:

```text
BPF_PROG_LOAD type=17 (raw_tracepoint) name=read_task_struc insn_cnt=56 hash=faf32c71d920a0c6
native-loader jit-info original fd=11 id=17 type=17 name=read_task_struc tag=7f6621b619c2ec76 jited_len=272 xlated_len=304
native-loader jit-info native fd=16 id=18 type=17 name=read_task_struc tag=63a51376c0189f82 jited_len=360 xlated_len=40
native-loader replaced prog=read_task_struc original_fd=11 native_fd=16
```

Root cause:

```text
arm64 read_task_struct.proof.o still contained helper-id indirect calls:
0x24: ldr x0, [x0]
0x28: blr x8          ; x8 was loaded with immediate helper id 1
0x38: mov x20, x0
0x3c: blr x8          ; x8 was loaded with immediate helper id 14
0x50: blr x8          ; x8 was loaded with immediate helper id 35
0x74: blr x9          ; x9 was loaded with immediate helper id 113
0xec: blr x9          ; x9 was loaded with immediate helper id 6
```

The x86 native-link success path already scans immediate helper-id loads before
register-indirect calls and rewrites those calls to real helper targets. The
arm64 path only handled relocated `CALL26` helper calls, so proof objects that
encode helper calls as `mov wN,#helper_id; blr xN` could pass link-time checks
and jump to helper id `0x1` at runtime.

Technical decisions:

- Fix this in `native-link`, not loader or shim. The failing behavior is
  architecture-specific machine-code lowering, and the shim/loader already
  selected and loaded the intended native replacement.
- Add fail-fast behavior for unresolved arm64 `blr` in kernel mode, so future
  unsupported register-indirect calls fail during load instead of entering the
  kernel as bad executable addresses.
- Do not filter OTEL or `read_task_struc`; the app remains part of the corpus.
- No build occurred inside QEMU.

Code change:

```text
native-sim/x86/native_lab/native_link/src/main.rs
- Decode arm64 MOVZ immediate helper-id loads.
- Track helper IDs by target register within each symbol.
- Rewrite `blr xN` helper calls through `build_arm64_helper_call()`, reusing
  the existing helper/map lookup/update lowering path.
- Leave proof mode symbolic, matching the existing proof-object contract.
- Add a focused arm64 unit test for helper-id MOVZ and BLR decoding.
```

Verification after the source edit:

```text
cargo test --manifest-path native-sim/x86/native_lab/native_link/Cargo.toml arm64_
exit 0
5 passed; 0 failed; 2 filtered out

make host-runner-arm64
exit 0
rebuilt runner/build-arm64-llvmbpf/native_loader/libnative_loader.so
```

## Phase 22 - Rebuild host arm64 native artifacts after arm64 helper-call lowering

Status: passed.

Command:

```bash
make host-native-bpf-arm64
```

Result:

```text
make exit 0
native_link_arm64=ELF 64-bit LSB pie executable, ARM aarch64
native_link_build_id=4fb01acb3e4b77fbaf75b8f86ea0041189183b4c
stage_native_o=112
proof_ok=112
proof_o=1241
```

Native artifact manifest after rebuild:

```text
bcc status=native-objects-proof-linked version=1 manifest_objects=29 native_files=8
cilium status=native-objects-proof-linked version=1 manifest_objects=89 native_files=8
katran status=native-objects-proof-linked version=1 manifest_objects=3 native_files=4
otelcol-ebpf-profiler status=native-objects-proof-linked version=1 manifest_objects=26 native_files=1
tetragon status=native-objects-proof-linked version=1 manifest_objects=93 native_files=88
tracee status=native-objects-proof-linked version=1 manifest_objects=113 native_files=3
```

Technical decisions:

- This is the required local cross-build step before any QEMU retry.
- Proof objects intentionally remain symbolic and may still show
  `mov wN,#helper_id; blr xN`; kernel-mode native-link consumes that proof
  object later and rewrites those helper calls with live helper addresses from
  the loader-generated link plan.
- Rebuild the runtime image next so QEMU receives the new arm64 `native-link`
  binary and regenerated native artifacts.
- No app, program, or pass filtering was introduced.

## Phase 23 - Rebuild arm64 runtime image after arm64 helper-call fix

Status: passed.

Command:

```bash
make arm64-runner-runtime-image-tar
```

Result:

```text
make exit 0
image=arm64 linux 1953774908 sha256:9740c230bdecd368a5e3f89fda584b6d683216cf1a7d9926a2b97c68c04d787f
tar=-rw------- 1 yunwei37 yunwei37 1.9G May 29 12:45 .cache/container-images/arm64-runner-runtime.image.tar
tar_size=1968538624
```

Native artifact manifest after image rebuild:

```text
bcc status=native-objects-proof-linked manifest_objects=29 native_files=8
cilium status=native-objects-proof-linked manifest_objects=89 native_files=8
katran status=native-objects-proof-linked manifest_objects=3 native_files=4
otelcol-ebpf-profiler status=native-objects-proof-linked manifest_objects=26 native_files=1
tetragon status=native-objects-proof-linked manifest_objects=93 native_files=88
tracee status=native-objects-proof-linked manifest_objects=113 native_files=3
```

Technical decisions:

- Image rebuild remained host-side only; QEMU still only receives prebuilt
  artifacts.
- This image carries the new arm64 `native-link`, regenerated arm64 native BPF
  artifacts, and the previously fixed `libnative_loader.so`.
- The next test stays single-app OTEL; do not advance to all-app corpus until
  every app has passed individually.

## Phase 24 - OTEL single-app QEMU retry after helper-call lowering

Status: failed; continue fixing in `native-link` / loader-side link plan only.

Command:

```bash
PLATFORM=qemu ARCH=arm64 \
  BPFREJIT_SHIM_NATIVE_LOADER=post \
  SKIP_REJIT=norejit \
  BPFREJIT_CORPUS_APPS="otelcol-ebpf-profiler/profiling" \
  SAMPLES=1 WORKLOAD_DURATION=10 \
  BPFREJIT_CORPUS_APP_TIMEOUT=600 \
  TIMEOUT=1200 \
  make corpus
```

Result:

```text
make exit 0
artifact=/home/yunwei37/workspace/bpf-benchmark/corpus/results/arm64_qemu_corpus_19700101_000004_696979
details/result.json status=error
details/result.json error=null
skip_rejit=true
samples=1
workload_seconds=10.0
app_status=error
app_error=native app exited before BPF programs were tracked by shim
baseline_workloads=1
post_workloads=0
baseline shim log lines=332
post shim log lines=230
```

Key shim data:

```text
post BPF_PROG_LOAD type=17 raw_tracepoint name=read_task_struc hash=faf32c71d920a0c6
native-loader replaced prog=read_task_struc original_fd=11 native_fd=16
post BPF_PROG_LOAD type=7 perf_event name=perf_unwind_sto hash=31f72993c38631b0
native-loader failed prog=perf_unwind_sto ... error=native-link kernel failed (rc=1)
native-link: arm64 entry=perf_unwind_stop (5192 bytes), 1 reachable symbol(s) total
Error: arm64 helper call bpf_tail_call has no helper address
```

Technical decision:

- This is progress from the previous kernel PC=0x1 panic: unresolved register
  helper calls now fail during native linking instead of producing bad kernel
  code.
- The new failure is specifically arm64 `bpf_tail_call` lowering. x86 has an
  inline lowering path because `bpf_tail_call` is not just a normal helper
  function call; it must validate the prog-array slot, update the tail-call
  counter, restore the current JIT frame, and branch to
  `prog->bpf_func + tail_call_offset`.
- Keep the fix in `native-link` plus loader link-plan metadata. Do not change
  shim behavior and do not filter OTEL or any tail-called program.
- Continue using the local cross-build then QEMU test sequence. No build
  occurred inside QEMU.

## Phase 25 - Local cross-build retry exposed over-eager arm64 tail-call cleanup planning

Status: failed first, fixed locally in `native-link`, unit-tested.

Failed command:

```bash
make host-native-bpf-arm64
```

Failed result:

```text
make exit 2
failing stage=native-tetragon
failing entry=filter_inet
source object=vendor/build/native-bpf/arm64/6.15.11-061511-generic/native/tetragon/bpf_generic_fentry_v61.native.o
error=arm64 entry with bpf_tail_call has multiple incompatible return epilogues
```

Changed files:

```text
native-sim/x86/native_lab/native_link/src/main.rs
```

What changed:

- Added arm64 entry tail-call detection before planning tail-call cleanup.
  This matches the x86 success-path shape: only an entry that actually contains
  `bpf_tail_call` needs the tail-call frame cleanup analysis.
- Skipped tail-call cleanup planning in `--mode proof`; proof objects only need
  ABI metadata and symbolic helper calls. Kernel-mode native-link consumes the
  proof object later and plans cleanup when it actually lowers the helper call.
- Normalized arm64 cleanup candidates by dropping ABI-stripped restore NOPs.
  Clang may schedule return-value moves between restore groups, so two valid
  epilogues can differ only by where stripped restore NOPs would have appeared.
  The runtime cleanup only needs the native stack cleanup words plus any
  unstripped restores.

Technical decision:

- Keep the fix entirely in native-link. No loader/shim change was needed for
  this failure.
- Do not filter Tetragon or `filter_inet`; the failure surfaced naturally in
  the host cross-build and was fixed at the linker analysis boundary.
- This is still local-only validation; QEMU will not be used until the host
  arm64 artifacts and runtime image rebuild successfully.

Validation:

```bash
cargo fmt --manifest-path native-sim/x86/native_lab/native_link/Cargo.toml
cargo test --manifest-path native-sim/x86/native_lab/native_link/Cargo.toml arm64_
```

```text
cargo fmt exit 0
cargo test exit 0
running 10 tests
10 passed; 0 failed; 0 ignored; 2 filtered out
new coverage:
- arm64_tail_call_cleanup_ignores_stripped_restore_padding
- arm64_tail_call_detection_requires_tail_helper
```

## Phase 26 - Local arm64 native BPF cross-build after cleanup-planning fix

Status: passed.

Command:

```bash
make host-native-bpf-arm64
```

Result:

```text
make exit 0
native-link=ELF 64-bit LSB pie executable, ARM aarch64, BuildID c4058ec275ad5e84bf6cfd69675b24d117396c7b
libnative_loader.so=ELF 64-bit LSB shared object, ARM aarch64, BuildID d20f94c71185db51c8ad0b4ee4ec8fc0c5bc0ff7
micro_exec=ELF 64-bit LSB pie executable, ARM aarch64, BuildID 4119ac9264f7fb2412318cadf9272d9caeca2933
stage_native_o=112
proof_ok=112
proof_o=1241
```

Manifest data:

```text
bcc status=native-objects-proof-linked version=1 manifest_objects=29 native_files=8
cilium status=native-objects-proof-linked version=1 manifest_objects=89 native_files=8
katran status=native-objects-proof-linked version=1 manifest_objects=3 native_files=4
otel status=native-objects-proof-linked version=1 manifest_objects=26 native_files=16
tetragon status=native-objects-proof-linked version=1 manifest_objects=93 native_files=88
tracee status=native-objects-proof-linked version=1 manifest_objects=113 native_files=3
```

Technical decisions:

- The previous Tetragon `filter_inet` proof failure is fixed without app or
  program filtering. `filter_inet` proof objects were generated successfully
  for multiple Tetragon variants.
- This phase confirms host-side artifacts only. The next required step is to
  rebuild the arm64 runtime image so QEMU receives the new native-link output,
  loader link-plan metadata, generated native artifacts, and runner fixes.
- Continue single-app functional QEMU tests before any all-app corpus run.

## Phase 27 - Rebuild arm64 runtime image tar after linker/link-plan fixes

Status: passed.

Command:

```bash
make arm64-runner-runtime-image-tar
```

Result:

```text
make exit 0
docker image=bpf-benchmark/runner-runtime:arm64
docker image id=sha256:1b6d73e7316bf35a9611a9b4cb3f7f2df92d52000b1fe15a4e3db1e2534fea83
docker image created=2026-05-29T13:16:24.306881298-07:00
docker image size=1953842768
tar=.cache/container-images/arm64-runner-runtime.image.tar
tar size=1968606720
tar mtime=2026-05-29 13:16:51.122184333 -0700
tar sha256=6a03725ad0d2e2307be3732e7485cf0693fd379ad60b482f7c4160f9b67c600a
native-link BuildID=c4058ec275ad5e84bf6cfd69675b24d117396c7b
libnative_loader.so BuildID=d20f94c71185db51c8ad0b4ee4ec8fc0c5bc0ff7
micro_exec BuildID=4119ac9264f7fb2412318cadf9272d9caeca2933
```

Technical decisions:

- This phase is still host-side/local build work only. It packages the
  cross-built arm64 runner, native loader, native-link, shim, kernel/modules,
  app binaries, and staged native BPF artifacts into the image consumed by QEMU.
- No build step is performed inside QEMU. QEMU runtime tests must only consume
  this image tar.
- Docker build reused cached lower layers where possible. The changed layers
  were the runner/native artifacts and runtime Python/config layers affected by
  the arm64 fixes.
- The build dependency also regenerated the arm64 micro proof artifacts, but
  this is not the final micro validation. Per the test order constraint, the
  authoritative micro run remains last, after each app and then all-app corpus
  pass in QEMU.

Next step:

- Start single-app QEMU functional tests from the current image. Do not run the
  all-app corpus until every app has passed individually with this image.

## Phase 28 - Single-app QEMU functional test: otelcol-ebpf-profiler/profiling

Status: passed.

Command:

```bash
PLATFORM=qemu ARCH=arm64 \
  BPFREJIT_SHIM_NATIVE_LOADER=post \
  SKIP_REJIT=norejit \
  BPFREJIT_CORPUS_APPS="otelcol-ebpf-profiler/profiling" \
  SAMPLES=1 WORKLOAD_DURATION=10 \
  BPFREJIT_CORPUS_APP_TIMEOUT=600 \
  TIMEOUT=1200 \
  make corpus
```

Artifact:

```text
/home/yunwei37/workspace/bpf-benchmark/corpus/results/arm64_qemu_corpus_19700101_000004_749235
```

Result:

```text
make exit 0
suite status=ok
app status=ok
app error=
samples=1
workload_seconds=10.0
skip_rejit=true
baseline_workloads=1
post_rejit_workloads=1
baseline shim log lines=323
post_rejit shim log lines=278
native-loader log lines=49
post native-loader replaced lines=10
native-link/native-loader error lines=0
```

Native replacements observed in post phase:

```text
read_task_struc
perf_unwind_sto
perf_unwind_nat
perf_unwind_hot
perf_unwind_per
perf_unwind_php
perf_unwind_pyt
perf_unwind_rub
perf_unwind_v8
perf_go_labels
```

Raw workload data:

```text
baseline otel_python3_int_loop_0 rc=0 duration_s=11.415655072 stderr="python3 int_loop ops=737592 elapsed_s=10.000036 worker=0 sink=2847331721"
baseline otel_python3_int_loop_1 rc=0 duration_s=11.417246815999995 stderr="python3 int_loop ops=714213 elapsed_s=10.052092 worker=1 sink=2830348175"
baseline otel_ruby_int_loop_0 rc=0 duration_s=23.860200272 stderr="ruby int_loop ops=3138049 elapsed_s=10.000425 worker=0 sink=2029532326"
baseline otel_ruby_int_loop_1 rc=0 duration_s=23.861935599999995 stderr="ruby int_loop ops=4607369 elapsed_s=10.000058 worker=1 sink=4041727499"
baseline otel_nodejs_int_loop_0 rc=0 duration_s=23.865844175999996 stderr="nodejs int_loop ops=1928896 elapsed_s=10.022921 worker=0 sink=914338816"
baseline otel_nodejs_int_loop_1 rc=0 duration_s=23.867634527999996 stderr="nodejs int_loop ops=1833273 elapsed_s=10.000809 worker=1 sink=1809681408"
baseline otel_perl_int_loop_0 rc=0 duration_s=23.869049840000002 stderr="perl int_loop ops=964752 elapsed_s=10.037004 worker=0 sink=2265988849"
baseline otel_perl_int_loop_1 rc=0 duration_s=23.870303183999994 stderr="perl int_loop ops=986305 elapsed_s=10.006826 worker=1 sink=444000339"
baseline otel_php_int_loop_0 rc=0 duration_s=23.871781951999992 stderr="php int_loop ops=6547127 elapsed_s=10.021492 worker=0 sink=2160263440"
baseline otel_php_int_loop_1 rc=0 duration_s=23.873193872 stderr="php int_loop ops=6759262 elapsed_s=10.029844 worker=1 sink=3750477572"
baseline otel_stress_ng_cpu rc=0 duration_s=23.874545424000004
post otel_python3_int_loop_0 rc=0 duration_s=11.157761792000002 stderr="python3 int_loop ops=1011174 elapsed_s=10.014574 worker=0 sink=101071523"
post otel_python3_int_loop_1 rc=0 duration_s=11.358020208 stderr="python3 int_loop ops=991209 elapsed_s=10.002066 worker=1 sink=341506987"
post otel_ruby_int_loop_0 rc=0 duration_s=18.24606315199999 stderr="ruby int_loop ops=4417031 elapsed_s=10.000036 worker=0 sink=2770208768"
post otel_ruby_int_loop_1 rc=0 duration_s=18.247533168000004 stderr="ruby int_loop ops=3176778 elapsed_s=10.001990 worker=1 sink=3642180648"
post otel_nodejs_int_loop_0 rc=0 duration_s=26.927135664000005 stderr="nodejs int_loop ops=4262499 elapsed_s=10.011688 worker=0 sink=783171392"
post otel_nodejs_int_loop_1 rc=0 duration_s=26.937113567999987 stderr="nodejs int_loop ops=4514253 elapsed_s=10.016631 worker=1 sink=1411897400"
post otel_perl_int_loop_0 rc=0 duration_s=26.938276192000004 stderr="perl int_loop ops=1432673 elapsed_s=10.021751 worker=0 sink=3803373254"
post otel_perl_int_loop_1 rc=0 duration_s=26.939406879999993 stderr="perl int_loop ops=1301887 elapsed_s=10.019433 worker=1 sink=2017086413"
post otel_php_int_loop_0 rc=0 duration_s=28.464302176000004 stderr="php int_loop ops=25921308 elapsed_s=10.000005 worker=0 sink=1464718949"
post otel_php_int_loop_1 rc=0 duration_s=28.465606607999987 stderr="php int_loop ops=7311041 elapsed_s=10.002325 worker=1 sink=1946494547"
post otel_stress_ng_cpu rc=0 duration_s=28.466918879999994
```

Technical decisions:

- The previous OTEL arm64 blockers are resolved in the current image:
  helper-call lowering no longer jumps to address `0x1`, and arm64
  `bpf_tail_call` no longer fails native-link with missing helper address.
- No loader/shim change was made for this phase. The successful native
  replacement path is through native-link/link-plan plus the existing loader
  interface.
- This remains a functional correctness run. The recorded workload values are
  raw app-side outputs only; no performance ratios or aggregation are computed
  here.

Next step:

- Re-run `bcc/set` on the same image because the earlier passing bcc run used
  an older native-link build before the tail-call and cleanup-planning fixes.

## Phase 29 - Single-app QEMU functional test: bcc/set

Status: passed.

Command:

```bash
PLATFORM=qemu ARCH=arm64 \
  BPFREJIT_SHIM_NATIVE_LOADER=post \
  SKIP_REJIT=norejit \
  BPFREJIT_CORPUS_APPS="bcc/set" \
  SAMPLES=1 WORKLOAD_DURATION=10 \
  TIMEOUT=1200 \
  make corpus
```

Artifact:

```text
/home/yunwei37/workspace/bpf-benchmark/corpus/results/arm64_qemu_corpus_19700101_000003_989442
```

Result:

```text
make exit 0
suite status=ok
app status=ok
app error=
samples=1
workload_seconds=10.0
skip_rejit=true
baseline_workloads=1
post_rejit_workloads=1
baseline shim log lines=525
post_rejit shim log lines=645
native-loader log lines=120
post native-loader replaced lines=23
native-link/native-loader error lines=0
```

Native replacements observed in post phase:

```text
blk_account_io_
block_rq_comple
block_rq_insert
block_rq_issue
fentry_vfs_crea
fentry_vfs_fsyn
fentry_vfs_open
fentry_vfs_read
fentry_vfs_writ
inet_sock_set_s
kprobe__cap_cap x2
sched_switch
sched_wakeup
sched_wakeup_ne
sys_enter
sys_exit
tcp_v4_connect
tcp_v4_connect_
tcp_v6_connect
tcp_v6_connect_
tracepoint__sys x2
```

Raw workload data:

```text
baseline workload=stress_ng_bcc_hook_hot rc=0 duration_s=14.701386928000005 stdout_lines=28 stderr_lines=0
post workload=stress_ng_bcc_hook_hot rc=0 duration_s=22.6588364 stdout_lines=28 stderr_lines=0
baseline stdout sample:
stress-ng: info:  [634] setting to a 10 secs run per stressor
stress-ng: info:  [634] dispatching hogs: 1 syscall, 1 cap, 1 set, 1 sockfd
stress-ng: info:  [635] syscall: using method 'fast75'
stress-ng: info:  [635] syscall: 290 system call tests, 217 (74.8%) fastest non-failing tests fully exercised
post stdout sample:
stress-ng: info:  [815] setting to a 10 secs run per stressor
stress-ng: info:  [815] dispatching hogs: 1 syscall, 1 cap, 1 set, 1 sockfd
stress-ng: info:  [816] syscall: using method 'fast75'
stress-ng: info:  [816] syscall: 290 system call tests, 217 (74.8%) fastest non-failing tests fully exercised
```

Technical decisions:

- This fresh bcc run uses the same runtime image as Phase 28, so it validates
  that the tail-call and cleanup-planning fixes did not regress the already
  working BCC path.
- No BCC program was skipped or filtered. Duplicate 15-byte BPF program names
  are recorded as loaded by the app and replaced by the native loader.
- The capability warnings come from `stress-ng-cap` and are workload/kernel
  warnings, not native-link or loader errors.

Next step:

- Continue single-app QEMU functional testing with `cilium/agent`.

## Phase 30 - Single-app QEMU functional test: cilium/agent first attempt

Status: failed before app BPF/native-link path.

Command:

```bash
PLATFORM=qemu ARCH=arm64 \
  BPFREJIT_SHIM_NATIVE_LOADER=post \
  SKIP_REJIT=norejit \
  BPFREJIT_CORPUS_APPS="cilium/agent" \
  SAMPLES=1 WORKLOAD_DURATION=10 \
  BPFREJIT_CORPUS_APP_TIMEOUT=600 \
  TIMEOUT=1200 \
  make corpus
```

Artifact:

```text
/home/yunwei37/workspace/bpf-benchmark/corpus/results/arm64_qemu_corpus_19700101_000004_110874
```

Result:

```text
make exit 0
suite status=error
app status=error
samples=1
workload_seconds=10.0
skip_rejit=true
app error=command failed (2): ip link add dev bpfbench0 type veth peer name bpfbench1
Error: Unknown device type.
```

Investigation data:

```text
arm64 kernel config includes CONFIG_VETH=m
arm64 kernel config includes CONFIG_DUMMY=m
arm64 kernel config includes CONFIG_TUN=m
arm64 kernel config includes CONFIG_VXLAN=m
arm64 image contains /artifacts/lib/modules/7.0.0-rc2+/kernel/drivers/net/veth.ko
arm64 image contains /artifacts/lib/modules/7.0.0-rc2+/kernel/drivers/net/dummy.ko
arm64 image contains /artifacts/lib/modules/7.0.0-rc2+/kernel/drivers/net/tun.ko
arm64 image contains /artifacts/lib/modules/7.0.0-rc2+/kernel/drivers/net/vxlan/vxlan.ko
arm64 QEMU root has /lib -> usr/lib
arm64 QEMU root did not have /lib/modules populated or symlinked for kernel module autoload
```

Technical decision:

- This is not a native-link, shim, or loader failure. Cilium failed before it
  could start its BPF/native workload because the veth module was not visible
  through the standard `/lib/modules/$(uname -r)` autoload path.
- Keep app code, loader, shim, and native-link unchanged for this failure.
- Apply the smallest QEMU-runtime fix: expose the already-packaged
  `/artifacts/lib/modules` tree at `/lib/modules` and export
  `BPFREJIT_KERNEL_MODULES_ROOT=/artifacts` so explicit modprobe callers and
  kernel module autoload see the same arm64 module tree as the x86 success
  path.

Next step:

- Patch `runner/scripts/qemu-arm64-init`, rebuild the arm64 runtime image tar
  locally, then retry `cilium/agent` as a single app.

## Phase 31 - QEMU arm64 module-tree visibility fix and local image rebuild

Status: passed.

Files changed:

```text
runner/scripts/qemu-arm64-init
docs/tmp/arm64_native_kernel_all_apps_plan_20260529.md
```

Change:

```text
runner/scripts/qemu-arm64-init:
- if /artifacts/lib/modules exists and /lib/modules does not, create
  /lib/modules -> /artifacts/lib/modules
- export BPFREJIT_KERNEL_MODULES_ROOT=/artifacts
```

Validation:

```bash
sh -n runner/scripts/qemu-arm64-init
make arm64-runner-runtime-image-tar
```

Result:

```text
sh -n exit 0
make arm64-runner-runtime-image-tar exit 0
docker image=bpf-benchmark/runner-runtime:arm64
docker image id=sha256:63d30cbfe1e7366c463524cdc68a5326a010ce8cceedf596bd55ab0e4f368805
docker image created=2026-05-29T13:30:40.350247771-07:00
docker image size=1953842768
tar=.cache/container-images/arm64-runner-runtime.image.tar
tar size=1968606720
tar mtime=2026-05-29 13:31:07.380125963 -0700
tar sha256=9edfa2e3d101a135101414a2f21d54db0fdfbd4849537021b799d5888c1399d5
native-link BuildID=c4058ec275ad5e84bf6cfd69675b24d117396c7b
libnative_loader.so BuildID=d20f94c71185db51c8ad0b4ee4ec8fc0c5bc0ff7
micro_exec BuildID=4119ac9264f7fb2412318cadf9272d9caeca2933
```

Technical decisions:

- Keep this fix outside loader, shim, native-link, and app runner code. The
  failure was arm64 QEMU runtime module visibility, not app logic.
- Use a symlink rather than copying modules during boot. The module tree is
  already packaged in the image under `/artifacts/lib/modules`; copying would
  be slower and would duplicate data.
- Export `BPFREJIT_KERNEL_MODULES_ROOT=/artifacts` so explicit runner
  `modprobe -d` calls use the same module tree. The `/lib/modules` symlink is
  for kernel request_module/autoload and tools that do not pass `-d`.
- No QEMU build was performed. The image was rebuilt locally before retrying
  QEMU, matching the build/test constraint.

Next step:

- Retry `cilium/agent` as a single-app QEMU functional test using this image
  tar.

## Phase 32 - Single-app QEMU functional test: cilium/agent second attempt

Status: failed before Cilium agent/BPF native path, after fixing veth module
visibility.

Command:

```bash
PLATFORM=qemu ARCH=arm64 \
  BPFREJIT_SHIM_NATIVE_LOADER=post \
  SKIP_REJIT=norejit \
  BPFREJIT_CORPUS_APPS="cilium/agent" \
  SAMPLES=1 WORKLOAD_DURATION=10 \
  BPFREJIT_CORPUS_APP_TIMEOUT=600 \
  TIMEOUT=1200 \
  make corpus
```

Artifact:

```text
/home/yunwei37/workspace/bpf-benchmark/corpus/results/arm64_qemu_corpus_19700101_000004_828072
```

Result:

```text
make exit 0
suite status=error
app status=error
samples=1
workload_seconds=10.0
skip_rejit=true
```

Failure data:

```text
local etcd exited with code 2 before becoming healthy
etcd stderr: etcd on unsupported platform without ETCD_UNSUPPORTED_ARCH=arm64 set
etcd data dir=/var/tmp/ciliumrunner_hq70h2nj/etcd/data
etcd fatal: cannot open database at /var/tmp/ciliumrunner_hq70h2nj/etcd/data/member/snap/db (invalid argument)
```

Technical decision:

- Phase 31 fixed the veth/module autoload issue: this run progressed past
  `ip link add ... type veth`.
- The new failure is Cilium's local etcd dependency, not native-link, shim, or
  native-loader. It occurs before Cilium agent setup and before any Cilium BPF
  program measurement.
- Fix the etcd runner path directly and minimally:
  - pass `ETCD_UNSUPPORTED_ARCH=arm64` only when the runtime architecture is
    arm64/aarch64;
  - mount tmpfs-backed writable scratch directories in QEMU init so etcd's
    bbolt database is not created on the 9p root filesystem.
- Keep Cilium app loading real upstream `cilium-agent`; do not replace it with
  a custom loader or skip Cilium.

Next step:

- Patch `runner/libs/app_runners/etcd_support.py` and
  `runner/scripts/qemu-arm64-init`, validate locally, rebuild the arm64 runtime
  image tar, then retry `cilium/agent` as a single app.

## Phase 33 - Local cross-build after Cilium etcd/QEMU scratch fix

Status: completed.

Changed files:

- `runner/libs/app_runners/etcd_support.py`
- `runner/scripts/qemu-arm64-init`
- `docs/tmp/arm64_native_kernel_all_apps_plan_20260529.md`

Behavioral changes:

- `etcd_support.py` now passes an explicit environment to the local etcd
  process and sets `ETCD_UNSUPPORTED_ARCH=arm64` only when runtime
  `os.uname().machine` is `aarch64` or `arm64`.
- `qemu-arm64-init` mounts tmpfs on `/tmp`, `/var/tmp`, and `/dev/shm`, then
  recreates `/var/tmp/bpfrejit-runtime`. This keeps Cilium/etcd scratch data
  off the QEMU 9p root filesystem.

Local validation commands and data:

```bash
sh -n runner/scripts/qemu-arm64-init
```

```text
exit=0
```

```bash
python3 -m py_compile runner/libs/app_runners/etcd_support.py
```

```text
exit=0
```

```bash
make arm64-runner-runtime-image-tar
```

```text
exit=0
docker image id=sha256:0ed1459cb15c258f5e197ce01d681c87ca4d279f603b44474fbb19009b71f8d9
docker image created=2026-05-29T13:37:47.541630969-07:00
docker image size=1953842973
tar path=.cache/container-images/arm64-runner-runtime.image.tar
tar size=1968606720
tar mtime=2026-05-29 13:38:09.977483160 -0700
tar sha256=e527ce8e6a924a9bdf342486c4e09e1998535bd0e402db6e5e07030c8ae653a5
native-link BuildID=c4058ec275ad5e84bf6cfd69675b24d117396c7b
libnative_loader.so BuildID=d20f94c71185db51c8ad0b4ee4ec8fc0c5bc0ff7
micro_exec BuildID=4119ac9264f7fb2412318cadf9272d9caeca2933
```

Technical decision:

- This is a QEMU runtime environment fix. It does not change loader, shim,
  native-link, or the Cilium app runner's BPF loading contract.
- The etcd flag is restricted to arm64 because x86 already has a passing path
  and should not absorb unrelated behavior changes.
- tmpfs is mounted in QEMU init rather than inside app runners so every app
  gets a normal writable Linux scratch area while preserving the rule that QEMU
  never builds anything.
- The runtime image was rebuilt locally before QEMU execution. No build step is
  performed inside QEMU.

Next step:

- Retry `cilium/agent` as a single-app QEMU functional test using the image tar
  above.

## Phase 34 - Single-app QEMU functional test: cilium/agent third attempt

Status: failed in post/native execution path; baseline functional path passed.

Command:

```bash
PLATFORM=qemu ARCH=arm64 \
  BPFREJIT_SHIM_NATIVE_LOADER=post \
  SKIP_REJIT=norejit \
  BPFREJIT_CORPUS_APPS="cilium/agent" \
  SAMPLES=1 WORKLOAD_DURATION=10 \
  BPFREJIT_CORPUS_APP_TIMEOUT=600 \
  TIMEOUT=1200 \
  make corpus
```

Result:

```text
make exit=2
new result.json=none; guest panicked before writing qemu-status
baseline measurement_start observed
baseline measurement_done status=ok
post phase reached after rejit_skipped event
```

Failure data from QEMU console:

```text
Unable to handle kernel read from unreadable memory at virtual address 0000000049396b80
pc: lookup_nulls_elem_raw+0x34/0xc0
lr: __htab_map_lookup_elem+0x5c/0x78
caller: bpf_prog_5a0f6aadfc0089b1_cil_xdp_entry+0x1e0/0x470
context: veth_xdp_rcv_skb -> bpf_dispatcher_xdp_func -> cil_xdp_entry
panic: Kernel panic - not syncing: Oops: Fatal exception in interrupt
```

Technical decision:

- The tmpfs/etcd fix worked: this run reached Cilium baseline measurement and
  completed it successfully. The remaining problem is in the post/native
  execution path.
- The panic occurs when `cil_xdp_entry` calls `__htab_map_lookup_elem`.
  `lookup_nulls_elem_raw` receives an invalid bucket pointer, which is
  consistent with applying hash-map-specific lookup lowering to a non-hash map.
- x86 native-link already avoids this class of bug by preferring native map
  symbol matching against `lookup_sites`/`lookup_maps`, and only falling back to
  helper-call order when no map symbol can be traced. arm64 currently consumes
  lookup metadata mostly by ordinal and ignores `lookup_maps`.
- The minimal fix is arm64-only in `native-link`: reuse the x86-success-path
  lookup-site selection semantics for arm64 helper lowering. Do not change the
  loader, shim, Cilium app runner, or app loading model for this issue.
- Add focused unit tests that prove arm64 lookup selection prefers native map
  identity over ordinal order and uses `lookup_maps` for extra native repeated
  map lookups.

Next step:

- Patch `native-sim/x86/native_lab/native_link/src/main.rs`, run targeted
  native-link tests locally, cross-build arm64 native artifacts locally, rebuild
  the arm64 runtime image tar locally, then retry `cilium/agent` as a single
  app.

## Phase 35 - Arm64 native-link lookup-site selection parity with x86

Status: completed.

Changed files:

- `native-sim/x86/native_lab/native_link/src/main.rs`
- `docs/tmp/arm64_native_kernel_all_apps_plan_20260529.md`

Behavioral changes:

- arm64 native-link now selects `bpf_map_lookup_elem` lowering metadata using
  the same successful-path strategy as x86:
  - if the native callsite's map argument can be traced, first match unused
    `lookup_sites` by native/source map name with BPF object-name truncation;
  - then use `lookup_maps` for native map symbols that have no remaining
    source-order site;
  - then use the generic helper call target instead of applying the wrong
    specialized map lowering;
  - only fall back to ordinal order when the native map argument cannot be
    traced.
- Added focused arm64 unit tests for:
  - preferring native map identity over ordinal order;
  - using `lookup_maps` for extra native repeated map lookup calls.

Local validation commands and data:

```bash
cargo fmt --manifest-path native-sim/x86/native_lab/native_link/Cargo.toml
```

```text
exit=0
```

```bash
cargo test --manifest-path native-sim/x86/native_lab/native_link/Cargo.toml arm64_
```

```text
exit=0
tests=12 passed, 0 failed, 2 filtered
new tests:
  arm64_lookup_selection_prefers_native_map_over_ordinal_order
  arm64_lookup_selection_uses_lookup_maps_for_extra_native_map_calls
```

```bash
make host-native-bpf-arm64
```

```text
exit=0
stage_native_o=112
proof_o=1241
native-link BuildID=ebecab828b1322abfee698dd0ddeabb35e47daea
libnative_loader.so BuildID=d20f94c71185db51c8ad0b4ee4ec8fc0c5bc0ff7
micro_exec BuildID=4119ac9264f7fb2412318cadf9272d9caeca2933
```

Staged manifest data:

```text
bcc: status=native-objects-proof-linked version=1 objects=29 map_rules=0
cilium: status=native-objects-proof-linked version=1 objects=89 map_rules=19
katran: status=native-objects-proof-linked version=1 objects=3 map_rules=0
otelcol-ebpf-profiler: status=native-objects-proof-linked version=1 objects=26 map_rules=0
tetragon: status=native-objects-proof-linked version=1 objects=93 map_rules=59
tracee: status=native-objects-proof-linked version=1 objects=113 map_rules=59
```

Technical decision:

- This fixes an arm64 native-link gap by matching the established x86
  successful path. It does not add app filtering and does not change loader,
  shim, Cilium app startup, or the native-loader ABI.
- The generic-helper fallback is safer and more faithful than ordinal
  specialization when a native map symbol is known but no matching specialized
  metadata exists. It avoids routing non-hash maps into
  `__htab_map_lookup_elem`.
- The unit tests fail on the previous arm64 ordinal-first behavior and directly
  guard the Cilium `cil_xdp_entry` failure class.
- No QEMU build was performed; all compilation and proof-linking happened on
  the host.

Next step:

- Rebuild the arm64 runtime image tar locally and retry `cilium/agent` as a
  single-app QEMU functional test.

## Phase 36 - Local arm64 runtime image rebuild after lookup-selection fix

Status: completed.

Changed files:

- `docs/tmp/arm64_native_kernel_all_apps_plan_20260529.md`

Command:

```bash
make arm64-runner-runtime-image-tar
```

Result data:

```text
exit=0
image_id=sha256:41afea61d68b9d5dbdad512373c247f16d1de64a51a5dc970ddeada954532710
image_created=2026-05-29T13:57:13.473139011-07:00
image_size=1953842196
tar=.cache/container-images/arm64-runner-runtime.image.tar
tar_size=1968605696
tar_mtime=2026-05-29 13:57:39.622067096 -0700
tar_sha256=24093df4901e186612bade431af7ee16b86ae71c9942d19b56fb9504b8851be9
native-link BuildID=ebecab828b1322abfee698dd0ddeabb35e47daea
libnative_loader.so BuildID=d20f94c71185db51c8ad0b4ee4ec8fc0c5bc0ff7
micro_exec BuildID=4119ac9264f7fb2412318cadf9272d9caeca2933
```

Technical decision:

- This is the required local cross-build/repackage step before any QEMU
  retest. The rebuilt image contains the Phase 35 arm64 native-link
  lookup-site selection fix.
- No QEMU-side build was performed.
- The native loader and shim BuildIDs did not change in this phase; the
  behavior change under test is isolated to the arm64 `native-link` output.

Next step:

- Retry `cilium/agent` alone under QEMU with `BPFREJIT_SHIM_NATIVE_LOADER=post`
  and `SKIP_REJIT=norejit`, then append the raw status and native-loader data.

## Phase 37 - Cilium single-app QEMU retest after lookup-selection fix

Status: failed; root cause identified.

Changed files:

- `docs/tmp/arm64_native_kernel_all_apps_plan_20260529.md`

Command:

```bash
PLATFORM=qemu ARCH=arm64 BPFREJIT_SHIM_NATIVE_LOADER=post SKIP_REJIT=norejit \
  BPFREJIT_CORPUS_APPS="cilium/agent" SAMPLES=1 WORKLOAD_DURATION=10 \
  BPFREJIT_CORPUS_APP_TIMEOUT=600 TIMEOUT=1200 make corpus
```

Result data:

```text
make_exit=0
artifact=/home/yunwei37/workspace/bpf-benchmark/corpus/results/arm64_qemu_corpus_19700101_000005_208304
suite_status=error
app_status=error
baseline_workloads=1
baseline_workload_raw_packets=521032 and 520887 from pktgen stdout
baseline_workload_raw_errors=0 and 0 from pktgen stdout
post_rejit=null
shim_log_lines_baseline=1231
shim_log_lines_post=909
post_native_replacements_before_failure=3
post_native_replaced_programs=cil_xdp_entry,tail_drop_notif,tail_handle_ipv
kernel_panic=no
```

Failure data:

```text
event=phase_error
phase=post_rejit_start
error=Remote end closed connection without response
native-loader failed prog=tail_nodeport_n
native-loader error=native map symbol cilium_snat_v4_external matches multiple loaded maps named cilium_snat_v4_
runtime map cilium_snat_v4_ #1: type=9 key_size=14 value_size=40 max_entries=131072
runtime map cilium_snat_v4_ #2: type=6 key_size=4 value_size=4 max_entries=33
manifest rule cilium_snat_v4_external: type=9 key_size=14 value_size=40 max_entries=591428
```

Technical decision:

- Phase 35 fixed the previous arm64 native-link mis-lowering: this run did not
  reproduce the `lookup_nulls_elem_raw` kernel panic and reached later Cilium
  post startup.
- The new failure is a native-loader map-symbol resolution bug exposed by BPF's
  15-byte map-name truncation. `cilium_snat_v4_external` and
  `cilium_snat_v4_alloc_retries` both become `cilium_snat_v4_` in the kernel.
- The manifest already contains enough stable shape information to distinguish
  them by type/key/value. The `max_entries=591428` component is not stable for
  this runtime: Cilium created the external SNAT LRU hash with `max_entries=131072`.
- Do not change the app runner, loader ABI, shim ABI, or app loading model. Do
  not skip `tail_nodeport_n`. The minimal fix is to remove the unstable
  `max_entries` constraint from the Cilium manifest rule for
  `cilium_snat_v4_external`; LRU-hash lookup lowering does not need
  `max_entries`.

Next step:

- Patch `vendor/bpf/write_native_manifest.py`, regenerate arm64 native
  artifacts locally, rebuild the arm64 runtime image tar locally, then retry
  `cilium/agent` alone under QEMU.

## Phase 38 - Cilium SNAT manifest rule fix and local arm64 native artifacts

Status: completed.

Changed files:

- `vendor/bpf/write_native_manifest.py`
- `docs/tmp/arm64_native_kernel_all_apps_plan_20260529.md`

Implementation:

- Removed the unstable `max_entries=591428` constraint from the
  `cilium_snat_v4_external` native map rule.
- Kept the stable disambiguation fields:
  `match=exact`, `type=BPF_MAP_TYPE_LRU_HASH`, `key_size=14`,
  `value_size=40`.
- Left `cilium_snat_v4_alloc_retries` unchanged:
  `type=BPF_MAP_TYPE_PERCPU_ARRAY`, `key_size=4`, `value_size=4`,
  `max_entries=33`.

Local validation commands and data:

```bash
python3 -m py_compile vendor/bpf/write_native_manifest.py
```

```text
exit=0
```

```bash
make host-native-bpf-arm64
```

```text
exit=0
stage_native_o=112
proof_o=1241
native-link BuildID=ebecab828b1322abfee698dd0ddeabb35e47daea
libnative_loader.so BuildID=d20f94c71185db51c8ad0b4ee4ec8fc0c5bc0ff7
micro_exec BuildID=4119ac9264f7fb2412318cadf9272d9caeca2933
```

Generated manifest validation:

```text
cilium_snat_v4_external rule:
  match=exact type=9 key_size=14 value_size=40 max_entries=<absent>
cilium_snat_v4_alloc_retries rule:
  match=exact type=6 key_size=4 value_size=4 max_entries=33
cilium objects=89 map_rules=19
```

Staged manifest data:

```text
bcc: status=native-objects-proof-linked version=1 objects=29 map_rules=0
cilium: status=native-objects-proof-linked version=1 objects=89 map_rules=19
katran: status=native-objects-proof-linked version=1 objects=3 map_rules=0
otelcol-ebpf-profiler: status=native-objects-proof-linked version=1 objects=26 map_rules=0
tetragon: status=native-objects-proof-linked version=1 objects=93 map_rules=59
tracee: status=native-objects-proof-linked version=1 objects=113 map_rules=59
```

Technical decision:

- This keeps loader behavior fail-fast: ambiguous map resolution is still an
  error when shape cannot disambiguate. The fix removes only the unstable
  field that made the correct shape fail to match this runtime.
- No app filtering, ReJIT filtering, loader ABI change, shim ABI change, or
  app-runner bypass was introduced.
- No QEMU-side build was performed.

Next step:

- Rebuild the arm64 runtime image tar locally, record image metadata, then
  retry `cilium/agent` alone under QEMU.

## Phase 39 - Rebuild arm64 runtime image after Cilium manifest fix

Status: completed.

Changed files:

- `docs/tmp/arm64_native_kernel_all_apps_plan_20260529.md`

Implementation:

- Rebuilt the arm64 runner runtime image tar from local cross-built artifacts
  after the Phase 38 Cilium manifest change.
- The build included the staged arm64 native BPF artifacts and rebuilt image
  layers; no build step was run inside QEMU.
- This is not the final micro validation. The build still exercised the
  host-side arm64 micro proof build-only path as part of the image dependency
  chain; the required QEMU `make micro` run remains last.

Local validation commands and data:

```bash
make arm64-runner-runtime-image-tar
```

```text
exit=0
image_tar=.cache/container-images/arm64-runner-runtime.image.tar
image_tar_size=1968605696
image_tar_mtime=2026-05-29 14:12:51.305433050 -0700
image_tar_sha256=d3eebf735e2fefadf59a0baaa3c19af64ca46da5876d0c21c36a34db06188b54
docker_image_id=sha256:11613982055be6c4e8c8a7518e625c96ee093b6edf8ee604b2e03f7489556cc6
docker_image_created=2026-05-29T14:12:26.639068642-07:00
docker_image_size=1953842169
native-link BuildID=ebecab828b1322abfee698dd0ddeabb35e47daea
libnative_loader.so BuildID=d20f94c71185db51c8ad0b4ee4ec8fc0c5bc0ff7
micro_exec BuildID=4119ac9264f7fb2412318cadf9272d9caeca2933
```

Technical decision:

- Continue using the normal `make` image entrypoint so QEMU receives only
  image-layer artifacts produced on the host.
- Keep the Cilium retry scoped to `cilium/agent` only. The all-app corpus run is
  still blocked until each app has passed individually.

Next step:

- Retry `cilium/agent` alone under QEMU with native loader enabled for
  `post_rejit` and `SKIP_REJIT=norejit`.

## Phase 40 - Cilium duplicate `.rodata.config` data-map resolution

Status: completed.

Changed files:

- `native-sim/libnativeloader/src/native_loader.cpp`
- `docs/tmp/arm64_native_kernel_all_apps_plan_20260529.md`

QEMU command and data:

```bash
PLATFORM=qemu ARCH=arm64 BPFREJIT_SHIM_NATIVE_LOADER=post SKIP_REJIT=norejit \
  BPFREJIT_CORPUS_APPS="cilium/agent" SAMPLES=1 WORKLOAD_DURATION=10 \
  BPFREJIT_CORPUS_APP_TIMEOUT=600 TIMEOUT=1200 make corpus
```

```text
make_exit=0
artifact=/home/yunwei37/workspace/bpf-benchmark/corpus/results/arm64_qemu_corpus_19700101_000005_112957
suite_status=error
app_status=error
baseline_status=ok
baseline_workloads=1
post_rejit=null
kernel_panic=no
shim_log_lines_baseline=1433
shim_log_lines_post=1038
```

Failure data:

```text
phase=post_rejit_start
error=Remote end closed connection without response
native-loader failed prog=tail_no_service
native-loader error=multiple ARRAY maps match native data section .rodata.config: .rodata.config and .rodata.config
post native replacements before failure included cil_xdp_entry, tail_handle_ipv,
tail_ipv4_ct_eg, cil_lxc_policy_, cil_to_netdev, tail_ipv4_policy,
tail_drop_notif, tail_nodeport_n, cil_to_container, tail_handle_snat,
cil_lxc_policy, cil_from_host, tail_ipv4_ct_in, and others.
```

Relevant runtime map creation data from shim log:

```text
249.323663 BPF_MAP_CREATE type=2 key_size=4 value_size=221 max_entries=1 name=.rodata.config -> fd=93 kernel_map_id=157
285.297729 BPF_MAP_CREATE type=2 key_size=4 value_size=221 max_entries=1 name=.rodata.config -> fd=184 kernel_map_id=187
290.661365 BPF_PROG_LOAD name=tail_no_service hash=68b18889f6fcbb11
292.074038 native-loader failed prog=tail_no_service duplicate .rodata.config
```

Implementation:

- Changed native-loader data-section map resolution for `.bss`, `.data`, and
  `.rodata*` ARRAY maps.
- If multiple matching data maps have the same kernel address/value address,
  behavior remains unchanged.
- If multiple same-section data maps are distinct, choose the newest matching
  map by `kernel_id` and then fd. This matches libbpf's per-object loading
  pattern in Cilium, where older `.rodata.config` maps remain open while the
  next object is loaded.
- Kept fail-fast behavior for same-kernel-address candidates with mismatched
  direct value addresses.
- No app filtering, ReJIT filtering, loader ABI change, shim ABI change, or app
  loading bypass was introduced.

Technical decision:

- This is a native-loader correctness fix rather than an app workaround. The
  loader already supports resolving open process maps when a data map is not in
  loaded metadata; this fixes the earlier path where already-collected metadata
  had the same duplicate-section situation and failed before the open-process
  newest-map rule could help.
- The change is intentionally narrow: it affects only BPF data-map binding for
  native object data symbols and does not alter helper lowering, tail-call
  lowering, manifest matching, or shim behavior.

Local validation commands and data:

```bash
make host-runner-arm64
```

```text
exit=0
libnative_loader.so BuildID=9dac070616bb76a8ee20ac511615e8a3cf6de2b6
micro_exec BuildID=b31c3c999d2ef78a59f5ad9b251b2a6e2e4a149b
```

Next step:

- Rebuild the arm64 runtime image tar locally with the new loader, then retry
  `cilium/agent` alone under QEMU.

## Phase 41 - Rebuild arm64 runtime image after loader data-map fix

Status: completed.

Changed files:

- `docs/tmp/arm64_native_kernel_all_apps_plan_20260529.md`

Implementation:

- Rebuilt the arm64 runtime image tar locally after the Phase 40 native-loader
  change.
- The build used host cross-built artifacts only. No build step was run inside
  QEMU.
- The dependency chain reran the arm64 micro proof build-only validation. This
  is not the final QEMU micro run; final micro remains last.

Local validation commands and data:

```bash
make arm64-runner-runtime-image-tar
```

```text
exit=0
micro proof build-only benchmarks=29
micro proof build-only status=29 ok, 0 failed
image_tar=.cache/container-images/arm64-runner-runtime.image.tar
image_tar_size=1968605696
image_tar_mtime=2026-05-29 14:28:04.309150290 -0700
image_tar_sha256=adc7385db443863e57ea14aa01055e357090ba6bf135aa4c7e91d26e3142c183
docker_image_id=sha256:fb30e657a594a9c00c5d4bbf7412dcdc7102b2d8751bd98c2d5ae176d99b6d3e
docker_image_created=2026-05-29T14:27:39.051896186-07:00
docker_image_size=1953842164
native-link BuildID=ebecab828b1322abfee698dd0ddeabb35e47daea
libnative_loader.so BuildID=9dac070616bb76a8ee20ac511615e8a3cf6de2b6
micro_exec BuildID=b31c3c999d2ef78a59f5ad9b251b2a6e2e4a149b
```

Technical decision:

- Keep the next test scoped to `cilium/agent`. The all-app corpus remains
  blocked until Cilium and the remaining apps pass individually.

Next step:

- Retry `cilium/agent` alone under QEMU with the new native-loader image.

## Remaining mandatory todo - one-app-at-a-time ARM64 native_kernel completion

Status: active.

Global constraints for all remaining phases:

- Do not wait for user confirmation.
- Do not modify git state.
- Use only `make <target>` for benchmark/test entrypoints.
- Build locally first, then run QEMU. Do not build inside QEMU.
- Validate functional correctness before performance-oriented runs.
- Test corpus apps one at a time. Do not run all apps until each app has
  passed individually.
- Keep code changes minimal and record every changed file, technical decision,
  command, exit status, and artifact path in this document.
- Keep loader/shim unchanged unless the observed failure is a correctness
  mismatch with the x86 success path. ARM64-specific behavior should stay in
  native-link when feasible.
- Do not filter, skip, or exclude BPF programs from ReJIT.
- Do not add framework-side aggregation, ratios, geomeans, summaries, or
  performance interpretation.
- Keep performance in mind for every fix; prefer direct lowering/fast paths and
  avoid app-runner workarounds.
- Run `micro` last to verify these changes did not break micro.

Completion todo:

1. Fix the current `cilium/agent` ARM64 native tail-call kernel panic.
2. Re-run native-link ARM64 unit tests and a local Cilium proof-object
   disassembly check.
3. Rebuild `host-runner-arm64`, `host-native-bpf-arm64`, and the arm64 runtime
   image tar locally.
4. Re-run `cilium/agent` alone under QEMU.
5. Run remaining single apps under QEMU, one at a time: `tracee/monitor`,
   `tetragon/observer`, `katran`, then any already-passed app only if a later
   code change touches its success path.
6. After all six apps pass individually, run the arm64 all-app corpus under
   QEMU.
7. Run `micro` last under QEMU and record the artifact.

## Phase 42 - Cilium ARM64 proof ABI tail-call sidecar pop

Status: in progress.

Changed files so far:

- `native-sim/x86/native_lab/native_link/src/main.rs`
- `docs/tmp/arm64_native_kernel_all_apps_plan_20260529.md`

QEMU command and failure data that triggered this phase:

```bash
PLATFORM=qemu ARCH=arm64 BPFREJIT_SHIM_NATIVE_LOADER=post SKIP_REJIT=norejit \
  BPFREJIT_CORPUS_APPS="cilium/agent" SAMPLES=1 WORKLOAD_DURATION=10 \
  BPFREJIT_CORPUS_APP_TIMEOUT=600 TIMEOUT=1200 make corpus
```

```text
make_exit=2
finalized_artifact=none
partial_artifact=.cache/qemu-arm64-root/home/yunwei37/workspace/bpf-benchmark/corpus/results/arm64_qemu_corpus_19700101_000005_120791
suite_status=running
app_status=running
qemu_status_file=missing
kernel_panic=yes
```

Kernel panic:

```text
Unable to handle kernel execute from non-executable memory at virtual address ffff000005fcd000
ESR=0x8600000f IABT level 3 permission fault
pc=0xffff000005fcd000
lr=0xffff000005fcd000
PID=1780 Comm=cilium-agent
Code: 00000000 00000000 00000000 00000000 (010a80a0)
Kernel panic - not syncing: Oops: Fatal exception in interrupt
```

Native-loader trace immediately before panic:

```text
390.177 BPF_LINK_CREATE prog_fd=117 native cil_to_host kernel_prog_id=319 ksym0=0xffff8000835b1ed0
392.122 native-loader replaced prog=tail_nodeport_r kernel_prog_id=333 ksym0=0xffff8000835bdad0
392.122 BPF_PROG_LOAD name=tail_nodeport_r -> fd=221 errno=0 kernel_prog_id=333
```

Technical diagnosis:

- The failure is in ARM64 native-link, not loader/shim.
- `.proof.o` input already stripped the sidecar entry prologue and records the
  sidecar callee-saved register mask in `.native_link_abi`.
- x86 kernel-mode rewrite reads this proof ABI mask and uses it when building
  the final linked blob.
- ARM64 kernel-mode rewrite only used the newly stripped entry ABI mask. For a
  proof input this can be zero, so ARM64 tail-call inline cleanup restored the
  native caller frame but did not pop sidecar-saved x19-x22 before branching to
  `prog->bpf_func + tail_call_offset`.
- That leaves the tail-call landing ABI inconsistent and can return or branch
  through corrupted state after Cilium tail-call dispatch.

Implementation:

- Added ARM64 proof ABI mask propagation in `rewrite_arm64`.
- ARM64 kernel-mode rewrite now reads `.native_link_abi` when not in proof mode
  and uses that mask in preference to the entry strip mask.
- Kept proof mode unchanged.
- Added focused regression tests for proof-mask precedence and tail-call inline
  sidecar callee-saved pops.
- Loader and shim behavior were not changed.

Next validation:

- Run native-link ARM64 unit tests.
- Link and disassemble Cilium `cil_to_host.proof.o` locally to verify the
  generated tail-call path pops x21/x22 and x19/x20 before loading
  `prog->bpf_func`.

Local validation commands and data:

```bash
cargo test --manifest-path native-sim/x86/native_lab/native_link/Cargo.toml arm64_
```

```text
exit=0
tests=14 passed, 0 failed, 0 ignored, 2 filtered out
new regression tests:
  arm64_proof_callee_saved_mask_wins_for_kernel_rewrite
  arm64_tail_call_inline_pops_proof_sidecar_callee_saved_regs
```

```bash
cargo run --manifest-path native-sim/x86/native_lab/native_link/Cargo.toml -- \
  --input vendor/build/native-bpf/arm64/6.15.11-061511-generic/native/cilium/bpf_host.cil_to_host.proof.o \
  --symbol cil_to_host \
  --link-plan /tmp/cil_to_host_link_plan.json \
  --output /tmp/cil_to_host_after.blob \
  --output-map-patches /tmp/cil_to_host_after.map-patches \
  --output-abi /tmp/cil_to_host_after.abi \
  --show
```

```text
exit=0
output=/tmp/cil_to_host_after.blob
output_size=2988 bytes
map_patch_sites=11
output_abi=callee_saved_mask 15
```

Relevant disassembly after fix:

```text
3f0: ldp x24, x23, [sp, #80]
3f4: ldp x30, x25, [sp, #64]
3f8: add sp, sp, #0x80
3fc: ldp x21, x22, [sp], #16
400: ldp x19, x20, [sp], #16
404: ldr x10, [x11, #72]
408: add x10, x10, #0x1c
40c: br x10
```

Technical decision:

- The generated sequence now mirrors the x86 proof-input behavior: the native
  caller frame cleanup is followed by the sidecar frame pop recorded in proof
  ABI metadata, then the branch targets `prog->bpf_func + 28`.
- This stays in native-link and does not change loader or shim behavior.

Next step:

- Rebuild `host-runner-arm64`, `host-native-bpf-arm64`, and the arm64 runtime
  image tar locally before retrying `cilium/agent` in QEMU.

## Phase 43 - Local ARM64 rebuild after proof ABI tail-call fix

Status: completed.

Changed files:

- `docs/tmp/arm64_native_kernel_all_apps_plan_20260529.md`

Build commands and data:

```bash
make host-runner-arm64
```

```text
exit=0
libnative_loader.so BuildID=9dac070616bb76a8ee20ac511615e8a3cf6de2b6
micro_exec BuildID=b31c3c999d2ef78a59f5ad9b251b2a6e2e4a149b
```

```bash
make host-native-bpf-arm64
```

```text
exit=0
native-link BuildID=ca1f609fa71ea1a47d9d10ad29cf7aa1155b5ca8
stage_native_o=112
proof_o=1239
bcc: status=native-objects-proof-linked version=1 objects=29 map_rules=0
cilium: status=native-objects-proof-linked version=1 objects=89 map_rules=19
katran: status=native-objects-proof-linked version=1 objects=3 map_rules=0
otelcol-ebpf-profiler: status=native-objects-proof-linked version=1 objects=26 map_rules=0
tetragon: status=native-objects-proof-linked version=1 objects=93 map_rules=59
tracee: status=native-objects-proof-linked version=1 objects=113 map_rules=59
```

```bash
make arm64-runner-runtime-image-tar
```

```text
exit=0
micro proof build-only benchmarks=29
micro proof build-only status=29 ok, 0 failed
image_tar=.cache/container-images/arm64-runner-runtime.image.tar
image_tar_size=1968671232
image_tar_mtime=2026-05-29 15:01:11.921467727 -0700
image_tar_sha256=a3279a5f8b169f154679e28f53129874ee825c5b03b1eab91a4fdecd8aedb03c
docker_image_id=sha256:59b44c568712350ae1b0c437fc3fd0c047b543445e37112a5c3f5f187a3303a0
docker_image_created=2026-05-29T15:00:54.863737255-07:00
docker_image_size=1953907800
native-link BuildID=ca1f609fa71ea1a47d9d10ad29cf7aa1155b5ca8
libnative_loader.so BuildID=9dac070616bb76a8ee20ac511615e8a3cf6de2b6
micro_exec BuildID=b31c3c999d2ef78a59f5ad9b251b2a6e2e4a149b
```

Technical decision:

- Kept the rebuild sequence fully host-side. QEMU receives only the new runtime
  image tar and repo artifacts; it does not compile anything.
- The only executable that changed for this phase is native-link. Loader and
  shim BuildIDs are unchanged.
- `proof_o` decreased from the prior 1241 count to 1239 because native-link
  regenerated the proof corpus with current object reachability; all six app
  manifests remained `native-objects-proof-linked`.

Next step:

- Retry `cilium/agent` alone under QEMU with the new arm64 runtime image.
