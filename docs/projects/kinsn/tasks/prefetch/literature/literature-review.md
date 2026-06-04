# Prefetch Literature Review

最后更新：2026-06-03。

## 文档边界

本文件是 Kinsn prefetch task 的 literature review 和 source-cache 索引，不是当前实现计划，也不是
最新实验结果。

当前 canonical task docs 在：

```text
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch
```

阅读当前状态时必须以这些文件为准：

```text
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/README.md
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/plan.md
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/policy-matrix.md
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/results.md
```

## 结论

Kinsn 里的 `PRFM/PREFETCHT0` 不能按“在某个 load 前插一条 prefetch hint”来设计。
这类策略缺少 timeliness、candidate selection 和 overhead control，已有 ARM64 PRFM micro /
Katran 结果也说明它不是稳定收益。

更合理的结论是：

1. `bpf_arm64_prfm_pldl1keep` 和 `bpf_x86_prefetcht0` 可以保留为底层 kfunc ABI。
2. 当前 prefetch selector 只能算可运行 prototype，不是可默认启用的算法。
3. 下一步必须先做 research-driven micro，而不是直接扩展默认策略。
4. 最有价值的方向不是 sequential/short packet load，而是 hardware prefetcher 难处理、但
   software 能提前知道地址的 indirect access。
5. 如果 micro 上仍然找不到稳定 positive region，PRFM 应作为 negative / forced-only family。

## Review 规则

后续更新本 review 必须遵守：

1. 必须保存完整 source。论文保存 PDF/PS，网页保存 HTML，开源实现保存源码或 repository snapshot。
2. 不能只看 abstract、新闻稿、博客或搜索摘要就写设计结论。
3. 每个 design claim 必须能追溯到本地 source cache。
4. 下载失败或被登录墙阻挡的 source 必须在 manifest 中标出，不能写成已阅读。
5. 不能复制长段原文；报告只写归纳、对比和对 Kinsn 的设计影响。

Source cache：

```text
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/literature/sources
```

Source manifest：

```text
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/literature/sources/manifest.tsv
```

## 问题定义

这个 task 研究的是 Kinsn 项目的 prefetch family：

```text
BPF program
  -> prefetch selector inserts KINSN_SIDECAR + KINSN_CALL
  -> target kfunc is bpf_arm64_prfm_pldl1keep / bpf_x86_prefetcht0
  -> kernel kinsn JIT emits native PRFM / PREFETCHT0
  -> CPU treats it as a cache prefetch hint
```

这里的 prefetch 是 CPU cache prefetch，不是 Linux page-cache readahead。它不改变程序语义。
所以 correctness 只能证明 kfunc path 没坏，不能证明 performance policy 有用。

当前 repo 已有实现：

| arch | kfunc | native hint | source |
|---|---|---|---|
| ARM64 | `bpf_arm64_prfm_pldl1keep` | `prfm pldl1keep, [xN]` | `/home/ruoji/github/bpf-opt/code/module/arm64/bpf_arm64_prfm.c` |
| x86 | `bpf_x86_prefetcht0` | `prefetcht0 [rN]` | `/home/ruoji/github/bpf-opt/code/module/x86/bpf_x86_prefetch.c` |

当前 `bpfopt` prefetch pass：

```text
/home/ruoji/github/bpf-opt/code/bpfopt/crates/bpfopt/src/passes/prefetch.rs
```

它已经做了有限 lookahead，例如 map value dereference、packet pointer dereference、固定 slot
distance 和基本安全过滤。但它还缺少文献中反复出现的几个条件：

- likely miss 判断。
- prefetch distance / injection site 的 timeliness model。
- cacheline dedup。
- bandwidth / cache pollution control。
- per-site 或 profile feedback。
- 对 verifier-safe insertion point 的显式证明。

### 和 upstream LLVM ARM 预取通道的关系

Deepresearch 里最值得保留的一点是：upstream LLVM 已有一条普通 C/C++ 编译链使用的
prefetch 通道，但它和 Kinsn 当前 task 不是同一条 path。

普通 LLVM path 是：

```text
C/C++ __builtin_prefetch 或 LLVM LoopDataPrefetch
  -> llvm.prefetch intrinsic
  -> ISD::PREFETCH
  -> ARM/AArch64 target lowering
  -> PLD/PLDW/PLI 或 PRFM
```

