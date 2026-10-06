import KinsnLean4.Kinsn.Catalog
import KinsnLean4.Kinsn.Payload
import KinsnLean4.Kinsn.ModuleMemory
import KinsnLean4.Kinsn.ModulePrefetch
import KinsnLean4.Kinsn.ModuleFlags
import KinsnLean4.Kinsn.ModuleRotate
import KinsnLean4.Kinsn.ModuleArmRotate
import KinsnLean4.Kinsn.ModuleRegister
import KinsnLean4.Kinsn.ModuleEndian
import KinsnLean4.Kinsn.ModuleLea

namespace Kinsn.ModuleCatalog

/-! Source-specific catalogue at the JIT maps. Operands below are the decoded,
validated operands; byte offsets retain their signed 16-bit encoding.
Each certificate includes spec correctness, write bounds and full-memory
refinement through ArmStateEquiv.arm_refines or X86StateEquiv.x86_refines.
Rotation exposes exactly its explicit BPF temporary. -/

/-- arm64/bpf_arm64_ldr.c:instantiate_ldrb_mem/emit_ldrb_mem_arm64. -/
def bpf_arm64_ldrb (dst base : BPF.Reg) (off : BitVec 16) : ArmStateEquiv Catalog.armMap :=
  ModuleMemory.loadCert Catalog.armMap 1 dst base (BitVec.signExtend 64 off)

/-- arm64/bpf_arm64_ldr.c:instantiate_ldrh_mem/emit_ldrh_mem_arm64. -/
def bpf_arm64_ldrh (dst base : BPF.Reg) (off : BitVec 16) : ArmStateEquiv Catalog.armMap :=
  ModuleMemory.loadCert Catalog.armMap 2 dst base (BitVec.signExtend 64 off)

/-- arm64/bpf_arm64_ldr.c:instantiate_ldr_w_mem/emit_ldr_w_mem_arm64. -/
def bpf_arm64_ldr_w (dst base : BPF.Reg) (off : BitVec 16) : ArmStateEquiv Catalog.armMap :=
  ModuleMemory.loadCert Catalog.armMap 4 dst base (BitVec.signExtend 64 off)

/-- arm64/bpf_arm64_ldr.c:instantiate_ldr_x_mem/emit_ldr_x_mem_arm64. -/
def bpf_arm64_ldr_x (dst base : BPF.Reg) (off : BitVec 16) : ArmStateEquiv Catalog.armMap :=
  ModuleMemory.loadCert Catalog.armMap 8 dst base (BitVec.signExtend 64 off)

/-- arm64/bpf_arm64_str.c:instantiate_strb/emit_strb_arm64. -/
def bpf_arm64_strb (src base : BPF.Reg) (off : BitVec 16) : ArmStateEquiv Catalog.armMap :=
  ModuleMemory.storeCert Catalog.armMap 1 src base (BitVec.signExtend 64 off)

/-- arm64/bpf_arm64_str.c:instantiate_strh/emit_strh_arm64. -/
def bpf_arm64_strh (src base : BPF.Reg) (off : BitVec 16) : ArmStateEquiv Catalog.armMap :=
  ModuleMemory.storeCert Catalog.armMap 2 src base (BitVec.signExtend 64 off)

/-- arm64/bpf_arm64_str.c:instantiate_str_w/emit_str_w_arm64. -/
def bpf_arm64_str_w (src base : BPF.Reg) (off : BitVec 16) : ArmStateEquiv Catalog.armMap :=
  ModuleMemory.storeCert Catalog.armMap 4 src base (BitVec.signExtend 64 off)

/-- arm64/bpf_arm64_str.c:instantiate_str_x/emit_str_x_arm64. -/
def bpf_arm64_str_x (src base : BPF.Reg) (off : BitVec 16) : ArmStateEquiv Catalog.armMap :=
  ModuleMemory.storeCert Catalog.armMap 8 src base (BitVec.signExtend 64 off)

 /-- arm64/bpf_arm64_str.c:instantiate_strb_zero_mem/emit_strb_fixed_arm64. -/
def bpf_arm64_strb_zero (base : BPF.Reg) (off : BitVec 16) : ArmStateEquiv Catalog.armMap :=
  ModuleMemory.zeroCert Catalog.armMap base (BitVec.signExtend 64 off)

/-- arm64/bpf_arm64_ldp.c:instantiate_ldp/emit_ldp_arm64. The decoder
    also rejects base=hi and lo=hi; the proof needs only base≠lo. -/
def bpf_arm64_ldp_x (lo hi base : BPF.Reg) (off : BitVec 16) (h : base ≠ lo) :
    ArmStateEquiv Catalog.armMap :=
  ModuleMemory.pairLoadCert Catalog.armMap lo hi base (BitVec.signExtend 64 off) h

/-- arm64/bpf_arm64_ldp.c:instantiate_stp/emit_stp_arm64. -/
def bpf_arm64_stp_x (lo hi base : BPF.Reg) (off : BitVec 16) : ArmStateEquiv Catalog.armMap :=
  ModuleMemory.pairStoreCert Catalog.armMap lo hi base (BitVec.signExtend 64 off)

