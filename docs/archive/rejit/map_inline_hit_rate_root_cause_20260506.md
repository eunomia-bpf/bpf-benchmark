# map_inline hit-rate root cause, R1 noop,map_inline x86 corpus

Date: 2026-05-06  
Primary run: `corpus/results/x86_kvm_corpus_20260507_023000_475311`  
Verifier-log smoke: `corpus/results/x86_kvm_corpus_20260507_034456_818538`  
Chosen program: `tetragon/observer`, prog id 19 in the smoke, `event_exit_acct_process`

## Executive verdict

`map_inline` applied to only 2 of the 138 qualified R1 programs because the helper-lookup path is effectively blocked by verifier-state alignment/reconstruction, not primarily by the daemon's 64 KiB map snapshot cap.

R1 has 110 qualified programs with at least one `map_inline` match. Only 2 applied anything, and both applied direct pseudo-map-value loads, not helper `bpf_map_lookup_elem` rewrites. Of the 108 qualified programs with matched sites but zero applied sites, 107 have direct `verifier log has no state snapshot at call pc ...` diagnostics. That is the dominant missed-hit shape.

The 64 KiB cap is real, but it is a smaller lever for the 2/138 question. Across all R1 daemon map snapshot decisions, raising the cap to 256 KiB would newly dump 235 program-map observations, and raising it to 1 MiB would newly dump 428. In the 138-qualified population, those become only 64 observations / 4 unique maps at 256 KiB and 86 observations / 20 unique maps at 1 MiB. In the chosen Tetragon program, two lookup sites are blocked by size, but four lookup sites have dumpable maps and still fail because the pass cannot recover the key from verifier state.

## Inputs read

- `docs/kernel-jit-optimization-plan.md`
- `CLAUDE.md`
- `docs/tmp/corpus_workload_coverage_audit_20260506.md`

Constraints followed: investigation only, no code changes. Benchmark reruns used Makefile targets only.

## Prong A: daemon map snapshot cap audit

The snapshot decision log is emitted by `log_bpftool_map_snapshot_decision` in `daemon/src/commands.rs`. The line is written to stderr with this format:

```text
daemon: map_snapshot prog_id={} map_id={} map_type={} size_bytes={} action={}
```

The cap is `MAP_SNAPSHOT_MAX_BYTES = 64 * 1024`. Actions observed in R1:

- `dumped`: bpftool JSON dump was kept under the cap.
- `skip_size`: map type needed a dump, but the JSON dump exceeded 64 KiB.
- `skip_type`: map type did not need a dump.

### R1 all-program snapshot decisions

R1 `details/daemon.stderr.log` contained the full decision stream, so no full corpus rerun was needed for Prong A.

Total program-map observations: 6,845  
Programs with snapshot decisions: 546  
Dumped: 4,240  
Skipped by size: 1,526  
Skipped by type: 1,079

| app | total maps observed | dumped | skip_size | unique skip_size maps | skip_type |
|---|---:|---:|---:|---:|---:|
| bcc/set | 30 | 14 | 7 | 4 | 9 |
| bpftrace/set | 24 | 10 | 8 | 5 | 6 |
| cilium/agent | 384 | 183 | 34 | 2 | 167 |
| katran | 18 | 10 | 7 | 7 | 1 |
| otelcol-ebpf-profiler/profiling | 105 | 54 | 27 | 4 | 24 |
| tetragon/observer | 3550 | 2123 | 827 | 237 | 600 |
| tracee/monitor | 2734 | 1846 | 616 | 13 | 272 |

`skip_size` by map type across all R1 observations:

| map_type | observations |
|---:|---:|
| 6 | 901 |
| 9 | 347 |
| 1 | 184 |
| 2 | 94 |

`skip_type` by map type across all R1 observations:

| map_type | observations |
|---:|---:|
| 3 | 343 |
| 4 | 260 |
| 10 | 156 |
| 7 | 147 |
| 27 | 87 |
| 5 | 51 |
| 11 | 34 |
| 22 | 1 |

### R1 qualified-program snapshot decisions

This is the subset tied directly to the 138 qualified-program hit-rate question.

Total qualified program-map observations: 1,633  
Dumped: 1,089  
Skipped by size: 369  
Skipped by type: 175

| app | total maps observed | dumped | skip_size | unique skip_size maps | skip_type |
|---|---:|---:|---:|---:|---:|
| bcc/set | 28 | 13 | 7 | 4 | 8 |
| bpftrace/set | 22 | 9 | 8 | 5 | 5 |
| katran | 1 | 0 | 0 | 0 | 1 |
| otelcol-ebpf-profiler/profiling | 11 | 5 | 2 | 2 | 4 |
| tetragon/observer | 208 | 123 | 51 | 22 | 34 |
| tracee/monitor | 1363 | 939 | 301 | 11 | 123 |

Cap-lift estimate:

| population | cap | newly dumped observations | unique maps unlocked |
|---|---:|---:|---:|
| all R1 programs | 256 KiB | 235 | 51 |
| all R1 programs | 1 MiB | 428 | 154 |
| 138 qualified programs | 256 KiB | 64 | 4 |
| 138 qualified programs | 1 MiB | 86 | 20 |

Qualified-population cap-lift by app:

| cap | bcc/set | bpftrace/set | otel | tetragon | tracee |
|---:|---:|---:|---:|---:|---:|
| 256 KiB | 1 | 0 | 1 | 1 | 61 |
| 1 MiB | 1 | 8 | 2 | 9 | 66 |

### Unique skip_size maps, all R1 programs

This table is de-duplicated by `(app, map_id, map_type)`. `refs` is the number of program-map observations that hit `skip_size`; `qualified_refs` is the subset from the 138 qualified programs. A range in `dump_size_bytes` means the same live map produced different dump byte sizes across program observations.

