import KProgFormal.ClightRefinement.Arm64ClobberMemoryState

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ClobberCoreState

open Arm64Producer (HeaderLocal TailLocal)
open Arm64ProgramEntryAllocation (world)

/-- The original helper retains the actual saved caller environment, its
live local ranges and initialized flag. Each caller owns its temp metadata. -/
structure Saved {initial seed : CC.Mem} {entry : HeaderLocal initial}
    (env : CC.Env) (base : Arm64MemsetHeaderView.View initial seed entry)
    (abi : TailLocal initial 6) (byte : BitVec 8) (rawR0 : BitVec 64) (n : Nat)
    (cell : TailLocal initial 5) (flagValue : BitVec 8) (m : CC.Mem) where
  memory : Arm64ClobberMemoryState.Packet base abi byte rawR0 n m
  callee : ∀ id value, env.get id = some value →
    CC.Mem.rangePerm m value.1 0 (CC.sizeof world.genv_cenv value.2) .Cur .Freeable = true
  flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue m

/-- Project the real memcpy caller without imposing its metadata on another
caller's helper execution. The actual allocation env and flag remain. -/
def of_memcpy {initial seed calleeBefore m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {rawR0 : BitVec 64} {n : Nat} {cell : TailLocal initial 5} {flagValue : BitVec 8} {le : CC.TempEnv}
    (prior : Arm64ClobberMemoryState.Caller base abi byte calleeBefore rawR0 n cell flagValue m le) :
    Saved (Arm64MemcpySource.allocation calleeBefore).1 base abi byte rawR0 n cell flagValue m :=
  ⟨prior.memory,prior.callee,prior.flag⟩

/-- The same completed memset heap supplies its actual R0=-32, source bytes,
original eight-local env and flag. Its real access map gives live rights. -/
def of_memset {initial seed calleeBefore m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {cell : TailLocal initial 5} {flagValue : BitVec 8} {le : CC.TempEnv}
    (prior : Arm64MemsetWriteLoop.Invariant base abi byte 16 m le)
    (flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue m)
    (access : m.access = (Arm64MemsetSource.allocation calleeBefore).2.access) :
    Saved (Arm64MemsetSource.allocation calleeBefore).1 base abi byte (-32#64) 0 cell flagValue m where
  memory := Arm64ClobberMemoryState.of_memset prior
  callee := fun id value binding =>
    (CC.Mem.rangePerm_congr (m1 := m) (m2 := (Arm64MemsetSource.allocation calleeBefore).2)
      (fun offset => by simp only [CC.Mem.perm,access])).trans
      (((allocated_local_storage (Arm64MemsetSource.allocated calleeBefore)).1 id value binding).2.2)
  flag := flag

/-- One actual provider/cache outcome retains the same saved env's rights
and flag while the original shared packet follows its genuine supplied heap. -/
def Saved.supplied {initial seed before after : CC.Mem} {entry : HeaderLocal initial}
    {env : CC.Env} {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {rawR0 : BitVec 64} {n : Nat} {cell : TailLocal initial 5} {flagValue : BitVec 8}
    (prior : Saved env base abi byte rawR0 n cell flagValue before)
    (frame : Arm64ProgramEntryCacheFrame.Frame initial false before after) :
    Saved env base abi byte rawR0 n cell flagValue after where
  memory := prior.memory.supplied frame
  callee := fun id value binding => (CC.Mem.rangePerm_congr (m1 := after) (m2 := before)
    (fun offset => by simp only [CC.Mem.perm,frame.access])).trans (prior.callee id value binding)
  flag := prior.flag.tail_frame (Arm64ProducerTailFrame.of_cache entry frame)

end KProgFormal.ClightRefinement.Arm64ClobberCoreState
