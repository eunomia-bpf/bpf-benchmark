# x86-64 128-bit 宽 load/store kinsn 设计报告

日期：2026-03-26  
状态：design only  
结论标签：**x86 pair load/store 不建议走 SIMD；x86 的“16B 宽机会”应并入 Bulk memory，而不是做 `ldp/stp` 风格 kinsn**

## 0. 文档目标与方法

本文回答的问题不是“x86 有没有 16B 指令”，而是：

1. 在 **BpfReJIT 当前 kinsn v2 框架** 下，x86-64 是否值得为 `memory <-> two GPR` 设计一个真正的 128-bit 宽 load/store kinsn。
2. 如果要做，最佳 native 路线是：
   - SSE2 `MOVDQU/MOVDQA`
   - AVX `VMOVDQU`
   - `REP MOVSB`
   - 继续用两条普通 `mov`
3. FPU 上下文成本、程序类型上下文约束、verifier 建模、daemon 选路，最终应该如何落地。

本报告基于以下来源：

- 仓库内设计与实现：
  - `docs/kernel-jit-optimization-plan.md`
  - `docs/tmp/20260324/128bit_wide_loadstore_research_20260324.md`
  - `docs/tmp/20260324/simd_kinsn_design_20260324.md`
  - `docs/kinsn-design.md`
  - `module/include/kinsn_common.h`
  - `module/x86/*.c`
  - `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`
  - `vendor/linux-framework/Documentation/core-api/floating-point.rst`
  - `vendor/linux-framework/arch/x86/include/asm/fpu/api.h`
  - `vendor/linux-framework/arch/x86/include/asm/simd.h`
  - `vendor/linux-framework/arch/x86/include/asm/fpu/sched.h`
  - `vendor/linux-framework/arch/x86/kernel/fpu/core.c`
  - `vendor/linux-framework/arch/x86/kernel/fpu/context.h`
  - `vendor/linux-framework/arch/x86/lib/memcpy_64.S`
  - `vendor/linux-framework/arch/x86/lib/memset_64.S`
- 本地静态建模：
  - `llvm-mca 18.1.3`，`-mcpu=skylake/znver4/arrowlake-s`
  - `objdump` 对典型序列的机器码长度统计

方法说明：

- `llvm-mca` 只用于 **纯指令级** latency / throughput 比较，不用于估计 `rep movsb` 的真实 copy-engine 行为。
- `rep movsb/stosb` 的判断以仓库内 Linux x86 string routine 选择逻辑为主；`llvm-mca` 对 `rep` 指令的数字不可直接当真实性能。
- 本文明确区分两类语义：
  - **Pair load/store**：`memory <-> two GPR`，即 ARM64 `LDP/STP` 那类语义
  - **Bulk copy 16B**：`memory -> temp -> memory`，即 `memcpy128`

这两类语义在 x86 上的最优 native 指令不同，不能混成一个结论。

---

## 1. 执行摘要

### 1.1 最终建议

**结论先行：**

1. **Option D（两条普通 `mov`）应作为 x86 `wide_load128/store128` 的默认答案。**  
   对 `memory <-> two GPR` 语义，SSE2/AVX 的 pack/unpack 成本已经让它在指令级上输给两条普通 `mov`，更不要说 FPU section。
2. **Option C（`REP MOVSB`）是 x86 的正确“16B 宽机会”，但它只适用于 `memcpy`-like bulk memory，不适用于 pair load/store。**
3. **Option A/B（SSE2 / AVX）不适合做 x86 pair load/store kinsn。**  
   它们只在 `memory -> XMM -> memory` 的 bulk copy 上才有机会；即便如此，也必须把 `kernel_fpu_begin/end()` 的固定成本按**整次 BPF 程序调用**摊销，而不是按单条 kinsn。
4. **如果论文需要统一抽象，可以保留 `bpf_ldp64/bpf_stp64` 的架构无关语义，但 x86 只做 scalar emit 或 instantiate-only。**
5. **x86 的性能 story 应放在 Bulk memory kinsn：`rep movsb/stosb` phase 1，SIMD phase 2。**  
   这和 ARM64 `LDP/STP` 的 free win 形成了非常好的架构对比。

### 1.2 选项结论矩阵

