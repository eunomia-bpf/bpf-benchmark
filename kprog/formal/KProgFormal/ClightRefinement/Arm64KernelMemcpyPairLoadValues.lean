import KProgFormal.ClightRefinement.Arm64KernelMemcpyTwoLoads

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64KernelMemcpyPairLoadValues

/-- Each real64bit half of a native16byte read is the corresponding8byte
read, including wraparound addresses and arbitrary underlying contents. -/
theorem half (s : ArmState) (address : BitVec 64) (i : Fin 2) :
    (read_mem_bytes 16 address s).extractLsb' (i.val*64) 64 =
      read_mem_bytes 8 (address+BitVec.ofNat 64 (i.val*8)) s := by
  simp only [Memory.State.read_mem_bytes_eq_mem_read_bytes]
  apply BitVec.eq_of_getLsbD_eq
  intro bit bound
  rw [BitVec.getLsbD_extractLsb',Memory.getLsbD_read_bytes (by decide),Memory.getLsbD_read_bytes (by decide)]
  have index : i.val*64+bit < 16*8 := by omega
  have div : (i.val*64+bit)/8 = i.val*8+bit/8 := by omega
  have mod : (i.val*64+bit)%8 = bit%8 := by omega
  simp only [bound,index,decide_true,Bool.true_and,div,mod,BitVec.ofNat_add,BitVec.add_assoc]

/-- Both captured LDPs deliver the same two words in either actual native
pair mode. Read observations keep their original initialization profile. -/
theorem values (s : Reference.AArch64.State) (i : Fin 2) (profile : MemoryProfile) (address : BitVec 64) :
    Reference.AArch64.gpr (Arm64KernelMemcpyPairRead.after s i profile address)
      (Arm64KernelMemcpyPairLoads.lowRegister i) = read_mem_bytes 8 address s.machine ∧
    Reference.AArch64.gpr (Arm64KernelMemcpyPairRead.after s i profile address)
      (Arm64KernelMemcpyPairLoads.highRegister i) = read_mem_bytes 8 (address+8#64) s.machine := by
  have low : (read_mem_bytes 16 address s.machine).extractLsb' 0 64 = read_mem_bytes 8 address s.machine := by
    simpa using half s.machine address 0
  have high : (read_mem_bytes 16 address s.machine).extractLsb' 64 64 = read_mem_bytes 8 (address+8#64) s.machine := by
    simpa using half s.machine address 1
  have middle : read_mem_bytes 8 (address+8#64) (Arm64KernelMemcpyPairRead.middle s profile address) =
      read_mem_bytes 8 (address+8#64) s.machine :=
    Arm64KernelMemcpyReadMemory.bytes_same s.machine _ rfl 8 (address+8#64)
  have cases : ∀ i : Fin 2, i = 0 ∨ i = 1 := by decide +kernel
  rcases cases i with rfl | rfl <;>
    cases mode : profile.pairSingleAccess <;>
    simp +decide [Arm64KernelMemcpyPairRead.after,mode,Arm64KernelMemcpyPairRead.singleAfter,
      Arm64KernelMemcpyPairRead.splitAfter,Arm64KernelMemcpyPairLoads.after,
      Arm64KernelMemcpyPairLoads.lowRegister,Arm64KernelMemcpyPairLoads.highRegister,
      Arm64KernelMemcpyPairLoads.fields,Reference.AArch64.gpr,write_pc,write_gpr_zr,
      write_gpr,r_of_w_same,r_of_w_different,low,high,middle]

/-- The SAME two actual step witnesses retain both first-pair words through
the second LDP and supply the repeated words in X12/X13. -/
theorem two_values (s : Reference.AArch64.State) (profile : MemoryProfile) (origin : BitVec 64)
    (result : Arm64KernelMemcpyTwoLoads.Result s profile origin) :
    Reference.AArch64.gpr result.final 6 = read_mem_bytes 8 (Reference.AArch64.gpr s 1) s.machine ∧
    Reference.AArch64.gpr result.final 7 = read_mem_bytes 8 (Reference.AArch64.gpr s 1+8#64) s.machine ∧
    Reference.AArch64.gpr result.final 12 = read_mem_bytes 8 (Reference.AArch64.gpr s 1) s.machine ∧
    Reference.AArch64.gpr result.final 13 = read_mem_bytes 8 (Reference.AArch64.gpr s 1+8#64) s.machine := by
  have first : Reference.AArch64.gpr result.loaded 6 = read_mem_bytes 8 (Reference.AArch64.gpr s 1) s.machine ∧
      Reference.AArch64.gpr result.loaded 7 = read_mem_bytes 8 (Reference.AArch64.gpr s 1+8#64) s.machine := by
    rw [result.loadedView]
    exact values s 0 profile (Reference.AArch64.gpr s 1)
  have second : Reference.AArch64.gpr result.final 12 = read_mem_bytes 8 (Reference.AArch64.gpr s 1) result.loaded.machine ∧
      Reference.AArch64.gpr result.final 13 = read_mem_bytes 8 (Reference.AArch64.gpr s 1+8#64) result.loaded.machine := by
    rw [result.finalView]
    exact values result.loaded 1 profile (Reference.AArch64.gpr s 1)
  obtain ⟨_,_,_,memory0,_,_,_,_,_⟩ := Arm64KernelMemcpyPairRead.frame s 0 profile (Reference.AArch64.gpr s 1)
  have memory : result.loaded.machine.mem = s.machine.mem :=
    (congrArg (fun state : Reference.AArch64.State => state.machine.mem) result.loadedView).trans memory0
  obtain ⟨_,_,fields1,_,_,_,_,_,_⟩ := Arm64KernelMemcpyPairRead.frame result.loaded 1 profile (Reference.AArch64.gpr s 1)
  have keep6 : Reference.AArch64.gpr result.final 6 = Reference.AArch64.gpr result.loaded 6 :=
    (congrArg (fun state => Reference.AArch64.gpr state 6) result.finalView).trans
      (fields1 (.GPR (6#5)) (by decide) (by decide) (by decide))
  have keep7 : Reference.AArch64.gpr result.final 7 = Reference.AArch64.gpr result.loaded 7 :=
    (congrArg (fun state => Reference.AArch64.gpr state 7) result.finalView).trans
      (fields1 (.GPR (7#5)) (by decide) (by decide) (by decide))
  exact ⟨keep6.trans first.1,keep7.trans first.2,
    second.1.trans (Arm64KernelMemcpyReadMemory.bytes_same s.machine result.loaded.machine memory 8 (Reference.AArch64.gpr s 1)),
    second.2.trans (Arm64KernelMemcpyReadMemory.bytes_same s.machine result.loaded.machine memory 8 (Reference.AArch64.gpr s 1+8#64))⟩

end KProgFormal.ClightRefinement.Arm64KernelMemcpyPairLoadValues
