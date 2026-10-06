# Dynamic Map Invalidation 设计报告（2026-03-26）

本文只讨论 **Dynamic Map Inlining 的失效链路**，不重复展开已完成的 `MapInlinePass` 重写识别算法。目标是在当前 daemon 代码结构上，把“inline 当前 map 值”补全成一个完整的 deopt runtime：**inline -> monitor -> invalidate -> rollback/respecialize**。

## TL;DR

- `MapInlinePass` 现在已经会在 pass 执行时通过 `bpf_map_lookup_elem_by_id(map_id, key, value_size)` 读取 live map 值并生成常量替换；真正缺的是 daemon 侧的 **依赖登记、变化检测、回退和重特化**。
- v1 推荐方案是：**只在 `watch/serve` 常驻模式对 mutable map 启用 dynamic invalidation**；`apply`/`apply-all` 这类一次性命令仍只允许 frozen map inline。
- 依赖库的持久身份应使用 **`map_id + key`**，不是裸 `map_fd`。`map_fd` 只做运行时缓存，因为 fd 不能跨重启持久化。
- 变化检测 v1 用 **轮询**：按 `(map_id, key)` 去重后，周期性 `BPF_MAP_LOOKUP_ELEM`，比较 **安装时快照的 full-value hash**。默认间隔 `1000ms`。调度上按 map 分桶，syscall 仍是一 key 一 lookup。
- 失效动作 v1 选择 **rollback-first**：一旦发现脏值，先直接用 `orig_prog_insns` 回滚到原始字节码，再进入 cooldown，安静窗口后重新从原始字节码跑完整 `PassManager` 并用新值 `REJIT`。这比“立即直冲 respecialize”更安全。
- frozen map 不进入 dependency DB，也不进入轮询。当前代码里更可靠的检查点是 `MapInfo.frozen`，不是直接读某个 `map_flags` 位。
- daemon 重启后不能只靠 live state 重建依赖，因为内核 UAPI 不能反推出 `(map_id, key, value_hash)`。v1 应使用 **daemon-owned journal/state file** 持久化；恢复失败时保守回滚。
- 正确性保证是 **bounded staleness + eventual consistency**，不是线性一致性。轮询模式对 `A -> B -> A` 的 ABA 变化天然不完备，因此 **只适合性能优化 map，不适合安全/权限/策略 map**。

## 1. 当前代码的真实起点

从现有实现看，#474f 并不是“再加一个 pass”，而是给已有 pass 补一个 runtime controller：

1. `daemon/src/passes/map_inline.rs`
   `MapInlinePass` 已经会：
   - 找 `map_lookup_elem` site；
   - 解析常量 key；
   - 调 `bpf::bpf_map_lookup_elem_by_id()` 读 live value；
   - 把 `*(r0 + off)` 重写为 `MOV/LD_IMM64` 常量。

2. `daemon/src/commands.rs`
   `try_apply_one()` 每次都会从 `orig_insns` 重新构建 `BpfProgram`，再跑完整 pipeline，然后 `BPF_PROG_REJIT`。这意味着 **“从原始字节码重新特化”** 这条路已经天然存在，不需要另造一套 patch-specialized-bytecode 的机制。

3. `daemon/src/server.rs`
   当前 `cmd_watch()` 的语义是“新程序优化一次后就不再回访”，`cmd_serve()` 也没有后台 invalidation loop。这和 dynamic specialization 不兼容。

4. `daemon/src/analysis/map_info.rs`
   `MapInfoAnalysis` 已经返回 `MapInfo { frozen, map_id, ... }`。当前 `frozen` 是通过 `bpf_map_get_info_by_id()` 的 best-effort 冻结探测得到的。对本设计而言，这已经足够作为 “skip invalidation” 的判定输入。

## 2. v1 目标与非目标

### 2.1 目标

v1 要解决的是：

- 对已经 inline 进 bytecode 的 mutable map value 建依赖；
- 后台检测这些依赖是否失效；
- 失效时把程序恢复到正确语义；
- 值稳定后再重新特化；
- daemon 重启后尽量恢复监控，不把 specialized program 留在“无人看管”状态。

### 2.2 非目标

v1 不追求：

