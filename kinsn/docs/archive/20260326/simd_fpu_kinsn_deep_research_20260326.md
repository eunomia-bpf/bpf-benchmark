# SIMD/FPU kinsn 深度研究（BpfReJIT，面向 OSDI'26）

日期：2026-03-26  
作者：Codex 深度研究笔记

## 0. 执行摘要

结论先行：

- 总体判断是 **`CONDITIONAL`**，但要拆成两层看：
  - **x86**：对 OSDI'26 主线工程来说，**`NO for v1`，`very narrow YES for phase 2`**。
  - **ARM64**：**`CONDITIONAL YES`**，但也只适合极少数、足够粗粒度的大块操作。
- **v1 不应该做 true SIMD/FPU kinsn**。应该坚持现有设计：  
  **x86 用 `rep movsb/stosb`，ARM64 用 `LDP/STP` / `STP XZR`，都不进 FPU/NEON section**。[PLAN][SIMD-DESIGN][WIDE-LDST]
- 如果做 phase 2，**最低可行集合**不是“泛化 AVX2/NEON”，而是：
  1. `bpf_memcpy_fast` / `bpf_memset_fast` 继续走 **no-FPU backend**；
  2. `bpf_crc32/c` 先做 **scalar CRC instruction chain**；
  3. 只有在 **x86 >= 512B 且最好 >= 1-2KiB**、**ARM64 >= 1KiB**、并且 `irq_fpu_usable()` / `may_use_simd()` 成立时，才考虑 **PCLMUL/PMULL/NEON**。
- **论文故事**可以讲，但不该讲成“我们在 kernel BPF 里广泛用 AVX2/NEON 很赚”。更强的故事其实是：
  - **BpfReJIT 的 semantic kinsn 能恢复宽机器语义；**
  - **真正稳定、可上线、可跨机复现的第一收益面是 no-FPU bulk-memory；**
  - **true SIMD 是强 ISA 不对称的第二层优化：ARM64 更友好，x86 更昂贵且更脆弱。**

一句话总结：

> **BpfReJIT 应该把“SIMD opportunity”重新定义为“wide-machine opportunity”。对 OSDI'26，值得主打的是 `rep movsb/stosb` + `LDP/STP` + scalar CRC，而不是把 x86 AVX2/AVX-512 FPU section 搬进热路径。**

---

## 1. 研究范围与方法

本次研究同时使用了：

- **仓库内已有设计文档**：
  - `docs/kernel-jit-optimization-plan.md`（重点看 §3.1 SIMD 行）[PLAN]
  - `docs/tmp/20260324/simd_kinsn_design_20260324.md` [SIMD-DESIGN]
  - `docs/tmp/20260324/128bit_wide_loadstore_research_20260324.md` [WIDE-LDST]
  - `docs/tmp/20260323/simd_constprop_opportunity_analysis_20260323.md` [SIMD-OPP]
  - `docs/tmp/20260326/corpus_call_statistics_20260326.md` [CALL-STATS]
  - `docs/tmp/20260323/map_inlining_opportunity_analysis_20260323.md` [MAP-OPP]
- **Linux 内核源码**：
  - x86 FPU 管理
  - ARM64 FPSIMD/NEON 管理
  - crypto SIMD 用法
  - netfilter `pipapo_avx2` 作为“内核网络子系统内的 SIMD 邻居”
- **外部论文/系统资料**：
  - Swift, PacketMill, Junction, hXDP, X2DP
  - PyPy tracing JIT vectorization, JITSPMM
  - DPDK vector mode 文档
  - x86 XSAVE/XSAVEC 量级资料

此外，我做了两类本地静态扫描：

### 1.1 源码级模式扫描

对 `runner/repos` 中 **1078 个 BPF 实现 `.c` 文件**做了保守扫描（排除 header / generated include），统计：

- `__builtin_memcpy/memset/memmove`
- checksum / crc
- 字符串匹配
- bloom filter map
- `bpf_map_lookup_elem()`

这是 **“源码表面机会面”**。

### 1.2 macro corpus 对象级 store-run 扫描

对 `corpus/config/macro_corpus.yaml` 中 **764 个 program entry / 477 个唯一 `.bpf.o`**，用 `llvm-objdump -dr --no-show-raw-insn` 做了 **保守的 contiguous store-run** 检测：

- 规则：同函数内、同 base、同 src reg、同宽度、连续 offset、至少 4 条、总 span >= 64B
- 这个扫描 **只会抓到明确的 store-run**，不会抓到混合 load/store copy，也抓不到复杂 memcpy lowering

因此：

- 它给的是 **bulk zeroing 机会的下界**
- 对“某个 program entry 所在 object 是否含有机会点”的映射，只能给 **object-level upper bound**

换句话说，下面的 corpus 数字要按“**下界 + 上界**”去读，而不能误解成完全精确的 section 级 ground truth。

---

## 2. FPU/FPSIMD 上下文成本：源码事实与定量估计

## 2.1 x86：`kernel_fpu_begin()/kernel_fpu_end()` 具体做了什么

在 x86_64 上，`kernel_fpu_begin()` 实际是 `kernel_fpu_begin_mask(KFPU_MXCSR)`。[KX86-API]

`kernel_fpu_begin_mask()` 的关键路径如下：[KX86-CORE]

1. `fpregs_lock()`  
   在 !RT 上相当于 `local_bh_disable()`；RT 上相当于 `preempt_disable()`。[KX86-API]
2. 检查 `irq_fpu_usable()`
3. 把 per-cpu `kernel_fpu_allowed` 置为 `false`
4. 如果当前线程不是 `PF_KTHREAD|PF_USER_WORKER`，且 `TIF_NEED_FPU_LOAD` 还没置位：
   - 置 `TIF_NEED_FPU_LOAD`
   - `save_fpregs_to_fpstate(x86_task_fpu(current))`
5. `__cpu_invalidate_fpregs_state()`
6. 如需要则初始化控制寄存器：
   - `ldmxcsr(MXCSR_DEFAULT)`（默认 `kernel_fpu_begin()` 会做）
   - 如请求 387 状态则 `fninit`

`kernel_fpu_end()` 本身只做两件事：[KX86-CORE]

1. 把 `kernel_fpu_allowed` 置回 `true`
2. `fpregs_unlock()`

注意：**`kernel_fpu_end()` 不负责把用户态 FP 状态立刻恢复回寄存器。**

### 2.1.1 现代 6.x x86 到底是 eager 还是 lazy？

现代 x86 Linux 不是早年那种 “#NM fault 驱动的 old lazy FPU switching”。  
从调度路径看，`switch_fpu()` 在切换出旧任务时会：

- 保存旧任务 fpregs 到内存
- 置 `TIF_NEED_FPU_LOAD`
- 让 restore 延迟到真正返回用户态之前再做 [KX86-SCHED]

所以更准确的说法是：

> **现代 x86 是 eager save + lazy/deferred restore。**

这点对 BpfReJIT 很重要，因为 `kernel_fpu_begin()` 可能触发 **立即 save**，而 restore 往往要在 **之后返回用户态**时才支付。

### 2.1.2 x86 save/restore 覆盖哪些组件？

`save_fpregs_to_fpstate()`：

