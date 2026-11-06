# Bound exclusive-store outcomes on ARM

The former simulator always wrote memory and status0. STXR/STLXR now consume
an explicit fresh Boolean failure outcome at each actual source instruction PC.
The T binding ties that marker to the exact final native exclusive store,
width and release bit. Success performs one existing width-specific write;
failure leaves memory unchanged. Both paths write the architectural32-bit
status and preserve NZCV. No fabricated reservation, helper return or entry
monitor assumption is used. Keeping both branches also requires verifier
admission of the store address even when a concrete monitor would fail.

The generated Boolean-status contract replaces the unconditional-success
contract. Lean connects that status to the authoritative physical-monitor/
environment model, including empty-monitor failure. The full359-module
Lean/C/Rust/wire check passes. All2056 status cases,400 exact-memory handler
cases and686110 full-state/tag/stack route cases pass with both outcomes;
all old success scenes remain. A final focused retry also checks that the
status write clears the entire upper32 bits. The59 legacy host recipes explicitly select
their old success fixture, while exclusive-specific tests provide per-case
outcomes. There is no production default hook. Earlier full attempts exposing
an unrelated concurrent syntax edit and the missing host environment are
retained in the lane logs; the final combined full log is archived here.

Four actual W/X STXR/STLXR positive programs pass source and bound-native
QEMU execution: result37, return2, generation1. Their success/failure branches
both produce37 through the corresponding conditional private store; the
observable result assumes neither success nor absence of spurious failure.
The exact new kernel/module/loader, native proofs and frozen simulator inputs
are built into replay.tar.gz. Extract and run `make -C runtime run`; on DGX
Spark add `ACCEL=kvm CPU=host`. A standalone proof cannot load its private
bound-only marker; these controls exercise the required bound route.

F's retained30-case actual bound suite now rejects all four formerly accepted
exclusive-failure branches at the verifier. It also rejects the repaired D0
high-lane case; two older numeric SP/LR findings remain active repairs. Unsafe
candidates were never executed. The captured outcome JSON retains every case.

The source/native memory-order, platform-alignment/single-copy-atomicity and
whole-program event projections remain active proof and implementation work.
Fresh choice plus descriptor binding alone does not establish those properties;
this result closes the demonstrated missing failure paths and conditional-write
bug without claiming complete concurrent ISA or six-application equivalence.
