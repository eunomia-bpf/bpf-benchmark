import KProgFormal.ClightRefinement.Arm64AddRegisterCall

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64AddRegisterNative

/-- Mature decoded fields for the actual fourth source call: ADD X3,X1,X2,LSL0.
The fetched encoding is bound only by the external decoder certificate. -/
def fields : Add_sub_shifted_reg_cls :=
  { sf := 1, op := 0, S := 0, shift := 0, Rm := 2, imm6 := 0, Rn := 1, Rd := 3 }

private theorem shift_zero {n : Nat} (x : BitVec n) :
    shift_reg x .LSL (0#6) = x := by
  change x <<< (0 : Nat) = x
  exact BitVec.shiftLeft_zero x

/-- Evaluate the actual external shifted-register ADD body. -/
theorem execute (s : Reference.AArch64.State) :
    DPR.exec_add_sub_shifted_reg fields s.machine =
      (Arm64Nop.atCursor (read_pc s.machine + 4#64)
        (Arm64RegisterWrite.nativeUpdate s 3
          (Reference.AArch64.gpr s 1 + Reference.AArch64.gpr s 2) false)).machine := by
  simp +decide [fields, DPR.exec_add_sub_shifted_reg, fst_AddWithCarry_eq_add,
    read_gpr_zr, read_gpr, shift_zero, decode_shift, write_gpr_zr, write_gpr,
    Arm64Nop.atCursor, Arm64RegisterWrite.nativeUpdate, Arm64RegisterWrite.written,
    Reference.AArch64.gpr, write_pc, w, write_base_pc, write_base_gpr]
  rfl

/-- The real fetched/decoded word executes through LNSym's checked wrapper. -/
theorem native_step (s : Reference.AArch64.State) (instruction : Reference.AArch64.Instruction)
    (decoded : instruction.decoded = .DPR (.Add_sub_shifted_reg fields))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    stepi_checked s.machine =
      (Arm64Nop.atCursor (read_pc s.machine + 4#64)
        (Arm64RegisterWrite.nativeUpdate s 3
          (Reference.AArch64.gpr s 1 + Reference.AArch64.gpr s 2) false)).machine := by
  have decode : decode_raw_inst instruction.encoding = some (.DPR (.Add_sub_shifted_reg fields)) :=
    instruction.valid.trans (congrArg some decoded)
  simpa [stepi_checked, stepi, noError, fetched, decode, exec_inst] using execute s

/-- Keep complete native histories/state and expose only the actual new delta. -/
theorem reference_step (s : Reference.AArch64.State) (instruction : Reference.AArch64.Instruction)
    (decoded : instruction.decoded = .DPR (.Add_sub_shifted_reg fields))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    Reference.AArch64.step s =
      ⟨Arm64Nop.atCursor (read_pc s.machine + 4#64)
        (Arm64RegisterWrite.nativeUpdate s 3
          (Reference.AArch64.gpr s 1 + Reference.AArch64.gpr s 2) false), [], none⟩ := by
  have history : read_memory_accesses
      (Arm64Nop.atCursor (read_pc s.machine + 4#64)
        (Arm64RegisterWrite.nativeUpdate s 3
          (Reference.AArch64.gpr s 1 + Reference.AArch64.gpr s 2) false)).machine =
      read_memory_accesses s.machine := by
    simp [Arm64Nop.atCursor, Arm64RegisterWrite.nativeUpdate, read_memory_accesses,
      write_pc, w, write_base_pc, write_base_gpr]
  have afterError : read_err
      (Arm64Nop.atCursor (read_pc s.machine + 4#64)
        (Arm64RegisterWrite.nativeUpdate s 3
          (Reference.AArch64.gpr s 1 + Reference.AArch64.gpr s 2) false)).machine = .None := by
    simpa [Arm64Nop.atCursor, Arm64RegisterWrite.nativeUpdate, read_err,
      write_pc, r_of_w_different] using noError
  simp only [Reference.AArch64.step, native_step s instruction decoded noError fetched,
    history, List.drop_length, afterError, noError]
  rfl

private theorem stored_operand {initial memory : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial memory entry)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      memory.nextblock memory (.Vptr entry.block 0) s)
    (i : Fin 31) (raw : BitVec 64) (known : BitVec 8)
    (word : CC.Mem.load .Mint64 memory ((storage.tables false).cellBlock i) 0 = some (.Vlong raw))
    (kind : CC.Mem.load .Mint8unsigned memory ((storage.tables true).cellBlock i) 0 = some (.Vint (known.setWidth 32))) :
    Reference.AArch64.gpr s i = Reference.Provenance.AArch64.materialize origins raw known := by
  have actual : Arm64EntryMemory.gpr memory.nextblock memory (.Vptr entry.block 0) i.val =
      some (.Vlong raw, .Vint (known.setWidth 32)) := by
    rw [Arm64RegisterWrite.storage_gpr storage i, word, kind]
    rfl
  obtain ⟨value, bits, tag, read, representedValue, nativeWord⟩ := represented.gpr i
  have same := Option.some.inj (read.symm.trans actual)
  have valueEq : value = .Vlong raw := congrArg Prod.fst same
  have wideEq := CC.Val.Vint.inj (congrArg Prod.snd same)
  have tagEq : tag = known := by
    have narrowed := congrArg (fun bits : BitVec 32 => bits.setWidth 8) wideEq
    simpa using narrowed
  have bitsEq : bits = raw := by
    simpa only [valueEq, Arm64Registers.ValueRep] using representedValue
  simpa only [bitsEq, tagEq] using nativeWord

/-- Derive both native operands from the same actual scalar/STACK cells and
existing register representation, with no separate native-address premise. -/
theorem source_bits {initial memory : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial memory entry)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      memory.nextblock memory (.Vptr entry.block 0) s)
    (lhs raw : BitVec 64)
    (lhsWord : CC.Mem.load .Mint64 memory ((storage.tables false).cellBlock 1) 0 = some (.Vlong lhs))
    (lhsTag : CC.Mem.load .Mint8unsigned memory ((storage.tables true).cellBlock 1) 0 = some (.Vint 0))
    (rhsWord : CC.Mem.load .Mint64 memory ((storage.tables false).cellBlock 2) 0 = some (.Vlong raw))
    (rhsTag : CC.Mem.load .Mint8unsigned memory ((storage.tables true).cellBlock 2) 0 = some (.Vint (4#32))) :
    Reference.AArch64.gpr s 1 = lhs ∧ Reference.AArch64.gpr s 2 = raw + origins.stack := by
  have left := stored_operand storage addresses origins s represented 1 lhs (0#8) lhsWord lhsTag
  have right := stored_operand storage addresses origins s represented 2 raw (4#8) rhsWord rhsTag
  constructor
  · simpa [Reference.Provenance.AArch64.materialize] using left
  · simpa [Reference.Provenance.AArch64.materialize] using right

end KProgFormal.ClightRefinement.Arm64AddRegisterNative