| 选项 | 对 `memory <-> two GPR` | 对 `memcpy128` | FPU | 推荐 |
| --- | --- | --- | --- | --- |
| A. SSE2 `MOVDQU/MOVDQA` | 指令级就不占优 | 仅在 bulk copy 有条件成立 | 需要 | **NO** for pair；**CONDITIONAL** for bulk phase 2 |
| B. AVX `VMOVDQU` | 指令级就不占优 | bulk copy 比 SSE2 更像 future path | 需要 | **NO** for pair；**CONDITIONAL** for bulk phase 2 |
| C. `REP MOVSB` | 语义不匹配 | 很匹配 | 不需要 | **YES** for bulk；**NO** for pair |
| D. Two `mov` | 完全匹配 | 作为小块 baseline 合理 | 不需要 | **YES** |

---

## 2. 当前仓库里的 x86 现实边界

### 2.1 当前 x86 BPF JIT 是纯 GPR 路线

`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c` 当前对内存访问的 lowering 非常直接：

- `emit_ldx()`：`BPF_DW` load -> `mov r64, [base+off]`
- `emit_stx()`：`BPF_DW` store -> `mov [base+off], r64`
- `emit_kinsn_desc_call()`：module 只负责发一小段原生 bytes；当前 x86 kinsn 都是 GPR-only 的短序列

也就是说，现状不是“已经有 XMM 支持，差一个 peephole”，而是：

- JIT 的寄存器模型、调用点、异常/fixup、模块 emit helper，全部默认 **不碰 XMM/YMM**
- 现有 `module/x86/*.c` 也都只发射短小的整数/标量序列

### 2.2 当前 kinsn v2 的 verifier 模型是 proof sequence，不是 effect DSL

`docs/kinsn-design.md` 已经确定：

- `instantiate_insn(payload, insn_buf)` 是唯一 canonical 语义源
- verifier 通过 proof lowering 分析普通 BPF 指令序列
- native emit 只是 refinement

这对本文很重要，因为它意味着：

- **verifier 不需要知道 XMM/YMM**
- 但 native emit 若要用 SIMD，必须自己解决：
  - FPU 上下文合法性
  - 程序类型上下文限制
  - 可能的 runtime fallback

---

## 3. 技术选项分析

## 3.1 先区分语义匹配

| 方案 | 能否表达 `memory <-> two GPR` | 能否表达 `memory -> temp -> memory` | 备注 |
| --- | --- | --- | --- |
| SSE2 `MOVDQU/MOVDQA` | 能，但需要 XMM<->GPR pack/unpack | 能 | pair 语义不自然 |
| AVX `VMOVDQU` | 能，但同样要 pack/unpack | 能 | 对 pair 仍不自然 |
| `REP MOVSB` | **不能** | **能** | 本质是 memory-to-memory primitive |
| Two `mov` | **能** | 能，但 16B copy 要 4 条 `mov` | pair 语义最自然 |

核心点：

- **ARM64 `LDP/STP` 对应的是 pair GPR access**
- **x86 `rep movsb` 对应的是 bulk copy**
- 把两者都叫“128-bit 宽访存”可以，但 native 答案并不相同

## 3.2 指令级吞吐与代码大小

下面的数字基于本地 `llvm-mca` 和 `objdump`，都是 **典型 disp8 场景**。

### A. SSE2 `MOVDQU/MOVDQA`

典型 pair load / store 序列：

```asm
# load pair
movdqu  (%rdi), %xmm0
movq    %xmm0, %rax
psrldq  $8, %xmm0
movq    %xmm0, %rdx

# store pair
movq       %rax, %xmm0
movq       %rdx, %xmm1
punpcklqdq %xmm1, %xmm0
movdqu     %xmm0, (%rdi)
```

典型 16B copy 序列：

```asm
movdqu (%rsi), %xmm0
movdqu %xmm0, (%rdi)
```

代码大小（不含 `kernel_fpu_begin/end`）：

| 序列 | bytes |
| --- | ---: |
| pair load | 19 |
| pair store | 18 |
| memcpy128 | 8 |

`llvm-mca` 指令级 RThroughput：

| 序列 | Skylake | Zen4 | Arrow Lake |
| --- | ---: | ---: | ---: |
| pair load | 2.0 | 2.5 | 2.0 |
| pair store | 3.0 | 2.5 | 2.0 |
| memcpy128 | 1.0 | 1.0 | 0.5 |

load-side 关键依赖链：

- 低 64 位结果：约 8 / 9 / 10 cycles
- 高 64 位结果：约 9 / 11 / 11 cycles

对齐要求：

- `MOVDQA`：要求 16B 对齐，否则 fault；收益很小
- `MOVDQU`：允许非对齐
- 在本地 `llvm-mca` 模型里，`MOVDQA` 与 `MOVDQU` 的吞吐/延迟相同；因此单独为 `MOVDQA` 引入 verifier/daemon 对齐门槛没有明显价值

