# Prefetch Commit Plan

最后更新：2026-06-04。

## 结论

Prefetch task 的可提交内容应提交到 `code` repo，不提交到顶层 workspace：

```text
repo:   /home/ruoji/github/bpf-opt/code
remote: origin git@github.com:eunomia-bpf/bpf-benchmark.git
branch: codex/llvm-arm-backend
```

本计划只覆盖 Kinsn prefetch task。不要把下面内容混入 prefetch commits：

- `/home/ruoji/github/bpf-opt/experiments` 顶层完整 AWS raw logs；
- `code/micro/results/aws_*` 和 `code/corpus/results/aws_*` 大型 runner result directories；
- `llvm-backend/llvm` 子模块 dirty state；
- docs project migration / archive 的大批量无关改动；
- `Makefile`、`cond_select.rs`、`vendor/Makefile` 等非 prefetch task 改动。

如果要提交当前 prefetch batch，建议拆成 5 个 commit。这样拆分按工程边界分离：
selector/profile 机制、pass scalability 修复、micro probes、profile/corpus helper、文档与 compact
experiment artifacts。

## Commit 1: bpfopt prefetch profile policy

Subject:

```text
bpfopt: add profile-gated prefetch policies
```

Stage only the relevant hunks from:

```text
bpfopt/crates/bpfopt/src/passes/prefetch.rs
bpfopt/crates/bpfopt/src/passes/prefetch_tests.rs
runner/config/passes/prefetch/default.yaml
corpus/config/prefetch/*.json
micro/config/prefetch-*.json
```

Purpose:

```text
Add a conservative prefetch selector that can be driven by a per-PC profile
table. The profile supports prefetch/skip actions, per-point hint override,
policy metadata, horizon, degree, and reason fields. The default path remains
evidence-gated and does not insert prefetch without profile evidence.
```

## Commit 2: bpfopt prefetch census scalability

Subject:

```text
bpfopt: reduce prefetch corpus census overhead
```

Stage only the relevant hunks from:

```text
bpfopt/crates/bpfopt/src/analysis/bbprogram.rs
bpfopt/crates/bpfopt/src/pass.rs
bpfopt/crates/bpfopt/src/passes/prefetch.rs
bpfopt/crates/bpfopt/src/passes/prefetch_tests.rs
```

Purpose:

```text
Disable per-candidate diagnostics by default, add explicit candidate export
flags, and cache site PC / layout offsets inside the prefetch pass. This keeps
large-program corpus census usable while preserving an explicit diagnostics
mode for profile generation.
```

## Commit 3: tools prefetch profile generator

Subject:

```text
tools: generate prefetch profiles from corpus candidates
```

Stage:

```text
scripts/prefetch_profile_from_candidates.py
corpus/config/prefetch/katran-profile-pc16-r0.json
corpus/config/prefetch/katran-profile-multisite-map-value.json
corpus/config/prefetch/katran-profile-generated-map-value-top12.json
```

Purpose:

```text
Convert candidate diagnostics TSV into per-PC prefetch profile JSON. The first
generator supports source filtering, site budget, hint/policy/horizon/degree
metadata, and rank-column based ordering for future profile/PMU evidence.
```

## Commit 4: micro prefetch policy probes

Subject:

```text
micro: add prefetch policy probes
```

Stage:

```text
micro/config/micro_pure_jit.yaml
micro/programs/prefetch_*.bpf.c
micro/programs/prefetch_*.md
micro/config/prefetch-*.json
micro/programs/build-x86/kernel_offsets.h
micro/programs/kernel_offsets.h
```

Purpose:

```text
Add synthetic-control micro cases for fixed distance, packet/map candidates,
future-address horizon, degree, hint variants, spatial footprint, MLOP,
struct-field, mixed policy table, and stream-of-strides probes.
```

## Commit 5: docs prefetch task report

Subject:

```text
docs: add kinsn prefetch reports
```

Stage:

```text
docs/projects/kinsn/tasks/prefetch/README.md
docs/projects/kinsn/tasks/prefetch/plan.md
docs/projects/kinsn/tasks/prefetch/mechanism.md
docs/projects/kinsn/tasks/prefetch/safety-rules.md
docs/projects/kinsn/tasks/prefetch/policy-matrix.md
docs/projects/kinsn/tasks/prefetch/microbench-design.md
docs/projects/kinsn/tasks/prefetch/results.md
docs/projects/kinsn/tasks/prefetch/completion-audit.md
docs/projects/kinsn/tasks/prefetch/commit-plan.md
docs/projects/kinsn/tasks/prefetch/literature/
docs/projects/kinsn/tasks/prefetch/experiments/
```

Purpose:

```text
Provide a self-contained task report, policy matrix, microbenchmark design,
literature review, compact experiment artifact bundle, and final completion
audit. Full raw AWS logs remain in /home/ruoji/github/bpf-opt/experiments.
```

## Required validation before push

At minimum rerun:

```bash
cd /home/ruoji/github/bpf-opt/code/bpfopt
cargo test -p bpfopt prefetch

cd /home/ruoji/github/bpf-opt/code
python3 -m py_compile scripts/prefetch_profile_from_candidates.py
```

Recent experiment evidence is summarized in:

```text
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/results.md
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch/experiments
```

Key referenced experiments:

- `2026-06-03-prefetch-c7g-pmu-policy-diagnosis`: c7g PMU-backed attribution.
- `2026-06-04-prefetch-pf-llm-missing-policy-smoke`: x86 correctness / emit smoke.
- `2026-06-04-prefetch-pf-llm-missing-policy-arm64-attribution`: ARM64 paired attribution for
  struct-field, mixed-policy-table, and stream-of-strides.
- `2026-06-04-prefetch-corpus-default-structural-smoke`: first `katran` corpus census and candidate TSV.
- `2026-06-04-prefetch-corpus-profile-fed-smoke`: real `katran` single-site profile-fed insertion.
- `2026-06-04-prefetch-corpus-multisite-profile-fed`: real `katran` multi-site profile-fed insertion.
- `2026-06-04-prefetch-corpus-generated-profile-table`: diagnostics TSV to generated profile smoke.
- `2026-06-04-prefetch-corpus-tracee-no-diagnostics-rerun`: Tracee overhead fix validation.
- `2026-06-04-prefetch-corpus-allapps-no-diagnostics-rerun`: all-app corpus runnability status.
