# ReverseSim 研究笔记

状态:研究方向

## 项目背景:三个姐妹 idea

本研究项目产出三篇彼此独立的论文,它们共用同一套评测设施(`bpf-benchmark`
corpus、micro 套件和测量基础设施),但用不同的设计和实现解决不同的问题。

| # | Idea | 问题 | 设计核心 | 内核改动 |
|---|---|---|---|---|
| 1 | **Speculative eBPF optimization**(投机式 eBPF 优化) | 已加载的 eBPF 程序错失了那些只有在程序上线后才可见的优化机会(map 内容稳定下来、分支 profile 浮现、helper 调用模式显现)。 | 纯用户态工具:观察运行中的程序,施加 BPF-to-BPF 重写 pass(`map_inline`、`const_prop`、`dce`、`bounds_check_merge`、`branch_flip` 等),再用 stock 内核的原子或近原子 attach 更新机制换入优化后的候选程序。 | 接近零。 |
| 2 | **Kinsn** | eBPF 指令集离硬件太远,无法表达若干 native 等价的优化(rotate、conditional select、BMI 位域提取、BLS 指令、prefetch)。 | 一个新的 OS 抽象:内核定义的双语义指令,以 kfunc 机制的 `KF_KINSN` 特化形式实现。verifier 把一个声明式 effect(`model_call` → `bpf_kinsn_effect`)施加到它的抽象状态上,JIT 则分派到内核模块提供的、按架构区分的 `emit_x86()` / `emit_arm64()` 回调。用户态优化器(`bpfopt`)负责识别候选模式。 | kinsn 框架 patch + 各架构模块,TCB 增长但有界。 |
| 3 | **ReverseSim**(本文档) | 在内核里安全地运行任意 x86/arm64 native 代码,且不要求开发者写 eBPF、也不要求另外提交一份 proof。 | 用 eBPF C 写一个目标 ISA 的 simulator(或一个 emit eBPF 的 JIT)。针对某个具体目标程序做特化,会把 simulator 坍缩成 straight-line eBPF,由 stock verifier 检查。随后内核 JIT 把它 lower 成 native。 | 接近零。 |

这三者不是同一个设计的递进版本。每个各自挑了一个不同的问题、一个在 trust /
内核暴露面 / 覆盖面空间里不同的位置。本文档讲的是 idea #3。idea #1 在
`docs/rejit-speculative-optimization-ebpf_idea.md`,idea #2 在
`docs/kinsn_idea.md`(机制设计见 `docs/tmp/kinsn-design.md`,形式语义见
`docs/tmp/kinsn-formal-semantics.md`)。

