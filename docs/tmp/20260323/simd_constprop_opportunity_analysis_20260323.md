# SIMD kinsn 与 Verifier-Assisted Constant Propagation 优化机会调研

日期: 2026-03-23

## 结论摘要

结论先行:

- `SIMD kinsn` 在真实 BPF workload 中**有机会，但主要集中在 XDP/TC 这类 packet fast path**，不是 tracing/kprobe。
- 真实程序里**显式 `memcpy/memset` 并不多**: 在 `429` 个成功构建的 BPF 源文件中，只发现 `23` 个显式 builtin 调用点: `13` 个 `__builtin_memcpy`、`9` 个 `__builtin_memset`、`1` 个 `__builtin_memmove`。但这**不代表内存操作少**，因为大量 copy/zero-init 已经被 LLVM 展开成标量 load/store。
- 当前 x86 BPF JIT **没有通用 `memcpy/memset` lowering**，也**没有 `rep movsb` / SSE / AVX 专门路径**；现状是按 BPF 指令逐条发射标量 load/store 或 helper call。
- 内核中直接用 SIMD 受 `kernel_fpu_begin/end()`、`may_use_simd()`、IRQ/NMI 上下文限制，**做“每次小 copy 都开一次 FPU section”基本不划算**。如果要做，必须是**XDP/TC 热路径上的粗粒度、可摊销、短临界区**。
- `verifier-assisted constant propagation` 的机会比 SIMD 更“稳”: 从归档 verifier log 的保守下界看，**约 23% 的已记录 state line 含有精确常量寄存器信息**；而在整个 `.bpf.o` corpus 中，`62.5%` 的条件分支都在和立即数比较，`8.05%` 的全部指令是 ALU-immediate，说明**dead branch / DCE / strength reduction** 的后续收益面很大。
- 从落地优先级看，建议是:
  1. 先做 verifier-assisted const prop，用于 branch folding / DCE / strength reduction / helper-size specialization。
  2. 再做面向 XDP/TC 的小规模 SIMD kinsn，优先固定长度 header copy/compare/hash/checksum。
  3. tracing/kprobe 更适合做 const prop，不适合把 SIMD 作为第一优先级。

## 调研方法与口径

本报告混合了三类证据:

1. `corpus/build/**/*.bpf.o` 的对象级统计与反汇编。
2. `corpus/results/*` 中已有 verifier log 归档的保守下界统计。
3. 论文与内核源码/文档。

需要特别说明的口径:

- `memcpy/memset helper` 这个说法在 eBPF ABI 里并不准确。`vendor/linux-framework/include/uapi/linux/bpf.h` 的 helper 枚举里**没有通用 `bpf_memcpy/bpf_memset` helper**。真实对象里出现的是两类东西:
  - 源码级 `__builtin_memcpy/__builtin_memset`，通常被 LLVM 直接展开；
  - copy-like helper，例如 `bpf_probe_read_kernel`、`bpf_skb_load_bytes`、`bpf_xdp_load_bytes`。
- verifier 统计方面，仓库里**缺少全量成功加载程序的 `log_level=2` 日志**。因此下面关于常量信息的数字是**归档 failure log 的保守下界**，不是无偏 corpus-wide 平均值。
- 本仓库的 `docs/reference/papers/08-merlin.pdf` 与 `09-epso.pdf` 是错配镜像；对 Merlin/EPSO 我使用了作者页面 / arXiv / ACM 元数据，而不是本地错配 PDF。

## 1. SIMD kinsn 机会

### 1.1 真实 workload 的类型分布

对 `corpus/build/` 下 `565` 个 `.bpf.o` 进行枚举后，成功识别出 `468` 个对象中的 `2017` 个 BPF program。按 program type 看，数量最多的是:

- `kprobe`: `549`
- `tracing`: `452`
- `sched_cls`: `186`
- `tracepoint`: `166`
- `raw_tracepoint`: `118`
- `xdp`: `92`
- `lsm`: `83`

