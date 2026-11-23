import KProgFormal.ClightRefinement.X86LogicChecked

namespace KProgFormal.ClightRefinement.X86LogicReference

/-- Alias of the canonical reference's existing CPU input projection. -/
def input : Reference.X86.State → X86.Cpu := by
  run_tac
    Lean.Elab.Tactic.closeMainGoal `canonical_x86_cpu_input
      (Lean.mkConst (Lean.mkPrivateNameCore `KProgFormal.Reference.X86
        `KProgFormal.Reference.X86.externalCpu))

/-- Alias of the canonical reference's existing RFLAGS transport. -/
def flagsWord : BitVec 64 → X86.Flags → BitVec 64 := by
  run_tac
    Lean.Elab.Tactic.closeMainGoal `canonical_x86_rflags_output
      (Lean.mkConst (Lean.mkPrivateNameCore `KProgFormal.Reference.X86
        `KProgFormal.Reference.X86.externalRflags))

/-- The original input projection carries every architectural GPR. -/
theorem input_register (state : Reference.X86.State) (reg : X86.GPR) :
    (input state).regs.get reg = state.gpr reg.index := by
  cases reg <;> rfl

/-- The canonical reference wrapper uses the same checked logical register
step. Its full state preserves native memory, XMM0, FS/GS and address mode,
updates the selected register and flags, consumes one oracle bit and advances PC. -/
theorem native_step (state : Reference.X86.State) (dst src : Fin 16)
    (highDst highSrc : Bool) (kind : X86.BinKind) (value nextPc : BitVec 64)
    (running : state.modelError = none)
    (selected :
      (kind = .xor ∧ value = (input state).getReg .b (X86.GPR.ofIndex dst) highDst ^^^
        (input state).getReg .b (X86.GPR.ofIndex src) highSrc) ∨
      (kind = .or ∧ value = (input state).getReg .b (X86.GPR.ofIndex dst) highDst |||
        (input state).getReg .b (X86.GPR.ofIndex src) highSrc) ∨
      (kind = .and ∧ value = (input state).getReg .b (X86.GPR.ofIndex dst) highDst &&&
        (input state).getReg .b (X86.GPR.ofIndex src) highSrc)) :
    Reference.X86.nativeStep (.bin kind .b (.reg (X86.GPR.ofIndex dst) highDst)
      (.reg (X86.GPR.ofIndex src) highSrc)) nextPc state =
      ⟨{state with
        gpr := fun reg => ((input state).setReg .b (X86.GPR.ofIndex dst) value highDst).regs.get
          (X86.GPR.ofIndex reg),
        rflags := flagsWord state.rflags (X86.Flags.logic .b (X86.Value.trunc .b value)
          (state.oracle.bits state.oracle.cursor) (input state).flags),
        pc := nextPc, oracle := {state.oracle with cursor := state.oracle.cursor + 1},
        modelError := none}, [], none⟩ := by
  let cpu := input state
  let length := (nextPc - state.pc).toNat
  let checked : X86.CheckedState :=
    {cpu := {cpu with mem := X86.Mem.empty}
     profile := some {readable := state.memory.readable, writable := state.memory.writable, initialized := state.memory.initialized}
     addressWidth := match state.addressWidth with | .w48 => .la48 | .w57 => .la57}
  have active : checked.stopped = false := by
    change state.modelError.isSome = false
    simp only [running, Option.isSome_none]
  have live : X86.Live {cpu with mem := X86.Mem.empty} := running
  have numeric := X86LogicNative.register_step {cpu with mem := X86.Mem.empty}
    dst src highDst highSrc kind value length live selected checked.addressWidth
  unfold Reference.X86.nativeStep
  dsimp only
  rw [X86LogicChecked.reads]
  simp only [List.foldl_nil]
  rw [X86LogicChecked.register]
  rotate_left 1
  · exact active
  dsimp only
  let project (output : X86.Cpu) : Reference.Transition Reference.X86.State :=
    ⟨{state with
      gpr := fun reg => output.regs.get (X86.GPR.ofIndex reg),
      rflags := flagsWord state.rflags output.flags, xmm0 := output.getXmm .x0,
      pc := output.rip, fsBase := output.fsBase, gsBase := output.gsBase,
      oracle := output.oracle, modelError := output.ms}, [], none⟩
  change project (X86.step ⟨.bin kind .b (.reg (X86.GPR.ofIndex dst) highDst)
    (.reg (X86.GPR.ofIndex src) highSrc), length⟩ {cpu with mem := X86.Mem.empty}
      checked.addressWidth) = _
  rw [numeric]
  have pc : state.pc + BitVec.ofNat 64 (nextPc - state.pc).toNat = nextPc := by
    have encoded : BitVec.ofNat 64 (nextPc - state.pc).toNat = nextPc - state.pc := by
      apply BitVec.eq_of_toNat_eq
      exact Nat.mod_eq_of_lt (nextPc - state.pc).isLt
    rw [encoded, BitVec.add_comm]
    exact BitVec.sub_add_cancel nextPc state.pc
  change (⟨{state with
    gpr := fun reg => ((input state).setReg .b (X86.GPR.ofIndex dst) value highDst).regs.get
      (X86.GPR.ofIndex reg),
    rflags := flagsWord state.rflags (X86.Flags.logic .b (X86.Value.trunc .b value)
      (state.oracle.bits state.oracle.cursor) (input state).flags),
    pc := state.pc + BitVec.ofNat 64 (nextPc - state.pc).toNat,
    oracle := {state.oracle with cursor := state.oracle.cursor + 1},
    modelError := state.modelError}, [], none⟩ : Reference.Transition Reference.X86.State) = _
  simp only [pc, running]

