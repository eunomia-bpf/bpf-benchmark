# Dynamic Map Inlining + Invalidation 设计报告（2026-03-24）

基于 `docs/kernel-jit-optimization-plan.md` 中 #423 的目标，以及已有机会分析 `docs/tmp/20260323/map_inlining_opportunity_analysis_20260323.md`，本文给出可落地的 daemon 侧实现设计。核心目标不是“把 map lookup 静态替换成常量”这么简单，而是做一个可失效、可回退、可重新特化的 runtime-guided specialization 机制。

## TL;DR

- 推荐的 v1 范围很窄：只做 `BPF_MAP_TYPE_ARRAY`、常量 key、固定 offset 标量 load、`watch/serve` 常驻模式，不支持一次性 `apply-all`。
- `bpf_stats` 只能做 hotness gating，不能检测 map 变化；真正的 invalidation substrate 首选 version counter，其次是精确 slot polling；`ring_buffer` 适合作为可选加速通道；当前 kernel UAPI 的 whole-map hash 只对 frozen map 可用，不适合动态 map。
- bytecode rewrite 必须从 `BPF_PROG_GET_ORIGINAL` 返回的原始字节码重建，而不是在上一次 specialized bytecode 上叠加修改；否则 invalidation 和 branch fixup 会越来越脆弱。
- null check 消除只能在“lookup 总是成功”时做。v1 里这基本等价于：`ARRAY` map + 常量 key + key `< max_entries`。`HASH/LRU_HASH/LPM` 一律不做。
- pass 位置应放在现有 peephole 之前：`dynamic_map_inline -> simplify_cfg/const_fold_cfg -> wide_mem -> rotate -> cond_select -> extract -> endian_fusion -> branch_flip`。
- break-even 在完整 REJIT 成本下仍然可行：按 `3-7ms verify + ~30us JIT` 估算，若单次 lookup 节省 `50-100ns`，一次 specialize 需要约 `3e4-1.4e5` 次命中回本；若经历一次 rollback 再 respecialize，则需要约 `6e4-2.8e5` 次命中回本。对 Katran/Cilium/Tetragon 这类低更新、高读取的 control-plane map，仍然成立。

## 1. 设计目标与推荐 v1 范围

### 1.1 目标

`docs/kernel-jit-optimization-plan.md` 已经明确把 #423 定义为“JVM deoptimization 模型”的动态 map inlining：当 map 在一段时间内稳定时，把当前值直接 inline 到 bytecode；当 map 被修改时，daemon 检测到假设失效，触发 rollback 或重新 specialize。

这和 #422 的 frozen map inlining 本质不同：

- #422 依赖 map 的永久只读属性。
- #423 依赖“暂时稳定”的运行时假设，必须配套 invalidation。

### 1.2 推荐 v1 范围

建议 v1 只支持下面这组条件同时成立的 call site：

1. map 类型是 `BPF_MAP_TYPE_ARRAY`。
2. key 是编译期常量，并且能从栈上 key materialization 精确恢复。
3. helper 返回值只被当作“定长标量字段容器”使用。
4. 所有使用都是 `*(u8/u16/u32/u64 *)(r0 + const_off)` 这种固定 offset load。
5. 这些 load 之后只参与标量比较、位测试、简单分支，不把 `r0` 当指针向外传播。
6. daemon 处于常驻模式，能够持续维护 invalidation 状态。

v1 明确不做：

- `HASH/LRU_HASH/LPM_TRIE`
- `PERCPU_*` map
- `map-in-map`、`prog_array`
- 含 kptr、socket、spin lock、timer 等内核对象的 value
- helper 返回值继续当指针传递给其他 helper / subprog 的场景
- 一次性 `apply-all`

原因很简单：#423 的难点不在“识别 lookup pattern”，而在“假设失效后系统还能保持正确”。先把动态失效链路做稳，比一开始追求广覆盖更重要。

## 2. Map 稳定性检测机制

