# `map_inline` 不必要保守限制 review（2026-03-28）

## 结论先行

先给结论，避免把几类限制混在一起：

1. 当前实现**并不要求 key 必须是 4 字节**。站点级 value rewrite 已经支持按 `map.key_size` 提取更宽 key，测试覆盖了 **20-byte HASH key**。
2. 当前实现**并不要求 `map_fd ldimm64 -> key setup -> lookup` 必须连续**才能做 inline。这个“连续块”要求只影响“把整个 lookup pattern 一起删掉”，不影响“把后续 `LDX_MEM` 改成常量”。
3. 当前实现**确实要求 key bytes 在 inline 时必须已知且 site-invariant**。这一点对“无 guard 的全消除”是必要条件；如果想支持 dynamic key，已经不是“放宽一个 if”了，而是要改成“带 runtime key guard / 多版本 / hot-key fallback”的新 specialization 形态。
4. 当前实现所谓“纯标量 load 限制”里，**对 loaded scalar 的后续算术/比较/存储并不保守**；真正保守的是 pointer alias/use classifier 本身：只接受 fixed-offset `LDX_MEM`、只做线性 use-region 扫描、helper whitelist 很窄、HASH 不能跨 readonly helper。
5. 当前 mutable guard **已经是 site-local，不是 per-map / per-program 全局 veto**。用户担心的“同一张 map 在程序别处有写，就把只读 site 也杀掉”在当前代码里已经不是事实。
6. map type 上，`PERCPU_ARRAY` **已经支持**（条件是所有 CPU slot 的 bytes 完全一致）；`PERCPU_HASH` / `LRU_PERCPU_HASH` 我认为是**保守但可放宽**；`ARRAY_OF_MAPS` / `HASH_OF_MAPS` 则**不是当前 pass 形态下的简单放宽点**，需要另一类 specialization。

如果目标是“扩大 HASH map 全消除覆盖范围”，我建议的优先级是：

1. 放宽“全消除专用”的 setup/remove bookkeeping，而不是重做 constant-key 语义。
2. 放宽 `r0` use classifier 的 helper/CFG 保守性。
3. 只有在愿意接受“带 runtime guard 的特化”后，才去碰 dynamic key。

## 证据与基线

本次 review 直接阅读了：

- `daemon/src/passes/map_inline.rs`
- `daemon/src/passes/map_inline_tests.rs`
- `daemon/src/analysis/map_info.rs`
- `daemon/src/commands.rs`
- `daemon/src/invalidation.rs`
- `daemon/src/server.rs`
- `daemon/src/bpf.rs`

另外，我用 `2026-03-28` 最新一批 e2e metadata 做了一个现实基线汇总，文件为：

- `e2e/results/bcc_20260328_220000/metadata.json`
- `e2e/results/bpftrace_20260328_215036/metadata.json`
- `e2e/results/katran_20260328_223121/metadata.json`
- `e2e/results/scx_20260328_215808/metadata.json`
- `e2e/results/tetragon_20260328_214746/metadata.json`
- `e2e/results/tracee_20260328_213806/metadata.json`

汇总结果：

- `map_inline` pass instance: `56`
- `sites_applied`: `249`
- `sites_skipped`: `333`

和本次 6 个限制最相关的 skip reason 计数：

| skip reason | 计数 |
| --- | ---: |
| `lookup key is not a constant stack or pseudo-map-value materialization` | 134 |
| `mutable lookup result has non-load uses` | 77 |
| `lookup result is not consumed by fixed-offset scalar loads` | 67 |
| `PERCPU_ARRAY value differs across CPUs for 19 slot(s)` | 19 |
| `map type 13 not inlineable in v1` | 16 |
| `map type 12 not inlineable in v1` | 6 |
| `map type 5 not inlineable in v1` | 5 |
| `map type 10 not inlineable in v1` | 4 |

这组数说明：

- 目前最大的真实 blocker 仍然是 **constant key**。
- 第二梯队是 **use classifier / mutable-site alias 保守性**。
- `PERCPU_HASH` / `LRU_PERCPU_HASH` 和 `ARRAY_OF_MAPS` / `HASH_OF_MAPS` 在真实 workload 里也确实出现了。
- “key 必须 4B”不是主要瓶颈，至少不是今天代码的主要瓶颈。

## 1. Key 宽度限制

### 代码位置

- `daemon/src/passes/map_inline.rs:161-190`
  - `try_extract_constant_key_sized()` 按 `info.key_size` 提取 key。
- `daemon/src/passes/map_inline.rs:192-277`
  - `try_extract_constant_key_from_map_value()` 也按 `info.key_size` 切片。
