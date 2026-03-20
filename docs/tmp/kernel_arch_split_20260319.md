# Kernel Arch Split Report

Date: 2026-03-19

## Scope

Pure refactor of the kernel JIT recompile architecture:

- split `vendor/linux-framework/kernel/bpf/jit_directives.c` into:
  - `vendor/linux-framework/kernel/bpf/jit_validators.c`
  - `vendor/linux-framework/kernel/bpf/jit_policy.c`
  - reduced `vendor/linux-framework/kernel/bpf/jit_directives.c`
- added an arch callback for native-choice / CPU-feature support:
  - generic declaration in `include/linux/bpf_jit_directives.h`
  - weak default implementation in `kernel/bpf/jit_validators.c`
  - x86 override in `arch/x86/net/bpf_jit_comp.c`
- updated `kernel/bpf/Makefile` to build the new objects

No intended behavior change.

## File Size Before / After

Before:

- `vendor/linux-framework/kernel/bpf/jit_directives.c`: 2797 lines

After:

- `vendor/linux-framework/kernel/bpf/jit_directives.c`: 727 lines
- `vendor/linux-framework/kernel/bpf/jit_validators.c`: 1599 lines
- `vendor/linux-framework/kernel/bpf/jit_policy.c`: 432 lines

Net:

- old single file total: 2797 lines
- new split total: 2758 lines
- delta: -39 lines

## Functional Split

`jit_validators.c` now owns:

- all canonical-form validators and shape parsers
- generic site validation helpers
- canonical param setters
- form metadata and generic rule validation
- weak default `bpf_jit_arch_form_supported()`

`jit_policy.c` now owns:

- sealed memfd validation
- policy allocation / free
- v2 policy blob parsing
- rule sorting and overlap validation
- active-rule lookup

`jit_directives.c` now owns:

- syscall entry
- rollback / snapshot logic
- staged-image recompile orchestration
- recompile logging
- shadow ksym management
- rule release

## Arch Callback

Added:

```c
bool bpf_jit_arch_form_supported(u16 canonical_form, u16 native_choice);
```

Behavior:

- generic weak default returns `false`
- x86 provides the strong implementation
- validator-side native-choice gating now calls this hook instead of using x86-specific `boot_cpu_has()` logic inside the generic metadata path

Current x86 checks preserved:

- `COND_SELECT` / `CMOVCC` requires `X86_FEATURE_CMOV`
- `ROTATE` / `RORX` requires `X86_FEATURE_BMI2`
- `ENDIAN_FUSION` / `MOVBE` requires `X86_FEATURE_MOVBE`

## Verification

Executed:

1. `cd vendor/linux-framework && make -j$(nproc) bzImage`
2. `cd /home/yunwei37/workspace/bpf-benchmark && make vm-selftest`
3. `cd /home/yunwei37/workspace/bpf-benchmark && make vm-micro-smoke`
4. `cd /home/yunwei37/workspace/bpf-benchmark && cmake --build scanner/build --target test_scanner && ./scanner/build/test_scanner`

Results:

- `bzImage`: success
- `vm-selftest`: PASS 19/19
- `vm-micro-smoke`: `simple` pass, `cmov_dense` pass
- scanner tests: `PASS 180`
