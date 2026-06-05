# Kinsn Prefetch 计划

最后更新：2026-06-05。

## 结论

当前阶段的目标不是开始 integrated prefetcher，而是先把 prefetch 策略的 micro 证据做完整。
也就是说，先为每个策略构造匹配该策略的测试用例，确认测试用例本身有效，再看 treatment
是否有收益。

长期如果 micro evidence 支持，才考虑在 Kinsn 项目里实现 profile-assisted software prefetcher：

```text
BPF bytecode
  -> bpfopt prefetch selector 分析 load site
  -> 对每个 site 选择 skip / horizon / spatial / MLOP / degree / hint
  -> 插入 KINSN_SIDECAR + KINSN_CALL
  -> kernel kinsn JIT emit x86 prefetch* 或 ARM64 prfm
```

当前还不能 default-enable。已经证明的是：在 synthetic-control micro 上，部分
profile-fed future-address 策略在 ARM64 `c7g.large` 上有 cache-miss-drop evidence。当前正在做的是：
逐个策略审计测试用例有效性，并把只适合作为诊断或跳过规则的用例从正向性能证据里分离出来。

## Scope

本 task 只讨论 Kinsn 项目里的 CPU cache prefetch：

```text
/home/ruoji/github/bpf-opt/code/bpfopt/crates/bpfopt/src/passes/prefetch.rs
/home/ruoji/github/bpf-opt/code/module/x86/bpf_x86_prefetch.c
/home/ruoji/github/bpf-opt/code/module/arm64/bpf_arm64_prfm.c
```

它不是：

- 普通 LLVM `llvm.prefetch` / `LoopDataPrefetch`。
- Dynamic ReJIT 项目的整体 runtime policy。
- PF-LLM 的 hardware prefetcher ensemble。

PF-LLM 对本 task 的作用是提供 access-pattern taxonomy 和 per-PC policy table 这个设计启发；
当前实现是 Kinsn 子集 / 简化映射，不是 PF-LLM 本身。

## 总体阶段

| stage | 目标 | 当前状态 |
|---|---|---|
| 1. 机制打通 | 让 BPF bytecode 中的 kinsn prefetch call 能被 x86/ARM64 JIT 变成 native hint。 | 已完成。 |
| 2. Safety / admission | 保证插入点 verifier-safe、register stable、不会跨 call/jump/exit，并支持 profile gate。 | 已完成第一版；复杂 CFG dominance 仍待加强。 |
| 3. 策略筛选 | 对实际访问模式策略做 synthetic micro 验证；`horizon`、`degree`、`hint variant` 只作为参数测试。 | 已完成当前策略集合的一轮筛选；正向候选、负向诊断和跳过规则已分离。 |
| 4. PMU 归因 | 用能采 `cache_misses` 的 ARM64 AWS instance 验证 positive timing 是否来自 miss 下降。 | 已完成主要候选和主要拒绝项；已补 `first-deref`、`future-first`、`stream-of-strides degree1` PMU。`first-deref` 高 miss 但不降 miss；`stream degree1` 弱正向；`stream degree2` 拒绝。 |
| 5. 用例有效性清理 | 把每个策略的测试用例标成正向有效 / 弱正向 / 负向有效 / 诊断 / 跳过规则 / 无效，并补待办项。 | 已完成当前策略集合的整理：正向、诊断、跳过规则已经分开。 |
| 6. Integrated prefetcher | 在 micro 策略 gate 完成后，再设计 per-PC policy/profile schema，按 site 选择 skip/prefetch，并为策略配置 horizon/degree/hint 参数。 | 不是当前阶段。profile schema 已有基础能力，但在 micro 文档和证据收尾前不进入 integrated selector 设计。 |
| 7. Real coverage | 做 corpus site census，确认真实 BPF 里是否存在足够多 candidate，并导出 per-site profile generation 所需字段。 | 已开始，但不是当前 blocker；micro 用例有效性先完成。 |
| 8. Regression / default decision | 在原本通用 micro 和 corpus 上测集成 selector，决定 default / profile-gated / disabled。 | 当前决策：不能 default-enable；只能作为 `profile-gated research candidate`。 |

## 已完成的设计结论

### 值得继续追的策略