这说明 corpus 的“真实 workload”主要分两大类:

- 数量上以 tracing/kprobe 为主；
- 但真正和 SIMD 强相关的热点，是 `xdp` 与 `sched_cls/tc` 这类 packet path。

### 1.2 哪些操作可以用 SIMD 加速

从真实对象反汇编看，适合 SIMD 的操作主要不是“大块通用 memcpy”，而是**固定长度、已知偏移、重复频繁的 header/tuple 操作**:

1. 固定长度 copy / move
   - MAC 地址 `6B`
   - IPv6 地址 `16B`
   - TCP/IP header 片段 `20B/40B`
   - flow tuple / key struct 的 `12B/16B/32B/40B`
2. 固定长度 compare
   - MAC / IPv4 / IPv6 地址比较
   - TCP option / SYN cookie 相关 header 比较
3. checksum / hash
   - L3/L4 checksum 累加
   - flow hash / tuple hash
4. packet parsing 中的批量字段抽取
   - 一次读入 16B/32B header，再 mask/shuffle/byteswap
5. 栈上 zero-init
   - struct 临时对象清零，当前常被 LLVM 展开为连续 `st/stx`

对象级例子:

- `corpus/build/xdp-tools/xdp_flowtable.bpf.o` 的 `xdp_fwd_flow_full` 开头就是一串连续的 `*(u64 *)(r10 - off) = 0`，典型的 `memset`-like stack zeroing。
- `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_synproxy_kern.bpf.o` 中有大量 IPv6 地址拷贝、tuple 拼装、TCP option parsing，这些都已经被标量 load/store 展开。

这意味着: **SIMD 的机会主要是把已经被 scalarized 的固定长度内存与 header 操作重新“收拢”为更宽的机器指令序列**。

### 1.3 显式 memcpy/memset 的使用频率与大小分布

在 `429` 个成功构建的 BPF 源文件中，显式 builtin 的频率并不高:

- `__builtin_memcpy`: `13`
- `__builtin_memset`: `9`
- `__builtin_memmove`: `1`
- 涉及文件数: `15`

这说明:

- **显式写出来的 `memcpy/memset` 很少**；
- 但 packet code 里并不缺 copy/zeroing，只是它们往往被编译器在 IR/ISel 阶段提前展开掉了。

常见 size expression 分布:

- `ETH_ALEN` 出现 `3` 次
- `sizeof(event.comm)` 出现 `2` 次
- `sizeof(tup.ipv6.saddr)` / `sizeof(tup.ipv6.daddr)` 各出现 `1` 次
- `sizeof(bpf_tuple.ipv4)`、`sizeof(*hdr->tcp)`、`TCP_CA_NAME_MAX`、`sizeof(info)`、`sizeof(data)` 等也出现

从这些 expression 可以看出，显式 builtin 的典型尺寸并不大，主要集中在:

- `6B`
- `8B/12B/16B`
- `20B/40B`
- 少量更大的 struct 清零

这和 SIMD 的适用区间是匹配的，但也意味着**不能靠“拦截大型 memcpy helper”来做**，而要靠**重新识别 scalarized fixed-size block**。

### 1.4 `.bpf.o` 里有没有 `memcpy/memset helper`

结论: **没有通用 `memcpy/memset` helper**。

证据:

- `vendor/linux-framework/include/uapi/linux/bpf.h` 的 helper 列表里没有 `FN(memcpy)` 或 `FN(memset)`。
- 当前真实对象中，显式内存操作要么已经变成标量指令，要么调用的是 copy-like helper。

对象级 copy-like helper 统计如下:

