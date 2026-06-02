# 2026-06-01 prefetch-map-large-working-set-attribution

## 结论

本实验完成，状态是 `blocked_by_raw_kinsn_map_loader`。

后续状态更新：该阻塞点已在新的修复实验中解决，map-backed treatment 已可运行。新的性能结论见：

```text
/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-map-raw-loader-fix/report.md
```

本轮根据 prefetch literature review 的结论，尝试把 prefetch micro 从 1400-byte XDP staged
packet 扩展到 256 KiB map-backed working set，目标是制造更接近 cold / large working-set 的
memory access。

结果：

- 新增 3 个 map-backed benchmark，均使用 `io_mode: map` 和 256 KiB `input_map` value。
- control 通过。`-bpf-kinsn-mode=all=disable` 下，AWS ARM64 kernel runtime 能创建和填充
  `input_map`，3 个 benchmark 都通过 expected result。
- treatment 失败。开启 `-bpf-kinsn-mode=prefetch=force` 后，object 中出现
  `bpf_arm64_prfm_pldl1keep` relocation，runner 切到 raw-kinsn loader；该 loader 当前不支持
  map relocation，导致 `input_map` 的 `LDIMM64` 没有被替换成 map fd，verifier 报
  `R1 type=scalar expected=map_ptr`。
- 因此本实验不能形成 prefetch performance attribution。阻塞点是 runner/raw-kinsn loader 的 map
  relocation 支持，不是 PRFM ABI，也不是新 micro 的 verifier 写法。

下一步必须先修复 raw-kinsn micro loader 对 `.maps` / `R_BPF_64_64` map relocation 的支持，然后
重新跑同一个 experiment。

## 实验问题

本实验要回答：

1. 现有 micro framework 是否能跑 map-backed large working-set prefetch case？
2. 在比 XDP packet 更大的 map value working set 上，`PRFM` treatment 是否能形成 same-LLC
   control/treatment attribution？

答案：

- control 可以跑，说明 benchmark 载体和 map 输入路径可用。
- treatment 当前不能跑，说明 raw-kinsn loader map 支持是下一个前置工程问题。

## Benchmark

新增代码：

```text
/home/ruoji/github/bpf-opt/code/micro/programs/prefetch_map_research.bpf.c
/home/ruoji/github/bpf-opt/code/runner/libs/input_generators.py
/home/ruoji/github/bpf-opt/code/micro/config/micro_pure_jit.yaml
```

新增 benchmark：

| benchmark | input | 目的 |
|---|---:|---|
| `prefetch_map_page_stride` | 256 KiB `input_map` value | 每轮跨 4 KiB page-ish region 访问，制造大 working-set stride。 |
| `prefetch_map_indirect_page` | 256 KiB `input_map` value | 从 table byte 计算 page/offset，再访问 payload，模拟 indirect access。 |
| `prefetch_map_line_dedup` | 256 KiB `input_map` value | 每轮读取同一 cacheline 内 4 个 word，检查 cacheline dedup 需求。 |

这些 case 都标记为 `kernel-only`，因为它们依赖真实 BPF map 输入；当前目标是 kernel runtime
prefetch attribution，不是 native runtime 对比。

## 命令

从 `/home/ruoji/github/bpf-opt` 执行。

本地 smoke：

```bash
python3 -m py_compile code/runner/libs/input_generators.py

make -C code/micro/programs OUTPUT_DIR=/tmp/bpf-opt-prefetch-map-smoke \
  /tmp/bpf-opt-prefetch-map-smoke/prefetch_map_research.bpf.o

make -C code/micro/programs OUTPUT_DIR=/tmp/bpf-opt-prefetch-map-smoke \
  /tmp/bpf-opt-prefetch-map-smoke/prefetch_map_research.native.so

PYTHONPATH=/home/ruoji/github/bpf-opt/code \
  python3 code/micro/driver.py \
  --suite /home/ruoji/github/bpf-opt/code/micro/config/micro_pure_jit.yaml \
  --list | grep prefetch_map
```

AWS control smoke：

```bash
BENCHES='prefetch_map_page_stride,prefetch_map_indirect_page,prefetch_map_line_dedup'
LLC='/home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn/bin/llc'

./aws-config/run.sh arm64 micro \
  RUN_TOKEN=prefetch-map-control-smoke \
  BENCH="$BENCHES" \
  RUNTIMES=kernel \
  SAMPLES=1 WARMUPS=0 INNER_REPEAT=1000 \
  PERF_COUNTERS=1 PERF_SCOPE=full_repeat_raw \
  BPFREJIT_MICRO_BPF_COMPILER=kinsn-llvm \
  BPF_KINSN_LLC="$LLC" \
  BPF_KINSN_LLC_FLAGS='-disable-gotox -bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable'
```

