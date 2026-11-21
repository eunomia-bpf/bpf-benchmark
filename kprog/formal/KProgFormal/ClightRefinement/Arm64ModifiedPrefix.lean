import KProgFormal.ClightRefinement.Arm64ModifiedRead

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64Modified.Prefix
open Arm64RegisterReads (GprLayout)
open Arm64Compare.RhsCall (arguments width)

def initialTemps (b : CC.Block) (ofs : CC.Integers.Ptrofs) (reg : BitVec 64) (narrow : Bool) : CC.TempEnv :=
  (((((CC.createUndefTemps Read.handler.fn_temps).set Arm64Program._entry (.Vptr b ofs)).set
    Arm64Program._reg (.Vlong reg)).set Arm64Program._mod (.Vint (1#32))).set
    Arm64Program._shift (.Vint (0#32))).set Arm64Program._width (width narrow)

private theorem names :
    CC.listNorepet (CC.varNames Read.handler.fn_vars) ∧
    CC.listNorepet (CC.varNames Read.handler.fn_params) ∧
    CC.listDisjoint (CC.varNames Read.handler.fn_params) (CC.varNames Read.handler.fn_temps) := by
  decide +kernel

/-- Bind all five real parameters and the actual local temporaries. Empty
source fn_vars means entry keeps the exact incoming memory and frontier. -/
theorem entry_bound (world : CC.CGenv) (m : CC.Mem) (b : CC.Block) (ofs : CC.Integers.Ptrofs)
    (reg : BitVec 64) (narrow : Bool) :
    CC.doFunctionEntry2 world Read.handler (arguments b ofs reg narrow) m =
      some (CC.emptyEnv, initialTemps b ofs reg narrow, m) := by
  unfold CC.doFunctionEntry2
  rw [ite_eq_left names]
  rfl

theorem entry_observations (b : CC.Block) (ofs : CC.Integers.Ptrofs) (reg : BitVec 64) (narrow : Bool) :
    (initialTemps b ofs reg narrow).get Arm64Program._entry = some (.Vptr b ofs) ∧
    (initialTemps b ofs reg narrow).get Arm64Program._reg = some (.Vlong reg) ∧
    (initialTemps b ofs reg narrow).get Arm64Program._mod = some (.Vint (1#32)) ∧
    (initialTemps b ofs reg narrow).get Arm64Program._shift = some (.Vint (0#32)) ∧
    (initialTemps b ofs reg narrow).get Arm64Program._width = some (width narrow) := by
  simp +decide [initialTemps, CC.PTree.gso]

def modifiedCont (k : CC.Cont) : CC.Cont :=
  .Kloop1 (.Ssequence Read.readLoop Read.modify) .Sbreak (.Kseq Read.ret k)
def readerCont (k : CC.Cont) : CC.Cont := .Kseq Read.modify (modifiedCont k)

set_option hygiene false in
/-- The actual entry and original loop prefix reach the original inlined read. -/
theorem enter_read (world : CC.CGenv) (b : CC.Block) (ofs : CC.Integers.Ptrofs)
    (reg : BitVec 64) (narrow : Bool) (m : CC.Mem) (k : CC.Cont) :
    InternalRun world 4 (.Callstate (.Internal Read.handler) (arguments b ofs reg narrow) k m)
      (.State Read.handler Read.readLoop (readerCont k) CC.emptyEnv (initialTemps b ofs reg narrow) m) := by
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
    InternalRun world 74
      (.Callstate (.Internal Read.handler) (arguments b ofs (BitVec.ofNat 64 i.val) narrow) k m)
      (.State Read.handler Read.modify (modifiedCont k) CC.emptyEnv
        (Read.finishTemps (Read.prefixTemps (initialTemps b ofs (BitVec.ofNat 64 i.val) narrow)
          (.Vptr b ofs) (.Vptr cb co) (.Vptr vb vo) (.Vptr tb to) (.Vptr kb ko)
          (.Vlong value) (BitVec.ofNat 64 i.val) 0) value) m) := by
  have observations := entry_observations b ofs (BitVec.ofNat 64 i.val) narrow
  have entered := enter_read world b ofs (BitVec.ofNat 64 i.val) narrow m k
  have executed := Read.scalar_bound world layout i b cb vb tb kb ofs co vo to ko m (readerCont k)
    CC.emptyEnv (initialTemps b ofs (BitVec.ofNat 64 i.val) narrow) value
    observations.1 observations.2.1 cells cellSlot tags tagSlot cell kind
  let after := Read.finishTemps (Read.prefixTemps (initialTemps b ofs (BitVec.ofNat 64 i.val) narrow)
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

end KProgFormal.ClightRefinement.Arm64Modified.Prefix
