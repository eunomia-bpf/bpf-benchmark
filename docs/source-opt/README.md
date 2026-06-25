# eBPF 源码优化探索计划

Last updated: 2026-06-25

本文档是 `docs/source-opt/` 的执行手册。目标是系统性探索：在不使用
`kinsn`、`bpfopt`、ReJIT、shim、LD_PRELOAD 或 native-loader 的前提下，
只重写真实应用的 eBPF 源码，观察真实 app loader 加载优化后 BPF 程序时
workload 是否改善。

## 核心结论先行

- 这是源码优化实验，不是 workload 改写实验。
- 每次只调一个 app，不一次性跑全量 6 app。
- 每个 app 至少完成 1 个 clean-source baseline run 和 5 个独立源码优化
  attempt。
- 每个 attempt 结束后，app 源码必须回到 attempt 前状态；只保留
  `docs/source-opt/<app-slug>/YYYYMMDD-HHMMSS-<attempt-slug>/` 下的 patch、
  记录和结果路径。
- agent 不运行 `git add`、`git commit`、`git push`。除只读状态检查外，不用
  git 命令修改工作区。

## 实验问题

**Thesis:** 手工重写真实 app 的 eBPF C 源码，可以在保持 app 功能、加载路径、
map/event ABI 和 workload 不变的情况下，降低 BPF hot path 代价或提高 app
workload throughput。

| ID | Claim | 证据 | 状态 |
| --- | --- | --- | --- |
| C1 | 源码重写不破坏真实 app 启动和 BPF 加载 | app `status=ok`，`error=""`，workload returncode 为 0 | planned |
| C2 | 源码重写保持 app-visible 语义 | event/map/tail-call/payload ABI 无变化；必要时用 app 日志或 raw payload 佐证 | planned |
| C3 | 源码重写带来可解释性能信号 | clean-source baseline run 与 optimized-source run 的 raw workload payload 可配对做外部分析 | planned |

## 强制边界

- 只允许修改 app 自己的 eBPF 源码或直接 eBPF 头文件。
- 真实 app binary 仍按现有 runner 启动，并由 app 自己加载 BPF 程序。
- 不直接用 framework、bpftool、libbpf 小工具或自定义 loader 加载 `.bpf.o`。
- 不使用 `BPF_PROG_REJIT`、`bpfopt --pass ...`、`runner/config/passes/*`、
  shim socket、LD_PRELOAD、native-loader 或 kinsn module path。
- framework 只保留 raw workload payload；任何 ratio、平均值、geomean、
  wins/losses、summary 都在外部分析脚本中计算。
- 不降低 app 功能覆盖，不删除被加载 BPF program，不绕开 policy/security check。
- 不运行 `git add`、`git commit`、`git push`。
- 不使用 `git restore`、`git reset`、`git checkout --`、`git stash`、
  `git revert` 等会破坏或隐藏工作区状态的命令。

## 当前运行语义

源码优化评估使用 `SKIP_REJIT=all`。该模式在当前代码中有三个关键效果：

- 不注入 shim/LD_PRELOAD。
- 不加载 kinsn modules。
- corpus 只运行 baseline measurement；baseline stop 后直接结束 app lifecycle，
  `post_rejit` 为 `null`，`rejit_result.mode` 为 `skip_rejit_all`。

这意味着源码优化的比较单位不是同一个 result 内的 baseline/post pair，而是：

```text
clean upstream source result.json
vs.
optimized source attempt result.json
```

## 性能记录

本节是 docs 侧 post-hoc 记录，不改变 runner 或 `result.json` schema。`samples`
列是 3 次 workload sample 的原始吞吐量派生值；`vs baseline` 是同一 app 内
attempt mean 相对 clean-source baseline mean 的文档侧计算。网络类 workload
使用 pktgen stdout 中的每 sample total pps；stress-ng workload 使用 stdout 中
各 stressor real-time `bogo ops/s` 的 sample 内求和。数值越高越好。

### `katran`

