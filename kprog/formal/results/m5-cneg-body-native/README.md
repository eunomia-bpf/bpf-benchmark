# Complete CNEG body and LNSym native step

Body.corresponds pairs the actual full CNEG64/GE handler body with the fetched
LNSym CSNEG X6,X5,X5,LT alias. The same pre-memory scalar word/tag observation
and existing register representation derive the physical source value,
including M3 stack-origin materialization. The source result is the native
GPR5 word or its modular negation according to the reached GE condition.

The actual writer certificate supplies stores, typed readback, caller-frame
and permission effects. Its established representation law proves all GPRs,
SP, SIMD and NZCV for the native post-state. The fetched instruction's decoder
certificate and no-error pre-state establish PC+4, empty events and no fault.
The result also retains every original generic argument and every producer
local observation outside the two destination cells.

Focused build 262 and one public type/axiom query pass at original proof
caps, CPU 17, one worker, 32 GiB and shared timing lock. Standard logic and
inherited external-function/assembly assumptions are recorded by the query.
Generic allocation/free and the original eighth caller/prefix composition
continue next. V coordinates whole confirmation. Raw evidence:
/workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z.
