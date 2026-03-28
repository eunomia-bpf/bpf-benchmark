# BpfReJIT dynamic map inlining 的 correctness contract（2026-03-28）

本文只形式化当前代码实现出来的 contract，不替论文做额外扩张。实现依据主要来自：

- `daemon/src/analysis/map_info.rs`
- `daemon/src/passes/map_inline.rs`
- `daemon/src/passes/map_inline_tests.rs`
- `daemon/src/invalidation.rs`
- `daemon/src/commands.rs`
- `daemon/src/server.rs`

结论先行：当前实现不是“任意 mutable map 上都保持与 `bpf_map_lookup_elem()` 强等价”的机制；它是一个**条件成立时语义等价、条件失效后靠 periodic polling 触发 re-REJIT/rollback 的 speculative specialization**。这点必须在论文里讲清楚。

## 1. 支持的 map type 精确列表

### 1.1 支持 inline 的 map type

| map type | 是否支持 | 模式 | 说明 |
| --- | --- | --- | --- |
| `BPF_MAP_TYPE_ARRAY` (2) | 支持 | direct inline | 常量 key 且 `key < max_entries` 时，lookup/null-check/pointer setup 整段都可删掉。frozen 和 mutable 都可做，但 mutable 仅限 read-only site。 |
| `BPF_MAP_TYPE_PERCPU_ARRAY` (6) | 条件支持 | direct inline | 与 `ARRAY` 一样可以删掉 lookup pattern，但额外要求该 key 的所有 per-CPU slot 字节完全一致；否则拒绝 inline。 |
| `BPF_MAP_TYPE_HASH` (1) | 支持 | speculative inline | 只改写后续 fixed-offset scalar load，不删 helper call 和 null check。 |
| `BPF_MAP_TYPE_LRU_HASH` (9) | 支持 | speculative inline | 与 `HASH` 相同。 |

这里“direct inline”和“speculative inline”的区别是：

- `ARRAY`/`PERCPU_ARRAY`：当前实现允许把 `bpf_map_lookup_elem()` 调用本身删掉，因此运行时不再保留 hit/miss guard。
- `HASH`/`LRU_HASH`：当前实现必须保留 live helper call 和 null check，只把 `*(r0 + off)` 改成常量装载，因此它是带 guard 的 speculative constant substitution。

### 1.2 明确排除的 map type

当前 `MapInfo::supports_direct_value_access()` 明确只接受上面四类。以下类型被排除：

- `BPF_MAP_TYPE_PERCPU_HASH` (5)
- `BPF_MAP_TYPE_LRU_PERCPU_HASH` (10)
- `BPF_MAP_TYPE_PROG_ARRAY` (3)
- `BPF_MAP_TYPE_PERF_EVENT_ARRAY` (4)
- `BPF_MAP_TYPE_STACK_TRACE`
- `BPF_MAP_TYPE_CGROUP_STORAGE`
- `BPF_MAP_TYPE_RINGBUF`
- 其他不支持 userspace 直接按 key 读取 value bytes 的 map

每类排除原因如下：

- `PERCPU_HASH` / `LRU_PERCPU_HASH`：
  userspace lookup 看到的是“拼接后的 per-CPU blob”，而运行中的 BPF 程序语义只看当前 CPU slot。代码里没有像 `PERCPU_ARRAY` 那样做“全 slot 一致性”证明，因此不存在单一常量能够对所有 CPU 同时等价。
- `PROG_ARRAY` / `PERF_EVENT_ARRAY` / `RINGBUF` / `STACK_TRACE` / `CGROUP_STORAGE` 等：
  不满足 “supports direct value access” 这个前提，无法把 helper 返回的 value 解释成可安全复制的普通 bytes。

### 1.3 不是 map-type 级别禁止，但会在 site 级别被排除的情形

这几类常被 reviewer 问到，但它们不是“map type 不支持”，而是“该 call site 不满足前置条件”：

- `HASH` / `LRU_HASH` 的 dynamic key：不支持。key 必须在该 site 被恢复成常量字节串。
- 任意 map 上的 pointer escape / store-back：对 mutable map site 会被拒绝；对 direct removal 也会阻止删除 lookup pattern。
- `PERCPU_ARRAY` 的 mixed per-CPU values：不支持。只要某个 slot 不同，该 site 就直接跳过。

