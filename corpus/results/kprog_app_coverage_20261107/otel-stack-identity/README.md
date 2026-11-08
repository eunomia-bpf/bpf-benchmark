# OTel coherent stack/value identity batch000433

The whole original application uses the common registered native-only service and the captured native-width private-stack candidate. Two requests generate and compile, read_task_struct binds, and perf_unwind_stop reaches an8-byte private-stack read at offset-91. The actual verifier reports misaligned stack access,2884processed instructions/144states. All terminal native hashes and source pins reconcile.

The earlier CMP-identity epoch233455 remains a distinct result with3generated/compiled and2bound. This candidate exposes the alignment requirement of its wide private-stack read. Its successor selects a native-width read at an aligned address and the canonical byte ladder at each unaligned address, preserving the native value and private memory.

| Baseline resident | Generated | Compiled | Bound | Verifier rejection |
| ---: | ---: | ---: | ---: | --- |
| 13 | 2 | 2 | 1 | misaligned stack read (-91,8bytes) |

```sh
make -f /workspaces/.agent-state/kprog-lanes/C/tc-stack-successors/otelcol-ebpf-profiler__profiling/Makefile corpus STATE=/workspaces/.agent-state/kprog-lanes/C/tc-stack-successors/otelcol-ebpf-profiler__profiling APPS=otelcol-ebpf-profiler/profiling CPUS=20-23 VM_MEM=12G VM_CPUS=8 SAMPLES=1 WORKLOAD_DURATION=2
```

`service.tar.gz` keeps every request and full compiler/verifier/kernel logs; `result.tar.gz` keeps actual JIT workload and app/shim records. `launch.tar.gz` captures native, simulator, module, binary and exact command inputs. The complete coverage and artifact identities are in `coverage.json` and `observations.json`. Whole-application completion follows the recorded alignment class.
