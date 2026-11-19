import KProgFormal.ClightRefinement.Arm64ProducerTablesToRegisters

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProducerGprInputs

open Arm64Producer

/-- The30 input declarations precede the separate x30-zero branch. -/
def inputRegister (i : Fin 30) : Fin 31 := ⟨i.val, Nat.lt_trans i.isLt (by decide)⟩

/-- Framed outcomes of the actual kind-6 calls at visited memories. Each full
returned word and supplied memory stays explicit; availability is an
invocation-environment obligation, not an invented provider implementation. -/
def ProviderAt (world : CC.CGenv) (m : CC.Mem) (values : Fin 31 → BitVec 64) : Prop :=
  ∀ (i : Fin 30) (before : CC.Mem), before.access = (allocation m).2.access →
    ∃ trace supplied,
      CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv world.genv_genv)
        [.Vint (6#32)] before trace (.Vlong (values (inputRegister i))) supplied ∧
      supplied.access = before.access ∧ supplied.nextblock = before.nextblock ∧
      FrameBelow m.nextblock before supplied ∧
      ∀ id ty block, (allocation m).1.get id = some (block, ty) →
        ∀ chunk ofs, CC.Mem.load chunk supplied block ofs = CC.Mem.load chunk before block ofs

/-- Preserve the standalone environment parameterization. -/
def Provider (m : CC.Mem) (values : Fin 31 → BitVec 64) : Prop :=
  ProviderAt ge m values

private theorem names_separate : ∀ selected (i j : Fin 30), i ≠ j →
    tableCellName selected (inputRegister i) ≠ (registerDeclaration (inputRegister j)).word ∧
    tableCellName selected (inputRegister i) ≠ (registerDeclaration (inputRegister j)).tag := by
  decide +kernel

/-- Shared traversal over a real declaration family. The caller supplies
its checked successor chain and actual per-input execution, while the existing
induction retains ordered traces, earlier cells and caller/local/temp frames. -/
theorem run_suffix_body (world : CC.CGenv) (f : CC.Function) (e : CC.Env)
    (decl : Fin 31 → RegisterDeclaration) (stage : Fin 31 → CC.Stmt)
    (sameNames : ∀ i, (decl i).word = (registerDeclaration i).word ∧
      (decl i).tag = (registerDeclaration i).tag)
    (chain : ∀ i : Fin 30, (decl (inputRegister i)).rest =
      stage ⟨i.val + 1, Nat.add_lt_add_right i.isLt 1⟩)
    (m : CC.Mem) (blocks : Bool → Fin 30 → CC.Block)
    (bindings : ∀ selected i, (allocation m).1.get (tableCellName selected (inputRegister i)) =
      some (blocks selected i, tableCellType selected))
    (values : Fin 31 → BitVec 64) (provider : ProviderAt world m values)
    (runInput : ∀ (i : Fin 30) (before supplied : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) (trace : CC.Trace),
      CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv world.genv_genv)
        [.Vint (6#32)] before trace (.Vlong (values (inputRegister i))) supplied →
      supplied.access = (allocation m).2.access →
      ∃ xb tb after,
        (allocation m).1.get (decl (inputRegister i)).word =
          some (xb, .Tunion Arm64Entry._arm64_sim_gpr CC.noattr) ∧
        (allocation m).1.get (decl (inputRegister i)).tag = some (tb, CC.tuchar) ∧
        CC.Star (CC.Step2 world) (.State f (stage (inputRegister i)) k e le before)
          trace (.State f (decl (inputRegister i)).rest k e
            ((decl (inputRegister i)).temps le (values (inputRegister i))) after) ∧
        CC.Mem.loadv .Mint64 after (.Vptr xb 0) = some (.Vlong (values (inputRegister i))) ∧
        CC.Mem.loadv .Mint8unsigned after (.Vptr tb 0) = some (.Vint 0) ∧
        (∀ id ty block, (allocation m).1.get id = some (block, ty) →
          id ≠ (decl (inputRegister i)).word → id ≠ (decl (inputRegister i)).tag →
          ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk supplied block ofs) ∧
        FrameBelow m.nextblock supplied after ∧ after.access = supplied.access ∧
        after.nextblock = supplied.nextblock)
    (count : Nat) :
    ∀ start : Fin 31, start.val + count = 30 → ∀ (before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont),
    before.access = (allocation m).2.access →
    ∃ after finalLe, ∃ traces : List CC.Trace, traces.length = count ∧
      CC.Star (CC.Step2 world) (.State f (stage start) k e le before)
        traces.flatten (.State f (stage 30) k e finalLe after) ∧
      (∀ j : Fin 30, start.val ≤ j.val →
        CC.Mem.load .Mint64 after (blocks false j) 0 = some (.Vlong (values (inputRegister j))) ∧
        CC.Mem.load .Mint8unsigned after (blocks true j) 0 = some (.Vint 0)) ∧
      (∀ selected (j : Fin 30), j.val < start.val → ∀ chunk ofs,
        CC.Mem.load chunk after (blocks selected j) ofs = CC.Mem.load chunk before (blocks selected j) ofs) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) →
        (∀ i : Fin 30, id ≠ (decl (inputRegister i)).word ∧
          id ≠ (decl (inputRegister i)).tag) → ∀ chunk ofs,
        CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      (∀ id, (∀ i : Fin 30, id ≠ (decl (inputRegister i)).inputTemp ∧
          id ≠ (decl (inputRegister i)).resultTemp) → finalLe.get id = le.get id) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  have separated : ∀ selected (i j : Fin 30), i ≠ j →
      tableCellName selected (inputRegister i) ≠ (decl (inputRegister j)).word ∧
      tableCellName selected (inputRegister i) ≠ (decl (inputRegister j)).tag := by
    intro selected i j different
    rw [(sameNames (inputRegister j)).1, (sameNames (inputRegister j)).2]
    exact names_separate selected i j different
  induction count with
  | zero =>
    intro start bound before le k access
    have same : start = 30 := Fin.ext (by omega)
    subst start
    refine ⟨before, le, [], rfl, .refl _, ?_, ?_, ?_, ?_, FrameBelow.refl _ _, rfl, rfl⟩
    · intro j lower; have := j.isLt; omega
    · intro selected j upper chunk ofs; rfl
    · intro id ty block binding different chunk ofs; rfl
    · intro id different; rfl
  | succ count ih =>
    intro start bound before le k access
    let i : Fin 30 := ⟨start.val, by omega⟩
    let nextStart : Fin 31 := ⟨start.val + 1, by omega⟩
    obtain ⟨trace, supplied, call, providerAccess, providerNext, providerFrame, providerLocals⟩ :=
      provider i before access
    obtain ⟨xb, tb, middle, wordBinding, tagBinding, headRun, headWord, headTag,
        headLocals, headFrame, headAccess, headNext⟩ :=
      runInput i before supplied le k trace call
        (providerAccess.trans access)
    rw [(sameNames (inputRegister i)).1] at wordBinding
    rw [(sameNames (inputRegister i)).2] at tagBinding
    have wordBlock : xb = blocks false i :=
      congrArg Prod.fst (Option.some.inj (wordBinding.symm.trans (bindings false i)))
    have tagBlock : tb = blocks true i :=
      congrArg Prod.fst (Option.some.inj (tagBinding.symm.trans (bindings true i)))
    rw [wordBlock] at headWord
    rw [tagBlock] at headTag
    change CC.Mem.load .Mint64 middle (blocks false i) 0 = some (.Vlong (values (inputRegister i))) at headWord
    change CC.Mem.load .Mint8unsigned middle (blocks true i) 0 = some (.Vint 0) at headTag
    rw [chain i] at headRun
    obtain ⟨after, finalLe, traces, length, tailRun, tailReads, tailOld, tailLocals,
        tailTemps, tailFrame, tailAccess, tailNext⟩ :=
      ih nextStart (by dsimp [nextStart]; omega) middle
        ((decl (inputRegister i)).temps le (values (inputRegister i))) k
        (headAccess.trans (providerAccess.trans access))
    refine ⟨after, finalLe, trace :: traces, by simp [length], ?_, ?_, ?_, ?_, ?_,
      (providerFrame.trans headFrame).trans tailFrame,
      tailAccess.trans (headAccess.trans providerAccess), tailNext.trans (headNext.trans providerNext)⟩
    · simpa only [List.flatten_cons, CC.Eapp, show inputRegister i = start from Fin.ext rfl] using star_trans headRun tailRun
    · intro j lower
      by_cases same : j = i
      · subst j
        exact ⟨(tailOld false i (by dsimp [i, nextStart]; omega) .Mint64 0).trans headWord,
          (tailOld true i (by dsimp [i, nextStart]; omega) .Mint8unsigned 0).trans headTag⟩
      · apply tailReads j
        have different : j.val ≠ start.val := fun equal => same (Fin.ext equal)
        dsimp [nextStart]
        omega
    · intro selected j upper chunk ofs
      have different : j ≠ i := by intro equal; subst j; dsimp [i] at upper; omega
      exact (tailOld selected j (by dsimp [nextStart]; omega) chunk ofs).trans
        ((headLocals _ _ _ (bindings selected j) (separated selected j i different).1
          (separated selected j i different).2 chunk ofs).trans
          (providerLocals _ _ _ (bindings selected j) chunk ofs))
    · intro id ty block binding different chunk ofs
      exact (tailLocals id ty block binding different chunk ofs).trans
        ((headLocals id ty block binding (different i).1 (different i).2 chunk ofs).trans
          (providerLocals id ty block binding chunk ofs))
    · intro id different
      exact (tailTemps id different).trans
        ((CC.PTree.gso _ _ _ _ (Ne.symm (different i).2)).trans
          (CC.PTree.gso _ _ _ _ (Ne.symm (different i).1)))

private theorem run_suffix (world : CC.CGenv)
    (layout : world.genv_cenv = ge.genv_cenv)
    (binding : CC.Genv.findSymbol world.genv_genv Arm64Entry._native_lab_entry_input =
        some (CC.Positive.ofNat 64) ∧
      CC.Genv.findFunctPtr world.genv_genv (CC.Positive.ofNat 64) = some Arm64OriginCache.inputFunction) (m : CC.Mem) (blocks : Bool → Fin 30 → CC.Block)
    (bindings : ∀ selected i, (allocation m).1.get (tableCellName selected (inputRegister i)) =
      some (blocks selected i, tableCellType selected))
    (values : Fin 31 → BitVec 64) (provider : ProviderAt world m values) (count : Nat) :
    ∀ start : Fin 31, start.val + count = 30 → ∀ (before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont),
    before.access = (allocation m).2.access →
    ∃ after finalLe, ∃ traces : List CC.Trace, traces.length = count ∧
      CC.Star (CC.Step2 world) (.State producer (registerDeclarationStage start) k (allocation m).1 le before)
        traces.flatten (.State producer (registerDeclarationStage 30) k (allocation m).1 finalLe after) ∧
      (∀ j : Fin 30, start.val ≤ j.val →
        CC.Mem.load .Mint64 after (blocks false j) 0 = some (.Vlong (values (inputRegister j))) ∧
        CC.Mem.load .Mint8unsigned after (blocks true j) 0 = some (.Vint 0)) ∧
      (∀ selected (j : Fin 30), j.val < start.val → ∀ chunk ofs,
        CC.Mem.load chunk after (blocks selected j) ofs = CC.Mem.load chunk before (blocks selected j) ofs) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) →
        (∀ i : Fin 30, id ≠ (registerDeclaration (inputRegister i)).word ∧
          id ≠ (registerDeclaration (inputRegister i)).tag) → ∀ chunk ofs,
        CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      (∀ id, (∀ i : Fin 30, id ≠ (registerDeclaration (inputRegister i)).inputTemp ∧
          id ≠ (registerDeclaration (inputRegister i)).resultTemp) → finalLe.get id = le.get id) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  exact run_suffix_body world producer (allocation m).1 registerDeclaration registerDeclarationStage
    (fun _ => ⟨rfl, rfl⟩) register_declarations_chain m blocks bindings values provider
    (fun i before supplied le k trace call access =>
      register_input_returns_bound world layout binding i m before supplied le k
        (values (inputRegister i)) trace call access) count

/-- All30 real GPR visits, including x0, derive word/tag data from actual
external outcomes. Both per-return temporary updates and30 ordered traces
are retained, with earlier local and caller readbacks framed. -/
theorem gpr_inputs_initialized_bound (world : CC.CGenv)
    (layout : world.genv_cenv = ge.genv_cenv)
    (binding : CC.Genv.findSymbol world.genv_genv Arm64Entry._native_lab_entry_input =
        some (CC.Positive.ofNat 64) ∧
      CC.Genv.findFunctPtr world.genv_genv (CC.Positive.ofNat 64) = some Arm64OriginCache.inputFunction) (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (values : Fin 31 → BitVec 64) (provider : ProviderAt world m values)
    (access : before.access = (allocation m).2.access) :
    ∃ blocks : Bool → Fin 30 → CC.Block, ∃ after finalLe, ∃ traces : List CC.Trace,
      traces.length = 30 ∧
      (∀ selected i, (allocation m).1.get (tableCellName selected (inputRegister i)) =
        some (blocks selected i, tableCellType selected)) ∧
      CC.Star (CC.Step2 world) (.State producer (registerDeclarationStage 0) k (allocation m).1 le before)
        traces.flatten (.State producer (registerDeclarationStage 30) k (allocation m).1 finalLe after) ∧
      (∀ i : Fin 30, CC.Mem.load .Mint64 after (blocks false i) 0 = some (.Vlong (values (inputRegister i))) ∧
        CC.Mem.load .Mint8unsigned after (blocks true i) 0 = some (.Vint 0)) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) →
        (∀ i : Fin 30, id ≠ (registerDeclaration (inputRegister i)).word ∧
          id ≠ (registerDeclaration (inputRegister i)).tag) → ∀ chunk ofs,
        CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      (∀ id, (∀ i : Fin 30, id ≠ (registerDeclaration (inputRegister i)).inputTemp ∧
          id ≠ (registerDeclaration (inputRegister i)).resultTemp) → finalLe.get id = le.get id) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  classical
  have storage : ∀ selected (i : Fin 30), ∃ block,
      (allocation m).1.get (tableCellName selected (inputRegister i)) = some (block, tableCellType selected) := by
    intro selected i
    obtain ⟨block, bound, _⟩ := local_storage m (tableCellName selected (inputRegister i))
      (tableCellType selected) (table_cell_declaration selected (inputRegister i))
    exact ⟨block, bound⟩
  let blocks : Bool → Fin 30 → CC.Block := fun selected i => Classical.choose (storage selected i)
  have bindings : ∀ selected i, (allocation m).1.get (tableCellName selected (inputRegister i)) =
      some (blocks selected i, tableCellType selected) := fun selected i => Classical.choose_spec (storage selected i)
  obtain ⟨after, finalLe, traces, length, run, reads, _, locals, temps, frame, finalAccess, next⟩ :=
    run_suffix world layout binding m blocks bindings values provider 30 0 rfl before le k access
  exact ⟨blocks, after, finalLe, traces, length, bindings, run, (fun i => reads i (Nat.zero_le _)),
    locals, temps, frame, finalAccess, next⟩

theorem gpr_inputs_initialized (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (values : Fin 31 → BitVec 64) (provider : Provider m values)
    (access : before.access = (allocation m).2.access) :
    ∃ blocks : Bool → Fin 30 → CC.Block, ∃ after finalLe, ∃ traces : List CC.Trace,
      traces.length = 30 ∧
      (∀ selected i, (allocation m).1.get (tableCellName selected (inputRegister i)) =
        some (blocks selected i, tableCellType selected)) ∧
      CC.Star (CC.Step2 ge) (.State producer (registerDeclarationStage 0) k (allocation m).1 le before)
        traces.flatten (.State producer (registerDeclarationStage 30) k (allocation m).1 finalLe after) ∧
      (∀ i : Fin 30, CC.Mem.load .Mint64 after (blocks false i) 0 = some (.Vlong (values (inputRegister i))) ∧
        CC.Mem.load .Mint8unsigned after (blocks true i) 0 = some (.Vint 0)) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) →
        (∀ i : Fin 30, id ≠ (registerDeclaration (inputRegister i)).word ∧
          id ≠ (registerDeclaration (inputRegister i)).tag) → ∀ chunk ofs,
        CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      (∀ id, (∀ i : Fin 30, id ≠ (registerDeclaration (inputRegister i)).inputTemp ∧
          id ≠ (registerDeclaration (inputRegister i)).resultTemp) → finalLe.get id = le.get id) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock :=
  gpr_inputs_initialized_bound ge rfl producer_input_binding m before le k values provider access

/-- All30 GPR visits compose with x30 zero, tables, four flags,64 vector
visits and RAW setup. No initial GPR/tag/table/flag/vector contents are assumed;
provider outcomes and same-invocation native bindings remain explicit. -/
theorem gpr_inputs_to_registers_with_storage
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (ctx : CC.Val) (ctxWord : BitVec 64) (represented : Arm64Registers.ValueRep addresses ctx ctxWord)
    (m before : CC.Mem) (le : CC.TempEnv) (input : le.get Arm64Entry._ctx = some ctx)
    (k : CC.Cont) (s : Reference.AArch64.State) (inputs : Fin 31 → BitVec 64)
    (gprProvider : Provider m inputs)
    (flagInputs : Fin 4 → BitVec 64) (flagProvider : Arm64ProducerFlagInputs.Provider m flagInputs)
    (flagMatches : ∀ i, .Vint (flagWord (flagInputs i)) = Arm64ProducerEntryView.flagValues s i)
    (vectorProvider : Arm64ProducerVectorInputs.Provider m (Arm64ProducerVectorInputs.nativeVectorWord s))
    (access : before.access = (allocation m).2.access)
    (nativeContext : Reference.AArch64.gpr s 0 = ctxWord)
    (nativeReturn : Reference.AArch64.gpr s 30 = origins.returnAddress)
    (nativeOther : ∀ i : Fin 31, i ≠ 0 → i ≠ 30 → Reference.AArch64.gpr s i = inputs i)
    (nativeSp : Reference.AArch64.sp s = origins.stack) :
    ∃ entry : HeaderLocal m, ∃ after finalLe, ∃ traces : List CC.Trace, traces.length = 98 ∧
      CC.Star (CC.Step2 ge) (.State producer (registerDeclarationStage 0) k (allocation m).1 le before)
        traces.flatten (.State producer afterVectorLoop k (allocation m).1 finalLe after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val)
        after.nextblock after (.Vptr entry.block 0) s ∧
      Nonempty (Arm64ProducerRegisterStorage.Storage m after entry) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  obtain ⟨blocks, middle, gprLe, traces, length, bindings, gprRun, reads,
      _, temps, gprFrame, gprAccess, gprNext⟩ :=
    gpr_inputs_initialized m before le k inputs gprProvider access
  have ctxSeparate : ∀ i : Fin 30,
      Arm64Entry._ctx ≠ (registerDeclaration (inputRegister i)).inputTemp ∧
      Arm64Entry._ctx ≠ (registerDeclaration (inputRegister i)).resultTemp := by decide +kernel
  have ctxInput : gprLe.get Arm64Entry._ctx = some ctx := (temps _ ctxSeparate).trans input
  have words : ∀ (i : Fin 31), i ≠ 0 → i ≠ 30 → ∀ block : CC.Block,
      (allocation m).1.get (tableCellName false i) = some (block, tableCellType false) →
      CC.Mem.load .Mint64 middle block 0 = some (.Vlong (inputs i)) := by
    intro i nonzero nonlr block bound
    let j : Fin 30 := ⟨i.val, by have := i.isLt; have : i.val ≠ 30 := fun h => nonlr (Fin.ext h); omega⟩
    have index : inputRegister j = i := Fin.ext rfl
    have slot := bindings false j
    rw [index] at slot
    have same : block = blocks false j := congrArg Prod.fst (Option.some.inj (bound.symm.trans slot))
    rw [same]
    simpa only [index] using (reads j).1
  have tags : ∀ (i : Fin 31), i ≠ 0 → i ≠ 30 → ∀ block : CC.Block,
      (allocation m).1.get (tableCellName true i) = some (block, tableCellType true) →
      CC.Mem.load .Mint8unsigned middle block 0 = some (.Vint 0) := by
    intro i nonzero nonlr block bound
    let j : Fin 30 := ⟨i.val, by have := i.isLt; have : i.val ≠ 30 := fun h => nonlr (Fin.ext h); omega⟩
    have index : inputRegister j = i := Fin.ext rfl
    have slot := bindings true j
    rw [index] at slot
    have same : block = blocks true j := congrArg Prod.fst (Option.some.inj (bound.symm.trans slot))
    rw [same]
    exact (reads j).2
  obtain ⟨entry, after, finalLe, suffixTraces, suffixLength, suffix, registers, storage,
      suffixFrame, suffixAccess, suffixNext⟩ :=
    Arm64ProducerTablesToRegisters.tables_to_registers_with_storage addresses origins ctx ctxWord represented
      m middle gprLe ctxInput k s inputs flagInputs flagProvider flagMatches vectorProvider
      (gprAccess.trans access) words tags nativeContext nativeReturn nativeOther nativeSp
  refine ⟨entry, after, finalLe, traces ++ suffixTraces, by simp [length, suffixLength], ?_, registers, storage,
    gprFrame.trans suffixFrame, suffixAccess.trans gprAccess, suffixNext.trans gprNext⟩
  simpa only [List.flatten_append, CC.Eapp] using star_trans gprRun suffix

/-- Observer projection of the same resource-carrying source execution. -/
theorem gpr_inputs_to_registers
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (ctx : CC.Val) (ctxWord : BitVec 64) (represented : Arm64Registers.ValueRep addresses ctx ctxWord)
    (m before : CC.Mem) (le : CC.TempEnv) (input : le.get Arm64Entry._ctx = some ctx)
    (k : CC.Cont) (s : Reference.AArch64.State) (inputs : Fin 31 → BitVec 64)
    (gprProvider : Provider m inputs)
    (flagInputs : Fin 4 → BitVec 64) (flagProvider : Arm64ProducerFlagInputs.Provider m flagInputs)
    (flagMatches : ∀ i, .Vint (flagWord (flagInputs i)) = Arm64ProducerEntryView.flagValues s i)
    (vectorProvider : Arm64ProducerVectorInputs.Provider m (Arm64ProducerVectorInputs.nativeVectorWord s))
    (access : before.access = (allocation m).2.access)
    (nativeContext : Reference.AArch64.gpr s 0 = ctxWord)
    (nativeReturn : Reference.AArch64.gpr s 30 = origins.returnAddress)
    (nativeOther : ∀ i : Fin 31, i ≠ 0 → i ≠ 30 → Reference.AArch64.gpr s i = inputs i)
    (nativeSp : Reference.AArch64.sp s = origins.stack) :
    ∃ entry : HeaderLocal m, ∃ after finalLe, ∃ traces : List CC.Trace, traces.length = 98 ∧
      CC.Star (CC.Step2 ge) (.State producer (registerDeclarationStage 0) k (allocation m).1 le before)
        traces.flatten (.State producer afterVectorLoop k (allocation m).1 finalLe after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val)
        after.nextblock after (.Vptr entry.block 0) s ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  obtain ⟨entry, after, finalLe, traces, length, run, registers, _, frame, access, next⟩ :=
    gpr_inputs_to_registers_with_storage addresses origins ctx ctxWord represented m before le input k s inputs gprProvider flagInputs flagProvider flagMatches vectorProvider access nativeContext nativeReturn nativeOther nativeSp
  exact ⟨entry, after, finalLe, traces, length, run, registers, frame, access, next⟩

/-- The actual producer call allocates/initializes its frame and executes all
98 input visits before constructing the register view. No first-call prefix
is duplicated; the existing580 cache prefix plus9 RAW setup transitions stop
at register declaration0 before its actual kind-6 call. -/
theorem producer_registers_initialized_with_storage
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (ctx : CC.Val) (ctxWord : BitVec 64) (represented : Arm64Registers.ValueRep addresses ctx ctxWord)
    (m : CC.Mem) (continuation : CC.Val) (k : CC.Cont)
    (s : Reference.AArch64.State) (inputs : Fin 31 → BitVec 64)
    (gprProvider : Provider m inputs)
    (flagInputs : Fin 4 → BitVec 64) (flagProvider : Arm64ProducerFlagInputs.Provider m flagInputs)
    (flagMatches : ∀ i, .Vint (flagWord (flagInputs i)) = Arm64ProducerEntryView.flagValues s i)
    (vectorProvider : Arm64ProducerVectorInputs.Provider m (Arm64ProducerVectorInputs.nativeVectorWord s))
    (nativeContext : Reference.AArch64.gpr s 0 = ctxWord)
    (nativeReturn : Reference.AArch64.gpr s 30 = origins.returnAddress)
    (nativeOther : ∀ i : Fin 31, i ≠ 0 → i ≠ 30 → Reference.AArch64.gpr s i = inputs i)
    (nativeSp : Reference.AArch64.sp s = origins.stack) :
    ∃ entry : HeaderLocal m, ∃ after finalLe, ∃ traces : List CC.Trace, traces.length = 98 ∧
      CC.Star (CC.Step2 ge) (.Callstate (.Internal producer) [ctx, continuation] k m)
        traces.flatten (.State producer afterVectorLoop k (allocation m).1 finalLe after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val)
        after.nextblock after (.Vptr entry.block 0) s ∧
      Nonempty (Arm64ProducerRegisterStorage.Storage m after entry) ∧
      FrameBelow m.nextblock m after ∧ after.access = (allocation m).2.access ∧
      after.nextblock = (allocation m).2.nextblock := by
  obtain ⟨cached, cacheRun, _, cacheFrame, cacheAccess, cacheNext⟩ := entry_caches_initialized m ctx continuation k
  obtain ⟨ready, setupRun, _, setupFrame, setupAccess, setupNext⟩ :=
    setup_register_input m cached (initialTemps ctx continuation) k cacheAccess
  change InternalRun ge 9
    (.State producer afterCacheStage k (allocation m).1 (initialTemps ctx continuation) cached)
    (.State producer (registerDeclarationStage 0) k (allocation m).1 (initialTemps ctx continuation) ready) at setupRun
  have ctxSeparate : Arm64Entry._continuation ≠ Arm64Entry._ctx := by decide +kernel
  have ctxInput : (initialTemps ctx continuation).get Arm64Entry._ctx = some ctx :=
    (CC.PTree.gso _ _ _ _ ctxSeparate).trans (CC.PTree.gss _ _ _)
  have prefixRun : InternalRun ge 589 (.Callstate (.Internal producer) [ctx, continuation] k m)
      (.State producer (registerDeclarationStage 0) k (allocation m).1 (initialTemps ctx continuation) ready) :=
    cacheRun.trans setupRun
  obtain ⟨entry, after, finalLe, traces, length, run, registers, storage, frame, access, next⟩ :=
    gpr_inputs_to_registers_with_storage addresses origins ctx ctxWord represented m ready (initialTemps ctx continuation)
      ctxInput k s inputs gprProvider flagInputs flagProvider flagMatches vectorProvider
      (setupAccess.trans cacheAccess) nativeContext nativeReturn nativeOther nativeSp
  refine ⟨entry, after, finalLe, traces, length, ?_, registers, storage,
    (cacheFrame.trans setupFrame).trans frame, access.trans (setupAccess.trans cacheAccess),
    next.trans (setupNext.trans cacheNext)⟩
  simpa only [CC.E0, CC.Eapp, List.nil_append] using star_trans prefixRun.sound run

/-- Observer projection of the same resource-carrying source execution. -/
theorem producer_registers_initialized
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (ctx : CC.Val) (ctxWord : BitVec 64) (represented : Arm64Registers.ValueRep addresses ctx ctxWord)
    (m : CC.Mem) (continuation : CC.Val) (k : CC.Cont)
    (s : Reference.AArch64.State) (inputs : Fin 31 → BitVec 64)
    (gprProvider : Provider m inputs)
    (flagInputs : Fin 4 → BitVec 64) (flagProvider : Arm64ProducerFlagInputs.Provider m flagInputs)
    (flagMatches : ∀ i, .Vint (flagWord (flagInputs i)) = Arm64ProducerEntryView.flagValues s i)
    (vectorProvider : Arm64ProducerVectorInputs.Provider m (Arm64ProducerVectorInputs.nativeVectorWord s))
    (nativeContext : Reference.AArch64.gpr s 0 = ctxWord)
    (nativeReturn : Reference.AArch64.gpr s 30 = origins.returnAddress)
    (nativeOther : ∀ i : Fin 31, i ≠ 0 → i ≠ 30 → Reference.AArch64.gpr s i = inputs i)
    (nativeSp : Reference.AArch64.sp s = origins.stack) :
    ∃ entry : HeaderLocal m, ∃ after finalLe, ∃ traces : List CC.Trace, traces.length = 98 ∧
      CC.Star (CC.Step2 ge) (.Callstate (.Internal producer) [ctx, continuation] k m)
        traces.flatten (.State producer afterVectorLoop k (allocation m).1 finalLe after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val)
        after.nextblock after (.Vptr entry.block 0) s ∧
      FrameBelow m.nextblock m after ∧ after.access = (allocation m).2.access ∧
      after.nextblock = (allocation m).2.nextblock := by
  obtain ⟨entry, after, finalLe, traces, length, run, registers, _, frame, access, next⟩ :=
    producer_registers_initialized_with_storage addresses origins ctx ctxWord represented m continuation k s inputs gprProvider flagInputs flagProvider flagMatches vectorProvider nativeContext nativeReturn nativeOther nativeSp
  exact ⟨entry, after, finalLe, traces, length, run, registers, frame, access, next⟩

end KProgFormal.ClightRefinement.Arm64ProducerGprInputs
