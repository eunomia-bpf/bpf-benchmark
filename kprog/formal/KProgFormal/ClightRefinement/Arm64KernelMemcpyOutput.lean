import KProgFormal.ClightRefinement.Arm64KernelMemcpyPairProfile

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64KernelMemcpyOutput

/-- The final actual store witness reads back its original X13/X12 words. -/
theorem readback (s : Reference.AArch64.State) (profile : MemoryProfile) (origin : BitVec 64)
    (stores : Arm64KernelMemcpyTwoStores.Result s profile origin) :
    read_mem_bytes 16 (Reference.AArch64.gpr s 0) stores.final.machine =
      Reference.AArch64.gpr s 13 ++ Reference.AArch64.gpr s 12 := by
  have reached := congrArg (fun state : Reference.AArch64.State => read_mem_bytes 16 (Reference.AArch64.gpr s 0) state.machine) stores.finalView
  have actual : read_mem_bytes 16 (Reference.AArch64.gpr s 0)
      (Arm64KernelMemcpyPairWrite.after stores.stored 1
        (Arm64KernelMemcpyPairWrite.finalProfile profile (Reference.AArch64.gpr s 0)) (Reference.AArch64.gpr s 0)).machine =
      Reference.AArch64.gpr stores.stored 13 ++ Reference.AArch64.gpr stores.stored 12 :=
    Arm64KernelMemcpyPairMemory.readback stores.stored 1 _ _
  have high : Reference.AArch64.gpr stores.stored 13 = Reference.AArch64.gpr s 13 :=
    stores.storedFields (.GPR (13#5)) (by decide)
  have low : Reference.AArch64.gpr stores.stored 12 = Reference.AArch64.gpr s 12 :=
    stores.storedFields (.GPR (12#5)) (by decide)
  exact (reached.trans actual).trans
    ((congrArg (fun hi : BitVec 64 => hi ++ Reference.AArch64.gpr stores.stored 12) high).trans
      (congrArg (fun lo : BitVec 64 => Reference.AArch64.gpr s 13 ++ lo) low))

/-- The SAME two actual stores retain every outside physical byte. -/
theorem outside (s : Reference.AArch64.State) (profile : MemoryProfile) (origin : BitVec 64)
    (stores : Arm64KernelMemcpyTwoStores.Result s profile origin) (other : BitVec 64)
    (notWritten : 16 ≤ (other-Reference.AArch64.gpr s 0).toNat) :
    read_mem other stores.final.machine = read_mem other s.machine := by
  have last := congrArg (fun state : Reference.AArch64.State => read_mem other state.machine) stores.finalView
  have first := congrArg (fun state : Reference.AArch64.State => read_mem other state.machine) stores.storedView
  exact (last.trans (Arm64KernelMemcpyPairMemory.outside stores.stored 1 _ _ other notWritten)).trans
    (first.trans (Arm64KernelMemcpyPairMemory.outside s 0 profile _ other notWritten))

/-- The final real profile is exactly the original profile with the actual
16byte destination initialized, in both modes and after both writes. -/
theorem profile (s : Reference.AArch64.State) (input : MemoryProfile) (origin : BitVec 64)
    (stores : Arm64KernelMemcpyTwoStores.Result s input origin) :
    read_memory_profile stores.final.machine =
      some (Arm64KernelMemcpyWriteMemory.updated input 16 (Reference.AArch64.gpr s 0)) :=
  stores.profileAfter.trans (congrArg some (Arm64KernelMemcpyPairProfile.repeated_profile_eq input _))

/-- The SAME original two-load witness supplies the original16bytes copied
by one actual two-store witness, preserving its steps, frame and RET fetch. -/
theorem complete_from_loads (s current : Reference.AArch64.State) (origin : BitVec 64) (input : MemoryProfile)
    (loads : Arm64KernelMemcpyTwoLoads.Result s input origin) (reached : current = loads.final)
    (destinationEnd : Reference.AArch64.gpr s 5 = Reference.AArch64.gpr s 0+16#64)
    (profileRead : read_memory_profile s.machine = some input)
    (writable : MemoryMode.permitted input.writable (Reference.AArch64.gpr s 0) 16 = true) :
    ∃ stores : Arm64KernelMemcpyTwoStores.Result current input origin,
      read_mem_bytes 16 (Reference.AArch64.gpr current 0) stores.final.machine =
        read_mem_bytes 16 (Reference.AArch64.gpr s 1) s.machine ∧
      (∀ j : Fin 16, read_mem (Reference.AArch64.gpr current 0+BitVec.ofNat 64 j.val) stores.final.machine =
        read_mem (Reference.AArch64.gpr s 1+BitVec.ofNat 64 j.val) s.machine) ∧
      (∀ other : BitVec 64, 16 ≤ (other-Reference.AArch64.gpr current 0).toNat →
        read_mem other stores.final.machine = read_mem other current.machine) ∧
      read_memory_profile stores.final.machine =
        some (Arm64KernelMemcpyWriteMemory.updated input 16 (Reference.AArch64.gpr current 0)) := by
  obtain ⟨stores,_,_,_,low,high⟩ :=
    Arm64KernelMemcpyTwoStores.complete_from_loads s current origin input loads reached destinationEnd profileRead writable
  have actual : read_mem_bytes 16 (Reference.AArch64.gpr current 0) stores.final.machine =
      read_mem_bytes 16 (Reference.AArch64.gpr s 1) s.machine :=
    (readback current input origin stores).trans
      (((congrArg (fun hi : BitVec 64 => hi ++ Reference.AArch64.gpr current 12) high).trans
        (congrArg (fun lo : BitVec 64 => read_mem_bytes 8 (Reference.AArch64.gpr s 1+8#64) s.machine ++ lo) low)).trans
          (Arm64KernelMemcpyPairMemory.join_read s.machine (Reference.AArch64.gpr s 1)))
  refine ⟨stores,actual,?_,outside current input origin stores,profile current input origin stores⟩
  intro j
  exact (Arm64KernelMemcpyPairMemory.byte_at stores.final.machine (Reference.AArch64.gpr current 0) j).trans
    ((congrArg (fun value : BitVec 128 => value.extractLsb' (j.val*8) 8) actual).trans
      (Arm64KernelMemcpyPairMemory.byte_at s.machine (Reference.AArch64.gpr s 1) j).symm)

end KProgFormal.ClightRefinement.Arm64KernelMemcpyOutput
