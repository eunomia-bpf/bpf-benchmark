import KProgFormal.ClightRefinement.X86NopReference

namespace KProgFormal.ClightRefinement.X86PushChecked

private def reducePush : Lean.Elab.Tactic.TacticM Unit := do
  let imported (name : Lean.Name) := Lean.mkIdent (Lean.mkPrivateNameCore `X86.CheckedMemory name)
  Lean.Elab.Tactic.evalTactic (← `(tactic|
    simp +decide [$(imported `X86.accessPlan):term, $(imported `X86.spanFor):term,
      $(imported `X86.checkedResult):term, $(imported `X86.divisionFault):term,
      $(imported `X86.commit):term, $(imported `X86.validate):term,
      $(imported `X86.permitted):term, $(imported `X86.bytesAt):term,
      X86.Op.lockIllegal,X86.Op.anyLocked,X86.Op.lockable,X86.Operand.locked,
      X86.StringContext.prepare,X86.CheckedState.stopped,X86.Cpu.stopped,
      List.foldl_nil,List.nil_append,Option.toList,ite_self,List.all_map]))

/-- The existing checked planner needs no input-memory read for register
PUSH; it still validates the actual write span in checked execution. -/
theorem reads (cpu : X86.Cpu) (length : Nat) :
    X86.plannedReadAddresses ⟨.push .q (.reg .rbx),length⟩ cpu = .ok [] := by
  unfold X86.plannedReadAddresses
  run_tac reducePush
  intro running
  rfl

/-- Characterize the pinned checked PUSH success path using its ORIGINAL
numerical step and actual store event. Native canonicality and permissions
are explicit, and are not inferred from private simulator cache rights. -/
theorem success (state : X86.CheckedState) (profile : X86.MemoryProfile) (length : Nat)
    (running : state.stopped = false) (present : state.profile = some profile)
    (canonical : (List.range 8).all (fun lane => X86.canonical
      (state.cpu.regs.get .rsp - (8#64) + BitVec.ofNat 64 lane) state.addressWidth) = true)
    (writable : (List.range 8).all (fun lane => profile.writable
      (state.cpu.regs.get .rsp - (8#64) + BitVec.ofNat 64 lane)) = true) :
    let next := X86.step ⟨.push .q (.reg .rbx),length⟩ state.cpu state.addressWidth
    X86.stepChecked ⟨.push .q (.reg .rbx),length⟩ state =
      { state with
        cpu := next,
        profile := some { profile with
          initialized := fun address =>
          if (address - (state.cpu.regs.get .rsp - (8#64))).toNat < 8 then true else profile.initialized address},
        events := state.events ++ [.memory .write (state.cpu.regs.get .rsp - (8#64))
          ((List.range 8).map (fun lane => next.mem.read (state.cpu.regs.get .rsp - (8#64) + BitVec.ofNat 64 lane))) true]} := by
  have live : X86.Live state.cpu := by
    cases observed : state.cpu.ms with
    | none => exact observed
    | some error => simp [X86.CheckedState.stopped,X86.Cpu.stopped,observed] at running
  have numeric := X86.step_push_reg (s := state.cpu) (len := length) .q .rbx live
  have nextLive : (X86.step ⟨.push .q (.reg .rbx),length⟩ state.cpu state.addressWidth {sourceBase := (0#64)}).ms = none := by
    change (X86.step ⟨.push .q (.reg .rbx),length⟩ state.cpu).ms = none
    rw [numeric]
    exact live
  have active : state.fault.isSome = false := by
    simpa [X86.CheckedState.stopped,X86.Cpu.stopped,live] using running
  have canonicalBytes := canonical
  have writableBytes := writable
  simp only [List.all_eq_true,List.mem_range] at canonicalBytes writableBytes
  have noCanonicalFault : ¬ ∃ lane, lane < 8 ∧ X86.canonical
      (state.cpu.regs.get .rsp - (8#64) + BitVec.ofNat 64 lane) state.addressWidth = false := by
    rintro ⟨lane,bound,failed⟩
    have ok := canonicalBytes lane bound
    simp_all
  have noWriteFault : ¬ ∃ lane, lane < 8 ∧ profile.writable
      (state.cpu.regs.get .rsp - (8#64) + BitVec.ofNat 64 lane) = false := by
    rintro ⟨lane,bound,failed⟩
    have ok := writableBytes lane bound
    simp_all
  unfold X86.stepChecked
  rw [running]
  run_tac reducePush
  all_goals simp only [present,active,live,noCanonicalFault,noWriteFault,nextLive,Option.isSome_none,
    Bool.false_eq_true,false_or,or_false,ite_false]
  all_goals rfl

end KProgFormal.ClightRefinement.X86PushChecked
