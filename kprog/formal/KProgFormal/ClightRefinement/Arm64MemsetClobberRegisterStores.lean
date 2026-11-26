import KProgFormal.ClightRefinement.Arm64MemsetClobberRegisters

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemsetClobberRegisterStores

open Arm64Producer
open Arm64ProducerRegisterStorage
open Arm64ProgramEntryAllocation (world)
open Arm64MemsetClobberEntry (helper)
open Arm64MemsetClobberRegisters (declaration valueTemps callCont fieldExpr cellExpr wordType entryType)

theorem layout : Arm64RegisterWrite.GprLayout world := by
  constructor <;> decide +kernel

def temps {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry) (i : Fin 18) (le : CC.TempEnv) (value : BitVec 64) : CC.TempEnv :=
  ((((valueTemps i le value).set (declaration i).wordRootKey (.Vptr (storage.tables false).tableBlock 0)).set
    (declaration i).wordPtrKey (.Vptr ((storage.tables false).cellBlock (declaration i).reg) 0)).set
    (declaration i).tagRootKey (.Vptr (storage.tables true).tableBlock 0)).set
    (declaration i).tagPtrKey (.Vptr ((storage.tables true).cellBlock (declaration i).reg) 0)

private theorem slot_unsigned : ∀ i : Fin 31,
    CC.Integers.Ptrofs.unsigned (CC.Integers.Ptrofs.repr (8 * (i.val : Int))) =
      8 * (i.val : Int) := by decide +kernel

private theorem slot_offsets : ∀ i : Fin 31,
    CC.Integers.Ptrofs.add 0 (CC.Integers.Ptrofs.mul (CC.Integers.Ptrofs.repr 8)
      (CC.Cop.ptrofsOfInt .Signed (CC.Integers.Int.repr (i.val : Int)))) =
      CC.Integers.Ptrofs.repr (8 * (i.val : Int)) := by decide +kernel

private theorem add_slot (cenv : CC.CompositeEnv) (memory : CC.Mem) (tags : Bool) (block : CC.Block) (i : Fin 31) :
    CC.Cop.semBinaryOperation cenv .Oadd (.Vptr block 0)
      (CC.tptr (CC.tptr (tableCellType tags))) (.Vint (CC.Integers.Int.repr (i.val : Int))) CC.tint memory =
      some (.Vptr block (CC.Integers.Ptrofs.repr (8 * (i.val : Int)))) := by
  cases tags
  all_goals
    change some (CC.Val.Vptr block (CC.Integers.Ptrofs.add 0
      (CC.Integers.Ptrofs.mul (CC.Integers.Ptrofs.repr 8)
        (CC.Cop.ptrofsOfInt .Signed (CC.Integers.Int.repr (i.val : Int)))))) = _
    rw [slot_offsets i]

private theorem ptr_literals :
    CC.Integers.Ptrofs.unsigned (CC.Integers.Ptrofs.repr 8) = 8 ∧
    CC.Integers.Ptrofs.unsigned (CC.Integers.Ptrofs.repr 0) = 0 ∧
    CC.Integers.Ptrofs.repr 0 = 0 ∧ CC.Integers.Ptrofs.unsigned 0 = 0 := by decide +kernel

private theorem ptr_add_zero (offset : CC.Integers.Ptrofs) :
    CC.Integers.Ptrofs.add 0 offset = offset := BitVec.zero_add offset

private theorem tag_zero :
    BitVec.ofInt 32 0 &&& (BitVec.allOnes 32 >>> (32-8)) = 0 := by decide +kernel

