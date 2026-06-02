# 2026-06-01 prefetch-map-raw-loader-fix

## 结论

本实验完成，状态是 `completed_no_prefetch_win`。

本轮先修复 runner 的 raw-kinsn loader，使含 `bpf_arm64_prfm_*` kfunc extern 的 BPF object
也能使用 BTF-style `.maps`。修复后，3 个 map-backed prefetch micro 的 smoke、control 和
treatment 都能在 AWS ARM64 kernel runtime 运行。

性能结论：map-backed large working-set 没有证明 `PRFM` 是稳定收益。5 samples、1 warmup、
`INNER_REPEAT=100000` 下，3 个 case 的 `exec_ns` geomean treatment/control 是 `1.001694`，
约 0.17% slower。

| case | treatment PRFM | median treatment/control | 结论 |
|---|---:|---:|---|
| `prefetch_map_page_stride` | 1 | `0.997014` | 约 0.30% faster，幅度很小。 |
| `prefetch_map_indirect_page` | 2 | `1.005259` | 约 0.53% slower。 |
| `prefetch_map_line_dedup` | 1 | `1.002829` | 约 0.28% slower。 |
| geomean | - | `1.001694` | 约 0.17% slower。 |

因此，prefetch task 仍保持 `forced-only, default disabled`。下一步不应默认启用 `PRFM`；
如果继续 prefetch，应转向 selector v2 的严格 skip reason，或真实 app/corpus 的 site-level
attribution。

## 实验问题

本实验要回答两个问题：

1. raw-kinsn loader 能否支持 BTF `.maps` 和 map relocation？
2. 在 256 KiB map-backed working set 上，`PRFM` treatment 是否能比 same-LLC no-kinsn
   control 更快？

答案：

- loader 问题已修复。raw-kinsn 路径现在能解析 BTF `.maps`，创建 `input_map` / `result_map`，
  并把 ELF map relocation patch 成真实 map fd。
- prefetch 性能没有稳定 win。只有 `prefetch_map_page_stride` 小幅变快，另外两个 case 变慢。

## 命令

从 `/home/ruoji/github/bpf-opt` 执行。

本地构建验证：

```bash
make -C code/runner/build-llvmbpf micro_exec -j4
make -C code/runner/build-arm64-llvmbpf micro_exec -j4
```

AWS 配置和清理：

```bash
./aws-config/check.sh arm64
./aws-config/run.sh arm64 terminate
```

AWS smoke：

```bash
EXP=/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-map-raw-loader-fix
BENCHES='prefetch_map_page_stride,prefetch_map_indirect_page,prefetch_map_line_dedup'
LLC='/home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn/bin/llc'

./aws-config/run.sh arm64 micro \
  RUN_TOKEN=prefetch-map-loader-fix-smoke2 \
  BENCH="$BENCHES" \
  RUNTIMES=kernel \
  SAMPLES=1 WARMUPS=0 INNER_REPEAT=1000 \
  PERF_COUNTERS=1 PERF_SCOPE=full_repeat_raw \
  BPFREJIT_MICRO_BPF_COMPILER=kinsn-llvm \
  BPF_KINSN_LLC="$LLC" \
  BPF_KINSN_LLC_FLAGS='-disable-gotox -bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable -bpf-kinsn-mode=prefetch=force'
```

AWS control：

```bash
./aws-config/run.sh arm64 micro \
  RUN_TOKEN=prefetch-map-loader-fix-control \
  BENCH="$BENCHES" \
  RUNTIMES=kernel \
  SAMPLES=5 WARMUPS=1 INNER_REPEAT=100000 \
  PERF_COUNTERS=1 PERF_SCOPE=full_repeat_raw \
  BPFREJIT_MICRO_BPF_COMPILER=kinsn-llvm \
  BPF_KINSN_LLC="$LLC" \
  BPF_KINSN_LLC_FLAGS='-disable-gotox -bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable'
```

AWS treatment：

```bash
./aws-config/run.sh arm64 micro \
  RUN_TOKEN=prefetch-map-loader-fix-treatment \
  BENCH="$BENCHES" \
  RUNTIMES=kernel \
  SAMPLES=5 WARMUPS=1 INNER_REPEAT=100000 \
  PERF_COUNTERS=1 PERF_SCOPE=full_repeat_raw \
  BPFREJIT_MICRO_BPF_COMPILER=kinsn-llvm \
  BPF_KINSN_LLC="$LLC" \
  BPF_KINSN_LLC_FLAGS='-disable-gotox -bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable -bpf-kinsn-mode=prefetch=force'
```

## 环境

- workspace：`/home/ruoji/github/bpf-opt`
- code repo：`/home/ruoji/github/bpf-opt/code`
- runner builds：
  - `/home/ruoji/github/bpf-opt/code/runner/build-llvmbpf/micro_exec`
  - `/home/ruoji/github/bpf-opt/code/runner/build-arm64-llvmbpf/micro_exec`
