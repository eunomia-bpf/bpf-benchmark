# Auto-Research Framework Feedback Terminology Analysis

## Overview

This document analyzes how auto-research frameworks and LLM-driven optimization benchmarks describe their feedback mechanisms, comparing them with traditional benchmarks. The goal is to find suitable terminology for describing multi-layer compilation pipeline feedback like "verifier logs, JIT output, and runtime counters."

---

## Per-Paper Analysis

### 1. GSO (Global Software Optimization) - UC Berkeley 2024

**Feedback Description:**
- Uses "**performance test as a precise specification**" - the test itself serves as feedback
- "**Execution-based evaluation**" - runtime results validate optimization
- Agent receives "codebase, performance tests, and a target optimization" as input

**Feedback Components:**
- Performance test results (runtime measurements)
- Correctness checks (functional equivalence)
- Build success/failure

**Key Terminology:**
- "**Precise specification**" (vs ambiguous natural language specs in SWE-bench)
- "**OPT@K metric**" - measures whether optimization achieves human-level performance

**Distinction from Traditional Benchmarks:**
- Traditional: static input/output pairs
- GSO: dynamic execution environment with measurable performance delta

---

### 2. KernelBench - Stanford 2025

**Feedback Description:**
- "**Execution results and profiler feedback**" fed back to LM iteratively
- "**Ground-truth signals**" from the compilation/execution environment
- "**Rich signals**" including compiler errors, correctness checks, runtime profiling

**Explicit Feedback Categories (Figure 5):**
1. **Compiler feedback (G)** - NVCC compile issues
2. **Execution feedback (E)** - output mismatch, correctness checks
3. **Profiler feedback (P)** - PyTorch profiler timing breakdown, wall-clock time

**Key Terminology:**
- "**Iterative refinement with execution feedback**"
- "**Environment feedback**" - encompasses compiler + execution + profiler
- "**Programmatic verification**" of generated kernels
- "**Test-time feedback**"

**Findings:**
- With G+E+P feedback, fast_1 improves from 12% to 43% (DeepSeek-R1, Level 2)
- "Leveraging execution feedback helps reduce errors and improves overall speedups over time"

---

### 3. SWE-bench - Princeton/Stanford 2024

**Feedback Description:**
- Uses "**execution-based evaluation**" via unit tests
- "**Fail-to-pass tests**" as success criterion
- Limited explicit feedback loop - primarily one-shot generation

**Key Terminology:**
- "**Robust evaluation**" through test execution
- "**Execution-based filtering**" during benchmark construction

**Note:** SWE-bench is primarily an evaluation benchmark, not an iterative optimization framework. Feedback is implicit (pass/fail tests) rather than structured multi-layer signals.

---

### 4. AI Scientist v2 - Sakana AI 2025

**Feedback Description:**
- "**VLM (Vision-Language Model) feedback loop**" for figure quality
- "**Experiment progress manager**" tracks success/failure at each stage
- Nodes marked as "**buggy**" vs "**non-buggy**" based on execution outcomes

**Feedback Components per Node:**
- Experiment script
- High-level plan description
- Execution error trace (if applicable)
- Performance metrics (training/validation)
- Visualization script + generated figures
- VLM feedback on figures
- Final status (buggy/non-buggy)

**Key Terminology:**
- "**Agentic tree search**" with execution-guided node selection
- "**Structured feedback**" from execution environment
- "**Experimental outputs**" saved to numpy files
- "**Best-first search**" guided by performance metrics

---

### 5. PIE (Performance-Improving Edits) - UPenn/CMU/Google 2024

**Feedback Description:**
- Uses "**gem5 simulator**" for deterministic performance measurement
- "**Execution time annotations**" from full system simulation
- Feedback is primarily offline (training data) rather than online iterative

**Key Terminology:**
- "**Execution time**" as ground truth
- "**Performance-conditioned generation**" - tags indicate target performance level
- "**Reliable performance annotations**" via deterministic simulation

**Distinction:** PIE focuses on learning from historical performance data rather than iterative online feedback.

---

### 6. ComPilot (Compiler Pilot) - NYU Abu Dhabi 2025

**Feedback Description:**
- "**Closed-loop interaction**" between LLM and compiler
- "**Compiler-generated feedback**" on each transformation attempt
- "**Feedback Generator**" submodule constructs structured feedback messages

**Five Explicit Feedback Categories:**
1. **Invalid Schedule** - syntactically/semantically invalid transformation
2. **Illegal Schedule** - violates data dependencies (legality check)
3. **Solver Failure** - Tiramisu solver cannot find valid parameters
4. **Compiler Crash** - transformation causes compiler error
5. **Successful Execution** - includes measured speedup/slowdown ratio

**Key Terminology:**
- "**Optimization dialogue**" - conversation history as episodic memory
- "**Feedback messages**" / "**Observations**" (from environment)
- "**Action-Observation exchange**"
- "**Concrete feedback**" from execution
- "**Ground-truth empirical feedback**"
- "**Validity, legality, and performance impact**"

**Design Pattern:**
```
LLM proposes --> Compiler validates --> Feedback generated --> LLM refines
```

**Key Finding (RQ6):**
- "With Feedback" achieves ~23% higher speedup than "Without Feedback" at T=30
- Feedback enables in-context learning from mistakes and successes

---

### 7. AwareCompiler - CAS/NTU 2025

**Feedback Description:**
- "**Multi-turn agent-environment interaction**"
- "**Outcome-based composite reward function**"
- Uses "**optimization effect**" as feedback signal

**Feedback/Reward Components:**
1. **Format Reward** - valid reasoning/tool-call/answer structure
2. **Answer Reward** - compilation test, schema/protocol validation
3. **Performance Reward** - code size reduction measurement

