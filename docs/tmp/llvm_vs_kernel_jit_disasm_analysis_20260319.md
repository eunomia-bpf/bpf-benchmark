# LLVM JIT vs Kernel JIT x86_64 Disassembly Analysis

Date: March 19, 2026

## Goal

Explain where the current `llvmbpf` vs stock kernel JIT gap comes from at the native x86_64 instruction level for representative BPF programs.

## Inputs and Method

- Project context: `docs/kernel-jit-optimization-plan.md`
- Fresh build on March 19, 2026:
  - `source /home/yunwei37/workspace/.venv/bin/activate`
  - `make -C micro micro_exec programs`
- Fresh disassembly dumps on March 19, 2026:
  - `micro_exec run-llvmbpf --dump-jit --compile-only`
  - `sudo -n micro_exec run-kernel --dump-jit --dump-xlated ... --compile-only`
  - `llvm-objdump -dr --no-show-raw-insn --triple=bpfel` for BPF bytecode
  - `objdump -D -Mintel -b binary -m i386:x86-64` for native code
- Dump artifacts are stored in:
  - `docs/tmp/llvm_vs_kernel_jit_disasm_20260319_artifacts/`
- Runtime medians come from the authoritative March 18, 2026 VM run:
  - `micro/results/vm_micro_authoritative_20260318.json`
- Approximate cycle deltas use the average TSC frequency from that run:
  - `3.686 GHz`
  - Rough rule: `1 ns ~= 3.686 cycles`

Notes:

- `simple` is included only as a structural control. Its kernel median on March 18, 2026 is `10.5 ns`, so the runtime ratio is below `ktime` resolution and should not be treated as a real backend-performance signal.
- I did **not** use `branch_flip_dense` in the main set. On March 18, 2026 it was `1.050x` (`llvmbpf/kernel`), so it does not explain the observed LLVM advantage. `bounds_ladder` is more representative of the current gap, but it is not a pure BRANCH_FLIP isolate.

## Selected Benchmarks

| Benchmark | Form focus | llvmbpf ns | kernel ns | L/K exec ratio | L/K code ratio | Why selected |
| --- | --- | ---: | ---: | ---: | ---: | --- |
| `rotate_dense` | ROTATE | 124.0 | 204.5 | 0.606x | 0.741x | Cleanest rotate idiom; large repeated hot pattern |
| `cond_select_dense` | COND_SELECT | 52.0 | 74.0 | 0.703x | 0.815x | Cleanest compare/select diamond |
| `load_byte_recompose` | WIDE_MEM | 65.0 | 147.0 | 0.442x | 0.312x | Most direct byte-recompose causal isolate |
| `extract_dense` | BITFIELD_EXTRACT | 78.0 | 159.0 | 0.491x | 0.664x | Useful precisely because it does **not** become `bextr` |
| `endian_swap_dense` | ENDIAN_FUSION | 44.0 | 117.5 | 0.374x | 0.609x | Exact `be32` lowering comparison |
| `bounds_ladder` | BRANCH_FLIP-adjacent | 73.5 | 138.0 | 0.533x | 0.343x | Branch-heavy real winner, but entangled with wide-load collapse |
| `large_mixed_500` | Mixed forms | 345.0 | 429.0 | 0.804x | 0.418x | Shows interaction beyond single canonical forms |
| `simple` | Control / no optimization sites | 16.0 | 10.5 | 1.524x | 0.624x | Structural control for prologue/store shaping |

## Executive Summary

1. The two clearest first-order LLVM wins are still:
   - wide-load collapse of byte-recompose ladders
   - rotate idiom selection (`rorx` instead of `shr; shl; or`)
2. `cond_select_dense` shows a real if-conversion advantage:
   - LLVM emits `104` `cmov` instructions and only `1` branch
   - kernel emits `107` branches and no `cmov`
3. `endian_swap_dense` matches the expected ENDIAN_FUSION story exactly:
   - LLVM emits `256` `movbe`
   - kernel emits `256` `bswap` after separate loads
4. `extract_dense` is important because it shows a gap **outside** the current 8-form taxonomy:
   - neither side emits `bextr`
   - LLVM instead narrows loads and arithmetic to `32-bit` operations