### 2.1 机制对比

| 机制 | 能检测什么 | 精度 | 代价 | 需要工作负载配合吗 | 结论 |
|---|---|---|---|---|---|
| `bpf_stats` (`run_cnt` / `run_time_ns`) | 程序热度 | 只到 program 级 | 很低 | 否 | 只能做 hotness gating，不能做 invalidation |
| version counter | 指定 map / slot 是否变更 | 高 | 很低 | 通常需要 | v1 首选 |
| `ring_buffer` 事件 | 近实时 update 事件 | 高 | 低到中等 | 需要 workload 或 observer | 适合做可选 fast path |
| 周期性 hash 对比 | map 或 slot 内容变化 | 中等到高 | 中等 | 否 | whole-map hash 对动态 map 不现实；slot compare 可作为兜底 |

### 2.2 `bpf_stats` 的可行性

`daemon/src/profiler.rs` 当前只轮询 `bpf_prog_info.run_cnt` 和 `run_time_ns`。这非常适合回答两个问题：

- 哪些程序值得 optimize。
- 一个 specialized program 是否仍然足够 hot，值得继续维护。

但它回答不了：

- 哪张 map 变了。
- 变的是哪个 key。
- 当前 specialized 假设是否失效。

因此，`bpf_stats` 在 #423 里只能作为前置筛选条件：

- `if !hot(program) => 不 specialize`
- `if specialized && no longer hot => 可以延迟 respecialize`

它不是 invalidation 机制。

### 2.3 version 号方案

这是最强、最干净的方案。思路是把 map 内容变化显式编码成单调递增的 generation token。

可行形式有两种：

1. sidecar version map
   - 例如 Tracee 已经有大量 `*_version` map。
   - control plane 更新真实 map 时，同时 `version++`。
2. inline version field
   - 把 generation 放在同一个 value 结构体中。
   - daemon specialize 前后双读 version，确认快照一致。

优点：

- O(1) 检测。
- 不需要扫整张 map。
- 只要 token 单调递增，天然抗 ABA。
- 和 batch invalidation 非常兼容。

缺点：

- 需要 workload 已有 version substrate，或者愿意新增一个。
- 如果一个 map 内只有少数 slot 会被 inline，最好做到 slot-level version，而不是 whole-map version；否则 fanout 会过大。

结论：

- 若 workload 已有 version map，直接把它作为 primary invalidation source。
- 若没有，但 map 明显属于“配置面少改、数据面多读”，值得为它引入 version 机制。

### 2.4 `ring_buffer` 事件方案

`ring_buffer` 适合作为事件驱动的 invalidation 快路径，但不适合作为 v1 唯一依赖。

有两种落地方式：

1. workload cooperation
   - control plane 在每次 `map_update_elem` 成功后，额外写一条 `(map_id, key, generation)` 事件到 ringbuf。
   - daemon 订阅后立刻标脏。
2. observer BPF / tracing path
   - 额外挂一个观测器，追踪 map update/delete 路径并发事件。
   - 这会引入额外复杂度、内核版本耦合，以及 fd -> map_id / key 提取问题。

优点：

- 低延迟，适合秒级 heartbeat 一类的高频控制面更新。
- 可以把 polling interval 拉长，减少空转。

缺点：

- 需要额外 runtime 组件。
- 如果事件丢失，必须仍有 polling 兜底。
- 若通过 tracing 旁路实现，会偏离当前“daemon 零 libbpf、最小新机制”的路线。

结论：

- 把 ringbuf 视为 optional accelerator，而不是 correctness anchor。
- 正确性基线仍然要靠 version counter 或周期性 compare。

### 2.5 周期性 hash / compare 方案

这里必须区分两件事：

1. kernel UAPI 的 `bpf_map_info.hash`
2. userspace 自己做周期性 value compare

