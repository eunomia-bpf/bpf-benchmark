import KProgFormal.ClightRefinement.Arm64CiliumCallerMemOffsetPrefix

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerMemOffset
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure)
private noncomputable def stage : CC.Stmt := Arm64CiliumCallerMemOffsetPrefix.afterIndex

private structure Parts where
  body : CC.Stmt
  finish : CC.Stmt
  condition : CC.Expr
  yes : CC.Stmt
  no : CC.Stmt

private noncomputable def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless node.isAppOfArity ctor arity do throwError "actual numeric memory-offset source changed"
      pure node.getAppArgs
    let original ← Lean.Elab.Term.elabTerm (← `(Arm64CiliumCallerMemOffsetPrefix.afterIndex)) none
    let outer ← peel original ``CC.Stmt.Ssequence 2
    let loop ← peel outer[0]! ``CC.Stmt.Sloop 2
    let b0 ← peel loop[0]! ``CC.Stmt.Ssequence 2
    let b1 ← peel b0[1]! ``CC.Stmt.Ssequence 2
    let b2 ← peel b1[1]! ``CC.Stmt.Ssequence 2
    let pp ← peel b2[0]! ``CC.Stmt.Ssequence 2
    let pair ← peel pp[0]! ``CC.Stmt.Ssequence 2
    let choose ← peel pair[0]! ``CC.Stmt.Sifthenelse 3
    Lean.Elab.Tactic.closeMainGoal `actual_mem_offset
      (← Lean.Meta.mkAppM ``Parts.mk #[loop[0]!,outer[1]!,choose[0]!,choose[1]!,choose[2]!])

private noncomputable def body : CC.Stmt := parts.body
private noncomputable def condition : CC.Expr := parts.condition
theorem source : Arm64CiliumCallerMemOffsetPrefix.afterIndex =
    .Ssequence (.Sloop body .Sbreak) parts.finish := rfl

private theorem body_source : body =
    .Ssequence (.Sset ___kprog_a64_mbo_imm (.Etempvar ___a64_mbo_imm CC.tulong))
    (.Ssequence (.Sset ___kprog_a64_mbo_index (.Etempvar ___a64_mbo_index CC.tulong))
      (.Ssequence
        (.Ssequence
          (.Ssequence (.Sifthenelse condition parts.yes parts.no)
            (.Sifthenelse (.Etempvar _t'150 CC.tint)
              s_trusted_arm64_arm64_sim_xdp_46 s_trusted_arm64_arm64_sim_xdp_47))
          (.Sset ___kprog_a64_mbo_prepost (.Etempvar _t'151 CC.tint)))
        (.Ssequence
          (.Ssequence (.Sifthenelse (.Etempvar ___a64_mbo_has_index CC.tuchar)
              s_trusted_arm64_arm64_sim_xdp_48 s_trusted_arm64_arm64_sim_xdp_49)
            (.Sset ___kprog_a64_mbo_has_index (.Etempvar _t'152 CC.tint)))
          (.Ssequence
            (.Ssequence s_trusted_arm64_arm64_sim_xdp_50
              (.Sset ___kprog_a64_mbo_base (.Etempvar _t'153 CC.tulong)))
            (.Ssequence s_trusted_arm64_arm64_sim_xdp_51 s_trusted_arm64_arm64_sim_xdp_52))))) := rfl
private theorem yes_source : parts.yes = .Sset _t'150 (.Econst_int (1#32) CC.tint) := rfl
private theorem finish_source : parts.finish = .Sset ___a64_store_off
    (.Ecast (.Etempvar ___a64_mbo_result CC.tulong) CC.tlong) := rfl
private theorem flag (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr world e le memory condition = some (.Vint (1#32)) := rfl

private noncomputable def env0 (le : CC.TempEnv) := Arm64CiliumCallerMemOffsetPrefix.resultEnv le
private noncomputable def env1 (le : CC.TempEnv) := CC.PTree.set ___kprog_a64_mbo_imm (CC.Val.Vlong Arm64CiliumCallerSPPreindex.delta) (env0 le)
private noncomputable def env2 (le : CC.TempEnv) := CC.PTree.set ___kprog_a64_mbo_index (CC.Val.Vlong (0#64)) (env1 le)
private noncomputable def env3 (le : CC.TempEnv) := CC.PTree.set _t'150 (CC.Val.Vint (1#32)) (env2 le)
private noncomputable def env4 (le : CC.TempEnv) := CC.PTree.set _t'151 (CC.Val.Vint (1#32)) (env3 le)
private noncomputable def env5 (le : CC.TempEnv) := CC.PTree.set ___kprog_a64_mbo_prepost (CC.Val.Vint (1#32)) (env4 le)
private noncomputable def env6 (le : CC.TempEnv) := CC.PTree.set _t'152 (CC.Val.Vint (0#32)) (env5 le)
private noncomputable def env7 (le : CC.TempEnv) := CC.PTree.set ___kprog_a64_mbo_has_index (CC.Val.Vint (0#32)) (env6 le)
private noncomputable def env8 (le : CC.TempEnv) := CC.PTree.set _t'153 (CC.Val.Vlong (0#64)) (env7 le)
private noncomputable def env9 (le : CC.TempEnv) := CC.PTree.set ___kprog_a64_mbo_base (CC.Val.Vlong (0#64)) (env8 le)
private noncomputable def env10 (le : CC.TempEnv) := CC.PTree.set ___kprog_a64_mbo_result (CC.Val.Vlong (0#64)) (env9 le)
private noncomputable def env11 (le : CC.TempEnv) := CC.PTree.set ___a64_mbo_result (CC.Val.Vlong (0#64)) (env10 le)
private noncomputable def env12 (le : CC.TempEnv) := CC.PTree.set ___a64_store_off (CC.Val.Vlong (0#64)) (env11 le)

noncomputable def resultEnv (le : CC.TempEnv) : CC.TempEnv := env12 le

private theorem read0 (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr world e (env0 le) memory (.Etempvar ___a64_mbo_imm CC.tulong) = some (CC.Val.Vlong Arm64CiliumCallerSPPreindex.delta) := by
  have lookup : (env0 le).get ___a64_mbo_imm = some (CC.Val.Vlong Arm64CiliumCallerSPPreindex.delta) := by
    unfold env0 Arm64CiliumCallerMemOffsetPrefix.resultEnv
    rw [CC.PTree.gso ___a64_mbo_index ___a64_mbo_imm _ _ (by decide +kernel),
      CC.PTree.gss]
  simp only [CC.doEvalExpr,lookup]

private theorem read1 (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr world e (env1 le) memory (.Etempvar ___a64_mbo_index CC.tulong) = some (CC.Val.Vlong (0#64)) := by
  have lookup : (env1 le).get ___a64_mbo_index = some (CC.Val.Vlong (0#64)) := by
    unfold env1 env0 Arm64CiliumCallerMemOffsetPrefix.resultEnv
    rw [CC.PTree.gso ___kprog_a64_mbo_imm ___a64_mbo_index _ _ (by decide +kernel),
      CC.PTree.gss]
  simp only [CC.doEvalExpr,lookup]

private theorem read2 (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr world e (env3 le) memory (.Etempvar _t'150 CC.tint) = some (CC.Val.Vint (1#32)) := by
  have lookup : (env3 le).get _t'150 = some (CC.Val.Vint (1#32)) := by
    unfold env3 env2 env1 env0 Arm64CiliumCallerMemOffsetPrefix.resultEnv
    rw [CC.PTree.gss]
  simp only [CC.doEvalExpr,lookup]

private theorem read3 (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr world e (env4 le) memory (.Etempvar _t'151 CC.tint) = some (CC.Val.Vint (1#32)) := by
  have lookup : (env4 le).get _t'151 = some (CC.Val.Vint (1#32)) := by
    unfold env4 env3 env2 env1 env0 Arm64CiliumCallerMemOffsetPrefix.resultEnv
    rw [CC.PTree.gss]
  simp only [CC.doEvalExpr,lookup]

private theorem read4 (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr world e (env5 le) memory (.Etempvar ___a64_mbo_has_index CC.tuchar) = some (CC.Val.Vint (0#32)) := by
  have lookup : (env5 le).get ___a64_mbo_has_index = some (CC.Val.Vint (0#32)) := by
    unfold env5 env4 env3 env2 env1 env0 Arm64CiliumCallerMemOffsetPrefix.resultEnv
    rw [CC.PTree.gso ___kprog_a64_mbo_prepost ___a64_mbo_has_index _ _ (by decide +kernel),
      CC.PTree.gso _t'151 ___a64_mbo_has_index _ _ (by decide +kernel),
      CC.PTree.gso _t'150 ___a64_mbo_has_index _ _ (by decide +kernel),
      CC.PTree.gso ___kprog_a64_mbo_index ___a64_mbo_has_index _ _ (by decide +kernel),
      CC.PTree.gso ___kprog_a64_mbo_imm ___a64_mbo_has_index _ _ (by decide +kernel),
      CC.PTree.gso ___a64_mbo_index ___a64_mbo_has_index _ _ (by decide +kernel),
      CC.PTree.gso ___a64_mbo_imm ___a64_mbo_has_index _ _ (by decide +kernel),
      CC.PTree.gso ___a64_mbo_isrc ___a64_mbo_has_index _ _ (by decide +kernel),
      CC.PTree.gso _t'141 ___a64_mbo_has_index _ _ (by decide +kernel),
      CC.PTree.gss]
  simp only [CC.doEvalExpr,lookup]

private theorem read5 (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr world e (env6 le) memory (.Etempvar _t'152 CC.tint) = some (CC.Val.Vint (0#32)) := by
  have lookup : (env6 le).get _t'152 = some (CC.Val.Vint (0#32)) := by
    unfold env6 env5 env4 env3 env2 env1 env0 Arm64CiliumCallerMemOffsetPrefix.resultEnv
    rw [CC.PTree.gss]
  simp only [CC.doEvalExpr,lookup]

private theorem read6 (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr world e (env7 le) memory (.Etempvar ___kprog_a64_mbo_prepost CC.tint) = some (CC.Val.Vint (1#32)) := by
  have lookup : (env7 le).get ___kprog_a64_mbo_prepost = some (CC.Val.Vint (1#32)) := by
    unfold env7 env6 env5 env4 env3 env2 env1 env0 Arm64CiliumCallerMemOffsetPrefix.resultEnv
    rw [CC.PTree.gso ___kprog_a64_mbo_has_index ___kprog_a64_mbo_prepost _ _ (by decide +kernel),
      CC.PTree.gso _t'152 ___kprog_a64_mbo_prepost _ _ (by decide +kernel),
      CC.PTree.gss]
  simp only [CC.doEvalExpr,lookup]

private theorem read7 (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr world e (env8 le) memory (.Etempvar _t'153 CC.tulong) = some (CC.Val.Vlong (0#64)) := by
  have lookup : (env8 le).get _t'153 = some (CC.Val.Vlong (0#64)) := by
    unfold env8 env7 env6 env5 env4 env3 env2 env1 env0 Arm64CiliumCallerMemOffsetPrefix.resultEnv
    rw [CC.PTree.gss]
  simp only [CC.doEvalExpr,lookup]

private theorem read8 (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr world e (env9 le) memory (.Etempvar ___kprog_a64_mbo_base CC.tulong) = some (CC.Val.Vlong (0#64)) := by
  have lookup : (env9 le).get ___kprog_a64_mbo_base = some (CC.Val.Vlong (0#64)) := by
    unfold env9 env8 env7 env6 env5 env4 env3 env2 env1 env0 Arm64CiliumCallerMemOffsetPrefix.resultEnv
    rw [CC.PTree.gss]
  simp only [CC.doEvalExpr,lookup]

private theorem read9 (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr world e (env10 le) memory (.Etempvar ___kprog_a64_mbo_has_index CC.tint) = some (CC.Val.Vint (0#32)) := by
  have lookup : (env10 le).get ___kprog_a64_mbo_has_index = some (CC.Val.Vint (0#32)) := by
    unfold env10 env9 env8 env7 env6 env5 env4 env3 env2 env1 env0 Arm64CiliumCallerMemOffsetPrefix.resultEnv
    rw [CC.PTree.gso ___kprog_a64_mbo_result ___kprog_a64_mbo_has_index _ _ (by decide +kernel),
      CC.PTree.gso ___kprog_a64_mbo_base ___kprog_a64_mbo_has_index _ _ (by decide +kernel),
      CC.PTree.gso _t'153 ___kprog_a64_mbo_has_index _ _ (by decide +kernel),
      CC.PTree.gss]
  simp only [CC.doEvalExpr,lookup]

private theorem read10 (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr world e (env10 le) memory (.Etempvar ___kprog_a64_mbo_result CC.tulong) = some (CC.Val.Vlong (0#64)) := by
  have lookup : (env10 le).get ___kprog_a64_mbo_result = some (CC.Val.Vlong (0#64)) := by
    unfold env10 env9 env8 env7 env6 env5 env4 env3 env2 env1 env0 Arm64CiliumCallerMemOffsetPrefix.resultEnv
    rw [CC.PTree.gss]
  simp only [CC.doEvalExpr,lookup]

private theorem read11 (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr world e (env11 le) memory (.Ecast (.Etempvar ___a64_mbo_result CC.tulong) CC.tlong) = some (CC.Val.Vlong (0#64)) := by
  have lookup : (env11 le).get ___a64_mbo_result = some (CC.Val.Vlong (0#64)) := by
    unfold env11 env10 env9 env8 env7 env6 env5 env4 env3 env2 env1 env0 Arm64CiliumCallerMemOffsetPrefix.resultEnv
    rw [CC.PTree.gss]
  simp only [CC.doEvalExpr,lookup]
  rfl

private theorem flat_read0 (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr world e (Arm64CiliumCallerMemOffsetPrefix.resultEnv le) memory (.Etempvar ___a64_mbo_imm CC.tulong) = some (CC.Val.Vlong Arm64CiliumCallerSPPreindex.delta) := by
  simpa only [env0] using read0 world e le memory

private theorem flat_read1 (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr world e (CC.PTree.set ___kprog_a64_mbo_imm (CC.Val.Vlong Arm64CiliumCallerSPPreindex.delta) (Arm64CiliumCallerMemOffsetPrefix.resultEnv le)) memory (.Etempvar ___a64_mbo_index CC.tulong) = some (CC.Val.Vlong (0#64)) := by
  simpa only [env1,env0] using read1 world e le memory

private theorem flat_read2 (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr world e (CC.PTree.set _t'150 (CC.Val.Vint (1#32)) (CC.PTree.set ___kprog_a64_mbo_index (CC.Val.Vlong (0#64)) (CC.PTree.set ___kprog_a64_mbo_imm (CC.Val.Vlong Arm64CiliumCallerSPPreindex.delta) (Arm64CiliumCallerMemOffsetPrefix.resultEnv le)))) memory (.Etempvar _t'150 CC.tint) = some (CC.Val.Vint (1#32)) := by
  simpa only [env3,env2,env1,env0] using read2 world e le memory

private theorem flat_read3 (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr world e (CC.PTree.set _t'151 (CC.Val.Vint (1#32)) (CC.PTree.set _t'150 (CC.Val.Vint (1#32)) (CC.PTree.set ___kprog_a64_mbo_index (CC.Val.Vlong (0#64)) (CC.PTree.set ___kprog_a64_mbo_imm (CC.Val.Vlong Arm64CiliumCallerSPPreindex.delta) (Arm64CiliumCallerMemOffsetPrefix.resultEnv le))))) memory (.Etempvar _t'151 CC.tint) = some (CC.Val.Vint (1#32)) := by
  simpa only [env4,env3,env2,env1,env0] using read3 world e le memory

private theorem flat_read4 (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr world e (CC.PTree.set ___kprog_a64_mbo_prepost (CC.Val.Vint (1#32)) (CC.PTree.set _t'151 (CC.Val.Vint (1#32)) (CC.PTree.set _t'150 (CC.Val.Vint (1#32)) (CC.PTree.set ___kprog_a64_mbo_index (CC.Val.Vlong (0#64)) (CC.PTree.set ___kprog_a64_mbo_imm (CC.Val.Vlong Arm64CiliumCallerSPPreindex.delta) (Arm64CiliumCallerMemOffsetPrefix.resultEnv le)))))) memory (.Etempvar ___a64_mbo_has_index CC.tuchar) = some (CC.Val.Vint (0#32)) := by
  simpa only [env5,env4,env3,env2,env1,env0] using read4 world e le memory

private theorem flat_read5 (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr world e (CC.PTree.set _t'152 (CC.Val.Vint (0#32)) (CC.PTree.set ___kprog_a64_mbo_prepost (CC.Val.Vint (1#32)) (CC.PTree.set _t'151 (CC.Val.Vint (1#32)) (CC.PTree.set _t'150 (CC.Val.Vint (1#32)) (CC.PTree.set ___kprog_a64_mbo_index (CC.Val.Vlong (0#64)) (CC.PTree.set ___kprog_a64_mbo_imm (CC.Val.Vlong Arm64CiliumCallerSPPreindex.delta) (Arm64CiliumCallerMemOffsetPrefix.resultEnv le))))))) memory (.Etempvar _t'152 CC.tint) = some (CC.Val.Vint (0#32)) := by
  simpa only [env6,env5,env4,env3,env2,env1,env0] using read5 world e le memory

private theorem flat_read6 (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr world e (CC.PTree.set ___kprog_a64_mbo_has_index (CC.Val.Vint (0#32)) (CC.PTree.set _t'152 (CC.Val.Vint (0#32)) (CC.PTree.set ___kprog_a64_mbo_prepost (CC.Val.Vint (1#32)) (CC.PTree.set _t'151 (CC.Val.Vint (1#32)) (CC.PTree.set _t'150 (CC.Val.Vint (1#32)) (CC.PTree.set ___kprog_a64_mbo_index (CC.Val.Vlong (0#64)) (CC.PTree.set ___kprog_a64_mbo_imm (CC.Val.Vlong Arm64CiliumCallerSPPreindex.delta) (Arm64CiliumCallerMemOffsetPrefix.resultEnv le)))))))) memory (.Etempvar ___kprog_a64_mbo_prepost CC.tint) = some (CC.Val.Vint (1#32)) := by
  simpa only [env7,env6,env5,env4,env3,env2,env1,env0] using read6 world e le memory

private theorem flat_read7 (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr world e (CC.PTree.set _t'153 (CC.Val.Vlong (0#64)) (CC.PTree.set ___kprog_a64_mbo_has_index (CC.Val.Vint (0#32)) (CC.PTree.set _t'152 (CC.Val.Vint (0#32)) (CC.PTree.set ___kprog_a64_mbo_prepost (CC.Val.Vint (1#32)) (CC.PTree.set _t'151 (CC.Val.Vint (1#32)) (CC.PTree.set _t'150 (CC.Val.Vint (1#32)) (CC.PTree.set ___kprog_a64_mbo_index (CC.Val.Vlong (0#64)) (CC.PTree.set ___kprog_a64_mbo_imm (CC.Val.Vlong Arm64CiliumCallerSPPreindex.delta) (Arm64CiliumCallerMemOffsetPrefix.resultEnv le))))))))) memory (.Etempvar _t'153 CC.tulong) = some (CC.Val.Vlong (0#64)) := by
  simpa only [env8,env7,env6,env5,env4,env3,env2,env1,env0] using read7 world e le memory

private theorem flat_read8 (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr world e (CC.PTree.set ___kprog_a64_mbo_base (CC.Val.Vlong (0#64)) (CC.PTree.set _t'153 (CC.Val.Vlong (0#64)) (CC.PTree.set ___kprog_a64_mbo_has_index (CC.Val.Vint (0#32)) (CC.PTree.set _t'152 (CC.Val.Vint (0#32)) (CC.PTree.set ___kprog_a64_mbo_prepost (CC.Val.Vint (1#32)) (CC.PTree.set _t'151 (CC.Val.Vint (1#32)) (CC.PTree.set _t'150 (CC.Val.Vint (1#32)) (CC.PTree.set ___kprog_a64_mbo_index (CC.Val.Vlong (0#64)) (CC.PTree.set ___kprog_a64_mbo_imm (CC.Val.Vlong Arm64CiliumCallerSPPreindex.delta) (Arm64CiliumCallerMemOffsetPrefix.resultEnv le)))))))))) memory (.Etempvar ___kprog_a64_mbo_base CC.tulong) = some (CC.Val.Vlong (0#64)) := by
  simpa only [env9,env8,env7,env6,env5,env4,env3,env2,env1,env0] using read8 world e le memory

private theorem flat_read9 (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr world e (CC.PTree.set ___kprog_a64_mbo_result (CC.Val.Vlong (0#64)) (CC.PTree.set ___kprog_a64_mbo_base (CC.Val.Vlong (0#64)) (CC.PTree.set _t'153 (CC.Val.Vlong (0#64)) (CC.PTree.set ___kprog_a64_mbo_has_index (CC.Val.Vint (0#32)) (CC.PTree.set _t'152 (CC.Val.Vint (0#32)) (CC.PTree.set ___kprog_a64_mbo_prepost (CC.Val.Vint (1#32)) (CC.PTree.set _t'151 (CC.Val.Vint (1#32)) (CC.PTree.set _t'150 (CC.Val.Vint (1#32)) (CC.PTree.set ___kprog_a64_mbo_index (CC.Val.Vlong (0#64)) (CC.PTree.set ___kprog_a64_mbo_imm (CC.Val.Vlong Arm64CiliumCallerSPPreindex.delta) (Arm64CiliumCallerMemOffsetPrefix.resultEnv le))))))))))) memory (.Etempvar ___kprog_a64_mbo_has_index CC.tint) = some (CC.Val.Vint (0#32)) := by
  simpa only [env10,env9,env8,env7,env6,env5,env4,env3,env2,env1,env0] using read9 world e le memory

private theorem flat_read10 (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr world e (CC.PTree.set ___kprog_a64_mbo_result (CC.Val.Vlong (0#64)) (CC.PTree.set ___kprog_a64_mbo_base (CC.Val.Vlong (0#64)) (CC.PTree.set _t'153 (CC.Val.Vlong (0#64)) (CC.PTree.set ___kprog_a64_mbo_has_index (CC.Val.Vint (0#32)) (CC.PTree.set _t'152 (CC.Val.Vint (0#32)) (CC.PTree.set ___kprog_a64_mbo_prepost (CC.Val.Vint (1#32)) (CC.PTree.set _t'151 (CC.Val.Vint (1#32)) (CC.PTree.set _t'150 (CC.Val.Vint (1#32)) (CC.PTree.set ___kprog_a64_mbo_index (CC.Val.Vlong (0#64)) (CC.PTree.set ___kprog_a64_mbo_imm (CC.Val.Vlong Arm64CiliumCallerSPPreindex.delta) (Arm64CiliumCallerMemOffsetPrefix.resultEnv le))))))))))) memory (.Etempvar ___kprog_a64_mbo_result CC.tulong) = some (CC.Val.Vlong (0#64)) := by
  simpa only [env10,env9,env8,env7,env6,env5,env4,env3,env2,env1,env0] using read10 world e le memory

private theorem flat_read11 (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr world e (CC.PTree.set ___a64_mbo_result (CC.Val.Vlong (0#64)) (CC.PTree.set ___kprog_a64_mbo_result (CC.Val.Vlong (0#64)) (CC.PTree.set ___kprog_a64_mbo_base (CC.Val.Vlong (0#64)) (CC.PTree.set _t'153 (CC.Val.Vlong (0#64)) (CC.PTree.set ___kprog_a64_mbo_has_index (CC.Val.Vint (0#32)) (CC.PTree.set _t'152 (CC.Val.Vint (0#32)) (CC.PTree.set ___kprog_a64_mbo_prepost (CC.Val.Vint (1#32)) (CC.PTree.set _t'151 (CC.Val.Vint (1#32)) (CC.PTree.set _t'150 (CC.Val.Vint (1#32)) (CC.PTree.set ___kprog_a64_mbo_index (CC.Val.Vlong (0#64)) (CC.PTree.set ___kprog_a64_mbo_imm (CC.Val.Vlong Arm64CiliumCallerSPPreindex.delta) (Arm64CiliumCallerMemOffsetPrefix.resultEnv le)))))))))))) memory (.Ecast (.Etempvar ___a64_mbo_result CC.tulong) CC.tlong) = some (CC.Val.Vlong (0#64)) := by
  simpa only [env11,env10,env9,env8,env7,env6,env5,env4,env3,env2,env1,env0] using read11 world e le memory

private theorem temp_type (id : CC.Ident) (ty : CC.Ty) :
    CC.typeof (.Etempvar id ty) = ty := rfl
private theorem condition_type : CC.typeof condition = CC.tuint := rfl
private theorem unsigned_true (memory : CC.Mem) :
    CC.Cop.boolVal (.Vint (1#32)) CC.tuint memory = some true := rfl

private theorem int_value (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (value : BitVec 32) (ty : CC.Ty) :
    CC.doEvalExpr world e le memory (.Econst_int value ty) = some (.Vint value) := rfl

private theorem zero_int (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr world e le memory (.Ecast (.Econst_int (CC.Integers.Int.repr 0) CC.tint) CC.tint) =
      some (.Vint (0#32)) := rfl
private theorem one_int (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr world e le memory (.Ecast (.Econst_int (CC.Integers.Int.repr 1) CC.tint) CC.tint) =
      some (.Vint (1#32)) := rfl
private theorem zero_long (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr world e le memory (.Ecast (.Econst_long (CC.Integers.Int64.repr 0) CC.tulong) CC.tulong) =
      some (.Vlong (0#64)) := rfl
private theorem bools (memory : CC.Mem) :
    CC.Cop.boolVal (.Vint (0#32)) CC.tint memory = some false ∧
    CC.Cop.boolVal (.Vint (1#32)) CC.tint memory = some true ∧
    CC.Cop.boolVal (.Vint (0#32)) CC.tuchar memory = some false := ⟨rfl,rfl,rfl⟩

/-- Actual numeric pre/post computation: the effective offset is zero after updating SP. -/
theorem execute (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) (k : CC.Cont) :
    InternalRun world 44
      (.State procedure Arm64CiliumCallerMemOffsetPrefix.afterIndex k e
        (Arm64CiliumCallerMemOffsetPrefix.resultEnv le) memory)
      (.State procedure .Sskip k e (resultEnv le) memory) := by
  apply internalRun_of_steps
  all_goals
    simp only [source,body_source,yes_source,finish_source,
      s_trusted_arm64_arm64_sim_xdp_46,s_trusted_arm64_arm64_sim_xdp_47,
      s_trusted_arm64_arm64_sim_xdp_48,s_trusted_arm64_arm64_sim_xdp_49,
      s_trusted_arm64_arm64_sim_xdp_50,s_trusted_arm64_arm64_sim_xdp_51,s_trusted_arm64_arm64_sim_xdp_52,
      steps,InternalPath,InternalState,CC.doStep,temp_type,
      int_value,flag,condition_type,unsigned_true,zero_int,one_int,zero_long,flat_read0,flat_read1,flat_read2,flat_read3,flat_read4,flat_read5,flat_read6,flat_read7,flat_read8,flat_read9,flat_read10,flat_read11,
      (bools memory).1,(bools memory).2.1,(bools memory).2.2,
      resultEnv,env12,env11,env10,env9,env8,env7,env6,env5,env4,env3,env2,env1,env0,
      ite_true,ite_false,Bool.false_eq_true,true_and,and_true,CC.E0,CC.Eapp,List.nil_append] <;> trivial

/-- Every temporary outside the twelve numeric assignments retains its incoming prefix value. -/
theorem temp_frame (le : CC.TempEnv) (id : CC.Ident)
    (h0 : id ≠ ___kprog_a64_mbo_imm)
    (h1 : id ≠ ___kprog_a64_mbo_index)
    (h2 : id ≠ _t'150)
    (h3 : id ≠ _t'151)
    (h4 : id ≠ ___kprog_a64_mbo_prepost)
    (h5 : id ≠ _t'152)
    (h6 : id ≠ ___kprog_a64_mbo_has_index)
    (h7 : id ≠ _t'153)
    (h8 : id ≠ ___kprog_a64_mbo_base)
    (h9 : id ≠ ___kprog_a64_mbo_result)
    (h10 : id ≠ ___a64_mbo_result)
    (h11 : id ≠ ___a64_store_off) :
    (resultEnv le).get id = (Arm64CiliumCallerMemOffsetPrefix.resultEnv le).get id := by
  unfold resultEnv env12 env11 env10 env9 env8 env7 env6 env5 env4 env3 env2 env1 env0
  rw [CC.PTree.gso ___a64_store_off id _ _ (Ne.symm h11),
    CC.PTree.gso ___a64_mbo_result id _ _ (Ne.symm h10),
    CC.PTree.gso ___kprog_a64_mbo_result id _ _ (Ne.symm h9),
    CC.PTree.gso ___kprog_a64_mbo_base id _ _ (Ne.symm h8),
    CC.PTree.gso _t'153 id _ _ (Ne.symm h7),
    CC.PTree.gso ___kprog_a64_mbo_has_index id _ _ (Ne.symm h6),
    CC.PTree.gso _t'152 id _ _ (Ne.symm h5),
    CC.PTree.gso ___kprog_a64_mbo_prepost id _ _ (Ne.symm h4),
    CC.PTree.gso _t'151 id _ _ (Ne.symm h3),
    CC.PTree.gso _t'150 id _ _ (Ne.symm h2),
    CC.PTree.gso ___kprog_a64_mbo_index id _ _ (Ne.symm h1),
    CC.PTree.gso ___kprog_a64_mbo_imm id _ _ (Ne.symm h0)]

/-- Actual pre/post=true and has-index=false make the effective store offset zero. -/
theorem values (le : CC.TempEnv) :
    (resultEnv le).get ___kprog_a64_mbo_prepost = some (CC.Val.Vint (1#32)) ∧
    (resultEnv le).get ___kprog_a64_mbo_has_index = some (CC.Val.Vint (0#32)) ∧
    (resultEnv le).get ___kprog_a64_mbo_base = some (CC.Val.Vlong (0#64)) ∧
    (resultEnv le).get ___a64_mbo_result = some (CC.Val.Vlong (0#64)) ∧
    (resultEnv le).get ___a64_store_off = some (CC.Val.Vlong (0#64)) := by
  unfold resultEnv env12 env11 env10 env9 env8 env7 env6 env5 env4 env3 env2 env1 env0
  refine ⟨?_,?_,?_,?_,?_⟩
  · rw [CC.PTree.gso ___a64_store_off ___kprog_a64_mbo_prepost _ _ (by decide +kernel),
      CC.PTree.gso ___a64_mbo_result ___kprog_a64_mbo_prepost _ _ (by decide +kernel),
      CC.PTree.gso ___kprog_a64_mbo_result ___kprog_a64_mbo_prepost _ _ (by decide +kernel),
      CC.PTree.gso ___kprog_a64_mbo_base ___kprog_a64_mbo_prepost _ _ (by decide +kernel),
      CC.PTree.gso _t'153 ___kprog_a64_mbo_prepost _ _ (by decide +kernel),
      CC.PTree.gso ___kprog_a64_mbo_has_index ___kprog_a64_mbo_prepost _ _ (by decide +kernel),
      CC.PTree.gso _t'152 ___kprog_a64_mbo_prepost _ _ (by decide +kernel),
      CC.PTree.gss]
  · rw [CC.PTree.gso ___a64_store_off ___kprog_a64_mbo_has_index _ _ (by decide +kernel),
      CC.PTree.gso ___a64_mbo_result ___kprog_a64_mbo_has_index _ _ (by decide +kernel),
      CC.PTree.gso ___kprog_a64_mbo_result ___kprog_a64_mbo_has_index _ _ (by decide +kernel),
      CC.PTree.gso ___kprog_a64_mbo_base ___kprog_a64_mbo_has_index _ _ (by decide +kernel),
      CC.PTree.gso _t'153 ___kprog_a64_mbo_has_index _ _ (by decide +kernel),
      CC.PTree.gss]
  · rw [CC.PTree.gso ___a64_store_off ___kprog_a64_mbo_base _ _ (by decide +kernel),
      CC.PTree.gso ___a64_mbo_result ___kprog_a64_mbo_base _ _ (by decide +kernel),
      CC.PTree.gso ___kprog_a64_mbo_result ___kprog_a64_mbo_base _ _ (by decide +kernel),
      CC.PTree.gss]
  · rw [CC.PTree.gso ___a64_store_off ___a64_mbo_result _ _ (by decide +kernel),
      CC.PTree.gss]
  · rw [CC.PTree.gss]

/-- Compose actual linked SP write, original prefix and numeric offset on the same derived memory. -/
theorem advance {m before : CC.Mem} (header : Arm64CiliumCallerHeaderSource.Header m) (sources : Arm64CiliumCallerHeaderSource.Sources m) (scalars : Arm64CiliumCallerEntryScalars.Locals m)
    (access : before.access = (Arm64CiliumCallerLink.allocation m).2.access)
    (pointers : Arm64CiliumCallerHeaderSequence.Initialized header sources before 12)
    (reads : ∀ i : Fin 2,CC.Mem.load (Arm64CiliumCallerEntryScalars.chunk i)
      before (scalars.block i) 0 = some (Arm64CiliumCallerEntryScalars.value i))
    (le : CC.TempEnv) (k : CC.Cont) :
    ∃ result : Arm64CiliumCallerSPWriteMemory.Store (before := before) header sources scalars,
      InternalRun Arm64CiliumCallerLinkedProgram.ge 131
        (.State procedure Arm64CiliumCallerSPAlignment.tail
          (.Kloop1 Arm64CiliumCallerSPAlignment.body .Sbreak (.Kseq Arm64CiliumCallerMemOffsetPrefix.stage k))
          (Arm64CiliumCallerLink.allocation m).1 le before)
        (.State procedure .Sskip (.Kloop1 Arm64CiliumCallerMemOffsetPrefix.body .Sbreak (.Kseq Arm64CiliumCallerMemOffsetPrefix.rest k)) (Arm64CiliumCallerLink.allocation m).1
          (resultEnv (Arm64CiliumCallerSPPreindex.resultEnv le)) result.after) ∧
      Arm64EntryMemory.borrowed result.after.nextblock .Mint64 result.after (.Vptr header.block 0)
        Arm64Program._sp = some (.Vlong Arm64CiliumCallerSPPreindex.delta) := by
  obtain ⟨result,run,read⟩ := Arm64CiliumCallerMemOffsetPrefix.advance
    header sources scalars access pointers reads le k
  have numeric := execute Arm64CiliumCallerLinkedProgram.ge (Arm64CiliumCallerLink.allocation m).1
    (Arm64CiliumCallerSPPreindex.resultEnv le) result.after
    (.Kloop1 Arm64CiliumCallerMemOffsetPrefix.body .Sbreak
      (.Kseq Arm64CiliumCallerMemOffsetPrefix.rest k))
  exact ⟨result,run.trans numeric,read⟩

end KProgFormal.ClightRefinement.Arm64CiliumCallerMemOffset
