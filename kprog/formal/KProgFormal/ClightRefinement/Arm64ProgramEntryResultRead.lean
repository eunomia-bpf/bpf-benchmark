import KProgFormal.ClightRefinement.Arm64ProgramEntryUaddlvCall
import KProgFormal.ClightRefinement.Arm64MovKeepLinked
import KProgFormal.ClightRefinement.Arm64ProgramEntryColdRead

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryResultRead

open Arm64ProgramEntryAllocation (world allocation)
open Arm64Producer (HeaderLocal)

private structure Parts where
  call5 : CC.Stmt
  call7 : CC.Stmt
  vector3 : CC.Stmt
  firstXor : CC.Stmt
  vector0 : CC.Stmt
  secondXor : CC.Stmt
  next : CC.Stmt

private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ``CC.Stmt.Ssequence 2 do
        throwError "original result read sequence changed"
      pure actual.getAppArgs
    let root ← peel (← Lean.Elab.Term.elabTerm (← `(Arm64ProgramEntryUaddlvCall.afterUaddlv)) none)
    let first ← peel root[0]!
    let calls ← peel first[0]!
    let result ← peel first[1]!
    let tail ← peel root[1]!
    let second ← peel tail[0]!
    Lean.Elab.Tactic.closeMainGoal `actual_result_reads
      (← Lean.Meta.mkAppM ``Parts.mk #[calls[0]!,calls[1]!,result[0]!,result[1]!,second[0]!,second[1]!,tail[1]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_result_read_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private def call5 : CC.Stmt := by run_tac cachePart (← `(parts.call5))
private def call7 : CC.Stmt := by run_tac cachePart (← `(parts.call7))
def vector3 : CC.Stmt := by run_tac cachePart (← `(parts.vector3))
def firstXor : CC.Stmt := by run_tac cachePart (← `(parts.firstXor))
def vector0 : CC.Stmt := by run_tac cachePart (← `(parts.vector0))
def secondXor : CC.Stmt := by run_tac cachePart (← `(parts.secondXor))
def afterReads : CC.Stmt := by run_tac cachePart (← `(parts.next))

def call (seven : Bool) : CC.Stmt := if seven then call7 else call5
def resultKey (seven : Bool) : CC.Ident := if seven then Arm64ProgramFixture._t'132 else Arm64ProgramFixture._t'131
def index (seven : Bool) : Fin 31 := if seven then 7 else 5

theorem source : Arm64ProgramEntryUaddlvCall.afterUaddlv =
    .Ssequence (.Ssequence (.Ssequence (call false) (call true)) (.Ssequence vector3 firstXor))
      (.Ssequence (.Ssequence vector0 secondXor) afterReads) := rfl

theorem call_source (seven : Bool) : call seven = .Scall (some (resultKey seven))
    (.Evar Arm64ProgramFixture._kprog_arm64_program_read
      (.Tfunction [CC.tptr (.Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr),CC.tulong]
        CC.tulong CC.cc_default))
    [.Eaddrof (.Evar Arm64ProgramFixture.___a64_entry
        (.Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr))
        (CC.tptr (.Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr)),
     .Econst_int (CC.Integers.Int.repr (if seven then 7 else 5)) CC.tint] := by
  cases seven <;> rfl

private theorem unshadowed (initial : CC.Mem) :
    (allocation initial).1.get Arm64ProgramFixture._kprog_arm64_program_read = none := by
  have outside : Arm64ProgramFixture._kprog_arm64_program_read ∉
      CC.varNames Arm64ProgramFixture.f_arm64_execute_compile.fn_vars := by decide +kernel
  simpa only [CC.emptyEnv,CC.PTree.gempty] using CC.allocVariables_env_other
    (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation initial)).symm) outside

private theorem eval_cons {e : CC.Env} {le : CC.TempEnv} {m : CC.Mem}
    {a : CC.Expr} {xs : List CC.Expr} {ty : CC.Ty} {tys : List CC.Ty}
    {v converted : CC.Val} {values : List CC.Val}
    (head : CC.doEvalExpr world e le m a = some v)
    (cast : CC.Cop.semCast v (CC.typeof a) ty m = some converted)
    (rest : CC.doEvalExprlist world e le m xs tys = some values) :
    CC.doEvalExprlist world e le m (a :: xs) (ty :: tys) = some (converted :: values) := by
  simp only [CC.doEvalExprlist,head,cast,rest]

private theorem call_step {initial : CC.Mem} (entry : HeaderLocal initial) (seven : Bool)
    (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    CC.Step2 world
      (.State Arm64ProgramFixture.f_arm64_execute_compile (call seven) k (allocation initial).1 le m) CC.E0
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read)
        [.Vptr entry.block 0,.Vlong (BitVec.ofNat 64 (index seven).val)]
        (.Kcall (some (resultKey seven)) Arm64ProgramFixture.f_arm64_execute_compile
          (allocation initial).1 le k) m) := by
  have header : (allocation initial).1.get Arm64ProgramFixture.___a64_entry =
      some (entry.block,.Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr) :=
    Arm64ProgramEntryAllocation.local_binding initial _ _ _ entry.binding
  have binding :
      CC.Genv.findSymbol world.genv_genv Arm64ProgramFixture._kprog_arm64_program_read = some (CC.Positive.ofNat 66) ∧
      CC.Genv.findFunctPtr world.genv_genv (CC.Positive.ofNat 66) =
        some (.Internal Arm64Program.f_kprog_arm64_program_read) := by
    constructor <;> run_tac Arm64ProgramEntryLinked.sourceEquality
  rw [call_source]
  apply CC.Step.call (tyargs := [CC.tptr (.Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr),CC.tulong])
    (tyres := CC.tulong) (cconv := CC.cc_default) (vf := .Vptr (CC.Positive.ofNat 66) 0)
  · rfl
  · apply CC.doEvalExpr_sound
    simp only [CC.doEvalExpr,CC.lvalOfVar,unshadowed initial,binding.1,CC.doDerefLoc,CC.accessMode]
    rfl
  · apply CC.doEvalExprlist_sound
    refine eval_cons (v := .Vptr entry.block 0) ?_ ?_ ?_
    · simp only [CC.doEvalExpr,CC.doEvalLvalue,CC.lvalOfVar,header]
      rfl
    · rfl
    refine eval_cons (v := .Vint (CC.Integers.Int.repr (if seven then 7 else 5))) ?_ ?_ ?_
    · rfl
    · cases seven <;> rfl
    · rfl
  · simpa +decide [CC.Genv.findFunct,CC.Integers.Ptrofs.eq,CC.Integers.Ptrofs.zero,
      CC.Integers.MI.eq,CC.Integers.MI.zero] using binding.2
  · rfl

