import KProgFormal.ClightRefinement.Arm64MovKeepRead

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MovKeep

open Arm64NumericProgram
open Arm64MovImmediate

private theorem temp_data (unused : Arm64Nop.IgnoredArguments) (entry : CC.Block)
    (i : Fin 31) (imm : BitVec 16) (column : Fin 4) (narrow : Bool) :
    let le := Dispatch.Keep.temps
      (Dispatch.Keep.initialTemps (operands unused entry (BitVec.ofNat 64 i.val) imm column) narrow) narrow
    le.get Arm64Program._entry = some (.Vptr entry 0) ∧
    le.get Arm64Program._dst = some (.Vlong (BitVec.ofNat 64 i.val)) ∧
    le.get Arm64Program._imm = some (.Vlong (imm.setWidth 64)) ∧
    le.get Arm64Program._aux = some (.Vint (aux column)) ∧
    le.get Arm64Program.___a64_l_width = some (Arm64RegisterWrite.width narrow) := by
  cases narrow <;> simp +decide only [Dispatch.Keep.temps, Dispatch.Keep.initialTemps,
    operands, Arm64Nop.resultEnv, Dispatch.flags, Arm64Width.result, Arm64Width.argument,
    Arm64RegisterWrite.width, CC.PTree.gss, CC.PTree.gso]

/-- Execute the entire actual ordinary scalar MOVK call, deriving the read
from its actual pre-call word/tag loads and deriving both stores from rights. -/
theorem call_scalar_returns {m before : CC.Mem} {entry : Arm64Producer.HeaderLocal m}
    (storage : Arm64ProducerRegisterStorage.Storage m before entry)
    (unused : Arm64Nop.IgnoredArguments) (addresses : Arm64Registers.PointerOrigins)
    (i : Fin 31) (bits : BitVec 64) (imm : BitVec 16) (column : Fin 4) (narrow : Bool)
    (word : CC.Mem.load .Mint64 before ((storage.tables false).cellBlock i) 0 = some (.Vlong bits))
    (tag : CC.Mem.load .Mint8unsigned before ((storage.tables true).cellBlock i) 0 = some (.Vint 0)) :
    ∃ written after,
      Arm64RegisterWrite.Result (storage.frame (Arm64Nop.entry_frame ge before))
        i (merge bits imm column) narrow written ∧
      InternalRun ge 203
        (.Callstate (.Internal Arm64Nop.handler)
          (Dispatch.Keep.arguments (operands unused entry.block (BitVec.ofNat 64 i.val) imm column) narrow) .Kstop before)
        (.Returnstate .Vundef .Kstop after) ∧
      CC.Mem.freeList written (CC.blocksOfEnv ge.genv_cenv (Arm64Nop.allocation ge before).1) = some after ∧
      FrameBelow before.nextblock written after ∧
      after.contents = written.contents ∧ after.nextblock = written.nextblock ∧
      (∀ row ∈ CC.blocksOfEnv ge.genv_cenv (Arm64Nop.allocation ge before).1,
        ∀ ofs, row.2.1 ≤ ofs → ofs < row.2.2 →
          ∀ kind permission, CC.Mem.perm after row.1 ofs kind permission = false) := by
  let carried := storage.frame (Arm64Nop.entry_frame ge before)
  let le := Dispatch.Keep.temps
    (Dispatch.Keep.initialTemps (operands unused entry.block (BitVec.ofNat 64 i.val) imm column) narrow) narrow
  have allocatedWord : CC.Mem.load .Mint64 (Arm64Nop.allocation ge before).2
      ((carried.tables false).cellBlock i) 0 = some (.Vlong bits) :=
    ((Arm64Nop.entry_frame ge before).load .Mint64 _ 0
      (Arm64ProducerEntryView.load_live .Mint64 before _ 0 _ word)).trans word
  have allocatedTag : CC.Mem.load .Mint8unsigned (Arm64Nop.allocation ge before).2
      ((carried.tables true).cellBlock i) 0 = some (.Vint 0) :=
    ((Arm64Nop.entry_frame ge before).load .Mint8unsigned _ 0
      (Arm64ProducerEntryView.load_live .Mint8unsigned before _ 0 _ tag)).trans tag
  have inputs := temp_data unused entry.block i imm column narrow
  have names := Arm64MovImmediate.unshadowed before
  have branch := scalar_writer_call carried addresses (Arm64Nop.allocation ge before).1 le
    i bits imm column narrow names.1 names.2 inputs.1 inputs.2.1 inputs.2.2.1
    inputs.2.2.2.1 inputs.2.2.2.2 allocatedWord allocatedTag
  obtain ⟨written, result⟩ := Arm64RegisterWrite.write carried i (merge bits imm column) narrow
  obtain ⟨middle, wordStore, tagStore⟩ := result.stores
  have write := Arm64RegisterWrite.execute_stores_bound ge composites_same
    (.Kcall none Arm64Nop.handler (Arm64Nop.allocation ge before).1
      (writerTemps le bits imm column) Dispatch.continuation) rfl
    m (Arm64Nop.allocation ge before).2 middle written entry carried i
      (merge bits imm column) narrow wordStore tagStore
  have finish := Suffix.after_writer (Arm64Nop.allocation ge before).1
    (writerTemps le bits imm column) written
  have owned : ∀ id v, (Arm64Nop.allocation ge before).1.get id = some v →
      CC.Mem.rangePerm written v.1 0 (CC.sizeof ge.genv_cenv v.2) .Cur .Freeable = true := by
    intro id v binding
    have live := ((allocated_local_storage (Arm64MovImmediate.allocated before)).1 id v binding).2.2
    exact (CC.Mem.rangePerm_congr (m1 := written) (m2 := (Arm64Nop.allocation ge before).2)
      (fun offset => by simp only [CC.Mem.perm, result.access])).trans live
  obtain ⟨after, freed, frame, contents, next, released⟩ :=
    deallocate_live_locals (Arm64MovImmediate.allocated before) owned
  have dispatch := (Dispatch.Keep.call_dispatch before
    (operands unused entry.block (BitVec.ofNat 64 i.val) imm column) narrow).1
  have leave : InternalRun ge 1
      (.State Arm64Nop.handler .Sskip .Kstop (Arm64Nop.allocation ge before).1
        (writerTemps le bits imm column) written) (.Returnstate .Vundef .Kstop after) :=
    .step trivial (.skip_call _ _ _ _ _ _ rfl freed) (.refl _)
  exact ⟨written, after, result, (((dispatch.trans branch).trans write).trans finish).trans leave,
    freed, frame, contents, next, released⟩

