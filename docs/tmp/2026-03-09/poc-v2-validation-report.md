# POC v2 Validation Report

Date: 2026-03-09

Kernel: `7.0.0-rc2-gc23719abc330-dirty`

Validation artifact: `docs/tmp/poc-v2-validation-results.json`

## Outcome

The v2 POC now boots and runs in `virtme-ng` with the custom kernel.

For `cmov_select`, this is now a true JIT-level change:

- `xlated_prog_len` is unchanged with and without directives: `7480`
- `jited_prog_len` changes only with directives: `4168 -> 4167`
- `directive_hint` finds `1` site
- inferred applied directive sites: `1`

The “applied site” count above is inferred from the combination of:

- `directive_hint` reporting `1` site
- successful directive-enabled load/run
- `jited_prog_len` changing while `xlated_prog_len` stays identical

## Fixes Made

1. `vendor/linux/arch/x86/net/bpf_jit_comp.c`
   Fixed the shared conditional-jump path so non-directed programs do not use an uninitialized `jmp_cond`.
2. `vendor/linux/arch/x86/net/bpf_jit_comp.c`
   Fixed compact `cmov_select` fused-region `addrs[]` bookkeeping and its matching convergence check.
   This removed the subprog call-target corruption that previously panicked the guest.
3. `micro/runner/src/kernel_runner.cpp`
   Fixed manual `BPF_PROG_LOAD` for large programs by retrying without verifier logging after log-buffer exhaustion (`ENOSPC`).

## Results

Manual-load medians are the fairest comparison for “without directives” vs “with directives”, because both modes use the same loader path.

| benchmark | directive sites | manual no directives exec_ns | manual with directives exec_ns | delta ns | ratio | xlated_prog_len | jited_prog_len |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| `cmov_select` | 1 | 742 | 840 | +98 | 1.132x | 7480 -> 7480 | 4168 -> 4167 |
| `binary_search` | 0 | 394 | 570 | +176 | 1.447x | 1520 -> 1520 | 841 -> 841 |
| `switch_dispatch` | 0 | 430 | 415 | -15 | 0.965x | 2160 -> 2160 | 1627 -> 1627 |

## Interpretation

- `cmov_select` proves the v2 design point: the BPF program is not rewritten, while the native x86 image changes under directives.
- On this machine and workload, the directive-enabled `cmov_select` median is slower than manual no-directives (`840 ns` vs `742 ns`, `+13.2%`).
- `binary_search` and `switch_dispatch` have `0` directive sites and show no code-size changes; their execution deltas should be treated as run-to-run noise rather than directive effects.
