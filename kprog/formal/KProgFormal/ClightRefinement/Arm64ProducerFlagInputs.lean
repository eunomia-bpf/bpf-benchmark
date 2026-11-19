import KProgFormal.ClightRefinement.Arm64ProducerVectorInputs

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProducerFlagInputs

open Arm64Producer

/-- Required kind-6 outcomes at each actual flag visit, retaining the complete
returned word and supplied memory. Availability and frame obligations belong
to the invocation environment; no fixed full-word outcome is selected here. -/
def ProviderAt (world : CC.CGenv) (m : CC.Mem) (values : Fin 4 → BitVec 64) : Prop :=
  ∀ (i : Fin 4) (before : CC.Mem), before.access = (allocation m).2.access →
    ∃ trace supplied,
      CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv world.genv_genv)
        [.Vint (6#32)] before trace (.Vlong (values i)) supplied ∧
      supplied.access = before.access ∧ supplied.nextblock = before.nextblock ∧
      FrameBelow m.nextblock before supplied ∧
      ∀ id ty block, (allocation m).1.get id = some (block, ty) →
        ∀ chunk ofs, CC.Mem.load chunk supplied block ofs = CC.Mem.load chunk before block ofs

def Provider (m : CC.Mem) (values : Fin 4 → BitVec 64) : Prop :=
  ProviderAt ge m values

private def stage (n : Nat) : CC.Stmt :=
  if h : n < 4 then flagDeclarationStage ⟨n, h⟩ else (flagDeclaration 3).rest

private theorem next_stage : ∀ i : Fin 4, (flagDeclaration i).rest = stage (i.val + 1) := by
  simp only [Fin.forall_fin_succ, Fin.forall_fin_zero]
  repeat' apply And.intro
  all_goals first | rfl | trivial

private theorem names_distinct : ∀ i j : Fin 4, i ≠ j →
    (flagDeclaration i).name ≠ (flagDeclaration j).name := by decide +kernel

/-- Shared four-visit induction with an actual declaration/stage family.
Provider traces, earlier flags and local/temporary/caller frames are retained. -/
theorem run_suffix_body (world : CC.CGenv) (f : CC.Function) (e : CC.Env)
    (decl : Fin 4 → FlagDeclaration) (atStage : Nat → CC.Stmt)
    (sameNames : ∀ i, (decl i).name = (flagDeclaration i).name)
    (next_stage : ∀ i, (decl i).rest = atStage (i.val + 1))
    (m : CC.Mem) (blocks : Fin 4 → CC.Block)
    (bindings : ∀ i, (allocation m).1.get (decl i).name = some (blocks i, CC.tuchar))
    (values : Fin 4 → BitVec 64) (provider : ProviderAt world m values)
    (runInput : ∀ (i : Fin 4) (before supplied : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) (trace : CC.Trace),
      CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv world.genv_genv)
        [.Vint (6#32)] before trace (.Vlong (values i)) supplied →
      supplied.access = (allocation m).2.access →
      ∃ block after, (allocation m).1.get (decl i).name = some (block, CC.tuchar) ∧
        CC.Star (CC.Step2 world) (.State f (atStage i.val) k e le before)
          trace (.State f (decl i).rest k e (le.set (decl i).inputTemp (.Vlong (values i))) after) ∧
        CC.Mem.loadv .Mint8unsigned after (.Vptr block 0) = some (.Vint (flagWord (values i))) ∧
        (flagWord (values i) = (0#32) ∨ flagWord (values i) = (1#32)) ∧
        (∀ id ty other, (allocation m).1.get id = some (other, ty) → id ≠ (decl i).name →
          ∀ chunk ofs, CC.Mem.load chunk after other ofs = CC.Mem.load chunk supplied other ofs) ∧
        FrameBelow m.nextblock supplied after ∧ after.access = supplied.access ∧
        after.nextblock = supplied.nextblock)
    (count : Nat) :
    ∀ start, start + count = 4 → ∀ (before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont),
    before.access = (allocation m).2.access →
    ∃ after finalLe, ∃ traces : List CC.Trace, traces.length = count ∧
      CC.Star (CC.Step2 world) (.State f (atStage start) k e le before)
        traces.flatten (.State f (atStage 4) k e finalLe after) ∧
      (∀ j : Fin 4, start ≤ j.val → CC.Mem.load .Mint8unsigned after (blocks j) 0 =
        some (.Vint (flagWord (values j)))) ∧
      (∀ j : Fin 4, j.val < start → CC.Mem.load .Mint8unsigned after (blocks j) 0 =
        CC.Mem.load .Mint8unsigned before (blocks j) 0) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) →
        (∀ i : Fin 4, id ≠ (decl i).name) → ∀ chunk ofs,
        CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      (∀ id, (∀ i : Fin 4, id ≠ (decl i).inputTemp) → finalLe.get id = le.get id) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  have separated : ∀ i j : Fin 4, i ≠ j → (decl i).name ≠ (decl j).name := by
    intro i j different
    rw [sameNames i, sameNames j]
    exact names_distinct i j different
  induction count with
  | zero =>
    intro start bound before le k access
    have same : start = 4 := by omega
    subst start
    refine ⟨before, le, [], rfl, .refl _, ?_, ?_, ?_, ?_, FrameBelow.refl _ _, rfl, rfl⟩
    · intro j lower; have := j.isLt; omega
    · intro j upper; rfl
    · intro id ty block binding different chunk ofs; rfl
    · intro id different; rfl
  | succ count ih =>
    intro start bound before le k access
    let i : Fin 4 := ⟨start, by omega⟩
    obtain ⟨trace, supplied, call, providerAccess, providerNext, providerFrame, providerLocals⟩ :=
      provider i before access
    obtain ⟨block, middle, binding, headRun, headRead, _, headLocals, headFrame, headAccess, headNext⟩ :=
      runInput i before supplied le k trace call (providerAccess.trans access)
    have sameBlock : block = blocks i := congrArg Prod.fst (Option.some.inj (binding.symm.trans (bindings i)))
    subst block
    change CC.Mem.load .Mint8unsigned middle (blocks i) 0 = some (.Vint (flagWord (values i))) at headRead
    have head : CC.Star (CC.Step2 world) (.State f (atStage start) k e le before)
        trace (.State f (atStage (start + 1)) k e
          (le.set (decl i).inputTemp (.Vlong (values i))) middle) := by
      rw [next_stage i] at headRun
      exact headRun
    obtain ⟨after, finalLe, traces, length, tailRun, tailReads, tailWords, tailLocals,
        tailTemps, tailFrame, tailAccess, tailNext⟩ :=
      ih (start + 1) (by omega) middle (le.set (decl i).inputTemp (.Vlong (values i))) k
        (headAccess.trans (providerAccess.trans access))
    refine ⟨after, finalLe, trace :: traces, by simp [length], ?_, ?_, ?_, ?_, ?_,
      (providerFrame.trans headFrame).trans tailFrame,
      tailAccess.trans (headAccess.trans providerAccess), tailNext.trans (headNext.trans providerNext)⟩
    · simpa only [List.flatten_cons, CC.Eapp] using star_trans head tailRun
    · intro j lower
      by_cases same : j = i
      · subst j
        exact (tailWords i (by dsimp [i]; omega)).trans headRead
      · apply tailReads j
        have different : j.val ≠ start := fun equal => same (Fin.ext equal)
        omega
    · intro j upper
      have different : j ≠ i := by intro equal; subst j; dsimp [i] at upper; omega
      exact (tailWords j (by omega)).trans
        ((headLocals _ _ _ (bindings j) (separated j i different) .Mint8unsigned 0).trans
          (providerLocals _ _ _ (bindings j) .Mint8unsigned 0))
    · intro id ty block binding different chunk ofs
      exact (tailLocals id ty block binding different chunk ofs).trans
        ((headLocals id ty block binding (different i) chunk ofs).trans
          (providerLocals id ty block binding chunk ofs))
    · intro id different
      exact (tailTemps id different).trans (CC.PTree.gso _ _ _ _ (Ne.symm (different i)))

private theorem run_suffix (world : CC.CGenv)
    (inputBinding : CC.Genv.findSymbol world.genv_genv Arm64Entry._native_lab_entry_input =
        some (CC.Positive.ofNat 64) ∧
      CC.Genv.findFunctPtr world.genv_genv (CC.Positive.ofNat 64) = some Arm64OriginCache.inputFunction) (m : CC.Mem) (blocks : Fin 4 → CC.Block)
    (bindings : ∀ i, (allocation m).1.get (flagDeclaration i).name = some (blocks i, CC.tuchar))
    (values : Fin 4 → BitVec 64) (provider : ProviderAt world m values) (count : Nat) :
    ∀ start, start + count = 4 → ∀ (before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont),
    before.access = (allocation m).2.access →
    ∃ after finalLe, ∃ traces : List CC.Trace, traces.length = count ∧
      CC.Star (CC.Step2 world) (.State producer (stage start) k (allocation m).1 le before)
        traces.flatten (.State producer (stage 4) k (allocation m).1 finalLe after) ∧
      (∀ j : Fin 4, start ≤ j.val → CC.Mem.load .Mint8unsigned after (blocks j) 0 =
        some (.Vint (flagWord (values j)))) ∧
      (∀ j : Fin 4, j.val < start → CC.Mem.load .Mint8unsigned after (blocks j) 0 =
        CC.Mem.load .Mint8unsigned before (blocks j) 0) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) →
        (∀ i : Fin 4, id ≠ (flagDeclaration i).name) → ∀ chunk ofs,
        CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      (∀ id, (∀ i : Fin 4, id ≠ (flagDeclaration i).inputTemp) → finalLe.get id = le.get id) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  exact run_suffix_body world producer (allocation m).1 flagDeclaration stage
    (fun _ => rfl) next_stage m blocks bindings values provider
    (fun i before supplied le k trace call access => by
      simpa only [stage, dite_eq_left i.isLt] using
        flag_input_returns_bound world inputBinding i m before supplied le k (values i) trace call access) count

/-- Four actual flag calls followed by the actual three-transition LR-zero
assignment. All masked flag bytes are derived, and the next state is exactly
vectorStart, before any of its64 calls have been consumed. -/
theorem flag_inputs_initialized_bound (world : CC.CGenv)
    (inputBinding : CC.Genv.findSymbol world.genv_genv Arm64Entry._native_lab_entry_input =
        some (CC.Positive.ofNat 64) ∧
      CC.Genv.findFunctPtr world.genv_genv (CC.Positive.ofNat 64) = some Arm64OriginCache.inputFunction) (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (values : Fin 4 → BitVec 64) (provider : ProviderAt world m values)
    (access : before.access = (allocation m).2.access) :
    ∃ blocks : Fin 4 → CC.Block, ∃ lrBlock after finalLe, ∃ traces : List CC.Trace,
      traces.length = 4 ∧
      (∀ i, (allocation m).1.get (flagDeclaration i).name = some (blocks i, CC.tuchar)) ∧
      (allocation m).1.get Arm64Entry.___a64_lr = some (lrBlock, CC.tulong) ∧
      CC.Star (CC.Step2 world) (.State producer afterPointerTables k (allocation m).1 le before)
        traces.flatten (.State producer vectorStart k (allocation m).1 finalLe after) ∧
      (∀ i, CC.Mem.load .Mint8unsigned after (blocks i) 0 = some (.Vint (flagWord (values i)))) ∧
      CC.Mem.load .Mint64 after lrBlock 0 = some (.Vlong 0) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) →
        (∀ i : Fin 4, id ≠ (flagDeclaration i).name) → id ≠ Arm64Entry.___a64_lr → ∀ chunk ofs,
        CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      (∀ id, (∀ i : Fin 4, id ≠ (flagDeclaration i).inputTemp) → finalLe.get id = le.get id) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  classical
  have storage : ∀ i : Fin 4, ∃ block,
      (allocation m).1.get (flagDeclaration i).name = some (block, CC.tuchar) := by
    intro i
    obtain ⟨block, bound, _⟩ := scalar_local m (flagDeclaration i).name CC.tuchar .Mint8unsigned
      (flag_declarations_source i).2 rfl (by decide)
    exact ⟨block, bound⟩
  let blocks : Fin 4 → CC.Block := fun i => Classical.choose (storage i)
  have bindings : ∀ i, (allocation m).1.get (flagDeclaration i).name = some (blocks i, CC.tuchar) :=
    fun i => Classical.choose_spec (storage i)
  obtain ⟨middle, finalLe, traces, length, run, reads, _, locals, temps, frame, finalAccess, next⟩ :=
    run_suffix world inputBinding m blocks bindings values provider 4 0 rfl before le k access
  obtain ⟨lrBlock, after, lrBinding, lrRun, lrRead, lrLocals, lrFrame, lrAccess, lrNext⟩ :=
    lr_initialized_bound world m middle finalLe k (finalAccess.trans access)
  have source : stage 0 = afterPointerTables := first_flag_stage
  have target : stage 4 = (flagDeclaration 3).rest := rfl
  refine ⟨blocks, lrBlock, after, finalLe, traces, length, bindings, lrBinding, ?_, ?_, lrRead,
    ?_, temps, frame.trans lrFrame, lrAccess.trans finalAccess, lrNext.trans next⟩
  · rw [source, target] at run
    simpa only [CC.E0, CC.Eapp, List.append_nil] using star_trans run lrRun.sound
  · intro i
    have different : ∀ i : Fin 4, (flagDeclaration i).name ≠ Arm64Entry.___a64_lr := by decide +kernel
    exact (lrLocals _ _ _ (bindings i) (different i) .Mint8unsigned 0).trans (reads i (Nat.zero_le _))
  · intro id ty block bound notFlags notLr chunk ofs
    exact (lrLocals id ty block bound notLr chunk ofs).trans
      (locals id ty block bound notFlags chunk ofs)

theorem flag_inputs_initialized (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (values : Fin 4 → BitVec 64) (provider : Provider m values)
    (access : before.access = (allocation m).2.access) :
    ∃ blocks : Fin 4 → CC.Block, ∃ lrBlock after finalLe, ∃ traces : List CC.Trace,
      traces.length = 4 ∧
      (∀ i, (allocation m).1.get (flagDeclaration i).name = some (blocks i, CC.tuchar)) ∧
      (allocation m).1.get Arm64Entry.___a64_lr = some (lrBlock, CC.tulong) ∧
      CC.Star (CC.Step2 ge) (.State producer afterPointerTables k (allocation m).1 le before)
        traces.flatten (.State producer vectorStart k (allocation m).1 finalLe after) ∧
      (∀ i, CC.Mem.load .Mint8unsigned after (blocks i) 0 = some (.Vint (flagWord (values i)))) ∧
      CC.Mem.load .Mint64 after lrBlock 0 = some (.Vlong 0) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) →
        (∀ i : Fin 4, id ≠ (flagDeclaration i).name) → id ≠ Arm64Entry.___a64_lr → ∀ chunk ofs,
        CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      (∀ id, (∀ i : Fin 4, id ≠ (flagDeclaration i).inputTemp) → finalLe.get id = le.get id) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock :=
  flag_inputs_initialized_bound ge producer_input_binding m before le k values provider access

/-- Four flag outcomes, LR zero, all64 vector outcomes and the RAW suffix
establish the existing register relation. Only masked flag bits are bound to
native NZCV; the full64-bit provider outcomes remain unconstrained otherwise. -/
theorem flag_vector_inputs_and_raw_registers_with_storage
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (ctx : CC.Val) (ctxWord : BitVec 64) (represented : Arm64Registers.ValueRep addresses ctx ctxWord)
    (m before : CC.Mem) (le : CC.TempEnv) (input : le.get Arm64Entry._ctx = some ctx)
    (k : CC.Cont) (s : Reference.AArch64.State) (inputs : Fin 31 → BitVec 64)
    (flagInputs : Fin 4 → BitVec 64) (flagProvider : Provider m flagInputs)
    (flagMatches : ∀ i, .Vint (flagWord (flagInputs i)) = Arm64ProducerEntryView.flagValues s i)
    (vectorProvider : Arm64ProducerVectorInputs.Provider m (Arm64ProducerVectorInputs.nativeVectorWord s))
    (access : before.access = (allocation m).2.access)
    (tablesBefore : ∀ tags, ∃ table : TableLocals tags m, ∀ i,
      CC.Mem.load CC.Mptr before table.tableBlock (8 * (i.val : Int)) = some (.Vptr (table.cellBlock i) 0))
    (wordsBefore : ∀ (i : Fin 31), i ≠ 0 → ∀ block : CC.Block,
      (allocation m).1.get (tableCellName false i) = some (block, tableCellType false) →
      CC.Mem.load .Mint64 before block 0 = some (.Vlong (if i = 30 then 0 else inputs i)))
    (tagsBefore : ∀ (i : Fin 31), i ≠ 0 → i ≠ 30 → ∀ block : CC.Block,
      (allocation m).1.get (tableCellName true i) = some (block, tableCellType true) →
      CC.Mem.load .Mint8unsigned before block 0 = some (.Vint 0))
    (nativeContext : Reference.AArch64.gpr s 0 = ctxWord)
    (nativeReturn : Reference.AArch64.gpr s 30 = origins.returnAddress)
    (nativeOther : ∀ i : Fin 31, i ≠ 0 → i ≠ 30 → Reference.AArch64.gpr s i = inputs i)
    (nativeSp : Reference.AArch64.sp s = origins.stack) :
    ∃ entry : HeaderLocal m, ∃ after finalLe, ∃ traces : List CC.Trace, traces.length = 68 ∧
      CC.Star (CC.Step2 ge) (.State producer afterPointerTables k (allocation m).1 le before)
        traces.flatten (.State producer afterVectorLoop k (allocation m).1 finalLe after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val)
        after.nextblock after (.Vptr entry.block 0) s ∧
      Nonempty (Arm64ProducerRegisterStorage.Storage m after entry) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  obtain ⟨blocks, _, middle, flagLe, traces, length, bindings, _, flagRun, flagReads, _,
      locals, temps, flagFrame, flagAccess, flagNext⟩ :=
    flag_inputs_initialized m before le k flagInputs flagProvider access
  have ctxSeparate : ∀ i : Fin 4, Arm64Entry._ctx ≠ (flagDeclaration i).inputTemp := by decide +kernel
  have ctxInput : flagLe.get Arm64Entry._ctx = some ctx := (temps _ ctxSeparate).trans input
  have tables : ∀ tags, ∃ table : TableLocals tags m, ∀ i,
      CC.Mem.load CC.Mptr middle table.tableBlock (8 * (i.val : Int)) = some (.Vptr (table.cellBlock i) 0) := by
    intro tags
    obtain ⟨table, reads⟩ := tablesBefore tags
    have different : ∀ tags, (∀ i : Fin 4, tableName tags ≠ (flagDeclaration i).name) ∧
        tableName tags ≠ Arm64Entry.___a64_lr := by decide +kernel
    refine ⟨table, ?_⟩
    intro i
    rw [locals _ _ _ table.binding (different tags).1 (different tags).2 CC.Mptr (8 * (i.val : Int))]
    exact reads i
  have words : ∀ (i : Fin 31), i ≠ 0 → ∀ block : CC.Block,
      (allocation m).1.get (tableCellName false i) = some (block, tableCellType false) →
      CC.Mem.load .Mint64 middle block 0 = some (.Vlong (if i = 30 then 0 else inputs i)) := by
    intro i zero block bound
    have different : ∀ i : Fin 31, (∀ j : Fin 4, tableCellName false i ≠ (flagDeclaration j).name) ∧
        tableCellName false i ≠ Arm64Entry.___a64_lr := by decide +kernel
    rw [locals _ _ _ bound (different i).1 (different i).2 .Mint64 0]
    exact wordsBefore i zero block bound
  have tags : ∀ (i : Fin 31), i ≠ 0 → i ≠ 30 → ∀ block : CC.Block,
      (allocation m).1.get (tableCellName true i) = some (block, tableCellType true) →
      CC.Mem.load .Mint8unsigned middle block 0 = some (.Vint 0) := by
    intro i zero lr block bound
    have different : ∀ i : Fin 31, (∀ j : Fin 4, tableCellName true i ≠ (flagDeclaration j).name) ∧
        tableCellName true i ≠ Arm64Entry.___a64_lr := by decide +kernel
    rw [locals _ _ _ bound (different i).1 (different i).2 .Mint8unsigned 0]
    exact tagsBefore i zero lr block bound
  have flags : ∀ (i : Fin 4) (block : CC.Block),
      (allocation m).1.get (headerSourceName (Arm64ProducerEntryView.flagIndex i)) =
        some (block, headerSourceType (Arm64ProducerEntryView.flagIndex i)) →
      CC.Mem.load .Mint8unsigned middle block 0 = some (Arm64ProducerEntryView.flagValues s i) := by
    intro i block bound
    have source : ∀ i : Fin 4,
        headerSourceName (Arm64ProducerEntryView.flagIndex i) = (flagDeclaration i).name ∧
        headerSourceType (Arm64ProducerEntryView.flagIndex i) = CC.tuchar := by decide +kernel
    rw [(source i).1, (source i).2] at bound
    have same : block = blocks i := congrArg Prod.fst (Option.some.inj (bound.symm.trans (bindings i)))
    subst block
    simpa only [flagMatches i] using flagReads i
  obtain ⟨entry, after, finalLe, vectorTraces, vectorLength, vectorRun, registers, storage,
      vectorFrame, vectorAccess, vectorNext⟩ :=
    Arm64ProducerVectorInputs.vector_inputs_and_raw_registers_with_storage addresses origins ctx ctxWord represented
      m middle flagLe ctxInput k s inputs (flagAccess.trans access) vectorProvider tables words tags flags
      nativeContext nativeReturn nativeOther nativeSp
  refine ⟨entry, after, finalLe, traces ++ vectorTraces, by simp [length, vectorLength], ?_, registers, storage,
    flagFrame.trans vectorFrame, vectorAccess.trans flagAccess, vectorNext.trans flagNext⟩
  simpa only [List.flatten_append, CC.Eapp] using star_trans flagRun vectorRun

/-- Observer projection of the same resource-carrying source execution. -/
theorem flag_vector_inputs_and_raw_registers
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (ctx : CC.Val) (ctxWord : BitVec 64) (represented : Arm64Registers.ValueRep addresses ctx ctxWord)
    (m before : CC.Mem) (le : CC.TempEnv) (input : le.get Arm64Entry._ctx = some ctx)
    (k : CC.Cont) (s : Reference.AArch64.State) (inputs : Fin 31 → BitVec 64)
    (flagInputs : Fin 4 → BitVec 64) (flagProvider : Provider m flagInputs)
    (flagMatches : ∀ i, .Vint (flagWord (flagInputs i)) = Arm64ProducerEntryView.flagValues s i)
    (vectorProvider : Arm64ProducerVectorInputs.Provider m (Arm64ProducerVectorInputs.nativeVectorWord s))
    (access : before.access = (allocation m).2.access)
    (tablesBefore : ∀ tags, ∃ table : TableLocals tags m, ∀ i,
      CC.Mem.load CC.Mptr before table.tableBlock (8 * (i.val : Int)) = some (.Vptr (table.cellBlock i) 0))
    (wordsBefore : ∀ (i : Fin 31), i ≠ 0 → ∀ block : CC.Block,
      (allocation m).1.get (tableCellName false i) = some (block, tableCellType false) →
      CC.Mem.load .Mint64 before block 0 = some (.Vlong (if i = 30 then 0 else inputs i)))
    (tagsBefore : ∀ (i : Fin 31), i ≠ 0 → i ≠ 30 → ∀ block : CC.Block,
      (allocation m).1.get (tableCellName true i) = some (block, tableCellType true) →
      CC.Mem.load .Mint8unsigned before block 0 = some (.Vint 0))
    (nativeContext : Reference.AArch64.gpr s 0 = ctxWord)
    (nativeReturn : Reference.AArch64.gpr s 30 = origins.returnAddress)
    (nativeOther : ∀ i : Fin 31, i ≠ 0 → i ≠ 30 → Reference.AArch64.gpr s i = inputs i)
    (nativeSp : Reference.AArch64.sp s = origins.stack) :
    ∃ entry : HeaderLocal m, ∃ after finalLe, ∃ traces : List CC.Trace, traces.length = 68 ∧
      CC.Star (CC.Step2 ge) (.State producer afterPointerTables k (allocation m).1 le before)
        traces.flatten (.State producer afterVectorLoop k (allocation m).1 finalLe after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val)
        after.nextblock after (.Vptr entry.block 0) s ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  obtain ⟨entry, after, finalLe, traces, length, run, registers, _, frame, access, next⟩ :=
    flag_vector_inputs_and_raw_registers_with_storage addresses origins ctx ctxWord represented m before le input k s inputs flagInputs flagProvider flagMatches vectorProvider access tablesBefore wordsBefore tagsBefore nativeContext nativeReturn nativeOther nativeSp
  exact ⟨entry, after, finalLe, traces, length, run, registers, frame, access, next⟩

end KProgFormal.ClightRefinement.Arm64ProducerFlagInputs
