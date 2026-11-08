# Tracee whole-application typed-read replay005903

The complete original upstream app consumes the generic narrow-read/aligned-stack candidate through the registered native-only service. All6observed native requests freshly generate and compile;5bind. sys_exit_submit reaches the actual bpf_probe_read R2 length range refusal after3502processed instructions,151total/146peak states and4maxstates perinstruction. The earlier aligned-stack epoch retains3458instructions at the same helper-length frontier.

| Baseline resident | Generated | Compiled | Bound | Specialization/loader errors | Verifier rejections |
| ---: | ---: | ---: | ---: | ---: | ---: |
| 151 | 6 | 6 | 5 | 0 | 1 |

All6terminal native hashes and captured source pins reconcile. Original native/app/workload, common57e6module and captured8cfcaller/worker retain their epochs. The run uses20-23/eightvCPU/12GiB and one2-second existing workload sample. The next generic investigation follows the modular length/control relation into the helper call.

```sh
make -f /workspaces/.agent-state/kprog-lanes/C/typed-read-successors/tracee__monitor/Makefile corpus STATE=/workspaces/.agent-state/kprog-lanes/C/typed-read-successors/tracee__monitor APPS=tracee/monitor CPUS=20-23 VM_MEM=12G VM_CPUS=8 SAMPLES=1 WORKLOAD_DURATION=2
```

`service.tar.gz` preserves all original native/proof inputs and full generation/compiler/verifier/kernel logs. `result.tar.gz` preserves upstream startup/JIT workload/shim records; `launch.tar.gz` captures private/source/image/binary commands. `coverage.json` and `observations.json` preserve inventories and artifact hashes. The655360-case narrow-read mechanism remains separate component evidence.
