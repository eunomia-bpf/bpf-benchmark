import KProgFormal.ClightRefinement.X86RegisterTagCall

namespace KProgFormal.ClightRefinement.X86RegisterTagSite

/-- Shared spelling of the original register-tag call sites; each selector
source identity binds its actual call to this statement. -/
def statement (target register : CC.Ident) : CC.Stmt :=
  .Scall (some target)
    (.Evar X86_program_profile_bpf._x86_sim_inline_reg_tag
      (.Tfunction [CC.tptr (.Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr),
        CC.tulong] CC.tuchar CC.cc_default))
    [.Etempvar X86_program_profile_bpf.___x86_bind
      (CC.tptr (.Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr)),
      .Etempvar register CC.tuchar]

/-- A genuine original tag call, full helper execution and caller return
preserve the entire heap and materialize exactly the loaded tag. -/
theorem execute (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (memory : CC.Mem)
    (target register : CC.Ident) (index : Fin 16) (tag : BitVec 8)
    (bindingBlock cellsBlock helperBlock : CC.Block) (offset base : CC.Integers.Ptrofs)
    (registerRead : le.get register = some (X86Width.argument (X86RegisterReadValue.registerByte index)))
    (binding : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock offset))
    (helper : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._x86_sim_inline_reg_tag = some helperBlock ∧
      CC.Genv.findFunctPtr ge.genv_genv helperBlock =
        some (.Internal X86_program_profile_bpf.f_x86_sim_inline_reg_tag))
    (unshadowed : e.get X86_program_profile_bpf._x86_sim_inline_reg_tag = none)
    (cells : CC.Mem.load CC.Mptr memory bindingBlock (CC.Integers.Ptrofs.unsigned offset) =
      some (.Vptr cellsBlock base))
    (current : CC.Mem.load .Mint8unsigned memory cellsBlock
      (CC.Integers.Ptrofs.unsigned ((base + CC.Integers.Ptrofs.repr (16 * (index.val : Int))) + 8)) =
        some (X86Width.argument tag)) :
    InternalRun ge 23 (.State function (statement target register) k e le memory)
      (.State function .Sskip k e (le.set target (X86Width.argument tag)) memory) := by
  have widen : CC.Cop.semCast (X86Width.argument (X86RegisterReadValue.registerByte index))
      CC.tuchar CC.tulong memory =
      some (.Vlong ((X86RegisterReadValue.registerByte index).setWidth 64)) := by
    change some (CC.Val.Vlong (CC.Cop.castIntLong .Unsigned
      ((X86RegisterReadValue.registerByte index).setWidth 32))) = _
    rw [X86RegisterReadEntry.unsigned_byte]
  have entered : InternalRun ge 1 (.State function (statement target register) k e le memory)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_sim_inline_reg_tag)
        [.Vptr bindingBlock offset, .Vlong ((X86RegisterReadValue.registerByte index).setWidth 64)]
        (.Kcall (some target) function e le k) memory) := by
    refine .step trivial ?_ (.refl _)
    apply CC.Step.call (tyargs := [CC.tptr (.Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr),
      CC.tulong]) (tyres := CC.tuchar) (cconv := CC.cc_default) (vf := .Vptr helperBlock 0)
    · rfl
    · apply CC.doEvalExpr_sound
      simp only [CC.doEvalExpr, CC.lvalOfVar, CC.doDerefLoc, CC.accessMode, unshadowed, helper.1]
      rfl
    · apply CC.doEvalExprlist_sound
      simp only [CC.doEvalExprlist, CC.doEvalExpr, CC.typeof, binding, registerRead, widen]
      rfl
    · change CC.Genv.findFunctPtr ge.genv_genv helperBlock = _
      exact helper.2
    · rfl
  have called := X86RegisterTagCall.execute ge layout memory (.Kcall (some target) function e le k)
    index tag bindingBlock cellsBlock offset base cells current
  have resumed : InternalRun ge 1
      (.Returnstate (X86Width.argument tag) (CC.callCont (.Kcall (some target) function e le k)) memory)
      (.State function .Sskip k e (le.set target (X86Width.argument tag)) memory) := by
    apply internalRun_of_steps
    all_goals simp only [steps, InternalPath, InternalState, CC.doStep, CC.callCont,
      CC.setOpttemp, CC.Eapp, CC.E0, List.nil_append, true_and]
  exact (entered.trans called).trans resumed

end KProgFormal.ClightRefinement.X86RegisterTagSite
