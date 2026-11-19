import KProgFormal.ClightRefinement.Arm64NumericProgram
import KProgFormal.ClightRefinement.Arm64GlobalMemory

set_option Elab.async false

namespace KProgFormal.ClightRefinement.Arm64NumericMemory

open Arm64NumericProgram
open Arm64GlobalMemory (globalAccess hasByteInitializer)

/-- Check every actual data initializer in the complete linked program.
Functions contribute no assumed data-storage or native-input bindings. -/
private theorem variable_sources : ∀ row ∈ program.prog_defs,
    hasByteInitializer row.2 := by decide +kernel

private theorem initialized :
    ∃ memory, program.initMem = some memory ∧ memory.nextblock.toNat = 204 ∧
      FrameBelow CC.Mem.empty.nextblock CC.Mem.empty memory ∧
      ∀ (i : Nat) (row : CC.Ident × CC.GlobDef CC.FunDef CC.Ty),
        program.prog_defs[i]? = some row → ∀ b, b.toNat = 1+i →
          CC.PMap.get b memory.access = globalAccess row.2 := by
  obtain ⟨memory, allocated, next, frame, access⟩ :=
    Arm64GlobalMemory.globals_allocation_bound ge.genv_genv program.prog_defs
      variable_sources CC.Mem.empty
  rw [definition_count] at next
  exact ⟨memory, allocated, next, frame, access⟩

/-- The actual 203-definition world's successful initialization is derived.
It is distinct from the earlier producer world's 189-frontier witness. -/
noncomputable def initialMemory : CC.Mem := Classical.choose initialized

theorem init_mem : program.initMem = some initialMemory :=
  (Classical.choose_spec initialized).1

theorem initial_next : initialMemory.nextblock.toNat = 204 :=
  (Classical.choose_spec initialized).2.1

theorem initial_frame : FrameBelow CC.Mem.empty.nextblock CC.Mem.empty initialMemory :=
  (Classical.choose_spec initialized).2.2.1

/-- Exact permissions of every actual linked definition, including data. -/
theorem initial_access (i : Nat) (row : CC.Ident × CC.GlobDef CC.FunDef CC.Ty)
    (found : program.prog_defs[i]? = some row) (b : CC.Block) (block : b.toNat = 1+i) :
    CC.PMap.get b initialMemory.access = globalAccess row.2 :=
  (Classical.choose_spec initialized).2.2.2 i row found b block

