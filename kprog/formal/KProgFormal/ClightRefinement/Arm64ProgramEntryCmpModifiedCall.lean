import KProgFormal.ClightRefinement.Arm64ProgramEntryCmpBranch
import KProgFormal.ClightRefinement.Arm64ModifiedNoneCall

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryCmpModifiedCall

open Arm64ProgramEntryAllocation (world allocation)
open Arm64ProgramEntryCmpBranch

private def symbol : CC.Block :=
  (CC.Genv.findSymbol world.genv_genv Arm64ProgramFixture._kprog_arm64_program_modified).get (by decide +kernel)
private theorem binding :
    CC.Genv.findSymbol world.genv_genv Arm64ProgramFixture._kprog_arm64_program_modified = some symbol ∧
    CC.Genv.findFunctPtr world.genv_genv symbol = some (.Internal Arm64Modified.Read.handler) := by
  constructor <;> run_tac Arm64ProgramEntryLinked.sourceEquality
private theorem unshadowed (initial : CC.Mem) :
    (allocation initial).1.get Arm64ProgramFixture._kprog_arm64_program_modified = none := by
  have outside : Arm64ProgramFixture._kprog_arm64_program_modified ∉
      CC.varNames Arm64ProgramFixture.f_arm64_execute_compile.fn_vars := by decide +kernel
  simpa only [CC.emptyEnv,CC.PTree.gempty] using CC.allocVariables_env_other
    (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation initial)).symm) outside

private def packedByte (amount : BitVec 32) : CC.Expr :=
  .Ecast (.Ebinop .Oand (.Ebinop .Oshr (.Econst_int 0 CC.tint) (.Econst_int amount CC.tint) CC.tint)
    (.Econst_int 255 CC.tuint) CC.tuint) CC.tuchar

