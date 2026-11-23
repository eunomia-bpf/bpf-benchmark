import KProgFormal.ClightRefinement.Arm64OrnBody
import KProgFormal.ClightRefinement.Arm64OrnNative

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Orn.Body

/-- The actual scalar/tag observation and existing pre-relation determine
its physical value, including the original M3 stack-origin materialization. -/
private theorem materialized_source (addresses : Arm64Registers.PointerOrigins)
    (origins : Reference.Provenance.AArch64.Origins) (s : Reference.AArch64.State)
    (frontier : CC.Block) (m : CC.Mem) (entry : CC.Val) (raw : BitVec 64) (tag : BitVec 8)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val) frontier m entry s)
    (observed : Arm64EntryMemory.gpr frontier m entry 6 = some (.Vlong raw, .Vint (tag.setWidth 32))) :
    Reference.AArch64.gpr s 6 = Reference.Provenance.AArch64.materialize origins raw tag := by
  obtain ⟨value, bits, kind, read, valueRep, physical⟩ := represented.gpr 6
  have same := Option.some.inj (read.symm.trans observed)
  have valueEq : value = .Vlong raw := congrArg Prod.fst same
  have kindEq : kind = tag := by
    have widened := CC.Val.Vint.inj (congrArg Prod.snd same)
    simpa using congrArg (fun bits : BitVec 32 => bits.setWidth 8) widened
  have bitsEq : bits = raw := by
    simpa only [valueEq, Arm64Registers.ValueRep] using valueRep
  simpa only [bitsEq, kindEq] using physical

