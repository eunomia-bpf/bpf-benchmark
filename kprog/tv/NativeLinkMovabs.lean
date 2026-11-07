import NativeLinkPatchTable

/-! Fixed10-byte MOVABS consumer used by the native-link GOT materializer.
The template is decoded and executed by the canonical x86 ISA. -/
namespace KProgTV.NativeLinkMovabs
open KProgFormal.Reference

def rex (dst : X86.Register) : Byte := BitVec.ofNat 8 (0x48+dst.val/8)
def opcode (dst : X86.Register) : Byte := BitVec.ofNat 8 (0xb8+dst.val%8)

def movabsBytes (dst : X86.Register) (target : Word) : Array Byte :=
  #[rex dst,opcode dst,target.setWidth 8,(target>>>8).setWidth 8,
    (target>>>16).setWidth 8,(target>>>24).setWidth 8,(target>>>32).setWidth 8,
    (target>>>40).setWidth 8,(target>>>48).setWidth 8,(target>>>56).setWidth 8]

theorem target_roundtrip (target : Word) :
    BitVec.ofNat 64 (target.toNat%256+(target.toNat>>>8)%256*256+
      (target.toNat>>>16)%256*65536+(target.toNat>>>24)%256*16777216+
      (target.toNat>>>32)%256*4294967296+(target.toNat>>>40)%256*1099511627776+
      (target.toNat>>>48)%256*281474976710656+(target.toNat>>>56)%256*72057594037927936)=target := by
  apply BitVec.eq_of_toNat_eq
  have bound := target.isLt
  simp +decide [Nat.shiftRight_eq_div_pow,BitVec.toNat_ofNat] at *
  omega