/-- arm64/bpf_arm64_mov.c:instantiate_mov_x/emit_mov_x_arm64. -/
def bpf_arm64_mov_x (dst src : BPF.Reg) : ArmStateEquiv Catalog.armMap :=
  ModuleRegister.movCert Catalog.armMap dst src

/-- arm64/bpf_arm64_rev.c:instantiate_rev_w/emit_rev_w_arm64. -/
def bpf_arm64_rev_w (dst : BPF.Reg) : ArmStateEquiv Catalog.armMap :=
  ModuleRegister.revCert Catalog.armMap true dst

/-- arm64/bpf_arm64_rev.c:instantiate_rev_x/emit_rev_x_arm64. -/
def bpf_arm64_rev_x (dst : BPF.Reg) : ArmStateEquiv Catalog.armMap :=
  ModuleRegister.revCert Catalog.armMap false dst

/-- arm64/bpf_arm64_ubfm.c:instantiate_extract/emit_ubfm_x_arm64. -/
def bpf_arm64_ubfm_x (dst : BPF.Reg) (start width : Nat)
    (hw : 1 ≤ width) (hw32 : width ≤ 32) (hbound : start + width ≤ 64) :
    ArmStateEquiv Catalog.armMap :=
  ModuleRegister.extractCert Catalog.armMap dst start width hw hw32 hbound

/-- arm64/bpf_arm64_extr.c:instantiate_rotate32/emit_rotate32_arm64. -/
theorem bpf_arm64_extr_w_refines (dst src tmp : BPF.Reg) (n : Nat) (hn : n < 32)
    (hts : tmp ≠ src) (htd : tmp ≠ dst) (b : BPF.State) (a : ARM64.State)
    (hi : observeBpf b = observeArm Catalog.armMap a) :
    observeBpf (BPF.mexec (ModuleRotate.bpf .w32 dst src tmp n) b) =
      observeArm Catalog.armMap (ARM64.mexec
        (ModuleArmRotate.native .w32 (Catalog.armReg dst) (Catalog.armReg src)
          (Catalog.armReg tmp) n) a) :=
  (ModuleArmRotate.cert Catalog.armMap .w32 dst src tmp n hn hts htd).arm_refines b a hi

/-- arm64/bpf_arm64_extr.c:instantiate_rotate64/emit_rotate64_arm64. -/
theorem bpf_arm64_extr_x_refines (dst src tmp : BPF.Reg) (n : Nat) (hn : n < 64)
    (hts : tmp ≠ src) (htd : tmp ≠ dst) (b : BPF.State) (a : ARM64.State)
    (hi : observeBpf b = observeArm Catalog.armMap a) :
    observeBpf (BPF.mexec (ModuleRotate.bpf .w64 dst src tmp n) b) =
      observeArm Catalog.armMap (ARM64.mexec
        (ModuleArmRotate.native .w64 (Catalog.armReg dst) (Catalog.armReg src)
          (Catalog.armReg tmp) n) a) :=
  (ModuleArmRotate.cert Catalog.armMap .w64 dst src tmp n hn hts htd).arm_refines b a hi

/-- arm64/bpf_arm64_prfm.c:instantiate_prfm_pldl1keep/emit_prfm_pldl1keep_arm64. -/
def bpf_arm64_prfm_pldl1keep (base : BPF.Reg) : ArmStateEquiv Catalog.armMap :=
  ModulePrefetch.armCert Catalog.armMap base

/-- arm64/bpf_arm64_csel.c:instantiate_tst/emit_tst_arm64. -/
def bpf_arm64_tst (r : BPF.Reg) : ArmStateEquiv Catalog.armMap :=
  ModuleFlags.tstCert Catalog.armMap r

/-- arm64/bpf_arm64_ccmp.c:instantiate_cmp/emit_cmp_w_arm64. -/
def bpf_arm64_cmp_w (r : BPF.Reg) : ArmStateEquiv Catalog.armMap :=
  ModuleFlags.cmpCert Catalog.armMap true r

/-- arm64/bpf_arm64_ccmp.c:instantiate_cmp/emit_cmp_x_arm64. -/
def bpf_arm64_cmp_x (r : BPF.Reg) : ArmStateEquiv Catalog.armMap :=
  ModuleFlags.cmpCert Catalog.armMap false r

/-- arm64/bpf_arm64_ccmp.c:instantiate_ccmp/emit_ccmp_w_arm64. -/
def bpf_arm64_ccmp_w (r : BPF.Reg) (failNE : Bool) : ArmStateEquiv Catalog.armMap :=
  ModuleFlags.ccmpCert Catalog.armMap true failNE r

/-- arm64/bpf_arm64_ccmp.c:instantiate_ccmp/emit_ccmp_x_arm64. -/
def bpf_arm64_ccmp_x (r : BPF.Reg) (failNE : Bool) : ArmStateEquiv Catalog.armMap :=
  ModuleFlags.ccmpCert Catalog.armMap false failNE r

