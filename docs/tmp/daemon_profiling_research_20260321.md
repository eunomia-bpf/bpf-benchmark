# Daemon Runtime Profiling Research

日期: 2026-03-21

## 结论摘要

对 BpfReJIT daemon 来说，当前最适合先落地的 runtime profiling 数据源是 **`bpf_prog_info.run_cnt/run_time_ns` 轮询**：

- 能稳定回答“哪些程序是 hot”
- 开销极低，daemon 端 polling 成本远小于开启 `bpf_stats` 后内核在每次程序执行路径上增加的计时成本
- 已经 upstream，可直接通过 `BPF_OBJ_GET_INFO_BY_FD` 获取
- 我在本机 VM 上已经用 `daemon/src/profiler.rs` 跑通了 POC

但它 **不能** 回答下面两个问题：

- **BranchFlip** 需要的“某条分支 taken/not-taken 各多少次”
- **const propagation** 需要的“某个 map/helper/callsite 访问有多热”

这两类信息，现有 upstream 数据源都没有低开销、跨架构、直接可用的答案。我的建议是：

1. 近期把 daemon 的 PGO 第一阶段限定为 **program hotness**，只用 `run_cnt/run_time_ns`
2. BranchFlip 如果必须上线，优先考虑 **显式插桩**，不要把 daemon 核心决策绑在 LBR/branch stack 上
3. map access hotness 同理，优先考虑 **helper/callsite 级插桩计数**，而不是全局 kprobe/fentry helper tracing

## 数据源对比

| 数据源 | 能回答 hot program | 能回答 branch direction | 能回答 map access hotness | 精度 | 开销 | 结论 |
|---|---:|---:|---:|---|---|---|
| `bpf_prog_info.run_cnt/run_time_ns` | 是 | 否 | 否 | 程序级精确累计值 | 低 | **当前默认方案** |
| `perf stat --bpf-prog` / perf counters | 是 | 只能给 aggregate branches/branch-misses，不能给 edge direction | 否 | 程序级 aggregate | 中 | 可作为补充，不够支撑 BranchFlip |
| perf branch records / LBR | 勉强 | **理论上可行，但强依赖 JIT 地址映射和硬件** | 否 | 架构相关，样本化，不是全覆盖 | 中到高 | **不建议作为 daemon 默认路径** |
| `bpf_prog_info` 其他字段 / iterators / bpf_link | 部分辅助 | 否 | 否 | 静态/元数据为主 | 低 | 适合做 gating，不是 runtime PGO 主数据源 |
| kprobe/tracepoint/fentry 观测另一个 BPF 程序 | 是 | 可以做实验性 branch/LBR 方案 | 理论上可 trace helper 调用 | 取决于挂点和过滤 | 高 | 适合实验，不适合常驻 daemon |

## 1. BPF stats

### 1.1 能拿到什么

在 `kernel.bpf_stats_enabled=1` 或通过 `BPF_ENABLE_STATS(BPF_STATS_RUN_TIME)` 打开后，`struct bpf_prog_info` 会填充：

- `run_cnt`
- `run_time_ns`
- `recursion_misses`

此外，不依赖 stats 开关、同样可从 `bpf_prog_info` 读到的字段还包括：

- `verified_insns`
- `nr_map_ids` / `map_ids`
- `prog_type` / `id` / `name`
- `jited_prog_len` / `xlated_prog_len`
- `load_time`
- `btf_id`
- `attach_btf_obj_id` / `attach_btf_id`
- `nr_func_info` / `func_info_rec_size` / `line_info*` / `prog_tags`

这些字段对 daemon 的价值：

- `run_cnt` / `run_time_ns`: hotness 主指标
- `avg_ns = delta_run_time_ns / delta_run_cnt`: 粗粒度收益估算
- `verified_insns`: 复杂度 proxy，可用于 pass 预算或优先级
- `map_ids`: 只告诉你“这个程序会碰哪些 map”，**不告诉你访问频次**
- `recursion_misses`: 可以识别某些 tracing/trampoline 程序的递归丢样风险

### 1.2 精度

这是 **每个 BPF program 的累计精确计数**，不是采样值。daemon 自己看到的是两个累计值之间的 delta：

- `delta_run_cnt`
- `delta_run_time_ns`
- `delta_avg_ns`

它非常适合做：

- top-N hot program 排序
- “最近一个 polling 窗口是否活跃”
- pass budget 分配

它不适合做：

- 分支方向概率
- per-basic-block hotness
- per-map / per-helper 访问热度

