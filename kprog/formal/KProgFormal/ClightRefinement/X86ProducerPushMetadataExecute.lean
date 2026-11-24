import KProgFormal.ClightRefinement.X86ProducerPushMetadataSelect
import KProgFormal.ClightRefinement.X86ProducerPushMetadataClear
import KProgFormal.ClightRefinement.X86ProducerPushMetadataCurrent

namespace KProgFormal.ClightRefinement.X86ProducerPushMetadataExecute
open X86ProducerLayout (ge)
open X86ProducerPushBody (handler allocation)
open X86ProducerPushStackSource (prepareCont storage outerCont)

def selection {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    (ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer) (k : CC.Cont) (memory : CC.Mem) :=
  X86ProducerPushMetadataSelect.certificate ready (prepareCont k) memory

def temps {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    (ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer) (k : CC.Cont) (memory : CC.Mem) : CC.TempEnv :=
  X86ProducerPushMetadataClear.temps (selection ready k memory).output (ready.sources 12).block (ready.sources 13).block 0 0

/-- Finish the real slot5 loop, prepare loop and source sequence into the
original storage loop; no break or control transition is omitted. -/
theorem resume (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (memory : CC.Mem) :
    InternalRun ge 5
      (.State handler .Sskip (X86ProducerPushMetadataSource.continuation 5 (prepareCont k)) e le memory)
      (.State handler storage (outerCont k) e le memory) := by
  apply internalRun_of_steps
  all_goals simp only [steps, InternalPath, InternalState, CC.doStep,
    X86ProducerPushMetadataSource.continuation, prepareCont, CC.E0, CC.Eapp, List.nil_append, true_and]

/-- Actual stack preparation/width, all six overlap guards and both selected
slot5 stores compose to the real storage loop on the SAME RSP-prefix heap.
The only inputs are the already constructed producer/source result. -/
theorem from_rsp {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    (result : X86ProducerPushRspPrefix.Result ready) (k : CC.Cont) :
    ∃ middle after, CC.Mem.store .Mint8unsigned result.after (ready.sources 12).block 0 (.Vint 0) = some middle ∧
    CC.Mem.store CC.Mptr middle (ready.sources 13).block 0 (.Vlong 0) = some after ∧
    InternalRun ge (25 + (selection ready k result.after).count + 18)
      (.State handler X86ProducerPushRspSource.stackLoop k (allocation ready.after).1 (X86ProducerPushRspPrefix.temps ready) result.after)
      (.State handler storage (outerCont k) (allocation ready.after).1 (temps ready k result.after) after) ∧
    CC.Mem.load .Mint8unsigned after (ready.sources 12).block 0 = some (.Vint 0) ∧
    CC.Mem.load CC.Mptr after (ready.sources 13).block 0 = some (.Vlong 0) ∧
    (∀ c ofs, CC.Mem.load c after ready.entry.block ofs = CC.Mem.load c result.after ready.entry.block ofs) ∧
    (∀ c ofs, CC.Mem.load c after ready.gprs.block ofs = CC.Mem.load c result.after ready.gprs.block ofs) ∧
    (∀ c ofs, CC.Mem.load c after (ready.sources 1).block ofs = CC.Mem.load c result.after (ready.sources 1).block ofs) ∧
    X86ReleaseProvider.View after ready.entry.block (ready.sources 1).block 0 ∧
    X86CallFrameComplete.View after ready.entry.block (X86ProducerHeaderViews.ghosts ready.sources) ∧
    FrameBelow before.nextblock ready.stackOutcome.supplied after ∧
    (∀ c b ofs, b.toNat < before.nextblock.toNat → CC.Mem.load c after b ofs = CC.Mem.load c before b ofs) ∧
    after.access = result.after.access ∧ after.nextblock = result.after.nextblock := by
  have selected := X86ProducerPushMetadataSelect.executes ready (prepareCont k) result.after
  rw [X86ProducerPushMetadataSelect.source_continuation] at selected
  have sourceInputs := X86ProducerPushMetadataSelect.inputs ready (prepareCont k) result.after
  have safe := ready.separated.2.2 5
  have tagRead : CC.Mem.load CC.Mptr result.after ready.entry.block 96 = some (.Vptr (ready.sources 12).block 0) := result.ghost_view.tags 5
  have pointerRead : CC.Mem.load CC.Mptr result.after ready.entry.block 104 = some (.Vptr (ready.sources 13).block 0) := result.ghost_view.pointers 5
  obtain ⟨middle,after,tagStored,pointerStored,cleared,tagBack,pointerBack,access,frontier,frame⟩ :=
    X86ProducerPushMetadataClear.execute (allocation ready.after).1 (selection ready k result.after).output
      (X86ProducerPushMetadataSource.continuation 5 (prepareCont k)) result.after ready.entry.block
      (ready.sources 12).block (ready.sources 13).block 0 0 sourceInputs.1 tagRead pointerRead safe.1 safe.2.2
      (result.ghost_view.tag_rights 5) (result.ghost_view.pointer_rights 5)
  have current := X86ProducerPushMetadataCurrent.preserve result tagStored pointerStored
  have full := (((X86ProducerPushStackWidth.from_rsp result k).trans selected).trans cleared).trans
    (resume (allocation ready.after).1 (temps ready k result.after) k after)
  exact ⟨middle,after,tagStored,pointerStored,full,tagBack,pointerBack,current⟩

/-- Original binding, width selector and saved RBX remain the actual inputs
to the following storage loop after both metadata assignments. -/
theorem inputs {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    (ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer) (k : CC.Cont) (memory : CC.Mem) :
    (temps ready k memory).get X86_program_profile_bpf.___x86_bind = some (.Vptr ready.entry.block 0) ∧
    (temps ready k memory).get X86_program_profile_bpf.___x86_l_pp_width = some (.Vint (8#32)) ∧
    (temps ready k memory).get X86_program_profile_bpf.___x86_l_pp_value = some (.Vlong (ready.values 3)) := ⟨rfl,rfl,rfl⟩

end KProgFormal.ClightRefinement.X86ProducerPushMetadataExecute
