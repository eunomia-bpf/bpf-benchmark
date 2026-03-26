# BpfReJIT daemon 运行时数据架构分析（2026-03-26）

## 0. 范围与结论

本文基于以下实现阅读得出结论：

- `daemon/src/main.rs`
- `daemon/src/commands.rs`
- `daemon/src/bpf.rs`
- `daemon/src/analysis/map_info.rs`
- `daemon/src/passes/map_inline.rs`
- `daemon/src/passes/const_prop.rs`
- `daemon/src/passes/dce.rs`
- `daemon/src/invalidation.rs`
- `daemon/src/profiler.rs`
- `daemon/src/pass.rs`
- `daemon/src/kfunc_discovery.rs`
- 补充阅读：`daemon/src/server.rs`、`daemon/src/passes/mod.rs`、`daemon/src/analysis/{branch_target,cfg,liveness}.rs`

先说明两个代码位置上的事实：

1. 仓库里没有独立的 `daemon/src/analysis/pgo.rs`。PGO 的 production 实现实际分散在 `daemon/src/profiler.rs`、`daemon/src/pass.rs` 和 `daemon/src/passes/branch_flip.rs`。
2. `cmd_watch` / `cmd_serve` 不在 `commands.rs`，而是在 `daemon/src/server.rs`。

高层结论：

- daemon 当前有三条运行时数据链路：
  - 启动期环境快照：kfunc/BTF 能力、CPU 能力。
  - 每个 program 的即时快照：`prog_info`、`map_ids`、map metadata、map value、`run_cnt/run_time_ns`。
  - REJIT 反馈：verifier log、最终 xlated/JIT image。
- 这三条链路没有被统一抽象成一个“runtime state layer”。它们分别落在 `PassContext`、`BpfProgram`、`AnalysisCache` 和 pass 内部直接 syscall 四个位置。
- `map_inline` 的 specialization 发生在 pipeline 最前面，`const_prop` 和 `dce` 只是消费它生成的常量和死代码。
- `MapInvalidationTracker` 当前完全未接入 optimize loop；它只是一个独立的数据结构和批量检查器。
- PGO 的数据流只完成了一半：
  - 已实现：program-level `run_cnt/run_time_ns` delta，外加一个 PMU `branch_miss_rate`。
  - 未实现：production 路径里的 per-PC branch profile。
  - 结果：`BranchFlipPass` 在真实运行中基本拿不到它真正需要的 `branch_profiles`，因此实际很难翻转分支。

## 1. Runtime Data Sources

### 1.1 数据源总表

