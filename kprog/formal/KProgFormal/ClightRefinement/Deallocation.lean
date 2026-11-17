import KProgFormal.ClightRefinement.Frame
import CCLib.Locals

namespace KProgFormal.ClightRefinement

/-- Local bindings point to distinct new blocks whose full declared ranges
remain Freeable. Contents are unrestricted, including undefined bytes. -/
private structure LocalFrame (ce : CC.CompositeEnv) (frontier : CC.Block)
    (e : CC.Env) (m : CC.Mem) : Prop where
  bound : frontier.toNat ≤ m.nextblock.toNat
  live : ∀ i v, e.get i = some v →
    frontier.toNat ≤ v.1.toNat ∧ v.1.toNat < m.nextblock.toNat ∧
    CC.Mem.rangePerm m v.1 0 (CC.sizeof ce v.2) .Cur .Freeable = true
  distinct : ∀ i j v w, e.get i = some v → e.get j = some w → i ≠ j → v.1 ≠ w.1

private theorem binding_set {e : CC.Env} {id query : CC.Ident}
    {value new : CC.Block × CC.Ty} (h : (e.set id new).get query = some value) :
    (query = id ∧ value = new) ∨ (query ≠ id ∧ e.get query = some value) := by
  by_cases hi : id = query
  · subst query
    rw [CC.PTree.gss] at h
    exact Or.inl ⟨rfl, (Option.some.inj h).symm⟩
  · exact Or.inr ⟨Ne.symm hi, by rw [CC.PTree.gso _ _ _ _ hi] at h; exact h⟩

private theorem range_alloc_other (m : CC.Mem) (b : CC.Block) (ty : CC.Ty)
    (lo hi : CC.Z) (hne : b ≠ m.nextblock)
    (h : CC.Mem.rangePerm m b lo hi .Cur .Freeable = true) (ce : CC.CompositeEnv) :
    CC.Mem.rangePerm (CC.Mem.alloc m 0 (CC.sizeof ce ty)).1 b lo hi .Cur .Freeable = true := by
  apply CC.Mem.rangePerm_intro
  intro ofs hlo hhi
  rw [CC.Mem.perm_alloc_other _ _ _ _ hne]
  exact CC.Mem.rangePerm_perm m b lo hi .Cur .Freeable h ofs hlo hhi

private theorem LocalFrame.alloc {ce : CC.CompositeEnv} {frontier : CC.Block}
    {e : CC.Env} {m : CC.Mem} (h : LocalFrame ce frontier e m)
    (id : CC.Ident) (ty : CC.Ty) :
    LocalFrame ce frontier (e.set id (m.nextblock, ty))
      (CC.Mem.alloc m 0 (CC.sizeof ce ty)).1 := by
  have bound := h.bound
  refine ⟨?_, ?_, ?_⟩
  · simp only [CC.Mem.alloc_nextblock, CC.Positive.toNat_succ]
    omega
  · intro query value hv
    rcases binding_set hv with ⟨rfl, rfl⟩ | ⟨_, hold⟩
    · refine ⟨h.bound, ?_, ?_⟩
      · simp only [CC.Mem.alloc_nextblock, CC.Positive.toNat_succ]
        omega
      · apply CC.Mem.rangePerm_intro
        intro ofs hlo hhi
        exact CC.Mem.perm_alloc_same m 0 (CC.sizeof ce ty) ofs .Cur hlo hhi
    · obtain ⟨hlo, hhi, hr⟩ := h.live query value hold
      refine ⟨hlo, ?_, range_alloc_other m value.1 ty _ _ ?_ hr ce⟩
      · simp only [CC.Mem.alloc_nextblock, CC.Positive.toNat_succ]
        omega
      · intro he
        rw [he] at hhi
        omega
  · intro i j v w hi hj hij
    rcases binding_set hi with ⟨rfl, rfl⟩ | ⟨_, hold_i⟩
    · rcases binding_set hj with ⟨rfl, rfl⟩ | ⟨_, hold_j⟩
      · exact False.elim (hij rfl)
      · have upper := (h.live j w hold_j).2.1
        intro he
        have hn := congrArg CC.Positive.toNat he
        dsimp only at hn
        omega
    · rcases binding_set hj with ⟨rfl, rfl⟩ | ⟨_, hold_j⟩
      · have upper := (h.live i v hold_i).2.1
        intro he
        have hn := congrArg CC.Positive.toNat he
        dsimp only at hn
        omega
      · exact h.distinct i j v w hold_i hold_j hij

private theorem LocalFrame.allocVariables {ce : CC.CompositeEnv} {frontier : CC.Block}
    {e e' : CC.Env} {m m' : CC.Mem} {vars : List (CC.Ident × CC.Ty)}
    (h : CC.AllocVariables ce e m vars e' m') (hf : LocalFrame ce frontier e m) :
    LocalFrame ce frontier e' m' := by
  induction h with
  | nil => exact hf
  | cons e m id ty vars m1 b1 m2 e2 ha _ ih =>
    cases ha
    exact ih (hf.alloc id ty)

