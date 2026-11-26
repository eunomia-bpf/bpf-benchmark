import KProgFormal.ClightRefinement.Arm64MemsetClobberFlagsComplete

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemsetClobberVectors

open Arm64Producer Arm64ProducerRegisterStorage
open Arm64ProgramEntryAllocation (world)
open Arm64MemsetClobberEntry (helper)
open Arm64MemsetClobberRegisters (fieldExpr entryType)

def field (high : Bool) : CC.Ident := if high then Arm64Program._vector_hi else Arm64Program._vector_lo
def pointerExpr (high : Bool) (index : Fin 32) : CC.Expr :=
  .Ederef (.Ebinop .Oadd (fieldExpr (field high) (CC.tarray (CC.tptr CC.tulong) 32))
    (.Econst_int (CC.Integers.Int.repr (index.val : Int)) CC.tint) (CC.tptr (CC.tptr CC.tulong))) (CC.tptr CC.tulong)

/-- The final actual pair has no outer sequence or invented suffix. -/
structure Declaration where
  high : Bool
  index : Fin 32
  valueKey : CC.Ident
  ptrKey : CC.Ident
  stage : CC.Stmt
  pair : CC.Stmt
  next : Option CC.Stmt
  call : CC.Stmt
  pointer : CC.Stmt
  assign : CC.Stmt
  stage_source : stage = match next with | some tail => .Ssequence pair tail | none => pair
  pair_source : pair = .Ssequence call (.Ssequence pointer assign)
  call_source : call = .Scall (some valueKey)
    (.Evar Arm64Program._native_lab_entry_input (.Tfunction [CC.tuint] CC.tulong CC.cc_default))
    [.Econst_int (CC.Integers.Int.repr 6) CC.tint]
  pointer_source : pointer = .Sset ptrKey (pointerExpr high index)
  assign_source : assign = .Sassign (.Ederef (.Etempvar ptrKey (CC.tptr CC.tulong)) CC.tulong)
    (.Etempvar valueKey CC.tulong)

