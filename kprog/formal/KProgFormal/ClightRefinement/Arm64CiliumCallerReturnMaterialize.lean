import KProgFormal.ClightRefinement.Arm64CiliumCallerReturnMemory

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerReturnMaterialize
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure allocation)
open Arm64CiliumCallerLinkedProgram (ge)
open Arm64CiliumCallerDefaults (Locals)
open Arm64CiliumCallerReturnMemory (Store)

noncomputable def baseEnv (le : CC.TempEnv) (base : BitVec 64) : CC.TempEnv :=
  CC.PTree.set ___a64_mat_base__3 (CC.Val.Vlong base) le
noncomputable def valueEnv (le : CC.TempEnv) (base : BitVec 64) : CC.TempEnv :=
  CC.PTree.set ___a64_mat_value__1 (CC.Val.Vlong base) (baseEnv le base)
noncomputable def resultEnv (le : CC.TempEnv) (base : BitVec 64) : CC.TempEnv :=
  CC.PTree.set ___a64_store_value (CC.Val.Vlong base) (valueEnv le base)

/-- The original unsigned64 addition materializes raw0 at the arbitrary returned base. -/
theorem add_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (base : BitVec 64)
    (zero : le.get ___a64_mat_value__1 = some (.Vlong (0#64)))
    (baseRead : le.get ___a64_mat_base__3 = some (.Vlong base)) :
    CC.doEvalExpr ge e le memory
      (.Ebinop .Oadd (.Etempvar ___a64_mat_value__1 CC.tulong)
        (.Etempvar ___a64_mat_base__3 CC.tulong) CC.tulong) = some (.Vlong base) := by
  simp only [CC.doEvalExpr,zero,baseRead]
  change some (CC.Val.Vlong ((0#64) + base)) = some (.Vlong base)
  rw [BitVec.zero_add]

/-- The SAME cache Store supplies the actual setBase load. Nine original steps
then finish both loops, copying the materialized value without further heap effects. -/
theorem execute {m supplied : CC.Mem} {locals : Locals m} {base : BitVec 64}
    (result : Store (supplied := supplied) locals base) (le : CC.TempEnv)
    (zero : le.get ___a64_mat_value__1 = some (.Vlong (0#64))) (k : CC.Cont) :
    InternalRun ge 9
      (.State procedure Arm64CiliumCallerReturnProvider.setBase
        (Arm64CiliumCallerReturnMemory.afterContinuation k) (allocation m).1 le result.after)
      (.State procedure .Sskip k (allocation m).1 (resultEnv le base) result.after) := by
  let outer := CC.Cont.Kloop1 Arm64CiliumCallerReturnProvider.body .Sbreak k
  let addCont := CC.Cont.Kseq Arm64CiliumCallerReturnProvider.storeValue outer
  have carried : (baseEnv le base).get ___a64_mat_value__1 = some (.Vlong (0#64)) := by
    unfold baseEnv
    rw [CC.PTree.gso ___a64_mat_base__3 ___a64_mat_value__1 _ _ (by decide +kernel)]
    exact zero
  have baseRead : (baseEnv le base).get ___a64_mat_base__3 = some (.Vlong base) :=
    CC.PTree.gss _ _ _
  have baseStep : CC.Step2 ge
      (.State procedure Arm64CiliumCallerReturnProvider.setBase
        (Arm64CiliumCallerReturnMemory.afterContinuation k) (allocation m).1 le result.after) CC.E0
      (.State procedure .Sskip (Arm64CiliumCallerReturnMemory.afterContinuation k)
        (allocation m).1 (baseEnv le base) result.after) := by
    apply CC.Step.set
    exact CC.doEvalExpr_sound _ _ _ _ _ _ (Arm64CiliumCallerReturnMemory.return_value result le)
  have addStep : CC.Step2 ge
      (.State procedure Arm64CiliumCallerReturnProvider.addValue addCont
        (allocation m).1 (baseEnv le base) result.after) CC.E0
      (.State procedure .Sskip addCont (allocation m).1 (valueEnv le base) result.after) := by
    apply CC.Step.set
    exact CC.doEvalExpr_sound _ _ _ _ _ _ (add_value (allocation m).1 (baseEnv le base) result.after base carried baseRead)
  have storeStep : CC.Step2 ge
      (.State procedure Arm64CiliumCallerReturnProvider.storeValue outer
        (allocation m).1 (valueEnv le base) result.after) CC.E0
      (.State procedure .Sskip outer (allocation m).1 (resultEnv le base) result.after) := by
    apply CC.Step.set
    exact .Etempvar _ _ _ (CC.PTree.gss _ _ _)
  refine .step trivial baseStep ?_
  refine .step trivial (CC.Step.skip_or_continue_loop1 _ _ _ _ _ _ _ _ (Or.inl rfl)) ?_
  refine .step trivial (CC.Step.break_loop2 _ _ _ _ _ _ _) ?_
  refine .step trivial (CC.Step.skip_seq _ _ _ _ _ _) ?_
  refine .step trivial addStep ?_
  refine .step trivial (CC.Step.skip_seq _ _ _ _ _ _) ?_
  refine .step trivial storeStep ?_
  refine .step trivial (CC.Step.skip_or_continue_loop1 _ _ _ _ _ _ _ _ (Or.inl rfl)) ?_
  exact .step trivial (CC.Step.break_loop2 _ _ _ _ _ _ _) (.refl _)

theorem temp_frame (le : CC.TempEnv) (base : BitVec 64) (id : CC.Ident)
    (h0 : id ≠ ___a64_mat_base__3) (h1 : id ≠ ___a64_mat_value__1)
    (h2 : id ≠ ___a64_store_value) :
    (resultEnv le base).get id = le.get id := by
  unfold resultEnv valueEnv baseEnv
  rw [CC.PTree.gso ___a64_store_value id _ _ (Ne.symm h2),
    CC.PTree.gso ___a64_mat_value__1 id _ _ (Ne.symm h1),
    CC.PTree.gso ___a64_mat_base__3 id _ _ (Ne.symm h0)]

theorem values (le : CC.TempEnv) (base : BitVec 64) :
    (resultEnv le base).get ___a64_store_value = some (.Vlong base) ∧
    (resultEnv le base).get ___a64_mat_value__1 = some (.Vlong base) := by
  constructor
  · unfold resultEnv
    exact CC.PTree.gss _ _ _
  · unfold resultEnv
    rw [CC.PTree.gso ___a64_store_value ___a64_mat_value__1 _ _ (by decide +kernel)]
    unfold valueEnv
    exact CC.PTree.gss _ _ _


/-- The reached original RETURN branch set raw materialization value0 before the provider call. -/
theorem input_zero (le : CC.TempEnv) :
    (Arm64CiliumCallerReturnProvider.resultEnv le).get ___a64_mat_value__1 = some (.Vlong (0#64)) := by
  unfold Arm64CiliumCallerReturnProvider.resultEnv
  rw [CC.PTree.gso _t'13881 ___a64_mat_value__1 _ _ (by decide +kernel),
    CC.PTree.gso ___a64_mat_tag__1 ___a64_mat_value__1 _ _ (by decide +kernel)]
  exact CC.PTree.gss _ _ _

/-- Compose the actual cache suffix and completion, deriving raw0 from the reached original temps. -/
theorem advance {m supplied : CC.Mem} {locals : Locals m} {base : BitVec 64}
    (result : Store (supplied := supplied) locals base) (le : CC.TempEnv) (k : CC.Cont) :
    InternalRun ge 15
      (.Returnstate (.Vlong base)
        (.Kcall (some _t'157) procedure (allocation m).1 (Arm64CiliumCallerReturnProvider.resultEnv le)
          (Arm64CiliumCallerReturnProvider.continuation k)) supplied)
      (.State procedure .Sskip k (allocation m).1
        (resultEnv (Arm64CiliumCallerReturnMemory.resultEnv
          (Arm64CiliumCallerReturnProvider.resultEnv le) base) base) result.after) := by
  have zero : (Arm64CiliumCallerReturnMemory.resultEnv
      (Arm64CiliumCallerReturnProvider.resultEnv le) base).get ___a64_mat_value__1 = some (.Vlong (0#64)) := by
    unfold Arm64CiliumCallerReturnMemory.resultEnv
    rw [CC.PTree.gso _t'157 ___a64_mat_value__1 _ _ (by decide +kernel)]
    exact input_zero le
  exact (Arm64CiliumCallerReturnMemory.execute result (Arm64CiliumCallerReturnProvider.resultEnv le) k).trans
    (execute result _ zero k)

/-- Actual current allocation rights derive both stores and the complete fifteen-step original suffix. -/
theorem write_and_advance {m supplied : CC.Mem} (locals : Locals m) (base : BitVec 64)
    (access : supplied.access = (allocation m).2.access) (le : CC.TempEnv) (k : CC.Cont) :
    ∃ result : Store (supplied := supplied) locals base,
      InternalRun ge 15
        (.Returnstate (.Vlong base)
          (.Kcall (some _t'157) procedure (allocation m).1 (Arm64CiliumCallerReturnProvider.resultEnv le)
            (Arm64CiliumCallerReturnProvider.continuation k)) supplied)
        (.State procedure .Sskip k (allocation m).1
          (resultEnv (Arm64CiliumCallerReturnMemory.resultEnv
            (Arm64CiliumCallerReturnProvider.resultEnv le) base) base) result.after) := by
  obtain ⟨result⟩ := Arm64CiliumCallerReturnMemory.write locals base access
  exact ⟨result,advance result le k⟩

end KProgFormal.ClightRefinement.Arm64CiliumCallerReturnMaterialize
