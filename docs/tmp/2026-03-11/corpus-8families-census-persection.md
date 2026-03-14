# Scanner-backed 8-Family Directive Census

- Repository root: `/home/yunwei37/workspace/bpf-benchmark`
- Scanner CLI: `/home/yunwei37/workspace/bpf-benchmark/scanner/build/bpf-jit-scanner`
- Raw input set on disk: 67 micro paths + 560 corpus paths
- Corpus source: filesystem scan under `corpus/build`
- Actual `EM_BPF` objects scanned: 67 micro + 560 corpus = 627 total
- Skipped non-BPF `.bpf.o` artifacts: 0
- Method: extract each executable non-dot ELF section, then invoke `bpf-jit-scanner scan --xlated <section> --all --v5`.

## Aggregate Summary

| Metric | Value |
| --- | --- |
| Objects | 627 |
| Objects with >=1 site | 220 |
| Coverage | 35.1% |
| Executable sections | 1545 |
| BPF instructions | 1471661 |
| Total sites | 17637 |
| Average sites per object | 28.13 |
| COND_SELECT sites / objects | 7724 / 135 |
| WIDE_MEM sites / objects | 2987 / 94 |
| ROTATE sites / objects | 2685 / 23 |
| ADDR_CALC sites / objects | 19 / 11 |
| BITFIELD_EXTRACT sites / objects | 557 / 46 |
| ZERO_EXT_ELIDE sites / objects | 0 / 0 |
| ENDIAN_FUSION sites / objects | 1386 / 50 |
| BRANCH_FLIP sites / objects | 2279 / 27 |

## Micro Summary

| Metric | Value |
| --- | --- |
| Objects | 67 |
| Objects with >=1 site | 63 |
| Coverage | 94.0% |
| Executable sections | 67 |
| BPF instructions | 29630 |
| Total sites | 1102 |
| Average sites per object | 16.45 |
| COND_SELECT sites / objects | 47 / 8 |
| WIDE_MEM sites / objects | 155 / 62 |
| ROTATE sites / objects | 865 / 20 |
| ADDR_CALC sites / objects | 5 / 4 |
| BITFIELD_EXTRACT sites / objects | 15 / 6 |
| ZERO_EXT_ELIDE sites / objects | 0 / 0 |
| ENDIAN_FUSION sites / objects | 0 / 0 |
| BRANCH_FLIP sites / objects | 15 / 3 |

## Corpus Summary

| Metric | Value |
| --- | --- |
| Objects | 560 |
| Objects with >=1 site | 157 |
| Coverage | 28.0% |
| Executable sections | 1478 |
| BPF instructions | 1442031 |
| Total sites | 16535 |
| Average sites per object | 29.53 |
| COND_SELECT sites / objects | 7677 / 127 |
| WIDE_MEM sites / objects | 2832 / 32 |
| ROTATE sites / objects | 1820 / 3 |
| ADDR_CALC sites / objects | 14 / 7 |
| BITFIELD_EXTRACT sites / objects | 542 / 40 |
| ZERO_EXT_ELIDE sites / objects | 0 / 0 |
| ENDIAN_FUSION sites / objects | 1386 / 50 |
| BRANCH_FLIP sites / objects | 2264 / 24 |

## Family Summary

| Family | All Sites | All Objects | Micro Sites | Micro Objects | Corpus Sites | Corpus Objects |
| --- | --- | --- | --- | --- | --- | --- |
| COND_SELECT | 7724 | 135 | 47 | 8 | 7677 | 127 |
| WIDE_MEM | 2987 | 94 | 155 | 62 | 2832 | 32 |
| ROTATE | 2685 | 23 | 865 | 20 | 1820 | 3 |
| ADDR_CALC | 19 | 11 | 5 | 4 | 14 | 7 |
| BITFIELD_EXTRACT | 557 | 46 | 15 | 6 | 542 | 40 |
| ZERO_EXT_ELIDE | 0 | 0 | 0 | 0 | 0 | 0 |
| ENDIAN_FUSION | 1386 | 50 | 0 | 0 | 1386 | 50 |
| BRANCH_FLIP | 2279 | 27 | 15 | 3 | 2264 | 24 |

## Project Summary

