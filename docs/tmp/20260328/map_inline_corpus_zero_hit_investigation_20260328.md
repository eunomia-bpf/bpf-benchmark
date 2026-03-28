# BpfReJIT `map_inline` 全量 corpus 零命中调查

日期：2026-03-28

## TL;DR

- `2026-03-26` 的最后一份全量 corpus artifact 确实记录了 `map_inline = 0`，但这份 artifact 已经落后于当前 pass 控制面和后续 `map_inline` 增强，不能代表“当前 daemon 在全量 corpus 上仍然 0 命中”。
- 这份 full-run artifact 只保留了 `metadata.json`，没有 `details/`，而批处理结果里又是 `daemon_debug_stripped: true`，因此几乎拿不到站点级 `skip reason`。它能证明“当时没有 recorded hit”，但不能证明“当前实现为什么 0 hit”。
- 当前 corpus 并不缺 `map_lookup_elem()` 负载。对全量 run 选择集做离线扫描后，`764` 个程序里有 `148` 个程序、共 `2432` 个 lookup sites；其中 `1005` 个 site 的 key 可从栈上恢复为常量，保守 preflight 仍能看到 `212` 个潜在 inline 候选。
- 当前安全版 coverage 掉到很低的主要技术原因不是 constant-key enhancement 没落地，而是 safety guard 太粗。尤其是 `mutable map value is written elsewhere in program` 这条 guard 现在是“按 `map_id` 的程序级 veto”，会把同一张 mutable map 上本来只读的 lookup site 一起杀掉。
- Katran 的演化链条已经把这个问题暴露得很清楚：
  - 仓内笔记记录过一个高水位：定向 rerun 曾到 `41/105`。
  - 后续 live corpus 定向验证也曾稳定到 `7/64`。
  - 当前安全版 artifact `docs/tmp/20260327/katran_debug_batch_result.json` 只剩 `2/66`，其中 `50/64` 个 skip 直接来自那条程序级 mutable-writeback guard。

## 1. 调查范围与证据

阅读与检查的对象：

- 当前实现：
  - `daemon/src/passes/map_inline.rs`
  - `daemon/src/analysis/map_info.rs`
  - `daemon/src/pass.rs`
  - `daemon/src/commands.rs`
- 当前 benchmark 配置：
  - `corpus/config/benchmark_config.yaml`
- 最新全量 corpus 结果：
  - `corpus/results/vm_corpus_20260326_174240/metadata.json`
  - `corpus/results/vm_corpus_20260326_201508/metadata.json`
  - `docs/tmp/20260326/corpus-rejit-batch/*.json`
- Katran 定向 rerun / 调试结果：
  - `docs/tmp/20260327/experiment_progress_and_current_issues_20260327.md`
  - `docs/tmp/20260327/katran_corpus_map_inline_20260327.md`
  - `docs/tmp/20260327/katran_debug_batch_result.json`
- 额外做了一个纯离线 `.bpf.o` 站点扫描，用当前仓库里的 `map_inline` 逻辑统计全量选择集站点形态；没有跑 VM，也没有对 host kernel 做任何 BPF 操作。

## 2. 当前 `map_inline` 的完整逻辑

### 2.1 总体结构

`MapInlinePass::run()` 在 `daemon/src/passes/map_inline.rs:658-723`，它会跑最多 `8` 轮 fixed-point。

- 第一轮启用 verifier-guided key extraction。
- 后续轮次继续跑 `map_inline`，但不再尝试 verifier-guided key extraction。
- 除 lookup-site rewrite 之外，当前 pass 还包含一条 direct `pseudo_map_value` load rewrite 路径，用于 frozen map / `.rodata` 风格的直接 load，代码在 `daemon/src/passes/map_inline.rs:1338-1471`。

### 2.2 Constant key 提取

站点级 key 提取入口在 `extract_site_constant_key()`，`daemon/src/passes/map_inline.rs:1094-1205`。顺序是：