- `daemon/src/passes/map_inline.rs:279-343`
  - `try_extract_constant_key_verifier_guided()`。
- `daemon/src/passes/map_inline.rs:291-295`
  - verifier-guided 路径明确限制 `key_size > 8` 时直接失败。
- `daemon/src/passes/map_inline.rs:41-50`
  - `ConstantKey` 只记录一个 `store_pc` 和一个 `source_imm_pc`。
- `daemon/src/passes/map_inline.rs:432-506`
  - `find_constant_stack_bytes_with_limit()` 虽然能拼接多条栈写恢复更宽 key，但最后只返回一个 `latest_store_pc`。
- `daemon/src/passes/map_inline.rs:1256-1269`
  - 构造 `lookup_pattern_pcs` 时只加入 `key.store_pc` / `key.source_imm_pc`，不会把“组成宽 key 的所有 store pc”都加入。
- `daemon/src/passes/map_inline_tests.rs:1134-1172`
  - `map_inline_pass_rewrites_hash_lookup_with_pseudo_map_value_20_byte_key()`。
- `daemon/src/passes/map_inline_tests.rs:1328-1384`
  - `map_inline_pass_rewrites_hash_lookup_with_20_byte_constant_key()`。

### 现状判断

“当前要求 key 是 4 字节”这个判断，**对当前代码已经不成立**。

当前实现实际是：

- backward scan / pseudo-map-value fallback 支持按 `map.key_size` 恢复完整 key bytes。
- 20-byte HASH key 已经有单测覆盖，并且可以成功做 site-inline。
- 真正还残留的宽 key 偏置，不在“能不能 inline”，而在“能不能把整段 lookup pattern 一起删掉”。

### 哪些地方是必要的，哪些是多余保守

必要的部分：

- `key.width < info.key_size` 时拒绝，`daemon/src/passes/map_inline.rs:825-831`。
  - 这是 correctness 必要条件，因为当前 rewrite 直接拿完整 key bytes 去做 live lookup/read expected value。

不必要保守的部分：

1. `verifier-guided` 只支持 `<= 8B`。
   - 代码位置：`daemon/src/passes/map_inline.rs:291-295`。
   - 这不是语义需要，只是因为当前 `verifier_guided_stack_store_value()` 用 `u64` 临时容器承载已知值，`daemon/src/passes/map_inline.rs:591-628`。
   - 只要把 verifier-guided 路径改成“返回 `Vec<u8>` 而不是 `u64`”，这条限制就能去掉。

2. 宽 key 的“组成 store pc 集合”没有完整保留下来。
   - 代码位置：`daemon/src/passes/map_inline.rs:41-50`、`432-506`、`1256-1269`。
   - 结果是：宽 key / split-store key 虽然能 inline value，但不容易 full-remove setup。
   - 这也是为什么 `daemon/src/passes/map_inline_tests.rs:1328-1384` 的 20-byte constant HASH key 最终只做了 load rewrite，没有把 lookup pattern 删掉。

3. `R2` setup 只用 8 条 real insn lookback 找“可一起删除的 pointer setup”。
   - 代码位置：`daemon/src/passes/map_inline.rs:22`、`1633-1654`。
   - 这不影响 key 恢复本身，只影响“能否顺手删掉那两条 `mov r2=fp; add r2,off` setup”。
   - 这也是全消除 coverage 的保守点，不是 inline 语义的硬条件。

### 放宽建议

建议拆成两个层次：

1. 先做“宽 key full-removal bookkeeping 修正”。
   - 让 `ConstantKey` 保存 `materialization_pcs: Vec<usize>`。
   - `find_constant_stack_bytes_with_limit()` 在拼接 key bytes 的同时，收集所有参与覆盖 key 区间的 stack store pc。
   - `build_site_rewrite()` 删除 pattern 时把这些 pc 全部纳入候选 skip set。

2. 再做“verifier-guided 宽 key 支持”。
   - 把 `verifier_guided_stack_store_value()` 从 `u64` 改成 `Vec<u8>`。
   - 允许多条 verifier-confirmed store 拼接宽 key，而不是只接受“单条 store 覆盖整个 key”。

### 预期 coverage 增益

对“site 是否能被 inline”：

- 这部分增益**很小**，接近 `0` 到“少量站点”。
- 因为 20-byte key 这类 constant-key site，今天其实已经能 inline。
- 当前 134 个 constant-key miss 的大头不是“key 太宽”，而是“key 根本不是 site-invariant constant”。

对“HASH 全消除 lookup + null check + null path”：

