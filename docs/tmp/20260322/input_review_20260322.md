# Micro & Corpus Benchmark 输入数据审查报告

日期：2026-03-22

---

## 1. Micro Benchmark 输入概览

所有 micro benchmark 的输入由 `runner/libs/input_generators.py` 中的函数生成。每个生成器使用**固定 seed 的 LCG（线性同余生成器）**产生数据，因此：
- **完全 deterministic**：相同代码每次生成完全相同的 `.mem` 文件
- **无 Python random 模块依赖**：使用自定义 `_lcg()` 函数
- **一次生成，缓存复用**：`materialize_input()` 检查文件是否已存在，默认不重新生成

### 1.1 每个 Benchmark 的输入类型

| Benchmark | 生成器 | 输入类型 | 说明 |
|-----------|--------|----------|------|
| simple | `generate_simple` | **固定 pattern** | `bytes(range(64))`，0x00..0x3F |
| simple_packet | `generate_simple_packet` | **固定 pattern** | 同 simple |
| memory_pair_sum | `generate_memory_pair_sum` | **固定常量** | 两个 hardcoded u64 |
| bitcount | `generate_bitcount` | **LCG 伪随机** | 256 个 u64，固定 seed |
| log2_fold | `generate_log2_fold` | **LCG 伪随机** | 128 个 u64，`\|1` 确保非零 |
| dep_chain_short | `_generate_dep_chain` | **LCG 伪随机** | 64 个 u64 |
| dep_chain_long | `_generate_dep_chain` | **LCG 伪随机** | 256 个 u64 |
| binary_search | `generate_binary_search` | **结构化** | 32 个排序整数 + 16 个 query（1/3 命中, 2/3 未命中） |
| **branch_layout** | `generate_branch_layout` | **偏斜分布** | 432 值：每 10 个有 1 个 > threshold（hot path 90%, cold 10%） |
| **switch_dispatch** | `generate_switch_dispatch` | **LCG 伪随机** | 128 个 6-bit 值 (0..63)，均匀分布 |
| **branch_dense** | `generate_branch_dense` | **偏斜分布** | 128 个 u32：每 5 个有 1 个 > threshold（hot 80%, cold 20%） |
| **cmov_select** | `generate_cmov_select` | **交替 pattern** | lhs/rhs 交替：偶数索引 lhs<rhs，奇数 lhs>rhs → 50/50 分支 |
| **cmov_dense** | `generate_cmov_dense` | **LCG 伪随机** | 4 个 32-元素 u64 数组，比较结果取决于 LCG 值 |
| **cond_select_dense** | `generate_cond_select_dense` | **交替 pattern** | 偶数索引 lhs>rhs，奇数 lhs<rhs → 严格 50/50 交替 |
| **branch_flip_dense** | `generate_branch_flip_dense` | **LCG 伪随机** | 256 个 u64，每个位测试由 index-dependent mask 决定 |
| **branch_fanout_32** | `generate_branch_fanout_32` | **循环覆盖** | 128 值，tag 从 32 个候选中按 `(i*9+5) % 32` 循环选取 |
| **deep_guard_tree_8** | `generate_deep_guard_tree_8` | **循环 pattern** | 32 条记录，`leaf = index % 9` 确定哪条路径 |
| checksum | `generate_checksum` | **LCG 伪随机** | 32 轮 × 512 个 u16 |
| fibonacci_iter | `generate_fibonacci_iter` | **固定常量** | rounds + mix + seed 三个值 |
| fixed_loop_small/large | 对应 generator | **固定常量** | rounds + mix + seed |
| multi_acc_4/8 | `_generate_multi_acc` | **LCG 伪随机** | 128 个 u64 |
| stride_load_4/16 | `_generate_stride_load` | **LCG 伪随机** | 128 个 u64 |
| code_clone_2/8 | `_generate_code_clone` | **LCG 伪随机** | 128 个 u64 |
| large_mixed_500/1000 | `_generate_large_mixed` | **LCG 伪随机** | 32 个 u64 |
| nested_loop_2/3 | 对应 generator | **LCG 伪随机** | outer×inner 个 u64 |
| mixed_alu_mem | `generate_mixed_alu_mem` | **LCG 伪随机** | 128 个 u64 |
| spill_pressure | `generate_spill_pressure` | **LCG 伪随机** | 64 个 u64 |
| bounds_ladder | `generate_bounds_ladder` | **LCG 伪随机** | 32 条结构化记录 |
| bounds_check_heavy | `generate_bounds_check_heavy` | **LCG 伪随机** | 32 条记录含 span/offset/selector |
| load_word32 / load_byte | `_generate_load_width_blob` | **LCG 伪随机** | 256 个 u32 |
| load_byte_recompose / load_native_u64 | `_generate_load_isolation` | **LCG 伪随机** | 128 个 u64（**两者 seed 相同！**） |
| const_fold_chain | `generate_const_fold_chain` | **LCG 伪随机** | 128 个 u32 |
| struct_field_cluster | `generate_struct_field_cluster` | **LCG 伪随机** | 32 条结构化记录 |
| bitfield_extract | `generate_bitfield_extract` | **LCG 伪随机** | 32 条双 u64 记录 |
| extract_dense | `generate_extract_dense` | **LCG 伪随机** | 256 个 u64 |
| smallmul_strength_reduce | `generate_smallmul_strength_reduce` | **LCG 伪随机** | 128 个 u64 |
| alu32_64_pingpong | `generate_alu32_64_pingpong` | **LCG 伪随机** | 64 个 u64 |
| memcmp_prefix_64 | `generate_memcmp_prefix_64` | **结构化** | 3 个 scenario：early mismatch + late mismatch + full match |
| packet_parse | `generate_packet_parse` | **结构化** | 54 个构造的 IPv4/TCP packet |
| packet_parse_vlans_tcpopts | `generate_packet_parse_vlans_tcpopts` | **结构化** | 单个 VLAN+TCP options 包 |
| packet_rss_hash | `generate_packet_rss_hash` | **结构化** | 单个 IPv4 TCP 包 |
| packet_redundant_bounds | `generate_packet_redundant_bounds` | **LCG 伪随机** | 32 条结构化记录 |
| bpf_call_chain | `generate_bpf_call_chain` | **LCG 伪随机** | 8 个 u64 |
| local_call_fanout | `generate_local_call_fanout` | **循环 pattern** | 16 条记录，`selector = index % 4` |
| imm64_storm | `generate_imm64_storm` | **LCG 伪随机** | 4 个 u64 |
| mega_basic_block_2048 | `generate_mega_basic_block_2048` | **LCG 伪随机** | 8 个 u64 |
| rotate64_hash | `generate_rotate64_hash` | **LCG 伪随机** | 8 个 u64 |
| rotate_dense | `generate_rotate_dense` | **LCG 伪随机** | 8 个 u64 |
| addr_calc_stride | `generate_addr_calc_stride` | **LCG 伪随机** | 256 个 u64 |
| endian_swap_dense | `generate_endian_swap_dense` | **LCG 伪随机** | 256 个 u32 |
| tc_bitcount | reuse `bitcount` | 同 bitcount | |
| tc_checksum | reuse `checksum` | 同 checksum | |
| cgroup_hash_chain | reuse `hash_chain` | 同 hash_chain | |

