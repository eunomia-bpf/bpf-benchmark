import KProgFormal.ClightRefinement.Arm64MemsetComplete

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemsetProgramCaller

open Arm64Producer
open Arm64ProgramEntryAllocation (world)

private structure Parts where
  call : CC.Stmt
  next : CC.Stmt
private def parts : Parts := by
  run_tac do
    let term ← Lean.Elab.Term.elabTerm (← `(Arm64ProgramEntryOrdinaryMoves.afterSecond)) none
    let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
    unless actual.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original memset caller sequence changed"
    Lean.Elab.Tactic.closeMainGoal `actual_memset_caller_parts (← Lean.Meta.mkAppM ``Parts.mk actual.getAppArgs)
private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_memset_caller_part (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))
def call : CC.Stmt := by run_tac cachePart (← `(parts.call))
def next : CC.Stmt := by run_tac cachePart (← `(parts.next))
theorem source : Arm64ProgramEntryOrdinaryMoves.afterSecond = .Ssequence call next := rfl
theorem next_source : next = Arm64ProgramEntryPointerWrites.beforeSecond := rfl
private def entryType : CC.Ty := .Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr
theorem call_source : call = .Scall none
    (.Evar Arm64ProgramFixture._kprog_arm64_program_memset (.Tfunction [CC.tptr entryType] CC.tvoid CC.cc_default))
    [.Eaddrof (.Evar Arm64ProgramFixture.___a64_entry entryType) (CC.tptr entryType)] := rfl

private def symbol : CC.Block := CC.Positive.ofNat 70
theorem binding : CC.Genv.findSymbol world.genv_genv Arm64ProgramFixture._kprog_arm64_program_memset = some symbol ∧
    CC.Genv.findFunctPtr world.genv_genv symbol = some (.Internal Arm64MemsetSource.handler) := by
  constructor <;> run_tac Arm64ProgramEntryLinked.sourceEquality

def callCont (initial : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) : CC.Cont :=
  .Kcall none Arm64ProgramFixture.f_arm64_execute_compile (Arm64ProgramEntryAllocation.allocation initial).1 le (.Kseq next k)

theorem ready {initial : CC.Mem} (entry : HeaderLocal initial) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    InternalRun world 2 (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryOrdinaryMoves.afterSecond
      k (Arm64ProgramEntryAllocation.allocation initial).1 le m)
      (.Callstate (.Internal Arm64MemsetSource.handler) [.Vptr entry.block 0] (callCont initial le k) m) := by
  have outside : Arm64ProgramFixture._kprog_arm64_program_memset ∉ CC.varNames Arm64ProgramFixture.f_arm64_execute_compile.fn_vars := by decide +kernel
  have unshadowed : (Arm64ProgramEntryAllocation.allocation initial).1.get Arm64ProgramFixture._kprog_arm64_program_memset = none := by
    simpa only [CC.emptyEnv,CC.PTree.gempty] using CC.allocVariables_env_other
      (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (Arm64ProgramEntryAllocation.allocation initial)).symm) outside
  have header : (Arm64ProgramEntryAllocation.allocation initial).1.get Arm64ProgramFixture.___a64_entry =
      some (entry.block,entryType) := Arm64ProgramEntryAllocation.local_binding initial _ _ _ entry.binding
  rw [source]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [call_source]
  refine .step trivial ?_ (.refl _)
  apply CC.Step.call (tyargs := [CC.tptr entryType]) (tyres := CC.tvoid) (cconv := CC.cc_default) (vf := .Vptr symbol 0)
  · rfl
  · apply CC.doEvalExpr_sound
    simp only [CC.doEvalExpr,CC.lvalOfVar,unshadowed,binding.1,CC.doDerefLoc,CC.accessMode]
    rfl
  · apply CC.doEvalExprlist_sound
    simp only [CC.doEvalExprlist,CC.doEvalExpr,CC.doEvalLvalue,CC.lvalOfVar,header,
      CC.Cop.semCast,CC.Cop.classifyCast,CC.typeconv,CC.removeAttributes,CC.tattr,entryType,CC.tptr]
    rfl
  · simpa +decide [CC.Genv.findFunct,CC.Integers.Ptrofs.eq,CC.Integers.Ptrofs.zero,
      CC.Integers.MI.eq,CC.Integers.MI.zero] using binding.2
  · rfl

theorem returned (initial : CC.Mem) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    InternalRun world 2 (.Returnstate .Vundef (callCont initial le k) m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile next k (Arm64ProgramEntryAllocation.allocation initial).1 le m) :=
  .step trivial (CC.doStep_sound _ _ _ _ rfl) (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _))

