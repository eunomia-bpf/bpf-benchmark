import KProgFormal.ClightRefinement.Arm64ProducerGprInputs

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64RegisterWrite

open Arm64Producer
open Arm64ProducerRegisterStorage

def procedure : CC.Function := Arm64Program.f_kprog_arm64_program_write

private structure Pieces where
  eager : CC.Stmt
  regSet : CC.Stmt
  masked : CC.Stmt
  spTest : CC.Expr
  spAlternative : CC.Stmt
  ordinary : CC.Stmt
  releaseTest : CC.Expr
  releaseAlternative : CC.Stmt

private def pieces : Pieces := by
  run_tac do
    let mut root ← Lean.Elab.Term.elabTerm (← `(procedure.fn_body)) none
    root ← Lean.Meta.withTransparency .all (Lean.Meta.whnf root)
    unless root.isAppOfArity ``CC.Stmt.Sloop 2 do throwError "scalar writer loop changed"
    let mut rest := root.getAppArgs[0]!
    let mut prefixStmts : Array Lean.Expr := #[]
    for _ in [:3] do
      rest ← Lean.Meta.withTransparency .all (Lean.Meta.whnf rest)
      unless rest.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "scalar writer prefix changed"
      prefixStmts := prefixStmts.push rest.getAppArgs[0]!
      rest := rest.getAppArgs[1]!
    rest ← Lean.Meta.withTransparency .all (Lean.Meta.whnf rest)
    unless rest.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "scalar writer tail changed"
    let destination ← Lean.Meta.withTransparency .all (Lean.Meta.whnf rest.getAppArgs[0]!)
    let release ← Lean.Meta.withTransparency .all (Lean.Meta.whnf rest.getAppArgs[1]!)
    unless destination.isAppOfArity ``CC.Stmt.Sifthenelse 3 && release.isAppOfArity ``CC.Stmt.Sifthenelse 3 do
      throwError "scalar writer destination/release tests changed"
    let result ← Lean.Meta.mkAppM ``Pieces.mk #[prefixStmts[0]!, prefixStmts[1]!, prefixStmts[2]!,
      destination.getAppArgs[0]!, destination.getAppArgs[1]!, destination.getAppArgs[2]!,
      release.getAppArgs[0]!, release.getAppArgs[1]!]
    Lean.Elab.Tactic.closeMainGoal `actual_scalar_writer_parts result

/-- Cache only actual source components; the equation below checks their assembly. -/
private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
  Lean.Elab.Tactic.closeMainGoal `actual_writer_part actual

private def eager : CC.Stmt := by
  run_tac cachePart (← `(pieces.eager))
private def regSet : CC.Stmt := by
  run_tac cachePart (← `(pieces.regSet))
private def masked : CC.Stmt := by
  run_tac cachePart (← `(pieces.masked))
private def spTest : CC.Expr := by
  run_tac cachePart (← `(pieces.spTest))
private def spAlternative : CC.Stmt := by
  run_tac cachePart (← `(pieces.spAlternative))
private def ordinary : CC.Stmt := by
  run_tac cachePart (← `(pieces.ordinary))
private def releaseTest : CC.Expr := by
  run_tac cachePart (← `(pieces.releaseTest))
