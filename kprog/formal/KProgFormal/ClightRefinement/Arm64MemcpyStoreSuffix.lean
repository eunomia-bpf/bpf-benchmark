import KProgFormal.ClightRefinement.Arm64MemcpyTagLoop
import KProgFormal.ClightRefinement.Arm64MemcpyByteLane
import KProgFormal.ClightRefinement.Arm64MemcpyBytePacket
import KProgFormal.ClightRefinement.Arm64MemcpyLaneGates
import KProgFormal.ClightRefinement.Arm64MemcpyPostStore

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyStoreSuffix

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpySource (handler)

private def inputs : List CC.Ident :=
  [Arm64Program._entry,Arm64Program.___a64_lib_len,Arm64Program.___a64_lib_i,
   Arm64Program.___a64_lib_src_tag,Arm64Program.___a64_stw_index,Arm64Program.___a64_stw_width,
   Arm64Program.___a64_stw_value,Arm64Program.___a64_loss_off]
private def Same (le next : CC.TempEnv) : Prop := ∀ id ∈ inputs, next.get id = le.get id

private theorem tag_same (le : CC.TempEnv) (i : Fin 16) (tags : CC.Block) :
    Same le (Arm64MemcpyTagLoop.temps le i tags) := by
  have names : ∀ id ∈ inputs, Arm64Program.___tv__1 ≠ id ∧ Arm64Program._t'38 ≠ id ∧
      Arm64Program.___tp__1 ≠ id ∧ Arm64Program._t'143 ≠ id ∧
      Arm64Program.___ts__1 ≠ id ∧ Arm64Program.___ti__1 ≠ id := by decide +kernel
  intro id member
  have other := names id member
  exact Arm64MemcpyTagLoop.kept le i tags id other.1 other.2.1 other.2.2.1
    other.2.2.2.1 other.2.2.2.2.1 other.2.2.2.2.2

private theorem gates_same (le : CC.TempEnv) (index : BitVec 64) :
    Same le (Arm64MemcpyByteGates.temps le index) := by
  have names : ∀ id ∈ inputs, Arm64Program.___a64_stw_last ≠ id ∧ Arm64Program._t'39 ≠ id := by decide +kernel
  intro id member
  exact Arm64MemcpyByteGates.kept le index id (names id member).1 (names id member).2

