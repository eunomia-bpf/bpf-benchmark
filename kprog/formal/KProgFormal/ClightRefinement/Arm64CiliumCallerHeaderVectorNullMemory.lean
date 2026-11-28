import KProgFormal.ClightRefinement.Arm64CiliumCallerHeaderVectorNullSource

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerHeaderVectorNullMemory
open Arm64CiliumCallerLink (procedure ge allocation)
open Arm64CiliumCallerHeaderSource (Header)
open Arm64CiliumCallerHeaderVectorNullSource (pointerType lhs rhs row pointerOffset offset)
open Arm64CiliumCallerGPRFrames (localRead)

structure Store {m : CC.Mem} (header : Header m) (supplied : CC.Mem) (i : Fin 64) where
  after : CC.Mem
  stored : CC.Mem.store .Mint64 supplied header.block (offset i) (.Vlong (0#64)) = some after
  read : CC.Mem.load .Mint64 after header.block (offset i) = some (.Vlong (0#64))
  otherFields : ∀ j : Fin 64,j ≠ i →
    CC.Mem.load .Mint64 after header.block (offset j) =
      CC.Mem.load .Mint64 supplied header.block (offset j)
  fixedFields : ∀ j : Fin 12,
    CC.Mem.load .Mint64 after header.block (8*(j.val : Int)) =
      CC.Mem.load .Mint64 supplied header.block (8*(j.val : Int))
  otherBlocks : ∀ b,b ≠ header.block → ∀ c o,
    CC.Mem.load c after b o = CC.Mem.load c supplied b o
  frame : FrameBelow m.nextblock supplied after
  access : after.access = supplied.access
  frontier : after.nextblock = supplied.nextblock

/-- Actual vector-array rights derive each original NULL store in the SAME header. -/
theorem store {m supplied : CC.Mem} (header : Header m) (i : Fin 64)
    (access : supplied.access = (allocation m).2.access) :
    Nonempty (Store header supplied i) := by
  have valid : CC.Mem.validAccess supplied .Mint64 header.block (offset i) .Writable = true := by
    simp only [CC.Mem.validAccess,Bool.and_eq_true]
    refine ⟨?_,?_⟩
    · apply CC.Mem.rangePerm_intro
      intro o lower upper
      have bound := i.isLt
      have lo : (96 : Int) ≤ o := by
        change 96+8*(i.val : Int) ≤ o at lower
        omega
      have hi : o < (608 : Int) := by
        change o < (96+8*(i.val : Int))+8 at upper
        omega
      have permission := CC.Mem.rangePerm_perm _ _ _ _ _ _
        (Arm64CiliumCallerHeaderVectorNullSource.storage header) o lo hi
      simpa only [CC.Mem.perm,access] using permission
    · change ((96+8*(i.val : Int)) % 8 == 0) = true
      have aligned : (96+8*(i.val : Int)) % 8 = 0 := by omega
      simp only [aligned,beq_self_eq_true]
  obtain ⟨after,stored⟩ : ∃ after,CC.Mem.store .Mint64 supplied header.block
      (offset i) (.Vlong (0#64)) = some after := by
    simp only [CC.Mem.store,valid,ite_true]
    exact ⟨_,rfl⟩
  refine ⟨⟨after,stored,CC.Mem.load_store_same stored,?_,?_,
    (fun b different c o => CC.Mem.load_store_other stored c b o (.inl different)),
    FrameBelow.store header.fresh stored,CC.Mem.store_access stored,CC.Mem.store_nextblock stored⟩⟩
  · intro j different
    have ne : j.val ≠ i.val := fun h => different (Fin.ext h)
    have separate : offset j+8 ≤ offset i ∨ offset i+8 ≤ offset j := by
      unfold offset
      omega
    exact CC.Mem.load_store_other stored .Mint64 header.block (offset j) (.inr separate)
  · intro j
    have bound := j.isLt
    have separate : 8*(j.val : Int)+8 ≤ offset i := by
      unfold offset
      omega
    exact CC.Mem.load_store_other stored .Mint64 header.block (8*(j.val : Int)) (.inr (.inl separate))

/-- The original sequence/assign/skip visit consumes that SAME genuine NULL store. -/
theorem visit {m before : CC.Mem} (header : Header m) (i : Fin 64)
    (access : before.access = (allocation m).2.access)
    (le : CC.TempEnv) (k : CC.Cont) (rest : CC.Stmt) :
    ∃ writes : Store header before i,
      InternalRun ge 3 (.State procedure (.Ssequence (row i) rest) k (allocation m).1 le before)
        (.State procedure rest k (allocation m).1 le writes.after) := by
  obtain ⟨writes⟩ := store header i access
  have assigned : CC.doAssignLoc ge.genv_cenv pointerType before
      header.block (pointerOffset i) .Full (.Vlong (0#64)) = some writes.after := by
    simpa only [CC.doAssignLoc,(Arm64CiliumCallerHeaderVectorNullSource.assignment before).1,
      CC.Mem.storev,Arm64CiliumCallerHeaderVectorNullSource.offsets] using writes.stored
  have step : CC.Step2 ge (.State procedure (row i) (.Kseq rest k) (allocation m).1 le before) CC.E0
      (.State procedure .Sskip (.Kseq rest k) (allocation m).1 le writes.after) := by
    apply CC.Step.assign
    · exact CC.doEvalLvalue_sound _ _ _ _ _ _ _ _
        (Arm64CiliumCallerHeaderVectorNullSource.target_locations header le before i)
    · exact CC.doEvalExpr_sound _ _ _ _ _ _
        (Arm64CiliumCallerHeaderVectorNullSource.rhs_value before (allocation m).1 le)
    · exact (Arm64CiliumCallerHeaderVectorNullSource.assignment before).2
    · exact CC.doAssignLoc_sound _ _ _ _ _ _ _ _ assigned
  have internal : InternalState (.State procedure (row i) (.Kseq rest k) (allocation m).1 le before) := by
    unfold row;trivial
  refine ⟨writes,?_⟩
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl)
    (.step internal step (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)))

theorem named_frame {m before : CC.Mem} {header : Header m} {i : Fin 64}
    (writes : Store header before i) (id : CC.Ident)
    (different : id ≠ Arm64CiliumCallerUnit.___a64_entry) (c : CC.Chunk) (o : Int) :
    localRead m writes.after id c o = localRead m before id c o := by
  cases binding : (allocation m).1.get id with
  | none => simp only [localRead,binding,Option.bind_none]
  | some cell =>
    have separate := (allocated_local_storage (Arm64CiliumCallerLink.allocated m)).2
      _ _ _ _ binding header.binding different
    simpa only [localRead,binding,Option.bind_some] using writes.otherBlocks cell.1 separate c o

end KProgFormal.ClightRefinement.Arm64CiliumCallerHeaderVectorNullMemory
