import KProgFormal.ClightRefinement.Arm64Producer
import KProgFormal.Clight.Arm64ProgramFixture

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64ProgramEntryAllocation

/-- The production binding names its borrowed view differently. Swapping the
names gives an injective map without restricting possible local lookups. -/
def localName (id : CC.Ident) : CC.Ident :=
  if id = Arm64Entry._entry then Arm64ProgramFixture.___a64_entry
  else if id = Arm64ProgramFixture.___a64_entry then Arm64Entry._entry else id

private theorem entry_names_distinct :
    Arm64Entry._entry ≠ Arm64ProgramFixture.___a64_entry := by decide +kernel

private theorem name_involution (id : CC.Ident) : localName (localName id) = id := by
  by_cases first : id = Arm64Entry._entry
  · subst id
    simp [localName, Ne.symm entry_names_distinct]
  · by_cases second : id = Arm64ProgramFixture.___a64_entry
    · subst id
      simp [localName, Ne.symm entry_names_distinct]
    · simp [localName, first, second]

private theorem name_injective : Function.Injective localName := by
  intro a b equal
  simpa only [name_involution] using congrArg localName equal

/-- Only the two anonymous composite tags in the actual local declarations
change. This is not an expression, temporary or function-body renaming. -/
def localType : CC.Ty → CC.Ty
  | .Tarray (.Tstruct id attr) size arrayAttr =>
      .Tarray (.Tstruct (if id = Arm64Entry.__2854 then Arm64ProgramFixture.__5183 else id)
        attr) size arrayAttr
  | .Tunion id attr =>
      .Tunion (if id = Arm64Entry.__2856 then Arm64ProgramFixture.__5185 else id) attr
  | ty => ty

def declaration (row : CC.Ident × CC.Ty) : CC.Ident × CC.Ty :=
  (localName row.1, localType row.2)

def world : CC.CGenv := Arm64ProgramFixture.prog.globalenv

def allocation (m : CC.Mem) : CC.Env × CC.Mem :=
  CC.doAllocVariables world.genv_cenv CC.emptyEnv m
    Arm64ProgramFixture.f_arm64_execute_compile.fn_vars

/-- Complete composite records retain member types/order, attributes, size,
alignment and rank under the two actual anonymous source tags. The named
borrowed-entry header has exactly the same layout in both source units. -/
theorem composite_layouts :
    world.genv_cenv.get Arm64ProgramFixture.__5183 =
      Arm64Producer.ge.genv_cenv.get Arm64Entry.__2854 ∧
    world.genv_cenv.get Arm64ProgramFixture.__5185 =
      Arm64Producer.ge.genv_cenv.get Arm64Entry.__2856 ∧
    world.genv_cenv.get Arm64ProgramFixture._kprog_arm64_entry =
      Arm64Producer.ge.genv_cenv.get Arm64Entry._kprog_arm64_entry := by decide +kernel

/-- Kernel comparison of every actual declaration, not just their sizes. -/
theorem declarations : Arm64ProgramFixture.f_arm64_execute_compile.fn_vars =
    Arm64Producer.producer.fn_vars.map declaration := by decide +kernel

private theorem sizes_at : ∀ i : Fin Arm64Producer.producer.fn_vars.length,
    CC.sizeof world.genv_cenv (localType Arm64Producer.producer.fn_vars[i].2) =
      CC.sizeof Arm64Producer.ge.genv_cenv Arm64Producer.producer.fn_vars[i].2 := by
  decide +kernel

theorem local_size (row : CC.Ident × CC.Ty) (present : row ∈ Arm64Producer.producer.fn_vars) :
    CC.sizeof world.genv_cenv (localType row.2) =
      CC.sizeof Arm64Producer.ge.genv_cenv row.2 := by
  obtain ⟨i, rfl⟩ := List.mem_iff_get.mp present
  exact sizes_at i

def EnvsCorrespond (source actual : CC.Env) : Prop :=
  ∀ id, actual.get (localName id) =
    (source.get id).map (fun value => (value.1, localType value.2))

