import KProgFormal.ClightRefinement.X86ProducerSubCall
import KProgFormal.ClightRefinement.X86ProducerPushWidth

namespace KProgFormal.ClightRefinement.X86ProducerSubWidth
open X86ProducerSubCall (handler initialTemps values)
open X86ProducerLayout (ge)

private structure Parts where
  body : CC.Stmt
  widthCall : CC.Stmt
  widthSet : CC.Stmt
  decision : CC.Stmt
private def parts : Parts := by
  run_tac do
    let loop ← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.Elab.Term.elabTerm (← `(handler.fn_body)) none))
    unless loop.isAppOfArity ``CC.Stmt.Sloop 2 do throwError "original SUB wrapper loop changed"
    let body ← Lean.Meta.withTransparency .all (Lean.Meta.whnf loop.getAppArgs[0]!)
    unless body.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original SUB width/dispatch sequence changed"
    let setup ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body.getAppArgs[0]!)
    unless setup.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original SUB width call/assignment changed"
    Lean.Elab.Tactic.closeMainGoal `original_x86_push_width_parts
      (← Lean.Meta.mkAppM ``Parts.mk #[loop.getAppArgs[0]!,setup.getAppArgs[0]!,setup.getAppArgs[1]!,body.getAppArgs[1]!])

def body : CC.Stmt := parts.body
def widthCall : CC.Stmt := parts.widthCall
def widthSet : CC.Stmt := parts.widthSet
def decision : CC.Stmt := parts.decision
def loopCont (k : CC.Cont) : CC.Cont := .Kloop1 body .Sbreak k
def widthCont (le : CC.TempEnv) (k : CC.Cont) : CC.Cont :=
  .Kcall (some X86_program_profile_bpf._t'1) handler CC.emptyEnv le (.Kseq widthSet (.Kseq decision (loopCont k)))
def temps (le : CC.TempEnv) : CC.TempEnv :=
  (le.set X86_program_profile_bpf._t'1 (.Vint (8#32))).set X86_program_profile_bpf.___x86_dispatch_width (.Vint (8#32))

theorem source : handler.fn_body = .Sloop body .Sbreak ∧ body = .Ssequence (.Ssequence widthCall widthSet) decision := by constructor <;> rfl
theorem width_source : widthCall = .Scall (some X86_program_profile_bpf._t'1)
    (.Evar X86_program_profile_bpf._x86_width_effective (.Tfunction [CC.tuchar] CC.tuchar CC.cc_default))
    [.Etempvar X86_program_profile_bpf._flags CC.tuchar] := by rfl

theorem width_assignment : widthSet = .Sset X86_program_profile_bpf.___x86_dispatch_width
    (.Ecast (.Etempvar X86_program_profile_bpf._t'1 CC.tuchar) CC.tuchar) := by rfl

open X86ProducerPushWidth (widthBlock width_binding)

/-- The original loop/sequences and true helper binding execute before any
SUB dispatcher condition. The memory is identical throughout. -/
theorem enter (memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (read : le.get X86_program_profile_bpf._flags = some (.Vint (8#32))) :
    InternalRun ge 4 (.State handler handler.fn_body k CC.emptyEnv le memory)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_width_effective) [.Vint (8#32)] (widthCont le k) memory) := by
  have expression : CC.doEvalExpr ge CC.emptyEnv le memory
      (.Evar X86_program_profile_bpf._x86_width_effective (.Tfunction [CC.tuchar] CC.tuchar CC.cc_default)) = some (.Vptr widthBlock 0) := by
    simp only [CC.doEvalExpr, CC.lvalOfVar, CC.emptyEnv, CC.PTree.gempty, width_binding.1, CC.doDerefLoc, CC.accessMode]
    rfl
  have args : CC.doEvalExprlist ge CC.emptyEnv le memory [.Etempvar X86_program_profile_bpf._flags CC.tuchar] [CC.tuchar] = some [.Vint (8#32)] := by
    simp only [CC.doEvalExprlist, CC.doEvalExpr, CC.typeof, read]
    rfl
  have call : InternalRun ge 1 (.State handler widthCall (.Kseq widthSet (.Kseq decision (loopCont k))) CC.emptyEnv le memory)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_width_effective) [.Vint (8#32)] (widthCont le k) memory) := by
    rw [width_source]
    refine .step trivial ?_ (.refl _)
    apply CC.Step.call (tyargs := [CC.tuchar]) (tyres := CC.tuchar) (cconv := CC.cc_default) (vf := .Vptr widthBlock 0)
    · rfl
    · exact CC.doEvalExpr_sound _ _ _ _ _ _ expression
    · exact CC.doEvalExprlist_sound _ _ _ _ _ _ _ args
    · have zeroOffset : CC.Integers.Ptrofs.eq (0 : CC.Integers.Ptrofs) CC.Integers.Ptrofs.zero = true := rfl
      simpa only [CC.Genv.findFunct, zeroOffset, ite_true] using width_binding.2
    · rfl
  rw [source.1, source.2]
  exact .step trivial (CC.doStep_sound ge _ _ _ rfl)
    (.step trivial (CC.doStep_sound ge _ _ _ rfl)
      (.step trivial (CC.doStep_sound ge _ _ _ rfl) call))

theorem resume (memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) :
    InternalRun ge 4 (.Returnstate (.Vint (8#32)) (widthCont le k) memory)
      (.State handler decision (loopCont k) CC.emptyEnv (temps le) memory) := by
  apply internalRun_of_steps
  all_goals simp +decide [steps, InternalPath, InternalState, CC.doStep, widthCont, width_assignment, temps,
    CC.callCont, CC.setOpttemp, CC.doEvalExpr, CC.PTree.gss, CC.Cop.semCast, CC.Cop.classifyCast,
    CC.Cop.castIntInt, CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.typeof, CC.tuchar, CC.E0, CC.Eapp]

/-- Original wrapper entry, real effective-width call/return and assignment
compose15 silent internal transitions to its original dispatcher decision. -/
theorem from_call (memory : CC.Mem) (k : CC.Cont) (binding : CC.Block) :
    InternalRun ge 15 (.Callstate (.Internal handler) (values binding) k memory)
      (.State handler decision (loopCont k) CC.emptyEnv (temps (initialTemps binding)) memory) := by
  have names : X86_program_profile_bpf._imm ≠ X86_program_profile_bpf._flags ∧
      X86_program_profile_bpf._aux ≠ X86_program_profile_bpf._flags := by decide +kernel
  have flags : (initialTemps binding).get X86_program_profile_bpf._flags = some (.Vint (8#32)) := by
    unfold initialTemps
    rw [CC.PTree.gso _ _ _ _ names.1, CC.PTree.gso _ _ _ _ names.2, CC.PTree.gss]
  have helper : InternalRun ge 6
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_width_effective) [.Vint (8#32)] (widthCont (initialTemps binding) k) memory)
      (.Returnstate (.Vint (8#32)) (widthCont (initialTemps binding) k) memory) :=
    X86Width.internal ge (8#8) (widthCont (initialTemps binding) k) memory
  exact (X86ProducerSubCall.entry memory k binding).trans ((enter memory _ k flags).trans (helper.trans (resume memory _ k)))

/-- Real width temporaries preserve every other original parameter observation. -/
theorem unchanged (le : CC.TempEnv) (name : CC.Ident)
    (notResult : X86_program_profile_bpf._t'1 ≠ name) (notWidth : X86_program_profile_bpf.___x86_dispatch_width ≠ name) :
    (temps le).get name = le.get name := by
  unfold temps
  rw [CC.PTree.gso _ _ _ _ notWidth, CC.PTree.gso _ _ _ _ notResult]

end KProgFormal.ClightRefinement.X86ProducerSubWidth
