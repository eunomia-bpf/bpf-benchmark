import KProgFormal.ClightRefinement.Arm64Producer

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64GlobalMemory

open Arm64Producer

/-- Final access of a global, using the imported extent and permission rules. -/
def globalAccess (definition : CC.GlobDef CC.FunDef CC.Ty)
    (ofs : CC.Z) (_ : CC.PermKind) : Option CC.Permission :=
  match definition with
  | .Gfun _ => if 0 ≤ ofs ∧ ofs < 1 then some .Nonempty else none
  | .Gvar var => if 0 ≤ ofs ∧ ofs < CC.InitData.listSize var.gvar_init
      then some (CC.Genv.permGlobvar var) else none

private theorem positive_injective {a b : CC.Positive} (same : a.toNat = b.toNat) : a = b := by
  induction a generalizing b with
  | xH => cases b with
    | xH => rfl
    | xO b => have := CC.Positive.toNat_pos b; simp only [CC.Positive.toNat] at same; omega
    | xI b => have := CC.Positive.toNat_pos b; simp only [CC.Positive.toNat] at same; omega
  | xO a ih => cases b with
    | xH => have := CC.Positive.toNat_pos a; simp only [CC.Positive.toNat] at same; omega
    | xO b => congr 1; apply ih; simp only [CC.Positive.toNat] at same; omega
    | xI b => simp only [CC.Positive.toNat] at same; omega
  | xI a ih => cases b with
    | xH => have := CC.Positive.toNat_pos a; simp only [CC.Positive.toNat] at same; omega
    | xO b => simp only [CC.Positive.toNat] at same; omega
    | xI b => congr 1; apply ih; simp only [CC.Positive.toNat] at same; omega

private theorem byte_store (m : CC.Mem) (b : CC.Block) (size ofs : Int) (value : CC.Val)
    (free : CC.Mem.rangePerm m b 0 size .Cur .Freeable = true)
    (lower : 0 ≤ ofs) (upper : ofs < size) :
    ∃ after, CC.Mem.store .Mint8unsigned m b ofs value = some after ∧
      after.access = m.access ∧ after.nextblock = m.nextblock ∧ FrameBelow b m after := by
  have writable : CC.Mem.rangePerm m b ofs (ofs + 1) .Cur .Writable = true := by
    apply CC.Mem.rangePerm_intro
    intro offset least most
    apply CC.Mem.perm_implies (CC.Mem.rangePerm_perm m b 0 size .Cur .Freeable free offset
      (by omega) (by omega)) (by decide)
  have valid : CC.Mem.validAccess m .Mint8unsigned b ofs .Writable = true := by
    simpa [CC.Mem.validAccess, CC.sizeChunk, CC.alignChunk] using writable
  have success : (CC.Mem.store .Mint8unsigned m b ofs value).isSome = true := by
    simp [CC.Mem.store, valid]
  cases stored : CC.Mem.store .Mint8unsigned m b ofs value with
  | none => simp [stored] at success
  | some after => exact ⟨after, rfl, CC.Mem.store_access stored, CC.Mem.store_nextblock stored,
      FrameBelow.store (Nat.le_refl _) stored⟩

private theorem store_zeros (m : CC.Mem) (b : CC.Block) (size ofs : Int) (count : Nat)
    (free : CC.Mem.rangePerm m b 0 size .Cur .Freeable = true)
    (lower : 0 ≤ ofs) (upper : ofs + count ≤ size) :
    ∃ after, CC.Genv.storeZerosAux m b ofs count = some after ∧
      after.access = m.access ∧ after.nextblock = m.nextblock ∧ FrameBelow b m after := by
  induction count generalizing m ofs with
  | zero => exact ⟨m, rfl, rfl, rfl, FrameBelow.refl _ _⟩
  | succ n ih =>
    obtain ⟨mid, stored, access, next, frame⟩ := byte_store m b size ofs
      (.Vint CC.Integers.Int.zero) free lower (by omega)
    have freeMid : CC.Mem.rangePerm mid b 0 size .Cur .Freeable = true := by
      exact (CC.Mem.rangePerm_congr (fun ofs => by simp only [CC.Mem.perm, access])).trans free
    obtain ⟨after, tail, accessTail, nextTail, frameTail⟩ := ih mid (ofs+1) freeMid (by omega) (by omega)
    refine ⟨after, ?_, accessTail.trans access, nextTail.trans next, frame.trans frameTail⟩
    simp only [CC.Genv.storeZerosAux, stored]
    exact tail