- 这部分增益是 **small-to-medium**。
- 它主要会把“已经 applied，但只做了 load rewrite”的宽 key / split-store site 升级成 full elimination。
- 由于当前 debug 产物没有单独统计“applied 但未 full-remove”的计数，我没法给出精确 site 数；但从测试和代码形态看，它更像是“提升已有命中质量”，不是“新开大量 miss -> hit”。

### 安全性分析

这类放宽只要满足两个条件就是安全的：

1. 参与删除的 key-setup 指令必须都是构造该已知 key bytes 的 side-effect-free 指令。
2. 删除集合必须完整覆盖它们的使用，或留给后续 DCE/branch-fixup 的残留指令也必须是语义无关的 dead code。

换句话说：

- 把 `u64` 扩成 `Vec<u8>` 是纯实现放宽，不引入 correctness 风险。
- 把“单个 `store_pc`”扩成“所有 materialization pcs”反而更安全，因为现在的 full-removal 路径对宽 key 是“知道 key bytes，但不知道 setup 的完整边界”。

## 2. Contiguous setup 限制

### 代码位置

- `daemon/src/passes/map_inline.rs:1583-1596`
  - `find_map_load_for_call()` 只要求回溯到“call 前最后一次定义 `r1`”，并不要求 setup 连续。
- `daemon/src/passes/map_inline.rs:1857-2035`
  - `resolve_stack_pointer_to_stack*()` 能沿 copy / add-sub 常量链回溯 `r2`，也不要求 setup 连续。
- `daemon/src/passes/map_inline.rs:1609-1630`
  - `lookup_pattern_removal_is_safe()` 明确要求待删除 pc 集必须形成一个 tight contiguous block。
- `daemon/src/passes/map_inline_tests.rs:1033-1064`
  - `test_map_inline_interleaved_arg_setup()` 证明“中间夹杂无关指令”时，site 仍然能 inline。

### 现状判断

“当前要求 map_fd load、key setup、lookup 必须连续”这个说法，**对 site eligibility 不成立**，但**对 full removal 成立**。

更准确地说：

- 当前 pass 对“能否 inline 常量 load”并不要求 setup 连续。
- 当前 pass 对“能否把整个 lookup pattern 都删掉”使用了“连续块”作为一个非常强的代理条件。

### 是否必要

对 full removal 而言，这个 contiguous 要求**不是语义硬条件**，只是当前实现为了简单和保险选的 proxy。

为什么说不是硬条件：

- 如果中间夹着的是无关、无 side effect 的 setup 指令，保留它们并不会影响 correctness。
- 更进一步，如果这些夹杂指令只给被删除的 helper call 准备参数，那么它们本身也只是 dead code，可以让 DCE 收掉。
- 也就是说，full elimination 真正需要的是“删掉的东西不会破坏剩余程序”，而不是“这些 pc 在数轴上正好连续”。

### 放宽建议

建议分两步：

1. 把 `lookup_pattern_removal_is_safe()` 从“连续块判定”改成“依赖/副作用判定”。
   - 保留 branch-target check。
   - 额外检查“被删除指令是否无 side effect”。
   - 允许 skip set 非连续，只要夹在中间留下来的指令不依赖被删除结果，或本身可安全保留。

2. 顺手把 map arg resolution 也从“最后一次定义 `r1` 必须是 `LD_IMM64 BPF_PSEUDO_MAP_FD`”扩成“允许 `mov r1, rX` alias chain”。
   - 代码位置：`daemon/src/passes/map_inline.rs:1583-1596`。
   - 这是一个比“是否连续”更强的隐藏 setup 限制。
   - 当前它会导致某些 site 根本不会被识别成 `MapLookupSite`，不是 full-removal，而是“连候选都进不来”。

### 预期 coverage 增益

对 `sites_applied`：

- **几乎没有增量**。
- 因为这条限制当前只影响“删不删整段 lookup pattern”，不影响“能不能把 fixed loads 改常量”。

对“HASH 全消除”：

- 我判断是 **small-to-medium** 增量。
- 这会把一部分“已 applied 但 helper/null-check 还留着”的 site 升级成 full elimination。
- 由于现有产物没有单独统计这类 site，我不建议在论文里写精确数字，只建议写成“预计提升 full-removal coverage，而不是 applied-site coverage”。

### 安全性分析

contiguous proxy 本身是保守但安全的。

如果要放宽，真正需要补的是：

- side-effect analysis
- live-use / dead-def analysis
- branch target / fallthrough 修正

只要这三点补齐，去掉“必须连续”不会引入 correctness 问题；否则容易出现“删掉 helper 后，夹在中间留下来的指令还在读被删 setup 的结果”。

## 3. Constant key 限制

### 代码位置

- `daemon/src/passes/map_inline.rs:807-823`
  - site 级别如果 `extract_site_constant_key()` 失败就直接 skip。
