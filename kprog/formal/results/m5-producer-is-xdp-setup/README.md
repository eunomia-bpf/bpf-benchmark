# Actual is_xdp zero initialization on the original setup witness

The original three exported setup assignments execute nine actual internal steps. Their real byte store initializes the allocated sim_is_xdp TailLocal5 to zero; the following original helper-context and ABI-base stores preserve it by allocation separation. Deterministic internal successor equality identifies this constructed store witness with any reached original nine-step setup, so its zero observation belongs to that same execution. The public theorem quantifies the actual reached run and uses no external provider replay. Header696 is the later pointer to this is_xdp source byte.

Focused build 410 and 1 public type/axiom queries pass under shared timing, CPU17, one worker and32GiB at original200000/512 proof caps. The public log records actual axiom dependencies. V owns whole confirmation.

Raw evidence: /workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z.
