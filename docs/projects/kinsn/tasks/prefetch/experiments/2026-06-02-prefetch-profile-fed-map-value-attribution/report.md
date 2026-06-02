# 2026-06-02 prefetch-profile-fed-map-value-attribution

## 结论

profile-fed map-value prefetch gate 已经能在 x86 和 ARM64 kernel micro runtime 上稳定触发目标
site：`prefetch_map_page_stride` 的每个 treatment sample 都是
`sites_matched=1`、`sites_applied=1`、`insn_delta=2`。

性能结论是 **preliminary positive signal, not default-enable evidence**：

| arch | metric | control ns | treatment ns | treatment/control | speedup | native delta | BPF delta |
|---|---|---:|---:|---:|---:|---:|---:|
| x86 | `exec_mean_ns` | 9376.400 | 8417.000 | 0.897679 | 11.398% | +4 B | +16 B |
| x86 | `exec_median_ns` | 9955.000 | 7918.000 | 0.795379 | 25.726% | +4 B | +16 B |
| ARM64 | `exec_mean_ns` | 14512.800 | 14021.600 | 0.966154 | 3.503% | +8 B | +16 B |
| ARM64 | `exec_median_ns` | 14168.000 | 14024.000 | 0.989836 | 1.027% | +8 B | +16 B |

解释：

- x86 的 `exec_ns` 有明显正向信号，但 `wall_exec_ns` 均值基本相同，不能单独作为强性能结论。
- ARM64 的 treatment samples 很稳定，mean 有 3.5% speedup，median 只有 1.0% speedup。
- 这说明 profile gate 是一个可用 admission mechanism；是否作为最终策略，还需要更大的 sample、
  PMU counter 和真实 profile/corpus evidence。

## 实验问题

Kinsn prefetch 是插入型优化：它不会删除原始 load，而是在 load 前额外插入
`KINSN_SIDECAR + KINSN_CALL`，由 kernel kinsn JIT 生成 native prefetch hint。

map-value prefetch 之前默认 disabled，因为 map lookup 返回的 value pointer 不一定 miss-prone。
本实验要回答：

1. `bpfopt --pass prefetch -- --profile FILE` 是否能把 profile side input 传进 kernel micro runtime。
2. profile 是否只允许指定的 map-value BPF PC 通过 admission。
3. 在同一个 benchmark、同一个 kernel/runtime、同一个 arch 上，profile-fed treatment 相对 no-pass
   control 是否有可观察 runtime 差异。

## Policy

profile 文件：

```text
/home/ruoji/github/bpf-opt/code/micro/config/prefetch-map-page-stride-profile-pc52.json
```

内容：

```json
{
  "map_value_pcs": [52]
}
```

语义：

- `pc=52` 是 `prefetch_map_page_stride` 中 map value first deref 的 BPF PC。
- 没有 profile 时，该 map-value candidate 必须 skipped。
- profile 包含该 PC 时，selector 允许该 site 插入 prefetch。

插入后，BPF bytecode 增加两个 kinsn 指令：`KINSN_SIDECAR` 和 `KINSN_CALL`。x86 native
看到 `prefetcht0 [rN]`，ARM64 native 看到 `prfm pldl1keep, [xN]`。

## 命令

全部命令都从 `/home/ruoji/github/bpf-opt` 执行，通过 Makefile wrapper：

```bash
/home/ruoji/github/bpf-opt/aws-config/run.sh x86 micro \
  BENCH=prefetch_map_page_stride \
  RUNTIMES=kernel \
  SAMPLES=5 \
  WARMUPS=1 \
  INNER_REPEAT=10000
```

```bash
/home/ruoji/github/bpf-opt/aws-config/run.sh x86 micro \
  BENCH=prefetch_map_page_stride \
  RUNTIMES=kernel \
  SAMPLES=5 \
  WARMUPS=1 \
  INNER_REPEAT=10000 \
  BPFREJIT_BENCH_PASSES=prefetch \
  BPFREJIT_BENCH_PASS_ARGS='--profile /home/ruoji/github/bpf-opt/code/micro/config/prefetch-map-page-stride-profile-pc52.json'
```

