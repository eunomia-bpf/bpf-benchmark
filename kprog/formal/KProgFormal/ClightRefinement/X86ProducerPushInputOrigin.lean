import KProgFormal.ClightRefinement.X86ProducerPushStateView

namespace KProgFormal.ClightRefinement.X86ProducerPushInputOrigin
open X86ProducerLayout (ge)
open X86ProducerHeaderSource (localName)

variable {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    {rsp : X86ProducerPushRspPrefix.Result ready}
    {metadata : X86ProducerPushMetadataPrefix.Result rsp}
    {cache : X86ProducerPushCachePrefix.Result metadata}

/-- Bind the representation to the SAME actual kind1 input invocation.
Private arena coordinates remain an explicit representation parameter. -/
def origins (ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer) (arena : BitVec 64) :
    Reference.Provenance.X86.Origins := ⟨ready.stackOutcome.value,arena⟩

/-- The original native-base object retains the actual kind1 value through
PUSH. This derives current storage from genuine frames, without assuming
an independent origin/result equality or setting the native origin to zero. -/
theorem base (complete : X86ProducerPushComplete.Result cache) (arena : BitVec 64) :
    CC.Mem.load .Mint64 ready.after ready.base.block 0 = some (.Vlong (origins ready arena).stack) ∧
    CC.Mem.load .Mint64 complete.after ready.base.block 0 = some (.Vlong (origins ready arena).stack) := by
  have names : localName 14 ≠ localName 0 ∧ localName 14 ≠ localName 1 ∧ localName 14 ≠ localName 12 ∧ localName 14 ≠ localName 13 := by decide +kernel
  exact ⟨ready.base_read,(X86ProducerPushLocalFrame.loads complete ready.base names _ _).trans ready.base_read⟩

/-- Relative source RSP zero represents the actual kind1 native stack input
under the existing GPR relation. No weak provider law is strengthened. -/
theorem native_stack (arena : BitVec 64) (addresses : Arm64Registers.PointerOrigins) (state : Reference.X86.State)
    (registers : X86RegisterView.RegistersRepresent addresses (origins ready arena) ready.after ready.gprs.block 0
      (X86LogicReference.input state)) : state.gpr 4 = ready.stackOutcome.value := by
  have actual := X86ProducerPushGprView.initial_sp addresses (origins ready arena) (X86LogicReference.input state) registers
  simpa only [X86LogicReference.input_register,X86.GPR.index_ofIndex,origins] using actual

end KProgFormal.ClightRefinement.X86ProducerPushInputOrigin
