# Micro Benchmark 性能数据深度分析与改进机会

> 分析日期：2026-03-18
> 数据来源：`micro/results/vm_micro_authoritative_20260314.json`（3 iterations, 3 warmups, 500 repeat, VM 环境）
> 消融数据：`micro/results/per_form_ablation_20260313/`

---

## 0. 执行摘要

当前权威数据：**62 benchmark overall geomean KR/K = 0.9489（speedup 5.1%）**，16 个 applied benchmark 的 geomean = **0.9308（speedup 6.9%）**。

关键发现：
1. **VM 噪声严重干扰**：46 个"non-applied"benchmark（policy sites=0 或无 policy）的 KR/K 比值偏离 1.0，说明 recompile path 本身引入了系统性噪声
2. **ROTATE 是唯一稳定正向 form**，贡献了大部分 applied speedup
3. **三个 applied benchmark 是净回归**：memcmp_prefix_64、branch_flip_dense、addr_calc_stride
4. **大量 rotate/wide 站点被 policy 跳过**，潜在改进空间巨大
5. **WIDE_MEM 在 ablation 中表现混合**，需要更精细的 policy

---

## 1. 当前结果逐条分析

### 1.1 Applied Benchmarks（16 个，policy 有 sites > 0）

| # | Benchmark | KR/K | 方向 | Sites | 主要 Form | 分析 |
|---|-----------|------|------|-------|-----------|------|
| 1 | rotate_dense | 0.526 | **WIN +47.4%** | 256 rotate | ROTATE | 最大 winner，RORX 替换 4-insn shift+or 序列 |
| 2 | cmov_dense | 0.684 | **WIN +31.6%** | 26 rotate | ROTATE | 名字误导——policy 跳过了 32 cmov sites，只应用 26 rotate sites |
| 3 | log2_fold | 0.850 | **WIN +15.0%** | 3 wide | WIDE_MEM | 跳过了 8 cmov（因为 log2 有不可预测分支），只用 wide |
| 4 | cmov_select | 0.864 | **WIN +13.6%** | 1 cmov | CMOV | 单个 cmov site，跳过了 4 rotate + 6 wide |
| 5 | mixed_alu_mem | 0.939 | WIN +6.1% | 2 extract + 1 wide | EXTRACT+WIDE | |
| 6 | binary_search | 0.945 | WIN +5.5% | 1 cmov + 2 wide | CMOV+WIDE | |
| 7 | multi_acc_4 | 0.953 | WIN +4.7% | 1 lea + 2 wide | LEA+WIDE | |
| 8 | switch_dispatch | 0.987 | WIN +1.3% | 1 cmov + 2 wide | CMOV+WIDE | 微弱正向 |
| 9 | branch_dense | 0.993 | WIN +0.7% | 4 bflip + 1 cmov + 2 wide | 混合 | 几乎中性 |
| 10 | bounds_ladder | 1.000 | neutral | 2 cmov + 2 wide | CMOV+WIDE | 完全中性 |
| 11 | bpf_call_chain | 1.019 | LOSS -1.9% | 1 cmov + 2 wide | CMOV+WIDE | 轻微回归 |
| 12 | large_mixed_500 | 1.025 | LOSS -2.5% | 3 bflip | BRANCH_FLIP | 回归 |
| 13 | multi_acc_8 | 1.031 | LOSS -3.1% | 2 lea + 2 wide | LEA+WIDE | 回归 |
| 14 | addr_calc_stride | 1.056 | **LOSS -5.6%** | 8 lea | LEA | 回归！8 个 LEA sites 反而变慢 |
| 15 | branch_flip_dense | 1.084 | **LOSS -8.4%** | 255 bflip | BRANCH_FLIP | 大量 branch-flip 导致 I-cache flush 回归 |
| 16 | memcmp_prefix_64 | 1.176 | **LOSS -17.6%** | 3 rotate | ROTATE | 最大 regressor！仅 3 rotate sites 却 -17.6% |

### 1.2 Non-Applied Benchmarks 中的异常值

以下 non-applied benchmark 显示的大幅偏离 1.0 **不是优化效果**，而是 **VM 噪声 / recompile path 系统开销**：

