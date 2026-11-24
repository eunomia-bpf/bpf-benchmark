import KProgFormal.ClightRefinement.X86ProducerPushDispatch

namespace KProgFormal.ClightRefinement.X86ProducerPushBody
open X86ProducerLayout (ge)

def handler : CC.Function := X86_program_profile_bpf.f_x86_sim_inline_arm_DISP_PUSH
def allocation (memory : CC.Mem) : CC.Env × CC.Mem := CC.doAllocVariables ge.genv_cenv CC.emptyEnv memory handler.fn_vars
def initialTemps (binding : CC.Block) : CC.TempEnv :=
  ((((((((CC.createUndefTemps handler.fn_temps).set X86_program_profile_bpf.___x86_bind (.Vptr binding 0)).set
    X86_program_profile_bpf._op (.Vint (18#32))).set X86_program_profile_bpf._dst (.Vint (255#32))).set
    X86_program_profile_bpf._src (.Vint (3#32))).set X86_program_profile_bpf._flags (.Vint (8#32))).set
    X86_program_profile_bpf._aux (.Vint 0)).set X86_program_profile_bpf._imm (.Vlong 0)).set
    X86_program_profile_bpf._width (.Vint (8#32))

def continuation (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) : CC.Cont :=
  .Kcall none X86ProducerPushCall.handler CC.emptyEnv
    (X86ProducerPushDispatch.certificate binding k memory).output
    (X86ProducerPushDispatch.certificate binding k memory).continuation

private def handlerIndex : Nat := by
  run_tac do
    let mut rows ← Lean.Elab.Term.elabTerm (← `(X86_program_profile_bpf.global_definitions)) none
    let mut index := 0
    while true do
      let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf rows)
      unless node.isAppOfArity ``List.cons 3 do throwError "original DISP_PUSH global definition missing"
      let row ← Lean.Meta.withTransparency .all (Lean.Meta.whnf node.getAppArgs[1]!)
      unless row.isAppOfArity ``Prod.mk 4 do throwError "original DISP_PUSH global row changed"
      if row.getAppArgs[2]!.isConstOf ``X86_program_profile_bpf._x86_sim_inline_arm_DISP_PUSH then
        Lean.Elab.Tactic.closeMainGoal `original_x86_push_body_index (Lean.mkNatLit index)
        return
      rows := node.getAppArgs[2]!
      index := index + 1

def handlerBlock : CC.Block := CC.Positive.ofNat (handlerIndex + 1)

/-- The actual body binding is proved in the original complete producer world. -/
theorem handler_binding :
    CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_sim_inline_arm_DISP_PUSH = some handlerBlock ∧
    CC.Genv.findFunctPtr ge.genv_genv handlerBlock = some (.Internal handler) := by
  constructor <;> run_tac do
    let goal ← Lean.Elab.Tactic.getMainGoal
    let target ← Lean.Meta.whnfR (← Lean.instantiateMVars (← goal.getType))
    unless target.isAppOfArity ``Eq 3 do throwError "expected actual PUSH body binding equality"
    goal.assign (← Lean.Meta.mkEqRefl target.getAppArgs[2]!)
    Lean.Elab.Tactic.replaceMainGoal []

/-- Real target/argument evaluation enters the selected body with its original
continuation and unchanged complete caller memory. -/
theorem call (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) :
    InternalRun ge 1
      (.State X86ProducerPushCall.handler X86ProducerPushDispatch.targetCall
        (X86ProducerPushDispatch.certificate binding k memory).continuation CC.emptyEnv
        (X86ProducerPushDispatch.certificate binding k memory).output memory)
      (.Callstate (.Internal handler) (X86ProducerPushDispatch.values binding) (continuation binding k memory) memory) := by
  have function : CC.doEvalExpr ge CC.emptyEnv (X86ProducerPushDispatch.certificate binding k memory).output memory
      X86ProducerPushDispatch.expression = some (.Vptr handlerBlock 0) := by
    simp only [X86ProducerPushDispatch.expression, CC.doEvalExpr, CC.lvalOfVar, CC.emptyEnv,
      CC.PTree.gempty, handler_binding.1, CC.doDerefLoc, CC.accessMode]
    rfl
  rw [X86ProducerPushDispatch.target_source]
  refine .step trivial ?_ (.refl _)
  apply CC.Step.call (tyargs := X86ProducerPushDispatch.argumentTypes) (tyres := CC.tvoid)
    (cconv := CC.cc_default) (vf := .Vptr handlerBlock 0)
  · rfl
  · exact CC.doEvalExpr_sound _ _ _ _ _ _ function
  · exact CC.doEvalExprlist_sound _ _ _ _ _ _ _ (X86ProducerPushDispatch.arguments binding k memory)
  · have zeroOffset : CC.Integers.Ptrofs.eq (0 : CC.Integers.Ptrofs) CC.Integers.Ptrofs.zero = true := rfl
    simpa only [CC.Genv.findFunct, zeroOffset, ite_true] using handler_binding.2
  · rfl

private theorem declarations : CC.listNorepet (CC.varNames handler.fn_vars) ∧
    CC.listNorepet (CC.varNames handler.fn_params) ∧
    CC.listDisjoint (CC.varNames handler.fn_params) (CC.varNames handler.fn_temps) := by decide +kernel

theorem allocation_valid (memory : CC.Mem) : CC.AllocVariables ge.genv_cenv CC.emptyEnv memory handler.fn_vars
    (allocation memory).1 (allocation memory).2 := CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation memory)).symm

/-- Genuine body function entry allocates its three original locals and binds
all eight original parameters; it does not start after an assumed allocation. -/
theorem entry (memory : CC.Mem) (k : CC.Cont) (binding : CC.Block) :
    InternalRun ge 1 (.Callstate (.Internal handler) (X86ProducerPushDispatch.values binding) k memory)
      (.State handler handler.fn_body k (allocation memory).1 (initialTemps binding) (allocation memory).2) := by
  have entered : CC.FunctionEntry2 ge handler (X86ProducerPushDispatch.values binding) memory
      (allocation memory).1 (initialTemps binding) (allocation memory).2 :=
    .intro declarations.1 declarations.2.1 declarations.2.2 (allocation_valid memory) rfl
  exact .step trivial (.internal_function _ _ _ _ _ _ _ entered) (.refl _)

/-- The real allocation frames every old raw byte and Cur/Max permission,
while its actual frontier may advance. -/
theorem entry_frame (memory : CC.Mem) : memory.nextblock.toNat ≤ (allocation memory).2.nextblock.toNat ∧
    FrameBelow memory.nextblock memory (allocation memory).2 :=
  FrameBelow.allocVariables (allocation_valid memory) _ (Nat.le_refl _)

private theorem local_size : handler.fn_vars.length = 3 := rfl
def localDecl (i : Fin 3) : CC.Ident × CC.Ty := handler.fn_vars[i.val]'(by rw [local_size]; exact i.isLt)
def localName (i : Fin 3) : CC.Ident := (localDecl i).1
def localType (i : Fin 3) : CC.Ty := (localDecl i).2

structure Local (memory : CC.Mem) (i : Fin 3) where
  block : CC.Block
  binding : (allocation memory).1.get (localName i) = some (block, localType i)
  fresh : memory.nextblock.toNat ≤ block.toNat
  owned : block.toNat < (allocation memory).2.nextblock.toNat
  range : CC.Mem.rangePerm (allocation memory).2 block 0 (CC.sizeof ge.genv_cenv (localType i)) .Cur .Freeable = true

private theorem declared : ∀ i : Fin 3, (localName i, localType i) ∈ handler.fn_vars := by decide +kernel

/-- All three original local declarations obtain actual allocated bindings,
freshness/ownership and full declared-range rights from the SAME function entry. -/
theorem local_storage (memory : CC.Mem) (i : Fin 3) : Nonempty (Local memory i) := by
  obtain ⟨block, binding⟩ := allocated_local_binding (allocation_valid memory) declarations.1 (declared i)
  obtain ⟨fresh, owned, range⟩ := (allocated_local_storage (allocation_valid memory)).1 _ _ binding
  exact ⟨⟨block, binding, fresh, owned, range⟩⟩

end KProgFormal.ClightRefinement.X86ProducerPushBody
