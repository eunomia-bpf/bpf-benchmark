import KProgFormal.ClightRefinement.Arm64ProgramEntryPostMemoryCodeAdmission

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryPostMemoryBranchSites
open Arm64Producer (HeaderLocal HeaderSourceLocal TailLocal)
open Arm64ProgramEntryAllocation (world allocation)

/-- The imported B.GT target is based on actual SUBS successor PC; the other
site is its genuine fallthrough. These are physical cursors, not source tags. -/
def cursor (s : Reference.AArch64.State) (offset : BitVec 19) (taken : Bool) : BitVec 64 :=
  if taken then BR.Cond_branch_imm_inst.branch_taken_pc (Arm64ProgramEntryJccNative.fields (12#4) offset)
    (read_pc s.machine + 4#64) else read_pc s.machine + 4#64 + 4#64

def atSite (s : Reference.AArch64.State) (offset : BitVec 19) (taken : Bool) : Reference.AArch64.State :=
  Arm64Nop.atCursor (cursor s offset taken) s

def selected (s : Reference.AArch64.State) (gprs : Fin 18 → BitVec 64) (flags : Fin 4 → BitVec 64) : Bool :=
  ConditionHolds (12#4) (Arm64ProgramEntryCmpNative.after (Arm64ProgramEntryPostMemoryCmpView.native s gprs flags)).machine

/-- Bind the two actual decoded BL/RET/continuation sites once. Their genuine
BL immediates may differ. No provider-map callback is supplied here. -/
structure Sites (s : Reference.AArch64.State) (offset : BitVec 19) where
  fallOffset : BitVec 26
  takenOffset : BitVec 26
  fallCode : Arm64ProgramEntryLinkReturnNative.Admission (atSite s offset false) fallOffset
  takenCode : Arm64ProgramEntryLinkReturnNative.Admission (atSite s offset true) takenOffset

def callOffset {s : Reference.AArch64.State} {offset : BitVec 19} (sites : Sites s offset) (taken : Bool) : BitVec 26 :=
  if taken then sites.takenOffset else sites.fallOffset

def siteAdmission {s : Reference.AArch64.State} {offset : BitVec 19} (sites : Sites s offset) (taken : Bool) :
    Arm64ProgramEntryLinkReturnNative.Admission (atSite s offset taken) (callOffset sites taken) := by
  cases taken
  · exact sites.fallCode
  · exact sites.takenCode

theorem chosen_pc (s : Reference.AArch64.State) (gprs : Fin 18 → BitVec 64) (flags : Fin 4 → BitVec 64)
    (offset : BitVec 19) :
    read_pc (Arm64ProgramEntryCmpBgtNative.after (Arm64ProgramEntryPostMemoryCmpView.native s gprs flags) offset).machine =
      read_pc (atSite s offset (selected s gprs flags)).machine := by
  rw [atSite,Arm64ProgramEntryPostMemoryCodeAdmission.cursor_pc,Arm64ProgramEntryCmpBgtNative.pc,
    Arm64ProgramEntryPostMemoryCmpView.pc]
  rfl

def chosenOffset (s : Reference.AArch64.State) (gprs : Fin 18 → BitVec 64) (flags : Fin 4 → BitVec 64)
    (offset : BitVec 19) (sites : Sites s offset) : BitVec 26 := callOffset sites (selected s gprs flags)

/-- Actual current flags choose the SAME corresponding real code certificate,
transported to the true post-CMP/B.GT state with its complete other fields. -/
def admission (s : Reference.AArch64.State) (gprs : Fin 18 → BitVec 64) (flags : Fin 4 → BitVec 64)
    (offset : BitVec 19) (sites : Sites s offset) :
    Arm64ProgramEntryLinkReturnNative.Admission
      (Arm64ProgramEntryCmpBgtNative.after (Arm64ProgramEntryPostMemoryCmpView.native s gprs flags) offset)
      (chosenOffset s gprs flags offset sites) :=
  Arm64ProgramEntryPostMemoryCodeAdmission.transport
    (atSite s offset (selected s gprs flags))
    (Arm64ProgramEntryCmpBgtNative.after (Arm64ProgramEntryPostMemoryCmpView.native s gprs flags) offset)
    (chosenOffset s gprs flags offset sites) (siteAdmission sites (selected s gprs flags))
    ((Arm64ProgramEntryPostMemoryCodeAdmission.branch_program s gprs flags offset).trans
      (Arm64ProgramEntryPostMemoryCodeAdmission.cursor_program s _).symm)
    (chosen_pc s gprs flags offset)

/-- Complete original source return and four actual native suffix steps
consume these two real code sites for the SAME current provider outputs. -/
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
    (sites : Sites sourceState conditionOffset)
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
      Arm64ProgramEntrySourceReturnNative.Facts (Arm64ProgramEntryPostMemoryCmpView.native sourceState gprs flags) conditionOffset (chosenOffset sourceState gprs flags conditionOffset sites) (admission sourceState gprs flags conditionOffset sites) live (.Vptr entry.block 0) lr.block := by
  exact Arm64ProgramEntryPostMemoryCmpView.execute prior frame le k hk ctxBlock ctxOffset mark ctxBelow ctx originalMark
    saved savedResult sourceState noError cmpFetched branch conditionOffset branchDecoded branchFetched
    (chosenOffset sourceState gprs flags conditionOffset sites) (admission sourceState gprs flags conditionOffset sites)
    prefixTrace prefixRun

end KProgFormal.ClightRefinement.Arm64ProgramEntryPostMemoryBranchSites
