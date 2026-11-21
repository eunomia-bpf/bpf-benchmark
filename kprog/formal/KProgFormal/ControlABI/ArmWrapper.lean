import KProgFormal.Reference.AArch64

/-! The native ARM64 JIT copies X0 to BPF_R0/X7 before the stock epilogue,
which copies X7 back to X0. These are the real LNSym decoded MOV instructions.
PAC/BTI, physical image embedding, stack permissions and exception frames keep
their kernel/platform interpretation. -/
namespace KProgFormal.ControlABI.ArmWrapper

/-- A64_MOV(1, dst, src) is ORR Xdst, XZR, Xsrc, LSL #0. -/
def moveFields (destination source : BitVec 5) : Logical_shifted_reg_cls :=
  { sf := 1, opc := 1, shift := 0, N := 0, Rm := source,
    imm6 := 0, Rn := 31, Rd := destination }

theorem bridge_in_decodes : decode_raw_inst 0xaa0003e7#32 =
    some (.DPR (.Logical_shifted_reg (moveFields 7 0))) := by decide +kernel

theorem bridge_out_decodes : decode_raw_inst 0xaa0703e0#32 =
    some (.DPR (.Logical_shifted_reg (moveFields 0 7))) := by decide +kernel

/-- Every MOV source bit and every untouched architectural field come from
LNSym's actual execution, including arbitrary incoming vectors and flags. -/
theorem execute_move (state : ArmState) (destination source : BitVec 5) :
    DPR.exec_logical_shifted_reg (moveFields destination source) state =
      write_gpr_zr 64 destination (read_gpr_zr 64 source state)
        (write_pc (read_pc state + 4) state) := by
  simp +decide only [DPR.exec_logical_shifted_reg, moveFields,
    DPR.decode_op, DPR.exec_logical_shifted_reg_op, decode_shift, shift_reg]
  change write_gpr_zr 64 destination
    ((read_gpr_zr 64 31 state) ||| (read_gpr_zr 64 source state) <<< 0)
    (write_pc (read_pc state + 4) state) = _
  simp [read_gpr_zr, BitVec.shiftLeft_zero, BitVec.zero_or]

/-- The JIT's incoming bridge saves the native result in X7. -/
theorem bridge_in (state : ArmState) :
    r (.GPR 7) (DPR.exec_logical_shifted_reg (moveFields 7 0) state) = r (.GPR 0) state := by
  rw [execute_move]
  simp [write_gpr_zr, read_gpr_zr, read_gpr, write_gpr, r_of_w_same]

/-- Every intervening epilogue prefix that retains X7 delivers the original
native X0 through the actual outgoing MOV. The stack-unwind correspondence is
kept separate from this exact dataflow fact. -/
theorem bridge_result (state intermediate : ArmState)
    (saved : r (.GPR 7) intermediate =
      r (.GPR 7) (DPR.exec_logical_shifted_reg (moveFields 7 0) state)) :
    r (.GPR 0) (DPR.exec_logical_shifted_reg (moveFields 0 7) intermediate) =
      r (.GPR 0) state := by
  rw [bridge_in] at saved
  rw [execute_move]
  simpa [write_gpr_zr, read_gpr_zr, read_gpr, write_gpr,
    r_of_w_same] using saved

end KProgFormal.ControlABI.ArmWrapper

#print axioms KProgFormal.ControlABI.ArmWrapper.bridge_in_decodes
#print axioms KProgFormal.ControlABI.ArmWrapper.execute_move
#print axioms KProgFormal.ControlABI.ArmWrapper.bridge_result