| 数据 | 内核侧来源 | userspace 封装 | 读取时机 | 缓存/新鲜度 | 下游消费者 |
| --- | --- | --- | --- | --- | --- |
| live program ID 列表 | `BPF_PROG_GET_NEXT_ID` | `bpf::iter_prog_ids()` | `enumerate`、`apply-all`、`watch` 每轮、`serve optimize-all` | 每次调用即时读取 | 命令层调度 |
| program FD | `BPF_PROG_GET_FD_BY_ID` | `bpf::bpf_prog_get_fd_by_id()` | 每次操作某个 prog 时 | 即时 | `commands`, `profiler` |
| `bpf_prog_info` | `BPF_OBJ_GET_INFO_BY_FD` | `bpf::bpf_prog_get_info()` | `enumerate`、`rewrite`、`apply`、`apply-all`、`profile`、PGO poll | 每次 syscall 即时快照 | 程序名、`prog_type`、原始字节码、`run_cnt`、`run_time_ns` |
| 原始 BPF bytecode | `orig_prog_insns` in `bpf_prog_info` | `bpf::bpf_prog_get_info(fd, true)` | `enumerate`、`rewrite`、`try_apply_one()` | 每次 per-program 读取 | `BpfProgram` 初始 IR |
| program 使用的 map IDs | `nr_map_ids/map_ids` in `bpf_prog_info` | `bpf::bpf_prog_get_map_ids()` | `enumerate`、`rewrite`、`try_apply_one()` | 每个 optimize/rewrite 操作读一次；rollback retry 复用 | `BpfProgram.map_ids` |
| map metadata | `BPF_MAP_GET_FD_BY_ID` + `BPF_OBJ_GET_INFO_BY_FD` | `bpf::bpf_map_get_info_by_id()` | `MapInfoAnalysis` 首次执行时 | 每个 pipeline run 内按 analysis cache 缓存；下一次 run 重读 | `MapInlinePass` 资格判断 |
| map frozen 状态 | map info 的 best-effort 推断 | `bpf_map_try_detect_frozen()` | 同上 | best-effort；不是统一 runtime version | `MapInfo::is_inlineable_v1()` |
| map value | `BPF_MAP_LOOKUP_ELEM` | `bpf::bpf_map_lookup_elem_by_id()` | `MapInlinePass::build_site_rewrite()` 中按 site 读取 | 不缓存；每个 site 单独读取；retry 会重读 | map specialization |
| program stats | `run_cnt/run_time_ns` in `bpf_prog_info` | `profiler::ProgStatsPoller` | `watch` 热度排序；`--pgo` optimize 前观察；`profile` 子命令 | 每次 snapshot 即时 | hotness ranking，`ProfilingData.program_hotness` |
| PMU 分支计数 | `perf_event_open` + `read/ioctl` | `profiler::pmu::PmuCounters` | `--pgo` optimize 前观察窗口 | 每次 optimize 一次 | `ProfilingData.branch_miss_rate` |
| BTF/kfunc registry | `/sys/kernel/btf/vmlinux`、`/sys/kernel/btf/<module>`、`BPF_BTF_GET_*` | `kfunc_discovery::discover_kinsns()` | `main()` 启动时一次 | daemon 生命周期内固定，不刷新 | `PassContext.kinsn_registry` |
| CPU 能力 | `/proc/cpuinfo` 或架构默认值 | `PlatformCapabilities::detect()` | `main()` 启动时一次 | daemon 生命周期内固定，不刷新 | `PassContext.platform` |
| 最终 xlated/JIT image | `BPF_OBJ_GET_INFO_BY_FD` | `bpf::bpf_prog_get_runtime_images()` | REJIT 成功后调试读取 | REJIT 后即时 | debug JSON |
| verifier log | `BPF_PROG_REJIT(log_level=2)` | `bpf::bpf_prog_rejit()` | REJIT 成功或失败时 | 每次 attempt 即时 | rollback attribution, debug |

### 1.2 何时读取，何时不读取

几个容易误判的点：

- `enumerate` 不是纯静态扫描。`cmd_enumerate()` 会真的跑一遍 pass pipeline，因此 `map_inline` 依然会触发 live map metadata/value 读取。
- `rewrite` 也不是纯 bytecode pretty-print。它同样跑完整 pipeline，只是不执行 `BPF_PROG_REJIT`。
- `watch` 即使没有 `--pgo`，也会调用 `rank_programs_by_hotness()`，因此依然会读 `run_cnt/run_time_ns`。
- `serve` 常驻并不代表自动刷新 runtime data。它只是让“下一次请求再读一次”成为可能。

### 1.3 新鲜度与 staleness 风险

按类型划分：

- 启动期数据：
  - `kfunc_discovery` 和 `PlatformCapabilities::detect` 只在 `main()` 启动时跑一次。
  - 风险是 daemon 常驻期间模块加载/卸载、BTF 变化不会被重新发现。
- per-program 即时数据：
  - `prog_info`、`map_info`、`map_value`、`run_cnt/run_time_ns` 都是在当前 optimize/rewrite 动作里现读。
  - 但它们不是一个原子快照，读取之间可能穿插真实 workload 的变化。
- pipeline 内缓存：
  - `AnalysisCache` 只缓存 `Analysis` 结果，且只活在一次 `PassManager::run()` 内。
  - `map_info` 属于 analysis，可缓存一轮。
  - `map value` 不属于 analysis，不缓存。
- rollback retry：
  - `try_apply_one()` 会复用同一份 `profiling`。
  - 但会重建 `BpfProgram`、重跑 pipeline，因此 map metadata/value 会重新读取。
  - 这意味着“同一个 optimize 请求的不同 retry”理论上可以看到不同 map value。

## 2. 数据流架构

### 2.1 总体数据流