- 任意 map 类型都支持 dynamic invalidation；
- 事件驱动作为 correctness 基线；
- byte-range 精确失效；
- 安全/权限/策略 map 的零窗口一致性；
- 在一次性 `apply`/`apply-all` 模式支持 mutable map inline。

v1 的工程边界应当是：

- **frozen map**：永久 inline，无 invalidation。
- **mutable direct-value maps**：只在 `watch/serve` 托管模式下允许 inline，并配套 invalidation。
- **one-shot 命令**：只允许 frozen fast path。

## 3. 设计选择：为什么 v1 选 rollback-first

失效后有两种主要动作：

| 方案 | 正确性恢复 | 性能恢复 | REJIT 次数 | 风险 |
|---|---|---|---:|---|
| 直接从原始字节码 respecialize | 快，单次 REJIT | 快 | 1 | 若 snapshot 在优化窗口继续变化，容易再次装入陈旧值 |
| 先 rollback 到 original，再等 quiet period 后 respecialize | 快速恢复正确语义 | 慢一拍 | 2 | 逻辑最简单，失败时也停在正确的 generic 状态 |

v1 推荐：

- **dirty -> 立即 rollback 到 original**
- **cooldown / quiet period -> 再调用 `try_apply_one()` 做 respecialize**

理由：

1. 当前错误语义来自“程序里硬编码了旧常量”。发现 dirty 后，第一优先级是 **尽快恢复 generic 语义**，而不是尽快恢复最优性能。
2. `try_apply_one()` 已经天然是“从 `orig_insns` 重新跑 pipeline”的实现路径，适合做 respecialize。
3. rollback 不依赖新的稳定 snapshot；respecialize 依赖。两步拆开后，状态机更稳，失败处理更简单。

因此 v1 的核心状态机应为：

```text
Generic
  -> Optimizing
  -> Specialized
  -> DirtyPendingRollback
  -> CoolingDown
  -> Optimizing
```

补充状态：

- `NoOp`: 当前 pipeline 没有可用 site。
- `Failed`: 连续 REJIT/rollback 失败，进入退避。
- `Unloaded`: 程序已卸载，清理记录。

## 4. 依赖追踪数据结构

### 4.1 为什么不能只存 `(map_fd, key, hash)`

用户故事里说“记录 `(map_fd, key, inlined_value_hash)` tuple”，但在当前实现里：

- `MapInlinePass` 真正稳定的身份是 `map_id`；
- `map_fd` 每次 lookup 都是通过 `bpf_map_get_fd_by_id(map_id)` 临时打开；
- fd 不能跨 daemon 重启持久化。

因此设计上应当区分两层：

- **持久化层**：使用 `(map_id, key, value_hash)`；
- **运行时层**：额外缓存 `map_fd`，减少反复 open/close。

### 4.2 推荐 Rust 结构

```rust
type ProgKey = (u32 /* prog_id */, u64 /* load_time */);

#[derive(Clone, Debug, PartialEq, Eq, Hash, Serialize, Deserialize)]
struct TrackedMapSlot {
    map_id: u32,
    key: Vec<u8>,
}

#[derive(Clone, Debug, Serialize, Deserialize)]
struct DependencySnapshot {
    value_hash: u64,
    value_bytes: Vec<u8>,   // v1 保存 full value，避免只靠 hash
    value_size: u32,
    map_type: u32,
    frozen: bool,
    used_offsets: Vec<(u16, u8)>, // 预留；v1 可填 fixed-load ranges 或留空
}

#[derive(Clone, Debug, Serialize, Deserialize)]
struct ProgramDependency {
    slot: TrackedMapSlot,
    snapshot: DependencySnapshot,
}

#[derive(Clone, Debug, Serialize, Deserialize)]
enum ProgramState {
    Specialized,
    DirtyPendingRollback,
    CoolingDown { until_millis: u64 },
    NoOp,
    Failed { retries: u32 },
}

#[derive(Clone, Debug, Serialize, Deserialize)]
struct SpecializedProgramRecord {
    prog_id: u32,
    load_time: u64,
    prog_name: String,
    prog_type: u32,
    original_tag: [u8; 8],
    specialized_tag: [u8; 8],
    dependencies: Vec<ProgramDependency>,
    state: ProgramState,
    last_transition_millis: u64,
}

struct InliningDependencyDB {
    programs: HashMap<ProgKey, SpecializedProgramRecord>,
    reverse_index: HashMap<TrackedMapSlot, BTreeSet<ProgKey>>,
    map_fd_cache: HashMap<u32, OwnedFd>, // runtime only，不持久化
    in_flight: HashSet<ProgKey>,         // 防止同一程序并发 REJIT
}
```