private def releaseAlternative : CC.Stmt := by
  run_tac cachePart (← `(pieces.releaseAlternative))
private def body : CC.Stmt := .Ssequence eager (.Ssequence regSet (.Ssequence masked
  (.Ssequence (.Sifthenelse spTest spAlternative ordinary)
    (.Sifthenelse releaseTest releaseAlternative .Sskip))))
private theorem body_eq : procedure.fn_body = .Sloop body .Sbreak := rfl

def width (narrow : Bool) : CC.Val := .Vint (if narrow then 4 else 8)
def written (narrow : Bool) (value : BitVec 64) : BitVec 64 :=
  if narrow then (value.setWidth 32).setWidth 64 else value

def arguments (entry : CC.Block) (i : Fin 31) (value : BitVec 64) (narrow : Bool) : List CC.Val :=
  [.Vptr entry 0, .Vlong (BitVec.ofNat 64 i.val), .Vlong value, width narrow]

private def entryComposite : CC.Composite :=
  (ge.genv_cenv.get Arm64Program._kprog_arm64_entry).get (by decide +kernel)
private def gprComposite : CC.Composite :=
  (ge.genv_cenv.get Arm64Program._arm64_sim_gpr).get (by decide +kernel)
private theorem layouts :
    ge.genv_cenv.get Arm64Program._kprog_arm64_entry = some entryComposite ∧
    CC.fieldOffset ge.genv_cenv Arm64Program._sp entryComposite.co_members = .OK (40, .Full) ∧
    CC.fieldOffset ge.genv_cenv Arm64Program._cells entryComposite.co_members = .OK (0, .Full) ∧
    CC.fieldOffset ge.genv_cenv Arm64Program._tag_cells entryComposite.co_members = .OK (8, .Full) ∧
    ge.genv_cenv.get Arm64Program._arm64_sim_gpr = some gprComposite ∧
    CC.unionFieldOffset ge.genv_cenv Arm64Program._x gprComposite.co_members = .OK (0, .Full) ∧
    CC.sizeof ge.genv_cenv (CC.tptr (.Tunion Arm64Program._arm64_sim_gpr CC.noattr)) = 8 ∧
    CC.sizeof ge.genv_cenv (CC.tptr CC.tuchar) = 8 := by decide +kernel

/-- The writer needs only these header, union and pointer layout facts.
The symbol table and unrelated composites may differ after source linking. -/
structure GprLayout (world : CC.CGenv) : Prop where
  entry : world.genv_cenv.get Arm64Program._kprog_arm64_entry = some entryComposite
  sp : CC.fieldOffset world.genv_cenv Arm64Program._sp entryComposite.co_members = .OK (40, .Full)
  cells : CC.fieldOffset world.genv_cenv Arm64Program._cells entryComposite.co_members = .OK (0, .Full)
  tags : CC.fieldOffset world.genv_cenv Arm64Program._tag_cells entryComposite.co_members = .OK (8, .Full)
  cell : world.genv_cenv.get Arm64Program._arm64_sim_gpr = some gprComposite
  payload : CC.unionFieldOffset world.genv_cenv Arm64Program._x gprComposite.co_members = .OK (0, .Full)
  cellPointer : CC.sizeof world.genv_cenv (CC.tptr (.Tunion Arm64Program._arm64_sim_gpr CC.noattr)) = 8
  tagPointer : CC.sizeof world.genv_cenv (CC.tptr CC.tuchar) = 8

theorem program_layout : GprLayout ge :=
  ⟨layouts.1, layouts.2.1, layouts.2.2.1, layouts.2.2.2.1,
    layouts.2.2.2.2.1, layouts.2.2.2.2.2.1, layouts.2.2.2.2.2.2.1,
    layouts.2.2.2.2.2.2.2⟩

private theorem names : CC.listNorepet (CC.varNames procedure.fn_vars) ∧
    CC.listNorepet (CC.varNames procedure.fn_params) ∧
    CC.listDisjoint (CC.varNames procedure.fn_params) (CC.varNames procedure.fn_temps) := by decide +kernel
private theorem vars : procedure.fn_vars = [] := rfl
private theorem params : procedure.fn_params =
    [(Arm64Program._entry, CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr)),
     (Arm64Program._reg, CC.tulong), (Arm64Program._value, CC.tulong), (Arm64Program._width, CC.tuchar)] := rfl
private theorem result_type : procedure.fn_return = CC.tvoid := rfl

private theorem slot_unsigned : ∀ i : Fin 31,
    CC.Integers.Ptrofs.unsigned (CC.Integers.Ptrofs.repr (8 * (i.val : Int))) =
      8 * (i.val : Int) := by decide +kernel

private theorem guard_data : ∀ i : Fin 31,
    CC.Cop.semCmp .Ceq (.Vlong (BitVec.ofNat 64 i.val)) CC.tulong (.Vint (CC.Integers.Int.repr 32)) CC.tuint CC.Mem.empty = some (.Vint 0) ∧
    CC.Cop.semCmp .Clt (.Vlong (BitVec.ofNat 64 i.val)) CC.tulong (.Vint (CC.Integers.Int.repr 31)) CC.tuint CC.Mem.empty = some (.Vint 1) ∧
    CC.Cop.semCmp .Cne (.Vlong (BitVec.ofNat 64 i.val)) CC.tulong (.Vint (CC.Integers.Int.repr 31)) CC.tuint CC.Mem.empty = some (.Vint 1) ∧
    CC.Cop.semCmp .Cne (.Vlong (BitVec.ofNat 64 i.val)) CC.tulong (.Vint (CC.Integers.Int.repr 255)) CC.tuint CC.Mem.empty = some (.Vint 1) := by decide +kernel

private theorem guards (cenv : CC.CompositeEnv) (memory : CC.Mem) (i : Fin 31) :
    CC.Cop.semBinaryOperation cenv .Oeq (.Vlong (BitVec.ofNat 64 i.val)) CC.tulong (.Vint (CC.Integers.Int.repr 32)) CC.tuint memory = some (.Vint 0) ∧
    CC.Cop.semBinaryOperation cenv .Olt (.Vlong (BitVec.ofNat 64 i.val)) CC.tulong (.Vint (CC.Integers.Int.repr 31)) CC.tuint memory = some (.Vint 1) ∧
    CC.Cop.semBinaryOperation cenv .One (.Vlong (BitVec.ofNat 64 i.val)) CC.tulong (.Vint (CC.Integers.Int.repr 31)) CC.tuint memory = some (.Vint 1) ∧
    CC.Cop.semBinaryOperation cenv .One (.Vlong (BitVec.ofNat 64 i.val)) CC.tulong (.Vint (CC.Integers.Int.repr 255)) CC.tuint memory = some (.Vint 1) := by
  simp only [CC.Cop.semBinaryOperation]
  exact guard_data i

private theorem cast_index_bits : ∀ i : Fin 31,
    (BitVec.ofNat 64 i.val).setWidth 32 &&& (BitVec.allOnes 32 >>> (32-8)) =
      BitVec.ofNat 32 i.val := by decide +kernel

private theorem tag_zero :
    BitVec.ofInt 32 0 &&& (BitVec.allOnes 32 >>> (32-8)) = 0 := by decide +kernel

private theorem eq_byte_uint (cenv : CC.CompositeEnv) (memory : CC.Mem) (a b : BitVec 32) :
    CC.Cop.semBinaryOperation cenv .Oeq (.Vint a) CC.tuchar (.Vint b) CC.tuint memory =
      some (CC.Val.ofBool (CC.Integers.Int.cmpu .Ceq a b)) := rfl

private theorem and_words (cenv : CC.CompositeEnv) (memory : CC.Mem) (a b : BitVec 64) :
    CC.Cop.semBinaryOperation cenv .Oand (.Vlong a) CC.tulong (.Vlong b) CC.tulong memory =
      some (.Vlong (a &&& b)) := rfl

private theorem slot_offsets : ∀ i : Fin 31,
    CC.Integers.Ptrofs.add 0 (CC.Integers.Ptrofs.mul (CC.Integers.Ptrofs.repr 8)
      (CC.Cop.ptrofsOfInt .Signed (BitVec.ofNat 32 i.val))) =
      CC.Integers.Ptrofs.repr (8 * (i.val : Int)) := by decide +kernel

private theorem add_slot (cenv : CC.CompositeEnv) (memory : CC.Mem) (tags : Bool) (block : CC.Block) (i : Fin 31) :
    CC.Cop.semBinaryOperation cenv .Oadd (.Vptr block 0)
      (CC.tptr (CC.tptr (tableCellType tags))) (.Vint (BitVec.ofNat 32 i.val)) CC.tuchar memory =
      some (.Vptr block (CC.Integers.Ptrofs.repr (8 * (i.val : Int)))) := by
  cases tags
  all_goals
    change some (CC.Val.Vptr block (CC.Integers.Ptrofs.add 0
      (CC.Integers.Ptrofs.mul (CC.Integers.Ptrofs.repr 8)
        (CC.Cop.ptrofsOfInt .Signed (BitVec.ofNat 32 i.val))))) = _
    rw [slot_offsets i]

private theorem low_mask (value : BitVec 64) :
    (value &&& BitVec.ofInt 64 4294967295).setWidth 32 = value.setWidth 32 := by
  rw [BitVec.setWidth_and]
  change value.setWidth 32 &&& BitVec.allOnes 32 = value.setWidth 32
  exact BitVec.and_allOnes

private theorem full_mask (value : BitVec 64) :
    value &&& BitVec.ofInt 64 (-1) = value := by
  change value &&& BitVec.allOnes 64 = value
  exact BitVec.and_allOnes

private theorem ptr_add_zero (offset : CC.Integers.Ptrofs) :
    CC.Integers.Ptrofs.add 0 offset = offset := BitVec.zero_add offset
private theorem ptr_literals :
    CC.Integers.Ptrofs.unsigned (CC.Integers.Ptrofs.repr 40) = 40 ∧
    CC.Integers.Ptrofs.unsigned (CC.Integers.Ptrofs.repr 8) = 8 ∧
    CC.Integers.Ptrofs.unsigned (CC.Integers.Ptrofs.repr 0) = 0 ∧
    CC.Integers.Ptrofs.repr 0 = 0 ∧
    CC.Integers.Ptrofs.unsigned 0 = 0 := by decide +kernel

set_option hygiene false in
/-- Certify the actual 67 internal transitions for either scalar width. -/
theorem execute_stores_layout (world : CC.CGenv)
    (layout : GprLayout world) (k : CC.Cont)
    (hk : CC.isCallCont k = true) (m before middle after : CC.Mem) (entry : HeaderLocal m)
    (storage : Storage m before entry) (i : Fin 31) (value : BitVec 64) (narrow : Bool)
    (wordStore : CC.Mem.store .Mint64 before ((storage.tables false).cellBlock i) 0 (.Vlong (written narrow value)) = some middle)
    (tagStore : CC.Mem.store .Mint8unsigned middle ((storage.tables true).cellBlock i) 0 (.Vint 0) = some after) :
    InternalRun world 67
      (.Callstate (.Internal procedure) (arguments entry.block i value narrow) k before)
      (.Returnstate .Vundef k after) := by
  have different : ∀ i : Fin 31, tableCellName false i ≠ Arm64Entry._entry ∧
      tableCellName false i ≠ tableName true := by decide +kernel
  have wordHeaderOther := storage.separate_local false i _ _ _ entry.binding (different i).1
  have wordTagTableOther := storage.separate_local false i _ _ _ (storage.tables true).binding (different i).2
  have wordRoot : CC.Mem.load CC.Mptr before entry.block 0 =
      some (.Vptr (storage.tables false).tableBlock 0) := storage.roots false
  have tagRoot : CC.Mem.load CC.Mptr middle entry.block 8 = some (.Vptr (storage.tables true).tableBlock 0) :=
    (CC.Mem.load_store_other wordStore CC.Mptr entry.block 8 (.inl (Ne.symm wordHeaderOther))).trans (storage.roots true)
  have tagSlot : CC.Mem.load CC.Mptr middle (storage.tables true).tableBlock (8 * (i.val : Int)) =
      some (.Vptr ((storage.tables true).cellBlock i) 0) :=
    (CC.Mem.load_store_other wordStore CC.Mptr (storage.tables true).tableBlock _ (.inl (Ne.symm wordTagTableOther))).trans
      (storage.slots true i)
  have empty : (CC.PTree.empty : CC.Env).elements = [] := rfl
  have checksBefore := guards world.genv_cenv before i
  have checksAfter := guards world.genv_cenv after i
  simp only [CC.tulong, CC.tuint, CC.Integers.Int.repr, CC.Integers.MI.repr] at checksBefore checksAfter
  have addWord := add_slot world.genv_cenv before false (storage.tables false).tableBlock i
  have addTag := add_slot world.genv_cenv middle true (storage.tables true).tableBlock i
  have unionId : Arm64Entry._arm64_sim_gpr = Arm64Program._arm64_sim_gpr := rfl
  simp only [CC.tptr, CC.tuchar, tableCellType, unionId, eq_self, Bool.false_eq_true, ite_true, ite_false] at addWord addTag
  cases narrow <;> simp only [written, eq_self, Bool.false_eq_true, ite_true, ite_false] at wordStore
  all_goals
    run_tac do
      let reduce ← `(tactic|
          simp +decide only [body_eq, body, eager, regSet, masked, spTest, ordinary, releaseTest, arguments, width, written,
      CC.doStep, hk, CC.doFunctionEntry2, names, vars, params, result_type,
      CC.doAllocVariables, CC.bindParameterTemps, CC.emptyEnv, CC.PTree.gss, CC.PTree.gso,
      CC.doEvalExpr, CC.doEvalLvalue, CC.doDerefLoc, CC.doAssignLoc, CC.lvalOfField, CC.Mem.loadv, CC.Mem.storev,
      CC.accessMode, CC.typeof, layout.entry, layout.sp, layout.cells, layout.tags, layout.cell, layout.payload,
      layout.cellPointer, layout.tagPointer,
      wordRoot, storage.slots false i, storage.spPointer, storage.spRead, tagRoot, tagSlot,
      checksBefore.1, checksBefore.2.1, checksBefore.2.2.1, checksBefore.2.2.2,
      checksAfter.1,
      eq_byte_uint, and_words, addWord, addTag,
      CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
      CC.Cop.castIntLong, CC.Cop.boolVal, CC.Cop.classifyBool, CC.typeconv, CC.removeAttributes, CC.tattr,
      CC.tuchar, CC.tuint, CC.tint, CC.tulong, CC.tlong, CC.tptr, ptr_add_zero, ptr_literals.1, ptr_literals.2.1, ptr_literals.2.2.1, ptr_literals.2.2.2.1, ptr_literals.2.2.2.2,
      CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse,
      CC.Integers.Int.eq, CC.Integers.Int64.eq, CC.Integers.MI.eq,
      CC.Integers.Int.cmpu, CC.Integers.Int64.cmpu, CC.Integers.MI.cmpu,
      CC.Integers.Int.repr, CC.Integers.Int64.repr, CC.Integers.MI.repr,
      CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.Integers.Int.signed, CC.Integers.MI.signed,
      CC.Integers.Int64.unsigned, CC.Integers.Int.unsigned, CC.Integers.MI.unsigned,
      CC.Integers.Int.zero, CC.Integers.MI.zero, CC.Integers.Int64.and, CC.Integers.MI.and,
      CC.E0, CC.Eapp, CC.blocksOfEnv, CC.Mem.freeList, CC.callCont, empty,
      wordStore, tagStore, low_mask, full_mask, slot_unsigned i, List.nil_append, List.append_nil, ite_false, ite_true, eq_self, Bool.false_eq_true, Bool.true_eq_false, Bool.not_true, Bool.not_false, BitVec.zero_add, BitVec.and_allOnes, BitVec.ofInt_natCast, BitVec.ofNat_toNat, cast_index_bits i, tag_zero] <;> try rfl)
      for _ in [:66] do
        Lean.Elab.Tactic.evalTactic (← `(tactic|
          apply InternalRun.step))
        Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
        Lean.Elab.Tactic.evalTactic reduce

      Lean.Elab.Tactic.evalTactic (← `(tactic|
        exact InternalRun.step trivial (.skip_call _ _ _ _ _ _ hk rfl) (InternalRun.refl _)))

set_option hygiene false in
/-- Register 31 is XZR, distinct from the SP selector 32. Its actual writer
still eagerly reads SP, but returns without touching any cell or permission. -/
theorem execute_zr_layout (world : CC.CGenv)
    (layout : GprLayout world) (k : CC.Cont)
    (hk : CC.isCallCont k = true) (m before : CC.Mem) (entry : HeaderLocal m)
    (storage : Storage m before entry) (value : BitVec 64) (narrow : Bool) :
    InternalRun world 38
      (.Callstate (.Internal procedure) [.Vptr entry.block 0, .Vlong 31, .Vlong value, width narrow] k before)
      (.Returnstate .Vundef k before) := by
  have empty : (CC.PTree.empty : CC.Env).elements = [] := rfl
  cases narrow
  all_goals
    run_tac do
      let reduce ← `(tactic|
          simp +decide only [body_eq, body, eager, regSet, masked, spTest, ordinary, releaseTest, width, written,
      CC.doStep, hk, CC.doFunctionEntry2, names, vars, params, result_type,
      CC.doAllocVariables, CC.bindParameterTemps, CC.emptyEnv, CC.PTree.gss, CC.PTree.gso,
      CC.doEvalExpr, CC.doEvalLvalue, CC.doDerefLoc, CC.doAssignLoc, CC.lvalOfField, CC.Mem.loadv, CC.Mem.storev,
      CC.accessMode, CC.typeof, layout.entry, layout.sp, layout.cells, layout.tags, layout.cell, layout.payload,
      layout.cellPointer, layout.tagPointer,
      storage.spPointer, storage.spRead,

      eq_byte_uint, and_words,
      CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
      CC.Cop.castIntLong, CC.Cop.boolVal, CC.Cop.classifyBool, CC.typeconv, CC.removeAttributes, CC.tattr,
      CC.tuchar, CC.tuint, CC.tint, CC.tulong, CC.tlong, CC.tptr, ptr_add_zero, ptr_literals.1, ptr_literals.2.1, ptr_literals.2.2.1, ptr_literals.2.2.2.1, ptr_literals.2.2.2.2,
      CC.Val.ofBool, CC.Val.Vtrue, CC.Val.Vfalse,
      CC.Integers.Int.eq, CC.Integers.Int64.eq, CC.Integers.MI.eq,
      CC.Integers.Int.cmpu, CC.Integers.Int64.cmpu, CC.Integers.MI.cmpu,
      CC.Integers.Int.repr, CC.Integers.Int64.repr, CC.Integers.MI.repr,
      CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.Integers.Int.signed, CC.Integers.MI.signed,
      CC.Integers.Int64.unsigned, CC.Integers.Int.unsigned, CC.Integers.MI.unsigned,
      CC.Integers.Int.zero, CC.Integers.MI.zero, CC.Integers.Int64.and, CC.Integers.MI.and,
      CC.E0, CC.Eapp, CC.blocksOfEnv, CC.Mem.freeList, CC.callCont, empty,
      low_mask, full_mask, List.nil_append, List.append_nil, ite_false, ite_true, eq_self, Bool.false_eq_true, Bool.true_eq_false, Bool.not_true, Bool.not_false, BitVec.zero_add, BitVec.and_allOnes, BitVec.ofInt_natCast, BitVec.ofNat_toNat, tag_zero] <;> try rfl)
      for _ in [:37] do
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
        Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
        Lean.Elab.Tactic.evalTactic reduce
      Lean.Elab.Tactic.evalTactic (← `(tactic|
        exact InternalRun.step trivial (.skip_call _ _ _ _ _ _ hk rfl) (InternalRun.refl _)))

