# OTel whole-application aligned private-stack replay001743

The generic alignment-aware stack representation closes the preceding perf_unwind_stop private-stack offset-91 failure. The complete upstream application freshly generates and compiles3requests; read_task_struct and perf_unwind_stop bind, and perf_unwind_native reaches the verifier instruction-exploration limit. The actual log records1000001processed instructions,66042total states,2541peak states and46maxstates perinstruction.

| Baseline resident | Generated | Compiled | Bound | Specialization/loader errors | Verifier rejections |
| ---: | ---: | ---: | ---: | ---: | ---: |
| 13 | 3 | 3 | 2 | 0 | 1 |

All3terminal native/kernel hashes and captured source pins reconcile. The existing one2-second workload and full original native objects use20-23/eightvCPU/12GiB. The next generic representation repair continues from the exploration frontier.

```sh
make -f /workspaces/.agent-state/kprog-lanes/C/aligned-stack-successors/otelcol-ebpf-profiler__profiling/Makefile corpus STATE=/workspaces/.agent-state/kprog-lanes/C/aligned-stack-successors/otelcol-ebpf-profiler__profiling APPS=otelcol-ebpf-profiler/profiling CPUS=20-23 VM_MEM=12G VM_CPUS=8 SAMPLES=1 WORKLOAD_DURATION=2
```

`service.tar.gz` preserves all terminal generation/compiler/verifier/native archives, `result.tar.gz` preserves upstream application/JIT workload/shim output, and `launch.tar.gz` preserves exact source/image/binary commands and inputs. Coverage and artifact identities remain in `coverage.json`/`observations.json`. The generic candidate stays captured; the production simulator retains its published source epoch.
