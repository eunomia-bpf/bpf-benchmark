# NativeBPF:用 eBPF simulator 让内核扩展又安全又高效

状态:研究方向 · idea #3 的论文线 hub

> **一句话**:内核扩展今天被"安全 × 高效"的三难逼着二选一 —— 内核模块快但不安全、
> eBPF 安全但有 codegen 惩罚、Rust-for-Linux 快但安全靠信任编译器而非独立验证。NativeBPF
> 占住缺失的那一角:**native 性能 + eBPF-verifier 级、对不可信作者也成立的独立安全**,
> 办法是裸跑原生扩展、而由 eBPF verifier 经一个忠实 simulator 来认证它。

## 项目背景:三个姐妹 idea

本研究项目产出三篇彼此独立的论文,它们共用同一套评测设施(`bpf-benchmark`
corpus、micro 套件和测量基础设施),但用不同的设计和实现解决不同的问题。

| # | Idea | 问题 | 设计核心 | 内核改动 |
|---|---|---|---|---|
| 1 | **Speculative eBPF optimization**(投机式 eBPF 优化) | 已加载的 eBPF 程序错失了那些只有在程序上线后才可见的优化机会(map 内容稳定下来、分支 profile 浮现、helper 调用模式显现)。 | 纯用户态工具:观察运行中的程序,施加 BPF-to-BPF 重写 pass(`map_inline`、`const_prop`、`dce`、`bounds_check_merge`、`branch_flip` 等),再用 stock 内核的原子或近原子 attach 更新机制换入优化后的候选程序。 | 接近零。 |
| 2 | **Kinsn** | eBPF 指令集离硬件太远,无法表达若干 native 等价的优化(rotate、conditional select、BMI 位域提取、BLS 指令、prefetch)。 | 一个新的 OS 抽象:内核定义的双语义指令,以 kfunc 机制的 `KF_KINSN` 特化形式实现。verifier 把一个声明式 effect(`model_call` → `bpf_kinsn_effect`)施加到它的抽象状态上,JIT 则分派到内核模块提供的、按架构区分的 `emit_x86()` / `emit_arm64()` 回调。用户态优化器(`bpfopt`)负责识别候选模式。 | kinsn 框架 patch + 各架构模块,TCB 增长但有界。 |
| 3 | **NativeBPF**(本文档) | 内核扩展被"安全 × 高效"三难逼着二选一:模块快但不安全、eBPF 安全但有 codegen 惩罚、Rust 快但安全靠信任编译器而非独立验证。如何同时拿到 native 性能 + 对不可信作者也成立的独立安全? | 用 eBPF C 写一个目标 ISA 的忠实解释器。针对某个具体目标程序特化,把解释器坍缩成 straight-line eBPF,**交给 stock eBPF verifier 做它平常那套安全分析**。**verifier 接受后直接裸跑 native P;那段 eBPF 只是被分析的对象,从不执行,无 lowering。** | 接近零(执行 native P 的路径除外)。 |

这三者不是同一个设计的递进版本。每个各自挑了一个不同的问题、一个在 trust /
内核暴露面 / 覆盖面空间里不同的位置。本文档讲的是 idea #3。idea #1 在
`docs/rejit-speculative-optimization-ebpf_idea.md`,idea #2 在
`docs/kinsn_idea.md`(机制设计见 `docs/tmp/kinsn-design.md`,形式语义见
`docs/tmp/kinsn-formal-semantics.md`)。