/-- Every declared local has its actual type in the resulting environment
when the declaration names are distinct. This uses the imported allocation
relation and its environment-preservation lemma. -/
theorem allocated_local_binding {ce : CC.CompositeEnv} {e0 e : CC.Env} {m m1 : CC.Mem}
    {vars : List (CC.Ident × CC.Ty)} {query : CC.Ident} {ty : CC.Ty}
    (halloc : CC.AllocVariables ce e0 m vars e m1)
    (names : CC.listNorepet (CC.varNames vars)) (present : (query, ty) ∈ vars) :
    ∃ block, e.get query = some (block, ty) := by
  induction halloc with
  | nil => simp at present
  | cons e0 m id ty0 rest m2 block m3 e3 ha tail ih =>
    have nr := List.nodup_cons.mp names
    rcases List.mem_cons.mp present with head | member
    · cases head
      rw [CC.allocVariables_env_other tail nr.1]
      exact ⟨block, CC.PTree.gss _ _ _⟩
    · exact ih nr.2 member

/-- The actual local allocator gives every bound local a distinct fresh,
caller-owned block with the full declared range Freeable. No byte contents
are prescribed, and declaration sizes need not be positive for this law. -/
theorem allocated_local_storage {ce : CC.CompositeEnv} {m m1 : CC.Mem} {e : CC.Env}
    {vars : List (CC.Ident × CC.Ty)}
    (halloc : CC.AllocVariables ce CC.emptyEnv m vars e m1) :
    (∀ i v, e.get i = some v →
      m.nextblock.toNat ≤ v.1.toNat ∧ v.1.toNat < m1.nextblock.toNat ∧
      CC.Mem.rangePerm m1 v.1 0 (CC.sizeof ce v.2) .Cur .Freeable = true) ∧
    (∀ i j v w, e.get i = some v → e.get j = some w → i ≠ j → v.1 ≠ w.1) := by
  have initial : LocalFrame ce m.nextblock CC.emptyEnv m := by
    refine ⟨Nat.le_refl _, ?_, ?_⟩
    · intro i v hi
      simp only [CC.emptyEnv, CC.PTree.gempty] at hi
      cases hi
    · intro i j v w hi hj hij
      simp only [CC.emptyEnv, CC.PTree.gempty] at hi
      cases hi
  have frame := LocalFrame.allocVariables halloc initial
  exact ⟨frame.live, frame.distinct⟩

/-- A successful free-list changes permissions only. -/
theorem free_list_shape {before after : CC.Mem} {blocks : List (CC.Block × CC.Z × CC.Z)}
    (freed : CC.Mem.freeList before blocks = some after) :
    after.contents = before.contents ∧ after.nextblock = before.nextblock := by
  induction blocks generalizing before with
  | nil =>
    simp only [CC.Mem.freeList, Option.some.injEq] at freed
    subst after
    exact ⟨rfl, rfl⟩
  | cons row rest ih =>
    rcases row with ⟨block, lo, hi⟩
    cases step : CC.Mem.free before block lo hi with
    | none => simp [CC.Mem.freeList, step] at freed
    | some middle =>
      simp only [CC.Mem.freeList, step] at freed
      obtain ⟨contents, next⟩ := ih freed
      rw [CC.Mem.free_result step] at contents next
      exact ⟨contents, next⟩

private theorem free_list_denied {before after : CC.Mem}
    {blocks : List (CC.Block × CC.Z × CC.Z)}
    (freed : CC.Mem.freeList before blocks = some after)
    (block : CC.Block) (ofs : CC.Z) (kind : CC.PermKind) (permission : CC.Permission)
    (denied : CC.Mem.perm before block ofs kind permission = false) :
    CC.Mem.perm after block ofs kind permission = false := by
  induction blocks generalizing before with
  | nil =>
    simp only [CC.Mem.freeList, Option.some.injEq] at freed
    subst after
    exact denied
  | cons row rest ih =>
    rcases row with ⟨freedBlock, lo, hi⟩
    cases step : CC.Mem.free before freedBlock lo hi with
    | none => simp [CC.Mem.freeList, step] at freed
    | some middle =>
      simp only [CC.Mem.freeList, step] at freed
      apply ih freed
      rw [CC.Mem.free_result step]
      by_cases same : block = freedBlock
      · subst block
        by_cases inside : lo ≤ ofs ∧ ofs < hi
        · exact CC.Mem.perm_free_inside before freedBlock lo hi ofs kind permission inside.1 inside.2
        · have outside : ofs < lo ∨ hi ≤ ofs := by
            by_cases lower : lo ≤ ofs
            · exact .inr (Int.le_of_not_gt (fun upper => inside ⟨lower, upper⟩))
            · exact .inl (Int.lt_of_not_ge lower)
          rw [CC.Mem.perm_free_outside before freedBlock lo hi ofs kind permission outside]
          exact denied
      · rw [CC.Mem.perm_free_other before freedBlock lo hi block same ofs kind permission]
        exact denied

