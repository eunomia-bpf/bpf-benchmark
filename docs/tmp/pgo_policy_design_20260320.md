# PGO-Style Policy Design for BpfReJIT

Date: 2026-03-20

Scope:
- `docs/kernel-jit-optimization-plan.md`
- `docs/tmp/katran_site_coverage_analysis_20260320.md`
- `docs/tmp/emitter_cost_and_branchflip_analysis_20260320.md`
- `docs/tmp/2026-03-10/policy-decision-layer-design.md`
- `corpus/generate_default_policies.py`
- `corpus/auto_tune.py`
- `runner/libs/metrics.py`
- `scanner/src/cli.cpp`
- `docs/paper/paper.tex`
- `vendor/linux-framework/Documentation/dev-tools/autofdo.rst`
- `vendor/linux-framework/Documentation/dev-tools/propeller.rst`
- `vendor/linux-framework/tools/perf/Documentation/perf-stat.txt`
- `vendor/linux-framework/tools/bpf/bpftool/Documentation/bpftool-prog.rst`
- LLVM docs: Advanced Build Configurations, BOLT section

Constraint:
- 只做分析和设计，不改代码。

## Executive Summary

结论先行：

1. **PGO-style policy 在 eBPF / BpfReJIT 场景是可行的，但当前只在“程序级 hotness + family 级/分组级决策”上完全可落地。**
   - `bpf_prog_info.run_cnt/run_time_ns` 已足够做 program hot/cold 分类。
   - `perf stat --bpf-prog <id>` 已足够做 **program-wide** `cycles/instructions/branches/branch-misses`。
   - **缺的不是“有没有 profile”，而是“没有 first-class per-site attribution”。**
2. **当前最应该做的不是一上来追 full AutoFDO/BOLT-style site attribution，而是先把 policy pipeline 从 offline object scan 切到 live enumerate。**
   - 否则 Katran 这种 `branch-flip` live-only family 根本进不了 policy 输入。
   - 在 discovery 错层的情况下，后面的 PGO/cost model 都没有意义。
3. **短期最合理的设计是“三层 policy”：**
   - `Safety gate`：已知 correctness-broken form 直接禁用，例如 `endian-swap-store-16`。
   - `Profitability gate`：用 `run_cnt/run_time_ns`、site density、code-size delta、same-size 标记做程序级 admission。
   - `Profile-gated tuning`：只对少数真正 hot 且 profile 显示有机会的程序，跑 branch-sensitive families 的 A/B 试验。
4. **对 branch-flip，当前最现实的方案不是“56 sites 全开/全关”，而是：**
   - 先用 live enumerate 找到真实候选；
   - 再用 program-wide `branch_miss_rate` 决定这个程序值不值得继续调；
   - 再用分组 A/B 或少量 site/group search 找出值得 flip 的局部区域。
5. **这条方向会增强论文，但不能替代论文主贡献。**
   - 它能把 paper 里的“guided by profiling and deployment policy”从口号变成实证。
   - 但 novelty 仍然应该是 **安全/优化分离 + fail-closed bounded variant interface**。
   - 如果最后结果只是“fixed kernel heuristic + profile threshold 也一样好”，reviewer 会合理地问：为什么不直接做 kernel heuristic。

我的建议：

- **P0**：live-enumerate-based policy generation + runtime-hotness gate + rule-based cost model。
- **P1**：接入 `perf stat --bpf-prog` 做 program-level branch miss gating，并把 `auto_tune.py` 扩展到 live programs。
- **P2**：做 branch/site attribution、在线闭环、策略持久化和再训练。

## 1. Problem Restatement

当前 policy 系统的四个核心问题，本质上分别对应四个不同层次的缺陷：

1. **Discovery 错层**：
   - `generate_default_policies.py` 用的是 `scanner scan <object> --program-name ...`。
   - Katran `balancer_ingress` 的 offline object scan 看不到 `branch-flip`，但 live enumerate 能看到 `56` 个 sites。
   - 这意味着默认 policy 不是“保守”，而是“输入就错了”。
