import KProgFormal.ClightRefinement.Arm64CiliumCallerVectorPointerLoopValues

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerVectorPointerLoopMemory
open Arm64CiliumCallerLink (procedure ge allocation)
open Arm64CiliumCallerHeaderSource (Header)
open Arm64CiliumCallerVectorSource (Storage)
open Arm64CiliumCallerVectorPointerLoopSource (pointerType assignment headerOffset slot header_slots)
open Arm64CiliumCallerVectorPointerLoopValues (headerPointerOffset vectorPointerOffset)
open Arm64CiliumCallerGPRFrames (localRead)

private theorem bounds : ∀ (high : Bool) (i : Fin 32),
    96 ≤ headerOffset high i ∧ headerOffset high i+8 ≤ 608 := by decide +kernel
private theorem tail_lower : ∀ j : Fin 16,
    608 ≤ Arm64CiliumCallerHeaderTailSource.offset j := by decide +kernel

structure Store {m : CC.Mem} (header : Header m) (vectors : Storage m)
    (supplied : CC.Mem) (high : Bool) (i : Fin 32) where
  after : CC.Mem
  stored : CC.Mem.store .Mint64 supplied header.block (headerOffset high i)
    (.Vptr vectors.block (vectorPointerOffset high i)) = some after
  read : CC.Mem.load .Mint64 after header.block (headerOffset high i) =
    some (.Vptr vectors.block (vectorPointerOffset high i))
  otherFields : ∀ j : Fin 64,j ≠ slot high i →
    CC.Mem.load .Mint64 after header.block (Arm64CiliumCallerHeaderVectorNullSource.offset j) =
      CC.Mem.load .Mint64 supplied header.block (Arm64CiliumCallerHeaderVectorNullSource.offset j)
  fixedFields : ∀ j : Fin 12,
    CC.Mem.load .Mint64 after header.block (8*(j.val : Int)) =
      CC.Mem.load .Mint64 supplied header.block (8*(j.val : Int))
  tailFields : ∀ j : Fin 16,
    CC.Mem.load (Arm64CiliumCallerHeaderTailSource.chunk j) after header.block
      (Arm64CiliumCallerHeaderTailSource.offset j) =
    CC.Mem.load (Arm64CiliumCallerHeaderTailSource.chunk j) supplied header.block
      (Arm64CiliumCallerHeaderTailSource.offset j)
  otherBlocks : ∀ b,b ≠ header.block → ∀ c o,
    CC.Mem.load c after b o = CC.Mem.load c supplied b o
  frame : FrameBelow m.nextblock supplied after
  access : after.access = supplied.access
  frontier : after.nextblock = supplied.nextblock

/-- The current header rights construct each real vector-storage pointer store. -/
theorem store {m supplied : CC.Mem} (header : Header m) (vectors : Storage m)
    (high : Bool) (i : Fin 32) (access : supplied.access = (allocation m).2.access) :
    Nonempty (Store header vectors supplied high i) := by
  have valid : CC.Mem.validAccess supplied .Mint64 header.block (headerOffset high i) .Writable = true := by
    simp only [CC.Mem.validAccess,Bool.and_eq_true]
    refine ⟨?_,?_⟩
    · apply CC.Mem.rangePerm_intro
      intro o lower upper
      have lo : (96 : Int) ≤ o := by have bound := (bounds high i).1;omega
      have hi : o < (608 : Int) := by
        change o < headerOffset high i+8 at upper
        have bound := (bounds high i).2
        omega
      have permission := CC.Mem.rangePerm_perm _ _ _ _ _ _
        (Arm64CiliumCallerHeaderVectorNullSource.storage header) o lo hi
      simpa only [CC.Mem.perm,access] using permission
    · change ((headerOffset high i) % 8 == 0) = true
      have aligned : headerOffset high i % 8 = 0 := by
        unfold headerOffset
        cases high <;> simp_all <;> omega
      simp only [aligned,beq_self_eq_true]
  obtain ⟨after,stored⟩ : ∃ after,CC.Mem.store .Mint64 supplied header.block
      (headerOffset high i) (.Vptr vectors.block (vectorPointerOffset high i)) = some after := by
    simp only [CC.Mem.store,valid,ite_true]
    exact ⟨_,rfl⟩
  refine ⟨⟨after,stored,CC.Mem.load_store_same stored,?_,?_,?_,
    (fun b different c o => CC.Mem.load_store_other stored c b o (.inl different)),
    FrameBelow.store header.fresh stored,CC.Mem.store_access stored,CC.Mem.store_nextblock stored⟩⟩
  · intro j different
    have ne : j.val ≠ (slot high i).val := fun h => different (Fin.ext h)
    have separate : Arm64CiliumCallerHeaderVectorNullSource.offset j+8 ≤ headerOffset high i ∨
        headerOffset high i+8 ≤ Arm64CiliumCallerHeaderVectorNullSource.offset j := by
      rw [← (header_slots high i).1]
      unfold Arm64CiliumCallerHeaderVectorNullSource.offset
      omega
    exact CC.Mem.load_store_other stored .Mint64 header.block _ (.inr separate)
  · intro j
    have bound := j.isLt
    have separate : 8*(j.val : Int)+8 ≤ headerOffset high i := by
      have lower := (bounds high i).1
      omega
    exact CC.Mem.load_store_other stored .Mint64 header.block _ (.inr (.inl separate))
  · intro j
    have separate : headerOffset high i+8 ≤ Arm64CiliumCallerHeaderTailSource.offset j := by
      have upper := (bounds high i).2
      have lower := tail_lower j
      omega
    exact CC.Mem.load_store_other stored (Arm64CiliumCallerHeaderTailSource.chunk j)
      header.block _ (.inr (.inr separate))

