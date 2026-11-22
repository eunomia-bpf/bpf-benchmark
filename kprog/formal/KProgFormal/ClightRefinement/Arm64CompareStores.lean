import KProgFormal.ClightRefinement.Arm64CompareMath

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64Compare.Stores
open Arm64Producer
open Arm64ProducerRegisterStorage

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source (some (← Lean.Elab.Tactic.getMainTarget))
  Lean.Elab.Term.synthesizeSyntheticMVarsNoPostponing
  Lean.Elab.Tactic.closeMainGoal `actual_cmp_store_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.instantiateMVars term)))
private def sourceParts : List CC.Stmt := by
  run_tac do
    let mut tail ← Lean.Elab.Term.elabTerm (← `(Math.stores)) none
    let mut rows : Array Lean.Expr := #[]
    for _ in [:3] do
      tail ← Lean.Meta.withTransparency .all (Lean.Meta.whnf tail)
      unless tail.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "actual CMP stores changed"
      rows := rows.push tail.getAppArgs[0]!
      tail := tail.getAppArgs[1]!
    rows := rows.push tail
    Lean.Elab.Tactic.closeMainGoal `actual_cmp_stores
      (← Lean.Meta.mkListLit (Lean.mkConst ``CC.Stmt) rows.toList)
private def zCode : CC.Stmt := by run_tac cachePart (← `((sourceParts[0]?).getD .Sskip))
private def nCode : CC.Stmt := by run_tac cachePart (← `((sourceParts[1]?).getD .Sskip))
private def cCode : CC.Stmt := by run_tac cachePart (← `((sourceParts[2]?).getD .Sskip))
private def vCode : CC.Stmt := by run_tac cachePart (← `((sourceParts[3]?).getD .Sskip))
def code (i : Fin 4) : CC.Stmt := [zCode,nCode,cCode,vCode][i]

theorem source : Math.stores = .Ssequence (code 0) (.Ssequence (code 1) (.Ssequence (code 2) (code 3))) := rfl

/-- Source store order Z,N,C,V, mapped back to the existing N,Z,C,V storage. -/
def flagIndex (i : Fin 4) : Fin 4 := [1,0,2,3][i]
def field (i : Fin 4) : CC.Ident := [Arm64Program._z,Arm64Program._n,Arm64Program._c,Arm64Program._v][i]
def offset (i : Fin 4) : CC.Z := [72,64,80,88][i]
def temporary (i : Fin 4) : CC.Ident := [Arm64Program._t'7018,Arm64Program._t'7017,Arm64Program._t'7016,Arm64Program._t'7015][i]
private theorem four_cases : ∀ i : Fin 4, i=0 ∨ i=1 ∨ i=2 ∨ i=3 := by decide +kernel

private def expression (i : Fin 4) : CC.Expr :=
  match code i with
  | .Ssequence _ (.Sassign _ value) => value
  | _ => .Econst_int 0 CC.tint
private def pointer (i : Fin 4) : CC.Expr :=
  .Efield (.Ederef (.Etempvar Arm64Program._entry
    (CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr)))
    (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr)) (field i) (CC.tptr CC.tuchar)
private theorem code_source (i : Fin 4) : code i = .Ssequence (.Sset (temporary i) (pointer i))
    (.Sassign (.Ederef (.Etempvar (temporary i) (CC.tptr CC.tuchar)) CC.tuchar) (expression i)) := by
  rcases four_cases i with rfl|rfl|rfl|rfl <;> rfl
private theorem expression_type (i : Fin 4) : CC.typeof (expression i) = CC.tint := by
  rcases four_cases i with rfl|rfl|rfl|rfl <;> rfl

/-- The source unsigned comparisons and overflow bit expression, before any
native-ISA correspondence theorem. -/
def condition (lhs rhs result sign : BitVec 64) (i : Fin 4) : Bool :=
  [CC.Integers.Int64.cmpu .Ceq lhs rhs,
   CC.Integers.Int64.cmpu .Cne (result &&& sign) 0,
   CC.Integers.Int64.cmpu .Cge lhs rhs,
   CC.Integers.Int64.cmpu .Cne (((lhs ^^^ rhs) &&& (lhs ^^^ result)) &&& sign) 0][i]
def value (lhs rhs result sign : BitVec 64) (i : Fin 4) : CC.Val :=
  CC.Val.ofBool (condition lhs rhs result sign i)
def operands (le : CC.TempEnv) (lhs rhs result sign : BitVec 64) : Prop :=
  le.get Arm64Program.___kprog_a64_sub_lhs__4 = some (.Vlong lhs) ∧
  le.get Arm64Program.___kprog_a64_sub_rhs__4 = some (.Vlong rhs) ∧
  le.get Arm64Program.___kprog_a64_sub_res__4 = some (.Vlong result) ∧
  le.get Arm64Program.___kprog_a64_sub_sign__4 = some (.Vlong sign)

private def zExpr : CC.Expr := by
  run_tac cachePart (← `(match zCode with
    | .Ssequence _ (.Sassign _ value) => value | _ => .Econst_int 0 CC.tint))
