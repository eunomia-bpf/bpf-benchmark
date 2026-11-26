import KProgFormal.ClightRefinement.Arm64ProgramEntryLinkNative
import KProgFormal.ClightRefinement.Arm64ProgramEntryReturnNative

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryLinkReturnNative
open Arm64Producer (HeaderLocal HeaderSourceLocal TailLocal)
open Arm64ProgramEntryAllocation (world allocation)

/-- The same actual code supplies BL, RET at its true target and the decoded
continuation at callerPC+4. Source labels are related to these fetched sites;
source token64 retains its own coordinate. -/
structure Admission (s : Reference.AArch64.State) (offset : BitVec 26) where
  call : Reference.AArch64.Instruction
  decoded : call.decoded = .BR (.Uncond_branch_imm (Arm64ProgramEntryLinkNative.fields offset))
  callFetched : fetch_inst (read_pc s.machine) s.machine = some call.encoding
  calleeFetched : fetch_inst (BR.Uncond_branch_imm_inst.branch_taken_pc
    (Arm64ProgramEntryLinkNative.fields offset) (read_pc s.machine)) s.machine =
      some Arm64ProgramEntryReturnNative.instruction.encoding
  continuation : Reference.AArch64.Instruction
  continuationFetched : fetch_inst (read_pc s.machine + 4#64) s.machine = some continuation.encoding

def after (s : Reference.AArch64.State) (offset : BitVec 26) : Reference.AArch64.State :=
  Arm64ProgramEntryReturnNative.after (Arm64ProgramEntryLinkNative.after s offset)

theorem call_code (s : Reference.AArch64.State) (offset : BitVec 26) (cursor : BitVec 64) :
    fetch_inst cursor (Arm64ProgramEntryLinkNative.after s offset).machine = fetch_inst cursor s.machine := by
  simp [fetch_inst,Arm64ProgramEntryLinkNative.after,write_pc,write_gpr,w,write_base_pc,write_base_gpr]

theorem return_code (s : Reference.AArch64.State) (offset : BitVec 26) (cursor : BitVec 64) :
    fetch_inst cursor (after s offset).machine = fetch_inst cursor s.machine := by
  unfold after
  have retained : fetch_inst cursor (Arm64ProgramEntryReturnNative.after
      (Arm64ProgramEntryLinkNative.after s offset)).machine =
      fetch_inst cursor (Arm64ProgramEntryLinkNative.after s offset).machine := by
    simp [fetch_inst,Arm64ProgramEntryReturnNative.after,Arm64Nop.atCursor,write_pc,w,write_base_pc]
  exact retained.trans (call_code s offset cursor)

theorem return_fetched (s : Reference.AArch64.State) (offset : BitVec 26) (admitted : Admission s offset) :
    fetch_inst (read_pc (Arm64ProgramEntryLinkNative.after s offset).machine)
      (Arm64ProgramEntryLinkNative.after s offset).machine = some Arm64ProgramEntryReturnNative.instruction.encoding := by
  rw [Arm64ProgramEntryLinkNative.pc,call_code]
  exact admitted.calleeFetched

/-- Both real fetched native steps, with no intervening state assumption. -/
theorem steps (s : Reference.AArch64.State) (offset : BitVec 26) (admitted : Admission s offset)
    (noError : read_err s.machine = .None) :
    Reference.AArch64.step s = ⟨Arm64ProgramEntryLinkNative.after s offset,[],none⟩ ∧
    Reference.AArch64.step (Arm64ProgramEntryLinkNative.after s offset) = ⟨after s offset,[],none⟩ := by
  exact ⟨Arm64ProgramEntryLinkNative.reference_step s offset admitted.call admitted.decoded noError admitted.callFetched,
    Arm64ProgramEntryReturnNative.reference_step _ ((Arm64ProgramEntryLinkNative.error s offset).trans noError)
      (return_fetched s offset admitted)⟩

theorem pc (s : Reference.AArch64.State) (offset : BitVec 26) :
    read_pc (after s offset).machine = read_pc s.machine + 4#64 :=
  (Arm64ProgramEntryReturnNative.pc _).trans (Arm64ProgramEntryLinkNative.link s offset)

theorem link (s : Reference.AArch64.State) (offset : BitVec 26) :
    Reference.AArch64.gpr (after s offset) 30 = read_pc s.machine + 4#64 :=
  (Arm64ProgramEntryReturnNative.link _).trans (Arm64ProgramEntryLinkNative.link s offset)

/-- The actual reached native code decodes at its real return PC. -/
theorem continuation_fetched (s : Reference.AArch64.State) (offset : BitVec 26) (admitted : Admission s offset) :
    fetch_inst (read_pc (after s offset).machine) (after s offset).machine = some admitted.continuation.encoding := by
  rw [pc,return_code]
  exact admitted.continuationFetched

/-- The real source readbacks and code-admitted native LR form one finite
control-coordinate relation. It keeps source64/tag9 separate from physicalPC. -/
structure Observation (m : CC.Mem) (entry : CC.Val) (lr : CC.Block)
    (caller current : Reference.AArch64.State) (continuation : Reference.AArch64.Instruction) : Prop where
  sourceLink : Arm64EntryMemory.gpr m.nextblock m entry 30 = some (.Vlong 64,.Vint (9#32))
  sourceLocal : CC.Mem.load .Mint64 m lr 0 = some (.Vlong 64)
  nativeLink : Reference.AArch64.gpr current 30 = read_pc caller.machine + 4#64
  nativeCode : fetch_inst (Reference.AArch64.gpr current 30) current.machine = some continuation.encoding

/-- SAME original CALL68 and RET_TO84 compose to152 source steps, keeping all
three CALL stores and the true repeated LR store. Both genuine native steps
use the one admitted code, and their real continuation is the source label's
finite code coordinate, with explicit source/read/native observations. -/
theorem complete {initial seed before : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {rawR0 : BitVec 64} {n : Nat} {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64}
    {vectors : Fin 64 → BitVec 64} {cell : TailLocal initial 5} {flagValue : BitVec 8}
    (prior : Arm64ClobberResult.Packet base abi byte rawR0 n gprs flags vectors cell flagValue before)
    (lr : HeaderSourceLocal initial 4) (le : CC.TempEnv) (k : CC.Cont) (hk : CC.isCallCont k = true)
    (s : Reference.AArch64.State) (offset : BitVec 26) (admitted : Admission s offset)
    (noError : read_err s.machine = .None) :
    ∃ linked, ∃ result : Arm64ProgramEntryLinkComplete.Result prior lr linked,
      ∃ reached, ∃ effect : Arm64ProgramEntryLinkCall.Effect lr linked reached,
        InternalRun world 152
          (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryCmpLabels.takenBody
            (.Kseq Arm64ProgramEntryCmpLabels.takenAfter k) (allocation initial).1 le before)
          (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryReturnTarget.continuationBody
            (Arm64ProgramEntryReturnTarget.targetCont k) (allocation initial).1
            (Arm64ProgramEntryReturnComplete.temps (Arm64ProgramEntryLinkCall.temps le)) reached) ∧
        Reference.AArch64.step s = ⟨Arm64ProgramEntryLinkNative.after s offset,[],none⟩ ∧
        Reference.AArch64.step (Arm64ProgramEntryLinkNative.after s offset) = ⟨after s offset,[],none⟩ ∧
        read_pc (after s offset).machine = read_pc s.machine + 4#64 ∧
        Observation reached (.Vptr entry.block 0) lr.block s (after s offset) admitted.continuation ∧
        FrameBelow initial.nextblock before reached ∧
        (Arm64ProgramEntryReturnComplete.temps (Arm64ProgramEntryLinkCall.temps le)).get Arm64ProgramFixture._result =
          le.get Arm64ProgramFixture._result ∧
        (Arm64ProgramEntryReturnComplete.temps (Arm64ProgramEntryLinkCall.temps le)).get Arm64ProgramFixture._ctx =
          le.get Arm64ProgramFixture._ctx := by
  obtain ⟨linked,result,call,callNative,_,_,_,caller,_,_⟩ := Arm64ProgramEntryLinkNative.complete
    prior lr le k hk s offset admitted.call admitted.decoded noError admitted.callFetched
  obtain ⟨reached,effect,returned,returnNative,word,localRead,_,_,returnCaller,resultTemp,ctxTemp⟩ :=
    Arm64ProgramEntryReturnNative.complete result.packet lr (Arm64ProgramEntryLinkCall.temps le) k result.link
      (Arm64ProgramEntryLinkNative.after s offset) ((Arm64ProgramEntryLinkNative.error s offset).trans noError)
      (return_fetched s offset admitted)
  have nativeCode : fetch_inst (Reference.AArch64.gpr (after s offset) 30) (after s offset).machine =
      some admitted.continuation.encoding := by
    rw [link,return_code]
    exact admitted.continuationFetched
  exact ⟨linked,result,reached,effect,call.trans returned,callNative,returnNative,pc s offset,
    ⟨word,localRead,link s offset,nativeCode⟩,caller.trans returnCaller,
    resultTemp.trans (Arm64ProgramEntryLinkComplete.result_readback le),
    ctxTemp.trans (Arm64ProgramEntryLinkComplete.ctx_preserved le)⟩

end KProgFormal.ClightRefinement.Arm64ProgramEntryLinkReturnNative
