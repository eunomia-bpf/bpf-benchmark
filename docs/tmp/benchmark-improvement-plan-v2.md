# BpfReJIT Benchmark Improvement Plan v2

日期：2026-03-11

## 0. 结论先行

当前 benchmark 并不是“只测 XDP”，但这个事实没有被系统地展示出来。

- micro suite 目前确实以 XDP 为主：67 个 benchmark 中 64 个是 XDP，2 个是 tc，1 个是 cgroup_skb。
- corpus exec 已经以 tc 为主：`docs/tmp/corpus-runnability-results.json` 显示当前有 79 个 paired exec 程序，其中 `sched_cls=61`、`xdp=16`、`cgroup_skb=2`；paired site 数分别是 `2144/60/220`。
- corpus census 已覆盖全类型静态分布：已有 17637 个 directive sites / 220 objects，可支撑“跨类型存在性”和 code-size 论证。
- e2e 已覆盖 tracing/lsm/tracepoint 场景，但它回答的是 attach+trigger 价值，不是 isolated `exec_ns`。

因此，benchmark 改进的正确方向不是把所有类型都硬塞进 micro `test_run`，而是：

1. 短期把 corpus exec 的 tc/cgroup_skb 能力做扎实、做显式。
2. 中期把“非网络类型”主要放到 code-size + e2e 两条线上。
3. 论文里明确说明三层 benchmark 各自回答的问题。

## 1. 数据依据与当前约束

本方案只基于以下已读数据：

- `docs/tmp/corpus-runnability-results.json`
- `micro/runner/src/kernel_runner.cpp`
- `micro/orchestrator/corpus.py`
- `micro/programs/common.h`
- `vendor/linux-framework/net/bpf/test_run.c`
- `docs/kernel-jit-optimization-plan.md`（轻量参考）

关键事实：

- corpus runnability 文件是全量 program 级记录，不是只有 79 条 paired 样本。
- 其中 summary 为：
  - `programs_found=1836`
  - `loadable_programs=1214`
  - `packet_candidate_programs=304`
  - `packet_runnable_programs=166`
  - `packet_paired_programs=79`
  - `true_runnable_programs=381`
  - `tracing_candidate_programs=1007`
  - `tracing_measured_programs=379`
- 按 `prog_type_name` 看，当前真正有 paired `exec_ns` 的只有三类：
  - `sched_cls: 61`
  - `xdp: 16`
  - `cgroup_skb: 2`
- paired 程序的 directive sites 分布：
  - `sched_cls: 2144`
  - `xdp: 60`
  - `cgroup_skb: 220`
- `micro/orchestrator/corpus.py` 目前把 `xdp/socket/classifier/tc/flow_dissector/sk_skb/sk_msg` 都路由到 `io_mode=packet`；把 `raw_tracepoint/raw_tp` 路由到 `io_mode=context`；其他类型默认也是 `context`，但没有真实 memory payload。
- `micro/runner/src/kernel_runner.cpp` 已支持 `packet/staged/context/map` 四种 I/O 形态；但 `context` 路径当前被强制设成单次运行：
  - `effective_repeat = 1`
  - `test_opts.repeat = 0`
- `micro/programs/common.h` 已有：
  - XDP 的 `packet/staged/map` 宏
  - tc 的 `staged/map` 宏
  - cgroup_skb 的 `staged/map` 宏
- 当前 vendored kernel `test_run.c` 中：
  - `skb/xdp/flow_dissector/sk_lookup` 支持 `repeat` 和 `duration`
  - `raw_tracepoint` 明确 **不支持** `data_in/out`、`ctx_out`、`duration`、`repeat`

这意味着：

- tc/cgroup_skb 扩展是现成路径，不需要新 kernel 能力。
- raw_tracepoint exec micro 只有在内核 `test_run` 支持 `repeat/duration` 之后才值得做成主数据；当前内核不满足。

## 2. 现状总结

### 2.1 一页表格：三层 benchmark 的类型覆盖与测量能力

| 层级 | 当前覆盖 | 当前类型覆盖 | 可直接测什么 | 现有限制 | 对论文回答的问题 |
|---|---:|---|---|---|---|
| micro suite | 67 benchmarks | 64 XDP, 2 tc, 1 cgroup_skb | `exec_ns`、native code size、codegen quality | 以 XDP 为主，非 XDP 样本太少；`context` 路径未做 repeatable exec | 单个 canonical form 是否改善 JIT lowering |
| corpus recompile exec | 79 paired programs / 1836 total scanned | `sched_cls=61`, `xdp=16`, `cgroup_skb=2` | paired `exec_ns`、paired code size、correctness | 只覆盖 packet-test-run 友好类型；报表上没有突出 tc 主体地位 | BpfReJIT 在真实程序上是否有效 |
| corpus census | 220 objects, 17637 sites | 全类型 | static site coverage、可做 code-size 统计 | 无 `exec_ns` | 8 canonical forms 在真实生态中的广泛性 |
| e2e | Tracee/Tetragon/bpftrace | tracing/lsm/tracepoint | attach+trigger、真实工作负载下 end-to-end 收益 | 不隔离单次 program `exec_ns` | 系统在真实部署中的有效性 |

