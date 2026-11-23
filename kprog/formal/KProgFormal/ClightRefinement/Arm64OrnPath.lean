import KProgFormal.ClightRefinement.Arm64OrnNumeric
import KProgFormal.ClightRefinement.Arm64OrnWrite

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Orn.Path

def inputs : List CC.Ident :=
  [Arm64Program._entry,Arm64Program._dst,Arm64Program._src,Arm64Program._src2,
   Arm64Program._src3,Arm64Program._flags,Arm64Program._aux,Arm64Program._op,
   Arm64Program.___a64_l_width]

private theorem retained_input (id : CC.Ident) (inside : id ∈ inputs) :
    id ∈ Numeric.retained := by
  simp only [inputs,List.mem_cons,List.not_mem_nil,or_false] at inside
  rcases inside with rfl|rfl|rfl|rfl|rfl|rfl|rfl|rfl|rfl
  all_goals simp [Numeric.retained]

private theorem slot_unsigned : ∀ i : Fin 31,
    CC.Integers.Ptrofs.unsigned (CC.Integers.Ptrofs.repr (8 * (i.val : Int))) =
      8 * (i.val : Int) := by decide +kernel

/-- The original RHS helper obtains its six loads from actual producer
storage and the pre-memory scalar/tag cells. -/
theorem rhs_storage {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry)
    (src : Fin 31) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (value : BitVec 64)
    (unshadowed : e.get Arm64Program._kprog_arm64_program_modified = none)
    (entryRead : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (source : le.get Arm64Program._src2 = some (.Vlong (BitVec.ofNat 64 src.val)))
    (aux : le.get Arm64Program._aux = some (.Vint (65792#32)))
    (width : le.get Arm64Program.___a64_l_width = some (.Vint (4#32)))
    (word : CC.Mem.load .Mint64 m ((storage.tables false).cellBlock src) 0 = some (.Vlong value))
    (tag : CC.Mem.load .Mint8unsigned m ((storage.tables true).cellBlock src) 0 = some (.Vint 0)) :
    InternalRun Arm64ProgramEntryLinked.ge 126
      (.State Arm64Nop.handler ReadEntry.rhs k e le m)
      (.State Arm64Nop.handler RhsCall.tail k e (RhsCall.temps le ((value <<< 1) &&& (4294967295#64))) m) := by
  have offset : CC.Integers.Ptrofs.add 0 (CC.Integers.Ptrofs.repr (8 * (src.val : Int))) =
      CC.Integers.Ptrofs.repr (8 * (src.val : Int)) := BitVec.zero_add _
  apply RhsCall.scalar src entry.block (storage.tables false).tableBlock
    ((storage.tables false).cellBlock src) (storage.tables true).tableBlock
    ((storage.tables true).cellBlock src) 0 0 0 0 0 e le m k value
    unshadowed entryRead source aux width
  · exact storage.roots false
  · simpa only [CC.Mem.loadv,offset,slot_unsigned] using storage.slots false src
  · simpa only [CC.Mem.loadv,ite_true,show (CC.Integers.Ptrofs.add 0 (CC.Integers.Ptrofs.repr 8)).unsigned = 8 from by decide] using storage.roots true
  · simpa only [CC.Mem.loadv,offset,slot_unsigned] using storage.slots true src
  · exact word
  · exact tag

/-- Compose the real ORN reader, original modified-RHS call, numeric suffix
and scalar writer on the same reached heap and original caller frame. -/
theorem execute {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry)
    (origins : Reference.Provenance.AArch64.Origins) (src rhs dst : Fin 31)
    (raw : BitVec 64) (tag : BitVec 8) (rhsValue : BitVec 64)
    (tags : tag = 0 ∨ tag = 4)
    (observed : Arm64EntryMemory.gpr m.nextblock m (.Vptr entry.block 0) src.val =
      some (.Vlong raw,.Vint (tag.setWidth 32)))
    (cache : tag = 4 → Arm64RegisterReads.WarmEntryCache false m.nextblock m
      (.Vptr entry.block 0) origins.stack)
    (rhsWord : CC.Mem.load .Mint64 m ((storage.tables false).cellBlock rhs) 0 = some (.Vlong rhsValue))
    (rhsTag : CC.Mem.load .Mint8unsigned m ((storage.tables true).cellBlock rhs) 0 = some (.Vint 0))
    (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (readerFree : e.get Arm64Program._kprog_arm64_program_read = none)
    (modifierFree : e.get Arm64Program._kprog_arm64_program_modified = none)
    (writerFree : e.get Arm64Program._kprog_arm64_program_write = none)
    (entryRead : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (source : le.get Arm64Program._src = some (.Vlong (BitVec.ofNat 64 src.val)))
    (source2 : le.get Arm64Program._src2 = some (.Vlong (BitVec.ofNat 64 rhs.val)))
    (destination : le.get Arm64Program._dst = some (.Vlong (BitVec.ofNat 64 dst.val)))
    (op : le.get Arm64Program._op = some (.Vint (53#32)))
    (aux : le.get Arm64Program._aux = some (.Vint (65792#32)))
    (width : le.get Arm64Program.___a64_l_width = some (.Vint (4#32))) :
    ∃ count after le',
      Arm64RegisterWrite.Result storage dst
        ((Reference.Provenance.AArch64.materialize origins raw tag |||
          ~~~((rhsValue <<< 1) &&& (4294967295#64))) &&& (4294967295#64)) true after ∧
      InternalRun Arm64ProgramEntryLinked.ge count
        (.State Arm64Nop.handler ReadEntry.branch k e le m)
        (.State Arm64Nop.handler .Sskip k e le' after) ∧
      ∀ id ∈ inputs, le'.get id = le.get id := by
  let value := Reference.Provenance.AArch64.materialize origins raw tag
  let shifted := (rhsValue <<< 1) &&& (4294967295#64)
  let lhsTemps := ReadEntry.lhsTemps le value
  let rhsTemps := RhsCall.temps lhsTemps shifted
  have read := ReadEntry.scalar origins m.nextblock entry.block 0 src e le m k raw tag tags observed cache readerFree entryRead source op
  have lhsReady := ReadEntry.ready le value
  have lhsKept (id : CC.Ident) (inside : id ∈ inputs) : lhsTemps.get id = le.get id := lhsReady.2 id inside
  have modified := rhs_storage storage rhs e lhsTemps (ReadEntry.innerCont k) rhsValue modifierFree
    ((lhsKept _ (by simp [inputs])).trans entryRead)
    ((lhsKept _ (by simp [inputs])).trans source2)
    ((lhsKept _ (by simp [inputs])).trans aux)
    ((lhsKept _ (by simp [inputs])).trans width) rhsWord rhsTag
  have rhsReady := RhsCall.ready lhsTemps shifted
  have rhsKept (id : CC.Ident) (inside : id ∈ inputs) : rhsTemps.get id = le.get id := by
    apply Eq.trans (rhsReady.2 id ?_) (lhsKept id inside)
    simp only [inputs,List.mem_cons,List.not_mem_nil,or_false] at inside
    rcases inside with rfl|rfl|rfl|rfl|rfl|rfl|rfl|rfl|rfl
    all_goals simp
  have numericOp : rhsTemps.get Arm64Program.___kprog_a64_orn_op = some (.Vlong (53#64)) := by
    rw [rhsReady.2 _ (by simp)]
    change (((le.set Arm64Program.___kprog_a64_orn_op (.Vlong (53#64))).set
      Arm64Program._t'137 (.Vlong value)).set Arm64Program.___kprog_a64_orn_lhs (.Vlong value)).get
      Arm64Program.___kprog_a64_orn_op = _
    rw [CC.PTree.gso _ _ _ _ (by decide +kernel),CC.PTree.gso _ _ _ _ (by decide +kernel),CC.PTree.gss]
  have lhsValue : rhsTemps.get Arm64Program.___kprog_a64_orn_lhs = some (.Vlong value) :=
    (rhsReady.2 _ (by simp)).trans lhsReady.1
  obtain ⟨count,numericTemps,numeric,result,numericKept⟩ := Numeric.execute Arm64ProgramEntryLinked.ge
    e rhsTemps m k value shifted numericOp lhsValue rhsReady.1 ((rhsKept _ (by simp [inputs])).trans width)
  have finalKept (id : CC.Ident) (inside : id ∈ inputs) : numericTemps.get id = le.get id :=
    (numericKept id (retained_input id inside)).trans (rhsKept id inside)
  obtain ⟨after,written,write⟩ := Write.scalar_write storage dst ((value ||| ~~~shifted) &&& (4294967295#64))
    true e numericTemps k writerFree ((finalKept _ (by simp [inputs])).trans entryRead)
    ((finalKept _ (by simp [inputs])).trans destination) result ((finalKept _ (by simp [inputs])).trans width)
  exact ⟨_,after,numericTemps,written,((read.trans modified).trans numeric).trans write,finalKept⟩

end KProgFormal.ClightRefinement.Arm64Orn.Path
