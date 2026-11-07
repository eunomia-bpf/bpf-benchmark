# Whole Katran bound with provenance-selected register storage

Actual `x86_kvm_corpus_20261107_213447_736880` completes Katran startup and the existing
XDP pktgen workload through the common native-only registered service:
1baseline application program,1fresh generated/compiled/accepted/bound request,
app status ok, source drift0, replacement1 and native failure0. The five startup
feature probes retain the existing classifier route. Original native input
ba252e0372d1 and all app/workload sources retain their captured identities.

The generic low8/high8/16 write representation uses the existing scalar tag:
scalar writes keep ordinary union storage; pointer-tagged values use a complete
volatile local union before the partial write and full64-bit reload. Both forms
preserve all upper bits and produce the same scalar tag. Captured include
cf27e323c885 matches the candidate's100448MOV host/UBSan cases. The common
producer adoption follows the running Tracee source epoch.

| Arm | Sent / BPF runs / XDP TX | LRU hit-path / miss | Receiver packets | Load-balancer TX drops | Receiver drops | XDP drops |
| --- | ---: | --- | ---: | ---: | ---: | ---: |
| JIT | 2318117 | 2318117 / 0 | 2318117 | 0 | 0 | 0 |
| Bound native | 2386430 | 2386430 / 0 | 2377743 | 5158 | 3529 | 0 |

Each arm executes one BPF invocation and one XDP TX action per sent workload
packet, with LRU hit-path counters and miss0. The native receiver difference8687
is exactly the5158TX drops plus3529receiver drops in the recorded network path.
Both use the existing two-second workload; their packet totals reflect achieved
throughput. This functional run records work/correctness, and R's recipe supplies
the performance measurement. All counter values, including gauge-like fields,
remain in the raw corpus output and coverage.json.

Command: `make -f /workspaces/.agent-state/kprog-lanes/C/representation-runtime-replay/katran/Makefile corpus IMAGE=bpf-benchmark/kprog-native-only:x86-current STATE="$D" CPUS=20-23 VM_CPUS=8 VM_MEM=12G APPS=katran SAMPLES=1 WORKLOAD_DURATION=2`.
Twelve GiB/eight guest vCPUs on20-23, one sample/two-second workload. The launch
archive captures the exact common sources, private include and compiler wrapper;
the service archive captures kernel-owned native requests, fresh generated B,
verification/binding and outcomes; the result archive captures the corpus tree.
Collection evidence keeps all baseline receipts and full packet/action/drop
reconciliation. Closed guest disk/export are retired. Universal simulator/token/
link laws retain the safety responsibility.
