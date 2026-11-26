import KProgFormal.ClightRefinement.Arm64MemsetIterationAdvance

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemsetIterationEntry

open Arm64ProgramEntryAllocation (world)
open Arm64MemsetSource (handler)

private theorem abi_temps (le : CC.TempEnv) (abi : CC.Block) :
    Arm64MemsetAbiRead.temps le abi (2#8) =
      ((le.set Arm64Program._t'172 (.Vptr abi 0)).set Arm64Program._t'173 (.Vint 2)).set
        Arm64Program._t'67 (.Vint 0) := rfl

def tagTemps {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry) (le : CC.TempEnv) (i : Fin 16) : CC.TempEnv :=
  Arm64MemsetTagRead.finalTemps (Arm64MemsetStackSetup.temps le (BitVec.ofNat 64 i.val))
    (storage.tables true).tableBlock ((storage.tables true).cellBlock 0) (4#8)

def pointerTemps {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry) (le : CC.TempEnv)
    (i : Fin 16) (abi : CC.Block) : CC.TempEnv :=
  Arm64MemsetStackRoute.temps
    (Arm64MemsetAbiRead.temps (Arm64MemsetArmSelect.temps (tagTemps storage le i)) abi (2#8))
    storage.sp.block storage.spValue

def lossTemps {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry) (le : CC.TempEnv)
    (i : Fin 16) (abi : CC.Block) : CC.TempEnv :=
  Arm64MemsetPointerRoute.temps
    (Arm64MemsetPointerRoute.readTemps (Arm64MemsetPointerRoute.regTemps (pointerTemps storage le i abi))
      (storage.tables false).tableBlock ((storage.tables false).cellBlock 0) (-32#64)) (-32#64)

def temps {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry) (le : CC.TempEnv)
    (i : Fin 16) (abi : CC.Block) (byte : BitVec 8) : CC.TempEnv :=
  Arm64MemsetLossSetup.temps (lossTemps storage le i abi) (Arm64MemsetStoreRoute.lossOffset i) byte

private theorem tag_inputs {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry) (le : CC.TempEnv) (i : Fin 16) :
    (tagTemps storage le i).get Arm64Program._entry = le.get Arm64Program._entry ∧
    (tagTemps storage le i).get Arm64Program.___a64_mwr_tag = some (.Vint ((4#8).setWidth 32)) := by
  simp +decide only [tagTemps,Arm64MemsetTagRead.finalTemps,Arm64MemsetTagRead.temps,CC.PTree.gso,CC.PTree.gss]
  exact ⟨(Arm64MemsetStackSetup.selection le (BitVec.ofNat 64 i.val)).1,trivial⟩

private theorem pointer_inputs {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry) (le : CC.TempEnv) (i : Fin 16) (abi : CC.Block) :
    (pointerTemps storage le i abi).get Arm64Program._entry = le.get Arm64Program._entry ∧
    (pointerTemps storage le i abi).get Arm64Program.___a64_mwr_bsrc = some (.Vint 1) := by
  simp +decide only [pointerTemps,Arm64MemsetStackRoute.temps,Arm64MemsetStackRoute.selectedTemps,
    abi_temps,Arm64MemsetArmSelect.temps,CC.PTree.gso,CC.PTree.gss]
  exact ⟨(tag_inputs storage le i).1,trivial⟩

private theorem tag_loop {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry) (le : CC.TempEnv) (i : Fin 16) :
    (tagTemps storage le i).get Arm64Program.___a64_lib_i = le.get Arm64Program.___a64_lib_i ∧
    (tagTemps storage le i).get Arm64Program.___a64_lib_len = le.get Arm64Program.___a64_lib_len ∧
    (tagTemps storage le i).get Arm64Program.___a64_lib_byte = le.get Arm64Program.___a64_lib_byte := by
  simp +decide only [tagTemps,Arm64MemsetTagRead.finalTemps,Arm64MemsetTagRead.temps,CC.PTree.gso]
  have kept := Arm64MemsetStackSetup.temps_loop le (BitVec.ofNat 64 i.val)
  exact ⟨kept.1,kept.2.1,Arm64MemsetStackSetup.byte_preserved le (BitVec.ofNat 64 i.val)⟩

private theorem pointer_loop {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry) (le : CC.TempEnv) (i : Fin 16) (abi : CC.Block) :
    (pointerTemps storage le i abi).get Arm64Program.___a64_lib_i = le.get Arm64Program.___a64_lib_i ∧
    (pointerTemps storage le i abi).get Arm64Program.___a64_lib_len = le.get Arm64Program.___a64_lib_len ∧
    (pointerTemps storage le i abi).get Arm64Program.___a64_lib_byte = le.get Arm64Program.___a64_lib_byte := by
  simp +decide only [pointerTemps,Arm64MemsetStackRoute.temps,Arm64MemsetStackRoute.selectedTemps,abi_temps,Arm64MemsetArmSelect.temps,CC.PTree.gso]
  exact tag_loop storage le i

private theorem loss_loop {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry) (le : CC.TempEnv) (i : Fin 16) (abi : CC.Block) :
    (lossTemps storage le i abi).get Arm64Program.___a64_lib_i = le.get Arm64Program.___a64_lib_i ∧
    (lossTemps storage le i abi).get Arm64Program.___a64_lib_len = le.get Arm64Program.___a64_lib_len ∧
    (lossTemps storage le i abi).get Arm64Program.___a64_lib_byte = le.get Arm64Program.___a64_lib_byte := by
  simp +decide only [lossTemps,Arm64MemsetPointerRoute.temps,Arm64MemsetPointerRoute.readTemps,Arm64MemsetPointerRoute.regTemps,CC.PTree.gso]
  exact pointer_loop storage le i abi

/-- The original true for-loop guard, address setup, actual R0 tag and word
loads, arm/ABI/SP routing and loss setup reach the genuine store body. All187
transitions execute on the same current heap at every original byte counter. -/
theorem execute {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry)
    (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (i : Fin 16) (abi : CC.Block) (byte : BitVec 8)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (hi : le.get Arm64Program.___a64_lib_i = some (.Vlong (BitVec.ofNat 64 i.val)))
    (hlen : le.get Arm64Program.___a64_lib_len = some (.Vlong 16))
    (hbyte : le.get Arm64Program.___a64_lib_byte = some (.Vint (byte.setWidth 32)))
    (gpr : Arm64EntryMemory.gpr m.nextblock m (.Vptr entry.block 0) 0 =
      some (.Vlong (-32#64),.Vint ((4#8).setWidth 32)))
    (header : CC.Mem.load CC.Mptr m entry.block 704 = some (.Vptr abi 0))
    (kind : CC.Mem.load .Mint8unsigned m abi 0 = some (.Vint 2)) :
    InternalRun world 187 (.State handler Arm64MemsetLoop.loop k e le m)
      (.State handler Arm64MemsetLossSetup.store
        (Arm64MemsetLossSetup.continuation (Arm64MemsetIterationAdvance.continuation k)) e
        (temps storage le i abi byte) m) := by
  have less : (BitVec.ofNat 64 i.val).ult (16#64) = true := by
    have all : ∀ j : Fin 16, (BitVec.ofNat 64 j.val).ult (16#64) = true := by decide +kernel
    exact all i
  have guard := Arm64MemsetLoop.guard_true e le m k (BitVec.ofNat 64 i.val) (16#64) hi hlen less
  have setup := Arm64MemsetStackSetup.to_tag e le m (Arm64MemsetLoop.writeCont k) (BitVec.ofNat 64 i.val) hi
  have selected := Arm64MemsetStackSetup.selection le (BitVec.ofNat 64 i.val)
  have tag := Arm64MemsetTagRead.complete storage e (Arm64MemsetStackSetup.temps le (BitVec.ofNat 64 i.val))
    (Arm64MemsetLoop.writeCont k) (.Vlong (-32#64)) (4#8) (selected.1.trans hentry) selected.2 gpr
  have tagged := (tag_inputs storage le i).2
  have arm := Arm64MemsetArmSelect.execute e (tagTemps storage le i) m
    (Arm64MemsetIterationAdvance.continuation k) tagged
  have abiEntry : (Arm64MemsetArmSelect.temps (tagTemps storage le i)).get Arm64Program._entry = some (.Vptr entry.block 0) := by
    simpa +decide only [Arm64MemsetArmSelect.temps,CC.PTree.gso] using (tag_inputs storage le i).1.trans hentry
  have abiTag : (Arm64MemsetArmSelect.temps (tagTemps storage le i)).get Arm64Program.___a64_mwr_tag = some (.Vint ((4#8).setWidth 32)) := by
    simpa +decide only [Arm64MemsetArmSelect.temps,CC.PTree.gso] using tagged
  have readAbi := Arm64MemsetAbiRead.execute e (Arm64MemsetArmSelect.temps (tagTemps storage le i)) m
    (Arm64MemsetIterationAdvance.continuation k) entry.block abi (2#8) abiEntry abiTag header kind
  have spEntry : (Arm64MemsetAbiRead.temps (Arm64MemsetArmSelect.temps (tagTemps storage le i)) abi (2#8)).get Arm64Program._entry = some (.Vptr entry.block 0) := by
    simpa +decide only [abi_temps,CC.PTree.gso] using abiEntry
  have spArm : (Arm64MemsetAbiRead.temps (Arm64MemsetArmSelect.temps (tagTemps storage le i)) abi (2#8)).get Arm64Program.___a64_mwr_arm = some (.Vint 0) := by
    simp +decide only [abi_temps,Arm64MemsetArmSelect.temps,CC.PTree.gso,CC.PTree.gss]
  have sp := Arm64MemsetStackRoute.execute storage e _ (Arm64MemsetIterationAdvance.continuation k) spEntry spArm
  have pointer := Arm64MemsetPointerRoute.execute storage (-32#64) (4#8) e
    (pointerTemps storage le i abi) (Arm64MemsetIterationAdvance.continuation k)
    ((pointer_inputs storage le i abi).1.trans hentry) (pointer_inputs storage le i abi).2 gpr
  have base : (lossTemps storage le i abi).get Arm64Program.___a64_mwr_base = some (.Vlong (-32#64)) := by
    simp only [lossTemps,Arm64MemsetPointerRoute.temps,CC.PTree.gss]
  have offset : (lossTemps storage le i abi).get Arm64Program.___a64_mwr_off = some (.Vlong (BitVec.ofNat 64 i.val)) := by
    simp +decide only [lossTemps,Arm64MemsetPointerRoute.temps,Arm64MemsetPointerRoute.readTemps,
      Arm64MemsetPointerRoute.regTemps,pointerTemps,Arm64MemsetStackRoute.temps,Arm64MemsetStackRoute.selectedTemps,
      abi_temps,Arm64MemsetArmSelect.temps,tagTemps,Arm64MemsetTagRead.finalTemps,Arm64MemsetTagRead.temps,
      CC.PTree.gso]
    exact (Arm64MemsetStackSetup.temps_loop le (BitVec.ofNat 64 i.val)).2.2
  have value : (lossTemps storage le i abi).get Arm64Program.___a64_lib_byte = some (.Vint (byte.setWidth 32)) := by
    simp +decide only [lossTemps,Arm64MemsetPointerRoute.temps,Arm64MemsetPointerRoute.readTemps,
      Arm64MemsetPointerRoute.regTemps,pointerTemps,Arm64MemsetStackRoute.temps,Arm64MemsetStackRoute.selectedTemps,
      abi_temps,Arm64MemsetArmSelect.temps,tagTemps,Arm64MemsetTagRead.finalTemps,Arm64MemsetTagRead.temps,
      CC.PTree.gso]
    exact (Arm64MemsetStackSetup.byte_preserved le (BitVec.ofNat 64 i.val)).trans hbyte
  have loss := Arm64MemsetLossSetup.execute e (lossTemps storage le i abi) m
    (Arm64MemsetIterationAdvance.continuation k) (-32#64) (BitVec.ofNat 64 i.val) byte base offset value
  exact ((((((guard.trans setup).trans tag).trans arm).trans readAbi).trans sp).trans pointer).trans loss

private theorem loss_assignments (le : CC.TempEnv) (off : BitVec 64) (byte : BitVec 8) :
    (Arm64MemsetLossSetup.temps le off byte).get Arm64Program._entry = le.get Arm64Program._entry ∧
    (Arm64MemsetLossSetup.temps le off byte).get Arm64Program.___a64_lib_i = le.get Arm64Program.___a64_lib_i ∧
    (Arm64MemsetLossSetup.temps le off byte).get Arm64Program.___a64_lib_len = le.get Arm64Program.___a64_lib_len ∧
    (Arm64MemsetLossSetup.temps le off byte).get Arm64Program.___a64_lib_byte = le.get Arm64Program.___a64_lib_byte ∧
    (Arm64MemsetLossSetup.temps le off byte).get Arm64Program.___a64_loss_off = some (.Vlong off) ∧
    (Arm64MemsetLossSetup.temps le off byte).get Arm64Program.___a64_loss_width = some (.Vint 1) ∧
    (Arm64MemsetLossSetup.temps le off byte).get Arm64Program.___a64_loss_value = some (.Vlong (byte.setWidth 64)) := by
  refine ⟨?_,?_,?_,?_,?_,?_,?_⟩
  · have other0 : Arm64Program.___a64_loss_value ≠ Arm64Program._entry := by decide +kernel
    have other1 : Arm64Program.___a64_loss_width ≠ Arm64Program._entry := by decide +kernel
    have other2 : Arm64Program.___a64_loss_off ≠ Arm64Program._entry := by decide +kernel
    simp only [Arm64MemsetLossSetup.temps,CC.PTree.gss,CC.PTree.gso _ _ _ _ other0,CC.PTree.gso _ _ _ _ other1,CC.PTree.gso _ _ _ _ other2]
  · have other0 : Arm64Program.___a64_loss_value ≠ Arm64Program.___a64_lib_i := by decide +kernel
    have other1 : Arm64Program.___a64_loss_width ≠ Arm64Program.___a64_lib_i := by decide +kernel
    have other2 : Arm64Program.___a64_loss_off ≠ Arm64Program.___a64_lib_i := by decide +kernel
    simp only [Arm64MemsetLossSetup.temps,CC.PTree.gss,CC.PTree.gso _ _ _ _ other0,CC.PTree.gso _ _ _ _ other1,CC.PTree.gso _ _ _ _ other2]
  · have other0 : Arm64Program.___a64_loss_value ≠ Arm64Program.___a64_lib_len := by decide +kernel
    have other1 : Arm64Program.___a64_loss_width ≠ Arm64Program.___a64_lib_len := by decide +kernel
    have other2 : Arm64Program.___a64_loss_off ≠ Arm64Program.___a64_lib_len := by decide +kernel
    simp only [Arm64MemsetLossSetup.temps,CC.PTree.gss,CC.PTree.gso _ _ _ _ other0,CC.PTree.gso _ _ _ _ other1,CC.PTree.gso _ _ _ _ other2]
  · have other0 : Arm64Program.___a64_loss_value ≠ Arm64Program.___a64_lib_byte := by decide +kernel
    have other1 : Arm64Program.___a64_loss_width ≠ Arm64Program.___a64_lib_byte := by decide +kernel
    have other2 : Arm64Program.___a64_loss_off ≠ Arm64Program.___a64_lib_byte := by decide +kernel
    simp only [Arm64MemsetLossSetup.temps,CC.PTree.gss,CC.PTree.gso _ _ _ _ other0,CC.PTree.gso _ _ _ _ other1,CC.PTree.gso _ _ _ _ other2]
  · have other0 : Arm64Program.___a64_loss_value ≠ Arm64Program.___a64_loss_off := by decide +kernel
    have other1 : Arm64Program.___a64_loss_width ≠ Arm64Program.___a64_loss_off := by decide +kernel
    simp only [Arm64MemsetLossSetup.temps,CC.PTree.gss,CC.PTree.gso _ _ _ _ other0,CC.PTree.gso _ _ _ _ other1]
  · have other0 : Arm64Program.___a64_loss_value ≠ Arm64Program.___a64_loss_width := by decide +kernel
    simp only [Arm64MemsetLossSetup.temps,CC.PTree.gss,CC.PTree.gso _ _ _ _ other0]
  · simp only [Arm64MemsetLossSetup.temps,CC.PTree.gss]

/-- The actual187-step source entry retains the same loop inputs and entry
pointer, and establishes exactly the real offset, width and byte operands. -/
theorem observations {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry) (le : CC.TempEnv)
    (i : Fin 16) (abi : CC.Block) (byte : BitVec 8) :
    (temps storage le i abi byte).get Arm64Program._entry = le.get Arm64Program._entry ∧
    (temps storage le i abi byte).get Arm64Program.___a64_lib_i = le.get Arm64Program.___a64_lib_i ∧
    (temps storage le i abi byte).get Arm64Program.___a64_lib_len = le.get Arm64Program.___a64_lib_len ∧
    (temps storage le i abi byte).get Arm64Program.___a64_lib_byte = le.get Arm64Program.___a64_lib_byte ∧
    (temps storage le i abi byte).get Arm64Program.___a64_loss_off = some (.Vlong (Arm64MemsetStoreRoute.lossOffset i)) ∧
    (temps storage le i abi byte).get Arm64Program.___a64_loss_width = some (.Vint 1) ∧
    (temps storage le i abi byte).get Arm64Program.___a64_loss_value = some (.Vlong (byte.setWidth 64)) := by
  have kept := loss_loop storage le i abi
  have entryKept : (lossTemps storage le i abi).get Arm64Program._entry = le.get Arm64Program._entry := by
    simp +decide only [lossTemps,Arm64MemsetPointerRoute.temps,Arm64MemsetPointerRoute.readTemps,
      Arm64MemsetPointerRoute.regTemps,CC.PTree.gso]
    exact (pointer_inputs storage le i abi).1
  have assigned := loss_assignments (lossTemps storage le i abi) (Arm64MemsetStoreRoute.lossOffset i) byte
  exact ⟨assigned.1.trans entryKept,assigned.2.1.trans kept.1,
    assigned.2.2.1.trans kept.2.1,assigned.2.2.2.1.trans kept.2.2,
    assigned.2.2.2.2⟩

def nextTemps {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (view : Arm64MemsetHeaderView.View initial m entry)
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry) (le : CC.TempEnv)
    (i : Fin 16) (abi : CC.Block) (byte : BitVec 8) : CC.TempEnv :=
  (Arm64MemsetIterationAdvance.temps view (temps storage le i abi byte) i byte storage.sp.block).set
    Arm64Program.___a64_lib_i (.Vlong (BitVec.ofNat 64 i.val + (1#64)))

/-- The complete iteration uses the same source entry, length and byte,
with exactly the incremented original unsigned loop counter. -/
theorem next_observations {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (view : Arm64MemsetHeaderView.View initial m entry)
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry) (le : CC.TempEnv)
    (i : Fin 16) (abi : CC.Block) (byte : BitVec 8) :
    (nextTemps view storage le i abi byte).get Arm64Program.___a64_lib_i =
      some (.Vlong (BitVec.ofNat 64 i.val + (1#64))) ∧
    (nextTemps view storage le i abi byte).get Arm64Program._entry = le.get Arm64Program._entry ∧
    (nextTemps view storage le i abi byte).get Arm64Program.___a64_lib_len = le.get Arm64Program.___a64_lib_len ∧
    (nextTemps view storage le i abi byte).get Arm64Program.___a64_lib_byte = le.get Arm64Program.___a64_lib_byte := by
  have back := Arm64MemsetIterationAdvance.next_observations view (temps storage le i abi byte) i byte storage.sp.block
  have entered := observations storage le i abi byte
  exact ⟨back.1,back.2.1.trans entered.1,back.2.2.1.trans entered.2.2.1,
    back.2.2.2.trans entered.2.2.2.1⟩

/-- A complete real for-loop iteration: original guard/setup/reads/ABI,
both source stores, actual SP=-32 exits and the original counter backedge. -/
theorem complete {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (view : Arm64MemsetHeaderView.View initial m entry)
    (resources : Arm64ProgramEntryResources.Resources initial m entry)
    (storage : Arm64ProducerRegisterStorage.Storage initial m entry)
    (spAtBase : storage.spValue = (-32#64))
    (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (i : Fin 16) (abi : CC.Block) (byte : BitVec 8)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (hi : le.get Arm64Program.___a64_lib_i = some (.Vlong (BitVec.ofNat 64 i.val)))
    (hlen : le.get Arm64Program.___a64_lib_len = some (.Vlong 16))
    (hbyte : le.get Arm64Program.___a64_lib_byte = some (.Vint (byte.setWidth 32)))
    (tagBytes : ∀ j : Fin 24, CC.Mem.load .Mint8unsigned m view.tags.block (j.val : Int) = some (.Vint 0))
    (gpr : Arm64EntryMemory.gpr m.nextblock m (.Vptr entry.block 0) 0 =
      some (.Vlong (-32#64),.Vint ((4#8).setWidth 32)))
    (header : CC.Mem.load CC.Mptr m entry.block 704 = some (.Vptr abi 0))
    (kind : CC.Mem.load .Mint8unsigned m abi 0 = some (.Vint 2)) :
    ∃ tagged after,
      CC.Star (CC.Step2 world)
        (.State handler Arm64MemsetLoop.loop k e le m) CC.E0
        (.State handler Arm64MemsetLoop.loop k e
          (nextTemps view storage le i abi byte) after) ∧
      CC.Mem.store .Mint64 m view.tags.block 8 (.Vlong 0) = some tagged ∧
      CC.Mem.store .Mint8unsigned tagged view.stack.block ((Arm64MemsetStoreExecution.index i).val : Int)
        (.Vint (byte.setWidth 32)) = some after ∧
      CC.Mem.load .Mint8unsigned after view.stack.block ((Arm64MemsetStoreExecution.index i).val : Int) = some (.Vint (byte.setWidth 32)) ∧
      FrameBelow initial.nextblock m after ∧ after.access = m.access ∧ after.nextblock = m.nextblock ∧
      (∀ (chunk : CC.Chunk) (block : CC.Block) (offset : Int), block ≠ view.tags.block → block ≠ view.stack.block →
        CC.Mem.load chunk after block offset = CC.Mem.load chunk m block offset) ∧
      Nonempty (Arm64MemsetHeaderView.View initial after entry) ∧
      Arm64ProgramEntryResources.Resources initial after entry ∧
      (∀ j : Fin 24, CC.Mem.load .Mint8unsigned after view.tags.block (j.val : Int) = some (.Vint 0)) ∧
      CC.Mem.load CC.Mptr after entry.block 40 = some (.Vptr storage.sp.block 0) ∧
      CC.Mem.load .Mint64 after storage.sp.block 0 = some (.Vlong (-32#64)) ∧
      (∀ j : Fin 16, j ≠ i →
        CC.Mem.load .Mint8unsigned after view.stack.block ((Arm64MemsetStoreExecution.index j).val : Int) =
          CC.Mem.load .Mint8unsigned m view.stack.block ((Arm64MemsetStoreExecution.index j).val : Int)) ∧
      ∃ current : Arm64ProducerRegisterStorage.Storage initial after entry,
        current.spValue = (-32#64) := by
  have entered := execute storage e le k i abi byte hentry hi hlen hbyte gpr header kind
  have inputs := observations storage le i abi byte
  obtain ⟨tagged,after,run,rest⟩ := Arm64MemsetIterationAdvance.execute view resources storage spAtBase
    e (temps storage le i abi byte) k i byte (inputs.1.trans hentry) (inputs.2.1.trans hi)
    inputs.2.2.2.2.1 inputs.2.2.2.2.2.1 inputs.2.2.2.2.2.2 tagBytes
  refine ⟨tagged,after,?_,rest⟩
  simpa only [nextTemps,CC.E0,CC.Eapp,List.nil_append] using star_trans entered.sound run

end KProgFormal.ClightRefinement.Arm64MemsetIterationEntry
