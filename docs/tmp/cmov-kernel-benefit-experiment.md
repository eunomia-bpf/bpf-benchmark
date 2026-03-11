# CMOV Kernel Benefit Experiment

**Date:** 2026-03-11

## Goal

Try to close the paper gap "CMOV is beneficial on unpredictable branches in the kernel JIT" using the existing kernel recompile path on:

- `switch_dispatch`
- `binary_search`
- `bounds_ladder`

## 1. Current Framework State

- Host kernel from `uname -r`: `6.15.11-061511-generic`
- Host is **not** the custom v4 recompile kernel.
- A VM boot path is available locally:
  - image: `vendor/linux/arch/x86/boot/bzImage`
  - guest `uname -r`: `7.0.0-rc2-g1572a4ddb52b-dirty`
- The current `vendor/linux` branch is `jit-fixed-baselines`, but the checked-in `.config` has all fixed-heuristic options disabled:
  - `CONFIG_BPF_JIT_FIXED_ROTATE=n`
  - `CONFIG_BPF_JIT_FIXED_WIDE_MEM=n`
  - `CONFIG_BPF_JIT_FIXED_LEA=n`
  - `CONFIG_BPF_JIT_FIXED_CMOV=n`
- So this VM image is usable as a stock-JIT kernel that still supports `BPF_PROG_JIT_RECOMPILE`.

### Sanity Check: Recompile Path Really Works

I booted the VM image and ran `log2_fold` with `--compile-only --recompile-cmov`.

Observed:

- `cmov_sites = 6`
- `policy_generated = true`
- `syscall_attempted = true`
- `applied = true`
- `jited_prog_len 648 -> 682`

So the kernel-side recompile path is live; the problem is not "missing syscall support."

## 2. Fresh VM Results On The Three Target Benchmarks

Command shape used:

```bash
vng --run vendor/linux/arch/x86/boot/bzImage \
  --cwd /home/yunwei37/workspace/bpf-benchmark \
  --exec "micro/build/runner/micro_exec run-kernel --program ... \
    --memory ... --input-size ... --io-mode staged --repeat 1000 [--recompile-cmov]"
```

### Fresh live measurements

| Benchmark | Stock `exec_ns` | `--recompile-cmov` `exec_ns` | `cmov_sites` | `policy_generated` | `syscall_attempted` | `jited_prog_len` before/after |
| --- | ---: | ---: | ---: | :---: | :---: | ---: |
| `switch_dispatch` | 369 | 293 | 0 | no | no | `1627 -> 1627` |
| `binary_search` | 585 | 596 | 0 | no | no | `841 -> 841` |
| `bounds_ladder` | 234 | 215 | 0 | no | no | `844 -> 844` |

Interpretation:

- All three `--recompile-cmov` runs were **no-ops**.
- No policy blob was generated, so `BPF_PROG_JIT_RECOMPILE` was never called.
- Native code size did not change.
- Therefore the `exec_ns` movement above is only VM measurement noise, not CMOV profitability evidence.

### Statistical significance

- Not measured.
- These are single VM point measurements with `--repeat 1000`, but no outer repetition / hypothesis test.
- Since no recompile was actually applied, significance testing would not answer the paper question anyway.

## 3. Existing v4 Result Files

### `micro/results/v4_new_directives_test.json`

Archived v4 data from the custom `7.0.0-rc2` recompile kernel shows the same pattern:

| Benchmark | Baseline `exec_ns` | Recompile `exec_ns` | Delta | `cmov_sites` | `bpf_prog_jit_recompile_called` | `jited_prog_len` before/after |
| --- | ---: | ---: | ---: | ---: | :---: | ---: |
| `switch_dispatch` | 196 | 222 | `+13.3%` | 0 | no | `1627 -> 1627` |
| `binary_search` | 383 | 362 | `-5.5%` | 0 | no | `841 -> 841` |
| `bounds_ladder` | 125 | 127 | `+1.6%` | 0 | no | `844 -> 844` |

These archived numbers agree with the fresh VM runs:

- zero CMOV coverage
- no actual recompile
- unchanged native code size
- runtime deltas are not attributable to CMOV

### `micro/results/v4_recompile_comprehensive.json`

This file does **not** provide a beneficial unpredictable-branch kernel-JIT CMOV case.

What it does show:

- `log2_fold`: `sites_found = 6`, recompile applied, and CMOV is harmful (`+24%` to `+28%`)
- `cmov_select`: `sites_found = 1`, but only marginal/noisy movement (`~2%`)

What it does **not** show:

- any positive CMOV result for `switch_dispatch`
- any positive CMOV result for `binary_search`
- any positive CMOV result for `bounds_ladder`

### `docs/tmp/v4-round3-test-results.md`

Round 3 is useful as evidence that the v4 framework is functional, but it still does not close the CMOV-benefit gap:

- it demonstrates active `ROTATE` and `WIDE_MEM`
- it still reports no usable CMOV benefit case for the unpredictable-branch benchmarks

## 4. Extra Check: v5 Path

I also booted `vendor/linux-framework/arch/x86/boot/bzImage` and probed the same three benchmarks with:

```bash
--recompile-v5 --recompile-cmov
```

Result:

- `switch_dispatch`: `cmov_sites = 0`
- `binary_search`: `cmov_sites = 0`
- `bounds_ladder`: `cmov_sites = 0`

So this is not just a host-kernel mismatch. Even the newer v5 userspace pattern path still does not cover these three targets.

## 5. Why The Gap Remains

Inference from the benchmark sources plus the zero-site scans:

- current `COND_SELECT` only rewrites BPF **select idioms** that match the scanner's compact/diamond patterns
- `switch_dispatch` is a real `switch` dispatch benchmark
- `binary_search` is a loop with control-flow updates to `found/index`
- `bounds_ladder` is an if/else ladder over record fields

These are certainly unpredictable-branch workloads, but they are **not currently exposed to the kernel recompiler as matched COND_SELECT sites**. The framework cannot apply a CMOV policy where the scanner finds no site.

So the blocker is now clear:

- not the kernel
- not the VM
- not the syscall
- **the COND_SELECT coverage / pattern vocabulary**

## 6. What Needs To Happen Next

To actually close the paper gap, one of the following must happen:

1. Extend the `COND_SELECT` scanner/pattern language so it matches the xlated BPF shapes produced by `switch_dispatch`, `binary_search`, or `bounds_ladder`.
2. Or introduce a broader control-flow-to-select lowering than the current compact/diamond select matcher.
3. Then rerun until at least one unpredictable-branch benchmark shows all of:
   - `cmov_sites > 0`
   - `policy_generated = true`
   - `syscall_attempted = true`
   - changed `jited_prog_len`
   - reproducible `exec_ns` improvement over stock
4. After that, collect outer repetitions and do a real significance test.

## Bottom Line

- The kernel-JIT recompile framework is available locally and works end-to-end in the VM.
- The requested CMOV-benefit experiment on `switch_dispatch`, `binary_search`, and `bounds_ladder` still cannot be demonstrated.
- Existing v4 result files also contain **no** kernel-JIT CMOV benefit case for those benchmarks.
- Therefore this session does **not** close the "CMOV benefit in kernel JIT" gap.
- The immediate next blocker is **COND_SELECT scanner coverage**, not VM setup.
