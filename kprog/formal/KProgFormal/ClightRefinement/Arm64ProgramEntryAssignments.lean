import KProgFormal.ClightRefinement.Arm64ProgramEntryFields

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryAssignments

open Arm64ProgramEntryAllocation (world)
open Arm64ProgramEntrySource (expression statement)

/-- Scalar stores use the imported memory operation, independently of the
composite environment. This includes failed stores and bitfield writes. -/
theorem scalar_store (first second : CC.CompositeEnv) (ty : CC.Ty)
    (chunk : CC.Chunk) (scalar : CC.accessMode ty = .By_value chunk)
    (m : CC.Mem) (block : CC.Block) (offset : CC.Integers.Ptrofs)
    (bits : CC.Bitfield) (value : CC.Val) :
    CC.doAssignLoc first ty m block offset bits value =
      CC.doAssignLoc second ty m block offset bits value := by
  cases bits with
  | Full => simp only [CC.doAssignLoc, scalar]
  | Bits sz sg pos width => cases ty <;> rfl

/-- Transport an executable scalar assignment. Evaluation and annotations
are the only expression premises; cast and store success come from the source
step, and the actual step has exactly the same post-memory. -/
theorem assignment (sourceWorld actualWorld : CC.CGenv)
    (sourceFunction actualFunction : CC.Function) (source actual : CC.Env)
    (sourceTemps actualTemps : CC.TempEnv) (sourceCont actualCont : CC.Cont)
    (lhs rhs mappedLhs mappedRhs : CC.Expr) (before after : CC.Mem)
    (chunk : CC.Chunk)
    (leftType : CC.typeof mappedLhs = CC.typeof lhs)
    (rightType : CC.typeof mappedRhs = CC.typeof rhs)
    (scalar : CC.accessMode (CC.typeof lhs) = .By_value chunk)
    (left : CC.doEvalLvalue actualWorld actual actualTemps before mappedLhs =
      CC.doEvalLvalue sourceWorld source sourceTemps before lhs)
    (right : CC.doEvalExpr actualWorld actual actualTemps before mappedRhs =
      CC.doEvalExpr sourceWorld source sourceTemps before rhs)
    (stepped : CC.doStep sourceWorld
      (.State sourceFunction (.Sassign lhs rhs) sourceCont source sourceTemps before) =
      some (CC.E0, .State sourceFunction .Sskip sourceCont source sourceTemps after)) :
    CC.doStep actualWorld
      (.State actualFunction (.Sassign mappedLhs mappedRhs) actualCont actual actualTemps before) =
      some (CC.E0, .State actualFunction .Sskip actualCont actual actualTemps after) := by
  simp only [CC.doStep] at stepped ⊢
  rw [left, right, leftType, rightType]
  cases hl : CC.doEvalLvalue sourceWorld source sourceTemps before lhs with
  | none => simp only [hl] at stepped; cases stepped
  | some location =>
    rcases location with ⟨block, offset, bits⟩
    cases hr : CC.doEvalExpr sourceWorld source sourceTemps before rhs with
    | none => simp only [hl, hr] at stepped; cases stepped
    | some value =>
      simp only [hl, hr] at stepped ⊢
      cases hc : CC.Cop.semCast value (CC.typeof rhs) (CC.typeof lhs) before with
      | none => simp only [hc] at stepped; cases stepped
      | some cast =>
        simp only [hc] at stepped ⊢
        rw [scalar_store actualWorld.genv_cenv sourceWorld.genv_cenv _ chunk scalar]
        cases hs : CC.doAssignLoc sourceWorld.genv_cenv (CC.typeof lhs)
            before block offset bits cast with
        | none => simp only [hs] at stepped; cases stepped
        | some result =>
          simp only [hs, Option.some.injEq, Prod.mk.injEq, CC.State.State.injEq] at stepped
          obtain ⟨_, _, _, _, _, _, rfl⟩ := stepped
          rfl

