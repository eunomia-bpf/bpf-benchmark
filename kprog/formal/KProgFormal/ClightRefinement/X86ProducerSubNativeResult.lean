import KProgFormal.ClightRefinement.X86ProducerSubResult
import KProgFormal.ClightRefinement.X86SubImmediateReference

namespace KProgFormal.ClightRefinement.X86ProducerSubNativeResult
open X86LogicReference (input)
open X86ProducerPushInputOrigin (origins)

variable {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    {rsp : X86ProducerPushRspPrefix.Result ready} {metadata : X86ProducerPushMetadataPrefix.Result rsp}
    {cache : X86ProducerPushCachePrefix.Result metadata}

/-- Numerical RSP of the SAME two canonical ISA steps. Initial GPR view
binds actual kind1 stack input; native PUSH access success remains explicit.
This theorem does not claim source flags or RSP writeback already occurred. -/
theorem native (arena : BitVec 64) (addresses : Arm64Registers.PointerOrigins)
    (state : Reference.X86.State) (pushPc subPc : BitVec 64) (running : state.modelError = none)
    (canonical : (List.range 8).all (fun lane => X86.canonical
      (state.gpr 4-(8#64)+BitVec.ofNat 64 lane)
      (match state.addressWidth with | .w48 => .la48 | .w57 => .la57)) = true)
    (writable : (List.range 8).all (fun lane => state.memory.writable
      (state.gpr 4-(8#64)+BitVec.ofNat 64 lane)) = true)
    (registers : X86RegisterView.RegistersRepresent addresses (origins ready arena)
      ready.after ready.gprs.block 0 (input state)) :
    let pushed := Reference.X86.step (.push .w64 3 pushPc) state
    let subtracted := Reference.X86.step (.arithmetic .w64 .sub (.register (.low 4)) (.immediate 32) subPc) pushed.state
    subtracted.state.gpr 4 = ready.stackOutcome.value-(8#64)-(32#64) := by
  let pushed := Reference.X86.step (.push .w64 3 pushPc) state
  have push := X86PushReference.step state pushPc running canonical writable
  have stack := X86ProducerPushInputOrigin.native_stack arena addresses state registers
  have rspRegister : X86.GPR.ofIndex (4 : Fin 16) = .rsp := rfl
  have pushedStack : pushed.state.gpr 4 = state.gpr 4-(8#64) := by
    rw [show pushed = Reference.X86.step (.push .w64 3 pushPc) state from rfl,push]
    simp only [X86.Cpu.setReg,X86.Value.writeView,Bool.false_eq_true,ite_false,rspRegister,X86.Regs.get_set_same]
  have live : pushed.state.modelError = none := by
    rw [show pushed = Reference.X86.step (.push .w64 3 pushPc) state from rfl,push]
    exact running
  have sub := X86SubImmediateReference.step pushed.state 4 32 subPc live
  change (Reference.X86.step (.arithmetic .w64 .sub (.register (.low 4)) (.immediate 32) subPc) pushed.state).state.gpr 4 = _
  rw [sub]
  simp only [X86.Cpu.setReg,X86.Value.writeView,Bool.false_eq_true,ite_false,rspRegister,X86.Regs.get_set_same,pushedStack,stack]
  all_goals rfl

/-- The genuine original saved source result equals THAT canonical native
RSP. The source temp derives actual helper/caller execution; no result
correspondence or native-base equality is assumed as an intermediate premise. -/
theorem saved (complete : X86ProducerPushComplete.Result cache)
    (arena : BitVec 64) (addresses : Arm64Registers.PointerOrigins)
    (state : Reference.X86.State) (pushPc subPc : BitVec 64) (running : state.modelError = none)
    (canonical : (List.range 8).all (fun lane => X86.canonical
      (state.gpr 4-(8#64)+BitVec.ofNat 64 lane)
      (match state.addressWidth with | .w48 => .la48 | .w57 => .la57)) = true)
    (writable : (List.range 8).all (fun lane => state.memory.writable
      (state.gpr 4-(8#64)+BitVec.ofNat 64 lane)) = true)
    (registers : X86RegisterView.RegistersRepresent addresses (origins ready arena)
      ready.after ready.gprs.block 0 (input state)) :
    let pushed := Reference.X86.step (.push .w64 3 pushPc) state
    let subtracted := Reference.X86.step (.arithmetic .w64 .sub (.register (.low 4)) (.immediate 32) subPc) pushed.state
    (X86ProducerSubResult.temps ready.entry.block (X86ProducerSubLhs.bodyCont complete) complete.after
      (ready.stackOutcome.value-(8#64))).get X86_program_profile_bpf.___x86_l_result =
        some (.Vlong (subtracted.state.gpr 4)) := by
  dsimp only
  rw [native arena addresses state pushPc subPc running canonical writable registers]
  exact X86ProducerSubResult.saved _ _ _ _

/-- SAME original source run and exact saved-number correspondence are
composed together. Source flags/register writeback remain later obligations. -/
theorem execute (complete : X86ProducerPushComplete.Result cache)
    (header : X86ProducerEntryReady.HeaderReads ready)
    (arena : BitVec 64) (addresses : Arm64Registers.PointerOrigins)
    (state : Reference.X86.State) (pushPc subPc : BitVec 64) (running : state.modelError = none)
    (canonical : (List.range 8).all (fun lane => X86.canonical
      (state.gpr 4-(8#64)+BitVec.ofNat 64 lane)
      (match state.addressWidth with | .w48 => .la48 | .w57 => .la57)) = true)
    (writable : (List.range 8).all (fun lane => state.memory.writable
      (state.gpr 4-(8#64)+BitVec.ofNat 64 lane)) = true)
    (registers : X86RegisterView.RegistersRepresent addresses (origins ready arena)
      ready.after ready.gprs.block 0 (input state)) :
    let pushed := Reference.X86.step (.push .w64 3 pushPc) state
    let subtracted := Reference.X86.step (.arithmetic .w64 .sub (.register (.low 4)) (.immediate 32) subPc) pushed.state
    CC.Star (CC.Step2 X86ProducerLayout.ge)
      (.State X86ProducerHeaderSource.producer X86ProducerBindLoop.firstCall (.Kseq X86ProducerContextSource.followingCalls outer)
        (X86ProducerCacheAllocation.allocation X86ProducerLayout.ge.genv_cenv before).1 ready.output ready.after) CC.E0
      (.State X86ProducerSubBody.handler .Sskip
        (X86ProducerSubResult.following ready.entry.block (X86ProducerSubLhs.bodyCont complete) complete.after (ready.stackOutcome.value-(8#64)))
        (X86ProducerSubBody.allocation complete.after).1
        (X86ProducerSubResult.temps ready.entry.block (X86ProducerSubLhs.bodyCont complete) complete.after (ready.stackOutcome.value-(8#64)))
        (X86ProducerSubBody.allocation complete.after).2) ∧
    (X86ProducerSubResult.temps ready.entry.block (X86ProducerSubLhs.bodyCont complete) complete.after
      (ready.stackOutcome.value-(8#64))).get X86_program_profile_bpf.___x86_l_result =
        some (.Vlong (subtracted.state.gpr 4)) :=
  ⟨X86ProducerSubResult.execute complete header,
    saved complete arena addresses state pushPc subPc running canonical writable registers⟩

end KProgFormal.ClightRefinement.X86ProducerSubNativeResult