| Run | Primary metric | Samples | vs baseline | Result |
| --- | ---: | --- | ---: | --- |
| `baseline` | pktgen_total_pps mean=3061171; errors=986773942 | `3059743, 3085331, 3038438` | n/a | `corpus/results/x86_kvm_corpus_20260625_082123_391460` |
| `20260625-013540-udp-parse-first` | pktgen_total_pps mean=3051836; errors=985181939 | `3067825, 3063624, 3024059` | -0.30% | `corpus/results/x86_kvm_corpus_20260625_084248_406394` |
| `20260625-015559-icmp-protocol-refresh` | pktgen_total_pps mean=3045438; errors=976211084 | `3025440, 3035539, 3075335` | -0.51% | `corpus/results/x86_kvm_corpus_20260625_090323_284447` |
| `20260625-021633-calc-offset-fastpath` | pktgen_total_pps mean=3053240; errors=844276210 | `3050340, 3051894, 3057485` | -0.26% | `corpus/results/x86_kvm_corpus_20260625_092311_749645` |
| `20260625-023639-quic-connid-no-null-check` | pktgen_total_pps mean=3060385; errors=1034578362 | `3036690, 3053123, 3091341` | -0.03% | `corpus/results/x86_kvm_corpus_20260625_094328_513110` |
| `20260625-025627-stable-rt-header-early-return` | pktgen_total_pps mean=3005981; errors=919785621 | `3001715, 2991963, 3024265` | -1.80% | `corpus/results/x86_kvm_corpus_20260625_100305_598103` |

### `bcc/set`

| Run | Primary metric | Samples | vs baseline | Result |
| --- | ---: | --- | ---: | --- |
| `baseline` | stress_ng_sum_bogo_ops_s mean=710465 | `712551, 710948, 707896` | n/a | `corpus/results/x86_kvm_corpus_20260625_102432_554290` |
| `20260625-033814-opensnoop-reuse-pidtgid` | stress_ng_sum_bogo_ops_s mean=710090 | `708989, 711064, 710216` | -0.05% | `corpus/results/x86_kvm_corpus_20260625_104426_414018` |
| `20260625-035755-tcpconnect-lazy-uid-filter` | stress_ng_sum_bogo_ops_s mean=704178 | `701784, 704943, 705807` | -0.88% | `corpus/results/x86_kvm_corpus_20260625_110418_916430` |
| `20260625-041821-tcplife-cache-newstate` | stress_ng_sum_bogo_ops_s mean=704720 | `704690, 704389, 705081` | -0.81% | `corpus/results/x86_kvm_corpus_20260625_112427_430171` |
| `20260625-043750-syscount-interrupt-fast-return` | stress_ng_sum_bogo_ops_s mean=711554 | `709915, 711686, 713061` | +0.15% | `corpus/results/x86_kvm_corpus_20260625_114437_519205` |
| `20260625-045812-runqlat-skip-idle-tgid-read` | stress_ng_sum_bogo_ops_s mean=705171 | `704250, 704247, 707015` | -0.75% | `corpus/results/x86_kvm_corpus_20260625_120517_651286` |

### `tracee/monitor`

| Run | Primary metric | Samples | vs baseline | Result |
| --- | ---: | --- | ---: | --- |
| `baseline` | stress_ng_sum_bogo_ops_s mean=460865 | `462328, 456918, 463350` | n/a | `corpus/results/x86_kvm_corpus_20260625_122431_943915` |
| `20260625-053834-sys-exit-reuse-saved-ret` | stress_ng_sum_bogo_ops_s mean=458984 | `458065, 459824, 459063` | -0.41% | `corpus/results/x86_kvm_corpus_20260625_124558_225233` |
| `20260625-060003-cache-sys-enter-compat` | stress_ng_sum_bogo_ops_s mean=459817 | `461155, 459142, 459152` | -0.23% | `corpus/results/x86_kvm_corpus_20260625_130746_945964` |
| `20260625-062113-defer-sys-exit-ret-read` | stress_ng_sum_bogo_ops_s mean=460218 | `458576, 460270, 461807` | -0.14% | `corpus/results/x86_kvm_corpus_20260625_132825_862375` |
| `20260625-064212-socket-dup-late-args` | stress_ng_sum_bogo_ops_s mean=458474 | `460912, 456147, 458361` | -0.52% | `corpus/results/x86_kvm_corpus_20260625_134931_275984` |
| `20260625-070258-socket-dup-unix-else` | stress_ng_sum_bogo_ops_s mean=454296 | `454215, 454954, 453718` | -1.43% | `corpus/results/x86_kvm_corpus_20260625_141005_857825` |

