# Safety ≠ Correctness 分离原则：相关工作调研

**日期**: 2026-03-24
**目的**: 调研是否有其他论文/系统将 safety 和 correctness 的分离作为核心 insight 或设计原则，评估 BpfReJIT Insight 3 的 novelty。

---

## 1. BpfReJIT 的 Insight 回顾

BpfReJIT 的 Insight 3 核心主张：

> **Safety ≠ Correctness — 与内核 eBPF 安全模型对齐**
> - 内核组件保证 safety：verifier 验证新 bytecode，和 BPF_PROG_LOAD 完全相同的安全保证
> - 用户态 daemon 负责 correctness：编译变换保持程序语义
> - 如果 daemon 有 bug，程序行为可能改变，但内核安全不受影响（fail-safe）
> - 这种分离之所以可能，是因为 BPF 有强制性的 verifier

关键创新点：**将编译优化框架的 safety guarantee 和 correctness guarantee 分到不同信任域，利用已有 verifier 作为 safety backstop，让 correctness 可以在用户态自由迭代。**

---

## 2. 相关工作分析

### 2.1 BPF/eBPF 领域

#### K2 (SIGCOMM 2021)
- **论文**: "Synthesizing Safe and Efficient Kernel Extensions for Packet Processing", Xu et al., SIGCOMM 2021
- **Safety vs Correctness 讨论**: K2 明确区分了 safety checking（程序不违反内核 checker 约束）和 equivalence checking（优化后的程序语义等价）。K2 内部同时实现了两者：用 first-order logic 做等价检验，用 kernel checker 做安全检验。还有 post-processing pass 把输出程序加载到内核，用 kernel checker 过滤不安全的程序。
- **与 BpfReJIT 异同**: K2 是离线超优化器，safety 和 correctness 都在用户态完成（用自己的 formal checker）。**K2 不依赖内核 verifier 作为 safety backstop**——它自己模拟 verifier 的规则。最终加载到 kernel 是一个最终检查，不是核心信任机制。BpfReJIT 的关键区别是：safety 完全委托给内核 verifier（不在用户态重新实现），correctness 完全在用户态。
- **Novelty 威胁**: 低。K2 虽然分开了 safety check 和 equivalence check，但这是同一个系统内部的两个步骤，不是跨信任域的架构分离。

#### Merlin (ASPLOS 2024)
- **论文**: "Merlin: Multi-tier Optimization of eBPF Code for Performance and Compactness", Zhai et al., ASPLOS 2024
- **Safety vs Correctness 讨论**: Merlin 在 verifier 之前优化 BPF 字节码，所有优化后的程序必须通过 kernel verification。但 Merlin 不讨论 safety/correctness 分离——它假设优化是正确的，然后用 verifier 确认安全性。
- **与 BpfReJIT 异同**: Merlin 是 load-time 静态优化，不涉及运行时 recompilation。它没有跨信任域的设计。
- **Novelty 威胁**: 低。

#### EPSO (ASE 2025)
- **论文**: "EPSO: A Caching-Based Efficient Superoptimizer for BPF Bytecode", ASE 2025
- **Safety vs Correctness 讨论**: 类似 K2，EPSO 在用户态做超优化，用自己的 equivalence checking 保证 correctness，用 kernel verifier 做最终安全检查。
- **Novelty 威胁**: 低。离线超优化，不涉及运行时框架。

#### ePass (eBPF Foundation 2025)
- **论文**: "ePass: Verifier-Cooperative Runtime Enforcement for eBPF"
- **Safety vs Correctness 讨论**: ePass 是**内核态** LLVM-like 编译框架。它的设计是 verifier-cooperative：所有变换在内核态完成，变换后的程序重新经过 verifier。ePass 的 trust model 是整个系统都在内核态，verifier 是同一信任域内的 safety checker。
- **与 BpfReJIT 异同**: ePass 把优化和验证都放在内核态，不涉及信任域分离。BpfReJIT 的核心差异是把 correctness-critical 的编译优化移到用户态，实现跨信任域分离。
- **Novelty 威胁**: 中低。ePass 是最接近 BpfReJIT 的工作，但它的设计选择恰好与 BpfReJIT 相反——把一切放在内核态。BpfReJIT 可以论证为什么 ePass 的选择有局限性（内核态不适合复杂优化）。

