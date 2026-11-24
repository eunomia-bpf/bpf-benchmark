import KProgFormal.ClightRefinement.X86LogicReference

namespace KProgFormal.ClightRefinement.X86LogicRegisterReference
open X86LogicReference

/-- Alias of the SAME canonical binding's existing width projection. -/
def size : Reference.X86.ScalarWidth → X86.Size := by
  run_tac
    Lean.Elab.Tactic.closeMainGoal `canonical_x86_register_size
      (Lean.mkConst (Lean.mkPrivateNameCore `KProgFormal.Reference.X86
        `KProgFormal.Reference.X86.externalSize))

private theorem numeric (size : X86.Size) (cpu : X86.Cpu) (dst src : Fin 16) (highDst highSrc : Bool)
    (kind : X86.BinKind) (value : BitVec 64) (length : Nat) (live : X86.Live cpu)
    (selected :
      (kind = .xor ∧ value = cpu.getReg size (X86.GPR.ofIndex dst) highDst ^^^
        cpu.getReg size (X86.GPR.ofIndex src) highSrc) ∨
      (kind = .or ∧ value = cpu.getReg size (X86.GPR.ofIndex dst) highDst |||
        cpu.getReg size (X86.GPR.ofIndex src) highSrc) ∨
      (kind = .and ∧ value = cpu.getReg size (X86.GPR.ofIndex dst) highDst &&&
        cpu.getReg size (X86.GPR.ofIndex src) highSrc))
    (addressWidth : X86.LinearAddressWidth := .la48) :
    X86.step ⟨.bin kind size (.reg (X86.GPR.ofIndex dst) highDst)
      (.reg (X86.GPR.ofIndex src) highSrc), length⟩ cpu addressWidth =
      {cpu.setReg size (X86.GPR.ofIndex dst) (X86.Value.trunc size value) highDst with
        flags := X86.Flags.logic size (X86.Value.trunc size value)
          (cpu.oracle.bits cpu.oracle.cursor) cpu.flags,
        oracle := {cpu.oracle with cursor := cpu.oracle.cursor + 1},
        rip := cpu.rip + BitVec.ofNat 64 length} := by
  change X86.step ⟨.bin kind size (.reg (X86.GPR.ofIndex dst) highDst)
    (.reg (X86.GPR.ofIndex src) highSrc), length⟩ cpu = _
  rcases selected with ⟨rfl, rfl⟩ | ⟨rfl, rfl⟩ | ⟨rfl, rfl⟩
  · simpa only [X86.Cpu.readOperand, X86.Cpu.setReg, X86.Value.writeHigh8,
      X86.Value.writeView, X86.Value.trunc_trunc] using
      (X86.step_xor_reg_op (s := cpu) (len := length) size (X86.GPR.ofIndex dst) highDst
        (.reg (X86.GPR.ofIndex src) highSrc) live rfl)
  · simpa only [X86.Cpu.readOperand, X86.Cpu.setReg, X86.Value.writeHigh8,
      X86.Value.writeView, X86.Value.trunc_trunc] using
      (X86.step_or_reg_op (s := cpu) (len := length) size (X86.GPR.ofIndex dst) highDst
        (.reg (X86.GPR.ofIndex src) highSrc) live rfl)
  · simpa only [X86.Cpu.readOperand, X86.Cpu.setReg, X86.Value.writeHigh8,
      X86.Value.writeView, X86.Value.trunc_trunc] using
      (X86.step_and_reg_op (s := cpu) (len := length) size (X86.GPR.ofIndex dst) highDst
        (.reg (X86.GPR.ofIndex src) highSrc) live rfl)


private def reduceRegister : Lean.Elab.Tactic.TacticM Unit := do
  let imported (name : Lean.Name) :=
    Lean.mkIdent (Lean.mkPrivateNameCore `X86.CheckedMemory name)
  Lean.Elab.Tactic.evalTactic (← `(tactic|
    simp_all [$(imported `X86.accessPlan):term, $(imported `X86.spanFor):term,
      $(imported `X86.checkedResult):term, $(imported `X86.divisionFault):term, $(imported `X86.commit):term,
      X86.wellFormed2, X86.Operand.isMem, X86.Operand.isImm,
      X86.Op.lockIllegal, X86.Op.anyLocked, X86.Op.lockable, X86.Operand.locked,
      X86.StringContext.prepare,
      List.foldl_nil, List.nil_append, Option.toList, ite_self]))