5. `bounds_ladder` is **not** a pure BRANCH_FLIP explanation of the gap:
   - the bigger win is still wide-load collapse
   - LLVM also if-converts two branch diamonds with `cmove`
6. `large_mixed_500` confirms that a sizeable remainder of the gap is not attributable to any single local peephole:
   - LLVM mixes load collapsing, `cmov`, rotate/variable-shift selection, and better whole-function register use
7. `simple` shows that smaller code alone does not guarantee speed on ultra-short programs. It is a useful control, not a contributor to the real gap.

## Cross-Benchmark Native Summary

| Benchmark | LLVM insns | Kernel insns | Static delta | Approx cycle delta | Most visible difference |
| --- | ---: | ---: | ---: | ---: | --- |
| `rotate_dense` | 1838 | 2814 | +976 kernel | +297 cycles | `256` `rorx` vs `256` rotate triplets |
| `cond_select_dense` | 959 | 1398 | +439 kernel | +81 cycles | `104` `cmov` vs `107` branches |
| `load_byte_recompose` | 36 | 96 | +60 kernel | +302 cycles | qword load vs byte ladder |
| `extract_dense` | 2077 | 2604 | +527 kernel | +299 cycles | 32-bit narrowing vs 64-bit ops |
| `endian_swap_dense` | 777 | 1068 | +291 kernel | +271 cycles | `256` `movbe` vs `256` `bswap` |
| `bounds_ladder` | 73 | 203 | +130 kernel | +238 cycles | wide loads + `cmove` vs byte ladders + branches |
| `large_mixed_500` | 232 | 576 | +344 kernel | +310 cycles | mixed-form whole-function optimization |
| `simple` | 24 | 33 | +9 kernel | not meaningful | store coalescing / prologue shape |

## Detailed Side-by-Side Analysis

### 1. `rotate_dense` (ROTATE)

Artifacts:

- `docs/tmp/llvm_vs_kernel_jit_disasm_20260319_artifacts/rotate_dense.bpf.asm`
- `docs/tmp/llvm_vs_kernel_jit_disasm_20260319_artifacts/rotate_dense.llvmbpf.asm`
- `docs/tmp/llvm_vs_kernel_jit_disasm_20260319_artifacts/rotate_dense.kernel.asm`

Key BPF bytecode:

```asm
r3 += r2
r2 = r3
r2 >>= 0x33
r3 <<= 0xd
r3 |= r2
```

LLVM JIT:

```asm
lea    rcx,[rsi+rax*1]
xor    rcx,rbp
rorx   rcx,rcx,0x2f
```

Kernel JIT:

```asm
add    rdx,rsi
mov    rsi,rdx
shr    rsi,0x33
shl    rdx,0xd
or     rdx,rsi
```

What LLVM does differently:

- LLVM recognizes the rotate idiom and selects a single rotate instruction.
- On this benchmark LLVM emits `256` `rorx`.
- Kernel emits the literal BPF lowering: `256` `shl`, `263` `shr`, and `256` `or`.
- Roughly `519` of the `976` extra kernel instructions are directly explained by rotate expansion alone.

Canonical-form mapping:

- This is the cleanest example of `ROTATE`.

Cycle estimate:

- Per site, the kernel sequence is about `3` dependent ALU ops where LLVM uses `1`.
- A reasonable exposed-latency estimate is about `2 cycles/site`.
- With `256` sites, the upper-bound structural win is about `500` cycles.
- The measured benchmark delta is about `297` cycles, which is consistent with rotate lowering being the dominant cause and the rest partially overlapping.

### 2. `cond_select_dense` (COND_SELECT)

Artifacts:

- `docs/tmp/llvm_vs_kernel_jit_disasm_20260319_artifacts/cond_select_dense.bpf.asm`
- `docs/tmp/llvm_vs_kernel_jit_disasm_20260319_artifacts/cond_select_dense.llvmbpf.asm`
- `docs/tmp/llvm_vs_kernel_jit_disasm_20260319_artifacts/cond_select_dense.kernel.asm`

Key BPF bytecode:

```asm
r3 = r4
if r0 > r5 goto +0x1
r3 = r2
r2 ^= const
r2 += acc
```

LLVM JIT:

```asm
mov    rsi,QWORD PTR [rax+0x8]
cmp    rsi,QWORD PTR [rax+0x348]
cmova  rcx,rdx
...
cmp    rdi,QWORD PTR [rax+0x350]
cmova  rcx,rsi
```

Kernel JIT:

```asm
mov    rcx,r8
cmp    rbx,rax
ja     0xdf
mov    rcx,rsi
...
mov    rcx,r8
cmp    rbx,rax
ja     0x116
mov    rcx,rdx
```

What LLVM does differently:

- LLVM if-converts the select diamonds into `cmov`.
- LLVM has `104` `cmov` and only `1` branch in the whole function.
- Kernel has `107` branches and no `cmov`.
- The branch reduction is larger than the code-size ratio alone suggests, because it removes control-flow edges rather than just dead instructions.

Canonical-form mapping:

- This is the cleanest `COND_SELECT` benchmark in the current suite.

Cycle estimate:

- If branches are perfectly predicted, `cmp + branch + move` vs `cmp + cmov` is only a small win, around `~1 cycle/site`.
- If branches are unpredictable, the advantage can jump to `10-15+ cycles/site`.
- The observed benchmark delta is about `81` cycles total, or about `0.8 cycles/site`, which suggests the dataset is mostly predictable but still benefits from branch elimination.

### 3. `load_byte_recompose` (WIDE_MEM)

Artifacts:

- `docs/tmp/llvm_vs_kernel_jit_disasm_20260319_artifacts/load_byte_recompose.bpf.asm`
- `docs/tmp/llvm_vs_kernel_jit_disasm_20260319_artifacts/load_byte_recompose.llvmbpf.asm`
- `docs/tmp/llvm_vs_kernel_jit_disasm_20260319_artifacts/load_byte_recompose.kernel.asm`

Key BPF bytecode:

```asm
r2 = *(u8 *)(r1 + 0x9)
r2 <<= 0x8
r3 = *(u8 *)(r1 + 0x8)
r2 |= r3
...
r0 = *(u8 *)(r4 + 0x0)
```

LLVM JIT:

```asm
cmp    DWORD PTR [rax+0x8],0x80
...
mov    rdi,QWORD PTR [rcx-0x7]
and    r8b,0xf
shrx   r8,rdi,r8
add    rsi,rdi
xor    rsi,r8
```

Kernel JIT:

```asm
movzx  rsi,BYTE PTR [rdi+0x9]
shl    rsi,0x8
movzx  rdx,BYTE PTR [rdi+0x8]
or     rsi,rdx
...
movzx  rsi,BYTE PTR [rcx-0x6]
shl    rsi,0x8
or     rsi,rbx
```

What LLVM does differently:

- LLVM collapses the byte-recompose ladder into real `DWORD`/`QWORD` loads.
- Even the `count == 128` header check is narrowed to a single `cmp DWORD PTR [...]`.
- In the loop, LLVM loads one `QWORD` and immediately applies `shrx`.
- Kernel still reconstructs the same values byte-by-byte with `movzx` + `shl` + `or`.

Canonical-form mapping:

- This is the strongest current `WIDE_MEM` example.

Cycle estimate:

- The kernel loop uses about `8` byte loads plus multiple merge ops per value.
- LLVM reduces that to one `QWORD` load plus the real work.
- A static instruction accounting says about `8-10` hot instructions disappear per loaded value.
- The observed delta is about `302` cycles total, or about `2.4 cycles` per loop iteration across `128` values. That means most of the static savings are real, but only part of them are on the exposed critical path.

### 4. `extract_dense` (BITFIELD_EXTRACT, but not in the expected way)

Artifacts:

- `docs/tmp/llvm_vs_kernel_jit_disasm_20260319_artifacts/extract_dense.bpf.asm`
- `docs/tmp/llvm_vs_kernel_jit_disasm_20260319_artifacts/extract_dense.llvmbpf.asm`
- `docs/tmp/llvm_vs_kernel_jit_disasm_20260319_artifacts/extract_dense.kernel.asm`

Key BPF bytecode:

```asm
r3 = *(u64 *)(r1 + 0x8)
r4 = r3
r4 >>= 0x5
r4 &= 0x1f
r5 = r3
r5 >>= 0x11
r5 &= 0x3ff
```

LLVM JIT:

