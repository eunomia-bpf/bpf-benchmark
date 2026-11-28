import KProgFormal.ClightRefinement.Arm64CiliumCallerScalarEntry

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64CiliumCallerHelperSetup
open Arm64CiliumCallerUnit
open Arm64CiliumCallerLink (procedure ge allocation)

theorem temporary_separation :
    (∀ i : Fin 31,(Arm64CiliumCallerGPRSource.declaration i).inputTemp ≠ _ctx ∧
      (Arm64CiliumCallerGPRSource.declaration i).resultTemp ≠ _ctx) ∧
    (∀ i : Fin 4,(Arm64CiliumCallerFlags.declaration i).inputTemp ≠ _ctx) ∧
    (∀ i : Fin 64,Arm64CiliumCallerVectorSource.temporary i ≠ _ctx) ∧
    _t'1 ≠ _ctx ∧ _t'2 ≠ _ctx := by decide +kernel

theorem gpr_next (inputs : Fin 30 → BitVec 64) (n : Nat) (le : CC.TempEnv) :
    (Arm64CiliumCallerGPRSequence.nextTemps inputs n le).get _ctx = le.get _ctx := by
  unfold Arm64CiliumCallerGPRSequence.nextTemps
  split
  · rename_i h
    let i := Arm64CiliumCallerGPRSource.inputIndex ⟨n,h⟩
    change ((le.set (Arm64CiliumCallerGPRSource.declaration i).inputTemp _).set
      (Arm64CiliumCallerGPRSource.declaration i).resultTemp _).get _ctx = _
    rw [CC.PTree.gso _ _ _ _ (temporary_separation.1 i).2,
      CC.PTree.gso _ _ _ _ (temporary_separation.1 i).1]
  · exact CC.PTree.gso _ _ _ _ (temporary_separation.1 30).2

theorem gpr_temps (inputs : Fin 30 → BitVec 64) (n count : Nat) (le : CC.TempEnv) :
    (Arm64CiliumCallerGPRSequence.finalTemps inputs n count le).get _ctx = le.get _ctx := by
  induction count generalizing n le with
  | zero => rfl
  | succ count ih =>
    simp only [Arm64CiliumCallerGPRSequence.finalTemps]
    rw [ih,gpr_next]

theorem flag_next (inputs : Fin 4 → BitVec 64) (n : Nat) (le : CC.TempEnv) :
    (Arm64CiliumCallerFlagSequence.nextTemps inputs n le).get _ctx = le.get _ctx := by
  unfold Arm64CiliumCallerFlagSequence.nextTemps
  split
  · rename_i h
    exact CC.PTree.gso _ _ _ _ (temporary_separation.2.1 ⟨n,h⟩)
  · rfl

theorem flag_temps (inputs : Fin 4 → BitVec 64) (n count : Nat) (le : CC.TempEnv) :
    (Arm64CiliumCallerFlagSequence.finalTemps inputs n count le).get _ctx = le.get _ctx := by
  induction count generalizing n le with
  | zero => rfl
  | succ count ih =>
    simp only [Arm64CiliumCallerFlagSequence.finalTemps]
    rw [ih,flag_next]

theorem vector_next (inputs : Fin 64 → BitVec 64) (n : Nat) (le : CC.TempEnv) :
    (Arm64CiliumCallerVectorSequence.nextTemps inputs n le).get _ctx = le.get _ctx := by
  unfold Arm64CiliumCallerVectorSequence.nextTemps
  split
  · rename_i h
    exact CC.PTree.gso _ _ _ _ (temporary_separation.2.2.1 ⟨n,h⟩)
  · rfl

theorem vector_temps (inputs : Fin 64 → BitVec 64) (n count : Nat) (le : CC.TempEnv) :
    (Arm64CiliumCallerVectorSequence.finalTemps inputs n count le).get _ctx = le.get _ctx := by
  induction count generalizing n le with
  | zero => rfl
  | succ count ih =>
    simp only [Arm64CiliumCallerVectorSequence.finalTemps]
    rw [ih,vector_next]

noncomputable def entryTemps (ctx : CC.Block) (ctxOfs : CC.Integers.Ptrofs)
    (results : Bool → CC.Block) (resultOffsets : Bool → CC.Integers.Ptrofs)
    (inputs : Fin 30 → BitVec 64) (flagInputs : Fin 4 → BitVec 64)
    (vectorInputs : Fin 64 → BitVec 64) : CC.TempEnv :=
  Arm64CiliumCallerVectorSequence.finalTemps vectorInputs 0 64
    (Arm64CiliumCallerFlagSequence.finalTemps flagInputs 0 4
    (Arm64CiliumCallerGPRSequence.finalTemps inputs 0 31
      (Arm64CiliumCallerGPREntry.contextTemps ctx ctxOfs results resultOffsets)))

