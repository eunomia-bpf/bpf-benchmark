import KProgFormal.ClightRefinement.Arm64CntHigh
import KProgFormal.ClightRefinement.Arm64CntVectorWrite
import KProgFormal.ClightRefinement.Arm64CntVectorStorage
import KProgFormal.ClightRefinement.Arm64CntNativeView

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Cnt.Path

def statement : CC.Stmt := .Ssequence ReductionSite.highPath VectorWrite.lowPath
def inputs : List CC.Ident :=
  [Arm64Program._entry,Arm64Program._dst,Arm64Program._src,Arm64Program._src2,
   Arm64Program._src3,Arm64Program._flags,Arm64Program._aux,Arm64Program._op,Arm64Program._imm]

private theorem read_outside : ∀ upper, ∀ id ∈ inputs,
    id ≠ ReductionSite.resultKey upper ∧
    id ≠ (if upper then Arm64Program._t'2836 else Arm64Program._t'2834) ∧
    id ≠ ReductionSite.inputKey upper := by decide +kernel

private theorem read_kept (upper : Bool) (le : CC.TempEnv) (vb : CC.Block) (vo : CC.Integers.Ptrofs)
    (value : BitVec 64) (id : CC.Ident) (inside : id ∈ inputs) :
    (ReadReduction.temps upper le vb vo value).get id = le.get id := by
  rw [ReadReduction.temps,ReductionSite.retained upper _ _ id (read_outside upper id inside).1]
  exact ReadEntry.retained upper le vb vo value id
    (read_outside upper id inside).2.1 (read_outside upper id inside).2.2

private theorem high_outside : ∀ id ∈ inputs,
    Arm64Program.___a64_red_hi ≠ id ∧ Arm64Program._t'2790 ≠ id := by decide +kernel

private theorem high_kept (le : CC.TempEnv) (vb : CC.Block) (vo : CC.Integers.Ptrofs)
    (value : BitVec 64) (id : CC.Ident) (inside : id ∈ inputs) :
    (High.temps le vb vo value).get id = le.get id := by
  unfold High.temps
  rw [CC.PTree.gso _ _ _ _ (high_outside id inside).1,
    CC.PTree.gso _ _ _ _ (high_outside id inside).2]
  exact read_kept true le vb vo value id inside

private theorem saved_high (le : CC.TempEnv) (vb : CC.Block) (vo : CC.Integers.Ptrofs) (value : BitVec 64) :
    (ReadReduction.temps false le vb vo value).get Arm64Program.___a64_red_hi =
      le.get Arm64Program.___a64_red_hi := by
  rw [ReadReduction.temps,ReductionSite.retained false _ _ Arm64Program.___a64_red_hi (by decide +kernel)]
  exact ReadEntry.retained false le vb vo value Arm64Program.___a64_red_hi
    (by decide +kernel) (by decide +kernel)

