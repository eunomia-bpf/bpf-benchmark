# bpfopt / daemon 重构分析

日期：2026-04-26

## 1. 结论摘要

当前 `bpfopt-suite/` 已经完成了第一阶段的“代码搬家”，但还没有完成第二阶段的“架构分层”。

- `bpfopt-suite` 里最有价值的部分，是把 `daemon` 的优化 pass、IR、analysis、pipeline 抽到了 `bpfopt-core`，并且已经把 `map_inline` / `map_info` 从实时内核查询改成了 side-input 模式。
- 但 `daemon/` 仍然是唯一真正完整、可工作的实现。它没有依赖 `bpfopt-suite`，仍然自己携带 `analysis` / `pass` / `passes` / `bpf` / `profiler` / `server` / `commands` 全套实现。
- 因此现在的真实状态不是“daemon 已经拆完”，而是“同一套逻辑被复制成了两份，而且两份已经开始漂移”。
- 如果按你现在要求的目标收敛，`bpfopt-suite` 不应该继续往“六个工具齐活”方向补，而应该反过来收缩成 `bpfopt`：只保留纯优化 pass library + CLI；`rejit` / `verify` / `daemon` / `profiler` / `syscall` 全部留在 `daemon/` 一侧。

一句话判断：`bpfopt-suite` 现在更像“抽取中的 fork”，还不是最终的“纯优化层”。

## 2. 设计约束

我先按仓库现有设计约束来判断边界：

- `docs/kernel-jit-optimization-plan.md:364` 明确写了 `bpfopt-suite` 设计目标：pipeline 由 bash 组装，`daemon` 退化成 `REJIT` 代理 + watch 薄壳。
- `docs/tmp/bpfopt_design_v3.md:13-18` 定义了六个工具：`bpfopt` / `bpfverify` / `bpfprof` / `bpfget` / `bpfrejit` / `bpfrejit-daemon`。
- `docs/tmp/bpfopt_design_v3.md:38` 把 `bpfopt` 定义为“纯字节码优化器，零内核依赖”。
- `docs/tmp/bpfopt_design_v3.md:214-241` 又把 `bpfrejit-daemon` 定义成“不做任何优化，不跑 pass pipeline”的可选 watch 薄壳。

但当前代码和上面这组设计并不一致：

- `daemon/src/main.rs:7-21` 仍然直接编译并链接 `analysis` / `bpf` / `commands` / `insn` / `invalidation` / `kfunc_discovery` / `pass` / `passes` / `profiler` / `server`。
- `daemon/src/commands.rs:533-740` 仍然在 daemon 内部跑完整 pipeline、逐 pass dry-run verify、最终 REJIT。
- `daemon/src/server.rs:77-216` 仍然在 daemon 内部持有 profiling 状态、hotness 排序、invalidation tick 和 socket 协议。

所以设计文档里的“薄壳 daemon”并没有真正落地。

## 3. `bpfopt-suite/crates/` 与 `daemon/src/` 的对应关系

| crate | 当前职责 | `daemon/src/` 对应关系 | 结论 |
|---|---|---|---|
| `bpfopt-core` | pass library、analysis、IR、pipeline | 对应 `daemon/src/analysis/*`、`daemon/src/insn.rs`、`daemon/src/pass.rs`、`daemon/src/passes/*`、`daemon/src/verifier_log.rs`，另外还带了测试辅助 `elf_parser.rs` / `test_utils.rs` | 这是唯一已经有实质迁移价值的 crate，但还不够“纯” |
| `bpfopt` | CLI front-end，读 raw insns，注入 side-input，调用 `bpfopt-core` | 没有一一对应的单文件；它把原本 daemon 内部的 pipeline 入口外部化了 | 应保留，但要与 library 重新命名/收口 |
| `bpfget` | 目标是读取 live BPF 程序与 metadata | 应抽自 `daemon/src/bpf.rs`，并可能复用 `daemon/src/kfunc_discovery.rs` | 现在 `main.rs` 是 stub，未完成 |
| `bpfverify` | 目标是 `BPF_PROG_LOAD` dry-run verify | 应抽自 `daemon/src/bpf.rs`，必要时配合 `daemon/src/verifier_log.rs` | 现在 `main.rs` 是 stub，未完成 |
| `bpfprof` | 目标是 profile 采集 | 对应 `daemon/src/profiler.rs` + `daemon/src/bpf.rs` | 现在 `main.rs` 是 stub；`src/profiler.rs` 是近复制件 |
| `bpfrejit` | 目标是执行 `BPF_PROG_REJIT` | 对应 `daemon/src/bpf.rs` 最终 REJIT 路径，外加 `daemon/src/commands.rs` 里的 fd-array 组装逻辑 | 现在 `main.rs` 是 stub，未完成 |
| `bpfrejit-daemon` | 目标是 watch 薄壳 | 理论上对应 `daemon/src/main.rs`、`server.rs`、`commands.rs`、`invalidation.rs` | 现在 `main.rs` 是 stub；`commands_ref.rs` / `server_ref.rs` / `invalidation.rs` 只是旁置复制件 |
| `kernel-sys` | 目标是抽出 raw syscall wrapper | 直接对应 `daemon/src/bpf.rs` | 现在仍是 placeholder，没有真正抽出 |

