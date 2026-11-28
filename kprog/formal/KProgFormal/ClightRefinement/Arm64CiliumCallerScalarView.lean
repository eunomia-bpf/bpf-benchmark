import KProgFormal.ClightRefinement.Arm64CiliumCallerGPRView

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerScalarView
open Arm64CiliumCallerHeaderSource (Header Sources)
open Arm64CiliumCallerGPRFrames (localRead)
open Arm64Producer (flagWord)
open Arm64ProducerEntryView (flagIndex flagValues)

theorem field_names : ∀ i : Fin 12,
    (Arm64CiliumCallerHeaderSource.declaration i).field = Arm64Producer.headerField i := by
  decide +kernel

/-- Actual header pointer and actual pointee load feed the existing borrowed reader. -/
theorem borrowed_readback {m memory : CC.Mem} (header : Header m) (sources : Sources m)
    (i : Fin 12) (chunk : CC.Chunk) (value : CC.Val)
    (pointers : Arm64CiliumCallerHeaderSequence.Initialized header sources memory 12)
    (read : CC.Mem.load chunk memory (sources.block i) 0 = some value) :
    Arm64EntryMemory.borrowed memory.nextblock chunk memory (.Vptr header.block 0)
      (Arm64CiliumCallerHeaderSource.declaration i).field = some value := by
  rw [field_names i]
  apply Arm64ProducerEntryView.header_borrowed_readback memory header.block i chunk
    (sources.block i) 0 value
  · simpa [CC.Mptr,CC.Archi.ptr64] using pointers i i.isLt
  · exact read

private theorem flag_names : ∀ i : Fin 4,
    (Arm64CiliumCallerHeaderSource.declaration (flagIndex i)).sourceName =
      (Arm64CiliumCallerFlags.declaration i).name := by decide +kernel

private theorem flag_cells {m memory : CC.Mem} (sources : Sources m)
    (inputs : Fin 4 → BitVec 64)
    (current : Arm64CiliumCallerFlagSequence.Initialized m memory inputs 4) :
    ∀ i : Fin 4,CC.Mem.load .Mint8unsigned memory (sources.block (flagIndex i)) 0 =
      some (.Vint (flagWord (inputs i))) := by
  intro i
  have read := current i i.isLt
  rw [← flag_names i] at read
  simpa only [localRead,sources.binding (flagIndex i),Option.bind_some] using read

/-- The original arbitrary provider bytes remain the actual unsigned scalar views. -/
theorem flags_readbacks {m memory : CC.Mem} (header : Header m) (sources : Sources m)
    (inputs : Fin 4 → BitVec 64)
    (pointers : Arm64CiliumCallerHeaderSequence.Initialized header sources memory 12)
    (current : Arm64CiliumCallerFlagSequence.Initialized m memory inputs 4) :
    Arm64EntryMemory.flags memory.nextblock memory (.Vptr header.block 0) =
      some (.Vint (flagWord (inputs 0)),.Vint (flagWord (inputs 1)),
        .Vint (flagWord (inputs 2)),.Vint (flagWord (inputs 3))) := by
  apply Arm64ProducerEntryView.flags_readback memory header.block sources.block
    (fun i => .Vint (flagWord (inputs i)))
  · intro i
    simpa [CC.Mptr,CC.Archi.ptr64] using pointers i i.isLt
  · exact flag_cells sources inputs current

/-- One-bit native flag correspondence is explicit, not assumed for arbitrary bytes. -/
theorem native_flags {m memory : CC.Mem} (header : Header m) (sources : Sources m)
    (inputs : Fin 4 → BitVec 64)
    (pointers : Arm64CiliumCallerHeaderSequence.Initialized header sources memory 12)
    (current : Arm64CiliumCallerFlagSequence.Initialized m memory inputs 4)
    (s : Reference.AArch64.State)
    (matching : ∀ i : Fin 4,CC.Val.Vint (flagWord (inputs i)) = flagValues s i) :
    Arm64Nop.FlagsRepresent memory.nextblock memory (.Vptr header.block 0) s := by
  apply Arm64ProducerEntryView.header_flags_represent memory header.block sources.block s
  · intro i
    simpa [CC.Mptr,CC.Archi.ptr64] using pointers i i.isLt
  · intro i
    have read := flag_cells sources inputs current i
    simpa only [matching i] using read

end KProgFormal.ClightRefinement.Arm64CiliumCallerScalarView