/-- Compose the complete original CNT branch, high first and then low,
with both real stores derived from original vector allocation permissions.
The actual input words follow from storage and full register representation. -/
theorem execute {initial before : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (old : Arm64ProducerRegisterStorage.Storage initial before entry)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s)
    (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (global : e.get Arm64Program._kprog_arm64_reduction = none)
    (entryRead : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (op : le.get Arm64Program._op = some (.Vint (36#32)))
    (aux : le.get Arm64Program._aux = some (.Vint (16#32))) :
    ∃ after le' count, InternalRun Arm64ProgramEntryLinked.ge count
      (.State Arm64Nop.handler statement k e le before)
      (.State Arm64Nop.handler .Sskip k e le' after) ∧
      VectorMemory.Effect before after old.vectors.block
        (DPSFP.simd_count_bytes ((Reference.AArch64.readVector s 0).setWidth 64))
        (DPSFP.simd_count_bytes ((Reference.AArch64.readVector s 0 >>> 64).setWidth 64)) ∧
      Arm64VectorWritable.Writable old.vectors after ∧
      ∀ id ∈ inputs, le'.get id = le.get id := by
  let lo := (Reference.AArch64.readVector s 0).setWidth 64
  let hi := (Reference.AArch64.readVector s 0 >>> 64).setWidth 64
  obtain ⟨lowSlot,lowLoaded⟩ := Inputs.reads old addresses origins s represented false
  obtain ⟨highSlot,highLoaded⟩ := Inputs.reads old addresses origins s represented true
  obtain ⟨after,effect,writable⟩ := VectorMemory.write old.vectors old.vectorWritable
    (DPSFP.simd_count_bytes lo) (DPSFP.simd_count_bytes hi)
  have enter : InternalRun Arm64ProgramEntryLinked.ge 1
      (.State Arm64Nop.handler statement k e le before)
      (.State Arm64Nop.handler ReductionSite.highPath (.Kseq VectorWrite.lowPath k) e le before) :=
    .step (by trivial) (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  obtain ⟨highCount,highRun⟩ := High.execute e le before (.Kseq VectorWrite.lowPath k)
    entry.block old.vectors.block (CC.Integers.Ptrofs.repr 8) hi entryRead highSlot highLoaded global op aux
  let highTemps := High.temps le old.vectors.block (CC.Integers.Ptrofs.repr 8) hi
  have highEntry : highTemps.get Arm64Program._entry = some (.Vptr entry.block 0) :=
    (High.entry le _ _ hi).trans entryRead
  have highOp : highTemps.get Arm64Program._op = some (.Vint (36#32)) :=
    (High.opcode le _ _ hi).trans op
  have lowEnter : InternalRun Arm64ProgramEntryLinked.ge 3
      (.State Arm64Nop.handler .Sskip (.Kseq VectorWrite.lowPath k) e highTemps before)
      (.State Arm64Nop.handler (ReductionSite.readPrefix false)
        (.Kseq VectorWrite.lowWrites (.Kseq VectorWrite.highChoice k)) e highTemps before) := by
    apply InternalRun.step
    · trivial
    · exact CC.doStep_sound _ _ _ _ rfl
    rw [VectorWrite.source.1]
    apply InternalRun.step
    · trivial
    · exact CC.doStep_sound _ _ _ _ rfl
    apply InternalRun.step
    · trivial
    · exact CC.doStep_sound _ _ _ _ rfl
    exact .refl _
  obtain ⟨lowCount,lowRun⟩ := ReadReduction.execute false e highTemps before
    (.Kseq VectorWrite.lowWrites (.Kseq VectorWrite.highChoice k)) entry.block old.vectors.block
    (CC.Integers.Ptrofs.repr 0) lo highEntry lowSlot lowLoaded global highOp
  let lowTemps := ReadReduction.temps false highTemps old.vectors.block (CC.Integers.Ptrofs.repr 0) lo
  have storeEnter : InternalRun Arm64ProgramEntryLinked.ge 1
      (.State Arm64Nop.handler .Sskip (.Kseq VectorWrite.lowWrites (.Kseq VectorWrite.highChoice k)) e lowTemps before)
      (.State Arm64Nop.handler VectorWrite.lowWrites (.Kseq VectorWrite.highChoice k) e lowTemps before) :=
    .step (by trivial) (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  have lowEntry : lowTemps.get Arm64Program._entry = some (.Vptr entry.block 0) :=
    (ReadReduction.entry false highTemps _ _ lo).trans highEntry
  have lowOp : lowTemps.get Arm64Program._op = some (.Vint (36#32)) :=
    (ReadReduction.opcode false highTemps _ _ lo).trans highOp
  have highSaved : lowTemps.get Arm64Program.___a64_red_hi = some (.Vlong (DPSFP.simd_count_bytes hi)) :=
    (saved_high highTemps _ _ lo).trans (High.result le _ _ hi)
  have separate : entry.block ≠ old.vectors.block :=
    Arm64Fmov.VectorStorage.separate old.vectors _ _ _ entry.binding (by decide +kernel)
  obtain ⟨writeCount,writeRun⟩ := VectorWrite.execute e lowTemps before after k entry.block old.vectors.block
    (DPSFP.simd_count_bytes lo) (DPSFP.simd_count_bytes hi) lowEntry lowOp
    (ReadReduction.result false highTemps _ _ lo) highSaved lowSlot highSlot separate effect
  refine ⟨after,VectorWrite.temps lowTemps old.vectors.block,_,
    ((((enter.trans highRun).trans lowEnter).trans lowRun).trans storeEnter).trans writeRun,
    effect,writable,?_⟩
  intro id inside
  have outside : ∀ id ∈ inputs, id ≠ Arm64Program._t'2833 ∧ id ≠ Arm64Program._t'2832 := by decide +kernel
  exact (VectorWrite.retained lowTemps _ id (outside id inside).1 (outside id inside).2).trans
    ((read_kept false highTemps _ _ lo id inside).trans (high_kept le _ _ hi id inside))

end KProgFormal.ClightRefinement.Arm64Cnt.Path
