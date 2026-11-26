import KProgFormal.ClightRefinement.Arm64MemsetClobberVectorState

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemsetClobberVectorsComplete

open Arm64Producer
open Arm64ProgramEntryAllocation (world)
open Arm64MemsetClobberEntry (helper)
open Arm64MemsetClobberVectors (declaration offset afterStmt)

/-- Stage64 is the actual post-assignment skip of the final V31.hi pair. -/
def stage (n : Nat) : CC.Stmt := if h : n < 64 then (declaration ⟨n,h⟩).stage else .Sskip
theorem first_source : stage 0 = Arm64MemsetClobberFlags.stage 4 := Arm64MemsetClobberVectors.first_source
theorem after_source : ∀ i : Fin 64, afterStmt i = stage (i.val + 1) := by
  simp only [Fin.forall_fin_succ,Fin.forall_fin_zero]
  repeat' apply And.intro
  all_goals first | rfl | trivial

structure Invariant {initial seed : CC.Mem} {entry : HeaderLocal initial}
    (base : Arm64MemsetHeaderView.View initial seed entry) (abi : TailLocal initial 6)
    (byte : BitVec 8) (outerLe : CC.TempEnv) (gprs : Fin 18 → BitVec 64) (flags : Fin 4 → BitVec 64)
    (n : Nat) (values : Fin 64 → BitVec 64) (m : CC.Mem) (le : CC.TempEnv) where
  flagsPacket : Arm64MemsetClobberFlagsComplete.Invariant base abi byte outerLe gprs 4 flags m le
  written : ∀ j : Fin 64, j.val < n →
    CC.Mem.load .Mint64 m flagsPacket.registers.ready.storage.vectors.block (offset j) = some (.Vlong (values j))