| Project | Objects | With Sites | Total | CMOV | WIDE | ROTATE | LEA | EXTRACT | ZEROEXT | ENDIAN | BFLIP |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| tetragon | 23 | 12 | 4245 | 3194 | 676 | 0 | 14 | 115 | 0 | 40 | 206 |
| tracee | 2 | 1 | 3806 | 1729 | 229 | 0 | 0 | 49 | 0 | 8 | 1791 |
| linux-selftests | 369 | 58 | 2082 | 142 | 15 | 1810 | 0 | 55 | 0 | 57 | 3 |
| loxilb | 3 | 3 | 2027 | 188 | 1729 | 0 | 0 | 64 | 0 | 42 | 4 |
| cilium | 3 | 3 | 1506 | 737 | 0 | 0 | 0 | 198 | 0 | 341 | 230 |
| calico | 8 | 8 | 1302 | 361 | 108 | 10 | 0 | 37 | 0 | 786 | 0 |
| micro | 67 | 63 | 1102 | 47 | 155 | 865 | 5 | 15 | 0 | 0 | 15 |
| coroot-node-agent | 1 | 1 | 998 | 910 | 32 | 0 | 0 | 0 | 0 | 56 | 0 |
| KubeArmor | 3 | 3 | 138 | 121 | 16 | 0 | 0 | 0 | 0 | 1 | 0 |
| xdp-tools | 13 | 11 | 113 | 88 | 1 | 0 | 0 | 3 | 0 | 17 | 4 |
| xdp-tutorial | 25 | 18 | 100 | 61 | 22 | 0 | 0 | 3 | 0 | 13 | 1 |
| scx | 4 | 4 | 70 | 49 | 0 | 0 | 0 | 2 | 0 | 0 | 19 |
| bcc | 57 | 13 | 66 | 59 | 0 | 0 | 0 | 2 | 0 | 1 | 4 |
| opentelemetry-ebpf-profiler | 3 | 3 | 30 | 18 | 0 | 0 | 0 | 0 | 0 | 12 | 0 |
| katran | 5 | 2 | 20 | 9 | 4 | 0 | 0 | 2 | 0 | 5 | 0 |
| suricata | 2 | 2 | 11 | 3 | 0 | 0 | 0 | 8 | 0 | 0 | 0 |
| systemd | 6 | 3 | 6 | 6 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| real_world_code_size | 15 | 5 | 5 | 0 | 0 | 0 | 0 | 2 | 0 | 2 | 1 |
| libbpf-bootstrap | 12 | 4 | 4 | 0 | 0 | 0 | 0 | 2 | 0 | 1 | 1 |
| netbird | 1 | 1 | 4 | 0 | 0 | 0 | 0 | 0 | 0 | 4 | 0 |
| datadog-agent | 2 | 1 | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| tubular | 1 | 1 | 1 | 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| manual-test | 2 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |

## Top 15 Corpus Objects By Total Sites

| Object | Insns | Secs | CMOV | WIDE | ROTATE | LEA | EXTRACT | ZEROEXT | ENDIAN | BFLIP | Total |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/tracee/tracee.bpf.o | 436191 | 156 | 1729 | 229 | 0 | 0 | 49 | 0 | 8 | 1791 | 3806 |
| corpus/build/tetragon/bpf_generic_lsm_core.bpf.o | 50785 | 2 | 1646 | 74 | 0 | 0 | 3 | 0 | 5 | 17 | 1745 |
| corpus/build/loxilb/llb_ebpf_emain.bpf.o | 37763 | 8 | 94 | 863 | 0 | 0 | 32 | 0 | 21 | 2 | 1012 |
| corpus/build/loxilb/llb_ebpf_main.bpf.o | 37765 | 8 | 94 | 863 | 0 | 0 | 32 | 0 | 21 | 2 | 1012 |
| corpus/build/coroot-node-agent/ebpf.bpf.o | 37060 | 46 | 910 | 32 | 0 | 0 | 0 | 0 | 56 | 0 | 998 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_verif_scale2.bpf.o | 14750 | 1 | 0 | 0 | 992 | 0 | 0 | 0 | 0 | 0 | 992 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/core_kern.bpf.o | 15766 | 5 | 0 | 0 | 818 | 0 | 0 | 0 | 0 | 0 | 818 |
| corpus/build/cilium/bpf_lxc.bpf.o | 41873 | 2 | 336 | 0 | 0 | 0 | 138 | 0 | 106 | 0 | 580 |
| corpus/build/cilium/bpf_xdp.bpf.o | 26121 | 2 | 231 | 0 | 0 | 0 | 28 | 0 | 85 | 230 | 574 |
| corpus/build/tetragon/bpf_generic_usdt.bpf.o | 19633 | 3 | 260 | 155 | 0 | 2 | 22 | 0 | 5 | 35 | 479 |
| corpus/build/tetragon/bpf_generic_uprobe.bpf.o | 21548 | 3 | 307 | 98 | 0 | 2 | 22 | 0 | 5 | 35 | 469 |
| corpus/build/tetragon/bpf_generic_kprobe.bpf.o | 19321 | 4 | 307 | 88 | 0 | 2 | 22 | 0 | 5 | 35 | 459 |
| corpus/build/tetragon/bpf_generic_rawtp.bpf.o | 16287 | 2 | 260 | 73 | 0 | 2 | 22 | 0 | 5 | 35 | 397 |
| corpus/build/cilium/bpf_overlay.bpf.o | 29582 | 2 | 170 | 0 | 0 | 0 | 32 | 0 | 150 | 0 | 352 |
| corpus/build/tetragon/bpf_generic_tracepoint.bpf.o | 17605 | 2 | 181 | 84 | 0 | 2 | 22 | 0 | 5 | 35 | 329 |

## Analysis

- Corpus coverage is `157/560` objects with sites, or `28.0%`.
- By raw site count, `COND_SELECT` is the largest family in the corpus (7677 sites).
- By object coverage, `COND_SELECT` appears in the widest set of corpus objects (127 objects).
- Highest-density corpus objects: `corpus/build/tracee/tracee.bpf.o` (3806), `corpus/build/tetragon/bpf_generic_lsm_core.bpf.o` (1745), `corpus/build/loxilb/llb_ebpf_emain.bpf.o` (1012).
- New-family corpus totals: `ZERO_EXT_ELIDE` = 0 sites across 0 corpus objects; `ENDIAN_FUSION` = 1386 sites across 50 corpus objects; `BRANCH_FLIP` = 2264 sites across 24 corpus objects.
- Top projects by total sites: `tetragon` (4245), `tracee` (3806), `linux-selftests` (2082), `loxilb` (2027), `cilium` (1506).
- These are raw scanner-backed candidate counts over ELF program sections, not live xlated acceptance counts.
