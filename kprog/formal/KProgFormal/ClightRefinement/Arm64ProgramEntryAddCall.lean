import KProgFormal.ClightRefinement.Arm64AddImmediateNativeCall
import KProgFormal.ClightRefinement.Arm64ProgramEntryMovCall

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryAddCall

open Arm64Producer (HeaderLocal HeaderSourceLocal)
open Arm64ProducerRegisterStorage Arm64ProducerEntryView
open Arm64ProgramEntryAllocation (world)

private structure Parts where
  call : CC.Stmt
  next : CC.Stmt

private def parts : Parts := by
  run_tac do
    let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf
      (← Lean.Elab.Term.elabTerm (← `(Arm64ProgramEntryMovCall.afterKeep)) none))
    unless actual.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original ADD caller sequence changed"
    Lean.Elab.Tactic.closeMainGoal `actual_add_caller (← Lean.Meta.mkAppM ``Parts.mk actual.getAppArgs)

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_add_part (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private def call : CC.Stmt := by run_tac cachePart (← `(parts.call))
def afterAdd : CC.Stmt := by run_tac cachePart (← `(parts.next))

/-- The next real source call after MOVK, with its untouched successor. -/
theorem source : Arm64ProgramEntryMovCall.afterKeep = .Ssequence call afterAdd := rfl

private def target : CC.Expr := by
  run_tac do
    let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf
      (← Lean.Elab.Term.elabTerm (← `(call)) none))
    unless actual.isAppOfArity ``CC.Stmt.Scall 3 do throwError "original ADD call changed"
    Lean.Elab.Tactic.closeMainGoal `actual_add_target actual.getAppArgs[1]!

private def actualArgs : List CC.Expr := by
  run_tac do
    let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf
      (← Lean.Elab.Term.elabTerm (← `(call)) none))
    unless actual.isAppOfArity ``CC.Stmt.Scall 3 do throwError "original ADD arguments changed"
    Lean.Elab.Tactic.closeMainGoal `actual_add_arguments actual.getAppArgs[2]!

private def parameterTypes : List CC.Ty :=
  [CC.tptr (.Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr),
    CC.tuint, CC.tulong, CC.tulong, CC.tulong, CC.tulong, CC.tuchar, CC.tuint, CC.tulong]

private theorem call_source : call = .Scall none target actualArgs := rfl
private theorem target_type : CC.Cop.classifyFun (CC.typeof target) =
    .f parameterTypes CC.tvoid CC.cc_default := rfl

private theorem execute_not_local : Arm64ProgramFixture._kprog_arm64_program_execute ∉
    CC.varNames Arm64ProgramFixture.f_arm64_execute_compile.fn_vars := by decide +kernel

private theorem target_eval (initial : CC.Mem) (le : CC.TempEnv) (m : CC.Mem) :
    CC.doEvalExpr world (Arm64ProgramEntryAllocation.allocation initial).1 le m target =
      some (.Vptr Arm64ProgramEntryLinked.executeBlock 0) := by
  have absent : (Arm64ProgramEntryAllocation.allocation initial).1.get
      Arm64ProgramFixture._kprog_arm64_program_execute = none := by
    simpa only [CC.emptyEnv, CC.PTree.gempty] using CC.allocVariables_env_other
      (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (Arm64ProgramEntryAllocation.allocation initial)).symm)
      execute_not_local
  have symbol : CC.Genv.findSymbol world.genv_genv Arm64ProgramFixture._kprog_arm64_program_execute =
      some Arm64ProgramEntryLinked.executeBlock := Arm64ProgramEntryLinked.execute_binding.1
  simp only [target, CC.doEvalExpr, CC.lvalOfVar, absent, symbol,
    CC.doDerefLoc, CC.accessMode, CC.Integers.Ptrofs.zero, CC.Integers.MI.zero]

private theorem args_eval {initial : CC.Mem} (entry : HeaderLocal initial) (le : CC.TempEnv) (m : CC.Mem) :
    CC.doEvalExprlist world (Arm64ProgramEntryAllocation.allocation initial).1 le m actualArgs parameterTypes =
      some (Arm64AddImmediate.Call.arguments entry.block 2 (16#64) (.Vlong (255#64)) (.Vlong (255#64))) := by
  have header : (Arm64ProgramEntryAllocation.allocation initial).1.get Arm64ProgramFixture.___a64_entry =
      some (entry.block, .Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr) :=
    Arm64ProgramEntryAllocation.local_binding initial _ _ _ entry.binding
  simp only [actualArgs, parameterTypes, Arm64AddImmediate.Call.arguments,
    CC.doEvalExprlist, CC.doEvalExpr, CC.doEvalLvalue, CC.lvalOfVar, header, CC.typeof,
    CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, CC.Cop.castIntLong,
    CC.Integers.Int.unsigned, CC.Integers.MI.unsigned, CC.Integers.Int.signed, CC.Integers.MI.signed,
    CC.Integers.Int64.repr, CC.Integers.Int.repr, CC.Integers.MI.repr,
    CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.Integers.Ptrofs.zero, CC.Integers.MI.zero,
    BitVec.ofInt_natCast, BitVec.ofNat_toNat, CC.tptr, CC.tvoid, CC.tuint, CC.tint, CC.tulong, CC.tuchar, CC.Archi.ptr64]
  rfl

def callCont (initial : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) : CC.Cont :=
  .Kcall none Arm64ProgramFixture.f_arm64_execute_compile
    (Arm64ProgramEntryAllocation.allocation initial).1 le (.Kseq afterAdd k)

/-- Execute the genuine original ADD call and all nine source argument casts. -/
theorem enter {initial : CC.Mem} (entry : HeaderLocal initial) (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem) :
    InternalRun world 2
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryMovCall.afterKeep k
        (Arm64ProgramEntryAllocation.allocation initial).1 le m)
      (.Callstate (.Internal Arm64Nop.handler)
        (Arm64AddImmediate.Call.arguments entry.block 2 (16#64) (.Vlong (255#64)) (.Vlong (255#64)))
        (callCont initial le k) m) := by
  have handler_type : CC.typeOfFundef (.Internal Arm64Nop.handler) =
      .Tfunction parameterTypes CC.tvoid CC.cc_default := rfl
  have zero : CC.Integers.Ptrofs.eq (0 : CC.Integers.Ptrofs) CC.Integers.Ptrofs.zero = true := rfl
  have funct : CC.Genv.findFunct world.genv_genv (.Vptr Arm64ProgramEntryLinked.executeBlock 0) =
      some (.Internal Arm64Nop.handler) := by
    have binding : CC.Genv.findFunctPtr world.genv_genv Arm64ProgramEntryLinked.executeBlock =
        some (.Internal Arm64Nop.handler) := Arm64ProgramEntryLinked.execute_binding.2
    simp only [CC.Genv.findFunct, zero, ite_true, binding]
  have next : CC.Step2 world
      (.State Arm64ProgramFixture.f_arm64_execute_compile call (.Kseq afterAdd k)
        (Arm64ProgramEntryAllocation.allocation initial).1 le m) CC.E0
      (.Callstate (.Internal Arm64Nop.handler)
        (Arm64AddImmediate.Call.arguments entry.block 2 (16#64) (.Vlong (255#64)) (.Vlong (255#64)))
        (callCont initial le k) m) := by
    apply CC.doStep_sound
    simp only [call_source, CC.doStep, target_type, target_eval, args_eval entry le m,
      funct, handler_type, ite_true, callCont]
  have sequence : CC.Step2 world
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryMovCall.afterKeep k
        (Arm64ProgramEntryAllocation.allocation initial).1 le m) CC.E0
      (.State Arm64ProgramFixture.f_arm64_execute_compile call (.Kseq afterAdd k)
        (Arm64ProgramEntryAllocation.allocation initial).1 le m) := by
    apply CC.doStep_sound
    simp only [CC.doStep, source]
  have selected : InternalRun world 1
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryMovCall.afterKeep k
        (Arm64ProgramEntryAllocation.allocation initial).1 le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile call (.Kseq afterAdd k)
        (Arm64ProgramEntryAllocation.allocation initial).1 le m) := .step trivial sequence (.refl _)
  have invoked : InternalRun world 1
      (.State Arm64ProgramFixture.f_arm64_execute_compile call (.Kseq afterAdd k)
        (Arm64ProgramEntryAllocation.allocation initial).1 le m)
      (.Callstate (.Internal Arm64Nop.handler)
        (Arm64AddImmediate.Call.arguments entry.block 2 (16#64) (.Vlong (255#64)) (.Vlong (255#64)))
        (callCont initial le k) m) := .step trivial next (.refl _)
  exact selected.trans invoked

/-- The actual void-call continuation resumes the unchanged source successor. -/
theorem leave (initial : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) (m : CC.Mem) :
    InternalRun world 2 (.Returnstate .Vundef (callCont initial le k) m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile afterAdd k
        (Arm64ProgramEntryAllocation.allocation initial).1 le m) :=
  .step trivial (CC.doStep_sound _ _ _ _ rfl)
    (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _))

/-- The real third caller segment, from the original MOVK successor through
ADD and its actual return, refines the admitted fetched ADD-from-SP word. -/
theorem corresponds {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (header : (j : Fin 12) → HeaderSourceLocal initial j)
    (pointers : ∀ j, CC.Mem.load CC.Mptr before entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0))
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s)
    (warm : Arm64RegisterReads.WarmEntryCache false before.nextblock before (.Vptr entry.block 0) origins.stack)
    (le : CC.TempEnv) (k : CC.Cont) (instruction : Reference.AArch64.Instruction)
    (decoded : instruction.decoded = .DPI (.Add_sub_imm (Arm64AddImmediate.Native.fields 2 (16#12) false)))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    ∃ written after, ∃ finalStorage : Storage initial after entry,
      CC.Mem.load .Mint64 after ((finalStorage.tables false).cellBlock 2) 0 =
        some (.Vlong (storage.spValue + (16#64))) ∧
      CC.Mem.load .Mint8unsigned after ((finalStorage.tables true).cellBlock 2) 0 = some (.Vint (4#32)) ∧
      InternalRun world 337
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryMovCall.afterKeep k
          (Arm64ProgramEntryAllocation.allocation initial).1 le before)
        (.State Arm64ProgramFixture.f_arm64_execute_compile afterAdd k
          (Arm64ProgramEntryAllocation.allocation initial).1 le after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) before.nextblock after (.Vptr entry.block 0)
        (Reference.AArch64.step s).state ∧
      (Reference.AArch64.step s).events = [] ∧ (Reference.AArch64.step s).fault = none ∧
      FrameBelow initial.nextblock before after ∧
      CC.Mem.freeList written (CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world before).1) = some after ∧
      FrameBelow before.nextblock written after ∧
      after.contents = written.contents ∧ after.nextblock = written.nextblock ∧
      (∀ row ∈ CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world before).1,
        ∀ ofs, row.2.1 ≤ ofs → ofs < row.2.2 →
          ∀ kind permission, CC.Mem.perm after row.1 ofs kind permission = false) ∧
      Arm64CacheLocalFrame.Kept initial before after 2 ∧
      (∀ j, CC.Mem.load CC.Mptr after entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0)) ∧
      Arm64RegisterReads.WarmEntryCache false before.nextblock after (.Vptr entry.block 0) origins.stack := by
  have entered := enter entry le k before
  obtain ⟨written, after, finalStorage, word, tag, run, registers, events, fault, frame, freed,
      freeFrame, contents, next, released, kept, finalPointers, finalWarm⟩ :=
    Arm64AddImmediate.Call.corresponds storage bound header pointers addresses origins s represented warm
      2 (16#12) false (.Vlong (255#64)) (.Vlong (255#64)) (callCont initial le k) rfl
      instruction decoded noError fetched
  have returned := leave initial le k after
  exact ⟨written, after, finalStorage, word, tag, (entered.trans run).trans returned,
    registers, events, fault, frame, freed, freeFrame, contents, next, released, kept, finalPointers, finalWarm⟩

end KProgFormal.ClightRefinement.Arm64ProgramEntryAddCall