| helper | 调用次数 | 常量 size 比例 | 常见 size |
| --- | ---: | ---: | --- |
| `probe_read_kernel` | `25296` | `99.9%` | `8, 4, 16, 65, 104, 2, 256` |
| `probe_read_kernel_str` | `1728` | `36.7%` | `16, 4096, 64, 256` |
| `probe_read_user` | `126` | `98.4%` | `8, 16, 4, 144, 16384` |
| `probe_read_user_str` | `78` | `100%` | `128, 255, 4096, 8160` |
| `skb_load_bytes` | `590` | `29.5%` | `20, 8, 14, 4` |
| `skb_store_bytes` | `536` | `58.4%` | `4, 2, 16, 20` |
| `skb_load_bytes_relative` | `6` | `0%` | 动态 |
| `copy_from_user` | `23` | `95.7%` | `8, 4, 9, 64` |
| `xdp_load_bytes` | `7` | `100%` | `10, 14, 20, 40` |
| `copy_from_user_task` | `3` | `66.7%` | `4` |

合并看，copy-like helper 总数是 `28393`，其中在保守识别下 `93.77%` 的 size 是常量。

但这里有一个关键区分:

- `probe_read_kernel*` 在 tracing 程序里数量巨大，**不构成 SIMD kinsn 的主要收益点**，因为 JIT 无法把 helper 内部实现替换成向量化 fast path。
- 真正与 SIMD 更相关的是 `xdp_load_bytes` / `skb_load_bytes` / scalarized packet parsing/copy，它们虽然调用次数远少于 tracing helper，但更接近 hot packet path。

### 1.5 当前 BPF JIT 对 memcpy 的处理方式

从 `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c` 看，当前 x86 JIT 的处理是:

- `BPF_ST/BPF_STX` 直接发标量 store
- `BPF_LDX` 直接发标量 load
- `BPF_CALL` 直接发普通 helper/kfunc call，只有 kinsn 走 `emit_kinsn_call()`

对应代码位置:

- 标量 store: `arch/x86/net/bpf_jit_comp.c:2141-2177`
- 标量 load: `arch/x86/net/bpf_jit_comp.c:2258-2308`
- call/kinsn call: `arch/x86/net/bpf_jit_comp.c:2471-2497`

因此现状不是:

- 不是 `rep movsb`
- 不是 SSE/AVX
- 也不是一个通用的 `memcpy` lowering pass

而是:

- **LLVM 先把 BPF 级 copy/zero 展开成 load/store**
- **x86 BPF JIT 再一条条把这些 BPF load/store 映射成标量 x86 指令**

这意味着 SIMD 的切入点只能是:

1. 新增 kinsn / peephole，在 JIT 前或 JIT 中重新识别 fixed-size block；
2. 或者引入 `rep movsb/stosb` / 宽 GPR / SSE2/AVX2 的专门 lowering。

值得注意的是，`rep movsb`/`rep stosb` 不需要 XMM/YMM 状态，**它是一个比“直接上 SIMD”更保守的中间设计点**。

### 1.6 SIMD 的 context switch / FPU 开销是否可接受

现有证据支持的结论是:

- **对 tracing/kprobe 的小 copy，不可接受**
- **对 XDP/TC 的超短小 header copy，逐次进入 FPU section 也大概率不可接受**
- **只有在一个较粗粒度的 SIMD section 内能摊销多条 memory ops / checksum / hash 时，才有希望**

依据如下:

1. 内核文档明确说 kernel 默认禁止 FP/SIMD，因为否则要保存/恢复用户态 FP 状态。见 `Documentation/core-api/floating-point.rst:6-20`。
2. 文档要求 FP 代码放在独立 TU，并用 `kernel_fpu_begin/end()` 包住，critical section 要尽量小。见 `floating-point.rst:11-20, 66-78`。
3. x86 侧 `kernel_fpu_begin/end()` 会:
   - `fpregs_lock()`
   - 检查 `irq_fpu_usable()`
   - 切换 `kernel_fpu_allowed`
   - 可能把当前 task 的 FP regs 保存到 fpstate
   - 失效当前 fpregs 状态
   - 初始化 `MXCSR`
   见 `arch/x86/kernel/fpu/core.c:472-507`。
