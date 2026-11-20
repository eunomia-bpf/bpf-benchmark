import KProgFormal.ClightRefinement.Arm64ProgramEntryRawSetup
import KProgFormal.ClightRefinement.Arm64ProgramEntryResources

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryBody

open Arm64ProgramEntryAllocation (world allocation)

private def parts : List CC.Stmt × CC.Stmt := by
  run_tac do
    let mut body ← Lean.Elab.Term.elabTerm (← `(Arm64ProgramEntrySource.body)) none
    let mut rows : List Lean.Expr := []
    for _ in [:5] do
      body ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body)
      unless body.isAppOfArity ``CC.Stmt.Ssequence 2 do
        throwError "actual body setup sequence changed"
      rows := rows ++ [body.getAppArgs[0]!]
      body := body.getAppArgs[1]!
    Lean.Elab.Tactic.closeMainGoal `actual_body_setup
      (← Lean.Meta.mkAppM ``Prod.mk #[(← Lean.Meta.mkListLit (Lean.mkConst ``CC.Stmt) rows), body])

def afterSetup : CC.Stmt := by
  run_tac do
    let term ← Lean.Elab.Term.elabTerm (← `(parts.2)) none
    Lean.Elab.Tactic.closeMainGoal `actual_after_setup
      (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

def spAssignment : CC.Stmt := by
  run_tac do
    let row ← Lean.Elab.Term.elabTerm (← `(parts.1[0]'(by decide +kernel))) none
    Lean.Elab.Tactic.closeMainGoal `actual_sp_assignment
      (← Lean.Meta.withTransparency .all (Lean.Meta.whnf row))

def flagName (i : Fin 4) : CC.Ident :=
  if i.val = 0 then Arm64ProgramFixture.___a64_n else
  if i.val = 1 then Arm64ProgramFixture.___a64_z else
  if i.val = 2 then Arm64ProgramFixture.___a64_c else Arm64ProgramFixture.___a64_v

def flagTemp (i : Fin 4) : CC.Ident :=
  if i.val = 0 then Arm64ProgramFixture._t'172 else
  if i.val = 1 then Arm64ProgramFixture._t'171 else
  if i.val = 2 then Arm64ProgramFixture._t'170 else Arm64ProgramFixture._t'169

def contextName (i : Fin 3) : CC.Ident :=
  if i.val = 0 then Arm64ProgramFixture._mark else
  if i.val = 1 then Arm64ProgramFixture._priority else Arm64ProgramFixture._hash

def contextOffset (i : Fin 3) : Int := if i.val = 0 then 8 else if i.val = 1 then 32 else 68

def contextIndex (i : Fin 4) : Fin 3 := if i.val = 0 then 0 else if i.val = 1 then 1 else 2

def contextExpr (i : Fin 3) : CC.Expr :=
  .Efield (.Ederef (.Etempvar Arm64ProgramFixture._ctx
    (CC.tptr (.Tstruct Arm64ProgramFixture.___sk_buff CC.noattr)))
    (.Tstruct Arm64ProgramFixture.___sk_buff CC.noattr)) (contextName i) CC.tuint

def flagRhs (i : Fin 4) : CC.Expr :=
  .Ebinop .Oand (if i.val = 3 then
      .Ebinop .Oshr (.Etempvar (flagTemp i) CC.tuint) (.Econst_int (1#32) CC.tint) CC.tuint
    else .Etempvar (flagTemp i) CC.tuint) (.Econst_int (1#32) CC.tint) CC.tuint

def flagStatement (i : Fin 4) : CC.Stmt :=
  .Ssequence (.Sset (flagTemp i) (contextExpr (contextIndex i)))
    (.Sassign (.Evar (flagName i) CC.tuchar) (flagRhs i))

private def flagStages : List CC.Stmt := by
  run_tac do
    let mut body ← Lean.Elab.Term.elabTerm (← `(Arm64ProgramEntrySource.body)) none
    body ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body)
    body := body.getAppArgs[1]!
    let mut rows : List Lean.Expr := []
    for _ in [:4] do
      body ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body)
      unless body.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "actual flag stage changed"
      rows := rows ++ [body]
      body := body.getAppArgs[1]!
    Lean.Elab.Tactic.closeMainGoal `actual_flag_stages
      (← Lean.Meta.mkListLit (Lean.mkConst ``CC.Stmt) rows)

private def flag_stage_0 : CC.Stmt := by
  run_tac do
    let term ← Lean.Elab.Term.elabTerm (← `(flagStages[0]'(by decide +kernel))) none
    Lean.Elab.Tactic.closeMainGoal `actual_flag_stage
      (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private def flag_stage_1 : CC.Stmt := by
  run_tac do
    let term ← Lean.Elab.Term.elabTerm (← `(flagStages[1]'(by decide +kernel))) none
    Lean.Elab.Tactic.closeMainGoal `actual_flag_stage
      (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private def flag_stage_2 : CC.Stmt := by
  run_tac do
    let term ← Lean.Elab.Term.elabTerm (← `(flagStages[2]'(by decide +kernel))) none
    Lean.Elab.Tactic.closeMainGoal `actual_flag_stage
      (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private def flag_stage_3 : CC.Stmt := by
  run_tac do
    let term ← Lean.Elab.Term.elabTerm (← `(flagStages[3]'(by decide +kernel))) none
    Lean.Elab.Tactic.closeMainGoal `actual_flag_stage
      (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

def flagStage (n : Nat) : CC.Stmt :=
  if n = 0 then flag_stage_0 else if n = 1 then flag_stage_1 else
  if n = 2 then flag_stage_2 else if n = 3 then flag_stage_3 else afterSetup

theorem source : Arm64ProgramEntrySource.body =
    .Ssequence spAssignment (flagStage 0) := by
  run_tac Arm64ProgramEntryLinked.sourceEquality

theorem sp_source : spAssignment = .Sassign (.Evar Arm64ProgramFixture.___a64_sp CC.tlong)
    (.Eunop .Oneg (.Econst_int (32#32) CC.tint) CC.tint) := rfl

private def flag_head_0 : CC.Stmt := by
  run_tac do
    let stage ← Lean.Elab.Term.elabTerm (← `(flag_stage_0)) none
    let exposed ← Lean.Meta.withTransparency .all (Lean.Meta.whnf stage)
    Lean.Elab.Tactic.closeMainGoal `actual_flag_head exposed.getAppArgs[0]!

private theorem flag_head_source_0 : flag_head_0 = flagStatement 0 := by
  run_tac Arm64ProgramEntryLinked.sourceEquality

private theorem flag_source_0 : flagStage 0 =
    .Ssequence (flagStatement 0) (flagStage 1) := by
  have shape : flagStage 0 = .Ssequence flag_head_0 (flagStage 1) := by
    run_tac Arm64ProgramEntryLinked.sourceEquality
  exact shape.trans (congrArg (fun head => CC.Stmt.Ssequence head (flagStage 1)) flag_head_source_0)

private def flag_head_1 : CC.Stmt := by
  run_tac do
    let stage ← Lean.Elab.Term.elabTerm (← `(flag_stage_1)) none
    let exposed ← Lean.Meta.withTransparency .all (Lean.Meta.whnf stage)
    Lean.Elab.Tactic.closeMainGoal `actual_flag_head exposed.getAppArgs[0]!

private theorem flag_head_source_1 : flag_head_1 = flagStatement 1 := by
  run_tac Arm64ProgramEntryLinked.sourceEquality

private theorem flag_source_1 : flagStage 1 =
    .Ssequence (flagStatement 1) (flagStage 2) := by
  have shape : flagStage 1 = .Ssequence flag_head_1 (flagStage 2) := by
    run_tac Arm64ProgramEntryLinked.sourceEquality
  exact shape.trans (congrArg (fun head => CC.Stmt.Ssequence head (flagStage 2)) flag_head_source_1)

private def flag_head_2 : CC.Stmt := by
  run_tac do
    let stage ← Lean.Elab.Term.elabTerm (← `(flag_stage_2)) none
    let exposed ← Lean.Meta.withTransparency .all (Lean.Meta.whnf stage)
    Lean.Elab.Tactic.closeMainGoal `actual_flag_head exposed.getAppArgs[0]!

private theorem flag_head_source_2 : flag_head_2 = flagStatement 2 := by
  simp +decide only [flag_head_2, flagStatement, contextExpr, contextIndex,
    contextName, flagTemp, flagName, flagRhs, ite_true, ite_false]
  rfl

private theorem flag_source_2 : flagStage 2 =
    .Ssequence (flagStatement 2) (flagStage 3) := by
  have shape : flagStage 2 = .Ssequence flag_head_2 (flagStage 3) := by
    run_tac Arm64ProgramEntryLinked.sourceEquality
  exact shape.trans (congrArg (fun head => CC.Stmt.Ssequence head (flagStage 3)) flag_head_source_2)

private def flag_head_3 : CC.Stmt := by
  run_tac do
    let stage ← Lean.Elab.Term.elabTerm (← `(flag_stage_3)) none
    let exposed ← Lean.Meta.withTransparency .all (Lean.Meta.whnf stage)
    Lean.Elab.Tactic.closeMainGoal `actual_flag_head exposed.getAppArgs[0]!

private theorem flag_head_source_3 : flag_head_3 = flagStatement 3 := by
  simp +decide only [flag_head_3, flagStatement, contextExpr, contextIndex,
    contextName, flagTemp, flagName, flagRhs, ite_true, ite_false]
  rfl

private theorem flag_source_3 : flagStage 3 =
    .Ssequence (flagStatement 3) (flagStage 4) := by
  have shape : flagStage 3 = .Ssequence flag_head_3 (flagStage 4) := by
    run_tac Arm64ProgramEntryLinked.sourceEquality
  exact shape.trans (congrArg (fun head => CC.Stmt.Ssequence head (flagStage 4)) flag_head_source_3)

theorem flag_chain : ∀ i : Fin 4, flagStage i.val =
    .Ssequence (flagStatement i) (flagStage (i.val + 1)) := by
  simp only [Fin.forall_fin_succ, Fin.forall_fin_zero]
  exact ⟨flag_source_0, flag_source_1, flag_source_2, flag_source_3, trivial⟩

theorem flags_end : flagStage 4 = afterSetup := rfl

private def contextComposite : CC.Composite :=
  (world.genv_cenv.get Arm64ProgramFixture.___sk_buff).get (by decide +kernel)

private theorem context_layout :
    world.genv_cenv.get Arm64ProgramFixture.___sk_buff = some contextComposite ∧
    ∀ i : Fin 3, CC.fieldOffset world.genv_cenv (contextName i)
      contextComposite.co_members = .OK (contextOffset i, .Full) := by decide +kernel

/-- A real context field load in the linked world, at its computed byte offset.
It is independent of the native-input provider and local-variable contents. -/
theorem context_read (e : CC.Env) (le : CC.TempEnv) (memory : CC.Mem)
    (block : CC.Block) (ofs : CC.Integers.Ptrofs) (i : Fin 3) (value : BitVec 32)
    (ctx : le.get Arm64ProgramFixture._ctx = some (.Vptr block ofs))
    (read : CC.Mem.loadv .Mint32 memory
      (.Vptr block (CC.Integers.Ptrofs.add ofs (CC.Integers.Ptrofs.repr (contextOffset i)))) =
      some (.Vint value)) :
    CC.doEvalExpr world e le memory (contextExpr i) = some (.Vint value) := by
  simpa only [contextExpr, CC.doEvalExpr, ctx, CC.doDerefLoc, CC.accessMode,
    CC.lvalOfField, CC.typeof, context_layout.1, context_layout.2 i,
    CC.tuint] using read

/-- The same original caller field load survives all framed local writes. -/
theorem context_read_frame {frontier : CC.Block} {before after : CC.Mem}
    (frame : FrameBelow frontier before after) (block : CC.Block)
    (old : block.toNat < frontier.toNat) (ofs : CC.Integers.Ptrofs)
    (i : Fin 3) :
    CC.Mem.loadv .Mint32 after
      (.Vptr block (CC.Integers.Ptrofs.add ofs (CC.Integers.Ptrofs.repr (contextOffset i)))) =
    CC.Mem.loadv .Mint32 before
      (.Vptr block (CC.Integers.Ptrofs.add ofs (CC.Integers.Ptrofs.repr (contextOffset i)))) :=
  frame.load .Mint32 block _ old

/-- Actual and canonical local identities agree for these five scalar stores. -/
theorem flag_binding (initial : CC.Mem) (i : Fin 4) (block : CC.Block)
    (binding : (Arm64Producer.allocation initial).1.get (flagName i) = some (block, CC.tuchar)) :
    (allocation initial).1.get (flagName i) = some (block, CC.tuchar) := by
  have actual := Arm64ProgramEntryAllocation.local_binding initial _ _ _ binding
  have fixed : ∀ i : Fin 4, Arm64ProgramEntryAllocation.localName (flagName i) = flagName i := by
    decide +kernel
  simpa only [fixed i, Arm64ProgramEntryAllocation.localType, CC.tuchar] using actual

def flagBits (i : Fin 4) (value : BitVec 32) : BitVec 32 :=
  (if i.val = 3 then value >>> 1 else value) &&& (1#32)

/-- The real unsigned-byte assignment retains exactly its masked bit. -/
theorem flag_byte (i : Fin 4) (value : BitVec 32) :
    CC.Cop.castIntInt .I8 .Unsigned (flagBits i value) = flagBits i value := by
  change (flagBits i value &&& (255#32)) = _
  simp only [flagBits, BitVec.and_assoc]
  rfl

/-- The real negative signed SP store succeeds from its allocated permissions. -/
theorem sp_setup (initial before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (access : before.access = (Arm64Producer.allocation initial).2.access) :
    ∃ block after,
      (Arm64Producer.allocation initial).1.get Arm64Entry.___a64_sp = some (block, CC.tlong) ∧
      InternalRun world 3
        (.State Arm64ProgramFixture.f_arm64_execute_compile
          (.Ssequence spAssignment (flagStage 0)) k (allocation initial).1 le before)
        (.State Arm64ProgramFixture.f_arm64_execute_compile (flagStage 0) k (allocation initial).1 le after) ∧
      CC.Mem.load .Mint64 after block 0 = some (.Vlong (BitVec.ofInt 64 (-32))) ∧
      (∀ id ty other, (Arm64Producer.allocation initial).1.get id = some (other, ty) →
        id ≠ Arm64Entry.___a64_sp → ∀ chunk ofs,
        CC.Mem.load chunk after other ofs = CC.Mem.load chunk before other ofs) ∧
      FrameBelow initial.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  obtain ⟨block, binding, fresh, writable⟩ := Arm64Producer.scalar_local initial
    Arm64Entry.___a64_sp CC.tlong .Mint64 (by decide +kernel) rfl (by decide)
  obtain ⟨after, stored, afterAccess⟩ := Arm64Producer.create_store initial before .Mint64 block
    (.Vlong (BitVec.ofInt 64 (-32))) access writable
  change CC.Mem.store .Mint64 before block 0 (.Vlong (18446744073709551584#64)) = some after at stored
  have bound := Arm64ProgramEntryRawSetup.sp_binding initial block binding
  change (allocation initial).1.get Arm64ProgramFixture.___a64_sp = some (block, CC.tlong) at bound
  have execution : steps world 3
      (.State Arm64ProgramFixture.f_arm64_execute_compile (.Ssequence spAssignment (flagStage 0))
        k (allocation initial).1 le before) =
      some (CC.E0, .State Arm64ProgramFixture.f_arm64_execute_compile (flagStage 0)
        k (allocation initial).1 le after) ∧
      InternalPath world 3
      (.State Arm64ProgramFixture.f_arm64_execute_compile (.Ssequence spAssignment (flagStage 0))
        k (allocation initial).1 le before) := by
    simp +decide [steps, InternalPath, InternalState, sp_source, CC.doStep, CC.doEvalExpr,
      CC.doEvalLvalue, CC.lvalOfVar, bound, CC.doAssignLoc, CC.accessMode, CC.typeof,
      CC.Cop.semUnaryOperation, CC.Cop.semNeg, CC.Cop.classifyNeg,
      CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntLong,
      CC.Integers.Int.neg, CC.Integers.MI.neg,
      CC.Integers.Int.signed, CC.Integers.MI.signed, CC.Integers.Int64.repr,
      CC.Integers.Int.repr, CC.Integers.MI.repr, CC.Integers.Ptrofs.zero, CC.Integers.Ptrofs.unsigned, CC.Integers.MI.unsigned, CC.Integers.MI.zero,
      CC.tlong, CC.tint, CC.Archi.ptr64, CC.Mem.storev, stored, CC.Eapp, CC.E0]
  refine ⟨block, after, binding, internalRun_of_steps execution.2 execution.1,
    CC.Mem.load_store_same stored, ?_, FrameBelow.store fresh stored,
    afterAccess.trans access.symm, CC.Mem.store_nextblock stored⟩
  intro id ty other bindingOther different chunk ofs
  have distinct := (allocated_local_storage
    (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (Arm64Producer.allocation initial)).symm)).2
  exact CC.Mem.load_store_other stored chunk other ofs
    (.inl (distinct _ _ _ _ bindingOther binding different))

/-- Actual context-load, mask and byte-store edge, with exact temporary update.
Store success is supplied here only to isolate execution; flag_setup derives it. -/
theorem flag_execute (i : Fin 4) (e : CC.Env) (le : CC.TempEnv)
    (before after : CC.Mem) (k : CC.Cont) (block ctxBlock : CC.Block)
    (ctxOfs : CC.Integers.Ptrofs) (value : BitVec 32)
    (bound : e.get (flagName i) = some (block, CC.tuchar))
    (ctx : le.get Arm64ProgramFixture._ctx = some (.Vptr ctxBlock ctxOfs))
    (read : CC.Mem.loadv .Mint32 before (.Vptr ctxBlock
      (CC.Integers.Ptrofs.add ctxOfs (CC.Integers.Ptrofs.repr (contextOffset (contextIndex i))))) =
      some (.Vint value))
    (stored : CC.Mem.store .Mint8unsigned before block 0 (.Vint (flagBits i value)) = some after) :
    InternalRun world 6
      (.State Arm64ProgramFixture.f_arm64_execute_compile
        (.Ssequence (flagStatement i) (flagStage (i.val + 1))) k e le before)
      (.State Arm64ProgramFixture.f_arm64_execute_compile (flagStage (i.val + 1))
        k e (le.set (flagTemp i) (.Vint value)) after) := by
  have field := context_read e le before ctxBlock ctxOfs (contextIndex i) value ctx read
  have cast := flag_byte i value
  have execution : steps world 6
      (.State Arm64ProgramFixture.f_arm64_execute_compile
        (.Ssequence (flagStatement i) (flagStage (i.val + 1))) k e le before) =
      some (CC.E0, .State Arm64ProgramFixture.f_arm64_execute_compile (flagStage (i.val + 1))
        k e (le.set (flagTemp i) (.Vint value)) after) ∧
      InternalPath world 6
      (.State Arm64ProgramFixture.f_arm64_execute_compile
        (.Ssequence (flagStatement i) (flagStage (i.val + 1))) k e le before) := by
    by_cases high : i.val = 3
    all_goals simp only [flagBits, high, ite_true, ite_false] at stored
    all_goals
      simp +decide [steps, InternalPath, InternalState, flagStatement, CC.doStep,
        field, flagRhs, high, flagBits, CC.doEvalExpr, CC.doEvalLvalue, CC.lvalOfVar, bound,
        CC.doDerefLoc, CC.doAssignLoc, CC.accessMode, CC.typeof, CC.PTree.gss,
        CC.Cop.semBinaryOperation, CC.Cop.semAnd, CC.Cop.semBinarith,
        CC.Cop.classifyBinarith, CC.Cop.binarithType,
        CC.Cop.semShr, CC.Cop.semShift, CC.Cop.classifyShift,
        CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
        CC.tuchar, CC.tuint, CC.tint, CC.typeconv, CC.removeAttributes, CC.tattr,
        CC.Integers.Int.ltu, CC.Integers.MI.ltu, CC.Integers.Int.iwordsize, CC.Integers.MI.iwordsize,
        CC.Integers.Int.shru, CC.Integers.MI.shru,
        CC.Integers.Int.and, CC.Integers.MI.and, CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext,
        CC.Integers.Int.repr, CC.Integers.MI.repr,
        CC.Integers.Ptrofs.zero, CC.Integers.Ptrofs.unsigned, CC.Integers.MI.unsigned, CC.Integers.MI.zero, CC.Mem.storev,
        stored, CC.E0, CC.Eapp, BitVec.and_assoc]
  exact internalRun_of_steps execution.2 execution.1

/-- Store success is derived from the same actual allocation permissions.
The original context load is the only data-source premise. -/
theorem flag_setup (initial before : CC.Mem) (i : Fin 4) (le : CC.TempEnv) (k : CC.Cont)
    (ctxBlock : CC.Block) (ctxOfs : CC.Integers.Ptrofs) (value : BitVec 32)
    (ctx : le.get Arm64ProgramFixture._ctx = some (.Vptr ctxBlock ctxOfs))
    (read : CC.Mem.loadv .Mint32 before (.Vptr ctxBlock
      (CC.Integers.Ptrofs.add ctxOfs (CC.Integers.Ptrofs.repr (contextOffset (contextIndex i))))) =
      some (.Vint value))
    (access : before.access = (Arm64Producer.allocation initial).2.access) :
    ∃ block after,
      (Arm64Producer.allocation initial).1.get (flagName i) = some (block, CC.tuchar) ∧
      InternalRun world 6
        (.State Arm64ProgramFixture.f_arm64_execute_compile (flagStage i.val) k (allocation initial).1 le before)
        (.State Arm64ProgramFixture.f_arm64_execute_compile (flagStage (i.val + 1))
          k (allocation initial).1 (le.set (flagTemp i) (.Vint value)) after) ∧
      CC.Mem.load .Mint8unsigned after block 0 = some (.Vint (flagBits i value)) ∧
      (∀ id ty other, (Arm64Producer.allocation initial).1.get id = some (other, ty) →
        id ≠ flagName i → ∀ chunk ofs,
        CC.Mem.load chunk after other ofs = CC.Mem.load chunk before other ofs) ∧
      FrameBelow initial.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  have present : ∀ i : Fin 4, (flagName i, CC.tuchar) ∈ Arm64Producer.producer.fn_vars := by decide +kernel
  obtain ⟨block, binding, fresh, writable⟩ := Arm64Producer.scalar_local initial
    (flagName i) CC.tuchar .Mint8unsigned (present i) rfl (by decide)
  obtain ⟨after, stored, afterAccess⟩ := Arm64Producer.create_store initial before .Mint8unsigned block
    (.Vint (flagBits i value)) access writable
  have run := flag_execute i (allocation initial).1 le before after k block ctxBlock ctxOfs value
    (flag_binding initial i block binding) ctx read stored
  rw [← flag_chain i] at run
  have loaded : CC.Mem.load .Mint8unsigned after block 0 = some (.Vint (flagBits i value)) := by
    have same := CC.Mem.load_store_same stored
    have mask := flag_byte i value
    change (flagBits i value &&& (255#32)) = flagBits i value at mask
    simpa only [CC.Val.loadResult, CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext,
      show ¬(8 : Nat) ≥ 32 by decide, ite_false, show BitVec.allOnes 32 >>> (32-8) = (255#32) by decide,
      mask] using same
  refine ⟨block, after, binding, run, loaded, ?_, FrameBelow.store fresh stored,
    afterAccess.trans access.symm, CC.Mem.store_nextblock stored⟩
  intro id ty other bindingOther different chunk ofs
  have distinct := (allocated_local_storage
    (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (Arm64Producer.allocation initial)).symm)).2
  exact CC.Mem.load_store_other stored chunk other ofs
    (.inl (distinct _ _ _ _ bindingOther binding different))

def setupTemps (le : CC.TempEnv) (values : Fin 3 → BitVec 32) : CC.TempEnv :=
  (((le.set (flagTemp 0) (.Vint (values 0))).set (flagTemp 1) (.Vint (values 1))).set
    (flagTemp 2) (.Vint (values 2))).set (flagTemp 3) (.Vint (values 2))

private theorem ctx_temp_other : ∀ i : Fin 4, Arm64ProgramFixture._ctx ≠ flagTemp i := by decide +kernel

private theorem ctx_set (le : CC.TempEnv) (i : Fin 4) (value : BitVec 32) :
    (le.set (flagTemp i) (.Vint value)).get Arm64ProgramFixture._ctx =
      le.get Arm64ProgramFixture._ctx := CC.PTree.gso _ _ _ _ (Ne.symm (ctx_temp_other i))

private theorem names_distinct : ∀ i j : Fin 4, i ≠ j → flagName i ≠ flagName j := by decide +kernel
private theorem sp_other : ∀ i : Fin 4, Arm64Entry.___a64_sp ≠ flagName i := by decide +kernel

/-- The actual five setup stores and four context reads, in one reached memory.
Every input comes from the original caller object and survives the local writes.
Native state/ABI admission remains a separate relation, not an assumed effect. -/
theorem setup (initial before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (ctxBlock : CC.Block) (ctxOfs : CC.Integers.Ptrofs) (values : Fin 3 → BitVec 32)
    (ctx : le.get Arm64ProgramFixture._ctx = some (.Vptr ctxBlock ctxOfs))
    (old : ctxBlock.toNat < initial.nextblock.toNat)
    (caller : FrameBelow initial.nextblock initial before)
    (reads : ∀ i : Fin 3, CC.Mem.loadv .Mint32 initial (.Vptr ctxBlock
      (CC.Integers.Ptrofs.add ctxOfs (CC.Integers.Ptrofs.repr (contextOffset i)))) = some (.Vint (values i)))
    (access : before.access = (Arm64Producer.allocation initial).2.access) :
    ∃ spBlock, ∃ blocks : Fin 4 → CC.Block, ∃ after,
      (Arm64Producer.allocation initial).1.get Arm64Entry.___a64_sp = some (spBlock, CC.tlong) ∧
      (∀ i, (Arm64Producer.allocation initial).1.get (flagName i) = some (blocks i, CC.tuchar)) ∧
      InternalRun world 27
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntrySource.body
          k (allocation initial).1 le before)
        (.State Arm64ProgramFixture.f_arm64_execute_compile afterSetup
          k (allocation initial).1 (setupTemps le values) after) ∧
      CC.Mem.load .Mint64 after spBlock 0 = some (.Vlong (BitVec.ofInt 64 (-32))) ∧
      (∀ i, CC.Mem.load .Mint8unsigned after (blocks i) 0 =
        some (.Vint (flagBits i (values (contextIndex i))))) ∧
      (∀ id ty block, (Arm64Producer.allocation initial).1.get id = some (block, ty) →
        id ≠ Arm64Entry.___a64_sp → (∀ i, id ≠ flagName i) → ∀ chunk ofs,
        CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow initial.nextblock initial after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock ∧
      (setupTemps le values).get Arm64ProgramFixture._ctx = some (.Vptr ctxBlock ctxOfs) ∧
      (∀ i, CC.Mem.loadv .Mint32 after (.Vptr ctxBlock
        (CC.Integers.Ptrofs.add ctxOfs (CC.Integers.Ptrofs.repr (contextOffset i)))) = some (.Vint (values i))) := by
  obtain ⟨spBlock, m1, spBinding, spRun, spRead, spOther, spFrame, spAccess, spNext⟩ := sp_setup initial before le k access
  have frame1 := caller.trans spFrame
  have read1 := (context_read_frame frame1 ctxBlock old ctxOfs 0).trans (reads 0)
  obtain ⟨bn, m2, nb, nr, nv, no, nf, na, nn⟩ := flag_setup initial m1 0 le k ctxBlock ctxOfs (values 0)
    ctx read1 (spAccess.trans access)
  let le1 := le.set (flagTemp 0) (.Vint (values 0))
  have ctx1 : le1.get Arm64ProgramFixture._ctx = some (.Vptr ctxBlock ctxOfs) := (ctx_set le 0 _).trans ctx
  have frame2 := frame1.trans nf
  have read2 := (context_read_frame frame2 ctxBlock old ctxOfs 1).trans (reads 1)
  obtain ⟨bz, m3, zb, zr, zv, zo, zf, za, zn⟩ := flag_setup initial m2 1 le1 k ctxBlock ctxOfs (values 1)
    ctx1 read2 (na.trans (spAccess.trans access))
  let le2 := le1.set (flagTemp 1) (.Vint (values 1))
  have ctx2 : le2.get Arm64ProgramFixture._ctx = some (.Vptr ctxBlock ctxOfs) := (ctx_set le1 1 _).trans ctx1
  have frame3 := frame2.trans zf
  have read3 := (context_read_frame frame3 ctxBlock old ctxOfs 2).trans (reads 2)
  obtain ⟨bc, m4, cb, cr, cv, co, cf, ca, cn⟩ := flag_setup initial m3 2 le2 k ctxBlock ctxOfs (values 2)
    ctx2 read3 (za.trans (na.trans (spAccess.trans access)))
  let le3 := le2.set (flagTemp 2) (.Vint (values 2))
  have ctx3 : le3.get Arm64ProgramFixture._ctx = some (.Vptr ctxBlock ctxOfs) := (ctx_set le2 2 _).trans ctx2
  have frame4 := frame3.trans cf
  have read4 := (context_read_frame frame4 ctxBlock old ctxOfs 2).trans (reads 2)
  obtain ⟨bv, after, vb, vr, vv, vo, vf, va, vn⟩ := flag_setup initial m4 3 le3 k ctxBlock ctxOfs (values 2)
    ctx3 read4 (ca.trans (za.trans (na.trans (spAccess.trans access))))
  let blocks : Fin 4 → CC.Block := fun i => if i.val = 0 then bn else if i.val = 1 then bz else if i.val = 2 then bc else bv
  have finalFrame := frame4.trans vf
  have cases4 : ∀ i : Fin 4, i = 0 ∨ i = 1 ∨ i = 2 ∨ i = 3 := by decide +kernel
  refine ⟨spBlock, blocks, after, spBinding, ?_, ?_, ?_, ?_, ?_, finalFrame,
    va.trans (ca.trans (za.trans (na.trans spAccess))),
    vn.trans (cn.trans (zn.trans (nn.trans spNext))), ?_, ?_⟩
  · intro i; rcases cases4 i with rfl | rfl | rfl | rfl
    exact nb
    exact zb
    exact cb
    exact vb
  · rw [← source] at spRun
    have combined := (((spRun.trans nr).trans zr).trans cr).trans vr
    change InternalRun world 27 _
      (.State Arm64ProgramFixture.f_arm64_execute_compile (flagStage 4)
        k (allocation initial).1 (setupTemps le values) after) at combined
    rw [flags_end] at combined
    exact combined
  · exact (vo _ _ _ spBinding (sp_other 3) _ _).trans
      ((co _ _ _ spBinding (sp_other 2) _ _).trans
      ((zo _ _ _ spBinding (sp_other 1) _ _).trans
      ((no _ _ _ spBinding (sp_other 0) _ _).trans spRead)))
  · intro i; rcases cases4 i with rfl | rfl | rfl | rfl
    · exact (vo _ _ _ nb (names_distinct 0 3 (by decide)) _ _).trans
        ((co _ _ _ nb (names_distinct 0 2 (by decide)) _ _).trans
        ((zo _ _ _ nb (names_distinct 0 1 (by decide)) _ _).trans nv))
    · exact (vo _ _ _ zb (names_distinct 1 3 (by decide)) _ _).trans
        ((co _ _ _ zb (names_distinct 1 2 (by decide)) _ _).trans zv)
    · exact (vo _ _ _ cb (names_distinct 2 3 (by decide)) _ _).trans cv
    · exact vv
  · intro id ty block binding notSP notFlag chunk ofs
    exact (vo _ _ _ binding (notFlag 3) _ _).trans
      ((co _ _ _ binding (notFlag 2) _ _).trans
      ((zo _ _ _ binding (notFlag 1) _ _).trans
      ((no _ _ _ binding (notFlag 0) _ _).trans
      (spOther _ _ _ binding notSP _ _))))
  · exact (ctx_set le3 3 _).trans ctx3
  · intro i; exact (context_read_frame finalFrame ctxBlock old ctxOfs i).trans (reads i)

end KProgFormal.ClightRefinement.Arm64ProgramEntryBody
