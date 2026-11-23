import KProgFormal.ClightRefinement.Arm64CnegCondition

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Cneg.Write

/-- The original scalar writer edge with its actual callee and source arguments. -/
private theorem scalar_call (world : CC.CGenv) (block b : CC.Block)
    (binding : CC.Genv.findSymbol world.genv_genv Arm64Program._kprog_arm64_program_write = some block ∧
      CC.Genv.findFunctPtr world.genv_genv block = some (.Internal Arm64RegisterWrite.procedure))
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (dst value : BitVec 64) (narrow : Bool)
    (unshadowed : e.get Arm64Program._kprog_arm64_program_write = none)
    (entry : le.get Arm64Program._entry = some (.Vptr b 0))
    (destination : le.get Arm64Program._dst = some (.Vlong dst))
    (result : le.get Arm64Program.___a64_l_result__3 = some (.Vlong value))
    (width : le.get Arm64Program.___a64_l_width = some (Arm64RegisterWrite.width narrow)) :
    CC.Step2 world (.State Arm64Nop.handler ReadEntry.writer k e le m) CC.E0
      (.Callstate (.Internal Arm64RegisterWrite.procedure)
        [.Vptr b 0, .Vlong dst, .Vlong value, Arm64RegisterWrite.width narrow]
        (.Kcall none Arm64Nop.handler e le k) m) := by
  have source : ReadEntry.writer = .Scall none
      (.Evar Arm64Program._kprog_arm64_program_write
        (.Tfunction [CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr), CC.tulong,
          CC.tulong, CC.tuchar] CC.tvoid CC.cc_default))
      [.Etempvar Arm64Program._entry (CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr)),
       .Etempvar Arm64Program._dst CC.tulong,
       .Etempvar Arm64Program.___a64_l_result__3 CC.tulong,
       .Etempvar Arm64Program.___a64_l_width CC.tuchar] := rfl
  rw [source]
  apply CC.Step.call
    (tyargs := [CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr), CC.tulong, CC.tulong, CC.tuchar])
    (tyres := CC.tvoid) (cconv := CC.cc_default) (vf := .Vptr block 0)
  · rfl
  · apply CC.doEvalExpr_sound
    simp only [CC.doEvalExpr, CC.doEvalLvalue, CC.lvalOfVar, CC.doDerefLoc, CC.accessMode,
      CC.typeof, unshadowed, binding.1, CC.Integers.Ptrofs.zero, CC.Integers.MI.zero]
  · apply CC.doEvalExprlist_sound
    cases narrow <;> simp +decide [Arm64RegisterWrite.width, CC.doEvalExprlist, CC.doEvalExpr, entry, destination, result, width, CC.typeof,
      CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.classifyBool, CC.typeconv, CC.removeAttributes,
      CC.tattr, CC.tptr, CC.tulong, CC.tuchar, CC.Archi.ptr64]
  · simpa +decide [CC.Genv.findFunct, CC.Integers.Ptrofs.eq, CC.Integers.Ptrofs.zero,
      CC.Integers.MI.eq, CC.Integers.MI.zero] using binding.2
  · rfl

/-- Both actual stores and the real caller return, on this reached heap. -/
theorem scalar_write {initial memory : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial memory entry) (i : Fin 31)
    (value : BitVec 64) (narrow : Bool) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (unshadowed : e.get Arm64Program._kprog_arm64_program_write = none)
    (entryRead : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (destination : le.get Arm64Program._dst = some (.Vlong (BitVec.ofNat 64 i.val)))
    (result : le.get Arm64Program.___a64_l_result__3 = some (.Vlong value))
    (width : le.get Arm64Program.___a64_l_width = some (Arm64RegisterWrite.width narrow)) :
    ∃ after, Arm64RegisterWrite.Result storage i value narrow after ∧
      InternalRun Arm64ProgramEntryLinked.ge 69
        (.State Arm64Nop.handler ReadEntry.writer k e le memory)
        (.State Arm64Nop.handler .Sskip k e le after) := by
  obtain ⟨after, written⟩ := Arm64RegisterWrite.write storage i value narrow
  obtain ⟨middle, word, tag⟩ := written.stores
  have call : InternalRun Arm64ProgramEntryLinked.ge 1
      (.State Arm64Nop.handler ReadEntry.writer k e le memory)
      (.Callstate (.Internal Arm64RegisterWrite.procedure)
        (Arm64RegisterWrite.arguments entry.block i value narrow)
        (.Kcall none Arm64Nop.handler e le k) memory) :=
    .step trivial (scalar_call Arm64ProgramEntryLinked.ge (CC.Positive.ofNat 107) entry.block
      Arm64MovKeep.Linked.writer_binding e le memory k (BitVec.ofNat 64 i.val) value narrow
      unshadowed entryRead destination result width) (.refl _)
  have write := Arm64RegisterWrite.execute_stores_layout Arm64ProgramEntryLinked.ge
    Arm64MovKeep.Linked.writer_layout (.Kcall none Arm64Nop.handler e le k) rfl
    initial memory middle after entry storage i value narrow word tag
  have finish : InternalRun Arm64ProgramEntryLinked.ge 1
      (.Returnstate .Vundef (.Kcall none Arm64Nop.handler e le k) after)
      (.State Arm64Nop.handler .Sskip k e le after) :=
    .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  exact ⟨after, written, (call.trans write).trans finish⟩

end KProgFormal.ClightRefinement.Arm64Cneg.Write
