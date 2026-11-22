import KProgFormal.ClightRefinement.Arm64CompareFlagBytes
import KProgFormal.ClightRefinement.Arm64RegisterStorageFrontier

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64Compare.Native

private theorem stored_operand {initial memory : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial memory entry)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      memory.nextblock memory (.Vptr entry.block 0) s)
    (i : Fin 31) (raw : BitVec 64) (known : BitVec 8)
    (word : CC.Mem.load .Mint64 memory ((storage.tables false).cellBlock i) 0 = some (.Vlong raw))
    (kind : CC.Mem.load .Mint8unsigned memory ((storage.tables true).cellBlock i) 0 = some (.Vint (known.setWidth 32))) :
    Reference.AArch64.gpr s i = Reference.Provenance.AArch64.materialize origins raw known := by
  have actual : Arm64EntryMemory.gpr memory.nextblock memory (.Vptr entry.block 0) i.val =
      some (.Vlong raw, .Vint (known.setWidth 32)) := by
    rw [Arm64RegisterWrite.storage_gpr storage i, word, kind]
    rfl
  obtain ⟨value, bits, tag, read, representedValue, nativeWord⟩ := represented.gpr i
  have same := Option.some.inj (read.symm.trans actual)
  have valueEq : value = .Vlong raw := congrArg Prod.fst same
  have wideEq := CC.Val.Vint.inj (congrArg Prod.snd same)
  have tagEq : tag = known := by
    have narrowed := congrArg (fun bits : BitVec 32 => bits.setWidth 8) wideEq
    simpa using narrowed
  have bitsEq : bits = raw := by
    simpa only [valueEq, Arm64Registers.ValueRep] using representedValue
  simpa only [bitsEq, tagEq] using nativeWord

