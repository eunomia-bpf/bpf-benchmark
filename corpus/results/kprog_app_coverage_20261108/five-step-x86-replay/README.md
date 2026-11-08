# Five-step x86 replay and matched runtime

The final-source38-case native-only replay completes with9 valid executions,27 stock-verifier refusals and2 generation coverage failures: the existing missing-handler and unbounded-indirect-jump cases. All38 terminal native SHA256 values match their native inputs. Unsafe cases use the existing load-only commands; the9 positive controls execute through TEST_RUN. Accepted dangerous cases:0. The source includes the architectural RET/RSP correction in a04786538.

The original complete-app startup attempts retain their actual failure stages:

| Application | Baseline census | Native submissions | Generated | Compiled | Installed | Recorded stage |
| --- | ---: | ---: | ---: | ---: | ---: | --- |
| Cilium | startup error |0|0|0|0| split-BTF module loading, nfnetlink/xfrm error22 |
| Tracee |151|1|0|0|0| captured helper-declaration resource path |
| Tetragon |287|1|1|0|0| compiler transport, broker directory read-only in guest |
| OTel |13|1|1|0|0| compiler transport, broker directory read-only in guest |

These are setup/transport outcomes. Corpus metadata and application statuses record errors. Each process wrapper's exit0 describes command closure; application acceptance follows the recorded application status. All3 submitted native hashes match their terminal archives. Historical coverage frontiers retain their earlier source epochs in the adjacent reports.

The matched-runtime repair incrementally refreshes the existing kernel module cache after the final vmlinux link. All842 standard modules are installed, and the image build completes. The kernel image and vmlinux SHA256 values stay equal across the refresh; standard modules gain split-BTF data generated against the final vmlinux. The captured helper declarations use the original vendored bytes. Corrected guest launchers expose their broker directory through the existing writable-directory interface. These changes supply the existing compiler and module-loading resources.

Original application/native/workload inputs remain. Corrected full Cilium and Tracee run serially, followed by complete Tetragon and OTel, with captured generator/header inputs, fresh host compilation, eight vCPUs,12GiB and host CPUs20-23. Added runtime admission checks:0. Stock verification and faithful simulation remain the two safety facts.

```sh
make -f /workspaces/.agent-state/kprog-lanes/C/design-only/remaining-apps/checks.Makefile safety-complete
taskset -c8-11 unshare --mount --propagation private sh /workspaces/.agent-state/kprog-lanes/C/design-only/remaining-apps/final-modules/inside.sh
make -f /workspaces/.agent-state/kprog-lanes/C/design-only/remaining-apps/cilium-final-modules/Makefile corpus STATE=/workspaces/.agent-state/kprog-lanes/C/design-only/remaining-apps/cilium-final-modules CPUS=20-23 VM_CPUS=8 VM_MEM=12G APPS=cilium/agent SAMPLES=1 WORKLOAD_DURATION=2
```

`safety.tar.gz` retains all38 actual request archives, native/source/load logs and outcomes. `applications.tar.gz` retains complete original startup results, per-program/work counters and all3 terminal requests. `runtime.tar.gz` retains captured sources, commands, launchers, module/image build receipts and the setup repairs. `matching-modules.tar.gz` retains the complete842-module final kernel package. `observations.json` records counts and hashes. Runtime loading and application results follow the corrected cohorts' terminal archives.
