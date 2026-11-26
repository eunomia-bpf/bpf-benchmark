import KProgFormal.ClightRefinement.Arm64MemsetIterationEntry

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemsetWriteLoop

open Arm64Producer Arm64ProducerRegisterStorage
open Arm64ProgramEntryAllocation (world)
open Arm64MemsetSource (handler)

/-- All source observations live on the same current heap. The canonical
stack and tag identities are fixed while earlier actual byte stores accumulate. -/
structure Invariant {initial seed : CC.Mem} {entry : HeaderLocal initial}
    (base : Arm64MemsetHeaderView.View initial seed entry)
    (abi : TailLocal initial 6) (byte : BitVec 8) (n : Nat) (m : CC.Mem) (le : CC.TempEnv) where
  view : Arm64MemsetHeaderView.View initial m entry
  stackSame : view.stack.block = base.stack.block
  tagsSame : view.tags.block = base.tags.block
  resources : Arm64ProgramEntryResources.Resources initial m entry
  storage : Arm64ProducerRegisterStorage.Storage initial m entry
  spAtBase : storage.spValue = (-32#64)
  entryRead : le.get Arm64Program._entry = some (.Vptr entry.block 0)
  counter : le.get Arm64Program.___a64_lib_i = some (.Vlong (BitVec.ofNat 64 n))
  length : le.get Arm64Program.___a64_lib_len = some (.Vlong 16)
  value : le.get Arm64Program.___a64_lib_byte = some (.Vint (byte.setWidth 32))
  gpr : Arm64EntryMemory.gpr m.nextblock m (.Vptr entry.block 0) 0 =
    some (.Vlong (-32#64),.Vint ((4#8).setWidth 32))
  abiHeader : CC.Mem.load CC.Mptr m entry.block 704 = some (.Vptr abi.block 0)
  abiKind : CC.Mem.load .Mint8unsigned m abi.block 0 = some (.Vint 2)
  tagBytes : ∀ j : Fin 24, CC.Mem.load .Mint8unsigned m base.tags.block (j.val : Int) = some (.Vint 0)
  written : ∀ j : Fin 16, j.val < n →
    CC.Mem.load .Mint8unsigned m base.stack.block ((Arm64MemsetStoreExecution.index j).val : Int) =
      some (.Vint (byte.setWidth 32))

/-- Assemble the initial loop packet from observations on this actual heap. -/
def of_inputs {initial m : CC.Mem} {entry : HeaderLocal initial}
    (view : Arm64MemsetHeaderView.View initial m entry) (abi : TailLocal initial 6) (byte : BitVec 8)
    (resources : Arm64ProgramEntryResources.Resources initial m entry)
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry)
    (spAtBase : storage.spValue = (-32#64)) (le : CC.TempEnv)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (counter : le.get Arm64Program.___a64_lib_i = some (.Vlong 0))
    (length : le.get Arm64Program.___a64_lib_len = some (.Vlong 16))
    (value : le.get Arm64Program.___a64_lib_byte = some (.Vint (byte.setWidth 32)))
    (gpr : Arm64EntryMemory.gpr m.nextblock m (.Vptr entry.block 0) 0 =
      some (.Vlong (-32#64),.Vint ((4#8).setWidth 32)))
    (abiHeader : CC.Mem.load CC.Mptr m entry.block 704 = some (.Vptr abi.block 0))
    (abiKind : CC.Mem.load .Mint8unsigned m abi.block 0 = some (.Vint 2))
    (tagBytes : ∀ j : Fin 24, CC.Mem.load .Mint8unsigned m view.tags.block (j.val : Int) = some (.Vint 0)) :
    Invariant view abi byte 0 m le where
  view := view
  stackSame := rfl
  tagsSame := rfl
  resources := resources
  storage := storage
  spAtBase := spAtBase
  entryRead := hentry
  counter := counter
  length := length
  value := value
  gpr := gpr
  abiHeader := abiHeader
  abiKind := abiKind
  tagBytes := tagBytes
  written := by intro j impossible; omega

/-- The actual original initializer supplies all four loop temporary reads. -/
def initialized {initial m : CC.Mem} {entry : HeaderLocal initial}
    (view : Arm64MemsetHeaderView.View initial m entry) (abi : TailLocal initial 6) (mark : BitVec 32)
    (resources : Arm64ProgramEntryResources.Resources initial m entry)
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry)
    (spAtBase : storage.spValue = (-32#64))
    (gpr : Arm64EntryMemory.gpr m.nextblock m (.Vptr entry.block 0) 0 =
      some (.Vlong (-32#64),.Vint ((4#8).setWidth 32)))
    (abiHeader : CC.Mem.load CC.Mptr m entry.block 704 = some (.Vptr abi.block 0))
    (abiKind : CC.Mem.load .Mint8unsigned m abi.block 0 = some (.Vint 2))
    (tagBytes : ∀ j : Fin 24, CC.Mem.load .Mint8unsigned m view.tags.block (j.val : Int) = some (.Vint 0)) :
    Invariant view abi (Arm64MemsetLossSetup.byte mark) 0 m
      (Arm64MemsetLoop.initializedTemps entry.block (mark.setWidth 64) (16#64)) := by
  apply of_inputs view abi (Arm64MemsetLossSetup.byte mark) resources storage spAtBase _
    (gpr := gpr) (abiHeader := abiHeader) (abiKind := abiKind) (tagBytes := tagBytes)
  all_goals simp +decide only [Arm64MemsetLoop.initializedTemps,Arm64MemsetSource.readTemps,
    Arm64MemsetSource.byteTemps,Arm64MemsetSource.initialTemps,Arm64MemsetLossSetup.byte,
    CC.PTree.gso,CC.PTree.gss]

private theorem cells_other : ∀ tags,
    tableCellName tags (0 : Fin 31) ≠ tailLocalName 2 ∧
    tableCellName tags (0 : Fin 31) ≠ tailLocalName 0 := by decide +kernel

private theorem increment_word : ∀ i : Fin 16,
    BitVec.ofNat 64 i.val + (1#64) = BitVec.ofNat 64 (i.val + 1) := by decide +kernel

/-- One real loop iteration transports all current observations through both
actual stores. The next reader values follow typed allocation separation. -/
theorem step {initial seed m : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    (e : CC.Env) (k : CC.Cont) (i : Fin 16) {le : CC.TempEnv}
    (prior : Invariant base abi byte i.val m le) :
    ∃ after, ∃ _current : Invariant base abi byte (i.val + 1) after
        (Arm64MemsetIterationEntry.nextTemps prior.view prior.storage le i abi.block byte),
      CC.Star (CC.Step2 world) (.State handler Arm64MemsetLoop.loop k e le m) CC.E0
        (.State handler Arm64MemsetLoop.loop k e
          (Arm64MemsetIterationEntry.nextTemps prior.view prior.storage le i abi.block byte) after) ∧
      FrameBelow initial.nextblock m after ∧ after.access = m.access ∧ after.nextblock = m.nextblock ∧
      (∀ (chunk : CC.Chunk) (block : CC.Block) (offset : Int), block ≠ base.tags.block → block ≠ base.stack.block →
        CC.Mem.load chunk after block offset = CC.Mem.load chunk m block offset) := by
  have tags : ∀ j : Fin 24, CC.Mem.load .Mint8unsigned m prior.view.tags.block (j.val : Int) = some (.Vint 0) := by
    simpa only [prior.tagsSame] using prior.tagBytes
  obtain ⟨tagged,after,run,tagStore,byteStore,byteRead,frame,access,next,outside,_newView,
      resources,currentTags,_pointer,_spRead,otherBytes,_currentStorage⟩ :=
    Arm64MemsetIterationEntry.complete prior.view prior.resources prior.storage prior.spAtBase
      e le k i abi.block byte prior.entryRead prior.counter prior.length prior.value tags
      prior.gpr prior.abiHeader prior.abiKind
  have separate := (allocated_local_storage (CC.doAllocVariables_sound _ _ _ _ _ _
    (Prod.eta (allocation initial)).symm)).2
  have other (id : CC.Ident) (ty : CC.Ty) (block : CC.Block)
      (binding : (allocation initial).1.get id = some (block,ty))
      (notTag : id ≠ tailLocalName 2) (notStack : id ≠ tailLocalName 0)
      (chunk : CC.Chunk) (offset : Int) :
      CC.Mem.load chunk after block offset = CC.Mem.load chunk m block offset :=
    outside chunk block offset
      (separate _ _ _ _ binding prior.view.tags.binding notTag)
      (separate _ _ _ _ binding prior.view.stack.binding notStack)
  have entryOther := other _ _ _ entry.binding (by decide +kernel) (by decide +kernel)
  let view : Arm64MemsetHeaderView.View initial after entry :=
    ⟨prior.view.stack,prior.view.tags,(entryOther CC.Mptr 608).trans prior.view.stackPointer,
      (entryOther CC.Mptr 648).trans prior.view.tagPointer,
      (entryOther .Mint32 656).trans prior.view.capacity,(entryOther .Mint64 672).trans prior.view.bias⟩
  let storage := Arm64MemsetIterationStorage.storage prior.view i byte tagStore byteStore prior.storage
  have cellOther (tags : Bool) :
      CC.Mem.load (cellChunk tags) after ((prior.storage.tables tags).cellBlock 0) 0 =
        CC.Mem.load (cellChunk tags) m ((prior.storage.tables tags).cellBlock 0) 0 :=
    other _ _ _ ((prior.storage.tables tags).cellBinding 0)
      (cells_other tags).1 (cells_other tags).2 (cellChunk tags) 0
  have gpr : Arm64EntryMemory.gpr after.nextblock after (.Vptr entry.block 0) 0 =
      some (.Vlong (-32#64),.Vint ((4#8).setWidth 32)) := by
    have newWalk := Arm64RegisterWrite.storage_gpr storage (0 : Fin 31)
    have oldWalk := Arm64RegisterWrite.storage_gpr prior.storage (0 : Fin 31)
    simp only [Fin.val_zero] at newWalk oldWalk
    rw [newWalk]
    change (do
      let word ← CC.Mem.load .Mint64 after ((prior.storage.tables false).cellBlock 0) 0
      let tag ← CC.Mem.load .Mint8unsigned after ((prior.storage.tables true).cellBlock 0) 0
      pure (word,tag)) = _
    rw [show CC.Mem.load .Mint64 after ((prior.storage.tables false).cellBlock 0) 0 =
      CC.Mem.load .Mint64 m ((prior.storage.tables false).cellBlock 0) 0 from cellOther false]
    rw [show CC.Mem.load .Mint8unsigned after ((prior.storage.tables true).cellBlock 0) 0 =
      CC.Mem.load .Mint8unsigned m ((prior.storage.tables true).cellBlock 0) 0 from cellOther true]
    exact oldWalk.symm.trans prior.gpr
  have getters := Arm64MemsetIterationEntry.next_observations prior.view prior.storage le i abi.block byte
  let current : Invariant base abi byte (i.val + 1) after
      (Arm64MemsetIterationEntry.nextTemps prior.view prior.storage le i abi.block byte) := {
    view := view
    stackSame := prior.stackSame
    tagsSame := prior.tagsSame
    resources := resources
    storage := storage
    spAtBase := prior.spAtBase
    entryRead := getters.2.1.trans prior.entryRead
    counter := by simpa only [increment_word] using getters.1
    length := getters.2.2.1.trans prior.length
    value := getters.2.2.2.trans prior.value
    gpr := gpr
    abiHeader := (entryOther CC.Mptr 704).trans prior.abiHeader
    abiKind := (other _ _ _ abi.binding (by decide +kernel) (by decide +kernel) .Mint8unsigned 0).trans prior.abiKind
    tagBytes := by simpa only [prior.tagsSame] using currentTags
    written := by
      intro j bound
      by_cases same : j = i
      · subst j
        simpa only [prior.stackSame] using byteRead
      · have earlier : j.val < i.val := by
          have different : j.val ≠ i.val := by intro eq; exact same (Fin.ext eq)
          omega
        have kept := otherBytes j same
        rw [prior.stackSame] at kept
        exact kept.trans (prior.written j earlier)
  }
  refine ⟨after,current,run,frame,access,next,?_⟩
  intro chunk block offset notTag notStack
  exact outside chunk block offset (by simpa only [prior.tagsSame] using notTag)
    (by simpa only [prior.stackSame] using notStack)

/-- Execute n sequential original iterations, accumulating earlier real byte
readbacks on the current heap and preserving the original outside frame. -/
theorem iterations {initial seed before : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    (e : CC.Env) (k : CC.Cont) {le : CC.TempEnv}
    (start : Invariant base abi byte 0 before le) (n : Nat) (bound : n ≤ 16) :
    ∃ after nextLe, ∃ _current : Invariant base abi byte n after nextLe,
      CC.Star (CC.Step2 world) (.State handler Arm64MemsetLoop.loop k e le before) CC.E0
        (.State handler Arm64MemsetLoop.loop k e nextLe after) ∧
      FrameBelow initial.nextblock before after ∧ after.access = before.access ∧ after.nextblock = before.nextblock ∧
      (∀ (chunk : CC.Chunk) (block : CC.Block) (offset : Int), block ≠ base.tags.block → block ≠ base.stack.block →
        CC.Mem.load chunk after block offset = CC.Mem.load chunk before block offset) := by
  induction n with
  | zero => exact ⟨before,le,start,.refl _,FrameBelow.refl _ _,rfl,rfl,by intros; rfl⟩
  | succ n ih =>
    obtain ⟨middle,middleLe,prior,run,frame,access,next,outside⟩ := ih (by omega)
    let i : Fin 16 := ⟨n,by omega⟩
    obtain ⟨after,current,iteration,iterationFrame,iterationAccess,iterationNext,iterationOutside⟩ := step e k i prior
    refine ⟨after,_,current,?_,frame.trans iterationFrame,iterationAccess.trans access,iterationNext.trans next,?_⟩
    · simpa only [CC.E0,CC.Eapp,List.nil_append] using star_trans run iteration
    · intro chunk block offset notTag notStack
      exact (iterationOutside chunk block offset notTag notStack).trans (outside chunk block offset notTag notStack)

/-- All sixteen real byte-loop iterations and the original false guard exit
execute, with all sixteen readbacks and current resources on the final heap. -/
theorem execute {initial seed before : CC.Mem} {entry : HeaderLocal initial}
    {base : Arm64MemsetHeaderView.View initial seed entry} {abi : TailLocal initial 6} {byte : BitVec 8}
    (e : CC.Env) (k : CC.Cont) {le : CC.TempEnv}
    (start : Invariant base abi byte 0 before le) :
    ∃ after nextLe, ∃ _current : Invariant base abi byte 16 after nextLe,
      CC.Star (CC.Step2 world) (.State handler Arm64MemsetLoop.loop k e le before) CC.E0
        (.State handler .Sskip k e nextLe after) ∧
      (∀ j : Fin 16, CC.Mem.load .Mint8unsigned after base.stack.block
        ((Arm64MemsetStoreExecution.index j).val : Int) = some (.Vint (byte.setWidth 32))) ∧
      FrameBelow initial.nextblock before after ∧ after.access = before.access ∧ after.nextblock = before.nextblock ∧
      (∀ (chunk : CC.Chunk) (block : CC.Block) (offset : Int), block ≠ base.tags.block → block ≠ base.stack.block →
        CC.Mem.load chunk after block offset = CC.Mem.load chunk before block offset) := by
  obtain ⟨after,nextLe,current,run,frame,access,next,outside⟩ := iterations e k start 16 (by decide)
  have leave := Arm64MemsetLoop.guard_false e nextLe after k (16#64) (16#64)
    current.counter current.length (by decide +kernel)
  refine ⟨after,nextLe,current,?_,fun j => current.written j j.isLt,frame,access,next,outside⟩
  simpa only [CC.E0,CC.Eapp,List.nil_append] using star_trans run leave.sound

/-- Genuine caller input reads and the actual loop initializer reach the
original loop head, before its first guard, in162+4 source transitions. -/
theorem original_entry {initial before markWritten markAfter constantWritten constantAfter : CC.Mem}
    {entry : HeaderLocal initial} {storage : Arm64ProducerRegisterStorage.Storage initial before entry}
    {addresses : Arm64Registers.PointerOrigins} {origins : Reference.Provenance.AArch64.Origins}
    {prior next : Reference.AArch64.State} {priorK nextK : CC.Cont} (mark : BitVec 32)
    (first : Arm64MovImmediate.OrdinaryCall.Result storage 1 (mark.setWidth 64)
      addresses origins prior priorK markWritten markAfter)
    (bound : (allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (second : Arm64MovImmediate.OrdinaryCall.Result (first.storage bound) 2 (16#64)
      addresses origins next nextK constantWritten constantAfter) (k : CC.Cont) :
    InternalRun world 166 (.Callstate (.Internal handler) [.Vptr entry.block 0] k constantAfter)
      (.State handler Arm64MemsetLoop.loop
        (.Kseq Arm64MemsetLoop.effects (Arm64MemsetSource.continuation k))
        (Arm64MemsetSource.allocation constantAfter).1
        (Arm64MemsetLoop.initializedTemps entry.block (mark.setWidth 64) (16#64))
        (Arm64MemsetSource.allocation constantAfter).2) :=
  (Arm64MemsetInputs.original_reads mark first bound second k).trans
    (Arm64MemsetLoop.start (Arm64MemsetSource.allocation constantAfter).1
      (Arm64MemsetSource.allocation constantAfter).2 entry.block (mark.setWidth 64) (16#64)
      (Arm64MemsetSource.continuation k))

/-- The original full call executes allocation, real input reads, initializer,
all sixteen real byte iterations and the false guard, reaching the untouched
tag-transfer/clobber continuation. Current heap domains stay explicit. -/
theorem original {initial before markWritten markAfter constantWritten constantAfter : CC.Mem}
    {entry : HeaderLocal initial} {oldStorage : Arm64ProducerRegisterStorage.Storage initial before entry}
    {addresses : Arm64Registers.PointerOrigins} {origins : Reference.Provenance.AArch64.Origins}
    {prior next : Reference.AArch64.State} {priorK nextK : CC.Cont} (mark : BitVec 32)
    (first : Arm64MovImmediate.OrdinaryCall.Result oldStorage 1 (mark.setWidth 64)
      addresses origins prior priorK markWritten markAfter)
    (bound : (allocation initial).2.nextblock.toNat ≤ before.nextblock.toNat)
    (second : Arm64MovImmediate.OrdinaryCall.Result (first.storage bound) 2 (16#64)
      addresses origins next nextK constantWritten constantAfter)
    (view : Arm64MemsetHeaderView.View initial (Arm64MemsetSource.allocation constantAfter).2 entry)
    (abi : TailLocal initial 6)
    (resources : Arm64ProgramEntryResources.Resources initial (Arm64MemsetSource.allocation constantAfter).2 entry)
    (storage : Arm64ProducerRegisterStorage.Storage initial (Arm64MemsetSource.allocation constantAfter).2 entry)
    (spAtBase : storage.spValue = (-32#64))
    (gpr : Arm64EntryMemory.gpr (Arm64MemsetSource.allocation constantAfter).2.nextblock
      (Arm64MemsetSource.allocation constantAfter).2 (.Vptr entry.block 0) 0 =
      some (.Vlong (-32#64),.Vint ((4#8).setWidth 32)))
    (abiHeader : CC.Mem.load CC.Mptr (Arm64MemsetSource.allocation constantAfter).2 entry.block 704 = some (.Vptr abi.block 0))
    (abiKind : CC.Mem.load .Mint8unsigned (Arm64MemsetSource.allocation constantAfter).2 abi.block 0 = some (.Vint 2))
    (tagBytes : ∀ j : Fin 24, CC.Mem.load .Mint8unsigned (Arm64MemsetSource.allocation constantAfter).2
      view.tags.block (j.val : Int) = some (.Vint 0)) (k : CC.Cont) :
    ∃ after nextLe, ∃ _current : Invariant view abi (Arm64MemsetLossSetup.byte mark) 16 after nextLe,
      CC.Star (CC.Step2 world) (.Callstate (.Internal handler) [.Vptr entry.block 0] k constantAfter) CC.E0
        (.State handler .Sskip (.Kseq Arm64MemsetLoop.effects (Arm64MemsetSource.continuation k))
          (Arm64MemsetSource.allocation constantAfter).1 nextLe after) ∧
      (∀ j : Fin 16, CC.Mem.load .Mint8unsigned after view.stack.block
        ((Arm64MemsetStoreExecution.index j).val : Int) =
          some (.Vint ((Arm64MemsetLossSetup.byte mark).setWidth 32))) ∧
      FrameBelow initial.nextblock (Arm64MemsetSource.allocation constantAfter).2 after ∧
      after.access = (Arm64MemsetSource.allocation constantAfter).2.access ∧
      after.nextblock = (Arm64MemsetSource.allocation constantAfter).2.nextblock ∧
      (∀ (chunk : CC.Chunk) (block : CC.Block) (offset : Int), block ≠ view.tags.block → block ≠ view.stack.block →
        CC.Mem.load chunk after block offset =
          CC.Mem.load chunk (Arm64MemsetSource.allocation constantAfter).2 block offset) := by
  have entryRun := original_entry mark first bound second k
  let start := initialized view abi mark resources storage spAtBase gpr abiHeader abiKind tagBytes
  obtain ⟨after,nextLe,current,run,rest⟩ := execute (Arm64MemsetSource.allocation constantAfter).1
    (.Kseq Arm64MemsetLoop.effects (Arm64MemsetSource.continuation k)) start
  refine ⟨after,nextLe,current,?_,rest⟩
  simpa only [CC.E0,CC.Eapp,List.nil_append] using star_trans entryRun.sound run

end KProgFormal.ClightRefinement.Arm64MemsetWriteLoop