补充观察：

- `bpfopt-suite/Cargo.toml:2-10` 仍然把所有六个工具和 `kernel-sys` 都作为 workspace member。
- `daemon/Cargo.toml:11-17` 完全没有依赖 `bpfopt-suite` 的任何 crate；这说明当前不是“共享实现”，而是“平行复制”。

## 4. 哪些 crate 不应该存在于最终的 `bpfopt`

按你给的目标，“`bpfopt` 应该是纯优化 pass，不应该包含 `rejit` / `daemon` / `verify` / `syscall`”，那最终 `bpfopt` 目录里不该有这些 crate：

1. `crates/kernel-sys`
   - 这是 raw syscall wrapper。
   - `bpfopt-suite/crates/kernel-sys/src/lib.rs:2-10` 自己就写着 TODO，要从 `daemon/src/bpf.rs` 提取。
   - 这类代码天然属于 daemon/kernel integration 层，不属于纯 pass 层。

2. `crates/bpfget`
   - 它是 live kernel introspection 工具，不是 optimizer。
   - `bpfopt-suite/crates/bpfget/src/main.rs:4-6` 目前还是 stub。

3. `crates/bpfverify`
   - 它是 verifier dry-run 工具，不是 optimizer。
   - `bpfopt-suite/crates/bpfverify/src/main.rs:4-6` 目前还是 stub。

4. `crates/bpfprof`
   - 它是运行时 profile 采集工具，不是 optimizer。
   - `bpfopt-suite/crates/bpfprof/src/main.rs:4-6` 目前还是 stub。

5. `crates/bpfrejit`
   - 它是 REJIT 提交工具，不是 optimizer。
   - `bpfopt-suite/crates/bpfrejit/src/main.rs:4-6` 目前还是 stub。

6. `crates/bpfrejit-daemon`
   - 它是 daemon/watch 层，不是 optimizer。
   - `bpfopt-suite/crates/bpfrejit-daemon/src/main.rs:4-6` 目前还是 stub。

也就是说，按新的边界，整个 `bpfopt-suite` workspace 最终应该被砍到只剩“优化层”本身，而不是继续保留六工具总装。

## 5. 应该保留在最终 `bpfopt` 的内容

如果只保留纯优化层，应该保留的是下面两部分：

1. 现 `bpfopt-core` 里的纯 pass / IR / analysis 代码
   - `analysis/*`
   - `insn.rs`
   - `pass.rs` 的纯 IR / pipeline / analysis cache 部分
   - `passes/*`

2. 现 `bpfopt` CLI
   - `bpfopt-suite/crates/bpfopt/src/main.rs:19-107` 已经有完整 CLI 形状。
   - `bpfopt-suite/crates/bpfopt/src/main.rs:262-459` 已经能读 target/profile/map-values/map-ids side-input 并驱动 `PassManager`。

但这里有一个关键点：不是“整个 `bpfopt-core` 原封不动保留”，而是“保留其中纯优化的部分”。当前 `bpfopt-core` 里仍然混着几类不够纯的东西：

### 5.1 不该继续留在纯 pass library 里的模块/概念

- `verifier_log.rs`
  - `bpfopt-suite/crates/bpfopt-core/src/verifier_log.rs:2-13` 明确是 verifier log parser，而且注释直接提到 `bpf_prog_rejit()` failure path。
  - 这属于 verifier-oracle / daemon debug 层，不属于纯 pass core。

- `PassVerifyResult` / `PassVerifyStatus` / `run_with_verifier`
  - `bpfopt-suite/crates/bpfopt-core/src/pass.rs:315-404` 把 verify 状态塞进了 `PassResult`。
  - `bpfopt-suite/crates/bpfopt-core/src/pass.rs:793-978` 的 `run_with_verifier()` 已经把“逐 pass verify + rejection rollback”做成了 core 逻辑。
  - 这直接把 daemon 的 orchestration 策略带进了 core。

