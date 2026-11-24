import KProgFormal.ClightRefinement.X86QwordDestination

namespace KProgFormal.ClightRefinement.X86QwordDestinationScalar

def temps (le : CC.TempEnv) : CC.TempEnv :=
  (((le.set X86_program_profile_bpf._t'131 (.Vint (0#32))).set
    X86_program_profile_bpf._t'131 (.Vint (0#32))).set
    X86_program_profile_bpf._t'136 (.Vint (0#32))).set
    X86_program_profile_bpf._t'138 (.Vint (0#32))

/-- The original tag6 test, materialization, source-tag gate and operation
selector finish the scalar destination path without a third helper call. -/
theorem finish (ge : CC.CGenv) (function : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) (memory : CC.Mem)
    (tag : le.get X86_program_profile_bpf._t'135 = some (X86Width.argument (0#8))) :
    InternalRun ge 12 (.State function .Sskip (X86QwordDestination.continuation k) e le memory)
      (.State function X86ShiftWriteback.sourceWriter k e (temps le) memory) := by
  apply internalRun_of_steps
  all_goals
    simp +decide [steps, InternalPath, InternalState, X86QwordDestination.continuation,
      X86QwordDestination.compared, X86QwordDestination.saved, X86QwordSelection.fourth,
      X86QwordSelection.fifth, X86QwordSelection.gate, temps, CC.doStep, CC.doEvalExpr,
      CC.typeof, tag, X86Width.argument, CC.PTree.gss, CC.PTree.gso,
      CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp,
      CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType,
      CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
      CC.Cop.boolVal, CC.Cop.classifyBool, CC.typeconv, CC.removeAttributes, CC.tattr,
      CC.tuchar, CC.tuint, CC.tint, CC.tbool,
      CC.Integers.Int.eq, CC.Integers.MI.eq, CC.Integers.Int.zero, CC.Integers.MI.zero,
      CC.Integers.Int.one, CC.Integers.MI.one, CC.Integers.Int.repr, CC.Integers.MI.repr,
      CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse, CC.Eapp, CC.E0]
  rfl

/-- Both real destination-tag calls and their actual returns compose with
all original qword scalar-destination gates. The complete79-step path
retains the entire heap and derives every tag temporary from the initial load. -/
theorem execute (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv)
    (k : CC.Cont) (memory : CC.Mem) (index : Fin 16)
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
        some (X86Width.argument (0#8))) :
    let firstTemps := (X86QwordSelection.temps le).set X86_program_profile_bpf._t'132 (X86Width.argument (0#8))
    let secondTemps := (X86QwordDestination.temps firstTemps).set X86_program_profile_bpf._t'135
      (X86Width.argument (0#8))
    InternalRun ge 79 (.State function X86ShiftWriteback.scalarWriter k e le memory)
      (.State function X86ShiftWriteback.sourceWriter k e (temps secondTemps) memory) := by
  dsimp only
  let firstTemps := (X86QwordSelection.temps le).set X86_program_profile_bpf._t'132 (X86Width.argument (0#8))
  let secondTemps := (X86QwordDestination.temps firstTemps).set X86_program_profile_bpf._t'135
    (X86Width.argument (0#8))
  have firstRun := X86QwordTagStage.first ge layout function e le k memory index (0#8)
    bindingBlock cellsBlock helperBlock offset base width dstShift srcShift destination binding helper
    unshadowed cells current
  have readyDst : firstTemps.get X86_program_profile_bpf._dst =
      some (X86Width.argument (X86RegisterReadValue.registerByte index)) := by
    simp +decide [firstTemps, X86QwordSelection.temps, CC.PTree.gso, destination]
  have readyBinding : firstTemps.get X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock offset) := by
    simp +decide [firstTemps, X86QwordSelection.temps, CC.PTree.gso, binding]
  have prepared := X86QwordDestination.prepare ge function e firstTemps k memory
    (by simp only [firstTemps, CC.PTree.gss])
  have preparedDst : (X86QwordDestination.temps firstTemps).get X86_program_profile_bpf._dst =
      some (X86Width.argument (X86RegisterReadValue.registerByte index)) := by
    simp +decide [X86QwordDestination.temps, CC.PTree.gso, readyDst]
  have preparedBinding : (X86QwordDestination.temps firstTemps).get
      X86_program_profile_bpf.___x86_bind = some (.Vptr bindingBlock offset) := by
    simp +decide [X86QwordDestination.temps, CC.PTree.gso, readyBinding]
  have called := X86RegisterTagSite.execute ge layout function e
    (X86QwordDestination.temps firstTemps) (X86QwordDestination.continuation k) memory
    X86_program_profile_bpf._t'135 X86_program_profile_bpf._dst index (0#8)
    bindingBlock cellsBlock helperBlock offset base preparedDst preparedBinding helper unshadowed cells current
  rw [← X86QwordDestination.call_source] at called
  have finished := finish ge function e secondTemps k memory (by simp only [secondTemps, CC.PTree.gss])
  exact ((firstRun.trans prepared).trans called).trans finished

end KProgFormal.ClightRefinement.X86QwordDestinationScalar
