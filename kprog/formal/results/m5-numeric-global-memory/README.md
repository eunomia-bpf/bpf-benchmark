# M5: initialization of the Numeric-linked world

The existing global allocator proof now accepts its actual Genv and explicit
initializer facts. The same induction derives successful allocation, exact
frontier growth, old-block contents/both-permission framing and indexed access
for arbitrary starting memory. Its byte/function proofs are reused; the old
188-definition producer initialization and public 189-frontier API remain.

`Arm64NumericMemory` checks the actual complete linked program's initializer
facts and uses that allocator to derive `program.initMem = some initialMemory`
and nextblock 204 from its 203 definitions. It retains function Nonempty access
without read/write/free permission, the actual string's 48 read-only bytes at
block 20 and the empty stderr declaration at block 61 with no access. Successful
initialization includes the actual data stores, rather than a function census.
The frontier equation proves this witness differs from the earlier memory.

`producer_entry` transports the actual raw producer's function-entry rule
using only the already proved composite-layout equality. Its one real
allocation transition executes in Numeric.ge for arbitrary context,
continuation and call continuation. Allocation preserves every initial global
byte and both permission maps; each actual local owns its full Freeable range
at a block >=204, distinct from every global, including the 15 appended rows.
No whole Genv/symbol-table or initialized-memory equality is assumed.

This is initialization and function-entry allocation. The actual 98 external
input visits, their provider traces/post-memory and the producer continuation
still need transport. The already entered Callstate is retained as the entry
boundary; a global caller or program execution is not inferred from it.
Physical native memory/alias/origin, relative caches, control and the complete
O1/O2/O4 recount remain M5. Complete ISA-handler/family count remains 0;
M6 and fresh final Lake/make check follow M5.

Validation is recorded in validation.json: focused actual-world proof build,
public type/axiom queries including the preserved old API, one final full
Lake build and direct comparison of all 23 C exports against 9c617740f.
One worker on CPU 17, queries/edits/Git on 18, 32 GiB address space, normal 200000
heartbeats / 512 recursion and every host command under shared timing lock.
C/runtime and frozen benchmark paths remain unchanged. Raw attempts stay at
/workspaces/kprog-raw/formal/m5-numeric-global-memory.

Result: focused 178 jobs, final full Lake 322 jobs, all 14 public queries and
all 23 export comparisons pass. Only standard axioms occur on memory laws;
the internal execution law additionally retains the existing Clight external
function/inline assembly parameters. No new axioms or proof-limit changes.