4. x86 头文件明确警告: `kernel_fpu_begin/end()` 会禁用 preemption 和 softirq processing，不适合长临界区。见 `arch/x86/include/asm/fpu/api.h:17-22`。
5. `may_use_simd()` 最终依赖 `irq_fpu_usable()`，而后者在 `NMI` 中直接 false，在 hardirq 中也受限制。见:
   - `arch/x86/include/asm/simd.h:9-16`
   - `arch/x86/kernel/fpu/core.c:74-111`
6. x86 FPU core 还专门跟踪 AVX512 使用，因为它会影响核心最高频率。见 `arch/x86/kernel/fpu/core.c:114-124`。

因此工程判断是:

- **AVX512 基本不适合作为内核 BPF JIT 的首选向量宽度**。
- 如果要做，优先级应是:
  1. `rep movsb/stosb` 或多 GPR 宽拷贝
  2. `SSE2`/`AVX2` 的短 section
  3. 最后才考虑更宽向量

### 1.7 kernel 对 “SIMD in BPF context” 的限制

严格说，内核并没有“专门允许 BPF 随意用 SIMD”的通道；它只有通用 kernel FPU/SIMD 规则。

在 BPF 语境下，这些限制意味着:

- tracing program 常在更复杂的内核上下文触发，安全 envelope 更差；
- XDP 多数运行在 NAPI/softirq 相关路径，理论上比 NMI/hardirq 宽松，但仍不适合每个 6B/16B copy 都包一层 `kernel_fpu_begin/end()`；
- 如果未来通过 kinsn 把若干相邻 fixed-size ops 合并到一个 native sequence，中间才可能有摊销空间。

### 1.8 有没有 paper 讨论 BPF + SIMD

结论分两层:

第一层，**在你列出的主流论文里，几乎没有“Linux 内核 BPF JIT 直接用 CPU SIMD 寄存器做通用优化”的工作**。

第二层，**有一些邻近工作在讨论更广义的并行/专用硬件方向**:

- `hXDP` 讨论的是 FPGA NIC 上的 eBPF/XDP 并行执行，不是 CPU SSE/AVX。
- `eBPFML`（SIGCOMM 2025 workshop abstract）提出给 eBPF ISA 增加矩阵乘 helper，并通过 JIT 利用 Intel AMX，属于“硬件加速指令扩展”，比 SIMD 更激进。
- `X2DP`（SIGCOMM 2025 poster/demo）标题本身就指向 XDP 并行化方向，但我没有找到足够细节证明它已经是成熟的“内核 CPU SIMD JIT”方案。

所以文献现状更像是:

- **BPF + parallelism / specialization / hardware offload**: 有
- **BPF JIT + 通用 CPU SIMD memcpy/hash/parse**: 几乎没有成熟公开方案

## 2. Verifier-assisted constant propagation

### 2.1 `log_level=2` 暴露了什么信息

结合归档 verifier log 和已有 parser 研究，`log_level=2` 暴露的不是只有“这个寄存器是不是常量”，而是一个相当丰富的抽象状态:

- 当前 `PC`
- 分支转移信息，如 `from <prev> to <pc>`
- 寄存器类型，如 `scalar()` / `ctx()` / `map_value` / `pkt(...)`
- 数值边界，如 `smin/smax/umin/umax`
- `var_off`
- 指针 `id`
- 栈/包偏移，如 `off=...`, `fp-...`

对 const-prop 来说，最可用的不是单一 bit，而是三类信息:

1. 精确常量
2. singleton range / 近似 singleton range
3. 已知 offset / pointer-kind / packet-bound 信息

### 2.2 归档 verifier log 中可利用常量信息的保守下界

在本次调研中，对仓库里约 `120` 个唯一归档 verifier log block 做 exact-constant token 提取后，可以得到一个保守下界:

- state line 总数: `552`
- 含精确常量寄存器信息的 state line: `127`
- 比例: 约 `23.01%`
- 精确常量寄存器出现次数: `127`

最常见的精确常量值是:

- `0`: `68`
- `3312`: `14`
- `1`: `11`
- `6`: `5`
- `16`: `5`

这组数字的意义:

- `0/1` 这类 flag、null、bool、loop bound、branch condition 非常多；
- `6/16` 这类小常量与 header size、地址宽度、helper size 很吻合；
- verifier log 里真正“值很大而且仍是常量”的情况也存在，但不是主流。

同时，这些归档 log 还暴露了大量非精确但很有用的状态信息:

- pointer-kind 信息行: `228`
- offset-bearing 行: `68`
- `id=` 行: `28`
- range-bearing 行: `26`

所以对 const-prop 来说，精确常量只是第一层。

### 2.3 verifier 在多少个 PC 点能确定寄存器是常量

这里必须实话实说:

- 如果只用仓库里现成的归档 log，**我能给出的可靠数字是“至少有 `127` 个已记录的 PC-state snapshot 暴露了精确常量寄存器”**。
- 但我**不能把它直接当作“真实 corpus 中 unique PC 的占比”**，因为:
  - 这些 log 主要是 failure trace；
  - 缺成功加载程序的全量 `log_level=2`；
  - 归档里同一小程序会重复出现。

因此更合理的表述是:

- **exact-constant 的可见度至少不低**；
- **真实可利用 PC 点数大概率远高于归档 failure log 的下界**；
- 如果要做严谨评估，必须补全成功 load 程序的 `log_level=2|BPF_LOG_STATS` 采样。

### 2.4 在我们 corpus 中，const prop 的“消费端”有多大

虽然成功 verifier log 缺失，但 `.bpf.o` 静态形态已经说明 const prop 后续优化的消费面很大:

- 指令总数: `1,443,686`
- 条件分支总数: `121,157`
- 其中与立即数比较的条件分支: `75,769`
- 占全部条件分支比例: `62.54%`
- ALU-immediate 指令: `116,245`
- 占全部指令比例: `8.05%`

这意味着:

1. **dead branch / DCE 空间很大**
   - 如果 verifier 在某路径上已知 `rX` 是常量，那么大量 `if rX <imm>` / `if rX == <imm>` 可以直接折叠。
2. **strength reduction / constant folding 空间很大**
   - 大量 shift/mask/add with immediate 会因为源值被 verifier 固定而继续塌缩。
3. **helper-size / offset specialization 很自然**
   - 当 verifier 已知 size、offset、header kind 时，copy/checksum/hash 的专门 lowering 可以更激进。

### 2.5 能触发多少后续优化

按真实 BPF workload 的优先级排序，我认为 const-prop 触发的收益大致是:

1. `Dead branch` / `DCE`
   - 这是最大的确定性收益项。
   - 原因: 真实程序里 branch-immediate 太多，而且 verifier 非常擅长证明 flag/offset/nullability。
2. `Strength reduction`
   - 尤其是 packet parsing 里的 mask/shift/endian/offset 计算链。
3. `Helper / memcpy-size specialization`
   - 已知固定 size 时，可以改走更紧凑的 kinsn/native path。
4. `Loop unrolling`
   - 有收益，但在 packet path 里**不是头号机会**。

原因是:

- 在可见源文件中，loop-heavy 的代码很多已经手工 `#pragma unroll` 或直接使用 `bpf_loop()`。
- `#pragma unroll` 在仓库 BPF 源里出现 `79` 次，明显集中在 `scx` 等基础设施代码与个别 tracing 例子；
- `bpf_loop()` 只出现 `4` 次，主要在 `xdp-examples/delay-kfunc` 和 `systemd` 的个别程序；
- 真正 XDP/TC fast path 更常见的是**分支折叠、固定 offset、header-copy specialization**，不是“把大循环再自动 unroll 一层”。

### 2.6 有没有 paper 讨论 BPF const propagation / partial evaluation

有，但形态不同:

- `Merlin` 明确把 `constant propagation (CP) + dead code elimination (DCE)` 作为优化策略之一。
- `K2` 没有做 verifier-assisted const prop，但它做了 `memory offset concretization`，本质上是利用 compile-time-known offset 做更强等价化简。
- `EPSO` 走的是 offline superoptimization + rule cache，更像 codelet specialization，而不是 verifier-state-driven const prop。
- `Jitk` / `Jitterbug` 的重点是可信实现与正确性，不是 const-prop 本身。

