import KProgFormal.ClightRefinement.X86ProducerPushBody

namespace KProgFormal.ClightRefinement.X86ProducerEffectiveWidth
open X86ProducerLayout (ge)
open X86ProducerPushBody (handler allocation)

def statement (result argument : CC.Ident) : CC.Stmt := .Scall (some result)
  (.Evar X86_program_profile_bpf._x86_width_effective (.Tfunction [CC.tuchar] CC.tuchar CC.cc_default))
  [.Etempvar argument CC.tuchar]
def continuation (frame : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) (result : CC.Ident) : CC.Cont :=
  .Kcall (some result) handler (allocation frame).1 le k

/-- Actual producer-world width Scall and return, parameterized only by the
original temporary names. This shares the unchanged six-step helper proof. -/
theorem invoke (frame memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) (result argument : CC.Ident)
    (read : le.get argument = some (.Vint (8#32))) :
    InternalRun ge 8 (.State handler (statement result argument) k (allocation frame).1 le memory)
      (.State handler .Sskip k (allocation frame).1 (le.set result (.Vint (8#32))) memory) := by
  have absent : (allocation frame).1.get X86_program_profile_bpf._x86_width_effective = none := rfl
  have function : CC.doEvalExpr ge (allocation frame).1 le memory
      (.Evar X86_program_profile_bpf._x86_width_effective (.Tfunction [CC.tuchar] CC.tuchar CC.cc_default)) =
        some (.Vptr X86ProducerPushWidth.widthBlock 0) := by
    simp only [CC.doEvalExpr, CC.lvalOfVar, absent, X86ProducerPushWidth.width_binding.1, CC.doDerefLoc, CC.accessMode]
    rfl
  have args : CC.doEvalExprlist ge (allocation frame).1 le memory [.Etempvar argument CC.tuchar] [CC.tuchar] = some [.Vint (8#32)] := by
    simp only [CC.doEvalExprlist, CC.doEvalExpr, read, CC.typeof]
    rfl
  have called : InternalRun ge 1 (.State handler (statement result argument) k (allocation frame).1 le memory)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_width_effective) [.Vint (8#32)] (continuation frame le k result) memory) := by
    unfold statement
    refine .step trivial ?_ (.refl _)
    apply CC.Step.call (tyargs := [CC.tuchar]) (tyres := CC.tuchar) (cconv := CC.cc_default)
      (vf := .Vptr X86ProducerPushWidth.widthBlock 0)
    · rfl
    · exact CC.doEvalExpr_sound _ _ _ _ _ _ function
    · exact CC.doEvalExprlist_sound _ _ _ _ _ _ _ args
    · have zeroOffset : CC.Integers.Ptrofs.eq (0 : CC.Integers.Ptrofs) CC.Integers.Ptrofs.zero = true := rfl
      simpa only [CC.Genv.findFunct, zeroOffset, ite_true] using X86ProducerPushWidth.width_binding.2
    · rfl
  have helper : InternalRun ge 6
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_width_effective) [.Vint (8#32)] (continuation frame le k result) memory)
      (.Returnstate (.Vint (8#32)) (continuation frame le k result) memory) :=
    X86Width.internal ge (8#8) (continuation frame le k result) memory
  have returned : InternalRun ge 1 (.Returnstate (.Vint (8#32)) (continuation frame le k result) memory)
      (.State handler .Sskip k (allocation frame).1 (le.set result (.Vint (8#32))) memory) :=
    .step trivial (CC.doStep_sound ge _ _ _ rfl) (.refl _)
  exact (called.trans helper).trans returned

end KProgFormal.ClightRefinement.X86ProducerEffectiveWidth
