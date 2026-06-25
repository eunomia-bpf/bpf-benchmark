# eBPF 源码优化探索计划

Last updated: 2026-06-25

本文档定义一个只修改应用 eBPF 源码的探索流程。目标是评估“人工重写 upstream app 的 eBPF C 源码”是否能在真实应用加载路径下改善 benchmark workload 表现。该流程不使用 `kinsn`、`bpfopt`、ReJIT、shim、LD_PRELOAD、native-loader，且不产生 commit 或 push。

## 边界

- 只允许修改 app 自己的 eBPF 源码或其直接 eBPF 头文件。
- 真实 app binary 仍按现有 runner 启动，并由 app 自己加载 BPF 程序。
- 不直接用 framework、bpftool、libbpf 小工具或自定义 loader 加载 `.bpf.o`。
- 不使用 `BPF_PROG_REJIT`、`bpfopt --pass ...`、`runner/config/passes/*`、shim socket、LD_PRELOAD 或 native-loader。
- framework 仍只保留 raw workload payload；任何 ratio、平均值、geomean、wins/losses、summary 都在外部分析脚本中计算。
- 不运行 `git add`、`git commit`、`git push`。只允许读状态的 git 命令，例如 `git status`、`git diff`、`git show`。
- 不使用 `git restore`、`git reset`、`git checkout --`、`git stash`、`git revert` 等会破坏或隐藏工作区状态的命令。

## 运行模式

源码优化评估使用 `SKIP_REJIT=all`。该模式会跳过 ReJIT，并阻止 shim/LD_PRELOAD 注入；corpus 只运行 baseline measurement，不再启动 post_rejit phase。

参考 `docs/eval_kinsn.md`，正式 attempt 使用接近 kinsn evaluation 的参数：

```sh
SKIP_REJIT=all \
BPFREJIT_CORPUS_APPS='<app>' \
BPFREJIT_CORPUS_BPF_STATS=0 \
SAMPLES=3 WORKLOAD_DURATION=180 WARMUPS=1 \
BPFREJIT_CORPUS_APP_TIMEOUT=3600 \
BPFREJIT_CORPUS_REJIT_TIMEOUT=1200 \
TIMEOUT=7200 KEEP_WORKDIRS=1 \
make corpus
```

如需快速验证编译或启动，可以先运行 smoke，但 smoke 结果不能作为正式结论：

```sh
SKIP_REJIT=all \
BPFREJIT_CORPUS_APPS='<app>' \
BPFREJIT_CORPUS_BPF_STATS=0 \
SAMPLES=1 WORKLOAD_DURATION=30 WARMUPS=0 \
BPFREJIT_CORPUS_APP_TIMEOUT=1800 \
TIMEOUT=3600 KEEP_WORKDIRS=1 \
make corpus
```

## Attempt 目录

每次优化尝试创建一个时间戳目录：

```text
docs/source-opt/YYYYMMDD-HHMMSS-<app>-<slug>/
  README.md
  source.diff
  build.log
  run-command.sh
  result-paths.txt
  correctness.md
```

字段含义：

- `README.md`：中文记录本次尝试的假设、修改位置、预期影响、风险和最终结论。
- `source.diff`：本次源码修改的完整 patch。patch 必须能从 attempt 前源码状态重新应用。
- `build.log`：构建命令输出摘要或日志路径。
- `run-command.sh`：实际运行的 `make corpus` 命令；只作为记录，不要求可执行。
- `result-paths.txt`：本次 run 的 `corpus/results/...` 路径。
- `correctness.md`：正确性检查清单、失败原因和保守结论。

## 每次尝试流程

1. 记录起点：
   - 运行 `git status --short`。
   - 运行 `df -h . /var/lib/docker 2>/dev/null || df -h .` 检查磁盘空间。
   - 若存在无关未提交改动，先记录并避免触碰这些文件；如果影响目标 app，停止等待人工确认。
2. 建立 attempt 目录：
   - 目录名使用本地时间戳和 app 名，例如 `20260625-143000-katran-mod-hash`。
3. 选择一个 app 和一个很小的源码假设：
   - 每次只改一个 app。
   - 每次只验证一个优化点，避免把多个机制混在同一个 patch 中。
4. 修改 eBPF 源码：
   - 优先改 `vendor/repos/<app>/...` 中真实 upstream source。
   - 不修改 runner、pass yaml、shim、daemon、bpfopt 或 workload。
5. 生成并保存 patch：
   - 将本次源码变更写入 `source.diff`。
   - patch 中不包含 result 文件、cache、build artifact 或无关文档。
6. 构建真实 app artifact：
   - 通过 `make corpus` 的依赖或 `make -C vendor apps-<arch>` 触发现有 app build。
   - 不手写 loader，不绕过 upstream binary。
