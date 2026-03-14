# Linux x86 BPF JIT Analysis for Userspace-Guided Backend Directives

This document analyzes the local kernel source tree in `vendor/linux/` with emphasis on the x86 JIT backend and the verifier/runtime machinery that feeds it.

Primary files analyzed:

- `vendor/linux/arch/x86/net/bpf_jit_comp.c`
- `vendor/linux/include/linux/bpf.h`
- `vendor/linux/include/linux/bpf_verifier.h`
- `vendor/linux/kernel/bpf/verifier.c`
- `vendor/linux/kernel/bpf/core.c`

For the exact `BPF_PROG_LOAD` syscall entrypoint, I also looked at `vendor/linux/kernel/bpf/syscall.c`, because the requested end-to-end pipeline starts there.

## 1. JIT Compilation Pipeline

### 1.1 Exact flow from `BPF_PROG_LOAD` to native code

The concrete path in this tree is:

1. `sys_bpf()` dispatches `BPF_PROG_LOAD` to `bpf_prog_load()` in `kernel/bpf/syscall.c`.
2. `bpf_prog_load()` allocates `struct bpf_prog`, copies user instructions, sets metadata, and runs the verifier:
   - `bpf_prog_alloc()` / `bpf_prog_alloc_no_stats()` allocate the program and aux state.
   - `bpf_prog_alloc_no_stats()` already decides JIT policy defaults:
     - `prog->jit_requested = ebpf_jit_enabled()`
     - `prog->blinding_requested = bpf_jit_blinding_enabled(prog)`
     - See `kernel/bpf/core.c:128-129`.
3. `bpf_prog_load()` calls `bpf_check(&prog, attr, uattr, uattr_size)` (`kernel/bpf/syscall.c:3089`).
4. `bpf_check()` allocates `struct bpf_verifier_env`, allocates `env->insn_aux_data`, and initializes `env->insn_aux_data[i].orig_idx = i` (`kernel/bpf/verifier.c:25933-25940`).
5. The verifier runs its normal analysis and late lowering passes. The relevant late pipeline near the end of `bpf_check()` is:
   - `convert_ctx_accesses(env)`
   - `do_misc_fixups(env)`
   - `opt_subreg_zext_lo32_rnd_hi32(env, attr)`
   - `fixup_call_args(env)`
   - if maps/BTF pseudo-`ldimm64` cleanup is needed, `convert_pseudo_ld_imm64(env)`
   - See `kernel/bpf/verifier.c:26090-26161`.
6. `fixup_call_args()` is where JIT interaction becomes important:
   - If `prog->jit_requested` and the program is not offloaded, it calls `jit_subprogs(env)` first (`kernel/bpf/verifier.c:23064-23076`).
   - `jit_subprogs()` does all subprogram splitting and the two-stage bpf2bpf JIT process if the program has multiple subprograms.
7. Control returns to `bpf_prog_load()`, which then calls `bpf_prog_select_runtime(prog, &err)` (`kernel/bpf/syscall.c:3093`).
8. `bpf_prog_select_runtime()` either:
   - skips directly to finalization if `prog->bpf_func` is already set, which is what happens for successfully JITed multi-subprog programs after `jit_subprogs()`, or
   - allocates JIT line-info storage and calls `bpf_int_jit_compile(prog)` for the architecture backend (`kernel/bpf/core.c:2519-2573`).
9. On x86, `bpf_int_jit_compile()` is the real backend implementation in `arch/x86/net/bpf_jit_comp.c:3716`.
10. Once JIT succeeds:
    - `prog->bpf_func` is set to the final native entry address.
    - `prog->jited = 1`
    - `prog->jited_len` is set.
    - `bpf_prog_update_insn_ptrs()` and `bpf_prog_fill_jited_linfo()` consume the `addrs[]` mapping.
11. Back in `bpf_prog_load()`, the program gets an ID, kallsyms entry, and an fd returned to userspace.

### 1.2 Where constant blinding happens

Constant blinding is not a verifier pass. It happens inside the arch JIT path:

- `bpf_prog_select_runtime()` calls `bpf_int_jit_compile()`.
- x86 `bpf_int_jit_compile()` immediately calls `bpf_jit_blind_constants(prog)` before any x86 address-pass work (`arch/x86/net/bpf_jit_comp.c:3733`).
- `bpf_jit_blind_constants()` lives in `kernel/bpf/core.c:1489`.

So the actual ordering is:

1. verifier finishes
2. verifier rewrites are done
3. runtime selection chooses JIT
4. constant blinding may clone and rewrite the program
5. x86 JIT pass loop runs on the possibly blinded clone

This is a major constraint for any directive scheme that wants to survive from verifier-visible instruction indices to final native emission.

### 1.3 What `do_jit()` actually is

`do_jit()` in `arch/x86/net/bpf_jit_comp.c:1652` is one backend emission pass, not the whole compiler.

It takes:

- `struct bpf_prog *bpf_prog`
- `int *addrs`
- `u8 *image`
- `u8 *rw_image`
- `int oldproglen`
- `struct jit_context *ctx`
- `bool jmp_padding`

Its responsibilities are:

- emit the prologue
- emit each BPF instruction into a temporary buffer `temp`
- maintain per-BPF-insn x86 offsets in `addrs[]`
- emit or size-estimate exception table entries for `PROBE_MEM*` and arena accesses
- resolve branches using `addrs[]` from the previous pass
- emit the shared exit epilogue
- return the pass's total native code size in bytes

It does not:

- allocate executable memory
- loop until convergence
- finalize JIT memory protections
- split subprograms
- perform constant blinding

Those are handled by its caller, `bpf_int_jit_compile()`.

### 1.4 Pass structure in `bpf_int_jit_compile()`

The x86 pass loop is in `arch/x86/net/bpf_jit_comp.c:3777-3851`.

Important constants:

- `MAX_PASSES = 20`
- `PADDING_PASSES = MAX_PASSES - 5`

First-time compilation does this:

1. If blinding is enabled, possibly replace `prog` with a blinded clone.
2. Allocate or reuse `jit_data`.
3. Allocate `addrs[prog->len + 1]`.
4. Seed `addrs[]` with rough 64-byte-per-insn estimates:
   - `for (i = 0; i <= prog->len; i++) addrs[i] = proglen += 64;`
   - `ctx.cleanup_addr` is initialized to that same rough end estimate.
5. Repeatedly call `do_jit(..., image = NULL, rw_image = NULL, ...)`.
6. Once `proglen == oldproglen`, allocate final executable memory plus extable:
   - `bpf_jit_binary_pack_alloc(roundup(proglen, align) + extable_size, ...)`
   - set `prog->aux->extable`
