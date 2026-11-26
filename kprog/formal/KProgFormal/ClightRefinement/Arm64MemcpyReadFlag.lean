import KProgFormal.ClightRefinement.Arm64MemcpyReadCurrent

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64MemcpyReadFlag

open Arm64Producer (TailLocal HeaderLocal)
open Arm64ProgramEntryAllocation (world allocation)

private theorem actual_binding {initial : CC.Mem} (id : CC.Ident) (ty : CC.Ty) (block : CC.Block)
    (binding : (Arm64Producer.allocation initial).1.get id = some (block,ty))
    (name : Arm64ProgramEntryAllocation.localName id = id)
    (type : Arm64ProgramEntryAllocation.localType ty = ty) :
    (allocation initial).1.get id = some (block,ty) := by
  have actual := Arm64ProgramEntryAllocation.local_binding initial id block ty binding
  simpa only [name,type] using actual

private theorem setup_exec (initial before m1 m2 after : CC.Mem)
    (le : CC.TempEnv) (k : CC.Cont) (fb cb ab : CC.Block)
    (flag : (allocation initial).1.get Arm64Entry.___a64_sim_is_xdp = some (fb,CC.tuchar))
    (ctx : (allocation initial).1.get Arm64Entry.___a64_sim_helper_ctx = some (cb,CC.tptr CC.tvoid))
    (abi : (allocation initial).1.get Arm64Entry.___a64_sim_helper_abi_base = some (ab,CC.tptr CC.tvoid))
    (s0 : CC.Mem.store .Mint8unsigned before fb 0 (.Vint 0) = some m1)
    (s1 : CC.Mem.store CC.Mptr m1 cb 0 (.Vlong 0) = some m2)
    (s2 : CC.Mem.store CC.Mptr m2 ab 0 (.Vlong 0) = some after) :
    InternalRun world 9
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryPrefix.afterCacheStage
        k (allocation initial).1 le before)
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryInputs.registerStage
        k (allocation initial).1 le after) := by
  change CC.Mem.storev .Mint8unsigned before (.Vptr fb (0#64)) (.Vint (0#32)) = some m1 at s0
  change CC.Mem.storev CC.Mptr m1 (.Vptr cb (0#64)) (.Vlong (0#64)) = some m2 at s1
  change CC.Mem.storev CC.Mptr m2 (.Vptr ab (0#64)) (.Vlong (0#64)) = some after at s2
  rw [Arm64ProgramEntryInputs.setup_source]
  apply internalRun_of_steps
  all_goals simp +decide [Arm64Producer.setupAssignments,List.foldr,steps,InternalPath,InternalState,
    CC.doStep,CC.doEvalLvalue,CC.lvalOfVar,CC.doEvalExpr,CC.typeof,CC.doAssignLoc,CC.accessMode,
    CC.Cop.semCast,CC.Cop.classifyCast,CC.Cop.castIntInt,CC.Cop.castIntLong,
    CC.Integers.Int.signed,CC.Integers.MI.signed,CC.Integers.Int64.repr,CC.Integers.Int.repr,
    CC.Integers.MI.repr,CC.Integers.Int.zero_ext,CC.Integers.MI.zero_ext,
    CC.Integers.Ptrofs.zero,CC.Integers.MI.zero,CC.Archi.ptr64,CC.tptr,CC.tvoid,CC.tint,CC.tuchar,
    CC.E0,CC.Eapp,flag,ctx,abi,s0,s1,s2]

/-- The original three setup stores really initialize the flag byte to
zero. Its value is read back from those stores, not a later reader premise. -/
theorem initialized (initial before : CC.Mem) (le : CC.TempEnv) (k : CC.Cont)
    (cell : TailLocal initial 5)
    (access : before.access = (Arm64Producer.allocation initial).2.access) :
    ∃ after, InternalRun world 9
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryPrefix.afterCacheStage
        k (allocation initial).1 le before)
      (.State Arm64ProgramFixture.f_arm64_execute_compile Arm64ProgramEntryInputs.registerStage
        k (allocation initial).1 le after) ∧
      CC.Mem.load .Mint8unsigned after cell.block 0 = some (.Vint 0) ∧
      FrameBelow initial.nextblock before after ∧ after.access = before.access ∧
      after.nextblock = before.nextblock := by
  obtain ⟨fb,flag,fresh,flagWritable⟩ := Arm64Producer.scalar_local initial Arm64Entry.___a64_sim_is_xdp
    CC.tuchar .Mint8unsigned (by decide +kernel) rfl (by decide)
  have binding : (Arm64Producer.allocation initial).1.get Arm64Entry.___a64_sim_is_xdp =
      some (cell.block,CC.tuchar) := cell.binding
  have same : fb = cell.block := congrArg Prod.fst (Option.some.inj (flag.symm.trans binding))
  subst fb
  obtain ⟨cb,ctx,ctxFresh,ctxWritable⟩ := Arm64Producer.scalar_local initial Arm64Entry.___a64_sim_helper_ctx
    (CC.tptr CC.tvoid) CC.Mptr (by decide +kernel) rfl (by decide)
  obtain ⟨ab,abi,abiFresh,abiWritable⟩ := Arm64Producer.scalar_local initial Arm64Entry.___a64_sim_helper_abi_base
    (CC.tptr CC.tvoid) CC.Mptr (by decide +kernel) rfl (by decide)
  obtain ⟨m1,s0,a1⟩ := Arm64Producer.create_store initial before .Mint8unsigned cell.block (.Vint 0) access flagWritable
  obtain ⟨m2,s1,a2⟩ := Arm64Producer.create_store initial m1 CC.Mptr cb (.Vlong 0) a1 ctxWritable
  obtain ⟨after,s2,a3⟩ := Arm64Producer.create_store initial m2 CC.Mptr ab (.Vlong 0) a2 abiWritable
  have distinct := (allocated_local_storage
    (CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (Arm64Producer.allocation initial)).symm)).2
  have fc : cell.block ≠ cb := distinct _ _ _ _ binding ctx (by decide +kernel)
  have fa : cell.block ≠ ab := distinct _ _ _ _ binding abi (by decide +kernel)
  have zero : CC.Val.loadResult .Mint8unsigned (.Vint 0) = .Vint 0 := by decide +kernel
  have read := (CC.Mem.load_store_other s2 .Mint8unsigned cell.block 0 (.inl fa)).trans
    ((CC.Mem.load_store_other s1 .Mint8unsigned cell.block 0 (.inl fc)).trans (CC.Mem.load_store_same s0))
  refine ⟨after,?_,by simpa only [zero] using read,?_,a3.trans access.symm,?_⟩
  · exact setup_exec initial before m1 m2 after le k cell.block cb ab
      (actual_binding _ _ _ binding (by decide +kernel) rfl)
      (actual_binding _ _ _ ctx (by decide +kernel) rfl)
      (actual_binding _ _ _ abi (by decide +kernel) rfl) s0 s1 s2
  · exact ((FrameBelow.store fresh s0).trans (FrameBelow.store ctxFresh s1)).trans
      (FrameBelow.store abiFresh s2)
  · exact (CC.Mem.store_nextblock s2).trans ((CC.Mem.store_nextblock s1).trans (CC.Mem.store_nextblock s0))

/-- The real sixteen-field header initializer supplies its flag pointer.
The actual initialized byte survives the original intervening local frame. -/
theorem of_header {initial initialized memory : CC.Mem} (entry : HeaderLocal initial)
    (sources : (i : Fin 9) → TailLocal initial i)
    (reads : ∀ i, CC.Mem.load (Arm64Producer.tailChunk i) memory entry.block (Arm64Producer.tailOffset i) =
      some (Arm64ProgramEntryTail.actualValue sources i))
    (zero : CC.Mem.load .Mint8unsigned initialized (sources 5).block 0 = some (.Vint 0))
    (kept : CC.Mem.load .Mint8unsigned memory (sources 5).block 0 =
      CC.Mem.load .Mint8unsigned initialized (sources 5).block 0) :
    Arm64MemcpyReadCurrent.Flag entry (sources 5) (0#8) memory := by
  refine ⟨?_,?_⟩
  · have header := reads ⟨12,by decide⟩
    exact header
  · exact kept.trans zero

end KProgFormal.ClightRefinement.Arm64MemcpyReadFlag
