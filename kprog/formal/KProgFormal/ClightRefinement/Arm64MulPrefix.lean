import KProgFormal.ClightRefinement.Arm64MulOperands

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Mul.Prefix

def afterLhs (le : CC.TempEnv) (narrow : Bool) (lhs : BitVec 64) : CC.TempEnv :=
  Operands.lhsTemps (Dispatch.temps le narrow) lhs

def afterRhs (le : CC.TempEnv) (narrow : Bool) (lhs rhs : BitVec 64) : CC.TempEnv :=
  Operands.rhsTemps (afterLhs le narrow lhs) rhs

def finalTemps (le : CC.TempEnv) (narrow : Bool) (lhs rhs : BitVec 64) : CC.TempEnv :=
  Operands.addendTemps (afterRhs le narrow lhs rhs)

/-- One actual original dispatcher/three-reader prefix. All typed observations
belong to the same reached heap; the unused third read is actually executed. -/
theorem body_operands {initial memory : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial memory entry)
    (i j : Fin 31) (lhs rhs : BitVec 64) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (narrow : Bool)
    (widthName : e.get Arm64Program._arm64_width_effective = none)
    (readName : e.get Arm64Program._kprog_arm64_program_read = none)
    (entryRead : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (source : le.get Arm64Program._src = some (.Vlong (BitVec.ofNat 64 i.val)))
    (source2 : le.get Arm64Program._src2 = some (.Vlong (BitVec.ofNat 64 j.val)))
    (source3 : le.get Arm64Program._src3 = some (.Vlong (255#64)))
    (flags : le.get Arm64Program._flags = some (Arm64Width.argument (Dispatch.flags narrow)))
    (op : le.get Arm64Program._op = some (.Vint (12#32)))
    (lhsWord : CC.Mem.load .Mint64 memory ((storage.tables false).cellBlock i) 0 = some (.Vlong lhs))
    (lhsTag : CC.Mem.load .Mint8unsigned memory ((storage.tables true).cellBlock i) 0 = some (.Vint 0))
    (rhsWord : CC.Mem.load .Mint64 memory ((storage.tables false).cellBlock j) 0 = some (.Vlong rhs))
    (rhsTag : CC.Mem.load .Mint8unsigned memory ((storage.tables true).cellBlock j) 0 = some (.Vint 0)) :
    InternalRun Arm64ProgramEntryLinked.ge 348
      (.State Arm64Nop.handler Arm64Nop.handler.fn_body k e le memory)
      (.State Arm64Nop.handler Operands.product (Operands.tailCont (Dispatch.continuation k)) e
        (finalTemps le narrow lhs rhs) memory) := by
  have dispatch := Dispatch.Linked.body_dispatch e le memory k narrow widthName flags op
  have entry1 : (Dispatch.temps le narrow).get Arm64Program._entry = some (.Vptr entry.block 0) := by
    simp +decide only [Dispatch.temps, Arm64Nop.resultEnv, CC.PTree.gso, entryRead]
  have source1 : (Dispatch.temps le narrow).get Arm64Program._src = some (.Vlong (BitVec.ofNat 64 i.val)) := by
    simp +decide only [Dispatch.temps, Arm64Nop.resultEnv, CC.PTree.gso, source]
  have op1 : (Dispatch.temps le narrow).get Arm64Program._op = some (.Vint (12#32)) := by
    simp +decide only [Dispatch.temps, Arm64Nop.resultEnv, CC.PTree.gso, op]
  have left := Operands.lhs_scalar storage i lhs e (Dispatch.temps le narrow) (Dispatch.continuation k)
    readName entry1 source1 op1 lhsWord lhsTag
  have entry2 : (afterLhs le narrow lhs).get Arm64Program._entry = some (.Vptr entry.block 0) := by
    simp +decide only [afterLhs, Operands.lhsTemps, Operands.opTemps, Dispatch.temps,
      Arm64Nop.resultEnv, CC.PTree.gso, entryRead]
  have source2' : (afterLhs le narrow lhs).get Arm64Program._src2 = some (.Vlong (BitVec.ofNat 64 j.val)) := by
    simp +decide only [afterLhs, Operands.lhsTemps, Operands.opTemps, Dispatch.temps,
      Arm64Nop.resultEnv, CC.PTree.gso, source2]
  have op2 : (afterLhs le narrow lhs).get Arm64Program._op = some (.Vint (12#32)) := by
    simp +decide only [afterLhs, Operands.lhsTemps, Operands.opTemps, Dispatch.temps,
      Arm64Nop.resultEnv, CC.PTree.gso, op]
  have right := Operands.rhs_scalar storage j rhs e (afterLhs le narrow lhs) (Dispatch.continuation k)
    readName entry2 source2' op2 rhsWord rhsTag
  have entry3 : (afterRhs le narrow lhs rhs).get Arm64Program._entry = some (.Vptr entry.block 0) := by
    simp +decide only [afterRhs, Operands.rhsTemps, afterLhs, Operands.lhsTemps,
      Operands.opTemps, Dispatch.temps, Arm64Nop.resultEnv, CC.PTree.gso, entryRead]
  have source3' : (afterRhs le narrow lhs rhs).get Arm64Program._src3 = some (.Vlong (255#64)) := by
    simp +decide only [afterRhs, Operands.rhsTemps, afterLhs, Operands.lhsTemps,
      Operands.opTemps, Dispatch.temps, Arm64Nop.resultEnv, CC.PTree.gso, source3]
  have third := Operands.addend_zero entry.block 0 e (afterRhs le narrow lhs rhs) memory
    (Dispatch.continuation k) readName entry3 source3'
  simpa only [finalTemps, afterRhs, afterLhs] using ((dispatch.trans left).trans right).trans third

end KProgFormal.ClightRefinement.Arm64Mul.Prefix
