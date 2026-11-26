import KProgFormal.ClightRefinement.Arm64ClobberResult
import KProgFormal.ClightRefinement.Arm64ProducerEntryView

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ClobberNativeFlags

open Arm64Producer Arm64ProducerRegisterStorage

/-- Interpret the same four actual masked helper outcomes using the imported
architectural flag writer. Every other native field retains its observation. -/
def native (s : Reference.AArch64.State) (values : Fin 4 → BitVec 64) : Reference.AArch64.State :=
  { s with machine := write_pstate (make_pstate
      ((flagWord (values 0)).setWidth 1) ((flagWord (values 1)).setWidth 1)
      ((flagWord (values 2)).setWidth 1) ((flagWord (values 3)).setWidth 1)) s.machine }

theorem masked_scalar (value : BitVec 64) :
    ((flagWord value).setWidth 1).setWidth 32 = flagWord value := by
  rcases flag_word_bit value with zero | one
  · rw [zero]; rfl
  · rw [one]; rfl

theorem native_values (s : Reference.AArch64.State) (values : Fin 4 → BitVec 64) :
    ∀ i : Fin 4, Arm64ProducerEntryView.flagValues (native s values) i = .Vint (flagWord (values i)) := by
  simp only [Fin.forall_fin_succ,Fin.forall_fin_zero]
  refine ⟨?_,?_,?_,?_,trivial⟩ <;>
    simp +decide [Arm64ProducerEntryView.flagValues,native,write_pstate,make_pstate,read_flag,
      r_of_w_different,r_of_w_same,masked_scalar] <;> rfl

theorem native_other (s : Reference.AArch64.State) (values : Fin 4 → BitVec 64)
    (field : StateField) (other : ∀ flag, field ≠ .FLAG flag) :
    r field (native s values).machine = r field s.machine := by
  simp only [native,write_pstate,make_pstate]
  rw [r_of_w_different (other .V),r_of_w_different (other .C),
    r_of_w_different (other .Z),r_of_w_different (other .N)]

/-- The same completed memory helper packet derives the condition reader's
flag relation directly from its actual selected provider map. -/
theorem represented {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {rawR0 : BitVec 64} {copiedN : Nat} {gprs : Fin 18 → BitVec 64}
    {flags : Fin 4 → BitVec 64} {vectors : Fin 64 → BitVec 64} {cell : TailLocal initial 5} {flagValue : BitVec 8}
    (packet : Arm64ClobberResult.Packet base abi byte rawR0 copiedN gprs flags vectors cell flagValue m)
    (s : Reference.AArch64.State) :
    Arm64Nop.FlagsRepresent m.nextblock m (.Vptr entry.block 0) (native s flags) := by
  have nn := packet.flagWords 0
  have zz := packet.flagWords 1
  have cc := packet.flagWords 2
  have vv := packet.flagWords 3
  change Arm64EntryMemory.borrowed m.nextblock .Mint8unsigned m (.Vptr entry.block 0) Arm64Program._n = _ at nn
  change Arm64EntryMemory.borrowed m.nextblock .Mint8unsigned m (.Vptr entry.block 0) Arm64Program._z = _ at zz
  change Arm64EntryMemory.borrowed m.nextblock .Mint8unsigned m (.Vptr entry.block 0) Arm64Program._c = _ at cc
  change Arm64EntryMemory.borrowed m.nextblock .Mint8unsigned m (.Vptr entry.block 0) Arm64Program._v = _ at vv
  unfold Arm64Nop.FlagsRepresent Arm64EntryMemory.flags
  rw [nn,zz,cc,vv]
  have n := native_values s flags 0
  have z := native_values s flags 1
  have c := native_values s flags 2
  have v := native_values s flags 3
  change CC.Val.Vint ((read_flag .N (native s flags).machine).setWidth 32) = _ at n
  change CC.Val.Vint ((read_flag .Z (native s flags).machine).setWidth 32) = _ at z
  change CC.Val.Vint ((read_flag .C (native s flags).machine).setWidth 32) = _ at c
  change CC.Val.Vint ((read_flag .V (native s flags).machine).setWidth 32) = _ at v
  simp only [bind,pure,Option.bind_some,n,z,c,v]

end KProgFormal.ClightRefinement.Arm64ClobberNativeFlags