private theorem env_set {source actual : CC.Env} (related : EnvsCorrespond source actual)
    (id : CC.Ident) (block : CC.Block) (ty : CC.Ty) :
    EnvsCorrespond (source.set id (block, ty))
      (actual.set (localName id) (block, localType ty)) := by
  intro queried
  by_cases equal : queried = id
  · subst queried
    simp only [CC.PTree.gss, Option.map_some]
  · rw [CC.PTree.gso, CC.PTree.gso]
    · exact related queried
    · exact Ne.symm equal
    · exact fun same => equal (name_injective same).symm

private theorem allocate_declarations (sourceCE actualCE : CC.CompositeEnv) (vars : List (CC.Ident × CC.Ty))
    (sizes : ∀ row ∈ vars, CC.sizeof actualCE (localType row.2) =
      CC.sizeof sourceCE row.2)
    (m : CC.Mem) (source actual : CC.Env) (related : EnvsCorrespond source actual) :
    (CC.doAllocVariables sourceCE source m vars).2 =
      (CC.doAllocVariables actualCE actual m (vars.map declaration)).2 ∧
    EnvsCorrespond (CC.doAllocVariables sourceCE source m vars).1
      (CC.doAllocVariables actualCE actual m (vars.map declaration)).1 := by
  induction vars generalizing source actual m with
  | nil => exact ⟨rfl, related⟩
  | cons row rest ih =>
    rcases row with ⟨id, ty⟩
    have size := sizes (id, ty) List.mem_cons_self
    simpa only [CC.doAllocVariables, List.map_cons, declaration, size] using
      ih (fun row present => sizes row (List.mem_cons_of_mem _ present))
        (CC.Mem.alloc m 0 (CC.sizeof sourceCE ty)).1
        (source.set id ((CC.Mem.alloc m 0 (CC.sizeof sourceCE ty)).2, ty))
        (actual.set (localName id)
          ((CC.Mem.alloc m 0 (CC.sizeof sourceCE ty)).2, localType ty))
        (env_set related id _ ty)

/-- The real production function allocates exactly the same memory as the
extracted producer, for every incoming memory. Local references preserve their
blocks and offsets while their source names/types correspond. No allocation
outcome, successful initialization or continuation binding is assumed. -/
theorem allocation_corresponds (m : CC.Mem) :
    (Arm64Producer.allocation m).2 = (allocation m).2 ∧
    EnvsCorrespond (Arm64Producer.allocation m).1 (allocation m).1 := by
  rw [allocation, declarations]
  exact allocate_declarations Arm64Producer.ge.genv_cenv world.genv_cenv
    Arm64Producer.producer.fn_vars local_size m CC.emptyEnv CC.emptyEnv
      (fun _ => by simp only [CC.emptyEnv, CC.PTree.gempty, Option.map_none])

theorem local_binding (m : CC.Mem) (id : CC.Ident) (block : CC.Block) (ty : CC.Ty)
    (bound : (Arm64Producer.allocation m).1.get id = some (block, ty)) :
    (allocation m).1.get (localName id) = some (block, localType ty) := by
  rw [(allocation_corresponds m).2 id, bound]
  rfl

/-- Actual local ownership follows from the imported allocator and the source
layout correspondence. This covers the entry view and both anonymous storage
objects with identical fresh block identities and complete Freeable ranges. -/
theorem local_storage (m : CC.Mem) (id : CC.Ident) (ty : CC.Ty)
    (present : (id, ty) ∈ Arm64Producer.producer.fn_vars) :
    ∃ block, (allocation m).1.get (localName id) = some (block, localType ty) ∧
      m.nextblock.toNat ≤ block.toNat ∧ block.toNat < (allocation m).2.nextblock.toNat ∧
      CC.Mem.rangePerm (allocation m).2 block 0
        (CC.sizeof world.genv_cenv (localType ty)) .Cur .Freeable = true := by
  obtain ⟨block, bound, lower, upper, owned⟩ := Arm64Producer.local_storage m id ty present
  refine ⟨block, local_binding m id block ty bound, lower, ?_, ?_⟩
  · simpa only [← (allocation_corresponds m).1] using upper
  · simpa only [← (allocation_corresponds m).1, local_size (id, ty) present] using owned

end KProgFormal.ClightRefinement.Arm64ProgramEntryAllocation
