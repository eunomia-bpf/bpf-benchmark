# BEXTR Without-Copy Bug Fix Report

**日期**: 2026-03-13
**状态**: 代码修复完成；bzImage 编译 + VM 验证待完成
**文件**: `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`

---

## 问题描述

在 `emit_bitfield_extract_core` 函数（L3310 区域）中，BEXTR 路径的条件仅检查：
1. CPU 有 BMI1 特性
2. effective_mask 是低位连续字段

**缺失**：未检查 `src_reg != dst_reg`（with-copy 模式）。

### 后果

- **without-copy 模式**（`src_reg == dst_reg`，约 25% 的 site）：
  - 原本：`SHR + AND` = 6B（2 条指令）
  - BEXTR 路径：`MOV_imm32 + BEXTR` = 9B（2 条指令）
  - **净效果：+3B/site，代码反而变大！**

- **with-copy 模式**（`src_reg != dst_reg`，约 75% 的 site）：
  - 原本：`MOV + SHR + AND` = 12B（3 条指令）
  - BEXTR 路径：`MOV_imm32 + BEXTR` = 9B（2 条指令）
  - **净效果：−3B/site（正确优化）**

### 实测影响（来自 BEXTR fix #169）

`extract_dense`（512 sites）：
- Stock：149 ns median
- Recompile（旧 emitter，含 without-copy bug）：268 ns
- **Ratio：0.556x（灾难性回归）**

jited size：11255 → 10487（−768B，仅 1.5B/site）

与预期 3B/site 相比，1.5B/site 恰好对应约 25% without-copy site 拉低了平均值（75% × 3B − 25% × 3B = 1.5B/site net）。

---

## 修复内容

**文件**: `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c`
**函数**: `emit_bitfield_extract_core`

### 修改前（原始代码，~L3310）

```c
if (boot_cpu_has(X86_FEATURE_BMI1) &&
    bitfield_low_mask_width(effective_mask, &field_width)) {
```

### 修改后

```c
if (boot_cpu_has(X86_FEATURE_BMI1) &&
    src_reg != dst_reg &&
    bitfield_low_mask_width(effective_mask, &field_width)) {
```

同时更新了函数上方注释，明确说明：
- BEXTR 仅用于 with-copy pattern（dst != src）
- without-copy site 回退到 SHR+AND（更快、更小）

---

## 预期改善

修复后 `extract_dense` 预期：
- without-copy site（~25%，128 sites）：回退到 SHR+AND（6B，不变）
- with-copy site（~75%，384 sites）：继续用 BEXTR（9B，节省 3B）
- **总 size reduction**：384 × 3B = 1152B（约 −10.2%，vs 旧的 −6.8%）
- 且消除 without-copy site 的 BEXTR latency 惩罚（3c vs 2c）
- **预计 ratio 改善**：从 0.556x → 约 0.70-0.80x（仍有 BEXTR latency 问题，但 without-copy overhead 消除）

`bitfield_extract`（非 dense，site 数少）预计无回归。

---

## 后续验证（TODO）

1. **编译 bzImage**：
   ```bash
   cd /home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework
   make -j$(nproc) bzImage
   ```

2. **VM 中跑 extract_dense 对比**：
   ```bash
   source /home/yunwei37/workspace/.venv/bin/activate
   vng --run vendor/linux-framework/arch/x86/boot/bzImage --exec \
     'cd /home/yunwei37/workspace/bpf-benchmark && python3 micro/run_micro.py \
       --runtime kernel --bench extract_dense --bench bitfield_extract --bench rotate_dense \
       --iterations 2 --warmups 1 --repeat 200 \
       --output micro/results/bextr_without_copy_fix_stock.json'
   ```

3. **Recompile 对比**（用 policy 重编）：
   ```bash
   vng --run vendor/linux-framework/arch/x86/boot/bzImage --exec \
     'cd /home/yunwei37/workspace/bpf-benchmark && python3 micro/run_micro.py \
       --runtime kernel --bench extract_dense --bench bitfield_extract --bench rotate_dense \
       --iterations 2 --warmups 1 --repeat 200 \
       --recompile-policy micro/policies/ \
       --output micro/results/bextr_without_copy_fix_recompile.json'
   ```

4. **检查 jited size**：确认 extract_dense 的 jited 从 10487 减少到约 9715（增加 ~772B 额外节省）

5. **更新 MEMORY.md 和 plan doc** 中 extract_dense 的 ratio

---

## 数据引用

- 原始回归数据：`docs/tmp/cmov-bextr-regression-investigation.md`
- BEXTR fix #169 数据：`micro/results/micro_62bench_post_bextr_fix_20260313.json`
- 修改文件：`vendor/linux-framework/arch/x86/net/bpf_jit_comp.c` L3311