Kinsn path 是：

```text
BPF bytecode
  -> bpfopt prefetch selector inserts KINSN_SIDECAR + KINSN_CALL
  -> bpf_arm64_prfm_pldl1keep / bpf_x86_prefetcht0
  -> kernel kinsn JIT emits PRFM / PREFETCHT0
```

因此，LLVM ARM backend 的现有实现有两个可参考点，但不能直接替代 Kinsn selector：

1. 它证明 prefetch primitive 的 lowering 本身不是难点；难点是 policy。
2. `TargetTransformInfo` 暴露了 distance、minimum stride、iteration-ahead、address-space 等 hook，
   说明成熟实现不会硬编码一个固定距离。

本地 source 还确认了两个边界：

- AArch64 `AArch64TargetMachine.cpp` 有 `aarch64-enable-loop-data-prefetch` 和
  Falkor HW prefetch fix 的 pipeline reference。
- ARM32 `ARMISelLowering.cpp` 有 `ISD::PREFETCH -> ARMISD::PRELOAD` lowering，但本轮没有把
  “ARM32 默认接入 LoopDataPrefetch pass”作为已证事实；它不影响 Kinsn PRFM task。

## Source 覆盖范围

本轮 review 覆盖四类 source。

| 类别 | 代表 source | 目的 |
|---|---|---|
| ISA / compiler / vendor interface | Arm PRFM, LLVM `llvm.prefetch`, GCC `__builtin_prefetch`, Intel optimization manual, Linux `prefetch.h`, DPDK `rte_prefetch.h` | 判断 prefetch primitive 的语义和工程使用方式。 |
| LLVM / QEMU implementation source | LLVM LoopDataPrefetch, TargetTransformInfo, ARM/AArch64 lowering, AArch64 Falkor HWPF fix, QEMU AArch64 decode | 区分普通 LLVM compiler path 和 Kinsn path，并确定性能评估不能依赖 QEMU。 |
| 软件/编译器 prefetch | Mowry 1992, Luk/Mowry 1996, Ainsworth/Jones 2017, APT-GET 2022, LLVM/GCC loop prefetch pass | 判断 selector 应该如何选 candidate、distance、insertion site。 |
| OS / eBPF programmable policy | FetchBPF ATC 2024 | 判断 eBPF 作为 prefetch policy mechanism 的设计边界。 |
| 硬件 / HW-SW co-design prefetch | GRP, Bingo, IPCP, Berti, Pythia, CLIP, Prophet, Pickle, PF-LLM | 判断现代 prefetch 设计如何处理 pattern diversity、timeliness、bandwidth 和 programmability。 |

## 设计矩阵

### Criteria 定义

| Criteria | 含义 | 为什么对 Kinsn 重要 |
|---|---|---|
| Access pattern | 方法针对 affine loop、pointer chain、indirect array、spatial footprint、temporal correlation、page fault 等哪类访问。 | BPF packet/map 程序通常短、分支多，不能假设有 dense loop。 |
| Decision point | 决策是在 programmer、compiler、profile phase、hardware runtime、offline model 还是 eBPF policy 中做。 | Kinsn 当前主要能在 static BPF bytecode / LLVM backend 做决策。 |
| Timeliness control | 是否显式选择 prefetch distance 和 insertion site。 | 太近没有 latency hiding，太远会 evict / pollute。 |
| Candidate quality | 是否判断 likely miss、not hardware-prefetchable、critical load。 | 对 hot data 或 sequential access 插 PRFM 只会增加成本。 |
| Address generation | prefetch target 地址是否能提前、安全、低开销地算出来。 | BPF verifier safety 和 pointer bounds 决定能不能插。 |
| Overhead control | 是否控制额外指令、metadata、bandwidth、cache pollution。 | PRFM 本身也是一条 native instruction，错误 hint 会变慢。 |
| Deployability | 是否能在现有 Kinsn/eBPF 框架中实现。 | 需要避免大硬件改动、用户态 round trip 或不可验证 pointer 操作。 |

### 方法对比