/-- x86/bpf_x86_prefetch.c:instantiate_prefetcht0/emit_prefetcht0_x86. -/
def bpf_x86_prefetcht0 (base : BPF.Reg) : X86StateEquiv Catalog.x86Map :=
  ModulePrefetch.x86Cert Catalog.x86Map base

/-- x86/bpf_x86_lea.c:instantiate_lea32/emit_lea32_x86. -/
def bpf_x86_leal (dst base index : BPF.Reg) (scale : Nat)
    (hasBase hasIndex : Bool) (disp : BitVec 32) (hs : scale ≤ 3)
    (halias : hasBase = true → hasIndex = true → dst = index → dst = base ∧ scale = 0) :
    X86StateEquiv Catalog.x86Map :=
  ModuleLea.cert Catalog.x86Map .w32 dst base index scale hasBase hasIndex disp hs halias

/-- x86/bpf_x86_lea.c:instantiate_lea64/emit_lea64_x86. -/
def bpf_x86_leaq (dst base index : BPF.Reg) (scale : Nat)
    (hasBase hasIndex : Bool) (disp : BitVec 32) (hs : scale ≤ 3)
    (halias : hasBase = true → hasIndex = true → dst = index → dst = base ∧ scale = 0) :
    X86StateEquiv Catalog.x86Map :=
  ModuleLea.cert Catalog.x86Map .w64 dst base index scale hasBase hasIndex disp hs halias

/-- The catalogue certificates retain the original register-map refinement pattern. -/
theorem arm_jit_sound (k : ArmStateEquiv Catalog.armMap) (b : BPF.State) (a : ARM64.State)
    (hi : observeBpf b = observeArm Catalog.armMap a) :
    observeBpf (BPF.mexec k.bpf b) = observeArm Catalog.armMap (ARM64.mexec k.native a) :=
  k.arm_refines b a hi

theorem x86_jit_sound (k : X86StateEquiv Catalog.x86Map) (b : BPF.State) (a : X86.State)
    (hi : observeBpf b = observeX86 Catalog.x86Map a) :
    observeBpf (BPF.mexec k.bpf b) = observeX86 Catalog.x86Map (X86.mexec k.native a) :=
  k.x86_refines b a hi

/-- arm64/bpf_arm64_ldr.c:decode_ldr_payload/instantiate_ldr/emit_ldr_arm64.
    The certificate consumes the actual escaped fields and signed offset.
    `hd` and `hb` are the decoder's register bounds; accepted emit offsets
    are a subset of the offsets covered by the semantic proof. -/
def armLoadPayload (bytes : Nat) (p : BitVec 64)
    (hd : Payload.regField p 0 < 10) (hb : Payload.regField p 4 ≤ 10) :
    ArmStateEquiv Catalog.armMap :=
  ModuleMemory.loadCert Catalog.armMap bytes
    (Payload.reg (Payload.regField p 0) (by omega))
    (Payload.reg (Payload.regField p 4) hb) (Payload.offset p 8)

theorem arm_load_payload_refines (bytes : Nat) (p : BitVec 64)
    (hd : Payload.regField p 0 < 10) (hb : Payload.regField p 4 ≤ 10)
    (b : BPF.State) (a : ARM64.State)
    (hi : observeBpf b = observeArm Catalog.armMap a) :
    observeBpf (BPF.mexec (armLoadPayload bytes p hd hb).bpf b) =
      observeArm Catalog.armMap (ARM64.mexec (armLoadPayload bytes p hd hb).native a) :=
  (armLoadPayload bytes p hd hb).arm_refines b a hi

/-- arm64/bpf_arm64_extr.c:decode_rotate_payload and both expansions/emitters:
    the shift byte is masked to five/six bits before instantiation. -/
theorem arm_rotate_payload_refines (w : BPF.Width) (p : BitVec 64)
    (hd : Payload.regField p 0 ≤ 10) (hs : Payload.regField p 4 ≤ 10)
    (ht : Payload.regField p 16 ≤ 10)
    (hds : Payload.reg (Payload.regField p 16) ht ≠ Payload.reg (Payload.regField p 0) hd)
    (hss : Payload.reg (Payload.regField p 16) ht ≠ Payload.reg (Payload.regField p 4) hs)
    (b : BPF.State) (a : ARM64.State) (hi : observeBpf b = observeArm Catalog.armMap a) :
    let dst := Payload.reg (Payload.regField p 0) hd
    let src := Payload.reg (Payload.regField p 4) hs
    let tmp := Payload.reg (Payload.regField p 16) ht
    let n := (Payload.byteField p 8).toNat % (if w = .w64 then 64 else 32)
    observeBpf (BPF.mexec (ModuleRotate.bpf w dst src tmp n) b) =
      observeArm Catalog.armMap (ARM64.mexec
        (ModuleArmRotate.native w (Catalog.armReg dst) (Catalog.armReg src)
          (Catalog.armReg tmp) n) a) := by
  dsimp only
  apply (ModuleArmRotate.cert Catalog.armMap w _ _ _ _ ?_ hss hds).arm_refines b a hi
  exact Nat.mod_lt _ (by cases w <;> decide)

end Kinsn.ModuleCatalog
