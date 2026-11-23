# Actual FMOV vector memory effects

The actual512-byte producer vector allocation derives both successful Mint64 stores: low64=value at48, then high64=0 at56. The first actual store carries the writable certificate to the second. Imported CompCert memory laws prove both final reads, both halves of all31 other vectors, exact loads of every chunk on every other block, access preservation and the unchanged allocation frontier. These proofs use standard logic only.

Focused build178 for actual vector memory effects and 7 public type/axiom queries pass at original200000/512 caps, shared timing, CPU17, one worker and32GiB. The query log records the exact imported axiom dependencies. V owns whole confirmation.
Raw evidence: /workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z.
