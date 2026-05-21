# Kinsn:让 eBPF 更贴近硬件的一个新 OS 抽象

状态:研究方向 · idea #2 的论文线 hub

> 本文档是 Kinsn 论文线索的单一 hub。详细机制设计见 `docs/tmp/kinsn-design.md`,
> 形式化语义见 `docs/tmp/kinsn-formal-semantics.md`,工程实现细节见各 pass 的
> `docs/tmp/*kinsn*` 调研报告。

## 项目背景:三个姐妹 idea

本研究项目产出三篇彼此独立的论文,它们共用同一套评测设施(`bpf-benchmark`
corpus、micro 套件和测量基础设施),但用不同的设计解决不同的问题。

| # | Idea | Hub 文档 |
|---|---|---|
| 1 | Speculative eBPF optimization(纯用户态) | `docs/rejit-speculative-optimization-ebpf_idea.md` |
| 2 | **Kinsn**(本文档)—— 新 OS 抽象,让 eBPF 贴近硬件 | `docs/kinsn_idea.md` |
| 3 | NativeBPF(eBPF 里的 x86/arm native simulator) | `docs/nativebpf_idea.md` |

这三个 idea 不是同一个设计的递进版本。每个各自挑了一个不同的问题、一个在 trust /
内核暴露面 / 覆盖面空间里不同的位置,以及一个不同的设计核心。

## 1. 问题

eBPF 指令集刻意保持最小:load/store、ALU、比较、分支、call、exit,外加少数几条
packet 专用指令。这种极简让内核 verifier 可处理、JIT 也小,但它也使得几类 native
硬件级的优化从 eBPF 程序内部无法触及:

- **Rotate**(`RORX`/`ROR`):hash 和 crypto 风格的循环 emit 出
  `(x << n) | (x >> (64-n))`,内核 JIT 无法把它融合成单条硬件 rotate。
- **Conditional select**(`CMOV`/`CSEL`):无分支选择不可用;BPF emit 出一段
  branch+mov 序列,在可预测输入上更费,在不可预测输入上又输给一个分支。
- **Bitfield extract**(`BEXTR`/`UBFX`):位打包的协议解析 emit 出 `shift+and`
  序列,而不是单条硬件 extract。
- **Endian fusion**(`MOVBE`):load+byte-swap 是两条指令而不是一条。
- **Wide load/store pair**(arm64 上的 `LDP`/`STP`):相邻的 64 位 load 或 store
  无法配对成单条 128 位内存操作。
- **Bulk memory**(x86 上的 `rep movsb`,arm64 上的 `LDP/STP` 链):内联的
  memcpy/memset 无法使用 ISA 专用的批量路径。
- **Prefetch**(`PREFETCHT0`/`PRFM`):没有办法为即将到来的内存访问给缓存提示。
- **Conditional compare chain**(arm64 上的 `CCMP`):链式比较无法坍缩成 arm64
  专用的 compare-then-conditional-compare 形式。

把这些每一个都做成内核 JIT peephole,需要许多小 patch,每个都要走上游 review,每个都
增加内核暴露面、且必须为每个支持的架构维护。累积的内核 churn 很高,上游周期又慢。

## 2. Idea

**Kinsn**(kernel instruction)是一个新的 OS 抽象,它让内核能向 eBPF 程序暴露硬件
专用的指令原语,而无需扩展核心 eBPF 指令集、也无需为每个特性打 verifier 或 JIT patch。

每条 kinsn 都是一个**双语义原语**:

- **Verifier 语义**:一个声明式 effect(`bpf_kinsn_effect`),描述该操作的 clobber
  mask、结果 range、tnum、sub-register 定义和内存访问。内核 verifier 把这个 effect
  施加到抽象状态上,再用它现有的规则检查结果。
- **执行语义**:一个按架构区分的 `emit_x86()` / `emit_arm64()` 回调,在 JIT 期间
  emit 出 native 指令序列。

kinsn 以现有 kfunc 机制的特化形式实现:新增一个 `KF_KINSN` flag 和一张挂接的
`bpf_kinsn_ops` 表。verifier 对每条 kinsn 的情形零改动地复用 `check_kfunc_call()`;
JIT 在 CALL-emit 时检查 `KF_KINSN`,分派到模块提供的 emit 回调,而不是生成一个函数调用。