### 4.3 为什么 v1 仍然保存 `value_bytes`

虽然需求里只要求 hash，但工程实现里建议 **同时保存 full value bytes**：

- v1 当前没有 digest crate，引入 `sha256/blake3` 纯为这件事不划算；
- 依赖 `u64` hash 作为快速比较即可，真正确认仍可回退到字节比较；
- map value 通常很小，这个内存开销可接受；
- 后续做持久化恢复和冲突诊断时，原始 bytes 很有用。

因此推荐：

- hash 作为轮询快路径；
- bytes 作为 collision-free 校验和持久化内容。

hash 算法方面，v1 用一个内置的稳定 64-bit 指纹即可，例如 FNV-1a。

### 4.4 反向索引为何必要

dynamic invalidation 的 fanout 不是“program -> map”，而是“**shared slot -> many programs**”。

因此必须有：

```text
(map_id, key) -> {prog1, prog2, prog3, ...}
```

这样一个共享配置 slot 变化时，poller 只需 lookup 一次，就能 fan out 到所有依赖程序。

## 5. 依赖如何从 `MapInlinePass` 流到 daemon runtime

### 5.1 必须记录“真正被 inline 的值”

`MapInlinePass` 当前是在 pass 内部直接 lookup map value。也就是说：

- pass 看见的值，才是被写进 specialized bytecode 的值；
- 如果等到 `try_apply_one()` 结束后再重新 lookup 生成依赖 hash，可能已经不是同一个值了。

因此设计上必须让 `MapInlinePass` 产出 artifact，而不是让 daemon 事后重新猜。

推荐新增一个 pass artifact：

```rust
struct MapInlineDependencyArtifact {
    map_id: u32,
    key: Vec<u8>,
    value_bytes: Vec<u8>,
    value_hash: u64,
    map_type: u32,
    frozen: bool,
    used_offsets: Vec<(u16, u8)>,
}
```

可以挂在：

- `PassResult` 的新字段；
- 或 `BpfProgram` 的 side metadata；
- 或 `PipelineResult` 的新 `artifacts` 字段。

推荐放在 `PassResult/PipelineResult`，因为它天然对应一次 pipeline 运行的产物。

### 5.2 安装前必须做二次校验

仅靠 pass 内部 lookup 还不够，因为 map 可能在“pass 读取值”和“REJIT 提交 specialized bytecode”之间变化。

因此 `try_apply_one()` 在 `bpf_prog_rejit()` 之前必须执行：

1. 汇总 `MapInlineDependencyArtifact`；
2. 以 `(map_id, key)` 去重；
3. 若同一个 slot 在同一轮 pipeline 中出现多个不同 `value_bytes`，判定为 **unstable snapshot**，直接放弃本轮 specialize；
4. 对每个去重后的 slot 再做一次 fresh lookup；
5. 若 fresh value 与 artifact 中的 `value_bytes` 不一致，直接放弃本轮 specialize。

这一步是 v1 的安装期 race 防线。

未来若引入 version token，应升级为：

```text
token_before
value
token_after
if token_before != token_after -> abort install
```

但 v1 没有 version token 时，至少要做“双读 value”。

### 5.3 注册时机

只有在下面条件同时成立时，依赖才真正进入 `InliningDependencyDB`：

1. pipeline changed；
2. 安装前重校验通过；
3. `BPF_PROG_REJIT` 成功；
4. dependency DB / state file 更新成功。

若第 4 步失败，不能把 mutable specialized program 留在运行中。正确做法是：

- 立即尝试 rollback 到 original；
- 对外把本次 optimize 视为失败。

原则很简单：**没有被 daemon 成功登记并接管的 mutable specialization，不能留在内核里运行。**

## 6. 变化检测机制

### 6.1 v1：轮询是 correctness anchor

v1 用轮询，默认配置：

