import KProgFormal.ClightRefinement.Arm64MovImmediateSuffix
import KProgFormal.ClightRefinement.Arm64RegisterStorageFrame

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MovImmediate

open Arm64NumericProgram

/-- Bind the actual MOV_IMM operands; source2/source3/aux retain arbitrary
incoming Clight values. NONE is the real eager-read selector, not a skipped read. -/
def operands (unused : Arm64Nop.IgnoredArguments) (entry : CC.Block) (i : Fin 31)
    (value : BitVec 64) : Arm64Nop.IgnoredArguments :=
  ⟨.Vptr entry 0, .Vlong (BitVec.ofNat 64 i.val), .Vlong 255,
    unused.src2, unused.src3, unused.aux, .Vlong value⟩

private theorem temp_data (unused : Arm64Nop.IgnoredArguments) (entry : CC.Block)
    (i : Fin 31) (value : BitVec 64) (narrow : Bool) :
    let le := Dispatch.scalarEnv (Dispatch.initialTemps (operands unused entry i value) narrow) narrow
    le.get Arm64Program._entry = some (.Vptr entry 0) ∧
    le.get Arm64Program._src = some (.Vlong 255) ∧
    le.get Arm64Program._dst = some (.Vlong (BitVec.ofNat 64 i.val)) ∧
    le.get Arm64Program._op = some (.Vint 1) ∧
    le.get Arm64Program._imm = some (.Vlong value) ∧
    le.get Arm64Program.___a64_l_width = some (Arm64RegisterWrite.width narrow) := by
  cases narrow <;> simp +decide [Dispatch.scalarEnv, Dispatch.dispatchEnv, Dispatch.initialTemps,
    operands, Arm64Nop.resultEnv, Dispatch.flags, Arm64Width.result, Arm64Width.argument,
    Arm64RegisterWrite.width, CC.PTree.gss, CC.PTree.gso]

/-- The actual no-cell destination selector; SP is the separate selector 32. -/
def zrOperands (unused : Arm64Nop.IgnoredArguments) (entry : CC.Block)
    (value : BitVec 64) : Arm64Nop.IgnoredArguments :=
  ⟨.Vptr entry 0, .Vlong 31, .Vlong 255,
    unused.src2, unused.src3, unused.aux, .Vlong value⟩

private theorem zr_temp_data (unused : Arm64Nop.IgnoredArguments) (entry : CC.Block)
    (value : BitVec 64) (narrow : Bool) :
    let le := Dispatch.scalarEnv (Dispatch.initialTemps (zrOperands unused entry value) narrow) narrow
    le.get Arm64Program._entry = some (.Vptr entry 0) ∧
    le.get Arm64Program._src = some (.Vlong 255) ∧
    le.get Arm64Program._dst = some (.Vlong 31) ∧
    le.get Arm64Program._op = some (.Vint 1) ∧
    le.get Arm64Program._imm = some (.Vlong value) ∧
    le.get Arm64Program.___a64_l_width = some (Arm64RegisterWrite.width narrow) := by
  cases narrow <;> simp +decide [Dispatch.scalarEnv, Dispatch.dispatchEnv, Dispatch.initialTemps,
    zrOperands, Arm64Nop.resultEnv, Dispatch.flags, Arm64Width.result, Arm64Width.argument,
    Arm64RegisterWrite.width, CC.PTree.gss, CC.PTree.gso]

private theorem callees_not_local :
    Arm64Program._kprog_arm64_program_read ∉ CC.varNames Arm64Nop.handler.fn_vars ∧
    Arm64Program._kprog_arm64_program_write ∉ CC.varNames Arm64Nop.handler.fn_vars := by decide +kernel

theorem allocated_bound (world : CC.CGenv) (before : CC.Mem) :
    CC.AllocVariables world.genv_cenv CC.emptyEnv before Arm64Nop.handler.fn_vars
      (Arm64Nop.allocation world before).1 (Arm64Nop.allocation world before).2 :=
  CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (Arm64Nop.allocation world before)).symm

theorem allocated (before : CC.Mem) :
    CC.AllocVariables ge.genv_cenv CC.emptyEnv before Arm64Nop.handler.fn_vars
      (Arm64Nop.allocation ge before).1 (Arm64Nop.allocation ge before).2 := allocated_bound ge before

theorem unshadowed_bound (world : CC.CGenv) (before : CC.Mem) :
    (Arm64Nop.allocation world before).1.get Arm64Program._kprog_arm64_program_read = none ∧
    (Arm64Nop.allocation world before).1.get Arm64Program._kprog_arm64_program_write = none := by
  constructor
  · simpa only [CC.emptyEnv, CC.PTree.gempty] using
      CC.allocVariables_env_other (allocated_bound world before) callees_not_local.1
  · simpa only [CC.emptyEnv, CC.PTree.gempty] using
      CC.allocVariables_env_other (allocated_bound world before) callees_not_local.2

theorem unshadowed (before : CC.Mem) :
    (Arm64Nop.allocation ge before).1.get Arm64Program._kprog_arm64_program_read = none ∧
    (Arm64Nop.allocation ge before).1.get Arm64Program._kprog_arm64_program_write = none := unshadowed_bound ge before