当前内核里，`vendor/linux-framework/kernel/bpf/syscall.c` 只在 `map->frozen` 时才允许通过 `bpf_map_get_info_by_fd()` 取 hash；否则直接 `-EPERM`。同时 `vendor/linux-framework/kernel/bpf/arraymap.c` 提供的 `array_map_get_hash()` 是对整个 array value 区做 SHA256。也就是说：

- whole-map hash 目前只对 frozen map 成立。
- 对动态 map，当前 UAPI 不能把 hash 当 invalidation 机制。

因此，对 mutable map 真正可行的只有：

- 周期性 `lookup(key)` 取回当前 value。
- 只比较被 specialization 依赖的 byte range。

这仍然有价值，尤其适合小 `ARRAY` map：

- Katran `ctl_array[0]`
- Cilium `runtime_config[slot]`
- Tetragon `tg_conf_map[0]` 某几个字段

但它有一个根本问题：ABA。

如果值经历了 `A -> B -> A`，单纯比较“当前值是否等于安装时快照”会误判“从未变化过”。所以：

- 没有 version token 时，compare 只能作为 best-effort 兜底。
- 需要在报告和实现里明确：纯 compare 模式不保证捕获 transient dirty window。

### 2.6 推荐方案

推荐一个分层策略：

1. `bpf_stats` 决定是否值得 specialize。
2. 优先使用 workload 提供的 version counter。
3. 没有 version 时，对精确依赖的 `(map_id, key, byte_range)` 做周期性 compare。
4. 若 workload 能提供 ringbuf 事件，则把它作为 fast invalidate 信号；后台仍保留低频 compare 兜底。

## 3. Invalidation 触发机制

### 3.1 依赖模型

v1 不应该把依赖建模成“program 依赖某张 map”，而应该建模成“program 依赖某个 map slot 的某些字节”。

建议数据结构：

```text
MapSlotKey = (map_id, key_bytes)
FieldRange = (value_off, width)

DepRecord {
  slot: MapSlotKey,
  ranges: [FieldRange...],
  install_generation: Option<u64>,
  install_value_bytes: Vec<u8>,
}

ProgramSpec {
  prog_id,
  orig_tag,
  specialized_tag,
  deps: Vec<DepRecord>,
  state,
}
```

然后建立一个 reverse index：

```text
(map_id, key_bytes) -> {prog_id...}
```

这样 Cilium 这类“同一张共享 config map 被很多程序读，但每个程序只关心少数 slot”的场景才可控。

### 3.2 轮询 vs 事件驱动

#### 轮询

优点：

- 与当前 `daemon/src/server.rs` 的 watch 模式最一致。
- 无需 workload 改造。
- correctness 简单。

缺点：

- 失效延迟取决于 poll interval。
- 若没有 version，只能比较当前值，存在 ABA 漏检。

#### 事件驱动

优点：

- 失效传播快。
- 对频繁但 bursty 的 control-plane update 更友好。

缺点：

- 需要额外事件源。
- 必须有 polling fallback。

推荐：

- v1 以 polling 为主。
- v2 再叠加 ringbuf/version event 作为 fast path。

### 3.3 Batch invalidation

当一个共享 config map 被多个 program specialize 之后，失效传播不能逐程序独立判断，否则 daemon 会抖动。

推荐流程：

1. 某个 `(map_id, key)` 被检测为 dirty。
2. 通过 reverse index 找到所有依赖它的 specialized program。
3. 把这些 program 都标成 `DirtyPendingRollback`。
4. 本轮只触发一次 rollback，恢复到 original bytecode。
5. 在一个 debounce / cooldown 窗口内合并后续 update。
6. quiet period 结束后，再按当前值统一 respecialize。

这样可以避免：

- map 连续更新导致每次都 REJIT。
- 多个依赖程序交错 rollback / respecialize。

### 3.4 推荐状态机

```text
Generic
  -> CandidateStable
  -> Specialized(version/value snapshot)
  -> DirtyPendingRollback
  -> GenericCoolingDown
  -> CandidateStable
```