| app | map_id | type | refs | qualified_refs | dump_size_bytes | <=256KB | <=1MB |
|---|---:|---:|---:|---:|---:|---|---|
| bcc/set | 3 | 1 | 2 | 2 | 1924533 | no | no |
| bcc/set | 6 | 1 | 2 | 2 | 4848697 | no | no |
| bcc/set | 7 | 1 | 2 | 2 | 3627877 | no | no |
| bcc/set | 20 | 1 | 1 | 1 | 203314 | yes | yes |
| bpftrace/set | 3836 | 1 | 1 | 1 | 769110 | no | yes |
| bpftrace/set | 3837 | 1 | 1 | 1 | 540014 | no | yes |
| bpftrace/set | 3841 | 1 | 2 | 2 | 395770 | no | yes |
| bpftrace/set | 3842 | 1 | 2 | 2 | 304938 | no | yes |
| bpftrace/set | 3843 | 1 | 2 | 2 | 304938 | no | yes |
| cilium/agent | 224 | 9 | 9 | 0 | 216514 | yes | yes |
| cilium/agent | 225 | 9 | 25 | 0 | 433502 | no | yes |
| katran | 3564 | 2 | 1 | 0 | 3847707452 | no | no |
| katran | 3565 | 2 | 1 | 0 | 1080250 | no | no |
| katran | 3572 | 2 | 1 | 0 | 1918268502 | no | no |
| katran | 3559 | 6 | 1 | 0 | 2818916 | no | no |
| katran | 3566 | 6 | 1 | 0 | 11275330 | no | no |
| katran | 3567 | 6 | 1 | 0 | 4852652 | no | no |
| katran | 3574 | 6 | 1 | 0 | 1408916 | no | no |
| otelcol-ebpf-profiler/profiling | 66 | 1 | 1 | 0 | 679278 | no | yes |
| otelcol-ebpf-profiler/profiling | 61 | 2 | 1 | 0 | 3759499 | no | no |
| otelcol-ebpf-profiler/profiling | 68 | 6 | 12 | 1 | 840794-840911 | no | yes |
| otelcol-ebpf-profiler/profiling | 69 | 6 | 13 | 1 | 161655-161657 | yes | yes |
| tetragon/observer | 273 | 1 | 129 | 9 | 11902895-18042727 | no | no |
| tetragon/observer | 278 | 2 | 1 | 0 | 983203 | no | yes |
| tetragon/observer | 633 | 2 | 2 | 0 | 114817 | yes | yes |
| tetragon/observer | 653 | 2 | 2 | 0 | 114817 | yes | yes |
| tetragon/observer | 676 | 2 | 2 | 0 | 114817 | yes | yes |
| tetragon/observer | 889 | 2 | 2 | 0 | 114817 | yes | yes |
| tetragon/observer | 906 | 2 | 2 | 0 | 114817 | yes | yes |
| tetragon/observer | 932 | 2 | 2 | 0 | 114817 | yes | yes |
| tetragon/observer | 956 | 2 | 2 | 0 | 114817 | yes | yes |
| tetragon/observer | 1262 | 2 | 2 | 0 | 114817 | yes | yes |
| tetragon/observer | 1309 | 2 | 2 | 0 | 114817 | yes | yes |
| tetragon/observer | 1336 | 2 | 2 | 0 | 114817 | yes | yes |
| tetragon/observer | 1350 | 2 | 2 | 0 | 114817 | yes | yes |
| tetragon/observer | 1397 | 2 | 2 | 0 | 114817 | yes | yes |
| tetragon/observer | 1412 | 2 | 2 | 0 | 114817 | yes | yes |
| tetragon/observer | 1454 | 2 | 2 | 0 | 114817 | yes | yes |
| tetragon/observer | 1525 | 2 | 2 | 0 | 114817 | yes | yes |
| tetragon/observer | 1787 | 2 | 2 | 0 | 114817 | yes | yes |
| tetragon/observer | 1826 | 2 | 2 | 0 | 114817 | yes | yes |
| tetragon/observer | 1846 | 2 | 2 | 0 | 114817 | yes | yes |
| tetragon/observer | 1865 | 2 | 2 | 0 | 114817 | yes | yes |
| tetragon/observer | 1893 | 2 | 2 | 0 | 114817 | yes | yes |
| tetragon/observer | 1948 | 2 | 2 | 0 | 114817 | yes | yes |
| tetragon/observer | 2206 | 2 | 2 | 0 | 114817 | yes | yes |
| tetragon/observer | 2219 | 2 | 2 | 0 | 114817 | yes | yes |
| tetragon/observer | 2273 | 2 | 2 | 0 | 114817 | yes | yes |
| tetragon/observer | 2282 | 2 | 2 | 0 | 114817 | yes | yes |
| tetragon/observer | 2332 | 2 | 2 | 0 | 114817 | yes | yes |
| tetragon/observer | 2335 | 2 | 2 | 0 | 114817 | yes | yes |
| tetragon/observer | 2426 | 2 | 2 | 0 | 114817 | yes | yes |
| tetragon/observer | 2492 | 2 | 2 | 0 | 114817 | yes | yes |
| tetragon/observer | 2573 | 2 | 2 | 0 | 114817 | yes | yes |
| tetragon/observer | 2648 | 2 | 2 | 0 | 114817 | yes | yes |
| tetragon/observer | 2704 | 2 | 2 | 0 | 114817 | yes | yes |
| tetragon/observer | 2775 | 2 | 2 | 0 | 114817 | yes | yes |
| tetragon/observer | 3087 | 2 | 2 | 0 | 114817 | yes | yes |
| tetragon/observer | 3130 | 2 | 2 | 0 | 114817 | yes | yes |
| tetragon/observer | 3147 | 2 | 2 | 0 | 114817 | yes | yes |
| tetragon/observer | 3164 | 2 | 2 | 0 | 114817 | yes | yes |
| tetragon/observer | 3206 | 2 | 2 | 0 | 114817 | yes | yes |
| tetragon/observer | 3216 | 2 | 2 | 0 | 114817 | yes | yes |
| tetragon/observer | 3266 | 2 | 2 | 0 | 114817 | yes | yes |
| tetragon/observer | 3412 | 2 | 2 | 0 | 114817 | yes | yes |
| tetragon/observer | 3440 | 2 | 2 | 0 | 114817 | yes | yes |
| tetragon/observer | 3471 | 2 | 2 | 0 | 114817 | yes | yes |
| tetragon/observer | 3556 | 2 | 2 | 0 | 114817 | yes | yes |
| tetragon/observer | 280 | 6 | 83 | 2 | 1672418 | no | no |
| tetragon/observer | 357 | 6 | 1 | 1 | 108928 | yes | yes |
| tetragon/observer | 376 | 6 | 2 | 0 | 628634-628644 | no | yes |
| tetragon/observer | 396 | 6 | 3 | 0 | 907497-909524 | no | yes |
| tetragon/observer | 402 | 6 | 1 | 0 | 3672224 | no | no |
| tetragon/observer | 421 | 6 | 1 | 0 | 462738 | no | yes |
| tetragon/observer | 432 | 6 | 1 | 0 | 462624 | no | yes |
| tetragon/observer | 534 | 6 | 21 | 0 | 3281293-3665986 | no | no |
| tetragon/observer | 631 | 6 | 2 | 0 | 627552 | no | yes |
| tetragon/observer | 636 | 6 | 1 | 0 | 1835385 | no | no |
| tetragon/observer | 637 | 6 | 1 | 0 | 3672224 | no | no |
| tetragon/observer | 645 | 6 | 1 | 0 | 460704 | no | yes |
| tetragon/observer | 660 | 6 | 2 | 0 | 627552 | no | yes |
| tetragon/observer | 672 | 6 | 1 | 0 | 460704 | no | yes |
| tetragon/observer | 673 | 6 | 1 | 0 | 3672224 | no | no |
| tetragon/observer | 674 | 6 | 1 | 0 | 1835385 | no | no |
| tetragon/observer | 679 | 6 | 1 | 0 | 1835385 | no | no |
| tetragon/observer | 684 | 6 | 1 | 0 | 460704 | no | yes |
| tetragon/observer | 687 | 6 | 2 | 0 | 627552 | no | yes |
| tetragon/observer | 697 | 6 | 1 | 0 | 3672224 | no | no |
| tetragon/observer | 739 | 6 | 25 | 3 | 2945411-3137211 | no | no |
| tetragon/observer | 867 | 6 | 1 | 0 | 1835385 | no | no |
| tetragon/observer | 870 | 6 | 1 | 0 | 460704 | no | yes |
| tetragon/observer | 879 | 6 | 1 | 0 | 3672224 | no | no |
| tetragon/observer | 880 | 6 | 2 | 0 | 627552 | no | yes |
| tetragon/observer | 895 | 6 | 1 | 1 | 627552 | no | yes |
| tetragon/observer | 914 | 6 | 1 | 0 | 1835385 | no | no |
| tetragon/observer | 917 | 6 | 1 | 0 | 460704 | no | yes |
| tetragon/observer | 927 | 6 | 1 | 0 | 1835385 | no | no |
| tetragon/observer | 933 | 6 | 1 | 0 | 460704 | no | yes |
| tetragon/observer | 947 | 6 | 1 | 0 | 3672224 | no | no |
| tetragon/observer | 948 | 6 | 2 | 0 | 627552 | no | yes |
| tetragon/observer | 952 | 6 | 1 | 0 | 1835385 | no | no |
| tetragon/observer | 965 | 6 | 1 | 0 | 3672224 | no | no |
| tetragon/observer | 969 | 6 | 2 | 0 | 627552 | no | yes |
| tetragon/observer | 973 | 6 | 1 | 0 | 460704 | no | yes |
| tetragon/observer | 1015 | 6 | 46 | 5 | 2945443-3137343 | no | no |
| tetragon/observer | 1263 | 6 | 1 | 0 | 460704 | no | yes |
| tetragon/observer | 1269 | 6 | 1 | 0 | 1835385 | no | no |
| tetragon/observer | 1276 | 6 | 1 | 0 | 3672224 | no | no |
| tetragon/observer | 1277 | 6 | 2 | 0 | 627552 | no | yes |
| tetragon/observer | 1286 | 6 | 1 | 0 | 1835385 | no | no |
| tetragon/observer | 1296 | 6 | 1 | 1 | 627552 | no | yes |
| tetragon/observer | 1315 | 6 | 1 | 0 | 460704 | no | yes |
| tetragon/observer | 1321 | 6 | 1 | 0 | 460704 | no | yes |
| tetragon/observer | 1327 | 6 | 1 | 0 | 1835385 | no | no |
| tetragon/observer | 1331 | 6 | 2 | 0 | 627552 | no | yes |
| tetragon/observer | 1334 | 6 | 1 | 0 | 3672224 | no | no |
| tetragon/observer | 1347 | 6 | 2 | 0 | 627552 | no | yes |
| tetragon/observer | 1361 | 6 | 1 | 0 | 460704 | no | yes |
| tetragon/observer | 1363 | 6 | 1 | 0 | 1835385 | no | no |
| tetragon/observer | 1368 | 6 | 1 | 0 | 3672224 | no | no |
| tetragon/observer | 1382 | 6 | 1 | 0 | 1835385 | no | no |
| tetragon/observer | 1384 | 6 | 1 | 0 | 3672224 | no | no |
| tetragon/observer | 1386 | 6 | 2 | 0 | 627552 | no | yes |
| tetragon/observer | 1394 | 6 | 1 | 0 | 460704 | no | yes |
| tetragon/observer | 1405 | 6 | 1 | 0 | 1835385 | no | no |
| tetragon/observer | 1407 | 6 | 1 | 0 | 460704 | no | yes |
| tetragon/observer | 1417 | 6 | 2 | 0 | 627552 | no | yes |
| tetragon/observer | 1429 | 6 | 1 | 0 | 3672224 | no | no |
| tetragon/observer | 1434 | 6 | 1 | 0 | 1835385 | no | no |
| tetragon/observer | 1435 | 6 | 1 | 0 | 3672224 | no | no |
| tetragon/observer | 1451 | 6 | 2 | 0 | 627552 | no | yes |
| tetragon/observer | 1459 | 6 | 1 | 0 | 460704 | no | yes |
| tetragon/observer | 1500 | 6 | 7 | 1 | 2896484-2896489 | no | no |
| tetragon/observer | 1517 | 6 | 1 | 0 | 1835385 | no | no |
| tetragon/observer | 1518 | 6 | 2 | 0 | 627552 | no | yes |
| tetragon/observer | 1526 | 6 | 1 | 0 | 3672224 | no | no |
| tetragon/observer | 1530 | 6 | 1 | 0 | 460704 | no | yes |
| tetragon/observer | 1573 | 6 | 33 | 6 | 2897343-2994036 | no | no |
| tetragon/observer | 1776 | 6 | 2 | 0 | 631301-631321 | no | yes |
| tetragon/observer | 1777 | 6 | 1 | 0 | 1835385 | no | no |
| tetragon/observer | 1788 | 6 | 1 | 0 | 460704 | no | yes |
| tetragon/observer | 1791 | 6 | 1 | 0 | 3672224 | no | no |
| tetragon/observer | 1800 | 6 | 1 | 0 | 460704 | no | yes |
| tetragon/observer | 1806 | 6 | 1 | 0 | 1835385 | no | no |
| tetragon/observer | 1823 | 6 | 1 | 1 | 627552 | no | yes |
| tetragon/observer | 1830 | 6 | 1 | 0 | 1835385 | no | no |
| tetragon/observer | 1843 | 6 | 2 | 0 | 630885-630888 | no | yes |
| tetragon/observer | 1850 | 6 | 1 | 0 | 460704 | no | yes |
| tetragon/observer | 1851 | 6 | 1 | 0 | 3672224 | no | no |
| tetragon/observer | 1858 | 6 | 1 | 0 | 460704 | no | yes |
| tetragon/observer | 1874 | 6 | 1 | 1 | 627552 | no | yes |
| tetragon/observer | 1887 | 6 | 1 | 0 | 1835385 | no | no |
| tetragon/observer | 1891 | 6 | 2 | 0 | 630272 | no | yes |
| tetragon/observer | 1894 | 6 | 1 | 0 | 460704 | no | yes |
| tetragon/observer | 1895 | 6 | 1 | 0 | 1835385 | no | no |
| tetragon/observer | 1912 | 6 | 1 | 0 | 3672224 | no | no |
| tetragon/observer | 1937 | 6 | 1 | 0 | 1835385 | no | no |
| tetragon/observer | 1947 | 6 | 1 | 1 | 627552 | no | yes |
| tetragon/observer | 1949 | 6 | 1 | 0 | 460704 | no | yes |
| tetragon/observer | 1988 | 6 | 36 | 0 | 2892592 | no | no |
| tetragon/observer | 2191 | 6 | 2 | 0 | 627552 | no | yes |
| tetragon/observer | 2194 | 6 | 1 | 0 | 1835385 | no | no |
| tetragon/observer | 2198 | 6 | 1 | 0 | 460704 | no | yes |
| tetragon/observer | 2204 | 6 | 1 | 0 | 3672224 | no | no |
| tetragon/observer | 2220 | 6 | 1 | 0 | 460704 | no | yes |
| tetragon/observer | 2226 | 6 | 1 | 0 | 1835385 | no | no |
| tetragon/observer | 2247 | 6 | 1 | 0 | 627552 | no | yes |
| tetragon/observer | 2253 | 6 | 1 | 0 | 3672224 | no | no |
| tetragon/observer | 2258 | 6 | 1 | 0 | 460704 | no | yes |
| tetragon/observer | 2260 | 6 | 2 | 0 | 627552 | no | yes |
| tetragon/observer | 2264 | 6 | 1 | 0 | 1835385 | no | no |
| tetragon/observer | 2284 | 6 | 1 | 0 | 627552 | no | yes |
| tetragon/observer | 2285 | 6 | 1 | 0 | 1835385 | no | no |
| tetragon/observer | 2299 | 6 | 1 | 0 | 460704 | no | yes |
| tetragon/observer | 2320 | 6 | 1 | 0 | 1835385 | no | no |
| tetragon/observer | 2327 | 6 | 1 | 0 | 3672224 | no | no |
| tetragon/observer | 2330 | 6 | 2 | 0 | 627552 | no | yes |
| tetragon/observer | 2333 | 6 | 1 | 0 | 460704 | no | yes |
| tetragon/observer | 2338 | 6 | 1 | 0 | 460704 | no | yes |
| tetragon/observer | 2345 | 6 | 1 | 0 | 3672224 | no | no |
| tetragon/observer | 2355 | 6 | 1 | 0 | 1835385 | no | no |
| tetragon/observer | 2359 | 6 | 2 | 0 | 627552 | no | yes |
| tetragon/observer | 2397 | 6 | 7 | 0 | 3666530-3666551 | no | no |
| tetragon/observer | 2407 | 6 | 1 | 0 | 1835385 | no | no |
| tetragon/observer | 2416 | 6 | 1 | 0 | 3672224 | no | no |
| tetragon/observer | 2422 | 6 | 1 | 0 | 460704 | no | yes |
| tetragon/observer | 2427 | 6 | 2 | 0 | 628124-628130 | no | yes |
| tetragon/observer | 2477 | 6 | 6 | 1 | 3472730-3664727 | no | no |
| tetragon/observer | 2483 | 6 | 2 | 0 | 627552 | no | yes |
| tetragon/observer | 2488 | 6 | 1 | 0 | 460704 | no | yes |
| tetragon/observer | 2490 | 6 | 1 | 0 | 1835385 | no | no |
| tetragon/observer | 2550 | 6 | 1 | 0 | 460704 | no | yes |
| tetragon/observer | 2555 | 6 | 1 | 0 | 3672224 | no | no |
| tetragon/observer | 2569 | 6 | 1 | 0 | 1835385 | no | no |
| tetragon/observer | 2570 | 6 | 7 | 0 | 3666654-3666663 | no | no |
| tetragon/observer | 2576 | 6 | 2 | 0 | 628130-628132 | no | yes |
| tetragon/observer | 2615 | 6 | 7 | 1 | 3665925 | no | no |
| tetragon/observer | 2625 | 6 | 1 | 0 | 3672224 | no | no |
| tetragon/observer | 2634 | 6 | 2 | 0 | 627552 | no | yes |
| tetragon/observer | 2635 | 6 | 1 | 0 | 1835385 | no | no |
| tetragon/observer | 2649 | 6 | 1 | 0 | 460704 | no | yes |
| tetragon/observer | 2689 | 6 | 7 | 1 | 3234184-3570554 | no | no |
| tetragon/observer | 2699 | 6 | 1 | 0 | 460704 | no | yes |
| tetragon/observer | 2708 | 6 | 1 | 0 | 3672224 | no | no |
| tetragon/observer | 2720 | 6 | 1 | 0 | 1835385 | no | no |
| tetragon/observer | 2722 | 6 | 2 | 0 | 628651-628653 | no | yes |
| tetragon/observer | 2762 | 6 | 7 | 0 | 2892592 | no | no |
| tetragon/observer | 2772 | 6 | 2 | 0 | 627552 | no | yes |
| tetragon/observer | 2792 | 6 | 1 | 0 | 460704 | no | yes |
| tetragon/observer | 2795 | 6 | 1 | 0 | 1835385 | no | no |
| tetragon/observer | 2797 | 6 | 1 | 0 | 3672224 | no | no |
| tetragon/observer | 2835 | 6 | 43 | 7 | 2945437-3137235 | no | no |
| tetragon/observer | 3075 | 6 | 1 | 0 | 1835385 | no | no |
| tetragon/observer | 3090 | 6 | 1 | 0 | 3672224 | no | no |
| tetragon/observer | 3091 | 6 | 1 | 0 | 460704 | no | yes |
| tetragon/observer | 3097 | 6 | 2 | 0 | 627552 | no | yes |
| tetragon/observer | 3108 | 6 | 1 | 0 | 460704 | no | yes |
| tetragon/observer | 3119 | 6 | 1 | 0 | 1835385 | no | no |
| tetragon/observer | 3126 | 6 | 1 | 1 | 627552 | no | yes |
| tetragon/observer | 3135 | 6 | 1 | 0 | 3672224 | no | no |
| tetragon/observer | 3152 | 6 | 1 | 0 | 1835385 | no | no |
| tetragon/observer | 3155 | 6 | 1 | 0 | 460704 | no | yes |
| tetragon/observer | 3160 | 6 | 2 | 0 | 627552 | no | yes |
| tetragon/observer | 3165 | 6 | 2 | 0 | 627552 | no | yes |
| tetragon/observer | 3166 | 6 | 1 | 0 | 1835385 | no | no |
| tetragon/observer | 3169 | 6 | 1 | 0 | 460704 | no | yes |
| tetragon/observer | 3180 | 6 | 1 | 0 | 3672224 | no | no |
| tetragon/observer | 3189 | 6 | 1 | 0 | 3672224 | no | no |
| tetragon/observer | 3201 | 6 | 2 | 0 | 627552 | no | yes |
| tetragon/observer | 3210 | 6 | 1 | 0 | 460704 | no | yes |
| tetragon/observer | 3211 | 6 | 1 | 0 | 1835385 | no | no |
| tetragon/observer | 3225 | 6 | 1 | 0 | 1835385 | no | no |
| tetragon/observer | 3233 | 6 | 1 | 0 | 460704 | no | yes |
| tetragon/observer | 3235 | 6 | 1 | 0 | 3672224 | no | no |
| tetragon/observer | 3237 | 6 | 2 | 0 | 627552 | no | yes |
| tetragon/observer | 3242 | 6 | 1 | 1 | 627552 | no | yes |
| tetragon/observer | 3253 | 6 | 1 | 0 | 460704 | no | yes |
| tetragon/observer | 3267 | 6 | 1 | 0 | 1835385 | no | no |
| tetragon/observer | 3313 | 6 | 21 | 3 | 3616807 | no | no |
| tetragon/observer | 3403 | 6 | 1 | 0 | 1835385 | no | no |
| tetragon/observer | 3414 | 6 | 1 | 0 | 3672224 | no | no |
| tetragon/observer | 3421 | 6 | 1 | 0 | 460704 | no | yes |
| tetragon/observer | 3425 | 6 | 2 | 0 | 627552 | no | yes |
| tetragon/observer | 3441 | 6 | 1 | 0 | 460704 | no | yes |
| tetragon/observer | 3448 | 6 | 2 | 0 | 627552 | no | yes |
| tetragon/observer | 3451 | 6 | 1 | 0 | 3672224 | no | no |
| tetragon/observer | 3455 | 6 | 1 | 0 | 1835385 | no | no |
| tetragon/observer | 3460 | 6 | 2 | 0 | 627552 | no | yes |
| tetragon/observer | 3466 | 6 | 1 | 0 | 3672224 | no | no |
| tetragon/observer | 3469 | 6 | 1 | 0 | 1835385 | no | no |
| tetragon/observer | 3481 | 6 | 1 | 0 | 460704 | no | yes |
| tetragon/observer | 3521 | 6 | 7 | 0 | 2892592 | no | no |
| tetragon/observer | 3537 | 6 | 1 | 0 | 3672224 | no | no |
| tetragon/observer | 3539 | 6 | 1 | 0 | 1835385 | no | no |
| tetragon/observer | 3547 | 6 | 2 | 0 | 627552 | no | yes |
| tetragon/observer | 3552 | 6 | 1 | 0 | 460704 | no | yes |
| tetragon/observer | 744 | 9 | 8 | 1 | 512526 | no | yes |
| tetragon/observer | 1020 | 9 | 14 | 1 | 8577454 | no | no |
| tetragon/observer | 2840 | 9 | 14 | 2 | 8574254 | no | no |
| tracee/monitor | 3733 | 1 | 39 | 21 | 1036648-15414665 | no | yes |
| tracee/monitor | 3739 | 2 | 1 | 0 | 82093 | yes | yes |
| tracee/monitor | 3740 | 6 | 52 | 26 | 9450041-9450111 | no | no |
| tracee/monitor | 3748 | 6 | 123 | 56 | 3673454-3737950 | no | no |
| tracee/monitor | 3749 | 6 | 2 | 0 | 3595008 | no | no |
| tracee/monitor | 3751 | 6 | 121 | 61 | 105982 | yes | yes |
| tracee/monitor | 3803 | 6 | 1 | 1 | 3673354 | no | no |
| tracee/monitor | 3708 | 9 | 130 | 61 | 17136655-32180040 | no | no |
| tracee/monitor | 3718 | 9 | 123 | 58 | 4757109-5240179 | no | no |
| tracee/monitor | 3752 | 9 | 4 | 4 | 2184591-3038510 | no | no |
| tracee/monitor | 3753 | 9 | 13 | 6 | 224122-10157960 | yes | yes |
| tracee/monitor | 3799 | 9 | 5 | 5 | 91855376 | no | no |
| tracee/monitor | 3800 | 9 | 2 | 2 | 6132674 | no | no |