#### BCF (SOSP/OSDI area)
- **论文**: "Prove It to the Kernel: Precise Extension Analysis via Proof-Guided Abstraction Refinement"
- **Safety vs Correctness 讨论**: BCF 用用户态的 reasoning 生成 proof/certificate，然后在内核态做 proof checking。这是 proof-carrying code 模式在 eBPF 的应用。Safety 由 proof checker 保证，correctness 由用户态的 prover 负责。
- **与 BpfReJIT 异同**: BCF 确实有某种程度的 safety/correctness 分离——proof generation 在用户态（可以有 bug，但内核 checker 会拒绝无效 proof），proof checking 在内核态保证 safety。但 BCF 的目标是让程序通过 verifier（扩展 expressiveness），不是优化。
- **Novelty 威胁**: 中。BCF 的 proof-carrying 模式与 BpfReJIT 的 "untrusted optimizer + trusted verifier" 模式有哲学上的相似性。但应用场景完全不同（verification precision vs runtime optimization）。

#### BeePL (PriSC 2025)
- **论文**: "BeePL: Correct-by-compilation kernel extensions"
- **Safety vs Correctness 讨论**: BeePL 是基于 CompCert 的 verified compilation，目标是同时保证 safety 和 correctness。它不分离两者——而是用 verified compiler 同时保证两者。
- **Novelty 威胁**: 低。BeePL 是相反的哲学：把一切验证到底，而非分离。

#### AEE (USENIX Security 2025)
- **论文**: "Approximation Enforced Execution of Untrusted Linux Kernel Extensions"
- **Safety vs Correctness 讨论**: AEE 的核心 insight 是把 verifier 拆分为 "复杂的状态近似"（不可信）和 "简单的安全检查"（可信），然后在运行时 enforce 近似。**这是一种 safety/trust-reduction 策略**，但不是 safety/correctness 分离——AEE 关注的是 verifier 自身的 bug tolerance，不是编译优化的正确性。
- **与 BpfReJIT 异同**: AEE 减少 verifier 的 TCB，BpfReJIT 利用 verifier 作为 safety backstop。两者的信任模型不同但互补。
- **Novelty 威胁**: 低。完全不同的问题。

#### Moat (USENIX Security 2024) / SafeBPF (CCSW 2024)
- **Safety vs Correctness 讨论**: Moat 和 SafeBPF 用硬件隔离（MPK/MTE）提供 defense-in-depth，在 verifier 之外增加一层 safety 保障。它们假设 verifier 可能有 bug，所以加硬件保护。
- **Novelty 威胁**: 低。这些是 defense-in-depth 方案，不涉及编译优化。

#### VEP (NSDI 2025)
- **论文**: "VEP: A Two-stage Verification Toolchain for Full eBPF Programmability"
- **Safety vs Correctness 讨论**: VEP 用两阶段验证——source-level verification (VEP-C) 和 bytecode-level proof checking (VEP-eBPF)。用户态 prover 是不可信的，内核态 checker 是可信的。这是 proof-carrying code 在 eBPF 验证的实例。
- **与 BpfReJIT 异同**: VEP 的 "用户态不可信 prover + 内核态可信 checker" 模式与 BpfReJIT 的 "用户态不可信 optimizer + 内核态可信 verifier" 有结构性相似。但 VEP 是为了验证程序安全性，BpfReJIT 是为了运行时优化。
- **Novelty 威胁**: 中。信任模式相似，但应用完全不同。

#### Rex/Rax (ATC 2025)
- **论文**: "Rex: Closing the language-verifier gap with safe and usable kernel extensions"
- **Safety vs Correctness 讨论**: Rex 用 trusted compiler（Rust 编译器）替代 in-kernel verifier。Safety 由编译器保证，correctness 由程序员保证。这是 "trusted compiler" 模式，与 BpfReJIT 的 "untrusted optimizer + trusted verifier" 模式恰好相反。
- **Novelty 威胁**: 低。设计哲学不同。

---

### 2.2 JIT 编译器验证

