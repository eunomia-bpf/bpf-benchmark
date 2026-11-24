import KProgFormal.ClightRefinement.X86ProducerPushStorageSetup
import KProgFormal.ClightRefinement.X86ProducerEffectiveWidth
import KProgFormal.ClightRefinement.InternalPrefixBuilder

namespace KProgFormal.ClightRefinement.X86ProducerPushStorageSelect
open X86ProducerLayout (ge)
open X86ProducerPushBody (handler allocation)
open X86ProducerPushStorageSource

def initialTemps {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer} (rsp : X86ProducerPushRspPrefix.Result ready) : CC.TempEnv :=
  X86ProducerPushStorageSetup.temps (X86ProducerPushStorageSetup.initialTemps rsp) ready.gprs.block

def firstStart {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    (rsp : X86ProducerPushRspPrefix.Result ready) (k : CC.Cont) (memory : CC.Mem) : CC.State :=
  .State handler .Sskip (widthCont k) (allocation ready.after).1
    ((initialTemps rsp).set X86_program_profile_bpf._t'18 (.Vint (8#32))) memory

structure FirstCertificate {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    (rsp : X86ProducerPushRspPrefix.Result ready) (k : CC.Cont) (memory : CC.Mem) where
  count : Nat
  output : CC.TempEnv
  continuation : CC.Cont
  run : InternalRun ge count (firstStart rsp k memory) (.State handler guardCall continuation (allocation ready.after).1 output memory)

private def makeCertificate (startName targetName constructorName : Lean.Name) : Lean.Elab.Tactic.TacticM Unit :=
  Lean.Elab.Tactic.withMainContext do
    let goalType ← Lean.instantiateMVars (← Lean.Elab.Tactic.getMainTarget)
    let parameters := goalType.getAppArgs
    unless parameters.size == 8 do throwError "original PUSH storage certificate parameters changed"
    let ready := parameters[4]!
    let world ← Lean.Elab.Term.elabTerm (← `(ge)) none
    let initial ← Lean.Meta.mkAppM startName #[parameters[5]!,parameters[6]!,parameters[7]!]
    let frame ← Lean.Meta.mkAppM ``X86ProducerEntryReady.Result.after #[ready]
    let allocated ← Lean.Meta.mkAppM ``allocation #[frame]
    let originalEnv ← Lean.Meta.mkAppM ``Prod.fst #[allocated]
    let originalHandler ← Lean.Elab.Term.elabTerm (← `(handler)) none
    let built ← InternalPrefixBuilder.buildTo world initial originalHandler (Lean.mkConst targetName) originalEnv parameters[7]!
    Lean.Elab.Tactic.closeMainGoal `original_x86_push_storage_path
      (← Lean.Meta.mkAppM constructorName #[Lean.mkNatLit built.count,built.output,built.continuation,built.proof])

/-- Actual original width save/value copy/fast-loop/index/control transitions
reach the second real width Scall, keeping the entire heap unchanged. -/
def firstCertificate {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    (rsp : X86ProducerPushRspPrefix.Result ready) (k : CC.Cont) (memory : CC.Mem) : FirstCertificate rsp k memory := by
  run_tac makeCertificate ``firstStart ``X86ProducerPushStorageSource.guardCall ``FirstCertificate.mk

def secondStart {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    (rsp : X86ProducerPushRspPrefix.Result ready) (k : CC.Cont) (memory : CC.Mem) : CC.State :=
  .State handler .Sskip (firstCertificate rsp k memory).continuation (allocation ready.after).1
    ((firstCertificate rsp k memory).output.set X86_program_profile_bpf._t'32 (.Vint (8#32))) memory

structure SecondCertificate {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    (rsp : X86ProducerPushRspPrefix.Result ready) (k : CC.Cont) (memory : CC.Mem) where
  count : Nat
  output : CC.TempEnv
  continuation : CC.Cont
  run : InternalRun ge count (secondStart rsp k memory) (.State handler cacheRead continuation (allocation ready.after).1 output memory)

/-- Every real width/alignment/boolean branch selects the original qword
cache pointer read, without erasing the fallback branches in the source. -/
def secondCertificate {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    (rsp : X86ProducerPushRspPrefix.Result ready) (k : CC.Cont) (memory : CC.Mem) : SecondCertificate rsp k memory := by
  run_tac makeCertificate ``secondStart ``X86ProducerPushStorageSource.cacheRead ``SecondCertificate.mk

theorem guard_inputs {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    (rsp : X86ProducerPushRspPrefix.Result ready) (k : CC.Cont) (memory : CC.Mem) :
    (firstCertificate rsp k memory).output.get X86_program_profile_bpf.___x86_loss_width = some (.Vint (8#32)) ∧
    (firstCertificate rsp k memory).output.get X86_program_profile_bpf.___x86_stw_index = some (.Vlong (40#64)) ∧
    (firstCertificate rsp k memory).output.get X86_program_profile_bpf.___x86_loss_value = some (.Vlong (ready.values 3)) := ⟨rfl,rfl,rfl⟩

theorem cache_inputs {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer}
    (rsp : X86ProducerPushRspPrefix.Result ready) (k : CC.Cont) (memory : CC.Mem) :
    (secondCertificate rsp k memory).output.get X86_program_profile_bpf.___x86_bind = some (.Vptr ready.entry.block 0) ∧
    (secondCertificate rsp k memory).output.get X86_program_profile_bpf.___x86_stw_index = some (.Vlong (40#64)) ∧
    (secondCertificate rsp k memory).output.get X86_program_profile_bpf.___x86_loss_value = some (.Vlong (ready.values 3)) ∧
    (secondCertificate rsp k memory).output.get X86_program_profile_bpf._t'33 = some (.Vint (1#32)) ∧
    (secondCertificate rsp k memory).output.get X86_program_profile_bpf._t'34 = some (.Vint (1#32)) := ⟨rfl,rfl,rfl,rfl,rfl⟩

/-- Reloads, two genuine width calls and every actual source selector compose
on the SAME current metadata result to the original cache pointer read. -/
theorem from_metadata {before : CC.Mem} {ctxBlock : CC.Block} {ctxOffset : CC.Integers.Ptrofs} {outer : CC.Cont}
    {ready : X86ProducerEntryReady.Result before ctxBlock ctxOffset outer} {rsp : X86ProducerPushRspPrefix.Result ready}
    (result : X86ProducerPushMetadataPrefix.Result rsp) (k : CC.Cont) :
    InternalRun ge (12 + 8 + (firstCertificate rsp k result.after).count + 8 + (secondCertificate rsp k result.after).count)
      (.State handler X86ProducerPushStackSource.storage k (allocation ready.after).1 (X86ProducerPushStorageSetup.initialTemps rsp) result.after)
      (.State handler cacheRead (secondCertificate rsp k result.after).continuation (allocation ready.after).1
        (secondCertificate rsp k result.after).output result.after) := by
  have firstSource : widthCall = X86ProducerEffectiveWidth.statement X86_program_profile_bpf._t'18 X86_program_profile_bpf.___x86_l_pp_width := rfl
  have guardSource : guardCall = X86ProducerEffectiveWidth.statement X86_program_profile_bpf._t'32 X86_program_profile_bpf.___x86_loss_width := rfl
  have firstCall := X86ProducerEffectiveWidth.invoke ready.after result.after (initialTemps rsp) (widthCont k)
    X86_program_profile_bpf._t'18 X86_program_profile_bpf.___x86_l_pp_width (X86ProducerPushStorageSetup.inputs rsp).2.1
  rw [← firstSource] at firstCall
  have secondCall := X86ProducerEffectiveWidth.invoke ready.after result.after (firstCertificate rsp k result.after).output
    (firstCertificate rsp k result.after).continuation X86_program_profile_bpf._t'32 X86_program_profile_bpf.___x86_loss_width
      (guard_inputs rsp k result.after).1
  rw [← guardSource] at secondCall
  exact ((((X86ProducerPushStorageSetup.from_metadata result k).trans firstCall).trans
    (firstCertificate rsp k result.after).run).trans secondCall).trans (secondCertificate rsp k result.after).run

end KProgFormal.ClightRefinement.X86ProducerPushStorageSelect
