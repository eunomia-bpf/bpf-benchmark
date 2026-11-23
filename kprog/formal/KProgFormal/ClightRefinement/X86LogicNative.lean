import KProgFormal.ClightRefinement.X86AluReturn
import X86.Theorems

namespace KProgFormal.ClightRefinement.X86LogicNative

/-- The imported ISA executes each logical byte-register form with the exact
raw source result, one AF oracle draw and next PC. All remaining native CPU
fields retain their values, including memory, other registers and model state. -/
theorem register_step (cpu : X86.Cpu) (dst src : Fin 16) (highDst highSrc : Bool)
    (kind : X86.BinKind) (value : BitVec 64) (length : Nat) (live : X86.Live cpu)
    (selected :
      (kind = .xor ∧ value = cpu.getReg .b (X86.GPR.ofIndex dst) highDst ^^^
        cpu.getReg .b (X86.GPR.ofIndex src) highSrc) ∨
      (kind = .or ∧ value = cpu.getReg .b (X86.GPR.ofIndex dst) highDst |||
        cpu.getReg .b (X86.GPR.ofIndex src) highSrc) ∨
      (kind = .and ∧ value = cpu.getReg .b (X86.GPR.ofIndex dst) highDst &&&
        cpu.getReg .b (X86.GPR.ofIndex src) highSrc))
    (addressWidth : X86.LinearAddressWidth := .la48) :
    X86.step ⟨.bin kind .b (.reg (X86.GPR.ofIndex dst) highDst)
      (.reg (X86.GPR.ofIndex src) highSrc), length⟩ cpu addressWidth =
      {cpu.setReg .b (X86.GPR.ofIndex dst) value highDst with
        flags := X86.Flags.logic .b (X86.Value.trunc .b value)
          (cpu.oracle.bits cpu.oracle.cursor) cpu.flags,
        oracle := {cpu.oracle with cursor := cpu.oracle.cursor + 1},
        rip := cpu.rip + BitVec.ofNat 64 length} := by
  change X86.step ⟨.bin kind .b (.reg (X86.GPR.ofIndex dst) highDst)
    (.reg (X86.GPR.ofIndex src) highSrc), length⟩ cpu = _
  rcases selected with ⟨rfl, rfl⟩ | ⟨rfl, rfl⟩ | ⟨rfl, rfl⟩
  · simpa only [X86.Cpu.readOperand, X86.Cpu.setReg, X86.Value.writeHigh8,
      X86.Value.writeView, X86.Value.trunc_trunc] using
      (X86.step_xor_reg_op (s := cpu) (len := length) .b (X86.GPR.ofIndex dst) highDst
        (.reg (X86.GPR.ofIndex src) highSrc) live rfl)
  · simpa only [X86.Cpu.readOperand, X86.Cpu.setReg, X86.Value.writeHigh8,
      X86.Value.writeView, X86.Value.trunc_trunc] using
      (X86.step_or_reg_op (s := cpu) (len := length) .b (X86.GPR.ofIndex dst) highDst
        (.reg (X86.GPR.ofIndex src) highSrc) live rfl)
  · simpa only [X86.Cpu.readOperand, X86.Cpu.setReg, X86.Value.writeHigh8,
      X86.Value.writeView, X86.Value.trunc_trunc] using
      (X86.step_and_reg_op (s := cpu) (len := length) .b (X86.GPR.ofIndex dst) highDst
        (.reg (X86.GPR.ofIndex src) highSrc) live rfl)

/-- Actual source GPR/flag postconditions transport to that imported ISA step.
Both low/high byte lanes and overlapping source/destination registers retain
the native simultaneous-read semantics and its explicit oracle consumption. -/
theorem represented (cpu : X86.Cpu) (dst src : Fin 16) (highDst highSrc : Bool)
    (kind : X86.BinKind) (value : BitVec 64) (length : Nat) (live : X86.Live cpu)
    (selected :
      (kind = .xor ∧ value = cpu.getReg .b (X86.GPR.ofIndex dst) highDst ^^^
        cpu.getReg .b (X86.GPR.ofIndex src) highSrc) ∨
      (kind = .or ∧ value = cpu.getReg .b (X86.GPR.ofIndex dst) highDst |||
        cpu.getReg .b (X86.GPR.ofIndex src) highSrc) ∨
      (kind = .and ∧ value = cpu.getReg .b (X86.GPR.ofIndex dst) highDst &&&
        cpu.getReg .b (X86.GPR.ofIndex src) highSrc))
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.X86.Origins)
    (memory : CC.Mem) (block : CC.Block) (base : CC.Integers.Ptrofs)
    (registers : X86RegisterView.RegistersRepresent addresses origins memory block base
      (cpu.setReg .b (X86.GPR.ofIndex dst) value highDst))
    (places : X86LogicFlagOrder.Locations)
    (flags : X86LogicFlagMemory.FlagsRepresent memory places
      (X86.Flags.logic .b (X86.Value.trunc .b value) (cpu.oracle.bits cpu.oracle.cursor) cpu.flags))
    (addressWidth : X86.LinearAddressWidth := .la48) :
    let next := X86.step ⟨.bin kind .b (.reg (X86.GPR.ofIndex dst) highDst)
      (.reg (X86.GPR.ofIndex src) highSrc), length⟩ cpu addressWidth
    X86RegisterView.RegistersRepresent addresses origins memory block base next ∧
      X86LogicFlagMemory.FlagsRepresent memory places next.flags := by
  dsimp only
  rw [register_step cpu dst src highDst highSrc kind value length live selected addressWidth]
  exact ⟨registers, flags⟩

end KProgFormal.ClightRefinement.X86LogicNative