```text
                   kernel / system live state
  ----------------------------------------------------------------
  BPF prog table      BPF map table        BTF objects      PMU/perf
  - prog ids          - map info           - vmlinux        - branch insns
  - prog_info         - map values         - module BTF     - branch misses
  - orig/xlated/jit
  - run_cnt/time_ns
  ----------------------------------------------------------------
          |                  |                 |                |
          v                  v                 v                v
     daemon/src/bpf.rs   daemon/src/bpf.rs  kfunc_discovery   profiler.rs
          \                 /                   |                /
           \               /                    |               /
            \             /                     |              /
             v           v                      v             v
                 commands::try_apply_one() / server::cmd_watch()
                              |
                              v
          +-----------------------------------------------+
          | BpfProgram                                    |
          | - insns                                       |
          | - map_ids                                     |
          | - annotations(branch_profile)                 |
          | - branch_miss_rate                            |
          | - required_btf_fds                            |
          +-----------------------------------------------+
                              |
                              +---- PassContext
                              |     - kinsn_registry
                              |     - platform
                              |     - policy
                              |     - prog_type
                              |
                              v
                    PassManager::run_with_profiling()
                              |
          +-------------------+-------------------------------+
          |                   |                               |
          v                   v                               v
   ProfilingData inject   AnalysisCache                 Pass-local syscalls
   - branch_profiles      - BranchTarget               - map value lookup
   - branch_miss_rate     - CFG                        - later REJIT feedback
   - program_hotness      - Liveness
                           - MapInfo
          |                   |                               |
          +-------------------+---------------+---------------+
                                              |
                                              v
                          passes::map_inline -> const_prop -> dce -> ...
                                              |
                                              v
                         relocate_map_fds + build_rejit_fd_array
                                              |
                                              v
                                     BPF_PROG_REJIT
                                              |
                                              v
                              verifier log / final xlated / JIT image
```

### 2.2 `PassContext` 到底承载了什么

`PassContext` 只承载“环境型”和“相对稳定”的信息：

- `kinsn_registry`
- `platform`
- `policy`
- `prog_type`

它**没有**承载以下运行时数据：

- map IDs
- map metadata
- map values
- program hotness
- per-PC PGO 信息

这些数据分别走了别的通道：

- `BpfProgram.map_ids`
- `AnalysisCache<MapInfoAnalysis>`
- `MapInlinePass` 内部的直接 syscall
- `BpfProgram.annotations` / `BpfProgram.branch_miss_rate`

所以更准确的说法不是“PassContext 把 runtime information 传给 passes”，而是：

```text
PassContext       -> 环境与平台约束
BpfProgram        -> per-program metadata + injected profiling
AnalysisCache     -> 可缓存的分析结果
pass-local syscall -> 非缓存、按需读取的 live value
```

### 2.3 静态分析与 runtime-informed 分析的边界

边界是存在的，但并不整齐。

明确属于“纯静态分析”的部分：

- `BranchTargetAnalysis`
- `CFGAnalysis`
- `LivenessAnalysis`

它们只读当前 `BpfProgram.insns`，不碰内核。

带 runtime 成分的部分：

- `MapInfoAnalysis`
  - 形式上是 analysis。
  - 实际上会走 syscall 去把 `map_id -> live map info`。
- `MapInlinePass`
  - 不是 analysis。
  - 直接在 pass 里读 map value。
- PGO
  - 既不是 analysis，也不进 `PassContext`。
  - 它先在 `commands.rs` 收集，之后被注入 `BpfProgram.annotations`。

因此当前架构是“静态分析框架 + 若干 runtime side channel”，不是一个统一的 runtime-aware analysis framework。

## 3. Map Value Lifecycle

### 3.1 map value 在 pipeline 的哪个位置被读取

默认 pipeline 顺序见 `daemon/src/passes/mod.rs`：

```text
map_inline -> const_prop -> dce -> ...
```

因此 map value specialization 的顺序是：

```text
orig bytecode
  -> MapInfoAnalysis: resolve map reference / type / key_size / value_size / frozen
  -> MapInlinePass: recover constant key + lookup live map value
  -> emit MOV/LD_IMM64 constants
  -> ConstPropPass: fold downstream arithmetic / conditional logic
  -> DcePass: remove dead blocks / nop / unreachable code
  -> REJIT
```

