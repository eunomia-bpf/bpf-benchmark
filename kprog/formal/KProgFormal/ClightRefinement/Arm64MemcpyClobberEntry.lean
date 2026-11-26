import KProgFormal.ClightRefinement.Arm64MemcpyTransferProgram
import KProgFormal.ClightRefinement.Arm64MemsetClobberEntry

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyClobberEntry

open Arm64ProgramEntryAllocation (world)
open Arm64MemsetClobberEntry (helper)

private def symbol : CC.Block := CC.Positive.ofNat 109
private theorem binding :
    CC.Genv.findSymbol world.genv_genv Arm64Program._kprog_arm64_program_clobbers = some symbol ∧
    CC.Genv.findFunctPtr world.genv_genv symbol = some (.Internal helper) := by
  constructor <;> run_tac Arm64ProgramEntryLinked.sourceEquality
private theorem call_source : Arm64MemcpyTransferSource.clobbers = .Scall none
    (.Evar Arm64Program._kprog_arm64_program_clobbers
      (.Tfunction [CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr)] CC.tvoid CC.cc_default))
    [.Etempvar Arm64Program._entry (CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr))] := rfl

def callCont (before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) : CC.Cont :=
  .Kcall none Arm64MemcpySource.handler (Arm64MemcpySource.allocation before).1 le k

/-- The original memcpy continuation calls the actual linked C helper, keeping
its own locals and exact return continuation live. -/
theorem call_step (before m : CC.Mem) (entry : CC.Block) (le : CC.TempEnv) (k : CC.Cont)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0)) :
    CC.Step2 world (.State Arm64MemcpySource.handler Arm64MemcpyTransferSource.clobbers k
      (Arm64MemcpySource.allocation before).1 le m) CC.E0
      (.Callstate (.Internal helper) [.Vptr entry 0] (callCont before le k) m) := by
  have unshadowed : (Arm64MemcpySource.allocation before).1.get Arm64Program._kprog_arm64_program_clobbers = none := by
    have outside : Arm64Program._kprog_arm64_program_clobbers ∉ CC.varNames Arm64MemcpySource.handler.fn_vars := by decide +kernel
    simpa only [CC.emptyEnv,CC.PTree.gempty] using CC.allocVariables_env_other (Arm64MemcpySource.allocated before) outside
  rw [call_source]
  apply CC.Step.call (tyargs := [CC.tptr (.Tstruct Arm64Program._kprog_arm64_entry CC.noattr)])
    (tyres := CC.tvoid) (cconv := CC.cc_default) (vf := .Vptr symbol 0)
  · rfl
  · apply CC.doEvalExpr_sound
    simp only [CC.doEvalExpr,CC.lvalOfVar,unshadowed,binding.1,CC.doDerefLoc,CC.accessMode]
    rfl
  · apply CC.doEvalExprlist_sound
    simp only [CC.doEvalExprlist,CC.doEvalExpr,hentry]
    rfl
  · simpa +decide [CC.Genv.findFunct,CC.Integers.Ptrofs.eq,CC.Integers.Ptrofs.zero,
      CC.Integers.MI.eq,CC.Integers.MI.zero] using binding.2
  · rfl

/-- The same complete memcpy packet supplies every real header/SP read.
The original helper has no allocation, and its shared20-step entry runs
under memcpy's own saved function, eight-local frame and continuation. -/
theorem execute {initial seed calleeBefore m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    {le : CC.TempEnv}
    (current : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore 16 m le) (k : CC.Cont) :
    InternalRun world 22
      (.State Arm64MemcpySource.handler Arm64MemcpyTransferSource.clobbers k
        (Arm64MemcpySource.allocation calleeBefore).1 le m)
      (.State helper Arm64MemsetClobberEntry.loop
        (Arm64MemsetClobberEntry.continuation (callCont calleeBefore le k)) CC.emptyEnv
        (Arm64MemsetClobberEntry.temps entry.block current.packet.storage.sp.block) m) := by
  have first : InternalRun world 1
      (.State Arm64MemcpySource.handler Arm64MemcpyTransferSource.clobbers k
        (Arm64MemcpySource.allocation calleeBefore).1 le m)
      (.Callstate (.Internal helper) [.Vptr entry.block 0] (callCont calleeBefore le k) m) :=
    .step trivial (call_step calleeBefore m entry.block le k current.entryRead) (.refl _)
  have opened : InternalRun world 1
      (.Callstate (.Internal helper) [.Vptr entry.block 0] (callCont calleeBefore le k) m)
      (.State helper helper.fn_body (callCont calleeBefore le k) CC.emptyEnv
        (Arm64MemsetClobberEntry.initialTemps entry.block) m) :=
    .step trivial (.internal_function _ _ _ _ _ _ _ (Arm64MemsetClobberEntry.entry_valid m entry.block)) (.refl _)
  have bodyRun := Arm64MemsetClobberEntry.enter CC.emptyEnv (Arm64MemsetClobberEntry.initialTemps entry.block) m
    (callCont calleeBefore le k) entry.block current.packet.storage.sp.block
    (by simp only [Arm64MemsetClobberEntry.initialTemps,CC.PTree.gss]) current.packet.view.bias
    current.packet.storage.spPointer (by simpa only [current.packet.spAtBase] using current.packet.storage.spRead)
  exact first.trans (opened.trans bodyRun)

end KProgFormal.ClightRefinement.Arm64MemcpyClobberEntry
