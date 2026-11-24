import KProgFormal.ClightRefinement.X86ProducerHeaderSource

namespace KProgFormal.ClightRefinement.X86ProducerHeaderLocals
open X86ProducerHeaderSource
open X86ProducerCacheAllocation (allocation)

/-- Actual local binding and full declared-range ownership, without assuming
initialized contents or a post-execution heap. -/
structure Local (ce : CC.CompositeEnv) (before : CC.Mem) (name : CC.Ident) (ty : CC.Ty) where
  block : CC.Block
  binding : (allocation ce before).1.get name = some (block, ty)
  fresh : before.nextblock.toNat ≤ block.toNat
  owned : block.toNat < (allocation ce before).2.nextblock.toNat
  range : CC.Mem.rangePerm (allocation ce before).2 block 0 (CC.sizeof ce ty) .Cur .Freeable = true

abbrev HeaderLocal (ce : CC.CompositeEnv) (before : CC.Mem) :=
  Local ce before X86_program_profile_bpf.___x86_inline_bindings headerType
abbrev SourceLocal (ce : CC.CompositeEnv) (before : CC.Mem) (i : Fin 24) :=
  Local ce before (localName i) (localType i)

private theorem declarations :
    CC.listNorepet (CC.varNames producer.fn_vars) ∧
    (X86_program_profile_bpf.___x86_inline_bindings, headerType) ∈ producer.fn_vars ∧
    ∀ i : Fin 24, (localName i, localType i) ∈ producer.fn_vars ∧
      localName i ≠ X86_program_profile_bpf.___x86_inline_bindings := by decide +kernel

private theorem local_storage (ce : CC.CompositeEnv) (before : CC.Mem) (name : CC.Ident) (ty : CC.Ty)
    (present : (name, ty) ∈ producer.fn_vars) : Nonempty (Local ce before name ty) := by
  have allocated : CC.AllocVariables ce CC.emptyEnv before producer.fn_vars
      (allocation ce before).1 (allocation ce before).2 :=
    CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation ce before)).symm
  obtain ⟨block, binding⟩ := allocated_local_binding allocated declarations.1 present
  obtain ⟨fresh, owned, range⟩ := (allocated_local_storage allocated).1 _ _ binding
  exact ⟨⟨block, binding, fresh, owned, range⟩⟩

/-- The real producer allocator supplies the header object and permissions. -/
theorem header_local (ce : CC.CompositeEnv) (before : CC.Mem) : Nonempty (HeaderLocal ce before) :=
  local_storage ce before _ _ declarations.2.1

/-- Every actual source object for the 24 header-pointer stores is allocated
with its original type and full declared-range Freeable rights. -/
theorem source_local (ce : CC.CompositeEnv) (before : CC.Mem) (i : Fin 24) : Nonempty (SourceLocal ce before i) :=
  local_storage ce before _ _ (declarations.2.2 i).1

/-- Distinct original local names derive source/header block separation. -/
theorem source_separate (ce : CC.CompositeEnv) (before : CC.Mem) (i : Fin 24)
    (entry : HeaderLocal ce before) (source : SourceLocal ce before i) : source.block ≠ entry.block := by
  have allocated : CC.AllocVariables ce CC.emptyEnv before producer.fn_vars
      (allocation ce before).1 (allocation ce before).2 :=
    CC.doAllocVariables_sound _ _ _ _ _ _ (Prod.eta (allocation ce before)).symm
  exact (allocated_local_storage allocated).2 _ _ _ _ source.binding entry.binding (declarations.2.2 i).2

end KProgFormal.ClightRefinement.X86ProducerHeaderLocals
