import KProgFormal.ClightRefinement.X86ProducerScalarExecute

namespace KProgFormal.ClightRefinement.X86ProducerStackBaseSource
open X86ProducerHeaderSource (producer)
open X86ProducerHeaderLocals (SourceLocal)
open X86ProducerCacheAllocation (allocation)
open X86ProducerLayout (ge)
open X86RegisterWriteRspReleaseWord (inputFunction inputEF)

private structure Parts where
  zero : CC.Stmt
  afterZero : CC.Stmt
  call : CC.Stmt
  assignment : CC.Stmt
  finalSetup : CC.Stmt
  resultName : CC.Ident

private def parts : Parts := by
  run_tac do
    let body ← Lean.Meta.withTransparency .all (Lean.Meta.whnf
      (← Lean.Elab.Term.elabTerm (← `(X86ProducerScalarSource.following)) none))
    unless body.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original return-zero suffix changed"
    let tail ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body.getAppArgs[1]!)
    unless tail.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original stack-base/final-context sequence changed"
    let setup ← Lean.Meta.withTransparency .all (Lean.Meta.whnf tail.getAppArgs[0]!)
    unless setup.isAppOfArity ``CC.Stmt.Ssequence 2 do throwError "original stack-base call/store changed"
    let call ← Lean.Meta.withTransparency .all (Lean.Meta.whnf setup.getAppArgs[0]!)
    unless call.isAppOfArity ``CC.Stmt.Scall 3 do throwError "original stack-base provider changed"
    let result ← Lean.Meta.withTransparency .all (Lean.Meta.whnf call.getAppArgs[0]!)
    unless result.isAppOfArity ``Option.some 2 do throwError "original stack-base input result missing"
    Lean.Elab.Tactic.closeMainGoal `original_x86_stackbase_parts
      (← Lean.Meta.mkAppM ``Parts.mk #[body.getAppArgs[0]!,body.getAppArgs[1]!,setup.getAppArgs[0]!,
        setup.getAppArgs[1]!,tail.getAppArgs[1]!,result.getAppArgs[1]!])

def zero : CC.Stmt := parts.zero
def afterZero : CC.Stmt := parts.afterZero
def inputCall : CC.Stmt := parts.call
def assignment : CC.Stmt := parts.assignment
def finalSetup : CC.Stmt := parts.finalSetup
def resultName : CC.Ident := parts.resultName
def callCont (k : CC.Cont) : CC.Cont := .Kseq assignment (.Kseq finalSetup k)
def continuation (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) : CC.Cont :=
  .Kcall (some resultName) producer e le (callCont k)

/-- The actual return-zero and kind1 call/store/final-context sequence is kept. -/
theorem source_route : X86ProducerScalarSource.following = .Ssequence zero afterZero ∧
    afterZero = .Ssequence (.Ssequence inputCall assignment) finalSetup := by constructor <;> rfl

theorem source_zero : zero = .Sassign (.Evar X86_program_profile_bpf.___x86_sim_ret_addr CC.tulong)
    (.Econst_int (CC.Integers.Int.repr 0) CC.tint) := by rfl

theorem source_call : inputCall = .Scall (some resultName)
    (.Evar X86_program_profile_bpf._native_lab_entry_input (.Tfunction [CC.tuint] CC.tulong CC.cc_default))
    [.Econst_int (CC.Integers.Int.repr 1) CC.tint] := by rfl

theorem source_assignment : assignment = .Sassign (.Evar X86_program_profile_bpf.___x86_native_stack_base CC.tulong)
    (.Etempvar resultName CC.tulong) := by rfl

/-- The actual return-address zero store is derived from its own original
allocated eight-byte local, preserving all other supplied-memory blocks. -/
theorem return_zero (before memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (ret : SourceLocal ge.genv_cenv before 23)
    (access : memory.access = (allocation ge.genv_cenv before).2.access) :
    ∃ after, InternalRun ge 3
      (.State producer X86ProducerScalarSource.following k (allocation ge.genv_cenv before).1 le memory)
      (.State producer afterZero k (allocation ge.genv_cenv before).1 le after) ∧
    CC.Mem.store .Mint64 memory ret.block 0 (.Vlong 0) = some after ∧
    CC.Mem.load .Mint64 after ret.block 0 = some (.Vlong 0) ∧
    (∀ c b ofs, b ≠ ret.block → CC.Mem.load c after b ofs = CC.Mem.load c memory b ofs) ∧
    FrameBelow before.nextblock memory after ∧ after.access = memory.access ∧ after.nextblock = memory.nextblock := by
  obtain ⟨after, run, stored, read, outside, frame, rights, next⟩ :=
    X86ProducerScalarStore.write before memory le k afterZero 9 ret (.Econst_int (CC.Integers.Int.repr 0) CC.tint)
      (.Vint 0) (.Vlong 0) rfl rfl rfl access
  refine ⟨after, ?_, stored, read, outside, frame, rights, next⟩
  rw [source_route.1]
  exact .step trivial (CC.doStep_sound ge _ _ _ rfl) run

/-- The genuine next provider call has kind1, not kind6. Original global
binding and unshadowed allocated environment reach its actual Callstate;
no kind1 provider outcome or memory ABI is asserted. -/
theorem enter (before memory : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) :
    InternalRun ge 3 (.State producer afterZero k (allocation ge.genv_cenv before).1 le memory)
      (.Callstate inputFunction [.Vint (1#32)] (continuation (allocation ge.genv_cenv before).1 le k) memory) := by
  have allocated := CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation ge.genv_cenv before)).symm
  have absent : X86_program_profile_bpf._native_lab_entry_input ∉ CC.varNames producer.fn_vars := by decide +kernel
  have notLocal : (allocation ge.genv_cenv before).1.get X86_program_profile_bpf._native_lab_entry_input = none := by
    simpa only [CC.emptyEnv, CC.PTree.gempty] using CC.allocVariables_env_other allocated absent
  have call : CC.doStep ge (.State producer inputCall (callCont k) (allocation ge.genv_cenv before).1 le memory) =
      some (CC.E0, .Callstate inputFunction [.Vint (1#32)] (continuation (allocation ge.genv_cenv before).1 le k) memory) := by
    simp +decide [source_call, continuation, CC.doStep, CC.doEvalExpr, CC.doEvalExprlist,
      CC.lvalOfVar, notLocal, CC.doDerefLoc, CC.accessMode, CC.typeof,
      X86ProducerFirstInput.input_binding.1, X86ProducerFirstInput.input_binding.2,
      CC.Genv.findFunct, CC.Cop.classifyFun, inputFunction, inputEF,
      CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt, CC.tuint, CC.tint, CC.tulong]
  rw [source_route.2]
  exact .step trivial (CC.doStep_sound ge _ _ _ rfl)
    (.step trivial (CC.doStep_sound ge _ _ _ rfl)
      (.step trivial (CC.doStep_sound ge _ _ _ call) (.refl _)))

end KProgFormal.ClightRefinement.X86ProducerStackBaseSource
