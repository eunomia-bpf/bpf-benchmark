import KProgFormal.ClightRefinement.Arm64CompareRhsCall

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64Modified.Read
open Arm64RegisterReads (GprLayout)

def handler : CC.Function := Arm64Program.f_kprog_arm64_program_modified

private structure Pieces where
  readLoop : CC.Stmt
  readBody : CC.Stmt
  raw : CC.Stmt
  tags : CC.Stmt
  materialize : CC.Stmt
  modify : CC.Stmt
  ret : CC.Stmt

private def pieces : Pieces := by
  run_tac do
    let peel (term : Lean.Expr) (constructor : Lean.Name) (arity : Nat) :
        Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity constructor arity do throwError "actual modified read constructors changed"
      pure actual.getAppArgs
    let function ← peel (← Lean.Elab.Term.elabTerm (← `(handler.fn_body)) none) ``CC.Stmt.Ssequence 2
    let outer ← peel function[0]! ``CC.Stmt.Sloop 2
    let pair ← peel outer[0]! ``CC.Stmt.Ssequence 2
    let loop ← peel pair[0]! ``CC.Stmt.Sloop 2
    let read ← peel loop[0]! ``CC.Stmt.Ssequence 2
    let tail ← peel read[1]! ``CC.Stmt.Ssequence 2
    Lean.Elab.Tactic.closeMainGoal `actual_modified_read (← Lean.Meta.mkAppM ``Pieces.mk
      #[pair[0]!, loop[0]!, read[0]!, tail[0]!, tail[1]!, pair[1]!, function[1]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_modified_read_part (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

def readLoop : CC.Stmt := by run_tac cachePart (← `(pieces.readLoop))
def readBody : CC.Stmt := by run_tac cachePart (← `(pieces.readBody))
def raw : CC.Stmt := by run_tac cachePart (← `(pieces.raw))
def tags : CC.Stmt := by run_tac cachePart (← `(pieces.tags))
def materialize : CC.Stmt := by run_tac cachePart (← `(pieces.materialize))
def modify : CC.Stmt := by run_tac cachePart (← `(pieces.modify))
def ret : CC.Stmt := by run_tac cachePart (← `(pieces.ret))

/-- The entire actual helper retains both inlined reading and modification loops. -/
theorem handler_source : handler.fn_body =
    .Ssequence (.Sloop (.Ssequence readLoop modify) .Sbreak) ret := rfl

/-- The actual inlined read retains its raw/tag/materialization stages. -/
theorem read_source : readLoop = .Sloop readBody .Sbreak ∧
    readBody = .Ssequence raw (.Ssequence tags materialize) := ⟨rfl, rfl⟩

def readCont (k : CC.Cont) : CC.Cont := .Kloop1 readBody .Sbreak k

private theorem index_nat (i : Fin 31) : (BitVec.ofNat 64 i.val).toNat = i.val := by
  simp only [BitVec.toNat_ofNat]
  exact Nat.mod_eq_of_lt (by have := i.isLt; omega)

private theorem index_cast (i : Fin 31) (m : CC.Mem) :
    CC.Cop.semCast (.Vlong (BitVec.ofNat 64 i.val)) CC.tulong CC.tuchar m =
      some (.Vint (BitVec.ofNat 32 i.val)) := by
  have small : i.val < 2 ^ 8 := by have := i.isLt; omega
  change some (CC.Val.Vint (CC.Cop.castIntInt .I8 .Unsigned
    (CC.Integers.Int.repr ((BitVec.ofNat 64 i.val).toNat : Int)))) = _
  rw [index_nat]
  change some (CC.Val.Vint (BitVec.ofInt 32 (i.val : Int) &&& (255#32))) = _
  rw [BitVec.ofInt_natCast,
    ← BitVec.setWidth_ofNat_of_le_of_lt (by decide : 8 ≤ 32) small]
  congr 2
  change (BitVec.ofNat 8 i.val).setWidth 32 &&& (BitVec.allOnes 8).setWidth 32 = _
  rw [← BitVec.setWidth_and, BitVec.and_allOnes]

private theorem index_offset (i : Fin 31) :
    CC.Integers.Ptrofs.mul (CC.Integers.Ptrofs.repr 8)
      (CC.Integers.Ptrofs.of_ints (BitVec.ofNat 32 i.val)) =
    CC.Integers.Ptrofs.repr (8 * (i.val : CC.Z)) := by
  have bound := i.isLt
  have norm : (BitVec.ofNat 32 i.val).toNat = i.val := by
    simp only [BitVec.toNat_ofNat]
    exact Nat.mod_eq_of_lt (by omega)
  have signed : (BitVec.ofNat 32 i.val).toInt = (i.val : Int) := by
    rw [BitVec.toInt_eq_toNat_of_lt (by rw [norm]; omega), norm]
  change (8#64) * BitVec.ofInt 64 (BitVec.ofNat 32 i.val).toInt =
    BitVec.ofInt 64 (8 * (i.val : Int))
  simp only [signed, BitVec.ofInt_natCast, ← BitVec.ofNat_mul]
  rw [show (8 : Int) * (i.val : Int) = ((8 * i.val : Nat) : Int) by omega,
    BitVec.ofInt_natCast]

private theorem offset_zero (ofs : CC.Integers.Ptrofs) :
    CC.Integers.Ptrofs.add ofs (CC.Integers.Ptrofs.repr 0) = ofs := BitVec.add_zero ofs

def prefixTemps (le : CC.TempEnv) (entry cells cell tags tagCell value : CC.Val)
    (reg : BitVec 64) (tag : BitVec 8) : CC.TempEnv :=
  let vtag := CC.Val.Vint (tag.setWidth 32)
  (((((((((((((le.set Arm64Program.___a64_l_reg (.Vlong reg)).set
    Arm64Program._t'22 cells).set Arm64Program._t'23 cell).set Arm64Program._t'24 value).set
    Arm64Program._t'1 value).set Arm64Program._t'1 value).set Arm64Program.___a64_read_value value).set
    Arm64Program.___a64_l_reg__1 (.Vlong reg)).set Arm64Program._t'19 tags).set
    Arm64Program._t'20 tagCell).set Arm64Program._t'21 vtag).set Arm64Program._t'2 vtag).set
    Arm64Program._t'2 vtag).set Arm64Program.___a64_read_tag vtag

private theorem read_tag_mask (tag : BitVec 8) :
    tag.setWidth 32 &&& (255#32) = tag.setWidth 32 := by
  change tag.setWidth 32 &&& (BitVec.allOnes 8).setWidth 32 = tag.setWidth 32
  rw [← BitVec.setWidth_and, BitVec.and_allOnes]

/-- The actual inlined read reaches materialization from real table loads.
The arbitrary caller environment and all memory are retained. -/
theorem prefix_bound (world : CC.CGenv) (layout : GprLayout world) (i : Fin 31) (b cb vb tb kb : CC.Block)
    (ofs co vo to ko : CC.Integers.Ptrofs) (m : CC.Mem) (k : CC.Cont) (e : CC.Env) (le : CC.TempEnv)
    (value : CC.Val) (tag : BitVec 8)
    (entryRead : le.get Arm64Program._entry = some (.Vptr b ofs))
    (regRead : le.get Arm64Program._reg = some (.Vlong (BitVec.ofNat 64 i.val)))
    (cells : CC.Mem.loadv CC.Mptr m (.Vptr b ofs) = some (.Vptr cb co))
    (cellSlot : CC.Mem.loadv CC.Mptr m (.Vptr cb (CC.Integers.Ptrofs.add co
      (CC.Integers.Ptrofs.repr (8 * (i.val : CC.Z))))) = some (.Vptr vb vo))
    (tags : CC.Mem.loadv CC.Mptr m (.Vptr b (CC.Integers.Ptrofs.add ofs
      (CC.Integers.Ptrofs.repr 8))) = some (.Vptr tb to))
    (tagSlot : CC.Mem.loadv CC.Mptr m (.Vptr tb (CC.Integers.Ptrofs.add to
      (CC.Integers.Ptrofs.repr (8 * (i.val : CC.Z))))) = some (.Vptr kb ko))
    (cell : CC.Mem.loadv .Mint64 m (.Vptr vb vo) = some value)
    (kind : CC.Mem.loadv .Mint8unsigned m (.Vptr kb ko) = some (.Vint (tag.setWidth 32)))
    (valueCast : CC.Cop.semCast value CC.tulong CC.tulong m = some value) :
    steps world 53 (.State handler readLoop k e le m) =
      some (CC.E0, .State handler materialize (readCont k) e
        (prefixTemps le (.Vptr b ofs) (.Vptr cb co) (.Vptr vb vo) (.Vptr tb to) (.Vptr kb ko)
          value (BitVec.ofNat 64 i.val) tag) m) ∧
    InternalPath world 53 (.State handler readLoop k e le m) := by
  have bound := i.isLt
  have ne : BitVec.ofNat 64 i.val ≠ (32#64) := by
    intro h
    have eq := congrArg BitVec.toNat h
    rw [index_nat] at eq
    simp only [BitVec.toNat_ofNat] at eq
    omega
  have lt : (BitVec.ofNat 64 i.val).ult (31#64) = true := by
    rw [BitVec.ult_eq_decide, index_nat]
    simp only [BitVec.toNat_ofNat]
    simp [bound]
  have cast := index_cast i m
  simp [CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
    CC.tulong, CC.tuchar, CC.Integers.Int.repr, CC.Integers.MI.repr,
    CC.Integers.Int64.unsigned, CC.Integers.MI.unsigned,
    CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext,
    BitVec.toNat_ofNat, Int.natCast_emod, Option.some.injEq, CC.Val.Vint.injEq] at cast
  simp only [CC.Cop.semCast, CC.Cop.classifyCast, CC.tulong, CC.Archi.ptr64,
    ↓reduceIte] at valueCast
  simp only [CC.Mptr, CC.Archi.ptr64, ↓reduceIte] at cells cellSlot tags tagSlot
  simp +decide [steps, InternalPath, InternalState, readLoop, readBody, raw, tags, materialize, readCont,
    step_seq, step_loop, step_skip_seq, step_skip_loop, step_break_loop, step_set, step_if,
    prefixTemps, entryRead, regRead,
    Arm64Program.s_kprog_arm64_program_modified_0, Arm64Program.s_kprog_arm64_program_modified_1, CC.PTree.gso, CC.doEvalExpr, CC.lvalOfField, CC.doDerefLoc,
    CC.typeof, CC.typeconv, CC.removeAttributes, CC.tattr, CC.accessMode,
    layout.entry, layout.cell, layout.cells, layout.tags, layout.payload,
    CC.Cop.semBinaryOperation, CC.Cop.semCmp, CC.Cop.classifyCmp, CC.Cop.semBinarith,
    CC.Cop.classifyBinarith, CC.Cop.binarithType, CC.Cop.semAdd, CC.Cop.classifyAdd,
    CC.Cop.semAddPtrInt, CC.Cop.ptrofsOfInt, index_offset, cast,
    CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, CC.Cop.castIntLong,
    CC.Cop.boolVal, CC.Cop.classifyBool, CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse,
    CC.Integers.Int64.cmpu, CC.Integers.Int64.eq, CC.Integers.MI.cmpu,
    CC.Integers.Int.eq, CC.Integers.Int.zero, CC.Integers.Int.one,
    CC.Integers.MI.zero, CC.Integers.MI.one, CC.Integers.MI.eq, CC.Integers.MI.ltu, ne, lt,
    CC.Integers.Int.repr, CC.Integers.Int64.repr, CC.Integers.MI.repr,
    CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.Integers.Int64.unsigned,
    CC.Integers.Int.unsigned, CC.Integers.MI.unsigned, offset_zero, read_tag_mask,
    CC.Mptr, CC.Archi.ptr64, CC.tptr, CC.sizeof, CC.tuchar, CC.tint, CC.tuint, CC.tlong, CC.tulong,
    CC.E0, CC.Eapp, cells, cellSlot, tags, tagSlot, cell, kind, valueCast]

def finishTemps (le : CC.TempEnv) (value : BitVec 64) : CC.TempEnv :=
  ((le.set Arm64Program.___a64_mat_value (.Vlong value)).set
    Arm64Program.___a64_mat_tag (.Vint 0)).set Arm64Program.___a64_modified_input (.Vlong value)

set_option hygiene false in
private theorem materialize_scalar (world : CC.CGenv) (e : CC.Env) (le : CC.TempEnv)
    (m : CC.Mem) (k : CC.Cont) (value : BitVec 64)
    (valueRead : le.get Arm64Program.___a64_read_value = some (.Vlong value))
    (tagRead : le.get Arm64Program.___a64_read_tag = some (.Vint 0)) :
    InternalRun world 16 (.State handler materialize (readCont k) e le m)
      (.State handler .Sskip k e (finishTemps le value) m) := by
  run_tac do
    for _ in [:16] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic (← `(tactic| simp +decide only [CC.doStep, materialize,
        readCont, readBody, finishTemps, Arm64Program.s_kprog_arm64_program_modified_5,
        CC.PTree.gss, CC.PTree.gso, valueRead, tagRead, CC.doEvalExpr, CC.typeof,
        CC.typeconv, CC.removeAttributes, CC.tattr, CC.Cop.semBinaryOperation,
        CC.Cop.semCmp, CC.Cop.classifyCmp, CC.Cop.semBinarith, CC.Cop.classifyBinarith,
        CC.Cop.binarithType, CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
        CC.Cop.castIntLong, CC.Cop.boolVal, CC.Cop.classifyBool, CC.Val.ofBool,
        CC.Val.Vtrue, CC.Val.Vfalse, CC.Integers.Int.cmpu, CC.Integers.MI.cmpu,
        CC.Integers.Int.eq, CC.Integers.MI.eq, CC.Integers.Int.zero, CC.Integers.Int.one,
        CC.Integers.MI.zero, CC.Integers.MI.one, CC.Integers.Int.repr, CC.Integers.MI.repr,
        CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.tuchar, CC.tint,
        CC.tuint, CC.tulong, CC.Archi.ptr64, CC.E0, CC.Eapp,
        List.nil_append, List.append_nil, ite_true, ite_false, eq_self,
        Bool.false_eq_true, Bool.true_eq_false] <;> try rfl))
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

/-- The real inlined scalar read, materialization and output use the original
source loops, retaining the whole memory and deriving the value from loads. -/
theorem scalar_bound (world : CC.CGenv) (layout : GprLayout world) (i : Fin 31) (b cb vb tb kb : CC.Block)
    (ofs co vo to ko : CC.Integers.Ptrofs) (m : CC.Mem) (k : CC.Cont) (e : CC.Env) (le : CC.TempEnv)
    (value : BitVec 64)
    (entryRead : le.get Arm64Program._entry = some (.Vptr b ofs))
    (regRead : le.get Arm64Program._reg = some (.Vlong (BitVec.ofNat 64 i.val)))
    (cells : CC.Mem.loadv CC.Mptr m (.Vptr b ofs) = some (.Vptr cb co))
    (cellSlot : CC.Mem.loadv CC.Mptr m (.Vptr cb (CC.Integers.Ptrofs.add co
      (CC.Integers.Ptrofs.repr (8 * (i.val : CC.Z))))) = some (.Vptr vb vo))
    (tags : CC.Mem.loadv CC.Mptr m (.Vptr b (CC.Integers.Ptrofs.add ofs
      (CC.Integers.Ptrofs.repr 8))) = some (.Vptr tb to))
    (tagSlot : CC.Mem.loadv CC.Mptr m (.Vptr tb (CC.Integers.Ptrofs.add to
      (CC.Integers.Ptrofs.repr (8 * (i.val : CC.Z))))) = some (.Vptr kb ko))
    (cell : CC.Mem.loadv .Mint64 m (.Vptr vb vo) = some (.Vlong value))
    (kind : CC.Mem.loadv .Mint8unsigned m (.Vptr kb ko) = some (.Vint 0))
 :
    InternalRun world 69 (.State handler readLoop k e le m)
      (.State handler .Sskip k e
        (finishTemps (prefixTemps le (.Vptr b ofs) (.Vptr cb co) (.Vptr vb vo)
          (.Vptr tb to) (.Vptr kb ko) (.Vlong value) (BitVec.ofNat 64 i.val) 0) value) m) := by
  have prefixRun := prefix_bound world layout i b cb vb tb kb ofs co vo to ko m k e le
    (.Vlong value) 0 entryRead regRead cells cellSlot tags tagSlot cell kind rfl
  have observed :
      (prefixTemps le (.Vptr b ofs) (.Vptr cb co) (.Vptr vb vo) (.Vptr tb to) (.Vptr kb ko)
        (.Vlong value) (BitVec.ofNat 64 i.val) 0).get Arm64Program.___a64_read_value = some (.Vlong value) ∧
      (prefixTemps le (.Vptr b ofs) (.Vptr cb co) (.Vptr vb vo) (.Vptr tb to) (.Vptr kb ko)
        (.Vlong value) (BitVec.ofNat 64 i.val) 0).get Arm64Program.___a64_read_tag = some (.Vint 0) := by
    simp +decide [prefixTemps, CC.PTree.gso]
  have finished := materialize_scalar world e _ m k value observed.1 observed.2
  exact (internalRun_of_steps prefixRun.2 prefixRun.1).trans finished

end KProgFormal.ClightRefinement.Arm64Modified.Read