### `cilium/agent`

| Run | Primary metric | Samples | vs baseline | Result |
| --- | ---: | --- | ---: | --- |
| `baseline` | pktgen_total_pps mean=1488103 | `1491361, 1493893, 1479055` | n/a | `corpus/results/x86_kvm_corpus_20260625_143038_806522` |
| `20260625-074510-local-delivery-redirect-peer` | pktgen_total_pps mean=1503521 | `1499183, 1511544, 1499836` | +1.04% | `corpus/results/x86_kvm_corpus_20260625_145141_817976` |
| `20260625-080510-from-container-error-unlikely` | pktgen_total_pps mean=1494040 | `1492844, 1485606, 1503670` | +0.40% | `corpus/results/x86_kvm_corpus_20260625_151130_130358` |
| `20260625-082528-cil-lxc-policy-error-unlikely` | pktgen_total_pps mean=1509617 | `1517661, 1501746, 1509443` | +1.45% | `corpus/results/x86_kvm_corpus_20260625_153206_021422` |
| `20260625-084516-cil-to-container-error-unlikely` | pktgen_total_pps mean=1510065 | `1509682, 1507833, 1512679` | +1.48% | `corpus/results/x86_kvm_corpus_20260625_155126_330125` |
| `20260625-090437-tail-ipv4-to-endpoint-revalidate-unlikely` | pktgen_total_pps mean=1672124 | `1668711, 1666812, 1680849` | +12.37% | `corpus/results/x86_kvm_corpus_20260625_161125_111575` |

### `tetragon/observer`

| Run | Primary metric | Samples | vs baseline | Result |
| --- | ---: | --- | ---: | --- |
| `baseline` | stress_ng_sum_bogo_ops_s mean=358681 | `362190, 355981, 357871` | n/a | `corpus/results/x86_kvm_corpus_20260625_163302_015551` |
| `20260625-094557-sparse-selector-active-clear` | stress_ng_sum_bogo_ops_s mean=356619 | `362792, 351299, 355765` | -0.57% | `corpus/results/x86_kvm_corpus_20260625_165241_915913` |
| `20260625-100649-filter-args-active-fastpath` | stress_ng_sum_bogo_ops_s mean=355810 | `358593, 353455, 355383` | -0.80% | `corpus/results/x86_kvm_corpus_20260625_171339_967034` |
| `20260625-102800-lazy-ns-cap-selector-state` | stress_ng_sum_bogo_ops_s mean=387898 | `392895, 386207, 384593` | +8.15% | `corpus/results/x86_kvm_corpus_20260625_173550_665242` |
| `20260625-105314-lazy-ns-cap-conditional-cap-sparse` | stress_ng_sum_bogo_ops_s mean=386271 | `391844, 381971, 384998` | +7.69% | `corpus/results/x86_kvm_corpus_20260625_175958_060141` |

## App 源码、构建和加载路径

每次 attempt 必须先确认目标 app 的源码修改会经过真实 app loader。