AWS formal control:

```bash
./aws-config/run.sh arm64 micro \
  RUN_TOKEN=prefetch-map-control-r1 \
  BENCH="$BENCHES" \
  RUNTIMES=kernel \
  SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000 \
  PERF_COUNTERS=1 PERF_SCOPE=full_repeat_raw \
  BPFREJIT_MICRO_BPF_COMPILER=kinsn-llvm \
  BPF_KINSN_LLC="$LLC" \
  BPF_KINSN_LLC_FLAGS='-disable-gotox -bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable'
```

AWS treatment attempt:

```bash
./aws-config/run.sh arm64 micro \
  RUN_TOKEN=prefetch-map-treatment-r1 \
  BENCH="$BENCHES" \
  RUNTIMES=kernel \
  SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000 \
  PERF_COUNTERS=1 PERF_SCOPE=full_repeat_raw \
  BPFREJIT_MICRO_BPF_COMPILER=kinsn-llvm \
  BPF_KINSN_LLC="$LLC" \
  BPF_KINSN_LLC_FLAGS='-disable-gotox -bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable -bpf-kinsn-mode=prefetch=force'
```

## 环境

- workspace：`/home/ruoji/github/bpf-opt`
- code repo：`/home/ruoji/github/bpf-opt/code`
- platform：AWS ARM64
- instance type：`t4g.small`
- region：`us-east-1`
- remote user：`ec2-user`
- kernel：`7.0.0-rc2+`
- runtime image：`bpf-benchmark/runner-runtime:arm64`
- custom `llc`：`/home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn/bin/llc`

## 文件改动

代码和配置：

- `/home/ruoji/github/bpf-opt/code/micro/programs/prefetch_map_research.bpf.c`
- `/home/ruoji/github/bpf-opt/code/runner/libs/input_generators.py`
- `/home/ruoji/github/bpf-opt/code/micro/config/micro_pure_jit.yaml`

文档和实验记录：

