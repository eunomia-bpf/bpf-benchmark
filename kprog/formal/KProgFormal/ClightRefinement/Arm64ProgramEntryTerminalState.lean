import KProgFormal.ClightRefinement.Arm64ProgramEntryTerminalFrame

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryTerminalState
open Arm64Producer (HeaderLocal HeaderSourceLocal TailLocal)
open Arm64ProgramEntryTerminalStores (Effect)

private theorem not_zero : ∀ i : Fin 18, (Arm64MemsetClobberRegisters.declaration i).reg ≠ (0 : Fin 31) := by decide +kernel
private theorem word_lr : Arm64Producer.tableCellName false (0 : Fin 31) ≠ Arm64Producer.headerSourceName 4 := by decide +kernel
private theorem tag_lr : Arm64Producer.tableCellName true (0 : Fin 31) ≠ Arm64Producer.headerSourceName 4 := by decide +kernel
private theorem lr_sp : Arm64Producer.headerSourceName 4 ≠ Arm64Entry.___a64_sp := by decide +kernel

section Effect
variable {initial seed before after : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {rawR0 : BitVec 64} {n : Nat} {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64}
    {vectors : Fin 64 → BitVec 64} {cell : TailLocal initial 5} {flagValue : BitVec 8}
    (prior : Arm64ClobberResult.Packet base abi byte rawR0 n gprs flags vectors cell flagValue before)
    {value : BitVec 64} (effect : Effect prior.memory.storage value after)
include effect

/-- The SAME three-store effect supplies a terminal view whose actual SP is
zero and whose real X0 tag is scalar0. -/
def storage : Arm64ProducerRegisterStorage.Storage initial after entry := Arm64ProgramEntryTerminalFrame.storage effect

def view : Arm64MemsetHeaderView.View initial after entry :=
  Arm64MemsetHeaderView.of_frame prior.memory.view (Arm64ProgramEntryTerminalFrame.tailFrame effect)

theorem resources : Arm64ProgramEntryResources.Resources initial after entry :=
  Arm64MemsetIterationResources.resources prior.memory.resources (Arm64ProgramEntryTerminalFrame.tailFrame effect).header
    (fun block _ => congrArg (CC.PMap.get block) (Arm64ProgramEntryTerminalFrame.access effect))

theorem r0 : Arm64EntryMemory.gpr after.nextblock after (.Vptr entry.block 0) 0 = some (.Vlong value,.Vint (0#32)) :=
  Arm64ProgramEntryTerminalFrame.r0 effect

theorem sp : Arm64EntryMemory.borrowed after.nextblock .Mint64 after (.Vptr entry.block 0) Arm64Program._sp = some (.Vlong 0) :=
  Arm64ProducerEntryView.header_borrowed_readback after entry.block 5 .Mint64 (storage prior effect).sp.block 0 _
    (storage prior effect).spPointer (storage prior effect).spRead

theorem registers (i : Fin 18) : Arm64EntryMemory.gpr after.nextblock after (.Vptr entry.block 0)
    (Arm64MemsetClobberRegisters.declaration i).reg.val = some (.Vlong (gprs i),.Vint 0) := by
  have keep := Arm64ProgramEntryTerminalFrame.gpr effect (Arm64MemsetClobberRegisters.declaration i).reg
  rw [ite_eq_right (not_zero i)] at keep
  exact keep.trans (prior.registers i)

theorem flagWords (i : Fin 4) : Arm64EntryMemory.borrowed after.nextblock .Mint8unsigned after (.Vptr entry.block 0)
    (Arm64MemsetClobberFlags.field i) = some (.Vint (Arm64Producer.flagWord (flags i))) :=
  (Arm64ProgramEntryTerminalFrame.flag effect i).trans (prior.flagWords i)

theorem vector (i : Fin 64) : CC.Mem.load .Mint64 after prior.memory.storage.vectors.block (Arm64MemsetClobberVectors.offset i) =
    some (.Vlong (vectors i)) := (Arm64ProgramEntryTerminalFrame.vector effect i).trans (prior.vectors i)

theorem flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue after :=
  prior.flag.tail_frame (Arm64ProgramEntryTerminalFrame.tailFrame effect)

theorem abiHeader : CC.Mem.load CC.Mptr after entry.block 704 = some (.Vptr abi.block 0) :=
  ((Arm64ProgramEntryTerminalFrame.tailFrame effect).header CC.Mptr 704).trans prior.memory.abiHeader

theorem abiKind : CC.Mem.load .Mint8unsigned after abi.block 0 = some (.Vint 2) :=
  ((Arm64ProgramEntryTerminalFrame.tailFrame effect).tail 6 abi .Mint8unsigned 0).trans prior.memory.abiKind

theorem tagBytes (j : Fin 24) : CC.Mem.load .Mint8unsigned after base.tags.block (j.val : Int) = some (.Vint 0) := by
  have kept := (Arm64ProgramEntryTerminalFrame.tailFrame effect).tail 2
    ⟨prior.memory.view.tags.block,prior.memory.view.tags.binding⟩ .Mint8unsigned (j.val : Int)
  change CC.Mem.load .Mint8unsigned after prior.memory.view.tags.block (j.val : Int) =
    CC.Mem.load .Mint8unsigned before prior.memory.view.tags.block (j.val : Int) at kept
  rw [prior.memory.tagsSame] at kept
  exact kept.trans (prior.memory.tagBytes j)

theorem source (j : Fin 16) : CC.Mem.load .Mint8unsigned after base.stack.block (64+(j.val : Int)) =
    some (.Vint (byte.setWidth 32)) := by
  have kept := (Arm64ProgramEntryTerminalFrame.tailFrame effect).tail 0 prior.memory.view.stack .Mint8unsigned (64+(j.val : Int))
  rw [prior.memory.stackSame] at kept
  exact kept.trans (prior.memory.source j)

theorem copied (j : Fin 16) (limit : j.val < n) : CC.Mem.load .Mint8unsigned after base.stack.block (80+(j.val : Int)) =
    some (.Vint (byte.setWidth 32)) := by
  have kept := (Arm64ProgramEntryTerminalFrame.tailFrame effect).tail 0 prior.memory.view.stack .Mint8unsigned (80+(j.val : Int))
  rw [prior.memory.stackSame] at kept
  exact kept.trans (prior.memory.copied j limit)

theorem lr (lrCell : HeaderSourceLocal initial 4) : CC.Mem.load .Mint64 after lrCell.block 0 = CC.Mem.load .Mint64 before lrCell.block 0 :=
  Arm64ProgramEntryTerminalFrame.local_load effect _ _ _ lrCell.binding word_lr tag_lr lr_sp .Mint64 0

theorem link (observed : Arm64EntryMemory.gpr before.nextblock before (.Vptr entry.block 0) 30 = some (.Vlong 64,.Vint (9#32))) :
    Arm64EntryMemory.gpr after.nextblock after (.Vptr entry.block 0) 30 = some (.Vlong 64,.Vint (9#32)) := by
  have keep := Arm64ProgramEntryTerminalFrame.gpr effect (30 : Fin 31)
  rw [ite_eq_right (by decide : (30 : Fin 31) ≠ 0)] at keep
  exact keep.trans observed

end Effect
end KProgFormal.ClightRefinement.Arm64ProgramEntryTerminalState
