# Real ARM BCC exclusive-retry rejection

The canonical native-only service generated and compiled `vfsstat/fentry_vfs_read`,
then the bound loader rejected its proof with `infinite loop detected at insn2`.
The actual native sequence is LDXR at8, ADD at12, STXR at16, CBNZ at20 back to8.
The store-outcome input quantifies over both0/1 on every visit; its failure branch
returns to the load with the same verifier state. No artificial trip bound,
forced success, changed native source or changed compiler flags was used.

`summary.json` retains the exact compiled instructions, bound context, native and
artifact hashes. `request-1.failure.tar.gz` is the complete closed service request,
including kernel-copied native bytes, source identities, generated C/native proof/
BPF, compiler commands and full loader/verifier diagnostics. Native identity was
independently checked against the service receipt and fresh generator input.
This is one rejected application request, not a completed BCC inventory or run.
The existing eight-tool/two-start BCC guest continues unchanged and its collector
owns the whole-run publication.

The repair must preserve both exclusive outcomes and the original control flow.
The current verifier combines memory-safety and termination checking, while this
native retry has no fixed iteration bound. A private kernel-contract candidate
examines exact-state convergence only after a sealed exclusive outcome and reuses
SCC read/precision propagation; it has only passed patch applicability, is not
applied/compiled/accepted, and makes no native termination claim. Kernel/SCC safety,
liveness-contract implications, delayed unsafe branches, ordinary-loop rejection,
existing safety regressions and the real application still need validation.