2. **Selection 不看 workload**：
   - 当前 YAML 是静态 explicit allowlist。
   - 即使 live 里能看到 `branch-flip=56`，也不知道哪些 branch 真 hot，哪些 mispredict 真严重。
3. **Cost model 太粗**：
   - scanner 现有 cost model 只有三条硬规则：
     - same-size forms 默认跳过；
     - cmov 默认跳过；
     - dense family 超过 `max_sites_per_form` 跳过。
   - 这能挡掉一部分明显 bad case，但不能回答“哪个 site 值得为了它 recompile”。
4. **Policy 是 compile-time 静态 YAML，不是 runtime control loop**：
   - 论文正文已经写了 `load -> run -> profile -> generate policy -> re-JIT -> measure -> refine`。
   - 但当前实现主路径还没有一个真正基于 live stats 的闭环。

## 2. Feasibility: Is PGO-Style Policy Actually Possible?

## 2.1 Short Answer

**可以，但分两档：**

- **档 1：coarse-grained PGO，今天就能做**
  - 目标：决定“哪些程序值得 recompile、哪些 family 值得考虑、哪些程序完全不值得动”。
  - 数据源：`run_cnt`、`run_time_ns`、`perf stat --bpf-prog`。
  - 这是我认为应该立刻落地的方向。
- **档 2：fine-grained per-site PGO，当前只能近似做**
  - 目标：决定“同一程序里哪几个 `branch-flip` sites 值得开”。
  - 当前没有直接的 per-site branch-miss UAPI。
  - 只能靠 A/B isolation、分组搜索、或者未来的 JIT-address sampling / kernel telemetry。

所以答案不是 “PGO 不可行”，而是：

> **program-level PGO 已经可行；site-level PGO 需要更重的 attribution 机制。**

## 2.2 What Signals Already Exist Today

### A. `bpf_prog_info`: `run_cnt` / `run_time_ns`

仓库里已经有现成使用链路：

- `runner/libs/metrics.py` 通过 `bpf_enable_stats()` 和 `bpf_prog_get_info_by_fd()` 读取：
  - `run_cnt`
  - `run_time_ns`
  - `jited_prog_len`
  - `xlated_prog_len`
- 这已经用于 E2E/tracing 类 workload 的前后 delta 采样。

这组数据足够回答：

- 哪些程序在当前 workload 中真的在跑；
- 哪些程序是 hot，哪些是 cold；
- 每个程序平均每次执行多长；
- program-level recompile 代价有没有机会 amortize。

局限：

- 这是 **per-program cumulative stats**，不是 per-site。
- 一些 prog type 现在仍然有洞，例如仓库里对 `struct_ops/scx` 已经记录过 `run_cnt/run_time_ns` 不稳定或拿不到。

### B. PMU: `perf stat --bpf-prog <id>`

内核自带的 `perf stat --bpf-prog` 文档明确支持：

- `cycles`
- `instructions`
- `branches`
- `branch-misses`

这意味着对一个已加载 BPF program，可以拿到 **program-wide branch miss rate**：

`branch_miss_rate = branch_misses / branches`

以及：

- `IPC = instructions / cycles`
- 更粗的 cache/front-end 信号

这对 `cmov` 和 `branch-flip` 非常关键，因为它把“policy-sensitive”从纯猜测推进到“至少能基于 live branch behavior 做 admission”。

局限：

- 仍然是 **program-wide**，不是 per-site。
- 需要 root / perf 权限。
- 对极短程序或很短 profiling window，统计稳定性仍然会差。

### C. `bpftool prog profile`

它更 BPF-aware，但目前公开接口的 metric 菜单更窄，常见是：

- `cycles`
- `instructions`
- `llc_misses`

**没有现成 branch-miss metric。**

所以对 branch-flip，`perf stat --bpf-prog` 比 `bpftool prog profile` 更直接。

### D. Existing measurement infra in this repo

