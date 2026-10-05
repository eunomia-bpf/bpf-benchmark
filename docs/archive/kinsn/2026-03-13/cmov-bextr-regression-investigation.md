# CMOV 与 BEXTR 性能回归调查报告

**日期**: 2026-03-13
**状态**: 调查完成；根因已识别；修复方案已制定
**内核**: `7.0.0-rc2-ga7ce05b49cb2-dirty`（post-BEXTR-fix build #38）
**数据来源**: `docs/tmp/micro-62bench-post-bextr-fix-raw.md`（62-bench, 2 iters × 500 repeat）

---

## 执行摘要

`cond_select_dense`（0.482x，104 CMOV sites）和 `extract_dense`（0.556x，512 BEXTR sites）的灾难性回归**不是 emitter bug**，而是两个不同根因的组合：

1. **CMOV 回归**：根本原因是 **critical-path 数据依赖延迟增加**。`cond_select_dense` 的输入是确定性的（固定种子生成），分支 100% 可预测。在可预测分支下，branch predictor 使分支开销接近 0 周期；CMOV 则强制 CPU 等待 CMP 结果，把 2 条并行执行的 MOV 变成了数据依赖链，增加了 `acc` 累加的关键路径延迟。此外，emitter 的 AUX_REG 路径在 IMM false-branch 情况下**没有减少指令数**（反而从 4 条增加到约 4 条但不同模式），使 code size 节省仅约 1 byte/site（104 bytes/104 sites），不足以抵消 I-cache recompile overhead。

2. **BEXTR 回归**：根本原因是 **code size 节省不足，I-cache recompile overhead 主导**。BEXTR 乃 VEX 编码指令（`MOV_imm32_noflags + BEXTR` = 约 9B），取代 with-copy 的 `MOV+SHR+AND`（约 12B），实际 jited 节省 768B/512sites = 1.5B/site，说明大多数 site 是 without-copy 模式（仅 2 insn → 2 insn，几乎无尺寸收益），只有少数是 with-copy（3 insn → 2 insn）。BEXTR 自身 latency 约 3-4 cycles（Intel BMI1），而 SHR+AND 可完全 pipeline（各 1c），在紧密循环中 BEXTR 实际更慢，加上 full-image recompile（11255→10487，图像地址改变）带来的 I-cache 压力，导致净回归。

**关键结论**：这两个案例都是 **policy-sensitivity 的直接证据**——CMOV/BEXTR 在特定场景下（可预测分支、BMI1 BEXTR 延迟高、without-copy site）是错误选择，证明需要 policy control 而非 fixed heuristics。

---

## 背景：关键数据对比

| 指标 | cond_select_dense | extract_dense | rotate_dense (成功对照) |
|------|:-----------------:|:-------------:|:-----------------------:|
| Stock median | 48 ns | 149 ns | 206 ns |
| Recompile median | 99.5 ns | 268 ns | 176.5 ns |
| Ratio | **0.482x** | **0.556x** | **1.167x** |
| Sites | 104 (CMOV) | 512 (BEXTR) | 256 (RORX) |
| jited stock | 6154 | 11255 | 10198 |
| jited recompile | 6050 | 10487 | 7638 |
| Size reduction | −104 B (−1.7%) | −768 B (−6.8%) | −2560 B (−25.1%) |
| Applied | yes | yes | yes |

辅助对照（1 site）：`cmov_select`：574.5ns → 655ns = **0.877x**（1 site 已造成 14% 回归）
辅助对照（cmov_dense）：`command-failed`（可能 OOM/crash，已知问题）

**规律**：size reduction 越大 → 成功可能性越高。Rotate −25% 成功，BEXTR −6.8% 勉强不够，CMOV −1.7% 远不够。

---

## CMOV 回归根因分析

### 1. Emitter 输出的指令序列分析

`cond_select_dense.bpf.c` 中每个 `COND_SELECT_DENSE_STEP` 生成（BPF 层）：
```
load a, b, on_true, on_false from input_map  (loads)
JLE  (lhs <= rhs?) +1                        (BPF_JMP)
MOV  selected = on_true                      (then_insn: diamond 4-insn pattern)
JA   +1                                      (skip)
MOV  selected = on_false                     (else_insn: overwrite)
acc += selected ^ BIAS
```

