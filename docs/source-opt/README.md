# eBPF 源码优化探索计划

Last updated: 2026-06-26

本文档是 `docs/source-opt/` 的执行手册。目标是系统性探索：在不使用
`kop`、`bpfopt`、ReJIT、shim、LD_PRELOAD 或 native-loader 的前提下，
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
| C1 | 源码重写不破坏真实 app 启动和 BPF 加载 | app `status=ok`，`error=""`，workload returncode 为 0 | complete |
| C2 | 源码重写保持 app-visible 语义 | event/map/tail-call/payload ABI 无变化；每个 attempt 的 `correctness.md` 记录 gate | complete |
| C3 | 源码重写带来可解释性能信号 | clean-source baseline run 与 optimized-source run 的 raw workload payload 已按 app 记录 | complete |

## 强制边界

- 只允许修改 app 自己的 eBPF 源码或直接 eBPF 头文件。
- 真实 app binary 仍按现有 runner 启动，并由 app 自己加载 BPF 程序。
- 不直接用 framework、bpftool、libbpf 小工具或自定义 loader 加载 `.bpf.o`。
- 不使用 `BPF_PROG_REJIT`、`bpfopt --pass ...`、`runner/config/passes/*`、
  shim socket、LD_PRELOAD、native-loader 或 kop module path。
- framework 只保留 raw workload payload；任何 ratio、平均值、geomean、
  wins/losses、summary 都在外部分析脚本中计算。
- 不降低 app 功能覆盖，不删除被加载 BPF program，不绕开 policy/security check。
- 不运行 `git add`、`git commit`、`git push`。
- 不使用 `git restore`、`git reset`、`git checkout --`、`git stash`、
  `git revert` 等会破坏或隐藏工作区状态的命令。

## 当前运行语义

源码优化评估使用 `SKIP_REJIT=all`。该模式在当前代码中有三个关键效果：

- 不注入 shim/LD_PRELOAD。
- 不加载 kop modules。
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
| `phase2/20260625-164917-udp-flow-migration-require-dst` | pktgen_total_pps mean=3305186; errors=648715246; accepted-for-analysis | `3299495, 3294334, 3321729` | +7.97% | `corpus/results/x86_kvm_corpus_20260625_235638_664542` |
| `phase2/20260625-172006-lru-miss-proto-compare` | pktgen_total_pps mean=3288342; errors=1647406492; completed-not-stacked | `3267504, 3316271, 3281251` | +7.42% | `corpus/results/x86_kvm_corpus_20260626_002120_778242` |
| `phase2/20260625-182615-cache-vip-metadata` | pktgen_total_pps mean=3348905; errors=1008452024; accepted-for-analysis | `3390361, 3336180, 3320175` | +9.40% | `corpus/results/x86_kvm_corpus_20260626_004646_185930` |
| `phase2/20260625-180602-cache-vip-plus-lru-proto-compare` | pktgen_total_pps mean=3275764; errors=1659713484; completed-not-stacked | `3272779, 3268211, 3286301` | +7.01% | `corpus/results/x86_kvm_corpus_20260626_011245_701549` |
| `phase2/20260625-183134-nonnull-lru-map` | pktgen_total_pps mean=3301431; errors=1600708022; completed-not-stacked | `3317221, 3295753, 3291320` | +7.85% | `corpus/results/x86_kvm_corpus_20260626_013906_982440` |
| `phase3/20260626-043917-phase3-thoff-parser-reuse` | pktgen_total_pps mean=3338745; errors=893490992; completed-not-stacked | `3337569, 3357814, 3320853` | +9.07% | `corpus/results/x86_kvm_corpus_20260626_114838_879478` |
| `phase3/20260626-050412-phase3-quic-v0-cid-fast-reject` | pktgen_total_pps mean=3320793; errors=716551110; completed-not-stacked | `3276898, 3371790, 3313690` | +8.48% | `corpus/results/x86_kvm_corpus_20260626_121345_246104` |
| `phase3/20260626-052931-phase3-unlikely-hot-map-misses` | pktgen_total_pps mean=3349874; errors=643973416; accepted-for-analysis | `3379459, 3355767, 3314396` | +9.43% | `corpus/results/x86_kvm_corpus_20260626_123820_861697` |
| `phase3/20260626-055442-phase3-vip-flag-branch-layout` | pktgen_total_pps mean=3414266; errors=794306103; accepted-for-analysis | `3406881, 3418862, 3417054` | +11.53% | `corpus/results/x86_kvm_corpus_20260626_130130_983141` |
| `phase3/20260626-061622-phase3-quic-hot-branch-layout` | pktgen_total_pps mean=3277602; errors=670177168; completed-not-stacked | `3275164, 3299603, 3258040` | +7.07% | `corpus/results/x86_kvm_corpus_20260626_132449_671728` |

### `bcc/set`

