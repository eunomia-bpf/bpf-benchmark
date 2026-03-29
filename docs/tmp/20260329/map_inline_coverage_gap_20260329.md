# `map_inline` 覆盖差距调研

日期：2026-03-29

## 结论摘要

按 `corpus/build` 全量对象做离线统计，`map_inline` 的覆盖差距很大，但主因不只是一条：

1. `corpus/build` 里一共有 17,321 个原始 `bpf_map_lookup_elem` helper call。按当前 `find_map_lookup_sites()` 能真正识别成候选 site 的有 14,679 个，占原始 helper call 的 84.7%。
2. 当前 `MapInlinePass` fixed-point 最终实际命中 1,629 个 site，只占原始 helper call 的 9.4%，占 recognized site 的 11.1%。
3. 动态 key 确实是第一大 blocker，但不是唯一大头：
   - 按所有 recognized site 算，动态 key site 有 8,649 个，占 58.9%。
   - 按“map type 已经进入 v1 支持集”的 site 算，动态 key skip 有 5,264 个，占 supported site 的 49.1%。
4. 即使只看“map type 支持 + key 已经是常量”的 5,456 个 site，最终也只命中 1,629 个，命中率 29.9%。剩余缺口主要不是 key，而是返回值 use pattern 不满足 `fixed-offset scalar loads only`。
5. 按首轮 source-order skip reason 归一化后，前三大原因分别是：
   - `lookup key is not a constant stack or pseudo-map-value materialization`: 5,264
   - `map type ... not inlineable in v1`: 3,959
   - `lookup result is not consumed by fixed-offset scalar loads`: 2,883

结论上，`map_inline` 当前覆盖差距更准确的描述是：

- 原始 corpus upper bound 很高，但先有 15.3% helper call 连 candidate site 都建不起来；
- 在能建起来的 site 里，动态 key 是第一大 blocker；
- 但即便把动态 key 全部解决，仍然会被 unsupported map type 和 fixed-load-only gate 吃掉大量站点。

## 方法和口径

- 代码阅读对象：`daemon/src/passes/map_inline.rs`
- 数据来源：`corpus/build` 里的 936 个 `.bpf.o`，共 2,092 个 BPF program
- 统计方法：
  - 用临时离线 wrapper 直接调用当前源码里的 `find_map_lookup_sites()`、`extract_site_constant_key()`、`run_map_inline_round()`、`MapInlinePass`
  - `per-site skip reason` 取的是“首轮 `run_map_inline_round(..., use_verifier_guided_keys=true)` 在原始 bytecode 上的第一个失败原因”
  - “实际命中”取的是完整 fixed-point `MapInlinePass` 的最终 `sites_applied`
- 这次没有改 repo 里的代码；临时分析工具只放在 `/tmp`
- `map lookup failed: ...` 里包含 map id / key 值，统计时按一类归一化成 `map lookup failed`

一个重要 caveat：

- corpus 级别没有配套的 live map 内容，也没有全量 verifier state 可直接复用，所以这次 `map lookup failed` 本质上是“corpus-only 离线 mock map state 下无法取到值”的保守下界，不代表 live run 下一定不能 inline。
- 但这类 site 只占 recognized site 的 5.0%，不会改变主结论。

## 1. 总量对比

| 指标 | 数量 | 占比 |
|---|---:|---:|
| `.bpf.o` objects | 936 | - |
| BPF programs | 2,092 | - |
| 原始 `map_lookup_elem` helper call | 17,321 | 100.0% raw |
| recognized lookup sites | 14,679 | 84.7% raw |
| raw - recognized 差值 | 2,642 | 15.3% raw |
| 首轮 `map_inline` 直接命中 | 1,533 | 10.4% recognized |
| fixed-point 最终命中 | 1,629 | 11.1% recognized / 9.4% raw |
| fixed-point 相比首轮新增命中 | 96 | +6.3% hits |
| 常量 key site | 6,030 | 41.1% recognized |
| 动态 key site | 8,649 | 58.9% recognized |
| v1 支持的 map type site | 10,720 | 73.0% recognized |
| `v1 支持 + key 常量` site | 5,456 | 37.2% recognized / 50.9% supported |

两个 upper bound 都值得看：

- 如果把“theoretical upper bound”定义成 corpus 里所有原始 helper call，当前 hit rate 是 9.4%。
- 如果把 upper bound 定义成当前 pass 能识别成 candidate 的 lookup site，当前 hit rate 是 11.1%。

