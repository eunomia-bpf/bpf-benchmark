# Pre-LEAVE canonical interface refusal on saved real CPU states

The adapter reads the exact8192 CPU records from the completed parent
LEAVE64 experiment (1e18c95cb). It checks actual C9/one-byte boundaries and
all8 input classes, and sends real native bytes to V's one canonical step.
There is no LEAVE implementation in this adapter. It compares all16 GPRs,
PC, memory bytes/permissions, fault presence/model class and full RFLAGS
with only exception-delivery RF(bit16) cleared on fault. Raw flags and
hardware trap/error remain in the CPU record. SIMD/segments were not measured.

The frozen pre-LEAVE canonical executable f1c5d75b refuses all8 first requests;
zero canonical cases were compared. Make exits2. This is an unavailable
encoding, not a zero-difference canonical pass. Exact diagnostics, complete
first requests and per-class counts remain in unavailable.jsonl.gz and
reference-classes.tsv. The complete8192 CPU input/output records remain in
the parent's committed cases.jsonl.gz. No additional CPU execution occurred.

The verified archive contains this adapter and the exact old canonical
source closure. V is implementing the single canonical LEAVE rule; after
publication replay these SAMECPU states with that executable. Fault14/#PF
maps to the existing read-fault abstraction and fault12/#SS in these
noncanonical-frame cases to non_canonical; those categories and all register
rollback are checked, never synthesized as canonical behavior. No source
ISA, simulator, kernel/module or production header changed here.

```sh
taskset -c 16-19 make -f kprog/results/kprog_fidelity_20261107/differential/x86-leave64/canonical-before/Makefile reference
```
