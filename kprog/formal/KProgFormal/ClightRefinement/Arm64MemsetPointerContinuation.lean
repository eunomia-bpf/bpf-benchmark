import KProgFormal.ClightRefinement.Arm64MemsetProgramCaller

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemsetPointerContinuation

open Arm64Producer Arm64ProducerRegisterStorage
open Arm64ProgramEntryAllocation (world)
open Arm64ProgramEntryPointerWrites (before call after destination raw)

/-- Execute an actual original pointer-call site using the current writable
cells. The same two stores supply its genuine linked procedure execution. -/
theorem site {initial m : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial m entry) (index : Fin 3) (le : CC.TempEnv) (k : CC.Cont) :
    ∃ written, Arm64PointerWrite.Result storage (destination index) (raw index) (4#8) written ∧
      InternalRun world 57
        (.State Arm64ProgramFixture.f_arm64_execute_compile (before index) k (Arm64ProgramEntryAllocation.allocation initial).1 le m)
        (.State Arm64ProgramFixture.f_arm64_execute_compile (after index) k (Arm64ProgramEntryAllocation.allocation initial).1 le written) := by
  let cont := CC.Cont.Kcall none Arm64ProgramFixture.f_arm64_execute_compile (Arm64ProgramEntryAllocation.allocation initial).1 le (.Kseq (after index) k)
  obtain ⟨written,effect⟩ := Arm64PointerWrite.write storage (destination index) (raw index) (4#8)
  obtain ⟨middle,word,tag⟩ := effect.stores
  have enter : InternalRun world 2
      (.State Arm64ProgramFixture.f_arm64_execute_compile (before index) k (Arm64ProgramEntryAllocation.allocation initial).1 le m)
      (.Callstate (.Internal Arm64PointerWrite.procedure)
        (Arm64PointerWrite.arguments entry.block (destination index) (raw index) (4#8)) cont m) := by
    rw [Arm64ProgramEntryPointerWrites.source]
    exact .step trivial (CC.doStep_sound _ _ _ _ rfl)
      (.step (by rw [Arm64ProgramEntryPointerWrites.call_source]; trivial)
        (Arm64ProgramEntryPointerWrites.call_step entry index le m (.Kseq (after index) k)) (.refl _))
  have procedure := Arm64PointerWrite.execute_stores_layout world Arm64PointerWrite.Linked.layout cont rfl
    initial m middle written entry storage (destination index) (raw index) (4#8) word tag
  have leave : InternalRun world 2 (.Returnstate .Vundef cont written)
      (.State Arm64ProgramFixture.f_arm64_execute_compile (after index) k (Arm64ProgramEntryAllocation.allocation initial).1 le written) :=
    .step trivial (CC.doStep_sound _ _ _ _ rfl) (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _))
  exact ⟨written,effect,(enter.trans procedure).trans leave⟩

/-- These are the two successive original sites after the completed memset. -/
theorem source : before (1 : Fin 3) = Arm64MemsetProgramCaller.next ∧
    after (1 : Fin 3) = before (2 : Fin 3) ∧
    after (2 : Fin 3) = Arm64ProgramEntryPointerWrites.afterThird := by
  exact ⟨rfl,rfl,rfl⟩

structure Effect {initial beforeMem : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial beforeMem entry) (middle finalMem : CC.Mem) : Prop where
  first : Arm64PointerWrite.Result storage 0 (-16#64) (4#8) middle
  second : Arm64PointerWrite.Result first.storage 1 (-32#64) (4#8) finalMem

/-- Both actual calls consume the preceding store output and retain the real
caller environment and temps through the fifteenth-MOV continuation. -/
theorem execute {initial m : CC.Mem} {entry : HeaderLocal initial}
    (storage : Storage initial m entry) (le : CC.TempEnv) (k : CC.Cont) :
    ∃ middle finalMem, Effect storage middle finalMem ∧
      InternalRun world 114
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64MemsetProgramCaller.next k (Arm64ProgramEntryAllocation.allocation initial).1 le m)
        (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryPointerWrites.afterThird k
          (Arm64ProgramEntryAllocation.allocation initial).1 le finalMem) := by
  obtain ⟨middle,first,one⟩ := site storage 1 le k
  change Arm64PointerWrite.Result storage 0 (-16#64) (4#8) middle at first
  obtain ⟨finalMem,second,two⟩ := site first.storage 2 le k
  change Arm64PointerWrite.Result first.storage 1 (-32#64) (4#8) finalMem at second
  exact ⟨middle,finalMem,⟨first,second⟩,one.trans two⟩

section Effect
variable {initial beforeMem middle finalMem : CC.Mem} {entry : HeaderLocal initial}
    {priorStorage : Storage initial beforeMem entry} (effect : Effect priorStorage middle finalMem)
include effect

def Effect.storage : Storage initial finalMem entry := effect.second.storage

theorem Effect.caller : FrameBelow initial.nextblock beforeMem finalMem :=
  effect.first.caller.trans effect.second.caller

theorem Effect.access : finalMem.access = beforeMem.access := effect.second.access.trans effect.first.access

theorem Effect.nextblock : finalMem.nextblock = beforeMem.nextblock :=
  effect.second.nextblock.trans effect.first.nextblock

/-- The selected R0/R1 observations follow all four real payload/tag stores;
all other GPR reads retain their precise prior result. -/
theorem Effect.gpr (j : Fin 31) :
    Arm64EntryMemory.gpr finalMem.nextblock finalMem (.Vptr entry.block 0) j.val =
      if j = 1 then some (.Vlong (-32#64),.Vint ((4#8).setWidth 32))
      else if j = 0 then some (.Vlong (-16#64),.Vint ((4#8).setWidth 32))
      else Arm64EntryMemory.gpr beforeMem.nextblock beforeMem (.Vptr entry.block 0) j.val := by
  rw [effect.second.nextblock,effect.second.gpr j,effect.first.nextblock,effect.first.gpr j]

/-- Actual allocation names keep every other local, including header, stack,
stack tags, SP, flags, vectors and ABI, across the same two pointer calls. -/
theorem Effect.local_load (id : CC.Ident) (ty : CC.Ty) (block : CC.Block)
    (binding : (Arm64Producer.allocation initial).1.get id = some (block,ty))
    (w0 : tableCellName false (0 : Fin 31) ≠ id) (t0 : tableCellName true (0 : Fin 31) ≠ id)
    (w1 : tableCellName false (1 : Fin 31) ≠ id) (t1 : tableCellName true (1 : Fin 31) ≠ id)
    (chunk : CC.Chunk) (offset : Int) :
    CC.Mem.load chunk finalMem block offset = CC.Mem.load chunk beforeMem block offset :=
  (effect.second.local_load id ty block binding w1 t1 chunk offset).trans
    (effect.first.local_load id ty block binding w0 t0 chunk offset)

end Effect
end KProgFormal.ClightRefinement.Arm64MemsetPointerContinuation