新优化 = 在一个小内核模块里定义一条新 kinsn + 一个用户态模式识别器(在 `bpfopt` 里),
把匹配的 BPF 字节码重写成调用该 kinsn。**每个新优化对核心内核 verifier、JIT 或 BPF ISA
的改动为零。**

## 3. 为什么这是一个新抽象,而不是又一个 peephole

三条性质把 kinsn 与内核内 peephole 优化区分开:

1. **策略与机制分离**。内核模块提供机制(指令做什么、verifier 该如何建模它、JIT 该如何
   emit 它)。用户态 `bpfopt` 提供策略(重写哪些模式、用什么 cost model、何时值得插入
   一条 kinsn)。机制小而固定;策略丰富而可迭代。

2. **每个优化不打核心内核 patch**。核心内核 JIT 和 verifier 不动。加一条新 kinsn 是一次
   模块改动加一个外部字节码重写 pass。上游周期是一次性的(针对 kinsn 框架本身),不是
   每个特性一次。

3. **随 workload 自适应的插入**。一条 kinsn 是否有益取决于 workload 特征(CMOV 看分支
   可预测性、prefetch 看热/易 miss 的内存访问、LDP/STP 看寄存器压力)。一个带运行时
   profile 数据的用户态优化器,挑插入点比任何静态内核启发式都更好。

这套组合产出一个新的 OS 抽象:**一个由内核定义、verifier 建模、JIT emit、模块实现的
eBPF 指令扩展面**。

## 4. 机制速写

详细机制设计见 `docs/tmp/kinsn-design.md`。这里是简短速写:

- `struct bpf_kinsn_ops` 持有模块回调:
  - `model_call(call, effect)`:产出一个声明式 `bpf_kinsn_effect`,供 verifier
    施加到抽象状态上。
  - `decode_call(call)` / `validate_call(call)`:解码编码后的操作数并检查良构性。
  - `emit_x86(call, ctx)` / `emit_arm64(call, ctx)`:在 JIT 期 emit native 代码。
- `KF_KINSN` 是一个新的 kfunc flag(与 KF_ACQUIRE / KF_RELEASE / KF_SLEEPABLE
  互斥)。
- 打包编码:一条紧邻在 kinsn `BPF_CALL` 之前的 sidecar 伪指令
  (`BPF_PSEUDO_KINSN_SIDECAR`)携带操作数位。verifier 在施加建模 effect 之前先解码
  sidecar。零参数 setup,N→1 指令替换。
- 模块生命周期:标准 Linux 模块 load/unload。当一个 kinsn 模块未加载时,verifier 拒绝
  引用它 kfunc 的程序,JIT 也永远看不到它们。在程序已加载之后再卸载,在飞的程序继续
  执行已经 emit 出的 native 代码。

形式化语义:`docs/tmp/kinsn-formal-semantics.md`。

### 4.1 内核源码触点(rejit-v2 分支 / kinsn 子集)

`vendor/linux-framework/rejit-v2` 分支的 kinsn 子集——即仅 kinsn 的内核暴露面——触及
以下文件。(REJIT 专属文件属于正交的 speculative-optimization 论文线,本篇刻意排除;
见 `docs/nativebpf_idea.md` 中关于 kernel-ABI 变体的讨论,以及内核 worktree 里的
`docs/kinsn-only` 分支。)

| 文件 | 职责 |
|------|------|
| `include/linux/bpf.h` | `bpf_kinsn_ops` / `bpf_kinsn_effect` / `bpf_kinsn_call`结构体、注册 API |
| `include/linux/bpf_verifier.h` | kinsn verifier 辅助结构体 |
| `include/linux/btf.h` | `KF_KINSN` flag |
| `include/uapi/linux/bpf.h` + `tools/include/uapi/linux/bpf.h` | `BPF_PSEUDO_KINSN_SIDECAR` + `BPF_PSEUDO_KINSN_CALL` enum 扩展 |
| `kernel/bpf/btf.c` | kinsn BTF id 解析 |
| `kernel/bpf/verifier.c` | kinsn 注册 / 查找、`model_call` verifier 流程、sidecar 解码 |
| `kernel/bpf/disasm.c` | kinsn 反汇编支持 |
| `arch/x86/net/bpf_jit_comp.c` | x86 JIT CALL-case kinsn 内联 dispatch |
| `arch/arm64/net/bpf_jit_comp.c` | arm64 JIT kinsn 内联 dispatch |

