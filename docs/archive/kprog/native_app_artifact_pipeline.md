# Native App Artifact Pipeline Design

This is a design draft for building native sidecar artifacts for the seven
upstream corpus apps. It intentionally does not describe a custom app loader:
each app still starts normally and loads its own BPF programs. Native artifacts
are only sidecars consumed later by the live ReJIT/native backend.

## Goals

- Build a native object for every BPF program that can be loaded by every
  supported upstream app.
- Preserve the names and relocations needed by `native-link`: program symbols,
  helper symbols, map symbols, global data sections, and CO-RE-derived offsets.
- Keep benchmark execution on the existing app-level boundary: real upstream
  app startup, shim/daemon live discovery, then native apply against live
  programs.
- Store artifacts in the existing app artifact layer so Python/config changes
  do not rebuild apps, kernel, daemon, or native sidecars.
- Fail fast when a native sidecar cannot be produced or cannot be matched to a
  live program. Do not silently fall back to stock BPF.

## Non-Goals

- Do not load app `.bpf.o` files directly through a framework loader.
- Do not replace upstream app binaries with benchmark-specific binaries.
- Do not filter programs by app, program type, helper set, or map type.
- Do not compute runtime summaries, ratios, coverage scores, or rollups in the
  benchmark framework.
- Do not put long-lived build artifacts under `/tmp`, `corpus/results`, or
  `.cache`.

## Artifact Location

Host build output should live under the owning app artifact tree, keyed by the
target kernel identity:

```text
vendor/build/<vendor-arch>/<app>/native-bpf/<kernel-id>/
```

Examples:

```text
vendor/build/x86/katran/native-bpf/6.x-bpfrejit-<vmlinux-sha>/
vendor/build/x86/tetragon/native-bpf/6.x-bpfrejit-<vmlinux-sha>/
vendor/build/arm64/tracee/native-bpf/6.x-bpfrejit-<vmlinux-sha>/
```

Runtime image output should live under the existing repo artifact root:

```text
/artifacts/user/repo-artifacts/<run-target-arch>/<app>/native-bpf/<kernel-id>/
```

The runner already exposes this root through `BPFREJIT_REPO_ARTIFACT_ROOT`.
Runtime lookup should therefore use:

```text
repo_artifact_root() / <app> / "native-bpf" / <kernel-id>
```

This keeps sidecars next to the app that produced the live BPF programs:

```text
/artifacts/user/repo-artifacts/x86_64/katran/native-bpf/6.x-bpfrejit-<vmlinux-sha>/
/artifacts/user/repo-artifacts/x86_64/cilium/native-bpf/6.x-bpfrejit-<vmlinux-sha>/
/artifacts/user/repo-artifacts/x86_64/otelcol-ebpf-profiler/native-bpf/6.x-bpfrejit-<vmlinux-sha>/
```

For Tracee and Tetragon, `repo-artifacts/<arch>/<app>` is already a symlink to
`/artifacts/tracee` or `/artifacts/tetragon`, so the same logical path still
works.

## Bundle Layout

Each app gets one root manifest and one directory per upstream BPF object:

```text
native-bpf/
  6.x-bpfrejit-<vmlinux-sha>/
    manifest.v1.json
    objects/
      balancer/
        source.bpf.o
        core.resolved.json
        core_native.h
        native.o
        compile_commands.json
        build.log
        relocs.json
      bpf_generic_kprobe_v61/
        source.bpf.o
        core.resolved.json
        core_native.h
        native.o
        compile_commands.json
        build.log
        relocs.json
```

`source.bpf.o` is the canonical upstream object produced by the real app build.
It is not loaded by the benchmark framework. It is kept only for identity,
debugging, and static metadata validation.

`core.resolved.json` is the build-time CO-RE lowering record for the target
kernel BTF. `core_native.h` is the generated native-mode header or shim consumed
by the native compile. If the implementation uses rewritten C/LLVM IR instead
of a header-only shim, the rewritten input should live beside these files and be
referenced from the manifest.

