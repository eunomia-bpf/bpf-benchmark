# Diagnostics

- Base: phase2 attempt 3 (`cache-vip-metadata`)
- Build command: `make -C vendor katran-x86`
- Build result: succeeded; see `build.log`

| Variant | xdp section size | Approx BPF instruction slots | Note |
| --- | ---: | ---: | --- |
| clean upstream source | `0x4870` | 2318 | restored artifact baseline |
| phase2 attempt 3 | `0x47b8` | 2295 | current best formal result |
| this diagnostic | `0x48c8` | 2330 | rejected before formal run |

Displayed xdp instruction lines: `2255`.

The candidate is larger than clean and attempt 3, so it is not worth a
180-second x 3 formal run.
