# Original ADD tagged pointer path

Pointer.source factors the original selection into its four gate groups.
Pointer.select executes53 actual internal transitions: for width8, operationADD,
STACK4 and a destination other thanSP32, it bypasses SP-destination, ORR and SUB
branches and reaches the actual _t20 raw-pointer reader. All original candidate
and other temporary values remain in the reached environment.

Pointer.enter_writer adds the actual selected reader call, its21-step raw SP
read, return/sequencing and actual writer-call argument evaluations/casts. Its78
transitions reach the genuine linked pointer writer67 with raw spValue+rhs and
tag4. The source argument is not pre-materialized. All31 ordinary destinations
and arbitrary64-bit RHS are covered; raw SP comes from the same Storage.

Pointer.execute composes that same source path with the53-step pointer writer
and returns into the original handler in132 transitions. Storage rights derive
the actual stores, with no successful-store, new provider, native post-state or
old destination restriction. It retains Result (including raw/tag readback,
writable Storage, caller frame, permissions and frontier), complete register
representation at the original observer frontier and canonical cache-local Kept.
The writer's represented native value materializes raw+rhs/tag4 exactly once.

Checks and public theorem types/axioms are recorded alongside. Raw logs and
failed attempts stay in /workspaces/kprog-raw/formal/m5-add-tail. Original
200000-heartbeat/512-depth/asyncfalse limits remain, with one proof worker.

This begins at the actual selection after candidate evaluation and returns to
its original enclosing handler continuation. Full generic allocation/body/free,
original source successor, fetched native ADD composition and all-outcome
contracts remain. General W/SP/ZR/tag alternatives remain open. M5/O1/O2/O4/M6
are open, completed ISA families0. Whole confirmation follows at batch end.
