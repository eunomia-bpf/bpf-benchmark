# AArch64 native-only application coverage, 2026-11-07 UTC

The trusted QEMU transport now accepts all six existing corpus app selectors through the retained standard two-start `corpus.driver` recipe. The application submits native ELF; the registered common service generates and binds fresh proofs. No application proof is supplied. Katran uses the same two-start counter protocol as the other five applications. The retained v35 root, canonical kernel/modules, loader and native-link are reused without rebuilding the image or kernel.

Reproduction from `/workspaces/repository`:

```sh
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile trusted-service-arm64-run TRUSTED_APP=otelcol-ebpf-profiler TRUSTED_RESULTS=corpus/results/kprog_arm64_app_coverage_20261107
```

Set `TRUSTED_APP` to `bcc`, `otelcol-ebpf-profiler`, `cilium`, `tetragon`, `katran`, or `tracee`. The existing control remains the default. Each app guest uses 8 GiB and host CPUs 8-11; run them serially. Existing `SAMPLES=1`, `WORKLOAD_DURATION=2`, BPF stats and native-only proof requirements are preserved. Only the existing app selector is replaced in a private copy of the retained launcher. Tracee/Tetragon use their actual packaged `/artifacts` root; the other applications retain the existing artifact root. OTel data-object paths and native entries both become absolute before moving the manifest.

`transport-preflight.json` records actual manifest/ELF hashes, all six Make dry runs and shell/environment checks. Counts below describe the recorded preflight selector snapshot, including probes and variants; they are not loaded-program or verifier-acceptance denominators.

| Application | Packaged selectors | Extra data objects | Current native-only full application |
| --- | ---: | ---: | --- |
| BCC | 32 | 0 | Closed error: 16 bound, 3 retry-loop rejections; native workload not reached |
| OTel | 36 | 15 | Closed: first proof refused for readonly-byte mismatch |
| Cilium | 98 | 0 | Closed: readonly features.h startup error |
| Tetragon | 245 | 0 | Closed:152baseline rows, mixed-call selector missing |
| Katran | 12 | 0 | Pending current native-only two-start run |
| Tracee | 123 | 0 | Pending current native-only run |

The BCC job and collector have closed and published [bcc-full-start](../kprog_arm64_app_coverage_20261106/bcc-full-start/trusted-arm64-bcc-result/). Its reviewed inventory, proof/verifier counts and work counters are recorded below; it remains an application error. The existing serial queue retains later application results separately; the closed first-pass cohorts are consolidated in [the observed coverage table](coverage-table.md). The older [six-app startup census](../kprog_arm64_app_coverage_20261106/runtime-context-v11/README.md) and [29-micro evidence](../kprog_arm64_app_coverage_20261106/memory-extension/README.md) remain historical evidence with their original paths and inputs; they are not relabeled as current native-only acceptance.

The private broad exclusive-retry convergence candidate is not adopted: its [closed constant-cycle diagnostic](../kprog_arm64_app_coverage_20261106/trusted-exclusive-retry-result/candidate-constant-cycle/trusted-arm64-service-result/README.md) found load-time admissions that require repair. Canonical kernel/module hashes remain unchanged. No unsafe native execution was performed. All six applications and the remaining O1-O4 obligations are still incomplete. QEMU timing is functional only; Spark performance runs remain deferred by current coordination priorities.


## Closed BCC full-start result

[The complete native-only BCC startup](../kprog_arm64_app_coverage_20261106/bcc-full-start/trusted-arm64-bcc-result/README.md) has 23 baseline resident counter rows, 19 distinct source-program requests, 19 emitted/compiled proof artifacts, 16 bound acceptances and three verifier rejections. The three errors are `infinite loop detected` in vfsstat `fentry_vfs_read`, syscount `sys_exit` and runqlat `sched_switch`. There were zero specialization failures among those 19 requests. BCC reports vfsstat exit97 and never reaches native workload measurement; the baseline four-stressor workload and all per-program counters remain in [bcc-full-start-coverage.json](bcc-full-start-coverage.json). The baseline and requested-program counts have distinct denominators; startup stopped before every baseline entry received a native request.

| Baseline resident rows | Distinct requested source IDs | Proofs compiled | Bound accepted | Specialization failed | Verifier rejected | Native workload |
| ---: | ---: | ---: | ---: | ---: | ---: | --- |
| 23 | 19 | 19 | 16 | 0 | 3 infinite-loop | Not reached |

All 19 closed request identities match the kernel-owned native ELF; no unfinished request directory remained. Host status is false and guest exit1. Physical source hashes changed during this already-running guest; the raw archive retains its original source capture and drift record. Its result is not relabeled as an unchanged-source run. The broad retry-convergence kernel candidate is not applied and its separate findings remain open.

## Katran behavior audit

[Direct raw-record review](katran-behavior-review.json) of the already published 14:59 native-only Katran run finds 19,391 pktgen packets, 19,391 bound-native program runs and 19,391 receiver packets. The LRU total is 19,391 and its miss field is 1; this ARM run does not miss on every packet. The fallback-LRU selection counter is 19,391, which counts selection of the fallback cache rather than misses. The separate `lru_miss` entry is the TCP SYN/non-SYN breakdown, so its zero fields are not used as the generic UDP miss count. Drop, pass, encapsulation-failure and consistent-hash-drop counters are zero in the retained record.

This audit uses the same exact archived work.json, native identity and generation-bound receipt, without rerunning or changing the workload. The worker was subsequently promoted in b89015df9; the historical one-arm run is not presented as a new current two-start comparison. The new two-start Katran replay remains in the serial queue. QEMU values here establish functional work, not performance.
