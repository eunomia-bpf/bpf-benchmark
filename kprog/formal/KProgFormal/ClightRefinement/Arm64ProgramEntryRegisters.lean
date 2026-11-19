import KProgFormal.ClightRefinement.Arm64ProgramEntryInputs

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryRegisters

open Arm64ProgramEntryAllocation (world allocation)
open Arm64ProgramEntryInputs (firstDeclaration nextRegisterStage inputContinuation CacheReadbacks)
open Arm64ProgramEntryCall (initialTemps)

/-- Only the actual named GPR record and its x offset are required. -/
theorem gpr_layout : Arm64Producer.GprLayout world := by
  unfold Arm64Producer.GprLayout
  decide +kernel

private theorem actual_binding (initial : CC.Mem) (id : CC.Ident) (block : CC.Block) (ty : CC.Ty)
    (bound : (Arm64Producer.allocation initial).1.get id = some (block, ty))
    (name : Arm64ProgramEntryAllocation.localName id = id)
    (type : Arm64ProgramEntryAllocation.localType ty = ty) :
    (allocation initial).1.get id = some (block, ty) := by
  have actual := Arm64ProgramEntryAllocation.local_binding initial id block ty bound
  rw [name, type] at actual
  exact actual

/-- All temporaries outside the two returned-value names remain unchanged. -/
theorem other_temporaries (temps : CC.TempEnv) (value : BitVec 64) (id : CC.Ident)
    (notInput : firstDeclaration.inputTemp ≠ id) (notResult : firstDeclaration.resultTemp ≠ id) :
    (firstDeclaration.temps temps value).get id = temps.get id := by
  unfold Arm64Producer.RegisterDeclaration.temps
  rw [CC.PTree.gso _ _ _ _ notResult, CC.PTree.gso _ _ _ _ notInput]

theorem context_retained (ctx : CC.Val) (value : BitVec 64) :
    (firstDeclaration.temps (initialTemps ctx) value).get Arm64ProgramFixture._ctx = some ctx := by
  rw [other_temporaries _ _ _ (by decide +kernel) (by decide +kernel)]
  exact Arm64ProgramEntryCall.initial_context ctx

/-- The actual continuation consumes a supplied word and executes both stores
in nine internal steps, using the source memory witness without replay. -/
theorem first_writeback (initial supplied : CC.Mem) (temps : CC.TempEnv) (k : CC.Cont)
    (value : BitVec 64) (access : supplied.access = (allocation initial).2.access) :
    ∃ writes : Arm64Producer.DeclarationStores firstDeclaration initial supplied value,
      (allocation initial).1.get firstDeclaration.word =
        some (writes.wordBlock, .Tunion Arm64Entry._arm64_sim_gpr CC.noattr) ∧
      (allocation initial).1.get firstDeclaration.tag = some (writes.tagBlock, CC.tuchar) ∧
      InternalRun world 9
        (.Returnstate (.Vlong value) (inputContinuation initial temps k) supplied)
        (.State Arm64ProgramFixture.f_arm64_execute_compile nextRegisterStage k
          (allocation initial).1 (firstDeclaration.temps temps value) writes.after) := by
  have sourceAccess : supplied.access = (Arm64Producer.allocation initial).2.access :=
    access.trans (congrArg CC.Mem.access (Arm64ProgramEntryAllocation.allocation_corresponds initial).1.symm)
  obtain ⟨writes⟩ := Arm64Producer.declaration_stores_for firstDeclaration initial supplied value
    (by decide +kernel) (by decide +kernel) (by decide +kernel) sourceAccess
  have word := actual_binding initial firstDeclaration.word writes.wordBlock
    (.Tunion Arm64Entry._arm64_sim_gpr CC.noattr) writes.wordBinding (by decide +kernel) (by rfl)
  have tag := actual_binding initial firstDeclaration.tag writes.tagBlock CC.tuchar
    writes.tagBinding (by decide +kernel) (by rfl)
  have run := Arm64Producer.declaration_return_body world Arm64ProgramFixture.f_arm64_execute_compile
    (allocation initial).1 gpr_layout firstDeclaration initial supplied temps k value writes word tag
  exact ⟨writes, word, tag, internalRun_of_steps run.2 run.1⟩

