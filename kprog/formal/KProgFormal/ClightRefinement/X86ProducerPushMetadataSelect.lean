import KProgFormal.ClightRefinement.X86ProducerPushMetadataSource
import KProgFormal.ClightRefinement.X86ProducerPushStackWidth
import KProgFormal.ClightRefinement.InternalPrefixBuilder

namespace KProgFormal.ClightRefinement.X86ProducerPushMetadataSelect
open X86ProducerLayout (ge)
open X86ProducerPushBody (handler allocation)

def initialTemps {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    (ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer) : CC.TempEnv :=
  X86ProducerPushStackWidth.temps (X86ProducerPushStackSetup.temps (X86ProducerPushRspPrefix.temps ready) ready.gprs.block)

def start {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    (ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer) (k : CC.Cont) (memory : CC.Mem) : CC.State :=
  .State handler X86ProducerPushStackSource.stages k (allocation ready.after).1 (initialTemps ready) memory

structure Certificate {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    (ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer) (k : CC.Cont) (memory : CC.Mem) where
  count : Nat
  output : CC.TempEnv
  continuation : CC.Cont
  run : InternalRun ge count (start ready k memory)
    (.State handler (X86ProducerPushMetadataSource.clear 5) continuation (allocation ready.after).1 output memory)

/-- Construct the proof along every actual source guard and loop transition;
all five nonoverlapping slots are skipped and slot5 reaches its original clear. -/
def certificate {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    (ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer) (k : CC.Cont) (memory : CC.Mem) : Certificate ready k memory := by
  run_tac Lean.Elab.Tactic.withMainContext do
    let goalType ← Lean.instantiateMVars (← Lean.Elab.Tactic.getMainTarget)
    unless goalType.isAppOfArity ``Certificate 7 do throwError "expected original PUSH metadata certificate"
    let parameters := goalType.getAppArgs
    let ready := parameters[4]!
    let world ← Lean.Elab.Term.elabTerm (← `(ge)) none
    let initial ← Lean.Meta.mkAppM ``start #[ready,parameters[5]!,parameters[6]!]
    let memory ← Lean.Meta.mkAppM ``X86ProducerEntryReady.Result.after #[ready]
    let allocated ← Lean.Meta.mkAppM ``allocation #[memory]
    let originalEnv ← Lean.Meta.mkAppM ``Prod.fst #[allocated]
    let originalHandler ← Lean.Elab.Term.elabTerm (← `(handler)) none
    let target ← Lean.Elab.Term.elabTerm (← `(X86ProducerPushMetadataSource.clear 5)) none
    let built ← InternalPrefixBuilder.buildTo world initial originalHandler target originalEnv parameters[6]!
    Lean.Elab.Tactic.closeMainGoal `original_x86_push_metadata_path
      (← Lean.Meta.mkAppM ``Certificate.mk #[Lean.mkNatLit built.count,built.output,built.continuation,built.proof])

theorem executes {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    (ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer) (k : CC.Cont) (memory : CC.Mem) :
    InternalRun ge (certificate ready k memory).count (start ready k memory)
      (.State handler (X86ProducerPushMetadataSource.clear 5) (certificate ready k memory).continuation
        (allocation ready.after).1 (certificate ready k memory).output memory) := (certificate ready k memory).run

theorem source_continuation {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    (ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer) (k : CC.Cont) (memory : CC.Mem) :
    (certificate ready k memory).continuation = X86ProducerPushMetadataSource.continuation 5 k := rfl

theorem decisions {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    (ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer) (k : CC.Cont) (memory : CC.Mem) :
    ∀ i : Fin 6, (certificate ready k memory).output.get (X86ProducerPushMetadataSource.flag i) =
      some (.Vint (if i = 5 then (1#32) else 0)) := by
  intro i
  have cases : ∀ i : Fin 6, i = 0 ∨ i = 1 ∨ i = 2 ∨ i = 3 ∨ i = 4 ∨ i = 5 := by decide +kernel
  rcases cases i with rfl | rfl | rfl | rfl | rfl | rfl <;> rfl

theorem inputs {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    (ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer) (k : CC.Cont) (memory : CC.Mem) :
    (certificate ready k memory).output.get X86_program_profile_bpf.___x86_bind = some (.Vptr ready.entry.block 0) ∧
    (certificate ready k memory).output.get X86_program_profile_bpf.___x86_sv_index = some (.Vlong (40#64)) ∧
    (certificate ready k memory).output.get X86_program_profile_bpf.___x86_sv_width = some (.Vlong (8#64)) ∧
    (certificate ready k memory).output.get X86_program_profile_bpf.___x86_l_pp_value = some (.Vlong (ready.values 3)) := ⟨rfl,rfl,rfl,rfl⟩

end KProgFormal.ClightRefinement.X86ProducerPushMetadataSelect