### 1.2 输入格式与 BPF 程序 input_map 匹配情况

所有检查过的 BPF 程序的 input struct 定义与生成器输出格式一致：
- header（count, threshold 等）使用 `<II`（两个 u32 LE）
- 数据数组使用 `<Q`（u64 LE）或 `<I`（u32 LE）或 `<H`（u16 LE）
- 程序端通过 `micro_read_u32_le()` / `micro_read_u64_le()` 读取，与生成器写入的 LE 格式匹配
- dense 变体（cmov_dense, cond_select_dense, branch_flip_dense 等）直接用 struct cast，layout 与生成器匹配

**无格式不匹配问题。**

---

## 2. Branch-Heavy Benchmark 的分支预测行为分析

这是审查的核心问题：输入数据对分支预测行为的影响。

### 2.1 cmov_select

**生成器**：交替 pattern。偶数索引 `lhs = lo, rhs = hi`（即 lhs < rhs），奇数索引 `lhs = hi, rhs = lo`。

**BPF 程序**：`if (lhs <= rhs) selected = on_false;`

**分支行为**：严格 50/50 交替，ABABAB... 模式。现代 CPU 的分支预测器可以轻松学习此模式（周期为 2），所以这其实是**高度可预测的**输入。

**影响**：这意味着 cmov_select 的测量结果**低估了** CMOV 在不可预测场景下的优势。如果分支预测器能完美预测，branch 方案开销几乎为零，CMOV 只增加了数据依赖链延迟。

