# Actual CNEG read, condition, numeric and write path

Path.execute composes the original scalar-reader call, actual GE helper and
normalization, width-8 numeric suffix and scalar-writer call on the same
reached heap. Ordinary scalar and warm-stack operands both follow their
original source path. The initial premises identify the real pre-memory
word/tag, selected warm cache, current flag representation, writable storage
and original source-call arguments.

The result contains actual word/tag stores, typed readback, caller-frame and
permission preservation, and the original generic-handler inputs. All reader
and condition calls execute; intermediate returned values and post-memory
states are derived by the component proofs. The arithmetic negates the M3
materialized operand exactly when the reached native GE condition holds.
The public transition count is existential, reusing the component runs.

Focused build 256 and one public type/axiom query pass at the original
200000-heartbeat/512-depth caps, CPU 17, one worker, 32 GiB and shared timing
lock. Standard logic and the inherited external-function/assembly assumptions
appear in the axiom query. The first attempt's source-site simplification
and finite-membership diagnostics are retained with the successful checks.
The accepted proof uses direct imported PTree transport laws at distinct
keys and reuses the existing reader/condition/numeric/writer semantics.

The next composition connects this original branch to full handler dispatch,
then generic allocation/free and the genuine eighth source/native call.
The complete original program prefix currently reaches seven calls. Root
integration follows that component batch; the numeric and writer components
already passed the 411-job targeted root and three root queries. V coordinates
whole confirmation. Raw evidence remains under
/workspaces/kprog-raw/formal/m5-cneg/20261122T123023Z.
