import KProgFormal.ClightRefinement.Arm64KernelMemcpySource
import KProgFormal.ClightRefinement.Arm64ProgramEntryReturnNative

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64KernelMemcpyReturn
abbrev Return := Arm64ProgramEntryReturnNative.after

/-- The captured kernel RET is the existing mature RET X30 certificate. -/
theorem word : (Arm64KernelMemcpyCode.instruction 13).encoding =
    Arm64ProgramEntryReturnNative.instruction.encoding := rfl

/-- The SAME completed stores derive the real RET step and original LR
target, retaining all registers and the complete output memory/profile. -/
theorem execute (s : Reference.AArch64.State) (profile : MemoryProfile) (origin : BitVec 64)
    (stores : Arm64KernelMemcpyTwoStores.Result s profile origin) :
    Reference.AArch64.step stores.final = ⟨Return stores.final,[],none⟩ ∧
    read_pc (Return stores.final).machine = Reference.AArch64.gpr s 30 ∧
    read_err (Return stores.final).machine = .None ∧
    (∀ field : StateField, field ≠ .PC → r field (Return stores.final).machine = r field s.machine) ∧
    (Return stores.final).machine.mem = stores.final.machine.mem ∧
    (Return stores.final).machine.memoryProfile = stores.final.machine.memoryProfile ∧
    (Return stores.final).machine.memoryAccesses = stores.final.machine.memoryAccesses ∧
    (Return stores.final).machine.program = stores.final.machine.program ∧
    (Return stores.final).machine.exclusive = stores.final.machine.exclusive ∧
    (Return stores.final).machine.atomicAccesses = stores.final.machine.atomicAccesses ∧
    (Return stores.final).machine.threadPointerInputs = stores.final.machine.threadPointerInputs ∧
    (Return stores.final).extraFlags = stores.final.extraFlags := by
  have fetched : fetch_inst (read_pc stores.final.machine) stores.final.machine =
      some Arm64ProgramEntryReturnNative.instruction.encoding := by
    simpa only [word] using stores.returnFetch
  obtain ⟨memory,program,profileSame,history,atomic,exclusive,thread,extra⟩ :=
    Arm64ProgramEntryReturnNative.resources stores.final
  exact ⟨Arm64ProgramEntryReturnNative.reference_step stores.final stores.noError fetched,
    (Arm64ProgramEntryReturnNative.pc stores.final).trans (stores.fields (.GPR (30#5)) (by decide)),
    (Arm64ProgramEntryReturnNative.error stores.final).trans stores.noError,
    fun field notPC => (Arm64ProgramEntryReturnNative.field stores.final field notPC).trans (stores.fields field notPC),
    memory,profileSame,history,program,exclusive,atomic,thread,extra⟩

/-- Returning preserves every actual copied byte and outside-byte frame. -/
theorem bytes (s : Reference.AArch64.State) (profile : MemoryProfile) (origin : BitVec 64)
    (stores : Arm64KernelMemcpyTwoStores.Result s profile origin) (width : Nat) (address : BitVec 64) :
    read_mem_bytes width address (Return stores.final).machine = read_mem_bytes width address stores.final.machine :=
  Arm64KernelMemcpyReadMemory.bytes_same _ _ (Arm64ProgramEntryReturnNative.resources stores.final).1 width address

/-- The real final initialized profile is retained at the actual LR target. -/
theorem profile (s : Reference.AArch64.State) (input : MemoryProfile) (origin : BitVec 64)
    (stores : Arm64KernelMemcpyTwoStores.Result s input origin) :
    read_memory_profile (Return stores.final).machine =
      some (Arm64KernelMemcpyWriteMemory.updated input 16 (Reference.AArch64.gpr s 0)) :=
  (Arm64ProgramEntryReturnNative.resources stores.final).2.2.1.trans (Arm64KernelMemcpyOutput.profile s input origin stores)

end KProgFormal.ClightRefinement.Arm64KernelMemcpyReturn