#### Jitterbug (OSDI 2020)
- **论文**: "Specification and verification in the field: Applying formal methods to BPF just-in-time compilers in the Linux kernel", Nelson et al., OSDI 2020
- **Safety vs Correctness 讨论**: Jitterbug 形式化验证 JIT 编译器的 correctness（每条 BPF 指令翻译成的机器指令语义等价）。它不区分 safety 和 correctness——verification 同时覆盖两者。
- **Novelty 威胁**: 低。Jitterbug 是 verified JIT，不涉及分离设计。

#### Jitk (OSDI 2014)
- **论文**: "Jitk: A Trustworthy In-Kernel Interpreter Infrastructure", Wang et al.
- **Safety vs Correctness 讨论**: 类似 Jitterbug，用 Coq 验证 JIT correctness。不讨论分离。
- **Novelty 威胁**: 低。

---

### 2.3 Verified Compilers

#### CompCert
- **论文**: "Formal verification of a realistic compiler", Leroy, CACM 2009
- **Safety vs Correctness 讨论**: CompCert 的 correctness theorem 保证：编译后代码的所有可观测行为都是源代码允许的行为。这意味着源代码级别验证的 safety properties 自动保持到二进制。**CompCert 不区分 safety 和 correctness**——correctness 隐含了 safety preservation。CompCert 的 TCB 分析（Monniaux 2022）详细讨论了哪些组件需要信任，但这是 TCB 最小化，不是 safety/correctness 分离。
- **Novelty 威胁**: 低。哲学不同——CompCert 追求全验证，BpfReJIT 利用已有 verifier 做分离。

#### CakeML
- **论文**: "CakeML: A Verified Implementation of ML", Kumar et al., POPL 2014
- **Safety vs Correctness 讨论**: 类似 CompCert，全验证路线。通过消除 unverified 组件来最小化 TCB。
- **Novelty 威胁**: 低。

#### Vellvm
- **论文**: "Vellvm: Verified LLVM", Zhao et al., POPL 2012
- **Safety vs Correctness 讨论**: 类似 CompCert，形式化 LLVM IR 语义并验证优化 pass 的正确性。
- **Novelty 威胁**: 低。

---

### 2.4 Translation Validation 和 Result Checking

#### Translation Validation (Necula, PLDI 2000)
- **论文**: "Translation Validation for an Optimizing Compiler", Pnueli et al. / Necula
- **Safety vs Correctness 讨论**: Translation validation 的核心思想是：**不验证编译器，验证编译结果**。每次编译后，用一个（简单的）validator 检查输出是否是输入的正确翻译。这与 BpfReJIT 有哲学相似性——validator 是可信的，compiler 是不可信的。
- **与 BpfReJIT 异同**: Translation validation 关注的是 **correctness** validation，不是 safety。在 translation validation 中，如果 validator 通过了，那么编译是正确的；如果没通过，编译被拒绝。BpfReJIT 中，verifier 保证的是 safety（不会崩溃/提权），不保证 correctness（语义不变）。**这是关键区别**。
- **Novelty 威胁**: 中高。Translation validation 是 "untrusted compiler + trusted validator" 的经典模式。BpfReJIT 可以被视为这个模式的一个实例。但 **BpfReJIT 的 validator (verifier) 只检查 safety 而不检查 correctness，这是一个重要的新维度**。

#### Alive2 (PLDI 2021)
- **论文**: "Alive2: Bounded Translation Validation for LLVM", Lopes et al.
- **Safety vs Correctness 讨论**: Alive2 验证 LLVM pass 的 correctness（refinement relation），但不区分 safety 和 correctness。
- **Novelty 威胁**: 低。

#### Program Checking (Blum & Kannan, 1989/1995)
- **论文**: "Designing programs that check their work", Blum & Kannan, JACM 1995
- **Safety vs Correctness 讨论**: 经典的 result checking 思想——用简单的 checker 验证复杂程序的输出。这是 "untrusted program + trusted checker" 模式的理论基础。
- **与 BpfReJIT 异同**: BpfReJIT 的 verifier 可以被视为一种 result checker，但它检查的是 safety properties 而非 functional correctness。
- **Novelty 威胁**: 低（太 general）。