| 方法 | Source | Access pattern | Decision point | Timeliness | Candidate quality | Kinsn 适配度 |
|---|---|---|---|---|---|---|
| ISA hint / builtin | Arm PRFM, LLVM, GCC, Intel | 不限制 | programmer / compiler | 不自动处理 | 不自动处理 | 高，适合作为 kfunc ABI；低，不能当算法。 |
| Manual packet/data-plane prefetch | Linux `prefetch.h`, DPDK `rte_prefetch.h` | packet processing / streaming | programmer | 人工调位置 | 人工判断 | 中；说明 packet path 会用 prefetch，但需要 workload-specific tuning。 |
| Affine loop compiler prefetch | Mowry 1992, GCC loop prefetch, LLVM LoopDataPrefetch | dense array / regular loop | compiler | loop distance | locality analysis | 低到中；BPF 很少是典型 affine loop，但规则可借鉴。 |
| Target TTI controlled compiler prefetch | LLVM TargetTransformInfo, AArch64TargetMachine | regular loop / target-known memory system | compiler + target hooks | distance / stride / max ahead hooks | target policy | 中；对 Kinsn 的直接启发是参数化距离和 target-gated policy。 |
| Recursive data structure prefetch | Luk/Mowry 1996 | pointer-linked structures | compiler / data-layout transform | jump pointer / linearization | pointer structure analysis | 低；BPF 通常不能改 kernel data layout。 |
| Indirect memory software prefetch | Ainsworth/Jones 2017 | `A[B[i+d]]` 类 indirect access | compiler | lookahead distance + duplicated slice | 过滤可能 fault 的 slice | 高；这是 Kinsn 最值得模仿的算法形态。 |
| Profile-guided / runtime software prefetch | APT-GET 2022, RPG² 2024 | irregular / indirect apps | profile / runtime tuning | profile-guided or online distance/site | 可按输入和机器 rollback / tune | 中；短期不做 runtime injection，但必须保留 distance sweep 和 per-site attribution。 |
| eBPF page-prefetch policy | FetchBPF 2024 | Linux page fault / readahead | eBPF policy hook | policy-dependent | policy-dependent | 中；机制上启发 Kinsn，但它是 page prefetch，不是 CPU cache PRFM。 |
| Microarchitecture-specific compiler workaround | AArch64 Falkor HWPF fix | target-specific hardware prefetcher hazard | target machine pass | CPU-specific | CPU-specific tag collision analysis | 中；如果 PRFM 默认启用，必须 CPU-gated，不能全局策略。 |
| Cooperative HW/SW region prefetch | GRP 2003 | spatial / pointer / indirect region | compiler hints + hardware engine | hardware handles scheduling | compiler classifies load kind | 中；说明“软件给语义、硬件发请求”比纯软件 hint 更稳，但需要硬件支持。 |
| Spatial hardware prefetch | Bingo, IPCP | spatial footprint / IP-classified patterns | hardware runtime | hardware dynamic | accuracy/coverage hardware metrics | 低；Kinsn 不能改 CPU prefetcher，但可借鉴 pattern taxonomy。 |
| Local/timely hardware prefetch | Berti 2022 | per-IP local delta / L1D | hardware runtime | measured timely deltas | per-IP coverage/timeliness | 低到中；强化“按 site 而不是全局固定距离”这个原则。 |
| Learned/system-aware hardware prefetch | Pythia, CLIP, PF-LLM | heterogeneous workloads | online RL / offline LLM / criticality model | dynamic / learned | accuracy, timeliness, bandwidth | 低到中；证明 prefetch 需要多维反馈，不适合作为当前短期实现。 |
| Programmable LLC prefetch | Pickle 2025 | irregular graph / software-known future | software policy + hardware scheduler | hardware scheduler | software describes strategy | 中；和 Kinsn 目标相近，但需要新的 hardware mechanism。 |
| Temporal prefetch metadata management | Prophet 2025 | recurring irregular temporal correlation | profile-guided HW/SW | profile-guided metadata policy | useful metadata filtering | 低；Kinsn 没有 temporal metadata table，但结论支持 profile/feedback。 |

## 逐类分析

### 1. ISA / compiler / vendor interface

Arm `PRFM`、x86 `PREFETCHT0`、LLVM `llvm.prefetch`、GCC `__builtin_prefetch` 和 Linux/DPDK
helper 都把 prefetch 定义成 hint。共同点是：