```bash
/home/ruoji/github/bpf-opt/aws-config/run.sh arm64 micro \
  BENCH=prefetch_map_page_stride \
  RUNTIMES=kernel \
  SAMPLES=5 \
  WARMUPS=1 \
  INNER_REPEAT=10000
```

```bash
/home/ruoji/github/bpf-opt/aws-config/run.sh arm64 micro \
  BENCH=prefetch_map_page_stride \
  RUNTIMES=kernel \
  SAMPLES=5 \
  WARMUPS=1 \
  INNER_REPEAT=10000 \
  BPFREJIT_BENCH_PASSES=prefetch \
  BPFREJIT_BENCH_PASS_ARGS='--profile /home/ruoji/github/bpf-opt/code/micro/config/prefetch-map-page-stride-profile-pc52.json'
```

前置 smoke 还各跑了 `SAMPLES=1 WARMUPS=0`，只用于确认 profile args propagation 和
`sites_applied=1`，不作为性能数据。

## 环境

| arch | instance | kernel | runtime | timing source | remote user | region |
|---|---|---|---|---|---|---|
| x86 | `t3.small` | `7.0.0-rc2+` | kernel micro | `ktime`; wall side `rdtsc` | `ec2-user` | `us-east-1` |
| ARM64 | `t4g.small` | `7.0.0-rc2+` | kernel micro | `ktime`; wall side unavailable | `ec2-user` | `us-east-1` |

Benchmark:

```text
/home/ruoji/github/bpf-opt/code/micro/programs/prefetch_map_research.bpf.c
/home/ruoji/github/bpf-opt/code/micro/programs/prefetch_map_research.md
```

Manifest:

```text
/home/ruoji/github/bpf-opt/code/micro/config/micro_pure_jit.yaml
```

## 文件改动

为支持本实验，涉及以下文件：

- `/home/ruoji/github/bpf-opt/code/bpfopt/crates/bpfopt/src/passes/prefetch.rs`
- `/home/ruoji/github/bpf-opt/code/bpfopt/crates/bpfopt/src/passes/mod.rs`
- `/home/ruoji/github/bpf-opt/code/bpfopt/crates/bpfopt/src/passes/prefetch_tests.rs`
- `/home/ruoji/github/bpf-opt/code/micro/driver.py`
- `/home/ruoji/github/bpf-opt/code/runner/include/micro_exec.hpp`
- `/home/ruoji/github/bpf-opt/code/runner/src/common.cpp`
- `/home/ruoji/github/bpf-opt/code/runner/src/kernel_runner.cpp`
- `/home/ruoji/github/bpf-opt/code/runner/suites/_common.py`
- `/home/ruoji/github/bpf-opt/code/Makefile`
- `/home/ruoji/github/bpf-opt/code/micro/config/prefetch-map-page-stride-profile-pc52.json`

本实验不提交任何 AWS credential、`.pem` 或 secret。

## 数据文件

原始 AWS result 副本：

```text
/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-profile-fed-map-value-attribution/data/aws-results/aws_x86_micro_20260602_055006_955057
/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-profile-fed-map-value-attribution/data/aws-results/aws_x86_micro_20260602_055621_359189
/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-profile-fed-map-value-attribution/data/aws-results/aws_x86_micro_20260602_053114_114520
/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-profile-fed-map-value-attribution/data/aws-results/aws_arm64_micro_20260602_054258_718433
/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-profile-fed-map-value-attribution/data/aws-results/aws_arm64_micro_20260602_060355_842916
/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-profile-fed-map-value-attribution/data/aws-results/aws_arm64_micro_20260602_061059_543563
```

分析文件：

```text
/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-profile-fed-map-value-attribution/analysis/raw-samples.tsv
/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-profile-fed-map-value-attribution/analysis/summary.tsv
/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-profile-fed-map-value-attribution/analysis/paired-attribution.tsv
/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-profile-fed-map-value-attribution/analysis/bpfopt-sites.tsv
/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-profile-fed-map-value-attribution/analysis/aws-instances.tsv
```

