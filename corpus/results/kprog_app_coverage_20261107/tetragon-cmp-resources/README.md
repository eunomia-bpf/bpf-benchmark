# Tetragon CMP resource replay

The complete source manifest selects execve_send. Four requests generate and compile, three bind. Request4 reaches the verifier sequence of 8193 jumps, with189726 processed instructions and1926 total states. The generic CMP/read candidate retains the observed jump-depth failure class.

| Baseline load attempts | Baseline accepted loads | Baseline resident programs | Service requests | Generated | Compiled | Accepted/bound |
| ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| 311 | 308 | 287 | 4 | 4 | 4 | 3 |

Baseline syscall counts include startup probes; the full named-load inventory and resident snapshot provide the separate census evidence. Each batch uses one existing workload sample of two seconds,12GiB/eight vCPU on20-23. Native timing follows complete application startup and matching work.

Command: `make -f C/cmp-resource-app-replay/tetragon__observer/Makefile corpus STATE=RUN CPUS=20-23 VM_CPUS=8 VM_MEM=12G APPS=tetragon/observer SAMPLES=1 WORKLOAD_DURATION=2`, after the captured private image build. `C` denotes `/workspaces/.agent-state/kprog-lanes/C`; `RUN` is that batch directory. launch.tar.gz retains launch scripts and inputs; service.tar.gz retains terminal requests and compiler/verifier logs; result.tar.gz retains complete app, shim, workload and program counters; coverage.json retains source/image identities and terminal hash reconciliation. Source drift count0; remaining temporary disk/image-tar count0.
