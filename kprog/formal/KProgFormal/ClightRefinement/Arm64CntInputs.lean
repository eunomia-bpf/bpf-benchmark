import KProgFormal.ClightRefinement.Arm64CntVectorView
import KProgFormal.ClightRefinement.Arm64CntNative

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Cnt.Inputs

open Arm64Producer Arm64ProducerRegisterStorage

/-- Original storage and pre-representation supply both actual vector0
loads, including their defined long values. -/
theorem words {initial before : CC.Mem} {entry : HeaderLocal initial}
    (old : Storage initial before entry)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s) :
    CC.Mem.load .Mint64 before old.vectors.block 0 =
        some (.Vlong ((Reference.AArch64.readVector s 0).setWidth 64)) ∧
      CC.Mem.load .Mint64 before old.vectors.block 8 =
        some (.Vlong ((Reference.AArch64.readVector s 0 >>> 64).setWidth 64)) := by
  have actual := represented.vectors 0
  rw [Arm64RegisterWrite.storage_vector old (0 : Fin 32)] at actual
  change (do let low ← CC.Mem.load .Mint64 before old.vectors.block 0
             let high ← CC.Mem.load .Mint64 before old.vectors.block 8
             pure (low,high)) = _ at actual
  cases lowRead : CC.Mem.load .Mint64 before old.vectors.block 0 with
  | none =>
    simp only [lowRead,bind,Option.bind_none] at actual
    cases actual
  | some low =>
    cases highRead : CC.Mem.load .Mint64 before old.vectors.block 8 with
    | none =>
      simp only [lowRead,highRead,bind,Option.bind_none,Option.bind_some] at actual
      cases actual
    | some high =>
      simp only [lowRead,highRead,bind,Option.bind_some,pure] at actual
      exact ⟨congrArg some (congrArg Prod.fst (Option.some.inj actual)),
        congrArg some (congrArg Prod.snd (Option.some.inj actual))⟩

private theorem slots {initial before : CC.Mem} {entry : HeaderLocal initial}
    (old : Storage initial before entry) (upper : Bool) :
    CC.Mem.load CC.Mptr before entry.block (if upper then 352 else 96) =
      some (.Vptr old.vectors.block (CC.Integers.Ptrofs.repr (if upper then 8 else 0))) := by
  have actual := old.vectorPointers upper (0 : Fin 32)
  cases upper <;> exact actual

/-- The two genuine source pointer walks and their word reads follow
from the original storage/representation, with no extra read-success premise. -/
theorem reads {initial before : CC.Mem} {entry : HeaderLocal initial}
    (old : Storage initial before entry)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s) (upper : Bool) :
    CC.Mem.loadv CC.Mptr before (.Vptr entry.block (CC.Integers.Ptrofs.repr (if upper then 352 else 96))) =
        some (.Vptr old.vectors.block (CC.Integers.Ptrofs.repr (if upper then 8 else 0))) ∧
      CC.Mem.loadv .Mint64 before
          (.Vptr old.vectors.block (CC.Integers.Ptrofs.repr (if upper then 8 else 0))) =
        some (.Vlong (if upper then (Reference.AArch64.readVector s 0 >>> 64).setWidth 64
          else (Reference.AArch64.readVector s 0).setWidth 64)) := by
  have pointer := slots old upper
  obtain ⟨low,high⟩ := words old addresses origins s represented
  cases upper
  · exact ⟨pointer,low⟩
  · exact ⟨pointer,high⟩

end KProgFormal.ClightRefinement.Arm64Cnt.Inputs