- hint 不改变程序语义。
- target 不支持或 CPU 判断无用时可以弱化。
- programmer/compiler 必须自己决定“prefetch 谁”和“提前多久”。

对 Kinsn 的影响：

```text
kfunc ABI 是必要但不充分的。
PRFM/PREFETCHT0 正确 emit 只能证明 mechanism work，不能证明 policy work。
```

DPDK 和 Linux 的接口还说明：工业/社区通常不会让工具对每个 load 自动 prefetch，而是暴露
不同 locality / write / non-temporal 语义，让开发者在 hot path 上人工调。

### 2. Affine loop compiler prefetch

Mowry/Lam/Gupta 的 ASPLOS 1992 论文和 GCC/LLVM 的 loop prefetch pass 代表传统 compiler
prefetch。核心设计是：

1. 对 loop reference 做 locality/reuse analysis。
2. 只 prefetch likely miss 的 reference。
3. 计算 prefetch-ahead distance。
4. 控制 prefetch count 和 loop transform overhead。

GCC 的 `tree-ssa-loop-prefetch.cc` 明确有 `prefetch_mod`、`prefetch_before`、trip count、
simultaneous prefetch limit、instruction/prefetch ratio 等 cost model。LLVM 的
`LoopDataPrefetch.cpp` 也依赖 target-provided prefetch distance、cacheline size、stride threshold。

对 Kinsn 的影响：

- 不能固定一个 `TARGET_PREFETCH_DISTANCE=8` 后宣称算法完成。
- 必须有 minimum lead distance、max hint count、dedup、loop/region cost model。
- BPF program 不一定有 LLVM/GCC 期待的 affine loop，所以这类方法只能提供原则，不是直接实现。

### 2.1 LLVM ARM/AArch64 prefetch implementation evidence

Deepresearch 中关于 LLVM ARM backend 的部分有参考价值，但要按层次拆开：

| 证据 | 本地 source | 对 Kinsn 的意义 |
|---|---|---|
| `LoopDataPrefetch.cpp` 在 IR 层插入 `llvm.prefetch`。 | `sources/opensource/llvm-loop-data-prefetch.cpp` | 可借鉴 candidate/distance/cost model；不能直接处理 BPF bytecode。 |
| `TargetTransformInfo.h` 有 prefetch distance、minimum stride、max iterations ahead、write-prefetch、address-space hooks。 | `sources/opensource/llvm-target-transform-info.h` | 说明成熟策略必须 target-parameterized，不能只用一个全局 `TARGET_PREFETCH_DISTANCE`。 |
| AArch64 target pipeline 有 `aarch64-enable-loop-data-prefetch`。 | `sources/opensource/llvm-aarch64-targetmachine.cpp` | 证明 AArch64 upstream compiler path 支持 IR-level automatic loop prefetch。 |
| AArch64 lowering 支持 `ISD::PREFETCH` 和 `aarch64_prefetch` intrinsic 到 target prefetch node。 | `sources/opensource/llvm-aarch64-isel-lowering.cpp` | 证明 primitive lowering 不是主要研究风险。 |
| ARM32 lowering 支持 `ISD::PREFETCH -> ARMISD::PRELOAD`，TableGen 中有 PLD/PLDW pattern。 | `sources/opensource/llvm-arm-isel-lowering.cpp`, `sources/opensource/llvm-arm-instr-info.td` | 说明 32-bit ARM 也有 primitive lowering；但不作为 Kinsn ARM64 PRFM 的实现依据。 |
| AArch64 Falkor HWPF fix 是 CPU-specific pass。 | `sources/opensource/llvm-aarch64-falkor-hwpf-fix.cpp` | 如果将来默认启用 PRFM，也应 CPU-gated / workload-gated，而不是全局默认。 |

这部分对当前 Kinsn PRFM task 的结论是：

```text
LLVM upstream 的经验支持“policy 和 lowering 分层”。
Kinsn 已经有 lowering/native emit；现在缺的是 BPF bytecode 层的 policy。
```

### 3. Pointer-based / recursive data structure prefetch

Luk/Mowry 的 ASPLOS 1996 论文说明 pointer-chasing 的核心困难：未来 node 地址依赖当前 node
load。如果要提前 `d` 个 node，直接跟指针会产生 `d` 次 dereference，成本很高，且 lead time
不够。论文讨论 greedy prefetch、history pointer、data linearization 等方案。

