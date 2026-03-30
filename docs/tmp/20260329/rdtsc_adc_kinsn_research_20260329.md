# RDTSC + ADC/SBB 在 BPF 程序中的优化价值调研

日期：2026-03-29  
范围：只做历史会话回读与仓库静态分析；不改代码，不跑 VM。

## 一句话结论

- `RDTSC`：真实 workload 压力很大，但不适合做“透明、语义等价”的 BPF REJIT 优化。若做，应作为显式 opt-in 的 x86 时间戳 primitive，而不是把 `bpf_ktime_get_ns()` 偷偷改写成 `RDTSC`。
- `ADC/SBB`：语义上是合格的 x86 kinsn 候选，但当前 corpus 几乎没有需求信号。短期不值得进入默认 pipeline；更适合作为 future work 或专项 microbenchmark。

更短地说：`RDTSC` 是“需求强但抽象不对”，`ADC/SBB` 是“抽象对但需求太弱”。

## 调研输入

1. 回读两段被中断的历史会话：
   - `~/.codex/sessions/2026/03/29/rollout-2026-03-29T18-33-18-019d3c5f-b6e1-75b3-8fd7-4bfb13eb9d9d.jsonl`
   - `~/.codex/sessions/2026/03/29/rollout-2026-03-29T18-52-27-019d3c71-3bb0-76a2-a088-412d3b8e8068.jsonl`
2. 核对当前 in-tree kinsn 集合、daemon registry/discovery、x86 kinsn module 实现。
3. 对当前 `corpus/build/**/*.bpf.o` 做静态扫描：
   - 扫 `call 0x5` 估算 `bpf_ktime_get_ns` 使用密度
   - 扫 `__int128 add/sub` 对应的 carry/borrow lowering 形态
4. 复用仓库已有 helper 风险扫描与 micro benchmark 文档，补足 workload 侧证据。

## 当前树里已有 kinsn 的画像

当前 formal model 里的 in-tree kinsn 集合只有：

- `bpf_rotate64`
- `bpf_select64`
- `bpf_extract64`
- `bpf_endian_load16`
- `bpf_endian_load32`
- `bpf_endian_load64`
- `bpf_speculation_barrier`

对应文档与实现：

- `docs/kinsn-formal-semantics.md`
- `daemon/src/pass.rs`
- `daemon/src/kfunc_discovery.rs`
- `module/x86/`
- `module/arm64/`

当前 daemon registry/discovery 里也只显式支持：

- `rotate/select/extract`
- `memcpy_bulk/memset_bulk`
- `endian_load16/32/64`

没有任何 `rdtsc` 或 `adc/sbb` 目标。

这很重要，因为当前树里能成立的 kinsn 候选都同时满足两件事：

1. 它们是清晰的局部 refinement：proof sequence 是普通 BPF，native emit 只是更短的目标架构实现。
2. 它们在真实程序里有可见 site 数量或明确的收益面。

已有计划文档里的 corpus 证据正是这种模式：

- `ROTATE`: 701 sites, 15 applied
- `BITFIELD_EXTRACT`: 524 sites, 4 applied
- `ENDIAN_FUSION`: 256 sites, 17 applied

所以后面对 `RDTSC` 和 `ADC/SBB` 的判断，核心不是“ISA 上帅不帅”，而是“是否同时满足这两个条件”。

## RDTSC：需求强，但不是好的透明优化对象

### 1. 真实 workload 里，时间 helper 确实很多

这一点不是猜测，静态证据很强。

本 turn 对当前 build 的快速扫描结果：

- 全部 `corpus/build/**/*.bpf.o`：917 个对象
- 其中命中 `call 0x5`（`bpf_ktime_get_ns`）的对象：150 个
- 总命中次数：1505

去掉 `linux-selftests` 之后，结果依然很高：

- 非 selftests 对象：261 个
- 其中命中 `bpf_ktime_get_ns` 的对象：128 个
- 总命中次数：1396

仓库里更早的一轮 helper 扫描也给出类似结论，只是口径更窄：

- `ktime_get_ns`: 932 次，86 个对象
- `jiffies64`: 221 次
- `ktime_get_boot_ns`: 177 次

也就是说，真实压力不在“有没有计时需求”，而在“计时需求非常常见，而且 helper 家族不止一个入口”。

### 2. micro 侧也有一致信号

`docs/micro-bench-status.md` 里，runtime suite 的结论是：

- `get_time_heavy` 是少数明确对 kernel 更有利的 case 之一
- `helper_call_100` 也属于 helper-heavy workload

这说明“helper 边界本身是热点”这个方向没有问题。

### 3. 但 `RDTSC` 不是 `bpf_ktime_get_ns()` 的语义等价替换

这才是关键。

`bpf_ktime_get_ns()` 的语义是：

- 单位：纳秒
- 语义：内核定义的单调时间源
- 抽象层级：架构无关 helper

