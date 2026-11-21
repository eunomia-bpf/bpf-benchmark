import KProgFormal.ClightRefinement.Arm64AddImmediateCall
import KProgFormal.ClightRefinement.Arm64AddImmediateNative

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64AddImmediate.Call

open Arm64Producer (HeaderLocal HeaderSourceLocal)
open Arm64ProducerRegisterStorage Arm64ProducerEntryView
open Arm64ProgramEntryLinked (ge)

/-- The complete actual generic call refines the fetched mature ADD-from-SP
step. Source raw/tag storage, real release, cache and caller facts survive. -/
theorem corresponds {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (header : (j : Fin 12) → HeaderSourceLocal initial j)
    (pointers : ∀ j, CC.Mem.load CC.Mptr before entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0))
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s)
    (warm : Arm64RegisterReads.WarmEntryCache false before.nextblock before (.Vptr entry.block 0) origins.stack)
    (i : Fin 31) (imm : BitVec 12) (shifted : Bool) (src2 src3 : CC.Val)
    (k : CC.Cont) (valid : CC.isCallCont k = true)
    (instruction : Reference.AArch64.Instruction)
    (decoded : instruction.decoded = .DPI (.Add_sub_imm (Native.fields i imm shifted)))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    ∃ written after, ∃ finalStorage : Storage initial after entry,
      CC.Mem.load .Mint64 after ((finalStorage.tables false).cellBlock i) 0 =
        some (.Vlong (storage.spValue + Native.operand imm shifted)) ∧
      CC.Mem.load .Mint8unsigned after ((finalStorage.tables true).cellBlock i) 0 = some (.Vint (4#32)) ∧
      InternalRun ge 333
        (.Callstate (.Internal Arm64Nop.handler) (arguments entry.block i (Native.operand imm shifted) src2 src3) k before)
        (.Returnstate .Vundef k after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) before.nextblock after (.Vptr entry.block 0)
        (Reference.AArch64.step s).state ∧
      (Reference.AArch64.step s).events = [] ∧ (Reference.AArch64.step s).fault = none ∧
      FrameBelow initial.nextblock before after ∧
      CC.Mem.freeList written (CC.blocksOfEnv ge.genv_cenv (Arm64Nop.allocation ge before).1) = some after ∧
      FrameBelow before.nextblock written after ∧
      after.contents = written.contents ∧ after.nextblock = written.nextblock ∧
      (∀ row ∈ CC.blocksOfEnv ge.genv_cenv (Arm64Nop.allocation ge before).1,
        ∀ ofs, row.2.1 ≤ ofs → ofs < row.2.2 →
          ∀ kind permission, CC.Mem.perm after row.1 ofs kind permission = false) ∧
      Arm64CacheLocalFrame.Kept initial before after i ∧
      (∀ j, CC.Mem.load CC.Mptr after entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0)) ∧
      Arm64RegisterReads.WarmEntryCache false before.nextblock after (.Vptr entry.block 0) origins.stack ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat := by
  have sourceSP := Arm64AddOperandReads.Linked.sp_native storage addresses origins s represented
  have native := Native.reference_step s instruction i imm shifted decoded noError fetched
  have update := Native.pointer_update s i imm shifted origins storage.spValue sourceSP
  obtain ⟨written, after, finalStorage, word, tag, run, registers, frame, freed, freeFrame,
      contents, next, released, kept, finalPointers, finalWarm, finalBound⟩ :=
    execute storage bound header pointers addresses origins s represented warm i (Native.operand imm shifted) src2 src3 k valid
  refine ⟨written, after, finalStorage, word, tag, run, ?_, ?_, ?_, frame, freed, freeFrame,
    contents, next, released, kept, finalPointers, finalWarm, finalBound⟩
  · rw [native]
    exact (Arm64Registers.cursor after (.Vptr entry.block 0)
      (Arm64RegisterWrite.nativeUpdate s i (Reference.AArch64.sp s + Native.operand imm shifted) false)
      (read_pc s.machine + 4#64)).mpr (by simpa only [update] using registers)
  · rw [native]
  · rw [native]

/-- Every arbitrary relational execution is a silent prefix of the same
complete fetched-step-refining return. No trace-silence or external-call
determinism premise is imposed on observed executions. -/
theorem all_behaviors {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (header : (j : Fin 12) → HeaderSourceLocal initial j)
    (pointers : ∀ j, CC.Mem.load CC.Mptr before entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0))
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s)
    (warm : Arm64RegisterReads.WarmEntryCache false before.nextblock before (.Vptr entry.block 0) origins.stack)
    (i : Fin 31) (imm : BitVec 12) (shifted : Bool) (src2 src3 : CC.Val)
    (instruction : Reference.AArch64.Instruction)
    (decoded : instruction.decoded = .DPI (.Add_sub_imm (Native.fields i imm shifted)))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    ∃ after, ∃ finalStorage : Storage initial after entry,
      CC.Mem.load .Mint64 after ((finalStorage.tables false).cellBlock i) 0 =
        some (.Vlong (storage.spValue + Native.operand imm shifted)) ∧
      CC.Mem.load .Mint8unsigned after ((finalStorage.tables true).cellBlock i) 0 = some (.Vint (4#32)) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) before.nextblock after (.Vptr entry.block 0)
        (Reference.AArch64.step s).state ∧
      FrameBelow initial.nextblock before after ∧
      Arm64RegisterReads.WarmEntryCache false before.nextblock after (.Vptr entry.block 0) origins.stack ∧
      (∀ t other, CC.Star (CC.Step2 ge)
        (.Callstate (.Internal Arm64Nop.handler) (arguments entry.block i (Native.operand imm shifted) src2 src3) .Kstop before) t other →
        t = CC.E0 ∧ ∃ remaining, InternalRun ge remaining other (.Returnstate .Vundef .Kstop after)) ∧
      (∀ t other, CC.Star (CC.Step2 ge)
        (.Callstate (.Internal Arm64Nop.handler) (arguments entry.block i (Native.operand imm shifted) src2 src3) .Kstop before) t other →
        (∀ u next, ¬ CC.Step2 ge other u next) →
        t = CC.E0 ∧ other = .Returnstate .Vundef .Kstop after) ∧
      ¬ (∃ states : Nat → CC.State,
        states 0 = .Callstate (.Internal Arm64Nop.handler)
          (arguments entry.block i (Native.operand imm shifted) src2 src3) .Kstop before ∧
        ∀ j, ∃ t, CC.Step2 ge (states j) t (states (j+1))) := by
  obtain ⟨_written, after, finalStorage, word, tag, run, registers, _events, _fault, frame,
      _freed, _freeFrame, _contents, _next, _released, _kept, _pointers, finalWarm, _finalBound⟩ :=
    corresponds storage bound header pointers addresses origins s represented warm i imm shifted src2 src3
      .Kstop rfl instruction decoded noError fetched
  have stuck : ∀ t next, ¬ CC.Step2 ge (.Returnstate .Vundef .Kstop after) t next := by
    intro t next step
    cases step
  exact ⟨after, finalStorage, word, tag, registers, frame, finalWarm,
    fun _ _ observed => run.finish_prefix stuck observed,
    fun _ _ observed endpoint => run.endpoint_unique stuck observed endpoint,
    run.no_infinite stuck⟩

end KProgFormal.ClightRefinement.Arm64AddImmediate.Call
