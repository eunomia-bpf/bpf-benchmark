import NativeLinkArmHelper
import BPF

/-! Kind9 binds immutable STXR bytes to the fresh exclusive-choice marker.
Instruction behavior comes from canonical AArch64 and the existing BPF ISA. -/
namespace KProgTV.NativeLinkArmExclusive
open KProgFormal.Reference KProgTV
open _root_.KProgTV.NativeLinkArmBL26 (nat_mask nat_mask_ne)

def field (word : BitVec 32) (shift : Nat) : AArch64.Register :=
  ⟨(word.toNat / 2^shift)%32,Nat.mod_lt _ (by decide)⟩

/-- Exact native opcode and status/data/base overlap checks from the kernel. -/
def AcceptedWord (word : BitVec 32) : Prop :=
  word &&& 0xbfe07c00=0x88007c00 ∧ field word 16≠field word 0 ∧
    ((field word 5).val=31 ∨ field word 16≠field word 5)

def instruction (word : BitVec 32) : AArch64.Instruction :=
  .exclusive (.store (if (word.toNat/2^30)%2=1 then .w64 else .w32)
    ((word.toNat/2^15)%2==1) (field word 16) (field word 0) (field word 5))

theorem accepted_decode (word : BitVec 32) (accepted : AcceptedWord word) :
    AArch64.decode (NativeLinkArmHelper.wordBytes word)=.ok (instruction word) := by
  have first : word.toNat &&& 0xfffff0ff≠0xd503305f :=
    nat_mask_ne _ (0xfffff0ff#32) (0xd503305f#32) (by have mask:=accepted.1; bv_decide)
  have load : word.toNat &&& 0xbfff7c00≠0x885f7c00 :=
    nat_mask_ne _ (0xbfff7c00#32) (0x885f7c00#32) (by have mask:=accepted.1; bv_decide)
  have store : word.toNat &&& 0xbfe07c00=0x88007c00 :=
    nat_mask _ (0xbfe07c00#32) (0x88007c00#32) accepted.1
  generalize replaced : NativeLinkArmHelper.wordBytes word=bytes
  have size : bytes.size=4 := by
    rw [←replaced]
    simp only [NativeLinkArmHelper.wordBytes,List.size_toArray,valueBytes,List.length_map,List.length_range]
  have value : littleEndian 32 bytes.toList=word := by
    rw [←replaced]
    exact NativeLinkArmHelper.word_bytes word
  have dataOverlap : field word 16≠field word 0 := accepted.2.1
  have baseOverlap : ¬((field word 5).val != 31 && decide (field word 16=field word 5))=true := by
    rcases accepted.2.2 with base | apart
    · simp [base]
    · simp [apart]
  simp only [AArch64.decode,size,ne_eq,not_true_eq_false,if_false,value,first,load,store,
    if_true,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  let source : AArch64.Register := ⟨word.toNat%32,Nat.mod_lt _ (by decide)⟩
  have sourceField : field word 0=source := by
    apply Fin.ext
    simp [field,source]
  have distinct : field word 16≠source := by
    rw [←sourceField]
    exact dataOverlap
  change (if field word 16=source then _ else
    if ((field word 5).val != 31 && decide (field word 16=field word 5)) then _ else _)=_
  rw [if_neg distinct,if_neg baseOverlap]
  simp only [instruction,sourceField]
  rfl


/-- The exact kernel scanner stride, measured in8B proof instructions. -/
def proofWords (code : Nat) : Nat := if code=0x18 then 2 else 1

def position (codes : Nat → Nat) : Nat → Nat
  | 0 => 0
  | visit+1 => position codes visit+proofWords (codes (position codes visit))

theorem proof_words_bounds (code : Nat) : 1≤proofWords code ∧ proofWords code≤2 := by
  unfold proofWords
  split <;> omega

theorem position_mono (codes : Nat → Nat) (first last : Nat) (ordered : first≤last) :
    position codes first≤position codes last := by
  induction last generalizing first with
  | zero =>
      have same : first=0 := by omega
      subst first
      exact Nat.le_refl _
  | succ last ih =>
      by_cases earlier : first≤last
      · have old:=ih first earlier
        have stride:=proof_words_bounds (codes (position codes last))
        simp only [position]
        omega
      · have same : first=last+1 := by omega
        subst first
        exact Nat.le_refl _

theorem position_visits (codes : Nat → Nat) (visit : Nat) : visit≤position codes visit := by
  induction visit with
  | zero => simp [position]
  | succ visit ih =>
      have stride:=proof_words_bounds (codes (position codes visit))
      simp only [position]
      omega

/-- An accepted scanner index belongs to the unique instruction boundary
sequence. A wide-immediate continuation lies strictly between two boundaries. -/
theorem wide_continuation_excluded (codes : Nat → Nat) (first last : Nat)
    (wide : codes (position codes first)=0x18) :
    position codes last≠position codes first+1 := by
  intro same
  by_cases earlier : last≤first
  · have ordered:=position_mono codes last first earlier
    omega
  · have ordered:=position_mono codes (first+1) last (by omega)
    have step : position codes (first+1)=position codes first+2 := by
      simp [position,proofWords,wide]
    rw [step] at ordered
    omega

/-- The existing index<count guard and count≤one million keep the C u32
scanner increment within bounds, including an overshoot past a continuation. -/
theorem scanner_step_bounds (code current index count : Nat)
    (advance : current<index) (indexBound : index<count) (countBound : count≤1000000) :
    current+proofWords code≤count ∧ current+proofWords code<2^32 := by
  have stride:=proof_words_bounds code
  omega

def descriptor (index pc : BitVec 32) : BitVec 64 := index.zeroExtend 64 ||| (pc.zeroExtend 64 <<< 32)

theorem descriptor_fields (index pc : BitVec 32) :
    (descriptor index pc).setWidth 32=index ∧ ((descriptor index pc)>>>32).setWidth 32=pc := by
  unfold descriptor
  bv_decide

theorem verifier_choice_range (failure : Bool) :
    ((if failure then 1 else 0) : Word).toNat≤1 := by
  cases failure <;> decide

/-- The kernel's fresh scalar interval represents exactly both Boolean
outcomes at each site and visit. -/
theorem verifier_choice_complete (value : Word) (bounded : value.toNat≤1) :
    ∃ failure : Bool, value=(if failure then 1 else 0) := by
  by_cases zero : value.toNat=0
  · refine ⟨false,?_⟩
    apply BitVec.eq_of_toNat_eq
    exact zero
  · refine ⟨true,?_⟩
    apply BitVec.eq_of_toNat_eq
    change value.toNat=1
    omega

def marker (pc : BitVec 32) : BPF.Instruction := ⟨0xb7,0,9,5,pc⟩

theorem marker_fields (pc : BitVec 32) :
    (marker pc).code=0xb7 ∧ (marker pc).src=9 ∧ (marker pc).dst=0 ∧
    (marker pc).offset=5 ∧ (marker pc).imm=pc := by exact ⟨rfl,rfl,rfl,rfl,rfl⟩

/-- The same complete32-bit source PC and current visit choose the outcome.
Every call advances the visit and preserves all other BPF state fields. -/
theorem marker_execution (env : BPF.Environment) (program : Array Byte) (state : BPF.State)
    (pc : BitVec 32) (failure : Bool) (choice : env.exclusiveFailure pc state.exclusiveVisit=.ok failure) :
    BPF.execute env program state (marker pc)=
      .ok ⟨BPF.setReg {state with pc:=state.pc+1,exclusiveVisit:=state.exclusiveVisit+1} 0
        (if failure then 1 else 0),[],none⟩ := by
  simp +decide [BPF.execute,marker,choice]
  rfl

theorem marker_step (env : BPF.Environment) (program : Array Byte) (state : BPF.State)
    (pc : BitVec 32) (failure : Bool) (live : state.halted=false) (nonnegative : 0≤state.pc)
    (decoded : BPF.decode program state.pc.toNat=.ok (marker pc))
    (choice : env.exclusiveFailure pc state.exclusiveVisit=.ok failure) :
    BPF.step env program state=
      .ok ⟨BPF.setReg {state with pc:=state.pc+1,exclusiveVisit:=state.exclusiveVisit+1} 0
        (if failure then 1 else 0),[],none⟩ := by
  have lower : ¬state.pc<0 := by omega
  simp only [BPF.step,live,Bool.false_eq_true,if_false,lower,decoded]
  simpa only [live] using marker_execution env program state pc failure choice

def symbolicSite (word : BitVec 32) (slot : Word) : BlockStep AArch64.State :=
  NativeLinkArmHelper.symbolicSite slot (instruction word)

theorem accepted_site (code : Memory) (word : BitVec 32) (slot : Word)
    (accepted : AcceptedWord word)
    (bound : (bytesAt code slot 4).toArray=NativeLinkArmHelper.wordBytes word) :
    TranslationValidation (symbolicSite word slot) (NativeLinkArmHelper.decodedSite code slot) Eq := by
  exact NativeLinkArmHelper.site_preservation code slot (instruction word) (by rw [bound]; exact accepted_decode word accepted)

theorem accepted_site_reflects (code : Memory) (word : BitVec 32) (slot : Word)
    (accepted : AcceptedWord word)
    (bound : (bytesAt code slot 4).toArray=NativeLinkArmHelper.wordBytes word)
    (before after : AArch64.State) (events : List Event)
    (run : NativeLinkArmHelper.decodedSite code slot before events after) :
    symbolicSite word slot before events after := by
  exact NativeLinkArmHelper.site_reflects code slot (instruction word)
    (by rw [bound]; exact accepted_decode word accepted) before after events run

/-- The unchanged native sites compose for every family of accepted kind9
records and every finite canonical execution prefix. -/
theorem accepted_blocks {Site : Type} (code : Memory) (words : Site → BitVec 32) (slots : Site → Word)
    (accepted : ∀ site, AcceptedWord (words site))
    (bound : ∀ site, (bytesAt code (slots site) 4).toArray=NativeLinkArmHelper.wordBytes (words site)) :
    TranslationValidation (Execution (tokenStep (fun site => symbolicSite (words site) (slots site))))
      (tokenStep (fun site => NativeLinkArmHelper.decodedSite code (slots site))) Eq := by
  exact (tokenwise_validation _ _ Eq (fun site => accepted_site code (words site) (slots site)
    (accepted site) (bound site))).execution

theorem accepted_blocks_reflect {Site : Type} (code : Memory) (words : Site → BitVec 32) (slots : Site → Word)
    (accepted : ∀ site, AcceptedWord (words site))
    (bound : ∀ site, (bytesAt code (slots site) 4).toArray=NativeLinkArmHelper.wordBytes (words site))
    (before after : AArch64.State) (events : List Event)
    (run : Execution (tokenStep (fun site => NativeLinkArmHelper.decodedSite code (slots site))) before events after) :
    Execution (tokenStep (fun site => symbolicSite (words site) (slots site))) before events after := by
  apply Execution.of_step_imp _ run
  intro first trace next head
  obtain ⟨site,step⟩:=head
  exact ⟨site,accepted_site_reflects code (words site) (slots site) (accepted site) (bound site) first next trace step⟩

end KProgTV.NativeLinkArmExclusive
#print axioms KProgTV.NativeLinkArmExclusive.accepted_decode
#print axioms KProgTV.NativeLinkArmExclusive.descriptor_fields
#print axioms KProgTV.NativeLinkArmExclusive.marker_fields
#print axioms KProgTV.NativeLinkArmExclusive.marker_execution
#print axioms KProgTV.NativeLinkArmExclusive.accepted_site
#print axioms KProgTV.NativeLinkArmExclusive.accepted_site_reflects
#print axioms KProgTV.NativeLinkArmExclusive.proof_words_bounds
#print axioms KProgTV.NativeLinkArmExclusive.position_mono
#print axioms KProgTV.NativeLinkArmExclusive.position_visits
#print axioms KProgTV.NativeLinkArmExclusive.wide_continuation_excluded
#print axioms KProgTV.NativeLinkArmExclusive.scanner_step_bounds
#print axioms KProgTV.NativeLinkArmExclusive.marker_step
#print axioms KProgTV.NativeLinkArmExclusive.accepted_blocks
#print axioms KProgTV.NativeLinkArmExclusive.accepted_blocks_reflect
#print axioms KProgTV.NativeLinkArmExclusive.verifier_choice_range
#print axioms KProgTV.NativeLinkArmExclusive.verifier_choice_complete