def Inputs {initial seed : CC.Mem} {entry : HeaderLocal initial}
    (base : Arm64MemsetHeaderView.View initial seed entry) (abi : TailLocal initial 6)
    (byte : BitVec 8) (outerLe : CC.TempEnv) (gprs : Fin 18 → BitVec 64) (flags : Fin 4 → BitVec 64) : Prop :=
  ∀ (i : Fin 64) values m le, Invariant base abi byte outerLe gprs flags i.val values m le →
    ∃ (value : BitVec 64) (trace : CC.Trace) (supplied : CC.Mem),
      CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv world.genv_genv)
        [.Vint (6#32)] m trace (.Vlong value) supplied ∧
      Arm64ProgramEntryCacheFrame.Frame initial false m supplied

private def supplied {initial seed before after : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {outerLe le : CC.TempEnv} {n : Nat} {values : Fin 64 → BitVec 64}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64}
    (prior : Invariant base abi byte outerLe gprs flags n values before le)
    (frame : Arm64ProgramEntryCacheFrame.Frame initial false before after) :
    Invariant base abi byte outerLe gprs flags n values after le where
  flagsPacket := {
    registers := {
      ready := Arm64MemsetClobberRegisterState.supplied prior.flagsPacket.registers.ready frame
      parameter := prior.flagsPacket.registers.parameter
      written := by
        intro j bound
        rw [frame.nextblock]
        exact (frame.gpr prior.flagsPacket.registers.ready.storage (Arm64MemsetClobberRegisters.declaration j).reg).trans
          (prior.flagsPacket.registers.written j bound) }
    written := by
      intro j bound
      rw [frame.nextblock]
      exact (frame.flag prior.flagsPacket.registers.ready.storage j).trans (prior.flagsPacket.written j bound) }
  written := by
    intro j bound
    have different : baseName false ≠ Arm64Entry.___a64_vectors ∧ validName false ≠ Arm64Entry.___a64_vectors := by decide +kernel
    exact (frame.local_load _ _ _ prior.flagsPacket.registers.ready.storage.vectors.binding different.1 different.2
      .Mint64 (offset j)).trans (prior.written j bound)

def updated (values : Fin 64 → BitVec 64) (i : Fin 64) (value : BitVec 64) : Fin 64 → BitVec 64 :=
  fun j => if j = i then value else values j

private def written {initial seed before after : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {outerLe le : CC.TempEnv} {values : Fin 64 → BitVec 64}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} (i : Fin 64)
    (prior : Invariant base abi byte outerLe gprs flags i.val values before le) (value : BitVec 64)
    (effect : Arm64MemsetClobberVectors.Effect prior.flagsPacket.registers.ready.storage i value after) :
    Invariant base abi byte outerLe gprs flags (i.val + 1) (updated values i value) after
      (Arm64MemsetClobberVectors.temps i le value prior.flagsPacket.registers.ready.storage.vectors.block) where
  flagsPacket := {
    registers := {
      ready := Arm64MemsetClobberVectorState.ready effect prior.flagsPacket.registers.ready rfl
      parameter := (Arm64MemsetClobberVectors.entry_retained i le value _).trans prior.flagsPacket.registers.parameter
      written := fun j bound => (Arm64MemsetClobberVectorState.gpr effect
        (Arm64MemsetClobberRegisters.declaration j).reg).trans (prior.flagsPacket.registers.written j bound) }
    written := fun j bound => (Arm64MemsetClobberVectorState.flag effect j).trans (prior.flagsPacket.written j bound) }
  written := by
    intro j bound
    have block : (Arm64MemsetClobberVectorState.ready effect prior.flagsPacket.registers.ready rfl).storage.vectors.block =
        prior.flagsPacket.registers.ready.storage.vectors.block := by
      unfold Arm64MemsetClobberVectorState.ready
      rfl
    change CC.Mem.load .Mint64 after
      (Arm64MemsetClobberVectorState.ready effect prior.flagsPacket.registers.ready rfl).storage.vectors.block (offset j) = _
    rw [block]
    by_cases same : j = i
    · subst j
      simpa only [updated,ite_true,eq_self,offset] using effect.read
    · have unequal : j.val ≠ i.val := by intro equal; exact same (Fin.ext equal)
      have priorBound : j.val < i.val := by omega
      simpa only [updated,same,ite_false] using
        (Arm64MemsetClobberVectorState.other_half effect j same).trans (prior.written j priorBound)

/-- One real vector visit, with the final pair's shorter original source
path and exact skip continuation retained by the actual store theorem. -/
theorem step {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {outerLe le : CC.TempEnv} {values : Fin 64 → BitVec 64}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64}
    (inputs : Inputs base abi byte outerLe gprs flags) (k : CC.Cont) (i : Fin 64)
    (prior : Invariant base abi byte outerLe gprs flags i.val values m le) :
    ∃ after nextLe nextValues trace, ∃ _current : Invariant base abi byte outerLe gprs flags (i.val + 1) nextValues after nextLe,
      CC.Star (CC.Step2 world) (.State helper (stage i.val) k CC.emptyEnv le m) trace
        (.State helper (stage (i.val + 1)) k CC.emptyEnv nextLe after) ∧
      FrameBelow initial.nextblock m after ∧ after.access = m.access ∧ after.nextblock = m.nextblock := by
  obtain ⟨value,trace,provided,provider,cache⟩ := inputs i values m le prior
  let packet := supplied prior cache
  have enter := Arm64MemsetClobberVectors.ready i le m k
  have external : CC.Star (CC.Step2 world)
      (.Callstate Arm64OriginCache.inputFunction [.Vint (6#32)] (Arm64MemsetClobberVectors.callCont i le k) m)
      trace (.Returnstate (.Vlong value) (Arm64MemsetClobberVectors.callCont i le k) provided) :=
    .step _ _ _ _ _ _ (.external_function _ _ _ _ _ _ _ _ _ _ provider) (.refl _)
      (by simp only [CC.E0,CC.Eapp,List.append_nil])
  obtain ⟨after,effect⟩ := Arm64MemsetClobberVectors.write packet.flagsPacket.registers.ready.storage i value
  have stores := Arm64MemsetClobberVectors.returned_store packet.flagsPacket.registers.ready.storage i le value
    packet.flagsPacket.registers.parameter after k effect.stored
  refine ⟨after,_,_,trace,written i packet value effect,?_,cache.caller.trans effect.caller,
    effect.access.trans cache.access,effect.nextblock.trans cache.nextblock⟩
  have actual := star_trans (star_trans enter.sound external) stores.sound
  rw [after_source i] at actual
  simpa only [stage,i.isLt,dite_eq_left,CC.E0,CC.Eapp,List.nil_append,List.append_nil] using actual

theorem iterations {initial seed before : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {outerLe le : CC.TempEnv} {values : Fin 64 → BitVec 64}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64}
    (inputs : Inputs base abi byte outerLe gprs flags) (k : CC.Cont)
    (start : Invariant base abi byte outerLe gprs flags 0 values before le) (n : Nat) (bound : n ≤ 64) :
    ∃ after nextLe nextValues trace, ∃ _current : Invariant base abi byte outerLe gprs flags n nextValues after nextLe,
      CC.Star (CC.Step2 world) (.State helper (stage 0) k CC.emptyEnv le before) trace
        (.State helper (stage n) k CC.emptyEnv nextLe after) ∧
      FrameBelow initial.nextblock before after ∧ after.access = before.access ∧ after.nextblock = before.nextblock := by
  induction n with
  | zero => exact ⟨before,le,values,CC.E0,start,.refl _,FrameBelow.refl _ _,rfl,rfl⟩
  | succ n ih =>
    obtain ⟨middle,middleLe,middleValues,firstTrace,prior,run,frame,access,next⟩ := ih (by omega)
    let i : Fin 64 := ⟨n,by omega⟩
    obtain ⟨after,nextLe,nextValues,secondTrace,current,iteration,iterationFrame,iterationAccess,iterationNext⟩ := step inputs k i prior
    exact ⟨after,nextLe,nextValues,CC.Eapp firstTrace secondTrace,current,star_trans run iteration,
      frame.trans iterationFrame,iterationAccess.trans access,iterationNext.trans next⟩

theorem execute {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {outerLe le : CC.TempEnv} {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64}
    (current : Arm64MemsetClobberFlagsComplete.Invariant base abi byte outerLe gprs 4 flags m le)
    (inputs : Inputs base abi byte outerLe gprs flags) (k : CC.Cont) :
    ∃ after nextLe values trace, ∃ _current : Invariant base abi byte outerLe gprs flags 64 values after nextLe,
      CC.Star (CC.Step2 world) (.State helper (Arm64MemsetClobberFlags.stage 4) k CC.emptyEnv le m) trace
        (.State helper .Sskip k CC.emptyEnv nextLe after) ∧
      FrameBelow initial.nextblock m after ∧ after.access = m.access ∧ after.nextblock = m.nextblock := by
  let start : Invariant base abi byte outerLe gprs flags 0 (fun _ => 0) m le := ⟨current,by intros j impossible; omega⟩
  have last : stage 64 = .Sskip := rfl
  simpa only [first_source,last] using iterations inputs k start 64 (by decide)

private theorem half_indices : ∀ j : Fin 32,
    (declaration ⟨2*j.val,by omega⟩).index = j ∧ (declaration ⟨2*j.val,by omega⟩).high = false ∧
    (declaration ⟨2*j.val+1,by omega⟩).index = j ∧ (declaration ⟨2*j.val+1,by omega⟩).high = true := by decide +kernel

/-- Both halves of all32 vectors read their respective real provider words,
including the last original V31.hi store. -/
theorem final_vectors {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {outerLe le : CC.TempEnv} {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (current : Invariant base abi byte outerLe gprs flags 64 values m le) (j : Fin 32) :
    Arm64EntryMemory.vector m.nextblock m (.Vptr entry.block 0) j =
      some (.Vlong (values ⟨2*j.val,by omega⟩),.Vlong (values ⟨2*j.val+1,by omega⟩)) := by
  have low := current.written ⟨2*j.val,by omega⟩ (by omega)
  have high := current.written ⟨2*j.val+1,by omega⟩ (by omega)
  simp only [offset,(half_indices j).1,(half_indices j).2.1,(half_indices j).2.2.1,(half_indices j).2.2.2] at low high
  rw [Arm64RegisterWrite.storage_vector current.flagsPacket.registers.ready.storage j,low,high]
  rfl

/-- The same actual clobbers call now includes both release scans, all GPR
and flag pairs and every vector half through its genuine final assignment. -/
theorem original {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {outerLe : CC.TempEnv} (current : Arm64MemsetTagTransferComplete.Invariant base abi byte 16 m outerLe)
    (byteInputs : Arm64MemsetReleaseComplete.Inputs base abi byte outerLe)
    (registerInputs : Arm64MemsetClobberRegisterComplete.Inputs base abi byte outerLe)
    (flagInputs : ∀ gprs, Arm64MemsetClobberFlagsComplete.Inputs base abi byte outerLe gprs)
    (vectorInputs : ∀ gprs flags, Inputs base abi byte outerLe gprs flags) (before : CC.Mem) (k : CC.Cont) :
    ∃ after nextLe gprs flags values trace, ∃ _current : Invariant base abi byte outerLe gprs flags 64 values after nextLe,
      CC.Star (CC.Step2 world) (.State Arm64MemsetSource.handler Arm64MemsetTagTransfer.clobbers k
        (Arm64MemsetSource.allocation before).1 outerLe m) trace
        (.State helper .Sskip
          (Arm64MemsetReleaseTagLoop.restCont (Arm64MemsetClobberEntry.callCont before outerLe k)) CC.emptyEnv nextLe after) ∧
      FrameBelow initial.nextblock m after ∧ after.access = m.access ∧ after.nextblock = m.nextblock := by
  obtain ⟨middle,middleLe,gprs,flags,firstTrace,packet,flagRun,frame,access,next⟩ :=
    Arm64MemsetClobberFlagsComplete.original current byteInputs registerInputs flagInputs before k
  obtain ⟨after,nextLe,values,secondTrace,current,vectors,vectorFrame,vectorAccess,vectorNext⟩ :=
    execute packet (vectorInputs gprs flags) (Arm64MemsetReleaseTagLoop.restCont (Arm64MemsetClobberEntry.callCont before outerLe k))
  exact ⟨after,nextLe,gprs,flags,values,CC.Eapp firstTrace secondTrace,current,star_trans flagRun vectors,
    frame.trans vectorFrame,vectorAccess.trans access,vectorNext.trans next⟩

end KProgFormal.ClightRefinement.Arm64MemsetClobberVectorsComplete
