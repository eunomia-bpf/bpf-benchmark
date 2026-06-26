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
| this candidate | `0x47c8` | 2297 | rejected before formal run |

`llvm-objdump -d --section=xdp` reported 2223 displayed instruction lines for
this candidate.

## Interpretation

The source rewrite should reduce work when `vip_miss_stats` does not match the
current VIP, but it increases verifier-visible code. Since the already-tested
stats-path combination was slower than attempt 3, this candidate is not worth a
formal 3-sample run.