| Run | Primary metric | Samples | vs baseline | Result |
| --- | ---: | --- | ---: | --- |
| `baseline` | stress_ng_sum_bogo_ops_s mean=710465 | `712551, 710948, 707896` | n/a | `corpus/results/x86_kvm_corpus_20260625_102432_554290` |
| `20260625-033814-opensnoop-reuse-pidtgid` | stress_ng_sum_bogo_ops_s mean=710090 | `708989, 711064, 710216` | -0.05% | `corpus/results/x86_kvm_corpus_20260625_104426_414018` |
| `20260625-035755-tcpconnect-lazy-uid-filter` | stress_ng_sum_bogo_ops_s mean=704178 | `701784, 704943, 705807` | -0.88% | `corpus/results/x86_kvm_corpus_20260625_110418_916430` |
| `20260625-041821-tcplife-cache-newstate` | stress_ng_sum_bogo_ops_s mean=704720 | `704690, 704389, 705081` | -0.81% | `corpus/results/x86_kvm_corpus_20260625_112427_430171` |
| `20260625-043750-syscount-interrupt-fast-return` | stress_ng_sum_bogo_ops_s mean=711554 | `709915, 711686, 713061` | +0.15% | `corpus/results/x86_kvm_corpus_20260625_114437_519205` |
| `20260625-045812-runqlat-skip-idle-tgid-read` | stress_ng_sum_bogo_ops_s mean=705171 | `704250, 704247, 707015` | -0.75% | `corpus/results/x86_kvm_corpus_20260625_120517_651286` |
| `phase2/20260625-185708-capable-fexit-syscount-base` | stress_ng_sum_bogo_ops_s mean=718235; accepted-for-analysis | `719939, 713743, 721022` | +1.09% | `corpus/results/x86_kvm_corpus_20260626_020646_300498` |
| `phase2/20260625-192229-tcpconnect-fexit-stack` | stress_ng_sum_bogo_ops_s mean=717722; accepted-for-analysis; not selected as next base | `716964, 718507, 717694` | +1.02% | `corpus/results/x86_kvm_corpus_20260626_023049_621850` |
| `phase2/20260625-194654-syscount-raw-tracepoint` | stress_ng_sum_bogo_ops_s mean=724628; accepted-for-analysis; selected as next base | `727466, 720947, 725471` | +1.99% | `corpus/results/x86_kvm_corpus_20260626_025631_917158` |
| `phase2/20260625-201115-syscount-latency-specialized-exit` | stress_ng_sum_bogo_ops_s mean=715349; accepted-for-analysis; not selected as next base | `713487, 715830, 716731` | +0.69% | `corpus/results/x86_kvm_corpus_20260626_031853_909472` |
| `phase2/20260625-203413-raw-syscount-tcpconnect-fexit` | stress_ng_sum_bogo_ops_s mean=729628; accepted-for-analysis; selected as bcc/set phase2 best | `729898, 726762, 732224` | +2.70% | `corpus/results/x86_kvm_corpus_20260626_034309_094312` |
| `phase3/20260626-064041-phase3-tcpconnect-default-fastpath` | stress_ng_sum_bogo_ops_s mean=730977; accepted-for-analysis; selected as current bcc/set phase3 base | `730828, 727856, 734246` | +2.89% | `corpus/results/x86_kvm_corpus_20260626_135003_717963` |
| `phase3/20260626-070554-phase3-syscount-default-filter-fastpath` | stress_ng_sum_bogo_ops_s mean=733113; accepted-for-analysis; selected as current bcc/set phase3 base | `733995, 732654, 732689` | +3.19% | `corpus/results/x86_kvm_corpus_20260626_141358_076518` |
| `phase3/20260626-072828-phase3-capable-default-branch-layout` | stress_ng_sum_bogo_ops_s mean=727184; completed-not-stacked | `725965, 726577, 729010` | +2.35% | `corpus/results/x86_kvm_corpus_20260626_143534_405266` |
| `phase3/20260626-075220-phase3-syscount-key-width-cleanup` | stress_ng_sum_bogo_ops_s mean=794393; accepted-for-analysis; selected as current bcc/set phase3 base | `794399, 794426, 794353` | +11.81% | `corpus/results/x86_kvm_corpus_20260626_150154_266900` |
| `phase3/20260626-081655-phase3-tcpconnect-default-event-fastpath` | stress_ng_sum_bogo_ops_s mean=789683; completed-not-stacked | `790657, 788288, 790104` | +11.15% | `corpus/results/x86_kvm_corpus_20260626_152354_967827` |

### `tracee/monitor`

