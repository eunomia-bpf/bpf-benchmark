# BPF bytecode -> LLVM IR -> optimize -> BPF bytecode: feasibility study

Date: 2026-03-07

Question: can we take a BPF ELF, lift it with `llvmbpf`, run LLVM optimizations, lower it back to BPF bytecode, and still pass the Linux verifier?

## Executive verdict

Short answer: **yes for a constrained MVP, no for `llvmbpf`'s current IR without additional engineering**.

What is feasible now:

- A **single-function**, **no-maps**, **no-helper-calls**, **no-local-calls** round-trip is technically feasible. LLVM's BPF backend exists, lowers ordinary LLVM IR to BPF, and the local toolchain emits valid BPF ELF/object code.
- A demo that proves "lift -> optimize -> lower -> verifier accepts" for a simple packet/scalar program is realistic.

What is **not** feasible as a direct pipe today:

- `llvmbpf`'s current lift is designed for **native JIT/AOT**, not for reconstructing verifier-safe BPF. The biggest blocker is that local BPF-to-BPF calls are encoded as a synthetic call stack plus `indirectbr` in one LLVM function (`vendor/llvmbpf/src/compiler.cpp:233-247`, `307-352`, `1043-1097`). Stock LLVM BPF backend aborts on `indirectbr`.
- Map and helper semantics are not preserved in a round-trippable form. `llvmbpf` resolves many `LDDW` pseudos to concrete pointers or helper calls during lifting (`vendor/llvmbpf/src/compiler.cpp:824-1005`), which is fine for host execution but loses the kernel-facing `BPF_PSEUDO_MAP_*` / `BPF_PSEUDO_FUNC` encoding needed in BPF bytecode (`vendor/libbpf/include/uapi/linux/bpf.h:1343-1380`).

My bottom-line assessment:

- **Constrained prototype:** feasible in days.
- **Useful verifier-safe prototype for simple real programs:** feasible in ~500-1000 LOC.
- **General BPF ELF -> LLVM IR -> BPF ELF round-trip for arbitrary real-world programs:** feasible in principle, but requires redesigning parts of the lifter rather than just wiring `llc -march=bpf` behind the current IR dump path.

## 1. What `llvmbpf` lifts today

### Public API and existing IR emission

- The public VM API is in `vendor/llvmbpf/include/llvmbpf.hpp`. Relevant entry points are `load_code`, `compile`, `do_aot_compile`, `set_lddw_helpers`, and `set_optimization_level` (`vendor/llvmbpf/include/llvmbpf.hpp:45-99`).
- `llvmbpf` already has a CLI path that emits the lifted LLVM IR: `bpftime-vm build <obj> -emit-llvm` (`vendor/llvmbpf/cli/main.cpp:29-38`, `75-122`; `vendor/llvmbpf/README.md:88-106`).
- Internally the lift happens in `llvm_bpf_jit_context::generateModule(...)` declared in `vendor/llvmbpf/src/llvm_jit_context.hpp:42-47` and defined in `vendor/llvmbpf/src/compiler.cpp`.

### Register and stack model

`llvmbpf` models BPF state in a very direct but host-oriented way:

- It allocates **11 LLVM stack slots** for `r0`..`r10` (`vendor/llvmbpf/src/compiler.cpp:203-207`).
- It allocates one large stack object sized as `STACK_SIZE * MAX_LOCAL_FUNC_DEPTH + 10`, computes `stackEnd`, and stores that into `r10` (`vendor/llvmbpf/src/compiler.cpp:208-231`).
- The JIT entry signature is `i64 bpf_main(ptr mem, i64 mem_len)` and those two incoming parameters are written into `r1` and `r2` (`vendor/llvmbpf/src/compiler.cpp:248-257`; public typedef in `vendor/llvmbpf/include/llvmbpf.hpp:30-32`).

This matches the eBPF ABI closely enough for execution, but it is not yet a canonical BPF-codegen IR.

### Control flow

- Basic blocks are split directly from bytecode jump targets (`vendor/llvmbpf/src/compiler.cpp:148-168`, `263-289`).
- Jump destinations are resolved with helpers in `vendor/llvmbpf/src/compiler_utils.cpp:197-260`.
- Conditional branches are emitted via `CreateCondBr` in `emitCondJmpWithDstAndSrc(...)` (`vendor/llvmbpf/src/compiler_utils.cpp:291-305`).