### 1.3 开销

开销分两块：

1. **开启 `bpf_stats` 后，内核执行每次 BPF 程序时增加计时和 per-cpu 统计更新**
2. **daemon 轮询 `BPF_OBJ_GET_INFO_BY_FD` 的用户态 polling 开销**

第一块是常驻执行路径成本，来自内核：

- `__bpf_prog_run()` 在 stats 开启时会在调度前后读 `sched_clock()`，并更新 per-cpu `cnt/nsecs`
- trampoline 路径也会做类似的 start/end 计时与统计更新

第二块我在本机上实测了 daemon POC。

### 1.4 polling 间隔建议

建议分三档：

- **默认 daemon 间隔: 1s**
  - 足够用于长期 hotness 排序
  - 对 100~1000 个程序都很轻
- **较积极的在线优化间隔: 100ms~250ms**
  - 适合 benchmark / 短 burst 工作负载
  - 能更快发现新 hot program
- **不建议低于 50ms 作为常驻默认**
  - 因为现有数据只有 program 级累计值，频率再高也拿不到 branch/map 细节
  - 只会增加 syscall 数量和 decision noise

### 1.5 本机实测

环境：

- Kernel: `Linux 6.15.11-061511-generic x86_64`
- `bpftool v7.7.0`
- `perf` 对当前 kernel 版本缺少匹配工具包，因此这次没有跑 perf/LBR 实测

步骤：

1. `sudo sysctl kernel.bpf_stats_enabled=1`
2. `sudo ./tests/hold_bpf_prog micro/programs/load_byte_recompose.bpf.o 180`
3. 目标程序 ID: `826` (`load_byte_recompose_xdp`)
4. 用 `bpftool prog run` 触发执行，同时用新 daemon profiler 轮询

结果 1: `repeat=1000`

```text
prog 826 baseline: run_cnt=0 run_time_ns=0 avg_ns=-
sample  elapsed_ms   delta_run_cnt   delta_time_ns  delta_avg_ns
--------------------------------------------------------------------
     1     200.162            1000           21695         21.70
     2     200.083               0               0             -
     3     200.157               0               0             -
final totals: run_cnt=1000 run_time_ns=21695 avg_ns=21.70
```

结果 2: `repeat=5,000,000`

```text
prog 826 baseline: run_cnt=1000 run_time_ns=21695 avg_ns=21.70
sample  elapsed_ms   delta_run_cnt   delta_time_ns  delta_avg_ns
--------------------------------------------------------------------
     1     100.188         1438591        15344509         10.67
     2     100.158         3561409        27553277          7.74
     3     100.375               0               0             -
     4     100.223               0               0             -
     5     100.718               0               0             -
final totals: run_cnt=5001000 run_time_ns=42919481 avg_ns=8.58
```

观察：

- delta `run_cnt` 与 `bpftool prog run repeat N` 对得上
- 长 workload 会自然跨多个 polling 窗口分摊
- `run_time_ns/run_cnt` 与 `bpftool prog run` 打印的平均 duration 同数量级，但不完全相等
  - 这里属于 **预期现象**
  - `bpftool prog run` 的 duration 量的是 test-run 路径平均值
  - `bpf_stats.run_time_ns` 量的是 BPF 程序执行路径中的内核 runtime 统计

轮询开销基准：

```text
100000 次 back-to-back profile 轮询，stdout/stderr 丢弃，总耗时 0.089817s
=> 约 0.898 us / poll / program
```

这个数字是 **daemon POC 端到端开销**：

- 复用同一个 prog fd
- 包含用户态循环和 `BPF_OBJ_GET_INFO_BY_FD`
- 不包含“开启 bpf_stats 后，目标程序每次执行自身多出来的计时成本”

按这个数粗估：

- 100 个程序，1s 间隔: 约 `0.09 ms/s`
- 1000 个程序，100ms 间隔: 约 `9 ms/s`，也仍然不到 1 个核的 1%

所以在 daemon 侧，**polling 本身不是瓶颈**。

## 2. perf_event branch profiling

### 2.1 可行的部分

当前 upstream 里能直接做到的是：

- `perf stat --bpf-prog ID -e cycles,instructions,...`
- 对 BPF program 做 aggregate PMU 计数

这适合拿：

- cycles
- instructions
- branches
- branch-misses

但这些都只是 **程序级 aggregate**，不是 per-edge 的 taken/not-taken。

### 2.2 想拿 branch records / LBR 会遇到什么问题