| Run | Primary metric | Samples | vs baseline | Result |
| --- | ---: | --- | ---: | --- |
| `baseline` | stress_ng_sum_bogo_ops_s mean=460865 | `462328, 456918, 463350` | n/a | `corpus/results/x86_kvm_corpus_20260625_122431_943915` |
| `20260625-053834-sys-exit-reuse-saved-ret` | stress_ng_sum_bogo_ops_s mean=458984 | `458065, 459824, 459063` | -0.41% | `corpus/results/x86_kvm_corpus_20260625_124558_225233` |
| `20260625-060003-cache-sys-enter-compat` | stress_ng_sum_bogo_ops_s mean=459817 | `461155, 459142, 459152` | -0.23% | `corpus/results/x86_kvm_corpus_20260625_130746_945964` |
| `20260625-062113-defer-sys-exit-ret-read` | stress_ng_sum_bogo_ops_s mean=460218 | `458576, 460270, 461807` | -0.14% | `corpus/results/x86_kvm_corpus_20260625_132825_862375` |
| `20260625-064212-socket-dup-late-args` | stress_ng_sum_bogo_ops_s mean=458474 | `460912, 456147, 458361` | -0.52% | `corpus/results/x86_kvm_corpus_20260625_134931_275984` |
| `20260625-070258-socket-dup-unix-else` | stress_ng_sum_bogo_ops_s mean=454296 | `454215, 454954, 453718` | -1.43% | `corpus/results/x86_kvm_corpus_20260625_141005_857825` |
| `phase2/20260625-205820-cap-capable-fentry` | rejected-correctness: Tracee failed BPF load; fentry program returned unknown helper result instead of 0 | `N/A` | N/A | `corpus/results/x86_kvm_corpus_20260626_040613_380312` |
| `phase2/20260625-210832-cap-capable-fentry-return0` | stress_ng_sum_bogo_ops_s mean=462359; accepted-for-analysis | `466968, 460401, 459707` | +0.32% | `corpus/results/x86_kvm_corpus_20260626_041555_482043` |
| `phase2/20260625-213013-phase2-cap-fentry-early-noaudit` | stress_ng_sum_bogo_ops_s mean=453930; rejected-no-signal; not selected as next base | `453680, 454459, 453651` | -1.50% | `corpus/results/x86_kvm_corpus_20260626_043813_884875` |
| `phase2/20260625-215524-phase2-simple-value-args-fastpath` | rejected-correctness: Tracee failed BPF load; verifier rejected `sys_exit_submit` after simple-value arg fast path | `N/A` | N/A | `corpus/results/x86_kvm_corpus_20260626_050351_616916` |
| `phase2/20260625-220744-phase2-hot-syscall-arg-count` | stress_ng_sum_bogo_ops_s mean=456957; rejected-no-signal; not selected as next base | `453757, 460873, 456241` | -0.85% | `corpus/results/x86_kvm_corpus_20260626_051548_824007` |
| `phase3/20260626-084029-phase3-no-scope-filter-fastpath` | stress_ng_sum_bogo_ops_s mean=462517; completed-not-stacked | `461582, 464345, 461625` | +0.36% | `corpus/results/x86_kvm_corpus_20260626_155038_747634` |
| `phase3/20260626-090841-phase3-prctl-fentry` | stress_ng_sum_bogo_ops_s mean=464810; accepted-for-analysis; selected as current tracee phase3 base | `462950, 465355, 466125` | +0.86% | `corpus/results/x86_kvm_corpus_20260626_161621_526914` |
| `phase3/20260626-093333-phase3-hot-syscall-arg-serializer` | stress_ng_sum_bogo_ops_s mean=457589; completed-not-stacked | `458895, 456475, 457398` | -0.71% | `corpus/results/x86_kvm_corpus_20260626_164248_792753` |
| `phase3/20260626-095936-phase3-value-args-first` | stress_ng_sum_bogo_ops_s mean=450374; completed-not-stacked | `450246, 448766, 452111` | -2.28% | `corpus/results/x86_kvm_corpus_20260626_170733_776031` |
| `phase3/20260626-102417-phase3-commit-creds-fentry` | stress_ng_sum_bogo_ops_s mean=461933; completed-not-stacked | `460381, 463013, 462406` | +0.23% | `corpus/results/x86_kvm_corpus_20260626_173247_019570` |

### `cilium/agent`