- 若 `use_xsave()`：走 `os_xsave()`
- 否则才走 `fxsave()` [KX86-CORE]

`restore_fpregs_from_fpstate()`：

- 若 `use_xsave()`：走 `os_xrstor(fpstate, mask)`
- mask 为 `fpu_kernel_cfg.max_features & mask` [KX86-CORE]

`XFEATURE_MASK_FPSTATE` 包含：

- 所有用户态需要 restore 的 xstate（不含被 eager 切换的 PKRU）
- 以及支持的 supervisor xstate [KX86-XSTATE]

这意味着：**x86 的 save/restore 成本取决于启用的 xstate 组件，而不是一个固定常数。**

## 2.2 x86：XSAVE area 大小到底有多大

从内核头文件可直接读出几个关键组件大小：[KX86-XSTATE][KX86-TYPES]

| 组件 | 大小 | 说明 |
| --- | ---: | --- |
| `FXSAVE` legacy area | 512B | x87 + SSE 低位 |
| XSAVE header | 64B | `XSAVE_HDR_SIZE` |
| YMM high halves | 256B | AVX 才有 |
| AVX-512 opmask | 64B | `k0-k7` |
| AVX-512 ZMM upper 256 | 512B | `ZMM0-15` 高 256 |
| AVX-512 hi16 ZMM | 1024B | `ZMM16-31` |

因此，几个常见级别的 **xstate 下界** 可以直接算出来：

- **SSE/FXSAVE 级别**：`512B`
- **AVX 级别**：`512 + 64 + 256 = 832B`
- **AVX-512 级别**：`832 + 64 + 512 + 1024 = 2432B`

这还没算：

- MPX / PKRU / CET / PASID / APX 等额外组件
- padding / layout 细节
- AMX tile state

对于 AMX，内核注释明确写了：

- tile config 是 `64B`
- **每个 tile data register 是 `1KB`，且寄存器数量取决于实现** [KX86-TYPES]

所以 x86 上的真实 xstate 开销可以从 **几百字节**直接涨到**多 KB**，这是它和 ARM64 plain NEON 的第一个根本差异。

### 2.2.1 AVX-512 还有额外问题：降频

`arch/x86/kernel/fpu/core.c` 直接有注释：

> `Track AVX512 state use because it is known to slow the max clock speed of the core.` [KX86-CORE]

所以对 BpfReJIT 而言，**AVX-512 不是“更宽的 AVX2”而已**，它还可能带来频率副作用。  
这使得 AVX-512 几乎不适合作为 OSDI'26 主线结果的一部分。

## 2.3 ARM64：`kernel_neon_begin()/kernel_neon_end()` 具体做了什么

ARM64 并不是“NEON 免费”。

`may_use_simd()` 要求：[KARM-SIMD]

- `system_capabilities_finalized()`
- `system_supports_fpsimd()`
- 不在 hardirq
- 不在 NMI

`fpsimd.c` 的大段注释说明 ARM64 采用的是 **ownership + lazy restore** 模型：[KARM-FPSIMD]

- `fpsimd_last_state`
- `fpsimd_cpu`
- `TIF_FOREIGN_FPSTATE`
- `TIF_KERNEL_FPSTATE`

`kernel_neon_begin()` 做的关键事情是：[KARM-FPSIMD]

1. `BUG_ON(!may_use_simd())`
2. `get_cpu_fpsimd_context()`
3. 若已经处于 nested kernel FPSIMD：
   - `fpsimd_save_state(state)`
4. 否则：
   - `fpsimd_save_user_state()`
   - 记录 `current->thread.kernel_fpsimd_state`
   - 置 `TIF_KERNEL_FPSTATE`
5. `fpsimd_flush_cpu_state()`
6. `put_cpu_fpsimd_context()`

`kernel_neon_end()` 则：

- 若是 softirq nested 情况则恢复保存下来的 kernel FPSIMD state
- 否则清 `TIF_KERNEL_FPSTATE` 并清空 `current->thread.kernel_fpsimd_state` [KARM-FPSIMD]

### 2.3.1 ARM64 也是 lazy restore，不是“零成本”

`fpsimd.c` 注释写得很清楚：

- 普通 syscall 返回用户态时，如果 `TIF_FOREIGN_FPSTATE` 仍然清着，可以避免 restore
- 调用 `kernel_neon_begin()` 时会把任务的 FPSIMD 状态写回内存，并把 CPU 寄存器所有权让给 kernel [KARM-FPSIMD]

所以 ARM64 的真实语义是：

> **不是没有 save/restore，而是 common-case state 更小、ownership 模型更简单。**

## 2.4 ARM64：保存的状态大小有多大

plain FPSIMD 的用户态结构是：[KARM-UAPI]

```c
struct user_fpsimd_state {
    __uint128_t vregs[32];
    __u32 fpsr;
    __u32 fpcr;
    __u32 __reserved[2];
};
```

大小很好算：

- `32 * 16 = 512B`
- `fpsr + fpcr + reserved = 16B`
- 合计 **528B**

这比 x86 的 AVX/AVX-512 xstate 明显更小。

但 ARM64 也不是完全固定成本，因为 `fpsimd_save_user_state()` 在用户态活跃使用 SVE/SME 时会走：

- `sve_save_state(...)`
- `sme_save_state(...)` [KARM-FPSIMD]

而 `sigcontext.h` 里的宏说明：

- `SVE_SIG_REGS_SIZE(vq)` 是 **随 VL 变化的**
- `ZA_SIG_REGS_SIZE(vq) = ((vq * 16) * (vq * 16))`，是 **二次增长** [KARM-SIG]

这意味着：

- **plain NEON/FPSIMD**：通常是 **528B**
- **SVE/SME live**：可能是 **多 KB**
- **ZA**：在大 VL 下甚至可到 **64KB 量级**

因此，“ARM64 NEON 免费”这句话是不准确的。更准确的是：

> **ARM64 plain NEON common-case 比 x86 AVX 便宜很多，但并不免费；遇到 SVE/SME 也可能很贵。**

## 2.5 定量成本估计

### 2.5.1 x86：可直接引用的公开量级

我找到的最可信、最贴近内核工程的公开量级有两类：

1. **Intel 内核 tracepoint 讨论**：  
   为了给 XSAVE/XSAVES/XRSTOR 加 trace event，patch 作者举例说在一台 Intel Sapphire Rapids 上，某次 trace 中 `XSAVES` 大约是 **85 cycles**。[P9]
2. **glibc `XSAVEC` 讨论**：  
   有实测提到 Skylake AVX-512 机器上，某个热路径从 **145 cycles** 变到 **272 cycles**，也就是 **约 127 cycles** 的额外成本。[P10]

这两个数字不是 Linux `kernel_fpu_begin()` 的完整 end-to-end 微基准，但至少给出一个结论：

> **现代 Intel 上，单次 XSAVE-family 指令的量级通常就是几十到一百多 cycles，不是个位数。**

再结合 `kernel_fpu_begin()` / `kernel_fpu_end()` 路径本身还有：

- `fpregs_lock()/unlock()`
- `kernel_fpu_allowed` 切换
- 可选 `ldmxcsr`
- 以及稍后返回用户态时的 restore

我给出下面这个 **工程估计**：

