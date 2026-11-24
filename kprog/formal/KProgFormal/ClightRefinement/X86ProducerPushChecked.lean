import KProgFormal.ClightRefinement.X86PushMemoryView
import KProgFormal.ClightRefinement.X86PushChecked

namespace KProgFormal.ClightRefinement.X86ProducerPushChecked
open X86ProducerLayout (ge)
open X86ProducerHeaderSource (producer)

variable {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    {rsp : X86ProducerPushRspPrefix.Result ready}
    {metadata : X86ProducerPushMetadataPrefix.Result rsp}
    {cache : X86ProducerPushCachePrefix.Result metadata}

/-- The actual silent PUSH C call represents GPRs and initialized cached
bytes of the pinned checked native step, on its explicit successful native
access domain. Initial platform/cache relation, guest-event observation,
fetch/PC and full instruction refinement remain separate obligations. -/
theorem execute (complete : X86ProducerPushComplete.Result cache)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.X86.Origins)
    (state : X86.CheckedState) (profile : X86.MemoryProfile) (length : Nat)
    (running : state.stopped = false) (present : state.profile = some profile)
    (canonical : (List.range 8).all (fun lane => X86.canonical
      (state.cpu.regs.get .rsp - (8#64) + BitVec.ofNat 64 lane) state.addressWidth) = true)
    (writable : (List.range 8).all (fun lane => profile.writable
      (state.cpu.regs.get .rsp - (8#64) + BitVec.ofNat 64 lane)) = true)
    (registers : X86RegisterView.RegistersRepresent addresses origins ready.after ready.gprs.block 0 state.cpu)
    (memory : X86StackCacheView.Represents ready.after (ready.sources 1).block
      (X86PushMemoryView.view state.cpu.mem profile) origins.stack) :
    let next := X86.stepChecked ⟨.push .q (.reg .rbx),length⟩ state
    ∃ outputProfile, next.profile = some outputProfile ∧
      CC.Star (CC.Step2 ge)
        (.State producer X86ProducerBindLoop.firstCall (.Kseq X86ProducerContextSource.followingCalls outer)
          (X86ProducerCacheAllocation.allocation ge.genv_cenv before).1 ready.output ready.after) CC.E0
        (.State producer X86ProducerContextSource.followingCalls outer
          (X86ProducerCacheAllocation.allocation ge.genv_cenv before).1 ready.output complete.after) ∧
      X86RegisterView.RegistersRepresent addresses origins complete.after ready.gprs.block 0 next.cpu ∧
      X86StackCacheView.Represents complete.after (ready.sources 1).block
        (X86PushMemoryView.view next.cpu.mem outputProfile) origins.stack ∧
      next.fault = state.fault := by
  have source := X86ProducerPushNativeRegisters.execute complete addresses origins state.cpu registers
  have stack : state.cpu.regs.get .rsp = origins.stack :=
    X86ProducerPushGprView.initial_sp addresses origins state.cpu registers
  have payload := X86ProducerPushNativeRegisters.payload complete addresses origins state.cpu registers
  have same : ready.values 3 = state.cpu.regs.get .rbx :=
    CC.Val.Vlong.inj (Option.some.inj (complete.word_read.symm.trans payload))
  have bytes := X86PushMemoryView.represented ready.after complete.after (ready.sources 1).block state.cpu.mem profile
    origins.stack (state.cpu.regs.get .rbx) memory (fun byte => by simpa only [same] using X86ProducerPushCacheBytes.table complete byte)
  have live : X86.Live state.cpu := by
    cases observed : state.cpu.ms with
    | none => exact observed
    | some error => simp [X86.CheckedState.stopped,X86.Cpu.stopped,observed] at running
  have numeric := X86.step_push_reg (s := state.cpu) (len := length) .q .rbx live
  dsimp only
  rw [X86PushChecked.success state profile length running present canonical writable]
  change ∃ outputProfile, _
  rw [show X86.step ⟨.push .q (.reg .rbx),length⟩ state.cpu state.addressWidth =
    X86.step ⟨.push .q (.reg .rbx),length⟩ state.cpu from rfl,numeric]
  refine ⟨_,rfl,source.1,?_,?_,rfl⟩
  · intro index
    obtain ⟨value,raw,tag,wordRead,tagRead,valueRep,native⟩ := source.2.1 index
    refine ⟨value,raw,tag,wordRead,tagRead,valueRep,?_⟩
    simpa only [X86.Cpu.setReg,X86.Value.writeView,Bool.false_eq_true,ite_false,X86.Size.bytes,
      show X86.GPR.ofIndex (4 : Fin 16) = .rsp from rfl] using native
  · have qword : state.cpu.getReg .q .rbx = state.cpu.regs.get .rbx := by
      simpa only [X86.Cpu.getReg,Bool.false_eq_true,ite_false] using X86.Value.trunc_q (state.cpu.regs.get .rbx)
    simpa only [stack,qword,X86.Size.bytes,show (8 : BitVec 64) = (8#64) from rfl] using bytes

end KProgFormal.ClightRefinement.X86ProducerPushChecked
