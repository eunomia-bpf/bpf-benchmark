# Micro Benchmark 进一步优化分析（2026-03-18）

基于以下输入整理：

- 当前权威状态：2026-03-18，`10 iter / 5 warmup / 1000 repeat`
- 参考文档：`docs/kernel-jit-optimization-plan.md`
- 参考文档：`docs/tmp/micro_performance_improvement_analysis.md`
- 全量 scanner census：对 `config/micro_pure_jit.yaml` 中全部 `62` 个 benchmark 逐个执行 `scanner/build/bpf-jit-scanner scan --all --json`
- 当前 repo policy：`micro/policies/*.yaml`

---

## 0. 执行摘要

我认为下一轮进一步提高 micro benchmark performance，最值得做的不是继续“盲扩 coverage”，而是分三层推进：

1. **先处理当前两个 loss**
   - `cmov_select`：当前 manifest **已经没有 cmov site**，只有 `rotate=4, wide=6`。也就是说这个 benchmark 现在被 `rotate-only` policy 优化的是“副作用 rotate”，不是它本来要测的 select/cmov。这个 loss 很可能不是“rotate form 坏”，而是 **policy 选错了对象**。
   - `mixed_alu_mem`：当前是 `1 wide + 2 extract`。从 site 位置和旧 ablation 看，**真正有风险的是 2 个 hot extract**，不是那个单独的 wide site。

2. **再扩剩余的高价值 rotate 空白**
   - 真正值得优先试的不是 `packet_rss_hash`，而是：
     - `imm64_storm`：`rotate=64`
     - `mega_basic_block_2048`：`rotate=512`
     - `branch_fanout_32`：`rotate=8`
   - 其中 `imm64_storm` 是我认为最像 `rotate64_hash` / `rotate_dense` 的新增目标；`mega_basic_block_2048` site 数最多，但需要分 budget 验证，不应直接 all-in。

3. **不要把 WIDE_MEM 当成“只要有 site 就该开”的 family**
   - 当前数据支持的结论是：**WIDE 是强上下文敏感 form**。
   - `bounds_ladder` 和 `bpf_call_chain` 现在是正向，但这并**不能**证明 wide 本身正向，因为它们的 wide site 很靠前，属于 header/setup；真正的正向更可能来自别的 form 或布局效应。

如果只看 applied-only geomean，粗估：

- 只清掉 `cmov_select`：约 `1.118x -> 1.139x`
- 只清掉 `mixed_alu_mem`：约 `1.118x -> 1.140x`
- 两个都清掉：约 `1.118x -> 1.167x`

这三个数字是按当前 9 个 applied benchmark 的公开 gain 粗估，不是新实测值；**是否真的改 policy 仍应先做 subset VM 验证**。

---

## 1. 先看全局：当前 family 覆盖分布

### 1.1 Scanner 发现的总 site 分布

| Family | 有 site 的 benchmark 数 | 总 site 数 |
|---|---:|---:|
| `rotate` | 16 | 1020 |
| `wide` | 51 | 146 |
| `cmov` | 8 | 150 |
| `branch-flip` | 4 | 270 |
| `extract` | 5 | 525 |
| `lea` | 5 | 13 |
| `endian` | 1 | 256 |

### 1.2 当前 policy 实际选中的 site

| Family | 被选中的 benchmark 数 | 被选中的 site 数 |
|---|---:|---:|
| `rotate` | 6 | 416 |
| `wide` | 3 | 5 |
| `cmov` | 1 | 2 |
| `extract` | 1 | 2 |

关键信号：

- 当前 repo 的稳定收益几乎全部来自 `rotate`
- `rotate` 仍然只覆盖了 `416 / 1020 = 40.8%` 的 scanner sites
- `wide` 虽然在 `51` 个 benchmark 里都能扫到，但大多数只是稀疏、小收益、上下文敏感 site
- `cmov_select` 当前根本没有 `cmov` site；这说明“benchmark 名字”和“当前 manifest”已经不一致

---

## 2. 还有哪些 non-applied benchmark 有 rotate site 可以新增？

### 2.1 全部 non-applied rotate benchmark