/-- Assignment-only soundness uses the imported expression/store laws and
assignment constructor. The axiom report still includes the imported Step2
model's abstract external semantics; it adds no new axiom. -/
theorem assignment_sound (ge : CC.CGenv) (f : CC.Function) (lhs rhs : CC.Expr)
    (k : CC.Cont) (env : CC.Env) (temps : CC.TempEnv) (before after : CC.Mem)
    (stepped : CC.doStep ge (.State f (.Sassign lhs rhs) k env temps before) =
      some (CC.E0, .State f .Sskip k env temps after)) :
    CC.Step2 ge (.State f (.Sassign lhs rhs) k env temps before) CC.E0
      (.State f .Sskip k env temps after) := by
  simp only [CC.doStep] at stepped
  split at stepped
  · next block offset bits value left right =>
      split at stepped
      · next cast casted =>
          split at stepped
          · next result stored =>
              cases stepped
              exact .assign f lhs rhs k env temps before block offset bits value cast after
                (CC.doEvalLvalue_sound ge env temps before lhs block offset bits left)
                (CC.doEvalExpr_sound ge env temps before rhs value right) casted
                (CC.doAssignLoc_sound _ _ _ _ _ _ _ _ stored)
          · exact absurd stepped (by simp)
      · exact absurd stepped (by simp)
  · exact absurd stepped (by simp)

private theorem twelve_cases : ∀ i : Fin 12, i = 0 ∨ i = 1 ∨ i = 2 ∨ i = 3 ∨ i = 4 ∨ i = 5 ∨ i = 6 ∨ i = 7 ∨ i = 8 ∨ i = 9 ∨ i = 10 ∨ i = 11 := by decide +kernel

private theorem rhs_shape : ∀ i : Fin 12, Arm64Producer.headerRhs i =
    if i.val < 2 then .Evar (Arm64Producer.headerSourceName i) (Arm64Producer.headerSourceType i)
    else .Eaddrof (.Evar (Arm64Producer.headerSourceName i) (Arm64Producer.headerSourceType i))
      (CC.tptr (Arm64Producer.headerSourceType i)) := by
  intro i
  rcases twelve_cases i with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl <;> rfl

/-- All twelve real header RHS expressions obtain their correspondence from
allocation, including array decay and address-of. No initialized read is assumed. -/
theorem header_rhs (initial before : CC.Mem) (temps : CC.TempEnv) (i : Fin 12) :
    CC.doEvalExpr world (Arm64ProgramEntryAllocation.allocation initial).1 temps before
        (expression (Arm64Producer.headerRhs i)) =
      CC.doEvalExpr Arm64Producer.ge (Arm64Producer.allocation initial).1 temps before
        (Arm64Producer.headerRhs i) := by
  have present : ∀ i : Fin 12, (Arm64Producer.headerSourceName i,
      Arm64Producer.headerSourceType i) ∈ Arm64Producer.producer.fn_vars := by decide +kernel
  have bound :=  Arm64ProgramEntryExpressions.allocated_local initial before temps
    (Arm64Producer.headerSourceName i) (Arm64Producer.headerSourceType i) (present i)
  rw [rhs_shape]
  split
  · exact bound.2.1
  · exact bound.2.2

private theorem header_types : ∀ i : Fin 12,
    CC.typeof (expression (Arm64Producer.headerTarget i)) =
      CC.typeof (Arm64Producer.headerTarget i) ∧
    CC.typeof (expression (Arm64Producer.headerRhs i)) =
      CC.typeof (Arm64Producer.headerRhs i) := by decide +kernel

/-- A source header assignment executes in the actual generated function,
with its own continuation and allocation environment, producing the same memory.
Any source post-memory framing fact therefore applies unchanged. -/
theorem header_assignment (initial before after : CC.Mem) (temps : CC.TempEnv)
    (sourceCont actualCont : CC.Cont) (i : Fin 12)
    (stepped : CC.doStep Arm64Producer.ge
      (.State Arm64Producer.producer (Arm64Producer.headerAssignment i) sourceCont
        (Arm64Producer.allocation initial).1 temps before) =
      some (CC.E0, .State Arm64Producer.producer .Sskip sourceCont
        (Arm64Producer.allocation initial).1 temps after)) :
    CC.doStep world
      (.State Arm64ProgramFixture.f_arm64_execute_compile
        (statement (Arm64Producer.headerAssignment i)) actualCont
        (Arm64ProgramEntryAllocation.allocation initial).1 temps before) =
      some (CC.E0, .State Arm64ProgramFixture.f_arm64_execute_compile .Sskip actualCont
        (Arm64ProgramEntryAllocation.allocation initial).1 temps after) := by
  apply assignment Arm64Producer.ge world Arm64Producer.producer
    Arm64ProgramFixture.f_arm64_execute_compile _ _ temps temps sourceCont actualCont
    (Arm64Producer.headerTarget i) (Arm64Producer.headerRhs i)
    (expression (Arm64Producer.headerTarget i)) (expression (Arm64Producer.headerRhs i))
    before after CC.Mptr (header_types i).1 (header_types i).2
    (Arm64Producer.header_layout.2.2.2.1 i)
  · exact (Arm64ProgramEntryFields.allocated_header initial before temps temps
      (Arm64Producer.headerField i) (Arm64Producer.headerPointerType i)).1
  · exact header_rhs initial before temps i
  · exact stepped

