import KProgFormal.ClightRefinement.Arm64ProgramEntryJccSourceNative

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryJccDecoded
open Arm64ProgramEntryAllocation (world allocation)
open Arm64Producer (HeaderLocal TailLocal)

/-- Decode every actual mark%15 form with the original 64-to-32 byte delta.
This finite kernel check concerns only the instruction encoding; its condition
semantics are imported unchanged. -/
private theorem decode_all : ∀ code : Fin 15,
    decode_raw_inst (0x54ffff00#32 ||| BitVec.ofNat 32 code.val) =
      some (.BR (.Cond_branch_imm (Arm64ProgramEntryJccNative.fields
        (BitVec.ofNat 4 code.val) (-8#19)))) := by decide +kernel

def instruction (mark : BitVec 32) : Reference.AArch64.Instruction :=
  ⟨0x54ffff00#32 ||| BitVec.ofNat 32 (Arm64ProgramEntryJcc.code mark).val,
   .BR (.Cond_branch_imm (Arm64ProgramEntryJccNative.fields
     (BitVec.ofNat 4 (Arm64ProgramEntryJcc.code mark).val) (-8#19))),
   decode_all (Arm64ProgramEntryJcc.code mark)⟩

theorem target (code : BitVec 4) (cursor : BitVec 64) :
    BR.Cond_branch_imm_inst.branch_taken_pc (Arm64ProgramEntryJccNative.fields code (-8#19)) cursor =
      cursor + (-32#64) := by
  change cursor + BitVec.signExtend 64 ((-8#19) ++ 0#2) = cursor + (-32#64)
  apply congrArg (fun delta : BitVec 64 => cursor + delta)
  decide +kernel

/-- The original current-source offset is -32 bytes, and fallthrough is +4. -/
theorem pc (s : Reference.AArch64.State) (mark : BitVec 32) :
    read_pc (Arm64ProgramEntryJccNative.after s
      (BitVec.ofNat 4 (Arm64ProgramEntryJcc.code mark).val) (-8#19)).machine =
      read_pc s.machine + (if ConditionHolds
        (BitVec.ofNat 4 (Arm64ProgramEntryJcc.code mark).val) s.machine then (-32#64) else 4#64) := by
  rw [Arm64ProgramEntryJccNative.pc,target]
  split <;> rfl

theorem reference_step (s : Reference.AArch64.State) (flags : Fin 4 → BitVec 64) (mark : BitVec 32)
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some (instruction mark).encoding) :
    Reference.AArch64.step (Arm64ClobberNativeFlags.native s flags) =
      ⟨Arm64ProgramEntryJccNative.after (Arm64ClobberNativeFlags.native s flags)
        (BitVec.ofNat 4 (Arm64ProgramEntryJcc.code mark).val) (-8#19),[],none⟩ :=
  Arm64ProgramEntryJccSourceNative.reference_step s flags (instruction mark) mark (-8#19) rfl noError fetched

/-- The complete original JCC source caller and actual source-selected native
word share the same provider packet. The decoder premise is discharged for all
fifteen real conditions; current code admission/fetch remains explicit. -/
theorem complete {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    {cell : TailLocal initial 5} {flagValue : BitVec 8}
    (packet : Arm64ClobberResult.Packet base abi byte (-16#64) 16 gprs flags values cell flagValue m)
    (frame : FrameBelow initial.nextblock initial m)
    (le : CC.TempEnv) (k : CC.Cont) (hk : CC.isCallCont k = true)
    (ctxBlock : CC.Block) (ctxOffset : CC.Integers.Ptrofs) (mark : BitVec 32)
    (ctxBelow : ctxBlock.toNat < initial.nextblock.toNat)
    (ctx : le.get Arm64ProgramFixture._ctx = some (.Vptr ctxBlock ctxOffset))
    (originalMark : CC.Mem.loadv .Mint32 initial
      (.Vptr ctxBlock (CC.Integers.Ptrofs.add ctxOffset (CC.Integers.Ptrofs.repr 8))) = some (.Vint mark))
    (before : BitVec 64) (prior : le.get Arm64ProgramFixture._result = some (.Vlong before))
    (s : Reference.AArch64.State)
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some (instruction mark).encoding) :
    let n := Arm64ClobberNativeFlags.native s flags
    let code := BitVec.ofNat 4 (Arm64ProgramEntryJcc.code mark).val
    let predicate := BR.Cond_branch_imm_inst.condition_holds (Arm64ProgramEntryJccNative.fields code (-8#19)) n.machine
    ∃ count, InternalRun world count
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64MemcpyProgramEntry.next k
        (allocation initial).1 le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryJccLabels.takenBody
        (.Kseq Arm64ProgramEntryJccLabels.takenAfter k) (allocation initial).1
        (Arm64ProgramEntryJccComplete.temps le before (values 63) mark n) m) ∧
      Arm64Nop.FlagsRepresent m.nextblock m (.Vptr entry.block 0) n ∧
      Reference.AArch64.step n = ⟨Arm64ProgramEntryJccNative.after n code (-8#19),[],none⟩ ∧
      (Arm64ProgramEntryJccComplete.temps le before (values 63) mark n).get Arm64ProgramFixture._result =
        some (.Vlong (if predicate then before ^^^ values 63 else (before ^^^ values 63) ^^^ 1#64)) ∧
      (Arm64ProgramEntryJccComplete.temps le before (values 63) mark n).get Arm64ProgramFixture._ctx =
        some (.Vptr ctxBlock ctxOffset) ∧
      Arm64ProgramEntryJcc.truth mark n = (if predicate then 1#32 else 0#32) ∧
      read_pc (Arm64ProgramEntryJccNative.after n code (-8#19)).machine =
        (if predicate then BR.Cond_branch_imm_inst.branch_taken_pc
          (Arm64ProgramEntryJccNative.fields code (-8#19)) (read_pc n.machine) else read_pc n.machine + 4#64) := by
  exact Arm64ProgramEntryJccSourceNative.complete packet frame le k hk ctxBlock ctxOffset mark
    ctxBelow ctx originalMark before prior s (instruction mark) (-8#19) rfl noError fetched

end KProgFormal.ClightRefinement.Arm64ProgramEntryJccDecoded
