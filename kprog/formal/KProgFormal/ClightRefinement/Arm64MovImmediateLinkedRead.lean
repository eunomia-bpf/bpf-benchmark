import KProgFormal.ClightRefinement.Arm64ProgramEntryCacheFrame

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64MovImmediate.LinkedRead

open Arm64Producer Arm64ProducerRegisterStorage Arm64ProducerEntryView
open Arm64ProgramEntryAllocation (world)
open Arm64ProgramEntryCacheFrame (Frame)

/-- Execute the actual MOV_IMM scalar suffix with its eager cold SP32 read.
The external trace, supplied memory and two cache stores remain observable.
The immediate is unrestricted; the actual writer derives its word/tag stores.
This stops with the generic handler's frame live, before its final free. -/
theorem scalar_write {initial before supplied : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial before entry)
    (header : (i : Fin 12) → HeaderSourceLocal initial i)
    (pointers : ∀ i, CC.Mem.load CC.Mptr before entry.block (8 * (i.val : Int)) =
      some (.Vptr (header i).block 0))
    (access : ∀ block, block.toNat < (allocation initial).2.nextblock.toNat →
      CC.PMap.get block before.access = CC.PMap.get block (allocation initial).2.access)
    (bound : (allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (cold : Arm64EntryMemory.borrowed before.nextblock .Mint8unsigned before (.Vptr entry.block 0)
      Arm64Program._sp_valid = some (.Vint 0))
    (addresses : Arm64Registers.PointerOrigins) (origins : Reference.Provenance.AArch64.Origins)
    (s : Reference.AArch64.State)
    (represented : Arm64Registers.Represents addresses origins (fun r => r.val)
      before.nextblock before (.Vptr entry.block 0) s)
    (trace : CC.Trace)
    (provider : CC.externalCall Arm64OriginCache.inputEF (CC.Genv.toSenv world.genv_genv)
      [.Vint 1] before trace (.Vlong origins.stack) supplied)
    (outcome : Frame initial false before supplied)
    (e : CC.Env) (le : CC.TempEnv) (i : Fin 31) (value : BitVec 64) (narrow : Bool)
    (readUnshadowed : e.get Arm64Program._kprog_arm64_program_read = none)
    (writeUnshadowed : e.get Arm64Program._kprog_arm64_program_write = none)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (hsrc : le.get Arm64Program._src = some (.Vlong 32))
    (hdst : le.get Arm64Program._dst = some (.Vlong (BitVec.ofNat 64 i.val)))
    (hop : le.get Arm64Program._op = some (.Vint 1))
    (himm : le.get Arm64Program._imm = some (.Vlong value))
    (hwidth : le.get Arm64Program.___a64_l_width = some (Arm64RegisterWrite.width narrow)) :
    ∃ locals : CacheLocals false initial, ∃ middle cached written,
    ∃ carried : Storage initial cached entry,
      CC.Star (CC.Step2 world)
        (.State Arm64Nop.handler Dispatch.scalarBranch Dispatch.continuation e le before)
        trace (.State Arm64Nop.handler .Sskip .Kstop e
          (Suffix.writerTempsRead le (Reference.AArch64.sp s) value) written) ∧
      CC.Mem.store .Mint64 supplied locals.baseBlock 0 (.Vlong origins.stack) = some middle ∧
      CC.Mem.store .Mint8unsigned middle locals.validBlock 0 (.Vint 1) = some cached ∧
      Arm64RegisterReads.WarmEntryCache false before.nextblock cached (.Vptr entry.block 0) origins.stack ∧
      Frame initial false before cached ∧
      Arm64Registers.Represents addresses origins (fun r => r.val)
        before.nextblock cached (.Vptr entry.block 0) s ∧
      Arm64RegisterWrite.Result carried i value narrow written ∧
      Arm64Registers.Represents addresses origins (fun r => r.val)
        before.nextblock written (.Vptr entry.block 0) (Arm64RegisterWrite.nativeUpdate s i value narrow) ∧
      FrameBelow initial.nextblock before written ∧
      written.access = before.access ∧ written.nextblock = before.nextblock := by
  let readK := CC.Cont.Kcall (some Arm64Program._t'4) Arm64Nop.handler e le Suffix.readCont
  obtain ⟨locals, middle, cached, read, storeBase, storeValid, warm, frame, ⟨carried⟩, same⟩ :=
    Arm64ProgramEntryCacheFrame.read_framed storage header pointers access bound cold
      addresses origins s represented trace readK provider outcome
  have enter := Suffix.read_call_bound world (CC.Positive.ofNat 66)
    Arm64MovKeep.Linked.reader_binding 32 e le before entry.block readUnshadowed hentry hsrc
  have select := Suffix.after_read_bound world (CC.Positive.ofNat 107)
    Arm64MovKeep.Linked.writer_binding (Reference.AArch64.sp s) e le cached entry.block
      (BitVec.ofNat 64 i.val) value narrow writeUnshadowed hentry hdst hop himm hwidth
  have toWriter := star_trans (star_trans enter.sound read) select.sound
  obtain ⟨written, result⟩ := Arm64RegisterWrite.write carried i value narrow
  obtain ⟨storeMiddle, wordStore, tagStore⟩ := result.stores
  have write := Arm64RegisterWrite.execute_stores_layout world Arm64MovKeep.Linked.writer_layout
    (.Kcall none Arm64Nop.handler e (Suffix.writerTempsRead le (Reference.AArch64.sp s) value)
      Dispatch.continuation) rfl initial cached storeMiddle written entry carried i value narrow wordStore tagStore
  have finish := Suffix.after_writer_bound world e (Suffix.writerTempsRead le (Reference.AArch64.sp s) value) written
  have cachedRep : Arm64Registers.Represents addresses origins (fun r => r.val)
      cached.nextblock cached (.Vptr entry.block 0) s := by
    simpa only [frame.nextblock] using same
  have finalRep := result.represents addresses origins s cachedRep
  rw [frame.nextblock] at finalRep
  refine ⟨locals, middle, cached, written, carried, ?_, storeBase, storeValid, warm, frame, same,
    result, finalRep, frame.caller.trans result.caller, result.access.trans frame.access,
    result.nextblock.trans frame.nextblock⟩
  simpa only [readK, CC.callCont, Arm64RegisterWrite.arguments, CC.Eapp, CC.E0,
    List.nil_append, List.append_nil] using star_trans toWriter (write.trans finish).sound

end KProgFormal.ClightRefinement.Arm64MovImmediate.LinkedRead