### 2.2 cond_select_dense

**生成器**：同样交替 pattern。偶数索引 `lhs > rhs`，奇数 `lhs < rhs`。

**BPF 程序**：`if (lhs <= rhs) selected = on_false;`，每组 8 lanes 展开。

**分支行为**：完全与 cmov_select 相同 — 严格交替，高度可预测。

**影响**：在论文中 cond_select_dense 是 **0.482x**（llvmbpf/kernel），这个结论实际上是在**可预测场景**下测的。也就是说：即使分支可预测，CMOV 版本也比 branch 版本快 2x。这反过来证明了一个有趣的事实 — cond_select_dense 的瓶颈不是分支预测开销，而可能是 branch 指令本身在 pipeline 中的执行成本（即使预测正确也有 bubble）或者 CMOV 的 data-dependent 路径更短。

### 2.3 cmov_dense

**生成器**：4 个 32-元素 u64 数组，全由 LCG 生成。比较用 `lhs > rhs`, `lhs >= rhs`, signed variants 等。

**BPF 程序**：32 个展开的 CMOV step，每个用不同的比较条件。

**分支行为**：LCG 值的高位近似均匀分布 → 每个 step 大约 50% 概率。但因为值是固定的（deterministic），对于同一输入重复执行时，分支模式完全一样。CPU 分支预测器经过 warmup 后可以学习到这个固定 pattern。

**影响**：这比真正的"随机"要可预测得多，但又比交替 pattern 难预测。介于两者之间。

### 2.4 branch_flip_dense

**生成器**：256 个 LCG 伪随机 u64。

**BPF 程序**：每个 step 检测 `value & MASK(index)` 是否非零，其中 `MASK(INDEX) = 1ULL << (((INDEX) * 3U) & 31U)`。

**分支行为**：由于 mask 是 index-dependent 的（每个展开位置测试不同的 bit），而 LCG 值的各 bit 近似均匀 → 每个 step 大约 50% 概率。但因为是展开的（每个 step 的 index 是编译期常量），且值固定不变，warmup 后 CPU 可以学习。

**影响**：与 cmov_dense 类似，处于"可学习"和"近似均匀"之间。

### 2.5 branch_layout

**生成器**：432 值中每 10 个有 1 个超过 `hot_threshold`（= 900）。

**BPF 程序**：`if (value < hot_threshold)` 走 hot path，否则走 cold path。

**分支行为**：90% hot / 10% cold，高度偏斜。分支预测器会迅速偏向 hot path，预测准确率 ~90%。

**影响**：合理。这个 benchmark 测的就是 branch layout（把 cold path 移出 hot path），90/10 偏斜是合适的设计。

### 2.6 binary_search

**生成器**：16 个 query 中 `1/3 命中、2/3 未命中`（`if index % 3 == 0` 选已知存在的值）。

**BPF 程序**：对每个 query 做线性扫描（不是真正的 binary search），`if (!found && current == target)` 是主要分支。

**分支行为**：
- 大多数迭代 `found == 0 && current != target` → 继续循环（高度可预测的"不命中"分支）
- 命中时 `found` 变为 1，之后所有迭代走另一条路径
- 分支模式是可预测的（每个 query 最多一次命中点）

### 2.7 switch_dispatch

**生成器**：128 个值，每个 = `((state >> 32) ^ index) & 0x3F`，覆盖 0..63。

**分支行为**：64 路 switch，值近似均匀分布但 deterministic。BPF 编译器通常会将其编译为 jump table，所以分支预测依赖 indirect branch predictor。128 个固定不变的 dispatch 目标，warmup 后 BTB 可以记住。

### 2.8 branch_fanout_32

**生成器**：`tag = TAGS[(i*9+5) % len(TAGS)]`，32 个 tag 循环覆盖。

**分支行为**：因为 `(i*9+5) % 32` 是一个有规律的序列，间接分支预测器可以学习。

