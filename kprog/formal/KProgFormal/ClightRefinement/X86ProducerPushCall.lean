import KProgFormal.ClightRefinement.X86ProducerEntryReady

namespace KProgFormal.ClightRefinement.X86ProducerPushCall
open X86ProducerHeaderSource (producer headerType)
open X86ProducerHeaderLocals (HeaderLocal)
open X86ProducerCacheAllocation (allocation)
open X86ProducerLayout (ge)

def handler : CC.Function := X86_program_profile_bpf.f___x86_instruction_X86_OP_PUSH

def argumentTypes : List CC.Ty := [CC.tptr headerType, CC.tuchar, CC.tuchar, CC.tuchar, CC.tuint, CC.tulong]
def expression : CC.Expr := .Evar X86_program_profile_bpf.___x86_instruction_X86_OP_PUSH
  (.Tfunction argumentTypes CC.tvoid CC.cc_default)
def argumentExpressions : List CC.Expr :=
  [.Eaddrof (.Evar X86_program_profile_bpf.___x86_inline_bindings headerType) (CC.tptr headerType),
    .Econst_int (CC.Integers.Int.repr 255) CC.tuint, .Econst_int (CC.Integers.Int.repr 3) CC.tuint,
    .Econst_int (CC.Integers.Int.repr 8) CC.tuint, .Econst_int (CC.Integers.Int.repr 0) CC.tint,
    .Ecast (.Econst_int (CC.Integers.Int.repr 0) CC.tint) CC.tulong]
