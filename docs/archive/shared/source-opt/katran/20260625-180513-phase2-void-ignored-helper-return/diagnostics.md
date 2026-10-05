# Diagnostics

- Base: phase2 attempt 3 (`cache-vip-metadata`)
- Build command: `make -C vendor katran-x86`
- Build result: succeeded; see `build.log`

| Variant | xdp section size | Displayed xdp instruction lines | Note |
| --- | ---: | ---: | --- |
| clean upstream source | `0x4870` | n/a | restored artifact baseline |
| phase2 attempt 3 | `0x47b8` | 2221 | current best formal result |
| this diagnostic | `0x47b8` | 2221 | no emitted-code signal |

No formal run.