这些策略在 ARM64 `c7g.large` 上有 PMU-backed evidence：

| 策略 / 用例 | treatment/control | cache miss ratio | 解释 |
|---|---:|---:|---|
| MLOP/index-field | `0.945284` | `0.019193` | 地址由 index + field offset 组成，并且 future address 已物化。 |
| degree1 | `0.958149` | `0.006768` | 预取一个 future address 比 degree2/3 更好。 |
| horizon2 | `0.961195` | `0.009627` | 提前两个 logical step 比 horizon1 更合理。 |
| pipeline next-iteration | `0.968297` | `0.006868` | 当前轮提前预取下一轮 pointer。 |
| spatial-within-page | `0.971461` | `0.000460` | 同一 future page 内多个 offset 有 miss drop，但有 instruction overhead。 |
| struct-field fixed-offset | `0.986178` | `0.150586` | fixed fields 有弱正向信号。 |
| mixed per-PC policy table | `0.977369` | `0.010690` | 证明 profile table 可以只插 useful site、跳过 hot/no-lead sites。 |
| stream-of-strides degree1 | `0.990870` | `0.882631` | 单个 high-miss stream site 有弱正向信号；只保留 profile-gated degree1。 |

这些结果只能支持 `profile-gated candidate`。原因是它们依赖 hand-profiled PC/register，并且都是
synthetic-control micro。

### 不应进入默认策略的策略

| 策略 | 当前证据 |
|---|---|
| default structural prefetch | 只在 low-cache-miss 小 case 上有 timing win，不能证明 cache-prefetch 机理。 |
| same-iteration map / upper-bound | c7g PMU 显示 cache miss 没有实质下降。 |
| plain stride64 / stride256 / stride4096 | timing 中性，不能证明独立收益。 |
| x86 `nta` | 在当前 horizon/degree cases 明显变慢。 |
| ARM64 L2 hint default | L2 hints 没有超过 L1 hints。 |
| stream-of-strides degree2 / two-site placement | cache miss 下降，但 instructions/cycles overhead 抵消，exec 不赢。 |
| first-deref current placement | 高 miss，但 treatment miss 基本不降，cycles/instructions 上升。 |

## 当前决策

截至 2026-06-04，Kinsn prefetch 的可提交状态是：

```text
mechanism: implemented
safety gate: implemented first version
profile schema: implemented first version
micro evidence: positive only for selected profile-fed future-address patterns
corpus evidence: site census and profile insertion smoke only
default policy: disabled
automatic selector: not accepted yet
```

不能默认启用的原因：

1. 自动 structural selector 在真实 `katran` corpus 里匹配 224 个 candidate，但由于缺少 profile /
   PMU evidence，按安全 gate 全部跳过。
2. Tracee 真实程序里候选点很多，但当前只证明 default census 能跑得更快；没有证明插入 prefetch
   能改善真实 workload。
3. all-app corpus 目前主要失败在 app runnability，不能作为默认策略的收益或回归证据。
4. micro positive cases 是 synthetic-control，而且依赖 profile 指定 PC/register；不能外推成
   default selector。

因此本 task 当前完成的是 profile-assisted prefetch infrastructure 和 policy screening。后续如果要
重新推进 default selector，必须先补真实 evidence source：profile count、PMU miss/drop 或
real-derived workload coverage。

## 后续计划

### Step 1: 统一 profile schema

目标：把当前 hand-profile JSON 从 allow-list 扩展为 per-PC policy table。

每个 site 至少需要记录：

```text
program / benchmark
BPF PC
register
policy: skip | horizon | spatial | mlop | degree
hint: t0/t1/t2/nta or pldl1keep/pldl1strm/pldl2keep/pldl2strm
degree
horizon
reason
```

成功标准：

- 能表达当前所有 positive candidates。
- 能表达 negative filtering，例如 hot/sequential/no-lead-time/dependent-chain skip。
- profile schema 改动必须有 unit test 和一个 micro smoke。

当前状态：

- 已实现 `map_value_policy_points`。
- 已支持每个 point 的 `action: prefetch | skip`。
- 已支持每个 point 的 `policy`、`horizon`、`degree`、`hint`、`reason` metadata。
- 已支持 per-point `hint` override；未指定时使用 CLI `--hint` 默认值。
- 已有 Rust unit tests。
- 已用 `prefetch_mixed_policy_table` 在 x86 smoke 和 ARM64 c7g PMU run 中验证 schema 能插入
  1 个 prefetch point 并 skip 16 个非目标 site。
