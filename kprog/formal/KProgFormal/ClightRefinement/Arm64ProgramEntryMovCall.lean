import KProgFormal.ClightRefinement.Arm64MovImmediateLinkedCall
import KProgFormal.ClightRefinement.Arm64ProgramEntryBodyView

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryMovCall

open Arm64Producer Arm64ProducerRegisterStorage Arm64ProducerEntryView
open Arm64ProgramEntryAllocation (world)

private structure Parts where
  mark : CC.Stmt
  call : CC.Stmt
  afterMov : CC.Stmt
  priority : CC.Stmt
  nextCall : CC.Stmt
  afterKeep : CC.Stmt

private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "actual MOV call sequence changed"
      pure actual.getAppArgs
    let outer ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64ProgramEntryBody.afterSetup)) none)
    let first ← peel outer[0]!
    let following ← peel outer[1]!
    let second ← peel following[0]!
    Lean.Elab.Tactic.closeMainGoal `actual_entry_mov_parts (← Lean.Meta.mkAppM ``Parts.mk
      #[first[0]!, first[1]!, outer[1]!, second[0]!, second[1]!, following[1]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_entry_mov_part (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private def markSet : CC.Stmt := by run_tac cachePart (← `(parts.mark))
private def firstCall : CC.Stmt := by run_tac cachePart (← `(parts.call))
def afterMov : CC.Stmt := by run_tac cachePart (← `(parts.afterMov))
private def prioritySet : CC.Stmt := by run_tac cachePart (← `(parts.priority))
def nextCall : CC.Stmt := by run_tac cachePart (← `(parts.nextCall))
def afterKeep : CC.Stmt := by run_tac cachePart (← `(parts.afterKeep))

theorem priority_source : afterMov = .Ssequence (.Ssequence prioritySet nextCall) afterKeep := rfl
private theorem priority_set_source : prioritySet = .Sset Arm64ProgramFixture._t'167 (Arm64ProgramEntryBody.contextExpr 1) := rfl

def priorityTemps (le : CC.TempEnv) (priority : BitVec 32) : CC.TempEnv :=
  le.set Arm64ProgramFixture._t'167 (.Vint priority)


theorem source : Arm64ProgramEntryBody.afterSetup = .Ssequence (.Ssequence markSet firstCall) afterMov := rfl
private theorem mark_source : markSet = .Sset Arm64ProgramFixture._t'168 (Arm64ProgramEntryBody.contextExpr 0) := rfl

def markTemps (le : CC.TempEnv) (mark : BitVec 32) : CC.TempEnv := le.set Arm64ProgramFixture._t'168 (.Vint mark)

def callCont (initial : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) (mark : BitVec 32) : CC.Cont :=
  .Kcall none Arm64ProgramFixture.f_arm64_execute_compile (Arm64ProgramEntryAllocation.allocation initial).1 (markTemps le mark) (.Kseq afterMov k)

private theorem entry_binding {initial : CC.Mem} (entry : HeaderLocal initial) :
    (Arm64ProgramEntryAllocation.allocation initial).1.get Arm64ProgramFixture.___a64_entry =
      some (entry.block, .Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr) := by
  exact Arm64ProgramEntryAllocation.local_binding initial _ _ _ entry.binding

private theorem execute_not_local : Arm64ProgramFixture._kprog_arm64_program_execute ∉
    CC.varNames Arm64ProgramFixture.f_arm64_execute_compile.fn_vars := by decide +kernel

private theorem unshadowed (initial : CC.Mem) :
    (Arm64ProgramEntryAllocation.allocation initial).1.get Arm64ProgramFixture._kprog_arm64_program_execute = none := by
  simpa only [CC.emptyEnv, CC.PTree.gempty] using
    CC.allocVariables_env_other
      (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (Arm64ProgramEntryAllocation.allocation initial)).symm) execute_not_local

private def target : CC.Expr := by
  run_tac do
    let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.Elab.Term.elabTerm (← `(firstCall)) none))
    unless actual.isAppOfArity ``CC.Stmt.Scall 3 do throwError "actual MOV call changed"
    Lean.Elab.Tactic.closeMainGoal `actual_mov_target actual.getAppArgs[1]!

private def actualArgs : List CC.Expr := by
  run_tac do
    let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.Elab.Term.elabTerm (← `(firstCall)) none))
    unless actual.isAppOfArity ``CC.Stmt.Scall 3 do throwError "actual MOV call changed"
    Lean.Elab.Tactic.closeMainGoal `actual_mov_arguments actual.getAppArgs[2]!

private def parameterTypes : List CC.Ty :=
  [CC.tptr (.Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr),
    CC.tuint, CC.tulong, CC.tulong, CC.tulong, CC.tulong, CC.tuchar, CC.tuint, CC.tulong]

private theorem call_source : firstCall = .Scall none target actualArgs := rfl
private theorem classify_target : CC.Cop.classifyFun (CC.typeof target) =
    .f parameterTypes CC.tvoid CC.cc_default := rfl
private theorem handler_type : CC.typeOfFundef (.Internal Arm64Nop.handler) =
    .Tfunction parameterTypes CC.tvoid CC.cc_default := rfl

private theorem target_eval (initial : CC.Mem) (le : CC.TempEnv) (memory : CC.Mem) :
    CC.doEvalExpr world (Arm64ProgramEntryAllocation.allocation initial).1 le memory target =
      some (.Vptr (CC.Positive.ofNat 72) 0) := by
  have absent := unshadowed initial
  have symbol : CC.Genv.findSymbol world.genv_genv Arm64ProgramFixture._kprog_arm64_program_execute =
      some (CC.Positive.ofNat 72) := Arm64ProgramEntryLinked.execute_binding.1
  simp only [target, CC.doEvalExpr, CC.lvalOfVar, absent, symbol, CC.doDerefLoc, CC.accessMode, CC.Integers.Ptrofs.zero, CC.Integers.MI.zero]

private theorem args_eval {initial : CC.Mem} (entry : HeaderLocal initial)
    (le : CC.TempEnv) (memory : CC.Mem) (mark : BitVec 32) :
    CC.doEvalExprlist world (Arm64ProgramEntryAllocation.allocation initial).1 (markTemps le mark) memory
      actualArgs parameterTypes =
      some (Arm64MovImmediate.Dispatch.arguments (Arm64MovImmediate.LinkedRead.entry_operands entry.block mark) false) := by
  have header := entry_binding entry
  have marked : (markTemps le mark).get Arm64ProgramFixture._t'168 = some (.Vint mark) := CC.PTree.gss _ _ _
  simp only [actualArgs, parameterTypes, CC.doEvalExprlist, CC.doEvalExpr, CC.doEvalLvalue,
    CC.lvalOfVar, header, CC.typeof, marked, CC.Cop.semCast, CC.Cop.classifyCast,
    CC.Cop.castIntInt, CC.Cop.castIntLong, CC.Integers.Int.unsigned, CC.Integers.MI.unsigned,
    CC.Integers.Int.signed, CC.Integers.MI.signed, CC.Integers.Int64.repr,
    CC.Integers.Int.repr, CC.Integers.MI.repr, CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext,
    CC.Integers.Ptrofs.zero, CC.Integers.MI.zero, BitVec.ofInt_natCast, BitVec.ofNat_toNat,
    CC.tptr, CC.tvoid, CC.tuint, CC.tint, CC.tulong, CC.tuchar, CC.Archi.ptr64,
    Arm64MovImmediate.Dispatch.arguments, Arm64MovImmediate.LinkedRead.entry_operands,
    Arm64MovImmediate.Dispatch.flags, Arm64Width.argument, Bool.false_eq_true, ite_false, ite_true,
    BitVec.ofInt_natCast, BitVec.ofNat_toNat]
  rfl

private theorem call_step {initial : CC.Mem} (entry : HeaderLocal initial)
    (le : CC.TempEnv) (k : CC.Cont) (memory : CC.Mem) (mark : BitVec 32) :
    CC.doStep world (.State Arm64ProgramFixture.f_arm64_execute_compile firstCall
      (.Kseq afterMov k) (Arm64ProgramEntryAllocation.allocation initial).1 (markTemps le mark) memory) =
      some (CC.E0, .Callstate (.Internal Arm64Nop.handler)
        (Arm64MovImmediate.Dispatch.arguments (Arm64MovImmediate.LinkedRead.entry_operands entry.block mark) false)
        (callCont initial le k mark) memory) := by
  have binding : CC.Genv.findFunctPtr world.genv_genv (CC.Positive.ofNat 72) =
      some (.Internal Arm64Nop.handler) := Arm64ProgramEntryLinked.execute_binding.2
  have zero : CC.Integers.Ptrofs.eq (0 : CC.Integers.Ptrofs) CC.Integers.Ptrofs.zero = true := rfl
  have funct : CC.Genv.findFunct world.genv_genv (.Vptr (CC.Positive.ofNat 72) 0) =
      some (.Internal Arm64Nop.handler) := by
    simp only [CC.Genv.findFunct, zero, ite_true, binding]
  simp only [call_source, CC.doStep, classify_target, target_eval, args_eval entry,
    funct, handler_type, ite_true, callCont]

/-- The ORIGINAL fixture loads mark and enters the real generic handler in
five internal transitions, deriving all nine actual arguments. -/
theorem enter {initial : CC.Mem} (entry : HeaderLocal initial)
    (le : CC.TempEnv) (k : CC.Cont) (memory : CC.Mem)
    (ctxBlock : CC.Block) (ctxOfs : CC.Integers.Ptrofs) (mark : BitVec 32)
    (ctx : le.get Arm64ProgramFixture._ctx = some (.Vptr ctxBlock ctxOfs))
    (read : CC.Mem.loadv .Mint32 memory (.Vptr ctxBlock
      (CC.Integers.Ptrofs.add ctxOfs (CC.Integers.Ptrofs.repr 8))) = some (.Vint mark)) :
    InternalRun world 5
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryBody.afterSetup
        k (Arm64ProgramEntryAllocation.allocation initial).1 le memory)
      (.Callstate (.Internal Arm64Nop.handler)
        (Arm64MovImmediate.Dispatch.arguments (Arm64MovImmediate.LinkedRead.entry_operands entry.block mark) false)
        (callCont initial le k mark) memory) := by
  have loaded := Arm64ProgramEntryBody.context_read (Arm64ProgramEntryAllocation.allocation initial).1 le memory ctxBlock ctxOfs 0 mark ctx read
  have marked : CC.doStep world
      (.State Arm64ProgramFixture.f_arm64_execute_compile markSet (.Kseq firstCall (.Kseq afterMov k))
        (Arm64ProgramEntryAllocation.allocation initial).1 le memory) =
      some (CC.E0, .State Arm64ProgramFixture.f_arm64_execute_compile .Sskip (.Kseq firstCall (.Kseq afterMov k))
        (Arm64ProgramEntryAllocation.allocation initial).1 (markTemps le mark) memory) := by
    simp only [mark_source, CC.doStep, loaded, markTemps]
  have openingStep : CC.doStep world
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryBody.afterSetup
        k (Arm64ProgramEntryAllocation.allocation initial).1 le memory) =
      some (CC.E0, .State Arm64ProgramFixture.f_arm64_execute_compile (.Ssequence markSet firstCall)
        (.Kseq afterMov k) (Arm64ProgramEntryAllocation.allocation initial).1 le memory) := by
    rw [source]; rfl
  have innerStep : CC.doStep world
      (.State Arm64ProgramFixture.f_arm64_execute_compile (.Ssequence markSet firstCall)
        (.Kseq afterMov k) (Arm64ProgramEntryAllocation.allocation initial).1 le memory) =
      some (CC.E0, .State Arm64ProgramFixture.f_arm64_execute_compile markSet
        (.Kseq firstCall (.Kseq afterMov k)) (Arm64ProgramEntryAllocation.allocation initial).1 le memory) := rfl
  have skipStep : CC.doStep world
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip (.Kseq firstCall (.Kseq afterMov k))
        (Arm64ProgramEntryAllocation.allocation initial).1 (markTemps le mark) memory) =
      some (CC.E0, .State Arm64ProgramFixture.f_arm64_execute_compile firstCall (.Kseq afterMov k)
        (Arm64ProgramEntryAllocation.allocation initial).1 (markTemps le mark) memory) := rfl
  exact .step trivial (CC.doStep_sound _ _ _ _ openingStep)
    (.step trivial (CC.doStep_sound _ _ _ _ innerStep)
      (.step trivial (CC.doStep_sound _ _ _ _ marked)
        (.step trivial (CC.doStep_sound _ _ _ _ skipStep)
          (.step trivial (CC.doStep_sound _ _ _ _ (call_step entry le k memory mark)) (.refl _)))))

/-- The unchanged void-call return resumes the actual source successor. -/
theorem leave (initial : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) (mark : BitVec 32) (memory : CC.Mem) :
    InternalRun world 2 (.Returnstate .Vundef (callCont initial le k mark) memory)
      (.State Arm64ProgramFixture.f_arm64_execute_compile afterMov k (Arm64ProgramEntryAllocation.allocation initial).1 (markTemps le mark) memory) :=
  .step trivial (CC.doStep_sound _ _ _ _ rfl)
    (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _))

/-- Execute the source priority load AFTER the completed first call, reaching
the actual MOVK call statement and retaining its original continuation. -/
theorem priority_ready (initial : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) (memory : CC.Mem)
    (ctxBlock : CC.Block) (ctxOfs : CC.Integers.Ptrofs) (priority : BitVec 32)
    (ctx : le.get Arm64ProgramFixture._ctx = some (.Vptr ctxBlock ctxOfs))
    (read : CC.Mem.loadv .Mint32 memory (.Vptr ctxBlock
      (CC.Integers.Ptrofs.add ctxOfs (CC.Integers.Ptrofs.repr 32))) = some (.Vint priority)) :
    InternalRun world 4
      (.State Arm64ProgramFixture.f_arm64_execute_compile afterMov k
        (Arm64ProgramEntryAllocation.allocation initial).1 le memory)
      (.State Arm64ProgramFixture.f_arm64_execute_compile nextCall (.Kseq afterKeep k)
        (Arm64ProgramEntryAllocation.allocation initial).1 (priorityTemps le priority) memory) := by
  have loaded := Arm64ProgramEntryBody.context_read (Arm64ProgramEntryAllocation.allocation initial).1 le memory
    ctxBlock ctxOfs 1 priority ctx read
  have openingStep : CC.doStep world
      (.State Arm64ProgramFixture.f_arm64_execute_compile afterMov k
        (Arm64ProgramEntryAllocation.allocation initial).1 le memory) =
      some (CC.E0, .State Arm64ProgramFixture.f_arm64_execute_compile (.Ssequence prioritySet nextCall)
        (.Kseq afterKeep k) (Arm64ProgramEntryAllocation.allocation initial).1 le memory) := by
    rw [priority_source]; rfl
  have innerStep : CC.doStep world
      (.State Arm64ProgramFixture.f_arm64_execute_compile (.Ssequence prioritySet nextCall)
        (.Kseq afterKeep k) (Arm64ProgramEntryAllocation.allocation initial).1 le memory) =
      some (CC.E0, .State Arm64ProgramFixture.f_arm64_execute_compile prioritySet
        (.Kseq nextCall (.Kseq afterKeep k)) (Arm64ProgramEntryAllocation.allocation initial).1 le memory) := rfl
  have loadedStep : CC.doStep world
      (.State Arm64ProgramFixture.f_arm64_execute_compile prioritySet (.Kseq nextCall (.Kseq afterKeep k))
        (Arm64ProgramEntryAllocation.allocation initial).1 le memory) =
      some (CC.E0, .State Arm64ProgramFixture.f_arm64_execute_compile .Sskip (.Kseq nextCall (.Kseq afterKeep k))
        (Arm64ProgramEntryAllocation.allocation initial).1 (priorityTemps le priority) memory) := by
    simp only [priority_set_source, CC.doStep, loaded, priorityTemps]
  have skipStep : CC.doStep world
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip (.Kseq nextCall (.Kseq afterKeep k))
        (Arm64ProgramEntryAllocation.allocation initial).1 (priorityTemps le priority) memory) =
      some (CC.E0, .State Arm64ProgramFixture.f_arm64_execute_compile nextCall (.Kseq afterKeep k)
        (Arm64ProgramEntryAllocation.allocation initial).1 (priorityTemps le priority) memory) := rfl
  exact .step trivial (CC.doStep_sound _ _ _ _ openingStep)
    (.step trivial (CC.doStep_sound _ _ _ _ innerStep)
      (.step trivial (CC.doStep_sound _ _ _ _ loadedStep)
        (.step trivial (CC.doStep_sound _ _ _ _ skipStep) (.refl _))))

/-- Run the actual first fixture call through its genuine successor and
priority load. The provider trace, resulting heap/storage and scalar inputs
of the next call all come from this same execution. -/
theorem execute {initial before supplied : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry)
    (header : (i : Fin 12) → HeaderSourceLocal initial i)
    (pointers : ∀ i, CC.Mem.load CC.Mptr before entry.block (8 * (i.val : Int)) = some (.Vptr (header i).block 0))
    (access : ∀ block, block.toNat < (Arm64Producer.allocation initial).2.nextblock.toNat →
      CC.PMap.get block before.access = CC.PMap.get block (Arm64Producer.allocation initial).2.access)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (cold : Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned before (.Vptr entry.block 0)
      Arm64Program._sp_valid = some (.Vint 0))
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins) (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val) before.nextblock before (.Vptr entry.block 0) s)
    (le : CC.TempEnv) (k : CC.Cont) (ctxBlock : CC.Block) (ctxOfs : CC.Integers.Ptrofs)
    (mark priority : BitVec 32)
    (ctx : le.get Arm64ProgramFixture._ctx = some (.Vptr ctxBlock ctxOfs))
    (old : ctxBlock.toNat < initial.nextblock.toNat)
    (markRead : CC.Mem.loadv .Mint32 before (.Vptr ctxBlock
      (CC.Integers.Ptrofs.add ctxOfs (CC.Integers.Ptrofs.repr 8))) = some (.Vint mark))
    (priorityRead : CC.Mem.loadv .Mint32 before (.Vptr ctxBlock
      (CC.Integers.Ptrofs.add ctxOfs (CC.Integers.Ptrofs.repr 32))) = some (.Vint priority))
    (trace : CC.Trace)
    (provider : CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv world.genv_genv)
      [.Vint 1] (Arm64Nop.allocation world before).2 trace (.Vlong origins.stack) supplied)
    (outcome : Arm64ProgramEntryCacheFrame.Frame initial false (Arm64Nop.allocation world before).2 supplied) :
    ∃ written after, ∃ finalStorage : Storage initial after entry,
      CC.Mem.load .Mint64 after ((finalStorage.tables false).cellBlock 1) 0 = some (.Vlong (mark.setWidth 64)) ∧
      CC.Mem.load .Mint8unsigned after ((finalStorage.tables true).cellBlock 1) 0 = some (.Vint 0) ∧
      CC.Star (CC.Step2 world)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryBody.afterSetup k
          (Arm64ProgramEntryAllocation.allocation initial).1 le before)
        trace (.State Arm64ProgramFixture.f_arm64_execute_compile nextCall (.Kseq afterKeep k)
          (Arm64ProgramEntryAllocation.allocation initial).1 (priorityTemps (markTemps le mark) priority) after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) before.nextblock after (.Vptr entry.block 0)
        (Arm64RegisterWrite.nativeUpdate s 1 (mark.setWidth 64) false) ∧
      FrameBelow initial.nextblock before after ∧
      (priorityTemps (markTemps le mark) priority).get Arm64ProgramFixture._t'167 = some (.Vint priority) ∧
      CC.Mem.freeList written (CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world before).1) = some after ∧
      FrameBelow before.nextblock written after ∧
      after.contents = written.contents ∧ after.nextblock = (Arm64Nop.allocation world before).2.nextblock ∧
      (∀ row ∈ CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world before).1,
        ∀ ofs, row.2.1 ≤ ofs → ofs < row.2.2 →
          ∀ kind permission, CC.Mem.perm after row.1 ofs kind permission = false) := by
  obtain ⟨written, after, finalStorage, word, tag, call, registers, frame, freed, freeFrame, contents, next, released⟩ :=
    Arm64MovImmediate.LinkedCall.entry_call storage header pointers access bound cold addresses origins s represented mark trace
      provider outcome (callCont initial le k mark) rfl
  have entered := enter entry le k before ctxBlock ctxOfs mark ctx markRead
  have returned := leave initial le k mark after
  have nextCtx : (markTemps le mark).get Arm64ProgramFixture._ctx = some (.Vptr ctxBlock ctxOfs) := by
    simp +decide only [markTemps, CC.PTree.gso, ctx]
  have nextRead := (Arm64ProgramEntryBody.context_read_frame frame ctxBlock old ctxOfs 1).trans priorityRead
  have priorityLoad := priority_ready initial (markTemps le mark) k after ctxBlock ctxOfs priority nextCtx nextRead
  refine ⟨written, after, finalStorage, word, tag, ?_, registers, frame, CC.PTree.gss _ _ _,
    freed, freeFrame, contents, next, released⟩
  simpa only [CC.Eapp, CC.E0, List.nil_append, List.append_nil] using
    star_trans (star_trans entered.sound call) (returned.trans priorityLoad).sound

end KProgFormal.ClightRefinement.Arm64ProgramEntryMovCall