| Benchmark | Rotate sites | 其他 family | 备注 |
|---|---:|---|---|
| `mega_basic_block_2048` | 512 | `wide=8` | 超大直线热块 |
| `imm64_storm` | 64 | `wide=4` | 热块、staged、很像 rotate 类 winner |
| `packet_rss_hash` | 11 | `wide=2` | packet-backed、`rotate-32`、此前不稳定 |
| `branch_fanout_32` | 8 | `wide=1` | staged、`rotate-64`、此前不稳定 |
| `memcmp_prefix_64` | 3 | `wide=1` | 已验证为负例 |
| `code_clone_8` | 2 | `wide=1` | rotate 太少，且 llvmbpf 还更慢 |
| `alu32_64_pingpong` | 1 | `wide=3` | rotate 不是主矛盾 |
| `code_clone_2` | 1 | `wide=1` | rotate 太少 |
| `fixed_loop_large` | 1 | `wide=3` | rotate 太少 |
| `fixed_loop_small` | 1 | `wide=3` | rotate 太少 |

### 2.2 优先级排序

#### P0：`imm64_storm`

- scanner：`rotate=64, wide=4`
- 结构：`micro/programs/imm64_storm.bpf.c` 是 **完全 staged、热直线 block、纯 rotate-64**
- llvmbpf/kernel adjusted exec ratio：约 `0.740`
- 这类程序和当前最强 winner 的相似度最高：
  - `rotate_dense`：大量 hot `rotate-64`
  - `rotate64_hash`：大量 hot `rotate-64`
- 它没有 packet path、没有 branch predictability 干扰，也没有 same-size 问题

结论：

- **这是当前最值得新增的 rotate benchmark**
- 预期 benchmark-level gain：保守估计 `+10% ~ +20%`
- 预期 applied-only 提升：如果它能落到 `0.80x ~ 0.85x`，粗估 applied-only 可从 `1.118x` 提升到约 `1.124x ~ 1.131x`
- **必须 VM 验证**

#### P1：`mega_basic_block_2048`

- scanner：`rotate=512, wide=8`
- 结构：`micro/programs/mega_basic_block_2048.bpf.c` 是 **巨型 straight-line basic block**
- 优点：site 极多，且全部在热路径
- 风险：
  - 当前默认 cost model 的 `max-sites-per-form=128` 会把这类程序视为高风险
  - llvmbpf/kernel adjusted exec ratio 只有约 `0.915`，说明虽然 rotate 很多，但**可恢复 headroom 并不像 site 数那样夸张**

结论：

- 不建议直接结论为“512 site 一定是大赢”
- 正确做法是 **分 budget 验证**：`64 -> 128 -> 256 -> 512`
- 我认为这比 `packet_rss_hash` 更值得做，但必须带预算，不要 full 512 直接上 repo policy
- 预期 benchmark-level gain：`+5% ~ +15%` 更现实
- **必须 VM 验证**

#### P1：`branch_fanout_32`

- scanner：`rotate=8, wide=1`
- 结构：`micro/programs/branch_fanout_32.bpf.c` 是 staged 输入，8 个 `rotate-64` 在 switch body 内
- llvmbpf/kernel adjusted exec ratio：约 `0.716`
- 之前试过一次，但被标注为“不稳定”

结论：

- 这不是 coverage 上最大的洞，但它是**低成本重试**对象
- 之前不稳定很可能和旧 VM 精度有关；现在 authoritative 配置已经更干净
- 预期 benchmark-level gain：`+3% ~ +8%`
- 对 applied-only aggregate 的边际贡献不大，但如果只需写一个小 YAML，这个实验性价比高
- **必须 VM 验证**

#### P2：`packet_rss_hash`

- scanner：`rotate=11, wide=2`
- 结构：packet-backed，且 rotate 是 `rotate-32`
- llvmbpf/kernel raw exec ratio：约 `1.2`，并不显示 kernel 落后
- 之前已经验证过“不稳定”

结论：

- **短期不建议继续投入**
- 它的问题不只是 site 少，而是：
  - packet-backed
  - 基线太短
  - 当前 rotate win 的主要证据都来自 `rotate-64`，不是 `rotate-32`