open Arm64Producer

private theorem source_header_lvalue (world : CC.CGenv)
    (layout : world.genv_cenv = ge.genv_cenv) (m before : CC.Mem) (le : CC.TempEnv) (i : Fin 12)
    (entry : HeaderLocal m) :
    CC.doEvalLvalue world (allocation m).1 le before (headerTarget i) =
      some (entry.block, CC.Integers.Ptrofs.repr (8 * (i.val : Int)), .Full) := by
  simp [headerTarget, headerType, CC.doEvalLvalue, CC.lvalOfVar, CC.doEvalExpr,
    CC.doDerefLoc, CC.accessMode, CC.lvalOfField, CC.typeof, entry.binding,
    layout, header_layout.1, header_layout.2.1, CC.Integers.Ptrofs.add,
    CC.Integers.Ptrofs.zero, CC.Integers.MI.zero, CC.Integers.MI.add]
  all_goals
    apply congrArg (fun ofs => (ofs, CC.Bitfield.Full))
    exact BitVec.zero_add _

private theorem source_header_rhs (world : CC.CGenv) (m before : CC.Mem) (le : CC.TempEnv) (i : Fin 12)
    (cell : HeaderSourceLocal m i) :
    CC.doEvalExpr world (allocation m).1 le before (headerRhs i) = some (.Vptr cell.block 0) ∧
    CC.Cop.semCast (.Vptr cell.block 0) (CC.typeof (headerRhs i))
      (CC.typeof (headerTarget i)) before = some (.Vptr cell.block 0) := by
  constructor
  · by_cases first : i.val < 2
    · have cases2 : i = 0 ∨ i = 1 := by
        have values : i.val = 0 ∨ i.val = 1 := by omega
        rcases values with zero | one
        · exact .inl (Fin.ext zero)
        · exact .inr (Fin.ext one)
      rcases cases2 with rfl | rfl
      all_goals simp [headerRhs, headerSourceType, CC.tarray, CC.doEvalExpr, CC.lvalOfVar,
        CC.doDerefLoc, CC.accessMode, cell.binding, CC.Integers.Ptrofs.zero, CC.Integers.MI.zero]
    · simp [headerRhs, first, CC.doEvalExpr, CC.doEvalLvalue, CC.lvalOfVar,
        cell.binding, CC.Integers.Ptrofs.zero, CC.Integers.MI.zero]
  · simp [CC.Cop.semCast, header_layout.2.2.1]