```asm
mov    edx,DWORD PTR [rax+0x8]
mov    esi,edx
shr    esi,0x5
and    esi,0x1f
shr    edx,0x11
and    edx,0x3ff
```

Kernel JIT:

```asm
mov    rdx,QWORD PTR [rdi+0x8]
mov    rcx,rdx
shr    rcx,0x5
and    rcx,0x1f
mov    r8,rdx
shr    r8,0x11
and    r8,0x3ff
```

What LLVM does differently:

- Neither side emits `bextr`.
- The real LLVM win is **load-width narrowing**:
  - LLVM turns the `u64` BPF load into `DWORD PTR` native loads because only low bits are used.
  - LLVM keeps the whole extract pipeline in `32-bit` registers.
- Kernel keeps the literal `64-bit` load and `64-bit` arithmetic.

Canonical-form mapping:

- This benchmark was expected to represent `BITFIELD_EXTRACT`.
- For stock LLVM-vs-kernel JIT, the dominant difference is **not** `bextr`.
- This means the current 8-form taxonomy is missing at least one real codegen effect: `load-width narrowing / partial-width lowering`.

Cycle estimate:

- The benchmark delta is about `299` cycles.
- Spread across `256` input words, that is only about `1.2 cycles/word`.
- That is exactly the profile expected from width narrowing: small per-site savings, but repeated many times.

### 5. `endian_swap_dense` (ENDIAN_FUSION)

Artifacts:

- `docs/tmp/llvm_vs_kernel_jit_disasm_20260319_artifacts/endian_swap_dense.bpf.asm`
- `docs/tmp/llvm_vs_kernel_jit_disasm_20260319_artifacts/endian_swap_dense.llvmbpf.asm`
- `docs/tmp/llvm_vs_kernel_jit_disasm_20260319_artifacts/endian_swap_dense.kernel.asm`

Key BPF bytecode:

```asm
r3 = *(u32 *)(r1 + 0x8)
r3 = be32 r3
...
r3 = *(u32 *)(r1 + 0xc)
r3 = be32 r3
```

LLVM JIT:

```asm
movbe  ecx,DWORD PTR [rax+0x8]
movbe  edx,DWORD PTR [rax+0xc]
add    rdx,rcx
movbe  ecx,DWORD PTR [rax+0x10]
```

Kernel JIT:

```asm
mov    edx,DWORD PTR [rdi+0x8]
bswap  edx
...
mov    edx,DWORD PTR [rdi+0xc]
bswap  edx
```

What LLVM does differently:

- LLVM fuses `load + bswap` into `movbe`.
- LLVM emits `256` `movbe`.
- Kernel emits `256` `bswap` after separate loads.
- This is exactly the expected `ENDIAN_FUSION` story and is one of the cleanest cross-runtime differences in the set.

Canonical-form mapping:

- Clean `ENDIAN_FUSION`.

Cycle estimate:

- This is roughly a `1 instruction/site` win.
- The measured delta is about `271` cycles total, or about `1.06 cycles/site` across `256` swaps.
- That lines up very closely with the native instruction difference.

### 6. `bounds_ladder` (branch-heavy, but mostly WIDE_MEM in practice)

Artifacts:

- `docs/tmp/llvm_vs_kernel_jit_disasm_20260319_artifacts/bounds_ladder.bpf.asm`
- `docs/tmp/llvm_vs_kernel_jit_disasm_20260319_artifacts/bounds_ladder.llvmbpf.asm`
- `docs/tmp/llvm_vs_kernel_jit_disasm_20260319_artifacts/bounds_ladder.kernel.asm`

Key BPF bytecode:

```asm
r3 &= 0x1
if r3 == 0x0 goto +0x3
r0 >>= 0x5
r8 ^= r0
...
r5 &= 0x3
if r5 == 0x0 goto ...
r4 <<= 0x1
r9 ^= r4
```

LLVM JIT:

```asm
mov    r8,QWORD PTR [rax+rcx*1+0x28]
...
test   r11b,0x1
cmove  rdi,r9
...
test   bl,0x3
cmove  rdx,r8
```

Kernel JIT:

```asm
movzx  rdi,BYTE PTR [r8+0x24]
shl    rdi,0x20
movzx  rbx,BYTE PTR [r8+0x22]
...
cmp    rsi,0x20
jne    0x2fb
...
je     0x2a8
```

