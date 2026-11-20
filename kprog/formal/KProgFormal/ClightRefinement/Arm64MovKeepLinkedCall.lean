import KProgFormal.ClightRefinement.Arm64MovKeepLinked
import KProgFormal.ClightRefinement.Arm64MovKeepContext

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64MovKeep.Linked

open Arm64ProgramEntryLinked
open Arm64MovImmediate

/-- The actual merged program resolves the width helper to its original body. -/
theorem width_binding :
    CC.Genv.findSymbol ge.genv_genv Arm64Program._arm64_width_effective = some (CC.Positive.ofNat 97) ∧
    CC.Genv.findFunctPtr ge.genv_genv (CC.Positive.ofNat 97) =
      some (.Internal Arm64Program.f_arm64_width_effective) := by
  constructor <;> run_tac sourceEquality

def bindings : CallBindings ge where
  widthBlock := CC.Positive.ofNat 97
  readerBlock := CC.Positive.ofNat 66
  writerBlock := CC.Positive.ofNat 107
  width := width_binding
  reader := reader_binding
  writer := writer_binding
  readerLayout := reader_layout
  writerLayout := writer_layout

/-- Instance in the actual fixture/handler link, retaining the original frontier and resources. -/
theorem call_scalar_returns {m before : CC.Mem} {entry : Arm64Producer.HeaderLocal m}
    (storage : Arm64ProducerRegisterStorage.Storage m before entry)
    (unused : Arm64Nop.IgnoredArguments) (addresses : Arm64Registers.PointerOrigins)
    (i : Fin 31) (bits : BitVec 64) (imm : BitVec 16) (column : Fin 4) (narrow : Bool)
    (word : CC.Mem.load .Mint64 before ((storage.tables false).cellBlock i) 0 = some (.Vlong bits))
    (tag : CC.Mem.load .Mint8unsigned before ((storage.tables true).cellBlock i) 0 = some (.Vint 0)) :
    ∃ written after,
      Arm64RegisterWrite.Result (storage.frame (Arm64Nop.entry_frame ge before))
        i (merge bits imm column) narrow written ∧
      InternalRun ge 203
        (.Callstate (.Internal Arm64Nop.handler)
          (Dispatch.Keep.arguments (operands unused entry.block (BitVec.ofNat 64 i.val) imm column) narrow) .Kstop before)
        (.Returnstate .Vundef .Kstop after) ∧
      CC.Mem.freeList written (CC.blocksOfEnv ge.genv_cenv (Arm64Nop.allocation ge before).1) = some after ∧
      FrameBelow before.nextblock written after ∧
      after.contents = written.contents ∧ after.nextblock = written.nextblock ∧
      (∀ row ∈ CC.blocksOfEnv ge.genv_cenv (Arm64Nop.allocation ge before).1,
        ∀ ofs, row.2.1 ≤ ofs → ofs < row.2.2 →
          ∀ kind permission, CC.Mem.perm after row.1 ofs kind permission = false) :=
  call_scalar_returns_bound ge bindings storage unused addresses i bits imm column narrow word tag

/-- Instance in the actual fixture/handler link, retaining the original frontier and resources. -/
theorem call_scalar_represents {m before : CC.Mem} {entry : Arm64Producer.HeaderLocal m}
    (storage : Arm64ProducerRegisterStorage.Storage m before entry)
    (unused : Arm64Nop.IgnoredArguments) (addresses : Arm64Registers.PointerOrigins)
    (origins : Reference.Provenance.AArch64.Origins) (s : Reference.AArch64.State)
    (i : Fin 31) (bits : BitVec 64) (imm : BitVec 16) (column : Fin 4) (narrow : Bool)
    (word : CC.Mem.load .Mint64 before ((storage.tables false).cellBlock i) 0 = some (.Vlong bits))
    (tag : CC.Mem.load .Mint8unsigned before ((storage.tables true).cellBlock i) 0 = some (.Vint 0))
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s) :
    ∃ after, InternalRun ge 203
      (.Callstate (.Internal Arm64Nop.handler)
        (Dispatch.Keep.arguments (operands unused entry.block (BitVec.ofNat 64 i.val) imm column) narrow) .Kstop before)
      (.Returnstate .Vundef .Kstop after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val)
        before.nextblock after (.Vptr entry.block 0)
          (Arm64RegisterWrite.nativeUpdate s i (merge (Reference.AArch64.gpr s i) imm column) narrow) :=
  call_scalar_represents_bound ge bindings storage unused addresses origins s i bits imm column narrow word tag represented

