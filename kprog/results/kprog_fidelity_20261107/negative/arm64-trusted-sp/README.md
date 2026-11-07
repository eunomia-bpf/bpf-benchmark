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

The second host run also ended with a reporting-only failure: its repeated
safe control executed correctly, and `misaligned_sp` was rejected by the
production ABI analyzer with `native SP alignment fault at 0x10: ldrb w0, [sp]`.
The original archive and guest exit1 are retained in `second-run-summary.json`;
normalized outcomes are separate. The classifier now recognizes a ValueError
whose traceback originates in the actual x86/ARM micro-prog generator or ABI
analysis, rather than needing a new literal for every legitimate refusal.
Compiler/syscall/producer exceptions retain their separate stages. Cumulative
unique coverage is4 safe controls and12 rejected unsafe cases, with18 extended
negatives still to execute. No unsafe native program has run or been accepted.

The third continuation finished on2026-11-07 at11:43UTC. It recorded the
unchanged passing control,13 additional unsafe refusals (7 specialization and
6 verifier), then **one accepted unsafe return-target input**. That accepted
case was strictly LOAD-ONLY: no unsafe TEST_RUN occurred. The unmodified host
archive is `trusted-arm64-service-result/run-20261107T112703385738Z.tar.gz`;
`third-run-*` files retain its exact messages, identities, exit and counts.
Cumulative completed unique identities are4 valid controls and25 rejected
unsafe inputs;5 unsafe inputs remain unresolved, including the accepted
finding. `completed-cases.json` excludes that acceptance so a continuation
must retry it. Root cause: the proof native linker changed entry RET into an
unconditional trampoline branch before the simulator could observe the
return register. A repair and native-only common-service replay are in
progress; no full safety pass is claimed.

The return-target repair preserves entry RET, including the return after an
external tail-helper veneer, when proof mode retains the entry ABI. It leaves
the kernel execution linker behavior unchanged. Three assertions extend the
existing frame/tail-call regressions; all58 ARM linker tests passed. Both host
and static AArch64 builds completed incrementally in a private copy of A's
warm target directory. `return-linker-*` retains build logs, source/binary
hashes and the exact source/binaries. No shared executable/image/kernel/module
was overwritten. The existing transport now selects this private specializer
linker; the producer still uses its unchanged kernel-mode linker.

```sh
taskset -c 16-19 make -f kprog/results/kprog_fidelity_20261107/negative/arm64-trusted-sp/Makefile linker-build
taskset -c 20-23 make -f kprog/results/kprog_fidelity_20261107/negative/arm64-trusted-sp/Makefile qemu
```

The repaired replay reruns every one of the34 saved native identities, rather
than skipping older receipts generated by the lossy linker. This full fresh
common-service/QEMU validation is pending; the historical accepted finding
remains visible above until the new per-case receipts establish rejection.

## Immutable checkpoint of the repaired full replay

`fresh-prefix-summary.json` and compressed outcomes record only closed requests
from the still-running full34-case replay using the corrected proof linker.
The unchanged native ELF SHA is checked against both the saved fixture and the
actual kernel-owned ELF in each request archive. Every counted request archive
is closed and independently hashed; all unsafe submissions are LOAD-ONLY.
`fresh-prefix-requests.tar.gz` retains those complete original request archives
plus the run's input pins and selected native identities. The summary gives the
exact completed count/stages and any source drift at capture. Remaining cases
are not counted, and this checkpoint makes no full-suite pass claim. The
historical accepted return-target finding and old-linker archives remain above.

## Completed repaired full replay, 2026-11-07 12:38 UTC

The existing detached replay has now completed all34 unchanged native inputs:
4 valid controls executed correctly under both kernel and generation-bound
native paths (result0, retval2), and all30 unsafe inputs were rejected.
The breakdown is16 verifier rejections,13 specialization rejections and1
loader rejection. Guest and QEMU exit0; unsafe acceptances0; unsafe native
executions0. The earlier pending/checkpoint statements above describe their
historical captures and are superseded by this full-run result.

`fresh-full-summary.json` records every case's stage, exact decisive diagnostic,
native identity, closed request archive SHA256 and original message SHA256.
Offline receipt checks matched all34 identities against the saved fixtures,
request receipts, kernel-owned ELF and specializer input ELF. All34 request
source-identity maps agree; shared identities match the host's input pins, and
the transport records unchanged source/binary pins over the full run.
The original host archive remains in this Workspace at
`trusted-arm64-service-result/run-20261107T120541064586Z.tar.gz`, SHA256
`040286c756831a8ce05f53e8fb697147549940766370a45867ee0af87067aede`.
The existing Makefile qemu command above produced this run; harvesting receipts
started no new guest or build and did not rerun any native input.

The previously accepted `return_register_overwrite` identity now rejects in
the verifier with `invalid func unknown#-1`; the native identity is unchanged.
This closes that saved linker regression. It does not establish universal O3:
the independent ordinary-context-store admission finding on both ISAs remains
open in `../context-projection/README.md`, with C/A owning the production
projection repair. Real-hardware validation of the current ARM771-form
static differential harness also remains pending.
