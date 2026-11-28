import KProgFormal.ClightRefinement.Arm64CiliumCallerVectorPointerLoopMemory

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerVectorPointerLoopIteration
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure ge allocation)
open Arm64CiliumCallerHeaderSource (Header)
open Arm64CiliumCallerVectorSource (Storage)
open Arm64CiliumCallerVectorPointerLoopSource
open Arm64CiliumCallerVectorPointerLoopValues (vectorPointerOffset)

private theorem opposite_slots : ∀ i : Fin 32,slot false i ≠ slot true i := by decide +kernel
private theorem different_slots (side high : Bool) (i j : Fin 32) (different : j ≠ i) :
    slot side j ≠ slot high i := by
  intro same
  have eq := congrArg Fin.val same
  have ne : j.val ≠ i.val := fun h => different (Fin.ext h)
  have ib := i.isLt
  have jb := j.isLt
  cases side <;> cases high <;>
    simp only [slot,Bool.false_eq_true,ite_false,ite_true] at eq <;> omega

/-- The original guard, two actual stores and increment make one11-step iteration. -/
theorem iteration {m before : CC.Mem} (header : Header m) (vectors : Storage m)
    (i : Fin 32) (access : before.access = (allocation m).2.access)
    (le : CC.TempEnv) (k : CC.Cont)
    (indexFound : le.get _i = some (.Vint (CC.Integers.Int.repr i.val))) :
    ∃ after,InternalRun ge 11 (.State procedure loop k (allocation m).1 le before)
        (.State procedure loop k (allocation m).1
          (le.set _i (.Vint (CC.Integers.Int.repr (i.val+1)))) after) ∧
      (∀ high,CC.Mem.load .Mint64 after header.block (headerOffset high i) =
        some (.Vptr vectors.block (vectorPointerOffset high i))) ∧
      (∀ (side : Bool) (j : Fin 32),j ≠ i →
        CC.Mem.load .Mint64 after header.block (headerOffset side j) =
          CC.Mem.load .Mint64 before header.block (headerOffset side j)) ∧
      (∀ j : Fin 12,CC.Mem.load .Mint64 after header.block (8*(j.val : Int)) =
        CC.Mem.load .Mint64 before header.block (8*(j.val : Int))) ∧
      (∀ j : Fin 16,CC.Mem.load (Arm64CiliumCallerHeaderTailSource.chunk j)
          after header.block (Arm64CiliumCallerHeaderTailSource.offset j) =
        CC.Mem.load (Arm64CiliumCallerHeaderTailSource.chunk j)
          before header.block (Arm64CiliumCallerHeaderTailSource.offset j)) ∧
      (∀ b,b ≠ header.block → ∀ c o,CC.Mem.load c after b o = CC.Mem.load c before b o) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  let loopK := CC.Cont.Kloop1 body increment k
  let stores := CC.Stmt.Ssequence (assignment false) (assignment true)
  obtain ⟨low,lowRun⟩ := Arm64CiliumCallerVectorPointerLoopMemory.assign
    header vectors false i access le (.Kseq (assignment true) loopK) indexFound
  obtain ⟨high,highRun⟩ := Arm64CiliumCallerVectorPointerLoopMemory.assign
    header vectors true i (low.access.trans access) le loopK indexFound
  have test := Arm64CiliumCallerVectorPointerLoopValues.condition_values (m := m) le before
    ⟨i.val,by have bound := i.isLt;omega⟩ indexFound
  change CC.doEvalExpr ge (allocation m).1 le before condition =
    some (.Vint (if i.val < 32 then 1 else 0)) at test
  rw [ite_eq_left i.isLt] at test
  have branch : CC.doStep ge
      (.State procedure guard (.Kseq stores loopK) (allocation m).1 le before) =
      some (CC.E0,.State procedure .Sskip (.Kseq stores loopK) (allocation m).1 le before) := by
    simp only [Arm64CiliumCallerVectorPointerLoopSource.guard,CC.doStep,test]
    rfl
  have incrementStep : CC.doStep ge
      (.State procedure increment (.Kloop2 body increment k) (allocation m).1 le high.after) =
      some (CC.E0,.State procedure .Sskip (.Kloop2 body increment k) (allocation m).1
        (le.set _i (.Vint (CC.Integers.Int.repr (i.val+1)))) high.after) := by
    simp only [increment,CC.doStep,
      Arm64CiliumCallerVectorPointerLoopValues.increment_values (m := m) le high.after i indexFound]
  have loopPrefix : InternalRun ge 5
      (.State procedure loop k (allocation m).1 le before)
      (.State procedure (assignment false) (.Kseq (assignment true) loopK) (allocation m).1 le before) :=
    .step trivial (CC.doStep_sound _ _ _ _ rfl)
      (.step trivial (CC.doStep_sound _ _ _ _ rfl)
        (.step trivial (CC.doStep_sound _ _ _ _ branch)
          (.step trivial (CC.doStep_sound _ _ _ _ rfl)
            (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)))))
  have middle : InternalRun ge 1
      (.State procedure .Sskip (.Kseq (assignment true) loopK) (allocation m).1 le low.after)
      (.State procedure (assignment true) loopK (allocation m).1 le low.after) :=
    .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  have suffix : InternalRun ge 3
      (.State procedure .Sskip loopK (allocation m).1 le high.after)
      (.State procedure loop k (allocation m).1
        (le.set _i (.Vint (CC.Integers.Int.repr (i.val+1)))) high.after) :=
    .step trivial (CC.doStep_sound _ _ _ _ rfl)
      (.step trivial (CC.doStep_sound _ _ _ _ incrementStep)
        (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)))
  refine ⟨high.after,(((loopPrefix.trans lowRun).trans middle).trans highRun).trans suffix,?_,?_,
    (fun j => (high.fixedFields j).trans (low.fixedFields j)),
    (fun j => (high.tailFields j).trans (low.tailFields j)),
    (fun b different c o => (high.otherBlocks b different c o).trans (low.otherBlocks b different c o)),
    low.frame.trans high.frame,high.access.trans low.access,high.frontier.trans low.frontier⟩
  · intro side
    cases side
    · have kept := high.otherFields (slot false i) (opposite_slots i)
      rw [(header_slots false i).1] at kept
      exact kept.trans low.read
    · exact high.read
  · intro side j different
    have keepHigh := high.otherFields (slot side j) (different_slots side true i j different)
    have keepLow := low.otherFields (slot side j) (different_slots side false i j different)
    rw [(header_slots side j).1] at keepHigh keepLow
    exact keepHigh.trans keepLow

