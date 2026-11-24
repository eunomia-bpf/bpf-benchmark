import KProgFormal.ClightRefinement.X86PushReference
import KProgFormal.ClightRefinement.X86ProducerPushNativeCache

namespace KProgFormal.ClightRefinement.X86ProducerPushReference
open X86ProducerLayout (ge)
open X86ProducerHeaderSource (producer)
open X86LogicReference (input)

variable {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    {rsp : X86ProducerPushRspPrefix.Result ready}
    {metadata : X86ProducerPushMetadataPrefix.Result rsp}
    {cache : X86ProducerPushCachePrefix.Result metadata}

/-- Actual original source PUSH and the EXACT shared Reference.X86 step
have corresponding GPRs and initialized cache bytes on the explicit native
success domain. The native write event is characterized separately from
the source's silent private-cache execution; no trace equality is asserted. -/
theorem execute (complete : X86ProducerPushComplete.Result cache)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.X86.Origins)
    (state : Reference.X86.State) (nextPc : BitVec 64)
    (running : state.modelError = none)
    (canonical : (List.range 8).all (fun lane => X86.canonical
      (state.gpr 4 - (8#64) + BitVec.ofNat 64 lane)
      (match state.addressWidth with | .w48 => .la48 | .w57 => .la57)) = true)
    (writable : (List.range 8).all (fun lane => state.memory.writable
      (state.gpr 4 - (8#64) + BitVec.ofNat 64 lane)) = true)
    (registers : X86RegisterView.RegistersRepresent addresses origins ready.after ready.gprs.block 0 (input state))
    (memory : X86StackCacheView.Represents ready.after (ready.sources 1).block state.memory origins.stack) :
    let next := Reference.X86.step (.push .w64 3 nextPc) state
    CC.Star (CC.Step2 ge)
      (.State producer X86ProducerBindLoop.firstCall (.Kseq X86ProducerContextSource.followingCalls outer)
        (X86ProducerCacheAllocation.allocation ge.genv_cenv before).1 ready.output ready.after) CC.E0
      (.State producer X86ProducerContextSource.followingCalls outer
        (X86ProducerCacheAllocation.allocation ge.genv_cenv before).1 ready.output complete.after) ∧
    X86RegisterView.RegistersRepresent addresses origins complete.after ready.gprs.block 0 (input next.state) ∧
    X86StackCacheView.Represents complete.after (ready.sources 1).block next.state.memory origins.stack ∧
    next.state.pc = nextPc ∧ next.fault = none ∧
    next.events = [.memory .write (state.gpr 4 - (8#64)) (Reference.valueBytes (state.gpr 3) 8) true] := by
  have source := X86ProducerPushNativeRegisters.execute complete addresses origins (input state) registers
  have cacheMemory := X86ProducerPushNativeCache.memory complete addresses origins state.memory (input state) registers memory
  dsimp only
  rw [X86PushReference.step state nextPc running canonical writable]
  refine ⟨source.1,?_,?_,rfl,rfl,rfl⟩
  · intro index
    obtain ⟨value,raw,tag,wordRead,tagRead,valueRep,native⟩ := source.2.1 index
    refine ⟨value,raw,tag,wordRead,tagRead,valueRep,?_⟩
    rw [X86LogicReference.input_register,X86.GPR.index_ofIndex]
    have nativeRsp : (input state).regs.get .rsp = state.gpr 4 := X86LogicReference.input_register state .rsp
    simpa only [nativeRsp,show X86.GPR.ofIndex (4 : Fin 16) = .rsp from rfl] using native
  · simpa only [X86LogicReference.input_register,
      show X86.GPR.rsp.index = (4 : Fin 16) from rfl,
      show X86.GPR.rbx.index = (3 : Fin 16) from rfl,
      show X86.GPR.ofIndex (4 : Fin 16) = .rsp from rfl,
      show X86.GPR.ofIndex (3 : Fin 16) = .rbx from rfl,
      show (8 : BitVec 64) = (8#64) from rfl] using cacheMemory

end KProgFormal.ClightRefinement.X86ProducerPushReference