def values (binding : CC.Block) : List CC.Val :=
  [.Vptr binding 0, .Vint (255#32), .Vint (3#32), .Vint (8#32), .Vint 0, .Vlong 0]
def continuation (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) : CC.Cont :=
  .Kcall none producer e le (.Kseq X86ProducerContextSource.followingCalls k)

/-- The real first instruction is the original PUSH wrapper call, with every
original expression and its unconsumed following-call continuation. -/
theorem source_call : X86ProducerBindLoop.firstCall = .Scall none expression argumentExpressions := by rfl

private def handlerIndex : Nat := by
  run_tac do
    let mut rows ← Lean.Elab.Term.elabTerm (← `(X86_program_profile_bpf.global_definitions)) none
    let mut index := 0
    while true do
      let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf rows)
      unless node.isAppOfArity ``List.cons 3 do throwError "original PUSH global definition missing"
      let row ← Lean.Meta.withTransparency .all (Lean.Meta.whnf node.getAppArgs[1]!)
      unless row.isAppOfArity ``Prod.mk 4 do throwError "original PUSH global row changed"
      if row.getAppArgs[2]!.isConstOf ``X86_program_profile_bpf.___x86_instruction_X86_OP_PUSH then
        Lean.Elab.Tactic.closeMainGoal `original_x86_push_index (Lean.mkNatLit index)
        return
      rows := node.getAppArgs[2]!
      index := index + 1

def handlerBlock : CC.Block := CC.Positive.ofNat (handlerIndex + 1)

/-- Both symbol and internal function come from the SAME complete original
exported world; no callee-binding premise or copied function is used. -/
theorem handler_binding :
    CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf.___x86_instruction_X86_OP_PUSH = some handlerBlock ∧
    CC.Genv.findFunctPtr ge.genv_genv handlerBlock = some (.Internal handler) := by
  constructor <;> run_tac do
    let goal ← Lean.Elab.Tactic.getMainGoal
    let target ← Lean.Meta.whnfR (← Lean.instantiateMVars (← goal.getType))
    unless target.isAppOfArity ``Eq 3 do throwError "expected real PUSH binding equality"
    goal.assign (← Lean.Meta.mkEqRefl target.getAppArgs[2]!)
    Lean.Elab.Tactic.replaceMainGoal []

/-- The current actual header-local binding suffices to evaluate every real
argument and unsigned-byte/word cast, with no temporary or memory assumption. -/
theorem arguments (before memory : CC.Mem) (le : CC.TempEnv) (entry : HeaderLocal ge.genv_cenv before) :
    CC.doEvalExprlist ge (allocation ge.genv_cenv before).1 le memory argumentExpressions argumentTypes = some (values entry.block) := by
  simp only [argumentExpressions, argumentTypes, values, CC.doEvalExprlist, CC.doEvalExpr,
    CC.doEvalLvalue, CC.lvalOfVar, entry.binding, CC.typeof]
  rfl

/-- Real call evaluation reaches the original PUSH Callstate on the SAME
heap/temporaries and actual original continuation. -/
theorem call (before memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) (entry : HeaderLocal ge.genv_cenv before) :
    InternalRun ge 1
      (.State producer X86ProducerBindLoop.firstCall (.Kseq X86ProducerContextSource.followingCalls k)
        (allocation ge.genv_cenv before).1 le memory)
      (.Callstate (.Internal handler) (values entry.block) (continuation (allocation ge.genv_cenv before).1 le k) memory) := by
  have allocated := CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation ge.genv_cenv before)).symm
  have absent : X86_program_profile_bpf.___x86_instruction_X86_OP_PUSH ∉ CC.varNames producer.fn_vars := by decide +kernel
  have notLocal : (allocation ge.genv_cenv before).1.get X86_program_profile_bpf.___x86_instruction_X86_OP_PUSH = none := by
    simpa only [CC.emptyEnv, CC.PTree.gempty] using CC.allocVariables_env_other allocated absent
  have function : CC.doEvalExpr ge (allocation ge.genv_cenv before).1 le memory expression = some (.Vptr handlerBlock 0) := by
    simp only [expression, CC.doEvalExpr, CC.lvalOfVar, notLocal, handler_binding.1, CC.doDerefLoc, CC.accessMode]
    rfl
  rw [source_call]
  refine .step trivial ?_ (.refl _)
  apply CC.Step.call (tyargs := argumentTypes) (tyres := CC.tvoid) (cconv := CC.cc_default) (vf := .Vptr handlerBlock 0)
  · rfl
  · exact CC.doEvalExpr_sound _ _ _ _ _ _ function
  · exact CC.doEvalExprlist_sound _ _ _ _ _ _ _ (arguments before memory le entry)
  · have zeroOffset : CC.Integers.Ptrofs.eq (0 : CC.Integers.Ptrofs) CC.Integers.Ptrofs.zero = true := rfl
    simpa only [CC.Genv.findFunct, zeroOffset, ite_true] using handler_binding.2
  · rfl

def initialTemps (binding : CC.Block) : CC.TempEnv :=
  ((((((CC.createUndefTemps handler.fn_temps).set X86_program_profile_bpf.___x86_bind (.Vptr binding 0)).set
    X86_program_profile_bpf._dst (.Vint (255#32))).set X86_program_profile_bpf._src (.Vint (3#32))).set
    X86_program_profile_bpf._flags (.Vint (8#32))).set X86_program_profile_bpf._aux (.Vint 0)).set
    X86_program_profile_bpf._imm (.Vlong 0)

/-- The actual wrapper's empty local list preserves the complete heap through
its genuine function entry; original parameter binding is retained. -/
theorem entry (memory : CC.Mem) (k : CC.Cont) (binding : CC.Block) :
    InternalRun ge 1 (.Callstate (.Internal handler) (values binding) k memory)
      (.State handler handler.fn_body k CC.emptyEnv (initialTemps binding) memory) := by
  have entered : CC.FunctionEntry2 ge handler (values binding) memory CC.emptyEnv (initialTemps binding) memory :=
    .intro (by decide +kernel) (by decide +kernel) (by decide +kernel) (.nil _ _) rfl
  exact .step trivial (.internal_function _ _ _ _ _ _ _ entered) (.refl _)

end KProgFormal.ClightRefinement.X86ProducerPushCall