`RDTSC/RDTSCP` 的语义是：

- 单位：TSC cycles
- 抽象层级：x86 私有时间戳计数器
- 不是纳秒
- 需要额外处理 ordering、频率换算、迁移/同步等问题

因此，把 `bpf_ktime_get_ns()` “透明地”改写成 `RDTSC`，会立刻遇到三个问题：

1. 单位不对。  
   raw TSC 是 cycles，不是 ns。
2. 时钟域不对。  
   helper 返回的是内核定义的时间抽象，`RDTSC` 返回的是 x86 硬件计数器。
3. 有额外实现负担。  
   一旦要补 fence、cycle->ns 转换、跨 CPU 一致性假设，这就不再是“一条原生指令替一个 helper call”，而是在重做 helper 语义。

这和 `rotate -> RORX`、`branch+mov -> CMOV` 不一样。  
后者是同一语义的更短实现；`ktime_get_ns -> RDTSC` 不是。

### 4. 这个 repo 已经把“测量精度”问题放在 BPF 程序外面解决了

当前 runner 在 BPF 程序外部已经用 `rdtsc` 做测量：

- `runner/src/kernel_runner.cpp`
- `runner/src/llvmbpf_runner.cpp`

也就是说，如果动机是“benchmark 计时精度不够”，当前框架已经在 harness 层解决了这件事。把 `RDTSC` 塞进 BPF 程序本身，并不会改进当前 benchmark infrastructure；它只会引入新的程序语义。

这进一步降低了它作为默认 kinsn 的价值。

### 5. 还有替代时间源，说明问题是“计时 API 面”而不是 helper 5 单点

已有 helper scan 明确显示：

- `ktime_get_ns` 之外，还有 `ktime_get_boot_ns`
- 还有 `jiffies64`

因此，即使只把 helper 5 优化掉，也不会从根本上改变“BPF 程序里存在高频时间读取”这个事实。  
这更像“引入新的显式 timing primitive / helper family 设计”问题，而不是一个局部 peephole。

### 6. 对 RDTSC 的结论

`RDTSC` 不是好的默认 kinsn 候选，也不是好的透明 REJIT pass 候选。

如果将来要做，合理边界应当是：

- 作为显式 opt-in 的 x86-only primitive
- 名义上更接近 `bpf_rdtsc_cycles()` / `bpf_rdtscp_cycles()`
- 目标场景限定在 tracing/profiling/benchmarking
- 明确告诉用户：这是 cycles，不是 portable monotonic ns

换句话说，它更像“新 helper/kfunc API”，不像“透明优化”。

对当前 OSDI 主线和默认 pipeline，我的结论是：不做。

## ADC/SBB：抽象对，但当前几乎没有需求

### 1. 历史会话已经确认：`__int128` add/sub 在 BPF 里会降成显式 carry/borrow 链

中断的前序会话已经做了一个最小 `unsigned __int128` 样例，并确认 clang 面向 BPF 的 lowering 形态。

`add` 的核心序列是：

```text
r3 = r4
r3 += r2
r2 = 0x1
if r4 > r3 goto +0x1
r2 = 0x0
...
r4 += r1
r4 += r2
```

`sub` 的核心序列是：

```text
r2 = 0x1
if r4 > r3 goto +0x1
r2 = 0x0
r3 -= r4
...
r1 -= r4
r1 -= r2
```

也就是说，当前 BPF ISA/JIT 没有针对 carry chain 的专门表达；它就是普通比较 + 条件 carry/borrow + 两段 64-bit 算术。

从 ISA 角度说，这正是 `ADD/ADC` 或 `SUB/SBB` 能吃到的形状。

### 2. 但真实 corpus 里，我这轮一个 site 都没扫到

本 turn 对当前 `corpus/build/**/*.bpf.o` 的扫描结果：

- 917 个 `.bpf.o`
- 命中 `__int128 add` 对应 carry 链：0
- 命中 `__int128 sub` 对应 borrow 链：0

也就是说，当前 build 里没有任何明显的 ADC/SBB 机会点。

这是一个非常强的负信号。

### 3. `__int128` 在真实代码里更多只是“存储布局”，不是“算术热点”

源码 grep 结果也支持这个判断：

- `bcc/libbpf-tools/tcptop.h`
- `bcc/libbpf-tools/tcplife.h`
- `bcc/libbpf-tools/tcpstates.h`

这些地方的 `unsigned __int128` 主要只是拿来放 IPv6 地址字段，不是做 128-bit 算术。

### 4. 甚至有项目显式回避 `__int128`

Datadog 的 BPF 代码里有直接注释：

> Using the type unsigned __int128 generates an error in the ebpf verifier

对应文件：