#### P3：其余 rotate 空白

- `fixed_loop_small`
- `fixed_loop_large`
- `code_clone_2`
- `code_clone_8`
- `alu32_64_pingpong`

结论：

- rotate site 太少，不足以显著改变 benchmark
- 这些 benchmark 即使有 llvmbpf gap，gap 也明显不主要来自 rotate
- 优先级低于 `imm64_storm` / `mega_basic_block_2048` / `branch_fanout_32`

---

## 3. 两个 current loss 能怎么修？

### 3.1 `cmov_select -3.4%`：核心问题不是“rotate 差”，而是“现在根本没有 cmov site”

当前 scanner census：

- `cmov_select`: `rotate=4, wide=6`
- `cmov=0`

这意味着：

- 这个 benchmark 名字虽然叫 `cmov_select`
- 但 **当前 BPF object/manifest 已经不再提供 `cond-select` canonical site**
- 现在的 `rotate-only` policy 优化的是 `acc = micro_rotl64(...)` 这种副作用 rotate，而不是 select 本体

从源码也能看出来：

- `micro/programs/cmov_select.bpf.c` 的 benchmark intent 是 `cmov_select_pick()`
- 但当前 scanner 没有在 manifest 中恢复出对应 `cmov` site

所以当前 loss 的合理解释是：

- 不是“rotate form 在这个 benchmark 上证明有害”
- 而是“**这个 benchmark 现在不适合作为 rotate benchmark**”

我的判断：

1. **最稳妥修法**：直接清掉 `cmov_select`
   - 立刻把错误对象从 applied set 里移走
   - 粗估 applied-only：`1.118x -> 1.139x`
2. **更好的长期修法**：恢复它的 `cmov` canonical site
   - 要么调整 benchmark 代码，让 select pattern 再次变成 scanner 可识别的 `cond-select-64`
   - 要么扩 scanner pattern，让 `cmov_select_pick` 这种 noinline/select 子程序重新命中

结论：

- **短期 policy 建议**：`cmov_select -> sites: []`
- **长期系统建议**：不要接受“cmov benchmark 只能靠 rotate-only 勉强上车”的状态；这会污染 family attribution
- **需要 VM 验证**：是，但我认为它是当前两个 loss 里更接近“应当清掉”的那个

### 3.2 `mixed_alu_mem -4.0%`：更像 `extract` 拖累，而不是 `wide` 拖累

当前 manifest：

- `wide=1`，site 在 `insn 10`
- `extract=2`，site 在 `insn 73` 和 `insn 228`

从源码看：

- `wide=1` 很靠前，对应 header/setup 阶段
- 两个 `extract` 更靠后，落在主循环热路径

把这个结果和旧 per-form ablation 对上，可以得到很清晰的解释：

- `mixed_alu_mem` 的 `wide-only` 曾经是正向
- `extract-only` 是负向
- 现在 combined `wide + extract` 变成负向，非常像 **hot extract 把 sparse wide 的收益吃掉**

所以这里最可能的真实结论不是“整个 benchmark 不该优化”，而是：

- **当前 `extract` 子类过粗**
- 需要把 `with-copy` 与 `without-copy`、hot-loop 与 non-hot-path 区分开

短期上，我给两个建议：

1. **保守策略**：直接清掉 `mixed_alu_mem`
   - 粗估 applied-only：`1.118x -> 1.140x`
2. **更好的策略**：只保留 `wide=1`，移除两个 `extract`
   - 这需要高精度 subset rerun 确认
   - 之前做过一次 3-iteration follow-up，方向看起来更好，但噪声太大，不能作为 repo 依据

结论：

- 如果目标是“下一轮先把 applied-only 拉高”，最简单的是 **直接清掉**
- 如果目标是“保住 benchmark 数量同时尽量正向”，应该 **专门跑 `wide-only` vs `empty`**
- **需要 VM 验证**

### 3.3 如果把两个 loss 都清掉，值不值得？

粗估：