`native.o` should be a relocatable native ELF object, not a fully linked shared
library. App native artifacts need unresolved relocations for helpers, maps,
rodata/data/bss, and reachable subprograms. CO-RE relocations are different:
they must already be resolved for the target kernel before native codegen.
This matches the stage2 direction better than the older micro `.native.so` path.

`relocs.json` is a build-side extract of relocation intent. It is an artifact,
not a benchmark result. It should list the raw relocations that the runtime
native backend is expected to resolve against live kernel state.

## Manifest Schema

The root manifest should be strict and versioned:

```json
{
  "schema": 1,
  "app": "katran",
  "arch": "x86_64",
  "kernel": {
    "release": "6.x-bpfrejit",
    "vmlinux_sha256": "...",
    "vmlinux_btf_sha256": "..."
  },
  "objects": [
    {
      "name": "balancer",
      "source_bpf_object": "objects/balancer/source.bpf.o",
      "source_bpf_sha256": "...",
      "core": {
        "strategy": "build-time-core-lowering",
        "resolved": "objects/balancer/core.resolved.json",
        "native_header": "objects/balancer/core_native.h"
      },
      "native_object": "objects/balancer/native.o",
      "native_object_sha256": "...",
      "programs": [
        {
          "symbol": "balancer_ingress",
          "section": "xdp",
          "prog_name": "balancer_ingress",
          "prog_type": "xdp"
        }
      ],
      "maps": [
        {
          "symbol": "reals",
          "name": "reals",
          "type": "hash",
          "key_size": 4,
          "value_size": 16
        }
      ],
      "globals": [
        {
          "section": ".rodata",
          "map_name": "balancer.rodata"
        }
      ],
      "helpers": [
        "bpf_map_lookup_elem",
        "bpf_tail_call"
      ]
    }
  ]
}
```

The manifest must not contain benchmark summaries or derived performance data.
It is allowed to contain identity and ABI data needed to match a live program
to a native sidecar.

## Compile Model

Every app BPF source is compiled twice from the same app build inputs:

1. Normal BPF object, using the upstream app build path.
2. Build-time CO-RE lowering record, using the canonical BPF object's
   `.BTF`/`.BTF.ext` plus the target kernel BTF.
3. Native relocatable object, using the same source, include paths, generated
   headers, app config headers, and the lowered CO-RE/native shim for the target
   kernel.

The native compile should use a dedicated macro such as
`BPFREJIT_NATIVE_APP`, not `MICRO_NATIVE`, so app-specific headers can avoid
micro assumptions.

Baseline native flags:

```text
-O2 -g -fPIC -c
-fno-plt
-fomit-frame-pointer
-fno-stack-protector
-fno-asynchronous-unwind-tables
-fno-unwind-tables
-fno-jump-tables
-mllvm -switch-to-lookup=false
-DBPFREJIT_NATIVE_APP
```

x86_64 should also use:

```text
-mno-red-zone
```

The target triple must match the runtime kernel architecture:

```text
x86_64-linux-gnu
aarch64-linux-gnu
```

## Helper Symbols

Native app builds need a shared native helper header. In BPF mode it includes
the normal upstream helper headers. In native mode it exposes helpers as
extern functions with stable kernel helper names:

```c
#ifdef BPFREJIT_NATIVE_APP
extern void *bpf_map_lookup_elem(void *map, const void *key);
extern long bpf_map_update_elem(void *map, const void *key,
                                const void *value, unsigned long flags);
extern unsigned long long bpf_ktime_get_ns(void);
extern long bpf_probe_read_kernel(void *dst, unsigned int size,
                                  const void *unsafe_ptr);
#else
#include <bpf/bpf_helpers.h>
#endif
```

`native-link` resolves these relocations against live kernel helper/kfunc
addresses. Unsupported helpers are hard failures for the native phase.

## Map Symbols

Map declarations should remain source-compatible with libbpf-style app code.
Native mode should preserve a symbol for each map object:

```c
struct {
    __uint(type, BPF_MAP_TYPE_HASH);
    __uint(max_entries, 1024);
    __type(key, struct key);
    __type(value, struct value);
} reals SEC(".maps");
```

References such as `&reals` must become relocations against the `reals` symbol.
The runtime native backend resolves those relocations using live map ids/fds
from the shim/daemon program snapshot, never from a companion `.bpf.o`.

The manifest records map name, symbol, type, key size, value size, and max
entries so runtime validation can detect mismatches before applying native code.

## Global Data and RoData

App BPF programs use `.rodata`, `.data`, and `.bss` maps for constants and
mutable globals. Native code must not blindly bake these values into the object
unless the upstream C compiler already treats them as true compile-time
constants.

Required behavior:

- Relocations against `.rodata`, `.data`, and `.bss` are preserved.
- `native-link` learns how to resolve section-symbol plus offset references to
  the corresponding live global-data map value pointer.
- The manifest maps each global section to the expected live map name.
- Runtime validation compares live map metadata before native apply.

This is required for libbpf skeleton apps and for Go apps that configure
globals before load.

## BTF, CO-RE, and Kernel Layout

Native objects are kernel-specific artifacts. They must be built for the same
kernel image/BTF used by the runtime benchmark image.

For BPF, CO-RE relocations are applied by libbpf before `BPF_PROG_LOAD`. Native
code does not get that libbpf relocation step. Compiling the same source against
the target kernel's `vmlinux.h` is not sufficient: app sources often contain
conditional CO-RE branches for multiple kernel layouts, and C type checking
still sees both branches. Some apps also use raw
`__builtin_preserve_access_index()` expressions, not just `BPF_CORE_READ`.

CO-RE must therefore be a separate build phase before native compilation:

1. Build the canonical upstream `.bpf.o` with `.BTF` and `.BTF.ext`.
2. Run a `core-lower` tool against that object and the target kernel BTF.
3. Resolve every CO-RE relocation kind used by the object:
   - field byte offset and byte size,
   - field existence,
   - type existence and type size,
   - enum value existence and enum value,
   - signedness and lshift/rshift data for bitfield reads.
4. Emit `core.resolved.json` with the raw relocation decisions.
5. Emit either `core_native.h` or a lowered C/LLVM IR input for native compile.
6. Fail the sidecar build if any preserve-access builtin, CO-RE builtin, or
   `.BTF.ext` relocation remains unresolved for native codegen.

The initial implementation should use libbpf's CO-RE resolver or the
`cilium/ebpf` resolver logic already vendored by Cilium/Tetragon, not a
hand-written BTF parser. The important property is that native lowering and
libbpf BPF loading consult the same target BTF and produce the same CO-RE
decisions.

The generated native path must preserve BPF helper semantics. For example,
`BPF_CORE_READ(task, pid)` should lower to a `bpf_probe_read_kernel` call from
`task + resolved_offset`, not to an unchecked native kernel dereference. Direct
native dereference would change fault behavior and can panic the kernel.

The lowering tool must handle these source patterns:

- `BPF_CORE_READ*`, `bpf_core_read*`, and `BPF_CORE_READ_BITFIELD*`.
- `bpf_core_field_exists`, `bpf_core_field_size`, `bpf_core_type_exists`,
  `bpf_core_type_size`, `bpf_core_enum_value_exists`, and enum value queries.
- `PT_REGS_*_CORE` helpers that depend on target register layout.
- Direct `__builtin_preserve_access_index()` use.
- `__attribute__((preserve_access_index))` local type declarations.

If a source-level macro shim cannot lower a pattern without C type-checking the
wrong kernel branch, the pipeline must switch to source rewrite or LLVM IR
lowering for that object. A native build that merely ignores the builtin or
uses host C struct offsets is invalid.

The manifest must include both the kernel image hash and target BTF hash.
Runtime native apply must hash the running `/sys/kernel/btf/vmlinux` and fail if
it does not match the manifest. If an app uses split/module BTF for attach
typing or CO-RE, the manifest needs the module BTF name and hash as well.

