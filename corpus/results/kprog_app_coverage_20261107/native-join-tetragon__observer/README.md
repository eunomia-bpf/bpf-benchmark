# tetragon/observer: consistent stack-slot join epoch

Actual `x86_kvm_corpus_20261107_210552_695762` performs whole application startup with the existing
workload through the registered native-only generation/verifier/binding service.
The common source epoch contains binary readonly extraction, affine stack-origin
transport, consistent external-slot joins and shared LEA corrections. Each actual
source/header SHA appears in the launch snapshot and kernel request archives.

| Accepted baseline app loads | Resident counters | Feature probes | Generated | Compiled | Bound | Specialization errors | Confirmed verifier rejections | Native stub load errors | Further app loads |
| ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| 289 | 287 | 22 | 3 | 3 | 2 | 0 | 0 | 1 | 286 |

The helper-source relation error closes: the third request now generates and
compiles. Native-stub BPF_PROG_LOAD returns EINVAL. The preserved log includes
processed34919 instructions, maxstates4, total526, peak286; the native blob has
37 contiguous chunks and4618 bytes, with proof_bound=1. The final native group
load and materialization route is the next generic diagnosis. The table records
this native-stub load error separately from a confirmed verifier rejection.

Source drift []; actual app status `error`.
The original native input remains fixed within each application epoch; Tracee
uses the helper-preserving whole object7479850e2345. Baseline counts use PID/TID
load receipts and unique kernel program IDs with the existing probe classifier.
The application completion queue retains every observed application load instance.
Matching-work timing follows full startup.

Command: `make -f /workspaces/.agent-state/kprog-lanes/C/join-application-replay/tetragon__observer/Makefile corpus IMAGE=bpf-benchmark/kprog-native-only:x86-current STATE="$D" CPUS=20-23 VM_CPUS=8 VM_MEM=12G APPS=tetragon/observer SAMPLES=1 WORKLOAD_DURATION=2`.
Twelve GiB/eight guest vCPUs on20-23, one sample/two-second workload.
coverage.json keeps counters, requests, source hashes and the failure stage;
service.tar.gz keeps exact request/kernel/native/generated/load artifacts;
result.tar.gz keeps the corpus tree; launch.tar.gz keeps commands and source
snapshots; collection-evidence keeps raw baseline receipts and collector output.
Closed image exports, guest disks and the temporary Tracee image tag are retired.
These runtime observations support the universal simulator/token/link safety laws.
