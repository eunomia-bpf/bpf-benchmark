# Original memcpy transfer and shared clobber continuations

The cache is extracted from the actual original memcpy afterCopy Clight source. Its transfer/Scall sequence and outer source loop retain the real body and continuations. Kernel-checked statement equality identifies the same original clobber call used by memset. Two actual entry and three actual exit transitions retain the memcpy function, its own eight-local environment, temporary map and heap.

Focused build 377 and 4 public type/axiom queries pass under shared timing, CPU17, one worker and32GiB at original200000/512 proof caps. The public log records actual axiom dependencies. V owns whole confirmation.

Raw evidence: /workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z.