1. 第一轮先尝试 verifier-guided key extraction。
2. 失败后退回栈回溯扫描。
3. 再失败后尝试 `BPF_PSEUDO_MAP_VALUE` key。

三条路径分别是：

- verifier-guided：
  - `try_extract_constant_key_verifier_guided()`，`daemon/src/passes/map_inline.rs:272-341`
  - 只支持 `key_size <= 8`
  - 依赖 `program.verifier_states`
  - 会检查同一 call-site 的多个 verifier state 是否给出一致 key
- 栈扫描：
  - `try_extract_constant_key_sized()`，`daemon/src/passes/map_inline.rs:151-177`
  - `find_constant_stack_bytes*()`，`daemon/src/passes/map_inline.rs:412-505`
  - 会沿着当前子程序向后回溯，拼接覆盖 key 区间的 `ST/STX` 栈写
  - 支持 key 宽度按 map `key_size` 精确提取，不再要求 store 宽度和 key_size 完全相等
- `PSEUDO_MAP_VALUE`：
  - `try_extract_constant_key_from_map_value()`，`daemon/src/passes/map_inline.rs:179-270`
  - 要求 key 指针最终能解到 `BPF_PSEUDO_MAP_VALUE`
  - 源 map 必须是 frozen
  - 会把源 map value 的指定偏移片段当作 key

为了让栈扫描覆盖真实 clang 代码生成，当前实现还做了两层泛化：

- 常量寄存器求值：
  - `resolve_constant_reg_value_inner()`，`daemon/src/passes/map_inline.rs:1678-1789`
  - 支持 `mov imm`、`mov reg`、`ldimm64`、常量 ALU K/X 链，以及从“已知常量栈槽”load 回寄存器
- key 指针来源解析：
  - `resolve_key_pointer_origin_inner()`，`daemon/src/passes/map_inline.rs:1865-1949`
  - 支持寄存器 copy chain、`add/sub` 常量偏移
  - 能区分 key 来自栈还是 `pseudo_map_value`

### 2.3 Map type 过滤

map type 语义在 `daemon/src/analysis/map_info.rs:31-80`。

当前 v1 直接可 inline 的类型只有：

- `HASH` (`1`)
- `ARRAY` (`2`)
- `PERCPU_ARRAY` (`6`)
- `LRU_HASH` (`9`)

进一步区分：

- 可以删掉 lookup/null-check pattern 的只有：
  - `ARRAY`
  - `PERCPU_ARRAY`
- 属于 speculative inline 的只有：
  - `HASH`
  - `LRU_HASH`

明确不支持的几类：

- `PERCPU_HASH` / `LRU_PERCPU_HASH`
- 各类不支持 direct value access 的 map
- Katran 里常见的 `map type 12` / `13` 也会被当前 v1 直接跳过

### 2.4 `r0` use classification

`classify_r0_uses_with_options()` 在 `daemon/src/passes/map_inline.rs:2190-2300`。

它会从 helper call 之后沿着 `r0` 的 alias 继续扫描，区分为：

- `fixed_loads`
  - `r0` 或其 alias 只被固定偏移的 `ldx` 标量 load 消费
- `other_uses`
  - 任何非 fixed-offset scalar load 的使用
- `alias_copy_pcs`
  - 寄存器 copy、栈 spill / reload 形成的 alias
- `null_check_pc`
  - 只接受“在任何其它 use 之前出现的 immediate null check”

这个 classifier 目前允许：

- 寄存器 copy
- 8-byte 栈 spill / reload
- 在特定条件下穿过 helper call

但对 mutable map 来说，仍然非常保守：

- 只要存在 `other_uses`，站点就会被拒绝

### 2.5 Safety guards

当前 `map_inline.rs` 里的主要 safety guard 有：

1. unsupported map type
   - `daemon/src/passes/map_inline.rs:782-799`
