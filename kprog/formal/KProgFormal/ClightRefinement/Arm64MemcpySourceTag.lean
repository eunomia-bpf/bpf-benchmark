import KProgFormal.ClightRefinement.Arm64MemcpySource

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpySourceTag

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpySource (handler)

private structure Parts where
  tagLoop : CC.Stmt
  tagBody : CC.Stmt
  regSet : CC.Stmt
  tagRest : CC.Stmt
  read : CC.Stmt
  rest : CC.Stmt
  normal : CC.Stmt
  inner : CC.Stmt
  root : CC.Stmt
  rootRest : CC.Stmt
  slot : CC.Stmt
  slotRest : CC.Stmt
  byte : CC.Stmt
  widen : CC.Stmt
  copy : CC.Stmt
  tagCopy : CC.Stmt
  afterTag : CC.Stmt

private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor arity do throwError "original memcpy source tag path changed"
      pure actual.getAppArgs
    let outer ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64MemcpySource.afterLength)) none) ``CC.Stmt.Ssequence 2
    let loop ← peel outer[0]! ``CC.Stmt.Sloop 2
    let body ← peel loop[0]! ``CC.Stmt.Ssequence 2
    let tagRest ← peel body[1]! ``CC.Stmt.Ssequence 2
    let guards ← peel tagRest[0]! ``CC.Stmt.Sifthenelse 3
    let rest ← peel guards[2]! ``CC.Stmt.Sifthenelse 3
    let normal ← peel rest[1]! ``CC.Stmt.Ssequence 2
    let inner ← peel normal[0]! ``CC.Stmt.Ssequence 2
    let rootRest ← peel inner[1]! ``CC.Stmt.Ssequence 2
    let slotRest ← peel rootRest[1]! ``CC.Stmt.Ssequence 2
    Lean.Elab.Tactic.closeMainGoal `actual_memcpy_tag_parts
      (← Lean.Meta.mkAppM ``Parts.mk #[outer[0]!,loop[0]!,body[0]!,body[1]!,tagRest[0]!,guards[2]!,rest[1]!,
        normal[0]!,inner[0]!,inner[1]!,rootRest[0]!,rootRest[1]!,slotRest[0]!,slotRest[1]!,normal[1]!,tagRest[1]!,outer[1]!])
private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_memcpy_tag_part (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))
private def tagLoop : CC.Stmt := by run_tac cachePart (← `(parts.tagLoop))
private def tagBody : CC.Stmt := by run_tac cachePart (← `(parts.tagBody))
private def regSet : CC.Stmt := by run_tac cachePart (← `(parts.regSet))
private def tagRest : CC.Stmt := by run_tac cachePart (← `(parts.tagRest))
private def rest : CC.Stmt := by run_tac cachePart (← `(parts.rest))
private def normal : CC.Stmt := by run_tac cachePart (← `(parts.normal))
private def inner : CC.Stmt := by run_tac cachePart (← `(parts.inner))
private def root : CC.Stmt := by run_tac cachePart (← `(parts.root))
private def rootRest : CC.Stmt := by run_tac cachePart (← `(parts.rootRest))
private def slot : CC.Stmt := by run_tac cachePart (← `(parts.slot))
private def slotRest : CC.Stmt := by run_tac cachePart (← `(parts.slotRest))
private def byte : CC.Stmt := by run_tac cachePart (← `(parts.byte))
private def widen : CC.Stmt := by run_tac cachePart (← `(parts.widen))
private def copy : CC.Stmt := by run_tac cachePart (← `(parts.copy))
private def tagCopy : CC.Stmt := by run_tac cachePart (← `(parts.tagCopy))
private def readStmt : CC.Stmt := by run_tac cachePart (← `(parts.read))
def afterTag : CC.Stmt := by run_tac cachePart (← `(parts.afterTag))
private theorem source : Arm64MemcpySource.afterLength = .Ssequence tagLoop afterTag := rfl
private theorem normal_source : normal = .Ssequence inner copy := rfl
private theorem inner_source : inner = .Ssequence root rootRest := rfl
private theorem rootRest_source : rootRest = .Ssequence slot slotRest := rfl
private theorem slotRest_source : slotRest = .Ssequence byte widen := rfl
private def cont (k : CC.Cont) : CC.Cont := .Kseq tagCopy (.Kloop1 tagBody .Sbreak (.Kseq afterTag k))
def selectedTemps (le : CC.TempEnv) : CC.TempEnv := le.set Arm64Program.___a64_l_reg (.Vlong 1)
private def entryComposite : CC.Composite :=
  (world.genv_cenv.get Arm64Program._kprog_arm64_entry).get (by decide +kernel)
