import KProgFormal.ClightRefinement.X86ProducerPushReference
import KProgFormal.ClightRefinement.X86ProducerScalarView

namespace KProgFormal.ClightRefinement.X86ProducerPushStateView
open X86ProducerLayout (ge)
open X86ProducerHeaderSource (producer)
open X86LogicReference (input)

/-- Same original source execution and final heap represent all actual GPR,
flag, XMM0 and initialized-cache views of the EXACT shared ISA step. Initial
platform views and native access are explicit. Native events are described,
not equated to the source's silent private cache update. -/
theorem execute {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    {rsp : X86ProducerPushRspPrefix.Result ready} {metadata : X86ProducerPushMetadataPrefix.Result rsp}
    {cache : X86ProducerPushCachePrefix.Result metadata} (complete : X86ProducerPushComplete.Result cache)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.X86.Origins)
    (state : Reference.X86.State) (nextPc : BitVec 64) (running : state.modelError = none)
    (canonical : (List.range 8).all (fun lane => X86.canonical
      (state.gpr 4 - (8#64) + BitVec.ofNat 64 lane)
      (match state.addressWidth with | .w48 => .la48 | .w57 => .la57)) = true)
    (writable : (List.range 8).all (fun lane => state.memory.writable
      (state.gpr 4 - (8#64) + BitVec.ofNat 64 lane)) = true)
    (registers : X86RegisterView.RegistersRepresent addresses origins ready.after ready.gprs.block 0 (input state))
    (scalars : X86ProducerScalarView.Represents ready ready.after (input state))
    (memory : X86StackCacheView.Represents ready.after (ready.sources 1).block state.memory origins.stack) :
    let next := Reference.X86.step (.push .w64 3 nextPc) state
    CC.Star (CC.Step2 ge)
      (.State producer X86ProducerBindLoop.firstCall (.Kseq X86ProducerContextSource.followingCalls outer)
        (X86ProducerCacheAllocation.allocation ge.genv_cenv before).1 ready.output ready.after) CC.E0
      (.State producer X86ProducerContextSource.followingCalls outer
        (X86ProducerCacheAllocation.allocation ge.genv_cenv before).1 ready.output complete.after) ∧
    X86RegisterView.RegistersRepresent addresses origins complete.after ready.gprs.block 0 (input next.state) ∧
    X86ProducerScalarView.Represents ready complete.after (input next.state) ∧
    X86StackCacheView.Represents complete.after (ready.sources 1).block next.state.memory origins.stack ∧
    next.state.pc = nextPc ∧ next.fault = none ∧
    next.events = [.memory .write (state.gpr 4 - (8#64)) (Reference.valueBytes (state.gpr 3) 8) true] := by
  have actual := X86ProducerPushReference.execute complete addresses origins state nextPc running canonical writable registers memory
  have scalar := X86ProducerScalarView.reference complete state nextPc running canonical writable scalars
  exact ⟨actual.1,actual.2.1,scalar,actual.2.2⟩

end KProgFormal.ClightRefinement.X86ProducerPushStateView