- `--invalidation-interval-ms=1000`

轮询线程职责：

1. 从 `InliningDependencyDB` 拿出所有 mutable `TrackedMapSlot`；
2. 按 `map_id` 分桶；
3. 对每个 `map_id` 打开或复用 `map_fd`；
4. 对桶内每个唯一 `key` 调 `BPF_MAP_LOOKUP_ELEM`；
5. 计算 `value_hash`，必要时做 bytes compare；
6. 把脏 slot fan out 给依赖它的所有 program；
7. 触发 rollback。

### 6.2 Batch vs per-entry

推荐结论：

- **调度层面按 map 分桶 batch**
- **syscall 仍按 key 单独 lookup**

原因：

- 我们追踪的是 sparse key set，不是全表遍历；
- `BPF_MAP_LOOKUP_BATCH` 不适合“只查少数固定 key”这个模型；
- 按 map 分桶已经能减少重复 open fd 和重复 fanout。

因此 v1 poll plan 形态应当是：

```text
map_id = 101
  - key = [0,0,0,0]
  - key = [1,0,0,0]
map_id = 202
  - key = [7,0,0,0]
```

### 6.3 Poller 算法

```text
loop every interval_ms:
  snapshot = db.snapshot_unique_slots()
  dirty_slots = []

  for each map_id bucket in snapshot:
    fd = open_or_reuse(map_id)
    for each key in bucket:
      cur = lookup(fd, key)
      if lookup failed:
        dirty_slots += (map_id, key)
        continue
      if hash(cur) != installed_hash:
        dirty_slots += (map_id, key)
        continue
      if cur != installed_bytes:
        dirty_slots += (map_id, key)

  dirty_programs = reverse_index fanout(dirty_slots)
  for prog in dirty_programs:
    rollback_to_original(prog)
    move prog -> CoolingDown
```

### 6.4 map 删除 / 程序卸载的处理

需要显式处理两类对象失效：

1. 程序卸载
   - `bpf_prog_get_fd_by_id(prog_id)` 失败；
   - 或 `load_time/tag` 不再匹配。
   动作：从 DB 移除该程序和其 reverse index 项，不再重试。

2. map 打不开 / lookup 失败
   - 理论上程序仍持有 map 引用时这很少见；
   - 但从 daemon 角度应当把它当作 “依赖不可再验证”。
   动作：若程序仍在，触发 rollback；rollback 后移除该 dependency。

### 6.5 v2：事件驱动只做 accelerator

v2 可以叠加：

- workload cooperation 的 ringbuf/perf event；
- 或 sidecar version map；
- 或 inline generation field。

但它们的角色应当是：

- **快速把 slot 标脏**
- **降低平均失效延迟**

而不是取代 polling correctness baseline。原因是：

- 事件可能丢；
- ringbuf 需要额外组件；
- 只有 version token 才能真正解决 ABA。

## 7. 失效动作与重特化流程

### 7.1 rollback helper

为了让 invalidation 路径不重复走完整 pipeline，建议新增一个专用 helper，例如：

```rust
fn try_restore_original(prog_id: u32, ctx: &PassContext) -> Result<()>
```

其内部流程应为：

1. `bpf_prog_get_fd_by_id(prog_id)`
2. `bpf_prog_get_info(fd, fetch_orig = true)` 取 `orig_insns`
3. `bpf_prog_get_map_ids(fd)` 做 map fd relocation
4. `bpf_prog_rejit(fd, orig_insns, fd_array = [])`

它不跑优化 pass，只做“恢复原始程序”。

### 7.2 dirty 后的状态转移

推荐转移：

```text
Specialized
  -> DirtyPendingRollback
  -> rollback_to_original()
  -> CoolingDown(until = now + invalidation_interval_ms)
  -> try_apply_one()
  -> Specialized / NoOp / Failed
```

细节：

- rollback 成功后，要把该 program 从 `reverse_index` 的活跃依赖里移除，因为 generic 程序已不再依赖内联常量；
- `CoolingDown` 只保留程序级状态，不再继续轮询旧 dependency；
- cooldown 默认就用一个 `invalidation_interval_ms`，v1 不再额外引入新 CLI。

### 7.3 为什么 respecialize 仍走 `try_apply_one()`

