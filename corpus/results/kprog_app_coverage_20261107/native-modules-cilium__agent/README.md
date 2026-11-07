# cilium/agent: coherent-kernel native startup

Actual `x86_kvm_corpus_20261107_201146_214927`, full upstream application startup, existing
two-start workload and the common native-only generation/verifier/binding
service. Image1ead525666cc and bootdf7a92936b41 carry the matching BTF epoch.

| Application load instances accepted in baseline | Resident counters | Feature probe attempts | Generated | Compiled | Accepted/bound | Specialization errors | Verifier rejections | Further load instances remaining |
| ---: | ---: | ---: | ---: | ---: | ---: | --- | ---: | ---: |
| 163 | 72 | 44 | 1 | 0 | 0 | 1: compiler map declaration | 0 | 162 |

Generated C references cilium_percpu_trace_id while the kernel-validated map binding set names the three used application maps and readonly configuration fields. Clang reports an undeclared identifier. Generic map-symbol declaration/binding coverage is the next repair.

The baseline load count follows each PID/TID load receipt and its kernel program
ID. The unchanged production feature-probe classifier partitions the observed
attempts. Repeated application loads retain their distinct kernel IDs; resident
counters describe the final snapshot. The application completion queue retains
every observed load instance. Actual app/metadata status is error, and the outer
driver records exit0. Source identities and any observed drift remain explicit
in coverage.json. Matching native workload measurement follows startup closure.

```sh
make -f corpus/results/kprog_app_coverage_20261107/native-only-runtime/Makefile corpus STATE="$D" CPUS=20-23 VM_CPUS=8 VM_MEM=12G APPS=cilium/agent SAMPLES=1 WORKLOAD_DURATION=2
```

coverage.json preserves raw work/counters, request outcomes and source pins.
service.tar.gz preserves original registered-service/kernel/request archives;
result.tar.gz preserves the corpus tree; launch.tar.gz preserves commands,
package input manifest and source snapshots; collection-evidence.tar.gz preserves
collector output and all baseline receipt rows with the exact generic
classifier source. Closed experiment image tar and guest disk are retired.
Runtime observations and universal simulator/token/link safety laws retain their
respective evidence responsibilities.