| Run | Primary metric | Samples | vs baseline | Result |
| --- | ---: | --- | ---: | --- |
| `baseline` | pktgen_total_pps mean=1488103 | `1491361, 1493893, 1479055` | n/a | `corpus/results/x86_kvm_corpus_20260625_143038_806522` |
| `20260625-074510-local-delivery-redirect-peer` | pktgen_total_pps mean=1503521 | `1499183, 1511544, 1499836` | +1.04% | `corpus/results/x86_kvm_corpus_20260625_145141_817976` |
| `20260625-080510-from-container-error-unlikely` | pktgen_total_pps mean=1494040 | `1492844, 1485606, 1503670` | +0.40% | `corpus/results/x86_kvm_corpus_20260625_151130_130358` |
| `20260625-082528-cil-lxc-policy-error-unlikely` | pktgen_total_pps mean=1509617 | `1517661, 1501746, 1509443` | +1.45% | `corpus/results/x86_kvm_corpus_20260625_153206_021422` |
| `20260625-084516-cil-to-container-error-unlikely` | pktgen_total_pps mean=1510065 | `1509682, 1507833, 1512679` | +1.48% | `corpus/results/x86_kvm_corpus_20260625_155126_330125` |
| `20260625-090437-tail-ipv4-to-endpoint-revalidate-unlikely` | pktgen_total_pps mean=1672124 | `1668711, 1666812, 1680849` | +12.37% | `corpus/results/x86_kvm_corpus_20260625_161125_111575` |
| `phase2/20260625-223000-phase2-stack-first-round-fastpaths` | pktgen_total_pps mean=1617479; errors=0; accepted-for-analysis; not selected as next base | `1595444, 1626858, 1630134` | +8.69% | `corpus/results/x86_kvm_corpus_20260626_054657_483125` |
| `phase2/20260625-230230-phase2-tail-ipv4-policy-ok-fastpath` | pktgen_total_pps mean=1609694; errors=0; accepted-for-analysis; not selected as next base | `1635252, 1608005, 1585824` | +8.17% | `corpus/results/x86_kvm_corpus_20260626_061027_069307` |
| `phase2/20260625-232531-phase2-egress-policy-verdict-fastpath` | pktgen_total_pps mean=1476514; errors=0; accepted-for-analysis; rejected-no-signal; not selected as next base | `1473623, 1488389, 1467531` | -0.78% | `corpus/results/x86_kvm_corpus_20260626_063507_838342` |
| `phase2/20260625-235119-phase2-lazy-ingress-fraginfo` | pktgen_total_pps mean=1456652; errors=0; accepted-for-analysis; rejected-no-signal; not selected as next base | `1460702, 1462853, 1446400` | -2.11% | `corpus/results/x86_kvm_corpus_20260626_065929_399049` |
| `phase2/20260626-001346-phase2-best-plus-local-delivery` | pktgen_total_pps mean=1528055; errors=0; accepted-for-analysis; not selected as next base | `1534942, 1516759, 1532465` | +2.68% | `corpus/results/x86_kvm_corpus_20260626_072138_036296` |
| `phase3/20260626-105321-phase3-reserved-identity-cold` | pktgen_total_pps mean=1672664; errors=0; accepted-for-analysis; selected as current cilium phase3 base; marginal +0.03% vs previous best | `1683410, 1662935, 1671646` | +12.40% | `corpus/results/x86_kvm_corpus_20260626_180150_613607` |
| `phase3/20260626-111706-phase3-lazy-policy-verdict-payload` | pktgen_total_pps mean=1572938; errors=0; completed-not-stacked | `1554963, 1566899, 1596952` | +5.70% | `corpus/results/x86_kvm_corpus_20260626_182603_784560` |
| `phase3/20260626-114554-phase3-policy-established-fastpath` | pktgen_total_pps mean=1569838; errors=0; completed-not-stacked | `1579206, 1566724, 1563584` | +5.49% | `corpus/results/x86_kvm_corpus_20260626_185324_568478` |
| `phase3/20260626-120930-phase3-cil-to-container-error-unlikely-stack` | pktgen_total_pps mean=1686212; errors=0; accepted-for-analysis; selected as current cilium phase3 base; +0.81% vs prior Cilium phase3 base | `1688102, 1686224, 1684311` | +13.31% | `corpus/results/x86_kvm_corpus_20260626_191637_695574` |
| `phase3/20260626-123126-phase3-policy-error-unlikely-stack` | pktgen_total_pps mean=1714120; errors=0; accepted-for-analysis; selected as current cilium phase3 best; +1.66% vs prior Cilium phase3 base | `1713045, 1718508, 1710806` | +15.19% | `corpus/results/x86_kvm_corpus_20260626_193753_200824` |

### `tetragon/observer`