/-- Derive both native operands from the same actual scalar cells and
existing register representation, with no separate native-address premise. -/
theorem source_bits {initial memory : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial memory entry)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      memory.nextblock memory (.Vptr entry.block 0) s)
    (lhs raw : BitVec 64)
    (lhsWord : CC.Mem.load .Mint64 memory ((storage.tables false).cellBlock 4) 0 = some (.Vlong lhs))
    (lhsTag : CC.Mem.load .Mint8unsigned memory ((storage.tables true).cellBlock 4) 0 = some (.Vint 0))
    (rhsWord : CC.Mem.load .Mint64 memory ((storage.tables false).cellBlock 1) 0 = some (.Vlong raw))
    (rhsTag : CC.Mem.load .Mint8unsigned memory ((storage.tables true).cellBlock 1) 0 = some (.Vint 0)) :
    Reference.AArch64.gpr s 4 = lhs ∧ Reference.AArch64.gpr s 1 = raw := by
  have left := stored_operand storage addresses origins s represented 4 lhs (0#8) lhsWord lhsTag
  have right := stored_operand storage addresses origins s represented 1 raw (0#8) rhsWord rhsTag
  constructor
  · simpa [Reference.Provenance.AArch64.materialize] using left
  · simpa [Reference.Provenance.AArch64.materialize] using right


end KProgFormal.ClightRefinement.Arm64Compare.Native

namespace KProgFormal.ClightRefinement.Arm64Compare.Call
open Arm64Producer Arm64ProducerRegisterStorage Arm64ProducerEntryView

private theorem keep_sp : ∀ i : Fin 4,
    headerSourceName (Arm64ProducerEntryView.flagIndex (Stores.flagIndex i)) ≠ headerSourceName 5 := by decide +kernel
private theorem keep_vector : ∀ i : Fin 4,
    headerSourceName (Arm64ProducerEntryView.flagIndex (Stores.flagIndex i)) ≠ Arm64Entry.___a64_vectors := by decide +kernel
private theorem keep_header : ∀ i : Fin 4,
    headerSourceName (Arm64ProducerEntryView.flagIndex (Stores.flagIndex i)) ≠ Arm64Entry._entry := by decide +kernel

/-- The actual call/free retains every GPR/tag observation at the actual new frontier. -/
theorem Result.gpr {initial before written after : CC.Mem} {entry : HeaderLocal initial}
    {storage : Storage initial before entry} {lhs rhs : BitVec 64} {k : CC.Cont}
    {finalStorage : Storage initial after entry} (result : Result storage lhs rhs k written after finalStorage)
    (i : Fin 31) :
    Arm64EntryMemory.gpr after.nextblock after (.Vptr entry.block 0) i.val =
      Arm64EntryMemory.gpr before.nextblock before (.Vptr entry.block 0) i.val := by
  rw [Arm64RegisterWrite.storage_gpr finalStorage i,Arm64RegisterWrite.storage_gpr storage i,
    result.gpr_load false i .Mint64 0,result.gpr_load true i .Mint8unsigned 0]

/-- SP is read through the same actual header pointer and typed scalar local. -/
theorem Result.sp {initial before written after : CC.Mem} {entry : HeaderLocal initial}
    {storage : Storage initial before entry} {lhs rhs : BitVec 64} {k : CC.Cont}
    {finalStorage : Storage initial after entry} (result : Result storage lhs rhs k written after finalStorage) :
    Arm64EntryMemory.borrowed after.nextblock .Mint64 after (.Vptr entry.block 0) Arm64Program._sp =
      Arm64EntryMemory.borrowed before.nextblock .Mint64 before (.Vptr entry.block 0) Arm64Program._sp := by
  have old := header_borrowed_readback before entry.block 5 .Mint64 storage.sp.block 0 _ storage.spPointer storage.spRead
  have pointer := (result.locals _ _ _ entry.binding keep_header CC.Mptr 40).trans storage.spPointer
  have read := (result.locals _ _ _ storage.sp.binding keep_sp .Mint64 0).trans storage.spRead
  exact (header_borrowed_readback after entry.block 5 .Mint64 storage.sp.block 0 _ pointer read).trans old.symm

/-- All32 actual low/high vector reads survive the same flag-writing call. -/
theorem Result.vector {initial before written after : CC.Mem} {entry : HeaderLocal initial}
    {storage : Storage initial before entry} {lhs rhs : BitVec 64} {k : CC.Cont}
    {finalStorage : Storage initial after entry} (result : Result storage lhs rhs k written after finalStorage)
    (i : Fin 32) :
    Arm64EntryMemory.vector after.nextblock after (.Vptr entry.block 0) i =
      Arm64EntryMemory.vector before.nextblock before (.Vptr entry.block 0) i := by
  rw [Arm64RegisterWrite.storage_vector finalStorage i,Arm64RegisterWrite.storage_vector storage i]
  have same : finalStorage.vectors.block = storage.vectors.block :=
    congrArg Prod.fst (Option.some.inj (finalStorage.vectors.binding.symm.trans storage.vectors.binding))
  rw [same,result.locals _ _ _ storage.vectors.binding keep_vector .Mint64
    (CC.Integers.Ptrofs.unsigned (vectorLoopSourceOffset false i)),
    result.locals _ _ _ storage.vectors.binding keep_vector .Mint64
    (CC.Integers.Ptrofs.unsigned (vectorLoopSourceOffset true i))]

private theorem Result.native_flags {initial before written after : CC.Mem} {entry : HeaderLocal initial}
    {storage : Storage initial before entry} {lhs rhs : BitVec 64} {k : CC.Cont}
    {finalStorage : Storage initial after entry} (result : Result storage lhs rhs k written after finalStorage)
    (s : Reference.AArch64.State)
    (left : Reference.AArch64.gpr s 4 = lhs) (right : Reference.AArch64.gpr s 1 = rhs) :
    Arm64Nop.FlagsRepresent after.nextblock after (.Vptr entry.block 0) (Native.after s) := by
  have observed (i : Fin 4) :
      Arm64EntryMemory.borrowed after.nextblock .Mint8unsigned after (.Vptr entry.block 0)
        (headerField (Arm64ProducerEntryView.flagIndex (Stores.flagIndex i))) =
      some (.Vint ((read_flag (FlagBytes.flag i) (Native.after s).machine).setWidth 32)) := by
    have bytes := result.bytes i
    rw [← left,← right,FlagBytes.native_value] at bytes
    exact header_borrowed_readback after entry.block
      (Arm64ProducerEntryView.flagIndex (Stores.flagIndex i)) .Mint8unsigned
      (finalStorage.flags (Stores.flagIndex i)).block 0 _ (finalStorage.flagPointers _) bytes
  have n := observed 1
  have z := observed 0
  have c := observed 2
  have v := observed 3
  change Arm64EntryMemory.borrowed after.nextblock .Mint8unsigned after (.Vptr entry.block 0)
    Arm64Program._n = some (.Vint ((read_flag .N (Native.after s).machine).setWidth 32)) at n
  change Arm64EntryMemory.borrowed after.nextblock .Mint8unsigned after (.Vptr entry.block 0)
    Arm64Program._z = some (.Vint ((read_flag .Z (Native.after s).machine).setWidth 32)) at z
  change Arm64EntryMemory.borrowed after.nextblock .Mint8unsigned after (.Vptr entry.block 0)
    Arm64Program._c = some (.Vint ((read_flag .C (Native.after s).machine).setWidth 32)) at c
  change Arm64EntryMemory.borrowed after.nextblock .Mint8unsigned after (.Vptr entry.block 0)
    Arm64Program._v = some (.Vint ((read_flag .V (Native.after s).machine).setWidth 32)) at v
  simp only [Arm64Nop.FlagsRepresent,Arm64EntryMemory.flags,n,z,c,v,bind,Option.bind_some,pure]

/-- Full GPR/provenance, SP, SIMD and NZCV correspondence after the actual
413-step call, flag stores, release and return. Native operands are derived
from the original scalar cells and pre-relation, not added as assumptions. -/
theorem Result.represents {initial before written after : CC.Mem} {entry : HeaderLocal initial}
    {storage : Storage initial before entry} {lhs rhs : BitVec 64} {k : CC.Cont}
    {finalStorage : Storage initial after entry} (result : Result storage lhs rhs k written after finalStorage)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s)
    (lhsWord : CC.Mem.load .Mint64 before ((storage.tables false).cellBlock 4) 0 = some (.Vlong lhs))
    (lhsTag : CC.Mem.load .Mint8unsigned before ((storage.tables true).cellBlock 4) 0 = some (.Vint 0))
    (rhsWord : CC.Mem.load .Mint64 before ((storage.tables false).cellBlock 1) 0 = some (.Vlong rhs))
    (rhsTag : CC.Mem.load .Mint8unsigned before ((storage.tables true).cellBlock 1) 0 = some (.Vint 0)) :
    Arm64Registers.Represents addresses origins (fun r => r.val)
      after.nextblock after (.Vptr entry.block 0) (Native.after s) := by
  obtain ⟨left,right⟩ := Native.source_bits storage addresses origins s represented lhs rhs lhsWord lhsTag rhsWord rhsTag
  refine ⟨?_,?_,?_,result.native_flags s left right⟩
  · intro i
    obtain ⟨value,raw,tag,read,bits,word⟩ := represented.gpr i
    exact ⟨value,raw,tag,(result.gpr i).trans read,bits,((Native.registers s).1 i).trans word⟩
  · obtain ⟨offset,read,bits⟩ := represented.sp
    exact ⟨offset,result.sp.trans read,(Native.registers s).2.1.trans bits⟩
  · intro i
    rw [result.vector,(Native.registers s).2.2.1 i]
    exact represented.vectors i

/-- Keep the original producer reader frontier across true callee allocation
and freeing, using actual typed ownership rather than a new reader assumption. -/
theorem Result.represents_at {initial before written after : CC.Mem} {entry : HeaderLocal initial}
    {storage : Storage initial before entry} {lhs rhs : BitVec 64} {k : CC.Cont}
    {finalStorage : Storage initial after entry} (result : Result storage lhs rhs k written after finalStorage)
    (frontier : CC.Block) (bound : (allocation initial).2.nextblock.toNat ≤ frontier.toNat)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      frontier before (.Vptr entry.block 0) s)
    (lhsWord : CC.Mem.load .Mint64 before ((storage.tables false).cellBlock 4) 0 = some (.Vlong lhs))
    (lhsTag : CC.Mem.load .Mint8unsigned before ((storage.tables true).cellBlock 4) 0 = some (.Vint 0))
    (rhsWord : CC.Mem.load .Mint64 before ((storage.tables false).cellBlock 1) 0 = some (.Vlong rhs))
    (rhsTag : CC.Mem.load .Mint8unsigned before ((storage.tables true).cellBlock 1) 0 = some (.Vint 0)) :
    Arm64Registers.Represents addresses origins (fun r => r.val)
      frontier after (.Vptr entry.block 0) (Native.after s) := by
  apply (Arm64RegisterStorageFrontier.represents_iff finalStorage frontier bound addresses origins (Native.after s)).mpr
  exact result.represents addresses origins s
    ((Arm64RegisterStorageFrontier.represents_iff storage frontier bound addresses origins s).mp represented)
    lhsWord lhsTag rhsWord rhsTag