7. Run one final pass with `image != NULL` and `rw_image != NULL` to emit actual bytes.
8. Finalize the text pack and patch direct tail calls.

Subprogram recompilation does a related but slightly different flow:

1. First JIT pass for each subprog allocates image memory but does not finalize it if `prog->is_func && !extra_pass`.
2. The backend stores `addrs`, `ctx`, `proglen`, `image`, `header`, `rw_header` in `prog->aux->jit_data`.
3. After verifier-side relocation of bpf2bpf call targets, `jit_subprogs()` calls `bpf_int_jit_compile(func[i])` again.
4. That second call sees cached `jit_data`, sets `extra_pass = true`, `padding = true`, and reruns `do_jit()` directly against the existing image.
5. Only in this second subprog call does x86 finalize the binary pack.

That cached-extra-pass behavior is the reason bpf2bpf directives cannot treat `bpf_int_jit_compile()` as a single-shot pipeline.

### 1.5 What `addrs[]` means

`addrs[]` is not "address of BPF instruction i". It is a boundary table.

For a program with `len` BPF instructions:

- `addrs` has length `len + 1`
- `addrs[0]` is the native offset immediately after the prologue, which is also the native start of BPF instruction 0
- `addrs[i]` for `i > 0` is the native offset immediately after BPF instruction `i - 1`, which is also the native start of BPF instruction `i`

This dual interpretation is why x86 uses the same array for two different consumers:

- `bpf_prog_update_insn_ptrs(prog, addrs, image)` expects start-of-instruction offsets
- `bpf_prog_fill_jited_linfo(prog, addrs + 1)` expects end-of-instruction offsets

See:

- x86 comment near `bpf_prog_update_insn_ptrs()` call: `arch/x86/net/bpf_jit_comp.c:3894-3917`
- `bpf_prog_fill_jited_linfo()` in `kernel/bpf/core.c:228-254`
- `bpf_prog_update_insn_ptrs()` in `kernel/bpf/bpf_insn_array.c:274-300`

For ordinary instructions, that model is clean.

For `BPF_LD | BPF_IMM | BPF_DW`, the BPF encoding consumes two instruction slots. x86 emits one native sequence, increments `insn++` and `i++` inside the case, and ultimately updates the boundary corresponding to the second slot. That is acceptable because control flow cannot target the second half of an `ldimm64`.

### 1.6 What `image[]` and `rw_image[]` are

The backend uses two different views of final code memory:

- `image` is the executable address range used for IP-relative math and final function entry addresses
- `rw_image` is the writable alias that the JIT actually copies bytes into

This matters because:

- relative calls/jumps must be computed against the final executable address
- extable entries store deltas relative to final text addresses
- actual byte stores must go to writable memory before finalization

When `image == NULL`, `do_jit()` is in dry-run mode and only sizes/emits into `temp`.
When `image != NULL`, `do_jit()` verifies that each emitted instruction lands exactly at the precomputed offsets:

- `proglen + ilen <= oldproglen`
- `proglen + ilen == addrs[i]`

If either fails, the JIT aborts as a fatal backend error (`arch/x86/net/bpf_jit_comp.c:2770-2779`).

### 1.7 "Two-pass" vs "many-pass" reality

Conceptually, this backend is usually described as two-pass:

1. size estimation / address discovery
2. actual emission

In code, it is really:

1. rough address seed
2. repeated dry passes until native layout converges
3. final image-writing pass

Potentially more than two dry passes are required because x86 short-vs-near jump selection changes instruction sizes, which changes later displacements, which can cause oscillation.

The backend fights that in two ways:

- it restricts short forward branch offsets to at most 123 bytes via `is_imm8_jmp_offset()` (`arch/x86/net/bpf_jit_comp.c:70-118`)
- in late passes it enables `jmp_padding`, which emits NOP padding when a jump shrinks, so the already-converged layout does not keep bouncing

For directive work, the important takeaway is: the x86 backend assumes a deterministic, repeatable mapping from original BPF instruction order to native byte boundaries across repeated passes.

## 2. Instruction Emission Model

### 2.1 There is no `emit_insn()` in this file

This backend does not have a generic `emit_insn()` dispatcher. The core primitives are:

- `emit_code(u8 *ptr, u32 bytes, unsigned int len)` (`arch/x86/net/bpf_jit_comp.c:25`)
- `EMIT(bytes, len)` and `EMIT1`/`EMIT2`/`EMIT3`/`EMIT4`/`EMIT5`
- `EMIT*_off32` helpers for an opcode prefix followed by a 32-bit immediate/displacement

Everything else is built out of those plus x86 encoding helpers:

- `add_1mod`, `add_2mod`, `add_3mod` for REX bits
- `add_1reg`, `add_2reg` for ModRM encoding
- `maybe_emit_mod`, `maybe_emit_1mod`
- `emit_insn_suffix`, `emit_insn_suffix_SIB`

So the model is:

1. choose opcode bytes
2. choose REX prefix if needed
3. choose ModRM/SIB/displacement bytes
4. write raw bytes directly

### 2.2 BPF register to x86 register mapping

The fixed mapping is in `reg2hex[]` (`arch/x86/net/bpf_jit_comp.c:181-196`):

| BPF reg | x86 reg | Notes |
|---|---|---|
| `BPF_REG_0` | `RAX` | return value |
| `BPF_REG_1` | `RDI` | arg1 |
| `BPF_REG_2` | `RSI` | arg2 |
| `BPF_REG_3` | `RDX` | arg3 |
| `BPF_REG_4` | `RCX` | arg4 / shift count register |
| `BPF_REG_5` | `R8` | arg5 |
| `BPF_REG_6` | `RBX` | callee-saved |
| `BPF_REG_7` | `R13` | callee-saved |
| `BPF_REG_8` | `R14` | callee-saved |
| `BPF_REG_9` | `R15` | callee-saved |
| `BPF_REG_FP` | `RBP` | frame pointer |
| `BPF_REG_AX` | `R10` | BPF temp / blinding temp |
| `AUX_REG` | `R11` | backend scratch |
| `X86_REG_R9` | `R9` | backend-only, also private-stack FP substitute |
| `X86_REG_R12` | `R12` | backend-only, arena base |

Important consequences:

- `R12` is intentionally not exposed as a normal BPF register because x86 addressing with `r12` as base is awkward and more expensive.
- `R10` / `BPF_REG_AX` is reserved for backend/verifier rewrites and constant blinding.
- Any directive that wants more scratch registers is immediately constrained by this mapping and by helper-call ABI preservation.