- `/home/ruoji/github/bpf-opt/docs/projects/kinsn/tasks/prefetch/plan.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-map-large-working-set-attribution/report.md`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-map-large-working-set-attribution/data/run-contract.json`
- `/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-map-large-working-set-attribution/analysis/*`

## 数据文件

Raw results：

- `data/control-smoke-result/`
- `data/control-r1-result/`
- `data/treatment-r1-failed-result/`

Logs：

- `data/aws-check.log`
- `data/aws-control-smoke.log`
- `data/aws-prefetch-map-control-r1.log`
- `data/aws-prefetch-map-treatment-r1.log`
- `data/remote-control-smoke.log`
- `data/remote-treatment-r1.log`
- `data/aws-terminate.log`
- `data/aws-active-after.json`
- `data/aws-describe-instances.json`

Analysis：

- `analysis/control-and-failure-summary.tsv`
- `analysis/object-reloc-summary.txt`
- `analysis/aws-cost-estimate.tsv`
- `analysis/aws-instances.tsv`

## 问题和处理

### Treatment load failure

Treatment object 同时包含 map relocation 和 `bpf_arm64_prfm_pldl1keep` relocation：

```text
R_BPF_64_64 input_map
R_BPF_64_32 bpf_arm64_prfm_pldl1keep
R_BPF_64_64 result_map
```

因为 object 中存在 kfunc sidecar，runner 走 raw-kinsn loader。这个 loader 只解析 kfunc relocation，
不支持 `.maps` 和 map fd relocation。结果是 `input_map` 的 `LDIMM64` 仍是 0，kernel verifier
看到：

```text
4: (18) r1 = 0x0
6: (85) call bpf_map_lookup_elem#1
R1 type=scalar expected=map_ptr
```

因此失败来自 runner/raw-kinsn loader 功能缺失。control 没有 kfunc sidecar，走普通 libbpf loader，
所以 map relocation 正常。

处理：

- 停止继续跑 r2/r3，避免重复消耗 AWS。
- 保留 failed treatment raw data 和 remote log。
- 记录下一步必须修复 raw-kinsn loader map support。
- 已执行 terminate / active-instance check，确认无活动实例。

## 结果

### Control

| run | benchmark | status | samples | median `exec_ns` | median `cycles` |
|---|---|---:|---:|---:|---:|
| control smoke | `prefetch_map_page_stride` | completed | 1 | 14613 | 35123356 |
| control smoke | `prefetch_map_indirect_page` | completed | 1 | 14688 | 36732985 |
| control smoke | `prefetch_map_line_dedup` | completed | 1 | 14555 | 36346369 |
| control r1 | `prefetch_map_page_stride` | completed | 3 | 13985 | 3493117995 |
| control r1 | `prefetch_map_indirect_page` | completed | 3 | 15096 | 3662206592 |
| control r1 | `prefetch_map_line_dedup` | completed | 3 | 14496 | 3619768877 |

### Treatment

| benchmark | status | reason |
|---|---|---|
| `prefetch_map_page_stride` | failed before benchmark execution | raw-kinsn loader did not relocate `input_map`. |
| `prefetch_map_indirect_page` | failed before benchmark execution | raw-kinsn loader did not relocate `input_map`. |
| `prefetch_map_line_dedup` | failed before benchmark execution | raw-kinsn loader did not relocate `input_map`. |

### Object Evidence

| object | `bpf_arm64_prfm_pldl1keep` symbol | map relocations |
|---|---:|---:|
| control | 0 | present |
| treatment | 1 undefined symbol, 4 call relocations | present but not handled by raw loader |

因此没有 treatment/control runtime ratio。本实验的有效结论是 framework blocker，不是 prefetch
performance conclusion。

## AWS 时间和费用

估算输入：

- instance：`t4g.small`
- compute 单价：`$0.0208/hour`
- root EBS：32 GiB gp3，按 `$0.08/GB-month` 和 730 hours/month 估算
- 不包含 data transfer、税、free tier、credits、Savings Plans、Reserved Instances 或账户级折扣。

| instance | wall seconds | compute USD | EBS USD | total USD |
|---|---:|---:|---:|---:|
| control smoke | 268 | 0.001548444 | 0.000261065 | 0.001809510 |
| control r1 | 452 | 0.002611556 | 0.000440304 | 0.003051860 |
| treatment r1 | 317 | 0.001831556 | 0.000308798 | 0.002140353 |
| total | 1037 | 0.005991556 | 0.001010167 | 0.007001723 |

实例清理：

```text
data/aws-active-after.json => []
```

## 后续

1. 修复 raw-kinsn loader map support：
   - 解析 `.maps` / map specs；
   - 创建 map fd；
   - 将 `R_BPF_64_64 input_map/result_map` patch 成 `BPF_PSEUDO_MAP_FD`；
   - raw load 后保留 map fd 给 `io_mode: map` 更新和结果读取。
2. 用本实验同一目录或 rerun 目录重跑：
   - control smoke；
   - treatment smoke；
   - 3 轮 control/treatment pair；
   - JIT dump / object relocation summary。
3. 如果 treatment 能跑，再判断 map-backed large working-set 是否给 PRFM 带来性能收益。

## 收尾一致性复查

已回看：

- 本实验的 control smoke、control r1、treatment r1 failed result。
- 前序 prefetch experiments：
  - `/home/ruoji/github/bpf-opt/experiments/2026-05-31-prefetch-research-micro-attribution/report.md`
  - `/home/ruoji/github/bpf-opt/experiments/2026-05-31-prefetch-candidate-filtering-micro-attribution/report.md`
  - `/home/ruoji/github/bpf-opt/experiments/2026-06-01-prefetch-indirect-timeliness-micro-attribution/report.md`
- task doc：
  - `/home/ruoji/github/bpf-opt/docs/projects/kinsn/tasks/prefetch/plan.md`

发现和处理：

- `plan.md` 仍把 map-backed large working-set 写成下一步但没有记录 raw-kinsn loader blocker。
  已更新为：必须先修复 raw-kinsn loader map relocation，再做 map-backed attribution。
- 未发现需要删除的 prefetch micro 代码。新增 map-backed micro 仍有价值，因为它已经证明 control
  路径可用，并明确暴露 treatment 的前置 loader 缺口。

是否重跑：

- 没有重跑 treatment r2/r3，因为 treatment r1 在所有 3 个 benchmark 上同一原因失败；继续跑只会
  重复同一个 raw-loader blocker。
- 已清理 AWS 实例，并保存失败 raw data。