## Prong B: verifier-state PC alignment audit

I first ran the requested smoke:

```bash
BPFREJIT_BENCH_PASSES='noop,map_inline' BPFREJIT_CORPUS_APPS='tetragon/observer' SAMPLES=1 KEEP_WORKDIRS=all make corpus
```

That produced `corpus/results/x86_kvm_corpus_20260507_033859_357762`. The `KEEP_WORKDIRS=all` plan captured input/output bytecode and reports, but the injected capture command aborts before verifier logs are written. To preserve verifier logs without changing code, I ran a second Makefile-only Tetragon smoke with a deliberately failing third pass:

```bash
BPFREJIT_BENCH_PASSES='noop,map_inline,branch_flip' BPFREJIT_CORPUS_APPS='tetragon/observer' SAMPLES=1 KEEP_WORKDIRS=1 make corpus
```

That produced `corpus/results/x86_kvm_corpus_20260507_034456_818538`. `branch_flip` fails after `noop` and `map_inline` because it requires `--profile`; the preserved tarball for prog id 19 contains:

- `input_step0.bin`
- `output_step0.bin`
- `output_step1.bin`
- `report_step0.json`
- `report_step1.json`
- `verifier_log_step0.log`
- `verifier_log_step1.log`
- `map-values/`

The selected program in the smoke:

| field | value |
|---|---|
| app | `tetragon/observer` |
| prog id | 19 |
| name | `event_exit_acct_process` |
| type | `kprobe` |
| baseline bytes_jited | 1012 |
| baseline bytes_xlated | 1792 |
| baseline run_cnt_delta | 5190 |
| baseline run_time_ns_delta | 7453229 |
| post run_cnt_delta | 5131 |
| post run_time_ns_delta | 7079987 |

The R1 candidate referenced in the request is the same program shape: `event_exit_acct_process`, jit 1012 B, 15,064 baseline runs, 22,845,767 ns in R1.

### map_inline diagnostics for the chosen program

`map_inline` matched four dumpable sites and applied zero rewrites:

```text
maps_skipped_by_size=2
site at PC=22: verifier-guided key extraction failed: verifier log has no state snapshot at call pc 22
site at PC=56: verifier-guided key extraction failed: verifier log has no state snapshot at call pc 56
site at PC=159: verifier-guided key extraction failed: verifier log has no state snapshot at call pc 159
site at PC=170: verifier-guided key extraction failed: verifier log has no state snapshot at call pc 170
```

Re-running `bpfopt` locally against the captured bytecode/log with `BPFREJIT_MAP_INLINE_DEBUG=1` reproduced the same decisions:

| call_pc | map_id | map_type | map_name | decision |
|---:|---:|---|---|---|
| 9 | 8 | hash | `execve_map` | skipped: snapshot size 6,013,402 |
| 22 | 46 | percpu_array | `exit_heap_map` | skipped: no verifier state snapshot at call pc |
| 56 | 7 | array | `tg_conf_map` | skipped: no verifier state snapshot at call pc |
| 78 | 15 | percpu_array | `tg_stats_map` | skipped: snapshot size 1,672,395 |
| 109 | 15 | percpu_array | `tg_stats_map` | skipped: snapshot size 1,672,395 |
| 159 | 10 | percpu_array | `execve_map_stat` | skipped: no verifier state snapshot at call pc |
| 170 | 10 | percpu_array | `execve_map_stat` | skipped: no verifier state snapshot at call pc |

### Bytecode map_lookup call sites

The input to `map_inline` is `output_step0.bin` from the `noop` pass. It contains 177 BPF instructions and 7 `bpf_map_lookup_elem` helper calls.

Map ids supplied to `bpfopt` for the captured program were:

| map index | map_id | type | name | snapshot |
|---:|---:|---|---|---|
| 0 | 8 | hash | `execve_map` | skip_size 6,013,402 |
| 1 | 46 | percpu_array | `exit_heap_map` | dumped, 1 entry |
| 2 | 7 | array | `tg_conf_map` | dumped, 1 entry |
| 3 | 14 | perf_event_array | `tcpmon_map` | skip_type |
| 4 | 15 | percpu_array | `tg_stats_map` | skip_size 1,672,395 |
| 5 | 19 | ringbuf | `tg_rb_events` | skip_type |
| 6 | 10 | percpu_array | `execve_map_stat` | dumped, 3 entries |