对 Kinsn 的影响：

- 不应该把所有 “map value pointer chain” 当成天然 positive case。
- 如果地址必须先执行一个 load 才知道，那么 PRFM 很可能太晚。
- 除非 BPF program 已经有自然 jump pointer / offset table，否则 Kinsn 不能靠 PRFM 自动解决
  linked-structure latency。

### 4. Indirect memory access software prefetch

Ainsworth/Jones CGO 2017 是当前最贴近 Kinsn 的论文。它处理的是：

```text
idx = index_array[i + distance]
prefetch data_array[idx]
```

关键点：

- 目标 data access 是 irregular，硬件 stride prefetcher 很难预测。
- 地址生成 slice 可以从未来 iteration 复制出来。
- 不只要 prefetch 最终 data，有时还要 prefetch address-generation chain 中的 intermediate data。
- prefetch distance、architecture、memory-level parallelism 都影响收益。

对 Kinsn 的影响：

```text
下一版 PRFM micro 应优先构造 packet/map 里的 indirect access。
例如 packet 中先读 offset table，再按 offset 访问 payload；或 map value 中有 index/offset，再访问另一个位置。
```

这比 “first map value deref” 或 “简单 packet deref” 更可能出现 stable win。

### 5. Profile-guided timely software prefetch

APT-GET 直接指出 static prefetch 的主要问题是 timeliness：即使 prefetch 是 accurate，也可能
太早或太晚。它用 profile 估计 load execution time，选择 prefetch distance 和 injection site。

RPG² 进一步把这个问题推进到 runtime：同一个 prefetch policy 会随 input 和 microarchitecture
变化而变成 win 或 slowdown，因此它采用 online profiling、runtime injection/tuning 和 rollback。
这对 Kinsn 很重要，因为我们已经观察到 PRFM 在 micro / Katran 上并不是稳定 win。

对 Kinsn 的影响：

- 当前阶段不必马上做 profile-guided selector。
- 但 micro 必须做 distance sweep，否则无法判断失败原因。
- 每个 site 需要保存 native dump、site count、static instruction count、runtime raw samples。
- 如果将来进入 corpus/app policy，应该记录 per-site performance feedback，而不是只看 geomean。
- 如果某个 prefetch variant 在一部分 case 变快、一部分 case 变慢，默认策略必须能禁用或 rollback，
  不能只按 overall geomean 开启。

### 6. OS / eBPF programmable prefetch

FetchBPF 是最相关的系统论文，但它研究的是 Linux page prefetch/readahead policy，不是 CPU cache
`PRFM/PREFETCHT0`。它的价值是机制层面的：

- eBPF 可以作为 kernel policy 的安全扩展机制。
- 不同 workload 需要不同 prefetch policy，不存在 one-size-fits-all。
- 一个 prefetch framework 应该抽象 common mechanism，让 policy 可替换。

对 Kinsn 的影响：

- Kinsn 的 PRFM task 不应该只追求“把 hint 插进去”，而应该把 prefetch policy 独立成可评估单元。
- 但 FetchBPF 的 page prefetch hooks 不能直接证明 CPU-cache PRFM 有用。
- 如果 Kinsn 想讲系统故事，FetchBPF 是 related work；如果讲 micro kinsn，Ainsworth/Jones 和
  APT-GET 更直接。

### 7. Hardware and HW/SW co-design prefetch

GRP、Bingo、IPCP、Berti、Pythia、CLIP、Prophet、Pickle、PF-LLM 的共同信息是：现代 prefetch 不是
单一 hint，而是一个多维决策问题。