`MapInlinePass::run()` 的关键步骤：

1. 用 `MapInfoAnalysis` 拿到 `map_ref.info`。
2. 从 bytecode 恢复 constant key。
3. 判断 map type/frozen/null-check/fixed-load pattern 是否满足 v1 限制。
4. 在 `build_site_rewrite()` 里调用 `bpf::bpf_map_lookup_elem_by_id(info.map_id, key, value_size)`。
5. 把对 `r0` 返回 value pointer 的固定 offset load 替换为常量装载。
6. 只有 array map 才会进一步删掉 map load/helper/null check 整个 lookup pattern。

### 3.2 value 是读一次缓存，还是每轮重读

结论：

- map metadata：每个 pipeline run 内按 analysis cache 缓存一次。
- map value：**不缓存**。

更细一点：

- 同一个 site，在一次 `MapInlinePass` 里只会读一次。
- 同一个 map/key 若出现在多个 site，代码没有 dedup/cache，会读多次。
- 同一个 optimize 请求如果进入 rollback retry，map value 会重读。
- `watch` / `serve` 的下一次 optimize 请求也会重读。

所以 value 生命周期是“短生命周期、per-site、pass-local”，不是“program-level runtime snapshot”。

### 3.3 从“读到值”到“REJIT 落地”之间会发生什么

存在如下窗口：

```text
read map value
  -> emit replacement constants
  -> const_prop
  -> dce
  -> other passes
  -> relocate_map_fds
  -> BPF_PROG_REJIT
```

在这个窗口里，map value 理论上可以变化。

当前 v1 的缓解手段只有一层：

- `MapInfo::is_inlineable_v1()` 要求 map 必须是 `frozen`，且类型必须支持 direct value access。

但这并不等于“架构上有 snapshot / versioning / invalidation”：

- `frozen` 是 best-effort 推断，不是统一版本号。
- map metadata 和 map value 是分两个 syscall 读的，不是一个原子事务。
- retry 之间可能重新看到不同值。

### 3.4 array 与 hash 的差异

array map：

- 允许 `can_remove_lookup_pattern_v1()`。
- key 必须 `< max_entries`。
- 可删掉 map load/helper/null-check 这整个 lookup pattern。

hash / LRU hash：

- 被标为 `speculative_v1`。
- 必须有紧跟着的 immediate null check。
- 当前实现通常只替换后续 fixed-load 为常量，不会整段删掉 lookup。

这意味着 hash specialization 在语义上仍保留“lookup 是否为 NULL”的控制流，但返回值内容已经被常量化。

### 3.5 `MapInvalidationTracker` 与这条链路的真实关系

当前关系是：**没有接上**。

`daemon/src/invalidation.rs` 已实现的能力只有：

- 记录 `(prog_id, map_fd, key, expected_value)`。
- 按 map 分组批量读取 key。
- 返回哪些 `prog_id` 的当前 value 已经和 `expected_value` 不一致。

但它没有被以下任何地方调用：

- `MapInlinePass`
- `PassManager`
- `try_apply_one()`
- `watch`
- `serve`

所以今天的实际状态是：

```text
MapInlinePass specialization
   X
   X  没有把 dependency metadata 注册给 MapInvalidationTracker
   X
MapInvalidationTracker
   X
   X  没有驱动 re-REJIT / deopt / rollback
   X
watch/serve
   X
   X  不会监听 map change
   X
```

还有一个实现层面的脱节：

- `MapInlinePass` 以 `map_id` 读 value。
- `MapInvalidationTracker` 以 `map_fd` 记录依赖。

这说明 invalidation 模块还没有和现有 specialization path 对齐到同一种 identity。

## 4. PGO / Profiling Lifecycle

### 4.1 PGO 数据如何采集

production PGO 路径在 `commands::collect_pgo_data()` -> `profiler::collect_program_profiling()`。

流程如下：