private def nExpr : CC.Expr := by
  run_tac cachePart (← `(match nCode with
    | .Ssequence _ (.Sassign _ value) => value | _ => .Econst_int 0 CC.tint))
private def cExpr : CC.Expr := by
  run_tac cachePart (← `(match cCode with
    | .Ssequence _ (.Sassign _ value) => value | _ => .Econst_int 0 CC.tint))
private def vExpr : CC.Expr := by
  run_tac cachePart (← `(match vCode with
    | .Ssequence _ (.Sassign _ value) => value | _ => .Econst_int 0 CC.tint))

private theorem value_eval (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem)
    (lhs rhs result sign : BitVec 64) (i : Fin 4) (inputs : operands le lhs rhs result sign) :
    CC.doEvalExpr Arm64ProgramEntryLinked.ge e le m (expression i) = some (value lhs rhs result sign i) := by
  obtain ⟨hl,hr,hs,hn⟩ := inputs
  rcases four_cases i with rfl|rfl|rfl|rfl
  · change CC.doEvalExpr Arm64ProgramEntryLinked.ge e le m zExpr = some (value lhs rhs result sign 0)
    simp only [zExpr, CC.doEvalExpr, hl,hr,hs,hn,CC.typeof]
    rfl
  · change CC.doEvalExpr Arm64ProgramEntryLinked.ge e le m nExpr = some (value lhs rhs result sign 1)
    simp only [nExpr, CC.doEvalExpr, hl,hr,hs,hn,CC.typeof]
    rfl
  · change CC.doEvalExpr Arm64ProgramEntryLinked.ge e le m cExpr = some (value lhs rhs result sign 2)
    simp only [cExpr, CC.doEvalExpr, hl,hr,hs,hn,CC.typeof]
    rfl
  · change CC.doEvalExpr Arm64ProgramEntryLinked.ge e le m vExpr = some (value lhs rhs result sign 3)
    simp only [vExpr, CC.doEvalExpr, hl,hr,hs,hn,CC.typeof]
    rfl

private theorem flag_cast (b : Bool) (m : CC.Mem) :
    CC.Cop.semCast (CC.Val.ofBool b) CC.tint CC.tuchar m = some (CC.Val.ofBool b) := by
  cases b <;> rfl

private theorem address (b : CC.Block) (i : Fin 4) :
    CC.lvalOfField Arm64ProgramEntryLinked.ge (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr)
      (field i) (.Vptr b 0) = some (b,CC.Integers.Ptrofs.repr (offset i),.Full) := by
  rcases four_cases i with rfl|rfl|rfl|rfl <;>
    run_tac Arm64ProgramEntryLinked.sourceEquality
private theorem offset_unsigned : ∀ i : Fin 4,
    CC.Integers.Ptrofs.unsigned (CC.Integers.Ptrofs.repr (offset i)) = offset i := by decide +kernel

private theorem temporary_ne : ∀ i : Fin 4,
    temporary i ≠ Arm64Program._entry ∧
    temporary i ≠ Arm64Program.___kprog_a64_sub_lhs__4 ∧
    temporary i ≠ Arm64Program.___kprog_a64_sub_rhs__4 ∧
    temporary i ≠ Arm64Program.___kprog_a64_sub_res__4 ∧
    temporary i ≠ Arm64Program.___kprog_a64_sub_sign__4 := by decide +kernel

private theorem operands_set (le : CC.TempEnv) (lhs rhs result sign : BitVec 64)
    (i : Fin 4) (ptr : CC.Val) (inputs : operands le lhs rhs result sign) :
    operands (le.set (temporary i) ptr) lhs rhs result sign := by
  obtain ⟨hl,hr,hs,hn⟩ := inputs
  exact ⟨(CC.PTree.gso _ _ _ _ (temporary_ne i).2.1).trans hl,
    (CC.PTree.gso _ _ _ _ (temporary_ne i).2.2.1).trans hr,
    (CC.PTree.gso _ _ _ _ (temporary_ne i).2.2.2.1).trans hs,
    (CC.PTree.gso _ _ _ _ (temporary_ne i).2.2.2.2).trans hn⟩

set_option hygiene false in
/-- One original flag pointer load and byte assignment, with the real source
expression evaluated from captured arithmetic operands. -/
private theorem single (e : CC.Env) (le : CC.TempEnv) (m after : CC.Mem) (k : CC.Cont)
    (entryBlock flagBlock : CC.Block) (lhs rhs result sign : BitVec 64) (i : Fin 4)
    (entry : le.get Arm64Program._entry = some (.Vptr entryBlock 0))
    (inputs : operands le lhs rhs result sign)
    (read : CC.Mem.load CC.Mptr m entryBlock (offset i) = some (.Vptr flagBlock 0))
    (stored : CC.Mem.store .Mint8unsigned m flagBlock 0 (value lhs rhs result sign i) = some after) :
    InternalRun Arm64ProgramEntryLinked.ge 4 (.State Arm64Nop.handler (code i) k e le m)
      (.State Arm64Nop.handler .Sskip k e (le.set (temporary i) (.Vptr flagBlock 0)) after) := by
  have loaded : CC.doEvalExpr Arm64ProgramEntryLinked.ge e le m (pointer i) = some (.Vptr flagBlock 0) := by
    simp only [pointer, CC.doEvalExpr, CC.doEvalLvalue, entry, CC.typeof,
      CC.doDerefLoc, CC.accessMode, CC.tptr, address, CC.Mem.loadv, offset_unsigned, read] <;> rfl
  have evaluated := value_eval e (le.set (temporary i) (.Vptr flagBlock 0)) m
    lhs rhs result sign i (operands_set le lhs rhs result sign i _ inputs)
  have cast := flag_cast (condition lhs rhs result sign i) m
  have assigned : CC.doAssignLoc Arm64ProgramEntryLinked.ge.genv_cenv CC.tuchar m flagBlock 0 .Full
      (value lhs rhs result sign i) = some after := by
    simp only [CC.doAssignLoc, CC.accessMode, CC.tuchar, CC.Mem.storev]
    exact stored
  dsimp only [value] at assigned
  have targetType : CC.typeof (.Ederef (.Etempvar (temporary i) (CC.tptr CC.tuchar)) CC.tuchar) = CC.tuchar := rfl
  rw [code_source]
  run_tac do
    for _ in [:4] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp only [code_source, CC.doStep, loaded,
        CC.doEvalExpr, CC.doEvalLvalue, expression_type, targetType, evaluated,
        CC.PTree.gss, cast, value, assigned, CC.E0] <;> try rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

private theorem pointer_offset : ∀ i : Fin 4,
    8 * ((Arm64ProducerEntryView.flagIndex (flagIndex i)).val : Int) = offset i := by decide +kernel

private theorem flag_allocated {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry) (i : Fin 4) :
    initial.nextblock.toNat ≤ (storage.flags (flagIndex i)).block.toNat ∧
    CC.Mem.validAccess (allocation initial).2 .Mint8unsigned (storage.flags (flagIndex i)).block 0 .Writable = true := by
  have present : ∀ i : Fin 4,
      (headerSourceName (Arm64ProducerEntryView.flagIndex (flagIndex i)),
       headerSourceType (Arm64ProducerEntryView.flagIndex (flagIndex i))) ∈ producer.fn_vars := by decide +kernel
  have size : ∀ i : Fin 4,
      CC.sizeof Arm64Producer.ge.genv_cenv (headerSourceType (Arm64ProducerEntryView.flagIndex (flagIndex i))) =
        CC.sizeChunk .Mint8unsigned := by decide +kernel
  obtain ⟨block,binding,fresh,writable⟩ := scalar_local initial _ _ .Mint8unsigned (present i) (size i) (by decide)
  have same : block = (storage.flags (flagIndex i)).block :=
    congrArg Prod.fst (Option.some.inj (binding.symm.trans (storage.flags (flagIndex i)).binding))
  subst block
  exact ⟨fresh,writable⟩

private theorem flag_separate {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry) (i : Fin 4)
    (id : CC.Ident) (ty : CC.Ty) (block : CC.Block)
    (binding : (allocation initial).1.get id = some (block,ty))
    (different : headerSourceName (Arm64ProducerEntryView.flagIndex (flagIndex i)) ≠ id) :
    (storage.flags (flagIndex i)).block ≠ block := by
  exact (allocated_local_storage
    (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation initial)).symm)).2
      _ _ _ _ (storage.flags (flagIndex i)).binding binding different

private theorem flag_names : ∀ i j : Fin 4, i ≠ j →
    headerSourceName (Arm64ProducerEntryView.flagIndex (flagIndex i)) ≠
      headerSourceName (Arm64ProducerEntryView.flagIndex (flagIndex j)) := by decide +kernel
private theorem flag_header_names : ∀ i : Fin 4,
    headerSourceName (Arm64ProducerEntryView.flagIndex (flagIndex i)) ≠ Arm64Entry._entry := by decide +kernel

/-- Only the actual four byte-cell permissions are needed; unrelated callee
allocations and freed blocks may change the rest of the access map. -/
def Writable {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry) : Prop :=
  ∀ i : Fin 4, CC.Mem.validAccess before .Mint8unsigned
    (storage.flags (flagIndex i)).block 0 .Writable = true

/-- Every actual source storage constructor retains these allocation-derived
permissions, including the original preceding five-call result. -/
theorem writable_of_storage {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry) : Writable storage :=
  fun i => storage.flagWritable (flagIndex i)

theorem writable_of_access {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry)
    (access : before.access = (allocation initial).2.access) : Writable storage := by
  intro i
  exact (CC.Mem.validAccess_congr (m1 := before) (m2 := (allocation initial).2)
    (chunk := .Mint8unsigned) (b := (storage.flags (flagIndex i)).block) (ofs := 0) (p := .Writable)
    (fun o => by simp only [CC.Mem.perm,access])).trans (flag_allocated storage i).2

/-- Successful stores, reached bytes and allocation/caller frames, all produced
from the original current access map rather than assumed post-state flags. -/
structure Effect {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry) (lhs rhs result sign : BitVec 64) (after : CC.Mem) : Prop where
  stores : ∃ m1 m2 m3,
    CC.Mem.store .Mint8unsigned before (storage.flags (flagIndex 0)).block 0 (value lhs rhs result sign 0) = some m1 ∧
    CC.Mem.store .Mint8unsigned m1 (storage.flags (flagIndex 1)).block 0 (value lhs rhs result sign 1) = some m2 ∧
    CC.Mem.store .Mint8unsigned m2 (storage.flags (flagIndex 2)).block 0 (value lhs rhs result sign 2) = some m3 ∧
    CC.Mem.store .Mint8unsigned m3 (storage.flags (flagIndex 3)).block 0 (value lhs rhs result sign 3) = some after
  bytes : ∀ i, CC.Mem.load .Mint8unsigned after (storage.flags (flagIndex i)).block 0 = some (value lhs rhs result sign i)
  caller : FrameBelow initial.nextblock before after
  access : after.access = before.access
  nextblock : after.nextblock = before.nextblock

private theorem load_written {m after : CC.Mem} {block : CC.Block} (b : Bool)
    (stored : CC.Mem.store .Mint8unsigned m block 0 (CC.Val.ofBool b) = some after) :
    CC.Mem.load .Mint8unsigned after block 0 = some (CC.Val.ofBool b) := by
  have read := CC.Mem.load_store_same stored
  cases b <;> exact read

/-- All four store successes and final flag bytes follow from allocation-derived
byte permissions; the actual source store order is retained. -/
theorem write_writable {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry) (lhs rhs result sign : BitVec 64)
    (writable : Writable storage) :
    ∃ after, Effect storage lhs rhs result sign after := by
  have create (memory : CC.Mem) (i : Fin 4) (v : CC.Val)
      (same : memory.access = before.access) :
      ∃ after, CC.Mem.store .Mint8unsigned memory (storage.flags (flagIndex i)).block 0 v = some after := by
    have permission := (CC.Mem.validAccess_congr (m1 := memory) (m2 := before)
      (chunk := .Mint8unsigned) (b := (storage.flags (flagIndex i)).block) (ofs := 0) (p := .Writable)
      (fun o => by simp only [CC.Mem.perm,same])).trans (writable i)
    simp only [CC.Mem.store,permission,ite_true]
    exact ⟨_,rfl⟩
  obtain ⟨m1,s0⟩ := create before 0 (value lhs rhs result sign 0) rfl
  obtain ⟨m2,s1⟩ := create m1 1 (value lhs rhs result sign 1) (CC.Mem.store_access s0)
  obtain ⟨m3,s2⟩ := create m2 2 (value lhs rhs result sign 2)
    ((CC.Mem.store_access s1).trans (CC.Mem.store_access s0))
  obtain ⟨after,s3⟩ := create m3 3 (value lhs rhs result sign 3)
    (((CC.Mem.store_access s2).trans (CC.Mem.store_access s1)).trans (CC.Mem.store_access s0))
  have distinct (i j : Fin 4) (different : i ≠ j) :
      (storage.flags (flagIndex i)).block ≠ (storage.flags (flagIndex j)).block :=
    flag_separate storage i _ _ _ (storage.flags (flagIndex j)).binding (flag_names i j different)
  refine ⟨after,⟨⟨m1,m2,m3,s0,s1,s2,s3⟩,?_,?_,?_,?_⟩⟩
  · intro i
    rcases four_cases i with rfl|rfl|rfl|rfl
    · rw [CC.Mem.load_store_other s3 .Mint8unsigned _ 0 (.inl (distinct 0 3 (by decide))),
        CC.Mem.load_store_other s2 .Mint8unsigned _ 0 (.inl (distinct 0 2 (by decide))),
        CC.Mem.load_store_other s1 .Mint8unsigned _ 0 (.inl (distinct 0 1 (by decide)))]
      exact load_written _ s0
    · rw [CC.Mem.load_store_other s3 .Mint8unsigned _ 0 (.inl (distinct 1 3 (by decide))),
        CC.Mem.load_store_other s2 .Mint8unsigned _ 0 (.inl (distinct 1 2 (by decide)))]
      exact load_written _ s1
    · rw [CC.Mem.load_store_other s3 .Mint8unsigned _ 0 (.inl (distinct 2 3 (by decide)))]
      exact load_written _ s2
    · exact load_written _ s3
  · exact (((FrameBelow.store (flag_allocated storage 0).1 s0).trans
      (FrameBelow.store (flag_allocated storage 1).1 s1)).trans
      (FrameBelow.store (flag_allocated storage 2).1 s2)).trans
      (FrameBelow.store (flag_allocated storage 3).1 s3)
  · exact (((CC.Mem.store_access s3).trans (CC.Mem.store_access s2)).trans
      (CC.Mem.store_access s1)).trans (CC.Mem.store_access s0)
  · exact (((CC.Mem.store_nextblock s3).trans (CC.Mem.store_nextblock s2)).trans
      (CC.Mem.store_nextblock s1)).trans (CC.Mem.store_nextblock s0)

/-- Every differently named actual producer local retains every load, including
header, GPR/tag cells, SP, caches and vectors through their allocation bindings. -/
theorem Effect.local_load {initial before after : CC.Mem} {entry : HeaderLocal initial}
    {storage : Storage initial before entry} {lhs rhs result sign : BitVec 64}
    (effect : Effect storage lhs rhs result sign after)
    (id : CC.Ident) (ty : CC.Ty) (block : CC.Block)
    (binding : (allocation initial).1.get id = some (block,ty))
    (different : ∀ i, headerSourceName (Arm64ProducerEntryView.flagIndex (flagIndex i)) ≠ id)
    (chunk : CC.Chunk) (ofs : CC.Z) :
    CC.Mem.load chunk after block ofs = CC.Mem.load chunk before block ofs := by
  obtain ⟨m1,m2,m3,s0,s1,s2,s3⟩ := effect.stores
  exact (((CC.Mem.load_store_other s3 chunk block ofs
    (.inl (Ne.symm (flag_separate storage 3 id ty block binding (different 3))))).trans
    (CC.Mem.load_store_other s2 chunk block ofs
      (.inl (Ne.symm (flag_separate storage 2 id ty block binding (different 2)))))).trans
    (CC.Mem.load_store_other s1 chunk block ofs
      (.inl (Ne.symm (flag_separate storage 1 id ty block binding (different 1)))))).trans
    (CC.Mem.load_store_other s0 chunk block ofs
      (.inl (Ne.symm (flag_separate storage 0 id ty block binding (different 0)))))

def temps (le : CC.TempEnv) (blocks : Fin 4 → CC.Block) : CC.TempEnv :=
  (((le.set (temporary 0) (.Vptr (blocks 0) 0)).set (temporary 1) (.Vptr (blocks 1) 0)).set
    (temporary 2) (.Vptr (blocks 2) 0)).set (temporary 3) (.Vptr (blocks 3) 0)

private theorem followed {e : CC.Env} {le finalLe : CC.TempEnv} {m after : CC.Mem}
    {k : CC.Cont} {body next : CC.Stmt}
    (run : InternalRun Arm64ProgramEntryLinked.ge 4
      (.State Arm64Nop.handler body (.Kseq next k) e le m)
      (.State Arm64Nop.handler .Sskip (.Kseq next k) e finalLe after)) :
    InternalRun Arm64ProgramEntryLinked.ge 6
      (.State Arm64Nop.handler (.Ssequence body next) k e le m)
      (.State Arm64Nop.handler next k e finalLe after) := by
  apply InternalRun.step
  · trivial
  · apply CC.doStep_sound
    rfl
  have resumed : InternalRun Arm64ProgramEntryLinked.ge 1
      (.State Arm64Nop.handler .Sskip (.Kseq next k) e finalLe after)
      (.State Arm64Nop.handler next k e finalLe after) := by
    apply InternalRun.step
    · trivial
    · apply CC.doStep_sound
      rfl
    exact InternalRun.refl _
  exact run.trans resumed

private theorem entry_set (le : CC.TempEnv) (entry : CC.Block) (i : Fin 4) (ptr : CC.Val)
    (read : le.get Arm64Program._entry = some (.Vptr entry 0)) :
    (le.set (temporary i) ptr).get Arm64Program._entry = some (.Vptr entry 0) :=
  (CC.PTree.gso _ _ _ _ (temporary_ne i).1).trans read

/-- Follow all original pointer loads and stores; later pointer reads are
transported through the actual earlier stores using source allocation separation. -/
theorem execute_effect {initial before after : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (lhs rhs result sign : BitVec 64)
    (entryRead : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (inputs : operands le lhs rhs result sign)
    (effect : Effect storage lhs rhs result sign after) :
    InternalRun Arm64ProgramEntryLinked.ge 22 (.State Arm64Nop.handler Math.stores k e le before)
      (.State Arm64Nop.handler .Sskip k e (temps le (fun i => (storage.flags (flagIndex i)).block)) after) := by
  obtain ⟨m1,m2,m3,s0,s1,s2,s3⟩ := effect.stores
  let blocks := fun i => (storage.flags (flagIndex i)).block
  let le1 := le.set (temporary 0) (.Vptr (blocks 0) 0)
  let le2 := le1.set (temporary 1) (.Vptr (blocks 1) 0)
  let le3 := le2.set (temporary 2) (.Vptr (blocks 2) 0)
  have headerOther (i : Fin 4) : (storage.flags (flagIndex i)).block ≠ entry.block :=
    flag_separate storage i _ _ _ entry.binding (flag_header_names i)
  have pointers0 (i : Fin 4) : CC.Mem.load CC.Mptr before entry.block (offset i) = some (.Vptr (blocks i) 0) := by
    simpa only [pointer_offset] using storage.flagPointers (flagIndex i)
  have pointers1 (i : Fin 4) : CC.Mem.load CC.Mptr m1 entry.block (offset i) = some (.Vptr (blocks i) 0) :=
    (CC.Mem.load_store_other s0 CC.Mptr _ _ (.inl (Ne.symm (headerOther 0)))).trans (pointers0 i)
  have pointers2 (i : Fin 4) : CC.Mem.load CC.Mptr m2 entry.block (offset i) = some (.Vptr (blocks i) 0) :=
    (CC.Mem.load_store_other s1 CC.Mptr _ _ (.inl (Ne.symm (headerOther 1)))).trans (pointers1 i)
  have pointers3 (i : Fin 4) : CC.Mem.load CC.Mptr m3 entry.block (offset i) = some (.Vptr (blocks i) 0) :=
    (CC.Mem.load_store_other s2 CC.Mptr _ _ (.inl (Ne.symm (headerOther 2)))).trans (pointers2 i)
  have entry1 := entry_set le entry.block 0 (.Vptr (blocks 0) 0) entryRead
  have entry2 := entry_set le1 entry.block 1 (.Vptr (blocks 1) 0) entry1
  have entry3 := entry_set le2 entry.block 2 (.Vptr (blocks 2) 0) entry2
  have inputs1 := operands_set le lhs rhs result sign 0 (.Vptr (blocks 0) 0) inputs
  have inputs2 := operands_set le1 lhs rhs result sign 1 (.Vptr (blocks 1) 0) inputs1
  have inputs3 := operands_set le2 lhs rhs result sign 2 (.Vptr (blocks 2) 0) inputs2
  have zRun := followed (single e le before m1 (.Kseq (.Ssequence (code 1) (.Ssequence (code 2) (code 3))) k)
    entry.block (blocks 0) lhs rhs result sign 0 entryRead inputs (pointers0 0) s0)
  have nRun := followed (single e le1 m1 m2 (.Kseq (.Ssequence (code 2) (code 3)) k)
    entry.block (blocks 1) lhs rhs result sign 1 entry1 inputs1 (pointers1 1) s1)
  have cRun := followed (single e le2 m2 m3 (.Kseq (code 3) k)
    entry.block (blocks 2) lhs rhs result sign 2 entry2 inputs2 (pointers2 2) s2)
  have vRun := single e le3 m3 after k entry.block (blocks 3) lhs rhs result sign 3 entry3 inputs3 (pointers3 3) s3
  rw [source]
  exact ((zRun.trans nRun).trans cRun).trans vRun

/-- Execute all four original source stores with no assumed store success or
post-state: actual allocation permissions produce the effect and run together. -/
theorem execute_writable {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (lhs rhs result sign : BitVec 64)
    (entryRead : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (inputs : operands le lhs rhs result sign)
    (writable : Writable storage) :
    ∃ after, Effect storage lhs rhs result sign after ∧
      InternalRun Arm64ProgramEntryLinked.ge 22 (.State Arm64Nop.handler Math.stores k e le before)
        (.State Arm64Nop.handler .Sskip k e (temps le (fun i => (storage.flags (flagIndex i)).block)) after) := by
  obtain ⟨after,effect⟩ := write_writable storage lhs rhs result sign writable
  exact ⟨after,effect,execute_effect storage e le k lhs rhs result sign entryRead inputs effect⟩

set_option hygiene false in
private theorem exit_loop (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    InternalRun Arm64ProgramEntryLinked.ge 7
      (.State Arm64Nop.handler .Sskip (Math.continuation k) e le m)
      (.State Arm64Nop.handler .Sskip k e le m) := by
  run_tac do
    for _ in [:7] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp only [Math.continuation, CC.doStep] <;> rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

/-- The entire original CMP SUB flag loop: real arithmetic44, real stores22,
and both original loop/switch exits7. Inputs and resulting flag bytes are
connected through the exact computed arithmetic map, not a readback premise. -/
theorem execute_loop_writable {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (lhs rhs : BitVec 64) (narrow : Bool)
    (entryRead : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (effective : le.get Arm64Program.___a64_l_width = some (RhsCall.width narrow))
    (lhsRead : le.get Arm64Program.___a64_l_lhs__4 = some (.Vlong lhs))
    (rhsRead : le.get Arm64Program.___a64_l_rhs__4 = some (.Vlong rhs))
    (writable : Writable storage) :
    ∃ after, Effect storage (Math.left lhs narrow) (Math.right rhs narrow)
        (Math.result lhs rhs narrow) (Math.sign narrow) after ∧
      InternalRun Arm64ProgramEntryLinked.ge 73 (.State Arm64Nop.handler RhsCall.flags k e le before)
        (.State Arm64Nop.handler .Sskip k e
          (temps (Math.temps le lhs rhs narrow) (fun i => (storage.flags (flagIndex i)).block)) after) := by
  have mathRun := Math.execute Arm64ProgramEntryLinked.ge e le before k lhs rhs narrow effective lhsRead rhsRead
  have entryAfter : (Math.temps le lhs rhs narrow).get Arm64Program._entry = some (.Vptr entry.block 0) := by
    dsimp only [Math.temps,Math.readyTemps]
    repeat rw [CC.PTree.gso _ _ _ _ (by decide +kernel)]
    exact entryRead
  obtain ⟨_,hs,hl,hr,hv⟩ := Math.values le lhs rhs narrow
  have inputs : operands (Math.temps le lhs rhs narrow) (Math.left lhs narrow) (Math.right rhs narrow)
      (Math.result lhs rhs narrow) (Math.sign narrow) := ⟨hl,hr,hv,hs⟩
  obtain ⟨after,effect,storeRun⟩ := execute_writable storage e (Math.temps le lhs rhs narrow) (Math.continuation k)
    (Math.left lhs narrow) (Math.right rhs narrow) (Math.result lhs rhs narrow) (Math.sign narrow)
    entryAfter inputs writable
  exact ⟨after,effect,(mathRun.trans storeRun).trans (exit_loop e _ after k)⟩


/-- Original whole-access convenience specialization, retaining the accepted API. -/
theorem write {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry) (lhs rhs result sign : BitVec 64)
    (access : before.access = (allocation initial).2.access) :
    ∃ after, Effect storage lhs rhs result sign after :=
  write_writable storage lhs rhs result sign (writable_of_access storage access)

/-- Original whole-access convenience specialization, retaining the accepted API. -/
theorem execute {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (lhs rhs result sign : BitVec 64)
    (entryRead : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (inputs : operands le lhs rhs result sign)
    (access : before.access = (allocation initial).2.access) :
    ∃ after, Effect storage lhs rhs result sign after ∧
      InternalRun Arm64ProgramEntryLinked.ge 22 (.State Arm64Nop.handler Math.stores k e le before)
        (.State Arm64Nop.handler .Sskip k e (temps le (fun i => (storage.flags (flagIndex i)).block)) after) :=
  execute_writable storage e le k lhs rhs result sign entryRead inputs (writable_of_access storage access)

/-- Original whole-access convenience specialization, retaining the accepted API. -/
theorem execute_loop {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (lhs rhs : BitVec 64) (narrow : Bool)
    (entryRead : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (effective : le.get Arm64Program.___a64_l_width = some (RhsCall.width narrow))
    (lhsRead : le.get Arm64Program.___a64_l_lhs__4 = some (.Vlong lhs))
    (rhsRead : le.get Arm64Program.___a64_l_rhs__4 = some (.Vlong rhs))
    (access : before.access = (allocation initial).2.access) :
    ∃ after, Effect storage (Math.left lhs narrow) (Math.right rhs narrow)
        (Math.result lhs rhs narrow) (Math.sign narrow) after ∧
      InternalRun Arm64ProgramEntryLinked.ge 73 (.State Arm64Nop.handler RhsCall.flags k e le before)
        (.State Arm64Nop.handler .Sskip k e
          (temps (Math.temps le lhs rhs narrow) (fun i => (storage.flags (flagIndex i)).block)) after) :=
  execute_loop_writable storage e le k lhs rhs narrow entryRead effective lhsRead rhsRead (writable_of_access storage access)

/-- Real caller allocation/free frames preserve exactly the owned flag-cell
permissions, even when unrelated access-map entries change. -/
theorem Writable.frame {initial before after : CC.Mem} {entry : HeaderLocal initial}
    {storage : Storage initial before entry} (writable : Writable storage)
    (nextStorage : Storage initial after entry) (frontier : CC.Block)
    (bound : (allocation initial).2.nextblock.toNat ≤ frontier.toNat)
    (frame : FrameBelow frontier before after) : Writable nextStorage := by
  intro i
  have same : (nextStorage.flags (flagIndex i)).block = (storage.flags (flagIndex i)).block :=
    congrArg Prod.fst (Option.some.inj ((nextStorage.flags (flagIndex i)).binding.symm.trans
      (storage.flags (flagIndex i)).binding))
  rw [same]
  have owned := Nat.lt_of_lt_of_le (storage.flags (flagIndex i)).owned bound
  exact (CC.Mem.validAccess_congr (m1 := after) (m2 := before)
    (chunk := .Mint8unsigned) (b := (storage.flags (flagIndex i)).block) (ofs := 0) (p := .Writable)
    (fun o => by simp only [CC.Mem.perm,(frame _ owned).2])).trans (writable i)

/-- Real stores preserve permissions while changing the reached flag contents. -/
theorem Writable.access {initial before after : CC.Mem} {entry : HeaderLocal initial}
    {storage : Storage initial before entry} (writable : Writable storage)
    (nextStorage : Storage initial after entry) (access : after.access = before.access) :
    Writable nextStorage := by
  intro i
  have same : (nextStorage.flags (flagIndex i)).block = (storage.flags (flagIndex i)).block :=
    congrArg Prod.fst (Option.some.inj ((nextStorage.flags (flagIndex i)).binding.symm.trans
      (storage.flags (flagIndex i)).binding))
  rw [same]
  exact (CC.Mem.validAccess_congr (m1 := after) (m2 := before)
    (chunk := .Mint8unsigned) (b := (storage.flags (flagIndex i)).block) (ofs := 0) (p := .Writable)
    (fun o => by simp only [CC.Mem.perm,access])).trans (writable i)

end KProgFormal.ClightRefinement.Arm64Compare.Stores