What LLVM does differently:

- LLVM does use a small amount of branch elimination:
  - `2` `cmove`
  - fewer branches (`4` vs `10`)
- But that is **not** the whole story.
- The much larger difference is that LLVM recognizes fixed-offset fields and uses real `QWORD` loads for the 64-bit record fields, while the kernel still byte-recomposes them.
- Static counts make this obvious:
  - LLVM: `8` `movzx`
  - kernel: `40` `movzx`

Canonical-form mapping:

- `bounds_ladder` is not a clean BRANCH_FLIP isolate.
- In this benchmark, the observed gap is mostly `WIDE_MEM`, with a secondary if-conversion win.

Cycle estimate:

- The benchmark delta is about `238` cycles total.
- With `32` records, that is about `7.4 cycles/record`.
- That is far too large to be explained by just two conditional moves; it strongly suggests the wide-load collapse is the first-order cause.

### 7. `large_mixed_500` (mixed forms + whole-function optimization)

Artifacts:

- `docs/tmp/llvm_vs_kernel_jit_disasm_20260319_artifacts/large_mixed_500.bpf.asm`
- `docs/tmp/llvm_vs_kernel_jit_disasm_20260319_artifacts/large_mixed_500.llvmbpf.asm`
- `docs/tmp/llvm_vs_kernel_jit_disasm_20260319_artifacts/large_mixed_500.kernel.asm`

Key BPF bytecode:

```asm
r2 &= 0x7
r5 = r8
r5 <<= r2
r5 ^= r3
r5 ^= r1
r5 += r1
...
if r2 == 0x0 goto +0x2
```

LLVM JIT:

```asm
movzx  esi,BYTE PTR [rax+rcx*1-0x24]
...
shlx   rdi,r14,rdi
...
test   dil,0x1
cmove  r12,r8
```

Kernel JIT:

```asm
movzx  rdi,BYTE PTR [rsi-0x24]
movzx  rcx,BYTE PTR [rsi-0x26]
...
shr    rdx,0x4
...
je     0x808
```

What LLVM does differently:

- LLVM does **not** completely eliminate byte-recompose here; some byte loads remain.
- But LLVM still wins on several fronts at once:
  - fewer byte loads (`12` `movzx` vs `72`)
  - fewer branches (`3` vs `18`)
  - `8` `cmov`
  - `7` `rorx`
  - variable-shift lowering such as `shlx`
- The remaining gap here is therefore a mixed optimizer effect, not a single canonical-form effect.

Canonical-form mapping:

- This is the clearest example that the gap is wider than the current local-form taxonomy.

Inference:

- The extra win here is partly register allocation and whole-function scheduling, because no single local transform explains a `576 -> 232` instruction drop.

Cycle estimate:

- The measured delta is about `310` cycles total.
- Across `32` outer iterations, that is about `9.7 cycles/iteration`.
- That is consistent with several small local wins stacking together rather than one dominant peephole.

### 8. `simple` (control)

Artifacts:

- `docs/tmp/llvm_vs_kernel_jit_disasm_20260319_artifacts/simple.llvmbpf.asm`
- `docs/tmp/llvm_vs_kernel_jit_disasm_20260319_artifacts/simple.kernel.asm`

LLVM JIT:

```asm
endbr64
...
mov    BYTE PTR [rax+0x2],0xbc
mov    WORD PTR [rax],0x614e
mov    DWORD PTR [rax+0x3],0x0
mov    BYTE PTR [rax+0x7],0x0
ret
```

Kernel JIT:

```asm
push   rbp
mov    rbp,rsp
...
mov    BYTE PTR [rdi+0x2],sil
mov    BYTE PTR [rdi+0x1],sil
mov    BYTE PTR [rdi+0x0],sil
...
leave
ret
```

What it shows:

- LLVM coalesces the constant output store into mixed-width stores.
- Kernel writes the same bytes one-by-one and keeps a frame prologue/epilogue.
- This is a real codegen difference, but not one of the main gap drivers.

Why it matters:

- Even here, LLVM code is smaller.
- But the runtime result goes the other way in the March 18, 2026 authoritative run because the kernel median is only `10.5 ns`.
- So `simple` confirms that ultra-short timings are not useful for gap attribution.

## Form-Level Attribution

