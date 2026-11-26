# Actual memcpy destination pointer and SP guard

The original destination selector consumes the actual source-SP result, calls the linked R0 pointer reader104 into temp82, restores the saved memcpy frame, reads header40 into temp95 and actual SP into temp96, then evaluates signed(-16+i>=-32) into temp81=1. The true arm executes39 steps; the actual preceding skip and selector extend it to41. Both actual SP reads and the R0 observation derive from the same current packet. All sixteen copied bytes, eight caller-local ranges, loop controls and the reached heap are retained.

Focused build 439 and 5 public type/axiom queries pass under shared timing, CPU17, one worker and32GiB at original200000/512 proof caps. The public log records actual axiom dependencies. V owns whole confirmation.

Raw evidence: /workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z.
