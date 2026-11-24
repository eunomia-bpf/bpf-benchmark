import KProgFormal.ClightRefinement.X86LogicReference

namespace KProgFormal.ClightRefinement.X86NopReference
open X86LogicReference

private def reduceNop : Lean.Elab.Tactic.TacticM Unit := do
  let imported (name : Lean.Name) := Lean.mkIdent (Lean.mkPrivateNameCore `X86.CheckedMemory name)
  Lean.Elab.Tactic.evalTactic (← `(tactic|
    simp_all [$(imported `X86.accessPlan):term, $(imported `X86.spanFor):term,
      $(imported `X86.checkedResult):term, $(imported `X86.divisionFault):term, $(imported `X86.commit):term,
      X86.Op.lockIllegal, X86.Op.anyLocked, X86.Op.lockable, X86.Operand.locked,
      X86.StringContext.prepare, List.foldl_nil, List.nil_append, Option.toList, ite_self]))

private theorem checked (state : X86.CheckedState) (length : Nat) (running : state.stopped = false) :
    X86.stepChecked ⟨.nop none, length⟩ state =
      {state with cpu := X86.step ⟨.nop none, length⟩ state.cpu state.addressWidth} := by
  unfold X86.stepChecked
  rw [running]
  run_tac reduceNop

private theorem reads (cpu : X86.Cpu) (length : Nat) :
    X86.plannedReadAddresses ⟨.nop none, length⟩ cpu = .ok [] := by
  unfold X86.plannedReadAddresses
  run_tac reduceNop
  intro running
  rfl

private theorem restore_bit (word : BitVec 64) (bit : Fin 64) :
    (if word.getLsbD bit.val then word ||| ((1#64) <<< bit.val)
      else word &&& ~~~((1#64) <<< bit.val)) = word := by
  apply BitVec.eq_of_getLsbD_eq
  intro j hj
  by_cases same : j = bit.val
  · subst j
    cases selected : word.getLsbD bit.val <;>
      simp [selected, BitVec.getLsbD_or, BitVec.getLsbD_and, BitVec.getLsbD_not,
        BitVec.getLsbD_shiftLeft, bit.isLt]
  · cases selected : word.getLsbD bit.val <;>
      simp [BitVec.getLsbD_or, BitVec.getLsbD_and, BitVec.getLsbD_not,
        BitVec.getLsbD_shiftLeft, hj, bit.isLt] <;> omega

private def unpackFlags : Lean.Elab.Tactic.TacticM Unit := do
  let imported (name : Lean.Name) := Lean.mkIdent (Lean.mkPrivateNameCore `KProgFormal.Reference.X86 name)
  Lean.Elab.Tactic.evalTactic (← `(tactic|
    simp only [flagsWord, input,
      $(imported `KProgFormal.Reference.X86.externalCpu):term,
      $(imported `KProgFormal.Reference.X86.externalFlags):term,
      $(imported `KProgFormal.Reference.X86.externalRflags):term,
      List.foldl_cons, List.foldl_nil]))

/-- Round-trip the SAME canonical RFLAGS projection at every original bit.
This proof uses kernel bit lemmas, without a native decision axiom. -/
theorem flags_roundtrip (state : Reference.X86.State) :
    flagsWord state.rflags (input state).flags = state.rflags := by
  have bit0 := restore_bit state.rflags ⟨0, by decide⟩
  change (if state.rflags.getLsbD 0 then state.rflags ||| (1 : BitVec 64)
    else state.rflags &&& ~~~(1 : BitVec 64)) = state.rflags at bit0
  have bit2 := restore_bit state.rflags ⟨2, by decide⟩
  change (if state.rflags.getLsbD 2 then state.rflags ||| (4 : BitVec 64)
    else state.rflags &&& ~~~(4 : BitVec 64)) = state.rflags at bit2
  have bit4 := restore_bit state.rflags ⟨4, by decide⟩
  change (if state.rflags.getLsbD 4 then state.rflags ||| (16 : BitVec 64)
    else state.rflags &&& ~~~(16 : BitVec 64)) = state.rflags at bit4
  have bit6 := restore_bit state.rflags ⟨6, by decide⟩
  change (if state.rflags.getLsbD 6 then state.rflags ||| (64 : BitVec 64)
    else state.rflags &&& ~~~(64 : BitVec 64)) = state.rflags at bit6
  have bit7 := restore_bit state.rflags ⟨7, by decide⟩
  change (if state.rflags.getLsbD 7 then state.rflags ||| (128 : BitVec 64)
    else state.rflags &&& ~~~(128 : BitVec 64)) = state.rflags at bit7
  have bit11 := restore_bit state.rflags ⟨11, by decide⟩
  change (if state.rflags.getLsbD 11 then state.rflags ||| (2048 : BitVec 64)
    else state.rflags &&& ~~~(2048 : BitVec 64)) = state.rflags at bit11
  have bit10 := restore_bit state.rflags ⟨10, by decide⟩
  change (if state.rflags.getLsbD 10 then state.rflags ||| (1024 : BitVec 64)
    else state.rflags &&& ~~~(1024 : BitVec 64)) = state.rflags at bit10
  run_tac unpackFlags
  rw [bit0, bit2, bit4, bit6, bit7, bit11, bit10]

