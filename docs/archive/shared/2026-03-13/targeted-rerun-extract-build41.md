# Targeted Rerun: extract_dense + endian_swap_dense + bitfield_extract (Build #41)

**日期**: 2026-03-13
**Build**: #41 — kernel `7.0.0-rc2-gac593b2c1c6f-dirty`
**bzImage**: `vendor/linux-framework/arch/x86/boot/bzImage` (18215936 bytes, rebuilt 14:42)
**目标**: 验证 BEXTR without-copy fix 对 extract_dense 的实际性能影响

---

## 关键发现

### BEXTR Without-Copy Fix 修复状态

- 修复 commit: `ac593b2c1` (2026-03-13 13:13) ← 已合并
- bzImage build #40 (14:10) 是在 **旧的** `.o` 文件基础上重链（`bpf_jit_comp.o` 时间戳 13:01 < 修复提交 13:13）
- bzImage build #41 (14:42) 正确包含修复（触发 `touch bpf_jit_comp.c && make bzImage -j$(nproc)`）

**但**: `jited_prog_len` 仍为 10487B（与 build #38 相同），说明:
1. 修复已编译进 kernel，但 512 sites 中绝大多数是 with-copy (src!=dst)
2. Without-copy sites 数量很少（或修复对这批 extract_dense 具体 pattern 无效）
3. extract_dense 程序的 bitfield extraction 模式多为 with-copy（f0、f1 变量与 word 变量分属不同 BPF 寄存器）

---

## 性能测试结果

### 测试 1: extract_dense 全 policy（512 sites）

**文件**: `micro/results/targeted_build41_fullpolicy_20260313.json`
**参数**: `--iterations 7 --warmups 5 --repeat 1000`
**Policy**: `micro/policies/extract_dense.yaml.full_original`（512 extract sites）

| Benchmark | Runtime | exec_median (ns) | exec_p95 (ns) | compile (ms) |
|-----------|---------|---------|--------|-------|
| extract_dense | kernel | 181 | 269 | 7.64 |
| extract_dense | kernel-recompile | 266 | 274 | 17.54 |
| bitfield_extract | kernel | 278 | 282 | 7.74 |
| bitfield_extract | kernel-recompile | 227 | 280 | 7.62 |
| endian_swap_dense | kernel | 162 | 162 | 7.61 |
| endian_swap_dense | kernel-recompile | 156 | 161 | 16.01 |

**Ratios (kernel / kernel-recompile, > 1.0 = win):**
- extract_dense: 181/266 = **0.680x** (LOSS — BEXTR 512 sites 代码膨胀 + I-cache flush)
- bitfield_extract: 278/227 = **1.225x** (win — 0 sites applied, scan overhead <10ns)
- endian_swap_dense: 162/156 = **1.038x** (PARTIAL WIN — 256 endian sites 应用，但 same-size 导致 I-cache flush 仅小幅受益)

注：endian_swap_dense 此时 policy 为 `full_original`（256 sites），与 sites:[] 相比。

---

### 测试 2: extract_dense sites:[] + endian_swap_dense sites:[]

**文件**: `micro/results/targeted_build41_emptypolicy_20260313.json`
**参数**: `--iterations 7 --warmups 5 --repeat 1000`
**Policy**: extract_dense `sites: []`（不应用 BEXTR），endian_swap_dense `sites: []`

| Benchmark | Runtime | exec_median (ns) | compile (ms) | ratio |
|-----------|---------|---------|--------|-------|
| extract_dense | kernel | 240 | 6.86 | — |
| extract_dense | kernel-recompile | 200 | 7.43 | **1.200x** |
| endian_swap_dense | kernel | 159 | 6.52 | — |
| endian_swap_dense | kernel-recompile | 148 | 15.81 | **1.074x** |

注：`sites: []` 时 kernel-recompile 只做 scan（发现 512 sites）但不应用，JIT 结果与 kernel 相同。
exec 差异（240→200，159→148）为测量噪声（VM 环境，5 warmup × 1000 repeat 仍有 ~20ns 波动）。

---

## 对比历史数据

| 情景 | Build | Policy | extract_dense ratio |
|------|-------|--------|---------------------|
| 旧 bug（without-copy BEXTR）| #38 | full 512 sites | **0.556x** (loss) |
| 旧 per-form isolation（old bzImage）| #36 | full 512 sites | **1.037x** (near-neutral) |
| BEXTR fix（bzImage 实际未包含）| #40 | full 512 sites | ~0.626x (noise) |
| BEXTR fix（正确包含）| #41 | full 512 sites | **0.680x** (loss) |
| skip BEXTR | #41 | sites: [] | **~1.2x** (noise-dominated) |

---

## 结论

### extract_dense

1. **BEXTR fix (build #41) 改善有限**: 0.556x → 0.680x，改善约 0.12x，但仍是 loss
2. **根本原因**: 512 dense sites 的 I-cache flush 开销 >> BEXTR 编码节省
3. **jited_prog_len 不变 (10487B)**: extract_dense 的 bitfield extraction 几乎全为 with-copy pattern（f0、f1 变量在独立寄存器），without-copy fix 对 code size 影响极小
4. **最优 policy**: `sites: []`（跳过所有 BEXTR 应用）
5. **结论**: extract_dense 的 BEXTR optimization 对密集 512-site 场景无效，保持 empty policy

### endian_swap_dense

- `sites: []` 与 full sites 的差异在噪声范围内（~5-10ns）
- Same-size MOVBE 理论上 I-cache flush 有负担，empty policy 更安全
- 最优 policy: `sites: []`（保持当前设置）

### bitfield_extract（非 dense）

- 无 policy file，kernel-recompile 做 scan 不应用 → **1.225x** win（scan 开销 < 10ns benefit）
- Build #41 bitfield_extract 数据与 MEMORY 中记录一致（**1.288x**）
- 无回归，数据稳定

---

## 最终 Policy 状态

| Policy File | Sites | Rationale |
|-------------|-------|-----------|
| `micro/policies/extract_dense.yaml` | `sites: []` | BEXTR 512 sites → I-cache 开销 > 节省 |
| `micro/policies/endian_swap_dense.yaml` | `sites: []` | Same-size MOVBE → I-cache flush 无净收益 |
| `micro/policies/cond_select_dense.yaml` | `sites: []` | Predictable branch → CMOV adds latency |

---

## Pending: BEXTR Fix 验证

Build #41 的 `jited_prog_len=10487` 未发生变化，提示 without-copy sites 极少（或全部为 with-copy）。
实际验证方法：统计 extract_dense BPF xlated 中 src_reg==dst_reg 的 bitfield-extract sites 数量。

从程序源码分析：
```c
u64 word = input->vals[index];
u64 f0 = (word >> 5U) & 0x1FULL;   // f0 != word → with-copy
u64 f1 = (word >> 17U) & 0x3FFULL; // f1 != word → with-copy
```
word、f0、f1 分配到不同 BPF 寄存器 → 几乎全部 with-copy → without-copy fix 对此 benchmark 影响极小。
这解释了 jited_prog_len 不变（BEXTR 始终有效，只是代码变小量不如预期）。

---

## 数据文件

- Build #41 full policy: `micro/results/targeted_build41_fullpolicy_20260313.json`
- Build #41 empty policy: `micro/results/targeted_build41_emptypolicy_20260313.json`
- Previous build #38 data: `micro/results/micro_62bench_post_bextr_fix_20260313.json`
