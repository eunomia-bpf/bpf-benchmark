# Katran Branch-Flip Profiling (2026-03-20)

## Executive Summary

- 目标程序：`balancer_ingress`
- 采集方式：
  - live profile：`runner/scripts/collect_e2e_profile.py katran` 通过 `virtme-ng` guest 运行
  - paired benchmark：`e2e/run.py katran --vm`，same-image `stock -> recompile`
  - 参数：`--katran-packet-repeat 1`
- 结论：
  - live enumerate 稳定看到 `74` 个 live sites，其中 `branch-flip=56`
  - Phase 2 的 6 组 branch-flip 里，只有 `g06` 在第一次 `3 cycles x 5s` 筛选中出现了弱正向：`1.039x`
  - 但 Phase 3 把 `g06` 二分后，`g06a=0.983x`、`g06b=0.855x`，都转为负向
  - Phase 4 最终复测 (`5 cycles x 5s`)：
    - `safe6`：`1.093x`
    - `safe6 + g06`：`0.913x`
  - 结论收敛为：**这轮 Katran workload 下，没有 branch-flip site 值得加入最终 policy**
- 最优 policy：
  - `docs/tmp/katran_branchflip_policies/katran_branchflip_optimal.policy.yaml`
  - 内容等于 `safe6`：`4 wide + 2 endian-load-swap-32`
  - **不包含任何 branch-flip site**

## Phase 1: Live Profile

Artifact:

- `docs/tmp/katran_branchflip_profile_20260320.json`

Guest profile 生成时间（UTC）：

- `2026-03-21T02:20:20.159715+00:00`

6s profile window 下的 program-level stats：

- `run_cnt = 2286`
- `run_time_ns = 766012`
- `avg_ns/run = 335.09`
- `bytes_jited = 13412`
- `bytes_xlated = 23872`

Live site census：

- `total = 74`
- `branch-flip = 56`
- `cmov = 8`
- `wide = 4`
- `endian = 4`
- `extract = 2`

56 个 branch-flip offsets（按 insn offset 排序）：

`15, 370, 481, 567, 614, 644, 676, 723, 874, 922, 952, 979, 1019, 1131, 1179, 1200, 1243, 1270, 1284, 1307, 1408, 1440, 1495, 1512, 1528, 1543, 1582, 1618, 1739, 1763, 1779, 1810, 1862, 1909, 1953, 1980, 1996, 2048, 2068, 2110, 2136, 2150, 2172, 2278, 2307, 2362, 2379, 2399, 2414, 2457, 2480, 2606, 2626, 2643, 2691, 2734`

分组 policy manifest：

- `docs/tmp/katran_branchflip_policies/manifest.json`

## Measurement Notes

- 所有 Phase 2 / Phase 3 benchmark 都是 guest 内 same-image paired measurement。
- 每次 run 都比较本次 boot 内的 `stock` 与 `recompile`。
- 不同 VM boot 之间 raw `bpf avg ns` 漂移很大（本轮观察到 `~295ns` 到 `~472ns`），所以**跨 run 只用 paired `bpf_speedup_ratio` 判断正负，不直接横比 raw ns**。
- `8s x 5 cycles` 的 final validation 对 harness 不稳定，`safe6` 和 `safe6+g06` 都 hit request timeout；最终采用稳定的 `5s x 5 cycles` 作为最终 gate。

## Phase 2: Group Screening

Artifacts:

- `docs/tmp/katran_branchflip_runs_20260320/phase1_summary.json`
- `docs/tmp/katran_branchflip_runs_20260320/safe6.json`
- `docs/tmp/katran_branchflip_runs_20260320/g01.json`
- `docs/tmp/katran_branchflip_runs_20260320/g02.json`
- `docs/tmp/katran_branchflip_runs_20260320/g03.json`
- `docs/tmp/katran_branchflip_runs_20260320/g04.json`
- `docs/tmp/katran_branchflip_runs_20260320/g05.json`
- `docs/tmp/katran_branchflip_runs_20260320/g06.json`

Config:

- `3 cycles`
- `5s` per phase
- `packet_repeat=1`
- policy = `safe6 + group-specific branch-flip offsets`

Results (paired `bpf_speedup_ratio = stock / recompile`)：

| Label | Branch-flip count | Offset range | BPF speedup | Result |
| --- | ---: | --- | ---: | --- |
| `safe6` | `0` | `-` | `0.937x` | baseline |
| `g01` | `10` | `15..922` | `0.974x` | negative |
| `g02` | `10` | `952..1307` | `0.983x` | negative |
| `g03` | `9` | `1408..1739` | `0.975x` | negative |
| `g04` | `9` | `1763..2048` | `0.954x` | negative |
| `g05` | `9` | `2068..2379` | `0.968x` | negative |
| `g06` | `9` | `2399..2734` | `1.039x` | tentative positive |

`g06` 的 offsets：

- `2399, 2414, 2457, 2480, 2606, 2626, 2643, 2691, 2734`

初筛判断：

- `g01..g05` 都是负向，不值得继续
- 只有 `g06` 进入 Phase 3

## Phase 3: Bisection On g06

Artifacts:

- `docs/tmp/katran_branchflip_runs_20260320/phase3_g06_halves_summary.json`
- `docs/tmp/katran_branchflip_runs_20260320/g06a.json`
- `docs/tmp/katran_branchflip_runs_20260320/g06b.json`

二分：

- `g06a = 2399, 2414, 2457, 2480, 2606`
- `g06b = 2626, 2643, 2691, 2734`

Results:

| Label | Offsets | BPF speedup | Result |
| --- | --- | ---: | --- |
| `g06a` | `2399, 2414, 2457, 2480, 2606` | `0.983x` | negative |
| `g06b` | `2626, 2643, 2691, 2734` | `0.855x` | strongly negative |

结论：

- `g06` 的初筛正向**不可分解**
- 拆开后两半都不正向
- 因此我没有继续做单 site profiling；继续往下拆没有意义

## Phase 4: Final Validation

Artifacts:

- `docs/tmp/katran_branchflip_runs_20260320/final_validation_summary_5cycles.json`
- `docs/tmp/katran_branchflip_runs_20260320/final5_safe6.json`
- `docs/tmp/katran_branchflip_runs_20260320/final5_g06.json`

Stable final gate config:

- `5 cycles`
- `5s` per phase
- `packet_repeat=1`

Final results:

| Policy | BPF speedup | BPF delta | Decision |
| --- | ---: | ---: | --- |
| `safe6` | `1.093x` | `-8.53%` | keep |
| `safe6 + g06` | `0.913x` | `+9.55%` | reject |

这一步给出了最终判定：

- `safe6` 在更长的重复测量里是稳定正向
- `g06` 在最终复测里翻成明显负向
- 所以 `g06` 在 Phase 2 的 `1.039x` 更像一次性噪声或需要整组耦合才出现的不可复现效应

## Final Policy

最终 policy：

- `docs/tmp/katran_branchflip_policies/katran_branchflip_optimal.policy.yaml`

等价于：

- `docs/tmp/katran_branchflip_policies/katran_branchflip_safe6.policy.yaml`

最终保留 site：

- `wide-load-2`: `120, 125, 266, 271`
- `endian-load-swap-32`: `381, 734`

最终明确不保留：

- `56/56 branch-flip sites`

## Bottom Line

- 这轮 Katran branch-flip profiling 没有找到任何可稳定保留的 branch-flip site。
- **值得 flip 的 site 数量 = 0。**
- 当前最优 Katran policy 仍然是 **`safe6` only**。
