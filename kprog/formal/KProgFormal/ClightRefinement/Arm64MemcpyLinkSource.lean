import KProgFormal.ClightRefinement.Arm64MemcpyLinkProgram
import KProgFormal.ClightRefinement.Arm64Producer

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyLinkSource
open Arm64MemcpyLinkProgram (ge entry)

def allocation (m : CC.Mem) : CC.Env × CC.Mem :=
  CC.doAllocVariables ge.genv_cenv CC.emptyEnv m entry.fn_vars

def temps (addressing : CC.Val) (address : BitVec 64) : CC.TempEnv :=
  ((CC.createUndefTemps entry.fn_temps).set Arm64Addressing._addressing addressing).set
    Arm64Addressing._address (.Vlong address)

private theorem names :
    CC.listNorepet (CC.varNames entry.fn_vars) ∧
    CC.listNorepet (CC.varNames entry.fn_params) ∧
    CC.listDisjoint (CC.varNames entry.fn_params) (CC.varNames entry.fn_temps) := by
  decide +kernel

theorem allocated (m : CC.Mem) :
    CC.AllocVariables ge.genv_cenv CC.emptyEnv m entry.fn_vars
      (allocation m).1 (allocation m).2 :=
  CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation m)).symm

/-- The original two-argument LINK enters with its actual two local arrays
and its genuine undefined temporary environment, for arbitrary caller memory. -/
theorem entry_valid (m : CC.Mem) (addressing : CC.Val) (address : BitVec 64) :
    CC.FunctionEntry2 ge entry [addressing,.Vlong address] m
      (allocation m).1 (temps addressing address) (allocation m).2 :=
  .intro names.1 names.2.1 names.2.2 (allocated m) rfl

theorem enter (m : CC.Mem) (addressing : CC.Val) (address : BitVec 64) (k : CC.Cont) :
    InternalRun ge 1 (.Callstate (.Internal entry) [addressing,.Vlong address] k m)
      (.State entry entry.fn_body k (allocation m).1 (temps addressing address) (allocation m).2) :=
  .step trivial (.internal_function _ _ _ _ _ _ _ (entry_valid m addressing address)) (.refl _)

theorem allocation_frame (m : CC.Mem) : FrameBelow m.nextblock m (allocation m).2 :=
  (FrameBelow.allocVariables (allocated m) m.nextblock (Nat.le_refl _)).2

theorem local_storage (m : CC.Mem) (id : CC.Ident) (ty : CC.Ty)
    (present : (id,ty) ∈ entry.fn_vars) :
    ∃ block, (allocation m).1.get id = some (block,ty) ∧
      m.nextblock.toNat ≤ block.toNat ∧ block.toNat < (allocation m).2.nextblock.toNat ∧
      CC.Mem.rangePerm (allocation m).2 block 0 (CC.sizeof ge.genv_cenv ty) .Cur .Freeable = true := by
  obtain ⟨block,bound⟩ := allocated_local_binding (allocated m) names.1 present
  exact ⟨block,bound,(allocated_local_storage (allocated m)).1 _ _ bound⟩

private def headerComposite : CC.Composite :=
  (ge.genv_cenv.get Arm64Addressing._kprog_arm64_addressing).get (by decide +kernel)

/-- These are the actual addressing header fields, rather than the distinct
program-entry wrapper's pointer-table header. -/
theorem header_layout :
    ge.genv_cenv.get Arm64Addressing._kprog_arm64_addressing = some headerComposite ∧
    CC.fieldOffset ge.genv_cenv Arm64Addressing._coordinates headerComposite.co_members = .OK (0,.Full) ∧
    CC.fieldOffset ge.genv_cenv Arm64Addressing._registers headerComposite.co_members = .OK (8,.Full) ∧
    CC.fieldOffset ge.genv_cenv Arm64Addressing._tags headerComposite.co_members = .OK (16,.Full) ∧
    CC.fieldOffset ge.genv_cenv Arm64Addressing._b headerComposite.co_members = .OK (24,.Full) ∧
    CC.fieldOffset ge.genv_cenv Arm64Addressing._stack_tags headerComposite.co_members = .OK (32,.Full) ∧
    CC.fieldOffset ge.genv_cenv Arm64Addressing._capacity headerComposite.co_members = .OK (48,.Full) ∧
    CC.fieldOffset ge.genv_cenv Arm64Addressing._bias headerComposite.co_members = .OK (56,.Full) ∧
    CC.sizeof ge.genv_cenv (.Tunion Arm64Addressing._arm64_sim_gpr CC.noattr) = 8 := by
  decide +kernel

