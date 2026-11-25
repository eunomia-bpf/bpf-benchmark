import KProgFormal.ClightRefinement.X86ProducerSubSetup
import KProgFormal.ClightRefinement.X86ProducerSubReadValue
import KProgFormal.ClightRefinement.X86ProducerPushRead

namespace KProgFormal.ClightRefinement.X86ProducerSubReadSite
open X86ProducerLayout (ge)
open X86ProducerSubBody (handler allocation)
open X86ProducerSubSetup (readCall)

def resultName : CC.Ident := by
  run_tac do
    let stmt ← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.Elab.Term.elabTerm (← `(readCall)) none))
    let result ← Lean.Meta.withTransparency .all (Lean.Meta.whnf stmt.getAppArgs[0]!)
    unless result.isAppOfArity ``Option.some 2 do throwError "actual RSP reader result missing"
    Lean.Elab.Tactic.closeMainGoal `actual_sub_reader_result result.getAppArgs[1]!

def argumentTypes : List CC.Ty := [CC.tptr X86ProducerHeaderSource.headerType,CC.tulong,CC.tulong,CC.tulong]
def expression : CC.Expr := .Evar X86_program_profile_bpf._x86_sim_inline_read_reg
  (.Tfunction argumentTypes CC.tulong CC.cc_default)
def argumentExpressions : List CC.Expr := by
  run_tac do
    let stmt ← Lean.Meta.withTransparency .all (Lean.Meta.whnf (← Lean.Elab.Term.elabTerm (← `(readCall)) none))
    Lean.Elab.Tactic.closeMainGoal `actual_sub_reader_arguments stmt.getAppArgs[2]!

def values (binding : CC.Block) : List CC.Val := [.Vptr binding 0,.Vlong (4#64),.Vlong (8#64),.Vlong 0]

theorem source_read : readCall = .Scall (some resultName) expression argumentExpressions := by rfl

def start (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) : CC.State :=
  .State handler .Sskip (X86ProducerSubSetup.certificate binding k memory).continuation
    (allocation memory).1 (X86ProducerSubSetup.temps binding k memory) (allocation memory).2

structure Certificate (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) where
  count : Nat
  output : CC.TempEnv
  continuation : CC.Cont
  run : InternalRun ge count (start binding k memory)
    (.State handler readCall continuation (allocation memory).1 output (allocation memory).2)

/-- The original post-width return, casts, auxiliary decode and shift
selection reach the genuine RSP read call without replacing any statement. -/
def certificate (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) : Certificate binding k memory := by
  run_tac Lean.Elab.Tactic.withMainContext do
    let goalType ← Lean.instantiateMVars (← Lean.Elab.Tactic.getMainTarget)
    let parameters := goalType.getAppArgs
    let world ← Lean.Elab.Term.elabTerm (← `(ge)) none
    let initial ← Lean.Meta.mkAppM ``start #[parameters[0]!,parameters[1]!,parameters[2]!]
    let allocated ← Lean.Meta.mkAppM ``allocation #[parameters[2]!]
    let env ← Lean.Meta.mkAppM ``Prod.fst #[allocated]
    let memory ← Lean.Meta.mkAppM ``Prod.snd #[allocated]
    let original ← Lean.Elab.Term.elabTerm (← `(handler)) none
    let target ← Lean.Elab.Term.elabTerm (← `(readCall)) none
    let built ← InternalPrefixBuilder.build world initial original target env memory
    Lean.Elab.Tactic.closeMainGoal `actual_sub_operand_prefix
      (← Lean.Meta.mkAppM ``Certificate.mk #[Lean.mkNatLit built.count,built.output,built.continuation,built.proof])

theorem executes (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) :
    InternalRun ge (certificate binding k memory).count (start binding k memory)
      (.State handler readCall (certificate binding k memory).continuation (allocation memory).1
        (certificate binding k memory).output (allocation memory).2) := (certificate binding k memory).run

theorem arguments (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) :
    CC.doEvalExprlist ge (allocation memory).1 (certificate binding k memory).output (allocation memory).2
      argumentExpressions argumentTypes = some (values binding) := by rfl

def continuation (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) : CC.Cont :=
  .Kcall (some resultName) handler (allocation memory).1 (certificate binding k memory).output
    (certificate binding k memory).continuation

/-- Actual global reader-call binding, exact original expressions and all
casts pass the materialized-RSP reader its real source operands. -/
theorem call (binding : CC.Block) (k : CC.Cont) (memory : CC.Mem) :
    InternalRun ge 1
      (.State handler readCall (certificate binding k memory).continuation (allocation memory).1
        (certificate binding k memory).output (allocation memory).2)
      (.Callstate (.Internal X86_program_profile_bpf.f_x86_sim_inline_read_reg) (values binding)
        (continuation binding k memory) (allocation memory).2) := by
  have absent : (allocation memory).1.get X86_program_profile_bpf._x86_sim_inline_read_reg = none := rfl
  have function : CC.doEvalExpr ge (allocation memory).1 (certificate binding k memory).output (allocation memory).2 expression =
      some (.Vptr X86ProducerPushRead.readerBlock 0) := by
    simp only [expression,CC.doEvalExpr,CC.lvalOfVar,absent,X86ProducerPushRead.reader_binding.1,CC.doDerefLoc,CC.accessMode]
    rfl
  rw [source_read]
  refine .step trivial ?_ (.refl _)
  apply CC.Step.call (tyargs := argumentTypes) (tyres := CC.tulong) (cconv := CC.cc_default)
    (vf := .Vptr X86ProducerPushRead.readerBlock 0)
  · rfl
  · exact CC.doEvalExpr_sound _ _ _ _ _ _ function
  · exact CC.doEvalExprlist_sound _ _ _ _ _ _ _ (arguments binding k memory)
  · have zero : CC.Integers.Ptrofs.eq (0 : CC.Integers.Ptrofs) CC.Integers.Ptrofs.zero = true := rfl
    simpa only [CC.Genv.findFunct,zero,ite_true] using X86ProducerPushRead.reader_binding.2
  · rfl

/-- The genuine source read site executes the complete original RSP reader
on SAME actual allocated heap. No returned-lhs equality is assumed. -/
theorem from_body {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    {rsp : X86ProducerPushRspPrefix.Result ready} {metadata : X86ProducerPushMetadataPrefix.Result rsp}
    {cache : X86ProducerPushCachePrefix.Result metadata} (complete : X86ProducerPushComplete.Result cache)
    (header : X86ProducerEntryReady.HeaderReads ready) (k : CC.Cont) :
    InternalRun ge ((X86ProducerSubSetup.certificate ready.entry.block k complete.after).count + 8 +
      (certificate ready.entry.block k complete.after).count + 1 + X86RegisterReadRspCall.length .q)
      (X86ProducerSubSetup.start ready.entry.block k complete.after)
      (.Returnstate (.Vlong (ready.stackOutcome.value-(8#64)))
        (CC.callCont (continuation ready.entry.block k complete.after)) (allocation complete.after).2) := by
  have setup := (X86ProducerSubSetup.executes ready.entry.block k complete.after).trans
    (X86ProducerSubSetup.invoke ready.entry.block k complete.after)
  have read := ((executes ready.entry.block k complete.after).trans
    (call ready.entry.block k complete.after)).trans
    (X86ProducerSubReadValue.call complete header (continuation ready.entry.block k complete.after))
  simpa only [Nat.add_assoc] using setup.trans read

end KProgFormal.ClightRefinement.X86ProducerSubReadSite