- `required_btf_fds` / `target_btf_fds`
  - `bpfopt-suite/crates/bpfopt-core/src/pass.rs:54-56` 的 `required_btf_fds` 注释写得很清楚：这是给 serve optimize path 构建 REJIT `fd_array` 用的。
  - `bpfopt-suite/crates/bpfopt-core/src/pass.rs:478-580` 的 `KinsnRegistry` 还持有 BTF FD transport metadata。
  - 这不是“是否能优化”的抽象能力，而是“如何把结果送进 REJIT”的 transport 细节。

- `elf_parser.rs` / `mock_maps.rs` / `test_utils.rs`
  - `bpfopt-suite/crates/bpfopt-core/src/lib.rs:9-17` 这些模块被 runtime crate 直接导出。
  - `bpfopt-suite/crates/bpfopt-core/src/insn.rs:447-470` 甚至保留了测试时按 repo 路径找 `.bpf.o` 的 helper。
  - 这些应该下沉到 `tests/support` 或 dev-only support crate，而不是留在纯 runtime library 里。

### 5.2 应保留但需要抽象净化的能力

- `map_inline` / `const_prop` 对 side-input 的依赖应该保留。
  - `bpfopt-suite/crates/bpfopt/src/main.rs:326-371` 已经把 map snapshot / profile 注入到了 `BpfProgram`。
  - `bpfopt-suite/crates/bpfopt-core/src/pass.rs:70-89` 已经有 `map_values` / `map_metadata` 容器。
  - 这类 side-input 是“纯优化数据依赖”，不是 daemon 依赖。

- kinsn/target capability 本身应该保留，但 transport 细节应抽掉。
  - pass 需要知道某个 lowering target 是否可用。
  - 但它不需要知道 REJIT `fd_array` 如何组装，也不需要知道 daemon 怎样保活这些 FD。

## 6. `daemon/` 和 `bpfopt-suite/` 之间的代码重复

### 6.1 重复不是少量，而是系统性复制

我按文件级对照后，结论是：

- `bpfopt-core/src` 一共有 32 个 Rust 源文件。
- 其中有 30 个能在 `daemon/src` 找到直接对应物。
- 其中 12 个是逐字相同复制。
- 其中 18 个已经发生了定制化分叉。

对应 diff 统计显示，`bpfopt-core/src` 相对于 `daemon/src` 这一块大约是“8k+ 行新增 / 500+ 行删改”量级，不是薄适配，而是一整套 fork。

### 6.2 主要重复面

1. Pass core 重复
   - `bpfopt-core` 与 `daemon/src/analysis/*`、`pass.rs`、`passes/*` 基本是双份维护。
   - `daemon/src/passes/mod.rs:52-118` 和 `bpfopt-core/src/passes/mod.rs:52-118` 维持了同一份 pass registry。

2. Verifier/oracle 重复
   - `daemon/src/verifier_log.rs` 和 `bpfopt-core/src/verifier_log.rs` 是整份复制。
   - 这会导致 const-prop / map-inline 的 oracle 行为很容易双边漂移。

3. Profile / discovery / invalidation 重复
   - `bpfopt-suite/crates/bpfprof/src/profiler.rs` 是 `daemon/src/profiler.rs` 的近复制件。
   - `bpfopt-suite/crates/bpfget/src/kfunc_discovery.rs` 是 `daemon/src/kfunc_discovery.rs` 的逐字复制件。
   - `bpfopt-suite/crates/bpfrejit-daemon/src/invalidation.rs` 是 `daemon/src/invalidation.rs` 的近复制件。

4. Daemon command/server 重复
   - `bpfopt-suite/crates/bpfrejit-daemon/src/commands_ref.rs` 与 `daemon/src/commands.rs` 高度相似。
   - `bpfopt-suite/crates/bpfrejit-daemon/src/server_ref.rs` 与 `daemon/src/server.rs` 高度相似。
   - 但这些“ref”文件当前没有接进 `main.rs`，本质上是 stranded copies。

5. Syscall 层没有共享，只有“计划共享”
   - `bpfopt-suite/crates/kernel-sys/src/lib.rs:7-10` 还是 placeholder。
   - 真正的 syscall 层仍全量留在 `daemon/src/bpf.rs:1-1772+`。

### 6.3 最危险的问题不是“代码多”，而是“行为开始漂移”

