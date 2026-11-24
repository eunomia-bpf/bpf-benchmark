import KProgFormal.ClightRefinement.X86ProducerPushInputOrigin

namespace KProgFormal.ClightRefinement.X86ProducerHeaderReady
open X86ProducerLayout (ge)
open X86ProducerHeaderSource (localName)
open X86ProducerHeaderLocals (SourceLocal)

variable {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    {rsp : X86ProducerPushRspPrefix.Result ready}
    {metadata : X86ProducerPushMetadataPrefix.Result rsp}
    {cache : X86ProducerPushCachePrefix.Result metadata}

/-- Identical original allocator bindings identify the same source object;
no fresh block equality or pointer-header premise is assumed. -/
theorem source_block (ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer)
    (i : Fin 24) (object : SourceLocal ge.genv_cenv before i) : (ready.sources i).block = object.block := by
  have binding := (ready.sources i).binding.symm.trans object.binding
  exact congrArg Prod.fst (Option.some.inj binding)

/-- Every original header-pointer read survives the actual complete PUSH,
including header112's native-base pointer and all flag/vector pointers. -/
theorem preserve (complete : X86ProducerPushComplete.Result cache) (header : X86ProducerEntryReady.HeaderReads ready) :
    ∀ i : Fin 24, CC.Mem.load CC.Mptr complete.after ready.entry.block (8 * (i.val : Int)) =
      some (.Vptr (ready.sources i).block 0) := by
  have names : X86_program_profile_bpf.___x86_inline_bindings ≠ localName 0 ∧
      X86_program_profile_bpf.___x86_inline_bindings ≠ localName 1 ∧
      X86_program_profile_bpf.___x86_inline_bindings ≠ localName 12 ∧
      X86_program_profile_bpf.___x86_inline_bindings ≠ localName 13 := by decide +kernel
  intro i
  exact (X86ProducerPushLocalFrame.loads complete ready.entry names _ _).trans (header i)

/-- Current header/cell/native-base observations needed by the real RSP
reader all derive the same source initializer and genuine PUSH/free frames. -/
theorem current (complete : X86ProducerPushComplete.Result cache) (header : X86ProducerEntryReady.HeaderReads ready) :
    CC.Mem.load CC.Mptr complete.after ready.entry.block 0 = some (.Vptr ready.gprs.block 0) ∧
    CC.Mem.load CC.Mptr complete.after ready.entry.block 112 = some (.Vptr ready.base.block 0) ∧
    CC.Mem.load .Mint64 complete.after ready.base.block 0 = some (.Vlong ready.stackOutcome.value) ∧
    CC.Mem.load CC.Mptr complete.after ready.gprs.block 64 = some (.Vlong X86ProducerPushRspStore.nextRsp) := by
  have base := preserve complete header 14
  rw [source_block ready 14 ready.base] at base
  exact ⟨complete.cells_read,base,(X86ProducerPushInputOrigin.base complete 0).2,complete.rsp_read⟩

/-- No initialized header or post-PUSH source run is a premise: SAME real
kind6/kind1 prefix constructs the stronger packet and all genuine outputs. -/
theorem from_call (before : CC.Mem) (ctxBlock : CC.Block) (ctxOffset : CC.Integers.Ptrofs) (outer : CC.Cont)
    (inputs6 : X86ProducerRaxPrefix.Inputs before) (inputs1 : X86ProducerStackBaseProvider.Inputs before) :
    ∃ ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer,
    ∃ rsp : X86ProducerPushRspPrefix.Result ready, ∃ metadata : X86ProducerPushMetadataPrefix.Result rsp,
    ∃ cache : X86ProducerPushCachePrefix.Result metadata, ∃ complete : X86ProducerPushComplete.Result cache,
      X86ProducerEntryReady.HeaderReads ready ∧
      (∀ i : Fin 24, CC.Mem.load CC.Mptr complete.after ready.entry.block (8 * (i.val : Int)) = some (.Vptr (ready.sources i).block 0)) := by
  obtain ⟨ready,header⟩ := X86ProducerEntryReady.from_call_with_header before ctxBlock ctxOffset outer inputs6 inputs1
  obtain ⟨rsp⟩ := X86ProducerPushRspPrefix.from_ready ready
  obtain ⟨metadata⟩ := X86ProducerPushMetadataPrefix.from_rsp rsp
  obtain ⟨cache⟩ := X86ProducerPushCachePrefix.from_metadata metadata
  obtain ⟨complete⟩ := X86ProducerPushComplete.from_cache cache
  exact ⟨ready,rsp,metadata,cache,complete,header,preserve complete header⟩

end KProgFormal.ClightRefinement.X86ProducerHeaderReady
