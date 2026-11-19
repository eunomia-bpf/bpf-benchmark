import KProgFormal.ClightRefinement.Arm64ProgramEntryRegisterSource
import KProgFormal.ClightRefinement.Arm64ProducerGprInputs

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryGprInputs

open Arm64ProgramEntryAllocation (world allocation)
open Arm64ProgramEntryRegisterSource (declaration stage afterRegisters)
open Arm64ProducerGprInputs (inputRegister ProviderAt)
open Arm64Producer (tableCellName tableCellType)

/-- The continuation carries the actual function, local environment and temps. -/
def continuation (i : Fin 31) (initial : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) : CC.Cont :=
  let d := declaration i
  .Kcall (some d.inputTemp) Arm64ProgramFixture.f_arm64_execute_compile (allocation initial).1 le
    (.Kseq d.setValue (.Kseq d.storeValue (.Kseq (.Ssequence d.storeTag d.rest) k)))

/-- Instantiate the one shared store construction for every actual declaration. -/
theorem storage (i : Fin 31) (initial supplied : CC.Mem) (value : BitVec 64)
    (access : supplied.access = (Arm64Producer.allocation initial).2.access) :
    ∃ writes : Arm64Producer.DeclarationStores (declaration i) initial supplied value,
      (allocation initial).1.get (declaration i).word =
        some (writes.wordBlock, .Tunion Arm64Entry._arm64_sim_gpr CC.noattr) ∧
      (allocation initial).1.get (declaration i).tag = some (writes.tagBlock, CC.tuchar) := by
  obtain ⟨wordMember, tagMember, distinct, wordName, tagName, _, _⟩ :=
    Arm64ProgramEntryRegisterSource.storage_metadata i
  obtain ⟨writes⟩ := Arm64Producer.declaration_stores_for (declaration i) initial supplied value
    wordMember tagMember distinct access
  have word := Arm64ProgramEntryAllocation.local_binding initial _ _ _ writes.wordBinding
  have tag := Arm64ProgramEntryAllocation.local_binding initial _ _ _ writes.tagBinding
  rw [wordName] at word
  rw [tagName] at tag
  exact ⟨writes, word, tag⟩

