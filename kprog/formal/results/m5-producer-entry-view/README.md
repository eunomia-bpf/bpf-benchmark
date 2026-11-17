# Producer header to borrowed-entry flag reads

`Arm64ProducerEntryView.lean` connects actual producer memory readbacks to
the existing C-layout readers. A successful imported Mem.load derives the
block bound required by Arm64EntryMemory.load from the memory's own
invariants. The reader frontier is the reached memory's nextblock. There is
no assumed successful checked read or caller-supplied live-block bound.

The first twelve scalar pointer fields use the imported consumer composite
and Ctypes.fieldOffset. Actual pointer-slot and pointee loads establish the
borrowed reads. n/z/c/v use indices 8/9/10/11 and offsets 64/72/80/88. Their
four real byte reads establish FlagsRepresent with the existing native
one-bit flag values.

The actual 638-transition producer header/loop theorem now establishes that
relation at its reached entry. It transports the flag-cell reads through
proved preservation of the other locals and retains caller framing, the
access map and nextblock. The precise pre-header flag-value premise is tied
to real allocation bindings. Connecting it to native provider outcomes is
still an admissibility obligation; arbitrary eight-bit inputs are not
silently converted to one-bit flags. A compiled query checks that byte2
cannot equal the native N-flag value.

The bridge constructs no continuation body or source-to-NOP control edge.
GPR/SP/vector source views, native origins/cell maps/provider admissibility,
architectural memory/events/faults/control and full handler migration/recount
remain M5, followed by remaining M6. Complete ISA-handler count remains zero.
Production C, generated exports and frozen benchmark paths stay unchanged.

Focused Lake passes 163 jobs. Six public type/axiom queries and three source
queries pass, including the actual linked execution world. The five reader
facts use only propext, Classical.choice and Quot.sound; the producer-run
statement also mentions imported CC.externalFunctionsSem/CC.inlineAssemblySem.
No new semantic/native-reflection axiom or raised proof budget is introduced.
Full Lake passes 290 jobs; all 23 exports (243488732 bytes) remain byte-identical
to 9c617740f. Raw retains all local failed elaboration attempts and both
successful pre/post-reduction query versions.

From kprog/formal, run each command under timing SH, CPU17 or18,
`ulimit -v 33554432`, LEAN_NUM_THREADS=1 and default200000heartbeats/512recDepth:

```
lake build KProgFormal.ClightRefinement.Arm64ProducerEntryView
lake env lean -j1 results/m5-producer-entry-view/Query.lean
lake env lean -j1 results/m5-producer-entry-view/Next.lean
lake build
python3 results/clight-build/compare.py 9c617740f
```

Raw: /workspaces/kprog-raw/formal/m5-producer-entry-view. Native make check last
passed at 5236c0e96; it was not repeated for this Lean-only step. Fresh full
Lake and make check remain required at actual M5/M6 completion.