| 方向 | 关键信息 | 对 Kinsn 的影响 |
|---|---|---|
| GRP | compiler 提供 load hint，hardware 负责低开销生成请求。 | 软件分类有价值，但纯软件 PRFM 缺少 hardware scheduler。 |
| Bingo / IPCP | 不同 instruction/page/region 有不同 spatial pattern。 | Kinsn selector 需要按 pattern 分类，不要全局同一策略。 |
| Berti | L1D prefetch 也要按 static instruction / local delta 学 timely access。 | Kinsn selector 应按 site 记录和比较，不应只做 family-level geomean。 |
| Pythia | 需要多种 program context 和 system feedback，且要考虑 bandwidth。 | 只看 static BPF pattern 可能不够，negative result 合理。 |
| CLIP | 高 accuracy prefetch 在 bandwidth-constrained 系统也可能伤害性能。 | micro 必须记录 slowdown，不能只看 hit/miss 或 site count。 |
| Prophet | profile-guided hints 可辅助 temporal metadata management。 | 将来可做 profile，但不是短期必要条件。 |
| Pickle | irregular graph prefetch 更适合 software-defined policy + hardware scheduling。 | Kinsn 的 software policy 思路对，但缺少专用 scheduling hardware。 |
| PF-LLM | offline 分析 load context，给 hardware prefetcher hint。 | 说明静态上下文有用，但最终仍需要 runtime hardware consumer。 |

这些论文共同反对一个结论：

```text
不要把 prefetch 看成“哪个 native instruction 更快”。
真正问题是：这个 hint 是否 timely、accurate、low-overhead、not bandwidth-harmful。
```

### 8. Evaluation boundary: QEMU is correctness-only

Deepresearch 中“QEMU 不能用于 PRFM 性能结论”这一点应纳入本 task。QEMU AArch64 decode source
明确把 PRFM 标成 no-op for QEMU；QEMU mailing list 也解释过 PRFM 不应引发真实 memory access，
architecture 允许把 prefetch 当成 NOP 处理。

对 Kinsn 的影响：

- QEMU 可以用来检查 object / loader / dump path 是否不崩。
- QEMU 不能用来判断 PRFM 是否减少 cache miss 或变快。
- PRFM performance gate 必须在真实 ARM64/x86 hardware 上跑 kernel runtime，并保存 PMU/perf
  counter。至少要记录 `cycles`、`instructions`、cache miss / refill、dTLB miss 或平台可用的
  closest counters。
- benchmark framework 仍只能保存 raw measurements；ratio/geomean 和 PMU 解释在 analysis-side 做。

## 对当前 Kinsn PRFM 的判断

已有实验显示：

| 证据 | 结论 |
|---|---|
| `/home/ruoji/github/bpf-opt/experiments/2026-05-26-arm64-prfm-native-jit-dump-fix` | native JIT dump 确认能 emit `prfm pldl1keep, [xN]`。 |
| `/home/ruoji/github/bpf-opt/experiments/2026-05-27-arm64-family-only-same-llc-attribution` | PRFM affected geomean `1.009656628`，约 0.97% slower。 |
| `/home/ruoji/github/bpf-opt/experiments/2026-05-29-arm64-targeted-jit-dump-attribution` | `simple_packet` 和 `payload_prefix_memcmp_scan` 只增加 PRFM，没有稳定收益。 |

结合 literature，解释是：

1. 当前 candidate 太宽，可能预取 hot data、短路径 data 或 helper 已触碰过的 data。
2. 当前 distance 是固定 slot，不一定对应 CPU 上的 memory latency。
3. 当前没有判断 target load 是否 likely miss。
4. 当前没有区分 sequential packet scan 和 indirect access。
5. 当前没有 bandwidth/cache pollution control。

因此默认 policy 应保持 disabled。

## 推荐设计

### Short-term: research micro, not default selector

先实现 micro 和评估，不改默认策略。

Micro 必须覆盖四组：

| Suite | 目的 | 预期 |
|---|---|---|
| Negative: immediate-before-load | 验证“load 前一条插 prefetch”无效。 | treatment 不快或更慢。 |
| Negative: hot / short packet path | 验证 hot L1 / short path 不应插。 | treatment 不快。 |
| Sweep: same access + distance variants | 找 timeliness window。 | 只有某些距离可能有效。 |
| Positive candidate: indirect packet/map access | 模拟 Ainsworth/Jones 的 indirect pattern。 | 如果 PRFM 有价值，应该在这里体现。 |

每个 micro 至少有这些 variants：

```text
no-prefetch
prefetch-distance-0
prefetch-distance-2
prefetch-distance-4
prefetch-distance-8
prefetch-distance-16
prefetch-distance-32
```

每个 variant 必须保存：

