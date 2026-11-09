import KProgFormal.NativeLinkSourceRefinement

/-!
Source-derived ordinary-region ownership for the final x86 direct-tail pokes.
The extractor recognizes both complete producer/finalizer bodies, fixed patch
width, descriptor coordinates and the emitting primitive. The model quantifies
all append-only callee-pop and stack-add lengths and arbitrary patch contents.
Its instruction stream follows either native emission or ordinary emission.
Accepted final JIT cursor/label and C/compiler/primitive correspondence are
platform interfaces; ownership follows from the source construction below.
-/
namespace KProgFormal.NativeLinkSourceLayout
open Reference NativeLinkProducerImage NativeLinkSource

structure Tail where
  calleeBytes : Nat
  stackBytes : Nat
  target : List Byte
  bypass : List Byte
  targetLength : target.length = textPatchBytes
  bypassLength : bypass.length = textPatchBytes

inductive Block where
  | ordinary (bytes : Nat)
  | native (bytes : Nat)
  | tail (body : Tail)

/-- Each C switch case emits its own region. The native callback case and the
ordinary tail-call case occupy distinct instruction iterations. -/
def region : Block → Region
  | .ordinary bytes => ⟨bytes,false⟩
  | .native bytes => ⟨bytes,true⟩
  | .tail t => tailRegion t.calleeBytes t.stackBytes

/-- The finalizer's two descriptor destinations in their actual source order. -/
def blockWrites (cursor : Nat) : Block → List Fixup
  | .tail t => tailWrites cursor t.calleeBytes t.stackBytes t.target t.bypass
  | _ => []

/-- The same cursor increments both final layout and patch ownership. -/
def sourceWrites : Nat → List Block → List Fixup
  | _, [] => []
  | cursor, first::rest => blockWrites cursor first ++
      sourceWrites (cursor+(region first).size) rest

theorem tail_write_owned (cursor : Nat) (t : Tail) (write : Fixup)
    (member : write ∈ tailWrites cursor t.calleeBytes t.stackBytes t.target t.bypass) :
    fixupFits ⟨cursor, tailSize t.calleeBytes t.stackBytes, false⟩ write := by
  simp only [tailWrites, List.mem_cons, List.mem_singleton, List.not_mem_nil, or_false] at member
  rcases member with first | second
  · subst write
    dsimp only [fixupFits]
    rw [t.targetLength]
    simp only [tailSize, tailPrefix, textPatchBytes]
    omega
  · subst write
    dsimp only [fixupFits]
    rw [t.bypassLength]
    simp only [tailSize, tailPrefix, textPatchBytes]
    omega

/-- Every finalizer destination obtains its ordinary owner from construction;
caller-supplied write-span ownership has been discharged for these two sites. -/
theorem source_write_owners (cursor : Nat) (blocks : List Block) :
    ∀ write ∈ sourceWrites cursor blocks, ∃ owner ∈ place cursor (blocks.map region),
      owner.native = false ∧ fixupFits owner write := by
  induction blocks generalizing cursor with
  | nil => intro write member; simp [sourceWrites] at member
  | cons first rest ih =>
    intro write member
    simp only [sourceWrites, List.mem_append] at member
    rcases member with current | later
    · cases first with
      | ordinary bytes => simp [blockWrites] at current
      | native bytes => simp [blockWrites] at current
      | tail t =>
        refine ⟨⟨cursor, tailSize t.calleeBytes t.stackBytes, false⟩, ?_, rfl, ?_⟩
        · simp only [List.map_cons, place, region, tailRegion]
          exact List.mem_cons_self
        · exact tail_write_owned cursor t write current
    · obtain ⟨owner, inside, ordinary, bounds⟩ := ih _ write later
      refine ⟨owner, ?_, ordinary, bounds⟩
      simp only [List.map_cons, place]
      exact List.mem_cons_of_mem _ inside

/-- Pack copying followed by all source-constructed final tail fixups preserves
every native chunk, for arbitrary mixed streams, sizes and patch contents. -/
theorem source_final_native (writable final : Image) (blocks : List Block)
    (native : Placed) (member : native ∈ place 0 (blocks.map region))
    (kind : native.native = true) :
    Agree (applyFixups (copy final 0 writable 0 (extent (blocks.map region)))
        (sourceWrites 0 blocks)) writable native.start native.size :=
  finalized_native_image writable final (blocks.map region) native member kind
    (sourceWrites 0 blocks) (source_write_owners 0 blocks)

/-- The generated final-fixup list supplies S5's generic producer-to-executable
composition directly. All remaining premises concern source bytes, layout and
platform embedding, with final tail-write ownership derived above. -/
theorem source_producer_to_final_bytes (resolve : Resolution)
    (source scratch writable final : Image) (chunk : NativeLinkProducer.Chunk)
    (records : List NativeLinkProducer.Record)
    (selected : ∀ r ∈ records, NativeLinkProducer.Selected chunk r)
    (blocks : List Block) (native : Placed)
    (member : native ∈ place 0 (blocks.map region)) (kind : native.native = true)
    (size : native.size = chunk.size) (memory : Memory) (base : Word)
    (embedded : Embeds memory base
      (applyFixups (copy final 0
        (copy writable native.start
          (applyRecords resolve (copy scratch 0 source chunk.start chunk.size)
            (records.map (NativeLinkProducer.localize chunk))) 0 chunk.size)
        0 (extent (blocks.map region))) (sourceWrites 0 blocks)) (extent (blocks.map region))) :
    ∀ i < chunk.size,
      memory.value (base+BitVec.ofNat 64 (native.start+i)) =
        applyRecords resolve source records (chunk.start+i) :=
  producer_to_final_bytes resolve source scratch writable final chunk records selected
    (blocks.map region) native member kind size (sourceWrites 0 blocks)
    (source_write_owners 0 blocks) memory base embedded

end KProgFormal.NativeLinkSourceLayout
