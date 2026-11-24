import KProgFormal.ClightRefinement.X86ProducerPushRspRead
import KProgFormal.ClightRefinement.X86ProducerPushRspValue

namespace KProgFormal.ClightRefinement.X86ProducerPushRspExecute
open X86ProducerLayout (ge)
open X86ProducerPushBody (handler allocation)

/-- Execute the original RSP decrement assignment and true following skip,
using the store already constructed from the SAME actual allocation. -/
theorem assignment (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (memory after : CC.Mem) (cells : CC.Block)
    (first : le.get X86_program_profile_bpf._t'228 = some (.Vptr cells 0))
    (current : le.get X86_program_profile_bpf._t'230 = some (.Vlong 0))
    (eight : le.get X86_program_profile_bpf.___x86_l_pp_step = some (.Vlong (8#64)))
    (stored : CC.Mem.store CC.Mptr memory cells 64 (.Vlong X86ProducerPushRspStore.nextRsp) = some after) :
    InternalRun ge 2
      (.State handler X86ProducerPushRspSource.store (.Kseq X86ProducerPushRspSource.stackLoop k) e le memory)
      (.State handler X86ProducerPushRspSource.stackLoop k e le after) := by
  have address : CC.doEvalLvalue ge e le memory X86ProducerPushRspSource.target = some (cells, (64#64), .Full) := by
    rw [X86ProducerPushRspAddress.original.2.2]
    exact X86ProducerPushRspAddress.pointer_address e le memory cells _ first
  have evaluated := X86ProducerPushRspValue.evaluate e le memory current eight
  have storev : CC.Mem.storev CC.Mptr memory (.Vptr cells (64#64)) (.Vlong X86ProducerPushRspStore.nextRsp) = some after := stored
  have access : CC.accessMode (CC.typeof X86ProducerPushRspSource.target) = .By_value CC.Mptr := rfl
  have step : CC.doStep ge
      (.State handler X86ProducerPushRspSource.store (.Kseq X86ProducerPushRspSource.stackLoop k) e le memory) =
      some (CC.E0, .State handler .Sskip (.Kseq X86ProducerPushRspSource.stackLoop k) e le after) := by
    rw [X86ProducerPushRspSource.reads.2.2.2]
    simp only [CC.doStep, address, evaluated.1, evaluated.2, CC.doAssignLoc, access]
    change (match CC.Mem.storev CC.Mptr memory (.Vptr cells (64#64)) (.Vlong X86ProducerPushRspStore.nextRsp) with
      | some heap => some (CC.E0, CC.State.State handler .Sskip (.Kseq X86ProducerPushRspSource.stackLoop k) e le heap)
      | none => none) = _
    rw [storev]
  exact .step trivial (CC.doStep_sound ge _ _ _ step)
    (.step trivial (CC.doStep_sound ge _ _ _ rfl) (.refl _))

/-- All actual source steps from the saved operand to the real stack loop
compose with genuine RSP store/readback and original caller/data frames. -/
theorem from_ready {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    (ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer) (bodyCont : CC.Cont) :
    ∃ after, InternalRun ge 13
      (.State handler .Sskip (X86ProducerPushReadReturn.following ready.entry.block bodyCont ready.after)
        (allocation ready.after).1 (X86ProducerPushReadReturn.temps ready.entry.block bodyCont ready.after (ready.values 3))
        (allocation ready.after).2)
      (.State handler X86ProducerPushRspSource.stackLoop (X86ProducerPushRspSource.control ready.entry.block bodyCont ready.after)
        (allocation ready.after).1
        (X86ProducerPushRspRead.temps (X86ProducerPushReadReturn.temps ready.entry.block bodyCont ready.after (ready.values 3)) ready.gprs.block) after) ∧
    CC.Mem.store CC.Mptr (allocation ready.after).2 ready.gprs.block 64 (.Vlong X86ProducerPushRspStore.nextRsp) = some after ∧
    CC.Mem.load CC.Mptr after ready.gprs.block 64 = some (.Vlong X86ProducerPushRspStore.nextRsp) ∧
    (∀ row : Fin 32, row ≠ 8 → CC.Mem.load (X86ProducerGprStore.chunk row) after ready.gprs.block (X86ProducerGprStore.offset row) =
      CC.Mem.load (X86ProducerGprStore.chunk row) (allocation ready.after).2 ready.gprs.block (X86ProducerGprStore.offset row)) ∧
    (∀ c b ofs, b ≠ ready.gprs.block → CC.Mem.load c after b ofs = CC.Mem.load c (allocation ready.after).2 b ofs) ∧
    FrameBelow before.nextblock (allocation ready.after).2 after ∧
    after.access = (allocation ready.after).2.access ∧ after.nextblock = (allocation ready.after).2.nextblock := by
  obtain ⟨after, stored, readback, rows, outside, caller, access, frontier⟩ := X86ProducerPushRspStore.write ready
  let initial := X86ProducerPushReadReturn.temps ready.entry.block bodyCont ready.after (ready.values 3)
  have first : (X86ProducerPushRspRead.temps initial ready.gprs.block).get X86_program_profile_bpf._t'228 = some (.Vptr ready.gprs.block 0) := by
    simp +decide [X86ProducerPushRspRead.temps, X86ProducerPushRspRead.secondTemps,
      X86ProducerPushRspRead.firstTemps, CC.PTree.gss, CC.PTree.gso]
  have current : (X86ProducerPushRspRead.temps initial ready.gprs.block).get X86_program_profile_bpf._t'230 = some (.Vlong 0) := CC.PTree.gss _ _ _
  have eight : (X86ProducerPushRspRead.temps initial ready.gprs.block).get X86_program_profile_bpf.___x86_l_pp_step = some (.Vlong (8#64)) := by
    simp +decide only [X86ProducerPushRspRead.temps, X86ProducerPushRspRead.secondTemps,
      X86ProducerPushRspRead.firstTemps, CC.PTree.gso]
    exact (X86ProducerPushRspSource.inputs ready.entry.block bodyCont ready.after (ready.values 3)).2.1
  have enter := X86ProducerPushRspSource.enter ready.entry.block bodyCont ready.after (ready.values 3)
  have loaded := X86ProducerPushRspRead.from_ready ready bodyCont
    (.Kseq X86ProducerPushRspSource.stackLoop (X86ProducerPushRspSource.control ready.entry.block bodyCont ready.after))
  have assigned := assignment (allocation ready.after).1 (X86ProducerPushRspRead.temps initial ready.gprs.block)
    (X86ProducerPushRspSource.control ready.entry.block bodyCont ready.after) (allocation ready.after).2 after ready.gprs.block
    first current eight stored
  exact ⟨after, (enter.trans loaded).trans assigned, stored, readback, rows, outside, caller, access, frontier⟩

end KProgFormal.ClightRefinement.X86ProducerPushRspExecute
