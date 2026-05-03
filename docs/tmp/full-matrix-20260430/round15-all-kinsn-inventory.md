# Round 15 — 全量 kinsn inventory

调研日期：2026-05-01

## 调研范围与方法

- 枚举 `module/x86/` 和 `module/arm64/` 下所有 `.c` 源文件及其 `Makefile`
- 检查每个模块注册的 `bpf_kinsn` descriptor（`DEFINE_KINSN_V2_MODULE`）
- 检查 `bpfopt/crates/bpfopt/src/pass.rs` 中 `KinsnRegistry` 的 BTF ID 字段
- 检查 `bpfopt/crates/bpfopt/src/passes/mod.rs` 和各 pass 文件确认哪些 pass 消费哪个 kinsn
- 检查 `daemon/crates/bpfget/src/lib.rs` 的 `KINSN_PROBE_TARGETS` 列表
- 检查 `corpus/config/benchmark_config.yaml` 的 12-pass 默认策略
- 检查 `docs/kernel-jit-optimization-plan.md` 中规划/研究过的 kinsn
- 参考 `docs/tmp/setcc_cset_kinsn_research_20260430.md`、`andn_kinsn_research_20260430.md`、`bls_kinsn_research_20260430.md`、`region_kinsn_research_20260430.md`

---

## 完整 kinsn inventory 表

### 已实现的 kinsn（module 层有 `.c` 文件）

| kinsn 名 | kernel 端实现文件 | x86 JIT emit | ARM64 JIT emit | bpfopt pass 消费 | daemon bpfget 探针 | 12-pass 默认策略 | 状态 |
|---|---|---|---|---|---|---|---|
| `bpf_rotate64` | `module/x86/bpf_rotate.c`<br>`module/arm64/bpf_rotate.c` | ✅ ROL + MOV | ✅ EXTR | `rotate` pass | ✅ `bpf_rotate64` | ✅ x86 + ARM64 | **已启用** |
| `bpf_select64` | `module/x86/bpf_select.c`<br>`module/arm64/bpf_select.c` | ✅ TEST+CMOV | ✅ TST+CSEL | `cond_select` pass | ✅ `bpf_select64` | ✅ x86 + ARM64 | **已启用** |
| `bpf_extract64` | `module/x86/bpf_extract.c`<br>`module/arm64/bpf_extract.c` | ✅ SHR+AND | ✅ UBFM | `extract` pass | ✅ `bpf_extract64` | ✅ x86 + ARM64 | **已启用** |
| `bpf_endian_load16` | `module/x86/bpf_endian.c`<br>`module/arm64/bpf_endian.c` | ✅ MOVZX+ROL16 | ✅ LDRH+REV16+AND | `endian_fusion` pass (16位分支) | ⚠️ **未探针**（bpfget 只探 `bpf_endian_load64` 作为哨兵）| ✅ x86 + ARM64 (随 endian_fusion) | **已启用**（依赖 endian_load64 哨兵） |
| `bpf_endian_load32` | `module/x86/bpf_endian.c`<br>`module/arm64/bpf_endian.c` | ✅ MOV+BSWAP32 | ✅ LDR_W+REV_W | `endian_fusion` pass (32位分支) | ⚠️ **未探针**（随 endian_load64 哨兵）| ✅ x86 + ARM64 (随 endian_fusion) | **已启用**（依赖 endian_load64 哨兵） |
| `bpf_endian_load64` | `module/x86/bpf_endian.c`<br>`module/arm64/bpf_endian.c` | ✅ MOV64+BSWAP64 | ✅ LDR_X+REV_X | `endian_fusion` pass (64位分支) | ✅ `bpf_endian_load64` | ✅ x86 + ARM64 | **已启用** |
| `bpf_memcpy_bulk` | `module/x86/bpf_bulk_memory.c`<br>`module/arm64/bpf_bulk_memory.c` | ✅ REP MOVSB | ✅ LDP/STP 循环 | `bulk_memory` pass | ⚠️ 探针名 `bpf_bulk_memcpy`（兼容旧名） | ✅ x86 + ARM64 | **已启用** |
| `bpf_memset_bulk` | `module/x86/bpf_bulk_memory.c`<br>`module/arm64/bpf_bulk_memory.c` | ✅ REP STOSB | ✅ STP 循环 | `bulk_memory` pass | ⚠️ 探针名 `bpf_bulk_memset`（兼容旧名） | ✅ x86 + ARM64 | **已启用** |
| `bpf_prefetch` | `module/x86/bpf_prefetch.c`<br>`module/arm64/bpf_prefetch.c` | ✅ PREFETCHT0 | ✅ PRFM PLDL1KEEP | `prefetch` pass | ✅ `bpf_prefetch` | ✅ x86 + ARM64 | **已启用** |
| `bpf_ccmp64` | ❌ x86 无<br>`module/arm64/bpf_ccmp.c` | ❌ 无 x86 emit | ✅ CMP+CCMP+CSET | `ccmp` pass | ✅ `bpf_ccmp64` | ✅ **仅 ARM64** | **已启用（ARM64 only）** |
| `bpf_ldp128` | ❌ x86 无<br>`module/arm64/bpf_ldp.c` | ❌ 无 x86 emit | ✅ LDP Xt,Xt2,[Xn] | **无 pass** | ❌ 未探针 | ❌ 不在 12-pass | **已实现 module 但无 pass** |
| `bpf_stp128` | ❌ x86 无<br>`module/arm64/bpf_stp.c`（同文件）| ❌ 无 x86 emit | ✅ STP Xt,Xt2,[Xn] | **无 pass** | ❌ 未探针 | ❌ 不在 12-pass | **已实现 module 但无 pass** |
| `bpf_speculation_barrier` | `module/x86/bpf_barrier.c`<br>`module/arm64/bpf_barrier.c` | ✅ LFENCE | ✅ DSB SY + ISB | **无 pass**（已留桩） | ❌ 未探针 | ❌ 不在 12-pass | **已实现 module 但暂不评估** |

