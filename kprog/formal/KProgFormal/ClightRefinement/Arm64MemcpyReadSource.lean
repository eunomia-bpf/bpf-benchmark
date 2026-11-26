import KProgFormal.ClightRefinement.Arm64MemcpyReadCall

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyReadSource

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpyReadCall (reader)

private structure Parts where
  outer : CC.Stmt
  body : CC.Stmt
  offset : CC.Stmt
  afterOffset : CC.Stmt
  result : CC.Stmt

private def parts : Parts := by
  run_tac do
    let peel (term : Lean.Expr) (ctor : Lean.Name) : Lean.Elab.Tactic.TacticM (Array Lean.Expr) := do
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ctor 2 do throwError "original memory-reader entry changed"
      pure actual.getAppArgs
    let root ← peel (← Lean.Elab.Term.elabTerm (← `(reader.fn_body)) none) ``CC.Stmt.Ssequence
    let outer ← peel root[0]! ``CC.Stmt.Sloop
    let body ← peel outer[0]! ``CC.Stmt.Ssequence
    Lean.Elab.Tactic.closeMainGoal `actual_memory_reader_entry
      (← Lean.Meta.mkAppM ``Parts.mk #[root[0]!,outer[0]!,body[0]!,body[1]!,root[1]!])

private def cachePart (source : Lean.Syntax) : Lean.Elab.Tactic.TacticM Unit := do
  let term ← Lean.Elab.Term.elabTerm source none
  Lean.Elab.Tactic.closeMainGoal `actual_memory_reader_entry_part
    (← Lean.Meta.withTransparency .all (Lean.Meta.whnf term))

private def outer : CC.Stmt := by run_tac cachePart (← `(parts.outer))
private def body : CC.Stmt := by run_tac cachePart (← `(parts.body))
def offset : CC.Stmt := by run_tac cachePart (← `(parts.offset))
def afterOffset : CC.Stmt := by run_tac cachePart (← `(parts.afterOffset))
def result : CC.Stmt := by run_tac cachePart (← `(parts.result))

theorem source : reader.fn_body = .Ssequence outer result ∧
    outer = .Sloop body .Sbreak ∧ body = .Ssequence offset afterOffset := ⟨rfl,rfl,rfl⟩

private def tempList : List (CC.Ident × CC.Ty) := by run_tac cachePart (← `(reader.fn_temps))
private def undefTemps : CC.TempEnv := CC.createUndefTemps tempList

def initialTemps (entry : CC.Block) (extra : BitVec 64) : CC.TempEnv :=
  (((((((undefTemps.set Arm64Program._entry (.Vptr entry 0)).set Arm64Program._base (.Vlong 1)).set
    Arm64Program._index (.Vlong 255)).set Arm64Program._aux (.Vint 255)).set
    Arm64Program._imm (.Vlong 0)).set Arm64Program._extra (.Vlong extra)).set
    Arm64Program._width (.Vint 1))

def allocation (before : CC.Mem) : CC.Env × CC.Mem :=
  CC.doAllocVariables world.genv_cenv CC.emptyEnv before reader.fn_vars

theorem allocated (before : CC.Mem) :
    CC.AllocVariables world.genv_cenv CC.emptyEnv before reader.fn_vars (allocation before).1 (allocation before).2 :=
  CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation before)).symm

theorem local_count : reader.fn_vars.length = 13 := rfl

theorem entry_frame (before : CC.Mem) : FrameBelow before.nextblock before (allocation before).2 :=
  (FrameBelow.allocVariables (allocated before) before.nextblock (Nat.le_refl _)).2

/-- The actual seven-parameter entry binds both original undef-temp chunks
and allocates every one of the reader's thirteen real typed local objects. -/
theorem entry_valid (before : CC.Mem) (entry : CC.Block) (extra : BitVec 64) :
    CC.FunctionEntry2 world reader (Arm64MemcpyReadCall.arguments entry extra) before
      (allocation before).1 (initialTemps entry extra) (allocation before).2 := by
  apply CC.FunctionEntry2.intro
  · decide +kernel
  · decide +kernel
  · have chunks :
        CC.listDisjoint (CC.varNames reader.fn_params)
          (CC.varNames Arm64Program.l_kprog_arm64_program_memory_read_temps_0) ∧
        CC.listDisjoint (CC.varNames reader.fn_params)
          (CC.varNames Arm64Program.l_kprog_arm64_program_memory_read_temps_1) := by
      constructor <;> decide +kernel
    intro id present other
    change id ∈ CC.varNames
      (Arm64Program.l_kprog_arm64_program_memory_read_temps_0 ++
       Arm64Program.l_kprog_arm64_program_memory_read_temps_1) at other
    simp only [CC.varNames,List.map_append,List.mem_append] at other
    exact other.elim (chunks.1 id present) (chunks.2 id present)
  · exact allocated before
  · rfl

def outerCont (k : CC.Cont) : CC.Cont :=
  .Kloop1 body .Sbreak (.Kseq result k)

def continuation (k : CC.Cont) : CC.Cont :=
  .Kseq afterOffset (outerCont k)

/-- Follow the same actual call through its real allocation and original
sequence/loop entry into the reader's offset-computation loop. -/
theorem enter (before : CC.Mem) (entry : CC.Block) (extra : BitVec 64) (k : CC.Cont) :
    InternalRun world 4
      (.Callstate (.Internal reader) (Arm64MemcpyReadCall.arguments entry extra) k before)
      (.State reader offset (continuation k) (allocation before).1
        (initialTemps entry extra) (allocation before).2) := by
  refine .step trivial (.internal_function _ _ _ _ _ _ _ (entry_valid before entry extra)) ?_
  rw [source.1]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [source.2.1]
  refine .step trivial (CC.doStep_sound _ _ _ _ rfl) ?_
  rw [source.2.2]
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)

end KProgFormal.ClightRefinement.Arm64MemcpyReadSource