### ALU, loads/stores, and 32-bit semantics

- ALU source/destination loading is handled in `emitLoadALUSource`, `emitLoadALUDest`, `emitStoreALUResult` (`vendor/llvmbpf/src/compiler_utils.cpp:5-57`).
- The important 32-bit rule is preserved: 32-bit ALU results are zero-extended back into 64-bit registers (`vendor/llvmbpf/src/compiler_utils.cpp:45-57`), matching kernel ABI docs (`vendor/linux/Documentation/bpf/classic_vs_extended.rst:35-40`).
- Memory loads/stores are lowered through explicit pointer arithmetic and typed `load`/`store` IR (`vendor/llvmbpf/src/compiler_utils.cpp:136-164`, `263-289`).

### Helper calls

- Helper symbol names are synthesized as `_bpf_helper_ext_%04u` by `ext_func_sym()` (`vendor/llvmbpf/src/compiler_utils.hpp:39-43`).
- `emitExtFuncCall(...)` turns a BPF helper call into an LLVM call with five `i64` arguments taken from `r1`..`r5`, and stores the result into `r0` (`vendor/llvmbpf/src/compiler_utils.cpp:308-345`).

This is a major semantic mismatch for round-trip: LLVM now sees a normal external function call, not a kernel helper ID.

### Maps and `LDDW` pseudos

The `LDDW` handling is where `llvmbpf` most clearly optimizes for execution rather than re-emission:

- Helper names for map/code/var resolution are defined in `vendor/llvmbpf/src/llvm_jit_context.hpp:23-27`.
- `vendor/llvmbpf/src/compiler.cpp:783-1017` handles all `LDDW` pseudos:
  - `src == 1`: map-by-fd
  - `src == 2`: map-by-fd plus map-value offset
  - `src == 3`: variable address
  - `src == 4`: code address
  - `src == 5`: map-by-index
  - `src == 6`: map-by-index plus map-value offset
- In several of these cases, the lifter immediately turns the pseudo into a **host pointer constant** or a runtime helper call (`vendor/llvmbpf/src/compiler.cpp:829-905`, `935-1005`).

That means the original BPF relocation semantics are often **lost during lifting**.

### Local BPF-to-BPF calls

This is the hardest blocker:

- `llvmbpf` does **not** preserve subprograms as separate LLVM functions.
- Instead it allocates a synthetic `callStack` and `callItemCnt` (`vendor/llvmbpf/src/compiler.cpp:233-247`), saves `r6-r9`, shifts `r10`, and branches into the callee block on call (`vendor/llvmbpf/src/compiler.cpp:1047-1097`).
- Returns are implemented through a synthetic `localFuncReturnBlock` that restores state and then executes `CreateIndirectBr(targetAddr)` (`vendor/llvmbpf/src/compiler.cpp:307-352`).

That is fine for host execution, but it is not how BPF subprograms are represented, and it is not lowerable by stock LLVM BPF backend in my experiments.

## 2. What LLVM's BPF backend can lower

### The backend exists and is production-grade

- Both local toolchains expose BPF targets: `/usr/bin/llc` is LLVM **18.1.3**, and `/usr/bin/llc-20` is LLVM **20.1.8**.
- Both register `bpf`, `bpfel`, and `bpfeb`.
- `llvmbpf` itself currently optimizes via generic `PassBuilder` in `optimizeModule(...)` (`vendor/llvmbpf/src/llvm_jit_context.cpp:200-284`) and emits **host-native** AOT objects by setting the target triple to the default host triple in `do_aot_compile(...)` (`vendor/llvmbpf/src/llvm_jit_context.cpp:421-480`). It does **not** currently have a BPF AOT path.

### BPF-specific optimization passes that matter

LLVM's BPF target adds verifier-aware passes. In LLVM 20.1.8 source:

- `BPFTargetMachine::registerPassBuilderCallbacks()` injects:
  - `BPFPreserveStaticOffsetPass`
  - `BPFAbstractMemberAccessPass`
  - `BPFPreserveDITypePass`
  - `BPFIRPeepholePass`
  - `SimplifyCFGPass`
  - `BPFASpaceCastSimplifyPass`
  - `BPFAdjustOptPass`
  (`tmp/llvm20-bpf-src/BPFTargetMachine.cpp:120-142`)