/-- Compare actual stores across allocation and actual free at the ORIGINAL
frontier; the real linked call is retained as the execution certificate. -/
theorem call_scalar_represents {m before : CC.Mem} {entry : Arm64Producer.HeaderLocal m}
    (storage : Arm64ProducerRegisterStorage.Storage m before entry)
    (unused : Arm64Nop.IgnoredArguments) (addresses : Arm64Registers.PointerOrigins)
    (origins : Reference.Provenance.AArch64.Origins) (s : Reference.AArch64.State)
    (i : Fin 31) (bits : BitVec 64) (imm : BitVec 16) (column : Fin 4) (narrow : Bool)
    (word : CC.Mem.load .Mint64 before ((storage.tables false).cellBlock i) 0 = some (.Vlong bits))
    (tag : CC.Mem.load .Mint8unsigned before ((storage.tables true).cellBlock i) 0 = some (.Vint 0))
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s) :
    ∃ after, InternalRun ge 203
      (.Callstate (.Internal Arm64Nop.handler)
        (Dispatch.Keep.arguments (operands unused entry.block (BitVec.ofNat 64 i.val) imm column) narrow) .Kstop before)
      (.Returnstate .Vundef .Kstop after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val)
        before.nextblock after (.Vptr entry.block 0)
          (Arm64RegisterWrite.nativeUpdate s i (merge (Reference.AArch64.gpr s i) imm column) narrow) := by
  have observed : Arm64EntryMemory.gpr before.nextblock before (.Vptr entry.block 0) i.val =
      some (.Vlong bits, .Vint 0) := by
    rw [Arm64RegisterWrite.storage_gpr storage i, word, tag]
    rfl
  have input := scalar_native_bits addresses origins s before.nextblock before (.Vptr entry.block 0)
    i bits observed represented
  have nativeWord : CC.Mem.load .Mint64 before ((storage.tables false).cellBlock i) 0 =
      some (.Vlong (Reference.AArch64.gpr s i)) := by simpa only [input] using word
  obtain ⟨comparison, comparisonResult⟩ := Arm64RegisterWrite.write storage i
    (merge (Reference.AArch64.gpr s i) imm column) narrow
  obtain ⟨written, after, actualResult, run, _, freedFrame, _, _, _⟩ :=
    call_scalar_returns storage unused addresses i (Reference.AArch64.gpr s i) imm column narrow nativeWord tag
  obtain ⟨_, comparisonWord, comparisonTag⟩ := comparisonResult.stores
  obtain ⟨_, actualWord, actualTag⟩ := actualResult.stores
  have wordFrame := stores_frame (Arm64Nop.entry_frame ge before) comparisonWord actualWord
  have tagFrame := stores_frame wordFrame comparisonTag actualTag
  exact ⟨after, run, (Arm64Registers.frame (tagFrame.trans freedFrame) (.Vptr entry.block 0)
    (Arm64RegisterWrite.nativeUpdate s i (merge (Reference.AArch64.gpr s i) imm column) narrow)).mpr
      (comparisonResult.represents addresses origins s represented)⟩