Raw measurement 保存在 framework result JSON；ratio、speedup 和 summary 只在 `analysis/` 和本报告中计算。

## 问题和处理

### pass args propagation

第一次 x86 profile-fed smoke 失败。原因是 `BPFREJIT_BENCH_PASS_ARGS` 没有透传到 runtime
container，`micro.driver` 没有看到 `--profile`。处理记录：

```text
/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-profile-fed-map-value-attribution/attempts/profile-args-missing/report.md
```

修复：

- `runner/suites/_common.py` 允许透传 `BPFREJIT_BENCH_PASS_ARGS`。
- profile 文件放到 `micro/config/`，确保 runtime image 可访问。

### Docker buildx cache

x86 image rebuild 时本地 Docker buildx snapshot cache 损坏，报：

```text
failed to prepare extraction snapshot ... parent snapshot ... does not exist
```

执行 `docker builder prune -f` 后重跑成功。处理记录：

```text
/home/ruoji/github/bpf-opt/experiments/2026-06-02-prefetch-profile-fed-map-value-attribution/attempts/docker-buildx-cache-failure/report.md
```

## 结果

### bpfopt application

| arch | samples | sites matched | sites applied | BPF insn delta |
|---|---:|---:|---:|---:|
| x86 | 5 | 1 each | 1 each | +2 each |
| ARM64 | 5 | 1 each | 1 each | +2 each |

### Raw runtime

| arch | case | exec_ns samples |
|---|---|---|
| x86 | control | `10728, 7880, 7853, 9955, 10466` |
| x86 | treatment | `10477, 7945, 7836, 7909, 7918` |
| ARM64 | control | `15550, 14034, 14672, 14140, 14168` |
| ARM64 | treatment | `14030, 14002, 14015, 14037, 14024` |

### Code size

| arch | case | BPF bytes | native bytes |
|---|---|---:|---:|
| x86 | control | 920 | 494 |
| x86 | treatment | 936 | 498 |
| ARM64 | control | 920 | 632 |
| ARM64 | treatment | 936 | 640 |

The treatment adds a prefetch hint; it is not a shorter replacement.

### Interpretation

The profile-fed gate is functioning correctly. It produces the expected native prefetch hint and preserves the
expected result value on all samples.

The speed signal is not yet sufficient for default admission:

- x86 `exec_ns` improves, but wall/cycle side timing does not show a strong paired improvement.
- ARM64 treatment is stable and slightly faster by `exec_ns`, but the median improvement is about 1%.
- No PMU counters were collected in this run, so the report cannot prove the speedup came from fewer cache misses.

This policy should remain profile-gated. It should not be default-enabled from this experiment alone.

## 验证

本地验证：

```bash
cd /home/ruoji/github/bpf-opt
python3 -m py_compile code/micro/driver.py code/runner/suites/_common.py
```

```bash
cd /home/ruoji/github/bpf-opt/code/bpfopt
cargo test -p bpfopt prefetch
cargo fmt -p bpfopt --check
```

```bash
cd /home/ruoji/github/bpf-opt/code
make host-runner-x86
```

结果：

- Python compile passed.
- `cargo test -p bpfopt prefetch` passed：13 tests.
- `cargo fmt -p bpfopt --check` passed.
- `make host-runner-x86` passed.

注意：`cargo test -p bpfopt prefetch` 曾从错误目录
`/home/ruoji/github/bpf-opt/code` 执行一次，因该目录没有 `Cargo.toml` 失败；随后从正确
workspace `/home/ruoji/github/bpf-opt/code/bpfopt` 重跑通过。

## AWS cost

Pricing source:

- EC2 On-Demand pricing: <https://aws.amazon.com/ec2/pricing/on-demand/>
- EBS pricing: <https://aws.amazon.com/ebs/pricing/>

Rates used for approximate estimate in `us-east-1`:

- `t3.small` Linux on-demand: `$0.0208/hour`
- `t4g.small` Linux on-demand: `$0.0168/hour`
- EBS `gp3`: `$0.08/GB-month`
- root volume: `32 GB`

Known instances:

| arch | case | instance id | type | launch UTC | state | approx wall min |
|---|---|---|---|---|---|---:|
| x86 | smoke | `i-07f397108c08d36b2` | `t3.small` | `2026-06-02T05:25:48+00:00` | terminated | 5.45 |
| ARM64 | smoke | `i-0320d00f195c07b53` | `t4g.small` | `2026-06-02T05:37:31+00:00` | terminated | 5.48 |
| x86 | control | `i-0cbf011d0b30f1a4f` | `t3.small` | `2026-06-02T05:44:38+00:00` | terminated | 5.58 |
| x86 | treatment | `i-0534d9ff54adb5ad9` | `t3.small` | `2026-06-02T05:51:46+00:00` | terminated | 4.68 |
| ARM64 | control | `i-08a2542fdd6fe0ac2` | `t4g.small` | `2026-06-02T05:57:57+00:00` | terminated | 6.09 |
| ARM64 | treatment | `i-019d03615362c1488` | `t4g.small` | `2026-06-02T06:05:30+00:00` | terminated | 5.60 |

Known compute estimate:

- x86 known compute: about `15.71 min * $0.0208/hour = $0.0054`.
- ARM64 known compute: about `17.17 min * $0.0168/hour = $0.0048`.
- known EBS estimate: about `32 GB * $0.08/GB-month * 0.548 hour / 720 = $0.0020`.
- known total: about `$0.012`.

This estimate excludes data transfer, tax, free tier, credits, Savings Plans, Reserved Instances, and account-level
discounts. The first failed x86 profile-args-missing attempt is not included in the numeric estimate because its
instance id / launch time was not retained in the copied logs.

## 后续

1. Keep profile-fed map-value prefetch behind profile/PMU evidence.
2. Add PMU-enabled run for this case to check whether speedup correlates with cache-miss reduction.
3. Add independent reruns if this policy is considered for admission; current `SAMPLES=5` is only an attribution
   smoke, not paper-grade stability evidence.
4. Continue with profile generation pipeline: corpus/site census should produce `map_value_pcs` or PMU-style
   `map_value_sites`, rather than hand-written PC allow-list.

## 收尾一致性复查

已回看：

- 当前实验失败 attempt：`attempts/profile-args-missing`。
- 当前实验本地 build failure：`attempts/docker-buildx-cache-failure`。
- 前序 prefetch 文档：
  `/home/ruoji/github/bpf-opt/docs/projects/kinsn/tasks/prefetch/plan.md`、
  `/home/ruoji/github/bpf-opt/docs/projects/kinsn/tasks/prefetch/policy-matrix.md`。
- 前序实验：
  `/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-profile-gate-impl/report.md`、
  `/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-selector-v3-policy-smoke/report.md`、
  `/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-x86-paired-attribution/report.md`。

发现和处理：

- 旧文档仍写着 “profile-fed AWS attribution 未跑”。已更新
  `/home/ruoji/github/bpf-opt/docs/projects/kinsn/tasks/prefetch/plan.md` 和
  `/home/ruoji/github/bpf-opt/docs/projects/kinsn/tasks/prefetch/policy-matrix.md`，记录为
  “已完成一轮 x86/ARM64 paired attribution，结果是 preliminary positive signal but not
  default-enable evidence”。
- 第一次 failed smoke 的结论已更新为 runner env propagation 问题，不再作为 selector failure。
- Docker buildx failure 已隔离为本地 cache 问题，不影响 benchmark 结论。

是否重跑：

- 代码行为修复后已经重跑 x86 smoke、ARM64 smoke 和 x86/ARM64 paired attribution。
- 本轮没有继续做 PMU 或多轮 independent rerun；原因是该实验目标是验证 profile-fed admission 和
  first paired signal，不是最终 paper-grade stability run。
