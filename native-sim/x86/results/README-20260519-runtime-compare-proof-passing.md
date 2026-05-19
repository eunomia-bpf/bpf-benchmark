# ReverseSim x86 proof-passing runtime comparison

Scope:

- Proof source state: restored to the current 29/29 proof-passing micro source shape.
- Proof recheck: `native-sim/x86/results/README-20260519-proof-recheck-29of29.md`.
- Runtime command:

```bash
make micro BENCH="payload_prefix_memcmp_scan tetragon_process_event_arg_filter" \
  RUNTIMES="native llvmbpf kernel native_lab" \
  SAMPLES=1 WARMUPS=0 INNER_REPEAT=100000
```

Micro result:

- `micro/results/x86_kvm_micro_20260519_213344_357618/metadata.json`

The four runtime names are the runtime modes defined by
`micro/config/micro_pure_jit.yaml`: `native`, `llvmbpf`, `kernel`, and
`native_lab`. `micro_stage2.yaml` only defines `kernel` and `native_lab`, which
are included here.

| Micro program | Runtime | Compile ns | Exec ns | Result | Retval | Native code bytes | BPF bytecode bytes |
| --- | --- | ---: | ---: | ---: | ---: | ---: | ---: |
| `payload_prefix_memcmp_scan` | `native` | 52122 | 48 | 9377358970524074984 | 2 | 548 | 0 |
| `payload_prefix_memcmp_scan` | `llvmbpf` | 10383894 | 72 | 9377358970524074984 | 2 | 492 | 1136 |
| `payload_prefix_memcmp_scan` | `kernel` | 789995 | 83 | 9377358970524074984 | 2 | 606 | 1136 |
| `payload_prefix_memcmp_scan` | `native_lab` | 112239488 | 51 | 9377358970524074984 | 2 | 528 | 0 |
| `tetragon_process_event_arg_filter` | `native` | 49826 | 114 | 12641586655603153431 | 2 | 870 | 0 |
| `tetragon_process_event_arg_filter` | `llvmbpf` | 14981566 | 132 | 12641586655603153431 | 2 | 927 | 2336 |
| `tetragon_process_event_arg_filter` | `kernel` | 9590857 | 163 | 12641586655603153431 | 2 | 1295 | 2336 |
| `tetragon_process_event_arg_filter` | `native_lab` | 120014671 | 116 | 12641586655603153431 | 2 | 810 | 0 |

All eight runs produced the expected benchmark result and retval. This is a
single-sample runtime check, not an analysis-side aggregate.

Percentage view:

- `vs kernel` means `(kernel_exec_ns - runtime_exec_ns) / kernel_exec_ns`.
  Positive means faster than kernel eBPF.
- `vs native` means `(runtime_exec_ns - native_exec_ns) / native_exec_ns`.
  Positive means overhead over direct native.

| Micro program | Runtime | Exec ns | vs kernel | Runtime / kernel | vs native |
| --- | --- | ---: | ---: | ---: | ---: |
| `payload_prefix_memcmp_scan` | `native` | 48 | +42.2% | 0.578x | +0.0% |
| `payload_prefix_memcmp_scan` | `llvmbpf` | 72 | +13.3% | 0.867x | +50.0% |
| `payload_prefix_memcmp_scan` | `kernel` | 83 | +0.0% | 1.000x | +72.9% |
| `payload_prefix_memcmp_scan` | `native_lab` | 51 | +38.6% | 0.614x | +6.2% |
| `tetragon_process_event_arg_filter` | `native` | 114 | +30.1% | 0.699x | +0.0% |
| `tetragon_process_event_arg_filter` | `llvmbpf` | 132 | +19.0% | 0.810x | +15.8% |
| `tetragon_process_event_arg_filter` | `kernel` | 163 | +0.0% | 1.000x | +43.0% |
| `tetragon_process_event_arg_filter` | `native_lab` | 116 | +28.8% | 0.712x | +1.8% |

## Compared With The Previous Proof-Failing Shape

