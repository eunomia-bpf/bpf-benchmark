# Both original TBNZ labels and precise goto continuations

Both original TBNZ targets are cached from the complete original function body and checked against imported Clight.findLabel/callCont. The actual local fallthrough returns to the original TBNZ loop continuation; taken reaches the real following comparison body with its precise remaining suffix. Both actual Step.goto transitions preserve source heap, original program env and saved temps.

Focused build 484 and 6 public type/axiom queries pass under shared timing, CPU17, one worker and32GiB at original200000/512 proof caps. The public log records actual axiom dependencies. V owns whole confirmation.

Raw evidence: /workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z.