#### Certifying Compilation
- **Safety vs Correctness 讨论**: Certifying compiler 生成代码和 certificate，client 端用简单的 checker 验证 certificate。"程序 safety 可以被建立，即使是在未知机器上用未知编译器编译并通过不可信网络传输的。" 这与 BpfReJIT 的模式非常相似——optimizer 不可信，但 safety 由 checker (verifier) 保证。
- **Novelty 威胁**: 中。哲学上相似，但 certifying compilation 检查的是具体 properties（通常包括 correctness），而 BpfReJIT 的 verifier 只检查 safety。

---

### 2.5 Proof-Carrying Code

#### PCC (Necula & Lee, OSDI 1996)
- **论文**: "Safe Kernel Extensions Without Run-Time Checking", Necula & Lee, OSDI 1996
- **Safety vs Correctness 讨论**: **PCC 是最接近 BpfReJIT 哲学的经典工作。** PCC 的核心思想是：untrusted code producer 生成代码和 safety proof，trusted kernel checker 验证 proof。如果 proof 通过，代码保证满足 safety policy。**PCC 明确区分了 safety（由 checker 保证）和 functional correctness（不保证）。** 引用原文："proof-carrying code is tamperproof; tampering goes undetected only if the resulting code is still guaranteed to respect the safety policy"。
- **与 BpfReJIT 异同**:
  - **相同点**: (1) 不可信的 code producer / optimizer；(2) 可信的 kernel-side safety checker；(3) safety 和 correctness 是分离的——safety 由 checker 保证，correctness 是 producer 的责任；(4) fail-safe 设计：即使 producer 有 bug，安全不受影响。
  - **不同点**: (1) PCC 是在 load-time 做 one-shot verification，BpfReJIT 是在 runtime 做 continuous recompilation；(2) PCC 需要 producer 生成 proof，BpfReJIT 利用已有的 BPF verifier（不需要新的 proof format）；(3) PCC 的 safety checker 是新设计的 proof checker，BpfReJIT 复用了内核已有的 BPF verifier infrastructure。
- **Novelty 威胁**: **高**。PCC 的 safety/correctness 分离思想与 BpfReJIT 高度一致。**BpfReJIT 需要明确 acknowledge PCC 作为哲学上的 precursor。**

---

### 2.6 Software Fault Isolation (SFI) 和 WebAssembly

#### NaCl / SFI
- **论文**: "Native Client: A Sandbox for Portable, Untrusted x86 Native Code", Yee et al., S&P 2009
- **Safety vs Correctness 讨论**: NaCl 用 SFI 保证 sandbox safety（内存隔离）。编译器生成的代码可能有 correctness bug，但 sandbox safety 由 binary verifier 保证。**NaCl 明确分离了 sandbox safety（由 verifier 保证）和 functional correctness（不保证）。**
- **与 BpfReJIT 异同**: NaCl 的 "untrusted compiler + trusted binary verifier" 模式与 BpfReJIT 非常相似。区别在于 NaCl 验证的是 SFI properties（内存隔离），BpfReJIT 验证的是 BPF safety properties。
- **Novelty 威胁**: **中高**。NaCl 是 SFI 领域的经典 safety/correctness 分离实例。

#### VeriWasm (NDSS 2021)
- **论文**: "Доверяй, но проверяй: SFI safety for native-compiled Wasm", Johnson et al., NDSS 2021
- **Safety vs Correctness 讨论**: **VeriWasm 最明确地阐述了 safety/correctness 分离。** VeriWasm 是 Wasm 编译输出的 SFI verifier——它验证编译后的 native code 是否满足 sandbox safety properties，**而不关心编译是否语义正确**。即使 Cranelift 有 miscompilation bug，VeriWasm 保证 sandbox 不会被突破。
- **与 BpfReJIT 异同**:
  - **相同点**: (1) untrusted compiler + trusted safety verifier；(2) safety 检查独立于 correctness；(3) compiler bug 只影响 correctness 不影响 safety。
  - **不同点**: (1) VeriWasm 是 post-compilation 验证，BpfReJIT 复用已有的 load-time verifier；(2) VeriWasm 验证 SFI properties，BpfReJIT 验证 BPF safety properties；(3) VeriWasm 的 compiler 不是有意 untrusted——它是为了 defense-in-depth 而增加验证层。BpfReJIT 是有意设计成 untrusted optimizer + trusted verifier 的架构。
