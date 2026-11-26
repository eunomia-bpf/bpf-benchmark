# Retained actual clobber output through later local frees

The final current packet retains actual R0, source/copied bytes, SP, ABI, resources, tags, all18 actual GPR provider words, all4 masked flag bytes, all64 vector-half provider words and the same initialized fault flag. The original retained-local frame transports these observations through actual later-callee frees while that callee releases its own local permissions. Output observations use original producer-local bindings and the real caller frontier.

Focused build 465 and 3 public type/axiom queries pass under shared timing, CPU17, one worker and32GiB at original200000/512 proof caps. The public log records actual axiom dependencies. V owns whole confirmation.

Raw evidence: /workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z.