结论：

- 对 pair 语义，**SSE2 指令级已经输给两条普通 `mov`**
- 对 `memcpy128`，SSE2 确实能把 4 条 `mov` 压成 2 条 vector move，但仍受 FPU section 束缚

### B. AVX `VMOVDQU`

典型 pair load / store 序列：

```asm
# load pair
vmovdqu (%rdi), %xmm0
vmovq   %xmm0, %rax
vpsrldq $8, %xmm0, %xmm0
vmovq   %xmm0, %rdx

# store pair
vmovq       %rax, %xmm0
vmovq       %rdx, %xmm1
vpunpcklqdq %xmm1, %xmm0, %xmm0
vmovdqu     %xmm0, (%rdi)
```

代码大小（不含 FPU section）：

| 序列 | bytes |
| --- | ---: |
| pair load | 19 |
| pair store | 18 |
| memcpy128 | 8 |

`llvm-mca` 指令级 RThroughput：

| 序列 | Skylake | Zen4 | Arrow Lake |
| --- | ---: | ---: | ---: |
| pair load | 2.0 | 2.5 | 2.0 |
| pair store | 3.0 | 2.5 | 2.0 |
| memcpy128 | 1.0 | 1.0 | 0.5 |

AVX 相比 SSE2 的真实优点不是这 16B pair 序列更快，而是：

1. 可以全程使用 VEX 编码，避免 legacy SSE / AVX transition penalty
2. 未来可自然扩到 256-bit bulk copy

但对本题的 `memory <-> two GPR`：

- **pack/unpack 指令数没减少**
- **吞吐没改善**
- **仍然需要 FPU section**

所以 AVX 并没有把 pair load/store 变成好主意。

### C. `REP MOVSB`

典型核心序列：

```asm
mov $16, %ecx
rep movsb
```

代码大小（假设 `rdi/rsi` 已经是 dst/src）：

| 序列 | bytes |
| --- | ---: |
| `mov ecx, 16` + `rep movsb` | 7 |

优点：

- 不需要 `kernel_fpu_begin/end`
- 与内核当前 `memcpy_64.S` / `memset_64.S` 的方向一致
- 对 FSRM/FSRS / ERMS 机器特别自然

问题：

- **它不能表达 pair load/store**
- 只适合 `memcpy` / `memset`
- 需要 `RDI/RSI/RCX` 这种 canonical 寄存器形态；虽然 BPF JIT 映射里 `r1/r2/r4` 正好对应 `RDI/RSI/RCX`，但 isolated pair load/store 没法直接利用这一点

结论：

- **`REP MOVSB` 是 x86 Bulk memory kinsn 的好答案**
- **不是 x86 `bpf_wide_load128/store128` 的答案**

### D. Two `mov`

典型序列：

```asm
# load pair
movq (%rdi), %rax
movq 8(%rdi), %rdx

# store pair
movq %rax, (%rdi)
movq %rdx, 8(%rdi)
```

代码大小：

| 序列 | bytes |
| --- | ---: |
| pair load | 7 |
| pair store | 7 |
| memcpy128（load2+store2） | 14 |

`llvm-mca` 指令级 RThroughput：

| 序列 | Skylake | Zen4 | Arrow Lake |
| --- | ---: | ---: | ---: |
| pair load | 1.0 | 0.7 | 0.7 |
| pair store | 2.0 | 2.0 | 1.0 |
| memcpy128（4 mov） | 2.0 | 2.0 | 1.0 |

优点：

- 完全匹配 `memory <-> two GPR`
- 不碰 FPU/XMM
- verifier proof sequence 与 native 语义几乎完全重合
- 程序类型无额外上下文门槛

结论：

- **这是 x86 pair load/store 的 baseline，也是实际上最合理的 native emit**

## 3.3 选项总表

| 选项 | 典型 pair load bytes | 典型 pair store bytes | pair load RThroughput（SKL/Zn4/ARL） | pair store RThroughput（SKL/Zn4/ARL） | FPU | 对齐要求 |
| --- | ---: | ---: | --- | --- | --- | --- |
| SSE2 `MOVDQU` | 19 | 18 | 2.0 / 2.5 / 2.0 | 3.0 / 2.5 / 2.0 | 需要 | 无 |
| SSE2 `MOVDQA` | 19 | 18 | 与 `MOVDQU` 基本同级 | 与 `MOVDQU` 基本同级 | 需要 | **16B 对齐** |
| AVX `VMOVDQU` | 19 | 18 | 2.0 / 2.5 / 2.0 | 3.0 / 2.5 / 2.0 | 需要 | 无 |
| Two `mov` | 7 | 7 | **1.0 / 0.7 / 0.7** | **2.0 / 2.0 / 1.0** | 不需要 | 无 |
| `REP MOVSB` | N/A | N/A | N/A | N/A | 不需要 | 无 |

