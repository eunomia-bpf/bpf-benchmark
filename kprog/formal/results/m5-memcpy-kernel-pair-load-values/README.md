# Bind both real LDP register pairs to the same physical source words

The mature bit-level memory theorem proves that either64bit half of the actual16byte read equals the corresponding8byte read at wrapping64 addresses. Both captured LDP instructions and both platform pair modes therefore produce the exact physical low/high words, retaining arbitrary underlying contents and original initialization observations. TwoLoads now exposes reached-state equalities derived by reflexivity from its existing execution. The same loaded/final witnesses give X6/X7 and X12/X13 from the original source; the second LDP preserves the first pair and its unchanged physical memory supplies the repeated pair. No fresh successful read or state premise is added.

Focused build 84 and 5 public type/axiom queries pass under shared timing, CPU17, one worker and32GiB at original200000/512 proof caps. The public log records actual axiom dependencies. V owns whole confirmation.

Raw evidence: /workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z.