Program context ABI is related but separate from CO-RE. XDP, TC, cgroup skb,
tracepoint, raw tracepoint, kprobe, fentry/fexit, and LSM contexts each need a
native context-lowering rule that matches the kernel's BPF context access
semantics. CO-RE only resolves typed kernel data accesses; it does not by
itself define how `struct __sk_buff`, `struct xdp_md`, `struct pt_regs`, or
BTF-typed attach contexts are passed to native code.

## Program Matching at Runtime

Native apply runs against live programs discovered by the shim/daemon. It must
not assume that an artifact exists or that a static object name is unique.

Suggested matching order:

1. App namespace from the app runner/shim socket.
2. Program type and expected attach type.
3. BPF program name and section name from the manifest.
4. Live map names/types/sizes against manifest map metadata.
5. Helper call set against native relocation/helper set.
6. Optional exact live bytecode hash, if the build pipeline can produce one for
   that app and kernel.

If zero candidates match, return a per-program native error. If multiple
candidates match, return an ambiguity error. Do not choose heuristically.

The live program's map fds, link fds, perf event fds, XDP attach state, tail
call prog arrays, and program id remain owned by the shim/daemon snapshot. The
sidecar object only supplies native code and relocation intent.

## Runtime Flow

The eventual native backend should follow this shape:

1. App starts normally and loads BPF.
2. Shim/daemon discovers all live programs and records raw load metadata.
3. Runner requests a native phase through the existing socket boundary.
4. For every live program, daemon looks up the app `native-bpf` manifest.
5. Daemon matches the live program to exactly one sidecar program entry.
6. Daemon invokes `native-link` with:
   - native object path,
   - program symbol,
   - live map ids/fds,
   - helper/kfunc table,
   - global data map bindings,
   - lookup-site metadata when available.
7. Optional native-sim/proof step loads a proof object for the exact linked
   native blob.
8. Daemon applies native code to the live program through the native kernel
   mechanism.
9. Corpus measurement runs the normal app workload and records raw counters.

No app workload code should load the sidecar directly.

## App-Specific Build Strategy

### Katran

Katran is the first target.

Current build already emits:

```text
vendor/build/<arch>/katran/bpf/*.bpf.o
```

Add sibling native objects under:

```text
vendor/build/<arch>/katran/native-bpf/<kernel-id>/objects/<object>/native.o
```

Use the same source files, include directories, and defines as the existing
Katran BPF object build. This gives an early XDP-only pilot with clear map and
attach behavior.

### Tetragon

The Tetragon build already copies many BPF objects into:

```text
vendor/build/<arch>/tetragon/
```

The sidecar build should hook the same upstream BPF make invocation and emit
native objects for the same object set. Because the runtime app root is copied
as a whole, `native-bpf/` can live directly beside those BPF objects.

Tetragon will stress tracing program types, tail calls, ring/perf output, and
helper coverage.

### Tracee

Tracee should expose the generated BPF objects and the exact source/flags used
for its embedded assets during the existing Tracee build. The native sidecar
pipeline should consume those generated objects, not independently recreated
source guesses.

If the upstream build does not expose enough source/flag metadata, native
artifact build should fail for Tracee until the build hook is added.

### Cilium

Cilium BPF sources live under `vendor/repos/cilium/bpf` and are copied into
`/var/lib/cilium/bpf` in the runtime image. Native sidecars should be built
from the same source tree and the same benchmark profile config headers that
the corpus runner uses.

Cilium should come late because TC/XDP/cgroup programs, tail calls, pinned
maps, and generated config headers make exact identity more fragile.

### OTEL eBPF Profiler

The profiler embeds BPF assets through its Go build. The sidecar pipeline must
hook that asset generation path and copy out each generated BPF object plus the
matching native object.

This app is tail-call heavy. Native apply must preserve prog-array semantics,
and runtime interpretation should keep the existing rule that savings for
tail-called descendants are accounted at the attached caller.