| Run | Primary metric | Samples | vs baseline | Result |
| --- | ---: | --- | ---: | --- |
| `baseline` | stress_ng_sum_bogo_ops_s mean=358681 | `362190, 355981, 357871` | n/a | `corpus/results/x86_kvm_corpus_20260625_163302_015551` |
| `20260625-094557-sparse-selector-active-clear` | stress_ng_sum_bogo_ops_s mean=356619 | `362792, 351299, 355765` | -0.57% | `corpus/results/x86_kvm_corpus_20260625_165241_915913` |
| `20260625-100649-filter-args-active-fastpath` | stress_ng_sum_bogo_ops_s mean=355810 | `358593, 353455, 355383` | -0.80% | `corpus/results/x86_kvm_corpus_20260625_171339_967034` |
| `20260625-102800-lazy-ns-cap-selector-state` | stress_ng_sum_bogo_ops_s mean=387898 | `392895, 386207, 384593` | +8.15% | `corpus/results/x86_kvm_corpus_20260625_173550_665242` |
| `20260625-105314-lazy-ns-cap-conditional-cap-sparse` | stress_ng_sum_bogo_ops_s mean=386271 | `391844, 381971, 384998` | +7.69% | `corpus/results/x86_kvm_corpus_20260625_175958_060141` |
| `20260625-111613-lazy-ns-cap-skip-empty-namespace-loop` | stress_ng_sum_bogo_ops_s mean=389565 | `391278, 386987, 390431` | +8.61% | `corpus/results/x86_kvm_corpus_20260625_182312_224669` |
| `phase2/20260626-004351-phase2-tracepoint-nop-arg-fastpath` | stress_ng_sum_bogo_ops_s mean=391151; accepted-for-analysis; selected as current tetragon phase2 best | `399794, 385719, 387940` | +9.05% | `corpus/results/x86_kvm_corpus_20260626_075102_935489` |
| `phase2/20260626-010736-phase2-defer-selector-active-clear` | stress_ng_sum_bogo_ops_s mean=390959; accepted-for-analysis; not selected as next base | `391940, 385567, 395369` | +9.00% | `corpus/results/x86_kvm_corpus_20260626_081407_505208` |
| `phase2/20260626-012946-phase2-filter-args-no-selector-fastpath` | stress_ng_sum_bogo_ops_s mean=390359; accepted-for-analysis; not selected as next base | `397404, 388898, 384775` | +8.83% | `corpus/results/x86_kvm_corpus_20260626_083643_226335` |
| `phase2/20260626-015135-phase2-tracepoint-no-selector-filter-bypass` | stress_ng_sum_bogo_ops_s mean=388975; accepted-for-analysis; not selected as next base | `390527, 390759, 385637` | +8.45% | `corpus/results/x86_kvm_corpus_20260626_085918_851913` |
| `phase2/20260626-021402-phase2-tracepoint-curr-only-no-selector-bypass` | stress_ng_sum_bogo_ops_s mean=391962; accepted-for-analysis; selected as tetragon phase2 best | `393846, 395075, 386967` | +9.28% | `corpus/results/x86_kvm_corpus_20260626_092152_089522` |
| `phase3/20260626-125641-phase3-tracepoint-sparse-active-clear` | stress_ng_sum_bogo_ops_s mean=393050; accepted-for-analysis; selected as current tetragon phase3 base; +0.28% vs phase2 best | `394428, 393844, 390877` | +9.58% | `corpus/results/x86_kvm_corpus_20260626_200430_726187` |
| `phase3/20260626-132055-phase3-tracepoint-no-selector-config-flag` | stress_ng_sum_bogo_ops_s mean=400249; accepted-for-analysis; selected as current tetragon phase3 base; +1.83% vs prior phase3 base | `403732, 400561, 396453` | +11.59% | `corpus/results/x86_kvm_corpus_20260626_202805_644441` |
| `phase3/20260626-134335-phase3-tracepoint-defer-pass-init` | stress_ng_sum_bogo_ops_s mean=392557; accepted-for-analysis; completed-not-stacked; -1.92% vs attempt 2 | `400953, 388615, 388104` | +9.44% | `corpus/results/x86_kvm_corpus_20260626_205027_125596` |
| `phase3/20260626-140504-phase3-tracepoint-fallback-state-split` | stress_ng_sum_bogo_ops_s mean=387226; accepted-for-analysis; completed-not-stacked; -3.25% vs attempt 2 | `391814, 382985, 386879` | +7.96% | `corpus/results/x86_kvm_corpus_20260626_211133_416524` |
| `phase3/20260626-142719-phase3-process-stage-config-cache` | stress_ng_sum_bogo_ops_s mean=398133; accepted-for-analysis; completed-not-stacked; -0.53% vs attempt 2 | `401171, 397862, 395365` | +11.00% | `corpus/results/x86_kvm_corpus_20260626_213400_944958` |

### `otelcol-ebpf-profiler/profiling`