- custom `llc`：`/home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn/bin/llc`
- AWS arch：`arm64`
- AWS region：`us-east-1`
- AWS instance type：`t4g.small`
- AWS remote user：`ec2-user`
- AWS root volume：32 GiB
- runtime image：`bpf-benchmark/runner-runtime:arm64`
- kernel：`7.0.0-rc2+`

## 文件改动

代码改动：

- `/home/ruoji/github/bpf-opt/code/runner/include/micro_exec.hpp`
- `/home/ruoji/github/bpf-opt/code/runner/src/elf_program_loader.cpp`
- `/home/ruoji/github/bpf-opt/code/runner/src/kernel_runner.cpp`

相关 prefetch micro 改动来自前序 map-backed experiment，本实验继续使用：

- `/home/ruoji/github/bpf-opt/code/micro/programs/prefetch_map_research.bpf.c`
- `/home/ruoji/github/bpf-opt/code/micro/config/micro_pure_jit.yaml`
- `/home/ruoji/github/bpf-opt/code/runner/libs/input_generators.py`

文档 / 实验记录改动：

- `/home/ruoji/github/bpf-opt/docs/projects/kinsn/tasks/prefetch/plan.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-map-large-working-set-attribution/report.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-map-raw-loader-fix/report.md`

## 实现内容

问题来源：前序实验中，开启 `prefetch=force` 后 object 出现 `bpf_arm64_prfm_pldl1keep`
kfunc extern。runner 因此走 raw-kinsn loader，但 raw loader 原来只 patch kfunc relocation，
不创建 maps，也不 patch `input_map` / `result_map` 的 map relocation。verifier 看到
`bpf_map_lookup_elem` 的第一个参数不是 map pointer，报 `R1 type=scalar expected=map_ptr`。

本轮修复：

- `load_program_image()` 新增可选 `map_ids` 参数。
- ELF relocation patch 复用已有逻辑：如果 relocation symbol 命中 `map_ids`，把 `LDIMM64`
  改成 `BPF_PSEUDO_MAP_FD` 和真实 fd。
- raw-kinsn loader 不再用 libbpf open 含 unresolved kfunc extern 的 object。原因是 libbpf
  会在 open/load 阶段解析 extern BTF，并因 `bpf_arm64_prfm_pldl1keep` 找不到 BTF 而失败。
- raw-kinsn loader 改为直接解析 object BTF `.maps` datasec：
  - `__uint(type, value)` 从 BTF pointer-to-array 的 `nr_elems` 读常量。
  - `__type(key, T)` / `__type(value, T)` 用 BTF type size 得到 key/value size。
  - 调用 `bpf_map_create()` 创建 map。
  - 持有 map fd，供 relocation patch 和 map input/result path 使用。

当前支持范围：BTF-style simple maps，例如本实验的 `BPF_MAP_TYPE_ARRAY`。raw-kinsn loader 仍不支持
fixture replay、Katran fixture、map-in-map、prog array 或 custom BTF path。

## 数据文件

- `data/aws-treatment-smoke.log`：初始失败 smoke，仍走 libbpf maps-only open，失败于 extern BTF。
- `data/remote-treatment-smoke.log`：初始失败远端 log。
- `data/aws-treatment-smoke2.log`：修复后 smoke。
- `data/aws-control.log`：正式 control。
- `data/aws-treatment.log`：正式 treatment。
- `data/smoke-result/`：修复后 smoke raw result。
- `data/control-result/`：control raw result。
- `data/treatment-result/`：treatment raw result。
- `data/aws-instance-describe.json`：AWS instance 状态。
- `analysis/prefetch-map-attribution.tsv`：按 case 的 sample、median ratio、code size delta。
- `analysis/prfm-counts.tsv`：control/treatment native PRFM 数量。
- `analysis/aws-cost-estimate.tsv`：AWS wall time 和费用估算。

## 问题和处理

初始尝试失败：

```text
libbpf: failed to find BTF for extern 'bpf_arm64_prfm_pldl1keep': -2
bpf_object__open_file failed: No such file or directory
```

原因：即使禁用 program autoload，libbpf open/load object 仍会处理 extern kfunc BTF。含 kinsn extern
的 object 不能用 libbpf maps-only path 作为 raw loader 的 map 创建方案。

处理：改为手动 BTF `.maps` parsing + `bpf_map_create()`，完全绕开 libbpf object open/load。

## 结果

### Correctness / Loader

| run | result |
|---|---|
| local x86 runner build | passed |
| local arm64 runner build | passed |
| AWS treatment smoke | 3/3 completed |
| AWS control | 3/3 completed |
| AWS treatment | 3/3 completed |

3 个 treatment case 都命中 native `prfm pldl1keep`：

| case | control PRFM | treatment PRFM |
|---|---:|---:|
| `prefetch_map_indirect_page` | 0 | 2 |
| `prefetch_map_line_dedup` | 0 | 1 |
| `prefetch_map_page_stride` | 0 | 1 |

