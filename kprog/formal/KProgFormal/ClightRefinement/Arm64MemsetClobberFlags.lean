import KProgFormal.ClightRefinement.Arm64MemsetClobberRegisterComplete

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemsetClobberFlags

open Arm64Producer Arm64ProducerRegisterStorage
open Arm64ProgramEntryAllocation (world)
open Arm64MemsetClobberEntry (helper)
open Arm64MemsetClobberRegisters (fieldExpr entryType)

def field (i : Fin 4) : CC.Ident := headerField (Arm64ProducerEntryView.flagIndex i)

/-- Metadata for each original flag pair, including its exact continuation
and source-checked unsigned64 mask followed by the actual uchar assignment. -/
structure Declaration where
  index : Fin 4
  valueKey : CC.Ident
  ptrKey : CC.Ident
  stage : CC.Stmt
  pair : CC.Stmt
  next : CC.Stmt
  call : CC.Stmt
  pointer : CC.Stmt
  assign : CC.Stmt
  stage_source : stage = .Ssequence pair next
  pair_source : pair = .Ssequence call (.Ssequence pointer assign)
  call_source : call = .Scall (some valueKey)
    (.Evar Arm64Program._native_lab_entry_input (.Tfunction [CC.tuint] CC.tulong CC.cc_default))
    [.Econst_int (CC.Integers.Int.repr 6) CC.tint]
  pointer_source : pointer = .Sset ptrKey (fieldExpr (field index) (CC.tptr CC.tuchar))
  assign_source : assign = .Sassign (.Ederef (.Etempvar ptrKey (CC.tptr CC.tuchar)) CC.tuchar)
    (.Ebinop .Oand (.Etempvar valueKey CC.tulong) (.Econst_int (CC.Integers.Int.repr 1) CC.tint) CC.tulong)

