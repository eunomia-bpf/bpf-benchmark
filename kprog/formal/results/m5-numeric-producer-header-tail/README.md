# M5: initialized Numeric header tail and callback bindings

The actual 16 header-tail stores now execute under an explicit world, matching
composite layout and the two real callback-symbol bindings. Existing local
addresses, union layout, casts, store/list construction and permissions are
reused. The three original public APIs remain projections, including the
complete 276-transition header and cache laws.

`payload_callbacks` derives both findSymbol and findFunctPtr in the actual
Numeric global environment for the retained load/store callbacks at blocks
184/185. The kernel checks the source equalities. Layout equality is not used
to infer symbols or function bodies. Tail initialization consumes only the
symbol facts it actually reads; the function-body facts remain available for
subsequent calls without an extra admission premise.

`initialized_tail` appends only 48 actual silent transitions to the earlier
Numeric execution, reaching beforeVectorLoop. All 16 typed tail readbacks
are derived, and the earlier 12 scalar addresses and 64 null vector-pointer
slots survive. The new nine TailLocal witnesses bind the actual source
locals. Binding uniqueness connects the stack-tag and helper-context/base
pointers to the previous resources.

Both tables, updated GPRs/x0 context-tag1/x30 zero-tag10, flags, LR/SP zero,
64 vector input words, 24 stack tags, context cells, `_ctx`, initial204 global
contents/permissions and allocation access/frontier survive with the same
98 ordered traces. Both borrowed cache-storage resources derive again at
this reached memory from preserved scalar pointers/rights; local binding
uniqueness and framing retain their cold values. Earlier header stores are
not repeated. The 64 vector header pointers remain NULL until the live loop.

The represented-context and actual-world provider contracts remain explicit.
Actual vector-loop/Storage/caller/native/provider admission, relative caches,
physical memory/alias/origin/control and all-family O1/O2/O4 recount remain
M5. Complete ISA-handler/family count stays 0; M6 follows M5. The separate
x86 atomic and released-alias formal bindings remain open.
No C/runtime, benchmark, paper/design, kernel, base or image change is made.

Raw attempts: /workspaces/kprog-raw/formal/m5-numeric-producer-header-tail.
Every host command holds timing SH. One-worker builds use CPU17/32GiB;
reads/queries/Git use CPU16. Default200000 heartbeats/512 recursion/asyncfalse.
Validation outcomes and public axiom sets are in validation.json.

Final validation: full Lake passes 332 jobs; all eight public type/axiom
queries pass. Focused attempts are retained in validation.json. All ten Arm64
exports retain the byte baseline. The historical 23-file comparison records
12 changed x86 exports and exit 1; it remains an explicit
report, with no x86 atomic/alias proof claim. Current export bytes are
248620630; historical baseline bytes are 243488732. Native make check
remains due at final goal confirmation.