set_option maxHeartbeats 4000000 in
/-- Every64-bit target and every destination, including RSP/RBP/high registers,
uses the actual10-byte template and canonical next PC. -/
theorem movabs_decode (s : X86.State) (dst : X86.Register) (target : Word) :
    X86.decode (movabsBytes dst target) s=
      .ok (.move .w64 (.register (.low dst)) (.immediate target) (s.pc+(10#64))) := by
  rcases dst with ⟨reg,bounded⟩
  have cases : reg=0 ∨ reg=1 ∨ reg=2 ∨ reg=3 ∨ reg=4 ∨ reg=5 ∨ reg=6 ∨ reg=7 ∨
      reg=8 ∨ reg=9 ∨ reg=10 ∨ reg=11 ∨ reg=12 ∨ reg=13 ∨ reg=14 ∨ reg=15 := by omega
  rcases cases with rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl | rfl
  all_goals unfold movabsBytes rex opcode
  all_goals canonical_x86_decode
  all_goals rw [target_roundtrip]

/-- Immediate materialization changes its destination and PC, preserves the
entire remaining architecture, and has an empty guest effect trace. -/
theorem movabs_result (s : X86.State) (dst : X86.Register) (target : Word) :
    X86.step (.move .w64 (.register (.low dst)) (.immediate target) (s.pc+(10#64))) s=
      ⟨{ s with gpr := fun r => if r=dst then target else s.gpr r,pc := s.pc+(10#64) },[],none⟩ := by
  simp +decide [X86.step,X86.moveStep,X86.scalarRead,X86.scalarWrite,X86.scalarWriteValue,
    X86.RegisterSlice.reg,X86.RegisterSlice.shift,X86.ScalarWidth.bits,X86.ScalarWidth.bytes]

/-- Only the actual instruction header is protected separately; the entire
immediate is supplied by the final mixed-table literal theorem. -/
def HeaderProtected (patches : List NativeLinkPatchTable.Patch) (pc : Word) : Prop :=
  ∀ patch∈patches, NativeLinkPatchTable.OutsideWrite pc patch ∧
    NativeLinkPatchTable.OutsideWrite (pc+(1#64)) patch

theorem table_movabs_bytes (patches : List NativeLinkPatchTable.Patch) (code : Memory)
    (separated : patches.Pairwise NativeLinkPatchTable.Separated)
    (valid : ∀ patch∈patches, NativeLinkPatchTable.OriginalValid code patch)
    (pc : Word) (dst : X86.Register) (target : Word)
    (member : NativeLinkPatchTable.Patch.literal (pc+(2#64)) target∈patches)
    (header : code.value pc=rex dst ∧ code.value (pc+(1#64))=opcode dst)
    (retained : HeaderProtected patches pc) :
    (bytesAt (NativeLinkPatchTable.applyTable patches code) pc 10).toArray=movabsBytes dst target := by
  have first := (NativeLinkPatchTable.table_value_outside patches code pc
    (fun patch inside => (retained patch inside).1)).trans header.1
  have second := (NativeLinkPatchTable.table_value_outside patches code (pc+(1#64))
    (fun patch inside => (retained patch inside).2)).trans header.2
  have field := NativeLinkPatchTable.table_patch_bytes patches code separated valid
    (.literal (pc+(2#64)) target) member
  change (bytesAt (NativeLinkPatchTable.applyTable patches code) (pc+(2#64)) 8).toArray=
    (valueBytes target 8).toArray at field
  have sameField := congrArg Array.toList field
  simp only [List.toList_toArray] at sameField
  have splitBytes : bytesAt (NativeLinkPatchTable.applyTable patches code) pc 10=
      (NativeLinkPatchTable.applyTable patches code).value pc ::
        (NativeLinkPatchTable.applyTable patches code).value (pc+(1#64)) ::
          bytesAt (NativeLinkPatchTable.applyTable patches code) (pc+(2#64)) 8 := by
    simp +decide [bytesAt,List.range_succ,List.range_zero,List.map_append,
      List.map_cons,List.map_nil,List.map_singleton,BitVec.add_assoc]
  rw [splitBytes,first,second,sameField]
  simp +decide [movabsBytes,valueBytes,List.range_succ,List.range_zero,List.map_append,
    List.map_cons,List.map_nil,List.map_singleton]

theorem table_movabs_decode (patches : List NativeLinkPatchTable.Patch) (code : Memory)
    (separated : patches.Pairwise NativeLinkPatchTable.Separated)
    (valid : ∀ patch∈patches, NativeLinkPatchTable.OriginalValid code patch)
    (s : X86.State) (dst : X86.Register) (target : Word)
    (member : NativeLinkPatchTable.Patch.literal (s.pc+(2#64)) target∈patches)
    (header : code.value s.pc=rex dst ∧ code.value (s.pc+(1#64))=opcode dst)
    (retained : HeaderProtected patches s.pc) :
    X86.decode (bytesAt (NativeLinkPatchTable.applyTable patches code) s.pc 10).toArray s=
      .ok (.move .w64 (.register (.low dst)) (.immediate target) (s.pc+(10#64))) := by
  rw [table_movabs_bytes patches code separated valid s.pc dst target member header retained]
  exact movabs_decode s dst target

def intended (pc : Word) (dst : X86.Register) (target : Word) : BlockStep X86.State :=
  fun before events after => before.pc=pc ∧
    ∃ effect, X86.Step (.move .w64 (.register (.low dst)) (.immediate target) (before.pc+(10#64)))
      before effect ∧ effect.events=events ∧ effect.state=after

def emitted (code : Memory) (pc : Word) : BlockStep X86.State :=
  fun before events after => before.pc=pc ∧
    ∃ instruction effect, X86.decode (bytesAt code before.pc 10).toArray before=.ok instruction ∧
      X86.Step instruction before effect ∧ effect.events=events ∧ effect.state=after

/-- Every physical final-code MOVABS behavior implements bound materialization
with the full canonical architecture and exact empty guest effect sequence. -/
theorem movabs_preservation (patches : List NativeLinkPatchTable.Patch) (code : Memory)
    (separated : patches.Pairwise NativeLinkPatchTable.Separated)
    (valid : ∀ patch∈patches, NativeLinkPatchTable.OriginalValid code patch)
    (pc : Word) (dst : X86.Register) (target : Word)
    (member : NativeLinkPatchTable.Patch.literal (pc+(2#64)) target∈patches)
    (header : code.value pc=rex dst ∧ code.value (pc+(1#64))=opcode dst)
    (retained : HeaderProtected patches pc) :
    TranslationValidation (intended pc dst target)
      (emitted (NativeLinkPatchTable.applyTable patches code) pc) Eq := by
  constructor
  intro n p events next relation source
  subst p
  obtain ⟨position,effect,step,trace,state⟩ := source
  have decoded := table_movabs_decode patches code separated valid n dst target
    (by simpa only [position] using member) (by simpa only [position] using header)
    (by simpa only [position] using retained)
  have nativeStep : emitted (NativeLinkPatchTable.applyTable patches code) pc n events next :=
    ⟨position,.move .w64 (.register (.low dst)) (.immediate target) (n.pc+(10#64)),effect,
      decoded,step,trace,state⟩
  exact ⟨next,by simpa only [List.append_nil] using Execution.next nativeStep (Execution.refl next),rfl⟩

theorem emitted_reflects (patches : List NativeLinkPatchTable.Patch) (code : Memory)
    (separated : patches.Pairwise NativeLinkPatchTable.Separated)
    (valid : ∀ patch∈patches, NativeLinkPatchTable.OriginalValid code patch)
    (pc : Word) (dst : X86.Register) (target : Word)
    (member : NativeLinkPatchTable.Patch.literal (pc+(2#64)) target∈patches)
    (header : code.value pc=rex dst ∧ code.value (pc+(1#64))=opcode dst)
    (retained : HeaderProtected patches pc)
    (before after : X86.State) (events : List Event)
    (run : emitted (NativeLinkPatchTable.applyTable patches code) pc before events after) :
    intended pc dst target before events after := by
  obtain ⟨position,instruction,effect,decoded,step,trace,state⟩ := run
  have expected := table_movabs_decode patches code separated valid before dst target
    (by simpa only [position] using member) (by simpa only [position] using header)
    (by simpa only [position] using retained)
  have same : instruction=.move .w64 (.register (.low dst)) (.immediate target) (before.pc+(10#64)) :=
    Except.ok.inj (decoded.symm.trans expected)
  subst instruction
  exact ⟨position,effect,step,trace,state⟩

/-- Stable map identity and accepted offset/callback resolution compose
with actual final-code consumption, for arbitrary retained map environments. -/
theorem map_movabs_preservation (kind : NativeLinkLiteral.MapKind)
    (maps : List NativeLinkLiteral.RetainedMap) (encoded target : Word)
    (resolved : NativeLinkLiteral.resolveMap kind maps encoded=some target)
    (patches : List NativeLinkPatchTable.Patch) (code : Memory)
    (separated : patches.Pairwise NativeLinkPatchTable.Separated)
    (valid : ∀ patch∈patches, NativeLinkPatchTable.OriginalValid code patch)
    (pc : Word) (dst : X86.Register)
    (member : NativeLinkPatchTable.Patch.literal (pc+(2#64)) target∈patches)
    (header : code.value pc=rex dst ∧ code.value (pc+(1#64))=opcode dst)
    (retained : HeaderProtected patches pc) :
    (∃ map∈maps, map.id=NativeLinkLiteral.mapId encoded ∧
      NativeLinkLiteral.TargetWitness kind map (NativeLinkLiteral.mapOffset encoded) target) ∧
    TranslationValidation (intended pc dst target)
      (emitted (NativeLinkPatchTable.applyTable patches code) pc) Eq :=
  ⟨NativeLinkLiteral.resolve_map_sound kind maps encoded target resolved,
    movabs_preservation patches code separated valid pc dst target member header retained⟩

/-- Every final-code consumer has the exact full architectural successor and
empty guest trace; every untouched register/flag/vector/memory field is retained. -/
theorem emitted_architecture (patches : List NativeLinkPatchTable.Patch) (code : Memory)
    (separated : patches.Pairwise NativeLinkPatchTable.Separated)
    (valid : ∀ patch∈patches, NativeLinkPatchTable.OriginalValid code patch)
    (pc : Word) (dst : X86.Register) (target : Word)
    (member : NativeLinkPatchTable.Patch.literal (pc+(2#64)) target∈patches)
    (header : code.value pc=rex dst ∧ code.value (pc+(1#64))=opcode dst)
    (retained : HeaderProtected patches pc)
    (before after : X86.State) (events : List Event)
    (run : emitted (NativeLinkPatchTable.applyTable patches code) pc before events after) :
    after={ before with gpr := fun r => if r=dst then target else before.gpr r,pc := before.pc+(10#64) } ∧
      events=[] := by
  obtain ⟨position,effect,step,trace,state⟩ :=
    emitted_reflects patches code separated valid pc dst target member header retained before after events run
  simp only [X86.Step,X86.matchesTransition,movabs_result,X86.definedFlags,X86.observedRegisters,
    Option.isSome_none,Bool.false_eq_true,ite_false,
    show (0xffffffffffffffff#64)=BitVec.allOnes 64 by decide,BitVec.and_allOnes] at step
  obtain ⟨sameEvents,sameFault,sameState⟩ := step
  have maskFlags (flags : Word) : flags &&& (0xffffffffffffffff : Word)=flags := by
    exact BitVec.and_allOnes
  simp only [maskFlags] at sameState
  exact ⟨(sameState.trans state).symm,(sameEvents.trans trace).symm⟩

end KProgTV.NativeLinkMovabs

#print axioms KProgTV.NativeLinkMovabs.target_roundtrip
#print axioms KProgTV.NativeLinkMovabs.movabs_decode
#print axioms KProgTV.NativeLinkMovabs.movabs_result

#print axioms KProgTV.NativeLinkMovabs.table_movabs_bytes
#print axioms KProgTV.NativeLinkMovabs.table_movabs_decode
#print axioms KProgTV.NativeLinkMovabs.movabs_preservation
#print axioms KProgTV.NativeLinkMovabs.emitted_reflects

#print axioms KProgTV.NativeLinkMovabs.map_movabs_preservation
#print axioms KProgTV.NativeLinkMovabs.emitted_architecture
