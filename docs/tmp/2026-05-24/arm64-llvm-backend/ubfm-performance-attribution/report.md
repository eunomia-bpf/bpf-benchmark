# ARM64 UBFM Performance Attribution

Date: 2026-05-24.

## Summary

This report records the development-grade performance attribution for the ARM64 `UBFM`
kinsn family in the LLVM BPF backend.

The experiment compares three AWS ARM64 full micro runs:

| group | setup | benchmarks | samples | failed samples |
|---|---|---:|---:|---:|
| `baseline` | ordinary clang | 29 | 174 | 0 |
| `control-disabled` | custom `llc`, ARM64 target, `all=disable` | 29 | 174 | 0 |
| `treatment-ubfm-only` | custom `llc`, ARM64 target, `all=disable`, `bextr=force` | 29 | 174 | 0 |

The main attribution comparison is:

```text
treatment-ubfm-only / control-disabled
```

Key result:

- `treatment-ubfm-only` emitted only `bpf_arm64_ubfm_x`; no `bpf_x86_*` symbols were emitted.
- `UBFM` appeared in 12 of 29 micro objects, with 38 relocations.
- Full-suite median treatment/control:
  - `native`: `1.000000`
  - `kernel`: `0.999758`
- Selected 12-benchmark median treatment/control:
  - `native`: `1.000000`
  - `kernel`: `0.996766`
- The clearest selected kernel improvement was `packed_header_bitfield_decode`:
  - control `936 ns`
  - treatment `903 ns`
  - treatment/control `0.964744`

This supports the conclusion that `UBFM` is correct and can provide localized benefit on
bitfield-heavy cases. It does not support a claim of significant full-suite improvement.
This is not paper-grade performance data because it uses `SAMPLES=3` and no confidence interval.

## Context

The ARM64 LLVM backend work is not a normal AArch64 backend. LLVM still emits BPF object files.
For selected BPF MachineInstr patterns, the BPF backend emits:

```text
KINSN_SIDECAR + KINSN_CALL bpf_arm64_*
```

The runner patches the relocation as a kinsn call, the verifier checks the proof expansion, and
the ARM64 module lowers the kinsn into native AArch64 instructions.

For `UBFM`, the target kfunc is:

```text
bpf_arm64_ubfm_x
```

The logical policy key used by the current selector is:

```text
-bpf-kinsn-mode=bextr=force
```

Under ARM64 target, this selects `BPF_KINSN_ARM64_UBFM_X` for low-mask bitfield extract patterns.

## Commands

All benchmark runs were executed through the AWS wrapper / Makefile entry path.

Baseline:

```bash
cd /home/ruoji/github/bpf-opt
QEMU_LD_PREFIX=/usr/aarch64-linux-gnu /home/ruoji/github/bpf-opt/aws-config/run.sh arm64 micro \
  RUNTIMES="native kernel" SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000
```

Control:

```bash
cd /home/ruoji/github/bpf-opt
QEMU_LD_PREFIX=/usr/aarch64-linux-gnu /home/ruoji/github/bpf-opt/aws-config/run.sh arm64 micro \
  BPFREJIT_MICRO_BPF_COMPILER=kinsn-llvm \
  BPF_KINSN_LLC="/home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn/bin/llc" \
  BPF_KINSN_LLC_FLAGS="-bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable" \
  RUNTIMES="native kernel" SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000
```

Treatment:

```bash
cd /home/ruoji/github/bpf-opt
QEMU_LD_PREFIX=/usr/aarch64-linux-gnu /home/ruoji/github/bpf-opt/aws-config/run.sh arm64 micro \
  BPFREJIT_MICRO_BPF_COMPILER=kinsn-llvm \
  BPF_KINSN_LLC="/home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn/bin/llc" \
  BPF_KINSN_LLC_FLAGS="-bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable -bpf-kinsn-mode=bextr=force" \
  RUNTIMES="native kernel" SAMPLES=3 WARMUPS=0 INNER_REPEAT=100000
```

## Environment

