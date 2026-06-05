# Kinsn Prefetch Experiment Artifacts

最后更新：2026-06-05。

## 结论

本目录保存 Kinsn prefetch task 的可提交实验 artifact。它不是完整的原始运行目录镜像，
而是面向远端读者和 reviewer 的可复查结果包。

每个实验子目录至少包含：

- `report.md`：实验目的、命令、环境、问题、结果、收尾复查。
- `analysis/`：由 raw measurements 计算出的 TSV 分析结果。
- `data/run-contract.json`：本次实验的运行契约。
- `data/*.json` / `data/*.tsv`：小型 AWS instance、pricing、result-map 等复查数据。

默认不提交的内容：

- AWS stdout / stderr 大日志；如果日志较小且用于解释失败路径，可以随实验子目录提交。
- runner 原始结果目录完整副本；如果结果目录很小且用于证明 failure/success path，可以提交小型 raw copy。
- 编译产物，例如 `.o`、`.so`、`.mem`。
- 调试用大文件，例如完整 doc path dump。

这些大文件仍保存在顶层 workspace 的原始实验目录：

```text
/home/ruoji/github/bpf-opt/experiments
```

如果需要完全复现某个实验，先读对应子目录的 `report.md`，其中记录了原始绝对路径、命令和环境。

## Artifact 清单