- 当前：`9 applied`, `1.118x`
- 清一个 loss：约 `1.139x`
- 两个都清：约 `7 applied`, `1.167x`

我的判断：

- **从 applied-only headline 看，非常值得**
- **从 paper narrative 看，要注意 applied 数下降**
- 因此理想路线不是只清，而是：
  - 先把这两个问题 bench 处理掉
  - 同时补进 `imm64_storm` 或 `branch_fanout_32`

---

## 4. 已清掉的 9 个 benchmark，有哪些可能用别的 form 恢复？

### 4.1 值得恢复尝试的

#### `log2_fold`：优先试 `cmov-only`

当前 scanner：

- `cmov=8`
- `wide=3`

当前源码 `micro/programs/log2_fold.bpf.c` 的热路径是一个明显的 compare/shift ladder，`cmov` 在语义上比 `wide` 更像真正的优化对象。

为什么它值得重试：

- 当前 policy 清空，是因为“3 个 wide 在最新 authoritative run 回归”
- 但这并不等于 “8 个 cmov 也不行”
- 旧材料里关于 `log2_fold` 的叙述存在前后不一致，说明这类 site 在不同 build / policy 下有漂移

建议：

- 跑 `empty` / `wide-only` / `cmov-only`
- 不建议直接回 `cmov+wide`

优先级：**中**

#### `switch_dispatch`：优先试 `wide-only`

当前 scanner：

- `cmov=1`
- `wide=2`

旧 per-form ablation 里：

- `wide-only` 是正向
- `cmov-only` 是负向

所以它其实不是“没法恢复”，而是“**之前 mix 选错了**”。

建议：

- 跑 `empty` / `wide-only`
- 不要再先试 `cmov+wide`

优先级：**中**

#### `binary_search`：可以试 `cmov-only`，但预期收益很小

当前 scanner：

- `cmov=1`
- `wide=2`

旧 per-form ablation 里：

- `cmov-only` 约中性略正
- `wide-only` 明显负

建议：

- 如果要恢复，只试 `cmov-only`
- 但这更像“补 coverage”，不是 headline 增益来源

优先级：**低到中**

### 4.2 不值得优先恢复的

#### `memcmp_prefix_64`

- 只有 `rotate=3`
- 已经是明确负例
- llvmbpf gap 很大，但 gap 显然不主要来自这 3 个 rotate

结论：**继续保持清空**

#### `branch_flip_dense`

- 只有 `branch-flip=255`
- same-size
- 没有 profile，就没有足够信息做“只开一部分 site”的好选择

结论：**继续保持清空**

#### `branch_dense`

- `branch-flip=4, cmov=1, wide=2`
- 旧 per-form 数据都只是非常轻微的正向/负向

结论：

- 可以做 `branch-flip-only` 或 `wide-only` 的小实验
- 但 aggregate 价值很低，不应排在前面

#### `multi_acc_4` / `multi_acc_8`

- 当前 empty policy 自己都还在飘
- `multi_acc_4` 甚至在 `sites=[]` 下还能出现明显偏移

结论：

- 这两个 benchmark 目前更像 measurement-noise detector，不像稳定优化目标
- 先不投时间

#### `addr_calc_stride`

- `lea=8`
- 历史材料里有过明显正向，也有过明显负向
- 源码确实是 LEA 该发挥的典型场景，但也确实可能触发 AGU 竞争

结论：

- 这是“可以做高精度 recheck”的对象
- 但不应排在 rotate 扩展前面

---

## 5. WIDE_MEM 到底在哪些 benchmark 上是真正正向的？

### 5.1 先给结论

**当前不能把 `bpf_call_chain + bounds_ladder` 的正向，解读成“WIDE_MEM family 整体正向”。**

更准确的说法是：

- `WIDE_MEM` 只有在**命中重复执行的 load-recompose 热路径**时，才可能稳定正向
- 如果它只命中 header/setup，那 benchmark-level 正向往往不可信，容易被其他 form 或布局效应掩盖

### 5.2 为什么 `bpf_call_chain` 现在是正向，但不能据此推广 WIDE？

当前 manifest：

