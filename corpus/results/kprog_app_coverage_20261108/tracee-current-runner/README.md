# Whole Tracee with the current runner

The original Tracee151-program baseline completes. The verified restart submits six native requests: six generate and compile, and five install. `sys_exit_submit` reaches the stock verifier, which reports `invalid access to map value, value_size=80 off=1036 size=4` after3042instructions and92states. The original application records startup error and retains its full stderr and workload evidence. The readonly-index representation is the next generic model frontier.

| Entry | Generated | Compiled | Installed | Terminal outcome |
| --- | ---: | ---: | ---: | --- |
| tracepoint__raw_syscalls__sys_enter | 1 | 1 | 1 | installed |
| sys_enter_init | 1 | 1 | 1 | installed |
| sys_enter_submit | 1 | 1 | 1 | installed |
| tracepoint__raw_syscalls__sys_exit | 1 | 1 | 1 | installed |
| sys_exit_init | 1 | 1 | 1 | installed |
| sys_exit_submit | 1 | 1 | 0 | stock-verifier readonly indexing |

The incremental image copies the current already-published Tracee runner. Its verified startup waits for compile/load completion. The prior [current CORE-input cohort](../tracee-current-core/README.md) retains its300second client-lifetime outcome. Both cohorts use native SHA256 `7479850e23454e957f4c5880a18d92a91c27dd282af52f768e4422fe9366a722` and the current CORE-preserving header source. All six terminal native hashes match. The new guest boots the promoted shared five-step bzImage4eaf9f27/vmlinux1530dcc6, eight vCPUs,12GiB on CPUs20-23. The actual model header is captured with the command receipts.

```sh
N=/workspaces/.agent-state/kprog-lanes/C/design-only/remaining-apps/tracee-runner
make -f "$N/Makefile" image
make -f /workspaces/.agent-state/kprog-lanes/C/design-only/remaining-apps/tracee-current-runner/Makefile corpus STATE=/workspaces/.agent-state/kprog-lanes/C/design-only/remaining-apps/tracee-current-runner CPUS=20-23 VM_CPUS=8 VM_MEM=12G APPS=tracee/monitor SAMPLES=1 WORKLOAD_DURATION=2
```

`service.tar.gz` contains the complete request archive including kernel/service logs, each native object, generated C/BPF and loader/stock-verifier logs. `result.tar.gz` retains the original corpus result and work counters. `runtime.tar.gz` retains the actual current-runner layer and commands; `coverage.json` records the observed six requests and their joins. The framework exit0 and application startup error retain their separate meanings.