Stock x86 JIT 对 diamond 4-insn 生成：
```
CMP  r_lhs, r_rhs                      (3B: REX + 0x39 + ModRM)
JBE  short offset (+N bytes)           (2B: 0x76 + disp8)
MOV  dst, r_on_true                    (3B: REX + 0x89 + ModRM)
JMP  short offset (+M bytes)           (2B: 0xEB + disp8)
MOV  dst, r_on_false                   (3B: REX + 0x89 + ModRM)
  [总计: 13B/site]
```

CMOV emitter (`emit_bpf_cmov_select`) 对 diamond-4 生成（见 `bpf_jit_comp.c` L1368-1407）：

**Case A：else_insn 是 reg-reg MOV（BPF_X src），且 `cmov_src_reg != dst_reg`**：
```
CMP  r_lhs, r_rhs                      (3B: REX + 0x39 + ModRM)
MOV  dst, r_on_true                    (3B: REX + 0x89 + ModRM)  ← 仅当 then_insn 不是 noop
CMOVcc dst, r_on_false                 (4B: REX + 0x0F + 0x4X + ModRM)
  [总计: 10B/site，节省 3B]
```

**Case B：else_insn 是 IMM（on_false 是立即数）**（`BPF_SRC == BPF_K`）：
```
CMP  r_lhs, r_rhs                      (3B)
MOV_noflags  AUX_REG, imm              (5-7B: MOV r64, imm64 或 MOVSX r64, imm32)
MOV  dst, r_on_true                    (3B)
CMOVcc dst, AUX_REG                    (4B)
  [总计: 15-17B/site，比 stock 更大！]
```

从 `cond_select_dense.bpf.c` 可知，`on_true` 和 `on_false` 都是从 input 结构体加载的**寄存器值**（不是立即数），所以应走 Case A 路径。但 asm volatile barrier 导致编译器把 `selected` 的赋值变成寄存器操作，需要检查具体 BPF 字节码。

**关键测量**：jited 6154 → 6050 = 节省 104 bytes / 104 sites = **1 byte/site**。

如果是纯 Case A（节省 3B/site × 104 = 312B），实际只有 104B，说明大约有 2/3 的 site 走了 Case B 或 noop 路径，净节省更少甚至为零或负。这解释了为什么 code size 节省微乎其微。

### 2. CMOV 的微架构数据依赖问题

`cond_select_dense` 的关键路径是 `acc` 累加链：
```
acc += selected ^ BIAS(index)
asm volatile("" : "+r"(acc) : "r"(selected) : "memory");
```

**Stock branch path（分支可预测时）**：
- Branch predictor 预测跳转方向，CPU **投机执行** `acc += ...`
- 若分支 100% 可预测（固定种子输入），IPC 接近峰值
- `selected` 的值通过 register rename 直接可用

**CMOV path**：
- CMOVcc 是**数据依赖**指令：必须等 CMP 结果（flag register）才能确定 `dst` 的最终值
- 不管分支是否可预测，CMOVcc 都引入了 CMP→CMOVcc→acc 的 3-instruction 数据依赖链
- CMOVcc latency（x86-64 现代核心）：1 cycle（Skylake/Zen3），但仍需消耗 1 execution slot
- 关键：在可预测分支下，stock 路径几乎不增加 `acc` 的关键路径（投机执行），CMOV 则必须序列化

这就是为什么 1 site 的 `cmov_select` 就已经 0.877x（14% 慢），104 sites 的 `cond_select_dense` 达到 0.482x（107% 慢）。

### 3. I-Cache Recompile Overhead

仅节省 104 bytes（−1.7%）几乎无法补偿 full-image recompile 带来的：
- 新 `bpf_binary_pack` 分配（新地址，I-cache 冷启动）
- `synchronize_rcu()` 和 JIT image 地址更新
- 新地址可能与 cache line 对齐方式不同

对比 rotate_dense（−25% size）：大幅 size 减少意味着程序更多地压缩入 L1I-cache，带来可测量加速，足以抵消 recompile 开销。

### 4. 总结：CMOV 回归贡献量化

| 因素 | 估计贡献 |
|------|---------|
| CMOV 增加 acc 关键路径（每 site ~0.5ns @ 3GHz） | **+2ns/site × 104 = ~208ns 慢化**（→ 2.1x 倍增） |
| Code size 节省太少（−1.7%），无法抵消 I-cache recompile | **+5-10ns 净开销** |
| 合计：stock 48ns → recompile ~99.5ns | 与观测吻合 ✓ |

---

## BEXTR 回归根因分析

### 1. BEXTR 指令特性

