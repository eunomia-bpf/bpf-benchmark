import KProgFormal.ClightRefinement.Arm64ProgramEntryJccNative
import KProgFormal.ClightRefinement.Arm64ProgramEntryJccComplete

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryJccSourceNative

open Arm64ProgramEntryAllocation (world allocation)
open Arm64Producer (HeaderLocal TailLocal)

/-- The actual helper flag transport retains the current instruction cursor. -/
theorem pc_before (s : Reference.AArch64.State) (flags : Fin 4 → BitVec 64) :
    read_pc (Arm64ClobberNativeFlags.native s flags).machine = read_pc s.machine := by
  exact Arm64ClobberNativeFlags.native_other s flags .PC (by intro flag; intro impossible; cases impossible)

/-- The same actual flag transport retains the complete native error field. -/
theorem error_before (s : Reference.AArch64.State) (flags : Fin 4 → BitVec 64) :
    read_err (Arm64ClobberNativeFlags.native s flags).machine = read_err s.machine := by
  exact Arm64ClobberNativeFlags.native_other s flags .ERR (by intro flag; intro impossible; cases impossible)

/-- Current code and its real fetch survive the actual helper flag update. -/
theorem fetch_before (s : Reference.AArch64.State) (flags : Fin 4 → BitVec 64) :
    fetch_inst (read_pc (Arm64ClobberNativeFlags.native s flags).machine)
      (Arm64ClobberNativeFlags.native s flags).machine = fetch_inst (read_pc s.machine) s.machine := by
  rw [pc_before]
  simp [fetch_inst,Arm64ClobberNativeFlags.native,write_pstate,make_pstate,w,write_base_flag]

/-- Bind that same flag state, actual code and instruction certificate to the
mature step. The branch retains its imported taken/fallthrough PC and histories. -/
theorem reference_step (s : Reference.AArch64.State) (flags : Fin 4 → BitVec 64)
    (instruction : Reference.AArch64.Instruction) (mark : BitVec 32) (offset : BitVec 19)
    (decoded : instruction.decoded = .BR (.Cond_branch_imm
      (Arm64ProgramEntryJccNative.fields (BitVec.ofNat 4 (Arm64ProgramEntryJcc.code mark).val) offset)))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    Reference.AArch64.step (Arm64ClobberNativeFlags.native s flags) =
      ⟨Arm64ProgramEntryJccNative.after (Arm64ClobberNativeFlags.native s flags)
        (BitVec.ofNat 4 (Arm64ProgramEntryJcc.code mark).val) offset,[],none⟩ := by
  apply Arm64ProgramEntryJccNative.reference_step _ instruction _ offset decoded
  · exact (error_before s flags).trans noError
  · exact (fetch_before s flags).trans fetched

/-- The original source segment executes its full condition call, label search
and genuine false-path XOR on the SAME completed memcpy packet. Its selected
condition is the actual fetched branch predicate. The source segment includes
the false-path XOR before its common label; the one native step exposes both
actual PCs for the continuing code/label and fallthrough-instruction binding. -/
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
    (s : Reference.AArch64.State) (instruction : Reference.AArch64.Instruction) (offset : BitVec 19)
    (decoded : instruction.decoded = .BR (.Cond_branch_imm
      (Arm64ProgramEntryJccNative.fields (BitVec.ofNat 4 (Arm64ProgramEntryJcc.code mark).val) offset)))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    let n := Arm64ClobberNativeFlags.native s flags
    let code := BitVec.ofNat 4 (Arm64ProgramEntryJcc.code mark).val
    let predicate := BR.Cond_branch_imm_inst.condition_holds (Arm64ProgramEntryJccNative.fields code offset) n.machine
    ∃ count, InternalRun world count
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64MemcpyProgramEntry.next k
        (allocation initial).1 le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryJccLabels.takenBody
        (.Kseq Arm64ProgramEntryJccLabels.takenAfter k) (allocation initial).1
        (Arm64ProgramEntryJccComplete.temps le before (values 63) mark n) m) ∧
      Arm64Nop.FlagsRepresent m.nextblock m (.Vptr entry.block 0) n ∧
      Reference.AArch64.step n = ⟨Arm64ProgramEntryJccNative.after n code offset,[],none⟩ ∧
      (Arm64ProgramEntryJccComplete.temps le before (values 63) mark n).get Arm64ProgramFixture._result =
        some (.Vlong (if predicate then before ^^^ values 63 else (before ^^^ values 63) ^^^ 1#64)) ∧
      (Arm64ProgramEntryJccComplete.temps le before (values 63) mark n).get Arm64ProgramFixture._ctx =
        some (.Vptr ctxBlock ctxOffset) ∧
      Arm64ProgramEntryJcc.truth mark n = (if predicate then 1#32 else 0#32) ∧
      read_pc (Arm64ProgramEntryJccNative.after n code offset).machine =
        (if predicate then BR.Cond_branch_imm_inst.branch_taken_pc
          (Arm64ProgramEntryJccNative.fields code offset) (read_pc n.machine) else read_pc n.machine + 4#64) := by
  dsimp only
  obtain ⟨count,run⟩ := Arm64ProgramEntryJccComplete.execute packet frame le k hk ctxBlock ctxOffset mark
    ctxBelow ctx originalMark before prior s
  refine ⟨count,run,Arm64ClobberNativeFlags.represented packet s,
    reference_step s flags instruction mark offset decoded noError fetched,?_,?_,
    Arm64ProgramEntryJccNative.source_truth _ mark offset,?_⟩
  · rw [Arm64ProgramEntryJccComplete.result_readback,Arm64ProgramEntryJccNative.condition]
    rfl
  · exact (Arm64ProgramEntryJccComplete.ctx_preserved le before (values 63) mark _).trans ctx
  · rw [Arm64ProgramEntryJccNative.pc,Arm64ProgramEntryJccNative.condition]
    rfl

end KProgFormal.ClightRefinement.Arm64ProgramEntryJccSourceNative
