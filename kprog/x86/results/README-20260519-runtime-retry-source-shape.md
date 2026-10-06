# ReverseSim runtime retry: source-shape impact

Command used for each run:

```bash
make micro BENCH="payload_prefix_memcmp_scan tetragon_process_event_arg_filter" \
  RUNTIMES="native kernel native_lab" \
  SAMPLES=5 WARMUPS=1 INNER_REPEAT=100000
```

Notes:

- `new-shaped` is the proof-passing source shape used in
  `README-20260519-proof-recheck-29of29.md`.
- `old-restored` is the original partial-register source shape restored after
  the new run. The worktree was restored so these two micro source files have no
  remaining diff.
- Decision after this comparison: do not adopt `new-shaped`. Keep the old
  source shape and accept the two ReverseSim proof failures for now.
- The runner warned that CPU governor/turbo settings may add noise.

Result directories:

- `new-shaped`: `micro/results/x86_kvm_micro_20260519_232848_505180`
- `old-restored`: `micro/results/x86_kvm_micro_20260519_233313_602963`
- extra sanity old run before shaping: `micro/results/x86_kvm_micro_20260519_232115_705154`

Shape evidence:

- `new-shaped` payload native asm uses `mov esi,0x1d` and `mov r8d,0x4`.
- `old-restored` payload native asm uses `mov sil,0x1d` and `mov r8b,0x4`.
- `new-shaped` tetragon avoids the `mov dl,0x1` partial-register artifact.
- `old-restored` tetragon contains `mov dl,0x1`.

| Micro program | Shape | Runtime | Exec mean ns | Exec median ns | Exec min-max ns | Compile mean ns | Native bytes | BPF bytes | Gain vs kernel |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| `payload_prefix_memcmp_scan` | `new-shaped` | `native` | 48.0 | 48.0 | 48-48 | 41294 | 548 | 0 | +41.6% |
| `payload_prefix_memcmp_scan` | `new-shaped` | `kernel` | 82.2 | 82.0 | 82-83 | 780966 | 606 | 1136 | +0.0% |
| `payload_prefix_memcmp_scan` | `new-shaped` | `native_lab` | 51.0 | 51.0 | 51-51 | 111110243 | 528 | 0 | +38.0% |
| `payload_prefix_memcmp_scan` | `old-restored` | `native` | 49.4 | 49.0 | 49-50 | 44404 | 510 | 0 | +50.6% |
| `payload_prefix_memcmp_scan` | `old-restored` | `kernel` | 100.0 | 100.0 | 99-101 | 853346 | 565 | 1112 | +0.0% |
| `payload_prefix_memcmp_scan` | `old-restored` | `native_lab` | 53.0 | 53.0 | 53-53 | 111323340 | 493 | 0 | +47.0% |
| `tetragon_process_event_arg_filter` | `new-shaped` | `native` | 113.2 | 113.0 | 113-114 | 41425 | 870 | 0 | +31.1% |
| `tetragon_process_event_arg_filter` | `new-shaped` | `kernel` | 164.2 | 164.0 | 163-166 | 9572943 | 1295 | 2336 | +0.0% |
| `tetragon_process_event_arg_filter` | `new-shaped` | `native_lab` | 116.4 | 116.0 | 116-117 | 119275136 | 810 | 0 | +29.1% |
| `tetragon_process_event_arg_filter` | `old-restored` | `native` | 107.8 | 107.0 | 107-111 | 42216 | 802 | 0 | +30.0% |
| `tetragon_process_event_arg_filter` | `old-restored` | `kernel` | 154.0 | 154.0 | 154-154 | 7361292 | 1260 | 2296 | +0.0% |
| `tetragon_process_event_arg_filter` | `old-restored` | `native_lab` | 109.2 | 109.0 | 109-110 | 117596136 | 761 | 0 | +29.1% |

Delta view, using `old-restored` as baseline:

| Micro program | Runtime | Old mean ns | New mean ns | New vs old |
| --- | --- | ---: | ---: | ---: |
| `payload_prefix_memcmp_scan` | `native` | 49.4 | 48.0 | -2.8% |
| `payload_prefix_memcmp_scan` | `kernel` | 100.0 | 82.2 | -17.8% |
| `payload_prefix_memcmp_scan` | `native_lab` | 53.0 | 51.0 | -3.8% |
| `tetragon_process_event_arg_filter` | `native` | 107.8 | 113.2 | +5.0% |
| `tetragon_process_event_arg_filter` | `kernel` | 154.0 | 164.2 | +6.6% |
| `tetragon_process_event_arg_filter` | `native_lab` | 109.2 | 116.4 | +6.6% |

Native-vs-kernel gain impact:

| Micro program | Runtime | Old gain | New gain | Gain delta |
| --- | --- | ---: | ---: | ---: |
| `payload_prefix_memcmp_scan` | `native` | +50.6% | +41.6% | -9.0 pp |
| `payload_prefix_memcmp_scan` | `native_lab` | +47.0% | +38.0% | -9.0 pp |
| `tetragon_process_event_arg_filter` | `native` | +30.0% | +31.1% | +1.1 pp |
| `tetragon_process_event_arg_filter` | `native_lab` | +29.1% | +29.1% | +0.0 pp |

Interpretation:

- For `payload_prefix_memcmp_scan`, the apparent native-vs-kernel speedup
  shrinks by about 9 percentage points in the proof-passing source shape. The
  native path is slightly faster, but kernel eBPF gets much faster.
- For `tetragon_process_event_arg_filter`, the source shaping slows both native
  and kernel paths similarly; the native-vs-kernel gap is effectively unchanged.