| field | value |
|---|---|
| workspace | `/home/ruoji/github/bpf-opt` |
| code repo | `/home/ruoji/github/bpf-opt/code` |
| LLVM submodule | `/home/ruoji/github/bpf-opt/code/llvm-backend/llvm` |
| code branch | `codex/llvm-arm-backend` |
| LLVM branch | `codex/llvm-arm-backend` |
| code HEAD | `6e12532a2b2c8eaebb2e9f34a5fe63e318e55553` |
| LLVM HEAD | `d30b7118fb949879b5300a312fff8d16dd40756e` |
| platform | AWS |
| arch | arm64 |
| region | `us-east-1` |
| instance type | `t4g.small` |
| kernel | `7.0.0-rc2+` |
| runtime container | `bpf-benchmark/runner-runtime:arm64` |
| runtimes | `native kernel` |

## Object Coverage

```text
attempt              objects  kfunc_extern_objects  kfunc_symbols  arm64_ubfm_symbols  arm64_symbols  x86_symbols  status
baseline             29       0                     0              0                   0              0            completed
control-disabled     29       0                     0              0                   0              0            completed
treatment-ubfm-only  29       12                    12             12                  12             0            completed
```

Selected UBFM objects:

```text
bcc_runqlat_log2_histogram_bucket.bpf.o  1
bcc_tcpconnect_ipv4_tuple_filter.bpf.o   2
bitmap_popcount_scan.bpf.o               1
bpftrace_comm_key_fnv_hash.bpf.o         1
cgroup_skb_hash_chain.bpf.o              2
cilium_socket_lb_service_select.bpf.o    2
flow_5tuple_rss_hash.bpf.o               2
flow_record_field_scan.bpf.o             1
katran_lb_consistent_hash_select.bpf.o   11
otel_stack_frame_unwind_scan.bpf.o       1
packed_header_bitfield_decode.bpf.o      13
packet_vlan_tcpopt_parser.bpf.o          1
```

## Performance

```text
treatment  scope     runtime  benchmarks  median_treatment_over_control  wins_lt_0.98  losses_gt_1.02  neutral
ubfm       all       native   29          1.000000                       2             2               25
ubfm       all       kernel   29          0.999758                       5             4               20
ubfm       selected  native   12          1.000000                       1             1               10
ubfm       selected  kernel   12          0.996766                       1             0               11
```

Key selected kernel rows:

```text
benchmark                          control_ns  treatment_ns  treatment/control  relocations
bpftrace_comm_key_fnv_hash         1679        1656          0.986301           1
cgroup_skb_hash_chain              1047        1039          0.992359           2
packed_header_bitfield_decode      936         903           0.964744           13
```

Complete TSV data is in:

```text
data/run-result-summary.tsv
data/object-symbol-summary.tsv
data/object-relocations.tsv
data/perf-directional-summary.tsv
data/perf-selected-kfunc-benchmarks.tsv
data/aws-cost-summary.tsv
data/aws-cost-total.txt
```

## AWS Cost

All three instances reached `terminated`. Active experiment instance count after the runs was `0`.

Estimated cost:

```text
baseline              $0.003078
control-disabled      $0.003068
treatment-ubfm-only   $0.003009
total                 $0.009155
```

Assumptions:

- EC2 on-demand `t4g.small` Linux in US East (N. Virginia): `$0.0168000000` / hour.
- EBS gp3 in US East (N. Virginia): `$0.0800000000` / GB-month.
- Root volume: 32 GB.
- Does not include data transfer, tax, free tier, credits, Savings Plans, Reserved Instances, or
  account-level discounts.

## Next

The next development step is a combined `REV+EXTR+UBFM` regression:

1. Build full 29 micro objects with all three completed families enabled.
2. Verify no `bpf_x86_*` appears in ARM64 treatment.
3. Run AWS ARM64 correctness / performance smoke with `RUNTIMES="native kernel"`.
4. Keep scoped x86 target-isolation check separate because broad default x86 policy has a known
   independent selector issue.