| App | 主要 eBPF 源码 | 现有构建入口 | runtime artifact/load path | 注意 |
| --- | --- | --- | --- | --- |
| `katran` | `vendor/repos/katran/katran/lib/bpf/*.c` | `make -C vendor katran-x86` 或 `make corpus` 依赖 | `vendor/build/x86/katran/bpf/*.bpf.o` -> `/artifacts/user/repo-artifacts/x86_64/katran/bpf/`；runner 将 object 交给真实 katran server | 优先从 `balancer.c` hot path 开始 |
| `bcc/set` | `vendor/repos/bcc/libbpf-tools/*.bpf.c` | `make -C vendor bcc-x86` 或 `make corpus` 依赖 | `vendor/build/x86/bcc/bin/*` -> `/usr/local/bin/`；真实 libbpf-tools 自加载 BPF | 每个 tool 是独立 app 子进程，避免一次改多个 tool |
| `tracee/monitor` | `vendor/repos/tracee/pkg/ebpf/c/*.bpf.c` 和 `lsmsupport/*.bpf.c` | `make -C vendor tracee-x86` 或 `make corpus` 依赖 | BPF artifacts embedded/packaged 到真实 `tracee` binary path | 改 event payload 前必须证明 ABI 不变 |
| `cilium/agent` | `vendor/repos/cilium/bpf/**/*.c` 和 `*.h` | `make -C vendor cilium-x86` 或 `make corpus` 依赖 | runtime image 复制 `vendor/repos/cilium/bpf/` 到 `/var/lib/cilium/bpf/`，真实 `cilium-agent` 使用该 datapath | tail-call/map/policy 语义复杂，后置执行 |
| `tetragon/observer` | `vendor/repos/tetragon/bpf/**/*.c` 和 `*.h` | `make -C vendor tetragon-x86` 或 `make corpus` 依赖 | `vendor/build/x86/tetragon/*` -> `/artifacts/tetragon/`，runner 用 `--bpf-lib` 指向该目录 | 程序多，先做单一 policy/hot helper 级别改动 |
| `otelcol-ebpf-profiler/profiling` | `vendor/repos/opentelemetry-ebpf-profiler/support/ebpf/*.ebpf.c` | `make -C vendor otel-x86` 或 `make corpus` 依赖 | `otelcol-ebpf-profiler` binary/artifacts 由 OCB 构建，真实 collector 加载 profiler BPF | tail-called programs 自身 `run_cnt=0`，不要用它判断未执行 |

## 标准命令

正式 run 参数对齐 `docs/eval_kinsn.md` 的 app-by-app corpus 设置，但禁用 ReJIT
和 shim：

```sh
SKIP_REJIT=all \
BPFREJIT_CORPUS_APPS='<single-app>' \
BPFREJIT_CORPUS_BPF_STATS=0 \
SAMPLES=3 WORKLOAD_DURATION=180 WARMUPS=1 \
BPFREJIT_CORPUS_APP_TIMEOUT=3600 \
BPFREJIT_CORPUS_REJIT_TIMEOUT=1200 \
TIMEOUT=7200 KEEP_WORKDIRS=1 \
make corpus
```

`<single-app>` 必须是一个 app 名，不能是 CSV 列表。允许值：

```text
bcc/set
otelcol-ebpf-profiler/profiling
cilium/agent
tetragon/observer
katran
tracee/monitor
```

快速 smoke 只用于编译、启动和 loader sanity，不作为正式结论：

```sh
SKIP_REJIT=all \
BPFREJIT_CORPUS_APPS='<single-app>' \
BPFREJIT_CORPUS_BPF_STATS=0 \
SAMPLES=1 WORKLOAD_DURATION=30 WARMUPS=0 \
BPFREJIT_CORPUS_APP_TIMEOUT=1800 \
TIMEOUT=3600 KEEP_WORKDIRS=1 \
make corpus
```

## 目录结构

每个 app 有一个汇总目录，每次源码优化有独立 attempt 目录：

```text
docs/source-opt/
  README.md
  <app-slug>/
    SUMMARY.md
    baseline/
      run-command.sh
      result-paths.txt
      notes.md
    YYYYMMDD-HHMMSS-<attempt-slug>/
      README.md
      source.diff
      build.log
      run-command.sh
      result-paths.txt
      correctness.md
```

`<app-slug>` 使用 `katran`、`bcc-set`、`tracee-monitor`、
`cilium-agent`、`tetragon-observer`、`otelcol-ebpf-profiler`。

attempt 文件含义：

- `README.md`：假设、修改位置、预期影响、风险、最终状态。
- `source.diff`：本次源码修改的完整 patch，只包含 app 源码相关文件。
- `build.log`：构建摘要或完整日志路径。
- `run-command.sh`：实际运行的 `make corpus` 命令，作为记录即可。
- `result-paths.txt`：本次 run 的 `corpus/results/...` 路径。
- `correctness.md`：正确性 gate 逐项结果。

## 单个 app 的完整流程

每个 app 必须按顺序完成以下步骤。当前 app 未完成前，不进入下一个 app。