因为 `try_apply_one()` 现在已经具备：

- 从 `orig_insns` 重新构建 `BpfProgram`；
- 跑完整 `PassManager`；
- 执行 verifier-guided rollback；
- 完成 map fd relocation；
- 调 `BPF_PROG_REJIT`。

dynamic invalidation 不需要另造第二套“重新优化”入口，只需要：

- 在 `try_apply_one()` 外围加 dependency artifact / 安装前重校验；
- 在 `watch/serve` runtime 里决定何时调用它。

## 8. `serve/watch` 集成方案

### 8.1 新的 runtime config

建议在 `main.rs` 顶层 CLI 增加：

```text
--invalidation-interval-ms <u64>   # default 1000
```

它对不同命令的语义：

- `serve`：后台 invalidation poller 的轮询周期；
- `watch`：后台 invalidation poller 的轮询周期；
- `apply`/`apply-all`/`rewrite`/`enumerate`：解析但不生效。

`watch --interval` 继续保留为“发现/热度排序轮次”的秒级周期；两者含义不同，不能复用。

### 8.2 runtime mode 必须显式区分

建议在 `PassContext` / `PolicyConfig` 里新增类似：

```rust
enum MapInlineRuntimeMode {
    FrozenOnly,
    ManagedDynamic,
}
```

语义：

- `FrozenOnly`
  - one-shot 命令使用；
  - mutable map 不允许 inline。
- `ManagedDynamic`
  - `watch/serve` 使用；
  - mutable map 允许 inline，但必须产生 dependency artifact 并被 runtime 托管。

这能避免 `apply-all` 把 mutable 值写进 bytecode 后无人监控。

### 8.3 `cmd_serve`

`cmd_serve()` 应在启动时创建：

```rust
struct DaemonRuntime {
    db: Arc<Mutex<InliningDependencyDB>>,
    interval_ms: u64,
    // ctx/pass_names/pgo_config/rollback_enabled 供后台 respecialize 使用
}
```

并启动一个后台线程：

- poll dependencies；
- rollback dirty programs；
- 在 cooldown 到期后自动 respecialize。

`process_request("optimize")` 的流程应改为：

1. 调 `try_apply_one()`；
2. 若结果里只有 frozen dependencies，直接返回；
3. 若结果里有 mutable dependencies，注册到 `DaemonRuntime`；
4. 注册和持久化成功后再返回成功响应；
5. 注册失败则立即 rollback，并返回错误。

### 8.4 `cmd_watch`

`cmd_watch()` 当前用 `optimized/no_op/fail_count` 三个集合表达状态，这对 dynamic invalidation 太粗。

建议改为：

- 前台 discovery loop：
  - 继续扫描 live prog IDs；
  - 对 `Generic / CoolingDown 已到期 / Failed 退避结束` 的程序决定是否 `try_apply_one()`；
  - hotness ranking 保留。
- 后台 invalidation loop：
  - 只监控 `Specialized` 程序；
  - 检测 dirty 并 rollback。

因此 `optimized` 集合应被 `ProgramState` 表替代，而不是继续“一次成功后永不再看”。

### 8.5 并发控制

`serve` 的客户端请求和后台 poller 都可能试图操作同一个 program，必须防止并发 REJIT。

最简单的工程做法是：

- `InliningDependencyDB` 里维护 `in_flight: HashSet<ProgKey>`；
- 任意 optimize / rollback / respecialize 之前先 `claim_program(prog)`；
- 操作结束后 `release_program(prog)`；
- 已经 in-flight 的程序，本轮 poll 或外部 optimize 请求都跳过或返回 `busy`。

否则会出现：

- poller 刚准备 rollback，客户端同时又发 `optimize`；
- 两次 `BPF_PROG_REJIT` 交错，状态文件和 reverse index 都会乱。

## 9. Frozen map 特殊路径

### 9.1 判定来源

这里需要纠正一个实现细节：

- `BPF_MAP_FREEZE` 在当前代码里不是一个直接从 `map_flags` 读取的稳定位；
- `daemon/src/bpf.rs` 目前通过 `bpf_map_get_info_by_id()` 的冻结探测得到 `frozen: bool`；
- `MapInfoAnalysis` 再把这个布尔值放进 `MapInfo`。

