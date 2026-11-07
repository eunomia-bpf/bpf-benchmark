import PacketInvocation
import PacketStoreTransport
set_option maxRecDepth 4096
set_option maxHeartbeats 2000000
namespace KProgTV.PacketPCRelocation
open KProgFormal.Reference KProgTV.PacketCompiled

def shiftPC (base : Word) (s : AArch64.State) : AArch64.State :=
  { s with pc := base + s.pc }

def shiftTransition (base : Word) (result : Transition AArch64.State) : Transition AArch64.State :=
  { result with state := shiftPC base result.state }

def instructionCommutes (base : Word) (s : AArch64.State) (position : Nat) : Prop :=
  match AArch64.decode (native.extract position (position+4)) with
  | .error _ => False
  | .ok instruction => AArch64.step instruction (shiftPC base s) =
      shiftTransition base (AArch64.step instruction s)


theorem all_instructions (base : Word) (s : AArch64.State) :
    ∀ position : Fin 17, instructionCommutes base s (position.val*4) := by
  simp only [Fin.forall_fin_succ]
  refine ⟨?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_, ?_⟩
  all_goals first
    | (intro impossible; exact Fin.elim0 impossible)
    | skip
  all_goals simp only [Fin.val_zero, Fin.val_succ, Fin.ofNat', Fin.instOfNat]
  all_goals unfold instructionCommutes
  all_goals first
    | rw [PacketEntryCertificate.decode0]
    | rw [PacketGuardCertificate.decode4]
    | rw [PacketGuardCertificate.decode8]
    | rw [PacketGuardCertificate.decode12]
    | rw [PacketGuardCertificate.decode16]
    | rw [PacketGuardCertificate.decode20]
    | rw [PacketCheckedBlocks.native_decode24]
    | rw [PacketCheckedBlocks.native_decode28]
    | rw [PacketStoreTransport.packet_decode32]
    | rw [PacketStoreTransport.packet_decode36]
    | rw [PacketStoreTransport.packet_decode40]
    | rw [PacketStoreTransport.packet_decode44]
    | rw [PacketStoreTransport.packet_decode48]
    | rw [PacketStoreTransport.packet_decode52]
    | rw [PacketStoreTransport.packet_decode56]
    | rw [PacketStoreTransport.packet_decode60]
    | rw [PacketCheckedBlocks.native_decode64]
  all_goals simp +decide [Fin.ofNat', Fin.instOfNat, AArch64.step, shiftPC, shiftTransition,
    AArch64.pairMemoryStep, SimpleEntryCertificate.pair, AArch64.pairRegisters,
    AArch64.spAlignmentFault, AArch64.memoryBase, AArch64.readReg, AArch64.writeReg,
    AArch64.moveRegStep, AArch64.readData, AArch64.writeData, AArch64.compareStep,
    AArch64.compareOperand, AArch64.arithmeticImmediateStep, AArch64.arithmeticRegisterStep,
    AArch64.arithmeticShift, AArch64.shiftValue, AArch64.branchStep,
    AArch64.memoryStep, AArch64.MemoryWidth.bytes, BitVec.add_assoc]
  all_goals repeat' first
    | rfl
    | (split <;> simp_all [BitVec.add_assoc])
  all_goals
    cases first : readMemory s.memory (s.gpr 0) AArch64.Width.w64.bytes with
    | error fault => simp_all
    | ok pair =>
        rcases pair with ⟨value, event⟩
        cases second : readMemory s.memory (s.gpr 0 + BitVec.ofNat 64 AArch64.Width.w64.bytes)
            AArch64.Width.w64.bytes with
        | error fault => simp_all
        | ok pair =>
            rcases pair with ⟨value2, event2⟩
            simp_all [BitVec.add_assoc]

/-- Fetch at the callback's actual RX base has the same canonical instruction
and effects; only the complete architectural PC is translated. -/
theorem step_at (base : Word) (s : AArch64.State) (position : Fin 17)
    (atPosition : s.pc = BitVec.ofNat 64 (position.val*4)) :
    ARM64Path.step base native (shiftPC base s) =
      (ARM64Path.step 0 native s).map (shiftTransition base) := by
  have cancel (value : Word) : base + value - base = value := by
    rw [BitVec.add_comm base value]
    exact BitVec.add_sub_cancel value base
  have zero (value : Word) : value - (0 : Word) = value := BitVec.sub_zero value
  have bound : position.val*4 < 2^64 := by omega
  have unwrap : (BitVec.ofNat 64 (position.val*4)).toNat = position.val*4 := by
    simp [BitVec.toNat_ofNat, Nat.mod_eq_of_lt bound]
  have within : ¬ position.val*4+4 > native.size := by
    change ¬ position.val*4+4 > 68
    omega
  have same := all_instructions base s position
  unfold instructionCommutes at same
  cases decoded : AArch64.decode (native.extract (position.val*4) (position.val*4+4)) with
  | error error => simp [decoded] at same
  | ok instruction =>
      have commute : AArch64.step instruction (shiftPC base s) =
          shiftTransition base (AArch64.step instruction s) := by simpa only [decoded] using same
      have original : ARM64Path.step 0 native s = .ok (AArch64.step instruction s) := by
        simp +decide [ARM64Path.step, zero, atPosition, unwrap, within, decoded,
          Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad] <;> omega
      have rebased : ARM64Path.step base native (shiftPC base s) =
          .ok (AArch64.step instruction (shiftPC base s)) := by
        simp +decide [ARM64Path.step, shiftPC, cancel, atPosition, unwrap, within, decoded,
          Except.bind, Except.map, Except.pure, Bind.bind, Pure.pure, Except.instMonad] <;> omega
      rw [original, rebased]
      exact congrArg Except.ok commute

end KProgTV.PacketPCRelocation
#print axioms KProgTV.PacketPCRelocation.all_instructions

#print axioms KProgTV.PacketPCRelocation.step_at
