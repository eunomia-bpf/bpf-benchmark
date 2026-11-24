import KProgFormal.ClightRefinement.Arm64ProducerAbiBodyView
import KProgFormal.ClightRefinement.Arm64MemsetStackInputs
import KProgFormal.ClightRefinement.Arm64ProducerTailFrame

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemsetHeaderView

open Arm64Producer Arm64ProducerRegisterStorage
open Arm64ProgramEntryAllocation (world)
open Arm64ProgramEntryBody (afterSetup setupTemps contextOffset)
open Arm64ProgramEntryBodyView (Result nativeSetup)

/-- The actual source stack/tag roots and scalar fields used by the store route. -/
structure View (initial memory : CC.Mem) (entry : HeaderLocal initial) where
  stack : TailLocal initial 0
  tags : StackTagLocal initial
  stackPointer : CC.Mem.load CC.Mptr memory entry.block 608 = some (.Vptr stack.block 0)
  tagPointer : CC.Mem.load CC.Mptr memory entry.block 648 = some (.Vptr tags.block 0)
  capacity : CC.Mem.load .Mint32 memory entry.block 656 = some (.Vint 160)
  bias : CC.Mem.load .Mint64 memory entry.block 672 = some (.Vlong 96)

private noncomputable def canonical_tag (initial : CC.Mem) (source : TailLocal initial 2) : StackTagLocal initial := by
  let actual := Classical.choice (stack_tag_local initial)
  have same : actual.block = source.block :=
    congrArg Prod.fst (Option.some.inj (actual.binding.symm.trans source.binding))
  exact ⟨source.block,source.binding,by rw [←same]; exact actual.fresh,by rw [←same]; exact actual.range⟩

/-- Project the real sixteen-field initializer output, with its original
actual allocation-bound source witnesses, into the fields used by memset. -/
noncomputable def of_header {initial memory : CC.Mem} {entry : HeaderLocal initial}
    (sources : (i : Fin 9) → TailLocal initial i)
    (reads : ∀ i, CC.Mem.load (tailChunk i) memory entry.block (tailOffset i) =
      some (Arm64ProgramEntryTail.actualValue sources i)) : View initial memory entry where
  stack := sources 0
  tags := canonical_tag initial (sources 2)
  stackPointer := by
    have actual := reads ⟨0,by decide⟩
    change CC.Mem.load CC.Mptr memory entry.block 608 = some (.Vptr (sources 0).block 0) at actual
    exact actual
  tagPointer := by
    have actual := reads ⟨5,by decide⟩
    change CC.Mem.load CC.Mptr memory entry.block 648 = some (.Vptr (sources 2).block 0) at actual
    exact actual
  capacity := by
    have actual := reads ⟨6,by decide⟩
    change CC.Mem.load .Mint32 memory entry.block 656 = some (.Vint 160) at actual
    exact actual
  bias := by
    have actual := reads ⟨9,by decide⟩
    change CC.Mem.load .Mint64 memory entry.block 672 = some (.Vlong 96) at actual
    exact actual

/-- The SAME actual header observations survive the existing source frame. -/
def of_frame {initial before after : CC.Mem} {entry : HeaderLocal initial}
    (view : View initial before entry) (frame : Arm64ProducerTailFrame.Frame initial entry before after) :
    View initial after entry where
  stack := view.stack
  tags := view.tags
  stackPointer := (frame.header CC.Mptr 608).trans view.stackPointer
  tagPointer := (frame.header CC.Mptr 648).trans view.tagPointer
  capacity := (frame.header .Mint32 656).trans view.capacity
  bias := (frame.header .Mint64 672).trans view.bias