- `bpf_call_chain`: `wide=2`, `cmov=1`
- 当前 policy 已经去掉 `cmov`，只保留 `wide=2`

但源码 `micro/programs/bpf_call_chain.bpf.c` 很清楚：

- 这两个 wide site 对应的是循环前的一次性 `acc` / `mix` 初始读入
- 真正 64 轮热路径在三个子函数里

所以：

- 现在看到的 `+6.1%`，**不太可能主要来自这两个冷的 wide site**
- 更可能是布局、调用边界、或 measurement spread 的综合结果

结论：

- `bpf_call_chain` 现在可以暂时保留
- 但它**不能**作为“WIDE family 可以扩”的依据

### 5.3 为什么 `bounds_ladder` 也是正向，但核心更像 CMOV 白名单，而不是 WIDE 白名单？

当前 manifest：

- `wide=2`
- `cmov=2`

源码 `micro/programs/bounds_ladder.bpf.c` 里：

- `wide` 是最开始对 `record_count` / `record_size` 的 header 读取
- `cmov` 则更接近 loop 内两个真正的 select 点

旧 per-form ablation 也支持这个判断：

- `cmov-only` 是正向
- `wide-only` 反而是轻微负向

结论：

- `bounds_ladder` 的正向应该归因于“**稀疏、热路径上的 cmov 白名单**”
- 不是 WIDE 的通用成功案例

### 5.4 真正该怎么理解 WIDE 的适用边界？

从目前材料看，WIDE 更像下面三类中的第 1 类：

1. **loop body 中反复执行的 byte-ladder**
2. 稀疏 setup load，但刚好影响后续布局
3. 纯噪声 / 对齐效应

第 1 类才应该进长期 policy。

因此：

- `switch_dispatch` 的 `wide-only` 值得重测
- `log2_fold` 的 `wide-only` 可以复测，但不应默认乐观
- `bpf_call_chain` 和 `bounds_ladder` 不应被用来扩 WIDE family policy

### 5.5 我的 policy 建议

- **WIDE 默认继续保守**
- 只对白名单 benchmark 开
- 不要因为 scanner 在 `51` 个 benchmark 上都找到了 wide，就尝试扩 coverage

---

## 6. ENDIAN_FUSION / BRANCH_FLIP 这些 same-size form 真的不能优化吗？

### 6.1 `ENDIAN_FUSION`

当前 census：

- `endian_swap_dense`: `endian=256`

这类 site 的难点不是“scanner 没找到”，而是：

- `LDX + BSWAP32` 与 `MOVBE` 经常是 **same-size**
- 所以收益如果存在，也不是来自 code size，而是来自 uop / load-use / backend behavior
- 这就天然更 **CPU-specific**

我认为这里不应做“部分 site apply”：

- `endian_swap_dense` 是一个均匀、unrolled、密集的 hot loop
- 256 个 site 基本没有明显冷热之分
- 如果 `MOVBE` 在当前 CPU 上真有利，应该是 **all-or-none**
- 随机只开一部分 site，大概率只会把信号稀释掉

结论：

- `ENDIAN_FUSION` **不是完全没价值**
- 但正确策略不是“少量 site 试试看”，而是“**CPU-gated 的 all-or-none 验证**”
- 在没有新实测前，repo 默认继续 skip 没问题

### 6.2 `BRANCH_FLIP`

当前 census：

- `branch_flip_dense`: `branch-flip=255`
- `branch_dense`: `branch-flip=4`
- `large_mixed_500`: `branch-flip=3`
- `large_mixed_1000`: `branch-flip=8`

我对 `BRANCH_FLIP` 的判断是：

- 这个 family 不是“按静态 site 数量就能决定”的 form
- 真正决定因素是 **branch bias / predictability**
- scanner 现在没有 profile，就不知道哪几个 branch 值得 flip

所以：

- `branch_flip_dense` 上做“只 apply 少量 site”在理论上是可能的
- 但如果没有 profile 指导，这个 partial selection 本质上是 blind

结论：

- `BRANCH_FLIP` 的未来方向不是调 site 数，而是 **加 profile / bias 信息**
- 在没有 profile 前，不建议投入太多精力在 dense blind branch-flip 上

