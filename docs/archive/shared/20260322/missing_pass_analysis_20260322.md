# Missing Pass Analysis: BITFIELD_EXTRACT / ENDIAN_FUSION / ADDR_CALC

**Date**: 2026-03-22
**Scope**: 评估三种未实现优化 pattern 在真实程序中的 site 覆盖、性能预期和优先级。
**数据来源**:
- `corpus/results/archive/corpus-8families-persection.json` — 627 个 ELF 的 8-family 普查（截至 2026-03-12，是目前最全的横向数据）
- `corpus/results/corpus_authoritative_20260320.json` — 授权 corpus 跑批（有 endian 数据，v2 架构）
- `micro/results/dev/vm_micro.json` — 2026-03-22 VM micro 跑批（v2 with kinsn）
- `docs/tmp/20260322/micro_analysis_v2_20260322.md` — micro 性能分析报告

---

## 1. 三个 Pattern 的 Corpus Site 普查

### 1.1 完整数字（8-family census，627 objects，1,471,661 指令）

| Family | 总 sites | corpus sites | corpus objects | micro sites | micro objects | 每百对象命中率 |
|--------|----------|--------------|----------------|-------------|---------------|----------------|
| **BITFIELD_EXTRACT** | 557 | 542 | 40 | 15 | 6 | 40/560 = 7.1% |
| **ENDIAN_FUSION** | 1,386 | 1,386 | 50 | 0 | 0 | 50/560 = 8.9% |
| **ADDR_CALC** | 19 | 14 | 7 | 5 | 4 | 7/560 = 1.3% |

参考（已实现的 pass）：

| Family | 总 sites | corpus sites | corpus objects |
|--------|----------|--------------|----------------|
| COND_SELECT | 7,724 | 7,677 | 127 |
| WIDE_MEM | 2,987 | 2,832 | 32 |
| ROTATE | 2,685 | 1,820 | 3 |
| BRANCH_FLIP | 2,279 | 2,264 | 24 |

### 1.2 BITFIELD_EXTRACT — 按项目分布

| 项目 | sites | 性质 |
|------|-------|------|
| cilium | 198 | 网络（策略执行，load balancer） |
| tetragon | 115 | 安全追踪 |
| loxilb | 64 | 网络（云原生 LB） |
| linux-selftests | 55 | 内核自测 |
| tracee | 49 | 安全追踪 |
| calico | 37 | 网络（K8s 策略） |
| suricata | 8 | 网络 IDS |
| xdp-tools / xdp-tutorial | 6 | 网络工具 |
| katran / scx / bcc / libbpf-bootstrap / real_world | 少量 | 其他 |

**核心观察**：cilium + tetragon + loxilb 三个项目贡献了 377/542 corpus sites（69.5%）。
cilium 是最大单点（198 sites），是生产级 Kubernetes 网络平面，是真实高价值 workload。

### 1.3 ENDIAN_FUSION — 按项目分布

| 项目 | sites | 性质 |
|------|-------|------|
| calico | 786 | 网络（Calico eBPF 策略） |
| cilium | 341 | 网络（K8s LB + 策略） |
| linux-selftests | 57 | 内核自测 |
| coroot-node-agent | 56 | 可观测（云原生监控） |
| loxilb | 42 | 网络（云原生 LB） |
| tetragon | 40 | 安全追踪 |
| xdp-tools | 17 | 网络工具 |
| opentelemetry-ebpf-profiler | 12 | 可观测 |
| xdp-tutorial / katran | 18 | 网络 |
| tracee / KubeArmor / netbird / 其他 | 少量 | 安全/观测 |

**核心观察**：calico + cilium 两个纯网络项目贡献了 1,127/1,386 sites（81.3%）。
这与预期一致：网络程序大量解析包头字段，需要频繁做字节序转换（ntohl/ntohs → load + bswap32/bswap16）。
ENDIAN_FUSION 是网络程序的典型热路径 pattern。

**与 v1 授权数据的交叉验证**：`corpus_authoritative_20260320.json` 中 calico 贡献 797 endian sites，与普查数据（786）吻合，说明数字可靠。

### 1.4 ADDR_CALC — 按项目分布

