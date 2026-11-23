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

def byte128 (value : BitVec 128) (index : Fin 16) : BitVec 8 :=
  DPSFP.simd_count_bytes ((value >>> (8 * index.val)).setWidth 8)

/-- The same imported loop writes all sixteen actual vector bytes. -/
theorem writes128 (value : BitVec 128) :
    DPSFP.simd_count_bytes value =
      ((0#128)
        |> BitVec.partInstall 0 8 (byte128 value 0)
        |> BitVec.partInstall 8 8 (byte128 value 1)
        |> BitVec.partInstall 16 8 (byte128 value 2)
        |> BitVec.partInstall 24 8 (byte128 value 3)
        |> BitVec.partInstall 32 8 (byte128 value 4)
        |> BitVec.partInstall 40 8 (byte128 value 5)
        |> BitVec.partInstall 48 8 (byte128 value 6)
        |> BitVec.partInstall 56 8 (byte128 value 7)
        |> BitVec.partInstall 64 8 (byte128 value 8)
        |> BitVec.partInstall 72 8 (byte128 value 9)
        |> BitVec.partInstall 80 8 (byte128 value 10)
        |> BitVec.partInstall 88 8 (byte128 value 11)
        |> BitVec.partInstall 96 8 (byte128 value 12)
        |> BitVec.partInstall 104 8 (byte128 value 13)
        |> BitVec.partInstall 112 8 (byte128 value 14)
        |> BitVec.partInstall 120 8 (byte128 value 15)) := by
  simp only [byte128,byte_sum,BitVec.setWidth_ushiftRight_eq_extractLsb]
  run_tac Lean.Meta.withTransparency .all do
    (← Lean.Elab.Tactic.getMainGoal).applyRfl

theorem bytes128 (value : BitVec 128) :
    DPSFP.simd_count_bytes value =
      ((((((((byte128 value 15 ++ byte128 value 14) ++ byte128 value 13) ++ byte128 value 12) ++
        byte128 value 11) ++ byte128 value 10) ++ byte128 value 9) ++ byte128 value 8) ++
       (((((((byte128 value 7 ++ byte128 value 6) ++ byte128 value 5) ++ byte128 value 4) ++
        byte128 value 3) ++ byte128 value 2) ++ byte128 value 1) ++ byte128 value 0)) := by
  rw [writes128]
  repeat rw [BitVec.partInstall_partInstall]
  rw [BitVec.partInstall_eq]
  simp only [BitVec.append_assoc,BitVec.cast_eq]

private theorem low_byte (value : BitVec 128) (i : Fin 8) :
    byte (value.setWidth 64) i = byte128 value ⟨i.val,by omega⟩ := by
  unfold byte byte128
  apply congrArg DPSFP.simd_count_bytes
  simp only [BitVec.setWidth_ushiftRight_eq_extractLsb]
  exact BitVec.extractLsb'_setWidth_of_le (by omega)

private theorem high_byte (value : BitVec 128) (i : Fin 8) :
    byte ((value >>> 64).setWidth 64) i = byte128 value ⟨i.val + 8,by omega⟩ := by
  unfold byte byte128
  apply congrArg DPSFP.simd_count_bytes
  simp only [BitVec.setWidth_ushiftRight_eq_extractLsb]
  apply BitVec.eq_of_getLsbD_eq
  intro j bound
  have inner : 8 * i.val + j < 64 := by omega
  simp only [BitVec.getLsbD_extractLsb',bound,inner,decide_true,Bool.true_and]
  congr 1 <;> omega

/-- The imported vector result is exactly the pair of actual word counts. -/
theorem halves128 (value : BitVec 128) :
    DPSFP.simd_count_bytes value =
      (DPSFP.simd_count_bytes ((value >>> 64).setWidth 64) ++
        DPSFP.simd_count_bytes (value.setWidth 64)) := by
  rw [bytes128,bytes64,bytes64]
  simp only [high_byte]
  simp only [low_byte]
  run_tac Lean.Meta.withTransparency .all do
    (← Lean.Elab.Tactic.getMainGoal).applyRfl

end KProgFormal.ClightRefinement.Arm64Cnt.Lanes
