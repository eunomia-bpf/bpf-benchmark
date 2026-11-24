import KProgFormal.ClightRefinement.X86LogicReference

namespace KProgFormal.ClightRefinement.X86SubImmediateChecked

private def reduceImmediate : Lean.Elab.Tactic.TacticM Unit := do
  let imported (name : Lean.Name) := Lean.mkIdent (Lean.mkPrivateNameCore `X86.CheckedMemory name)
  Lean.Elab.Tactic.evalTactic (← `(tactic|
    simp +decide [$(imported `X86.accessPlan):term,$(imported `X86.spanFor):term,
      $(imported `X86.checkedResult):term,$(imported `X86.divisionFault):term,$(imported `X86.commit):term,
      X86.wellFormed2,X86.Operand.isMem,X86.Operand.isImm,X86.Op.lockIllegal,X86.Op.anyLocked,
      X86.Op.lockable,X86.Operand.locked,X86.StringContext.prepare,List.foldl_nil,List.nil_append,Option.toList,ite_self]))

/-- The original checked native register/immediate SUB performs no memory
transfer, retaining every actual profile/event/fault while delegating all
numerical and flag semantics to the pinned external step. -/
theorem checked (state : X86.CheckedState) (reg : X86.GPR) (value : BitVec 64) (length : Nat)
    (running : state.stopped = false) :
    X86.stepChecked ⟨.bin .sub .q (.reg reg) (.imm value),length⟩ state =
      {state with cpu := X86.step ⟨.bin .sub .q (.reg reg) (.imm value),length⟩ state.cpu state.addressWidth} := by
  unfold X86.stepChecked
  rw [running]
  run_tac reduceImmediate
  intro stopped
  have same : state.stopped = true := stopped
  simpa only [running,Bool.false_eq_true] using same

theorem reads (cpu : X86.Cpu) (reg : X86.GPR) (value : BitVec 64) (length : Nat) :
    X86.plannedReadAddresses ⟨.bin .sub .q (.reg reg) (.imm value),length⟩ cpu = .ok [] := by
  unfold X86.plannedReadAddresses
  run_tac reduceImmediate
  intro running
  rfl

/-- Exact qword SUB result, all six arithmetic flags and untouched native
frame come from the original external numerical theorem, not a C-derived
arithmetic model. No memory permission premise is needed for register SUB. -/
theorem numeric (cpu : X86.Cpu) (reg : X86.GPR) (value : BitVec 64) (length : Nat)
    (live : X86.Live cpu) (mode : X86.LinearAddressWidth := .la48) :
    X86.step ⟨.bin .sub .q (.reg reg) (.imm value),length⟩ cpu mode =
      {cpu.setReg .q reg (cpu.getReg .q reg - value) with
        flags := X86.Flags.sub .q (cpu.getReg .q reg) value cpu.flags,
        rip := cpu.rip + BitVec.ofNat 64 length} := by
  change X86.step ⟨.bin .sub .q (.reg reg) (.imm value),length⟩ cpu = _
  simpa only [X86.Flags.subResult,X86.Value.trunc_q,X86.Cpu.setReg,X86.Value.writeView,
    Bool.false_eq_true,ite_false] using X86.step_sub_reg_imm (s := cpu) (len := length) .q reg value live

end KProgFormal.ClightRefinement.X86SubImmediateChecked
