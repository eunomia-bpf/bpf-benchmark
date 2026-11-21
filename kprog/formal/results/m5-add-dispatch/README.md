# ADD_IMM dispatch from the original body

Arm64AddImmediateDispatch decomposes the complete exported generic body into
its actual width call and NOP, ADRP, MOV, MOVK and ALU gates. body_source
kernel-checks exact reassembly; no alternative handler body is substituted.

body_dispatch_bound certifies 39 internal transitions from that original body
to its original ALU branch for opcode3, both W and X widths, arbitrary memory,
local environment, remaining temporaries and caller continuation. It includes
the actual four-transition width-call entry, six-transition exported width
procedure, and 29 transitions installing the result and making the gates.
The exact reached temp environment and original loop continuation are retained.
No source/destination values, heap validity, provider outcomes or successful
register reads are assumed for this dispatch-only prefix.

The generic theorem uses the actual width symbol/function binding and its
ordinary unshadowed local-name condition. The linked API checks the original
width definition at block97 in the one fixture/Program/Numeric world.

Focused checking passes 228 Lake jobs and four public type/axiom queries at
original 200000-heartbeat/512-depth caps, CPU17, nice0, one worker and32GiB
address space. Only standard logic and inherited external/assembly relations
appear. Count.lean records the diagnostic path counts for both widths; the
actual path proof is independent of that evaluation. Whole-library confirmation
follows at batch end; raw /workspaces/kprog-raw/formal/m5-add-dispatch.

This is dispatch from an already-entered handler body. Generic function entry,
LHS/RHS/tag/arithmetic/write/free, original source successor and fetched native
ADD composition remain M5 work. O1/O2/O4 and M6 remain open; ISA-family count0.

Batch confirmation (2026-11-21): `lake build KProgFormal` passed all 294 jobs
in 30.436 seconds, with the root artifact at 2026-11-21T15:24:43.564922+00:00.
CPUs16-23/nice19/one worker/32GiB AS; native tools/executables excluded.
This confirms the three changed proof steps together; no complete handler
count, O1/O2/O4 recount, final default Lake build or make check is claimed.
