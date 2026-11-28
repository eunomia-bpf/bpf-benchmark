import KProgFormal.ClightRefinement.Arm64CiliumCallerHeaderSource

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerHeaderMemory
open Arm64CiliumCallerLink (procedure ge allocation)
open Arm64CiliumCallerHeaderSource (Header Sources declaration lhs rhs row pointerOffset)
open Arm64CiliumCallerGPRFrames (localRead)

structure Store {m : CC.Mem} (header : Header m) (sources : Sources m)
    (supplied : CC.Mem) (i : Fin 12) where
  after : CC.Mem
  stored : CC.Mem.store .Mint64 supplied header.block (8*(i.val : Int))
    (.Vptr (sources.block i) 0) = some after
  read : CC.Mem.load .Mint64 after header.block (8*(i.val : Int)) =
    some (.Vptr (sources.block i) 0)
  otherFields : ∀ j : Fin 12,j ≠ i →
    CC.Mem.load .Mint64 after header.block (8*(j.val : Int)) =
      CC.Mem.load .Mint64 supplied header.block (8*(j.val : Int))
  otherBlocks : ∀ b,b ≠ header.block → ∀ c o,
    CC.Mem.load c after b o = CC.Mem.load c supplied b o
  frame : FrameBelow m.nextblock supplied after
  access : after.access = supplied.access
  frontier : after.nextblock = supplied.nextblock

/-- Current rights on the actual header derive each real pointer store. -/
theorem store {m supplied : CC.Mem} (header : Header m) (sources : Sources m) (i : Fin 12)
    (access : supplied.access = (allocation m).2.access) :
    Nonempty (Store header sources supplied i) := by
  have valid : CC.Mem.validAccess supplied .Mint64 header.block (8*(i.val : Int)) .Writable = true := by
    simp only [CC.Mem.validAccess,Bool.and_eq_true]
    refine ⟨?_,?_⟩
    · apply CC.Mem.rangePerm_intro
      intro o lower upper
      have bound := i.isLt
      have lo : (0 : Int) ≤ o := by omega
      have hi : o < (96 : Int) := by
        change o < 8*(i.val : Int)+8 at upper
        omega
      have permission := CC.Mem.rangePerm_perm _ _ _ _ _ _ header.writable o lo hi
      simpa only [CC.Mem.perm,access] using permission
    · change ((8*(i.val : Int)) % 8 == 0) = true
      have aligned : (8*(i.val : Int)) % 8 = 0 := by omega
      simp only [aligned,beq_self_eq_true]
  obtain ⟨after,stored⟩ : ∃ after,CC.Mem.store .Mint64 supplied header.block
      (8*(i.val : Int)) (.Vptr (sources.block i) 0) = some after := by
    simp only [CC.Mem.store,valid,ite_true]
    exact ⟨_,rfl⟩
  have read := CC.Mem.load_store_same stored
  have result : CC.Val.loadResult .Mint64 (.Vptr (sources.block i) 0) =
      .Vptr (sources.block i) 0 := rfl
  rw [result] at read
  refine ⟨⟨after,stored,read,?_,
    (fun b different c o => CC.Mem.load_store_other stored c b o (.inl different)),
    FrameBelow.store header.fresh stored,CC.Mem.store_access stored,CC.Mem.store_nextblock stored⟩⟩
  intro j different
  have ne : j.val ≠ i.val := fun h => different (Fin.ext h)
  have separate : 8*(j.val : Int)+8 ≤ 8*(i.val : Int) ∨
      8*(i.val : Int)+8 ≤ 8*(j.val : Int) := by omega
  exact CC.Mem.load_store_other stored .Mint64 header.block (8*(j.val : Int)) (.inr separate)

/-- Execute the original sequence/assignment/skip visit with that SAME store. -/
theorem visit {m before : CC.Mem} (header : Header m) (sources : Sources m) (i : Fin 12)
    (access : before.access = (allocation m).2.access)
    (le : CC.TempEnv) (k : CC.Cont) (rest : CC.Stmt) :
    ∃ writes : Store header sources before i,
      InternalRun ge 3 (.State procedure (.Ssequence (row i) rest) k (allocation m).1 le before)
        (.State procedure rest k (allocation m).1 le writes.after) := by
  obtain ⟨writes⟩ := store header sources i access
  have assigned : CC.doAssignLoc ge.genv_cenv (declaration i).ty before
      header.block (pointerOffset i) .Full (.Vptr (sources.block i) 0) = some writes.after := by
    simpa only [CC.doAssignLoc,(Arm64CiliumCallerHeaderSource.modes (sources.block i) before i).1,
      CC.Mem.storev,Arm64CiliumCallerHeaderSource.offsets] using writes.stored
  have step : CC.Step2 ge (.State procedure (row i) (.Kseq rest k) (allocation m).1 le before) CC.E0
      (.State procedure .Sskip (.Kseq rest k) (allocation m).1 le writes.after) := by
    apply CC.Step.assign
    · exact CC.doEvalLvalue_sound _ _ _ _ _ _ _ _
        (Arm64CiliumCallerHeaderSource.target_locations header le before i)
    · exact CC.doEvalExpr_sound _ _ _ _ _ _
        (Arm64CiliumCallerHeaderSource.source_values sources le before i)
    · exact (Arm64CiliumCallerHeaderSource.modes (sources.block i) before i).2
    · exact CC.doAssignLoc_sound _ _ _ _ _ _ _ _ assigned
  have internal : InternalState (.State procedure (row i) (.Kseq rest k) (allocation m).1 le before) := by
    unfold row;trivial
  refine ⟨writes,?_⟩
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl)
    (.step internal step (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)))

/-- The original allocation's distinct names frame every other local. -/
theorem named_frame {m before : CC.Mem} {header : Header m} {sources : Sources m} {i : Fin 12}
    (writes : Store header sources before i) (id : CC.Ident)
    (different : id ≠ Arm64CiliumCallerUnit.___a64_entry) (c : CC.Chunk) (o : Int) :
    localRead m writes.after id c o = localRead m before id c o := by
  cases binding : (allocation m).1.get id with
  | none => simp only [localRead,binding,Option.bind_none]
  | some cell =>
    have separate := (allocated_local_storage (Arm64CiliumCallerLink.allocated m)).2
      _ _ _ _ binding header.binding different
    simpa only [localRead,binding,Option.bind_some] using writes.otherBlocks cell.1 separate c o

end KProgFormal.ClightRefinement.Arm64CiliumCallerHeaderMemory
