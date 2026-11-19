import KProgFormal.ClightRefinement.Arm64ProducerTables

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Producer

structure FlagDeclaration where
  name : CC.Ident
  inputTemp : CC.Ident
  rest : CC.Stmt

def FlagDeclaration.store (d : FlagDeclaration) : CC.Stmt :=
  .Sassign (.Evar d.name CC.tuchar)
    (.Ebinop .Oand (.Etempvar d.inputTemp CC.tulong) (.Econst_int (1#32) CC.tint) CC.tulong)

def FlagDeclaration.body (d : FlagDeclaration) : CC.Stmt :=
  .Ssequence (.Ssequence (.Scall (some d.inputTemp)
    (.Evar Arm64Entry._native_lab_entry_input (.Tfunction [CC.tuint] CC.tulong CC.cc_default))
    [.Econst_int (6#32) CC.tint]) d.store) d.rest

private def flagRows : List (CC.Stmt × FlagDeclaration) := by
  run_tac do
    let mut body ← Lean.Elab.Term.elabTerm (← `(afterPointerTables)) none
    let mut rows : Array Lean.Expr := #[]
    for _ in [:4] do
      let original := body
      let outer ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body)
      unless outer.isAppOfArity ``CC.Stmt.Ssequence 2 do
        throwError "producer flag declaration sequence changed"
      let inner ← Lean.Meta.withTransparency .all (Lean.Meta.whnf outer.getAppArgs[0]!)
      unless inner.isAppOfArity ``CC.Stmt.Ssequence 2 do
        throwError "producer flag call/store sequence changed"
      let call ← Lean.Meta.withTransparency .all (Lean.Meta.whnf inner.getAppArgs[0]!)
      let store ← Lean.Meta.withTransparency .all (Lean.Meta.whnf inner.getAppArgs[1]!)
      unless call.isAppOfArity ``CC.Stmt.Scall 3 && store.isAppOfArity ``CC.Stmt.Sassign 2 do
        throwError "producer flag call/store changed"
      let result ← Lean.Meta.withTransparency .all (Lean.Meta.whnf call.getAppArgs[0]!)
      let target ← Lean.Meta.withTransparency .all (Lean.Meta.whnf store.getAppArgs[0]!)
      unless result.isAppOfArity ``Option.some 2 && target.isAppOfArity ``CC.Expr.Evar 2 do
        throwError "producer flag local names changed"
      let declaration ← Lean.Meta.mkAppM ``FlagDeclaration.mk
        #[target.getAppArgs[0]!, result.getAppArgs[1]!, outer.getAppArgs[1]!]
      rows := rows.push (← Lean.Meta.mkAppM ``Prod.mk #[original, declaration])
      body := outer.getAppArgs[1]!
    let rowType ← Lean.Meta.mkAppM ``Prod #[Lean.mkConst ``CC.Stmt, Lean.mkConst ``FlagDeclaration]
    let result ← Lean.Meta.mkListLit rowType rows.toList
    Lean.Elab.Tactic.closeMainGoal `actual_producer_flags result

def flagDeclaration (i : Fin 4) : FlagDeclaration :=
  (flagRows[i.val]'(by simpa only [flagRows, List.length_cons, List.length_nil, Nat.reduceAdd] using i.isLt)).2

def flagDeclarationStage (i : Fin 4) : CC.Stmt :=
  (flagRows[i.val]'(by simpa only [flagRows, List.length_cons, List.length_nil, Nat.reduceAdd] using i.isLt)).1

theorem flag_declarations_source : ∀ i : Fin 4,
    flagDeclarationStage i = (flagDeclaration i).body ∧
    ((flagDeclaration i).name, CC.tuchar) ∈ producer.fn_vars := by
  simp only [Fin.forall_fin_succ, Fin.forall_fin_zero]
  repeat' apply And.intro
  all_goals first | rfl | decide +kernel

theorem flag_names :
    (flagDeclaration 0).name = Arm64Entry.___a64_n ∧
    (flagDeclaration 1).name = Arm64Entry.___a64_z ∧
    (flagDeclaration 2).name = Arm64Entry.___a64_c ∧
    (flagDeclaration 3).name = Arm64Entry.___a64_v := by decide +kernel

theorem first_flag_stage : flagDeclarationStage 0 = afterPointerTables := by rfl

theorem flag_declarations_chain : ∀ i : Fin 3,
    (flagDeclaration ⟨i.val, Nat.lt_trans i.isLt (by decide)⟩).rest =
      flagDeclarationStage ⟨i.val + 1, Nat.add_lt_add_right i.isLt 1⟩ := by
  simp only [Fin.forall_fin_succ, Fin.forall_fin_zero]
  repeat' apply And.intro
  all_goals first | rfl | trivial

/-- The exact exported unsigned-byte cast of the masked input word. -/
def flagWord (value : BitVec 64) : CC.Integers.Int :=
  CC.Cop.castIntInt .I8 .Unsigned
    (CC.Integers.Int.repr (CC.Integers.Int64.unsigned (CC.Integers.Int64.and value (1#64))))

theorem flag_word_bit (value : BitVec 64) : flagWord value = (0#32) ∨ flagWord value = (1#32) := by
  have bit : (value.toNat : Int) % 2 = 0 ∨ (value.toNat : Int) % 2 = 1 := by omega
  rcases bit with zero | one <;>
    simp [flagWord, CC.Cop.castIntInt, CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext,
      CC.Integers.Int.repr, CC.Integers.MI.repr, CC.Integers.Int64.unsigned, CC.Integers.MI.unsigned,
      CC.Integers.Int64.and, CC.Integers.MI.and, *]

def FlagDeclaration.continuationFor (d : FlagDeclaration) (f : CC.Function) (e : CC.Env)
    (le : CC.TempEnv) (k : CC.Cont) : CC.Cont :=
  .Kcall (some d.inputTemp) f e le (.Kseq d.store (.Kseq d.rest k))

def FlagDeclaration.continuation (d : FlagDeclaration) (m : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) : CC.Cont :=
  d.continuationFor producer (allocation m).1 le k

/-- Shared internal call prefix with the real function, environment and symbol. -/
theorem flag_call_body (world : CC.CGenv) (f : CC.Function) (e : CC.Env) (inputBlock : CC.Block)
    (binding : CC.Genv.findSymbol world.genv_genv Arm64Entry._native_lab_entry_input = some inputBlock ∧
      CC.Genv.findFunctPtr world.genv_genv inputBlock = some Arm64OriginCache.inputFunction)
    (d : FlagDeclaration) (memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (unshadowed : e.get Arm64Entry._native_lab_entry_input = none) :
    steps world 3 (.State f d.body k e le memory) =
      some (CC.E0, .Callstate Arm64OriginCache.inputFunction [.Vint (6#32)]
        (d.continuationFor f e le k) memory) ∧
    InternalPath world 3 (.State f d.body k e le memory) := by
  simp +decide [steps, InternalPath, InternalState, FlagDeclaration.body, FlagDeclaration.continuationFor,
    CC.doStep, CC.doEvalExpr, CC.doEvalExprlist, CC.lvalOfVar, CC.doDerefLoc, CC.accessMode, CC.typeof,
    CC.tptr, CC.tint, CC.tuint, CC.tulong, CC.Cop.classifyFun, CC.Cop.semCast, CC.Cop.classifyCast,
    CC.Cop.castIntInt, CC.Genv.findFunct, CC.Integers.Ptrofs.eq, CC.Integers.Ptrofs.zero,
    CC.Integers.MI.zero, CC.typeOfFundef, Arm64OriginCache.inputFunction,
    Arm64OriginCache.inputEF, unshadowed, binding.1, binding.2,
    CC.Integers.Int.repr, CC.Integers.MI.repr, CC.E0, CC.Eapp]

theorem flag_input_ready_bound (world : CC.CGenv)
    (binding : CC.Genv.findSymbol world.genv_genv Arm64Entry._native_lab_entry_input =
        some (CC.Positive.ofNat 64) ∧
      CC.Genv.findFunctPtr world.genv_genv (CC.Positive.ofNat 64) = some Arm64OriginCache.inputFunction) (i : Fin 4) (m memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) :
    InternalRun world 3 (.State producer (flagDeclarationStage i) k (allocation m).1 le memory)
      (.Callstate Arm64OriginCache.inputFunction [.Vint (6#32)]
        ((flagDeclaration i).continuation m le k) memory) := by
  rw [(flag_declarations_source i).1]
  have unshadowed : (allocation m).1.get Arm64Entry._native_lab_entry_input = none := by
    have notLocal : Arm64Entry._native_lab_entry_input ∉ CC.varNames producer.fn_vars := by decide +kernel
    simpa only [CC.emptyEnv, CC.PTree.gempty] using CC.allocVariables_env_other
      (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation m)).symm) notLocal
  have run := flag_call_body world producer (allocation m).1 (CC.Positive.ofNat 64)
    binding (flagDeclaration i) memory le k unshadowed
  exact internalRun_of_steps run.2 run.1

theorem flag_return_body (world : CC.CGenv) (f : CC.Function) (e : CC.Env)
    (d : FlagDeclaration) (supplied after : CC.Mem)
    (le : CC.TempEnv) (k : CC.Cont) (value : BitVec 64) (block : CC.Block)
    (binding : e.get d.name = some (block, CC.tuchar))
    (stored : CC.Mem.storev .Mint8unsigned supplied (.Vptr block (0#64))
      (.Vint (flagWord value)) = some after) :
    steps world 4 (.Returnstate (.Vlong value) (d.continuationFor f e le k) supplied) =
      some (CC.E0, .State f d.rest k e
        (le.set d.inputTemp (.Vlong value)) after) ∧
    InternalPath world 4 (.Returnstate (.Vlong value) (d.continuationFor f e le k) supplied) := by
  simp +decide [steps, InternalPath, InternalState, FlagDeclaration.continuationFor, FlagDeclaration.store,
    CC.doStep, CC.setOpttemp, CC.PTree.gss, CC.doEvalExpr, CC.doEvalLvalue, CC.lvalOfVar,
    CC.doAssignLoc, CC.typeof, CC.accessMode, CC.Cop.semBinaryOperation, CC.Cop.semAnd,
    CC.Cop.semBinarith, CC.Cop.classifyBinarith, CC.Cop.binarithType, CC.Cop.semCast,
    CC.Cop.classifyCast, CC.Cop.castIntInt, CC.Cop.castIntLong, CC.typeconv,
    CC.removeAttributes, CC.tattr, CC.tuchar, CC.tulong, CC.tint, flagWord,
    CC.Integers.Int.repr, CC.Integers.Int64.repr, CC.Integers.MI.repr,
    CC.Integers.Int64.unsigned, CC.Integers.MI.unsigned, CC.Integers.Int.signed,
    CC.Integers.MI.signed, CC.Integers.Int64.and, CC.Integers.MI.and, CC.Integers.Int64.loword,
    BitVec.ofInt_natCast, BitVec.ofNat_toNat,
    CC.Integers.Ptrofs.zero, CC.Integers.MI.zero, CC.E0, CC.Eapp, binding] at stored ⊢
  simp [stored, CC.doStep, CC.E0, CC.Eapp, InternalState, InternalPath, steps]

/-- Each actual flag input outcome writes the low bit through its real byte
local. Provider trace and post-memory are retained, with explicit permissions. -/
theorem flag_input_returns_body (world : CC.CGenv) (f : CC.Function) (e : CC.Env)
    (inputBlock : CC.Block)
    (inputBinding : CC.Genv.findSymbol world.genv_genv Arm64Entry._native_lab_entry_input = some inputBlock ∧
      CC.Genv.findFunctPtr world.genv_genv inputBlock = some Arm64OriginCache.inputFunction)
    (unshadowed : e.get Arm64Entry._native_lab_entry_input = none)
    (d : FlagDeclaration) (member : (d.name, CC.tuchar) ∈ producer.fn_vars)
    (m before supplied : CC.Mem)
    (actualBinding : ∀ block, (allocation m).1.get d.name = some (block, CC.tuchar) →
      e.get d.name = some (block, CC.tuchar))
    (le : CC.TempEnv) (k : CC.Cont) (value : BitVec 64) (trace : CC.Trace)
    (provider : CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv world.genv_genv)
      [.Vint (6#32)] before trace (.Vlong value) supplied)
    (access : supplied.access = (allocation m).2.access) :
    ∃ block after, (allocation m).1.get d.name = some (block, CC.tuchar) ∧
      CC.Star (CC.Step2 world)
        (.State f d.body k e le before)
        trace (.State f d.rest k e (le.set d.inputTemp (.Vlong value)) after) ∧
      CC.Mem.loadv .Mint8unsigned after (.Vptr block 0) = some (.Vint (flagWord value)) ∧
      (flagWord value = (0#32) ∨ flagWord value = (1#32)) ∧
      (∀ id ty other, (allocation m).1.get id = some (other, ty) → id ≠ d.name →
        ∀ chunk ofs, CC.Mem.load chunk after other ofs = CC.Mem.load chunk supplied other ofs) ∧
      FrameBelow m.nextblock supplied after ∧ after.access = supplied.access ∧
      after.nextblock = supplied.nextblock := by
  obtain ⟨block, binding, fresh, writable⟩ := scalar_local m d.name CC.tuchar .Mint8unsigned
    member rfl (by decide)
  obtain ⟨after, stored, afterAccess⟩ :=
    create_store m supplied .Mint8unsigned block (.Vint (flagWord value)) access writable
  have suffix := flag_return_body world f e d supplied after le k value block (actualBinding block binding) stored
  have call : CC.Star (CC.Step2 world)
      (.Callstate Arm64OriginCache.inputFunction [.Vint (6#32)] (d.continuationFor f e le k) before)
      trace (.Returnstate (.Vlong value) (d.continuationFor f e le k) supplied) :=
    .step _ _ _ _ _ _ (.external_function _ _ _ _ _ _ _ _ _ _ provider) (.refl _)
      (by simp [CC.E0, CC.Eapp])
  have prefixRun := flag_call_body world f e inputBlock inputBinding d before le k unshadowed
  refine ⟨block, after, binding, ?_, ?_, flag_word_bit value, ?_, FrameBelow.store fresh stored,
    afterAccess.trans access.symm, CC.Mem.store_nextblock stored⟩
  · simpa only [CC.E0, CC.Eapp, List.nil_append, List.append_nil] using
      star_trans (internalRun_of_steps prefixRun.2 prefixRun.1).sound
        (star_trans call (internalRun_of_steps suffix.2 suffix.1).sound)
  · have load := CC.Mem.load_store_same stored
    rcases flag_word_bit value with zero | one <;>
      simpa [CC.Mem.loadv, CC.Integers.Ptrofs.unsigned, CC.Integers.MI.unsigned,
        CC.Val.loadResult, CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, *] using load
  · intro id ty other bound different chunk ofs
    have distinct := (allocated_local_storage
      (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation m)).symm)).2
    exact CC.Mem.load_store_other stored chunk other ofs
      (.inl (distinct _ _ _ _ bound binding different))

theorem flag_input_returns_bound (world : CC.CGenv)
    (inputBinding : CC.Genv.findSymbol world.genv_genv Arm64Entry._native_lab_entry_input =
        some (CC.Positive.ofNat 64) ∧
      CC.Genv.findFunctPtr world.genv_genv (CC.Positive.ofNat 64) = some Arm64OriginCache.inputFunction) (i : Fin 4) (m before supplied : CC.Mem)
    (le : CC.TempEnv) (k : CC.Cont) (value : BitVec 64) (trace : CC.Trace)
    (provider : CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv world.genv_genv)
      [.Vint (6#32)] before trace (.Vlong value) supplied)
    (access : supplied.access = (allocation m).2.access) :
    let d := flagDeclaration i
    ∃ block after, (allocation m).1.get d.name = some (block, CC.tuchar) ∧
      CC.Star (CC.Step2 world)
        (.State producer (flagDeclarationStage i) k (allocation m).1 le before)
        trace (.State producer d.rest k (allocation m).1 (le.set d.inputTemp (.Vlong value)) after) ∧
      CC.Mem.loadv .Mint8unsigned after (.Vptr block 0) = some (.Vint (flagWord value)) ∧
      (flagWord value = (0#32) ∨ flagWord value = (1#32)) ∧
      (∀ id ty other, (allocation m).1.get id = some (other, ty) → id ≠ d.name →
        ∀ chunk ofs, CC.Mem.load chunk after other ofs = CC.Mem.load chunk supplied other ofs) ∧
      FrameBelow m.nextblock supplied after ∧ after.access = supplied.access ∧
      after.nextblock = supplied.nextblock := by
  have unshadowed : (allocation m).1.get Arm64Entry._native_lab_entry_input = none := by
    have notLocal : Arm64Entry._native_lab_entry_input ∉ CC.varNames producer.fn_vars := by decide +kernel
    simpa only [CC.emptyEnv, CC.PTree.gempty] using CC.allocVariables_env_other
      (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation m)).symm) notLocal
  dsimp only
  rw [(flag_declarations_source i).1]
  exact flag_input_returns_body world producer (allocation m).1 (CC.Positive.ofNat 64)
    inputBinding unshadowed (flagDeclaration i) (flag_declarations_source i).2 m before supplied
    (fun _ bound => bound) le k value trace provider access

theorem flag_input_ready (i : Fin 4) (m memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) :
    InternalRun ge 3 (.State producer (flagDeclarationStage i) k (allocation m).1 le memory)
      (.Callstate Arm64OriginCache.inputFunction [.Vint (6#32)]
        ((flagDeclaration i).continuation m le k) memory) :=
  flag_input_ready_bound ge producer_input_binding i m memory le k

theorem flag_input_returns (i : Fin 4) (m before supplied : CC.Mem)
    (le : CC.TempEnv) (k : CC.Cont) (value : BitVec 64) (trace : CC.Trace)
    (provider : CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv ge.genv_genv)
      [.Vint (6#32)] before trace (.Vlong value) supplied)
    (access : supplied.access = (allocation m).2.access) :
    let d := flagDeclaration i
    ∃ block after, (allocation m).1.get d.name = some (block, CC.tuchar) ∧
      CC.Star (CC.Step2 ge)
        (.State producer (flagDeclarationStage i) k (allocation m).1 le before)
        trace (.State producer d.rest k (allocation m).1 (le.set d.inputTemp (.Vlong value)) after) ∧
      CC.Mem.loadv .Mint8unsigned after (.Vptr block 0) = some (.Vint (flagWord value)) ∧
      (flagWord value = (0#32) ∨ flagWord value = (1#32)) ∧
      (∀ id ty other, (allocation m).1.get id = some (other, ty) → id ≠ d.name →
        ∀ chunk ofs, CC.Mem.load chunk after other ofs = CC.Mem.load chunk supplied other ofs) ∧
      FrameBelow m.nextblock supplied after ∧ after.access = supplied.access ∧
      after.nextblock = supplied.nextblock :=
  flag_input_returns_bound ge producer_input_binding i m before supplied le k value trace provider access

/-- The actual pointer-table segment reaches the first flag call with both
complete tables still readable. No flag provider outcome is assumed here. -/
theorem pointer_tables_first_flag (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (access : before.access = (allocation m).2.access) :
    ∃ ready, InternalRun ge 189
        (.State producer (registerDeclaration 30).rest k (allocation m).1 le before)
        (.Callstate Arm64OriginCache.inputFunction [.Vint (6#32)]
          ((flagDeclaration 0).continuation m le k) ready) ∧
      (∀ tags, ∃ locals : TableLocals tags m, ∀ i,
        CC.Mem.load CC.Mptr ready locals.tableBlock (8 * (i.val : Int)) =
          some (.Vptr (locals.cellBlock i) 0)) ∧
      FrameBelow m.nextblock before ready ∧ ready.access = before.access ∧
      ready.nextblock = before.nextblock := by
  obtain ⟨ready, tables, reads, _, frame, finalAccess, next⟩ :=
    pointer_tables_initialized m before le k access
  refine ⟨ready, ?_, reads, frame, finalAccess, next⟩
  have call := flag_input_ready 0 m ready le k
  rw [first_flag_stage] at call
  exact tables.trans call

end KProgFormal.ClightRefinement.Arm64Producer