仓库里其实已经具备了不少可复用基础设施：

- `runner/src/perf_counters.cpp` 已支持 `branch_misses` / `branches` / `cycles` / `instructions`
- `auto_tune.py` 已经有：
  - census
  - all-apply screening
  - leave-one-out ablation
  - pairwise combo search
- `scanner enumerate --recompile` 已经有一个初级 cost model hook

换句话说，BpfReJIT 缺的不是 profiling primitives，而是：

1. live enumerate 作为真实 discovery 输入；
2. runtime stats 和 policy compiler 的连接；
3. 对 policy-sensitive families 的 runtime-aware decision logic。

## 2.3 What Is Not Yet Available

### A. No first-class per-site hotness

今天没有一个 `bpf_prog_info` 字段告诉你：

- `branch-flip site #17` 贡献了多少 miss；
- `cmov site #3` 是 hot 还是 cold；
- 哪个 BPF basic block 才是真正热点。

### B. No robust BPF-site-to-PMU attribution

当前最接近的路径是：

1. live enumerate 拿 BPF site 清单；
2. `bpftool prog dump jited` / `bpf_prog_info.jited_*` 看 native image；
3. `perf` 做 native-address 采样；
4. 再反推到 BPF site。

这个路径能做研究原型，但还不够 production-ready，也不够适合作为 P0 依赖。

### C. No stability guarantees for all prog types

对于 network / tracing program，大体可行；
对于某些 attach 模式或 `struct_ops`，现有 stats 支持并不完整。

所以 PGO-style policy 的 realistic claim 应该是：

> **对主流有 runtime stats 的 live BPF programs 可行，不是对所有 prog type 一刀切。**

## 3. The First Principle: Live Enumerate Must Replace Offline Object Scan

这是整个设计里最重要的一点。

Katran 的事实已经说明：

- offline object scan：`branch-flip = 0`
- live enumerate：`branch-flip = 56`

如果 discovery 继续依赖 object scan，那么：

- policy-sensitive family 会系统性缺失；
- PGO 根本没有机会做；
- 任何“默认 policy”都只是建立在错误输入上的静态猜测。

### 3.1 What should change

当前 `generate_default_policies.py` 的职责混在一起了：

1. 发现 sites
2. 选择 sites
3. 写静态 explicit YAML allowlist

应该拆成三层：

1. **Discovery**
   - source of truth = `scanner enumerate --prog-id ... --all --json`
2. **Observation**
   - `run_cnt/run_time_ns`
   - optional PMU counters
3. **Decision / compilation**
   - 把高层 policy 规则编译成 per-site blob/YAML

### 3.2 Recommended source hierarchy

推荐顺序：

1. **live enumerate**
   - 用于真实 attached/running 程序
   - 这是 steady-state policy 的权威输入
2. **offline object scan**
   - 只保留给 corpus census、coverage characterization、无 live instance 的预分析
   - 不再作为默认 runtime policy 的唯一输入

### 3.3 Practical artifact split

建议把当前“一个静态 YAML 代表全部 policy”改成两类 artifact：

1. **High-level policy spec**
   - family allow/deny
   - profile thresholds
   - known-bad form blocklist
   - canary/rollback parameters
2. **Generated live policy**
   - 基于某次 live enumerate + profile snapshot 编译出的 explicit site decisions
   - 最终进入 `BPF_PROG_JIT_RECOMPILE`

这样可以保留现有 kernel/blob ABI，不需要把 kernel 变复杂，但把 userspace policy 层真正做成 runtime system。

## 4. Proposed Policy Architecture

## 4.1 Control Loop

推荐的 runtime feedback loop：

1. **Load stock**
   - 先用 stock JIT 跑
2. **Observe**
   - 采样 `run_cnt/run_time_ns` delta
   - optional: `perf stat --bpf-prog`
   - live enumerate sites
3. **Decide**
   - 筛掉 cold program
   - 应用 hard safety rules
   - 对少数 hot program 运行 family/site tuning
