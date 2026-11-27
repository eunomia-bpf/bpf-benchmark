import KProgFormal.ClightRefinement.Arm64MemcpyLinkCall

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyLinkWriter
open Arm64MemcpyLinkProgram (ge writer)
open Arm64MemcpyLinkSource (tableName cellType cellOffset header_layout)
open Arm64MemcpyLinkCall (Header arguments)

def allocation (m : CC.Mem) : CC.Env × CC.Mem :=
  CC.doAllocVariables ge.genv_cenv CC.emptyEnv m writer.fn_vars

def temps {original header offset} (h : Header original header offset) (address : BitVec 64) : CC.TempEnv :=
  let a := (CC.createUndefTemps writer.fn_temps).set Arm64Address._coordinates (CC.Val.Vptr h.coordinates h.coordinateOffset)
  let b := a.set Arm64Address._registers (CC.Val.Vptr h.registers h.registerOffset)
  let c := b.set Arm64Address._tags (CC.Val.Vptr h.tags h.tagOffset)
  let d := c.set Arm64Address._stack_bytes (CC.Val.Vptr h.bytes h.byteOffset)
  let e := d.set Arm64Address._stack_tags (CC.Val.Vptr h.stackTags h.stackTagOffset)
  let f := e.set Arm64Address._capacity (CC.Val.Vint h.capacity)
  let g := f.set Arm64Address._bias (CC.Val.Vlong h.bias)
  let j := g.set Arm64Address._reg (CC.Val.Vlong (30#64))
  let l := j.set Arm64Address._value (CC.Val.Vlong address)
  l.set Arm64Address._tag (CC.Val.Vint (9#32))

private theorem names :
    CC.listNorepet (CC.varNames writer.fn_vars) ∧
    CC.listNorepet (CC.varNames writer.fn_params) ∧
    CC.listDisjoint (CC.varNames writer.fn_params) (CC.varNames writer.fn_temps) := by
  decide +kernel

theorem allocated (m : CC.Mem) :
    CC.AllocVariables ge.genv_cenv CC.emptyEnv m writer.fn_vars (allocation m).1 (allocation m).2 :=
  CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation m)).symm

theorem enter {original header offset} (h : Header original header offset) (address : BitVec 64)
    (m : CC.Mem) (k : CC.Cont) :
    InternalRun ge 1 (.Callstate (.Internal writer) (arguments h address) k m)
      (.State writer writer.fn_body k (allocation m).1 (temps h address) (allocation m).2) := by
  have entered : CC.FunctionEntry2 ge writer (arguments h address) m (allocation m).1 (temps h address) (allocation m).2 :=
    .intro names.1 names.2.1 names.2.2 (allocated m) rfl
  exact .step trivial (.internal_function _ _ _ _ _ _ _ entered) (.refl _)

theorem allocation_frame (m : CC.Mem) : FrameBelow m.nextblock m (allocation m).2 :=
  (FrameBelow.allocVariables (allocated m) m.nextblock (Nat.le_refl _)).2

theorem local_storage (m : CC.Mem) (id : CC.Ident) (ty : CC.Ty) (present : (id,ty) ∈ writer.fn_vars) :
    ∃ b, (allocation m).1.get id = some (b,ty) ∧
      m.nextblock.toNat ≤ b.toNat ∧ b.toNat < (allocation m).2.nextblock.toNat ∧
      CC.Mem.rangePerm (allocation m).2 b 0 (CC.sizeof ge.genv_cenv ty) .Cur .Freeable = true := by
  obtain ⟨b,bound⟩ := allocated_local_binding (allocated m) names.1 present
  exact ⟨b,bound,(allocated_local_storage (allocated m)).1 _ _ bound⟩

private def parts : List CC.Stmt × CC.Stmt × CC.Stmt := by
  run_tac do
    let mut rest ← Lean.Elab.Term.elabTerm (← `(writer.fn_body)) none
    let mut rows : Array Lean.Expr := #[]
    for _ in [:62] do
      rest ← Lean.Meta.withTransparency .all (Lean.Meta.whnf rest)
      unless rest.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "writer table prefix changed"
      let stmt ← Lean.Meta.withTransparency .all (Lean.Meta.whnf rest.getAppArgs[0]!)
      unless stmt.isAppOfArity ``CC.Stmt.Sassign 2 do throwError "writer table assignment changed"
      rows := rows.push stmt
      rest := rest.getAppArgs[1]!
    rest ← Lean.Meta.withTransparency .all (Lean.Meta.whnf rest)
    unless rest.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "writer stack prefix changed"
    let items ← Lean.Meta.mkListLit (Lean.mkConst ``CC.Stmt) rows.toList
    let tail ← Lean.Meta.mkAppM ``Prod.mk #[rest.getAppArgs[0]!,rest.getAppArgs[1]!]
    Lean.Elab.Tactic.closeMainGoal `actual_writer_setup (← Lean.Meta.mkAppM ``Prod.mk #[items,tail])

def stackStatement : CC.Stmt := parts.2.1
def ordinary : CC.Stmt := parts.2.2
def baseName (tags : Bool) : CC.Ident := if tags then Arm64Address._tags else Arm64Address._registers

def tableStatement (tags : Bool) (i : Fin 31) : CC.Stmt :=
  .Sassign
    (.Ederef (.Ebinop .Oadd
      (.Evar (tableName tags) (CC.tarray (CC.tptr (cellType tags)) 31))
      (.Econst_int (CC.Integers.Int.repr i.val) CC.tint)
      (CC.tptr (CC.tptr (cellType tags)))) (CC.tptr (cellType tags)))
    (.Ebinop .Oadd (.Etempvar (baseName tags) (CC.tptr (cellType tags)))
      (.Ecast (.Econst_int (CC.Integers.Int.repr i.val) CC.tuint) CC.tuchar) (CC.tptr (cellType tags)))

theorem tables_source : writer.fn_body =
    (List.ofFn (tableStatement false)).foldr CC.Stmt.Ssequence
      ((List.ofFn (tableStatement true)).foldr CC.Stmt.Ssequence (.Ssequence stackStatement ordinary)) := by
  run_tac do
    let goal ← Lean.Elab.Tactic.getMainGoal
    let target ← Lean.instantiateMVars (← goal.getType)
    goal.assign (← Lean.Meta.mkEqRefl target.getAppArgs[2]!)
    Lean.Elab.Tactic.replaceMainGoal []

private def stackComposite : CC.Composite :=
  (ge.genv_cenv.get Arm64Address.__2882).get (by decide +kernel)

theorem stack_layout :
    ge.genv_cenv.get Arm64Address.__2882 = some stackComposite ∧
    CC.fieldOffset ge.genv_cenv Arm64Address._b stackComposite.co_members = .OK (0,.Full) ∧
    CC.sizeof ge.genv_cenv (.Tstruct Arm64Address.__2882 CC.noattr) = 8 := by
  decide +kernel

structure Table (tags : Bool) (m : CC.Mem) where
  block : CC.Block
  binding : (allocation m).1.get (tableName tags) =
    some (block,CC.tarray (CC.tptr (cellType tags)) 31)
  fresh : m.nextblock.toNat ≤ block.toNat
  owned : CC.Mem.rangePerm (allocation m).2 block 0 248 .Cur .Freeable = true

theorem table_storage (tags : Bool) (m : CC.Mem) : Nonempty (Table tags m) := by
  have declared : (tableName tags,CC.tarray (CC.tptr (cellType tags)) 31) ∈ writer.fn_vars := by
    cases tags <;> decide +kernel
  have size : CC.sizeof ge.genv_cenv (CC.tarray (CC.tptr (cellType tags)) 31) = 248 := by
    cases tags <;> decide +kernel
  obtain ⟨block,bound,fresh,_,owned⟩ := local_storage m _ _ declared
  exact ⟨⟨block,bound,fresh,by simpa only [size] using owned⟩⟩


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
/-- The actual writer table store derives permission from its own real
allocator and retains the SAME parameter pointer and wrapping arithmetic. -/
theorem table_store (tags : Bool) (i : Fin 31) (m before : CC.Mem) (table : Table tags m)
    (cells : CC.Block) (cellBase : CC.Integers.Ptrofs)
    (access : before.access = (allocation m).2.access)
    (le : CC.TempEnv) (input : le.get (baseName tags) = some (.Vptr cells cellBase))
    (k : CC.Cont) (rest : CC.Stmt) :
    ∃ after,
      InternalRun ge 3
        (.State writer (.Ssequence (tableStatement tags i) rest) k (allocation m).1 le before)
        (.State writer rest k (allocation m).1 le after) ∧
      CC.Mem.store CC.Mptr before table.block (8 * (i.val : Int))
        (.Vptr cells (CC.Integers.Ptrofs.add cellBase (cellOffset tags i))) = some after ∧
      CC.Mem.load CC.Mptr after table.block (8 * (i.val : Int)) =
        some (.Vptr cells (CC.Integers.Ptrofs.add cellBase (cellOffset tags i))) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧ after.nextblock = before.nextblock := by
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
  have addSlot := add_slot tags i before table.block 0
  have addCell := add_cells tags i before cells cellBase
  have slotZero (ofs : CC.Integers.Ptrofs) : CC.Integers.Ptrofs.add 0 ofs = ofs := BitVec.zero_add ofs
  rw [slotZero] at addSlot
  simp only [CC.tptr,CC.tarray,CC.tint,CC.tuchar] at addSlot
  simp only [CC.tptr,CC.tuchar] at addCell
  have narrow := (indices i).2.1
  have unsignedSlot := (indices i).1
  simp only [CC.Mptr,CC.Archi.ptr64,ite_true] at stored
  have execution : InternalRun ge 3
      (.State writer (.Ssequence (tableStatement tags i) rest) k (allocation m).1 le before)
      (.State writer rest k (allocation m).1 le after) := by
    run_tac do
      let reduce ← `(tactic|
        simp +decide only [tableStatement,CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,CC.doDerefLoc,
          CC.doAssignLoc,CC.lvalOfVar,CC.accessMode,CC.typeof,CC.Mem.loadv,CC.Mem.storev,
          input,table.binding,stored,addSlot,addCell,narrow,unsignedSlot,
          CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntInt,CC.Integers.Int.zero_ext,
          CC.Integers.MI.zero_ext,CC.tarray,CC.tptr,CC.tint,CC.tuchar,CC.tuint,
          CC.Mptr,CC.Archi.ptr64,CC.Integers.Ptrofs.zero,CC.Integers.MI.zero,
          CC.E0,CC.Eapp,List.nil_append,List.append_nil,ite_true,ite_false,eq_self,
          Bool.false_eq_true,Bool.true_eq_false] <;> try rfl)
      for _ in [:3] do
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
        Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
        Lean.Elab.Tactic.evalTactic reduce
      Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))
  exact ⟨after,execution,stored,
    by simpa [CC.Mptr,CC.Archi.ptr64,CC.Val.loadResult] using CC.Mem.load_store_same stored,
    FrameBelow.store table.fresh stored,CC.Mem.store_access stored,CC.Mem.store_nextblock stored⟩

theorem run_table (tags : Bool) (rows : List (Fin 31)) (m before : CC.Mem) (table : Table tags m)
    (cells : CC.Block) (cellBase : CC.Integers.Ptrofs)
    (access : before.access = (allocation m).2.access)
    (le : CC.TempEnv) (input : le.get (baseName tags) = some (.Vptr cells cellBase))
    (k : CC.Cont) (rest : CC.Stmt) :
    ∃ after,
      InternalRun ge (3 * rows.length)
        (.State writer (rows.foldr (fun i next => .Ssequence (tableStatement tags i) next) rest)
          k (allocation m).1 le before)
        (.State writer rest k (allocation m).1 le after) ∧
      (∀ i ∈ rows, CC.Mem.load CC.Mptr after table.block (8 * (i.val : Int)) =
        some (.Vptr cells (CC.Integers.Ptrofs.add cellBase (cellOffset tags i)))) ∧
      (∀ i ∉ rows, CC.Mem.load CC.Mptr after table.block (8 * (i.val : Int)) =
        CC.Mem.load CC.Mptr before table.block (8 * (i.val : Int))) ∧
      (∀ b, b ≠ table.block → ∀ chunk ofs, CC.Mem.load chunk after b ofs = CC.Mem.load chunk before b ofs) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧ after.nextblock = before.nextblock := by
  induction rows generalizing before with
  | nil =>
    refine ⟨before,.refl _,?_,?_,?_,FrameBelow.refl _ _,rfl,rfl⟩
    · intro i member; cases member
    · intro i absent; rfl
    · intro b different chunk ofs; rfl
  | cons head tail ih =>
    obtain ⟨middle,headRun,stored,headRead,headFrame,headAccess,headNext⟩ :=
      table_store tags head m before table cells cellBase access le input k
        (tail.foldr (fun i next => .Ssequence (tableStatement tags i) next) rest)
    obtain ⟨after,tailRun,tailRead,tailOther,tailBlocks,tailFrame,tailAccess,tailNext⟩ :=
      ih middle (headAccess.trans access)
    have headOther (j : Fin 31) (different : j ≠ head) :
        CC.Mem.load CC.Mptr middle table.block (8 * (j.val : Int)) =
          CC.Mem.load CC.Mptr before table.block (8 * (j.val : Int)) := by
      have ne : j.val ≠ head.val := fun equal => different (Fin.ext equal)
      have separated : 8 * (j.val : Int) + 8 ≤ 8 * (head.val : Int) ∨
          8 * (head.val : Int) + 8 ≤ 8 * (j.val : Int) := by omega
      exact CC.Mem.load_store_other stored _ _ _ (.inr separated)
    refine ⟨after,?_,?_,?_,?_,headFrame.trans tailFrame,
      tailAccess.trans headAccess,tailNext.trans headNext⟩
    · simpa only [List.foldr_cons,List.length_cons,Nat.mul_add,Nat.mul_one,Nat.add_comm] using headRun.trans tailRun
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

theorem parameter_reads {original header offset} (h : Header original header offset) (address : BitVec 64) :
    (∀ tags, (temps h address).get (baseName tags) =
      some (.Vptr (if tags then h.tags else h.registers) (if tags then h.tagOffset else h.registerOffset))) ∧
    (temps h address).get Arm64Address._stack_bytes = some (.Vptr h.bytes h.byteOffset) := by
  constructor
  · intro tags
    cases tags <;> simp +decide only [temps,baseName,CC.PTree.gss,CC.PTree.gso,ite_true,ite_false,Bool.false_eq_true]
  · simp +decide only [temps,CC.PTree.gss,CC.PTree.gso]

private theorem table_distinct (m : CC.Mem) (words : Table false m) (tags : Table true m) :
    words.block ≠ tags.block :=
  (allocated_local_storage (allocated m)).2 _ _ _ _ words.binding tags.binding (by decide +kernel)

private theorem table_list (tags : Bool) :
    List.ofFn (tableStatement tags) = (List.finRange 31).map (tableStatement tags) := by
  simp only [List.finRange,List.map_ofFn,Function.comp_def]

theorem stack_source : stackStatement = .Sassign
    (.Efield (.Evar Arm64Address.___a64_stack (.Tstruct Arm64Address.__2882 CC.noattr))
      Arm64Address._b (CC.tptr (CC.tvolatile CC.tuchar)))
    (.Etempvar Arm64Address._stack_bytes (CC.tptr (CC.tvolatile CC.tuchar))) := by
  run_tac do
    let goal ← Lean.Elab.Tactic.getMainGoal
    let target ← Lean.instantiateMVars (← goal.getType)
    goal.assign (← Lean.Meta.mkEqRefl target.getAppArgs[2]!)
    Lean.Elab.Tactic.replaceMainGoal []

set_option hygiene false in
theorem stack_write (m before : CC.Mem) (stack : CC.Block)
    (binding : (allocation m).1.get Arm64Address.___a64_stack =
      some (stack,.Tstruct Arm64Address.__2882 CC.noattr))
    (fresh : m.nextblock.toNat ≤ stack.toNat)
    (owned : CC.Mem.rangePerm (allocation m).2 stack 0 8 .Cur .Freeable = true)
    (access : before.access = (allocation m).2.access)
    (bytes : CC.Block) (offset : CC.Integers.Ptrofs) (le : CC.TempEnv)
    (input : le.get Arm64Address._stack_bytes = some (.Vptr bytes offset)) (k : CC.Cont) :
    ∃ after, InternalRun ge 3
        (.State writer (.Ssequence stackStatement ordinary) k (allocation m).1 le before)
        (.State writer ordinary k (allocation m).1 le after) ∧
      CC.Mem.store CC.Mptr before stack 0 (.Vptr bytes offset) = some after ∧
      CC.Mem.load CC.Mptr after stack 0 = some (.Vptr bytes offset) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧ after.nextblock = before.nextblock := by
  have valid : CC.Mem.validAccess before CC.Mptr stack 0 .Writable = true := by
    simp only [CC.Mem.validAccess,Bool.and_eq_true]
    refine ⟨?_,by decide +kernel⟩
    apply CC.Mem.rangePerm_intro
    intro ofs lower upper
    have permission := CC.Mem.perm_implies
      (CC.Mem.rangePerm_perm _ _ _ _ _ _ owned ofs lower (by change ofs < 0 + 8 at upper; omega))
      (by decide : CC.permOrder .Freeable .Writable = true)
    simpa only [CC.Mem.perm,access] using permission
  have exists_store : ∃ after, CC.Mem.store CC.Mptr before stack 0 (.Vptr bytes offset) = some after := by
    unfold CC.Mem.store
    rw [valid]
    exact ⟨_,rfl⟩
  obtain ⟨after,stored⟩ := exists_store
  have zero : CC.Integers.Ptrofs.repr 0 = 0 := rfl
  have stackOffset : (CC.Integers.Ptrofs.add CC.Integers.Ptrofs.zero 0).unsigned = 0 := rfl
  have addZero : CC.Integers.Ptrofs.add 0 0 = 0 := rfl
  have unsignedZero : CC.Integers.Ptrofs.unsigned 0 = 0 := rfl
  simp only [CC.Mptr,CC.Archi.ptr64,ite_true] at stored
  have execution : InternalRun ge 3
      (.State writer (.Ssequence stackStatement ordinary) k (allocation m).1 le before)
      (.State writer ordinary k (allocation m).1 le after) := by
    run_tac do
      let reduce ← `(tactic|
        simp +decide only [stack_source,CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,CC.lvalOfVar,
          CC.lvalOfField,CC.doDerefLoc,CC.doAssignLoc,CC.accessMode,CC.typeof,CC.Mem.loadv,
          CC.Mem.storev,binding,input,stored,stack_layout.1,stack_layout.2.1,
          CC.Cop.semCast,CC.Cop.classifyCast,CC.tptr,CC.Mptr,CC.Archi.ptr64,zero,stackOffset,addZero,unsignedZero,
          CC.E0,CC.Eapp,List.nil_append,List.append_nil,ite_true,ite_false,eq_self] <;> try rfl)
      for _ in [:3] do
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
        Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
        Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
        Lean.Elab.Tactic.evalTactic reduce
      Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))
  exact ⟨after,execution,stored,
    by simpa [CC.Mptr,CC.Archi.ptr64,CC.Val.loadResult] using CC.Mem.load_store_same stored,
    FrameBelow.store fresh stored,CC.Mem.store_access stored,CC.Mem.store_nextblock stored⟩

/-- Enter the real three-local writer,execute both actual pointer tables
and its actual stack-descriptor store once,retaining every original byte. -/
theorem initialize_writer {original header offset} (h : Header original header offset)
    (address : BitVec 64) (m : CC.Mem) (k : CC.Cont) :
    ∃ (words : Table false m) (tags : Table true m) (stack : CC.Block) (after : CC.Mem),
      InternalRun ge 190 (.Callstate (.Internal writer) (arguments h address) k m)
        (.State writer ordinary k (allocation m).1 (temps h address) after) ∧
      (∀ i, CC.Mem.load CC.Mptr after words.block (8 * (i.val : Int)) =
        some (.Vptr h.registers (CC.Integers.Ptrofs.add h.registerOffset (cellOffset false i)))) ∧
      (∀ i, CC.Mem.load CC.Mptr after tags.block (8 * (i.val : Int)) =
        some (.Vptr h.tags (CC.Integers.Ptrofs.add h.tagOffset (cellOffset true i)))) ∧
      (allocation m).1.get Arm64Address.___a64_stack =
        some (stack,.Tstruct Arm64Address.__2882 CC.noattr) ∧
      CC.Mem.load CC.Mptr after stack 0 = some (.Vptr h.bytes h.byteOffset) ∧
      FrameBelow m.nextblock m after ∧
      after.access = (allocation m).2.access ∧ after.nextblock = (allocation m).2.nextblock := by
  obtain ⟨words⟩ := table_storage false m
  obtain ⟨tags⟩ := table_storage true m
  obtain ⟨stack,stackBinding,stackFresh,stackUpper,stackOwned⟩ :=
    local_storage m Arm64Address.___a64_stack (.Tstruct Arm64Address.__2882 CC.noattr) (by decide +kernel)
  rw [stack_layout.2.2] at stackOwned
  have parameters := parameter_reads h address
  obtain ⟨middle,wordRun,wordSlots,_,wordBlocks,wordFrame,wordAccess,wordNext⟩ :=
    run_table false (List.finRange 31) m (allocation m).2 words h.registers h.registerOffset
      rfl (temps h address) (parameters.1 false) k
      ((List.ofFn (tableStatement true)).foldr CC.Stmt.Ssequence (.Ssequence stackStatement ordinary))
  obtain ⟨written,tagRun,tagSlots,_,tagBlocks,tagFrame,tagAccess,tagNext⟩ :=
    run_table true (List.finRange 31) m middle tags h.tags h.tagOffset
      wordAccess (temps h address) (parameters.1 true) k (.Ssequence stackStatement ordinary)
  obtain ⟨after,stackRun,stored,stackRead,stackFrame,stackAccess,stackNext⟩ :=
    stack_write m written stack stackBinding stackFresh stackOwned (tagAccess.trans wordAccess)
      h.bytes h.byteOffset (temps h address) parameters.2 k
  have entryRun := enter h address m k
  have trueRun : InternalRun ge 93
      (.State writer ((List.ofFn (tableStatement true)).foldr CC.Stmt.Ssequence
        (.Ssequence stackStatement ordinary)) k (allocation m).1 (temps h address) middle)
      (.State writer (.Ssequence stackStatement ordinary) k (allocation m).1 (temps h address) written) := by
    simpa only [table_list,List.foldr_map,List.length_finRange] using tagRun
  have falseRun : InternalRun ge 93
      (.State writer writer.fn_body k (allocation m).1 (temps h address) (allocation m).2)
      (.State writer ((List.ofFn (tableStatement true)).foldr CC.Stmt.Ssequence
        (.Ssequence stackStatement ordinary)) k (allocation m).1 (temps h address) middle) := by
    simpa only [tables_source,table_list,List.foldr_map,List.length_finRange] using wordRun
  have wordStack : words.block ≠ stack :=
    (allocated_local_storage (allocated m)).2 _ _ _ _ words.binding stackBinding (by decide +kernel)
  have tagStack : tags.block ≠ stack :=
    (allocated_local_storage (allocated m)).2 _ _ _ _ tags.binding stackBinding (by decide +kernel)
  refine ⟨words,tags,stack,after,((entryRun.trans falseRun).trans trueRun).trans stackRun,?_,?_,
    stackBinding,stackRead,(((allocation_frame m).trans wordFrame).trans tagFrame).trans stackFrame,
    stackAccess.trans (tagAccess.trans wordAccess),stackNext.trans (tagNext.trans wordNext)⟩
  · intro i
    exact (CC.Mem.load_store_other stored _ _ _ (.inl wordStack)).trans
      ((tagBlocks words.block (table_distinct m words tags) _ _).trans (wordSlots i (List.mem_finRange i)))
  · intro i
    exact (CC.Mem.load_store_other stored _ _ _ (.inl tagStack)).trans (tagSlots i (List.mem_finRange i))


/-- The SAME original LINK entry,outer tables,header setup and CALL feed
the actual three-local writer initialization. No prefix is re-executed. -/
theorem execute {m : CC.Mem} {header : CC.Block} {offset : CC.Integers.Ptrofs}
    (h : Header m header offset) (old : header.toNat < m.nextblock.toNat)
    (address : BitVec 64) (k : CC.Cont) :
    ∃ (outerWords : Arm64MemcpyLinkSource.Table false m)
      (outerTags : Arm64MemcpyLinkSource.Table true m) (before : CC.Mem)
      (words : Table false before) (tags : Table true before) (stack : CC.Block) (after : CC.Mem),
      InternalRun ge 590
        (.Callstate (.Internal Arm64MemcpyLinkProgram.entry) [.Vptr header offset,.Vlong address] k m)
        (.State writer ordinary (Arm64MemcpyLinkCall.writerCont h address
          (Arm64MemcpyLinkCall.initializedTemps h address) k)
          (allocation before).1 (temps h address) after) ∧
      (∀ i, CC.Mem.load CC.Mptr after outerWords.block (8 * (i.val : Int)) =
        some (.Vptr h.registers (CC.Integers.Ptrofs.add h.registerOffset (cellOffset false i)))) ∧
      (∀ i, CC.Mem.load CC.Mptr after outerTags.block (8 * (i.val : Int)) =
        some (.Vptr h.tags (CC.Integers.Ptrofs.add h.tagOffset (cellOffset true i)))) ∧
      (∀ i, CC.Mem.load CC.Mptr after words.block (8 * (i.val : Int)) =
        some (.Vptr h.registers (CC.Integers.Ptrofs.add h.registerOffset (cellOffset false i)))) ∧
      (∀ i, CC.Mem.load CC.Mptr after tags.block (8 * (i.val : Int)) =
        some (.Vptr h.tags (CC.Integers.Ptrofs.add h.tagOffset (cellOffset true i)))) ∧
      (allocation before).1.get Arm64Address.___a64_stack =
        some (stack,.Tstruct Arm64Address.__2882 CC.noattr) ∧
      CC.Mem.load CC.Mptr after stack 0 = some (.Vptr h.bytes h.byteOffset) ∧
      FrameBelow m.nextblock m after ∧ FrameBelow before.nextblock before after ∧
      before.access = (Arm64MemcpyLinkSource.allocation m).2.access ∧
      before.nextblock = (Arm64MemcpyLinkSource.allocation m).2.nextblock ∧
      after.access = (allocation before).2.access ∧ after.nextblock = (allocation before).2.nextblock := by
  obtain ⟨outerWords,outerTags,before,prefixRun,outerWordSlots,outerTagSlots,outerFrame,outerAccess,outerNext⟩ :=
    Arm64MemcpyLinkCall.execute h old address k
  obtain ⟨words,tags,stack,after,body,wordSlots,tagSlots,stackBinding,stackRead,innerFrame,innerAccess,innerNext⟩ :=
    initialize_writer h address before
      (Arm64MemcpyLinkCall.writerCont h address (Arm64MemcpyLinkCall.initializedTemps h address) k)
  have outerWordOld : outerWords.block.toNat < before.nextblock.toNat := by
    rw [outerNext]
    exact ((allocated_local_storage (Arm64MemcpyLinkSource.allocated m)).1 _ _ outerWords.binding).2.1
  have outerTagOld : outerTags.block.toNat < before.nextblock.toNat := by
    rw [outerNext]
    exact ((allocated_local_storage (Arm64MemcpyLinkSource.allocated m)).1 _ _ outerTags.binding).2.1
  have frontier : m.nextblock.toNat ≤ before.nextblock.toNat := by
    rw [outerNext]
    exact (FrameBelow.allocVariables (Arm64MemcpyLinkSource.allocated m) m.nextblock (Nat.le_refl _)).1
  have frame : FrameBelow m.nextblock m after :=
    outerFrame.trans (fun b below => innerFrame b (by omega))
  exact ⟨outerWords,outerTags,before,words,tags,stack,after,prefixRun.trans body,
    (fun i => (innerFrame.load _ _ _ outerWordOld).trans (outerWordSlots i)),
    (fun i => (innerFrame.load _ _ _ outerTagOld).trans (outerTagSlots i)),
    wordSlots,tagSlots,stackBinding,stackRead,frame,innerFrame,outerAccess,outerNext,innerAccess,innerNext⟩

end KProgFormal.ClightRefinement.Arm64MemcpyLinkWriter
