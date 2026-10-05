# Additional x86 BPF JIT Optimization Opportunities Beyond Byte-Recompose, `cmov`, and Callee-Saved Trimming

## Scope and Method

- Kernel source inspected: `vendor/linux/arch/x86/net/bpf_jit_comp.c`
- Existing writeup inspected: `docs/paper.md` sections 5 and 10
- Workload source inspected: `micro/programs/*.bpf.c`
- Concrete codegen examples taken from `micro/jit-dumps/*.asm` and summary tables in `micro/jit-dumps/report.md`
- Performance ratios taken from `micro/results/pure_jit_authoritative_analysis.md`

Important constraint: both runtimes consume the same eBPF ELF, so differences in `micro/jit-dumps/*.asm` are codegen differences, not source-level differences.

This file focuses on what the kernel x86 JIT actually does today, not on generic compiler wishlists.

## Short Answer

The kernel x86 JIT is still fundamentally a linear instruction selector:

- it scans once to detect callee-saved register usage (`detect_reg_usage()`, `vendor/linux/arch/x86/net/bpf_jit_comp.c:1504-1519`);
- then it emits x86 in one `for` loop over BPF insns (`do_jit()`, `vendor/linux/arch/x86/net/bpf_jit_comp.c:1652-2794`);
- there is no CFG builder, no value lattice, no liveness engine beyond callee-saved prologue trimming, no scheduler, and no loop-aware pass.

So the realistic extra opportunities are not "full LLVM-style optimization passes". They are bounded x86-side peepholes and small layout heuristics:

1. byte-store composition for the ubiquitous final `micro_write_u64_le()` result store;
2. rotate/bit-twiddle idiom recognition (`rorx`/`rol`/`ror`, `blsr`);
3. arithmetic fusion to `lea`;
4. modest branch-layout / fall-through optimization;
5. small memory-encoding cleanups (`off == 0` displacement elision, `movbe` for BE-load idioms).

General constant propagation, DCE, scheduling, full register allocation, and loop unrolling are mostly absent, but they are also much worse ROI inside this JIT.

## Highest-Value Additional Opportunities

| Opportunity | What kernel does today | Concrete LLVM contrast | Benchmarks likely benefiting | Code-size impact | Exec-time impact | Complexity |
| --- | --- | --- | --- | --- | --- | --- |
| Byte-store composition | Emits each BPF store separately | LLVM frequently collapses final 8 byte stores to one `mov` | ~31/31 pure-JIT benchmarks | Moderate fixed-per-function win | Small, mostly fixed-overhead | ~80-140 LOC |
| Rotate idioms | No generic rotate recognizer in main JIT | LLVM emits `rorx` in rotate-heavy loops | ~10/31 pure-JIT benchmarks | Moderate | Small-to-moderate | ~120-220 LOC |
| `lea` arithmetic fusion | No `lea` in main BPF JIT path | LLVM uses `lea` heavily for add/scale/offset arithmetic | ~6-10/31 pure-JIT benchmarks | Small-to-moderate | Small | ~100-180 LOC |
| Branch layout / fall-through | Strict BPF block order, 1:1 `jcc` lowering | LLVM reduces branches and places fall-throughs better | ~4-5/31 pure-JIT benchmarks | Moderate on branch-heavy code | Moderate on select/search workloads | ~200-350 LOC |
| `blsr` bit-twiddle | No `blsr` pattern support | LLVM uses `blsr` in `bitcount` | 1 benchmark now | Small | Moderate for that benchmark | ~40-80 LOC |
| `movbe` BE-load fusion | No `movbe` use | LLVM uses `movbe` in `packet_parse` | 1 benchmark now | Small | Small | ~60-120 LOC |
| `off == 0` disp-elision | Intentionally leaves a disp8 byte on many memory ops | LLVM can use shorter encodings | Broad, but tiny per-site | Tiny | Tiny | ~20-40 LOC |

## A. Constant Folding / Propagation

### What the kernel JIT actually does

The kernel JIT does a few single-insn immediate peepholes:

- `emit_mov_imm32()` turns `mov reg, 0` into `xor reg, reg` and picks smaller encodings for `imm32` loads (`vendor/linux/arch/x86/net/bpf_jit_comp.c:909-947`).
- `emit_mov_imm64()` chooses `mov32` when the immediate fits (`vendor/linux/arch/x86/net/bpf_jit_comp.c:949-973`).
- ALU-immediate emission chooses `imm8` encodings and short `rax/eax` forms (`vendor/linux/arch/x86/net/bpf_jit_comp.c:1818-1864`).
- compare-with-zero is lowered to `test reg, reg` (`vendor/linux/arch/x86/net/bpf_jit_comp.c:2544-2549`).
- shift-by-1 uses the shorter `D1` form (`vendor/linux/arch/x86/net/bpf_jit_comp.c:1983-1988`).