/-- Compatibility with callers whose complete composite environment is
unchanged. New linked callers can supply only GprLayout instead. -/
theorem execute_stores_bound (world : CC.CGenv)
    (composites : world.genv_cenv = ge.genv_cenv) (k : CC.Cont)
    (hk : CC.isCallCont k = true) (m before middle after : CC.Mem) (entry : HeaderLocal m)
    (storage : Storage m before entry) (i : Fin 31) (value : BitVec 64) (narrow : Bool)
    (wordStore : CC.Mem.store .Mint64 before ((storage.tables false).cellBlock i) 0 (.Vlong (written narrow value)) = some middle)
    (tagStore : CC.Mem.store .Mint8unsigned middle ((storage.tables true).cellBlock i) 0 (.Vint 0) = some after) :
    InternalRun world 67
      (.Callstate (.Internal procedure) (arguments entry.block i value narrow) k before)
      (.Returnstate .Vundef k after) := by
  have layout : GprLayout world := by
    constructor
    all_goals rw [composites]
    exact program_layout.entry
    exact program_layout.sp
    exact program_layout.cells
    exact program_layout.tags
    exact program_layout.cell
    exact program_layout.payload
    exact program_layout.cellPointer
    exact program_layout.tagPointer
  exact execute_stores_layout world layout k hk m before middle after entry storage i value narrow wordStore tagStore