/-- The pinned canonical checked ISA executes NOP without reading memory,
changing flags, registers, oracle, vector or address state. Only PC advances. -/
theorem step (state : Reference.X86.State) (nextPc : BitVec 64)
    (running : state.modelError = none) :
    Reference.X86.step (.nop nextPc) state = ⟨{state with pc := nextPc}, [], none⟩ := by
  change Reference.X86.nativeStep (.nop none) nextPc state = _
  let cpu := input state
  let length := (nextPc - state.pc).toNat
  let planned : X86.CheckedState :=
    {cpu := {cpu with mem := X86.Mem.empty}
     profile := some {readable := state.memory.readable, writable := state.memory.writable, initialized := state.memory.initialized}
     addressWidth := match state.addressWidth with | .w48 => .la48 | .w57 => .la57}
  have active : planned.stopped = false := by
    change state.modelError.isSome = false
    simp only [running, Option.isSome_none]
  have live : X86.Live {cpu with mem := X86.Mem.empty} := running
  have numerical := X86.step_nop (s := {cpu with mem := X86.Mem.empty}) (len := length) none live rfl
  unfold Reference.X86.nativeStep
  dsimp only
  rw [reads]
  simp only [List.foldl_nil]
  rw [checked]
  rotate_left 1
  · exact active
  dsimp only
  let project (output : X86.Cpu) : Reference.Transition Reference.X86.State :=
    ⟨{state with
      gpr := fun reg => output.regs.get (X86.GPR.ofIndex reg),
      rflags := flagsWord state.rflags output.flags, xmm0 := output.getXmm .x0,
      pc := output.rip, fsBase := output.fsBase, gsBase := output.gsBase,
      oracle := output.oracle, modelError := output.ms}, [], none⟩
  change project (X86.step ⟨.nop none, length⟩ {cpu with mem := X86.Mem.empty} planned.addressWidth) = _
  change project (X86.step ⟨.nop none, length⟩ {cpu with mem := X86.Mem.empty}) = _
  rw [numerical]
  have pc : state.pc + BitVec.ofNat 64 (nextPc - state.pc).toNat = nextPc := by
    have encoded : BitVec.ofNat 64 (nextPc - state.pc).toNat = nextPc - state.pc := by
      apply BitVec.eq_of_toNat_eq
      exact Nat.mod_eq_of_lt (nextPc - state.pc).isLt
    rw [encoded, BitVec.add_comm]
    exact BitVec.sub_add_cancel nextPc state.pc
  have registers : (fun reg => cpu.regs.get (X86.GPR.ofIndex reg)) = state.gpr := by
    funext reg
    rw [input_register, X86.GPR.index_ofIndex]
  change (⟨{state with
      gpr := fun reg => cpu.regs.get (X86.GPR.ofIndex reg),
      rflags := flagsWord state.rflags cpu.flags,
      pc := state.pc + BitVec.ofNat 64 (nextPc - state.pc).toNat}, [], none⟩ : Reference.Transition Reference.X86.State) = _
  rw [registers, flags_roundtrip, pc]

end KProgFormal.ClightRefinement.X86NopReference
