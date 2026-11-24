import KProgFormal.ClightRefinement.X86ProducerPushOperand
import KProgFormal.ClightRefinement.X86ProducerPushReadValue

namespace KProgFormal.ClightRefinement.X86ProducerPushRead
open X86ProducerLayout (ge)
open X86ProducerPushBody (handler allocation)

private def readerIndex : Nat := by
  run_tac do
    let mut rows ← Lean.Elab.Term.elabTerm (← `(X86_program_profile_bpf.global_definitions)) none
    let mut index := 0
    while true do
      let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf rows)
      unless node.isAppOfArity ``List.cons 3 do throwError "original register reader global missing"
      let row ← Lean.Meta.withTransparency .all (Lean.Meta.whnf node.getAppArgs[1]!)
      unless row.isAppOfArity ``Prod.mk 4 do throwError "original register reader global row changed"
      if row.getAppArgs[2]!.isConstOf ``X86_program_profile_bpf._x86_sim_inline_read_reg then
        Lean.Elab.Tactic.closeMainGoal `original_x86_push_reader_index (Lean.mkNatLit index)
        return
      rows := node.getAppArgs[2]!
      index := index + 1

def readerBlock : CC.Block := CC.Positive.ofNat (readerIndex + 1)

theorem reader_binding :
    CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_sim_inline_read_reg = some readerBlock ∧
    CC.Genv.findFunctPtr ge.genv_genv readerBlock =
      some (.Internal X86_program_profile_bpf.f_x86_sim_inline_read_reg) := by
  constructor <;> run_tac do
    let goal ← Lean.Elab.Tactic.getMainGoal
    let target ← Lean.Meta.whnfR (← Lean.instantiateMVars (← goal.getType))
    unless target.isAppOfArity ``Eq 3 do throwError "expected original reader global equality"
    goal.assign (← Lean.Meta.mkEqRefl target.getAppArgs[2]!)
    Lean.Elab.Tactic.replaceMainGoal []

def continuation (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) : CC.Cont :=
  .Kcall (some X86_program_profile_bpf._t'10) handler (allocation memory).1
    (X86ProducerPushOperand.certificate binding k memory).output
    (X86ProducerPushOperand.certificate binding k memory).continuation

/-- Original RBX operand Scall, with actual full-world callee resolution and
actual local environment. No lookup or argument-evaluation premise remains. -/
theorem call (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) :
    InternalRun ge 1
      (.State handler X86ProducerPushOperand.readCall
        (X86ProducerPushOperand.certificate binding k memory).continuation (allocation memory).1
        (X86ProducerPushOperand.certificate binding k memory).output (allocation memory).2)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_sim_inline_read_reg)
        (X86ProducerPushOperand.values binding) (continuation binding k memory) (allocation memory).2) := by
  have absentLocal : (allocation memory).1.get X86_program_profile_bpf._x86_sim_inline_read_reg = none := rfl
  have function : CC.doEvalExpr ge (allocation memory).1 (X86ProducerPushOperand.certificate binding k memory).output
      (allocation memory).2 X86ProducerPushOperand.expression = some (.Vptr readerBlock 0) := by
    simp only [X86ProducerPushOperand.expression, CC.doEvalExpr, CC.lvalOfVar, absentLocal,
      reader_binding.1, CC.doDerefLoc, CC.accessMode]
    rfl
  rw [X86ProducerPushOperand.source_read]
  refine .step trivial ?_ (.refl _)
  apply CC.Step.call (tyargs := X86ProducerPushOperand.argumentTypes) (tyres := CC.tulong)
    (cconv := CC.cc_default) (vf := .Vptr readerBlock 0)
  · rfl
  · exact CC.doEvalExpr_sound _ _ _ _ _ _ function
  · exact CC.doEvalExprlist_sound _ _ _ _ _ _ _ (X86ProducerPushOperand.arguments binding k memory)
  · have zeroOffset : CC.Integers.Ptrofs.eq (0 : CC.Integers.Ptrofs) CC.Integers.Ptrofs.zero = true := rfl
    simpa only [CC.Genv.findFunct, zeroOffset, ite_true] using reader_binding.2
  · rfl

/-- Actual original body entry through its genuine register-mode selector,
reader Scall and complete RBX helper execution, with the SAME initialized
resources and unchanged allocated memory throughout. -/
theorem from_body {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    (ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer) (k : CC.Cont) :
    InternalRun ge ((X86ProducerPushOperand.certificate ready.entry.block k ready.after).count + 1 +
        X86RegisterReadScalar.length .q)
      (X86ProducerPushOperand.start ready.entry.block k ready.after)
      (.Returnstate (.Vlong (ready.values 3))
        (CC.callCont (continuation ready.entry.block k ready.after)) (allocation ready.after).2) := by
  exact ((X86ProducerPushOperand.executes ready.entry.block k ready.after).trans
    (call ready.entry.block k ready.after)).trans (X86ProducerPushReadValue.call ready _)

end KProgFormal.ClightRefinement.X86ProducerPushRead