| Run | Primary metric | Samples | vs baseline | Result |
| --- | ---: | --- | ---: | --- |
| `baseline` | language_ops_total mean=19644780415 | `19476891866, 19704797451, 19752651928` | n/a | `corpus/results/x86_kvm_corpus_20260625_184535_486633` |
| `20260625-120059-defer-kernel-stackid-unmapped-pid` | language_ops_total mean=19631015807; rejected-correctness: artifact provenance failed | `19482699802, 19832870505, 19577477114` | -0.07% | `corpus/results/x86_kvm_corpus_20260625_190706_743922` |
| `20260625-122046-defer-kernel-stackid-unmapped-pid-rebuilt-ebpf` | language_ops_total mean=19644068683; rejected-no-signal | `19898566747, 19709048452, 19324590849` | -0.00% | `corpus/results/x86_kvm_corpus_20260625_192715_058308` |
| `20260625-124147-tail-call-use-existing-record` | language_ops_total mean=19358366012; rejected-no-signal | `19402588695, 19278089079, 19394420261` | -1.46% | `corpus/results/x86_kvm_corpus_20260625_194845_959410` |
| `20260625-130417-trace-send-size-direct` | language_ops_total mean=19634728466; rejected-no-signal | `19889012769, 19180704492, 19834468137` | -0.05% | `corpus/results/x86_kvm_corpus_20260625_201102_658698` |
| `20260625-132530-native-frames-per-program-5` | language_ops_total mean=19611239252; rejected-no-signal | `19226116826, 20279757143, 19327843786` | -0.17% | `corpus/results/x86_kvm_corpus_20260625_203203_222972` |
| `20260625-134604-lazy-clear-custom-labels` | language_ops_total mean=19480337627; rejected-no-signal | `19345351817, 19739934685, 19355726380` | -0.84% | `corpus/results/x86_kvm_corpus_20260625_205249_386525` |
| `phase2/20260626-024357-phase2-defer-comm-stack-unmapped-pid` | language_ops_total mean=19481366793; rejected-no-signal | `19676128056, 19509969254, 19258003069` | -0.83% | `corpus/results/x86_kvm_corpus_20260626_095211_287090` |
| `phase2/20260626-030730-phase2-early-drop-error-only` | language_ops_total mean=19582008878; rejected-no-signal | `19879363031, 19331939856, 19534723746` | -0.32% | `corpus/results/x86_kvm_corpus_20260626_101543_422474` |
| `phase2/20260626-032939-phase2-native-frames-per-program-8` | language_ops_total mean=19526940261; rejected-no-signal | `19705666680, 19244754469, 19630399634` | -0.60% | `corpus/results/x86_kvm_corpus_20260626_103605_569628` |
| `phase2/20260626-035305-phase2-single-delta-reuse` | language_ops_total mean=19575112832; rejected-no-signal | `19658284979, 19486494323, 19580559194` | -0.35% | `corpus/results/x86_kvm_corpus_20260626_110000_678727` |
| `phase2/20260626-041515-phase2-batch-php-frame-metric` | language_ops_total mean=19508075671; rejected-no-signal | `19462147885, 19814623616, 19247455513` | -0.70% | `corpus/results/x86_kvm_corpus_20260626_112227_995529` |
| `phase3/20260626-145000-phase3-native-unwind-error-unlikely` | language_ops_total mean=19365498890; rejected-no-signal; branch hints shrank `unwind_native` by 12 instructions but regressed throughput | `19583174016, 19234194165, 19279128490` | -1.42% | `corpus/results/x86_kvm_corpus_20260626_215832_429743` |
| `phase3/20260626-151552-phase3-defer-pid-exists-lpm-lookup` | language_ops_total mean=19481636379; rejected-no-signal; deferred dummy PID LPM lookup until mapping failure but throughput still regressed | `19585524873, 19436580480, 19422803783` | -0.83% | `corpus/results/x86_kvm_corpus_20260626_222221_639047` |

## App 源码、构建和加载路径

每次 attempt 必须先确认目标 app 的源码修改会经过真实 app loader。

| App | 主要 eBPF 源码 | 现有构建入口 | runtime artifact/load path | 注意 |
| --- | --- | --- | --- | --- |
| `katran` | `vendor/repos/katran/katran/lib/bpf/*.c` | `make -C vendor katran-x86` 或 `make corpus` 依赖 | `vendor/build/x86/katran/bpf/*.bpf.o` -> `/artifacts/user/repo-artifacts/x86_64/katran/bpf/`；runner 将 object 交给真实 katran server | 优先从 `balancer.c` hot path 开始 |
| `bcc/set` | `vendor/repos/bcc/libbpf-tools/*.bpf.c` | `make -C vendor bcc-x86` 或 `make corpus` 依赖 | `vendor/build/x86/bcc/bin/*` -> `/usr/local/bin/`；真实 libbpf-tools 自加载 BPF | 每个 tool 是独立 app 子进程，避免一次改多个 tool |
| `tracee/monitor` | `vendor/repos/tracee/pkg/ebpf/c/*.bpf.c` 和 `lsmsupport/*.bpf.c` | `make -C vendor tracee-x86` 或 `make corpus` 依赖 | BPF artifacts embedded/packaged 到真实 `tracee` binary path | 改 event payload 前必须证明 ABI 不变 |
| `cilium/agent` | `vendor/repos/cilium/bpf/**/*.c` 和 `*.h` | `make -C vendor cilium-x86` 或 `make corpus` 依赖 | runtime image 复制 `vendor/repos/cilium/bpf/` 到 `/var/lib/cilium/bpf/`，真实 `cilium-agent` 使用该 datapath | tail-call/map/policy 语义复杂，后置执行 |
| `tetragon/observer` | `vendor/repos/tetragon/bpf/**/*.c` 和 `*.h` | `make -C vendor tetragon-x86` 或 `make corpus` 依赖 | `vendor/build/x86/tetragon/*` -> `/artifacts/tetragon/`，runner 用 `--bpf-lib` 指向该目录 | 程序多，先做单一 policy/hot helper 级别改动 |
| `otelcol-ebpf-profiler/profiling` | `vendor/repos/opentelemetry-ebpf-profiler/support/ebpf/*.ebpf.c` | 先 `make -C vendor/repos/opentelemetry-ebpf-profiler/support/ebpf TARGET_ARCH=amd64` 重建 embedded BPF，再用 `make corpus` 正式运行 | `otelcol-ebpf-profiler` binary/artifacts 由 OCB 构建，真实 collector 加载 profiler BPF | tail-called programs 自身 `run_cnt=0`；仅改源文件但不重建 `tracer.ebpf.amd64` 不能算有效 attempt |

## 标准命令

