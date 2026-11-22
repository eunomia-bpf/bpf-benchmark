# Fetched native CSEL64

Arm64SelectNative binds the mature conditional-select fields for plain 64-bit
CSEL with ordinary source and destination registers and any four-bit condition.
It evaluates DPR.exec_conditional_select through LNSym's ConditionHolds,
read/write operations and real PC update. No new native decoder, condition
semantics or instruction body is defined.

native_step retains the external decoder certificate, real instruction fetch
and initial error-state premise. reference_step returns the full machine with
PC+4, no new memory events and no fault. Other registers, flags, memory,
permissions, histories and extra native state stay with the original machine.
pointer_step identifies this selected source with its existing raw/tag/native
materialization before applying the same fetched step. It does not assume a
source writer post-state or store success.

Focused build186 and four public type/axiom queries pass at the original
200000-heartbeat/512-depth caps on CPU17/nice0/one worker/32GiB. The public
native statements use only standard logical axioms. One Bool normalization
failure is retained in raw; proof limits were unchanged. Whole-library
confirmation follows at batch end.

The matching Clight writer execution, whole generic call, frame free, original
seventh source call and full handler correspondence remain open. This native
step alone closes no ISA family. M5/O1/O2/O4 and M6 remain open.
Raw: /workspaces/kprog-raw/formal/m5-select-branch/20261122T105431Z.
