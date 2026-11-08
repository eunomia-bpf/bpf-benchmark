# Original Katran on the shared exact-extent x86 runtime

The preceding two attempts retain Katran ip_tunnel BTF errno22 during baseline startup. A fresh shared-kernel guest resolves the current ip_tunnel file hash and loads it successfully. The existing application image carries its earlier ordinary-module payload, which runtime startup installs. This original Katran retry refreshes only the existing image kernel/module layer from the same current shared build. Application image/native inputs,75d2 simulator snapshot, specializer/loader and existing two-second workload retain their previous definitions.

Actual generated/compiled/installed/failures: (1, 1, 1, 0). Work status: [{'application': 'katran', 'status': 'ok', 'error': ''}]. [coverage.json](coverage.json), [work.json](work.json) and [summary.json](summary.json) retain measured stages/counters and exact input hashes. Existing raw workload/lifecycle/native/B/compiler/verifier records remain in the result and service archives.

```sh
make -f /workspaces/.agent-state/kprog-lanes/C/design-only/remaining-apps/katran-shared-packaged/Makefile corpus STATE=/workspaces/.agent-state/kprog-lanes/C/design-only/remaining-apps/katran-shared-packaged CPUS=20-23 VM_CPUS=8 VM_MEM=12G APPS=katran SAMPLES=1 WORKLOAD_DURATION=2
```

[runtime.tar.gz](runtime.tar.gz) retains commands, captured input hashes, guest source and original terminal records. Timing remains with R. Runtime admission additions0.

### Phase-local work accounting

| Phase | LB RX / BPF / XDP TX / VIP / LRU / real-map packets | LRU miss | Receiver RX | LB TX drop | Receiver drop |
| --- | ---: | ---: | ---: | ---: | ---: |
| baseline | 2457811 | 0 | 2405984 | 14675 | 37152 |
| post_rejit | 2126026 | 0 | 1283310 | 447272 | 395444 |

Every count named in the second column has the displayed phase-local value. Receiver RX plus the two recorded drop reasons accounts for the LB input in each phase. Both original workload commands exit0. The two-second duration-driven phase totals retain their distinct values. [work-accounting.json](work-accounting.json) selects the original fields from [work.json](work.json); all interface/map/workload components remain in that complete raw record. R owns timing on CPUs0-7 with the established counterbalanced protocol.
