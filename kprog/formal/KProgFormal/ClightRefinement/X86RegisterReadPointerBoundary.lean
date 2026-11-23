import KProgFormal.ClightRefinement.X86RegisterReadLanes

namespace KProgFormal.ClightRefinement.X86RegisterReadPointerBoundary

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source (some (← Lean.Elab.Tactic.getMainTarget))
  Lean.Elab.Term.synthesizeSyntheticMVarsNoPostponing
  Lean.Elab.Tactic.closeMainGoal `actual_x86_reader_pointer_boundary
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.instantiateMVars term)))

private def tests : CC.Stmt := by
  run_tac cachePart (← `(match X86RegisterReadTag.lanes with
    | .Ssequence first _ => first | _ => .Sskip))
def assignment : CC.Stmt := by
  run_tac cachePart (← `(match X86RegisterReadTag.lanes with
    | .Ssequence _ last => last | _ => .Sskip))

theorem source : X86RegisterReadTag.lanes = .Ssequence tests assignment := rfl

def prepared (le : CC.TempEnv) : CC.TempEnv :=
  (((le.set X86_program_profile_bpf._t'4 (.Vint (0#32))).set
    X86_program_profile_bpf._t'5 (.Vlong X86.Size.q.mask)).set
    X86_program_profile_bpf._t'5 (.Vlong X86.Size.q.mask)).set
    X86_program_profile_bpf._t'5 (.Vlong X86.Size.q.mask)

/-- The actual qword selectors reach the original shift/mask assignment
in16 steps without inspecting the raw input word. -/
theorem qword_prefix (ge : CC.CGenv) (e : CC.Env) (le : CC.TempEnv)
    (k : CC.Cont) (m : CC.Mem)
    (width : le.get X86_program_profile_bpf.___x86_rd_width = some (X86ShiftLeft.argument .q)) :
    InternalRun ge 16
      (.State X86_program_profile_bpf.f_x86_sim_inline_read_reg X86RegisterReadTag.lanes k e le m)
      (.State X86_program_profile_bpf.f_x86_sim_inline_read_reg assignment k e (prepared le) m) := by
  rw [source]
  apply internalRun_of_steps
  all_goals
    simp +decide [steps, InternalPath, InternalState, CC.doStep, tests, prepared,
      X86_program_profile_bpf.s_x86_sim_inline_read_reg_5,
      CC.doEvalExpr, CC.typeof, width, X86ShiftLeft.argument, X86.Size.bytes, X86.Size.mask,
      CC.PTree.gss, CC.PTree.gso, CC.Cop.semBinaryOperation, CC.Cop.semCmp,
      CC.Cop.classifyCmp, CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
      CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
      CC.Cop.boolVal, CC.Cop.classifyBool, CC.typeconv, CC.removeAttributes, CC.tattr,
      CC.tuchar, CC.tuint, CC.tint, CC.tulong,
      CC.Integers.Int.eq, CC.Integers.MI.eq,
      CC.Integers.Int.zero, CC.Integers.MI.zero,
      CC.Integers.Int.repr, CC.Integers.Int64.repr, CC.Integers.MI.repr,
      CC.Val.ofBool, CC.Val.Vfalse, CC.Eapp, CC.E0]

/-- At this actual source statement, the current imported Clight interpreter
has no successor for a pointer-valued raw word, even with zero shift. -/
theorem pointer_assignment (ge : CC.CGenv) (e : CC.Env) (le : CC.TempEnv)
    (k : CC.Cont) (m : CC.Mem) (block : CC.Block) (offset : CC.Integers.Ptrofs)
    (word : le.get X86_program_profile_bpf.___x86_rd_value = some (.Vptr block offset)) :
    CC.doStep ge (.State X86_program_profile_bpf.f_x86_sim_inline_read_reg
      assignment k e (prepared le) m) = none := by
  have wordReady : (prepared le).get X86_program_profile_bpf.___x86_rd_value =
      some (.Vptr block offset) := by
    simp +decide [prepared, CC.PTree.gso, word]
  have shiftReady : (prepared le).get X86_program_profile_bpf._t'4 = some (.Vint (0#32)) := by
    simp +decide [prepared, CC.PTree.gss, CC.PTree.gso]
  simp only [CC.doStep, assignment, CC.doEvalExpr, wordReady, shiftReady, CC.typeof,
    CC.Cop.semBinaryOperation, CC.Cop.semShr, CC.Cop.semShift, CC.Cop.classifyShift,
    CC.typeconv, CC.removeAttributes, CC.tattr, CC.tulong, CC.tuint]

/-- This is also a boundary of the relational Clight semantics, rather than
only a missing case of its executable interpreter. -/
theorem pointer_no_step (ge : CC.CGenv) (e : CC.Env) (le : CC.TempEnv)
    (k : CC.Cont) (m : CC.Mem) (block : CC.Block) (offset : CC.Integers.Ptrofs)
    (word : le.get X86_program_profile_bpf.___x86_rd_value = some (.Vptr block offset))
    (trace : CC.Trace) (next : CC.State) :
    ¬ CC.Step2 ge (.State X86_program_profile_bpf.f_x86_sim_inline_read_reg
      assignment k e (prepared le) m) trace next := by
  have wordReady : (prepared le).get X86_program_profile_bpf.___x86_rd_value =
      some (.Vptr block offset) := by
    simp +decide [prepared, CC.PTree.gso, word]
  intro step
  change CC.Step ge (CC.FunctionEntry2 ge) _ _ _ at step
  simp only [assignment] at step
  cases step with
  | set _ _ _ _ _ _ _ _ evaluated =>
    cases evaluated with
    | Ebinop _ _ _ _ _ _ _ left _ _ =>
      cases left with
      | Ebinop _ _ _ _ _ _ _ raw _ operation =>
        cases raw with
        | Etempvar _ _ _ observed =>
          rw [wordReady] at observed
          cases observed
          simp only [CC.typeof, CC.Cop.semBinaryOperation, CC.Cop.semShr,
            CC.Cop.semShift, CC.Cop.classifyShift, CC.typeconv,
            CC.removeAttributes, CC.tattr, CC.tulong, CC.tuint] at operation
          cases operation
        | Elvalue _ _ _ _ _ location _ => cases location
      | Elvalue _ _ _ _ _ location _ => cases location
    | Elvalue _ _ _ _ _ location _ => cases location
  | skip_or_continue_loop1 =>
    rename_i impossible
    rcases impossible with h | h <;> cases h
  | skip_break_switch =>
    rename_i impossible
    rcases impossible with h | h <;> cases h

/-- Existing pointer origins can represent the input's native bits, but
the actual qword lane source still reaches the interpreter boundary above.
An address-projection argument is needed to extend the scalar-reader domain. -/
theorem pointer_boundary (ge : CC.CGenv) (e : CC.Env) (le : CC.TempEnv)
    (k : CC.Cont) (m : CC.Mem) (block : CC.Block) (offset : CC.Integers.Ptrofs)
    (addresses : Arm64Registers.PointerOrigins) (base : BitVec 64)
    (origin : addresses block = some base)
    (width : le.get X86_program_profile_bpf.___x86_rd_width = some (X86ShiftLeft.argument .q))
    (word : le.get X86_program_profile_bpf.___x86_rd_value = some (.Vptr block offset)) :
    Arm64Registers.ValueRep addresses (.Vptr block offset) (base + offset.setWidth 64) ∧
    ∃ stopped, InternalRun ge 16
      (.State X86_program_profile_bpf.f_x86_sim_inline_read_reg X86RegisterReadTag.lanes k e le m)
      stopped ∧ CC.doStep ge stopped = none ∧
        ∀ trace next, ¬ CC.Step2 ge stopped trace next := by
  refine ⟨⟨base, origin, rfl⟩, _, qword_prefix ge e le k m width,
    pointer_assignment ge e le k m block offset word, ?_⟩
  exact fun trace next => pointer_no_step ge e le k m block offset word trace next

end KProgFormal.ClightRefinement.X86RegisterReadPointerBoundary