- raw kernel runtime samples。
- raw PMU / perf samples：至少包括 cycles、instructions、cache miss/refill、dTLB miss 或平台可用的
  nearest events。
- BPF xlated dump。
- native JIT dump。
- `prfm` / `prefetcht0` count。
- static native instruction count。
- affected site list。

### Selector v3 条件

selector v3 已经作为 conservative admission policy 落地。它仍不是默认启用策略；只有后续
same-LLC attribution 找到稳定 positive region，才允许扩大默认 admission。selector v3 必须满足：

| 条件 | 要求 |
|---|---|
| Candidate class | 先只支持 packet/map indirect access，不支持 arbitrary load。 |
| Safety | insertion point 必须被 null/bounds/verifier-safe condition dominate。 |
| Address slice | 计算 prefetch address 的 slice 不能引入新的可能 faulting load，除非该 load 本身已有 verifier-safe proof。 |
| Distance | distance 参数化，不硬编码一个值。 |
| Dedup | 同 cacheline / 同 static address expression 不能重复插。 |
| Budget | 每个 basic block 或 loop 有 max prefetch count。 |
| Default policy | 未通过 AWS same-LLC attribution 前必须 disabled 或 forced-only。 |

### Longer-term: profile-guided optional path

如果 static selector 有 positive region，但迁移到 corpus/app 后不稳，可以考虑 profile-guided path：

1. 收集 per-site runtime attribution。
2. 记录 site 的 hit/miss proxy、lead distance、native sequence。
3. 只对 positive site 默认启用。

这对应 APT-GET / Prophet / PF-LLM 的启发，但不是当前第一步。

## 实验标准

Prefetch 实验和普通 kinsn family 不一样。`REV` / `EXTR` 是 semantic replacement；PRFM 是
hint insertion。因此标准必须更严格：

| 标准 | 要求 |
|---|---|
| Correctness | object symbol、BPF xlated dump、native JIT dump 都要通过。 |
| Performance | 必须用 kernel runtime；`llvmbpf` 不能证明 PRFM 效果。 |
| Hardware | 性能结论必须来自真实 ARM64/x86 hardware；QEMU 只能用于 correctness / dump path。 |
| PMU evidence | 每个 performance run 必须尽量保存 cycles、instructions、cache miss/refill、dTLB miss 或平台可用 closest counters。 |
| Attribution | 必须 per-case 展示，不只给 geomean。 |
| Stability | 至少 3 组 independent AWS control/treatment pair。 |
| Explanation | 对 win/slowdown 都要说明 native instruction delta、hint count、distance、candidate class。 |
| Scope | framework 只保存 raw measurement；ratio/geomean 在 analysis side 做。 |

## 结论性判断

目前不能默认启用 prefetch family。

应该执行的下一步是：

```text
1. 保留现有 ABI 和 native emit。
2. 保留 prefetch micro suite 和 policy matrix。
3. 使用 selector v3 过滤明显错误策略。
4. 对 packet first-deref 做 x86/ARM64 多轮 same-LLC attribution。
5. 为 map value prefetch 增加 profile/PMU gate。
6. 只有 positive window 稳定后，才考虑 default candidate。
```

如果 indirect-access micro 也不能稳定变快，prefetch 应写成 Kinsn 的 negative result：

```text
Kinsn can expose CPU prefetch hints safely, but automatic PRFM/PREFETCHT0 insertion is not justified as a default policy on the evaluated BPF workloads.
```

## Sources

完整 source 已下载到：

```text
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/literature/sources
```

主要公开链接：

- Arm PRFM instruction documentation:
  `https://developer.arm.com/documentation/ddi0602/2021-12/Base-Instructions/PRFM--register---Prefetch-Memory--register--?lang=en`
- LLVM `llvm.prefetch` intrinsic:
  `https://llvm.org/docs/LangRef.html#llvm-prefetch-intrinsic`
- GCC `__builtin_prefetch`:
  `https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html`
- Intel Optimization Reference Manual:
  `https://www.intel.co.jp/content/dam/doc/manual/64-ia-32-architectures-optimization-manual.pdf`
- Mowry, Lam, Gupta, “Design and Evaluation of a Compiler Algorithm for Prefetching,” ASPLOS 1992:
  `https://suif.stanford.edu/papers/mowry92.pdf`