- 已把 corpus app-level pass config 接到 `BPFREJIT_BENCH_PASS_ARGS`，可以通过环境变量传
  `-- --profile ...` 做 profile-fed corpus run。
- 已用真实 `katran` candidate `pc=16, reg=r0` 做过单 site profile-fed smoke：
  matched 225、applied 1、skipped 224、insn_delta 2。
- 已用真实 `katran` candidate TSV 手工选择 12 个不同 map-value pointer-definition site，
  做过 multi-site profile-fed smoke：matched 236、applied 12、skipped 224、insn_delta 24。
- 已新增 `/home/ruoji/github/bpf-opt/code/scripts/prefetch_profile_from_candidates.py`，从
  candidate diagnostics TSV 自动生成 profile table。
- 已用 generated profile 做过 AWS ARM64 `katran` corpus smoke：matched 236、applied 12、
  skipped 224、insn_delta 24。
- generator 已支持 `--rank-column COLUMN` 和 `--rank-descending`，本地 smoke 证明可按数值列排序。
  当前已记录的 Katran generated profile 仍使用默认 PC-order top-N；ranking 只是下一步
  profile/PMU evidence-backed selector 的输入接口。

剩余问题：

- schema 现在是 hand-profiled policy table，不是自动 selector。
- `reason` / `policy` metadata 已验证格式和记录，但还没有用于自动决策。
- profile generator 目前没有真实 score 输入；需要后续从 profile count、PMU miss/drop 或 real workload
  census 生成 rank column，再用现有 ranking 接口排序。

### Step 2: 补用例有效性待办项

优先补：

| item | 当前状态 | 还缺什么 |
|---|---|---|
| `struct-field` 基线缺失压力 | x86 smoke done；ARM64 c7g PMU done；3 个 `prfm`；timing / rate 有结果。 | 已补：control `cache_misses` mean `362260.333`，control miss rate `0.005006681`。 |
| `mixed-policy-table` 性能有效性 | schema done；x86 smoke done；ARM64 c7g PMU done；1 个 `prfm`，16 个 skipped site。 | 已补：control `cache_misses` mean `1281564.0`，control miss rate `0.026966484`。仍需在结论里区分 schema evidence 和 performance evidence。 |
| `first-deref` PMU | timing-negative；PMU 已补。 | control `cache_misses` mean `1395197.0`，treatment `1394078.0`，miss 基本不降；cycles/instructions 上升；拒绝当前 placement。 |
| `future-first` diagnostic PMU | PMU 已补。 | 插入 1 个 `prfm`，但 miss count/rate 没下降；不作为正向 evidence。 |
| `stream-of-strides degree1` | high-miss PMU done；weak positive。 | T/C exec `0.990870`，miss ratio `0.882631`；保留 profile-gated weak candidate。 |
| `stream-of-strides degree2 / two-site` | high-miss PMU done；miss 下降但 exec/cycles 不赢。 | two-site placement 可判定无收益；只有继续 degree>1 stream direction 时才需要重构 scheduling 后重测。 |
| standalone stride | diagnostic done；timing neutral。 | 若仍要作为 policy candidate，构造 high-miss、lead-time-matched positive case；否则明确 reject standalone。 |

### Step 3: Corpus site census

目标：回答真实 BPF 中是否存在这些 shape。

需要统计：

- map-value load sites 数量。
- packet first-deref sites 数量。
- future pointer 是否能在 BPF bytecode 中提前物化。
- spatial/MLOP/degree1-like pattern 是否存在。
- 哪些 site 只适合 skip。

成功标准：

- 输出 per-program / per-site TSV。
- 每个候选 site 标注 pattern、是否 verifier-safe、是否需要 profile。
- 不把 synthetic micro 结果直接外推到真实程序。

当前状态：

- 已开始，但不完整。
- 2026-06-04 通过 AWS ARM64 corpus smoke 验证了默认 structural selector 在 `katran` 上能运行：
  `balancer_ingres` 匹配 224 个候选，应用 0 个，全部跳过。
