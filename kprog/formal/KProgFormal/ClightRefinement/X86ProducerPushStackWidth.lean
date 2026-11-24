import KProgFormal.ClightRefinement.X86ProducerPushStackSetup

namespace KProgFormal.ClightRefinement.X86ProducerPushStackWidth
open X86ProducerLayout (ge)
open X86ProducerPushBody (handler allocation)
open X86ProducerPushStackSource (widthCall widthSave widthCont stages prepareCont)

def continuation (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) : CC.Cont :=
  .Kcall (some X86_program_profile_bpf._t'11) handler e le (widthCont k)
def temps (le : CC.TempEnv) : CC.TempEnv :=
  (le.set X86_program_profile_bpf._t'11 (.Vint (8#32))).set X86_program_profile_bpf.___x86_sv_width (.Vlong (8#64))

theorem call (frame memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (read : le.get X86_program_profile_bpf.___x86_l_pp_width = some (.Vint (8#32))) :
    InternalRun ge 1 (.State handler widthCall (widthCont k) (allocation frame).1 le memory)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_width_effective) [.Vint (8#32)]
        (continuation (allocation frame).1 le k) memory) := by
  have absent : (allocation frame).1.get X86_program_profile_bpf._x86_width_effective = none := rfl
  have function : CC.doEvalExpr ge (allocation frame).1 le memory
      (.Evar X86_program_profile_bpf._x86_width_effective (.Tfunction [CC.tuchar] CC.tuchar CC.cc_default)) =
        some (.Vptr X86ProducerPushWidth.widthBlock 0) := by
    simp only [CC.doEvalExpr, CC.lvalOfVar, absent, X86ProducerPushWidth.width_binding.1, CC.doDerefLoc, CC.accessMode]
    rfl
  have args : CC.doEvalExprlist ge (allocation frame).1 le memory
      [.Etempvar X86_program_profile_bpf.___x86_l_pp_width CC.tuchar] [CC.tuchar] = some [.Vint (8#32)] := by
    simp only [CC.doEvalExprlist, CC.doEvalExpr, read, CC.typeof]
    rfl
  rw [X86ProducerPushStackSource.width_source.1]
  refine .step trivial ?_ (.refl _)
  apply CC.Step.call (tyargs := [CC.tuchar]) (tyres := CC.tuchar) (cconv := CC.cc_default)
    (vf := .Vptr X86ProducerPushWidth.widthBlock 0)
  · rfl
  · exact CC.doEvalExpr_sound _ _ _ _ _ _ function
  · exact CC.doEvalExprlist_sound _ _ _ _ _ _ _ args
  · have zeroOffset : CC.Integers.Ptrofs.eq (0 : CC.Integers.Ptrofs) CC.Integers.Ptrofs.zero = true := rfl
    simpa only [CC.Genv.findFunct, zeroOffset, ite_true] using X86ProducerPushWidth.width_binding.2
  · rfl

theorem resume (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (memory : CC.Mem) :
    InternalRun ge 4 (.Returnstate (.Vint (8#32)) (continuation e le k) memory)
      (.State handler stages (prepareCont k) e (temps le) memory) := by
  have cast : CC.Cop.semCast (.Vint (8#32)) CC.tuchar CC.tulong memory = some (.Vlong (8#64)) := rfl
  apply internalRun_of_steps
  all_goals simp only [steps, InternalPath, InternalState, CC.doStep, continuation,
    X86ProducerPushStackSource.widthCont, X86ProducerPushStackSource.width_source.2,
    CC.setOpttemp, CC.doEvalExpr, CC.typeof, CC.PTree.gss, cast, temps,
    CC.E0, CC.Eapp, List.nil_append, true_and]

/-- True call, existing complete six-step width helper and actual return/save
compose eleven internal steps; complete source memory is unchanged. -/
theorem execute (frame memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (read : le.get X86_program_profile_bpf.___x86_l_pp_width = some (.Vint (8#32))) :
    InternalRun ge 11 (.State handler widthCall (widthCont k) (allocation frame).1 le memory)
      (.State handler stages (prepareCont k) (allocation frame).1 (temps le) memory) := by
  have helper : InternalRun ge 6
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_width_effective) [.Vint (8#32)] (continuation (allocation frame).1 le k) memory)
      (.Returnstate (.Vint (8#32)) (continuation (allocation frame).1 le k) memory) :=
    X86Width.internal ge (8#8) (continuation (allocation frame).1 le k) memory
  exact (call frame memory le k read).trans (helper.trans (resume _ le k memory))

theorem from_rsp {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    (result : X86ProducerPushRspPrefix.Result ready) (k : CC.Cont) :
    InternalRun ge 25
      (.State handler X86ProducerPushRspSource.stackLoop k (allocation ready.after).1 (X86ProducerPushRspPrefix.temps ready) result.after)
      (.State handler stages (prepareCont k) (allocation ready.after).1
        (temps (X86ProducerPushStackSetup.temps (X86ProducerPushRspPrefix.temps ready) ready.gprs.block)) result.after) :=
  (X86ProducerPushStackSetup.from_rsp result k).trans
    (execute ready.after result.after _ k (X86ProducerPushStackSetup.inputs ready).2.1)

theorem inputs {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    (ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer) :
    (temps (X86ProducerPushStackSetup.temps (X86ProducerPushRspPrefix.temps ready) ready.gprs.block)).get X86_program_profile_bpf.___x86_sv_index = some (.Vlong (40#64)) ∧
    (temps (X86ProducerPushStackSetup.temps (X86ProducerPushRspPrefix.temps ready) ready.gprs.block)).get X86_program_profile_bpf.___x86_sv_width = some (.Vlong (8#64)) ∧
    (temps (X86ProducerPushStackSetup.temps (X86ProducerPushRspPrefix.temps ready) ready.gprs.block)).get X86_program_profile_bpf.___x86_bind = some (.Vptr ready.entry.block 0) ∧
    (temps (X86ProducerPushStackSetup.temps (X86ProducerPushRspPrefix.temps ready) ready.gprs.block)).get X86_program_profile_bpf.___x86_l_pp_value = some (.Vlong (ready.values 3)) :=
  ⟨rfl,CC.PTree.gss _ _ _,rfl,rfl⟩

end KProgFormal.ClightRefinement.X86ProducerPushStackWidth
