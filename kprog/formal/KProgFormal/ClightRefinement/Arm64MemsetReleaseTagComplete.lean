import KProgFormal.ClightRefinement.Arm64MemsetReleaseTagStore

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemsetReleaseTagComplete

open Arm64Producer
open Arm64ProgramEntryAllocation (world)
open Arm64MemsetClobberEntry (helper)
open Arm64MemsetReleaseTagLoop (loop)

structure Invariant {initial seed : CC.Mem} {entry : HeaderLocal initial}
    (base : Arm64MemsetHeaderView.View initial seed entry) (abi : TailLocal initial 6)
    (byte : BitVec 8) (outerLe : CC.TempEnv) (n : Nat) (m : CC.Mem) (le : CC.TempEnv) where
  released : Arm64MemsetReleaseComplete.Invariant base abi byte outerLe 160 m le
  counter : le.get Arm64Program.___a64_release_w = some (.Vint (BitVec.ofNat 32 n))

private def retime {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {outerLe le : CC.TempEnv} {n : Nat} (prior : Invariant base abi byte outerLe n m le)
    (nextLe : CC.TempEnv) (nextN : Nat)
    (parameter : nextLe.get Arm64Program._entry = le.get Arm64Program._entry)
    (counter : nextLe.get Arm64Program.___a64_release_w = some (.Vint (BitVec.ofNat 32 nextN)))
    (old : nextLe.get Arm64Program.___a64_release_old = le.get Arm64Program.___a64_release_old)
    (new : nextLe.get Arm64Program.___a64_release_new = le.get Arm64Program.___a64_release_new)
    (bytes : nextLe.get Arm64Program.___a64_release_i = le.get Arm64Program.___a64_release_i) :
    Invariant base abi byte outerLe nextN m nextLe where
  released := {prior.released with
    parameter := parameter.trans prior.released.parameter
    counter := bytes.trans prior.released.counter
    old := old.trans prior.released.old
    new := new.trans prior.released.new }
  counter := counter

private def prepared {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {outerLe le : CC.TempEnv} (i : Fin 20) (prior : Invariant base abi byte outerLe i.val m le) :
    Invariant base abi byte outerLe i.val m (Arm64MemsetReleaseTagLoop.temps le i) := by
  have obs := Arm64MemsetReleaseTagLoop.observations le i
  exact retime prior _ _ obs.1 (obs.2.1.trans prior.counter) obs.2.2.1 obs.2.2.2.1 obs.2.2.2.2

private theorem successor : ∀ i : Fin 20,
    BitVec.ofNat 32 i.val + (1#32) = BitVec.ofNat 32 (i.val + 1) := by decide +kernel

private def advanced {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {outerLe le : CC.TempEnv} (i : Fin 20) (prior : Invariant base abi byte outerLe i.val m le) :
    Invariant base abi byte outerLe (i.val + 1) m
      (le.set Arm64Program.___a64_release_w (.Vint (BitVec.ofNat 32 i.val + (1#32)))) := by
  apply retime prior _ (i.val + 1)
  all_goals simp +decide only [CC.PTree.gss,CC.PTree.gso,successor]

private def written {initial seed before after : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {outerLe le : CC.TempEnv} {n : Nat} (prior : Invariant base abi byte outerLe n before le) (i : Fin 8)
    (stored : CC.Mem.store .Mint64 before prior.released.ready.view.tags.block 0 (.Vlong 0) = some after) :
    Invariant base abi byte outerLe n after
      (Arm64MemsetReleaseTagStore.temps le i prior.released.ready.view.tags.block) := by
  have obs := Arm64MemsetReleaseTagStore.inputs le i prior.released.ready.view.tags.block
  have separate := (allocated_local_storage (CC.doAllocVariables_sound _ _ _ _ _ _
    (Prod.eta (allocation initial)).symm)).2
  have entryOther : entry.block ≠ prior.released.ready.view.tags.block :=
    separate _ _ _ _ entry.binding prior.released.ready.view.tags.binding (by decide +kernel)
  have abiOther : abi.block ≠ prior.released.ready.view.tags.block :=
    separate _ _ _ _ abi.binding prior.released.ready.view.tags.binding (by decide +kernel)
  have stackOther : prior.released.ready.view.stack.block ≠ prior.released.ready.view.tags.block :=
    separate _ _ _ _ prior.released.ready.view.stack.binding prior.released.ready.view.tags.binding (by decide +kernel)
  have outside (chunk : CC.Chunk) (block : CC.Block) (offset : Int) (other : block ≠ prior.released.ready.view.tags.block) :=
    CC.Mem.load_store_other stored chunk block offset (.inl other)
  have gpr := Arm64MemsetReleaseTagStore.gpr_after prior.released.ready.view stored prior.released.ready.storage (0 : Fin 31)
  simp only [Fin.val_zero] at gpr
  have tagReads : ∀ j : Fin 24, CC.Mem.load .Mint8unsigned before prior.released.ready.view.tags.block (j.val : Int) = some (.Vint 0) := by
    simpa only [prior.released.ready.tagsSame] using prior.released.ready.tagBytes
  have tags := Arm64MemsetReleaseTagStore.tag_bytes stored tagReads
  refine {
    released := {
      ready := {prior.released.ready with
        view := Arm64MemsetReleaseTagStore.view_after prior.released.ready.view stored
        resources := Arm64MemsetReleaseTagStore.resources_after prior.released.ready.view stored prior.released.ready.resources
        storage := Arm64MemsetReleaseTagStore.storage_after prior.released.ready.view stored prior.released.ready.storage
        gpr := gpr.trans prior.released.ready.gpr
        abiHeader := (outside CC.Mptr entry.block 704 entryOther).trans prior.released.ready.abiHeader
        abiKind := (outside .Mint8unsigned abi.block 0 abiOther).trans prior.released.ready.abiKind
        tagBytes := by simpa only [prior.released.ready.tagsSame] using tags
        written := ?_ }
      parameter := obs.1.trans prior.released.parameter
      counter := obs.2.2.2.2.trans prior.released.counter
      old := obs.2.2.1.trans prior.released.old
      new := obs.2.2.2.1.trans prior.released.new }
    counter := obs.2.1.trans prior.counter }
  intro j bound
  have kept := outside .Mint8unsigned prior.released.ready.view.stack.block
    ((Arm64MemsetStoreExecution.index j).val : Int) stackOther
  rw [prior.released.ready.stackSame] at kept
  exact kept.trans (prior.released.ready.written j bound)

/-- An actual selected tag iteration performs its real offset0 volatile
read/modify/write; other indices execute the real short-circuit skip. -/
theorem step {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {outerLe le : CC.TempEnv} (k : CC.Cont) (i : Fin 20) (prior : Invariant base abi byte outerLe i.val m le) :
    ∃ after nextLe, ∃ _current : Invariant base abi byte outerLe (i.val + 1) after nextLe,
      CC.Star (CC.Step2 world) (.State helper loop k CC.emptyEnv le m) CC.E0
        (.State helper loop k CC.emptyEnv nextLe after) ∧
      FrameBelow initial.nextblock m after ∧ after.access = m.access ∧ after.nextblock = m.nextblock ∧
      (∀ (chunk : CC.Chunk) (block : CC.Block) (offset : Int), block ≠ base.tags.block →
        CC.Mem.load chunk after block offset = CC.Mem.load chunk m block offset) := by
  let packet := prepared i prior
  by_cases active : Arm64MemsetReleaseTagLoop.active i = true
  · have low : i.val < 8 := (Arm64MemsetReleaseTagLoop.active_positions i).mp active
    let j : Fin 8 := ⟨i.val,low⟩
    have setup := Arm64MemsetReleaseTagLoop.setup CC.emptyEnv le m k entry.block i prior.released.parameter prior.counter
      prior.released.old prior.released.new prior.released.ready.view.capacity prior.released.ready.view.bias
    simp only [active,ite_true] at setup
    have tagReads : ∀ q : Fin 24, CC.Mem.load .Mint8unsigned m packet.released.ready.view.tags.block (q.val : Int) = some (.Vint 0) := by
      simpa only [packet.released.ready.tagsSame] using packet.released.ready.tagBytes
    obtain ⟨after,run,stored,frame,access,next,outside,_tags⟩ :=
      Arm64MemsetReleaseTagStore.execute packet.released.ready.view packet.released.ready.resources CC.emptyEnv _
        (Arm64MemsetReleaseTagLoop.continuation k) j packet.released.parameter packet.counter tagReads
    let changed := written packet j stored
    have back := Arm64MemsetReleaseTagLoop.advance CC.emptyEnv _ after k (Arm64MemsetReleaseTagLoop.index i) changed.counter
    refine ⟨after,_,advanced i changed,?_,frame,access,next,?_⟩
    · simpa only [Arm64MemsetReleaseTagLoop.index,CC.E0,CC.Eapp,List.nil_append] using star_trans (star_trans setup.sound run) back.sound
    · intro chunk block offset notTag
      exact outside chunk block offset (by simpa only [packet.released.ready.tagsSame] using notTag)
  · have inactive : Arm64MemsetReleaseTagLoop.active i = false := Bool.eq_false_iff.mpr active
    have run := Arm64MemsetReleaseTagLoop.inactive CC.emptyEnv le m k entry.block i prior.released.parameter prior.counter
      prior.released.old prior.released.new prior.released.ready.view.capacity prior.released.ready.view.bias inactive
    exact ⟨m,_,advanced i packet,run.sound,FrameBelow.refl _ _,rfl,rfl,by intros; rfl⟩

/-- Compose all20 actual word indices and their two real control paths while
retaining the same original caller packet on every reached heap. -/
theorem iterations {initial seed before : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {outerLe le : CC.TempEnv} (k : CC.Cont) (start : Invariant base abi byte outerLe 0 before le)
    (n : Nat) (bound : n ≤ 20) :
    ∃ after nextLe, ∃ _current : Invariant base abi byte outerLe n after nextLe,
      CC.Star (CC.Step2 world) (.State helper loop k CC.emptyEnv le before) CC.E0
        (.State helper loop k CC.emptyEnv nextLe after) ∧
      FrameBelow initial.nextblock before after ∧ after.access = before.access ∧ after.nextblock = before.nextblock ∧
      (∀ (chunk : CC.Chunk) (block : CC.Block) (offset : Int), block ≠ base.tags.block →
        CC.Mem.load chunk after block offset = CC.Mem.load chunk before block offset) := by
  induction n with
  | zero => exact ⟨before,le,start,.refl _,FrameBelow.refl _ _,rfl,rfl,by intros; rfl⟩
  | succ n ih =>
    obtain ⟨middle,middleLe,prior,run,frame,access,next,outside⟩ := ih (by omega)
    let i : Fin 20 := ⟨n,by omega⟩
    obtain ⟨after,nextLe,current,iteration,iterationFrame,iterationAccess,iterationNext,iterationOutside⟩ := step k i prior
    refine ⟨after,nextLe,current,?_,frame.trans iterationFrame,iterationAccess.trans access,iterationNext.trans next,?_⟩
    · simpa only [CC.E0,CC.Eapp,List.nil_append] using star_trans run iteration
    · intro chunk block offset notTag
      exact (iterationOutside chunk block offset notTag).trans (outside chunk block offset notTag)

private def start {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {outerLe le : CC.TempEnv} (current : Arm64MemsetReleaseComplete.Invariant base abi byte outerLe 160 m le) :
    Invariant base abi byte outerLe 0 m (le.set Arm64Program.___a64_release_w (.Vint 0)) where
  released := {current with
    parameter := by simpa +decide only [CC.PTree.gso] using current.parameter
    counter := by simpa +decide only [CC.PTree.gso] using current.counter
    old := by simpa +decide only [CC.PTree.gso] using current.old
    new := by simpa +decide only [CC.PTree.gso] using current.new }
  counter := CC.PTree.gss ..

/-- Execute the original tag initialization, complete20-word scan, eight
actual stores, final false guard and release-wrapper exit into real rest. -/
theorem execute {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {outerLe le : CC.TempEnv} (current : Arm64MemsetReleaseComplete.Invariant base abi byte outerLe 160 m le)
    (called : CC.Cont) :
    ∃ after nextLe, ∃ _current : Invariant base abi byte outerLe 20 after nextLe,
      CC.Star (CC.Step2 world) (.State helper Arm64MemsetClobberEntry.tags
        (Arm64MemsetReleaseComplete.tagCont called) CC.emptyEnv le m) CC.E0
        (.State helper Arm64MemsetClobberEntry.rest (Arm64MemsetReleaseTagLoop.restCont called) CC.emptyEnv nextLe after) ∧
      (∀ j : Fin 16, CC.Mem.load .Mint8unsigned after base.stack.block
        ((Arm64MemsetStoreExecution.index j).val : Int) = some (.Vint (byte.setWidth 32))) ∧
      FrameBelow initial.nextblock m after ∧ after.access = m.access ∧ after.nextblock = m.nextblock ∧
      (∀ (chunk : CC.Chunk) (block : CC.Block) (offset : Int), block ≠ base.tags.block →
        CC.Mem.load chunk after block offset = CC.Mem.load chunk m block offset) := by
  have enter := Arm64MemsetReleaseTagLoop.enter CC.emptyEnv le m (Arm64MemsetReleaseComplete.tagCont called)
  obtain ⟨after,nextLe,packet,run,frame,access,next,outside⟩ :=
    iterations (Arm64MemsetReleaseComplete.tagCont called) (start current) 20 (by decide)
  let finalLe := nextLe.set Arm64Program._t'234 (.Vint 160)
  let finalPacket : Invariant base abi byte outerLe 20 after finalLe := retime packet finalLe 20
    (by simp +decide only [finalLe,CC.PTree.gso])
    (by simpa +decide only [finalLe,CC.PTree.gso] using packet.counter)
    (by simp +decide only [finalLe,CC.PTree.gso])
    (by simp +decide only [finalLe,CC.PTree.gso])
    (by simp +decide only [finalLe,CC.PTree.gso])
  have leave := Arm64MemsetReleaseTagLoop.finish CC.emptyEnv nextLe after (Arm64MemsetReleaseComplete.tagCont called)
    entry.block packet.released.parameter packet.counter packet.released.ready.view.capacity
  have rest := Arm64MemsetReleaseTagLoop.outer_exit CC.emptyEnv finalLe after called
  refine ⟨after,finalLe,finalPacket,?_,fun j => finalPacket.released.ready.written j j.isLt,frame,access,next,outside⟩
  simpa only [CC.E0,CC.Eapp,List.nil_append] using star_trans (star_trans (star_trans enter.sound run) leave.sound) rest.sound

/-- From the same actual memset clobbers call, compose its complete byte and
tag release scans, keeping all original providers/traces and actual stores. -/
theorem original {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {outerLe : CC.TempEnv} (current : Arm64MemsetTagTransferComplete.Invariant base abi byte 16 m outerLe)
    (inputs : Arm64MemsetReleaseComplete.Inputs base abi byte outerLe) (before : CC.Mem) (k : CC.Cont) :
    ∃ after nextLe trace, ∃ _current : Invariant base abi byte outerLe 20 after nextLe,
      CC.Star (CC.Step2 world) (.State Arm64MemsetSource.handler Arm64MemsetTagTransfer.clobbers k
        (Arm64MemsetSource.allocation before).1 outerLe m) trace
        (.State helper Arm64MemsetClobberEntry.rest
          (Arm64MemsetReleaseTagLoop.restCont (Arm64MemsetClobberEntry.callCont before outerLe k)) CC.emptyEnv nextLe after) ∧
      (∀ j : Fin 16, CC.Mem.load .Mint8unsigned after base.stack.block
        ((Arm64MemsetStoreExecution.index j).val : Int) = some (.Vint (byte.setWidth 32))) ∧
      FrameBelow initial.nextblock m after ∧ after.access = m.access ∧ after.nextblock = m.nextblock := by
  obtain ⟨middle,middleLe,trace,packet,bytes,_byteReads,frame,access,next⟩ := Arm64MemsetReleaseComplete.execute current inputs before k
  obtain ⟨after,nextLe,current,tags,reads,tagFrame,tagAccess,tagNext,_outside⟩ :=
    execute packet (Arm64MemsetClobberEntry.callCont before outerLe k)
  refine ⟨after,nextLe,trace,current,?_,reads,frame.trans tagFrame,tagAccess.trans access,tagNext.trans next⟩
  simpa only [CC.E0,CC.Eapp,List.append_nil] using star_trans bytes tags

end KProgFormal.ClightRefinement.Arm64MemsetReleaseTagComplete
