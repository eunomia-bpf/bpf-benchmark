import KProgFormal.ClightRefinement.X86ProducerPushReadPrefix
import KProgFormal.ClightRefinement.X86ProducerPushRspExecute
import KProgFormal.ClightRefinement.X86ProducerPushRspResources

namespace KProgFormal.ClightRefinement.X86ProducerPushRspPrefix
open X86ProducerHeaderSource (producer)
open X86ProducerLayout (ge)
open X86ProducerPushBody (handler allocation)
open X86ProducerPushPrefix (bodyCont)

def temps {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {k : CC.Cont}
    (ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset k) : CC.TempEnv :=
  X86ProducerPushRspRead.temps (X86ProducerPushReadReturn.temps ready.entry.block (bodyCont ready) ready.after (ready.values 3)) ready.gprs.block

/-- One complete original traced source prefix and its current resources.
The endpoint precedes actual stack/cache stores and completion of PUSH. -/
structure Result {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {k : CC.Cont}
    (ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset k) where
  after : CC.Mem
  run : CC.Star (CC.Step2 ge) (.Callstate (.Internal producer) [.Vptr ctxBlock ctxOffset] k before) ready.trace
    (.State handler X86ProducerPushRspSource.stackLoop (X86ProducerPushRspSource.control ready.entry.block (bodyCont ready) ready.after)
      (allocation ready.after).1 (temps ready) after)
  stored : CC.Mem.store CC.Mptr (allocation ready.after).2 ready.gprs.block 64 (.Vlong X86ProducerPushRspStore.nextRsp) = some after
  rsp_read : CC.Mem.load CC.Mptr after ready.gprs.block 64 = some (.Vlong X86ProducerPushRspStore.nextRsp)
  rows : ∀ row : Fin 32, row ≠ 8 → CC.Mem.load (X86ProducerGprStore.chunk row) after ready.gprs.block (X86ProducerGprStore.offset row) =
    CC.Mem.load (X86ProducerGprStore.chunk row) (allocation ready.after).2 ready.gprs.block (X86ProducerGprStore.offset row)
  outside : ∀ c b ofs, b ≠ ready.gprs.block → CC.Mem.load c after b ofs = CC.Mem.load c (allocation ready.after).2 b ofs
  header : ∀ c ofs, CC.Mem.load c after ready.entry.block ofs = CC.Mem.load c (allocation ready.after).2 ready.entry.block ofs
  cache_view : X86ReleaseProvider.View after ready.entry.block (ready.sources 1).block 0
  ghost_view : X86CallFrameComplete.View after ready.entry.block (X86ProducerHeaderViews.ghosts ready.sources)
  cells_read : CC.Mem.load CC.Mptr after ready.entry.block 0 = some (.Vptr ready.gprs.block 0)
  rsp_tag : CC.Mem.load .Mint8unsigned after ready.gprs.block 72 = some (.Vint 0)
  caller_loads : ∀ c b ofs, b.toNat < before.nextblock.toNat → CC.Mem.load c after b ofs = CC.Mem.load c before b ofs
  post_provider_frame : FrameBelow before.nextblock ready.stackOutcome.supplied after
  access : after.access = (allocation ready.after).2.access
  frontier : after.nextblock = (allocation ready.after).2.nextblock

/-- No source run, store, post-store View or new provider premise is assumed;
all actual RSP-update effects follow the SAME initialized producer prefix. -/
theorem from_ready {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {k : CC.Cont}
    (ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset k) : Nonempty (Result ready) := by
  obtain ⟨after, executed, stored, rsp, rows, outside, caller, access, frontier⟩ :=
    X86ProducerPushRspExecute.from_ready ready (bodyCont ready)
  have resources := X86ProducerPushRspResources.views ready stored
  have source := star_trans (X86ProducerPushReadPrefix.from_ready ready) executed.sound
  have bound : before.nextblock.toNat ≤ ready.after.nextblock.toNat := by
    have fresh := ready.gprs.fresh
    have owned : ready.gprs.block.toNat < ready.after.nextblock.toNat := by
      rw [ready.frontier]
      exact ready.gprs.owned
    omega
  have bodyFrame : FrameBelow before.nextblock ready.after (allocation ready.after).2 := by
    intro b below
    exact (X86ProducerPushBody.entry_frame ready.after).2 b (by omega)
  refine ⟨⟨after, ?_, stored, rsp, rows, outside, resources.1, resources.2.1, resources.2.2.1,
    resources.2.2.2.1, resources.2.2.2.2, ?_, ready.post_provider_frame.trans (bodyFrame.trans caller), access, frontier⟩⟩
  · simpa only [temps, CC.E0, CC.Eapp, List.append_nil] using source
  · intro c b ofs below
    exact (caller.load c b ofs below).trans ((bodyFrame.load c b ofs below).trans (ready.caller_loads c b ofs below))

theorem from_call (before : CC.Mem) (ctxBlock : CC.Block) (ctxOffset : CC.Integers.Ptrofs) (k : CC.Cont)
    (inputs6 : X86ProducerRaxPrefix.Inputs before) (inputs1 : X86ProducerStackBaseProvider.Inputs before) :
    ∃ ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset k, Nonempty (Result ready) := by
  obtain ⟨ready⟩ := X86ProducerEntryReady.from_call before ctxBlock ctxOffset k inputs6 inputs1
  exact ⟨ready, from_ready ready⟩

end KProgFormal.ClightRefinement.X86ProducerPushRspPrefix
