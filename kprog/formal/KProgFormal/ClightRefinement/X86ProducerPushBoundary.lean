import KProgFormal.ClightRefinement.X86ProducerPushStoreObservation
import KProgFormal.ClightRefinement.X86ProducerPushInputOrigin

namespace KProgFormal.ClightRefinement.X86ProducerPushBoundary
open X86ProducerLayout (ge)
open X86ProducerHeaderSource (producer)
open X86LogicReference (input)
open X86ProducerPushInputOrigin (origins)

/-- One concrete original PUSH boundary, using the SAME actual kind1 stack
origin, full original source execution, native data views and real store
observation. Platform initial views/native access are explicit; fetched
instruction binding and general external/guest trace simulation remain open. -/
theorem execute {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    {rsp : X86ProducerPushRspPrefix.Result ready} {metadata : X86ProducerPushMetadataPrefix.Result rsp}
    {cache : X86ProducerPushCachePrefix.Result metadata} (complete : X86ProducerPushComplete.Result cache)
    (arena : BitVec 64) (addresses : Arm64Registers.PointerOrigins)
    (state : Reference.X86.State) (nextPc : BitVec 64) (running : state.modelError = none)
    (canonical : (List.range 8).all (fun lane => X86.canonical
      (state.gpr 4 - (8#64) + BitVec.ofNat 64 lane)
      (match state.addressWidth with | .w48 => .la48 | .w57 => .la57)) = true)
    (writable : (List.range 8).all (fun lane => state.memory.writable
      (state.gpr 4 - (8#64) + BitVec.ofNat 64 lane)) = true)
    (registers : X86RegisterView.RegistersRepresent addresses (origins ready arena) ready.after ready.gprs.block 0 (input state))
    (scalars : X86ProducerScalarView.Represents ready ready.after (input state))
    (memory : X86StackCacheView.Represents ready.after (ready.sources 1).block state.memory (origins ready arena).stack) :
    let next := Reference.X86.step (.push .w64 3 nextPc) state
    CC.Star (CC.Step2 ge)
      (.State producer X86ProducerBindLoop.firstCall (.Kseq X86ProducerContextSource.followingCalls outer)
        (X86ProducerCacheAllocation.allocation ge.genv_cenv before).1 ready.output ready.after) CC.E0
      (.State producer X86ProducerContextSource.followingCalls outer
        (X86ProducerCacheAllocation.allocation ge.genv_cenv before).1 ready.output complete.after) ∧
    X86RegisterView.RegistersRepresent addresses (origins ready arena) complete.after ready.gprs.block 0 (input next.state) ∧
    X86ProducerScalarView.Represents ready complete.after (input next.state) ∧
    X86StackCacheView.Represents complete.after (ready.sources 1).block next.state.memory (origins ready arena).stack ∧
    next.state.pc = nextPc ∧ next.fault = none ∧
    next.events = [X86ProducerPushStoreObservation.event (origins ready arena).stack (ready.values 3)] ∧
    state.gpr 4 = ready.stackOutcome.value ∧
    CC.Mem.load .Mint64 complete.after ready.base.block 0 = some (.Vlong (state.gpr 4)) ∧
    CC.Mem.store .Mint64 metadata.after (ready.sources 1).block 40 (.Vlong (ready.values 3)) = some cache.after := by
  have actual := X86ProducerPushStateView.execute complete addresses (origins ready arena) state nextPc
    running canonical writable registers scalars memory
  have observed := X86ProducerPushStoreObservation.correspondence complete addresses (origins ready arena) state nextPc
    running canonical writable registers
  have initialStack := X86ProducerPushInputOrigin.native_stack arena addresses state registers
  have retained := (X86ProducerPushInputOrigin.base complete arena).2
  refine ⟨actual.1,actual.2.1,actual.2.2.1,actual.2.2.2.1,actual.2.2.2.2.1,actual.2.2.2.2.2.1,
    observed,initialStack,?_,cache.stored⟩
  simpa only [initialStack,origins] using retained

end KProgFormal.ClightRefinement.X86ProducerPushBoundary
