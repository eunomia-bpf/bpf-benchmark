# AArch64 native-only application coverage, 2026-11-07 UTC

The trusted QEMU transport now accepts all six existing corpus app selectors through the retained standard two-start `corpus.driver` recipe. The application submits native ELF; the registered common service generates and binds fresh proofs. Applications supply native ELF bytes and metadata; fresh verifier artifacts originate in the registered service. Katran uses the same two-start counter protocol as the other five applications. The retained v35 root, canonical kernel/modules, loader and native-link reuse the existing image and kernel builds.

Reproduction from `/workspaces/repository`:

```sh
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile trusted-service-arm64-run TRUSTED_APP=otelcol-ebpf-profiler TRUSTED_RESULTS=corpus/results/kprog_arm64_app_coverage_20261107
```

Set `TRUSTED_APP` to `bcc`, `otelcol-ebpf-profiler`, `cilium`, `tetragon`, `katran`, or `tracee`. The existing control remains the default. Each app guest uses 8 GiB and host CPUs 8-11; run them serially. Existing `SAMPLES=1`, `WORKLOAD_DURATION=2`, BPF stats and native-only proof requirements are preserved. Only the existing app selector is replaced in a private copy of the retained launcher. Tracee/Tetragon use their actual packaged `/artifacts` root; the other applications retain the existing artifact root. OTel data-object paths and native entries both become absolute before moving the manifest.

`transport-preflight.json` records actual manifest/ELF hashes, all six Make dry runs and shell/environment checks. Counts below describe the recorded preflight selector snapshot, including probes and variants; loaded-program and verifier-acceptance denominators come from the recorded application runs.

| Application | Packaged selectors | Extra data objects | Current native-only full application |
| --- | ---: | ---: | --- |
| BCC | 32 | 0 | Closed error: 16 bound, 3 retry-loop rejections; startup aborts before native measurement |
| OTel | 36 | 15 | Closed: first proof refused for readonly-byte mismatch |
| Cilium | 98 | 0 | Closed: readonly features.h startup error |
| Tetragon | 245 | 0 | Closed:152baseline rows; feature-probe descriptor identity mismatch |
| Katran | 12 | 0 | Guest/app completed; one generated, compiled and bound request |
| Tracee | 123 | 0 | Pending current native-only run |

The BCC job and collector have closed and published [bcc-full-start](../kprog_arm64_app_coverage_20261106/bcc-full-start/trusted-arm64-bcc-result/). Its reviewed inventory, proof/verifier counts and work counters are recorded below; it remains an application error. The existing serial queue retains later application results separately; the closed first-pass cohorts are consolidated in [the observed coverage table](coverage-table.md). The older [six-app startup census](../kprog_arm64_app_coverage_20261106/runtime-context-v11/README.md) and [29-micro evidence](../kprog_arm64_app_coverage_20261106/memory-extension/README.md) remain historical evidence with their original paths and inputs; current native-only outcomes retain their separate source epochs and runtime records.

The canonical kernel and module remain the active path. The private broad exclusive-retry convergence candidate has an open defect: its [closed constant-cycle diagnostic](../kprog_arm64_app_coverage_20261106/trusted-exclusive-retry-result/candidate-constant-cycle/trusted-arm64-service-result/README.md) found load-time admissions that require repair. Canonical kernel/module hashes remain unchanged. Unsafe native execution count is zero. Six-application closure and O1-O4 theorem work continue. QEMU timing is functional only; Spark performance runs remain deferred by current coordination priorities.


## Closed BCC full-start result

[The complete native-only BCC startup](../kprog_arm64_app_coverage_20261106/bcc-full-start/trusted-arm64-bcc-result/README.md) has 23 baseline resident counter rows, 19 distinct source-program requests, 19 emitted/compiled proof artifacts, 16 bound acceptances and three verifier rejections. The three errors are `infinite loop detected` in vfsstat `fentry_vfs_read`, syscount `sys_exit` and runqlat `sched_switch`. There were zero specialization failures among those 19 requests. BCC reports vfsstat exit97 during startup before native workload measurement; the baseline four-stressor workload and all per-program counters remain in [bcc-full-start-coverage.json](bcc-full-start-coverage.json). The baseline and requested-program counts have distinct denominators; startup stopped before every baseline entry received a native request.

| Baseline resident rows | Distinct requested source IDs | Proofs compiled | Bound accepted | Specialization failed | Verifier rejected | Native workload |
| ---: | ---: | ---: | ---: | ---: | ---: | --- |
| 23 | 19 | 19 | 16 | 0 | 3 infinite-loop | Startup abort |