### 2.3 Concrete emission helpers

Key helpers:

- immediates:
  - `emit_mov_imm32()`
  - `emit_mov_imm64()`
- register moves/sign extension:
  - `emit_mov_reg()`
  - `emit_movsx_reg()`
- memory:
  - `emit_ldx()`, `emit_ldsx()`
  - `emit_ldx_index()`, `emit_ldsx_index()`
  - `emit_stx()`, `emit_stx_index()`
- control flow:
  - `emit_patch()`, `emit_call()`, `emit_jump()`
  - `emit_indirect_jump()`
  - `emit_return()`

The switch inside `do_jit()` then handles each BPF opcode class by calling those helpers or inlining small opcode sequences.

### 2.4 How major BPF classes are lowered

#### ALU / ALU64

Examples:

- register-register add/sub/and/or/xor:
  - `maybe_emit_mod(...)`
  - emit x86 two-register opcode from `simple_alu_opcodes[]`
- immediate add/sub/and/or/xor:
  - emit `83 /op imm8` when possible
  - otherwise `81 /op imm32`
  - special short forms for `rax/eax`
- `MOV`:
  - regular move or sign-extending move depending on `insn->off`
- `MUL`:
  - `imul`
- `DIV` / `MOD`:
  - spill `rax`/`rdx` if necessary
  - move operands into x86's required div registers
  - use `div` or `idiv`
- shifts:
  - immediate shifts use `D1`/`C1`
  - variable shifts prefer BMI2 `shrx/sarx/shlx` when available
  - otherwise move count to `rcx` and use classic shift-by-`cl`
- endian ops:
  - `bswap`, `ror`, `movzwl`, or self-move zero extension

#### LD / LDX / ST / STX

- `BPF_LD | BPF_IMM | BPF_DW` becomes `movabs` or shorter mov forms depending on value width
- plain loads and stores use `emit_ldx` / `emit_ldsx` / `emit_stx`
- stack access is not special in x86 JIT terms; it is just memory access with base `BPF_REG_FP` unless private-stack mode remaps FP to `r9`

#### JMP / JMP32

- compare or test first
- map BPF relation to x86 `Jcc`
- choose short (`rel8`) or near (`rel32`) jump using `addrs[]`
- unconditional `JA` becomes either:
  - optimized away if target is fallthrough
  - short `EB rel8`
  - near `E9 rel32`

#### CALL

`BPF_JMP | BPF_CALL` computes:

- `func = (u8 *)__bpf_call_base + imm32`

That works because verifier and subprog prep rewrite helper/kfunc/pseudo-call immediates into offsets relative to `__bpf_call_base`.

If `src_reg == BPF_PSEUDO_CALL` and `tail_call_reachable` is true, x86 reloads the tail-call counter pointer into `rax` before issuing the call.

#### TAIL_CALL

`BPF_JMP | BPF_TAIL_CALL` is handled by two special inlined sequences:

- `emit_bpf_tail_call_direct()` when verifier created a direct poke descriptor and set `imm != 0`
- `emit_bpf_tail_call_indirect()` otherwise

This is not a helper call. The x86 backend emits the entire tailcall mechanism inline.

### 2.5 Concrete instruction examples

#### Example A: `r0 = *(u8 *)(r1 + 0)`

BPF:

```c
BPF_LDX_MEM(BPF_B, BPF_REG_0, BPF_REG_1, 0)
```

x86 path:

- `do_jit()` hits the `BPF_LDX | BPF_MEM | BPF_B` case
- calls `emit_ldx(&prog, BPF_B, dst_reg, src_reg, off)`
- `emit_ldx()` emits `movzx rax, byte ptr [rdi + 0]`

Bytes:

```asm
48 0f b6 47 00    movzx rax, BYTE PTR [rdi+0x0]
```

Why:

- `r0 -> rax`
- `r1 -> rdi`
- byte load uses `0F B6`
- 64-bit destination uses REX.W

#### Example B: `r6 = *(u8 *)(r7 + 8)`

BPF:

```c
BPF_LDX_MEM(BPF_B, BPF_REG_6, BPF_REG_7, 8)
```

x86:

```asm
49 0f b6 5d 08    movzx rbx, BYTE PTR [r13+0x8]
```

Here the REX prefix changes because `r13` is an extended register.

#### Example C: `r0 += 5`

BPF:

```c
BPF_ALU64_IMM(BPF_ADD, BPF_REG_0, 5)
```

x86:

```asm
48 83 c0 05       add rax, 0x5
```

#### Example D: `if r1 == 0 goto target`

BPF:

```c
BPF_JMP_IMM(BPF_JEQ, BPF_REG_1, 0, off)
```

x86 path:

- immediate 0 compare is optimized into `test reg, reg`
- then `je`

Typical x86:

```asm
48 85 ff          test rdi, rdi
74 xx             je target
```

or near form:

```asm
48 85 ff          test rdi, rdi
0f 84 xx xx xx xx je target
```

#### Example E: `r0 = 0x1122334455667788`

BPF:

```c
BPF_LD_IMM64(BPF_REG_0, 0x1122334455667788ULL)
```

x86:

```asm
48 b8 88 77 66 55 44 33 22 11    movabs rax, 0x1122334455667788
```

## 3. Control Flow

### 3.1 How BPF jumps become x86 jumps

The backend preserves verifier-visible linear instruction order. For conditional jumps:

1. emit `cmp` or `test`
2. map BPF relation to x86 condition code
3. compute displacement with `addrs[target] - addrs[current_boundary]`
4. choose short or near encoding

The condition mapping in `emit_cond_jmp` is:

- `BPF_JEQ -> JE`
- `BPF_JNE -> JNE`
- `BPF_JSET -> JNE` after `test`
- unsigned:
  - `BPF_JGT -> JA`
  - `BPF_JLT -> JB`
  - `BPF_JGE -> JAE`
  - `BPF_JLE -> JBE`
- signed:
  - `BPF_JSGT -> JG`
  - `BPF_JSLT -> JL`
  - `BPF_JSGE -> JGE`
  - `BPF_JSLE -> JLE`

See `arch/x86/net/bpf_jit_comp.c:2561-2604`.

### 3.2 Why `addrs[]` resolves jump targets

Remember the boundary interpretation:

- during emission of BPF insn `i - 1`, the x86 next-PC for that insn is `addrs[i]`
- the BPF jump target boundary is `addrs[i + off]`

So the backend computes:

```c
jmp_offset = addrs[i + insn->off] - addrs[i];
```

for conditional and unconditional jumps.

That is exactly the x86 displacement needed from the end of the current instruction to the target boundary.