---

## 7. 我建议怎么调 policy

### 7.1 立即可考虑的 policy 方向

| 优先级 | Benchmark / Policy | 建议 | 原因 | 预期 |
|---|---|---|---|---|
| P0 | `cmov_select` | `sites: []` | 当前 manifest 没有 `cmov`，rotate-only 优化错对象 | applied-only 粗估到 `~1.139x` |
| P0 | `mixed_alu_mem` | 先测 `wide-only`；不稳就清空 | 2 个 hot extract 更像真实拖累 | applied-only 粗估到 `~1.140x` |
| P0 | `imm64_storm` | 新增 `rotate-only` | 64 个热 `rotate-64`，最像现有 rotate winner | 单 benchmark 高概率正向 |
| P1 | `mega_basic_block_2048` | 分 budget 试 `64/128/256/512 rotate` | 512 个热 rotate，但 headroom 没 site 数看起来那么大 | 可能新增一个中到强 winner |
| P1 | `branch_fanout_32` | 重试 `rotate-only` | staged、8 个 `rotate-64`、重试成本低 | 可能新增一个小到中 winner |
| P2 | `log2_fold` | 只试 `cmov-only` 与 `wide-only` | 当前清空只说明旧 mix 不行，不说明 cmov-only 不行 | benchmark-level 小到中提升 |
| P2 | `switch_dispatch` | 只试 `wide-only` | 旧 ablation 指向 wide-only，而不是 cmov+wide | benchmark-level 小到中提升 |
| P3 | `binary_search` | 如要恢复，只试 `cmov-only` | wide-only 明确差 | aggregate 贡献很小 |

### 7.2 不建议的 policy 方向

| Benchmark / Family | 不建议原因 |
|---|---|
| `packet_rss_hash` / `rotate` | packet-backed + 基线太短 + `rotate-32`，当前不稳定 |
| `memcmp_prefix_64` / `rotate` | 已经是明确负例 |
| `branch_flip_dense` / `branch-flip` | 没有 profile，partial apply 也是 blind |
| `bpf_call_chain` / 更多 `wide` | 当前正向不应被解读为 wide family 可扩 |
| `bounds_ladder` / 更多 `wide` | 当前正向核心更像 cmov 白名单，不是 wide 白名单 |

### 7.3 需要改的不只是 YAML，还包括 policy 规则本身

我建议把当前“一个通用 cost model”改成更 family-aware 的规则：

1. `ROTATE`
   - 不应继续沿用全 family 共用的 `max-sites-per-form=128`
   - rotate 是 code-shrinking family，site 数多不等于应该默认判死刑
   - 建议：**rotate 单独允许更高 budget**

2. `WIDE`
   - 默认继续保守
   - 只对白名单 benchmark 开
   - 不做“scanner 找到就加”

3. `CMOV`
   - 继续默认保守
   - 只白名单 `bounds_ladder` 这类稀疏 hot select
   - `log2_fold` 是否能进白名单，需要当前 build 下重新 isolate

4. `EXTRACT`
   - 应该拆分子类：`with-copy` vs `without-copy`
   - 当前 `mixed_alu_mem` 与 `extract_dense` 的分化已经足够说明这个拆分是必要的

5. `ENDIAN` / `BRANCH_FLIP`
   - 继续默认 skip
   - 如果要重新开放，必须带 CPU gating 或 profile 信息

---

## 8. 有没有“新的 canonical form”可以在现有 benchmark 上开启？

严格说，当前不是缺“大量新 family”，而是缺 **更细粒度的子类**。我认为最有价值的不是再造一个全新 family，而是下面 4 个 refinement：

### 8.1 `EXTRACT_WITH_COPY` vs `EXTRACT_WITHOUT_COPY`

这是最明确的一个。

现状：

- `mixed_alu_mem`：稀疏 extract，行为与 `extract_dense` 完全不同
- `extract_dense`：512 site 的 dense extract 明显不适合当前 emitter/policy

如果 scanner/policy 不区分这两个子类，`extract` family 永远会被混合统计污染。

