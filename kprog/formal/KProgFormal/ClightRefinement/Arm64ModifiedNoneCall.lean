import KProgFormal.ClightRefinement.Arm64ModifiedNone

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64Modified.NoneCall
open Arm64RegisterReads (GprLayout)
def arguments (b : CC.Block) (ofs : CC.Integers.Ptrofs) (reg : BitVec 64) : List CC.Val :=
  [.Vptr b ofs,.Vlong reg,.Vint 0,.Vint 0,.Vint 8]

def initialTemps (b : CC.Block) (ofs : CC.Integers.Ptrofs) (reg : BitVec 64) : CC.TempEnv :=
  (((((CC.createUndefTemps Read.handler.fn_temps).set Arm64Program._entry (.Vptr b ofs)).set
    Arm64Program._reg (.Vlong reg)).set Arm64Program._mod (.Vint (0#32))).set
    Arm64Program._shift (.Vint (0#32))).set Arm64Program._width (.Vint 8)

private theorem names :
    CC.listNorepet (CC.varNames Read.handler.fn_vars) ∧
    CC.listNorepet (CC.varNames Read.handler.fn_params) ∧
    CC.listDisjoint (CC.varNames Read.handler.fn_params) (CC.varNames Read.handler.fn_temps) := by
  decide +kernel

/-- Bind all five real parameters and the actual local temporaries. Empty
source fn_vars means entry keeps the exact incoming memory and frontier. -/
theorem entry_bound (world : CC.CGenv) (m : CC.Mem) (b : CC.Block) (ofs : CC.Integers.Ptrofs)
    (reg : BitVec 64) :
    CC.doFunctionEntry2 world Read.handler (arguments b ofs reg) m =
      some (CC.emptyEnv, initialTemps b ofs reg, m) := by
  unfold CC.doFunctionEntry2
  rw [ite_eq_left names]
  rfl

theorem entry_observations (b : CC.Block) (ofs : CC.Integers.Ptrofs) (reg : BitVec 64) :
    (initialTemps b ofs reg).get Arm64Program._entry = some (.Vptr b ofs) ∧
    (initialTemps b ofs reg).get Arm64Program._reg = some (.Vlong reg) ∧
    (initialTemps b ofs reg).get Arm64Program._mod = some (.Vint (0#32)) ∧
    (initialTemps b ofs reg).get Arm64Program._shift = some (.Vint (0#32)) ∧
    (initialTemps b ofs reg).get Arm64Program._width = some (.Vint 8) := by
  simp +decide [initialTemps, CC.PTree.gso]

open Prefix (modifiedCont readerCont)

def readTemps (b cb vb tb kb : CC.Block) (ofs co vo to ko : CC.Integers.Ptrofs)
    (i : Fin 31) (value : BitVec 64) : CC.TempEnv :=
  Read.finishTemps (Read.prefixTemps (initialTemps b ofs (BitVec.ofNat 64 i.val))
    (.Vptr b ofs) (.Vptr cb co) (.Vptr vb vo) (.Vptr tb to) (.Vptr kb ko)
    (.Vlong value) (BitVec.ofNat 64 i.val) 0) value

set_option hygiene false in
/-- The actual entry and original loop prefix reach the original inlined read. -/
theorem enter_read (world : CC.CGenv) (b : CC.Block) (ofs : CC.Integers.Ptrofs)
    (reg : BitVec 64) (m : CC.Mem) (k : CC.Cont) :
    InternalRun world 4 (.Callstate (.Internal Read.handler) (arguments b ofs reg) k m)
      (.State Read.handler Read.readLoop (readerCont k) CC.emptyEnv (initialTemps b ofs reg) m) := by
  run_tac do
    for _ in [:4] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp only [CC.doStep, entry_bound,
        Read.handler_source, readerCont, modifiedCont] <;> rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

/-- Real function entry, inlined scalar reading and continuation resume reach
its unchanged modifier loop, preserving the exact incoming whole heap. -/
theorem read_prefix_bound (world : CC.CGenv) (layout : GprLayout world) (i : Fin 31) (b cb vb tb kb : CC.Block)
    (ofs co vo to ko : CC.Integers.Ptrofs) (m : CC.Mem) (k : CC.Cont)
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
    InternalRun world 74
      (.Callstate (.Internal Read.handler) (arguments b ofs (BitVec.ofNat 64 i.val)) k m)
      (.State Read.handler Read.modify (modifiedCont k) CC.emptyEnv
        (Read.finishTemps (Read.prefixTemps (initialTemps b ofs (BitVec.ofNat 64 i.val))
          (.Vptr b ofs) (.Vptr cb co) (.Vptr vb vo) (.Vptr tb to) (.Vptr kb ko)
          (.Vlong value) (BitVec.ofNat 64 i.val) 0) value) m) := by
  have observations := entry_observations b ofs (BitVec.ofNat 64 i.val)
  have entered := enter_read world b ofs (BitVec.ofNat 64 i.val) m k
  have executed := Read.scalar_bound world layout i b cb vb tb kb ofs co vo to ko m (readerCont k)
    CC.emptyEnv (initialTemps b ofs (BitVec.ofNat 64 i.val)) value
    observations.1 observations.2.1 cells cellSlot tags tagSlot cell kind
  let after := Read.finishTemps (Read.prefixTemps (initialTemps b ofs (BitVec.ofNat 64 i.val))
    (.Vptr b ofs) (.Vptr cb co) (.Vptr vb vo) (.Vptr tb to) (.Vptr kb ko)
    (.Vlong value) (BitVec.ofNat 64 i.val) 0) value
  have resumed : InternalRun world 1
      (.State Read.handler .Sskip (readerCont k) CC.emptyEnv after m)
      (.State Read.handler Read.modify (modifiedCont k) CC.emptyEnv after m) := by
    apply InternalRun.step
    · trivial
    · apply CC.doStep_sound
      rfl
    · exact InternalRun.refl _
  exact (entered.trans executed).trans resumed



private theorem observations (b cb vb tb kb : CC.Block) (ofs co vo to ko : CC.Integers.Ptrofs)
    (i : Fin 31) (value : BitVec 64) :
    (readTemps b cb vb tb kb ofs co vo to ko i value).get Arm64Program.___a64_modified_input = some (.Vlong value) ∧
    (readTemps b cb vb tb kb ofs co vo to ko i value).get Arm64Program._mod = some (.Vint 0) ∧
    (readTemps b cb vb tb kb ofs co vo to ko i value).get Arm64Program._shift = some (.Vint 0) ∧
    (readTemps b cb vb tb kb ofs co vo to ko i value).get Arm64Program._width = some (.Vint 8) := by
  dsimp only [readTemps,Read.finishTemps,Read.prefixTemps,initialTemps]
  refine ⟨?_,?_,?_,?_⟩
  all_goals repeat first
    | rw [CC.PTree.gss]
    | rw [CC.PTree.gso _ _ _ _ (by decide +kernel)]
  all_goals rfl

private theorem return_type : Read.handler.fn_return = CC.tulong := rfl

set_option hygiene false in
/-- Real source outer-loop exit, return evaluation and empty local freeList. -/
theorem return_bound (world : CC.CGenv) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (value : BitVec 64) (result : le.get Arm64Program._result = some (.Vlong value)) :
    InternalRun world 4 (.State Read.handler .Sskip (modifiedCont k) CC.emptyEnv le m)
      (.Returnstate (.Vlong value) (CC.callCont k) m) := by
  have empty : (CC.PTree.empty : CC.Env).elements = [] := rfl
  run_tac do
    for _ in [:4] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [CC.doStep,modifiedCont,
        Read.ret,return_type,result,CC.doEvalExpr,CC.typeof,CC.Cop.semCast,CC.Cop.classifyCast,
        CC.tulong,CC.Archi.ptr64,CC.blocksOfEnv,CC.Mem.freeList,CC.emptyEnv,empty,
        CC.E0,CC.Eapp,List.nil_append,List.append_nil,ite_true,ite_false] <;> try rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

/-- The complete original NONE(0)/width8 function returns the actual X word
through entry, raw/tag reading, modifier and real return, with exact same heap. -/
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
    ∃ count, InternalRun world count
      (.Callstate (.Internal Read.handler) (arguments b ofs (BitVec.ofNat 64 i.val)) k m)
      (.Returnstate (.Vlong value) (CC.callCont k) m) := by
  have entered := read_prefix_bound world layout i b cb vb tb kb ofs co vo to ko m k value
    cells cellSlot tags tagSlot cell kind
  have observed := observations b cb vb tb kb ofs co vo to ko i value
  have modified := None.execute world CC.emptyEnv
    (readTemps b cb vb tb kb ofs co vo to ko i value) m (modifiedCont k) value
    observed.1 observed.2.1 observed.2.2.1 observed.2.2.2
  have returned := return_bound world (None.temps (readTemps b cb vb tb kb ofs co vo to ko i value) value) m k value
    (by exact CC.PTree.gss _ _ _)
  exact ⟨_,(entered.trans modified).trans returned⟩

end KProgFormal.ClightRefinement.Arm64Modified.NoneCall
