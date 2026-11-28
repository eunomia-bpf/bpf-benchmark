import KProgFormal.ClightRefinement.Arm64CiliumCallerHeaderTailValues

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerHeaderTailMemory
open Arm64CiliumCallerLink (procedure ge allocation)
open Arm64CiliumCallerHeaderSource (Header)
open Arm64CiliumCallerHeaderTailSource (site lhs rhs row chunk offset pointerOffset)
open Arm64CiliumCallerHeaderTailValues (Storage prevalue value)
open Arm64CiliumCallerGPRFrames (localRead)

private theorem bounds : ∀ i : Fin 16,
    608 ≤ offset i ∧ offset i+CC.sizeChunk (chunk i) ≤ 728 ∧
    offset i % CC.alignChunk (chunk i) = 0 := by decide +kernel
private theorem disjoint : ∀ i j : Fin 16,j ≠ i →
    offset j+CC.sizeChunk (chunk j) ≤ offset i ∨
      offset i+CC.sizeChunk (chunk i) ≤ offset j := by decide +kernel
private theorem old_disjoint : ∀ (i : Fin 16) (j : Fin 76),
    8*(j.val : Int)+8 ≤ offset i := by decide +kernel

structure Store {m : CC.Mem} (header : Header m) (resource : Storage m)
    (supplied : CC.Mem) (i : Fin 16) where
  after : CC.Mem
  stored : CC.Mem.store (chunk i) supplied header.block (offset i) (value resource i) = some after
  read : CC.Mem.load (chunk i) after header.block (offset i) = some (value resource i)
  otherFields : ∀ j : Fin 16,j ≠ i →
    CC.Mem.load (chunk j) after header.block (offset j) =
      CC.Mem.load (chunk j) supplied header.block (offset j)
  oldFields : ∀ j : Fin 76,
    CC.Mem.load .Mint64 after header.block (8*(j.val : Int)) =
      CC.Mem.load .Mint64 supplied header.block (8*(j.val : Int))
  otherBlocks : ∀ b,b ≠ header.block → ∀ c o,
    CC.Mem.load c after b o = CC.Mem.load c supplied b o
  frame : FrameBelow m.nextblock supplied after
  access : after.access = supplied.access
  frontier : after.nextblock = supplied.nextblock

/-- Current rights derive the actual mixed-width store and all same-header frames. -/
theorem store {m supplied : CC.Mem} (header : Header m) (resource : Storage m) (i : Fin 16)
    (access : supplied.access = (allocation m).2.access) :
    Nonempty (Store header resource supplied i) := by
  have valid : CC.Mem.validAccess supplied (chunk i) header.block (offset i) .Writable = true := by
    simp only [CC.Mem.validAccess,Bool.and_eq_true]
    refine ⟨?_,?_⟩
    · apply CC.Mem.rangePerm_intro
      intro o lower upper
      have lo : (608 : Int) ≤ o := by
        have bound : (608 : Int) ≤ offset i := (bounds i).1
        omega
      have hi : o < (728 : Int) := by
        have bound : offset i+CC.sizeChunk (chunk i) ≤ (728 : Int) := (bounds i).2.1
        omega
      have permission := CC.Mem.rangePerm_perm _ _ _ _ _ _
        (Arm64CiliumCallerHeaderTailSource.storage header) o lo hi
      simpa only [CC.Mem.perm,access] using permission
    · simp only [(bounds i).2.2,beq_self_eq_true]
  obtain ⟨after,stored⟩ : ∃ after,CC.Mem.store (chunk i) supplied header.block
      (offset i) (value resource i) = some after := by
    simp only [CC.Mem.store,valid,ite_true]
    exact ⟨_,rfl⟩
  have read := CC.Mem.load_store_same stored
  rw [(Arm64CiliumCallerHeaderTailValues.casts resource supplied i).2] at read
  exact ⟨⟨after,stored,read,
    (fun j different => CC.Mem.load_store_other stored (chunk j) header.block (offset j)
      (.inr (disjoint i j different))),
    (fun j => CC.Mem.load_store_other stored .Mint64 header.block (8*(j.val : Int))
      (.inr (.inl (old_disjoint i j)))),
    (fun b different c o => CC.Mem.load_store_other stored c b o (.inl different)),
    FrameBelow.store header.fresh stored,CC.Mem.store_access stored,CC.Mem.store_nextblock stored⟩⟩

/-- Original sequence/assign/skip consumes that SAME typed store and RHS value. -/
theorem visit {m before : CC.Mem} (header : Header m) (resource : Storage m) (i : Fin 16)
    (access : before.access = (allocation m).2.access)
    (le : CC.TempEnv) (k : CC.Cont) (rest : CC.Stmt) :
    ∃ writes : Store header resource before i,
      InternalRun ge 3 (.State procedure (.Ssequence (row i) rest) k (allocation m).1 le before)
        (.State procedure rest k (allocation m).1 le writes.after) := by
  obtain ⟨writes⟩ := store header resource i access
  have assigned : CC.doAssignLoc ge.genv_cenv (site i).ty before
      header.block (pointerOffset i) .Full (value resource i) = some writes.after := by
    simpa only [CC.doAssignLoc,(Arm64CiliumCallerHeaderTailSource.layout.2.2 i).2.1,
      CC.Mem.storev,Arm64CiliumCallerHeaderTailSource.offsets] using writes.stored
  have step : CC.Step2 ge (.State procedure (row i) (.Kseq rest k) (allocation m).1 le before) CC.E0
      (.State procedure .Sskip (.Kseq rest k) (allocation m).1 le writes.after) := by
    apply CC.Step.assign
    · exact CC.doEvalLvalue_sound _ _ _ _ _ _ _ _
        (Arm64CiliumCallerHeaderTailSource.target_locations header le before i)
    · exact CC.doEvalExpr_sound _ _ _ _ _ _
        (Arm64CiliumCallerHeaderTailValues.source_values resource le before i)
    · exact (Arm64CiliumCallerHeaderTailValues.casts resource before i).1
    · exact CC.doAssignLoc_sound _ _ _ _ _ _ _ _ assigned
  have internal : InternalState (.State procedure (row i) (.Kseq rest k) (allocation m).1 le before) := by
    unfold row;trivial
  refine ⟨writes,?_⟩
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl)
    (.step internal step (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)))

theorem named_frame {m before : CC.Mem} {header : Header m} {resource : Storage m} {i : Fin 16}
    (writes : Store header resource before i) (id : CC.Ident)
    (different : id ≠ Arm64CiliumCallerUnit.___a64_entry) (c : CC.Chunk) (o : Int) :
    localRead m writes.after id c o = localRead m before id c o :=
  Arm64CiliumCallerHeaderEntry.local_frame header writes.otherBlocks id different c o

end KProgFormal.ClightRefinement.Arm64CiliumCallerHeaderTailMemory
