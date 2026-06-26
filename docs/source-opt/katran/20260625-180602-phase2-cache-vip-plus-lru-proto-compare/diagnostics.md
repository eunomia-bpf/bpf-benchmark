# Diagnostics

## Build

- Command: `make -C vendor katran-x86`
- Result: succeeded; see `build.log`.

## Object size / instruction proxy

Object inspected: `vendor/build/x86/katran/bpf/balancer.bpf.o`

| Variant | xdp section size | Approx BPF instruction slots | Note |
| --- | ---: | ---: | --- |
| clean upstream source | `0x4870` | 2318 | restored artifact baseline |
| phase2 attempt 3 | `0x47b8` | 2295 | current best formal result |
| this attempt | `0x4798` | 2291 | 4 slots smaller than attempt 3 |

Displayed xdp instruction lines: `2217`.

The candidate has a small emitted-code reduction and fixes a source-level
assignment-vs-comparison bug, so it is promoted to a formal run.
