import KProgFormal.ClightRefinement.X86ProducerPushStateView

namespace KProgFormal.ClightRefinement.X86ProducerPushStoreObservation
open X86ProducerLayout (ge)
open X86ProducerPushBody (handler allocation)

/-- Logical observation of the actual selected Mint64 cache write. This
uses the established cache/native coordinate and scalar byte projection;
it is not a Clight external-call event or a second instruction semantics. -/
def event (origin value : BitVec 64) : Reference.Event :=
  .memory .write (X86StackCacheView.address origin 40) (Reference.valueBytes value 8) true

variable {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    {rsp : X86ProducerPushRspPrefix.Result ready}
    {metadata : X86ProducerPushMetadataPrefix.Result rsp}

/-- The observation is backed by the real original assignment transition,
its actual pointer/index/RBX temporaries and all eight actual stored bytes.
No hypothetical successful store or assumed source run is supplied. -/
theorem source (cache : X86ProducerPushCachePrefix.Result metadata) :
    InternalRun ge 1
      (.State handler X86ProducerPushStorageSource.cacheStore
        (X86ProducerPushCacheExecute.following rsp (X86ProducerPushCachePrefix.control ready) metadata.after)
        (allocation ready.after).1 (X86ProducerPushCachePrefix.temps metadata) metadata.after)
      (.State handler .Sskip
        (X86ProducerPushCacheExecute.following rsp (X86ProducerPushCachePrefix.control ready) metadata.after)
        (allocation ready.after).1 (X86ProducerPushCachePrefix.temps metadata) cache.after) ∧
    ∀ lane : Fin 8, CC.Mem.load .Mint8unsigned cache.after (ready.sources 1).block (40 + lane.val) =
      some (.Vint (((Reference.valueBytes (ready.values 3) 8)[lane.val]!).setWidth 32)) := by
  have inputs := X86ProducerPushStorageSelect.cache_inputs rsp (X86ProducerPushCachePrefix.control ready) metadata.after
  have pointer : (X86ProducerPushCachePrefix.temps metadata).get X86_program_profile_bpf._t'211 =
      some (.Vptr (ready.sources 1).block 0) := CC.PTree.gss _ _ _
  have index : (X86ProducerPushCachePrefix.temps metadata).get X86_program_profile_bpf.___x86_stw_index = some (.Vlong (40#64)) := by
    simpa +decide [X86ProducerPushCachePrefix.temps,CC.PTree.gso] using inputs.2.1
  have value : (X86ProducerPushCachePrefix.temps metadata).get X86_program_profile_bpf.___x86_loss_value = some (.Vlong (ready.values 3)) := by
    simpa +decide [X86ProducerPushCachePrefix.temps,CC.PTree.gso] using inputs.2.2.1
  refine ⟨X86ProducerPushCacheExecute.assignment _ _ _ metadata.after cache.after (ready.sources 1).block (ready.values 3)
    pointer index value cache.stored,?_⟩
  intro lane
  simpa [Reference.valueBytes,lane.isLt] using X86ScalarStoreBytes.load cache.stored lane

/-- The canonical write event is exactly the logical observation of the
same actual cache assignment. This is a boundary observation equality,
not an equality between the whole source E0 and guest-event traces. -/
theorem correspondence {cache : X86ProducerPushCachePrefix.Result metadata} (complete : X86ProducerPushComplete.Result cache)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.X86.Origins)
    (state : Reference.X86.State) (nextPc : BitVec 64) (running : state.modelError = none)
    (canonical : (List.range 8).all (fun lane => X86.canonical
      (state.gpr 4 - (8#64) + BitVec.ofNat 64 lane)
      (match state.addressWidth with | .w48 => .la48 | .w57 => .la57)) = true)
    (writable : (List.range 8).all (fun lane => state.memory.writable
      (state.gpr 4 - (8#64) + BitVec.ofNat 64 lane)) = true)
    (registers : X86RegisterView.RegistersRepresent addresses origins ready.after ready.gprs.block 0 (X86LogicReference.input state)) :
    (Reference.X86.step (.push .w64 3 nextPc) state).events = [event origins.stack (ready.values 3)] := by
  rw [X86PushReference.step state nextPc running canonical writable]
  have stack : state.gpr 4 = origins.stack := by
    have sp := X86ProducerPushGprView.initial_sp addresses origins (X86LogicReference.input state) registers
    simpa only [X86LogicReference.input_register,X86.GPR.index_ofIndex] using sp
  have payload := X86ProducerPushNativeRegisters.payload complete addresses origins (X86LogicReference.input state) registers
  have value : ready.values 3 = state.gpr 3 := by
    have same := CC.Val.Vlong.inj (Option.some.inj (complete.word_read.symm.trans payload))
    simpa only [X86LogicReference.input_register,X86.GPR.index_ofIndex] using same
  have position := X86PushNativePayload.coordinate origins.stack 0
  have coordinate : X86StackCacheView.address origins.stack 40 = origins.stack - (8#64) := by simpa using position
  simp only [event,stack,value,coordinate]

end KProgFormal.ClightRefinement.X86ProducerPushStoreObservation
