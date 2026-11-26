import KProgFormal.ClightRefinement.Arm64MemsetLaneGates
import KProgFormal.ClightRefinement.Arm64MemsetByteLane

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemsetStackWrite

open Arm64ProgramEntryAllocation (world)
open Arm64MemsetSource (handler)

/-- Exactly the original tag loop's six updated source temporaries. -/
private def tagTemps (le : CC.TempEnv) (i : Fin 160) (tags : CC.Block) (word : BitVec 64) : CC.TempEnv :=
  ((((((le.set Arm64Program.___ti__1 (.Vlong (BitVec.ofNat 64 i.val >>> 3))).set
    Arm64Program.___ts__1 (.Vint ((((BitVec.ofNat 64 i.val >>> 3) &&& (7#64)) * (8#64)).setWidth 32))).set
    Arm64Program._t'136 (.Vptr tags 0)).set
    Arm64Program.___tp__1 (.Vptr tags ((BitVec.ofNat 64 i.val >>> 3) &&& ~~~(7#64)))).set
    Arm64Program._t'35 (.Vlong word)).set Arm64Program.___tv__1 (.Vlong word))

private theorem tagTemps_source (le : CC.TempEnv) (i : Fin 160) (tags : CC.Block) (word : BitVec 64) :
    Arm64MemsetTagWrite.temps (Arm64MemsetTagSource.preparedTemps le i tags) word = tagTemps le i tags word := rfl

private def laneTemps (le : CC.TempEnv) (value : BitVec 8) (stack : CC.Block) : CC.TempEnv :=
  (((((le.set Arm64Program.___kprog_a64_bl_lane (.Vlong 0)).set
    Arm64Program.___kprog_a64_bl_value (.Vlong (value.setWidth 64))).set
    Arm64Program.___kprog_a64_bl_shift (.Vlong 0)).set
    Arm64Program.___kprog_a64_bl_shift (.Vlong 0)).set Arm64Program._t'134 (.Vptr stack 0))

private theorem laneTemps_source (le : CC.TempEnv) (value : BitVec 8) (stack : CC.Block) :
    Arm64MemsetByteWrite.temps (Arm64MemsetByteLane.temps le value) stack = laneTemps le value stack := rfl

def temps (le : CC.TempEnv) (i : Fin 160) (tags stack : CC.Block) (word : BitVec 64) (value : BitVec 8) : CC.TempEnv :=
  Arm64MemsetLaneGates.temps (laneTemps
    (Arm64MemsetByteGates.temps (tagTemps le i tags word) (BitVec.ofNat 64 i.val)) value stack)

/-- The actual tag/byte/gate temporary updates retain the original entry
and loss offset used by the real post-store SP/tag loop. -/
theorem temps_inputs (le : CC.TempEnv) (i : Fin 160) (tags stack : CC.Block)
    (word : BitVec 64) (value : BitVec 8) :
    (temps le i tags stack word value).get Arm64Program._entry = le.get Arm64Program._entry ∧
    (temps le i tags stack word value).get Arm64Program.___a64_loss_off = le.get Arm64Program.___a64_loss_off := by
  constructor <;> simp +decide only [temps,tagTemps,laneTemps,Arm64MemsetByteGates.temps,
    Arm64MemsetLaneGates.temps,CC.PTree.gso]

/-- Real store temporary assignments preserve the enclosing loop counter,
length and byte parameter. -/
theorem temps_loop (le : CC.TempEnv) (i : Fin 160) (tags stack : CC.Block) (word : BitVec 64) (value : BitVec 8) :
    (temps le i tags stack word value).get Arm64Program.___a64_lib_i = le.get Arm64Program.___a64_lib_i ∧
    (temps le i tags stack word value).get Arm64Program.___a64_lib_len = le.get Arm64Program.___a64_lib_len ∧
    (temps le i tags stack word value).get Arm64Program.___a64_lib_byte = le.get Arm64Program.___a64_lib_byte := by
  refine ⟨?_,?_,?_⟩ <;> simp +decide only [temps,tagTemps,laneTemps,Arm64MemsetByteGates.temps,Arm64MemsetLaneGates.temps,CC.PTree.gso]

/-- The entire original stack arm executes its real tag read/modify/write,
width and crossing gates, volatile byte store, and all seven remaining gates.
The two real stores and their complete source continuations are retained. -/
theorem execute (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont)
    (entry tags stack : CC.Block) (i : Fin 160) (word : BitVec 64) (value : BitVec 8)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry 0))
    (hindex : le.get Arm64Program.___a64_stw_index = some (.Vlong (BitVec.ofNat 64 i.val)))
    (hwidth : le.get Arm64Program.___a64_stw_width = some (.Vint 1))
    (hvalue : le.get Arm64Program.___a64_stw_value = some (.Vlong (value.setWidth 64)))
    (tagPointer : CC.Mem.load CC.Mptr m entry 648 = some (.Vptr tags 0))
    (stackPointer : CC.Mem.load CC.Mptr m entry 608 = some (.Vptr stack 0))
    (observed : CC.Mem.load .Mint64 m tags (Arm64MemsetTagWrite.offset (Arm64MemsetTagSource.tagOf i)) = some (.Vlong word))
    (tagRange : CC.Mem.rangePerm m tags 0 24 .Cur .Writable = true)
    (stackRange : CC.Mem.rangePerm m stack 0 160 .Cur .Writable = true)
    (entrySeparate : entry ≠ tags) (stackSeparate : tags ≠ stack) :
    ∃ tagged after,
      CC.Star (CC.Step2 world) (.State handler Arm64Program.s_kprog_arm64_program_memset_77 k e le m) CC.E0
        (.State handler .Sskip k e (temps le i tags stack word value) after) ∧
      CC.Mem.store .Mint64 m tags (Arm64MemsetTagWrite.offset (Arm64MemsetTagSource.tagOf i))
        (.Vlong (Arm64MemsetTagWrite.cleared (Arm64MemsetTagSource.tagOf i) word)) = some tagged ∧
      CC.Mem.store .Mint8unsigned tagged stack (i.val : Int) (.Vint (value.setWidth 32)) = some after ∧
      CC.Mem.load .Mint8unsigned after stack (i.val : Int) = some (.Vint (value.setWidth 32)) ∧
      CC.Mem.load .Mint64 after tags (Arm64MemsetTagWrite.offset (Arm64MemsetTagSource.tagOf i)) =
        some (.Vlong (Arm64MemsetTagWrite.cleared (Arm64MemsetTagSource.tagOf i) word)) ∧
      after.access = m.access ∧ after.nextblock = m.nextblock ∧
      (∀ (chunk : CC.Chunk) (block : CC.Block) (offset : Int), block ≠ tags → block ≠ stack →
        CC.Mem.load chunk after block offset = CC.Mem.load chunk m block offset) := by
  have enter : InternalRun world 1
      (.State handler Arm64Program.s_kprog_arm64_program_memset_77 k e le m)
      (.State handler Arm64MemsetTagWrite.loop (.Kseq Arm64MemsetByteGates.afterTag k) e le m) := by
    rw [Arm64MemsetByteGates.source]
    exact .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  obtain ⟨tagged,tagRun,tagStored,tagRead,tagAccess,tagNext⟩ := Arm64MemsetTagSource.execute e le m
    (.Kseq Arm64MemsetByteGates.afterTag k) entry tags i word hentry hindex tagPointer observed tagRange
  rw [tagTemps_source] at tagRun
  let lt := tagTemps le i tags word
  have nextTag : InternalRun world 1
      (.State handler .Sskip (.Kseq Arm64MemsetByteGates.afterTag k) e lt tagged)
      (.State handler Arm64MemsetByteGates.afterTag k e lt tagged) :=
    .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  have widthTag : lt.get Arm64Program.___a64_stw_width = some (.Vint 1) := by
    simpa +decide only [lt,tagTemps,CC.PTree.gso] using hwidth
  have indexTag : lt.get Arm64Program.___a64_stw_index = some (.Vlong (BitVec.ofNat 64 i.val)) := by
    simpa +decide only [lt,tagTemps,CC.PTree.gso] using hindex
  have gateRun := Arm64MemsetByteGates.to_byte e lt tagged k (BitVec.ofNat 64 i.val) widthTag indexTag
  let lg := Arm64MemsetByteGates.temps lt (BitVec.ofNat 64 i.val)
  have entryGate : lg.get Arm64Program._entry = some (.Vptr entry 0) := by
    simpa +decide only [lg,Arm64MemsetByteGates.temps,lt,tagTemps,CC.PTree.gso] using hentry
  have indexGate : lg.get Arm64Program.___a64_stw_index = some (.Vlong (BitVec.ofNat 64 i.val)) := by
    simpa +decide only [lg,Arm64MemsetByteGates.temps,CC.PTree.gso] using indexTag
  have valueGate : lg.get Arm64Program.___a64_stw_value = some (.Vlong (value.setWidth 64)) := by
    simpa +decide only [lg,Arm64MemsetByteGates.temps,lt,tagTemps,CC.PTree.gso] using hvalue
  have pointerTag : CC.Mem.load CC.Mptr tagged entry 608 = some (.Vptr stack 0) :=
    (CC.Mem.load_store_other tagStored CC.Mptr entry 608 (.inl entrySeparate)).trans stackPointer
  have rangeTag : CC.Mem.rangePerm tagged stack 0 160 .Cur .Writable = true := by
    rw [CC.Mem.rangePerm_store_eq tagStored]
    exact stackRange
  obtain ⟨after,byteRun,byteStored,byteRead,byteAccess,byteNext⟩ := Arm64MemsetByteLane.execute e lg tagged
    (.Kseq Arm64MemsetByteGates.afterByte k) entry stack i value entryGate indexGate valueGate pointerTag rangeTag
  rw [laneTemps_source] at byteRun
  let lb := laneTemps lg value stack
  have nextByte : InternalRun world 1
      (.State handler .Sskip (.Kseq Arm64MemsetByteGates.afterByte k) e lb after)
      (.State handler Arm64MemsetByteGates.afterByte k e lb after) :=
    .step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)
  have widthByte : lb.get Arm64Program.___a64_stw_width = some (.Vint 1) := by
    simpa +decide only [lb,laneTemps,lg,Arm64MemsetByteGates.temps,CC.PTree.gso] using widthTag
  have remaining := Arm64MemsetLaneGates.execute e lb after k widthByte
  refine ⟨tagged,after,?_,tagStored,byteStored,byteRead,?_,byteAccess.trans tagAccess,byteNext.trans tagNext,?_⟩
  · simpa only [CC.Eapp,CC.E0,List.nil_append,temps,lb,lg,lt] using
      star_trans (star_trans (star_trans (star_trans (star_trans
        (star_trans enter.sound tagRun) nextTag.sound) gateRun.sound) byteRun) nextByte.sound) remaining.sound
  · exact (CC.Mem.load_store_other byteStored .Mint64 tags
      (Arm64MemsetTagWrite.offset (Arm64MemsetTagSource.tagOf i)) (.inl stackSeparate)).trans tagRead
  · intro chunk block offset tagOther stackOther
    exact (CC.Mem.load_store_other byteStored chunk block offset (.inl stackOther)).trans
      (CC.Mem.load_store_other tagStored chunk block offset (.inl tagOther))


/-- The same original producer allocations supply both write permissions,
block separation and the complete raw caller frame for the full source arm. -/
theorem execute_local {initial : CC.Mem} (entry : Arm64Producer.HeaderLocal initial)
    (tags : Arm64Producer.StackTagLocal initial) (stack : Arm64Producer.TailLocal initial 0)
    (e : CC.Env) (le : CC.TempEnv) (m : CC.Mem) (k : CC.Cont) (i : Fin 160)
    (word : BitVec 64) (value : BitVec 8)
    (tagAccess : CC.PMap.get tags.block m.access = CC.PMap.get tags.block (Arm64Producer.allocation initial).2.access)
    (stackAccess : CC.PMap.get stack.block m.access = CC.PMap.get stack.block (Arm64Producer.allocation initial).2.access)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (hindex : le.get Arm64Program.___a64_stw_index = some (.Vlong (BitVec.ofNat 64 i.val)))
    (hwidth : le.get Arm64Program.___a64_stw_width = some (.Vint 1))
    (hvalue : le.get Arm64Program.___a64_stw_value = some (.Vlong (value.setWidth 64)))
    (tagPointer : CC.Mem.load CC.Mptr m entry.block 648 = some (.Vptr tags.block 0))
    (stackPointer : CC.Mem.load CC.Mptr m entry.block 608 = some (.Vptr stack.block 0))
    (observed : CC.Mem.load .Mint64 m tags.block
      (Arm64MemsetTagWrite.offset (Arm64MemsetTagSource.tagOf i)) = some (.Vlong word)) :
    ∃ tagged after,
      CC.Star (CC.Step2 world) (.State handler Arm64Program.s_kprog_arm64_program_memset_77 k e le m) CC.E0
        (.State handler .Sskip k e (temps le i tags.block stack.block word value) after) ∧
      CC.Mem.store .Mint64 m tags.block (Arm64MemsetTagWrite.offset (Arm64MemsetTagSource.tagOf i))
        (.Vlong (Arm64MemsetTagWrite.cleared (Arm64MemsetTagSource.tagOf i) word)) = some tagged ∧
      CC.Mem.store .Mint8unsigned tagged stack.block (i.val : Int) (.Vint (value.setWidth 32)) = some after ∧
      CC.Mem.load .Mint8unsigned after stack.block (i.val : Int) = some (.Vint (value.setWidth 32)) ∧
      CC.Mem.load .Mint64 after tags.block (Arm64MemsetTagWrite.offset (Arm64MemsetTagSource.tagOf i)) =
        some (.Vlong (Arm64MemsetTagWrite.cleared (Arm64MemsetTagSource.tagOf i) word)) ∧
      FrameBelow initial.nextblock m after ∧ after.access = m.access ∧ after.nextblock = m.nextblock ∧
      (∀ (chunk : CC.Chunk) (block : CC.Block) (offset : Int), block ≠ tags.block → block ≠ stack.block →
        CC.Mem.load chunk after block offset = CC.Mem.load chunk m block offset) := by
  have allocation := CC.doAllocVariables_sound _ _ _ _ _ _
    (Prod.eta (Arm64Producer.allocation initial)).symm
  have storage := allocated_local_storage allocation
  have stackLive := storage.1 _ _ stack.binding
  have actualSize : CC.sizeof Arm64Producer.ge.genv_cenv (Arm64Producer.tailLocalType 0) = 160 := by decide +kernel
  have tagRange : CC.Mem.rangePerm m tags.block 0 24 .Cur .Writable = true :=
    (CC.Mem.rangePerm_congr (m1 := m) (m2 := (Arm64Producer.allocation initial).2)
      (fun offset => by simp only [CC.Mem.perm,tagAccess])).trans tags.range
  have writable : CC.Mem.rangePerm (Arm64Producer.allocation initial).2 stack.block 0 160 .Cur .Writable = true :=
    CC.Mem.rangePerm_implies (by simpa only [actualSize] using stackLive.2.2) (by decide)
  have stackRange : CC.Mem.rangePerm m stack.block 0 160 .Cur .Writable = true :=
    (CC.Mem.rangePerm_congr (m1 := m) (m2 := (Arm64Producer.allocation initial).2)
      (fun offset => by simp only [CC.Mem.perm,stackAccess])).trans writable
  have entrySeparate : entry.block ≠ tags.block :=
    storage.2 _ _ _ _ entry.binding tags.binding (by decide +kernel)
  have stackSeparate : tags.block ≠ stack.block :=
    storage.2 _ _ _ _ tags.binding stack.binding (by decide +kernel)
  obtain ⟨tagged,after,run,tagStored,byteStored,byteRead,tagRead,access,next,outside⟩ :=
    execute e le m k entry.block tags.block stack.block i word value hentry hindex hwidth hvalue
      tagPointer stackPointer observed tagRange stackRange entrySeparate stackSeparate
  exact ⟨tagged,after,run,tagStored,byteStored,byteRead,tagRead,
    (FrameBelow.store tags.fresh tagStored).trans (FrameBelow.store stackLive.1 byteStored),access,next,outside⟩

end KProgFormal.ClightRefinement.Arm64MemsetStackWrite
