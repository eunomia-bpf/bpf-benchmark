import KProgFormal.ClightRefinement.Arm64ProgramEntryCmpFrame
import KProgFormal.ClightRefinement.Arm64CompareFlagBytes
import KProgFormal.ClightRefinement.Arm64ClobberNativeFlags

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryCmpFlags
open Arm64Producer
open Arm64Compare

/-- Exact imported subtraction flag tuple in the packet's N,Z,C,V order. -/
def bits (lhs rhs : BitVec 64) (i : Fin 4) : BitVec 1 :=
  let p := (AddWithCarry lhs (~~~rhs) (1#1)).snd
  [p.n,p.z,p.c,p.v][i]
def values (lhs rhs : BitVec 64) (i : Fin 4) : BitVec 64 := (bits lhs rhs i).setWidth 64

private theorem four_cases : ∀ i : Fin 4, i=0 ∨ i=1 ∨ i=2 ∨ i=3 := by decide +kernel
private theorem one_bit (bit : BitVec 1) : bit=0#1 ∨ bit=1#1 := by
  have range := bit.isLt
  have cases : bit.toNat=0 ∨ bit.toNat=1 := by omega
  rcases cases with zero|one
  · left; apply BitVec.eq_of_toNat_eq; exact zero
  · right; apply BitVec.eq_of_toNat_eq; exact one
private theorem encoded_bit (bit : BitVec 1) : flagWord (bit.setWidth 64) = bit.setWidth 32 := by
  rcases one_bit bit with rfl|rfl <;> rfl

theorem source_order (lhs rhs : BitVec 64) (i : Fin 4) :
    bits lhs rhs (Stores.flagIndex i) = Arm64Compare.FlagBytes.bits lhs rhs i := by
  rcases four_cases i with rfl|rfl|rfl|rfl <;> rfl

theorem encoded (lhs rhs : BitVec 64) (i : Fin 4) :
    flagWord (values lhs rhs i) = (bits lhs rhs i).setWidth 32 := encoded_bit _

/-- The actual C stores consume the same arbitrary operands as imported
AddWithCarry; each real source byte equals that imported flag's encoding. -/
theorem source_value (lhs rhs : BitVec 64) (i : Fin 4) :
    Stores.value (Arm64ProgramEntryCmpArithmetic.left lhs false)
      (Arm64ProgramEntryCmpArithmetic.right rhs false)
      (Arm64ProgramEntryCmpArithmetic.result lhs rhs false)
      (Arm64ProgramEntryCmpArithmetic.sign false) i =
      .Vint (flagWord (values lhs rhs (Stores.flagIndex i))) := by
  have raw := Arm64Compare.FlagBytes.source_value lhs rhs i
  have wide : Arm64Compare.Body.rhsValue rhs false = rhs :=
    Arm64Modified.Modifier.result_wide rhs
  unfold Arm64Compare.Call.flagValue at raw
  rw [wide] at raw
  rw [encoded,source_order]
  exact raw

/-- The imported flag writer is used directly; all remaining native state
observations stay available through the mature writer's frame lemmas. -/
def native (s : Reference.AArch64.State) (lhs rhs : BitVec 64) : Reference.AArch64.State :=
  { s with machine := write_pstate (AddWithCarry lhs (~~~rhs) (1#1)).snd s.machine }

theorem native_values (s : Reference.AArch64.State) (lhs rhs : BitVec 64) (i : Fin 4) :
    Arm64ProducerEntryView.flagValues (native s lhs rhs) i = .Vint (flagWord (values lhs rhs i)) := by
  rw [encoded]
  rcases four_cases i with rfl|rfl|rfl|rfl <;>
    simp +decide [Arm64ProducerEntryView.flagValues,native,bits,write_pstate,read_flag,
      r_of_w_same,r_of_w_different] <;> rfl

theorem native_other (s : Reference.AArch64.State) (lhs rhs : BitVec 64)
    (field : StateField) (other : ∀ flag, field ≠ .FLAG flag) :
    r field (native s lhs rhs).machine = r field s.machine := by
  simp only [native,write_pstate]
  rw [r_of_w_different (other .V),r_of_w_different (other .C),
    r_of_w_different (other .Z),r_of_w_different (other .N)]

/-- Four reached bytes, produced by the SAME actual store chain, rebuild the
current source flag observations in N,Z,C,V order. -/
theorem readback {initial before after : CC.Mem} {entry : HeaderLocal initial}
    {storage : Arm64ProducerRegisterStorage.Storage initial before entry} (lhs rhs : BitVec 64)
    (effect : Stores.Effect storage (Arm64ProgramEntryCmpArithmetic.left lhs false)
      (Arm64ProgramEntryCmpArithmetic.right rhs false) (Arm64ProgramEntryCmpArithmetic.result lhs rhs false)
      (Arm64ProgramEntryCmpArithmetic.sign false) after) (j : Fin 4) :
    Arm64EntryMemory.borrowed after.nextblock .Mint8unsigned after (.Vptr entry.block 0)
      (Arm64MemsetClobberFlags.field j) = some (.Vint (flagWord (values lhs rhs j))) := by
  unfold Arm64MemsetClobberFlags.field
  rw [Arm64RegisterWrite.storage_flag effect.storage j]
  have byte (i : Fin 4) := (effect.bytes i).trans (congrArg some (source_value lhs rhs i))
  rcases four_cases j with rfl|rfl|rfl|rfl
  · exact byte 1
  · exact byte 0
  · exact byte 2
  · exact byte 3

/-- The same packet is retained with its UPDATED imported subtraction flags;
all GPR/tag pairs, vectors, copied bytes and initialized flag are transported. -/
def packet {initial seed before after : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {rawR0 : BitVec 64} {copiedN : Nat} {gprs : Fin 18 → BitVec 64}
    {oldFlags : Fin 4 → BitVec 64} {vectors : Fin 64 → BitVec 64}
    {cell : TailLocal initial 5} {flagValue : BitVec 8}
    (prior : Arm64ClobberResult.Packet base abi byte rawR0 copiedN gprs oldFlags vectors cell flagValue before)
    (lhs rhs : BitVec 64)
    (effect : Stores.Effect prior.memory.storage (Arm64ProgramEntryCmpArithmetic.left lhs false)
      (Arm64ProgramEntryCmpArithmetic.right rhs false) (Arm64ProgramEntryCmpArithmetic.result lhs rhs false)
      (Arm64ProgramEntryCmpArithmetic.sign false) after) :
    Arm64ClobberResult.Packet base abi byte rawR0 copiedN gprs (values lhs rhs) vectors cell flagValue after where
  memory := Arm64ProgramEntryCmpFrame.memory effect prior.memory rfl
  registers := fun j => (Arm64ProgramEntryCmpFrame.gpr effect
    (Arm64MemsetClobberRegisters.declaration j).reg).trans (prior.registers j)
  flagWords := readback lhs rhs effect
  vectors := fun j => (Arm64ProgramEntryCmpFrame.vector effect .Mint64
    (Arm64MemsetClobberVectors.offset j)).trans (prior.vectors j)
  flag := prior.flag.tail_frame (Arm64ProgramEntryCmpFrame.tailFrame effect)

/-- Actual reached flag bytes represent the imported subtraction flag writer.
This is a flag-state relation; native instruction/PC composition follows it. -/
theorem represented {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {rawR0 : BitVec 64} {copiedN : Nat} {gprs : Fin 18 → BitVec 64} {vectors : Fin 64 → BitVec 64}
    {cell : TailLocal initial 5} {flagValue : BitVec 8} (lhs rhs : BitVec 64)
    (current : Arm64ClobberResult.Packet base abi byte rawR0 copiedN gprs (values lhs rhs) vectors cell flagValue m)
    (s : Reference.AArch64.State) :
    Arm64Nop.FlagsRepresent m.nextblock m (.Vptr entry.block 0) (native s lhs rhs) := by
  have nn := current.flagWords 0
  have zz := current.flagWords 1
  have cc := current.flagWords 2
  have vv := current.flagWords 3
  change Arm64EntryMemory.borrowed m.nextblock .Mint8unsigned m (.Vptr entry.block 0) Arm64Program._n = _ at nn
  change Arm64EntryMemory.borrowed m.nextblock .Mint8unsigned m (.Vptr entry.block 0) Arm64Program._z = _ at zz
  change Arm64EntryMemory.borrowed m.nextblock .Mint8unsigned m (.Vptr entry.block 0) Arm64Program._c = _ at cc
  change Arm64EntryMemory.borrowed m.nextblock .Mint8unsigned m (.Vptr entry.block 0) Arm64Program._v = _ at vv
  unfold Arm64Nop.FlagsRepresent Arm64EntryMemory.flags
  rw [nn,zz,cc,vv]
  have n := native_values s lhs rhs 0
  have z := native_values s lhs rhs 1
  have c := native_values s lhs rhs 2
  have v := native_values s lhs rhs 3
  change CC.Val.Vint ((read_flag .N (native s lhs rhs).machine).setWidth 32) = _ at n
  change CC.Val.Vint ((read_flag .Z (native s lhs rhs).machine).setWidth 32) = _ at z
  change CC.Val.Vint ((read_flag .C (native s lhs rhs).machine).setWidth 32) = _ at c
  change CC.Val.Vint ((read_flag .V (native s lhs rhs).machine).setWidth 32) = _ at v
  simp only [bind,pure,Option.bind_some,n,z,c,v]

end KProgFormal.ClightRefinement.Arm64ProgramEntryCmpFlags
