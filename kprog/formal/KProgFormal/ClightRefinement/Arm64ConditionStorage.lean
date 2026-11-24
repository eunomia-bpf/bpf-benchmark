import KProgFormal.ClightRefinement.Arm64ConditionAll

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ConditionAll

/-- Original allocation-bound flag cells and the same architectural flag
relation derive all four actual source byte loads for every condition. -/
theorem from_storage {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry)
    (s : Reference.AArch64.State)
    (represented : Arm64Nop.FlagsRepresent m.nextblock m (.Vptr entry.block 0) s)
    (world : CC.CGenv) (condition : Fin 15) (k : CC.Cont) :
    ∃ count, InternalRun world count
      (.Callstate (.Internal handler) (arguments condition.val (fun i => (storage.flags i).block)) k m)
      (.Returnstate (.Vint (if ConditionHolds (BitVec.ofNat 4 condition.val) s.machine then 1#32 else 0#32))
        (CC.callCont k) m) := by
  have nn := Arm64RegisterWrite.storage_flag storage 0
  have zz := Arm64RegisterWrite.storage_flag storage 1
  have cc := Arm64RegisterWrite.storage_flag storage 2
  have vv := Arm64RegisterWrite.storage_flag storage 3
  change Arm64EntryMemory.borrowed m.nextblock .Mint8unsigned m (.Vptr entry.block 0) Arm64Program._n = _ at nn
  change Arm64EntryMemory.borrowed m.nextblock .Mint8unsigned m (.Vptr entry.block 0) Arm64Program._z = _ at zz
  change Arm64EntryMemory.borrowed m.nextblock .Mint8unsigned m (.Vptr entry.block 0) Arm64Program._c = _ at cc
  change Arm64EntryMemory.borrowed m.nextblock .Mint8unsigned m (.Vptr entry.block 0) Arm64Program._v = _ at vv
  have actual := represented
  unfold Arm64Nop.FlagsRepresent Arm64EntryMemory.flags at actual
  rw [nn,zz,cc,vv] at actual
  simp only [bind,pure,Option.bind_eq_some_iff,Option.some.injEq,Prod.mk.injEq] at actual
  obtain ⟨nv,nr,zv,zr,cv,cr,vv,vr,ne,ze,ce,ve⟩ := actual
  have readN : CC.Mem.load .Mint8unsigned m (storage.flags 0).block 0 =
      some (.Vint ((read_flag .N s.machine).setWidth 32)) := by simpa only [ne] using nr
  have readZ : CC.Mem.load .Mint8unsigned m (storage.flags 1).block 0 =
      some (.Vint ((read_flag .Z s.machine).setWidth 32)) := by simpa only [ze] using zr
  have readC : CC.Mem.load .Mint8unsigned m (storage.flags 2).block 0 =
      some (.Vint ((read_flag .C s.machine).setWidth 32)) := by simpa only [ce] using cr
  have readV : CC.Mem.load .Mint8unsigned m (storage.flags 3).block 0 =
      some (.Vint ((read_flag .V s.machine).setWidth 32)) := by simpa only [ve] using vr
  exact internal world m k condition (fun i => (storage.flags i).block) s
    (read_flag .N s.machine) (read_flag .Z s.machine) (read_flag .C s.machine) (read_flag .V s.machine)
    readN readZ readC readV rfl rfl rfl rfl

end KProgFormal.ClightRefinement.Arm64ConditionAll