private def sourceParts : CC.Stmt × CC.Stmt := by
  run_tac do
    let actual ← Lean.Elab.Term.elabTerm (← `(entry.fn_body)) none
    let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf actual)
    unless actual.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "LINK entry shape changed"
    let parts ← Lean.Meta.mkAppM ``Prod.mk actual.getAppArgs
    Lean.Elab.Tactic.closeMainGoal `actual_link_source_parts parts

def first : CC.Stmt := sourceParts.1
def afterFirst : CC.Stmt := sourceParts.2
theorem first_source : entry.fn_body = .Ssequence first afterFirst := rfl

private def tableParts : List (CC.Ident × CC.Stmt) × CC.Stmt := by
  run_tac do
    let mut rest ← Lean.Elab.Term.elabTerm (← `(entry.fn_body)) none
    let mut rows : Array Lean.Expr := #[]
    for _ in [:62] do
      rest ← Lean.Meta.withTransparency .all (Lean.Meta.whnf rest)
      unless rest.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "LINK table prefix changed"
      let statement := rest.getAppArgs[0]!
      let exposed ← Lean.Meta.withTransparency .all (Lean.Meta.whnf statement)
      unless exposed.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "LINK table row changed"
      let head ← Lean.Meta.withTransparency .all (Lean.Meta.whnf exposed.getAppArgs[0]!)
      unless head.isAppOfArity ``CC.Stmt.Sset 2 do throwError "LINK table read changed"
      rows := rows.push (← Lean.Meta.mkAppM ``Prod.mk #[head.getAppArgs[0]!,statement])
      rest := rest.getAppArgs[1]!
    let rowType ← Lean.Elab.Term.elabTerm (← `(CC.Ident × CC.Stmt)) none
    let rowsLit ← Lean.Meta.mkListLit rowType rows.toList
    Lean.Elab.Tactic.closeMainGoal `actual_link_tables (← Lean.Meta.mkAppM ``Prod.mk #[rowsLit,rest])

def afterTables : CC.Stmt := tableParts.2
def tableTemporary (tags : Bool) (i : Fin 31) : CC.Ident :=
  (tableParts.1[if tags then i.val + 31 else i.val]'(by
    change (if tags then i.val + 31 else i.val) < 62
    have bound := i.isLt
    split <;> omega)).1
def tableName (tags : Bool) : CC.Ident :=
  if tags then Arm64Addressing.___a64_tag_cells else Arm64Addressing.___a64_cells
def cellType (tags : Bool) : CC.Ty :=
  if tags then CC.tuchar else .Tunion Arm64Addressing._arm64_sim_gpr CC.noattr
def headerField (tags : Bool) : CC.Ident :=
  if tags then Arm64Addressing._tags else Arm64Addressing._registers
def tableStatement (tags : Bool) (i : Fin 31) : CC.Stmt :=
  .Ssequence
    (.Sset (tableTemporary tags i)
      (.Efield
        (.Ederef (.Etempvar Arm64Addressing._addressing
          (CC.tptr (.Tstruct Arm64Addressing._kprog_arm64_addressing CC.noattr)))
          (.Tstruct Arm64Addressing._kprog_arm64_addressing CC.noattr))
        (headerField tags) (CC.tptr (cellType tags))))
    (.Sassign
      (.Ederef
        (.Ebinop .Oadd
          (.Evar (tableName tags) (CC.tarray (CC.tptr (cellType tags)) 31))
          (.Econst_int (CC.Integers.Int.repr i.val) CC.tint)
          (CC.tptr (CC.tptr (cellType tags))))
        (CC.tptr (cellType tags)))
      (.Ebinop .Oadd
        (.Etempvar (tableTemporary tags i) (CC.tptr (cellType tags)))
        (.Ecast (.Econst_int (CC.Integers.Int.repr i.val) CC.tuint) CC.tuchar)
        (CC.tptr (cellType tags))))

/-- Every real LINK row is a header read followed by its original typed
pointer arithmetic and table store, including all source temporary names. -/
theorem tables_source : entry.fn_body =
    (List.ofFn (tableStatement false)).foldr CC.Stmt.Ssequence
      ((List.ofFn (tableStatement true)).foldr CC.Stmt.Ssequence afterTables) := by
  rfl

theorem table_temporaries : ∀ tags (i : Fin 31),
    tableTemporary tags i ≠ Arm64Addressing._addressing ∧
    tableTemporary tags i ≠ Arm64Addressing._address := by
  decide +kernel

structure Table (tags : Bool) (m : CC.Mem) where
  block : CC.Block
  binding : (allocation m).1.get (tableName tags) =
    some (block,CC.tarray (CC.tptr (cellType tags)) 31)
  fresh : m.nextblock.toNat ≤ block.toNat
  owned : CC.Mem.rangePerm (allocation m).2 block 0 248 .Cur .Freeable = true

theorem table_storage (tags : Bool) (m : CC.Mem) : Nonempty (Table tags m) := by
  have declared : (tableName tags,CC.tarray (CC.tptr (cellType tags)) 31) ∈ entry.fn_vars := by
    cases tags <;> decide +kernel
  have size : CC.sizeof ge.genv_cenv (CC.tarray (CC.tptr (cellType tags)) 31) = 248 := by
    cases tags <;> decide +kernel
  obtain ⟨block,bound,fresh,_,owned⟩ := local_storage m _ _ declared
  exact ⟨⟨block,bound,fresh,by simpa only [size] using owned⟩⟩

def headerOffset (tags : Bool) : CC.Integers.Ptrofs := CC.Integers.Ptrofs.repr (if tags then 16 else 8)
def cellOffset (tags : Bool) (i : Fin 31) : CC.Integers.Ptrofs :=
  CC.Integers.Ptrofs.repr ((if tags then 1 else 8) * (i.val : Int))

private theorem indices : ∀ i : Fin 31,
    CC.Integers.Ptrofs.unsigned (CC.Integers.Ptrofs.repr (8 * (i.val : Int))) = 8 * (i.val : Int) ∧
    ((CC.Integers.Int.repr i.val) &&& (BitVec.allOnes 32 >>> (32-8))) = CC.Integers.Int.repr i.val ∧
    CC.Integers.Ptrofs.mul (CC.Integers.Ptrofs.repr 8)
      (CC.Cop.ptrofsOfInt .Signed (CC.Integers.Int.repr i.val)) =
      CC.Integers.Ptrofs.repr (8 * (i.val : Int)) ∧
    CC.Integers.Ptrofs.mul (CC.Integers.Ptrofs.repr 1)
      (CC.Cop.ptrofsOfInt .Signed (CC.Integers.Int.repr i.val)) =
      CC.Integers.Ptrofs.repr (i.val : Int) := by
  decide +kernel


private theorem add_slot (tags : Bool) (i : Fin 31) (m : CC.Mem)
    (b : CC.Block) (ofs : CC.Integers.Ptrofs) :
    CC.Cop.semBinaryOperation ge.genv_cenv .Oadd (.Vptr b ofs)
      (CC.tarray (CC.tptr (cellType tags)) 31) (.Vint (CC.Integers.Int.repr i.val)) CC.tint m =
      some (.Vptr b (CC.Integers.Ptrofs.add ofs (CC.Integers.Ptrofs.repr (8 * (i.val : Int))))) := by
  change some (CC.Val.Vptr b (CC.Integers.Ptrofs.add ofs
    (CC.Integers.Ptrofs.mul (CC.Integers.Ptrofs.repr 8)
      (CC.Cop.ptrofsOfInt .Signed (CC.Integers.Int.repr i.val))))) = _
  rw [(indices i).2.2.1]

private theorem add_cells (tags : Bool) (i : Fin 31) (m : CC.Mem)
    (b : CC.Block) (ofs : CC.Integers.Ptrofs) :
    CC.Cop.semBinaryOperation ge.genv_cenv .Oadd (.Vptr b ofs)
      (CC.tptr (cellType tags)) (.Vint (CC.Integers.Int.repr i.val)) CC.tuchar m =
      some (.Vptr b (CC.Integers.Ptrofs.add ofs (cellOffset tags i))) := by
  cases tags
  · simp only [cellType,cellOffset,Bool.false_eq_true,ite_false]
    simp only [CC.Cop.semBinaryOperation,CC.Cop.semAdd,CC.Cop.classifyAdd,
      CC.typeconv,CC.removeAttributes,CC.tattr,CC.tptr,CC.tuchar,CC.tint,
      CC.Cop.semAddPtrInt,header_layout.2.2.2.2.2.2.2.2]
    rw [(indices i).2.2.1]
  · simp only [cellType,cellOffset,ite_true]
    change some (CC.Val.Vptr b (CC.Integers.Ptrofs.add ofs
      (CC.Integers.Ptrofs.mul (CC.Integers.Ptrofs.repr 1)
        (CC.Cop.ptrofsOfInt .Signed (CC.Integers.Int.repr i.val))))) = _
    rw [(indices i).2.2.2]
    simp only [Int.one_mul]

set_option hygiene false in
/-- Every actual row derives its own successful typed store from the real
allocated table's rights, retaining its exact original pointer arithmetic.
Only the original caller header read is admitted; the current read follows
from the same preceding allocation/store frame. -/
theorem table_store (tags : Bool) (i : Fin 31) (m before : CC.Mem) (table : Table tags m)
    (header cells : CC.Block) (offset cellBase : CC.Integers.Ptrofs)
    (old : header.toNat < m.nextblock.toNat)
    (read : CC.Mem.load CC.Mptr m header
      (CC.Integers.Ptrofs.unsigned (CC.Integers.Ptrofs.add offset (headerOffset tags))) =
        some (.Vptr cells cellBase))
    (frame : FrameBelow m.nextblock m before)
    (access : before.access = (allocation m).2.access)
    (le : CC.TempEnv) (input : le.get Arm64Addressing._addressing = some (.Vptr header offset))
    (k : CC.Cont) (rest : CC.Stmt) :
    ∃ after,
      InternalRun ge 6
        (.State entry (.Ssequence (tableStatement tags i) rest) k (allocation m).1 le before)
        (.State entry rest k (allocation m).1
          (le.set (tableTemporary tags i) (.Vptr cells cellBase)) after) ∧
      CC.Mem.store CC.Mptr before table.block (8 * (i.val : Int))
        (.Vptr cells (CC.Integers.Ptrofs.add cellBase (cellOffset tags i))) = some after ∧
      CC.Mem.load CC.Mptr after table.block (8 * (i.val : Int)) =
        some (.Vptr cells (CC.Integers.Ptrofs.add cellBase (cellOffset tags i))) ∧
      FrameBelow m.nextblock before after ∧
      after.access = before.access ∧ after.nextblock = before.nextblock := by
  have valid : CC.Mem.validAccess before CC.Mptr table.block (8 * (i.val : Int)) .Writable = true := by
    simp only [CC.Mem.validAccess,Bool.and_eq_true]
    refine ⟨?_,?_⟩
    · apply CC.Mem.rangePerm_intro
      intro ofs lower upper
      have bound := i.isLt
      have permission := CC.Mem.perm_implies
        (CC.Mem.rangePerm_perm _ _ _ _ _ _ table.owned ofs (by omega)
          (by change ofs < 8 * (i.val : Int) + 8 at upper; omega))
        (by decide : CC.permOrder .Freeable .Writable = true)
      simpa only [CC.Mem.perm,access] using permission
    · change ((8 * (i.val : Int)) % 8 == 0) = true
      have aligned : (8 * (i.val : Int)) % 8 = 0 := by omega
      simp only [aligned,beq_self_eq_true]
  have exists_store : ∃ after, CC.Mem.store CC.Mptr before table.block (8 * (i.val : Int))
      (.Vptr cells (CC.Integers.Ptrofs.add cellBase (cellOffset tags i))) = some after := by
    unfold CC.Mem.store
    rw [valid]
    exact ⟨_,rfl⟩
  obtain ⟨after,stored⟩ := exists_store
  have loaded := (frame.load CC.Mptr header
    (CC.Integers.Ptrofs.unsigned (CC.Integers.Ptrofs.add offset (headerOffset tags))) old).trans read
  have selected : CC.fieldOffset ge.genv_cenv (headerField tags) headerComposite.co_members =
      .OK ((if tags then 16 else 8),.Full) := by
    cases tags
    · exact header_layout.2.2.1
    · exact header_layout.2.2.2.1
  have addSlot := add_slot tags i before table.block 0
  have addCell := add_cells tags i before cells cellBase
  have narrow := (indices i).2.1
  have unsignedSlot := (indices i).1
  have slotZero (ofs : CC.Integers.Ptrofs) : CC.Integers.Ptrofs.add 0 ofs = ofs := BitVec.zero_add ofs
  rw [slotZero] at addSlot
  simp only [CC.tptr,CC.tarray,CC.tint,CC.tuchar] at addSlot
  simp only [CC.tptr,CC.tuchar] at addCell
  simp only [CC.Mptr,CC.Archi.ptr64,ite_true] at stored loaded
  simp only [headerOffset] at loaded
  have execution : InternalRun ge 6
      (.State entry (.Ssequence (tableStatement tags i) rest) k (allocation m).1 le before)
      (.State entry rest k (allocation m).1
        (le.set (tableTemporary tags i) (.Vptr cells cellBase)) after) := by
    run_tac do
      let reduce ← `(tactic|
        simp +decide only [tableStatement,CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,
          CC.doDerefLoc,CC.doAssignLoc,CC.lvalOfVar,CC.lvalOfField,CC.accessMode,CC.typeof,
          CC.Mem.loadv,CC.Mem.storev,input,CC.PTree.gss,CC.PTree.gso,
          header_layout.1,selected,table.binding,loaded,stored,addSlot,addCell,narrow,unsignedSlot,
          CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntInt,CC.Integers.Int.zero_ext,
          CC.Integers.MI.zero_ext,CC.tarray,CC.tptr,CC.tint,CC.tuchar,CC.tuint,
          CC.Mptr,CC.Archi.ptr64,CC.Integers.Ptrofs.zero,CC.Integers.MI.zero,
          CC.E0,CC.Eapp,List.nil_append,List.append_nil,ite_true,ite_false,
          eq_self,Bool.false_eq_true,Bool.true_eq_false] <;> try rfl)
      for _ in [:6] do
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
        Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
        Lean.Elab.Tactic.evalTactic reduce
      Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))
  exact ⟨after,execution,stored,
    by simpa [CC.Mptr,CC.Archi.ptr64,CC.Val.loadResult] using CC.Mem.load_store_same stored,
    FrameBelow.store table.fresh stored,CC.Mem.store_access stored,CC.Mem.store_nextblock stored⟩