净 diff 体量(仅 kinsn 分支,叠加在 stock 7.0-rc baseline 之上):
**10 个文件共 +869 / -101 LOC**(零 REJIT 引用,纯 kinsn surface)。

## 5. 覆盖面与取舍

kinsn 暴露面是刻意有界的。覆盖决策由 corpus 证据驱动:只有当支持的运行时 corpus 里有
足够多的 site 来证明内核模块暴露面的合理性、且在插入点处有可测量的性能收益时,才加入
一个候选 kinsn。

**已实现的 kinsn**(在对应架构上为默认策略):

| Kinsn | 架构 | 状态 | Site 证据 | 设计 / 调研引用 |
|---|---|---|---|---|
| `bpf_rotate64` | x86 / arm64 | 已实现 | 701 sites,15 applied(shift+or → RORX) | — |
| `bpf_select64` (CMOV/CSEL) | x86 / arm64 | 已实现,**策略敏感** | 12 corpus applied(branch+mov → CMOV) | 策略:可预测输入 → CMOV 更慢;不可预测 → 更快 |
| `bpf_extract64` (BEXTR/UBFX) | x86 / arm64 | 已实现 | 524 sites,4 applied(shift+and → BEXTR) | — |
| `bpf_endian` (MOVBE / rev16/32/64) | x86 / arm64 | 已实现 | 256 sites,17 corpus applied(load+bswap → MOVBE) | — |
| `bpf_ldp128` / `bpf_stp128` | **仅 arm64** | 已实现 | ARM64 corpus store-pair 密度高;当前 JIT 0 个 LDP/STP | `arm64_ldp_stp_kinsn_design_20260326.md`、`arm64_bpf_ldp_module_report_20260326.md`;x86 dispatch 到 `rep movsb`(见 `x86_128bit_wide_loadstore_design_20260326.md`) |
| `bpf_bulk_memory` | x86 / arm64 | 已实现 | corpus 40 / 74 / 360 / 464 B 连续 copy/zero runs | `simd_kinsn_design_20260324.md`;x86 用 `rep movsb/stosb`,ARM64 用 LDP/STP,均 no-FPU |
| `bpf_ccmp` | arm64 | 已设计(第一波) | **4957 sites,6228 条省下的分支** | `arm64_kinsn_research_20260329.md`;受限的第一波,避免通用变长 compare-chain |
| `bpf_prefetch` (PrefetchV2) | x86 / arm64 | 已实现,默认 pass | 17391 个 `map_lookup_elem` + 21 个 `map_lookup_percpu_elem` 潜在 site;hot+missy site 预期 2.5-25ns/exec | `docs/tmp/p89_prefetchv2_impl.md`、`memory_hints_kinsn_research_20260329.md`、`prefetch_kinsn_design_20260329.md` |
| `bpf_lea{32,64}` | **仅 x86** | 实验性 | Katran `lea` 122 applied,bytes 13629→13277,BPF counter ratio 1.0487 | `docs/tmp/lea_kinsn_design_census_20260513.md`(详 §5.1 收窄决定) |

**明确不做 / 推迟**(附理由 + 调研引用):