/-- The same full-state result holds for the canonical ISA's logical
byte-register instruction constructor, with its legal low/high register slices. -/
theorem step (state : Reference.X86.State) (dst src : Reference.X86.RegisterSlice)
    (kind : Reference.X86.LogicKind) (value nextPc : BitVec 64)
    (running : state.modelError = none)
    (selected :
      (kind = .xor ∧ value = (input state).getReg .b (X86.GPR.ofIndex dst.reg) (dst.shift .w8 == 8) ^^^
        (input state).getReg .b (X86.GPR.ofIndex src.reg) (src.shift .w8 == 8)) ∨
      (kind = .or ∧ value = (input state).getReg .b (X86.GPR.ofIndex dst.reg) (dst.shift .w8 == 8) |||
        (input state).getReg .b (X86.GPR.ofIndex src.reg) (src.shift .w8 == 8)) ∨
      (kind = .and ∧ value = (input state).getReg .b (X86.GPR.ofIndex dst.reg) (dst.shift .w8 == 8) &&&
        (input state).getReg .b (X86.GPR.ofIndex src.reg) (src.shift .w8 == 8))) :
    Reference.X86.step (.logic .w8 kind (.register dst) (.register src) nextPc) state =
      ⟨{state with
        gpr := fun reg => ((input state).setReg .b (X86.GPR.ofIndex dst.reg) value (dst.shift .w8 == 8)).regs.get
          (X86.GPR.ofIndex reg),
        rflags := flagsWord state.rflags (X86.Flags.logic .b (X86.Value.trunc .b value)
          (state.oracle.bits state.oracle.cursor) (input state).flags),
        pc := nextPc, oracle := {state.oracle with cursor := state.oracle.cursor + 1},
        modelError := none}, [], none⟩ := by
  rcases selected with ⟨rfl, payload⟩ | ⟨rfl, payload⟩ | ⟨rfl, payload⟩
  · exact native_step state dst.reg src.reg (dst.shift .w8 == 8) (src.shift .w8 == 8)
      .xor value nextPc running (.inl ⟨rfl, payload⟩)
  · exact native_step state dst.reg src.reg (dst.shift .w8 == 8) (src.shift .w8 == 8)
      .or value nextPc running (.inr (.inl ⟨rfl, payload⟩))
  · exact native_step state dst.reg src.reg (dst.shift .w8 == 8) (src.shift .w8 == 8)
      .and value nextPc running (.inr (.inr ⟨rfl, payload⟩))

end KProgFormal.ClightRefinement.X86LogicReference