/-- The represented return is the only stuck outcome of any finite run;
all traces are silent and infinite execution is excluded. -/
theorem call_scalar_all_behaviors {m before : CC.Mem} {entry : Arm64Producer.HeaderLocal m}
    (storage : Arm64ProducerRegisterStorage.Storage m before entry)
    (unused : Arm64Nop.IgnoredArguments) (i : Fin 31) (bits : BitVec 64)
    (imm : BitVec 16) (column : Fin 4) (narrow : Bool)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (word : CC.Mem.load .Mint64 before ((storage.tables false).cellBlock i) 0 = some (.Vlong bits))
    (tag : CC.Mem.load .Mint8unsigned before ((storage.tables true).cellBlock i) 0 = some (.Vint 0))
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s) :
    ∃ after, InternalRun ge 203
      (.Callstate (.Internal Arm64Nop.handler)
        (Dispatch.Keep.arguments (operands unused entry.block (BitVec.ofNat 64 i.val) imm column) narrow) .Kstop before)
      (.Returnstate .Vundef .Kstop after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val)
        before.nextblock after (.Vptr entry.block 0)
          (Arm64RegisterWrite.nativeUpdate s i (merge (Reference.AArch64.gpr s i) imm column) narrow) ∧
      (∀ t other, CC.Star (CC.Step2 ge)
        (.Callstate (.Internal Arm64Nop.handler)
          (Dispatch.Keep.arguments (operands unused entry.block (BitVec.ofNat 64 i.val) imm column) narrow) .Kstop before) t other →
        t = CC.E0 ∧ ∃ remaining, InternalRun ge remaining other (.Returnstate .Vundef .Kstop after)) ∧
      (∀ t other, CC.Star (CC.Step2 ge)
        (.Callstate (.Internal Arm64Nop.handler)
          (Dispatch.Keep.arguments (operands unused entry.block (BitVec.ofNat 64 i.val) imm column) narrow) .Kstop before) t other →
        (∀ u next, ¬ CC.Step2 ge other u next) →
        t = CC.E0 ∧ other = .Returnstate .Vundef .Kstop after) ∧
      ¬ (∃ states : Nat → CC.State,
        states 0 = .Callstate (.Internal Arm64Nop.handler)
          (Dispatch.Keep.arguments (operands unused entry.block (BitVec.ofNat 64 i.val) imm column) narrow) .Kstop before ∧
        ∀ i, ∃ t, CC.Step2 ge (states i) t (states (i + 1))) := by
  obtain ⟨after, run, rep⟩ := call_scalar_represents storage unused addresses origins s i bits imm column narrow word tag represented
  have stuck := return_stuck .Vundef after
  exact ⟨after, run, rep, fun _ _ observed => run.finish_prefix stuck observed,
    fun _ _ observed otherStuck => run.endpoint_unique stuck observed otherStuck,
    run.no_infinite stuck⟩

end KProgFormal.ClightRefinement.Arm64MovKeep
