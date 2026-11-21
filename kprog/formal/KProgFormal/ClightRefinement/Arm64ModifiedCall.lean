import KProgFormal.ClightRefinement.Arm64ModifiedModifier

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64Modified.Call
open Arm64RegisterReads (GprLayout)
open Arm64Compare.RhsCall (arguments width)

private def readTemps (b cb vb tb kb : CC.Block) (ofs co vo to ko : CC.Integers.Ptrofs)
    (i : Fin 31) (value : BitVec 64) (narrow : Bool) : CC.TempEnv :=
  Read.finishTemps (Read.prefixTemps (Prefix.initialTemps b ofs (BitVec.ofNat 64 i.val) narrow)
    (.Vptr b ofs) (.Vptr cb co) (.Vptr vb vo) (.Vptr tb to) (.Vptr kb ko)
    (.Vlong value) (BitVec.ofNat 64 i.val) 0) value

private theorem observations (b cb vb tb kb : CC.Block) (ofs co vo to ko : CC.Integers.Ptrofs)
    (i : Fin 31) (value : BitVec 64) (narrow : Bool) :
    (readTemps b cb vb tb kb ofs co vo to ko i value narrow).get Arm64Program.___a64_modified_input = some (.Vlong value) ∧
    (readTemps b cb vb tb kb ofs co vo to ko i value narrow).get Arm64Program._mod = some (.Vint (1#32)) ∧
    (readTemps b cb vb tb kb ofs co vo to ko i value narrow).get Arm64Program._shift = some (.Vint (0#32)) ∧
    (readTemps b cb vb tb kb ofs co vo to ko i value narrow).get Arm64Program._width = some (width narrow) := by
  dsimp only [readTemps, Read.finishTemps, Read.prefixTemps, Prefix.initialTemps]
  refine ⟨?_, ?_, ?_, ?_⟩
  all_goals
    repeat first
      | rw [CC.PTree.gss]
      | rw [CC.PTree.gso _ _ _ _ (by decide +kernel)]

private theorem return_type : Read.handler.fn_return = CC.tulong := rfl

set_option hygiene false in
/-- Real outer-loop exit, source return evaluation and empty local freeList. -/
theorem return_bound (world : CC.CGenv) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (value : BitVec 64) (narrow : Bool) :
    InternalRun world 4
      (.State Read.handler .Sskip (Prefix.modifiedCont k) CC.emptyEnv (Modifier.finalTemps le narrow value) m)
      (.Returnstate (.Vlong (Modifier.result value narrow)) (CC.callCont k) m) := by
  have empty : (CC.PTree.empty : CC.Env).elements = [] := rfl
  run_tac do
    for _ in [:4] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [CC.doStep, Prefix.modifiedCont,
        Read.ret, Modifier.finalTemps, return_type, CC.PTree.gss, CC.doEvalExpr, CC.typeof,
        CC.Cop.semCast, CC.Cop.classifyCast, CC.tulong, CC.Archi.ptr64,
        CC.blocksOfEnv, CC.Mem.freeList, CC.emptyEnv, empty, CC.E0, CC.Eapp,
        List.nil_append, List.append_nil, ite_true, ite_false] <;> try rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

/-- The actual helper's entry, read, LSL0/width mask and real return preserve
all memory and derive the returned word solely from actual table loads. -/
theorem execute (world : CC.CGenv) (layout : GprLayout world) (i : Fin 31) (b cb vb tb kb : CC.Block)
    (ofs co vo to ko : CC.Integers.Ptrofs) (m : CC.Mem) (k : CC.Cont) (narrow : Bool)
    (value : BitVec 64)
    (cells : CC.Mem.loadv CC.Mptr m (.Vptr b ofs) = some (.Vptr cb co))
    (cellSlot : CC.Mem.loadv CC.Mptr m (.Vptr cb (CC.Integers.Ptrofs.add co
      (CC.Integers.Ptrofs.repr (8 * (i.val : CC.Z))))) = some (.Vptr vb vo))
    (tags : CC.Mem.loadv CC.Mptr m (.Vptr b (CC.Integers.Ptrofs.add ofs
      (CC.Integers.Ptrofs.repr 8))) = some (.Vptr tb to))
    (tagSlot : CC.Mem.loadv CC.Mptr m (.Vptr tb (CC.Integers.Ptrofs.add to
      (CC.Integers.Ptrofs.repr (8 * (i.val : CC.Z))))) = some (.Vptr kb ko))
    (cell : CC.Mem.loadv .Mint64 m (.Vptr vb vo) = some (.Vlong value))
    (kind : CC.Mem.loadv .Mint8unsigned m (.Vptr kb ko) = some (.Vint 0)) :
    InternalRun world 119
      (.Callstate (.Internal Read.handler) (arguments b ofs (BitVec.ofNat 64 i.val) narrow) k m)
      (.Returnstate (.Vlong (Modifier.result value narrow)) (CC.callCont k) m) := by
  have entered := Prefix.read_prefix_bound world layout i b cb vb tb kb ofs co vo to ko m k narrow value
    cells cellSlot tags tagSlot cell kind
  have observed := observations b cb vb tb kb ofs co vo to ko i value narrow
  have modified := Modifier.execute_lsl_zero world CC.emptyEnv
    (readTemps b cb vb tb kb ofs co vo to ko i value narrow) m (Prefix.modifiedCont k) value narrow
    observed.1 observed.2.1 observed.2.2.1 observed.2.2.2
  have returned := return_bound world (readTemps b cb vb tb kb ofs co vo to ko i value narrow) m k value narrow
  exact (entered.trans modified).trans returned

/-- All relational executions of the actual closed helper are silent prefixes
of the same unique terminal return; no infinite execution is possible. -/
theorem all_behaviors (world : CC.CGenv) (layout : GprLayout world) (i : Fin 31) (b cb vb tb kb : CC.Block)
    (ofs co vo to ko : CC.Integers.Ptrofs) (m : CC.Mem) (narrow : Bool)
    (value : BitVec 64)
    (cells : CC.Mem.loadv CC.Mptr m (.Vptr b ofs) = some (.Vptr cb co))
    (cellSlot : CC.Mem.loadv CC.Mptr m (.Vptr cb (CC.Integers.Ptrofs.add co
      (CC.Integers.Ptrofs.repr (8 * (i.val : CC.Z))))) = some (.Vptr vb vo))
    (tags : CC.Mem.loadv CC.Mptr m (.Vptr b (CC.Integers.Ptrofs.add ofs
      (CC.Integers.Ptrofs.repr 8))) = some (.Vptr tb to))
    (tagSlot : CC.Mem.loadv CC.Mptr m (.Vptr tb (CC.Integers.Ptrofs.add to
      (CC.Integers.Ptrofs.repr (8 * (i.val : CC.Z))))) = some (.Vptr kb ko))
    (cell : CC.Mem.loadv .Mint64 m (.Vptr vb vo) = some (.Vlong value))
    (kind : CC.Mem.loadv .Mint8unsigned m (.Vptr kb ko) = some (.Vint 0)) :
    (∀ t other, CC.Star (CC.Step2 world)
      (.Callstate (.Internal Read.handler) (arguments b ofs (BitVec.ofNat 64 i.val) narrow) .Kstop m) t other →
      t = CC.E0 ∧ ∃ remaining, InternalRun world remaining other
        (.Returnstate (.Vlong (Modifier.result value narrow)) .Kstop m)) ∧
    (∀ t other, CC.Star (CC.Step2 world)
      (.Callstate (.Internal Read.handler) (arguments b ofs (BitVec.ofNat 64 i.val) narrow) .Kstop m) t other →
      (∀ u next, ¬ CC.Step2 world other u next) →
      t = CC.E0 ∧ other = .Returnstate (.Vlong (Modifier.result value narrow)) .Kstop m) ∧
    ¬ (∃ states : Nat → CC.State,
      states 0 = .Callstate (.Internal Read.handler) (arguments b ofs (BitVec.ofNat 64 i.val) narrow) .Kstop m ∧
      ∀ j, ∃ t, CC.Step2 world (states j) t (states (j+1))) := by
  have run := execute world layout i b cb vb tb kb ofs co vo to ko m .Kstop narrow value
    cells cellSlot tags tagSlot cell kind
  have stuck : ∀ t next, ¬ CC.Step2 world
      (.Returnstate (.Vlong (Modifier.result value narrow)) .Kstop m) t next := by
    intro t next step
    cases step
  exact ⟨fun _ _ observed => run.finish_prefix stuck observed,
    fun _ _ observed endpoint => run.endpoint_unique stuck observed endpoint,
    run.no_infinite stuck⟩

end KProgFormal.ClightRefinement.Arm64Modified.Call