set_option hygiene false in
/-- Execute the two inline assignments in the original clobber helper,
including its real root/cell reads and exact next-pair continuation. -/
theorem execute_stores {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry) (i : Fin 18) (le : CC.TempEnv) (value : BitVec 64)
    (entryRead : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (middle after : CC.Mem) (k : CC.Cont)
    (wordStore : CC.Mem.store .Mint64 before ((storage.tables false).cellBlock (declaration i).reg) 0
      (.Vlong value) = some middle)
    (tagStore : CC.Mem.store .Mint8unsigned middle ((storage.tables true).cellBlock (declaration i).reg) 0
      (.Vint 0) = some after) :
    InternalRun world 17
      (.State helper (.Ssequence (declaration i).wordRoot
        (.Ssequence (declaration i).wordPtr (declaration i).wordAssign))
        (.Kseq (.Ssequence (declaration i).tag (declaration i).next) k) CC.emptyEnv (valueTemps i le value) before)
      (.State helper (declaration i).next k CC.emptyEnv (temps storage i le value) after) := by
  have different : ∀ i : Fin 31, tableCellName false i ≠ Arm64Entry._entry ∧
      tableCellName false i ≠ tableName true := by decide +kernel
  have wordHeaderOther := storage.separate_local false (declaration i).reg _ _ _ entry.binding (different _).1
  have wordTagTableOther := storage.separate_local false (declaration i).reg _ _ _ (storage.tables true).binding (different _).2
  have wordRoot : CC.Mem.load CC.Mptr before entry.block 0 = some (.Vptr (storage.tables false).tableBlock 0) := storage.roots false
  have tagRoot : CC.Mem.load CC.Mptr middle entry.block 8 = some (.Vptr (storage.tables true).tableBlock 0) :=
    (CC.Mem.load_store_other wordStore CC.Mptr entry.block 8 (.inl (Ne.symm wordHeaderOther))).trans (storage.roots true)
  have tagSlot : CC.Mem.load CC.Mptr middle (storage.tables true).tableBlock (8 * ((declaration i).reg.val : Int)) =
      some (.Vptr ((storage.tables true).cellBlock (declaration i).reg) 0) :=
    (CC.Mem.load_store_other wordStore CC.Mptr (storage.tables true).tableBlock _ (.inl (Ne.symm wordTagTableOther))).trans
      (storage.slots true (declaration i).reg)
  have addWord := add_slot world.genv_cenv before false (storage.tables false).tableBlock (declaration i).reg
  have addTag := add_slot world.genv_cenv middle true (storage.tables true).tableBlock (declaration i).reg
  have unionId : Arm64Entry._arm64_sim_gpr = Arm64Program._arm64_sim_gpr := rfl
  simp only [CC.tptr, CC.tuchar, CC.tint, CC.Integers.Int.repr, CC.Integers.MI.repr,
    tableCellType, unionId, eq_self, Bool.false_eq_true, ite_true, ite_false] at addWord addTag
  have names := Arm64MemsetClobberRegisters.key_names i
  have keepValue (v : CC.Val) (t : CC.TempEnv) := CC.PTree.gso _ _ v t names.1
  have keepWordRoot (v : CC.Val) (t : CC.TempEnv) := CC.PTree.gso _ _ v t names.2.1
  have keepWordPtr (v : CC.Val) (t : CC.TempEnv) := CC.PTree.gso _ _ v t names.2.2.1
  have keepTagRoot (v : CC.Val) (t : CC.TempEnv) := CC.PTree.gso _ _ v t names.2.2.2.1
  have keepTagPtr (v : CC.Val) (t : CC.TempEnv) := CC.PTree.gso _ _ v t names.2.2.2.2.1
  have keepRootValue (v : CC.Val) (t : CC.TempEnv) := CC.PTree.gso _ _ v t names.2.2.2.2.2.1
  have keepPtrValue (v : CC.Val) (t : CC.TempEnv) := CC.PTree.gso _ _ v t names.2.2.2.2.2.2
  run_tac do
    let reduce ← `(tactic|
      simp +decide only [CC.doStep, (declaration i).tag_source,
        (declaration i).word_root_source, (declaration i).word_ptr_source, (declaration i).word_assign_source,
        (declaration i).tag_root_source, (declaration i).tag_ptr_source, (declaration i).tag_assign_source,
        fieldExpr, cellExpr, entryType, wordType, valueTemps, temps,
        CC.doEvalExpr, CC.doEvalLvalue, CC.doDerefLoc, CC.doAssignLoc, CC.lvalOfField,
        CC.Mem.loadv, CC.Mem.storev, CC.accessMode, CC.typeof,
        layout.entry, layout.cells, layout.tags, layout.cell, layout.payload,
        layout.cellPointer, layout.tagPointer, CC.PTree.gss,
        keepValue, keepWordRoot, keepWordPtr, keepTagRoot, keepTagPtr, keepRootValue, keepPtrValue,
        entryRead, names.1, names.2.1, names.2.2.1, names.2.2.2.1, names.2.2.2.2.1,
        names.2.2.2.2.2.1, names.2.2.2.2.2.2,
        wordRoot, storage.slots false (declaration i).reg, tagRoot, tagSlot, addWord, addTag,
        CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, CC.typeconv, CC.removeAttributes, CC.tattr,
        CC.tuchar, CC.tuint, CC.tint, CC.tulong, CC.tptr,
        CC.Integers.Int.repr, CC.Integers.MI.repr,
        CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext,
        CC.Integers.Int.signed, CC.Integers.MI.signed,
        CC.Integers.Int.unsigned, CC.Integers.MI.unsigned,
        CC.Val.offsetPtr, ptr_add_zero, BitVec.zero_add, ptr_literals.1, ptr_literals.2.1, ptr_literals.2.2.1, ptr_literals.2.2.2,
        CC.E0, wordStore, tagStore, tag_zero, slot_unsigned (declaration i).reg,
        ite_true, ite_false, eq_self, Bool.false_eq_true] <;> try rfl)
    for _ in [:17] do
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply InternalRun.step))
      Lean.Elab.Tactic.evalTactic (← `(tactic| trivial))
      Lean.Elab.Tactic.evalTactic (← `(tactic| apply CC.doStep_sound))
      Lean.Elab.Tactic.evalTactic reduce
    Lean.Elab.Tactic.evalTactic (← `(tactic| exact InternalRun.refl _))

