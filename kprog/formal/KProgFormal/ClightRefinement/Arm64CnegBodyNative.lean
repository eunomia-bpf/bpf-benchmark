import KProgFormal.ClightRefinement.Arm64CnegBody
import KProgFormal.ClightRefinement.Arm64CnegNative

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Cneg.Body

/-- The actual scalar/tag observation and existing pre-relation determine
its physical value, including the original M3 stack-origin materialization. -/
private theorem materialized_source (addresses : Arm64Registers.PointerOrigins)
    (origins : Reference.Provenance.AArch64.Origins) (s : Reference.AArch64.State)
    (frontier : CC.Block) (m : CC.Mem) (entry : CC.Val) (raw : BitVec 64) (tag : BitVec 8)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val) frontier m entry s)
    (observed : Arm64EntryMemory.gpr frontier m entry 5 = some (.Vlong raw, .Vint (tag.setWidth 32))) :
    Reference.AArch64.gpr s 5 = Reference.Provenance.AArch64.materialize origins raw tag := by
  obtain ⟨value, bits, kind, read, valueRep, physical⟩ := represented.gpr 5
  have same := Option.some.inj (read.symm.trans observed)
  have valueEq : value = .Vlong raw := congrArg Prod.fst same
  have kindEq : kind = tag := by
    have widened := CC.Val.Vint.inj (congrArg Prod.snd same)
    simpa using congrArg (fun bits : BitVec 32 => bits.setWidth 8) widened
  have bitsEq : bits = raw := by
    simpa only [valueEq, Arm64Registers.ValueRep] using valueRep
  simpa only [bitsEq, kindEq] using physical

/-- The original complete CNEG body refines the fetched LNSym CSNEG/LT alias.
The physical operand is derived from the same reached scalar word/tag;
all GPRs, SP, SIMD, NZCV and original local observations are retained by the
actual writer certificate and the imported native step. -/
theorem corresponds {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State) (instruction : Reference.AArch64.Instruction)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      m.nextblock m (.Vptr entry.block 0) s)
    (raw : BitVec 64) (tag : BitVec 8) (tags : tag = 0 ∨ tag = 4)
    (observed : Arm64EntryMemory.gpr m.nextblock m (.Vptr entry.block 0) 5 =
      some (.Vlong raw, .Vint (tag.setWidth 32)))
    (cache : tag = 4 → Arm64RegisterReads.WarmEntryCache false m.nextblock m
      (.Vptr entry.block 0) origins.stack)
    (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (widthFree : e.get Arm64Program._arm64_width_effective = none)
    (readerFree : e.get Arm64Program._kprog_arm64_program_read = none)
    (conditionFree : e.get Arm64Program._kprog_arm64_program_condition = none)
    (writerFree : e.get Arm64Program._kprog_arm64_program_write = none)
    (entryRead : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (source : le.get Arm64Program._src = some (.Vlong (5#64)))
    (destination : le.get Arm64Program._dst = some (.Vlong (6#64)))
    (op : le.get Arm64Program._op = some (.Vint (65#32)))
    (aux : le.get Arm64Program._aux = some (.Vint (10#32)))
    (flags : le.get Arm64Program._flags = some (Arm64Width.argument (8#8)))
    (decoded : instruction.decoded = .DPR (.Conditional_select Native.fields))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    ∃ count after le',
      Arm64RegisterWrite.Result storage 6
        (if ConditionHolds (10#4) s.machine then -Reference.AArch64.gpr s 5 else Reference.AArch64.gpr s 5)
        false after ∧
      InternalRun Arm64ProgramEntryLinked.ge count
        (.State Arm64Nop.handler Arm64Nop.handler.fn_body k e le m)
        (.State Arm64Nop.handler .Sskip k e le' after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) m.nextblock after
        (.Vptr entry.block 0) (Reference.AArch64.step s).state ∧
      Arm64CacheLocalFrame.Kept initial m after 6 ∧
      (∀ id ∈ inputs, le'.get id = le.get id) ∧
      Reference.AArch64.step s =
        ⟨Arm64Nop.atCursor (read_pc s.machine + 4#64)
          (Arm64RegisterWrite.nativeUpdate s 6
            (if ConditionHolds (10#4) s.machine then -Reference.AArch64.gpr s 5 else Reference.AArch64.gpr s 5)
            false), [], none⟩ := by
  have physical := materialized_source addresses origins s m.nextblock m (.Vptr entry.block 0)
    raw tag represented observed
  obtain ⟨count, after, le', written, run, kept⟩ := execute storage origins s represented.flags
    5 6 raw tag tags observed cache e le k widthFree readerFree conditionFree writerFree
    entryRead source destination op aux flags
  dsimp only at written
  rw [← physical] at written
  have registers := written.represents addresses origins s represented
  have step := Native.reference_step s instruction decoded noError fetched
  refine ⟨count, after, le', written, run, ?_, written.local_load, kept, step⟩
  rw [step]
  exact (Arm64Registers.cursor after (.Vptr entry.block 0)
    (Arm64RegisterWrite.nativeUpdate s 6
      (if ConditionHolds (10#4) s.machine then -Reference.AArch64.gpr s 5 else Reference.AArch64.gpr s 5) false)
    (read_pc s.machine + 4#64)).mpr registers

end KProgFormal.ClightRefinement.Arm64Cneg.Body