/-- Follow one stated provider outcome in the real production function.
Framing and readbacks in the store witness are relative to supplied memory. -/
theorem first_input_returns (initial before supplied : CC.Mem) (temps : CC.TempEnv) (k : CC.Cont)
    (value : BitVec 64) (trace : CC.Trace)
    (provider : CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv world.genv_genv)
      [.Vint (6#32)] before trace (.Vlong value) supplied)
    (access : supplied.access = (allocation initial).2.access) :
    ∃ writes : Arm64Producer.DeclarationStores firstDeclaration initial supplied value,
      (allocation initial).1.get firstDeclaration.word =
        some (writes.wordBlock, .Tunion Arm64Entry._arm64_sim_gpr CC.noattr) ∧
      (allocation initial).1.get firstDeclaration.tag = some (writes.tagBlock, CC.tuchar) ∧
      CC.Star (CC.Step2 world)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryInputs.registerStage k
          (allocation initial).1 temps before)
        trace (.State Arm64ProgramFixture.f_arm64_execute_compile nextRegisterStage k
          (allocation initial).1 (firstDeclaration.temps temps value) writes.after) := by
  obtain ⟨writes, word, tag, suffix⟩ := first_writeback initial supplied temps k value access
  have externalStep : CC.Star (CC.Step2 world)
      (.Callstate Arm64OriginCache.inputFunction [.Vint (6#32)] (inputContinuation initial temps k) before)
      trace (.Returnstate (.Vlong value) (inputContinuation initial temps k) supplied) :=
    .step _ _ _ _ _ _ (.external_function _ _ _ _ _ _ _ _ _ _ provider) (.refl _)
      (by simp [CC.E0, CC.Eapp])
  refine ⟨writes, word, tag, ?_⟩
  simpa only [CC.E0, CC.Eapp, List.nil_append, List.append_nil] using
    star_trans (Arm64ProgramEntryInputs.first_call_ready initial before temps k).sound
      (star_trans externalStep suffix.sound)

private theorem cache_readbacks (initial before supplied : CC.Mem) (value : BitVec 64)
    (writes : Arm64Producer.DeclarationStores firstDeclaration initial supplied value)
    (caches : CacheReadbacks initial before)
    (preserved : ∀ id ty block, (Arm64Producer.allocation initial).1.get id = some (block, ty) →
      ∀ chunk ofs, CC.Mem.load chunk supplied block ofs = CC.Mem.load chunk before block ofs) :
    CacheReadbacks initial writes.after := by
  intro returns
  obtain ⟨locals, baseBinding, validBinding, base, valid⟩ := caches returns
  refine ⟨locals, baseBinding, validBinding, ?_, ?_⟩
  · have keep := writes.otherLocals _ _ _ locals.baseBinding
      (by cases returns <;> decide +kernel) (by cases returns <;> decide +kernel) .Mint64 0
    exact keep.trans ((preserved _ _ _ locals.baseBinding .Mint64 0).trans base)
  · have keep := writes.otherLocals _ _ _ locals.validBinding
      (by cases returns <;> decide +kernel) (by cases returns <;> decide +kernel) .Mint8unsigned 0
    exact keep.trans ((preserved _ _ _ locals.validBinding .Mint8unsigned 0).trans valid)

/-- Compose actual call entry with a framed first-provider contract. The
trace, returned word and supplied memory stay explicit; availability and
preservation are invocation-environment premises, as in the source contracts. -/
theorem entry_first_returns (initial : CC.Mem) (ctx : CC.Val) (k : CC.Cont) (value : BitVec 64)
    (provider : ∀ before : CC.Mem, before.access = (allocation initial).2.access →
      ∃ trace supplied,
        CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv world.genv_genv)
          [.Vint (6#32)] before trace (.Vlong value) supplied ∧
        supplied.access = before.access ∧ supplied.nextblock = before.nextblock ∧
        FrameBelow initial.nextblock before supplied ∧
        ∀ id ty block, (Arm64Producer.allocation initial).1.get id = some (block, ty) →
          ∀ chunk ofs, CC.Mem.load chunk supplied block ofs = CC.Mem.load chunk before block ofs) :
    ∃ trace supplied, ∃ writes : Arm64Producer.DeclarationStores firstDeclaration initial supplied value,
      (allocation initial).1.get firstDeclaration.word =
        some (writes.wordBlock, .Tunion Arm64Entry._arm64_sim_gpr CC.noattr) ∧
      (allocation initial).1.get firstDeclaration.tag = some (writes.tagBlock, CC.tuchar) ∧
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [ctx] k initial)
        trace (.State Arm64ProgramFixture.f_arm64_execute_compile nextRegisterStage k
          (allocation initial).1 (firstDeclaration.temps (initialTemps ctx) value) writes.after) ∧
      CacheReadbacks initial writes.after ∧ FrameBelow initial.nextblock initial writes.after ∧
      writes.after.access = (allocation initial).2.access ∧
      writes.after.nextblock = (allocation initial).2.nextblock := by
  obtain ⟨before, prefixRun, caches, frame, access, next⟩ := Arm64ProgramEntryInputs.first_input_ready initial ctx k
  obtain ⟨trace, supplied, outcome, suppliedAccess, suppliedNext, suppliedFrame, preserved⟩ := provider before access
  obtain ⟨writes, word, tag, suffix⟩ := first_writeback initial supplied (initialTemps ctx) k value
    (suppliedAccess.trans access)
  have externalStep : CC.Star (CC.Step2 world)
      (.Callstate Arm64OriginCache.inputFunction [.Vint (6#32)]
        (inputContinuation initial (initialTemps ctx) k) before)
      trace (.Returnstate (.Vlong value) (inputContinuation initial (initialTemps ctx) k) supplied) :=
    .step _ _ _ _ _ _ (.external_function _ _ _ _ _ _ _ _ _ _ outcome) (.refl _)
      (by simp [CC.E0, CC.Eapp])
  refine ⟨trace, supplied, writes, word, tag, ?_, cache_readbacks initial before supplied value writes caches preserved,
    frame.trans (suppliedFrame.trans writes.frame), writes.access.trans (suppliedAccess.trans access),
    writes.next.trans (suppliedNext.trans next)⟩
  simpa only [CC.E0, CC.Eapp, List.nil_append, List.append_nil] using
    star_trans prefixRun.sound (star_trans externalStep suffix.sound)

end KProgFormal.ClightRefinement.Arm64ProgramEntryRegisters