| 候选 | Site 证据 | 理由 / 调研引用 |
|---|---|---|
| POPCNT / CLZ / CTZ | 0 site | clang 已展开 `__builtin_popcount` 为高效位操作序列。`bit_ops_kinsn_research_20260329.md` |
| CRC32 | loxilb SCTP CRC32C: 2 个 byte-update site | broad corpus 覆盖低;若做,第一版 CRC32C-only no-FPU scalar backend + loxilb-targeted `step8/step64` idiom pass。`crc32_kinsn_research_20260329.md` |
| PDEP / PEXT | 0 site | corpus 无 site。`bit_ops_kinsn_research_20260329.md` |
| SHRX / SHLX | 0 incremental gain | OoO CPU 上无增量收益。`bit_ops_kinsn_research_20260329.md` |
| MADD / MSUB | MADD 47 direct sites;MSUB 0 direct sites | MADD 仅二级优化;MSUB 宽松形式需 liveness/semantic work,不进 first wave。`arm64_kinsn_research_20260329.md` |
| UBFX / BFI | UBFX 321 total / 74 with-copy;BFI 0 | UBFX 应扩展现有 `extract` pass 覆盖 copy form;BFI 0 site 不做。`arm64_kinsn_research_20260329.md` |
| RDTSC / RDTSCP | 不适合默认 | cycles 不是 portable monotonic ns;不适合 `bpf_ktime_get_ns()` 透明 rewrite;若做应显式 opt-in。`rdtsc_adc_kinsn_research_20260329.md` |
| ADC / SBB | 917 个 `.bpf.o` 扫描:add carry-chain 0、sub borrow-chain 0 | 短期不进默认 pipeline。`rdtsc_adc_kinsn_research_20260329.md` |
| SETcc / CSET | **supported runtime corpus 9417 sites**(Tetragon 8832、Cilium 401、Calico 91、BCC 79);raw census 28653 sites | 比较结果直接存 0/1,不需要 branch+mov。standalone boolean-set 不被现 `COND_SELECT` 覆盖,应独立 kinsn。**调研完成待实现**:`docs/tmp/setcc_cset_kinsn_research_20260430.md` |
| ANDN | 957 个 `.bpf.o` 扫描:去重后 45 sites(Tracee 30 + Cilium 14) | 全部需 liveness proof;热路径上限 ~1.0M site/s × 2 cycles ≈ 0.07% 单核增量。不做第一波。`docs/tmp/andn_kinsn_research_20260430.md` |
| BLSI / BLSR / BLSMSK | 957 个 `.bpf.o` 扫描:BLSI 3 + BLSR 3 + BLSMSK 0(全部来自已移除 scx_lavd_main);supported app 为 0 | 当前 8-app corpus 无 exact site,后续 phase。`docs/tmp/bls_kinsn_research_20260430.md` |
| PAUSE / YIELD | corpus 几乎无 BPF-level busy-wait | 内核 BPF spinlock helper 内部已有 PAUSE/WFE,kinsn 无增量价值。`pause_yield_kinsn_research_20260329.md` |
| FPU SIMD (x86) | x86 corpus 绝大多数 copy/store ≤128B,break-even ≥数百字节 | `kernel_fpu_begin/end` XSAVE/XRSTOR ~200-800 cycles,pair load/store 远超收益。`simd_fpu_kinsn_deep_research_20260326.md` |
| NEON SIMD (arm64) | 仅 ≥1KiB + `may_use_simd()` 可考虑 | no-FPU LDP/STP 优先;Linux crypto 模式(per-op fpu_begin/end)不适用于 BPF 细粒度调用。同上 |
| NT store | corpus 无明确 streaming write 场景 | 不值得。`memory_hints_kinsn_research_20260329.md` |
| Region kinsn(寄存器扩展) | Cilium/Calico Jenkins/hash 信号,Tetragon byte-pack/decoder;上界 census 24/1/175 clusters | 高寄存器压力代码段包装为 region kinsn。首版限定 pure scalar N→1 无内存/stack/packet/map 写、无 helper/call,等 kinsn v3 / region ABI 收敛。`docs/tmp/region_kinsn_research_20260430.md` |
| 除法强度削减(常量除数 → shift+mul) | 957 .bpf.o:DIV/MOD 共 1269 sites,K 812 / X 457;Cilium `/1e9` 占 553 | 纯 bytecode 需 64×64→128 mulhi emulation,先等 per-site profile 或 native mulhi/kinsn。`docs/tmp/division_reduction_research_20260430.md` |

决策规则:一条新 kinsn 必须具备非平凡的受支持 corpus site 数量(粗略下限:数百个)、
在插入点处有可隔离出来的、大于插入带来的 I-cache 与 verifier 重跑成本的性能收益,以及
一个对 verifier 友好的声明式 effect。三者缺一,该提案就留在"不做"的桶里。

### 5.1 LEA / 地址生成的收窄决定(2026-05-13)

详细 design doc:`docs/tmp/lea_kinsn_design_census_20260513.md`。

**状态**:作为一个仅 x86 的 kinsn 实验实现。在项目"不改核心 JIT"政策下,**不走核心
内核 JIT peephole 路线**。ARM64 不实现 LEA,也不应对外暴露 `bpf_lea{32,64}`。

合并普查:

- 运行时 `testbin`:严格不重叠的 site **共 13,321 个**(Tracee 6,405、Tetragon
  6,363、OTEL 470、Cilium 79、Katran 4)。静态 scalar 的第一波将是跨 4 个 app 的
  10,922 个 site。所有严格运行时 site 都是朴素的 pattern `a`(`MOV+ADD`);scaled-index、
  scaled+disp 和 add-imm-chain 均为 0。
