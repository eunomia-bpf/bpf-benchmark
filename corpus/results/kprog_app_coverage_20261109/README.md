# x86 application coverage, November 9 UTC

This index preserves the latest completed whole-application cohort for each application and the ensuing serial runtime queue. Counts below refer to terminal native service requests. Resident census refers to the stated startup epoch. Complete startup remains the target for every application; the four continuing applications retain each observed failure and original workload outcome.

| Application | Program census | Native requests | Proof generated | Compiled | Verifier accepted / installed | Specialization or preparation cause | Verifier error class | Whole work |
| --- | --- | ---: | ---: | ---: | ---: | --- | --- | --- |
| BCC | 25 in completed startup | 25 | 25 | 25 | 25 | 0 | 0 | completed |
| OTel | 13 resident in recorded startup | 3 | 3 | 3 | 2 | 0 | 1: proof stack write at -528, size 8 | native startup error |
| Cilium | 72 resident in recorded startup | 16 | 15 | 15 | 14 | 1: source release before GET_CONTEXT | 1: scalar memory read, tail_ipv4_policy | native startup error |
| Tetragon | 287 resident in earlier original startup; paired census continues | 0 | 0 | 0 | 0 | paired startup reaches baseline verifier | baseline helper4 R2 unbounded, generic_kprobe_filter_arg | startup error |
| Katran | 1 in completed startup | 1 | 1 | 1 | 1 | 0 | 0 | completed |
| Tracee | 151 resident in earlier original startup; paired census continues | 0 | 0 | 0 | 0 | paired startup reaches baseline verifier | baseline map access offset65672, size4096, value32536 | startup error |

BCC and Katran share the [completed same-copy cohort](../../../kprog/results/kprog_design_only_20261108/same-copy-link/bcc-katran/README.md),26 generated/compiled/installed and application status ok. Its coverage, service/result/runtime archives and raw work counters retain the actual native/runtime epoch. The current exception-recovery kernel/module supplies a newer epoch, whose whole-application replay remains a separate observation.

The continuing cohorts are [OTel](../kprog_app_coverage_20261108/otel-counted-native-loop/application/README.md), [Cilium](../kprog_app_coverage_20261108/cilium-prepared-end/whole-current/README.md), [Tetragon](../kprog_app_coverage_20261108/tetragon-paired-source/application/README.md) and [Tracee](../kprog_app_coverage_20261108/tracee-clamp-register/application/README.md). Each directory retains coverage.json, service.tar.gz, result.tar.gz and runtime.tar.gz. coverage-index.json records their exact artifact hashes, terminal request failures and application errors. The [November 8 ledger](../kprog_app_coverage_20261108/README.md) retains prior source epochs and complete historical census attribution.

The generic [map-helper caller-frame candidate](../kprog_app_coverage_20261108/map-caller-frame/README.md) has existing4100slot/19458route host observations and the captured Cilium native generation/compilation. Its [original38 replay](../kprog_app_coverage_20261108/map-caller-frame/safety/README.md) records9valid executions,28verifier rejections,1generation failure and risky native executions0. The current whole Cilium successor captures the candidate with paired current kernel/module/worker/loader. Universal helper-frame laws368483bd retain concrete platform footprint, caller ownership and physical ABI/compiler obligations.

Tracee's published paired source20096/compile806ab supplies native, JIT and embedded binary assets from the same selected C tree. The existing startup launcher reached image packaging with a missing Dockerfile. Its initial diagnostic is preserved under the existing experiment's bootstrap-initial directory, and the restored image recipe packages those completed assets. Its whole successor follows Cilium serially on CPUs20-23 with12GiB guest memory.

Both new commands use the frozen sample and duration settings:

```sh
make -f /workspaces/.agent-state/kprog-lanes/C/design-only/remaining-apps/cilium-map-caller-frame/Makefile corpus STATE=/workspaces/.agent-state/kprog-lanes/C/design-only/remaining-apps/cilium-map-caller-frame CPUS=20-23 VM_CPUS=8 VM_MEM=12G APPS=cilium/agent SAMPLES=3 WORKLOAD_DURATION=180
make -f /workspaces/.agent-state/kprog-lanes/C/design-only/remaining-apps/tracee-clamp-macro/Makefile corpus STATE=/workspaces/.agent-state/kprog-lanes/C/design-only/remaining-apps/tracee-clamp-macro CPUS=20-23 VM_CPUS=8 VM_MEM=12G APPS=tracee/monitor SAMPLES=3 WORKLOAD_DURATION=180
```

Existing detached controllers own these commands, their terminal collection and private-index publication. Their current state resides in /workspaces/.agent-state/kprog-lanes/C/current.json. R timing requests follow actual matching-work receipts. Benchmark framework, native-input selection and workload definitions retain their frozen bytes.

The [exception-recovery original38 cohort](../../../kprog/results/kprog_design_only_20261108/load-fault-recovery/original38/README.md) records9valid executions/28verifier rejections/1generation failure, risky native executions0. The full-word NULL-BTF diagnostics isolate x86 SMAP fault dispatch before exception-table recovery. The coordinator case00:38 records the narrow dispatch candidate and existing successful live-control observations. Protected-read fault-prefix correspondence remains with the generic model and universal laws.