/-- Checked register operands require no memory transfers. Every incoming
memory profile, event, fault and canonical-address mode is retained while
execution delegates to the same imported numerical step. -/
private theorem checked (size : X86.Size) (state : X86.CheckedState) (dst src : Fin 16) (highDst highSrc : Bool)
    (kind : X86.BinKind) (length : Nat) (running : state.stopped = false) :
    X86.stepChecked ⟨.bin kind size (.reg (X86.GPR.ofIndex dst) highDst)
      (.reg (X86.GPR.ofIndex src) highSrc), length⟩ state =
      {state with cpu := X86.step ⟨.bin kind size (.reg (X86.GPR.ofIndex dst) highDst)
        (.reg (X86.GPR.ofIndex src) highSrc), length⟩ state.cpu state.addressWidth} := by
  unfold X86.stepChecked
  rw [running]
  cases kind
  all_goals run_tac reduceRegister
  all_goals rfl

/-- The original checked access planner requests no reads for binary byte
register forms, including both high-byte selectors and aliasing registers. -/
private theorem reads (size : X86.Size) (cpu : X86.Cpu) (dst src : Fin 16) (highDst highSrc : Bool)
    (kind : X86.BinKind) (length : Nat) :
    X86.plannedReadAddresses ⟨.bin kind size (.reg (X86.GPR.ofIndex dst) highDst)
      (.reg (X86.GPR.ofIndex src) highSrc), length⟩ cpu = .ok [] := by
  unfold X86.plannedReadAddresses
  cases kind
  all_goals run_tac reduceRegister
  all_goals intro running; rfl


theorem native_step (size : X86.Size) (state : Reference.X86.State) (dst src : Fin 16)
    (highDst highSrc : Bool) (kind : X86.BinKind) (value nextPc : BitVec 64)
    (running : state.modelError = none)
    (selected :
      (kind = .xor ∧ value = (input state).getReg size (X86.GPR.ofIndex dst) highDst ^^^
        (input state).getReg size (X86.GPR.ofIndex src) highSrc) ∨
      (kind = .or ∧ value = (input state).getReg size (X86.GPR.ofIndex dst) highDst |||
        (input state).getReg size (X86.GPR.ofIndex src) highSrc) ∨
      (kind = .and ∧ value = (input state).getReg size (X86.GPR.ofIndex dst) highDst &&&
        (input state).getReg size (X86.GPR.ofIndex src) highSrc)) :
    Reference.X86.nativeStep (.bin kind size (.reg (X86.GPR.ofIndex dst) highDst)
      (.reg (X86.GPR.ofIndex src) highSrc)) nextPc state =
      ⟨{state with
        gpr := fun reg => ((input state).setReg size (X86.GPR.ofIndex dst) (X86.Value.trunc size value) highDst).regs.get
          (X86.GPR.ofIndex reg),
        rflags := flagsWord state.rflags (X86.Flags.logic size (X86.Value.trunc size value)
          (state.oracle.bits state.oracle.cursor) (input state).flags),
        pc := nextPc, oracle := {state.oracle with cursor := state.oracle.cursor + 1},
        modelError := none}, [], none⟩ := by
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
  have numeric := numeric size {cpu with mem := X86.Mem.empty}
    dst src highDst highSrc kind value length live selected planned.addressWidth
  unfold Reference.X86.nativeStep
  dsimp only
  rw [reads size]
  simp only [List.foldl_nil]
  rw [checked size]
  rotate_left 1
  · exact active
  dsimp only
  let project (output : X86.Cpu) : Reference.Transition Reference.X86.State :=
    ⟨{state with
      gpr := fun reg => output.regs.get (X86.GPR.ofIndex reg),
      rflags := flagsWord state.rflags output.flags, xmm0 := output.getXmm .x0,
      pc := output.rip, fsBase := output.fsBase, gsBase := output.gsBase,
      oracle := output.oracle, modelError := output.ms}, [], none⟩
  change project (X86.step ⟨.bin kind size (.reg (X86.GPR.ofIndex dst) highDst)
    (.reg (X86.GPR.ofIndex src) highSrc), length⟩ {cpu with mem := X86.Mem.empty}
      planned.addressWidth) = _
  rw [numeric]
  have pc : state.pc + BitVec.ofNat 64 (nextPc - state.pc).toNat = nextPc := by
    have encoded : BitVec.ofNat 64 (nextPc - state.pc).toNat = nextPc - state.pc := by
      apply BitVec.eq_of_toNat_eq
      exact Nat.mod_eq_of_lt (nextPc - state.pc).isLt
    rw [encoded, BitVec.add_comm]
    exact BitVec.sub_add_cancel nextPc state.pc
  change (⟨{state with
    gpr := fun reg => ((input state).setReg size (X86.GPR.ofIndex dst) (X86.Value.trunc size value) highDst).regs.get
      (X86.GPR.ofIndex reg),
    rflags := flagsWord state.rflags (X86.Flags.logic size (X86.Value.trunc size value)
      (state.oracle.bits state.oracle.cursor) (input state).flags),
    pc := state.pc + BitVec.ofNat 64 (nextPc - state.pc).toNat,
    oracle := {state.oracle with cursor := state.oracle.cursor + 1},
    modelError := state.modelError}, [], none⟩ : Reference.Transition Reference.X86.State) = _
  simp only [pc, running]


