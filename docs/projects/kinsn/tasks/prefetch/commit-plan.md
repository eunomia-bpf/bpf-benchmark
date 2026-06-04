# Prefetch Commit Plan

最后更新：2026-06-04。

## 结论

本文件记录本次实际提交拆分。提交发生在 `code` repo，不是在顶层 workspace：

```text
repo:   /home/ruoji/github/bpf-opt/code
remote: origin git@github.com:eunomia-bpf/bpf-benchmark.git
branch: codex/llvm-arm-backend
```

本次只提交 Kinsn prefetch task 相关改动。不要提交：

- `/home/ruoji/github/bpf-opt/experiments` 顶层完整 raw logs；
- `code/micro/results/aws_*` 大型 runner result directories；
- `llvm-backend/llvm` 子模块 dirty state；
- docs 迁移 / archive 的无关大批量改动；
- `Makefile`、`cond_select.rs`、`vendor/Makefile` 等非 prefetch task 改动。

本次拆成 4 个 commit：

1. `module: add prefetch hint variants`
2. `bpfopt: add profile-gated prefetch policy`
3. `micro: add prefetch policy probes`
4. `docs: add kinsn prefetch reports`

这样拆分符合代码边界：module ABI / kfunc target、bpfopt selector、micro workload、docs 和
实验 artifact 分开提交。

## Commit 1: module hint variants

Subject:

```text
module: add prefetch hint variants
```

Stage only:

```text
module/x86/bpf_x86_prefetch.c
module/arm64/bpf_arm64_prfm.c
runner/config/passes/prefetch/default.yaml
bpfopt/kinsnprober/src/main.rs
```

Purpose:

```text
Expose x86 prefetchnta/prefetcht0/prefetcht1/prefetcht2 and ARM64
prfm pldl1keep/pldl1strm/pldl2keep/pldl2strm so policy experiments can
separate hint selection from placement and degree.
```

## Commit 2: bpfopt policy

Subject:

```text
bpfopt: add profile-gated prefetch policy
```

Stage only:

```text
bpfopt/crates/bpfopt/src/passes/prefetch.rs
bpfopt/crates/bpfopt/src/passes/prefetch_tests.rs
```

Purpose:

```text
Add conservative packet/map pointer tracking, profile-gated map-value
prefetch points, same-cacheline dedup, site budgeting, hint selection,
and per-site prefetch/skip actions.
```

## Commit 3: micro probes

Subject:

```text
micro: add prefetch policy probes
```

Stage only:

```text
micro/config/micro_pure_jit.yaml
micro/programs/prefetch_upper_bound.bpf.c
micro/programs/prefetch_upper_bound.md
micro/config/prefetch-*.json
```

Purpose:

```text
Add synthetic-control micro cases and profile JSONs for horizon, degree,
spatial footprint, MLOP/index-field, struct-field, mixed policy table,
and stream-of-strides prefetch policy probes.
```

## Commit 4: docs and experiment artifacts

Subject:

```text
docs: add kinsn prefetch reports
```

Stage only:

```text
docs/projects/kinsn/tasks/prefetch/README.md
docs/projects/kinsn/tasks/prefetch/plan.md
docs/projects/kinsn/tasks/prefetch/mechanism.md
docs/projects/kinsn/tasks/prefetch/safety-rules.md
docs/projects/kinsn/tasks/prefetch/policy-matrix.md
docs/projects/kinsn/tasks/prefetch/microbench-design.md
docs/projects/kinsn/tasks/prefetch/results.md
docs/projects/kinsn/tasks/prefetch/commit-plan.md
docs/projects/kinsn/tasks/prefetch/literature/
docs/projects/kinsn/tasks/prefetch/experiments/
```

Purpose:

```text
Provide a self-contained task report, policy matrix, microbenchmark design,
literature review, and compact experiment artifact bundle. Full raw AWS logs
remain in /home/ruoji/github/bpf-opt/experiments.
```

## Validation referenced by commits

Commands and results are recorded in:

```text
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/results.md
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/experiments
```

Recent key experiments:

- `2026-06-03-prefetch-c7g-pmu-policy-diagnosis`: c7g PMU-backed attribution.
- `2026-06-04-prefetch-pf-llm-missing-policy-smoke`: x86 correctness / emit smoke.
- `2026-06-04-prefetch-pf-llm-missing-policy-arm64-attribution`: ARM64 smoke and paired attribution for struct-field, mixed-policy-table, and stream-of-strides.