private def declarations : Array Declaration := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor arity do throwError "original clobber flag source changed"
      pure actual.getAppArgs
    let mut source ← Lean.Elab.Term.elabTerm (← `(Arm64MemsetClobberRegisterComplete.stage 18)) none
    let mut rows : Array Lean.Expr := #[]
    for n in [:4] do
      let stage ← peel source ``CC.Stmt.Ssequence 2
      let pair ← peel stage[0]! ``CC.Stmt.Ssequence 2
      let tail ← peel pair[1]! ``CC.Stmt.Ssequence 2
      let call ← peel pair[0]! ``CC.Stmt.Scall 3
      let value ← peel call[0]! ``Option.some 2
      let pointer ← peel tail[0]! ``CC.Stmt.Sset 2
      let small ← Lean.Meta.mkAppM ``LT.lt #[Lean.mkNatLit n,Lean.mkNatLit 4]
      let index ← Lean.Meta.mkAppM ``Fin.mk #[Lean.mkNatLit n,← Lean.Meta.mkDecideProof small]
      let row ← Lean.Meta.mkAppM ``Declaration.mk #[index,value[1]!,pointer[0]!,source,stage[0]!,stage[1]!,
        pair[0]!,tail[0]!,tail[1]!,← Lean.Meta.mkEqRefl source,← Lean.Meta.mkEqRefl stage[0]!,
        ← Lean.Meta.mkEqRefl pair[0]!,← Lean.Meta.mkEqRefl tail[0]!,← Lean.Meta.mkEqRefl tail[1]!]
      rows := rows.push row
      source := stage[1]!
    Lean.Elab.Tactic.closeMainGoal `actual_clobber_flag_declarations
      (← Lean.Meta.mkArrayLit (Lean.mkConst ``Declaration) rows.toList)

def declaration (i : Fin 4) : Declaration := declarations[i.val]'(by change i.val < 4; exact i.isLt)
theorem first_source : (declaration 0).stage = Arm64MemsetClobberRegisterComplete.stage 18 := rfl
theorem indices : ∀ i : Fin 4, (declaration i).index = i := by decide +kernel
theorem key_names : ∀ i : Fin 4, (declaration i).valueKey ≠ Arm64Program._entry ∧
    (declaration i).ptrKey ≠ Arm64Program._entry ∧ (declaration i).ptrKey ≠ (declaration i).valueKey := by decide +kernel

def stage (n : Nat) : CC.Stmt := if h : n < 4 then (declaration ⟨n,h⟩).stage else (declaration 3).next
theorem next_source (i : Fin 4) : (declaration i).next = stage (i.val + 1) := by
  have positions : ∀ i : Fin 4, i = 0 ∨ i = 1 ∨ i = 2 ∨ i = 3 := by decide +kernel
  rcases positions i with rfl | rfl | rfl | rfl
  all_goals rfl

def callCont (i : Fin 4) (le : CC.TempEnv) (k : CC.Cont) : CC.Cont :=
  .Kcall (some (declaration i).valueKey) helper CC.emptyEnv le
    (.Kseq (.Ssequence (declaration i).pointer (declaration i).assign) (.Kseq (declaration i).next k))
def temps (i : Fin 4) (le : CC.TempEnv) (value : BitVec 64) (block : CC.Block) : CC.TempEnv :=
  (le.set (declaration i).valueKey (.Vlong value)).set (declaration i).ptrKey (.Vptr block 0)

theorem ready (i : Fin 4) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    InternalRun world 3 (.State helper (declaration i).stage k CC.emptyEnv le m)
      (.Callstate Arm64OriginCache.inputFunction [.Vint (6#32)] (callCont i le k) m) := by
  rw [(declaration i).stage_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
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

private def composite : CC.Composite :=
  (world.genv_cenv.get Arm64Program._kprog_arm64_entry).get (by decide +kernel)
private theorem layout : world.genv_cenv.get Arm64Program._kprog_arm64_entry = some composite ∧
    ∀ i : Fin 4, CC.fieldOffset world.genv_cenv (field i) composite.co_members =
      .OK (8 * ((Arm64ProducerEntryView.flagIndex i).val : Int),.Full) := by constructor <;> decide +kernel
private theorem offsets : ∀ i : Fin 4,
    CC.Integers.Ptrofs.unsigned (CC.Integers.Ptrofs.repr (8 * ((Arm64ProducerEntryView.flagIndex i).val : Int))) =
      8 * ((Arm64ProducerEntryView.flagIndex i).val : Int) := by decide +kernel
private theorem ptr_zero : CC.Integers.Ptrofs.unsigned 0 = 0 := by decide +kernel
private theorem add_zero (offset : CC.Integers.Ptrofs) : CC.Integers.Ptrofs.add 0 offset = offset := BitVec.zero_add offset
private theorem masked (cenv : CC.CompositeEnv) (m : CC.Mem) (value : BitVec 64) :
    CC.Cop.semBinaryOperation cenv .Oand (.Vlong value) CC.tulong (.Vint (CC.Integers.Int.repr 1)) CC.tint m =
      some (.Vlong (CC.Integers.Int64.and value (1#64))) := rfl

set_option hygiene false in
/-- The actual Returnstate, pointer read, mask, uchar cast and inline store
reach the exact original next statement in seven internal transitions. -/
theorem returned_store {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry) (i : Fin 4) (le : CC.TempEnv) (value : BitVec 64)
    (entryRead : le.get Arm64Program._entry = some (.Vptr entry.block 0)) (after : CC.Mem) (k : CC.Cont)
    (stored : CC.Mem.store .Mint8unsigned before (storage.flags i).block 0 (.Vint (flagWord value)) = some after) :
    InternalRun world 7 (.Returnstate (.Vlong value) (callCont i le k) before)
      (.State helper (declaration i).next k CC.emptyEnv (temps i le value (storage.flags i).block) after) := by
  have names := key_names i
  have keepValue (v : CC.Val) (t : CC.TempEnv) := CC.PTree.gso _ _ v t names.1
  have keepPtrValue (v : CC.Val) (t : CC.TempEnv) := CC.PTree.gso _ _ v t names.2.2
  have pointer := storage.flagPointers i
  have mask := masked world.genv_cenv before value
  simp only [CC.tulong,CC.tint] at mask
  have store := stored
  simp only [flagWord,CC.Cop.castIntInt,CC.Integers.Int64.unsigned,CC.Integers.MI.unsigned] at store
  run_tac do
    let reduce ← `(tactic|
      simp +decide only [CC.doStep,CC.setOpttemp,callCont,temps,(declaration i).pointer_source,(declaration i).assign_source,
        indices i,fieldExpr,entryType,CC.doEvalExpr,CC.doEvalLvalue,CC.doDerefLoc,CC.doAssignLoc,CC.lvalOfField,
        CC.Mem.loadv,CC.Mem.storev,CC.accessMode,CC.typeof,layout.1,layout.2 i,CC.PTree.gss,keepValue,keepPtrValue,
        entryRead,add_zero,offsets i,ptr_zero,pointer,mask,
        CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntInt,CC.typeconv,CC.removeAttributes,CC.tattr,
        CC.tuchar,CC.tuint,CC.tint,CC.tulong,CC.tptr,CC.E0,store,flagWord,
        CC.Integers.Int64.unsigned,CC.Integers.MI.unsigned,ite_true,ite_false,eq_self] <;> try rfl)
    for _ in [:7] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic reduce
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

structure Effect {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry) (i : Fin 4) (value : BitVec 64) (after : CC.Mem) : Prop where
  stored : CC.Mem.store .Mint8unsigned before (storage.flags i).block 0 (.Vint (flagWord value)) = some after
  read : CC.Mem.load .Mint8unsigned after (storage.flags i).block 0 = some (.Vint (flagWord value))
  caller : FrameBelow initial.nextblock before after
  access : after.access = before.access
  nextblock : after.nextblock = before.nextblock

/-- Current writable flag rights construct the real store and its readback. -/
theorem write {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry) (i : Fin 4) (value : BitVec 64) :
    ∃ after, Effect storage i value after := by
  have existsStore : ∃ after, CC.Mem.store .Mint8unsigned before (storage.flags i).block 0
      (.Vint (flagWord value)) = some after := by
    simp only [CC.Mem.store,storage.flagWritable i,ite_true]
    exact ⟨_,rfl⟩
  obtain ⟨after,stored⟩ := existsStore
  have present : ∀ j : Fin 4, (headerSourceName (Arm64ProducerEntryView.flagIndex j),
      headerSourceType (Arm64ProducerEntryView.flagIndex j)) ∈ producer.fn_vars := by decide +kernel
  obtain ⟨block,binding,fresh,_,_⟩ := local_storage initial _ _ (present i)
  have same : block = (storage.flags i).block :=
    congrArg Prod.fst (Option.some.inj (binding.symm.trans (storage.flags i).binding))
  have flagFresh : initial.nextblock.toNat ≤ (storage.flags i).block.toNat := by simpa only [same] using fresh
  refine ⟨after,stored,?_,FrameBelow.store flagFresh stored,CC.Mem.store_access stored,CC.Mem.store_nextblock stored⟩
  have read := CC.Mem.load_store_same stored
  rcases flag_word_bit value with zero | one <;>
    simpa [CC.Val.loadResult,CC.Integers.Int.zero_ext,CC.Integers.MI.zero_ext, *] using read

theorem entry_retained (i : Fin 4) (le : CC.TempEnv) (value : BitVec 64) (block : CC.Block) :
    (temps i le value block).get Arm64Program._entry = le.get Arm64Program._entry := by
  unfold temps
  rw [CC.PTree.gso _ _ _ _ (key_names i).2.1,CC.PTree.gso _ _ _ _ (key_names i).1]

end KProgFormal.ClightRefinement.Arm64MemsetClobberFlags