/-- Actual pointer/MOV effects and the real memset allocation preserve this
same source view, including both scalar fields and the two actual blocks. -/
def through_inputs {initial before pointerWritten markWritten markAfter constantWritten constantAfter : CC.Mem}
    {entry : HeaderLocal initial} {storage : Storage initial before entry}
    {raw : BitVec 64} {addresses : Arm64Registers.PointerOrigins}
    {origins : Reference.Provenance.AArch64.Origins} {prior next : Reference.AArch64.State}
    {priorK nextK : CC.Cont} {mark : BitVec 32}
    (pointer : Arm64PointerWrite.Result storage 0 raw (4#8) pointerWritten)
    (bound : (allocation initial).2.nextblock.toNat ≤ pointerWritten.nextblock.toNat)
    (first : Arm64MovImmediate.OrdinaryCall.Result pointer.storage 1 (mark.setWidth 64)
      addresses origins prior priorK markWritten markAfter)
    (second : Arm64MovImmediate.OrdinaryCall.Result (first.storage bound) 2 (16#64)
      addresses origins next nextK constantWritten constantAfter)
    (view : View initial before entry) : View initial (Arm64MemsetSource.allocation constantAfter).2 entry where
  stack := view.stack
  tags := view.tags
  stackPointer := (Arm64MemsetStackInputs.header pointer bound first second CC.Mptr 608).trans view.stackPointer
  tagPointer := (Arm64MemsetStackInputs.header pointer bound first second CC.Mptr 648).trans view.tagPointer
  capacity := (Arm64MemsetStackInputs.header pointer bound first second .Mint32 656).trans view.capacity
  bias := (Arm64MemsetStackInputs.header pointer bound first second .Mint64 672).trans view.bias

/-- The actual98-provider source execution constructs the view at the
same reached heap while retaining every original setup/storage contract. -/
theorem entry_setup_represents (initial : CC.Mem) (ctxBlock : CC.Block)
    (ctxOfs : CC.Integers.Ptrofs) (k : CC.Cont)
    (kind : TailLocal initial 6)
    (addresses : Arm64Registers.PointerOrigins) (ctxWord : BitVec 64)
    (context : Arm64Registers.ValueRep addresses (.Vptr ctxBlock ctxOfs) ctxWord)
    (values : Fin 31 → BitVec 64) (provider : Arm64ProducerGprInputs.ProviderAt world initial values)
    (flags : Fin 4 → BitVec 64) (flagProvider : Arm64ProducerFlagInputs.ProviderAt world initial flags)
    (vectors : Fin 64 → BitVec 64) (vectorProvider : Arm64ProducerVectorInputs.ProviderAt world initial vectors)
    (origins : Reference.Provenance.AArch64.Origins) (s : Reference.AArch64.State)
    (native : Arm64ProgramEntryRegisterView.NativeBindings origins ctxWord values flags vectors s)
    (fields : Fin 3 → BitVec 32) (old : ctxBlock.toNat < initial.nextblock.toNat)
    (reads : ∀ i : Fin 3, CC.Mem.loadv .Mint32 initial (.Vptr ctxBlock
      (CC.Integers.Ptrofs.add ctxOfs (CC.Integers.Ptrofs.repr (contextOffset i)))) = some (.Vint (fields i))) :
    ∃ entry : HeaderLocal initial, ∃ cells : (i : Fin 12) → HeaderSourceLocal initial i,
    ∃ sources : (i : Fin 9) → TailLocal initial i, ∃ localVector : VectorLocal initial,
    ∃ before temps after, ∃ traces : List CC.Trace,
      traces.length = 98 ∧
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [.Vptr ctxBlock ctxOfs] k initial)
        traces.flatten (.State Arm64ProgramFixture.f_arm64_execute_compile afterSetup
          k (Arm64ProgramEntryAllocation.allocation initial).1 (setupTemps temps fields) after) ∧
      (∀ i, CC.Mem.load CC.Mptr after entry.block (8 * (i.val : Int)) =
        some (.Vptr (cells i).block 0)) ∧
      (∀ high (i : Fin 32), CC.Mem.load CC.Mptr after entry.block
        ((if high then 352 else 96) + 8 * (i.val : Int)) =
        some (.Vptr localVector.block (vectorLoopSourceOffset high i))) ∧
      (∀ i, CC.Mem.load (tailChunk i) after entry.block (tailOffset i) =
        some (Arm64ProgramEntryTail.actualValue sources i)) ∧
      ∃ storage : Storage initial before entry,
        Result storage temps k ctxBlock ctxOfs fields after ∧
        Arm64Registers.Represents addresses origins (fun r => r.val)
          before.nextblock after (.Vptr entry.block 0) (nativeSetup s origins fields) ∧
        Arm64ProgramEntryResources.Resources initial after entry ∧
        Nonempty (Arm64ProgramEntryInitialized.Values initial before (.Vptr ctxBlock ctxOfs)
          values flags vectors) ∧
        after.access = (Arm64Producer.allocation initial).2.access ∧
        before.nextblock = (Arm64ProgramEntryAllocation.allocation initial).2.nextblock ∧
        CC.Mem.load .Mint8unsigned after kind.block 0 = some (.Vint 2) ∧
        CC.Mem.load CC.Mptr after entry.block 704 = some (.Vptr kind.block 0) ∧
        Nonempty (View initial after entry) := by
  obtain ⟨entry,cells,sources,localVector,before,temps,after,traces,length,run,pointers,vectorPointers,
    tailReads,storage,result,registers,resources,data,access,next,abi,abiPointer⟩ :=
    Arm64ProducerAbiBodyView.entry_setup_represents initial ctxBlock ctxOfs k kind addresses ctxWord context
      values provider flags flagProvider vectors vectorProvider origins s native fields old reads
  exact ⟨entry,cells,sources,localVector,before,temps,after,traces,length,run,pointers,vectorPointers,
    tailReads,storage,result,registers,resources,data,access,next,abi,abiPointer,⟨of_header sources tailReads⟩⟩

end KProgFormal.ClightRefinement.Arm64MemsetHeaderView