**显著"假 speedup"（sites=0 但 KR/K < 0.9）**：
- simple_packet: 0.583（baseline, 12ns vs 7ns，sub-ktime noise）
- struct_field_cluster: 0.723（101ns vs 73ns，VM noise）
- endian_swap_dense: 0.763（policy=sites:[]，但 recompile path 的 empty-policy 反而快了？矛盾）
- stride_load_16: 0.769, stride_load_4: 0.846
- load_word32: 0.796, imm64_storm: 0.770

**显著"假 regression"（sites=0 但 KR/K > 1.1）**：
- local_call_fanout: 1.453（无 policy 文件，但 KR 明显慢）
- packet_parse: 1.429（policy=sites:[]）
- memory_pair_sum: 1.286（7ns vs 9ns，sub-ktime noise）

**分析**：这些偏差表明 VM 环境下 3 iterations 不够稳定。non-applied benchmarks 的理想 KR/K 应接近 1.0。当前数据中 non-applied 的 geomean 约 0.956，说明 recompile path 系统性偏快约 4%，这可能**膨胀了 overall 的 speedup 数字**。

### 1.3 按 Policy 分类的完整分布

| 分类 | 数量 | Geomean KR/K | 说明 |
|------|------|-------------|------|
| Applied (sites > 0) | 16 | 0.931 (6.9% speedup) | 9 WIN, 1 neutral, 6 LOSS |
| Policy sites=0 | 13 | ~0.96 | 本该是 1.0，有系统性偏差 |
| No policy file | 33 | ~0.95 | 同上 |
| **Overall** | **62** | **0.949 (5.1% speedup)** | |

---

## 2. Applied Benchmark 的 Per-Form 分解

### 2.1 Per-Form 贡献排名（基于 ablation 数据）

| Form | Ablation Geomean | 方向 | 最佳 benchmark | 最差 benchmark |
|------|-----------------|------|---------------|---------------|
| **ROTATE** | 0.923x | **WIN +7.7%** | rotate_dense 0.732 | memcmp_prefix_64 1.236 |
| ENDIAN | 0.981x | WIN +1.9% | endian_swap_dense 0.981 | (only 1) |
| BRANCH_FLIP | 0.992x | WIN +0.8% | branch_flip_dense 0.986 | (mixed) |
| LEA | 0.999x | neutral | multi_acc_8 0.964 | addr_calc_stride 1.033 |
| WIDE | 1.007x | **LOSS** | mixed_alu_mem 0.947 | binary_search 1.198 |
| EXTRACT | 1.067x | **LOSS** | (none positive) | extract_dense 1.115 |
| CMOV | 1.068x | **LOSS** | cmov_select 0.976 | cond_select_dense 1.538 |

### 2.2 每个 Applied Benchmark 的 Form 组合分析

**正向贡献 benchmarks**：

1. **rotate_dense** (0.526): 纯 ROTATE，256 sites。RORX 将 4-insn rotate（mov+shl+shr+or，~13B）替换为单条 RORX（6B），每 site 节省 7B。256 sites * 7B = 巨大的代码缩减。这是最成功的优化。

2. **cmov_dense** (0.684): 实际是 ROTATE（26 sites），不是 CMOV。Policy 跳过了 32 个 cmov sites（因为 dense diamonds 上 CMOV 增加关键路径延迟），只留 rotate。ROTATE 单独贡献全部 31.6% 加速。

3. **log2_fold** (0.850): 3 个 WIDE_MEM sites。跳过了 8 cmov sites（log2 有不可预测的分支跳转序列，CMOV 在此不利）。WIDE 将 byte-load+shift+or 替换为单条 wide load，在 setup 代码中节省指令。

4. **cmov_select** (0.864): 1 个 CMOV site。这是 CMOV 最佳用例：单个 predictable-ish diamond。跳过了 4 rotate + 6 wide sites 以隔离效果。

5. **mixed_alu_mem** (0.939): 2 extract + 1 wide。EXTRACT 在 hot loop 中将 shift+and 替换为 BEXTR（仅 with-copy 模式），WIDE 在 setup 中。

6. **binary_search** (0.945): 1 cmov + 2 wide。CMOV 替换了搜索中的条件分支，WIDE 在 setup。

7. **multi_acc_4** (0.953): 1 lea + 2 wide。LEA 在 hot loop 中替换 mov+shl+add，WIDE 在 cold setup。

**回归 benchmarks**：