Instruction-site table:

| call_pc | map_load_pc | map_index | map_id | map_type | map_name | snapshot decision | key setup |
|---:|---:|---:|---:|---|---|---|---|
| 9 | 7 | 0 | 8 | hash | `execve_map` | skip_size 6,013,402 | `fp-4`, from PCs 4-6 |
| 22 | 20 | 1 | 46 | percpu_array | `exit_heap_map` | dumped | `fp-12`, from PCs 17-19 |
| 56 | 54 | 2 | 7 | array | `tg_conf_map` | dumped | `fp-8`, from PCs 51-53 |
| 78 | 76 | 4 | 15 | percpu_array | `tg_stats_map` | skip_size 1,672,395 | `fp-4`, from PCs 73-75 |
| 109 | 107 | 4 | 15 | percpu_array | `tg_stats_map` | skip_size 1,672,395 | `fp-4`, from PCs 104-106 |
| 159 | 157 | 6 | 10 | percpu_array | `execve_map_stat` | dumped | `fp-4`, from PCs 154-156 |
| 170 | 168 | 6 | 10 | percpu_array | `execve_map_stat` | dumped | `fp-4`, from PCs 165-167 |

### Verifier-state PC list and intersection

Parsing `verifier_log_step0.log` for state-bearing verifier lines yielded:

| metric | value |
|---|---:|
| state records | 240 |
| unique PCs with emitted state | 137 |
| full-state records | 27 |
| instruction-delta records | 213 |

Unique PCs with emitted state:

```text
0-7, 9-16, 18-20, 22-27, 29-32, 35-48, 50-54, 57-61, 63,
65-66, 68-72, 74-76, 78-82, 84-85, 87-88, 90-91, 93, 95-96,
98-100, 102-103, 105-107, 109-114, 116, 118-120, 122, 124-125,
127-128, 130-131, 133, 135, 137, 139, 141-147, 149-153, 155-157,
159-162, 164-168, 170-175
```

Intersection with map lookup call PCs:

| call_pc | raw verifier state at pc? | raw state kind | state at pc-1? | state at pc+1? | bpfopt usable snapshot? |
|---:|---|---|---|---|---|
| 9 | yes | delta | no | yes | not used; map skipped by size |
| 22 | yes | delta | no | yes | no |
| 56 | no | none | no | yes | no |
| 78 | yes | delta | no | yes | not used; map skipped by size |
| 109 | yes | delta | no | yes | not used; map skipped by size |
| 159 | yes | delta | no | yes | no |
| 170 | yes | delta | no | yes | no |

No `[path: P]` notation appeared in this verifier log.

### Missing-PC analysis

The missing-site symptom is not a simple off-by-one. For PC 22, 159, and 170 the raw log does contain a state-bearing line at the call PC, but that line is an instruction delta after the helper call and contains only the return register:

```text
22: ... call bpf_map_lookup_elem#1 ; R0=map_value(map=exit_heap_map,ks=4,vs=40)
159: ... call bpf_map_lookup_elem#1 ; R0=map_value(map=execve_map_stat,ks=4,vs=8)
170: ... call bpf_map_lookup_elem#1 ; R0=map_value_or_null(id=7,map=execve_map_stat,ks=4,vs=8)
```

`kernel_sys::verifier_states_from_log` converts parsed state lines to JSON only when a line has a serialized register or stack field. `convert_reg_state` serializes scalar constants, ranges, tnums, offsets, or precise markers, but a pure `map_value` pointer with no offset/range/const data serializes to nothing. Then `convert_verifier_state` drops the now-empty state. That is why `bpfopt` reports "no state snapshot" for PCs where the raw log has only `R0=map_value...`.

For PC 56, the verifier does not emit a call-PC delta at all. The first post-call non-null state is at PC 57:

```text
57: R0=map_value(map=tg_conf_map,ks=4,vs=48)
```

Even preserving type-only `R0=map_value` states would not be sufficient. `map_inline` needs the pre-call state: `R2` must point to the stack key, and the stack bytes for that key must be known. The verifier log emits those facts as deltas before the helper call, not as a full call-PC snapshot.

Example for failing site PC 22:

| verifier pc | kind | relevant emitted state |
|---:|---|---|
| 18 | full | `R1=0 R10=fp0 fp-16=0000????` |
| 18 | delta | `R2=fp0 R10=fp0` |
| 19 | delta | `R2=fp-12` |
| 20 | delta | `R1=map_ptr(map=exit_heap_map,ks=4,vs=40)` |
| 22 | delta | `R0=map_value(map=exit_heap_map,ks=4,vs=40)` |
| 23 | delta | `R0=map_value(...) R8=map_value(...)` |

The information needed to inline PC 22 exists across the pre-call delta stream: stack slot `fp-16=0000????`, `R2=fp-12`, and `R1=map_ptr`. The current extraction path asks for a single `VerifierInsn` whose `pc == call_pc`, then reads `R2` and stack bytes from that one state. That fails because no cumulative pre-call state is materialized at PC 22.

Example for failing site PC 56:

| verifier pc | kind | relevant emitted state |
|---:|---|---|
| 50 | full | `R0=scalar()` |
| 50 | delta | `R1=0` |
| 51 | delta | `R1=0 R10=fp0 fp-8=mmmm0` |
| 52 | delta | `R2=fp0 R10=fp0` |
| 53 | delta | `R2=fp-8` |
| 54 | delta | `R1=map_ptr(map=tg_conf_map,ks=4,vs=48)` |
| 57 | full | `R0=map_value(map=tg_conf_map,ks=4,vs=48)` |

Again, the pre-call key facts are present before the call, but not as a call-PC full snapshot.

Example for failing site PC 159:

| verifier pc | kind | relevant emitted state |
|---:|---|---|
| 153 | delta | `R1=0` |
| 155 | full | `R1=0 R10=fp0 fp-8=0000mmmm` |
| 155 | delta | `R2=fp0 R10=fp0` |
| 156 | delta | `R2=fp-4` |
| 157 | delta | `R1=map_ptr(map=execve_map_stat,ks=4,vs=8)` |
| 159 | delta | `R0=map_value(map=execve_map_stat,ks=4,vs=8)` |

### Success-site comparison

The two R1 qualified programs with `sites_applied > 0` were:

| app | prog id | program | matched | applied | skipped | applied-site shape |
|---|---:|---|---:|---:|---:|---|
| `otelcol-ebpf-profiler/profiling` | 55 | `native_tracer_entry` | 34 | 30 | 4 | direct pseudo-map-value loads |
| `tracee/monitor` | 579 | `tracepoint__sched__sched_process_fork` | 32 | 1 | 31 | direct pseudo-map-value load |

Their applied diagnostics are all of this form:

```text
constantized pseudo-map-value load from map_id=... off=... value=...
```

The skipped helper sites in those same programs still show the same verifier-guided failure shape:

```text
verifier-guided key extraction failed: verifier log has no state snapshot at call pc ...
```