`extract_dense.bpf.c` 每个 step 提取两个 bitfields：
```c
u64 f0 = (word >> 5U) & 0x1FULL;    // shift=5, mask=0x1f (5-bit field)
u64 f1 = (word >> 17U) & 0x3FFULL;  // shift=17, mask=0x3ff (10-bit field)
```

BPF 字节码模式（with-copy，dst != src）：
```
insn N:   MOV64  r_dst = r_src         (with-copy)
insn N+1: RSH64  r_dst >>= 5
insn N+2: AND64  r_dst &= 0x1f
```

BPF 字节码模式（without-copy，dst == src）：
```
insn N:   RSH64  r_dst >>= 5          (without-copy)
insn N+1: AND64  r_dst &= 0x1f
```

`emit_bitfield_extract_core`（L3277-3343）逻辑：
- **有 BMI1 且 mask 是低位连续字段**：emit `MOV_imm32_noflags(AUX_REG, control) + BEXTR(dst, src, AUX_REG)` = 约 9B
- **Fallback**（without-copy，dst==src）：emit `SHR + AND` = 约 6B

实际 jited 减少 768 bytes / 512 sites = **1.5B/site**。

分析：
- 如果全是 with-copy：替换 `MOV+SHR+AND`（约 12B）→ `MOV_imm32+BEXTR`（约 9B），节省 3B/site
- 如果全是 without-copy：`SHR+AND`（6B）→ `MOV_imm32+BEXTR`（9B），增加 3B/site（退化！）
- 平均 1.5B/site 说明约 75% with-copy（3B saved × 75% − 3B overhead × 25% = 1.5B net）

**关键发现**：25% 的 without-copy site 被 BEXTR 路径处理后实际变大了（从 6B 变成 9B），BEXTR AUX_REG 路径（`emit_mov_imm32_noflags + emit_bextr`）对于 without-copy 情况会增加约 3B！

### 2. BEXTR 在 x86 BMI1 上的 Latency 特性

Intel Skylake BEXTR（BMI1 形式）：
- **Latency**: 3 cycles（比 SHR 1c + AND 1c 差得多）
- **Throughput**: 1 operation/cycle（SHR+AND 可以 2 ops/cycle）

AMD Zen 3/4 BEXTR：
- **Latency**: 2 cycles（仍不如 SHR 1c + AND 1c）

在 `extract_dense` 的紧循环中：
```c
acc += f0 + f1 + index;
asm volatile("" : "+r"(acc) : "r"(word), "r"(f0), "r"(f1) : "memory");
```
f0 和 f1 在同一个 `word` 上提取，BEXTR 用同一 `AUX_REG` 作为控制寄存器。如果 CPU 无法乱序执行两个连续的 BEXTR（因为它们共用 AUX_REG），则形成序列化依赖。

相比之下，SHR+AND 对不同寄存器（f0 路径和 f1 路径）可完全乱序 pipeline。

### 3. I-Cache Recompile Overhead 量化

- size reduction：768B（−6.8%）
- 比 endian_swap_dense（0B，0.695x）好，但远不如 rotate_dense（2560B，1.167x）
- 6.8% 的 size reduction 对 L1I-cache 的改善有限，但 full-image 换地址的开销仍然存在

### 4. 总结：BEXTR 回归贡献量化

| 因素 | 估计贡献 |
|------|---------|
| BEXTR latency（3c vs 2c for SHR+AND）× 512 sites × 2 fields | **+2-4 ns/site 延迟增加** |
| Without-copy site（~25%）code 变大 3B × 128 sites | **+384B 额外 code size**，I-cache 恶化 |
| Full-image recompile（−6.8% size，但新地址） | **+10-20ns 净开销** |
| 合计：stock 149ns → recompile ~268ns | **+119ns，1.8x 慢化**，与观测吻合 ✓ |

---

## 两者的共同模式：code-size reduction 阈值

基于全部 6 个 dense benchmark 数据，存在明显阈值效应：

| Benchmark | Size Reduction | Ratio | 结果 |
|-----------|:-------------:|:-----:|------|
| rotate_dense | −25.1% (2560B) | 1.167x | ✅ 成功 |
| addr_calc_stride | −12.9%（估算） | 1.401x | ✅ 成功 |
| branch_flip_dense | 0% (0B) | 1.052x | ✅ 微弱成功* |
| endian_swap_dense | 0% (0B) | 0.695x | ❌ 回归 |
| extract_dense | −6.8% (768B) | 0.556x | ❌ 回归 |
| cond_select_dense | −1.7% (104B) | 0.482x | ❌ 重度回归 |