**结论非常直接：**

- 对 pair load/store，Option D 在指令级已经赢了
- Option A/B 只有在 `memcpy128` 语义下才有潜在意义

---

## 4. FPU 上下文成本深分析

## 4.1 `kernel_fpu_begin()/end()` 的实际实现

基于 `vendor/linux-framework/arch/x86/kernel/fpu/core.c`、`api.h`、`sched.h`、`context.h`，x86-64 当前逻辑可概括为：

### `kernel_fpu_begin_mask()`

1. `fpregs_lock()`
   - `!PREEMPT_RT`：`local_bh_disable()`
   - `PREEMPT_RT`：`preempt_disable()`
2. `irq_fpu_usable()`
   - NMI：不可用
   - 已经在 kernel FPU section 中：不可用
   - hardirq：只有在没打到 `fpregs_lock()` 保护区时才可用
   - process / softirq：通常可用
3. `kernel_fpu_allowed = false`
4. 如果当前是用户线程且 `!TIF_NEED_FPU_LOAD`：
   - `set_thread_flag(TIF_NEED_FPU_LOAD)`
   - `save_fpregs_to_fpstate(x86_task_fpu(current))`
5. `__cpu_invalidate_fpregs_state()`
6. 初始化控制寄存器：
   - `ldmxcsr(MXCSR_DEFAULT)`
   - 64-bit 下一般不走 `fninit`，除非显式请求 `KFPU_387`

### `kernel_fpu_end()`

1. `kernel_fpu_allowed = true`
2. `fpregs_unlock()`

### 含义

它不是一个“便宜地借用 XMM 两条指令”的 API，而是一个 **kernel FP critical section**：

- 可能保存当前用户态 FP/xstate
- 一定会关掉这段时间内的普通调度/softirq 进入路径
- 还要维护 `kernel_fpu_allowed` 和当前 CPU 的 fpregs ownership

这决定了：**它只能按“大块工作”摊销，不能按 16B pair op 摊销。**

## 4.2 现代内核是 eager save + lazy restore，不是老式 lazy FPU switching

需要区分两个“lazy”：

1. **老式 lazy task switching**：靠 #NM 在第一次用 FPU 时再 restore  
   这已经不是现代主线内核的策略。
2. **当前实现的 lazy restore before userspace**：  
   `switch_fpu()`/`kernel_fpu_begin()` 把状态存到内存并设置 `TIF_NEED_FPU_LOAD`；真正 restore 发生在 `switch_fpu_return()` / `fpregs_restore_userregs()` 这类“返回用户态前”路径。

所以现代 6.x+/7.x 线上的实际形态是：

- **save 偏 eager**
- **restore 偏 lazy**

这对本文的含义是：

- “BPF 程序当前在 kernel 中执行，所以也许 XMM 已经是空的”这个假设不成立
- 如果当前线程刚从 userspace 进内核，`kernel_fpu_begin()` 很可能真的要先把用户态 FP/xstate 存掉

## 4.3 能否跨多个 SIMD 操作摊销 FPU section？

**能，但只能按整次 BPF 程序调用摊销，不能按单条 kinsn 摊销。**

### 每条 kinsn 各自 begin/end

这是最差方案：

- 每个 16B op 都要一次 `kernel_fpu_begin/end`
- 固定成本远大于 16B op 自身的任何收益
- 还会把程序类型上下文约束散落到每个站点

对本题，**可直接判死刑**。

### 整个 BPF 程序 invocation 只 begin/end 一次

这是唯一可能成立的 SIMD 方案：

- JIT prologue：若程序包含 SIMD kinsn，则 enter FPU section
- JIT epilogue：统一 leave
- 中间多个 bulk-memory SIMD op 共摊一次固定成本

但这已经超出了当前 module `emit_x86()` 的能力边界：

- 现有 x86 kinsn emitter 只发本地短序列，不负责 JIT prologue/epilogue
- 要做到程序级摊销，需要 **JIT 级别** 新增“本程序使用 SIMD”标记和包裹逻辑

因此：

