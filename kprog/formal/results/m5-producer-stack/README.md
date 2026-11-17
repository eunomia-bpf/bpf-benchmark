# Actual raw producer stack-tag and SP initialization

The exported segment immediately after the vector inputs contains 24 byte
assignments to the actual stack-tag local, then the signed-long SP-zero
assignment. Kernel-checked source and offset equations use this profile's
24-byte declaration rather than assuming a generic stack capacity.

`stack_tag_local` derives the allocated binding and complete writable range
from the real producer allocation. Each actual assignment constructs its byte
store and completes three internal transitions. The finite composition
`stack_tags_initialized` completes all 24 actual assignments in 72 transitions
with every byte reading back zero. It preserves all other declared-local
loads, all caller bytes and Cur/Max permissions, access and allocation frontier.
`sp_initialized` then completes the actual SP-zero assignment in three
transitions. `stack_tags_and_sp` composes the exact source segment in 75
transitions, preserving both tag-byte and SP readbacks and all other locals.
The saved environment, temporaries and control continuation remain actual.

The stage-start access map matching the actual allocation remains an explicit
premise. This internal segment has no provider or assembly step. No input
provider purity, native physical SP origin, packed-word tag-read theorem,
stack payload initialization or whole-producer/native correspondence is claimed.

Focused build passes 153 jobs, seven compiled public type/axiom queries pass,
and the full build passes 280 jobs under timing SH. Source facts use standard
axioms; internal runs additionally mention the imported opaque external and
assembly relations in Step2, without executing either boundary. Default proof
limits and one worker are retained. Last full `make check` passed at
`5236c0e96`; no native rerun for this Lean-only change. C, exports, external
semantics and frozen benchmark paths are unchanged.

Reproduce from `kprog/formal` using the lane's CPU/memory limits:

```
LEAN_NUM_THREADS=1 lake build KProgFormal.ClightRefinement.Arm64ProducerStack
LEAN_NUM_THREADS=1 lake env lean -j1 results/m5-producer-stack/Query.lean
flock -s /workspaces/.agent-state/kprog-lanes/locks/timing env LEAN_NUM_THREADS=1 lake build
```

All attempts and result-side preparation logs remain under
`/workspaces/kprog-raw/formal/m5-producer-stack`. Context/tag updates, entry
header/cache-pointer construction, borrowed continuation and native
ABI/origin/memory/control correspondence plus O1/O2/O4 recount remain M5.
Complete ISA-handler refinements remain zero; M6 closure follows M5.