- Luk, Mowry, “Compiler-Based Prefetching for Recursive Data Structures,” ASPLOS 1996:
  `https://www.cs.cmu.edu/~profet/papers/asplos96_RDS_pf.ps.gz`
- Ainsworth, Jones, “Software Prefetching for Indirect Memory Accesses,” CGO 2017:
  `https://www.cl.cam.ac.uk/~tmj32/papers/docs/ainsworth17-cgo.pdf`
- APT-GET, “Profile-guided Timely Software Prefetching,” EuroSys 2022:
  `https://crss.us/media/pubs/763ceada9d994d9493489e730a34adf969f0a7e0.pdf`
- FetchBPF, “Customizable Prefetching Policies in Linux with eBPF,” USENIX ATC 2024:
  `https://www.usenix.org/system/files/atc24-cao.pdf`
- GRP, “Guided Region Prefetching,” ISCA 2003:
  `https://www.cs.utexas.edu/ftp/dburger/papers/ISCA03_prefetch.pdf`
- Bingo Spatial Data Prefetcher, HPCA 2019:
  `https://www.cs.cmu.edu/~18742/papers/Bakhshalipour2019.pdf`
- IPCP, ISCA 2020:
  `https://www.cse.iitb.ac.in/~biswa/IPCP_ISCA20.pdf`
- Pythia, MICRO 2021:
  `https://people.inf.ethz.ch/omutlu/pub/Pythia-customizable-hardware-prefetcher-using-reinforcement-learning_micro21.pdf`
- Berti, MICRO 2022:
  `https://webdiis.unizar.es/~chus/pubs/2022_MICRO.pdf`
- CLIP, MICRO 2023:
  `https://www.cse.iitb.ac.in/~biswa/MICRO23.pdf`
- RPG², ASPLOS 2024:
  `https://zyuxuan0115.github.io/files/RPG2_ASPLOS_2024.pdf`
- Prophet, ISCA 2025:
  `https://zhiyaoxie.com/files/ISCA25_Prophet.pdf`
- Pickle Prefetcher:
  `https://arxiv.org/pdf/2511.19973`
- PF-LLM, ASPLOS 2026:
  `https://fact-lab.hkust.edu.hk/publications/conference-paper/2025/xu-2025-pf-llm/3779212.3790202.pdf`
- DPDK `rte_prefetch.h`:
  `https://raw.githubusercontent.com/DPDK/dpdk/main/lib/eal/include/generic/rte_prefetch.h`
- Linux `prefetch.h`:
  `https://raw.githubusercontent.com/torvalds/linux/master/include/linux/prefetch.h`
- LLVM `LoopDataPrefetch.cpp`:
  `https://raw.githubusercontent.com/llvm/llvm-project/main/llvm/lib/Transforms/Scalar/LoopDataPrefetch.cpp`
- LLVM `TargetTransformInfo.h`:
  `https://github.com/llvm/llvm-project/blob/main/llvm/include/llvm/Analysis/TargetTransformInfo.h`
- LLVM `AArch64TargetMachine.cpp`:
  `https://github.com/llvm/llvm-project/blob/main/llvm/lib/Target/AArch64/AArch64TargetMachine.cpp`
- LLVM `AArch64FalkorHWPFFix.cpp`:
  `https://github.com/llvm/llvm-project/blob/main/llvm/lib/Target/AArch64/AArch64FalkorHWPFFix.cpp`
- LLVM ARM/AArch64 prefetch lowering:
  `https://github.com/llvm/llvm-project/blob/main/llvm/lib/Target/AArch64/AArch64ISelLowering.cpp`,
  `https://github.com/llvm/llvm-project/blob/main/llvm/lib/Target/ARM/ARMISelLowering.cpp`
- GCC `tree-ssa-loop-prefetch.cc`:
  `https://raw.githubusercontent.com/gcc-mirror/gcc/master/gcc/tree-ssa-loop-prefetch.cc`
- Pythia source repository:
  `https://github.com/CMU-SAFARI/Pythia`
- QEMU AArch64 decode:
  `https://raw.githubusercontent.com/qemu/qemu/master/target/arm/tcg/a64.decode`
- QEMU PRFM NOP discussion:
  `https://lists.gnu.org/archive/html/qemu-devel/2017-03/msg04907.html`
