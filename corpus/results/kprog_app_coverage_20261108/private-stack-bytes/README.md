# Private-stack scalar stores through register aliases

The generic x86 MOV store handler reuses the existing private-stack byte ladder when its destination register carries STACK provenance and its value is scalar. The direct RSP byte path calls that same ladder. Pointer-valued stores retain their native-width operation and verifier pointer provenance; public memory keeps its existing native-width operation. Guest addresses, widths, bytes, flags and control flow retain their values. The change adds0runtime admission predicates.

The latest closed [Cilium metadata cohort](../xdp-metadata/README.md) exposes a native64-bit scalar store through a private-stack register alias at proof-stackoff-156. The stock verifier requires aligned stack-wide accesses there. The representation writes the same private bytes through the existing byte ladder. Cilium's original native object and workload remain selected by the full application.

| Measurement | Actual outcome |
| --- | --- |
| Existing stack-arm host route, UBSan | 117782cases,0differences |
| Existing stack-write-lanes host route, UBSan | 1401654cases,0differences |
| Existing MOV-store host route, UBSan | 1292621cases,0differences |
| Same MOV-store fixture with STACK constructor, UBSan | 1292621cases,0differences |
| Existing micro compile controls | 29positive+1negative-native,exit0 |
| Actual captured Cilium full generated source compile | exit0 |
| Complete original Cilium successor | detached; terminal receipt follows |

The complete-state host observations total4104678. The retained first additional-fixture invocation records a Makefile command concatenation error; the corrected host invocation compiles and executes each fixture and returns0. Source/archive captures preserve that distinction. The micro wrapper substitutes only the model-header include, keeping the existing generated programs and compiler flags.

```sh
N=/workspaces/.agent-state/kprog-lanes/C/design-only/remaining-apps/private-stack-bytes
make -f "$N/Makefile" host
make -f "$N/Makefile" component
make -f "$N/Makefile" micro
make -f /workspaces/.agent-state/kprog-lanes/C/design-only/remaining-apps/cilium-private-stack/Makefile corpus STATE=/workspaces/.agent-state/kprog-lanes/C/design-only/remaining-apps/cilium-private-stack CPUS=20-23 VM_CPUS=8 VM_MEM=12G APPS=cilium/agent SAMPLES=1 WORKLOAD_DURATION=2
```

`component.tar.gz` retains the exact candidate, base/patch, existing oracle snapshots and outputs, current captured source/BPF/compiler command, all compile-control outcomes, and the whole-application successor commands. Universal O2 representation reasoning belongs to the shared simulator/token line; complete-application generation and stock verification remain the coverage evidence.