What it does not do:

- no cross-insn constant propagation;
- no register value tracking;
- no folding of `mov imm; add imm`, `mov imm; cmp imm`, or similar adjacent sequences;
- no pattern matcher over a BPF basic block beyond the current instruction.

The evidence is structural: `do_jit()` emits one BPF instruction at a time inside the main `for` loop (`vendor/linux/arch/x86/net/bpf_jit_comp.c:1717-2787`) and keeps no per-register constant state.

### Can BPF immediates be folded across instructions?

Not in the current kernel JIT.

They could be, but only by adding a new peephole/value-tracking layer. In this benchmark suite, that is not the best use of effort because LLVM has already folded many source-level constants before the x86 backend ever runs. The remaining profitable cases are narrower x86-side idioms:

- rotate recognition from shift/or patterns;
- `blsr` from `x &= x - 1`;
- `lea` from add/scale/address arithmetic.

Representative constant-heavy workloads where limited peepholes would help:

- `large_mixed_1000` (`micro/programs/large_mixed_1000.bpf.c:17-30`, `micro/programs/large_mixed_1000.bpf.c:69-75`)
- `code_clone_8` (`micro/programs/code_clone_8.bpf.c:17-23`, `micro/programs/code_clone_8.bpf.c:41-50`)
- `fixed_loop_small` (`micro/programs/fixed_loop_small.bpf.c:32-36`)
- `fixed_loop_large` (`micro/programs/fixed_loop_large.bpf.c:32-36`)

### Assessment

- Full cross-insn constant propagation in this JIT: not present, and not a good first target.
- Limited immediate peepholes: worthwhile, but they are better discussed under section G.
- Likely benefiting benchmarks: ~4-8 pure-JIT benchmarks for limited peepholes; near-zero value for a full late JIT constant-prop pass.
- Estimated impact: code size `0-5%`, exec `0-5%` for limited peepholes.
- Complexity: ~150-250 LOC for a narrow peephole pass; `500+` LOC for anything resembling real propagation.

## B. Dead Code Elimination

### What the kernel JIT actually does

There is no general DCE pass after verification.

The only obvious "dead code" handling in `bpf_jit_comp.c` is:

- remove no-op unconditional jumps when the resolved target is the next instruction (`vendor/linux/arch/x86/net/bpf_jit_comp.c:2664-2688`);
- merge repeated `EXIT` instructions into jumps to one cleanup epilogue via `seen_exit` (`vendor/linux/arch/x86/net/bpf_jit_comp.c:2722-2748`);
- special handling for `JA -1` to stabilize passes when there are "long sequences of replaced dead code" (`vendor/linux/arch/x86/net/bpf_jit_comp.c:2647-2654`).

That is useful cleanup, but it is not general DCE over redundant ALU/MOV instructions.

### Would there be verifier-left dead instructions worth skipping?

Possibly in corner cases, but there is little evidence that this is a meaningful remaining gap in this suite. The benchmarks where LLVM wins big do not look like "kernel kept dead insns"; they look like:

- wider loads/stores;
- branchless lowering;
- better bit/arithmetic idioms.

### Assessment

- Current support: minimal and local.
- Likely benefiting benchmarks: `0-2`.
- Estimated impact: usually noise-level.
- Complexity: ~200-400 LOC if the JIT grows CFG/liveness just for DCE.
- Priority: low.

## C. Instruction Scheduling

### What the kernel JIT actually does

The kernel JIT does not reorder instructions for pipeline efficiency. It emits in BPF order:

- decode BPF insn;
- emit x86 bytes immediately into `temp`;
- copy them out and advance `addrs[]`.

See `vendor/linux/arch/x86/net/bpf_jit_comp.c:1717-2787`.

There is no post-selection scheduling window and no machine-IR stage.

### What LLVM does differently

LLVM is not just using different idioms; the resulting hot loops are also less serialized in several benchmarks:

- `bitcount`: kernel dependency-chain estimate `14` vs LLVM `6` (`micro/jit-dumps/report.md:176`)
- `fixed_loop_large`: kernel `11` vs LLVM `5` (`micro/jit-dumps/report.md:178`)
- `dep_chain_short`: kernel `13` vs LLVM `10` (`micro/jit-dumps/report.md:179`)

