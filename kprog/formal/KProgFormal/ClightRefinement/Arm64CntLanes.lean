import KProgFormal.ClightRefinement.Arm64CntNative

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Cnt.Lanes

/-- The imported byte loop written as its eight actual additions. -/
private def bitSum (byte : BitVec 8) : BitVec 8 :=
  ((((((((0#8 + (byte.extractLsb' 0 1).setWidth 8) +
    (byte.extractLsb' 1 1).setWidth 8) + (byte.extractLsb' 2 1).setWidth 8) +
    (byte.extractLsb' 3 1).setWidth 8) + (byte.extractLsb' 4 1).setWidth 8) +
    (byte.extractLsb' 5 1).setWidth 8) + (byte.extractLsb' 6 1).setWidth 8) +
    (byte.extractLsb' 7 1).setWidth 8)

private theorem all_bytes : ∀ byte : BitVec 8,
    DPSFP.simd_count_bytes byte = bitSum byte := by decide +kernel

private theorem byte_sum (byte : BitVec 8) :
    DPSFP.simd_count_bytes byte = bitSum byte := all_bytes byte

def byte (value : BitVec 64) (index : Fin 8) : BitVec 8 :=
  DPSFP.simd_count_bytes ((value >>> (8 * index.val)).setWidth 8)

/-- The original imported word loop performs these eight real byte writes. -/
theorem writes64 (value : BitVec 64) :
    DPSFP.simd_count_bytes value =
      BitVec.partInstall 56 8 (byte value 7)
       (BitVec.partInstall 48 8 (byte value 6)
        (BitVec.partInstall 40 8 (byte value 5)
         (BitVec.partInstall 32 8 (byte value 4)
          (BitVec.partInstall 24 8 (byte value 3)
           (BitVec.partInstall 16 8 (byte value 2)
            (BitVec.partInstall 8 8 (byte value 1)
             (BitVec.partInstall 0 8 (byte value 0) (0#64)))))))) := by
  simp only [byte,byte_sum,BitVec.setWidth_ushiftRight_eq_extractLsb]
  run_tac Lean.Meta.withTransparency .all do
    (← Lean.Elab.Tactic.getMainGoal).applyRfl

/-- Adjacent imported byte writes preserve their complete 64-bit result. -/
theorem bytes64 (value : BitVec 64) :
    DPSFP.simd_count_bytes value =
      (((((((byte value 7 ++ byte value 6) ++ byte value 5) ++ byte value 4) ++
        byte value 3) ++ byte value 2) ++ byte value 1) ++ byte value 0) := by
  rw [writes64]
  repeat rw [BitVec.partInstall_partInstall]
  exact BitVec.partInstall_eq _ _

end KProgFormal.ClightRefinement.Arm64Cnt.Lanes
