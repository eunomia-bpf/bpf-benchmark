# Tetragon whole-application typed-read replay005356

The original upstream application uses the registered native-only service and generic aligned-stack/narrow-read representation. All5observed native requests freshly generate and compile;4bind. execve_send reaches the verifier sequence limit of8193jumps after179285processed instructions,1930total/peak states and4maxstates perinstruction. The earlier stack-width epoch reached189726instructions/1926states at the same jump limit.

| Baseline resident | Generated | Compiled | Bound | Specialization/loader errors | Verifier rejections |
| ---: | ---: | ---: | ---: | ---: | ---: |
| 287 | 5 | 5 | 4 | 0 | 1 |

All5terminal native hashes and captured source pins reconcile. The complete application/native/workload, common57e6module and captured8cfcaller/worker retain their epochs. The run uses20-23/eightvCPU/12GiB and one2-second existing workload sample. Generic control/state exploration remains the next Tetragon frontier.

```sh
make -f /workspaces/.agent-state/kprog-lanes/C/typed-read-successors/tetragon__observer/Makefile corpus STATE=/workspaces/.agent-state/kprog-lanes/C/typed-read-successors/tetragon__observer APPS=tetragon/observer CPUS=20-23 VM_MEM=12G VM_CPUS=8 SAMPLES=1 WORKLOAD_DURATION=2
```

`service.tar.gz` preserves every original native/proof input and full generation/compiler/verifier/kernel log. `result.tar.gz` preserves upstream startup/JIT workload/shim records. `launch.tar.gz` captures private/source/image/binary commands; `coverage.json` and `observations.json` preserve counters and artifact hashes. The655360-case read mechanism and full OTel source compilation remain separate component evidence.