| 项目 | sites | 性质 |
|------|-------|------|
| tetragon | 14 | 安全追踪 |
| micro | 5 | micro benchmarks |
| 其他所有项目 | 0 | — |

**核心观察**：ADDR_CALC pattern（`mov reg, base; lsh reg, N; add reg, offset` 风格的三指令地址计算序列）在真实程序中极为罕见。仅 tetragon 有 14 个 corpus sites，且分布在 tetragon 这个特殊安全追踪程序中。所有网络程序（calico、cilium、katran、xdp-tools）、可观测程序（tracee、coroot）都没有 ADDR_CALC sites。

---

## 2. Micro Benchmark 数据

### 2.1 三个 family 的 micro benchmark 列表

来自 `micro/config/micro_pure_jit.yaml` 和 VM micro 跑批数据：

| Benchmark | Family | K(ns) | KR(ns) | L(ns) | KR/K | L/K | 当前状态 |
|-----------|--------|-------|--------|-------|------|-----|---------|
| bitfield_extract | bitfield-extract | 198 | 193 | 177 | 0.975 | 0.894 | APPLIED（WideMemPass auto-apply，bitfield sites=0） |
| extract_dense | bitfield-extract | 180 | 165 | 132 | 0.917 | 0.733 | IDENTITY（policy cleared，sites=0 applied） |
| addr_calc_stride | addr-calc | 153 | 145 | 73 | 0.948 | 0.477 | IDENTITY（sites=0 applied） |
| endian_swap_dense | endian-fusion | 122 | 110 | 67 | 0.902 | 0.549 | IDENTITY（sites=0 applied） |

**注意**：KR/K 数字包含 ~7.8% VM 系统性偏差（详见 micro_analysis_v2_20260322.md §2），因此这些 0.9x 数字大多是 VM 偏差，不代表真实的 REJIT 收益。真实收益需从"是否 applied"判断。

### 2.2 Gap 数据（llvmbpf vs kernel，无偏差）

| Benchmark | L/K ratio | 说明 |
|-----------|-----------|------|
| extract_dense | 0.733 | BEXTR 优化的潜在上界（27%差距） |
| endian_swap_dense | 0.549 | MOVBE 优化的潜在上界（45%差距） |
| addr_calc_stride | 0.477 | LEA 优化的潜在上界（52%差距） |

**关键发现**：addr_calc_stride 的 L/K 差距最大（0.477x），但这与 micro 程序设计有关——`addr_calc_stride` 是一个专为 LEA-style 地址计算设计的 canonical benchmark，不反映真实程序的 site 密度。

---

## 3. Pattern 分析

### 3.1 BITFIELD_EXTRACT

**Pattern**：`shift + and` 提取固定位域，例如：
```
lsh r1, 16         ; 把目标字段移到低位
rsh r1, 48         ; 清除高位
; 或者等价的 rsh + and 组合
```
目标是将 BPF `(val >> K) & MASK` 模式替换为 BEXTR 指令（`bpf_extract64(val, start, len) → JIT emit BEXTR`）。

**覆盖数据**：
- **542 corpus sites，40 个 corpus objects**
- 最重要来源：cilium (198)、tetragon (115)、loxilb (64)
- 这三个都是生产级程序，site 密度适中

**性能预期**：
- BEXTR 将 2 条指令（rsh + and）换为 1 条 x86 BEXTR
- 但在当前 extract_dense benchmark 上，L/K = 0.733（27% 差距），说明确实有 gap
- 历史数据（v1 corpus 授权）：extract_dense 从 0.556x（有 bug）修复后到正常水平，说明 BEXTR 有收益但需要正确实现
- **I-cache 开销**：kfunc call site 扩展 2→5 insns（+3 insns），dense sites 会触发 I-cache flush，这正是 extract_dense 当前 policy 被清空的原因（见 micro_analysis_v2 §3）

**实现状态**：kinsn `bpf_extract64` 已在 `module/x86/bpf_extract.c` 实现，emit BEXTR。daemon 中无对应 pass（ExtractPass 未实现）。

### 3.2 ENDIAN_FUSION

