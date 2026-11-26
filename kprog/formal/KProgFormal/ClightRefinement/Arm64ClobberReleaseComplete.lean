import KProgFormal.ClightRefinement.Arm64ClobberReleaseState

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ClobberReleaseComplete

open Arm64Producer
open Arm64ProgramEntryAllocation (world)
open Arm64MemsetClobberEntry (helper loop)

/-- The actual saved caller temporary environment stays fixed
while the actual clobber helper advances its own independent environment. -/
structure Invariant {initial seed : CC.Mem} {entry : HeaderLocal initial}
    (base : Arm64MemsetHeaderView.View initial seed entry) (abi : TailLocal initial 6)
    (byte : BitVec 8) (calleeBefore : CC.Mem) (rawR0 : BitVec 64) (copiedN : Nat)
    (cell : TailLocal initial 5) (flagValue : BitVec 8) (outerLe : CC.TempEnv) (n : Nat) (m : CC.Mem) (le : CC.TempEnv) where
  ready : Arm64ClobberMemoryState.Caller base abi byte calleeBefore rawR0 copiedN cell flagValue m outerLe
  parameter : le.get Arm64Program._entry = some (.Vptr entry.block 0)
  counter : le.get Arm64Program.___a64_release_i = some (.Vint (BitVec.ofNat 32 n))
  old : le.get Arm64Program.___a64_release_old = some (.Vlong (-96#64))
  new : le.get Arm64Program.___a64_release_new = some (.Vlong (-32#64))

/-- Actual available kind6 outcomes on visited selected source states, with
the existing explicit provider/cache ABI. Provider memory may change. -/
def Inputs {initial seed : CC.Mem} {entry : HeaderLocal initial}
    (base : Arm64MemsetHeaderView.View initial seed entry) (abi : TailLocal initial 6)
    (byte : BitVec 8) (calleeBefore : CC.Mem) (rawR0 : BitVec 64) (copiedN : Nat)
    (cell : TailLocal initial 5) (flagValue : BitVec 8) (outerLe : CC.TempEnv) : Prop :=
  ∀ (n : Nat) (m : CC.Mem) (le : CC.TempEnv), Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe n m le → n < 64 →
    ∃ (value : BitVec 64) (trace : CC.Trace) (supplied : CC.Mem),
      CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv world.genv_genv)
        [.Vint (6#32)] m trace (.Vlong value) supplied ∧
      Arm64ProgramEntryCacheFrame.Frame initial false m supplied

private def retime {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {calleeBefore : CC.Mem} {rawR0 : BitVec 64} {copiedN : Nat} {cell : TailLocal initial 5} {flagValue : BitVec 8}
    {outerLe le : CC.TempEnv} {n : Nat} (prior : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe n m le)
    (nextLe : CC.TempEnv) (nextN : Nat)
    (parameter : nextLe.get Arm64Program._entry = le.get Arm64Program._entry)
    (counter : nextLe.get Arm64Program.___a64_release_i = some (.Vint (BitVec.ofNat 32 nextN)))
    (old : nextLe.get Arm64Program.___a64_release_old = le.get Arm64Program.___a64_release_old)
    (new : nextLe.get Arm64Program.___a64_release_new = le.get Arm64Program.___a64_release_new) :
    Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe nextN m nextLe :=
  ⟨prior.ready,parameter.trans prior.parameter,counter,old.trans prior.old,new.trans prior.new⟩

private def prepared {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {calleeBefore : CC.Mem} {rawR0 : BitVec 64} {copiedN : Nat} {cell : TailLocal initial 5} {flagValue : BitVec 8}
    {outerLe le : CC.TempEnv} (i : Fin 160) (prior : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe i.val m le) :
    Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe i.val m (Arm64MemsetReleaseLoop.temps le i) := by
  have obs := Arm64MemsetReleaseLoop.observations le i
  exact retime prior _ _ obs.1 (obs.2.1.trans prior.counter) obs.2.2.1 obs.2.2.2.1

private theorem successor : ∀ i : Fin 160,
    BitVec.ofNat 32 i.val + (1#32) = BitVec.ofNat 32 (i.val + 1) := by decide +kernel

private def advanced {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {calleeBefore : CC.Mem} {rawR0 : BitVec 64} {copiedN : Nat} {cell : TailLocal initial 5} {flagValue : BitVec 8}
    {outerLe le : CC.TempEnv} (i : Fin 160) (prior : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe i.val m le) :
    Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe (i.val + 1) m
      (le.set Arm64Program.___a64_release_i (.Vint (BitVec.ofNat 32 i.val + (1#32)))) := by
  apply retime prior _ (i.val + 1)
  all_goals simp +decide only [CC.PTree.gss,CC.PTree.gso,successor]

private def supplied {initial seed before after : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {calleeBefore : CC.Mem} {rawR0 : BitVec 64} {copiedN : Nat} {cell : TailLocal initial 5} {flagValue : BitVec 8}
    {outerLe le : CC.TempEnv} {n : Nat}
    (prior : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe n before le)
    (frame : Arm64ProgramEntryCacheFrame.Frame initial false before after) :
    Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe n after le :=
  {prior with ready := prior.ready.supplied frame}

private def written {initial seed before after : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {calleeBefore : CC.Mem} {rawR0 : BitVec 64} {copiedN : Nat} {cell : TailLocal initial 5} {flagValue : BitVec 8}
    {outerLe le : CC.TempEnv} {n : Nat} (prior : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe n before le)
    (i : Fin 64) (value : BitVec 64)
    (stored : CC.Mem.store .Mint8unsigned before prior.ready.memory.view.stack.block (i.val : Int)
      (.Vint ((value.setWidth 8).setWidth 32)) = some after) :
    Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe n after (Arm64MemsetReleaseStore.temps le prior.ready.memory.view.stack.block value) := by
  have obs := Arm64MemsetReleaseStore.inputs le prior.ready.memory.view.stack.block value
  exact {
    ready := Arm64ClobberReleaseState.caller_released prior.ready i value stored
    parameter := obs.1.trans prior.parameter
    counter := obs.2.1.trans prior.counter
    old := obs.2.2.1.trans prior.old
    new := obs.2.2.2.trans prior.new }

theorem step {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {calleeBefore : CC.Mem} {rawR0 : BitVec 64} {copiedN : Nat} {cell : TailLocal initial 5} {flagValue : BitVec 8}
    {outerLe le : CC.TempEnv} (inputs : Inputs base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe) (k : CC.Cont) (i : Fin 160)
    (prior : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe i.val m le) :
    ∃ after nextLe trace, ∃ _current : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe (i.val + 1) after nextLe,
      CC.Star (CC.Step2 world) (.State helper loop k CC.emptyEnv le m) trace
        (.State helper loop k CC.emptyEnv nextLe after) ∧
      FrameBelow initial.nextblock m after ∧ after.access = m.access ∧ after.nextblock = m.nextblock := by
  let packet := prepared i prior
  by_cases active : Arm64MemsetReleaseLoop.active i = true
  · have low : i.val < 64 := (Arm64MemsetReleaseLoop.active_positions i).mp active
    let j : Fin 64 := ⟨i.val,low⟩
    have setup := Arm64MemsetReleaseLoop.setup CC.emptyEnv le m k entry.block i prior.parameter prior.counter
      prior.old prior.new prior.ready.memory.view.capacity prior.ready.memory.view.bias
    rw [active] at setup
    obtain ⟨value,trace,middle,provider,providerFrame⟩ := inputs i.val m _ packet low
    let provided := supplied packet providerFrame
    obtain ⟨after,run,stored,_read,frame,access,next⟩ := Arm64MemsetReleaseStore.execute provided.ready.memory.view provided.ready.memory.resources _
      (Arm64MemsetReleaseLoop.continuation k) j value trace provided.parameter provided.counter provider
    let changed := written provided j value stored
    have back := Arm64MemsetReleaseLoop.advance CC.emptyEnv _ after k (Arm64MemsetReleaseLoop.index i) changed.counter
    refine ⟨after,_,trace,advanced i changed,?_,providerFrame.caller.trans frame,
      access.trans providerFrame.access,next.trans providerFrame.nextblock⟩
    simpa only [Arm64MemsetReleaseLoop.index,CC.E0,CC.Eapp,List.nil_append,List.append_nil] using
      star_trans (star_trans setup.sound run) back.sound
  · have inactive : Arm64MemsetReleaseLoop.active i = false := Bool.eq_false_iff.mpr active
    have run := Arm64MemsetReleaseLoop.inactive CC.emptyEnv le m k entry.block i prior.parameter prior.counter
      prior.old prior.new prior.ready.memory.view.capacity prior.ready.memory.view.bias inactive
    exact ⟨m,_,CC.E0,advanced i packet,run.sound,FrameBelow.refl _ _,rfl,rfl⟩

/-- Sequentially execute every actual byte index, with ordered real external
traces and all protected source/copied data bytes and resources retained on each reached heap. -/
theorem iterations {initial seed before : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {calleeBefore : CC.Mem} {rawR0 : BitVec 64} {copiedN : Nat} {cell : TailLocal initial 5} {flagValue : BitVec 8}
    {outerLe le : CC.TempEnv} (inputs : Inputs base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe) (k : CC.Cont)
    (start : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe 0 before le) (n : Nat) (bound : n ≤ 160) :
    ∃ after nextLe trace, ∃ _current : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe n after nextLe,
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

section Current
variable {initial seed before : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {calleeBefore : CC.Mem} {rawR0 : BitVec 64} {copiedN : Nat} {cell : TailLocal initial 5} {flagValue : BitVec 8}
    {outerLe : CC.TempEnv}

private def start (current : Arm64ClobberMemoryState.Caller base abi byte calleeBefore rawR0 copiedN cell flagValue before outerLe) :
    Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe 0 before
      (Arm64MemsetClobberEntry.temps entry.block current.memory.storage.sp.block) := by
  have obs := Arm64MemsetClobberEntry.inputs entry.block current.memory.storage.sp.block
  exact ⟨current,obs.1,obs.2.2.2,obs.2.1,obs.2.2.1⟩

def tagCont (k : CC.Cont) : CC.Cont := Arm64MemsetReleaseComplete.tagCont k
private theorem continuation_source (k : CC.Cont) : Arm64MemsetClobberEntry.continuation k =
    .Kseq Arm64MemsetClobberEntry.tags (tagCont k) := rfl

/-- The shared helper's real160-index scan retains all64 selected actual
provider/store effects, ordered external traces, final guard and next tag
statement, with the actual R0 and same caller/flag packet throughout. -/
theorem execute
    (current : Arm64ClobberMemoryState.Caller base abi byte calleeBefore rawR0 copiedN cell flagValue before outerLe)
    (inputs : Inputs base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe) (k : CC.Cont) :
    ∃ after nextLe trace,
      ∃ _current : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe 160 after nextLe,
      CC.Star (CC.Step2 world)
        (.State helper loop (Arm64MemsetClobberEntry.continuation k) CC.emptyEnv
          (Arm64MemsetClobberEntry.temps entry.block current.memory.storage.sp.block) before) trace
        (.State helper Arm64MemsetClobberEntry.tags (tagCont k) CC.emptyEnv nextLe after) ∧
      FrameBelow initial.nextblock before after ∧ after.access = before.access ∧ after.nextblock = before.nextblock := by
  obtain ⟨after,nextLe,trace,packet,run,frame,access,next⟩ := iterations inputs
    (Arm64MemsetClobberEntry.continuation k) (start current) 160 (by decide)
  let finalLe := nextLe.set Arm64Program._t'237 (.Vint 160)
  let finalPacket : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe 160 after finalLe :=
    retime packet finalLe 160
      (by simp +decide only [finalLe,CC.PTree.gso])
      (by simpa +decide only [finalLe,CC.PTree.gso] using packet.counter)
      (by simp +decide only [finalLe,CC.PTree.gso])
      (by simp +decide only [finalLe,CC.PTree.gso])
  have leave := Arm64MemsetReleaseLoop.finish CC.emptyEnv nextLe after (Arm64MemsetClobberEntry.continuation k)
    entry.block packet.parameter packet.counter packet.ready.memory.view.capacity
  have nextStatement : InternalRun world 1
      (.State helper .Sskip (Arm64MemsetClobberEntry.continuation k) CC.emptyEnv finalLe after)
      (.State helper Arm64MemsetClobberEntry.tags (tagCont k) CC.emptyEnv finalLe after) := by
    rw [continuation_source]
    exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  refine ⟨after,finalLe,trace,finalPacket,?_,frame,access,next⟩
  simpa only [CC.E0,CC.Eapp,List.nil_append,List.append_nil] using
    star_trans (star_trans run leave.sound) nextStatement.sound

end Current
end KProgFormal.ClightRefinement.Arm64ClobberReleaseComplete
