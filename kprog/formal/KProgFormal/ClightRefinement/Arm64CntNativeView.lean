import KProgFormal.ClightRefinement.Arm64CntVectorView
import KProgFormal.ClightRefinement.Arm64CntNative
import KProgFormal.ClightRefinement.Arm64CntLanes

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Cnt.NativeView

theorem gpr (s : Reference.AArch64.State) (i : Fin 31) :
    Reference.AArch64.gpr (Native.after s) i = Reference.AArch64.gpr s i := by
  simp [Native.after,Arm64Nop.atCursor,Reference.AArch64.gpr,write_pc,write_sfp,r_of_w_different]

theorem sp (s : Reference.AArch64.State) :
    Reference.AArch64.sp (Native.after s) = Reference.AArch64.sp s := by
  simp [Native.after,Arm64Nop.atCursor,Reference.AArch64.sp,write_pc,write_sfp,r_of_w_different]

theorem flag (s : Reference.AArch64.State) (p : PFlag) :
    read_flag p (Native.after s).machine = read_flag p s.machine := by
  simp [Native.after,Arm64Nop.atCursor,read_flag,write_pc,write_sfp,r_of_w_different]

private theorem vector_indices : ∀ i : Fin 32, i ≠ 0 → BitVec.ofNat 5 i.val ≠ (0#5) := by decide +kernel

theorem other (s : Reference.AArch64.State) (i : Fin 32) (different : i ≠ 0) :
    Reference.AArch64.readVector (Native.after s) i = Reference.AArch64.readVector s i := by
  simp only [Native.after,Arm64Nop.atCursor,Reference.AArch64.readVector,write_pc,write_sfp]
  rw [r_of_w_different (fld1 := .SFP (BitVec.ofNat 5 i.val)) (fld2 := .PC) (by intro equal; cases equal)]
  apply r_of_w_different
  intro equal
  exact vector_indices i different (StateField.SFP.inj equal)

theorem low (s : Reference.AArch64.State) :
    (Reference.AArch64.readVector (Native.after s) 0).setWidth 64 =
      DPSFP.simd_count_bytes ((Reference.AArch64.readVector s 0).setWidth 64) := by
  rw [Native.destination,Lanes.halves128,BitVec.setWidth_append]
  simp

theorem high (s : Reference.AArch64.State) :
    ((Reference.AArch64.readVector (Native.after s) 0 >>> 64).setWidth 64) =
      DPSFP.simd_count_bytes ((Reference.AArch64.readVector s 0 >>> 64).setWidth 64) := by
  rw [Native.destination,Lanes.halves128,
    BitVec.setWidth_ushiftRight_eq_extractLsb,BitVec.extractLsb'_append_eq_left]

/-- Actual source loads and the original representation fix both native
input words; the native input values are derived from these observations. -/
theorem source {initial before : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (old : Arm64ProducerRegisterStorage.Storage initial before entry) (lo hi : BitVec 64)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s)
    (lowRead : CC.Mem.load .Mint64 before old.vectors.block 0 = some (.Vlong lo))
    (highRead : CC.Mem.load .Mint64 before old.vectors.block 8 = some (.Vlong hi)) :
    lo = (Reference.AArch64.readVector s 0).setWidth 64 ∧
      hi = (Reference.AArch64.readVector s 0 >>> 64).setWidth 64 := by
  have observed : Arm64EntryMemory.vector before.nextblock before (.Vptr entry.block 0) 0 =
      some (.Vlong lo,.Vlong hi) := by
    rw [Arm64RegisterWrite.storage_vector old]
    change (do let low ← CC.Mem.load .Mint64 before old.vectors.block 0
               let high ← CC.Mem.load .Mint64 before old.vectors.block 8
               pure (low,high)) = _
    simp only [lowRead,highRead,bind,Option.bind_some,pure]
  have same := Option.some.inj ((represented.vectors 0).symm.trans observed)
  exact ⟨(CC.Val.Vlong.inj (congrArg Prod.fst same)).symm,
    (CC.Val.Vlong.inj (congrArg Prod.snd same)).symm⟩

/-- Both actual count stores refine the complete imported register state,
including all GPRs, SP, NZCV and all 31 other vectors. -/
theorem represents {initial before after : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (old : Arm64ProducerRegisterStorage.Storage initial before entry) (lo hi : BitVec 64)
    (effect : VectorMemory.Effect before after old.vectors.block
      (DPSFP.simd_count_bytes lo) (DPSFP.simd_count_bytes hi))
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s)
    (lowRead : CC.Mem.load .Mint64 before old.vectors.block 0 = some (.Vlong lo))
    (highRead : CC.Mem.load .Mint64 before old.vectors.block 8 = some (.Vlong hi)) :
    Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock after (.Vptr entry.block 0) (Native.after s) := by
  obtain ⟨loEq,hiEq⟩ := source old lo hi addresses origins s represented lowRead highRead
  constructor
  · intro i
    obtain ⟨cell,raw,kind,read,defined,physical⟩ := represented.gpr i
    exact ⟨cell,raw,kind,(VectorView.gpr old _ _ effect i).trans read,defined,(gpr s i).trans physical⟩
  · simpa only [VectorView.sp old _ _ effect,sp] using represented.sp
  · intro i
    by_cases same : i = 0
    · subst i
      rw [VectorView.selected old _ _ effect,low,high,loEq,hiEq]
    · rw [VectorView.other old _ _ effect i same,other s i same]
      exact represented.vectors i
  · simpa only [Arm64Nop.FlagsRepresent,VectorView.flags old _ _ effect,flag] using represented.flags

end KProgFormal.ClightRefinement.Arm64Cnt.NativeView
