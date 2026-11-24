import KProgFormal.ClightRefinement.X86ProducerPushResources
import KProgFormal.ClightRefinement.InternalPrefixBuilder
import KProgFormal.ClightRefinement.X86ProducerPushTemporaries

namespace KProgFormal.ClightRefinement.X86ProducerPushOperand
open X86ProducerPushBody (handler allocation initialTemps)
open X86ProducerLayout (ge)

def readCall : CC.Stmt := X86_program_profile_bpf.s_x86_sim_inline_arm_DISP_PUSH_2
def argumentTypes : List CC.Ty := [CC.tptr X86ProducerHeaderSource.headerType, CC.tulong, CC.tulong, CC.tulong]
def expression : CC.Expr := .Evar X86_program_profile_bpf._x86_sim_inline_read_reg
  (.Tfunction argumentTypes CC.tulong CC.cc_default)
def argumentExpressions : List CC.Expr :=
  [.Etempvar X86_program_profile_bpf.___x86_bind (CC.tptr X86ProducerHeaderSource.headerType),
    .Etempvar X86_program_profile_bpf._src CC.tuchar,
    .Econst_int (CC.Integers.Int.repr 8) CC.tuint, .Econst_int (CC.Integers.Int.repr 0) CC.tuint]
def values (binding : CC.Block) : List CC.Val := [.Vptr binding 0, .Vlong (3#64), .Vlong (8#64), .Vlong 0]

theorem source_read : readCall = .Scall (some X86_program_profile_bpf._t'10) expression argumentExpressions := by rfl

def start (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) : CC.State :=
  .State handler handler.fn_body k (allocation memory).1 (initialTemps binding) (allocation memory).2

def cachedStart (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) : CC.State :=
  .State handler handler.fn_body k (allocation memory).1 (X86ProducerPushTemporaries.cached binding) (allocation memory).2

theorem exact_start (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) :
    start binding k memory = cachedStart binding k memory := by
  unfold start cachedStart
  rw [X86ProducerPushTemporaries.exact_initial]

theorem original_run {binding : CC.Block} {k : CC.Cont} {memory : CC.Mem} {count : Nat} {last : CC.State}
    (run : InternalRun ge count (cachedStart binding k memory) last) :
    InternalRun ge count (start binding k memory) last := by
  rw [exact_start]
  exact run

structure Certificate (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) where
  count : Nat
  output : CC.TempEnv
  continuation : CC.Cont
  run : InternalRun ge count (start binding k memory)
    (.State handler readCall continuation (allocation memory).1 output (allocation memory).2)

/-- The actual AUX0 register path executes every recovery/mode/direction/width
selector and original sequence before the real RBX reader call. -/
def certificate (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) : Certificate binding k memory := by
  run_tac Lean.Elab.Tactic.withMainContext do
    let world ← Lean.Elab.Term.elabTerm (← `(ge)) none
    let goalType ← Lean.instantiateMVars (← Lean.Elab.Tactic.getMainTarget)
    unless goalType.isAppOfArity ``Certificate 3 do throwError "expected original PUSH operand certificate parameters"
    let parameters := goalType.getAppArgs
    let initial ← Lean.Meta.mkAppM ``cachedStart #[parameters[0]!,parameters[1]!,parameters[2]!]
    let allocated ← Lean.Meta.mkAppM ``allocation #[parameters[2]!]
    let originalEnv ← Lean.Meta.mkAppM ``Prod.fst #[allocated]
    let originalMem ← Lean.Meta.mkAppM ``Prod.snd #[allocated]
    let originalHandler ← Lean.Elab.Term.elabTerm (← `(handler)) none
    let target ← Lean.Elab.Term.elabTerm (← `(readCall)) none
    let built ← InternalPrefixBuilder.build world initial originalHandler target originalEnv originalMem
    let original ← Lean.Meta.mkAppM ``original_run #[built.proof]
    let term ← Lean.Meta.mkAppM ``Certificate.mk
      #[Lean.mkNatLit built.count, built.output, built.continuation, original]
    Lean.Elab.Tactic.closeMainGoal `original_x86_push_operand_path term

theorem executes (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) :
    InternalRun ge (certificate binding k memory).count (start binding k memory)
      (.State handler readCall (certificate binding k memory).continuation (allocation memory).1
        (certificate binding k memory).output (allocation memory).2) := (certificate binding k memory).run

theorem arguments (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) :
    CC.doEvalExprlist ge (allocation memory).1 (certificate binding k memory).output (allocation memory).2
      argumentExpressions argumentTypes = some (values binding) := by rfl

end KProgFormal.ClightRefinement.X86ProducerPushOperand