But the same table also shows that much of the chain-length gap is caused by specific missing idioms:

- wide loads instead of byte-recompose;
- `blsr`;
- `rorx`.

So a "scheduler pass" would not be the clean first fix.

### Assessment

- Current support: none.
- Likely benefiting benchmarks: ~4-6 (`bitcount`, `dep_chain_short`, `dep_chain_long`, `fixed_loop_large`, `code_clone_8`, maybe `large_mixed_1000`).
- Estimated impact: exec `3-8%` on those few dependency-heavy loops, code size roughly neutral.
- Complexity: `500-900+` LOC and a major design shift.
- Priority: low, behind bounded peepholes.

## D. Register Allocation

### What the kernel JIT actually does

The BPF-to-x86 mapping is fundamentally fixed:

- `reg2hex[]` hard-codes BPF registers to x86 registers (`vendor/linux/arch/x86/net/bpf_jit_comp.c:171-197`).
- There is no allocator, no remapping per basic block, and no spill-cost model.
- The only prepass is `detect_reg_usage()` for callee-saved pushes/pops (`vendor/linux/arch/x86/net/bpf_jit_comp.c:1504-1519`).

There are also local save/restore patterns because the JIT cannot ask "is this value dead now?":

- div/mod path pushes/pops `rax` and `rdx` around x86 division (`vendor/linux/arch/x86/net/bpf_jit_comp.c:1889-1944`);
- non-BMI2 variable shifts may save/restore `rcx` (`vendor/linux/arch/x86/net/bpf_jit_comp.c:2019-2045`).

### What LLVM does differently

LLVM is not performing a trivial 1:1 mapping. It will sometimes use `r12` and different save sets:

- `docs/paper.md:307-317`
- `micro/jit-dumps/report.md:145-168`

But the paper's aggregate finding is important: spill reduction is not the dominant remaining explanation (`docs/paper.md:252-262`).

### Assessment

There are two different scopes here:

1. Full register allocator in the kernel JIT:
   - possible in theory;
   - very high complexity;
   - not well justified by the measured spill gap.

2. Targeted liveness around special x86 constraints:
   - avoid some `push/pop` around div/mod and shift fallback paths when values are dead;
   - maybe use `r12` more aggressively in selected cases.

For the current suite, the second option is the only plausible one.

- Likely benefiting benchmarks: ~4-6 (`spill_pressure`, `multi_acc_8`, `multi_acc_4`, `large_mixed_500`, `large_mixed_1000`, `bpf_call_chain` if extended to the pure-JIT suite).
- Estimated impact: code size `0-5%`, exec `0-5%`.
- Complexity: ~250-500 LOC for targeted liveness; `800+` LOC for a real allocator.
- Priority: medium-low.

## E. Loop Optimizations

### What the kernel JIT actually does

Nothing loop-aware. The JIT does not:

- detect induction variables;
- unroll loops;
- hoist invariants;
- strength-reduce loop-carried arithmetic.

Back-edges are simply emitted as `jmp`/`jcc` once offsets are known (`vendor/linux/arch/x86/net/bpf_jit_comp.c:2502-2719`).

### Is this a real kernel-vs-LLVM x86 JIT gap?

Not really, at least not as a separate pass.

Both runtimes still have explicit loops in the final x86 for many cases:

- `fixed_loop_large`: kernel back-edge at `micro/jit-dumps/fixed_loop_large.kernel.asm:112-113`, LLVM back-edge at `micro/jit-dumps/fixed_loop_large.llvmbpf.asm:55-56`
- `bitcount`: kernel loop at `micro/jit-dumps/bitcount.kernel.asm:78-98`, LLVM loop at `micro/jit-dumps/bitcount.llvmbpf.asm:52-67`

LLVM's advantage inside loops mostly comes from better idioms inside the loop body, not from a separate late loop optimizer.

### Assessment

- Current support: none.
- Distinct remaining JIT opportunity: low.
- Better framing: fix loop-body idioms (`rorx`, `blsr`, wide loads/stores, branch layout) rather than add a loop optimizer.
- Priority: low.

## F. Branch Layout

### What the kernel JIT actually does

For normal BPF programs, branch lowering is strictly linear:

- compare/test is emitted;
- the BPF opcode is translated to one x86 condition;
- target offsets are resolved from `addrs[i + off]`.

See:

- conditional branches: `vendor/linux/arch/x86/net/bpf_jit_comp.c:2481-2639`
- unconditional branches: `vendor/linux/arch/x86/net/bpf_jit_comp.c:2644-2719`

There is no attempt to:

- reorder basic blocks;
- invert a condition to make the hot path fall through;
- merge adjacent branch diamonds;
- place cold blocks out of line.

The file does contain branch-target alignment for trampolines/dispatchers (`vendor/linux/arch/x86/net/bpf_jit_comp.c:3441-3453`, `vendor/linux/arch/x86/net/bpf_jit_comp.c:3637-3644`), but that is not used by the main BPF program JIT path.

### What LLVM does differently

This is visible in both the aggregate counts and the asm:

- `switch_dispatch`: kernel `136` branches vs LLVM `69` (`micro/jit-dumps/report.md:21-22`)
- `binary_search`: kernel `16` vs LLVM `13` (`micro/jit-dumps/report.md:17-18`)

In `switch_dispatch`, the kernel emits a long compare/jump/assign tree:

- compare tree start: `micro/jit-dumps/switch_dispatch.kernel.asm:76-90`
- repeated branch-to-assign structure continues throughout the function

LLVM still branches, but it also lays out more fall-through-friendly subtrees and mixes in branchless selects:

- compact compare tree start: `micro/jit-dumps/switch_dispatch.llvmbpf.asm:63-79`
- many value-selection sites use `cmove` instead of branch-to-assign

### Assessment

- Current support: none for normal BPF code.
- Likely benefiting benchmarks: ~4-5 (`switch_dispatch`, `binary_search`, `branch_layout`, `packet_parse`, `bounds_ladder`).
- Estimated impact:
  - code size: `5-20%` on branch-heavy kernels;
  - exec: `5-25%` on the best cases.
- Risk: without profile info, generic layout heuristics can hurt cases like `branch_dense`, where kernel already wins on runtime (`micro/results/pure_jit_authoritative_analysis.md:39-40`, `micro/results/pure_jit_authoritative_analysis.md:96`).
- Complexity: ~200-350 LOC for local fall-through/block inversion heuristics; more for a true block placer.
- Priority: medium.

## G. Peephole Patterns

### What the kernel JIT already has

The kernel JIT is not completely peephole-free. It already does several local x86 choices:

- `mov 0` -> `xor reg, reg` (`vendor/linux/arch/x86/net/bpf_jit_comp.c:928-938`)
- compare-zero -> `test reg, reg` (`vendor/linux/arch/x86/net/bpf_jit_comp.c:2544-2549`)
- short immediates and short jump forms (`vendor/linux/arch/x86/net/bpf_jit_comp.c:1858-1863`, `vendor/linux/arch/x86/net/bpf_jit_comp.c:2605-2633`, `vendor/linux/arch/x86/net/bpf_jit_comp.c:2690-2715`)
- BMI2 variable shifts when available (`vendor/linux/arch/x86/net/bpf_jit_comp.c:1996-2017`)

What it does not have is a multi-insn peephole engine. That is where the remaining opportunities are.

### G1. Rotate idioms -> `rorx` / `rol` / `ror`

The main JIT path does not recognize generic rotate idioms. The only rotate-related code in the file is special-purpose:

- `rol dst_reg, 32` in `insn_is_cast_user()` (`vendor/linux/arch/x86/net/bpf_jit_comp.c:1771-1773`)
- `ror %ax, 8` for 16-bit endian swap (`vendor/linux/arch/x86/net/bpf_jit_comp.c:2051-2065`)

LLVM clearly does recognize and exploit rotate idioms:

- `fixed_loop_small`: `rorx` at `micro/jit-dumps/fixed_loop_small.llvmbpf.asm:47-48`
- `fixed_loop_large`: `rorx` at `micro/jit-dumps/fixed_loop_large.llvmbpf.asm:52-56`
- `code_clone_2`: `rorx` at `micro/jit-dumps/code_clone_2.llvmbpf.asm:54-58`
- `code_clone_8`: `rorx` at `micro/jit-dumps/code_clone_8.llvmbpf.asm:60-64` and `micro/jit-dumps/code_clone_8.llvmbpf.asm:94-98`

Representative source patterns:

