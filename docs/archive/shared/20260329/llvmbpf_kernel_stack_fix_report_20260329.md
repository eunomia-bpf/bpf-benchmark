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

For programs without pseudo-calls, this removes the old synthetic llvmbpf
userspace call-stack model entirely. Pseudo-call handling is covered below by
preserving kernel call relocations plus the original subprogram region.

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

### 8. Fixed kernel tail-call helper semantics

In kernel-compatible mode, helper `bpf_tail_call#12` no longer:

- writes a synthetic userspace-style return value into `r0`
- forces the lifted function to exit immediately after the helper

This removed the earlier Tracee-wide `R0 !read_ok` verifier failures.

### 9. Added kernel-mode pseudo-call preservation for BPF-to-BPF programs

Kernel-compatible lift no longer hard-fails on pseudo-calls.

Current implementation:

- kernel-mode pseudo-calls are emitted as external symbols like
  `__llvmbpf_pseudo_call_pc_<pc>`
- llvmbpf only codegens the main entry subprogram in kernel mode
- postprocess rewrites those pseudo-call relocations back into
  `BPF_PSEUDO_CALL` immediates
- postprocess appends the original subprogram bytecode region unchanged

This is a hybrid approach:

- the main program is still lifted/optimized
- subprogram bodies are preserved from the original kernel bytecode

This was enough to move `sys_dup_exit_tail` from host-lift failure into real
kernel `REJIT` validation.

### 10. Added a verifier-bounds peephole for widened 16-bit compares

Postprocess now rewrites a common LLVM shape:

- `wtmp = widx`
- `wtmp &= 0xffff`
- compare on `wtmp`
- later `ridx &= 0xffff`

back into a compare on the original index register when it is safe to do so.

The matcher was widened to tolerate a small number of non-clobbering
instructions between the `AND32` and the compare. This removed the remaining
`invalid access to map value` failure on
`tracepoint__sched__sched_process_fork`.

### 11. Relaxed REJIT tail-call poke matching for moved helper sites

In `vendor/linux-framework/kernel/bpf/syscall.c`,
`bpf_prog_rejit_update_poke_tab()` no longer requires the new lifted program to
keep the exact original eBPF `insn_idx` for direct-tail-call poke entries.

The updated check still requires:

- same poke count
- same poke reason ordering
- same `(map, key)` ordering

This is sufficient for the runtime update path, which only consumes the
refreshed JIT addresses plus `(map, key)` metadata.

This fixed the earlier `EINVAL` REJIT failures on:

- `lkm_seeker_mod_tree_tail`
- `send_bin`
- `send_bin_tp`

## Explicit Remaining Limitations

Kernel-compatible mode still rejects:

- `var_addr` LDDW pseudos
- `code_addr` LDDW pseudos
- `map_by_idx` and `map_by_idx + map_val` LDDW pseudos

These fail loudly by design.

Additional current limitation:

- kernel-mode pseudo-calls are preserved by appending the original subprogram
  region; subprogram bodies are not yet re-lifted or re-optimized

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

#### Iteration 1: tail-call + pseudo-call + map-bounds fixes

Session:

- `docs/tmp/20260329/llvmbpf_rejit_roundtrip_poc/sessions/tracee_live_iter3_20260329_201120`

Tracee attached 29 programs in this session.

Host-side prepare:

- `29 / 29` programs lifted and lowered successfully

End-to-end `REJIT` results:

- `5 / 29` fully passed
- `24 / 29` failed

Programs that fully passed:

- `tracepoint__raw_syscalls__sys_enter`
- `sys_enter_init`
- `tracepoint__raw_syscalls__sys_exit`
- `lkm_seeker_new_mod_only_tail`
- `tracepoint__sched__sched_process_free`

Important deltas vs. the earlier `3 / 37` Tracee baseline:

- verifier `R0 !read_ok` failures dropped to `0`
- verifier `invalid access to map value` failures dropped to `0`
- pseudo-call programs no longer failed host lift

Failure breakdown:

- `14` hit `BPF_PROG_REJIT: E2BIG`
- `7` hit `BPF_PROG_REJIT: ENOSPC`
- `3` hit `BPF_PROG_REJIT: EINVAL`

Representative examples:

- `sys_dup_exit_tail`: host lift now succeeds, but `2342 -> 2735` insns still
  fail `E2BIG`