/-- Both permission kinds retain function-only Nonempty; they grant no
read, write or free permission to the instruction block. -/
theorem function_permissions (i : Nat) (id : CC.Ident) (fd : CC.FunDef)
    (found : program.prog_defs[i]? = some (id, .Gfun fd))
    (b : CC.Block) (block : b.toNat = 1+i) (kind : CC.PermKind) :
    CC.Mem.perm initialMemory b 0 kind .Nonempty = true ∧
    CC.Mem.perm initialMemory b 0 kind .Readable = false ∧
    CC.Mem.perm initialMemory b 0 kind .Writable = false ∧
    CC.Mem.perm initialMemory b 0 kind .Freeable = false := by
  simp [CC.Mem.perm, initial_access i _ found b block, globalAccess,
    CC.permOrder', CC.permOrder, CC.Permission.rank]

/-- The actual linked string retains its original block and 48-byte read-only
extent, without equating the two worlds' initialized memories. -/
theorem string_access (ofs : Int) (kind : CC.PermKind) :
    CC.PMap.get (CC.Positive.ofNat 20) initialMemory.access ofs kind =
      if 0 ≤ ofs ∧ ofs < 48 then some .Readable else none := by
  have access := initial_access 19
    (Arm64Program.___stringlit_1, .Gvar Arm64Program.v___stringlit_1)
    (by rfl) (CC.Positive.ofNat 20) (by decide +kernel)
  have size : CC.InitData.listSize Arm64Program.v___stringlit_1.gvar_init = 48 := by decide +kernel
  have permission : CC.Genv.permGlobvar Arm64Program.v___stringlit_1 = .Readable := rfl
  simpa only [globalAccess, size, permission] using congrFun (congrFun access ofs) kind

/-- The empty stderr declaration is allocated but supplies no storage or
native FILE pointer. -/
theorem stderr_access (ofs : Int) (kind : CC.PermKind) :
    CC.PMap.get (CC.Positive.ofNat 61) initialMemory.access ofs kind = none := by
  have access := initial_access 60 (Arm64Program._stderr, .Gvar Arm64Program.v_stderr)
    (by rfl) (CC.Positive.ofNat 61) (by decide +kernel)
  have empty : CC.InitData.listSize Arm64Program.v_stderr.gvar_init = 0 := rfl
  have impossible : ¬ (0 ≤ ofs ∧ ofs < 0) := by omega
  simpa only [globalAccess, empty, impossible, ite_false] using congrFun (congrFun access ofs) kind

/-- Different allocation frontiers rule out identifying this memory with the
older linked producer's initialization witness. -/
theorem distinct_initial_memory : initialMemory ≠ Arm64GlobalMemory.initialMemory := by
  intro equal
  have next := congrArg (fun memory : CC.Mem => memory.nextblock.toNat) equal
  rw [initial_next, Arm64GlobalMemory.initial_next] at next
  contradiction

/-- Function entry in the actual Numeric environment uses the same composite
layout, with this world's initialized memory and its real producer frame. -/
theorem producer_entry (ctx continuation : CC.Val) :
    CC.FunctionEntry2 ge Arm64Producer.producer [ctx, continuation] initialMemory
      (Arm64Producer.allocation initialMemory).1 (Arm64Producer.initialTemps ctx continuation)
      (Arm64Producer.allocation initialMemory).2 :=
  Arm64Producer.entry_valid_bound ge composites_same initialMemory ctx continuation

/-- One genuine allocation transition from an already entered producer call.
Its external input calls and continuation remain later execution obligations. -/
theorem producer_entry_internal (ctx continuation : CC.Val) (k : CC.Cont) :
    InternalRun ge 1 (.Callstate (.Internal Arm64Producer.producer) [ctx, continuation] k initialMemory)
      (.State Arm64Producer.producer Arm64Producer.producer.fn_body k
        (Arm64Producer.allocation initialMemory).1 (Arm64Producer.initialTemps ctx continuation)
        (Arm64Producer.allocation initialMemory).2) :=
  .step trivial (.internal_function _ _ _ _ _ _ _ (producer_entry ctx continuation)) (.refl _)

/-- The actual frame allocation preserves the contents and both permission
maps of all 203 initial global blocks. -/
theorem producer_preserves_globals :
    FrameBelow (CC.Positive.ofNat 204) initialMemory (Arm64Producer.allocation initialMemory).2 := by
  intro b below
  apply Arm64Producer.entry_frame initialMemory b
  rw [CC.Positive.toNat_ofNat _ (by decide)] at below
  simpa only [initial_next] using below

/-- Every actual declared producer local starts beyond the complete linked
world and owns its real Freeable extent in that world's composite layout. -/
theorem local_after_globals (id : CC.Ident) (ty : CC.Ty)
    (present : (id, ty) ∈ Arm64Producer.producer.fn_vars) :
    ∃ block, (Arm64Producer.allocation initialMemory).1.get id = some (block, ty) ∧
      204 ≤ block.toNat ∧ block.toNat < (Arm64Producer.allocation initialMemory).2.nextblock.toNat ∧
      CC.Mem.rangePerm (Arm64Producer.allocation initialMemory).2 block 0 (CC.sizeof ge.genv_cenv ty)
        .Cur .Freeable = true := by
  simpa only [composites_same, initial_next] using
    Arm64Producer.local_storage initialMemory id ty present

/-- Allocation excludes aliases with every initial global, including all
15 appended definitions rather than only the earlier 188. -/
theorem local_global_disjoint (id : CC.Ident) (ty : CC.Ty)
    (present : (id, ty) ∈ Arm64Producer.producer.fn_vars) (block : CC.Block)
    (bound : (Arm64Producer.allocation initialMemory).1.get id = some (block, ty))
    (global : CC.Block) (below : global.toNat < 204) : global ≠ block := by
  obtain ⟨actual, found, fresh, _, _⟩ := local_after_globals id ty present
  have same : actual = block := congrArg Prod.fst (Option.some.inj (found.symm.trans bound))
  subst actual
  intro equal
  rw [equal] at below
  omega

end KProgFormal.ClightRefinement.Arm64NumericMemory
