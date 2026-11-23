# CSEL stores determine the CNEG scalar input

The original CSEL result certificate and its pre-memory register1 scalar/tag0
and register2 stack-relative/tag4 observations determine the actual stored
register5 word/tag. The source theorem derives the resulting CNEG input as a
Vlong value with tag0 or tag4. It uses the real conditional choice, original
stored word/tag readbacks and imported storage observations.

The complete eight-call program proof supplies these pre-memory observations
from actual MOV/MOVK and SP-relative ADD stores carried through intervening
add/multiply/compare executions. The existing CNEG body derives the physical
operand using the same register representation and M3 materialization.

Focused build 330 and one public type/axiom query pass at the original
200000-heartbeat/512-depth caps, CPU 17, one worker, 32 GiB and shared timing
lock. The initial diagnostics exposed Boolean false coercion and the explicit
Fin31 index normalization; their raw log remains with the successful run.
The query reports standard logic and inherited external-function/assembly
assumptions. V coordinates whole confirmation. Raw evidence:
/workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z.
