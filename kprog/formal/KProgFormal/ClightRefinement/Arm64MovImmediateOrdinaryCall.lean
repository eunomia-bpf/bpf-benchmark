import KProgFormal.ClightRefinement.Arm64MovImmediateCall
import KProgFormal.ClightRefinement.Arm64MovKeepLinkedCall
import KProgFormal.ClightRefinement.Arm64ProgramEntryAllocation

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MovImmediate.OrdinaryCall

open Arm64ProgramEntryAllocation (world)

/-- Original ordinary MOV calls retain all three NONE register selectors and
the actual zero auxiliary argument. The immediate stays arbitrary. -/
def operands (entry : CC.Block) (i : Fin 31) (value : BitVec 64) : Arm64Nop.IgnoredArguments :=
  ⟨.Vptr entry 0,.Vlong (BitVec.ofNat 64 i.val),.Vlong 255,.Vlong 255,.Vlong 255,.Vint 0,.Vlong value⟩

def temps (entry : CC.Block) (i : Fin 31) (value : BitVec 64) : CC.TempEnv :=
  Dispatch.scalarEnv (Dispatch.initialTemps (operands entry i value) false) false

private theorem temp_data (entry : CC.Block) (i : Fin 31) (value : BitVec 64) :
    (temps entry i value).get Arm64Program._entry = some (.Vptr entry 0) ∧
    (temps entry i value).get Arm64Program._src = some (.Vlong 255) ∧
    (temps entry i value).get Arm64Program._dst = some (.Vlong (BitVec.ofNat 64 i.val)) ∧
    (temps entry i value).get Arm64Program._op = some (.Vint 1) ∧
    (temps entry i value).get Arm64Program._imm = some (.Vlong value) ∧
    (temps entry i value).get Arm64Program.___a64_l_width = some (Arm64RegisterWrite.width false) := by
  simp +decide only [temps,Dispatch.scalarEnv,Dispatch.dispatchEnv,Dispatch.initialTemps,
    operands,Arm64Nop.resultEnv,Dispatch.flags,Arm64Width.result,Arm64Width.argument,
    Arm64RegisterWrite.width,CC.PTree.gss,CC.PTree.gso,Bool.false_eq_true,ite_false]