### 2.9 deep_guard_tree_8

**生成器**：`leaf = index % 9`，精心设计的 9 种 field pattern，确保 8 级 if/else 树的每个叶子都被覆盖。

**分支行为**：固定的循环 pattern（周期 9），每条路径覆盖 ~3.5 次。CPU 可以学习这个模式。

---

## 3. Corpus Benchmark 输入

### 3.1 Packet 输入

Corpus benchmark 使用两种固定构造的 64-byte packet：

1. **`macro_dummy_packet_64.bin`** — 标准 Ethernet/IPv4/TCP SYN 包
   - dst MAC = ff:ff:ff:ff:ff:ff（broadcast）
   - src IP = 10.0.0.1, dst IP = 10.0.0.2
   - src port = 12345, dst port = 80
   - 正确的 IP checksum
   - payload = 10 bytes of 'A'
   - **用于**：Calico、Suricata、Linux selftests

2. **`katran_vip_packet_64.bin`** — Katran LB 专用包
   - 使用 Katran LB MAC 和 client MAC
   - client IP = 10.0.0.2, VIP = 10.100.1.1
   - src port = 31337, dst port = 8080
   - TCP ACK flag
   - payload = "KATRANVIP!"
   - **仅用于**：Katran

3. **`macro_dummy_context_64.bin`** — 64 字节全零 context
   - **用于**：compile_only 类型（systemd, datadog-agent）

### 3.2 per-target 输入差异

从 `macro_corpus.yaml` 看：
- **Katran**：使用专门构造的 VIP packet，因为 Katran XDP 程序需要识别到 VIP 的流量才有意义的执行路径
- **其余 packet 类型**：都用同一个 dummy packet
- **compile_only 和 attach_trigger**：不需要真正的数据输入

### 3.3 输入合理性

Corpus 的输入策略与 micro 不同 — 它测的是**真实程序**的 JIT 编译和执行性能。关键约束：
- 每个程序只有一种 `io_mode` 和 `test_input`
- 没有 predictable / unpredictable 输入变体
- 这是合理的，因为 corpus 关注的是**整体程序**的 recompile speedup，而不是单个分支行为

---

## 4. 问题判断与改进建议

### 4.1 关键发现：CMOV/COND_SELECT 输入是高度可预测的

**`cmov_select` 和 `cond_select_dense` 都使用严格交替的 lhs/rhs pattern（偶数 true，奇数 false），这是 CPU 分支预测器最容易预测的 pattern 之一。**

这意味着：
- 当前的 `cond_select_dense` 0.482x 结果是在**可预测输入**下测的
- 如果使用不可预测输入（random 50/50），CMOV 优势会更大（因为 branch 版本会受到 misprediction penalty）
- 当前结果**低估了 CMOV 在真实不可预测场景下的收益**

但反过来说，这个发现也可以用于论文：
- predictable 输入下 CMOV 已经 0.482x → **即使分支可预测，CMOV 仍然显著优于 branch**
- 这说明 kernel JIT 的 branch 方案有**除了 misprediction 之外的 pipeline 开销**（例如：分支指令本身的 decode/retire 成本、branch 造成的 fetch bubble、code layout 影响等）

### 4.2 已有的 predictable/random 变体未被使用

生成器中已经存在以下变体：
- `generate_branch_layout_predictable` — 所有值都 < threshold（100% hot path）
- `generate_branch_layout_random` — 50/50 随机 hot/cold
- `generate_branch_fanout_32_predictable` — 所有值用同一个 tag
- `generate_branch_fanout_32_random` — tag 从 LCG 随机选取

**这些变体注册在 GENERATORS dict 中，但 `micro_pure_jit.yaml` 没有引用它们。** 这说明已经有人开始做 policy sensitivity 实验的准备工作，但未完成。

### 4.3 branch_flip_dense 和 cmov_dense 的输入是 "伪随机但可学习"

由于：
1. LCG 产生固定序列
2. 每次 benchmark 运行完全相同的输入
3. CPU 分支预测器有 warmup 阶段（benchmark 跑 2 次 warmup）

这些 benchmark 的分支可预测性处于灰色地带。经过足够多的 repeat（200 次），BTB 可能已经学习了部分 pattern。

### 4.4 log2_fold 的分支密度

