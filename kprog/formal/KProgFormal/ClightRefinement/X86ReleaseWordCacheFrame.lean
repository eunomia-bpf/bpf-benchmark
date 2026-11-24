import KProgFormal.ClightRefinement.X86ReleaseByteCacheFrame

namespace KProgFormal.ClightRefinement.X86ReleaseWordCacheFrame
open X86RegisterWriteRspReleaseWord (address stackRecord inputEF inputFunction temps)
open X86ReleaseByteCacheFrame (AboveFrame)

private theorem byte_address : ∀ (slot : Fin 6) (lane : Fin 8),
    CC.Integers.Ptrofs.repr (8 * (slot.val : Int) + lane.val) =
      CC.Integers.Ptrofs.repr (8 * (slot.val : Int)) + CC.Integers.Ptrofs.repr lane.val := by decide +kernel

private theorem lane_before_end : ∀ (slot : Fin 6) (lane : Fin 8),
    (X86RegisterWriteRspReleaseByteLoop.position slot lane).toInt <
      (X86RegisterWriteRspReleaseSelect.offset slot + 8#64).toInt := by decide +kernel

/-- A byte at or above the actual new-SP boundary is outside the linear
Mint64 store range selected by the original whole-word release guard.
Modular cache bases may wrap; no extra pointer-range premise is used. -/
theorem whole_disjoint (base : CC.Integers.Ptrofs) (slot readSlot : Fin 6) (readLane : Fin 8)
    (old next : BitVec 64)
    (whole : X86RegisterWriteRspReleaseSelect.whole slot old next = true)
    (above : CC.Integers.Int64.cmp .Cge
      (X86RegisterWriteRspReleaseByteLoop.position readSlot readLane) next = true) :
    CC.Integers.Ptrofs.unsigned (X86RegisterWriteRspReleaseByteCall.address base readSlot readLane) + 1 ≤
      CC.Integers.Ptrofs.unsigned (address base slot) ∨
    CC.Integers.Ptrofs.unsigned (address base slot) + 8 ≤
      CC.Integers.Ptrofs.unsigned (X86RegisterWriteRspReleaseByteCall.address base readSlot readLane) := by
  let word := address base slot
  let read := X86RegisterWriteRspReleaseByteCall.address base readSlot readLane
  apply Classical.byContradiction
  intro disjoint
  have overlap : word.toNat ≤ read.toNat ∧ read.toNat < word.toNat + 8 := by
    change ¬ ((read.toNat : Int) + 1 ≤ word.toNat ∨ (word.toNat : Int) + 8 ≤ read.toNat) at disjoint
    omega
  let lane : Fin 8 := ⟨read.toNat - word.toNat, by omega⟩
  have bytePointer : X86RegisterWriteRspReleaseByteCall.address base slot lane =
      word + CC.Integers.Ptrofs.repr lane.val := by
    simp only [X86RegisterWriteRspReleaseByteCall.address, word, address, byte_address, BitVec.add_assoc]
  have same : X86RegisterWriteRspReleaseByteCall.address base slot lane = read := by
    rw [bytePointer]
    apply BitVec.eq_of_toNat_eq
    simp only [BitVec.toNat_add]
    have bound := read.isLt
    change read.toNat < 18446744073709551616 at bound
    have laneBound := lane.isLt
    change read.toNat - word.toNat < 8 at laneBound
    change ((word.toNat + ((read.toNat - word.toNat) % 18446744073709551616)) % 18446744073709551616) = read.toNat
    omega
  have positions := X86ReleaseByteCacheFrame.same_position base slot readSlot lane readLane same.symm
  have endBefore : CC.Integers.Int64.cmp .Cle
      (X86RegisterWriteRspReleaseSelect.offset slot + 8#64) next = true := by
    cases first : CC.Integers.Int64.cmp .Cge (X86RegisterWriteRspReleaseSelect.offset slot) old
    · simp only [X86RegisterWriteRspReleaseSelect.whole, first, Bool.false_and, Bool.false_eq_true] at whole
    · simpa only [X86RegisterWriteRspReleaseSelect.whole, first, Bool.true_and] using whole
  change (!next.slt (X86RegisterWriteRspReleaseSelect.offset slot + 8#64)) = true at endBefore
  change (!(X86RegisterWriteRspReleaseByteLoop.position readSlot readLane).slt next) = true at above
  simp only [BitVec.slt_eq_decide, Bool.not_eq_true', decide_eq_false_iff_not] at endBefore above
  have inside := lane_before_end slot lane
  rw [positions] at above
  omega

/-- The actual constructed whole-word store preserves the source cache-byte
reads above the boundary; the provider's preceding frame remains explicit. -/
theorem store_frame (base : CC.Integers.Ptrofs) (stack : CC.Block) (slot : Fin 6)
    (old next value : BitVec 64) (before supplied after : CC.Mem)
    (whole : X86RegisterWriteRspReleaseSelect.whole slot old next = true)
    (stored : CC.Mem.store .Mint64 supplied stack (CC.Integers.Ptrofs.unsigned (address base slot))
      (.Vlong value) = some after)
    (providerFrame : AboveFrame stack base next before supplied) : AboveFrame stack base next before after := by
  intro readSlot readLane above
  have disjoint := whole_disjoint base slot readSlot readLane old next whole above
  have unchanged := CC.Mem.load_store_other stored .Mint8unsigned stack
    (CC.Integers.Ptrofs.unsigned (X86RegisterWriteRspReleaseByteCall.address base readSlot readLane))
    (.inr disjoint)
  exact unchanged.trans (providerFrame readSlot readLane above)

/-- Original whole-word guard, actual provider trace and real Mint64 store,
with cache-byte preservation derived from the store and explicit provider ABI. -/
theorem selected (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (stackLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_stack_mem = some stackRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (before supplied : CC.Mem) (binding stack input : CC.Block) (base : CC.Integers.Ptrofs)
    (slot : Fin 6) (old next value : BitVec 64) (trace : CC.Trace)
    (symbol : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._native_lab_entry_input = some input)
    (global : CC.Genv.findFunctPtr ge.genv_genv input = some inputFunction)
    (notLocal : e.get X86_program_profile_bpf._native_lab_entry_input = none)
    (bindingRead : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr binding 0))
    (indexRead : le.get X86_program_profile_bpf.___x86_release_i__5 =
      some (.Vint (X86RegisterWriteRspReleaseSelect.index slot)))
    (offsetRead : le.get X86_program_profile_bpf.___x86_release_off__5 =
      some (.Vlong (X86RegisterWriteRspReleaseSelect.offset slot)))
    (oldRead : le.get X86_program_profile_bpf.___x86_release_old__5 = some (.Vlong old))
    (nextRead : le.get X86_program_profile_bpf.___x86_release_new__5 = some (.Vlong next))
    (whole : X86RegisterWriteRspReleaseSelect.whole slot old next = true)
    (provider : CC.externalCall inputEF (CC.Genv.toSenv ge.genv_genv)
      [.Vint (6#32)] before trace (.Vlong value) supplied)
    (header : CC.Mem.load CC.Mptr supplied binding 8 = some (.Vptr stack base))
    (writable : CC.Mem.validAccess supplied .Mint64 stack
      (CC.Integers.Ptrofs.unsigned (address base slot)) .Writable = true)
    (providerFrame : AboveFrame stack base next before supplied) :
    ∃ after, CC.Star (CC.Step2 ge)
      (.State function X86RegisterWriteRspReleaseLoop.iteration k e le before)
      trace (.State function .Sskip k e
        (temps (X86RegisterWriteRspReleaseSelect.temps le slot old next) value stack base) after) ∧
    CC.Mem.store .Mint64 supplied stack (CC.Integers.Ptrofs.unsigned (address base slot))
      (.Vlong value) = some after ∧
    CC.Mem.load .Mint64 after stack (CC.Integers.Ptrofs.unsigned (address base slot)) = some (.Vlong value) ∧
    after.access = supplied.access ∧ after.nextblock = supplied.nextblock ∧
    (∀ chunk other offset, other ≠ stack →
      CC.Mem.load chunk after other offset = CC.Mem.load chunk supplied other offset) ∧
    AboveFrame stack base next before after := by
  obtain ⟨after, run, stored, readback, access, frontier, frame⟩ :=
    X86RegisterWriteRspReleaseWord.selected ge layout stackLayout function e le k before supplied binding stack input base
      slot old next value trace symbol global notLocal bindingRead indexRead offsetRead oldRead nextRead whole
      provider header writable
  exact ⟨after, run, stored, readback, access, frontier, frame,
    store_frame base stack slot old next value before supplied after whole stored providerFrame⟩

end KProgFormal.ClightRefinement.X86ReleaseWordCacheFrame