| Gap source | Benchmarks | Evidence | Confidence |
| --- | --- | --- | --- |
| WIDE_MEM / byte-recompose collapse | `load_byte_recompose`, `bounds_ladder`, `large_mixed_500` | LLVM replaces byte ladders with `DWORD`/`QWORD` loads; kernel remains literal | High |
| ROTATE | `rotate_dense`, `large_mixed_500` | `rorx` on LLVM side; kernel uses `shr/shl/or` | High |
| COND_SELECT / if-conversion | `cond_select_dense`, `bounds_ladder`, `large_mixed_500` | LLVM emits `cmov/cmove`; kernel keeps branches | High for existence, medium for total suite contribution |
| ENDIAN_FUSION | `endian_swap_dense` | `movbe` vs `mov + bswap` | High |
| BITFIELD_EXTRACT as currently defined | `extract_dense` | No `bextr` on either side; current form does not describe the actual LLVM win | Low as an explanation of current stock-vs-LLVM gap |
| BRANCH_FLIP alone | `bounds_ladder` | Present, but secondary to load widening | Medium-low |

## Differences Not Captured by the Current 8 Canonical Forms

### 1. Load-width narrowing

`extract_dense` is the clearest example. LLVM uses `DWORD PTR` loads and `32-bit` arithmetic because the extracted fields never require the high half of the original `u64`. Kernel keeps the literal `64-bit` shape.

This is a real backend advantage, and it is not the same as `BITFIELD_EXTRACT` in the current BpfReJIT taxonomy.

### 2. Store coalescing

`simple` shows LLVM coalescing small constant stores into wider native stores. Kernel still writes byte-by-byte. This is small, but it is another native selection difference outside the current 8 forms.

### 3. Whole-function if-conversion and mixed-form profitability

`large_mixed_500` shows LLVM stacking several small transforms in one function:

- fewer byte loads
- fewer branches
- some `cmov`
- some rotate selection
- variable-shift instruction selection

This is bigger than a local one-site matcher. It depends on whole-function register and CFG reasoning.

### 4. Register-width and register-allocation effects

`extract_dense` and `large_mixed_500` both show LLVM using narrower ops or fewer temporaries. That is hard for the current kernel JIT model to replicate with local peepholes alone.

## What LLVM Does That the Kernel JIT Cannot Easily Replicate

### Easy or at least plausible for kernel JIT

- Local rotate idiom selection (`ROTATE`)
- Local load+byte-swap fusion (`ENDIAN_FUSION`)
- Local byte-recompose collapse when the access window is obvious (`WIDE_MEM`)
- Small local branch-to-`cmov` if-conversion (`COND_SELECT`)

### Harder without adding more IR-like reasoning

- Load-width narrowing from downstream use-def reasoning (`extract_dense`)
- Choosing when if-conversion is profitable over a large straight-line region (`cond_select_dense`, `large_mixed_500`)
- Mixing several transforms in one pass while preserving good register allocation (`large_mixed_500`)
- Coalescing stores and narrowing intermediate values based on whole-function dataflow (`simple`, `extract_dense`)

In short:

- The current kernel JIT can realistically recover a meaningful subset of the gap with better local lowering.
- The remaining gap is not just "missing peepholes"; part of it is real optimizer territory.

## Bottom Line

1. The largest instruction-level contributors in this comparison are:
   - `WIDE_MEM` / byte-recompose collapse
   - `ROTATE`
2. The next tier is:
   - `COND_SELECT`
   - `ENDIAN_FUSION`
3. `BRANCH_FLIP` is **not** the main explanation for the current LLVM advantage in the chosen branch-heavy benchmark. In `bounds_ladder`, most of the win is still wide-load collapse.
4. At least one meaningful gap source is missing from the 8-form taxonomy:
   - load-width narrowing / partial-width lowering
5. `large_mixed_500` shows the remaining gap is partly beyond local canonical forms:
   - register allocation
   - mixed-form scheduling
   - whole-function if-conversion decisions

If the paper question is "where does the `llvmbpf` advantage come from on x86_64?", the instruction-level answer from this side-by-side dump set is:

- first from wider and more fused memory operations,
- second from better rotate and select lowering,
- and third from optimizer effects that are broader than the current BpfReJIT canonical-form vocabulary.