```text
try_apply_one()
  -> collect_pgo_data(prog_id, interval)
      -> ProgStatsPoller::open(prog_id)
      -> optional PmuCounters::open()
      -> poll_delta() 建 baseline
      -> reset_and_enable PMU
      -> sleep(interval)
      -> read PMU counters + disable
      -> second poll_delta()
      -> build ProfilingData
```

`ProfilingData` 当前 production 字段实际只填了两个：

- `program_hotness = Some(PgoAnalysis)`
- `branch_miss_rate = Option<f64>`

`branch_profiles` 在 production 路径里保持空 `HashMap`。

### 4.2 它如何流到 `BranchFlipPass`

数据流如下：

```text
profiler.rs
  -> ProfilingData
  -> commands::try_apply_one()
  -> PassManager::run_with_profiling()
  -> BpfProgram.inject_profiling()
       - branch_profiles -> annotations[pc].branch_profile
       - branch_miss_rate -> program.branch_miss_rate
  -> BranchFlipPass::run()
```

`BranchFlipPass` 的判定分两层：

1. program 级别：必须有 `branch_miss_rate`，且不超过阈值。
2. site 级别：该 `pc` 必须有 `branch_profile`，且 taken ratio >= `min_bias`。

问题在于 production profiler 从来没生成 per-PC `branch_profile`。因此真实运行里通常会变成：

```text
有 branch_miss_rate
但没有 branch_profiles
=> BranchFlipPass 只能看到 “no PGO data available (PGO-only mode)”
=> 不翻分支
```

所以当前 PGO 闭环是“半截链路”。

### 4.3 是否存在 warmup -> profile -> optimize -> measure 序列

只有很弱的一次性版本：

```text
observe once
  -> optimize once
```

没有实现的部分：

- 没有独立 warmup 阶段。
- 没有 optimize 后再测一轮来验证收益。
- 没有把优化后的性能反馈回下一轮 pass policy。
- 没有 A/B compare。
- 没有“变冷/变热后重新编译”的循环。

`cmd_profile` 只是一个独立诊断命令，不参与自动优化闭环。

### 4.4 PGO 数据质量风险

`run_cnt/run_time_ns` 是 kernel 暴露的 per-program 计数，语义上是对的。

PMU 路径问题更大：

- `perf_event_open` 用的是 `pid = 0`、`cpu = -1`，也就是当前 daemon 线程的 perf event。
- 这并没有把 PMU 计数绑定到“目标 BPF program”上。
- daemon 在观察窗口里基本只是 sleep，因此这个 `branch_miss_rate` 很难视为目标 program 的真实 branch miss rate。

也就是说：

- `program_hotness` 还算可信。
- `branch_miss_rate` 的“归因到某个 BPF prog”在当前实现里是非常可疑的。

## 5. `serve` / `watch` / `apply-all` 的差异

### 5.1 模式对比

| 模式 | 生命周期 | program 发现方式 | runtime data 读取节奏 | 会不会 revisit 已优化 program | map change invalidation |
| --- | --- | --- | --- | --- | --- |
| `apply-all` | 一次性 | 当前所有 `iter_prog_ids()` | 每个 program 读一次 | 不会 | 不可能 |
| `watch` | 常驻轮询 | 每轮重新 `iter_prog_ids()` | 每轮先做 hotness ranking；候选 program 再执行 optimize | 不会，一旦进 `optimized`/`no_op` 就不再看 | 没有 |
| `serve` | 常驻 socket server | 按请求 | 每个请求独立重读 | 取决于客户端是否再次请求 | 没有自动 invalidation |
| `enumerate` | 一次性 | 当前所有 `iter_prog_ids()` | dry-run 也会读 map metadata/value | 不适用 | 不适用 |
| `rewrite` | 一次性 | 指定 program | dry-run 也会读 map metadata/value | 不适用 | 不适用 |

### 5.2 `serve` 模式

`serve` 常驻的只是：

- Unix socket
- 启动期构造好的 `PassContext`
- kinsn 的 BTF FDs

它**不会**后台主动做这些事：

- 重新发现 kfunc/BTF 能力
- 轮询 map value
- 轮询 invalidation tracker
- 发现 program 热度变化

所以：

- daemon stay alive != runtime data 自动刷新
- 只有“客户端再次发 optimize 请求”时，才会重新读一遍 map value / prog stats

