import KProgFormal.ClightRefinement.Arm64KernelMemcpyEntryCode

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64KernelMemcpyLanding

/-- Both captured kernel entry sites contain this exact BTI c word.
LNSym executes it in its FEAT_BTI-absent architectural projection. -/
def instruction : Reference.AArch64.Instruction :=
  ⟨0xd503245f#32,.BR (.Hints {CRm := 4,op2 := 2}),by decide +kernel⟩

theorem word : Arm64KernelMemcpyCode.word 0 = instruction.encoding := rfl

def after (s : Reference.AArch64.State) : Reference.AArch64.State :=
  Arm64Nop.atCursor (read_pc s.machine+4#64) s

theorem execute (s : Reference.AArch64.State) :
    BR.exec_hints {CRm := 4,op2 := 2} s.machine = (after s).machine :=
  BR.exec_hints_bti _ s.machine (by decide +kernel)

theorem pc (s : Reference.AArch64.State) :
    read_pc (after s).machine = read_pc s.machine+4#64 := by
  simp only [after,Arm64Nop.atCursor,read_pc,write_pc,r_of_w_same]

theorem field (s : Reference.AArch64.State) (name : StateField) (different : name ≠ .PC) :
    r name (after s).machine = r name s.machine := by
  simp only [after,Arm64Nop.atCursor,write_pc,r_of_w_different different]

theorem resources (s : Reference.AArch64.State) :
    (after s).machine.mem = s.machine.mem ∧
    (after s).machine.program = s.machine.program ∧
    (after s).machine.memoryProfile = s.machine.memoryProfile ∧
    (after s).machine.memoryAccesses = s.machine.memoryAccesses ∧
    (after s).machine.atomicAccesses = s.machine.atomicAccesses ∧
    (after s).machine.exclusive = s.machine.exclusive ∧
    (after s).machine.threadPointerInputs = s.machine.threadPointerInputs ∧
    (after s).extraFlags = s.extraFlags := by
  simp only [after,Arm64Nop.atCursor,write_pc,w,write_base_pc,and_self]

/-- A genuine checked fetch executes the mature BTI body once. The real
input memory, profile, histories, monitor, thread inputs and all registers
stay in the same physical state; the reference emits no new event or fault. -/
theorem reference_step (s : Reference.AArch64.State)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding)
    (noError : read_err s.machine = .None) :
    Reference.AArch64.step s = ⟨after s,[],none⟩ := by
  have decode : decode_raw_inst instruction.encoding = some (.BR (.Hints {CRm := 4,op2 := 2})) := instruction.valid
  have native : stepi_checked s.machine = (after s).machine := by
    simpa [stepi_checked,stepi,noError,fetched,decode,exec_inst] using execute s
  have history : read_memory_accesses (after s).machine = read_memory_accesses s.machine := by
    simp only [read_memory_accesses,(resources s).2.2.2.1]
  have error : read_err (after s).machine = .None := (field s .ERR (by decide)).trans noError
  simp only [Reference.AArch64.step,native,history,List.drop_length,error,noError]
  rfl

/-- Generic symbol BTI derives the exact existing prologue admission. -/
theorem generic (s : Reference.AArch64.State) (origin : BitVec 64)
    (code : Arm64KernelMemcpyCode.Code origin s.machine) (cursor : read_pc s.machine = origin)
    (noError : read_err s.machine = .None) :
    Reference.AArch64.step s = ⟨after s,[],none⟩ ∧
    read_pc (after s).machine = origin+4#64 ∧
    read_err (after s).machine = .None ∧
    Arm64KernelMemcpyCode.Code origin (after s).machine := by
  have fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding := by
    rw [cursor]
    have zero : BitVec.ofNat 64 (4*(0 : Fin 14).val) = 0#64 := rfl
    simpa only [zero,BitVec.add_zero,word] using code 0
  exact ⟨reference_step s fetched noError,(pc s).trans (congrArg (fun p => p+4#64) cursor),
    (field s .ERR (by decide)).trans noError,Arm64KernelMemcpyCode.transport code (resources s).2.1⟩

end KProgFormal.ClightRefinement.Arm64KernelMemcpyLanding
