import KProgFormal.ClightRefinement.Arm64FmovCaller

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Fmov.Inputs

/-- The permission is part of the genuine allocation-derived source storage
and is carried by its actual producer, store and frame constructors. -/
theorem writable {initial before : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (old : Arm64ProducerRegisterStorage.Storage initial before entry) :
    Arm64VectorWritable.Writable old.vectors before := old.vectorWritable

/-- The real vector pointer walk and pre-representation supply the old low
half and its successful read within the original producer premises. -/
theorem old_vector {initial before : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (old : Arm64ProducerRegisterStorage.Storage initial before entry)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s) :
    CC.Mem.load .Mint64 before old.vectors.block 48 =
      some (.Vlong ((Reference.AArch64.readVector s 3).setWidth 64)) := by
  have actual := represented.vectors 3
  rw [Arm64RegisterWrite.storage_vector old (3 : Fin 32)] at actual
  change (do let low ← CC.Mem.load .Mint64 before old.vectors.block 48
             let high ← CC.Mem.load .Mint64 before old.vectors.block 56
             pure (low,high)) = _ at actual
  cases lowRead : CC.Mem.load .Mint64 before old.vectors.block 48 with
  | none =>
    simp only [lowRead,bind,Option.bind_none] at actual
    cases actual
  | some low =>
    cases highRead : CC.Mem.load .Mint64 before old.vectors.block 56 with
    | none =>
      simp only [lowRead,highRead,bind,Option.bind_none,Option.bind_some] at actual
      cases actual
    | some high =>
      simp only [lowRead,highRead,bind,Option.bind_some,pure] at actual
      exact congrArg some (congrArg Prod.fst (Option.some.inj actual))

end KProgFormal.ClightRefinement.Arm64Fmov.Inputs