- 生成的 `testobject`:严格 BPF site 跨全部 7 个 app 共 6,999 个(6,995 个 pattern
  `a`,4 个 pattern `b`,0 个 pattern `c`,0 个 pattern `d`)。
- Native `testccode/*.x86.s`:42,153 条 `lea` 指令,但其中 36,991 条是简单的
  base+disp 地址 materialization。**BPF-object 严格 / native 之比为 16.6%**。
- Katran 矛盾已解决:实际 native Katran 计数是 225,而 Katran BPF 严格计数是 4。native
  那边的丰富性来自 x86 地址模式 materialization,而非字节码层面的算术 LEA。

含义:剩下的 BPF 层面机会是相邻的 `MOV+ADD`。一个核心 JIT peephole 会最直接地 lower
它,但该路线被"不改核心 JIT"政策排除。已实现的纯 kinsn 路线保住了那条边界,并让用户态
拥有替换策略。它对匹配 site 减少了最终的 x86 指令数 / 代码大小,但在 packed-sidecar
替换之后主导模式仍是 2 个 BPF slot,并未把当初引发这项调查的 native 地址模式 LEA 收回来。
在事后性能证据显示出运行时收益之前,把 LEA 当作**实验性**对待。

## 6. 与另外两个 idea 的关系

### Idea #1 —— Speculative eBPF optimization

两个 idea 共用 `bpfopt` 作为用户态重写工具、`bpfrejit-daemon` 作为编排器。区别在于
daemon 跑哪些 pass、以及这些 pass 需要哪些内核设施。

- idea #1 的默认 pipeline 只有 BPF-to-BPF 重写(`map_inline`、`const_prop`、`dce`、
  `bounds_check_merge`、`branch_flip` 等)。它要求接近零的内核改动。
- idea #2 的 pipeline 可以包含引入 kinsn 的 pass(`rotate`、`cond_select`、`extract`、
  `endian_fusion`、`prefetch` 等)。这些需要内核里的 kinsn 框架 patch 加上各架构 kinsn
  模块。

一个搭载 idea #2 的内核严格包含一个只搭载 idea #1 的内核。两条 pipeline 可组合:想要
两者的部署就跑它们 pass 的并集。但论文把它们分开,因为贡献点不同(用户态机制 vs. 内核
抽象)。

### Idea #3 —— NativeBPF

idea #2 和 idea #3 从相反的两端攻击同一个底层问题——如何让非平凡的 native 操作在
eBPF 安全模型内变得可用:

- Kinsn 用内核定义的双语义原语扩展内核侧的指令集。每个新原语都让内核 TCB 小幅增长。
- NativeBPF 用一个经过验证的 simulator 或 JIT 扩展用户态侧的 lowering。内核保持不变。
  新增的 TCB 是一个用户态产物:每个目标 ISA 一个 C 文件。

Kinsn 覆盖普通 eBPF 表达不好的少数几种模式。NativeBPF 覆盖目标 ISA 能表达的任何东西,
只要其 lowering 对 verifier 可处理。两者并不互斥:一个支持 kinsn 的内核,配上一个在有
益处时 emit kinsn 的 NativeBPF,是一个自然的 ablation 点,但二者互不依赖。

## 7. 论文 framing

可能的标题:

```text
Kinsn: A Hardware-Aware Instruction Extension Surface for eBPF
```

核心的系统主张:

```text
Kinsn introduces a new kernel abstraction that lets eBPF programs use
platform-specific hardware instructions safely. The verifier checks each
kinsn through a declarative effect supplied by a kernel module; the JIT
emits the native instruction sequence via the same module. New instructions
are added without modifying the core verifier, the core JIT, or the eBPF
ISA, and a userspace optimizer chooses insertion sites based on workload
profile data.
```

一份有分量的评测需要展示:

- 广泛的 kinsn 覆盖(至少 rotate / cond_select / extract / endian / prefetch /
  pair load-store / bulk memory),而非单个原语;
- 真实 eBPF 程序(Cilium / Katran / Tetragon / Tracee / BCC / bpftrace /
  loxilb),而非只有 microbenchmark;
- 在至少一条策略敏感的 kinsn 上(CMOV 是典型例子),随 workload 自适应的插入胜过固定的
  内核启发式;
- 小而可理解的内核暴露面(框架 patch);
- 模块级隔离(加载或卸载一个 kinsn 模块不影响无关程序);
- arm64 结果,而非只有 x86,以验证按架构区分的抽象。