- Codegen also adds `createBPFCheckAndAdjustIR()`, the instruction selector, `BPFMIPeephole`, and pre-emit checking/peepholes (`tmp/llvm20-bpf-src/BPFTargetMachine.cpp:145-183`).

These target-specific passes are important because generic LLVM optimization is not verifier-aware.

Two especially relevant backend passes:

- `BPFAdjustOpt.cpp` explicitly says its job is to "make the code more kernel verifier friendly" and works around verifier-hostile `InstCombine` transforms (`tmp/llvm20-bpf-src/BPFAdjustOpt.cpp:1-10`, `83-90`).
- `BPFPreserveStaticOffset.cpp` documents that `SimplifyCFG`, `InstCombine`, and `GVN` can break verifier-required `getelementptr` + `load/store` adjacency, and that the pass exists to preserve static offsets for verifier-rewritten context accesses (`tmp/llvm20-bpf-src/BPFPreserveStaticOffset.cpp:13-64`).

Important implication: if we optimize lifted IR with a **generic** pass pipeline, we can create IR that lowers but then fails verifier checks. A correct round-trip tool should build the optimizer with a **BPF `TargetMachine`**, not with `PassBuilder(nullptr, ...)` as `llvmbpf` currently does (`vendor/llvmbpf/src/llvm_jit_context.cpp:241-268`).

### Backend legality/ABI limits

LLVM BPF backend has hard limits that a round-trip tool must respect:

- `BPFStackSizeOption` defaults to **512 bytes** (`tmp/llvm20-bpf-src/BPFRegisterInfo.cpp:29-32`), matching kernel `MAX_BPF_STACK` (`vendor/linux/include/linux/filter.h:98-99`).
- `R10` is the read-only frame pointer and `R11` is a pseudo stack pointer in backend internals (`tmp/llvm20-bpf-src/BPFRegisterInfo.cpp:53-57`).
- Only `CallingConv::C` and `Fast` are supported; **stack arguments**, **variadic functions**, and **aggregate returns** are rejected (`tmp/llvm20-bpf-src/BPFISelLowering.cpp:324-399`).
- `MaxArgs = 5` (`tmp/llvm20-bpf-src/BPFISelLowering.cpp:402`).
- Tail-call optimization is disabled in normal LLVM-call lowering (`tmp/llvm20-bpf-src/BPFISelLowering.cpp:419-452`).
- Dynamic stack allocation is rejected (`tmp/llvm20-bpf-src/BPFISelLowering.cpp:664-669`).
- Signed division is rejected unless using CPU features that support it (`tmp/llvm20-bpf-src/BPFISelLowering.cpp:657-661`; CPU feature table in `tmp/llvm20-bpf-src/BPFSubtarget.cpp:78-94`).
- `-mcpu=v3` enables `alu32`, while `v4` adds more ISA features (`tmp/llvm20-bpf-src/BPFSubtarget.cpp:78-94`; also `vendor/linux/Documentation/bpf/clang-notes.rst:13-16`, `20-36`).

### Empirical lowering results

I ran local lowering experiments with both LLVM 18.1.3 and LLVM 20.1.8. The behavior matched on the key cases.

1. **Plain lifted-style IR lowers cleanly to BPF.**

- A simple `define i64 @bpf_main(ptr %ctx, i64 %len)` function lowered to ordinary BPF assembly with `r1`, `r2`, a conditional branch, and a byte load.

2. **Internal LLVM function calls lower to real BPF subprogram calls.**

- `internal.ll` with `caller()` calling internal `callee()` produced a direct BPF `call -0x4` and no relocation.
- This is good news: if the lifter preserved BPF subprograms as separate LLVM functions, the backend can emit BPF-to-BPF calls correctly.

3. **External LLVM calls become ordinary call relocations, not helper IDs.**

- `helper.ll` with `declare i64 @helper(...)` produced:
  - `call -0x1`
  - relocation `R_BPF_64_32 helper`
- This is **not** the kernel helper ABI. A post-pass or custom lowering is required to rewrite such calls into `imm = helper_id`, `src_reg = 0`.

4. **External globals become `R_BPF_64_64` relocations.**