- **pair load/store**：不值得为它做这套基础设施
- **bulk memory SIMD**：future phase 2 可以考虑，但前提是大量连续 copy/zero 能摊销

## 4.4 `irq_fpu_usable()` 对 BPF 执行上下文的影响

`irq_fpu_usable()` 直接带来一个非常关键的工程事实：

- tracing / perf / kprobe 这类程序可能跑在 NMI / hardirq / 杂上下文
- XDP / TC 通常更接近 softirq / process context

因此任何 x86 SIMD kinsn 若存在，都不应该像当前通用 x86 kinsn 那样默认 `BPF_PROG_TYPE_UNSPEC` 全开。

更合理的 gate 是：

- **只给 XDP / SCHED_CLS / 可能再加少数明确上下文稳定的类型**
- tracing / perf_event / 可能触发 NMI 的类型默认禁用

而这件事 **verifier 证明不了**；它属于注册策略/JIT 选路策略。

## 4.5 微架构视角下的成本

### 指令本体并不是主要矛盾

本地 `llvm-mca` 显示：

- 两条普通 `mov` 的 pair load 吞吐在 Skylake / Zen4 / Arrow Lake 上都优于 SSE2/AVX pack/unpack 方案
- 16B `memcpy128` 场景下，vector copy 才开始有明确优势

所以微架构差异不会改变 pair 结论。

### 真正主导的是 xstate 保存成本

`kernel_fpu_begin()` 慢不慢，主要不取决于 `movdqu`，而取决于：

1. 当前线程是否需要 `save_fpregs_to_fpstate()`
2. 当前 CPU 打开的 xstate footprint 有多大
   - SSE-only 比较小
   - AVX / AVX-512 打开后更大
3. 当前是否处于用户线程、softirq、kthread 等不同上下文

可操作的工程成本分层可以写成：

| 路径 | 组成 | 工程估计 |
| --- | --- | --- |
| 快路径 | `fpregs_lock` + `kernel_fpu_allowed` 切换 + `__cpu_invalidate_fpregs_state` + `ldmxcsr` + `kernel_fpu_end` | 约几十 cycles，本文后续用 `20~40 cycles` 做 break-even 估算 |
| 慢路径 | 快路径 + `save_fpregs_to_fpstate()` 保存当前用户态 FP/xstate | 约百级到数百 cycles，本文后续用 `100~250+ cycles` 做 break-even 估算 |

这里故意给的是 **design-level 区间**，不是硅上实测值。  
对本题已经足够，因为 pair load/store 连“零 FPU 成本”都赢不了；真正需要这些数字的是 future bulk-SIMD gate。

可用的工程判断：

- **Skylake**：pair SIMD 指令本体已经不如 two-mov；没有充分理由为它付出 FPU section
- **Zen4**：标量 load 端口非常强，pair SIMD 更不占优；若平台启用了更大的 xstate，save 成本可能更糟
- **Arrow Lake**：标量小块 copy 已经很强；vector `memcpy128` 仍优于 4-mov copy，但 pair SIMD 仍输；对这一代更有意义的是 FSRM/FSRS 类 short-string path，而不是 16B pair SIMD

### 一个重要的“已保存”特例

如果当前线程已经有 `TIF_NEED_FPU_LOAD`，`kernel_fpu_begin()` 会跳过 `save_fpregs_to_fpstate()`。

这出现在：

- 任务刚被调度切入，旧 CPU state 已经在 switch-out 时保存
- 前面已经有别的 kernel FPU 路径把状态内存化了

这会把成本从“慢路径”降到“快路径”，但即便如此：

- 对 pair load/store 仍然不够
- 只对大块 bulk memory SIMD 才有讨论价值

---

## 5. Break-even 分析

## 5.1 对 `bpf_wide_load128()/bpf_wide_store128()`：不存在 break-even

这是本文最关键的定量结论。

### Pair load

`llvm-mca`：

| 方案 | Skylake | Zen4 | Arrow Lake |
| --- | ---: | ---: | ---: |
| two `mov` | **1.0** | **0.7** | **0.7** |
| SSE2 pair load | 2.0 | 2.5 | 2.0 |
| AVX pair load | 2.0 | 2.5 | 2.0 |

SSE2/AVX 在**不计 FPU**时就已经更慢。

### Pair store

| 方案 | Skylake | Zen4 | Arrow Lake |
| --- | ---: | ---: | ---: |
| two `mov` | **2.0** | **2.0** | **1.0** |
| SSE2 pair store | 3.0 | 2.5 | 2.0 |
| AVX pair store | 3.0 | 2.5 | 2.0 |