- skip reason 显示真实 app 中确实存在大量 structural candidates，但当前 safety/admission 策略要求
  map-value site 有 profile / PMU evidence；这正是后续 profile-fed selector 要解决的问题。
- 已补做 `katran` diagnostics rerun，导出 224 个候选的
  `pc/source/ptr_reg/ptr_root_pc/ptr_def_pc/mem_off/dependent_load_depth/hint`。这个结果保存在：
  `/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/experiments/2026-06-04-prefetch-corpus-default-structural-smoke/analysis/katran-diagnostics-candidates.tsv`。
- `bcc/set` 失败在 `biosnoop` attach 阶段，不是 prefetch pass failure。
- 已做单 site profile-fed corpus smoke：将 `pc=16, reg=r0` 写入 profile，`katran` matched 225、
  applied 1、skipped 224、insn_delta 2。这证明 profile-fed corpus insertion path 可用。
- 已做 multi-site profile-fed corpus smoke：从 candidate TSV 选择 12 个不同 map-value
  pointer-definition site，`katran` matched 236、applied 12、skipped 224、insn_delta 24。
  这证明真实 corpus per-PC profile table 可以控制多个 site。
- 已做 generated-profile corpus smoke：从同一 candidate TSV 自动生成 12 点 profile，
  `katran` matched 236、applied 12、skipped 224、insn_delta 24。
- 下一步必须把 profile generation 从 simple top-N 推进到 profile/PMU evidence-backed ranking，并跑更多真实 app / site。
  ranking CLI 已有，但缺少真实 evidence source；不能只依赖 synthetic-control micro。
- 已做 selected-app default census：`katran` 完整通过；`tracee/monitor` baseline 加载 167 个 BPF
  program，prefetch pass 匹配 15542 个候选、应用 0 个，但 post-ReJIT shim socket reset；
  `tetragon/observer`、`katran/wrk`、`bpftrace/set` 分别被 artifact、workload 和 library dependency
  问题阻塞。下一步要先拆分 app runnability 和 pass scalability，而不是把 selected-app suite
  当作性能 gate。
- 已针对 Tracee pass scalability 做 rerun：默认关闭 per-candidate diagnostics 并缓存 site layout 后，
  Tracee total `bpfopt_ms` 从 308187 降到 51357，max single-program `bpfopt_ms` 从 26817
  降到 2781；matched candidate 数仍为 15542，应用数仍为 0。
- 已重跑 all-app default census：当前只有 `katran` 成功，其余 app 失败在 attach、library、
  shim tracking 或 workload connectivity 阶段。all-app corpus 需要先修 runnability，不能作为
  prefetch policy gate。

### Step 4: 集成 profile-assisted selector

目标：让 `bpfopt --pass prefetch -- --profile FILE` 按 per-PC policy table 插入 prefetch。

成功标准：

- positive policy 只在 profile 指定 site 生效。
- negative site 明确 skip。
- 每个 transformed program 输出 `sites_matched / sites_applied / skip_reason`。
- x86/ARM64 object/JIT smoke 均能看到对应 native hint。

### Step 5: 评估集成效果

必须分三层跑：

| level | 目的 |
|---|---|
| targeted synthetic micro | 继续验证每个 policy 的 best-case / controlled behavior。 |
| 原本通用 micro suite | 检查集成 selector 是否误伤普通 BPF code shape。 |
| corpus / real-derived programs | 检查真实覆盖率和真实性能影响。 |

默认启用条件：

- synthetic micro 上有 PMU-backed positive evidence。
- 通用 micro 不出现系统性 regression。
- corpus/site census 证明 pattern 真实存在。
- corpus 或 real-derived run 上至少没有明显 regression。

如果这些条件不满足，prefetch 只能保持 `profile-gated research candidate`。

## 文档和实验入口

Canonical task docs：

```text
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/README.md
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/technical-report.md
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/mechanism.md
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/safety-rules.md
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/policy-matrix.md
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/microbench-design.md
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/results.md
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/completion-audit.md
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/commit-plan.md
```

Experiment artifacts：

```text
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/experiments
/home/ruoji/github/bpf-opt/experiments
```

Literature review and source cache：

```text
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/literature/literature-review.md
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/literature/sources
```