### BCC libbpf-tools

BCC libbpf-tools already build a fixed APPS list. The sidecar pipeline should
extend the same make invocation and produce native objects for each selected
tool's generated BPF source/object.

Each child process still starts the real BCC tool binary. Sidecars are matched
only after the tool has loaded its own live programs.

### bpftrace

bpftrace is the hardest case because scripts are compiled at runtime. The
benchmark's scripts are fixed under `runner/assets/bpftrace_scripts`, but the
native sidecar still must come from the same bpftrace codegen path.

Required direction:

- Add or use an AOT/codegen mode that emits the exact BPF object for each
  benchmark script.
- Emit a native object from the same generated IR or generated C, not from a
  hand-written replacement.
- Record script path and script SHA in the manifest.

Until that exists, all-app native mode cannot honestly claim bpftrace support.

## Docker and Make Integration

Native app artifacts live under each app's repo-artifacts tree, but they should
be copied as a separate native-sidecar layer after the kernel manifest is known
and before runner/Rust/Python runtime layers. The reason is that native objects
are target-kernel-specific, while the regular app binaries and BPF objects are
mostly app-source-specific.

Expected Docker copy shape:

```text
COPY --link vendor/build/${VENDOR_BUILD_ARCH}/katran/native-bpf/ \
  /artifacts/user/repo-artifacts/${RUN_TARGET_ARCH}/katran/native-bpf/
```

Equivalent copies are needed for each app. Tracee/Tetragon may copy the whole
app artifact tree if `native-bpf/` is inside that tree.

Makefile targets should remain minimal and local. The natural ownership is
`vendor/Makefile`, because these are source-built app artifacts. A later
implementation can add app-specific native sidecar prerequisites to the
existing app artifact targets, rather than adding a new benchmark entrypoint.

The runtime image target should depend on the normal source app artifact target
plus the target kernel manifest once that target includes native sidecars.
Python/YAML changes must not trigger sidecar rebuilds.

## Validation Rules

Native sidecar build validation:

- Every app in `corpus/config/macro_apps.yaml` has a
  `native-bpf/<kernel-id>/manifest.v1.json`.
- Every manifest object has an existing `source.bpf.o` and `native.o`.
- Every manifest object has a `core.resolved.json` produced from the canonical
  `.BTF.ext` and target BTF, even if the object has zero CO-RE relocations.
- Every program entry has a symbol, section, program type, and object path.
- Every CO-RE relocation in `.BTF.ext` has an explicit resolved record or an
  explicit unsupported error.
- Native input contains no unlowered `__builtin_preserve_*` or `bpf_core_*`
  builtin use.
- Every relocation in `native.o` is either internal code, helper, map, global
  data, or an explicitly supported architecture relocation.
- Unsupported relocation kinds fail the build.

Runtime validation:

- Running kernel identity matches manifest kernel identity.
- Running `/sys/kernel/btf/vmlinux` hash matches manifest target BTF hash.
- Live program matches exactly one manifest entry.
- Live map metadata matches manifest map metadata.
- Helper and kfunc relocations resolve.
- Global data maps resolve with valid offsets.
- Native proof, if enabled, loads for the exact linked native blob.

Failure in any rule becomes a native phase error for the program/app. There is
no silent fallback to stock BPF inside the native phase.

## Initial Rollout

1. Implement the manifest and bundle format with Katran only.
2. Teach the native backend to resolve sidecars from
   `repo_artifact_root()/app/native-bpf/<kernel-id>`.
3. Apply live native code to Katran XDP programs using live map state, not a
   companion object.
4. Add Tetragon or BCC next to expand tracing helper coverage.
5. Add Tracee and OTEL once embedded BPF asset extraction is reliable.
6. Add Cilium after config-header identity and tail-call/prog-array handling are
   stable.
7. Add bpftrace after exact AOT/codegen native sidecar generation exists.

The all-app native target should not report partial support as success. Missing
or unsupported app sidecars are explicit errors until each app pipeline is real.
