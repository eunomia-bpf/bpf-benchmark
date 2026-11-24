import KProgFormal.ClightRefinement.Arm64MemsetInputs
import KProgFormal.ClightRefinement.Arm64PointerWriteFrame

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64MemsetStackInputs

open Arm64MovImmediate

private def register (i : Fin 3) : Fin 31 := ⟨i.val,Nat.lt_of_lt_of_le i.isLt (by decide : 3 ≤ 31)⟩

section Original
variable {initial before pointerWritten markWritten markAfter constantWritten constantAfter : CC.Mem}
    {entry : Arm64Producer.HeaderLocal initial}
    {storage : Arm64ProducerRegisterStorage.Storage initial before entry}
    {raw : BitVec 64} {addresses : Arm64Registers.PointerOrigins}
    {origins : Reference.Provenance.AArch64.Origins} {prior next : Reference.AArch64.State}
    {priorK nextK : CC.Cont} {mark : BitVec 32}
    (pointer : Arm64PointerWrite.Result storage 0 raw (4#8) pointerWritten)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ pointerWritten.nextblock.toNat)
    (first : OrdinaryCall.Result pointer.storage 1 (mark.setWidth 64) addresses origins prior priorK markWritten markAfter)
    (second : OrdinaryCall.Result (first.storage bound) 2 (16#64) addresses origins next nextK constantWritten constantAfter)
include pointer bound first second

/-- R0's actual pointer payload and tag4 survive both complete ordinary MOVs
and the real eight-local memset allocation. No successful read is assumed. -/
theorem gpr :
    Arm64EntryMemory.gpr constantAfter.nextblock (Arm64MemsetSource.allocation constantAfter).2
      (.Vptr entry.block 0) 0 = some (.Vlong raw,.Vint ((4#8).setWidth 32)) := by
  have pointerRead : Arm64EntryMemory.gpr pointerWritten.nextblock pointerWritten (.Vptr entry.block 0) 0 =
      some (.Vlong raw,.Vint ((4#8).setWidth 32)) := by
    simpa only [pointer.nextblock,eq_self,ite_true,Fin.val_zero] using pointer.gpr 0
  have carried := (Arm64MemsetInputs.other second (Arm64MemsetInputs.bound_after first bound) 0 (by decide)).trans
    ((Arm64MemsetInputs.other first bound 0 (by decide)).trans pointerRead)
  exact (Arm64EntryMemory.gpr_frame (Arm64MemsetSource.entry_frame constantAfter) (.Vptr entry.block 0) 0).trans carried

private theorem local_load (id : CC.Ident) (ty : CC.Ty) (block : CC.Block)
    (binding : (Arm64Producer.allocation initial).1.get id = some (block,ty))
    (other : ∀ (i : Fin 3) (tags : Bool),
      Arm64Producer.tableCellName tags (register i) ≠ id)
    (chunk : CC.Chunk) (offset : Int) :
    CC.Mem.load chunk (Arm64MemsetSource.allocation constantAfter).2 block offset =
      CC.Mem.load chunk before block offset := by
  have finalBound := Arm64MemsetInputs.bound_after second (Arm64MemsetInputs.bound_after first bound)
  have owned := Nat.lt_of_lt_of_le (Arm64RegisterStorageFrontier.local_owned initial id ty block binding) finalBound
  exact ((Arm64MemsetSource.entry_frame constantAfter).load chunk block offset owned).trans
    ((second.kept id ty block binding (other 2 false) (other 2 true) chunk offset).trans
      ((first.kept id ty block binding (other 1 false) (other 1 true) chunk offset).trans
        (pointer.local_load id ty block binding (other 0 false) (other 0 true) chunk offset)))

/-- All real tail locals retain their complete source observations: the stack,
payload,24-byte tags, ABI locals and both callback pointers. -/
theorem tail (i : Fin 9) (actual : Arm64Producer.TailLocal initial i) (chunk : CC.Chunk) (offset : Int) :
    CC.Mem.load chunk (Arm64MemsetSource.allocation constantAfter).2 actual.block offset =
      CC.Mem.load chunk before actual.block offset := by
  have different : ∀ (j : Fin 3) (tags : Bool) (i : Fin 9),
      Arm64Producer.tableCellName tags (register j) ≠ Arm64Producer.tailLocalName i := by decide +kernel
  exact local_load pointer bound first second _ _ _ actual.binding (fun j tags => different j tags i) chunk offset

/-- Every actual header slot survives the real pointer/MOV effects and new
callee frame; this includes capacity, bias, stack and stack-tag pointers. -/
theorem header (chunk : CC.Chunk) (offset : Int) :
    CC.Mem.load chunk (Arm64MemsetSource.allocation constantAfter).2 entry.block offset =
      CC.Mem.load chunk before entry.block offset := by
  have different : ∀ (j : Fin 3) (tags : Bool),
      Arm64Producer.tableCellName tags (register j) ≠ Arm64Entry._entry := by decide +kernel
  exact local_load pointer bound first second _ _ _ entry.binding different chunk offset

/-- SP's original pointer and signed-long payload follow the same preserved
producer locals, retaining its exact raw bits through both MOVs and allocation. -/
theorem sp :
    CC.Mem.load CC.Mptr (Arm64MemsetSource.allocation constantAfter).2 entry.block 40 = some (.Vptr storage.sp.block 0) ∧
    CC.Mem.load .Mint64 (Arm64MemsetSource.allocation constantAfter).2 storage.sp.block 0 = some (.Vlong storage.spValue) := by
  have different : ∀ (j : Fin 3) (tags : Bool),
      Arm64Producer.tableCellName tags (register j) ≠ Arm64Producer.headerSourceName 5 := by decide +kernel
  exact ⟨(header pointer bound first second CC.Mptr 40).trans storage.spPointer,
    (local_load pointer bound first second _ _ _ storage.sp.binding different .Mint64 0).trans storage.spRead⟩

end Original
end KProgFormal.ClightRefinement.Arm64MemsetStackInputs
