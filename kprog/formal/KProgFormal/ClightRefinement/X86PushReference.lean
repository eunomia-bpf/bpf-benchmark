import KProgFormal.ClightRefinement.X86NativeByteFold
import KProgFormal.ClightRefinement.X86PushChecked

namespace KProgFormal.ClightRefinement.X86PushReference
open X86LogicReference (input flagsWord)

private def effects : Reference.Memory → List X86.MemoryAccessEvent → Reference.Transition Reference.Memory := by
  run_tac
    Lean.Elab.Tactic.closeMainGoal `original_reference_effect_projection
      (Lean.mkConst (Lean.mkPrivateNameCore `KProgFormal.Reference.X86 `KProgFormal.Reference.X86.externalEffects))

private def projectEffects : Lean.Elab.Tactic.TacticM Unit := do
  let imported (name : Lean.Name) := Lean.mkIdent (Lean.mkPrivateNameCore `KProgFormal.Reference.X86 name)
  Lean.Elab.Tactic.evalTactic (← `(tactic|
    simp only [effects,$(imported `KProgFormal.Reference.X86.externalEffects):term,
      List.foldl_cons,List.foldl_nil,List.nil_append]))

/-- The SAME canonical Reference.X86 checked PUSH on its explicit successful
native-access domain, including the original arbitrary byte memory, complete
CPU frame, actual write event, initialization and exact next PC. -/
theorem step (state : Reference.X86.State) (nextPc : BitVec 64)
    (running : state.modelError = none)
    (canonical : (List.range 8).all (fun lane => X86.canonical
      (state.gpr 4 - (8#64) + BitVec.ofNat 64 lane)
      (match state.addressWidth with | .w48 => .la48 | .w57 => .la57)) = true)
    (writable : (List.range 8).all (fun lane => state.memory.writable
      (state.gpr 4 - (8#64) + BitVec.ofNat 64 lane)) = true) :
    Reference.X86.step (.push .w64 3 nextPc) state =
      ⟨{state with
        gpr := fun reg => ((input state).setReg .q .rsp (state.gpr 4 - (8#64))).regs.get (X86.GPR.ofIndex reg),
        memory := Reference.storeMemory state.memory (state.gpr 4 - (8#64)) (state.gpr 3) 8,
        pc := nextPc},
        [.memory .write (state.gpr 4 - (8#64)) (Reference.valueBytes (state.gpr 3) 8) true],none⟩ := by
  change Reference.X86.nativeStep (.push .q (.reg .rbx)) nextPc state = _
  let cpu := input state
  let length := (nextPc - state.pc).toNat
  let profile : X86.MemoryProfile :=
    ⟨state.memory.readable,state.memory.writable,state.memory.initialized⟩
  let checked : X86.CheckedState :=
    {cpu := {cpu with mem := X86.Mem.empty},profile := some profile,
     addressWidth := match state.addressWidth with | .w48 => .la48 | .w57 => .la57}
  have active : checked.stopped = false := by
    change state.modelError.isSome = false
    simp only [running,Option.isSome_none]
  have live : X86.Live {cpu with mem := X86.Mem.empty} := running
  have rsp : cpu.regs.get .rsp = state.gpr 4 := X86LogicReference.input_register state .rsp
  have rbx : cpu.regs.get .rbx = state.gpr 3 := X86LogicReference.input_register state .rbx
  have legal : (List.range 8).all (fun lane => X86.canonical
      (checked.cpu.regs.get .rsp - (8#64) + BitVec.ofNat 64 lane) checked.addressWidth) = true := by
    simpa only [checked,rsp] using canonical
  have allowed : (List.range 8).all (fun lane => profile.writable
      (checked.cpu.regs.get .rsp - (8#64) + BitVec.ofNat 64 lane)) = true := by
    simpa only [checked,profile,rsp] using writable
  have numerical := X86.step_push_reg (s := {cpu with mem := X86.Mem.empty}) (len := length) .q .rbx live
  have payload := X86PushNativePayload.bytes X86.Mem.empty (state.gpr 4 - (8#64)) (state.gpr 3)
  have pc : state.pc + BitVec.ofNat 64 (nextPc - state.pc).toNat = nextPc := by
    have encoded : BitVec.ofNat 64 (nextPc - state.pc).toNat = nextPc - state.pc := by
      apply BitVec.eq_of_toNat_eq
      exact Nat.mod_eq_of_lt (nextPc - state.pc).isLt
    rw [encoded,BitVec.add_comm]
    exact BitVec.sub_add_cancel nextPc state.pc
  unfold Reference.X86.nativeStep
  dsimp only
  rw [X86PushChecked.reads]
  simp only [List.foldl_nil]
  let project (output : X86.CheckedState) : Reference.Transition Reference.X86.State :=
    let effect := effects state.memory output.events
    ⟨{state with
      gpr := fun reg => output.cpu.regs.get (X86.GPR.ofIndex reg),
      rflags := flagsWord state.rflags output.cpu.flags,xmm0 := output.cpu.getXmm .x0,
      memory := effect.state,pc := output.cpu.rip,fsBase := output.cpu.fsBase,gsBase := output.cpu.gsBase,
      oracle := output.cpu.oracle,modelError := output.cpu.ms},effect.events,effect.fault⟩
  change project (X86.stepChecked ⟨.push .q (.reg .rbx),length⟩ checked) = _
  rw [X86PushChecked.success checked profile length active rfl legal allowed]
  dsimp only [project]
  rw [show X86.step ⟨.push .q (.reg .rbx),length⟩ {cpu with mem := X86.Mem.empty} checked.addressWidth =
      X86.step ⟨.push .q (.reg .rbx),length⟩ {cpu with mem := X86.Mem.empty} from rfl,numerical]
  have qword : ({cpu with mem := X86.Mem.empty} : X86.Cpu).getReg .q .rbx = state.gpr 3 := by
    simpa only [X86.Cpu.getReg,Bool.false_eq_true,ite_false,X86.Value.trunc_q] using rbx
  simp only [checked,X86.Size.bytes,rsp,qword,List.nil_append]
  rw [payload]
  run_tac projectEffects
  change (⟨{state with
      gpr := fun reg => ((cpu.setReg .q .rsp (state.gpr 4 - (8#64))).regs.get (X86.GPR.ofIndex reg)),
      rflags := flagsWord state.rflags cpu.flags,
      memory := X86NativeByteFold.storeBytes state.memory (state.gpr 4 - (8#64)) (Reference.valueBytes (state.gpr 3) 8),
      pc := state.pc + BitVec.ofNat 64 length},
      [.memory .write (state.gpr 4 - (8#64)) (Reference.valueBytes (state.gpr 3) 8) true],none⟩ : Reference.Transition Reference.X86.State) = _
  rw [X86NativeByteFold.scalar,X86NopReference.flags_roundtrip,pc]

end KProgFormal.ClightRefinement.X86PushReference
