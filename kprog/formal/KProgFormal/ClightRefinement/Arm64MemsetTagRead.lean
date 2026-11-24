import KProgFormal.ClightRefinement.Arm64MemsetStackSetup

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemsetTagRead

open Arm64ProgramEntryAllocation (world)
open Arm64MemsetSource (handler)

private structure Parts where
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
  tagBody : CC.Stmt
  afterTag : CC.Stmt
  writeBody : CC.Stmt

private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) (arity : Nat) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor arity do
        throwError "original memset tag reader changed"
      pure actual.getAppArgs
    let outer ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64Program.s_kprog_arm64_program_memset_11)) none) ``CC.Stmt.Sifthenelse 3
    let rest ← peel outer[2]! ``CC.Stmt.Sifthenelse 3
    let normal ← peel rest[1]! ``CC.Stmt.Ssequence 2
    let inner ← peel normal[0]! ``CC.Stmt.Ssequence 2
    let rootRest ← peel inner[1]! ``CC.Stmt.Ssequence 2
    let slotRest ← peel rootRest[1]! ``CC.Stmt.Ssequence 2
    let continuation ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64MemsetStackSetup.tagCont CC.Cont.Kstop)) none) ``CC.Cont.Kseq 2
    let tagLoop ← peel continuation[1]! ``CC.Cont.Kloop1 3
    let route ← peel tagLoop[2]! ``CC.Cont.Kseq 2
    let writeLoop ← peel route[1]! ``CC.Cont.Kloop1 3
    Lean.Elab.Tactic.closeMainGoal `actual_memset_tag_reader
      (← Lean.Meta.mkAppM ``Parts.mk #[outer[2]!,rest[1]!,normal[0]!,inner[0]!,inner[1]!,
        rootRest[0]!,rootRest[1]!,slotRest[0]!,slotRest[1]!,normal[1]!,continuation[0]!,tagLoop[0]!,route[0]!,writeLoop[0]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_memset_tag_read_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

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
private def tagBody : CC.Stmt := by run_tac cachePart (← `(parts.tagBody))
def afterTag : CC.Stmt := by run_tac cachePart (← `(parts.afterTag))
private def writeBody : CC.Stmt := by run_tac cachePart (← `(parts.writeBody))
def continuation (k : CC.Cont) : CC.Cont := .Kloop1 writeBody .Sbreak (Arm64MemsetStackSetup.continuation k)
private theorem cont_source (k : CC.Cont) : Arm64MemsetStackSetup.tagCont k =
    .Kseq tagCopy (.Kloop1 tagBody .Sbreak (.Kseq afterTag (continuation k))) := rfl

