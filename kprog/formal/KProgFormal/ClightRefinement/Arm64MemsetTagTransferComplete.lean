import KProgFormal.ClightRefinement.Arm64MemsetTagTransferStore

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemsetTagTransferComplete

open Arm64Producer
open Arm64ProgramEntryAllocation (world)
open Arm64MemsetSource (handler)

structure Invariant {initial seed : CC.Mem} {entry : HeaderLocal initial}
    (base : Arm64MemsetHeaderView.View initial seed entry) (abi : TailLocal initial 6)
    (byte : BitVec 8) (n : Nat) (m : CC.Mem) (le : CC.TempEnv) where
  ready : Arm64MemsetWriteLoop.Invariant base abi byte 16 m le
  counter : le.get Arm64Program.___a64_mt_i = some (.Vlong (BitVec.ofNat 64 n))
  destination : le.get Arm64Program.___a64_mt_dst = some (.Vlong 64)
  length : le.get Arm64Program.___a64_mt_len = some (.Vlong 16)

private def retime {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {n : Nat} {le : CC.TempEnv} (prior : Invariant base abi byte n m le) (nextLe : CC.TempEnv) (nextN : Nat)
    (entryRead : nextLe.get Arm64Program._entry = le.get Arm64Program._entry)
    (libCounter : nextLe.get Arm64Program.___a64_lib_i = le.get Arm64Program.___a64_lib_i)
    (libLength : nextLe.get Arm64Program.___a64_lib_len = le.get Arm64Program.___a64_lib_len)
    (libByte : nextLe.get Arm64Program.___a64_lib_byte = le.get Arm64Program.___a64_lib_byte)
    (counter : nextLe.get Arm64Program.___a64_mt_i = some (.Vlong (BitVec.ofNat 64 nextN)))
    (destination : nextLe.get Arm64Program.___a64_mt_dst = le.get Arm64Program.___a64_mt_dst)
    (length : nextLe.get Arm64Program.___a64_mt_len = le.get Arm64Program.___a64_mt_len) :
    Invariant base abi byte nextN m nextLe where
  ready := {prior.ready with
    entryRead := entryRead.trans prior.ready.entryRead
    counter := libCounter.trans prior.ready.counter
    length := libLength.trans prior.ready.length
    value := libByte.trans prior.ready.value}
  counter := counter
  destination := destination.trans prior.destination
  length := length.trans prior.length

private def aligned {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {le : CC.TempEnv} (i : Fin 16) (prior : Invariant base abi byte i.val m le) :
    Invariant base abi byte i.val m (Arm64MemsetTagTransferLoop.temps le i) := by
  have obs := Arm64MemsetTagTransferLoop.observations le i
  exact retime prior _ i.val obs.2.2.2.1 obs.2.2.2.2.1 obs.2.2.2.2.2.1 obs.2.2.2.2.2.2.1
    (obs.1.trans prior.counter) obs.2.1 obs.2.2.1

private theorem successor : ∀ i : Fin 16,
    BitVec.ofNat 64 i.val + (1#64) = BitVec.ofNat 64 (i.val + 1) := by decide +kernel

private def advanced {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {le : CC.TempEnv} (i : Fin 16) (prior : Invariant base abi byte i.val m le) :
    Invariant base abi byte (i.val + 1) m
      (le.set Arm64Program.___a64_mt_i (.Vlong (BitVec.ofNat 64 i.val + (1#64)))) := by
  apply retime prior _ (i.val + 1)
  all_goals simp +decide only [CC.PTree.gss,CC.PTree.gso,successor]

private def from_store {initial seed before after : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {n : Nat} {le : CC.TempEnv} (prior : Invariant base abi byte n before le) (high : Bool)
    (stored : CC.Mem.store .Mint64 before prior.ready.view.tags.block 8 (.Vlong 0) = some after) :
    Invariant base abi byte n after
      (Arm64MemsetTagTransferStore.temps le high prior.ready.view.tags.block) := by
  have obs := Arm64MemsetTagTransferStore.inputs le high prior.ready.view.tags.block
  have separate := (allocated_local_storage (CC.doAllocVariables_sound _ _ _ _ _ _
    (Prod.eta (allocation initial)).symm)).2
  have entryOther : entry.block ≠ prior.ready.view.tags.block :=
    separate _ _ _ _ entry.binding prior.ready.view.tags.binding (by decide +kernel)
  have abiOther : abi.block ≠ prior.ready.view.tags.block :=
    separate _ _ _ _ abi.binding prior.ready.view.tags.binding (by decide +kernel)
  have stackOther : prior.ready.view.stack.block ≠ prior.ready.view.tags.block :=
    separate _ _ _ _ prior.ready.view.stack.binding prior.ready.view.tags.binding (by decide +kernel)
  have outside (chunk : CC.Chunk) (block : CC.Block) (offset : Int) (other : block ≠ prior.ready.view.tags.block) :=
    CC.Mem.load_store_other stored chunk block offset (.inl other)
  have gpr := Arm64MemsetTagTransferStore.gpr_after prior.ready.view stored prior.ready.storage (0 : Fin 31)
  simp only [Fin.val_zero] at gpr
  have tagReads : ∀ j : Fin 24, CC.Mem.load .Mint8unsigned before prior.ready.view.tags.block (j.val : Int) = some (.Vint 0) := by
    simpa only [prior.ready.tagsSame] using prior.ready.tagBytes
  have tags := Arm64MemsetTagByteTransport.word_store stored tagReads
  refine {
    ready := {
      view := Arm64MemsetTagTransferStore.view_after prior.ready.view stored
      stackSame := prior.ready.stackSame
      tagsSame := prior.ready.tagsSame
      resources := Arm64MemsetTagTransferStore.resources_after prior.ready.view stored prior.ready.resources
      storage := Arm64MemsetTagTransferStore.storage_after prior.ready.view stored prior.ready.storage
      spAtBase := prior.ready.spAtBase
      entryRead := obs.1.trans prior.ready.entryRead
      counter := obs.2.1.trans prior.ready.counter
      length := obs.2.2.1.trans prior.ready.length
      value := obs.2.2.2.1.trans prior.ready.value
      gpr := gpr.trans prior.ready.gpr
      abiHeader := (outside CC.Mptr entry.block 704 entryOther).trans prior.ready.abiHeader
      abiKind := (outside .Mint8unsigned abi.block 0 abiOther).trans prior.ready.abiKind
      tagBytes := by simpa only [prior.ready.tagsSame] using tags
      written := ?_ }
    counter := obs.2.2.2.2.1.trans prior.counter
    destination := obs.2.2.2.2.2.1.trans prior.destination
    length := obs.2.2.2.2.2.2.trans prior.length }
  intro j bound
  have kept := outside .Mint8unsigned prior.ready.view.stack.block
    ((Arm64MemsetStoreExecution.index j).val : Int) stackOther
  rw [prior.ready.stackSame] at kept
  exact kept.trans (prior.ready.written j bound)

private theorem selected_position (i : Fin 16) (active : Arm64MemsetTagTransferLoop.active i = true) :
    Arm64MemsetTagTransferStore.position (i.val == 8) = Arm64MemsetTagTransferLoop.position i := by
  obtain low | high := (Arm64MemsetTagTransferLoop.active_positions i).mp active
  · simp [Arm64MemsetTagTransferStore.position,Arm64MemsetTagTransferLoop.position,low]
  · simp [Arm64MemsetTagTransferStore.position,Arm64MemsetTagTransferLoop.position,high]

/-- One real transfer iteration: actual s106 store at0/8 or genuine inactive
path, preserving the SAME completed byte/data/resources packet and increment. -/
theorem step {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    (e : CC.Env) (k : CC.Cont) (i : Fin 16) {le : CC.TempEnv}
    (prior : Invariant base abi byte i.val m le) :
    ∃ after nextLe, ∃ _current : Invariant base abi byte (i.val + 1) after nextLe,
      CC.Star (CC.Step2 world)
        (.State handler Arm64MemsetTagTransfer.loop (Arm64MemsetTagTransfer.continuation k) e le m) CC.E0
        (.State handler Arm64MemsetTagTransfer.loop (Arm64MemsetTagTransfer.continuation k) e nextLe after) ∧
      FrameBelow initial.nextblock m after ∧ after.access = m.access ∧ after.nextblock = m.nextblock ∧
      (∀ (chunk : CC.Chunk) (block : CC.Block) (offset : Int), block ≠ base.tags.block →
        CC.Mem.load chunk after block offset = CC.Mem.load chunk m block offset) := by
  let prepared := aligned i prior
  by_cases active : Arm64MemsetTagTransferLoop.active i = true
  · have setup := Arm64MemsetTagTransferLoop.setup e le m (Arm64MemsetTagTransfer.continuation k) i
      prior.counter prior.length prior.destination
    rw [active] at setup
    have obs := Arm64MemsetTagTransferLoop.observations le i
    have position : (Arm64MemsetTagTransferLoop.temps le i).get Arm64Program.___a64_mt_at =
        some (.Vlong (Arm64MemsetTagTransferStore.position (i.val == 8))) := by
      simpa only [selected_position i active] using obs.2.2.2.2.2.2.2
    have tags : ∀ j : Fin 24, CC.Mem.load .Mint8unsigned m prepared.ready.view.tags.block (j.val : Int) = some (.Vint 0) := by
      simpa only [prepared.ready.tagsSame] using prepared.ready.tagBytes
    obtain ⟨after,body,stored,_read,frame,access,next,outside,_tags,_bytes⟩ :=
      Arm64MemsetTagTransferStore.execute prepared.ready.view prepared.ready.resources e _
        (Arm64MemsetTagTransferLoop.continuation (Arm64MemsetTagTransfer.continuation k)) (i.val == 8)
        prepared.ready.entryRead position tags
    let written := from_store prepared (i.val == 8) stored
    have back := Arm64MemsetTagTransferLoop.advance e _ after (Arm64MemsetTagTransfer.continuation k)
      (BitVec.ofNat 64 i.val) written.counter
    refine ⟨after,_,advanced i written,?_,frame,access,next,?_⟩
    · simpa only [CC.E0,CC.Eapp,List.nil_append] using star_trans (star_trans setup.sound body) back.sound
    · intro chunk block offset notTag
      exact outside chunk block offset (by simpa only [prepared.ready.tagsSame] using notTag)
  · have inactive : Arm64MemsetTagTransferLoop.active i = false := Bool.eq_false_iff.mpr active
    have run := Arm64MemsetTagTransferLoop.inactive e le m (Arm64MemsetTagTransfer.continuation k) i
      prior.counter prior.length prior.destination inactive
    exact ⟨m,_,advanced i prepared,run.sound,FrameBelow.refl _ _,rfl,rfl,by intros; rfl⟩

/-- Actual sequential transfer iterations preserve all16 source byte values,
while the two selected original iterations perform their real tag stores. -/
theorem iterations {initial seed before : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    (e : CC.Env) (k : CC.Cont) {le : CC.TempEnv} (start : Invariant base abi byte 0 before le)
    (n : Nat) (bound : n ≤ 16) :
    ∃ after nextLe, ∃ _current : Invariant base abi byte n after nextLe,
      CC.Star (CC.Step2 world)
        (.State handler Arm64MemsetTagTransfer.loop (Arm64MemsetTagTransfer.continuation k) e le before) CC.E0
        (.State handler Arm64MemsetTagTransfer.loop (Arm64MemsetTagTransfer.continuation k) e nextLe after) ∧
      FrameBelow initial.nextblock before after ∧ after.access = before.access ∧ after.nextblock = before.nextblock ∧
      (∀ (chunk : CC.Chunk) (block : CC.Block) (offset : Int), block ≠ base.tags.block →
        CC.Mem.load chunk after block offset = CC.Mem.load chunk before block offset) := by
  induction n with
  | zero => exact ⟨before,le,start,.refl _,FrameBelow.refl _ _,rfl,rfl,by intros; rfl⟩
  | succ n ih =>
    obtain ⟨middle,middleLe,prior,run,frame,access,next,outside⟩ := ih (by omega)
    let i : Fin 16 := ⟨n,by omega⟩
    obtain ⟨after,nextLe,current,iteration,iterationFrame,iterationAccess,iterationNext,iterationOutside⟩ := step e k i prior
    refine ⟨after,nextLe,current,?_,frame.trans iterationFrame,iterationAccess.trans access,iterationNext.trans next,?_⟩
    · simpa only [CC.E0,CC.Eapp,List.nil_append] using star_trans run iteration
    · intro chunk block offset notTag
      exact (iterationOutside chunk block offset notTag).trans (outside chunk block offset notTag)

private def start {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {le : CC.TempEnv} (ready : Arm64MemsetWriteLoop.Invariant base abi byte 16 m le) :
    Invariant base abi byte 0 m (Arm64MemsetTagTransfer.temps le) := by
  have obs := Arm64MemsetTagTransfer.observations le
  exact {
    ready := {ready with
      entryRead := obs.1.trans ready.entryRead
      counter := obs.2.1.trans ready.counter
      length := obs.2.2.1.trans ready.length
      value := obs.2.2.2.1.trans ready.value}
    counter := obs.2.2.2.2.2.2
    destination := obs.2.2.2.2.1
    length := obs.2.2.2.2.2.1 }

/-- From the SAME actual completed byte loop, execute both original reader
calls, all16 transfer iterations, both real tag stores and the real outer exit. -/
theorem execute {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {le : CC.TempEnv} (ready : Arm64MemsetWriteLoop.Invariant base abi byte 16 m le)
    (addresses : Arm64Registers.PointerOrigins) (before : CC.Mem) (k : CC.Cont) :
    ∃ after nextLe, ∃ current : Invariant base abi byte 16 after nextLe,
      CC.Star (CC.Step2 world)
        (.State handler .Sskip (.Kseq Arm64MemsetLoop.effects k) (Arm64MemsetSource.allocation before).1 le m) CC.E0
        (.State handler Arm64MemsetTagTransfer.clobbers k (Arm64MemsetSource.allocation before).1 nextLe after) ∧
      (∀ j : Fin 16, CC.Mem.load .Mint8unsigned after base.stack.block
        ((Arm64MemsetStoreExecution.index j).val : Int) = some (.Vint (byte.setWidth 32))) ∧
      FrameBelow initial.nextblock m after ∧ after.access = m.access ∧ after.nextblock = m.nextblock ∧
      (∀ (chunk : CC.Chunk) (block : CC.Block) (offset : Int), block ≠ base.tags.block →
        CC.Mem.load chunk after block offset = CC.Mem.load chunk m block offset) := by
  have prefixRun := Arm64MemsetTagTransfer.after_bytes ready addresses before k
  obtain ⟨after,nextLe,current,run,frame,access,next,outside⟩ :=
    iterations (Arm64MemsetSource.allocation before).1 k (start ready) 16 (by decide)
  have leave := Arm64MemsetTagTransferLoop.finish (Arm64MemsetSource.allocation before).1 nextLe after k current.counter current.length
  refine ⟨after,nextLe,current,?_,fun j => current.ready.written j j.isLt,frame,access,next,outside⟩
  simpa only [CC.E0,CC.Eapp,List.nil_append] using star_trans (star_trans prefixRun.sound run) leave.sound

/-- The same original full memset call executes all16 data writes and all16
transfer iterations, including both genuine tag stores, to its real clobbers. -/
theorem original {initial before markWritten markAfter constantWritten constantAfter : CC.Mem}
    {entry : HeaderLocal initial} {oldStorage : Arm64ProducerRegisterStorage.Storage initial before entry}
    {addresses : Arm64Registers.PointerOrigins} {origins : Reference.Provenance.AArch64.Origins}
    {prior next : Reference.AArch64.State} {priorK nextK : CC.Cont} (mark : BitVec 32)
    (first : Arm64MovImmediate.OrdinaryCall.Result oldStorage 1 (mark.setWidth 64)
      addresses origins prior priorK markWritten markAfter)
    (bound : (allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (second : Arm64MovImmediate.OrdinaryCall.Result (first.storage bound) 2 (16#64)
      addresses origins next nextK constantWritten constantAfter)
    (view : Arm64MemsetHeaderView.View initial (Arm64MemsetSource.allocation constantAfter).2 entry)
    (abi : TailLocal initial 6)
    (resources : Arm64ProgramEntryResources.Resources initial (Arm64MemsetSource.allocation constantAfter).2 entry)
    (storage : Arm64ProducerRegisterStorage.Storage initial (Arm64MemsetSource.allocation constantAfter).2 entry)
    (spAtBase : storage.spValue = (-32#64))
    (gpr : Arm64EntryMemory.gpr (Arm64MemsetSource.allocation constantAfter).2.nextblock
      (Arm64MemsetSource.allocation constantAfter).2 (.Vptr entry.block 0) 0 =
      some (.Vlong (-32#64),.Vint ((4#8).setWidth 32)))
    (abiHeader : CC.Mem.load CC.Mptr (Arm64MemsetSource.allocation constantAfter).2 entry.block 704 = some (.Vptr abi.block 0))
    (abiKind : CC.Mem.load .Mint8unsigned (Arm64MemsetSource.allocation constantAfter).2 abi.block 0 = some (.Vint 2))
    (tagBytes : ∀ j : Fin 24, CC.Mem.load .Mint8unsigned (Arm64MemsetSource.allocation constantAfter).2
      view.tags.block (j.val : Int) = some (.Vint 0)) (k : CC.Cont) :
    ∃ after nextLe, ∃ _current : Invariant view abi (Arm64MemsetLossSetup.byte mark) 16 after nextLe,
      CC.Star (CC.Step2 world) (.Callstate (.Internal handler) [.Vptr entry.block 0] k constantAfter) CC.E0
        (.State handler Arm64MemsetTagTransfer.clobbers (Arm64MemsetSource.continuation k)
          (Arm64MemsetSource.allocation constantAfter).1 nextLe after) ∧
      (∀ j : Fin 16, CC.Mem.load .Mint8unsigned after view.stack.block
        ((Arm64MemsetStoreExecution.index j).val : Int) =
          some (.Vint ((Arm64MemsetLossSetup.byte mark).setWidth 32))) ∧
      FrameBelow initial.nextblock (Arm64MemsetSource.allocation constantAfter).2 after ∧
      after.access = (Arm64MemsetSource.allocation constantAfter).2.access ∧
      after.nextblock = (Arm64MemsetSource.allocation constantAfter).2.nextblock ∧
      (∀ (chunk : CC.Chunk) (block : CC.Block) (offset : Int), block ≠ view.tags.block → block ≠ view.stack.block →
        CC.Mem.load chunk after block offset =
          CC.Mem.load chunk (Arm64MemsetSource.allocation constantAfter).2 block offset) := by
  obtain ⟨middle,middleLe,ready,bytes,_byteReads,frame,access,next,outside⟩ :=
    Arm64MemsetWriteLoop.original mark first bound second view abi resources storage spAtBase gpr abiHeader abiKind tagBytes k
  obtain ⟨after,nextLe,current,transfer,reads,transferFrame,transferAccess,transferNext,transferOutside⟩ :=
    execute ready addresses constantAfter (Arm64MemsetSource.continuation k)
  refine ⟨after,nextLe,current,?_,reads,frame.trans transferFrame,transferAccess.trans access,
    transferNext.trans next,?_⟩
  · simpa only [CC.E0,CC.Eapp,List.nil_append] using star_trans bytes transfer
  · intro chunk block offset notTag notStack
    exact (transferOutside chunk block offset notTag).trans (outside chunk block offset notTag notStack)

end KProgFormal.ClightRefinement.Arm64MemsetTagTransferComplete
