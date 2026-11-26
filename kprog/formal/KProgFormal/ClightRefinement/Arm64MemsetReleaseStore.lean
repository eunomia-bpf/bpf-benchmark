import KProgFormal.ClightRefinement.Arm64MemsetReleaseLoop

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemsetReleaseStore

open Arm64ProgramEntryAllocation (world)
open Arm64MemsetClobberEntry (helper)

private structure Parts where
  call : CC.Stmt
  statement : CC.Stmt
  header : CC.Stmt
  store : CC.Stmt
  arguments : List CC.Expr

private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor arity do throwError "original release provider/store changed"
      pure actual.getAppArgs
    let root ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64MemsetReleaseLoop.selected)) none) ``CC.Stmt.Ssequence 2
    let statement ← peel root[1]! ``CC.Stmt.Ssequence 2
    let store ← peel statement[1]! ``CC.Stmt.Sbuiltin 4
    Lean.Elab.Tactic.closeMainGoal `actual_release_store_parts
      (← Lean.Meta.mkAppM ``Parts.mk #[root[0]!,root[1]!,statement[0]!,statement[1]!,store[3]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_release_store_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))
private def call : CC.Stmt := by run_tac cachePart (← `(parts.call))
def statement : CC.Stmt := by run_tac cachePart (← `(parts.statement))
private def header : CC.Stmt := by run_tac cachePart (← `(parts.header))
private def store : CC.Stmt := by run_tac cachePart (← `(parts.store))
private def arguments : List CC.Expr := by run_tac cachePart (← `(parts.arguments))

private theorem selected_source : Arm64MemsetReleaseLoop.selected = .Ssequence call statement := rfl
private theorem statement_source : statement = .Ssequence header store := rfl
private theorem store_source : store = .Sbuiltin none (.EF_vstore .Mint8unsigned)
    [CC.tptr (CC.tvolatile CC.tuchar),CC.tvolatile CC.tuchar] arguments := rfl