状态说明：

- `Generic`: 原始程序，未做 map inlining。
- `CandidateStable`: 满足 hotness 和稳定窗口要求，准备 specialize。
- `Specialized`: 已安装 specialized bytecode，并记录 snapshot。
- `DirtyPendingRollback`: 检测到假设失效，但还没提交 rollback。
- `GenericCoolingDown`: 已回退为 generic，等待 map 安静下来，避免抖动。

### 3.5 Race 处理

specialize 前必须避免“读取快照后 map 立刻变化，但 specialized bytecode 仍被安装”的窗口。

推荐协议：

1. `token0 = read_generation_or_none(map, key)`
2. `val0 = lookup(map, key)`
3. `token1 = read_generation_or_none(map, key)`
4. 若 `token0 != token1`，放弃 specialize，等待下一轮。
5. 用 `val0` 生成 specialized bytecode。
6. `REJIT(new_prog)`
7. 记录 `install_token = token1` 和 `install_value = val0`

若没有 version token，只能退化为双读 value：

1. `val0 = lookup(map, key)`
2. 生成 specialized bytecode
3. `val1 = lookup(map, key)`
4. 若 `val0 != val1`，放弃安装

这能减少竞态，但不能解决 ABA。

## 4. Bytecode Rewrite 算法

### 4.1 识别目标 pattern

v1 目标 pattern 可以严格限定为下面这种局部形态：

```text
store const key bytes -> stack
r2 = fp - key_off
r1 = ldimm64 map pseudo
call bpf_map_lookup_elem
if r0 == 0 goto Lnull     ; 可选，但常见
rX = *(u8/u16/u32/u64 *)(r0 + const_off)
... use rX in compares/branches ...
```

识别时需要同时证明：

1. `call` 的 helper id 是 `bpf_map_lookup_elem`。
2. `r1` 来源是对应 map 的 `ldimm64` pseudo。
3. `r2` 指向的 key 字节完全由常量栈写组成。
4. helper 返回值 `r0` 只被固定 offset load 使用，不逃逸。
5. 删除 helper call 后，`r1-r5` 的 call-clobber 影响不会被后续代码观察到。

### 4.2 重写结果

对每个支持的 field load：

- `u8/u16/u32` 用 `MOV32 imm` 直接生成。
- `u64` 用 `ldimm64` 生成。

注意这里推荐“把字段值直接 materialize 为标量”，而不是尝试构造 `BPF_PSEUDO_MAP_VALUE` 指针：

- 动态 map 的 value 不是 verifier 认可的 immutable map value。
- 直接塞 pointer 会引入类型和生命周期问题。
- 我们的目标就是常量折叠，不是 map direct value addressing。

### 4.3 Null check 消除

只有在 lookup 必然成功时，`if r0 == 0` 才能安全删除。

对 v1，这要求：

1. map 是 `ARRAY`。
2. key 是常量。
3. `key < max_entries`。

原因来自内核实现本身：`vendor/linux-framework/kernel/bpf/arraymap.c` 的 `array_map_lookup_elem()` 只有在 index 越界时才返回 `NULL`。因此只要常量 key 在边界内，lookup 就是 total 的。

对 `HASH/LRU_HASH/LPM`，即使 key 当前存在，也不能把“本次 lookup 命中”推广成“将来必命中”。所以 v1 不做。

### 4.4 Branch folding

rewrite 之后通常会出现三类可删分支：

1. `if r0 == 0` 永远为假
2. `if inlined_const == imm` 可以常量求值
3. 依赖这个字段的后续分支 / return path 变成 unreachable

因此 `dynamic_map_inline` 后面必须紧跟一个 CFG 简化 pass，而不是把这个工作留给 verifier。推荐新增：

- `simplify_cfg`
- 或者 `const_fold_cfg`

它至少要做：

- 删除永远不可能跳转的条件分支
- 删除 unreachable block
- 修复 branch offset
- 清理无用的 key stack store / dead move

