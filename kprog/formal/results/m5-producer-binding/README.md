# Linking the actual entry and handler exports

`Arm64LinkedProgram.lean` uses Clean's `CC.Link.linkProgram` on the complete
Arm64Program and Arm64Entry exports. The cached output is checked against that
linker by a closed kernel reflexivity certificate. Ordinary declaration kernel
checking remains enabled; no native reflection or semantic axiom is added.
The imported linker checks shared declarations and rebuilds the composite
environment. Explicit well-formedness proves its empty-environment fallback
is not used for these actual sources.

The original 183 program globals retain their exact definitions, function
lookups and symbol bindings. Five actual Entry functions are appended:
payload load/store at blocks 184/185, raw/XDP/SKB producers at 186/187/188.
The native-input declaration remains at block 64. Standalone Entry's input 58
and callback 59/60 values therefore cannot be transplanted into this environment.

All nine Program and fourteen Entry composite layouts are preserved, including
anonymous vector/stack types. Every producer local retains its actual size and
alignment. The linked producer allocates exactly the same environment, blocks
and memory for arbitrary caller memory; a real one-transition FunctionEntry2
witness now runs in the same global environment as the handlers. No copied
register bank or assumed successful allocation is introduced.

The next step migrates the earlier initialization witnesses onto this linked
environment and updates their input/callback bindings. Provider/Senv/native
origin correspondence and the genuine continuation body remain obligations.
The next query checks the combined global count/frontier and the continuation
ABI gap. No continuation, external or assembly body executes here. This is
source/environment binding, with complete ISA-handler refinement count zero;
M5 and remaining M6 stay open, including O1/O2/O4 recount.

Focused Lake passes 161 jobs; all fifteen public type/axiom queries pass.
The follow-up query proves 188 globals, frontier 189, and no exact continuation
signature among these exports. Full Lake passes 287 jobs with zero failures;
all 23 exports remain byte-identical to 9c617740f, 243488732 bytes. Source/layout/
binding facts use the three standard axioms; the internal entry run also
mentions the imported opaque external and assembly relations.
Checks use timing SH, CPU 17/18, one worker and 32 GiB address space, at default
200000 heartbeats and 512 recursion depth. Large closed equalities are checked
by kernel reflexivity, while selective unfolding keeps other reduction bounded.
Earlier failed attempts remain in raw.

Reproduce from kprog/formal with those bounds:

```
flock -s /workspaces/.agent-state/kprog-lanes/locks/timing env LEAN_NUM_THREADS=1 lake build KProgFormal.ClightRefinement.Arm64LinkedProgram
flock -s /workspaces/.agent-state/kprog-lanes/locks/timing env LEAN_NUM_THREADS=1 lake env lean -j1 results/m5-producer-binding/Query.lean
flock -s /workspaces/.agent-state/kprog-lanes/locks/timing env LEAN_NUM_THREADS=1 lake env lean -j1 results/m5-producer-binding/Next.lean
flock -s /workspaces/.agent-state/kprog-lanes/locks/timing env LEAN_NUM_THREADS=1 lake build
```

Raw: /workspaces/kprog-raw/formal/m5-producer-binding. Production C, pinned
submodules, generated exports and frozen benchmark paths stay unchanged. Last
full native make check remains PASS at 5236c0e96, not repeated for Lean-only
proof changes.

Continuation: [the unified producer migration](../m5-unified-producer/README.md)
moves the linked foundation below Producer, so its existing initialization and
lifetime witnesses use the linked environment. Query/Next imports and parent
entry names follow that route; the validation counts above retain this earlier
binding checkpoint.