/-- Instance in the actual fixture/handler link, retaining the original frontier and resources. -/
theorem call_scalar_all_behaviors {m before : CC.Mem} {entry : Arm64Producer.HeaderLocal m}
    (storage : Arm64ProducerRegisterStorage.Storage m before entry)
    (unused : Arm64Nop.IgnoredArguments) (i : Fin 31) (bits : BitVec 64)
    (imm : BitVec 16) (column : Fin 4) (narrow : Bool)
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (word : CC.Mem.load .Mint64 before ((storage.tables false).cellBlock i) 0 = some (.Vlong bits))
    (tag : CC.Mem.load .Mint8unsigned before ((storage.tables true).cellBlock i) 0 = some (.Vint 0))
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s) :
    ∃ after, InternalRun ge 203
      (.Callstate (.Internal Arm64Nop.handler)
        (Dispatch.Keep.arguments (operands unused entry.block (BitVec.ofNat 64 i.val) imm column) narrow) .Kstop before)
      (.Returnstate .Vundef .Kstop after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val)
        before.nextblock after (.Vptr entry.block 0)
          (Arm64RegisterWrite.nativeUpdate s i (merge (Reference.AArch64.gpr s i) imm column) narrow) ∧
      (∀ t other, CC.Star (CC.Step2 ge)
        (.Callstate (.Internal Arm64Nop.handler)
          (Dispatch.Keep.arguments (operands unused entry.block (BitVec.ofNat 64 i.val) imm column) narrow) .Kstop before) t other →
        t = CC.E0 ∧ ∃ remaining, InternalRun ge remaining other (.Returnstate .Vundef .Kstop after)) ∧
      (∀ t other, CC.Star (CC.Step2 ge)
        (.Callstate (.Internal Arm64Nop.handler)
          (Dispatch.Keep.arguments (operands unused entry.block (BitVec.ofNat 64 i.val) imm column) narrow) .Kstop before) t other →
        (∀ u next, ¬ CC.Step2 ge other u next) →
        t = CC.E0 ∧ other = .Returnstate .Vundef .Kstop after) ∧
      ¬ (∃ states : Nat → CC.State,
        states 0 = .Callstate (.Internal Arm64Nop.handler)
          (Dispatch.Keep.arguments (operands unused entry.block (BitVec.ofNat 64 i.val) imm column) narrow) .Kstop before ∧
        ∀ i, ∃ t, CC.Step2 ge (states i) t (states (i + 1))) :=
  call_scalar_all_behaviors_bound ge bindings storage unused i bits imm column narrow addresses origins s word tag represented

/-- Instance in the actual fixture/handler link, retaining the original frontier and resources. -/
theorem call_corresponds {m before : CC.Mem} {entry : Arm64Producer.HeaderLocal m}
    (storage : Arm64ProducerRegisterStorage.Storage m before entry)
    (unused : Arm64Nop.IgnoredArguments) (addresses : Arm64Registers.PointerOrigins)
    (origins : Reference.Provenance.AArch64.Origins) (s : Reference.AArch64.State)
    (instruction : Reference.AArch64.Instruction)
    (i : Fin 31) (bits : BitVec 64) (imm : BitVec 16) (column : Fin 4) (narrow : Bool)
    (word : CC.Mem.load .Mint64 before ((storage.tables false).cellBlock i) 0 = some (.Vlong bits))
    (tag : CC.Mem.load .Mint8unsigned before ((storage.tables true).cellBlock i) 0 = some (.Vint 0))
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s)
    (valid : narrow = true → column.val < 2)
    (decoded : instruction.decoded = .DPI (.Move_wide_imm (Native.fields i imm column narrow)))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    ∃ after, InternalRun ge 203
      (.Callstate (.Internal Arm64Nop.handler)
        (Arm64MovImmediate.Dispatch.Keep.arguments
          (operands unused entry.block (BitVec.ofNat 64 i.val) imm column) narrow) .Kstop before)
      (.Returnstate .Vundef .Kstop after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val)
        before.nextblock after (.Vptr entry.block 0) (Reference.AArch64.step s).state ∧
      (Reference.AArch64.step s).events = [] ∧ (Reference.AArch64.step s).fault = none :=
  Native.call_corresponds_bound ge bindings storage unused addresses origins s instruction i bits imm column narrow word tag represented valid decoded noError fetched