SSE2/AVX 仍然更慢。

因此：

- 对 `memory <-> two GPR`
- 即使 `kernel_fpu_begin/end()` 免费
- SSE2/AVX 也 **没有** break-even

结论：**x86 pair load/store 的 SIMD 方案从根上就不成立。**

## 5.2 对 `bpf_memcpy128()`：只有 bulk 语义才有 break-even

这里比较的是：

- baseline：4 条 `mov` 完成 16B copy
- SIMD：2 条 `movdqu/vmovdqu`

`llvm-mca`：

| 方案 | Skylake | Zen4 | Arrow Lake |
| --- | ---: | ---: | ---: |
| 4 x `mov` copy16 | 2.0 | 2.0 | 1.0 |
| 2 x vector move copy16 | **1.0** | **1.0** | **0.5** |

粗略理解：

- **每 16B chunk 省约 1 个 cycle**

于是 break-even 大致变成：

```text
所需字节数 ≈ 16B * FPU固定成本(cycles) / 每16B节省(cycles)
          ≈ 16B * C_fpu / 1
```

### 若按“每个 BPF 程序调用只包一次 FPU section”

| 假设的 `C_fpu` | 估计 break-even |
| --- | ---: |
| 20 cycles（极乐观，已保存快路径） | ~320B |
| 40 cycles（更现实的快路径） | ~640B |
| 100 cycles（有实际 save） | ~1600B |
| 250 cycles（慢路径 / 大 xstate） | ~4000B |

这和已有 bulk-memory 设计里“x86 SIMD gate >= 512B”是一致的：

- 512B 只是一个**乐观但不离谱**的 future threshold
- 对 16B/32B/64B 小块，根本不该进 FPU

### 若按“每条 kinsn 各自包一次 FPU section”

那每个 16B chunk 只能省约 1 cycle，却要支付几十到上百 cycles 的固定成本。

**永远不 break even。**

## 5.3 与 `REP MOVSB` 的比较

这里必须谨慎，因为 `rep movsb` 不适合用 `llvm-mca` 估真实吞吐。

可用的工程信号来自仓库内 Linux x86 string routines：

- `arch/x86/lib/memcpy_64.S` 在 FSRM 情况下直接用 `rep movsb`
- `arch/x86/lib/memset_64.S` 在 FSRS 情况下直接用 `rep stosb`

这说明上游内核自己的判断是：

- 在合适 CPU feature 上，short/medium copy 的默认答案已经是 `rep`
- 它的最大优点不是某一代上“绝对最快”，而是 **不需要 FPU section**

因此：

1. **对 pair load/store**：`rep movsb` 语义不匹配，不能比
2. **对 bulk copy**：
   - 在 FSRM/ERMS 机器上，phase 1 应优先选 `rep movsb`
   - SIMD 至少要在“`rep` 已经不够好，而且能按程序调用摊销 FPU”时才值得考虑

### 已保存 FP state 的特例

若 `TIF_NEED_FPU_LOAD` 已经置位，SIMD 的 break-even 会下降到 320B~640B 这个量级。

但注意：

- 这依然远大于 16B pair op
- 也依然没有击败 `rep movsb` 的普适性和无上下文门槛

---

## 6. kinsn API 设计

## 6.1 若坚持做 pair API：建议保留跨架构语义，但 x86 不做 SIMD native

建议的跨架构语义仍然可以是：

```c
bpf_wide_load128(dst_lo, dst_hi, src_base, offset)
bpf_wide_store128(src_lo, src_hi, dst_base, offset)
```

其含义必须明确为：

- 两个相邻的 64-bit access
- **不是 128-bit atomic access**
- **不是强制单条 native 指令**
- verifier canonical 语义就是两条 `LDXDW` / `STXDW`

推荐的 payload（52-bit sidecar 预算内足够）：

### `bpf_wide_load128`

| bits | 含义 |
| --- | --- |
| `[3:0]` | `dst_lo` |
| `[7:4]` | `dst_hi` |
| `[11:8]` | `base_reg` |
| `[27:12]` | `offset_s16` |
| `[29:28]` | `align_class`：0=unknown, 1=8B, 2=16B |
| `[31:30]` | flags 保留 |

`instantiate_insn()`：

```c
ldxdw dst_lo, [base + off]
ldxdw dst_hi, [base + off + 8]
```

### `bpf_wide_store128`

