# OTel native-only startup with canonical CMP/RORX and terminal draining

Actual `x86_kvm_corpus_20261107_190538_882861`, existing two-start workload protocol, original application/native ELF, external registered trusted service and REQUIRE_BOUND_PROOF=1. This is a failed native startup with complete raw evidence, not an end-to-end native application result.

| Actual baseline application programs | Generated | Compiled | Verifier accepted/bound | Specialization failed | Verifier rejected | Not reached after native startup abort |
| ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| 14 (13 resident + ephemeral read_task_struct) | 3 | 3 | 2 | 0 | 1: complexity | 11 |

| Actual app entry | Generated | Compiled | Accepted/bound | Result |
| --- | ---: | ---: | ---: | --- |
| read_task_struct | 1 | 1 | 1 | bound |
| perf_unwind_stop | 1 | 1 | 1 | bound |
| perf_unwind_native | 1 | 1 | 0 | verifier complexity 1,000,001 / 1,000,000 |
| Remaining 11 baseline app entries | 0 | 0 | 0 | native startup aborted before their loads |

`perf_unwind_native` rejects with `BPF program is too large. Processed 1000001 insn`; limit 1,000,000, max states per instruction 31, total states 64,654, peak states 2,538. All three requests compile, all terminal archives are readable, and each kernel-owned original ELF SHA matches its service receipt. No guest OOM. The 11 unattempted entries remain required; none is classified as unsupported or omitted from the target.

The baseline captures all 14 named application loads (plus three libbpf probe attempts, including the two-instruction `probe_bpf_perf_` identified by the existing shim classifier), 13 resident program counters and one existing mixed workload with 11 components. Native startup replaces two programs then aborts; no native workload completes, so no matching-work or timing claim. The corpus wrapper returns zero even though actual app/metadata status is error; the collector records the error and exits one after writing the complete evidence. `rejit_result.status=ok` does not override the actual app failure.

## Command, sources and raw evidence

```sh
make -f corpus/results/kprog_app_coverage_20261107/native-only-runtime/Makefile corpus \
  STATE=/workspaces/.agent-state/kprog-lanes/C/otel-current-cmp-rorx \
  CPUS=20-23 VM_CPUS=4 VM_MEM=12G APPS=otelcol-ebpf-profiler/profiling \
  SAMPLES=1 WORKLOAD_DURATION=2
```

Cached image a20b2981171d, existing TV kernel/15 modules, canonical CMP/RORX header 47fb55656f29 and corpus terminal drain 1570d4158; no image/kernel/module rebuild. The earlier service-check target incrementally rebuilt its helper, whose actual bytes/source are separately pinned at launch. All other 14 launch pins stayed stable; **trusted_specializer.py changed physically during this run** as R extended compiler discovery. The service imports its worker once at startup, and the launch worker snapshot is retained. This is not labeled a frozen-source run: launch and after source, both hashes and exact compiler-discovery diff are preserved. No application proof or compiler flag change is introduced by this result.

`coverage.json` retains all raw baseline/workload counters, native startup failure and per-request identities. `service.tar.gz` wraps the original complete service archive (including full kernel log/meminfo, generated C/objects and verifier logs); `result.tar.gz` holds the original corpus result tree; `launch.tar.gz` holds launch command and launch source snapshots. `collection-evidence.tar.gz` preserves terminal collector output/exit, full failing verifier log and the worker source drift. `checks.json` lists all 14 actual app names, all load attempts and failure classes. Closed own guest disk/exported image tar are deleted.

CMP/RORX fixes did not close this OTel complexity failure. The separately validated narrow-load zero-extension repair is the next candidate; it is not retroactively attributed to this run.
