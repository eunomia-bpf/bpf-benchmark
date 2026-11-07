# tracee/monitor: common affine producer epoch

Actual `x86_kvm_corpus_20261107_205819_761660` uses complete application startup and the unchanged workload
through the registered native-only service. Its kernel-owned requests exercise
binary ELF readonly extraction, finite affine helper stack origins and the
shared LEA correction together.

| Accepted baseline app loads | Resident counters | Feature probes | Generated | Compiled | Bound | Specialization errors | Verifier rejections | Further app loads |
| ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| 151 | 151 | 11 | 2 | 2 | 2 | 1 | 0 | 148 |

Observed startup error: ['native helper source stack relation unresolved at 0x1ad7: call   rax']. App status `error`;
source drift []. Two early requests bind, and helper-source
stack relation remains the next generic repair. The slot-join correction that
follows aligns the absent-record interpretation across reads and control-flow
joins; the next whole-application epoch captures it independently.

Command: `make -f /workspaces/.agent-state/kprog-lanes/C/affine-application-replay/tracee__monitor/Makefile corpus IMAGE=bpf-benchmark/kprog-native-core:c-20261107 STATE="$D" CPUS=20-23 VM_CPUS=8 VM_MEM=12G APPS=tracee/monitor SAMPLES=1 WORKLOAD_DURATION=2`.
Twelve GiB/eight guest vCPUs on20-23, one sample/two-second workload.
Tracee uses helper-preserving native7479850e2345; Tetragon retains its original
native artifacts. Baseline receipt counts follow PID/TID and kernel program IDs
with the unchanged production probe classifier. coverage.json keeps all request,
work and source identities; service/result/launch archives keep raw evidence;
collection-evidence preserves collector output and baseline receipts. Closed
image exports and guest disks are retired. Matching-work timing follows complete
startup. Universal simulator/token/link laws supply the safety argument.