**Key Terminology:**
- "**Agent-environment interaction**"
- "**Optimization effect**" = status + improvement percentage
- "**Tool response**" as intermediate feedback
- "**Context-aware**" feedback grounding

---

### 8. Shypula 2024 (Agentic Auto-Scheduling / ComPilot)

(Same paper as ComPilot above - covered in detail there)

---

### 9. GPU Kernel Scientist - ICML ES-FoMo 2025

**Feedback Description:**
- "**Benchmark timings**" as the only evaluation signal
- "**Black-box timing results**" correlated with code changes
- LLM must infer performance impact from before/after benchmarks

**Key Terminology:**
- "**Performance feedback**" from benchmark platform
- "**Iterative refinement as a discovery process**"
- "**End-to-end timing**" as primary signal

**Limitation noted:** "Having access to fine-grained feedback from profilers would give the GPU Kernel Scientist system a significant boost in capability"

---

## Summary: Terminology Patterns

### Common Terms for Multi-Layer Feedback

| Term | Papers Using It | Description |
|------|-----------------|-------------|
| **Execution feedback** | KernelBench, ComPilot | Runtime results, correctness checks |
| **Compiler feedback** | KernelBench, ComPilot, AwareCompiler | Compile errors, warnings, legality checks |
| **Profiler feedback** | KernelBench, GPU Kernel Scientist | Timing breakdown, performance counters |
| **Environment feedback** | KernelBench, AwareCompiler | Umbrella term for all execution-side signals |
| **Ground-truth signals** | KernelBench, ComPilot | Empirically measured outcomes |
| **Observations** | ComPilot | Agent receives as part of action-observation loop |
| **Structured feedback** | AI Scientist v2, ComPilot | Organized, machine-readable feedback format |

### Established Patterns

1. **"Closed-loop feedback"** (ComPilot) - emphasizes iterative nature
2. **"Concrete feedback"** (ComPilot) - vs abstract/heuristic guidance
3. **"Empirical feedback"** (ComPilot) - measured from actual execution
4. **"Rich signals"** (KernelBench) - multi-dimensional feedback
5. **"Action-Observation exchange"** (ComPilot) - RL-style framing

### Hierarchy of Feedback Layers

Based on the papers, a typical multi-layer feedback stack includes:

1. **Static Analysis Layer**: Syntax errors, type errors, semantic checks
2. **Compilation Layer**: Compiler warnings, legality checks, IR-level feedback
3. **Verification Layer**: Correctness proofs, dependency analysis, formal checks
4. **Execution Layer**: Runtime errors, functional correctness tests
5. **Performance Layer**: Timing, profiler data, hardware counters

---

## Recommended Terminology for BPFOptBench

For describing "verifier logs, JIT output, and runtime counters" in the eBPF context:

### Option A: "Multi-Stage Pipeline Feedback"
- Emphasizes the sequential stages of the compilation pipeline
- Parallels ComPilot's "validity, legality, and performance impact"

### Option B: "Layered Execution Feedback" 
- Emphasizes the hierarchical nature
- Combines KernelBench's "execution feedback" with multi-layer concept

### Option C: "Full-Stack Compilation Signals"
- Emphasizes completeness of feedback from source to runtime
- Novel but descriptive

### Option D: "Compiler-Verifier-Runtime Feedback" (Recommended)
- Most explicit about the three specific layers
- Parallels KernelBench's "Compiler feedback (G), Execution feedback (E), Profiler feedback (P)"

### Mapping to eBPF:

| Generic Term | eBPF Equivalent |
|--------------|-----------------|
| Compiler feedback | Verifier logs (reject reason, bounds info, state tracking) |
| IR/JIT feedback | JIT output (native code size, register allocation) |
| Profiler/Runtime feedback | Runtime counters (run_cnt, run_time_ns, perf events) |

### Suggested Phrasing for Paper

**Formal:**
> "BPFOptBench provides **multi-stage compilation pipeline feedback** encompassing verifier diagnostics, JIT transformation logs, and runtime performance counters."

**Alternative:**
> "Unlike benchmarks that provide only pass/fail signals, BPFOptBench exposes **rich, layered feedback** from the eBPF verifier (safety constraints and program state), JIT compiler (native code generation details), and kernel runtime (execution counts and timing)."

**Comparison to Related Work:**
> "Similar to KernelBench's **execution and profiler feedback** but specialized for kernel-space programs, BPFOptBench captures feedback at three distinct pipeline stages: verification, compilation, and execution."

---

## Key Differentiators of Auto-Research Frameworks vs Traditional Benchmarks

| Aspect | Traditional Benchmark | Auto-Research Framework |
|--------|----------------------|------------------------|
| Feedback | Binary pass/fail | Multi-layer, structured signals |
| Iteration | One-shot evaluation | Iterative refinement loop |
| Oracle | Ground truth labels | Execution environment |
| Guidance | None (just score) | Actionable error messages |
| Granularity | Task-level | Stage-level (compile, verify, run) |

### Core Characteristic
The defining feature of auto-research frameworks is **closed-loop interaction with execution environments** where each stage provides actionable, structured feedback enabling iterative improvement.

---

## Conclusion

The most widely used and well-established terminology for multi-layer compilation feedback is:

1. **"Execution feedback"** - for runtime signals (KernelBench, ComPilot)
2. **"Compiler feedback"** - for compilation-stage signals (KernelBench, ComPilot)  
3. **"Ground-truth signals"** / **"Empirical feedback"** - for measured outcomes

For BPFOptBench, recommend framing as:
- "**Multi-stage pipeline feedback**" (umbrella term)
- Decomposed as: **verifier feedback** (safety analysis), **JIT feedback** (code generation), **runtime feedback** (performance counters)

This aligns with established terminology while being specific to the eBPF domain.
