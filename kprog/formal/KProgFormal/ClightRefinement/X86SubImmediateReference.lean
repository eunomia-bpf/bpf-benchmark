import KProgFormal.ClightRefinement.X86SubImmediateChecked

namespace KProgFormal.ClightRefinement.X86SubImmediateReference
open X86LogicReference (input flagsWord)

/-- Exact shared canonical qword register/immediate SUB, including every
arithmetic flag, full untouched memory/vector/oracle/address frame and PC.
This native-model theorem does not assume private cache permissions and is
not by itself a source-handler refinement theorem. -/
theorem step (state : Reference.X86.State) (reg : Fin 16) (value nextPc : BitVec 64)
    (running : state.modelError = none) :
    Reference.X86.step (.arithmetic .w64 .sub (.register (.low reg)) (.immediate value) nextPc) state =
      ⟨{state with
        gpr := fun r => ((input state).setReg .q (X86.GPR.ofIndex reg)
          (state.gpr reg - value)).regs.get (X86.GPR.ofIndex r),
        rflags := flagsWord state.rflags (X86.Flags.sub .q (state.gpr reg) value (input state).flags),
        pc := nextPc},[],none⟩ := by
  change Reference.X86.nativeStep (.bin .sub .q (.reg (X86.GPR.ofIndex reg)) (.imm value)) nextPc state = _
  let cpu := input state
  let length := (nextPc-state.pc).toNat
  let checked : X86.CheckedState :=
    {cpu := {cpu with mem := X86.Mem.empty},
     profile := some ⟨state.memory.readable,state.memory.writable,state.memory.initialized⟩,
     addressWidth := match state.addressWidth with | .w48 => .la48 | .w57 => .la57}
  have active : checked.stopped = false := by
    change state.modelError.isSome = false
    simp only [running,Option.isSome_none]
  have live : X86.Live {cpu with mem := X86.Mem.empty} := running
  have numerical := X86SubImmediateChecked.numeric {cpu with mem := X86.Mem.empty}
    (X86.GPR.ofIndex reg) value length live checked.addressWidth
  unfold Reference.X86.nativeStep
  dsimp only
  rw [X86SubImmediateChecked.reads]
  simp only [List.foldl_nil]
  rw [X86SubImmediateChecked.checked]
  rotate_left 1
  · exact active
  dsimp only
  let project (output : X86.Cpu) : Reference.Transition Reference.X86.State :=
    ⟨{state with
      gpr := fun r => output.regs.get (X86.GPR.ofIndex r),
      rflags := flagsWord state.rflags output.flags,xmm0 := output.getXmm .x0,
      pc := output.rip,fsBase := output.fsBase,gsBase := output.gsBase,
      oracle := output.oracle,modelError := output.ms},[],none⟩
  change project (X86.step ⟨.bin .sub .q (.reg (X86.GPR.ofIndex reg)) (.imm value),length⟩
    {cpu with mem := X86.Mem.empty} checked.addressWidth) = _
  rw [numerical]
  have operand : ({cpu with mem := X86.Mem.empty} : X86.Cpu).getReg .q (X86.GPR.ofIndex reg) = state.gpr reg := by
    change (input state).getReg .q (X86.GPR.ofIndex reg) = state.gpr reg
    simp only [X86.Cpu.getReg,Bool.false_eq_true,ite_false,X86.Value.trunc_q,
      X86LogicReference.input_register,X86.GPR.index_ofIndex]
  have pc : state.pc + BitVec.ofNat 64 (nextPc-state.pc).toNat = nextPc := by
    have encoded : BitVec.ofNat 64 (nextPc-state.pc).toNat = nextPc-state.pc := by
      apply BitVec.eq_of_toNat_eq
      exact Nat.mod_eq_of_lt (nextPc-state.pc).isLt
    rw [encoded,BitVec.add_comm]
    exact BitVec.sub_add_cancel nextPc state.pc
  rw [operand]
  change (⟨{state with
    gpr := fun r => ((input state).setReg .q (X86.GPR.ofIndex reg) (state.gpr reg-value)).regs.get (X86.GPR.ofIndex r),
    rflags := flagsWord state.rflags (X86.Flags.sub .q (state.gpr reg) value (input state).flags),
    pc := state.pc + BitVec.ofNat 64 (nextPc-state.pc).toNat},[],none⟩ : Reference.Transition Reference.X86.State) = _
  rw [pc]

end KProgFormal.ClightRefinement.X86SubImmediateReference