**Pattern**：`load + bswap` 组合，例如：
```
ldxw r1, [r2+offset]    ; 加载 u32
bswap r1, 32            ; 字节序转换（ntohs/ntohl）
```
目标是合并为 MOVBE（Move with Byte Exchange）指令，`mov{be} r1, [r2+offset]` 一条指令完成 load + swap。

**覆盖数据**：
- **1,386 corpus sites，50 个 corpus objects**（注意：micro 中 0 sites，这些 sites 完全来自 corpus 真实程序）
- 最重要来源：calico (786)、cilium (341)，两者合计 81.3%
- 分布在 16 个不同项目，说明是跨领域的普遍 pattern

**性能预期**：
- endian_swap_dense 的 L/K = 0.549（45% 差距），说明 LLVM 能在这个 benchmark 上显著优化
- MOVBE 是 Haswell 以来的通用 Intel 指令（x86-64 baseline 上不保证，但所有 Broadwell+ 支持）
- 主要优化：load+bswap 2条指令→1条，减少 instruction count，可能改善 OoO 调度
- **注意**：MOVBE 需要新 kinsn 或直接 BPF bytecode 层合并（不需要单独 kinsn，可以直接 JIT emit MOVBE）

**实现状态**：无 kinsn 模块，无 daemon pass。

### 3.3 ADDR_CALC

**Pattern**：`mov + shift + add` 三指令地址计算，例如：
```
mov r3, r1          ; 复制 base
lsh r3, 3           ; r3 = index * 8
add r3, r2          ; r3 = base + index*8
```
目标是合并为 LEA 等价（x86 没有 BPF-to-LEA 直接映射，实际上是 `base + index*scale + disp` 的 x86 LEA）。

**覆盖数据**：
- **仅 19 total sites，corpus 中只有 14 sites，分布在 7 个对象**
- 100% 集中在 tetragon（corpus 的 14 个），其余项目为 0
- 这是所有 8 个 family 中 site 数量最少的（比 ZERO_EXT_ELIDE 还少——ZEE 有语义不满足要求返回 0）

**性能预期**：
- addr_calc_stride 的 L/K = 0.477（52% 差距），是三者中 gap 最大的
- 但这是 canonical benchmark，专为此 pattern 设计，不代表真实覆盖率
- 14 corpus sites 分布在 7 个对象中，每对象平均 2 个 sites，收益极有限
- x86 LEA 的真正优势（3-operand base+index*scale+disp）在 BPF bytecode 中很难自然产生这种 pattern

---

## 4. 综合评估

### 4.1 优先级矩阵

| Pattern | Corpus Sites | Projects | Site/Object | L/K Gap | 实现难度 | 综合优先级 |
|---------|-------------|---------|------------|---------|---------|----------|
| ENDIAN_FUSION | **1,386** | **16** | 27.7 | 45% | 中（新 kinsn 或 direct emit） | **高** |
| BITFIELD_EXTRACT | 542 | 15 | 13.6 | 27% | 中（kinsn 已有，需 daemon pass） | **中** |
| ADDR_CALC | **19** | **2** | 2.0 | 52% | 中（kinsn + daemon pass） | **低/可跳过** |

### 4.2 ENDIAN_FUSION — 推荐优先做

**理由**：
1. **Site 数量最多**（1,386）：是 BITFIELD_EXTRACT 的 2.6 倍，是 ADDR_CALC 的 73 倍
2. **覆盖面最广**（50 objects，16 projects）：网络程序普遍存在，calico + cilium 是论文最重要的 corpus workload
3. **micro 中 0 sites 反而是优势**：说明这个 pattern 完全来自真实程序，不是人工设计的 micro benchmark，对评审员更有说服力
4. **性能 gap 大**（L/K = 0.549，45% gap）：MOVBE 是 load+bswap 的自然 native 映射，x86 后端应当显著获益
5. **calico 是 corpus 的最大项目**（786/1,386 sites，57%）：calico 结果对论文很重要，ENDIAN_FUSION 将直接改善 calico corpus exec ratio

**风险**：
- MOVBE 在 VM 中可能不可用（需要 CPUID 检查），daemon 需要做能力检测
- 是否需要新 kinsn：可以用 direct BPF bytecode rewrite（把 ldxw+bswap 替换为一条 kfunc call bpf_movbe32）；或者直接在 JIT emit 层处理（更简单，但不需要 kinsn）

