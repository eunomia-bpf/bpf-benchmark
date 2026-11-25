import KProgFormal.ClightRefinement.X86ProducerSubScalarResources

namespace KProgFormal.ClightRefinement.X86ProducerSubFlagSource
open X86ProducerLayout (ge)
open X86ProducerSubBody (handler allocation)

/-- The next original flag compound, obtained from the genuine result
continuation. Its source syntax does not depend on the dummy data arguments. -/
def flags : CC.Stmt := by
  run_tac do
    let continuation ← Lean.Elab.Term.elabTerm (← `(X86ProducerSubResult.following CC.Positive.xH .Kstop CC.Mem.empty (0#64))) none
    let node ← Lean.Meta.withTransparency .all (Lean.Meta.whnf continuation)
    unless node.isAppOfArity ``CC.Cont.Kseq 2 do throwError "original flag compound missing"
    Lean.Elab.Tactic.closeMainGoal `actual_sub_flag_compound node.getAppArgs[0]!

def pointerLoad : CC.Stmt := by
  run_tac do
    let mut todo := #[← Lean.Elab.Term.elabTerm (← `(flags)) none]
    while !todo.isEmpty do
      let item := todo.back!
      todo := todo.pop
      let stmt ← Lean.Meta.withTransparency .all (Lean.Meta.whnf item)
      if stmt.isAppOfArity ``CC.Stmt.Sset 2 then
        let rhs ← Lean.Meta.withTransparency .all (Lean.Meta.whnf stmt.getAppArgs[1]!)
        if rhs.isAppOfArity ``CC.Expr.Efield 3 && rhs.getAppArgs[1]!.isConstOf ``X86_program_profile_bpf._cf then
          Lean.Elab.Tactic.closeMainGoal `actual_sub_old_cf_pointer stmt
          return
      else if stmt.isAppOfArity ``CC.Stmt.Ssequence 2 || stmt.isAppOfArity ``CC.Stmt.Sloop 2 then
        todo := todo.push stmt.getAppArgs[1]!
        todo := todo.push stmt.getAppArgs[0]!
      else if stmt.isAppOfArity ``CC.Stmt.Sifthenelse 3 then
        todo := todo.push stmt.getAppArgs[2]!
        todo := todo.push stmt.getAppArgs[1]!
    throwError "original oldCF header read missing"

def pointerTemp : CC.Ident := by
  run_tac do
    let stmt ← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.Elab.Term.elabTerm (← `(pointerLoad)) none))
    Lean.Elab.Tactic.closeMainGoal `actual_sub_old_cf_pointer_temp stmt.getAppArgs[0]!

def pointerExpr : CC.Expr := .Efield
  (.Ederef (.Etempvar X86_program_profile_bpf.___x86_bind (CC.tptr X86ProducerHeaderSource.headerType))
    X86ProducerHeaderSource.headerType) X86_program_profile_bpf._cf (CC.tptr CC.tuchar)

theorem pointer_source : pointerLoad = .Sset pointerTemp pointerExpr := by rfl

def start (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64) : CC.State :=
  .State handler .Sskip (X86ProducerSubResult.following binding k memory lhs) (allocation memory).1
    (X86ProducerSubResult.temps binding k memory lhs) (allocation memory).2

structure Certificate (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64) where
  count : Nat
  output : CC.TempEnv
  continuation : CC.Cont
  run : InternalRun ge count (start binding k memory lhs)
    (.State handler pointerLoad continuation (allocation memory).1 output (allocation memory).2)

/-- Every actual result-to-flag sequence/loop reaches the original oldCF
header load. No source memory read or flag statement is erased. -/
def certificate (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64) : Certificate binding k memory lhs := by
  run_tac Lean.Elab.Tactic.withMainContext do
    let goalType ← Lean.instantiateMVars (← Lean.Elab.Tactic.getMainTarget)
    let parameters := goalType.getAppArgs
    let world ← Lean.Elab.Term.elabTerm (← `(ge)) none
    let initial ← Lean.Meta.mkAppM ``start #[parameters[0]!,parameters[1]!,parameters[2]!,parameters[3]!]
    let allocated ← Lean.Meta.mkAppM ``allocation #[parameters[2]!]
    let env ← Lean.Meta.mkAppM ``Prod.fst #[allocated]
    let memory ← Lean.Meta.mkAppM ``Prod.snd #[allocated]
    let original ← Lean.Elab.Term.elabTerm (← `(handler)) none
    let target ← Lean.Elab.Term.elabTerm (← `(pointerLoad)) none
    let built ← InternalPrefixBuilder.buildTo world initial original target env memory
    Lean.Elab.Tactic.closeMainGoal `actual_sub_old_cf_prefix
      (← Lean.Meta.mkAppM ``Certificate.mk #[Lean.mkNatLit built.count,built.output,built.continuation,built.proof])

theorem executes (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64) :
    InternalRun ge (certificate binding k memory lhs).count (start binding k memory lhs)
      (.State handler pointerLoad (certificate binding k memory lhs).continuation (allocation memory).1
        (certificate binding k memory lhs).output (allocation memory).2) := (certificate binding k memory lhs).run

theorem binding (block : CC.Block) (k : CC.Cont) (memory : CC.Mem) (lhs : BitVec 64) :
    (certificate block k memory lhs).output.get X86_program_profile_bpf.___x86_bind = some (.Vptr block 0) := by rfl

end KProgFormal.ClightRefinement.X86ProducerSubFlagSource