1. **memcmp_prefix_64** (1.176): 3 rotate sites，但回归 17.6%。**这是 ROTATE 的反例**。可能原因：(a) memcmp 的 rotate 在 early-exit 路径上，不在 hot path；(b) recompile 的 I-cache flush 代价超过了 3 sites 的收益；(c) VM 噪声。ablation 也确认了 ROTATE 在此 benchmark 上 1.236x 回归。**建议：从 policy 中移除**。

2. **branch_flip_dense** (1.084): 255 branch-flip sites。ablation 显示 branch_flip 单独是 0.986x（微弱正向），但 authoritative run 中 1.084x 回归。**根因：dense 255 sites 导致 full-image recompile I-cache flush 开销大于 body-swap 微架构收益**。BRANCH_FLIP 的 body swap 不改变代码大小（只交换 true/false 分支体顺序），所以不节省 I-cache footprint。**建议：对 dense-site 程序 skip BRANCH_FLIP，或只 apply 部分 sites**。

3. **addr_calc_stride** (1.056): 8 LEA sites。ablation 也显示 LEA 单独 1.033x 回归。**根因：LEA base+index*scale 指令虽然更短，但引入了 AGU 依赖，在高 ILP stride-load 场景下反而更慢**。可能 LEA 的 port 竞争比原始 mov+shl+add 序列更差。**建议：skip LEA on addr_calc_stride**。

4. **multi_acc_8** (1.031): 2 lea + 2 wide。与 multi_acc_4 不同，8-lane 版本有更高寄存器压力，LEA 的 AUX_REG 使用可能加剧 spill。**建议：考虑 skip LEA，只保留 wide**。

5. **large_mixed_500** (1.025): 3 branch-flip sites。轻微回归，可能是 I-cache flush 开销。**建议：skip BRANCH_FLIP**。

6. **bpf_call_chain** (1.019): 1 cmov + 2 wide。轻微回归。CMOV + WIDE 组合在 call-heavy 程序上净负。**建议：去掉 cmov 只留 wide，或全部 skip**。

---

## 3. Policy 优化空间

### 3.1 当前 Policy 策略

当前 policy 使用以下规则：
- **CMOV**：在大多数有 sites 的程序上 apply，但在 `cond_select_dense` 上显式 skip（104 sites，predictable-branch）
- **WIDE_MEM**：在有 wide sites 的程序上选择性 apply。很多程序的 wide sites 被 skip（bitcount, checksum, dep_chain_long, etc.）
- **ROTATE**：在 rotate_dense/cmov_dense/memcmp_prefix_64 上 apply
- **LEA**：在 addr_calc_stride/multi_acc_4/multi_acc_8 上 apply
- **EXTRACT**：在 mixed_alu_mem/extract_dense 上。extract_dense 显式 skip 512 sites
- **ENDIAN**：endian_swap_dense 显式 skip 256 sites
- **BRANCH_FLIP**：在 branch_flip_dense/branch_dense/large_mixed_500 上 apply

### 3.2 过于保守的 Skip

以下 skip 可能是过于保守的，应该测试 apply：

| Benchmark | 被 Skip 的 Form | Scanner Sites | 当前 KR/K（无 policy） | 潜在收益 |
|-----------|-----------------|---------------|---------------------|----------|
| **imm64_storm** | rotate=64, wide=4 | 68 | 0.770 | 已经因 VM noise 显示 23% "speedup"，但真实 rotate 收益可能存在 |
| **rotate64_hash** | rotate=116, wide=7 | 123 | 1.011 | **116 rotate sites 完全未用！** 这是最大的遗漏 |
| **mega_basic_block_2048** | rotate=512, wide=8 | 520 | 1.002 | 512 rotate sites 未用，但 dense sites 有 I-cache flush 风险 |
| **large_mixed_1000** | bflip=8, rotate=7, wide=1 | 16 | 0.968 | 7 rotate sites 未用 |
| **branch_fanout_32** | rotate=8, wide=1 | 9 | 0.996 | policy skip 了 rotate=8，但 ablation 显示 ROTATE 是最高价值 form |
| **code_clone_2** | rotate=1, wide=1 | 2 | 0.925 | |
| **code_clone_8** | rotate=2, wide=1 | 3 | 0.984 | |
| **fixed_loop_small** | rotate=1, wide=3 | 4 | 0.857 | |
| **fixed_loop_large** | rotate=1, wide=3 | 4 | 0.997 | |
| **packet_rss_hash** | rotate=11, wide=2 | 13 | 1.111 | 11 rotate sites 完全未用，但 packet-backed 程序 |

