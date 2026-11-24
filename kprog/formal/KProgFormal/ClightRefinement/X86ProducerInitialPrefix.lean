import KProgFormal.ClightRefinement.X86ProducerGhostInitialize

namespace KProgFormal.ClightRefinement.X86ProducerInitialPrefix
open X86ProducerGhostSource X86ProducerGhostStore
open X86ProducerHeaderSource (producer)
open X86ProducerHeaderLocals (Local)
open X86ProducerCacheAllocation (allocation)
open X86ProducerLayout (ge)

def contextValues (i : Fin 5) : CC.Val :=
  if i.val = 4 then .Vint (2#32) else if i.val = 3 then .Vint 0 else .Vlong 0

private theorem five_cases : ∀ i : Fin 5, i = 0 ∨ i = 1 ∨ i = 2 ∨ i = 3 ∨ i = 4 := by decide +kernel

/-- The actual context updates construct the later header's typed source inputs;
this records the current early values, before subsequent provider/setup effects. -/
theorem context_inputs (le : CC.TempEnv) :
    X86ProducerContextSource.Typed contextValues ∧
    ∀ i, (finalTemps (contextTemps le)).get (X86ProducerContextSource.tempName i) = some (contextValues i) := by
  constructor
  · intro i
    rcases five_cases i with rfl | rfl | rfl | rfl | rfl
    · exact Or.inr ⟨0, rfl⟩
    · exact Or.inr ⟨0, rfl⟩
    · exact Or.inr ⟨0, rfl⟩
    · exact ⟨(0#8), rfl⟩
    · exact ⟨(2#8), rfl⟩
  · intro i
    rcases five_cases i with rfl | rfl | rfl | rfl | rfl
    · change (finalTemps (contextTemps le)).get X86_program_profile_bpf.___x86_sim_helper_ctx = some (.Vlong 0)
      have names : X86_program_profile_bpf.___x86_sim_helper_abi_base ≠ X86_program_profile_bpf.___x86_sim_helper_ctx := by decide +kernel
      unfold finalTemps contextTemps
      rw [CC.PTree.gso _ _ _ _ names, CC.PTree.gss]
    · change (finalTemps (contextTemps le)).get X86_program_profile_bpf.___x86_sim_helper_abi_base = some (.Vlong 0)
      unfold finalTemps contextTemps
      exact CC.PTree.gss _ _ _
    · change (finalTemps (contextTemps le)).get X86_program_profile_bpf.___x86_sim_skb_ctx = some (.Vlong 0)
      have names : X86_program_profile_bpf.___x86_sim_abi_kind ≠ X86_program_profile_bpf.___x86_sim_skb_ctx ∧ X86_program_profile_bpf.___x86_sim_is_xdp ≠ X86_program_profile_bpf.___x86_sim_skb_ctx ∧ X86_program_profile_bpf.___x86_sim_helper_ctx ≠ X86_program_profile_bpf.___x86_sim_skb_ctx ∧ X86_program_profile_bpf.___x86_sim_helper_abi_base ≠ X86_program_profile_bpf.___x86_sim_skb_ctx := by decide +kernel
      rcases names with ⟨n0, n1, n2, n3⟩
      unfold finalTemps contextTemps
      rw [CC.PTree.gso _ _ _ _ n3, CC.PTree.gso _ _ _ _ n2, CC.PTree.gso _ _ _ _ n1, CC.PTree.gso _ _ _ _ n0, CC.PTree.gss]
    · change (finalTemps (contextTemps le)).get X86_program_profile_bpf.___x86_sim_is_xdp = some (.Vint 0)
      have names : X86_program_profile_bpf.___x86_sim_helper_ctx ≠ X86_program_profile_bpf.___x86_sim_is_xdp ∧ X86_program_profile_bpf.___x86_sim_helper_abi_base ≠ X86_program_profile_bpf.___x86_sim_is_xdp := by decide +kernel
      rcases names with ⟨n0, n1⟩
      unfold finalTemps contextTemps
      rw [CC.PTree.gso _ _ _ _ n1, CC.PTree.gso _ _ _ _ n0, CC.PTree.gss]
    · change (finalTemps (contextTemps le)).get X86_program_profile_bpf.___x86_sim_abi_kind = some (.Vint (2#32))
      have names : X86_program_profile_bpf.___x86_sim_is_xdp ≠ X86_program_profile_bpf.___x86_sim_abi_kind ∧ X86_program_profile_bpf.___x86_sim_helper_ctx ≠ X86_program_profile_bpf.___x86_sim_abi_kind ∧ X86_program_profile_bpf.___x86_sim_helper_abi_base ≠ X86_program_profile_bpf.___x86_sim_abi_kind := by decide +kernel
      rcases names with ⟨n0, n1, n2⟩
      unfold finalTemps contextTemps
      rw [CC.PTree.gso _ _ _ _ n2, CC.PTree.gso _ _ _ _ n1, CC.PTree.gso _ _ _ _ n0, CC.PTree.gss]

/-- The actual full producer call enters, initializes every ABI field and all
six ghost tag/pointer pairs, and executes the real context updates in613
transitions. Every ABI readback survives via actual allocated-name separation;
no provider, permission, initialized view or output heap premise is supplied. -/
theorem from_call (before : CC.Mem) (ctx : CC.Val) (k : CC.Cont) :
    ∃ abi : Local ge.genv_cenv before X86_program_profile_bpf.___x86_sim_abi X86ProducerAbiSource.abiType,
    ∃ locals : Locals before, ∃ after,
    InternalRun ge 613 (.Callstate (.Internal producer) [ctx] k before)
      (.State producer beforeProvider k (allocation ge.genv_cenv before).1
        (finalTemps (contextTemps (X86ProducerEntry.initialTemps ctx))) after) ∧
    (∀ i, CC.Mem.load (X86ProducerAbiSource.chunk i) after abi.block (X86ProducerAbiSource.offset i) = some (X86ProducerAbiSource.value i)) ∧
    (∀ i, CC.Mem.load (chunk i) after (locals i).block 0 = some (value i)) ∧
    X86ProducerContextSource.Typed contextValues ∧
    (∀ i, (finalTemps (contextTemps (X86ProducerEntry.initialTemps ctx))).get
      (X86ProducerContextSource.tempName i) = some (contextValues i)) ∧
    FrameBelow before.nextblock before after ∧
    after.access = (allocation ge.genv_cenv before).2.access ∧ after.nextblock = (allocation ge.genv_cenv before).2.nextblock := by
  obtain ⟨abi, middle, abiRun, abiReads, abiOutside, abiFrame, abiAccess, abiNext⟩ :=
    X86ProducerAbiInitialize.from_call before ctx k
  obtain ⟨locals, after, setupRun, ghostReads, setupOutside, setupFrame, setupAccess, setupNext⟩ :=
    X86ProducerGhostInitialize.setup_initialized before middle (X86ProducerEntry.initialTemps ctx) k abiAccess
  have names : ∀ i : Fin 12, X86_program_profile_bpf.___x86_sim_abi ≠ X86ProducerHeaderSource.localName (row i) := by decide +kernel
  have allocated : CC.AllocVariables ge.genv_cenv CC.emptyEnv before producer.fn_vars
      (allocation ge.genv_cenv before).1 (allocation ge.genv_cenv before).2 :=
    CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation ge.genv_cenv before)).symm
  have abiOutsideGhosts : Outside locals abi.block := by
    intro i
    exact (allocated_local_storage allocated).2 _ _ _ _ abi.binding (locals i).binding (names i)
  refine ⟨abi, locals, after, abiRun.trans setupRun, ?_, ghostReads,
    (context_inputs (X86ProducerEntry.initialTemps ctx)).1, (context_inputs (X86ProducerEntry.initialTemps ctx)).2, abiFrame.trans setupFrame,
    setupAccess.trans abiAccess, setupNext.trans abiNext⟩
  intro i
  exact (setupOutside _ _ _ abiOutsideGhosts).trans (abiReads i)

end KProgFormal.ClightRefinement.X86ProducerInitialPrefix
