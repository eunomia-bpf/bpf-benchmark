# Actual terminal scalar and zero-SP storage with caller and local frames

The same three actual stores update real storage.spValue to0 and derive current X0 scalar/tag0, while every other GPR/tag, flag byte, vector half, header and original tail local remains. Allocation separation and imported store laws retain exact local loads, access/frontier and original caller frame. No old helper-phase R0-tag4/SP=-32 field is asserted after these stores.

Focused build 536 and 9 public type/axiom queries pass under shared timing, CPU17, one worker and32GiB at original200000/512 proof caps. The public log records actual axiom dependencies. V owns whole confirmation.

Raw evidence: /workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z.