private theorem store_bytes {F V : Type} (ge : CC.Genv F V) (values : List CC.Integers.Int)
    (m : CC.Mem) (b : CC.Block) (size ofs : Int)
    (free : CC.Mem.rangePerm m b 0 size .Cur .Freeable = true)
    (lower : 0 ≤ ofs) (upper : ofs + values.length ≤ size) :
    ∃ after, CC.Genv.storeInitDataList ge m b ofs (values.map CC.InitData.Init_int8) = some after ∧
      after.access = m.access ∧ after.nextblock = m.nextblock ∧ FrameBelow b m after := by
  induction values generalizing m ofs with
  | nil => exact ⟨m, rfl, rfl, rfl, FrameBelow.refl _ _⟩
  | cons value rest ih =>
    obtain ⟨mid, stored, access, next, frame⟩ := byte_store m b size ofs (.Vint value) free lower (by simp only [List.length_cons] at upper; omega)
    have freeMid : CC.Mem.rangePerm mid b 0 size .Cur .Freeable = true := by
      exact (CC.Mem.rangePerm_congr (fun ofs => by simp only [CC.Mem.perm, access])).trans free
    obtain ⟨after, tail, accessTail, nextTail, frameTail⟩ := ih mid (ofs+1) freeMid (by omega) (by
      simp only [List.length_cons] at upper; omega)
    refine ⟨after, ?_, accessTail.trans access, nextTail.trans next, frame.trans frameTail⟩
    simp only [List.map_cons, CC.Genv.storeInitDataList, CC.Genv.storeInitData, stored, CC.InitData.size]
    exact tail

private theorem bytes_size (values : List CC.Integers.Int) :
    CC.InitData.listSize (values.map CC.InitData.Init_int8) = values.length := by
  induction values with
  | nil => rfl
  | cons value rest ih =>
    change 1 + CC.InitData.listSize (rest.map CC.InitData.Init_int8) = _
    rw [ih]
    change (1 : Int) + (rest.length : Int) = ((rest.length + 1 : Nat) : Int)
    omega