- **Novelty 威胁**: **中高**。VeriWasm 明确实现了 safety/correctness 分离，但它的目标是 defense-in-depth（假设编译器可能有 bug），不是有意将优化逻辑放到不可信域。

#### Wasmtime/Cranelift
- **Safety vs Correctness 讨论**: Wasmtime 团队明确承认 "compiler bugs can break sandbox safety"。他们的解决方案是多层防御：fuzzing + VeriWasm + ISLE 验证。但在 Wasmtime 中，**compiler bug 可以导致 sandbox escape**——这正是他们需要 VeriWasm 的原因。**BPF 的关键区别是 verifier 在 JIT 之前运行，所以 JIT bug 可能突破安全，但 verifier bug 是更根本的问题。BpfReJIT 把优化移到 verifier 之前，让 verifier 始终是 safety backstop。**
- **Novelty 威胁**: 中。Wasmtime 讨论了 safety/correctness 关系，但没有像 BpfReJIT 这样有意利用这种分离作为架构原则。

---

### 2.7 操作系统安全

#### SPIN (SOSP 1995)
- **论文**: "Extensibility, Safety and Performance in the SPIN Operating System", Bershad et al., SOSP 1995
- **Safety vs Correctness 讨论**: SPIN 用 Modula-3 type safety 保证 kernel extension 的 safety（pointer safety, 不能伪造 capability）。但 type safety 不保证 functional correctness——extension 可能有 logic bug 但不会破坏内核安全。
- **与 BpfReJIT 异同**: SPIN 的 "type safety ≠ functional correctness" 与 BpfReJIT 的 "BPF safety ≠ optimization correctness" 在哲学上一致。但 SPIN 的 safety 由语言机制保证，BpfReJIT 由运行时 verifier 保证。
- **Novelty 威胁**: 中。SPIN 是可扩展内核 safety 的经典先驱，但没有涉及编译优化。

#### seL4 (SOSP 2009)
- **论文**: "seL4: Formal Verification of an OS Kernel", Klein et al., SOSP 2009
- **Safety vs Correctness 讨论**: seL4 追求全功能正确性验证（functional correctness implies safety）。不区分 safety 和 correctness——correctness proof 涵盖一切。
- **Novelty 威胁**: 低。

#### Singularity (Microsoft Research, 2005)
- **论文**: "An Overview of the Singularity Project", Hunt & Larus, MSR-TR-2005-135
- **Safety vs Correctness 讨论**: Singularity 用 type safety + software isolation 保证进程隔离。Safety 由 verifier 在 load-time 检查（verification of MSIL bytecode），correctness 是程序员的责任。
- **与 BpfReJIT 异同**: Singularity 的 "verified type safety ≠ functional correctness" 与 BpfReJIT 类似，但 Singularity 不涉及 dynamic recompilation/optimization。
- **Novelty 威胁**: 低。

#### Linux Livepatch
- **Safety vs Correctness 讨论**: Livepatch 的安全模型关注 consistency（确保在 safe point 切换到新代码），但 **不验证 patch 的 safety 或 correctness**。文档明确指出 "it isn't possible for kpatch-build to verify the safety of patches"。Livepatch 信任 patch author 提供安全且正确的代码。
- **与 BpfReJIT 异同**: **Livepatch 是反面例子**——它没有 verifier，所以无法做 safety/correctness 分离。BpfReJIT 的论点正是：因为 BPF 有 verifier，所以可以做这种分离——而 livepatch 等没有 verifier 的系统不行。
- **Novelty 威胁**: 无（是 BpfReJIT 的 motivation）。

---

### 2.8 The Correctness-Security Gap

#### D'Silva et al. (SPW 2015)
- **论文**: "The Correctness-Security Gap in Compiler Optimization", D'Silva, Payer, Song, IEEE SPW 2015
- **Safety vs Correctness 讨论**: **这篇论文最直接地讨论了 correctness 和 safety (security) 的 gap。** 核心观点：一个正确的（semantics-preserving）编译器优化可能违反安全保证。例如 dead store elimination 消除 memset 清零操作，在语义上是正确的（dead store），但在安全上泄露了敏感数据。
- **与 BpfReJIT 异同**: D'Silva 的 "correctness-security gap" 与 BpfReJIT 的 insight 方向相反。D'Silva 说的是：correctness ≠ safety（正确的编译可能不安全）。BpfReJIT 说的是：safety（verifier 保证的属性）不需要 correctness（优化正确性）——verifier 独立于优化是否正确来保证 safety。
- **Novelty 威胁**: 低。方向相反但互为补充。BpfReJIT 应该 cite 这篇作为 "correctness 和 safety 关系" 的讨论。

