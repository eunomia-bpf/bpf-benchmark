# All three original allocated pointer-write call sites

Actual Clight supplies all three genuine pointer-write sites in their original order: r0=-32/tag4 before the two MOV calls and memset, then r0=-16/tag4 and r1=-32/tag4 before the next MOV and memcpy. Each site executes its original signed constant and pointer casts, allocation-bound header lookup, linked helper at block67, both actual payload and provenance stores, and true caller return. The entire call is55 transitions; its source sequence reaches the actual next statement in57 transitions. The intervening operations stay in those source continuations. Storage derives write rights and the full register/cache/frame result. Stack offsets materialize through the existing provenance binding and the imported architectural register write; this setup helper adds no architectural instruction step.

Focused build 292 and 6 public type/axiom queries pass under shared timing, CPU17, one worker and32GiB at original200000/512 proof caps. The public log records actual axiom dependencies. V owns whole confirmation.

Raw evidence: /workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z.
