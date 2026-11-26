import KProgFormal.ClightRefinement.Arm64ProgramEntrySourceReturnNative

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryPostMemoryCmpView
open Arm64Producer (HeaderLocal HeaderSourceLocal TailLocal)
open Arm64ProgramEntryAllocation (world allocation)

/-- SAME input observations already used by original JCC/CBZ/TBNZ source
calls: provider NZCV, scalar X3 and scalar X4. This is a representation view;
actual native/helper execution and physical memory retain separate domains. -/
def native (s : Reference.AArch64.State) (gprs : Fin 18 → BitVec 64) (flags : Fin 4 → BitVec 64) : Reference.AArch64.State :=
  Arm64ProgramEntryTbnzCall.native (Arm64ProgramEntryCbzCall.native (Arm64ClobberNativeFlags.native s flags) (gprs 2)) (gprs 3)

theorem left (s : Reference.AArch64.State) (gprs : Fin 18 → BitVec 64) (flags : Fin 4 → BitVec 64) :
    Reference.AArch64.gpr (native s gprs flags) 3 = gprs 2 := by
  change r (.GPR (3#5)) (native s gprs flags).machine = gprs 2
  exact (Arm64ProgramEntryTbnzCall.native_other _ (gprs 3) (.GPR (3#5)) (by decide)).trans
    (Arm64ProgramEntryCbzCall.native_word _ (gprs 2))

theorem right (s : Reference.AArch64.State) (gprs : Fin 18 → BitVec 64) (flags : Fin 4 → BitVec 64) :
    Reference.AArch64.gpr (native s gprs flags) 4 = gprs 3 :=
  Arm64ProgramEntryTbnzCall.native_word _ (gprs 3)

theorem pc (s : Reference.AArch64.State) (gprs : Fin 18 → BitVec 64) (flags : Fin 4 → BitVec 64) :
    read_pc (native s gprs flags).machine = read_pc s.machine := by
  exact (Arm64ProgramEntryTbnzCall.native_other _ (gprs 3) .PC (by decide)).trans
    ((Arm64ProgramEntryCbzCall.native_other _ (gprs 2) .PC (by decide)).trans
      (Arm64ClobberNativeFlags.native_other s flags .PC (by intro flag; intro impossible; cases impossible)))

theorem error (s : Reference.AArch64.State) (gprs : Fin 18 → BitVec 64) (flags : Fin 4 → BitVec 64) :
    read_err (native s gprs flags).machine = read_err s.machine := by
  exact (Arm64ProgramEntryTbnzCall.native_other _ (gprs 3) .ERR (by decide)).trans
    ((Arm64ProgramEntryCbzCall.native_other _ (gprs 2) .ERR (by decide)).trans
      (Arm64ClobberNativeFlags.native_other s flags .ERR (by intro flag; intro impossible; cases impossible)))

theorem code (s : Reference.AArch64.State) (gprs : Fin 18 → BitVec 64) (flags : Fin 4 → BitVec 64) (cursor : BitVec 64) :
    fetch_inst cursor (native s gprs flags).machine = fetch_inst cursor s.machine := by
  simp [fetch_inst,native,Arm64ProgramEntryTbnzCall.native,Arm64ProgramEntryCbzCall.native,
    Arm64ClobberNativeFlags.native,write_pstate,make_pstate,w,write_base_flag,write_base_gpr]

theorem fetch (s : Reference.AArch64.State) (gprs : Fin 18 → BitVec 64) (flags : Fin 4 → BitVec 64) :
    fetch_inst (read_pc (native s gprs flags).machine) (native s gprs flags).machine =
      fetch_inst (read_pc s.machine) s.machine := by
  rw [pc,code]

theorem compare_fetch (s : Reference.AArch64.State) (gprs : Fin 18 → BitVec 64) (flags : Fin 4 → BitVec 64) :
    fetch_inst (read_pc (Arm64ProgramEntryCmpNative.after (native s gprs flags)).machine)
      (Arm64ProgramEntryCmpNative.after (native s gprs flags)).machine =
      fetch_inst (read_pc s.machine + 4#64) s.machine := by
  rw [Arm64ProgramEntryCmpNative.pc,pc]
  have retained (cursor : BitVec 64) : fetch_inst cursor
      (Arm64ProgramEntryCmpNative.after (native s gprs flags)).machine = fetch_inst cursor (native s gprs flags).machine := by
    simp [fetch_inst,Arm64ProgramEntryCmpNative.after,write_pstate,write_pc,w,write_base_pc,write_base_flag]
  rw [retained,code]

/-- The original provider values and original code derive actual CMP operands,
PC/error/fetch observations for the SAME full source-return witness. A fresh
CMP state or separate register-representation premise is not required. -/
theorem execute {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {vectors : Fin 64 → BitVec 64}
    {cell : TailLocal initial 5} {flagValue : BitVec 8}
    (prior : Arm64ClobberResult.Packet base abi byte (-16#64) 16 gprs flags vectors cell flagValue m)
    (frame : FrameBelow initial.nextblock initial m)
    (le : CC.TempEnv) (k : CC.Cont) (hk : CC.isCallCont k = true)
    (ctxBlock : CC.Block) (ctxOffset : CC.Integers.Ptrofs) (mark : BitVec 32)
    (ctxBelow : ctxBlock.toNat < initial.nextblock.toNat)
    (ctx : le.get Arm64ProgramFixture._ctx = some (.Vptr ctxBlock ctxOffset))
    (originalMark : CC.Mem.loadv .Mint32 initial
      (.Vptr ctxBlock (CC.Integers.Ptrofs.add ctxOffset (CC.Integers.Ptrofs.repr 8))) = some (.Vint mark))
    (saved : BitVec 64) (savedResult : le.get Arm64ProgramFixture._result = some (.Vlong saved))
    (sourceState : Reference.AArch64.State)
    (noError : read_err sourceState.machine = .None)
    (cmpFetched : fetch_inst (read_pc sourceState.machine) sourceState.machine = some Arm64ProgramEntryCmpNative.instruction.encoding)
    (branch : Reference.AArch64.Instruction) (conditionOffset : BitVec 19)
    (branchDecoded : branch.decoded = .BR (.Cond_branch_imm (Arm64ProgramEntryJccNative.fields (12#4) conditionOffset)))
    (branchFetched : fetch_inst (read_pc sourceState.machine + 4#64) sourceState.machine = some branch.encoding)
    (callOffset : BitVec 26)
    (admitted : Arm64ProgramEntryLinkReturnNative.Admission (Arm64ProgramEntryCmpBgtNative.after (native sourceState gprs flags) conditionOffset) callOffset)
    (prefixTrace : CC.Trace)
    (prefixRun : CC.Star (CC.Step2 world)
      (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [.Vptr ctxBlock ctxOffset] k initial) prefixTrace
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64MemcpyProgramEntry.next k (allocation initial).1 le m)) :
    ∃ live, ∃ lr : HeaderSourceLocal initial 4, ∃ stored after,
      Arm64ProgramEntryTerminalFree.FreeResult initial stored after ∧
      CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64ProgramFixture.f_arm64_execute_compile) [.Vptr ctxBlock ctxOffset] k initial) prefixTrace
        (.Returnstate (.Vint (Arm64ProgramEntryMemoryReturn.resultWord saved mark sourceState gprs flags vectors byte)) k after) ∧
      FrameBelow initial.nextblock initial after ∧
      Arm64ProgramEntrySourceReturnNative.Facts (native sourceState gprs flags) conditionOffset callOffset admitted live (.Vptr entry.block 0) lr.block := by
  exact Arm64ProgramEntrySourceReturnNative.execute prior frame le k hk ctxBlock ctxOffset mark ctxBelow ctx originalMark
    saved savedResult sourceState (native sourceState gprs flags) (left sourceState gprs flags) (right sourceState gprs flags)
    ((error sourceState gprs flags).trans noError) ((fetch sourceState gprs flags).trans cmpFetched)
    branch conditionOffset branchDecoded ((compare_fetch sourceState gprs flags).trans branchFetched)
    callOffset admitted prefixTrace prefixRun

end KProgFormal.ClightRefinement.Arm64ProgramEntryPostMemoryCmpView