4. **Compile**
   - 生成 per-program policy blob
5. **Apply**
   - `BPF_PROG_JIT_RECOMPILE`
6. **Validate**
   - correctness check
   - post-apply stats / perf
7. **Keep or rollback**
   - 若收益不成立，`policy_fd=0` 一键回退
8. **Persist**
   - 按 `{prog_tag, cpu model, workload label}` 记录成功策略

这和 paper 里的 narrative 完全一致，但比当前 static YAML 更真实。

## 4.2 Separate Three Kinds of Policy

### A. Safety policy

这不是 profitability 问题，而是 hard gate：

- 已知 correctness-broken form：
  - `endian-swap-store-16` 先 block
- 需要 CPU feature 的 form：
  - 例如 `MOVBE`、BMI2、特定 arch capability
- 需要 verifier/JIT invariant 的 form：
  - 保持当前 fail-closed kernel validator

### B. Profitability admission policy

回答“这个程序值不值得进 tuning 流程”：

- `delta_run_cnt` 太低：跳过
- `delta_run_time_ns` 太低：跳过
- `family site_count` 太大：默认跳过或只做抽样
- same-size form 且程序不热：跳过

### C. Tuning policy

只对 admission 通过的程序：

- family-level all-apply / leave-one-out
- branch-sensitive family 的 A/B
- canary apply / rollback

## 4.3 Data Model

建议 userspace 里显式建一个 profile record：

```text
ProgramProfile
  prog_id
  prog_tag
  name
  type
  attach_context
  xlated_insn_count
  jited_prog_len
  run_cnt_delta
  run_time_ns_delta
  avg_ns_per_run
  cycles
  instructions
  branches
  branch_misses
  branch_miss_rate
  live_site_manifest
  family_site_counts
```

以及 decision record：

```text
PolicyDecision
  family
  insn
  pattern_kind
  decision: apply | skip | block | profile_required
  confidence
  rationale
```

这样 policy 不是一串静态 site list，而是有来源、有解释、能 rollback 的决策。

## 5. Cost Model Design

## 5.1 Design Goal

cost model 不应该再只是“默认 skip 某些 family”，而应该回答：

> **在当前 workload 下，为这个 program 的这组 sites 做一次 recompile，预期收益是否大于代价与风险？**

## 5.2 Hard Gates First

先做 hard gate，再谈 score：

### Gate 1: Correctness

已知 correctness risk 的 form/site 直接跳过：

- `endian-swap-store-16` 当前应为 hard blocklist

### Gate 2: Liveness / hotness

使用窗口内 delta，而不是绝对值：

- `run_cnt_delta < R_min` -> skip
- `run_time_ns_delta < T_min` -> skip

理由：

- 程序不热，任何 recompile 收益都难以 amortize
- 这比 today 的“site count > 128”更接近真实收益

### Gate 3: Same-size rewrite default-off

same-size form 不应再被视为永远不值得，而应视为：

- **默认不启用**
- **只有当程序足够 hot 且有 profile/A-B 证据时才 override**

这比当前 scanner 的 `--skip-same-size` 更合理，因为它把“默认-off”与“永不允许”分开了。

### Gate 4: Dense-family control

`site_count` 很大时，默认不做 exhaustive tuning：

- `site_count <= N_small`：可以 single-site/group A/B
- `N_small < site_count <= N_large`：只做 grouped tuning
- `site_count > N_large`：默认 family-level decision，或只调 top groups

这里的意义不是“dense 一定没收益”，而是 **搜索成本** 和 **变更风险** 会飙升。

## 5.3 Ranking Signals

在 hard gate 之后，用以下信号排序：

