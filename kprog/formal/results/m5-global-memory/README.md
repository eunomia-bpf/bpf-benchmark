# Actual linked global memory

`Arm64GlobalMemory.lean` derives successful `Binding.program.initMem` from
Clean's actual allocator, zero filling, initializer stores and permission drop.
It constructs the memory rather than assuming successful initialization. Its
next block is 189. The actual source census is 186 functions and two data
globals: a 48-byte read-only string at block 20 and a zero-sized `stderr`
declaration at block 61. The earlier state handoff's “all functions” plan was
wrong; the first focused check exposed it, and this proof covers the data.

Every definition has its exact final access map for both Cur and Max. Function
blocks have Nonempty at offset zero, with no read/write/free permission. The
string is Readable exactly on [0,48); `stderr` has no accessible bytes. The
proof follows the real initializer sequence, including all 48 string bytes;
it does not replace the string with an assumed successful or function-only
allocation. The chosen memory is proved to equal the actual initMem result.

Actual producer allocation preserves every initial global byte and both
permission maps. Each declared local has its complete Freeable range starting
at or after 189, and cannot alias a global. This establishes initial-memory
and frame resources, not native provider outcomes or physical addresses.
Concrete native origins/admissibility, the continuation body, the remaining
architectural representation, events/faults/control, XDP/SKB and complete
handler refinements/recount remain M5. M6 follows M5; complete ISA-handler
refinement count remains zero. Production C and frozen benchmark paths stay
unchanged.

Focused Lake passes 146 jobs. Nine compiled type/axiom queries use only
propext, Classical.choice and Quot.sound. Source/resource queries check the
186/2 census, actual function blocks 64/184/185/186/188, both permission kinds,
string offsets -1/47/48, empty stderr and real entry-local allocation. Full
Lake passes 288 jobs, with all 23 exports (243488732 bytes) byte-identical to
9c617740f. The initial failed function-only census and all local elaboration
failures remain in raw. No proof limits were raised.

From kprog/formal, run each command under timing SH with taskset CPU 17 or 18,
`ulimit -v 33554432`, LEAN_NUM_THREADS=1 and the default proof budgets:

```
lake build KProgFormal.ClightRefinement.Arm64GlobalMemory
lake env lean -j1 results/m5-global-memory/Query.lean
lake env lean -j1 results/m5-global-memory/Next.lean
lake build
python3 results/clight-build/compare.py 9c617740f
```

Raw: /workspaces/kprog-raw/formal/m5-global-memory. Last full native make check
remains PASS at 5236c0e96; it was not repeated for Lean-only work. Fresh full
Lake and make check are still required for actual M5/M6 completion.