### 4.5 示例：Katran `ctl_array[0]`

典型原始形态：

```text
*(u32 *)(fp - 4) = 0
r2 = fp - 4
r1 = ldimm64 ctl_array
call map_lookup_elem
if r0 == 0 goto Lpass
r1 = *(u32 *)(r0 + 0)
if r1 == 0 goto Lpass
... second lookup and counter update ...
```

若当前 `ctl_array[0] == 0`，则 specialization 后可变成：

```text
r1 = 0
if r1 == 0 goto Lpass
... dead ...
```

再经过 `simplify_cfg`，整个函数可坍缩为：

```text
r0 = XDP_PASS
exit
```

这类 case 的真正收益往往不只是省掉一个 helper call，而是顺带删掉后续整条冷路径。

### 4.6 Bailout 条件

只要命中下面任一条件，就不做 rewrite：

- `r0` 被保存到栈上、传给 helper、传给 subprog、参与 pointer arithmetic
- key 不是常量
- 常量 key 越界
- 依赖的字段 load 不是固定 offset 标量 load
- helper call 之后有 live `r1-r5` 观察点，删除 call 会改变可见状态
- map 类型不在 allowlist
- map 可能被 BPF 程序自己写入，daemon 无法观测

## 5. Verifier 交互

### 5.1 类型变化

原始程序中：

- `map_lookup_elem` 的返回值是 `PTR_TO_MAP_VALUE_OR_NULL`

specialization 后：

- 原本从 `r0 + off` 读出的内容，变成普通 `SCALAR_VALUE`
- 若 `r0` 本身不再被用到，则可以完全删除 `r0` 相关路径

这意味着 verifier 视角下，specialized program 的类型系统其实更简单，而不是更复杂。

### 5.2 null check 要求

当前 verifier 对 `map_value_or_null` 的约束非常严格。内核 selftests 里已经有大量 `"invalid mem access 'map_value_or_null'"` 的失败用例。这说明：

- 在原始 `lookup` 路径中，若没有先证明非空，直接解引用会被拒绝。
- 因此 rewrite 不能“保留 pointer 语义但删掉 null check”。

正确做法只有两种：

1. 完全删除 pointer 语义，把 load 直接替换成常量标量。
2. 若无法证明 total lookup，则放弃该 site。

### 5.3 为什么 v1 必须限制在 `ARRAY`

`ARRAY` 的关键性质是：

- lookup 结果只取决于边界检查。
- 对常量 key，命中性可静态证明。

而 `HASH` 一类不具备这个性质：

- key 可能删除。
- 同一 key 的存在性随时间变化。
- nullability 是语义的一部分，不是“实现细节”。

因此 v1 若试图覆盖 hash map，要么保留双路径，要么引入更复杂的 guard/deopt stub，明显超出当前 daemon pass 的复杂度预算。

### 5.4 对 verifier 的实际依赖

本设计依赖 verifier 的地方只有两点：

1. `BPF_PROG_REJIT` 会对 specialized program 重新验证，保证安全。
2. 常量化之后 verifier 的寄存器状态更简单，不会因为 map pointer/nullability 产生额外拒绝。

本设计不应该依赖 verifier 替我们做物理 DCE。真正的 dead branch elimination 仍应由 daemon 自己的 `simplify_cfg` pass 完成。

## 6. Daemon Pass 设计

### 6.1 与现有 PassManager 的关系

当前默认 pipeline 在 `daemon/src/passes/mod.rs` 中是：

```text
wide_mem -> rotate -> cond_select -> extract -> endian_fusion -> branch_flip
```

而 `PassManager` 在 `daemon/src/pass.rs` 里对“任意 transform 后 analysis cache 全失效”这件事处理得很直接。这对新 pass 是好事，因为 dynamic map inlining 会大幅改变 CFG，重新算 analysis 是必要的。

### 6.2 推荐位置