"ReverseSim" 还有一个 kernel-ABI 变体(由内核拥有的双语义 ISA),那是 idea #3
更早的一种 framing。它和 idea #2 重叠很大,现在只作为一条备选路径记录在
[备选路径:kernel-ABI 双语义 ISA](#alternative-path-kernel-abi-dual-semantics-isa)
一节。

## 核心思想

ReverseSim 用 C 写一个目标 ISA 的 simulator 或 JIT,用 clang 编译成 eBPF,然后
让现有的 eBPF verifier 去检查结果。内核不需要学一套新 ISA,不新增 syscall,也不
承载任何新的 emit 路径。

```text
target native binary (x86 or arm64)
  -> compile-time specialization of a trusted simulator or JIT written in C
  -> eBPF program
  -> stock kernel verifier accepts (memory, pointers, calls, control flow)
  -> stock kernel JIT lowers to native
  -> native execution
```

一句话概括:

```text
ReverseSim brings native code into the eBPF safety model by
treating an eBPF-written simulator (or JIT) as the trusted lowering and the
stock eBPF verifier as the safety checker.
```

用户并不向内核提交 native 代码。用户提交的是 native 代码经过特化后的 eBPF 表示。
内核里的 native 机器仍然只执行 stock JIT emit 出来的东西。

这个 idea 内部有两种实现策略:

- **ReverseSim**:一个用 C 写的目标 ISA simulator,通过 clang 的常量传播针对单个
  目标程序做特化。编译很快(每个程序一次特化,而不是每次 load 跑一遍 LLVM)。详见
  [机制](#mechanism)。
- **ReverseSim-in-eBPF**:一个用 C 写的 native-to-eBPF JIT,编译成 eBPF,离线针对
  目标程序运行以 emit 出 eBPF 产物。产出的 eBPF 由 stock verifier 检查。JIT 本身只
  需验证一次;每个程序的使用就只是跑一遍这个 JIT。trust profile 与 simulator 变体
  相同。

两者都用 eBPF 写成,都依赖同一套 safety transfer 论证。区别只在于特化是 clang 的
活(simulator 变体)还是显式 emitter 的活(JIT 变体)。

## 它不是什么

它不是传统的 proof-carrying code(PCC)。

在经典 PCC 里,用户提交 native 代码外加一份 proof。内核检查 proof,然后不带运行时
检查地运行 native 代码。ReverseSim 不要求用户提交 proof。用户提交的是由一个可信
lowering 产出的 eBPF 程序,而现有的 eBPF verifier 就是 proof checker。

```text
PCC:
  user native code + user proof
    -> proof checker
    -> native execution

ReverseSim:
  user native program
    -> trusted lowering (simulator or JIT, both written in eBPF)
    -> eBPF
    -> stock eBPF verifier
    -> stock JIT
    -> native execution
```

它也不是"相信我,这段 native blob 等价于那段 eBPF"。在内核里运行的 native 代码
路径,是 verifier 接受过的某个 eBPF 程序经内核 JIT emit 出来的 lowering,而不是
用户提交的 native blob。

它也不是任意 native 二进制的执行。如果目标程序有真正无法翻译的行为(对一个无法识别
的内核地址做计算型间接调用、用运行时数据构造的、目标集合无界的跳转表、不支持的 SIMD
指令),特化会失败,程序在到达 verifier 之前就被拒绝。

## 与 kinsn 的关系

Kinsn(idea #2)和 ReverseSim(idea #3)从相反的两端攻击同一个底层问题——如何让
非平凡的 native 操作在 eBPF 安全模型内变得可用:

- Kinsn 用内核定义的双语义原语扩展内核侧的指令集。每个新原语都让内核 TCB 小幅增长。
- ReverseSim 用一个经过验证的 simulator 或 JIT 扩展用户态侧的 lowering。内核保持不变。
  新增的 TCB 是一个用户态产物:每个目标 ISA 一个 C 文件,可独立验证。

Kinsn 覆盖的是"普通 eBPF 表达不好的少数几种模式"。ReverseSim 覆盖的是"目标 ISA 能
表达的任何东西,只要其 lowering 对 verifier 可处理"。两者并不互斥:一个支持 kinsn 的
内核,配上一个在有益处时 emit kinsn 的 ReverseSim,是一个自然的 ablation 点,但二者
互不依赖。

## 机制

本节给出 ReverseSim 变体的规格。ReverseSim-in-eBPF 变体使用相同的 lowering 规则,
但由一个显式 emitter 来执行,而非依赖 clang 特化;见
[ReverseSim-In-eBPF 变体](#reversesim-in-ebpf-variant)。

### 按程序特化

用 C 写一个目标 ISA 的 simulator。对每个用户程序:

1. 目标 native 二进制被当作数据:一个 native 指令数组加一个入口 PC,二者在特化后的
   源码里都是 `static const`。
2. simulator 在编译期针对这份数据做特化。由于从编译器的视角看指令数组是常量,clang
   的常量传播和 switch-table lowering 会把 dispatch 循环展开成一串 straight-line 的
   逐指令 handler。
3. 内核 eBPF verifier 看到的是一个对 verifier 可处理的 BPF 程序:没有无界循环,没有
   对运行时可变 opcode 的间接 dispatch,只是一长串小小的 handler 体。
4. 内核 eBPF JIT 执行这个程序。尽管名字叫 "simulator",实际运行时路径是 straight-line
   的逐 handler native 代码,没有 dispatch 开销,形态等价于把目标指令直接翻译成 eBPF。

当特化是在编译期而非运行时完成时,"源码侧是 simulator、运行时侧是 JIT" 其实是同一条
代码路径。simulator 是语义规格说明;verifier 看到的产物是它针对单个程序的特化。

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

安全性通过一个 refinement(精化)论证,从 eBPF verifier 传递到被执行的行为:

```text
target native program P
  -> compile-time specialization of trusted simulator I to P
  -> result is eBPF program B_{I,P}
  -> verifier accepts B_{I,P}
  -> kernel JIT executes B_{I,P} as native code
```

在内核里运行的是经现有 eBPF JIT lower 后的 `B_{I,P}`,而不是原始目标二进制 `P`。
native 机器仍然只执行内核 JIT 的输出。用户根本不提交 native 代码;用户提交的是特化后
的 eBPF 表示。

`P` 里的越界以及其它不安全行为,无法藏在 simulator 抽象的背后。如果 `P` 越过 packet
末尾读取,对应的特化后 eBPF load 也会用相同的有效地址越过 packet 末尾读取,verifier
会把它当作 packet 指针违规拒绝掉。simulator 不做任何掩码、边界插入或 sandbox 调整:
它是把 native 语义忠实地 1:1 lower 成对内核已经在检查的同一批指针类型的 eBPF 操作。

一个微妙之处:这个论证依赖于内存访问是一对一翻译的。间接控制流需要一个显式的、对
verifier 友好的形式(PC dispatch)。其它 verifier 无法直接建模的指令(例如宽向量操作、
专用 CPU 指令)必须要么用 helper/kfunc 调用表达,要么在特化这一步被拒绝。

### 信任模型

这个 idea 把信任依赖转移到了:

- simulator `I` 的 C 源码;
- clang 把 `I` 编译成 eBPF 的过程。

simulator `I` 很小、每个目标 ISA 固定一份、且适合做形式化验证。simulator 语义的可能
来源有:

- 一个手写的 reference simulator,做一次形式化验证;
- 从机器可检查的 ISA 规格生成的 simulator(例如 Sail,`github.com/rems-project/sail`);
- ARM 发布了一个官方 C reference simulator,可作为 arm64 变体的起点。

clang 的编译正确性,正是现有 eBPF 生态对每个 BPF 程序都已经接受的那同一份信任依赖。
它不是一个新的 TCB 组成部分。

### 为什么它在运行时并不是真的 simulator

朴素的理解:这不过是个软件 simulator,会很慢。

精炼的理解:这是一个编译期 partial evaluator(部分求值器)。用户的程序是静态输入;
残差(residual)是 straight-line eBPF,由现有内核 JIT lower 成 straight-line native
代码。运行时开销与一个经过验证的 native-to-eBPF 翻译器直接 emit 出那段 eBPF 完全相同。
那个 "simulator" 是特化的语义锚点,而不是运行时的形态。

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
| 内核侧改动 | ~0 | 使用 stock verifier + JIT |

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
特化 simulator,并验证(a)clang 产出一个无 dispatch 的 eBPF 程序,(b)内核 verifier
接受它,(c)内核 JIT 把它 lower 成指令数量相当的 native 代码。

### ReverseSim-In-eBPF 变体

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
Any ReverseSim program accepted by the existing eBPF
verifier is safe under the same memory, pointer, helper, and control-flow
policy as ordinary eBPF, provided the lowering from target native code to eBPF
is a faithful 1:1 translation of native semantics into operations on the same
pointer types the verifier already checks.
```

在本模型下,内核不接受任意的 x86 或 arm64 blob。native 执行之所以安全,仅仅是因为每个
可执行操作都是 verifier 接受过的某条 eBPF 指令经 eBPF JIT lowering 的产物。

用户或编译器都可以产出这份 eBPF 产物,但产出者在安全性上并不被信任。被信任的部分是:

- 现有的 eBPF verifier;
- 现有的 eBPF JIT;
- 用 C 写的 simulator 或 JIT(每个目标 ISA 一份);
- clang 把那份 C 源码编译成 eBPF 的过程。

## Safety Transfer 论证

最强的安全性论证是一个 refinement(精化)论证:

```text
native program P
  -> lower(P) via simulator or JIT I = eBPF program B
  -> verifier accepts B
  -> trusted equivalence: B faithfully models the native semantics of P
  -> kernel JIT executes B; native machine runs JIT output
```

如果 verifier 证明了 `B` 安全,且可信等价性表明 `B` 的每个可观测行为(内存访问、helper
调用、控制流)都与 `P` 的对应行为相同,那么执行 `B` 所表现出的,恰好是 `P` 行为中安全
的那个子集:

```text
safe(B) and B models P faithfully => safe(execute(B)) and execute(B) ~ P
```

native 代码并不是因为某个独立的 ReverseSim 被验证过才变安全的。它变安全,是因为内核 JIT
运行的是 verifier 接受过的那个 eBPF 程序,而该 eBPF 程序在构造上就是用户意图中那个 native
程序的忠实模型。

有几种可能的绑定方式:

- 特化 simulator(本文档的主线情形):simulator 是可信 lowering;
- eBPF 里的显式 JIT:JIT 是可信 lowering;
- 可信的经验证翻译器:一个带机器可检查正确性证明的翻译器是可信 lowering;
- certificate 检查:用户态提交 `P`、`B` 以及一份等价性 certificate,内核在执行 `B` 前
  检查它。

什么不是安全边界:

```text
userspace submits safe B
userspace also submits arbitrary unsafe P
kernel verifies B but executes P directly without the trusted lowering
```

这个构造是不安全的,因为被验证的产物和被执行的产物之间没有可信 lowering 相连。

native 内存操作在这个 refinement 关系下是安全的。例如,一段被执行的指令序列,其源码层面
的意图是:

```asm
mov rax, [rdi + 8]
```

如果 lower 后的 eBPF 通过一个经 verifier 检查的 BPF 指针、以相同的边界、对象和 fault 行为
执行同一个 load,那它就是安全的。如果用户只是把那条 x86 直接提交给内核、而没有经由可信
lowering 产出一份 eBPF 产物供 verifier 检查,那它就不安全。

重要的失败模式是不忠实的 lowering。例如,把一个 x86 内存访问 lower 成一个 sandbox 化的
VM 操作:

```text
guest_addr = rax
if guest_addr + 8 > guest_mem_size: unsupported
load guest_mem[guest_addr]
```

这证明的是 sandbox 化 x86 simulator 语义的安全性,而不是把 `rax` 当作真实内核地址来用的
安全性。ReverseSim 的 lowering 忠实,当且仅当目标程序在 packet、ctx、map_value 和 stack
指针上的语义,一对一地映射到 verifier 已经在检查的 eBPF 指针类型操作上。不忠实的 lowering
会破坏 safety transfer。

## State Model

lowering 用 verifier 可见的 eBPF 状态来表示目标机器状态。

以 x86 为例:

| Native State | Verifier-Visible State | Runtime State |
|---|---|---|
| `rax`、`rdi`、`rsi`、`rdx`、`rcx`、`r8`、`rbx`、`r13`、`r14`、`r15` | 映射到 BPF 寄存器或 stack-slot 寄存器 | 内核 JIT 后映射到的物理寄存器 |
| 额外寄存器如 `r10`、`r11`、`r12` | 目标寄存器文件区域里的固定 stack slot | 内核 JIT 选择的物理寄存器 |
| flags / 条件状态 | 显式的 scalar shadow 状态 | 局部有效时用 native flags,否则由内核 JIT 管理 |
| 程序内存访问 | 经 verifier 检查的 BPF 指针操作 | 内核 JIT 后等价的 native load/store |

目标寄存器 slot 是 verifier 可见的状态。内核 JIT 可以把对应的值保存在物理寄存器里,只要
对该状态的所有可观测操作都由特化产物中的 eBPF 指令表示。

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

安全规则是:

```text
Any operation that can observe verifier-visible state or expose hidden runtime
state must be represented by an eBPF instruction in the specialized artifact,
or pass through a boundary adapter that materializes the verifier state
expected by ordinary eBPF.
```

例如,一个被内核 JIT 只保存在物理寄存器里的寄存器,可以在一个封闭的特化 region 内部支撑
某个目标寄存器 slot。但在允许一个普通 helper 读取指向该目标寄存器 slot 后备内存的指针
之前,lowering 必须把该值 materialize 到真实栈内存,或者拒绝这种程序形态。

## 备选路径:kernel-ABI 双语义 ISA

idea #3 更早的一种 framing 把双语义放进内核里:每条 ReverseSim 指令同时拥有一个 verifier
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
verifier 路径把 ReverseSim 指令 lower 成普通 BPF 语义并检查结果程序。JIT 路径则改为 emit
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

最近的祖先是用于安全内核扩展的 proof-carrying code:

- George C. Necula 和 Peter Lee,"Safe Kernel Extensions Without Run-Time
  Checking",OSDI 1996。

PCC 检查用户提供的、针对 native 代码的 proof。ReverseSim 则改为对 lower 后的 eBPF 程序
使用现有的 eBPF verifier,且不要求用户提供 proof。

Translation validation(翻译验证)与之相关:它可以验证按程序的特化保持了源语义,或者
验证一个手写 JIT 忠实地实现了目标 ISA。

Native Client、RockSalt 以及 native 机器码 validator 通过直接验证或约束 native 机器码来
安全执行 native 代码。ReverseSim 从不运行用户提交的 native 字节,从而避开了任意 native
验证;只有 stock 内核 JIT 的输出才运行。SFI(software fault isolation)的源头是 Wahbe
等人(SOSP 1993)。

**WebAssembly 沙箱一条线是 ReverseSim 最近邻的 prior work,结构完全同构**:把不可信代码
编译到一个可被安全检查的 IR,再 lower 成 native。Provably-Safe Multilingual Software
Sandboxing using WebAssembly(USENIX Security 2022)把多语言代码编译到 Wasm 当可安全检查
的 IR;VeriWasm(USENIX Security 2021)验证 Wasm→native 编译保持 SFI;RLBox(USENIX
Security 2020 / Firefox 95)把不可信库编译成 Wasm 再编 native,在同地址空间安全共享。
ReverseSim 的"native →(可信 lowering)→ eBPF → stock verifier 当 proof checker → stock
JIT → native",正是这套"untrusted → 可信编译 → safe IR → checker → native"。关键区别:
ReverseSim 不引入新 IR、不引入新 checker,而是复用内核已有的 eBPF verifier + JIT,且处理
的是 native ISA(x86/arm64)而非 Wasm 这类天生为沙箱设计的 IR。

经验证的 eBPF JIT 工作(Jitterbug、Serval、K2)证明的是一个 eBPF JIT 保持 eBPF 语义。
ReverseSim 是其对偶:它证明的是一个 native-to-eBPF lowering 保持 native 语义,并在下游
复用现有的(可能已被验证的)eBPF JIT。Jitk(OSDI 2014)对"把可信 lowering 写成可验证
组件"这点更贴:它形式化验证地把高层规则编译到 cBPF 加 machine code。RIOT 微控制器内核上
的 eBPF interpreter+verifier(CAV 2022)与 JIT(CAV 2024)端到端机器证明,则是"对一个
具体 eBPF interpreter/JIT 做整体机器证明"的现成范例,支撑本文 Trust Model 里"simulator
`I` 可被形式化验证一次"的可行性主张。

可复用的可信 ISA 规格包括 Sail 对 arm64 和 RISC-V 的机器可检查语义,以及 ARM 官方的 C
reference simulator。这些都是可信 simulator `I` 的候选来源。

## 论文 framing

系统层面的主张:

```text
ReverseSim brings native code into the kernel under the
eBPF safety model without modifying the kernel, by writing the trusted
native-to-eBPF lowering in eBPF itself.
```

可能的标题:

```text
ReverseSim: Bringing Native Code into the eBPF Safety Model
  (without changing the kernel)
```

要成为一篇有分量的系统论文,评测需要展示:

- 广泛的目标 ISA 覆盖,而非只有少数几条指令;
- 真实程序(用该 lowering 重新表达现有 eBPF app,外加一些没有明显 eBPF 表达的 native
  例程);
- 性能接近 native x86/arm64,且在相同源语义下与现有 eBPF JIT 相当或更优;
- 可信 lowering(eBPF 里的 simulator 或 JIT)的复杂度,及其做形式化验证的适宜程度;
- 相对于 PCC 和 kinsn,对新增可信代码库的清晰核算;
- verifier 自然拒绝不忠实 lower 程序的失败案例。

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
ReverseSim does not execute user-supplied native code. It
executes the stock eBPF JIT lowering of an eBPF program produced by a trusted
in-eBPF simulator or JIT, which makes a one-to-one faithful translation of
the target native program. The existing eBPF verifier is the safety checker.
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

3. ReverseSim (本 doc)
   定位: x86/arm simulator or JIT written in eBPF,
        enabling safely running native code in the kernel
        without additional proof from the user
   关键技术: 特化的 eBPF simulator(主线) 或 native-to-eBPF JIT in eBPF
   内核改动: 接近零
   形式化对象: 单个 C simulator / JIT 的正确性
   解决的问题: 直接在内核里运行 native 代码并保证安全;
              不再要求开发者写 eBPF

实验设置: 三条都使用同一套 ebpf app benchmark / micro 套件 / 测量基础设施
```

这三条不是 incremental 三个版本,而是三个独立的设计点,各自针对的"待解决问题"
不重合。Project 共享 corpus、measurement infra、kernel build,论文层面拆开。