perf branch stack (`PERF_SAMPLE_BRANCH_STACK`) 和 LBR 确实存在，但它们的问题是：

1. **强依赖硬件和架构**
   - branch records 不一定存在
   - x86 LBR 最常见，虚拟机和部分 CPU 上可能没有
2. **是 branch sample / snapshot，不是全计数**
   - 捕获的是最近 N 个硬件 branch entries
   - 不是每条静态分支的累计 taken/not-taken 计数
3. **很难稳定映射回 eBPF branch**
   - LBR 给的是 JIT 后机器码地址
   - 需要 JIT 镜像地址、反汇编、指令边界、JIT 优化后映射
   - 这一步高度 arch-specific
4. **daemon 不好做目标隔离**
   - 我在当前 perf 文档里找到了 `perf stat --bpf-prog`
   - **没有找到** `perf record --bpf-prog` 这类 branch sampling 直接按 BPF program 过滤的接口
   - 这意味着如果走 `perf record -j ...`，更像是 system-wide sampling + 事后按 JIT 地址范围过滤
   - 这是我基于当前文档做的推断

### 2.3 helper 路径

upstream 还提供两个相关 helper：

- `bpf_read_branch_records(ctx, ...)`
  - 只能在 **perf_event** 类型 BPF 程序里，从 perf event context 取 branch records
- `bpf_get_branch_snapshot(entries, size, flags)`
  - 直接从硬件分支引擎取 snapshot
  - helper 调用后硬件引擎很快会被停掉，内核文档明确要求使用者自己过滤 entries

这说明：

- **branch records 是能拿到的**
- 但仍然不是“拿到某条 eBPF `if` 分支 taken/not-taken 次数”的直接解

### 2.4 对 BranchFlip 的建议

如果 BranchFlip 需要 **稳定、可重复、可跨架构** 的分支方向数据，建议不要以 LBR 作为 daemon 默认实现。

更现实的两条路：

1. **rewrite 插桩**
   - 在候选条件分支前后插 per-edge counter
   - 最稳，直接得到 edge count
   - 代价是需要 instrumented image
2. **内核/REJIT 扩展**
   - 在 JIT 或 interpreter 侧加 branch profile hook
   - 复杂但最终数据质量最好

结论：**perf/LBR 适合研究原型，不适合当前 daemon 默认路径。**

## 3. BPF iterators / bpf_link / prog_info 其他字段

### 3.1 iterators / bpf_link 本身不是 profiling 数据源

`bpf_iter` 和 `bpf_link` 更像是：

- 枚举/遍历 kernel object
- 挂接/生命周期管理

它们很适合做：

- 列出所有 live BPF prog / map / link
- 读元数据

但不直接产生：

- branch direction
- map access count
- per-BB hotness

### 3.2 `bpf_prog_info` 里值得 daemon 用的字段

除了 `run_cnt/run_time_ns`，我认为最值得接进 pass framework 的还有：

- `verified_insns`
  - 适合做 pass budget / compile complexity hint
- `nr_map_ids` / `map_ids`
  - 适合做静态 dependency 发现
  - 对 const-prop 很重要，但只是“可能会访问哪些 map”
- `recursion_misses`
  - tracing 程序可用来识别 profile 可靠性问题
- `jited_prog_len` / `xlated_prog_len`
  - 能估计代码膨胀和收益空间
- `attach_btf_obj_id` / `attach_btf_id`
  - 对 fentry/fexit/struct_ops/LSM 等 program type 做 attach-side 分类有用

### 3.3 对 const propagation 的意义

这里只有一个坏消息：

- `prog_info.map_ids` 只能回答“程序关联到哪些 map”
- **回答不了“哪一个 map 被访问得更热”**

所以 const propagation 需要的 map hotness，最终还是要靠：

- helper/callsite 插桩计数
- 或者高开销 helper tracing

## 4. kprobe / tracepoint / fentry 观测另一个 BPF 程序

### 4.1 是否可行

可行。

最直接的 upstream 证据是 `bpftool prog profile` 的实现：它会给目标 BPF 程序挂 `fentry`/`fexit`，在 entry/exit 读取 perf counters，并累计差值。

这说明：

- 一个 BPF 程序可以通过 trampoline/profile hook 观测另一个 BPF 程序
- 条件是目标 program type / BTF / attach 方式支持

### 4.2 精度

这条路径适合拿：

- per-program cycles
- per-program instructions
- cache/TLB misses

它不直接适合拿：