推荐把新 pass 放在最前面，并在后面立刻接 CFG 简化：

```text
dynamic_map_inline
-> simplify_cfg
-> wide_mem
-> rotate
-> cond_select
-> extract
-> endian_fusion
-> branch_flip
```

理由：

- map inlining 最能创造常量和 unreachable block。
- 这些简化会让后续 peephole pass 看见更干净的代码。
- `branch_flip` 应继续放在最后，因为很多 branch 可能已经被删掉。

### 6.3 需要的新 analysis

现有 analysis 只有：

- `BranchTargetAnalysis`
- `CFGAnalysis`
- `LivenessAnalysis`

dynamic map inlining 至少还需要：

1. `MapLookupSiteAnalysis`
   - 找到 `map_lookup_elem` call site
   - 解析对应 map pseudo
2. `ConstKeyAnalysis`
   - 从 key stack store 里恢复常量 key 字节
3. `PointerUseAnalysis`
   - 判断 `r0` 是否只被固定 offset load 使用
4. `CallClobberSafetyAnalysis`
   - 删除 helper call 后，`r1-r5` 的语义变化是否可见
5. `DeadStoreAnalysis`
   - 删除 key materialization 后，哪些 stack store 可以清掉
6. `MapDependencyAnalysis`
   - 生成 `(map_id, key, byte_range)` 依赖记录，交给 runtime invalidation 层

其中 `LivenessAnalysis` 可以复用，但不够。

### 6.4 PassContext 扩展

当前 `PassContext` 只承载平台能力、kfunc registry、policy config。#423 需要把 runtime specialization 状态也显式挂进去。

建议新增：

```text
SpecializationContext {
  mode: GenericOnly | DynamicInline,
  snapshot_provider,
  dependency_index,
  invalidation_backend,
  policy: {
    min_hotness,
    min_stable_rounds,
    cooldown_rounds,
    allowed_maps,
    allowed_slots,
  }
}
```

这里的关键是区分两层：

- `dynamic_map_inline` pass 只负责“在给定 snapshot 的情况下改 bytecode”。
- `watch/serve` runtime controller 负责“何时提供 snapshot、何时回退、何时重新应用”。

不要把 invalidation 状态机直接塞进 pass 本身。

### 6.5 `watch/serve` 模式改造

当前 `daemon/src/server.rs` 的 watch 逻辑把“成功优化过的 program”放进 `optimized` 集合后就再也不看了。这和 #423 不兼容。

动态 map inlining 需要的不是“一次优化成功后永不再看”，而是：

- 允许同一个 prog 在 `generic <-> specialized` 之间反复切换
- 允许同一个 prog 随 map 值变化多次 respecialize
- 专门维护 dependency DB

因此推荐：

- `apply-all`: 不支持 `dynamic_map_inline`
- `watch/serve`: 支持，并内建 invalidation loop

### 6.6 与其他 pass 的交互

#### `wide_mem`

基本独立。map inlining 先删 helper path，再让 `wide_mem` 处理剩余的普通内存访问，更干净。

#### `rotate` / `cond_select` / `extract` / `endian_fusion`

这些 pass 在常量传播后通常只会受益，不会受损。

#### `branch_flip`

必须放最后。否则 dynamic map inlining 先删 branch，前面对 branch profile 的判断就白做了。

#### future `verifier-assisted const propagation` (#424)

二者是互补关系：

- `dynamic_map_inline` 利用 runtime map snapshot 造常量。
- #424 利用 verifier state 发现本来就能证明的常量。

长远看可以形成：

```text
dynamic_map_inline -> verifier_constprop -> simplify_cfg -> ...
```

## 7. Case Study 推演

### 7.1 Katran `ctl_array`

特点：

- `ARRAY` map
- key 常量，典型就是 `0`
- value 很小，直接作为 gate
- 更新极低频，通常是 startup / operator toggle

为什么适合：

