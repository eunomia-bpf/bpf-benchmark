import KProgFormal.ClightRefinement.Arm64ProgramEntryLinkWritten
import KProgFormal.ClightRefinement.Arm64ProgramEntryLinkLabels

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryLinkComplete
open Arm64Producer (HeaderLocal HeaderSourceLocal TailLocal)
open Arm64ProgramEntryAllocation (world allocation)

/-- The SAME real LR store and subsequent real X30 word/tag stores. -/
structure Result {initial seed before : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {rawR0 : BitVec 64} {n : Nat} {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64}
    {vectors : Fin 64 → BitVec 64} {cell : TailLocal initial 5} {flagValue : BitVec 8}
    (prior : Arm64ClobberResult.Packet base abi byte rawR0 n gprs flags vectors cell flagValue before)
    (lr : HeaderSourceLocal initial 4) (after : CC.Mem) where
  lrWritten : CC.Mem
  lrEffect : Arm64ProgramEntryLinkCall.Effect lr before lrWritten
  writerEffect : Arm64PointerWrite.Result (Arm64ProgramEntryLinkFrame.packet lrEffect prior).memory.storage 30 64 (9#8) after

section Result
variable {initial seed before after : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {rawR0 : BitVec 64} {n : Nat} {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64}
    {vectors : Fin 64 → BitVec 64} {cell : TailLocal initial 5} {flagValue : BitVec 8}
    {prior : Arm64ClobberResult.Packet base abi byte rawR0 n gprs flags vectors cell flagValue before}
    {lr : HeaderSourceLocal initial 4} (result : Result prior lr after)
include result

def Result.packet : Arm64ClobberResult.Packet base abi byte rawR0 n gprs flags vectors cell flagValue after :=
  Arm64ProgramEntryLinkWritten.packet (Arm64ProgramEntryLinkFrame.packet result.lrEffect prior) result.writerEffect

theorem Result.link : Arm64EntryMemory.gpr after.nextblock after (.Vptr entry.block 0) 30 =
    some (.Vlong 64,.Vint (9#32)) := Arm64ProgramEntryLinkWritten.link result.writerEffect

theorem Result.lr_readback : CC.Mem.load .Mint64 after lr.block 0 = some (.Vlong 64) :=
  (Arm64ProgramEntryLinkWritten.lr result.writerEffect lr).trans (CC.Mem.load_store_same result.lrEffect.stored)

theorem Result.caller : FrameBelow initial.nextblock before after := result.lrEffect.caller.trans result.writerEffect.caller

end Result

theorem result_readback (le : CC.TempEnv) :
    (Arm64ProgramEntryLinkCall.temps le).get Arm64ProgramFixture._result = le.get Arm64ProgramFixture._result := by
  exact CC.PTree.gso _ _ _ _ (by decide +kernel)

theorem ctx_preserved (le : CC.TempEnv) :
    (Arm64ProgramEntryLinkCall.temps le).get Arm64ProgramFixture._ctx = le.get Arm64ProgramFixture._ctx := by
  exact CC.PTree.gso _ _ _ _ (by decide +kernel)

/-- Complete original CALL: real LR store/load, all original pointer-writer
entry/body/return/caller transitions and genuine goto into callee. -/
theorem execute {initial seed before : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {rawR0 : BitVec 64} {n : Nat} {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64}
    {vectors : Fin 64 → BitVec 64} {cell : TailLocal initial 5} {flagValue : BitVec 8}
    (prior : Arm64ClobberResult.Packet base abi byte rawR0 n gprs flags vectors cell flagValue before)
    (lr : HeaderSourceLocal initial 4) (le : CC.TempEnv) (k : CC.Cont) (hk : CC.isCallCont k = true) :
    ∃ after, ∃ result : Result prior lr after, InternalRun world 68
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryCmpLabels.takenBody
        (.Kseq Arm64ProgramEntryCmpLabels.takenAfter k) (allocation initial).1 le before)
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryLinkLabels.callee k
        (allocation initial).1 (Arm64ProgramEntryLinkCall.temps le) after) := by
  obtain ⟨lrWritten,lrEffect,setup⟩ := Arm64ProgramEntryLinkCall.execute prior.memory.resources lr le k
  let middle := Arm64ProgramEntryLinkFrame.packet lrEffect prior
  obtain ⟨after,writerEffect,writer⟩ := Arm64ProgramEntryLinkWriter.invoke middle.memory.storage
    (Arm64ProgramEntryLinkCall.temps le) (Arm64ProgramEntryLinkCall.innerCont k) (by exact CC.PTree.gss _ _ _)
  have jumped := Arm64ProgramEntryLinkLabels.execute (initial := initial) (Arm64ProgramEntryLinkCall.temps le) after k hk
  exact ⟨after,⟨lrWritten,lrEffect,writerEffect⟩,(setup.trans writer).trans jumped⟩

/-- Join full original CMP and CALL on the same actual current memory witness.
The true updated CMP packet/effect supplies all actual link-write resources. -/
theorem from_cmp {initial seed before : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {vectors : Fin 64 → BitVec 64}
    {cell : TailLocal initial 5} {flagValue : BitVec 8}
    (prior : Arm64ClobberResult.Packet base abi byte (-16#64) 16 gprs flags vectors cell flagValue before)
    (lr : HeaderSourceLocal initial 4) (le : CC.TempEnv) (k : CC.Cont) (hk : CC.isCallCont k = true)
    (saved : BitVec 64) (savedResult : le.get Arm64ProgramFixture._result = some (.Vlong saved))
    (s : Reference.AArch64.State) :
    ∃ cmpAfter, ∃ updated : Arm64ClobberResult.Packet base abi byte (-16#64) 16 gprs
        (Arm64ProgramEntryCmpFlags.values (gprs 2) (gprs 3)) vectors cell flagValue cmpAfter,
      Arm64Compare.Stores.Effect prior.memory.storage
        (Arm64ProgramEntryCmpArithmetic.left (gprs 2) false)
        (Arm64ProgramEntryCmpArithmetic.right (gprs 3) false)
        (Arm64ProgramEntryCmpArithmetic.result (gprs 2) (gprs 3) false)
        (Arm64ProgramEntryCmpArithmetic.sign false) cmpAfter ∧
      ∃ after, ∃ result : Result updated lr after, ∃ count,
        InternalRun world count
          (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryTbnzLabels.takenBody
            (.Kseq Arm64ProgramEntryTbnzLabels.takenAfter k) (allocation initial).1 le before)
          (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryLinkLabels.callee k (allocation initial).1
            (Arm64ProgramEntryLinkCall.temps (Arm64ProgramEntryCmpComplete.temps le saved (gprs 2) (gprs 3) s)) after) ∧
        FrameBelow initial.nextblock before after := by
  obtain ⟨cmpAfter,updated,cmpEffect,cmpCount,cmp⟩ := Arm64ProgramEntryCmpComplete.execute prior le k hk saved savedResult s
  obtain ⟨after,result,call⟩ := execute updated lr (Arm64ProgramEntryCmpComplete.temps le saved (gprs 2) (gprs 3) s) k hk
  exact ⟨cmpAfter,updated,cmpEffect,after,result,_,cmp.trans call,cmpEffect.caller.trans result.caller⟩

/-- The full current JCC/CBZ/TBNZ/CMP/CALL source suffix is one execution
from the original post-memcpy state, retaining the actual caller context and
final scalar result while adding genuine LR64/X30-tag9 readbacks. -/
theorem from_memcpy {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {vectors : Fin 64 → BitVec 64}
    {cell : TailLocal initial 5} {flagValue : BitVec 8}
    (prior : Arm64ClobberResult.Packet base abi byte (-16#64) 16 gprs flags vectors cell flagValue m)
    (lr : HeaderSourceLocal initial 4) (frame : FrameBelow initial.nextblock initial m)
    (le : CC.TempEnv) (k : CC.Cont) (hk : CC.isCallCont k = true)
    (ctxBlock : CC.Block) (ctxOffset : CC.Integers.Ptrofs) (mark : BitVec 32)
    (ctxBelow : ctxBlock.toNat < initial.nextblock.toNat)
    (ctx : le.get Arm64ProgramFixture._ctx = some (.Vptr ctxBlock ctxOffset))
    (originalMark : CC.Mem.loadv .Mint32 initial
      (.Vptr ctxBlock (CC.Integers.Ptrofs.add ctxOffset (CC.Integers.Ptrofs.repr 8))) = some (.Vint mark))
    (before : BitVec 64) (saved : le.get Arm64ProgramFixture._result = some (.Vlong before))
    (s : Reference.AArch64.State) :
    let flagsState := Arm64ClobberNativeFlags.native s flags
    let compareState := Arm64ProgramEntryCbzCall.native flagsState (gprs 2)
    let cbzResult := Arm64ProgramEntryCbzExit.result
      (Arm64ProgramEntryJccExit.result (before ^^^ (vectors 63)) mark flagsState) compareState
    let tbnzState := Arm64ProgramEntryTbnzCall.native compareState (gprs 3)
    let tbnzResult := Arm64ProgramEntryTbnzExit.result cbzResult tbnzState
    ∃ cmpAfter, ∃ updated : Arm64ClobberResult.Packet base abi byte (-16#64) 16 gprs
        (Arm64ProgramEntryCmpFlags.values (gprs 2) (gprs 3)) vectors cell flagValue cmpAfter,
      ∃ cmpLe after, ∃ result : Result updated lr after, ∃ count,
        Arm64Compare.Stores.Effect prior.memory.storage
          (Arm64ProgramEntryCmpArithmetic.left (gprs 2) false)
          (Arm64ProgramEntryCmpArithmetic.right (gprs 3) false)
          (Arm64ProgramEntryCmpArithmetic.result (gprs 2) (gprs 3) false)
          (Arm64ProgramEntryCmpArithmetic.sign false) cmpAfter ∧
        InternalRun world count
          (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64MemcpyProgramEntry.next k (allocation initial).1 le m)
          (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryLinkLabels.callee k (allocation initial).1
            (Arm64ProgramEntryLinkCall.temps cmpLe) after) ∧
        (Arm64ProgramEntryLinkCall.temps cmpLe).get Arm64ProgramFixture._ctx = le.get Arm64ProgramFixture._ctx ∧
        (Arm64ProgramEntryLinkCall.temps cmpLe).get Arm64ProgramFixture._result =
          some (.Vlong (Arm64ProgramEntryCmpExit.result tbnzResult tbnzState (gprs 2) (gprs 3))) ∧
        FrameBelow initial.nextblock initial after := by
  dsimp only
  obtain ⟨cmpAfter,updated,cmpLe,cmpCount,cmpEffect,cmp,ctxEq,resultEq,caller⟩ :=
    Arm64ProgramEntryCmpComplete.from_memcpy prior frame le k hk ctxBlock ctxOffset mark ctxBelow ctx originalMark before saved s
  obtain ⟨after,result,call⟩ := execute updated lr cmpLe k hk
  exact ⟨cmpAfter,updated,cmpLe,after,result,_,cmpEffect,cmp.trans call,
    (ctx_preserved cmpLe).trans ctxEq,(result_readback cmpLe).trans resultEq,caller.trans result.caller⟩

end KProgFormal.ClightRefinement.Arm64ProgramEntryLinkComplete
