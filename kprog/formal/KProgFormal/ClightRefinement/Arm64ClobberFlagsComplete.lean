import KProgFormal.ClightRefinement.Arm64ClobberFlagState

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ClobberFlagsComplete

open Arm64Producer
open Arm64ProgramEntryAllocation (world)
open Arm64MemsetClobberEntry (helper)
open Arm64MemsetClobberFlags (declaration stage)

/-- The reached original flag suffix carries all earlier GPR provider words
and the exact masked byte of every flag already written. -/
structure Invariant {initial seed : CC.Mem} {entry : HeaderLocal initial}
    (base : Arm64MemsetHeaderView.View initial seed entry) (abi : TailLocal initial 6)
    (byte : BitVec 8) (calleeBefore : CC.Mem) (rawR0 : BitVec 64) (copiedN : Nat)
    (cell : TailLocal initial 5) (flagValue : BitVec 8) (outerLe : CC.TempEnv) (gprs : Fin 18 → BitVec 64)
    (n : Nat) (values : Fin 4 → BitVec 64) (m : CC.Mem) (le : CC.TempEnv) where
  registers : Arm64ClobberRegisterComplete.Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe 18 gprs m le
  written : ∀ j : Fin 4, j.val < n →
    Arm64EntryMemory.borrowed m.nextblock .Mint8unsigned m (.Vptr entry.block 0)
      (Arm64MemsetClobberFlags.field j) = some (.Vint (flagWord (values j)))