/-- Complete actual nine-argument generic procedure, including both scalar
stores and freeing its real locals. The writer result refers to the SAME
producer cells, carried through actual allocation, and the final free frames
all pre-call blocks relative to the already-written memory. -/
theorem call_returns {m before : CC.Mem} {entry : Arm64Producer.HeaderLocal m}
    (storage : Arm64ProducerRegisterStorage.Storage m before entry)
    (unused : Arm64Nop.IgnoredArguments) (i : Fin 31) (value : BitVec 64) (narrow : Bool) :
    ∃ written after,
      Arm64RegisterWrite.Result (storage.frame (Arm64Nop.entry_frame ge before)) i value narrow written ∧
      InternalRun ge 203
        (.Callstate (.Internal Arm64Nop.handler)
          (Dispatch.arguments (operands unused entry.block i value) narrow) .Kstop before)
        (.Returnstate .Vundef .Kstop after) ∧
      CC.Mem.freeList written (CC.blocksOfEnv ge.genv_cenv (Arm64Nop.allocation ge before).1) = some after ∧
      FrameBelow before.nextblock written after ∧
      after.contents = written.contents ∧ after.nextblock = written.nextblock ∧
      (∀ row ∈ CC.blocksOfEnv ge.genv_cenv (Arm64Nop.allocation ge before).1,
        ∀ ofs, row.2.1 ≤ ofs → ofs < row.2.2 →
          ∀ kind permission, CC.Mem.perm after row.1 ofs kind permission = false) := by
  let carried := storage.frame (Arm64Nop.entry_frame ge before)
  let le := Dispatch.scalarEnv (Dispatch.initialTemps (operands unused entry.block i value) narrow) narrow
  have inputs := temp_data unused entry.block i value narrow
  have names := unshadowed before
  obtain ⟨written, result, body⟩ := Suffix.scalar_write carried (Arm64Nop.allocation ge before).1 le
    i value narrow names.1 names.2 inputs.1 inputs.2.1 inputs.2.2.1 inputs.2.2.2.1
    inputs.2.2.2.2.1 inputs.2.2.2.2.2
  have owned : ∀ id v, (Arm64Nop.allocation ge before).1.get id = some v →
      CC.Mem.rangePerm written v.1 0 (CC.sizeof ge.genv_cenv v.2) .Cur .Freeable = true := by
    intro id v binding
    have live := ((allocated_local_storage (allocated before)).1 id v binding).2.2
    exact (CC.Mem.rangePerm_congr (m1 := written) (m2 := (Arm64Nop.allocation ge before).2)
      (fun offset => by simp only [CC.Mem.perm, result.access])).trans live
  obtain ⟨after, freed, frame, contents, next, released⟩ := deallocate_live_locals (allocated before) owned
  have dispatch := (Dispatch.call_dispatch before (operands unused entry.block i value) narrow).1
  have leave : InternalRun ge 1
      (.State Arm64Nop.handler .Sskip .Kstop (Arm64Nop.allocation ge before).1
        (Suffix.writerTemps le value) written) (.Returnstate .Vundef .Kstop after) :=
    .step trivial (.skip_call _ _ _ _ _ _ rfl freed) (.refl _)
  exact ⟨written, after, result, (dispatch.trans body).trans leave, freed, frame, contents, next, released⟩

/-- All 174 actual generic-handler transitions for XZR, including real
allocation, NONE read, the no-cell writer, and freeing every generic local.
Only fresh allocation blocks change; the original caller frontier is framed. -/
theorem call_zr_returns {m before : CC.Mem} {entry : Arm64Producer.HeaderLocal m}
    (storage : Arm64ProducerRegisterStorage.Storage m before entry)
    (unused : Arm64Nop.IgnoredArguments) (value : BitVec 64) (narrow : Bool) :
    ∃ after, InternalRun ge 174
      (.Callstate (.Internal Arm64Nop.handler)
        (Dispatch.arguments (zrOperands unused entry.block value) narrow) .Kstop before)
      (.Returnstate .Vundef .Kstop after) ∧
      CC.Mem.freeList (Arm64Nop.allocation ge before).2
        (CC.blocksOfEnv ge.genv_cenv (Arm64Nop.allocation ge before).1) = some after ∧
      FrameBelow before.nextblock before after ∧
      (∀ row ∈ CC.blocksOfEnv ge.genv_cenv (Arm64Nop.allocation ge before).1,
        ∀ ofs, row.2.1 ≤ ofs → ofs < row.2.2 →
          ∀ kind permission, CC.Mem.perm after row.1 ofs kind permission = false) := by
  let carried := storage.frame (Arm64Nop.entry_frame ge before)
  let le := Dispatch.scalarEnv (Dispatch.initialTemps (zrOperands unused entry.block value) narrow) narrow
  have inputs := zr_temp_data unused entry.block value narrow
  have names := unshadowed before
  have body := Suffix.scalar_zr carried (Arm64Nop.allocation ge before).1 le
    value narrow names.1 names.2 inputs.1 inputs.2.1 inputs.2.2.1 inputs.2.2.2.1
    inputs.2.2.2.2.1 inputs.2.2.2.2.2
  have owned : ∀ id v, (Arm64Nop.allocation ge before).1.get id = some v →
      CC.Mem.rangePerm (Arm64Nop.allocation ge before).2 v.1 0 (CC.sizeof ge.genv_cenv v.2) .Cur .Freeable = true := by
    intro id v binding
    exact ((allocated_local_storage (allocated before)).1 id v binding).2.2
  obtain ⟨after, freed, frame, _, _, released⟩ := deallocate_live_locals (allocated before) owned
  have dispatch := (Dispatch.call_dispatch before (zrOperands unused entry.block value) narrow).1
  have leave : InternalRun ge 1
      (.State Arm64Nop.handler .Sskip .Kstop (Arm64Nop.allocation ge before).1
        (Suffix.writerTemps le value) (Arm64Nop.allocation ge before).2)
      (.Returnstate .Vundef .Kstop after) :=
    .step trivial (.skip_call _ _ _ _ _ _ rfl freed) (.refl _)
  exact ⟨after, (dispatch.trans body).trans leave, freed,
    (Arm64Nop.entry_frame ge before).trans frame, released⟩

end KProgFormal.ClightRefinement.Arm64MovImmediate
