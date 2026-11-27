import KProgFormal.ClightRefinement.Arm64KernelMemcpyCode
import KProgFormal.ClightRefinement.Arm64Nop

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64KernelMemcpyEntryCode

/-- Actual exported alias differs from generic by0x230 in both sole-kernel
object and linked vmlinux. The captured entry's second word is the plain B. -/
def fields : Uncond_branch_imm_cls := {op := 0,imm26 := 0x3ffff73}
def instruction : Reference.AArch64.Instruction :=
  ⟨0x17ffff73#32,.BR (.Uncond_branch_imm fields),by decide +kernel⟩

structure Code (origin : BitVec 64) (machine : ArmState) : Prop where
  generic : Arm64KernelMemcpyCode.Code origin machine
  landing : fetch_inst (origin+0x230#64) machine = some (0xd503245f#32)
  branch : fetch_inst (origin+0x230#64+4#64) machine = some instruction.encoding

/-- The genuine signed immediate reaches the distinct generic symbol. -/
theorem target (origin : BitVec 64) :
    BR.Uncond_branch_imm_inst.branch_taken_pc fields (origin+0x230#64+4#64) = origin := by
  change origin+0x230#64+4#64+(-564#64) = origin
  bv_omega

def after (s : Reference.AArch64.State) : Reference.AArch64.State :=
  Arm64Nop.atCursor (BR.Uncond_branch_imm_inst.branch_taken_pc fields (read_pc s.machine)) s

theorem execute (s : Reference.AArch64.State) :
    BR.exec_uncond_branch_imm fields s.machine = (after s).machine := by
  simp [BR.exec_uncond_branch_imm,fields,after,Arm64Nop.atCursor]

theorem cursor (s : Reference.AArch64.State) :
    read_pc (after s).machine = BR.Uncond_branch_imm_inst.branch_taken_pc fields (read_pc s.machine) := by
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

/-- At the actual alias branch, mature B executes once and preserves LR and
the complete physical frame. The same program fetches the generic BTI next.
Both landing-pad executions and the selected live alternative keep their own
feature-bound admission. -/
theorem complete (s : Reference.AArch64.State) (origin : BitVec 64)
    (code : Code origin s.machine) (pc : read_pc s.machine = origin+0x230#64+4#64)
    (noError : read_err s.machine = .None) :
    Reference.AArch64.step s = ⟨after s,[],none⟩ ∧
    read_pc (after s).machine = origin ∧
    Reference.AArch64.gpr (after s) 30 = Reference.AArch64.gpr s 30 ∧
    (∀ name : StateField, name ≠ .PC → r name (after s).machine = r name s.machine) ∧
    Arm64KernelMemcpyCode.Code origin (after s).machine ∧
    fetch_inst (read_pc (after s).machine) (after s).machine = some (Arm64KernelMemcpyCode.word 0) := by
  have fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding := by
    rw [pc]
    exact code.branch
  have decode : decode_raw_inst instruction.encoding = some (.BR (.Uncond_branch_imm fields)) := instruction.valid
  have native : stepi_checked s.machine = (after s).machine := by
    simpa [stepi_checked,stepi,noError,fetched,decode,exec_inst] using execute s
  have history : read_memory_accesses (after s).machine = read_memory_accesses s.machine := by
    simp only [read_memory_accesses,(resources s).2.2.2.1]
  have error : read_err (after s).machine = .None := (field s .ERR (by decide)).trans noError
  have currentPC : read_pc (after s).machine = origin :=
    (cursor s).trans ((congrArg (BR.Uncond_branch_imm_inst.branch_taken_pc fields) pc).trans (target origin))
  have generic := Arm64KernelMemcpyCode.transport code.generic (resources s).2.1
  refine ⟨?_,currentPC,field s (.GPR (30#5)) (by decide),field s,generic,?_⟩
  · simp only [Reference.AArch64.step,native,history,List.drop_length,error,noError]
    rfl
  · rw [currentPC]
    have zero : (BitVec.ofNat 64 (4*(0 : Fin 14).val)) = 0#64 := rfl
    simpa only [zero,BitVec.add_zero] using generic 0

end KProgFormal.ClightRefinement.Arm64KernelMemcpyEntryCode
