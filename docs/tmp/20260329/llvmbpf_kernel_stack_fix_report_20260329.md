# llvmbpf Kernel Stack Fix Report

Date: 2026-03-29

## Goal

Make the llvmbpf lift path kernel-compatible for:

- `GET_ORIGINAL -> llvmbpf lift -> opt -O2 -> llc -march=bpf -> REJIT`

Required properties:

- kernel-style entry ABI: `r1 = ctx`, no synthetic userspace `r2 = len`
- kernel-size stack only, not the old multi-page synthetic llvmbpf stack
- no synthetic call stack when the source program has no BPF-to-BPF calls
- no silent fallback on helper or map relocation failures

## Checked llvmbpf Diff

`git diff` under `vendor/llvmbpf` shows the kernel-compatible work is now
concentrated in these task-relevant files:

- `include/llvmbpf.hpp`
- `src/vm.cpp`
- `src/compiler.cpp`
- `src/compiler_utils.hpp`
- `src/compiler_utils.cpp`
- `src/llvm_jit_context.cpp`

There is also a dirty `cli/main.cpp`, but it is unrelated to this kernel lift
fix.

## Implemented Changes

### 1. Added explicit kernel-compatible mode

New VM flag:

- `set_kernel_compatible_mode(true)`

This is enabled by the round-trip raw lifter before AOT emit.

### 2. Replaced the userspace entry ABI

Old shape:

- `define i64 @bpf_main(ptr %ctx, i64 %len)`
- llvmbpf wrote `r1 = ctx`, `r2 = len`

Kernel-compatible shape:

- `define i64 @bpf_main(ptr %ctx)`
- only `r1 = ctx`

This removes the old host-side ABI patching workaround.

### 3. Replaced the synthetic stack with exact kernel stack sizing

Kernel-compatible mode now scans the original eBPF bytecode and computes the
maximum negative `r10` access used by the real program. It allocates only that
many bytes, rounded up to 8 bytes, and sets `r10` to the end of that buffer.

Important detail:

- the stack alloca is now explicitly `align 8`

That alignment change was necessary because LLVM otherwise lowered some pointer
spills into two 32-bit stores, which the kernel verifier rejects. This was the
remaining blocker for the `opensnoop` and `filelife` exit programs.

### 4. Removed synthetic call-stack lowering in kernel mode

Kernel-compatible mode now:

- does not create `callStack`
- does not create `callItemCnt`
- lowers `EXIT` directly to function return

Current explicit limitation:

- BPF-to-BPF calls are still rejected with a hard error in kernel-compatible
  mode

### 5. Preserved kernel pseudo map references as external symbols

For kernel-compatible lift:

- pseudo map fd loads become external symbols like
  `__llvmbpf_pseudo_map_fd_<fd>`
- pseudo map value loads become external symbols like
  `__llvmbpf_pseudo_map_value_fd_<fd>_off_<off>`

This keeps the kernel relocation semantics visible to postprocess/repair
instead of collapsing them into userspace helper calls.

### 6. Allowed unknown helpers to survive lift as externals

`emitExtFuncCall()` now supports implicit external helper declarations in
kernel-compatible mode.

This fixed the earlier host-lift failures on programs that call helpers not
already predeclared by llvmbpf, including the `opensnoop` and `filelife` exit
tracepoints.

### 7. Disabled runtime `map_val` helper definition in kernel mode

In `src/llvm_jit_context.cpp`, the runtime `map_val` LDDW helper is not defined
for kernel-compatible AOT output.

That avoids reintroducing userspace-style LDDW helper assumptions on the
kernel round-trip path.

## Explicit Remaining Limitations

Kernel-compatible mode still rejects:

- BPF-to-BPF calls
- `var_addr` LDDW pseudos
- `code_addr` LDDW pseudos
- `map_by_idx` and `map_by_idx + map_val` LDDW pseudos

These fail loudly by design.

## Validation

### BCC round-trip results

Validated in VM with the POC flow:

- load live program
- `BPF_PROG_GET_ORIGINAL`
- host lift in kernel-compatible mode
- `opt -O2`
- `llc -march=bpf`
- postprocess
- `BPF_PROG_REJIT`

Results:

| Tool | Programs | Fully OK |
| --- | ---: | ---: |
| `execsnoop` | 2 | 2 |
| `opensnoop` | 6 | 6 |
| `filelife` | 5 | 5 |
| `capable` | 2 | 2 |
| `syscount` | 2 | 2 |
| Total | 17 | 17 |

Notes:

- `opensnoop` exit tracepoints no longer fail during host lift
- `filelife` and `opensnoop` exit programs no longer fail on invalid pointer
  spills after the `align 8` stack fix

### Tracee round-trip results

Tracee attached 37 programs in this session.

Host-side prepare:

- 35 / 37 programs lifted and lowered successfully
- 2 / 37 failed during lift

Lift failures:

- `sys_dup_exit_tail`: `Kernel-compatible lift does not support BPF-to-BPF calls yet at pc 1127`
- `syscall__accept4`: `Kernel-compatible lift does not support BPF-to-BPF calls yet at pc 804`

End-to-end `REJIT` results:

- 3 / 37 programs fully passed
- 34 / 37 were not fully successful

Programs that fully passed:

- `lkm_seeker_new_mod_only_tail`
- `tracepoint__sched__sched_process_free`
- `syscall_checker`

Failure breakdown for the remaining 34 programs:

- 15 hit verifier `R0 !read_ok` after tail-call-style paths
- 9 hit verifier `invalid access to map value`
- 5 failed `BPF_PROG_REJIT` with `E2BIG` (`Argument list too long`) on large
  programs
- 3 failed `BPF_PROG_REJIT` with `ENOSPC` (`No space left on device`) on very
  large programs
- 2 failed lift because kernel-compatible mode still rejects BPF-to-BPF calls

Large-program examples:

- `syscall__execve_enter`: `3956 -> 4780` insns, `E2BIG`
- `syscall__execve_exit`: `3958 -> 4788` insns, `E2BIG`
- `syscall__execveat_enter`: `4011 -> 4822` insns, `E2BIG`
- `lkm_seeker_modtree_loop`: `14236 -> 14421` insns, `ENOSPC`
- `lkm_seeker_kset_tail`: `14857 -> 14804` insns, `ENOSPC`

## Current Status

What is fixed:

- the kernel-stack incompatibility on the llvmbpf lift path
- the `opensnoop` exit tracepoint host-lift failure
- the 32-bit pointer-spill regression that still broke `REJIT` after lift
- the tested BCC tool set now passes end-to-end: `17 / 17`

What remains for broader Tracee coverage:

- real kernel-mode support for BPF-to-BPF calls
- better preservation of tail-call semantics so transformed programs do not
  read `R0` in verifier-invalid ways
- better preservation of bounded map-value pointer arithmetic on large Tracee
  programs
- understanding whether the `E2BIG` / `ENOSPC` failures are pure syscall/log
  size limits, program-size limits, or a byproduct of the transformed output

## Takeaway

The original llvmbpf kernel-stack problem is fixed for the tested round-trip
path.

The work is now past the original stack blocker and into second-order issues:

- kernel-mode BPF-to-BPF support
- tail-call-sensitive verifier behavior
- map-value bounds on large transformed Tracee programs
- large-program `REJIT` limits