## 3. 现有 paper 的相关工作

### 3.1 K2 (SIGCOMM'21)

结论:

- **没有 SIMD**
- **有常量/偏移具体化相关思想**
- 但不是 verifier log 驱动的 const prop

K2 的关键点是 superoptimization + safety analysis。它明确讨论了:

- `memory type concretization`
- `map type concretization`
- `memory offset concretization`

K2 论文中写得很直接: packet-processing programs 往往在 compile time 就能确定 packet header offset；如果能把 pointer offset 具体化，等式约束可以从 `rY_i == rY_l` 进一步简化成 `constant == rY_l`，甚至 `constant1 == constant2`，从而触发 cascading simplification。

所以 K2 和 const-prop 的关系是:

- **它利用常量 offset / typed memory 让等价检查更强**
- 但**不是把 verifier 的运行时抽象状态导出给后续 pass**

### 3.2 Merlin (ASPLOS'24)

结论:

- **没有 SIMD**
- **明确包含 const prop**

Merlin 的作者页 PDF 明确写到:

- 它采用两类主优化策略: `instruction merging` 与 `strength reduction`
- 同时专门有 `Optimization 1: Constant propagation (CP) and dead code elimination (DCE)`
- 优化在 verifier 之前进行

这篇论文对你的问题最直接的启发是:

- const-prop 在 eBPF 上不是“未来可能”，而是**已经被论文明确当作有效优化项**；
- 但 Merlin 主要走 LLVM IR pass + bytecode refinement，不依赖 verifier 输出；
- 也没有引入 SIMD。

### 3.3 EPSO (ASE'25)

结论:

- **没有 SIMD 证据**
- **更像 offline specialization / rule caching，而不是 verifier-assisted const prop**

从 arXiv 摘要看，EPSO 的核心是:

- offline superoptimization 发现 rewrite rules
- runtime 复用 cache 里的规则
- 在 Linux kernel 与多个 eBPF 项目 benchmark 上平均减少 `24.37%` 程序大小，平均 runtime 改善 `6.60%`

对 specialization 的判断:

- 如果宽泛地说，EPSO 的“离线发现 + 在线复用 rule”确实是一种 code-fragment specialization；
- 但**没有证据表明它在利用 verifier 常量状态做路径特化**。

### 3.4 Jitk (OSDI'14)

结论:

- **与 SIMD/const-prop 关系都很弱**
- 主要相关性在于“可信 in-kernel 执行基础设施”

Jitk 的主题是 trustworthy in-kernel interpreter infrastructure，不是 eBPF JIT 优化器。它对本问题的价值更多在:

- 如何把内核内执行基础设施做成可证明/可信
- 而不是讨论 SIMD 或 const-prop 机会

### 3.5 Jitterbug (OSDI'20)

结论:

- **没有 SIMD**
- **不是 const-prop 论文**
- 但和“JIT correctness 下能不能安全加优化”高度相关

Jitterbug 的重点是 BPF JIT correctness specification 和 verified JIT。它确实开发并验证了 `12` 个优化 patch，其中包括:

- RISC-V compressed instructions
- 若干 ALU/JIT codegen 改进

它对本题的启发是:

- 如果未来要把 SIMD kinsn 或 verifier-assisted const-prop 放到 JIT 路径里，**正确性与可验证性是实打实的工程约束**；
- 但论文本身不提供 SIMD 或 const-prop 机会评估。

### 3.6 hXDP (OSDI'20)

结论:

- **最接近“BPF + 数据级并行”**
- 但它做的是 **FPGA parallel lanes / VLIW pipeline**，不是 CPU SIMD

hXDP 的核心是:

- eBPF/XDP offload 到 FPGA NIC
- 静态分析 instruction-level parallelism
- 4 条并行执行 lanes
- helper 调用不能并行化