- `daemon/src/passes/map_inline.rs:1085-1208`
  - `extract_site_constant_key()` 的三条路径。
- `daemon/src/passes/map_inline.rs:1866-1971`
  - `resolve_key_pointer_origin*()` 只接受 key pointer 最终来自 stack / `BPF_PSEUDO_MAP_VALUE` 且偏移可常量化。
- `daemon/src/commands.rs:239-275`
  - 只把已经实际 inlined 的 `(map_id, key, expected_value)` 记录进 tracker。
- `daemon/src/invalidation.rs:94-160`
  - tracker 也是按具体 `(prog_id, map_fd, key, expected_value)` 做轮询比较。

### 现状判断

当前实现不是要求“源码层面的 compile-time constant key”，而是要求：

- 在 **该 lookup site** 上，inline 时能恢复出一个确定的、完整的、site-invariant key byte string。

这比“源码字面常量”稍宽：

- verifier-guided 可以接受某些语法上不明显常量、但 verifier state 已经把它收窄成单值的情况。
- pseudo-map-value key 也不是源码字面常量，但 inline 时确实是确定 bytes。

但是，它仍然是一个**硬常量 key** 模型，而不是“运行时 dynamic key 但 value 稳定”模型。

### 是否必要

对**当前这版“无 runtime key guard 的 HASH 全消除”**来说，这个限制是必要的。

原因很简单：

- 当前 rewrite 直接把 `bpf_map_lookup_elem(map, key)` 观察到的 `value` 变成若干常量 load。
- 如果 runtime key 不是唯一确定的，编译期根本不知道要把哪一个 `(key, value)` 填进指令流。
- 现有 invalidation tracker 只会跟踪“已经写进程序里的那个 key”，并不会在运行时替你做“如果 key=A 走版本 A；如果 key=B 走版本 B；否则 fallback helper”的分派。

所以：

- “value 稳定”本身不够。
- 还必须有“该 site 在运行时只会查这个确定 key”。

### 用户提出的 two alternatives 是否成立

#### 方案 A：inline 所有 `(key, value)` 对

理论上成立，但这已经是**另一种 pass 设计**，不是简单放宽当前 guard。

它至少需要：

- 把 runtime key bytes 读出来；
- 生成 key 比较链或 jump table；
- hot key 命中时走常量 fast path；
- 未命中时保留原 helper lookup fallback；
- invalidation tracker 改成跟踪一组 key，而不是一个 key。

这本质上是“guarded multi-key specialization”。

#### 方案 B：只 inline hot key

理论上也成立，但还是需要 runtime key guard。

否则你只是把“某次 profile 时看到的 hot key 对应 value”无条件写进程序，遇到冷 key 就直接错。

### 放宽建议

我不建议把当前 constant-key guard 直接删掉。

如果真要扩 coverage，正确方向是：

1. 保留当前 constant-key fast path，不动 correctness。
2. 新增 guarded specialization 形态：
   - 从 stack key bytes 生成若干 compare；
   - hit 已知 hot key 时用常量 load；
   - miss 时走原 helper call。
3. invalidation tracker 从“单 key”扩成“site 上被特化的 key 集合”。

### 预期 coverage 增益

这条一旦做成新 specialization 形态，理论上是最大的。

现实上限可以直接看当前 skip bucket：

- 在我汇总的最新 `2026-03-28` 六套 e2e 结果里，
- `lookup key is not a constant stack or pseudo-map-value materialization = 134 / 333 skipped`。

也就是说：

- **134 个 skipped site** 是“如果未来支持 guarded dynamic-key specialization，最有机会被重新争取”的上限池子。

但我不建议把这 134 全当成“可直接回收”：

- 里面有一部分 key 明显来自函数参数/ctx/动态 map state；
- 有些 site 即使 key guard 做出来，后面还会被 use-classifier / mutable-site guard 卡住；
- 还有一些本来就属于 map-of-maps / PERCPU_* 之类的别的问题。

更保守的说法是：

- 这条是**唯一可能带来 tens-to-100+ site 量级增益**的方向；
- 但它需要的是新设计，不是“去掉一个保守判断”。

### 安全性分析

直接去掉 constant-key guard 会立刻引入 correctness 问题。

只有两种安全做法：

1. 证明 runtime key 在该 site 上是 singleton。
2. 或者保留 runtime key guard + helper fallback。

除此之外，没有第三条路。

## 4. “纯标量 load”限制

### 代码位置

- `daemon/src/passes/map_inline.rs:2198-2309`
  - `classify_r0_uses_with_options()`。