/-- The actual generated function writes one header cell in three imported
Clight transitions. Memory permissions and framing use the same Mem.store
witness as the source assignment. -/
theorem header_write (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (i : Fin 12) (entry : HeaderLocal m) (cell : HeaderSourceLocal m i) (rest : CC.Stmt)
    (access : before.access = (allocation m).2.access) :
    ∃ after, InternalRun world 3
        (.State Arm64ProgramFixture.f_arm64_execute_compile
          (.Ssequence (statement (headerAssignment i)) rest) k
          (Arm64ProgramEntryAllocation.allocation m).1 le before)
        (.State Arm64ProgramFixture.f_arm64_execute_compile rest k
          (Arm64ProgramEntryAllocation.allocation m).1 le after) ∧
      CC.Mem.load CC.Mptr after entry.block (8 * (i.val : Int)) = some (.Vptr cell.block 0) ∧
      (∀ j : Fin 12, j ≠ i → CC.Mem.load CC.Mptr after entry.block (8 * (j.val : Int)) =
        CC.Mem.load CC.Mptr before entry.block (8 * (j.val : Int))) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ Arm64Entry._entry →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  have writable : CC.Mem.validAccess before CC.Mptr entry.block (8 * (i.val : Int)) .Writable = true := by
    simp only [CC.Mem.validAccess, Bool.and_eq_true]
    refine ⟨?_, ?_⟩
    · apply CC.Mem.rangePerm_intro
      intro ofs lower upper
      have bound := i.isLt
      have size := header_layout.2.2.2.2
      have lo : (0 : Int) ≤ ofs := by omega
      have hi : ofs < CC.sizeof ge.genv_cenv headerType := by
        change ofs < (8 * (i.val : Int)) + 8 at upper
        omega
      have perm := CC.Mem.rangePerm_perm (allocation m).2 entry.block 0
        (CC.sizeof ge.genv_cenv headerType) .Cur .Writable entry.range ofs lo hi
      simpa only [CC.Mem.perm, access] using perm
    · change ((8 * (i.val : Int)) % 8 == 0) = true
      simp
  have existsStore : ∃ after, CC.Mem.store CC.Mptr before entry.block (8 * (i.val : Int))
      (.Vptr cell.block 0) = some after := by
    unfold CC.Mem.store
    rw [writable]
    exact ⟨_, rfl⟩
  obtain ⟨after, stored⟩ := existsStore
  have storev : CC.Mem.storev CC.Mptr before
      (.Vptr entry.block (CC.Integers.Ptrofs.repr (8 * (i.val : Int)))) (.Vptr cell.block 0) = some after := by
    simpa only [CC.Mem.storev, header_offsets] using stored
  have target := source_header_lvalue Arm64Producer.ge rfl m before le i entry
  have rhs := source_header_rhs Arm64Producer.ge m before le i cell
  have assigned : CC.doStep Arm64Producer.ge
      (.State producer (headerAssignment i) (.Kseq rest k) (allocation m).1 le before) =
      some (CC.E0, .State producer .Sskip (.Kseq rest k) (allocation m).1 le after) := by
    simp only [headerAssignment, CC.doStep, target, rhs.1, rhs.2, CC.doAssignLoc, header_layout.2.2.2.1]
    change (match CC.Mem.storev CC.Mptr before
      (.Vptr entry.block (CC.Integers.Ptrofs.repr (8 * (i.val : Int)))) (.Vptr cell.block 0) with
      | some memory => some (CC.E0, CC.State.State producer .Sskip (.Kseq rest k) (allocation m).1 le memory)
      | none => none) = _
    rw [storev]
  have actualAssigned := header_assignment m before after le (.Kseq rest k) (.Kseq rest k) i assigned
  have run : InternalRun world 3
      (.State Arm64ProgramFixture.f_arm64_execute_compile
        (.Ssequence (statement (headerAssignment i)) rest) k
        (Arm64ProgramEntryAllocation.allocation m).1 le before)
      (.State Arm64ProgramFixture.f_arm64_execute_compile rest k
        (Arm64ProgramEntryAllocation.allocation m).1 le after) :=
    .step trivial (.seq _ _ _ _ _ _ _)
      (.step trivial (assignment_sound world _ _ _ _ _ _ _ _ actualAssigned)
        (.step trivial (.skip_seq _ _ _ _ _ _) (.refl _)))
  refine ⟨after, run, ?_, ?_, ?_, FrameBelow.store entry.fresh stored,
    CC.Mem.store_access stored, CC.Mem.store_nextblock stored⟩
  · simpa [CC.Val.loadResult, CC.Mptr, CC.Archi.ptr64] using CC.Mem.load_store_same stored
  · intro j different
    have ne : j.val ≠ i.val := fun h => different (Fin.ext h)
    have separate : (8 * j.val : Int) + 8 ≤ (8 * i.val : Int) ∨
        (8 * i.val : Int) + 8 ≤ (8 * j.val : Int) := by omega
    exact CC.Mem.load_store_other stored CC.Mptr entry.block (8 * (j.val : Int)) (.inr separate)
  · intro id ty block bound different chunk ofs
    have distinct := (allocated_local_storage
      (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation m)).symm)).2
    exact CC.Mem.load_store_other stored chunk block ofs
      (.inl (distinct _ _ _ _ bound entry.binding different))