## 2. Speculative inline 的前置条件

### 2.1 value access pattern：只允许 direct value access

当前 pass 只接受 `r0` 返回的 value pointer 最终被用于：

- 固定偏移
- 标量宽度
- 只读 load

也就是：

- `*(u8 *)(r0 + const_off)`
- `*(u16 *)(r0 + const_off)`
- `*(u32 *)(r0 + const_off)`
- `*(u64 *)(r0 + const_off)`

若某次 load 越界，site 会被拒绝。value 可以比 8 字节大，但**每个被替换的使用点必须是 1/2/4/8 字节的 fixed-offset scalar load**。

### 2.2 r0 use classification 的精确规则

`classify_r0_uses_with_options()` 对 lookup 返回值做的是一个很保守的别名追踪。它接受的 use 只有三类：

1. `mov64` 形成的寄存器别名
2. 8-byte stack spill/reload 形成的临时别名
3. 从任一 live alias 发起的 `ldx_mem` 固定偏移标量 load

它把其余使用都归入 `other_uses`。会落入 `other_uses` 的典型情形包括：

- 把 value pointer 当 helper 参数传出去
- 把 value pointer 当 store 目标写回 map value
- 对 pointer 本身做进一步算术并参与其他运算
- 在 helper call 后别名不再可证明存活

helper call 的处理也分 map 类型：

- frozen `ARRAY` / frozen `PERCPU_ARRAY`：
  可跨任意 helper call 继续追踪，但只能通过 callee-saved 寄存器 `r6-r9` 或 8-byte stack spill/reload 保留别名。
- mutable `ARRAY` / mutable `PERCPU_ARRAY`：
  只允许跨只读 helper `bpf_ktime_get_ns()`；跨其他 helper 会把该 site 视作 pointer escape。
- `HASH` / `LRU_HASH`：
  不允许跨 helper 继续使用 inline 结果；测试里 `hash + readonly helper` 会被拒绝。

### 2.3 mutable site 的 writeback guard

当前 writeback guard 是**site-local**的，不是“整程序只要写过同一张 map 就全部禁掉”。

精确规则是：

- 若 `!info.frozen` 且该 site 的 `uses.other_uses` 非空，则拒绝 inline。
- 若同一程序的别处对同一张 mutable map 有写回，但当前 site 自己是纯 fixed-load read-only，则当前 site 仍可 inline。

因此，当前实现定义的是“按 lookup site 的读写模式判定”，而不是“按 map 全局可变性判定”。

### 2.4 lookup 后 null check 的要求

对 `HASH` / `LRU_HASH` 这类 speculative site，null guard 是硬前提。若 `null_check_pc.is_none()`，site 直接跳过。

被识别为 null guard 的形式只有：

- `if alias == 0 goto ...` (`JEQ`)
- `if alias != 0 goto ...` (`JNE`)

并且这个 null check 必须出现在任何 fixed load 或 other use 之前。classifier 只会接受“紧贴 lookup result use-region 开头”的 null check。

另外要区分两层语义：

- `HASH` / `LRU_HASH`：
  只要求存在可识别的 immediate null check，因为 helper/null-check 最终会被保留。
- `ARRAY` / `PERCPU_ARRAY`：
  只有在 key in-range 且 non-null path 窗口足够 trivial 时，pass 才会顺带删掉 null check；否则即便做了 constant substitution，也会保留原 lookup/null-check。

### 2.5 key 类型要求

当前实现接受两类 constant key：

1. 从栈上恢复出来的常量 key bytes
2. 从 `BPF_PSEUDO_MAP_VALUE` 指向的 frozen source map value 中切片得到的常量 key bytes

精确要求是：

- key 必须能恢复成完整的 `map.key_size` 字节串
- 若恢复出来的宽度小于 `key_size`，拒绝
- `ARRAY` / `PERCPU_ARRAY` 若想删除 lookup pattern，还要求 key 是 in-range 的：
  `key < max_entries`
- verifier-guided key extraction 目前只覆盖 `key_size <= 8`
- 但 backward scan / pseudo-map-value fallback 可处理更宽的 constant key；测试已经覆盖 20-byte hash key

因此，“HASH with dynamic key”准确表述应为：