---

### 2.9 Safety/Liveness 分离（理论基础）

#### Lamport (1977), Alpern & Schneider (1985)
- **论文**: "Defining Liveness", Alpern & Schneider; "Recognizing Safety and Liveness", Alpern & Schneider, 1987
- **Safety vs Correctness 讨论**: 经典的 safety/liveness 分解：safety property = "bad things don't happen", liveness property = "good things do happen"。任何 correctness property 都可以分解为 safety 和 liveness 的 conjunction。
- **与 BpfReJIT 异同**: BpfReJIT 的 "safety" 是操作系统安全意义上的 safety（不崩溃/不提权），不是 Lamport 意义上的 temporal logic safety property。名词相同但含义不同。不过，BpfReJIT 可以引用这个理论来说明 "safety 和 correctness 的分离是有理论基础的"。
- **Novelty 威胁**: 无（太 general，不同语义）。

---

## 3. 综合分析

### 3.1 哪些工作最接近 BpfReJIT 的 insight？

按威胁程度排序：

| 工作 | 年份 | 关键相似性 | 威胁等级 |
|------|------|-----------|---------|
| **PCC** (Necula) | 1996 | untrusted producer + trusted kernel checker, safety ≠ correctness | **高** |
| **VeriWasm** | 2021 | untrusted compiler + trusted safety verifier, 明确 safety/correctness 分离 | **中高** |
| **NaCl/SFI** | 2009 | untrusted compiler + trusted binary verifier for sandbox safety | **中高** |
| **Translation Validation** | 2000 | untrusted compiler + trusted validator 模式 | **中** |
| **VEP** | 2025 | 用户态不可信 prover + 内核态可信 checker | **中** |
| **BCF** | ~2024 | 用户态 proof generation + 内核态 proof checking | **中** |
| **SPIN** | 1995 | type safety ≠ functional correctness for kernel extensions | **中** |
| **Certifying Compilation** | ~2000 | untrusted compiler + trusted certificate checker | **中** |

### 3.2 BpfReJIT 的独特组合

尽管以上工作都涉及 safety/correctness 分离的某些方面，BpfReJIT 的独特之处在于以下**组合**：

1. **复用已有 verifier**：PCC/VeriWasm 需要设计新的 proof format 或 verifier。BpfReJIT 完全复用已有的 BPF_PROG_LOAD 路径，零新增信任代码。

2. **运行时持续重编译**：PCC/NaCl/Translation Validation 都是 one-shot（load-time 或 compile-time）。BpfReJIT 允许运行时反复修改和重新验证程序，同时保持 safety invariant。

3. **有意的架构分离**：VeriWasm 是 defense-in-depth（假设编译器可能有 bug），NaCl 是沙箱隔离。BpfReJIT 是 **有意设计** 成 "不可信用户态 optimizer + 可信内核 verifier" 的架构，这种分离是 **设计原则**（不是 defense-in-depth），使得用户态可以自由迭代复杂的编译优化而不影响内核安全。

4. **BPF 生态系统的独特属性**：BPF verifier 是强制性的（所有 BPF 程序必须通过），已经过大量工程投入和安全审计，且有清晰的 safety 语义。这使得 BpfReJIT 的 safety backstop 比 PCC 或 SFI 的 checker 更加成熟和可信。

5. **Fail-safe with degraded correctness**：如果 daemon 有 bug，程序可能行为不正确但仍然安全。这种 graceful degradation 在 PCC/NaCl 中也存在（unsafe code 被拒绝），但 BpfReJIT 的 "通过验证但可能不正确" 的 failure mode 更加独特——verifier 通过意味着安全但不意味着等价。

### 3.3 与最近 eBPF 安全研究的关系

2024-2025 年 eBPF 安全研究的趋势是：
- **减少对 verifier 的依赖**：Rex 用 trusted compiler 替代 verifier，AEE 减少 verifier 的 TCB
- **增强 verifier**：ePass 做 verifier-cooperative 变换，VEP 做两阶段验证
- **补充 verifier**：Moat/SafeBPF 加硬件隔离

