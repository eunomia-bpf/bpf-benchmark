import KProgFormal.ClightRefinement.Arm64CnegCaller
import KProgFormal.ClightRefinement.Arm64ProgramEntrySelectPrefixNative

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Cneg

open Arm64Producer (HeaderLocal)
open Arm64ProducerRegisterStorage

/-- The actual CSEL input observations and its real stored result determine
CNEG's scalar/tag input. Both native choices retain the original Clight value;
stack-relative words retain tag4 and scalar words retain tag0. -/
theorem selected_source {initial before written after : CC.Mem} {entry : HeaderLocal initial}
    {storage : Storage initial before entry} {addresses : Arm64Registers.PointerOrigins}
    {origins : Reference.Provenance.AArch64.Origins} {native : Reference.AArch64.State}
    {k : CC.Cont} {count : Nat} {value : CC.Val} {raw : BitVec 64} {tag : BitVec 8}
    {finalStorage : Storage initial after entry}
    (result : Arm64Select.Call.Result storage addresses origins native k count value raw tag written after finalStorage)
    (scalar stack : BitVec 64)
    (scalarWord : CC.Mem.load .Mint64 before ((storage.tables false).cellBlock 1) 0 = some (.Vlong scalar))
    (scalarTag : CC.Mem.load .Mint8unsigned before ((storage.tables true).cellBlock 1) 0 = some (.Vint 0))
    (stackWord : CC.Mem.load .Mint64 before ((storage.tables false).cellBlock 2) 0 = some (.Vlong stack))
    (stackTag : CC.Mem.load .Mint8unsigned before ((storage.tables true).cellBlock 2) 0 = some (.Vint (4#32))) :
    ∃ bits kind, (kind = (0#8) ∨ kind = (4#8)) ∧
      Arm64EntryMemory.gpr after.nextblock after (.Vptr entry.block 0) 5 =
        some (.Vlong bits, .Vint (kind.setWidth 32)) := by
  let bits := if ConditionHolds (0#4) native.machine then scalar else stack
  let kind : BitVec 8 := if ConditionHolds (0#4) native.machine then 0 else 4
  have actual : Arm64EntryMemory.gpr before.nextblock before (.Vptr entry.block 0)
      (if ConditionHolds (0#4) native.machine then (1 : Fin 31) else 2).val =
        some (.Vlong bits, .Vint (kind.setWidth 32)) := by
    by_cases choice : ConditionHolds (0#4) native.machine
    · simp only [choice, ite_true, bits, kind]
      rw [Arm64RegisterWrite.storage_gpr storage 1, scalarWord, scalarTag]
      rfl
    · simp only [choice, Bool.false_eq_true, ite_false, bits, kind]
      rw [Arm64RegisterWrite.storage_gpr storage 2, stackWord, stackTag]
      rfl
  have same := Option.some.inj (result.selected.symm.trans actual)
  have valueEq : value = .Vlong bits := congrArg Prod.fst same
  have kindEq : tag = kind := by
    have widened := CC.Val.Vint.inj (congrArg Prod.snd same)
    simpa using congrArg (fun bits : BitVec 32 => bits.setWidth 8) widened
  refine ⟨bits, kind, ?_, ?_⟩
  · by_cases choice : ConditionHolds (0#4) native.machine <;> simp [kind, choice]
  · change Arm64EntryMemory.gpr after.nextblock after (.Vptr entry.block 0) (5 : Fin 31).val = _
    rw [Arm64RegisterWrite.storage_gpr finalStorage 5, result.word, result.tagRead, valueEq, kindEq]
    rfl

end KProgFormal.ClightRefinement.Arm64Cneg