`log2_fold` 的 `micro_log2_u32()` 使用 5 个连续的 `(value > X) << N` 比较 + 移位。对于 LCG 生成的均匀随机输入，每个比较大约 50/50。5 个分支 × 128 个值 = 640 个分支，且每个分支的结果取决于上一步移位后的值 → 对 CPU 来说这是**moderate unpredictability**。

这与 Memory 中记录的 `log2_fold +28.3%`（kernel 比 llvmbpf 慢）是一致的 — 分支较多且不太可预测时 kernel JIT 表现更差。

### 4.5 Corpus 输入的局限性

Corpus 使用单一固定 packet 是合理的工程选择（一致性 > 多样性），但有局限：
- 单一 packet 只触发程序的一条执行路径
- 例如 Katran LB：只测了匹配 VIP 的路径，没测 miss 路径
- Suricata XDP filter：dummy packet 可能不匹配任何 filter rule，走的是 fast-reject 路径

这对 JIT recompile benchmark 来说影响不大（因为 recompile 改变的是机器码质量，不改变执行路径），但如果想做 path coverage 分析就不够。

---

## 5. 改进建议

### 5.1 高优先级：为 policy-sensitive benchmark 添加 predictable/random 输入对

**目标**：证明 CMOV/branch-flip 优化的 policy sensitivity（即：相同优化在可预测 vs 不可预测输入下效果不同）。

需要新增的输入生成器和 YAML 条目：

| 现有 Benchmark | 需要的变体 | 输入特征 |
|----------------|-----------|----------|
| cond_select_dense | `cond_select_dense_random` | lhs/rhs 由 LCG 决定（而非交替） |
| cmov_select | `cmov_select_random` | lhs/rhs 由 LCG 决定 |
| branch_flip_dense | `branch_flip_dense_predictable` | 所有值的 test bit 都为 1（100% 一条路径） |
| cmov_dense | `cmov_dense_predictable` | 构造 lhs 始终 > rhs（100% 一条路径） |

**注意**：`branch_layout` 和 `branch_fanout_32` 的 predictable/random 变体**已经存在于生成器中**，只需要在 YAML 中添加条目。

### 5.2 中优先级：标注当前输入的分支可预测性

在现有结果的分析文档中应明确标注：
- `cond_select_dense` 的 0.482x 是在**alternating-predictable** 输入下测得的
- `log2_fold` 的 +28.3% 是在**approximately-uniform** 输入下测得的
- 这两个结果分别代表了 CMOV 优化在两个极端下的表现

### 5.3 低优先级：Corpus 输入多样化

为关键 corpus target 准备多种 packet：
- Katran：VIP hit + VIP miss + non-TCP
- Calico：policy match + policy miss
- Suricata：filter hit + filter miss

这对 corpus 的价值有限（因为主要测的是 recompile speedup），但可以用于补充 path-coverage 分析。

### 5.4 不需要改的

以下设计是合理的，无需修改：
- **LCG determinism**：确保每次运行结果可复现，这对 benchmark 至关重要
- **固定 seed**：不引入外部随机性，避免跑间变异
- **branch_layout 的 90/10 偏斜**：正确反映了 hot/cold branch layout 场景
- **binary_search 的 1/3 hit ratio**：合理的搜索 workload
- **深度 guard tree 的循环覆盖**：确保所有路径都被执行到
- **load_byte_recompose 和 load_native_u64 使用相同 seed**：这是设计意图，确保对比公平

---

## 6. 总结

| 维度 | 评估 |
|------|------|
| Determinism | 完美。全部使用固定 seed LCG，无外部随机性 |
| 格式匹配 | 完美。生成器输出与 BPF 程序 struct 定义一致 |
| 非分支 benchmark 输入 | 合理。LCG 伪随机足以测试 ALU/memory codegen |
| 分支 benchmark 输入 | **有改进空间**。cmov_select 和 cond_select_dense 使用交替 pattern 导致高度可预测，测不出 misprediction 场景。但已有的结论（0.482x）在可预测场景下仍有价值 |
| Corpus 输入 | 合理。单一 packet 足以测 recompile speedup |
| 已有但未用的变体 | 存在 branch_layout_predictable/random 和 branch_fanout_32_predictable/random，应在 YAML 中启用 |