theorem execute_zr_bound (world : CC.CGenv)
    (composites : world.genv_cenv = ge.genv_cenv) (k : CC.Cont)
    (hk : CC.isCallCont k = true) (m before : CC.Mem) (entry : HeaderLocal m)
    (storage : Storage m before entry) (value : BitVec 64) (narrow : Bool) :
    InternalRun world 38
      (.Callstate (.Internal procedure) [.Vptr entry.block 0, .Vlong 31, .Vlong value, width narrow] k before)
      (.Returnstate .Vundef k before) := by
  have layout : GprLayout world := by
    constructor
    all_goals rw [composites]
    exact program_layout.entry
    exact program_layout.sp
    exact program_layout.cells
    exact program_layout.tags
    exact program_layout.cell
    exact program_layout.payload
    exact program_layout.cellPointer
    exact program_layout.tagPointer
  exact execute_zr_layout world layout k hk m before entry storage value narrow

/-- The original standalone writer is the same execution at Kstop. -/
theorem execute_stores (m before middle after : CC.Mem) (entry : HeaderLocal m)
    (storage : Storage m before entry) (i : Fin 31) (value : BitVec 64) (narrow : Bool)
    (wordStore : CC.Mem.store .Mint64 before ((storage.tables false).cellBlock i) 0
      (.Vlong (written narrow value)) = some middle)
    (tagStore : CC.Mem.store .Mint8unsigned middle ((storage.tables true).cellBlock i) 0
      (.Vint 0) = some after) :
    InternalRun ge 67
      (.Callstate (.Internal procedure) (arguments entry.block i value narrow) .Kstop before)
      (.Returnstate .Vundef .Kstop after) :=
  execute_stores_bound ge rfl .Kstop rfl m before middle after entry storage i value narrow wordStore tagStore

