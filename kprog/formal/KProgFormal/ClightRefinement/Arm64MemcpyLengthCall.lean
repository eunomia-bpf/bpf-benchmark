import KProgFormal.ClightRefinement.Arm64MemsetPointerState

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyLengthCall

open Arm64Producer Arm64ProducerRegisterStorage
open Arm64ProgramEntryAllocation (world)
open Arm64MovImmediate

/-- The actual third ordinary MOV site immediately follows the two pointer
calls. Its original next statement is the genuine memcpy call continuation. -/
theorem source : Arm64ProgramEntryPointerWrites.afterThird =
    .Ssequence (Arm64ProgramEntryOrdinaryMoves.call 2) Arm64ProgramEntryOrdinaryMoves.afterThird :=
  Arm64ProgramEntryOrdinaryMoves.third_source

def callCont (initial : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) : CC.Cont :=
  .Kcall none Arm64ProgramFixture.f_arm64_execute_compile (Arm64ProgramEntryAllocation.allocation initial).1 le
    (.Kseq Arm64ProgramEntryOrdinaryMoves.afterThird k)

/-- The actual source effect, release and retained caller/cache frame share
one original dispatcher execution and its two payload/tag stores. -/
structure Result {initial beforeMem : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial beforeMem entry) (written finalMem : CC.Mem) : Prop where
  effect : Arm64RegisterWrite.Result (OrdinaryCall.allocatedStorage storage) 2 (16#64) false written
  freed : CC.Mem.freeList written (CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world beforeMem).1) = some finalMem
  frame : FrameBelow beforeMem.nextblock written finalMem
  contents : finalMem.contents = written.contents
  nextblock : finalMem.nextblock = written.nextblock
  released : ∀ row ∈ CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world beforeMem).1,
    ∀ ofs, row.2.1 ≤ ofs → ofs < row.2.2 →
      ∀ kind permission, CC.Mem.perm finalMem row.1 ofs kind permission = false
  kept : Arm64CacheLocalFrame.Kept initial beforeMem finalMem 2
  caller : FrameBelow initial.nextblock beforeMem finalMem

