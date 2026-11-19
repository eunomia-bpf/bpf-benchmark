# Tracee checked-generation failures while the run continues

PERF 2026-11-19T14:23:33Z: The coordinator's current main C/LTO run has completed
its baseline and is loading native programs. This snapshot retains every
record of the first33 completed requests, including checked and direct
paths; it is not the final app census or a performance result. Full logs
and capsules remain at the path in provenance.json. No guest, profile or
production change was started for this inspection.

Two distinct verification classes are already concrete:

- Request27, sys_dup_exit_tail: B generated, stock rejected at instruction959,
  `r7 -= r1`; r7 is an unbounded scalar and r1 is fp-280. The verifier says
  math between fp pointer and an unbounded register is not allowed.
- Request28, tracepoint__sched__sched_process_fork: B generated, stock
  rejected at instruction1, an eight-byte write to R10-536. This exceeds
  the unchanged512-byte stock frame limit.
- Request30 repeats the arithmetic class at instruction27607: R2 tried
  to subtract a pointer from a scalar. Its full symbol/source location is
  still to be resolved from the retained capsule.
- Requests29 and31-33 pass checked-sim-c. The rejected B requests above
  all install direct native with status0, as recorded. They are not skipped.

The arithmetic is separate from the repaired SKB NUMERIC input boundary.
Shared source x86_sim_local_bpf.h:948-953 forms an integer difference
between an address and the arena base, and :1645 performs another arena
difference for cache restoration. These are candidate origins, not an
exact debug-location mapping of the failing instructions yet. BPF register
provenance can survive C pointer-to-integer casts; do not fix this by
deleting the observation, removing alias semantics, choosing a constant
stack base or accepting unverified B. Native compilation must retain the
actual bits. A sound B-only numeric abstraction is a candidate to study,
with correlation/precision and source preservation still to establish.

Next after the active timing lease: inspect request27/30's completed
frontend and source debug mapping, reproduce the subtraction with a small
real B fixture, and test a general compiler transformation on that retained
IR. For request28 inspect actual packed frame objects and lifetimes before
choosing a change. No full frontend replay, relaxed compiler/kernel limit,
new refusal or runtime check is implied. Preserve the current run and report
all final checked/direct paths and samples when it finishes.