- `daemon/src/passes/map_inline.rs:2381-2383`
  - 当前唯一被识别为 readonly helper 的是 `bpf_ktime_get_ns()`。
- `daemon/src/passes/map_inline.rs:2401-2407`
  - `ends_current_use_region()`：遇到无关 jump 或下一个 lookup setup 就停。
- `daemon/src/passes/map_inline.rs:845-882`
  - site 使用 classifier 结果做 eligibility 判断。
- `daemon/src/passes/map_inline_tests.rs:1531-1573`
  - `map_inline_pass_rewrites_load_before_pointer_escape_to_helper()`。
- `daemon/src/passes/map_inline_tests.rs:1577-1617`
  - `map_inline_pass_rewrites_load_before_lookup_result_write_back()`。
- `daemon/src/passes/map_inline_tests.rs:1989-2021`
  - mutable array 跨 readonly helper 仍可 inline。
- `daemon/src/passes/map_inline_tests.rs:2024-2053`
  - hash 跨同一个 readonly helper 目前却被拒绝。

### 现状判断

这里最关键的结论是：

- 当前代码**并不要求“被 inline 的 load 后面只能继续做纯标量运算”**。
- 它真正要求的是：`r0` 或其 alias 的**直接 pointer uses**必须足够简单，最好只是 fixed-offset scalar `LDX_MEM`。

换句话说：

- `r0 -> ldx_mem -> r6`，然后 `r6` 再参与算术、比较、存栈、传 helper，这些都不是问题。
- 单测已经覆盖了“先 inline load，再 pointer escape / store-back”的 frozen case。

所以如果用户是在质疑“loaded scalar 后续为什么不能继续参与计算”，答案是：

- **当前代码其实已经允许**。

### 当前真正保守的地方

我认为这里有 4 个保守点：

1. 只接受 fixed-offset scalar `LDX_MEM`。
   - 代码位置：`daemon/src/passes/map_inline.rs:2293-2301`。
   - 这意味着 variable-offset load、memcpy 风格访问、helper-based read 都不会进入 `fixed_loads`。

2. 只做线性 use-region 扫描。
   - 代码位置：`daemon/src/passes/map_inline.rs:2401-2407`。
   - 一遇到无关 jump 就停，不走 CFG，不做 path merge。
   - 这会漏掉“alias 实际仍活着，但 load 出现在控制流后面”的 site。

3. helper whitelist 太窄。
   - 代码位置：`daemon/src/passes/map_inline.rs:2381-2383`。
   - 现在只把 `bpf_ktime_get_ns()` 视作 readonly helper。
   - 而且这个 readonly 穿越只对 `ARRAY/PERCPU_ARRAY` 生效，HASH 不生效。

4. HASH 不能跨 readonly helper。
   - 入口在 `daemon/src/passes/map_inline.rs:845-850` 传给 classifier 的两个 bool。
   - 对 HASH：
     - `allow_unrelated_helper_calls = false`
     - `allow_readonly_helper_calls = false`
   - 这不是语义必需，更像当前实现没有继续做 alias liveness / null-path reasoning。

### 哪些限制是必要的

必要的部分：

- 如果 `r0` 被真正当成 pointer 传给可能读/写该内存的 helper，当前 pass 不能删 lookup，也不应该盲目把 value load 常量化到 helper 之后。
- 如果 direct use 是 variable-offset read，当前 `read_scalar_from_value()` 根本没有足够信息做 constant substitution。
- mutable site 上如果 lookup result 被写回 map value，本 site 的自写会让 specialization 在 invalidation tick 之前高度可能 stale，这条 veto 大体合理。

不必要保守的部分：

- downstream scalar 运算不是问题。
- HASH 不允许跨 readonly helper 是不必要保守。
- 只允许一个 helper (`ktime_get_ns`) 也是不必要保守。
- 遇到无关 jump 就停是实现保守，不是语义硬条件。

### 放宽建议

我建议把这部分拆成三档：

1. 低风险：
   - 把 readonly helper whitelist 从单个 helper 扩成“按 helper signature / memory side effect”表。
   - 至少让 HASH 也能复用“callee-saved alias 跨 readonly helper”的逻辑。

2. 中风险：
   - 把 `ends_current_use_region()` 从线性规则换成一个小 CFG walk，只跟踪 alias live range。

3. 高风险：
   - 尝试接受某些 helper-based read pattern 或更复杂的 pointer arithmetic。
   - 这一步已经不再是“放宽保守性”，而是加新语义建模了。

### 预期 coverage 增益

真实上限可以从当前 skip bucket 粗看：

- `lookup result is not consumed by fixed-offset scalar loads = 67`
- `mutable lookup result has non-load uses = 77`

