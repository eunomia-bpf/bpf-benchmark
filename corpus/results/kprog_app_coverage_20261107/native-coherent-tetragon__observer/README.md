# tetragon/observer: coherent-kernel native startup

Actual `x86_kvm_corpus_20261107_201956_257793`, full upstream application startup, existing
two-start workload and the common native-only generation/verifier/binding
service. Image1ead525666cc and bootdf7a92936b41 carry the matching BTF epoch.

| Application load instances accepted in baseline | Resident counters | Feature probe attempts | Generated | Compiled | Accepted/bound | Specialization errors | Verifier rejections | Further load instances remaining |
| ---: | ---: | ---: | ---: | ---: | ---: | --- | ---: | ---: |
| 289 | 287 | 22 | 2 | 2 | 2 | 1: helper stack relation | 0 | 286 |

The common definedness analysis reaches the next helper call and reports unresolved source stack relation at native offset0x9ab. Two preceding application requests bind successfully. Generic helper-source stack relation analysis is the next repair.

The baseline load count follows each PID/TID load receipt and its kernel program
ID. The unchanged production feature-probe classifier partitions the observed
attempts. Repeated application loads retain their distinct kernel IDs; resident
counters describe the final snapshot. The application completion queue retains
every observed load instance. Actual app/metadata status is error, and the outer
driver records exit0. Source identities and any observed drift remain explicit
in coverage.json. Matching native workload measurement follows startup closure.

```sh
make -f corpus/results/kprog_app_coverage_20261107/native-only-runtime/Makefile corpus STATE="$D" CPUS=20-23 VM_CPUS=8 VM_MEM=12G APPS=tetragon/observer SAMPLES=1 WORKLOAD_DURATION=2
```

coverage.json preserves raw work/counters, request outcomes and source pins.
service.tar.gz preserves original registered-service/kernel/request archives;
result.tar.gz preserves the corpus tree; launch.tar.gz preserves commands,
package input manifest and source snapshots; collection-evidence.tar.gz preserves
collector output and all baseline receipt rows with the exact generic
classifier source. Closed experiment image tar and guest disk are retired.
Runtime observations and universal simulator/token/link safety laws retain their
respective evidence responsibilities.