private def declarations : Array Declaration := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor arity do throwError "original clobber vector source changed"
      pure actual.getAppArgs
    let mut source ← Lean.Elab.Term.elabTerm (← `(Arm64MemsetClobberFlags.stage 4)) none
    let mut rows : Array Lean.Expr := #[]
    for n in [:64] do
      let stage ← peel source ``CC.Stmt.Ssequence 2
      let pairSource := if n < 63 then stage[0]! else source
      let pair ← peel pairSource ``CC.Stmt.Ssequence 2
      let tail ← peel pair[1]! ``CC.Stmt.Ssequence 2
      let call ← peel pair[0]! ``CC.Stmt.Scall 3
      let value ← peel call[0]! ``Option.some 2
      let pointer ← peel tail[0]! ``CC.Stmt.Sset 2
      let next ← if n < 63 then Lean.Meta.mkAppM ``Option.some #[stage[1]!]
        else Lean.Elab.Term.elabTerm (← `((none : Option CC.Stmt))) none
      let small ← Lean.Meta.mkAppM ``LT.lt #[Lean.mkNatLit (n/2),Lean.mkNatLit 32]
      let index ← Lean.Meta.mkAppM ``Fin.mk #[Lean.mkNatLit (n/2),← Lean.Meta.mkDecideProof small]
      let row ← Lean.Meta.mkAppM ``Declaration.mk #[Lean.toExpr (n%2==1),index,value[1]!,pointer[0]!,
        source,pairSource,next,pair[0]!,tail[0]!,tail[1]!,← Lean.Meta.mkEqRefl source,
        ← Lean.Meta.mkEqRefl pairSource,← Lean.Meta.mkEqRefl pair[0]!,← Lean.Meta.mkEqRefl tail[0]!,← Lean.Meta.mkEqRefl tail[1]!]
      rows := rows.push row
      if n < 63 then source := stage[1]!
    Lean.Elab.Tactic.closeMainGoal `actual_clobber_vector_declarations
      (← Lean.Meta.mkArrayLit (Lean.mkConst ``Declaration) rows.toList)

def declaration (i : Fin 64) : Declaration := declarations[i.val]'(by change i.val < 64; exact i.isLt)
theorem first_source : (declaration 0).stage = Arm64MemsetClobberFlags.stage 4 := rfl
theorem final_source : (declaration 63).next = none := rfl
theorem positions : ∀ i : Fin 64, (declaration i).index.val = i.val / 2 ∧
    (declaration i).high = decide (i.val % 2 = 1) := by decide +kernel
theorem has_next : ∀ i : Fin 63, (declaration ⟨i.val,by omega⟩).next.isSome = true := by decide +kernel
theorem next_source : ∀ i : Fin 63,
    (declaration ⟨i.val,by omega⟩).next = some (declaration ⟨i.val+1,by omega⟩).stage := by
  simp only [Fin.forall_fin_succ,Fin.forall_fin_zero]
  repeat' apply And.intro
  all_goals first | rfl | trivial
theorem key_names : ∀ i : Fin 64, (declaration i).valueKey ≠ Arm64Program._entry ∧
    (declaration i).ptrKey ≠ Arm64Program._entry ∧ (declaration i).ptrKey ≠ (declaration i).valueKey := by decide +kernel

def offset (i : Fin 64) : Int :=
  CC.Integers.Ptrofs.unsigned (vectorLoopSourceOffset (declaration i).high (declaration i).index)
theorem source_offsets : ∀ i : Fin 64, offset i = 8 * (i.val : Int) := by decide +kernel

/-- This is the genuine post-assignment state for the final pair, or the
actual next source statement after a nonfinal pair's sequence skip. -/
def afterStmt (i : Fin 64) : CC.Stmt := match (declaration i).next with | some tail => tail | none => .Sskip
def tailCont (i : Fin 64) (k : CC.Cont) : CC.Cont :=
  match (declaration i).next with | some tail => .Kseq tail k | none => k
def callCont (i : Fin 64) (le : CC.TempEnv) (k : CC.Cont) : CC.Cont :=
  .Kcall (some (declaration i).valueKey) helper CC.emptyEnv le
    (.Kseq (.Ssequence (declaration i).pointer (declaration i).assign) (tailCont i k))
def temps (i : Fin 64) (le : CC.TempEnv) (value : BitVec 64) (block : CC.Block) : CC.TempEnv :=
  (le.set (declaration i).valueKey (.Vlong value)).set (declaration i).ptrKey
    (.Vptr block (vectorLoopSourceOffset (declaration i).high (declaration i).index))

private theorem pair_ready (i : Fin 64) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    InternalRun world 2 (.State helper (declaration i).pair (tailCont i k) CC.emptyEnv le m)
      (.Callstate Arm64OriginCache.inputFunction [.Vint (6#32)] (callCont i le k) m) := by
  rw [(declaration i).pair_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [(declaration i).call_source]
  refine .step trivial ?_ (.refl _)
  apply CC.Step.call (tyargs := [CC.tuint]) (tyres := CC.tulong) (cconv := CC.cc_default)
    (vf := .Vptr Arm64ProgramEntryCall.inputBlock 0)
  · rfl
  · apply CC.doEvalExpr_sound
    simp only [CC.doEvalExpr,CC.lvalOfVar,CC.emptyEnv,CC.PTree.gempty,
      Arm64ProgramEntryColdRead.input_binding.1,CC.doDerefLoc,CC.accessMode]
    rfl
  · apply CC.doEvalExprlist_sound
    rfl
  · simpa +decide [CC.Genv.findFunct,CC.Integers.Ptrofs.eq,CC.Integers.Ptrofs.zero,
      CC.Integers.MI.eq,CC.Integers.MI.zero] using Arm64ProgramEntryCall.input_binding.2
  · rfl

theorem ready (i : Fin 64) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    InternalRun world (if (declaration i).next.isSome then 3 else 2)
      (.State helper (declaration i).stage k CC.emptyEnv le m)
      (.Callstate Arm64OriginCache.inputFunction [.Vint (6#32)] (callCont i le k) m) := by
  rw [(declaration i).stage_source]
  cases hn : (declaration i).next with
  | none => simpa only [hn,Option.isSome_none,ite_false,Bool.false_eq_true,tailCont] using pair_ready i le m k
  | some tail =>
    simp only [Option.isSome_some,ite_true,eq_self]
    refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
    simpa only [tailCont,hn] using pair_ready i le m k

private def composite : CC.Composite :=
  (world.genv_cenv.get Arm64Program._kprog_arm64_entry).get (by decide +kernel)
private theorem layout : world.genv_cenv.get Arm64Program._kprog_arm64_entry = some composite ∧
    ∀ high : Bool, CC.fieldOffset world.genv_cenv (field high) composite.co_members =
      .OK ((if high then 352 else 96),.Full) := by constructor <;> decide +kernel
private theorem offsets : ∀ (high : Bool) (j : Fin 32),
    CC.Integers.Ptrofs.add (CC.Integers.Ptrofs.repr (if high then 352 else 96))
      (CC.Integers.Ptrofs.mul (CC.Integers.Ptrofs.repr 8) (CC.Cop.ptrofsOfInt .Signed (CC.Integers.Int.repr (j.val : Int)))) =
      CC.Integers.Ptrofs.repr ((if high then 352 else 96) + 8 * (j.val : Int)) ∧
    CC.Integers.Ptrofs.unsigned (CC.Integers.Ptrofs.repr ((if high then 352 else 96) + 8 * (j.val : Int))) =
      (if high then 352 else 96) + 8 * (j.val : Int) := by decide +kernel
private theorem add_slot (cenv : CC.CompositeEnv) (memory : CC.Mem) (high : Bool) (block : CC.Block) (j : Fin 32) :
    CC.Cop.semBinaryOperation cenv .Oadd (.Vptr block (CC.Integers.Ptrofs.repr (if high then 352 else 96)))
      (CC.tarray (CC.tptr CC.tulong) 32) (.Vint (CC.Integers.Int.repr (j.val : Int))) CC.tint memory =
      some (.Vptr block (CC.Integers.Ptrofs.repr ((if high then 352 else 96) + 8 * (j.val : Int)))) := by
  change some (CC.Val.Vptr block (CC.Integers.Ptrofs.add (CC.Integers.Ptrofs.repr (if high then 352 else 96))
    (CC.Integers.Ptrofs.mul (CC.Integers.Ptrofs.repr 8) (CC.Cop.ptrofsOfInt .Signed (CC.Integers.Int.repr (j.val : Int)))))) = _
  rw [(offsets high j).1]
private theorem add_zero (offset : CC.Integers.Ptrofs) : CC.Integers.Ptrofs.add 0 offset = offset := BitVec.zero_add offset

set_option hygiene false in
/-- The common actual return/pointer/assignment body ends at its own real
post-assignment skip, with the exact original continuation still present. -/
theorem returned_body {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry) (i : Fin 64) (le : CC.TempEnv) (value : BitVec 64)
    (entryRead : le.get Arm64Program._entry = some (.Vptr entry.block 0)) (after : CC.Mem) (k : CC.Cont)
    (stored : CC.Mem.store .Mint64 before storage.vectors.block
      (CC.Integers.Ptrofs.unsigned (vectorLoopSourceOffset (declaration i).high (declaration i).index))
      (.Vlong value) = some after) :
    InternalRun world 6
      (.Returnstate (.Vlong value) (callCont i le k) before)
      (.State helper .Sskip (tailCont i k) CC.emptyEnv (temps i le value storage.vectors.block) after) := by
  have names := key_names i
  have keepValue (v : CC.Val) (t : CC.TempEnv) := CC.PTree.gso _ _ v t names.1
  have keepPtrValue (v : CC.Val) (t : CC.TempEnv) := CC.PTree.gso _ _ v t names.2.2
  have pointer := storage.vectorPointers (declaration i).high (declaration i).index
  have add := add_slot world.genv_cenv before (declaration i).high entry.block (declaration i).index
  simp only [CC.tarray,CC.tptr,CC.tulong,CC.tint] at add
  run_tac do
      let reduce ← `(tactic|
        simp +decide only [CC.doStep,CC.setOpttemp,callCont,temps,
          (declaration i).pointer_source,(declaration i).assign_source,pointerExpr,fieldExpr,entryType,
          CC.doEvalExpr,CC.doEvalLvalue,CC.doDerefLoc,CC.doAssignLoc,CC.lvalOfField,
          CC.Mem.loadv,CC.Mem.storev,CC.accessMode,CC.typeof,layout.1,layout.2,CC.PTree.gss,keepValue,keepPtrValue,
          entryRead,add_zero,(offsets (declaration i).high (declaration i).index).2,pointer,add,
          CC.Cop.semCast,CC.Cop.classifyCast,CC.typeconv,CC.removeAttributes,CC.tattr,
          CC.tarray,CC.tuchar,CC.tint,CC.tulong,CC.tptr,CC.E0,stored,ite_true,ite_false,eq_self] <;> try rfl)
      for _ in [:6] do
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
        Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
        Lean.Elab.Tactic.evalTactic reduce
      Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

