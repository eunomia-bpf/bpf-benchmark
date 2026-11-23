# Actual width-four LSL1 modifier execution

The existing modifier source now has a checked LSL1 width-four execution law.
Its 41 actual Clight transitions include original parameter observations,
amount masking, case selection, shift, width mask, output assignment and loop
exit. It derives the source result (value << 1) & 0xffffffff and preserves
the entire heap, environment and continuation.

The proof shares the original source decomposition, imported shift/AND
semantics and existing switch structure with LSL0. New temporary snapshots
name only the actual reached assignments. The previous LSL0/W-X public law
retains its exact signature and recompiles with the new proof.

Focused build 236 and two public type/axiom queries (old LSL0 and new LSL1)
pass at original 200000-heartbeat/512-depth caps, CPU 17, one worker, 32 GiB
and shared timing lock. Queries report standard logic and inherited external-
function/assembly assumptions. Actual helper entry, reading and return are
the next composition boundary, followed by the full ORN handler/caller.
V coordinates whole confirmation. Raw evidence:
/workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z.
