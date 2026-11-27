import KProgFormal.ClightRefinement.Arm64KernelMemcpyTwoStores
import Arm.Memory.MemoryProofs

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64KernelMemcpyPairMemory

private theorem assemble (value : BitVec 128) :
    value.extractLsb' 64 64 ++ value.extractLsb' 0 64 = value := by
  simpa only [BitVec.extractLsb'_eq_self] using
    (BitVec.extractLsb'_append_extractLsb'_eq_extractLsb' (x := value)
      (start₁ := 0) (start₂ := 64) (len₁ := 64) (len₂ := 64) rfl)

/-- The actual16byte physical read is its two imported64bit halves. -/
theorem join_read (s : ArmState) (address : BitVec 64) :
    read_mem_bytes 8 (address+8#64) s ++ read_mem_bytes 8 address s = read_mem_bytes 16 address s := by
  have low : (read_mem_bytes 16 address s).extractLsb' 0 64 = read_mem_bytes 8 address s := by
    simpa using Arm64KernelMemcpyPairLoadValues.half s address 0
  have high : (read_mem_bytes 16 address s).extractLsb' 64 64 = read_mem_bytes 8 (address+8#64) s := by
    simpa using Arm64KernelMemcpyPairLoadValues.half s address 1
  exact (congrArg (fun hi : BitVec 64 => hi ++ read_mem_bytes 8 address s) high.symm).trans
    ((congrArg (fun lo : BitVec 64 => (read_mem_bytes 16 address s).extractLsb' 64 64 ++ lo) low.symm).trans
      (assemble (read_mem_bytes 16 address s)))

/-- Adjacent8byte native accesses are disjoint even across wrap64. -/
theorem separate (address : BitVec 64) :
    mem_separate address (address+7#64) (address+8#64) (address+15#64) = true := by
  have actual := mem_separate_contiguous_regions address (7#64) (7#64) (by decide)
  simpa only [BitVec.add_assoc,show (7#64)+(1#64) = 8#64 by decide,
    show (8#64)+(7#64) = 15#64 by decide] using actual

/-- The real split store's two imported writes read back the exact operands. -/
theorem split_readback (s : ArmState) (address : BitVec 64) (low high : BitVec 64) :
    read_mem_bytes 16 address (write_mem_bytes 8 (address+8#64) high (write_mem_bytes 8 address low s)) = high ++ low := by
  have lowRead : read_mem_bytes 8 address (write_mem_bytes 8 (address+8#64) high (write_mem_bytes 8 address low s)) = low := by
    rw [read_mem_bytes_of_write_mem_bytes_different (by decide) (by decide)]
    · exact read_mem_bytes_of_write_mem_bytes_same (by decide)
    · simpa only [show BitVec.ofNat 64 (8-1) = 7#64 by decide,BitVec.add_assoc,
        show (8#64)+(7#64) = 15#64 by decide] using separate address
  have highRead : read_mem_bytes 8 (address+8#64) (write_mem_bytes 8 (address+8#64) high (write_mem_bytes 8 address low s)) = high :=
    read_mem_bytes_of_write_mem_bytes_same (by decide)
  rw [←join_read,lowRead,highRead]

/-- The actual STP state retains precisely the imported byte-write memory;
profile/history/PC updates leave those bytes intact. -/
theorem memory (s : Reference.AArch64.State) (i : Fin 2) (profile : MemoryProfile) (address : BitVec 64) :
    (Arm64KernelMemcpyPairWrite.after s i profile address).machine.mem =
      if profile.pairSingleAccess then
        (write_mem_bytes 16 address (Arm64KernelMemcpyPairWrite.high s i ++ Arm64KernelMemcpyPairWrite.low s i) s.machine).mem
      else (write_mem_bytes 8 (address+8#64) (Arm64KernelMemcpyPairWrite.high s i)
        (write_mem_bytes 8 address (Arm64KernelMemcpyPairWrite.low s i) s.machine)).mem := by
  cases mode : profile.pairSingleAccess <;>
    simp only [Arm64KernelMemcpyPairWrite.after,Arm64KernelMemcpyPairStores.after,
      Arm64KernelMemcpyPairWrite.written,mode,Bool.false_eq_true,ite_false,ite_true,
      Arm64KernelMemcpyPairWrite.singleWritten,Arm64KernelMemcpyPairWrite.splitWritten,
      Arm64KernelMemcpyPairWrite.middle,Arm64KernelMemcpyPairWrite.Write,
      Arm64KernelMemcpyWriteMemory.after,record_memory_access,write_memory_profile,
      write_pc,w,write_base_pc,Memory.write_mem_bytes_eq_mem_write_bytes]

/-- Both real STP modes read back the original high++low operands. -/
theorem readback (s : Reference.AArch64.State) (i : Fin 2) (profile : MemoryProfile) (address : BitVec 64) :
    read_mem_bytes 16 address (Arm64KernelMemcpyPairWrite.after s i profile address).machine =
      Arm64KernelMemcpyPairWrite.high s i ++ Arm64KernelMemcpyPairWrite.low s i := by
  cases mode : profile.pairSingleAccess with
  | false =>
    have same : (Arm64KernelMemcpyPairWrite.after s i profile address).machine.mem =
        (write_mem_bytes 8 (address+8#64) (Arm64KernelMemcpyPairWrite.high s i)
          (write_mem_bytes 8 address (Arm64KernelMemcpyPairWrite.low s i) s.machine)).mem := by
      simpa only [mode,Bool.false_eq_true,ite_false] using memory s i profile address
    exact (Arm64KernelMemcpyReadMemory.bytes_same _ _ same 16 address).trans
      (split_readback s.machine address _ _)
  | true =>
    have same : (Arm64KernelMemcpyPairWrite.after s i profile address).machine.mem =
        (write_mem_bytes 16 address (Arm64KernelMemcpyPairWrite.high s i ++ Arm64KernelMemcpyPairWrite.low s i) s.machine).mem := by
      simpa only [mode,ite_true] using memory s i profile address
    exact (Arm64KernelMemcpyReadMemory.bytes_same _ _ same 16 address).trans
      (read_mem_bytes_of_write_mem_bytes_same (by decide))

/-- A byte outside the real wrapping store interval is physically retained
in either native pair mode. -/
theorem outside (s : Reference.AArch64.State) (i : Fin 2) (profile : MemoryProfile) (address other : BitVec 64)
    (notWritten : 16 ≤ (other-address).toNat) :
    read_mem other (Arm64KernelMemcpyPairWrite.after s i profile address).machine = read_mem other s.machine := by
  have distance : (16#64) ≤ other-address := notWritten
  have sep16 : mem_separate other other address (address+15#64) = true := by
    simp only [mem_separate,mem_overlap]
    bv_decide
  have sepLow : mem_separate other other address (address+7#64) = true := by
    simp only [mem_separate,mem_overlap]
    bv_decide
  have sepHigh : mem_separate other other (address+8#64) (address+15#64) = true := by
    simp only [mem_separate,mem_overlap]
    bv_decide
  cases mode : profile.pairSingleAccess with
  | false =>
    have same : (Arm64KernelMemcpyPairWrite.after s i profile address).machine.mem =
        (write_mem_bytes 8 (address+8#64) (Arm64KernelMemcpyPairWrite.high s i)
          (write_mem_bytes 8 address (Arm64KernelMemcpyPairWrite.low s i) s.machine)).mem := by
      simpa only [mode,Bool.false_eq_true,ite_false] using memory s i profile address
    have raw : read_mem other (write_mem_bytes 8 (address+8#64) (Arm64KernelMemcpyPairWrite.high s i)
        (write_mem_bytes 8 address (Arm64KernelMemcpyPairWrite.low s i) s.machine)) = read_mem other s.machine := by
      rw [read_mem_of_write_mem_bytes_different (by decide),read_mem_of_write_mem_bytes_different (by decide)]
      · simpa only [show BitVec.ofNat 64 (8-1) = 7#64 by decide] using sepLow
      · simpa only [show BitVec.ofNat 64 (8-1) = 7#64 by decide,BitVec.add_assoc,
          show (8#64)+(7#64) = 15#64 by decide] using sepHigh
    exact (congrArg (fun mem : Memory => mem other) same).trans raw
  | true =>
    have same : (Arm64KernelMemcpyPairWrite.after s i profile address).machine.mem =
        (write_mem_bytes 16 address (Arm64KernelMemcpyPairWrite.high s i ++ Arm64KernelMemcpyPairWrite.low s i) s.machine).mem := by
      simpa only [mode,ite_true] using memory s i profile address
    have raw : read_mem other (write_mem_bytes 16 address
        (Arm64KernelMemcpyPairWrite.high s i ++ Arm64KernelMemcpyPairWrite.low s i) s.machine) = read_mem other s.machine :=
      read_mem_of_write_mem_bytes_different (by decide) sep16
    exact (congrArg (fun mem : Memory => mem other) same).trans raw

/-- Every native byte in the real16byte read is its imported extraction,
using the wrapping bit-level read theorem rather than a nonwrap domain. -/
theorem byte_at (s : ArmState) (address : BitVec 64) (j : Fin 16) :
    read_mem (address+BitVec.ofNat 64 j.val) s = (read_mem_bytes 16 address s).extractLsb' (j.val*8) 8 := by
  simp only [Memory.State.read_mem_bytes_eq_mem_read_bytes,read_mem,read_store]
  apply BitVec.eq_of_getLsbD_eq
  intro bit bound
  rw [BitVec.getLsbD_extractLsb',Memory.getLsbD_read_bytes (by decide)]
  have index : j.val*8+bit < 16*8 := by omega
  have div : (j.val*8+bit)/8 = j.val := by omega
  have mod : (j.val*8+bit)%8 = bit := by omega
  simp only [bound,index,decide_true,Bool.true_and,div,mod]

/-- Both actual pair modes produce exactly the same physical memory. -/
theorem mode_memory_eq (s : Reference.AArch64.State) (i : Fin 2) (profile : MemoryProfile) (address : BitVec 64) :
    (Arm64KernelMemcpyPairWrite.after s i profile address).machine.mem =
      (Arm64KernelMemcpyPairWrite.after s i {profile with pairSingleAccess := true} address).machine.mem := by
  funext other
  by_cases inside : (other-address).toNat < 16
  · let j : Fin 16 := ⟨(other-address).toNat,inside⟩
    have sameAddress : address+BitVec.ofNat 64 j.val = other := by
      change address+BitVec.ofNat 64 (other-address).toNat = other
      simp only [BitVec.ofNat_toNat]
      bv_omega
    have first := byte_at (Arm64KernelMemcpyPairWrite.after s i profile address).machine address j
    have second := byte_at (Arm64KernelMemcpyPairWrite.after s i {profile with pairSingleAccess := true} address).machine address j
    rw [sameAddress,readback] at first second
    exact first.trans second.symm
  · exact (outside s i profile address other (by omega)).trans
      (outside s i {profile with pairSingleAccess := true} address other (by omega)).symm

end KProgFormal.ClightRefinement.Arm64KernelMemcpyPairMemory