正式 run 参数对齐 `docs/eval_kop.md` 的 app-by-app corpus 设置，但禁用 ReJIT
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
- `diagnostics.md`：第二轮起每次 attempt 记录修改前后的关键 BPF instruction count、
  objdump/分支布局观察、map/helper hot path 依据；诊断只辅助选点，不写入
  framework summary。

## 第二轮 stacked tuning

第一轮完成后继续第二轮，每个 app 再做 5 次源码优化 attempt，总计再增加
30 次。第二轮目标是把单 app 最佳提升推到 10-20%，允许在同一 app 内叠加
此前 correctness 通过且有正向性能信号的源码优化；没有正向信号的 patch
不得作为叠加 base。

第二轮执行规则：

- 仍然一次只跑一个 app，按 `katran`、`bcc/set`、`tracee/monitor`、
  `cilium/agent`、`tetragon/observer`、`otelcol-ebpf-profiler/profiling`
  顺序推进。
- 每个 app 做 5 次 phase2 attempt；当前 app 未完成前不进入下一个 app。
- attempt 可以是 stacked patch，但 `source.diff` 必须保存本次正式 run 使用的
  完整源码差异。
- 每次 attempt 前先做诊断：对当前 base 和候选 patch 看关键 BPF program 的
  instruction count、objdump 分支布局、map lookup/helper 调用位置。
- 诊断可以使用 `llvm-objdump`、`bpftool` 的离线 object 检查或构建日志，但
  正式性能仍只来自 `SKIP_REJIT=all ... make corpus` 的 raw result。
- 仍然禁止修改 workload、runner、framework、pass config、shim、LD_PRELOAD、
  ReJIT、bpfopt 或 kop 路径。
- 每次 run 后仍然恢复 app 源码和生成 artifact 到 attempt 前状态。
- 如果 30 次 phase2 全部完成但没有达到 10-20% 目标，继续从 `katran` 开始下一轮
  30 次，直到目标达成或明确记录阻塞原因。

第二轮当前进度：

- Completed phase2 apps: `katran`, `bcc/set`, `tracee/monitor`,
  `cilium/agent`, `tetragon/observer`, `otelcol-ebpf-profiler/profiling`
- Phase2 source optimization attempts: 30 / 30
- Current phase2 app: none; required phase2 sweep complete
- Current phase2 result: OTEL phase2 attempts 1-5 all passed correctness but
  regressed throughput (`-0.83%`, `-0.32%`, `-0.60%`, `-0.35%`, `-0.70%`).
  Do not stack them. The best overall source-opt signal remains
  `cilium/agent` first-round `tail-ipv4-to-endpoint-revalidate-unlikely`
  at `+12.37%`; strongest phase2 signals were `katran` `+9.40%` and
  `tetragon/observer` `+9.28%`.

## 第三轮 stacked tuning

第三轮继续增加 30 次源码优化 attempt：每个 app 再做 5 次。目标仍是把
单 app 最佳提升推到 10-20%，但不能只集中在已有高收益 app；必须按同样顺序
覆盖全部 6 个 app。第三轮允许从每个 app 已有最佳 correctness-passing patch
作为 base 继续叠加，前提是新的 `source.diff` 保存正式 run 使用的完整源码差异。

第三轮选点要求：

- 先诊断再改源码；每个 attempt 的 `diagnostics.md` 记录当前 base、候选 patch
  的 instruction count、关键程序 objdump 或 map/helper 调用观察。
- 优先关注 map lookup、helper 调用、per-packet stats 更新、分支布局和 hot-path
  数据重用，而不是继续只做冷路径微调。
- 仍然一次只跑一个 app，当前 app 的 5 次 phase3 attempt 完成前不进入下一个 app。
- 正式性能仍只来自 `SKIP_REJIT=all ... make corpus`，不写 framework-side summary。
- 每次 run 后恢复 app 源码和生成 artifact 到 attempt 前状态。

第三轮当前进度：

- Completed phase3 apps: `katran`, `bcc/set`, `tracee/monitor`,
  `cilium/agent`, `tetragon/observer`
