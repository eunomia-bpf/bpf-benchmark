# Tracee verified startup resource replay

The verified startup runner reaches native resource submission. Whole-ELF resource collection reaches the kernel descriptor-count limit (E2BIG); the app records one native failure and exits97. Service request count is0. The common entry-resource closure repair c664565cc selects the actual entry references; the matching caller/linker replay is active.

| Baseline load attempts | Baseline accepted loads | Baseline resident programs | Service requests | Generated | Compiled | Accepted/bound |
| ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| 162 | 162 | 151 | 0 | 0 | 0 | 0 |

Baseline syscall counts include startup probes; the full named-load inventory and resident snapshot provide the separate census evidence. Each batch uses one existing workload sample of two seconds,12GiB/eight vCPU on20-23. Native timing follows complete application startup and matching work.

Command: `make -f C/tracee-bound-startup-replay/Makefile corpus STATE=RUN CPUS=20-23 VM_CPUS=8 VM_MEM=12G APPS=tracee/monitor SAMPLES=1 WORKLOAD_DURATION=2`, after the captured private image build. `C` denotes `/workspaces/.agent-state/kprog-lanes/C`; `RUN` is that batch directory. launch.tar.gz retains launch scripts and inputs; service.tar.gz retains terminal requests and compiler/verifier logs; result.tar.gz retains complete app, shim, workload and program counters; coverage.json retains source/image identities and terminal hash reconciliation. Source drift count0; remaining temporary disk/image-tar count0.