### 5.3 `watch` 模式

`watch` 每轮会做两件 runtime 相关的事：

1. `iter_prog_ids()` 发现当前 live program。
2. `rank_programs_by_hotness()` 先观察 200ms，对候选 program 按 `run_cnt` delta 排序。

但它的状态机会让动态优化闭环断掉：

- 成功 optimize 的 prog 被放进 `optimized` 集合。
- 返回 no-op 的 prog 被放进 `no_op` 集合。
- 之后这些 prog 永远不再重试。

所以 `watch` 的真实语义更接近：

```text
发现新程序
  -> 按热度优先 optimize 一次
  -> 成功后永不回头
```

而不是：

```text
持续监听程序行为
  -> 根据 runtime 变化重复 specialize / invalidate / re-specialize
```

### 5.4 `apply-all`

`apply-all` 是最“静止”的模式：

- 每个 program 只走一次 `try_apply_one()`。
- 进程退出后不保留任何 runtime state。
- 不存在 invalidation、revisit、deopt 的可能。

## 6. 架构缺口与风险

### 6.1 runtime-informed 数据没有统一归档层

当前 runtime data 分散在四个地方：

- `PassContext`
- `BpfProgram`
- `AnalysisCache`
- pass-local syscall

带来的后果：

- 很难统一定义 freshness policy。
- 很难做 dependency tracking。
- 很难做“某种 runtime 数据变了，该失效哪些分析/哪些 specialization”。

### 6.2 map specialization 还不是动态优化闭环

现在已经有“猜测”的部分：

- `MapInlinePass` 用 live map value 把 load 变成常量。

但没有“失效”和“回退”的部分：

- 没有记录每个 specialized site 的 provenance。
- 没有把 dependency 注册给 daemon 级 tracker。
- 没有后台 invalidation poller。
- 没有 invalidated -> trigger re-REJIT 的执行器。
- 没有 deopt 到 baseline image 的机制。

`MapInvalidationTracker` 更像一个未来闭环的雏形，不是当前流水线的一部分。

### 6.3 verifier rollback 不是 JVM 式 deopt

当前已经存在的 rollback 只处理这一类问题：

```text
pass 改坏了 verifier 可接受性
  -> 从 verifier log 归因到某个 pass
  -> 禁掉该 pass
  -> 当场重试 REJIT
```

这不是 runtime deopt，因为它不依赖 map/profile 变化，也不发生在“程序已经稳定跑起来之后”。

JVM 类比下的状态：

| 能力 | 当前状态 |
| --- | --- |
| speculate | 部分存在。`map_inline` 会做基于 live value 的 specialization。 |
| dependency record | 基本没有接入主路径。 |
| invalidate on runtime change | 没有。 |
| deopt to safe baseline | 没有。 |
| recompile with new runtime data | 只能靠外部再次触发 optimize，请求级别而非自动闭环。 |

一句话总结：现在更像“带一点 runtime input 的一次性重写器”，还不像 JVM 的 speculate -> invalidate -> deopt -> recompile 系统。

### 6.4 PGO 闭环不完整

缺口有三层：

1. 没有 per-PC branch profile 采集。
2. `program_hotness` 没有真正驱动任何 pass 策略。
3. optimize 后没有再次测量收益。

这导致：

- `BranchFlipPass` 在 production 里几乎不会真正工作。
- `--pgo` 现在更多是在“给 pipeline 注入一个程序级热度和一个可疑的 PMU miss rate”，而不是完整的 profile-guided optimization。

### 6.5 `watch` 的状态机会阻断动态再优化

一旦某个 program 成功优化，`watch` 就把它加入 `optimized` 集合并永久跳过。

这会直接阻断以下未来需求：

- map 变了，应该重编。
- profile 变了，应该换一种 specialization。
- 之前冷，后来热，应该再跑一次 PGO。

也就是说，即使 `MapInvalidationTracker` 未来接上了，`watch` 的当前状态机仍然需要改。

### 6.6 启动期 capability snapshot 会变陈旧

`discover_kinsns()` 和 `PlatformCapabilities::detect()` 都只在 daemon 启动时运行。

这意味着：

