# ARM64 LLVM backend: REV+EXTR+UBFM+LDR_X combined regression

Date: 2026-05-25.

## Conclusion

This experiment enabled the currently completed ARM64 subsets together:

```text
REV + EXTR + UBFM + LDR_X
```

Result:

- Object isolation passed.
- AWS ARM64 full micro correctness passed.
- No ARM64/x86 target leakage was observed.
- `LDR_X` selected-safe subset can now be described as development-complete on micro.
- The whole `LDR` family remains partial because `LDRB`, `LDRH`, and `LDR_W` are not implemented.

This is a correctness/regression gate, not a paper-grade performance experiment. It does not
change the previous `LDR_X` performance conclusion: `LDR_X` reduced code size in the selected
benchmark, but runtime was neutral in the small sample.

## Experiment Setup

Workspace:

```text
/home/ruoji/github/bpf-opt
```

Code repo:

```text
/home/ruoji/github/bpf-opt/code
```

LLVM submodule:

```text
/home/ruoji/github/bpf-opt/code/llvm-backend/llvm
```

Custom `llc`:

```text
/home/ruoji/github/bpf-opt/code/llvm-backend/build-bpf-kinsn/bin/llc
```

AWS:

- arch: ARM64
- region: `us-east-1`
- instance type: `t4g.small`
- kernel: `7.0.0-rc2+`
- runtimes: `native`, `kernel`
- samples: 1
- warmups: 0
- inner repeat: 10000

## Object Isolation

| attempt | objects | kfunc symbols | arm64 symbols | x86 symbols | REV | EXTR | UBFM | LDR_X |
|---|---:|---:|---:|---:|---:|---:|---:|---:|
| arm64-all-disable | 29 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| arm64-rev-extr-ubfm-ldr | 29 | 22 | 22 | 0 | 2 | 7 | 12 | 1 |
| x86-scoped | 29 | 37 | 0 | 37 | 0 | 0 | 0 | 0 |

ARM64 combined relocations include:

```text
siphash_rotate64_mixer.bpf.o -> bpf_arm64_extr_x, bpf_arm64_ldr_x
```

The `LDR_X` symbol appears only in `siphash_rotate64_mixer.bpf.o`.

## AWS Correctness

| attempt | status | benchmarks | samples | failed samples | kernel | runtimes |
|---|---|---:|---:|---:|---|---|
| aws-full-micro | completed | 29 | 58 | 0 | 7.0.0-rc2+ | kernel,native |

## Cost

Price source: AWS Pricing API.

| item | unit price |
|---|---:|
| EC2 `t4g.small` Linux shared `us-east-1` | `$0.0168000000/hour` |
| EBS gp3 `us-east-1` | `$0.0800000000/GB-month` |

Estimated total: `$0.001907`.

This includes EC2 compute and prorated 32 GB gp3 root EBS time. It excludes data transfer,
taxes, free tier, credits, Savings Plans, Reserved Instances, and account-level discounts.

The AWS instance reached `terminated`; there were no active `bpf-benchmark-arm64` instances after
the run.

## Data

Summary data prepared for the code repository:

```text
code/docs/tmp/2026-05-25/arm64-llvm-backend/rev-extr-ubfm-ldr-combined-regression/data
```

Files:

- `run-contract.json`
- `object-symbol-summary.tsv`
- `object-relocations.tsv`
- `run-result-summary.tsv`
- `sample-summary.tsv`
- `selected-kfunc-code-size.tsv`
- `aws-cost-summary.tsv`
- `aws-price-summary.tsv`
- `aws-cost-total.txt`

Full local experiment record:

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-25-arm64-rev-extr-ubfm-ldr-combined-regression
```

## Next Step

The next recommended step is to design `LDRB` / `LDRH` / `LDR_W`.

That design should first read `/home/ruoji/github/bpf-opt/code/module/arm64/bpf_arm64_ldr.c`,
record payload constraints, offset encoding, verifier proof expansion, and then check whether the
current micro LLVM IR has stable byte / half / word load patterns. If the patterns are not stable,
record that and do not guess a selector.

Do not treat `LDR_X` as a runtime performance win unless a larger follow-up experiment changes
the current attribution result.
