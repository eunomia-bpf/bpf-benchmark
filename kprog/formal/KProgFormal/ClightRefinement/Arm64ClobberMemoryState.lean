import KProgFormal.ClightRefinement.Arm64MemcpyClobberEntry

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ClobberMemoryState

open Arm64Producer Arm64ProducerRegisterStorage
open Arm64ProgramEntryAllocation (world)

/-- Current helper memory observations are shared across callers. The
actual R0 and copied-byte progress are parameters; selected clobber outputs
for other registers, flags and vectors belong to their advancing stages. -/
structure Packet {initial seed : CC.Mem} {entry : HeaderLocal initial}
    (base : Arm64MemsetHeaderView.View initial seed entry) (abi : TailLocal initial 6) (byte : BitVec 8)
    (rawR0 : BitVec 64) (n : Nat) (m : CC.Mem) where
  view : Arm64MemsetHeaderView.View initial m entry
  stackSame : view.stack.block = base.stack.block
  tagsSame : view.tags.block = base.tags.block
  resources : Arm64ProgramEntryResources.Resources initial m entry
  storage : Storage initial m entry
  spAtBase : storage.spValue = (-32#64)
  r0 : Arm64EntryMemory.gpr m.nextblock m (.Vptr entry.block 0) 0 =
    some (.Vlong rawR0,.Vint ((4#8).setWidth 32))
  abiHeader : CC.Mem.load CC.Mptr m entry.block 704 = some (.Vptr abi.block 0)
  abiKind : CC.Mem.load .Mint8unsigned m abi.block 0 = some (.Vint 2)
  tagBytes : ∀ j : Fin 24, CC.Mem.load .Mint8unsigned m base.tags.block (j.val : Int) = some (.Vint 0)
  source : ∀ j : Fin 16, CC.Mem.load .Mint8unsigned m base.stack.block (64+(j.val : Int)) =
    some (.Vint (byte.setWidth 32))
  copied : ∀ j : Fin 16, j.val < n → CC.Mem.load .Mint8unsigned m base.stack.block (80+(j.val : Int)) =
    some (.Vint (byte.setWidth 32))

/-- The advancing helper retains the actual saved memcpy caller, its live
local rights and the same initialized source flag. -/
structure Caller {initial seed : CC.Mem} {entry : HeaderLocal initial}
    (base : Arm64MemsetHeaderView.View initial seed entry) (abi : TailLocal initial 6) (byte : BitVec 8)
    (calleeBefore : CC.Mem) (rawR0 : BitVec 64) (n : Nat) (cell : TailLocal initial 5) (flagValue : BitVec 8)
    (m : CC.Mem) (outerLe : CC.TempEnv) where
  memory : Packet base abi byte rawR0 n m
  callee : ∀ id value, (Arm64MemcpySource.allocation calleeBefore).1.get id = some value →
    CC.Mem.rangePerm m value.1 0 (CC.sizeof world.genv_cenv value.2) .Cur .Freeable = true
  entryRead : outerLe.get Arm64Program._entry = some (.Vptr entry.block 0)
  length : outerLe.get Arm64Program.___a64_lib_len = some (.Vlong 16)
  counter : outerLe.get Arm64Program.___a64_lib_i = some (.Vlong (BitVec.ofNat 64 n))
  sourceTag : outerLe.get Arm64Program.___a64_lib_src_tag = some (.Vint ((4#8).setWidth 32))
  flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue m

private theorem source_offset (j : Fin 16) :
    ((Arm64MemsetStoreExecution.index j).val : Int) = 64+(j.val : Int) := by
  change ((64+j.val : Nat) : Int) = _
  omega

/-- The completed memset observation specializes the same packet at its
actual R0=-32 and zero memcpy destination progress. -/
def of_memset {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {le : CC.TempEnv} (prior : Arm64MemsetWriteLoop.Invariant base abi byte 16 m le) :
    Packet base abi byte (-32#64) 0 m where
  view := prior.view
  stackSame := prior.stackSame
  tagsSame := prior.tagsSame
  resources := prior.resources
  storage := prior.storage
  spAtBase := prior.spAtBase
  r0 := prior.gpr
  abiHeader := prior.abiHeader
  abiKind := prior.abiKind
  tagBytes := prior.tagBytes
  source := fun j => by simpa only [source_offset] using prior.written j j.isLt
  copied := by intro j impossible; omega

/-- The actual reached memcpy packet supplies its actual R0=-16, copied
bytes and caller rights together with the same initialized flag witness. -/
def of_memcpy {initial seed calleeBefore m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    {le : CC.TempEnv} {n : Nat} {cell : TailLocal initial 5} {flagValue : BitVec 8}
    (prior : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore n m le)
    (flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue m) :
    Caller base abi byte calleeBefore (-16#64) n cell flagValue m le where
  memory := {
    view := prior.packet.view
    stackSame := prior.packet.stackSame
    tagsSame := prior.packet.tagsSame
    resources := prior.packet.resources
    storage := prior.packet.storage
    spAtBase := prior.packet.spAtBase
    r0 := prior.packet.r0
    abiHeader := prior.packet.abiHeader
    abiKind := prior.packet.abiKind
    tagBytes := prior.packet.tagBytes
    source := fun j => by simpa only [source_offset] using prior.packet.written j
    copied := prior.copied }
  callee := prior.callee
  entryRead := prior.entryRead
  length := prior.length
  counter := prior.counter
  sourceTag := prior.sourceTag
  flag := flag

/-- A real admitted provider/cache frame transports the shared memory
packet while allowing its two cache cells and supplied heap to change. -/
def Packet.supplied {initial seed before after : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {rawR0 : BitVec 64} {n : Nat}
    (prior : Packet base abi byte rawR0 n before)
    (frame : Arm64ProgramEntryCacheFrame.Frame initial false before after) : Packet base abi byte rawR0 n after := by
  have tail := Arm64ProducerTailFrame.of_cache entry frame
  let view : Arm64MemsetHeaderView.View initial after entry := {
    stack := prior.view.stack
    tags := prior.view.tags
    stackPointer := (tail.header CC.Mptr 608).trans prior.view.stackPointer
    tagPointer := (tail.header CC.Mptr 648).trans prior.view.tagPointer
    capacity := (tail.header .Mint32 656).trans prior.view.capacity
    bias := (tail.header .Mint64 672).trans prior.view.bias }
  refine {
    view := view
    stackSame := prior.stackSame
    tagsSame := prior.tagsSame
    resources := Arm64MemsetIterationResources.resources prior.resources tail.header
      (fun block _ => congrArg (CC.PMap.get block) frame.access)
    storage := frame.storage prior.storage
    spAtBase := prior.spAtBase
    r0 := ?_
    abiHeader := (tail.header CC.Mptr 704).trans prior.abiHeader
    abiKind := (tail.tail 6 abi .Mint8unsigned 0).trans prior.abiKind
    tagBytes := ?_
    source := ?_
    copied := ?_ }
  · rw [frame.nextblock]
    exact (frame.gpr prior.storage (0 : Fin 31)).trans prior.r0
  · intro j
    have kept := tail.tail 2 ⟨prior.view.tags.block,prior.view.tags.binding⟩ .Mint8unsigned (j.val : Int)
    change CC.Mem.load .Mint8unsigned after prior.view.tags.block (j.val : Int) =
      CC.Mem.load .Mint8unsigned before prior.view.tags.block (j.val : Int) at kept
    rw [prior.tagsSame] at kept
    exact kept.trans (prior.tagBytes j)
  · intro j
    have kept := tail.tail 0 prior.view.stack .Mint8unsigned (64+(j.val : Int))
    rw [prior.stackSame] at kept
    exact kept.trans (prior.source j)
  · intro j limit
    have kept := tail.tail 0 prior.view.stack .Mint8unsigned (80+(j.val : Int))
    rw [prior.stackSame] at kept
    exact kept.trans (prior.copied j limit)

/-- The same provider witness preserves the actual later memcpy-local
Freeable ranges through its access frame and transports the same flag. -/
def Caller.supplied {initial seed calleeBefore before after : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {rawR0 : BitVec 64} {n : Nat} {cell : TailLocal initial 5} {flagValue : BitVec 8} {outerLe : CC.TempEnv}
    (prior : Caller base abi byte calleeBefore rawR0 n cell flagValue before outerLe)
    (frame : Arm64ProgramEntryCacheFrame.Frame initial false before after) :
    Caller base abi byte calleeBefore rawR0 n cell flagValue after outerLe where
  memory := prior.memory.supplied frame
  callee := fun id value binding => (CC.Mem.rangePerm_congr (m1 := after) (m2 := before)
    (fun offset => by simp only [CC.Mem.perm,frame.access])).trans (prior.callee id value binding)
  entryRead := prior.entryRead
  length := prior.length
  counter := prior.counter
  sourceTag := prior.sourceTag
  flag := prior.flag.tail_frame (Arm64ProducerTailFrame.of_cache entry frame)

end KProgFormal.ClightRefinement.Arm64ClobberMemoryState
