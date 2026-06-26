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
| this attempt | `0x47b8` | 2295 | same size as attempt 3, different object hash |

`llvm-objdump -d --section=xdp` reported 2221 displayed instruction lines for
this attempt.

Object hash check:

- phase2 attempt 3-only object:
  `1e63877912dbbd97be5216cea1e493d8135ca81452ba6b068e0dd3eff33f6e3d`
- this attempt object:
  `6a2ea6cb7c2b8a0b50dcc73bf988e35b154122d8be2d0e17cb6ae6de70e6a0fb`

## Interpretation

The static size proxy does not improve, but the generated object changes. A
formal run is still useful because the source change removes redundant null
guards in hot-path conditions after the fallback map assignment.
