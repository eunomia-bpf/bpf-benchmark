import NativeLinkArmBL26

/-! Universal ARM helper-slot encodings use the single canonical decoder and
step. Far materialization retains its actual X10/LR state and48-bit profile. -/
namespace KProgTV.NativeLinkArmHelper
open KProgFormal.Reference
open NativeLinkArmBL26 (nat_mask nat_mask_ne)

def wordBytes (word : BitVec 32) : Array Byte := (valueBytes (word.zeroExtend 64) 4).toArray

theorem word_bytes (word : BitVec 32) : littleEndian 32 (wordBytes word).toList=word := by
  simp +decide [wordBytes,valueBytes,littleEndian,List.range_succ,List.range_zero,List.map_append]
  unfold Word at *
  bv_decide

def movnWord (field : BitVec 16) : BitVec 32 := 0x9280000a ||| (field.zeroExtend 32 <<< 5)

def keepColumn (high : Bool) : Fin 4 := if high then 2 else 1

def movkWord (high : Bool) (field : BitVec 16) : BitVec 32 :=
  (if high then 0xf2c0000a else 0xf2a0000a) ||| (field.zeroExtend 32 <<< 5)

theorem decode_movn (field : BitVec 16) :
    AArch64.decode (wordBytes (movnWord field))=.ok (.moveImmediate .w64 10 (~~~(field.zeroExtend 64))) := by
  have m0 : (movnWord field).toNat &&& 0xfffff0ff≠0xd503305f :=
    nat_mask_ne _ (0xfffff0ff#32) (0xd503305f#32) (by unfold movnWord; bv_decide)
  have m1 : (movnWord field).toNat &&& 0xbfff7c00≠0x885f7c00 :=
    nat_mask_ne _ (0xbfff7c00#32) (0x885f7c00#32) (by unfold movnWord; bv_decide)
  have m2 : (movnWord field).toNat &&& 0xbfe07c00≠0x88007c00 :=
    nat_mask_ne _ (0xbfe07c00#32) (0x88007c00#32) (by unfold movnWord; bv_decide)
  have m3 : (movnWord field).toNat &&& 0x7f800000≠0x29000000 :=
    nat_mask_ne _ (0x7f800000#32) (0x29000000#32) (by unfold movnWord; bv_decide)
  have m4 : (movnWord field).toNat &&& 0x7f800000≠0x28800000 :=
    nat_mask_ne _ (0x7f800000#32) (0x28800000#32) (by unfold movnWord; bv_decide)
  have m5 : (movnWord field).toNat &&& 0x7f800000≠0x29800000 :=
    nat_mask_ne _ (0x7f800000#32) (0x29800000#32) (by unfold movnWord; bv_decide)
  have m6 : (movnWord field).toNat &&& 0x3b000000≠0x39000000 :=
    nat_mask_ne _ (0x3b000000#32) (0x39000000#32) (by unfold movnWord; bv_decide)
  have m7 : (movnWord field).toNat &&& 0x3b200c00≠0x38000000 :=
    nat_mask_ne _ (0x3b200c00#32) (0x38000000#32) (by unfold movnWord; bv_decide)
  have m8 : (movnWord field).toNat &&& 0x3b200c00≠0x38000400 :=
    nat_mask_ne _ (0x3b200c00#32) (0x38000400#32) (by unfold movnWord; bv_decide)
  have m9 : (movnWord field).toNat &&& 0x3b200c00≠0x38000c00 :=
    nat_mask_ne _ (0x3b200c00#32) (0x38000c00#32) (by unfold movnWord; bv_decide)
  have m10 : (movnWord field).toNat &&& 0x3b200c00≠0x38200800 :=
    nat_mask_ne _ (0x3b200c00#32) (0x38200800#32) (by unfold movnWord; bv_decide)
  have m11 : (movnWord field).toNat &&& 0xfc000000≠0x94000000 :=
    nat_mask_ne _ (0xfc000000#32) (0x94000000#32) (by unfold movnWord; bv_decide)
  have m12 : (movnWord field).toNat &&& 0xfffffc1f≠0xd61f0000 :=
    nat_mask_ne _ (0xfffffc1f#32) (0xd61f0000#32) (by unfold movnWord; bv_decide)
  have m13 : (movnWord field).toNat &&& 0xfffffc1f≠0xd63f0000 :=
    nat_mask_ne _ (0xfffffc1f#32) (0xd63f0000#32) (by unfold movnWord; bv_decide)
  have m14 : (movnWord field).toNat &&& 0xfffffc1f≠0xd65f0000 :=
    nat_mask_ne _ (0xfffffc1f#32) (0xd65f0000#32) (by unfold movnWord; bv_decide)
  have m15 : (movnWord field).toNat &&& 0x1f000000≠0x10000000 :=
    nat_mask_ne _ (0x1f000000#32) (0x10000000#32) (by unfold movnWord; bv_decide)
  have m16 : (movnWord field).toNat &&& 0xfc000000≠0x14000000 :=
    nat_mask_ne _ (0xfc000000#32) (0x14000000#32) (by unfold movnWord; bv_decide)
  have m17 : (movnWord field).toNat &&& 0xff000010≠0x54000000 :=
    nat_mask_ne _ (0xff000010#32) (0x54000000#32) (by unfold movnWord; bv_decide)
  have m18 : (movnWord field).toNat &&& 0x7e000000≠0x34000000 :=
    nat_mask_ne _ (0x7e000000#32) (0x34000000#32) (by unfold movnWord; bv_decide)
  have m19 : (movnWord field).toNat &&& 0x7e000000≠0x36000000 :=
    nat_mask_ne _ (0x7e000000#32) (0x36000000#32) (by unfold movnWord; bv_decide)
  have m20 : (movnWord field).toNat &&& 0x7fe00c10≠0x7a400000 :=
    nat_mask_ne _ (0x7fe00c10#32) (0x7a400000#32) (by unfold movnWord; bv_decide)
  have m21 : (movnWord field).toNat &&& 0x7fe00c10≠0x7a400800 :=
    nat_mask_ne _ (0x7fe00c10#32) (0x7a400800#32) (by unfold movnWord; bv_decide)
  have m22 : (movnWord field).toNat &&& 0xbffffc00≠0xe205800 :=
    nat_mask_ne _ (0xbffffc00#32) (0xe205800#32) (by unfold movnWord; bv_decide)
  have m23 : (movnWord field).toNat &&& 0xbffffc00≠0x2e303800 :=
    nat_mask_ne _ (0xbffffc00#32) (0x2e303800#32) (by unfold movnWord; bv_decide)
  have m24 : (movnWord field).toNat &&& 0xfffffc00≠0x9e670000 :=
    nat_mask_ne _ (0xfffffc00#32) (0x9e670000#32) (by unfold movnWord; bv_decide)
  have m25 : (movnWord field).toNat &&& 0xfffffc00≠0x1e270000 :=
    nat_mask_ne _ (0xfffffc00#32) (0x1e270000#32) (by unfold movnWord; bv_decide)
  have m26 : (movnWord field).toNat &&& 0xfffffc00≠0x9e660000 :=
    nat_mask_ne _ (0xfffffc00#32) (0x9e660000#32) (by unfold movnWord; bv_decide)
  have m27 : (movnWord field).toNat &&& 0xfffffc00≠0x1e260000 :=
    nat_mask_ne _ (0xfffffc00#32) (0x1e260000#32) (by unfold movnWord; bv_decide)
  have m28 : (movnWord field).toNat &&& 0x7fe0ffe0≠0x2a0003e0 :=
    nat_mask_ne _ (0x7fe0ffe0#32) (0x2a0003e0#32) (by unfold movnWord; bv_decide)
  have m29 : (movnWord field).toNat &&& 0x7ffffc00≠0x11000000 :=
    nat_mask_ne _ (0x7ffffc00#32) (0x11000000#32) (by unfold movnWord; bv_decide)
  have m30 : (movnWord field).toNat &&& 0x1f800000≠0x12000000 :=
    nat_mask_ne _ (0x1f800000#32) (0x12000000#32) (by unfold movnWord; bv_decide)
  have m31 : (movnWord field).toNat &&& 0x1f800000≠0x11000000 :=
    nat_mask_ne _ (0x1f800000#32) (0x11000000#32) (by unfold movnWord; bv_decide)
  have m32 : (movnWord field).toNat &&& 0x7f800000≠0x72800000 :=
    nat_mask_ne _ (0x7f800000#32) (0x72800000#32) (by unfold movnWord; bv_decide)
  have nop : (movnWord field).toNat≠0xd503201f := by
    intro same
    have value : (movnWord field)=(0xd503201f#32) := BitVec.eq_of_toNat_eq same
    have apart : (movnWord field)≠(0xd503201f#32) := by unfold movnWord; bv_decide
    exact apart value
  have selected : (movnWord field).toNat &&& 0x7f800000=0x12800000 :=
    nat_mask _ (0x7f800000#32) (0x12800000#32) (by unfold movnWord; bv_decide)
  have addition : (movnWord field)=BitVec.ofNat 32 0x9280000a+(field.zeroExtend 32)*(32#32) := by
    unfold movnWord; bv_decide
  have natural : (movnWord field).toNat=0x9280000a+field.toNat*32 := by
    rw [addition]
    have bounded:=field.isLt
    simp only [BitVec.toNat_add,BitVec.toNat_mul,BitVec.toNat_setWidth,BitVec.toNat_ofNat]
    omega
  have width : (movnWord field).toNat/2^31=1 := by
    rw [natural]
    have bounded:=field.isLt
    omega
  have column : ((movnWord field).toNat/2^21)%4=0 := by
    rw [natural]
    have bounded:=field.isLt
    omega
  have destination : (movnWord field).toNat%32=10 := by
    rw [natural]
    omega
  have immediate : BitVec.ofNat 16 ((movnWord field).toNat/2^5)=field := by
    apply BitVec.eq_of_toNat_eq
    rw [natural]
    have bounded:=field.isLt
    simp only [BitVec.toNat_ofNat]
    omega
  have invert : ((movnWord field).toNat/2^30)%2=0 := by rw [natural]; have bounded:=field.isLt; omega
  have wide : BitVec.ofNat 64 (((movnWord field).toNat/2^5)%2^16)=field.zeroExtend 64 := by
    apply BitVec.eq_of_toNat_eq
    have source:=congrArg BitVec.toNat immediate
    have bounded:=field.isLt
    simp only [BitVec.toNat_ofNat,BitVec.toNat_setWidth] at source ⊢
    omega
  generalize replaced : wordBytes (movnWord field)=bytes
  have size : bytes.size=4 := by rw [←replaced]; simp only [wordBytes,List.size_toArray,valueBytes,List.length_map,List.length_range]
  have value : littleEndian 32 bytes.toList=(movnWord field) := by rw [←replaced]; exact word_bytes _
  simp +decide only [AArch64.decode,size,ne_eq,not_true_eq_false,if_false,value,m0,m1,m2,m3,m4,m5,m6,m7,m8,m9,m10,m11,m12,m13,m14,m15,m16,m17,m18,m19,m20,m21,m22,m23,m24,m25,m26,m27,m28,m29,m30,m31,m32,beq_eq_false_iff_ne.mpr m0,beq_eq_false_iff_ne.mpr m1,beq_eq_false_iff_ne.mpr m2,beq_eq_false_iff_ne.mpr m3,beq_eq_false_iff_ne.mpr m4,beq_eq_false_iff_ne.mpr m5,beq_eq_false_iff_ne.mpr m6,beq_eq_false_iff_ne.mpr m7,beq_eq_false_iff_ne.mpr m8,beq_eq_false_iff_ne.mpr m9,beq_eq_false_iff_ne.mpr m10,beq_eq_false_iff_ne.mpr m11,beq_eq_false_iff_ne.mpr m12,beq_eq_false_iff_ne.mpr m13,beq_eq_false_iff_ne.mpr m14,beq_eq_false_iff_ne.mpr m15,beq_eq_false_iff_ne.mpr m16,beq_eq_false_iff_ne.mpr m17,beq_eq_false_iff_ne.mpr m18,beq_eq_false_iff_ne.mpr m19,beq_eq_false_iff_ne.mpr m20,beq_eq_false_iff_ne.mpr m21,beq_eq_false_iff_ne.mpr m22,beq_eq_false_iff_ne.mpr m23,beq_eq_false_iff_ne.mpr m24,beq_eq_false_iff_ne.mpr m25,beq_eq_false_iff_ne.mpr m26,beq_eq_false_iff_ne.mpr m27,beq_eq_false_iff_ne.mpr m28,beq_eq_false_iff_ne.mpr m29,beq_eq_false_iff_ne.mpr m30,beq_eq_false_iff_ne.mpr m31,beq_eq_false_iff_ne.mpr m32,nop,selected,width,column,AArch64.Width.bits,immediate,invert,wide,BitVec.shiftLeft_zero,Bool.false_or,Bool.or_false,Bool.false_and,Bool.and_false,or_self,and_false,false_and,beq_eq_false_iff_ne,Bool.false_eq_true,if_true,dif_pos,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  congr 2
  apply Fin.ext
  exact destination
  all_goals simp only [Nat.mul_zero,BitVec.shiftLeft_zero]

theorem decode_movk (high : Bool) (field : BitVec 16) :
    AArch64.decode (wordBytes (movkWord high field))=.ok (.keep ⟨.w64,keepColumn high,field,10⟩) := by
  have m0 : (movkWord high field).toNat &&& 0xfffff0ff≠0xd503305f :=
    nat_mask_ne _ (0xfffff0ff#32) (0xd503305f#32) (by cases high <;> unfold movkWord <;> bv_decide)
  have m1 : (movkWord high field).toNat &&& 0xbfff7c00≠0x885f7c00 :=
    nat_mask_ne _ (0xbfff7c00#32) (0x885f7c00#32) (by cases high <;> unfold movkWord <;> bv_decide)
  have m2 : (movkWord high field).toNat &&& 0xbfe07c00≠0x88007c00 :=
    nat_mask_ne _ (0xbfe07c00#32) (0x88007c00#32) (by cases high <;> unfold movkWord <;> bv_decide)
  have m3 : (movkWord high field).toNat &&& 0x7f800000≠0x29000000 :=
    nat_mask_ne _ (0x7f800000#32) (0x29000000#32) (by cases high <;> unfold movkWord <;> bv_decide)
  have m4 : (movkWord high field).toNat &&& 0x7f800000≠0x28800000 :=
    nat_mask_ne _ (0x7f800000#32) (0x28800000#32) (by cases high <;> unfold movkWord <;> bv_decide)
  have m5 : (movkWord high field).toNat &&& 0x7f800000≠0x29800000 :=
    nat_mask_ne _ (0x7f800000#32) (0x29800000#32) (by cases high <;> unfold movkWord <;> bv_decide)
  have m6 : (movkWord high field).toNat &&& 0x3b000000≠0x39000000 :=
    nat_mask_ne _ (0x3b000000#32) (0x39000000#32) (by cases high <;> unfold movkWord <;> bv_decide)
  have m7 : (movkWord high field).toNat &&& 0x3b200c00≠0x38000000 :=
    nat_mask_ne _ (0x3b200c00#32) (0x38000000#32) (by cases high <;> unfold movkWord <;> bv_decide)
  have m8 : (movkWord high field).toNat &&& 0x3b200c00≠0x38000400 :=
    nat_mask_ne _ (0x3b200c00#32) (0x38000400#32) (by cases high <;> unfold movkWord <;> bv_decide)
  have m9 : (movkWord high field).toNat &&& 0x3b200c00≠0x38000c00 :=
    nat_mask_ne _ (0x3b200c00#32) (0x38000c00#32) (by cases high <;> unfold movkWord <;> bv_decide)
  have m10 : (movkWord high field).toNat &&& 0x3b200c00≠0x38200800 :=
    nat_mask_ne _ (0x3b200c00#32) (0x38200800#32) (by cases high <;> unfold movkWord <;> bv_decide)
  have m11 : (movkWord high field).toNat &&& 0xfc000000≠0x94000000 :=
    nat_mask_ne _ (0xfc000000#32) (0x94000000#32) (by cases high <;> unfold movkWord <;> bv_decide)
  have m12 : (movkWord high field).toNat &&& 0xfffffc1f≠0xd61f0000 :=
    nat_mask_ne _ (0xfffffc1f#32) (0xd61f0000#32) (by cases high <;> unfold movkWord <;> bv_decide)
  have m13 : (movkWord high field).toNat &&& 0xfffffc1f≠0xd63f0000 :=
    nat_mask_ne _ (0xfffffc1f#32) (0xd63f0000#32) (by cases high <;> unfold movkWord <;> bv_decide)
  have m14 : (movkWord high field).toNat &&& 0xfffffc1f≠0xd65f0000 :=
    nat_mask_ne _ (0xfffffc1f#32) (0xd65f0000#32) (by cases high <;> unfold movkWord <;> bv_decide)
  have m15 : (movkWord high field).toNat &&& 0x1f000000≠0x10000000 :=
    nat_mask_ne _ (0x1f000000#32) (0x10000000#32) (by cases high <;> unfold movkWord <;> bv_decide)
  have m16 : (movkWord high field).toNat &&& 0xfc000000≠0x14000000 :=
    nat_mask_ne _ (0xfc000000#32) (0x14000000#32) (by cases high <;> unfold movkWord <;> bv_decide)
  have m17 : (movkWord high field).toNat &&& 0xff000010≠0x54000000 :=
    nat_mask_ne _ (0xff000010#32) (0x54000000#32) (by cases high <;> unfold movkWord <;> bv_decide)
  have m18 : (movkWord high field).toNat &&& 0x7e000000≠0x34000000 :=
    nat_mask_ne _ (0x7e000000#32) (0x34000000#32) (by cases high <;> unfold movkWord <;> bv_decide)
  have m19 : (movkWord high field).toNat &&& 0x7e000000≠0x36000000 :=
    nat_mask_ne _ (0x7e000000#32) (0x36000000#32) (by cases high <;> unfold movkWord <;> bv_decide)
  have m20 : (movkWord high field).toNat &&& 0x7fe00c10≠0x7a400000 :=
    nat_mask_ne _ (0x7fe00c10#32) (0x7a400000#32) (by cases high <;> unfold movkWord <;> bv_decide)
  have m21 : (movkWord high field).toNat &&& 0x7fe00c10≠0x7a400800 :=
    nat_mask_ne _ (0x7fe00c10#32) (0x7a400800#32) (by cases high <;> unfold movkWord <;> bv_decide)
  have m22 : (movkWord high field).toNat &&& 0xbffffc00≠0xe205800 :=
    nat_mask_ne _ (0xbffffc00#32) (0xe205800#32) (by cases high <;> unfold movkWord <;> bv_decide)
  have m23 : (movkWord high field).toNat &&& 0xbffffc00≠0x2e303800 :=
    nat_mask_ne _ (0xbffffc00#32) (0x2e303800#32) (by cases high <;> unfold movkWord <;> bv_decide)
  have m24 : (movkWord high field).toNat &&& 0xfffffc00≠0x9e670000 :=
    nat_mask_ne _ (0xfffffc00#32) (0x9e670000#32) (by cases high <;> unfold movkWord <;> bv_decide)
  have m25 : (movkWord high field).toNat &&& 0xfffffc00≠0x1e270000 :=
    nat_mask_ne _ (0xfffffc00#32) (0x1e270000#32) (by cases high <;> unfold movkWord <;> bv_decide)
  have m26 : (movkWord high field).toNat &&& 0xfffffc00≠0x9e660000 :=
    nat_mask_ne _ (0xfffffc00#32) (0x9e660000#32) (by cases high <;> unfold movkWord <;> bv_decide)
  have m27 : (movkWord high field).toNat &&& 0xfffffc00≠0x1e260000 :=
    nat_mask_ne _ (0xfffffc00#32) (0x1e260000#32) (by cases high <;> unfold movkWord <;> bv_decide)
  have m28 : (movkWord high field).toNat &&& 0x7fe0ffe0≠0x2a0003e0 :=
    nat_mask_ne _ (0x7fe0ffe0#32) (0x2a0003e0#32) (by cases high <;> unfold movkWord <;> bv_decide)
  have m29 : (movkWord high field).toNat &&& 0x7ffffc00≠0x11000000 :=
    nat_mask_ne _ (0x7ffffc00#32) (0x11000000#32) (by cases high <;> unfold movkWord <;> bv_decide)
  have m30 : (movkWord high field).toNat &&& 0x1f800000≠0x12000000 :=
    nat_mask_ne _ (0x1f800000#32) (0x12000000#32) (by cases high <;> unfold movkWord <;> bv_decide)
  have m31 : (movkWord high field).toNat &&& 0x1f800000≠0x11000000 :=
    nat_mask_ne _ (0x1f800000#32) (0x11000000#32) (by cases high <;> unfold movkWord <;> bv_decide)
  have nop : (movkWord high field).toNat≠0xd503201f := by
    intro same
    have value : (movkWord high field)=(0xd503201f#32) := BitVec.eq_of_toNat_eq same
    have apart : (movkWord high field)≠(0xd503201f#32) := by cases high <;> unfold movkWord <;> bv_decide
    exact apart value
  have selected : (movkWord high field).toNat &&& 0x7f800000=0x72800000 :=
    nat_mask _ (0x7f800000#32) (0x72800000#32) (by cases high <;> unfold movkWord <;> bv_decide)
  have addition : (movkWord high field)=BitVec.ofNat 32 (if high then 0xf2c0000a else 0xf2a0000a)+(field.zeroExtend 32)*(32#32) := by
    cases high <;> unfold movkWord <;> bv_decide
  have natural : (movkWord high field).toNat=(if high then 0xf2c0000a else 0xf2a0000a)+field.toNat*32 := by
    rw [addition]
    have bounded:=field.isLt
    simp only [BitVec.toNat_add,BitVec.toNat_mul,BitVec.toNat_setWidth,BitVec.toNat_ofNat]
    cases high <;> simp only [Bool.false_eq_true,ite_false,ite_true] <;> omega
  have width : (movkWord high field).toNat/2^31=1 := by
    rw [natural]
    have bounded:=field.isLt
    cases high <;> simp only [Bool.false_eq_true,ite_false,ite_true] <;> omega
  have column : ((movkWord high field).toNat/2^21)%4=(keepColumn high).val := by
    rw [natural]
    have bounded:=field.isLt
    cases high <;> simp only [keepColumn,Bool.false_eq_true,ite_false,ite_true] <;> omega
  have destination : (movkWord high field).toNat%32=10 := by
    rw [natural]
    cases high <;> simp only [Bool.false_eq_true,ite_false,ite_true] <;> omega
  have immediate : BitVec.ofNat 16 ((movkWord high field).toNat/2^5)=field := by
    apply BitVec.eq_of_toNat_eq
    rw [natural]
    have bounded:=field.isLt
    simp only [BitVec.toNat_ofNat]
    cases high <;> simp only [Bool.false_eq_true,ite_false,ite_true] <;> omega
  have columnValid : (keepColumn high).val<4 := (keepColumn high).isLt
  generalize replaced : wordBytes (movkWord high field)=bytes
  have size : bytes.size=4 := by rw [←replaced]; simp only [wordBytes,List.size_toArray,valueBytes,List.length_map,List.length_range]
  have value : littleEndian 32 bytes.toList=(movkWord high field) := by rw [←replaced]; exact word_bytes _
  simp +decide only [AArch64.decode,size,ne_eq,not_true_eq_false,if_false,value,m0,m1,m2,m3,m4,m5,m6,m7,m8,m9,m10,m11,m12,m13,m14,m15,m16,m17,m18,m19,m20,m21,m22,m23,m24,m25,m26,m27,m28,m29,m30,m31,beq_eq_false_iff_ne.mpr m0,beq_eq_false_iff_ne.mpr m1,beq_eq_false_iff_ne.mpr m2,beq_eq_false_iff_ne.mpr m3,beq_eq_false_iff_ne.mpr m4,beq_eq_false_iff_ne.mpr m5,beq_eq_false_iff_ne.mpr m6,beq_eq_false_iff_ne.mpr m7,beq_eq_false_iff_ne.mpr m8,beq_eq_false_iff_ne.mpr m9,beq_eq_false_iff_ne.mpr m10,beq_eq_false_iff_ne.mpr m11,beq_eq_false_iff_ne.mpr m12,beq_eq_false_iff_ne.mpr m13,beq_eq_false_iff_ne.mpr m14,beq_eq_false_iff_ne.mpr m15,beq_eq_false_iff_ne.mpr m16,beq_eq_false_iff_ne.mpr m17,beq_eq_false_iff_ne.mpr m18,beq_eq_false_iff_ne.mpr m19,beq_eq_false_iff_ne.mpr m20,beq_eq_false_iff_ne.mpr m21,beq_eq_false_iff_ne.mpr m22,beq_eq_false_iff_ne.mpr m23,beq_eq_false_iff_ne.mpr m24,beq_eq_false_iff_ne.mpr m25,beq_eq_false_iff_ne.mpr m26,beq_eq_false_iff_ne.mpr m27,beq_eq_false_iff_ne.mpr m28,beq_eq_false_iff_ne.mpr m29,beq_eq_false_iff_ne.mpr m30,beq_eq_false_iff_ne.mpr m31,nop,selected,width,column,AArch64.Width.bits,immediate,columnValid,(keepColumn high).isLt,BitVec.shiftLeft_zero,Bool.false_or,Bool.or_false,Bool.false_and,Bool.and_false,or_self,and_false,false_and,beq_eq_false_iff_ne,Bool.false_eq_true,if_true,dif_pos,Except.bind,Except.pure,Bind.bind,Pure.pure,Except.instMonad]
  have finFields {n m : Nat} (left : Fin n) (right : Fin m)
      (shape : n=m) (same : left.val=right.val) : HEq left right := by
    subst m
    exact heq_of_eq (Fin.ext same)
  congr 2
  congr 1
  all_goals try simp +decide only [value,width]
  all_goals first
    | rfl
    | (apply Fin.ext; exact destination)
    | exact finFields _ _ (by simp [value,width,AArch64.Width.bits]) rfl

theorem decode_blr : AArch64.decode (wordBytes 0xd63f0140)=.ok (.branchRegister true 10) := by rfl

theorem decode_nop : AArch64.decode (wordBytes 0xd503201f)=.ok .nop := by rfl

def farWords (target : Word) (index : Fin 4) : BitVec 32 :=
  match index.val with
  | 0 => movnWord ((~~~target).setWidth 16)
  | 1 => movkWord false ((target>>>16).setWidth 16)
  | 2 => movkWord true ((target>>>32).setWidth 16)
  | _ => 0xd63f0140

/-- The actual ordered four u32 stores use canonical little-endian Memory. -/
def emit4 (code : Memory) (slot : Word) (words : Fin 4 → BitVec 32) : Memory :=
  let first:=storeMemory code slot ((words 0).setWidth 64) 4
  let second:=storeMemory first (slot+4) ((words 1).setWidth 64) 4
  let third:=storeMemory second (slot+8) ((words 2).setWidth 64) 4
  storeMemory third (slot+12) ((words 3).setWidth 64) 4

theorem relative_offsets (base left right : Word) :
    (base+left)-(base+right)=left-right := by unfold Word at *; bv_decide

theorem relative_start (base right : Word) : base-(base+right)=0-right := by
  unfold Word at *; bv_decide

theorem relative_base (base left : Word) : (base+left)-base=left := by
  rw [BitVec.add_comm,BitVec.add_sub_cancel]

/-- Every complete instruction word survives all four existing stores. -/
theorem emit4_fetch (code : Memory) (slot : Word) (words : Fin 4 → BitVec 32) (index : Fin 4) :
    (bytesAt (emit4 code slot words) (slot+BitVec.ofNat 64 (4*index.val)) 4).toArray=
      wordBytes (words index) := by
  rcases index with ⟨index,bound⟩
  have cases : index=0 ∨ index=1 ∨ index=2 ∨ index=3 := by omega
  rcases cases with rfl | rfl | rfl | rfl
  all_goals
    simp +decide only [emit4,bytesAt,wordBytes,valueBytes,List.range_succ,List.range_zero,List.map_append,
      List.map_cons,List.map_nil,List.map_singleton,List.append_nil,List.nil_append,
      storeMemory,BitVec.add_assoc,BitVec.add_zero,relative_offsets,relative_start,relative_base]
  all_goals simp +decide [BitVec.zeroExtend_eq_setWidth]

def initialValue (target : Word) : Word := ~~~((~~~target).setWidth 16).setWidth 64

def reconstructed (target : Word) : Word := 0xffff000000000000 ||| (target &&& 0x0000ffffffffffff)

def Kernel48 (target : Word) : Prop := target>>>48=0xffff

theorem reconstructed_exact (target : Word) : reconstructed target=target ↔ Kernel48 target := by
  unfold reconstructed Kernel48 Word at *
  bv_decide

theorem reconstruction (target : Word) :
    AArch64.moveKeepRaw 32
      (AArch64.moveKeepRaw 16 (initialValue target) (((target>>>16).setWidth 16).setWidth 64))
      (((target>>>32).setWidth 16).setWidth 64)=reconstructed target := by
  unfold AArch64.moveKeepRaw initialValue reconstructed Word at *
  bv_decide

/-- Canonical state computation supplies the three materialization stages. -/
def materialized (state : AArch64.State) (target : Word) : AArch64.State :=
  let first:=(AArch64.step (.moveImmediate .w64 10 (initialValue target)) state).state
  let second:=(AArch64.step (.keep ⟨.w64,⟨1,by decide⟩,(target>>>16).setWidth 16,10⟩) first).state
  (AArch64.step (.keep ⟨.w64,⟨2,by decide⟩,(target>>>32).setWidth 16,10⟩) second).state

theorem materialized_state (state : AArch64.State) (target : Word) :
    materialized state target={AArch64.writeReg state 10 (reconstructed target) with pc:=state.pc+12} := by
  have pc (value : Word) : value+(4#64)+(4#64)+(4#64)=value+(12#64) := by unfold Word at *; bv_decide
  simp +decide [materialized,AArch64.step,AArch64.keepStep,AArch64.narrow,AArch64.Width.bits,
    AArch64.readReg,AArch64.writeReg,reconstruction,pc]
  funext index
  by_cases selected : index.val=(10 : AArch64.Register).val <;> simp [selected]

/-- Actual BLR captures X10 before writing X30. All other architectural state
fields retain the canonical three-stage materialization result. -/
theorem far_reference (state : AArch64.State) (target : Word) :
    AArch64.step (.branchRegister true 10) (materialized state target)=
      ⟨{AArch64.writeReg (AArch64.writeReg state 10 (reconstructed target)) 30 (state.pc+16)
          with pc:=reconstructed target},[],none⟩ := by
  rw [materialized_state]
  have pc (value : Word) : value+(12#64)+(4#64)=value+(16#64) := by unfold Word at *; bv_decide
  simp +decide [AArch64.step,AArch64.readReg,AArch64.writeReg,pc]

theorem supported_far_reference (state : AArch64.State) (target : Word) (profile : Kernel48 target) :
    AArch64.step (.branchRegister true 10) (materialized state target)=
      ⟨{AArch64.writeReg (AArch64.writeReg state 10 target) 30 (state.pc+16) with pc:=target},[],none⟩ := by
  rw [far_reference,(reconstructed_exact target).mpr profile]

def farInstruction (target : Word) (index : Fin 4) : AArch64.Instruction :=
  match index.val with
  | 0 => .moveImmediate .w64 10 (initialValue target)
  | 1 => .keep ⟨.w64,⟨1,by decide⟩,(target>>>16).setWidth 16,10⟩
  | 2 => .keep ⟨.w64,⟨2,by decide⟩,(target>>>32).setWidth 16,10⟩
  | _ => .branchRegister true 10

theorem far_decode (code : Memory) (slot target : Word) (index : Fin 4) :
    AArch64.decode (bytesAt (emit4 code slot (farWords target))
      (slot+BitVec.ofNat 64 (4*index.val)) 4).toArray=.ok (farInstruction target index) := by
  rw [emit4_fetch]
  rcases index with ⟨index,bound⟩
  have cases : index=0 ∨ index=1 ∨ index=2 ∨ index=3 := by omega
  rcases cases with rfl | rfl | rfl | rfl
  · exact decode_movn _
  · exact decode_movk false _
  · exact decode_movk true _
  · exact decode_blr

/-- Symbolic slots use canonical Step. Byte slots use canonical decode/Step;
static PC positions identify instruction boundaries in the emitted block. -/
def symbolicSite (slot : Word) (instruction : AArch64.Instruction) : BlockStep AArch64.State :=
  fun before events after => before.pc=slot ∧
    ∃ effect, AArch64.Step instruction before effect ∧ effect.events=events ∧ effect.state=after

def decodedSite (code : Memory) (slot : Word) : BlockStep AArch64.State :=
  fun before events after => before.pc=slot ∧
    ∃ instruction effect, AArch64.decode (bytesAt code before.pc 4).toArray=.ok instruction ∧
      AArch64.Step instruction before effect ∧ effect.events=events ∧ effect.state=after

theorem site_preservation (code : Memory) (slot : Word) (instruction : AArch64.Instruction)
    (decoded : AArch64.decode (bytesAt code slot 4).toArray=.ok instruction) :
    TranslationValidation (symbolicSite slot instruction) (decodedSite code slot) Eq := by
  constructor
  intro before other events after related run
  subst other
  obtain ⟨position,effect,step,trace,state⟩:=run
  have head : decodedSite code slot before events after :=
    ⟨position,instruction,effect,by rw [position]; exact decoded,step,trace,state⟩
  exact ⟨after,by simpa only [List.append_nil] using Execution.next head (Execution.refl after),rfl⟩

theorem site_reflects (code : Memory) (slot : Word) (instruction : AArch64.Instruction)
    (decoded : AArch64.decode (bytesAt code slot 4).toArray=.ok instruction)
    (before after : AArch64.State) (events : List Event)
    (run : decodedSite code slot before events after) : symbolicSite slot instruction before events after := by
  obtain ⟨position,actual,effect,bytes,step,trace,state⟩:=run
  rw [position,decoded] at bytes
  have same : instruction=actual := Except.ok.inj bytes
  subst actual
  exact ⟨position,effect,step,trace,state⟩

/-- All four field-parametric sites compose through the existing token/block
closure. Every finite prefix retains its full state and ordered effects. -/
theorem far_block_preservation (code : Memory) (slot target : Word) :
    TranslationValidation
      (Execution (tokenStep (fun index : Fin 4 =>
        symbolicSite (slot+BitVec.ofNat 64 (4*index.val)) (farInstruction target index))))
      (tokenStep (fun index : Fin 4 =>
        decodedSite (emit4 code slot (farWords target)) (slot+BitVec.ofNat 64 (4*index.val)))) Eq := by
  exact (tokenwise_validation _ _ Eq (fun index =>
    site_preservation _ _ _ (far_decode code slot target index))).execution

theorem far_block_reflects (code : Memory) (slot target : Word)
    (before after : AArch64.State) (events : List Event)
    (run : Execution (tokenStep (fun index : Fin 4 =>
      decodedSite (emit4 code slot (farWords target)) (slot+BitVec.ofNat 64 (4*index.val)))) before events after) :
    Execution (tokenStep (fun index : Fin 4 =>
      symbolicSite (slot+BitVec.ofNat 64 (4*index.val)) (farInstruction target index))) before events after := by
  apply Execution.of_step_imp _ run
  intro before events after head
  obtain ⟨index,step⟩:=head
  exact ⟨index,site_reflects _ _ _ (far_decode code slot target index) before after events step⟩

/-- The near-call return pad advances through its three original NOPs from
an arbitrary returned architectural state. Callee effects stay in its ABI law. -/
theorem near_return_reference (state : AArch64.State) :
    AArch64.step .nop ((AArch64.step .nop ((AArch64.step .nop state).state)).state)=
      ⟨{state with pc:=state.pc+(12#64)},[],none⟩ := by
  simp only [AArch64.step]
  congr 2
  unfold Word at *
  bv_decide

/-- A first-word patch retains every complete later word within the image. -/
theorem stored_word_later (code : Memory) (slot : Word) (word : BitVec 32) (offset : Nat)
    (lower : 4≤offset) (bounded : offset+4≤2^64) :
    bytesAt (storeMemory code slot (word.setWidth 64) 4) (slot+BitVec.ofNat 64 offset) 4=
      bytesAt code (slot+BitVec.ofNat 64 offset) 4 := by
  apply List.map_congr_left
  intro index member
  have small : index<4 := List.mem_range.mp member
  have bound : offset+index<2^64 := by omega
  have position : ((slot+BitVec.ofNat 64 offset)+BitVec.ofNat 64 index-slot).toNat=offset+index := by
    rw [BitVec.add_assoc,←BitVec.ofNat_add,relative_base]
    simp only [BitVec.toNat_ofNat,Nat.mod_eq_of_lt bound]
  have outside : ¬((slot+BitVec.ofNat 64 offset)+BitVec.ofNat 64 index-slot).toNat<4 := by
    rw [position]; omega
  simp only [storeMemory,outside,ite_false]

def nearCode (code : Memory) (slot target : Word) : Memory :=
  storeMemory code slot ((NativeLinkArmBL26.kernelEncoding (target-slot)).setWidth 64) 4

def NearPadding (code : Memory) (slot : Word) : Prop :=
  ∀ index : Fin 4, 0<index.val →
    (bytesAt code (slot+BitVec.ofNat 64 (4*index.val)) 4).toArray=wordBytes 0xd503201f

theorem near_entry_decode (code : Memory) (slot target : Word)
    (accepted : NativeLinkArmBL26.kernelGuard (target-slot)) :
    AArch64.decode (bytesAt (nearCode code slot target) slot 4).toArray=
      .ok (.branchLink (target-slot)) :=
  NativeLinkArmBL26.kernel_written_decode code slot target accepted

theorem near_pad_decode (code : Memory) (slot target : Word) (padding : NearPadding code slot)
    (index : Fin 4) (positive : 0<index.val) :
    AArch64.decode (bytesAt (nearCode code slot target)
      (slot+BitVec.ofNat 64 (4*index.val)) 4).toArray=.ok .nop := by
  have retained:=stored_word_later code slot (NativeLinkArmBL26.kernelEncoding (target-slot))
    (4*index.val) (by omega) (by have := index.isLt; omega)
  unfold nearCode
  rw [retained,padding index positive]
  exact decode_nop

def nearInstruction (slot target : Word) (index : Fin 4) : AArch64.Instruction :=
  if index.val=0 then .branchLink (target-slot) else .nop

theorem near_decode (code : Memory) (slot target : Word) (padding : NearPadding code slot)
    (accepted : NativeLinkArmBL26.kernelGuard (target-slot)) (index : Fin 4) :
    AArch64.decode (bytesAt (nearCode code slot target)
      (slot+BitVec.ofNat 64 (4*index.val)) 4).toArray=.ok (nearInstruction slot target index) := by
  by_cases first : index.val=0
  · simp only [first,Nat.mul_zero,nearInstruction,ite_true]
    have position : slot+BitVec.ofNat 64 0=slot := by unfold Word at *; bv_decide
    rw [position]
    exact near_entry_decode code slot target accepted
  · have positive : 0<index.val := Nat.pos_of_ne_zero first
    simpa only [nearInstruction,first,ite_false] using near_pad_decode code slot target padding index positive

/-- The near body includes its actual BL link address and all three retained
NOP sites. Callee behavior joins through the separate helper ABI relation. -/
theorem near_block_preservation (code : Memory) (slot target : Word) (padding : NearPadding code slot)
    (accepted : NativeLinkArmBL26.kernelGuard (target-slot)) :
    TranslationValidation
      (Execution (tokenStep (fun index : Fin 4 =>
        symbolicSite (slot+BitVec.ofNat 64 (4*index.val)) (nearInstruction slot target index))))
      (tokenStep (fun index : Fin 4 =>
        decodedSite (nearCode code slot target) (slot+BitVec.ofNat 64 (4*index.val)))) Eq := by
  exact (tokenwise_validation _ _ Eq (fun index =>
    site_preservation _ _ _ (near_decode code slot target padding accepted index))).execution

theorem near_block_reflects (code : Memory) (slot target : Word) (padding : NearPadding code slot)
    (accepted : NativeLinkArmBL26.kernelGuard (target-slot))
    (before after : AArch64.State) (events : List Event)
    (run : Execution (tokenStep (fun index : Fin 4 =>
      decodedSite (nearCode code slot target) (slot+BitVec.ofNat 64 (4*index.val)))) before events after) :
    Execution (tokenStep (fun index : Fin 4 =>
      symbolicSite (slot+BitVec.ofNat 64 (4*index.val)) (nearInstruction slot target index))) before events after := by
  apply Execution.of_step_imp _ run
  intro before events after head
  obtain ⟨index,step⟩:=head
  exact ⟨index,site_reflects _ _ _ (near_decode code slot target padding accepted index) before after events step⟩

/-- The source MOVN/MOVK helper builders' shifts, u16 masks and u32 opcode
composition agree with all three field-parametric instruction words. -/
theorem kernel_far_words (target : Word) :
    farWords target 0=
      ((0x92800000#32) ||| (BitVec.ofNat 32 (0/16) <<< 21) |||
        (((~~~target &&& (0xffff#64)).setWidth 16).setWidth 32 <<< 5) ||| 10) ∧
    farWords target 1=
      ((0xf2800000#32) ||| (BitVec.ofNat 32 (16/16) <<< 21) |||
        ((((target>>>16) &&& (0xffff#64)).setWidth 16).setWidth 32 <<< 5) ||| 10) ∧
    farWords target 2=
      ((0xf2800000#32) ||| (BitVec.ofNat 32 (32/16) <<< 21) |||
        ((((target>>>32) &&& (0xffff#64)).setWidth 16).setWidth 32 <<< 5) ||| 10) := by
  unfold farWords movnWord movkWord Word at *
  bv_decide

local instance guardDecidable (delta : Word) : Decidable (NativeLinkArmBL26.kernelGuard delta) := by
  unfold NativeLinkArmBL26.kernelGuard
  infer_instance

def helperCode (code : Memory) (slot target : Word) : Memory :=
  if NativeLinkArmBL26.kernelGuard (target-slot) then nearCode code slot target
  else emit4 code slot (farWords target)

def helperInstruction (slot target : Word) (index : Fin 4) : AArch64.Instruction :=
  if NativeLinkArmBL26.kernelGuard (target-slot) then nearInstruction slot target index
  else farInstruction target index

/-- The existing load-time range choice selects the exact four-site body.
All finite prefixes preserve full state and effects through Composition. -/
theorem helper_block_preservation (code : Memory) (slot target : Word) (padding : NearPadding code slot) :
    TranslationValidation
      (Execution (tokenStep (fun index : Fin 4 =>
        symbolicSite (slot+BitVec.ofNat 64 (4*index.val)) (helperInstruction slot target index))))
      (tokenStep (fun index : Fin 4 =>
        decodedSite (helperCode code slot target) (slot+BitVec.ofNat 64 (4*index.val)))) Eq := by
  by_cases near : NativeLinkArmBL26.kernelGuard (target-slot)
  · simpa only [helperInstruction,helperCode,near,ite_true] using near_block_preservation code slot target padding near
  · simpa only [helperInstruction,helperCode,near,ite_false] using far_block_preservation code slot target

theorem helper_block_reflects (code : Memory) (slot target : Word) (padding : NearPadding code slot)
    (before after : AArch64.State) (events : List Event)
    (run : Execution (tokenStep (fun index : Fin 4 =>
      decodedSite (helperCode code slot target) (slot+BitVec.ofNat 64 (4*index.val)))) before events after) :
    Execution (tokenStep (fun index : Fin 4 =>
      symbolicSite (slot+BitVec.ofNat 64 (4*index.val)) (helperInstruction slot target index))) before events after := by
  by_cases near : NativeLinkArmBL26.kernelGuard (target-slot)
  · simp only [helperInstruction,helperCode,near,ite_true] at run ⊢
    exact near_block_reflects code slot target padding near before after events run
  · simp only [helperInstruction,helperCode,near,ite_false] at run ⊢
    exact far_block_reflects code slot target before after events run

/-- Both existing entry shapes reach the bound helper under the supported
address profile. Their actual X10 and link addresses remain explicit. -/
theorem helper_entry_result (state : AArch64.State) (target : Word) (profile : Kernel48 target) :
    (if NativeLinkArmBL26.kernelGuard (target-state.pc) then
      AArch64.step (.branchLink (target-state.pc)) state
     else AArch64.step (.branchRegister true 10) (materialized state target))=
    (if NativeLinkArmBL26.kernelGuard (target-state.pc) then
      ⟨{AArch64.writeReg state 30 (state.pc+(4#64)) with pc:=target},[],none⟩
     else ⟨{AArch64.writeReg (AArch64.writeReg state 10 target) 30 (state.pc+(16#64))
       with pc:=target},[],none⟩) := by
  by_cases near : NativeLinkArmBL26.kernelGuard (target-state.pc)
  · simp only [near,ite_true]
    exact NativeLinkArmBL26.branch_result state target
  · simp only [near,ite_false]
    exact supported_far_reference state target profile

end KProgTV.NativeLinkArmHelper
#print axioms KProgTV.NativeLinkArmHelper.word_bytes
#print axioms KProgTV.NativeLinkArmHelper.decode_movn
#print axioms KProgTV.NativeLinkArmHelper.decode_movk
#print axioms KProgTV.NativeLinkArmHelper.decode_blr
#print axioms KProgTV.NativeLinkArmHelper.decode_nop

#print axioms KProgTV.NativeLinkArmHelper.relative_offsets
#print axioms KProgTV.NativeLinkArmHelper.relative_start
#print axioms KProgTV.NativeLinkArmHelper.relative_base
#print axioms KProgTV.NativeLinkArmHelper.emit4_fetch
#print axioms KProgTV.NativeLinkArmHelper.reconstructed_exact
#print axioms KProgTV.NativeLinkArmHelper.reconstruction
#print axioms KProgTV.NativeLinkArmHelper.materialized_state
#print axioms KProgTV.NativeLinkArmHelper.far_reference
#print axioms KProgTV.NativeLinkArmHelper.supported_far_reference

#print axioms KProgTV.NativeLinkArmHelper.far_decode
#print axioms KProgTV.NativeLinkArmHelper.site_preservation
#print axioms KProgTV.NativeLinkArmHelper.site_reflects
#print axioms KProgTV.NativeLinkArmHelper.far_block_preservation
#print axioms KProgTV.NativeLinkArmHelper.far_block_reflects
#print axioms KProgTV.NativeLinkArmHelper.near_return_reference

#print axioms KProgTV.NativeLinkArmHelper.stored_word_later
#print axioms KProgTV.NativeLinkArmHelper.near_entry_decode
#print axioms KProgTV.NativeLinkArmHelper.near_pad_decode
#print axioms KProgTV.NativeLinkArmHelper.near_decode
#print axioms KProgTV.NativeLinkArmHelper.near_block_preservation
#print axioms KProgTV.NativeLinkArmHelper.near_block_reflects

#print axioms KProgTV.NativeLinkArmHelper.kernel_far_words
#print axioms KProgTV.NativeLinkArmHelper.helper_block_preservation
#print axioms KProgTV.NativeLinkArmHelper.helper_block_reflects
#print axioms KProgTV.NativeLinkArmHelper.helper_entry_result
