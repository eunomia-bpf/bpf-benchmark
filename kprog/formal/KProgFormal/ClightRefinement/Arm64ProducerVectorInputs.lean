import KProgFormal.ClightRefinement.Arm64EntryAdmissibility

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProducerVectorInputs

open Arm64Producer

/-- Required outcomes of the actual kind-6 external at each visited memory.
The post-memory is retained, not equated to its input. Caller bytes, local
readbacks and permissions needed by this source segment are explicit frame
obligations. This does not establish availability of a runtime provider. -/
def ProviderAt (world : CC.CGenv) (m : CC.Mem) (values : Fin 64 → BitVec 64) : Prop :=
  ∀ (i : Fin 64) (before : CC.Mem), before.access = (allocation m).2.access →
    ∃ trace supplied,
      CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv world.genv_genv)
        [.Vint (6#32)] before trace (.Vlong (values i)) supplied ∧
      supplied.access = before.access ∧ supplied.nextblock = before.nextblock ∧
      FrameBelow m.nextblock before supplied ∧
      ∀ id ty block, (allocation m).1.get id = some (block, ty) →
        ∀ chunk ofs, CC.Mem.load chunk supplied block ofs = CC.Mem.load chunk before block ofs

def Provider (m : CC.Mem) (values : Fin 64 → BitVec 64) : Prop :=
  ProviderAt ge m values

/-- Shared 64-visit induction with actual function, environment, stages and temps. -/
theorem run_suffix_body (world : CC.CGenv) (f : CC.Function) (e : CC.Env)
    (atStage : Nat → CC.Stmt) (inputTemp : Fin 64 → CC.Ident)
    (m : CC.Mem) (localVector : VectorLocal m)
    (values : Fin 64 → BitVec 64) (provider : ProviderAt world m values)
    (runInput : ∀ (i : Fin 64) (before supplied : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) (trace : CC.Trace),
      CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv world.genv_genv)
        [.Vint (6#32)] before trace (.Vlong (values i)) supplied →
      supplied.access = (allocation m).2.access →
      ∃ chosen : VectorLocal m, ∃ after,
        CC.Star (CC.Step2 world) (.State f (atStage i.val) k e le before)
          trace (.State f (atStage (i.val + 1)) k e (le.set (inputTemp i) (.Vlong (values i))) after) ∧
        CC.Mem.load .Mint64 after chosen.block (8 * (i.val : Int)) = some (.Vlong (values i)) ∧
        (∀ j : Fin 64, j ≠ i → CC.Mem.load .Mint64 after chosen.block (8 * (j.val : Int)) =
          CC.Mem.load .Mint64 supplied chosen.block (8 * (j.val : Int))) ∧
        (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ Arm64Entry.___a64_vectors →
          ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk supplied block ofs) ∧
        FrameBelow m.nextblock supplied after ∧ after.access = supplied.access ∧
        after.nextblock = supplied.nextblock)
    (count : Nat) :
    ∀ start, start + count = 64 → ∀ (before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont),
    before.access = (allocation m).2.access →
    ∃ after finalLe, ∃ traces : List CC.Trace, traces.length = count ∧
      CC.Star (CC.Step2 world)
        (.State f (atStage start) k e le before)
        traces.flatten (.State f (atStage 64) k e finalLe after) ∧
      (∀ j : Fin 64, start ≤ j.val →
        CC.Mem.load .Mint64 after localVector.block (8 * (j.val : Int)) = some (.Vlong (values j))) ∧
      (∀ j : Fin 64, j.val < start →
        CC.Mem.load .Mint64 after localVector.block (8 * (j.val : Int)) =
          CC.Mem.load .Mint64 before localVector.block (8 * (j.val : Int))) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ Arm64Entry.___a64_vectors →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      (∀ id, (∀ i : Fin 64, id ≠ inputTemp i) → finalLe.get id = le.get id) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  induction count with
  | zero =>
    intro start bound before le k access
    have same : start = 64 := by omega
    subst start
    refine ⟨before, le, [], rfl, .refl _, ?_, ?_, ?_, ?_, FrameBelow.refl _ _, rfl, rfl⟩
    · intro j lower; have := j.isLt; omega
    · intro j upper; rfl
    · intro id ty block binding different chunk ofs; rfl
    · intro id different; rfl
  | succ count ih =>
    intro start bound before le k access
    let i : Fin 64 := ⟨start, by omega⟩
    obtain ⟨trace, supplied, call, providerAccess, providerNext, providerFrame, providerLocals⟩ :=
      provider i before access
    obtain ⟨chosen, middle, headRun, headRead, headWords, headLocals, headFrame, headAccess, headNext⟩ :=
      runInput i before supplied le k trace call (providerAccess.trans access)
    have sameBlock : chosen.block = localVector.block :=
      congrArg Prod.fst (Option.some.inj (chosen.binding.symm.trans localVector.binding))
    rw [sameBlock] at headRead headWords
    obtain ⟨after, finalLe, traces, length, tailRun, tailReads, tailWords, tailLocals,
        tailTemps, tailFrame, tailAccess, tailNext⟩ :=
      ih (start + 1) (by omega) middle (le.set (inputTemp i) (.Vlong (values i))) k
        (headAccess.trans (providerAccess.trans access))
    refine ⟨after, finalLe, trace :: traces, by simp [length], ?_, ?_, ?_, ?_, ?_,
      (providerFrame.trans headFrame).trans tailFrame,
      tailAccess.trans (headAccess.trans providerAccess),
      tailNext.trans (headNext.trans providerNext)⟩
    · simpa only [List.flatten_cons, CC.Eapp] using star_trans headRun tailRun
    · intro j lower
      by_cases same : j = i
      · subst j
        exact (tailWords i (by dsimp [i]; omega)).trans headRead
      · apply tailReads j
        have different : j.val ≠ start := fun equal => same (Fin.ext equal)
        omega
    · intro j upper
      have different : j ≠ i := by intro equal; subst j; dsimp [i] at upper; omega
      exact (tailWords j (by omega)).trans ((headWords j different).trans
        (providerLocals _ _ _ localVector.binding .Mint64 (8 * (j.val : Int))))
    · intro id ty block binding different chunk ofs
      exact (tailLocals id ty block binding different chunk ofs).trans
        ((headLocals id ty block binding different chunk ofs).trans
          (providerLocals id ty block binding chunk ofs))
    · intro id different
      exact (tailTemps id different).trans (CC.PTree.gso _ _ _ _ (Ne.symm (different i)))

private theorem run_suffix (world : CC.CGenv)
    (layout : world.genv_cenv = ge.genv_cenv)
    (inputBinding : CC.Genv.findSymbol world.genv_genv Arm64Entry._native_lab_entry_input =
        some (CC.Positive.ofNat 64) ∧
      CC.Genv.findFunctPtr world.genv_genv (CC.Positive.ofNat 64) = some Arm64OriginCache.inputFunction) (m : CC.Mem) (localVector : VectorLocal m)
    (values : Fin 64 → BitVec 64) (provider : ProviderAt world m values) (count : Nat) :
    ∀ start, start + count = 64 → ∀ (before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont),
    before.access = (allocation m).2.access →
    ∃ after finalLe, ∃ traces : List CC.Trace, traces.length = count ∧
      CC.Star (CC.Step2 world)
        (.State producer (vectorStage start) k (allocation m).1 le before)
        traces.flatten (.State producer (vectorStage 64) k (allocation m).1 finalLe after) ∧
      (∀ j : Fin 64, start ≤ j.val →
        CC.Mem.load .Mint64 after localVector.block (8 * (j.val : Int)) = some (.Vlong (values j))) ∧
      (∀ j : Fin 64, j.val < start →
        CC.Mem.load .Mint64 after localVector.block (8 * (j.val : Int)) =
          CC.Mem.load .Mint64 before localVector.block (8 * (j.val : Int))) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ Arm64Entry.___a64_vectors →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      (∀ id, (∀ i : Fin 64, id ≠ vectorInputTemp i) → finalLe.get id = le.get id) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  exact run_suffix_body world producer (allocation m).1 vectorStage vectorInputTemp m localVector values provider
    (fun i before supplied le k trace call access =>
      vector_input_returns_bound world layout inputBinding i m before supplied le k (values i) trace call access) count

/-- All 64 real source visits, with one trace per call in source order.
Earlier local reads and caller memory survive each explicitly framed provider
outcome; all vector words are derived from the corresponding returned values. -/
theorem vector_inputs_initialized_bound (world : CC.CGenv)
    (layout : world.genv_cenv = ge.genv_cenv)
    (inputBinding : CC.Genv.findSymbol world.genv_genv Arm64Entry._native_lab_entry_input =
        some (CC.Positive.ofNat 64) ∧
      CC.Genv.findFunctPtr world.genv_genv (CC.Positive.ofNat 64) = some Arm64OriginCache.inputFunction) (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (values : Fin 64 → BitVec 64) (provider : ProviderAt world m values)
    (access : before.access = (allocation m).2.access) :
    ∃ localVector : VectorLocal m, ∃ after finalLe, ∃ traces : List CC.Trace, traces.length = 64 ∧
      CC.Star (CC.Step2 world)
        (.State producer vectorStart k (allocation m).1 le before)
        traces.flatten (.State producer afterVectorInputs k (allocation m).1 finalLe after) ∧
      (∀ i : Fin 64, CC.Mem.load .Mint64 after localVector.block (8 * (i.val : Int)) =
        some (.Vlong (values i))) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ Arm64Entry.___a64_vectors →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      (∀ id, (∀ i : Fin 64, id ≠ vectorInputTemp i) → finalLe.get id = le.get id) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  obtain ⟨localVector⟩ := vector_local m
  obtain ⟨after, finalLe, traces, length, run, reads, _, locals, temps, frame, finalAccess, next⟩ :=
    run_suffix world layout inputBinding m localVector values provider 64 0 rfl before le k access
  refine ⟨localVector, after, finalLe, traces, length, ?_, (fun i => reads i (Nat.zero_le _)),
    locals, temps, frame, finalAccess, next⟩
  simpa only [first_vector_stage, final_vector_stage] using run

theorem vector_inputs_initialized (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (values : Fin 64 → BitVec 64) (provider : Provider m values)
    (access : before.access = (allocation m).2.access) :
    ∃ localVector : VectorLocal m, ∃ after finalLe, ∃ traces : List CC.Trace, traces.length = 64 ∧
      CC.Star (CC.Step2 ge)
        (.State producer vectorStart k (allocation m).1 le before)
        traces.flatten (.State producer afterVectorInputs k (allocation m).1 finalLe after) ∧
      (∀ i : Fin 64, CC.Mem.load .Mint64 after localVector.block (8 * (i.val : Int)) =
        some (.Vlong (values i))) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ Arm64Entry.___a64_vectors →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      (∀ id, (∀ i : Fin 64, id ≠ vectorInputTemp i) → finalLe.get id = le.get id) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock :=
  vector_inputs_initialized_bound ge rfl producer_input_binding m before le k values provider access

/-- Native vector halves in the actual alternating low/high input order. -/
def nativeVectorWord (s : Reference.AArch64.State) (i : Fin 64) : BitVec 64 :=
  Arm64ProducerVectorView.vectorHalf s (i.val % 2 == 1) ⟨i.val / 2, by have := i.isLt; omega⟩

private def halfIndex (high : Bool) (lane : Fin 32) : Fin 64 :=
  ⟨2 * lane.val + (if high then 1 else 0), by have := lane.isLt; split <;> omega⟩

private theorem half_coordinates : ∀ high (lane : Fin 32),
    (halfIndex high lane).val / 2 = lane.val ∧
    ((halfIndex high lane).val % 2 == 1) = high ∧
    8 * ((halfIndex high lane).val : Int) = 16 * (lane.val : Int) + (if high then 8 else 0) := by
  decide +kernel

private theorem native_half (s : Reference.AArch64.State) (high : Bool) (lane : Fin 32) :
    nativeVectorWord s (halfIndex high lane) = Arm64ProducerVectorView.vectorHalf s high lane := by
  have index : (⟨(halfIndex high lane).val / 2, by have := (halfIndex high lane).isLt; omega⟩ : Fin 32) =
      lane := Fin.ext (half_coordinates high lane).1
  unfold nativeVectorWord
  rw [index, (half_coordinates high lane).2.1]

/-- The vector data premise of the RAW register proof now follows from all64
actual external visits. Provider traces/post-memories and source frame
obligations stay explicit; no fixed outcome or host fixture is substituted. -/
theorem vector_inputs_and_raw_registers_with_storage
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (ctx : CC.Val) (ctxWord : BitVec 64) (represented : Arm64Registers.ValueRep addresses ctx ctxWord)
    (m before : CC.Mem) (le : CC.TempEnv) (input : le.get Arm64Entry._ctx = some ctx)
    (k : CC.Cont) (s : Reference.AArch64.State) (inputs : Fin 31 → BitVec 64)
    (access : before.access = (allocation m).2.access)
    (provider : Provider m (nativeVectorWord s))
    (tablesBefore : ∀ tags, ∃ table : TableLocals tags m, ∀ i,
      CC.Mem.load CC.Mptr before table.tableBlock (8 * (i.val : Int)) = some (.Vptr (table.cellBlock i) 0))
    (wordsBefore : ∀ (i : Fin 31), i ≠ 0 → ∀ block : CC.Block,
      (allocation m).1.get (tableCellName false i) = some (block, tableCellType false) →
      CC.Mem.load .Mint64 before block 0 = some (.Vlong (if i = 30 then 0 else inputs i)))
    (tagsBefore : ∀ (i : Fin 31), i ≠ 0 → i ≠ 30 → ∀ block : CC.Block,
      (allocation m).1.get (tableCellName true i) = some (block, tableCellType true) →
      CC.Mem.load .Mint8unsigned before block 0 = some (.Vint 0))
    (flagsBefore : ∀ (i : Fin 4) (block : CC.Block),
      (allocation m).1.get (headerSourceName (Arm64ProducerEntryView.flagIndex i)) =
        some (block, headerSourceType (Arm64ProducerEntryView.flagIndex i)) →
      CC.Mem.load .Mint8unsigned before block 0 = some (Arm64ProducerEntryView.flagValues s i))
    (nativeContext : Reference.AArch64.gpr s 0 = ctxWord)
    (nativeReturn : Reference.AArch64.gpr s 30 = origins.returnAddress)
    (nativeOther : ∀ i : Fin 31, i ≠ 0 → i ≠ 30 → Reference.AArch64.gpr s i = inputs i)
    (nativeSp : Reference.AArch64.sp s = origins.stack) :
    ∃ entry : HeaderLocal m, ∃ after finalLe, ∃ traces : List CC.Trace, traces.length = 64 ∧
      CC.Star (CC.Step2 ge) (.State producer vectorStart k (allocation m).1 le before)
        traces.flatten (.State producer afterVectorLoop k (allocation m).1 finalLe after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val)
        after.nextblock after (.Vptr entry.block 0) s ∧
      Nonempty (Arm64ProducerRegisterStorage.Storage m after entry) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  obtain ⟨localVector, middle, vectorLe, traces, length, vectorRun, vectorReads,
      locals, temps, vectorFrame, vectorAccess, vectorNext⟩ :=
    vector_inputs_initialized m before le k (nativeVectorWord s) provider access
  have ctxSeparate : ∀ i : Fin 64, Arm64Entry._ctx ≠ vectorInputTemp i := by decide +kernel
  have vectorInput : vectorLe.get Arm64Entry._ctx = some ctx := (temps _ ctxSeparate).trans input
  have tables : ∀ tags, ∃ table : TableLocals tags m, ∀ i,
      CC.Mem.load CC.Mptr middle table.tableBlock (8 * (i.val : Int)) = some (.Vptr (table.cellBlock i) 0) := by
    intro tags
    obtain ⟨table, reads⟩ := tablesBefore tags
    have different : ∀ tags, tableName tags ≠ Arm64Entry.___a64_vectors := by decide +kernel
    refine ⟨table, ?_⟩
    intro i
    rw [locals _ _ _ table.binding (different tags) CC.Mptr (8 * (i.val : Int))]
    exact reads i
  have words : ∀ (i : Fin 31), i ≠ 0 → ∀ block : CC.Block,
      (allocation m).1.get (tableCellName false i) = some (block, tableCellType false) →
      CC.Mem.load .Mint64 middle block 0 = some (.Vlong (if i = 30 then 0 else inputs i)) := by
    intro i zero block bound
    have different : ∀ i : Fin 31, tableCellName false i ≠ Arm64Entry.___a64_vectors := by decide +kernel
    rw [locals _ _ _ bound (different i) .Mint64 0]
    exact wordsBefore i zero block bound
  have tags : ∀ (i : Fin 31), i ≠ 0 → i ≠ 30 → ∀ block : CC.Block,
      (allocation m).1.get (tableCellName true i) = some (block, tableCellType true) →
      CC.Mem.load .Mint8unsigned middle block 0 = some (.Vint 0) := by
    intro i zero lr block bound
    have different : ∀ i : Fin 31, tableCellName true i ≠ Arm64Entry.___a64_vectors := by decide +kernel
    rw [locals _ _ _ bound (different i) .Mint8unsigned 0]
    exact tagsBefore i zero lr block bound
  have flags : ∀ (i : Fin 4) (block : CC.Block),
      (allocation m).1.get (headerSourceName (Arm64ProducerEntryView.flagIndex i)) =
        some (block, headerSourceType (Arm64ProducerEntryView.flagIndex i)) →
      CC.Mem.load .Mint8unsigned middle block 0 = some (Arm64ProducerEntryView.flagValues s i) := by
    intro i block bound
    have different : ∀ i : Fin 4,
        headerSourceName (Arm64ProducerEntryView.flagIndex i) ≠ Arm64Entry.___a64_vectors := by decide +kernel
    rw [locals _ _ _ bound (different i) .Mint8unsigned 0]
    exact flagsBefore i block bound
  have vectors : ∀ block : CC.Block,
      (allocation m).1.get Arm64Entry.___a64_vectors = some (block, vectorArrayType) →
      ∀ high i, CC.Mem.load .Mint64 middle block (16 * (i.val : Int) + (if high then 8 else 0)) =
        some (.Vlong (Arm64ProducerVectorView.vectorHalf s high i)) := by
    intro block bound high i
    have same : block = localVector.block := congrArg Prod.fst (Option.some.inj (bound.symm.trans localVector.binding))
    subst block
    have read := vectorReads (halfIndex high i)
    rw [(half_coordinates high i).2.2, native_half] at read
    exact read
  obtain ⟨entry, after, finalLe, rawRun, registers, storage, rawFrame, rawAccess, rawNext⟩ :=
    Arm64EntryAdmissibility.raw_registers_initialized_with_storage addresses origins ctx ctxWord represented
      m middle vectorLe vectorInput k s inputs (vectorAccess.trans access) tables words tags flags vectors
      nativeContext nativeReturn nativeOther nativeSp
  refine ⟨entry, after, finalLe, traces, length, ?_, registers, storage, vectorFrame.trans rawFrame,
    rawAccess.trans vectorAccess, rawNext.trans vectorNext⟩
  simpa only [CC.E0, CC.Eapp, List.append_nil] using star_trans vectorRun rawRun.sound

/-- Observer projection of the same resource-carrying source execution. -/
theorem vector_inputs_and_raw_registers
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (ctx : CC.Val) (ctxWord : BitVec 64) (represented : Arm64Registers.ValueRep addresses ctx ctxWord)
    (m before : CC.Mem) (le : CC.TempEnv) (input : le.get Arm64Entry._ctx = some ctx)
    (k : CC.Cont) (s : Reference.AArch64.State) (inputs : Fin 31 → BitVec 64)
    (access : before.access = (allocation m).2.access)
    (provider : Provider m (nativeVectorWord s))
    (tablesBefore : ∀ tags, ∃ table : TableLocals tags m, ∀ i,
      CC.Mem.load CC.Mptr before table.tableBlock (8 * (i.val : Int)) = some (.Vptr (table.cellBlock i) 0))
    (wordsBefore : ∀ (i : Fin 31), i ≠ 0 → ∀ block : CC.Block,
      (allocation m).1.get (tableCellName false i) = some (block, tableCellType false) →
      CC.Mem.load .Mint64 before block 0 = some (.Vlong (if i = 30 then 0 else inputs i)))
    (tagsBefore : ∀ (i : Fin 31), i ≠ 0 → i ≠ 30 → ∀ block : CC.Block,
      (allocation m).1.get (tableCellName true i) = some (block, tableCellType true) →
      CC.Mem.load .Mint8unsigned before block 0 = some (.Vint 0))
    (flagsBefore : ∀ (i : Fin 4) (block : CC.Block),
      (allocation m).1.get (headerSourceName (Arm64ProducerEntryView.flagIndex i)) =
        some (block, headerSourceType (Arm64ProducerEntryView.flagIndex i)) →
      CC.Mem.load .Mint8unsigned before block 0 = some (Arm64ProducerEntryView.flagValues s i))
    (nativeContext : Reference.AArch64.gpr s 0 = ctxWord)
    (nativeReturn : Reference.AArch64.gpr s 30 = origins.returnAddress)
    (nativeOther : ∀ i : Fin 31, i ≠ 0 → i ≠ 30 → Reference.AArch64.gpr s i = inputs i)
    (nativeSp : Reference.AArch64.sp s = origins.stack) :
    ∃ entry : HeaderLocal m, ∃ after finalLe, ∃ traces : List CC.Trace, traces.length = 64 ∧
      CC.Star (CC.Step2 ge) (.State producer vectorStart k (allocation m).1 le before)
        traces.flatten (.State producer afterVectorLoop k (allocation m).1 finalLe after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val)
        after.nextblock after (.Vptr entry.block 0) s ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  obtain ⟨entry, after, finalLe, traces, length, run, registers, _, frame, access, next⟩ :=
    vector_inputs_and_raw_registers_with_storage addresses origins ctx ctxWord represented m before le input k s inputs access provider tablesBefore wordsBefore tagsBefore flagsBefore nativeContext nativeReturn nativeOther nativeSp
  exact ⟨entry, after, finalLe, traces, length, run, registers, frame, access, next⟩

end KProgFormal.ClightRefinement.Arm64ProducerVectorInputs
