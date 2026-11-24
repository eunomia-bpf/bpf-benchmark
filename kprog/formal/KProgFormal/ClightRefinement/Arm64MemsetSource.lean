import KProgFormal.ClightRefinement.Arm64ProgramEntryOrdinaryMoves
import KProgFormal.ClightRefinement.Arm64MovKeepLinked

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemsetSource

open Arm64ProgramEntryAllocation (world)

abbrev handler := Arm64Program.f_kprog_arm64_program_memset

private structure Parts where
  body : CC.Stmt
  byteRead : CC.Stmt
  byteSet : CC.Stmt
  lengthRead : CC.Stmt
  lengthSet : CC.Stmt
  afterReads : CC.Stmt

private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor 2 do
        throwError "original memset control changed"
      pure actual.getAppArgs
    let loop ← peel (← Lean.Elab.Term.elabTerm (← `(handler.fn_body)) none) ``CC.Stmt.Sloop
    let outer ← peel loop[0]! ``CC.Stmt.Ssequence
    let byte ← peel outer[0]! ``CC.Stmt.Ssequence
    let rest ← peel outer[1]! ``CC.Stmt.Ssequence
    let length ← peel rest[0]! ``CC.Stmt.Ssequence
    Lean.Elab.Tactic.closeMainGoal `actual_memset_parts
      (← Lean.Meta.mkAppM ``Parts.mk #[loop[0]!,byte[0]!,byte[1]!,length[0]!,length[1]!,rest[1]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_memset_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private def body : CC.Stmt := by run_tac cachePart (← `(parts.body))
private def byteSet : CC.Stmt := by run_tac cachePart (← `(parts.byteSet))
private def lengthSet : CC.Stmt := by run_tac cachePart (← `(parts.lengthSet))
def afterReads : CC.Stmt := by run_tac cachePart (← `(parts.afterReads))
private def byteRead : CC.Stmt := by run_tac cachePart (← `(parts.byteRead))
private def lengthRead : CC.Stmt := by run_tac cachePart (← `(parts.lengthRead))
def read (length : Bool) : CC.Stmt := if length then lengthRead else byteRead

def resultKey (length : Bool) : CC.Ident := if length then Arm64Program._t'2 else Arm64Program._t'1
def index (length : Bool) : Fin 31 := if length then 2 else 1
private def firstPart : CC.Stmt := .Ssequence (read false) byteSet
private def secondPart : CC.Stmt := .Ssequence (read true) lengthSet
private def rest : CC.Stmt := .Ssequence secondPart afterReads
def continuation (k : CC.Cont) : CC.Cont := .Kloop1 body .Sbreak k

theorem body_source : handler.fn_body = .Sloop (.Ssequence firstPart rest) .Sbreak := rfl
theorem read_source (length : Bool) : read length = .Scall (some (resultKey length))
    (.Evar Arm64Program._kprog_arm64_program_read
      (.Tfunction [CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr),CC.tulong]
        CC.tulong CC.cc_default))
    [.Etempvar Arm64Program._entry (CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr)),
     .Econst_int (CC.Integers.Int.repr (if length then 2 else 1)) CC.tuint] := by
  cases length <;> rfl

private def tempList : List (CC.Ident × CC.Ty) := by run_tac cachePart (← `(handler.fn_temps))
private def undefTemps : CC.TempEnv := CC.createUndefTemps tempList

def initialTemps (entry : CC.Block) : CC.TempEnv := undefTemps.set Arm64Program._entry (.Vptr entry 0)

/-- Allocate the eight actual typed store-value locals from the exported C. -/
def allocation (before : CC.Mem) : CC.Env × CC.Mem :=
  CC.doAllocVariables world.genv_cenv CC.emptyEnv before handler.fn_vars

theorem allocated (before : CC.Mem) :
    CC.AllocVariables world.genv_cenv CC.emptyEnv before handler.fn_vars
      (allocation before).1 (allocation before).2 :=
  CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation before)).symm

theorem entry_frame (before : CC.Mem) : FrameBelow before.nextblock before (allocation before).2 :=
  (FrameBelow.allocVariables (allocated before) before.nextblock (Nat.le_refl _)).2

theorem entry_valid (before : CC.Mem) (entry : CC.Block) :
    CC.FunctionEntry2 world handler [.Vptr entry 0] before
      (allocation before).1 (initialTemps entry) (allocation before).2 := by
  apply CC.FunctionEntry2.intro
  · decide +kernel
  · decide +kernel
  · change CC.listDisjoint [Arm64Program._entry] _
    intro id present other
    have eq : id = Arm64Program._entry := by simpa only [List.mem_singleton] using present
    subst id
    have chunks :
        Arm64Program._entry ∉ CC.varNames Arm64Program.l_kprog_arm64_program_memset_temps_0 ∧
        Arm64Program._entry ∉ CC.varNames Arm64Program.l_kprog_arm64_program_memset_temps_1 ∧
        Arm64Program._entry ∉ CC.varNames Arm64Program.l_kprog_arm64_program_memset_temps_2 ∧
        Arm64Program._entry ∉ CC.varNames Arm64Program.l_kprog_arm64_program_memset_temps_3 := by
      constructor
      · decide +kernel
      constructor
      · decide +kernel
      constructor <;> decide +kernel
    change Arm64Program._entry ∈ CC.varNames
      ((Arm64Program.l_kprog_arm64_program_memset_temps_0 ++ Arm64Program.l_kprog_arm64_program_memset_temps_1) ++
       (Arm64Program.l_kprog_arm64_program_memset_temps_2 ++ Arm64Program.l_kprog_arm64_program_memset_temps_3)) at other
    simp only [CC.varNames,List.map_append,List.mem_append] at other
    exact (other.elim (fun h => h.elim chunks.1 chunks.2.1)
      (fun h => h.elim chunks.2.2.1 chunks.2.2.2))
  · exact allocated before
  · rfl

private theorem unshadowed (before : CC.Mem) :
    (allocation before).1.get Arm64Program._kprog_arm64_program_read = none := by
  have outside : Arm64Program._kprog_arm64_program_read ∉ CC.varNames handler.fn_vars := by decide +kernel
  simpa only [CC.emptyEnv,CC.PTree.gempty] using CC.allocVariables_env_other (allocated before) outside

private theorem call_step (before memory : CC.Mem) (entry : CC.Block) (length : Bool)
    (le : CC.TempEnv) (k : CC.Cont)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0)) :
    CC.Step2 world (.State handler (read length) k (allocation before).1 le memory) CC.E0
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read)
        [.Vptr entry 0,.Vlong (BitVec.ofNat 64 (index length).val)]
        (.Kcall (some (resultKey length)) handler (allocation before).1 le k) memory) := by
  have binding :
      CC.Genv.findSymbol world.genv_genv Arm64Program._kprog_arm64_program_read = some (CC.Positive.ofNat 66) ∧
      CC.Genv.findFunctPtr world.genv_genv (CC.Positive.ofNat 66) =
        some (.Internal Arm64Program.f_kprog_arm64_program_read) := by
    constructor <;> run_tac Arm64ProgramEntryLinked.sourceEquality
  rw [read_source]
  apply CC.Step.call (tyargs := [CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr),CC.tulong])
    (tyres := CC.tulong) (cconv := CC.cc_default) (vf := .Vptr (CC.Positive.ofNat 66) 0)
  · rfl
  · apply CC.doEvalExpr_sound
    simp only [CC.doEvalExpr,CC.lvalOfVar,unshadowed before,binding.1,CC.doDerefLoc,CC.accessMode]
    rfl
  · apply CC.doEvalExprlist_sound
    cases length <;> simp only [CC.doEvalExprlist,CC.doEvalExpr,hentry]
    all_goals rfl
  · simpa +decide [CC.Genv.findFunct,CC.Integers.Ptrofs.eq,CC.Integers.Ptrofs.zero,
      CC.Integers.MI.eq,CC.Integers.MI.zero] using binding.2
  · rfl

