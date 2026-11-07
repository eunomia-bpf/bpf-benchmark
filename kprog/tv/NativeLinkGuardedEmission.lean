import NativeLinkMovabs

/-! Existing kernel emitter guards protect original nonzero code bytes.
CALL checks use the current destination; literal checks use the immutable
snapshot. Every memory update uses the canonical reference writer. -/
namespace KProgTV.NativeLinkGuardedEmission
open KProgFormal.Reference NativeLinkPatchTable

def ZeroWrite (code : Memory) (patch : Patch) : Prop :=
  ∀ i<writeSize patch, code.value (writeAddress patch+BitVec.ofNat 64 i)=0

def EmitGuard (original current : Memory) : Patch → Prop
  | .call record => (bytesAt current record.slot 5).toArray=#[0xe8,0,0,0,0]
  | .literal slot _ => bytesAt original slot 8=List.replicate 8 (0#8)

def CheckedTable (original : Memory) : Memory → List Patch → Prop
  | _,[] => True
  | current,patch::rest => EmitGuard original current patch ∧
      CheckedTable original (applyPatch current patch) rest

def PreservesNonzero (original current : Memory) : Prop :=
  ∀ address, original.value address≠0 → current.value address=original.value address

theorem zero_span (code : Memory) (slot : Word) (count : Nat)
    (zero : bytesAt code slot count=List.replicate count (0#8)) :
    ∀ i<count, code.value (slot+BitVec.ofNat 64 i)=0 := by
  intro i small
  have inside : code.value (slot+BitVec.ofNat 64 i)∈bytesAt code slot count :=
    List.mem_map.mpr ⟨i,List.mem_range.mpr small,rfl⟩
  rw [zero] at inside
  simp only [List.mem_replicate] at inside
  exact inside.2

theorem call_guard_zero (original current : Memory) (record : NativeLinkRelocationTable.Patch)
    (accepted : EmitGuard original current (.call record)) : ZeroWrite current (.call record) := by
  intro i small
  change i<4 at small
  have cases : i=0 ∨ i=1 ∨ i=2 ∨ i=3 := by omega
  rcases cases with rfl | rfl | rfl | rfl
  all_goals change (bytesAt current record.slot 5).toArray=#[0xe8,0,0,0,0] at accepted
  all_goals have same := congrArg Array.toList accepted
  all_goals simp +decide [bytesAt,List.range_succ,List.range_zero,List.map_append,
    List.map_cons,List.map_nil,List.map_singleton] at same
  all_goals simp only [writeAddress]
  all_goals first
    | (simpa +decide [BitVec.add_assoc] using same.2.1)
    | (simpa +decide [BitVec.add_assoc] using same.2.2.1)
    | (simpa +decide [BitVec.add_assoc] using same.2.2.2.1)
    | (simpa +decide [BitVec.add_assoc] using same.2.2.2.2)

/-- A checked write field lies outside every original nonzero byte. -/
theorem guard_outside_nonzero (original current : Memory) (patch : Patch)
    (preserved : PreservesNonzero original current) (accepted : EmitGuard original current patch)
    (address : Word) (nonzero : original.value address≠0) : OutsideWrite address patch := by
  change writeSize patch≤(address-writeAddress patch).toNat
  apply Nat.le_of_not_lt
  intro inside
  have position : writeAddress patch+BitVec.ofNat 64 (address-writeAddress patch).toNat=address := by
    rw [BitVec.ofNat_toNat,BitVec.add_comm]
    exact BitVec.sub_add_cancel _ _
  cases patch with
  | call record =>
      have zero := call_guard_zero original current record accepted _ inside
      rw [position,preserved address nonzero] at zero
      exact nonzero zero
  | literal slot target =>
      have zero := zero_span original slot 8 accepted _ inside
      change slot+BitVec.ofNat 64 (address-slot).toNat=address at position
      change original.value (slot+BitVec.ofNat 64 (address-slot).toNat)=0 at zero
      rw [position] at zero
      exact nonzero zero

/-- The invariant covers every prefix and every write in an arbitrary table,
including mixed original-snapshot/current-destination guard sources. -/
theorem checked_table_nonzero (original current : Memory) (patches : List Patch)
    (preserved : PreservesNonzero original current) (accepted : CheckedTable original current patches) :
    PreservesNonzero original (applyTable patches current) ∧
      ∀ patch∈patches, ∀ address, original.value address≠0 → OutsideWrite address patch := by
  induction patches generalizing current with
  | nil => exact ⟨preserved,by intro patch member; simp at member⟩
  | cons head rest ih =>
      obtain ⟨guard,tailGuard⟩ := accepted
      have headOutside := guard_outside_nonzero original current head preserved guard
      have nextPreserved : PreservesNonzero original (applyPatch current head) := by
        intro address nonzero
        exact (patch_outside current head address (headOutside address nonzero)).1.trans
          (preserved address nonzero)
      obtain ⟨last,tailOutside⟩ := ih (applyPatch current head) nextPreserved tailGuard
      refine ⟨last,?_⟩
      intro patch member address nonzero
      rcases List.mem_cons.mp member with same | inside
      · subst patch; exact headOutside address nonzero
      · exact tailOutside patch inside address nonzero

theorem rex_nonzero (dst : X86.Register) : NativeLinkMovabs.rex dst≠0 := by
  intro zero
  have bound := dst.isLt
  have bits := congrArg BitVec.toNat zero
  change (0x48+dst.val/8)%256=0 at bits
  omega

theorem opcode_nonzero (dst : X86.Register) : NativeLinkMovabs.opcode dst≠0 := by
  intro zero
  have bits := congrArg BitVec.toNat zero
  change (0xb8+dst.val%8)%256=0 at bits
  omega

/-- Existing successful table checks establish MOVABS header protection. -/
theorem checked_movabs_header (code : Memory) (patches : List Patch)
    (accepted : CheckedTable code code patches) (pc : Word) (dst : X86.Register)
    (header : code.value pc=NativeLinkMovabs.rex dst ∧
      code.value (pc+(1#64))=NativeLinkMovabs.opcode dst) :
    NativeLinkMovabs.HeaderProtected patches pc := by
  have retained := (checked_table_nonzero code code patches (by intro address nonzero; rfl) accepted).2
  intro patch inside
  exact ⟨retained patch inside pc (by rw [header.1]; exact rex_nonzero dst),
    retained patch inside (pc+(1#64)) (by rw [header.2]; exact opcode_nonzero dst)⟩

theorem template_header (code : Memory) (pc : Word) (dst : X86.Register) (value : Word)
    (template : (bytesAt code pc 10).toArray=NativeLinkMovabs.movabsBytes dst value) :
    code.value pc=NativeLinkMovabs.rex dst ∧ code.value (pc+(1#64))=NativeLinkMovabs.opcode dst := by
  have bytes := congrArg Array.toList template
  simp +decide [bytesAt,NativeLinkMovabs.movabsBytes,List.range_succ,List.range_zero,
    List.map_append,List.map_cons,List.map_nil,List.map_singleton] at bytes
  exact ⟨bytes.1,bytes.2.1⟩

/-- Original fixed-template bytes and the existing sequential kernel checks
supply the complete consumer TV instance, including its header protection. -/
theorem checked_movabs_preservation (code : Memory) (patches : List Patch)
    (accepted : CheckedTable code code patches)
    (separated : patches.Pairwise Separated)
    (valid : ∀ patch∈patches, OriginalValid code patch)
    (pc : Word) (dst : X86.Register) (target : Word)
    (member : Patch.literal (pc+(2#64)) target∈patches)
    (template : (bytesAt code pc 10).toArray=NativeLinkMovabs.movabsBytes dst 0) :
    TranslationValidation (NativeLinkMovabs.intended pc dst target)
      (NativeLinkMovabs.emitted (applyTable patches code) pc) Eq := by
  have header := template_header code pc dst 0 template
  exact NativeLinkMovabs.movabs_preservation patches code separated valid pc dst target member header
    (checked_movabs_header code patches accepted pc dst header)

theorem checked_map_movabs_preservation (kind : NativeLinkLiteral.MapKind)
    (maps : List NativeLinkLiteral.RetainedMap) (encoded target : Word)
    (resolved : NativeLinkLiteral.resolveMap kind maps encoded=some target)
    (code : Memory) (patches : List Patch) (accepted : CheckedTable code code patches)
    (separated : patches.Pairwise Separated)
    (valid : ∀ patch∈patches, OriginalValid code patch)
    (pc : Word) (dst : X86.Register)
    (member : Patch.literal (pc+(2#64)) target∈patches)
    (template : (bytesAt code pc 10).toArray=NativeLinkMovabs.movabsBytes dst 0) :
    (∃ map∈maps, map.id=NativeLinkLiteral.mapId encoded ∧
      NativeLinkLiteral.TargetWitness kind map (NativeLinkLiteral.mapOffset encoded) target) ∧
    TranslationValidation (NativeLinkMovabs.intended pc dst target)
      (NativeLinkMovabs.emitted (applyTable patches code) pc) Eq := by
  have header := template_header code pc dst 0 template
  exact NativeLinkMovabs.map_movabs_preservation kind maps encoded target resolved patches code separated valid
    pc dst member header (checked_movabs_header code patches accepted pc dst header)

theorem checked_emitted_architecture (code : Memory) (patches : List Patch)
    (accepted : CheckedTable code code patches)
    (separated : patches.Pairwise Separated)
    (valid : ∀ patch∈patches, OriginalValid code patch)
    (pc : Word) (dst : X86.Register) (target : Word)
    (member : Patch.literal (pc+(2#64)) target∈patches)
    (template : (bytesAt code pc 10).toArray=NativeLinkMovabs.movabsBytes dst 0)
    (before after : X86.State) (events : List Event)
    (run : NativeLinkMovabs.emitted (applyTable patches code) pc before events after) :
    after={ before with gpr := fun r => if r=dst then target else before.gpr r,pc := before.pc+(10#64) } ∧
      events=[] := by
  have header := template_header code pc dst 0 template
  exact NativeLinkMovabs.emitted_architecture patches code separated valid pc dst target member header
    (checked_movabs_header code patches accepted pc dst header) before after events run

end KProgTV.NativeLinkGuardedEmission

#print axioms KProgTV.NativeLinkGuardedEmission.zero_span
#print axioms KProgTV.NativeLinkGuardedEmission.call_guard_zero
#print axioms KProgTV.NativeLinkGuardedEmission.guard_outside_nonzero
#print axioms KProgTV.NativeLinkGuardedEmission.checked_table_nonzero
#print axioms KProgTV.NativeLinkGuardedEmission.rex_nonzero
#print axioms KProgTV.NativeLinkGuardedEmission.opcode_nonzero
#print axioms KProgTV.NativeLinkGuardedEmission.checked_movabs_header

#print axioms KProgTV.NativeLinkGuardedEmission.template_header
#print axioms KProgTV.NativeLinkGuardedEmission.checked_movabs_preservation
#print axioms KProgTV.NativeLinkGuardedEmission.checked_map_movabs_preservation
#print axioms KProgTV.NativeLinkGuardedEmission.checked_emitted_architecture