/-- Execute the genuine fifteenth MOV call through entry, dispatch, both
stores, real local free, return and original memcpy continuation. -/
theorem execute {initial beforeMem : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial beforeMem entry)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ beforeMem.nextblock.toNat)
    (le : CC.TempEnv) (k : CC.Cont) :
    ∃ written finalMem, Result storage written finalMem ∧
      InternalRun world 207
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryPointerWrites.afterThird k
          (Arm64ProgramEntryAllocation.allocation initial).1 le beforeMem)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryOrdinaryMoves.afterThird k
          (Arm64ProgramEntryAllocation.allocation initial).1 le finalMem) := by
  have enter : InternalRun world 2
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryPointerWrites.afterThird k
        (Arm64ProgramEntryAllocation.allocation initial).1 le beforeMem)
      (.Callstate (.Internal Arm64Nop.handler)
        (Dispatch.arguments (OrdinaryCall.operands entry.block 2 (16#64)) false) (callCont initial le k) beforeMem) := by
    rw [source]
    exact .step trivial (CC.doStep_sound _ _ _ _ rfl)
      (.step (by rw [Arm64ProgramEntryOrdinaryMoves.call_source]; trivial)
        (Arm64ProgramEntryOrdinaryMoves.call_step entry 2 le beforeMem (.Kseq Arm64ProgramEntryOrdinaryMoves.afterThird k) (0#32) (by intro impossible; exact False.elim ((by decide : (2 : Fin 3) ≠ 0) impossible))) (.refl _))
  obtain ⟨written,finalMem,effect,procedure,freed,frame,contents,next,released⟩ :=
    OrdinaryCall.execute storage 2 (16#64) (callCont initial le k) rfl
  have leave : InternalRun world 2 (.Returnstate .Vundef (callCont initial le k) finalMem)
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryOrdinaryMoves.afterThird k
        (Arm64ProgramEntryAllocation.allocation initial).1 le finalMem) :=
    .step trivial (CC.doStep_sound _ _ _ _ rfl) (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _))
  have allocationFrame := Arm64Nop.entry_frame world beforeMem
  have allocateKept := Arm64CacheLocalFrame.of_frame beforeMem.nextblock (2 : Fin 31) bound allocationFrame
  have writerKept : Arm64CacheLocalFrame.Kept initial (Arm64Nop.allocation world beforeMem).2 written 2 := effect.local_load
  have freeKept := Arm64CacheLocalFrame.of_frame beforeMem.nextblock (2 : Fin 31) bound frame
  have growth := (FrameBelow.allocVariables
    (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (Arm64Producer.allocation initial)).symm)
    initial.nextblock (Nat.le_refl _)).1
  have initialBound := Nat.le_trans growth bound
  have allocatedCaller : FrameBelow initial.nextblock beforeMem (Arm64Nop.allocation world beforeMem).2 :=
    fun block old => allocationFrame block (Nat.lt_of_lt_of_le old initialBound)
  have freedCaller : FrameBelow initial.nextblock written finalMem :=
    fun block old => frame block (Nat.lt_of_lt_of_le old initialBound)
  exact ⟨written,finalMem,⟨effect,freed,frame,contents,next,released,
    (allocateKept.trans writerKept).trans freeKept,(allocatedCaller.trans effect.caller).trans freedCaller⟩,
    (enter.trans procedure).trans leave⟩

section Result
variable {initial beforeMem written finalMem : CC.Mem} {entry : HeaderLocal initial}
    {old : Storage initial beforeMem entry} (result : Result old written finalMem)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ beforeMem.nextblock.toNat)
include result bound

def Result.storage : Storage initial finalMem entry :=
  Arm64RegisterStorageFrontier.storage_frame result.effect.storage beforeMem.nextblock bound result.frame

/-- The current result of the actual store and real free is R2=16/tag0. -/
theorem Result.selected : Arm64EntryMemory.gpr finalMem.nextblock finalMem (.Vptr entry.block 0) 2 =
    some (.Vlong (16#64),.Vint 0) := by
  have actual := result.effect.gpr (2 : Fin 31)
  simp only [eq_self,ite_true,Arm64RegisterWrite.written,Bool.false_eq_true,ite_false] at actual
  have atWritten : Arm64EntryMemory.gpr written.nextblock written (.Vptr entry.block 0) 2 =
      some (.Vlong (16#64),.Vint 0) := by
    simpa +decide [result.effect.nextblock] using actual
  have framed := (Arm64EntryMemory.gpr_frame result.frame (.Vptr entry.block 0) 2).trans
    ((Arm64RegisterStorageFrontier.gpr_eq result.effect.storage beforeMem.nextblock bound (2 : Fin 31)).trans atWritten)
  exact (Arm64RegisterStorageFrontier.gpr_eq (result.storage bound) beforeMem.nextblock bound (2 : Fin 31)).symm.trans framed

/-- Every other original GPR observation survives the same local allocation,
actual stores and free, at the real current heap frontier. -/
theorem Result.other (j : Fin 31) (different : (2 : Fin 31) ≠ j) :
    Arm64EntryMemory.gpr finalMem.nextblock finalMem (.Vptr entry.block 0) j.val =
      Arm64EntryMemory.gpr beforeMem.nextblock beforeMem (.Vptr entry.block 0) j.val := by
  rw [Arm64RegisterWrite.storage_gpr (result.storage bound) j,
    result.kept.cell_load old (result.storage bound) false j different .Mint64 0,
    result.kept.cell_load old (result.storage bound) true j different .Mint8unsigned 0,
    ← Arm64RegisterWrite.storage_gpr old j]

end Result
end KProgFormal.ClightRefinement.Arm64MemcpyLengthCall