- `tracepoint__sched__sched_process_fork`: `4042 -> 4911` insns, now `E2BIG`
  instead of `invalid access to map value`

#### Iteration 2: kernel REJIT poke-tab relaxation

Session:

- `docs/tmp/20260329/llvmbpf_rejit_roundtrip_poc/sessions/tracee_live_iter4_20260329_201647`

Tracee attached 33 programs in this session.

Host-side prepare:

- `33 / 33` programs lifted and lowered successfully

End-to-end `REJIT` results:

- `9 / 33` fully passed
- `24 / 33` failed

Programs that fully passed:

- `tracepoint__raw_syscalls__sys_enter`
- `sys_enter_init`
- `tracepoint__raw_syscalls__sys_exit`
- `lkm_seeker_mod_tree_tail`
- `lkm_seeker_new_mod_only_tail`
- `tracepoint__sched__sched_process_free`
- `send_bin`
- `send_bin_tp`
- `syscall__init_module`

Compared with Iteration 1:

- `EINVAL` failures dropped from `3` to `0`
- success count increased from `5` to `9`

Failure breakdown:

- `15` hit `BPF_PROG_REJIT: E2BIG`
- `8` hit `BPF_PROG_REJIT: ENOSPC`
- `1` hit verifier rejection surfaced as `BPF_PROG_REJIT: EPERM`

The remaining verifier failure is:

- `trace_ret_vfs_read_tail`
  - syscall error: `Permission denied (os error 13)`
  - verifier root cause: `R1 invalid mem access 'scalar'` at insn `4117`

Notes:

- the aggregate `results.json` in this session contains a broken giant JSON
  string in one verifier-log payload, so the final counts above were computed
  from per-program `programs/*/rejit.json`
- a targeted `O1` follow-up session for `trace_ret_vfs_read_tail`
  (`tracee_single_readtail_o1_20260329_202059`) was inconclusive because that
  specific program did not attach in the narrower run

#### Program-size findings

`E2BIG` is now clearly a kernel page-budget failure, not a verifier failure.

In `vendor/linux-framework/kernel/bpf/syscall.c`, REJIT rejects when:

- `bpf_prog_size(tmp->len) > prog->pages * PAGE_SIZE`

This explains why some relatively small deltas still fail, for example:

- `sys_exit_init`: `482 -> 521` insns
- `sys_dup_exit_tail`: `2342 -> 2735` insns

Quick host-side opt-level experiments on representative `E2BIG` programs
showed little leverage from changing `opt` level:

- `sys_exit_init`: `521` insns at `O2/O3/Os/Oz`, `522` at `O1`
- `sys_dup_exit_tail`: `2735` insns at `O2/O3/Os/Oz`, `2719` at `O1`
- `tracepoint__sched__sched_process_fork`: `4911` insns at `O2/O3/Os/Oz`,
  `4873` at `O1`
- `sys_enter_submit`: `4609` insns at `O2/O3/Os/Oz`, `4640` at `O1`

So simple `opt`-level retuning is not a promising path for the remaining
size-limited failures.

## Current Status

What is fixed:

- the kernel-stack incompatibility on the llvmbpf lift path
- the `opensnoop` exit tracepoint host-lift failure
- the 32-bit pointer-spill regression that still broke `REJIT` after lift
- kernel tail-call helper semantics (`R0 !read_ok` is gone)
- kernel pseudo-call handling for BPF-to-BPF callers in hybrid form
- widened compare repair for bounded 16-bit map-value indexing
- REJIT tail-call poke matching for moved helper sites
- the tested BCC tool set now passes end-to-end: `17 / 17`
- Tracee improved from `3 / 37` to `9 / 33` fully passing in current VM runs

What remains for broader Tracee coverage:

- reducing llvmbpf code-size growth enough to fit the kernel REJIT page budget
- understanding the remaining `ENOSPC` resource limit on large programs
- fixing the remaining verifier failure in `trace_ret_vfs_read_tail`
- replacing the hybrid pseudo-call preservation path with real lifted
  subprogram support if full optimization coverage is required

## Takeaway

The original llvmbpf kernel-stack problem is fixed for the tested round-trip
path.

The work is now past the original stack blocker and the early verifier
semantic blockers. The remaining Tracee failures are dominated by:

- REJIT page-budget `E2BIG`
- a still-unexplained large-program `ENOSPC`
- one residual verifier scalar/stack-type bug