/-- Preserve the original complete public first-row interface by invoking
the same generic checked row proof at its genuine source position. -/
theorem first_store (m : CC.Mem) (header registers : CC.Block)
    (headerOffset registerOffset : CC.Integers.Ptrofs) (address : BitVec 64) (k : CC.Cont)
    (old : header.toNat < m.nextblock.toNat)
    (read : CC.Mem.load CC.Mptr m header
      (CC.Integers.Ptrofs.unsigned (CC.Integers.Ptrofs.add headerOffset (CC.Integers.Ptrofs.repr 8))) =
        some (.Vptr registers registerOffset)) :
    ∃ block after, (allocation m).1.get Arm64Addressing.___a64_cells =
        some (block,CC.tarray (CC.tptr (.Tunion Arm64Addressing._arm64_sim_gpr CC.noattr)) 31) ∧
      InternalRun ge 6
        (.State entry entry.fn_body k (allocation m).1
          (temps (.Vptr header headerOffset) address) (allocation m).2)
        (.State entry afterFirst k (allocation m).1
          ((temps (.Vptr header headerOffset) address).set Arm64Addressing._t'69 (.Vptr registers registerOffset)) after) ∧
      CC.Mem.load CC.Mptr after block 0 = some (.Vptr registers registerOffset) ∧
      FrameBelow m.nextblock m after ∧
      after.access = (allocation m).2.access ∧ after.nextblock = (allocation m).2.nextblock := by
  obtain ⟨table⟩ := table_storage false m
  have input : (temps (.Vptr header headerOffset) address).get Arm64Addressing._addressing =
      some (.Vptr header headerOffset) := by
    simp +decide only [temps,CC.PTree.gss,CC.PTree.gso]
  obtain ⟨after,run,stored,readback,caller,access,next⟩ :=
    table_store false 0 m (allocation m).2 table header registers headerOffset registerOffset old read
      (allocation_frame m) rfl (temps (.Vptr header headerOffset) address) input k afterFirst
  have body : entry.fn_body = .Ssequence (tableStatement false 0) afterFirst := rfl
  have temporary : tableTemporary false 0 = Arm64Addressing._t'69 := rfl
  have zeroOffset : cellOffset false 0 = 0 := rfl
  have addZero (ofs : CC.Integers.Ptrofs) : CC.Integers.Ptrofs.add ofs 0 = ofs := BitVec.add_zero ofs
  change CC.Mem.load CC.Mptr after table.block 0 =
    some (.Vptr registers (CC.Integers.Ptrofs.add registerOffset (cellOffset false 0))) at readback
  rw [zeroOffset,addZero] at readback
  exact ⟨table.block,after,table.binding,
    by simpa only [body,temporary] using run,
    readback,(allocation_frame m).trans caller,access,next⟩

def tableTemps (tags : Bool) (rows : List (Fin 31)) (value : CC.Val) (le : CC.TempEnv) : CC.TempEnv :=
  rows.foldl (fun prior i => prior.set (tableTemporary tags i) value) le

theorem tableTemps_parameters (tags : Bool) (rows : List (Fin 31)) (value : CC.Val) (le : CC.TempEnv) :
    (tableTemps tags rows value le).get Arm64Addressing._addressing = le.get Arm64Addressing._addressing ∧
    (tableTemps tags rows value le).get Arm64Addressing._address = le.get Arm64Addressing._address := by
  induction rows generalizing le with
  | nil => exact ⟨rfl,rfl⟩
  | cons i rest ih =>
    have kept := ih (le.set (tableTemporary tags i) value)
    exact ⟨kept.1.trans (CC.PTree.gso _ _ _ _ (table_temporaries tags i).1),
      kept.2.trans (CC.PTree.gso _ _ _ _ (table_temporaries tags i).2)⟩

/-- The actual row list executes once, carrying the same original header read
through every real store. All table slots, abstract pointer offsets, original
caller bytes and other blocks are tracked through these same witnesses. -/
theorem run_table (tags : Bool) (rows : List (Fin 31)) (m before : CC.Mem) (table : Table tags m)
    (header cells : CC.Block) (offset cellBase : CC.Integers.Ptrofs)
    (old : header.toNat < m.nextblock.toNat)
    (read : CC.Mem.load CC.Mptr m header
      (CC.Integers.Ptrofs.unsigned (CC.Integers.Ptrofs.add offset (headerOffset tags))) =
        some (.Vptr cells cellBase))
    (frame : FrameBelow m.nextblock m before)
    (access : before.access = (allocation m).2.access)
    (le : CC.TempEnv) (input : le.get Arm64Addressing._addressing = some (.Vptr header offset))
    (k : CC.Cont) (rest : CC.Stmt) :
    ∃ after,
      InternalRun ge (6 * rows.length)
        (.State entry (rows.foldr (fun i next => .Ssequence (tableStatement tags i) next) rest)
          k (allocation m).1 le before)
        (.State entry rest k (allocation m).1 (tableTemps tags rows (.Vptr cells cellBase) le) after) ∧
      (∀ i ∈ rows, CC.Mem.load CC.Mptr after table.block (8 * (i.val : Int)) =
        some (.Vptr cells (CC.Integers.Ptrofs.add cellBase (cellOffset tags i)))) ∧
      (∀ i ∉ rows, CC.Mem.load CC.Mptr after table.block (8 * (i.val : Int)) =
        CC.Mem.load CC.Mptr before table.block (8 * (i.val : Int))) ∧
      (∀ b, b ≠ table.block → ∀ chunk ofs, CC.Mem.load chunk after b ofs = CC.Mem.load chunk before b ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧ after.nextblock = before.nextblock := by
  induction rows generalizing before le with
  | nil =>
    refine ⟨before,.refl _,?_,?_,?_,FrameBelow.refl _ _,rfl,rfl⟩
    · intro i member; cases member
    · intro i absent; rfl
    · intro b different chunk ofs; rfl
  | cons head tail ih =>
    let nextLe := le.set (tableTemporary tags head) (.Vptr cells cellBase)
    obtain ⟨middle,headRun,stored,headRead,headFrame,headAccess,headNext⟩ :=
      table_store tags head m before table header cells offset cellBase old read frame access le input k
        (tail.foldr (fun i next => .Ssequence (tableStatement tags i) next) rest)
    have nextInput : nextLe.get Arm64Addressing._addressing = some (.Vptr header offset) :=
      (CC.PTree.gso _ _ _ _ (table_temporaries tags head).1).trans input
    obtain ⟨after,tailRun,tailRead,tailOther,tailBlocks,tailFrame,tailAccess,tailNext⟩ :=
      ih middle (frame.trans headFrame) (headAccess.trans access) nextLe nextInput
    have headOther (j : Fin 31) (different : j ≠ head) :
        CC.Mem.load CC.Mptr middle table.block (8 * (j.val : Int)) =
          CC.Mem.load CC.Mptr before table.block (8 * (j.val : Int)) := by
      have ne : j.val ≠ head.val := fun equal => different (Fin.ext equal)
      have separated : 8 * (j.val : Int) + 8 ≤ 8 * (head.val : Int) ∨
          8 * (head.val : Int) + 8 ≤ 8 * (j.val : Int) := by omega
      exact CC.Mem.load_store_other stored _ _ _ (.inr separated)
    refine ⟨after,?_,?_,?_,?_,headFrame.trans tailFrame,
      tailAccess.trans headAccess,tailNext.trans headNext⟩
    · simpa only [List.foldr_cons,List.length_cons,Nat.mul_add,Nat.mul_one,
        Nat.add_comm,tableTemps,List.foldl_cons,nextLe] using headRun.trans tailRun
    · intro i member
      by_cases later : i ∈ tail
      · exact tailRead i later
      · have same : i = head := (List.mem_cons.mp member).resolve_right later
        subst i
        exact (tailOther head later).trans headRead
    · intro i absent
      have notHead : i ≠ head := by intro same; apply absent; simp only [same,List.mem_cons_self]
      have notTail : i ∉ tail := fun member => absent (List.mem_cons_of_mem _ member)
      exact (tailOther i notTail).trans (headOther i notHead)
    · intro b different chunk ofs
      exact (tailBlocks b different chunk ofs).trans (CC.Mem.load_store_other stored chunk b ofs (.inl different))

private theorem table_distinct (m : CC.Mem) (words : Table false m) (tags : Table true m) :
    words.block ≠ tags.block :=
  (allocated_local_storage (allocated m)).2 _ _ _ _ words.binding tags.binding (by decide +kernel)

private theorem table_list (tags : Bool) :
    List.ofFn (tableStatement tags) = (List.finRange 31).map (tableStatement tags) := by
  simp only [List.finRange,List.map_ofFn,Function.comp_def]

/-- The SAME original LINK call executes its real entry and both complete
31-row initializations (373 actual steps). Both final pointer tables and all
original caller bytes are derived, without extra current-read/store premises. -/
theorem initialize_tables (m : CC.Mem) (header registers tags : CC.Block)
    (offset registerBase tagBase : CC.Integers.Ptrofs) (address : BitVec 64) (k : CC.Cont)
    (old : header.toNat < m.nextblock.toNat)
    (wordRead : CC.Mem.load CC.Mptr m header
      (CC.Integers.Ptrofs.unsigned (CC.Integers.Ptrofs.add offset (CC.Integers.Ptrofs.repr 8))) =
        some (.Vptr registers registerBase))
    (tagRead : CC.Mem.load CC.Mptr m header
      (CC.Integers.Ptrofs.unsigned (CC.Integers.Ptrofs.add offset (CC.Integers.Ptrofs.repr 16))) =
        some (.Vptr tags tagBase)) :
    ∃ (words : Table false m) (tagTable : Table true m) (after : CC.Mem),
      InternalRun ge 373 (.Callstate (.Internal entry) [.Vptr header offset,.Vlong address] k m)
        (.State entry afterTables k (allocation m).1
          (tableTemps true (List.finRange 31) (.Vptr tags tagBase)
            (tableTemps false (List.finRange 31) (.Vptr registers registerBase)
              (temps (.Vptr header offset) address))) after) ∧
      (∀ i, CC.Mem.load CC.Mptr after words.block (8 * (i.val : Int)) =
        some (.Vptr registers (CC.Integers.Ptrofs.add registerBase (cellOffset false i)))) ∧
      (∀ i, CC.Mem.load CC.Mptr after tagTable.block (8 * (i.val : Int)) =
        some (.Vptr tags (CC.Integers.Ptrofs.add tagBase (cellOffset true i)))) ∧
      FrameBelow m.nextblock m after ∧
      after.access = (allocation m).2.access ∧ after.nextblock = (allocation m).2.nextblock := by
  obtain ⟨words⟩ := table_storage false m
  obtain ⟨tagTable⟩ := table_storage true m
  have input : (temps (.Vptr header offset) address).get Arm64Addressing._addressing =
      some (.Vptr header offset) := by
    simp +decide only [temps,CC.PTree.gss,CC.PTree.gso]
  obtain ⟨middle,wordRun,wordSlots,_,wordBlocks,wordFrame,wordAccess,wordNext⟩ :=
    run_table false (List.finRange 31) m (allocation m).2 words header registers offset registerBase old wordRead
      (allocation_frame m) rfl (temps (.Vptr header offset) address) input k
      ((List.ofFn (tableStatement true)).foldr CC.Stmt.Ssequence afterTables)
  have middleInput : (tableTemps false (List.finRange 31) (.Vptr registers registerBase)
      (temps (.Vptr header offset) address)).get Arm64Addressing._addressing = some (.Vptr header offset) :=
    (tableTemps_parameters _ _ _ _).1.trans input
  obtain ⟨after,tagRun,tagSlots,_,tagBlocks,tagFrame,tagAccess,tagNext⟩ :=
    run_table true (List.finRange 31) m middle tagTable header tags offset tagBase old tagRead
      ((allocation_frame m).trans wordFrame) wordAccess _ middleInput k afterTables
  have entryRun := enter m (.Vptr header offset) address k
  have trueRun : InternalRun ge 186
      (.State entry ((List.ofFn (tableStatement true)).foldr CC.Stmt.Ssequence afterTables)
        k (allocation m).1 (tableTemps false (List.finRange 31) (.Vptr registers registerBase)
          (temps (.Vptr header offset) address)) middle)
      (.State entry afterTables k (allocation m).1
        (tableTemps true (List.finRange 31) (.Vptr tags tagBase)
          (tableTemps false (List.finRange 31) (.Vptr registers registerBase)
            (temps (.Vptr header offset) address))) after) := by
    simpa only [table_list,List.foldr_map,List.length_finRange] using tagRun
  have falseRun : InternalRun ge 186
      (.State entry entry.fn_body k (allocation m).1 (temps (.Vptr header offset) address) (allocation m).2)
      (.State entry ((List.ofFn (tableStatement true)).foldr CC.Stmt.Ssequence afterTables)
        k (allocation m).1 (tableTemps false (List.finRange 31) (.Vptr registers registerBase)
          (temps (.Vptr header offset) address)) middle) := by
    simpa only [tables_source,table_list,List.foldr_map,List.length_finRange] using wordRun
  refine ⟨words,tagTable,after,(entryRun.trans falseRun).trans trueRun,?_,?_,
    ((allocation_frame m).trans wordFrame).trans tagFrame,tagAccess.trans wordAccess,tagNext.trans wordNext⟩
  · intro i
    exact (tagBlocks words.block (table_distinct m words tagTable) _ _).trans (wordSlots i (List.mem_finRange i))
  · intro i
    exact tagSlots i (List.mem_finRange i)

end KProgFormal.ClightRefinement.Arm64MemcpyLinkSource
