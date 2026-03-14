# Real Program Directive Census

- Repository root: `/home/yunwei37/workspace/bpf-benchmark`
- Scanner CLI: `/home/yunwei37/workspace/bpf-benchmark/scanner/build/bpf-jit-scanner`
- Raw input set on disk: 67 micro paths + 560 corpus paths
- Corpus source: filesystem scan under `corpus/build`
- Actual `EM_BPF` objects scanned: 67 micro + 560 corpus = 627 total
- Skipped non-BPF `.bpf.o` artifacts: 0
- Method: extract each executable non-dot ELF section, then invoke `bpf-jit-scanner scan <section> --all --v5`.

## Aggregate Summary

| Metric | Value |
| --- | --- |
| Objects | 627 |
| Objects with >=1 site | 206 |
| Coverage | 32.9% |
| Executable sections | 1545 |
| BPF instructions | 1471661 |
| Total sites | 15682 |
| Average sites per object | 25.01 |
| CMOV sites / objects | 9430 / 138 |
| WIDE_MEM sites / objects | 2987 / 94 |
| ROTATE sites / objects | 2687 / 24 |
| BITFIELD_EXTRACT sites / objects | 559 / 47 |
| LEA sites / objects | 19 / 11 |

## Micro Summary

| Metric | Value |
| --- | --- |
| Objects | 67 |
| Objects with >=1 site | 63 |
| Coverage | 94.0% |
| Executable sections | 67 |
| BPF instructions | 29630 |
| Total sites | 1089 |
| Average sites per object | 16.25 |
| CMOV sites / objects | 47 / 8 |
| WIDE_MEM sites / objects | 155 / 62 |
| ROTATE sites / objects | 867 / 21 |
| BITFIELD_EXTRACT sites / objects | 15 / 6 |
| LEA sites / objects | 5 / 4 |

## Corpus Summary

| Metric | Value |
| --- | --- |
| Objects | 560 |
| Objects with >=1 site | 143 |
| Coverage | 25.5% |
| Executable sections | 1478 |
| BPF instructions | 1442031 |
| Total sites | 14593 |
| Average sites per object | 26.06 |
| CMOV sites / objects | 9383 / 130 |
| WIDE_MEM sites / objects | 2832 / 32 |
| ROTATE sites / objects | 1820 / 3 |
| BITFIELD_EXTRACT sites / objects | 544 / 41 |
| LEA sites / objects | 14 / 7 |

## Top Objects By Total Sites

| Object | Insns | Secs | CMOV | WIDE | ROTATE | EXTRACT | LEA | Total |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| corpus/build/tracee/tracee.bpf.o | 436191 | 156 | 3191 | 229 | 0 | 49 | 0 | 3469 |
| corpus/build/tetragon/bpf_generic_lsm_core.bpf.o | 50785 | 2 | 1648 | 74 | 0 | 3 | 0 | 1725 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_verif_scale2.bpf.o | 14750 | 1 | 0 | 0 | 992 | 0 | 0 | 992 |
| corpus/build/loxilb/llb_ebpf_emain.bpf.o | 37763 | 8 | 94 | 863 | 0 | 32 | 0 | 989 |
| corpus/build/loxilb/llb_ebpf_main.bpf.o | 37765 | 8 | 94 | 863 | 0 | 32 | 0 | 989 |
| corpus/build/coroot-node-agent/ebpf.bpf.o | 37060 | 46 | 910 | 32 | 0 | 0 | 0 | 942 |
| corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/core_kern.bpf.o | 15766 | 5 | 0 | 0 | 818 | 0 | 0 | 818 |
| corpus/build/cilium/bpf_xdp.bpf.o | 26121 | 2 | 461 | 0 | 0 | 28 | 0 | 489 |
| corpus/build/cilium/bpf_lxc.bpf.o | 41873 | 2 | 336 | 0 | 0 | 138 | 0 | 474 |
| corpus/build/tetragon/bpf_generic_usdt.bpf.o | 19633 | 3 | 261 | 155 | 0 | 22 | 2 | 440 |
| corpus/build/tetragon/bpf_generic_uprobe.bpf.o | 21548 | 3 | 308 | 98 | 0 | 22 | 2 | 430 |
| corpus/build/tetragon/bpf_generic_kprobe.bpf.o | 19321 | 4 | 308 | 88 | 0 | 22 | 2 | 420 |
| corpus/build/tetragon/bpf_generic_rawtp.bpf.o | 16287 | 2 | 261 | 73 | 0 | 22 | 2 | 358 |
| corpus/build/tetragon/bpf_generic_tracepoint.bpf.o | 17605 | 2 | 182 | 84 | 0 | 22 | 2 | 290 |
| corpus/build/cilium/bpf_overlay.bpf.o | 29582 | 2 | 170 | 0 | 0 | 32 | 0 | 202 |

## Analysis

- Corpus coverage is `143/560` objects with sites, or `25.5%`.
- By raw site count, `CMOV` is the largest family in the corpus (9383 sites).
- By object coverage, `CMOV` appears in the widest set of corpus objects (130 objects).
- Highest-density corpus objects: `corpus/build/tracee/tracee.bpf.o` (3469), `corpus/build/tetragon/bpf_generic_lsm_core.bpf.o` (1725), `corpus/build/linux-selftests/tools/testing/selftests/bpf/progs/test_verif_scale2.bpf.o` (992).
- These are raw scanner-backed candidate counts over ELF program sections, not live xlated acceptance counts.