因此 v1 设计里应当使用 **`MapInfo.frozen`** 作为判定输入，而不是假设有一个现成的 `map_flags & FROZEN_BIT`。

如果后续内核 UAPI 暴露显式 frozen flag，可以在 `MapInfoAnalysis` 内部切换实现，但上层接口不需要变。

### 9.2 frozen maps 的行为

若 dependency 的 `frozen == true`：

- 允许在任意命令模式 inline；
- 不进入 dependency DB；
- 不进入轮询；
- 不受 restart recovery 影响。

也就是说，dynamic invalidation runtime 只服务 mutable maps。

## 10. 持久化与 daemon 重启恢复

### 10.1 为什么不能只靠 live state 重建

当前内核 UAPI 能给 daemon 的只有：

- current `bpf_prog_info`；
- `orig_prog_insns`；
- `map_ids`；
- 当前 program tag。

它 **不能** 反推出：

- 哪些 site 被 map_inline 命中过；
- 每个 site 用的是哪个 key；
- 安装时 inline 的 value hash 是什么。

因此：

- **不能只靠 live state 重建 dependency DB**；
- v1 必须有 daemon-owned state file / journal。

### 10.2 推荐：append-only journal

推荐把状态文件放在 `/var/run` 同级 runtime 目录，例如：

```text
/var/run/bpfrejit-invalidation.jsonl
```

理由：

- program ID / load_time 的生命周期本来就是当前 boot；
- `/var/run` 对 daemon restart 足够；
- 和 `serve` 默认 socket 路径一致。

日志记录类型建议为：

```text
prepare_specialize
commit_specialize
commit_rollback
drop_program
```

### 10.3 两阶段持久化协议

为了避免 “REJIT 成功但 state file 还没写成功，daemon 就崩了” 这个窗口，推荐：

1. 写 `prepare_specialize`
2. `fsync`
3. 执行 specialized `REJIT`
4. 更新内存 DB
5. 写 `commit_specialize`
6. `fsync`

回滚时同理：

1. 执行 rollback
2. 更新内存 DB
3. 写 `commit_rollback`

启动恢复逻辑：

1. replay journal；
2. 对每个 `commit_specialize` 记录，检查 `prog_id + load_time + specialized_tag` 是否仍匹配 live program；
3. 匹配则恢复 `Specialized` 监控；
4. 若只看到 `prepare_specialize` 没看到 `commit_specialize`，说明 crash 发生在不确定窗口，保守做法是 **尝试 rollback**；
5. 不匹配的旧记录直接丢弃。

### 10.4 恢复失败时的原则

恢复失败分两种：

1. journal 存在，但 replay 不一致
   - 保守 rollback。
2. journal 完全缺失或损坏
   - daemon 无法知道哪些 mutable specializations 还活着。

第二种是 v1 的运维限制。设计上应明确：

- dynamic invalidation 的安全恢复依赖 daemon 的 runtime state file；
- state file 丢失属于运维故障；
- 推荐把 daemon 以 systemd `RuntimeDirectory=` 管理，避免随意清理 `/var/run` 子文件。

## 11. 测试计划

### 11.1 daemon 单元测试

建议补在 `daemon/src` 的 Rust tests 中：

1. dependency DB CRUD
   - 注册 program；
   - reverse index 去重；
   - shared slot fanout；
   - rollback 后依赖移除。

2. 变化检测逻辑
   - 当前值未变，不标脏；
   - hash 变化，标脏；
   - hash 相同但 bytes 不同，仍标脏；
   - lookup 失败，标脏。

3. frozen map skip
   - frozen dependency 不进入 DB；
   - poller 完全忽略 frozen 记录。

4. 安装前重校验
   - `MapInlinePass` artifact 与第二次 lookup 不一致时，`try_apply_one()` 放弃 specialize；
   - 同一轮 pipeline 内同 slot 出现两个不同 snapshot 时，判定 unstable。

5. restart replay
   - journal replay 后恢复 `Specialized`；
   - `prepare_specialize` 未 commit 时走 rollback。

### 11.2 integration test 概念

集成测试应放在 repo-owned `tests/` 下，通过 `tests/*/Makefile` 接入 VM，不在 host kernel 上跑。