/-- Each original register call includes the real 73-step scalar reader and
the return to its exact memset continuation; its heap remains unchanged. -/
theorem scalar_read (before memory : CC.Mem) (entry frontier : CC.Block) (length : Bool)
    (le : CC.TempEnv) (k : CC.Cont) (value : BitVec 64)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (observed : Arm64EntryMemory.gpr frontier memory (.Vptr entry 0) (index length).val =
      some (.Vlong value,.Vint 0)) :
    InternalRun world 75
      (.State handler (read length) k (allocation before).1 le memory)
      (.State handler .Sskip k (allocation before).1 (le.set (resultKey length) (.Vlong value)) memory) := by
  let cont := CC.Cont.Kcall (some (resultKey length)) handler (allocation before).1 le k
  have enter : InternalRun world 1
      (.State handler (read length) k (allocation before).1 le memory)
      (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_read)
        [.Vptr entry 0,.Vlong (BitVec.ofNat 64 (index length).val)] cont memory) :=
    .step (by rw [read_source]; trivial) (call_step before memory entry length le k hentry) (.refl _)
  have reader := Arm64RegisterReads.gpr_read_nonrelative_bound world Arm64MovKeep.Linked.reader_layout
    (fun _ => none) frontier entry 0 (index length) memory cont (.Vlong value) value (0#8)
    observed rfl (by decide) (by decide)
  have leave : InternalRun world 1 (.Returnstate (.Vlong value) (CC.callCont cont) memory)
      (.State handler .Sskip k (allocation before).1 (le.set (resultKey length) (.Vlong value)) memory) :=
    .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  exact (enter.trans reader).trans leave

def byteTemps (le : CC.TempEnv) (value : BitVec 64) : CC.TempEnv :=
  (le.set Arm64Program._t'1 (.Vlong value)).set Arm64Program.___a64_lib_byte
    (.Vint ((value.setWidth 8).setWidth 32))

def readTemps (entry : CC.Block) (value length : BitVec 64) : CC.TempEnv :=
  ((byteTemps (initialTemps entry) value).set Arm64Program._t'2 (.Vlong length)).set
    Arm64Program.___a64_lib_len (.Vlong length)

private theorem byte_cast (value : BitVec 64) :
    value.setWidth 32 &&& (255#32) &&& (255#32) = (value.setWidth 8).setWidth 32 := by
  apply BitVec.eq_of_getLsbD_eq
  intro i
  have mask : (255#32).getLsbD i = (decide (i < 32) && decide (i < 8)) := by
    change ((BitVec.allOnes 8).setWidth 32).getLsbD i = _
    rw [BitVec.getLsbD_setWidth,BitVec.getLsbD_allOnes]
  by_cases small : i < 8
  · have wide : i < 32 := by omega
    simp only [BitVec.getLsbD_and,BitVec.getLsbD_setWidth,mask,small,wide,
      decide_true,Bool.true_and,Bool.and_true]
    trivial
  · simp only [BitVec.getLsbD_and,BitVec.getLsbD_setWidth,mask,small,decide_false,
      Bool.and_false,Bool.false_and]
    exact fun _ => True.intro

/-- Enter the actual memset function and execute both original source reads
and casts. The endpoint is its unchanged original write-loop/tag/clobber
body, with all eight allocated locals live and every old byte preserved. -/
theorem enter_reads (before : CC.Mem) (entry : CC.Block) (value length : BitVec 64) (k : CC.Cont)
    (byte : Arm64EntryMemory.gpr before.nextblock before (.Vptr entry 0) 1 = some (.Vlong value,.Vint 0))
    (len : Arm64EntryMemory.gpr before.nextblock before (.Vptr entry 0) 2 = some (.Vlong length,.Vint 0)) :
    InternalRun world 162
      (.Callstate (.Internal handler) [.Vptr entry 0] k before)
      (.State handler afterReads (continuation k) (allocation before).1
        (readTemps entry value length) (allocation before).2) := by
  let e := (allocation before).1
  let memory := (allocation before).2
  let le := initialTemps entry
  have first := scalar_read before memory entry before.nextblock false le
    (.Kseq byteSet (.Kseq rest (continuation k))) value
    (by simp only [le,initialTemps,CC.PTree.gss])
    ((Arm64EntryMemory.gpr_frame (entry_frame before) _ 1).trans byte)
  have second := scalar_read before memory entry before.nextblock true (byteTemps le value)
    (.Kseq lengthSet (.Kseq afterReads (continuation k))) length
    (by simp +decide only [byteTemps,le,initialTemps,CC.PTree.gss,CC.PTree.gso])
    ((Arm64EntryMemory.gpr_frame (entry_frame before) _ 2).trans len)
  have start : InternalRun world 4
      (.Callstate (.Internal handler) [.Vptr entry 0] k before)
      (.State handler (read false) (.Kseq byteSet (.Kseq rest (continuation k))) e le memory) := by
    refine .step trivial (.internal_function _ _ _ _ _ _ _ (entry_valid before entry)) ?_
    rw [body_source]
    refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
    refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
    exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  have middle : InternalRun world 5
      (.State handler .Sskip (.Kseq byteSet (.Kseq rest (continuation k))) e
        (le.set (resultKey false) (.Vlong value)) memory)
      (.State handler (read true) (.Kseq lengthSet (.Kseq afterReads (continuation k))) e
        (byteTemps le value) memory) := by
    apply internalRun_of_steps
    · simp +decide [InternalPath,InternalState,steps,CC.doStep,byteSet,rest,secondPart,
        CC.doEvalExpr,CC.typeof,CC.PTree.gss,CC.Cop.semCast,CC.Cop.classifyCast,
        CC.Cop.castIntInt,CC.tulong,CC.tuchar,CC.Integers.Int.repr,CC.Integers.MI.repr,
        CC.Integers.Int.zero_ext,CC.Integers.MI.zero_ext,CC.Integers.Int64.unsigned,
        CC.Integers.Int.unsigned,CC.Integers.MI.unsigned,resultKey]
    · simp +decide [steps,CC.doStep,byteSet,rest,secondPart,byteTemps,CC.doEvalExpr,
        CC.typeof,CC.PTree.gss,CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntInt,
        CC.tulong,CC.tuchar,CC.Integers.Int.repr,CC.Integers.MI.repr,CC.Integers.Int.zero_ext,
        CC.Integers.MI.zero_ext,CC.Integers.Int64.unsigned,CC.Integers.Int.unsigned,
        CC.Integers.MI.unsigned,resultKey,byte_cast]
  have finish : InternalRun world 3
      (.State handler .Sskip (.Kseq lengthSet (.Kseq afterReads (continuation k))) e
        ((byteTemps le value).set (resultKey true) (.Vlong length)) memory)
      (.State handler afterReads (continuation k) e (readTemps entry value length) memory) := by
    apply internalRun_of_steps
    · simp +decide [InternalPath,InternalState,steps,CC.doStep,lengthSet,CC.doEvalExpr,CC.PTree.gss,resultKey]
    · simp +decide [steps,CC.doStep,lengthSet,CC.doEvalExpr,CC.PTree.gss,resultKey,readTemps,le]
  exact (((start.trans first).trans middle).trans second).trans finish

end KProgFormal.ClightRefinement.Arm64MemsetSource