Because `addrs[]` comes from the previous pass, this only works if:

- the same BPF insn expands to the same native size on the current pass, or
- the pass loop iterates until the sizes stabilize

That is why convergence and padding matter so much.

### 3.3 Conditional branch emission details

The backend emits:

- short Jcc: `7x rel8`
- near Jcc: `0F 8x rel32`

When `jmp_padding` is enabled and an instruction shrinks from near to short, the backend may insert NOPs before the actual jump to keep downstream addresses stable. This uses:

```c
#define INSN_SZ_DIFF (((addrs[i] - addrs[i - 1]) - (prog - temp)))
```

and the padding logic in `emit_cond_jmp` / `emit_jmp` (`arch/x86/net/bpf_jit_comp.c:1589`, `2605-2719`).

### 3.4 Fall-through vs taken branch

The backend does not perform branch inversion, block placement, or probability-based reordering.

It emits BPF instruction order as given. Therefore:

- the verifier/frontend decides which path is fall-through
- x86 only chooses how to encode the branch
- x86 never flips the CFG to make the hot path fall through

This matters directly for the proposed `branch_reorder` directive: the current backend has no block scheduler.

### 3.5 Exit handling

The first `BPF_EXIT` in linear order materializes the full cleanup/epilogue and records:

- `ctx.cleanup_addr = proglen`

Later `BPF_EXIT`s emit a jump to that shared epilogue.

So there is exactly one real epilogue sequence per compiled function, even if there are many logical exits.

### 3.6 Tail calls

#### Indirect tail call

`emit_bpf_tail_call_indirect()` emits roughly:

1. bounds check `index < array->map.max_entries`
2. load tail-call-count pointer from stack
3. check `*tcc_ptr < MAX_TAIL_CALL_CNT`
4. load `array->ptrs[index]`
5. null check
6. increment tail-call count
7. restore callee-saved state and unwind stack frame
8. jump to `prog->bpf_func + X86_TAIL_CALL_OFFSET`

This is a real inter-program jump, not a call-return pair.

#### Direct tail call

Verifier can create `struct bpf_jit_poke_descriptor` entries for constant tail-call map/key pairs (`kernel/bpf/verifier.c:23744-23766`).

Then x86 emits a patchable bypass site plus a patchable target NOP region:

- `poke->tailcall_bypass`
- `poke->tailcall_target`
- `poke->bypass_addr`
- `poke->adj_off = X86_TAIL_CALL_OFFSET`

Later `bpf_tail_call_direct_fixup()` text-pokes those sites when the map slot is known/stable (`arch/x86/net/bpf_jit_comp.c:871-907`).

### 3.7 bpf2bpf calls

The verifier-side mechanism in `jit_subprogs()` is:

1. rewrite pseudo calls temporarily
2. split the main program into `func[i]`
3. JIT each subprog once to learn native addresses
4. rewrite call immediates / pseudo-func `ldimm64`s to actual callee addresses
5. JIT each subprog again against its cached image

x86-side `BPF_CALL` itself is simple:

```c
func = (u8 *)__bpf_call_base + imm32;
emit_call(&prog, func, ip);
```

The complicated part is entirely verifier/runtime prep, not the x86 call-site emitter.

## 4. Memory Access Patterns

### 4.1 Stack accesses

There is no dedicated stack opcode path in the x86 backend. Stack is just memory with base `BPF_REG_FP`.

Normal case:

- `BPF_REG_FP -> rbp`
- stack load/store uses `emit_ldx/emit_stx` with base `rbp`

Private-stack case:

- if `prog->aux->priv_stack_ptr` exists, x86 computes a per-cpu private frame pointer into backend-only `r9`
- then rewrites any use of `BPF_REG_FP` inside `do_jit()` to `X86_REG_R9`
- see `arch/x86/net/bpf_jit_comp.c:1670-1678`, `1729-1734`

So any directive that pattern-matches stack memory ops must account for both:

- `rbp` base
- `r9` base in private-stack mode

### 4.2 Map value accesses

From x86's point of view, map value accesses are plain memory accesses. The verifier establishes that a register contains a map-value pointer; x86 then just emits `emit_ldx`/`emit_stx` using that register as the base.

Important point:

- `struct bpf_insn_aux_data` does contain map-related facts such as `map_index`, `map_off`, and `map_key_state`
- but the x86 JIT does not consult them when emitting ordinary load/store instructions

So there is no separate "map value load" code path in `do_jit()`. The distinction is verifier-side, not x86-side.

### 4.3 Packet accesses

Direct packet pointer accesses are the same story:

- once the verifier has validated the pointer type and range
- once any ctx/special access has already been rewritten
- x86 just emits a plain memory instruction against whatever base register holds the packet pointer

So again, there is no dedicated "packet load" branch in `do_jit()` for normal direct packet data access.

The special cases that do exist are:

- `LD_ABS` / `LD_IND` rewrites in verifier space
- `PROBE_MEM*`
- arena accesses

### 4.4 Plain byte loads

#### Unsigned byte load path

`BPF_LDX | BPF_MEM | BPF_B` and `BPF_LDX | BPF_PROBE_MEM | BPF_B` eventually go through `emit_ldx()` unless the probe path adds extra scaffolding first.

Generic template from `emit_ldx()`:

```asm
REX.W + 0F B6 + ModRM/SIB/disp
```

This is `movzx r64, byte ptr [base + disp]`.

Examples:

```asm
48 0f b6 47 00    movzx rax, BYTE PTR [rdi+0x0]
49 0f b6 5d 08    movzx rbx, BYTE PTR [r13+0x8]
42 0f b6 44 27 00 movzx eax/rax-family destination from [rdi + r12 + 0]
```

The indexed form is used by `emit_ldx_index()` and by the arena `*_r12` wrappers.

#### Signed byte load path

`BPF_LDX | BPF_MEMSX | BPF_B` and `BPF_LDX | BPF_PROBE_MEMSX | BPF_B` go through `emit_ldsx()`.

Generic template:

```asm
REX.W + 0F BE + ModRM/SIB/disp
```

This is `movsx r64, byte ptr [base + disp]`.

### 4.5 Exact current shape of byte-assemble sequences

This is the most relevant point for a `wide_load` directive.

The x86 backend does not recognize a multi-byte load pattern. If LLVM/verifier leaves a sequence of separate byte loads plus shifts/ors, x86 emits each BPF instruction independently.

A typical little-endian 32-bit byte-assemble sequence like:

```c
r2 = *(u8 *)(r1 + 0);
r3 = *(u8 *)(r1 + 1);
r3 <<= 8;
r2 |= r3;
r3 = *(u8 *)(r1 + 2);
r3 <<= 16;
r2 |= r3;
r3 = *(u8 *)(r1 + 3);
r3 <<= 24;
r2 |= r3;
```

becomes something like:

```asm
48 0f b6 77 00    movzx rsi, BYTE PTR [rdi+0x0]
48 0f b6 57 01    movzx rdx, BYTE PTR [rdi+0x1]
48 c1 e2 08       shl   rdx, 0x8
48 09 d6          or    rsi, rdx
48 0f b6 57 02    movzx rdx, BYTE PTR [rdi+0x2]
48 c1 e2 10       shl   rdx, 0x10
48 09 d6          or    rsi, rdx
48 0f b6 57 03    movzx rdx, BYTE PTR [rdi+0x3]
48 c1 e2 18       shl   rdx, 0x18
48 09 d6          or    rsi, rdx
```

That is exactly the kind of sequence `wide_load` would want to replace with a narrower BPF window but a wider x86 memory operation, for example one `mov esi, dword ptr [rdi+0]` if alignment/endianness/range rules allow it.

### 4.6 `PROBE_MEM` and `PROBE_MEMSX`

`BPF_PROBE_MEM` does not just emit a fault-tolerant load. On x86 it emits:

1. an explicit address-range guard against userspace addresses
2. a zero-result fail-fast path
3. the actual load
4. an exception table entry so a kernel fault skips the load and clears the destination

The rough shape in `do_jit()` for `BPF_PROBE_MEM*` is:

```asm
movabs r10, VSYSCALL_ADDR
mov    r11, src_reg
add    r11, off          ; if off != 0
sub    r11, r10
movabs r10, limit
cmp    r11, r10
ja     load
xor    dst, dst
jmp    after_load
load:
movzx/movsx/mov ...
after_load:
```

Then x86 populates `prog->aux->extable` with:

- faulting instruction length
- destination pt_regs slot
- `EX_TYPE_BPF`

See `arch/x86/net/bpf_jit_comp.c:2247-2335`.

Any directive that tries to fold probe loads must preserve both:

- the explicit fast-path address check
- the extable fault semantics

### 4.7 Arena accesses and `PROBE_MEM32` / `PROBE_ATOMIC`

Arena access is different from generic `PROBE_MEM`.

Verifier rewrites PTR_TO_ARENA memory ops into:

- `BPF_PROBE_MEM32`
- `BPF_PROBE_MEM32SX`
- `BPF_PROBE_ATOMIC`

See `kernel/bpf/verifier.c:22672-22688`.

On x86:

1. `do_jit()` loads `r12 = arena_vm_start` once in the prologue region if `prog->aux->arena` is present (`arch/x86/net/bpf_jit_comp.c:1703-1707`).
2. Arena accesses use helpers like:
   - `emit_ldx_r12()`
   - `emit_ldsx_r12()`
   - `emit_stx_r12()`
   - indexed atomic helpers with `X86_REG_R12`
3. Extable entries are richer than normal probe loads:
   - faulting insn length
   - destination pt_regs slot or `DONT_CLEAR`
   - arena base reg pt_regs offset
   - `FIXUP_ARENA_ACCESS`
   - arena displacement encoded in `ex->data`
4. `ex_handler_bpf()` reports arena violations and then skips/clears as appropriate (`arch/x86/net/bpf_jit_comp.c:1479-1502`).

The practical rule is: arena accesses are not just widened memory ops. They are memory ops coupled to a very specific exception metadata format.

## 5. Prologue and Epilogue

### 5.1 Prologue layout

The prologue is emitted by `emit_prologue()` (`arch/x86/net/bpf_jit_comp.c:506-557`).

The normal non-exception-callback path is:

1. emit CFI preamble (`emit_cfi()`)
2. emit 5-byte patch window (`emit_nops(X86_PATCH_SIZE)`)
3. if entry of a tail-call context and not from classic BPF:
   - `xor rax, rax`
   - this initializes tail-call count
4. `push rbp`
5. `mov rbp, rsp`
6. emit `ENDBR`
7. `sub rsp, round_up(stack_depth, 8)` if stack is needed
8. if tail calls are reachable, emit tail-call-count setup via `emit_prologue_tail_call()`

Special cases:

- exception callback entry reuses/restores the existing main frame rather than creating a fresh ordinary one
- if arena is present, `r12` is pushed later and then loaded with `arena_vm_start`
- if private stack is enabled, `emit_priv_frame_ptr()` sets up `r9`

Also note:

- `X86_TAIL_CALL_OFFSET` is defined to point into the prologue after the patch window and frame-setup prefix
- tail calls jump to `prog->bpf_func + X86_TAIL_CALL_OFFSET`, not to the beginning of the function image

### 5.2 Callee-saved register optimization

`detect_reg_usage()` (`arch/x86/net/bpf_jit_comp.c:1504-1518`) scans the BPF instruction stream and marks whether BPF regs 6-9 appear as source or destination.

That controls saving/restoring:

- `BPF_REG_6 -> rbx`
- `BPF_REG_7 -> r13`
- `BPF_REG_8 -> r14`
- `BPF_REG_9 -> r15`

Then:

- `push_callee_regs()` saves only those marked registers
- `pop_callee_regs()` restores only those marked registers

Exceptions:

- if `prog->aux->exception_boundary` is true, x86 saves and restores all callee-saved regs using the static `all_callee_regs_used[]`
- if arena is present, x86 also saves/restores backend-only `r12`

So the optimization is real, but it is not universal.

### 5.3 Epilogue layout

The first `BPF_EXIT` emits:

1. optional Spectre BHB barrier for classic BPF in the relevant config/capability case
2. restore callee-saved regs
3. restore `r12` if needed
4. `leave`
5. `emit_return()`

`emit_return()` itself may emit:

- `jmp x86_return_thunk` on rethunk systems
- or plain `ret`
- possibly followed by `int3` for SLS mitigation

So the logical BPF epilogue is not always just `leave; ret`.

## 6. Verifier Interaction Points

### 6.1 `struct bpf_insn_aux_data`

The definition is in `include/linux/bpf_verifier.h:525-584`.

It is the verifier's per-instruction side table. Relevant groups of fields:

- memory typing and rewrite inputs:
  - `ptr_type`
  - `ctx_field_size`
  - map-related unions
  - `btf_var`
  - `loop_inline_state`
- rewrite and lowering controls:
  - `nospec`
  - `nospec_result`
  - `zext_dst`
  - `needs_zext`
  - `non_sleepable`
  - `call_with_percpu_alloc_ptr`
  - `arg_prog`
  - `obj_new_size`
  - `insert_off`
  - `kptr_struct_meta`
  - `jt`
