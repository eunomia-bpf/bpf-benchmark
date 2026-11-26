# Both complete original CBZ exits and actual fallthrough XOR2

The actual Numeric caller result is copied into the original taken temp. The real64<=32 width selector chooses the original forward-CBZ condition. Taken executes10 original transitions through the actual cbz_taken goto; fallthrough executes17 transitions through the real loop exit, source XOR2 and next label. Both reach the original TBNZ body with exact saved temp map on the same heap. The condition remains the imported LNSym CBZ predicate.

Focused build 481 and 2 public type/axiom queries pass under shared timing, CPU17, one worker and32GiB at original200000/512 proof caps. The public log records actual axiom dependencies. V owns whole confirmation.

Raw evidence: /workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z.
