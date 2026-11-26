# Same memset output and flag through actual following pointer calls

The actual retained full memset output executes both original following pointer call sites, including all four actual word/tag stores and saved program temps. R0/R1 receive their genuine new pointer words/tags. Same source bytes, resources, remaining actual provider GPR words, flags, vector halves and initialized flag survive via original effect/header/tail/local-load laws. The resulting real PointerState.Packet reaches the original length MOV.

Focused build 472 and 2 public type/axiom queries pass under shared timing, CPU17, one worker and32GiB at original200000/512 proof caps. The public log records actual axiom dependencies. V owns whole confirmation.

Raw evidence: /workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z.