/-- Instance in the actual fixture/handler link, retaining the original frontier and resources. -/
theorem call_scalar_in_context {m before : CC.Mem} {entry : Arm64Producer.HeaderLocal m}
    (storage : Arm64ProducerRegisterStorage.Storage m before entry)
    (unused : Arm64Nop.IgnoredArguments) (addresses : Arm64Registers.PointerOrigins)
    (i : Fin 31) (bits : BitVec 64) (imm : BitVec 16) (column : Fin 4) (narrow : Bool)
    (word : CC.Mem.load .Mint64 before ((storage.tables false).cellBlock i) 0 = some (.Vlong bits))
    (tag : CC.Mem.load .Mint8unsigned before ((storage.tables true).cellBlock i) 0 = some (.Vint 0))
    (k : CC.Cont) (valid : CC.isCallCont k = true) :
    ∃ written after,
      Arm64RegisterWrite.Result (storage.frame (Arm64Nop.entry_frame ge before))
        i (merge bits imm column) narrow written ∧
      InternalRun ge 203
        (.Callstate (.Internal Arm64Nop.handler)
          (Dispatch.Keep.arguments (operands unused entry.block (BitVec.ofNat 64 i.val) imm column) narrow) k before)
        (.Returnstate .Vundef k after) ∧
      (∀ b, b.toNat < before.nextblock.toNat →
        CC.PMap.get b after.access = CC.PMap.get b before.access) ∧
      CC.Mem.freeList written (CC.blocksOfEnv ge.genv_cenv (Arm64Nop.allocation ge before).1) = some after ∧
      FrameBelow before.nextblock written after ∧
      after.contents = written.contents ∧ after.nextblock = written.nextblock ∧
      (∀ row ∈ CC.blocksOfEnv ge.genv_cenv (Arm64Nop.allocation ge before).1,
        ∀ ofs, row.2.1 ≤ ofs → ofs < row.2.2 →
          ∀ kind permission, CC.Mem.perm after row.1 ofs kind permission = false) :=
  call_scalar_in_context_bound ge bindings storage unused addresses i bits imm column narrow word tag k valid

/-- Instance in the actual fixture/handler link, retaining the original frontier and resources. -/
theorem call_corresponds_in_context {m before : CC.Mem} {entry : Arm64Producer.HeaderLocal m}
    (storage : Arm64ProducerRegisterStorage.Storage m before entry)
    (unused : Arm64Nop.IgnoredArguments) (addresses : Arm64Registers.PointerOrigins)
    (origins : Reference.Provenance.AArch64.Origins) (s : Reference.AArch64.State)
    (instruction : Reference.AArch64.Instruction)
    (i : Fin 31) (bits : BitVec 64) (imm : BitVec 16) (column : Fin 4) (narrow : Bool)
    (word : CC.Mem.load .Mint64 before ((storage.tables false).cellBlock i) 0 = some (.Vlong bits))
    (tag : CC.Mem.load .Mint8unsigned before ((storage.tables true).cellBlock i) 0 = some (.Vint 0))
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s)
    (legal : narrow = true → column.val < 2)
    (decoded : instruction.decoded = .DPI (.Move_wide_imm (Native.fields i imm column narrow)))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding)
    (k : CC.Cont) (valid : CC.isCallCont k = true) :
    ∃ after, InternalRun ge 203
      (.Callstate (.Internal Arm64Nop.handler)
        (Dispatch.Keep.arguments (operands unused entry.block (BitVec.ofNat 64 i.val) imm column) narrow) k before)
      (.Returnstate .Vundef k after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val)
        before.nextblock after (.Vptr entry.block 0) (Reference.AArch64.step s).state ∧
      (∀ b, b.toNat < before.nextblock.toNat →
        CC.PMap.get b after.access = CC.PMap.get b before.access) ∧
      (Reference.AArch64.step s).events = [] ∧ (Reference.AArch64.step s).fault = none :=
  Native.call_corresponds_in_context_bound ge bindings storage unused addresses origins s instruction i bits imm column narrow word tag represented legal decoded noError fetched k valid

