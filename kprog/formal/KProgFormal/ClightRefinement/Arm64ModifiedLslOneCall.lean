import KProgFormal.ClightRefinement.Arm64ModifiedCall

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64Modified.LslOne
open Arm64RegisterReads (GprLayout)

/-- Actual five-argument call for the original width-four LSL1 modifier. -/
def arguments (b : CC.Block) (ofs : CC.Integers.Ptrofs) (reg : BitVec 64) : List CC.Val :=
  [.Vptr b ofs, .Vlong reg, .Vint (1#32), .Vint (1#32), Arm64Compare.RhsCall.width true]

private def initialTemps (b : CC.Block) (ofs : CC.Integers.Ptrofs) (reg : BitVec 64) : CC.TempEnv :=
  (((((CC.createUndefTemps Read.handler.fn_temps).set Arm64Program._entry (.Vptr b ofs)).set
    Arm64Program._reg (.Vlong reg)).set Arm64Program._mod (.Vint (1#32))).set
    Arm64Program._shift (.Vint (1#32))).set Arm64Program._width (Arm64Compare.RhsCall.width true)

private theorem entry (world : CC.CGenv) (m : CC.Mem) (b : CC.Block) (ofs : CC.Integers.Ptrofs)
    (reg : BitVec 64) :
    CC.doFunctionEntry2 world Read.handler (arguments b ofs reg) m =
      some (CC.emptyEnv, initialTemps b ofs reg, m) := by
  have names : CC.listNorepet (CC.varNames Read.handler.fn_vars) ∧
      CC.listNorepet (CC.varNames Read.handler.fn_params) ∧
      CC.listDisjoint (CC.varNames Read.handler.fn_params) (CC.varNames Read.handler.fn_temps) := by decide +kernel
  unfold CC.doFunctionEntry2
  rw [ite_eq_left names]
  rfl

set_option hygiene false in
private theorem enter_read (world : CC.CGenv) (b : CC.Block) (ofs : CC.Integers.Ptrofs)
    (reg : BitVec 64) (m : CC.Mem) (k : CC.Cont) :
    InternalRun world 4 (.Callstate (.Internal Read.handler) (arguments b ofs reg) k m)
      (.State Read.handler Read.readLoop (Prefix.readerCont k) CC.emptyEnv (initialTemps b ofs reg) m) := by
  run_tac do
    for _ in [:4] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp only [CC.doStep, entry,
        Read.handler_source, Prefix.readerCont, Prefix.modifiedCont] <;> rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

private def readTemps (b cb vb tb kb : CC.Block) (ofs co vo to ko : CC.Integers.Ptrofs)
    (i : Fin 31) (value : BitVec 64) : CC.TempEnv :=
  Read.finishTemps (Read.prefixTemps (initialTemps b ofs (BitVec.ofNat 64 i.val))
    (.Vptr b ofs) (.Vptr cb co) (.Vptr vb vo) (.Vptr tb to) (.Vptr kb ko)
    (.Vlong value) (BitVec.ofNat 64 i.val) 0) value

private theorem observations (b cb vb tb kb : CC.Block) (ofs co vo to ko : CC.Integers.Ptrofs)
    (i : Fin 31) (value : BitVec 64) :
    (readTemps b cb vb tb kb ofs co vo to ko i value).get Arm64Program.___a64_modified_input = some (.Vlong value) ∧
    (readTemps b cb vb tb kb ofs co vo to ko i value).get Arm64Program._mod = some (.Vint (1#32)) ∧
    (readTemps b cb vb tb kb ofs co vo to ko i value).get Arm64Program._shift = some (.Vint (1#32)) ∧
    (readTemps b cb vb tb kb ofs co vo to ko i value).get Arm64Program._width = some (Arm64Compare.RhsCall.width true) := by
  dsimp only [readTemps, Read.finishTemps, Read.prefixTemps, initialTemps]
  refine ⟨?_, ?_, ?_, ?_⟩
  all_goals
    repeat first
      | rw [CC.PTree.gss]
      | rw [CC.PTree.gso _ _ _ _ (by decide +kernel)]

set_option hygiene false in
private theorem returned (world : CC.CGenv) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (value : BitVec 64) (result : le.get Arm64Program._result = some (.Vlong value)) :
    InternalRun world 4
      (.State Read.handler .Sskip (Prefix.modifiedCont k) CC.emptyEnv le m)
      (.Returnstate (.Vlong value) (CC.callCont k) m) := by
  have returnType : Read.handler.fn_return = CC.tulong := rfl
  have empty : (CC.PTree.empty : CC.Env).elements = [] := rfl
  run_tac do
    for _ in [:4] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [CC.doStep, Prefix.modifiedCont,
        Read.ret, returnType, result, CC.doEvalExpr, CC.typeof, CC.Cop.semCast, CC.Cop.classifyCast,
        CC.tulong, CC.Archi.ptr64, CC.blocksOfEnv, CC.Mem.freeList, CC.emptyEnv, empty,
        CC.E0, CC.Eapp, List.nil_append, List.append_nil, ite_true, ite_false] <;> try rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

/-- Run the real width-four LSL1 helper from five-argument entry through its
actual scalar-cell read, modifier, loop exit and return. The incoming table
loads derive every intermediate value and the entire heap remains the same. -/
theorem execute (world : CC.CGenv) (layout : GprLayout world) (i : Fin 31) (b cb vb tb kb : CC.Block)
    (ofs co vo to ko : CC.Integers.Ptrofs) (m : CC.Mem) (k : CC.Cont) (value : BitVec 64)
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
      (.Callstate (.Internal Read.handler) (arguments b ofs (BitVec.ofNat 64 i.val)) k m)
      (.Returnstate (.Vlong ((value <<< 1) &&& (4294967295#64))) (CC.callCont k) m) := by
  have entered := enter_read world b ofs (BitVec.ofNat 64 i.val) m k
  have entryObs : (initialTemps b ofs (BitVec.ofNat 64 i.val)).get Arm64Program._entry = some (.Vptr b ofs) ∧
      (initialTemps b ofs (BitVec.ofNat 64 i.val)).get Arm64Program._reg = some (.Vlong (BitVec.ofNat 64 i.val)) := by
    constructor <;> simp +decide only [initialTemps, CC.PTree.gso, CC.PTree.gss]
  have read := Read.scalar_bound world layout i b cb vb tb kb ofs co vo to ko m (Prefix.readerCont k)
    CC.emptyEnv (initialTemps b ofs (BitVec.ofNat 64 i.val)) value
    entryObs.1 entryObs.2 cells cellSlot tags tagSlot cell kind
  have resumed : InternalRun world 1
      (.State Read.handler .Sskip (Prefix.readerCont k) CC.emptyEnv (readTemps b cb vb tb kb ofs co vo to ko i value) m)
      (.State Read.handler Read.modify (Prefix.modifiedCont k) CC.emptyEnv (readTemps b cb vb tb kb ofs co vo to ko i value) m) :=
    .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  have obs := observations b cb vb tb kb ofs co vo to ko i value
  obtain ⟨le', modified, result⟩ := Modifier.execute_lsl_one world CC.emptyEnv
    (readTemps b cb vb tb kb ofs co vo to ko i value) m (Prefix.modifiedCont k) value
    obs.1 obs.2.1 obs.2.2.1 obs.2.2.2
  exact (((entered.trans read).trans resumed).trans modified).trans
    (returned world le' m k ((value <<< 1) &&& (4294967295#64)) result)

end KProgFormal.ClightRefinement.Arm64Modified.LslOne