- A `ptrtoint @glob` test lowered to `ld_imm64` plus relocation `R_BPF_64_64 glob`.
- That means the backend can preserve symbolic addresses, but `llvmbpf` currently does not preserve maps that way.

5. **`indirectbr` is a hard blocker.**

- On both LLVM 18.1.3 and LLVM 20.1.8, `llc -march=bpf -mcpu=v3` aborts on:
  - `LLVM ERROR: Cannot select: ... brind ...`
  - failing in `BPF DAG->DAG Pattern Instruction Selection`
- I also checked `-mcpu=v4`; it still aborts.

This directly blocks `llvmbpf`'s current local-call encoding.

## 3. Verifier and ABI constraints that can break the round-trip

### Verifier model

The verifier tracks control flow, register types, and stack initialization:

- The user docs describe a CFG pass followed by symbolic execution over all paths (`vendor/linux/Documentation/bpf/verifier.rst:6-15`).
- After helper calls, `R1-R5` become unreadable while `R6-R9` are preserved (`vendor/linux/Documentation/bpf/verifier.rst:32-35`).
- Loads/stores require valid pointer-typed bases such as `PTR_TO_CTX`, `PTR_TO_MAP`, or `PTR_TO_STACK` (`vendor/linux/Documentation/bpf/verifier.rst:47-57`).
- Stack accesses must stay within `[-MAX_BPF_STACK, 0)`, and reads require prior initialization (`vendor/linux/Documentation/bpf/verifier.rst:71-87`).

Kernel verifier internals say the same thing more concretely:

- Register roles and pointer-type reasoning are documented at the top of `kernel/bpf/verifier.c` (`vendor/linux/kernel/bpf/verifier.c:56-120`).
- Combined stack depth is capped at `MAX_BPF_STACK` (`vendor/linux/kernel/bpf/verifier.c:6760-6783`).
- `BPF_CALL` reserved-field checks distinguish helper, pseudo-call, and kfunc call forms (`vendor/linux/kernel/bpf/verifier.c:21098-21130`).

### Loops and back-edges

There is a subtle documentation split:

- `vendor/linux/Documentation/bpf/verifier.rst:8-10` still says the first pass does DAG checking and disallows loops.
- Newer verifier code in `kernel/bpf/verifier.c` special-cases some back-edges when `env->bpf_capable` is set (`vendor/linux/kernel/bpf/verifier.c:18244-18250`) and has explicit infinite-loop detection in state pruning (`vendor/linux/kernel/bpf/verifier.c:20561-20573`).

Practical conclusion: a round-trip tool should **not** assume arbitrary LLVM loop transforms are verifier-safe. For an MVP, keep loops simple, bounded, and preferably avoid introducing new loop structure.

## 4. Key technical blockers

| Blocker | Evidence | Why it breaks round-trip | MVP workaround |
|---|---|---|---|
| Local BPF-to-BPF calls are lowered as `indirectbr`-based state machine | `vendor/llvmbpf/src/compiler.cpp:233-247`, `307-352`, `1047-1097` | LLVM BPF backend crashes on `indirectbr`; current lifted IR cannot be lowered back | Restrict MVP to single-function programs; later lift each subprogram as a separate LLVM function |
| Helper IDs are lost | `vendor/llvmbpf/src/compiler_utils.hpp:39-43`, `vendor/llvmbpf/src/compiler_utils.cpp:308-345` | External LLVM calls lower to `R_BPF_64_32 symbol`, not helper ID encoding | Post-process helper symbols into helper IDs; better: use a dedicated intrinsic/metadata |
| Map pseudo-instructions are concretized too early | `vendor/llvmbpf/src/compiler.cpp:824-1005` | `BPF_PSEUDO_MAP_FD` / `BPF_PSEUDO_MAP_VALUE` semantics are lost and replaced by host pointers or helper calls | Restrict MVP to no maps; later preserve maps as globals/relocations instead of concrete addresses |
| Generic `-O3` is not verifier-aware | `vendor/llvmbpf/src/llvm_jit_context.cpp:241-268` vs `tmp/llvm20-bpf-src/BPFTargetMachine.cpp:120-149` | Generic passes can separate GEP+load/store or trigger verifier-hostile canonicalizations | Optimize with a BPF `TargetMachine`, or run a curated pass list |
| Stack blow-up | Kernel `MAX_BPF_STACK=512` at `vendor/linux/include/linux/filter.h:98-99`; backend limit at `tmp/llvm20-bpf-src/BPFRegisterInfo.cpp:29-32`, `60-79` | LLVM spills or large allocas can make verifier reject | Restrict passes; reject oversized stack at compile time; start with tiny scalar programs |
| Unsupported IR constructs | backend rejects dynamic alloca and signed div (`tmp/llvm20-bpf-src/BPFISelLowering.cpp:657-669`) | Optimizer may introduce IR patterns backend cannot lower | Ban or canonicalize them before codegen |
| Calling convention mismatches | `tmp/llvm20-bpf-src/BPFISelLowering.cpp:324-399`, `402`, `419-452` | >5 args, stack args, varargs, aggregate returns are invalid for BPF backend | Keep lifted ABI extremely simple; do not invent helper wrappers that violate BPF CC |

