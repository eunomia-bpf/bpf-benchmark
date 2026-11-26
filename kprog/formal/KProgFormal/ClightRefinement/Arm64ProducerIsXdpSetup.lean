import KProgFormal.ClightRefinement.Arm64MemcpyReadCurrent

set_option Elab.async false
set_option linter.unusedSimpArgs false

namespace KProgFormal.ClightRefinement.Arm64ProducerIsXdpSetup

open Arm64Producer (TailLocal setupAssignments setupNames)

private theorem same_end {ge : CC.CGenv} {n : Nat} {s a b : CC.State}
    (first : InternalRun ge n s a) (second : InternalRun ge n s b) : a = b := by
  induction first generalizing b with
  | refl _ => cases second; rfl
  | step hs step remaining ih =>
    cases second with
    | step _ other rest =>
      have same := (internal_step_unique hs step other).2
      cases same
      exact ih rest

private theorem source_steps (world : CC.CGenv) (f : CC.Function) (rest : CC.Stmt) (e : CC.Env) (le : CC.TempEnv) (k : CC.Cont)
    (fb cb ab : CC.Block) (before m1 m2 after : CC.Mem)
    (flag : e.get Arm64Entry.___a64_sim_is_xdp = some (fb, CC.tuchar))
    (ctx : e.get Arm64Entry.___a64_sim_helper_ctx = some (cb, CC.tptr CC.tvoid))
    (abi : e.get Arm64Entry.___a64_sim_helper_abi_base = some (ab, CC.tptr CC.tvoid))
    (s0 : CC.Mem.store .Mint8unsigned before fb 0 (.Vint (0#32)) = some m1)
    (s1 : CC.Mem.store CC.Mptr m1 cb 0 (.Vlong (0#64)) = some m2)
    (s2 : CC.Mem.store CC.Mptr m2 ab 0 (.Vlong (0#64)) = some after) :
    steps world 9 (.State f (setupAssignments.foldr CC.Stmt.Ssequence rest) k e le before) =
      some (CC.E0, .State f rest k e le after) ∧
    InternalPath world 9 (.State f (setupAssignments.foldr CC.Stmt.Ssequence rest) k e le before) := by
  change CC.Mem.storev .Mint8unsigned before (.Vptr fb (0#64)) (.Vint (0#32)) = some m1 at s0
  change CC.Mem.storev CC.Mptr m1 (.Vptr cb (0#64)) (.Vlong (0#64)) = some m2 at s1
  change CC.Mem.storev CC.Mptr m2 (.Vptr ab (0#64)) (.Vlong (0#64)) = some after at s2
  simp +decide [steps, InternalPath, InternalState, setupAssignments, List.foldr,
    CC.doStep, CC.doEvalLvalue, CC.lvalOfVar, CC.doEvalExpr, CC.typeof,
    CC.doAssignLoc, CC.accessMode, CC.Cop.semCast, CC.Cop.classifyCast, CC.Cop.castIntInt,
    CC.Cop.castIntLong, CC.Integers.Int.signed, CC.Integers.MI.signed,
    CC.Integers.Int64.repr, CC.Integers.Int.repr, CC.Integers.MI.repr,
    CC.Integers.Int.zero_ext, CC.Integers.MI.zero_ext, CC.Integers.Ptrofs.zero, CC.Integers.MI.zero,
    CC.Archi.ptr64, CC.tptr, CC.tvoid, CC.tint, CC.tuchar,
    CC.E0, CC.Eapp, flag, ctx, abi, s0, s1, s2]

/-- Observe the actual initialized is_xdp zero byte on any reached original
three-store setup witness. Only its deterministic internal nine steps are
identified; no external provider outcome is replayed or assumed. -/
theorem observed (ge : CC.CGenv) (f : CC.Function) (e : CC.Env) (rest : CC.Stmt)
    (initial before after : CC.Mem) (le : CC.TempEnv) (k : CC.Cont) (cell : TailLocal initial 5)
    (bound : ∀ id ∈ setupNames, e.get id = (Arm64Producer.allocation initial).1.get id)
    (access : before.access = (Arm64Producer.allocation initial).2.access)
    (run : InternalRun ge 9
      (.State f (setupAssignments.foldr CC.Stmt.Ssequence rest) k e le before)
      (.State f rest k e le after)) :
    CC.Mem.load .Mint8unsigned after cell.block 0 = some (.Vint 0) := by
  obtain ⟨fb,flag,_flagFresh,flagWritable⟩ := Arm64Producer.scalar_local initial Arm64Entry.___a64_sim_is_xdp
    CC.tuchar .Mint8unsigned (by decide +kernel) rfl (by decide)
  obtain ⟨cb,ctx,_ctxFresh,ctxWritable⟩ := Arm64Producer.scalar_local initial Arm64Entry.___a64_sim_helper_ctx
    (CC.tptr CC.tvoid) CC.Mptr (by decide +kernel) rfl (by decide)
  obtain ⟨ab,abi,_abiFresh,abiWritable⟩ := Arm64Producer.scalar_local initial Arm64Entry.___a64_sim_helper_abi_base
    (CC.tptr CC.tvoid) CC.Mptr (by decide +kernel) rfl (by decide)
  have cellBinding : (Arm64Producer.allocation initial).1.get Arm64Entry.___a64_sim_is_xdp =
      some (cell.block,CC.tuchar) := cell.binding
  have same : fb = cell.block := congrArg Prod.fst (Option.some.inj (flag.symm.trans cellBinding))
  subst fb
  obtain ⟨m1,s0,a1⟩ := Arm64Producer.create_store initial before .Mint8unsigned cell.block (.Vint (0#32)) access flagWritable
  obtain ⟨m2,s1,a2⟩ := Arm64Producer.create_store initial m1 CC.Mptr cb (.Vlong (0#64)) a1 ctxWritable
  obtain ⟨created,s2,_a3⟩ := Arm64Producer.create_store initial m2 CC.Mptr ab (.Vlong (0#64)) a2 abiWritable
  have steps := source_steps ge f rest e le k cell.block cb ab before m1 m2 created
    ((bound _ (by decide +kernel)).trans flag) ((bound _ (by decide +kernel)).trans ctx)
    ((bound _ (by decide +kernel)).trans abi) s0 s1 s2
  have equal := same_end (internalRun_of_steps steps.2 steps.1) run
  have memoryEqual := congrArg (fun state => match state with
    | .State _ _ _ _ _ memory => memory
    | _ => before) equal
  change created = after at memoryEqual
  subst after
  have separate := (allocated_local_storage (CC.doAllocVariables_sound _ _ _ _ _ _
    (Prod.eta (Arm64Producer.allocation initial)).symm)).2
  have otherCtx : cell.block ≠ cb := separate _ _ _ _ cellBinding ctx (by decide +kernel)
  have otherAbi : cell.block ≠ ab := separate _ _ _ _ cellBinding abi (by decide +kernel)
  have zero : CC.Mem.load .Mint8unsigned m1 cell.block 0 = some (.Vint 0) := by
    simpa +decide [CC.Val.loadResult,CC.Integers.Int.zero_ext,CC.Integers.MI.zero_ext] using CC.Mem.load_store_same s0
  exact (CC.Mem.load_store_other s2 .Mint8unsigned cell.block 0 (.inl otherAbi)).trans
    ((CC.Mem.load_store_other s1 .Mint8unsigned cell.block 0 (.inl otherCtx)).trans zero)

end KProgFormal.ClightRefinement.Arm64ProducerIsXdpSetup
