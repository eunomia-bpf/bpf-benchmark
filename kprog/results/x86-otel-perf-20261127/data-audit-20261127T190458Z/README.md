# Performance data review

The inventory reads 4474 available metadata paths and expands multi-application records to 5866 rows. It retains 258 metadata paths with no remaining app JSON and separately lists 417 canonical directories without metadata. It does not decode every historical archive or certify every old run's native coverage.

All 5866 rows have empty inspected top-level image fields, and all 5866 have empty inspected top-level source-commit fields. These schema checks do not prove that nested fields or sidecars lack provenance. Batch READMEs and launcher receipts must supply those identities. The native-size, coverage and code-change receipts remain necessary for causal comparisons. Spark guest clocks often start in1970; their batch path/README supplies chronology. AWS, Docker, Workspace QEMU and Spark are separate cohorts.

There is no single monotonic slowdown in these records. There are real large absolute-latency changes, reference-correctness changes, run spread and ratio changes caused partly by the eBPF denominator. The20% per-call/30% throughput targets remain open.

## Recent x86 full timing

These are all available successful x86 KVM3x180 stats-on observations from the corrected-reference batch beginning11-22 afternoon;10s checks and PMU profiles are excluded. Older points remain in the inventory. One must not treat this chronological table as an isolated code intervention.

| App | Run / batch | eBPF ns | Native ns | Per-call ratio |
|---|---|---:|---:|---:|
| bcc/set | x86_kvm_corpus_20261122_152855_732291 | 103.4 | 104.1 | 0.9932 |
| bcc/set | x86_kvm_corpus_20261123_111038_481045 | 106.4 | 108.1 | 0.9841 |
| bcc/set | x86_kvm_corpus_20261124_063937_100806 | 111.8 | 110.1 | 1.0151 |
| cilium/agent | x86_kvm_corpus_20261122_155511_408865 | 622.9 | 1350.7 | 0.4612 |
| cilium/agent | x86_kvm_corpus_20261123_113701_916596 | 726.7 | 602.9 | 1.2054 |
| cilium/agent | x86_kvm_corpus_20261123_221708_962433 | 678.0 | 613.6 | 1.1050 |
| cilium/agent | x86_kvm_corpus_20261124_054725_460151 | 743.7 | 595.8 | 1.2482 |
| katran | x86_kvm_corpus_20261122_171542_684932 | 176.8 | 175.6 | 1.0066 |
| katran | x86_kvm_corpus_20261123_125701_042461 | 180.1 | 179.8 | 1.0015 |
| katran | x86_kvm_corpus_20261123_233751_015523 | 182.5 | 175.1 | 1.0420 |
| otelcol-ebpf-profiler/profiling | x86_kvm_corpus_20261122_150245_285011 | 3201.7 | 3393.5 | 0.9435 |
| otelcol-ebpf-profiler/profiling | x86_kvm_corpus_20261123_104425_910099 | 3161.2 | 3399.6 | 0.9299 |
| otelcol-ebpf-profiler/profiling | x86_kvm_corpus_20261123_215059_132597 | 3183.7 | 3371.2 | 0.9444 |
| otelcol-ebpf-profiler/profiling | x86_kvm_corpus_20261124_061344_709703 | 3374.7 | 3458.7 | 0.9757 |
| tetragon/observer | x86_kvm_corpus_20261122_162144_505539 | 740.2 | 330.9 | 2.2367 |
| tetragon/observer | x86_kvm_corpus_20261123_120320_002937 | 748.0 | 318.1 | 2.3514 |
| tetragon/observer | x86_kvm_corpus_20261123_224344_726413 | 3107.5 | 1080.5 | 2.8760 |
| tetragon/observer | x86_kvm_corpus_20261124_052119_515978 | 2666.2 | 956.3 | 2.7882 |
| tetragon/observer | x86_kvm_corpus_20261124_073447_416791 | 3428.5 | 1469.3 | 2.3335 |
| tracee/monitor | x86_kvm_corpus_20261122_164820_504768 | 365.6 | 183.9 | 1.9875 |
| tracee/monitor | x86_kvm_corpus_20261123_122951_540329 | 378.8 | 211.3 | 1.7925 |
| tracee/monitor | x86_kvm_corpus_20261123_231055_765801 | 411.1 | 194.6 | 2.1125 |

OTel's valid full-run native values span3371.2–3458.7ns while its ratio spans0.9299–0.9757. A better ratio does not imply a lower absolute native latency: the latest eBPF denominator is also larger. BCC likewise moves from104.1 to110.1native ns while its denominator rises enough for the ratio to improve. Cilium's11-22 clock-address defect is documented by the linker correction; after it, native is602.9/613.6/595.8ns, rather than a monotonic decline. Tetragon's large late-start latency rise affects both arms and is not hidden by its2x–3x ratios. Existing current-image evidence localizes much of the slow tracepoint to kernel ring-buffer locking, with static code equality; dynamic lock/path parity remains to check.