| bits | 含义 |
| --- | --- |
| `[3:0]` | `src_lo` |
| `[7:4]` | `src_hi` |
| `[11:8]` | `base_reg` |
| `[27:12]` | `offset_s16` |
| `[29:28]` | `align_class` |
| `[31:30]` | flags 保留 |

`instantiate_insn()`：

```c
stxdw [base + off], src_lo
stxdw [base + off + 8], src_hi
```

### x86 native emit 建议

- **首选**：两条普通 `mov`
- **可选**：如果论文需要“同名 kinsn 双架构统一”，x86 也可以干脆不提供 native emit，只用 proof sequence
- **不建议**：SSE2/AVX pair native emit

## 6.2 若 x86 真要抓 16B 宽机会：API 应转向 `memcpy128` / bulk-memory，而不是 pair

若 x86 这边想抓 16B 宽度本身，而不是 pair 语义，API 更合理的是：

```c
bpf_memcpy128(dst_base, dst_off, src_base, src_off)
```

payload 可编码为：

| bits | 含义 |
| --- | --- |
| `[3:0]` | `dst_base` |
| `[7:4]` | `src_base` |
| `[23:8]` | `dst_off_s16` |
| `[39:24]` | `src_off_s16` |
| `[41:40]` | `align_class` |
| `[42]` | `non_overlap = 1` |
| `[43]` | `allow_rep = 1` |

但这里有一个更强结论：

- 仓库已经有更一般的 **Bulk memory kinsn** 设计
- `memcpy128` 只是它的一个定长子例

因此 x86 最合理的路线不是再定义一个新的“16B 专用 SIMD kinsn”，而是：

- **直接把这类机会并入 Bulk memory pass / kinsn**
- x86 phase 1 用 `rep movsb`
- x86 phase 2 再讨论 AVX/SSE

## 6.3 “是否直接用 `REP MOVSB`，跳过 SIMD？”

对 x86，答案是：

- **对 pair load/store：不能，因为语义不匹配**
- **对 bulk memory：应该，至少在 phase 1**

所以真正的选择不是：

- “SIMD 还是 `rep`”

而是：

- **pair API 用 two-mov**
- **bulk API 用 `rep`**

---

## 7. Verifier 建模

## 7.1 128-bit 操作的 verifier 语义应继续建模为两个 64-bit access

对 `bpf_wide_load128/store128`，推荐 verifier 语义就是：

- 两条普通 `BPF_DW` 访存
- 顺序固定
- 不承诺 atomicity
- 不引入新的 128-bit reg state

这与 `docs/kinsn-design.md` 的 proof-lowering 路线完全兼容。

## 7.2 XMM/YMM clobber 对 verifier 应透明

即便 future x86 native emit 内部使用 XMM/YMM：

- 它们也不是 BPF architectural registers
- verifier 不应为它们建模

但“对 verifier 透明”不等于“工程上没成本”：

- native emit 必须保证 XMM live range 不跨 helper/subprog 边界
- 若采用程序级 FPU section，helper 前后不能把 XMM 当成 BPF 可见状态保存点

换句话说：

- **verifier 不需要看见 XMM**
- **JIT / emitter 仍然要自己守 discipline**

## 7.3 `kernel_fpu_begin/end()` 与 BPF 执行模型

它不该出现在 proof sequence 里，因为它不是 BPF 语义的一部分。

但它引出一个 verifier 之外的关键约束：

- verifier 无法证明“这个程序永远不在 NMI/hardirq 里跑”
- 因而是否允许某个 kinsn 使用 SIMD，不能交给 proof sequence 决定

必须由：

1. kfunc/kinsn 注册 gate
2. JIT emit 时基于 `prog->type` 的策略
3. 必要时 runtime guard + scalar fallback

来保证

---

## 8. Daemon pass 设计

## 8.1 Pattern matcher

对 pair load/store，可沿用已有 research 的定义：

- 相邻两条 `LDX_MEM(BPF_DW)` / `STX_MEM(BPF_DW)`
- 同 base reg
- `abs(off2 - off1) == 8`
- load/store 各自独立匹配

但 daemon 在 x86 上不应把它直接理解成“SIMD 机会”。

应该分流成两类：

1. **isolated pair GPR access**
   - 例如两个 qword load 进入两个不同寄存器
   - x86：保留 scalar
   - ARM64：可以变成 `LDP/STP`
2. **copy-like block**
   - 例如先连续 load，再连续 store，同源同目的形成 copy run
   - x86：送去 Bulk memory pass

## 8.2 与 Bulk memory pass 的关系

推荐：