现在已经能看到几处实质分叉：

- `map_info.rs`
  - `bpfopt-core` 版本改成从 `program.map_metadata` 读取。
  - `daemon` 版本仍然从 live kernel map info 读取。
  - 这是合理分叉，但如果继续双边改 bug，会非常难同步。

- `map_inline.rs`
  - `bpfopt-core` 版本改成从 `program.map_values` / `map_metadata` 读取。
  - `daemon` 版本仍然直接 `crate::bpf` 查 live map。
  - 这是抽象成功的一部分，但意味着现在两个版本不是同一份源。

- `server_ref.rs` / `commands_ref.rs`
  - 它们不是最终接线代码，也不是测试模块，只是复制在那里的“参考实现”。
  - 这种文件最容易变成误导性的死代码。

结论：当前最急需解决的不是“继续补 stub 工具”，而是“停止分叉，建立单一事实来源”。

## 7. 重构方案

## 7.1 目标形态

建议把现在的 `bpfopt-suite` 收缩并重命名为 `bpfopt/`，只保留纯优化层。

推荐结构：

```text
bpfopt/
  Cargo.toml
  crates/
    bpfopt/          # library，原 bpfopt-core 的纯净版
    bpfopt-cli/      # binary，输出可执行名仍叫 bpfopt
  tests/
    support/         # ELF fixture parser、mock maps、测试装配

daemon/
  Cargo.toml
  src/
    bpf.rs
    kfunc_discovery.rs
    profiler.rs
    invalidation.rs
    commands.rs
    server.rs
    main.rs
```

如果不想保留 workspace，也可以进一步压成单 crate：

```text
bpfopt/
  Cargo.toml
  src/lib.rs
  src/bin/bpfopt.rs
  tests/support/...
```

但无论哪种，原则都一样：`bpfopt` 目录里不能再有 `kernel-sys` / `bpfget` / `bpfverify` / `bpfprof` / `bpfrejit` / `bpfrejit-daemon` 这些 kernel-facing/daemon-facing crate。

## 7.2 `bpfopt`（纯优化层）应该包含什么

`bpfopt` 应该只包含：

- BPF bytecode IR
- instruction utilities
- analyses
- transform passes
- canonical pipeline ordering
- 纯数据 side-input 结构
  - target capability
  - profile snapshot
  - map snapshot
  - 可选的 abstract-state/oracle snapshot
- CLI front-end
  - 读 raw bytecode
  - 读 JSON side-input
  - 输出 raw bytecode
  - 输出 pass report

`bpfopt` 不应该包含：

- raw BPF syscall wrapper
- live kernel program enumeration
- live map lookup
- `perf_event_open`
- Unix socket server
- daemon request/response schema
- REJIT fd-array 组装
- verifier log capture / REJIT failure debug

## 7.3 daemon 应该如何依赖 `bpfopt`

daemon 应该直接依赖 library API，而不是依赖 CLI。

建议关系：

- `daemon` 负责：
  - `BPF_PROG_GET_ORIGINAL`
  - `BPF_PROG_LOAD` dry-run verify
  - `BPF_PROG_REJIT`
  - kinsn discovery
  - map snapshot 采集
  - profiling 采集
  - invalidation tracking
  - socket/server/protocol

- `bpfopt` 负责：
  - `Program` / `PassContext` / `PassManager`
  - `analyze()`
  - `run_pipeline()`
  - 每个 pass 的 rewrite 逻辑

daemon 的执行流程应变成：

1. 从内核取原始 bytecode、map IDs、prog_type。
2. 采集 target capabilities、profile、map snapshot。
3. 组装 `bpfopt::Program` 和 `bpfopt::Context`。
4. 调用 `bpfopt` library 跑 pass。
5. 在 daemon 里做每个 pass 的 dry-run verify / final REJIT。
6. 把结构化结果封成现有 server response。

关键点：daemon 是 orchestrator；`bpfopt` 是 transform engine。

## 7.4 如何消除代码重复

建议按“移动单一事实来源”而不是“再复制一次”来做。

### A. 直接移动到 `bpfopt`

- `daemon/src/analysis/*`
- `daemon/src/insn.rs`
- `daemon/src/passes/*`
- `daemon/src/passes/mod.rs`
- `daemon/src/pass.rs` 里的纯 IR / pipeline / analysis cache 部分

### B. 留在 daemon，不进入 `bpfopt`

