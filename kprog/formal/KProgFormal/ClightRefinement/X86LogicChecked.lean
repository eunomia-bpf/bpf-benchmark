import KProgFormal.ClightRefinement.X86LogicNative

namespace KProgFormal.ClightRefinement.X86LogicChecked

/-- Read the existing private checked-plan definitions through their pinned
module names; each generated proof term is checked against those definitions. -/
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
theorem register (state : X86.CheckedState) (dst src : Fin 16) (highDst highSrc : Bool)
    (kind : X86.BinKind) (length : Nat) (running : state.stopped = false) :
    X86.stepChecked ⟨.bin kind .b (.reg (X86.GPR.ofIndex dst) highDst)
      (.reg (X86.GPR.ofIndex src) highSrc), length⟩ state =
      {state with cpu := X86.step ⟨.bin kind .b (.reg (X86.GPR.ofIndex dst) highDst)
        (.reg (X86.GPR.ofIndex src) highSrc), length⟩ state.cpu state.addressWidth} := by
  unfold X86.stepChecked
  rw [running]
  cases kind
  all_goals run_tac reduceRegister
  all_goals rfl

/-- The original checked access planner requests no reads for binary byte
register forms, including both high-byte selectors and aliasing registers. -/
theorem reads (cpu : X86.Cpu) (dst src : Fin 16) (highDst highSrc : Bool)
    (kind : X86.BinKind) (length : Nat) :
    X86.plannedReadAddresses ⟨.bin kind .b (.reg (X86.GPR.ofIndex dst) highDst)
      (.reg (X86.GPR.ofIndex src) highSrc), length⟩ cpu = .ok [] := by
  unfold X86.plannedReadAddresses
  cases kind
  all_goals run_tac reduceRegister
  all_goals intro running; rfl

/-- Source GPR/flag representation after the actual writeback also represents
the checked ISA step, including its caller-supplied canonical-address mode. -/
theorem represented (state : X86.CheckedState) (dst src : Fin 16) (highDst highSrc : Bool)
    (kind : X86.BinKind) (value : BitVec 64) (length : Nat) (running : state.stopped = false)
    (selected :
      (kind = .xor ∧ value = state.cpu.getReg .b (X86.GPR.ofIndex dst) highDst ^^^
        state.cpu.getReg .b (X86.GPR.ofIndex src) highSrc) ∨
      (kind = .or ∧ value = state.cpu.getReg .b (X86.GPR.ofIndex dst) highDst |||
        state.cpu.getReg .b (X86.GPR.ofIndex src) highSrc) ∨
      (kind = .and ∧ value = state.cpu.getReg .b (X86.GPR.ofIndex dst) highDst &&&
        state.cpu.getReg .b (X86.GPR.ofIndex src) highSrc))
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.X86.Origins)
    (memory : CC.Mem) (block : CC.Block) (base : CC.Integers.Ptrofs)
    (registers : X86RegisterView.RegistersRepresent addresses origins memory block base
      (state.cpu.setReg .b (X86.GPR.ofIndex dst) value highDst))
    (places : X86LogicFlagOrder.Locations)
    (flags : X86LogicFlagMemory.FlagsRepresent memory places
      (X86.Flags.logic .b (X86.Value.trunc .b value) (state.cpu.oracle.bits state.cpu.oracle.cursor) state.cpu.flags))
 :
    let next := X86.stepChecked ⟨.bin kind .b (.reg (X86.GPR.ofIndex dst) highDst)
      (.reg (X86.GPR.ofIndex src) highSrc), length⟩ state
    X86RegisterView.RegistersRepresent addresses origins memory block base next.cpu ∧
      X86LogicFlagMemory.FlagsRepresent memory places next.cpu.flags := by
  have live : X86.Live state.cpu := by
    cases observed : state.cpu.ms with
    | none => exact observed
    | some error => simp [X86.CheckedState.stopped, X86.Cpu.stopped, observed] at running
  dsimp only
  rw [register state dst src highDst highSrc kind length running]
  exact X86LogicNative.represented state.cpu dst src highDst highSrc kind value length live selected
    addresses origins memory block base registers places flags state.addressWidth

end KProgFormal.ClightRefinement.X86LogicChecked