- **ARM64 pair load/store pass**：独立存在
- **x86 bulk-memory pass**：与现有 BlockMem/Bulk memory 方向合并
- **x86 pair pass**：如果保留，只用于 cross-arch semantic abstraction，不用于 SIMD 选路

原因：

- ARM64 的 ISA 有 pair GPR primitive
- x86 的“宽机会”主要体现在 string/bulk primitive，而不是 pair GPR primitive

## 8.3 x86 选路策略

建议优先级：

### 1. 若语义是 `memory <-> two GPR`

- 选 **Option D：two `mov`**
- 若为了统一 IR 引入 `bpf_wide_load128/store128`，x86 native emit 也仍然发两条 `mov`

### 2. 若语义是 `memory -> memory` 的定长或短 run copy

- 优先尝试 **Bulk memory kinsn**
- x86 phase 1：`rep movsb`
- 要求：
  - CPU 对 short/medium `rep` 友好
  - site 能 canonicalize 到 `rdi/rsi/rcx`，或者长度可在 emitter 内稳定 materialize

### 3. 只有在 future phase 2 才考虑 SIMD

必须同时满足：

- `prog->type` 限于 XDP / SCHED_CLS 一类可控上下文
- 能按**整次程序调用**摊销一次 FPU section
- 程序中 bulk bytes 足够大，建议门槛 **>= 512B**
- 不是 isolated 16B/32B site，而是长 run

---

## 9. 最终推荐

## 9.1 对四个选项分别给出 YES / NO / CONDITIONAL

### Option A：SSE2 `MOVDQU/MOVDQA`

- **对 x86 pair load/store：NO**
- **对 x86 bulk memory：CONDITIONAL**

理由：

- pair 语义下指令级就不占优
- `MOVDQA` 的 16B 对齐要求不值得
- 只有在 bulk copy 且能程序级摊销 FPU 时才值得讨论

### Option B：AVX `VMOVDQU`

- **对 x86 pair load/store：NO**
- **对 x86 bulk memory：CONDITIONAL，且优于 SSE2 作为 phase 2 路线**

理由：

- 对 pair 仍然没有减少 pack/unpack
- 对 bulk memory，AVX 的价值主要在：
  - future 256-bit 扩展
  - 避免 VEX/legacy transition 问题
- 但仍然受 FPU section 和程序类型门槛支配

### Option C：`REP MOVSB`

- **对 x86 pair load/store：NO**
- **对 x86 bulk memory：YES**

理由：

- 完全不需要 FPU
- 与内核现有 string routines 方向一致
- 这是 x86 “16B 宽机会”的正确第一阶段答案

### Option D：两条普通 `mov`

- **对 x86 pair load/store：YES**
- **对 x86 bulk memory：YES，作为小块 fallback**

理由：

- 语义最匹配
- 指令级上已经最佳
- 无 FPU / 无上下文门槛 / 无 verifier 新复杂度

## 9.2 对论文 story 的建议

最好的 OSDI story 不是“我们也给 x86 造了一个 128-bit SIMD pair op”，而是：

1. **同一套 kinsn 机制可以承载架构不对称的优化机会**
2. **ARM64**：有天然 pair GPR primitive，`LDP/STP` 是 free lunch
3. **x86**：没有对应 pair GPR primitive，pair 语义不值得 SIMD 化；真正的宽机会转向 bulk memory/string instruction

这比硬说“双架构都做 128-bit kinsn”更强，因为它展示的是：

- kinsn 机制的抽象能力
- 不同 ISA 上“同一语义为何有不同 native answer”

## 9.3 最终落地建议

**推荐的实际设计：**

1. 若要定义跨架构 pair kinsn：
   - 定义 `bpf_wide_load128/bpf_wide_store128`
   - verifier 一律展开成两条 `LDXDW/STXDW`
   - ARM64 native emit -> `LDP/STP`
   - x86 native emit -> 两条普通 `mov`，或干脆 instantiate-only
2. x86 的真正优化机会并入 Bulk memory：
   - phase 1：`rep movsb/stosb`
   - phase 2：AVX/SSE，仅在 `>= 512B` 且程序级 FPU 摊销成立时考虑
3. **不要**为 x86 专门做 SSE2/AVX 的 pair load/store kinsn

一句话结论：

> **x86 没有 ARM64 那种“免费”的 128-bit pair load/store。对 x86，`wide_load128/store128` 的正确答案是 scalar two-mov；真正值得做宽化的是 Bulk memory，而不是 pair GPR access。**