BpfReJIT 的定位是：**利用 verifier（不是减少/替代/增强它），在其 safety 保证之上构建不可信的优化框架**。这在当前 eBPF 安全研究图谱中是独特的。

---

## 4. Novelty 判断

### 4.1 BpfReJIT 的 safety/correctness 分离是否 novel？

**判断：不是完全 novel 的哲学思想，但是这个思想在内核 eBPF 动态优化中的首次系统化实例。**

- **哲学层面**："untrusted code producer + trusted safety checker" 是 PCC (1996) 的核心思想，已有 30 年历史。
- **SFI 层面**：NaCl 和 VeriWasm 已经在 sandbox 场景实现了类似的 safety/correctness 分离。
- **BPF 层面**：K2、Merlin、EPSO 等都利用了 kernel verifier 做最终安全检查，但它们是离线/load-time 工具，不是运行时框架。
- **BpfReJIT 的创新**：首次将 PCC/SFI 式的 safety/correctness 分离原则应用到 **内核 eBPF 动态重编译框架**，复用已有 BPF verifier 作为 safety backstop，实现了运行时持续优化与内核安全的解耦。

### 4.2 论文应该怎么定位这个 insight？

**推荐定位**：

> "While the principle of separating safety guarantees from correctness guarantees through trusted verification of untrusted code has roots in proof-carrying code [Necula 1996] and software fault isolation [Wahbe 1993, Yee 2009], BpfReJIT is the first system to apply this principle to dynamic, post-deployment recompilation of kernel eBPF programs. Unlike prior systems that require designing new proof formats (PCC) or binary validators (NaCl, VeriWasm), BpfReJIT leverages the existing BPF verifier—the same mandatory safety check that all BPF programs must pass—as its safety backstop. This reuse of existing infrastructure is enabled by BpfReJIT's design of submitting optimized programs through the standard BPF_PROG_LOAD path, requiring zero new trusted code for safety enforcement."

具体建议：
1. **明确 acknowledge** PCC 和 SFI 作为哲学先驱（Related Work 中详细讨论）
2. **强调差异化**：复用已有 verifier（vs 新建 checker）、运行时持续重编译（vs one-shot）、有意的架构分离（vs defense-in-depth）
3. **不要 claim** "首次提出 safety/correctness 分离"——而是 claim "首次在内核 eBPF 动态优化中系统化应用这一原则"
4. **用 livepatch 作为反例**：说明为什么这种分离在 BPF 中可行但在 livepatch 等系统中不可行（因为 BPF 有 verifier）

---

## 5. 推荐引用列表

以下是论文中应该引用的关键相关工作（按 relevance 排序）：

### 必须引用
1. Necula & Lee, "Safe Kernel Extensions Without Run-Time Checking", OSDI 1996 — PCC, 哲学先驱
2. Yee et al., "Native Client: A Sandbox for Portable, Untrusted x86 Native Code", S&P 2009 — SFI safety/correctness 分离
3. Johnson et al., "Доверяй, но проверяй: SFI safety for native-compiled Wasm", NDSS 2021 — VeriWasm, 最明确的 safety/correctness 分离
4. Xu et al., "Synthesizing Safe and Efficient Kernel Extensions for Packet Processing", SIGCOMM 2021 — K2, BPF 优化+verifier
5. D'Silva et al., "The Correctness-Security Gap in Compiler Optimization", SPW 2015 — correctness ≠ safety 的理论讨论

### 强烈推荐引用
6. Necula, "Translation Validation for an Optimizing Compiler", PLDI 2000 — untrusted compiler + trusted validator
7. Leroy, "Formal Verification of a Realistic Compiler", CACM 2009 — CompCert, verified compiler 对比
8. Bershad et al., "Extensibility, Safety and Performance in the SPIN Operating System", SOSP 1995 — type safety ≠ correctness
9. ePass, "Verifier-Cooperative Runtime Enforcement for eBPF" — 内核态 BPF 编译框架对比
10. Jia et al., "Rex: Closing the language-verifier gap", ATC 2025 — trusted compiler 路线对比

