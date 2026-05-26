# ARM64 LDRH/LDR_W performance attribution

日期：2026-05-25。

## 结论

本报告记录 ARM64 `LDRH` / `LDR_W` selected-safe subset 的 same-LLC performance
attribution。实验状态：`completed`。

三组 AWS ARM64 full micro 都通过：

| group | benchmarks | runtimes | samples | failed samples |
|---|---:|---:|---:|---:|
| baseline | 29 | 2 | 174 | 0 |
| control-disabled | 29 | 2 | 174 | 0 |
| treatment-wide-load | 29 | 2 | 174 | 0 |

主要性能口径是 `treatment-wide-load / control-disabled`，不是 treatment / clang baseline。

结果：

- kernel runtime：full suite geomean `0.965897`，selected-hw geomean `0.968229`。
- native runtime：full suite geomean `1.00577`，selected-hw geomean `1.00515`。
- selected-hw kernel wins/losses/neutral：4 / 2 / 16。
- selected-hw code size median 下降：BPF bytecode `1456 -> 1360`，JIT native
  `1020 -> 948`。
- AWS cost estimate：`$0.00951037`，只包含 on-demand compute 和 32GB gp3 root EBS。

这不是 paper-grade performance result。它是 development-grade micro attribution：证明当前
`LDRH/LDR_W` treatment correctness 通过，并且在 selected kernel subset 上有小样本 geomean
改善和 code-size reduction。

## 总体进度

总体目标：在 LLVM BPF backend 中实现 ARM64 kinsn-aware backend path。

Family 状态：

| Family | kfunc count | 当前状态 |
|---|---:|---|
| `REV` | 3 | development-complete on micro。 |
| `EXTR` | 2 | development-complete on micro。 |
| `UBFM` | 1 | development-complete on micro。 |
| `LDR` | 4 | partial；`LDR_X`、`LDRH/LDR_W` selected-safe subset development-complete on micro；`LDRB` normal selector deferred。 |
| `STR` | 4 | design-complete；direct-store selector deferred，store-widening selector deferred。 |
| `LDP/STP` | 2 | not started。 |
| `CSEL` | 2 | design-complete；next gate is LLVM implementation。 |
| `CCMP/CMP/CSET` | 5 | not started。 |
| `PRFM` | 1 | not started。 |
| `MOV` | 1 | not started。 |

当前 gate：`LDRH/LDR_W` family-only performance attribution completed。
后续 combined regression 已完成；`STR` design 已完成并决定暂缓 selector；`CSEL` design
和 targeted LLVM implementation 已完成，但当前 29 个 micro object 0 hit。下一步 gate 是
CSEL coverage/correctness。

## 实验配置

从 `/home/ruoji/github/bpf-opt` 通过 AWS wrapper 执行。

Baseline：

```bash
QEMU_LD_PREFIX=/usr/aarch64-linux-gnu \
/home/ruoji/github/bpf-opt/aws-config/run.sh arm64 micro \
  RUNTIMES="native kernel" \
  SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000
```

Control：

```bash
QEMU_LD_PREFIX=/usr/aarch64-linux-gnu \
/home/ruoji/github/bpf-opt/aws-config/run.sh arm64 micro \
  RUNTIMES="native kernel" \
  SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000 \
  BPFREJIT_MICRO_BPF_COMPILER=kinsn-llvm \
  BPF_KINSN_LLC="/home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn/bin/llc" \
  BPF_KINSN_LLC_FLAGS="-bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable"
```

Treatment:

```bash
QEMU_LD_PREFIX=/usr/aarch64-linux-gnu \
/home/ruoji/github/bpf-opt/aws-config/run.sh arm64 micro \
  RUNTIMES="native kernel" \
  SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000 \
  BPFREJIT_MICRO_BPF_COMPILER=kinsn-llvm \
  BPF_KINSN_LLC="/home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn/bin/llc" \
  BPF_KINSN_LLC_FLAGS="-bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable -bpf-kinsn-mode=wide-load=force"
```

## Object Coverage

```text
group	object_count	kfunc_symbol_count	arm64_symbol_count	x86_symbol_count
baseline	29	0	0	0
control-disabled	29	0	0	0
treatment-wide-load	29	26	26	0
```

Selected coverage:

```text
selected-hw:        22 benchmarks, LDRH=11 relocations, LDR_W=43 relocations
selected-wide-load: 23 benchmarks, LDRH=11, LDR_W=43, LDR_X=8
```

## Performance

Aggregate:

```text
scope	runtime	benchmarks	geomean_treatment_over_control	wins_lt_0.98	losses_gt_1.02	neutral
all	kernel	29	0.965897	7	3	19
all	native	29	1.00577	1	4	24
selected-wide-load	kernel	23	0.963069	5	2	16
selected-wide-load	native	23	1.00964	0	3	20
selected-hw	kernel	22	0.968229	4	2	16
selected-hw	native	22	1.00515	0	2	20
```

Selected-hw kernel faster rows:

```text
benchmark	control_ns	treatment_ns	treatment_over_control
packet_record_bounds_window	342	198	0.578947
trace_event_type_switch_dispatch	681	630	0.925110
bpf_local_call_fanout_dispatch	325	302	0.929231
katran_lb_consistent_hash_select	61	59	0.967213
```

Selected-hw kernel slower rows:

```text
benchmark	control_ns	treatment_ns	treatment_over_control
bpftrace_string_search_prefix_scan	512	533	1.04102
bcc_tcpconnect_ipv4_tuple_filter	319	327	1.02508
```

Selected-hw code size:

```text
metric	control_median	treatment_median	treatment_over_control
bpf_bytecode_bytes	1456	1360	0.934066
native_code_bytes	1020	948	0.929412
jited_prog_len	1020	948	0.929412
```

## AWS Cost

```text
group	instance_id	total_usd
baseline	i-0c37bdfc755e13e77	0.00324346
control-disabled	i-07d728cdcc925459c	0.00335063
treatment-wide-load	i-028f3ad153f92208f	0.00291629
TOTAL	-	0.00951037
```

价格来源：

- AWS Price List API，`AmazonEC2`，`US East (N. Virginia)`。
- `t4g.small` Linux On-Demand：`$0.0168` / hour。
- `gp3` storage：`$0.08` / GB-month。
- root volume：32 GB。

费用估算不包含 data transfer、税、free tier、credits、Savings Plans、Reserved Instances 或账户级折扣。

## Data

本目录只保存可公开查看的摘要数据：

- `data/run-contract.json`
- `data/object-symbol-summary.tsv`
- `data/treatment-relocation-counts.tsv`
- `data/selected-benchmarks.tsv`
- `data/correctness-summary.tsv`
- `data/aggregate-summary.tsv`
- `data/ratio-summary.tsv`
- `data/selected-hw-ratio-summary.tsv`
- `data/selected-hw-code-size-summary.tsv`
- `data/aws-time.tsv`
- `data/aws-cost-estimate.tsv`

完整 raw result 和 wrapper logs 在本地实验目录：

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-25-arm64-ldr-h-w-performance-attribution
```

## 后续状态

`REV+EXTR+UBFM+LDR_X+LDRH+LDR_W` combined regression 已完成：

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-25-arm64-rev-extr-ubfm-ldr-h-w-combined-regression
```

因此 `LDRH/LDR_W` 已加入 load-side selected-safe subset 的 development-complete micro
结论。`STR` design 已完成，结论是 direct-store selector 和 store-widening selector 都暂缓。
`CSEL` targeted LLVM implementation 已完成，但当前 micro 0 hit。下一步是 CSEL
coverage/correctness gate。