- `fixed_loop_small`: `micro/programs/fixed_loop_small.bpf.c:32-36`
- `fixed_loop_large`: `micro/programs/fixed_loop_large.bpf.c:32-36`
- `code_clone_2`: `micro/programs/code_clone_2.bpf.c:17-23`
- `code_clone_8`: `micro/programs/code_clone_8.bpf.c:17-23`
- `large_mixed_500`: `micro/programs/large_mixed_500.bpf.c:23-29`
- `large_mixed_1000`: `micro/programs/large_mixed_1000.bpf.c:23-29`
- `nested_loop_2`: `micro/programs/nested_loop_2.bpf.c:40-43`
- `nested_loop_3`: `micro/programs/nested_loop_3.bpf.c:43-50`
- `mixed_alu_mem`: `micro/programs/mixed_alu_mem.bpf.c:39-45`
- `bounds_check_heavy`: `micro/programs/bounds_check_heavy.bpf.c:88-91`

Assessment:

- Likely benefiting benchmarks: ~10/31 pure-JIT benchmarks.
- Estimated impact: code size `3-10%`, exec `2-10%` on rotate-heavy loops.
- Complexity: ~120-220 LOC.

### G2. `x &= x - 1` -> `blsr`

Kernel side:

- no `blsr` emission path is present in `bpf_jit_comp.c`.

LLVM side:

- `bitcount` uses `blsr` at `micro/jit-dumps/bitcount.llvmbpf.asm:60-63`.

Source pattern:

- `micro/programs/bitcount.bpf.c:17-24`

Assessment:

- Likely benefiting benchmarks: 1 (`bitcount`).
- Estimated impact: code size `2-4%` in that function, exec `5-15%` for `bitcount`.
- Complexity: ~40-80 LOC.

### G3. `mov`/`add`/scale arithmetic -> `lea`

The main BPF JIT path never emits `lea`; the only `lea` hits in `bpf_jit_comp.c` are trampoline/dispatcher code or comments, not normal BPF instruction lowering.

LLVM uses `lea` aggressively for arithmetic that the kernel leaves as multiple instructions:

- `fixed_loop_small`: `micro/jit-dumps/fixed_loop_small.llvmbpf.asm:42-44`
- `fixed_loop_large`: `micro/jit-dumps/fixed_loop_large.llvmbpf.asm:37`, `micro/jit-dumps/fixed_loop_large.llvmbpf.asm:49`
- `code_clone_2`: `micro/jit-dumps/code_clone_2.llvmbpf.asm:51-53`
- `code_clone_8`: `micro/jit-dumps/code_clone_8.llvmbpf.asm:57`, `micro/jit-dumps/code_clone_8.llvmbpf.asm:64-71`

The kernel cannot do this today because it lowers each BPF op independently:

- `MOV` handled at `vendor/linux/arch/x86/net/bpf_jit_comp.c:1755-1808`
- `ADD` handled at `vendor/linux/arch/x86/net/bpf_jit_comp.c:1739-1753` and `vendor/linux/arch/x86/net/bpf_jit_comp.c:1818-1864`
- no cross-insn fusion layer exists.

Assessment:

- Likely benefiting benchmarks: ~6-10 (`fixed_loop_small`, `fixed_loop_large`, `code_clone_2`, `code_clone_8`, `large_mixed_500`, `large_mixed_1000`, maybe `dep_chain_short`, `dep_chain_long`).
- Estimated impact: code size `2-6%`, exec `1-5%`.
- Complexity: ~100-180 LOC.

## H. Memory Access Patterns Beyond Byte-Recompose

### H1. Byte-store composition

This is the strongest additional opportunity not already called out in the paper.

Current kernel behavior:

- each store is emitted independently by `emit_stx()` / `emit_st_index()` (`vendor/linux/arch/x86/net/bpf_jit_comp.c:1196-1285`);
- store opcodes in the main switch are handled per BPF insn (`vendor/linux/arch/x86/net/bpf_jit_comp.c:2112-2148`).

Workload pattern:

- `micro_write_u64_le()` writes the result byte-by-byte (`micro/programs/common.h:58-63`);
- every staged/packet-backed benchmark macro uses that helper (`micro/programs/common.h:74-146`).

Asm evidence:

- kernel, `fixed_loop_large`: 8 byte stores at `micro/jit-dumps/fixed_loop_large.kernel.asm:121-139`
- LLVM, `fixed_loop_large`: single 64-bit store at `micro/jit-dumps/fixed_loop_large.llvmbpf.asm:57-61`
- kernel, `branch_layout`: 8 byte stores at `micro/jit-dumps/branch_layout.kernel.asm:105-125`
- LLVM, `branch_layout`: single 64-bit store at `micro/jit-dumps/branch_layout.llvmbpf.asm:53-55`

Aggregate evidence:

- direct non-stack stores: kernel `176` vs LLVM `30` across the dump subset (`micro/jit-dumps/report.md:82-107`)

This is the store-side analogue of byte-recompose. It is less important for runtime because it happens once at function exit, but it is a real, repeated code-size gap.

Assessment:

- Likely benefiting benchmarks: ~31/31 pure-JIT benchmarks.
- Estimated impact:
  - code size: about `-6` to `-7` x86 store instructions per function, often `-10` to `-30` bytes;
  - exec: usually `<3%`, but more visible on tiny baselines where fixed overhead dominates.
- Complexity: ~80-140 LOC.
- Priority: high for code size, medium for runtime.

### H2. `off == 0` displacement elision

The source explicitly calls out a missed optimization:

- `emit_insn_suffix()` comment: "If off == 0 we could skip this and save one extra byte" (`vendor/linux/arch/x86/net/bpf_jit_comp.c:1029-1034`)

Today the JIT chooses a disp8 form even for zero displacement in many cases.

Assessment:

- Likely benefiting benchmarks: broad, especially pointer-at-base accesses.
- Estimated impact: tiny but free-ish, `-1` byte per qualifying memory op.
- Complexity: ~20-40 LOC.
- Priority: low-medium because it is cheap.

### H3. Big-endian load fusion -> `movbe`

Current kernel behavior:

- endian conversion exists only through `BPF_END` lowering (`vendor/linux/arch/x86/net/bpf_jit_comp.c:2049-2105`);
- there is no `movbe` use in the main JIT path.

LLVM evidence:

- `packet_parse` uses `movbe` at `micro/jit-dumps/packet_parse.llvmbpf.asm:52`, `micro/jit-dumps/packet_parse.llvmbpf.asm:56`, `micro/jit-dumps/packet_parse.llvmbpf.asm:58`

Kernel contrast:

- `packet_parse` reconstructs the same fields through byte loads/shifts/ors at `micro/jit-dumps/packet_parse.kernel.asm:87-104` and `micro/jit-dumps/packet_parse.kernel.asm:151-163`

Source pattern:

- `micro/programs/packet_parse.bpf.c:44-47`

Assessment:

- Likely benefiting benchmarks: 1 current benchmark (`packet_parse`).
- Estimated impact: code size `2-5%` there, exec `1-5%`.
- Complexity: ~60-120 LOC.
- Priority: medium-low unless more BE-heavy workloads are added.

## Priority Ranking

If the goal is "extra opportunities beyond the 3 already identified" with good ROI inside `arch/x86/net/bpf_jit_comp.c`, I would prioritize them like this:

1. **Byte-store composition**
   - new, real, broad, and easy to localize;
   - best extra code-size win not already in the paper.

2. **Rotate/bit-twiddle peepholes (`rorx`/`rol`/`ror`, `blsr`)**
   - very concrete LLVM-vs-kernel difference;
   - clearly visible in asm;
   - meaningful on several hot loops.

3. **`lea` arithmetic fusion**
   - smaller than rotate support, but broad and cheap.

4. **Branch layout / fall-through heuristics**
   - real gap, but riskier and more heuristic-sensitive.

5. **Zero-displacement and `movbe` cleanups**
   - worthwhile polish, but smaller wins.

I would **not** prioritize, inside this JIT, a fresh implementation of:

- full constant propagation,
- full DCE,
- a machine scheduler,
- full register allocation,
- loop unrolling/hoisting.

Those are either mostly LLVM-mid-end work already, or they would turn this file into a small compiler backend rather than a JIT emitter.

## Bottom Line by Category

| Category | Does kernel JIT do it today? | Additional opportunity? | Recommendation |
| --- | --- | --- | --- |
| Constant folding / propagation | Only local immediate peepholes | Narrow peepholes only | Do not build full const-prop here |
| Dead code elimination | Only nop-jump and repeated-exit cleanup | Very little | Low priority |
| Instruction scheduling | No | Possible but expensive | Low priority |
| Register allocation | Fixed 1:1 mapping, no allocator | Limited liveness around special ops | Medium-low priority |
| Loop optimizations | No | Not a distinct remaining JIT gap | Low priority |
| Branch layout | No | Yes, for 4-5 branch-heavy workloads | Medium priority |
| Peephole patterns | Some single-insn ones | Yes, especially rotate/`blsr`/`lea` | High priority |
| Memory access patterns beyond byte-recompose | Partial only | Yes: byte-store composition, `movbe`, zero-disp | High priority for store composition |
