import KProgFormal.ClightRefinement.X86RegisterWriteRspReleaseAdvance

namespace KProgFormal.ClightRefinement.X86CallFrameEntry

def handler : CC.Function := X86_program_profile_bpf.f_x86_sim_inline_call_frame_values

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source (some (← Lean.Elab.Tactic.getMainTarget))
  Lean.Elab.Term.synthesizeSyntheticMVarsNoPostponing
  Lean.Elab.Tactic.closeMainGoal `actual_x86_call_frame_entry_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.instantiateMVars term)))

private def loopBody : CC.Stmt := by
  run_tac cachePart (← `(match handler.fn_body with | .Sloop body _ => body | _ => .Sskip))
private def reads : CC.Stmt := by
  run_tac cachePart (← `(match loopBody with | .Ssequence reads _ => reads | _ => .Sskip))
def afterSp : CC.Stmt := by
  run_tac cachePart (← `(match loopBody with | .Ssequence _ rest => rest | _ => .Sskip))

def continuation (k : CC.Cont) : CC.Cont := .Kloop1 loopBody .Sbreak k

def initialTemps (binding : CC.Val) : CC.TempEnv :=
  (CC.createUndefTemps handler.fn_temps).set X86_program_profile_bpf.___x86_bind binding

def temps (le : CC.TempEnv) (cells : CC.Block) (base : CC.Integers.Ptrofs) (sp : BitVec 64) : CC.TempEnv :=
  ((le.set X86_program_profile_bpf._t'13 (.Vptr cells base)).set
    X86_program_profile_bpf._t'14 (.Vlong sp)).set X86_program_profile_bpf.___x86_sv_sp (.Vlong sp)

private theorem declarations : CC.listNorepet (CC.varNames handler.fn_vars) ∧
    CC.listNorepet (CC.varNames handler.fn_params) ∧
    CC.listDisjoint (CC.varNames handler.fn_params) (CC.varNames handler.fn_temps) := by decide +kernel

/-- The exported frame helper retains all six guarded metadata-clearing arms. -/
theorem source : handler.fn_body = .Sloop (.Ssequence reads afterSp) .Sbreak := rfl

/-- The original frame helper binds its sole argument and allocates no locals. -/
theorem entry (ge : CC.CGenv) (memory : CC.Mem) (binding : CC.Val) :
    CC.FunctionEntry2 ge handler [binding] memory CC.emptyEnv (initialTemps binding) memory :=
  .intro declarations.1 declarations.2.1 declarations.2.2 (.nil _ _) rfl

/-- Genuine table/raw-RSP reads and the original casts derive the SP used by
all six metadata guards. The entire initial heap is retained. -/
theorem prefix_run (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (memory : CC.Mem)
    (binding cells : CC.Block) (base : CC.Integers.Ptrofs) (sp : BitVec 64)
    (bindingRead : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr binding 0))
    (header : CC.Mem.load CC.Mptr memory binding 0 = some (.Vptr cells base))
    (stackPointer : CC.Mem.load CC.Mptr memory cells
      (CC.Integers.Ptrofs.unsigned (CC.Integers.Ptrofs.add base (64#64))) = some (.Vlong sp)) :
    InternalRun ge 10 (.State handler handler.fn_body k e le memory)
      (.State handler afterSp (continuation k) e (temps le cells base sp) memory) := by
  have cellsField : CC.lvalOfField ge
      (.Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr)
      X86_program_profile_bpf._cells (.Vptr binding (0#64)) = some (binding, (0#64), .Full) :=
    X86RegisterReadValue.table_address ge layout binding (0 : CC.Integers.Ptrofs)
  have valueField := X86RegisterReadValue.value_address ge layout cells (CC.Integers.Ptrofs.add base (64#64))
  have ptrField := X86RegisterReadValue.pointer_address ge layout cells (CC.Integers.Ptrofs.add base (64#64))
  have zero : CC.Integers.Ptrofs.unsigned (0#64) = 0 := rfl
  have stride : (16#64) * BitVec.ofInt 64 (CC.Integers.MI.signed (CC.Integers.Int.repr 4)) = (64#64) := rfl
  dsimp only [CC.Integers.Ptrofs.add, CC.Integers.MI.add] at valueField ptrField stackPointer
  rw [source]
  apply internalRun_of_steps
  all_goals simp +decide [steps, InternalPath, InternalState, reads, continuation, temps,
    CC.doStep, CC.doEvalExpr, CC.doEvalLvalue, CC.doDerefLoc, CC.typeof,
    CC.PTree.gss, CC.PTree.gso, bindingRead, cellsField, valueField, ptrField, stride,
    CC.accessMode, CC.Mem.loadv, header, stackPointer, zero,
    CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.semAdd, CC.Cop.classifyAdd,
    CC.Cop.semBinaryOperation, CC.Cop.semAddPtrInt, CC.Cop.ptrofsOfInt,
    CC.Cop.castIntInt, CC.Cop.castIntLong, CC.typeconv, CC.removeAttributes, CC.tattr,
    CC.tint, CC.tuint, CC.tlong, CC.tptr, CC.tvoid, CC.Archi.ptr64_eq,
    CC.sizeof, layout.cell, X86RegisterLayout.layout.2.2.2.1,
    CC.Integers.Ptrofs.add, CC.Integers.Ptrofs.mul, CC.Integers.Ptrofs.repr, CC.Integers.Ptrofs.of_ints,
    CC.Integers.MI.add, CC.Integers.MI.mul, CC.Integers.MI.repr]
  all_goals rw (transparency := .all) [stride, valueField]
  all_goals dsimp only
  all_goals rw (transparency := .all) [ptrField]
  all_goals dsimp only
  all_goals rw (transparency := .all) [stackPointer]
  all_goals simp +decide [steps, InternalPath, InternalState, temps, continuation,
    CC.doStep, CC.doEvalExpr, CC.typeof, CC.PTree.gss, CC.PTree.gso,
    CC.Cop.semCast, CC.Cop.classifyCast, CC.Archi.ptr64_eq, CC.tptr, CC.tvoid, CC.tlong, CC.E0, CC.Eapp]
  all_goals rfl

/-- Real function entry and SP preparation compose to the original six-guard
body in11 transitions; no metadata-clearing result is assumed. -/
theorem call (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (k : CC.Cont) (memory : CC.Mem) (binding cells : CC.Block) (base : CC.Integers.Ptrofs) (sp : BitVec 64)
    (header : CC.Mem.load CC.Mptr memory binding 0 = some (.Vptr cells base))
    (stackPointer : CC.Mem.load CC.Mptr memory cells
      (CC.Integers.Ptrofs.unsigned (CC.Integers.Ptrofs.add base (64#64))) = some (.Vlong sp)) :
    InternalRun ge 11 (.Callstate (.Internal handler) [.Vptr binding 0] k memory)
      (.State handler afterSp (continuation k) CC.emptyEnv
        (temps (initialTemps (.Vptr binding 0)) cells base sp) memory) := by
  have entered : InternalRun ge 1 (.Callstate (.Internal handler) [.Vptr binding 0] k memory)
      (.State handler handler.fn_body k CC.emptyEnv (initialTemps (.Vptr binding 0)) memory) :=
    .step trivial (.internal_function _ _ _ _ _ _ _ (entry ge memory (.Vptr binding 0))) (.refl _)
  have bindingRead : (initialTemps (.Vptr binding 0)).get X86_program_profile_bpf.___x86_bind =
      some (.Vptr binding 0) := CC.PTree.gss _ _ _
  exact entered.trans (prefix_run ge layout CC.emptyEnv (initialTemps (.Vptr binding 0)) k memory
    binding cells base sp bindingRead header stackPointer)

end KProgFormal.ClightRefinement.X86CallFrameEntry
