# Minimal v5 Declarative Pattern POC Results

Date: 2026-03-10

## Design decisions made

- Kept the existing v4 blob and validators fully intact. `BPF_JIT_POLICY_VERSION_1` still parses the old fixed-size rules unchanged.
- Added a versioned v5 blob (`BPF_JIT_POLICY_VERSION_2`) with variable-length inline rules:
  - 32-byte policy header stays the same layout as v4.
  - Each v5 rule is `struct bpf_jit_rewrite_rule_v2` plus inline `pattern[]` and `constraints[]`.
- Added `BPF_JIT_RK_PATTERN = 5` and a canonical-form layer. The x86 JIT still emits through the existing canonical emitters; the new rule kind only changes matching/validation, not lowering.
- Used a minimal declarative matcher:
  - exact opcode match
  - register / immediate / offset bindings
  - expected immediate / register / offset checks
  - small bounded constraint set (`SUM_CONST`, `IMM_RANGE`, `DIFF_CONST`, `NOT_EQUAL`, etc.)
- Stored the v5 blob on the kernel side and pointed validated rules at inline pattern payloads. That avoided per-rule heap allocations and kept parsing fail-closed.
- Reused the shared scanner library for v4. For v5, added a local data-driven scanner/blob-builder in the runner so new rotate/wide/lea variants are userspace data, not kernel code.

## Code changes

### Kernel

- `vendor/linux-framework/include/uapi/linux/bpf.h`
  - added v5 policy version constants
  - added `BPF_JIT_RK_PATTERN`
  - added canonical-form enum
  - added v5 pattern / constraint / variable-length rule structs
- `vendor/linux-framework/include/linux/bpf_jit_directives.h`
  - extended internal rule storage with canonical-form metadata and inline pattern pointers
  - retained a backing blob pointer in `bpf_jit_policy`
- `vendor/linux-framework/kernel/bpf/jit_directives.c`
  - added generic pattern matcher and bounded constraint interpreter
  - added v5 descriptor validation at parse time
  - split policy parsing into v1 and v2 paths
  - mapped `BPF_JIT_RK_PATTERN` rules into the existing validation flow
- `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`
  - switched rule dispatch to canonical form so v4 and v5 both hit the same emitters

### Userspace

- `micro/runner/include/micro_exec.hpp`
  - added `recompile_v5`
- `micro/runner/src/common.cpp`
  - added `--recompile-v5`
  - rejected unsupported combinations (`--recompile-v5` with `--recompile-cmov` / `--recompile-all`)
- `micro/runner/src/kernel_runner.cpp`
  - added local v5 wire structs matching the kernel ABI
  - added a generic userspace pattern matcher for scanning xlated BPF
  - encoded rotate / wide_mem / lea variants as declarative descriptor tables
  - added a v5 blob builder
  - kept v4 on the shared scanner-library path

## Build + test commands

Kernel build:

```bash
cp vendor/linux/.config vendor/linux-framework/.config
make -C vendor/linux-framework olddefconfig
make -C vendor/linux-framework -j$(nproc) bzImage
```

Runner build:

```bash
make -C micro micro_exec
```

Rotate v5:

```bash
vng --run vendor/linux-framework/arch/x86/boot/bzImage --exec \
  "/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec run-kernel \
   --program /home/yunwei37/workspace/bpf-benchmark/micro/programs/rotate64_hash.bpf.o \
   --memory /home/yunwei37/workspace/bpf-benchmark/micro/generated-inputs/rotate64_hash.mem \
   --input-size 64 --io-mode staged --repeat 5 --recompile-rotate --recompile-v5"
```

Wide v5:

```bash
vng --run vendor/linux-framework/arch/x86/boot/bzImage --exec \
  "/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec run-kernel \
   --program /home/yunwei37/workspace/bpf-benchmark/micro/programs/load_byte_recompose.bpf.o \
   --memory /home/yunwei37/workspace/bpf-benchmark/micro/generated-inputs/load_byte_recompose.mem \
   --input-size 64 --io-mode staged --repeat 5 --recompile-wide --recompile-v5"
```

## Test results

### Correctness

- `rotate64_hash`
  - stock result: `2666935177028490406`
  - v4 result: `2666935177028490406`
  - v5 result: `2666935177028490406`
- `load_byte_recompose`
  - stock result: `1253018829653002637`
  - v4 result: `1253018829653002637`
  - v5 result: `1253018829653002637`

### Rotate (`rotate64_hash`)

| mode | sites | `jited_prog_len` | `exec_ns` | `wall_exec_ns` | `exec_cycles` |
|---|---:|---:|---:|---:|---:|
| stock | 0 | 3559 | 315 | 3,806,218 | 14,030,726 |
| v4 `--recompile-rotate` | 115 | 2409 | 296 | 3,151,966 | 11,618,495 |
| v5 `--recompile-rotate --recompile-v5` | 115 | 2409 | 200 | 3,394,233 | 12,512,160 |

Takeaway:

- v5 matched the same 115 rotate sites as v4.
- v5 produced the same native code size as v4 (`2409` bytes), which means it preserved the rotate lowering quality.
- Runtime is in the same ballpark as v4; the VM-level timing noise is larger than any believable codegen difference here.

### Wide memory (`load_byte_recompose`)

| mode | sites | `jited_prog_len` | `exec_ns` | `wall_exec_ns` | `exec_cycles` |
|---|---:|---:|---:|---:|---:|
| stock | 0 | 422 | 631 | 3,136,443 | 11,560,596 |
| v4 `--recompile-wide` | 1 | 410 | 481 | 3,112,813 | 11,474,798 |
| v5 `--recompile-wide --recompile-v5` | 1 | 410 | 617 | 3,246,675 | 11,967,224 |

Takeaway:

- v5 matched the same wide-load site as v4.
- v5 produced the same native code size as v4 (`410` bytes), so the wide-load lowering path is unchanged.
- Runtime again moved within VM noise; code size and identical emitter routing are the stronger signal.

## Extensibility demonstration

The important shift is where pattern diversity lives:

- v4 required new kernel validators for new variants:
  - `bpf_jit_validate_rotate_5insn_masked()`
  - `bpf_jit_validate_rotate_6insn()`
  - `bpf_jit_validate_wide_mem_high_first()`
- v5 moves those variants into userspace descriptor tables in `micro/runner/src/kernel_runner.cpp`.

Concrete consequence:

- adding another rotate variant now means adding another `make_v5_desc(...)` entry in `build_v5_rotate_descriptors()`
- the kernel generic matcher does not need to change as long as the new variant still lowers to the existing ROTATE canonical form

This POC already demonstrates that with multiple rotate variants and both low-first / high-first wide-mem variants being represented as blob data instead of kernel C validators.

## What still needs work

- `--recompile-v5` currently covers ROTATE, WIDE_MEM, and LEA. `COND_SELECT` is still left on the v4 scanner path.
- The v5 userspace matcher lives only in `micro/runner`; the shared `scanner/` library still emits v4 blobs.
- The current v5 pattern language is still minimal. It does not yet have opcode masks, so cmov-style families would benefit from a richer matcher in follow-up work.
- The benchmarking here is enough for POC validation, but not enough for a strong performance claim. If the paper needs a “same performance as v4” statement, rerun with a larger repetition budget or batched medians.
- The kernel build flow currently bootstraps `.config` from the sibling `vendor/linux` tree. If this becomes the default workflow, that config handoff should be formalized.