- `daemon/src/bpf.rs`
- `daemon/src/kfunc_discovery.rs`
- `daemon/src/profiler.rs`
- `daemon/src/invalidation.rs`
- `daemon/src/server.rs`
- `daemon/src/commands.rs`

### C. 从当前 `bpfopt-core` 再切出去

- `verifier_log.rs`
  - 留在 daemon，或者单独做 `daemon-oracle` support module。
- `PassVerifyResult` / `run_with_verifier()`
  - 从 core 移出，放回 daemon orchestration 层。
- `required_btf_fds` / `target_btf_fds`
  - 从 core 改成更抽象的 `required_kinsn_targets`。
- `elf_parser.rs` / `mock_maps.rs` / `test_utils.rs`
  - 挪到 `tests/support` 或 dev-only support crate。

## 7.5 迁移步骤

建议按下面顺序做，能最小化风险：

1. 先收敛命名和 scope
   - 把 `bpfopt-suite/` 目录重命名为 `bpfopt/`。
   - 同时在 workspace/member 级别删掉非纯 pass crate。

2. 先做“减法”，不要先补 stub
   - 删除 `kernel-sys`、`bpfget`、`bpfverify`、`bpfprof`、`bpfrejit`、`bpfrejit-daemon` 这些成员。
   - 这些如果以后还需要，可以作为 `daemon/tools` 再出现，但不应该留在 `bpfopt`。

3. 纯化 `bpfopt-core`
   - 从 `pass.rs` 去掉 verify/rollback transport 逻辑。
   - 从 `BpfProgram` 去掉 `required_btf_fds`。
   - 从 `KinsnRegistry` 去掉 `target_btf_fds` 这类 REJIT transport 字段。
   - 把 `verifier_log.rs`、`elf_parser.rs`、`mock_maps.rs`、`test_utils.rs` 挪出 runtime library。

4. 重命名 crate
   - 把“纯库”重命名成最终名字，避免 `bpfopt-core` 这种过渡名长期保留。
   - CLI 可以变成 `bpfopt-cli` package，但 binary name 仍然叫 `bpfopt`。

5. 让 daemon 真正依赖 `bpfopt`
   - 在 `daemon/Cargo.toml` 加 path dependency。
   - 逐步删除 `daemon/src/analysis/*`、`pass.rs`、`passes/*` 的本地模块，改为用依赖库。

6. 把 daemon 的 verify orchestration 保留在 daemon
   - 现有 `daemon/src/commands.rs:533-740` 的 per-pass verify / final REJIT 流程保留。
   - 但它不再直接拥有 pass 实现，只负责“何时验证、何时回滚、何时 REJIT”。

7. 最后删 stranded copies
   - 删除 `bpfrejit-daemon/src/*_ref.rs`
   - 删除未接线的重复 `profiler.rs` / `kfunc_discovery.rs`
   - 删除 placeholder `kernel-sys`

## 8. 当前进度评估

需要把“已经做了多少”分成两个口径看：

### 8.1 如果只看“pass 代码是否抽出来了”

这个部分已经做了不少，大约可以说完成了第一阶段的大头：

- `bpfopt-core` 已经存在，且不是空壳。
- `bpfopt` CLI 已经能跑 pass pipeline。
- `map_inline` / `map_info` 已经改成 side-input 模式，不再直接依赖 live kernel map syscall。

就“纯 pass 逻辑抽离”这一个子目标看，我认为大约完成了 **60%~70%**。

### 8.2 如果看“最终目标：`bpfopt` 纯优化层 + daemon 依赖它”

这个部分还远没完成：

- `daemon` 还没有依赖 `bpfopt`。
- 复制代码还没有删。
- verifier / REJIT transport 还混在 `bpfopt-core`。
- 五个 kernel-facing tool crate 仍然只是 stub。
- `bpfrejit-daemon` 也没有变成真正薄壳。

就最终架构目标看，我认为当前只有 **约三分之一到四成**，还处于“中途态”。

## 9. 最后判断

最合理的下一步不是继续把 `bpfopt-suite` 补成完整六工具套件，而是：

1. 立即把它收缩成真正的 `bpfopt`。
2. 明确规定 `bpfopt` 只负责优化，不碰 verify/rejit/daemon/syscall。
3. 让 `daemon` 成为唯一的 kernel-facing / runtime-facing 控制面。
4. 让 `daemon` 依赖 `bpfopt`，然后删除所有重复源码。

现在仓库里最接近最终形态的部分，是 `bpfopt-core` 对 pass 逻辑的抽离；最偏离最终形态的部分，是“六工具 workspace”这层外壳本身。
