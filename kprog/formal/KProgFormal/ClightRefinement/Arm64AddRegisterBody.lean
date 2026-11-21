import KProgFormal.ClightRefinement.Arm64AddRegisterPrefix
import KProgFormal.ClightRefinement.Arm64AddImmediatePointer

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64AddRegisterBody
open Arm64AddImmediate

/-- The original scalar writer edge, without replacing the call by its result. -/
private theorem scalar_call (world : CC.CGenv) (block b : CC.Block)
    (binding : CC.Genv.findSymbol world.genv_genv Arm64Program._kprog_arm64_program_write = some block ∧
      CC.Genv.findFunctPtr world.genv_genv block = some (.Internal Arm64RegisterWrite.procedure))
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (dst value : BitVec 64)
    (unshadowed : e.get Arm64Program._kprog_arm64_program_write = none)
    (entry : le.get Arm64Program._entry = some (.Vptr b 0))
    (destination : le.get Arm64Program._dst = some (.Vlong dst))
    (result : le.get Arm64Program.___a64_alu_result = some (.Vlong value))
    (width : le.get Arm64Program.___a64_alu_width = some (.Vint (8#32))) :
    CC.Step2 world (.State Arm64Nop.handler Pointer.scalar k e le m) CC.E0
      (.Callstate (.Internal Arm64RegisterWrite.procedure)
        [.Vptr b 0, .Vlong dst, .Vlong value, .Vint (8#32)]
        (.Kcall none Arm64Nop.handler e le k) m) := by
  have source : Pointer.scalar = .Scall none
      (.Evar Arm64Program._kprog_arm64_program_write
        (.Tfunction [CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr), CC.tulong,
          CC.tulong, CC.tuchar] CC.tvoid CC.cc_default))
      [.Etempvar Arm64Program._entry (CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr)),
       .Etempvar Arm64Program._dst CC.tulong,
       .Etempvar Arm64Program.___a64_alu_result CC.tulong,
       .Etempvar Arm64Program.___a64_alu_width CC.tuchar] := rfl
  rw [source]
  apply CC.Step.call
    (tyargs := [CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr), CC.tulong, CC.tulong, CC.tuchar])
    (tyres := CC.tvoid) (cconv := CC.cc_default) (vf := .Vptr block 0)
  · rfl
  · apply CC.doEvalExpr_sound
    simp only [CC.doEvalExpr, CC.doEvalLvalue, CC.lvalOfVar, CC.doDerefLoc, CC.accessMode,
      CC.typeof, unshadowed, binding.1, CC.Integers.Ptrofs.zero, CC.Integers.MI.zero]
  · apply CC.doEvalExprlist_sound
    simp +decide [CC.doEvalExprlist, CC.doEvalExpr, entry, destination, result, width, CC.typeof,
      CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.classifyBool, CC.typeconv, CC.removeAttributes,
      CC.tattr, CC.tptr, CC.tulong, CC.tuchar, CC.Archi.ptr64]
  · simpa +decide [CC.Genv.findFunct, CC.Integers.Ptrofs.eq, CC.Integers.Ptrofs.zero,
      CC.Integers.MI.eq, CC.Integers.MI.zero] using binding.2
  · rfl

/-- Both actual stores and the real caller return, on this reached heap. -/
theorem scalar_write {initial memory : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial memory entry) (i : Fin 31)
    (value : BitVec 64) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (unshadowed : e.get Arm64Program._kprog_arm64_program_write = none)
    (entryRead : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (destination : le.get Arm64Program._dst = some (.Vlong (BitVec.ofNat 64 i.val)))
    (result : le.get Arm64Program.___a64_alu_result = some (.Vlong value))
    (width : le.get Arm64Program.___a64_alu_width = some (.Vint (8#32))) :
    ∃ after, Arm64RegisterWrite.Result storage i value false after ∧
      InternalRun Arm64ProgramEntryLinked.ge 69
        (.State Arm64Nop.handler Pointer.scalar k e le memory)
        (.State Arm64Nop.handler .Sskip k e le after) := by
  obtain ⟨after, written⟩ := Arm64RegisterWrite.write storage i value false
  obtain ⟨middle, word, tag⟩ := written.stores
  have call : InternalRun Arm64ProgramEntryLinked.ge 1
      (.State Arm64Nop.handler Pointer.scalar k e le memory)
      (.Callstate (.Internal Arm64RegisterWrite.procedure)
        (Arm64RegisterWrite.arguments entry.block i value false)
        (.Kcall none Arm64Nop.handler e le k) memory) :=
    .step trivial (scalar_call Arm64ProgramEntryLinked.ge (CC.Positive.ofNat 107) entry.block
      Arm64MovKeep.Linked.writer_binding e le memory k (BitVec.ofNat 64 i.val) value
      unshadowed entryRead destination result width) (.refl _)
  have write := Arm64RegisterWrite.execute_stores_layout Arm64ProgramEntryLinked.ge
    Arm64MovKeep.Linked.writer_layout (.Kcall none Arm64Nop.handler e le k) rfl
    initial memory middle after entry storage i value false word tag
  have finish : InternalRun Arm64ProgramEntryLinked.ge 1
      (.Returnstate .Vundef (.Kcall none Arm64Nop.handler e le k) after)
      (.State Arm64Nop.handler .Sskip k e le after) :=
    .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  exact ⟨after, written, (call.trans write).trans finish⟩

/-- Actual temporary stores through all operand/candidate/selection stages. -/
def finalTemps (le : CC.TempEnv) (lhs rhs : BitVec 64) : CC.TempEnv :=
  Pointer.scalarTemps (Tail.scalarCandidateTemps (Arm64AddRegisterPrefix.afterRhs le lhs rhs) lhs rhs)

set_option hygiene false in
private theorem leave_loops (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    InternalRun world 4
      (.State Arm64Nop.handler .Sskip (Operands.tailCont (Dispatch.continuation k)) e le m)
      (.State Arm64Nop.handler .Sskip k e le m) := by
  run_tac do
    for _ in [:4] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

private theorem scalar_candidate_source (le : CC.TempEnv) (lhs rhs : BitVec 64) :
    Tail.scalarCandidateTemps le lhs rhs =
      ((((((le.set Arm64Program.___a64_alu_op (.Vint 0)).set Arm64Program._t'14 (.Vint 0)).set
        Arm64Program.___a64_alu_src_tag (.Vint 0)).set Arm64Program.___kprog_alu64_res (.Vlong 0)).set
        Arm64Program.___kprog_alu64_res (.Vlong (lhs + rhs))).set
        Arm64Program.___a64_alu_result (.Vlong (lhs + rhs))) := rfl

private theorem operand_entry (le : CC.TempEnv) (lhs rhs : BitVec 64) (value : CC.Val)
    (read : le.get Arm64Program._entry = some value) :
    (Arm64AddRegisterPrefix.afterRhs le lhs rhs).get Arm64Program._entry = some value := by
  simp +decide only [Arm64AddRegisterPrefix.afterRhs,
    Arm64AddRegisterModifier.finalTemps, Arm64AddRegisterModifier.prefixTemps,
    Arm64AddRegisterOperands.selectedTemps, Arm64AddRegisterPrefix.beforeRhs,
    Operands.lhsTemps, Operands.widthTemps, Operands.width, Dispatch.flags, Arm64Width.argument,
    Dispatch.registerTemps, Arm64Nop.resultEnv, CC.PTree.gss, CC.PTree.gso, read]

private theorem operand_source (le : CC.TempEnv) (lhs rhs : BitVec 64) (value : CC.Val)
    (read : le.get Arm64Program._src = some value) :
    (Arm64AddRegisterPrefix.afterRhs le lhs rhs).get Arm64Program._src = some value := by
  simp +decide only [Arm64AddRegisterPrefix.afterRhs,
    Arm64AddRegisterModifier.finalTemps, Arm64AddRegisterModifier.prefixTemps,
    Arm64AddRegisterOperands.selectedTemps, Arm64AddRegisterPrefix.beforeRhs,
    Operands.lhsTemps, Operands.widthTemps, Operands.width, Dispatch.flags, Arm64Width.argument,
    Dispatch.registerTemps, Arm64Nop.resultEnv, CC.PTree.gss, CC.PTree.gso, read]

private theorem operand_aux (le : CC.TempEnv) (lhs rhs : BitVec 64) (value : CC.Val)
    (read : le.get Arm64Program._aux = some value) :
    (Arm64AddRegisterPrefix.afterRhs le lhs rhs).get Arm64Program._aux = some value := by
  simp +decide only [Arm64AddRegisterPrefix.afterRhs,
    Arm64AddRegisterModifier.finalTemps, Arm64AddRegisterModifier.prefixTemps,
    Arm64AddRegisterOperands.selectedTemps, Arm64AddRegisterPrefix.beforeRhs,
    Operands.lhsTemps, Operands.widthTemps, Operands.width, Dispatch.flags, Arm64Width.argument,
    Dispatch.registerTemps, Arm64Nop.resultEnv, CC.PTree.gss, CC.PTree.gso, read]

private theorem operand_destination (le : CC.TempEnv) (lhs rhs : BitVec 64) (value : CC.Val)
    (read : le.get Arm64Program._dst = some value) :
    (Arm64AddRegisterPrefix.afterRhs le lhs rhs).get Arm64Program._dst = some value := by
  simp +decide only [Arm64AddRegisterPrefix.afterRhs,
    Arm64AddRegisterModifier.finalTemps, Arm64AddRegisterModifier.prefixTemps,
    Arm64AddRegisterOperands.selectedTemps, Arm64AddRegisterPrefix.beforeRhs,
    Operands.lhsTemps, Operands.widthTemps, Operands.width, Dispatch.flags, Arm64Width.argument,
    Dispatch.registerTemps, Arm64Nop.resultEnv, CC.PTree.gss, CC.PTree.gso, read]

private theorem operand_left (le : CC.TempEnv) (lhs rhs : BitVec 64) :
    (Arm64AddRegisterPrefix.afterRhs le lhs rhs).get Arm64Program.___a64_alu_lhs = some (.Vlong lhs) := by
  simp +decide only [Arm64AddRegisterPrefix.afterRhs,
    Arm64AddRegisterModifier.finalTemps, Arm64AddRegisterModifier.prefixTemps,
    Arm64AddRegisterOperands.selectedTemps, Arm64AddRegisterPrefix.beforeRhs,
    Operands.lhsTemps, Operands.widthTemps, Operands.width, Dispatch.flags, Arm64Width.argument,
    Dispatch.registerTemps, Arm64Nop.resultEnv, CC.PTree.gss, CC.PTree.gso]

private theorem operand_right (le : CC.TempEnv) (lhs rhs : BitVec 64) :
    (Arm64AddRegisterPrefix.afterRhs le lhs rhs).get Arm64Program.___a64_alu_rhs = some (.Vlong rhs) := by
  simp +decide only [Arm64AddRegisterPrefix.afterRhs,
    Arm64AddRegisterModifier.finalTemps, Arm64AddRegisterModifier.prefixTemps,
    Arm64AddRegisterOperands.selectedTemps, Arm64AddRegisterPrefix.beforeRhs,
    Operands.lhsTemps, Operands.widthTemps, Operands.width, Dispatch.flags, Arm64Width.argument,
    Dispatch.registerTemps, Arm64Nop.resultEnv, CC.PTree.gss, CC.PTree.gso]

private theorem operand_width (le : CC.TempEnv) (lhs rhs : BitVec 64) :
    (Arm64AddRegisterPrefix.afterRhs le lhs rhs).get Arm64Program.___a64_alu_width = some (.Vint (8#32)) := by
  simp +decide only [Arm64AddRegisterPrefix.afterRhs,
    Arm64AddRegisterModifier.finalTemps, Arm64AddRegisterModifier.prefixTemps,
    Arm64AddRegisterOperands.selectedTemps, Arm64AddRegisterPrefix.beforeRhs,
    Operands.lhsTemps, Operands.widthTemps, Operands.width, Dispatch.flags, Arm64Width.argument,
    Dispatch.registerTemps, Arm64Nop.resultEnv, CC.PTree.gss, CC.PTree.gso]

private theorem candidate_ready (le : CC.TempEnv) (lhs rhs : BitVec 64)
    (entry destination : CC.Val)
    (he : le.get Arm64Program._entry = some entry)
    (hw : le.get Arm64Program.___a64_alu_width = some (.Vint (8#32)))
    (hd : le.get Arm64Program._dst = some destination) :
    (Tail.scalarCandidateTemps le lhs rhs).get Arm64Program._entry = some entry ∧
    (Tail.scalarCandidateTemps le lhs rhs).get Arm64Program.___a64_alu_width = some (.Vint (8#32)) ∧
    (Tail.scalarCandidateTemps le lhs rhs).get Arm64Program._dst = some destination ∧
    (Tail.scalarCandidateTemps le lhs rhs).get Arm64Program.___a64_alu_op = some (.Vint 0) ∧
    (Tail.scalarCandidateTemps le lhs rhs).get Arm64Program.___a64_alu_src_tag = some (.Vint 0) ∧
    (Tail.scalarCandidateTemps le lhs rhs).get Arm64Program.___a64_alu_result = some (.Vlong (lhs + rhs)) := by
  simp +decide only [scalar_candidate_source, CC.PTree.gss, CC.PTree.gso, he, hw, hd, and_self]

/-- The unchanged generic source body, including scalar destination stores,
actual writer return and both loops. Its own local frame remains live. -/
theorem execute {initial memory : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial memory entry)
    (i j dst : Fin 31) (lhs raw base : BitVec 64) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (widthName : e.get Arm64Program._arm64_width_effective = none)
    (readName : e.get Arm64Program._kprog_arm64_program_read = none)
    (selectorName : e.get Arm64Program._kprog_arm64_alu_source = none)
    (tagName : e.get Arm64Program._kprog_arm64_program_tag = none)
    (writerName : e.get Arm64Program._kprog_arm64_program_write = none)
    (entryRead : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (source : le.get Arm64Program._src = some (.Vlong (BitVec.ofNat 64 i.val)))
    (source2 : le.get Arm64Program._src2 = some (.Vlong (BitVec.ofNat 64 j.val)))
    (destination : le.get Arm64Program._dst = some (.Vlong (BitVec.ofNat 64 dst.val)))
    (flags : le.get Arm64Program._flags = some (Arm64Width.argument (8#8)))
    (op : le.get Arm64Program._op = some (.Vint (7#32)))
    (aux : le.get Arm64Program._aux = some (.Vint (256#32)))
    (lhsWord : CC.Mem.load .Mint64 memory ((storage.tables false).cellBlock i) 0 = some (.Vlong lhs))
    (lhsTag : CC.Mem.load .Mint8unsigned memory ((storage.tables true).cellBlock i) 0 = some (.Vint 0))
    (rhsWord : CC.Mem.load .Mint64 memory ((storage.tables false).cellBlock j) 0 = some (.Vlong raw))
    (rhsTag : CC.Mem.load .Mint8unsigned memory ((storage.tables true).cellBlock j) 0 = some (.Vint (4#32)))
    (cache : Arm64RegisterReads.WarmEntryCache false memory.nextblock memory (.Vptr entry.block 0) base) :
    ∃ after, Arm64RegisterWrite.Result storage dst (lhs + (raw + base)) false after ∧
      InternalRun Arm64ProgramEntryLinked.ge 467
        (.State Arm64Nop.handler Arm64Nop.handler.fn_body k e le memory)
        (.State Arm64Nop.handler .Sskip k e (finalTemps le lhs (raw + base)) after) := by
  have operands := Arm64AddRegisterPrefix.body_operands storage i j lhs raw base e le k
    widthName readName selectorName entryRead source source2 flags op aux lhsWord lhsTag rhsWord rhsTag cache
  have arithmetic : InternalRun Arm64ProgramEntryLinked.ge 56
      (.State Arm64Nop.handler Operands.tail (Operands.tailCont (Dispatch.continuation k)) e
        (Arm64AddRegisterPrefix.afterRhs le lhs (raw + base)) memory)
      (.State Arm64Nop.handler Tail.selection (Operands.tailCont (Dispatch.continuation k)) e
        (Tail.scalarCandidateTemps (Arm64AddRegisterPrefix.afterRhs le lhs (raw + base)) lhs (raw + base)) memory) := by
    exact Tail.evaluate_scalar storage i e (Arm64AddRegisterPrefix.afterRhs le lhs (raw + base))
      (Operands.tailCont (Dispatch.continuation k)) lhs (raw + base) tagName
      (operand_entry le lhs (raw + base) _ entryRead)
      (operand_source le lhs (raw + base) _ source)
      (operand_aux le lhs (raw + base) _ aux)
      (operand_left le lhs (raw + base)) (operand_right le lhs (raw + base)) lhsTag
  let candidateTemps := Tail.scalarCandidateTemps (Arm64AddRegisterPrefix.afterRhs le lhs (raw + base)) lhs (raw + base)
  have candidateReady := candidate_ready (Arm64AddRegisterPrefix.afterRhs le lhs (raw + base)) lhs (raw + base)
    (.Vptr entry.block 0) (.Vlong (BitVec.ofNat 64 dst.val))
    (operand_entry le lhs (raw + base) _ entryRead) (operand_width le lhs (raw + base))
    (operand_destination le lhs (raw + base) _ destination)
  have notSP : ∀ d : Fin 31, BitVec.ofNat 64 d.val ≠ (32#64) := by decide +kernel
  have select := Pointer.select_scalar Arm64ProgramEntryLinked.ge e candidateTemps memory
    (Operands.tailCont (Dispatch.continuation k)) (BitVec.ofNat 64 dst.val) (notSP dst)
    candidateReady.2.1 candidateReady.2.2.1 candidateReady.2.2.2.1 candidateReady.2.2.2.2.1
  have ready :
      (finalTemps le lhs (raw + base)).get Arm64Program._entry = some (.Vptr entry.block 0) ∧
      (finalTemps le lhs (raw + base)).get Arm64Program._dst = some (.Vlong (BitVec.ofNat 64 dst.val)) ∧
      (finalTemps le lhs (raw + base)).get Arm64Program.___a64_alu_result = some (.Vlong (lhs + (raw + base))) ∧
      (finalTemps le lhs (raw + base)).get Arm64Program.___a64_alu_width = some (.Vint (8#32)) := by
    change (Pointer.scalarTemps candidateTemps).get Arm64Program._entry = _ ∧
      (Pointer.scalarTemps candidateTemps).get Arm64Program._dst = _ ∧
      (Pointer.scalarTemps candidateTemps).get Arm64Program.___a64_alu_result = _ ∧
      (Pointer.scalarTemps candidateTemps).get Arm64Program.___a64_alu_width = _
    simp +decide only [Pointer.scalarTemps, CC.PTree.gso]
    exact ⟨candidateReady.1, candidateReady.2.2.1, candidateReady.2.2.2.2.2, candidateReady.2.1⟩
  obtain ⟨after, result, write⟩ := scalar_write storage dst (lhs + (raw + base)) e
    (finalTemps le lhs (raw + base)) (Operands.tailCont (Dispatch.continuation k)) writerName
    ready.1 ready.2.1 ready.2.2.1 ready.2.2.2
  have leave := leave_loops Arm64ProgramEntryLinked.ge e (finalTemps le lhs (raw + base)) after k
  exact ⟨after, result, (((operands.trans arithmetic).trans select).trans write).trans leave⟩

end KProgFormal.ClightRefinement.Arm64AddRegisterBody
