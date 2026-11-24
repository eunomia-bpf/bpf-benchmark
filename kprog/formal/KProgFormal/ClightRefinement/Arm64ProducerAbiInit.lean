import KProgFormal.ClightRefinement.Arm64ProgramEntryPrefix

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProducerAbiInit

open Arm64ProgramEntryAllocation (world allocation)

private def earlier : List CC.Stmt := Arm64Producer.cachePrefix.dropLast

def statement : CC.Stmt := by
  run_tac do
    let term ← Lean.Elab.Term.elabTerm (← `(Arm64Producer.cachePrefix)) none
    let mut rows := term
    let mut last : Option Lean.Expr := none
    for _ in [:190] do
      let value ← Lean.Meta.withTransparency .all (Lean.Meta.whnf rows)
      if value.isAppOfArity ``List.nil 1 then
        match last with
        | none => throwError "original ABI initializer prefix is empty"
        | some actual =>
          Lean.Elab.Tactic.closeMainGoal `actual_producer_abi_initializer actual
          return
      unless value.isAppOfArity ``List.cons 3 do
        throwError "original ABI initializer prefix changed"
      last := some value.getAppArgs[1]!
      rows := value.getAppArgs[2]!
    throwError "original ABI initializer prefix exceeds actual count"

theorem source : statement = .Sassign (.Evar Arm64Entry.___a64_sim_abi_kind CC.tuchar)
    (.Econst_int (CC.Integers.Int.repr 2) CC.tuint) := rfl
private theorem prefix_source : Arm64Producer.cachePrefix = earlier ++ [statement] := by
  have nonempty : Arm64Producer.cachePrefix ≠ [] := by decide +kernel
  have actual : Arm64Producer.cachePrefix.getLast (by decide +kernel) = statement := by
    run_tac do
      let proof ← Lean.Meta.mkEqRefl (Lean.mkConst ``statement)
      Lean.Elab.Tactic.closeMainGoal `actual_last_initializer proof
  simpa only [earlier,actual] using (List.dropLast_concat_getLast nonempty).symm
private theorem earlier_length : earlier.length = 188 := by decide +kernel

private def isAssignment : CC.Stmt → Bool
  | .Sassign .. => true
  | _ => false

private theorem earlier_assignments : ∀ stmt ∈ earlier, ∃ lhs rhs, stmt = .Sassign lhs rhs := by
  have checked : earlier.all isAssignment = true := by decide +kernel
  intro stmt member
  have actual := List.all_eq_true.mp checked stmt member
  cases stmt <;> simp only [isAssignment,Bool.false_eq_true] at actual
  exact ⟨_,_,rfl⟩

private theorem cancel_prefix {ge : CC.CGenv} {n m : Nat} {start middle last : CC.State}
    (headRun : InternalRun ge n start middle) (whole : InternalRun ge (n+m) start last) :
    InternalRun ge m middle last := by
  induction headRun with
  | refl _ => simpa using whole
  | @step n start next middle hs step tail ih =>
    have reordered : InternalRun ge ((n+m)+1) start last := by
      simpa only [Nat.add_assoc,Nat.add_comm,Nat.add_left_comm] using whole
    cases reordered with
    | step _ other remaining =>
      have same := (internal_step_unique hs step other).2
      cases same
      exact ih remaining

/-- Peel actual assignment/sequence transitions, preserving the real suffix
execution and intermediate heap. The input is an existing source certificate. -/
private theorem assignment_suffix {ge : CC.CGenv} (front : List CC.Stmt)
    (plain : ∀ stmt ∈ front, ∃ lhs rhs, stmt = .Sassign lhs rhs)
    (f : CC.Function) (rest : CC.Stmt) (k : CC.Cont) (e : CC.Env) (le : CC.TempEnv)
    (n : Nat) (memory : CC.Mem) (last : CC.State)
    (run : InternalRun ge (3 * front.length + n)
      (.State f (front.foldr CC.Stmt.Ssequence rest) k e le memory) last) :
    ∃ middle, InternalRun ge n (.State f rest k e le middle) last := by
  induction front generalizing memory with
  | nil => exact ⟨memory,by simpa only [List.foldr,List.length_nil,Nat.mul_zero,Nat.zero_add] using run⟩
  | cons head tail ih =>
    obtain ⟨lhs,rhs,rfl⟩ := plain head (by simp)
    have count : 3 * (CC.Stmt.Sassign lhs rhs :: tail).length + n = ((3 * tail.length+n)+1)+1+1 := by
      simp only [List.length_cons]
      omega
    rw [count] at run
    simp only [List.foldr] at run
    cases run with
    | step _ first following =>
      cases first <;> try (simp_all [CC.isCallCont]; done)
      cases following with
      | step _ assigned following =>
        cases assigned
        cases following with
        | step _ skip following =>
          cases skip <;> try (simp_all [CC.isCallCont]; done)
          exact ih (fun stmt member => plain stmt (List.mem_cons.mpr (.inr member))) _ following

private theorem last_read (ge : CC.CGenv) (f : CC.Function) (rest : CC.Stmt) (k : CC.Cont)
    (e : CC.Env) (le : CC.TempEnv) (memory after : CC.Mem) (block : CC.Block)
    (binding : e.get Arm64Entry.___a64_sim_abi_kind = some (block,CC.tuchar))
    (run : InternalRun ge 3 (.State f (.Ssequence statement rest) k e le memory)
      (.State f rest k e le after)) :
    CC.Mem.load .Mint8unsigned after block 0 = some (.Vint 2) := by
  rw [source] at run
  cases run with
  | step _ first following =>
    cases first <;> try (simp_all [CC.isCallCont]; done)
    cases following with
    | step _ assigned following =>
      cases assigned with
      | assign _ _ _ _ _ _ _ loc ofs bf v2 v middle hlv he hc ha =>
        have own : CC.EvalLvalue ge e le memory (.Evar Arm64Entry.___a64_sim_abi_kind CC.tuchar) block 0 .Full :=
          .Evar_local _ _ _ binding
        obtain ⟨sameBlock,sameOffset,sameBits⟩ := CC.evalLvalue_determ hlv own
        cases sameBlock
        cases sameOffset
        cases sameBits
        have sameValue := CC.evalExpr_determ he (.Econst_int (CC.Integers.Int.repr 2) CC.tuint)
        cases sameValue
        have cast : CC.Cop.semCast (.Vint (CC.Integers.Int.repr 2)) CC.tuint CC.tuchar memory = some (.Vint 2) := rfl
        change CC.Cop.semCast (.Vint (CC.Integers.Int.repr 2)) CC.tuint CC.tuchar memory = some v at hc
        rw [cast] at hc
        cases Option.some.inj hc
        cases ha with
        | value _ chunk _ mode stored =>
          simp only [CC.accessMode,CC.tuchar] at mode
          cases mode
          cases following with
          | step _ skip following =>
            cases skip <;> try (simp_all [CC.isCallCont]; done)
            cases following
            change CC.Mem.store .Mint8unsigned memory block 0 (.Vint 2) = some after at stored
            have normalized : CC.Val.loadResult .Mint8unsigned (.Vint 2) = .Vint 2 := by decide +kernel
            simpa only [normalized] using CC.Mem.load_store_same stored

/-- Readback of the actual ABI initializer follows any complete original
568-step production prefix certificate. No byte-read success is assumed. -/
theorem observed (initial before : CC.Mem) (ctx : CC.Val) (k : CC.Cont)
    (kind : Arm64Producer.TailLocal initial 6)
    (run : InternalRun world 568
      (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [ctx] k initial)
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryPrefix.cacheStage k
        (allocation initial).1 (Arm64ProgramEntryCall.initialTemps ctx) before)) :
    CC.Mem.load .Mint8unsigned before kind.block 0 = some (.Vint 2) := by
  have binding := Arm64ProgramEntryAllocation.local_binding initial _ _ _ kind.binding
  have name : Arm64ProgramEntryAllocation.localName (Arm64Producer.tailLocalName 6) = Arm64Entry.___a64_sim_abi_kind := by decide +kernel
  have type : Arm64ProgramEntryAllocation.localType (Arm64Producer.tailLocalType 6) = CC.tuchar := rfl
  rw [name,type] at binding
  have tail : InternalRun world 567
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramFixture.f_arm64_execute_compile.fn_body k
        (allocation initial).1 (Arm64ProgramEntryCall.initialTemps ctx) (allocation initial).2)
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryPrefix.cacheStage k
        (allocation initial).1 (Arm64ProgramEntryCall.initialTemps ctx) before) :=
    cancel_prefix (Arm64ProgramEntryCall.entry_internal initial ctx k) (by simpa using run)
  rw [Arm64ProgramEntryPrefix.prefix_source,prefix_source,List.foldr_append] at tail
  have complete : InternalRun world (3 * earlier.length+3)
      (.State Arm64ProgramFixture.f_arm64_execute_compile
        (earlier.foldr CC.Stmt.Ssequence (.Ssequence statement Arm64ProgramEntryPrefix.cacheStage)) k
        (allocation initial).1 (Arm64ProgramEntryCall.initialTemps ctx) (allocation initial).2)
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryPrefix.cacheStage k
        (allocation initial).1 (Arm64ProgramEntryCall.initialTemps ctx) before) := by
    have count : 3 * earlier.length+3 = 567 := by rw [earlier_length]
    rw [count]
    simpa only [List.foldr] using tail
  obtain ⟨middle,last⟩ := assignment_suffix earlier earlier_assignments _ _ _ _ _ 3 _ _ complete
  exact last_read world _ _ _ _ _ middle before kind.block binding last

/-- The existing real prefix execution retains its access, frontier and caller
frame together with the actual ABI byte produced by that same execution. -/
theorem prefix_with_kind (initial : CC.Mem) (ctx : CC.Val) (k : CC.Cont) (kind : Arm64Producer.TailLocal initial 6) :
    ∃ before, InternalRun world 568
      (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [ctx] k initial)
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryPrefix.cacheStage k
        (allocation initial).1 (Arm64ProgramEntryCall.initialTemps ctx) before) ∧
      before.access = (allocation initial).2.access ∧ before.nextblock = (allocation initial).2.nextblock ∧
      FrameBelow initial.nextblock initial before ∧
      CC.Mem.load .Mint8unsigned before kind.block 0 = some (.Vint 2) := by
  obtain ⟨before,run,access,next,frame⟩ := Arm64ProgramEntryPrefix.prefix_internal initial ctx k
  exact ⟨before,run,access,next,frame,observed initial before ctx k kind run⟩

end KProgFormal.ClightRefinement.Arm64ProducerAbiInit