### 2.2 corpus exec 的真实结构

按 `prog_type_name` 聚合的当前状态如下：

| 类型 | 总数 | 可 load | paired exec | paired sites | 备注 |
|---|---:|---:|---:|---:|---|
| `sched_cls` | 185 | 109 | 61 | 2144 | 当前 corpus exec 的主力，不是 XDP |
| `xdp` | 91 | 45 | 16 | 60 | 数量少于 tc，但 micro 中占主导 |
| `cgroup_skb` | 7 | 5 | 2 | 220 | 数量少，但 site 密度不低 |
| `kprobe/tracing/lsm/raw_tracepoint/...` | 1553+ | 大量可 load | 0 | N/A | 当前无法通过统一 `test_run` 获得 paired `exec_ns` |

观察：

- `sched_cls` 不只是“顺手支持”，而是当前 corpus exec 的主体样本。
- `cgroup_skb` 数量不多，但 paired site 数已经高于 XDP，值得扩展。
- “只测 XDP”的真实问题，不是数据缺失，而是展示方式失真。

### 2.3 runner 能力的实际边界

现有 runner 的设计已经足够支撑短期扩展：

- `packet/staged/map` 三条路径都能稳定得到 `duration -> exec_ns`
- tc/cgroup_skb 走 `packet` 或 `map/staged` 路径，本质上复用 `skb test_run`
- `context` 路径当前只做单次 `retval` 风格测量，不适合做低噪声 micro exec

这和内核约束是一致的：

- `bpf_prog_test_run_skb()` 支持 `repeat/duration`
- `bpf_prog_test_run_xdp()` 支持 `repeat/duration`
- `bpf_prog_test_run_raw_tp()` 当前直接拒绝 `duration/repeat`

## 3. 短期改进（1-2 天，可立即做）

### 3.1 从 corpus 中提取更多 tc / cgroup_skb 程序作为 corpus exec benchmark

目标：

- 把 corpus exec 的主叙事从“16 个 XDP 样本”改成“以 tc 为主的真实程序集合”
- 优先扩展 `sched_cls`，其次补满 `cgroup_skb`

理由：

- 现在 `sched_cls` 已有 `109 loadable / 61 paired`，仍有可挖空间。
- `cgroup_skb` 已有 `5 loadable / 2 paired`，补到 4-5 个的成本很低。
- paired site 数已经表明 tc/cgroup_skb 对论文更有价值：`2144 + 220` 明显高于 XDP 的 `60`。

具体动作：

1. 从 `corpus-runnability-results.json` 中筛选：
   - `prog_type_name in {sched_cls, cgroup_skb}`
   - `loadable == true`
   - `strategy == packet_test_run`
2. 对尚未 paired 的样本按失败原因分桶：
   - baseline `test_run` 失败
   - baseline/recompile correctness 不可比
   - 输入包模板不合适
   - 外部 map / 环境依赖过重
3. 先扩展最易收敛的来源：
   - `calico`
   - `linux-selftests`
   - `suricata`
   - 现有 `tracee` 中的 packet-friendly 程序
4. 输出新的“paper set”时，默认按类型分层：
   - `tc-core`
   - `xdp-supplement`
   - `cgroup-skb-supplement`

建议验收线：

- `sched_cls` paired 程序数从 61 提到 75+。
- `cgroup_skb` paired 程序数从 2 提到 4+。
- paired sites 明确以 tc 为主，并在报表首页显示。

### 3.2 确保 corpus recompile runner 对 tc 类型正确测 `exec_ns`

这件事不是“重新发明 runner”，而是把已有能力变成显式保证。

已确认的事实：

- `corpus.py` 已把 `tc` 路由到 `io_mode=packet`
- `kernel_runner.cpp` 的 packet/staged 路径最终都把 `sample.exec_ns = test_opts.duration`
- `test_run.c` 的 `bpf_prog_test_run_skb()` 支持 `repeat/duration`

短期要补的是三类保障：

1. 结果保障
   - 对 `prog_type_name == sched_cls` 的 paired 样本，回归检查 `baseline_run.sample.exec_ns` 和 `recompile_run.sample.exec_ns` 必须非空、非零。
