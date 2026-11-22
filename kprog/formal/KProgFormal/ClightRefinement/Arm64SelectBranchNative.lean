import KProgFormal.ClightRefinement.Arm64SelectBranch
import KProgFormal.ClightRefinement.Arm64SelectNative

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Select

/-- The actual chosen raw/tag source sent to the linked writer materializes to
exactly the source selected by the fetched native CSEL. This is the call boundary;
source writer execution, frame free and program continuation remain separate. -/
theorem selected_writer_matches (addresses : Arm64Registers.PointerOrigins)
    (origins : Reference.Provenance.AArch64.Origins) (frontier b : CC.Block) (ofs : CC.Integers.Ptrofs)
    (m : CC.Mem) (native : Reference.AArch64.State) (instruction : Reference.AArch64.Instruction)
    (dst lhs rhs : Fin 31) (condition : BitVec 4)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val) frontier m (.Vptr b ofs) native)
    (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (pointerNameFree : e.get Arm64Program._kprog_arm64_program_pointer = none)
    (tagNameFree : e.get Arm64Program._kprog_arm64_program_tag = none)
    (writerNameFree : e.get Arm64Program._kprog_arm64_program_write_pointer = none)
    (decision : le.get Arm64Program.___a64_l_taken =
      some (.Vint (if ConditionHolds condition native.machine then 1 else 0)))
    (entry : le.get Arm64Program._entry = some (.Vptr b ofs))
    (index : le.get (Branch.sourceName (ConditionHolds condition native.machine)) =
      some (.Vlong (BitVec.ofNat 64 (if ConditionHolds condition native.machine then lhs else rhs).val)))
    (destination : le.get Arm64Program._dst = some (.Vlong (BitVec.ofNat 64 dst.val)))
    (decoded : instruction.decoded = .DPR (.Conditional_select (Native.fields dst lhs rhs condition)))
    (noError : read_err native.machine = .None)
    (fetched : fetch_inst (read_pc native.machine) native.machine = some instruction.encoding) :
    ∃ value raw tag,
      Arm64EntryMemory.gpr frontier m (.Vptr b ofs)
        (if ConditionHolds condition native.machine then lhs else rhs).val =
          some (value,.Vint (tag.setWidth 32)) ∧
      Arm64Registers.ValueRep addresses value raw ∧
      InternalRun Arm64ProgramEntryLinked.ge 66 (.State Arm64Nop.handler Branch.source k e le m)
        (.Callstate (.Internal Arm64PointerWrite.procedure)
          [.Vptr b ofs,.Vlong (BitVec.ofNat 64 dst.val),value,.Vint (tag.setWidth 32)]
          (.Kcall none Arm64Nop.handler e
            (Branch.temps (ConditionHolds condition native.machine) le value tag) k) m) ∧
      Reference.AArch64.step native =
        ⟨Arm64Nop.atCursor (read_pc native.machine + 4#64)
          (Arm64PointerWrite.nativeUpdate origins native dst raw tag), [], none⟩ := by
  obtain ⟨value,raw,tag,observed,bits,nativeWord,run⟩ := Branch.to_writer
    (ConditionHolds condition native.machine) addresses origins frontier b ofs m native
    (if ConditionHolds condition native.machine then lhs else rhs) represented e le k
    (BitVec.ofNat 64 dst.val) pointerNameFree tagNameFree writerNameFree decision entry index destination
  exact ⟨value,raw,tag,observed,bits,run,
    Native.pointer_step native instruction dst lhs rhs condition origins raw tag nativeWord decoded noError fetched⟩

end KProgFormal.ClightRefinement.Arm64Select