| Signal | Source | Meaning | Best used for |
| --- | --- | --- | --- |
| `run_time_ns_delta` | `bpf_prog_info` | 程序总 CPU 占用 | program admission / priority |
| `avg_ns_per_run` | `run_time_ns_delta / run_cnt_delta` | 单次执行开销 | 判断单次收益空间 |
| `run_cnt_delta` | `bpf_prog_info` | 执行频率 | amortization |
| `branch_miss_rate` | `perf stat --bpf-prog` | 分支可预测性差 | `cmov`, `branch-flip` |
| `jited_prog_len` / code delta prior | `bpf_prog_info` + family prior | 代码尺寸敏感性 | `wide`, `lea`, `same-size` |
| `site_count` | live enumerate | family 密度/搜索成本 | tuning budget |
| correctness risk class | manual DB | 风险 | hard block / conservative tuning |

## 5.4 Recommended Cost Function Shape

P0 不建议直接上复杂 ML model，建议先用 explainable rule engine：

```text
if correctness_blocked(form):
    skip
elif cold(program):
    skip
elif same_size(form) and not strong_profile_evidence(program):
    skip
elif dense(form) and not top_hot_program(program):
    skip
elif branch_sensitive(form) and branch_miss_rate < threshold:
    skip
else:
    candidate for apply or A/B tuning
```

如果需要一个统一评分，可用：

```text
score(program, family) =
    Hotness(program)
  * FamilyPriorBenefit(family, cpu)
  * ProfileMultiplier(program, family)
  - RecompilePenalty(program)
  - RiskPenalty(family, form)
```

但建议把这个 score 只作为排序，不作为唯一 gate。

## 5.5 Family-Specific Policy

### `wide` / `lea`

倾向：

- 默认优先级最高
- code shrink / direct lowering 的 prior 最强
- 当前 evidence 也最接近“substrate optimization”

建议：

- hot 程序上默认 allow
- dense 也可以放宽

### `rotate`

倾向：

- 与 CPU family 更相关
- 需要保留 CPU feature / microarchitecture prior

建议：

- 作为 P0/P1 的正向 family
- 但要保留 per-CPU prior，而不是 blanket 开启

### `endian`

倾向：

- split by `pattern_kind`
- 不同 subform 的 safety/profitability 差异大

建议：

- `endian-load-swap-32` 与 `endian-swap-store-16` 必须分开管理
- policy 单位应至少到 `family + pattern_kind`

### `cmov`

倾向：

- 明确的 policy-sensitive family
- 需要 branch behavior 才能判断

建议：

- 默认 `profile_required`
- 没有 branch profile 时不自动开启

### `branch-flip`

倾向：

- 最强 policy-sensitive
- 也是当前 live-only / discovery blind spot 最大的 family

建议：

- 默认 `profile_required`
- 不做全开默认值
- 需要 live enumerate + branch miss admission + grouped tuning

## 6. Branch-Flip Specific Design

Katran 已经给出最典型案例：

- live `branch-flip = 56`
- blind all-on：`0.739x`

这说明两点：

1. `branch-flip` 不是 validator 问题，而是 **policy 问题**
2. 它需要 **selective flip**，不是 family 全开

## 6.1 What we can do now

### Step 1: Program admission

只有满足以下条件的程序才继续：

- `run_time_ns_delta` 足够大
- `branch_miss_rate` 高于阈值
- `branch-flip site_count` 不超过调优预算，或属于 top hot set

### Step 2: Grouped tuning, not 56-way blind search

当前没有 per-site miss attribution，所以推荐：

- 按 live site 的 **insn proximity / pattern kind / basic-region heuristic** 分组
- 先测 group-level A/B
- group positive 后再局部细化

比起 56 个单 site 全扫，这更现实。

### Step 3: Keep only with hysteresis

branch-flip 结果容易 workload-sensitive，建议：

- 提升必须超过 margin 才 keep，例如 `> 3%`
- 否则回退，避免 jitter/noise 导致 thrash

## 6.2 What we cannot honestly claim yet

当前不能声称：

- 能精准知道 56 个 sites 里哪一个 branch 是真正高 miss 源；
- 能像 Propeller/BOLT 那样做真正的 block-level layout optimization；
- 能做完全自动的 branch profile to site mapping。

所以 paper/设计文档里应明确：