7. 正确性 gate：
   - app 必须成功启动。
   - workload return code 必须为 0。
   - app result `status` 必须为 `ok`，`error` 必须为空。
   - 如果 verifier、CO-RE、libbpf load、map layout、tail-call key 或 app 语义失败，本次 attempt 判定为失败。
8. 正式 run：
   - 使用 `SKIP_REJIT=all` 和上面的正式参数。
   - 每个 app 至少完成 5 个独立源码优化 attempt；每个 attempt 单独跑目标 app。
   - 一次只调优一个 app；不要一次性跑全量 6 app。每个 run 必须设置单个 `BPFREJIT_CORPUS_APPS='<app>'`。
9. 记录结果：
   - 写入 result 路径和 raw workload payload 位置。
   - 不在 framework 内计算比较指标；外部脚本可后处理 baseline 源码 run 与优化源码 run。
10. 回到 attempt 前源码状态：
    - 保存 patch 后，撤回本次 app 源码修改，只保留 `docs/source-opt/...` 记录目录。
    - 不使用 `git restore/reset/stash`。若需要回滚，用保存的 patch 做人工反向检查后只撤回本次 attempt 修改。
11. 磁盘清理：
    - 每个 attempt 结束后再次检查 `df -h . /var/lib/docker 2>/dev/null || df -h .`。
    - 如果 Docker 或 workspace 可用空间接近耗尽，先记录当前 result 路径，再删除无关旧 runtime image、dangling image 或旧临时构建缓存；不要删除本次 attempt 的 `docs/source-opt/...` 目录和仍需分析的 `corpus/results/...`。

## App 顺序与目标进展

按实现风险从低到高逐个推进：

| 顺序 | App | 原因 | 最低进展 |
| --- | --- | --- | --- |
| 1 | `katran` | BPF 文件少，hot path 明确，pktgen workload 稳定 | 5 个独立源码优化 attempt |
| 2 | `bcc/set` | 多个 libbpf-tools 小程序，编译反馈快 | 5 个独立源码优化 attempt |
| 3 | `tracee/monitor` | workload 覆盖强，但 BPF 程序和事件语义较多 | 5 个独立源码优化 attempt |
| 4 | `cilium/agent` | datapath/tail-call/map 语义复杂，需谨慎 | 5 个独立源码优化 attempt |
| 5 | `tetragon/observer` | 程序数量多，policy/event 语义复杂 | 5 个独立源码优化 attempt |
| 6 | `otelcol-ebpf-profiler/profiling` | tail-call accounting 和 profiler 语义复杂 | 5 个独立源码优化 attempt |

总目标是至少 30 个源码优化 attempt。必须一个 app 一个 app 地推进：当前 app 的 5 个 attempt 和小结完成后，才进入下一个 app。

## 正确性原则

源码重写必须保持语义等价。允许的优化包括：

- 删除真实不可达的冗余分支，但必须证明条件来自已有配置或 verifier-known invariant。
- 将重复 bounds check 合并为等价检查。
- 保持 map key/value layout 不变的局部计算重排。
- 保持 helper 调用顺序语义不变的局部数据准备优化。
- 保持 packet bounds、tail-call key、event payload ABI、ringbuf/perfbuf payload layout 不变的控制流整理。

禁止的优化包括：

- 跳过安全检查、policy check、verifier-required bounds check 或 error handling。
- 改变 map layout、event ABI、tail-call dispatch key、program attach point 或 app-visible payload。
- 用 benchmark-only 常量替代真实 app 配置，除非 upstream app 在该 benchmark 配置下本来就是常量，且记录了证明。
- 为了跑分降低功能覆盖、关闭程序、删除事件、减少被加载 BPF program。
- 引入 framework-side loader、shim、ReJIT、bpfopt 或 kinsn 依赖。

## Baseline 公平性

每个 app 的源码优化 attempt 必须与同一 app 的原始源码 run 比较。两边保持：

- 同一 commit 起点。
- 同一 kernel/runtime image 配置。
- 同一 app workload。
- 同一 `SAMPLES=3 WORKLOAD_DURATION=180 WARMUPS=1`。
- 同一 `SKIP_REJIT=all`，不使用 shim/LD_PRELOAD。
- 同一平台，优先 x86 KVM；需要跨架构证据时再做 AWS arm64 smoke 或正式 run。

## 结果判定

每个 attempt 只给出三类结论：

- `accepted-for-analysis`：构建、启动、workload、正确性 gate 全部通过，结果路径完整。
- `rejected-correctness`：源码改变可能破坏语义、ABI、加载、verifier 或 workload 行为。
- `rejected-no-signal`：正确但 raw workload 没有可解释改善，或结果噪声太大。

是否构成论文 claim，必须等外部分析完成后再判断。
