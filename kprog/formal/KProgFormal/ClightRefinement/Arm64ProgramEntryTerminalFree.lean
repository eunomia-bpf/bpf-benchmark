import KProgFormal.ClightRefinement.Arm64ProgramEntryTerminalRead

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryTerminalFree
open Arm64Producer (HeaderLocal HeaderSourceLocal)
open Arm64ProgramEntryAllocation (world allocation)

/-- Real original function freeList releases every original local range,
retains contents/frontier and protects the existing caller blocks. -/
structure FreeResult (initial current after : CC.Mem) : Prop where
  freed : CC.Mem.freeList current (CC.blocksOfEnv world.genv_cenv (allocation initial).1) = some after
  caller : FrameBelow initial.nextblock current after
  contents : after.contents = current.contents
  nextblock : after.nextblock = current.nextblock
  released : ∀ row ∈ CC.blocksOfEnv world.genv_cenv (allocation initial).1, ∀ ofs,
    row.2.1 ≤ ofs → ofs < row.2.2 → ∀ kind permission, CC.Mem.perm after row.1 ofs kind permission = false

theorem free {initial current : CC.Mem} {entry : HeaderLocal initial}
    (resources : Arm64ProgramEntryResources.Resources initial current entry) : ∃ after, FreeResult initial current after := by
  have allocated := CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation initial)).symm
  obtain ⟨after,freed,caller,contents,next,released⟩ := deallocate_live_locals allocated resources.freeable
  exact ⟨after,freed,caller,contents,next,released⟩

theorem return_type : Arm64ProgramFixture.f_arm64_execute_compile.fn_return = CC.tint := rfl

private theorem cast_uint (value : BitVec 64) (m : CC.Mem) :
    CC.Cop.semCast (.Vlong value) CC.tulong CC.tuint m = some (.Vint (value.setWidth 32)) := by
  have widthEq : BitVec.ofNat 32 value.toNat = value.setWidth 32 := by
    apply BitVec.eq_of_toNat_eq
    simp only [BitVec.toNat_ofNat,BitVec.toNat_setWidth]
  simp +decide only [CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntInt,CC.typeconv,CC.removeAttributes,CC.tattr,
    CC.tuint,CC.tulong,CC.Integers.Int.repr,CC.Integers.Int64.unsigned,CC.Integers.MI.repr,CC.Integers.MI.unsigned,
    BitVec.ofInt_natCast,CC.Archi.ptr64,ite_true,ite_false]
  rw [widthEq]

/-- The actual uint32 return expression is evaluated before the real imported
freeList. The source uint32 expression is converted to its actual declared
signed32 function return type, retaining the original low32 bits. -/
theorem return_step {initial current after : CC.Mem} (le : CC.TempEnv) (k : CC.Cont) (value : BitVec 64)
    (read : le.get Arm64ProgramFixture._t'148 = some (.Vlong value)) (freed : FreeResult initial current after) :
    CC.Step2 world (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryTerminalLoop.ret k
      (allocation initial).1 le current) CC.E0
      (.Returnstate (.Vint (value.setWidth 32)) (CC.callCont k) after) := by
  have evaluated : CC.doEvalExpr world (allocation initial).1 le current
      (.Ecast (.Etempvar Arm64ProgramFixture._t'148 CC.tulong) CC.tuint) = some (.Vint (value.setWidth 32)) := by
    simp only [CC.doEvalExpr,read,CC.typeof,cast_uint]
  rw [Arm64ProgramEntryTerminalLoop.return_source]
  apply CC.Step.return_1 (v := .Vint (value.setWidth 32))
  · exact CC.doEvalExpr_sound _ _ _ _ _ _ evaluated
  · rfl
  · exact freed.freed

/-- Release the SAME current live producer locals at the original Sreturn. -/
theorem invoke {initial current : CC.Mem} {entry : HeaderLocal initial}
    (resources : Arm64ProgramEntryResources.Resources initial current entry) (le : CC.TempEnv) (k : CC.Cont) (value : BitVec 64)
    (read : le.get Arm64ProgramFixture._t'148 = some (.Vlong value)) :
    ∃ after, FreeResult initial current after ∧ InternalRun world 1
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryTerminalLoop.ret k (allocation initial).1 le current)
      (.Returnstate (.Vint (value.setWidth 32)) (CC.callCont k) after) := by
  obtain ⟨after,freed⟩ := free resources
  exact ⟨after,freed,.step (by rw [Arm64ProgramEntryTerminalLoop.return_source]; trivial)
    (return_step le k value read freed) (.refl _)⟩

/-- Complete original SP check, actual read0/helper/caller, uint32 cast and
function return/freeList run86 transitions on the same terminal memory. -/
theorem execute {initial current : CC.Mem} (entry : HeaderLocal initial) (sp : HeaderSourceLocal initial 5)
    (resources : Arm64ProgramEntryResources.Resources initial current entry)
    (le : CC.TempEnv) (k : CC.Cont) (value : BitVec 64)
    (spRead : CC.Mem.load .Mint64 current sp.block 0 = some (.Vlong 0))
    (observed : Arm64EntryMemory.gpr current.nextblock current (.Vptr entry.block 0) 0 = some (.Vlong value,.Vint (0#32))) :
    ∃ after, FreeResult initial current after ∧ InternalRun world 86
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryTerminalStores.tail k (allocation initial).1 le current)
      (.Returnstate (.Vint (value.setWidth 32)) (CC.callCont k) after) := by
  have read := Arm64ProgramEntryTerminalRead.execute entry sp le current k value spRead observed
  obtain ⟨after,freed,returned⟩ := invoke resources
    (Arm64ProgramEntryTerminalRead.temps (Arm64ProgramEntryTerminalLoop.temps le) value)
    (Arm64ProgramEntryTerminalLoop.loopCont k) value (by exact CC.PTree.gss _ _ _)
  exact ⟨after,freed,read.trans returned⟩

end KProgFormal.ClightRefinement.Arm64ProgramEntryTerminalFree
