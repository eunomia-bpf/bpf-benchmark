# Tracee startup on the coherent kernel/module epoch

Actual `x86_kvm_corpus_20261107_200640_963093`, whole upstream application,
existing two-start workload, native-only registered generation/verifier/binding
service. Image1ead525666cc and bootdf7a92936b41 use the common BTF epoch.
The baseline reaches151 resident application programs and its workload.

| Application programs observed | Feature probe attempts | Generated | Compiled | Accepted/bound | Specialization errors | Verifier rejections | Further app entries remaining |
| ---: | ---: | ---: | ---: | ---: | ---: | --- | ---: |
| 151 | 11 | 2 | 2 | 1 | 0 | 1: scalar memory access | 149 |

The162 baseline load attempts contain151 application entries and11 existing
feature probes. The existing shim classifier identifies the small unnamed
probes plus libbpf_nametest and det_arg_ctx. Native startup fresh-binds its first
application entry and reaches the memory check on the next request. Both
terminal request archives are readable and both kernel-owned native input
identities match their receipts. All launch input hashes retain their captured
values. App/metadata status is error; the outer driver records exit0.

The verifier reports R2 scalar memory access at BPF instruction147, processing147
instructions. Native offset0x6c reads a register-frame field from an address
loaded through the raw context. The generic native compatibility header lowers
PT_REGS_*_CORE and its single-field pt_regs BPF_CORE_READ path to direct field
reads, while upstream CORE reads preserve the probe helper. The next common
compiler repair restores those helper semantics across all native compilations.
This preserves the helper/fault contract and records a new native-input epoch.
The current original native objects remain captured in this result.

The kernel log records the completed module/BTF startup; native workload and
matching-work measurement remain on the application completion queue. The149
further entries remain part of the required application coverage.

```sh
make -f corpus/results/kprog_app_coverage_20261107/native-only-runtime/Makefile corpus \
  STATE=/workspaces/.agent-state/kprog-lanes/C/remaining-apps-modules/tracee__monitor \
  CPUS=20-23 VM_CPUS=8 VM_MEM=12G APPS=tracee/monitor SAMPLES=1 WORKLOAD_DURATION=2
```

coverage.json retains baseline counters/work and request outcomes; service.tar.gz
retains the original service/kernel archive; result.tar.gz retains the full
corpus tree; launch.tar.gz retains commands, package manifest and source inputs;
collection-evidence.tar.gz retains terminal collector output, full loader
error and the generic compatibility/classifier source. Closed experiment image
tar and guest disk are retired. These are runtime observations; universal
simulator, token and native-link theorems carry the safety argument.