The pre-correction OTel1.849x and Katran fast historical references are not valid equal-work floors (documented perf-context and wrong-map lookup defects). Their raw numbers remain available; they are not promoted as best valid production results. Tracee's early0.047x capture is a diagnosed faulty read-address-policy path, not the current implementation.

## Spark full timing, batches5–8

Only documented Spark batches are listed here; guest1970 timestamps are not used as wall-clock dates.

| App | Run / batch | eBPF ns | Native ns | Per-call ratio |
|---|---|---:|---:|---:|
| bcc/set | Spark run5 | 93.3 | 98.0 | 0.9517 |
| bcc/set | Spark run6 | 93.0 | 99.2 | 0.9377 |
| bcc/set | Spark run7 | 93.2 | 97.5 | 0.9561 |
| bcc/set | Spark run8 | 94.6 | 97.5 | 0.9706 |
| cilium/agent | Spark run5 | 1000.6 | 985.7 | 1.0151 |
| cilium/agent | Spark run6 | 995.3 | 978.7 | 1.0169 |
| cilium/agent | Spark run7 | 1012.3 | 978.2 | 1.0348 |
| cilium/agent | Spark run8 | 988.4 | 969.4 | 1.0196 |
| katran | Spark run5 | 165.3 | 172.8 | 0.9568 |
| katran | Spark run6 | 162.8 | 174.6 | 0.9321 |
| katran | Spark run7 | 164.5 | 172.4 | 0.9540 |
| katran | Spark run8 | 164.2 | 165.3 | 0.9932 |
| otelcol-ebpf-profiler/profiling | Spark run5 | 253.1 | 252.1 | 1.0043 |
| otelcol-ebpf-profiler/profiling | Spark run6 | 261.8 | 257.5 | 1.0169 |
| otelcol-ebpf-profiler/profiling | Spark run8 | 253.6 | 240.4 | 1.0548 |
| tetragon/observer | Spark run5 | 446.0 | 322.2 | 1.3842 |
| tetragon/observer | Spark run6 | 446.8 | 322.7 | 1.3845 |
| tetragon/observer | Spark run7 | 450.4 | 321.7 | 1.4001 |
| tetragon/observer | Spark run8 | 447.8 | 312.1 | 1.4346 |
| tracee/monitor | Spark run5 | 334.1 | 210.8 | 1.5853 |
| tracee/monitor | Spark run6 | 332.9 | 217.0 | 1.5340 |
| tracee/monitor | Spark run8 | 334.2 | 203.1 | 1.6451 |

Cilium run7→run8: native978.2→969.4ns is about0.9% lower, while eBPF1012.3→988.4ns is about2.4% lower. Its per-call ratio therefore falls1.035→1.020 despite the lower native latency. The separate stats-off throughput1.124→1.009 also needs absolute throughput and workload/error context; it is not a per-call metric. Run8's other per-call ratios improve, but BCC/Katran still remain below1 and below the requested margin.

## Current diagnostic and next cause check

The current-image OTel PMU run is1x10/stats-on, not a new full rotation. It measures3193.13/3287.88ns,0.97118x. The current native unwinder body has fewer sampled periods per entry; the largest positive named kernel difference is trie_lookup_elem. Both phases execute that same kernel function. This does not prove more expensive individual trie calls: dynamic helper-call counts, queried keys and trie paths remain unmeasured. Do not rewrite the kernel or add app-specific routes from flat samples alone.

The existing common cmov change's paired short check is3326.1/3463.1ns, versus3506.3/3726.9 before. It also has a mechanism profile showing fewer dependent cmovs/array-helper stalls. Those starts do not supply a new full-rotation gain; the current full x86 timing remains frozen.

## Provenance references

- kprog/results/x86-rotate-20261122/README.md
- kprog/results/x86-rotate-20261123/README.md
- kprog/results/inner-template-20261123/x86-rotate.md
- kprog/results/cmov-branches-20261126/README.md
- kprog/results/profile-20261123/README-otel.md
- kprog/results/arm64-spark-run5-20261123/README.md
- kprog/results/arm64-spark-run6-20261124/README.md
- kprog/results/arm64-spark-run7-20261124/README.md
- kprog/results/arm64-spark-run8-20261126/README.md

The inventory preserves source paths, app/metadata hashes, phase program/active counts, sample counts, throughput samples, errors and missingness. It supports a broad audit; it does not silently manufacture absent image/source provenance or treat failed/incomplete runs as performance gains.
