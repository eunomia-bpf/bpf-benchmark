import KProgFormal.ClightRefinement.X86LogicNative

namespace KProgFormal.ClightRefinement.X86LogicChecked

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
  all_goals
    run_tac
      let imported (name : Lean.Name) :=
        Lean.mkIdent (Lean.mkPrivateNameCore `X86.CheckedMemory name)
      Lean.Elab.Tactic.evalTactic (← `(tactic|
        simp_all [$(imported `X86.accessPlan):term, $(imported `X86.spanFor):term,
          $(imported `X86.checkedResult):term, $(imported `X86.divisionFault):term, $(imported `X86.commit):term,
          X86.wellFormed2, X86.Operand.isMem, X86.Operand.isImm,
          X86.Op.lockIllegal, X86.Op.anyLocked, X86.Op.lockable, X86.Operand.locked,
          X86.StringContext.prepare,
          List.foldl_nil, List.nil_append, Option.toList, ite_self]))
  all_goals rfl

end KProgFormal.ClightRefinement.X86LogicChecked