- `HASH` map type 支持 inline
- 但**只有 constant-key lookup site** 支持 inline

## 3. Correctness invariant

### 3.1 形式化陈述

记：

- `P` 为原始程序
- `P'` 为 map-inline 后程序
- `s` 为某个被特化的 lookup site
- `dep(s) = (map_id, key, expected_value)` 为安装时记录到 tracker 的依赖

则当前实现声称的不是“无条件 `P == P'`”，而是下面这个**条件等价**：

> 对任一被 inline 的 site `s`，若从特化安装到该次执行期间，`dep(s)` 仍成立，并且该 site 满足第 2 节的静态 use-pattern 前提，则 `P'` 在该 site 上的观测结果与原始 `bpf_map_lookup_elem()` 语义等价。

更细一点：

- 对 `ARRAY`：
  若该 key 对应 value bytes 与 `expected_value` 相同，则删掉 helper/null-check 后得到的常量 load 与原语义等价。
- 对 `PERCPU_ARRAY`：
  若该 key 的完整 per-CPU blob 与安装时相同，且所有 CPU slot 仍然字节一致，则折叠后的单一常量值与任一 CPU 上的原始 lookup 结果等价。
- 对 `HASH` / `LRU_HASH`：
  helper call 和 null check 仍在运行时执行，所以 hit/miss 语义仍由 live map 决定；
  若此次执行走到 non-null path，则要求当前 value bytes 与 `expected_value` 相同，常量 load 才与原始 `*(r0 + off)` 等价。

### 3.2 什么条件下不再等价

以下任一条件成立时，原始语义与已安装的 specialized image 不再保证等价：

- tracked key 对应的 value bytes 被更新
- `HASH` / `LRU_HASH` 的 entry 被删除后又重新插入为不同值
- `PERCPU_ARRAY` 的任一 CPU slot 与其他 slot 不再一致
- 该 site 原本依赖的 key/value 假设失效，但下一次 invalidation tick 尚未发生
- invalidation 已检测到失效，但 re-REJIT 尚未成功完成

对于 reviewer 点名的几种情况，可逐条回答：

- value 被更新：
  不等价，直到下一次 polling 检测到并完成 re-REJIT/rollback。
- entry 被删除：
  对 `HASH` / `LRU_HASH`，若删除后 lookup 变成 miss，则由于 helper/null-check 仍保留，miss path 仍然正确；
  但若随后重新插入新值，在 polling 之前 non-null path 仍可能读到 stale constant。
- map resize：
  对当前支持的 `ARRAY` / `PERCPU_ARRAY` / `HASH` / `LRU_HASH`，实现并没有单独跟踪 metadata 变化；
  更准确地说，当前 contract 假设 `map_type/key_size/value_size/max_entries` 在 program 生命周期内不变。对这些标准 map type，这通常是内核 API 层面的既有约束，而不是 invalidation tracker 主动保证的。

### 3.3 并发安全与 per-CPU 语义

当前实现**不提供对并发 map update 的线性化语义**。它提供的是：

- 静态 side guard，防止把 pointer escape / writeback 这类明显不安全的 site 误 inline
- 动态 polling，最终发现 value 假设已经失效
- 成功后从原始 bytecode 重新特化或回滚

因此在并发更新下：

- `ARRAY` / `PERCPU_ARRAY`：
  由于 helper 已被删掉，运行中的程序会直接使用安装时常量；一旦值被并发更新，在下一次 poll 前该常量可能 stale。
- `HASH` / `LRU_HASH`：
  live helper 仍会在运行时决定 hit/miss，因此“是否 miss”这一层是动态的；
  但只要还是 hit，value contents 仍可能 stale，直到 poll 发现变更。

对 “BPF 程序在 per-CPU 上运行时，inline 的 value 是否 stale” 这个问题，答案必须写成：

- 只有 `PERCPU_ARRAY` 被支持
- 且只在“该 key 的所有 per-CPU slot 在安装时完全一致”时才允许 inline
- 若之后任一 CPU slot 改变，则 inline value 立即可能 stale；检测依赖下一次 polling

## 4. Invalidation 机制

### 4.1 检测方法

当前 invalidation 不是 version counter，也不是 hash compare。它是**按 `(map_fd, key)` 做精确 value compare**。