建议新建一个类似：

```text
tests/dynamic_map_invalidation/
```

测试流程：

1. 在 VM 中加载一个最小 ARRAY-map BPF 程序：
   - 程序读取 `ctl_array[0]`；
   - 根据值返回不同 retval。
2. 启动 `bpfrejit-daemon watch/serve --invalidation-interval-ms=100`。
3. 触发 optimize，确认程序被 specialized。
4. 更新 `ctl_array[0]` 的值。
5. 等待 poller 检测并 rollback。
6. 通过 `BPF_PROG_TEST_RUN` 或测试 harness 验证程序语义已恢复到新 map 值对应的行为。
7. 再等待 cooldown，验证程序能再次 respecialize。

这条测试要覆盖三件事：

- 检测到变化；
- 正确 rollback；
- 稳定后能重新 REJIT。

## 12. 正确性保证与限制

### 12.1 安装期保证

通过 “pass snapshot + 安装前二次 lookup 校验”，v1 可以保证：

- specialized program 不会因为 pass 内部读到的值和提交前值不同而立即过期。

但没有 version token 时，这仍然不是 ABA-safe。

### 12.2 运行期保证

在 polling v1 下，map 更新后的 stale window 上界近似为：

```text
staleness <= invalidation_interval_ms
          + poll scheduling jitter
          + rollback REJIT latency
```

按当前默认值和旧设计中的经验数值估算：

- `1000ms` 轮询；
- `~3-7ms` verify；
- `~30us` JIT；

则常见情况下 stale window 大约是 **1.00s 量级 + 少量抖动**。

注意：

- `cooldown` 只影响“多久重新获得性能收益”；
- **不影响** “多久恢复正确 generic 语义”，因为 rollback 在检测到 dirty 后立刻发生。

### 12.3 ABA 与 eventual consistency

轮询 + 当前值 compare 的根本限制是：

```text
A -> B -> A
```

若整个变化发生在两个 poll 间隔之间，v1 可能完全看不到。

因此必须在文档和实现注释里明确：

- v1 只提供 **eventual consistency**，不是强一致；
- 它适合 **性能优化**；
- 它 **不适合** 安全开关、权限位、策略判定、审计语义这类不能容忍瞬时陈旧值的 map。

要真正解决 ABA，必须上 version/generation token。

### 12.4 BPF-side writer 限制

若 map 还会被 BPF helper 在内核热路径更新，而 daemon 又不能稳定观察这些写：

- specialization 不可靠；
- v1 应直接禁止对此类 map 启用 mutable inline。

这可以通过 allowlist / map-type filter / workload annotation 在 policy 层表达。

## 13. 建议的落地顺序

1. `MapInlinePass` 产出 dependency artifact，`try_apply_one()` 增加安装前重校验。
2. 引入 `MapInlineRuntimeMode`，把 one-shot 和 managed-daemon 模式分开；frozen map 继续无条件支持。
3. 实现 `InliningDependencyDB`、reverse index、per-program in-flight lease。
4. 增加 `try_restore_original()`，把 dirty -> rollback 路径走通。
5. `cmd_serve` / `cmd_watch` 启动后台 poller，并在 optimize 成功后注册 dependency。
6. 落地 `/var/run/...jsonl` journal 和 restart replay。
7. 再做 v2：version token、ringbuf fast invalidate、byte-range precise invalidation。

## 结论

Dynamic Map Invalidation 在当前树上的最佳实现方式，不是去修改 `MapInlinePass` 的核心重写逻辑，而是把 daemon 从“一次性 optimizer”扩展成一个小型 specialization runtime：

- pass 负责产出“我依赖了哪些 `(map_id, key, value)`”；
- `try_apply_one()` 负责安装前重校验和 specialized `REJIT`；
- `watch/serve` runtime 负责持久化、轮询、rollback 和 respecialize。

v1 的关键取舍是：

1. **mutable map 只在托管模式启用**；
2. **变化后先 rollback，再 respecialize**；
3. **依赖持久化用 journal，不靠 live state 猜**；
4. **frozen map 直接跳过 invalidation**；
5. **接受 bounded staleness，但明确不把它用于安全语义。**

这条路径和当前代码结构最匹配，也最容易先把 #474f 做稳。