- per-edge branch direction
- per-map access frequency

### 4.3 开销

这条路径的开销明显高于 `run_cnt/run_time_ns`：

- 每次目标程序执行，至少多经过一次 entry hook 和一次 exit hook
- 每次 hook 还要做 perf event read

我没有在本机上跑这一块，因为当前 kernel 缺匹配 `perf` 用户态工具包；但从实现结构上看，这条路径不适合作为常驻 daemon 默认 profiling。

### 4.4 `fentry on bpf_prog_run?`

技术上可以考虑在通用 `bpf_prog_run` 路径上做 fentry/kprobe，再按 `prog` 指针或 ID 过滤。

但这有两个问题：

1. 它会先拦住 **所有** BPF 程序执行，再过滤
2. `bpf_prog_run` / trampoline 路径本身就是超热路径

所以这更像 debug/实验工具，而不是生产 daemon。

## 5. 对 daemon/PPOAnalysis 的建议

### 5.1 当前可以稳定接入的 PGOAnalysis

第一版 `PGOAnalysis` 建议只包含：

- `delta_run_cnt`
- `delta_run_time_ns`
- `delta_avg_ns`
- `total_run_cnt`
- `total_run_time_ns`
- `verified_insns`
- `map_ids`

用法：

- `delta_run_cnt` / `delta_run_time_ns` 做 hotness admission
- `delta_avg_ns` 做收益排序
- `verified_insns` 做复杂度 gating
- `map_ids` 做后续更细粒度 instrumentation 的目标发现

### 5.2 暂时不要承诺的 PGOAnalysis 字段

以下字段在没有插桩前，不建议在 pass 框架里当成“稳定可用接口”：

- `branch_taken_count[edge]`
- `branch_not_taken_count[edge]`
- `map_access_count[map_id]`
- `helper_call_count[callsite]`

## 6. 本次 POC 代码

### 6.1 新增文件

- `daemon/src/profiler.rs`

提供：

- `poll_prog_stats(prog_id) -> Result<ProgStats>`
- `ProgStatsPoller`
- `ProgStatsDelta`
- `collect_prog_stats_deltas(...)`
- `PgoAnalysis::from_delta(...)`
- `bpf_stats_enabled()`

### 6.2 CLI 验证入口

新增：

```bash
sudo ./daemon/target/release/bpfrejit-daemon profile <prog_id> --interval-ms 200 --samples 5
```

这个接口不是最终 daemon API，只是为了把 POC 在 VM 里跑通并方便验证 delta 逻辑。

## 7. 最终建议

### 推荐落地顺序

1. **现在就上线**
   - `run_cnt/run_time_ns` 轮询
   - `verified_insns/map_ids` 辅助元数据
2. **下一阶段补强**
   - 针对 BranchFlip / const-prop 做显式插桩 prototype
3. **研究项**
   - x86-only LBR + JIT address reverse mapping
   - fexit + `bpf_get_branch_snapshot()` 实验性 branch attribution

### 默认策略

- daemon 默认 polling 间隔: **1s**
- benchmark/debug 模式: **100ms~250ms**
- 不把 perf/LBR 设为默认依赖
- 不把 helper tracing 设为常驻方案

## Sources

公开文档：

- Linux sysctl: <https://docs.kernel.org/admin-guide/sysctl/kernel.html#bpf-stats-enabled>
- BPF iterators: <https://docs.kernel.org/bpf/bpf_iterators.html>
- `bpf(2)`: <https://man7.org/linux/man-pages/man2/bpf.2.html>
- `perf-record(1)`: <https://man7.org/linux/man-pages/man1/perf-record.1.html>

本仓库内核源码 / 文档：

- `vendor/linux/include/uapi/linux/bpf.h`
- `vendor/linux/include/linux/filter.h`
- `vendor/linux/kernel/bpf/trampoline.c`
- `vendor/linux/kernel/bpf/syscall.c`
- `vendor/linux/tools/perf/Documentation/perf-stat.txt`
- `vendor/linux/tools/perf/Documentation/perf-record.txt`
- `vendor/bpftool/docs/bpftool-prog.rst`
- `vendor/bpftool/src/prog.c`

说明：

- “`perf record` 文档中没有 `--bpf-prog`，而 `perf stat` 有” 这一点是基于当前仓库同步的 perf 文档与源码做的推断
- “fentry/fexit 方案的 overhead 明显高于 BPF stats” 是基于 bpftool profiler skeleton 的执行路径做的工程判断，不是本机实测数值