这篇论文说明:

- packet-processing BPF 确实存在大量可挖的并行性；
- 但公开论文里，成熟方案首先落在 FPGA/offload，而不是 kernel CPU SSE/AVX。

### 3.7 bpftime

结论:

- **没有找到显式 SIMD lowering 的证据**
- **有 LLVM/JIT/inlining，因此天然更容易吃到传统 const-prop / DCE**

`bpftime` OSDI'25 论文与 GitHub 描述强调的是:

- userspace eBPF runtime
- optimized compiler like LLVM
- extension compiler 可以 inline calls

这意味着:

- 在 userspace 场景，SIMD 的上下文约束比内核弱很多；
- 但我没有找到 bpftime 明确宣称“对 BPF bytecode 做了 SSE/AVX memcpy/hash lowering”的证据；
- 它更像是“把 LLVM 的常规优化能力带到用户态 eBPF”。

### 3.8 补充: 请求列表外但值得关注的工作

- `eBPFML`（SIGCOMM 2025 workshop abstract）明确提出给 eBPF 加 matrix-multiply helper，并让 JIT 利用 Intel AMX。这说明**把 eBPF ISA 扩到更强硬件 primitive**已经开始进入研究视野。
- `X2DP`（SIGCOMM 2025 poster/demo）至少从标题上说明，社区开始把 XDP 并行化本身当作独立方向。

## 4. 我们 corpus 中的机会评估

### 4.1 memcpy/memset helper 调用次数和参数大小

如果严格按“通用 `memcpy/memset` helper”来统计:

- **次数为 0**

因为 ABI 里就没有这个 helper。

如果按 copy-like helper 统计，则可见:

- tracing/kprobe 数量上占绝对多数，主要是 `probe_read_kernel`
- packet path 真正相关的是:
  - `skb_load_bytes`: `590`
  - `skb_store_bytes`: `536`
  - `xdp_load_bytes`: `7`

这些 packet helper 的常见 size 基本都很小:

- `4B`
- `8B`
- `14B`
- `16B`
- `20B`
- `40B`

这进一步支持了一个重要判断:

- **BPF workload 中潜在 SIMD 收益最大的不是“大块 memcpy”**
- **而是 packet header / tuple 的固定长度小块操作**

### 4.2 可被 const prop 优化的指令比例

我给出两个层面的数字:

1. verifier 可见下界
   - 归档 log 中约 `23%` 的 state line 含精确常量寄存器信息。
2. 静态消费者上界
   - `62.54%` 的条件分支在和立即数比较；
   - `8.05%` 的全部指令是 ALU-immediate。

因此比较保守但可信的判断是:

- **const-prop 后能够继续触发优化的“消费者位点”非常多**
- 但**需要补成功程序的 `log_level=2` 采样，才能把“消费面”转成更精确的“可命中率”**

### 4.3 SIMD 收益最大的程序类型

按我对真实对象、helper 分布和程序类型的综合判断，排序如下:

#### 第一梯队: `xdp` 与 `sched_cls/tc`

原因:

- 在最热的 packet path 上
- 数据是连续 packet buffer
- 常见操作正好是 `6/14/16/20/40B` 固定长度 header/tuple 访问
- checksum/hash/byteswap/parse 也集中在这里
- 反汇编中已经能看到大量 scalarized copy/zeroing

这是 **SIMD kinsn 最值得优先切入** 的程序类型。

#### 第二梯队: `sock_ops` / `sk_skb` / `cgroup_sock*` / `netfilter`

原因:

- 也有 tuple/address copy 与固定字段操作
- 但数据路径没有 XDP/TC 那么“纯 packet-fast-path”
- 规模与密度都较小

#### 第三梯队: `kprobe` / `tracepoint` / `tracing` / `raw_tracepoint`

原因:

- 这里 copy-like helper 极多，但绝大多数是 `probe_read_*`
- 程序的瓶颈往往是 helper、内核对象访问、map、ringbuf/perf 输出
- 即使 size 是常量，也**更适合 const-prop 和 helper specialization，不适合 SIMD**