- 命中 v1 所有前提
- null check 可直接删
- 常量化后能连带删掉后续 second lookup / cold path

失效策略：

- 轮询 `ctl_array[0]` 足够
- 若未来 Katran control plane 愿意维护一个 sidecar version，则进一步稳固

预期收益：

- 不只是省一次 lookup
- 更重要的是把整个 feature-disabled fast path 压成常量返回

### 7.2 Cilium `runtime_config`

特点：

- 共享 pinned config map
- 同一张 map 被多个 datapath 程序读
- 不同 slot 更新频率差异极大

关键结论：

- 不能做 whole-map specialization，只能做 slot-level specialization。
- 不能把所有 slot 都当 candidate，必须有 allowlist / denylist。

推荐分类：

- 适合 inline：`UTIME_OFFSET` 这类 startup / rare-change 槽位
- 不适合 inline：`AGENT_LIVENESS` 这类秒级 heartbeat 槽位，除非 workload 特别热且有强 version/event 支撑

失效策略：

- reverse index 必须按 `(map_id, slot)` 维护
- 最好引入 slot-level generation，而不是一改任意 slot 就使整张 runtime_config fanout invalidation

### 7.3 Tetragon `tg_conf_map`

特点：

- 明显属于低 churn config map
- 多个 program 会读同一个配置结构体里的少数字段
- 一些字段直接作为 enable/gate 或模式选择器

为什么适合：

- 很像 startup/environment discovery data
- 很多读取发生在事件热路径之前
- 一个字段一旦常量化，往往能触发分支剪枝

推荐策略：

- v1 只 inline 最常见的标量字段 load
- 对一个 `(map_id= tg_conf_map, key=0)` 可以记录多个 `FieldRange`
- invalidation 可以先用精确 value compare；若 control plane 愿意配合，再升级成 version-based

## 8. Break-even 模型

### 8.1 公式

令：

- `T_rejit = T_verify + T_jit`
- `Delta =` 单次 lookup 被省掉的时间
- `N_break_even = T_rejit / Delta`

按题设，`T_verify ≈ 3-7ms`，`T_jit ≈ 30us`，所以：

- 单次 specialize：`T_rejit ≈ 3.03-7.03ms`
- 一次 rollback + 一次 respecialize：`≈ 6.06-14.06ms`

### 8.2 单次 specialize 回本次数

| REJIT 成本 | 每次节省 `100ns` | 每次节省 `50ns` | 每次节省 `20ns` |
|---|---:|---:|---:|
| `3.03ms` | `30,300` | `60,600` | `151,500` |
| `7.03ms` | `70,300` | `140,600` | `351,500` |

### 8.3 一次 rollback + respecialize 的回本次数

| 总成本 | 每次节省 `100ns` | 每次节省 `50ns` | 每次节省 `20ns` |
|---|---:|---:|---:|
| `6.06ms` | `60,600` | `121,200` | `303,000` |
| `14.06ms` | `140,600` | `281,200` | `703,000` |

### 8.4 解释

这组数字看起来不低，但对目标 workload 仍然现实：

- Katran / Cilium datapath 的命中频率通常远高于 control-plane 更新频率。
- 动态 map inlining 常常不只是省 lookup 本身，还会删掉后续分支、第二个 lookup，实际 `Delta` 往往高于保守估计。
- 因此真正的问题不是“能不能回本”，而是“能否把 invalidation 做到足够稳，不因为抖动而把收益吃掉”。

## 9. 风险与限制

### 9.1 不能 inline 的 map 类型

v1 应明确排除：

- `HASH` / `LRU_HASH` / `LPM_TRIE`
- `PERCPU_ARRAY` / `PERCPU_HASH`
- `map-in-map`
- `prog_array`
- `ringbuf` / `queue` / `stack`
- `sockmap` / `sk_storage`
- 含 kptr / spin_lock / timer / 内核对象引用的 value

原因分别是：

