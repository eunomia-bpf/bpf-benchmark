import KProgFormal.ClightRefinement.Arm64MemcpyTagFrame

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyTagLoop

open Arm64ProgramEntryAllocation (world)
open Arm64MemcpySource (handler)

def temps (le : CC.TempEnv) (i : Fin 16) (tags : CC.Block) : CC.TempEnv :=
  Arm64MemcpyTagWrite.temps (Arm64MemcpyTagSetup.temps le i tags)

/-- The actual first tag loop includes its original address preparation,
both volatile builtins and all real loop/sequence exits to the byte suffix. -/
theorem execute {initial : CC.Mem} (tags : Arm64Producer.StackTagLocal initial)
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (entry : CC.Block) (i : Fin 16)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (hindex : le.get Arm64Program.___a64_stw_index = some (.Vlong (BitVec.ofNat 64 (80+i.val))))
    (header : CC.Mem.load CC.Mptr m entry 648 = some (.Vptr tags.block 0))
    (range : CC.Mem.rangePerm m tags.block 0 24 .Cur .Writable = true)
    (zero : ∀ j : Fin 24, CC.Mem.load .Mint8unsigned m tags.block (j.val : Int) = some (.Vint 0)) :
    ∃ after, CC.Star (CC.Step2 world)
      (.State handler Arm64Program.s_kprog_arm64_program_memcpy_81 k e le m) CC.E0
      (.State handler Arm64MemcpyTagSetup.afterTag k e (temps le i tags.block) after) ∧
      CC.Mem.store .Mint64 m tags.block 8 (.Vlong 0) = some after ∧
      FrameBelow m.nextblock m after ∧ after.access = m.access ∧ after.nextblock = m.nextblock := by
  have prefixRun := Arm64MemcpyTagSetup.execute e le m k entry tags.block i hentry hindex header
  have prepared := Arm64MemcpyTagSetup.prepared le i tags.block
  have offset : CC.Integers.Ptrofs.repr (Arm64MemsetTagWrite.offset (Arm64MemcpyTagSetup.tag i)) = (8#64) := by
    have checked : ∀ j : Fin 16, Arm64MemsetTagWrite.offset (Arm64MemcpyTagSetup.tag j) = (8 : Int) := by decide +kernel
    rw [checked i]
    rfl
  have pointer : (Arm64MemcpyTagSetup.temps le i tags.block).get Arm64Program.___tp__1 =
      some (.Vptr tags.block (8#64)) := by simpa only [offset] using prepared.1
  obtain ⟨after,run,stored,_zero,_caller,access,next⟩ := Arm64MemcpyTagWrite.execute tags e
    (Arm64MemcpyTagSetup.temps le i tags.block) m (Arm64MemcpyTagSetup.continuation k) i
    range pointer prepared.2 zero
  have leave : InternalRun world 3
      (.State handler .Sskip (Arm64MemcpyTagSetup.continuation k) e (temps le i tags.block) after)
      (.State handler Arm64MemcpyTagSetup.afterTag k e (temps le i tags.block) after) :=
    .step trivial (CC.doStep_sound _ _ _ _ rfl)
      (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)))
  refine ⟨after,?_,stored,Arm64MemcpyTagFrame.word_store stored zero m.nextblock,access,next⟩
  simpa only [CC.E0,CC.Eapp,List.nil_append] using star_trans prefixRun.sound (star_trans run leave.sound)

theorem kept (le : CC.TempEnv) (i : Fin 16) (tags : CC.Block) (id : CC.Ident)
    (copyOther : Arm64Program.___tv__1 ≠ id) (loadOther : Arm64Program._t'38 ≠ id)
    (pointerOther : Arm64Program.___tp__1 ≠ id) (headerOther : Arm64Program._t'143 ≠ id)
    (shiftOther : Arm64Program.___ts__1 ≠ id) (indexOther : Arm64Program.___ti__1 ≠ id) :
    (temps le i tags).get id = le.get id := by
  change ((((((le.set Arm64Program.___ti__1 (.Vlong (BitVec.ofNat 64 (80+i.val) >>> 3))).set
    Arm64Program.___ts__1 (.Vint ((((BitVec.ofNat 64 (80+i.val) >>> 3) &&& (7#64)) * (8#64)).setWidth 32))).set
    Arm64Program._t'143 (.Vptr tags 0)).set
    Arm64Program.___tp__1 (.Vptr tags ((BitVec.ofNat 64 (80+i.val) >>> 3) &&& ~~~(7#64)))).set
    Arm64Program._t'38 (.Vlong 0)).set Arm64Program.___tv__1 (.Vlong 0)).get id = le.get id
  simp only [CC.PTree.gso _ _ _ _ copyOther,CC.PTree.gso _ _ _ _ loadOther,
    CC.PTree.gso _ _ _ _ pointerOther,CC.PTree.gso _ _ _ _ headerOther,
    CC.PTree.gso _ _ _ _ shiftOther,CC.PTree.gso _ _ _ _ indexOther]

private def retain {initial seed calleeBefore before after : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    {le : CC.TempEnv} {n : Nat} (i : Fin 16)
    (prior : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore n before le)
    (producerBound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (callerBound : (Arm64MemcpySource.allocation calleeBefore).2.nextblock.toNat ≤ before.nextblock.toNat)
    (stored : CC.Mem.store .Mint64 before base.tags.block 8 (.Vlong 0) = some after) :
    Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore n after (temps le i base.tags.block) := by
  let current := Arm64MemcpyTagFrame.current prior producerBound callerBound stored
  refine ⟨current.packet,current.callee,?_,?_,?_,?_,current.copied⟩
  · exact (kept le i base.tags.block _ (by decide +kernel) (by decide +kernel) (by decide +kernel)
      (by decide +kernel) (by decide +kernel) (by decide +kernel)).trans current.entryRead
  · exact (kept le i base.tags.block _ (by decide +kernel) (by decide +kernel) (by decide +kernel)
      (by decide +kernel) (by decide +kernel) (by decide +kernel)).trans current.length
  · exact (kept le i base.tags.block _ (by decide +kernel) (by decide +kernel) (by decide +kernel)
      (by decide +kernel) (by decide +kernel) (by decide +kernel)).trans current.counter
  · exact (kept le i base.tags.block _ (by decide +kernel) (by decide +kernel) (by decide +kernel)
      (by decide +kernel) (by decide +kernel) (by decide +kernel)).trans current.sourceTag

/-- Actual current Freeable rights derive the real tag-word write. The
complete current memcpy packet and its flag survive the entire source loop. -/
theorem current {initial seed calleeBefore before : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : Arm64Producer.TailLocal initial 6} {byte : BitVec 8}
    {gprs : Fin 18 → BitVec 64} {flags : Fin 4 → BitVec 64} {values : Fin 64 → BitVec 64}
    (le : CC.TempEnv) (k : CC.Cont) (i : Fin 16)
    (prior : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore i.val before le)
    (producerBound : (Arm64Producer.allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (callerBound : (Arm64MemcpySource.allocation calleeBefore).2.nextblock.toNat ≤ before.nextblock.toNat)
    (hindex : le.get Arm64Program.___a64_stw_index = some (.Vlong (BitVec.ofNat 64 (80+i.val))))
    (cell : Arm64Producer.TailLocal initial 5) (flagValue : BitVec 8)
    (flag : Arm64MemcpyReadCurrent.Flag entry cell flagValue before) :
    ∃ after, ∃ _next : Arm64MemcpyLoopState.Invariant base abi byte gprs flags values calleeBefore i.val after
      (temps le i base.tags.block), CC.Star (CC.Step2 world)
      (.State handler Arm64Program.s_kprog_arm64_program_memcpy_81 k (Arm64MemcpySource.allocation calleeBefore).1 le before) CC.E0
      (.State handler Arm64MemcpyTagSetup.afterTag k (Arm64MemcpySource.allocation calleeBefore).1 (temps le i base.tags.block) after) ∧
      CC.Mem.store .Mint64 before base.tags.block 8 (.Vlong 0) = some after ∧
      FrameBelow before.nextblock before after ∧ Arm64MemcpyReadCurrent.Flag entry cell flagValue after ∧
      after.nextblock = before.nextblock := by
  have rights := prior.packet.resources.freeable _ _ (Arm64ProgramEntryRawSetup.tag_binding initial base.tags)
  change CC.Mem.rangePerm before base.tags.block 0 24 .Cur .Freeable = true at rights
  have range := CC.Mem.rangePerm_implies rights (by decide : CC.permOrder .Freeable .Writable = true)
  have header : CC.Mem.load CC.Mptr before entry.block 648 = some (.Vptr base.tags.block 0) := by
    rw [←prior.packet.tagsSame]
    exact prior.packet.view.tagPointer
  obtain ⟨after,run,stored,frame,_access,next⟩ := execute base.tags (Arm64MemcpySource.allocation calleeBefore).1
    le before k entry.block i prior.entryRead hindex header range prior.packet.tagBytes
  exact ⟨after,retain i prior producerBound callerBound stored,run,stored,frame,
    flag.frame before.nextblock producerBound frame,next⟩

end KProgFormal.ClightRefinement.Arm64MemcpyTagLoop
