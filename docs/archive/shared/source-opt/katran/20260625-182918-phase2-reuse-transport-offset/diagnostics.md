# Diagnostics

## Build

- Command: `make -C vendor katran-x86`
- Result: succeeded; see `build.log`.

## Object size / instruction proxy

Object inspected: `vendor/build/x86/katran/bpf/balancer.bpf.o`

| Variant | xdp section size | Approx BPF instruction slots | Note |
| --- | ---: | ---: | --- |
| clean upstream source | `0x4870` | 2318 | restored artifact baseline |
| phase2 attempt 3 | `0x47b8` | 2295 | current best katran phase2 base |
| this candidate | `0x4af8` | 2399 | rejected before formal run |

`llvm-objdump -d --section=xdp` reported 2325 displayed instruction lines for
this candidate.

## Interpretation

The intended optimization removes repeated offset recomputation on ordinary
non-ICMP packets, but the signature changes make the inlined BPF larger. Since
attempt 3 already wins on workload throughput and has smaller emitted code, this
candidate is not worth a formal 3-sample run.
