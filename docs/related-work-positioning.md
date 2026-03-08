# Related Work Positioning Analysis

This benchmark study is best positioned as a native-code-generation analysis of eBPF JIT backends. It does not replace bytecode-level superoptimization or application-level performance studies; it isolates a different layer of the stack and measures the code-quality consequences of that layer directly.

## 1. Optimization-Layer Taxonomy

| System | Layer | Operates on | Constraint | Key result |
|--------|-------|-------------|------------|------------|
| K2 (SIGCOMM'21) | Bytecode synthesis | BPF bytecode | verifier-constrained | 6-26% code-size reduction, 1.36-55.03% latency reduction |
| Merlin (ASPLOS'24) | Multi-layer | LLVM IR + BPF bytecode | verifier-constrained | Faster than K2 and more scalable |
| EPSO (ASE'25) | Bytecode rewriting | BPF bytecode | verifier-constrained | 795 rewrite rules; up to 68.87% bytecode size reduction; 6.60% average runtime reduction |
| KFuse (EuroSys'22) | In-kernel fusion | BPF programs | kernel-internal | Replaces indirect tail-call-style transfers with direct jumps; up to 2.3x on real applications |
| This work | JIT backend | Native x86-64 code | none at optimization time in userspace | 0.849x execution-time geomean and 0.496x native code-size ratio on 31 authoritative pure-JIT microbenchmarks |

The main distinction is layer placement. K2, Merlin, and EPSO transform verifier-visible program representations before JIT compilation. KFuse transforms relationships among already-validated programs inside the kernel. This work compares the final native code emitted by two JIT backends for the same BPF ELF inputs.

## 2. Orthogonality Argument

Bytecode-level optimizers and a native-code-level JIT comparison are complementary rather than substitutive. K2, Merlin, and EPSO act before JIT compilation, so their search space is limited to verifier-safe BPF bytecode rewrites. By contrast, llvmbpf changes the lowering decisions made during JIT compilation itself: direct wide loads instead of byte recompose, branch restructuring with `cmov`, and liveness-aware callee-saved handling.

That separation means the optimizations can in principle stack: Merlin-optimized bytecode can still be passed to llvmbpf, which can then optimize the resulting x86-64 machine code further. Our data show why this backend layer matters. On the 31 authoritative pure-JIT benchmarks, llvmbpf reaches `0.496x` native code size and `0.849x` execution time overall, with the largest gains in `control-flow` (`0.627x` exec geomean) and `memory-local` (`0.665x`) categories. Those are precisely the cases where native lowering choices dominate, and they are not fully visible to bytecode-only tools.

The JIT-dump analysis also identifies backend-only opportunities that bytecode rewriting does not directly expose: byte-load recomposition accounts for `50.7%` of the kernel instruction surplus, extra branch structure for `19.9%`, and fixed prologue/epilogue saves for `18.5%`. The weak correlation between code size and runtime (`Pearson r = 0.131`) further suggests that what matters is not only producing smaller verifier-safe bytecode, but also how the backend places or removes work on the dynamic critical path.

## 3. Empirical Study Differentiation

Most nearby empirical studies measure eBPF applications, runtimes, or system interaction effects rather than native code quality. BeeBox is the closest JIT-adjacent system in the research notes, but it is a security-hardening effort rather than a benchmarking study.

| Study | Focus | Our differentiation |
|-------|-------|-------------------|
| CoNEXT'25 "Demystifying eBPF" | Network-application performance, chaining, and tail-call overhead | We compare JIT backends on identical ELF inputs and analyze code generation, not application-level network behavior |
| "No Two Snowflakes Are Alike" | Cross-library performance, fidelity, and resource-use comparison | We go deeper on code quality by inspecting emitted x86-64, JIT dumps, and backend-specific mechanisms |
| ETH Zurich multicore study | Scalability, multicore resource use, and interference | We focus on single-core code-generation quality and matched backend comparison rather than concurrency effects |
| BeeBox (Sec'24) | Security hardening by modifying the JIT compiler | It is not a performance-characterization study and does not compare native code quality across JIT backends |

The closest empirical contribution of this work is therefore methodological: it treats eBPF JIT quality itself as the object of study. The evidence is not only timing-based; it connects timing to emitted instruction structure and then checks whether the same direction survives on real programs.

## 4. Key Claims We Can Make

1. This is a strong candidate for the first systematic native-code-level comparison of the Linux kernel eBPF JIT and a userspace LLVM-based JIT on identical BPF ELF inputs.
2. The measured native code-size reduction is large: `0.496x` on the 31 authoritative microbenchmarks, with a consistent external code-size advantage of `0.618x` across `162` paired real-program instances (`36` unique). Relative to K2's reported `6-26%` bytecode shrinkage, the backend-only headroom is clearly substantial, while remaining a different layer and metric.
3. The study identifies three concrete kernel JIT improvement opportunities tied to observed machine code: byte recompose, lack of `cmov`-style branchless lowering, and unconditional callee-saved register saves.
4. The execution result is not a synthetic one-off: llvmbpf wins `21/31` authoritative pure-JIT benchmarks, achieves a `0.849x` execution-time geomean (95% CI `[0.834, 0.865]`), and the valid-packet rerun yields a `0.514x` geomean across `98` paired runnable real-program instances.
5. The evaluation has real-program contact: the paired validation corpus is drawn from production-oriented sources including Cilium and libbpf-bootstrap, not only hand-written microbenchmarks.

## 5. Gap Acknowledgment

- This is not a superoptimizer or synthesis system; it does not search for optimal BPF programs the way K2 or EPSO do.
- It does not analyze verifier precision, verifier cost, or verifier acceptance behavior.
- It does not perform multi-program fusion or tail-call-chain elimination in the style of KFuse.
- The evaluation is single-platform today: x86-64 on Arrow Lake-S only.
- The microbenchmark suite is intentionally mechanism-oriented rather than corpus-representative, so end-to-end workload claims remain bounded.