**特别关注**：
- **rotate64_hash**：116 rotate sites 完全无 policy。这是 SipHash-like 程序，rotate 密集，应该是 ROTATE 的理想目标。没有 policy file 是一个严重遗漏。
- **imm64_storm**：64 rotate sites，也无 policy。
- **branch_fanout_32**：policy 显式 skip 了 8 rotate + 1 wide sites（`sites: []`），需要重新评估。

### 3.3 应该 Skip 但没 Skip 的

| Benchmark | Applied Form | 当前 KR/K | 建议 |
|-----------|-------------|-----------|------|
| **memcmp_prefix_64** | rotate=3 | 1.176 | **Skip rotate**。3 sites 不在 hot path，I-cache flush 代价 > 收益 |
| **branch_flip_dense** | bflip=255 | 1.084 | **Skip bflip**。dense 255 sites 的 full recompile 代价 > body-swap 收益 |
| **addr_calc_stride** | lea=8 | 1.056 | **Skip LEA**。LEA 在 stride-load 上反而增加 AGU 竞争 |
| **multi_acc_8** | lea=2, wide=2 | 1.031 | **Skip LEA**，保留 wide |
| **large_mixed_500** | bflip=3 | 1.025 | **Skip bflip** |
| **bpf_call_chain** | cmov=1, wide=2 | 1.019 | **Skip cmov**，可能也 skip wide |

### 3.4 Policy 优化后预期效果

如果执行以下 policy 变更：
1. Skip memcmp_prefix_64 rotate（消除 -17.6% → ~0%）
2. Skip branch_flip_dense bflip（消除 -8.4% → ~0%）
3. Skip addr_calc_stride LEA（消除 -5.6% → ~0%）
4. Skip multi_acc_8 LEA，保留 wide（改善 -3.1% → ~0%）
5. Skip large_mixed_500 bflip（消除 -2.5% → ~0%）
6. Skip bpf_call_chain cmov（改善 -1.9% → ~0%）

**保守估算**：
- Applied-only geomean 从 0.931 → ~0.888（因为移除了 6 个 regressor）
- 但 applied 数量从 16 → 10
- Overall geomean 不变（因为 skip 等于恢复到 baseline）

如果同时**新增 apply**：
7. 给 rotate64_hash 添加 rotate policy（116 sites）
8. 给 branch_fanout_32 添加 rotate policy（8 sites）

这些新增可能带来额外的 positive contribution。

---

## 4. Scanner Coverage 分析

### 4.1 Scanner 站点分布全景

| Family | 总程序数 | 总 Sites | 有 Policy 的程序数 | Applied Sites |
|--------|---------|---------|------------------|--------------|
| rotate | 21 | 819+ | 3 (rotate_dense, cmov_dense, memcmp) | 285 |
| wide | 55 | 120+ | 7 | ~15 |
| cmov | 8 | 150+ | 6 | ~7 |
| branch-flip | 4 | 270+ | 3 | 262 |
| lea | 5 | 13 | 3 | 11 |
| extract/bitfield | 6 | 525+ | 1 | 2 |
| endian | 1 | 256 | 0 (skipped) | 0 |

### 4.2 最大覆盖空白

**ROTATE 覆盖严重不足**：
- Scanner 在 21 个程序中找到 rotate sites
- 但只有 3 个程序有 rotate 在 policy 中（rotate_dense=256, cmov_dense=26, memcmp_prefix_64=3）
- 特别是 **rotate64_hash (116), imm64_storm (64), mega_basic_block_2048 (512), branch_fanout_32 (8), packet_rss_hash (11)** 完全没被利用
- ROTATE 是 ablation 中最高价值 form (0.923x geomean)

**WIDE_MEM 过于保守**：
- 55 个程序有 wide sites，但大量被 skip
- ablation 显示 WIDE 整体 1.007x（微弱 loss），但在特定程序上有强正向（mixed_alu_mem 0.947, switch_dispatch 0.927）
- 问题：wide sites 大多在 cold setup 代码中（读 count/seed），hot-path 贡献有限