2. 分类保障
   - 报表聚合以 `prog_type_name` 为主，不以“packet benchmark”统称，避免 tc 被 XDP 叙事淹没。
3. 文档保障
   - 在 benchmark 文档中明确写出：tc 使用的是 skb `test_run`，不是 attach+trigger。

建议加的最小回归检查：

- paired 样本数按类型输出
- paired 样本的 `exec_ns` 缺失数按类型输出
- `sched_cls` 和 `cgroup_skb` 的 geomean / median 单独输出

### 3.3 把现有 non-XDP 数据在报表中显式展示

这是最便宜、但对论文叙事收益最大的改动。

首页必须出现的三个数字：

- paired exec 程序数：`61 tc / 16 xdp / 2 cgroup_skb`
- paired sites：`2144 tc / 60 xdp / 220 cgroup_skb`
- 不可做 isolated `exec_ns` 的 tracing 类程序规模：约 `1204`（kprobe/tracing/lsm 量级）

建议新增的图表：

1. `Paired Exec Programs by Type`
2. `Paired Directive Sites by Type`
3. `Exec Speedup Distribution by Type`

如果只能加一页图，我会选：

- 左图：paired 程序数按类型
- 右图：paired site 数按类型

这样 reviewer 一眼就看见 corpus exec 的重心其实是 tc。

## 4. 中期改进（3-5 天）

### 4.1 raw_tracepoint micro benchmark：仅在 `test_run` 支持 repeat 时纳入主线

当前结论非常明确：

- vendored `test_run.c` 里的 `bpf_prog_test_run_raw_tp()` 明确不支持 `duration/repeat`
- 当前 `kernel_runner.cpp` 也把 `context` 路径统一降成单次运行

因此当前不应把 raw_tracepoint exec micro 当成必做项。

正确做法是条件化推进：

1. 如果未来 kernel `raw_tp test_run` 支持 `repeat/duration`
   - 给 runner 增加“repeatable context”白名单，而不是放开所有 `context`
   - 新增 raw_tracepoint micro wrappers
   - 将 raw_tp 作为 tracing 类的 isolated exec 补充
2. 如果内核仍不支持
   - raw_tp 只做 code-size / site-coverage 补充
   - exec 性能继续由 e2e 或 attach-trigger 路线回答

一句话判断标准：

- 没有 kernel 级 `duration/repeat`，就不要把 raw_tp 微基准包装成可信 `exec_ns` 数据。

### 4.2 非网络类型的 code-size 系统化对比

这是最应该做、也最容易在 3-5 天内形成稳定数据的中期项。

原因：

- BpfReJIT 的核心先验是 backend lowering 改善 native code generation。
- 对无法 `test_run` 的 tracing/lsm/kprobe 类程序，code size 仍是有效、低噪声、跨类型的直接证据。
- corpus census 已经给了全类型的 site 分布基础。

建议产出两个层次的数据：

1. per-program
   - baseline/recompile 的 native bytes
   - speedup 没有时，至少给 size delta
2. per-type
   - `kprobe`
   - `tracing`
   - `lsm`
   - `raw_tracepoint`
   - `perf_event`

建议图表：

1. `Code Size Delta by Program Type`
2. `Programs With Sites by Program Type`
3. `Site Count by Canonical Form and Program Type`

这组数据会把“BpfReJIT 不是网络专属”的证据补齐。

### 4.3 corpus exec 扩展到更多 tc 程序

中期目标不是盲目扩样，而是把 tc 做成“可信真实程序主结果”。

建议策略：

1. 优先补高 site 密度、低环境依赖样本
2. 维持 paired baseline/recompile correctness 的严格标准
3. 明确把 tc 结果作为 corpus exec 主表，把 XDP 放到补充表

推荐中期目标线：

- `sched_cls` paired 程序数 90 左右
- `cgroup_skb` paired 程序数接近 loadable 上限
- tc 单独形成稳定 geomean、median、p25/p75 报告

## 5. 对论文的具体建议

### 5.1 哪些数据可以直接进论文

可以直接作为主结果的数据：

- micro suite：67 benchmarks，用来证明 8 canonical forms 的 codegen effect
- corpus exec：79 paired programs，其中 tc 占 61，是真实程序主证据
- corpus census：17637 sites / 220 objects，用来证明生态广泛性
- e2e：Tracee / Tetragon / bpftrace，用来证明 tracing/lsm/tracepoint 场景的现实价值

建议主文结构：

1. micro：解释“为什么这些 canonical forms 值得做”
2. corpus exec：解释“在真实网络程序里是否依然有效”
3. corpus census + code-size：解释“覆盖面不止网络”
4. e2e：解释“在真实部署里是否有系统价值”

