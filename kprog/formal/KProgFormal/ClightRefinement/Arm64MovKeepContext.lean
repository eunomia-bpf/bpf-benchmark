import KProgFormal.ClightRefinement.Arm64MovKeepNative
import KProgFormal.ClightRefinement.Continuation

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64MovKeep

open Arm64NumericProgram
open Arm64MovImmediate

/-- The actual 203-step MOVK call in its enclosing caller, with the same stores,
real frame free and all old-block permission maps preserved. -/
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
          ∀ kind permission, CC.Mem.perm after row.1 ofs kind permission = false) := by
  obtain ⟨written, after, result, run, freed, frame, contents, next, released⟩ :=
    call_scalar_returns storage unused addresses i bits imm column narrow word tag
  refine ⟨written, after, result, ?_, ?_, freed, frame, contents, next, released⟩
  · simpa only [Continuation.state, Continuation.extend] using
      Continuation.run_extend k valid run
  · intro b old
    exact (frame b old).2.trans
      ((congrArg (fun access => CC.PMap.get b access) result.access).trans
        ((Arm64Nop.entry_frame ge before) b old).2)

/-- Actual producer allocation places every local below the reached frontier.
A call's permission frame therefore retains every local Freeable range even
though its selected word/tag contents change. -/
theorem producer_ownership_of_permissions {m before after : CC.Mem}
    (permissions : ∀ b, b.toNat < before.nextblock.toNat →
      CC.PMap.get b after.access = CC.PMap.get b before.access)
    (frontier : (Arm64Producer.allocation m).2.nextblock.toNat ≤ before.nextblock.toNat)
    (owned : ∀ id value, (Arm64Producer.allocation m).1.get id = some value →
      CC.Mem.rangePerm before value.1 0 (CC.sizeof ge.genv_cenv value.2) .Cur .Freeable = true) :
    ∀ id value, (Arm64Producer.allocation m).1.get id = some value →
      CC.Mem.rangePerm after value.1 0 (CC.sizeof ge.genv_cenv value.2) .Cur .Freeable = true := by
  intro id value binding
  have allocated := ((allocated_local_storage
    (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (Arm64Producer.allocation m)).symm)).1 id value binding).2.1
  have old : value.1.toNat < before.nextblock.toNat := Nat.lt_of_lt_of_le allocated frontier
  exact (CC.Mem.rangePerm_congr (m1 := after) (m2 := before)
    (fun ofs => by simp only [CC.Mem.perm, permissions value.1 old])).trans (owned id value binding)

/-- The complete actual call preserves producer ownership under the real caller.
Both pre-call ownership and the allocation frontier can be supplied directly
by Numeric initialized_storage's reached boundary and nextblock facts. -/
theorem call_scalar_owns_locals {m before : CC.Mem} {entry : Arm64Producer.HeaderLocal m}
    (storage : Arm64ProducerRegisterStorage.Storage m before entry)
    (unused : Arm64Nop.IgnoredArguments) (addresses : Arm64Registers.PointerOrigins)
    (i : Fin 31) (bits : BitVec 64) (imm : BitVec 16) (column : Fin 4) (narrow : Bool)
    (word : CC.Mem.load .Mint64 before ((storage.tables false).cellBlock i) 0 = some (.Vlong bits))
    (tag : CC.Mem.load .Mint8unsigned before ((storage.tables true).cellBlock i) 0 = some (.Vint 0))
    (k : CC.Cont) (valid : CC.isCallCont k = true)
    (frontier : (Arm64Producer.allocation m).2.nextblock.toNat ≤ before.nextblock.toNat)
    (owned : ∀ id value, (Arm64Producer.allocation m).1.get id = some value →
      CC.Mem.rangePerm before value.1 0 (CC.sizeof ge.genv_cenv value.2) .Cur .Freeable = true) :
    ∃ after, InternalRun ge 203
        (.Callstate (.Internal Arm64Nop.handler)
          (Dispatch.Keep.arguments (operands unused entry.block (BitVec.ofNat 64 i.val) imm column) narrow) k before)
        (.Returnstate .Vundef k after) ∧
      (∀ b, b.toNat < before.nextblock.toNat →
        CC.PMap.get b after.access = CC.PMap.get b before.access) ∧
      ∀ id value, (Arm64Producer.allocation m).1.get id = some value →
        CC.Mem.rangePerm after value.1 0 (CC.sizeof ge.genv_cenv value.2) .Cur .Freeable = true := by
  obtain ⟨written, after, result, run, permissions, freed, frame, contents, next, released⟩ :=
    call_scalar_in_context storage unused addresses i bits imm column narrow word tag k valid
  exact ⟨after, run, permissions, producer_ownership_of_permissions permissions frontier owned⟩

namespace Native

/-- The same contextual MOVK call refines the fetched/decoded mature checked step
and preserves caller permissions. Determinism identifies the existing witnesses;
no instruction or initialization is executed twice in the resulting certificate. -/
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
    (decoded : instruction.decoded = .DPI (.Move_wide_imm (fields i imm column narrow)))
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
      (Reference.AArch64.step s).events = [] ∧ (Reference.AArch64.step s).fault = none := by
  obtain ⟨written, after, result, run, permissions, freed, frame, contents, next, released⟩ :=
    call_scalar_in_context storage unused addresses i bits imm column narrow word tag .Kstop rfl
  obtain ⟨nativeAfter, nativeRun, rep, events, fault⟩ :=
    call_corresponds storage unused addresses origins s instruction i bits imm column narrow
      word tag represented legal decoded noError fetched
  have ending := (run.endpoint_unique (return_stuck .Vundef after) nativeRun.sound
    (return_stuck .Vundef nativeAfter)).2
  have memories : nativeAfter = after := congrArg
    (fun state => match state with | .Returnstate _ _ memory => memory | _ => before) ending
  rw [memories] at rep
  refine ⟨after, ?_, rep, permissions, events, fault⟩
  simpa only [Continuation.state, Continuation.extend] using
    Continuation.run_extend k valid run

end Native
end KProgFormal.ClightRefinement.Arm64MovKeep
