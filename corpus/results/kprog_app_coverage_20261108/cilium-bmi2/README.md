# Cilium whole-application BMI2 replay001201

The upstream application uses the native-only registered kernel-capsule service. Its XDP entry generates, compiles and binds; tail_nodeport_nat_ingress_ipv4 generates and compiles, then the worker loader reports `invalid source proof map relocation site/type`. Its actual ELF contains an R_BPF_64_32 call relocation for bpf_cast_to_kern_ctx at byte24. The preceding BMI2 count-definedness frontier passes through the current generic checker.

| Baseline resident | Generated | Compiled | Bound | Loader errors | Verifier rejections |
| ---: | ---: | ---: | ---: | ---: | ---: |
| 72 | 2 | 2 | 1 | 1 | 0 |

All2terminal kernel/native hashes reconcile. The next generic loader extension resolves the kfunc through matching vmlinux BTF and the pinned libbpf prototype matcher, retaining exact map bindings. CPUs20-23/eightvCPU/12GiB use the existing upstream startup and one2-second workload sample. App completion follows this recorded loader class.

```sh
make -f /workspaces/.agent-state/kprog-lanes/C/cilium-bmi2-replay/Makefile corpus STATE=/workspaces/.agent-state/kprog-lanes/C/cilium-bmi2-replay APPS=cilium/agent CPUS=20-23 VM_MEM=12G VM_CPUS=8 SAMPLES=1 WORKLOAD_DURATION=2
```

`service.tar.gz` preserves every terminal native/proof ELF and full generation/compiler/loader log; `result.tar.gz` preserves upstream app, shim and raw JIT work. `launch.tar.gz` preserves actual private/running/image inputs. The initial collector expected an earlier base-build package-inputs.json; its repair archives the actual queue inputs captured at startup. Complete collection and original diagnostic scripts/logs remain in the lane state. `coverage.json` and `observations.json` retain exact hashes and inventories.
