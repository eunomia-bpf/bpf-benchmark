# Use kernel-checked wrapping separation for actual STP memory frames

Public dependency inspection exposed three local native bv_decide dependencies in the initial outside-byte proof. This forward change replaces them with explicit unsigned-distance bounds, modular subtraction cancellation and kernel-checked arithmetic. Actual STP readback, outside frames and complete pair-mode memory equality retain their original types and arbitrary wrapping64 domain. Public queries now retain only the mature imported MemoryProofs native dependencies, named in the log, alongside standard logical dependencies; the kprog proof introduces no local native axiom. The initial receipt remains as historical evidence.

Focused build 96 and 8 public type/axiom queries pass under shared timing, CPU17, one worker and32GiB at original200000/512 proof caps. The public log records actual axiom dependencies. V owns whole confirmation.

Raw evidence: /workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z.
