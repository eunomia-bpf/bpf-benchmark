import KProgFormal.ClightRefinement.X86LogicAlu
import KProgFormal.ClightRefinement.X86ShiftLeftRoute

namespace KProgFormal.ClightRefinement.X86LogicSite

section Caller
variable (ge : CC.CGenv) (aluBlock : CC.Block)
    (binding : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_alu_result = some aluBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv aluBlock =
        some (.Internal X86_program_profile_bpf.f_x86_alu_result))
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (unshadowed : e.get X86_program_profile_bpf._x86_alu_result = none)
    (lhs rhs : BitVec 64) (size : X86.Size)
    (left : le.get X86_program_profile_bpf.___x86_l_lhs = some (.Vlong lhs))
    (right : le.get X86_program_profile_bpf.___x86_l_rhs = some (.Vlong rhs))
    (width : le.get X86_program_profile_bpf.___x86_l_width__1 = some (X86ShiftLeft.argument size))
    (k : CC.Cont) (m : CC.Mem)
include binding unshadowed left right width

/-- Real caller argument evaluation, complete selected helper and original
return/assignment compose through the arithmetic site in25 transitions. -/
theorem internal (code : BitVec 8) (value : BitVec 64)
    (operation : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint (code.setWidth 32)))
    (selected : (code = (2#8) ∧ value = lhs ^^^ rhs) ∨
      (code = (3#8) ∧ value = lhs ||| rhs) ∨
      (code = (4#8) ∧ value = lhs &&& rhs)) :
    InternalRun ge 25 (.State function X86ShiftLeftSite.statement k e le m)
      (.State function .Sskip k e (X86ShiftLeftSite.afterTemps le (.Vlong value)) m) := by
  obtain ⟨callK, beforeCall, afterCall⟩ := X86ShiftLeftSite.call_and_resume ge aluBlock binding
    function e le unshadowed lhs rhs size code left right operation width k m
  have widthArgument : X86ShiftLeft.argument size =
      .Vint ((BitVec.ofNat 8 size.bytes).setWidth 32) := by cases size <;> rfl
  have xorCode : (2#8).setWidth 32 = (2#32) := rfl
  have orCode : (3#8).setWidth 32 = (3#32) := rfl
  have andCode : (4#8).setWidth 32 = (4#32) := rfl
  have helper : InternalRun ge 20
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_alu_result)
        [.Vlong lhs, .Vlong rhs, .Vint (code.setWidth 32), X86ShiftLeft.argument size] callK m)
      (.Returnstate (.Vlong value) (CC.callCont callK) m) := by
    rcases selected with ⟨rfl, rfl⟩ | ⟨rfl, rfl⟩ | ⟨rfl, rfl⟩
    · simpa only [widthArgument, xorCode] using X86LogicAlu.xor_internal ge lhs rhs
        (BitVec.ofNat 8 size.bytes) callK m
    · simpa only [widthArgument, orCode] using X86LogicAlu.or_internal ge lhs rhs
        (BitVec.ofNat 8 size.bytes) callK m
    · simpa only [widthArgument, andCode] using X86LogicAlu.and_internal ge lhs rhs
        (BitVec.ofNat 8 size.bytes) callK m
  exact (beforeCall.trans helper).trans (afterCall (.Vlong value))

/-- Original SBB/ADC selection, real numerical execution and source resume
reach the untouched flag stage in29 transitions for all three logical codes. -/
theorem to_flags (code : BitVec 8) (value : BitVec 64)
    (operation : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint (code.setWidth 32)))
    (selected : (code = (2#8) ∧ value = lhs ^^^ rhs) ∨
      (code = (3#8) ∧ value = lhs ||| rhs) ∨
      (code = (4#8) ∧ value = lhs &&& rhs)) :
    InternalRun ge 29 (.State function X86ShiftLeftRoute.dispatch k e le m)
      (.State function X86ShiftLeftRoute.flags k e
        (X86ShiftLeftSite.afterTemps le (.Vlong value)) m) := by
  have supported : code = (2#8) ∨ code = (3#8) ∨ code = (4#8) ∨ code = (5#8) := by
    rcases selected with h | h | h
    · exact .inl h.1
    · exact .inr (.inl h.1)
    · exact .inr (.inr (.inl h.1))
  have routed := X86ShiftLeftRoute.select_arithmetic ge function e le k m code supported operation
  have numerical := internal ge aluBlock binding function e le unshadowed lhs rhs size
    left right width (.Kseq X86ShiftLeftRoute.flags k) m code value operation selected
  have resume : InternalRun ge 1
      (.State function .Sskip (.Kseq X86ShiftLeftRoute.flags k) e
        (X86ShiftLeftSite.afterTemps le (.Vlong value)) m)
      (.State function X86ShiftLeftRoute.flags k e
        (X86ShiftLeftSite.afterTemps le (.Vlong value)) m) := by
    apply internalRun_of_steps
    · simp [InternalPath, InternalState, CC.doStep]
    · simp [steps, CC.doStep, CC.Eapp, CC.E0]
  exact (routed.trans numerical).trans resume

/-- Actual XOR dispatcher-to-flag execution for arbitrary scalar operands. -/
theorem xor_to_flags
    (operation : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint (2#32))) :
    InternalRun ge 29 (.State function X86ShiftLeftRoute.dispatch k e le m)
      (.State function X86ShiftLeftRoute.flags k e
        (X86ShiftLeftSite.afterTemps le (.Vlong (lhs ^^^ rhs))) m) :=
  to_flags ge aluBlock binding function e le unshadowed lhs rhs size left right width k m
    (2#8) (lhs ^^^ rhs) operation (.inl ⟨rfl, rfl⟩)

/-- Actual OR dispatcher-to-flag execution for arbitrary scalar operands. -/
theorem or_to_flags
    (operation : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint (3#32))) :
    InternalRun ge 29 (.State function X86ShiftLeftRoute.dispatch k e le m)
      (.State function X86ShiftLeftRoute.flags k e
        (X86ShiftLeftSite.afterTemps le (.Vlong (lhs ||| rhs))) m) :=
  to_flags ge aluBlock binding function e le unshadowed lhs rhs size left right width k m
    (3#8) (lhs ||| rhs) operation (.inr (.inl ⟨rfl, rfl⟩))

/-- Actual AND dispatcher-to-flag execution for arbitrary scalar operands. -/
theorem and_to_flags
    (operation : le.get X86_program_profile_bpf.___x86_l_alu = some (.Vint (4#32))) :
    InternalRun ge 29 (.State function X86ShiftLeftRoute.dispatch k e le m)
      (.State function X86ShiftLeftRoute.flags k e
        (X86ShiftLeftSite.afterTemps le (.Vlong (lhs &&& rhs))) m) :=
  to_flags ge aluBlock binding function e le unshadowed lhs rhs size left right width k m
    (4#8) (lhs &&& rhs) operation (.inr (.inr ⟨rfl, rfl⟩))

end Caller
end KProgFormal.ClightRefinement.X86LogicSite
