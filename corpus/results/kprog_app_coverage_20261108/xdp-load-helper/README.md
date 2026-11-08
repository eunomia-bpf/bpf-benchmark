# x86 XDP byte-load helper

The complete Cilium matched-module startup reaches native entry `cil_xdp_entry` and generates its simulator. Its18 compiler diagnostics identify one missing C body: `bpf_xdp_load_bytes`, Linux helper189. The shared simulator now forwards the actual XDP context,32-bit offset, destination pointer and32-bit length to that helper, then uses the existing scalar-result and SysV caller-clobber model. The existing numeric and bounded-indirect helper dispatches select the same body.

The production change adds7 lines: helper identity, C body and dispatcher arm. The existing JSON/C/Lean table grows from67 to68 helpers. Existing host tests retain the complete4097-ID interval and register-call cases; their frame expectations follow the published caller-clobber model. The frame comparison becomes one shared function, reducing duplicate test code.

Validation exits0: existing ID oracle4100 cases, actual typed-helper ABI oracle18946 cases under UBSan, generated table checks, both helper-dispatch Lean modules, and29 workload-derived micro compilations plus1 negative compile control. These results cover the helper ABI/dispatch and compilation. V owns the universal operation/token/link composition.

| Complete matched-module application | Native requests | Generated | Compiled | Installed | Actual outcome |
| --- | ---: | ---: | ---: | ---: | --- |
| Cilium |1|1|0|0| missing XDP helper C body; current extension supplies it |
| Tracee |2|2|2|1| next entry `sys_enter_init`: R2 scalar memory access after242instructions |

Cilium's module-loading baseline completes after the842-module refresh. Tracee installs `tracepoint__raw_syscalls__sys_enter`. All3 native hashes match their actual terminal records. Corpus statuses retain the application errors. The complete Cilium successor consumes the extended header/table snapshot after the current BCC/Katran, Tetragon and OTel cohort; original upstream workloads and native inputs remain.

```sh
make -f /workspaces/.agent-state/kprog-lanes/C/design-only/remaining-apps/xdp-load-helper/Makefile check lean micro
make -f /workspaces/.agent-state/kprog-lanes/C/design-only/remaining-apps/cilium-xdp-helper/Makefile corpus STATE=/workspaces/.agent-state/kprog-lanes/C/design-only/remaining-apps/cilium-xdp-helper CPUS=20-23 VM_CPUS=8 VM_MEM=12G APPS=cilium/agent SAMPLES=1 WORKLOAD_DURATION=2
```

`component.tar.gz` contains existing oracle sources/logs, source patch, original helper baseline,30 compiler receipts and the captured successor launch plan. `applications.tar.gz` contains both actual whole-application cohorts, native/generated/load archives and work counters. `observations.json` records counts and source hashes. Added admission checks:0. The existing stock verifier decides the generated simulator.
