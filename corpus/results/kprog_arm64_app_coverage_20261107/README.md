# AArch64 native-only application coverage, 2026-11-07 UTC

The trusted QEMU transport now accepts all six existing corpus app selectors through the retained standard two-start `corpus.driver` recipe. The application submits native ELF; the registered common service generates and binds fresh proofs. No application proof is supplied. Katran uses the same two-start counter protocol as the other five applications. The retained v35 root, canonical kernel/modules, loader and native-link are reused without rebuilding the image or kernel.

Reproduction from `/workspaces/repository`:

```sh
make -f corpus/results/kprog_arm64_app_coverage_20261106/Makefile trusted-service-arm64-run TRUSTED_APP=otelcol-ebpf-profiler TRUSTED_RESULTS=corpus/results/kprog_arm64_app_coverage_20261107
```

Set `TRUSTED_APP` to `bcc`, `otelcol-ebpf-profiler`, `cilium`, `tetragon`, `katran`, or `tracee`. The existing control remains the default. Each app guest uses 8 GiB and host CPUs 8-11; run them serially. Existing `SAMPLES=1`, `WORKLOAD_DURATION=2`, BPF stats and native-only proof requirements are preserved. Only the existing app selector is replaced in a private copy of the retained launcher. Tracee/Tetragon use their actual packaged `/artifacts` root; the other applications retain the existing artifact root. OTel data-object paths and native entries both become absolute before moving the manifest.

`transport-preflight.json` records actual manifest/ELF hashes, all six Make dry runs and shell/environment checks. Counts below describe available selectors, including probes and variants; they are not loaded-program or verifier-acceptance denominators.

| Application | Packaged selectors | Extra data objects | Current native-only full application |
| --- | ---: | ---: | --- |
| BCC | 32 | 0 | Existing complete-start job running; raw collector owns its output |
| OTel | 36 | 15 | Next serial run |
| Cilium | 98 | 0 | Pending current native-only run |
| Tetragon | 245 | 0 | Pending current native-only run |
| Katran | 12 | 0 | Pending current native-only two-start run |
| Tracee | 123 | 0 | Pending current native-only run |

Current BCC job and collector are preserved. Their output is under [bcc-full-start](../kprog_arm64_app_coverage_20261106/bcc-full-start/trusted-arm64-bcc-result/). Its closed result, actual resident inventory, proof/generated/verifier counts and work counters must be reviewed before declaring coverage. The older [six-app startup census](../kprog_arm64_app_coverage_20261106/runtime-context-v11/README.md) and [29-micro evidence](../kprog_arm64_app_coverage_20261106/memory-extension/README.md) remain historical evidence with their original paths and inputs; they are not relabeled as current native-only acceptance.

The private broad exclusive-retry convergence candidate is not adopted: its [closed constant-cycle diagnostic](../kprog_arm64_app_coverage_20261106/trusted-exclusive-retry-result/candidate-constant-cycle/trusted-arm64-service-result/README.md) found load-time admissions that require repair. Canonical kernel/module hashes remain unchanged. No unsafe native execution was performed. All six applications and the remaining O1-O4 obligations are still incomplete. QEMU timing is functional only; Spark performance runs remain deferred by current coordination priorities.