- analysis bookkeeping:
  - `seen`
  - `jmp_point`
  - `prune_point`
  - `force_checkpoint`
  - `calls_callback`
  - `scc`
  - `live_regs_before`
- provenance:
  - `orig_idx`

Important practical point:

- by the time x86 JIT runs, it mostly sees already rewritten instructions and a few aggregate `bpf_prog_aux` fields
- most of `insn_aux_data` is consumed earlier by verifier rewrite passes

### 6.2 Where `adjust_insn_aux_data()` is called

Only from `bpf_patch_insn_data()`.

Search result in this tree:

- definition: `kernel/bpf/verifier.c:21926`
- only call site: `kernel/bpf/verifier.c:22035`

This is important because almost every verifier-side instruction expansion funnels through `bpf_patch_insn_data()`.

### 6.3 How `bpf_patch_insn_data()` works

`bpf_patch_insn_data()` (`kernel/bpf/verifier.c:22010-22038`) does:

1. optionally `vrealloc()` the aux array if the patch length `len > 1`
2. call `bpf_patch_insn_single(env->prog, off, patch, len)`
3. on success:
   - `adjust_insn_aux_data(env, new_prog, off, len)`
   - `adjust_subprog_starts(env, off, len)`
   - `adjust_insn_arrays(env, off, len)`
   - `adjust_poke_descs(new_prog, off, len)`

`bpf_patch_insn_single()` in `kernel/bpf/core.c:455-503` is the lower-level instruction-array patcher:

1. possibly reallocates the program storage
2. memmoves the tail of the instruction array
3. copies in the patch sequence
4. adjusts BPF branch offsets
5. adjusts line info offsets

So the full late-rewrite contract is split across:

- instruction-array patching in `core.c`
- aux-data and verifier bookkeeping patching in `verifier.c`

### 6.4 What `adjust_insn_aux_data()` actually preserves

This function is subtle and important.

Behavior for `cnt == 1`:

- it updates `data[off].zext_dst`
- returns

Behavior for `cnt > 1`:

1. remember `old_seen = data[off].seen`
2. memmove the aux tail upward so the original aux slot lands on the last replacement instruction
3. zero the newly inserted prefix aux slots
4. for inserted prefix slots:
   - copy `seen = old_seen`
   - recompute `zext_dst`

What it does not preserve for inserted prefix instructions:

- `orig_idx`
- `ptr_type`
- map facts
- memory facts
- `nospec`
- any custom metadata you might add unless you explicitly propagate it

In other words, inserted verifier-generated instructions immediately lose provenance and most side facts unless later logic rebuilds them.

### 6.5 Current `orig_idx` reality

Despite the comment, `orig_idx` is currently very weak in this tree.

It is:

- initialized once in `bpf_check()` (`kernel/bpf/verifier.c:25933-25940`)
- read for one error message in `bpf_patch_insn_data()` when patching overflows 16-bit BPF branch range (`kernel/bpf/verifier.c:22028-22033`)

It is not meaningfully propagated by `adjust_insn_aux_data()` today.

So if you want userspace-guided directives to survive verifier expansion, `orig_idx` cannot currently carry that on its own.

### 6.6 Where retained memory facts could be recorded

If the goal is to retain facts useful to backend directives, the natural place is still `struct bpf_insn_aux_data`, but the implementation contract is:

1. add field(s) to `struct bpf_insn_aux_data`
2. set them when the verifier discovers or derives the fact
3. explicitly propagate them in `adjust_insn_aux_data()` for inserted instructions
4. preserve/free them correctly in deletion paths such as `clear_insn_aux_data()` / `verifier_remove_insns()`

Otherwise the facts will disappear during late rewrites before x86 ever sees the program.

Good candidates for retention:

- directive provenance by original user instruction/window
- "this load sequence was validated as fusible" markers
- "this branch diamond was validated as cmov-safe" markers
- memory object/range facts that survive through verifier-generated scaffolding

### 6.7 Main verifier-to-JIT lowering stages relevant here

The key stages for backend directives are:

#### `convert_ctx_accesses()`

- rewrites ctx/sock/BTF accesses
- inserts `BPF_ST_NOSPEC`
- rewrites trusted/untrusted pointer memory ops into `BPF_PROBE_MEM*`
- rewrites arena accesses into `BPF_PROBE_MEM32*`
- increments `prog->aux->num_exentries`

This is where many "special" memory instructions that x86 later recognizes are created.

#### `do_misc_fixups()`

This is the big late lowering pass. It:

- inserts helper-inline sequences
- rewrites tail calls
- creates poke descriptors
- inlines some helper patterns
- rewrites some immediate forms

This pass is exactly why backend directives cannot assume the instruction stream reaching x86 still matches the original userspace BPF one-for-one.

#### `opt_subreg_zext_lo32_rnd_hi32()`

This pass is explicitly JIT-driven. It inserts zext-related instructions based on backend needs.

#### `jit_subprogs()`

This is the bridge between verifier final IR and subprog x86 JIT:

- split subprogs
- inherit relevant `bpf_prog_aux` state
- count extable-relevant instructions
- first JIT all subprogs
- rewrite calls to final addresses
- second JIT all subprogs

## 7. Specific Analysis for Directive Implementation

This section focuses on how the current x86 JIT would have to change for the three proposed directives.

### 7.1 `wide_load`

#### Current emission path

Current path for an ordinary unsigned byte load:

1. `do_jit()` enters:
   - `case BPF_LDX | BPF_MEM | BPF_B`
2. it falls into the shared LDX block (`arch/x86/net/bpf_jit_comp.c:2229-2300`)
3. unless probe scaffolding is needed, it calls:
   - `emit_ldx(&prog, BPF_B, dst_reg, src_reg, insn_off)`
4. `emit_ldx()` emits one `movzx` byte load

So the x86 backend today only sees one BPF byte load at a time.

For byte-assemble sequences, the shifts and `or`s are emitted later by their own ALU cases. There is no cross-insn fusion.

#### Where a fused emission hook could go

There are two realistic places:

1. at the top of the `for` loop in `do_jit()`, before the opcode `switch`
2. inside the `BPF_LDX | BPF_MEM | BPF_B` / `BPF_LDX | BPF_MEMSX | BPF_B` case cluster, before calling `emit_ldx()` / `emit_ldsx()`

I would favor a hook near the top of the loop, because `wide_load` is inherently multi-insn and likely needs to inspect:

- following BPF instructions
- branch boundaries / directive metadata
- possibly aux-data/provenance for the whole window