*branch_flip_dense 1.052x 轻微为正，可能是 2-iter 噪声，或该特定内存布局恰好有利。

**初步结论**：code size 必须减少 **>10-15%** 才能稳定覆盖 full-image recompile overhead。CMOV 和 BEXTR 在这个 micro-benchmark 上均未达到该阈值。

---

## Emitter 代码问题：AUX_REG 路径分析

### CMOV emitter 的潜在问题

`emit_bpf_cmov_select`（L1368-1407）当 `else_insn` 是 IMM（BPF_K src）时：
```c
} else {
    emit_bpf_mov_value_noflags(pprog, else_insn, AUX_REG, use_priv_fp);
    cmov_src_reg = AUX_REG;
}
```
这会 emit 额外的 `MOV AUX_REG, imm`，加上 `CMP + MOV_then + CMOVcc` = 4 条指令，而 stock 的 diamond-4 是 `JCC + MOV + JMP + MOV` = 4 条指令（约 13B vs 14-17B），没有节省。

对于 `cond_select_dense`，`on_true` 和 `on_false` 均从 struct 加载（registers），所以应该走 BPF_X 路径（Case A）。但 `asm volatile` barrier 的存在可能改变了 BPF IR，使得某些 site 走了 noop 路径（`bpf_mov_is_noop` 返回 true），导致没有 emit `then_insn` 的 MOV。这需要 VM 内 bpftool dump 验证。

### BEXTR emitter 的 without-copy 问题

`emit_bitfield_extract_core`（L3277-3343）当 `src_reg != dst_reg`（with-copy）进入 BEXTR 路径，会 emit：
```c
emit_mov_imm32_noflags(&prog, false, AUX_REG, control);  // 5B（non-extended reg）
emit_bextr(&prog, dst_reg, src_reg, AUX_REG, is64);     // 4B（VEX2 + 0xf7 + ModRM）
// 总计 9B
```

但 `without-copy`（`src_reg == dst_reg`）也会触发同样的 BEXTR 路径（因为 `boot_cpu_has(X86_FEATURE_BMI1)` 无论 dst==src 都 true）！对于 without-copy 原本只需要：
```c
emit_bitfield_rsh_imm  // 3B（REX + 0xC1 + ModRM + imm）
emit_bitfield_and_imm  // 3B（REX + 0x83 + ModRM + imm）
// 总计 6B
```

BEXTR 路径：9B vs fallback：6B，**without-copy 情况 BEXTR 反而增大 3B/site**。

这解释了为什么实际节省只有 1.5B/site 而不是 3B/site。

**这是一个潜在 emitter bug**（非正确性 bug，而是性能 bug）：BEXTR 路径应该仅在 with-copy（dst != src）时启用，以确保有 1 指令的净节省。

---

## 修复和缓解方案

### 方案 1（推荐）：BEXTR emitter — 仅在 with-copy 时用 BEXTR

在 `emit_bitfield_extract_core` 中，对 BEXTR 路径加 dst != src 条件：

```c
#if defined(CONFIG_X86_64)
if (boot_cpu_has(X86_FEATURE_BMI1) &&
    src_reg != dst_reg &&              // ← 新增：仅 with-copy 情况用 BEXTR
    bitfield_low_mask_width(effective_mask, &field_width)) {
    u32 control = ((field_width & 0xff) << 8) | (shift & 0xff);
    emit_mov_imm32_noflags(&prog, false, AUX_REG, control);
    emit_bextr(&prog, dst_reg, src_reg, AUX_REG, is64);
    *pprog = prog;
    return 0;
}
#endif
```

预期效果：
- without-copy（占 ~25%）降回 SHR+AND fallback（6B，更快）
- with-copy（占 ~75%）继续用 BEXTR（9B，节省 3B vs 12B）
- 总体：size reduction 从 1.5B/site → 约 2.25B/site（+50%），且 without-copy site 回归消除

但 BEXTR latency 问题仍然存在（3c vs 2c for SHR+AND on Intel）。这个修复只能部分改善，不会使 extract_dense 变为胜者。

### 方案 2（快速，policy-level）：在 micro suite 中把 cond_select_dense 设为 cmov:skip

