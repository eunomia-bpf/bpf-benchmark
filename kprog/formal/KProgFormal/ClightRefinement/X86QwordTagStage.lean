import KProgFormal.ClightRefinement.X86QwordSelection

namespace KProgFormal.ClightRefinement.X86QwordTagStage

/-- The original qword selector, actual reg_tag body and its genuine caller
return compose. Initial cell/tag observations determine the returned byte,
for all architectural rows and all tags, with the full heap unchanged. -/
theorem first (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (k : CC.Cont) (memory : CC.Mem) (index : Fin 16) (tag : BitVec 8)
    (bindingBlock cellsBlock helperBlock : CC.Block) (offset base : CC.Integers.Ptrofs)
    (width : le.get X86_program_profile_bpf.___x86_l_width__1 = some (X86ShiftLeft.argument .q))
    (dstShift : le.get X86_program_profile_bpf.___x86_l_dst_shift = some (.Vint (0#32)))
    (srcShift : le.get X86_program_profile_bpf.___x86_l_src_shift = some (.Vint (0#32)))
    (destination : le.get X86_program_profile_bpf._dst =
      some (X86Width.argument (X86RegisterReadValue.registerByte index)))
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
    InternalRun ge 37 (.State function X86ShiftWriteback.scalarWriter k e le memory)
      (.State function .Sskip (X86QwordSelection.continuation k) e
        ((X86QwordSelection.temps le).set X86_program_profile_bpf._t'132 (X86Width.argument tag)) memory) := by
  have entered := X86QwordSelection.enter ge function e le k memory index bindingBlock helperBlock
    offset width dstShift srcShift destination binding helper unshadowed
  have called := X86RegisterTagCall.execute ge layout memory
    (.Kcall (some X86_program_profile_bpf._t'132) function e (X86QwordSelection.temps le)
      (X86QwordSelection.continuation k)) index tag bindingBlock cellsBlock offset base cells current
  have resumed : InternalRun ge 1
      (.Returnstate (X86Width.argument tag)
        (CC.callCont (.Kcall (some X86_program_profile_bpf._t'132) function e
          (X86QwordSelection.temps le) (X86QwordSelection.continuation k))) memory)
      (.State function .Sskip (X86QwordSelection.continuation k) e
        ((X86QwordSelection.temps le).set X86_program_profile_bpf._t'132 (X86Width.argument tag)) memory) := by
    apply internalRun_of_steps
    all_goals simp only [steps, InternalPath, InternalState, CC.doStep, CC.callCont,
      CC.setOpttemp, CC.Eapp, CC.E0, List.nil_append, true_and]
  exact (entered.trans called).trans resumed

end KProgFormal.ClightRefinement.X86QwordTagStage
