import KProgFormal.ClightRefinement.X86ReleaseStorageCacheFrame

namespace KProgFormal.ClightRefinement.X86ProducerCacheAllocation

/-- Names of the six actual individually declared ghost tag locals. -/
def tagName (slot : Fin 6) : CC.Ident :=
  match slot.val with
  | 0 => X86_program_profile_bpf.___x86_stack_value_tag_0
  | 1 => X86_program_profile_bpf.___x86_stack_value_tag_1
  | 2 => X86_program_profile_bpf.___x86_stack_value_tag_2
  | 3 => X86_program_profile_bpf.___x86_stack_value_tag_3
  | 4 => X86_program_profile_bpf.___x86_stack_value_tag_4
  | _ => X86_program_profile_bpf.___x86_stack_value_tag_5

/-- Names of the six actual individually declared ghost pointer locals. -/
def pointerName (slot : Fin 6) : CC.Ident :=
  match slot.val with
  | 0 => X86_program_profile_bpf.___x86_stack_value_ptr_0
  | 1 => X86_program_profile_bpf.___x86_stack_value_ptr_1
  | 2 => X86_program_profile_bpf.___x86_stack_value_ptr_2
  | 3 => X86_program_profile_bpf.___x86_stack_value_ptr_3
  | 4 => X86_program_profile_bpf.___x86_stack_value_ptr_4
  | _ => X86_program_profile_bpf.___x86_stack_value_ptr_5

def allocation (ce : CC.CompositeEnv) (before : CC.Mem) : CC.Env × CC.Mem :=
  CC.doAllocVariables ce CC.emptyEnv before X86_program_profile_bpf.f_x86_program_profile_x86_sim_xdp.fn_vars

private theorem declarations :
    CC.listNorepet (CC.varNames X86_program_profile_bpf.f_x86_program_profile_x86_sim_xdp.fn_vars) ∧
    (X86_program_profile_bpf.___x86_stack_mem,
      CC.Ty.Tunion X86_program_profile_bpf._x86_sim_stack_mem CC.noattr) ∈
        X86_program_profile_bpf.f_x86_program_profile_x86_sim_xdp.fn_vars ∧
    (X86_program_profile_bpf.___x86_inline_bindings,
      CC.Ty.Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr) ∈
        X86_program_profile_bpf.f_x86_program_profile_x86_sim_xdp.fn_vars ∧
    ∀ slot : Fin 6,
      (tagName slot, CC.tuchar) ∈ X86_program_profile_bpf.f_x86_program_profile_x86_sim_xdp.fn_vars ∧
      (pointerName slot, CC.tptr CC.tvoid) ∈ X86_program_profile_bpf.f_x86_program_profile_x86_sim_xdp.fn_vars := by
  decide +kernel

private theorem names_distinct : ∀ slot : Fin 6,
    X86_program_profile_bpf.___x86_stack_mem ≠ tagName slot ∧
    X86_program_profile_bpf.___x86_stack_mem ≠ pointerName slot ∧
    tagName slot ≠ X86_program_profile_bpf.___x86_inline_bindings ∧
    pointerName slot ≠ X86_program_profile_bpf.___x86_inline_bindings ∧
    tagName slot ≠ pointerName slot := by decide +kernel