/-- A genuine assignment step consumes the SAME store, dynamic lvalue and RHS address. -/
theorem assign {m before : CC.Mem} (header : Header m) (vectors : Storage m)
    (high : Bool) (i : Fin 32) (access : before.access = (allocation m).2.access)
    (le : CC.TempEnv) (k : CC.Cont)
    (indexFound : le.get Arm64CiliumCallerUnit._i = some (.Vint (CC.Integers.Int.repr i.val))) :
    ∃ writes : Store header vectors before high i,
      InternalRun ge 1 (.State procedure (assignment high) k (allocation m).1 le before)
        (.State procedure .Sskip k (allocation m).1 le writes.after) := by
  obtain ⟨writes⟩ := store header vectors high i access
  have assigned : CC.doAssignLoc ge.genv_cenv pointerType before
      header.block (headerPointerOffset high i) .Full
      (.Vptr vectors.block (vectorPointerOffset high i)) = some writes.after := by
    simpa only [CC.doAssignLoc,
      (Arm64CiliumCallerVectorPointerLoopValues.assignment before high vectors.block
        (vectorPointerOffset high i)).1,
      CC.Mem.storev,(Arm64CiliumCallerVectorPointerLoopValues.offsets high i).1] using writes.stored
  have step : CC.Step2 ge (.State procedure (assignment high) k (allocation m).1 le before) CC.E0
      (.State procedure .Sskip k (allocation m).1 le writes.after) := by
    apply CC.Step.assign
    · exact CC.doEvalLvalue_sound _ _ _ _ _ _ _ _
        (Arm64CiliumCallerVectorPointerLoopValues.target_locations header le before high i indexFound)
    · exact CC.doEvalExpr_sound _ _ _ _ _ _
        (Arm64CiliumCallerVectorPointerLoopValues.source_values vectors le before high i indexFound)
    · exact (Arm64CiliumCallerVectorPointerLoopValues.assignment before high vectors.block
        (vectorPointerOffset high i)).2
    · exact CC.doAssignLoc_sound _ _ _ _ _ _ _ _ assigned
  have internal : InternalState (.State procedure (assignment high) k (allocation m).1 le before) := by
    unfold assignment;trivial
  exact ⟨writes,.step internal step (.refl _)⟩

theorem named_frame {m before : CC.Mem} {header : Header m} {vectors : Storage m}
    {high : Bool} {i : Fin 32} (writes : Store header vectors before high i)
    (id : CC.Ident) (different : id ≠ Arm64CiliumCallerUnit.___a64_entry)
    (c : CC.Chunk) (o : Int) :
    localRead m writes.after id c o = localRead m before id c o :=
  Arm64CiliumCallerHeaderEntry.local_frame header writes.otherBlocks id different c o

end KProgFormal.ClightRefinement.Arm64CiliumCallerVectorPointerLoopMemory
