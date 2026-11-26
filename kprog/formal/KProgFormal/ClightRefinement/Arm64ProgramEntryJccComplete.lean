import KProgFormal.ClightRefinement.Arm64ProgramEntryJccExit
import KProgFormal.ClightRefinement.Arm64ClobberNativeFlags

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryJccComplete

open Arm64ProgramEntryAllocation (world allocation)
open Arm64Producer (HeaderLocal TailLocal)

def temps (le : CC.TempEnv) (before selected : BitVec 64) (mark : BitVec 32)
    (s : Reference.AArch64.State) : CC.TempEnv :=
  Arm64ProgramEntryJccExit.temps
    (Arm64ProgramEntryJccPrefix.selectorTemps (Arm64ProgramEntryAfterMemcpy.temps le before selected))
    (before ^^^ selected) mark s

theorem result_readback (le : CC.TempEnv) (before selected : BitVec 64) (mark : BitVec 32)
    (s : Reference.AArch64.State) :
    (temps le before selected mark s).get Arm64ProgramFixture._result =
      some (.Vlong (Arm64ProgramEntryJccExit.result (before ^^^ selected) mark s)) := by
  unfold temps Arm64ProgramEntryJccExit.temps Arm64ProgramEntryJccExit.result
  split <;> simp +decide [Arm64ProgramEntryJcc.conditionTemps,Arm64ProgramEntryJcc.markTemps,
    Arm64ProgramEntryJccPrefix.selectorTemps,Arm64ProgramEntryAfterMemcpy.temps,CC.PTree.gss,CC.PTree.gso]

theorem ctx_preserved (le : CC.TempEnv) (before selected : BitVec 64) (mark : BitVec 32)
    (s : Reference.AArch64.State) :
    (temps le before selected mark s).get Arm64ProgramFixture._ctx = le.get Arm64ProgramFixture._ctx := by
  unfold temps Arm64ProgramEntryJccExit.temps
  split <;> simp +decide [Arm64ProgramEntryJcc.conditionTemps,Arm64ProgramEntryJcc.markTemps,
    Arm64ProgramEntryJccPrefix.selectorTemps,Arm64ProgramEntryAfterMemcpy.temps,CC.PTree.gso]

/-- One completed memcpy packet supplies V31.hi and the four current NZCV
values. The original caller frame supplies the same context mark. The actual
read/XOR, JCC selector, full condition call/return and both original goto
routes reach the original next body on the same heap. -/
theorem execute {initial seed m : CC.Mem} {entry : HeaderLocal initial}
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
    (s : Reference.AArch64.State) :
    ∃ count, InternalRun world count
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64MemcpyProgramEntry.next k
        (allocation initial).1 le m)
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryJccLabels.takenBody
        (.Kseq Arm64ProgramEntryJccLabels.takenAfter k) (allocation initial).1
        (temps le before (values 63) mark (Arm64ClobberNativeFlags.native s flags)) m) := by
  have read : CC.Mem.loadv .Mint32 m
      (.Vptr ctxBlock (CC.Integers.Ptrofs.add ctxOffset (CC.Integers.Ptrofs.repr 8))) = some (.Vint mark) := by
    unfold CC.Mem.loadv at originalMark ⊢
    exact (frame.load .Mint32 ctxBlock _ ctxBelow).trans originalMark
  have currentCtx : (Arm64ProgramEntryAfterMemcpy.temps le before (values 63)).get
      Arm64ProgramFixture._ctx = some (.Vptr ctxBlock ctxOffset) := by
    simpa +decide [Arm64ProgramEntryAfterMemcpy.temps,CC.PTree.gso] using ctx
  have currentResult : (Arm64ProgramEntryJccPrefix.selectorTemps
      (Arm64ProgramEntryAfterMemcpy.temps le before (values 63))).get Arm64ProgramFixture._result =
        some (.Vlong (before ^^^ (values 63))) := by
    simp +decide [Arm64ProgramEntryJccPrefix.selectorTemps,Arm64ProgramEntryAfterMemcpy.temps,CC.PTree.gss,CC.PTree.gso]
  obtain ⟨readCount,reads⟩ := Arm64ProgramEntryAfterMemcpy.execute packet le k before prior
  obtain ⟨prefixCount,prefixRun⟩ := Arm64ProgramEntryJccPrefix.execute
    (Arm64ProgramEntryAfterMemcpy.temps le before (values 63)) m k ctxBlock ctxOffset mark currentCtx read
  obtain ⟨callCount,call⟩ := Arm64ProgramEntryJcc.invoke packet.memory.storage
    (Arm64ClobberNativeFlags.native s flags) (Arm64ClobberNativeFlags.represented packet s)
    (Arm64ProgramEntryJccPrefix.selectorTemps (Arm64ProgramEntryAfterMemcpy.temps le before (values 63)))
    (Arm64ProgramEntryJccPrefix.conditionCont k) mark
  obtain ⟨exitCount,exit⟩ := Arm64ProgramEntryJccExit.execute
    (Arm64ProgramEntryJccPrefix.selectorTemps (Arm64ProgramEntryAfterMemcpy.temps le before (values 63))) m k hk
    (before ^^^ (values 63)) mark (Arm64ClobberNativeFlags.native s flags) currentResult
  exact ⟨_,((reads.trans prefixRun).trans call).trans exit⟩

end KProgFormal.ClightRefinement.Arm64ProgramEntryJccComplete
