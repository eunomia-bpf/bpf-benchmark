# Original Katran on the shared exact-extent x86 runtime

The preceding private-kernel whole run closes BCC25/25 with its original workload and records Katran ip_tunnel BTF errno22 during baseline startup. The shared exact-extent build incrementally relinks ordinary modules against the current vmlinux; this original Katran retry consumes that shared Image, ordinary modules and matching native module. Application image/native inputs,75d2 simulator snapshot, specializer/loader and existing two-second workload retain their previous definitions.

Actual generated/compiled/installed/failures: (0, 0, 0, 0). Work status: [{'application': 'katran', 'status': 'error', 'error': "modprobe ip_tunnel failed: modprobe: ERROR: could not insert 'ip_tunnel': Invalid argument"}]. [coverage.json](coverage.json), [work.json](work.json) and [summary.json](summary.json) retain measured stages/counters and exact input hashes. Existing raw workload/lifecycle/native/B/compiler/verifier records remain in the result and service archives.

```sh
make -f /workspaces/.agent-state/kprog-lanes/C/design-only/remaining-apps/katran-shared-extent/Makefile corpus STATE=/workspaces/.agent-state/kprog-lanes/C/design-only/remaining-apps/katran-shared-extent CPUS=20-23 VM_CPUS=8 VM_MEM=12G APPS=katran SAMPLES=1 WORKLOAD_DURATION=2
```

[runtime.tar.gz](runtime.tar.gz) retains commands, captured input hashes, guest source and original terminal records. Timing remains with R. Runtime admission additions0.
