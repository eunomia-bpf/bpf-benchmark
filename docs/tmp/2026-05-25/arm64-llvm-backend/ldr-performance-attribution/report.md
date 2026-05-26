# ARM64 LLVM backend: LDR_X performance attribution

Date: 2026-05-25.

## Conclusion

This experiment evaluated the ARM64 `LDR_X` selected-safe subset in the LLVM BPF backend.

Result:

- Correctness passed: baseline, same-LLC `all=disable` control, and `LDR_X` treatment each ran
  29 micro benchmarks, `native` and `kernel` runtimes, 3 samples per benchmark/runtime, with
  0 failed samples.
- Object isolation passed: only the treatment group emitted `bpf_arm64_ldr_x`, only
  `siphash_rotate64_mixer.bpf.o` contained that symbol, and no `bpf_x86_*` symbol appeared.
- Runtime performance was neutral in the selected kernel benchmark:
  `siphash_rotate64_mixer/kernel` control median 160 ns, treatment median 163 ns,
  `treatment/control = 1.01875`.
- Code size improved in the selected kernel benchmark:
  BPF bytecode 7952 -> 6456 bytes, JIT native 4120 -> 3336 bytes.

Therefore, current `LDR_X` should be described as correctness pass + code-size reduction +
runtime neutral in this small sample. It should not be reported as a runtime performance win.

## Experiment Setup

Workspace used for the run:

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
- root volume: 32 GB gp3
- kernel: `7.0.0-rc2+`
- runtimes: `native`, `kernel`
- samples: 3
- warmups: 0
- inner repeat: 100000

## Groups

| group | compiler / flags | purpose |
|---|---|---|
| baseline | default micro build | Original clang/kernel baseline. |
| control-disabled | custom `llc`, `-bpf-kinsn-target=arm64 -bpf-kinsn-mode=all=disable` | Same-LLC denominator. |
| treatment-ldr-only | custom `llc`, `all=disable`, `wide-load=force` | Isolate `LDR_X`. |

The primary comparison is:

```text
treatment-ldr-only / control-disabled
```

## Key Data

The committed summary data is under:

```text
code/docs/tmp/2026-05-25/arm64-llvm-backend/ldr-performance-attribution/data
```

Files:

- `run-contract.json`
- `object-symbol-summary.tsv`
- `correctness-summary.tsv`
- `median-summary.tsv`
- `treatment-control-ratios.tsv`
- `aggregate-summary.tsv`
- `aws-cost-summary.tsv`
- `aws-price-summary.tsv`
- `aws-cost-total.txt`

Large raw AWS result directories are not copied into `code/docs/tmp`; the local full record is:

```text
/home/ruoji/github/bpf-opt/experiments/2026-05-25-arm64-ldr-performance-attribution
```

## Object Symbols

| group | objects | objects with kfunc | kfunc symbols | arm64 symbols | x86 symbols | ldr_x symbols | relocations |
|---|---:|---:|---:|---:|---:|---:|---:|
| baseline | 29 | 0 | 0 | 0 | 0 | 0 | 0 |
| control-disabled | 29 | 0 | 0 | 0 | 0 | 0 | 0 |
| treatment-ldr-only | 29 | 1 | 1 | 1 | 0 | 1 | 8 |

Treatment-only kfunc object:

```text
siphash_rotate64_mixer.bpf.o -> bpf_arm64_ldr_x
```

## Runtime Results

Correctness:

| group | benchmarks | samples | failed samples | runtimes |
|---|---:|---:|---:|---|
| baseline | 29 | 174 | 0 | kernel,native |
| control-disabled | 29 | 174 | 0 | kernel,native |
| treatment-ldr-only | 29 | 174 | 0 | kernel,native |

Selected benchmark:

| benchmark | runtime | control median ns | treatment median ns | treatment/control | verdict |
|---|---|---:|---:|---:|---|
| `siphash_rotate64_mixer` | kernel | 160 | 163 | 1.01875 | neutral |
| `siphash_rotate64_mixer` | native | 44 | 45 | 1.02273 | slower |

Full-suite aggregate:

| runtime | benchmarks | wins <0.98 | neutral 0.98..1.02 | losses >1.02 | geomean treatment/control |
|---|---:|---:|---:|---:|---:|
| kernel | 29 | 2 | 24 | 3 | 1.00545 |
| native | 29 | 2 | 21 | 6 | 1.00941 |

## Cost

Price source: AWS Pricing API.

| item | unit price |
|---|---:|
| EC2 `t4g.small` Linux shared `us-east-1` | `$0.0168000000/hour` |
| EBS gp3 `us-east-1` | `$0.0800000000/GB-month` |

Estimated total for the three AWS runs: `$0.008879`.

This includes EC2 compute and prorated 32 GB gp3 root EBS time. It excludes data transfer,
taxes, free tier, credits, Savings Plans, Reserved Instances, and account-level discounts.

All instances reached `terminated`; there were no active `bpf-benchmark-arm64` instances after
the runs.

## Next Step

Run `REV+EXTR+UBFM+LDR_X` combined regression. The combined report must not claim `LDR_X`
as a runtime win unless a larger follow-up experiment changes this conclusion.