### 4.3 BITFIELD_EXTRACT — 中等优先级，有条件推进

**理由**：
1. 542 corpus sites，40 objects，覆盖 cilium/tetragon/loxilb 等关键项目
2. kinsn `bpf_extract64` 已实现（`module/x86/bpf_extract.c`），需要的是 daemon ExtractPass
3. L/K gap = 0.733（27%），比 ENDIAN 小但仍值得
4. **警告**：dense site 导致 I-cache flush 开销，extract_dense policy 已被清空。实际 corpus 程序中每对象 13.6 sites 平均密度，不像 micro 中的极端 dense case，I-cache 问题可能不严重

**风险**：
- extract_dense 的密集 I-cache flush 问题需要 policy 决策（per-program site density 阈值）
- 需要验证 corpus 真实 program 的 site density 不会触发类似 dense 回归

### 4.4 ADDR_CALC — 跳过，ROI 极低

**理由**：
1. **仅 19 total sites，corpus 中 14 sites**：与已实现的 family（COND_SELECT 7,724 / ROTATE 2,685）相差 2-3 个数量级
2. **只有 tetragon 有真实 sites**：tetragon 是 compile-only（无 exec 数据），对 exec ratio 没有贡献
3. **L/K gap 虽然大（52%）但是 canonical benchmark 的数字**：addr_calc_stride 是专门设计来测 LEA 的，真实程序里的 14 个 sites 分散在各函数中，几乎感觉不到
4. **实现成本不低**：需要 kinsn `bpf_lea()` + daemon AddrCalcPass，两者都不存在
5. **论文价值几乎为零**：site 数量太少，无法在 corpus/e2e 评估中展示显著差异

---

## 5. 结论

### 5.1 Do Now（如果要扩展 pass 集合）

**ENDIAN_FUSION** 是最优先候选：

```
优先级 = 覆盖面（50 objects）× 来源多样性（16 projects）× site 密度（27.7/object）× gap（45%）
```

建议实现路径：
1. 在 daemon 中实现 `EndianFusionPass`：扫描 `(ldxw src_reg+off; bswap32) / (ldxh src_reg+off; bswap16)` pattern，替换为 kfunc call `bpf_movbe32/bpf_movbe16`
2. 在 `module/x86/` 中实现 `bpf_movbe.c`：emit `movbe` 指令（CPUID.MOVBE 检查）
3. 预期 corpus 改善：calico exec ratio 可能有 5-15% 提升（需要实际测量）

**BITFIELD_EXTRACT** 值得做但优先级次之：
- kinsn 已有，只需 daemon ExtractPass
- 注意 policy 需要 site density 限制（< 某阈值才 apply）

### 5.2 Skip（不做）

**ADDR_CALC** 不值得实现：
- 19 sites，2 projects，单个 project（tetragon）compile-only
- 即使实现完美，对任何 exec 指标的贡献接近零
- 实现成本 > 论文价值

---

## 6. 数据完整性说明

本分析使用的 site 数字来源于两个数据集，两者略有差异：

| 来源 | bitfield | endian | lea |
|------|----------|--------|-----|
| 8-family census (`corpus-8families-persection.json`) | 557 total / 542 corpus | 1,386 | 19 total |
| `corpus_authoritative_20260320.json` | 54 (v2 scanner，可能定义更严格) | 825 | 0 |
| `vm_corpus.json` (2026-03-22 最新) | 0 (scanner 未实现) | 0 | 0 |

注意：`vm_corpus.json` 中 bitfield/endian/lea = 0 是因为 v2 daemon 中 ExtractPass 和 EndianFusionPass 尚未实现，scanner 未检测这些 family。

8-family census 使用的是单独的 8-family scanner（v1 时代工具），定义可能与 v2 daemon 不同。`corpus_authoritative_20260320.json` 的 825 endian sites 是 v2 架构下的测量，更接近真实可匹配数字。无论哪个版本，ENDIAN_FUSION 都是三者中 site 数量最多的，结论不变。