/-- The final actual pair ends at its six-step skip. Every nonfinal pair
executes its seventh sequence step to the real next source statement. -/
theorem returned_store {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry) (i : Fin 64) (le : CC.TempEnv) (value : BitVec 64)
    (entryRead : le.get Arm64Program._entry = some (.Vptr entry.block 0)) (after : CC.Mem) (k : CC.Cont)
    (stored : CC.Mem.store .Mint64 before storage.vectors.block
      (CC.Integers.Ptrofs.unsigned (vectorLoopSourceOffset (declaration i).high (declaration i).index))
      (.Vlong value) = some after) :
    InternalRun world (if (declaration i).next.isSome then 7 else 6)
      (.Returnstate (.Vlong value) (callCont i le k) before)
      (.State helper (afterStmt i) k CC.emptyEnv (temps i le value storage.vectors.block) after) := by
  have body := returned_body storage i le value entryRead after k stored
  cases hn : (declaration i).next with
  | none => simpa only [hn,Option.isSome_none,Bool.false_eq_true,ite_false,tailCont,afterStmt] using body
  | some tail =>
    have leave : InternalRun world 1
        (.State helper .Sskip (tailCont i k) CC.emptyEnv (temps i le value storage.vectors.block) after)
        (.State helper (afterStmt i) k CC.emptyEnv (temps i le value storage.vectors.block) after) := by
      simp only [tailCont,afterStmt,hn]
      exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
    simpa only [hn,Option.isSome_some,ite_true] using InternalRun.trans body leave

