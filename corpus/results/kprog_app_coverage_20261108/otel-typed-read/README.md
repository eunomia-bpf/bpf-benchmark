# OTel whole-application typed-read replay004333

The complete original upstream app consumes the generic narrow-read BPF representation through the registered native-only service. All3observed requests freshly generate and compile; read_task_struct and perf_unwind_stop bind. perf_unwind_native reaches the actual verifier exploration limit:1000001processed instructions,65666total states,2544peak and46maxstates perinstruction.

| Baseline resident | Generated | Compiled | Bound | Specialization/loader errors | Verifier rejections |
| ---: | ---: | ---: | ---: | ---: | ---: |
| 13 | 3 | 3 | 2 | 0 | 1 |

The three terminal native/kernel hashes and source pins reconcile. The fixed native/workload/common57e6module and captured8cfcaller/worker run on20-23/eightvCPU/12GiB with one2-second existing sample. The earlier aligned-stack epoch retains66042states at the same1000001instruction limit; both complete outcomes remain distinct. The next generic investigation addresses the remaining control/state exploration.

```sh
make -f /workspaces/.agent-state/kprog-lanes/C/typed-read-successors/otelcol-ebpf-profiler__profiling/Makefile corpus STATE=/workspaces/.agent-state/kprog-lanes/C/typed-read-successors/otelcol-ebpf-profiler__profiling APPS=otelcol-ebpf-profiler/profiling CPUS=20-23 VM_MEM=12G VM_CPUS=8 SAMPLES=1 WORKLOAD_DURATION=2
```

`service.tar.gz` preserves every original native/proof input and full generation/compiler/verifier/kernel log. `result.tar.gz` preserves actual upstream app/JIT workload/shim records; `launch.tar.gz` captures exact private/source/image/binary commands. `coverage.json`/`observations.json` retain inventories and hashes. The generic read mechanism655360-case result and40034instruction full-source compilation remain separate component evidence.
