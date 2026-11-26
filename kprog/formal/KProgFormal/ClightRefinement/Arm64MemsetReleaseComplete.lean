import KProgFormal.ClightRefinement.Arm64MemsetReleaseStore

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemsetReleaseComplete

open Arm64Producer
open Arm64ProgramEntryAllocation (world)
open Arm64MemsetClobberEntry (helper loop)

/-- The original memset caller's saved temporary environment stays fixed
while the actual clobber helper advances its own independent environment. -/
structure Invariant {initial seed : CC.Mem} {entry : HeaderLocal initial}
    (base : Arm64MemsetHeaderView.View initial seed entry) (abi : TailLocal initial 6)
    (byte : BitVec 8) (outerLe : CC.TempEnv) (n : Nat) (m : CC.Mem) (le : CC.TempEnv) where
  ready : Arm64MemsetWriteLoop.Invariant base abi byte 16 m outerLe
  parameter : le.get Arm64Program._entry = some (.Vptr entry.block 0)
  counter : le.get Arm64Program.___a64_release_i = some (.Vint (BitVec.ofNat 32 n))
  old : le.get Arm64Program.___a64_release_old = some (.Vlong (-96#64))
  new : le.get Arm64Program.___a64_release_new = some (.Vlong (-32#64))

/-- Actual available kind6 outcomes on visited selected source states, with
the existing explicit provider/cache ABI. Provider memory may change. -/
def Inputs {initial seed : CC.Mem} {entry : HeaderLocal initial}
    (base : Arm64MemsetHeaderView.View initial seed entry) (abi : TailLocal initial 6)
    (byte : BitVec 8) (outerLe : CC.TempEnv) : Prop :=
  ∀ (n : Nat) (m : CC.Mem) (le : CC.TempEnv), Invariant base abi byte outerLe n m le → n < 64 →
    ∃ (value : BitVec 64) (trace : CC.Trace) (supplied : CC.Mem),
      CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv world.genv_genv)
        [.Vint (6#32)] m trace (.Vlong value) supplied ∧
      Arm64ProgramEntryCacheFrame.Frame initial false m supplied

private def retime {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {outerLe le : CC.TempEnv} {n : Nat} (prior : Invariant base abi byte outerLe n m le)
    (nextLe : CC.TempEnv) (nextN : Nat)
    (parameter : nextLe.get Arm64Program._entry = le.get Arm64Program._entry)
    (counter : nextLe.get Arm64Program.___a64_release_i = some (.Vint (BitVec.ofNat 32 nextN)))
    (old : nextLe.get Arm64Program.___a64_release_old = le.get Arm64Program.___a64_release_old)
    (new : nextLe.get Arm64Program.___a64_release_new = le.get Arm64Program.___a64_release_new) :
    Invariant base abi byte outerLe nextN m nextLe :=
  ⟨prior.ready,parameter.trans prior.parameter,counter,old.trans prior.old,new.trans prior.new⟩

private def prepared {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {outerLe le : CC.TempEnv} (i : Fin 160) (prior : Invariant base abi byte outerLe i.val m le) :
    Invariant base abi byte outerLe i.val m (Arm64MemsetReleaseLoop.temps le i) := by
  have obs := Arm64MemsetReleaseLoop.observations le i
  exact retime prior _ _ obs.1 (obs.2.1.trans prior.counter) obs.2.2.1 obs.2.2.2.1

private theorem successor : ∀ i : Fin 160,
    BitVec.ofNat 32 i.val + (1#32) = BitVec.ofNat 32 (i.val + 1) := by decide +kernel

private def advanced {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {outerLe le : CC.TempEnv} (i : Fin 160) (prior : Invariant base abi byte outerLe i.val m le) :
    Invariant base abi byte outerLe (i.val + 1) m
      (le.set Arm64Program.___a64_release_i (.Vint (BitVec.ofNat 32 i.val + (1#32)))) := by
  apply retime prior _ (i.val + 1)
  all_goals simp +decide only [CC.PTree.gss,CC.PTree.gso,successor]

private def supplied {initial seed before after : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {outerLe le : CC.TempEnv} {n : Nat} (prior : Invariant base abi byte outerLe n before le)
    (frame : Arm64ProgramEntryCacheFrame.Frame initial false before after) :
    Invariant base abi byte outerLe n after le := by
  have tail := Arm64ProducerTailFrame.of_cache entry frame
  let view : Arm64MemsetHeaderView.View initial after entry := {
    stack := prior.ready.view.stack
    tags := prior.ready.view.tags
    stackPointer := (tail.header CC.Mptr 608).trans prior.ready.view.stackPointer
    tagPointer := (tail.header CC.Mptr 648).trans prior.ready.view.tagPointer
    capacity := (tail.header .Mint32 656).trans prior.ready.view.capacity
    bias := (tail.header .Mint64 672).trans prior.ready.view.bias }
  refine {prior with ready := {prior.ready with
    view := view
    resources := Arm64MemsetIterationResources.resources prior.ready.resources tail.header
      (fun block _ => congrArg (CC.PMap.get block) frame.access)
    storage := frame.storage prior.ready.storage
    gpr := ?_
    abiHeader := (tail.header CC.Mptr 704).trans prior.ready.abiHeader
    abiKind := (tail.tail 6 abi .Mint8unsigned 0).trans prior.ready.abiKind
    tagBytes := ?_
    written := ?_ }}
  · rw [frame.nextblock]
    exact (frame.gpr prior.ready.storage (0 : Fin 31)).trans prior.ready.gpr
  · intro j
    have kept := tail.tail 2 ⟨prior.ready.view.tags.block,prior.ready.view.tags.binding⟩ .Mint8unsigned (j.val : Int)
    change CC.Mem.load .Mint8unsigned after prior.ready.view.tags.block (j.val : Int) =
      CC.Mem.load .Mint8unsigned before prior.ready.view.tags.block (j.val : Int) at kept
    rw [prior.ready.tagsSame] at kept
    exact kept.trans (prior.ready.tagBytes j)
  · intro j bound
    have kept := tail.tail 0 prior.ready.view.stack .Mint8unsigned ((Arm64MemsetStoreExecution.index j).val : Int)
    rw [prior.ready.stackSame] at kept
    exact kept.trans (prior.ready.written j bound)

private def written {initial seed before after : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {outerLe le : CC.TempEnv} {n : Nat} (prior : Invariant base abi byte outerLe n before le)
    (i : Fin 64) (value : BitVec 64)
    (stored : CC.Mem.store .Mint8unsigned before prior.ready.view.stack.block (i.val : Int)
      (.Vint ((value.setWidth 8).setWidth 32)) = some after) :
    Invariant base abi byte outerLe n after (Arm64MemsetReleaseStore.temps le prior.ready.view.stack.block value) := by
  have obs := Arm64MemsetReleaseStore.inputs le prior.ready.view.stack.block value
  have separate := (allocated_local_storage (CC.doAllocVariables_sound _ _ _ _ _ _
    (Prod.eta (allocation initial)).symm)).2
  have entryOther : entry.block ≠ prior.ready.view.stack.block :=
    separate _ _ _ _ entry.binding prior.ready.view.stack.binding (by decide +kernel)
  have abiOther : abi.block ≠ prior.ready.view.stack.block :=
    separate _ _ _ _ abi.binding prior.ready.view.stack.binding (by decide +kernel)
  have dataTags := Arm64MemsetReleaseStore.data_tags prior.ready.view i value stored
  have gpr := Arm64MemsetReleaseStore.gpr_after prior.ready.view i value stored prior.ready.storage (0 : Fin 31)
  simp only [Fin.val_zero] at gpr
  refine {
    ready := {prior.ready with
      view := Arm64MemsetReleaseStore.view_after prior.ready.view i value stored
      resources := Arm64MemsetReleaseStore.resources_after prior.ready.view i value stored prior.ready.resources
      storage := Arm64MemsetReleaseStore.storage_after prior.ready.view i value stored prior.ready.storage
      gpr := gpr.trans prior.ready.gpr
      abiHeader := (CC.Mem.load_store_other stored CC.Mptr entry.block 704 (.inl entryOther)).trans prior.ready.abiHeader
      abiKind := (CC.Mem.load_store_other stored .Mint8unsigned abi.block 0 (.inl abiOther)).trans prior.ready.abiKind
      tagBytes := ?_
      written := ?_ }
    parameter := obs.1.trans prior.parameter
    counter := obs.2.1.trans prior.counter
    old := obs.2.2.1.trans prior.old
    new := obs.2.2.2.trans prior.new }
  · intro j
    have kept := dataTags.2 j
    rw [prior.ready.tagsSame] at kept
    exact kept.trans (prior.ready.tagBytes j)
  · intro j bound
    have kept := dataTags.1 j
    rw [prior.ready.stackSame] at kept
    exact kept.trans (prior.ready.written j bound)

/-- One actual byte-release iteration includes its real provider and volatile
store when selected; every other iteration follows the original skip path. -/
theorem step {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {outerLe le : CC.TempEnv} (inputs : Inputs base abi byte outerLe) (k : CC.Cont) (i : Fin 160)
    (prior : Invariant base abi byte outerLe i.val m le) :
    ∃ after nextLe trace, ∃ _current : Invariant base abi byte outerLe (i.val + 1) after nextLe,
      CC.Star (CC.Step2 world) (.State helper loop k CC.emptyEnv le m) trace
        (.State helper loop k CC.emptyEnv nextLe after) ∧
      FrameBelow initial.nextblock m after ∧ after.access = m.access ∧ after.nextblock = m.nextblock := by
  let packet := prepared i prior
  by_cases active : Arm64MemsetReleaseLoop.active i = true
  · have low : i.val < 64 := (Arm64MemsetReleaseLoop.active_positions i).mp active
    let j : Fin 64 := ⟨i.val,low⟩
    have setup := Arm64MemsetReleaseLoop.setup CC.emptyEnv le m k entry.block i prior.parameter prior.counter
      prior.old prior.new prior.ready.view.capacity prior.ready.view.bias
    rw [active] at setup
    obtain ⟨value,trace,middle,provider,providerFrame⟩ := inputs i.val m _ packet low
    let provided := supplied packet providerFrame
    obtain ⟨after,run,stored,_read,frame,access,next⟩ := Arm64MemsetReleaseStore.execute provided.ready.view provided.ready.resources _
      (Arm64MemsetReleaseLoop.continuation k) j value trace provided.parameter provided.counter provider
    let changed := written provided j value stored
    have back := Arm64MemsetReleaseLoop.advance CC.emptyEnv _ after k (Arm64MemsetReleaseLoop.index i) changed.counter
    refine ⟨after,_,trace,advanced i changed,?_,providerFrame.caller.trans frame,
      access.trans providerFrame.access,next.trans providerFrame.nextblock⟩
    simpa only [Arm64MemsetReleaseLoop.index,CC.E0,CC.Eapp,List.nil_append,List.append_nil] using
      star_trans (star_trans setup.sound run) back.sound
  · have inactive : Arm64MemsetReleaseLoop.active i = false := Bool.eq_false_iff.mpr active
    have run := Arm64MemsetReleaseLoop.inactive CC.emptyEnv le m k entry.block i prior.parameter prior.counter
      prior.old prior.new prior.ready.view.capacity prior.ready.view.bias inactive
    exact ⟨m,_,CC.E0,advanced i packet,run.sound,FrameBelow.refl _ _,rfl,rfl⟩

/-- Sequentially execute every actual byte index, with ordered real external
traces and all16 earlier data bytes/resources retained on each reached heap. -/
theorem iterations {initial seed before : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {outerLe le : CC.TempEnv} (inputs : Inputs base abi byte outerLe) (k : CC.Cont)
    (start : Invariant base abi byte outerLe 0 before le) (n : Nat) (bound : n ≤ 160) :
    ∃ after nextLe trace, ∃ _current : Invariant base abi byte outerLe n after nextLe,
      CC.Star (CC.Step2 world) (.State helper loop k CC.emptyEnv le before) trace
        (.State helper loop k CC.emptyEnv nextLe after) ∧
      FrameBelow initial.nextblock before after ∧ after.access = before.access ∧ after.nextblock = before.nextblock := by
  induction n with
  | zero => exact ⟨before,le,CC.E0,start,.refl _,FrameBelow.refl _ _,rfl,rfl⟩
  | succ n ih =>
    obtain ⟨middle,middleLe,firstTrace,prior,run,frame,access,next⟩ := ih (by omega)
    let i : Fin 160 := ⟨n,by omega⟩
    obtain ⟨after,nextLe,secondTrace,current,iteration,iterationFrame,iterationAccess,iterationNext⟩ := step inputs k i prior
    exact ⟨after,nextLe,CC.Eapp firstTrace secondTrace,current,star_trans run iteration,
      frame.trans iterationFrame,iterationAccess.trans access,iterationNext.trans next⟩

private def start {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {outerLe : CC.TempEnv} (current : Arm64MemsetTagTransferComplete.Invariant base abi byte 16 m outerLe) :
    Invariant base abi byte outerLe 0 m (Arm64MemsetClobberEntry.temps entry.block current.ready.storage.sp.block) := by
  have obs := Arm64MemsetClobberEntry.inputs entry.block current.ready.storage.sp.block
  exact ⟨current.ready,obs.1,obs.2.2.2,obs.2.1,obs.2.2.1⟩

private def tagTail : CC.Cont → CC.Cont := by
  run_tac do
    let result ← Lean.Meta.withLocalDeclD `savedContinuation (Lean.mkConst ``CC.Cont) fun k => do
      let term ← Lean.Meta.mkAppM ``Arm64MemsetClobberEntry.continuation #[k]
      let actual ← Lean.Meta.withTransparency .all (Lean.Meta.whnf term)
      unless actual.isAppOfArity ``CC.Cont.Kseq 2 do throwError "actual byte-release continuation changed"
      Lean.Meta.mkLambdaFVars #[k] actual.getAppArgs[1]!
    Lean.Elab.Tactic.closeMainGoal `actual_release_tag_cont result
def tagCont (k : CC.Cont) : CC.Cont := tagTail k
private theorem continuation_source (k : CC.Cont) : Arm64MemsetClobberEntry.continuation k =
    .Kseq Arm64MemsetClobberEntry.tags (tagCont k) := rfl

/-- The genuine memset clobbers call executes the complete160-index byte
scan, all selected actual provider/stores, final guard and next tag statement. -/
theorem execute {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {outerLe : CC.TempEnv} (current : Arm64MemsetTagTransferComplete.Invariant base abi byte 16 m outerLe)
    (inputs : Inputs base abi byte outerLe) (before : CC.Mem) (k : CC.Cont) :
    ∃ after nextLe trace, ∃ _current : Invariant base abi byte outerLe 160 after nextLe,
      CC.Star (CC.Step2 world) (.State Arm64MemsetSource.handler Arm64MemsetTagTransfer.clobbers k
        (Arm64MemsetSource.allocation before).1 outerLe m) trace
        (.State helper Arm64MemsetClobberEntry.tags
          (tagCont (Arm64MemsetClobberEntry.callCont before outerLe k)) CC.emptyEnv nextLe after) ∧
      (∀ j : Fin 16, CC.Mem.load .Mint8unsigned after base.stack.block
        ((Arm64MemsetStoreExecution.index j).val : Int) = some (.Vint (byte.setWidth 32))) ∧
      FrameBelow initial.nextblock m after ∧ after.access = m.access ∧ after.nextblock = m.nextblock := by
  have entryRun := Arm64MemsetClobberEntry.execute current before k
  let called := Arm64MemsetClobberEntry.callCont before outerLe k
  obtain ⟨after,nextLe,trace,packet,run,frame,access,next⟩ := iterations inputs (Arm64MemsetClobberEntry.continuation called)
    (start current) 160 (by decide)
  let finalLe := nextLe.set Arm64Program._t'237 (.Vint 160)
  let finalPacket : Invariant base abi byte outerLe 160 after finalLe := retime packet finalLe 160
    (by simp +decide only [finalLe,CC.PTree.gso])
    (by simpa +decide only [finalLe,CC.PTree.gso] using packet.counter)
    (by simp +decide only [finalLe,CC.PTree.gso])
    (by simp +decide only [finalLe,CC.PTree.gso])
  have leave := Arm64MemsetReleaseLoop.finish CC.emptyEnv nextLe after (Arm64MemsetClobberEntry.continuation called)
    entry.block packet.parameter packet.counter packet.ready.view.capacity
  have nextStatement : InternalRun world 1
      (.State helper .Sskip (Arm64MemsetClobberEntry.continuation called) CC.emptyEnv finalLe after)
      (.State helper Arm64MemsetClobberEntry.tags (tagCont called) CC.emptyEnv finalLe after) := by
    rw [continuation_source]
    exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  refine ⟨after,finalLe,trace,finalPacket,?_,fun j => finalPacket.ready.written j j.isLt,frame,access,next⟩
  simpa only [CC.E0,CC.Eapp,List.nil_append,List.append_nil] using
    star_trans (star_trans (star_trans entryRun.sound run) leave.sound) nextStatement.sound

end KProgFormal.ClightRefinement.Arm64MemsetReleaseComplete