theorem call_source : modifiedCall = .Scall (some Arm64ProgramFixture._t'144)
    (.Evar Arm64ProgramFixture._kprog_arm64_program_modified
      (.Tfunction [CC.tptr (.Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr),CC.tulong,
        CC.tuchar,CC.tuchar,CC.tuchar] CC.tulong CC.cc_default))
    [.Eaddrof (.Evar Arm64ProgramFixture.___a64_entry (.Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr))
       (CC.tptr (.Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr)),
     .Econst_int 4 CC.tuint,packedByte 8,packedByte 16,.Etempvar Arm64ProgramFixture.___a64_cmp_width CC.tuchar] := rfl

private theorem eval_cons {e : CC.Env} {le : CC.TempEnv} {m : CC.Mem}
    {a : CC.Expr} {xs : List CC.Expr} {ty : CC.Ty} {tys : List CC.Ty}
    {v converted : CC.Val} {values : List CC.Val}
    (head : CC.doEvalExpr world e le m a = some v)
    (cast : CC.Cop.semCast v (CC.typeof a) ty m = some converted)
    (rest : CC.doEvalExprlist world e le m xs tys = some values) :
    CC.doEvalExprlist world e le m (a :: xs) (ty :: tys) = some (converted :: values) := by
  simp only [CC.doEvalExprlist,head,cast,rest]

theorem call_step {initial : CC.Mem} (entry : Arm64Producer.HeaderLocal initial)
    (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (width : le.get Arm64ProgramFixture.___a64_cmp_width = some (.Vint 8)) :
    CC.Step2 world
      (.State Arm64ProgramFixture.f_arm64_execute_compile modifiedCall k (allocation initial).1 le m) CC.E0
      (.Callstate (.Internal Arm64Modified.Read.handler) (Arm64Modified.NoneCall.arguments entry.block 0 (4#64))
        (.Kcall (some Arm64ProgramFixture._t'144) Arm64ProgramFixture.f_arm64_execute_compile (allocation initial).1 le k) m) := by
  have header : (allocation initial).1.get Arm64ProgramFixture.___a64_entry =
      some (entry.block,.Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr) :=
    Arm64ProgramEntryAllocation.local_binding initial _ _ _ entry.binding
  rw [call_source]
  apply CC.Step.call (tyargs := [CC.tptr (.Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr),
    CC.tulong,CC.tuchar,CC.tuchar,CC.tuchar]) (tyres := CC.tulong) (cconv := CC.cc_default) (vf := .Vptr symbol 0)
  · rfl
  · apply CC.doEvalExpr_sound
    simp only [CC.doEvalExpr,CC.lvalOfVar,unshadowed initial,binding.1,CC.doDerefLoc,CC.accessMode]
    rfl
  · apply CC.doEvalExprlist_sound
    refine eval_cons (v := .Vptr entry.block 0) ?_ (by rfl) ?_
    · simp only [CC.doEvalExpr,CC.doEvalLvalue,CC.lvalOfVar,header]
      rfl
    refine eval_cons (v := .Vint (4#32)) (by rfl) (by rfl) ?_
    refine eval_cons (v := .Vint (0#32)) (by rfl) (by rfl) ?_
    refine eval_cons (v := .Vint (0#32)) (by rfl) (by rfl) ?_
    exact eval_cons (v := .Vint 8) (by simpa only [CC.doEvalExpr] using width) (by rfl) (by rfl)
  · simpa +decide [CC.Genv.findFunct,CC.Integers.Ptrofs.eq,CC.Integers.Ptrofs.zero,
      CC.Integers.MI.eq,CC.Integers.MI.zero] using binding.2
  · rfl

def temps (le : CC.TempEnv) (value : BitVec 64) : CC.TempEnv :=
  le.set Arm64ProgramFixture._t'144 (.Vlong value)

/-- The actual helper/caller uses X4 from the current allocated pointer tables,
reads both scalar word/tag, and returns the unchanged full-width word. -/
theorem invoke {initial : CC.Mem} (entry : Arm64Producer.HeaderLocal initial)
    (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (value : BitVec 64)
    (width : le.get Arm64ProgramFixture.___a64_cmp_width = some (.Vint 8))
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry)
    (observed : Arm64EntryMemory.gpr m.nextblock m (.Vptr entry.block 0) 4 = some (.Vlong value,.Vint 0)) :
    ∃ count, InternalRun world count
      (.State Arm64ProgramFixture.f_arm64_execute_compile modifiedCall k (allocation initial).1 le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip k (allocation initial).1 (temps le value) m) := by
  have actual := Arm64RegisterWrite.storage_gpr storage (4 : Fin 31)
  change Arm64EntryMemory.gpr m.nextblock m (.Vptr entry.block 0) 4 = _ at actual
  rw [actual] at observed
  simp only [bind,pure,Option.bind_eq_some_iff,Option.some.injEq,Prod.mk.injEq] at observed
  obtain ⟨word,wordRead,tag,tagRead,hw,ht⟩ := observed
  have wordLoad : CC.Mem.load .Mint64 m ((storage.tables false).cellBlock 4) 0 = some (.Vlong value) := by
    simpa only [hw] using wordRead
  have tagLoad : CC.Mem.load .Mint8unsigned m ((storage.tables true).cellBlock 4) 0 = some (.Vint 0) := by
    simpa only [ht] using tagRead
  let cont := CC.Cont.Kcall (some Arm64ProgramFixture._t'144) Arm64ProgramFixture.f_arm64_execute_compile
    (allocation initial).1 le k
  have enter : InternalRun world 1
      (.State Arm64ProgramFixture.f_arm64_execute_compile modifiedCall k (allocation initial).1 le m)
      (.Callstate (.Internal Arm64Modified.Read.handler) (Arm64Modified.NoneCall.arguments entry.block 0 (4#64)) cont m) :=
    .step (by rw [call_source]; trivial) (call_step entry le m k width) (.refl _)
  obtain ⟨count,run⟩ := Arm64Modified.NoneCall.execute world Arm64MovKeep.Linked.reader_layout (4 : Fin 31)
    entry.block (storage.tables false).tableBlock ((storage.tables false).cellBlock 4)
    (storage.tables true).tableBlock ((storage.tables true).cellBlock 4) 0 0 0 0 0 m cont value
    (by change CC.Mem.load CC.Mptr m entry.block 0 = _; exact storage.roots false)
    (by change CC.Mem.load CC.Mptr m (storage.tables false).tableBlock 32 = _; exact storage.slots false 4)
    (by change CC.Mem.load CC.Mptr m entry.block 8 = _; exact storage.roots true)
    (by change CC.Mem.load CC.Mptr m (storage.tables true).tableBlock 32 = _; exact storage.slots true 4)
    (by exact wordLoad) (by exact tagLoad)
  have leave : InternalRun world 1
      (.Returnstate (.Vlong value) (CC.callCont cont) m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip k (allocation initial).1 (temps le value) m) :=
    .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  exact ⟨_,(enter.trans run).trans leave⟩

end KProgFormal.ClightRefinement.Arm64ProgramEntryCmpModifiedCall
