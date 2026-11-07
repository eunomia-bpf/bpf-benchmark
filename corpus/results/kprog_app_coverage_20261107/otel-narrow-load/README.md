# otelcol-ebpf-profiler/profiling: common-service application startup batch

Actual `x86_kvm_corpus_20261107_192310_917567`, original application startup and existing two-start workload protocol, native-only registered service with generation, kernel verification and binding. These files record batch runtime observations. Universal O1/O2/O4 and native-link transformation theorems provide the safety argument through the common mechanisms.

| Application entries observed in baseline | Feature probe attempts | Generated | Compiled | Accepted/bound | Specialization errors | Verifier rejections |
| ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| 14 | 3 | 3 | 3 | 2 | 0 | 1 |

Verifier instruction exploration reaches 1,000,001 against limit 1,000,000; max_states_per_insn 31, total_states 64,869, peak_states 2,495.

The baseline runs its existing mixed workload with 13 resident counters and 14 application loads, including the ephemeral entry. Native startup binds two entries and reaches the complexity error on the third. Eleven further application entries remain on the completion queue. Actual app and corpus metadata status are `error`; the outer driver exit is `0`. Those recorded outcomes stay distinct.

```sh
make -f corpus/results/kprog_app_coverage_20261107/native-only-runtime/Makefile corpus STATE="$D" CPUS=20-23 VM_CPUS=4 VM_MEM=12G APPS=otelcol-ebpf-profiler/profiling SAMPLES=1 WORKLOAD_DURATION=2
```

CPU affinity 20–23, four guest vCPUs, 12 GiB, one sample and duration two seconds. Cached image `sha256:a20b2981171de35a85d1827760701e157efa17347c8705374f146a5d7dbe1a90`; simulator header `47fb55656f29`, memory header `3ba4bc7881f8`. All 17 launch input hashes retain their captured values at collection.

`coverage.json` preserves raw workload counters, startup diagnostics, request outcomes and source pins. `service.tar.gz` preserves the complete original service/kernel archive; `result.tar.gz` preserves the corpus result tree; `launch.tar.gz` preserves commands and source snapshots; `collection-evidence.tar.gz` preserves collection history. Closed experiment image tar and guest disk have been deleted. The application startup and matching-work queue continues from the recorded failure class.
