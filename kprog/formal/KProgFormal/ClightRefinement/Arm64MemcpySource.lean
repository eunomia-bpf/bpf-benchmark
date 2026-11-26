import KProgFormal.ClightRefinement.Arm64MemcpyLengthComplete

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpySource

open Arm64Producer
open Arm64ProgramEntryAllocation (world)

abbrev handler := Arm64Program.f_kprog_arm64_program_memcpy

private structure Parts where
  body : CC.Stmt
  lengthRead : CC.Stmt
  lengthSet : CC.Stmt
  afterLength : CC.Stmt

private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor 2 do throwError "original memcpy entry source changed"
      pure actual.getAppArgs
    let loop ← peel (← Lean.Elab.Term.elabTerm (← `(handler.fn_body)) none) ``CC.Stmt.Sloop
    let outer ← peel loop[0]! ``CC.Stmt.Ssequence
    let first ← peel outer[0]! ``CC.Stmt.Ssequence
    Lean.Elab.Tactic.closeMainGoal `actual_memcpy_entry_parts
      (← Lean.Meta.mkAppM ``Parts.mk #[loop[0]!,first[0]!,first[1]!,outer[1]!])
private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_memcpy_entry_part (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))
private def body : CC.Stmt := by run_tac cachePart (← `(parts.body))
def lengthRead : CC.Stmt := by run_tac cachePart (← `(parts.lengthRead))
private def lengthSet : CC.Stmt := by run_tac cachePart (← `(parts.lengthSet))
def afterLength : CC.Stmt := by run_tac cachePart (← `(parts.afterLength))
def continuation (k : CC.Cont) : CC.Cont := .Kloop1 body .Sbreak k

theorem body_source : handler.fn_body = .Sloop (.Ssequence (.Ssequence lengthRead lengthSet) afterLength) .Sbreak := rfl
theorem read_source : lengthRead = .Scall (some Arm64Program._t'1)
    (.Evar Arm64Program._kprog_arm64_program_read
      (.Tfunction [CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr),CC.tulong] CC.tulong CC.cc_default))
    [.Etempvar Arm64Program._entry (CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr)),
     .Econst_int (CC.Integers.Int.repr 2) CC.tuint] := rfl

private def tempList : List (CC.Ident × CC.Ty) := by run_tac cachePart (← `(handler.fn_temps))
private def undefTemps : CC.TempEnv := CC.createUndefTemps tempList
def initialTemps (entry : CC.Block) : CC.TempEnv := undefTemps.set Arm64Program._entry (.Vptr entry 0)
def lengthTemps (entry : CC.Block) (length : BitVec 64) : CC.TempEnv :=
  ((initialTemps entry).set Arm64Program._t'1 (.Vlong length)).set Arm64Program.___a64_lib_len (.Vlong length)

def allocation (before : CC.Mem) : CC.Env × CC.Mem :=
  CC.doAllocVariables world.genv_cenv CC.emptyEnv before handler.fn_vars

theorem locals_source : handler.fn_vars = Arm64MemsetSource.handler.fn_vars := rfl
theorem allocated (before : CC.Mem) :
    CC.AllocVariables world.genv_cenv CC.emptyEnv before handler.fn_vars (allocation before).1 (allocation before).2 :=
  CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation before)).symm

theorem entry_frame (before : CC.Mem) : FrameBelow before.nextblock before (allocation before).2 :=
  (FrameBelow.allocVariables (allocated before) before.nextblock (Nat.le_refl _)).2

theorem entry_valid (before : CC.Mem) (entry : CC.Block) :
    CC.FunctionEntry2 world handler [.Vptr entry 0] before (allocation before).1 (initialTemps entry) (allocation before).2 := by
  apply CC.FunctionEntry2.intro
  · decide +kernel
  · decide +kernel
  · change CC.listDisjoint [Arm64Program._entry] _
    intro id present other
    have eq : id = Arm64Program._entry := by simpa only [List.mem_singleton] using present
    subst id
    have chunks :
        Arm64Program._entry ∉ CC.varNames Arm64Program.l_kprog_arm64_program_memcpy_temps_0 ∧
        Arm64Program._entry ∉ CC.varNames Arm64Program.l_kprog_arm64_program_memcpy_temps_1 ∧
        Arm64Program._entry ∉ CC.varNames Arm64Program.l_kprog_arm64_program_memcpy_temps_2 ∧
        Arm64Program._entry ∉ CC.varNames Arm64Program.l_kprog_arm64_program_memcpy_temps_3 := by
      constructor
      · decide +kernel
      constructor
      · decide +kernel
      constructor <;> decide +kernel
    change Arm64Program._entry ∈ CC.varNames
      ((Arm64Program.l_kprog_arm64_program_memcpy_temps_0 ++ Arm64Program.l_kprog_arm64_program_memcpy_temps_1) ++
       (Arm64Program.l_kprog_arm64_program_memcpy_temps_2 ++ Arm64Program.l_kprog_arm64_program_memcpy_temps_3)) at other
    simp only [CC.varNames,List.map_append,List.mem_append] at other
    exact other.elim (fun h => h.elim chunks.1 chunks.2.1) (fun h => h.elim chunks.2.2.1 chunks.2.2.2)
  · exact allocated before
  · rfl

private theorem unshadowed (before : CC.Mem) :
    (allocation before).1.get Arm64Program._kprog_arm64_program_read = none := by
  have outside : Arm64Program._kprog_arm64_program_read ∉ CC.varNames handler.fn_vars := by decide +kernel
  simpa only [CC.emptyEnv,CC.PTree.gempty] using CC.allocVariables_env_other (allocated before) outside

theorem call_step (before memory : CC.Mem) (entry : CC.Block) (le : CC.TempEnv) (k : CC.Cont)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0)) :
    CC.Step2 world (.State handler lengthRead k (allocation before).1 le memory) CC.E0
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read) [.Vptr entry 0,.Vlong (2#64)]
        (.Kcall (some Arm64Program._t'1) handler (allocation before).1 le k) memory) := by
  have binding : CC.Genv.findSymbol world.genv_genv Arm64Program._kprog_arm64_program_read = some (CC.Positive.ofNat 66) ∧
      CC.Genv.findFunctPtr world.genv_genv (CC.Positive.ofNat 66) = some (.Internal Arm64Program.f_kprog_arm64_program_read) := by
    constructor <;> run_tac Arm64ProgramEntryLinked.sourceEquality
  rw [read_source]
  apply CC.Step.call (tyargs := [CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr),CC.tulong])
    (tyres := CC.tulong) (cconv := CC.cc_default) (vf := .Vptr (CC.Positive.ofNat 66) 0)
  · rfl
  · apply CC.doEvalExpr_sound
    simp only [CC.doEvalExpr,CC.lvalOfVar,unshadowed before,binding.1,CC.doDerefLoc,CC.accessMode]
    rfl
  · apply CC.doEvalExprlist_sound
    simp only [CC.doEvalExprlist,CC.doEvalExpr,hentry]
    rfl
  · simpa +decide [CC.Genv.findFunct,CC.Integers.Ptrofs.eq,CC.Integers.Ptrofs.zero,
      CC.Integers.MI.eq,CC.Integers.MI.zero] using binding.2
  · rfl

/-- The genuine length call reuses the imported scalar reader and restores
this memcpy caller's actual temp map on the same reached heap. -/
theorem length_read (before memory : CC.Mem) (entry frontier : CC.Block) (le : CC.TempEnv) (k : CC.Cont)
    (length : BitVec 64) (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (observed : Arm64EntryMemory.gpr frontier memory (.Vptr entry 0) 2 = some (.Vlong length,.Vint 0)) :
    InternalRun world 75 (.State handler lengthRead k (allocation before).1 le memory)
      (.State handler .Sskip k (allocation before).1 (le.set Arm64Program._t'1 (.Vlong length)) memory) := by
  let cont := CC.Cont.Kcall (some Arm64Program._t'1) handler (allocation before).1 le k
  have enter : InternalRun world 1 (.State handler lengthRead k (allocation before).1 le memory)
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read) [.Vptr entry 0,.Vlong (2#64)] cont memory) :=
    .step (by rw [read_source]; trivial) (call_step before memory entry le k hentry) (.refl _)
  have reader := Arm64RegisterReads.gpr_read_nonrelative_bound world Arm64MovKeep.Linked.reader_layout
    (fun _ => none) frontier entry 0 (2 : Fin 31) memory cont (.Vlong length) length (0#8)
    observed rfl (by decide) (by decide)
  have leave : InternalRun world 1 (.Returnstate (.Vlong length) (CC.callCont cont) memory)
      (.State handler .Sskip k (allocation before).1 (le.set Arm64Program._t'1 (.Vlong length)) memory) :=
    .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  exact (enter.trans reader).trans leave

/-- Execute actual FunctionEntry2, the real length call and original set into
lib_len, reaching the source-tag loop with the original eight locals live. -/
theorem enter_length (before : CC.Mem) (entry : CC.Block) (length : BitVec 64) (k : CC.Cont)
    (observed : Arm64EntryMemory.gpr before.nextblock before (.Vptr entry 0) 2 = some (.Vlong length,.Vint 0)) :
    InternalRun world 82 (.Callstate (.Internal handler) [.Vptr entry 0] k before)
      (.State handler afterLength (continuation k) (allocation before).1 (lengthTemps entry length) (allocation before).2) := by
  let e := (allocation before).1
  let m := (allocation before).2
  let le := initialTemps entry
  have start : InternalRun world 4 (.Callstate (.Internal handler) [.Vptr entry 0] k before)
      (.State handler lengthRead (.Kseq lengthSet (.Kseq afterLength (continuation k))) e le m) := by
    refine .step trivial (.internal_function _ _ _ _ _ _ _ (entry_valid before entry)) ?_
    rw [body_source]
    exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.step trivial (CC.doStep_sound _ _ _ _ rfl)
      (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)))
  have read := length_read before m entry before.nextblock le (.Kseq lengthSet (.Kseq afterLength (continuation k))) length
    (by simp only [le,initialTemps,CC.PTree.gss]) ((Arm64EntryMemory.gpr_frame (entry_frame before) _ 2).trans observed)
  have finish : InternalRun world 3 (.State handler .Sskip (.Kseq lengthSet (.Kseq afterLength (continuation k))) e
      (le.set Arm64Program._t'1 (.Vlong length)) m)
      (.State handler afterLength (continuation k) e (lengthTemps entry length) m) := by
    apply internalRun_of_steps
    · simp +decide [InternalPath,InternalState,steps,CC.doStep,lengthSet,CC.doEvalExpr,CC.PTree.gss]
    · simp +decide [steps,CC.doStep,lengthSet,CC.doEvalExpr,CC.PTree.gss,lengthTemps,le]
  exact (start.trans read).trans finish

/-- The preceding real MOV store supplies this original length read. -/
theorem current_length {initial seed before : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (prior : Arm64MemsetPointerState.Packet base abi byte (Arm64MemcpyLengthState.words gprs) flags values before)
    (k : CC.Cont) :
    InternalRun world 82 (.Callstate (.Internal handler) [.Vptr entry.block 0] k before)
      (.State handler afterLength (continuation k) (allocation before).1 (lengthTemps entry.block (16#64)) (allocation before).2) := by
  apply enter_length
  have position : (Arm64MemsetClobberRegisters.declaration 1).reg.val = 2 := rfl
  simpa +decide [Arm64MemcpyLengthState.words,position] using prior.registers (1 : Fin 18) (by decide)

end KProgFormal.ClightRefinement.Arm64MemcpySource
