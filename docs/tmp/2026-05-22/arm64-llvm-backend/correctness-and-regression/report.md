# ARM64 LLVM Backend Correctness And Regression

## Summary

The ARM64 `REV` and `EXTR` implementation passes the current local LLVM checks,
AWS ARM64 full micro correctness smoke, and target-isolation object checks.

Key results:

- LLVM `llc` and `FileCheck` build completed.
- Targeted `llc | FileCheck` checks for x86 default target, ARM64 target,
  ARM64 pseudos, ARM64 `REV`, and ARM64 `EXTR` all passed.
- AWS ARM64 correctness smoke completed for `REV` only, `EXTR` only, and
  `REV+EXTR`.
- ARM64 `REV+EXTR` object generation produced 29 objects with 9
  `bpf_arm64_*` symbols and 0 `bpf_x86_*` symbols.
- The `all=disable` control generated 29 objects with 0 kfunc externs.
- Scoped x86 `unary/rotate` generation still produced 29 objects with
  `bpf_x86_*` symbols only.

## LLVM Checks

Commands were run from:

```text
/home/ruoji/github/bpf-opt
```

Build:

```bash
ninja -C code/llvm-backend/build-bpf-kinsn llc FileCheck
```

Targeted checks:

```bash
code/llvm-backend/build-bpf-kinsn/bin/llc -mtriple=bpfel -mcpu=v4 \
  -verify-machineinstrs -bpf-enable-kinsn-select \
  -bpf-kinsn-mode=unary=force \
  < code/llvm-backend/llvm/llvm/test/CodeGen/BPF/kinsn-target.ll \
  | code/llvm-backend/build-bpf-kinsn/bin/FileCheck \
      code/llvm-backend/llvm/llvm/test/CodeGen/BPF/kinsn-target.ll \
      --check-prefix=X86

code/llvm-backend/build-bpf-kinsn/bin/llc -mtriple=bpfel -mcpu=v4 \
  -verify-machineinstrs -bpf-enable-kinsn-select \
  -bpf-kinsn-target=arm64 -bpf-kinsn-mode=unary=force \
  < code/llvm-backend/llvm/llvm/test/CodeGen/BPF/kinsn-target.ll \
  | code/llvm-backend/build-bpf-kinsn/bin/FileCheck \
      code/llvm-backend/llvm/llvm/test/CodeGen/BPF/kinsn-target.ll \
      --check-prefix=ARM64

code/llvm-backend/build-bpf-kinsn/bin/llc -mtriple=bpfel -mcpu=v4 \
  -x mir code/llvm-backend/llvm/llvm/test/CodeGen/BPF/kinsn-arm64-pseudos.mir \
  -o - \
  | code/llvm-backend/build-bpf-kinsn/bin/FileCheck \
      code/llvm-backend/llvm/llvm/test/CodeGen/BPF/kinsn-arm64-pseudos.mir

code/llvm-backend/build-bpf-kinsn/bin/llc -mtriple=bpfel -mcpu=v4 \
  -verify-machineinstrs -bpf-enable-kinsn-select \
  -bpf-kinsn-target=arm64 -bpf-kinsn-mode=unary=force \
  < code/llvm-backend/llvm/llvm/test/CodeGen/BPF/kinsn-arm64-rev-select.ll \
  | code/llvm-backend/build-bpf-kinsn/bin/FileCheck \
      code/llvm-backend/llvm/llvm/test/CodeGen/BPF/kinsn-arm64-rev-select.ll

code/llvm-backend/build-bpf-kinsn/bin/llc -mtriple=bpfel -mcpu=v4 \
  -verify-machineinstrs -bpf-enable-kinsn-select \
  -bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable \
  -bpf-kinsn-mode=rotate=force \
  < code/llvm-backend/llvm/llvm/test/CodeGen/BPF/kinsn-arm64-extr-select.ll \
  | code/llvm-backend/build-bpf-kinsn/bin/FileCheck \
      code/llvm-backend/llvm/llvm/test/CodeGen/BPF/kinsn-arm64-extr-select.ll
```

Result summary:

```text
data/filecheck-summary.txt
```

## AWS ARM64 Correctness Smoke

The correctness smoke ran on AWS ARM64 `t4g.small`, region `us-east-1`, with
kernel `7.0.0-rc2+` and runtime container `bpf-benchmark/runner-runtime:arm64`.

Runtime set:

```text
native kernel
```

Sample configuration:

```text
SAMPLES=1 WARMUPS=0 INNER_REPEAT=10000
```

Summary:

```text
attempt    benchmarks  runs  failed_samples  status     object_count  kfunc_symbols  arm64_rev_symbols  arm64_extr_symbols  x86_symbols
rev-only   29          58    0               completed  29            2              2                  0                   0
extr-only  29          58    0               completed  29            7              0                  7                   0
rev-extr   29          58    0               completed  29            9              2                  7                   0
```

The copied data is in:

```text
data/aws-correctness-summary.tsv
data/aws-correctness-cost-summary.tsv
data/aws-correctness-cost-total.txt
```

## Object-Level Regression

Object generation was run through Makefile entry points. The regression check
answers two questions:

- ARM64 target must not emit `bpf_x86_*`.
- The same custom `llc` with `all=disable` must still be a no-kinsn control.

Summary:

```text
case                      objects  kfunc symbols  arm64 symbols  x86 symbols  status
micro-x86-default-kinsn   18       62             0              62           failed
micro-x86-scoped-kinsn    29       9              0              9            completed
micro-arm64-all-disable   29       0              0              0            completed
micro-arm64-rev-extr      29       9              9              0            completed
```

The default x86 broad-policy failure is a known x86 selector issue, not an
ARM64 target leak. The scoped x86 check disables all families first and then
forces only `unary/rotate`; that path passes and emits only `bpf_x86_*`.

Copied object data:

```text
data/check-summary.tsv
data/object-symbol-summary.tsv
data/micro-arm64-all-disable.kfunc-symbols.tsv
data/micro-arm64-rev-extr.kfunc-symbols.tsv
data/micro-x86-scoped-kinsn.kfunc-symbols.tsv
data/micro-x86-default-kinsn.kfunc-symbols.tsv
```

## Known X86 Issue

The x86 broad default object smoke fails on `packet_vlan_tcpopt_parser` when the
existing broad x86 policy set is enabled. The failure is:

```text
BPFInstrInfo.cpp:44: Impossible reg-to-reg copy
```

Bisection points to the `movbe-be` family. The failing MIR contains an
unsupported physical-register class copy around `BPF_KINSN_X86_MOVBE16`:

```text
$r3 = COPY killed $w3
$r3 = BPF_KINSN_X86_MOVBE16 killed $r3, $r2, 26
```

The family bisection data is in:

```text
data/x86-broad-family-bisect.tsv
```

This should be fixed as a separate x86 selector bug. It is not evidence that
ARM64 generation leaks x86 kfuncs.