2. mutable map 的程序级 writeback veto
   - `collect_mutable_maps_with_lookup_value_writes()`，`daemon/src/passes/map_inline.rs:2302-2325`
   - `lookup_result_may_write_value()`，`daemon/src/passes/map_inline.rs:2327-2383`
   - 一旦某个 mutable `map_id` 在本程序任意 lookup site 上出现“可能经 lookup result 写回 map value”，该 `map_id` 上所有 lookup site 都会被 veto
3. speculative `HASH/LRU_HASH` 必须有 immediate null check
   - `daemon/src/passes/map_inline.rs:861-864`
4. lookup result 必须至少有一个 fixed-offset scalar load
   - `daemon/src/passes/map_inline.rs:874-878`
5. mutable lookup result 不能有 non-load uses
   - `daemon/src/passes/map_inline.rs:879-892`
6. `PERCPU_ARRAY` 只有在所有 CPU slot 的 value 完全一致时才能 inline
   - `prepare_inline_value()` / `collapse_uniform_percpu_array_value()`，`daemon/src/passes/map_inline.rs:1478-1518`
7. 删除 lookup/null-check pattern 前，还要求 non-null window 只包含“可平凡删除”的指令
   - `null_check_removal_window_is_trivial()`，`daemon/src/passes/map_inline.rs:2497-2530`
8. rewrite 不能跨 branch target，也不能发生内部 overlap
   - `daemon/src/passes/map_inline.rs:920-938`

关于 tail-call：

- 当前 `daemon/src/passes/map_inline.rs` 里没有看到一个显式的 tail-call-specific blanket guard。
- 所以“tail-call”不是当前 `map_inline` 自身的直接 veto 条件；此前 repo 笔记里出现的 tail-call 问题，更多是别的 pass 交互和更早阶段的保护策略，不是这份当前实现里的显式分支。

## 3. 当前 active passes

`corpus/config/benchmark_config.yaml` 当前配置非常明确：

- `performance: [map_inline, const_prop, dce]`
- `security: [dangerous_helper_firewall, live_patch, speculation_barrier]`
- `active: performance`

也就是说，按今天仓库里的配置，full corpus 的 performance profile 应该只跑：

- `map_inline`
- `const_prop`
- `dce`

## 4. 最新全量 corpus run 为什么不能解释“当前 0 hit”

### 4.1 最新全量 run 的事实

最后两份全量结果是：

- `corpus/results/vm_corpus_20260326_174240/metadata.json`
- `corpus/results/vm_corpus_20260326_201508/metadata.json`

两者都显示：

- `total_programs = 764`
- `details_dir = "details"`
- 但目录里实际上只有 `metadata.json`，没有 `details/`

两份 `metadata.json` 的总 `pass_counts` 都没有 `map_inline`：

- `20260326_201508`：
  - `const_prop = 138`
  - `dangerous_helper_firewall = 86`
  - `dce = 34`
  - `endian_fusion = 119`
  - `extract = 13`
  - `live_patch = 116`
  - `skb_load_bytes_spec = 2`
  - `wide_mem = 67`
  - `map_inline = 0`
- `20260326_174240`：
  - 同样没有 `map_inline`

### 4.2 这份 artifact 本身存在两个结构性问题

第一，它是 stale artifact。

- 今天的 benchmark 配置已经是 `map_inline,const_prop,dce`
- 但 `2026-03-26` 的 full-run `pass_counts` 还混入了大量别的 pass
- 这说明它不是在今天这套 active-pass / request-level pass control 下跑出来的权威结果

第二，它不保留足够的诊断信息。

- `details/` 目录缺失
- `docs/tmp/20260326/corpus-rejit-batch/*.json` 里虽然有逐程序结果，但 `rejit.daemon_debug_stripped = true`
- 因此拿不到今天最关键的信息：
  - `sites_found`
  - `sites_applied`
  - `sites_skipped`
  - `skip_reasons`
  - verifier-guided key extraction 是否真的参与

### 4.3 结论

`2026-03-26` full corpus artifact 可以证明一件事：

- 当时被保存下来的 full-run 结果里，`map_inline` 没有 recorded hit

但它不能证明两件更重要的事：