### 可选引用
11. Sun et al., "Approximation Enforced Execution", USENIX Security 2025 — verifier TCB reduction
12. Wu et al., "VEP: A Two-stage Verification Toolchain", NSDI 2025 — 两阶段验证
13. Blum & Kannan, "Designing programs that check their work", JACM 1995 — result checking 理论
14. Alpern & Schneider, "Recognizing Safety and Liveness", 1987 — safety/liveness 分离理论

---

## Sources

- [K2 Optimizing Compiler](https://k2.cs.rutgers.edu/)
- [K2 Paper (arXiv)](https://arxiv.org/abs/2103.00022)
- [Jitterbug (OSDI 2020)](https://www.usenix.org/conference/osdi20/presentation/nelson)
- [Jitk Paper](https://davidlazar.org/papers/jitk.pdf)
- [CompCert](https://compcert.org/)
- [CompCert TCB](https://hal.science/hal-03541595/document)
- [CakeML](https://cakeml.org/)
- [Vellvm](https://www.cis.upenn.edu/~stevez/vellvm/)
- [PCC - Necula](https://people.eecs.berkeley.edu/~necula/pcc.html)
- [PCC - Safe Kernel Extensions (OSDI 1996)](https://www.usenix.org/conference/osdi-96/safe-kernel-extensions-without-run-time-checking)
- [Translation Validation (Necula, PLDI 2000)](https://people.eecs.berkeley.edu/~necula/Papers/tv_pldi00.pdf)
- [Alive2 (PLDI 2021)](https://users.cs.utah.edu/~regehr/alive2-pldi21.pdf)
- [VeriWasm (NDSS 2021)](https://cseweb.ucsd.edu/~lerner/papers/wasm-sfi-ndss2021.pdf)
- [Wasmtime Security and Correctness](https://bytecodealliance.org/articles/security-and-correctness-in-wasmtime)
- [VeriISLE (Cranelift verification)](https://cs.wellesley.edu/~avh/veri-isle-preprint.pdf)
- [NaCl SFI](https://css.csail.mit.edu/6.858/2017/lec/l08-nacl.txt)
- [SPIN OS (SOSP 1995)](https://cseweb.ucsd.edu/~savage/papers/Sosp95.pdf)
- [seL4 (SOSP 2009)](https://www.sigops.org/s/conferences/sosp/2009/papers/klein-sosp09.pdf)
- [Singularity OS](https://www.microsoft.com/en-us/research/project/singularity/)
- [Linux Livepatch](https://docs.kernel.org/livepatch/livepatch.html)
- [Merlin (ASPLOS 2024)](https://people.cs.umass.edu/~juanzhai/papers/asplos24.pdf)
- [EPSO (ASE 2025)](https://arxiv.org/abs/2511.15589)
- [ePass](https://github.com/OrderLab/ePass)
- [BCF](https://haosun.info/assets/pdf/BCF.pdf)
- [BeePL](https://arxiv.org/abs/2507.09883)
- [Rex/Rax (ATC 2025)](https://www.usenix.org/conference/atc25/presentation/jia)
- [AEE (USENIX Security 2025)](https://www.usenix.org/conference/usenixsecurity25/presentation/sun-hao)
- [Moat (USENIX Security 2024)](https://www.usenix.org/conference/usenixsecurity24/presentation/lu-hongyi)
- [SafeBPF (CCSW 2024)](https://arxiv.org/abs/2409.07508)
- [VEP (NSDI 2025)](https://www.usenix.org/conference/nsdi25/presentation/wu-xiwei)
- [D'Silva: Correctness-Security Gap (SPW 2015)](https://nebelwelt.net/files/15LangSec.pdf)
- [Alpern & Schneider: Recognizing Safety and Liveness](https://www.cs.cornell.edu/fbs/publications/RecSafeLive.pdf)
- [Blum & Kannan: Program Checking (JACM 1995)](https://dl.acm.org/doi/10.1145/200836.200880)
- [Kernel Extension Verification is Untenable (HotOS 2023)](https://people.cs.vt.edu/djwillia/papers/hotos23-untenable.pdf)
- [eBPF Runtime in the Linux Kernel](https://arxiv.org/html/2410.00026v2)
- [Certifying Compilation](https://hjemmesider.diku.dk/~andrzej/certcomp.html)
