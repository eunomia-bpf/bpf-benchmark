# Tracee complete startup fixed-RSP replay013224

The complete original upstream app uses the registered native-only service and fixed-RSP/narrow-read/aligned-stack candidate. All6observed requests freshly generate and compile;5bind. sys_exit_submit reaches bpf_probe_read R2 length range after2938processed instructions,106total/101peak states and4maxstates perinstruction.

| Baseline resident | Generated | Compiled | Bound | Specialization/loader errors | Verifier rejections |
| ---: | ---: | ---: | ---: | ---: | ---: |
| 151 | 6 | 6 | 5 | 0 | 1 |

All6terminal native hashes and source pins reconcile. The original app/native/workload, common57e6module and captured8cfcaller/worker retain their epochs. The run uses20-23/eightvCPU/12GiB and one2-second existing workload sample.

```sh
make -f /workspaces/.agent-state/kprog-lanes/C/fixed-stack-successors/tracee__monitor/Makefile corpus STATE=/workspaces/.agent-state/kprog-lanes/C/fixed-stack-successors/tracee__monitor APPS=tracee/monitor CPUS=20-23 VM_MEM=12G VM_CPUS=8 SAMPLES=1 WORKLOAD_DURATION=2
```

`service.tar.gz` preserves all original native/proof inputs and full generation/compiler/verifier/kernel logs. `result.tar.gz` preserves upstream startup/JIT workload/shim records; `launch.tar.gz` captures private/source/image/binary commands. `coverage.json` and `observations.json` retain counters and artifact hashes.

The earlier typed-read epoch reached3502instructions/151states at the same helper-length frontier; this fixed-RSP epoch reaches2938instructions/106states. These are distinct complete startup attempts. Generic scalar32 and typed private-memory representations continue from the exact native length/control expressions.
