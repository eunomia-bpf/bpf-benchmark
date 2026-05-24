# ARM64 REV + EXTR + UBFM Combined Regression

Date: 2026-05-24.

## Summary

This report records the combined regression for the currently completed ARM64 kinsn families:

- `REV`
- `EXTR`
- `UBFM`

The experiment verifies object-level target isolation and AWS ARM64 runtime correctness when all
three families are enabled together.

Result:

- ARM64 `all=disable`: 29 objects, 0 kfunc externs.
- ARM64 `REV+EXTR+UBFM`: 29 objects, 21 `bpf_arm64_*` symbols, 0 `bpf_x86_*` symbols.
- Scoped x86 `unary/rotate/bextr`: 29 objects, 11 `bpf_x86_*` symbols, 0 `bpf_arm64_*` symbols.
- AWS ARM64 full micro: 29 benchmarks, `native` / `kernel`, 58 samples, 0 failed samples.
- Instance `i-00c2ef8e6b8b1f4e2` terminated.
- Estimated AWS cost: `$0.002060`.

This makes `UBFM` development-complete on the micro benchmark gate, alongside `REV` and `EXTR`.
It is not paper-grade performance data.

## Context

The ARM64 LLVM backend work extends the LLVM BPF backend. LLVM still emits BPF objects. Selected
BPF MachineInstr patterns are rewritten into ARM64 kinsn pseudos, then emitted as:

```text
KINSN_SIDECAR + KINSN_CALL bpf_arm64_*
```

The runner patches relocation type, the verifier checks proof expansion, and the ARM64 module
lowers the kinsn into native AArch64 instructions.

## Commands

ARM64 combined object smoke:

```bash
cd /home/ruoji/github/bpf-opt/code
make -C micro/programs \
  OUTPUT_DIR="/home/ruoji/github/bpf-opt/experiments/2026-05-24-arm64-rev-extr-ubfm-combined-regression/data/object-programs-arm64-rev-extr-ubfm" \
  KERNEL_OFFSETS_INPUT="/home/ruoji/github/bpf-opt/code/micro/programs/build-arm64/kernel_offsets.h" \
  BPFREJIT_MICRO_BPF_COMPILER=kinsn-llvm \
  BPF_KINSN_LLC="/home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn/bin/llc" \
  BPF_KINSN_LLC_FLAGS="-bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable -bpf-kinsn-mode=unary=force -bpf-kinsn-mode=rotate=force -bpf-kinsn-mode=bextr=force" \
  all
```

Scoped x86 object smoke:

```bash
cd /home/ruoji/github/bpf-opt/code
make -C micro/programs \
  OUTPUT_DIR="/home/ruoji/github/bpf-opt/experiments/2026-05-24-arm64-rev-extr-ubfm-combined-regression/data/object-programs-x86-scoped" \
  KERNEL_OFFSETS_INPUT="/home/ruoji/github/bpf-opt/code/micro/programs/build-arm64/kernel_offsets.h" \
  BPFREJIT_MICRO_BPF_COMPILER=kinsn-llvm \
  BPF_KINSN_LLC="/home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn/bin/llc" \
  BPF_KINSN_LLC_FLAGS="-bpf-kinsn-target=x86 -bpf-kinsn-mode=all=disable -bpf-kinsn-mode=unary=force -bpf-kinsn-mode=rotate=force -bpf-kinsn-mode=bextr=force" \
  all
```

AWS ARM64 full micro:

```bash
cd /home/ruoji/github/bpf-opt
QEMU_LD_PREFIX=/usr/aarch64-linux-gnu /home/ruoji/github/bpf-opt/aws-config/run.sh arm64 micro \
  BPFREJIT_MICRO_BPF_COMPILER=kinsn-llvm \
  BPF_KINSN_LLC="/home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn/bin/llc" \
  BPF_KINSN_LLC_FLAGS="-bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable -bpf-kinsn-mode=unary=force -bpf-kinsn-mode=rotate=force -bpf-kinsn-mode=bextr=force" \
  RUNTIMES="native kernel" \
  SAMPLES=1 WARMUPS=0 INNER_REPEAT=10000
```

## Object Results

```text
attempt                 objects  kfunc_extern_objects  kfunc_symbols  arm64_symbols  x86_symbols  arm64_rev_symbols  arm64_extr_symbols  arm64_ubfm_symbols
arm64-all-disable       29       0                     0              0              0            0                  0                   0
arm64-rev-extr-ubfm     29       16                    21             21             0            2                  7                   12
x86-scoped              29       9                     11             0              11           0                  0                   0
```

Complete TSV data:

```text
data/object-symbol-summary.tsv
data/object-relocations.tsv
```

## Runtime Results

```text
attempt          status     benchmarks  samples  failed_samples  kernel      generated_at
aws-full-micro   completed  29          58       0               7.0.0-rc2+  2026-05-24T10:07:20.242964+00:00
```

Complete sample TSV:

```text
data/sample-summary.tsv
```

## AWS Cost

```text
instance id    i-00c2ef8e6b8b1f4e2
instance type  t4g.small
final state    terminated
total cost     $0.002060
```

Assumptions:

- EC2 on-demand `t4g.small` Linux in US East (N. Virginia): `$0.0168000000` / hour.
- EBS gp3 in US East (N. Virginia): `$0.0800000000` / GB-month.
- Root volume: 32 GB.
- Does not include data transfer, tax, free tier, credits, Savings Plans, Reserved Instances, or
  account-level discounts.

## Next

The next step is not another direct implementation. The next step is a design pass for the next
family, likely direct load/store, based on the ARM64 module decoder ABI and verifier safety
constraints.
