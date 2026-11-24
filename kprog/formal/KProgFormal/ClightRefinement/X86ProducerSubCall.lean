import KProgFormal.ClightRefinement.X86ProducerEntryReady

namespace KProgFormal.ClightRefinement.X86ProducerSubCall
open X86ProducerHeaderSource (producer headerType)
open X86ProducerHeaderLocals (HeaderLocal)
open X86ProducerCacheAllocation (allocation)
open X86ProducerLayout (ge)

private structure Site where
  call : CC.Stmt
  tail : CC.Stmt

private def site : Site := by
  run_tac do
    let sequence ← Lean.Meta.withTransparency .all (Lean.Meta.whnf
      (← Lean.Elab.Term.elabTerm (← `(X86ProducerContextSource.followingCalls)) none))
    unless sequence.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original next source sequence changed"
    let label ← Lean.Meta.withTransparency .all (Lean.Meta.whnf sequence.getAppArgs[0]!)
    unless label.isAppOfArity ``CC.Stmt.Slabel 2 do throwError "original next source label changed"
    Lean.Elab.Tactic.closeMainGoal `original_sub_source_site
      (← Lean.Meta.mkAppM ``Site.mk #[label.getAppArgs[1]!,sequence.getAppArgs[1]!])

def callStmt : CC.Stmt := site.call
def followingCalls : CC.Stmt := site.tail

/-- The actual original label1 call and every unconsumed following statement. -/
theorem source_site : X86ProducerContextSource.followingCalls =
    .Ssequence (.Slabel X86_program_profile_bpf._x86_l_1 callStmt) followingCalls := by rfl

def handler : CC.Function := X86_program_profile_bpf.f___x86_instruction_X86_OP_ALU_IMM

def argumentTypes : List CC.Ty := [CC.tptr headerType, CC.tuchar, CC.tuchar, CC.tuchar, CC.tuint, CC.tulong]
def expression : CC.Expr := .Evar X86_program_profile_bpf.___x86_instruction_X86_OP_ALU_IMM
  (.Tfunction argumentTypes CC.tvoid CC.cc_default)
def argumentExpressions : List CC.Expr :=
  [.Eaddrof (.Evar X86_program_profile_bpf.___x86_inline_bindings headerType) (CC.tptr headerType),
    .Econst_int (CC.Integers.Int.repr 4) CC.tuint, .Econst_int (CC.Integers.Int.repr 255) CC.tuint,
    .Econst_int (CC.Integers.Int.repr 8) CC.tuint, .Econst_int (CC.Integers.Int.repr 1) CC.tuint,
    .Ecast (.Econst_long (CC.Integers.Int64.repr 32) CC.tulong) CC.tulong]
def values (binding : CC.Block) : List CC.Val :=
  [.Vptr binding 0, .Vint (4#32), .Vint (255#32), .Vint (8#32), .Vint (1#32), .Vlong (32#64)]
def continuation (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) : CC.Cont :=
  .Kcall none producer e le (.Kseq followingCalls k)

/-- The real next instruction is the original SUB wrapper call, with every
original expression and its unconsumed following-call continuation. -/
theorem source_call : callStmt = .Scall none expression argumentExpressions := by rfl

private def handlerIndex : Nat := by
  run_tac do
    let mut rows ← Lean.Elab.Term.elabTerm (← `(X86_program_profile_bpf.global_definitions)) none
    let mut index := 0
    while true do
      let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf rows)
      unless node.isAppOfArity ``List.cons 3 do throwError "original SUB global definition missing"
      let row ← Lean.Meta.withTransparency .all (Lean.Meta.whnf node.getAppArgs[1]!)
      unless row.isAppOfArity ``Prod.mk 4 do throwError "original SUB global row changed"
      if row.getAppArgs[2]!.isConstOf ``X86_program_profile_bpf.___x86_instruction_X86_OP_ALU_IMM then
        Lean.Elab.Tactic.closeMainGoal `original_x86_sub_index (Lean.mkNatLit index)
        return
      rows := node.getAppArgs[2]!
      index := index + 1

def handlerBlock : CC.Block := CC.Positive.ofNat (handlerIndex + 1)

/-- Both symbol and internal function come from the SAME complete original
exported world; no callee-binding premise or copied function is used. -/
theorem handler_binding :
    CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf.___x86_instruction_X86_OP_ALU_IMM = some handlerBlock ∧
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

/-- Real call evaluation reaches the original SUB Callstate on the SAME
heap/temporaries and actual original continuation. -/
theorem call (before memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) (entry : HeaderLocal ge.genv_cenv before) :
    InternalRun ge 1
      (.State producer callStmt (.Kseq followingCalls k)
        (allocation ge.genv_cenv before).1 le memory)
      (.Callstate (.Internal handler) (values entry.block) (continuation (allocation ge.genv_cenv before).1 le k) memory) := by
  have allocated := CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation ge.genv_cenv before)).symm
  have absent : X86_program_profile_bpf.___x86_instruction_X86_OP_ALU_IMM ∉ CC.varNames producer.fn_vars := by decide +kernel
  have notLocal : (allocation ge.genv_cenv before).1.get X86_program_profile_bpf.___x86_instruction_X86_OP_ALU_IMM = none := by
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
    X86_program_profile_bpf._dst (.Vint (4#32))).set X86_program_profile_bpf._src (.Vint (255#32))).set
    X86_program_profile_bpf._flags (.Vint (8#32))).set X86_program_profile_bpf._aux (.Vint (1#32))).set
    X86_program_profile_bpf._imm (.Vlong (32#64))

/-- The actual wrapper's empty local list preserves the complete heap through
its genuine function entry; original parameter binding is retained. -/
theorem entry (memory : CC.Mem) (k : CC.Cont) (binding : CC.Block) :
    InternalRun ge 1 (.Callstate (.Internal handler) (values binding) k memory)
      (.State handler handler.fn_body k CC.emptyEnv (initialTemps binding) memory) := by
  have entered : CC.FunctionEntry2 ge handler (values binding) memory CC.emptyEnv (initialTemps binding) memory :=
    .intro (by decide +kernel) (by decide +kernel) (by decide +kernel) (.nil _ _) rfl
  exact .step trivial (.internal_function _ _ _ _ _ _ _ entered) (.refl _)

end KProgFormal.ClightRefinement.X86ProducerSubCall
