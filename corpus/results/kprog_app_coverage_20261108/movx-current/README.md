# Current x86 MOVZX/MOVSX destination-lane identity

The generic register-extension handler carries compiler value identity in the actual architectural writeback lane:32bits for32-bit destinations and the full result for the other destination widths. The empty assembly expression preserves every value and flag. The existing width/sign extension and partial-register write contracts retain their effects. Additional admission predicates total0.

The [whole current-runner Tracee cohort](../tracee-current-runner/README.md) reaches a readonly80-byte table with a comparison-copy mask and later index of1036. The existing generic [destination-width profile](../tracee-movx-identity/README.md) carries the actual checked byte into the later index. This adoption applies its same six-line representation to the current canonical model, including the tested private-stack alias stores, and recompiles the current complete Tracee source.

| Observation | Actual outcome |
| --- | --- |
| Existing MOVX whole-state host route, UBSan | 23761cases,0differences |
| Existing MOVX shape host route, UBSan | 118803cases,0differences |
| Current captured whole Tracee source compile | exit0 |
| Existing micro compile controls | 29positive+1negative-native,exit0 |
| Complete original Tracee successor | detached; terminal receipt follows |

The host observations total142564 and include registers, tags and flags. The original Tracee native object remains7479850e23454e957f4c5880a18d92a91c27dd282af52f768e4422fe9366a722. The new complete startup uses the current-runner image, shared five-step kernel and a frozen header snapshot on CPUs20-23, eight vCPUs and12GiB. Stock-verifier/application outcomes supply the next coverage table.

```sh
N=/workspaces/.agent-state/kprog-lanes/C/design-only/remaining-apps/movx-current
make -f "$N/Makefile" host
make -f "$N/Makefile" component
make -f "$N/Makefile" micro
make -f /workspaces/.agent-state/kprog-lanes/C/design-only/remaining-apps/tracee-movx-current/Makefile corpus STATE=/workspaces/.agent-state/kprog-lanes/C/design-only/remaining-apps/tracee-movx-current CPUS=20-23 VM_CPUS=8 VM_MEM=12G APPS=tracee/monitor SAMPLES=1 WORKLOAD_DURATION=2
```

`component.tar.gz` retains the exact base/patch/model, current generated source and compiled BPF, the compiler command, existing oracle snapshots/outcomes, all compile-control outputs and the whole-application successor commands. V owns the universal MOVX token and compiled-body relation. Component observations and complete-application outcomes retain their respective evidence domains.
