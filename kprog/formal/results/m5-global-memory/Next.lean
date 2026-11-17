import KProgFormal.ClightRefinement.Arm64GlobalMemory
set_option Elab.async false
namespace KProgFormal.ClightRefinement.Arm64GlobalMemory.Inspection
open Arm64Producer

-- Actual source census: 186 functions and two data globals, not 188 functions.
example : (Binding.program.prog_defs.filter fun row => match row.2 with
    | .Gfun _ => true | .Gvar _ => false).length = 186 := by
  rw [Binding.linked_definitions]
  decide +kernel

example : (Binding.program.prog_defs.zipIdx.filterMap fun (row, i) => match row.2 with
    | .Gfun _ => none
    | .Gvar var => some (i+1, var.gvar_init.length, var.gvar_readonly, var.gvar_volatile)) =
    [(20, 48, true, false), (61, 0, false, false)] := by
  rw [Binding.linked_definitions]
  decide +kernel

-- Source-backed input and appended entry-unit pointers have real function
-- permissions in the initialized memory. These do not execute a provider/body.
example (k : CC.PermKind) : CC.Mem.perm initialMemory (CC.Positive.ofNat 64) 0 k .Nonempty = true := by
  exact (function_permissions 63 Arm64Program._native_lab_entry_input Arm64OriginCache.inputFunction (by
    rw [Binding.linked_definitions]; rfl) _ (by decide +kernel) k).1

example (k : CC.PermKind) : CC.Mem.perm initialMemory (CC.Positive.ofNat 184) 0 k .Nonempty = true := by
  exact (function_permissions 183 Arm64Entry._kprog_arm64_payload_load (.Internal Arm64Entry.f_kprog_arm64_payload_load) (by
    rw [Binding.linked_definitions]; rfl) _ (by decide +kernel) k).1

example (k : CC.PermKind) : CC.Mem.perm initialMemory (CC.Positive.ofNat 185) 0 k .Nonempty = true := by
  exact (function_permissions 184 Arm64Entry._kprog_arm64_payload_store (.Internal Arm64Entry.f_kprog_arm64_payload_store) (by
    rw [Binding.linked_definitions]; rfl) _ (by decide +kernel) k).1

example (k : CC.PermKind) : CC.Mem.perm initialMemory (CC.Positive.ofNat 186) 0 k .Nonempty = true := by
  exact (function_permissions 185 Arm64Entry._kprog_arm64_entry_raw (.Internal producer) (by
    rw [Binding.linked_definitions]; rfl) _ (by decide +kernel) k).1

example (k : CC.PermKind) : CC.Mem.perm initialMemory (CC.Positive.ofNat 188) 0 k .Nonempty = true := by
  exact (function_permissions 187 Arm64Entry._kprog_arm64_entry_skb (.Internal Arm64Entry.f_kprog_arm64_entry_skb) (by
    rw [Binding.linked_definitions]; rfl) _ (by decide +kernel) k).1


-- The byte before/after the string is inaccessible; its last byte is readable.
example (k : CC.PermKind) :
    CC.Mem.perm initialMemory (CC.Positive.ofNat 20) 47 k .Readable = true ∧
    CC.Mem.perm initialMemory (CC.Positive.ofNat 20) 48 k .Nonempty = false ∧
    CC.Mem.perm initialMemory (CC.Positive.ofNat 20) (-1) k .Nonempty = false := by
  simp [CC.Mem.perm, string_access, CC.permOrder', CC.permOrder, CC.Permission.rank]

example (k : CC.PermKind) : CC.Mem.perm initialMemory (CC.Positive.ofNat 61) 0 k .Nonempty = false := by
  simp [CC.Mem.perm, stderr_access, CC.permOrder']

-- Instantiates actual entry-local allocation rather than assuming a good block.
example : ∃ block, (allocation initialMemory).1.get Arm64Entry._entry =
      some (block, .Tstruct Arm64Entry._kprog_arm64_entry CC.noattr) ∧ 189 ≤ block.toNat := by
  obtain ⟨block, found, fresh, _, _⟩ := local_after_globals Arm64Entry._entry
    (.Tstruct Arm64Entry._kprog_arm64_entry CC.noattr) (by decide +kernel)
  exact ⟨block, found, fresh⟩
end KProgFormal.ClightRefinement.Arm64GlobalMemory.Inspection
