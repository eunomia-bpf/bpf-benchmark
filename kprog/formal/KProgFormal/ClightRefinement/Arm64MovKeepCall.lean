import KProgFormal.ClightRefinement.Arm64MovKeepSuffix
import KProgFormal.ClightRefinement.Arm64MovImmediateView

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MovKeep

open Arm64NumericProgram
open Arm64MovImmediate

private theorem temp_data (unused : Arm64Nop.IgnoredArguments) (entry : CC.Block)
    (imm : BitVec 16) (column : Fin 4) (narrow : Bool) :
    let le := Dispatch.Keep.temps
      (Dispatch.Keep.initialTemps (operands unused entry 31 imm column) narrow) narrow
    le.get Arm64Program._entry = some (.Vptr entry 0) ∧
    le.get Arm64Program._dst = some (.Vlong 31) ∧
    le.get Arm64Program._imm = some (.Vlong (imm.setWidth 64)) ∧
    le.get Arm64Program._aux = some (.Vint (aux column)) ∧
    le.get Arm64Program.___a64_l_width = some (Arm64RegisterWrite.width narrow) := by
  cases narrow <;> simp +decide only [Dispatch.Keep.temps, Dispatch.Keep.initialTemps,
    operands, Arm64Nop.resultEnv, Dispatch.flags, Arm64Width.result, Arm64Width.argument,
    Arm64RegisterWrite.width, CC.PTree.gss, CC.PTree.gso]

/-- All 156 transitions of the actual opcode-5 generic call for WZR/XZR:
allocation, dispatch, DST read, merge, real writer, loop exit and frame free.
Its source register selector is 31, distinct from SP32. -/
theorem call_zr_returns {m before : CC.Mem} {entry : Arm64Producer.HeaderLocal m}
    (storage : Arm64ProducerRegisterStorage.Storage m before entry)
    (unused : Arm64Nop.IgnoredArguments) (imm : BitVec 16) (column : Fin 4) (narrow : Bool) :
    ∃ after, InternalRun ge 156
      (.Callstate (.Internal Arm64Nop.handler)
        (Dispatch.Keep.arguments (operands unused entry.block 31 imm column) narrow) .Kstop before)
      (.Returnstate .Vundef .Kstop after) ∧
      CC.Mem.freeList (Arm64Nop.allocation ge before).2
        (CC.blocksOfEnv ge.genv_cenv (Arm64Nop.allocation ge before).1) = some after ∧
      FrameBelow before.nextblock before after ∧
      after.contents = (Arm64Nop.allocation ge before).2.contents ∧
      after.nextblock = (Arm64Nop.allocation ge before).2.nextblock ∧
      (∀ row ∈ CC.blocksOfEnv ge.genv_cenv (Arm64Nop.allocation ge before).1,
        ∀ ofs, row.2.1 ≤ ofs → ofs < row.2.2 →
          ∀ kind permission, CC.Mem.perm after row.1 ofs kind permission = false) := by
  let carried := storage.frame (Arm64Nop.entry_frame ge before)
  let le := Dispatch.Keep.temps
    (Dispatch.Keep.initialTemps (operands unused entry.block 31 imm column) narrow) narrow
  have inputs := temp_data unused entry.block imm column narrow
  have names := Arm64MovImmediate.unshadowed before
  have branch := zr_writer_call (Arm64Nop.allocation ge before).1 le
    (Arm64Nop.allocation ge before).2 entry.block imm column narrow names.1 names.2
    inputs.1 inputs.2.1 inputs.2.2.1 inputs.2.2.2.1 inputs.2.2.2.2
  have write := Arm64RegisterWrite.execute_zr_bound ge composites_same
    (.Kcall none Arm64Nop.handler (Arm64Nop.allocation ge before).1
      (writerTemps le 0 imm column) Dispatch.continuation) rfl
    m (Arm64Nop.allocation ge before).2 entry carried (merge 0 imm column) narrow
  have finish := Suffix.after_writer (Arm64Nop.allocation ge before).1
    (writerTemps le 0 imm column) (Arm64Nop.allocation ge before).2
  have owned : ∀ id v, (Arm64Nop.allocation ge before).1.get id = some v →
      CC.Mem.rangePerm (Arm64Nop.allocation ge before).2 v.1 0
        (CC.sizeof ge.genv_cenv v.2) .Cur .Freeable = true := by
    intro id v binding
    exact ((allocated_local_storage (Arm64MovImmediate.allocated before)).1 id v binding).2.2
  obtain ⟨after, freed, frame, contents, next, released⟩ :=
    deallocate_live_locals (Arm64MovImmediate.allocated before) owned
  have dispatch := (Dispatch.Keep.call_dispatch before
    (operands unused entry.block 31 imm column) narrow).1
  have leave : InternalRun ge 1
      (.State Arm64Nop.handler .Sskip .Kstop (Arm64Nop.allocation ge before).1
        (writerTemps le 0 imm column) (Arm64Nop.allocation ge before).2)
      (.Returnstate .Vundef .Kstop after) :=
    .step trivial (.skip_call _ _ _ _ _ _ rfl freed) (.refl _)
  exact ⟨after, (((dispatch.trans branch).trans write).trans finish).trans leave,
    freed, (Arm64Nop.entry_frame ge before).trans frame, contents, next, released⟩