## 5. Does this round-trip already exist anywhere?

I did **not** find an existing open-source tool or paper that does the exact pipeline:

> arbitrary BPF ELF -> lift to LLVM IR -> optimize -> lower back to verifier-safe BPF ELF/bytecode

What exists today:

- **`llvmbpf`**: BPF bytecode -> LLVM IR -> host native code. It already exposes the lift, but not BPF re-emission.
- **LLVM/Clang BPF backend**: LLVM IR -> BPF bytecode/object. This solves the lowering half.
- **!XDP (SOSP 2023)**: a published system that also lifts eBPF bytecode to LLVM IR for optimization/AOT, but the target is native execution, not round-trip back to BPF.
- **Merlin (ASPLOS 2024)**: operates on LLVM IR with customized LLVM passes and then applies an additional eBPF bytecode refinement pass before verification. This is close in spirit, but it is **not** a BPF-bytecode lifter round-trip.
- **K2 (SIGCOMM 2021)**: BPF bytecode -> BPF bytecode optimizer/synthesizer; no LLVM lifting.
- **EPSO (recent superoptimizer work)**: BPF bytecode -> BPF bytecode superoptimization; again no LLVM lifting.

So the exact round-trip appears to be **missing**, but the necessary pieces exist separately.

## 6. Minimal prototype: fastest path to a working demo

### Recommendation

Do **not** start from "arbitrary BPF ELF". Start from a deliberately restricted class:

- one program
- one function
- no maps
- no helpers
- no tail calls
- no local BPF-to-BPF calls
- no atomics

That is enough to prove the architecture.

### Implementation sketch

1. **Input.**

- Reuse existing ELF loading if you want ELF front-end convenience.
- The repo already has a strong ELF relocator in `micro/runner/src/elf_program_loader.cpp` that:
  - appends referenced executable sections (`273-356`)
  - rewrites map relocations to `BPF_PSEUDO_MAP_FD` (`466-475`)
  - rewrites local-call relocations to `BPF_PSEUDO_CALL` (`478-499`)
  - rewrites subprogram-address relocations for `ldimm64` (`502-518`)
- For the strict MVP you can avoid most of that complexity and simply feed `bpf_program__insns()` to `llvmbpf` like the CLI already does (`vendor/llvmbpf/cli/main.cpp:79-109`).

2. **Lift.**

- Reuse `llvm_bpf_jit_context::generateModule(...)`.
- Expose a new API that returns a `ThreadSafeModule` or serialized IR instead of immediately JITing/AOTing to host.

3. **Optimize.**

- Do **not** use the existing host-oriented `optimizeModule(...)` unchanged.
- Build a BPF `TargetMachine` for `bpfel` + `-mcpu=v3` and pass it into `PassBuilder` so the BPF target callbacks run (`tmp/llvm20-bpf-src/BPFTargetMachine.cpp:120-149`).
- For the first demo, I would start with either:
  - `-O1`, or
  - a custom pass list centered on `InstCombine`, `SimplifyCFG`, DCE, and constant propagation.

4. **Lower.**

- Add a new AOT path parallel to `do_aot_compile(...)`, but set:
  - triple to `bpfel`
  - CPU to `v3`
  - BPF target machine instead of host target machine
- Emit ELF object exactly as current AOT already does for host code (`vendor/llvmbpf/src/llvm_jit_context.cpp:421-480`), but with BPF target instead of host.