> **P0/P1 是 program-aware and workload-aware；P2 才是 site-aware attribution。**

## 7. How To Evolve the Current Policy System

## 7.1 Do not keep policy as compile-time explicit YAML only

当前 v3 YAML 的问题不是 YAML 本身，而是它承担了错误的角色：

- 既是 discovery snapshot
- 又是 decision result
- 还是 runtime artifact

建议改成：

1. **High-level policy config**
   - family defaults
   - known-bad form blocklist
   - thresholds
   - search budget
2. **Generated decision artifact**
   - live enumerate + profile 之后生成
   - explicit site list / blob

## 7.2 Add rule-based policy classes

建议每个 family/form 都有一个 class：

- `blocked`
- `default_on`
- `default_off`
- `profile_required`
- `experimental`

例如：

| Family / form | Class | Reason |
| --- | --- | --- |
| `wide` | `default_on` | low risk, strong prior |
| `lea` | `default_on` | low risk, code-shrinking prior |
| `rotate` | `experimental/default_on` by CPU | µarch-sensitive |
| `endian-load-swap-32` | `experimental` | form-specific validation needed |
| `endian-swap-store-16` | `blocked` | known correctness issue |
| `cmov` | `profile_required` | branch-sensitive |
| `branch-flip` | `profile_required` | strongest workload sensitivity |

## 7.3 Reuse `auto_tune.py`, but change its input layer

`auto_tune.py` 现有 phase 结构是有价值的：

1. census
2. all-apply
3. leave-one-out
4. pairwise combo
5. write winner

但它现在的问题是：

- 输入来自 offline scan
- measurement target 主要是 corpus packet-test-run / inventory
- 选择粒度是 family allowlist，不看 live stats

建议演进为：

- **Phase 1**：live enumerate + runtime stats snapshot
- **Phase 2**：只对 hot programs 跑 family-level all-apply
- **Phase 3**：对 regression programs 跑 leave-one-out
- **Phase 4**：只对 `profile_required` families 做 grouped/site tuning
- **Phase 5**：输出 live-generated policy

这样既复用已有 tuner 原型，又把它从 offline corpus tool 推进到 runtime policy engine。

## 8. Comparison With Other PGO Systems

## 8.1 AutoFDO

Linux 内核 in-tree 文档里的 `CONFIG_AUTOFDO_CLANG` 路径说明：

- 用 `perf` 做 hardware sampling
- 采 representative workload
- 离线生成 profile
- 再 rebuild kernel

对 BpfReJIT 的启发：

1. **Representative workload 是第一原则**
   - profile 不是“多采一点数据”就行，必须和目标 workload 同分布
2. **profile collection 与 optimization build 应分离**
   - 对 BpfReJIT 来说，就是“先 stock 跑，再基于观测 re-JIT”
3. **允许跨版本/轻微 drift 的 profile remap 很重要**
   - BpfReJIT 已经有 `family + pattern_kind` remap 思路，可以继续沿这个方向做

差异：

- AutoFDO 优化的是整个编译产物；
- BpfReJIT 优化的是已加载 live BPF program 的 bounded JIT variants；
- AutoFDO 可以任意影响 compiler decisions；BpfReJIT 只能在 kernel 预定义的 safe menu 里选。

## 8.2 Propeller

内核 in-tree 文档里的 `CONFIG_PROPELLER_CLANG` 路径更接近 branch/layout 问题：

- 同样基于 `perf`
- 强调 **block layout within/across functions**
- 建议叠在 AutoFDO 之上

对 BpfReJIT 的启发：

1. **branch/layout 是 second-stage optimization**
   - 先有 hotness，再谈 layout
2. **branch-sensitive optimization 需要 branch-aware profile，不是只看 exec time**
3. **这类优化通常不适合 blind all-on**

这正好对应 `branch-flip`：

- `branch-flip` 在 spirit 上更像 mini-Propeller than simple peephole
- 所以不应该和 `wide`/`lea` 用同一套“见到就开”的默认规则