/-- The original mandatory NONE read, switch and writer edge execute in the
actual fixture-linked world, with its real reader66 and writer107 bindings. -/
theorem to_writer (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (entry : CC.Block)
    (i : Fin 31) (value : BitVec 64)
    (readName : e.get Arm64Program._kprog_arm64_program_read = none)
    (writeName : e.get Arm64Program._kprog_arm64_program_write = none)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (hsrc : le.get Arm64Program._src = some (.Vlong 255))
    (hdst : le.get Arm64Program._dst = some (.Vlong (BitVec.ofNat 64 i.val)))
    (hop : le.get Arm64Program._op = some (.Vint 1))
    (himm : le.get Arm64Program._imm = some (.Vlong value))
    (hwidth : le.get Arm64Program.___a64_l_width = some (Arm64RegisterWrite.width false)) :
    InternalRun world 78
      (.State Arm64Nop.handler Dispatch.scalarBranch Dispatch.continuation e le m)
      (.Callstate (.Internal Arm64RegisterWrite.procedure)
        (Arm64RegisterWrite.arguments entry i value false)
        (.Kcall none Arm64Nop.handler e (Suffix.writerTemps le value) Dispatch.continuation) m) := by
  have enter := Suffix.read_call_bound world (CC.Positive.ofNat 66) Arm64MovKeep.Linked.reader_binding
    255 e le m entry readName hentry hsrc
  have read := Arm64MovImmediate.read_none world (.Vptr entry 0) m
    (.Kcall (some Arm64Program._t'4) Arm64Nop.handler e le Suffix.readCont)
  have select := Suffix.after_read_bound world (CC.Positive.ofNat 107) Arm64MovKeep.Linked.writer_binding
    0 e le m entry (BitVec.ofNat 64 i.val) value false writeName hentry hdst hop himm hwidth
  simpa only [CC.callCont,Suffix.writerTemps,Arm64RegisterWrite.arguments] using (enter.trans read).trans select

/-- Complete original generic MOV call in the real linked world, including
allocation, width and destination helpers, NONE read, both stores, loop exit,
free of every actual generic local and return to the supplied call continuation. -/
theorem execute {initial before : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial before entry)
    (i : Fin 31) (value : BitVec 64) (k : CC.Cont) (valid : CC.isCallCont k = true) :
    ∃ written after,
      Arm64RegisterWrite.Result (storage.frame (Arm64Nop.entry_frame world before)) i value false written ∧
      InternalRun world 203
        (.Callstate (.Internal Arm64Nop.handler) (Dispatch.arguments (operands entry.block i value) false) k before)
        (.Returnstate .Vundef k after) ∧
      CC.Mem.freeList written (CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world before).1) = some after ∧
      FrameBelow before.nextblock written after ∧
      after.contents = written.contents ∧ after.nextblock = written.nextblock ∧
      (∀ row ∈ CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world before).1,
        ∀ ofs, row.2.1 ≤ ofs → ofs < row.2.2 →
          ∀ kind permission, CC.Mem.perm after row.1 ofs kind permission = false) := by
  let carried := storage.frame (Arm64Nop.entry_frame world before)
  let e := (Arm64Nop.allocation world before).1
  let le := temps entry.block i value
  have inputs := temp_data entry.block i value
  have names := Arm64MovImmediate.unshadowed_bound world before
  have call := to_writer e le (Arm64Nop.allocation world before).2 entry.block i value names.1 names.2
    inputs.1 inputs.2.1 inputs.2.2.1 inputs.2.2.2.1 inputs.2.2.2.2.1 inputs.2.2.2.2.2
  obtain ⟨written,effect⟩ := Arm64RegisterWrite.write carried i value false
  obtain ⟨middle,wordStore,tagStore⟩ := effect.stores
  have write := Arm64RegisterWrite.execute_stores_layout world Arm64MovKeep.Linked.writer_layout
    (.Kcall none Arm64Nop.handler e (Suffix.writerTemps le value) Dispatch.continuation) rfl
    initial (Arm64Nop.allocation world before).2 middle written entry carried i value false wordStore tagStore
  have finish := Suffix.after_writer_bound world e (Suffix.writerTemps le value) written
  have halloc := Arm64MovImmediate.allocated_bound world before
  have owned : ∀ id v, e.get id = some v →
      CC.Mem.rangePerm written v.1 0 (CC.sizeof world.genv_cenv v.2) .Cur .Freeable = true := by
    intro id v binding
    have live := ((allocated_local_storage halloc).1 id v binding).2.2
    exact (CC.Mem.rangePerm_congr (m1 := written) (m2 := (Arm64Nop.allocation world before).2)
      (fun ofs => by simp only [CC.Mem.perm,effect.access])).trans live
  obtain ⟨after,freed,frame,contents,next,released⟩ := deallocate_live_locals halloc owned
  have dispatch := (Dispatch.call_dispatch_bound world (CC.Positive.ofNat 97) (CC.Positive.ofNat 98)
    Arm64MovKeep.Linked.width_binding Arm64ProgramEntryLinked.mov_selector_binding before (operands entry.block i value) false).1
  have leave : InternalRun world 1
      (.State Arm64Nop.handler .Sskip .Kstop e (Suffix.writerTemps le value) written)
      (.Returnstate .Vundef .Kstop after) :=
    .step trivial (.skip_call _ _ _ _ _ _ rfl freed) (.refl _)
  have run : InternalRun world 203
      (.Callstate (.Internal Arm64Nop.handler) (Dispatch.arguments (operands entry.block i value) false) .Kstop before)
      (.Returnstate .Vundef .Kstop after) := (((dispatch.trans call).trans write).trans finish).trans leave
  refine ⟨written,after,effect,?_,freed,frame,contents,next,released⟩
  simpa only [Continuation.state,Continuation.extend] using Continuation.run_extend k valid run

end KProgFormal.ClightRefinement.Arm64MovImmediate.OrdinaryCall
