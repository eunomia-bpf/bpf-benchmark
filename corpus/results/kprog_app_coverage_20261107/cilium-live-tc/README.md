# Cilium live native TC context, whole application batch000058

The live native TC context representation carries typed context fields and the kernel bpf_cast_to_kern_ctx identity. Startup binds cil_xdp_entry; the next entry cil_to_host reaches the ABI-definedness checker at BZHI eax,eax,r8d following MOV r8b/SUB r8b. One request generates/compiles/binds; the second specializes up to this count dependency. The generic BMI2 count-mask repair is checked separately and its whole-application successor follows the current serial OTel guest.

| Baseline resident | Generated | Compiled | Bound | Failure outcomes |
| ---: | ---: | ---: | ---: | ---: |
| 60 | 1 | 1 | 1 | 1 |

The entire upstream application starts under the existing corpus arm. Each row preserves every terminal request, exact kernel-native SHA256 and captured source/image inputs. CPUs20-23,12GiB,eightvCPU,one2-second sample use the original workload. Whole-application completion follows the recorded failure class.

Commands are retained in `launch.tar.gz` (`Makefile`, `run.sh`, `running-inputs.json`, `guest.py`, `collect.py`), and executed through:

```sh
make -f /workspaces/.agent-state/kprog-lanes/C/tc-stack-successors/cilium__agent/Makefile corpus CPUS=20-23 VM_MEM=12G VM_CPUS=8 STATE=/workspaces/.agent-state/kprog-lanes/C/tc-stack-successors/cilium__agent APPS=cilium/agent SAMPLES=1 WORKLOAD_DURATION=2
```

`coverage.json` and `observations.json` retain inventories and counters. `service.tar.gz` carries complete generation/compiler/verifier/kernel logs and every terminal archive. `result.tar.gz` carries upstream app/shim/workload records; `launch.tar.gz` pins the actual native/module/service/compiler inputs.