private theorem call_source : call = .Scall (some Arm64Program._t'1)
    (.Evar Arm64Program._native_lab_entry_input (.Tfunction [CC.tuint] CC.tulong CC.cc_default))
    [.Econst_int (CC.Integers.Int.repr 6) CC.tint] := rfl

def returnedTemps (le : CC.TempEnv) (value : BitVec 64) : CC.TempEnv := le.set Arm64Program._t'1 (.Vlong value)
def temps (le : CC.TempEnv) (stack : CC.Block) (value : BitVec 64) : CC.TempEnv :=
  (returnedTemps le value).set Arm64Program._t'235 (.Vptr stack 0)
def continuation (le : CC.TempEnv) (k : CC.Cont) : CC.Cont :=
  .Kcall (some Arm64Program._t'1) helper CC.emptyEnv le (.Kseq statement k)

/-- The selected original source calls the actual kind6 provider, with the
actual clobber helper's empty local environment and exact return target. -/
theorem ready (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    InternalRun world 2 (.State helper Arm64MemsetReleaseLoop.selected k CC.emptyEnv le m)
      (.Callstate Arm64OriginCache.inputFunction [.Vint (6#32)] (continuation le k) m) := by
  rw [selected_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [call_source]
  refine .step trivial ?_ (.refl _)
  apply CC.Step.call (tyargs := [CC.tuint]) (tyres := CC.tulong) (cconv := CC.cc_default)
    (vf := .Vptr Arm64ProgramEntryCall.inputBlock 0)
  · rfl
  · apply CC.doEvalExpr_sound
    simp only [CC.doEvalExpr,CC.lvalOfVar,CC.emptyEnv,CC.PTree.gempty,
      Arm64ProgramEntryColdRead.input_binding.1,CC.doDerefLoc,CC.accessMode]
    rfl
  · apply CC.doEvalExprlist_sound
    rfl
  · simpa +decide [CC.Genv.findFunct,CC.Integers.Ptrofs.eq,CC.Integers.Ptrofs.zero,
      CC.Integers.MI.eq,CC.Integers.MI.zero] using Arm64ProgramEntryCall.input_binding.2
  · rfl

private def entryComposite : CC.Composite :=
  (world.genv_cenv.get Arm64Program._kprog_arm64_entry).get (by decide +kernel)
private theorem layout :
    world.genv_cenv.get Arm64Program._kprog_arm64_entry = some entryComposite ∧
    CC.fieldOffset world.genv_cenv Arm64Program._b entryComposite.co_members = .OK (608,.Full) := by
  constructor <;> decide +kernel

private theorem header_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (entry stack : CC.Block)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (pointer : CC.Mem.load CC.Mptr m entry 608 = some (.Vptr stack 0)) :
    CC.doStep world (.State helper header k e le m) =
      some (CC.E0,.State helper .Sskip k e (le.set Arm64Program._t'235 (.Vptr stack 0)) m) := by
  simp only [header,CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,hentry,CC.lvalOfField,layout.1,layout.2,
    CC.typeof,CC.tptr,CC.tulong,CC.tuchar,CC.tvolatile,CC.typeconv,CC.removeAttributes,CC.tattr,
    CC.doDerefLoc,CC.accessMode,CC.Mptr,CC.Archi.ptr64,CC.Integers.Ptrofs.add,CC.Integers.MI.add,
    CC.Integers.Ptrofs.unsigned,CC.Integers.MI.unsigned,CC.Mem.loadv,ite_true,BitVec.zero_add]
  have fieldOffset : (((((0 : CC.Integers.Ptrofs) + CC.Integers.Ptrofs.repr 608).toNat) : Nat) : Int) = 608 := by decide +kernel
  rw [fieldOffset]
  rw [show CC.Mem.load .Mint64 m entry 608 = some (.Vptr stack 0) from pointer]

private theorem narrow_byte (value : BitVec 64) :
    value.setWidth 32 &&& (255#32) &&& (255#32) = (value.setWidth 8).setWidth 32 := by
  apply BitVec.eq_of_getLsbD_eq
  intro i
  have mask : (255#32).getLsbD i = (decide (i < 32) && decide (i < 8)) := by
    change ((BitVec.allOnes 8).setWidth 32).getLsbD i = _
    rw [BitVec.getLsbD_setWidth,BitVec.getLsbD_allOnes]
  by_cases small : i < 8
  · have wide : i < 32 := by omega
    simp only [BitVec.getLsbD_and,BitVec.getLsbD_setWidth,mask,small,wide,
      decide_true,Bool.true_and,Bool.and_true]
    trivial
  · simp only [BitVec.getLsbD_and,BitVec.getLsbD_setWidth,mask,small,decide_false,
      Bool.and_false,Bool.false_and]
    exact fun _ => True.intro

private theorem index_cast : ∀ i : Fin 160,
    CC.Integers.Ptrofs.of_intu (Arm64MemsetReleaseLoop.index i) = CC.Integers.Ptrofs.repr (i.val : Int) := by decide +kernel
private theorem index_unsigned : ∀ i : Fin 160,
    CC.Integers.Ptrofs.unsigned (CC.Integers.Ptrofs.repr (i.val : Int)) = (i.val : Int) := by decide +kernel
private theorem pointer_data : ∀ i : Fin 160,
    (0 : CC.Integers.Ptrofs) + (1 : CC.Integers.Ptrofs) * CC.Integers.Ptrofs.repr (i.val : Int) =
      BitVec.ofNat CC.Archi.ptrWordsize i.val := by decide +kernel

private theorem arguments_eval (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (stack : CC.Block)
    (i : Fin 160) (value : BitVec 64)
    (counter : le.get Arm64Program.___a64_release_i = some (.Vint (Arm64MemsetReleaseLoop.index i)))
    (word : le.get Arm64Program._t'1 = some (.Vlong value)) :
    CC.doEvalExprlist world e (le.set Arm64Program._t'235 (.Vptr stack 0)) m arguments
      [CC.tptr (CC.tvolatile CC.tuchar),CC.tvolatile CC.tuchar] =
      some [.Vptr stack (CC.Integers.Ptrofs.repr (i.val : Int)),.Vint ((value.setWidth 8).setWidth 32)] := by
  have hi : (le.set Arm64Program._t'235 (.Vptr stack 0)).get Arm64Program.___a64_release_i = some (.Vint (Arm64MemsetReleaseLoop.index i)) := by
    simpa +decide only [CC.PTree.gso] using counter
  have hv : (le.set Arm64Program._t'235 (.Vptr stack 0)).get Arm64Program._t'1 = some (.Vlong value) := by
    simpa +decide only [CC.PTree.gso] using word
  simp +decide only [arguments,CC.doEvalExprlist,CC.doEvalExpr,CC.doEvalLvalue,hi,hv,CC.PTree.gss,
    CC.Cop.semBinaryOperation,CC.Cop.semAdd,CC.Cop.classifyAdd,CC.Cop.semAddPtrInt,CC.Cop.ptrofsOfInt,
    CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntInt,CC.typeof,CC.typeconv,CC.removeAttributes,
    CC.tattr,CC.tptr,CC.tvolatile,CC.tuchar,CC.tuint,CC.tulong,CC.sizeof,CC.alignof,CC.Archi.ptr64,
    CC.Integers.Ptrofs.add,CC.Integers.Ptrofs.mul,CC.Integers.Ptrofs.repr,index_cast,
    CC.Integers.MI.add,CC.Integers.MI.mul,CC.Integers.Int.repr,CC.Integers.MI.repr,
    CC.Integers.Int64.unsigned,CC.Integers.MI.unsigned,CC.Integers.Int.zero_ext,CC.Integers.MI.zero_ext,
    BitVec.ofInt_natCast,BitVec.zero_add,BitVec.one_mul,ite_true,ite_false]
  change some [CC.Val.Vptr stack ((0 : CC.Integers.Ptrofs) + (1 : CC.Integers.Ptrofs) * CC.Integers.Ptrofs.repr (i.val : Int)),
    CC.Val.Vint (value.setWidth 32 &&& (255#32) &&& (255#32))] = _
  rw [pointer_data,narrow_byte]

/-- Execute this source's own pointer read and actual volatile byte store. -/
theorem write (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (entry stack : CC.Block)
    (i : Fin 160) (value : BitVec 64)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (counter : le.get Arm64Program.___a64_release_i = some (.Vint (Arm64MemsetReleaseLoop.index i)))
    (word : le.get Arm64Program._t'1 = some (.Vlong value))
    (pointer : CC.Mem.load CC.Mptr m entry 608 = some (.Vptr stack 0))
    (range : CC.Mem.rangePerm m stack 0 160 .Cur .Writable = true) :
    ∃ after, CC.Star (CC.Step2 world) (.State helper statement k e le m) CC.E0
        (.State helper .Sskip k e (le.set Arm64Program._t'235 (.Vptr stack 0)) after) ∧
      CC.Mem.store .Mint8unsigned m stack (i.val : Int) (.Vint ((value.setWidth 8).setWidth 32)) = some after ∧
      CC.Mem.load .Mint8unsigned after stack (i.val : Int) = some (.Vint ((value.setWidth 8).setWidth 32)) ∧
      after.access = m.access ∧ after.nextblock = m.nextblock := by
  have valid : CC.Mem.validAccess m .Mint8unsigned stack (i.val : Int) .Writable = true := by
    simp only [CC.Mem.validAccess,Bool.and_eq_true,decide_eq_true_eq]
    constructor
    · apply CC.Mem.rangePerm_intro
      intro offset low high
      exact CC.Mem.rangePerm_perm m stack 0 160 .Cur .Writable range offset (by omega)
        (by have bound := i.isLt; change offset < (i.val : Int) + 1 at high; omega)
    · simp [CC.alignChunk]
  obtain ⟨after,stored⟩ : ∃ after, CC.Mem.store .Mint8unsigned m stack (i.val : Int)
      (.Vint ((value.setWidth 8).setWidth 32)) = some after := by
    simp only [CC.Mem.store,valid,ite_true]
    exact ⟨_,rfl⟩
  have entered : InternalRun world 3 (.State helper statement k e le m)
      (.State helper store k e (le.set Arm64Program._t'235 (.Vptr stack 0)) m) := by
    rw [statement_source]
    refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
    refine .step trivial (CC.doStep_sound _ _ _ _ (header_step e le m _ entry stack hentry pointer)) ?_
    exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  have builtin : CC.Step2 world (.State helper store k e (le.set Arm64Program._t'235 (.Vptr stack 0)) m)
      CC.E0 (.State helper .Sskip k e (le.set Arm64Program._t'235 (.Vptr stack 0)) after) := by
    rw [store_source]
    apply CC.Step.builtin (vargs := [.Vptr stack (CC.Integers.Ptrofs.repr (i.val : Int)),.Vint ((value.setWidth 8).setWidth 32)]) (vres := .Vundef)
    · exact CC.doEvalExprlist_sound _ _ _ _ _ _ _ (arguments_eval e le m stack i value counter word)
    · exact CC.VolatileStoreSem.intro _ _ _ _ _ _ _
        (.nonvol _ _ _ _ _ _ (Arm64MemsetByteWrite.nonvolatile stack) (by simpa only [index_unsigned i] using stored))
  have one : CC.Star (CC.Step2 world) (.State helper store k e (le.set Arm64Program._t'235 (.Vptr stack 0)) m)
      CC.E0 (.State helper .Sskip k e (le.set Arm64Program._t'235 (.Vptr stack 0)) after) :=
    .step _ _ _ _ _ _ builtin (.refl _) rfl
  refine ⟨after,?_,stored,?_,CC.Mem.store_access stored,CC.Mem.store_nextblock stored⟩
  · simpa only [CC.E0,CC.Eapp,List.nil_append] using star_trans entered.sound one
  · have mask (byte : BitVec 8) : byte.setWidth 32 &&& (255#32) = byte.setWidth 32 := by
      change byte.setWidth 32 &&& (BitVec.allOnes 8).setWidth 32 = byte.setWidth 32
      rw [← BitVec.setWidth_and,BitVec.and_allOnes]
    have normalized : CC.Val.loadResult .Mint8unsigned (.Vint ((value.setWidth 8).setWidth 32)) =
        .Vint ((value.setWidth 8).setWidth 32) := by
      change CC.Val.Vint ((value.setWidth 8).setWidth 32 &&& (255#32)) = _
      rw [mask]
    simpa only [normalized] using CC.Mem.load_store_same stored

theorem inputs (le : CC.TempEnv) (stack : CC.Block) (value : BitVec 64) :
    (temps le stack value).get Arm64Program._entry = le.get Arm64Program._entry ∧
    (temps le stack value).get Arm64Program.___a64_release_i = le.get Arm64Program.___a64_release_i ∧
    (temps le stack value).get Arm64Program.___a64_release_old = le.get Arm64Program.___a64_release_old ∧
    (temps le stack value).get Arm64Program.___a64_release_new = le.get Arm64Program.___a64_release_new := by
  refine ⟨?_,?_,?_,?_⟩ <;> simp +decide only [temps,returnedTemps,CC.PTree.gso]

/-- Follow the real provider's outcome and returned memory, then perform the
actual selected byte write with permissions on that supplied memory. -/
theorem execute {initial before supplied : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (view : Arm64MemsetHeaderView.View initial supplied entry)
    (resources : Arm64ProgramEntryResources.Resources initial supplied entry)
    (le : CC.TempEnv) (k : CC.Cont) (i : Fin 64) (value : BitVec 64) (trace : CC.Trace)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (counter : le.get Arm64Program.___a64_release_i = some (.Vint (BitVec.ofNat 32 i.val)))
    (provider : CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv world.genv_genv)
      [.Vint (6#32)] before trace (.Vlong value) supplied) :
    ∃ after, CC.Star (CC.Step2 world) (.State helper Arm64MemsetReleaseLoop.selected k CC.emptyEnv le before)
        trace (.State helper .Sskip k CC.emptyEnv (temps le view.stack.block value) after) ∧
      CC.Mem.store .Mint8unsigned supplied view.stack.block (i.val : Int) (.Vint ((value.setWidth 8).setWidth 32)) = some after ∧
      CC.Mem.load .Mint8unsigned after view.stack.block (i.val : Int) = some (.Vint ((value.setWidth 8).setWidth 32)) ∧
      FrameBelow initial.nextblock supplied after ∧ after.access = supplied.access ∧ after.nextblock = supplied.nextblock := by
  have prefixRun := ready le before k
  have callRun : CC.Star (CC.Step2 world)
      (.Callstate Arm64OriginCache.inputFunction [.Vint (6#32)] (continuation le k) before)
      trace (.Returnstate (.Vlong value) (continuation le k) supplied) :=
    .step _ _ _ _ _ _ (.external_function _ _ _ _ _ _ _ _ _ _ provider) (.refl _)
      (by simp only [CC.E0,CC.Eapp,List.append_nil])
  have returned : InternalRun world 2 (.Returnstate (.Vlong value) (continuation le k) supplied)
      (.State helper statement k CC.emptyEnv (returnedTemps le value) supplied) := by
    exact .step trivial (CC.doStep_sound _ _ _ _ rfl)
      (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _))
  let j : Fin 160 := ⟨i.val,Nat.lt_trans i.isLt (by decide)⟩
  obtain ⟨after,run,stored,read,access,next⟩ := write CC.emptyEnv (returnedTemps le value) supplied k entry.block view.stack.block j value
    (by simpa +decide only [returnedTemps,CC.PTree.gso] using hentry)
    (by simpa +decide only [Arm64MemsetReleaseLoop.index,returnedTemps,CC.PTree.gso] using counter)
    (CC.PTree.gss ..) view.stackPointer (Arm64MemsetStoreExecution.ranges view resources).2
  have live := (allocated_local_storage (CC.doAllocVariables_sound _ _ _ _ _ _
    (Prod.eta (Arm64Producer.allocation initial)).symm)).1 _ _ view.stack.binding
  refine ⟨after,?_,stored,read,FrameBelow.store live.1 stored,access,next⟩
  simpa only [temps,CC.E0,CC.Eapp,List.nil_append,List.append_nil] using
    star_trans prefixRun.sound (star_trans callRun (star_trans returned.sound run))

section SingleStore
open Arm64Producer Arm64ProducerRegisterStorage
variable {initial before after : CC.Mem} {entry : HeaderLocal initial}
    (view : Arm64MemsetHeaderView.View initial before entry) (i : Fin 64) (value : BitVec 64)
    (stored : CC.Mem.store .Mint8unsigned before view.stack.block (i.val : Int)
      (.Vint ((value.setWidth 8).setWidth 32)) = some after)
include view i value stored

private theorem other (id : CC.Ident) (ty : CC.Ty) (block : CC.Block)
    (binding : (allocation initial).1.get id = some (block,ty))
    (notStack : id ≠ tailLocalName 0) (chunk : CC.Chunk) (offset : Int) :
    CC.Mem.load chunk after block offset = CC.Mem.load chunk before block offset := by
  have separate := (allocated_local_storage (CC.doAllocVariables_sound _ _ _ _ _ _
    (Prod.eta (allocation initial)).symm)).2
  exact CC.Mem.load_store_other stored chunk block offset (.inl
    (separate _ _ _ _ binding view.stack.binding notStack))

omit view i value stored
private theorem tables_other : ∀ tags, tableName tags ≠ tailLocalName 0 := by decide +kernel
private theorem cells_other : ∀ tags (j : Fin 31), tableCellName tags j ≠ tailLocalName 0 := by decide +kernel

/-- The single real byte store preserves current architectural storage and
rights through actual producer-allocation binding separation. -/
def storage_after (old : Storage initial before entry) : Storage initial after entry where
  tables := old.tables
  roots := fun tags => (other view i value stored _ _ _ entry.binding (by decide +kernel) CC.Mptr _).trans (old.roots tags)
  slots := fun tags j => (other view i value stored _ _ _ (old.tables tags).binding (tables_other tags) CC.Mptr _).trans (old.slots tags j)
  writable := fun tags j => (CC.Mem.validAccess_store_eq stored (cellChunk tags) ((old.tables tags).cellBlock j) 0 .Writable).trans (old.writable tags j)
  sp := old.sp
  spPointer := (other view i value stored _ _ _ entry.binding (by decide +kernel) CC.Mptr 40).trans old.spPointer
  spValue := old.spValue
  spRead := (other view i value stored _ _ _ old.sp.binding (by decide +kernel) .Mint64 0).trans old.spRead
  flags := old.flags
  flagPointers := fun flag => (other view i value stored _ _ _ entry.binding (by decide +kernel) CC.Mptr _).trans (old.flagPointers flag)
  flagWritable := fun flag => (CC.Mem.validAccess_store_eq stored .Mint8unsigned (old.flags flag).block 0 .Writable).trans (old.flagWritable flag)
  vectors := old.vectors
  vectorPointers := fun high j => (other view i value stored _ _ _ entry.binding (by decide +kernel) CC.Mptr _).trans (old.vectorPointers high j)
  vectorWritable := (CC.Mem.rangePerm_congr (m1 := after) (m2 := before)
    (fun offset => by simp only [CC.Mem.perm,CC.Mem.store_access stored])).trans old.vectorWritable

include view i value stored

theorem resources_after (old : Arm64ProgramEntryResources.Resources initial before entry) :
    Arm64ProgramEntryResources.Resources initial after entry :=
  Arm64MemsetIterationResources.resources old
    (fun chunk offset => other view i value stored _ _ _ entry.binding (by decide +kernel) chunk offset)
    (fun block _ => congrArg (CC.PMap.get block) (CC.Mem.store_access stored))

def view_after : Arm64MemsetHeaderView.View initial after entry where
  stack := view.stack
  tags := view.tags
  stackPointer := (other view i value stored _ _ _ entry.binding (by decide +kernel) CC.Mptr 608).trans view.stackPointer
  tagPointer := (other view i value stored _ _ _ entry.binding (by decide +kernel) CC.Mptr 648).trans view.tagPointer
  capacity := (other view i value stored _ _ _ entry.binding (by decide +kernel) .Mint32 656).trans view.capacity
  bias := (other view i value stored _ _ _ entry.binding (by decide +kernel) .Mint64 672).trans view.bias

theorem gpr_after (old : Storage initial before entry) (j : Fin 31) :
    Arm64EntryMemory.gpr after.nextblock after (.Vptr entry.block 0) j.val =
      Arm64EntryMemory.gpr before.nextblock before (.Vptr entry.block 0) j.val := by
  rw [Arm64RegisterWrite.storage_gpr (storage_after view i value stored old) j,Arm64RegisterWrite.storage_gpr old j]
  change (do let word ← CC.Mem.load .Mint64 after ((old.tables false).cellBlock j) 0
             let tag ← CC.Mem.load .Mint8unsigned after ((old.tables true).cellBlock j) 0
             pure (word,tag)) = _
  rw [other view i value stored _ _ _ ((old.tables false).cellBinding j) (cells_other false j) .Mint64 0,
    other view i value stored _ _ _ ((old.tables true).cellBinding j) (cells_other true j) .Mint8unsigned 0]

/-- Real disjoint-offset semantics protect every previously written data byte
64..79 and actual allocation separation protects all24 tag bytes. -/
theorem data_tags :
    (∀ j : Fin 16, CC.Mem.load .Mint8unsigned after view.stack.block
        ((Arm64MemsetStoreExecution.index j).val : Int) = CC.Mem.load .Mint8unsigned before view.stack.block
        ((Arm64MemsetStoreExecution.index j).val : Int)) ∧
    (∀ j : Fin 24, CC.Mem.load .Mint8unsigned after view.tags.block (j.val : Int) =
      CC.Mem.load .Mint8unsigned before view.tags.block (j.val : Int)) := by
  constructor
  · intro j
    apply CC.Mem.load_store_other stored
    right
    right
    have low := i.isLt
    change (i.val : Int) + 1 ≤ (64 + j.val : Nat)
    omega
  · intro j
    exact other view i value stored _ _ _ view.tags.binding (by decide +kernel) .Mint8unsigned _

end SingleStore

end KProgFormal.ClightRefinement.Arm64MemsetReleaseStore