### 5.2 如何回答 “你只测了 XDP？” 的 reviewer 质疑

推荐回答口径：

> 不是。micro suite 主要使用 XDP 作为受控 harness，但 corpus exec 的多数样本来自 tc：当前 paired exec 程序中 61 个是 `sched_cls`，只有 16 个是 XDP，另有 2 个 `cgroup_skb`。对于 tracing/lsm/kprobe 类程序，当前 Linux `BPF_PROG_TEST_RUN` 无法提供统一、低噪声的 isolated `exec_ns`，因此我们用两条补充证据回答这部分：一是全类型 corpus census / code-size，对应 backend codegen 影响；二是 Tracee/Tetragon/bpftrace e2e，对应真实 attach+trigger 场景。三层 benchmark 回答的是不同问题，而不是同一指标的重复测量。 

这段回答的关键点有三个：

- 承认 micro 以 XDP 为主，但解释这是 harness 选择，不是结论边界
- 立刻给出 corpus exec 中 tc 为主的硬数字
- 对 tracing 类无法做 isolated `exec_ns` 给出 kernel 机制原因，而不是“暂时没做”

### 5.3 需要哪些图表/表格

主文建议最少包含：

1. 一张 benchmark coverage 总表
   - micro / corpus exec / corpus census / e2e
   - 各自覆盖类型和测量维度
2. 一张 paired exec 程序数按类型图
   - `tc / xdp / cgroup_skb`
3. 一张 paired sites 按类型图
   - 证明真实程序中的 tc 重要性
4. 一张 corpus exec speedup 分布图
   - 按类型分组
5. 一张全类型 code-size 图
   - `kprobe/tracing/lsm/raw_tp/...`
6. 一张 e2e case-study 表
   - Tracee / Tetragon / bpftrace

如果篇幅紧张，压缩顺序应为：

1. 保留 coverage 总表
2. 保留 paired exec 按类型图
3. 保留 e2e 表
4. 其余放 appendix

## 6. 不应该做的

### 6.1 不应该把 kprobe / lsm 硬塞进 micro `test_run`

原因不是“麻烦”，而是方法学上不干净。

第一，当前 kernel 机制不支持统一的、可重复的 isolated exec path。

- kprobe/lsm/tracing 大量类型没有 `BPF_PROG_TEST_RUN` 路径
- raw_tracepoint 现有 `test_run` 也不支持 `duration/repeat`

第二，这些类型的真实语义依赖 hook attachment 和 kernel object state。

- 如果用假的 context 或自造 attach 环境去跑，测到的往往是 harness artifact，不是 JIT 质量
- 这会把“benchmark isolation”变成“benchmark distortion”

第三，这会稀释论文主线。

- BpfReJIT 的 thesis 是 post-load JIT specialization
- micro suite 的任务是隔离 canonical form 对 native lowering 的影响
- 它不需要、也不应该复刻所有 prog_type 的真实 attach 语义

结论：

- tracing/lsm/kprobe 应该主要走 `code-size + e2e`
- 不要为了追求类型表面覆盖率，牺牲测量可信度

### 6.2 为什么 micro suite 专注 JIT codegen，与 prog_type 无强绑定

micro suite 的本质是“最小可控程序 + 单一 canonical form + 可重复输入”。

canonical form 对应的是 JIT lowering pattern，例如：

- conditional select
- wide memory op
- rotate fusion
- address calculation
- bitfield extract

这些模式的核心差异来自：

- BPF 指令形状
- verifier 后 xlated 形态
- backend emission 选择

而不是来自 prog_type 本身。

prog_type 主要影响的是：

- context 布局
- helper / kfunc 可用性
- attach 语义

所以：

- 用 XDP 做 micro harness 是为了低噪声输入和稳定 `test_run`
- 不等于 BpfReJIT 只对 XDP 有效
- `common.h` 已经提供 tc/cgroup_skb 宏，说明 suite 设计本身就是可跨类型复用的

## 7. 建议的执行优先级

按性价比排序：

1. 先改报表，把现有 tc/cgroup_skb 数据显式展示
2. 再扩 corpus exec 的 tc/cgroup_skb paired 集合
3. 然后补全非网络类型 code-size 报表
4. raw_tracepoint exec micro 只在 kernel `test_run` 真正支持 `repeat/duration` 后再做

最终希望形成的论文叙事是：

- micro：canonical forms 在受控环境下确实改善 JIT codegen
- corpus exec：真实程序里，主证据来自 tc，不是只来自 XDP
- corpus census + code-size：覆盖面跨越 tracing / security / networking
- e2e：真实部署中也能带来价值
