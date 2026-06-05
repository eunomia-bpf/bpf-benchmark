# Kinsn Prefetch Completion Audit

最后更新：2026-06-04。

## 结论

Prefetch task 当前可以收尾为：

```text
status: completed_as_profile_gated_research_candidate
default_enable: no
automatic_selector: not accepted
```

这不是说 prefetch 没有实现。当前已经实现并验证的是：

- BPF bytecode 中插入 `KINSN_SIDECAR + KINSN_CALL`。
- x86 JIT emit `prefetch*`，ARM64 JIT emit `prfm`。
- `bpfopt` 支持 profile-gated prefetch / skip policy table。
- micro benchmark 已覆盖 fixed distance、same-iteration、future-address、horizon、degree、hint
  variant、spatial、MLOP、struct-field、mixed policy-table、stream-of-strides。
- ARM64 `c7g.large` 已做 PMU-capable attribution。
- corpus 已做 `katran` candidate census、single-site profile-fed insertion、multi-site insertion、
  generated-profile insertion、Tracee large-program overhead rerun。

不能默认启用的原因也已经有证据：

- 简单 structural selector 在真实 `katran` corpus 里只做 census，不插入任何 prefetch，因为没有
  profile / PMU evidence。
- positive micro 主要来自 synthetic-control / profile-fed future-address cases，不能外推为真实
  workload 默认收益。
- all-app corpus 当前被 app runnability 阻塞，不能作为 default selector 的收益或回归 gate。
- stream-of-strides 不能整体排除：degree1 / single-site high-miss case 有弱正向；degree2 /
  two-site 当前实现明显变慢，不应进入 positive candidate set。

因此，当前正确交付物是一个 **profile-assisted software prefetcher prototype** 和一套 policy
screening 结果；后续如果要做 default selector，需要作为新的研究迭代继续做 real-derived
evidence 和 corpus runnability。

## Scope

本审计只覆盖 Kinsn 项目中的 prefetch task：

```text
/home/ruoji/github/bpf-opt/code/bpfopt/crates/bpfopt/src/passes/prefetch.rs
/home/ruoji/github/bpf-opt/code/module/x86/bpf_x86_prefetch.c
/home/ruoji/github/bpf-opt/code/module/arm64/bpf_arm64_prfm.c
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch
```

它不覆盖：

- LLVM ARM backend 普通 `llvm.prefetch`。
- Dynamic ReJIT 的全局 runtime policy。
- PF-LLM 的硬件 prefetcher ensemble。

## Completion Checklist

| requirement | status | evidence |
|---|---|---|
| Native hint mechanism | completed | `bpfopt` 能插入 kinsn prefetch call；x86 / ARM64 smoke 看到 `prefetcht0` / `prfm pldl1keep`。 |
| Safety / admission | completed first version | profile gate、load-only、same-cacheline dedup、site budget、skip reason、candidate diagnostics。复杂 CFG dominance 仍是后续增强，不阻塞当前 research candidate。 |
| 策略筛选 | taxonomy rebuilt, first round complete for current policy set | 已测 same-iteration、packet/map structural、future-address single-stream、spatial、MLOP、struct-field、mixed-policy-table、stream-of-strides 等访问策略；horizon、degree、hint variant 只作为参数 sweep。当前已把正向用例、诊断用例和跳过规则分开。 |
| PMU attribution | completed | AWS ARM64 `c7g.large` 可采 `cycles/instructions/cache_references/cache_misses`；positive timing 与 miss drop 对齐的 cases 已记录。 |
| Slowdown diagnosis | completed for current candidates | same-iteration / fixed distance / plain stride / stream-of-strides degree2 都有 non-win evidence；stream-of-strides degree1 有 weak positive evidence。 |
| Profile schema | completed first version | 支持 per-PC `prefetch` / `skip`、per-point hint override、policy、horizon、degree、reason。 |
| Profile generator | completed first version | `/home/ruoji/github/bpf-opt/code/scripts/prefetch_profile_from_candidates.py` 从 candidate TSV 生成 profile JSON，支持 `--rank-column`。 |
| Corpus census | partially completed | `katran` 完整通过；Tracee default census 167 programs / 15542 candidates；all-app 被 runnability 阻塞。 |
| Corpus profile-fed insertion | completed smoke | `katran` single-site applied 1；multi-site applied 12；generated-profile applied 12。 |
| Integrated automatic selector | rejected for default | 缺真实收益证据；当前只能 profile-gated，不接受 default-enable。 |
| Documentation | completed | 主文档、plan、mechanism、safety、policy matrix、microbench design、results、literature、experiment artifacts、commit plan 均在 task 目录下。 |