## 2. `map_inline.rs` 的 skip reason 逻辑

当前 `run_map_inline_round()` 的 gate 基本是 source-order 短路，顺序如下：

1. `map reference metadata unavailable`
2. `map info unavailable`
3. `map type {t} not inlineable in v1`
4. `lookup key is not a constant stack or pseudo-map-value materialization`
5. `key width {w} is smaller than map key size {k}`
6. `constant key {v} out of range for max_entries {n}`
7. `speculative map inline requires an immediate null check`
8. `lookup result is not consumed by fixed-offset scalar loads`
9. `mutable lookup result has non-load uses`
10. `failed to materialize replacement constants`
11. `site-level inline veto: ...`
12. `map lookup failed: ...`
13. `internal rewrite overlap`
14. `overlapping map inline rewrite`

这次 corpus 真正出现的只有下面几类：

- `map type ... not inlineable in v1`
- `lookup key is not a constant stack or pseudo-map-value materialization`
- `constant key ... out of range for max_entries ...`
- `speculative map inline requires an immediate null check`
- `lookup result is not consumed by fixed-offset scalar loads`
- `mutable lookup result has non-load uses`
- `map lookup failed: ...`

`map reference metadata unavailable` / `map info unavailable` / `key width smaller than map key size` / `failed to materialize replacement constants` / `site-level inline veto` / rewrite overlap 这些在这次全量 corpus 里没有出现。

## 3. 首轮 per-site skip reason 统计

下面的统计按首轮原始 site 归一化，不把 `map lookup failed: <map-id> <key>` 拆成几百个细项。

| skip reason | site 数 | 占 recognized site | 占 skipped site |
|---|---:|---:|---:|
| `lookup key is not a constant stack or pseudo-map-value materialization` | 5,264 | 35.9% | 40.0% |
| `map type not inlineable in v1` | 3,959 | 27.0% | 30.1% |
| `lookup result is not consumed by fixed-offset scalar loads` | 2,883 | 19.6% | 21.9% |
| `map lookup failed` | 738 | 5.0% | 5.6% |
| `mutable lookup result has non-load uses` | 272 | 1.9% | 2.1% |
| `constant key out of range` | 16 | 0.1% | 0.1% |
| `speculative map inline requires an immediate null check` | 14 | 0.1% | 0.1% |

三个观察：

1. 动态 key 是第一大 blocker，但只占全部 recognized site 的 35.9%，没有单独过半。
2. unsupported map type 直接吃掉了 27.0% 的 recognized site，属于“key 还没开始看就已经出局”。
3. 对已经拿到常量 key 的 supported site，`fixed-offset scalar loads only` 才是最大的剩余 gate。

## 4. unsupported map type 具体是哪些

`map type ... not inlineable in v1` 一共 3,959 个 site，主要来自这些 map type：

| map type | site 数 |
|---|---:|
| `HASH_OF_MAPS` | 1,489 |
| `ARRAY_OF_MAPS` | 718 |
| `LRU_PERCPU_HASH` | 679 |
| `PERCPU_HASH` | 671 |
| `LPM_TRIE` | 361 |
| `DEVMAP` | 24 |
| `SOCKMAP` | 10 |
| `DEVMAP_HASH` | 4 |
| `PROG_ARRAY` | 1 |
| `STACK_TRACE` | 1 |
| `XSKMAP` | 1 |

这说明 current v1 的 coverage gap 里，光是“map family 不在支持集里”就已经是一个独立的大块，不是简单的 key extraction 问题。

## 5. 动态 key 到底占多大比例

这个问题要分两个口径看：

### 5.1 对所有 recognized lookup site

- 动态 key：8,649 / 14,679 = 58.9%
- 常量 key：6,030 / 14,679 = 41.1%

这是最直观的 corpus-level 比例。

### 5.2 对 v1 已支持的 map type

先去掉 unsupported map type 后，还剩 10,720 个 supported site。

- 动态 key skip：5,264 / 10,720 = 49.1%
- 非动态 key：5,456 / 10,720 = 50.9%

这说明：

- 动态 key 在 supported site 里仍然是第一大 blocker；
- 但它也只占一半左右，不能解释全部 coverage gap。

## 6. 为什么“常量 key”还不够

把视野缩到 `map type 支持 + key 常量` 的 5,456 个 site 后，最终只命中 1,629 个，命中率 29.9%。