Doing it only inside the single-byte case works, but the logic quickly stops looking like a normal single-insn lowering case.

#### What the hook must prove before fusing

At minimum:

- the whole window is straight-line
- no branch target lands inside the window
- no exception/fault semantics are being changed
- endianness/alignment/range assumptions are valid
- verifier-inserted probe/arena modes are not being accidentally collapsed into a plain load

If you cannot prove "no internal control-flow entry", you cannot safely replace multiple BPF instructions with one native load.

#### How `addrs[]` would need to change

This is the hardest structural part.

Suppose you fuse a window of `K` BPF instructions starting at loop boundary `i0`.

Boundary semantics are:

- `addrs[i0 - 1]` already denotes the native start of the window
- `addrs[i0] ... addrs[i0 + K - 1]` are boundaries inside the window
- `addrs[i0 + K]` is the boundary after the whole window

If the window is truly single-entry, then internal boundaries are no longer real native entry points. You therefore have only two safe options:

1. reject such windows unless no code or metadata ever needs those internal boundaries, or
2. collapse internal boundaries to a shared address and accept coarser mappings

Practically:

- `addrs[i0 + K]` must be set to the fused native end
- `addrs[i0] ... addrs[i0 + K - 1]` can only be collapsed if no branch target or semantic entry can land there

This is why `wide_load` needs verifier help, not just a JIT peephole.

Also note:

- `bpf_prog_fill_jited_linfo()` can tolerate multiple BPF instructions mapping to the same native address
- `bpf_prog_update_insn_ptrs()` for insn-array users can also tolerate identical native IPs
- control-flow entry into a collapsed middle boundary is the real correctness problem

#### Native code target

The likely replacement is not another byte-based sequence. It is a wider x86 memory op, for example:

```asm
8b 77 00          mov esi, DWORD PTR [rdi+0x0]
```

instead of four independent `movzx` byte loads plus shifts/ors, when the semantics really match a native 32-bit little-endian load.

But do not overlook:

- signed vs unsigned result rules
- explicit endianness conversions
- `PROBE_MEM*` and arena cases, which have extra fault behavior

### 7.2 `cmov_select`

#### Current emission path

Today x86 emits branchy control flow exactly as it appears in BPF.

A typical verifier-visible if/else diamond like:

```c
if (r1 > r2) goto then;
r0 = 0;
goto end;
then:
r0 = 1;
end:
```

becomes something like:

```asm
48 39 f7          cmp  rdi, rsi
77 xx             ja   .Lthen
31 c0             xor  eax, eax
eb yy             jmp  .Lend
b8 01 00 00 00    mov  eax, 0x1
```

There is no cmov lowering anywhere in the generic conditional-jump path.

The only existing `cmov`-style encoding in this file is a special-case use in the address-space-cast handling inside `BPF_ALU64 | BPF_MOV | BPF_X`, not a generic select optimization (`arch/x86/net/bpf_jit_comp.c:1756-1785`).

#### Where a cmov hook could go

The natural place is in the conditional jump handling block around:

- compare/test emission
- `emit_cond_jmp` label

At that point, the backend already knows:

- the x86 condition code
- operand widths
- register/immediate compare form

A cmov hook would pattern-match the following BPF window and, if the shape is a safe single-register select, emit:

1. compare/test
2. materialize default value
3. materialize alternate value in scratch
4. `CMOVcc dst, src`

This probably wants a new helper, something like `emit_cmov_reg()` / `emit_cmov_imm_via_scratch()`.

#### What must be proven

At minimum:

- the diamond only defines one destination value with no side effects
- both arms are simple assignments or moves
- the join has no side-entry from elsewhere
- no arm contains helper calls, loads with fault semantics, or other side effects
- destination liveness and scratch-register use are safe

Because x86 `CMOVcc` only moves registers, immediate values require materialization first.

#### `addrs[]` implications

Same structural issue as `wide_load`, but worse:

- the consumed window includes a conditional branch and usually an unconditional branch
- all internal boundaries become non-enterable
- any other jump into the middle of the diamond makes the transform invalid

So again, either:

- prove the window is single-entry single-exit and collapse its internal boundaries, or
- do not perform the transform

Without verifier support, this is fragile.

### 7.3 `branch_reorder`

#### What the current backend does

It preserves original linear order.

It only chooses:

- short vs near branch encodings
- whether a zero-offset unconditional jump can be optimized away

It does not:

- reorder basic blocks
- invert conditions to improve fall-through
- duplicate cold blocks
- maintain a separate block layout graph

#### Can block ordering change without restructuring `do_jit()`?

Not in any clean way.

`do_jit()` is built around:

- one linear `for (i = 1; i <= insn_cnt; i++, insn++)`
- one temporary per logical BPF instruction
- one monotonic boundary table `addrs[]`
- `INSN_SZ_DIFF` defined from adjacent original instruction boundaries

That design is fundamentally "emit in original BPF order".

True block reordering would require at least:

1. CFG/basic-block discovery at the backend
2. a block schedule distinct from original instruction order
3. a different label/boundary mapping model
4. a rewrite of short-jump convergence logic and padding logic

The strongest proof of incompatibility is the padding code:

```c
#define INSN_SZ_DIFF (((addrs[i] - addrs[i - 1]) - (prog - temp)))
```

That only makes sense when BPF instruction `i - 1` is emitted immediately after BPF instruction `i - 2` in native order. Once blocks are reordered, adjacent original indices are no longer adjacent native regions, and the formula stops meaning what the backend expects.

#### Constraints from `addrs[]`

`addrs[]` maps original BPF instruction boundaries to native boundaries. That is fine even for arbitrary layouts in theory, but this backend's implementation assumes much more:

- linear fill order
- local size-difference reasoning from adjacent original indices
- later-pass shrinking/padding based on those adjacent differences

So `branch_reorder` is not a peephole feature here. It is a backend architecture change.

## 8. Constant Blinding

### 8.1 How blinding works

`bpf_jit_blind_constants()` in `kernel/bpf/core.c:1489-1553`:

1. returns early if blinding not requested or already applied
2. clones the program
3. scans instructions
4. rewrites eligible immediate-bearing instructions using random masks and `BPF_REG_AX`
5. patches the clone with `bpf_patch_insn_single()`
6. updates insn-array offsets
7. marks the clone as `blinded`

The actual rewrite logic is in `bpf_jit_blind_insn()` (`kernel/bpf/core.c:1294-1487`).

Typical patterns:

- `ALU*_K` becomes:
  - `mov ax, rnd ^ imm`
  - `xor ax, rnd`
  - original op rewritten to register-source form
