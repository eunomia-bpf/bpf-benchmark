import KProgFormal.ClightRefinement.Arm64AddImmediateOperands
import KProgFormal.ClightRefinement.Arm64AddRegisterModifier

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64AddRegisterPrefix
open Arm64AddImmediate

/-- The actual LHS temporaries at the original RHS loop. -/
def beforeRhs (le : CC.TempEnv) (lhs : BitVec 64) : CC.TempEnv :=
  Operands.lhsTemps (Dispatch.registerTemps le false) false lhs

/-- Actual temporaries after the source AUX256/LSL0 suffix. -/
def afterRhs (le : CC.TempEnv) (lhs rhs : BitVec 64) : CC.TempEnv :=
  Arm64AddRegisterModifier.finalTemps (beforeRhs le lhs) rhs

/-- One source-linked run through the original dispatch, scalar LHS, warm
STACK RHS and actual LSL0 case to the original arithmetic/tag tail. Every
segment shares the same memory, with no replayed provider or post-read heap. -/
theorem body_operands {initial memory : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial memory entry)
    (i j : Fin 31) (lhs raw base : BitVec 64) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (widthName : e.get Arm64Program._arm64_width_effective = none)
    (readName : e.get Arm64Program._kprog_arm64_program_read = none)
    (selectorName : e.get Arm64Program._kprog_arm64_alu_source = none)
    (entryRead : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (source : le.get Arm64Program._src = some (.Vlong (BitVec.ofNat 64 i.val)))
    (source2 : le.get Arm64Program._src2 = some (.Vlong (BitVec.ofNat 64 j.val)))
    (flags : le.get Arm64Program._flags = some (Arm64Width.argument (8#8)))
    (op : le.get Arm64Program._op = some (.Vint (7#32)))
    (aux : le.get Arm64Program._aux = some (.Vint (256#32)))
    (lhsWord : CC.Mem.load .Mint64 memory ((storage.tables false).cellBlock i) 0 = some (.Vlong lhs))
    (lhsTag : CC.Mem.load .Mint8unsigned memory ((storage.tables true).cellBlock i) 0 = some (.Vint 0))
    (rhsWord : CC.Mem.load .Mint64 memory ((storage.tables false).cellBlock j) 0 = some (.Vlong raw))
    (rhsTag : CC.Mem.load .Mint8unsigned memory ((storage.tables true).cellBlock j) 0 = some (.Vint (4#32)))
    (cache : Arm64RegisterReads.WarmEntryCache false memory.nextblock memory (.Vptr entry.block 0) base) :
    InternalRun Arm64ProgramEntryLinked.ge 286
      (.State Arm64Nop.handler Arm64Nop.handler.fn_body k e le memory)
      (.State Arm64Nop.handler Operands.tail (Operands.tailCont (Dispatch.continuation k)) e
        (afterRhs le lhs (raw + base)) memory) := by
  have dispatch := Dispatch.Linked.body_dispatch_register e le memory k false widthName flags op
  have entry1 : (Dispatch.registerTemps le false).get Arm64Program._entry = some (.Vptr entry.block 0) := by
    simp +decide only [Dispatch.registerTemps, Arm64Nop.resultEnv, CC.PTree.gso, entryRead]
  have source1 : (Dispatch.registerTemps le false).get Arm64Program._src = some (.Vlong (BitVec.ofNat 64 i.val)) := by
    simp +decide only [Dispatch.registerTemps, Arm64Nop.resultEnv, CC.PTree.gso, source]
  have effective : (Dispatch.registerTemps le false).get Arm64Program.___a64_l_width = some (Operands.width false) := by
    simp +decide [Dispatch.registerTemps, Arm64Nop.resultEnv, Operands.width, Dispatch.flags,
      Arm64Width.result, Arm64Width.argument, CC.PTree.gss, CC.PTree.gso]
  have lhsRun := Operands.lhs_scalar storage i lhs e (Dispatch.registerTemps le false)
    (Dispatch.continuation k) false readName entry1 source1 effective lhsWord lhsTag
  have op2 : (beforeRhs le lhs).get Arm64Program._op = some (.Vint (7#32)) := by
    simp +decide only [beforeRhs, Operands.lhsTemps, Operands.widthTemps, Dispatch.registerTemps,
      Arm64Nop.resultEnv, CC.PTree.gso, op]
  have entry2 : (beforeRhs le lhs).get Arm64Program._entry = some (.Vptr entry.block 0) := by
    simp +decide only [beforeRhs, Operands.lhsTemps, Operands.widthTemps, Dispatch.registerTemps,
      Arm64Nop.resultEnv, CC.PTree.gso, entryRead]
  have source2' : (beforeRhs le lhs).get Arm64Program._src2 = some (.Vlong (BitVec.ofNat 64 j.val)) := by
    simp +decide only [beforeRhs, Operands.lhsTemps, Operands.widthTemps, Dispatch.registerTemps,
      Arm64Nop.resultEnv, CC.PTree.gso, source2]
  have aux2 : (beforeRhs le lhs).get Arm64Program._aux = some (.Vint (256#32)) := by
    simp +decide only [beforeRhs, Operands.lhsTemps, Operands.widthTemps, Dispatch.registerTemps,
      Arm64Nop.resultEnv, CC.PTree.gso, aux]
  have width2 : (beforeRhs le lhs).get Arm64Program.___a64_alu_width = some (.Vint (8#32)) := by
    simp +decide only [beforeRhs, Operands.lhsTemps, Operands.widthTemps, Operands.width,
      Dispatch.flags, Arm64Width.argument, CC.PTree.gss, CC.PTree.gso]
  have rhsRun := Arm64AddRegisterOperands.Linked.rhs_stack storage j raw base e (beforeRhs le lhs)
    (Operands.rhsCont (Dispatch.continuation k)) selectorName readName op2 entry2 source2' rhsWord rhsTag cache
  have modify := Arm64AddRegisterModifier.finish_lsl_zero Arm64ProgramEntryLinked.ge e
    (beforeRhs le lhs) memory (Operands.rhsCont (Dispatch.continuation k)) (raw + base) aux2 width2
  have leave : InternalRun Arm64ProgramEntryLinked.ge 1
      (.State Arm64Nop.handler .Sskip (Operands.rhsCont (Dispatch.continuation k)) e
        (afterRhs le lhs (raw + base)) memory)
      (.State Arm64Nop.handler Operands.tail (Operands.tailCont (Dispatch.continuation k)) e
        (afterRhs le lhs (raw + base)) memory) :=
    .step trivial (.skip_seq _ _ _ _ _ _) (.refl _)
  simpa only [beforeRhs, afterRhs] using (((dispatch.trans lhsRun).trans rhsRun).trans modify).trans leave

end KProgFormal.ClightRefinement.Arm64AddRegisterPrefix
