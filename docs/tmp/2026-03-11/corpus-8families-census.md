# Corpus 8-Family Census

- Generated: 2026-03-11T20:33:01+00:00
- Repo: `/home/yunwei37/workspace/bpf-benchmark`
- Kernel bzImage: `/home/yunwei37/workspace/bpf-benchmark/vendor/linux-framework/arch/x86/boot/bzImage`
- Guest kernel commit: `e52504a75`
- Scanner: `/home/yunwei37/workspace/bpf-benchmark/scanner/build/bpf-jit-scanner`
- Runner: `/home/yunwei37/workspace/bpf-benchmark/micro/build/runner/micro_exec`
- Census scope: `corpus/build/**/*.bpf.o` and `micro/programs/*.bpf.o`
- Scanner flags: `scan <obj> --all --v5`
- Effective 8 families from `--all`: `cmov`, `wide`, `rotate`, `lea`, `extract`, `zeroext`, `endian`, `bflip`

## Quick Validation

| Step | Result | Notes |
| --- | --- | --- |
| Scanner build | ok | `cmake --build scanner/build -j` completed; tail showed all three targets built |
| Scanner unit test | ok | `./scanner/build/test_scanner` tail: `PASS 78` |
| VM smoke | ok after CLI adjustment | Current `micro_exec` no longer accepts `--recompile auto-scan-v5`; equivalent working invocation is `run-kernel ... --recompile-all --recompile-v5` |

### VM Smoke Notes

- Command used: `vng --run vendor/linux-framework/arch/x86/boot/bzImage --exec "./micro/build/runner/micro_exec run-kernel micro/programs/simple.bpf.o --io-mode staged --repeat 5 --recompile-all --recompile-v5"`
- Exit status: `0`
- `simple.bpf.o` loaded and executed successfully in guest.
- Auto-scan/recompile path activated, but this program had no eligible v5 sites:
  - `cmov=0`
  - `wide=0`
  - `rotate=0`
  - `lea=0`
  - `extract=0`
- Runner JSON reported `directive_scan.total_sites=0`, `recompile.requested=true`, `recompile.mode="auto-scan-v5"`, `recompile.applied=false`.

## Census Summary

| Metric | Value |
| --- | --- |
| Total objects | 627 |
| Successful scans | 532 |
| Failed scans | 95 |
| Objects with >=1 site | 179 |
| Total sites | 3218 |

- Site-bearing object rate over all inputs: `179 / 627 = 28.5%`
- Site-bearing object rate over successful scans: `179 / 532 = 33.6%`
- Scan failure rate: `95 / 627 = 15.2%`

## By Source

| Source | Objects | Successful scans | Failed scans | Objects with sites | Total sites |
| --- | --- | --- | --- | --- | --- |
| corpus/build | 560 | 465 | 95 | 116 | 2116 |
| micro/programs | 67 | 67 | 0 | 63 | 1102 |

## By Family

| Family | Total sites | Share of all sites | corpus/build | micro/programs |
| --- | --- | --- | --- | --- |
| cmov | 468 | 14.5% | 421 | 47 |
| wide | 472 | 14.7% | 317 | 155 |
| rotate | 1857 | 57.7% | 992 | 865 |
| lea | 5 | 0.2% | 0 | 5 |
| extract | 70 | 2.2% | 55 | 15 |
| zeroext | 0 | 0.0% | 0 | 0 |
| endian | 313 | 9.7% | 313 | 0 |
| bflip | 33 | 1.0% | 18 | 15 |

## Failed Scan Breakdown

| Reason | Count | Typical cause |
| --- | --- | --- |
| `no_bpf_programs` | 74 | ELF contains no BPF programs |
| `missing_extern_btf` | 8 | external BTF dependency not available during object open |
| `arena_map_extra_enum64` | 6 | arena map metadata not supported by current host libbpf open path |
| `static_program_not_supported` | 4 | object uses static program sections libbpf refuses to open |
| `extern_map_linkage` | 2 | extern map linkage unsupported |
| `legacy_map_definitions` | 1 | legacy map definition format unsupported by libbpf v1.0+ |

Representative failing inputs included objects under `cilium`, `datadog-agent`, `linux-selftests`, `netbird`, `opentelemetry-ebpf-profiler`, and `scx`.

## Notes

- Totals above come from the live scanner CLI output, not from static metadata.
- The example census snippet in the task missed one family: `bflip`. In this tree, `scanner ... --all --v5` prints and counts 8 families including `bflip`.
- The 95 failures were object-open limitations in libbpf/input format handling; they were not scanner crashes.
- `zeroext` produced no hits across the scanned successful objects in this run.