private theorem byte_same (le : CC.TempEnv) (byte : BitVec 8) (stack : CC.Block) :
    Same le (Arm64MemcpyByteWrite.temps (Arm64MemcpyByteLane.temps le byte) stack) := by
  have names : ∀ id ∈ inputs, Arm64Program._t'141 ≠ id ∧ Arm64Program.___kprog_a64_bl_shift ≠ id ∧
      Arm64Program.___kprog_a64_bl_value ≠ id ∧ Arm64Program.___kprog_a64_bl_lane ≠ id := by decide +kernel
  intro id member
  have other := names id member
  change (((((le.set Arm64Program.___kprog_a64_bl_lane (.Vlong 0)).set
    Arm64Program.___kprog_a64_bl_value (.Vlong (byte.setWidth 64))).set
    Arm64Program.___kprog_a64_bl_shift (.Vlong 0)).set
    Arm64Program.___kprog_a64_bl_shift (.Vlong 0)).set Arm64Program._t'141 (.Vptr stack 0)).get id = le.get id
  simp only [CC.PTree.gso _ _ _ _ other.1,CC.PTree.gso _ _ _ _ other.2.1,
    CC.PTree.gso _ _ _ _ other.2.2.1,CC.PTree.gso _ _ _ _ other.2.2.2]

private theorem lanes_same (le : CC.TempEnv) : Same le (Arm64MemcpyLaneGates.temps le) := by
  have names : ∀ id ∈ inputs, Arm64Program._t'47 ≠ id ∧ Arm64Program._t'46 ≠ id ∧
      Arm64Program._t'45 ≠ id ∧ Arm64Program._t'44 ≠ id ∧ Arm64Program._t'43 ≠ id ∧
      Arm64Program._t'42 ≠ id ∧ Arm64Program._t'41 ≠ id := by decide +kernel
  intro id member
  have other := names id member
  simp only [Arm64MemcpyLaneGates.temps,CC.PTree.gso _ _ _ _ other.1,
    CC.PTree.gso _ _ _ _ other.2.1,CC.PTree.gso _ _ _ _ other.2.2.1,
    CC.PTree.gso _ _ _ _ other.2.2.2.1,CC.PTree.gso _ _ _ _ other.2.2.2.2.1,
    CC.PTree.gso _ _ _ _ other.2.2.2.2.2.1,CC.PTree.gso _ _ _ _ other.2.2.2.2.2.2]

private theorem post_same (le : CC.TempEnv) (sp : CC.Block) :
    Same le (Arm64MemcpyPostStore.temps le sp) := by
  have names : ∀ id ∈ inputs, Arm64Program._t'106 ≠ id ∧ Arm64Program._t'105 ≠ id := by decide +kernel
  intro id member
  exact Arm64MemcpyPostStore.kept le sp id (names id member).1 (names id member).2

private theorem compose {first second third : CC.TempEnv} (a : Same first second) (b : Same second third) :
    Same first third := fun id member => (b id member).trans (a id member)

private def retemp {initial seed calleeBefore m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    {le nextLe : CC.TempEnv} {n : Nat}
    (prior : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore n m le)
    (same : Same le nextLe) :
    Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore n m nextLe :=
  ⟨prior.packet,prior.callee,(same Arm64Program._entry (by decide +kernel)).trans prior.entryRead,
    (same Arm64Program.___a64_lib_len (by decide +kernel)).trans prior.length,
    (same Arm64Program.___a64_lib_i (by decide +kernel)).trans prior.counter,
    (same Arm64Program.___a64_lib_src_tag (by decide +kernel)).trans prior.sourceTag,prior.copied⟩

/-- The source byte store uses the actual producer allocation and current
Freeable rights of that same stack object. -/
theorem writable {initial seed m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry}
    (resources : Arm64ProgramEntryResources.Resources initial m entry) :
    CC.Mem.rangePerm m base.stack.block 0 160 .Cur .Writable = true := by
  have binding := Arm64ProgramEntryAllocation.local_binding initial _ _ _ base.stack.binding
  have owned := resources.freeable _ _ binding
  have size := Arm64ProgramEntryAllocation.local_size
    (Arm64Producer.tailLocalName 0,Arm64Producer.tailLocalType 0) (by decide +kernel)
  have actualSize : CC.sizeof Arm64Producer.ge.genv_cenv (Arm64Producer.tailLocalType 0) = 160 := by decide +kernel
  rw [size,actualSize] at owned
  exact CC.Mem.rangePerm_implies owned (by decide : CC.permOrder .Freeable .Writable = true)

/-- Compose source81 through its genuine tag-word and destination byte
stores, the remaining lane gates, and the actual SP and wrapper exits.
The same current packet and copied prefix reach the original increment. -/
theorem execute_framed {initial seed calleeBefore before : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (le : CC.TempEnv) (k : CC.Cont) (i : Fin 16)
    (prior : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore i.val before le)
    (producerBound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (callerBound : (Arm64MemcpySource.allocation calleeBefore).2.nextblock.toNat ≤ before.nextblock.toNat)
    (hindex : le.get Arm64Program.___a64_stw_index = some (.Vlong (BitVec.ofNat 64 (80+i.val))))
    (hwidth : le.get Arm64Program.___a64_stw_width = some (.Vint 1))
    (hvalue : le.get Arm64Program.___a64_stw_value = some (.Vlong (byte.setWidth 64)))
    (hoff : le.get Arm64Program.___a64_loss_off = some (.Vlong ((-16#64)+BitVec.ofNat 64 i.val)))
    (cell : Arm64Producer.TailLocal initial 5) (flagValue : BitVec 8)
    (flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue before) :
    ∃ tagged after nextLe,
      ∃ _next : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore i.val after nextLe,
      CC.Star (CC.Step2 world)
        (.State handler Arm64Program.s_kprog_arm64_program_memcpy_81
          (Arm64MemcpyStoreIndex.continuation (Arm64MemcpyReadCaller.continuation k))
          (Arm64MemcpySource.allocation calleeBefore).1 le before) CC.E0
        (.State handler .Sskip k (Arm64MemcpySource.allocation calleeBefore).1 nextLe after) ∧
      CC.Mem.store .Mint64 before base.tags.block 8 (.Vlong 0) = some tagged ∧
      CC.Mem.store .Mint8unsigned tagged base.stack.block (80+(i.val : Int)) (.Vint (byte.setWidth 32)) = some after ∧
      CC.Mem.load .Mint8unsigned after base.stack.block (80+(i.val : Int)) = some (.Vint (byte.setWidth 32)) ∧
      Arm64MemcpyReadCurrent.Flag entry cell flagValue after ∧
      FrameBelow initial.nextblock before after ∧ after.nextblock = before.nextblock ∧
      (∀ q : Fin 31, Arm64EntryMemory.gpr after.nextblock after (.Vptr entry.block 0) q.val =
        Arm64EntryMemory.gpr before.nextblock before (.Vptr entry.block 0) q.val) := by
  let e := (Arm64MemcpySource.allocation calleeBefore).1
  let cont := Arm64MemcpyStoreIndex.continuation (Arm64MemcpyReadCaller.continuation k)
  let tagLe := Arm64MemcpyTagLoop.temps le i base.tags.block
  obtain ⟨tagged,tagCurrent,tagRun,tagStore,_tagFrame,tagFlag,tagNext⟩ :=
    Arm64MemcpyTagLoop.current le cont i prior producerBound callerBound hindex cell flagValue flag
  have tagSame := tag_same le i base.tags.block
  have tagWidth := (tagSame Arm64Program.___a64_stw_width (by decide +kernel)).trans hwidth
  have tagIndex := (tagSame Arm64Program.___a64_stw_index (by decide +kernel)).trans hindex
  have gatesRun := Arm64MemcpyByteGates.to_byte e tagLe tagged cont (BitVec.ofNat 64 (80+i.val)) tagWidth tagIndex
  let gateLe := Arm64MemcpyByteGates.temps tagLe (BitVec.ofNat 64 (80+i.val))
  have gatesSame := gates_same tagLe (BitVec.ofNat 64 (80+i.val))
  have gateSame := compose tagSame gatesSame
  let gateCurrent := retemp tagCurrent gatesSame
  have stackPointer : CC.Mem.load CC.Mptr tagged entry.block 608 = some (.Vptr base.stack.block 0) := by
    rw [←gateCurrent.packet.stackSame]
    exact gateCurrent.packet.view.stackPointer
  let index : Fin 160 := ⟨80+i.val,by omega⟩
  obtain ⟨after,byteRun,byteStore,byteRead,_byteAccess,byteNext⟩ :=
    Arm64MemcpyByteLane.execute e gateLe tagged (.Kseq Arm64MemcpyByteGates.afterByte cont)
      entry.block base.stack.block index byte gateCurrent.entryRead
      ((gateSame Arm64Program.___a64_stw_index (by decide +kernel)).trans hindex)
      ((gateSame Arm64Program.___a64_stw_value (by decide +kernel)).trans hvalue)
      stackPointer (writable gateCurrent.packet.resources)
  have actualStore : CC.Mem.store .Mint8unsigned tagged base.stack.block
      (80+(i.val : Int)) (.Vint (byte.setWidth 32)) = some after := by
    have address : (index.val : Int) = 80+(i.val : Int) := by dsimp [index]
    simpa only [address] using byteStore
  have actualRead : CC.Mem.load .Mint8unsigned after base.stack.block
      (80+(i.val : Int)) = some (.Vint (byte.setWidth 32)) := by
    have address : (index.val : Int) = 80+(i.val : Int) := by dsimp [index]
    simpa only [address] using byteRead
  let byteLe := Arm64MemcpyByteWrite.temps (Arm64MemcpyByteLane.temps gateLe byte) base.stack.block
  have byteSame := byte_same gateLe byte base.stack.block
  let byteCurrent := retemp (Arm64MemcpyBytePacket.current i gateCurrent actualStore) byteSame
  have flagAfter := Arm64MemcpyByteStorage.flag base.stack (80+(i.val : Int)) byte actualStore tagFlag
  have enterLanes : InternalRun world 1
      (.State handler .Sskip (.Kseq Arm64MemcpyByteGates.afterByte cont) e byteLe after)
      (.State handler Arm64MemcpyByteGates.afterByte cont e byteLe after) :=
    .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  have beforeLanesSame := compose gateSame byteSame
  have lanesRun := Arm64MemcpyLaneGates.execute e byteLe after cont
    ((beforeLanesSame Arm64Program.___a64_stw_width (by decide +kernel)).trans hwidth)
  let laneLe := Arm64MemcpyLaneGates.temps byteLe
  have laneSame := lanes_same byteLe
  let laneCurrent := retemp byteCurrent laneSame
  have beforePostSame := compose beforeLanesSame laneSame
  have spRead : CC.Mem.load .Mint64 after laneCurrent.packet.storage.sp.block 0 = some (.Vlong (-32#64)) := by
    rw [laneCurrent.packet.storage.spRead,laneCurrent.packet.spAtBase]
  have postRun := Arm64MemcpyPostStore.after_write e laneLe after k entry.block
    laneCurrent.packet.storage.sp.block i laneCurrent.entryRead
    ((beforePostSame Arm64Program.___a64_loss_off (by decide +kernel)).trans hoff)
    laneCurrent.packet.storage.spPointer spRead
  let nextLe := Arm64MemcpyPostStore.temps laneLe laneCurrent.packet.storage.sp.block
  let next := retemp laneCurrent (post_same laneLe laneCurrent.packet.storage.sp.block)
  have tagFrame := Arm64MemcpyTagFrame.word_store tagStore prior.packet.tagBytes initial.nextblock
  have live := ((allocated_local_storage (CC.doAllocVariables_sound _ _ _ _ _ _
    (Prod.eta (Arm64Producer.allocation initial)).symm)).1 _ _ base.stack.binding).1
  have tagOlder := Arm64MemcpyTagFrame.word_store tagStore prior.packet.tagBytes before.nextblock
  let tagStorage := Arm64MemsetFreeState.storage before.nextblock producerBound tagOlder prior.packet.storage
  have tagGprs (j : Fin 31) := Arm64MemsetFreeState.gpr before.nextblock producerBound tagOlder prior.packet.storage j
  have byteGprs (j : Fin 31) := Arm64MemcpyByteStorage.gpr base.stack (80+(i.val : Int)) byte actualStore tagStorage j
  refine ⟨tagged,after,nextLe,next,?_,tagStore,actualStore,actualRead,flagAfter,
    tagFrame.trans (FrameBelow.store live actualStore),byteNext.trans tagNext,fun j => (byteGprs j).trans (tagGprs j)⟩
  simpa only [CC.E0,CC.Eapp,List.nil_append] using star_trans tagRun
    (star_trans gatesRun.sound (star_trans byteRun (star_trans enterLanes.sound
      (star_trans lanesRun.sound postRun.sound))))
/-- The original complete interface uses the same actual execution. -/
theorem execute {initial seed calleeBefore before : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (le : CC.TempEnv) (k : CC.Cont) (i : Fin 16)
    (prior : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore i.val before le)
    (producerBound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (callerBound : (Arm64MemcpySource.allocation calleeBefore).2.nextblock.toNat ≤ before.nextblock.toNat)
    (hindex : le.get Arm64Program.___a64_stw_index = some (.Vlong (BitVec.ofNat 64 (80+i.val))))
    (hwidth : le.get Arm64Program.___a64_stw_width = some (.Vint 1))
    (hvalue : le.get Arm64Program.___a64_stw_value = some (.Vlong (byte.setWidth 64)))
    (hoff : le.get Arm64Program.___a64_loss_off = some (.Vlong ((-16#64)+BitVec.ofNat 64 i.val)))
    (cell : Arm64Producer.TailLocal initial 5) (flagValue : BitVec 8)
    (flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue before) :
    ∃ tagged after nextLe,
      ∃ _next : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore i.val after nextLe,
      CC.Star (CC.Step2 world)
        (.State handler Arm64Program.s_kprog_arm64_program_memcpy_81
          (Arm64MemcpyStoreIndex.continuation (Arm64MemcpyReadCaller.continuation k))
          (Arm64MemcpySource.allocation calleeBefore).1 le before) CC.E0
        (.State handler .Sskip k (Arm64MemcpySource.allocation calleeBefore).1 nextLe after) ∧
      CC.Mem.store .Mint64 before base.tags.block 8 (.Vlong 0) = some tagged ∧
      CC.Mem.store .Mint8unsigned tagged base.stack.block (80+(i.val : Int)) (.Vint (byte.setWidth 32)) = some after ∧
      CC.Mem.load .Mint8unsigned after base.stack.block (80+(i.val : Int)) = some (.Vint (byte.setWidth 32)) ∧
      Arm64MemcpyReadCurrent.Flag entry cell flagValue after ∧
      FrameBelow initial.nextblock before after ∧ after.nextblock = before.nextblock := by
  obtain ⟨tagged,after,nextLe,next,run,tagStore,byteStore,read,flagAfter,frame,nextBlock,_kept⟩ := execute_framed le k i prior producerBound callerBound hindex hwidth hvalue hoff cell flagValue flag
  exact ⟨tagged,after,nextLe,next,run,tagStore,byteStore,read,flagAfter,frame,nextBlock⟩

end KProgFormal.ClightRefinement.Arm64MemcpyStoreSuffix