- 当前增强后的 daemon 在全量 corpus 上仍然会 0 hit
- 当前 0 hit 的站点级根因究竟是什么

## 5. 真实 corpus `.bpf.o` 的 map 使用模式

我对 full run 选择集做了纯离线扫描，结果如下。

### 5.1 总体规模

| 指标 | 数值 |
| --- | ---: |
| selected programs | 764 |
| selected objects | 477 |
| programs with `map_lookup_elem` | 148 |
| total lookup sites | 2432 |

这已经足够说明：

- full corpus 不是“没有 map lookup workload”
- `map_inline = 0` 不是因为 corpus 天然没有目标

### 5.2 key 形态

| 指标 | 数值 |
| --- | ---: |
| stack-constant key sites | 1005 |
| pseudo-map-value key sites | 0 |
| dynamic / other key sites | 1427 |

几个直接结论：

- 当前 full-corpus 选择集里，lookup-site 级别的 `PSEUDO_MAP_VALUE` key 实际上是 `0`。
- 所以近期加上的 `PSEUDO_MAP_VALUE` key enhancement 是正确方向，但它不是当前 full-corpus 站点覆盖的主要杠杆。
- 当前最有价值的 key-side enhancement 仍然是：
  - 栈 constant-key recovery
  - verifier-guided key extraction

### 5.3 map type 分布

| Map category | Sites |
| --- | ---: |
| `ARRAY` | 379 |
| `HASH` | 555 |
| `LRU_HASH` | 197 |
| `PERCPU_ARRAY` | 649 |
| `PERCPU_HASH` | 141 |
| `LRU_PERCPU_HASH` | 95 |
| other unsupported / non-direct-access types | 416 |

观察：

- 当前 v1 直接可能处理的类型总计 `1780` site：`ARRAY + HASH + LRU_HASH + PERCPU_ARRAY`
- 但其中 `PERCPU_ARRAY` 很多，而它又受“所有 CPU slot 必须字节级一致”的硬 guard 约束
- 明确超出当前 v1 map type 能力边界的 site 至少 `652` 个

### 5.4 lookup result 使用形态

| 指标 | 数值 |
| --- | ---: |
| sites without fixed loads | 1196 |
| fixed-load-only sites | 530 |
| fixed-load plus other-use sites | 706 |
| lookup writeback sites | 1137 |
| speculative hash sites missing immediate null-check | 31 |
| conservative preflight-eligible sites | 212 |
| potential constant-array sites | 277 |

这组数字基本把当前 coverage loss 解释完了：

- 最大的阻塞并不是“map lookup 太少”，而是：
  - 动态 key 多
  - 非 fixed-load consumer 多
  - mutable store-back / writeback 很常见
- 即使在非常保守的条件下，离线 preflight 仍然能看到 `212` 个潜在候选；这与 `0 hit` 明显矛盾，进一步说明 full-run artifact 已经过时或失真

### 5.5 来源分布

站点数最多的来源：

- `tetragon`: `1094`
- `calico`: `534`
- `tracee`: `134`
- `linux-selftests`: `156`
- `katran`: `79`
- `loxilb`: `145`
- `xdp-tools`: `63`
- `KubeArmor`: `71`

最值得优先看的对象：

- `corpus/build/KubeArmor/system_monitor.bpf.o`: `37` 个保守 preflight 候选
- `corpus/build/katran/balancer.bpf.o`: `28`
- `corpus/build/tracee/tracee.bpf.o`: `22`
- `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/xdp_synproxy_kern.bpf.o`: `20`
- `corpus/build/xdp-tools/xdp_redirect_cpumap.bpf.o`: `8`
- `corpus/build/scx/scx_rusty_main.bpf.o`: `7`

## 6. Katran 为什么能命中，而 full artifact 看起来是 0

### 6.1 Katran 的三个阶段

仓内现有证据能串出一条非常清楚的时间线：

1. 高水位阶段
   - `docs/tmp/20260327/experiment_progress_and_current_issues_20260327.md`
   - 记录了定向 Katran rerun 到过：
     - `sites_applied = 41`
     - `sites_found = 105`