private theorem run_header (m : CC.Mem) (entry : HeaderLocal m)
    (cells : (i : Fin 12) → HeaderSourceLocal m i) (rows : List (Fin 12)) (rest : CC.Stmt)
    (le : CC.TempEnv) (k : CC.Cont) (before : CC.Mem)
    (access : before.access = (allocation m).2.access) :
    ∃ after, InternalRun world (3 * rows.length)
        (.State Arm64ProgramFixture.f_arm64_execute_compile
          (rows.foldr (fun i next => .Ssequence (statement (headerAssignment i)) next) rest)
          k (Arm64ProgramEntryAllocation.allocation m).1 le before)
        (.State Arm64ProgramFixture.f_arm64_execute_compile rest k
          (Arm64ProgramEntryAllocation.allocation m).1 le after) ∧
      (∀ i ∈ rows, CC.Mem.load CC.Mptr after entry.block (8 * (i.val : Int)) = some (.Vptr (cells i).block 0)) ∧
      (∀ i ∉ rows, CC.Mem.load CC.Mptr after entry.block (8 * (i.val : Int)) =
        CC.Mem.load CC.Mptr before entry.block (8 * (i.val : Int))) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ Arm64Entry._entry →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  induction rows generalizing before with
  | nil =>
    refine ⟨before, .refl _, ?_, ?_, ?_, FrameBelow.refl _ _, rfl, rfl⟩
    · intro i member; cases member
    · intro i absent; rfl
    · intro id ty block bound different chunk ofs; rfl
  | cons head tail ih =>
    obtain ⟨middle, headRun, headRead, headOther, headLocals, headFrame, headAccess, headNext⟩ :=
      header_write m before le k head entry (cells head)
        (tail.foldr (fun i next => .Ssequence (statement (headerAssignment i)) next) rest) access
    obtain ⟨after, tailRun, tailRead, tailOther, tailLocals, tailFrame, tailAccess, tailNext⟩ :=
      ih middle (headAccess.trans access)
    refine ⟨after, ?_, ?_, ?_, ?_, headFrame.trans tailFrame,
      tailAccess.trans headAccess, tailNext.trans headNext⟩
    · simpa only [List.foldr_cons, List.length_cons, Nat.mul_add, Nat.mul_one,
        Nat.add_comm] using headRun.trans tailRun
    · intro i member
      by_cases later : i ∈ tail
      · exact tailRead i later
      · have same : i = head := (List.mem_cons.mp member).resolve_right later
        subst i
        exact (tailOther head later).trans headRead
    · intro i absent
      have notHead : i ≠ head := by intro same; apply absent; simp [same]
      have notTail : i ∉ tail := fun member => absent (List.mem_cons_of_mem _ member)
      exact (tailOther i notTail).trans (headOther i notHead)
    · intro id ty block bound different chunk ofs
      exact (tailLocals id ty block bound different chunk ofs).trans
        (headLocals id ty block bound different chunk ofs)

