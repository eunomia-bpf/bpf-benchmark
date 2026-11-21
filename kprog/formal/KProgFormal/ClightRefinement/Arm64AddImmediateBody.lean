import KProgFormal.ClightRefinement.Arm64AddImmediatePointerCall

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64AddImmediate.Body

/-- Expand only the exact reached operand temporaries, without changing their source. -/
private theorem operand_temps_source (le : CC.TempEnv) (lhs rhs : BitVec 64) :
    Operands.tailTemps le false lhs rhs =
      rhsTemps (((le.set Arm64Program.___a64_alu_width (.Vint (8#32))).set
        Arm64Program._t'7 (.Vlong lhs)).set Arm64Program.___a64_alu_lhs (.Vlong lhs)) rhs := rfl

private theorem candidate_temps_source (le : CC.TempEnv) (lhs rhs : BitVec 64) :
    Tail.candidateTemps le lhs rhs =
      ((((((le.set Arm64Program.___a64_alu_op (.Vint 0)).set Arm64Program._t'14 (.Vint (4#32))).set Arm64Program.___a64_alu_src_tag (.Vint (4#32))).set Arm64Program.___kprog_alu64_res (.Vlong (0#64))).set Arm64Program.___kprog_alu64_res (.Vlong (lhs + rhs))).set Arm64Program.___a64_alu_result (.Vlong (lhs + rhs))) := rfl

def operandTemps (le : CC.TempEnv) (native : Reference.AArch64.State) (rhs : BitVec 64) : CC.TempEnv :=
  Operands.tailTemps (Dispatch.temps le false) false (Reference.AArch64.sp native) rhs

def selectionTemps (le : CC.TempEnv) (native : Reference.AArch64.State) (rhs : BitVec 64) : CC.TempEnv :=
  Tail.candidateTemps (operandTemps le native rhs) (Reference.AArch64.sp native) rhs

def finalTemps (le : CC.TempEnv) (native : Reference.AArch64.State) (rhs raw : BitVec 64) : CC.TempEnv :=
  Pointer.writerTemps (selectionTemps le native rhs) raw

def continuation (k : CC.Cont) : CC.Cont := Operands.tailCont (Dispatch.continuation k)

set_option hygiene false in
private theorem leave_loops (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    InternalRun world 4 (.State Arm64Nop.handler .Sskip (continuation k) e le m)
      (.State Arm64Nop.handler .Sskip k e le m) := by
  run_tac do
    for _ in [:4] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp only [CC.doStep, continuation,
        Operands.tailCont, Dispatch.continuation, CC.E0, CC.Eapp, List.nil_append] <;> try rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

/-- Compose the unchanged whole generic body, including both loops, on one heap.
All source-temporary, provider-free and writer-store obligations come from the
actual preceding fragments and the same reached register/cache resources. -/
theorem execute {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (native : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      m.nextblock m (.Vptr entry.block 0) native)
    (cache : Arm64RegisterReads.WarmEntryCache false m.nextblock m (.Vptr entry.block 0) origins.stack)
    (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (i : Fin 31) (rhs : BitVec 64)
    (widthName : e.get Arm64Program._arm64_width_effective = none)
    (readName : e.get Arm64Program._kprog_arm64_program_read = none)
    (selectorName : e.get Arm64Program._kprog_arm64_alu_source = none)
    (tagName : e.get Arm64Program._kprog_arm64_program_tag = none)
    (pointerName : e.get Arm64Program._kprog_arm64_program_pointer = none)
    (writerName : e.get Arm64Program._kprog_arm64_program_write_pointer = none)
    (entryTemp : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (src : le.get Arm64Program._src = some (.Vlong (32#64)))
    (flags : le.get Arm64Program._flags = some (.Vint (8#32)))
    (op : le.get Arm64Program._op = some (.Vint (3#32)))
    (aux : le.get Arm64Program._aux = some (.Vint (0#32)))
    (dst : le.get Arm64Program._dst = some (.Vlong (BitVec.ofNat 64 i.val)))
    (immediate : le.get Arm64Program._imm = some (.Vlong rhs)) :
    ∃ after, Arm64PointerWrite.Result storage i (storage.spValue + rhs) (4#8) after ∧
      InternalRun Arm64ProgramEntryLinked.ge 331
        (.State Arm64Nop.handler Arm64Nop.handler.fn_body k e le m)
        (.State Arm64Nop.handler .Sskip k e (finalTemps le native rhs storage.spValue) after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) m.nextblock after (.Vptr entry.block 0)
        (Arm64PointerWrite.nativeUpdate origins native i (storage.spValue + rhs) (4#8)) ∧
      Arm64CacheLocalFrame.Kept initial m after i := by
  have operands := body_operands addresses origins m.nextblock entry.block 0 m native represented cache
    e le k false rhs widthName readName selectorName entryTemp src flags op immediate
  have arithmetic : InternalRun Arm64ProgramEntryLinked.ge 43
      (.State Arm64Nop.handler Operands.tail (continuation k) e (operandTemps le native rhs) m)
      (.State Arm64Nop.handler Tail.selection (continuation k) e (selectionTemps le native rhs) m) := by
    apply Tail.evaluate entry.block 0 e (operandTemps le native rhs) m (continuation k)
      (Reference.AArch64.sp native) rhs tagName
    all_goals simp +decide only [operandTemps, operand_temps_source, rhsTemps,
      Dispatch.temps, Arm64Nop.resultEnv, CC.PTree.gss, CC.PTree.gso,
      entryTemp, src, aux, immediate]
  have ready :
      (selectionTemps le native rhs).get Arm64Program._entry = some (.Vptr entry.block 0) ∧
      (selectionTemps le native rhs).get Arm64Program._src = some (.Vlong (32#64)) ∧
      (selectionTemps le native rhs).get Arm64Program.___a64_alu_width = some (.Vint (8#32)) ∧
      (selectionTemps le native rhs).get Arm64Program._dst = some (.Vlong (BitVec.ofNat 64 i.val)) ∧
      (selectionTemps le native rhs).get Arm64Program.___a64_alu_op = some (.Vint (0#32)) ∧
      (selectionTemps le native rhs).get Arm64Program.___a64_alu_src_tag = some (.Vint (4#32)) ∧
      (selectionTemps le native rhs).get Arm64Program.___a64_alu_rhs = some (.Vlong rhs) := by
    simp +decide only [selectionTemps, candidate_temps_source, operandTemps, operand_temps_source,
      rhsTemps, Dispatch.temps, Arm64Nop.resultEnv, CC.PTree.gss, CC.PTree.gso,
      entryTemp, src, dst, immediate, and_self]
  obtain ⟨after, result, write, registers, kept⟩ := Pointer.execute storage addresses origins native represented
    e (selectionTemps le native rhs) (continuation k) i rhs pointerName writerName
    ready.1 ready.2.1 ready.2.2.1 ready.2.2.2.1 ready.2.2.2.2.1 ready.2.2.2.2.2.1 ready.2.2.2.2.2.2
  have leave := leave_loops Arm64ProgramEntryLinked.ge e
    (finalTemps le native rhs storage.spValue) after k
  exact ⟨after, result, ((operands.trans arithmetic).trans write).trans leave, registers, kept⟩

end KProgFormal.ClightRefinement.Arm64AddImmediate.Body