- `runner/repos/datadog-agent/pkg/network/ebpf/c/conn_tuple.h`
- `runner/repos/datadog-agent/pkg/network/ebpf/c/conntrack/types.h`
- `runner/repos/datadog-agent/pkg/network/ebpf/c/runtime/conntrack-types.h`

他们直接把 IPv6 tuple 拆成 `saddr_h/saddr_l/daddr_h/daddr_l` 四个 `u64`。

这条证据很关键，因为它解释了为什么静态扫描里几乎看不到 `ADC/SBB` 机会点：  
不少真实项目在源码层就主动绕开了 `__int128`。

### 5. 从 kinsn 设计角度看，ADC/SBB 其实是“可以做”的

和 `RDTSC` 不同，`ADC/SBB` 在抽象层面是能放进当前 kinsn 模型里的。

可以把它理解成和当前 `select64` 很像：

- proof side：还是普通 BPF carry/borrow 序列
- native emit side：x86 用 `add; adc` 或 `sub; sbb`
- flags 完全是 site 内部状态，不暴露给 verifier

理论上的设计大致会是：

- payload 编码 `dst_lo/dst_hi/src_lo/src_hi`
- `instantiate_insn()` 生成今天 clang/BPF 已经在生成的那段 carry/borrow proof sequence
- `emit_x86()` 生成两条原生指令，外加必要的寄存器搬运

从这个角度说，它是一个“语义边界正确”的 x86 kinsn 候选。

### 6. 但工程 ROI 仍然偏低

因为它的收益完全取决于真实 site 数量，而当前站内证据是零。

相比现有成功候选，ADC/SBB 有三个劣势：

1. 它是更窄的 x86-only 机会点。  
   不像 rotate/extract/endian 在多个程序里自然出现。
2. 它依赖 pair-value pattern matching。  
   需要同时识别低 64 位、高 64 位和 carry/borrow 链。
3. 当前 workload 不给它任何压力。  
   没有 site，就没有默认 pipeline 价值。

所以它更像一个“如果将来加入专门 workload，就值得回头实现”的 future work，而不是当前主线优化。

### 7. 对 ADC/SBB 的结论

`ADC/SBB` 在语义上是合格的 kinsn 候选，但在当前树里没有足够的 workload 支撑。

如果未来要重新评估，应该先补一组真正会触发它的 benchmark：

- IPv6 address arithmetic
- 128-bit counter increment / decrement
- checksum carry chain
- bigint / crypto style loops

没有这些 workload，直接做实现大概率只会得到一个“漂亮但没有站内收益”的指令模块。

## 直接对比

| 候选 | 是否适合做透明、语义等价优化 | 当前 corpus 压力 | 现在做的工程 ROI | 建议 |
|------|------------------------------|------------------|------------------|------|
| `RDTSC/RDTSCP` | 否 | 高 | 中低 | 不进默认 pipeline；若做，改成显式 opt-in timing primitive |
| `ADC/SBB` | 是 | 极低 | 低 | 不进默认 pipeline；仅作为 future work / 新 benchmark 驱动项 |

## 最终建议

如果目标是当前 repo 的默认 pipeline、当前 OSDI 主线、以及“透明优化”叙事，我的建议非常明确：

1. 现在不要实现 `RDTSC`。
2. 现在也不要实现 `ADC/SBB`。

但两者“不做”的原因不一样：

- `RDTSC`：不是没有需求，而是它更像“新 API / 新语义”，不适合伪装成透明优化。
- `ADC/SBB`：不是抽象有问题，而是当前 workload 完全不需要它。

如果必须二选一保留到 future work：

1. 偏“产品/可用性”方向：保留 `RDTSC`，但改成显式 x86 timing primitive。
2. 偏“指令级优化研究”方向：保留 `ADC/SBB`，但先补会真正触发它的 benchmark 再说。

## 参考输入

- 历史会话：
  - `~/.codex/sessions/2026/03/29/rollout-2026-03-29T18-33-18-019d3c5f-b6e1-75b3-8fd7-4bfb13eb9d9d.jsonl`
  - `~/.codex/sessions/2026/03/29/rollout-2026-03-29T18-52-27-019d3c71-3bb0-76a2-a088-412d3b8e8068.jsonl`
- 当前 kinsn 设计与实现：
  - `docs/kinsn-formal-semantics.md`
  - `daemon/src/pass.rs`
  - `daemon/src/kfunc_discovery.rs`
  - `module/x86/bpf_select.c`
  - `module/x86/bpf_rotate.c`
- 候选清单与已有 corpus 证据：
  - `docs/kernel-jit-optimization-plan.md`
- helper 使用与 timing 侧证：
  - `docs/tmp/20260326/dangerous_helper_firewall_research_20260326.md`
  - `docs/tmp/20260326/helper_scan/dangerous_objects_extended.tsv`
  - `docs/micro-bench-status.md`
  - `runner/src/kernel_runner.cpp`
  - `runner/src/llvmbpf_runner.cpp`
