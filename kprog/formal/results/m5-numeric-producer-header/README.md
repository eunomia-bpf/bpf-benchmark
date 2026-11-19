# M5: initialized Numeric scalar header pointers and cache storage

The existing header lvalue/RHS/store/list proofs now accept their execution
world and matching composite layout where needed. Source metadata, local
storage, pointer casts and store construction are reused. All 12 actual
scalar pointer assignments execute in 36 internal transitions with exact
readbacks at `8*i`, preserving every other declared local and the original
caller frame/access/nextblock. Old public contracts remain projections.

`initialized_header` follows actual Numeric initialization, 98 input visits
and stack/SP/context setup. It derives the real header and all 12 source-local
bindings, connects its table/LR/SP pointers to the already derived resources,
and reaches `afterHeaderPointers`. The actual pointer tables and GPR data,
including x0 context/tag 1 and x30 tag 10, four flags, LR/SP zero, 64 vector
words, 24 stack tags, context cells, `_ctx` and original 204-frontier global
contents/permissions remain. The same 98 traces are retained.

The memory-only `header_cache_storage` law is reused at this same reached
memory. Both borrowed cache-storage resources are derived from the 12 pointer
readbacks and real allocation rights, with each entry block identified with
the actual header. Binding uniqueness connects the derived cache locals to
the earlier cold-cache witnesses, preserving both base words and valid bytes
at zero. Cache resources are not assumed and header stores are not duplicated.
The borrowed consumer layout facts are reused without equating whole Genvs
or Senvs or claiming a consumer execution.

Existing represented-context and actual-world provider ABI/availability
premises remain explicit. Remaining vector-pointer arrays/header tail/RAW,
full register Storage/caller and native/provider admission, relative cache
materialization, physical memory/alias/origin/control and all-family O1/O2/O4
recount remain M5. Complete ISA-handler/family count stays 0; M6 follows M5.
The separate x86 atomic/released-alias binding remains open. No C/runtime,
benchmark, paper/design, kernel, base or image change is made by FORMAL here.

Validation and retained attempts are in validation.json. Raw data:
/workspaces/kprog-raw/formal/m5-numeric-producer-header. One-worker builds use
CPU 17, reads/queries/Git use CPU 16; every host command holds timing SH,
with 32 GiB address space and normal 200000 heartbeats / 512 recursion limits.
No new trusted axiom or increased proof limit is introduced.

Final result: focused attempts are in validation.json. Full Lake passes
330 jobs once at the end; all six public type/axiom queries pass. All ten
Arm64 exports retain the byte baseline. The full 23-file comparison records
12 changed x86 exports from PERF’s source updates and exits
1; that report remains explicit, with no atomic/alias proof claim.
Current export size is 248620630 bytes. Native make check is due at final goal
confirmation (last whole pass 5236c0e9677f635526fdd515cde5195b2ba0810c).