All 19 closed request identities match the kernel-owned native ELF, and each request has a terminal archive. Host status is false and guest exit1. Physical source hashes changed during this already-running guest; the raw archive retains its original source capture and drift record. The result records its source drift explicitly. The canonical kernel continues as the active path, and the broad retry-convergence candidate retains its separate open findings.

## Katran behavior audit

[Direct raw-record review](katran-behavior-review.json) of the already published 14:59 native-only Katran run finds 19,391 pktgen packets, 19,391 bound-native program runs and 19,391 receiver packets. The LRU total is 19,391 and its miss field is 1; this ARM run records one cache miss across the full packet stream. The fallback-LRU selection counter is 19,391, which counts selection of the fallback cache. The separate `lru_miss` entry is the TCP SYN/non-SYN breakdown, and the generic UDP miss count comes from the separate LRU miss field. Drop, pass, encapsulation-failure and consistent-hash-drop counters are zero in the retained record.

This audit reuses the exact archived work.json, native identity and generation-bound receipt. The worker was subsequently promoted in b89015df9; the one-arm record retains its historical input and launch identity. The new two-start Katran replay has completed and its whole-application work record follows below. QEMU values here record functional work; the hardware performance phase follows the coordination priorities.

The [descriptor-stable feature-probe repair](probe-map-fd/README.md) is published at 8c0394e9e: the existing rule uses the shared normalized policy identity across process map descriptors. Its generic regression executes 33,094 checks per source version, and both complete ISA shim builds exit 0. The [ELF readonly reader repair](readonly-byte-exact/README.md) is staged with byte-exact mechanism evidence. The active serial queue retains its current inputs; queued OTel, Cilium and Tetragon replays consume their respective repairs after predecessor jobs close. Whole-application coverage and raw request/workload records continue through the common collector.

[The current Katran two-start work record](katran-two-start-work.json) reports guest exit0 and application status ok: baseline 26,197 packets and native 23,208 packets each equal their BPF-run, VIP, TX and receiver counts. Both phases record one LRU miss with identical workload configuration. Original host status records hashes_unchanged=false; analysis-time comparison with launch identifies the shared x86 memory-access header update. Raw host metadata and request identities retain their original values. Tracee now occupies the existing serial queue.

Safety work develops universal O1 ISA refinement, O2 per-token specialization, O4 binding and preservation theorems for each native-link transformation, composed for every program. Historical individual-program proof, certificate and validation material stays frozen. Application runtime coverage, raw service requests and workload counters come from common mechanisms applied uniformly to every request. The Tetragon replay follows this application-level collection scope.


## Trusted-path runtime and transport evidence

The [portable ARM transport controls](../kprog_arm64_app_coverage_20261106/trusted-arm64-transport-result/README.md) and the [Katran two-start run](trusted-arm64-katran-result/README.md) use the same kernel and module binaries, with SHA256 prefixes 48343ccf4938 and 2ebef5adbcd2. Both captures also share the exact trusted wire header. All five captured transport input hashes match the current retained inputs. The generic transport run exits 0 in both guest and QEMU and records 16 expected rejection controls plus three PASS markers. It exercises application proof-ELF and proof-upload rejection, immutable kernel-owned native bytes/entry/metadata after producer mutation, registered-service authority, source/load/map queries, request identity and disconnect behavior. Its original console output and exact inputs remain linked above.

Katran's actual application restart exits 0 in the guest, QEMU and application. The archived launcher sets REQUIRE_BOUND_PROOF=1; the native-only manifest carries native objects and metadata. The application log records one replacement with cache_hit=0, prebuilt_proof=0 and bound_required=1. The registered service generates and compiles the verifier artifact, completes the kernel request, and the bound native phase processes 23,208 packets with matching BPF-run and receiver counts. This pairs the priority-1 ARM application runtime with the common transport boundary controls. The original host status and shared-header drift record remain in the raw result; the whole-application work analysis records their provenance. Universal simulator, specialization, binding and native-link preservation theorem work continues alongside six-application execution.


## Finite indirect dispatch in application runs

The [whole-application source census](indirect-dispatch/README.md) reconciles the original common-service artifacts across the five closed first-pass cohorts. Katran's bound artifact contains 82 singleton indirect helper-call sites with actual register reads, CODE/helper partitioning and rejecting switch defaults; its finite local-return sets have sizes 0, 1 and 2. BCC direct helper calls, OTel's generated-source loader rejection, and the zero-request Cilium/Tetragon startup cohorts retain their separate counts. Tracee continues in the original serial queue. These source-site observations accompany the original workload counters and universal safety theorem work.