### 8.2 `ROTATE_64` vs `ROTATE_32`

现状：

- 当前稳定 winner 基本都是 `rotate-64`
- `packet_rss_hash` 的 `rotate-32` 目前没有稳定正证据

这不一定说明 `rotate-32` 一定不行，但至少说明它不该和 `rotate-64` 混成同一个默认 policy bucket。

### 8.3 `WIDE_SETUP` vs `WIDE_LOOP`

现状：

- `bpf_call_chain` / `bounds_ladder` 里 wide 很靠前，像 setup
- `switch_dispatch` / `log2_fold` 的 wide 更可能接近循环体

如果未来要让 WIDE 变成可扩 family，就需要把“只影响一次的 header load”和“每轮都执行的 load ladder”拆开。

### 8.4 `CMOV_SELECT` benchmark 的 scanner 可见性修复

`cmov_select` 当前 manifest 没有 cmov site，这本身就是一个信号：

- 不是说系统没有 cmov form
- 而是当前 benchmark 代码形态没有再命中 scanner pattern

这件事应该作为 scanner/benchmark 协同修复事项，而不是继续用 rotate-only 充数。

---

## 9. 测量精度还能怎么提高？

### 9.1 当前 full-suite 配置已经足够做 headline

`10 iter / 5 warmup / 1000 repeat` 的关键成就是：

- `non-applied geomean` 已经接近 `1.0`
- 说明 full-suite headline 基本干净了

所以：

- **不建议为了全套 62 benchmark 再把 authoritative 配置整体拉高**
- 成本会明显上升，但边际收益有限

### 9.2 但它还不够分辨 `-3% ~ -4%` 的小 loss

以当前样本离散度看：

- `cmov_select` 的 kernel / recompile 样本 spread 和它的 3.4% loss 是同一个量级
- `mixed_alu_mem` 的 4% loss 也没有大到足够一眼判死

所以对这种“方向重要、幅度不大”的 benchmark，应改成 **subset 高精度验证**，而不是继续靠 full suite。

### 9.3 我建议的验证策略

#### Full suite authoritative

- 保持：`10 iter / 5 warmup / 1000 repeat`

#### Targeted subset validation

针对单 benchmark policy 决策，建议：

- `20 iter / 10 warmup / 2000 repeat`
- benchmark 只跑 1~6 个目标对象，不跑全套 62

最值得做的 subset matrix：

1. `cmov_select`
   - `empty`
   - `current rotate-only`

2. `mixed_alu_mem`
   - `empty`
   - `wide-only`
   - `current wide+extract`

3. `log2_fold`
   - `empty`
   - `wide-only`
   - `cmov-only`

4. `switch_dispatch`
   - `empty`
   - `wide-only`
   - `cmov-only`

5. `imm64_storm`
   - `empty`
   - `rotate-only`

6. `mega_basic_block_2048`
   - `empty`
   - `rotate budget 64`
   - `rotate budget 128`
   - `rotate budget 256`
   - `rotate budget 512`

### 9.4 政策变更门槛

我建议下一轮统一用下面的 gate：

1. 目标 benchmark 在高精度 subset run 中方向稳定
2. 至少 2 次 rerun 同号
3. 如果预期 gain/loss 小于 5%，不只看单次中位数
4. 不把 packet-backed、sub-50ns benchmark 当成 repo policy 的主要判据

---

## 10. 最后的结论：下一轮最有价值的动作

如果目标是“**尽快继续拉高 applied-only，同时不把结论做脏**”，我建议的顺序是：

1. **高精度验证并大概率清掉 `cmov_select`**
2. **高精度验证 `mixed_alu_mem` 的 `wide-only`；不稳就清掉**
3. **新增 `imm64_storm rotate-only`**
4. **对 `mega_basic_block_2048` 做 rotate budget sweep**
5. **重试 `branch_fanout_32 rotate-only`**
6. **如果还有时间，再做 `log2_fold cmov-only` 和 `switch_dispatch wide-only`**

如果目标是“**最大化下一版 applied-only headline**”，那最可能的路线是：

