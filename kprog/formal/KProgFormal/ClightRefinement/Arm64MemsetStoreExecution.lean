import KProgFormal.ClightRefinement.Arm64MemsetStoreRoute
import KProgFormal.ClightRefinement.Arm64MemsetTagWords

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemsetStoreExecution

open Arm64ProgramEntryAllocation (world)
open Arm64MemsetSource (handler)

def index (i : Fin 16) : Fin 160 := ⟨64 + i.val,by omega⟩

private theorem word_offset : ∀ i : Fin 16,
    Arm64MemsetTagWrite.offset (Arm64MemsetTagSource.tagOf (index i)) = 8 := by decide +kernel
private theorem cleared_zero (i : Fin 16) :
    Arm64MemsetTagWrite.cleared (Arm64MemsetTagSource.tagOf (index i)) 0 = 0 := by
  apply BitVec.eq_of_toNat_eq
  simp [Arm64MemsetTagWrite.cleared,BitVec.toNat_and]

/-- The actual source Resources derive writable stack/tag ranges from the
real allocation bindings and actual target sizes. -/
theorem ranges {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (view : Arm64MemsetHeaderView.View initial m entry)
    (resources : Arm64ProgramEntryResources.Resources initial m entry) :
    CC.Mem.rangePerm m view.tags.block 0 24 .Cur .Writable = true ∧
    CC.Mem.rangePerm m view.stack.block 0 160 .Cur .Writable = true := by
  have tagBinding := Arm64ProgramEntryAllocation.local_binding initial _ _ _ view.tags.binding
  have stackBinding := Arm64ProgramEntryAllocation.local_binding initial _ _ _ view.stack.binding
  have tagRange := resources.freeable _ _ tagBinding
  have stackRange := resources.freeable _ _ stackBinding
  have tagSize : CC.sizeof world.genv_cenv
      (Arm64ProgramEntryAllocation.localType Arm64Producer.stackTagType) = 24 := by decide +kernel
  have stackSize : CC.sizeof world.genv_cenv
      (Arm64ProgramEntryAllocation.localType (Arm64Producer.tailLocalType 0)) = 160 := by decide +kernel
  exact ⟨CC.Mem.rangePerm_implies (by simpa only [tagSize] using tagRange) (by decide),
    CC.Mem.rangePerm_implies (by simpa only [stackSize] using stackRange) (by decide)⟩

def temps {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (view : Arm64MemsetHeaderView.View initial m entry) (le : CC.TempEnv) (i : Fin 16) (byte : BitVec 8) : CC.TempEnv :=
  Arm64MemsetStackWrite.temps (Arm64MemsetStoreRoute.temps le i byte) (index i)
    view.tags.block view.stack.block 0 byte

/-- At every one of the original16 offsets, execute the real bias/index/
action route and BOTH original stores. Writable ranges, separation and initial
word8 are derived from actual resources, bindings and24 byte observations.
Every source continuation, actual store equation and readback remains. -/
theorem execute {initial m : CC.Mem} {entry : Arm64Producer.HeaderLocal initial}
    (view : Arm64MemsetHeaderView.View initial m entry)
    (resources : Arm64ProgramEntryResources.Resources initial m entry)
    (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont) (i : Fin 16) (byte : BitVec 8)
    (hentry : le.get Arm64Program._entry = some (.Vptr entry.block 0))
    (hoff : le.get Arm64Program.___a64_loss_off = some (.Vlong (Arm64MemsetStoreRoute.lossOffset i)))
    (hwidth : le.get Arm64Program.___a64_loss_width = some (.Vint 1))
    (hvalue : le.get Arm64Program.___a64_loss_value = some (.Vlong (byte.setWidth 64)))
    (tagBytes : ∀ j : Fin 24, CC.Mem.load .Mint8unsigned m view.tags.block (j.val : Int) = some (.Vint 0)) :
    ∃ tagged after,
      CC.Star (CC.Step2 world) (.State handler Arm64MemsetLossSetup.store k e le m) CC.E0
        (.State handler .Sskip (Arm64MemsetStoreRoute.continuation k) e (temps view le i byte) after) ∧
      CC.Mem.store .Mint64 m view.tags.block 8 (.Vlong 0) = some tagged ∧
      CC.Mem.store .Mint8unsigned tagged view.stack.block ((index i).val : Int) (.Vint (byte.setWidth 32)) = some after ∧
      CC.Mem.load .Mint8unsigned after view.stack.block ((index i).val : Int) = some (.Vint (byte.setWidth 32)) ∧
      CC.Mem.load .Mint64 after view.tags.block 8 = some (.Vlong 0) ∧
      FrameBelow initial.nextblock m after ∧ after.access = m.access ∧ after.nextblock = m.nextblock ∧
      (∀ (chunk : CC.Chunk) (block : CC.Block) (offset : Int), block ≠ view.tags.block → block ≠ view.stack.block →
        CC.Mem.load chunk after block offset = CC.Mem.load chunk m block offset) ∧
      Nonempty (Arm64MemsetHeaderView.View initial after entry) := by
  have route := Arm64MemsetStoreRoute.execute view e le k i byte hentry hoff hwidth hvalue
  have observed := Arm64MemsetStoreRoute.observations le i byte entry.block hentry
  have word := Arm64MemsetTagWords.original m view.tags.block tagBytes ⟨1,by decide⟩
  change CC.Mem.load .Mint64 m view.tags.block 8 = some (.Vlong 0) at word
  have writable := ranges view resources
  have allocation := CC.doAllocVariables_sound _ _ _ _ _ _
    (Prod.eta (Arm64Producer.allocation initial)).symm
  have owned := allocated_local_storage allocation
  have entrySeparate : entry.block ≠ view.tags.block :=
    owned.2 _ _ _ _ entry.binding view.tags.binding (by decide +kernel)
  have stackSeparate : view.tags.block ≠ view.stack.block :=
    owned.2 _ _ _ _ view.tags.binding view.stack.binding (by decide +kernel)
  have entryStackSeparate : entry.block ≠ view.stack.block :=
    owned.2 _ _ _ _ entry.binding view.stack.binding (by decide +kernel)
  have stackFresh := (owned.1 _ _ view.stack.binding).1
  obtain ⟨tagged,after,run,tagStored,byteStored,byteRead,tagRead,access,next,outside⟩ :=
    Arm64MemsetStackWrite.execute e (Arm64MemsetStoreRoute.temps le i byte) m
      (Arm64MemsetStoreRoute.continuation k) entry.block view.tags.block view.stack.block (index i) 0 byte
      observed.1 observed.2.1 observed.2.2.1 observed.2.2.2 view.tagPointer view.stackPointer
      (by rw [word_offset]; exact word) writable.1 writable.2 entrySeparate stackSeparate
  have zeroTagStore : CC.Mem.store .Mint64 m view.tags.block 8 (.Vlong 0) = some tagged := by
    simpa only [word_offset,cleared_zero] using tagStored
  have zeroTagRead : CC.Mem.load .Mint64 after view.tags.block 8 = some (.Vlong 0) := by
    simpa only [word_offset,cleared_zero] using tagRead
  have frame := (FrameBelow.store view.tags.fresh tagStored).trans (FrameBelow.store stackFresh byteStored)
  have headers (chunk : CC.Chunk) (offset : Int) := outside chunk entry.block offset entrySeparate entryStackSeparate
  have newView : Arm64MemsetHeaderView.View initial after entry :=
    ⟨view.stack,view.tags,(headers CC.Mptr 608).trans view.stackPointer,
      (headers CC.Mptr 648).trans view.tagPointer,(headers .Mint32 656).trans view.capacity,
      (headers .Mint64 672).trans view.bias⟩
  refine ⟨tagged,after,?_,zeroTagStore,byteStored,byteRead,zeroTagRead,frame,access,next,outside,⟨newView⟩⟩
  simpa only [temps,CC.E0,CC.Eapp,List.nil_append] using star_trans route.sound run

end KProgFormal.ClightRefinement.Arm64MemsetStoreExecution