theorem initialized {m before : CC.Mem} (le : CC.TempEnv) (k : CC.Cont) :
    InternalRun ge 4
      (.State procedure Arm64CiliumCallerHeaderTailSource.after k (allocation m).1 le before)
      (.State procedure loop (.Kseq after k) (allocation m).1
        (le.set _i (.Vint (0#32))) before) := by
  rw [Arm64CiliumCallerVectorPointerLoopSource.source]
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl)
    (.step trivial (CC.doStep_sound _ _ _ _ rfl)
      (.step trivial (CC.doStep_sound _ _ _ _ rfl)
        (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _))))

theorem exited {m before : CC.Mem} (le : CC.TempEnv) (k : CC.Cont)
    (indexFound : le.get _i = some (.Vint (32#32))) :
    InternalRun ge 6 (.State procedure loop (.Kseq after k) (allocation m).1 le before)
      (.State procedure after k (allocation m).1 le before) := by
  have test : CC.doEvalExpr ge (allocation m).1 le before condition = some (.Vint (0#32)) :=
    Arm64CiliumCallerVectorPointerLoopValues.condition_values (m := m) le before ⟨32,by decide⟩ indexFound
  have branch : CC.doStep ge
      (.State procedure guard
        (.Kseq (.Ssequence (assignment false) (assignment true))
          (.Kloop1 body increment (.Kseq after k))) (allocation m).1 le before) =
      some (CC.E0,.State procedure .Sbreak
        (.Kseq (.Ssequence (assignment false) (assignment true))
          (.Kloop1 body increment (.Kseq after k))) (allocation m).1 le before) := by
    simp only [Arm64CiliumCallerVectorPointerLoopSource.guard,CC.doStep,test]
    rfl
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl)
    (.step trivial (CC.doStep_sound _ _ _ _ rfl)
      (.step trivial (CC.doStep_sound _ _ _ _ branch)
        (.step trivial (CC.doStep_sound _ _ _ _ rfl)
          (.step trivial (CC.doStep_sound _ _ _ _ rfl)
            (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _))))))

end KProgFormal.ClightRefinement.Arm64CiliumCallerVectorPointerLoopIteration
