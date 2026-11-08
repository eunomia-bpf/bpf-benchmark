# Cilium whole-application kfunc replay003807

The complete upstream application uses the native-only kernel-capsule service and the published kfunc relocation loader. Its XDP entry freshly generates/compiles/binds; tail_nodeport_nat_egress_ipv4 generates and compiles, then the worker reports `source proof kfunc prototype differs from vmlinux: bpf_cast_to_kern_ctx`. Actual libbpf opening normalizes the .ksyms function declaration linkage from EXTERN to GLOBAL; the original declaration and prototype remain available in the raw ELF.

| Baseline resident | Generated | Compiled | Bound | Loader errors | Verifier rejections |
| ---: | ---: | ---: | ---: | ---: | ---: |
| 72 | 2 | 2 | 1 | 1 | 0 |

Both terminal native/kernel hashes and captured source pins reconcile. The next common loader reads original BTF from the same ELF bytes as the validated instructions and relocations, retaining strong-external and kernel-prototype checks. Its regression covers actual libbpf opening and both observed Cilium ELF patterns.

```sh
make -f /workspaces/.agent-state/kprog-lanes/C/cilium-kfunc-replay/Makefile corpus STATE=/workspaces/.agent-state/kprog-lanes/C/cilium-kfunc-replay APPS=cilium/agent CPUS=20-23 VM_MEM=12G VM_CPUS=8 SAMPLES=1 WORKLOAD_DURATION=2
```

The original native/app/workload runs on20-23/eightvCPU/12GiB through the common57e6module. `service.tar.gz` preserves complete generation/compiler/loader requests, `result.tar.gz` preserves application/JIT workload/shim output, and `launch.tar.gz` preserves exact source/image/binary commands. `coverage.json`/`observations.json` retain inventories and hashes. Whole-app completion follows the recorded linkage class.