/-- The full call preserves the complete GPR/SP/SIMD/NZCV relation at the
original reader frontier, after its real local frame has been freed. -/
theorem call_zr_represents {m before : CC.Mem} {entry : Arm64Producer.HeaderLocal m}
    (storage : Arm64ProducerRegisterStorage.Storage m before entry)
    (unused : Arm64Nop.IgnoredArguments) (imm : BitVec 16) (column : Fin 4) (narrow : Bool)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s) :
    ∃ after, InternalRun ge 156
      (.Callstate (.Internal Arm64Nop.handler)
        (Dispatch.Keep.arguments (operands unused entry.block 31 imm column) narrow) .Kstop before)
      (.Returnstate .Vundef .Kstop after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val)
        before.nextblock after (.Vptr entry.block 0) s := by
  obtain ⟨after, run, _, frame, _, _, _⟩ := call_zr_returns storage unused imm column narrow
  exact ⟨after, run, (Arm64Registers.frame frame (.Vptr entry.block 0) s).mpr represented⟩

theorem return_stuck (value : CC.Val) (memory : CC.Mem) :
    ∀ t next, ¬ CC.Step2 ge (.Returnstate value .Kstop memory) t next := by
  intro t next step
  cases step

/-- Every finite relational execution is a silent prefix of that same
register-preserving return, and no infinite execution exists. -/
theorem call_zr_all_behaviors {m before : CC.Mem} {entry : Arm64Producer.HeaderLocal m}
    (storage : Arm64ProducerRegisterStorage.Storage m before entry)
    (unused : Arm64Nop.IgnoredArguments) (imm : BitVec 16) (column : Fin 4) (narrow : Bool)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s) :
    ∃ after, InternalRun ge 156
      (.Callstate (.Internal Arm64Nop.handler)
        (Dispatch.Keep.arguments (operands unused entry.block 31 imm column) narrow) .Kstop before)
      (.Returnstate .Vundef .Kstop after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val)
        before.nextblock after (.Vptr entry.block 0) s ∧
      (∀ t other, CC.Star (CC.Step2 ge)
        (.Callstate (.Internal Arm64Nop.handler)
          (Dispatch.Keep.arguments (operands unused entry.block 31 imm column) narrow) .Kstop before) t other →
        t = CC.E0 ∧ ∃ remaining, InternalRun ge remaining other (.Returnstate .Vundef .Kstop after)) ∧
      (∀ t other, CC.Star (CC.Step2 ge)
        (.Callstate (.Internal Arm64Nop.handler)
          (Dispatch.Keep.arguments (operands unused entry.block 31 imm column) narrow) .Kstop before) t other →
        (∀ u next, ¬ CC.Step2 ge other u next) →
        t = CC.E0 ∧ other = .Returnstate .Vundef .Kstop after) ∧
      ¬ (∃ states : Nat → CC.State,
        states 0 = .Callstate (.Internal Arm64Nop.handler)
          (Dispatch.Keep.arguments (operands unused entry.block 31 imm column) narrow) .Kstop before ∧
        ∀ i, ∃ t, CC.Step2 ge (states i) t (states (i + 1))) := by
  obtain ⟨after, run, rep⟩ := call_zr_represents storage unused imm column narrow addresses origins s represented
  have stuck := return_stuck .Vundef after
  exact ⟨after, run, rep, fun _ _ observed => run.finish_prefix stuck observed,
    fun _ _ observed otherStuck => run.endpoint_unique stuck observed otherStuck,
    run.no_infinite stuck⟩

end KProgFormal.ClightRefinement.Arm64MovKeep