- 先把两个 current loss 移出 applied set
- 再补进 `imm64_storm`
- 如果 `mega_basic_block_2048` 有一个 budget 稳定正向，再把它补进来

我对下一轮最乐观但仍合理的预期是：

- applied-only 从当前 `1.118x`
- 先到 `~1.14x`（清一个 loss）
- 再到 `~1.16x`（清两个 loss）
- 如果新增一个强 rotate winner，再到 `~1.17x ~ 1.19x`

其中真正高价值、最值得优先花时间验证的，不是 `packet_rss_hash`，而是：

- `imm64_storm`
- `mega_basic_block_2048`
- `cmov_select` 的退出/重做
- `mixed_alu_mem` 的 extract 拆分

---

## Appendix A. 62 个 benchmark 的 per-family site 分布

| Benchmark | Scanner site distribution |
|---|---|
| `simple` | no sites |
| `simple_packet` | no sites |
| `memory_pair_sum` | wide=2 |
| `bitcount` | wide=2 |
| `log2_fold` | cmov=8, wide=3 |
| `dep_chain_short` | wide=2 |
| `dep_chain_long` | wide=2 |
| `binary_search` | cmov=1, wide=2 |
| `branch_layout` | wide=2 |
| `switch_dispatch` | cmov=1, wide=2 |
| `branch_dense` | branch-flip=4, cmov=1, wide=2 |
| `cmov_select` | rotate=4, wide=6 |
| `cmov_dense` | cmov=32, rotate=26 |
| `checksum` | wide=2 |
| `load_word32` | wide=2 |
| `load_byte` | wide=2 |
| `load_byte_recompose` | wide=1 |
| `load_native_u64` | no sites |
| `packet_parse` | wide=5 |
| `bounds_ladder` | cmov=2, wide=2 |
| `bounds_check_heavy` | extract=1, wide=13 |
| `stride_load_4` | lea=1, wide=2 |
| `stride_load_16` | lea=1, wide=2 |
| `mixed_alu_mem` | extract=2, wide=1 |
| `spill_pressure` | wide=2 |
| `multi_acc_4` | lea=1, wide=2 |
| `multi_acc_8` | lea=2, wide=2 |
| `fibonacci_iter` | wide=4 |
| `fibonacci_iter_packet` | wide=4 |
| `fixed_loop_small` | rotate=1, wide=3 |
| `fixed_loop_large` | rotate=1, wide=3 |
| `nested_loop_2` | wide=3 |
| `nested_loop_3` | wide=3 |
| `code_clone_2` | rotate=1, wide=1 |
| `code_clone_8` | rotate=2, wide=1 |
| `large_mixed_500` | branch-flip=3, rotate=7, wide=1 |
| `large_mixed_1000` | branch-flip=8, rotate=7, wide=1 |
| `bpf_call_chain` | cmov=1, wide=2 |
| `memcmp_prefix_64` | rotate=3, wide=1 |
| `packet_parse_vlans_tcpopts` | extract=1, wide=6 |
| `local_call_fanout` | wide=3 |
| `packet_rss_hash` | rotate=11, wide=2 |
| `imm64_storm` | rotate=64, wide=4 |
| `alu32_64_pingpong` | rotate=1, wide=3 |
| `branch_fanout_32` | rotate=8, wide=1 |
| `deep_guard_tree_8` | wide=2 |
| `mega_basic_block_2048` | rotate=512, wide=8 |
| `rotate64_hash` | rotate=116, wide=7 |
| `packet_redundant_bounds` | wide=8 |
| `const_fold_chain` | wide=2 |
| `struct_field_cluster` | no sites |
| `bitfield_extract` | extract=9, wide=2 |
| `smallmul_strength_reduce` | wide=2 |
| `cond_select_dense` | cmov=104 |
| `rotate_dense` | rotate=256 |
| `addr_calc_stride` | lea=8 |
| `extract_dense` | extract=512 |
| `endian_swap_dense` | endian=256 |
| `branch_flip_dense` | branch-flip=255 |
| `tc_bitcount` | wide=2 |
| `tc_checksum` | wide=2 |
| `cgroup_hash_chain` | wide=2 |
