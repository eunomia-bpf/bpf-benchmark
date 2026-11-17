# Frozen breadth baseline before the joined helper batch

Recorded 2026-11-17T12:04:03Z. The coordinator's round on image fc7c4707
completed at 11:54:51Z through the frozen entry, stats off, three samples
of 180 seconds per arm on CPUs 0–7. Source series and installed-byte
receipts are in `../breadth-20261117/summary.txt`; raw logs remain at
`/workspaces/kprog-raw/breadth-20261117`.

Throughput is the existing reader's ratio of arm medians. Paired ratios
retain the sample order and are not replaced by that aggregate. Installed
bytes use cumulative native replacements matched to their JIT loads,
rather than unique truncated program names.

| App | Run suffix | Throughput native/eBPF | Paired sample ratios | Native / JIT bytes | Replacements |
|---|---|---:|---|---:|---:|
| OTel | 091405_442941 | 1.053x | 1.053 / 1.084 / 1.044 | 135,767 / 167,706 | 14 |
| BCC | 094120_596590 | 0.998x | 0.998 / 0.996 / 1.004 | 8,677 / 7,965 | 25 |
| Cilium | 100803_814231 | 2.819x | 3.277 / 2.622 / 2.797 | 484,353 / 581,577 | 113 |
| Tetragon | 103459_412261 | 1.042x | 1.049 / 1.036 / 1.042 | 2,078,688 / 2,472,912 | 288 |
| Tracee | 110157_163893 | 0.886x | 0.719 / 0.880 / 0.945 | 1,761,243 / 2,068,918 | 169 |
| Katran | 113013_185030 | 1.086x | 0.754 / 1.101 / 1.237 | 9,442 / 13,641 | 1 |

Each suffix identifies `corpus/results/x86_kvm_corpus_20261117_<suffix>`.
Cilium retains the configuration/work difference described in the main
review and is not an equal-work gain. Stats off supplies no per-call
time or body/helper/map split for any row. All native/JIT installed-byte
ratios exceed the 0.5 target; BCC exceeds 1.0.

Tracee's native sample rates rise from 273,773 to 338,245 to 360,468 while
its eBPF rates are 380,788 / 384,279 / 381,586. Katran's eBPF rates are
2,606,644 / 2,536,862 / 2,228,014; native rates are
1,966,650 / 2,792,890 / 2,755,961. These series do not isolate a compiler
or helper effect. They remain recorded without discarding a sample.

The archive reader reports a summed pktgen error count of 2,121,429,769
for Katran, while the app status is `ok` and its app-level error string is
empty. The raw per-thread pktgen reports retain their counters. This is
not evidence assigning those errors to BPF drops or to either linker;
the other five rows report zero workload errors in the existing reader.

The queued clock image starts building from 53d6c80ce at 11:59:07Z. Its
source joins clock LTO, 6066b311b task-BTF/jiffies loads, 8273b93af tail
frame accounting and 53d6c80ce user/compat string leaves. A subsequent
Tracee change must be attributed to those joined inputs, with per-call
and installed-size evidence, rather than assigned solely to the clock.
Batch 2 follows its image snapshot and adds credential/string-loop/
Cilium-switch changes. This baseline record changes no workload, timing
entry, source input or queue.