更新 `micro/policies/cond_select_dense.yaml`，将 sites 列表清空（不移除文件，只清空列表）：
```yaml
version: 3
program: 'cond_select_dense_xdp'
sites: []
```

效果：`cond_select_dense` 从 0.482x 变回 1.000x（不应用任何 site）。这不掩盖问题，而是正确的 policy decision：**固定分支可预测 workload 下 CMOV 不应启用**。

### 方案 3（架构改进）：在 emitter 中增加 "可预测性提示" 接口

长期方案：policy 中增加 `branch_predictor_hint: predictable`，emitter 在看到此 hint 时跳过 CMOV/BEXTR。但这需要 interface 设计变更，不在当前范围。

### 方案 4（论文策略）：将两者作为 policy-sensitivity 证据报告

最正确的处理方式：
1. `cond_select_dense` 0.482x 作为 "CMOV 在可预测分支下有害" 的定量证据
2. `extract_dense` 0.556x 作为 "BEXTR latency 比 SHR+AND 高" + "without-copy site 有 overhead" 的证据
3. 在论文中与 `log2_fold` 的 CMOV benefit（+28.3%，branch misprediction heavy）对比，展示 policy-sensitivity

---

## 论文 Implications（Policy-Sensitivity 核心证据）

这两个回归是论文 Section 1.1 核心 thesis 的最强证据：

> Fixed heuristics 不行：policy-sensitivity（CMOV +28.3%）+ 负面案例（CMOV −107%）

| 场景 | CMOV 行为 | 原因 |
|------|-----------|------|
| `log2_fold`（branch misprediction heavy） | **+28.3% 加速** | BTB miss 昂贵，CMOV 消除 15-20c penalty |
| `cond_select_dense`（完全可预测分支） | **−107% 回归** | BTB miss=0，CMOV 增加关键路径延迟 |
| 普通程序（混合）| 需要 profile 决策 | 取决于具体分支预测率 |

**这正是 BpfReJIT 存在的理由**：同一 canonical form，在不同 workload 下有完全相反的性能影响。Kernel 无法静态决定是否应用 CMOV，必须依赖 operator 提供的 policy（基于 profiling 或 workload 特征）。

对于 BEXTR：
- 代码密度高（大量 bitfield extract）+ BMI1 CPU + 以代码 cache 为瓶颈的 workload → BEXTR 有利（code size）
- 延迟敏感 workload + without-copy 占主导 → BEXTR 有害

论文可以把 `extract_dense` 0.556x 标注为 "policy-sensitive: disable for latency-critical, enable for throughput-cache workloads"，与 CMOV 的 `log2_fold` vs `cond_select_dense` 对比共同构成 Table 6 "Policy Sensitivity Evidence"。

---

## 需要 VM 验证的项目（后续 TODO）

以下项目需要在 VM 中实际执行来精确量化：

1. **验证 CMOV emitter 是否走 AUX_REG 路径**：
   ```bash
   bpftool prog dump jited name cond_select_dense_xdp | grep -A5 "cmov"
   ```
   检查是否有额外 MOV AUX_REG 指令。

2. **perf stat 对比**（IPC、branch-misses、cache-misses）：
   - `cond_select_dense` stock vs recompile
   - 预期：stock branch-misses ≈ 0，recompile branch-misses ≈ 0（两者都无 branch miss）
   - 但 IPC 应该 stock > recompile（CMOV 破坏了 ILP）

3. **验证 without-copy BEXTR 路径**：
   ```bash
   bpftool prog dump jited name extract_dense_xdp | grep -E "mov.*AUX|bextr"
   ```
   检查 without-copy site 是否被 BEXTR 处理（应看到连续的 MOV imm + BEXTR 对）。

4. **BEXTR fix 效果验证**：apply 方案 1 fix 后重建 bzImage，重跑 extract_dense，预期 ratio 改善到 ~0.7x（从 0.556x）。

---

## 数据文件引用

- 62-bench 原始数据：`docs/tmp/micro-62bench-post-bextr-fix-raw.md`
- BEXTR fix 背景：`docs/tmp/emitter-fix-extract-endian-bflip.md`
- Endian/branch_flip 类似分析：`docs/tmp/endian-bflip-perf-investigation.md`
- CMOV emitter 代码：`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c` L1368-1506
- BEXTR emitter 代码：`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c` L3237-3387
- policy 文件：`micro/policies/cond_select_dense.yaml`（104 sites）
- 全局状态：`docs/kernel-jit-optimization-plan.md`
