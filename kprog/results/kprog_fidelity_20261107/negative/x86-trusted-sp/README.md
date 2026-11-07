# Native-only trusted-service x86 safety suite

The complete current-service KVM run rejects **29/29 unsafe native entries**
and binds and executes **9/9 valid controls**, each with result0 and retval2.
No unsafe native entry was test-run. `outcomes.csv` gives each stage, exact
rejection diagnostic, source/kernel request IDs and native SHA256;
`outcomes.json.gz` preserves complete messages. Each request's compressed
success/failure archive retains the kernel-owned input, worker source identities,
generated proof/compiler/loader output and exact verifier log where applicable.
`summary.json` contains the totals; `guest-input-pins.json` pins the actual
kernel, module, generator, loader and simulator used, including the uncommitted
then-published stack repair from088f426a9.

The application-side harness loads a real BPF context, chooses a native-only
manifest entry, and submits through the production common service. Original
BPF bytecode is needed locally for manifest/map resolution; it is not supplied
as a proof. Only the registered service generates and compiles proof artifacts.
The probe checks a nonzero-generation sidecar and refuses prebuilt proofs.
Positive controls alone reach BPF_PROG_TEST_RUN; all negatives use argc3 and
remain load-only even if a finding were accepted. The possibly-NULL test uses a
HASH map whose key may be absent, rather than ARRAY key0's legitimate nonnull
case. No capability-dropping or simulator bounds guard is used.

The11 requested original cases all reject. Packet past-end read/write, missing
packet bound, map OOB, nullable lookup, invalid helper argument, stack OOB and
uninitialized stack reject in the verifier. The unbounded indirect jump and UD2
reject during specialization. The infinite-loop proof is refused by the loader
with `native_kernel bound proof contains no BPF exit`; it is separately labeled
loader rejection, not counted as a verifier diagnostic. Extended cases cover
entry/return/flags, helper clobbers, divide faults and four positive/negative
high32 stack-offset aliases. Exact per-case messages remain in the CSV/archive.

Safe controls exercise normal entry, SP copy/restore, stack alias loads,
CMOV alias/from-SP/to-SP/self-SP, XCHG alias, and spilled SP restore. Initially
the producer lacked source bytecode for local manifest selection and stopped
before SUBMIT; `setup-failure.json` retains that error, which is not counted as
safety rejection. Two CMOV controls initially omitted a destination initializer
required by conservative ABI analysis; their exact failing inputs/receipts
remain in `control-setup-before.tar.gz`. Explicit destination initialization
fixes those controls without changing production definedness. The first20
completed receipts are retained in `first20-before-classification.tar.gz`;
UD2 already rejected, but its `unsupported mnemonic` text needed an exact
classification entry. The complete38-case rerun is the reported result.

Commands from the repository root:

```sh
taskset -c 20-23 make -f kprog/results/kprog_fidelity_20261107/negative/x86-trusted-sp/Makefile build
taskset -c 20-23 make -f kprog/results/kprog_fidelity_20261107/negative/x86-trusted-sp/Makefile kvm
```

The runner reuses the existing matched TV kernel/module and current incremental
loader build, with2 guest CPUs and2GiB. A fresh request journal is required to
preserve receipts on a repeat. This result is x86 KVM only. Prior AArch64 QEMU
results used the earlier bound path; the new common-service path still requires
its own AArch64 safety replay. Whole-program formal closure and application
acceptance are independent of this negative-suite result.

## Production XDP context repair replay

After published context repair `18aef1f0c` and module repair `86e0927e9`,
the unchanged38 native inputs complete independently: **9 valid controls
execute correctly and29 unsafe inputs reject; zero accepted negatives and
zero unsafe execution**. Rejection stages are22 verifier,6 specialization and1 loader.
Every native/request/kernel-capture/generated identity matches, all38
request source-pin sets agree, host inputs are unchanged, and Make exits0.
`production-context/summary.json` and compressed outcomes retain every case
and exact diagnostics. `production-context/run-production-context.tar.gz`
preserves the original request archives, stdout/stderr, service/console logs
and input pins. The original39 tracked request/journal blobs remain
byte-identical; their prior IDs and findings were not overwritten.

The existing harness now accepts `RUN_OUT` (and `check.py --out`) only to
select a fresh evidence directory. Default commands retain the previous
output location and execute the identical fixtures/probe/service logic.
Command used (choose a new RUN_OUT directory for a repeat):

```sh
taskset -c 20-23 make -f kprog/results/kprog_fidelity_20261107/negative/x86-trusted-sp/Makefile kvm RUN_OUT=/workspaces/repository/kprog/results/kprog_fidelity_20261107/negative/x86-trusted-sp/production-context
```

The separate ordinary context-store control also rejects on this production
path; see context-projection/x86-production. This finite suite does not close
SKB projection, full ISA/ABI refinement or all six application admission.
