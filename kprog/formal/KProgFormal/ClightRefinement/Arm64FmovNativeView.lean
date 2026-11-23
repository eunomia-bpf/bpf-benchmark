import KProgFormal.ClightRefinement.Arm64FmovVectorView
import KProgFormal.ClightRefinement.Arm64FmovNative

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Fmov.NativeView

theorem gpr (s : Reference.AArch64.State) (i : Fin 31) :
    Reference.AArch64.gpr (Native.after s) i = Reference.AArch64.gpr s i := by
  simp [Native.after,Arm64Nop.atCursor,Reference.AArch64.gpr,write_pc,write_sfp,r_of_w_different]

theorem sp (s : Reference.AArch64.State) : Reference.AArch64.sp (Native.after s) = Reference.AArch64.sp s := by
  simp [Native.after,Arm64Nop.atCursor,Reference.AArch64.sp,write_pc,write_sfp,r_of_w_different]

theorem flag (s : Reference.AArch64.State) (p : PFlag) :
    read_flag p (Native.after s).machine = read_flag p s.machine := by
  simp [Native.after,Arm64Nop.atCursor,read_flag,write_pc,write_sfp,r_of_w_different]

private theorem vector_indices : ∀ i : Fin 32, i ≠ 3 → BitVec.ofNat 5 i.val ≠ (3#5) := by decide +kernel

theorem other (s : Reference.AArch64.State) (i : Fin 32) (different : i ≠ 3) :
    Reference.AArch64.readVector (Native.after s) i = Reference.AArch64.readVector s i := by
  simp only [Native.after,Arm64Nop.atCursor,Reference.AArch64.readVector,write_pc,write_sfp]
  rw [r_of_w_different (fld1 := .SFP (BitVec.ofNat 5 i.val)) (fld2 := .PC) (by intro equal; cases equal)]
  apply r_of_w_different
  intro equal
  exact vector_indices i different (StateField.SFP.inj equal)

private theorem halves (value : BitVec 64) :
    (value.setWidth 128).setWidth 64 = value ∧ ((value.setWidth 128 >>> 64).setWidth 64) = 0 := by
  constructor
  · simp
  · rw [← BitVec.setWidth_ushiftRight (x := value) (y := 64) (i := 128) (by decide),
      BitVec.ushiftRight_eq_zero (by decide)]
    rfl

/-- The same original scalar/tag0 read and pre-representation determine X7;
there is no independent native operand premise. -/
theorem source {initial before : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (old : Arm64ProducerRegisterStorage.Storage initial before entry) (value : BitVec 64)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s)
    (word : CC.Mem.load .Mint64 before ((old.tables false).cellBlock 7) 0 = some (.Vlong value))
    (tag : CC.Mem.load .Mint8unsigned before ((old.tables true).cellBlock 7) 0 = some (.Vint 0)) :
    Reference.AArch64.gpr s 7 = value := by
  have observed : Arm64EntryMemory.gpr before.nextblock before (.Vptr entry.block 0) 7 =
      some (.Vlong value,.Vint 0) := by
    change Arm64EntryMemory.gpr before.nextblock before (.Vptr entry.block 0) (7 : Fin 31).val = _
    rw [Arm64RegisterWrite.storage_gpr old (7 : Fin 31)]
    simp only [word,tag,bind,Option.bind_some,pure]
  obtain ⟨cell,raw,kind,read,defined,physical⟩ := represented.gpr 7
  have same := Option.some.inj (read.symm.trans observed)
  have cellEq : cell = .Vlong value := congrArg Prod.fst same
  have rawEq : raw = value := by simpa only [cellEq,Arm64Registers.ValueRep] using defined
  have kindEq : kind = 0 := by
    have widened := CC.Val.Vint.inj (congrArg Prod.snd same)
    simpa using congrArg (fun bits : BitVec 32 => bits.setWidth 8) widened
  simpa +decide [rawEq,kindEq,Reference.Provenance.AArch64.materialize] using physical

/-- The two actual source stores preserve the complete architectural
register relation against the imported LNSym FMOV state, including all
unselected vectors, GPRs, SP and NZCV. -/
theorem represents {initial before after : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (old : Arm64ProducerRegisterStorage.Storage initial before entry) (value : BitVec 64)
    (effect : VectorMemory.Effect before after old.vectors.block value)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s)
    (word : CC.Mem.load .Mint64 before ((old.tables false).cellBlock 7) 0 = some (.Vlong value))
    (tag : CC.Mem.load .Mint8unsigned before ((old.tables true).cellBlock 7) 0 = some (.Vint 0)) :
    Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock after (.Vptr entry.block 0) (Native.after s) := by
  have scalar := source old value addresses origins s represented word tag
  constructor
  · intro i
    obtain ⟨cell,raw,kind,read,defined,physical⟩ := represented.gpr i
    exact ⟨cell,raw,kind,(VectorView.gpr old value effect i).trans read,defined,(gpr s i).trans physical⟩
  · simpa only [VectorView.sp old value effect,sp] using represented.sp
  · intro i
    by_cases same : i = 3
    · subst i
      rw [VectorView.selected old value effect,Native.destination,scalar,(halves value).1,(halves value).2]
    · rw [VectorView.other old value effect i same,other s i same]
      exact represented.vectors i
  · simpa only [Arm64Nop.FlagsRepresent,VectorView.flags old value effect,flag] using represented.flags

end KProgFormal.ClightRefinement.Arm64Fmov.NativeView