tracker 记录的依赖是：

- `prog_id`
- `map_fd`
- `key`
- `expected_value`

轮询时的逻辑是：

1. 按 `map_fd` 对所有 tracked key 去重分组
2. 对每个 `map_fd` 读出这些 key 的当前值
3. 做字节级相等比较
4. 若 `current_value != expected_value`，则该 `prog_id` 被标记 invalidated

这意味着：

- 没有使用 whole-map hash
- 没有使用 generation counter
- 没有 trap-on-access
- 当前生产实现里，`BpfMapValueReader` 也还不是内核 batch lookup syscall；它只是按 key 逐个调用 `BPF_MAP_LOOKUP_ELEM`
- 丢 entry 的情况会被检测到，因为 `None != Some(expected_value)`

对于 `PERCPU_ARRAY`，tracker 记录的是**完整 per-CPU blob**，不是 pass 内部折叠后的单槽值；因此只要任一 CPU slot 变化，compare 就会失败。

### 4.2 检测频率

在 `serve` 模式下，轮询频率是固定的：

- 每 `1s` 一次 `check_for_invalidations()`

即，当前实现的 invalidation latency 下界约为一个 polling period，而不是一次 map update 的同步 trap。

在一次性 `apply` / `dry-run` 路径里，没有独立的后台 polling 线程；只有 `serve` 模式会持续维护 invalidation。

### 4.3 发现失效后的动作

`server::process_invalidation_tick()` 发现某个 `prog_id` invalidated 后，不是直接 patch 增量，而是调用 `commands::try_apply_one(prog_id, ...)` 重新跑一遍完整 optimize/apply 流程。

关键点有两个：

1. `try_apply_one()` 总是从 `bpf_prog_get_info(..., fetch_orig=true)` 拿到的 `orig_insns` 出发
2. 然后重新运行全 pass pipeline，再做一次 `BPF_PROG_REJIT`

因此发现失效后的结果只有两种：

- 当前值仍满足 inline 条件：
  重新 specialized，安装新的常量
- 当前值已不满足 inline 条件：
  pipeline 不再改写该 site，最终用原始 bytecode 做一次 identity REJIT，相当于 rollback to original

所以当前实现的实际策略不是“只 rollback”，而是：

- **re-REJIT from original**
- 结果可能是新的 specialized image，也可能是原始 image

### 4.4 rollback 如何保证不留 stale assumption

这里要区分两层：

#### 4.4.1 编译状态层面

这一层相对干净：

- 每次 reopt 都从 `orig_insns` 开始，而不是在上一次 specialized image 上叠加 patch
- tracker 刷新时先收集新依赖，再在 mutex 保护下 `remove_prog(prog_id)` 并安装新依赖
- 若打开新 map FD 失败，`record_map_inline_records()` 会直接报错，旧 tracker entries 会被保留，不会出现“旧依赖先删掉、新依赖又没装上”的状态

所以从“优化器内部状态”看，stale assumption 不会跨代累积。

#### 4.4.2 运行时执行层面

这一层必须保守表述：

- `BPF_PROG_REJIT` 的程序镜像替换是原子的；成功时整张程序一次性切到新 image，失败时旧 image 保持不变
- 但 invalidation 触发不是原子的，而是 periodic polling
- 因此 map value 已经变了、但 poll 还没跑到时，旧 specialized image 仍可能执行
- 若 poll 已发现失效，但 re-REJIT 失败，旧 specialized image 也会继续留在内核里，直到下一次成功重试

所以当前实现能保证的是：

- **whole-program image swap 原子**
- **assumption set 代际刷新不叠加旧快照**

它不能保证的是：

- map update 发生后立即 stop-the-world rollback
- 在任意并发更新下零 stale window

## 5. 已知限制和边界条件

### 5.1 为什么 `PERCPU_HASH` / `LRU_PERCPU_HASH` 不支持

原因不是“代码里暂时没做”，而是 contract 本身就不自然：

- userspace 读取到的是完整 per-CPU blob
- BPF 程序执行时只看到当前 CPU slot
- 当前实现没有像 `PERCPU_ARRAY` 那样做“所有 slot 完全相同”的站点级证明

因此不存在一个跨 CPU 都等价的单一常量语义。