/-- Low32 masking in the source operand and numeric result gives the same
zero-extended W32 word as the original native ORN operation. -/
theorem masked_written (lhs rhs : BitVec 64) :
    Arm64RegisterWrite.written true ((lhs ||| ~~~((rhs <<< 1) &&& (4294967295#64))) &&& (4294967295#64)) =
      Arm64RegisterWrite.written true (lhs ||| ~~~(rhs <<< 1)) := by
  have mask : (4294967295#64).setWidth 32 = BitVec.allOnes 32 := rfl
  have low : (((lhs ||| ~~~((rhs <<< 1) &&& (4294967295#64))) &&& (4294967295#64)).setWidth 32) =
      (lhs ||| ~~~(rhs <<< 1)).setWidth 32 := by
    simp only [BitVec.setWidth_and,BitVec.setWidth_or,
      BitVec.setWidth_not (by decide : 32 ≤ 64),mask,BitVec.and_allOnes]
  exact congrArg (fun word : BitVec 32 => word.setWidth 64) low

/-- The complete original ORN32 handler refines the fetched imported LNSym
logical-shifted step. Both native operands follow from the same pre-relation
and actual scalar/tag memory, including M3 left-operand materialization. -/
theorem corresponds {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State) (instruction : Reference.AArch64.Instruction)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      m.nextblock m (.Vptr entry.block 0) s)
    (raw : BitVec 64) (tag : BitVec 8) (tags : tag = 0 ∨ tag = 4) (rhsValue : BitVec 64)
    (observed : Arm64EntryMemory.gpr m.nextblock m (.Vptr entry.block 0) 6 =
      some (.Vlong raw,.Vint (tag.setWidth 32)))
    (cache : tag = 4 → Arm64RegisterReads.WarmEntryCache false m.nextblock m
      (.Vptr entry.block 0) origins.stack)
    (rhsWord : CC.Mem.load .Mint64 m ((storage.tables false).cellBlock 3) 0 = some (.Vlong rhsValue))
    (rhsTag : CC.Mem.load .Mint8unsigned m ((storage.tables true).cellBlock 3) 0 = some (.Vint 0))
    (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (widthFree : e.get Arm64Program._arm64_width_effective = none)
    (readerFree : e.get Arm64Program._kprog_arm64_program_read = none)
    (modifierFree : e.get Arm64Program._kprog_arm64_program_modified = none)
    (writerFree : e.get Arm64Program._kprog_arm64_program_write = none)
    (entryRead : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (source : le.get Arm64Program._src = some (.Vlong (6#64)))
    (source2 : le.get Arm64Program._src2 = some (.Vlong (3#64)))
    (destination : le.get Arm64Program._dst = some (.Vlong (7#64)))
    (op : le.get Arm64Program._op = some (.Vint (53#32)))
    (aux : le.get Arm64Program._aux = some (.Vint (65792#32)))
    (flags : le.get Arm64Program._flags = some (Arm64Width.argument (4#8)))
    (decoded : instruction.decoded = .DPR (.Logical_shifted_reg Native.fields))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    ∃ count after le',
      Arm64RegisterWrite.Result storage 7
        ((Reference.AArch64.gpr s 6 ||| ~~~((Reference.AArch64.gpr s 3 <<< 1) &&& (4294967295#64))) &&& (4294967295#64)) true after ∧
      InternalRun Arm64ProgramEntryLinked.ge count
        (.State Arm64Nop.handler Arm64Nop.handler.fn_body k e le m)
        (.State Arm64Nop.handler .Sskip k e le' after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) m.nextblock after
        (.Vptr entry.block 0) (Reference.AArch64.step s).state ∧
      Arm64CacheLocalFrame.Kept initial m after 7 ∧
      (∀ id ∈ inputs, le'.get id = le.get id) ∧
      Reference.AArch64.step s =
        ⟨Arm64Nop.atCursor (read_pc s.machine + 4#64)
          (Arm64RegisterWrite.nativeUpdate s 7
            (Reference.AArch64.gpr s 6 ||| ~~~(Reference.AArch64.gpr s 3 <<< 1)) true), [], none⟩ := by
  have physical := materialized_source addresses origins s m.nextblock m (.Vptr entry.block 0)
    raw tag represented observed
  have rhsObserved : Arm64EntryMemory.gpr m.nextblock m (.Vptr entry.block 0) (3 : Fin 31).val =
      some (.Vlong rhsValue,.Vint 0) := by
    rw [Arm64RegisterWrite.storage_gpr storage 3,rhsWord,rhsTag]
    rfl
  have rhsPhysical := Arm64MovKeep.scalar_native_bits addresses origins s m.nextblock m (.Vptr entry.block 0)
    3 rhsValue rhsObserved represented
  obtain ⟨count,after,le',written,run,kept⟩ := execute storage origins 6 3 7 raw tag rhsValue tags observed cache
    rhsWord rhsTag e le k widthFree readerFree modifierFree writerFree entryRead source source2 destination op aux flags
  rw [← physical,← rhsPhysical] at written
  have registers := written.represents addresses origins s represented
  have update : Arm64RegisterWrite.nativeUpdate s 7
      ((Reference.AArch64.gpr s 6 ||| ~~~((Reference.AArch64.gpr s 3 <<< 1) &&& (4294967295#64))) &&& (4294967295#64)) true =
      Arm64RegisterWrite.nativeUpdate s 7 (Reference.AArch64.gpr s 6 ||| ~~~(Reference.AArch64.gpr s 3 <<< 1)) true := by
    unfold Arm64RegisterWrite.nativeUpdate
    rw [masked_written]
  rw [update] at registers
  have step := Native.reference_step s instruction decoded noError fetched
  refine ⟨count,after,le',written,run,?_,written.local_load,kept,step⟩
  rw [step]
  exact (Arm64Registers.cursor after (.Vptr entry.block 0)
    (Arm64RegisterWrite.nativeUpdate s 7 (Reference.AArch64.gpr s 6 ||| ~~~(Reference.AArch64.gpr s 3 <<< 1)) true)
    (read_pc s.machine + 4#64)).mpr registers

end KProgFormal.ClightRefinement.Arm64Orn.Body
