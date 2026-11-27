import KProgFormal.ClightRefinement.Arm64CiliumCallerWriterPrefix

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerWriterGuard
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure ge allocation token)

noncomputable def tableWrites : CC.Stmt := s_trusted_arm64_arm64_sim_xdp_1701
noncomputable def afterStores : CC.Stmt := by
  run_tac do
    let value ← Lean.Elab.Term.elabTerm (← `(Arm64CiliumCallerWriterPrefix.guard)) none
    let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf value)
    unless node.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original guard continuation changed"
    Lean.Elab.Tactic.closeMainGoal `original_after_stores node.getAppArgs[1]!

noncomputable def temps (le : CC.TempEnv) : CC.TempEnv :=
  (((Arm64CiliumCallerWriterPrefix.temps le).set _t'1594 (.Vint (1#32))).set
    _t'1595 (.Vint (1#32))).set _t'1593 (.Vint (1#32))

/-- The actual reg30 guards take15 source steps to the original table stores.
Only existing Clight arithmetic/control is used;memory is not inspected. -/
theorem execute (m : CC.Mem) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) :
    InternalRun ge 15
      (.State procedure Arm64CiliumCallerWriterPrefix.guard k e
        (Arm64CiliumCallerWriterPrefix.temps le) m)
      (.State procedure tableWrites (.Kseq afterStores k) e (temps le) m) := by
  let base := Arm64CiliumCallerWriterPrefix.temps le
  let a := base.set _t'1594 (.Vint (1#32))
  let b := a.set _t'1595 (.Vint (1#32))
  let c := b.set _t'1593 (.Vint (1#32))
  have regRead : base.get ___a64_l_reg__234 = some (.Vlong (30#64)) := by
    unfold base Arm64CiliumCallerWriterPrefix.temps
    rw [CC.PTree.gso _ _ _ _ (by decide +kernel : ___a64_l_next_tag ≠ ___a64_l_reg__234),
      CC.PTree.gso _ _ _ _ (by decide +kernel : ___a64_l_next_ptr ≠ ___a64_l_reg__234),
      CC.PTree.gso _ _ _ _ (by decide +kernel : _t'12904 ≠ ___a64_l_reg__234),
      CC.PTree.gss]
  have eq32 : CC.doEvalExpr ge e base m
      (.Ebinop .Oeq (.Etempvar ___a64_l_reg__234 CC.tulong)
        (.Econst_int (CC.Integers.Int.repr 32) CC.tuint) CC.tint) = some (.Vint (0#32)) := by
    simp only [CC.doEvalExpr,regRead]
    rfl
  have lt31 : CC.doEvalExpr ge e base m
      (.Ebinop .Olt (.Etempvar ___a64_l_reg__234 CC.tulong)
        (.Econst_int (CC.Integers.Int.repr 31) CC.tuint) CC.tint) = some (.Vint (1#32)) := by
    simp only [CC.doEvalExpr,regRead]
    rfl
  have ne31 : CC.doEvalExpr ge e base m
      (.Ebinop .One (.Etempvar ___a64_l_reg__234 CC.tulong)
        (.Econst_int (CC.Integers.Int.repr 31) CC.tuint) CC.tint) = some (.Vint (1#32)) := by
    simp only [CC.doEvalExpr,regRead]
    rfl
  have ne255 : CC.doEvalExpr ge e base m
      (.Ecast (.Ebinop .One (.Etempvar ___a64_l_reg__234 CC.tulong)
        (.Econst_int (CC.Integers.Int.repr 255) CC.tuint) CC.tint) CC.tbool) = some (.Vint (1#32)) := by
    simp only [CC.doEvalExpr,regRead]
    rfl
  have getA : CC.doEvalExpr ge e a m (.Etempvar _t'1594 CC.tint) = some (.Vint (1#32)) := by
    exact CC.PTree.gss _ _ _
  have one : CC.doEvalExpr ge e a m
      (.Ecast (.Econst_int (CC.Integers.Int.repr 1) CC.tint) CC.tint) = some (.Vint (1#32)) := rfl
  have getB : CC.doEvalExpr ge e b m
      (.Ecast (.Ecast (.Etempvar _t'1595 CC.tint) CC.tuchar) CC.tbool) =
      some (.Vint (1#32)) := by
    simp only [CC.doEvalExpr,b,CC.PTree.gss]
    rfl
  have getC : CC.doEvalExpr ge e c m (.Etempvar _t'1593 CC.tint) = some (.Vint (1#32)) := by
    exact CC.PTree.gss _ _ _
  have no : CC.Cop.boolVal (.Vint (0#32)) CC.tint m = some false := rfl
  have yes : CC.Cop.boolVal (.Vint (1#32)) CC.tint m = some true := rfl
  dsimp only [a,b,c] at getA one getB getC
  have run : steps ge 15
      (.State procedure Arm64CiliumCallerWriterPrefix.guard k e base m) =
      some (CC.E0,.State procedure tableWrites (.Kseq afterStores k) e c m) := by
    simp [steps,CC.doStep,CC.typeof,Arm64CiliumCallerWriterPrefix.guard,
      s_trusted_arm64_arm64_sim_xdp_1700,eq32,lt31,ne31,ne255,getA,one,getB,getC,no,yes]
    exact ⟨rfl,rfl,rfl,rfl⟩
  have path : InternalPath ge 15
      (.State procedure Arm64CiliumCallerWriterPrefix.guard k e base m) := by
    simp [InternalPath,InternalState,CC.doStep,CC.typeof,Arm64CiliumCallerWriterPrefix.guard,
      s_trusted_arm64_arm64_sim_xdp_1700,eq32,lt31,ne31,ne255,getA,one,getB,getC,no,yes] <;> trivial
  exact internalRun_of_steps path run

/-- The same original invocation reaches real table stores in35 source
steps,with identical LR-store memory and frame.No initialized table or SP
value is asserted;execution of the table stores remains the next proof. -/
theorem begin_allocated (m : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) :
    ∃ lr : Arm64CiliumCallerLink.LRLocal m, ∃ after block value,
      InternalRun ge 35
        (.State procedure Arm64CiliumCallerLink.site k (allocation m).1 le (allocation m).2)
        (.State procedure tableWrites
          (.Kseq afterStores
            (Arm64CiliumCallerWriter.continuation (Arm64CiliumCallerWriter.outerContinuation k)))
          (allocation m).1 (temps (le.set ___a64_write_old_sp value)) after) ∧
      CC.Mem.store .Mint64 (allocation m).2 lr.block 0 (.Vlong token) = some after ∧
      CC.Mem.load .Mint64 after lr.block 0 = some (.Vlong token) ∧
      CC.Mem.load .Mint64 after block 0 = some value ∧
      FrameBelow m.nextblock (allocation m).2 after ∧
      after.access = (allocation m).2.access ∧ after.nextblock = (allocation m).2.nextblock := by
  obtain ⟨lr,after,block,value,first,stored,lrread,spread,frame,access,next⟩ :=
    Arm64CiliumCallerWriterPrefix.begin_allocated m le k
  have second := execute after (allocation m).1 (le.set ___a64_write_old_sp value)
    (Arm64CiliumCallerWriter.continuation (Arm64CiliumCallerWriter.outerContinuation k))
  exact ⟨lr,after,block,value,first.trans second,stored,lrread,spread,frame,access,next⟩

end KProgFormal.ClightRefinement.Arm64CiliumCallerWriterGuard