5. **Verify.**

- Add a tiny libbpf harness or shell out to `bpftool prog load`.
- Success criterion is not just "object produced"; it is "kernel verifier accepted it".

### LOC estimate

Rough, but concrete:

- 80-150 LOC: expose lifted module/IR without going through host AOT path
- 100-180 LOC: add `emit-bpf` / `generate_bpf_object()` path with BPF target machine
- 80-150 LOC: small verifier harness via libbpf or `bpftool`
- 150-300 LOC: helper-symbol rewrite into helper IDs
- 150-300 LOC: preserve map relocations instead of materializing addresses
- 200-400 LOC: redesign local-call lifting into separate LLVM functions

Total estimates:

- **Toy MVP (single-function, no maps/helpers): ~150-250 LOC**
- **Usable simple prototype (helpers + verifier harness): ~350-600 LOC**
- **General useful prototype (maps + local calls + reloc preservation): ~700-1200 LOC**

## 7. Expected benefit based on current benchmark data

The repo's current authoritative result is:

- `llvmbpf/kernel` exec-time geomean = **0.849x** (`docs/micro-bench-status.md:491-493`)
- `llvmbpf/kernel` native code-size geomean = **0.496x** (`docs/micro-bench-status.md:491-493`)

But that number is **not** a direct upper bound on what BPF-bytecode optimization can recover before kernel JIT.

Why not:

- Part of `llvmbpf`'s advantage is from **host-native** instruction selection and register allocation. The benchmark summary explicitly calls out x86-specific wins such as `cmov` and BMI instructions (`docs/micro-bench-status.md:493`).
- Those wins do **not** survive lowering back into BPF bytecode, because BPF ISA cannot encode x86-specific `cmov`/BMI patterns directly.

What is likely to survive:

- Your pass-ablation result says only two LLVM passes consistently matter on these BPF-scale programs:
  - `InstCombinePass`
  - `SimplifyCFGPass`
  (`docs/paper.md:370-381`)
- The same section says the rest of the tested passes had essentially zero median code-size effect (`docs/paper.md:374-381`).

So the likely benefit split is:

- **Code size:** meaningful upside, because `InstCombine` and `SimplifyCFG` can remove redundant scalar operations and dead/unreachable CFG structure before kernel JIT sees the bytecode.
- **Exec time:** probably smaller upside than code-size, because the kernel JIT still controls final native scheduling, register assignment, and microarchitectural instruction selection.

My concrete expectation:

- A round-trip optimizer could plausibly recover a **useful fraction of the code-size gap** on branchy/scalar single-function programs.
- It is **unlikely** to recover the full `0.849x` exec-time advantage, because much of that comes after BPF bytecode lowering.
- The first passes worth betting on are exactly the ones your data already isolated: `InstCombine` and `SimplifyCFG`.
- I would avoid aggressive loop transforms in the first version even if they occasionally help, because verifier complexity and bounded-loop behavior make them much riskier than straight-line simplification.

## 8. Recommended go/no-go

### Go, if the goal is:

- a paper/demo artifact showing that LLVM IR can be used as an **intermediate optimizer for existing BPF bytecode**
- a restricted proof-of-concept on single-function programs
- a foundation for later bytecode-level optimization work

### No-go, if the goal is:

- "take arbitrary real-world BPF ELF today and transparently improve it by piping current `llvmbpf` IR through `opt -O3 | llc -march=bpf`"

That direct plan will fail on:

- local subprogram calls
- map pseudo-instructions
- helper ABI preservation
- verifier-sensitive optimization interactions

## 9. Final recommendation

The fastest serious path is:

1. add a **BPF-target AOT emission path** to `llvmbpf`
2. restrict the first demo to **single-function / no-map / no-helper** programs
3. optimize with a **BPF-targeted** pass pipeline, not generic host `-O3`
4. prove verifier acceptance with a tiny libbpf loader
5. only then add helper/map relocation preservation
6. treat local BPF-to-BPF calls as a **second phase** that requires preserving subprogram structure as separate LLVM functions

If the question is "is the round-trip fundamentally possible?", the answer is **yes**.

If the question is "can we do it by reusing current `llvmbpf` IR exactly as-is?", the answer is **no**.