但这两个 bucket 不能简单相加理解成“144 都能救回来”。

更稳妥的判断是：

- helper whitelist / HASH 跨 readonly helper / CFG alias 放宽，**有机会吃掉其中的 low-tens sites**。
- 它不太可能像 dynamic-key 那样带来 100+ 量级增益，但很可能是“第二优先级”的真收益来源。

### 安全性分析

这类放宽必须守住两条线：

1. helper 不得通过该 pointer 读/写 map value bytes。
2. alias 在 helper / CFG 之后必须仍然可证明指向同一块 lookup result。

如果只是扩大 readonly helper whitelist，并要求 alias 保存在 `r6-r9` 或 8-byte spill/reload 里，我认为是可控的。

## 5. Mutable map 限制

### 代码位置

- `daemon/src/analysis/map_info.rs:58-66`
  - `is_inlineable_v1()` 不区分 frozen/mutable，mutable map type 本身允许 inline。
- `daemon/src/passes/map_inline.rs:870-882`
  - 真正的 mutable guard 只有这一条：
  - `if !info.frozen && !uses.other_uses.is_empty() { skip }`
- `daemon/src/passes/map_inline_tests.rs:1856-1883`
  - 当前 site 自己写回 map value，会被拒绝。
- `daemon/src/passes/map_inline_tests.rs:1886-1938`
  - 同一程序别处对同一张 map 写回，当前只读 site 仍能 inline。
- `daemon/src/passes/map_inline_tests.rs:1942-1986`
  - 另一张 mutable map 有写回，也不会污染当前只读 site。
- `daemon/src/commands.rs:239-275`
  - 每次成功 inline 后，按 `(prog_id, map_id, key, expected_value)` 刷新 tracker。
- `daemon/src/invalidation.rs:94-160`
  - tracker 只比较具体 key 的当前 value 是否等于 `expected_value`。
- `daemon/src/server.rs:31-55`
  - invalidation tick 发现不等就 reoptimize 对应 program。

### 现状判断

当前 mutable guard 是**site-local**的。

它不是：

- per-site 以外的 per-map veto；
- 也不是“程序里任何地方写过该 map 就全禁 inline”；
- 更不是“系统里任何程序 / 用户态写过该 map 就不 inline”。

当前真正的模型是：

- 允许 mutable read-only site speculative inline；
- 允许用户态或其他程序更新 map；
- 一旦 tracked `(map,key,value)` 变了，靠 polling invalidation 触发 re-REJIT。

### 是否必要

用户担心的“当前 mutable writeback guard 太粗，会错杀只读 site”这件事，**在当前代码里已经不是事实**。

所以：

- “把 per-map / per-program 全局 mutable veto 放宽”这条，在当前代码里没有可做的收益，因为它已经被放宽掉了。

当前仍保守、但大体必要的是：

- mutable site 上只要有 `other_uses`，就拒绝。

这条为什么我认为大体必要：

- 如果 site 自己通过 lookup result 写回 map value，那么 specialization 几乎必然在后续执行里变 stale；
- invalidation 不是 synchronous deopt，而是周期性 polling；
- 所以“当前 site 自己就会改这块 value”的情况，比“别的地方也许会改”危险得多。

### 放宽建议

我不建议把 `daemon/src/passes/map_inline.rs:870-882` 这一条整体删除。

可以做的只是更细化 `other_uses` 的分类：

- 把明确 readonly 的 helper / alias-preserving pattern 从 `other_uses` 里剥出去；
- 这本质上和上一节的 use-classifier 放宽是一回事。

### 预期 coverage 增益

- 对“修 per-map guard”的收益：**0**，因为当前已经没有这个 guard。
- 对“放宽 site-local `other_uses` 分类”的收益：落在上一节，和 `67 + 77` 那两个 bucket 重叠。

### 安全性分析

如果把 site-local mutable writeback veto 直接拿掉，会引入非常实在的 stale 风险：

- 该 site 本身就可能在本次执行中修改 value；
- 下一次执行到来时，specialized constant 仍然是旧值；
- invalidation tick 还没来得及触发 rollback。

所以这条不是“形式上保守”，而是当前 polling invalidation 模型下的重要安全边界。

## 6. Map type 限制

### 代码位置

- `daemon/src/analysis/map_info.rs:48-56`
  - `supports_direct_value_access()` 目前 whitelist 只有：
  - `HASH` / `ARRAY` / `PERCPU_ARRAY` / `LRU_HASH`
- `daemon/src/analysis/map_info.rs:70-75`
  - `can_remove_lookup_pattern_v1()` 只有：
  - `ARRAY` / `PERCPU_ARRAY`