/-- Every range in the actual free-list loses both Cur and Max permissions;
later frees cannot restore access to an already freed local. -/
theorem free_list_released {before after : CC.Mem}
    {blocks : List (CC.Block × CC.Z × CC.Z)}
    (freed : CC.Mem.freeList before blocks = some after) :
    ∀ row ∈ blocks, ∀ ofs, row.2.1 ≤ ofs → ofs < row.2.2 →
      ∀ kind permission, CC.Mem.perm after row.1 ofs kind permission = false := by
  induction blocks generalizing before with
  | nil => intro row member; cases member
  | cons head rest ih =>
    rcases head with ⟨block, lo, hi⟩
    cases step : CC.Mem.free before block lo hi with
    | none => simp [CC.Mem.freeList, step] at freed
    | some middle =>
      simp only [CC.Mem.freeList, step] at freed
      intro row member ofs lower upper kind permission
      rcases List.mem_cons.mp member with same | later
      · subst row
        apply free_list_denied freed block ofs kind permission
        rw [CC.Mem.free_result step]
        exact CC.Mem.perm_free_inside before block lo hi ofs kind permission lower upper
      · exact ih freed row later ofs lower upper kind permission

/-- Actual Freeable local ranges suffice for return.  Local contents and other
blocks may change arbitrarily; the free-list consumes the declared ranges while
retaining all caller bytes and permission maps. -/
theorem deallocate_live_locals {ce : CC.CompositeEnv} {m allocated before : CC.Mem}
    {e : CC.Env} {vars : List (CC.Ident × CC.Ty)}
    (halloc : CC.AllocVariables ce CC.emptyEnv m vars e allocated)
    (owned : ∀ id value, e.get id = some value →
      CC.Mem.rangePerm before value.1 0 (CC.sizeof ce value.2) .Cur .Freeable = true) :
    ∃ after, CC.Mem.freeList before (CC.blocksOfEnv ce e) = some after ∧
      FrameBelow m.nextblock before after ∧ after.contents = before.contents ∧
      after.nextblock = before.nextblock ∧
      (∀ row ∈ CC.blocksOfEnv ce e, ∀ ofs, row.2.1 ≤ ofs → ofs < row.2.2 →
        ∀ kind permission, CC.Mem.perm after row.1 ofs kind permission = false) := by
  obtain ⟨live, separate⟩ := allocated_local_storage halloc
  have rows := CC.PTree.forall_elements_of_get
    (fun v : CC.Block × CC.Ty => m.nextblock.toNat ≤ v.1.toNat ∧
      v.1.toNat < allocated.nextblock.toNat ∧
      CC.Mem.rangePerm before v.1 0 (CC.sizeof ce v.2) .Cur .Freeable = true) e
      (fun id value binding => ⟨(live id value binding).1,
        (live id value binding).2.1, owned id value binding⟩)
  have distinct := CC.PTree.pairwise_elements_of_get
    (fun v w : CC.Block × CC.Ty => v.1 ≠ w.1) e separate
  have ranges : ∀ row ∈ CC.blocksOfEnv ce e,
      CC.Mem.rangePerm before row.1 row.2.1 row.2.2 .Cur .Freeable = true := by
    intro row member
    rcases List.mem_map.mp member with ⟨binding, present, rfl⟩
    exact (rows binding present).2.2
  have pairwise : (CC.blocksOfEnv ce e).Pairwise (fun p q => p.1 ≠ q.1) :=
    distinct.map (CC.blockOfBinding ce) (fun _ _ h => h)
  have fresh : ∀ row ∈ CC.blocksOfEnv ce e, m.nextblock.toNat ≤ row.1.toNat := by
    intro row member
    rcases List.mem_map.mp member with ⟨binding, present, rfl⟩
    exact (rows binding present).1
  obtain ⟨after, freed⟩ := CC.freeList_isSome_of_rangePerm (CC.blocksOfEnv ce e) before ranges pairwise
  obtain ⟨contents, next⟩ := free_list_shape freed
  exact ⟨after, freed, FrameBelow.freeList fresh freed, contents, next, free_list_released freed⟩

/-- The upstream allocator and free-list always complete for an initially
empty local environment. No name, size, memory, or enumeration-order premise
is imposed; any overwritten allocation stays outside the caller's old frame. -/
theorem deallocate_locals {ce : CC.CompositeEnv} {m m1 : CC.Mem} {e : CC.Env}
    {vars : List (CC.Ident × CC.Ty)}
    (halloc : CC.AllocVariables ce CC.emptyEnv m vars e m1) :
    ∃ m2, CC.Mem.freeList m1 (CC.blocksOfEnv ce e) = some m2 ∧
      FrameBelow m.nextblock m m2 := by
  obtain ⟨after, freed, frame, _, _, _⟩ := deallocate_live_locals halloc
    (fun id value binding => ((allocated_local_storage halloc).1 id value binding).2.2)
  exact ⟨after, freed, ((FrameBelow.allocVariables halloc m.nextblock (Nat.le_refl _)).2).trans frame⟩

end KProgFormal.ClightRefinement
