# 三篇论文相关工作 / 参考文献缺口分析

日期: 2026-05-20
范围: `docs/rejit-speculative-optimization-ebpf_idea.md` (idea #1) /
`docs/kop_idea.md` (idea #2) / `docs/nativebpf_idea.md` (idea #3)
方法: web 检索 eBPF 优化/验证/JIT/native-code 文献 + 对比三篇现有引用

---

## TL;DR (结论先行)

三篇文档已经覆盖了**最核心的对标工作**(K2 / Merlin / EPSO / BCF / PCC / 经典 JIT
speculation),但**每篇都缺 2–4 个直接相关、审稿人一定会问的工作**:

- **idea #1 最大缺口**:**Morpheus / "Domain Specific Run Time Optimization for
  Software Data Planes" (ASPLOS'22, Miano et al.)** —— 这是**和 idea #1 几乎
  撞题的 prior work**:runtime profile-guided 特化软件数据面(含 eBPF)+ 动态
  重编译 + guard。必须引用并明确划清差异,否则审稿人会直接说"这不是
  Morpheus 吗"。
- **idea #2 最大缺口**:**hXDP (OSDI'20) + eBPF Program Warping (ATC'22)** ——
  用优化过的硬件实现替换 eBPF 指令序列、扩展 eBPF ISA,和 kop "拓宽 emit
  vocabulary" 思路同构(只是 target 是 FPGA 而非 host JIT)。
- **idea #3 最大缺口**:**WebAssembly 沙箱一条线 (RLBox / VeriWasm Sec'21 /
  Provably-Safe Multilingual Sandboxing Sec'22 / WasmBoxC)** —— "把不可信代码
  编译到可安全检查的 IR 再 lower 到 native" 与 reverse-sim 的
  "native→eBPF→verifier" 结构完全同构,是最近邻 prior work。

下面按论文逐条列出。✅ = 已引用,➕ = 建议新增,⚠️ = 撞题/必须正面回应。

---

## 检索到的 eBPF 相关工作全集 (按主题)

来源: pchaigno eBPF 论文清单 (2025-01) + eunomia 清单 + 直接检索。

### A. eBPF 字节码优化 / 超优化 (idea #1/#2 直接对标)
| 论文 | venue | 一句话 |
|---|---|---|
| K2: Synthesizing Safe and Efficient Kernel Extensions for Packet Processing | SIGCOMM'21 | 基于 synthesis 的 superoptimizer,stochastic search + verifier-passing |
| Merlin: Multi-tier Optimization of eBPF Code | ASPLOS'24 | LLVM pass + bytecode rewrite,instruction merging/strength reduction |
| EPSO: A Caching-Based Efficient Superoptimizer for BPF Bytecode | ASE'25 | caching 加速 superopt,优于 K2 全部、Merlin 92.68% |
| **Domain Specific Run Time Optimization for Software Data Planes (Morpheus)** | **ASPLOS'22** | **运行时按 traffic pattern 特化数据面二进制(含 eBPF),动态重编译** |

### B. eBPF + 硬件 / FPGA (idea #2 直接对标)
| 论文 | venue | 一句话 |
|---|---|---|
| hXDP: Efficient Software Packet Processing on FPGA NICs | OSDI'20 | XDP/eBPF 在 FPGA NIC 上执行,扩展 eBPF ISA |
| Faster Software Packet Processing on FPGA NICs with eBPF Program Warping | ATC'22 | peephole 把 eBPF 指令序列替换成优化过的硬件实现 |

### C. eBPF JIT 形式化验证 (idea #2/#3 对标)
| 论文 | venue | 一句话 |
|---|---|---|
| Jitterbug: Specification & Verification of BPF JIT (formal) | OSDI'20 | eBPF JIT 形式化验证 + 新 32-bit RISC-V verified JIT |
| Synthesizing JIT Compilers for In-Kernel DSLs | CAV'20 | 从 DSL interpreter 合成 verified eBPF/cBPF JIT |
| Jitk: Trustworthy In-Kernel Interpreter Infrastructure | OSDI'14 | 形式化验证把高层规则编译到 cBPF + machine code |
| Serval: Scaling Symbolic Evaluation for Verification | SOSP'19 | 通过 lift interpreter 做 system 软件 verifier(含 eBPF) |
| End-to-end Mechanized Proof of eBPF VM for Micro-controllers | CAV'22 | RIOT 上 eBPF interpreter+verifier 正确性证明 |
| End-to-End Mechanized Proof of JIT-Accelerated eBPF VM for IoT | CAV'24 | RIOT eBPF JIT 正确性证明 |

### D. eBPF verifier 精度 / 可表达性 (idea #1 "吃 verifier tnum/range" 的背景)
| 论文 | venue | 一句话 |
|---|---|---|
| PREVAIL: Simple and Precise Static Analysis of Untrusted Kernel Extensions | PLDI'19 | abstract interpretation 替代 verifier(Windows 用) |
| Sound, Precise, Fast Abstract Interpretation with Tristate Numbers | CGO'22 | 形式化证明并改进 verifier 的 tnum |
| Verifying the Verifier: eBPF Range Analysis Verification | CAV'23 | 自动形式化证明 verifier range analysis |
| Validating the eBPF Verifier via State Embedding | OSDI'24 | state embedding 当 oracle fuzz verifier |
| eBPF Misbehavior Detection: Spec-Based Oracle | SOSP'25 | spec-based oracle fuzz verifier |
| BCF: Prove It to the Kernel (proof-guided abstraction refinement) | SOSP'25 | userspace SMT 出 proof,verifier 精度按需 refine |
| Fast, Flexible, and Practical Kernel Extensions | SOSP'24 | verifier 加有限 runtime check,提升表达力 |
| Rex: Closing the language-verifier gap | ATC'25 | 用 Rust 编译器 + runtime check 替代 verifier |
| VEP: Two-stage Verification Toolchain | NSDI'25 | C 源码 annotation 做 PCC 式 eBPF 验证 |
| Approximation Enforced Execution of Untrusted Kernel Extensions | Sec'25 | 用 verifier 的 state approximation 加 runtime check |

### E. eBPF 安全加固 / 隔离 (idea #2 TCB 论证 + idea #3 沙箱对标)
| 论文 | venue | 一句话 |
|---|---|---|
| BeeBox: Hardening BPF Against Transient Execution Attacks | Sec'24 | verifier 静态分析 + SFI-like runtime check 防瞬态执行 |
| MOAT: Towards Safe BPF Kernel Extension | Sec'24 | Intel MPK + helper runtime check 隔离 eBPF |
| Hive: HW-assisted Isolated Execution for eBPF on AArch64 | Sec'24 | 用硬件 runtime isolation 替代 verifier 静态分析 |

### F. 安全运行 native code / 沙箱 (idea #3 直接对标)
| 论文 | venue | 一句话 |
|---|---|---|
| Safe Kernel Extensions Without Run-Time Checking (PCC) | OSDI'96 | proof-carrying code,reverse-sim 已引 ✅ |
| Native Client (NaCl) | S&P'09 | SFI 直接验证/约束 native 机器码,已引 ✅ |
| RockSalt | PLDI'12 | 形式化验证的 SFI checker,已引 ✅ |
| **VeriWasm: SFI safety for native-compiled Wasm** | **Sec'21** | **验证 Wasm→native 编译保持 SFI** |
| **Provably-Safe Multilingual Software Sandboxing using WebAssembly** | **Sec'22** | **多语言编译到 Wasm 当可安全检查 IR 再 lower 到 native** |
| **RLBox (Firefox 95)** | **Sec'20** | **不可信库编译成 Wasm 再编 native,同地址空间安全共享** |
| WasmBoxC / Gobi | blog/arXiv | Wasm 当 SFI 基底做库沙箱 |
| Sail (machine-checked ISA semantics) | —— | reverse-sim 已引 ✅ |

---

## 逐篇缺口

### Idea #1 — Speculative eBPF Optimization (`rejit-speculative-optimization-ebpf_idea.md`)

现有引用(§1.5 / §1.8 / §3):
- ✅ Self/PIC [Chambers&Ungar OOPSLA'91, Hölzle PLDI'91]
- ✅ HotSpot tiered + PGO,V8 TurboFan + OSR,CoreJIT [POPL'21]
- ✅ K2 [SIGCOMM'21] / Merlin [ASPLOS'24] / EPSO [ASE'25]
- ✅ BCF [SOSP'25],Linux livepatch,Jitk/Jitterbug,llvmbpf/bpftime

**建议新增**:
- ⚠️ **Morpheus — Domain Specific Run Time Optimization for Software Data
  Planes [ASPLOS'22, Miano/Sanaee/Risso/Rétvári/Antichi]**。这是 idea #1 的
  **最近邻 prior work**:它就是"运行时按 traffic profile 特化数据面二进制
  (含 eBPF)+ 动态重编译"。必须在 §1.8 比较表加一行,明确差异:Morpheus
  特化的是 datapath binary 且不经 verifier 重认证;bpfopt 是 BPF→BPF
  rewrite + stock verifier 当 oracle + guard-protected 多版本 + 不需要 OSR。
  **不引用这篇是 idea #1 投稿的最大风险。**
- ➕ **PREVAIL [PLDI'19]**:§1.4 Insight 3 / §1.5 反复讲"吃 verifier 已算出来的
  tnum/range,砍掉自己的 analyzer"。PREVAIL = abstract-interpretation verifier,
  是讨论"verifier 作为 abstract interpreter"时绕不开的引用。
- ➕ **Tristate Numbers [CGO'22] + Range Analysis Verification [CAV'23]**:既然
  设计 explicitly 依赖 verifier 的 tnum/range 当 ground truth,应引用这两篇
  说明"verifier 的 value-level abstract interpretation 是 sound 的、可被信任
  当 oracle"。直接支撑 Insight 3。
- ➕(可选)**verifier 可表达性一条线**:Fast/Flexible Kernel Extensions
  [SOSP'24]、Rex [ATC'25]、VEP [NSDI'25]、Approximation Enforced Execution
  [Sec'25]。这些都改 verifier/换 verifier;idea #1 的卖点恰恰是 **stock
  verifier、零内核改动**,放一句"与这些改内核的路线正交"能强化定位。

### Idea #2 — KOperation (`kop_idea.md`)

现有引用(§8):
- ✅ kfuncs (upstream),JIT peepholes (arm64 LDP fusion),JVM intrinsics,
  K2/Merlin/EPSO

**建议新增**:
- ⚠️ **hXDP [OSDI'20] + eBPF Program Warping [ATC'22]**:Program Warping 用
  peephole 把一串 eBPF 指令替换成**优化过的硬件实现**,hXDP 给 eBPF 扩
  ISA。这跟 kop 的核心("把一段 BPF 模式识别出来,emit 成更接近硬件的单条
  原语,拓宽 emit vocabulary")是同构的,只是 target 是 FPGA overlay 而非
  host x86/arm64 JIT。审稿人极可能拿这两篇对标 —— 应主动加入 §8,差异点是
  kop 在 stock host JIT 上做、module 边界、verifier 见 instantiate_insn。
- ➕ **JIT 形式化验证一条线**:Jitterbug [OSDI'20]、Synthesizing JIT Compilers
  [CAV'20]。kop 的 soundness 论证(declarative effect 必须忠实建模 native
  emit,见 §9 + `kop-formal-semantics.md`)正是"JIT emit 正确性"问题。引用
  这些是为 §9 风险点(declarative effect 不忠实 = 静默违反 verifier soundness)
  提供方法论锚点 —— translation validation / verified JIT 是 mitigation 的
  既有范式。
- ➕(可选)**BeeBox/MOAT/Hive [Sec'24]**:§6/§7 讲"kernel surface / TCB
  随 kop 数量增长"。这三篇是"给 eBPF 加硬件/SFI 隔离"的对照组,可用于
  论证 kop 的 TCB 增量 vs. 这些路线。优先级低于上面两条。

### Idea #3 — NativeBPF (`nativebpf_idea.md`)

现有引用(§Related Work Positioning):
- ✅ PCC [Necula&Lee OSDI'96]
- ✅ Translation validation(泛指)
- ✅ Native Client / RockSalt / native validators
- ✅ Verified eBPF JIT (Jitterbug / Serval / K2)
- ✅ Sail machine-checked ISA semantics

**建议新增**:
- ⚠️ **WebAssembly 沙箱一条线**:
  - **Provably-Safe Multilingual Software Sandboxing using WebAssembly
    [Sec'22, Bosamiya et al.]** —— 把多语言代码编译到 Wasm 当**可被安全检查的
    IR**,再 lower 到 native。
  - **VeriWasm [Sec'21]** —— 验证 Wasm→native 编译保持 SFI。
  - **RLBox [Sec'20 / Firefox 95]** —— 不可信库 → Wasm → native,同地址空间安全
    共享。
  这条线和 reverse-sim **结构完全同构**:reverse-sim 的"native → (trusted
  lowering) → eBPF → stock verifier 当 proof checker → stock JIT → native"
  正是 Wasm 沙箱的"untrusted → trusted compile → safe IR → checker →
  native",只是把 Wasm/SFI 换成 eBPF/verifier。**这是 reverse-sim 的最近邻
  prior work,必须正面区分**:reverse-sim 不引入新 IR/新 checker,复用内核已
  有的 eBPF verifier + JIT,且做的是 native ISA(x86/arm64)而非 Wasm 这类
  已经为沙箱设计的 IR。
- ➕ **Jitk [OSDI'14]**:已引 Serval,但 Jitk(verified 编译高层规则→cBPF+
  machine code)对"trusted lowering 写成可验证组件"这点更贴。
- ➕ **RISC-V/IoT eBPF mechanized proofs [CAV'22, CAV'24]**:reverse-sim 的
  trust model 依赖"simulator/JIT 写成 C 编到 eBPF 后可形式化验证一次"。这两篇
  是"对一个具体 eBPF interpreter/JIT 做端到端机器证明"的现成范例,支撑
  §Trust Model 里"simulator I 可被形式化验证"的可行性主张。
- ➕(可选)**经典 SFI [Wahbe et al. SOSP'93]**:与 NaCl/RockSalt 并列,补全
  SFI 谱系的起点。

---

## 跨三篇的共享 related-work 池(建议统一维护)

三篇共用同一 evaluation,related work 也大量重叠。建议建一个共享 bib,各篇按
定位取子集:

- **eBPF 优化对标**(#1 主用,#2 次用):K2 / Merlin / EPSO / **Morpheus** /
  hXDP / Program Warping
- **verifier 精度与替代**(#1 背景,#3 对照):PREVAIL / tnum CGO'22 /
  range CAV'23 / BCF / Fast-Flexible SOSP'24 / Rex / VEP /
  Approximation-Enforced
- **JIT/interpreter 形式化验证**(#2 #3 主用):Jitterbug / Synth-JIT CAV'20 /
  Jitk / Serval / RIOT CAV'22+CAV'24
- **安全运行 native / 沙箱**(#3 主用):PCC / NaCl / RockSalt / VeriWasm /
  Wasm-multilingual-sandbox / RLBox / SFI(Wahbe)
- **经典 JIT speculation**(#1 主用):Self/PIC / HotSpot / V8 TurboFan /
  CoreJIT

---

## 检索来源

- pchaigno, "eBPF Research Papers" (2025-01-07):
  https://pchaigno.github.io/bpf/2025/01/07/research-papers-bpf.html
- eunomia, "Key Research Papers" / "Ecosystem Progress 2024–2025":
  https://eunomia.dev/blog/2024/03/11/...  /  https://eunomia.dev/blog/2025/02/12/...
- Merlin (ASPLOS'24): https://people.cs.umass.edu/~juanzhai/papers/asplos24.pdf
- EPSO (ASE'25): https://arxiv.org/abs/2511.15589
- BCF (SOSP'25): https://haosun.info/assets/pdf/BCF.pdf
- hXDP (OSDI'20): https://arxiv.org/pdf/2010.14145
- Provably-Safe Multilingual Sandboxing (Sec'22):
  https://www.usenix.org/system/files/sec22fall_bosamiya.pdf
- VeriWasm (Sec'21): https://cseweb.ucsd.edu/~dstefan/pubs/johnson:2021:veriwasm.pdf
- Demystifying Performance of eBPF Network Applications (CoNEXT/ACM Netw. '25):
  https://dl.acm.org/doi/10.1145/3749216

---

## 二次审计补充(2026-05-20,3 个 haiku subagent 并行)

在第一轮(K2/Merlin/EPSO/Morpheus/hXDP/Wasm 等)之外,三个并行 subagent 又找出以下
净新增、且已下载 PDF 入 `docs/reference/papers/` 的引用。已分别补进三篇 idea doc 的
related work。

### Idea #1 — BpfReJIT(rejit doc §1.8 "speculation/deopt 与在线换码"补充)
| 论文 | venue | 作用 | PDF |
|---|---|---|---|
| Deoptless: Speculation w/ Dispatched OSR & Specialized Continuations | PLDI'22 | 对标 two-tier deopt(不走传统 deopt) | `90-deoptless-...pdf` |
| Correctness of Speculative Optimizations w/ Dynamic Deoptimization (Flückiger) | POPL'18 | CoreJIT 奠基前作,形式化 guard/deopt | `91-correctness-speculative-...pdf` |
| KShot: Live Kernel Patching (SMM+SGX) | DSN'20 | 运行中内核原子换码先例 | `92-kshot-...pdf` |
| bpftime (EIM) | OSDI'25 | 用户态 eBPF 运行时,正式引 | 已在 `47-cache-ext`/bpftime 库内 |

### Idea #2 — KOperation(§8 新增 "peephole/超优化正确性谱系")
kop soundness("声明式 effect ≡ native emit")= peephole 正确性问题,这条线原先一篇没引:
| 论文 | venue | 作用 | PDF |
|---|---|---|---|
| Alive: Provably Correct Peephole Optimizations | PLDI'15 | DSL+SMT 证 peephole 等价(⚠️ 方法论直系) | `85b-alive-...pdf` |
| STOKE: Stochastic Superoptimization | ASPLOS'13 | x86 序列超优化 + 符号验证 | `85-stoke-...pdf` |
| Minotaur: SIMD-Oriented Synthesizing Superoptimizer | OOPSLA'24 | 合成+验证 SIMD peephole | `86-minotaur-...pdf` |
| Souper (LLVM superoptimizer) | — | IR 级 SMT 超优化 | `87-souper-...pdf` |
| Alive2: Bounded Translation Validation for LLVM | PLDI'21 | LLVM 变换有界验证 | `88-alive2-...pdf` |
| Hydra: Generalizing Peephole Optimizations | OOPSLA'24 | 泛化 peephole + 验证 | `89-hydra-...pdf` |
| ePASS(in-kernel eBPF 编译框架) | 2025 | SSA IR + verifier 协同,架构对比(也涉 idea #1) | 无(GitHub) |

### Idea #3 — NativeBPF(机制谱系 + 主对比)
| 论文 | venue | 作用 | PDF |
|---|---|---|---|
| **Islaris: Verification of Machine Code Against Authoritative ISA Semantics** | PLDI'22 | **⚠️ 直击核心难题**:native↔权威 ISA 语义忠实等价的现成方法 | `80-islaris-...pdf` |
| Formally Verified Native Code Generation in an Effectful JIT | POPL'23 | 形式化验证动态 native 代码生成 | `81-formally-verified-native-codegen-...pdf` |
| SafeDrive | OSDI'06 | 语言级驱动隔离(对比:信任编译器一路) | `82-safedrive-...pdf` |
| Nooks | SOSP'03 | 页表沙箱隔离驱动(对比:运行时隔离一路) | `83-nooks-...pdf` |
| Singularity | SOSP/OSR'07 | SIP / Sing# 语言安全 | `84-singularity-...pdf` |
| CHERI | S&P 多年 | 硬件 capability 内存安全(对照路) | 无 |

### 最该立刻用的 4 个
1. **Islaris [PLDI'22]**(idea#3)—— 锚定核心难题,最高价值。
2. **Alive [PLDI'15] + STOKE [ASPLOS'13]**(idea#2)—— 补 kop 缺失的 peephole-correctness 谱系。
3. **Deoptless [PLDI'22]**(idea#1)—— 对标 two-tier deopt。

(注:`docs/reference/papers/manifest.csv` 已删除;元数据脏的问题随之消失。`manifest.json` 保留。)

### 补充:安全内核扩展的完整谱系(idea#3 主对比,2026-05-20)

把"扩展内核安全"理成 5 支(两轴:静态 vs 运行时强制 × 信任作者 vs 管二进制),NativeBPF
主对比的"更广谱系"已据此重写。新增 SFI 单列(原先被并进硬件隔离)+ 与 NativeBPF 的尖锐对照
("都不信任作者,但 SFI 运行时改写+插 check,NativeBPF 静态验证+裸跑未改动 native")。新下 PDF:
| 论文 | venue | 阵营 | PDF |
|---|---|---|---|
| XFI: Software Guards for System Address Spaces | OSDI'06 | SFI | `93-xfi-...pdf` |
| BGI: Fast Byte-Granularity Software Fault Isolation | SOSP'09 | SFI | `94-bgi-...pdf` |
| Mondrix: Memory Isolation for Linux (Mondriaan) | SOSP'05 | 硬件/页表隔离 | `95-mondrix-...pdf` |

(Wahbe SOSP'93 / NaCl / RockSalt 已在库 / 已引;CHERI 无 PDF;MPK 路线 MOAT/Hive 在库 #13/#14。)