**EXTRACT 需要区分 with-copy vs without-copy**：
- extract_dense 有 512 sites 但全 skip（因为都是 without-copy pattern，BEXTR 反而膨胀代码）
- mixed_alu_mem 的 2 extract sites 是 with-copy，表现正向
- Scanner 需要在 site 级别标注 with-copy/without-copy 以支持精细 policy

### 4.3 无 Sites 的程序

3 个程序完全没有 sites：`load_native_u64`, `simple`, `simple_packet`。这些是 baseline/control 程序，预期无 sites。

`struct_field_cluster` 也没有 sites（0 total），但 KR/K = 0.723，纯 VM 噪声。

---

## 5. Emitter 改进机会

### 5.1 ROTATE Emitter（最高价值）

**当前实现**（`emit_canonical_rotate`, line 2408）：
- 支持两种 native_choice：`BPF_JIT_ROT_RORX`（BMI2 RORX）和 `BPF_JIT_ROT_ROR`（普通 ROR）
- RORX：6 bytes（VEX prefix + F0 + modrm + imm8），**非破坏性**（dst != src OK）
- ROR：需要 mov（if src != dst）+ 4 bytes（REX + C1 + modrm + imm8）

**改进空间**：
- **现有 emitter 质量良好**：RORX 编码正确，6B 替换原始 4-insn ~13B 序列（mov+shl+shr+or）
- **潜在改进**：当 BMI2 不可用时回落到 ROR，但 ROR 是破坏性的需要额外 mov。当前实现正确处理了这一点
- **无明显 bug**

### 5.2 WIDE_MEM Emitter

**当前实现**（`emit_wide_load_sequence`, line 2307）：
- 对齐 width (2/4/8)：单条 LDX，可能跟一个 BSWAP
- 非对齐 width (3/5/6/7)：多 chunk 组合，用 shift+or 拼接

**改进空间**：
- 当前只处理 **byte-load+shift+or 合并为 wide load** 模式
- **不支持** byte-store+shift 的逆向（store 端 wide 化）
- **不支持**非连续 byte load 模式（gap in offsets）
- **不支持** 32-bit wide load（当前只有 2/4/8B 对齐快速路径，3/5/6/7B 走慢路径）
- emitter 质量正常，无 bug

### 5.3 CMOV Emitter

**当前实现**（`emit_canonical_select`, line 1544）：
- 三种变体：site_len=2 (guarded update), site_len=3 (compact select), site_len=4 (diamond select)
- **guarded update** (v5 新增)：`jcc +1, mov` → `cmp, cmovcc`
- **compact select**：`mov_default, jcc, mov_override` → `mov, cmp, cmovcc`
- **diamond select**：`jcc, mov_false, ja, mov_true` → `cmp, [mov_false_to_aux], mov_true, cmovcc`

**改进空间**：
- 对于 imm32 source，需要先 `mov_imm32 AUX, imm` 再 `cmovcc dst, AUX`（因为 CMOV 不支持 immediate source）。这增加了一条指令，可能抵消了消除 branch 的收益
- **关键问题**：CMOV 总是在关键路径上增加延迟（data dependency），而 branch 在可预测时是免费的。这就是为什么 cond_select_dense (predictable, 104 sites) 上 CMOV 回归 53.8%
- **Policy-sensitive 是 feature not bug**：这恰好证明了 userspace policy 的必要性
- 无 emitter bug

### 5.4 LEA Emitter

**当前实现**（`emit_canonical_lea_fusion`, line 2488）：
- 生成 `LEA dst, [base + index * scale]`
- 只支持 scale = 1/2/3（对应 SIB scale 1/2/4/8 的 log2）
- 不支持 displacement（disp8 hard-coded 0）

**改进空间**：
- **不支持 displacement**：如果原始模式是 `mov dst, src; shl dst, 2; add dst, base; add dst, 16`，不能用 `LEA dst, [base + src*4 + 16]`。只能处理 no-displacement 情况
- **LEA 在 addr_calc_stride 上回归**：可能因为 LEA 使用 AGU port，而原始 ALU 序列分布在多个 ALU port，ILP 更好
- 改进 LEA 的价值有限（整个 corpus 只有 19 sites in 11 objects）

