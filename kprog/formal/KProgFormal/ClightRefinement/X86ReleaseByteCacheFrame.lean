import KProgFormal.ClightRefinement.X86RegisterWriteRspReleaseByteCall

namespace KProgFormal.ClightRefinement.X86ReleaseByteCacheFrame
open X86RegisterWriteRspReleaseByteCall (address temps)
open X86RegisterWriteRspReleaseWord (inputEF inputFunction stackRecord)

private theorem position_offset : ∀ (slot : Fin 6) (lane : Fin 8),
    X86RegisterWriteRspReleaseByteLoop.position slot lane =
      CC.Integers.Int64.repr (8 * (slot.val : Int) + lane.val) - (48#64) := by decide +kernel

/-- Equality of actual cache byte pointers implies equality of the original
signed-offset expressions, even for arbitrary wrapping pointer bases. -/
theorem same_position (base : CC.Integers.Ptrofs) (slot readSlot : Fin 6) (lane readLane : Fin 8)
    (same : address base readSlot readLane = address base slot lane) :
    X86RegisterWriteRspReleaseByteLoop.position readSlot readLane =
      X86RegisterWriteRspReleaseByteLoop.position slot lane := by
  have shifted := congrArg (fun pointer : CC.Integers.Ptrofs => pointer - base) same
  have displacement : CC.Integers.Ptrofs.repr (8 * (readSlot.val : Int) + readLane.val) =
      CC.Integers.Ptrofs.repr (8 * (slot.val : Int) + lane.val) := by
    simpa only [address, BitVec.add_comm base, BitVec.add_sub_cancel] using shifted
  change CC.Integers.Int64.repr (8 * (readSlot.val : Int) + readLane.val) =
    CC.Integers.Int64.repr (8 * (slot.val : Int) + lane.val) at displacement
  rw [position_offset, position_offset, displacement]

/-- The real strict release guard excludes every byte at or above the new
signed SP from the selected store address. This is source guard arithmetic. -/
theorem released_distinct_address (base : CC.Integers.Ptrofs) (slot : Fin 6) (lane : Fin 8)
    (readSlot : Fin 6) (readLane : Fin 8) (old next : BitVec 64)
    (released : X86RegisterWriteRspReleaseByteLoop.released slot lane old next = true)
    (above : CC.Integers.Int64.cmp .Cge (X86RegisterWriteRspReleaseByteLoop.position readSlot readLane) next = true) :
    CC.Integers.Ptrofs.unsigned (address base readSlot readLane) ≠
      CC.Integers.Ptrofs.unsigned (address base slot lane) := by
  intro same
  have pointers : address base readSlot readLane = address base slot lane := by
    apply BitVec.eq_of_toNat_eq
    change ((address base readSlot readLane).toNat : Int) = (address base slot lane).toNat at same
    omega
  have positions := same_position base slot readSlot lane readLane pointers
  have less : CC.Integers.Int64.cmp .Clt (X86RegisterWriteRspReleaseByteLoop.position slot lane) next = true := by
    cases first : CC.Integers.Int64.cmp .Cge (X86RegisterWriteRspReleaseByteLoop.position slot lane) old
    · simp only [X86RegisterWriteRspReleaseByteLoop.released, first, Bool.false_and, Bool.false_eq_true] at released
    · simpa only [X86RegisterWriteRspReleaseByteLoop.released, first, Bool.true_and] using released
  change (X86RegisterWriteRspReleaseByteLoop.position slot lane).slt next = true at less
  change (!(X86RegisterWriteRspReleaseByteLoop.position readSlot readLane).slt next) = true at above
  simp only [positions, less, Bool.not_true, Bool.false_eq_true] at above

/-- A frame only for actual cache bytes whose source offset is at or above
new SP. Existing outside-cache provider frames do not imply this property. -/
def AboveFrame (stack : CC.Block) (base : CC.Integers.Ptrofs) (next : BitVec 64) (before after : CC.Mem) : Prop :=
  ∀ readSlot readLane,
    CC.Integers.Int64.cmp .Cge (X86RegisterWriteRspReleaseByteLoop.position readSlot readLane) next = true →
    CC.Mem.load .Mint8unsigned after stack (CC.Integers.Ptrofs.unsigned (address base readSlot readLane)) =
      CC.Mem.load .Mint8unsigned before stack (CC.Integers.Ptrofs.unsigned (address base readSlot readLane))

/-- Actual per-call/store frames compose in execution order. -/
theorem frame_trans (stack : CC.Block) (base : CC.Integers.Ptrofs) (next : BitVec 64)
    (before middle after : CC.Mem) (first : AboveFrame stack base next before middle)
    (last : AboveFrame stack base next middle after) : AboveFrame stack base next before after := by
  intro slot lane above
  exact (last slot lane above).trans (first slot lane above)

/-- The genuine selected byte path retains its provider trace/full memory,
constructed store/readback and prior frames, and additionally preserves cache
bytes at/above new SP under the stated per-provider byte-frame ABI. -/
theorem selected (ge : CC.CGenv) (layout : X86RegisterReadValue.Layout ge)
    (stackLayout : ge.genv_cenv.get X86_program_profile_bpf._x86_sim_stack_mem = some stackRecord)
    (function : CC.Function) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (before supplied : CC.Mem) (binding stack input : CC.Block) (base : CC.Integers.Ptrofs)
    (slot : Fin 6) (lane : Fin 8) (old next value : BitVec 64) (trace : CC.Trace)
    (symbol : CC.Genv.findSymbol ge.genv_genv X86_program_profile_bpf._native_lab_entry_input = some input)
    (global : CC.Genv.findFunctPtr ge.genv_genv input = some inputFunction)
    (notLocal : e.get X86_program_profile_bpf._native_lab_entry_input = none)
    (bindingRead : le.get X86_program_profile_bpf.___x86_bind = some (.Vptr binding 0))
    (indexRead : le.get X86_program_profile_bpf.___x86_release_i__5 =
      some (.Vint (X86RegisterWriteRspReleaseSelect.index slot)))
    (laneRead : le.get X86_program_profile_bpf.___x86_release_lane__5 =
      some (.Vint (X86RegisterWriteRspReleaseByteLoop.laneArg lane)))
    (offsetRead : le.get X86_program_profile_bpf.___x86_release_off__5 =
      some (.Vlong (X86RegisterWriteRspReleaseSelect.offset slot)))
    (oldRead : le.get X86_program_profile_bpf.___x86_release_old__5 = some (.Vlong old))
    (nextRead : le.get X86_program_profile_bpf.___x86_release_new__5 = some (.Vlong next))
    (released : X86RegisterWriteRspReleaseByteLoop.released slot lane old next = true)
    (provider : CC.externalCall inputEF (CC.Genv.toSenv ge.genv_genv)
      [.Vint (6#32)] before trace (.Vlong value) supplied)
    (header : CC.Mem.load CC.Mptr supplied binding 8 = some (.Vptr stack base))
    (writable : CC.Mem.validAccess supplied .Mint8unsigned stack
      (CC.Integers.Ptrofs.unsigned (address base slot lane)) .Writable = true)
    (providerFrame : AboveFrame stack base next before supplied) :
    ∃ after, CC.Star (CC.Step2 ge)
      (.State function X86RegisterWriteRspReleaseByteLoop.body
        (X86RegisterWriteRspReleaseByteLoop.loopContinuation k) e le before)
      trace (.State function .Sskip (X86RegisterWriteRspReleaseByteLoop.loopContinuation k) e
        (temps (X86RegisterWriteRspReleaseByteLoop.temps le slot lane old next) value stack base) after) ∧
    CC.Mem.store .Mint8unsigned supplied stack (CC.Integers.Ptrofs.unsigned (address base slot lane))
      (.Vint ((value.setWidth 8).setWidth 32)) = some after ∧
    CC.Mem.load .Mint8unsigned after stack (CC.Integers.Ptrofs.unsigned (address base slot lane)) =
      some (.Vint ((value.setWidth 8).setWidth 32)) ∧
    after.access = supplied.access ∧ after.nextblock = supplied.nextblock ∧
    (∀ chunk other offset, other ≠ stack →
      CC.Mem.load chunk after other offset = CC.Mem.load chunk supplied other offset) ∧
    (∀ offset, offset ≠ CC.Integers.Ptrofs.unsigned (address base slot lane) →
      CC.Mem.load .Mint8unsigned after stack offset = CC.Mem.load .Mint8unsigned supplied stack offset) ∧ AboveFrame stack base next before after := by
  obtain ⟨after, run, stored, readback, access, frontier, frame, bytes⟩ :=
    X86RegisterWriteRspReleaseByteCall.selected ge layout stackLayout function e le k before supplied binding stack input base
      slot lane old next value trace symbol global notLocal bindingRead indexRead laneRead offsetRead oldRead nextRead
      released provider header writable
  refine ⟨after, run, stored, readback, access, frontier, frame, bytes, ?_⟩
  intro readSlot readLane above
  have different := released_distinct_address base slot lane readSlot readLane old next released above
  exact (bytes _ different).trans (providerFrame readSlot readLane above)

end KProgFormal.ClightRefinement.X86ReleaseByteCacheFrame