/-- The observed effect of the actual scalar writer, with successful stores
retained for composing subsequent borrowed-entry and native-register proofs. -/
structure Result {m before : CC.Mem} {entry : HeaderLocal m}
    (storage : Storage m before entry) (i : Fin 31) (value : BitVec 64)
    (narrow : Bool) (after : CC.Mem) : Prop where
  stores : ∃ middle,
    CC.Mem.store .Mint64 before ((storage.tables false).cellBlock i) 0
      (.Vlong (written narrow value)) = some middle ∧
    CC.Mem.store .Mint8unsigned middle ((storage.tables true).cellBlock i) 0 (.Vint 0) = some after
  run : InternalRun ge 67
    (.Callstate (.Internal procedure) (arguments entry.block i value narrow) .Kstop before)
    (.Returnstate .Vundef .Kstop after)
  word : CC.Mem.load .Mint64 after ((storage.tables false).cellBlock i) 0 =
    some (.Vlong (written narrow value))
  tag : CC.Mem.load .Mint8unsigned after ((storage.tables true).cellBlock i) 0 = some (.Vint 0)
  caller : FrameBelow m.nextblock before after
  access : after.access = before.access
  nextblock : after.nextblock = before.nextblock

private theorem store_exists (memory : CC.Mem) (chunk : CC.Chunk) (block : CC.Block) (value : CC.Val)
    (writable : CC.Mem.validAccess memory chunk block 0 .Writable = true) :
    ∃ after, CC.Mem.store chunk memory block 0 value = some after := by
  simp only [CC.Mem.store, writable, ite_true]
  exact ⟨_, rfl⟩