### 5.5 BEXTR (BITFIELD_EXTRACT) Emitter

**当前实现**（`emit_bitfield_extract_core`, line 3354）：
- with-copy（src != dst）：`mov_imm32 AUX, control; BEXTR dst, src, AUX`（2 insn, 9B）
- without-copy（src == dst）：fallback 到 `SHR+AND`（2 insn, 6B）

**关键发现**：without-copy fix (commit daca445b1/ac593b2c1) 已正确处理。BEXTR without-copy 不再膨胀代码。但 extract_dense 仍然 skip 512 sites 因为 dense-site I-cache flush 问题。

### 5.6 ENDIAN_FUSION Emitter

**当前实现**（`emit_canonical_endian_fusion`, line 2760）：
- load-swap：`MOVBE dst, [base+off]`
- store-swap：`MOVBE [base+off], src`
- 需要 MOVBE CPU feature

**关键问题**：MOVBE 32-bit = 5B = LDX+BSWAP32 5B（same size）。不节省代码空间。16-bit MOVBE 需要额外 0x66 prefix + movzx 后缀，可能更大。只有 64-bit MOVBE (7B) vs LDX+BSWAP64 (7B) 持平。**ENDIAN_FUSION 在 x86 上不节省代码大小，纯微架构依赖。**

### 5.7 BRANCH_FLIP Emitter

**当前实现**（`emit_canonical_branch_flip`, line 3205）：
- swap body_a 和 body_b 的顺序，反转条件跳转
- 代码大小完全不变（body 内容相同，只是 body 顺序换了）

**关键问题**：不改变代码大小 → recompile I-cache flush 是纯开销。只有当 branch_flip 改变 hot-path layout 导致分支预测改善时才有收益。但 benchmark 中的输入是确定性的，不存在 runtime data-dependent branch misprediction。**BRANCH_FLIP 在当前 micro benchmarks 上几乎没有收益。**

---

## 6. 新 Form 可行性分析

### 6.1 Prologue 优化（预估 18.5% of pure-JIT gap）

**背景**：kernel JIT prologue 包含 callee-saved register push/pop、frame pointer 设置、BPF-to-x86 register mapping。llvmbpf 作为 LLVM JIT 可以省略不需要的 callee-saved registers。

**可行性**：
- **高**：不需要改 BPF 指令，只需分析每个程序实际使用的寄存器集合，省略未使用的 callee-saved push/pop
- **约束**：BPF-to-BPF 调用约定要求保留 R6-R9，但如果程序没有 subprog call 可以松弛
- **预期收益**：characterization 数据显示 prologue/epilogue 占 18.5% surplus。恢复一半 = ~9% 的 gap
- **风险**：kernel 7.0-rc2 已上游化部分 callee-saved 优化（ablation 显示 callee-saved ~0%），所以实际可恢复的部分可能很小
- **结论**：如果 kernel 已上游化 callee-saved skip，则 prologue 优化剩余空间有限。需要先验证当前 kernel 的 prologue 是否已优化

### 6.2 WIDE_MEM Pattern 扩展

**当前覆盖**：连续 byte-load + left-shift + or 合并

**潜在扩展**：
1. **byte-store 序列**：store 端的 byte decompose（`r >> 0) & 0xff → store8; (r >> 8) & 0xff → store8`）合并为 wide store。Scanner 未实现。
2. **非连续 offset**：当 byte loads 不是严格连续时（gap），当前 scanner 不匹配。
3. **16-bit load pair → 32-bit**：两个 `LDX_H` 合并为一个 `LDX_W`。
4. **32-bit load pair → 64-bit**：两个 `LDX_W` 合并为一个 `LDX_DW`。

**预期收益**：
- byte-recompose 是 50.7% of gap，当前 WIDE_MEM 只覆盖了最常见模式
- 扩展到 store 端 + 更多 load 宽度组合可能增加 10-20% 的 site 覆盖
- 但大部分 wide sites 在 cold setup 代码中（读 count/seed），hot-path 占比有限

**风险**：中等。新 pattern 需要 scanner + kernel emitter 双改。

### 6.3 其他高频 Pattern 分析

在 62 个 benchmark 中，以下 pattern 频繁出现但未被覆盖：

