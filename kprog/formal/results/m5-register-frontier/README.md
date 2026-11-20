# Producer storage at owned frontiers

`Arm64RegisterStorageFrontier` proves exact GPR, SP, NZCV and vector observer
equalities between any frontier above the canonical producer allocation and
the actual memory frontier. Every followed header/table/cell/pointee address
comes from the existing typed allocation bindings. Refused loads, undefined
values and pointer-valued words keep the imported Mem semantics.

The complete existing register relation transports in both directions at the
same memory and native state. `storage_frame` preserves the same allocation-
bound Storage through a frame at that owned frontier. This permits freeing
separate generic-handler locals without falsely claiming their freed blocks
remain framed below the larger callee allocation frontier. The borrowed-slot
law also covers the actual cache header pointers.

No external result, store success, changed pointer interpretation, or new
native ABI admission is assumed. This is a resource/observer transport lemma,
not execution of a fetched ISA instruction. The actual MOV_IMM dispatch and
cold-reader suffix must still be composed using these laws.

Focused 176 jobs and eleven public type/axiom queries pass at original caps,
CPU 17, nice 0, one worker and 32 GiB address space. The whole
`lake build KProgFormal` proof library/root passes 275 jobs together with the
actual-call composition, on CPUs 16–23, nice 19, one worker and 32 GiB address
space. Executable/tool builds are excluded under the current directive. Initial failures were finite
source-equation normalization at field names, conditional vector offsets and
Ptrofs zero addition; raw logs are preserved and limits were unchanged.
Validation and inherited logic axioms are recorded in validation.json.
Raw: `/workspaces/kprog-raw/formal/m5-register-frontier`. M5/M6 remain open;
completed ISA-family count is zero.