private theorem byte_global (m : CC.Mem) (id : CC.Ident) (var : CC.GlobVar CC.Ty)
    (values : List CC.Integers.Int) (source : var.gvar_init = values.map CC.InitData.Init_int8) :
    ∃ after, CC.Genv.allocGlobal Binding.ge.genv_genv m (id, .Gvar var) = some after ∧
      after.nextblock = m.nextblock.succ ∧ FrameBelow m.nextblock m after ∧
      CC.PMap.get m.nextblock after.access = globalAccess (.Gvar var) := by
  let size := CC.InitData.listSize var.gvar_init
  have sizeEq : size = values.length := by simp only [size, source, bytes_size]
  have free : CC.Mem.rangePerm (CC.Mem.alloc m 0 size).1 m.nextblock 0 size .Cur .Freeable = true := by
    apply CC.Mem.rangePerm_intro
    intro ofs lower upper
    exact CC.Mem.perm_alloc_same m 0 size ofs .Cur lower upper
  obtain ⟨zeroed, zeros, zeroAccess, zeroNext, zeroFrame⟩ := store_zeros
    (CC.Mem.alloc m 0 size).1 m.nextblock size 0 values.length free (by decide) (by rw [sizeEq]; simp)
  have zeroFree : CC.Mem.rangePerm zeroed m.nextblock 0 size .Cur .Freeable = true := by
    exact (CC.Mem.rangePerm_congr (fun ofs => by simp only [CC.Mem.perm, zeroAccess])).trans free
  obtain ⟨filled, fills, fillAccess, fillNext, fillFrame⟩ := store_bytes Binding.ge.genv_genv values
    zeroed m.nextblock size 0 zeroFree (by decide) (by rw [sizeEq]; simp)
  have fillFree : CC.Mem.rangePerm filled m.nextblock 0 size .Cur .Freeable = true := by
    exact (CC.Mem.rangePerm_congr (fun ofs => by simp only [CC.Mem.perm, fillAccess])).trans zeroFree
  have dropped : (CC.Mem.dropPerm filled m.nextblock 0 size (CC.Genv.permGlobvar var)).isSome = true := by
    simp only [CC.Mem.dropPerm, dite_eq_left fillFree, Option.isSome_some]
  cases drop : CC.Mem.dropPerm filled m.nextblock 0 size (CC.Genv.permGlobvar var) with
  | none => simp [drop] at dropped
  | some after =>
    have dropFields : after.contents = filled.contents ∧ after.nextblock = filled.nextblock ∧
        after.access = CC.PMap.set m.nextblock
          (fun ofs k => if 0 ≤ ofs ∧ ofs < size then some (CC.Genv.permGlobvar var)
            else CC.PMap.get m.nextblock filled.access ofs k) filled.access := by
      simp only [CC.Mem.dropPerm, dite_eq_left fillFree, Option.some.injEq] at drop
      cases drop
      exact ⟨rfl, rfl, rfl⟩
    refine ⟨after, ?_, ?_, ?_, ?_⟩
    · simp only [CC.Genv.allocGlobal, CC.Mem.alloc_result]
      have zeros' : CC.Genv.storeZeros (CC.Mem.alloc m 0 size).1 m.nextblock 0 size = some zeroed := by
        simpa only [CC.Genv.storeZeros, sizeEq, Int.toNat_natCast] using zeros
      rw [zeros']
      dsimp only
      rw [source, fills]
      dsimp only
      simpa only [size, source] using drop
    · rw [dropFields.2.1, fillNext, zeroNext, CC.Mem.alloc_nextblock]
    · have initFrame := (FrameBelow.alloc m.nextblock m 0 size (Nat.le_refl _)).trans (zeroFrame.trans fillFrame)
      exact initFrame.trans (by
        intro b below
        have distinct : m.nextblock ≠ b := by intro eq; rw [eq] at below; omega
        simp only [dropFields.1, dropFields.2.2, CC.PMap.gso _ _ _ _ distinct, and_self])
    · rw [dropFields.2.2, CC.PMap.gss, fillAccess, zeroAccess, CC.Mem.alloc_access, CC.PMap.gss]
      funext ofs k
      dsimp only [globalAccess]
      by_cases inside : 0 ≤ ofs ∧ ofs < size
      all_goals simp only [size] at inside
      all_goals simp [size, inside]

private theorem function_global (m : CC.Mem) (id : CC.Ident) (fd : CC.FunDef) :
    ∃ after, CC.Genv.allocGlobal Binding.ge.genv_genv m (id, .Gfun fd) = some after ∧
      after.nextblock = m.nextblock.succ ∧ FrameBelow m.nextblock m after ∧
      CC.PMap.get m.nextblock after.access = globalAccess (.Gfun fd) := by
  have free : CC.Mem.rangePerm (CC.Mem.alloc m 0 1).1 m.nextblock 0 1 .Cur .Freeable = true := by
    apply CC.Mem.rangePerm_intro
    intro ofs lower upper
    exact CC.Mem.perm_alloc_same m 0 1 ofs .Cur lower upper
  change ∃ after, CC.Mem.dropPerm (CC.Mem.alloc m 0 1).1 m.nextblock 0 1 .Nonempty = some after ∧ _
  rw [CC.Mem.dropPerm, dite_eq_left free]
  refine ⟨_, rfl, rfl, ?_, ?_⟩
  · intro b below
    have distinct : m.nextblock ≠ b := by intro eq; rw [eq] at below; omega
    simp only [CC.Mem.alloc_contents, CC.Mem.alloc_access, CC.PMap.gso _ _ _ _ distinct, and_self]
  · funext ofs kind
    simp only [CC.PMap.gss, CC.Mem.alloc_access, globalAccess]
    by_cases inside : 0 ≤ ofs ∧ ofs < 1 <;> simp [inside]

private def stringBytes : List CC.Integers.Int :=
  Arm64Program.v___stringlit_1.gvar_init.filterMap fun
    | .Init_int8 n => some n
    | _ => none

private def hasByteInitializer : CC.GlobDef CC.FunDef CC.Ty → Prop
  | .Gfun _ => True
  | .Gvar var => var.gvar_init = Arm64Program.v___stringlit_1.gvar_init ∨ var.gvar_init = []

private instance (definition : CC.GlobDef CC.FunDef CC.Ty) : Decidable (hasByteInitializer definition) := by
  cases definition with
  | Gfun _ => exact isTrue trivial
  | Gvar _ => exact inferInstanceAs (Decidable (_ = _ ∨ _ = ([] : List CC.InitData)))

private theorem variable_sources : ∀ row ∈ Binding.program.prog_defs, hasByteInitializer row.2 := by
  rw [Binding.linked_definitions]
  decide +kernel

private theorem global_allocation (row : CC.Ident × CC.GlobDef CC.FunDef CC.Ty)
    (member : row ∈ Binding.program.prog_defs) (m : CC.Mem) :
    ∃ after, CC.Genv.allocGlobal Binding.ge.genv_genv m row = some after ∧
      after.nextblock = m.nextblock.succ ∧ FrameBelow m.nextblock m after ∧
      CC.PMap.get m.nextblock after.access = globalAccess row.2 := by
  have source := variable_sources row member
  rcases row with ⟨id, fd | var⟩
  · exact function_global m id fd
  · rcases source with source | source
    · exact byte_global m id var stringBytes (source.trans (by rfl))
    · exact byte_global m id var [] source

/-- Fold the actual allocator. The indexed access result also retains data
initializers; a function-only census would miss the two real data globals. -/
private theorem globals_allocation (defs : List (CC.Ident × CC.GlobDef CC.FunDef CC.Ty))
    (members : ∀ row ∈ defs, row ∈ Binding.program.prog_defs) (m : CC.Mem) :
    ∃ after, CC.Genv.allocGlobals Binding.ge.genv_genv m defs = some after ∧
      after.nextblock.toNat = m.nextblock.toNat + defs.length ∧
      FrameBelow m.nextblock m after ∧
      ∀ (i : Nat) (row : CC.Ident × CC.GlobDef CC.FunDef CC.Ty), defs[i]? = some row →
        ∀ b, b.toNat = m.nextblock.toNat + i →
          CC.PMap.get b after.access = globalAccess row.2 := by
  induction defs generalizing m with
  | nil =>
    refine ⟨m, rfl, by simp, FrameBelow.refl _ _, ?_⟩
    intro i row found
    simp at found
  | cons head rest ih =>
    obtain ⟨mid, allocated, next, frame, access⟩ := global_allocation head
      (members head List.mem_cons_self) m
    obtain ⟨after, tail, tailNext, tailFrame, tailStorage⟩ :=
      ih (fun row mem => members row (List.mem_cons_of_mem _ mem)) mid
    have nextNat : mid.nextblock.toNat = m.nextblock.toNat + 1 := by
      rw [next, CC.Positive.toNat_succ]
    refine ⟨after, ?_, ?_, ?_, ?_⟩
    · simp only [CC.Genv.allocGlobals, allocated]; exact tail
    · simp only [List.length_cons]; omega
    · exact frame.trans (fun b below => tailFrame b (by omega))
    · intro i row found b block
      cases i with
      | zero =>
        simp only [List.getElem?_cons_zero, Option.some.injEq] at found
        subst row
        have same : b = m.nextblock := positive_injective (by simpa using block)
        subst b
        exact (tailFrame m.nextblock (by omega)).2.trans access
      | succ i =>
        apply tailStorage i row (by simpa using found) b
        omega

private theorem definitions_count : Binding.program.prog_defs.length = 188 := by
  rw [Binding.linked_definitions]
  rfl

private theorem initialized :
    ∃ m, Binding.program.initMem = some m ∧ m.nextblock.toNat = 189 ∧
      ∀ (i : Nat) (row : CC.Ident × CC.GlobDef CC.FunDef CC.Ty),
        Binding.program.prog_defs[i]? = some row → ∀ b, b.toNat = 1+i →
          CC.PMap.get b m.access = globalAccess row.2 := by
  obtain ⟨m, allocated, next, _, storage⟩ :=
    globals_allocation Binding.program.prog_defs (fun _ member => member) CC.Mem.empty
  rw [definitions_count] at next
  exact ⟨m, allocated, next, storage⟩

/-- Successful initialization of the actual linked program is derived, not
an assumed native-input or successful-allocation premise. -/
noncomputable def initialMemory : CC.Mem := Classical.choose initialized

theorem init_mem : Binding.program.initMem = some initialMemory :=
  (Classical.choose_spec initialized).1

theorem initial_next : initialMemory.nextblock.toNat = 189 :=
  (Classical.choose_spec initialized).2.1

/-- Exact initial access for every definition, including the two data globals. -/
theorem initial_access (i : Nat) (row : CC.Ident × CC.GlobDef CC.FunDef CC.Ty)
    (found : Binding.program.prog_defs[i]? = some row) (b : CC.Block) (block : b.toNat = 1+i) :
    CC.PMap.get b initialMemory.access = globalAccess row.2 :=
  (Classical.choose_spec initialized).2.2 i row found b block

/-- An actual function block has Nonempty, and no read/write/free permission,
for both Cur and Max. Data globals require their own imported extent/rules. -/
theorem function_permissions (i : Nat) (id : CC.Ident) (fd : CC.FunDef)
    (found : Binding.program.prog_defs[i]? = some (id, .Gfun fd))
    (b : CC.Block) (block : b.toNat = 1+i) (k : CC.PermKind) :
    CC.Mem.perm initialMemory b 0 k .Nonempty = true ∧
    CC.Mem.perm initialMemory b 0 k .Readable = false ∧
    CC.Mem.perm initialMemory b 0 k .Writable = false ∧
    CC.Mem.perm initialMemory b 0 k .Freeable = false := by
  simp [CC.Mem.perm, initial_access i _ found b block, globalAccess,
    CC.permOrder', CC.permOrder, CC.Permission.rank]

private theorem string_size : CC.InitData.listSize Arm64Program.v___stringlit_1.gvar_init = 48 := by
  decide +kernel

/-- The genuine read-only string occupies block20 with its full 48-byte extent. -/
theorem string_access (ofs : Int) (k : CC.PermKind) :
    CC.PMap.get (CC.Positive.ofNat 20) initialMemory.access ofs k =
      if 0 ≤ ofs ∧ ofs < 48 then some .Readable else none := by
  have access := initial_access 19
    (Arm64Program.___stringlit_1, .Gvar Arm64Program.v___stringlit_1) (by
      rw [Binding.linked_definitions]; rfl) (CC.Positive.ofNat 20) (by decide +kernel)
  have permission : CC.Genv.permGlobvar Arm64Program.v___stringlit_1 = .Readable := rfl
  simpa only [globalAccess, string_size, permission] using congrFun (congrFun access ofs) k

/-- The exported empty stderr declaration receives a block but no storage or
permission. It is not a supplied native FILE pointer or context. -/
theorem stderr_access (ofs : Int) (k : CC.PermKind) :
    CC.PMap.get (CC.Positive.ofNat 61) initialMemory.access ofs k = none := by
  have access := initial_access 60
    (Arm64Program._stderr, .Gvar Arm64Program.v_stderr) (by
      rw [Binding.linked_definitions]; rfl) (CC.Positive.ofNat 61) (by decide +kernel)
  have empty : CC.InitData.listSize Arm64Program.v_stderr.gvar_init = 0 := rfl
  have impossible : ¬ (0 ≤ ofs ∧ ofs < 0) := by omega
  simpa only [globalAccess, empty, impossible, ite_false] using congrFun (congrFun access ofs) k

/-- Actual producer allocation retains every global byte and both access maps. -/
theorem entry_preserves_globals :
    FrameBelow (CC.Positive.ofNat 189) initialMemory (allocation initialMemory).2 := by
  intro b below
  apply entry_frame initialMemory b
  rw [CC.Positive.toNat_ofNat _ (by decide)] at below
  simpa only [initial_next] using below

/-- Every actual local starts after all globals and has its complete Freeable
range, without a caller-supplied allocation result or alias premise. -/
theorem local_after_globals (id : CC.Ident) (ty : CC.Ty) (present : (id, ty) ∈ producer.fn_vars) :
    ∃ block, (allocation initialMemory).1.get id = some (block, ty) ∧
      189 ≤ block.toNat ∧ block.toNat < (allocation initialMemory).2.nextblock.toNat ∧
      CC.Mem.rangePerm (allocation initialMemory).2 block 0 (CC.sizeof ge.genv_cenv ty)
        .Cur .Freeable = true := by
  simpa only [initial_next] using local_storage initialMemory id ty present

/-- No actual producer local can alias any initial global block. -/
theorem local_global_disjoint (id : CC.Ident) (ty : CC.Ty)
    (present : (id, ty) ∈ producer.fn_vars) (block : CC.Block)
    (bound : (allocation initialMemory).1.get id = some (block, ty))
    (global : CC.Block) (below : global.toNat < 189) : global ≠ block := by
  obtain ⟨actual, found, fresh, _, _⟩ := local_after_globals id ty present
  have same : actual = block := by
    have := Option.some.inj (found.symm.trans bound)
    exact congrArg Prod.fst this
  subst actual
  intro equal
  rw [equal] at below
  omega

end KProgFormal.ClightRefinement.Arm64GlobalMemory
