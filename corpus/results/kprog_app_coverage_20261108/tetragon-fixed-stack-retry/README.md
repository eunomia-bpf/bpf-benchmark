# Tetragon complete fixed-RSP retry014223

The original upstream application uses the registered native-only service and fixed-RSP/aligned-stack/narrow-read candidate. All4observed native requests freshly generate and compile;3bind. event_execve reaches an actual8-byte proof-stack write refusal at R10-888 after453processed instructions and0explored states. Its generated model declares424native-stack bytes; the rejected access belongs to the compiled proof frame.

| Baseline resident | Generated | Compiled | Bound | Specialization/loader errors | Verifier rejections |
| ---: | ---: | ---: | ---: | ---: | ---: |
| 287 | 4 | 4 | 3 | 0 | 1 |

All4terminal native hashes and source pins reconcile. The original native/app/workload, common57e6module and captured8cfcaller/worker retain their epochs. The run uses20-23/eightvCPU/12GiB and one2-second existing workload sample. This valid complete startup attempt follows the archived resource-interval invocation. This startup reaches event_execve; the earlier execve_send8193-jump frontier remains separate active verification work in batch005356.

```sh
make -f /workspaces/.agent-state/kprog-lanes/C/fixed-stack-resource-retry/tetragon__observer/Makefile corpus STATE=/workspaces/.agent-state/kprog-lanes/C/fixed-stack-resource-retry/tetragon__observer APPS=tetragon/observer CPUS=20-23 VM_MEM=12G VM_CPUS=8 SAMPLES=1 WORKLOAD_DURATION=2
```

`service.tar.gz` preserves original native/proof inputs and full generation/compiler/verifier/kernel logs. `result.tar.gz` preserves upstream startup/JIT workload/shim records; `launch.tar.gz` captures private/source/image/binary commands. `coverage.json` and `observations.json` preserve inventories and hashes. Generic typed volatile private-memory representation now compiles both recorded Tetragon entries.