## 8.3 BOLT

LLVM 的 BOLT 文档把它定义为：

- **post-link**
- **profile-guided**
- 在 final binary 上做 layout/binary-level optimization

这对 BpfReJIT 的启发很强，因为 BpfReJIT 的优化点也在：

- verifier 之后
- final xlated/native boundary
- live binary 已经存在的情况下

和 BOLT 的共同点：

- 都不是源代码/IR 早期优化
- 都依赖真实运行 profile
- 都关注 post-codegen profitability

关键差异：

- BOLT 可以重排整个 binary；
- BpfReJIT 必须维持 kernel fail-closed 安全边界，只能选预先验证过的变体；
- BOLT 是 offline whole-binary optimizer；BpfReJIT 是 online/post-load per-program policy engine。

这其实是一个不错的论文 positioning：

> **BpfReJIT 不是 eBPF 的 BOLT。它是“带安全边界的 post-load bounded optimizer interface”。**

## 8.4 KCFI

先澄清：

- **KCFI 不是 PGO。**
- Linux 内核里真正的 in-tree profile-guided build 支持是 `AUTOFDO_CLANG` 和 `PROPELLER_CLANG`。
- KCFI 是 forward-edge control-flow integrity hardening。

对 BpfReJIT 的启发是：

1. kernel 社区接受“为了安全/正确性在 machine-code boundary 增加 metadata/instrumentation”
2. 但 KCFI 不回答 profitability，也不引入 workload policy

所以 KCFI 对 BpfReJIT 的关系是：

- **orthogonal**
- 更像 safety-plane analogy，而不是 PGO competitor

## 9. Recommended Roadmap

## P0: Fix the policy substrate first

目标：把系统从“错层静态 allowlist”升级到“live-aware conservative policy”

1. **把默认 policy generation 的输入切到 live enumerate**
   - `scanner enumerate --prog-id --json`
   - offline scan 只保留做 census/fallback
2. **把 policy 拆成 rule config + generated live artifact**
   - 不再把 checked-in YAML 当最终 runtime source of truth
3. **接入 `run_cnt/run_time_ns` hotness gate**
   - cold program 不 recompile
4. **引入 form-class policy**
   - `blocked/default_on/profile_required/...`
5. **把已知 correctness 问题固化为 hard gate**
   - 例如 `endian-swap-store-16`
6. **把 scanner 当前 cost model 升级为 runtime-aware gate**
   - same-size = default-off，不是 unconditional skip forever

为什么这是 P0：

- 不需要新 kernel ABI
- 不依赖 per-site PMU attribution
- 能立刻解决 Katran branch-flip live-only blind spot
- 能明显提高 paper 说服力

## P1: Add real profile-guided decisions

目标：把 system 从 live-aware 升级到 workload-aware

1. **接入 `perf stat --bpf-prog`**
   - 采 `cycles/instructions/branches/branch-misses`
2. **把 `cmov` / `branch-flip` 改成 `profile_required`**
   - 用 branch miss rate 做 admission
3. **扩展 `auto_tune.py` 到 live programs**
   - family-level A/B
   - grouped search for branch-sensitive forms
4. **做 canary keep/rollback**
   - apply -> remeasure -> keep or revert
5. **持久化 policy DB**
   - key = `prog_tag + cpu model + workload label`

为什么这是 P1：

- 能形成 paper 里真正的 `profile -> re-JIT -> refine` demo
- 能直接回答 reviewer 的 “why not PGO/AutoFDO?” 问题

## P2: Site-aware attribution and adaptive control

目标：把 branch-sensitive policy 从 program-aware 推进到 site-aware

1. **native-address sampling + JIT site mapping**
   - 尝试把 perf sample 对齐到 BPF site / native region
2. **group-to-site refinement**
   - 对 positive groups 再做局部搜索
3. **online adaptation with hysteresis**
   - workload 变化后自动 re-profile
4. **可能的 future kernel telemetry**
   - 如果要真正做 per-site profitability，最终可能需要更强的 kernel/JIT reporting