So the discriminating feature is not a successful helper-lookup verifier-state pattern in the R1 qualified population. The successful sites bypass verifier-guided key extraction entirely because they are direct pseudo-map-value loads. The failing Tetragon sites are helper lookups whose key state is split across verifier deltas before the call.

## Quantified hit-rate impact

Qualified R1 map_inline site totals:

| app | qualified programs | matched sites | applied sites | skipped sites | programs with matched sites | programs with applied sites |
|---|---:|---:|---:|---:|---:|---:|
| bcc/set | 20 | 11 | 0 | 11 | 9 | 0 |
| bpftrace/set | 8 | 13 | 0 | 13 | 5 | 0 |
| katran | 1 | 0 | 0 | 0 | 0 | 0 |
| otelcol-ebpf-profiler/profiling | 1 | 34 | 30 | 4 | 1 | 1 |
| tetragon/observer | 30 | 177 | 0 | 177 | 29 | 0 |
| tracee/monitor | 78 | 936 | 1 | 935 | 66 | 1 |

Across the 138 qualified programs:

- 110 programs had at least one matched `map_inline` site.
- 2 programs had at least one applied site.
- 108 programs had matched sites and zero applied sites.
- 107 of those 108 zero-applied matched programs had direct `no state snapshot` verifier-guided diagnostics.

Top qualified skip reasons:

| reason | count |
|---|---:|
| lookup key is not available from verifier-guided state | 374 |
| map type 10 not inlineable | 50 |
| map-in-map chain is not inlineable | 22 |
| map-in-map outer key unavailable after prior map_inline rewrite | 22 |

Estimated upside: fixing the verifier-state reconstruction issue would plausibly unlock up to about 107 additional qualified programs from "matched but zero applied" into "at least one helper lookup can be considered with a concrete key." That is an upper bound, not a guaranteed applied count, because map type, map-in-map semantics, mutable snapshot policy, and actual snapshot values still gate individual rewrites. For Tetragon alone, the upper bound is 29 additional qualified programs.

The cap-only upside is smaller for the 2/138 question. In the qualified population, 256 KiB unlocks only 4 unique maps and 1 MiB unlocks 20 unique maps. In the chosen Tetragon program, lifting the cap to 1 MiB would not unlock either size-skipped map: `execve_map` is 6,013,402 bytes and `tg_stats_map` is 1,672,395 bytes. The four dumpable sites would still be blocked by verifier-state reconstruction.

## Concrete fix proposals for Prong B

1. Add cumulative verifier-state reconstruction before map_inline key extraction.

   The current extraction path in `bpfopt/crates/bpfopt/src/passes/map_inline.rs` searches for `verifier_states.iter().filter(|state| state.pc == call_pc)` and expects that one state to contain `R2` plus stack bytes. That model does not match the real log: the verifier emits a full state at a prior PC and then instruction deltas for `R2`, stack, and `R1=map_ptr`.

   Proposed fix: build a per-frame, per-path cumulative state stream from the parsed verifier log. Seed from `PcFullState` / `EdgeFullState`; apply each `InsnDeltaState`; emit a synthetic pre-instruction snapshot at the next real PC. For `BPF_LD_IMM64` map loads, the next real PC is `pc + 2`, so the `R1=map_ptr` delta at PC 20 should produce a synthetic pre-call state at PC 22.

2. Preserve pointer-only states in the parser, but do not treat that as sufficient.

   `kernel_sys::convert_reg_state` drops type-only pointer states such as `R0=map_value(...)`. That explains why raw call-PC lines at PC 22, 159, and 170 disappear before `bpfopt` sees them. The parser should preserve `reg_type` for pointer states even without scalar metadata. This will improve diagnostics and keep the converted stream faithful, but it will not by itself unlock map_inline because post-call `R0` still does not contain pre-call `R2`.

3. Make map_inline request pre-call state, not call-result state.

   Introduce an API shaped like `verifier_pre_state_at_pc(call_pc, frame/path)` or materialize synthetic `PcFullState` records tagged as pre-state. The map_inline helper lookup extractor should consume that pre-call state. It should keep the existing "all occurrences must agree" guard when multiple verifier paths reach the same call PC.

4. Use bytecode materialization only after verifier proves the key pointer.

   Some sites have verifier stack slot types that are enough to recover zero keys (`fp-16=0000????`, `fp-8=0000mmmm`). Others, such as PC 170, show the key store in bytecode (`r1 = 2; *(u32 *)(fp-4) = r1`) but the verifier stack slot is not a full constant byte snapshot. A conservative extension is to use reconstructed verifier state for `R2=fp-4`, then use same-block bytecode materialization to compute the bytes only when the store sequence is unambiguous. This remains verifier-guided because the verifier provides the stack pointer and frame; it should not become a non-verifier fallback when `R2` is missing.

5. Add regression coverage against the captured verifier-log shape.

   A useful test would feed a minimal verifier log with:

   ```text
   18: R1=0 R10=fp0 fp-16=0000????
   18: ... ; R2=fp0 R10=fp0
   19: ... ; R2=fp-12
   20: ... ; R1=map_ptr(map=exit_heap_map,ks=4,vs=40)
   22: ... ; R0=map_value(map=exit_heap_map,ks=4,vs=40)
   ```

   The expected synthetic pre-call state at PC 22 should include `R2=fp-12` and the stack bytes needed for a 4-byte zero key. This test would catch the exact current failure without depending on the whole Tetragon binary.

## Final conclusion

Prong B is the bigger lever. The daemon cap explains some missed sites, especially in Tracee and Tetragon, but the R1 applied-site evidence shows that helper lookup inlining is not really firing in the qualified population. The verifier log contains the needed pre-call facts in many failures, but they are split across full-state and delta lines before the helper call. `map_inline` currently asks for a single call-PC snapshot, and the parser also drops pointer-only call-result deltas, so those sites surface as "no state snapshot" rather than as concrete keys.

Fixing verifier-state reconstruction should be prioritized before changing the map snapshot cap. After that fix, the cap can be revisited with a smaller, clearer residual set of size-gated maps.