1. 起点检查：
   - 运行 `git status --short`。
   - 运行 `df -h . /var/lib/docker 2>/dev/null || df -h .`。
   - 如果有无关未提交改动，记录并避免触碰；如果影响目标 app，停止等待人工确认。
2. 建立 app 汇总目录：
   - 创建 `docs/source-opt/<app-slug>/SUMMARY.md`。
   - 记录目标 app、起点状态、baseline result、5 个 attempt 的状态。
3. 跑 clean-source baseline：
   - 不改源码。
   - 使用正式 run 命令，且 `BPFREJIT_CORPUS_APPS` 只包含当前 app。
   - 将命令和 result path 写入 `baseline/`。
4. 设计 attempt：
   - 每次只验证一个源码优化假设。
   - 每次只改一个 app。
   - 优先小 patch，避免把多个机制混在一起。
5. 修改源码：
   - 只改目标 app 的 eBPF 源码/直接头文件。
   - 不改 runner、Makefile、Dockerfile、workload、bpfopt、shim、pass config。
6. 保存 patch：
   - 使用只读 diff 输出保存 `source.diff`。
   - patch 不包含 build output、cache、result 或无关文档。
7. 构建和 smoke：
   - 通过 `make corpus` 的现有依赖或 `make -C vendor <app>-x86` 构建。
   - 如果构建失败，记录为 `rejected-correctness`，保存 patch 和 build log，然后回到 attempt 前源码状态。
8. 正式 run：
   - 使用正式 run 命令。
   - 检查 result 中 app `status=ok`、`error=""`、`post_rejit=null`、`rejit_result.mode="skip_rejit_all"`。
9. 正确性判定：
   - 见下方 gate。
   - 如果 gate 不通过，保留 patch 和失败记录，但该 attempt 不进入性能分析。
10. 回到 attempt 前源码状态：
    - 保存 patch 后撤回本次 app 源码修改。
    - 不使用 git restore/reset/stash/checkout。需要反向应用时，用普通 `patch -p1 -R < source.diff` 这类非 git 方法，并人工检查 `git diff`。
11. 磁盘检查：
    - 再次运行 `df -h . /var/lib/docker 2>/dev/null || df -h .`。
    - 如果空间接近耗尽，先记录本次 result path，再清理无关旧 Docker image/cache；不要删除本次 attempt 目录和仍需分析的 `corpus/results/...`。
12. 更新 app `SUMMARY.md`：
    - attempt 状态只能是 `accepted-for-analysis`、`rejected-correctness` 或 `rejected-no-signal`。
    - 5 个 attempt 完成并写完小结后，才进入下一个 app。

## 正确性 gate

一个 attempt 必须同时通过以下 gate 才能进入性能分析：

| Gate | 通过条件 | 失败处理 |
| --- | --- | --- |
| Build | app artifact 构建成功，目标源码确实进入 artifact | `rejected-correctness` |
| Load | 真实 app 启动成功并自己加载 BPF | `rejected-correctness` |
| Workload | 所有 workload sample returncode 为 0 | `rejected-correctness` |
| Result schema | `status=ok`，`error=""`，`baseline.workloads[]` 存在，`post_rejit=null` | `rejected-correctness` |
| ABI | map key/value、event payload、tail-call key、attach point 未改变 | `rejected-correctness` |
| Coverage | 没有关闭程序、减少功能覆盖或跳过 security/policy check | `rejected-correctness` |
| Provenance | `source.diff`、命令、result path、correctness notes 完整 | 补齐后再判定 |

允许的优化：

- 删除真实不可达的冗余分支，但必须证明条件来自现有配置或 verifier-known invariant。
- 合并等价 bounds check。
- 保持 map key/value layout 不变的局部计算重排。
- 保持 helper 调用顺序语义不变的局部数据准备优化。
- 保持 packet bounds、tail-call key、event payload ABI、ringbuf/perfbuf payload layout 不变的控制流整理。

禁止的优化：

- 跳过安全检查、policy check、verifier-required bounds check 或 error handling。
- 改变 map layout、event ABI、tail-call dispatch key、program attach point 或 app-visible payload。
- 用 benchmark-only 常量替代真实 app 配置，除非 upstream app 在该 benchmark 配置下本来就是常量，且记录证明。
- 为了跑分降低功能覆盖、关闭程序、删除事件、减少被加载 BPF program。
- 引入 framework-side loader、shim、ReJIT、bpfopt 或 kinsn 依赖。

