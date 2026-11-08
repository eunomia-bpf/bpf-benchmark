# Tracee whole-application aligned-stack replay002731

The complete original upstream application uses the registered native-only generation service and the captured aligned-stack/narrow-value candidate. All6observed requests freshly generate and compile,5bind, and sys_exit_submit reaches the bpf_probe_read length relation. The verifier reports R2 unbounded memory access after3458processed instructions/151states/146peak/max4perinstruction. Both the table-index and preceding private-stack paths reach this actual helper call.

| Baseline resident | Generated | Compiled | Bound | Specialization/loader errors | Verifier rejections |
| ---: | ---: | ---: | ---: | ---: | ---: |
| 151 | 6 | 6 | 5 | 0 | 1 |

All6terminal native/kernel hashes and source pins reconcile. The original native SHA7479850e2345,common57e6module and c664resourcecaller/linker retain their captured epoch. CPUs20-23/eightvCPU/12GiB run one2-second existing workload sample. The next generic register-read identity representation preserves native widths through BPF ALU32 and masks; whole-app replay follows the current Cilium kfunc trial.

```sh
make -f /workspaces/.agent-state/kprog-lanes/C/aligned-stack-successors/tracee__monitor/Makefile corpus STATE=/workspaces/.agent-state/kprog-lanes/C/aligned-stack-successors/tracee__monitor APPS=tracee/monitor CPUS=20-23 VM_MEM=12G VM_CPUS=8 SAMPLES=1 WORKLOAD_DURATION=2
```

`coverage.json` and `observations.json` retain all terminal inventories, hashes and counts. `service.tar.gz` preserves complete generation/compiler/verifier/kernel records; `result.tar.gz` preserves actual application/JIT workload/shim output; `launch.tar.gz` preserves actual source/binary/image/command inputs. Whole-app completion continues from the recorded helper-length class.
