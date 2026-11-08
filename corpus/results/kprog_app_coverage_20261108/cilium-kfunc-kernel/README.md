# Cilium new-kernel baseline environment epoch014758

The new registered-kfunc x86 kernel and main native module boot, and the trusted service registers. The original Cilium JIT baseline reaches the route reconciler and exits with protocol unsupported. Kernel logs record invalid split-module BTF names for nfnetlink, xfrm_algo and bpf_preload. The service observes0native requests because startup ends during baseline preparation.

This epoch supplies complete framework/environment evidence. The latest valid native-coverage row remains batch010928. Matching all kernel modules to the new vmlinux BTF, installation and depmod now produce a coherent bundle for the corrected full Cilium guest. The route failure's relation to the module errors is an inference from their shared startup sequence.

```sh
make -f /workspaces/.agent-state/kprog-lanes/C/cilium-kfunc-kernel-replay/Makefile corpus STATE=/workspaces/.agent-state/kprog-lanes/C/cilium-kfunc-kernel-replay APPS=cilium/agent CPUS=20-23 VM_MEM=12G VM_CPUS=8 SAMPLES=1 WORKLOAD_DURATION=2
```

The original artifact streams in coverage.json preserve raw app/JIT/service/kernel output and exact inputs. Future native acceptance and work counters come from the corrected complete application attempt.