- 新 kinsn module 在 daemon 启动后加载，daemon 看不到。
- 旧 module 被替换/卸载，daemon 不会重新发现。

这在 `serve` / `watch` 这类长寿命模式里尤其明显。

### 6.7 `bpf_stats_enabled` 依赖没有统一前置检查

`cmd_profile` 会显式检查 `/proc/sys/kernel/bpf_stats_enabled`。

但：

- `watch` 热度排序不会先检查。
- `--pgo` optimize path 也不会先检查。

结果是如果宿主没开 `kernel.bpf_stats_enabled=1`：

- stats 可能静默退化为 0 或不可读。
- 排序/PGO 逻辑会“能跑但没有有效数据”。

### 6.8 map identity 与 invalidation key 的模型还没统一

主优化路径用的是：

- `map_id`

invalidation 草图用的是：

- `map_fd`

而 `map_fd` 是进程局部、可变生命周期的句柄，不像 `map_id` 那样天然适合做 daemon 级稳定标识。

这说明 invalidation 设计真正落地前，还需要先统一对象身份模型。

## 7. 推荐的心智模型

当前最准确的心智模型不是“daemon 维护一份持续更新的 runtime knowledge base”，而是：

```text
启动时:
  读取一份较稳定的环境信息
  -> PassContext

每次 optimize/rewrite 时:
  现读一份 per-program live snapshot
  -> BpfProgram + AnalysisCache + pass-local syscalls

完成后:
  立即把 rewrite 提交给 REJIT
  -> 不保留与 runtime 依赖绑定的长期状态
```

所以它现在更接近：

- startup capability discovery
- one-shot live-value specialization
- verifier-guided compile-time retry

而不是：

- 持续 profiling
- dependency tracking
- invalidation
- deopt / recompile

## 8. 最终回答对应问题的简明结论

### 8.1 Runtime Data Sources

- daemon 会从 kernel/system 读：
  - live BPF program IDs
  - `bpf_prog_info`，包括 `prog_type`、name、orig/xlated/JIT image、`run_cnt/run_time_ns`、map IDs
  - live map metadata 和 best-effort frozen 状态
  - live map value
  - BTF object / module BTF / kfunc registry
  - CPU platform capability
  - REJIT verifier log
- 其中：
  - kfunc/BTF/CPU capability 是启动期一次性读取。
  - prog/map/stats/value 基本都是 per-program、per-request/round 读取。
  - map value 没有统一缓存。

### 8.2 Data Flow Architecture

- kernel -> `bpf.rs` / `profiler.rs` / `kfunc_discovery.rs`
- -> `commands::try_apply_one()` / `server::cmd_watch()`
- -> `BpfProgram` + `PassContext`
- -> `PassManager::run_with_profiling()`
- -> analyses / passes
- -> `relocate_map_fds()` + `BPF_PROG_REJIT`

### 8.3 Map Value Lifecycle

- value 在 `MapInlinePass` 内按 site 读取。
- 读完后先经过 `const_prop`、`dce` 再 REJIT。
- value 不是统一 snapshot，也不参与 invalidation。
- `MapInvalidationTracker` 目前与主优化链路没有连接。

### 8.4 PGO Lifecycle

- profiler 用 `bpf_prog_info.run_cnt/run_time_ns` 做程序级 hotness。
- 另用 `perf_event_open` 采 `branch_miss_rate`。
- 然后把 `ProfilingData` 注入 `BpfProgram`。
- 但 production 里没有 per-PC `branch_profiles`，所以 `BranchFlipPass` 缺少核心输入。

### 8.5 `serve/watch` vs `apply-all`

- `serve`：常驻，但不自动刷新；只在新请求到来时重读。
- `watch`：常驻轮询并按热度先处理，但成功优化后不会 revisit。
- `apply-all`：一次性，没有 invalidation 的位置。

### 8.6 Gaps / Risks

- 没有统一 runtime state / dependency model。
- 没有动态 invalidation loop。
- 没有 JVM 风格 deopt/recompile。
- PGO 只有 program-level，缺少 branch-level 数据。
- PMU 数据对目标 program 的归因不可信。
- `watch` 的状态机不支持长期动态优化。