/-- All outcomes of the closed call share the same native-refining return.
The arbitrary-caller theorem describes its finite callee segment separately. -/
theorem call_corresponds_all_behaviors {m before : CC.Mem} {entry : Arm64Producer.HeaderLocal m}
    (storage : Arm64ProducerRegisterStorage.Storage m before entry)
    (unused : Arm64Nop.IgnoredArguments) (addresses : Arm64Registers.PointerOrigins)
    (origins : Reference.Provenance.AArch64.Origins) (s : Reference.AArch64.State)
    (instruction : Reference.AArch64.Instruction)
    (i : Fin 31) (bits : BitVec 64) (imm : BitVec 16) (column : Fin 4) (narrow : Bool)
    (word : CC.Mem.load .Mint64 before ((storage.tables false).cellBlock i) 0 = some (.Vlong bits))
    (tag : CC.Mem.load .Mint8unsigned before ((storage.tables true).cellBlock i) 0 = some (.Vint 0))
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s)
    (valid : narrow = true → column.val < 2)
    (decoded : instruction.decoded = .DPI (.Move_wide_imm (Native.fields i imm column narrow)))
    (noError : read_err s.machine = .None)
    (fetched : fetch_inst (read_pc s.machine) s.machine = some instruction.encoding) :
    ∃ after, InternalRun ge 203
      (.Callstate (.Internal Arm64Nop.handler)
        (Arm64MovImmediate.Dispatch.Keep.arguments
          (operands unused entry.block (BitVec.ofNat 64 i.val) imm column) narrow) .Kstop before)
      (.Returnstate .Vundef .Kstop after) ∧
      Arm64Registers.Represents addresses origins (fun r => r.val)
        before.nextblock after (.Vptr entry.block 0) (Reference.AArch64.step s).state ∧
      (Reference.AArch64.step s).events = [] ∧ (Reference.AArch64.step s).fault = none ∧
      (∀ t other, CC.Star (CC.Step2 ge)
        (.Callstate (.Internal Arm64Nop.handler)
          (Dispatch.Keep.arguments (operands unused entry.block (BitVec.ofNat 64 i.val) imm column) narrow)
            .Kstop before) t other →
        t = CC.E0 ∧ ∃ remaining, InternalRun ge remaining other (.Returnstate .Vundef .Kstop after)) ∧
      (∀ t other, CC.Star (CC.Step2 ge)
        (.Callstate (.Internal Arm64Nop.handler)
          (Dispatch.Keep.arguments (operands unused entry.block (BitVec.ofNat 64 i.val) imm column) narrow)
            .Kstop before) t other →
        (∀ u next, ¬ CC.Step2 ge other u next) →
        t = CC.E0 ∧ other = .Returnstate .Vundef .Kstop after) ∧
      ¬ (∃ states : Nat → CC.State,
        states 0 = .Callstate (.Internal Arm64Nop.handler)
          (Dispatch.Keep.arguments (operands unused entry.block (BitVec.ofNat 64 i.val) imm column) narrow)
            .Kstop before ∧
        ∀ j, ∃ t, CC.Step2 ge (states j) t (states (j + 1))) := by
  obtain ⟨after, run, rep, events, fault⟩ := call_corresponds storage unused addresses origins s instruction
    i bits imm column narrow word tag represented valid decoded noError fetched
  have stuck : ∀ t next, ¬ CC.Step2 ge (.Returnstate .Vundef .Kstop after) t next := by
    intro t next step
    cases step
  exact ⟨after, run, rep, events, fault,
    fun _ _ observed => run.finish_prefix stuck observed,
    fun _ _ observed endpoint => run.endpoint_unique stuck observed endpoint,
    run.no_infinite stuck⟩

end KProgFormal.ClightRefinement.Arm64MovKeep.Linked
