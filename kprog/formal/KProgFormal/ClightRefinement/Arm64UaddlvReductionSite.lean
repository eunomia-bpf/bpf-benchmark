import KProgFormal.ClightRefinement.Arm64UaddlvReduction
import KProgFormal.ClightRefinement.Arm64CntReductionSite

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Uaddlv.ReductionSite

abbrev site := Arm64Cnt.ReductionSite.site
abbrev inputKey := Arm64Cnt.ReductionSite.inputKey
abbrev resultKey := Arm64Cnt.ReductionSite.resultKey
abbrev readPrefix := Arm64Cnt.ReductionSite.readPrefix

/-- UADDLV uses these same two genuine source call statements; the
original caller supplies opcode37 to the actual shared C function. -/
theorem source (upper : Bool) : site upper =
    .Scall (some (resultKey upper))
      (.Evar Arm64Program._kprog_arm64_reduction (.Tfunction [CC.tulong,CC.tulong] CC.tulong CC.cc_default))
      [.Etempvar Arm64Program._op CC.tuint,.Etempvar (inputKey upper) CC.tulong] :=
  Arm64Cnt.ReductionSite.source upper

private theorem binding : ∃ block,
    CC.Genv.findSymbol Arm64ProgramEntryLinked.ge.genv_genv Arm64Program._kprog_arm64_reduction = some block ∧
    CC.Genv.findFunctPtr Arm64ProgramEntryLinked.ge.genv_genv block = some (.Internal Reduction.handler) := by
  refine ⟨(CC.Genv.findSymbol Arm64ProgramEntryLinked.ge.genv_genv Arm64Program._kprog_arm64_reduction).get
    (by decide +kernel),?_,?_⟩
  all_goals run_tac Arm64ProgramEntryLinked.sourceEquality

private theorem call_step (world : CC.CGenv) (block : CC.Block)
    (symbol : CC.Genv.findSymbol world.genv_genv Arm64Program._kprog_arm64_reduction = some block)
    (function : CC.Genv.findFunctPtr world.genv_genv block = some (.Internal Reduction.handler))
    (upper : Bool) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (value : BitVec 64)
    (global : e.get Arm64Program._kprog_arm64_reduction = none)
    (op : le.get Arm64Program._op = some (.Vint (37#32)))
    (word : le.get (inputKey upper) = some (.Vlong value)) :
    CC.Step2 world (.State Arm64Nop.handler (site upper) k e le m) CC.E0
      (.Callstate (.Internal Reduction.handler) [.Vlong (37#64),.Vlong value]
        (.Kcall (some (resultKey upper)) Arm64Nop.handler e le k) m) := by
  rw [source]
  apply CC.Step.call (vf := .Vptr block 0) (tyargs := [CC.tulong,CC.tulong])
    (tyres := CC.tulong) (cconv := CC.cc_default)
  · rfl
  · apply CC.doEvalExpr_sound
    simp only [CC.doEvalExpr,CC.lvalOfVar,global,symbol,CC.doDerefLoc,CC.accessMode]
    rfl
  · apply CC.doEvalExprlist_sound
    simp only [CC.doEvalExprlist,CC.doEvalExpr,op,word,CC.Cop.semCast,
      CC.Cop.classifyCast,CC.Cop.castIntLong,CC.typeof,CC.tuint,CC.tulong]
    rfl
  · change CC.Genv.findFunctPtr world.genv_genv block = some (.Internal Reduction.handler)
    exact function
  · rfl

/-- Execute either genuine source call, the complete op37 C reduction and
the real caller return, preserving the full heap and every other temporary. -/
theorem execute (upper : Bool) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (value : BitVec 64) (global : e.get Arm64Program._kprog_arm64_reduction = none)
    (op : le.get Arm64Program._op = some (.Vint (37#32)))
    (word : le.get (inputKey upper) = some (.Vlong value)) :
    ∃ count, InternalRun Arm64ProgramEntryLinked.ge count
      (.State Arm64Nop.handler (site upper) k e le m)
      (.State Arm64Nop.handler .Sskip k e (le.set (resultKey upper) (.Vlong (Reduction.sum value))) m) := by
  obtain ⟨block,symbol,function⟩ := binding
  have enter : InternalRun Arm64ProgramEntryLinked.ge 1
      (.State Arm64Nop.handler (site upper) k e le m)
      (.Callstate (.Internal Reduction.handler) [.Vlong (37#64),.Vlong value]
        (.Kcall (some (resultKey upper)) Arm64Nop.handler e le k) m) :=
    .step (by rw [source]; trivial)
      (call_step _ block symbol function upper e le m k value global op word) (.refl _)
  obtain ⟨count,run⟩ := Reduction.execute Arm64ProgramEntryLinked.ge value
    (.Kcall (some (resultKey upper)) Arm64Nop.handler e le k) m
  have leave : InternalRun Arm64ProgramEntryLinked.ge 1
      (.Returnstate (.Vlong (Reduction.sum value))
        (CC.callCont (.Kcall (some (resultKey upper)) Arm64Nop.handler e le k)) m)
      (.State Arm64Nop.handler .Sskip k e (le.set (resultKey upper) (.Vlong (Reduction.sum value))) m) := by
    apply InternalRun.step
    · trivial
    · exact CC.doStep_sound _ _ _ _ rfl
    exact .refl _
  exact ⟨_,(enter.trans run).trans leave⟩

theorem retained (upper : Bool) (le : CC.TempEnv) (value : CC.Val) (id : CC.Ident)
    (different : id ≠ resultKey upper) :
    (le.set (resultKey upper) value).get id = le.get id :=
  Arm64Cnt.ReductionSite.retained upper le value id different

end KProgFormal.ClightRefinement.Arm64Uaddlv.ReductionSite
