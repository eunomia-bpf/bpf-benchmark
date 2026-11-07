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

The34-input build and static linking passed. The QEMU run is in progress;
no ARM rejection/execution total is claimed yet. Its eventual compressed run
archive and summary go under `trusted-arm64-service-result/`, retaining exact
per-case diagnostics, kernel/worker identities and any failure. Do not restart
its healthy guest merely because QEMU or clang is slow. The accepted original
x86 results and prior ARM bound-path results remain separate evidence.
