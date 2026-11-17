import KProgFormal.ClightRefinement.Arm64ProducerEntryView
set_option Elab.async false
namespace KProgFormal.ClightRefinement.Arm64ProducerEntryView.Inspection
open Arm64Producer

-- Actual source ABI positions, including field identifier correspondence.
example : ∀ i : Fin 4, (flagIndex i).val = 8+i.val ∧
    headerField (flagIndex i) = [Arm64Program._n, Arm64Program._z, Arm64Program._c, Arm64Program._v][i] := by
  decide +kernel

-- Native flags are one bit; the bridge does not identify byte2 with a flag.
example (s : Reference.AArch64.State) : flagValues s 0 ≠ .Vint (2#32) := by
  change CC.Val.Vint ((read_flag .N s.machine).setWidth 32) ≠ .Vint (2#32)
  have cases2 : ∀ word : BitVec 1, word = 0 ∨ word = 1 := by decide +kernel
  rcases cases2 (read_flag .N s.machine) with zero | one
  · rw [zero]; decide +kernel
  · rw [one]; decide +kernel

-- The post-header flags must inhabit the actual linked execution world.
example (m before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) (s : Reference.AArch64.State)
    (access : before.access = (allocation m).2.access)
    (values : ∀ (i : Fin 4) (block : CC.Block),
      (allocation m).1.get (headerSourceName (flagIndex i)) = some (block, headerSourceType (flagIndex i)) →
      CC.Mem.load .Mint8unsigned before block 0 = some (flagValues s i)) :
    ∃ entry : HeaderLocal m, ∃ after finalLe,
      InternalRun Binding.ge 638 (.State producer afterContext k (allocation m).1 le before)
        (.State producer afterVectorLoop k (allocation m).1 finalLe after) ∧
      Arm64Nop.FlagsRepresent after.nextblock after (.Vptr entry.block 0) s ∧
      FrameBelow m.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock :=
  producer_flags_initialized m before le k s access values
end KProgFormal.ClightRefinement.Arm64ProducerEntryView.Inspection