- nullability 不是可静态消除的
- CPU 选择是运行时的一部分
- value 不是普通标量数据
- 或者 daemon 根本无法安全 snapshot / compare

### 9.2 ABA 问题

如果只靠“当前值是否等于安装时值”做 compare，会漏掉：

```text
A -> B -> A
```

这意味着 specialized 假设曾经失效过，但 daemon 没看到。对 correctness 来说这是不可接受的。

结论：

- 真正可靠的方案必须有单调 generation。
- 纯 compare 只能作为 best-effort fallback，并且只建议用于语义上接近 startup-only 的 map。

### 9.3 Race condition

即使有 version，仍然存在：

- 读取 value 与安装 specialized bytecode 之间的竞态

因此必须使用 `token_before / value / token_after` 协议。没有这个双读协议，dynamic inlining 只是在赌运气。

### 9.4 Shared-map fanout

Cilium 这类共享 config map 会让一个 update 同时影响很多 program。若只按 map 粒度追踪依赖，会导致过度 invalidation。

必须做到：

- slot-level dependency
- batch rollback
- cooldown / debounce

### 9.5 BPF-side writer

若 map 不仅被 userspace control plane 更新，还能被 BPF helper 在内核热路径中修改，而 daemon 又观测不到这些写，那么 specialization 就不可靠。

v1 应直接排除此类 map。

### 9.6 Daemon 重启

动态 specialize 依赖 daemon 维护的 dependency DB。若 daemon 重启而 specialized program 仍在运行，系统会失去 invalidation 能力。

可选策略有两个：

1. daemon 启动时先把所有由自己安装过的 specialized program 回滚到 original
2. 持久化 dependency DB，并在重启后恢复监控

v1 更建议选前者，简单且 fail-safe。

## 10. 推荐实现阶段

### Phase 1: 最小可用版本

- 仅支持 `ARRAY`
- 仅支持常量 key + 固定 offset 标量 load
- 仅支持 polling invalidation
- 仅在 `watch/serve` 模式启用
- 只从 `BPF_PROG_GET_ORIGINAL` 重建 specialized bytecode

这一步的目标是证明：

- rewrite 是正确的
- rollback / respecialize 状态机是稳定的
- Katran `ctl_array` / Tetragon `tg_conf_map` 这类 case 能跑通

### Phase 2: version-aware invalidation

- 接入 sidecar version map / inline generation field
- 把 compare fallback 降为次要路径
- 支持 slot-level generation

这一步主要解决 correctness 和 ABA。

### Phase 3: 事件驱动加速

- 接入 ringbuf invalidate event
- 在 polling 基线上做 fast path
- 处理 shared-map batch invalidation 的低延迟传播

### Phase 4: 扩展覆盖面

- 更复杂的 field-use pattern
- 多字段联合 specialize
- 与 #424 verifier-state constprop 联动

但这一阶段必须建立在前面三步已经把 invalidation 链路做稳的前提上。

## 结论

#423 的本质不是“再加一个 peephole pass”，而是把 daemon 从一次性 optimizer 扩展成一个带 deoptimization 能力的 specialization runtime。现有代码里已经有两个关键基础：

- `BPF_PROG_GET_ORIGINAL` 允许每次从原始 bytecode 重新生成 specialized 版本。
- `BPF_PROG_REJIT` 允许在 live program 上重新走标准 verify + JIT。

真正缺的是：

- 以 `(map_id, key, byte_range)` 为粒度的 dependency tracking
- version/polling/ringbuf 组合的 invalidation substrate
- 放在 pipeline 最前面的 `dynamic_map_inline + simplify_cfg`

如果只追求一个稳的 v1，最佳切入点就是：

- Katran `ctl_array`
- Tetragon `tg_conf_map`
- Cilium `runtime_config` 中的少数 rare-change slot

并且坚持两个原则：

1. 没有可靠 invalidation，就不要 specialize。
2. 没有 total lookup 证明，就不要删 null check。