theorem step (width : Reference.X86.ScalarWidth) (state : Reference.X86.State) (dst src : Reference.X86.RegisterSlice)
    (kind : Reference.X86.LogicKind) (value nextPc : BitVec 64)
    (running : state.modelError = none)
    (selected :
      (kind = .xor ∧ value = (input state).getReg (size width) (X86.GPR.ofIndex dst.reg) (dst.shift width == 8) ^^^
        (input state).getReg (size width) (X86.GPR.ofIndex src.reg) (src.shift width == 8)) ∨
      (kind = .or ∧ value = (input state).getReg (size width) (X86.GPR.ofIndex dst.reg) (dst.shift width == 8) |||
        (input state).getReg (size width) (X86.GPR.ofIndex src.reg) (src.shift width == 8)) ∨
      (kind = .and ∧ value = (input state).getReg (size width) (X86.GPR.ofIndex dst.reg) (dst.shift width == 8) &&&
        (input state).getReg (size width) (X86.GPR.ofIndex src.reg) (src.shift width == 8))) :
    Reference.X86.step (.logic width kind (.register dst) (.register src) nextPc) state =
      ⟨{state with
        gpr := fun reg => ((input state).setReg (size width) (X86.GPR.ofIndex dst.reg) (X86.Value.trunc (size width) value) (dst.shift width == 8)).regs.get
          (X86.GPR.ofIndex reg),
        rflags := flagsWord state.rflags (X86.Flags.logic (size width) (X86.Value.trunc (size width) value)
          (state.oracle.bits state.oracle.cursor) (input state).flags),
        pc := nextPc, oracle := {state.oracle with cursor := state.oracle.cursor + 1},
        modelError := none}, [], none⟩ := by
  rcases selected with ⟨rfl, payload⟩ | ⟨rfl, payload⟩ | ⟨rfl, payload⟩
  · exact native_step (size width) state dst.reg src.reg (dst.shift width == 8) (src.shift width == 8)
      .xor value nextPc running (.inl ⟨rfl, payload⟩)
  · exact native_step (size width) state dst.reg src.reg (dst.shift width == 8) (src.shift width == 8)
      .or value nextPc running (.inr (.inl ⟨rfl, payload⟩))
  · exact native_step (size width) state dst.reg src.reg (dst.shift width == 8) (src.shift width == 8)
      .and value nextPc running (.inr (.inr ⟨rfl, payload⟩))

end KProgFormal.ClightRefinement.X86LogicRegisterReference