/-- Cache actual production tails with kernel-checked source equations.
Only the source header's first LHS locates the cut; the statements and tails
come from the actual exported production function. -/
private def productionParts : { data : List (List CC.Stmt) × (CC.Stmt × CC.Stmt) //
    Arm64ProgramEntrySource.Spine Arm64ProgramFixture.f_arm64_execute_compile.fn_body
      data.1 data.2.1 ∧
    data.2.1 = (List.ofFn (fun i => statement (headerAssignment i))).foldr
      CC.Stmt.Ssequence data.2.2 } := by
  run_tac do
    let expected ← Lean.Elab.Term.elabTerm (← `(headerTarget 0)) none
    let mut source ← Lean.Elab.Term.elabTerm (← `(producer.fn_body)) none
    let mut count := 0
    while true do
      let body ← Lean.Meta.withTransparency .all (Lean.Meta.whnf source)
      unless body.isAppOfArity ``CC.Stmt.Ssequence 2 do
        throwError "source header assignment was not found"
      let head ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body.getAppArgs[0]!)
      if head.isAppOfArity ``CC.Stmt.Sassign 2 then
        if ← Lean.Meta.isDefEq head.getAppArgs[0]! expected then break
      source := body.getAppArgs[1]!
      count := count + 1
    let start ← Lean.Elab.Term.elabTerm
      (← `(Arm64ProgramFixture.f_arm64_execute_compile.fn_body)) none
    let mut current := start
    let mut segments : Array (Lean.Expr × Lean.Expr × Lean.Expr) := #[]
    let mut remaining := count
    while remaining > 0 do
      let first := current
      let mut heads : Array Lean.Expr := #[]
      for _ in [:min 32 remaining] do
        let body ← Lean.Meta.withTransparency .all (Lean.Meta.whnf current)
        unless body.isAppOfArity ``CC.Stmt.Ssequence 2 do
          throwError "actual prefix before header changed"
        heads := heads.push body.getAppArgs[0]!
        current := body.getAppArgs[1]!
      segments := segments.push (first,
        (← Lean.Meta.mkListLit (Lean.mkConst ``CC.Stmt) heads.toList), current)
      remaining := remaining - heads.size
    let first := current
    for _ in [:12] do
      let body ← Lean.Meta.withTransparency .all (Lean.Meta.whnf current)
      unless body.isAppOfArity ``CC.Stmt.Ssequence 2 do
        throwError "actual header initializer has fewer than twelve statements"
      current := body.getAppArgs[1]!
    let last := current
    let listTy ← Lean.Meta.mkAppM ``List #[Lean.mkConst ``CC.Stmt]
    let mut rows ← Lean.Meta.mkListLit listTy []
    let mut proof ← Lean.Meta.mkAppM ``Arm64ProgramEntrySource.Spine.nil #[first]
    for (head, segment, next) in segments.toList.reverse do
      let rhs ← Lean.Meta.mkAppM ``List.foldr #[Lean.mkConst ``CC.Stmt.Ssequence, next, segment]
      proof ← Lean.Meta.mkAppM ``Arm64ProgramEntrySource.Spine.step
        #[head, next, first, segment, rows, (← Lean.Meta.mkEqRefl rhs), proof]
      rows ← Lean.Meta.mkAppM ``List.cons #[segment, rows]
    let headers ← Lean.Elab.Term.elabTerm
      (← `(List.ofFn (fun i => statement (headerAssignment i)))) none
    let rhs ← Lean.Meta.mkAppM ``List.foldr #[Lean.mkConst ``CC.Stmt.Ssequence, last, headers]
    let equal ← Lean.Meta.mkEqRefl rhs
    let data ← Lean.Meta.mkAppM ``Prod.mk #[rows, (← Lean.Meta.mkAppM ``Prod.mk #[first, last])]
    let valid ← Lean.Meta.mkAppM ``And.intro #[proof, equal]
    let target ← Lean.Meta.whnf (← Lean.Elab.Tactic.getMainTarget)
    Lean.Elab.Tactic.closeMainGoal `production_header_parts
      (← Lean.Meta.mkAppOptM ``Subtype.mk #[some target.getAppArgs[0]!,
        some target.getAppArgs[1]!, some data, some valid])

def headerPrefix : List (List CC.Stmt) := productionParts.val.1
def beforeHeader : CC.Stmt := productionParts.val.2.1
def afterHeader : CC.Stmt := productionParts.val.2.2

/-- This region is an actual suffix of the actual exported function body. -/
theorem production_header : Arm64ProgramEntrySource.Spine
    Arm64ProgramFixture.f_arm64_execute_compile.fn_body headerPrefix beforeHeader :=
  productionParts.property.1

/-- All twelve header stores, followed by the actual production tail. -/
theorem production_header_source : beforeHeader =
    (List.ofFn (fun i => statement (headerAssignment i))).foldr CC.Stmt.Ssequence afterHeader :=
  productionParts.property.2

/-- All twelve actual scalar header pointers are constructed from the real
allocated locals in thirty-six internal transitions. The successor is the actual production tail; vector and tail initialization
remain to be transported before complete native admission. -/
theorem header_initialized (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (access : before.access = (allocation m).2.access) :
    ∃ entry : HeaderLocal m, ∃ cells : (i : Fin 12) → HeaderSourceLocal m i, ∃ after,
      InternalRun world 36 (.State Arm64ProgramFixture.f_arm64_execute_compile
          beforeHeader k (Arm64ProgramEntryAllocation.allocation m).1 le before)
        (.State Arm64ProgramFixture.f_arm64_execute_compile
          afterHeader k (Arm64ProgramEntryAllocation.allocation m).1 le after) ∧
      (∀ i, CC.Mem.load CC.Mptr after entry.block (8 * (i.val : Int)) = some (.Vptr (cells i).block 0)) ∧
      (∀ id ty block, (allocation m).1.get id = some (block, ty) → id ≠ Arm64Entry._entry →
        ∀ chunk ofs, CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  classical
  obtain ⟨entry⟩ := header_local m
  let cells : (i : Fin 12) → HeaderSourceLocal m i := fun i => Classical.choice (header_source_local m i)
  obtain ⟨after, run, read, _, other, frame, finalAccess, next⟩ :=
    run_header m entry cells (List.finRange 12) afterHeader le k before access
  refine ⟨entry, cells, after, ?_, (fun i => read i (List.mem_finRange i)), other, frame, finalAccess, next⟩
  have mapped : List.ofFn (fun i => statement (headerAssignment i)) =
      (List.finRange 12).map (fun i => statement (headerAssignment i)) := by
    simp only [List.finRange, List.map_ofFn, Function.comp_def]
  rw [production_header_source]
  simpa only [List.length_finRange, mapped, List.foldr_map] using run

end KProgFormal.ClightRefinement.Arm64ProgramEntryAssignments