/-- The actual producer allocator constructs cache/ghost separation and
pre-handler lifetime from the original local declarations. Header contents
and the external provider ABI are not asserted by allocation. -/
theorem owned (ce : CC.CompositeEnv) (before : CC.Mem) :
    ∃ (cache binding : CC.Block) (places : X86CallFrameComplete.Places),
    (allocation ce before).1.get X86_program_profile_bpf.___x86_stack_mem =
      some (cache, CC.Ty.Tunion X86_program_profile_bpf._x86_sim_stack_mem CC.noattr) ∧
    (allocation ce before).1.get X86_program_profile_bpf.___x86_inline_bindings =
      some (binding, CC.Ty.Tstruct X86_program_profile_bpf._x86_sim_inline_bindings CC.noattr) ∧
    (∀ slot, (allocation ce before).1.get (tagName slot) = some ((places.tag slot).1, CC.tuchar) ∧
      (allocation ce before).1.get (pointerName slot) = some ((places.pointer slot).1, CC.tptr CC.tvoid)) ∧
    (∀ slot, (places.tag slot).2 = 0 ∧ (places.pointer slot).2 = 0) ∧
    binding ≠ cache ∧ X86CallFrameComplete.Outside places cache ∧
    X86CallFrameComplete.Separated binding places ∧
    cache.toNat < (allocation ce before).2.nextblock.toNat ∧
    (∀ slot, (places.tag slot).1.toNat < (allocation ce before).2.nextblock.toNat ∧
      (places.pointer slot).1.toNat < (allocation ce before).2.nextblock.toNat) ∧
    CC.Mem.rangePerm (allocation ce before).2 cache 0
      (CC.sizeof ce (CC.Ty.Tunion X86_program_profile_bpf._x86_sim_stack_mem CC.noattr)) .Cur .Freeable = true := by
  have allocated : CC.AllocVariables ce CC.emptyEnv before
      X86_program_profile_bpf.f_x86_program_profile_x86_sim_xdp.fn_vars
      (allocation ce before).1 (allocation ce before).2 :=
    CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation ce before)).symm
  obtain ⟨cache, cacheBinding⟩ := allocated_local_binding allocated declarations.1 declarations.2.1
  obtain ⟨binding, headerBinding⟩ := allocated_local_binding allocated declarations.1 declarations.2.2.1
  have tagBindings : ∀ slot, ∃ block, (allocation ce before).1.get (tagName slot) = some (block, CC.tuchar) :=
    fun slot => allocated_local_binding allocated declarations.1 (declarations.2.2.2 slot).1
  have pointerBindings : ∀ slot, ∃ block, (allocation ce before).1.get (pointerName slot) = some (block, CC.tptr CC.tvoid) :=
    fun slot => allocated_local_binding allocated declarations.1 (declarations.2.2.2 slot).2
  let places : X86CallFrameComplete.Places :=
    ⟨fun slot => (Classical.choose (tagBindings slot), 0), fun slot => (Classical.choose (pointerBindings slot), 0)⟩
  have tags (slot : Fin 6) : (allocation ce before).1.get (tagName slot) = some ((places.tag slot).1, CC.tuchar) :=
    Classical.choose_spec (tagBindings slot)
  have pointers (slot : Fin 6) : (allocation ce before).1.get (pointerName slot) = some ((places.pointer slot).1, CC.tptr CC.tvoid) :=
    Classical.choose_spec (pointerBindings slot)
  obtain ⟨live, distinct⟩ := allocated_local_storage allocated
  refine ⟨cache, binding, places, cacheBinding, headerBinding, fun slot => ⟨tags slot, pointers slot⟩, fun _ => ⟨rfl, rfl⟩,
    ?_, ?_, ?_, (live _ _ cacheBinding).2.1, ?_, (live _ _ cacheBinding).2.2⟩
  · exact distinct _ _ _ _ headerBinding cacheBinding (by decide +kernel)
  · intro slot
    exact ⟨distinct _ _ _ _ cacheBinding (tags slot) (names_distinct slot).1,
      distinct _ _ _ _ cacheBinding (pointers slot) (names_distinct slot).2.1⟩
  · intro slot
    exact ⟨distinct _ _ _ _ (tags slot) headerBinding (names_distinct slot).2.2.1,
      distinct _ _ _ _ (pointers slot) headerBinding (names_distinct slot).2.2.2.1,
      distinct _ _ _ _ (tags slot) (pointers slot) (names_distinct slot).2.2.2.2⟩
  · intro slot
    exact ⟨(live _ _ (tags slot)).2.1, (live _ _ (pointers slot)).2.1⟩

end KProgFormal.ClightRefinement.X86ProducerCacheAllocation
