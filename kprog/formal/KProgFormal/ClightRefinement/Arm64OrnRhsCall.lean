import KProgFormal.ClightRefinement.Arm64OrnReadEntry
import KProgFormal.ClightRefinement.Arm64ModifiedLslOneCall

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64Orn.RhsCall

private structure Pieces where
  call : CC.Stmt
  readSet : CC.Stmt
  tail : CC.Stmt

private def pieces : Pieces := by
  run_tac do
    let peel (term : Lean.Expr) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "actual ORN RHS sequence changed"
      pure actual.getAppArgs
    let root ← peel (← Lean.Elab.Term.elabTerm (← `(ReadEntry.rhs)) none)
    let read ← peel root[0]!
    Lean.Elab.Tactic.closeMainGoal `actual_orn_rhs_call
      (← Lean.Meta.mkAppM ``Pieces.mk #[read[0]!,read[1]!,root[1]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_orn_rhs_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private def modifiedCall : CC.Stmt := by run_tac cachePart (← `(pieces.call))
private def readSet : CC.Stmt := by run_tac cachePart (← `(pieces.readSet))
def tail : CC.Stmt := by run_tac cachePart (← `(pieces.tail))

/-- The original RHS helper call, copy and untouched width/numeric suffix. -/
theorem source : ReadEntry.rhs = .Ssequence (.Ssequence modifiedCall readSet) tail := rfl

def callCont (k : CC.Cont) (e : CC.Env) (le : CC.TempEnv) : CC.Cont :=
  .Kcall (some Arm64Program._t'138) Arm64Nop.handler e le (.Kseq readSet (.Kseq tail k))

private def target : CC.Expr := by
  run_tac do
    let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf
      (← Lean.Elab.Term.elabTerm (← `(modifiedCall)) none))
    unless actual.isAppOfArity ``CC.Stmt.Scall 3 do throwError "actual modified call changed"
    Lean.Elab.Tactic.closeMainGoal `actual_modified_target actual.getAppArgs[1]!
private def actualArgs : List CC.Expr := by
  run_tac do
    let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf
      (← Lean.Elab.Term.elabTerm (← `(modifiedCall)) none))
    unless actual.isAppOfArity ``CC.Stmt.Scall 3 do throwError "actual modified call changed"
    Lean.Elab.Tactic.closeMainGoal `actual_modified_args actual.getAppArgs[2]!
private def parameterTypes : List CC.Ty :=
  [CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr), CC.tulong, CC.tuchar, CC.tuchar, CC.tuchar]
private theorem call_source : modifiedCall = .Scall (some Arm64Program._t'138) target actualArgs := rfl
private theorem target_type : CC.Cop.classifyFun (CC.typeof target) =
    .f parameterTypes CC.tulong CC.cc_default := rfl
private theorem function_type : CC.typeOfFundef (.Internal Arm64Program.f_kprog_arm64_program_modified) =
    .Tfunction parameterTypes CC.tulong CC.cc_default := rfl

/-- Decode the actual packed AUX expression and retain each original argument cast. -/
private theorem args_eval (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (b : CC.Block) (ofs : CC.Integers.Ptrofs) (source : BitVec 64)
    (entry : le.get Arm64Program._entry = some (.Vptr b ofs))
    (src : le.get Arm64Program._src2 = some (.Vlong source))
    (aux : le.get Arm64Program._aux = some (.Vint (65792#32)))
    (effective : le.get Arm64Program.___a64_l_width = some (Arm64Compare.RhsCall.width true)) :
    CC.doEvalExprlist world e le m actualArgs parameterTypes = some (Arm64Modified.LslOne.arguments b ofs source) := by
  simp +decide only [actualArgs, parameterTypes, Arm64Modified.LslOne.arguments, Arm64Compare.RhsCall.width, Arm64Compare.Dispatch.flags, Arm64Width.argument,
      CC.doEvalExprlist, CC.doEvalExpr, CC.typeof, entry, src, aux, effective,
      CC.Cop.semBinaryOperation, CC.Cop.semAnd, CC.Cop.semShr, CC.Cop.semShift, CC.Cop.classifyShift,
      CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType, CC.Cop.semCast,
      CC.Cop.classifyCast, CC.Cop.castIntInt, CC.Cop.castIntLong, CC.typeconv, CC.removeAttributes,
      CC.tattr, CC.tuint, CC.tint, CC.tuchar, CC.tulong, CC.tptr, CC.Archi.ptr64] <;> rfl

private theorem call_step (world : CC.CGenv) (block b : CC.Block) (ofs : CC.Integers.Ptrofs)
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (source : BitVec 64)
    (binding : CC.Genv.findSymbol world.genv_genv Arm64Program._kprog_arm64_program_modified = some block ∧
      CC.Genv.findFunctPtr world.genv_genv block = some (.Internal Arm64Program.f_kprog_arm64_program_modified))
    (unshadowed : e.get Arm64Program._kprog_arm64_program_modified = none)
    (entry : le.get Arm64Program._entry = some (.Vptr b ofs))
    (src : le.get Arm64Program._src2 = some (.Vlong source))
    (aux : le.get Arm64Program._aux = some (.Vint (65792#32)))
    (effective : le.get Arm64Program.___a64_l_width = some (Arm64Compare.RhsCall.width true)) :
    CC.Step2 world (.State Arm64Nop.handler modifiedCall k e le m) CC.E0
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_modified)
        (Arm64Modified.LslOne.arguments b ofs source) (.Kcall (some Arm64Program._t'138) Arm64Nop.handler e le k) m) := by
  rw [call_source]
  apply CC.Step.call (tyargs := parameterTypes) (tyres := CC.tulong) (cconv := CC.cc_default) (vf := .Vptr block 0)
  · exact target_type
  · apply CC.doEvalExpr_sound
    simp only [target, CC.doEvalExpr, CC.doEvalLvalue, CC.lvalOfVar, CC.doDerefLoc, CC.accessMode,
      CC.typeof, unshadowed, binding.1, CC.Integers.Ptrofs.zero, CC.Integers.MI.zero]
  · apply CC.doEvalExprlist_sound
    exact args_eval world e le m b ofs source entry src aux effective
  · simpa +decide [CC.Genv.findFunct, CC.Integers.Ptrofs.eq, CC.Integers.Ptrofs.zero, CC.Integers.MI.eq, CC.Integers.MI.zero] using binding.2
  · exact function_type

private theorem modified_binding : ∃ block,
    CC.Genv.findSymbol Arm64ProgramEntryLinked.ge.genv_genv Arm64Program._kprog_arm64_program_modified = some block ∧
    CC.Genv.findFunctPtr Arm64ProgramEntryLinked.ge.genv_genv block =
      some (.Internal Arm64Program.f_kprog_arm64_program_modified) := by
  refine ⟨(CC.Genv.findSymbol Arm64ProgramEntryLinked.ge.genv_genv Arm64Program._kprog_arm64_program_modified).get
    (by decide +kernel), ?_, ?_⟩
  all_goals run_tac Arm64ProgramEntryLinked.sourceEquality

/-- All original RHS argument casts at AUX65792 and width4, with actual target lookup. -/
theorem enter (b : CC.Block) (ofs : CC.Integers.Ptrofs)
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (reg : BitVec 64)
    (unshadowed : e.get Arm64Program._kprog_arm64_program_modified = none)
    (entry : le.get Arm64Program._entry = some (.Vptr b ofs))
    (src : le.get Arm64Program._src2 = some (.Vlong reg))
    (aux : le.get Arm64Program._aux = some (.Vint (65792#32)))
    (effective : le.get Arm64Program.___a64_l_width = some (Arm64Compare.RhsCall.width true)) :
    InternalRun Arm64ProgramEntryLinked.ge 3 (.State Arm64Nop.handler ReadEntry.rhs k e le m)
      (.Callstate (.Internal Arm64Modified.Read.handler)
        (Arm64Modified.LslOne.arguments b ofs reg) (callCont k e le) m) := by
  obtain ⟨block,binding⟩ := modified_binding
  apply InternalRun.step (mid := .State Arm64Nop.handler (.Ssequence modifiedCall readSet) (.Kseq tail k) e le m)
  · trivial
  · exact CC.doStep_sound _ _ _ _ (by simp only [CC.doStep,source])
  apply InternalRun.step (mid := .State Arm64Nop.handler modifiedCall (.Kseq readSet (.Kseq tail k)) e le m)
  · trivial
  · exact CC.doStep_sound _ _ _ _ rfl
  exact .step trivial (call_step Arm64ProgramEntryLinked.ge block b ofs e le m
    (.Kseq readSet (.Kseq tail k)) reg binding unshadowed entry src aux effective) (.refl _)

def temps (le : CC.TempEnv) (value : BitVec 64) : CC.TempEnv :=
  (le.set Arm64Program._t'138 (.Vlong value)).set Arm64Program.___kprog_a64_orn_rhs (.Vlong value)

set_option hygiene false in
/-- The original real helper return and RHS copy resume the unchanged suffix. -/
theorem returned (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (k : CC.Cont) (value : BitVec 64) :
    InternalRun world 4 (.Returnstate (.Vlong value) (callCont k e le) m)
      (.State Arm64Nop.handler tail k e (temps le value) m) := by
  run_tac do
    for _ in [:4] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp only [CC.doStep,callCont,readSet,temps,
        CC.setOpttemp,CC.PTree.gss,CC.doEvalExpr,CC.typeof,CC.Cop.semCast,CC.Cop.classifyCast,
        CC.typeconv,CC.removeAttributes,CC.tattr,CC.tulong,CC.E0,CC.Eapp,List.nil_append,List.append_nil] <;> try rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

/-- Actual RHS entry, scalar loads, LSL1 callee and copy preserve the entire heap. -/
theorem scalar (i : Fin 31) (b cb vb tb kb : CC.Block)
    (ofs co vo to ko : CC.Integers.Ptrofs) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (k : CC.Cont) (value : BitVec 64)
    (unshadowed : e.get Arm64Program._kprog_arm64_program_modified = none)
    (entry : le.get Arm64Program._entry = some (.Vptr b ofs))
    (src : le.get Arm64Program._src2 = some (.Vlong (BitVec.ofNat 64 i.val)))
    (aux : le.get Arm64Program._aux = some (.Vint (65792#32)))
    (effective : le.get Arm64Program.___a64_l_width = some (Arm64Compare.RhsCall.width true))
    (cells : CC.Mem.loadv CC.Mptr m (.Vptr b ofs) = some (.Vptr cb co))
    (cellSlot : CC.Mem.loadv CC.Mptr m (.Vptr cb (CC.Integers.Ptrofs.add co
      (CC.Integers.Ptrofs.repr (8 * (i.val : CC.Z))))) = some (.Vptr vb vo))
    (tags : CC.Mem.loadv CC.Mptr m (.Vptr b (CC.Integers.Ptrofs.add ofs
      (CC.Integers.Ptrofs.repr 8))) = some (.Vptr tb to))
    (tagSlot : CC.Mem.loadv CC.Mptr m (.Vptr tb (CC.Integers.Ptrofs.add to
      (CC.Integers.Ptrofs.repr (8 * (i.val : CC.Z))))) = some (.Vptr kb ko))
    (cell : CC.Mem.loadv .Mint64 m (.Vptr vb vo) = some (.Vlong value))
    (kind : CC.Mem.loadv .Mint8unsigned m (.Vptr kb ko) = some (.Vint 0)) :
    InternalRun Arm64ProgramEntryLinked.ge 126 (.State Arm64Nop.handler ReadEntry.rhs k e le m)
      (.State Arm64Nop.handler tail k e (temps le ((value <<< 1) &&& (4294967295#64))) m) := by
  have first := enter b ofs e le m k (BitVec.ofNat 64 i.val) unshadowed entry src aux effective
  have called := Arm64Modified.LslOne.execute Arm64ProgramEntryLinked.ge Arm64MovKeep.Linked.reader_layout
    i b cb vb tb kb ofs co vo to ko m (callCont k e le) value cells cellSlot tags tagSlot cell kind
  have last := returned Arm64ProgramEntryLinked.ge e le m k ((value <<< 1) &&& (4294967295#64))
  simpa only [CC.callCont,callCont] using (first.trans called).trans last

/-- Original inputs and the actual LHS survive the RHS call and copy. -/
theorem ready (le : CC.TempEnv) (value : BitVec 64) :
    (temps le value).get Arm64Program.___kprog_a64_orn_rhs = some (.Vlong value) ∧
    ∀ id ∈ [Arm64Program._entry,Arm64Program._dst,Arm64Program._src,Arm64Program._src2,
      Arm64Program._src3,Arm64Program._flags,Arm64Program._aux,Arm64Program._op,
      Arm64Program.___a64_l_width,Arm64Program.___kprog_a64_orn_op,Arm64Program.___kprog_a64_orn_lhs],
      (temps le value).get id = le.get id := by
  constructor
  · change (le.set _ (.Vlong value) |>.set _ (.Vlong value)).get _ = _
    exact CC.PTree.gss _ _ _
  · intro id inside
    simp at inside
    rcases inside with rfl|rfl|rfl|rfl|rfl|rfl|rfl|rfl|rfl|rfl|rfl
    all_goals
      unfold temps
      rw [CC.PTree.gso _ _ _ _ (by decide +kernel),CC.PTree.gso _ _ _ _ (by decide +kernel)]

end KProgFormal.ClightRefinement.Arm64Orn.RhsCall
