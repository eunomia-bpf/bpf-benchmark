import KProgFormal.ClightRefinement.Arm64ProducerVectorView
set_option Elab.async false
namespace KProgFormal.ClightRefinement.Arm64ProducerVectorView.Inspection
open Arm64Producer

-- Both consumer fields are embedded arrays, matching the producer ABI.
example :
    ((Arm64EntryMemory.composites.get Arm64Program._kprog_arm64_entry).map (fun co =>
      (CC.fieldType Arm64Program._vector_lo co.co_members,
       CC.fieldType Arm64Program._vector_hi co.co_members))) =
      some (.OK (CC.tarray (CC.tptr CC.tulong) 32), .OK (CC.tarray (CC.tptr CC.tulong) 32)) ∧
    CC.sizeof ge.genv_cenv vectorType = 16 ∧
    CC.sizeof ge.genv_cenv vectorArrayType = 512 := by
  decide +kernel

-- Last-lane slots and data both fit their actual declared storage.
example :
    CC.Integers.Ptrofs.unsigned (vectorLoopHeaderOffset false 31) = 344 ∧
    CC.Integers.Ptrofs.unsigned (vectorLoopHeaderOffset true 31) = 600 ∧
    CC.Integers.Ptrofs.unsigned (vectorLoopSourceOffset false 31) = 496 ∧
    CC.Integers.Ptrofs.unsigned (vectorLoopSourceOffset true 31) = 504 ∧
    (608 : Int) ≤ CC.sizeof ge.genv_cenv headerType ∧
    CC.sizeof ge.genv_cenv vectorArrayType = 504+8 := by
  decide +kernel

-- The full32 native vector readbacks belong to the actual linked638-step run.
example (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) (s : Reference.AArch64.State)
    (access : before.access = (allocation m).2.access)
    (values : ∀ block : CC.Block,
      (allocation m).1.get Arm64Entry.___a64_vectors = some (block, vectorArrayType) →
      ∀ high i, CC.Mem.load .Mint64 before block
        (16 * (i.val : Int) + (if high then 8 else 0)) = some (.Vlong (vectorHalf s high i))) :
    ∃ entry : HeaderLocal m, ∃ after finalLe,
      InternalRun Binding.ge 638 (.State producer afterContext k (allocation m).1 le before)
        (.State producer afterVectorLoop k (allocation m).1 finalLe after) ∧
      (∀ i : Fin 32, Arm64EntryMemory.vector after.nextblock after (.Vptr entry.block 0) i =
        some (.Vlong ((Reference.AArch64.readVector s i).setWidth 64),
          .Vlong (((Reference.AArch64.readVector s i) >>> 64).setWidth 64))) ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧ after.nextblock = before.nextblock :=
  producer_vectors_initialized m before le k s access values
end KProgFormal.ClightRefinement.Arm64ProducerVectorView.Inspection