2. 修 null-check removal 后的 corpus 定向阶段
   - `docs/tmp/20260327/katran_corpus_map_inline_20260327.md`
   - 记录了：
     - `sites_found = 64`
     - `sites_applied = 7`
     - 主要 skip：
       - constant-key miss `24`
       - non-load uses `20`
       - no fixed-loads `9`
       - map type `12/13` 各 `2`
3. 当前安全版
   - `docs/tmp/20260327/katran_debug_batch_result.json`
   - 记录了：
     - `sites_found = 66`
     - `sites_applied = 2`
     - `sites_skipped = 64`
     - skip reason：
       - `mutable map value is written elsewhere in program`: `50`
       - `lookup key is not a constant stack or pseudo-map-value materialization`: `8`
       - `lookup result is not consumed by fixed-offset scalar loads`: `2`
       - `map type 12 not inlineable in v1`: `2`
       - `map type 13 not inlineable in v1`: `2`

### 6.2 Katran 当前最关键的结论

Katran 现在已经证明：

- `map_inline` 不是天然打不到真实程序
- constant-key extraction 不是唯一 blocker
- coverage 从高水位掉到 `2`，主因是安全策略变得更保守，尤其是 mutable writeback guard

当前安全版最重的那条 skip：

- `mutable map value is written elsewhere in program`

不是 site-local 的，而是程序级 map veto：

- 只要这个程序里某个 lookup site 可能经 alias 写回某张 mutable map
- 同一个 `map_id` 上的其它 lookup site 也会一起被禁掉

这正好解释了为什么 Katran 从大量命中退化到只剩 `2` 个稳定 `ctl_array` site。

### 6.3 full artifact 为什么和 Katran 看上去矛盾

两者其实不矛盾。

真正的差异是：

- full corpus 的最后 artifact 是 stale 并且 stripped
- Katran 的定向 rerun 是新、近、并且保留了 `pass_details`

所以：

- full artifact 的 `0` 更像是“最后一次被保存的全量结果没有记录到 `map_inline`”
- Katran artifact 才能回答“当前算法在真实程序上具体被什么 guard 卡住”

## 7. 零命中的根因

### 7.1 流程 / artifact 层面的根因

这次“全量 corpus 零命中”的首要根因是：

- 增强后的 `map_inline` 从未在全量 corpus 上重跑并保存完整诊断

具体表现：

- 最后全量 run 仍停留在 `2026-03-26`
- 它的 pass 组合不是今天这套 performance-only 组合
- 它没有 `details/`
- 批处理结果又剥掉了 daemon 调试信息

因此今天能做的只能是：

- 从 stale artifact 证明“当时 recorded hit = 0”
- 再从当前源码和离线对象分布推断“如果今天重跑，真正会被什么 guard 卡住”

### 7.2 技术层面的主根因

如果问题改写成“为什么当前增强后的 daemon 即使重跑，全量 corpus 也可能仍然 hit 不高”，根因排序如下：

1. mutable writeback guard 过于粗糙
   - 当前是 map-wide、program-wide veto
   - 这是安全 coverage 从高水位掉到 `2` 的第一元凶
2. use classifier 仍然过窄
   - 很多 site 有 fixed loads，但同时带了其它 benign uses，就会被拒绝
3. 大量 key 仍然是动态 key
   - `1427 / 2432` 站点不属于当前 constant-key 模型
4. map type 覆盖仍有限
   - 至少 `652` 个 site 落在当前 v1 map type 边界之外
5. verifier-guided key extraction 在真实 rerun 里没有真正贡献
   - 代码路径已经接上了：
     - `daemon/src/commands.rs:659-689`
     - `daemon/src/pass.rs:82-86`
   - 但当前 Katran 调试 artifact 反复出现：
     - `no verifier states available`
   - 说明这条 enhancement 当前在真实 corpus/runner 路径上并没有形成稳定收益

## 8. 修复方案

### 8.1 短期：让当前增强后的 daemon 在全量 corpus 上真正 hit 起来

