# ARM64 LLVM backend: LDRH/LDR_W AWS correctness

Date: 2026-05-25.

## Conclusion

`LDRH` / `LDR_W` selected-safe subset passed AWS ARM64 correctness.

Summary:

```text
attempt	benchmarks	runtime_samples	failed_samples	status
selected-packet-record-bounds-window	1	2	0	completed
full-micro	29	58	0	completed
```

The selected benchmark was `packet_record_bounds_window` because it covers both new kfuncs:

```text
packet_record_bounds_window.bpf.o	bpf_arm64_ldr_w	6
packet_record_bounds_window.bpf.o	bpf_arm64_ldrh	2
```

This report proves runtime correctness on AWS ARM64 for `native` and `kernel` runtimes. The
follow-up same-LLC performance attribution has been completed in
`/home/ruoji/github/bpf-opt/experiments/2026-05-25-arm64-ldr-h-w-performance-attribution`.

## Current Progress

The ARM LLVM backend goal is:

```text
BPF MachineInstr pattern
  -> ARM64 kinsn pseudo
  -> KINSN_SIDECAR + KINSN_CALL bpf_arm64_*
  -> verifier proof expansion
  -> ARM64 module native lowering
```

Current family status:

| Family | Status |
|---|---|
| REV | development-complete on micro |
| EXTR | development-complete on micro |
| UBFM | development-complete on micro |
| LDR | partial; `LDR_X` and `LDRH/LDR_W` selected-safe subsets are development-complete on micro; `LDRB` normal selector is deferred |
| STR | design-complete; direct-store selector deferred |
| LDP/STP | not started |
| CSEL | design-complete; next gate is LLVM implementation |
| CCMP/CMP/CSET | not started |
| PRFM | not started |
| MOV | not started |

## Commands

Selected correctness:

```bash
cd /home/ruoji/github/bpf-opt
/home/ruoji/github/bpf-opt/aws-config/run.sh arm64 micro \
  BPFREJIT_MICRO_BPF_COMPILER=kinsn-llvm \
  BPF_KINSN_LLC="/home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn/bin/llc" \
  BPF_KINSN_LLC_FLAGS="-bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable -bpf-kinsn-mode=wide-load=force" \
  RUNTIMES="native kernel" \
  BENCH=packet_record_bounds_window \
  SAMPLES=1 WARMUPS=0 INNER_REPEAT=10000
```

Full micro correctness:

```bash
cd /home/ruoji/github/bpf-opt
/home/ruoji/github/bpf-opt/aws-config/run.sh arm64 micro \
  BPFREJIT_MICRO_BPF_COMPILER=kinsn-llvm \
  BPF_KINSN_LLC="/home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn/bin/llc" \
  BPF_KINSN_LLC_FLAGS="-bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable -bpf-kinsn-mode=wide-load=force" \
  RUNTIMES="native kernel" \
  SAMPLES=1 WARMUPS=0 INNER_REPEAT=10000
```

## Environment

| Field | Value |
|---|---|
| workspace | `/home/ruoji/github/bpf-opt` |
| code repo | `/home/ruoji/github/bpf-opt/code` |
| LLVM submodule | `/home/ruoji/github/bpf-opt/code/llvm-backend/llvm` |
| LLVM branch / HEAD | `codex/llvm-arm-backend` / `1f03d0351843bbf785a5abdf85207a9e82afc4c3` |
| custom `llc` | `/home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn/bin/llc` |
| platform / arch | `aws` / `arm64` |
| instance type | `t4g.small` |
| region | `us-east-1` |
| kernel | `7.0.0-rc2+` |
| container image | `bpf-benchmark/runner-runtime:arm64` |

## Data

Public summary data is in:

```text
/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-25/arm64-llvm-backend/ldr-h-w-aws-correctness/data
```

Included files:

```text
correctness-summary.tsv
selected-samples.tsv
selected-coverage-relocations.tsv
object-symbol-summary.tsv
arm64-wide-load-relocations.tsv
aws-time.tsv
aws-cost-estimate.tsv
```

Full raw logs and runner result copies are in:

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-25-arm64-ldr-h-w-aws-correctness
```

## AWS Cost

```text
attempt	instance_id	instance_type	aws_wall_seconds	compute_usd	ebs_usd	total_usd
selected-packet-record-bounds-window	i-05d375774d4eb9834	t4g.small	288	0.001344	0.000281	0.001625
full-micro	i-002a8c1f872a01d78	t4g.small	326	0.001521	0.000318	0.001839
total	-	-	614	0.002865	0.000598	0.003463
```

Both instances were terminated. Price source: AWS Price List API for `t4g.small` Linux On-Demand
and `gp3` in `US East (N. Virginia)`. Estimate excludes data transfer, taxes, free tier, credits,
Savings Plans, Reserved Instances, and account-level discounts.

## Next Step

`LDRH/LDR_W` same-LLC performance attribution is now complete:

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-25-arm64-ldr-h-w-performance-attribution
```

Key result: selected-hw kernel geomean treatment/control is `0.968229`; native is `1.00515`.
Combined regression was also completed:

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-25-arm64-rev-extr-ubfm-ldr-h-w-combined-regression
/home/ruoji/github/bpf-opt/code/docs/tmp/2026-05-25/arm64-llvm-backend/rev-extr-ubfm-ldr-h-w-combined-regression/report.md
```

`STR` design was completed after that and concluded that direct-store selector should stay
deferred. The next family design target is `CSEL`.

The original attribution plan was:

1. control: custom `llc` with `-bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable`.
2. treatment: custom `llc` with `all=disable` plus `wide-load=force`.
3. Report selected subset and full 29 micro separately.
