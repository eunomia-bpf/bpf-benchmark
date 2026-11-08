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
| Complete original Cilium successor | 5generated/compiled,4installed; stackoff-544/8 |

The complete-state host observations total4104678. The retained first additional-fixture invocation records a Makefile command concatenation error; the corrected host invocation compiles and executes each fixture and returns0. Source/archive captures preserve that distinction. The micro wrapper substitutes only the model-header include, keeping the existing generated programs and compiler flags.

```sh
N=/workspaces/.agent-state/kprog-lanes/C/design-only/remaining-apps/private-stack-bytes
make -f "$N/Makefile" host
make -f "$N/Makefile" component
make -f "$N/Makefile" micro
make -f /workspaces/.agent-state/kprog-lanes/C/design-only/remaining-apps/cilium-private-stack/Makefile corpus STATE=/workspaces/.agent-state/kprog-lanes/C/design-only/remaining-apps/cilium-private-stack CPUS=20-23 VM_CPUS=8 VM_MEM=12G APPS=cilium/agent SAMPLES=1 WORKLOAD_DURATION=2
```

`component.tar.gz` retains the exact candidate, base/patch, existing oracle snapshots and outputs, current captured source/BPF/compiler command, all compile-control outcomes, and the whole-application successor commands. Universal O2 representation reasoning belongs to the shared simulator/token line; complete-application generation and stock verification remain the coverage evidence.

The complete original Cilium successor has closed. Its baseline resident census is62. The native restart submits `cil_xdp_entry`, `cil_host_policy`, `tail_ipv4_ct_ingress`, `cil_from_host` and `tail_handle_ipv4_cont`. All five generate and compile; the first four install. The last reaches stock-verifier `invalid write to stack R10 off=-544 size=8` after389instructions. All five terminal native hashes match their captured objects. This whole-startup receipt advances the current table to5generated/4installed, with the original application startup error and work counters retained. Dynamic upstream load order and entry inventory retain their actual per-cohort records.

`service.tar.gz`, `result.tar.gz` and `coverage.json` preserve all five requests, generated C/BPF, stock-verifier logs, and the original corpus metadata/counters. `runtime.tar.gz` preserves the actual closed controller and guest commands. The current generic frontier joins Tetragon and OTel at private state/frame representation; measured stock-verifier limits remain the runtime decisions.