structure Effect {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry) (i : Fin 64) (value : BitVec 64) (after : CC.Mem) : Prop where
  stored : CC.Mem.store .Mint64 before storage.vectors.block
    (CC.Integers.Ptrofs.unsigned (vectorLoopSourceOffset (declaration i).high (declaration i).index)) (.Vlong value) = some after
  read : CC.Mem.load .Mint64 after storage.vectors.block
    (CC.Integers.Ptrofs.unsigned (vectorLoopSourceOffset (declaration i).high (declaration i).index)) = some (.Vlong value)
  caller : FrameBelow initial.nextblock before after
  access : after.access = before.access
  nextblock : after.nextblock = before.nextblock

theorem write {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry) (i : Fin 64) (value : BitVec 64) :
    ∃ after, Effect storage i value after := by
  have writable := Arm64VectorWritable.half_pointer storage.vectors storage.vectorWritable (declaration i).high (declaration i).index
  have existsStore : ∃ after, CC.Mem.store .Mint64 before storage.vectors.block
      (CC.Integers.Ptrofs.unsigned (vectorLoopSourceOffset (declaration i).high (declaration i).index)) (.Vlong value) = some after := by
    simp only [CC.Mem.store,writable,ite_true]
    exact ⟨_,rfl⟩
  obtain ⟨after,stored⟩ := existsStore
  exact ⟨after,stored,CC.Mem.load_store_same stored,FrameBelow.store storage.vectors.fresh stored,
    CC.Mem.store_access stored,CC.Mem.store_nextblock stored⟩

theorem entry_retained (i : Fin 64) (le : CC.TempEnv) (value : BitVec 64) (block : CC.Block) :
    (temps i le value block).get Arm64Program._entry = le.get Arm64Program._entry := by
  unfold temps
  rw [CC.PTree.gso _ _ _ _ (key_names i).2.1,CC.PTree.gso _ _ _ _ (key_names i).1]

end KProgFormal.ClightRefinement.Arm64MemsetClobberVectors