## 8. 相关工作定位

- **kfuncs(现有上游)**:kinsn 以 kfunc 的特化形式实现(KF_KINSN)。贡献点是双语义
  emit 路径,而非 BTF 或注册机制。
- **JIT peephole**:核心 JIT 里按架构区分的 peephole(例如上游 arm64 LDP fusion)。
  kinsn 把同样的能力推到一个模块边界之后,使得新增不触碰核心 JIT。
- **JVM intrinsics**:HotSpot intrinsic 把标准库调用替换成由 JIT 挑选的手写 native
  序列。kinsn 是把同一思路用到 eBPF 上,并让 verifier 以声明式方式建模该 intrinsic 的
  effect。
- **K2 / Merlin / EPSO**:在 load 前对源 `.bpf.o` 操作的 BPF 字节码优化器。它们不扩展
  BPF ISA,也无法 emit 标准 JIT 词汇表之外的 native 指令。kinsn 通过拓宽 emit 词汇表来
  与它们互补。
- **hXDP(OSDI 2020)/ eBPF Program Warping(ATC 2022)**:与 kinsn 思路同构的最近邻
  prior work。Program Warping 用 peephole 把一串 eBPF 指令替换成**优化过的硬件实现**,
  hXDP 给 eBPF 扩 ISA 以在 FPGA NIC 上执行。这正是 kinsn 的核心("识别一段 BPF 模式,
  emit 成更接近硬件的单条原语,拓宽 emit vocabulary"),区别在于它们的 target 是 FPGA
  overlay,而 kinsn 在 stock host x86/arm64 JIT 上做、走模块边界、verifier 见声明式
  effect。
- **经验证的 JIT / translation validation(Jitterbug OSDI 2020、Synthesizing JIT
  Compilers for In-Kernel DSLs CAV 2020)**:kinsn 的 soundness 论证(§9:声明式 effect
  必须忠实建模 native emit)本质上是"JIT emit 正确性"问题。verified JIT 与 translation
  validation 是这一缓解手段的既有方法论范式。
- **BeeBox / MOAT / Hive(USENIX Security 2024)**:给 eBPF 加硬件或 SFI 隔离的对照组
  (分别针对瞬态执行、Intel MPK、AArch64 硬件隔离)。可用于论证 kinsn 的 TCB 增量相对
  这些"改运行时隔离"路线的取舍。

## 9. 主要风险

- 每条新 kinsn 都增加一小块内核暴露面(模块回调、声明式 effect、JIT emit)。总暴露面随
  kinsn 数量增长,审计成本随之累积。
- 一个不忠实建模 native emit 的声明式 effect,会对任何使用该 kinsn 的程序静默违反 verifier
  soundness。每条 kinsn 的形式化语义文档与 translation-validation 工作
  (`docs/tmp/kinsn-formal-semantics.md`)是缓解办法。
- 随 workload 自适应的插入需要可靠的 per-site profile 数据。idea #1 的 `bpfprof
  --per-site` pipeline 是其来源;如果某个部署上 PMU 数据不可靠,策略敏感的 kinsn 必须
  回退到一个保守默认值,而不是去猜。
- 一些看起来很自然的 kinsn(FPU SIMD、RDTSC)无法加入,因为要么会改变语义(RDTSC 非
  单调),要么要付出超过收益的 setup 成本(FPU 上下文保存)。§5 的决策规则把它们挡在
  暴露面之外。

## 10. 交叉引用

- 机制设计:`docs/tmp/kinsn-design.md`
- 形式化语义与 translation validation:`docs/tmp/kinsn-formal-semantics.md`
- `bpf_kinsn_ops` 详细设计:`docs/tmp/20260323/kinsn_ops_design_20260323.md`
- 实现审计:`docs/tmp/20260323/kinsn_implementation_review_20260323.md`
- 每条 kinsn 的调研与决策:`docs/tmp/*kinsn*`(rotate、cond_select、extract、endian、
  prefetch、ccmp、lea、bls、andn、setcc_cset、simd_fpu、bulk_memory、ldp_stp、
  register_realloc、region_kinsn 等)
- Speculative-optimization 姐妹论文:`docs/rejit-speculative-optimization-ebpf_idea.md`
- NativeBPF 姐妹论文:`docs/nativebpf_idea.md`
