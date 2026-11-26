# Both original JCC goto routes and the real fallthrough XOR

After the original condition caller return, the imported ConditionHolds result drives the real Onotbool decision. Taken executes5 source transitions through the original jcc_taken goto. Fallthrough executes13 source transitions through the original local goto, both real loop exits, the source result XOR1 and original next label. Both routes meet the same actual next body and remaining suffix on the same heap, with the exact saved temp map and imported-model branch result.

Focused build 473 and 2 public type/axiom queries pass under shared timing, CPU17, one worker and32GiB at original200000/512 proof caps. The public log records actual axiom dependencies. V owns whole confirmation.

Raw evidence: /workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z.