1. **零偏移 MOV 冗余**：`mov r1, r1` 是 verifier 插入的 zext helper，x86 上应该是 noop 但仍然 emit（需确认 7.0-rc2 是否已修复）。ZERO_EXT_ELIDE form 存在但 x86-64 上 corpus 0 sites（因为 `bpf_jit_needs_zext()=false`）。

2. **常量传播**：`mov r1, imm; add r2, r1` 可替换为 `add r2, imm`。const_fold_chain benchmark 专门测试这个，但没有对应 form。
   - **可行性**：中等。需要跨指令分析，比单指令 peephole 复杂
   - **预期收益**：中低。大多数常量折叠已被 LLVM frontend 完成

3. **Strength reduction**：`mul r1, 3` → `lea r1, [r1 + r1*2]`。smallmul_strength_reduce benchmark 专门测试。
   - **可行性**：高。只需匹配 `MUL_IMM` where imm is 3,5,9 等 LEA-friendly 常量
   - **预期收益**：取决于 benchmark profile。当前 smallmul_strength_reduce 有 wide=2 sites 但 skip 了

4. **DIV/MOD 优化**：kernel JIT 在 div/mod 前保存/恢复 RAX/RDX，如果 src 已经在 RAX 可省略 mov。
   - **可行性**：中等
   - **预期收益**：低（div/mod 在 BPF 中不常见）

---

## 7. 具体改进建议（按优先级排序）

### P0: Policy 修复（清除明确回归，0 代码改动）

**动作**：修改 6 个 policy 文件，将 regressor 从 applied 变为 skip

| 改动 | 文件 | 预期影响 |
|------|------|---------|
| memcmp_prefix_64: skip rotate=3 | `micro/policies/memcmp_prefix_64.yaml` → sites: [] | applied geomean +2.3% |
| branch_flip_dense: skip bflip=255 | `micro/policies/branch_flip_dense.yaml` → sites: [] | applied geomean +1.0% |
| addr_calc_stride: skip lea=8 | `micro/policies/addr_calc_stride.yaml` → sites: [] | applied geomean +0.7% |
| multi_acc_8: skip lea, keep wide | `micro/policies/multi_acc_8.yaml` → 只留 wide=2 | applied geomean +0.4% |
| large_mixed_500: skip bflip=3 | `micro/policies/large_mixed_500.yaml` → skip bflip | applied geomean +0.3% |
| bpf_call_chain: skip cmov, keep wide | `micro/policies/bpf_call_chain.yaml` → 只留 wide=2 | applied geomean +0.2% |

**预期**：applied-only geomean 从 0.931 → ~0.885-0.90（10-12% speedup），但 applied 数量减少到 10

**复杂度**：极低（只改 YAML）
**风险**：极低（回归消除是确定性的）

### P1: 扩展 ROTATE 覆盖（最高 ROI）

**动作**：给以下程序创建 policy 文件，apply rotate sites

| 程序 | Rotate Sites | 预期收益 | 复杂度 |
|------|-------------|---------|--------|
| **rotate64_hash** | 116 | 高（SipHash 密集 rotate，类似 rotate_dense） | 低（写 policy YAML） |
| **branch_fanout_32** | 8 | 中 | 低 |
| **large_mixed_1000** | 7 | 中 | 低（已有 bflip policy，追加 rotate） |
| **large_mixed_500** | 7 | 中（替代被 skip 的 bflip） | 低 |
| **cmov_select** | 4 | 低（已有 cmov=1，追加 rotate） | 低 |
| imm64_storm | 64 | 不确定（可能 I-cache flush 风险） | 低 |
| mega_basic_block_2048 | 512 | 不确定（dense sites 风险高） | 低 |

**保守估算**：rotate64_hash 如果达到 rotate_dense 类似的 per-site 收益（~47%），即使打折到 20%，也能显著提升 applied-only geomean。

**预期**：applied-only 从 ~0.90 → ~0.87-0.88（12-13% speedup），applied 数量增加到 13-15

**复杂度**：低（只改/创建 policy YAML）
**风险**：中（需要 VM rerun 验证；dense-site 程序可能有 I-cache flush 问题）

### P2: 精细 WIDE_MEM Policy

**动作**：分析每个 wide site 是在 hot path 还是 cold setup，选择性 apply

