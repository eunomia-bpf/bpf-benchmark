import KProgFormal.ClightRefinement.Arm64CiliumCallerHelperEntry

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerABIBase
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure ge allocation)
open Arm64CiliumCallerContext (ABI abiType)

noncomputable def after : CC.Stmt := by
  run_tac do
    let body ← Lean.Elab.Term.elabTerm (← `(s_trusted_arm64_arm64_sim_xdp_9287)) none
    let exposed ← Lean.Meta.withTransparency .all (Lean.Meta.whnf body)
    unless exposed.isAppOfArity ``CC.Stmt.Ssequence 2 do
      throwError "actual helper ABI base sequence changed"
    Lean.Elab.Tactic.closeMainGoal `original_after_helper_abi exposed.getAppArgs[1]!

theorem source : s_trusted_arm64_arm64_sim_xdp_9287 =
    .Ssequence (.Sassign (.Evar ___a64_sim_helper_abi_base (CC.tptr CC.tvoid))
      (.Eaddrof (.Evar ___a64_sim_abi abiType) (CC.tptr abiType))) after := rfl

theorem default_replaced : Arm64CiliumCallerDefaults.name 8 = ___a64_sim_helper_abi_base ∧
    Arm64CiliumCallerDefaults.ty 8 = CC.tptr CC.tvoid ∧
    Arm64CiliumCallerDefaults.chunk 8 = CC.Chunk.Mint64 := by
  repeat' constructor
  all_goals rfl

structure Storage (m : CC.Mem) where
  block : CC.Block
  binding : (allocation m).1.get ___a64_sim_helper_abi_base = some (block,CC.tptr CC.tvoid)
  fresh : m.nextblock.toNat ≤ block.toNat
  live : CC.Mem.rangePerm (allocation m).2 block 0 8 .Cur .Freeable = true

theorem storage (m : CC.Mem) : Nonempty (Storage m) := by
  have names : CC.listNorepet (CC.varNames procedure.fn_vars) := by
    cases Arm64CiliumCallerLink.entry_valid m .Vundef with
    | intro hn _ _ _ _ => exact hn
  have declared : (___a64_sim_helper_abi_base,CC.tptr CC.tvoid) ∈ procedure.fn_vars := by decide +kernel
  obtain ⟨block,binding⟩ := allocated_local_binding (Arm64CiliumCallerLink.allocated m) names declared
  have owned := (allocated_local_storage (Arm64CiliumCallerLink.allocated m)).1 _ _ binding
  exact ⟨⟨block,binding,owned.1,owned.2.2⟩⟩

/-- Original address-of-ABI value and real current store, without an address oracle. -/
theorem execute {m before : CC.Mem} (resource : Storage m) (abi : ABI m)
    (access : before.access = (allocation m).2.access) (le : CC.TempEnv) (k : CC.Cont) :
    ∃ afterMem,
      InternalRun ge 3 (.State procedure s_trusted_arm64_arm64_sim_xdp_9287 k (allocation m).1 le before)
        (.State procedure after k (allocation m).1 le afterMem) ∧
      CC.Mem.store .Mint64 before resource.block 0 (.Vptr abi.block 0) = some afterMem ∧
      CC.Mem.load .Mint64 afterMem resource.block 0 = some (.Vptr abi.block 0) ∧
      (∀ b,b ≠ resource.block → ∀ c o,CC.Mem.load c afterMem b o = CC.Mem.load c before b o) ∧
      FrameBelow m.nextblock before afterMem ∧ afterMem.access = before.access ∧
      afterMem.nextblock = before.nextblock := by
  have live : CC.Mem.rangePerm before resource.block 0 8 .Cur .Freeable = true := by
    apply CC.Mem.rangePerm_intro
    intro o lower upper
    have permission := CC.Mem.rangePerm_perm _ _ _ _ _ _ resource.live o lower upper
    simpa only [CC.Mem.perm,access] using permission
  have range := CC.Mem.rangePerm_implies live (by decide : CC.permOrder .Freeable .Writable = true)
  have valid : CC.Mem.validAccess before .Mint64 resource.block 0 .Writable = true := by
    change (CC.Mem.rangePerm before resource.block 0 8 .Cur .Writable && true) = true
    rw [range];rfl
  obtain ⟨afterMem,stored⟩ : ∃ afterMem,CC.Mem.store .Mint64 before resource.block 0 (.Vptr abi.block 0) = some afterMem := by
    simp only [CC.Mem.store,valid,ite_true]
    exact ⟨_,rfl⟩
  have eval : CC.doEvalExpr ge (allocation m).1 le before
      (.Eaddrof (.Evar ___a64_sim_abi abiType) (CC.tptr abiType)) = some (.Vptr abi.block 0) := by
    simp [CC.doEvalExpr,CC.doEvalLvalue,CC.lvalOfVar,abi.binding,CC.Integers.Ptrofs.zero]
    rfl
  have step : CC.Step2 ge
      (.State procedure (.Sassign (.Evar ___a64_sim_helper_abi_base (CC.tptr CC.tvoid))
        (.Eaddrof (.Evar ___a64_sim_abi abiType) (CC.tptr abiType)))
        (.Kseq after k) (allocation m).1 le before) CC.E0
      (.State procedure .Sskip (.Kseq after k) (allocation m).1 le afterMem) := by
    apply CC.Step.assign
    · exact .Evar_local _ _ _ resource.binding
    · exact CC.doEvalExpr_sound _ _ _ _ _ _ eval
    · rfl
    · exact CC.doAssignLoc_sound _ _ _ _ _ _ _ _ stored
  refine ⟨afterMem,?_,stored,CC.Mem.load_store_same stored,
    (fun b different c o => CC.Mem.load_store_other stored c b o (.inl different)),
    FrameBelow.store resource.fresh stored,CC.Mem.store_access stored,CC.Mem.store_nextblock stored⟩
  rw [source]
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl)
    (.step trivial step (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)))

theorem bound_frame {m before afterMem : CC.Mem} (resource : Storage m)
    (blocks : ∀ b,b ≠ resource.block → ∀ c o,
      CC.Mem.load c afterMem b o = CC.Mem.load c before b o)
    {id : CC.Ident} {ty : CC.Ty} {b : CC.Block}
    (binding : (allocation m).1.get id = some (b,ty)) (different : id ≠ ___a64_sim_helper_abi_base) :
    ∀ c o,CC.Mem.load c afterMem b o = CC.Mem.load c before b o :=
  blocks b ((allocated_local_storage (Arm64CiliumCallerLink.allocated m)).2
    _ _ _ _ binding resource.binding different)

end KProgFormal.ClightRefinement.Arm64CiliumCallerABIBase
