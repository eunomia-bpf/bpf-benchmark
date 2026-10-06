# llvmbpf GET_ORIGINAL + REJIT Round-Trip POC

Date: 2026-03-29

## Goal

Redo the llvmbpf round-trip POC on the daemon-equivalent live-program path:

1. app loads BPF normally
2. VM side uses `BPF_PROG_GET_ORIGINAL`
3. host side runs `llvmbpf lift -> opt -O2 -> llc -march=bpf`
4. VM side uses `BPF_PROG_REJIT`

This deliberately avoids `.bpf.o` round-trip, `bpftool loadall`, and ELF metadata repair.

## What I built

New POC workspace:

- `docs/tmp/20260329/llvmbpf_rejit_roundtrip_poc/Makefile`
- `docs/tmp/20260329/llvmbpf_rejit_roundtrip_poc/CMakeLists.txt`
- `docs/tmp/20260329/llvmbpf_rejit_roundtrip_poc/raw_lifter.cpp`
- `docs/tmp/20260329/llvmbpf_rejit_roundtrip_poc/llvmbpf_rejit_host.py`
- `docs/tmp/20260329/llvmbpf_rejit_roundtrip_poc/llvmbpf_rejit_guest.py`
- `docs/tmp/20260329/llvmbpf_rejit_roundtrip_poc/guest_helper/src/main.rs`

Supporting session artifacts:

- `docs/tmp/20260329/llvmbpf_rejit_roundtrip_poc/sessions/execsnoop_live/`
- `docs/tmp/20260329/llvmbpf_rejit_roundtrip_poc/sessions/execsnoop_live2/`
- `docs/tmp/20260329/llvmbpf_rejit_roundtrip_poc/sessions/execsnoop_live3/`

## Host/VM split

- VM side:
  - enumerate live programs from the app runner
  - call `GET_ORIGINAL`
  - capture original bytecode and live `map_ids`
  - call `REJIT`
- host side:
  - raw-bytecode lift with a standalone llvmbpf wrapper
  - `opt -O2`
  - `llc -march=bpf`
  - helper-call postprocess

The repo root is shared into the VM, so host and VM exchange artifacts directly through the shared filesystem.

## Execsnoop run

Target app: BCC `execsnoop`

Live programs found:

- prog id `7`: `tracepoint__syscalls__sys_enter_execve`
- prog id `9`: `tracepoint__syscalls__sys_exit_execve`

### Stage results

For both live programs:

- `GET_ORIGINAL`: `2/2`
- llvmbpf lift: `2/2`
- `opt -O2`: `2/2`
- `llc -march=bpf`: `2/2`
- helper-call postprocess: `2/2`
- `REJIT`: `0/2`

So the live path removed the old object/ELF loading failures completely, but final kernel re-verification still failed.

## Issues found and fixes made

### 1. llc stack-limit failure on the host

Initial lowering failed before REJIT with:

- `Looks like the BPF stack limit is exceeded`

Fix:

- use `llc --bpf-stack-size=32768`

This was only a host-side codegen limit override. It did not make the emitted program verifier-safe by itself.

### 2. unresolved `__lddw_helper_map_val` pseudo-calls

The raw lowered object still contained unresolved `R_BPF_64_32` relocations for `__lddw_helper_map_val`.
After dumping `.text` to raw bytecode, these became bogus `call src_reg=1 imm=-1` instructions.

Observed on `execsnoop`:

- `sys_enter_execve`: `62` such call sites
- `sys_exit_execve`: `3` such call sites

Fix:

- guest helper now rewrites these runtime map-value pseudo-calls back to raw `LDDW src=2` pairs in-place before REJIT

Effect:

- the earlier verifier failure
  - `last insn is not an exit or jmp`
- disappeared

### 3. synthetic userspace entry ABI (`r2`/mem_len)

Raw llvmbpf lift emitted:

```llvm
define i64 @bpf_main(ptr %0, i64 %1)
...
store ptr %0, ptr %r1
store i64 %1, ptr %r2
```

This is userspace-vm ABI, not kernel BPF entry ABI. On the first live REJIT attempt this showed up as:

- verifier failure at instruction `0`
- `R2 !read_ok`

Fix:

- host prepare rewrites the lifted IR initialization from
  - `store i64 %1, ptr %r2`
  to
  - `store i64 0, ptr %r2`

Effect:

- the `R2 !read_ok` failure disappeared
- verifier progressed much deeper into both programs

## Remaining blocker

After the two fixes above, both `execsnoop` programs still failed REJIT in the kernel verifier.

The remaining failure is not about `.bpf.o`, ELF metadata, or map FD recovery.
It is about llvmbpf's execution model.

### `sys_enter_execve`

Current failure:

- `invalid write to stack R10 off=-16472 size=8`

### `sys_exit_execve`

Current failure:

- `invalid write to stack R10 off=-16472 size=8`

or the same class of verifier rejection after more instructions are processed.

### Root cause

llvmbpf lifts into a userspace-oriented VM model with a large synthetic stack and call stack:

- `stackBegin = alloca i64, i32 2058`
- `callStack = alloca ptr, i32 320`

That model is acceptable for native/userspace execution, but when lowered back to kernel eBPF it generates stack references far beyond the kernel verifier's stack bound.

This is the real blocker now.

## Comparison with the old `.bpf.o` POC

Previous `.bpf.o` path:

- `157/413` verifier pass (`38%`)
- major noise sources:
  - original object could not even be loaded by `bpftool loadall`
  - missing ELF metadata (`license`, BTF, etc.)
  - map relocation repair around reloaded objects

New live `GET_ORIGINAL + REJIT` path:

- no `bpftool loadall`
- no ELF metadata dependency
- no object re-load dependency
- map IDs come directly from the live program
- infrastructure path is correct and daemon-aligned

But current measured `execsnoop` result is:

- `0/2` REJIT pass

Interpretation:

- the new path successfully removes the old infrastructure failures
- the remaining failure is now the true llvmbpf kernel-compatibility problem
- so the old `38%` number is no longer the relevant bottleneck on this path
- however, I cannot honestly claim a higher final pass rate yet, because `execsnoop` still fails on the verifier after the path is corrected

## Why I did not expand to Tracee / more BCC tools

The requested first gate was:

- validate REJIT success on BCC `execsnoop`

That gate is still failing after fixing:

- host `llc` stack-limit issue
- runtime map-value pseudo-call reconstruction
- synthetic `r2` entry-ABI issue

At this point, expanding to Tracee or more BCC tools would mostly re-measure the same verifier blocker:

- llvmbpf's large synthetic stack / call-stack model

So I stopped after isolating the first real kernel-side blocker on the correct syscall path.

## Takeaway

The correct live path is now implemented and exercised:

- `GET_ORIGINAL` works
- host raw-bytecode lift/lower works
- `REJIT` is reached on live programs

But `execsnoop` shows that llvmbpf still needs kernel-oriented lowering fixes before this path can produce successful live-program REJITs:

1. kernel entry ABI, not userspace `(ctx, len)`
2. no synthetic verifier-incompatible stack expansion
3. no unresolved runtime map-value helper calls in the final raw BPF

Without fixing item `2`, the corrected live path still does not pass `execsnoop`.