private theorem layout :
    world.genv_cenv.get Arm64Program._kprog_arm64_entry = some entryComposite ∧
    CC.fieldOffset world.genv_cenv Arm64Program._tag_cells entryComposite.co_members = .OK (8,.Full) := by
  constructor <;> decide +kernel

private theorem root_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (entry table : CC.Block)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (read : CC.Mem.load CC.Mptr m entry 8 = some (.Vptr table 0)) :
    CC.doStep world (.State handler root k e le m) =
      some (CC.E0,.State handler .Sskip k e (le.set Arm64Program._t'202 (.Vptr table 0)) m) := by
  simp only [root,CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,hentry,CC.lvalOfField,layout.1,layout.2,
    CC.typeof,CC.tptr,CC.tuchar,CC.typeconv,CC.removeAttributes,CC.tattr,
    CC.doDerefLoc,CC.accessMode,CC.Mptr,CC.Archi.ptr64,CC.Integers.Ptrofs.add,CC.Integers.MI.add,
    CC.Integers.Ptrofs.unsigned,CC.Integers.MI.unsigned,CC.Mem.loadv,ite_true]
  have offset : (((((0 : CC.Integers.Ptrofs) + CC.Integers.Ptrofs.repr 8).toNat) : Nat) : Int) = 8 := by decide +kernel
  rw [offset,show CC.Mem.load .Mint64 m entry 8 = some (.Vptr table 0) from read]

private theorem slot_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (table cell : CC.Block)
    (hroot : le.get Arm64Program._t'202 = some (.Vptr table 0))
    (hreg : le.get Arm64Program.___a64_l_reg = some (.Vlong 1))
    (read : CC.Mem.load CC.Mptr m table 8 = some (.Vptr cell 0)) :
    CC.doStep world (.State handler slot k e le m) =
      some (CC.E0,.State handler .Sskip k e (le.set Arm64Program._t'203 (.Vptr cell 0)) m) := by
  simp only [slot,CC.doStep,CC.doEvalExpr,hroot,hreg,CC.doEvalLvalue,
    CC.Cop.semBinaryOperation,CC.Cop.semAdd,CC.Cop.classifyAdd,CC.Cop.semAddPtrInt,CC.Cop.ptrofsOfInt,
    CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntInt,CC.typeof,CC.typeconv,CC.removeAttributes,CC.tattr,
    CC.tptr,CC.tuchar,CC.tulong,CC.tint,CC.Archi.ptr64,CC.sizeof,CC.alignof,
    CC.Integers.Int.repr,CC.Integers.Int64.unsigned,CC.Integers.Int.zero_ext,CC.Integers.MI.zero_ext,
    CC.Integers.MI.repr,CC.Integers.MI.unsigned,CC.Integers.Int.signed,CC.Integers.MI.signed,
    CC.Integers.Ptrofs.add,CC.Integers.Ptrofs.mul,CC.Integers.Ptrofs.repr,CC.Integers.MI.add,CC.Integers.MI.mul,
    CC.doDerefLoc,CC.accessMode,CC.Mptr,CC.Mem.loadv,CC.Integers.Ptrofs.unsigned,ite_true,ite_false]
  change (match CC.Mem.load .Mint64 m table 8 with
    | some value => some (CC.E0,CC.State.State handler .Sskip k e (le.set Arm64Program._t'203 value) m)
    | none => none) = _
  rw [show CC.Mem.load .Mint64 m table 8 = some (.Vptr cell 0) from read]

private theorem byte_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (cell : CC.Block) (tag : BitVec 8)
    (hptr : le.get Arm64Program._t'203 = some (.Vptr cell 0))
    (read : CC.Mem.load .Mint8unsigned m cell 0 = some (.Vint (tag.setWidth 32))) :
    CC.doStep world (.State handler byte k e le m) =
      some (CC.E0,.State handler .Sskip k e (le.set Arm64Program._t'204 (.Vint (tag.setWidth 32))) m) := by
  simp only [byte,CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,hptr,CC.doDerefLoc,CC.accessMode,
    CC.typeof,CC.tuchar,CC.tattr,CC.Mem.loadv,CC.Integers.Ptrofs.unsigned,CC.Integers.MI.unsigned]
  change (match CC.Mem.load .Mint8unsigned m cell 0 with
    | some value => some (CC.E0,CC.State.State handler .Sskip k e (le.set Arm64Program._t'204 value) m)
    | none => none) = _
  rw [read]

def temps (le : CC.TempEnv) (table cell : CC.Block) (tag : BitVec 8) : CC.TempEnv :=
  (((((le.set Arm64Program._t'202 (.Vptr table 0)).set Arm64Program._t'203 (.Vptr cell 0)).set
    Arm64Program._t'204 (.Vint (tag.setWidth 32))).set Arm64Program._t'2 (.Vint (tag.setWidth 32))).set
    Arm64Program._t'2 (.Vint (tag.setWidth 32)))

/-- Execute both original R1 guards, the actual table/slot/byte loads and
both original casts in fifteen transitions, retaining all source state. -/
theorem read (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (entry table cell : CC.Block) (tag : BitVec 8)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (hreg : le.get Arm64Program.___a64_l_reg = some (.Vlong 1))
    (header : CC.Mem.load CC.Mptr m entry 8 = some (.Vptr table 0))
    (pointer : CC.Mem.load CC.Mptr m table 8 = some (.Vptr cell 0))
    (value : CC.Mem.load .Mint8unsigned m cell 0 = some (.Vint (tag.setWidth 32))) :
    InternalRun world 15 (.State handler readStmt k e le m)
      (.State handler .Sskip k e (temps le table cell tag) m) := by
  let l1 := le.set Arm64Program._t'202 (.Vptr table 0)
  let l2 := l1.set Arm64Program._t'203 (.Vptr cell 0)
  let l3 := l2.set Arm64Program._t'204 (.Vint (tag.setWidth 32))
  let l4 := l3.set Arm64Program._t'2 (.Vint (tag.setWidth 32))
  have rootReg : l1.get Arm64Program.___a64_l_reg = some (.Vlong 1) := by
    have other : Arm64Program._t'202 ≠ Arm64Program.___a64_l_reg := by decide +kernel
    simpa only [l1,CC.PTree.gso _ _ _ _ other] using hreg
  refine .step (mid := .State handler rest k e le m) trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [readStmt,CC.doStep,CC.doEvalExpr,hreg]
    rfl
  refine .step (mid := .State handler normal k e le m) trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [rest,CC.doStep,CC.doEvalExpr,hreg]
    rfl
  rw [normal_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [inner_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ (root_step e le m
    (.Kseq rootRest (.Kseq copy k)) entry table hentry header)) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [rootRest_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ (slot_step e l1 m
    (.Kseq slotRest (.Kseq copy k)) table cell (by simp only [l1,CC.PTree.gss]) rootReg pointer)) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [slotRest_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ (byte_step e l2 m (.Kseq widen (.Kseq copy k)) cell tag
    (by simp only [l2,CC.PTree.gss]) value)) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State handler .Sskip (.Kseq copy k) e l4 m) trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [widen,CC.doStep,CC.doEvalExpr,l3,CC.PTree.gss]
    rfl
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step trivial (CC.doStep_sound _ _ _ _ ?_) (.refl _)
  simp only [copy,CC.doStep,CC.doEvalExpr,l4,CC.PTree.gss]
  rfl


/-- The actual producer Storage roots and slots, and the same checked GPR
observation, supply every load of the original tag-reader statement. -/
theorem of_storage {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry)
    (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (raw : CC.Val) (tag : BitVec 8)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (hreg : le.get Arm64Program.___a64_l_reg = some (.Vlong 1))
    (observed : Arm64EntryMemory.gpr m.nextblock m (.Vptr entry.block 0) 1 = some (raw,.Vint (tag.setWidth 32))) :
    InternalRun world 15 (.State handler readStmt k e le m)
      (.State handler .Sskip k e (temps le (storage.tables true).tableBlock ((storage.tables true).cellBlock 1) tag) m) := by
  have walk := Arm64RegisterWrite.storage_gpr storage (1 : Fin 31)
  have position : (1 : Fin 31).val = 1 := rfl
  rw [position] at walk
  rw [walk] at observed
  have value : CC.Mem.load .Mint8unsigned m ((storage.tables true).cellBlock 1) 0 = some (.Vint (tag.setWidth 32)) := by
    cases wordRead : CC.Mem.load .Mint64 m ((storage.tables false).cellBlock 1) 0 with
    | none =>
      simp only [wordRead,bind,Option.bind_none] at observed
      cases observed
    | some word =>
      cases tagRead : CC.Mem.load .Mint8unsigned m ((storage.tables true).cellBlock 1) 0 with
      | none =>
        simp only [wordRead,tagRead,bind,Option.bind_some,Option.bind_none] at observed
        cases observed
      | some value =>
        have equal : (word,value) = (raw,.Vint (tag.setWidth 32)) := by
          simpa only [wordRead,tagRead,bind,Option.bind_some,pure,Option.some.injEq] using observed
        exact congrArg some (congrArg Prod.snd equal)
  exact read e le m k entry.block (storage.tables true).tableBlock ((storage.tables true).cellBlock 1) tag
    hentry hreg (storage.roots true)
    (by
      have actual := storage.slots true (1 : Fin 31)
      have offset : 8 * ((1 : Fin 31).val : Int) = 8 := by decide +kernel
      rw [offset] at actual
      exact actual) value


def finalTemps (le : CC.TempEnv) (table cell : CC.Block) (tag : BitVec 8) : CC.TempEnv :=
  (temps (selectedTemps le) table cell tag).set Arm64Program.___a64_lib_src_tag (.Vint (tag.setWidth 32))
private theorem tag_mask (tag : BitVec 8) : tag.setWidth 32 &&& (255#32) = tag.setWidth 32 := by
  change tag.setWidth 32 &&& (BitVec.allOnes 8).setWidth 32 = tag.setWidth 32
  rw [← BitVec.setWidth_and,BitVec.and_allOnes]

/-- The genuine tag-loop prefix sets its actual R1 selector. -/
private theorem select (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    InternalRun world 6 (.State handler Arm64MemcpySource.afterLength k e le m)
      (.State handler readStmt (cont k) e (selectedTemps le) m) := by
  have tagLoop_source : tagLoop = .Sloop tagBody .Sbreak := rfl
  have body_source : tagBody = .Ssequence regSet tagRest := rfl
  have rest_source : tagRest = .Ssequence readStmt tagCopy := rfl
  rw [source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [tagLoop_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [body_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State handler .Sskip (.Kseq tagRest (.Kloop1 tagBody .Sbreak (.Kseq afterTag k))) e
    (selectedTemps le) m) trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [regSet,CC.doStep,CC.doEvalExpr]
    rfl
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [rest_source]
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)

private theorem leave (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (table cell : CC.Block) (tag : BitVec 8) :
    InternalRun world 5 (.State handler .Sskip (cont k) e (temps (selectedTemps le) table cell tag) m)
      (.State handler afterTag k e (finalTemps le table cell tag) m) := by
  have small : ¬ (8 ≥ 32) := by decide
  have mask : BitVec.allOnes 32 >>> (32-8) = (255#32) := by decide +kernel
  unfold cont
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State handler .Sskip (.Kloop1 tagBody .Sbreak (.Kseq afterTag k)) e
    (finalTemps le table cell tag) m) trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [tagCopy,CC.doStep,CC.doEvalExpr,temps,CC.PTree.gss,CC.Cop.semCast,CC.Cop.classifyCast,
      CC.Cop.castIntInt,CC.typeof,CC.tuchar,CC.tuint,CC.typeconv,CC.removeAttributes,CC.tattr,
      CC.Integers.Int.zero_ext,CC.Integers.MI.zero_ext,small,ite_false,mask,tag_mask,finalTemps]
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.step trivial (CC.doStep_sound _ _ _ _ rfl)
    (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)))

/-- All original R1 guards, real table/slot/byte reads, casts, tag assignment
and genuine loop exits execute on the same heap, including exact tag bits. -/
theorem complete {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (raw : CC.Val) (tag : BitVec 8) (hentry : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (observed : Arm64EntryMemory.gpr m.nextblock m (.Vptr entry.block 0) 1 = some (raw,.Vint (tag.setWidth 32))) :
    InternalRun world 26 (.State handler Arm64MemcpySource.afterLength k e le m)
      (.State handler afterTag k e (finalTemps le (storage.tables true).tableBlock ((storage.tables true).cellBlock 1) tag) m) := by
  have read := of_storage storage e (selectedTemps le) (cont k) raw tag
    (by simpa +decide only [selectedTemps,CC.PTree.gso] using hentry)
    (by simp only [selectedTemps,CC.PTree.gss]) observed
  exact ((select e le m k).trans read).trans (leave e le m k _ _ tag)

private theorem kept (le : CC.TempEnv) (table cell : CC.Block) (tag : BitVec 8) (key : CC.Ident)
    (src : Arm64Program.___a64_lib_src_tag ≠ key)
    (t2 : Arm64Program._t'2 ≠ key) (t204 : Arm64Program._t'204 ≠ key)
    (t203 : Arm64Program._t'203 ≠ key) (t202 : Arm64Program._t'202 ≠ key)
    (reg : Arm64Program.___a64_l_reg ≠ key) :
    (finalTemps le table cell tag).get key = le.get key := by
  simp only [finalTemps,temps,selectedTemps,
    CC.PTree.gso _ _ _ _ src,CC.PTree.gso _ _ _ _ t2,CC.PTree.gso _ _ _ _ t204,
    CC.PTree.gso _ _ _ _ t203,CC.PTree.gso _ _ _ _ t202,CC.PTree.gso _ _ _ _ reg]

theorem observations (le : CC.TempEnv) (table cell : CC.Block) (tag : BitVec 8) :
    (finalTemps le table cell tag).get Arm64Program._entry = le.get Arm64Program._entry ∧
    (finalTemps le table cell tag).get Arm64Program.___a64_lib_len = le.get Arm64Program.___a64_lib_len ∧
    (finalTemps le table cell tag).get Arm64Program.___a64_lib_src_tag = some (.Vint (tag.setWidth 32)) := by
  refine ⟨kept le table cell tag _ (by decide) (by decide) (by decide) (by decide) (by decide) (by decide),
    kept le table cell tag _ (by decide) (by decide) (by decide) (by decide) (by decide) (by decide),?_⟩
  exact CC.PTree.gss _ _ _

end KProgFormal.ClightRefinement.Arm64MemcpySourceTag