def Inputs {initial seed : CC.Mem} {entry : HeaderLocal initial}
    (base : Arm64MemsetHeaderView.View initial seed entry) (abi : TailLocal initial 6)
    (byte : BitVec 8) (calleeBefore : CC.Mem) (rawR0 : BitVec 64) (copiedN : Nat)
    (cell : TailLocal initial 5) (flagValue : BitVec 8) (outerLe : CC.TempEnv) (gprs : Fin 18 → BitVec 64) : Prop :=
  ∀ (i : Fin 4) values m le, Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe gprs i.val values m le →
    ∃ (value : BitVec 64) (trace : CC.Trace) (supplied : CC.Mem),
      CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv world.genv_genv)
        [.Vint (6#32)] m trace (.Vlong value) supplied ∧
      Arm64ProgramEntryCacheFrame.Frame initial false m supplied

private def supplied {initial seed before after : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {calleeBefore : CC.Mem} {rawR0 : BitVec 64} {copiedN : Nat} {cell : TailLocal initial 5} {flagValue : BitVec 8}
    {outerLe le : CC.TempEnv} {n : Nat} {values : Fin 4 → BitVec 64} {gprs : Fin 18 → BitVec 64}
    (prior : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe gprs n values before le)
    (frame : Arm64ProgramEntryCacheFrame.Frame initial false before after) :
    Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe gprs n values after le where
  registers := {
    ready := prior.registers.ready.supplied frame
    parameter := prior.registers.parameter
    written := by
      intro j bound
      rw [frame.nextblock]
      exact (frame.gpr prior.registers.ready.memory.storage (Arm64MemsetClobberRegisters.declaration j).reg).trans
        (prior.registers.written j bound) }
  written := by
    intro j bound
    rw [frame.nextblock]
    exact (frame.flag prior.registers.ready.memory.storage j).trans (prior.written j bound)

def updated (values : Fin 4 → BitVec 64) (i : Fin 4) (value : BitVec 64) : Fin 4 → BitVec 64 :=
  fun j => if j = i then value else values j

private def written {initial seed before after : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {calleeBefore : CC.Mem} {rawR0 : BitVec 64} {copiedN : Nat} {cell : TailLocal initial 5} {flagValue : BitVec 8}
    {outerLe le : CC.TempEnv} {values : Fin 4 → BitVec 64} {gprs : Fin 18 → BitVec 64} (i : Fin 4)
    (prior : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe gprs i.val values before le) (value : BitVec 64)
    (effect : Arm64MemsetClobberFlags.Effect prior.registers.ready.memory.storage i value after) :
    Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe gprs (i.val + 1) (updated values i value) after
      (Arm64MemsetClobberFlags.temps i le value (prior.registers.ready.memory.storage.flags i).block) where
  registers := {
    ready := Arm64ClobberFlagState.caller_written prior.registers.ready effect
    parameter := (Arm64MemsetClobberFlags.entry_retained i le value _).trans prior.registers.parameter
    written := fun j bound => (Arm64MemsetClobberFlagState.gpr effect
      (Arm64MemsetClobberRegisters.declaration j).reg).trans (prior.registers.written j bound) }
  written := by
    intro j bound
    by_cases same : j = i
    · subst j
      simpa only [updated,ite_true,eq_self] using Arm64MemsetClobberFlagState.selected effect
    · have unequal : j.val ≠ i.val := by intro equal; exact same (Fin.ext equal)
      have priorBound : j.val < i.val := by omega
      simpa only [updated,same,ite_false] using
        (Arm64MemsetClobberFlagState.other_flag effect j same).trans (prior.written j priorBound)

/-- One original flag pair retains the actual external outcome and executes
the original pointer/mask/cast/store path on its supplied heap. -/
theorem step {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {calleeBefore : CC.Mem} {rawR0 : BitVec 64} {copiedN : Nat} {cell : TailLocal initial 5} {flagValue : BitVec 8}
    {outerLe le : CC.TempEnv} {values : Fin 4 → BitVec 64} {gprs : Fin 18 → BitVec 64}
    (inputs : Inputs base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe gprs) (k : CC.Cont) (i : Fin 4)
    (prior : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe gprs i.val values m le) :
    ∃ after nextLe nextValues trace, ∃ _current : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe gprs (i.val + 1) nextValues after nextLe,
      CC.Star (CC.Step2 world) (.State helper (stage i.val) k CC.emptyEnv le m) trace
        (.State helper (stage (i.val + 1)) k CC.emptyEnv nextLe after) ∧
      FrameBelow initial.nextblock m after ∧ after.access = m.access ∧ after.nextblock = m.nextblock := by
  obtain ⟨value,trace,provided,provider,cache⟩ := inputs i values m le prior
  let packet := supplied prior cache
  have enter := Arm64MemsetClobberFlags.ready i le m k
  have external : CC.Star (CC.Step2 world)
      (.Callstate Arm64OriginCache.inputFunction [.Vint (6#32)] (Arm64MemsetClobberFlags.callCont i le k) m)
      trace (.Returnstate (.Vlong value) (Arm64MemsetClobberFlags.callCont i le k) provided) :=
    .step _ _ _ _ _ _ (.external_function _ _ _ _ _ _ _ _ _ _ provider) (.refl _)
      (by simp only [CC.E0,CC.Eapp,List.append_nil])
  obtain ⟨after,effect⟩ := Arm64MemsetClobberFlags.write packet.registers.ready.memory.storage i value
  have stores := Arm64MemsetClobberFlags.returned_store packet.registers.ready.memory.storage i le value
    packet.registers.parameter after k effect.stored
  refine ⟨after,_,_,trace,written i packet value effect,?_,cache.caller.trans effect.caller,
    effect.access.trans cache.access,effect.nextblock.trans cache.nextblock⟩
  have actual := star_trans (star_trans enter.sound external) stores.sound
  rw [Arm64MemsetClobberFlags.next_source i] at actual
  simpa only [stage,i.isLt,dite_eq_left,CC.E0,CC.Eapp,List.nil_append,List.append_nil] using actual

theorem iterations {initial seed before : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {calleeBefore : CC.Mem} {rawR0 : BitVec 64} {copiedN : Nat} {cell : TailLocal initial 5} {flagValue : BitVec 8}
    {outerLe le : CC.TempEnv} {values : Fin 4 → BitVec 64} {gprs : Fin 18 → BitVec 64}
    (inputs : Inputs base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe gprs) (k : CC.Cont)
    (start : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe gprs 0 values before le) (n : Nat) (bound : n ≤ 4) :
    ∃ after nextLe nextValues trace, ∃ _current : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe gprs n nextValues after nextLe,
      CC.Star (CC.Step2 world) (.State helper (stage 0) k CC.emptyEnv le before) trace
        (.State helper (stage n) k CC.emptyEnv nextLe after) ∧
      FrameBelow initial.nextblock before after ∧ after.access = before.access ∧ after.nextblock = before.nextblock := by
  induction n with
  | zero => exact ⟨before,le,values,CC.E0,start,.refl _,FrameBelow.refl _ _,rfl,rfl⟩
  | succ n ih =>
    obtain ⟨middle,middleLe,middleValues,firstTrace,prior,run,frame,access,next⟩ := ih (by omega)
    let i : Fin 4 := ⟨n,by omega⟩
    obtain ⟨after,nextLe,nextValues,secondTrace,current,iteration,iterationFrame,iterationAccess,iterationNext⟩ := step inputs k i prior
    exact ⟨after,nextLe,nextValues,CC.Eapp firstTrace secondTrace,current,star_trans run iteration,
      frame.trans iterationFrame,iterationAccess.trans access,iterationNext.trans next⟩

/-- All four original flag pairs continue the same proved GPR clobber packet. -/
theorem execute {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {calleeBefore : CC.Mem} {rawR0 : BitVec 64} {copiedN : Nat} {cell : TailLocal initial 5} {flagValue : BitVec 8}
    {outerLe le : CC.TempEnv} {gprs : Fin 18 → BitVec 64}
    (current : Arm64ClobberRegisterComplete.Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe 18 gprs m le)
    (inputs : Inputs base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe gprs) (k : CC.Cont) :
    ∃ after nextLe values trace, ∃ _current : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe gprs 4 values after nextLe,
      CC.Star (CC.Step2 world) (.State helper (Arm64ClobberRegisterComplete.stage 18) k CC.emptyEnv le m) trace
        (.State helper (stage 4) k CC.emptyEnv nextLe after) ∧
      FrameBelow initial.nextblock m after ∧ after.access = m.access ∧ after.nextblock = m.nextblock := by
  let start : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe gprs 0 (fun _ => 0) m le := ⟨current,by intros j impossible; omega⟩
  have first : stage 0 = Arm64ClobberRegisterComplete.stage 18 := Arm64MemsetClobberFlags.first_source
  simpa only [first] using iterations inputs k start 4 (by decide)

theorem final_flags {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {calleeBefore : CC.Mem} {rawR0 : BitVec 64} {copiedN : Nat} {cell : TailLocal initial 5} {flagValue : BitVec 8}
    {outerLe le : CC.TempEnv} {gprs : Fin 18 → BitVec 64} {values : Fin 4 → BitVec 64}
    (current : Invariant base abi byte calleeBefore rawR0 copiedN cell flagValue outerLe gprs 4 values m le) :
    Arm64EntryMemory.flags m.nextblock m (.Vptr entry.block 0) =
      some (.Vint (flagWord (values 0)),.Vint (flagWord (values 1)),.Vint (flagWord (values 2)),.Vint (flagWord (values 3))) := by
  have n := current.written 0 (by decide)
  have z := current.written 1 (by decide)
  have c := current.written 2 (by decide)
  have v := current.written 3 (by decide)
  change Arm64EntryMemory.borrowed m.nextblock .Mint8unsigned m (.Vptr entry.block 0) Arm64Program._n = _ at n
  change Arm64EntryMemory.borrowed m.nextblock .Mint8unsigned m (.Vptr entry.block 0) Arm64Program._z = _ at z
  change Arm64EntryMemory.borrowed m.nextblock .Mint8unsigned m (.Vptr entry.block 0) Arm64Program._c = _ at c
  change Arm64EntryMemory.borrowed m.nextblock .Mint8unsigned m (.Vptr entry.block 0) Arm64Program._v = _ at v
  simp only [Arm64EntryMemory.flags,n,z,c,v,Option.bind_some]
  rfl

/-- The same original memcpy caller executes release scans, GPR pairs and all
four masked flag stores with their actual provider trace and selected values. -/
theorem original {initial seed calleeBefore m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {vectors : Fin 64 → BitVec 64}
    {cell : TailLocal initial 5} {flagValue : BitVec 8} {outerLe : CC.TempEnv}
    (current : Arm64MemcpyLoopState.Invariant base abi byte gprs flags vectors calleeBefore 16 m outerLe)
    (flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue m)
    (byteInputs : Arm64ClobberReleaseComplete.Inputs base abi byte calleeBefore (-16#64) 16 cell flagValue outerLe)
    (registerInputs : Arm64ClobberRegisterComplete.Inputs base abi byte calleeBefore (-16#64) 16 cell flagValue outerLe)
    (flagInputs : ∀ selectedGprs, Inputs base abi byte calleeBefore (-16#64) 16 cell flagValue outerLe selectedGprs)
    (k : CC.Cont) :
    ∃ after nextLe selectedGprs values trace,
      ∃ _current : Invariant base abi byte calleeBefore (-16#64) 16 cell flagValue outerLe selectedGprs 4 values after nextLe,
      CC.Star (CC.Step2 world)
        (.State Arm64MemcpySource.handler Arm64MemcpyTransferSource.clobbers k
          (Arm64MemcpySource.allocation calleeBefore).1 outerLe m) trace
        (.State helper (stage 4)
          (Arm64MemsetReleaseTagLoop.restCont (Arm64MemcpyClobberEntry.callCont calleeBefore outerLe k)) CC.emptyEnv nextLe after) ∧
      FrameBelow initial.nextblock m after ∧ after.access = m.access ∧ after.nextblock = m.nextblock := by
  obtain ⟨middle,middleLe,selectedGprs,firstTrace,packet,release,frame,access,next⟩ :=
    Arm64ClobberRegisterComplete.original current flag byteInputs registerInputs k
  obtain ⟨after,nextLe,values,secondTrace,finalCurrent,flagsRun,flagFrame,flagAccess,flagNext⟩ :=
    execute packet (flagInputs selectedGprs)
      (Arm64MemsetReleaseTagLoop.restCont (Arm64MemcpyClobberEntry.callCont calleeBefore outerLe k))
  exact ⟨after,nextLe,selectedGprs,values,CC.Eapp firstTrace secondTrace,finalCurrent,star_trans release flagsRun,
    frame.trans flagFrame,flagAccess.trans access,flagNext.trans next⟩

end KProgFormal.ClightRefinement.Arm64ClobberFlagsComplete
