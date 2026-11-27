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

private theorem table_declaration :
    (Arm64Addressing.___a64_cells,
      CC.tarray (CC.tptr (.Tunion Arm64Addressing._arm64_sim_gpr CC.noattr)) 31) ∈ entry.fn_vars ∧
    CC.sizeof ge.genv_cenv
      (CC.tarray (CC.tptr (.Tunion Arm64Addressing._arm64_sim_gpr CC.noattr)) 31) = 248 := by
  decide +kernel

set_option hygiene false in
/-- One true header read and first pointer-table store on the original LINK
body. Allocation derives the store permission; no successful store or current
header read is supplied separately. Every original caller byte is retained. -/
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
  obtain ⟨block,bound,fresh,upper,owned⟩ := local_storage m _ _ table_declaration.1
  rw [table_declaration.2] at owned
  have access : CC.Mem.validAccess (allocation m).2 CC.Mptr block 0 .Writable = true := by
    simp only [CC.Mem.validAccess, Bool.and_eq_true]
    refine ⟨?_,by decide +kernel⟩
    apply CC.Mem.rangePerm_intro
    intro offset lower higher
    exact CC.Mem.perm_implies
      (CC.Mem.rangePerm_perm _ _ _ _ _ _ owned offset lower (by change offset < 0 + 8 at higher; omega))
      (by decide : CC.permOrder .Freeable .Writable = true)
  have exists_store : ∃ after, CC.Mem.store CC.Mptr (allocation m).2 block 0
      (.Vptr registers registerOffset) = some after := by
    unfold CC.Mem.store
    rw [access]
    exact ⟨_,rfl⟩
  obtain ⟨after,stored⟩ := exists_store
  have loaded := (allocation_frame m).load CC.Mptr header
    (CC.Integers.Ptrofs.unsigned (CC.Integers.Ptrofs.add headerOffset (CC.Integers.Ptrofs.repr 8))) old
  rw [read] at loaded
  simp only [CC.Integers.Ptrofs.add,CC.Integers.Ptrofs.repr,
    CC.Integers.MI.add,CC.Integers.MI.repr,BitVec.ofInt_ofNat] at loaded
  have unsignedZero : CC.Integers.Ptrofs.unsigned (0 : CC.Integers.Ptrofs) = 0 := rfl
  simp only [CC.Mptr,CC.Archi.ptr64,ite_true] at stored loaded
  have execution : InternalRun ge 6
      (.State entry entry.fn_body k (allocation m).1 (temps (.Vptr header headerOffset) address) (allocation m).2)
      (.State entry afterFirst k (allocation m).1
        ((temps (.Vptr header headerOffset) address).set Arm64Addressing._t'69 (.Vptr registers registerOffset)) after) := by
    run_tac do
      let reduce ← `(tactic| simp +decide only [steps,InternalPath,InternalState,first_source,first,sourceParts,
      temps,CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,CC.doDerefLoc,CC.doAssignLoc,
      CC.lvalOfVar,CC.lvalOfField,CC.accessMode,CC.typeof,CC.Mem.loadv,CC.Mem.storev,
      CC.PTree.gss,CC.PTree.gso,header_layout.1,header_layout.2.2.1,header_layout.2.2.2.2.2.2.2.2,
      bound,loaded,stored,CC.Cop.semBinaryOperation,CC.Cop.semAdd,CC.Cop.classifyAdd,
      CC.Cop.semAddPtrInt,CC.Cop.ptrofsOfInt,CC.Cop.semCast,CC.Cop.classifyCast,
      CC.Cop.castIntInt,CC.Integers.Int.zero_ext,CC.Integers.MI.zero_ext,CC.Integers.Int.repr,
      CC.typeconv,CC.removeAttributes,CC.tattr,CC.sizeof,CC.tarray,CC.tptr,CC.tint,CC.tuchar,CC.tuint,CC.Mptr,
      CC.Archi.ptr64,CC.Integers.Ptrofs.zero,CC.Integers.MI.zero,CC.E0,CC.Eapp,
      CC.Integers.Ptrofs.add,CC.Integers.Ptrofs.mul,CC.Integers.Ptrofs.repr,
      CC.Integers.MI.add,CC.Integers.MI.mul,CC.Integers.MI.repr,
      CC.Integers.Ptrofs.of_ints,CC.Integers.MI.signed,unsignedZero,BitVec.add_zero,BitVec.zero_add,BitVec.mul_zero,BitVec.ofInt_ofNat,BitVec.toInt_zero,BitVec.zero_and,List.nil_append,List.append_nil,ite_true,ite_false,eq_self,Bool.false_eq_true,Bool.true_eq_false] <;> try rfl)
      for _ in [:6] do
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
        Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
        Lean.Elab.Tactic.evalTactic reduce
      Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))
  exact ⟨block,after,bound,execution,
    by simpa [CC.Mptr,CC.Archi.ptr64,CC.Val.loadResult] using CC.Mem.load_store_same stored,
    (allocation_frame m).trans (FrameBelow.store fresh stored),
    CC.Mem.store_access stored,CC.Mem.store_nextblock stored⟩

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

end KProgFormal.ClightRefinement.Arm64MemcpyLinkSource