/-- Actual inline-store effects, separate from any other writer function. -/
structure Effect {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry) (i : Fin 18) (value : BitVec 64) (after : CC.Mem) : Prop where
  stores : ∃ middle,
    CC.Mem.store .Mint64 before ((storage.tables false).cellBlock (declaration i).reg) 0 (.Vlong value) = some middle ∧
    CC.Mem.store .Mint8unsigned middle ((storage.tables true).cellBlock (declaration i).reg) 0 (.Vint 0) = some after
  word : CC.Mem.load .Mint64 after ((storage.tables false).cellBlock (declaration i).reg) 0 = some (.Vlong value)
  tag : CC.Mem.load .Mint8unsigned after ((storage.tables true).cellBlock (declaration i).reg) 0 = some (.Vint 0)
  caller : FrameBelow initial.nextblock before after
  access : after.access = before.access
  nextblock : after.nextblock = before.nextblock

private theorem store_exists (memory : CC.Mem) (chunk : CC.Chunk) (block : CC.Block) (value : CC.Val)
    (writable : CC.Mem.validAccess memory chunk block 0 .Writable = true) :
    ∃ after, CC.Mem.store chunk memory block 0 value = some after := by
  simp only [CC.Mem.store, writable, ite_true]
  exact ⟨_,rfl⟩

/-- Current source write permissions construct both successful stores. The
word readback survives the following tag store by allocation separation. -/
theorem write {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry) (i : Fin 18) (value : BitVec 64) :
    ∃ after, Effect storage i value after := by
  obtain ⟨middle,wordStore⟩ := store_exists before .Mint64 ((storage.tables false).cellBlock (declaration i).reg)
    (.Vlong value) (storage.writable false (declaration i).reg)
  have tagWritable : CC.Mem.validAccess middle .Mint8unsigned
      ((storage.tables true).cellBlock (declaration i).reg) 0 .Writable = true :=
    (CC.Mem.validAccess_store_eq wordStore _ _ _ _).trans (storage.writable true (declaration i).reg)
  obtain ⟨after,tagStore⟩ := store_exists middle .Mint8unsigned
    ((storage.tables true).cellBlock (declaration i).reg) (.Vint 0) tagWritable
  have word : CC.Mem.load .Mint64 after ((storage.tables false).cellBlock (declaration i).reg) 0 = some (.Vlong value) :=
    (CC.Mem.load_store_other tagStore .Mint64 _ 0
      (.inl (storage.cells_distinct false true (declaration i).reg (declaration i).reg (.inl (by decide))))).trans
      (CC.Mem.load_store_same wordStore)
  exact ⟨after,⟨⟨middle,wordStore,tagStore⟩,word,CC.Mem.load_store_same tagStore,
    (FrameBelow.store (storage.cell_fresh false (declaration i).reg) wordStore).trans
      (FrameBelow.store (storage.cell_fresh true (declaration i).reg) tagStore),
    (CC.Mem.store_access tagStore).trans (CC.Mem.store_access wordStore),
    (CC.Mem.store_nextblock tagStore).trans (CC.Mem.store_nextblock wordStore)⟩⟩