剩余 3,827 个 site 的主因是：

| 原因 | site 数 | 占 `supported + constant-key` |
|---|---:|---:|
| `lookup result is not consumed by fixed-offset scalar loads` | 2,883 | 52.8% |
| `map lookup failed` | 738 | 13.5% |
| `mutable lookup result has non-load uses` | 272 | 5.0% |
| `constant key out of range` | 16 | 0.3% |
| `speculative map inline requires an immediate null check` | 14 | 0.3% |
| 首轮已命中 | 1,533 | 28.1% |
| fixed-point 最终命中 | 1,629 | 29.9% |

核心结论是：

- 即使 key 变成常量，也还有大量 site 会被 use-pattern gate 卡住；
- 当前真实大坑是“返回值不是纯 fixed-offset scalar load”，而不是“key 还差一步常量传播”。

## 7. 项目分布

recognized site 最多的项目是：

| 项目 | recognized sites | 最终命中 | 命中率 |
|---|---:|---:|---:|
| `tetragon` | 5,493 | 424 | 7.7% |
| `tracee` | 2,994 | 97 | 3.2% |
| `KubeArmor` | 2,260 | 890 | 39.4% |
| `cilium` | 1,933 | 104 | 5.4% |
| `calico` | 534 | 1 | 0.2% |
| `linux-selftests` | 501 | 75 | 15.0% |

命中数高度集中：

- `KubeArmor` 一家就贡献了 890 个 hit，占全部 hit 的 54.6%
- `tetragon` 贡献 424 个，占 26.0%
- `cilium + tracee + linux-selftests` 合计再贡献 276 个

也就是说，当前 `map_inline` 的“有效覆盖”并不是均匀分布在 corpus 上，而是被少数几个项目吃掉了大部分收益。

一些项目的主导缺口也明显不同：

- `tetragon`：动态 key、unsupported map type、fixed-load gate 三者都很重
- `tracee`：`HASH_OF_MAPS` 等 unsupported map type 特别多，同时动态 key 也很重
- `KubeArmor`：命中很多，但 `map lookup failed` 也很多，说明它在 corpus-only 离线口径下对 live map 内容更敏感
- `cilium`：unsupported map type 和动态 key 都很重

## 8. raw helper call 和 recognized site 的差值

还有一层 gap 在 pass 入口之前：

- raw helper call: 17,321
- recognized site: 14,679
- 差值: 2,642 (15.3%)

差值最大的项目是：

| 项目 | raw helper call | recognized site | 差值 |
|---|---:|---:|---:|
| `tracee` | 4,555 | 2,994 | 1,561 |
| `tetragon` | 6,079 | 5,493 | 586 |
| `KubeArmor` | 2,501 | 2,260 | 241 |
| `cilium` | 2,063 | 1,933 | 130 |
| `opentelemetry-ebpf-profiler` | 76 | 9 | 67 |

所以如果后续要继续抬高 `map_inline` 的 corpus 覆盖率，除了 pass 内部 gate，本身还需要单独看一遍“为什么一部分 `map_lookup_elem` 没有进入 `find_map_lookup_sites()` 的 universe”。

## 9. 最值得优先做的事

如果目标是显著抬高真实 corpus 覆盖率，优先级大致应该是：

1. 继续提升 supported map family 覆盖，尤其是 `HASH_OF_MAPS` / `ARRAY_OF_MAPS` / `PERCPU_HASH` / `LRU_PERCPU_HASH`
2. 提升 dynamic key 识别/稳定化能力
3. 放宽或重写 `lookup result is not consumed by fixed-offset scalar loads` 这一 use-pattern gate
4. 单独补齐 raw helper call -> recognized site 的建模缺口

单做第 2 点不会解决大头问题，因为：

- unsupported map type 先吃掉了 3,959 个 site
- 就算 key 常量化了，仍然还有 2,883 个 site 会死在 fixed-load gate

## 一句话结论

`map_inline` 在真实 corpus 上的现状是：

- 上限看起来有 17k+ `map_lookup_elem`，但真正进入 pass universe 的只有 14.7k；
- 最终命中只有 1.63k；
- 动态 key 是第一大 blocker，但 unsupported map type 和 fixed-load-only use gate 加起来同样是硬伤；
- 因此 coverage gap 不是“再补一点 constant-key extraction 就能补齐”的问题，而是三块缺口叠加：candidate 识别、map family 支持、use-pattern 放宽。