/-- The original sixth source call resumes its caller after417 genuine
transitions and refines the same fetched/decoded mature CMP step. The returned
memory, complete register relation and actual callee release share one witness. -/
theorem execute_caller_corresponds {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry)
    (bound : (allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (frontier : CC.Block) (frontierBound : (allocation initial).2.nextblock.toNat ≤ frontier.toNat)
    (lhs rhs : BitVec 64)
    (lhsWord : CC.Mem.load .Mint64 before ((storage.tables false).cellBlock 4) 0 = some (.Vlong lhs))
    (lhsTag : CC.Mem.load .Mint8unsigned before ((storage.tables true).cellBlock 4) 0 = some (.Vint 0))
    (rhsWord : CC.Mem.load .Mint64 before ((storage.tables false).cellBlock 1) 0 = some (.Vlong rhs))
    (rhsTag : CC.Mem.load .Mint8unsigned before ((storage.tables true).cellBlock 1) 0 = some (.Vint 0))
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      frontier before (.Vptr entry.block 0) s)
    (instruction : Reference.AArch64.Instruction)
    (decoded : instruction.decoded = .DPR (.Add_sub_shifted_reg Native.fields))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding)
    (le : CC.TempEnv) (k : CC.Cont) :
    ∃ written after, ∃ finalStorage : Storage initial after entry,
      Result storage lhs rhs (Arm64ProgramEntryCompareCall.callCont initial le k) written after finalStorage ∧
      InternalRun Arm64ProgramEntryAllocation.world 417
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryMulCall.afterMul k
          (Arm64ProgramEntryAllocation.allocation initial).1 le before)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryCompareCall.afterCompare k
          (Arm64ProgramEntryAllocation.allocation initial).1 le after) ∧
      Reference.AArch64.step s = ⟨Native.after s,[],none⟩ ∧
      Arm64Registers.Represents addresses origins (fun r => r.val)
        frontier after (.Vptr entry.block 0) (Native.after s) := by
  obtain ⟨written,after,finalStorage,result,run⟩ := execute_caller_from_storage storage bound lhs rhs
    lhsWord lhsTag rhsWord rhsTag le k
  refine ⟨written,after,finalStorage,?_⟩
  refine ⟨result,?_⟩
  refine ⟨run,?_⟩
  constructor
  · exact Native.reference_step s instruction decoded noError fetched
  · exact result.represents_at frontier frontierBound addresses origins s represented lhsWord lhsTag rhsWord rhsTag

end KProgFormal.ClightRefinement.Arm64Compare.Call