## App 顺序和最低进展

按实现风险从低到高推进：

| 顺序 | App | 原因 | 完成条件 |
| --- | --- | --- | --- |
| 1 | `katran` | BPF 文件少，hot path 明确，pktgen workload 稳定 | complete: clean baseline + 5 attempts + summary |
| 2 | `bcc/set` | 多个 libbpf-tools 小程序，编译反馈快 | complete: clean baseline + 5 attempts + summary |
| 3 | `tracee/monitor` | workload 覆盖强，但 BPF 程序和事件语义较多 | clean baseline + 5 attempts + summary |
| 4 | `cilium/agent` | datapath/tail-call/map 语义复杂，需谨慎 | clean baseline + 5 attempts + summary |
| 5 | `tetragon/observer` | 程序数量多，policy/event 语义复杂 | clean baseline + 5 attempts + summary |
| 6 | `otelcol-ebpf-profiler/profiling` | tail-call accounting 和 profiler 语义复杂 | clean baseline + 5 attempts + summary |

总目标是至少 6 个 clean-source baseline runs 和 30 个源码优化 attempts。

当前进度：

- Completed apps: `katran`, `bcc/set`, `tracee/monitor`, `cilium/agent`
- Baselines: 5 / 6
- Source optimization attempts: 24 / 30
- Next app: `tetragon/observer`

## Attempt README 模板

每个 attempt 的 `README.md` 使用以下结构：

```markdown
# <app> source-opt attempt: <slug>

- Time:
- App:
- Status: planned / accepted-for-analysis / rejected-correctness / rejected-no-signal
- Source files:
- Hypothesis:
- Expected hot path:
- Correctness argument:
- Build command:
- Run command:
- Result path:
- Follow-up:
```

`correctness.md` 使用以下结构：

```markdown
# Correctness

| Gate | Evidence | Verdict |
| --- | --- | --- |
| Build | | pass/fail |
| Load | | pass/fail |
| Workload | | pass/fail |
| Result schema | | pass/fail |
| ABI | | pass/fail |
| Coverage | | pass/fail |
| Provenance | | pass/fail |
```

## 外部分析约定

framework 内不写任何比较 summary。外部分析可以从 raw payload 计算：

- 每个 app 的 workload throughput ratio：optimized-source / clean-source。
- 每个 attempt 的 sample 分布。
- 失败率和正确性失败类别。
- 若后续需要 BPF counter 证据，应单独设计一个允许 shim/BPF stats 的实验；这不属于本文档定义的 no-shim source-opt workflow。

分析时不能跨 app 混合单位。`stress-ng` bogo ops、pktgen pps、OTEL language loop ops
只能在同一个 app、同一 workload、同一参数下做 ratio。

## 磁盘清理策略

每次 attempt 前后都检查：

```sh
df -h . /var/lib/docker 2>/dev/null || df -h .
docker system df 2>/dev/null || true
```

如果空间接近耗尽，按以下顺序处理：

1. 记录当前 attempt 的 result path 和文档路径。
2. 用 `docker image ls` 找旧 runtime image。
3. 删除确认不再需要的旧 image 或 dangling image，例如 `docker image prune -f`。
4. 清理明显无关的旧临时构建缓存。
5. 不删除当前 attempt 目录、当前 app baseline、仍需分析的 `corpus/results/...`。

不要为了省空间删除唯一能证明某个 attempt 的 raw result。

## 完成定义

本文档目标完成时应满足：

- `docs/source-opt/README.md` 本身定义了可执行流程、命令、目录、gate、app 顺序和清理策略。
- 每个 app 都有明确 baseline + 5 attempts 的完成条件。
- 所有 run 都是单 app run。
- 文档明确 `SKIP_REJIT=all` 下无 post phase、无 shim、无 kinsn module preload。
- 文档明确不 commit/push、不使用 git 命令回滚源码。
- 后续 agent 可以仅按本文档推进，不需要重新解释实验边界。