### 仅在设计/调研文档中讨论、尚未实现的 kinsn 候选

| kinsn 候选名 | 设计状态 | x86 原语 | ARM64 原语 | 调研文档 | 推荐 |
|---|---|---|---|---|---|
| `bpf_setcc` | 📝 调研完成，待实现 | `cmp/test; mov 0; setcc` | `cmp/tst; cset` | `setcc_cset_kinsn_research_20260430.md` | **Round 16/17 候选** — 9417 sites |
| `bpf_andn` | ❌ 不做第一波 | BMI1 ANDN | ARM64 BIC | `andn_kinsn_research_20260430.md` | 暂缓 — 全部需 liveness proof |
| `bpf_blsi/blsr` | ⏸ 后续 phase | BMI1 BLSI/BLSR | 无直接对应 | `bls_kinsn_research_20260430.md` | 暂缓 — 支持 app 0 sites |
| region kinsn | ⏸ 后续 phase | 通用多寄存器区域 | 同 | `region_kinsn_research_20260430.md` | 等 kinsn v3 ABI 收敛 |

---

## bpfget 探针与 pass 关联

`daemon/crates/bpfget/src/lib.rs` 中 `KINSN_PROBE_TARGETS` 列表共探针 **8 个逻辑 kinsn**（其中 2 个有旧名兼容）：

```
bpf_rotate64        → probe: ["bpf_rotate64"]
bpf_select64        → probe: ["bpf_select64"]
bpf_ccmp64          → probe: ["bpf_ccmp64"]
bpf_prefetch        → probe: ["bpf_prefetch"]
bpf_extract64       → probe: ["bpf_extract64"]
bpf_endian_load64   → probe: ["bpf_endian_load64"]   ← 哨兵，代表整个 endian 模块
bpf_bulk_memcpy     → probe: ["bpf_bulk_memcpy", "bpf_memcpy_bulk"]
bpf_bulk_memset     → probe: ["bpf_bulk_memset", "bpf_memset_bulk"]
```

**注意**：`bpf_endian_load16` 和 `bpf_endian_load32` 在 `bpfget` 中不单独探针，只通过 `bpf_endian_load64` 的存在来推断整个 endian 模块在线。`bpfopt` 中三者有独立 BTF ID 字段，由 `bpfopt --target` 解析时单独填入。

**完全未探针的 module**：`bpf_ldp128`、`bpf_stp128`、`bpf_speculation_barrier` — 这三个 module 已编译进 `module/arm64/`（以及 barrier 的 `module/x86/`），但 bpfget、bpfopt、daemon 全程不感知。

---

## 12-pass 默认策略 vs kinsn 依赖

`corpus/config/benchmark_config.yaml` 中的 12-pass（x86 不含 ccmp，ARM64 含 ccmp）：

| pass 名 | 依赖 kinsn | x86 模块 | ARM64 模块 |
|---|---|---|---|
| `wide_mem` | 无（纯 bytecode 替换） | 不需要 | 不需要 |
| `rotate` | `bpf_rotate64` | `bpf_rotate.ko` | `bpf_rotate.ko` |
| `cond_select` | `bpf_select64` | `bpf_select.ko` | `bpf_select.ko` |
| `extract` | `bpf_extract64` | `bpf_extract.ko` | `bpf_extract.ko` |
| `endian_fusion` | `bpf_endian_load{16,32,64}` | `bpf_endian.ko` | `bpf_endian.ko` |
| `map_inline` | 无 | — | — |
| `const_prop` | 无 | — | — |
| `dce` | 无 | — | — |
| `bounds_check_merge` | 无 | — | — |
| `skb_load_bytes_spec` | 无 | — | — |
| `bulk_memory` | `bpf_memcpy_bulk` + `bpf_memset_bulk` | `bpf_bulk_memory.ko` | `bpf_bulk_memory.ko` |
| `prefetch` | `bpf_prefetch` | `bpf_prefetch.ko` | `bpf_prefetch.ko` |
| `ccmp`（仅 ARM64）| `bpf_ccmp64` | ❌ 无 | `bpf_ccmp.ko` |

`wide_mem` pass 不依赖任何 kinsn（纯 bytecode 替换，不发 kinsn call）。