/-- Actual original ctx argument survives every real prior temporary update. -/
theorem reached_context (ctx : CC.Block) (ctxOfs : CC.Integers.Ptrofs)
    (results : Bool → CC.Block) (resultOffsets : Bool → CC.Integers.Ptrofs)
    (inputs : Fin 30 → BitVec 64) (flagInputs : Fin 4 → BitVec 64)
    (vectorInputs : Fin 64 → BitVec 64) :
    (entryTemps ctx ctxOfs results resultOffsets inputs flagInputs vectorInputs).get _ctx =
      some (.Vptr ctx ctxOfs) := by
  unfold entryTemps
  rw [vector_temps,flag_temps,gpr_temps]
  unfold Arm64CiliumCallerGPREntry.contextTemps
  rw [CC.PTree.gso _ _ _ _ temporary_separation.2.2.2.2,
    CC.PTree.gso _ _ _ _ temporary_separation.2.2.2.1]
  exact CC.PTree.gss _ _ _

structure Storage (m : CC.Mem) where
  block : CC.Block
  binding : (allocation m).1.get ___a64_sim_helper_ctx = some (block,CC.tptr CC.tvoid)
  fresh : m.nextblock.toNat ≤ block.toNat
  live : CC.Mem.rangePerm (allocation m).2 block 0 8 .Cur .Freeable = true

theorem storage (m : CC.Mem) : Nonempty (Storage m) := by
  have names : CC.listNorepet (CC.varNames procedure.fn_vars) := by
    cases Arm64CiliumCallerLink.entry_valid m .Vundef with
    | intro hn _ _ _ _ => exact hn
  have declared : (___a64_sim_helper_ctx,CC.tptr CC.tvoid) ∈ procedure.fn_vars := by decide +kernel
  obtain ⟨block,binding⟩ := allocated_local_binding (Arm64CiliumCallerLink.allocated m) names declared
  have owned := (allocated_local_storage (Arm64CiliumCallerLink.allocated m)).1 _ _ binding
  exact ⟨⟨block,binding,owned.1,owned.2.2⟩⟩

/-- The actual helper-context pointer assignment, not a fresh context oracle. -/
theorem execute {m before : CC.Mem} (resource : Storage m)
    (access : before.access = (allocation m).2.access)
    (ctx : CC.Block) (ctxOfs : CC.Integers.Ptrofs) (le : CC.TempEnv) (k : CC.Cont)
    (input : le.get _ctx = some (.Vptr ctx ctxOfs)) :
    ∃ afterMem,
      InternalRun ge 3 (.State procedure Arm64CiliumCallerEntryScalars.after k (allocation m).1 le before)
        (.State procedure s_trusted_arm64_arm64_sim_xdp_9287 k (allocation m).1 le afterMem) ∧
      CC.Mem.store .Mint64 before resource.block 0 (.Vptr ctx ctxOfs) = some afterMem ∧
      CC.Mem.load .Mint64 afterMem resource.block 0 = some (.Vptr ctx ctxOfs) ∧
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
  obtain ⟨afterMem,stored⟩ : ∃ afterMem,CC.Mem.store .Mint64 before resource.block 0 (.Vptr ctx ctxOfs) = some afterMem := by
    simp only [CC.Mem.store,valid,ite_true]
    exact ⟨_,rfl⟩
  have eval : CC.doEvalExpr ge (allocation m).1 le before
      (.Ecast (.Etempvar _ctx (CC.tptr (.Tstruct _xdp_md CC.noattr))) (CC.tptr CC.tvoid)) =
        some (.Vptr ctx ctxOfs) := by
    simp [CC.doEvalExpr,input,CC.Cop.semCast,CC.Cop.classifyCast,CC.typeof,CC.tptr]
  have step : CC.Step2 ge
      (.State procedure s_trusted_arm64_arm64_sim_xdp_25
        (.Kseq s_trusted_arm64_arm64_sim_xdp_9287 k) (allocation m).1 le before) CC.E0
      (.State procedure .Sskip
        (.Kseq s_trusted_arm64_arm64_sim_xdp_9287 k) (allocation m).1 le afterMem) := by
    apply CC.Step.assign
    · exact .Evar_local _ _ _ resource.binding
    · exact CC.doEvalExpr_sound _ _ _ _ _ _ eval
    · rfl
    · exact CC.doAssignLoc_sound _ _ _ _ _ _ _ _ stored
  refine ⟨afterMem,?_,stored,CC.Mem.load_store_same stored,
    (fun b different c o => CC.Mem.load_store_other stored c b o (.inl different)),
    FrameBelow.store resource.fresh stored,CC.Mem.store_access stored,CC.Mem.store_nextblock stored⟩
  rw [Arm64CiliumCallerEntryScalars.after_source]
  exact .step trivial (CC.doStep_sound _ _ _ _ rfl)
    (.step trivial step (.step trivial (CC.doStep_sound _ _ _ _ rfl) (.refl _)))

end KProgFormal.ClightRefinement.Arm64CiliumCallerHelperSetup