| 平台 | 原始 save/restore 指令量级 | BpfReJIT 视角下的固定 tax |
| --- | --- | --- |
| x86 / Intel | **约 80-150 cycles**（公开资料） | **约 300-500 cycles typical**，最坏可更高 |

这里的 **300-500 cycles** 是把：

- begin 侧 save
- end 侧 bookkeeping
- 后续用户态 restore

一起看成“你在一次 BPF 执行里为 FPU section 引入的固定税”。  
这个数字在 **PF_KTHREAD**、或 `TIF_NEED_FPU_LOAD` 已经置位时会更低；在缓存压力大、xstate 大、或路径复杂时会更高。

### 2.5.2 x86 / AMD 怎么看？

我没有找到同等级、同条件、可直接引用的 **AMD Zen 上 XSAVE/XRSTOR apples-to-apples 公开数据**。  
因此对 AMD 的判断只能写成 **推断**：

- 机制上仍是 XSAVE-family / XRSTOR-family
- xstate 规模问题和 begin/end 固定 tax 问题并不会消失
- 因此 **数量级大概率仍是“几十到几百 cycles”**，不是零

这里必须明确标注：

> **这是推断，不是从 AMD 公开微基准直接读出来的结论。**

### 2.5.3 ARM64：没有同等公开微基准，但可以做结构化估计

ARM64 plain FPSIMD state 是 **528B**。一轮 save+restore 的纯数据搬运量约：

- `528B save + 528B restore = 1056B`

再考虑 32 个 128-bit vector reg 的成对 load/store 指令数和少量控制寄存器搬运，给出一个 **保守工程估计**：

| 平台 | 状态大小 | 固定 tax（估计） |
| --- | --- | --- |
| ARM64 plain FPSIMD | 528B | **约 60-120 cycles** |
| ARM64 with live SVE/SME | variable / multi-KB | 明显更高，不建议作为 baseline 假设 |

这里同样要写清楚：

> **60-120 cycles 是基于状态大小和指令形态的工程估计，不是我找到的公开论文实测。**

### 2.5.4 x86 vs ARM64：最重要的对比

| 维度 | x86 | ARM64 |
| --- | --- | --- |
| Common-case saved state | 832B (AVX) 到 2432B+ (AVX-512) | 528B (plain FPSIMD) |
| 状态大小是否固定 | 否，随 xstate feature 涨 | plain NEON 基本固定；SVE/SME 另算 |
| 切换模式 | eager save + deferred restore | ownership + deferred restore |
| begin/end 固定 tax | 高，且对 xstate 很敏感 | common-case 更低 |
| 额外副作用 | AVX-512 可能降频 | 无 AVX-512 式明显降频问题 |

因此：

- **ARM64 比 x86 更接近“可讨论 true SIMD”**
- 但它仍然 **不是零成本**
- 一旦引入 `LDP/STP` 这种 **no-FPU baseline**，ARM64 的 true NEON break-even 也会被推到更大的 buffer 区间

---

## 3. 相关工作与文献检索

我没有找到一篇“Linux kernel eBPF JIT 对通用 BPF 程序自动发射 AVX2/NEON”的成熟论文。  
真正接近的工作，基本分成三类：

1. **批处理/跨包并行**，而不是单包内 SIMD
2. **用户态 / kernel bypass**，绕开 kernel FPU/xstate 税
3. **JIT vectorization**，但对象是规则循环或数值 kernel，不是短小、helper-heavy 的内核 BPF

## 3.1 相关工作表