### Performance

`exec_ns` 是 runner 保存的 kernel runtime raw measurement，单位是 ns。下面只在 experiment
analysis 中计算 median 和 ratio；benchmark framework 本身只保存 raw data。

| benchmark | control exec ns samples | treatment exec ns samples | control median | treatment median | treatment/control | speedup |
|---|---|---|---:|---:|---:|---:|
| `prefetch_map_indirect_page` | `14648,14641,14641,14640,14633` | `14764,15400,14717,14718,14711` | 14641 | 14718 | `1.005259` | -0.526% |
| `prefetch_map_line_dedup` | `14923,14490,14493,14495,14503` | `14534,14539,14536,14534,15499` | 14495 | 14536 | `1.002829` | -0.283% |
| `prefetch_map_page_stride` | `14047,14064,13840,14357,14132` | `14022,14014,14021,14024,14025` | 14064 | 14022 | `0.997014` | +0.299% |
| geomean | - | - | - | - | `1.001694` | -0.169% |

Code size:

| benchmark | control native bytes | treatment native bytes | delta |
|---|---:|---:|---:|
| `prefetch_map_indirect_page` | 720 | 728 | +8 |
| `prefetch_map_line_dedup` | 976 | 984 | +8 |
| `prefetch_map_page_stride` | 632 | 640 | +8 |

PMU caveat：AWS kernel `perf_event_paranoid=2`，本轮只稳定拿到 `cycles` / `task_clock_ns` /
context switch 等基础 counter；`instructions`、cache miss、branch miss 等 perf events 返回
`No such file or directory`。因此本轮可以判断 runtime 结果，但不能用 cache-miss counter 做深度
机理归因。

## AWS 时间和费用

价格来源：

- EC2 `t4g.small` Linux on-demand：AWS Pricing API，`us-east-1`，`0.0168 USD/hour`。
- EBS gp3 storage：AWS Pricing API，`us-east-1`，`0.08 USD/GB-month`。

估算假设：root volume 32 GiB，按 730 hour/month 折算；不包含 data transfer、税、free tier、
credits、Savings Plans、Reserved Instances 或账户级折扣。

| run | instance id | launch UTC | observed terminate UTC | wall min | compute USD | EBS USD | total USD |
|---|---|---|---|---:|---:|---:|---:|
| failed-smoke | `i-09b35a08fedbe4c45` | 2026-06-01T07:13:27Z | 2026-06-01T07:18:42Z | 5.25 | 0.001471 | 0.000307 | 0.001778 |
| smoke2 | `i-02e7c68e290b30c05` | 2026-06-01T07:27:18Z | 2026-06-01T07:32:48Z | 5.51 | 0.001542 | 0.000322 | 0.001864 |
| control | `i-049cebb53720b8964` | 2026-06-01T07:34:51Z | 2026-06-01T07:42:00Z | 7.16 | 0.002006 | 0.000419 | 0.002425 |
| treatment | `i-0a270c14456ccb67c` | 2026-06-01T07:43:36Z | 2026-06-01T07:51:58Z | 8.37 | 0.002345 | 0.000489 | 0.002834 |
| total | - | - | - | - | 0.007364 | 0.001537 | 0.008901 |

AWS CLI `describe-instances` 显示 4 个 instance 均为 `terminated`。

## 后续

不要默认启用 `PRFM`。

下一步有两个可选方向：

1. 做 selector v2：只保留 `packet_first_deref` 这类已有弱 positive candidate，并给 hot L1、
   sequential、no-distance、small-block、cacheline-duplicate 等情况输出 skip reason。
2. 做真实 app/corpus site-level attribution：对每个 prefetch site 记录 source pattern、native
   code change、runtime delta 和 skip/apply reason。map-backed micro 已经说明 simple stride /
   indirect page / cacheline dedup 不足以支撑 default policy。

## 收尾一致性复查

已回看：

- 前序失败实验：`/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-map-large-working-set-attribution/report.md`
- 当前实验初始失败 smoke：`data/aws-treatment-smoke.log` 和 `data/remote-treatment-smoke.log`
- 当前实验修复后 smoke/control/treatment raw result
- Prefetch task 文档：`/home/ruoji/github/bpf-opt/docs/projects/kinsn/tasks/prefetch/plan.md`

发现和处理：

- 前序 report 仍写着 raw loader map relocation 阻塞。已在该 report 顶部补充后续状态，指向本实验。
- Prefetch task plan 中的下一步仍写“先修 raw-kinsn loader map relocation”。已更新为 loader 已修复、
  map-backed attribution 已完成，当前仍不默认启用 PRFM。
- 本轮修复没有删除已有 micro；没有发现需要清理的临时 workaround。

是否重跑：

- 修改 runner code 后已重新编译 x86/arm64 `micro_exec`。
- 已重跑 AWS smoke、control 和 treatment；结果记录在本实验目录。
