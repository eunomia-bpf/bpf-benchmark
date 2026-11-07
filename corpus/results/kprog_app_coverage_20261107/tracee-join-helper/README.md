# tracee/monitor: consistent stack-slot join epoch

Actual `x86_kvm_corpus_20261107_211016_200545` performs whole application startup with the existing
workload through the registered native-only generation/verifier/binding service.
The common source epoch contains binary readonly extraction, affine stack-origin
transport, consistent external-slot joins and shared LEA corrections. Each actual
source/header SHA appears in the launch snapshot and kernel request archives.

| Accepted baseline app loads | Resident counters | Feature probes | Generated | Compiled | Bound | Specialization errors | Confirmed verifier rejections | Native stub load errors | Further app loads |
| ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| 151 | 151 | 11 | 6 | 6 | 5 | 0 | 1 | 0 | 145 |

sys_enter_submit now binds along with the entry and initialization paths.
The sixth request, sys_exit_submit, generates and compiles; its verifier log
reports a four-byte indexed load from an80-byte readonly map at maximum
offset1036 (BPF instruction5674), processed2147 instructions and91 states.
Generic preservation of the native index/branch range is the next repair.

Source drift []; actual app status `error`.
The original native input remains fixed within each application epoch; Tracee
uses the helper-preserving whole object7479850e2345. Baseline counts use PID/TID
load receipts and unique kernel program IDs with the existing probe classifier.
The application completion queue retains every observed application load instance.
Matching-work timing follows full startup.

Command: `make -f /workspaces/.agent-state/kprog-lanes/C/join-application-replay/tracee__monitor/Makefile corpus IMAGE=bpf-benchmark/kprog-native-core:c-20261107 STATE="$D" CPUS=20-23 VM_CPUS=8 VM_MEM=12G APPS=tracee/monitor SAMPLES=1 WORKLOAD_DURATION=2`.
Twelve GiB/eight guest vCPUs on20-23, one sample/two-second workload.
coverage.json keeps counters, requests, source hashes and the failure stage;
service.tar.gz keeps exact request/kernel/native/generated/load artifacts;
result.tar.gz keeps the corpus tree; launch.tar.gz keeps commands and source
snapshots; collection-evidence keeps raw baseline receipts and collector output.
Closed image exports, guest disks and the temporary Tracee image tag are retired.
These runtime observations support the universal simulator/token/link safety laws.