换句话说:

- **tracing 是 const-prop 的大户**
- **XDP/TC 是 SIMD 的大户**

### 4.4 对我们自己的优化设计意味着什么

如果目标是做有现实收益的优化，我的建议是:

1. `Verifier-assisted const prop` 应该先做
   - 它覆盖所有 program type
   - 对 dead branch / DCE / strength reduction 的收益更确定
   - 对后续 SIMD/kinsn 选择还能提供 size/offset/path 条件
2. `SIMD kinsn` 应该从最窄的目标集合起步
   - 先只做 `xdp`/`tc`
   - 先只做固定长度 `16/32/40/64B` copy/compare/zero/hash/checksum
   - 优先考虑 `rep movsb/stosb` 或宽 GPR 方案，再考虑 XMM/YMM
3. 不要把 tracing 的 `probe_read_*` 当作 SIMD 主战场
   - 那里更适合 helper-size specialization、branch folding、DCE
4. 如果后续要把 verifier 信息真正喂给 optimizer，最有价值的字段是:
   - exact constant
   - singleton range
   - known offset
   - pointer kind / packet region

## 最终判断

### SIMD kinsn

- **有价值，但要窄做**
- 最值得做的是 XDP/TC 中的固定长度 header/tuple copy/compare/hash/checksum
- 最不值得做的是 tracing/kprobe 中的 helper-heavy 路径
- 如果实现依赖 `kernel_fpu_begin/end()`，必须严格控制使用上下文与摊销粒度

### verifier-assisted const propagation

- **价值更高，也更普适**
- 真实程序里 verifier 暴露出的常量、范围、offset 信息已经足够驱动一轮有效优化
- 最可能带来收益的是 dead branch / DCE / strength reduction，而不是大规模自动 loop unrolling

### 研发优先级建议

建议优先级:

1. `verifier-assisted const prop`
2. `const-prop` 驱动的 size/offset specialization
3. 面向 `xdp/tc` 的 fixed-size memcpy/hash/checksum kinsn
4. 只有在确认 FPU/context 约束可控后，再扩大到更宽的 SIMD lowering

## 参考资料

### 内核源码与文档

- Linux kernel floating-point API 文档: <https://www.kernel.org/doc/html/next/core-api/floating-point.html>
- 本地内核文档: `vendor/linux-framework/Documentation/core-api/floating-point.rst`
- x86 FPU API: `vendor/linux-framework/arch/x86/include/asm/fpu/api.h`
- x86 SIMD gate: `vendor/linux-framework/arch/x86/include/asm/simd.h`
- x86 FPU core: `vendor/linux-framework/arch/x86/kernel/fpu/core.c`
- x86 BPF JIT: `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`

### 论文与项目

- K2 PDF: <https://conferences.sigcomm.org/sigcomm/2021/files/papers/3452296.3472929.pdf>
- Merlin PDF: <https://people.cs.umass.edu/~juanzhai/papers/asplos24.pdf>
- EPSO arXiv abstract: <https://arxiv.org/abs/2511.15589>
- Jitk dblp entry: <https://dblp.org/rec/conf/osdi/ChenLWCT14>
- Jitterbug PDF: <https://www.usenix.org/system/files/osdi20-nelson.pdf>
- hXDP PDF: <https://www.usenix.org/system/files/osdi20-brunella.pdf>
- bpftime OSDI page: <https://www.usenix.org/conference/osdi25/technical-sessions>
- bpftime GitHub: <https://github.com/eunomia-bpf/bpftime>
- SIGCOMM 2025 workshop/proceedings 页面（含 `eBPFML` 摘要）: <https://conferences.sigcomm.org/sigcomm/2025/workshop/papers-workshop-info/>
- SIGCOMM 2025 accepted posters/demos 页面（含 `X2DP`）: <https://conferences.sigcomm.org/sigcomm/2025/accepted-posters-demos/>
