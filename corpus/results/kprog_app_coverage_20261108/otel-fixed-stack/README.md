# OTel whole-application fixed-RSP replay012120

The complete original upstream app uses the registered native-only service and generic fixed-RSP-offset/aligned-stack/narrow-read candidate. All3observed native requests freshly generate and compile; read_task_struct and perf_unwind_stop bind. perf_unwind_native reaches an actual verifier stack refusal: an8-byte write at R10-520, after2398processed instructions and60total/peak states.

| Baseline resident | Generated | Compiled | Bound | Specialization/loader errors | Verifier rejections |
| ---: | ---: | ---: | ---: | ---: | ---: |
| 13 | 3 | 3 | 2 | 0 | 1 |

All3terminal native hashes and captured source pins reconcile. The original native/app/workload, common57e6module and captured8cfcaller/worker retain their epochs. The run uses20-23/eightvCPU/12GiB and one2-second existing workload sample. The full source compile records10439BPF instructions versus40034in the preceding typed-read epoch. That preceding epoch reaches instruction exploration; this distinct candidate reaches proof-side stack pressure. Remaining verifier exploration follows actual future acceptance attempts.

```sh
make -f /workspaces/.agent-state/kprog-lanes/C/fixed-stack-successors/otelcol-ebpf-profiler__profiling/Makefile corpus STATE=/workspaces/.agent-state/kprog-lanes/C/fixed-stack-successors/otelcol-ebpf-profiler__profiling APPS=otelcol-ebpf-profiler/profiling CPUS=20-23 VM_MEM=12G VM_CPUS=8 SAMPLES=1 WORKLOAD_DURATION=2
```

`service.tar.gz` preserves every original native/proof input and full generation/compiler/verifier/kernel log. `result.tar.gz` preserves upstream startup/JIT workload/shim records; `launch.tar.gz` captures private/source/image/binary commands. `coverage.json` and `observations.json` preserve inventories and artifact hashes. Generic aligned-width private-stack stores are the next representation candidate under byte/JIT/host checks.