private theorem normal_source : normal = .Ssequence inner copy := rfl
private theorem inner_source : inner = .Ssequence root rootRest := rfl
private theorem rootRest_source : rootRest = .Ssequence slot slotRest := rfl
private theorem slotRest_source : slotRest = .Ssequence byte widen := rfl

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
      some (CC.E0,.State handler .Sskip k e (le.set Arm64Program._t'174 (.Vptr table 0)) m) := by
  simp only [root,CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,hentry,CC.lvalOfField,layout.1,layout.2,
    CC.typeof,CC.tptr,CC.tuchar,CC.typeconv,CC.removeAttributes,CC.tattr,
    CC.doDerefLoc,CC.accessMode,CC.Mptr,CC.Archi.ptr64,CC.Integers.Ptrofs.add,CC.Integers.MI.add,
    CC.Integers.Ptrofs.unsigned,CC.Integers.MI.unsigned,CC.Mem.loadv,ite_true]
  have offset : (((((0 : CC.Integers.Ptrofs) + CC.Integers.Ptrofs.repr 8).toNat) : Nat) : Int) = 8 := by decide +kernel
  rw [offset,show CC.Mem.load .Mint64 m entry 8 = some (.Vptr table 0) from read]

private theorem slot_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (table cell : CC.Block)
    (hroot : le.get Arm64Program._t'174 = some (.Vptr table 0))
    (hreg : le.get Arm64Program.___a64_l_reg__2 = some (.Vlong 0))
    (read : CC.Mem.load CC.Mptr m table 0 = some (.Vptr cell 0)) :
    CC.doStep world (.State handler slot k e le m) =
      some (CC.E0,.State handler .Sskip k e (le.set Arm64Program._t'175 (.Vptr cell 0)) m) := by
  simp only [slot,CC.doStep,CC.doEvalExpr,hroot,hreg,CC.doEvalLvalue,
    CC.Cop.semBinaryOperation,CC.Cop.semAdd,CC.Cop.classifyAdd,CC.Cop.semAddPtrInt,CC.Cop.ptrofsOfInt,
    CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntInt,CC.typeof,CC.typeconv,CC.removeAttributes,CC.tattr,
    CC.tptr,CC.tuchar,CC.tulong,CC.tint,CC.Archi.ptr64,CC.sizeof,CC.alignof,
    CC.Integers.Int.repr,CC.Integers.Int64.unsigned,CC.Integers.Int.zero_ext,CC.Integers.MI.zero_ext,
    CC.Integers.MI.repr,CC.Integers.MI.unsigned,CC.Integers.Int.signed,CC.Integers.MI.signed,
    CC.Integers.Ptrofs.add,CC.Integers.Ptrofs.mul,CC.Integers.Ptrofs.repr,CC.Integers.MI.add,CC.Integers.MI.mul,
    CC.doDerefLoc,CC.accessMode,CC.Mptr,CC.Mem.loadv,CC.Integers.Ptrofs.unsigned,ite_true,ite_false]
  change (match CC.Mem.load .Mint64 m table 0 with
    | some value => some (CC.E0,CC.State.State handler .Sskip k e (le.set Arm64Program._t'175 value) m)
    | none => none) = _
  rw [show CC.Mem.load .Mint64 m table 0 = some (.Vptr cell 0) from read]

private theorem byte_step (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (cell : CC.Block) (tag : BitVec 8)
    (hptr : le.get Arm64Program._t'175 = some (.Vptr cell 0))
    (read : CC.Mem.load .Mint8unsigned m cell 0 = some (.Vint (tag.setWidth 32))) :
    CC.doStep world (.State handler byte k e le m) =
      some (CC.E0,.State handler .Sskip k e (le.set Arm64Program._t'176 (.Vint (tag.setWidth 32))) m) := by
  simp only [byte,CC.doStep,CC.doEvalExpr,CC.doEvalLvalue,hptr,CC.doDerefLoc,CC.accessMode,
    CC.typeof,CC.tuchar,CC.tattr,CC.Mem.loadv,CC.Integers.Ptrofs.unsigned,CC.Integers.MI.unsigned]
  change (match CC.Mem.load .Mint8unsigned m cell 0 with
    | some value => some (CC.E0,CC.State.State handler .Sskip k e (le.set Arm64Program._t'176 value) m)
    | none => none) = _
  rw [read]

def temps (le : CC.TempEnv) (table cell : CC.Block) (tag : BitVec 8) : CC.TempEnv :=
  (((((le.set Arm64Program._t'174 (.Vptr table 0)).set Arm64Program._t'175 (.Vptr cell 0)).set
    Arm64Program._t'176 (.Vint (tag.setWidth 32))).set Arm64Program._t'17 (.Vint (tag.setWidth 32))).set
    Arm64Program._t'17 (.Vint (tag.setWidth 32)))

/-- Execute both original R0 guards, the actual table/slot/byte loads and
both original casts in fifteen transitions, retaining all source state. -/
theorem read (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (entry table cell : CC.Block) (tag : BitVec 8)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (hreg : le.get Arm64Program.___a64_l_reg__2 = some (.Vlong 0))
    (header : CC.Mem.load CC.Mptr m entry 8 = some (.Vptr table 0))
    (pointer : CC.Mem.load CC.Mptr m table 0 = some (.Vptr cell 0))
    (value : CC.Mem.load .Mint8unsigned m cell 0 = some (.Vint (tag.setWidth 32))) :
    InternalRun world 15 (.State handler Arm64Program.s_kprog_arm64_program_memset_11 k e le m)
      (.State handler .Sskip k e (temps le table cell tag) m) := by
  let l1 := le.set Arm64Program._t'174 (.Vptr table 0)
  let l2 := l1.set Arm64Program._t'175 (.Vptr cell 0)
  let l3 := l2.set Arm64Program._t'176 (.Vint (tag.setWidth 32))
  let l4 := l3.set Arm64Program._t'17 (.Vint (tag.setWidth 32))
  have rootReg : l1.get Arm64Program.___a64_l_reg__2 = some (.Vlong 0) := by
    have other : Arm64Program._t'174 ≠ Arm64Program.___a64_l_reg__2 := by decide +kernel
    simpa only [l1,CC.PTree.gso _ _ _ _ other] using hreg
  refine .step (mid := .State handler rest k e le m) trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [Arm64Program.s_kprog_arm64_program_memset_11,CC.doStep,CC.doEvalExpr,hreg]
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
    (hreg : le.get Arm64Program.___a64_l_reg__2 = some (.Vlong 0))
    (observed : Arm64EntryMemory.gpr m.nextblock m (.Vptr entry.block 0) 0 = some (raw,.Vint (tag.setWidth 32))) :
    InternalRun world 15 (.State handler Arm64Program.s_kprog_arm64_program_memset_11 k e le m)
      (.State handler .Sskip k e (temps le (storage.tables true).tableBlock ((storage.tables true).cellBlock 0) tag) m) := by
  have walk := Arm64RegisterWrite.storage_gpr storage (0 : Fin 31)
  simp only [Fin.val_zero] at walk
  rw [walk] at observed
  have value : CC.Mem.load .Mint8unsigned m ((storage.tables true).cellBlock 0) 0 = some (.Vint (tag.setWidth 32)) := by
    cases wordRead : CC.Mem.load .Mint64 m ((storage.tables false).cellBlock 0) 0 with
    | none =>
      simp only [wordRead,bind,Option.bind_none] at observed
      cases observed
    | some word =>
      cases tagRead : CC.Mem.load .Mint8unsigned m ((storage.tables true).cellBlock 0) 0 with
      | none =>
        simp only [wordRead,tagRead,bind,Option.bind_some,Option.bind_none] at observed
        cases observed
      | some value =>
        have equal : (word,value) = (raw,.Vint (tag.setWidth 32)) := by
          simpa only [wordRead,tagRead,bind,Option.bind_some,pure,Option.some.injEq] using observed
        exact congrArg some (congrArg Prod.snd equal)
  exact read e le m k entry.block (storage.tables true).tableBlock ((storage.tables true).cellBlock 0) tag
    hentry hreg (storage.roots true)
    (by
      have actual := storage.slots true (0 : Fin 31)
      have offset : 8 * ((0 : Fin 31).val : Int) = 0 := by decide +kernel
      rw [offset] at actual
      exact actual) value


def finalTemps (le : CC.TempEnv) (table cell : CC.Block) (tag : BitVec 8) : CC.TempEnv :=
  (temps le table cell tag).set Arm64Program.___a64_mwr_tag (.Vint (tag.setWidth 32))

private theorem tag_mask (tag : BitVec 8) : tag.setWidth 32 &&& (255#32) = tag.setWidth 32 := by
  change tag.setWidth 32 &&& (BitVec.allOnes 8).setWidth 32 = tag.setWidth 32
  rw [← BitVec.setWidth_and,BitVec.and_allOnes]

private theorem leave (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (table cell : CC.Block) (tag : BitVec 8) :
    InternalRun world 5 (.State handler .Sskip (Arm64MemsetStackSetup.tagCont k) e (temps le table cell tag) m)
      (.State handler afterTag (continuation k) e (finalTemps le table cell tag) m) := by
  have small : ¬ (8 ≥ 32) := by decide
  have mask : BitVec.allOnes 32 >>> (32-8) = (255#32) := by decide +kernel
  rw [cont_source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  refine .step (mid := .State handler .Sskip (.Kloop1 tagBody .Sbreak (.Kseq afterTag (continuation k))) e
    (finalTemps le table cell tag) m) trivial (CC.doStep_sound _ _ _ _ ?_) ?_
  · simp only [tagCopy,CC.doStep,CC.doEvalExpr,temps,CC.PTree.gss,CC.Cop.semCast,CC.Cop.classifyCast,
      CC.Cop.castIntInt,CC.typeof,CC.tuchar,CC.tuint,CC.typeconv,CC.removeAttributes,CC.tattr,
      CC.Integers.Int.zero_ext,CC.Integers.MI.zero_ext,small,ite_false,mask,tag_mask]
    rfl
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl)
    (.step trivial (CC.doStep_sound _ _ _ _ rfl)
      (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)))

/-- The complete original tag read, assignment and both loop exits retain
the actual source routing continuation and every memory observation. -/
theorem complete {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry)
    (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (raw : CC.Val) (tag : BitVec 8)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (hreg : le.get Arm64Program.___a64_l_reg__2 = some (.Vlong 0))
    (observed : Arm64EntryMemory.gpr m.nextblock m (.Vptr entry.block 0) 0 = some (raw,.Vint (tag.setWidth 32))) :
    InternalRun world 20 (.State handler Arm64Program.s_kprog_arm64_program_memset_11
      (Arm64MemsetStackSetup.tagCont k) e le m)
      (.State handler afterTag (continuation k) e
        (finalTemps le (storage.tables true).tableBlock ((storage.tables true).cellBlock 0) tag) m) :=
  (of_storage storage e le (Arm64MemsetStackSetup.tagCont k) raw tag hentry hreg observed).trans
    (leave e le m k (storage.tables true).tableBlock ((storage.tables true).cellBlock 0) tag)

/-- The actual pointer/MOV/allocation effects supply every original tag load.
All eight memset locals, the complete 276-step prefix and original R0/SP views
are retained together with the same canonical producer storage. -/
theorem original {initial before pointerWritten markWritten markAfter constantWritten constantAfter : CC.Mem}
    {entry : Arm64Producer.HeaderLocal initial}
    {storage : Arm64ProducerRegisterStorage.Storage initial before entry}
    {raw : BitVec 64} {addresses : Arm64Registers.PointerOrigins}
    {origins : Reference.Provenance.AArch64.Origins} {prior next : Reference.AArch64.State}
    {priorK nextK : CC.Cont} (mark : BitVec 32)
    (pointer : Arm64PointerWrite.Result storage 0 raw (4#8) pointerWritten)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ pointerWritten.nextblock.toNat)
    (first : Arm64MovImmediate.OrdinaryCall.Result pointer.storage 1 (mark.setWidth 64)
      addresses origins prior priorK markWritten markAfter)
    (second : Arm64MovImmediate.OrdinaryCall.Result (first.storage bound) 2 (16#64)
      addresses origins next nextK constantWritten constantAfter) (k : CC.Cont) :
    ∃ current : Arm64ProducerRegisterStorage.Storage initial (Arm64MemsetSource.allocation constantAfter).2 entry,
      InternalRun world 276 (.Callstate (.Internal handler) [.Vptr entry.block 0] k constantAfter)
        (.State handler afterTag
          (continuation (Arm64MemsetLoop.writeCont (.Kseq Arm64MemsetLoop.effects (Arm64MemsetSource.continuation k))))
          (Arm64MemsetSource.allocation constantAfter).1
          (finalTemps (Arm64MemsetStackSetup.temps
            (Arm64MemsetLoop.initializedTemps entry.block (mark.setWidth 64) (16#64)) 0)
            (current.tables true).tableBlock ((current.tables true).cellBlock 0) (4#8))
          (Arm64MemsetSource.allocation constantAfter).2) ∧
      Arm64EntryMemory.gpr constantAfter.nextblock (Arm64MemsetSource.allocation constantAfter).2
        (.Vptr entry.block 0) 0 = some (.Vlong raw,.Vint ((4#8).setWidth 32)) ∧
      CC.Mem.load CC.Mptr (Arm64MemsetSource.allocation constantAfter).2 entry.block 40 = some (.Vptr storage.sp.block 0) ∧
      CC.Mem.load .Mint64 (Arm64MemsetSource.allocation constantAfter).2 storage.sp.block 0 = some (.Vlong storage.spValue) := by
  have secondBound := Arm64MemsetInputs.bound_after first bound
  have finalBound := Arm64MemsetInputs.bound_after second secondBound
  let current := (second.storage secondBound).frame (Arm64MemsetSource.entry_frame constantAfter)
  have prefixRun := Arm64MemsetStackSetup.original mark pointer bound first second k
  have same := Arm64RegisterStorageFrontier.gpr_eq current constantAfter.nextblock finalBound (0 : Fin 31)
  simp only [Fin.val_zero] at same
  have observed := same.symm.trans prefixRun.2.1
  let le := Arm64MemsetLoop.initializedTemps entry.block (mark.setWidth 64) (16#64)
  have selected := Arm64MemsetStackSetup.selection le (0#64)
  have entryRead : le.get Arm64Program._entry = some (.Vptr entry.block 0) := by
    have other0 : Arm64Program.___a64_lib_i ≠ Arm64Program._entry := by decide +kernel
    have other1 : Arm64Program.___a64_lib_len ≠ Arm64Program._entry := by decide +kernel
    have other2 : Arm64Program._t'2 ≠ Arm64Program._entry := by decide +kernel
    have other3 : Arm64Program.___a64_lib_byte ≠ Arm64Program._entry := by decide +kernel
    have other4 : Arm64Program._t'1 ≠ Arm64Program._entry := by decide +kernel
    simp only [le,Arm64MemsetLoop.initializedTemps,Arm64MemsetSource.readTemps,Arm64MemsetSource.byteTemps,
      Arm64MemsetSource.initialTemps,CC.PTree.gso _ _ _ _ other0,CC.PTree.gso _ _ _ _ other1,
      CC.PTree.gso _ _ _ _ other2,CC.PTree.gso _ _ _ _ other3,CC.PTree.gso _ _ _ _ other4,CC.PTree.gss]
  have run := complete current (Arm64MemsetSource.allocation constantAfter).1
    (Arm64MemsetStackSetup.temps le 0)
    (Arm64MemsetLoop.writeCont (.Kseq Arm64MemsetLoop.effects (Arm64MemsetSource.continuation k)))
    (.Vlong raw) (4#8) (selected.1.trans entryRead) selected.2 observed
  exact ⟨current,prefixRun.1.trans run,prefixRun.2⟩

end KProgFormal.ClightRefinement.Arm64MemsetTagRead
