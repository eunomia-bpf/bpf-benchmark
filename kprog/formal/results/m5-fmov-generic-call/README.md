# Original FMOV generic call and real frame release

The true nine-argument FMOV call enters the original generic handler, derives vector/source loads and writable permissions through the actual allocation frame, executes the346-transition source/native body, and releases all live locals before returning. The348-transition call retains final low/high vector reads, actual producer Storage, write permissions, complete register correspondence, every differently named producer-local load and the original caller frame. Freed ranges lose all permissions. The body projections use kernel-checked field equalities at original recursion limits.

Focused build275 for the actual original FMOV generic call and release and 1 public type/axiom queries pass at original200000/512 caps, shared timing, CPU17, one worker and32GiB. The query log records the exact imported axiom dependencies. V owns whole confirmation.
Raw evidence: /workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z.
