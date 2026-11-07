# katran: common-service application startup batch

Actual `x86_kvm_corpus_20261107_193718_187857`, original application startup and existing two-start workload protocol, native-only registered service with generation, kernel verification and binding. These files record batch runtime observations. Universal O1/O2/O4 and native-link transformation theorems provide the safety argument through the common mechanisms.

| Application entries observed in baseline | Feature probe attempts | Generated | Compiled | Accepted/bound | Specialization errors | Verifier rejections |
| ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 |

Baseline topology setup reaches tunnel4 module lookup; packaged dependency indexes are the next repair.

The baseline startup prerequisite ends this attempt before the native phase. The application program denominator remains to be collected after successful startup. The registered service reports ready and receives zero requests. Feature probes retain their upstream behavior. Actual app and corpus metadata status are `error`; the outer driver exit is `0`. Those recorded outcomes stay distinct.

```sh
make -f corpus/results/kprog_app_coverage_20261107/native-only-runtime/Makefile corpus STATE="$D" CPUS=20-23 VM_CPUS=4 VM_MEM=12G APPS=katran SAMPLES=1 WORKLOAD_DURATION=2
```

CPU affinity 20–23, four guest vCPUs, 12 GiB, one sample and duration two seconds. Cached image `sha256:a20b2981171de35a85d1827760701e157efa17347c8705374f146a5d7dbe1a90`; simulator header `47fb55656f29`, memory header `3ba4bc7881f8`. All 17 launch input hashes retain their captured values at collection.

The first collector assumed a request log for every startup. The corrected generic reader represents the ready, zero-request service as an empty batch. Both collector histories are archived.

`coverage.json` preserves raw workload counters, startup diagnostics, request outcomes and source pins. `service.tar.gz` preserves the complete original service/kernel archive; `result.tar.gz` preserves the corpus result tree; `launch.tar.gz` preserves commands and source snapshots; `collection-evidence.tar.gz` preserves collection history. Closed experiment image tar and guest disk have been deleted. The application startup and matching-work queue continues from the recorded failure class.