The previous shape failed the ReverseSim proof load for these two programs, so
there is no valid `native_lab` runtime for it. The useful comparisons are:

- native runtime of old proof-failing source vs current proof-passing source;
- proof artifact size/compile cost before and after the source shaping.

Native runtime comparison, both with `SAMPLES=1 WARMUPS=0 INNER_REPEAT=10`:

- old proof-failing source:
  `micro/results/x86_kvm_micro_20260519_180639_651469/metadata.json`
- current proof-passing source:
  `micro/results/x86_kvm_micro_20260519_211116_300331/metadata.json`

| Micro program | Metric | Proof-failing source | Proof-passing source | Delta |
| --- | --- | ---: | ---: | ---: |
| `payload_prefix_memcmp_scan` | native exec ns | 155 | 157 | +1.3% |
| `payload_prefix_memcmp_scan` | native code bytes | 510 | 548 | +7.5% |
| `payload_prefix_memcmp_scan` | native compile ns | 56014 | 61494 | +9.8% |
| `tetragon_process_event_arg_filter` | native exec ns | 339 | 370 | +9.1% |
| `tetragon_process_event_arg_filter` | native code bytes | 802 | 870 | +8.5% |
| `tetragon_process_event_arg_filter` | native compile ns | 50049 | 65665 | +31.2% |

Proof artifact comparison:

- old proof-failing source:
  `native-sim/x86/results/README-20260519-182500-full-min-cond.md`
- current proof-passing source:
  `native-sim/x86/results/README-20260519-185000-full-29of29.md`

| Micro program | Metric | Proof-failing source | Proof-passing source | Delta |
| --- | --- | ---: | ---: | ---: |
| `payload_prefix_memcmp_scan` | proof status | fail | ok | fixed |
| `payload_prefix_memcmp_scan` | proof compile s | 2.829 | 2.859 | +1.1% |
| `payload_prefix_memcmp_scan` | proof BPF insns | 228 | 344 | +50.9% |
| `tetragon_process_event_arg_filter` | proof status | fail | ok | fixed |
| `tetragon_process_event_arg_filter` | proof compile s | 4.576 | 4.656 | +1.7% |
| `tetragon_process_event_arg_filter` | proof BPF insns | 301 | 303 | +0.7% |

## Did The Native-vs-eBPF Gain Shrink?

For this question, compare direct native against kernel eBPF in runs that have
both runtimes and use the same `INNER_REPEAT=100000` setting:

- proof-failing source:
  `micro/results/x86_kvm_micro_20260519_122043_563807/metadata.json`
- proof-passing source:
  `micro/results/x86_kvm_micro_20260519_213344_357618/metadata.json`

| Micro program | Source shape | Native exec ns | Kernel eBPF exec ns | Native / kernel | Native gain vs kernel |
| --- | --- | ---: | ---: | ---: | ---: |
| `payload_prefix_memcmp_scan` | proof-failing | 49 | 112 | 0.438x | +56.2% |
| `payload_prefix_memcmp_scan` | proof-passing | 48 | 83 | 0.578x | +42.2% |
| `tetragon_process_event_arg_filter` | proof-failing | 107 | 139 | 0.770x | +23.0% |
| `tetragon_process_event_arg_filter` | proof-passing | 114 | 163 | 0.699x | +30.1% |

Interpretation:

- `payload_prefix_memcmp_scan`: native-vs-kernel gain shrank by 14.1 percentage
  points. Native did not get slower in this pair (`49 ns -> 48 ns`); the gap
  shrank because kernel eBPF got faster (`112 ns -> 83 ns`).
- `tetragon_process_event_arg_filter`: native-vs-kernel gain grew by 7.0
  percentage points. Native got slightly slower (`107 ns -> 114 ns`), but
  kernel eBPF got slower by more (`139 ns -> 163 ns`).

There is no old `native_lab`-vs-kernel comparison for the proof-failing shape:
that proof did not load, so `native_lab` had no valid run.
