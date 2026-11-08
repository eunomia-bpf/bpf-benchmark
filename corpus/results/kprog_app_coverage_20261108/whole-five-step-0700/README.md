# Whole Tetragon and OTel on the five-step runtime

The original Tetragon matched-module startup generates, compiles and installs3 programs. The application then selects `event_execve`; its22448-byte source variant reaches the cached235-row manifest's selection frontier before native submission. The retained237-row inventory already supplies that exact v61 variant. The new runtime layer carries that published inventory and keeps every native object and upstream application/workload input.

The corrected entire Tetragon startup generates and compiles5 programs, installing4: `event_exit_acct_process`, `event_exit_disassociate_ctty`, `event_wake_up_new_task` and `execve_rate`. `event_execve` reaches stock verification and receives an invalid stack write at R10 offset-944, width8, after482 instructions. Its generated native-stack representation is424bytes and its full generated CFG has17 native CALL sites. These are the next generic stack/control-flow representation facts.

The entire OTel startup generates and compiles3 programs, installing `read_task_struct` and `perf_unwind_stop`. `perf_unwind_native` reaches the stock verifier's1000001-instruction exploration result, with56152 total states and2405 peak states. Corpus/app statuses record the startup errors. Baseline inventories retain287 Tetragon and13 OTel resident programs; accepted submission counts describe the actual reached entries.

| Whole application cohort | Generated | Compiled | Installed | Recorded failure |
| --- | ---: | ---: | ---: | --- |
| Tetragon original matched modules |3|3|3| manifest source variant before next submission |
| Tetragon237-row inventory |5|5|4| event_execve stack write-944/8 |
| OTel final modules |3|3|2| perf_unwind_native verifier exploration1000001 |

All11 terminal native hashes match their actual request objects. The five-step kernel/module, immutable native request flow, fresh host compilation and original corpus two-start work remain. The asset image build exits0 and adds the237-row manifest as one layer. Added checks/gates/limits:0.

```sh
make -f /workspaces/.agent-state/kprog-lanes/C/design-only/remaining-apps/tetragon-current-assets/Makefile corpus STATE=/workspaces/.agent-state/kprog-lanes/C/design-only/remaining-apps/tetragon-current-assets CPUS=20-23 VM_CPUS=8 VM_MEM=12G APPS=tetragon/observer SAMPLES=1 WORKLOAD_DURATION=2
```

The detached controller owns the command's compiler broker lifetime. `applications.tar.gz` retains all three complete original application result/service cohorts, actual native/generated/verifier logs and work counters. `runtime.tar.gz` retains the237-row inventory, image/build provenance and actual launch sources. `observations.json` records counts and hashes.