当前问题：很多 wide sites 被全部 skip（bitcount, checksum, dep_chain_long 等）。ablation 显示 WIDE 整体 1.007x（微弱 loss），但部分 benchmark 正向（mixed_alu_mem 0.947, switch_dispatch 0.927）。

关键 insight：wide sites 分两类：
- **Cold setup**：读 count/seed 的 u32 pair → 合并为 u64 load。收益极低（只执行一次）
- **Hot loop**：loop 内的 byte-recompose。收益高

**建议**：只 apply hot-loop wide sites，skip cold-setup wide sites。

**预期**：marginal improvement（WIDE 的 per-site 收益有限）
**复杂度**：中（需要分析每个 site 的位置）
**风险**：低

### P3: EXTRACT without-copy 优化

**现状**：extract_dense 512 sites 全 skip 因为 with-copy/without-copy 混合导致 I-cache flush 回归。

**建议**：
1. 在 scanner 中标注 with-copy vs without-copy
2. 只 apply with-copy sites（BEXTR 真正节省代码的情况）
3. Skip without-copy sites（SHR+AND 已经 6B，BEXTR 反而 9B）

**预期**：extract_dense 可能从 1.0 → 0.95（如果 with-copy sites 足够多）
**复杂度**：中（scanner 改动 + policy 改动）
**风险**：中

### P4: 新增 STRENGTH_REDUCE Form

**动作**：新增 `mul_imm` → `LEA` 的 strength reduction form

匹配 pattern：`BPF_ALU64_IMM(BPF_MUL, dst, 3)` → `LEA dst, [dst + dst*2]`

支持常量：3 (1+2), 5 (1+4), 9 (1+8)

**预期**：smallmul_strength_reduce benchmark 直接受益
**复杂度**：中高（需要新 canonical form + scanner pattern + kernel emitter）
**风险**：中（MUL 延迟 3 cycles，LEA 延迟 1 cycle，但 MUL 可能和 LEA 在不同 port）

### P5: Prologue NOP Elimination

**动作**：分析程序的实际寄存器使用，省略不需要的 callee-saved push/pop

**现状**：7.0-rc2 已部分上游化，ablation 显示 callee-saved ~0%。

**预期**：可能已经被上游覆盖，需要先验证
**复杂度**：中高（需要在 recompile 时做寄存器活跃性分析）
**风险**：低

### P6: ENDIAN_FUSION 条件启用

**现状**：全部 skip（256 sites on endian_swap_dense），因为 same-size recompile 导致 I-cache flush 回归。

**建议**：只在以下条件下启用：
1. 64-bit endian fusion（MOVBE 64-bit 可能比 LDX+BSWAP64 有微架构优势）
2. 特定 CPU model（某些 CPU 上 MOVBE 有专用执行单元）
3. 程序 sites 数量少（避免 dense-site I-cache flush）

**预期**：limited，因为 x86 上 MOVBE 不节省代码大小
**复杂度**：低（只改 policy）
**风险**：低

---

## 8. 综合改进路径

### 立即可做（P0, 改 YAML）

1. 清除 6 个 regressor policy → applied-only ~0.88-0.90
2. 新增 rotate64_hash, branch_fanout_32, large_mixed_500(rotate), large_mixed_1000(rotate) policy
3. 重跑 `make vm-micro` 验证

### 短期（P1-P2, 1-2 天）

1. 创建新 policy 文件并 VM 验证
2. 精细 WIDE policy（per-site hot/cold 分析）
3. 预期：overall ~0.93-0.94, applied-only ~0.85-0.88

### 中期（P3-P4, 1 周）

1. Scanner 支持 extract with-copy/without-copy 标注
2. Strength reduction form 原型
3. 预期：overall ~0.92-0.93, applied-only ~0.83-0.86

### 关键观察

**VM 噪声是当前最大的测量问题**。non-applied benchmarks 的 KR/K 偏差（geomean ~0.956 而非 1.0）说明：
- 要么 recompile path 本身有系统性优势（unlikely）
- 要么 3 iterations 不够消除 VM 调度噪声

**建议**：下次 authoritative run 使用 `ITERATIONS=10 WARMUPS=5 REPEAT=1000`，并分析 non-applied benchmarks 的 KR/K 是否收敛到 1.0。如果收敛，说明 applied 的数字更可信；如果不收敛，说明有系统性 bias 需要理解。