theorem Effect.local_load {initial before after : CC.Mem} {entry : HeaderLocal initial}
    {storage : Storage initial before entry} {i : Fin 18} {value : BitVec 64}
    (effect : Effect storage i value after) (id : CC.Ident) (ty : CC.Ty) (block : CC.Block)
    (binding : (allocation initial).1.get id = some (block,ty))
    (wordOther : tableCellName false (declaration i).reg ≠ id)
    (tagOther : tableCellName true (declaration i).reg ≠ id) (chunk : CC.Chunk) (offset : Int) :
    CC.Mem.load chunk after block offset = CC.Mem.load chunk before block offset := by
  obtain ⟨middle,wordStore,tagStore⟩ := effect.stores
  exact (CC.Mem.load_store_other tagStore chunk block offset
    (.inl (Ne.symm (storage.separate_local true (declaration i).reg _ _ _ binding tagOther)))).trans
      (CC.Mem.load_store_other wordStore chunk block offset
        (.inl (Ne.symm (storage.separate_local false (declaration i).reg _ _ _ binding wordOther))))

theorem Effect.other_cell {initial before after : CC.Mem} {entry : HeaderLocal initial}
    {storage : Storage initial before entry} {i : Fin 18} {value : BitVec 64}
    (effect : Effect storage i value after) (tags : Bool) (j : Fin 31) (different : j ≠ (declaration i).reg)
    (chunk : CC.Chunk) (offset : Int) :
    CC.Mem.load chunk after ((storage.tables tags).cellBlock j) offset =
      CC.Mem.load chunk before ((storage.tables tags).cellBlock j) offset := by
  obtain ⟨middle,wordStore,tagStore⟩ := effect.stores
  exact (CC.Mem.load_store_other tagStore chunk _ offset
    (.inl (storage.cells_distinct tags true j (declaration i).reg (.inr different)))).trans
      (CC.Mem.load_store_other wordStore chunk _ offset
        (.inl (storage.cells_distinct tags false j (declaration i).reg (.inr different))))

/-- Consume the real provider return and execute both original assignments.
The supplied heap provides current rights; the final heap is constructed. -/
theorem returned_write {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry) (i : Fin 18) (le : CC.TempEnv) (value : BitVec 64)
    (entryRead : le.get Arm64Program._entry = some (.Vptr entry.block 0)) (k : CC.Cont) :
    ∃ after, Effect storage i value after ∧
      InternalRun world 19 (.Returnstate (.Vlong value) (callCont i le k) before)
        (.State helper (declaration i).next k CC.emptyEnv (temps storage i le value) after) := by
  obtain ⟨after,effect⟩ := write storage i value
  obtain ⟨middle,wordStore,tagStore⟩ := effect.stores
  exact ⟨after,effect,InternalRun.trans (Arm64MemsetClobberRegisters.returned i le before k value)
    (execute_stores storage i le value entryRead middle after k wordStore tagStore)⟩

theorem entry_retained {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry) (i : Fin 18) (le : CC.TempEnv) (value : BitVec 64) :
    (temps storage i le value).get Arm64Program._entry = le.get Arm64Program._entry := by
  unfold temps
  rw [CC.PTree.gso _ _ _ _ (Arm64MemsetClobberRegisters.key_names i).2.2.2.2.1,
    CC.PTree.gso _ _ _ _ (Arm64MemsetClobberRegisters.key_names i).2.2.2.1,
    CC.PTree.gso _ _ _ _ (Arm64MemsetClobberRegisters.key_names i).2.2.1,
    CC.PTree.gso _ _ _ _ (Arm64MemsetClobberRegisters.key_names i).2.1]
  exact Arm64MemsetClobberRegisters.returned_entry i le value

end KProgFormal.ClightRefinement.Arm64MemsetClobberRegisterStores
