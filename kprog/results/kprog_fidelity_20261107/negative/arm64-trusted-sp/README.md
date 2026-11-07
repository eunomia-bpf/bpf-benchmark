# Native-only AArch64 common-service safety replay

The shared safety harness now selects x86 or AArch64 build/endpoint paths.
Its x86 default still produces exactly the same38 case dictionaries, native
ELF SHA256 values and manifests after rebuilding; `x86-default-parity.json`
records that comparison. The ARM builder compiles34 native-only inputs:
4 valid controls and all30 existing AArch64 negatives. The operator's existing
ARM loader static library/native-link build are reused, and the application
probe is statically linked for AArch64. No application proof is generated.
Assembler warnings for deliberately unpredictable register-overlap negative
inputs are retained as expected input evidence, not silently excluded.

The QEMU job is detached on host CPUs20-23 with2 guest CPUs and2GiB. It reuses
A's unchanged `trusted_service_arm64.host` transport and its retained v35 root
read-only, while directing the guest into lane F's safety harness and results.
F's live receipts temporarily use the transport's `service-*` directory; its
existing exit path archives them and deletes only that completed temporary.
The safety producer, native fixtures and output belong to F. Existing kernel,
module, worker and loader binaries are read as inputs and remain unmodified.

Valid controls cover return2, SP copy/restore, stack-alias memory and spilled
SP restoration. The negatives use a mutable HASH source context; its key may
be absent. Only valid controls reach TEST_RUN. The shared registered service
generates each proof from the kernel-owned native input; negative acceptance
would be a finding and remains load-only. Existing source/native identity
checks are retained. The shared suite implementation stays in
`negative/x86-trusted-sp/check.py`; there is no second broker or ISA model.

Commands from the repository root:

```sh
taskset -c 20-23 make -f kprog/results/kprog_fidelity_20261107/negative/arm64-trusted-sp/Makefile build
taskset -c 20-23 make -f kprog/results/kprog_fidelity_20261107/negative/arm64-trusted-sp/Makefile qemu
```

The34-input build and static linking passed. The first QEMU run completed
4/4 valid native executions and rejected all11 original requested negatives:
8 in the verifier,1 in the loader (no BPF exit),2 during specialization.
The BRK rejection was initially labeled `pipeline_rejected_unclassified` because
the report classifier lacked the exact `unsupported arm64 instruction` text.
Its recorded error/traceback proves specialization rejection before proof
compilation. Only that classification was corrected; the complete original
run archive remains unchanged, including its guest exit1 and all counterinputs.
`first-run-counts.json`, `first-run-summary.json` and compressed normalized
outcomes make that distinction explicit. Kernel/module/worker/loader inputs
were unchanged during the run. Guest timestamps start at1970; host UTC archive
and summary timestamps identify the actual run.

The remaining19 extended negatives have not yet run. The continuation uses
`completed-cases.json` to retain already-completed native identities and run
only missing cases plus the same safe return2 control. Every skipped completed
native SHA must equal the saved receipt; no unsafe case is excluded. Each new
host run gets its own archive under `trusted-arm64-service-result/`; combine
per-case identities across archives when reporting the full30-negative total.
There is no complete ARM suite pass claim yet. No production simulator,
generator, kernel or binding semantics changed for this report correction.
The accepted original x86 and historical ARM bound-path results remain separate.