"NativeBPF" 还有一个 kernel-ABI 变体(由内核拥有的双语义 ISA),那是 idea #3
更早的一种 framing。它和 idea #2 重叠很大,现在只作为一条备选路径记录在
[备选路径:kernel-ABI 双语义 ISA](#alternative-path-kernel-abi-dual-semantics-isa)
一节。

## 问题:内核扩展的安全 × 高效三难

扩展内核今天有三条主流路,各自缺"安全"或"高效"的一角:

| 方式 | 性能 | 安全来源 | 信任谁 | 表达力 |
|---|---|---|---|---|
| **kernel module (C)** | native ✅ | 无 ❌ | 完全信任作者 | 无限 ✅ |
| **eBPF** | eBPF-JIT,有 codegen 惩罚 ❌ | verifier 独立检查 ✅ | **不信任作者** ✅ | verifier 受限 ❌ |
| **Rust-for-Linux** | native ✅ | 编译期类型 / borrow checker | 信任 Rust 编译器 + `unsafe` 块 ⚠️ | 无限 ✅ |
| **NativeBPF(本文)** | **native ✅** | **verifier 独立检查 ✅** | **不信任作者 ✅** | verifier 受限 |

- **内核模块**:native 速度,但**没有任何验证**,一个 bug 就是内核崩溃 / 提权 —— 完全信任作者。
- **eBPF**:verifier 对不可信作者也独立保证内存安全 / 有界终止,但执行的是 eBPF-JIT 产物,
  背 codegen 惩罚(相对 native 约 30–40%,10 寄存器、byte-recompose 等;这正是 idea #1 /
  llvmbpf 在追的差距),且表达力受 verifier 限制。
- **Rust-for-Linux**:编译到 native,安全靠语言类型系统 / borrow checker —— 但那是**编译期**
  的、**信任 Rust 工具链 + `unsafe` 块**的安全,**不是对一个不可信二进制做独立的 load-time
  检查**;它没有 eBPF 那种"untrusted producer, trusted checker"性质。

**NativeBPF 占的是没人占的那一格:native 性能 + eBPF-verifier 级、对不可信作者也成立的
独立 load-time 安全。** module 没验证、eBPF 不 native、Rust 信任编译器而非独立验证 —— 三者
各缺一角,NativeBPF 把缺的那角补上。

**诚实的边界(必须主动承认)**:NativeBPF 的表达力仍被 verifier 锁死(无界循环、任意数据
结构跑不了)。所以它**不是**"在内核跑任意 native",而是 **"为本来就能在 verifier 下表达的
扩展,加上 native 速度,且仍不信任作者"** —— 一句话:**native-speed eBPF for untrusted
extensions**。它的天然战场和 eBPF 相同(多租户、跑不可信扩展),只是把性能拉到 native。
- **vs eBPF**:相同安全、相同表达力上限,**纯赚性能**(裸跑 native vs 跑 eBPF-JIT 产物)。
- **vs 模块 / Rust**:它们表达力无限而 NativeBPF 受限;NativeBPF 换来的是**对不可信作者
  也成立的独立验证**(模块完全没有;Rust 是编译器信任,不是独立检查)。

## 核心思想

NativeBPF 把 **stock eBPF verifier 复用成 native 代码的现成安全检查器(safety oracle)**:
用一个目标 ISA 的**忠实解释器 `I`**(不插任何检查的纯翻译器),让 verifier 对"`I` 跑目标
程序 P 的过程"跑它平常那套 abstract-interpretation 安全分析。**verifier 接受 = 它确证了
"P 在 eBPF 内存安全策略下没问题"。然后内核直接裸跑原生 P 本身。**

**关键:那段 eBPF 只是被 verifier 分析的对象,不是被执行的东西。整条路径没有 lowering ——
不把 P 翻译成 eBPF 再跑、也不 JIT eBPF 回 native。被执行的是未经改动的 native P。**

```text
                ┌─ 验证侧(只在 load / 验证期):
                │     native P + 已验证的忠实解释器 I
target P ───────┤     → 把 "I 跑 P" 表示成 verifier 可分析的 eBPF(见 §机制:如何特化)
                │     → stock eBPF verifier 跑它平常的安全分析(abstract interpretation)
                │     → verifier 接受 = 确证 P 内存安全
                │
                └─ 执行侧(运行期):
                      → 直接执行原生 P            ← 无 eBPF 执行,无 JIT-from-eBPF,无 lowering
```

> **机制提示(非本质,属可行性手段)**:通用解释器有无界循环,直接喂 verifier 过不了。
> 怎么把"`I` 跑 P"变成 verifier 可处理的直线 eBPF —— 靠**部分求值 / 特化**(把 P 当静态
> 输入,clang 常量传播把解释循环展开成直线)。这是让方案可行的工程技术,细节见
> [机制](#mechanism),不是 idea 的概念核心。概念核心只有一句:**复用 eBPF verifier 当
> native 的安全检查器,忠实解释器搭桥,裸跑 native。**

> **关于 PCC 的措辞**:本 idea **不是** proof-carrying code —— 没有任何东西携带一份显式
> proof 证书,verifier 也不是在校验证书,而是用自己的 abstract interpretation **推断**
> 安全性。因此核心描述不用 "PCC / proof checker / 携带 proof" 的语言;PCC 只作为相关工作
> 的**对照**出现(见 [相关工作](#related-work-positioning)与 [它不是什么](#它是什么不是什么))。

一句话概括:

```text
NativeBPF reuses the stock eBPF verifier as an off-the-shelf safety checker for
native code: a once-verified, faithful ISA interpreter — specialized to the target
program — turns "is P safe?" into an eBPF program that the verifier accepts or
rejects via its ordinary abstract-interpretation analysis. The native program P
itself then runs directly; the eBPF is only the analyzed artifact, never executed.
(Nothing carries an explicit proof and the verifier checks no certificate — this
is not proof-carrying code; see Related Work.)
```

用户向内核提交的是 native 程序 P(连同其特化解释器,供 verifier 分析)。verifier 接受后,
**内核直接裸跑 P**;eBPF 全程不参与执行。

这个 idea 内部有两种生成"供 verifier 分析的 eBPF"的策略:

- **NativeBPF(simulator 变体,主线)**:用 C 写目标 ISA 的忠实解释器,靠 clang 常量
  传播针对单个 P 做特化(这是 Futamura 第一投影:把解释器特化到程序 = 得到对该程序的
  专用直线 eBPF)。编译快(每个程序一次特化,而非每次 load 跑一遍 LLVM)。详见
  [机制](#mechanism)。
- **NativeBPF-in-eBPF(JIT 变体)**:用 C 写一个 native→eBPF 的显式翻译器,编译成
  eBPF,离线对 P emit 出供 verifier 分析的 eBPF。翻译器只需验证一次。两个变体的 trust
  模型与 safety transfer 论证完全相同,区别只在于"特化"由 clang 隐式做(simulator 变体)
  还是由显式 emitter 做(JIT 变体)。**两个变体的执行侧都一样 —— 跑 native P,不跑 eBPF。**

## 它是什么、不是什么

**它不是 proof-carrying code(PCC)。** PCC(Necula-Lee)的定义性特征是:代码**附带**一份
显式 proof 证书,一个轻量 checker **校验**这份证书。NativeBPF 两条都不满足:
- **没有任何东西携带 proof** —— 没有被生成、被传输、被校验的证书;
- **verifier 不校验 proof** —— 它跑自己的 abstract interpretation,**推断**出安全性
  (基础 eBPF verifier 是 inference engine,不是 proof checker;真正 PCC 风格的是 VEP 的
  源码 annotation、BCF 的 userspace 出 proof,基础 verifier 不是)。

所以本文档**不**用 "PCC / proof checker / 携带 proof" 当核心语言。准确的说法是:**复用
内核现成的 eBPF verifier(一个 load-time 安全分析器)当 native 代码的安全检查器。** PCC 与
本工作相关,但作为**对照**放在 [相关工作](#related-work-positioning)。

```text
经典 PCC:
  user native P + 用户附带的 proof 证书
    -> 轻量 checker 校验证书
    -> 裸跑 native P

NativeBPF(不是 PCC):
  native P + 已验证的忠实解释器 I(特化到 P → 一段直线 eBPF,作为被分析对象)
    -> stock eBPF verifier 跑它平常的 abstract interpretation(推断,非校验证书)
    -> verifier 接受 = 确证 P 内存安全
    -> 裸跑 native P              ← 直接跑 native,eBPF 不参与执行
```

**它不是"先把 P 翻译成 eBPF、再 JIT 回 native 来跑"。** eBPF 全程只是被 verifier 分析的
对象;被执行的始终是未经改动的原生 P,没有任何 lowering 往返。(早期文档曾把它写成"执行
eBPF-JIT 的产物"——那是错的:那样会白白背上 eBPF codegen 的性能惩罚,跑 native 的全部
意义就没了。)

它也不是"相信我,这段 native blob 是安全的"。native P 之所以能裸跑,是因为 verifier
对"忠实解释器跑 P 的过程"的抽象解释**确证**了 P 的每一次内存访问都在 eBPF 安全策略之内
(见 [安全性论证](#safety-argument));分析不过就拒绝,绝不裸跑。

它也不是任意 native 二进制的执行。如果目标程序有真正无法翻译的行为(对一个无法识别
的内核地址做计算型间接调用、用运行时数据构造的、目标集合无界的跳转表、不支持的 SIMD
指令),特化会失败,程序在到达 verifier 之前就被拒绝。

## 与 kinsn 的关系

Kinsn(idea #2)和 NativeBPF(idea #3)从相反的两端攻击同一个底层问题——如何让
非平凡的 native 操作在 eBPF 安全模型内变得可用:

- Kinsn 用内核定义的双语义原语扩展内核侧的指令集。每个新原语都让内核 TCB 小幅增长。
- NativeBPF 用一个经过验证的 simulator 或 JIT 扩展用户态侧的 lowering。内核保持不变。
  新增的 TCB 是一个用户态产物:每个目标 ISA 一个 C 文件,可独立验证。

Kinsn 覆盖的是"普通 eBPF 表达不好的少数几种模式"。NativeBPF 覆盖的是"目标 ISA 能
表达的任何东西,只要其 lowering 对 verifier 可处理"。两者并不互斥:一个支持 kinsn 的
内核,配上一个在有益处时 emit kinsn 的 NativeBPF,是一个自然的 ablation 点,但二者
互不依赖。

## 机制

本节给出 NativeBPF 变体的规格。NativeBPF-in-eBPF 变体使用相同的 lowering 规则,
但由一个显式 emitter 来执行,而非依赖 clang 特化;见
[NativeBPF-In-eBPF 变体](#reversesim-in-ebpf-variant)。

### 按程序特化

用 C 写一个目标 ISA 的 simulator。对每个用户程序:

1. 目标 native 二进制被当作数据:一个 native 指令数组加一个入口 PC,二者在特化后的
   源码里都是 `static const`。
2. simulator 在编译期针对这份数据做特化。由于从编译器的视角看指令数组是常量,clang
   的常量传播和 switch-table lowering 会把 dispatch 循环展开成一串 straight-line 的
   逐指令 handler。
3. 内核 eBPF verifier 看到的是一个对 verifier 可处理的 BPF 程序:没有无界循环,没有
   对运行时可变 opcode 的间接 dispatch,只是一长串小小的 handler 体。
4. **verifier 抽象解释这段 eBPF —— 它接受,就等于确证了"忠实解释器跑 P 的整个过程"
   内存安全。这段 eBPF 的全部用途就是被分析。它在此之后不再被执行:运行期直接裸跑原生 P。**

这里没有"运行时 simulator"也没有"运行时 JIT" —— 特化只在验证期发生一次,产物只喂给
verifier 做安全分析。simulator 是语义规格说明;verifier 看到的产物是它针对单个程序 P 的
特化(被分析对象)。被执行的永远是 native P。

### 为什么 verifier 会接受它

一个为图灵完备 ISA 写的通用 eBPF simulator 过不了 verifier:它有无界 dispatch 循环和
对任意 opcode 的间接跳转。特化把这两样都去掉:

- 指令序列是常量。外层 dispatch 循环被展开。特化之后没有任何运行时可变的 opcode 读取。
- 目标程序内部的直接跳转,变成对展开后 handler 链中已知偏移的 eBPF 跳转。目标程序内部
  的间接跳转,必须 lower 成一个 verifier 可接受的 dispatch(对编译期算出的、有界的可能
  目标集合做 PC-keyed switch)。
- 逐指令 handler 内部的内存访问走普通 BPF 指针类型。verifier 用它现有的规则检查它们。

每个 handler 都很小。每个 handler 都通过一条经过常量传播的控制路径到达。合在一起,它们
在 verifier 眼里就是一个很长但 straight-line 的 eBPF 程序。

### 安全性论证

安全性通过一个 refinement(精化)论证,从 eBPF verifier **传递到裸跑的 native P**:

```text
target native program P
  -> compile-time specialization of trusted interpreter I to P
  -> result is eBPF program B_{I,P}   （= 供 verifier 分析的对象,从不执行)
  -> verifier accepts B_{I,P}         （= 证明 "I 跑 P" 内存安全)
  -> 由"I 忠实等价于 ISA 语义" => P 本身内存安全
  -> 内核裸跑 native P
```

**被执行的是原始目标二进制 `P`,不是 `B_{I,P}`。** `B_{I,P}` 永远不被执行 —— 它只是
verifier 用来得出"P 安全"这一结论的被分析对象。验证期之后 eBPF 就退场,运行期 CPU 上跑的
就是 P。

为什么 verifier 接受 `B_{I,P}` 能证明 `P` 安全?**因为 `I` 是一个不插任何检查的纯忠实
翻译器。** `P` 里的越界等不安全行为无法藏在 simulator 抽象背后:如果 `P` 越过 packet
末尾读取,`B_{I,P}` 里对应那一步就会用**相同的有效地址**越过 packet 末尾读取,verifier
把它当作 packet 指针违规拒绝。`I` 绝不做掩码、边界插入或 sandbox 调整 —— 它逐条把 native
语义映射成对内核已在检查的同一批指针类型的 eBPF 操作。**"`I` 不做任何 sanitization"不是
实现细节,而是整个安全论证的支点:一旦 `I` 替 `P` 补了边界检查,verifier 看到的就是被
sanitize 过的安全访问,而裸跑的 `P` 仍然越界 —— safety transfer 当场失效。**

一个微妙之处:这个论证依赖于内存访问是一对一翻译的。间接控制流需要一个显式的、对
verifier 友好的形式(PC dispatch)。其它 verifier 无法直接建模的指令(例如宽向量操作、
专用 CPU 指令)必须要么用 helper/kfunc 调用表达,要么在特化这一步被拒绝。

### 信任模型

这个 idea 净增的信任依赖**只有一项**:解释器 `I` 的 C 源码与目标 ISA 真实语义的忠实等价
(`I` 不插任何检查)。

`I` 很小、每个目标 ISA 固定一份、且适合做形式化验证。其语义的可能来源有:

- 一个手写的 reference simulator,做一次形式化验证;
- 从机器可检查的 ISA 规格生成的 simulator(例如 Sail,`github.com/rems-project/sail`);
- ARM 发布了一个官方 C reference simulator,可作为 arm64 变体的起点。

**clang 编译 `I` 不是新增 TCB。** `I` 是一个写一次、固定、每 ISA 一份的可信组件,地位
等同于内核的一部分;编译它落在"信任工具链编译内核 / verifier 自身"这份**已经普遍预设**
的信任里。注意普通 eBPF 的安全也不来自信任 clang —— 来自 verifier 重查字节码;这里执行的
是裸 native P,而 `I` 作为可信代码被编译,与内核被 gcc/clang 编译同属一类信任,不是新项。

### 为什么"simulator"在运行时根本不存在

朴素的误解:这不过是个软件 simulator,会很慢。

更正:**simulator 在运行时根本不被执行。** 它只是验证期的一个**部分求值**对象(Futamura
第一投影:把解释器特化到程序 = 得到对该程序的编译产物 / 此处是供 verifier 分析的直线 eBPF)。`I` 的特化残差
是直线 eBPF,**唯一的消费者是 verifier**;它不被 JIT、不被运行。运行期 CPU 上跑的是原生
`P`,因此性能就是 native 性能 —— 这正是相对"跑 eBPF/eBPF-JIT 产物"路线的根本收益:**不
背 eBPF codegen 惩罚(10 寄存器、byte-recompose 等)。** "simulator" 纯粹是供 verifier
做安全分析的语义锚点,不是任何运行时形态。

### Helper、Kfunc 与边界 ABI

native 程序会做调用。simulator 不能把这些 emit 成不透明的绝对地址调用,因为 eBPF
verifier 要求每个调用都走它的 helper 或 kfunc 表。

编译期 lowering 处理这一点:

- 目标 native 程序里的每个 call site 在特化期被识别:把目标地址与内核导出的 helper
  和 kfunc 表做匹配。在同一内核上对一个现有 eBPF 程序做 `bpftool prog dump jited`,
  就能拿到类似程序所用每个 helper 的绝对地址;这些地址为识别提供锚点。
- 一个被识别的调用 lower 成一条 `BPF_CALL` eBPF 指令,其 `imm` 设为 helper 或 kfunc
  id。verifier 像检查任何其它 helper 调用一样检查它。
- 一个无法识别的调用地址会让特化大声失败。本模型不允许任意的间接内核调用。

tail call、exit 以及按 program 类型区分的返回值约定,同样在特化期 lower,各自使用现有
的 eBPF 惯用法。

### 寄存器文件与栈

目标机器的体系结构寄存器比 eBPF 多(x86 有 16 个 GPR,arm64 有 31 个,而 BPF 只有
10 个寄存器)。特化后的 simulator 把目标寄存器文件放在 BPF 栈的一块固定区域里:

```text
BPF stack layout:
  [ caller frame ]
  [ target reg file: r0..rN as i64 slots ]
  [ shadow flags  ]
  [ per-handler scratch ]
```

每个目标指令 handler 从这块 slot 区域读取源寄存器,以普通 eBPF 算术执行操作并做恰当
的类型跟踪(SCALAR 还是 PTR_TO_xxx,取决于 verifier 在那个 PC 上对那个 slot 的认知),
再把目标寄存器写回。

verifier 本来就按栈 slot 跟踪类型。风险在于状态爆炸——当很多 handler 在不同控制路径下
看到同一个 slot 带着不同类型时。缓解办法:在 handler 边界把所有通用目标寄存器钉死为
SCALAR 类型,只在真正执行指针类型操作的 handler 内部才把指针运算 materialize 出来。
更强的缓解办法:把目标程序切成更小的、对 verifier 可处理的 region,并在它们之间 emit
边界 materialization。

### 控制流 lowering

困难的情形:

- 直接的条件和无条件跳转 lower 成目标为展开后 handler 链中常量偏移的 eBPF 跳转。平凡。
- 间接跳转要求在特化期枚举出可能目标的集合。lower 后的形式是一个 PC-keyed switch:

  ```c
  switch (target_pc) {
    case PC_A: goto handler_A;
    case PC_B: goto handler_B;
    ...
    default:   fail();
  }
  ```

  这个 switch 表是常量,verifier 把它当作一个有界 dispatch 接受。落在枚举集合之外的
  目标会导致运行时 fail。
- 计算型 call 目标不被允许,除非它们落入被识别的 helper/kfunc 表。
- 返回语义把目标 ABI 的返回值寄存器映射到 eBPF 的 `r0`。

如果目标程序包含真正任意的间接控制流(用运行时数据构造的跳转表、从数据内存里 pop 出来
的返回地址),特化失败。这与 verifier 本来就对普通 eBPF 程序施加的限制相同,也与安全
模型一致。

### 实现规模

大致的体量预算:

| 组件 | LOC | 备注 |
|---|---|---|
| 各架构 simulator(x86) | 1.5k–3k C | dispatch + 逐指令 handler |
| 各架构 simulator(arm64) | 1k–2k C | ISA 更小,更简单 |
| 特化 driver | 500–1k Rust/C | 读取目标二进制,emit 特化后的 simulator 源码或直接 emit eBPF |
| Helper/kfunc 识别表 | 200–500 LOC | 每个内核 build 一份「绝对地址 -> helper id」映射 |
| 验证用内核改动 | ~0 | proof 检查复用 stock verifier(eBPF JIT 不参与,eBPF 不执行) |
| 执行 native P 的路径 | 待定 | 认证后需一条裸跑 P 的内核路径(模块/可执行页);这本身是开放设计点,**不是零成本** |

不需要新的内核 syscall,不需要新的 verifier hook,也不需要新的 JIT 路径。最终产物是一个
用户态工具,外加一份为运行中内核重新生成的 helper 地址表。

### 开放问题

这些事项决定了该变体能否扩展到超出一个小 PoC 的规模:

- 当指令数组是 static const 时,clang 是否能可靠地把 dispatch 坍缩掉,还是有些情形下它
  会留下运行时 dispatch?
- 在现实的目标程序规模下(1k、10k、100k 条 native 指令),verifier 是否能在其复杂度预算
  内接受展开后的程序?
- 栈 slot 化的目标寄存器的 SCALAR/PTR 状态,如何在不引起状态爆炸的前提下管理?
- 对带指针的目标寄存器(`rdi` 里的 packet 指针、`rsi` 里的 ctx 指针……),类型信息如何从
  prog-type 上下文传达进特化后的 handler?
- 预期 ARM 和 RISC-V 会比 x86 更友好,因为寄存器压力更低、也没有 CISC 特有的怪癖。需量化。

回答前两个问题的最小 PoC 是下一个具体步骤:实现一个 5 到 10 条指令的子集(`mov reg/imm`、
`add reg/reg`、`cmp`、条件与无条件 `jcc`、`ret`),为一个 50 条指令的程序编译一个手写的
特化 simulator,并验证(a)clang 产出一个无 dispatch 的直线 eBPF,(b)内核 verifier
接受它(= 确证 P 安全),(c)构造一个会越界的 P,确认它产出的 eBPF 被 verifier
**拒绝**(验证忠实性:不安全的 P 必须无法通过分析)。注意 PoC 不需要执行那段 eBPF ——
它只是被分析对象;真正要跑的是 native P。

### NativeBPF-In-eBPF 变体

idea #3 内部的另一条路是:用 C 写一个 native-to-eBPF JIT,把这个 JIT 本身编译成 eBPF,
离线针对目标二进制运行它,再把 emit 出来的 eBPF 提交给内核。trust profile 与 simulator
变体相同——JIT 取代 simulator 成为可信 lowering,而 stock eBPF verifier 仍然检查产出的
产物。

何时偏向 JIT 变体:

- 目标二进制大到使得整程序 clang 特化慢得无法放进流程里;
- lowering 需要 clang 常量传播发现不了的显式模式匹配(例如模式驱动地融合 native 的多
  指令惯用法);
- JIT 也可以充当 ablation 的宿主(关掉特定的 lowering、在可用处 emit kinsn 等)。

何时偏向 simulator 变体:

- lowering 规则简单、对每条 native 指令是统一的;
- 语义验证锚定在 simulator 上而非 emitter 上(相比 emitter,simulator 更容易对照 ISA
  规格做形式化);
- 实现工作量主要落在 handler 体上,而不是一个独立的 emitter 框架上。

两个变体共享下面的 Safety Model、Safety Transfer 论证、State Model 和 Boundary Rules。

## 安全模型

预期的安全性主张是:

```text
原生程序 P 在 eBPF 的内存 / 指针 / helper / 控制流策略下是安全的(因而可裸跑),
当且仅当 stock eBPF verifier 接受 B_{I,P}(即把忠实解释器 I 特化到 P 的产物),
且 I 是 native 语义到 verifier 已检查的同一批指针类型操作的、不插任何检查的 1:1 忠实翻译。
```

在本模型下,内核不接受任意的 x86 或 arm64 blob:**裸跑 P 之所以安全,是因为 verifier
对 `B_{I,P}` 的接受证明了 P 的每次访存都在 eBPF 安全策略内,而忠实等价把这份证明转移到了
真正在 CPU 上执行的 P。** 注意 eBPF `B_{I,P}` 本身从不执行 —— 它只是被 verifier 分析的对象。

用户或编译器都可以产出这份供 verifier 分析的 eBPF,但产出者在安全性上并不被信任。

**相对普通 eBPF,本 idea 净增的 TCB 只有一个:**

> **忠实解释器 `I` 与目标 ISA 真实语义的等价(`I` 不插任何检查、逐条忠实翻译)。**
> 它每个 ISA 一份、写一次、可一次性形式化验证。

其余"被信任的部分"都不是新增的:

- **eBPF verifier**:所有 eBPF 程序本来就信任它当安全裁决者 —— 不新增。
- **clang 编译 `I`**:`I` 是固定的可信组件(地位等同内核的一部分),编译它落在"信任工具链
  编译内核/verifier 自身"这份**已经普遍预设**的信任里 —— 普通 eBPF 的安全也不来自信任
  clang(来自 verifier)。所以 clang **不是新增 TCB 项**。
- **裸跑 native P 的执行路径**:内核本来就在跑 native;它不是独立的信任项。"proof 能否
  转移到裸跑的 P"这唯一的问题,**完全归结于上面那条 `I` 的忠实等价**。
- **eBPF JIT**:不在 TCB 里(eBPF 从不执行)。

对比经典 PCC(信任一份 per-program proof + 一个专用 checker),NativeBPF 把新增信任压缩成
**一个 per-ISA、可一次性验证**的解释器 —— 这是它 TCB 论述上的核心优势。

## Safety Transfer 论证

最强的安全性论证是一个 refinement(精化)论证。注意它的终点是**裸跑的 P**,不是 eBPF:

```text
native program P
  -> 把忠实解释器 I 特化到 P,得供 verifier 分析的 eBPF B = B_{I,P}
  -> verifier 接受 B          （证明 safe(I 跑 P))
  -> 忠实等价: B 的每个可观测访存/控制流 ≡ P 的对应行为(I 不插任何检查)
  -> 内核裸跑 native P
```

如果 verifier 证明了 `B` 安全,且忠实等价性表明 `B` 的每个可观测行为(访存、helper 调用、
控制流)都与 `P` 的对应行为**逐一相同**,那么裸跑 `P` 所表现出的,恰好是 `B` 被证明安全
的那个行为:

```text
safe(B) and B ≡ P faithfully  =>  safe(execute_native(P))
```

`P` 不是因为某个独立的 NativeBPF 被验证过才安全 —— 它安全,是因为 verifier 证明了"忠实
解释器跑 P"安全,而 `I` 的忠实等价把这份证明搬到了真正裸跑的 `P` 上。**整个论证的承重墙
就是这条忠实等价**:`I` 对 ISA 的建模必须和 CPU 真实执行 `P` 时的访存/控制流/异常行为
分毫不差。

> **核心难题(本 idea 真正该硬刚的,而非"lowering 工程"):** 上面 refinement 的最后一步
> "B ≡ P" 要求 `I` 的建模语义 == 真实 CPU 执行 `P` 的语义。任何偏差 —— flags 语义、未定义
> 行为、self-modifying code、并发/弱内存序、`I` 与硬件对某条指令理解不一致 —— 都会让 verifier
> 证的是一回事、CPU 跑的是另一回事,safety transfer 当场断裂。这正是原始讨论(附录 A)反复
> 绕、没有拍死的那一点。Paper 必须把这条等价做成可形式化、可对 oracle(如 eBPF/ISA self-test)
> 验证的工件,而不是假设它成立。

可能的可信 lowering 绑定方式:

- **特化忠实解释器(本文档主线)**:解释器是可信 lowering,clang 常量传播自动产出供 verifier 分析的直线 eBPF;
- **eBPF 里的显式 native→eBPF 翻译器**:翻译器是可信 lowering;
- **带机器可检查正确性证明的翻译器**:更强的可信 lowering;
- **certificate 检查**:用户态提交 `P`、`B` 及等价性 certificate,内核认证后裸跑 `P`。

**"verify B 却裸跑 P" 正是本 idea 的模型本身,不是漏洞。** 它安全的唯一前提是 `B` 与
裸跑的 `P` 之间由忠实的 `I` 锁住等价。真正不安全的构造是这条等价缺失时:

```text
userspace 提交一个安全的 B
userspace 又提交一个与 B 无忠实等价关系的、任意的 P
内核认证 B 后却裸跑那个无关的 P     ← 不安全:被分析的 B 与被执行的 P 没有等价桥相连
```

例如,一条被裸跑的 native 指令,其意图是:

```asm
mov rax, [rdi + 8]
```

只有当 `B_{I,P}` 里对应那一步通过一个经 verifier 检查的 BPF 指针、以**相同的边界、对象、
fault 行为**做同一个 load 时,裸跑这条 `mov` 才安全。若 `I` 对这条指令的建模与 CPU 实际
行为不符(等价断裂),verifier 的"安全"就保不住裸跑的 `P`。

重要的失败模式是不忠实的 lowering。例如,把一个 x86 内存访问 lower 成一个 sandbox 化的
VM 操作:

```text
guest_addr = rax
if guest_addr + 8 > guest_mem_size: unsupported
load guest_mem[guest_addr]
```

这证明的是 sandbox 化 x86 simulator 语义的安全性,而不是把 `rax` 当作真实内核地址来用的
安全性。NativeBPF 的 lowering 忠实,当且仅当目标程序在 packet、ctx、map_value 和 stack
指针上的语义,一对一地映射到 verifier 已经在检查的 eBPF 指针类型操作上。不忠实的 lowering
会破坏 safety transfer。

## State Model

有两套状态要分清:**验证侧**(eBPF `B_{I,P}` 怎么向 verifier 表示目标机器状态)
和**运行侧**(P 裸跑时 CPU 上的真实状态)。两者必须忠实对应,这就是 safety transfer 的
承重墙在状态层面的体现。

以 x86 为例:

| Native 状态 | 验证侧(verifier 可见,在 `B_{I,P}` 里的表示) | 运行侧(P 裸跑时的真实状态) |
|---|---|---|
| `rax`、`rdi`、`rsi`、`rdx`、`rcx`、`r8`、`rbx`、`r13`、`r14`、`r15` | 映射到 BPF 寄存器或 stack-slot 寄存器供 verifier 跟踪类型 | **就是真实的 x86 寄存器** |
| 额外寄存器如 `r10`、`r11`、`r12` | 目标寄存器文件区域里的固定 stack slot | **就是真实的 x86 寄存器** |
| flags / 条件状态 | 显式的 scalar shadow 状态供 verifier 推理 | **就是真实的 x86 flags** |
| 程序内存访问 | 经 verifier 检查的 BPF 指针操作 | **就是 P 的 native load/store** |

"验证侧"那一列是 `I` 为了让 verifier 能跟踪类型/边界而对 native 状态做的 eBPF 编码;
"运行侧"那一列是 P 裸跑时的真实机器状态 —— **没有 eBPF JIT、没有 stack-slot 寄存器文件**。
`I` 的忠实性要求:证明侧对每个状态位的可观测操作,与运行侧 P 真实做的操作逐一对应,否则
verifier 证的状态和 CPU 跑的状态对不上,safety transfer 断裂。

## Boundary Rules

困难的不是算术指令。困难的是观测边界(observation boundaries)。

下列操作需要显式的 lowering 规则:

- helper 调用;
- kfunc 调用;
- tail call;
- exit 与返回值;
- 栈指针逃逸;
- map、packet、ctx 和 dynptr 访问;
- 分支以及分支目标重定位;
- 跨指令边界的 native flags;
- callee-saved 和 caller-clobbered 的 native 寄存器;
- native 内存操作的异常或 fault 行为。

安全规则是:**P 里任何能观测状态或越出忠实解释器模型的操作(helper/kfunc 调用、栈逃逸、
对外暴露指针等),都必须在 eBPF 表示里被显式表示成 verifier 能检查的形式,且该表示要与
native P 实际做的事忠实一致;无法忠实表示的程序形态必须被拒绝(分析不通过)。** 否则会出现
"verifier 分析的过程"和"裸跑 P 的过程"分叉,safety transfer 断裂。

例如,P 把某个寄存器值当指针传给一个 kernel helper:eBPF 表示必须把这一步表示成一次真正的
helper 调用、且让 verifier 检查该指针的类型/边界 —— 而不是把它当成不透明 scalar
绕过去。如果这一步与 native P 实际传给 helper 的东西不一致(比如 eBPF 表示先 materialize
了一份安全的副本,而裸跑的 P 传的是原始越界指针),verifier 通过了、P 却越界,等价就断了。
所以这类边界要么忠实表示并交 verifier 检查,要么拒绝该程序。

## 备选路径:kernel-ABI 双语义 ISA

idea #3 更早的一种 framing 把双语义放进内核里:每条 NativeBPF 指令同时拥有一个 verifier
可见的 `instantiate_insn()` lowering 和一个按架构区分的 native emitter,二者都归内核 ABI
所有。这个 framing 已被降级为备选路径,因为它与 idea #2(Kinsn,整程序泛化)有显著重叠。

为完整起见在此记录:

```c
struct reversesim_insn {
        int (*instantiate_insn)(payload, struct bpf_insn *buf);
        int (*emit_x86)(payload, ...);
        int (*emit_arm64)(payload, ...);
};
```

`instantiate_insn()` 是 verifier 的 source of truth。native emitter 是执行层面的精化。
verifier 路径把 NativeBPF 指令 lower 成普通 BPF 语义并检查结果程序。JIT 路径则改为 emit
native 语义。

要让它成为一个整程序 substrate 而不是 peephole 机制,内核接口还需要:

- 分支感知的 proof lowering,而不只是局部 proof 序列;
- 一种在 kinsn 展开中编码或重定位程序级分支目标的办法;
- region 级的隐藏状态布局;
- 针对 call、tail call、exit 以及 helper 可见栈状态的显式 boundary adapter;
- 按架构区分的、针对隐藏 native 寄存器的寄存器分配和 save/restore 规则。

这本质上就是 kinsn(idea #2)从 peephole 泛化到整程序 substrate。如果项目以后发现值得做,
它属于 kinsn 论文线,而不是本篇。上面的 simulator 和 JIT 变体把内核暴露面保持在接近零,
仍然是 idea #3 的核心。

## 相关工作定位

### 主对比:扩展内核的三条路(安全 × 高效)

NativeBPF 的主战场是"如何安全高效地扩展内核",所以最直接的对比是现有三条路:

- **eBPF(系统本身)** [Linux kernel; bpftime / llvmbpf 等用户态运行时]:同样靠 verifier
  对不可信作者独立保证安全,但执行 eBPF-JIT 产物、背 codegen 惩罚,且表达力受 verifier 限。
  NativeBPF 与它**同安全、同表达力上限,但裸跑 native** —— 把 idea #1 / llvmbpf 追的
  30–40% 差距直接抹掉(不是优化 eBPF codegen,而是根本不执行 eBPF)。
- **Rust-for-Linux**:编译到 native、安全靠语言类型 / borrow checker。关键区别:Rust 是
  **编译期、信任工具链 + `unsafe`** 的安全,**不对一个不可信二进制做独立 load-time 验证**;
  NativeBPF 保留 eBPF 的"untrusted producer, trusted checker"性质。代价是 NativeBPF
  表达力受 verifier 限,而 Rust 无限。
- **裸内核模块 (C)**:native、表达力无限,但**零验证、完全信任作者**。NativeBPF 在
  verifier 可表达的范围内提供同样的 native 速度,但不要求信任作者。

一句话:**eBPF 不 native、Rust 信任编译器而非独立验证、模块没验证 —— NativeBPF 补上三者
缺的那一角(native + 对不可信作者独立验证)。**

**更广的安全内核扩展谱系(摆位用,非同类竞品)**:让内核扩展更安全有一整片设计空间,
按**两条轴**摆最清楚——**①安全何时强制**(静态验证完就裸跑 vs 运行时持续强制)×
**②是否信任作者**(信编译器/工具链 vs 不信任、直接管住二进制):

| 阵营 | 代表 | 何时强制 | 信任作者? | 代价 |
|---|---|---|:---:|---|
| **静态验证(不信任作者)** | eBPF verifier、**NativeBPF**、PCC/TAL | 静态,过后裸跑 | **否** | 表达力受 verifier 限 |
| **语言级(信任编译器)** | Rust-for-Linux、SafeDrive(OSDI'06)、Singularity(OSR'07) | 编译期 | 是(信工具链+`unsafe`) | — |
| **SFI(软件运行时检查,不信任作者)** | Wahbe(SOSP'93)、NaCl、RockSalt、XFI(OSDI'06)、BGI(SOSP'09) | **运行时**(改写+插 check/mask) | **否** | **每访问运行时开销 + 代码被改写** |
| **硬件/页表/MPK 隔离** | Nooks(SOSP'03)、Mondrix(SOSP'05)、MOAT/Hive(MPK,Sec'24) | 运行时 | 否 | 运行时开销 |
| **硬件 capability** | CHERI(S&P 多年) | 运行时 | 否 | 需特殊硬件 |

(外加裸内核模块 = 完全信任、零安全。)

**NativeBPF 与 SFI 是最尖锐的对照**:两者**都不信任作者**(同属"管住二进制"而非"信编译器"),
但强制方式正相反 —— **SFI 靠二进制改写 + 运行时插 check/mask(代码被改、每访问付开销);
NativeBPF 靠静态验证一次,然后裸跑未改动的 native(运行时零插桩、零隔离开销)。** 这比
"native vs eBPF-JIT"更能凸显 NativeBPF 的独特性。

NativeBPF 独占的格子:**静态 + 独立(不信任作者)验证 + native 速度裸跑、运行时无开销** ——
语言级路线信任编译器、SFI 与硬件路线都付运行时代价,都没占这一格。(SFI 各系统作为机制的
具体对照见下方[机制谱系](#机制谱系次要对比本工作的技术血缘)。)

### 机制谱系(次要对比:本工作的技术血缘)

下面这些不是"扩展内核"的同类竞品,而是 NativeBPF 机制(把 native 经一个可信 lowering 交给
一个独立 checker、再裸跑 native)的技术血缘与对照。

一个常被联想、但必须明确区分的对照是 proof-carrying code:

- George C. Necula 和 Peter Lee,"Safe Kernel Extensions Without Run-Time
  Checking",OSDI 1996。

PCC 让 native 代码**附带**一份显式 proof 证书,一个轻量 checker 去**校验**证书。
**NativeBPF 不是 PCC**:它不携带任何 proof,被喂给 verifier 的是一个特化到 P 的忠实
解释器,而 stock eBPF verifier 用自己的 abstract interpretation **推断**安全性 —— 不是
在校验一份证书。所以 PCC 是对照,不是本工作的归属。

Translation validation(翻译验证)与之相关:它可以验证按程序的特化保持了源语义,或者
验证一个手写 JIT 忠实地实现了目标 ISA。

Native Client、RockSalt 以及 native 机器码 validator 通过**直接**验证或约束 native 机器码
来安全执行 native 代码 —— 它们也裸跑 native,但 checker 是为该 ISA 专门构造的。NativeBPF
同样裸跑 native P,但**不专门造 checker**:它把"P 安全吗"经一个忠实解释器特化成 eBPF,复用
stock eBPF verifier 当现成的安全分析器。SFI(software fault isolation)的源头是 Wahbe 等人
(SOSP 1993),它靠二进制改写 + inline check 约束 native;NativeBPF 不改写、不插 check,
而是用 verifier 的抽象解释证明原样的 P 已经安全。

**WebAssembly 沙箱一条线是 NativeBPF 最近邻的 prior work,结构完全同构**:把不可信代码
编译到一个可被安全检查的 IR,再 lower 成 native。Provably-Safe Multilingual Software
Sandboxing using WebAssembly(USENIX Security 2022)把多语言代码编译到 Wasm 当可安全检查
的 IR;VeriWasm(USENIX Security 2021)验证 Wasm→native 编译保持 SFI;RLBox(USENIX
Security 2020 / Firefox 95)把不可信库编译成 Wasm 再编 native,在同地址空间安全共享。
两者结构同构:Wasm 沙箱是"untrusted → 可信编译成 safe IR → checker 通过 → 跑(JIT 后的)
native";NativeBPF 是"native P → 经忠实解释器特化成 eBPF → stock verifier 安全分析通过 →
**裸跑原生 P**"。关键区别两点:① NativeBPF 不引入新 IR、不引入新 checker,直接复用内核
已有的 eBPF verifier,处理的是 native ISA(x86/arm64)而非 Wasm 这类天生为沙箱设计的 IR;
② **被执行的是原生 P 本身,eBPF 不被执行**(Wasm 路线执行的是 Wasm→native 的产物)。

经验证的 eBPF JIT 工作(Jitterbug、Serval、K2)证明的是一个 eBPF JIT 保持 eBPF 语义。
NativeBPF 是其对偶:它要保证的是一个 native↔eBPF 的忠实等价(让 verifier 对 eBPF 的
安全结论能转移到裸跑的 native);注意它**不执行 eBPF、不依赖 eBPF JIT**。Jitk(OSDI 2014)
对"把可信 lowering 写成可验证
组件"这点更贴:它形式化验证地把高层规则编译到 cBPF 加 machine code。RIOT 微控制器内核上
的 eBPF interpreter+verifier(CAV 2022)与 JIT(CAV 2024)端到端机器证明,则是"对一个
具体 eBPF interpreter/JIT 做整体机器证明"的现成范例,支撑本文 Trust Model 里"simulator
`I` 可被形式化验证一次"的可行性主张。

**直击核心难题的 prior work**:NativeBPF 的承重墙是"忠实解释器 `I` 的建模语义 == 真实 CPU
执行 P 的语义"。
- **Islaris: Verification of Machine Code Against Authoritative ISA Semantics(PLDI 2022)**
  —— 把 native 机器码**对照权威完整 ISA 规格(ARMv8-A / RISC-V)**做验证。这正是 `I` 忠实
  等价该用的现成方法论,是这条 idea 最该正面引用、对标的工作(⚠️ must-cite)。
- **Formally Verified Native Code Generation in an Effectful JIT(POPL 2023)**:把 CompCert
  后端扩到 JIT 场景、在 Coq 里证明**动态生成 native 代码**的正确性 —— 对应"如何在没有
  compile-time 全验证时保证动态 lowering 正确"。

可复用的可信 ISA 规格包括 Sail 对 arm64 和 RISC-V 的机器可检查语义,以及 ARM 官方的 C
reference simulator。这些都是可信 simulator `I` 的候选来源。

## 论文 framing

系统层面的主张:

```text
Kernel extension forces a safety/efficiency trade-off: modules are fast but
unverified, eBPF is verified (against an untrusted producer) but pays a codegen
penalty, and Rust-for-Linux is fast but its safety is compile-time and trusts the
toolchain rather than independently checking an untrusted binary. NativeBPF hits
the missing corner — native-code efficiency with eBPF-verifier safety that holds
against an untrusted producer — by running the native extension directly while the
stock eBPF verifier certifies it via a faithful, once-verified ISA simulator. The
extension runs native (no eBPF execution, no lowering); the eBPF is only what the
verifier analyzes.
```

可能的标题:

```text
Making Kernel Extensions Safe and Efficient with an eBPF Simulator
```

要成为一篇有分量的系统论文,评测需要:

- **主对比矩阵**:在同一组扩展上对比 eBPF / Rust-for-Linux / 裸内核模块 / NativeBPF,
  沿"性能(吞吐 / 延迟 / 指令数 / cache)× 安全(对不可信作者是否独立验证)× 表达力"摆位;
- 性能就是 native x86/arm64(P 裸跑,无 eBPF 执行)——相同语义下**严格优于** eBPF-JIT 产物
  (那 30–40% 差距是 idea #1 / llvmbpf 在追的),并接近裸模块 / Rust;
- 安全:对不可信作者的独立 load-time 验证(模块没有、Rust 是编译器信任),并给出
  verifier 自然拒绝不忠实 / 不安全程序的失败案例;
- TCB 核算:相对模块(全信任)、Rust(信任编译器 + unsafe)、eBPF,NativeBPF 净增的信任
  只有"一个 per-ISA 可一次性验证的忠实 simulator";
- 覆盖面:广泛的目标 ISA 与真实扩展(把现有 eBPF app 用该路径重表达,量化 verifier 受限
  排除掉多少真实程序);
- 忠实等价(simulator ↔ CPU)的可形式化 / 可对 oracle 验证程度 —— 这是 native 执行声明的
  核心代价。

## 主要风险

这个 idea 可行,但风险很尖锐:

- 如果 clang 不能可靠地坍缩特化后的 dispatch,verifier 看到的产物就是一个通用 simulator,
  过不了 verifier。这是单个最大的开放问题。
- 如果在现实目标程序规模下展开产物超出了 verifier 的复杂度预算,实际覆盖面会急剧缩小。
- 如果目标程序内部的间接控制流无法归约成一个有界的 PC-keyed switch,程序会被拒绝;这会
  排除多少比例的真实程序,尚不清楚。
- 如果指针类型的目标寄存器在众多 handler 间引起 SCALAR/PTR 状态爆炸,verifier 的接受度
  会变得不稳定。
- 如果 helper/kfunc 识别表与运行中的内核失去同步,特化会把调用 lower 错;识别这一步必须
  针对运行中的内核重新生成,不能跨内核版本缓存。
- 如果可信 simulator 或 JIT 又大又 ad hoc,TCB 的论述就会变得困难;针对机器可检查的 ISA
  规格做形式化验证是缓解办法。
- 如果只覆盖目标 ISA 的一个小子集,结果看起来就像又一个 peephole 机制,而不是一条运行
  native 程序的路径。

因此最强的版本是保守的:

```text
NativeBPF executes the user's native program P directly. The eBPF artifact is
never executed — it is only what the verifier analyzes. A once-verified, faithful
(no-sanitization) ISA interpreter, specialized to P, turns "is P memory-safe?"
into an eBPF program that the stock eBPF verifier accepts or rejects via its
ordinary abstract-interpretation analysis. Verifier acceptance, combined with the
interpreter's faithful equivalence to the ISA, certifies that running P natively
stays within eBPF's memory/pointer/control-flow policy. The eBPF verifier is
reused as an off-the-shelf safety checker (not a proof checker — nothing is
carried or certificate-checked); P runs with no lowering.
```

这正是它与传统 proof-carrying code、以及 kernel-ABI 变体(那个与 kinsn 重叠)二者的关键
区别。

## 附录 A:原始讨论记录(2026-05-17)

以下是讨论该 specialized eBPF simulator variant 的原始对话记录,原文保留,
未做归纳或措辞调整。出于隐私考虑不标注具体发言者,按时间顺序呈现。

> 这里核心的问题是"simulator 对目标程序的解释执行"通过验证器的检查,并不能
> 说明目标程序真的安全,比如目标 native 程序里的一个 oob,可能不会导致
> simulator 的 oob,除非这个目标程序自己是 sanitized 的(插了安全检查)。

> 这个感觉很酷哈哈,但是可能不好实现

> 工程来说 这个 simulator 可能需要用到很多 bpf 的 hack,不过应该是 feasible

> 对,我们不仅仅要让 simulator 通过验证器的检查,实际上还要形式化验证这个
> simulator/JIT 是完全等价于 x86 指令的

> 目前看来....我今天试了试,确实不太好做

> 甚至可能 JIT 反而更好做一点

> 假如不能信任 clang 的编译(应该是不能?),那么我们要形式化验证 simulator/JIT
> 大概率要手写指令集转换的?

> 那写一个 x86 的 JIT,把 x86 指令 emit 成一段 bpf 指令序列反而还更方便一点...

> 也不容易因为状态爆炸导致过不去验证器

> 目前的 kinsn 基本上能表达大多数,但是跳转指令不好搞

> 因为跳转指令需要被 verifier 和 jit relocation

> register 可以,目前来说我们可以把栈的一部分当作 register

> 如果放宽一点,信任 clang 的编译的话会方便不少(我不确定这样可以被接受嘛,
> 你觉得呢 @sunhao

> 信任 clang 的话我基本上写出来 simulator 了

> 另外我在想干脆 rejit 不改 kernel 了

> map inline 还有一套确实有效果

> 至少 katran 比如说能 100ns -> 50ns

> 效果还是挺明显的

> 之前的问题在于 bpf runcnt 测量方法开销太大了,每次运行平均 30-50ns 开销,
> 导致不能用

> 这里是指信任 clang 编译的 simulator (in bpf bytecode)?我有点 confused

> 是的,信任 clang 编译的 ebpf simulator 的编译过程正确

> 这样我们形式化验证 c 写的 ebpf simulator 正确就好了?

> 然后我们再把 c 写的 ebpf simulator 加上对应的 x86 指令给 ebpf verifier,
> 等于我们让 ebpf verifier 去 verify "正确的 simulator 执行这几条 x86 指令的
> 过程"

> X86 simulator 到 ebpf bytecode 编译的等价性可以假设

> 只要 ebpf verifier 确认"正确的 simulator 执行这几条 x86 指令的过程"是
> 安全的那就安全了

> 那就简单啦 x

> 对 核心的问题就是我刚刚提到的那个

> 这里

> 如果目标程序不插检查它就通不过 ebpf verifier 了,因为这样的话会导致 simulator
> 解释的过程中出现越界访问?

> 说起来你会去 sosp 和 linux plumber 吗

> 我可能会去 sosp

> Plumber 不一定,不过下周末到西雅图

> 这两个在一起

> 一个城市,隔一两天好像

> 不过今天讨论的这个如果是 simulator 其实变成又和 kinsn 不一样的 idea 了(?

> 确实在一个地儿 我都没注意到

> X86 Simulator 视角没有 oob,所以我说目标程序的 oob 可能不会体现为
> simulator 的 oob

> verifier 不能只 verify simulator(图灵完备的不停机 simulator 也过不了
> 编译器),verify 的一定是"正确的 simulator 执行这几条 x86 指令的过程"

> 所以目标程序的 oob 一定会在执行的过程中体现为 simulator 的 oob

> 就是这个 simulator 在执行的时候的某一个步骤会去越界访问 packet 之类的,
> 因为它的执行会是和 native insn 完全一致的

> simulator 本身感知不到 oob 也不会去检查,它就是个单纯的翻译器

> 感觉是不一样的目标不一样的实现流程 x

> 解决的问题也会不一样,一个的出发点是怎么把 ebpf 变得更快,现在说的出发点变成,
> 如何直接跑 native insn 还能保证安全

> 其实经过 clang 的常量传播,实际上验证器验证的就等于 kinsn 展开的 bpf insn
> proof format

> 经过常量传播就等于把 x86 jit 成 ebpf 然后验证 ebpf

> 但是还是执行 x86

> 经常编译需要个几分钟

> I see,合理

> 加了 simulator 这一层以后,不知道会增加多少验证难度

> 不过感觉这个 idea 挺疯狂的哈哈,不错

> kinsn 实现太复杂了...主要是最后涉及 register 和 jmp,还得全局 relocate

> 也就是,如果我们想要做类似的事情,验证 kinsn 会更难(因为等于直接验证 jit
> compiler,不如直接验证 simulator)

> x86 simulator 也很复杂

> 确实 dan 提出来一个问题,我们怎么选择了 kinsn 的?是不是看看 native code
> 产物?然后我根据 native code 逐步加 kinsn,直到加了七八十个,然后我发现既然
> 大多数 insn 都有了那为啥不能直接跑 native code 得了

> simulator 可以想象成 native 指令对应的 eBPF 指令序列的 map

> 一个具体的程序可以想象成一系列 index

> Verifier 通过 lookup 找到 native 程序对应的语义,然后进行验证

> 但是 kinsn 跑 native code 我发现 jmp 很难解决,register 分配也很麻烦。。。

> 是这样的,目前就是这样做的

> 我实现了一个 poc 了

> 这个没法从零做,需要在 LLVM 加深度支持,从零 agent 一定会犯很多错

> '看看 Claude 写的 C compiler 有多少 bug 就能想象'

> 是的....今天折腾了一天发现 kinsn 完全覆盖 x86 走不通,太难了

> 而且还是改 kernel module

> Simulator 应该可以基于现有的改

> 我感觉让 agent 自己写可能也就几百行?而且可能更容易 hack 一下通过 ebpf
> verifier

> 另外 abi 要对齐

> 然后也可以用已有的 eBPF self tests 当作 oracle

> 让 agent 一直改

> 嗯

> 主要指令太多了

> 确实

> arm 可能好点

> 从零写 语义不一定对

> arm / riscv 估计也能不少加速,和 x86 不一样,估计加速主要在 reg 分配上面

> 最好基于 reference simulator,适配到能编到 eBPF

> ARM 应该有官方的 C simulator

> 有什么别人已经形式化验证过了的吗

> https://github.com/rems-project/sail

> 直接从 formal semantics 生成 simulator

> 不过可能太复杂了,作为 poc 也可以假设已有的是对的

> 感觉这样等于有三个 idea 各自解决一个不那么一样的问题了(

> 实现也不一样

> 虽然实验可能差不多

> 都可以拿 ebpf app 跑跑测试性能

> 今天讨论这个虽然可以说解决的不是 ebpf 的问题,但是实际上如果依赖 ebpf
> verifier 实现的话还是要遵守 ebpf 的 abi,验证也只会更严格

> abi(kfunc/helper/pseudo call) 确实是个问题,在 simulator 层面对应改 pc,
> 但在 eBPF 需要触发 verifier 对应的 call check

> 需要做对应的 abi 转换

> 让 kernel compile ebpf 之后 dump 出来 jitted code,我们就获得了所有 call
> 的地址

> 然后我们在用这些绝对地址 link 一下就好了

> 也几乎不用改内核

## 附录 B:三条思路在 project 内的定位

```text
1. Speculative optimization of eBPF
   定位: pure userspace tool for runtime optimization opportunities in eBPF
   关键技术: live discovery / atomic-or-near-atomic prog swap /
            map_inline + const_prop + dce 等纯 BPF-to-BPF rewrite
   内核改动: 接近零(取决于具体 attach 类型的 swap 能力)
   形式化对象: 每个 pass 的 BPF-to-BPF 重写正确性
   解决的问题: 已加载的 eBPF 程序在运行时上下文变化(map 内容、profile)后
              错失的优化机会

2. Kinsn
   定位: new OS abstraction for eBPF optimization,
        brings eBPF closer to hardware
   关键技术: 双语义 kernel-defined 指令(instantiate_insn + native emit) +
            可能的 LLVM backend / userspace optimizer 支持
   内核改动: 中等(verifier + JIT + 每条 kinsn 的 proof + relocation)
   形式化对象: 每条 kinsn 的 verifier 语义和 native emit 的等价性
   解决的问题: 让 eBPF 能表达更接近硬件的操作而不放弃 verifier 保证

3. NativeBPF (本 doc)
   定位: making kernel extensions safe AND efficient via an eBPF simulator;
        native 性能 + eBPF-verifier 级、对不可信作者也成立的独立验证
   关键技术: 特化的忠实 eBPF simulator(主线) 或 native-to-eBPF translator;
            verifier 当独立安全检查器,裸跑 native(eBPF 不执行、无 lowering)
   内核改动: 接近零(执行 native P 的路径除外)
   形式化对象: 单个 C simulator 与目标 ISA 的忠实等价(净增唯一 TCB)
   解决的问题: 内核扩展的安全 × 高效三难 —— 模块快但不安全、eBPF 安全但有 codegen 惩罚、
              Rust 快但安全靠信任编译器而非独立验证;NativeBPF 补缺的那一角
   主对比: eBPF 系统本身 / Rust-for-Linux / 裸内核模块
   诚实边界: 表达力仍受 verifier 限 → 是 "native-speed eBPF for untrusted extensions",
            不是 "在内核跑任意 native"

实验设置: 三条都使用同一套 ebpf app benchmark / micro 套件 / 测量基础设施
```

这三条不是 incremental 三个版本,而是三个独立的设计点,各自针对的"待解决问题"
不重合。Project 共享 corpus、measurement infra、kernel build,论文层面拆开。