为什么这是 P2：

- 技术风险大
- 对当前论文不是 blocking
- 更像后续系统论文/扩展工作

## 10. Paper Impact

## 10.1 Does this strengthen novelty?

**会增强，但方式要克制。**

增强点：

1. 它把“userspace policy plane”从 static YAML 变成真正 deployment-aware control loop
2. 它解释了为什么 `branch-flip` 这类 family 不能由 fixed kernel heuristic 决定
3. 它让 Katran 这种真实 workload 成为强 motivation，而不只是一个 site-coverage bug report

但不要把 novelty 改写成：

- “我们发明了 PGO”
- “我们比 AutoFDO/BOLT 更新”

正确说法应该是：

> **BpfReJIT 的新意不是 profile 本身，而是给 kernel eBPF JIT 提供了一个 safe, bounded, post-load, deployment-controlled optimization interface；PGO-style policy 是这个接口最自然、最有说服力的使用方式。**

## 10.2 What OSDI reviewers will ask

大概率会被问：

1. **Why not AutoFDO / Propeller / BOLT?**
   - 回答：这些系统说明 profile-guided post-codegen optimization 是合理方向，但它们不解决 kernel eBPF JIT 的安全边界，也不提供 per-program live re-JIT interface。
2. **Why not fixed kernel heuristic + perf threshold?**
   - 回答：如果 fixed kernel heuristic 在 tested workloads 上同样有效，那 paper 的正确结论就是“做 kernel heuristic”。
   - 所以必须用实验说明：
     - profitability 随 workload 变；
     - userspace/fleet owner 比 kernel 更适合维护 policy。
3. **Do you really need per-site policy?**
   - Katran `branch-flip=56 all-on -> 0.739x` 就是最好的回答。
4. **Is the current implementation actually profile-guided?**
   - 现在还不够，所以 P0/P1 应该尽快补一个真实闭环 demo。

## 10.3 What is paper-worth as P0 evidence

最值得补的不是 full site profiler，而是一个非常清楚的两步 demo：

1. stock attach + observe live stats / PMU
2. 生成 live-aware policy
3. re-JIT
4. keep or rollback based on measured effect

哪怕只在 1-2 个 workload 上做成，也比继续强调静态 YAML 更强。

## 11. Concrete Recommendations

如果只选三件事做，我建议：

1. **立刻把 policy discovery 切到 live enumerate。**
   - 这是所有后续工作的前提。
2. **立刻引入 `run_cnt/run_time_ns` admission gate。**
   - 这是最便宜、收益最大的 coarse-grained PGO。
3. **把 `branch-flip` 和 `cmov` 归类为 `profile_required`，只对 hot programs 做 tuning。**
   - 不再允许 blind family-wide default enable。

如果还能再做两件：

4. **接 `perf stat --bpf-prog`，把 branch miss rate 真正拉进 decision loop。**
5. **把 `auto_tune.py` 迁移到 live-program tuning，而不是只做 offline corpus family ablation。**

## 12. Bottom Line

最简洁的判断是：

- **PGO-style policy 对 BpfReJIT 是值得做、而且应该做的方向。**
- **但它的第一步不是 full site attribution，而是 live enumerate + runtime hotness gating。**
- **当前 policy 系统真正的 blocker 是 discovery 错层，不是缺一个更聪明的 heuristic。**
- **对论文来说，这条线会增强说服力，但前提是它服务于核心 thesis：userspace policy plane 能基于 deployment context 做出 kernel 无法安全硬编码的优化决策。**

## References

- Linux kernel docs: `Documentation/dev-tools/autofdo.rst`
- Linux kernel docs: `Documentation/dev-tools/propeller.rst`
- Linux kernel perf docs: `tools/perf/Documentation/perf-stat.txt`
- bpftool docs: `tools/bpf/bpftool/Documentation/bpftool-prog.rst`
- LLVM docs: Advanced Build Configurations, BOLT section