---

## 架构不对称性汇总

| kinsn | x86 实现 | ARM64 实现 | 说明 |
|---|---|---|---|
| `bpf_rotate64` | ✅ ROL | ✅ EXTR | 两架构均有，原语不同但等效 |
| `bpf_select64` | ✅ CMOV | ✅ CSEL | 两架构均有 |
| `bpf_extract64` | ✅ SHR+AND | ✅ UBFM | 两架构均有 |
| `bpf_endian_load{16,32,64}` | ✅ | ✅ | 两架构均有 |
| `bpf_memcpy_bulk` | ✅ REP MOVSB | ✅ LDP/STP 循环 | 两架构均有，实现差异大 |
| `bpf_memset_bulk` | ✅ REP STOSB | ✅ STP 循环 | 两架构均有 |
| `bpf_prefetch` | ✅ PREFETCHT0 | ✅ PRFM PLDL1KEEP | 两架构均有 |
| `bpf_ccmp64` | **❌ 无 x86** | ✅ CMP+CCMP+CSET | **ARM64 专属**；x86 有 LAHF/SETcc 但 ccmp chain 语义不直接映射 |
| `bpf_ldp128` | **❌ 无 x86**（设计决策：SSE/AVX FPU 开销不值得）| ✅ LDP | **ARM64 专属**；x86 用 `bulk_memory` 覆盖同类场景 |
| `bpf_stp128` | **❌ 无 x86** | ✅ STP | **ARM64 专属** |
| `bpf_speculation_barrier` | ✅ LFENCE | ✅ DSB SY + ISB | 两架构均有，但无 pass 激活 |

---

## 可以在 round 16/17 新增 pass 激活的 kinsn

### 1. `bpf_ldp128` + `bpf_stp128`（ARM64 专属，module 已实现）

- **kernel module**：`module/arm64/bpf_ldp.c`，已注册 `bpf_ldp128_desc` + `bpf_stp128_desc`，emit_arm64 完整
- **ARM64 JIT emit**：✅ 单条 LDP / STP 指令，1 insn 替换 2 个顺序 LDX/STX
- **缺什么**：
  1. bpfget KINSN_PROBE_TARGETS 未添加 probe
  2. daemon missing_target_kinsns 未加 ldp/stp case
  3. bpfopt KinsnRegistry 无 ldp128/stp128 BTF ID 字段
  4. 无对应 bpfopt pass（扫描相邻 LDX_MEM/STX_MEM 对，emit kinsn call）
  5. 不在 benchmark_config.yaml
- **ROI**：ARM64 corpus 相邻 64-bit load/store pair 密度高（plan doc：当前 JIT 完全没有 LDP/STP）；单 site 节省约 1 insn 发射，store pair 对 store-intensive 路径收益更明显

### 2. `bpf_speculation_barrier`（两架构 module 已实现，无 pass）

- **kernel module**：`module/x86/bpf_barrier.c`（LFENCE）、`module/arm64/bpf_barrier.c`（DSB SY + ISB）
- **实现状态**：emit_x86 + emit_arm64 完整，已注册 descriptor
- **缺什么**：bpfget/daemon/bpfopt 全程未探针；无对应 pass；plan doc 标注「⏸ 暂不评估」
- **ROI**：非性能类，属于 Spectre v1 缓解，论文 story 价值不明显；建议继续暂缓

### 3. `bpf_setcc`（两架构 module 均未实现，仅调研完成）

- **状态**：`docs/tmp/setcc_cset_kinsn_research_20260430.md` 调研完成，结论 ✅ 推荐第一波实现
- **需要**：module 新增（x86 SETcc + ARM64 CSET），bpfopt 新 pass，daemon/bpfget 探针
- **ROI**：supported runtime corpus 9417 static sites（Tetragon 8832、Cilium 401、Calico 91、BCC 79）

---

## 200 字以内总结

项目 kernel module 层共实现 **13 个 kinsn**（不计 setcc 等未实现候选）：
- `bpf_rotate64`、`bpf_select64`、`bpf_extract64`、`bpf_endian_load{16,32,64}`（各 3 kinsn 共 5 variant）、`bpf_memcpy_bulk`、`bpf_memset_bulk`、`bpf_prefetch`、`bpf_ccmp64`、`bpf_ldp128`、`bpf_stp128`、`bpf_speculation_barrier`。
- 其中 **10 个**已接入 bpfopt pass 并纳入 12-pass 默认策略（ccmp 仅 ARM64）。
- **3 个已实现但无 pass 激活**：`bpf_ldp128`、`bpf_stp128`（ARM64 module ✅，pass/daemon 探针缺失）、`bpf_speculation_barrier`（两架构 module ✅，暂无策略接入）。
- round 16/17 直接可加的候选：`bpf_ldp128/stp128`（ARM64 module 完整，只需写 pass + daemon 探针）和 `bpf_setcc`（需新 module + pass，ROI 最大）。
- `bpf_endian_load16/32` 在 bpfget 无独立探针（靠 endian_load64 哨兵推断），属于 bpfget 轻微不完整，但 pass 已正确使用三者。
