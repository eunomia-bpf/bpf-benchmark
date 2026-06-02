# Prefetch Commit Plan

最后更新：2026-06-02。

## 结论

提交发生在 `code` 仓库，不是在顶层 workspace：

```text
repo:   /home/ruoji/github/bpf-opt/code
branch: codex/llvm-arm-backend
remote: origin git@github.com:eunomia-bpf/bpf-benchmark.git
```

commit message 写在 `git commit` 的 message 里。本文只保存提交计划，不能替代 commit message。

建议拆成 4 个 commit：

1. `bpfopt: add profile-gated prefetch policy`
2. `runner: apply bpfopt passes in micro kernel runtime`
3. `micro: add prefetch policy probes`
4. `docs: add kinsn prefetch reports`

这样拆分符合要求：前三个 commit 分别对应实现、运行基础设施、benchmark 输入；第 4 个 commit
单独提交文档和完整小型实验 artifact。不能把实验结果混在代码实现 commit 里。

## 文档和实验数据放哪里

提交到 `code` repo 的文档和实验 artifact 放在：

```text
/home/ruoji/github/bpf-opt/code/docs/projects/kinsn/tasks/prefetch
```

准备提交：

| path | 作用 |
|---|---|
| `docs/projects/kinsn/tasks/prefetch/README.md` | 对外 self-contained task summary。 |
| `docs/projects/kinsn/tasks/prefetch/policy-matrix.md` | policy matrix：每个策略怎么实现、什么 case 触发、结果如何。 |
| `docs/projects/kinsn/tasks/prefetch/results.md` | 实验摘要：怎么跑、指标含义、每个实验结论。 |
| `docs/projects/kinsn/tasks/prefetch/experiments/README.md` | 提交的实验 artifact 索引。 |
| `docs/projects/kinsn/tasks/prefetch/experiments/*` | 每个关键实验的 `report.md`、`analysis/*`、`data/run-contract.json` 和小型 JSON/TSV。 |
| `docs/projects/kinsn/tasks/prefetch/commit-plan.md` | 本提交计划。 |

原始完整实验目录仍保留在顶层 workspace：

```text
/home/ruoji/github/bpf-opt/experiments
```

repo 内不提交完整 AWS stdout/stderr、大 runner result directory、编译产物和调试大文件；每个提交的
artifact report 都保留原始目录路径和复现信息。

## Commit 1: bpfopt policy

Subject:

```text
bpfopt: add profile-gated prefetch policy
```

Stage only:

```text
bpfopt/crates/bpfopt/src/analysis/bbprogram_lift.rs
bpfopt/crates/bpfopt/src/passes/mod.rs
bpfopt/crates/bpfopt/src/passes/prefetch.rs
bpfopt/crates/bpfopt/src/passes/prefetch_tests.rs
```

Message body draft:

```text
The prefetch pass used to be a structural probe: it could match packet or
map pointer loads, but it did not have enough information to distinguish
safe/profitable candidates from hot, dependent, or duplicated accesses.
That is too permissive for prefetch because prefetch is an inserted hint,
not a replacement for an existing load.

Add a conservative prefetch policy with packet/map pointer tracking,
stack-alias propagation, register-offset handling, load-only filtering,
same-cacheline deduplication, dependent-depth admission, per-program site
budgeting, and a profile gate for map-value candidates. Map-value prefetch
remains disabled by default unless the profile explicitly allows a load PC
or a prefetch point.

This keeps packet first-deref as a research candidate while preventing
structural map-value prefetch from being enabled without profile evidence.

Testing:
- cargo test -p bpfopt prefetch
- See docs/projects/kinsn/tasks/prefetch/results.md for AWS micro runs.
```

`Signed-off-by` 可以使用 git config 中的：

```text
Zhengjie Ji <103107033+zhengjieji@users.noreply.github.com>
```

## Commit 2: runner infrastructure

Subject:

```text
runner: apply bpfopt passes in micro kernel runtime
```

Stage only:

```text
runner/include/micro_exec.hpp
runner/libs/input_generators.py
runner/mk/build.mk
runner/src/common.cpp
runner/src/elf_program_loader.cpp
runner/src/kernel_runner.cpp
runner/suites/_common.py
micro/driver.py
```

Message body draft:

```text
The micro kernel runtime previously loaded the original ELF object directly.
That meant BPFREJIT_BENCH_PASSES=prefetch did not change the BPF program
under test, so control and treatment produced identical xlated/native code.

Route kernel micro programs through bpfopt when a pass is requested, then
load the transformed raw BPF bytecode through the raw kinsn loader. Extend
the raw loader path so map-backed micro programs can still use BTF maps and
map relocations after kinsn calls are inserted.

This makes micro kernel runtime usable for same-LLC prefetch attribution:
control keeps the original bytecode, while treatment runs the transformed
bytecode containing prefetch kinsn calls.

Testing:
- AWS x86/ARM64 prefetch selector smoke
- AWS x86/ARM64 profile-fed map-value attribution
- See docs/projects/kinsn/tasks/prefetch/results.md.
```

## Commit 3: micro probes

Subject:

```text
micro: add prefetch policy probes
```

Stage only:

```text
micro/config/micro_pure_jit.yaml
micro/config/prefetch-map-page-stride-profile-pc52.json
micro/config/prefetch-pipeline-page-stride-profile-pc45-r1.json
micro/config/prefetch-upper-page-stride-profile-pc62.json
micro/programs/prefetch_research.bpf.c
micro/programs/prefetch_research.md
micro/programs/prefetch_map_research.bpf.c
micro/programs/prefetch_map_research.md
micro/programs/prefetch_upper_bound.bpf.c
micro/programs/prefetch_upper_bound.md
```

Message body draft:

```text
Prefetch policy needs controlled benchmark shapes because a prefetch hint
can either hide memory latency or add overhead. Add synthetic-control micro
programs that isolate the policy cases used in the Kinsn prefetch task:
fixed-distance packet loads, packet first-deref, indirect chains,
cacheline deduplication, map-backed page-stride loads, same-iteration
upper-bound loads, and next-iteration/software-pipeline prefetch.

Add profile JSON files for profile-gated map-value and next-iteration
experiments. These probes are not real-derived workload evidence; they are
controlled policy probes used to test admission, codegen, and same-LLC
attribution.

Testing:
- Local object/native build smoke for prefetch micro programs
- AWS x86/ARM64 micro attribution summarized in
  docs/projects/kinsn/tasks/prefetch/results.md
```

## Commit 4: docs and experiment artifacts

Subject:

```text
docs: add kinsn prefetch reports
```

Stage only:

```text
docs/projects/kinsn/tasks/prefetch/README.md
docs/projects/kinsn/tasks/prefetch/policy-matrix.md
docs/projects/kinsn/tasks/prefetch/results.md
docs/projects/kinsn/tasks/prefetch/commit-plan.md
docs/projects/kinsn/tasks/prefetch/experiments/
```

Message body draft:

```text
The prefetch task now has code, benchmark probes, and multiple AWS micro
runs, but the result summary alone is not enough for reviewers to check
the evidence. The task needs a self-contained report bundle that explains
what prefetch means in Kinsn, how each policy is selected, how the micro
experiments run, and where each result comes from.

Add the prefetch task summary, policy matrix, experiment summary, commit
plan, and small experiment artifacts for the prefetch runs. Each experiment
artifact includes report.md, analysis files, run-contract data, and small
JSON/TSV metadata. Large AWS logs and generated binaries remain in the
top-level experiments directory and are referenced from the reports rather
than committed into the repository.

The reports record that the PREFETCHT0/PRFM kinsn path works, but no
prefetch policy is ready for default enablement. Next-iteration prefetch is
the strongest current candidate, but its ARM64 effect size is unstable and
still needs PMU-capable or longer-run validation.

Testing:
- Documentation artifact audit: 20 experiment directories, 144 files, about
  1.2 MiB under docs/projects/kinsn/tasks/prefetch/experiments
```

## Files explicitly excluded

Do not stage:

```text
micro/results/aws_*
corpus/results/aws_*
micro/programs/.bpf-compiler-config
micro/programs/build-x86/kernel_offsets.h
micro/programs/arm64_direct_abi_coverage.bpf.ll
Makefile
vendor/Makefile
bpfopt/crates/bpfopt/src/passes/cond_select.rs
bpfopt/kinsnprober/src/main.rs
llvm-backend/llvm
```

These are either unrelated dirty files, generated files, historical result directories, or separate tasks.

## Pre-commit checklist

Before committing, run from `/home/ruoji/github/bpf-opt/code`:

```bash
git status --short
git diff --stat
git diff
```

For each commit:

1. Stage only the files listed for that commit.
2. Re-run `git diff --cached --stat`.
3. Inspect `git diff --cached`.
4. Commit with Linux-kernel-style message.
5. Do not push until the user explicitly asks.