- `daemon/src/analysis/map_info.rs:79-80`
  - `is_speculative_v1()` 只有：
  - `HASH` / `LRU_HASH`
- `daemon/src/passes/map_inline.rs:1487-1527`
  - 只有 `PERCPU_ARRAY` 会经过“全 per-CPU slot 一致性折叠”。
- `daemon/src/bpf.rs:594-616`
  - userspace lookup value size 其实已经支持所有 per-CPU map type 的完整 blob 长度。
- `daemon/src/passes/map_inline_tests.rs:2226-2305`
  - `PERCPU_ARRAY` 当前已经支持 uniform-slot inline。
- `daemon/src/passes/map_inline_tests.rs:2308-2341`
  - mixed-slot `PERCPU_ARRAY` 会被拒绝。
- `daemon/src/passes/map_inline_tests.rs:2344-2418`
  - `PERCPU_HASH` / `LRU_PERCPU_HASH` 当前直接被拒绝。

### 6.1 PERCPU_ARRAY

#### 判断

“PERCPU_ARRAY 真的不能 inline 吗？”这个问题的答案是：

- **当前代码已经能 inline**，前提是同一个 key 的所有 CPU slot bytes 完全一致。

所以这不是一个待放宽的全局限制。

当前唯一的 site-level veto：

- `daemon/src/passes/map_inline.rs:1498-1527`
- 如果 per-CPU blob 各 slot 不一致，就拒绝。

这条 veto 我认为是必要的。

#### 预期 coverage

这条本身没有“再放宽 map type whitelist”的收益。

最新 e2e 聚合里：

- `PERCPU_ARRAY value differs across CPUs for 19 slot(s) = 19`

这 19 个 skip 是真实语义差异，不建议为了 coverage 直接放开。

### 6.2 PERCPU_HASH / LRU_PERCPU_HASH

#### 判断

这两类我认为是**当前代码里最像“不必要保守 map-type 限制”的点**。

原因：

1. `daemon/src/bpf.rs:594-616` 已经能按完整 per-CPU blob 大小做 userspace lookup。
2. 当前对 `PERCPU_ARRAY` 的处理方式是：
   - 先拿完整 per-CPU blob；
   - 再验证所有 slot 是否完全一致；
   - 一致才 collapse 成单个常量值。
3. 这套逻辑同样可以套到 `PERCPU_HASH` / `LRU_PERCPU_HASH`：
   - hit/miss 语义走 HASH 的 speculative path；
   - value bytes 走“uniform per-CPU blob collapse”。

也就是说，当前把 `PERCPU_HASH` / `LRU_PERCPU_HASH` 完全挡在 `supports_direct_value_access()` 之外，更像是“还没实现”，而不是“根本不可能正确”。

#### 放宽建议

建议把：

- `supports_direct_value_access()`
- `is_speculative_v1()`

扩到：

- `PERCPU_HASH`
- `LRU_PERCPU_HASH`

并把 `prepare_inline_value()` 的 `PERCPU_ARRAY` 专用逻辑泛化成“所有 per-CPU map 共享的 uniform-slot collapse”。

#### 预期 coverage

这是一个可以量化的 gain：

- 最新 6 套 e2e 聚合里，
- `map type 5 not inlineable in v1 = 5`
- `map type 10 not inlineable in v1 = 4`

也就是 **最多约 9 个直接 skip site** 可能被重新争取。

实际能回收多少，要再乘一个“该 key 的所有 CPU slot 是否刚好一致”的折扣。

#### 安全性分析

只要保留两层保护，这条放宽是可控的：

1. HASH-family 的 null/hit 语义仍按当前 speculative/full-removal 规则处理。
2. 只有当完整 per-CPU blob 各 slot 完全一致时，才 collapse 成单个常量。

如果 slot 不一致就继续 skip，不会引入 correctness 问题。

### 6.3 ARRAY_OF_MAPS / HASH_OF_MAPS（map type 12/13）

#### 判断

这两类当前在真实 workload 里确实是 blocker：

- 最新 6 套 e2e 聚合里，
- `map type 12 not inlineable in v1 = 6`
- `map type 13 not inlineable in v1 = 16`

但我不认为这属于“当前 pass 上的简单保守限制”。

原因是当前 `map_inline` 的核心假设是：

- helper 返回的是“可按 bytes 解释的 value blob”；
- 后续使用是 `*(r0 + off)` 这样的 field load。

而 map-of-maps 的 outer lookup 返回值语义不是普通 value bytes。

如果要做这类优化，正确方向不是“把 map type 12/13 塞进 whitelist”，而是新做一个：

- outer-map -> known inner map identity specialization
- 把 outer lookup 改成已知 inner map 的 pseudo-map load 或等价形式