- `JMP*_K` becomes:
  - materialize blinded immediate in `ax`
  - rewrite compare to register form
- `LD_IMM64` becomes multiple instructions building the constant through `ax`
- store-immediate becomes load-immediate-to-ax plus `STX`

### 8.2 When it runs relative to verification

It runs:

- after verifier completion
- before x86 pass-loop emission

This is critical because:

- verifier aux/provenance machinery is no longer live
- the blinding clone is produced by `bpf_patch_insn_single()` directly, not by `bpf_patch_insn_data()`
- therefore verifier `insn_aux_data` is not updated in tandem with the clone

### 8.3 Why blinding is problematic for directives

For directives, blinding is problematic in three ways:

#### Instruction windows can disappear

A single immediate-bearing BPF instruction may expand into 3 or more instructions before x86 emission.

That means:

- original instruction indices no longer line up with the actual program JITed by x86
- any backend window matcher keyed to original indices will drift

#### Pattern shapes change

Examples:

- `JMP_IMM` becomes `JMP_REG` against `BPF_REG_AX`
- immediate stores become register stores
- `LD_IMM64` expands into a staged build sequence

So a directive matcher that expects a specific BPF opcode shape may no longer see it.

#### Verifier provenance does not automatically follow the clone

Because blinding operates after verifier lifetime and uses `bpf_patch_insn_single()` directly, any directive metadata stored only in verifier aux structures is gone unless separately copied or reconstructible.

### 8.4 Practical implication

Any directive implementation needs an explicit policy for blinding. Real options are:

1. disallow directives when blinding is active
2. disable blinding for directive-tagged programs
3. carry directive metadata through the blinded clone in a separate side structure
4. define directives over post-blinding instruction windows instead of original ones

Option 3 is the most compatible, but it requires new plumbing outside the current verifier aux path.

## 9. Key Constraints and Gotchas

### 9.1 The backend is per-insn and in-order

The single biggest constraint:

- `do_jit()` emits one BPF instruction at a time in original order
- each iteration writes into `temp`
- `ilen` is checked against `BPF_MAX_INSN_SIZE`

This means every cross-insn optimization is fighting the current structure.

### 9.2 `BPF_MAX_INSN_SIZE` is only 128 bytes

`temp` is sized as:

```c
u8 temp[BPF_MAX_INSN_SIZE + BPF_INSN_SAFETY];
```

and each iteration rejects:

```c
if (ilen > BPF_MAX_INSN_SIZE) fatal
```

So any directive that fuses multiple BPF instructions into one emission step must keep the emitted native sequence under 128 bytes or redesign the temporary-buffer assumption.

### 9.3 Once `image` is allocated, layout must reproduce exactly

After the final code image is allocated, the backend insists that every later pass reproduce the already-converged offsets exactly. If a directive introduces pass-dependent behavior or unstable matching, x86 will fail hard.

Determinism across passes is mandatory.

### 9.4 `addrs[]` has two consumers with different interpretations

- full `addrs[]` is start-of-insn boundaries for insn arrays
- `addrs + 1` is end-of-insn boundaries for line info

Collapsing multiple BPF instructions to one native address may be acceptable for tooling, but not for control-flow entry into the middle of the window.

### 9.5 Directives must respect verifier rewrites first

By the time x86 sees the instruction stream, verifier may already have:

- inserted `BPF_ST_NOSPEC`
- rewritten accesses to `BPF_PROBE_MEM*`
- rewritten arena accesses
- inlined helpers
- inserted zext instructions
- rewritten tail calls

So a directive keyed only to original userspace bytecode is not sufficient. It needs either:

- stable provenance across rewrites, or
- a revalidation phase after rewrites

### 9.6 `orig_idx` is not enough today

Current `orig_idx` is initialized but not propagated through inserted verifier patchlets. If directive provenance needs to survive rewrites, `adjust_insn_aux_data()` must change.

### 9.7 Private stack and arena change register assumptions

Two backend modes materially alter addressing:

- private stack: `fp` accesses are remapped to `r9`
- arena: `r12` is reserved and preloaded with `arena_vm_start`

Any directive matcher or emitter that assumes:

- `fp == rbp`
- `r12` is free

will be wrong in some programs.

### 9.8 Fault-handled memory ops are not ordinary loads/stores

`PROBE_MEM*`, `PROBE_MEM32*`, and `PROBE_ATOMIC` have extable semantics. If directives touch them, they must preserve:

- correct faulting instruction length
- correct destination-clear behavior
- correct arena metadata when applicable
- correct `prog->aux->num_exentries`

Breaking extable accounting will cause backend failure or silent exception-handling bugs.

### 9.9 Direct tail calls depend on fixed patch geometry

Direct tail calls rely on 5-byte patchable jump slots and verifier-created poke descriptors. Do not casually change sizes or surrounding layout in that region without auditing:

- `emit_bpf_tail_call_direct()`
- `bpf_tail_call_direct_fixup()`
- verifier tail-call poke creation

### 9.10 CFI/ENDBR means function image start is not always callable entry

`prog->bpf_func` is set to:

```c
(void *)image + cfi_get_offset()
```

not necessarily raw `image`.

Any code that wants to reason about "native offset 0" needs to distinguish:

- start of allocated image
- start of callable BPF entrypoint

### 9.11 Likely lowest-risk insertion points

Given the current design, the least invasive directive strategy is probably:

1. keep verifier/runtime instruction order unchanged
2. add verifier-retained metadata for small, single-entry, side-effect-free windows
3. implement only local backend peepholes that:
   - preserve straight-line order
   - preserve pass determinism
   - collapse only non-enterable internal boundaries

That favors:

- `wide_load` over small byte-assemble windows
- `cmov_select` over tiny verified diamonds

and disfavors:

- true `branch_reorder` in the current backend structure

## 10. Implementation-Oriented Bottom Line

If the goal is "userspace-guided backend directives" on x86, the current kernel structure suggests:

1. Directive metadata must survive verifier rewrites, or be reconstructed after them.
2. `adjust_insn_aux_data()` is the first place that needs surgery for provenance retention.
3. Constant blinding is a second independent rewrite stage that must be handled explicitly.
4. The x86 backend can support local multi-insn peepholes, but only if:
   - they are deterministic across passes
   - they do not require true CFG reordering
   - they handle `addrs[]` boundary semantics correctly
   - they reject windows with internal branch targets
5. `wide_load` and `cmov_select` are plausible in the current architecture with careful metadata plumbing.
6. `branch_reorder` is not plausible as a localized patch to `do_jit()`; it wants a block-scheduled backend rather than the current linear emitter.