/-- Ordinary destinations use the source-derived writable cells. Width four
zero-extends into a full eight-byte store; width eight retains all input bits.
Neither successful stores nor a post-state are caller assumptions. -/
theorem write {m before : CC.Mem} {entry : HeaderLocal m}
    (storage : Storage m before entry) (i : Fin 31) (value : BitVec 64) (narrow : Bool) :
    ∃ after, Result storage i value narrow after := by
  obtain ⟨middle, wordStore⟩ := store_exists before .Mint64 ((storage.tables false).cellBlock i)
    (.Vlong (written narrow value)) (storage.writable false i)
  have tagWritable : CC.Mem.validAccess middle .Mint8unsigned
      ((storage.tables true).cellBlock i) 0 .Writable = true :=
    (CC.Mem.validAccess_store_eq wordStore _ _ _ _).trans (storage.writable true i)
  obtain ⟨after, tagStore⟩ := store_exists middle .Mint8unsigned
    ((storage.tables true).cellBlock i) (.Vint 0) tagWritable
  have distinct := storage.cells_distinct false true i i (.inl (by decide))
  have word : CC.Mem.load .Mint64 after ((storage.tables false).cellBlock i) 0 =
      some (.Vlong (written narrow value)) := by
    rw [CC.Mem.load_store_other tagStore .Mint64 _ 0 (.inl distinct)]
    exact CC.Mem.load_store_same wordStore
  have tag : CC.Mem.load .Mint8unsigned after ((storage.tables true).cellBlock i) 0 = some (.Vint 0) :=
    CC.Mem.load_store_same tagStore
  exact ⟨after, ⟨⟨middle, wordStore, tagStore⟩,
    execute_stores m before middle after entry storage i value narrow wordStore tagStore, word, tag,
    (FrameBelow.store (storage.cell_fresh false i) wordStore).trans
      (FrameBelow.store (storage.cell_fresh true i) tagStore),
    (CC.Mem.store_access tagStore).trans (CC.Mem.store_access wordStore),
    (CC.Mem.store_nextblock tagStore).trans (CC.Mem.store_nextblock wordStore)⟩⟩

