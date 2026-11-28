import KProgFormal.ClightRefinement.Arm64CiliumCallerSPWriteMemory
import KProgFormal.ClightRefinement.Arm64CiliumCallerLinkedSPCall
import KProgFormal.ClightRefinement.Arm64PointerWrite

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerSPWriterExecute
open Arm64CiliumCallerLink (allocation)
open Arm64CiliumCallerLinkedProgram (ge)
open Arm64CiliumCallerHeaderSource (Header Sources)
open Arm64CiliumCallerEntryScalars (Locals)

theorem layout : Arm64PointerWrite.GprLayout ge := by
  constructor
  all_goals
    run_tac do
      let goal ← Lean.Elab.Tactic.getMainGoal
      let target ← Lean.Meta.whnfR (← Lean.instantiateMVars (← goal.getType))
      goal.assign (← Lean.Meta.mkEqRefl target.getAppArgs[2]!)
      Lean.Elab.Tactic.replaceMainGoal []

/-- The actual SP writer body consumes the store derived from the SAME caller's local rights. -/
theorem execute {m before : CC.Mem} (header : Header m) (sources : Sources m) (scalars : Locals m)
    (access : before.access = (allocation m).2.access)
    (pointers : Arm64CiliumCallerHeaderSequence.Initialized header sources before 12)
    (reads : ∀ i : Fin 2,CC.Mem.load (Arm64CiliumCallerEntryScalars.chunk i)
      before (scalars.block i) 0 = some (Arm64CiliumCallerEntryScalars.value i))
    (k : CC.Cont) (valid : CC.isCallCont k = true) :
    ∃ result : Arm64CiliumCallerSPWriteMemory.Store (before := before) header sources scalars,
      InternalRun ge 42
        (.Callstate (.Internal Arm64Program.f_kprog_arm64_program_write_pointer)
          (Arm64CiliumCallerSPWriterCall.arguments header.block) k before)
        (.Returnstate .Vundef k result.after) ∧
      Arm64EntryMemory.borrowed result.after.nextblock .Mint64 result.after (.Vptr header.block 0)
        Arm64Program._sp = some (.Vlong Arm64CiliumCallerSPPreindex.delta) := by
  obtain ⟨result⟩ := Arm64CiliumCallerSPWriteMemory.write header sources scalars access pointers
  have pointerBefore := Arm64CiliumCallerSPWriteMemory.header_pointer header sources scalars pointers
  have pointerAfter := Arm64CiliumCallerSPWriteMemory.header_pointer header sources scalars result.pointers
  have oldSP : CC.Mem.load .Mint64 before (scalars.block 0) 0 = some (.Vlong (0#64)) := reads 0
  have run := Arm64PointerWrite.execute_sp_store_layout ge layout k valid before result.after
    header.block (scalars.block 0) pointerBefore pointerAfter oldSP result.stored
  refine ⟨result,?_,Arm64CiliumCallerSPWriteMemory.borrowed_after header sources scalars result⟩
  simpa only [Arm64PointerWrite.procedure,Arm64CiliumCallerSPWriterCall.arguments,
    Arm64CiliumCallerSPPreindex.delta] using run

end KProgFormal.ClightRefinement.Arm64CiliumCallerSPWriterExecute