### 5.2 为什么 `HASH` / `LRU_HASH` 只能做 speculative，不像 `ARRAY` 那样 direct

因为 `HASH` family 的 lookup 成功性本身就是动态的：

- key 可能不存在
- key 可能被删除
- key 可能 later reinsert

所以当前实现必须保留：

- live `bpf_map_lookup_elem()` helper call
- live null check

它只能把“命中后从 value pointer 读字段”这一步改成常量。

`ARRAY` / `PERCPU_ARRAY` 不同。对 constant in-range key，lookup success 是静态可知的，因此 helper/null-check 才有机会整段删除。

### 5.3 并发 map update 的 race window

当前 contract 的核心边界就是这个 race window：

- map 在 `t_update` 时刻更新
- daemon 在下一次 `t_poll` 才发现
- 然后还要再等一次成功的 `BPF_PROG_REJIT`

因此 stale window 约为：

- `poll interval`（当前为 1s）
- 加上 reoptimization / REJIT 延迟

这与 JVM 的 deopt trap 明显不同，必须在论文里单独强调。

### 5.4 value 大小限制

当前没有“整张 value 最大只能 N 字节”的显式全局阈值，但有两个实际边界：

- 只有 1/2/4/8 字节的 fixed-offset scalar load 能被替换
- 每个被替换的 load 都必须落在当前读取到的 value blob 边界内

额外还有一个 key-size 边界：

- verifier-guided key extraction 只支持 `<= 8B` key
- 但普通 backward scan 允许更宽的 constant key；测试已覆盖 20B hash key

### 5.5 其他站点级安全边界

当前实现还会拒绝以下站点：

- key 不是常量 materialization
- 待删除的 lookup pattern 覆盖了 branch target
- 待删指令块不是紧凑 contiguous block
- null-check 的 non-null window 里有非 trivial side effect
- rewrite 彼此重叠

这些都属于“为了保证 rewrite 不破坏 CFG/指针语义”的保守 guard。

## 6. 与 JVM deoptimization 的类比

这个类比是成立的，但要说清楚是“弱化版”。

### 6.1 相似点

两者都做三件事：

1. 在某个运行时假设成立时做 speculative optimization
2. 记录该优化依赖的 assumption
3. assumption 失效后回到更保守的代码，再基于新状态重新优化

把这个框架套到 BpfReJIT 上就是：

- speculative optimization：
  把 map lookup 读出的字段替换成常量
- assumption：
  `(map_id, key, expected_value)` 仍然成立
- deopt / respecialize：
  invalidation polling 发现不等后，从 original bytecode 重新 REJIT

### 6.2 关键差异

与 HotSpot/J9 之类 JVM deopt 相比，当前 BpfReJIT 有三个本质差异：

- JVM 是 trap-on-access / trap-on-guard-failure
  BpfReJIT 是 periodic polling
- JVM 可以在当前执行点 deopt，并恢复解释器/基线状态
  BpfReJIT 只能做 whole-program image replacement，不能中途接管当前帧
- JVM 的 invalidation 往往与依赖对象的版本系统耦合
  BpfReJIT 当前只做 value compare，没有版本号，因此不能消除 polling 窗口

因此论文里最准确的表述不是“像 JVM 一样的 deoptimization”，而是：

> BpfReJIT 采用了 JVM 风格的 speculative optimization + deoptimization 设计思路，但当前实现的 deoptimization 触发机制是 userspace periodic polling，而不是 synchronous trap。它提供的是 eventual rollback / re-specialization，而不是对并发 map update 的零窗口强一致语义。

## 建议写进论文的一句话版 contract

可以把 contract 压成下面这句话：

> Dynamic map inlining in BpfReJIT is a conditional specialization: for `ARRAY`, `PERCPU_ARRAY`, `HASH`, and `LRU_HASH` maps, the rewritten code is semantically equivalent to the original `bpf_map_lookup_elem()` site only while the specialized `(map_id, key, value)` snapshot remains valid and the lookup result is used exclusively through fixed-offset scalar loads. `HASH`-family sites keep the live helper call and null guard; `ARRAY`-family sites may remove them when the key is statically in-range. Snapshot invalidation is detected by 1-second userspace polling and repaired by re-REJIT from the original bytecode, so concurrent map updates can create a bounded stale window before rollback/respecialization completes.