/-- Execute the genuine source program call and its actual continuation,
deriving the complete memset procedure run and current output packet. -/
theorem original {initial before markWritten markAfter constantWritten constantAfter : CC.Mem}
    {entry : HeaderLocal initial} {oldStorage : Arm64ProducerRegisterStorage.Storage initial before entry}
    {addresses : Arm64Registers.PointerOrigins} {origins : Reference.Provenance.AArch64.Origins}
    {prior nextState : Reference.AArch64.State} {priorK nextK : CC.Cont} (mark : BitVec 32)
    (first : Arm64MovImmediate.OrdinaryCall.Result oldStorage 1 (mark.setWidth 64)
      addresses origins prior priorK markWritten markAfter)
    (bound : (allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (second : Arm64MovImmediate.OrdinaryCall.Result (first.storage bound) 2 (16#64)
      addresses origins nextState nextK constantWritten constantAfter)
    (view : Arm64MemsetHeaderView.View initial (Arm64MemsetSource.allocation constantAfter).2 entry)
    (abi : TailLocal initial 6)
    (resources : Arm64ProgramEntryResources.Resources initial (Arm64MemsetSource.allocation constantAfter).2 entry)
    (storage : Arm64ProducerRegisterStorage.Storage initial (Arm64MemsetSource.allocation constantAfter).2 entry)
    (spAtBase : storage.spValue = (-32#64))
    (gpr : Arm64EntryMemory.gpr (Arm64MemsetSource.allocation constantAfter).2.nextblock
      (Arm64MemsetSource.allocation constantAfter).2 (.Vptr entry.block 0) 0 =
      some (.Vlong (-32#64),.Vint ((4#8).setWidth 32)))
    (abiHeader : CC.Mem.load CC.Mptr (Arm64MemsetSource.allocation constantAfter).2 entry.block 704 = some (.Vptr abi.block 0))
    (abiKind : CC.Mem.load .Mint8unsigned (Arm64MemsetSource.allocation constantAfter).2 abi.block 0 = some (.Vint 2))
    (tagBytes : ∀ j : Fin 24, CC.Mem.load .Mint8unsigned (Arm64MemsetSource.allocation constantAfter).2
      view.tags.block (j.val : Int) = some (.Vint 0))
    (byteInputs : ∀ outerLe, Arm64MemsetReleaseComplete.Inputs view abi (Arm64MemsetLossSetup.byte mark) outerLe)
    (registerInputs : ∀ outerLe, Arm64MemsetClobberRegisterComplete.Inputs view abi (Arm64MemsetLossSetup.byte mark) outerLe)
    (flagInputs : ∀ outerLe gprs, Arm64MemsetClobberFlagsComplete.Inputs view abi (Arm64MemsetLossSetup.byte mark) outerLe gprs)
    (vectorInputs : ∀ outerLe gprs flags,
      Arm64MemsetClobberVectorsComplete.Inputs view abi (Arm64MemsetLossSetup.byte mark) outerLe gprs flags)
    (le : CC.TempEnv) (k : CC.Cont) :
    ∃ after written outerLe helperLe gprs flags values trace,
      ∃ _current : Arm64MemsetClobberVectorsComplete.Invariant view abi (Arm64MemsetLossSetup.byte mark)
        outerLe gprs flags 64 values after helperLe,
      CC.Star (CC.Step2 world) (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryOrdinaryMoves.afterSecond
        k (Arm64ProgramEntryAllocation.allocation initial).1 le constantAfter) trace
        (.State Arm64ProgramFixture.f_arm64_execute_compile next k (Arm64ProgramEntryAllocation.allocation initial).1 le after) ∧
      Arm64MemsetReturn.FreeResult constantAfter written after ∧
      FrameBelow initial.nextblock constantAfter after ∧
      after.nextblock = (Arm64MemsetSource.allocation constantAfter).2.nextblock := by
  have enter := ready entry le constantAfter k
  obtain ⟨after,written,outerLe,helperLe,gprs,flags,values,trace,packet,procedure,freed,frame,nextBlock⟩ :=
    Arm64MemsetComplete.original mark first bound second view abi resources storage spAtBase gpr abiHeader abiKind tagBytes
      byteInputs registerInputs flagInputs vectorInputs (callCont initial le k) rfl
  refine ⟨after,written,outerLe,helperLe,gprs,flags,values,trace,packet,?_,freed,frame,nextBlock⟩
  simpa only [CC.E0,CC.Eapp,List.nil_append,List.append_nil] using
    star_trans (star_trans enter.sound procedure) (returned initial le after k).sound

end KProgFormal.ClightRefinement.Arm64MemsetProgramCaller