| experiment | artifact files | 作用 |
|---|---:|---|
| `2026-05-26-arm64-prfm-prefetch-coverage-attribution` | 8 | ARM64 PRFM corpus targeted coverage / smoke。 |
| `2026-05-31-prefetch-research-micro-smoke` | 3 | 第一组 prefetch micro 本地 build smoke。 |
| `2026-05-31-prefetch-research-micro-attribution` | 9 | fixed-distance prefetch ARM64 micro attribution。 |
| `2026-05-31-prefetch-candidate-filtering-micro-attribution` | 8 | hot/sequential/large-stride/packet filtering micro attribution。 |
| `2026-06-01-prefetch-indirect-timeliness-micro-attribution` | 9 | indirect/dependent-chain/cacheline-dedup micro attribution。 |
| `2026-06-01-x86-prefetch-current-policy-micro-attribution` | 11 | x86 current-policy run；发现 runner 没有应用 pass。 |
| `2026-06-01-prefetch-micro-kernel-pass-path-fix` | 3 | micro kernel runtime pass application path fix。 |
| `2026-06-01-prefetch-policy-stack-alias-fix` | 5 | stack alias / register-offset pointer tracking fix。 |
| `2026-06-01-prefetch-map-large-working-set-attribution` | 8 | map-backed working-set attribution；暴露 raw loader map relocation 问题。 |
| `2026-06-01-prefetch-map-raw-loader-fix` | 6 | raw kinsn loader map/BTF relocation fix 和 rerun。 |
| `2026-06-01-prefetch-selector-v3-policy-smoke` | 4 | selector v3 x86/ARM64 admission smoke。 |
| `2026-06-01-prefetch-packet-first-deref-v3-attribution` | 12 | packet first-deref v3 x86/ARM64 same-LLC attribution。 |
| `2026-06-01-prefetch-profile-gate-impl` | 2 | profile-gate parser / admission Rust tests。 |
| `2026-06-01-prefetch-x86-paired-attribution` | 13 | x86 paired attribution for packet/map representatives。 |
| `2026-06-01-prefetch-x86-map-page-stride-independent-rerun` | 10 | x86 map-page-stride independent rerun。 |
| `2026-06-02-prefetch-profile-fed-map-value-attribution` | 7 | x86/ARM64 profile-fed map-value paired attribution。 |
| `2026-06-02-prefetch-profile-fed-map-value-pmu-attribution` | 5 | PMU capability smoke；当前 AWS micro 环境不能做 cache-miss attribution。 |
| `2026-06-02-prefetch-upper-bound-map-attribution` | 7 | same-iteration upper-bound map prefetch attribution。 |
| `2026-06-02-prefetch-pipeline-map-attribution` | 8 | next-iteration pipeline prefetch first stability run。 |
| `2026-06-02-prefetch-pipeline-map-independent-rerun1` | 6 | next-iteration pipeline independent rerun。 |
| `2026-06-02-prefetch-variant-degree-evidence` | 28 | hint variant ABI/native emit smoke；horizon1/2/4 和 degree paired sweep。 |
| `2026-06-02-prefetch-arm64-horizon-l1-pmu-stability` | 12 | ARM64 horizon2/horizon4 L1 long-repeat run；确认 timing/cycles 方向，默认 `t4g.small` PMU cache counters 不可用。 |
| `2026-06-03-prefetch-c7g-pmu-policy-diagnosis` | 9 | AWS ARM64 `c7g.large` PMU-backed policy diagnosis；确认 MLOP、degree1、horizon2、pipeline、spatial 有 cache-miss-drop evidence。 |
| `2026-06-04-prefetch-pf-llm-missing-policy-smoke` | 4 | 补 struct-field、mixed-policy-table、stream-of-strides 的 x86 correctness / emit smoke；不是性能结论。 |
| `2026-06-04-prefetch-pf-llm-missing-policy-arm64-attribution` | 9 | 补 struct-field、mixed-policy-table、stream-of-strides 的 ARM64 smoke 和 paired attribution；struct-field positive，mixed noise-level，stream-of-strides slowdown。 |
| `2026-06-04-prefetch-schema-and-pmu-evidence` | 13 | 完成 `map_value_policy_points` metadata schema，并用 ARM64 `c7g.large` 对 struct-field、mixed-policy-table、stream-of-strides 做 PMU-capable attribution。 |
| `2026-06-04-prefetch-corpus-default-structural-smoke` | 17 | AWS ARM64 corpus smoke；`bcc/set` attach failure，`katran` completed but default selector applied 0 sites and skipped all 224 candidates by evidence gate；config rerun verified `${BPFREJIT_BENCH_PASS_ARGS}` plumbing with empty args；diagnostics rerun exported 224 candidate rows for profile table generation. |
| `2026-06-04-prefetch-corpus-profile-fed-smoke` | 26 | AWS ARM64 `katran` profile-fed corpus smoke；真实 candidate `pc=16, reg=r0` 成功插入 1 个 prefetch，matched 225、applied 1、skipped 224、insn_delta 2；记录参数转发和远端 profile path 两个失败尝试。 |
| `2026-06-04-prefetch-corpus-multisite-profile-fed` | 13 | AWS ARM64 `katran` multi-site profile-fed corpus smoke；真实 candidate TSV 手工选出的 12 个 map-value profile points 成功插入 12 个 prefetch，matched 236、applied 12、skipped 224、insn_delta 24。 |
| `2026-06-04-prefetch-corpus-generated-profile-table` | 14 | 新增 diagnostics TSV -> profile JSON generator；AWS ARM64 `katran` generated-profile corpus smoke 成功插入 12 个 prefetch，matched 236、applied 12、skipped 224、insn_delta 24。 |
| `2026-06-04-prefetch-corpus-allapps-default-census` | 6 | AWS ARM64 all-app default structural census 尝试；被 `otelcol` app-load timeout 和 `cilium` long timeout 阻塞，中止并清理 instance；没有 corpus raw result。 |
| `2026-06-04-prefetch-corpus-selectedapps-default-census` | 13 | AWS ARM64 selected-app default structural census；`katran` 完整通过，`tracee` census 15542 个候选但 post-ReJIT shim reset，其他 app 是环境 / workload failure。 |
| `2026-06-04-prefetch-corpus-tracee-no-diagnostics-rerun` | 4 | AWS ARM64 `tracee/monitor` no-diagnostics rerun；default path matched 15542/applied 0 不变，total `bpfopt_ms` 从 308187 降到 51357，candidate diagnostics 默认关闭。 |
| `2026-06-04-prefetch-corpus-allapps-no-diagnostics-rerun` | 4 | AWS ARM64 all-app no-diagnostics rerun；suite 失败在 corpus app runnability，只有 `katran` 成功，不能作为 prefetch policy gate。 |
| `2026-06-04-prefetch-missing-performance-attribution` | 10 | 补 first-deref high-miss 和 stream-of-strides high-miss performance-attribution case；first-deref timing-negative；stream-high `c7g.medium` PMU rerun 显示 cache misses 下降但 exec/cycles 没有净收益。 |

合计：35 个实验，326 个小型 artifact 文件。完整 raw result directory 仍保存在顶层
`/home/ruoji/github/bpf-opt/experiments`。

## 如何阅读

推荐顺序：

1. 先读 `../README.md`，理解 Kinsn prefetch 和普通替换型 kinsn 的区别。
2. 再读 `../policy-matrix.md`，理解每个 policy 的触发条件和对应 micro case。
3. 再读 `../results.md`，看按时间排序的实验结论。
4. 最后按需进入本目录下对应实验，查看 `report.md` 和 `analysis/*.tsv`。
