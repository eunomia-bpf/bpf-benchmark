import KProgFormal.ClightRefinement.Arm64ProgramEntryTerminalLoop

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryTerminalRead
open Arm64Producer (HeaderLocal HeaderSourceLocal)
open Arm64ProgramEntryAllocation (world allocation)
open Arm64ProgramEntryTerminalLoop (callRead)

def temps (le : CC.TempEnv) (value : BitVec 64) : CC.TempEnv := le.set Arm64ProgramFixture._t'148 (.Vlong value)

theorem call_source : callRead = .Scall (some Arm64ProgramFixture._t'148)
    (.Evar Arm64ProgramFixture._kprog_arm64_program_read
      (.Tfunction [CC.tptr (.Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr),CC.tulong] CC.tulong CC.cc_default))
    [.Eaddrof (.Evar Arm64ProgramFixture.___a64_entry (.Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr))
       (CC.tptr (.Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr)),.Econst_int (0#32) CC.tuint] := rfl

private theorem unshadowed (initial : CC.Mem) : (allocation initial).1.get Arm64ProgramFixture._kprog_arm64_program_read = none := by
  have outside : Arm64ProgramFixture._kprog_arm64_program_read ∉ CC.varNames Arm64ProgramFixture.f_arm64_execute_compile.fn_vars := by decide +kernel
  simpa only [CC.emptyEnv,CC.PTree.gempty] using CC.allocVariables_env_other
    (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation initial)).symm) outside

private theorem eval_cons {e : CC.Env} {le : CC.TempEnv} {m : CC.Mem}
    {a : CC.Expr} {xs : List CC.Expr} {ty : CC.Ty} {tys : List CC.Ty} {v converted : CC.Val} {values : List CC.Val}
    (head : CC.doEvalExpr world e le m a = some v)
    (cast : CC.Cop.semCast v (CC.typeof a) ty m = some converted)
    (rest : CC.doEvalExprlist world e le m xs tys = some values) :
    CC.doEvalExprlist world e le m (a :: xs) (ty :: tys) = some (converted :: values) := by
  simp only [CC.doEvalExprlist,head,cast,rest]

theorem call_step {initial : CC.Mem} (entry : HeaderLocal initial) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) :
    CC.Step2 world (.State Arm64ProgramFixture.f_arm64_execute_compile callRead k (allocation initial).1 le m) CC.E0
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read) [.Vptr entry.block 0,.Vlong 0]
        (.Kcall (some Arm64ProgramFixture._t'148) Arm64ProgramFixture.f_arm64_execute_compile (allocation initial).1 le k) m) := by
  have header : (allocation initial).1.get Arm64ProgramFixture.___a64_entry =
      some (entry.block,.Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr) :=
    Arm64ProgramEntryAllocation.local_binding initial _ _ _ entry.binding
  have binding : CC.Genv.findSymbol world.genv_genv Arm64ProgramFixture._kprog_arm64_program_read = some (CC.Positive.ofNat 66) ∧
      CC.Genv.findFunctPtr world.genv_genv (CC.Positive.ofNat 66) = some (.Internal Arm64Program.f_kprog_arm64_program_read) := by
    have name : Arm64ProgramFixture._kprog_arm64_program_read = Arm64Program._kprog_arm64_program_read := rfl
    simpa only [Arm64ProgramEntryAllocation.world,name] using Arm64MovKeep.Linked.reader_binding
  rw [call_source]
  apply CC.Step.call (tyargs := [CC.tptr (.Tstruct Arm64ProgramFixture._kprog_arm64_entry CC.noattr),CC.tulong])
    (tyres := CC.tulong) (cconv := CC.cc_default) (vf := .Vptr (CC.Positive.ofNat 66) 0)
  · rfl
  · apply CC.doEvalExpr_sound
    simp only [CC.doEvalExpr,CC.lvalOfVar,unshadowed initial,binding.1,CC.doDerefLoc,CC.accessMode]
    rfl
  · apply CC.doEvalExprlist_sound
    refine eval_cons (v := .Vptr entry.block 0) ?_ (by rfl) ?_
    · simp only [CC.doEvalExpr,CC.doEvalLvalue,CC.lvalOfVar,header]
      rfl
    exact eval_cons (v := .Vint (0#32)) (by rfl) (by rfl) (by rfl)
  · simpa +decide [CC.Genv.findFunct,CC.Integers.Ptrofs.eq,CC.Integers.Ptrofs.zero,
      CC.Integers.MI.eq,CC.Integers.MI.zero] using binding.2
  · rfl

/-- The complete original combined reader returns the genuine terminal scalar
with tag0; the full helper and true caller take75 source transitions. -/
theorem invoke {initial : CC.Mem} (entry : HeaderLocal initial) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (value : BitVec 64)
    (observed : Arm64EntryMemory.gpr m.nextblock m (.Vptr entry.block 0) 0 = some (.Vlong value,.Vint (0#32))) :
    InternalRun world 75
      (.State Arm64ProgramFixture.f_arm64_execute_compile callRead k (allocation initial).1 le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip k (allocation initial).1 (temps le value) m) := by
  let cont := CC.Cont.Kcall (some Arm64ProgramFixture._t'148) Arm64ProgramFixture.f_arm64_execute_compile (allocation initial).1 le k
  have enter : InternalRun world 1
      (.State Arm64ProgramFixture.f_arm64_execute_compile callRead k (allocation initial).1 le m)
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read) [.Vptr entry.block 0,.Vlong 0] cont m) :=
    .step (by rw [call_source]; trivial) (call_step entry le m k) (.refl _)
  have actual : Arm64EntryMemory.gpr m.nextblock m (.Vptr entry.block 0) (0 : Fin 31).val =
      some (.Vlong value,.Vint ((0#8).setWidth 32)) := by
    simpa only [show (0 : Fin 31).val = 0 by decide +kernel,
      show (0#8).setWidth 32 = (0#32) by decide +kernel] using observed
  have helper := Arm64RegisterReads.gpr_read_nonrelative_bound world Arm64MovKeep.Linked.reader_layout (fun _ => none)
    m.nextblock entry.block 0 (0 : Fin 31) m cont (.Vlong value) value (0#8) actual rfl (by decide) (by decide)
  have leave : InternalRun world 1 (.Returnstate (.Vlong value) (CC.callCont cont) m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip k (allocation initial).1 (temps le value) m) :=
    .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  exact (enter.trans helper).trans leave

/-- Actual SP guard, complete read0 helper/caller and real sequence resume
reach the original uint32 Sreturn on the same terminal memory. -/
theorem execute {initial : CC.Mem} (entry : HeaderLocal initial) (sp : HeaderSourceLocal initial 5)
    (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (value : BitVec 64)
    (spRead : CC.Mem.load .Mint64 m sp.block 0 = some (.Vlong 0))
    (observed : Arm64EntryMemory.gpr m.nextblock m (.Vptr entry.block 0) 0 = some (.Vlong value,.Vint (0#32))) :
    InternalRun world 85
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryTerminalStores.tail k (allocation initial).1 le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryTerminalLoop.ret (Arm64ProgramEntryTerminalLoop.loopCont k)
        (allocation initial).1 (temps (Arm64ProgramEntryTerminalLoop.temps le) value) m) := by
  have loop := Arm64ProgramEntryTerminalLoop.execute sp le m k spRead
  have read := invoke entry (Arm64ProgramEntryTerminalLoop.temps le) m (Arm64ProgramEntryTerminalLoop.callCont k) value observed
  have resume : InternalRun world 1
      (.State Arm64ProgramFixture.f_arm64_execute_compile .Sskip (Arm64ProgramEntryTerminalLoop.callCont k)
        (allocation initial).1 (temps (Arm64ProgramEntryTerminalLoop.temps le) value) m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryTerminalLoop.ret (Arm64ProgramEntryTerminalLoop.loopCont k)
        (allocation initial).1 (temps (Arm64ProgramEntryTerminalLoop.temps le) value) m) :=
    .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  exact (loop.trans read).trans resume

end KProgFormal.ClightRefinement.Arm64ProgramEntryTerminalRead
