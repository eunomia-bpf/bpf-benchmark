import KProgFormal.ClightRefinement.Arm64FmovReadEntry

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Fmov.ReadOperands

def inputs : List CC.Ident :=
  [Arm64Program._entry,Arm64Program._dst,Arm64Program._src,Arm64Program._src2,
   Arm64Program._src3,Arm64Program._flags,Arm64Program._aux,Arm64Program._op,
   Arm64Program._imm,Arm64Program.___a64_l_width]

private theorem temps_source (le : CC.TempEnv) (vb : CC.Block) (vo : CC.Integers.Ptrofs) (oldLow value : BitVec 64) :
    ReadEntry.valueTemps le vb vo oldLow value =
    (((((((le.set Arm64Program._t'2786 (.Vlong (3#64))).set Arm64Program.___a64_fmov_index (.Vint (3#32))).set
      Arm64Program.___kprog_a64_fmov_dir (.Vlong 0)).set Arm64Program._t'2840 (.Vptr vb vo)).set
      Arm64Program.___kprog_a64_fmov_v0 (.Vlong oldLow)).set Arm64Program._t'2787 (.Vlong value)).set
      Arm64Program.___kprog_a64_fmov_src (.Vlong value)) := rfl

/-- The original assignments establish both operands, dir0 and index3,
while every original argument and computed width remains available. -/
theorem ready (le : CC.TempEnv) (vb : CC.Block) (vo : CC.Integers.Ptrofs) (oldLow value : BitVec 64) :
    ((ReadEntry.valueTemps le vb vo oldLow value).get Arm64Program.___kprog_a64_fmov_src = some (.Vlong value) ∧
     (ReadEntry.valueTemps le vb vo oldLow value).get Arm64Program.___kprog_a64_fmov_dir = some (.Vlong 0) ∧
     (ReadEntry.valueTemps le vb vo oldLow value).get Arm64Program.___a64_fmov_index = some (.Vint (3#32)) ∧
     (ReadEntry.valueTemps le vb vo oldLow value).get Arm64Program.___kprog_a64_fmov_v0 = some (.Vlong oldLow)) ∧
    ∀ id ∈ inputs, (ReadEntry.valueTemps le vb vo oldLow value).get id = le.get id := by
  constructor
  · refine ⟨?_,?_,?_,?_⟩
    all_goals rw [temps_source]
    · exact CC.PTree.gss _ _ _
    · iterate 4 rw [CC.PTree.gso _ _ _ _ (by decide +kernel)]
      exact CC.PTree.gss _ _ _
    · iterate 5 rw [CC.PTree.gso _ _ _ _ (by decide +kernel)]
      exact CC.PTree.gss _ _ _
    · iterate 2 rw [CC.PTree.gso _ _ _ _ (by decide +kernel)]
      exact CC.PTree.gss _ _ _
  · intro id inside
    simp only [inputs,List.mem_cons,List.not_mem_nil,or_false] at inside
    rcases inside with rfl|rfl|rfl|rfl|rfl|rfl|rfl|rfl|rfl|rfl
    all_goals rw [temps_source]
    all_goals iterate 7 rw [CC.PTree.gso _ _ _ _ (by decide +kernel)]

/-- Actual producer vector pointers and old-vector/GPR scalar loads derive
the complete original FMOV read prefix and helper return on the same heap. -/
theorem from_storage {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry) (i : Fin 31)
    (oldLow value : BitVec 64) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (unshadowed : e.get Arm64Program._kprog_arm64_program_read = none)
    (entryRead : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (index : le.get Arm64Program._src2 = some (.Vlong (3#64)))
    (source : le.get Arm64Program._src = some (.Vlong (BitVec.ofNat 64 i.val)))
    (aux : le.get Arm64Program._aux = some (.Vint 0))
    (oldVector : CC.Mem.load .Mint64 m storage.vectors.block 48 = some (.Vlong oldLow))
    (word : CC.Mem.load .Mint64 m ((storage.tables false).cellBlock i) 0 = some (.Vlong value))
    (tag : CC.Mem.load .Mint8unsigned m ((storage.tables true).cellBlock i) 0 = some (.Vint 0)) :
    ∃ count, InternalRun Arm64ProgramEntryLinked.ge count
      (.State Arm64Nop.handler DestinationSite.branch k e le m)
      (.State Arm64Nop.handler ReadEntry.tail (ReadEntry.innerCont k) e
        (ReadEntry.valueTemps le storage.vectors.block (Arm64Producer.vectorLoopSourceOffset false 3) oldLow value) m) := by
  have slot : CC.Mem.loadv CC.Mptr m (.Vptr entry.block (CC.Integers.Ptrofs.repr 120)) =
      some (.Vptr storage.vectors.block (Arm64Producer.vectorLoopSourceOffset false 3)) := by
    exact storage.vectorPointers false 3
  have data : CC.Mem.loadv .Mint64 m (.Vptr storage.vectors.block (Arm64Producer.vectorLoopSourceOffset false 3)) =
      some (.Vlong oldLow) := by
    change CC.Mem.load .Mint64 m storage.vectors.block _ = _
    have offset : (Arm64Producer.vectorLoopSourceOffset false 3).unsigned = 48 := by decide +kernel
    rw [offset]
    exact oldVector
  exact ReadEntry.scalar storage i storage.vectors.block (Arm64Producer.vectorLoopSourceOffset false 3)
    oldLow value e le k unshadowed entryRead index source aux slot data word tag

end KProgFormal.ClightRefinement.Arm64Fmov.ReadOperands