/-- Either genuine fixture call executes the complete source reader. The
original scalar or warm-stack observation determines its numeric return;
all memory and its actual caller continuation are retained. -/
theorem read {initial : CC.Mem} (entry : HeaderLocal initial) (seven : Bool)
    (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (origins : Reference.Provenance.AArch64.Origins)
    (raw : BitVec 64) (tag : BitVec 8) (tags : tag = 0 ∨ tag = 4)
    (observed : Arm64EntryMemory.gpr m.nextblock m (.Vptr entry.block 0) (index seven).val =
      some (.Vlong raw,.Vint (tag.setWidth 32)))
    (cache : tag = 4 → Arm64RegisterReads.WarmEntryCache false m.nextblock m
      (.Vptr entry.block 0) origins.stack) :
    ∃ count, InternalRun world count
      (.State Arm64ProgramFixture.f_arm64_execute_compile (call seven) k (allocation initial).1 le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip k (allocation initial).1
        (le.set (resultKey seven) (.Vlong (Reference.Provenance.AArch64.materialize origins raw tag))) m) := by
  let cont := CC.Cont.Kcall (some (resultKey seven)) Arm64ProgramFixture.f_arm64_execute_compile
    (allocation initial).1 le k
  have enter : InternalRun world 1
      (.State Arm64ProgramFixture.f_arm64_execute_compile (call seven) k (allocation initial).1 le m)
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read)
        [.Vptr entry.block 0,.Vlong (BitVec.ofNat 64 (index seven).val)] cont m) :=
    .step (by rw [call_source]; trivial) (call_step entry seven le m k) (.refl _)
  have leave (value : BitVec 64) : InternalRun world 1
      (.Returnstate (.Vlong value) (CC.callCont cont) m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip k (allocation initial).1
        (le.set (resultKey seven) (.Vlong value)) m) :=
    .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  rcases tags with rfl|rfl
  · have run := Arm64RegisterReads.gpr_read_nonrelative_bound world Arm64MovKeep.Linked.reader_layout
      (fun _ => none) m.nextblock entry.block 0 (index seven) m cont (.Vlong raw) raw (0#8)
      observed rfl (by decide) (by decide)
    exact ⟨_,by simpa +decide only [Reference.Provenance.AArch64.materialize,ite_false] using
      (enter.trans run).trans (leave raw)⟩
  · have run := Arm64RegisterReads.gpr_read_stack_bound world Arm64MovKeep.Linked.reader_layout
      Arm64ProgramEntryColdRead.stack_layout m.nextblock entry.block 0 (index seven) m cont raw origins.stack
      observed (cache rfl)
    exact ⟨_,by simpa +decide only [Reference.Provenance.AArch64.materialize,ite_true] using
      (enter.trans run).trans (leave (raw+origins.stack))⟩

def readTemps (le : CC.TempEnv) (left right : BitVec 64) : CC.TempEnv :=
  (le.set Arm64ProgramFixture._t'131 (.Vlong left)).set Arm64ProgramFixture._t'132 (.Vlong right)

/-- Execute the two original calls in their real sequence, including both
actual reader entries, complete bodies and true caller returns. -/
theorem both {initial : CC.Mem} (entry : HeaderLocal initial) (le : CC.TempEnv) (m : CC.Mem)
    (k : CC.Cont) (origins : Reference.Provenance.AArch64.Origins)
    (left right : BitVec 64) (tag : BitVec 8) (tags : tag = 0 ∨ tag = 4)
    (lhs : Arm64EntryMemory.gpr m.nextblock m (.Vptr entry.block 0) 5 =
      some (.Vlong left,.Vint (tag.setWidth 32)))
    (rhs : Arm64EntryMemory.gpr m.nextblock m (.Vptr entry.block 0) 7 = some (.Vlong right,.Vint 0))
    (cache : tag = 4 → Arm64RegisterReads.WarmEntryCache false m.nextblock m
      (.Vptr entry.block 0) origins.stack) :
    ∃ count, InternalRun world count
      (.State Arm64ProgramFixture.f_arm64_execute_compile (.Ssequence (call false) (call true)) k
        (allocation initial).1 le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip k (allocation initial).1
        (readTemps le (Reference.Provenance.AArch64.materialize origins left tag) right) m) := by
  have enter : InternalRun world 1
      (.State Arm64ProgramFixture.f_arm64_execute_compile (.Ssequence (call false) (call true)) k
        (allocation initial).1 le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile (call false) (.Kseq (call true) k)
        (allocation initial).1 le m) := .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  obtain ⟨n1,first⟩ := read entry false le m (.Kseq (call true) k) origins left tag tags lhs cache
  have next : InternalRun world 1
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip (.Kseq (call true) k)
        (allocation initial).1 (le.set (resultKey false)
          (.Vlong (Reference.Provenance.AArch64.materialize origins left tag))) m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile (call true) k (allocation initial).1
        (le.set (resultKey false) (.Vlong (Reference.Provenance.AArch64.materialize origins left tag))) m) :=
    .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  obtain ⟨n2,last⟩ := read entry true (le.set (resultKey false) (.Vlong (Reference.Provenance.AArch64.materialize origins left tag))) m k origins right 0 (.inl rfl) rhs (by intro bad; cases bad)
  refine ⟨1+n1+1+n2,?_⟩
  simpa +decide only [readTemps,resultKey,ite_true,ite_false,Bool.false_eq_true,Reference.Provenance.AArch64.materialize]
    using ((enter.trans first).trans next).trans last

/-- The same complete source/register relation fixes the actual materialized
reader result. No independent native operand is a premise. -/
theorem native_word (addresses : Arm64Registers.PointerOrigins)
    (origins : Reference.Provenance.AArch64.Origins) (s : Reference.AArch64.State)
    (m : CC.Mem) (b : CC.Block) (i : Fin 31) (raw : BitVec 64) (tag : BitVec 8)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val) m.nextblock m (.Vptr b 0) s)
    (observed : Arm64EntryMemory.gpr m.nextblock m (.Vptr b 0) i.val =
      some (.Vlong raw,.Vint (tag.setWidth 32))) :
    Reference.AArch64.gpr s i = Reference.Provenance.AArch64.materialize origins raw tag := by
  obtain ⟨value,bits,kind,read,valueRep,physical⟩ := represented.gpr i
  have same := Option.some.inj (read.symm.trans observed)
  have valueEq : value = .Vlong raw := congrArg Prod.fst same
  have kindEq : kind = tag := by
    have widened := CC.Val.Vint.inj (congrArg Prod.snd same)
    simpa using congrArg (fun bits : BitVec 32 => bits.setWidth 8) widened
  have bitsEq : bits = raw := by
    simpa only [valueEq,Arm64Registers.ValueRep] using valueRep
  simpa only [bitsEq,kindEq] using physical

end KProgFormal.ClightRefinement.Arm64ProgramEntryResultRead