| 工作 | 场景 | 核心发现 | 对 BpfReJIT 的启发 |
| --- | --- | --- | --- |
| **Swift** (NSDI'08) [P1] | 动态包过滤器 | 文中明确提到 “**SIMD instruction**”、并把小包聚成固定-size batch 一起处理 | 成功案例依赖 **batching across packets**；这和当前单次 BPF 执行模型不同 |
| **PacketMill** (ASPLOS'21) [P2] | per-core 100Gbps packet processing | 通过编译器式 specialization，把包处理提升到 **36.4 Gbps / core** | 更支持“semantic specialization / constant propagation / code shaping”优先，而不是一上来真 SIMD |
| **Junction** (NSDI'24) [P3] | kernel bypass cloud dataplane | 明确指出保存扩展 CPU state 可能是 **many kilobytes**，而 Junction 通过用户态模型避免了这笔税 | 说明 SIMD 在 userspace/kthread 模型比 in-kernel BPF 更自然 |
| **hXDP** (OSDI'20) [P4] | 扩展 eBPF ISA，面向 FPGA NIC | 把 XDP/eBPF 编译到更并行的数据面，吞吐提升 **1.7x-3x** | 真正显著的“向量化/并行化”往往来自 **更粗粒度执行模型** |
| **X2DP** (SIGCOMM'25 demo/poster) [P5] | 并行 XDP | 明确写到批处理使 **prefetching / SIMD** 成为可能，吞吐可到 **2.3x** | 再次说明：**batching** 比单包内 gather 更像真机会面 |
| **Vectorization in PyPy's Tracing JIT** [P6] | tracing JIT auto-vectorization | 证明运行时 JIT 也能识别 loop 并向量化 | JIT SIMD 可行，但前提是 IR 足够 loop-friendly；BPF packet parser 通常不是这种形态 |
| **JITSPMM** [P7] | JIT-specialized sparse kernel | JIT + ISA-specific specialization 能显著超过泛型库 | 支持“按机器定制 backend”这件事，但对象是粗粒度计算 kernel，不是 kernel FPU critical section |
| **DPDK vector modes** [P8] | userspace packet processing | SIMD path 被当作 **可选 burst mode**，不是默认无条件路径 | 工业实践也把 SIMD 看成 **受限的替代路径** |

## 3.2 对这些工作的综合判断

### 3.2.1 真正成功的“网络 SIMD”大多依赖 batching

Swift 和 X2DP 都非常关键，因为它们说明：

- SIMD 很少来自“把单包处理逻辑生硬改写成 gather/scatter”
- 更常见的是 **跨包形成 lane**，让一条向量指令处理多包同一字段

而 BpfReJIT 当前目标是：

- 保持 Linux kernel 内的 BPF 执行模型
- 优化单个 BPF program 的 native code emission

这决定了：

> **BpfReJIT 天然不具备 Swift/X2DP 那种 batching 带来的 SIMD 条件。**

### 3.2.2 userspace dataplane 比 kernel BPF 更容易“无痛用 SIMD”

Junction 的价值不在于它自己用了多少 AVX，而在于它点明了：

- 扩展 CPU state 很大
- kernel bypass 模型可以避开频繁 save/restore

这直接说明：

> **相同的 SIMD/backend idea，在 userspace dataplane 往往比在 kernel BPF JIT 更成立。**

### 3.2.3 相关工作并没有支持“对通用 BPF 程序做广泛 in-kernel SIMD codegen”

我这次检索得到的最接近工作：

- 要么是 batch / parallel XDP
- 要么是 userspace dataplane
- 要么是 JIT vectorization on loops

**没有发现一条成熟文献线支持：在 Linux kernel 内，对通用 eBPF JIT 广泛发射 AVX2/NEON，会是一个大而稳的收益面。**

这不是坏消息，反而给 BpfReJIT 的 paper story 一个更可信的定位：

> **我们的贡献不是“强行给 BPF 加 SIMD”，而是识别出 semantic kinsn 的真正 profitable frontier。**

---

## 4. Corpus 机会面分析

## 4.1 宏观 corpus 结构

`macro_corpus.yaml` 里共有 **764 个 program entry**，对应 **477 个唯一 `.bpf.o`**。  
其中：

- **296 个**是 `xdp` 或 `sched_cls`
- **174 个**带 networking tag 或 networking category

这说明：

- 真正可能从 bulk memory / checksum 受益的“网络 datapath 程序”并不少
- 但它们在整个 corpus 里并不是全部

另一份全 corpus 调用统计给出的全景是：[CALL-STATS]

- **568 objects**
- **2019 programs**
- **1,495,191** 条 executable BPF insns
- **3427** 个 bpf2bpf calls
- **537** 个 tail calls
- **59,939** 个危险/上下文敏感 helper calls

尤其重要的是项目分布：[CALL-STATS]

- `tracee` / `KubeArmor` / `tetragon` 这类 tracing/security 项目占了大量 helper-heavy 指令面
- `calico` / `loxilb` / `xdp-tools` / `katran` 更接近稳定 packet path

这进一步支持现有设计文档里的判断：

> **v1 先做 XDP/TC，不做 tracing/kprobe，是正确切分。** [SIMD-DESIGN]

## 4.2 源码级模式统计

对 `runner/repos` 中 **1078 个 BPF 实现 `.c` 文件**的扫描结果如下：

| 模式 | 文件数 | 命中数 | 解释 |
| --- | ---: | ---: | --- |
| `__builtin_memcpy` | 40 | 82 | 有，但并不普遍 |
| `__builtin_memset` | 25 | 70 | 有，但并不普遍 |
| `__builtin_memmove` | 3 | 5 | 极少 |
| `memcmp/strncmp/bpf_strncmp` | 36 | 80 | 多数不是热网络 fast path |
| `BPF_MAP_TYPE_BLOOM_FILTER` | 3 | 3 | 几乎全是 selftests |
| `bpf_map_lookup_elem()` | 246 | 828 | 很多，但 hash 在 helper/内核里 |
| `crc32/crc32c/checksum/csum` | 21 | 191 | 集中在 synproxy / flowtable / trafficgen / nat64 等 |

其中 checksum / crc 的高频文件主要是：

- `xdp_synproxy_kern.c`
- `xdp_flowtable.bpf.c`
- `nat64_kern.c`
- `xdp_trafficgen.bpf.c`

这说明：

- **checksum/CRC 是真实存在的机会面**
- 但 **Bloom filter / string-SIMD / generic hash SIMD** 远没有看起来那么广

### 4.2.1 与已有机会分析文档对齐

已有机会分析文档给出一个更“干净”的子集统计：[SIMD-OPP]

- 在 **429 个成功构建的 BPF 源文件**里，
- 只发现 **23 个显式 builtin 调用点**：
  - `__builtin_memcpy`: 13
  - `__builtin_memset`: 9
  - `__builtin_memmove`: 1

这个数字比我这次全 repo 源码扫描更小，原因是：

- 文档只算成功构建、且按更严格口径统计的 BPF 源文件
- 我这次扫描覆盖了更多 repo 变体和实现文件

但两者的方向完全一致：

> **显式 memcpy/memset 在源代码层并不多，真正的大头是 LLVM 已经 scalarize 的 copy/zero run。**

## 4.3 helper-level 统计：为什么 tracing helper 不是 SIMD 收益点

`simd_constprop_opportunity_analysis_20260323.md` 已经给出一个非常重要的数字：[SIMD-OPP]

- copy-like helper 总数：**28,393**
- 其中保守识别下 **93.77%** 的 size 是常量

但这个数字不能直接解释成“SIMD 很有机会”，因为构成是：

- `probe_read_kernel`: **25,296**
- `probe_read_kernel_str`: **1,728**
- `skb_load_bytes`: **590**
- `skb_store_bytes`: **536**
- `xdp_load_bytes`: **7**
- `copy_from_user`: **23**

含义是：

- **大量 copy-like helper 发生在 tracing/helper-heavy 世界**
- 这些 helper 的内部实现不由 BPF JIT 控制

所以：

> **helper 数量很多，不等于 JIT SIMD 机会很多。**

这个结论对任务边界很关键：  
BpfReJIT 能直接优化的是 **inline/native-emittable 的 block memory / scalarized load-store run**，而不是把 `bpf_probe_read_kernel()` 的内部逻辑替换成 SIMD。

## 4.4 map lookup / hash：看起来热，但不在 JIT 的可控面

另一份地图内联分析给出：[MAP-OPP]

- 全 corpus 里有 **11,556 个静态 `bpf_map_lookup_elem` call site**
- “真实 workload 子集”里也有 **11,231 个**

这说明 hash / map access 确实常见。  
但这对“SIMD FPU kinsn”的意义很有限，因为：

- helper 调用本身是 `call 0x1`
- 真正 hash 表实现、桶探测、prefetch、bitmap 操作在 **内核 map 实现**里
- BpfReJIT 不能直接向量化 helper 内部

因此：

- **hash computation** 不是优先的 BpfReJIT SIMD 方向
- 如果要碰这个方向，更像是 map specialization / helper bypass / data-structure co-design，而不是 `kernel_fpu_begin()` 包一层

## 4.5 macro corpus object-level 下界扫描

这是本次最关键的定量结果之一。

### 4.5.1 保守下界：明确的 bulk zeroing/store-run

对 `macro_corpus` 的 **477 个唯一 `.bpf.o`** 做保守 store-run 检测，得到：

- **891 个** `>=64B` 的 contiguous store-run site
- 分布在 **72 个 object**
- 这些 object 覆盖：
  - **30 个 XDP/TC object**
  - **31 个 networking-category object**

按 size 分桶：

| 阈值 | 全部 site 数 | XDP/TC site 数 |
| --- | ---: | ---: |
| `>=64B` | 891 | 317 |
| `>=128B` | 353 | 27 |
| `>=256B` | 173 | 14 |
| `>=512B` | 4 | 0 |
| `>=1024B` | 1 | 0 |

这组数字非常有解释力：

- **bulk-memory 机会是真实存在的**
- 但当阈值抬到 **x86 FPU-friendly 的 512B 以上**时，**networking/XDP/TC 的 store-run 基本消失了**

这直接意味着：

> **对 x86 而言，`kernel_fpu_begin()` 的 phase-2 gate 一旦设到 512B，真正会触发的 memcpy/memset 站点会非常少。**

### 4.5.2 object-level upper bound：哪些 program entry 所在 object 含有机会点

把 “object 含有至少一个 `>=64B` store-run” 映射回 `macro_corpus.yaml` program entry，可得到 **上界**：

- **219 / 764** 个 program entry 所在 object 含有 `>=64B` store-run
- **146 / 296** 个 XDP/TC program entry 所在 object 含有 `>=64B` store-run
- **127 / 174** 个 networking-related program entry 所在 object 含有 `>=64B` store-run

请注意，这里是 **object-level upper bound**，不是说 219 个 program section 本身都一定有 bulk-memory site。

### 4.5.3 代表性站点

从扫描结果和已有设计文档综合看，最典型的站点是：

| 站点 | 类型 | 规模 | 含义 |
| --- | --- | --- | --- |
| `calico/xdp_no_log.bpf.o:calico_xdp_main` | XDP | `58 x STXDW = 464B` | 典型大对象清零 [SIMD-DESIGN] |
| `calico/*hep*/*nat*/*wep*` 多个 TC object | TC | 大量 `464B` 零化 | 同类模式出现很多 |
| `loxilb/llb_xdp_main.bpf.o:xdp_packet_func` | XDP | `360` 连续 byte store | 典型 byte-wise scalarization [SIMD-DESIGN] |
| `loxilb/llb_ebpf_main.bpf.o:tc_packet_hook2` | TC | 约 `1105B` mixed block move | 这是 store-run 扫描漏掉、但人工分析抓到的大块 copy [SIMD-DESIGN] |
| `cilium/bpf_lxc.bpf.o:tail_icmp6_send_time_exceeded` | TC | `74B` stack zeroing | 中小块清零 [SIMD-DESIGN] |
| `xdp-tools/xdp_flowtable.bpf.o:xdp_fwd_flow_full` | XDP | `64B` stack zeroing | 小块但明确的 bulk-memory candidate [SIMD-DESIGN] |

### 4.5.4 对 corpus 的总体判断

可以把 corpus 机会面分成三层：

1. **强机会面**：`64B-512B` 的 zeroing / fixed block copy  
   这正是 `rep movsb/stosb`、`LDP/STP`、`STP XZR` 的主战场
2. **弱但存在的机会面**：`>=512B` 的超大块 copy / checksum  
   这才进入“也许值得 FPU/SIMD”的区间
3. **几乎没有的机会面**：Bloom / generic string-SIMD / gather-heavy packet parsing  
   corpus 里看不到足够强的证据

---

## 5. 按模式拆分：哪些操作真的适合 SIMD/FPU kinsn

## 5.1 `memcpy/memset (>128B)`：有机会，但主要是 **no-FPU**

这是最明确的机会面。

但是要分清：

- **“有 bulk-memory 机会”**
- 和
- **“值得进 FPU/NEON section”**

不是一回事。

从 corpus 看：

- `360B`、`464B` 这类站点很多
- `74B`、`64B` 这类也不少
- 真正 `>=512B` 的网络站点很少，只有人工分析抓到的个别 mixed-copy 例子（如 loxilb 1105B）

因此：

> **memcpy/memset 的主收益应该来自 no-FPU bulk backend，而不是 SSE2/AVX2/NEON。**

## 5.2 CRC32 / checksum：是真机会，但第一步不是 FPU

这里有一个容易被混淆的点：

- **x86 `crc32b/w/l/q` 是 GPR/整数指令，不需要 FPU**
- **ARM64 `crc32{b,h,w,x}` / `crc32c*` 也是标量指令**

真正需要 FPU/NEON 的，是：

- x86 的 `PCLMULQDQ` / `VPCLMULQDQ`
- ARM64 的 `PMULL`

内核本身已经给出门槛：[KCRC-X86][KCRC-ARM64]

- x86 `CRC32C_PCLMUL_BREAKEVEN = 512`
- ARM64 `min_len = 1024`

这其实就是 Linux 自己的工程判断：

> **小中等长度先走标量 CRC，只有大块数据才值得进 SIMD/PMULL。**

对 BpfReJIT 的意义非常直接：

- `bpf_crc32(c)` **值得做**
- 但 **phase 2 的第一步**应该是 **scalar CRC instruction chain**
- 不必把 `bpf_crc32(c)` 自动等价成 “必须引入 FPU kinsn”

## 5.3 Bloom filter probe：理论上适合 SIMD，实际 corpus 支撑很弱

理论上，Bloom filter probe 很适合：

- bitset parallelism
- 多个 hash position 的并行检查
- bitmap vector AND

但现实是：

- 我这次源码扫描里只看到 **3 个 BPF 实现文件**提到 `BPF_MAP_TYPE_BLOOM_FILTER`
- 基本都在 selftests
- `macro_corpus.yaml` 里没有一个明显的 production bloom workload

所以结论很简单：

> **Bloom filter probe 是“理论上适合 SIMD，实际 corpus 不支持”的方向。**

## 5.4 字符串 / 模式匹配（`PCMPISTRI` / `PCMPISTRM`）：低优先级

源码扫描里，字符串匹配相关命中：

- **36 个文件**
- **80 次命中**

但分布主要在：

- selftests
- tracee
- 一些非 dataplane 风格代码

同时，packet fast path 真正大规模扫描 payload 的程序在 corpus 里并不多。  
对 BPF 而言，字符串匹配还会碰到：

- verifier 边界
- 变长输入
- 循环 / 提前退出

所以这个方向不适合作为第一波 kinsn。

## 5.5 Hash computation：主要不在 BpfReJIT 可控面

`bpf_map_lookup_elem()` 很多，但 map hash 实际发生在 helper / map implementation 内部。  
因此：

- **“hash computation 很常见” 是对的**
- **“所以应该给 BPF JIT 做 SIMD hash kinsn” 不成立**

除非未来做的是：

- map bypass
- map specialization
- fixed key-layout / inline hash pipeline

否则它不在当前议题里。

## 5.6 Packet field extraction / gather loads：单包模型下不适合

单包 BPF parser 的常见特征是：

- 读几个固定 offset header field
- 很少凑得满 128/256-bit lane
- 常伴随边界检查和条件分支

这不适合：

- AVX2 gather
- AVX-512 gather
- “把多个不相邻 field 拼成一个向量”

因为：

- gather 本身延迟高
- 需要 FPU/XMM/YMM/ZMM
- 单包场景没有 Swift/X2DP 式 batch lane

对这类模式，更现实的优化是：

- ARM64 `LDP/STP`
- x86 no-FPU bulk-memory
- 常量传播 / DCE / branch simplification

而不是 generic gather SIMD。

---

## 6. Break-even 分析

## 6.1 分析框架

我用一个非常简单但足够有解释力的模型：

```
break_even_bytes = fixed_overhead_cycles / (scalar_cycles_per_byte - simd_cycles_per_byte)
```

核心不是追求“每台机器都精确”，而是看数量级。

### 6.1.1 x86 假设

- `kernel_fpu_begin/end` 的 **固定税**：`300-500 cycles`
- SIMD 数据通路理想化吞吐：
  - SSE2: `16 B/cycle`
  - AVX2: `32 B/cycle`
  - AVX-512: `64 B/cycle`

### 6.1.2 ARM64 假设

- plain NEON/FPSIMD 的 **固定税**：`80-120 cycles`（工程估计）
- 向量数据通路：
  - NEON: `16-32 B/cycle` 量级

### 6.1.3 baseline 也要分层

不能只拿 SIMD 去比“最烂的 byte-by-byte scalar path”。  
真正应该比的是三层 baseline：

1. **byte-store scalarized horror**
2. **qword-store scalar path**
3. **已有 no-FPU bulk path**（x86 `rep movsb/stosb`，ARM64 `LDP/STP` / `STP XZR`）

这三层给出的 break-even 会完全不同。

## 6.2 x86：FPU tax vs SSE2 / AVX2 / AVX-512

### 6.2.1 如果 baseline 是“最差的 byte-store scalar”

| 比较 | `300 cyc` | `400 cyc` | `500 cyc` |
| --- | ---: | ---: | ---: |
| byte-store -> SSE2 | 320B | 427B | 533B |
| byte-store -> AVX2 | 310B | 413B | 516B |
| byte-store -> AVX-512 | 305B | 406B | 508B |

这解释了一个现象：

- `loxilb` 那种 **360 个 byte store** 的路径，  
  **如果没有 `rep stosb` 这种 no-FPU 替代**，AVX2 的确可能开始接近 break-even

但问题在于：

> **x86 已经有 `rep movsb/stosb` 这个更自然、更便宜、无 FPU 的替代方案。**

所以即便这种“最差 byte-store path”存在，也不是 FPU/SIMD 的 strongest argument。

### 6.2.2 如果 baseline 是“qword-store scalar”

| 比较 | `300 cyc` | `400 cyc` | `500 cyc` |
| --- | ---: | ---: | ---: |
| qword-store -> SSE2 | 4.8KiB | 6.4KiB | 8.0KiB |
| qword-store -> AVX2 | 3.2KiB | 4.27KiB | 5.33KiB |
| qword-store -> AVX-512 | 2.74KiB | 3.66KiB | 4.57KiB |

这组数字直接告诉我们：

- `calico` 那种 **464B = 58 x STXDW** 零化  
  **远远不够 justify x86 FPU SIMD**

即便你把 AVX2 看得很乐观，也还差近一个数量级。

### 6.2.3 如果 baseline 已经是 no-FPU bulk path

再假设：

- `rep movsb/stosb` 这类 no-FPU 路径至少能做到 `16 B/cycle`
- AVX2 做到 `32 B/cycle`
- AVX-512 做到 `64 B/cycle`

则 break-even 变成：

| 比较 | `300 cyc` | `400 cyc` | `500 cyc` |
| --- | ---: | ---: | ---: |
| no-FPU bulk(16B/cyc) -> AVX2 | 9.6KiB | 12.8KiB | 16.0KiB |
| no-FPU bulk(16B/cyc) -> AVX-512 | 6.4KiB | 8.53KiB | 10.67KiB |

这基本宣判了：

> **在 x86 上，一旦 `rep movsb/stosb` 已经在位，SSE2/AVX2/AVX-512 对 BPF 的 memcpy/memset 几乎不再是 corpus 尺度上的主收益面。**

## 6.3 ARM64：NEON vs plain FPSIMD / LDP-STP

对 ARM64，先看“plain scalar / qword-store” baseline：

| 比较 | `80 cyc` | `120 cyc` |
| --- | ---: | ---: |
| qword-store -> NEON(16B/cyc) | 1.28KiB | 1.92KiB |

如果 baseline 再提升到：

- `LDP/STP` / `STP XZR`
- 也就是一个已经不错的 no-FPU bulk path

那么 true NEON 的 break-even 会进一步往上推。  
保守看，**1KiB 以上**才开始值得认真讨论，这和内核 `PMULL` 的 `min_len = 1024` 是同方向的。[KCRC-ARM64]

所以 ARM64 的真实判断是：

- **比 x86 更有可能成立**
- 但 **在 `LDP/STP` 已经存在之后，true NEON 也不会在 64B/128B/464B 这种区间上成为第一选择**

## 6.4 `kernel_fpu_begin()` / `kernel_neon_begin()` 能否按“每次 BPF 执行只进一次”来摊销？

理论上可以想象两种模式：

1. **每个 SIMD kinsn site 自己 begin/end**
2. **整个 BPF program prologue/epilogue 只包一次**

第二种看上去更美，但现实问题很多：

- x86 begin/end 期间会关 BH / preempt（视上下文而定）[KX86-API][KDOC-FP]
- 内核文档明确要求 FP critical section 要尽量小 [KDOC-FP]
- BPF program 中间可能有：
  - helper calls
  - tail calls
  - bpf2bpf
  - 复杂控制流
- 把整个 program 都包进 FPU critical section，会把“固定税”摊薄，但把“临界区风险”放大

因此：

> **“每次 BPF 执行只进一次 FPU”在理论上能摊销，但在实际 Linux 内核工程上通常不是好主意。**

对 OSDI'26 来说，更可信的策略是：

- **只在单个大块操作内部包 begin/end**
- 或直接避免 FPU，走 no-FPU backend

## 6.5 运行频率视角：几千次/秒 vs 百万次/秒

把固定税换算成单核占比，很直观：

假设 3.5GHz 核心：

| 固定税 | `10k exec/s` | `1M exec/s` | `5M exec/s` |
| --- | ---: | ---: | ---: |
| 80 cycles | 0.02% | 2.29% | 11.4% |
| 120 cycles | 0.03% | 3.43% | 17.1% |
| 300 cycles | 0.09% | 8.57% | 42.9% |
| 400 cycles | 0.11% | 11.43% | 57.1% |
| 500 cycles | 0.14% | 14.29% | 71.4% |

因此：

- **几千次/秒**：FPU tax 几乎可以忽略
- **百万次/秒级 packet path**：x86 的 FPU tax 已经是一级成本项

这点非常关键，因为：

- tracing / LSM / kprobe 类程序的调用频率可能只有几千到几万次/秒
- XDP/TC dataplane 程序却可能是 **百万次/秒甚至更高**

所以“FPU tax 高不高”的答案不是单一的：

> **对 tracing 可能没那么可怕；对 packet path 则是绝对不能忽视。**

---

## 7. Linux 现有子系统的 SIMD 模式

## 7.1 crypto 子系统：Linux 已经给出了正确的工程姿势

crypto 通用层的策略是：

- `crypto_simd_usable()` 先检查 `may_use_simd()`，并允许 selftest 时强制关闭 SIMD [KCRYPTO-SIMD]
- 如果不可用，generic `crypto/simd.c` 会转向 fallback/`cryptd` 路径，而不是硬上 SIMD [KCRYPTO-SIMD-C]

x86 crypto glue 的模式非常一致：

- `kernel_fpu_begin()`
- 调汇编/向量实现
- `kernel_fpu_end()`

而且不是“永远包整次请求”，而是经常：

- **按 walk/chunk 分段**
- **给小尾巴退出 FPU，继续走标量**

`arch/x86/crypto/ecb_cbc_helpers.h` 甚至直接把门槛做成了 `fpu_blocks`：  
当块数太小时，直接 `kernel_fpu_end()` 退出 FPU path。[KCRYPTO-ECB]

ARM64 crypto 则大量使用 `scoped_ksimd()`，也是：

- 每个 chunk / walk 进入
- 处理完就退出 [KCRYPTO-AES-ARM64]

`ghash-ce-glue.c` 里还有一句很典型的话：

> `/* avoid hogging the CPU for too long */`，所以它把 chunk 限成 `64KB`。[KCRYPTO-GHASH-ARM64]

### 7.1.1 crypto 模式对 BpfReJIT 的直接启发

Linux crypto 给出的范式是：

1. **先判断 SIMD 是否可用**
2. **只对足够大的 chunk 用 SIMD**
3. **必须有 fallback**
4. **critical section 尽量小**

这几条几乎可以原封不动地迁移到 BpfReJIT 的工程准则里。

但也要看到一个关键差异：

- crypto 往往处理的是 **大块、流式、可 chunk 的数据**
- BPF datapath 里很多候选站点只是 **64B / 74B / 464B 的零化/复制**

这就是为什么 crypto 的成功模式 **并不能反推**“BPF 里也应该默认上 FPU SIMD”。

## 7.2 更像 BpfReJIT 邻居的例子：`nft_set_pipapo_avx2`

比 crypto 更值得参考的，其实是 netfilter 的 `pipapo_avx2`。

这是 Linux **网络数据路径**里真正的 AVX2 例子。[KNET-PIPAPO]

它的模式非常克制：

1. 先在 datapath front-end 检查 `irq_fpu_usable()`；不行就 **退回 generic lookup** [KNET-PIPAPO]
2. 进入 fast path 后，调用 `kernel_fpu_begin_mask(0)`  
   代码注释明确说明：**这里不需要有效 MXCSR，所以传 0，省一条 `LDMXCSR`** [KNET-PIPAPO]
3. 只针对一个非常特定的位图/lookup 算法发射 AVX2 kernel

这给出三个非常重要的工程启发：

- **内核网络子系统里确实可以用 AVX2**
- 但必须是 **高度特化** 的算法，不是“打开 SIMD 模式后什么都向量化”
- 必须有 **context gate + generic fallback**

这几乎直接支持我对 BpfReJIT 的建议：

> **如果以后真的做 SIMD/FPU kinsn，它应该是少数几个高度语义化的 operation，而不是一个“通用向量模式”。**

---

## 8. 实现复杂度评估

## 8.1 需要多少新 kinsn/module？

如果按“最小可行集”来做，我建议的 BPF-visible 语义操作只有三类：

1. `bpf_memcpy_fast`
2. `bpf_memset_fast`
3. `bpf_crc32` / `bpf_crc32c`

这三类里：

- 前两类 **v1 就能做，但 backend 先是 no-FPU**
- 第三类 **phase 2 才做，但第一版也先是 scalar CRC 指令**

因此，不应该把 module 设计成：

- `bpf_simd_enter`
- `bpf_simd_exit`
- `bpf_avx2_memcpy`
- `bpf_neon_memcpy`

这种把“寄存器/上下文细节”暴露给上层的形态。

更合理的是：

> **保持 semantic kinsn 不变，把 no-FPU / scalar / SIMD 作为 backend selection。**

## 8.2 verifier：XMM/NEON 寄存器不必暴露，但 side condition 很烦

好消息是：

- BPF verifier 不需要真的理解 XMM/YMM/ZMM/NEON 寄存器
- 只要 kinsn 仍然能被 instantiate 成等价的普通 BPF 证明序列，就可以让 native emitter 在内部偷偷用 SIMD reg

所以 verifier 层的主问题不是“给 verifier 增加 XMM 类型系统”，而是：

1. **操作的语义边界是否清晰**
2. **能否给出简单的 instantiate-only proof sequence**
3. **什么时候允许 backend 选 SIMD/FPU**

这也是为什么：

- `memcpy_fast` / `memset_fast` 相对容易
- `crc32` 可以做，但比前两者难一点
- `memcmp` / string scan / gather-heavy op 会一下子复杂很多

## 8.3 不同架构的实现复杂度差异

### x86

复杂点包括：

- `irq_fpu_usable()`
- `kernel_fpu_begin/end`
- xstate 大小不固定
- `PF_KTHREAD` / `TIF_NEED_FPU_LOAD` 导致成本与上下文相关
- AVX-512 频率问题

### ARM64

复杂点包括：

- `may_use_simd()`
- `kernel_neon_begin/end`
- `TIF_FOREIGN_FPSTATE`
- `TIF_KERNEL_FPSTATE`
- 如果用户态 live SVE/SME，则成本可能显著膨胀

但总体上：

> **ARM64 的 true SIMD/FPSIMD path 仍然比 x86 更“规则”、更好解释。**

## 8.4 测试：QEMU TCG 可以测功能，不能测真实性能

这一点必须明确写进设计里：

- **QEMU TCG 可以做功能正确性和 fallback 覆盖**
- 但 **不能用来判断 SIMD/FPU break-even**

原因很简单：

- TCG 对向量指令的时延/吞吐没有真实意义
- TCG 不会真实反映 XSAVE/xstate/cache/frequency 行为

所以测试策略应该拆成两层：

1. **功能层**：
   - feature present / absent
   - `irq_fpu_usable()` / `may_use_simd()` gate
   - fallback correctness
2. **性能层**：
   - 裸机
   - 或至少 host pass-through 足够真实的 VM

## 8.5 单一 `bpf_simd_memcpy` 还是 operation family？

建议是 **operation family**，不是“一个 generic SIMD kinsn”。

理由：

- `memcpy/memset`
- `crc32/c`
- 将来可能的 `bitset_match`

它们的：

- verifier 语义
- gate 条件
- backend 选择

都不一样。

所以最合理的抽象层次是：

> **保留按语义划分的 kinsn family，让每个 family 内部自己做 no-FPU / scalar / SIMD backend dispatch。**

---

## 9. 明确推荐

## 9.1 最终 verdict

### 9.1.1 x86

**结论：`NO` 作为 OSDI'26 主线；`CONDITIONAL YES` 作为后续窄路径。**

更具体地说：

- **不要**把 x86 `AVX2/AVX-512 memcpy/memset` 放进论文主线
- **不要**把 “SIMD kinsn” 在 x86 上实现成“默认广泛用 FPU”
- **可以**保留一个未来 phase 2 方向：
  - 先做 `bpf_crc32/c` 的 scalar 版
  - 再看极少数 `>=1-2KiB` 的大块 copy/checksum 是否值得 `PCLMUL/AVX2`

### 9.1.2 ARM64

**结论：`CONDITIONAL YES`。**

原因是：

- common-case FPSIMD state 更小
- NEON path 比 x86 AVX path 更自然
- 但一旦 `LDP/STP` / `STP XZR` 已经存在，true NEON 的 break-even 仍然会被推到较大块

因此 ARM64 的建议是：

- v1：`LDP/STP` / `STP XZR` + scalar CRC
- phase 2：只在 **`>=1KiB`** 且 `may_use_simd()` 成立时讨论 true NEON/PMULL

## 9.2 最小可行集合（MVP）

如果现在要为 BpfReJIT 选一套既能写论文、又不把工程拖炸的最小集合，我的推荐是：

1. **`bpf_memcpy_fast`**
   - x86: `rep movsb`
   - ARM64: `LDP/STP`
2. **`bpf_memset_fast`**
   - x86: `rep stosb`
   - ARM64: `STP XZR`
3. **`bpf_crc32/c`**
   - x86: scalar `crc32b/w/l/q`
   - ARM64: scalar `crc32*` / `crc32c*`

而不是：

- SSE2 memcpy
- AVX2 memset
- AVX-512 anything
- generic string-SIMD
- Bloom / gather / hash SIMD

## 9.3 对论文叙事的建议

我认为 SIMD/FPU 完全可以出现在 paper 里，但方式要对。

正确讲法是：

1. **semantic kinsn 让 JIT 能恢复更宽机器语义**
2. **这个 frontier 分两层**
   - 第一层：no-FPU bulk memory / scalar CRC
   - 第二层：context-sensitive true SIMD
3. **这层 frontier 具有强 ISA asymmetry**
   - ARM64 plain NEON 更友好
   - x86 AVX 带 xstate/FPU/downclock 包袱

如果这么讲，它是一个很好的 **architectural insight**。  
如果讲成“我们给内核 BPF 大规模上 AVX2/NEON，性能很强”，则证据并不支持。

## 9.4 最终建议（一句话版本）

> **OSDI'26 主线：YES to wide-machine kinsn，NO to x86 true-SIMD mainline。**

展开就是：

- **主线做**：`rep movsb/stosb`、`LDP/STP`、`STP XZR`、scalar CRC
- **附录/未来工作做**：ARM64 NEON/PMULL，x86 极少数大块 `PCLMUL/AVX2`
- **明确不做**：AVX-512 主线化、generic gather/string/bloom SIMD

---

## 10. 参考资料

### 仓库内/内核源码

- [PLAN] `docs/kernel-jit-optimization-plan.md`
- [SIMD-DESIGN] `docs/tmp/20260324/simd_kinsn_design_20260324.md`
- [WIDE-LDST] `docs/tmp/20260324/128bit_wide_loadstore_research_20260324.md`
- [SIMD-OPP] `docs/tmp/20260323/simd_constprop_opportunity_analysis_20260323.md`
- [CALL-STATS] `docs/tmp/20260326/corpus_call_statistics_20260326.md`
- [MAP-OPP] `docs/tmp/20260323/map_inlining_opportunity_analysis_20260323.md`
- [KDOC-FP] `vendor/linux-framework/Documentation/core-api/floating-point.rst`
- [KX86-API] `vendor/linux-framework/arch/x86/include/asm/fpu/api.h`
- [KX86-CORE] `vendor/linux-framework/arch/x86/kernel/fpu/core.c`
- [KX86-SCHED] `vendor/linux-framework/arch/x86/include/asm/fpu/sched.h`
- [KX86-XSTATE] `vendor/linux-framework/arch/x86/include/asm/fpu/xstate.h`
- [KX86-TYPES] `vendor/linux-framework/arch/x86/include/asm/fpu/types.h`
- [KARM-SIMD] `vendor/linux-framework/arch/arm64/include/asm/simd.h`
- [KARM-FPSIMD] `vendor/linux-framework/arch/arm64/kernel/fpsimd.c`
- [KARM-UAPI] `vendor/linux-framework/arch/arm64/include/uapi/asm/ptrace.h`
- [KARM-SIG] `vendor/linux-framework/arch/arm64/include/uapi/asm/sigcontext.h`
- [KCRC-X86] `vendor/linux-framework/lib/crc/x86/crc32.h`
- [KCRC-ARM64] `vendor/linux-framework/lib/crc/arm64/crc32.h`
- [KCRYPTO-SIMD] `vendor/linux-framework/include/crypto/internal/simd.h`
- [KCRYPTO-SIMD-C] `vendor/linux-framework/crypto/simd.c`
- [KCRYPTO-ECB] `vendor/linux-framework/arch/x86/crypto/ecb_cbc_helpers.h`
- [KCRYPTO-AESNI] `vendor/linux-framework/arch/x86/crypto/aesni-intel_glue.c`
- [KCRYPTO-AES-ARM64] `vendor/linux-framework/arch/arm64/crypto/aes-glue.c`
- [KCRYPTO-GHASH-ARM64] `vendor/linux-framework/arch/arm64/crypto/ghash-ce-glue.c`
- [KNET-PIPAPO] `vendor/linux-framework/net/netfilter/nft_set_pipapo_avx2.c`

### 外部资料

- [P1] Wu, Richard et al. **Swift: A Fast Dynamic Packet Filter**. NSDI 2008.  
  https://www.usenix.org/legacy/events/nsdi08/tech/full_papers/wu/wu.pdf
- [P2] Farshin, Amin et al. **PacketMill: Toward Per-Core 100-Gbps Networking**. ASPLOS 2021.  
  https://people.kth.se/~farshin/documents/packetmill-asplos21.pdf
- [P3] Fried, Joshua et al. **Making Kernel Bypass Practical for the Cloud with Junction**. NSDI 2024.  
  https://www.usenix.org/system/files/nsdi24-fried.pdf
- [P4] Brunella, Claudio et al. **hXDP: Efficient Software Packet Processing on FPGA NICs**. OSDI 2020.  
  https://www.usenix.org/conference/osdi20/presentation/brunella
- [P5] **X2DP**. SIGCOMM 2025 Demos/Posters program.  
  https://conferences.sigcomm.org/sigcomm/2025/posters_demos.html
- [P6] Brunthaler, Stefan. **Vectorization in PyPy's Tracing Just-In-Time Compiler**. VMIL 2013.  
  https://publications.cispa.saarland/1693/1/p47-brunthaler.pdf
- [P7] **JITSPMM: Just-in-Time Compilation for Sparse Matrix-Matrix Multiplication on CPUs**. arXiv 2024.  
  https://arxiv.org/abs/2407.17416
- [P8] **DPDK 19.11 Release Notes**（runtime scalar/vector/AVX2 burst mode 选择）  
  https://doc.dpdk.org/guides-19.11/rel_notes/release_19_11.html
- [P9] **[PATCH 1/4] tracing/fpu: Add trace events for x86 FPU registers operations**（讨论 XSAVE(S) tracepoint 与 cycles 量级）  
  https://patchew.org/linux/20230901143414.1664368-1-yi.sun%40intel.com/20230901143414.1664368-2-yi.sun%40intel.com/
- [P10] **[PATCH 2/5] x86: Use XSAVEC for _dl_runtime_resolve**（glibc 讨论中给出 XSAVEC 相关 cycle 量级）  
  https://patchwork.ozlabs.org/project/glibc/patch/20171019174144.GA26576@gmail.com/

---

## 11. 本报告里哪些是“源码事实”，哪些是“推断”

为避免把工程估计写成硬事实，这里单独列出来：

### 11.1 直接由源码/文档证实的

- x86 `kernel_fpu_begin/end` 的调用路径与语义
- x86 是 eager save + deferred restore，而不是 old lazy `#NM` model
- x86 xstate 组件大小（512B / 64B / 256B / 1600B 等）
- ARM64 `kernel_neon_begin/end` 的 ownership 模型
- ARM64 plain FPSIMD state = 528B
- x86 CRC `512B` 和 ARM64 PMULL `1024B` 门槛
- crypto / pipapo 的 gate + fallback 模式
- AVX-512 可能影响 max clock

### 11.2 明确标了“推断/工程估计”的

- x86 “一次 BPF 执行可见的 FPU 固定税 ≈ 300-500 cycles typical”
- ARM64 plain NEON/FPSIMD 固定税 “≈ 60-120 cycles”
- AMD Zen 上 XSAVE/XRSTOR 的具体 cycles（未找到同等级公开微基准，只能推断同数量级）
- break-even 表中的 B/cycle 假设

这部分在后续若要进入论文正文，建议配一组 **bare-metal microbench** 来把估计收敛成实测。