- Phase3 source optimization attempts: 27 / 30
- Current phase3 app: `otelcol-ebpf-profiler/profiling` (paused after attempt 2)
- Current phase3 result: tetragon/observer attempt 2
  (`phase3-tracepoint-no-selector-config-flag`) passed correctness and measured
  `400249` stress_ng_sum_bogo_ops_s (`+11.59%` vs clean, `+1.83%` vs previous
  phase3 base). Attempt 3 passed correctness at `392557` (`+9.44%` vs clean,
  `-1.92%` vs attempt 2), despite shrinking `generic_tracepoint_event` from
  `0x66b8` to `0x65f8`; do not stack it. Attempt 4 passed correctness at
  `387226` (`+7.96%` vs clean, `-3.25%` vs attempt 2), despite keeping
  `generic_tracepoint_event` smaller than attempt 2 at `0x6600`; do not stack
  it. Attempt 5 passed correctness at `398133` (`+11.00%` vs clean,
  `-0.53%` vs attempt 2); process-stage config pointer reuse shrank
  `generic_tracepoint_process_event` from `0x67c8` to `0x66d0` but did not
  beat attempt 2, so do not stack it. Attempt 2 reaches the 10% target for
  Tetragon by moving the no-selector decision from a per-event `filter_map`
  lookup into load-time `event_config.flags`; Tetragon phase3 is complete and
  best remains attempt 2. Earlier bcc/set attempt 4
  (`phase3-syscount-key-width-cleanup`) passed correctness and measured
  `794393` stress_ng_sum_bogo_ops_s (`+11.81%` vs clean, `+8.36%` vs bcc/set
  phase3 attempt 2). This reaches the 10% target for bcc/set. Attempt 5 passed
  correctness at `789683` (`+11.15%` vs clean) but regressed by `0.59%` vs
  attempt 4, so do not stack it. Tracee phase3 attempt 1 passed correctness at
  `462517` (`+0.36%` vs clean, `+0.03%` vs phase2 best) but is effectively
  flat and should not be stacked. Tracee phase3 attempt 2 passed correctness at
  `464810` (`+0.86%` vs clean, `+0.53%` vs phase2 best) and remains the current
  tracee phase3 base. Tracee phase3 attempt 3 passed correctness at `457589`
  (`-0.71%` vs clean, `-1.55%` vs attempt 2), but the large hot syscall
  serializer expanded `sys_exit_submit` from `0x4fc8` to `0x60a0`, so do not
  stack it. Tracee phase3 attempt 4 passed correctness at `450374`
  (`-2.28%` vs clean, `-3.11%` vs attempt 2); even the small value-arg branch
  reorder in `save_args_to_submit_buf()` regressed, so do not stack it. Tracee
  phase3 attempt 5 passed correctness at `461933` (`+0.23%` vs clean, `-0.62%`
  vs attempt 2); `commit_creds` fentry is functionally safe but not hot enough,
  so do not stack it. Tracee phase3 is complete; best tracee phase3 result
  remains attempt 2 at `464810` (`+0.86%` vs clean). Cilium phase3 attempt 1
  passed correctness at `1672664` pktgen_total_pps (`+12.40%` vs clean,
  `+0.03%` vs previous Cilium best) and becomes the current Cilium phase3 base,
  but the margin is tiny. Cilium phase3 attempt 2 passed correctness at
  `1572938` (`+5.70%` vs clean, `-5.96%` vs current Cilium base); lazy policy
  verdict payload setup reduced offline `tc/tail` section size but hurt
  workload throughput, so do not stack it. Cilium phase3 attempt 3 passed
  correctness at `1569838` (`+5.49%` vs clean, `-6.15%` vs current Cilium
  base); explicit established+allow policy fast path also regressed, so do not
  stack it. Cilium phase3 attempt 4 passed correctness at `1686212` (`+13.31%`
  vs clean, `+0.81%` vs prior Cilium phase3 base); stacking the first-round
  positive `cil_to_container()` error-path hints with the reserved-identity base
  composes, so it becomes the current Cilium phase3 base. Cilium phase3 attempt
  5 passed correctness at `1714120` (`+15.19%` vs clean, `+1.66%` vs attempt
  4); stacking the first-round positive `cil_lxc_policy()` error-path hints
  composes again. Cilium phase3 is complete; best Cilium source-opt result is
  `20260626-123126-phase3-policy-error-unlikely-stack`. OTEL phase3 attempt 1
  passed correctness at `19365498890` language_ops_total (`-1.42%` vs clean);
  native-unwind branch hints shrank `unwind_native` by 12 instructions but
  regressed throughput, so do not stack it. OTEL phase3 attempt 2 passed
  correctness at `19481636379` language_ops_total (`-0.83%` vs clean);
  deferring the dummy PID LPM lookup until mapping failure reduced
  `native_tracer_entry` from 1322 to 1318 instructions and total artifact
  size from 123833 to 123813 instructions, but still regressed workload
  throughput, so do not stack it.
- Current phase3 target: stopped after OTEL phase3 attempt 2 per user request.
  Do not start attempts 3-5 or any new benchmark run unless explicitly resumed.

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
- 引入 framework-side loader、shim、ReJIT、bpfopt 或 kop 依赖。

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

第一轮当前进度：

- Completed apps: `katran`, `bcc/set`, `tracee/monitor`, `cilium/agent`, `tetragon/observer`, `otelcol-ebpf-profiler/profiling`
- Baselines: 6 / 6
- Source optimization attempts: 30 / 30
- Current app: none; required source-opt sweep complete
- Rejected pre-attempts: otel `20260625-120059-defer-kernel-stackid-unmapped-pid` did not prove the edited eBPF source entered the embedded artifact, so it is recorded but not counted in the 30 valid attempts.

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
- 文档明确 `SKIP_REJIT=all` 下无 post phase、无 shim、无 kop module preload。
- 文档明确不 commit/push、不使用 git 命令回滚源码。
- 后续 agent 可以仅按本文档推进，不需要重新解释实验边界。