theorem call_ready (i : Fin 30) (initial before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) :
    InternalRun world 5
      (.State Arm64ProgramFixture.f_arm64_execute_compile (stage (inputRegister i)) k
        (allocation initial).1 le before)
      (.Callstate Arm64OriginCache.inputFunction [.Vint (6#32)]
        (continuation (inputRegister i) initial le k) before) := by
  rw [Arm64ProgramEntryRegisterSource.source]
  have different : CC.Integers.Int.eq (declaration (inputRegister i)).index (30#32) = false := by
    rw [Arm64ProgramEntryRegisterSource.indices]
    exact beq_eq_false_iff_ne.mpr (Nat.ne_of_lt i.isLt)
  have run := Arm64Producer.declaration_call_body world Arm64ProgramFixture.f_arm64_execute_compile
    (allocation initial).1 Arm64ProgramEntryCall.inputBlock Arm64ProgramEntryCall.input_binding
    (declaration (inputRegister i)) before le k (Arm64ProgramEntryCall.input_unshadowed initial) different
  exact internalRun_of_steps run.2 run.1

theorem writeback (i : Fin 31) (initial supplied : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (value : BitVec 64) (access : supplied.access = (Arm64Producer.allocation initial).2.access) :
    ∃ writes : Arm64Producer.DeclarationStores (declaration i) initial supplied value,
      (allocation initial).1.get (declaration i).word =
        some (writes.wordBlock, .Tunion Arm64Entry._arm64_sim_gpr CC.noattr) ∧
      (allocation initial).1.get (declaration i).tag = some (writes.tagBlock, CC.tuchar) ∧
      InternalRun world 9 (.Returnstate (.Vlong value) (continuation i initial le k) supplied)
        (.State Arm64ProgramFixture.f_arm64_execute_compile (declaration i).rest k
          (allocation initial).1 ((declaration i).temps le value) writes.after) := by
  obtain ⟨writes, word, tag⟩ := storage i initial supplied value access
  have run := Arm64Producer.declaration_return_body world Arm64ProgramFixture.f_arm64_execute_compile
    (allocation initial).1 Arm64ProgramEntryRegisters.gpr_layout (declaration i) initial supplied le k
    value writes word tag
  exact ⟨writes, word, tag, internalRun_of_steps run.2 run.1⟩

/-- Retain every stated provider trace and supplied post-memory. -/
theorem input_returns (i : Fin 30) (initial before supplied : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (value : BitVec 64) (trace : CC.Trace)
    (provider : CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv world.genv_genv)
      [.Vint (6#32)] before trace (.Vlong value) supplied)
    (access : supplied.access = (Arm64Producer.allocation initial).2.access) :
    ∃ writes : Arm64Producer.DeclarationStores (declaration (inputRegister i)) initial supplied value,
      CC.Star (CC.Step2 world)
        (.State Arm64ProgramFixture.f_arm64_execute_compile (stage (inputRegister i)) k
          (allocation initial).1 le before)
        trace (.State Arm64ProgramFixture.f_arm64_execute_compile (declaration (inputRegister i)).rest k
          (allocation initial).1 ((declaration (inputRegister i)).temps le value) writes.after) := by
  obtain ⟨writes, _, _, suffix⟩ := writeback (inputRegister i) initial supplied le k value access
  have call : CC.Star (CC.Step2 world)
      (.Callstate Arm64OriginCache.inputFunction [.Vint (6#32)]
        (continuation (inputRegister i) initial le k) before)
      trace (.Returnstate (.Vlong value) (continuation (inputRegister i) initial le k) supplied) :=
    .step _ _ _ _ _ _ (.external_function _ _ _ _ _ _ _ _ _ _ provider) (.refl _)
      (by simp [CC.E0, CC.Eapp])
  refine ⟨writes, ?_⟩
  simpa only [CC.E0, CC.Eapp, List.nil_append, List.append_nil] using
    star_trans (call_ready i initial before le k).sound (star_trans call suffix.sound)

theorem zero_initialized (initial before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (access : before.access = (Arm64Producer.allocation initial).2.access) :
    ∃ writes : Arm64Producer.DeclarationStores (declaration 30) initial before 0,
      InternalRun world 10
        (.State Arm64ProgramFixture.f_arm64_execute_compile (stage 30) k (allocation initial).1 le before)
        (.State Arm64ProgramFixture.f_arm64_execute_compile afterRegisters k (allocation initial).1
          (le.set (declaration 30).resultTemp (.Vlong 0)) writes.after) := by
  obtain ⟨writes, word, tag⟩ := storage 30 initial before 0 access
  have same : CC.Integers.Int.eq (declaration 30).index (30#32) = true := by
    rw [Arm64ProgramEntryRegisterSource.indices]
    rfl
  have run := Arm64Producer.declaration_zero_body world Arm64ProgramFixture.f_arm64_execute_compile
    (allocation initial).1 Arm64ProgramEntryRegisters.gpr_layout (declaration 30) initial before le k same writes word tag
  refine ⟨writes, ?_⟩
  rw [Arm64ProgramEntryRegisterSource.source, ← Arm64ProgramEntryRegisterSource.last_rest]
  exact internalRun_of_steps run.2 run.1

private theorem zero_separate : ∀ selected (i : Fin 30),
    tableCellName selected (inputRegister i) ≠ (declaration 30).word ∧
    tableCellName selected (inputRegister i) ≠ (declaration 30).tag := by decide +kernel

private theorem caches_separate : ∀ returns (i : Fin 31),
    Arm64Producer.baseName returns ≠ (declaration i).word ∧
    Arm64Producer.baseName returns ≠ (declaration i).tag ∧
    Arm64Producer.validName returns ≠ (declaration i).word ∧
    Arm64Producer.validName returns ≠ (declaration i).tag := by decide +kernel

def wordValue (values : Fin 31 → BitVec 64) (i : Fin 31) : BitVec 64 :=
  if i.val = 30 then 0 else values i

/-- All30 provider visits and the real x30 branch, using the shared induction. -/
theorem initialized (initial before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (values : Fin 31 → BitVec 64) (provider : ProviderAt world initial values)
    (access : before.access = (Arm64Producer.allocation initial).2.access) :
    ∃ blocks : Bool → Fin 31 → CC.Block, ∃ after finalLe, ∃ traces : List CC.Trace,
      traces.length = 30 ∧
      (∀ selected i, (Arm64Producer.allocation initial).1.get (tableCellName selected i) =
        some (blocks selected i, tableCellType selected)) ∧
      CC.Star (CC.Step2 world)
        (.State Arm64ProgramFixture.f_arm64_execute_compile (stage 0) k (allocation initial).1 le before)
        traces.flatten (.State Arm64ProgramFixture.f_arm64_execute_compile afterRegisters k
          (allocation initial).1 finalLe after) ∧
      (∀ i, CC.Mem.load .Mint64 after (blocks false i) 0 = some (.Vlong (wordValue values i)) ∧
        CC.Mem.load .Mint8unsigned after (blocks true i) 0 = some (.Vint 0)) ∧
      (∀ id ty block, (Arm64Producer.allocation initial).1.get id = some (block, ty) →
        (∀ i, id ≠ (declaration i).word ∧ id ≠ (declaration i).tag) → ∀ chunk ofs,
        CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      (∀ id, (∀ i, id ≠ (declaration i).inputTemp ∧ id ≠ (declaration i).resultTemp) →
        finalLe.get id = le.get id) ∧
      FrameBelow initial.nextblock before after ∧ after.access = before.access ∧ after.nextblock = before.nextblock := by
  classical
  have live : ∀ selected (i : Fin 31), ∃ block,
      (Arm64Producer.allocation initial).1.get (tableCellName selected i) = some (block, tableCellType selected) := by
    intro selected i
    obtain ⟨block, bound, _⟩ := Arm64Producer.local_storage initial _ _ (Arm64Producer.table_cell_declaration selected i)
    exact ⟨block, bound⟩
  let blocks : Bool → Fin 31 → CC.Block := fun selected i => Classical.choose (live selected i)
  have bindings : ∀ selected i, (Arm64Producer.allocation initial).1.get (tableCellName selected i) =
      some (blocks selected i, tableCellType selected) := fun selected i => Classical.choose_spec (live selected i)
  have names : ∀ i, (declaration i).word = (Arm64Producer.registerDeclaration i).word ∧
      (declaration i).tag = (Arm64Producer.registerDeclaration i).tag :=
    fun i => ⟨(Arm64ProgramEntryRegisterSource.metadata i).1, (Arm64ProgramEntryRegisterSource.metadata i).2.1⟩
  obtain ⟨middle, middleLe, traces, length, run, reads, _, locals, temps, frame, middleAccess, middleNext⟩ :=
    Arm64ProducerGprInputs.run_suffix_body world Arm64ProgramFixture.f_arm64_execute_compile
      (allocation initial).1 declaration stage names Arm64ProgramEntryRegisterSource.chain initial
      (fun selected i => blocks selected (inputRegister i)) (fun selected i => bindings selected (inputRegister i))
      values provider (fun i before supplied le k trace call access => by
        obtain ⟨writes, path⟩ := input_returns i initial before supplied le k _ trace call access
        exact ⟨writes.wordBlock, writes.tagBlock, writes.after, writes.wordBinding, writes.tagBinding,
          path, writes.wordRead, writes.tagRead, writes.otherLocals, writes.frame, writes.access, writes.next⟩)
      30 0 rfl before le k access
  obtain ⟨writes, zero⟩ := zero_initialized initial middle middleLe k (middleAccess.trans access)
  have wb := writes.wordBinding
  have tb := writes.tagBinding
  rw [(names 30).1] at wb
  rw [(names 30).2] at tb
  have wordBlock : writes.wordBlock = blocks false 30 :=
    congrArg Prod.fst (Option.some.inj (wb.symm.trans (bindings false 30)))
  have tagBlock : writes.tagBlock = blocks true 30 :=
    congrArg Prod.fst (Option.some.inj (tb.symm.trans (bindings true 30)))
  refine ⟨blocks, writes.after, middleLe.set (declaration 30).resultTemp (.Vlong 0), traces, length, bindings,
    ?_, ?_, ?_, ?_, frame.trans writes.frame, writes.access.trans middleAccess, writes.next.trans middleNext⟩
  · simpa only [CC.E0, CC.Eapp, List.append_nil] using star_trans run zero.sound
  · intro i
    by_cases last : i = 30
    · subst i
      have word := writes.wordRead
      have tag := writes.tagRead
      rw [wordBlock] at word
      rw [tagBlock] at tag
      exact ⟨word, tag⟩
    · have nonlast : i.val ≠ 30 := fun same => last (Fin.ext same)
      let j : Fin 30 := ⟨i.val, by have bound := i.isLt; omega⟩
      have same : inputRegister j = i := Fin.ext rfl
      have keepWord := writes.otherLocals _ _ _ (bindings false (inputRegister j))
        (zero_separate false j).1 (zero_separate false j).2 .Mint64 0
      have keepTag := writes.otherLocals _ _ _ (bindings true (inputRegister j))
        (zero_separate true j).1 (zero_separate true j).2 .Mint8unsigned 0
      have prior := reads j (Nat.zero_le _)
      simpa only [wordValue, ite_eq_right nonlast, same] using
        And.intro (keepWord.trans prior.1) (keepTag.trans prior.2)
  · intro id ty block bound different chunk ofs
    exact (writes.otherLocals id ty block bound (different 30).1 (different 30).2 chunk ofs).trans
      (locals id ty block bound (fun i => different (inputRegister i)) chunk ofs)
  · intro id different
    exact (CC.PTree.gso _ _ _ _ (Ne.symm (different 30).2)).trans
      (temps id (fun i => different (inputRegister i)))

/-- The readback blocks also have their real production-environment bindings. -/
theorem actual_cell_binding (initial : CC.Mem) (selected : Bool) (i : Fin 31) (block : CC.Block)
    (bound : (Arm64Producer.allocation initial).1.get (tableCellName selected i) =
      some (block, tableCellType selected)) :
    (allocation initial).1.get (tableCellName selected i) = some (block, tableCellType selected) := by
  have actual := Arm64ProgramEntryAllocation.local_binding initial _ _ _ bound
  have name : Arm64ProgramEntryAllocation.localName (tableCellName selected i) = tableCellName selected i := by
    cases selected
    · change Arm64ProgramEntryAllocation.localName (Arm64Producer.registerDeclaration i).word = (Arm64Producer.registerDeclaration i).word
      rw [← (Arm64ProgramEntryRegisterSource.metadata i).1]
      exact (Arm64ProgramEntryRegisterSource.storage_metadata i).2.2.2.1
    · change Arm64ProgramEntryAllocation.localName (Arm64Producer.registerDeclaration i).tag = (Arm64Producer.registerDeclaration i).tag
      rw [← (Arm64ProgramEntryRegisterSource.metadata i).2.1]
      exact (Arm64ProgramEntryRegisterSource.storage_metadata i).2.2.2.2.1
  rw [name] at actual
  cases selected <;> exact actual

/-- Real call entry through all31 register declarations. Provider contracts
remain explicit and each of the30 traces is retained in order. -/
theorem entry_initialized (initial : CC.Mem) (ctx : CC.Val) (k : CC.Cont)
    (values : Fin 31 → BitVec 64) (provider : ProviderAt world initial values) :
    ∃ blocks : Bool → Fin 31 → CC.Block, ∃ after finalLe, ∃ traces : List CC.Trace,
      traces.length = 30 ∧
      (∀ selected i, (Arm64Producer.allocation initial).1.get (tableCellName selected i) =
        some (blocks selected i, tableCellType selected)) ∧
      (∀ selected i, (allocation initial).1.get (tableCellName selected i) =
        some (blocks selected i, tableCellType selected)) ∧
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [ctx] k initial)
        traces.flatten (.State Arm64ProgramFixture.f_arm64_execute_compile afterRegisters k
          (allocation initial).1 finalLe after) ∧
      (∀ i, CC.Mem.load .Mint64 after (blocks false i) 0 = some (.Vlong (wordValue values i)) ∧
        CC.Mem.load .Mint8unsigned after (blocks true i) 0 = some (.Vint 0)) ∧
      Arm64ProgramEntryInputs.CacheReadbacks initial after ∧ finalLe.get Arm64ProgramFixture._ctx = some ctx ∧
      FrameBelow initial.nextblock initial after ∧ after.access = (allocation initial).2.access ∧
      after.nextblock = (allocation initial).2.nextblock := by
  obtain ⟨ready, prefixRun, caches, frame, access, next⟩ := Arm64ProgramEntryInputs.entry_setup initial ctx k
  have canonical : ready.access = (Arm64Producer.allocation initial).2.access :=
    access.trans (congrArg CC.Mem.access (Arm64ProgramEntryAllocation.allocation_corresponds initial).1.symm)
  obtain ⟨blocks, after, finalLe, traces, length, bindings, run, reads, locals, temps,
      resultFrame, resultAccess, resultNext⟩ := initialized initial ready (Arm64ProgramEntryCall.initialTemps ctx) k values provider canonical
  rw [Arm64ProgramEntryRegisterSource.first_stage] at run
  refine ⟨blocks, after, finalLe, traces, length, bindings, (fun selected i => actual_cell_binding initial selected i _ (bindings selected i)),
    ?_, reads, ?_, ?_, frame.trans resultFrame,
    resultAccess.trans access, resultNext.trans next⟩
  · simpa only [CC.E0, CC.Eapp, List.nil_append] using star_trans prefixRun.sound run
  · intro returns
    obtain ⟨cache, baseBinding, validBinding, base, valid⟩ := caches returns
    refine ⟨cache, baseBinding, validBinding, ?_, ?_⟩
    · exact (locals _ _ _ cache.baseBinding (fun i => ⟨(caches_separate returns i).1,
        (caches_separate returns i).2.1⟩) .Mint64 0).trans base
    · exact (locals _ _ _ cache.validBinding (fun i => ⟨(caches_separate returns i).2.2.1,
        (caches_separate returns i).2.2.2⟩) .Mint8unsigned 0).trans valid
  · exact (temps _ (fun i => ⟨Ne.symm (Arm64ProgramEntryRegisterSource.storage_metadata i).2.2.2.2.2.1,
      Ne.symm (Arm64ProgramEntryRegisterSource.storage_metadata i).2.2.2.2.2.2⟩)).trans
      (Arm64ProgramEntryCall.initial_context ctx)

end KProgFormal.ClightRefinement.Arm64ProgramEntryGprInputs