1. 先补一轮“有诊断的全量 rerun”
   - 用当前 `performance = [map_inline, const_prop, dce]`
   - 每个程序保留 `pass_details`
   - 不要再把 `daemon_debug_stripped` 设成唯一保存形式
   - 至少要保存：
     - `sites_found`
     - `sites_applied`
     - `skip_reasons`
     - `diagnostics`
     - verifier states 是否成功捕获

2. 把 full-corpus 统计和 runtime benchmark 分开
   - 先做 compile-only / static-verify 风格的全量扫描
   - 目的只是回答：
     - 哪些对象有 `map_inline` 候选
     - 哪些 guard 最致命
   - 不要让 attach / workload / prepared-state 噪声掩盖 pass coverage

3. 把 verifier-guided key extraction 真正打通到 corpus 路径
   - 现在代码里有这个能力，但现有 Katran artifact 显示实际是 `no verifier states available`
   - 短期最值得补的不是再发明第四种 key matcher，而是确认：
     - verifier log capture 有没有成功
     - 失败时为什么失败
     - 失败比例多大

4. 优先验证高产对象，而不是盲目再跑一整轮 perf
   - 第一批建议：
     - `KubeArmor/system_monitor.bpf.o`
     - `katran/balancer.bpf.o`
     - `tracee/tracee.bpf.o`
     - `xdp_synproxy_kern.bpf.o`
     - `xdp_redirect_cpumap.bpf.o`
     - `scx_rusty_main.bpf.o`

5. 在“当前实现不改安全模型”的前提下，最现实的增益来源是：
   - 真正启用 verifier-guided keys
   - 吃掉更多 constant-array / percpu-array 站点
   - 对 frozen / `.rodata` / direct `pseudo_map_value` load 的命中单独统计

### 8.2 中期：把安全 coverage 从 `2` 站点扩回更多

1. 把 mutable writeback guard 从“按 `map_id` 的程序级 veto”收窄到 site-local / alias-local
   - 这是最重要的一条
   - 当前 guard 过度惩罚了“同一张 map 上既有写路径也有只读路径”的程序

2. 区分“会被程序写回的 state map”和“运行时只读的 config/control map”
   - 对于后者，即使 map 不是 frozen，也可以引入更细粒度的安全条件
   - Katran 当前 surviving 的 `ctl_array` 就说明这类 map 最有收益

3. 放宽 `r0` use classifier
   - 允许更多 benign control-flow / pointer-shaping use
   - 前提是最终 dereference 仍然是固定偏移、可证明安全的 scalar load

4. 为 `PERCPU_ARRAY` 提供比“全 CPU slot 完全相等”更细的安全模型
   - 当前 guard 太强，直接压掉了大量 corpus site
   - 可以考虑：
     - 明确只对语义上配置型的 percpu map 做统一性保证
     - 或引入版本化 invalidation，而不是一次性要求所有 slot 永远一致

5. 把“diagnostics 可追溯”变成所有 full-corpus rerun 的硬要求
   - 否则下一次再出现 `0 hit`，又会回到现在这种“只能从 stale metadata 反推”的状态

## 9. 最终判断

这次调查后的结论是：

- “`map_inline` 在最后一份全量 corpus run 上 0 hit”这个现象本身是真的。
- 但它的首要根因不是“当前增强后的 daemon 依然完全打不中 real corpus”，而是：
  - 最后的 full-corpus artifact 已经过时
  - 并且没有保留足够诊断来解释今天的实现
- 从当前源码和离线对象分布看，真正拖住 coverage 的是：
  - 程序级 mutable-map writeback veto
  - 过窄的 use classifier
  - verifier-guided key extraction 在真实路径上没有形成稳定收益

换句话说：

- 现在最该修的不是“再猜一次为什么 full artifact 是 0”
- 而是先补一轮带完整 `pass_details` 的全量 rerun，然后优先改掉那条把安全 coverage 压到 `2` 的 map-wide mutable-write guard
