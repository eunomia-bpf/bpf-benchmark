import KProgFormal.ClightRefinement.Arm64CntReadEntry
import KProgFormal.ClightRefinement.Arm64UaddlvReductionSite
import KProgFormal.ClightRefinement.Arm64UaddlvReductionNative

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Uaddlv.ReadReduction

def temps (upper : Bool) (le : CC.TempEnv) (vb : CC.Block) (vo : CC.Integers.Ptrofs)
    (value : BitVec 64) : CC.TempEnv :=
  (Arm64Cnt.ReadEntry.temps upper le vb vo value).set (ReductionSite.resultKey upper)
    (.Vlong ((DPSFP.simd_unsigned_sum_long 8 value).setWidth 64))

/-- Both real source pointer/word prefixes compose with the actual op37
call and caller return to produce the zero-extended imported word sum. -/
theorem execute (upper : Bool) (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (b vb : CC.Block) (vo : CC.Integers.Ptrofs) (value : BitVec 64)
    (entry : le.get Arm64Program._entry = some (.Vptr b 0))
    (slot : CC.Mem.loadv CC.Mptr m (.Vptr b (CC.Integers.Ptrofs.repr (if upper then 352 else 96))) =
      some (.Vptr vb vo))
    (loaded : CC.Mem.loadv .Mint64 m (.Vptr vb vo) = some (.Vlong value))
    (global : e.get Arm64Program._kprog_arm64_reduction = none)
    (op : le.get Arm64Program._op = some (.Vint (37#32))) :
    ∃ count, InternalRun Arm64ProgramEntryLinked.ge count
      (.State Arm64Nop.handler (ReductionSite.readPrefix upper) k e le m)
      (.State Arm64Nop.handler .Sskip k e (temps upper le vb vo value) m) := by
  have opcode : (Arm64Cnt.ReadEntry.temps upper le vb vo value).get Arm64Program._op = some (.Vint (37#32)) := by
    rw [Arm64Cnt.ReadEntry.retained upper le vb vo value Arm64Program._op
      (by cases upper <;> decide +kernel) (by cases upper <;> decide +kernel)]
    exact op
  obtain ⟨count,call⟩ := ReductionSite.execute upper e (Arm64Cnt.ReadEntry.temps upper le vb vo value) m k value
    global opcode (Arm64Cnt.ReadEntry.input upper le vb vo value)
  have nativeCall : InternalRun Arm64ProgramEntryLinked.ge count
      (.State Arm64Nop.handler (ReductionSite.site upper) k e (Arm64Cnt.ReadEntry.temps upper le vb vo value) m)
      (.State Arm64Nop.handler .Sskip k e (temps upper le vb vo value) m) := by
    simpa only [temps,Lanes.word] using call
  exact ⟨_,(Arm64Cnt.ReadEntry.prepare upper e le m k b vb vo value entry slot loaded).trans nativeCall⟩

theorem from_storage {initial before : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (old : Arm64ProducerRegisterStorage.Storage initial before entry)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s)
    (upper : Bool) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (entryRead : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (global : e.get Arm64Program._kprog_arm64_reduction = none)
    (op : le.get Arm64Program._op = some (.Vint (37#32))) :
    ∃ count, InternalRun Arm64ProgramEntryLinked.ge count
      (.State Arm64Nop.handler (ReductionSite.readPrefix upper) k e le before)
      (.State Arm64Nop.handler .Sskip k e
        (temps upper le old.vectors.block (CC.Integers.Ptrofs.repr (if upper then 8 else 0))
          (if upper then (Reference.AArch64.readVector s 0 >>> 64).setWidth 64
            else (Reference.AArch64.readVector s 0).setWidth 64)) before) := by
  obtain ⟨slot,loaded⟩ := Arm64Cnt.Inputs.reads old addresses origins s represented upper
  exact execute upper e le before k entry.block old.vectors.block _ _ entryRead slot loaded global op

theorem result (upper : Bool) (le : CC.TempEnv) (vb : CC.Block) (vo : CC.Integers.Ptrofs) (value : BitVec 64) :
    (temps upper le vb vo value).get (ReductionSite.resultKey upper) =
      some (.Vlong ((DPSFP.simd_unsigned_sum_long 8 value).setWidth 64)) := CC.PTree.gss _ _ _

theorem entry (upper : Bool) (le : CC.TempEnv) (vb : CC.Block) (vo : CC.Integers.Ptrofs) (value : BitVec 64) :
    (temps upper le vb vo value).get Arm64Program._entry = le.get Arm64Program._entry := by
  rw [temps,ReductionSite.retained upper _ _ Arm64Program._entry (by cases upper <;> decide +kernel)]
  exact Arm64Cnt.ReadEntry.retained upper le vb vo value Arm64Program._entry
    (by cases upper <;> decide +kernel) (by cases upper <;> decide +kernel)

theorem opcode (upper : Bool) (le : CC.TempEnv) (vb : CC.Block) (vo : CC.Integers.Ptrofs) (value : BitVec 64) :
    (temps upper le vb vo value).get Arm64Program._op = le.get Arm64Program._op := by
  rw [temps,ReductionSite.retained upper _ _ Arm64Program._op (by cases upper <;> decide +kernel)]
  exact Arm64Cnt.ReadEntry.retained upper le vb vo value Arm64Program._op
    (by cases upper <;> decide +kernel) (by cases upper <;> decide +kernel)

end KProgFormal.ClightRefinement.Arm64Uaddlv.ReadReduction
