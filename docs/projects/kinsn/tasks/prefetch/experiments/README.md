# Kinsn Prefetch Experiment Artifacts

最后更新：2026-06-02。

## 结论

本目录保存 Kinsn prefetch task 的可提交实验 artifact。它不是完整的原始运行目录镜像，
而是面向远端读者和 reviewer 的可复查结果包。

每个实验子目录至少包含：

- `report.md`：实验目的、命令、环境、问题、结果、收尾复查。
- `analysis/`：由 raw measurements 计算出的 TSV 分析结果。
- `data/run-contract.json`：本次实验的运行契约。
- `data/*.json` / `data/*.tsv`：小型 AWS instance、pricing、result-map 等复查数据。

没有提交的内容：

- AWS stdout / stderr 大日志。
- runner 原始结果目录完整副本。
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

合计：20 个实验，144 个小型 artifact 文件，约 1.2 MiB。

## 如何阅读

推荐顺序：

1. 先读 `../README.md`，理解 Kinsn prefetch 和普通替换型 kinsn 的区别。
2. 再读 `../policy-matrix.md`，理解每个 policy 的触发条件和对应 micro case。
3. 再读 `../results.md`，看按时间排序的实验结论。
4. 最后按需进入本目录下对应实验，查看 `report.md` 和 `analysis/*.tsv`。