## Policy Decision

当前保留的 positive research candidates：

| policy | why kept |
|---|---|
| MLOP / index-field | ARM64 PMU-backed strongest signal；future address 已物化。 |
| horizon2 future-address | 有提前量；ARM64 PMU-backed positive。 |
| pipeline next-iteration | 当前轮提前预取下一轮 pointer；PMU-backed positive。 |
| degree1 | degree1 比 degree2/3 更稳；degree 不是越大越好。 |
| spatial-within-page | miss drop 明显，但需要控制 instruction overhead。 |
| struct-field | 小幅正向 PMU signal，可作为 fixed-offset future fields 的 profile-gated candidate。 |
| mixed-policy-table | 主要证明 per-PC prefetch/skip schema 可以保护 negative sites。 |
| stream-of-strides degree1 | high-miss single-site profile 有小幅正向 PMU signal。 |

当前排除的 default candidates：

| policy | why rejected |
|---|---|
| fixed-distance same-iteration | 没有稳定提前量，ARM64 geomean 不支持。 |
| default structural packet/map | 真实 `katran` census 匹配很多，但没有 profile/PMU evidence 时全部跳过。 |
| same-iteration map / upper-bound | PMU 不能证明 cache miss 下降转化成收益。 |
| plain stride64 / stride256 / stride4096 | timing 中性或弱，不足以单独启用。 |
| x86 `nta` | 当前 horizon/degree cases 明显变慢。 |
| ARM64 L2 hint default | L2 hints 没超过 L1 hints。 |
| stream-of-strides degree2 / two-site implementation | ARM64 T/C exec `1.557562` / `1.002240` 两批结果都没有净收益；degree2 / two-site placement 被排除。 |

## Experiment Coverage

主要 experiment artifact 在：

```text
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/experiments
```

核心实验链路：

| category | representative experiment | what it answered |
|---|---|---|
| mechanism / smoke | `2026-06-04-prefetch-pf-llm-missing-policy-smoke` | x86 treatment 能按 profile 插入 `prefetcht0`。 |
| ARM64 PMU | `2026-06-03-prefetch-c7g-pmu-policy-diagnosis` | positive timing 是否伴随 cache miss drop。 |
| missing policy attribution | `2026-06-04-prefetch-pf-llm-missing-policy-arm64-attribution` | struct-field / mixed-policy-table / stream-of-strides 的 ARM64 结果。 |
| corpus census | `2026-06-04-prefetch-corpus-default-structural-smoke` | `katran` 真实 program 有 224 个候选，但默认 skip。 |
| profile-fed corpus | `2026-06-04-prefetch-corpus-profile-fed-smoke` | 真实 `katran` 单点 profile 能插入 1 个 prefetch。 |
| multi-site corpus | `2026-06-04-prefetch-corpus-multisite-profile-fed` | 真实 `katran` 多点 profile 能插入 12 个 prefetch。 |
| generated profile | `2026-06-04-prefetch-corpus-generated-profile-table` | candidate TSV -> profile JSON -> bpfopt insertion path 可用。 |
| pass overhead | `2026-06-04-prefetch-corpus-tracee-no-diagnostics-rerun` | default no-diagnostics 和 layout cache 把 Tracee total `bpfopt_ms` 从 308187 降到 51357。 |
| all-app status | `2026-06-04-prefetch-corpus-allapps-no-diagnostics-rerun` | all-app corpus 当前不是可用 prefetch policy gate。 |

## What Is Not Finished

下面这些不是当前 task 的完成条件，而是下一轮研究条件：

1. 修复 all-app corpus app runnability。
2. 从真实 workload 生成 profile / PMU evidence score，而不是 PC-order top-N。
3. 设计 automatic future-address selector。
4. 用 real-derived micro 或 corpus workload 证明 selected policy 在真实 shape 上有收益。
5. 再决定是否从 `profile-gated` 推进到 `default-enable`。

## Final Gate

当前 gate 结果：

```text
mechanism: pass
safety/admission: pass for profile-gated prototype
micro policy screening: pass
PMU attribution: pass
corpus census: partial pass
corpus profile insertion: pass smoke
default selector: fail / rejected by evidence
task decision: profile-gated research candidate only
```

因此，本 task 的当前完成标准不是“默认启用 prefetch”，而是“完成系统性筛选并得出不能默认启用、
只能 profile-gated 继续研究的结论”。
