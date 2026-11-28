import KProgFormal.ClightRefinement.Arm64CiliumCallerSPPreindex

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerSPWriterCall
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure ge allocation)
open Arm64CiliumCallerHeaderSource (Header headerType)

noncomputable def types : List CC.Ty := [CC.tptr headerType,CC.tulong,CC.tptr CC.tvoid,CC.tuchar]
noncomputable def functionType : CC.Ty := .Tfunction types CC.tvoid CC.cc_default
noncomputable def callee : CC.FunDef := .External
  (.EF_external "kprog_arm64_program_write_pointer"
    (CC.mksignature [.Xptr,.Xlong,.Xptr,.Xint8unsigned] .Xvoid CC.cc_default))
  types CC.tvoid CC.cc_default
noncomputable def calleeExpr : CC.Expr := .Evar _kprog_arm64_program_write_pointer functionType
noncomputable def headerExpr : CC.Expr :=
  .Eaddrof (.Evar ___a64_entry headerType) (CC.tptr headerType)
noncomputable def payloadExpr : CC.Expr := .Ecast
  (.Ecast (.Ebinop .Oadd
    (.Ecast (.Etempvar _t'13900 CC.tlong) CC.tulong)
    (.Ecast (.Etempvar ___a64_l_pp CC.tlong) CC.tulong) CC.tulong) CC.tlong)
  (CC.tptr CC.tvoid)
noncomputable def argumentExprs : List CC.Expr :=
  [headerExpr,.Econst_int (32#32) CC.tuint,payloadExpr,.Econst_int (4#32) CC.tuint]
noncomputable def arguments (header : CC.Block) : List CC.Val :=
  [.Vptr header 0,.Vlong (32#64),.Vlong Arm64CiliumCallerSPPreindex.delta,.Vint (4#32)]

theorem call_source : Arm64CiliumCallerSPPreindex.call = .Scall none calleeExpr argumentExprs := rfl

private theorem resolved :
    (CC.Genv.findSymbol ge.genv_genv _kprog_arm64_program_write_pointer).bind
      (CC.Genv.findFunctPtr ge.genv_genv) = some callee := by
  run_tac do
    let goal ← Lean.Elab.Tactic.getMainGoal
    let target ← Lean.Meta.whnfR (← Lean.instantiateMVars (← goal.getType))
    goal.assign (← Lean.Meta.mkEqRefl target.getAppArgs[2]!)
    Lean.Elab.Tactic.replaceMainGoal []

/-- The unchanged original caller resolves to the actual external declaration. -/
theorem callee_lookup : ∃ b,
    CC.Genv.findSymbol ge.genv_genv _kprog_arm64_program_write_pointer = some b ∧
    CC.Genv.findFunctPtr ge.genv_genv b = some callee :=
  (Option.bind_eq_some_iff
    (x := CC.Genv.findSymbol ge.genv_genv _kprog_arm64_program_write_pointer)
    (f := CC.Genv.findFunctPtr ge.genv_genv) (b := callee)).mp resolved

theorem unshadowed (m : CC.Mem) :
    (allocation m).1.get _kprog_arm64_program_write_pointer = none := by
  have absent : _kprog_arm64_program_write_pointer ∉ CC.varNames procedure.fn_vars := by decide +kernel
  simpa only [CC.emptyEnv,CC.PTree.gempty] using
    CC.allocVariables_env_other (Arm64CiliumCallerLink.allocated m) absent

theorem header_value {m : CC.Mem} (header : Header m) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr ge (allocation m).1 le memory headerExpr = some (.Vptr header.block 0) := by
  simp only [headerExpr,CC.doEvalExpr,CC.doEvalLvalue,CC.lvalOfVar,header.binding,ite_true]
  rfl

theorem payload_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr ge e (Arm64CiliumCallerSPPreindex.resultEnv le) memory payloadExpr =
      some (.Vlong Arm64CiliumCallerSPPreindex.delta) := by
  have different : _t'13900 ≠ ___a64_l_pp := by decide +kernel
  have spRead : (Arm64CiliumCallerSPPreindex.resultEnv le).get _t'13900 =
      some (.Vlong (0#64)) := CC.PTree.gss _ _ _
  have ppRead : (Arm64CiliumCallerSPPreindex.resultEnv le).get ___a64_l_pp =
      some (.Vlong Arm64CiliumCallerSPPreindex.delta) := by
    unfold Arm64CiliumCallerSPPreindex.resultEnv
    rw [CC.PTree.gso _t'13900 ___a64_l_pp _ _ different]
    exact CC.PTree.gss _ _ _
  simp only [payloadExpr,CC.doEvalExpr,spRead,ppRead]
  rfl

private theorem reg_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr ge e le memory (.Econst_int (32#32) CC.tuint) = some (.Vint (32#32)) := rfl
private theorem tag_value (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr ge e le memory (.Econst_int (4#32) CC.tuint) = some (.Vint (4#32)) := rfl
private theorem argument_types :
    CC.typeof headerExpr = CC.tptr headerType ∧ CC.typeof payloadExpr = CC.tptr CC.tvoid ∧
    CC.typeof (.Econst_int (32#32) CC.tuint) = CC.tuint ∧
    CC.typeof (.Econst_int (4#32) CC.tuint) = CC.tuint := ⟨rfl,rfl,rfl,rfl⟩
private theorem cast_header (memory : CC.Mem) (b : CC.Block) :
    CC.Cop.semCast (.Vptr b 0) (CC.tptr headerType) (CC.tptr headerType) memory = some (.Vptr b 0) := rfl
private theorem cast_payload (memory : CC.Mem) :
    CC.Cop.semCast (.Vlong Arm64CiliumCallerSPPreindex.delta) (CC.tptr CC.tvoid) (CC.tptr CC.tvoid) memory =
      some (.Vlong Arm64CiliumCallerSPPreindex.delta) := rfl
private theorem cast_reg (memory : CC.Mem) :
    CC.Cop.semCast (.Vint (32#32)) CC.tuint CC.tulong memory = some (.Vlong (32#64)) := rfl
private theorem cast_tag (memory : CC.Mem) :
    CC.Cop.semCast (.Vint (4#32)) CC.tuint CC.tuchar memory = some (.Vint (4#32)) := rfl

/-- All four original arguments derive from actual bindings and reached temporaries. -/
theorem arguments_value {m : CC.Mem} (header : Header m) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExprlist ge (allocation m).1 (Arm64CiliumCallerSPPreindex.resultEnv le) memory
      argumentExprs types = some (arguments header.block) := by
  have actualHeader := header_value header (Arm64CiliumCallerSPPreindex.resultEnv le) memory
  simp only [argumentExprs,types,CC.doEvalExprlist,actualHeader,payload_value,reg_value,tag_value,
    argument_types.1,argument_types.2.1,argument_types.2.2.1,argument_types.2.2.2,
    cast_header,cast_payload,cast_reg,cast_tag,arguments]

private theorem callee_value {m : CC.Mem} (le : CC.TempEnv) (memory : CC.Mem) (b : CC.Block)
    (symbol : CC.Genv.findSymbol ge.genv_genv _kprog_arm64_program_write_pointer = some b) :
    CC.doEvalExpr ge (allocation m).1 le memory calleeExpr = some (.Vptr b 0) := by
  simp only [calleeExpr,CC.doEvalExpr,CC.lvalOfVar,unshadowed m,symbol]
  rfl
private theorem function_class :
    CC.Cop.classifyFun (CC.typeof calleeExpr) = .f types CC.tvoid CC.cc_default := rfl
private theorem callee_type : CC.typeOfFundef callee = .Tfunction types CC.tvoid CC.cc_default := rfl

/-- Resolve the original external call; no external execution or memory effect is assumed. -/
theorem call_ready {m : CC.Mem} (header : Header m) (le : CC.TempEnv)
    (memory : CC.Mem) (k : CC.Cont) :
    InternalRun ge 1
      (.State procedure Arm64CiliumCallerSPPreindex.call k (allocation m).1
        (Arm64CiliumCallerSPPreindex.resultEnv le) memory)
      (.Callstate callee (arguments header.block)
        (.Kcall none procedure (allocation m).1 (Arm64CiliumCallerSPPreindex.resultEnv le) k) memory) := by
  obtain ⟨block,symbol,function⟩ := callee_lookup
  have callable : CC.Genv.findFunct ge.genv_genv (.Vptr block 0) = some callee := by
    simpa [CC.Genv.findFunct,CC.Integers.Ptrofs.eq,CC.Integers.Ptrofs.zero,
      CC.Integers.MI.eq,CC.Integers.MI.zero] using function
  have target := callee_value (m := m) (Arm64CiliumCallerSPPreindex.resultEnv le) memory block symbol
  have actuals := arguments_value header le memory
  apply internalRun_of_steps
  all_goals
    simp only [steps,InternalPath,InternalState,CC.doStep,call_source,function_class,target,
      actuals,callable,callee_type,ite_true,eq_self,true_and,and_true,CC.E0,CC.Eapp,List.nil_append]

end KProgFormal.ClightRefinement.Arm64CiliumCallerSPWriterCall