这是另一个 pass，不是当前 `map_inline` 的 if-guard 放宽。

#### 预期 coverage

- 这类 site 总量不低，当前直接 skip 约 `22` 个。
- 但对当前 pass 的简单放宽收益应视为 **0**，因为直接放开会破坏语义。

#### 安全性分析

当前 pass 如果把 map-of-maps 当普通 value bytes 处理，是明显不正确的。

所以这里的结论是：

- **有优化机会**
- 但**不是当前 pass 的“保守限制”，而是“优化对象不同”**

## 额外发现：两个直接影响 HASH 全消除的隐藏保守点

这两点不在用户列出的 6 条里，但我认为都值得一起记录。

### A. 只接受 `JEQ` fallthrough-non-null 形状做 full removal

代码位置：

- `daemon/src/passes/map_inline.rs:1249-1250`
  - `removable_null_check_pc` 只接受 `null_check_is_fallthrough_non_null()`
- `daemon/src/passes/map_inline.rs:2429-2436`
  - 这个 helper 只认 `JEQ rX, 0, +off` 且 non-null path 是 fallthrough
- `daemon/src/passes/map_inline_tests.rs:1485-1528`
  - `JNE` null guard 目前只做 load rewrite，不做 full removal

判断：

- 这是**不必要保守**。
- `JNE` 形的 null guard 也完全可以做 HASH 全消除，只是当前实现为了简化 null-path cleanup 只做了一个方向。

预期增益：

- 量化数据现在没有单独 bucket；
- 但对 HASH full elimination 是实打实的覆盖面扩张。

### B. `find_map_load_for_call()` 不解析 `r1` alias

代码位置：

- `daemon/src/passes/map_inline.rs:1583-1596`

判断：

- 当前只有“call 前最后一次定义 `r1` 就是 `LD_IMM64 BPF_PSEUDO_MAP_FD`”才把 site 识别出来。
- 如果真实程序是：
  - `ldimm64 r6 = map_fd`
  - `mov r1, r6`
  - `call lookup`
- 这类 site 当前会被漏掉。

这不是“连续”问题，而是更强的“map arg setup 解析太弱”。

## 最终判断表

| 限制 | 当前是否存在 | 是否必要 | 我建议怎么处理 |
| --- | --- | --- | --- |
| `key 必须 4B` | 否 | 否 | 不需要改这个方向；真正要改的是宽 key full-removal bookkeeping |
| 宽 key verifier-guided 只到 8B | 是 | 否 | 改成 byte-vector 提取 |
| full removal 依赖 contiguous setup | 是 | 否 | 改成依赖/副作用判定，不再要求 skip set 连续 |
| key 必须 site-invariant constant | 是 | 对当前无 guard 全消除是必要的 | 若要扩 dynamic key，必须升级成 guarded specialization |
| “只允许纯标量 load”导致后续算术不能 inline | 否 | 否 | 当前已经允许；真正该放宽的是 helper/CFG/use-classifier |
| mutable guard 是 per-map/per-program | 否 | 否 | 当前已经是 site-local，不需要修这个方向 |
| mutable site-local writeback veto | 是 | 大体必要 | 不建议直接删，只建议细化 `other_uses` 分类 |
| PERCPU_ARRAY 不支持 inline | 否 | 否 | 当前已支持 uniform-slot 情况 |
| PERCPU_HASH / LRU_PERCPU_HASH 全局排除 | 是 | 否，偏实现保守 | 建议按“uniform per-CPU blob + HASH null semantics”扩支持 |
| ARRAY_OF_MAPS / HASH_OF_MAPS 全局排除 | 是 | 对当前 pass 形态是必要的 | 若要做，单独做 map-of-maps specialization pass |

## 我认为最值得先改的三件事

1. 宽 key / split-store 的 full-removal bookkeeping。
   - 这是最“便宜”的 HASH 全消除覆盖扩张。
   - 不改 specialization 语义，只是把当前已经知道的 key materialization 边界记全。

2. full-removal 的 contiguous proxy。
   - 它不增加 `sites_applied`，但能增加“真正全消除”的比例。
   - 对用户当前关心的 HASH aggressive inline 命中率更对路。

3. use-classifier 的 helper/CFG 放宽。
   - 这是次于 dynamic-key 的真实 blocker。
   - 也是比 dynamic-key redesign 风险小得多的增量。

## 不建议直接动的两件事

1. 直接删掉 constant-key guard。
   - 这会马上引入错误 specialization。

2. 直接删掉 mutable site-local writeback veto。
   - 在当前 polling invalidation 模型下，会引入明显的 stale window correctness 风险。
