import KProgFormal.ClightRefinement.Arm64MulNative

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64Mul.NativeCall
open Arm64Producer (HeaderLocal HeaderSourceLocal)
open Arm64ProducerRegisterStorage Arm64ProducerEntryView
open Arm64ProgramEntryAllocation (world)
open Arm64ProgramEntryMulCall (arguments)

/-- The actual source call/free-return refines the fetched mature MUL step,
with both native operands derived from existing scalar cells. -/
theorem corresponds {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (header : (j : Fin 12) → HeaderSourceLocal initial j)
    (pointers : ∀ j, CC.Mem.load CC.Mptr before entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0))
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (native : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) native)
    (warm : Arm64RegisterReads.WarmEntryCache false before.nextblock before (.Vptr entry.block 0) origins.stack)
    (lhs rhs : BitVec 64)
    (lhsWord : CC.Mem.load .Mint64 before ((storage.tables false).cellBlock 1) 0 = some (.Vlong lhs))
    (lhsTag : CC.Mem.load .Mint8unsigned before ((storage.tables true).cellBlock 1) 0 = some (.Vint 0))
    (rhsWord : CC.Mem.load .Mint64 before ((storage.tables false).cellBlock 3) 0 = some (.Vlong rhs))
    (rhsTag : CC.Mem.load .Mint8unsigned before ((storage.tables true).cellBlock 3) 0 = some (.Vint 0))
    (k : CC.Cont) (valid : CC.isCallCont k = true)
    (instruction : Reference.AArch64.Instruction)
    (decoded : instruction.decoded = .DPR (.Data_processing_three_source Native.fields))
    (noError : read_err native.machine = .None)
    (fetched : fetch_inst (read_pc native.machine) native.machine = some instruction.encoding) :
    ∃ written after, ∃ finalStorage : Storage initial after entry,
      CC.Mem.load .Mint64 after ((finalStorage.tables false).cellBlock 4) 0 = some (.Vlong (lhs * rhs)) ∧
      CC.Mem.load .Mint8unsigned after ((finalStorage.tables true).cellBlock 4) 0 = some (.Vint 0) ∧
      InternalRun world 437 (.Callstate (.Internal Arm64Nop.handler) (arguments entry.block) k before)
        (.Returnstate .Vundef k after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val) before.nextblock after (.Vptr entry.block 0)
        (Reference.AArch64.step native).state ∧
      (Reference.AArch64.step native).events = [] ∧ (Reference.AArch64.step native).fault = none ∧
      FrameBelow initial.nextblock before after ∧
      CC.Mem.freeList written (CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world before).1) = some after ∧
      FrameBelow before.nextblock written after ∧
      after.contents = written.contents ∧ after.nextblock = written.nextblock ∧
      (∀ row ∈ CC.blocksOfEnv world.genv_cenv (Arm64Nop.allocation world before).1,
        ∀ ofs, row.2.1 ≤ ofs → ofs < row.2.2 →
          ∀ kind permission, CC.Mem.perm after row.1 ofs kind permission = false) ∧
      Arm64CacheLocalFrame.Kept initial before after 4 ∧
      (∀ j, CC.Mem.load CC.Mptr after entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0)) ∧
      Arm64RegisterReads.WarmEntryCache false before.nextblock after (.Vptr entry.block 0) origins.stack ∧
      (Arm64Producer.allocation initial).2.nextblock.toNat ≤ after.nextblock.toNat := by
  obtain ⟨left, right⟩ := Native.source_bits storage addresses origins native represented
    lhs rhs lhsWord lhsTag rhsWord rhsTag
  have nativeStep := Native.reference_step native instruction decoded noError fetched
  obtain ⟨written, after, finalStorage, word, tag, run, registers, frame, freed, freeFrame,
      contents, next, released, kept, finalPointers, finalWarm, finalBound⟩ :=
    Call.execute storage bound header pointers addresses origins native represented warm
      lhs rhs lhsWord lhsTag rhsWord rhsTag k valid
  refine ⟨written, after, finalStorage, word, tag, run, ?_, ?_, ?_, frame, freed, freeFrame,
    contents, next, released, kept, finalPointers, finalWarm, finalBound⟩
  · rw [nativeStep]
    exact (Arm64Registers.cursor after (.Vptr entry.block 0)
      (Arm64RegisterWrite.nativeUpdate native 4
        (Reference.AArch64.gpr native 1 * Reference.AArch64.gpr native 3) false)
      (read_pc native.machine + 4#64)).mpr (by simpa only [left, right] using registers)
  · rw [nativeStep]
  · rw [nativeStep]

/-- Arbitrary relational executions refine the same fetched native step. -/
theorem all_behaviors {initial before : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry)
    (bound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (header : (j : Fin 12) → HeaderSourceLocal initial j)
    (pointers : ∀ j, CC.Mem.load CC.Mptr before entry.block (8 * (j.val : Int)) = some (.Vptr (header j).block 0))
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (native : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) native)
    (warm : Arm64RegisterReads.WarmEntryCache false before.nextblock before (.Vptr entry.block 0) origins.stack)
    (lhs rhs : BitVec 64)
    (lhsWord : CC.Mem.load .Mint64 before ((storage.tables false).cellBlock 1) 0 = some (.Vlong lhs))
    (lhsTag : CC.Mem.load .Mint8unsigned before ((storage.tables true).cellBlock 1) 0 = some (.Vint 0))
    (rhsWord : CC.Mem.load .Mint64 before ((storage.tables false).cellBlock 3) 0 = some (.Vlong rhs))
    (rhsTag : CC.Mem.load .Mint8unsigned before ((storage.tables true).cellBlock 3) 0 = some (.Vint 0))
    (instruction : Reference.AArch64.Instruction)
    (decoded : instruction.decoded = .DPR (.Data_processing_three_source Native.fields))
    (noError : read_err native.machine = .None)
    (fetched : fetch_inst (read_pc native.machine) native.machine = some instruction.encoding) :
    ∃ after,
      Arm64Registers.Represents addresses origins (fun r => r.val) before.nextblock after (.Vptr entry.block 0)
        (Reference.AArch64.step native).state ∧
      (∀ t other, CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64Nop.handler) (arguments entry.block) .Kstop before) t other →
        t = CC.E0 ∧ ∃ remaining, InternalRun world remaining other (.Returnstate .Vundef .Kstop after)) ∧
      (∀ t other, CC.Star (CC.Step2 world)
        (.Callstate (.Internal Arm64Nop.handler) (arguments entry.block) .Kstop before) t other →
        (∀ u next, ¬ CC.Step2 world other u next) →
        t = CC.E0 ∧ other = .Returnstate .Vundef .Kstop after) ∧
      ¬ (∃ states : Nat → CC.State,
        states 0 = .Callstate (.Internal Arm64Nop.handler) (arguments entry.block) .Kstop before ∧
        ∀ j, ∃ t, CC.Step2 world (states j) t (states (j + 1))) := by
  obtain ⟨_written, after, _finalStorage, _word, _tag, run, registers, _⟩ :=
    corresponds storage bound header pointers addresses origins native represented warm lhs rhs
      lhsWord lhsTag rhsWord rhsTag .Kstop rfl instruction decoded noError fetched
  have stuck : ∀ t next, ¬ CC.Step2 world (.Returnstate .Vundef .Kstop after) t next := by
    intro t next step
    cases step
  exact ⟨after, registers,
    fun _ _ observed => run.finish_prefix stuck observed,
    fun _ _ observed endpoint => run.endpoint_unique stuck observed endpoint,
    run.no_infinite stuck⟩

end KProgFormal.ClightRefinement.Arm64Mul.NativeCall
