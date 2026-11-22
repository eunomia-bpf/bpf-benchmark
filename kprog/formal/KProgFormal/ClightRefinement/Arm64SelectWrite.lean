import KProgFormal.ClightRefinement.Arm64PointerValueFrame
import KProgFormal.ClightRefinement.Arm64SelectBranchNative

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Select

/-- Execute the selected original source branch, its two reads, both actual
writer stores and return into the handler. The raw value may be a bound Vptr;
all register observations and canonical cache locals follow the same result. -/
theorem write {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry)
    (taken : Bool) (addresses : Arm64Registers.PointerOrigins)
    (origins : Reference.Provenance.AArch64.Origins) (native : Reference.AArch64.State)
    (src dst : Fin 31)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      m.nextblock m (.Vptr entry.block 0) native)
    (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (pointerNameFree : e.get Arm64Program._kprog_arm64_program_pointer = none)
    (tagNameFree : e.get Arm64Program._kprog_arm64_program_tag = none)
    (writerNameFree : e.get Arm64Program._kprog_arm64_program_write_pointer = none)
    (decision : le.get Arm64Program.___a64_l_taken = some (.Vint (if taken then 1 else 0)))
    (entryRead : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (index : le.get (Branch.sourceName taken) = some (.Vlong (BitVec.ofNat 64 src.val)))
    (destination : le.get Arm64Program._dst = some (.Vlong (BitVec.ofNat 64 dst.val))) :
    ∃ value raw tag after,
      Arm64EntryMemory.gpr m.nextblock m (.Vptr entry.block 0) src.val =
        some (value,.Vint (tag.setWidth 32)) ∧
      Arm64Registers.ValueRep addresses value raw ∧
      Reference.AArch64.gpr native src = Reference.Provenance.AArch64.materialize origins raw tag ∧
      Arm64PointerWrite.ValueResult storage dst value tag after ∧
      InternalRun Arm64ProgramEntryLinked.ge 120
        (.State Arm64Nop.handler Branch.source k e le m)
        (.State Arm64Nop.handler .Sskip k e (Branch.temps taken le value tag) after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) m.nextblock after (.Vptr entry.block 0)
        (Arm64PointerWrite.nativeUpdate origins native dst raw tag) ∧
      Arm64CacheLocalFrame.Kept initial m after dst := by
  obtain ⟨value,raw,tag,read,bits,nativeWord,enter⟩ := Branch.to_writer taken addresses origins
    m.nextblock entry.block 0 m native src represented e le k (BitVec.ofNat 64 dst.val)
    pointerNameFree tagNameFree writerNameFree decision entryRead index destination
  obtain ⟨after,result,writer,registers,kept⟩ := Arm64PointerWrite.Linked.write_value storage dst value tag
    addresses origins native raw bits represented
    (.Kcall none Arm64Nop.handler e (Branch.temps taken le value tag) k) rfl
  have leave : InternalRun Arm64ProgramEntryLinked.ge 1
      (.Returnstate .Vundef (.Kcall none Arm64Nop.handler e (Branch.temps taken le value tag) k) after)
      (.State Arm64Nop.handler .Sskip k e (Branch.temps taken le value tag) after) :=
    .step trivial (by apply CC.doStep_sound; rfl) (.refl _)
  exact ⟨value,raw,tag,after,read,bits,nativeWord,result,(enter.trans writer).trans leave,registers,kept⟩

/-- The actual source writer result agrees with the fetched native CSEL64,
using the chosen operand's own raw value and tag from the pre-relation.
Generic dispatch, source condition computation and frame free are separate. -/
theorem write_matches {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (native : Reference.AArch64.State) (instruction : Reference.AArch64.Instruction)
    (dst lhs rhs : Fin 31) (condition : BitVec 4)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      m.nextblock m (.Vptr entry.block 0) native)
    (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (pointerNameFree : e.get Arm64Program._kprog_arm64_program_pointer = none)
    (tagNameFree : e.get Arm64Program._kprog_arm64_program_tag = none)
    (writerNameFree : e.get Arm64Program._kprog_arm64_program_write_pointer = none)
    (decision : le.get Arm64Program.___a64_l_taken =
      some (.Vint (if ConditionHolds condition native.machine then 1 else 0)))
    (entryRead : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (index : le.get (Branch.sourceName (ConditionHolds condition native.machine)) =
      some (.Vlong (BitVec.ofNat 64 (if ConditionHolds condition native.machine then lhs else rhs).val)))
    (destination : le.get Arm64Program._dst = some (.Vlong (BitVec.ofNat 64 dst.val)))
    (decoded : instruction.decoded = .DPR (.Conditional_select (Native.fields dst lhs rhs condition)))
    (noError : read_err native.machine = .None)
    (fetched : fetch_inst (read_pc native.machine) native.machine = some instruction.encoding) :
    ∃ value raw tag after,
      Arm64EntryMemory.gpr m.nextblock m (.Vptr entry.block 0)
        (if ConditionHolds condition native.machine then lhs else rhs).val =
          some (value,.Vint (tag.setWidth 32)) ∧
      Arm64Registers.ValueRep addresses value raw ∧
      Arm64PointerWrite.ValueResult storage dst value tag after ∧
      InternalRun Arm64ProgramEntryLinked.ge 120
        (.State Arm64Nop.handler Branch.source k e le m)
        (.State Arm64Nop.handler .Sskip k e
          (Branch.temps (ConditionHolds condition native.machine) le value tag) after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) m.nextblock after (.Vptr entry.block 0)
        (Arm64PointerWrite.nativeUpdate origins native dst raw tag) ∧
      Arm64CacheLocalFrame.Kept initial m after dst ∧
      Reference.AArch64.step native =
        ⟨Arm64Nop.atCursor (read_pc native.machine + 4#64)
          (Arm64PointerWrite.nativeUpdate origins native dst raw tag), [], none⟩ := by
  obtain ⟨value,raw,tag,after,read,bits,nativeWord,result,run,registers,kept⟩ := write storage
    (ConditionHolds condition native.machine) addresses origins native
    (if ConditionHolds condition native.machine then lhs else rhs) dst represented e le k
    pointerNameFree tagNameFree writerNameFree decision entryRead index destination
  exact ⟨value,raw,tag,after,read,bits,result,run,registers,kept,
    Native.pointer_step native instruction dst lhs rhs condition origins raw tag nativeWord decoded noError fetched⟩

end KProgFormal.ClightRefinement.Arm64Select