/-- Both writes preserve every load from a differently named actual producer
local. This covers header, pointer tables, SP, flags and vectors through their
real allocation bindings, without presuming native physical-address separation. -/
theorem Result.local_load {m before after : CC.Mem} {entry : HeaderLocal m}
    {storage : Storage m before entry} {i : Fin 31} {value : BitVec 64} {narrow : Bool}
    (result : Result storage i value narrow after) (id : CC.Ident) (ty : CC.Ty) (block : CC.Block)
    (binding : (allocation m).1.get id = some (block, ty))
    (wordOther : tableCellName false i ≠ id) (tagOther : tableCellName true i ≠ id)
    (chunk : CC.Chunk) (offset : Int) :
    CC.Mem.load chunk after block offset = CC.Mem.load chunk before block offset := by
  obtain ⟨middle, wordStore, tagStore⟩ := result.stores
  exact (CC.Mem.load_store_other tagStore chunk block offset
    (.inl (Ne.symm (storage.separate_local true i _ _ _ binding tagOther)))).trans
      (CC.Mem.load_store_other wordStore chunk block offset
        (.inl (Ne.symm (storage.separate_local false i _ _ _ binding wordOther))))

/-- Every other register cell retains all successful and unsuccessful loads,
for any chunk/offset, after the selected word and tag stores. -/
theorem Result.other_cell {m before after : CC.Mem} {entry : HeaderLocal m}
    {storage : Storage m before entry} {i : Fin 31} {value : BitVec 64} {narrow : Bool}
    (result : Result storage i value narrow after) (tags : Bool) (j : Fin 31) (different : j ≠ i)
    (chunk : CC.Chunk) (offset : Int) :
    CC.Mem.load chunk after ((storage.tables tags).cellBlock j) offset =
      CC.Mem.load chunk before ((storage.tables tags).cellBlock j) offset := by
  obtain ⟨middle, wordStore, tagStore⟩ := result.stores
  exact (CC.Mem.load_store_other tagStore chunk _ offset
    (.inl (storage.cells_distinct tags true j i (.inr different)))).trans
      (CC.Mem.load_store_other wordStore chunk _ offset
        (.inl (storage.cells_distinct tags false j i (.inr different))))

end KProgFormal.ClightRefinement.Arm64RegisterWrite
