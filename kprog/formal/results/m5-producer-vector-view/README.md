# Producer vector pointers to borrowed-entry reads

`Arm64ProducerVectorView.lean` follows the existing vector reader through its
two embedded pointer arrays and the low/high pointee loads. The array fields
have bases 96/352 and eight-byte pointer slots. The actual producer buffer has
32 elements of 16 bytes, with low/high data at offsets 0/8 in each element.
Successful imported loads discharge the reader's bounds at the reached
memory's nextblock.

The generic reader theorem retains independently supplied low/high pointer
blocks, offsets and values. The source specialization uses actual HeaderLocal
and VectorLocal resources and the pointer arrays produced by the real loop.
The native half projections use Reference.AArch64.readVector directly.

The actual 638-transition header/loop execution now establishes all 32 native
low/high pairs, transporting vector-buffer data through proved other-local
preservation. Caller bytes, both permission maps, access and nextblock remain
framed. The pre-header data premise is tied to the actual ___a64_vectors
allocation binding. Correspondence with native provider inputs remains open.
This does not construct a continuation body or an architectural memory/control
relation. The joint register source relation, physical origins/cell maps,
provider/LR/SP admissibility, memory/events/faults/control and complete handler
migration/recount remain M5, then remaining M6. Complete ISA-handler count0.

Focused Lake passes 165 jobs. Three public type/axiom queries and three source
queries pass: actual embedded-array types and producer layout, last-lane
pointer slots 344/600 and data offsets 496/504 with storage bounds, and explicit
linked-world execution/readbacks. Two reader facts use only
propext/Classical.choice/Quot.sound; producer_vectors_initialized additionally
mentions imported CC.externalFunctionsSem/CC.inlineAssemblySem. Full Lake
passes 292 jobs; all 23 exports (243488732 bytes) remain byte-identical to
9c617740f. All attempts pass on their first run at unchanged proof limits.

From kprog/formal, run each command under timing SH, CPU17 or18,
`ulimit -v 33554432`, LEAN_NUM_THREADS=1 and default200000heartbeats/512recDepth:

```
lake build KProgFormal.ClightRefinement.Arm64ProducerVectorView
lake env lean -j1 results/m5-producer-vector-view/Query.lean
lake env lean -j1 results/m5-producer-vector-view/Next.lean
lake build
python3 results/clight-build/compare.py 9c617740f
```

Raw: /workspaces/kprog-raw/formal/m5-producer-vector-view. Production C, exports
and frozen benchmark paths stay unchanged. Last native make check passed at
5236c0e96, not repeated for this Lean-only change; fresh full Lake and make
check remain required at actual M5/M6 completion.
