import KinsnLean4.Kinsn.Catalog
import KinsnLean4.Kinsn.ModuleFlags
import KinsnLean4.Kinsn.ModuleRegister

/-! Pre-fix C snapshot at commit `69f9a30f6`. These counterexamples are historical
records, not models of the corrected module code.

Kernel-checked counterexamples, with the complete selected C expansion,
including spills and restores. No `native_decide` or assumed equivalence.
The states are initially related by the actual JIT register maps. -/
namespace Kinsn.Counterexamples

def state (values : List (BPF.Reg × BitVec 64)) (mem : Machine.Memory := fun _ => 0)
    (flags : Machine.Flags := {}) : BPF.State :=
  ⟨fun r => if r = .r10 then 4096 else (values.lookup r).getD 0, mem, [], flags⟩

def liftX86 (s : BPF.State) : X86.State :=
  ⟨fun r => match r with
    | .rax => s.regs .r0 | .rdi => s.regs .r1 | .rsi => s.regs .r2
    | .rdx => s.regs .r3 | .rcx => s.regs .r4 | .r8 => s.regs .r5
    | .rbx => s.regs .r6 | .r13 => s.regs .r7 | .r14 => s.regs .r8
    | .r15 => s.regs .r9 | .rbp => s.regs .r10 | _ => 0,
    s.mem, s.trace, s.flags⟩

def liftArm (s : BPF.State) : ARM64.State :=
  ⟨fun r => match r with
    | .x7 => s.regs .r0 | .x0 => s.regs .r1 | .x1 => s.regs .r2
    | .x2 => s.regs .r3 | .x3 => s.regs .r4 | .x4 => s.regs .r5
    | .x19 => s.regs .r6 | .x20 => s.regs .r7 | .x21 => s.regs .r8
    | .x22 => s.regs .r9 | .x25 => s.regs .r10 | _ => 0,
    s.mem, s.trace, s.flags⟩

theorem lift_x86_related (s : BPF.State) : observeBpf s = observeX86 Catalog.x86Map (liftX86 s) := by
  unfold observeBpf observeX86 liftX86; congr 1; funext r; cases r <;> rfl

theorem lift_arm_related (s : BPF.State) : observeBpf s = observeArm Catalog.armMap (liftArm s) := by
  unfold observeBpf observeArm liftArm; congr 1; funext r; cases r <;> rfl

/-- include/kop_x86_emit.h:kop_x86_scratch_off. -/
def slot (r : BPF.Reg) : BitVec 64 :=
  match r with | .r6 => -40 | .r7 => -32 | _ => -24
/-- include/kop_x86_emit.h:kop_x86_save_scratch, increasing register order. -/
def save (rs : List BPF.Reg) : List BPF.MInsn :=
  rs.map (fun r => .store 8 .r10 (.reg r) (slot r))
/-- include/kop_x86_emit.h:kop_x86_restore_scratch, decreasing register order. -/
def restore (rs : List BPF.Reg) : List BPF.MInsn :=
  rs.reverse.map (fun r => .load 8 r .r10 (slot r))

def rr (op : BPF.AluOp) (w : BPF.Width) (d s : BPF.Reg) : BPF.MInsn :=
  .core (.alu op w d (.reg s))
def ri (op : BPF.AluOp) (w : BPF.Width) (d : BPF.Reg) (i : BitVec 64) : BPF.MInsn :=
  .core (.alu op w d (.imm i))
abbrev result (p : List BPF.MInsn) (q : List X86.MInsn) (s : BPF.State) (d : BPF.Reg) : Prop :=
  (BPF.mexec p s).regs d ≠ (X86.mexec q (liftX86 s)).regs (Catalog.x86Reg d)

/-- arm64/bpf_arm64_rev.c:instantiate_rev16_w/emit_rev16_w_arm64. -/
theorem rev16_w_mismatch :
    let s := state [(.r0, 0x12340000)]
    (BPF.mexec [.core (.bswap .b16 .r0)] s).regs .r0 ≠
      (ARM64.mexec [.rev16W .x7 .x7] (liftArm s)).armGet .x7 := by decide +kernel

/-- arm64/bpf_arm64_csel.c:instantiate_csel_ne/emit_csel_ne_arm64;
    the standalone emitter ignores the payload's condition register. -/
theorem csel_ne_mismatch :
    let s := state [(.r1, 1), (.r2, 11), (.r3, 22)] (fun _ => 0) {z := true}
    (BPF.mexec (ModuleFlags.cselBpf .r0 .r2 .r3 .r1) s).regs .r0 ≠
      (ARM64.mexec (ModuleFlags.cselArm Catalog.armMap .r0 .r2 .r3) (liftArm s)).armGet .x7 :=
  by decide +kernel

/-- arm64/bpf_arm64_ccmp.c:instantiate_cset, count=2, FAIL_EQ, width64. -/
def csetBpf : List BPF.MInsn :=
  [ri .mov .w64 .r0 0, .branch .eq .w64 .r1 (.imm 0) 2,
    .branch .eq .w64 .r2 (.imm 0) 1, ri .mov .w64 .r0 1]
/-- arm64/bpf_arm64_ccmp.c:emit_cset_arm64, CSET X7,NE. -/
theorem cset_mismatch :
    let s := state [(.r1, 1), (.r2, 1)] (fun _ => 0) {z := true}
    (BPF.mexec csetBpf s).regs .r0 ≠
      (ARM64.mexec [.cset .x7 true] (liftArm s)).armGet .x7 := by decide +kernel

/-- x86/bpf_x86_cmov.c:instantiate_cmp_cmov_rr/emit_cmp_cmov_rr_x86,
    false 32-bit CMOV condition, destination R3 has a nonzero upper half. -/
abbrev cmovBad (c : X86.CC) : Prop :=
  let s := state [(.r0, if c = .b then 1 else 0),
    (.r1, if c = .e then 1 else 0), (.r3, 0x100000001)]
  result (ModuleFlags.cmovBpf c false true .r0 .r1 .r3 .r5)
    (ModuleFlags.cmovX86 Catalog.x86Map c false true .r0 .r1 .r3 .r5) s .r3
theorem cmove32_mismatch : cmovBad .e := by decide +kernel
theorem cmovne32_mismatch : cmovBad .ne := by decide +kernel
theorem cmovb32_mismatch : cmovBad .b := by decide +kernel

/-- x86/bpf_x86_bmi2_shift.c:instantiate_bmi2_shift, dst=R6,src=R0,cnt=R2. -/
def bmiShiftBpf (w : BPF.Width) (left : Bool) : List BPF.MInsn :=
  save [.r6,.r7] ++ [rr .mov w .r6 .r0, rr .mov w .r7 .r2,
    rr (if left then .lsh else .rsh) w .r6 .r7] ++ restore [.r6,.r7]
/-- x86/bpf_x86_bmi2_shift.c:emit_bmi2_shift_x86. -/
abbrev bmiShiftBad (w : BPF.Width) (left : Bool) : Prop :=
  result (bmiShiftBpf w left) [.shift (if w = .w64 then 64 else 32) left .rbx .rax .rsi]
    (state [(.r0, if left then 1 else 2), (.r2, 1)]) .r6
theorem shlxl_mismatch : bmiShiftBad .w32 true := by decide +kernel
theorem shlxq_mismatch : bmiShiftBad .w64 true := by decide +kernel
theorem shrxl_mismatch : bmiShiftBad .w32 false := by decide +kernel
theorem shrxq_mismatch : bmiShiftBad .w64 false := by decide +kernel

/-- x86/bpf_x86_bmi2_shift.c:instantiate_bzhi, dst=R1,src=R0,cnt=R2. -/
def bzhiBpf (w : BPF.Width) : List BPF.MInsn :=
  save [.r6,.r7,.r8] ++ [rr .mov w .r6 .r0, rr .mov w .r7 .r2,
    .branch .ge .w64 .r7 (.imm (if w = .w64 then 64 else 32)) 4,
    ri .mov w .r8 1, rr .lsh w .r8 .r7, ri .add w .r8 (-1), rr .and w .r6 .r8,
    rr .mov w .r1 .r6] ++ restore [.r6,.r7,.r8]
/-- x86/bpf_x86_bmi2_shift.c:emit_bzhi_x86, count uses only its low byte. -/
abbrev bzhiBad (w : BPF.Width) : Prop :=
  result (bzhiBpf w) [.bzhi (if w = .w64 then 64 else 32) .rdi .rax .rsi]
    (state [(.r0, -1), (.r2, 256)]) .r1
theorem bzhil_mismatch : bzhiBad .w32 := by decide +kernel
theorem bzhiq_mismatch : bzhiBad .w64 := by decide +kernel

/-- x86/bpf_x86_bmi1.c:instantiate_bextrq, payload=0x601.
    Complete branch offsets, including both restoration paths. -/
def bextrBpf : List BPF.MInsn :=
  save [.r6,.r7,.r8] ++ [rr .mov .w64 .r6 .r0, rr .mov .w64 .r7 .r6,
    rr .mov .w64 .r8 .r7, ri .and .w64 .r8 255,
    .branch .ge .w64 .r8 (.imm 64) 14, rr .rsh .w64 .r6 .r8,
    ri .rsh .w64 .r7 8, ri .and .w64 .r7 255,
    .branch .eq .w64 .r7 (.imm 0) 10, .branch .ge .w64 .r7 (.imm 64) 4,
    ri .mov .w64 .r8 1, rr .lsh .w64 .r8 .r7, ri .add .w64 .r8 (-1),
    rr .and .w64 .r6 .r8, rr .mov .w64 .r1 .r6] ++ restore [.r6,.r7,.r8] ++
    [.ja 5, ri .mov .w64 .r6 0, rr .mov .w64 .r1 .r6] ++ restore [.r6,.r7,.r8]
/-- x86/bpf_x86_bmi1.c:emit_bextrq_x86. -/
theorem bextrq_mismatch : result bextrBpf [.core (.bextr .rdi .rax .rbx)]
    (state [(.r0, 255), (.r6, 0x0801)]) .r1 := by decide +kernel

/-- x86/bpf_x86_bmi1.c:instantiate_blsiq/instantiate_blsrq, dst=R6,src=R0. -/
def blsBpf (reset : Bool) : List BPF.MInsn :=
  save [.r6,.r7] ++ [rr .mov .w64 .r6 .r0] ++
    (if reset then [rr .mov .w64 .r7 .r6, ri .add .w64 .r7 (-1)]
     else [ri .mov .w64 .r7 0, rr .sub .w64 .r7 .r6]) ++
    [rr .and .w64 .r6 .r7] ++ restore [.r6,.r7]
/-- x86/bpf_x86_bmi1.c:emit_blsiq_x86/emit_blsrq_x86. -/
theorem blsiq_mismatch : result (blsBpf false) [.blsi .rbx .rax]
    (state [(.r0, 3)]) .r6 := by decide +kernel
theorem blsrq_mismatch : result (blsBpf true) [.blsr .rbx .rax]
    (state [(.r0, 3)]) .r6 := by decide +kernel

/-- x86/bpf_x86_rotate.c:instantiate_rol_cl, dst=R6,cnt=R4. -/
def rolBpf (w : BPF.Width) : List BPF.MInsn :=
  let mask : BitVec 64 := if w = .w64 then 63 else 31
  save [.r6,.r7,.r8] ++ [rr .mov w .r7 .r4, ri .and w .r7 mask,
    rr .mov w .r8 .r6, rr .lsh w .r6 .r7, ri .neg w .r7 0,
    ri .and w .r7 mask, rr .rsh w .r8 .r7, rr .or w .r6 .r8] ++
    restore [.r6,.r7,.r8]
/-- x86/bpf_x86_rotate.c:emit_rol_cl_x86. -/
theorem roll_mismatch : result (rolBpf .w32) [.rolCL 32 .rbx]
    (state [(.r6, 1), (.r4, 1)]) .r6 := by decide +kernel
theorem rolq_mismatch : result (rolBpf .w64) [.rolCL 64 .rbx]
    (state [(.r6, 1), (.r4, 1)]) .r6 := by decide +kernel

/-- x86/bpf_x86_rotate.c:instantiate_rotate, ARCH_IMM, dst=R0,src=R8,shift=1. -/
def rorxlBpf : List BPF.MInsn :=
  save [.r6,.r7] ++ [.load 8 .r6 .r10 (-24), rr .mov .w32 .r7 .r6,
    ri .lsh .w32 .r6 1, ri .rsh .w32 .r7 31, rr .or .w32 .r6 .r7,
    rr .mov .w32 .r0 .r6] ++ restore [.r6,.r7]
/-- x86/bpf_x86_rotate.c:emit_rotate32_x86; RORX count=(-1)&31. -/
theorem rorxl_mismatch : result rorxlBpf [.rorx32 .rax .r14 31]
    (state [(.r8, 1)]) .r0 := by decide +kernel

/-- x86/bpf_x86_byteorder.c:instantiate_rolw_imm/emit_rolw_imm_x86, imm=8. -/
theorem rolw_mismatch : result [.core (.bswap .b16 .r0)] [.rolW .rax 8]
    (state [(.r0, 0x10000)]) .r0 := by decide +kernel

/-- x86/bpf_x86_shd.c:instantiate_shd_imm, dst=R6,src=R0,imm=1. -/
def shdBpf (w : BPF.Width) (left : Bool) : List BPF.MInsn :=
  let width : BitVec 64 := if w = .w64 then 63 else 31
  save [.r6,.r7] ++ [rr .mov w .r7 .r0,
    ri (if left then .rsh else .lsh) w .r7 width,
    ri (if left then .lsh else .rsh) w .r6 1, rr .or w .r6 .r7] ++ restore [.r6,.r7]
/-- x86/bpf_x86_shd.c:emit_shd_imm_x86. -/
abbrev shdBad (w : BPF.Width) (left : Bool) : Prop :=
  result (shdBpf w left) [.shd (if w = .w64 then 64 else 32) left .rbx .rax 1]
    (state [(.r0, 1), (.r6, 1)]) .r6
theorem shldl_mismatch : shdBad .w32 true := by decide +kernel
theorem shldq_mismatch : shdBad .w64 true := by decide +kernel
theorem shrdl_mismatch : shdBad .w32 false := by decide +kernel
theorem shrdq_mismatch : shdBad .w64 false := by decide +kernel

/-- x86/bpf_x86_not.c:instantiate_not_narrow, nonarch dst=R6. -/
def notNarrowBpf (mask : BitVec 64) : List BPF.MInsn :=
  save [.r6,.r7] ++ [rr .mov .w64 .r7 .r6, ri .and .w64 .r7 (~~~mask),
    ri .xor .w64 .r6 mask, ri .and .w64 .r6 mask, rr .or .w64 .r6 .r7] ++ restore [.r6,.r7]
/-- x86/bpf_x86_not.c:emit_notb_r_x86/emit_notw_r_x86. -/
theorem notb_mismatch : result (notNarrowBpf 255) [.not 8 .rbx] (state []) .r6 :=
  by decide +kernel
theorem notw_mismatch : result (notNarrowBpf 65535) [.not 16 .rbx] (state []) .r6 :=
  by decide +kernel

/-- x86/bpf_x86_not.c:instantiate_notl_r/instantiate_notq_r, ARCH_IMM dst=R7. -/
def notWideBpf (w : BPF.Width) : List BPF.MInsn :=
  save [.r6] ++ [.load 8 .r6 .r10 (-32), ri .xor w .r6 (-1),
    .store 8 .r10 (.reg .r6) (-32)] ++ restore [.r6]
/-- x86/bpf_x86_not.c:emit_notl_r_x86/emit_notq_r_x86. -/
theorem notl_mismatch : result (notWideBpf .w32) [.not 32 .r13]
    (state [(.r7, 1)]) .r7 := by decide +kernel
theorem notq_mismatch : result (notWideBpf .w64) [.not 64 .r13]
    (state [(.r7, 1)]) .r7 := by decide +kernel

/-- x86/bpf_x86_byteorder.c:instantiate_bswap, ARCH_IMM dst=R7. -/
def bswapBpf (sz : BPF.EndSize) : List BPF.MInsn :=
  save [.r6] ++ [.load 8 .r6 .r10 (-32), .core (.bswap sz .r6),
    .store 8 .r10 (.reg .r6) (-32)] ++ restore [.r6]
/-- x86/bpf_x86_byteorder.c:emit_bswapl_x86/emit_bswapq_x86. -/
theorem bswapl_mismatch : result (bswapBpf .b32) [.bswap32 .r13]
    (state [(.r7, 1)]) .r7 := by decide +kernel
theorem bswapq_mismatch : result (bswapBpf .b64) [.core (.bswap .r13)]
    (state [(.r7, 1)]) .r7 := by decide +kernel

/-- x86/bpf_x86_imul.c:instantiate_imulq_rr, ARCH_RR dst=R8,src=R0. -/
def imulBpf : List BPF.MInsn :=
  save [.r6,.r7] ++ [.load 8 .r6 .r10 (-24), rr .mov .w64 .r7 .r0,
    rr .mul .w64 .r6 .r7, .store 8 .r10 (.reg .r6) (-24)] ++ restore [.r6,.r7]
/-- x86/bpf_x86_imul.c:emit_imulq_rr_x86. -/
theorem imulq_mismatch : result imulBpf [.imul .r14 .rax]
    (state [(.r8, 2), (.r0, 3)]) .r8 := by decide +kernel

/-- x86/bpf_x86_popcnt.c:instantiate_popcntq, nonarch dst=R6,src=R0:
    the fast path rejects scratch destinations, so this is its SWAR path. -/
def popcntBpf : List BPF.MInsn :=
  save [.r6,.r7,.r8] ++ [rr .mov .w64 .r6 .r0, rr .mov .w64 .r7 .r6,
    ri .rsh .w64 .r7 1, .core (.ldImm64 .r8 0x5555555555555555),
    rr .and .w64 .r7 .r8, rr .sub .w64 .r6 .r7,
    rr .mov .w64 .r7 .r6, ri .rsh .w64 .r7 2,
    .core (.ldImm64 .r8 0x3333333333333333), rr .and .w64 .r7 .r8,
    rr .and .w64 .r6 .r8, rr .add .w64 .r6 .r7,
    rr .mov .w64 .r7 .r6, ri .rsh .w64 .r7 4, rr .add .w64 .r6 .r7,
    .core (.ldImm64 .r8 0x0f0f0f0f0f0f0f0f), rr .and .w64 .r6 .r8,
    .core (.ldImm64 .r8 0x0101010101010101), rr .mul .w64 .r6 .r8,
    ri .rsh .w64 .r6 56] ++ restore [.r6,.r7,.r8]
/-- x86/bpf_x86_popcnt.c:emit_popcntq_x86. -/
theorem popcntq_mismatch : result popcntBpf [.popcnt .rbx .rax]
    (state [(.r0, 3)]) .r6 := by decide +kernel

/-- x86/bpf_x86_alu.c:instantiate_x86_alu_sib, dst=R8,base=R1,index=R2,
    scale=0,offset=0. The destination is in the restored scratch mask. -/
def aluSibBpf (op : BPF.AluOp) (w : BPF.Width) : List BPF.MInsn :=
  save [.r6,.r7,.r8] ++ [rr .mov .w64 .r6 .r1, rr .mov .w64 .r7 .r2,
    rr .add .w64 .r6 .r7, .load (if w = .w64 then 8 else 4) .r7 .r6 0,
    rr op w .r8 .r7] ++ (if w = .w32 then [rr .mov .w32 .r8 .r8] else []) ++
    restore [.r6,.r7,.r8]
/-- x86/bpf_x86_alu.c:emit_alu_sib_x86. -/
abbrev aluSibBad (bop : BPF.AluOp) (xop : X86.AluOp) (w : BPF.Width) : Prop :=
  result (aluSibBpf bop w) [.aluMem xop (w = .w32) .r14 .rdi .rsi 0 0]
    (state [(.r8, 2)] (fun a => if a = 0 then 1 else 0)) .r8
theorem addl_mismatch : aluSibBad .add .add .w32 := by decide +kernel
theorem addq_mismatch : aluSibBad .add .add .w64 := by decide +kernel
theorem subl_mismatch : aluSibBad .sub .sub .w32 := by decide +kernel
theorem subq_mismatch : aluSibBad .sub .sub .w64 := by decide +kernel
theorem andl_mismatch : aluSibBad .and .and .w32 := by decide +kernel
theorem andq_mismatch : aluSibBad .and .and .w64 := by decide +kernel
theorem xorl_mismatch : aluSibBad .xor .xor .w32 := by decide +kernel
theorem xorq_mismatch : aluSibBad .xor .xor .w64 := by decide +kernel
theorem orl_mismatch : aluSibBad .or .or .w32 := by decide +kernel
theorem orq_mismatch : aluSibBad .or .or .w64 := by decide +kernel

/-- x86/bpf_x86_alu.c:instantiate_x86_shift_cl, dst=R6,count=R4. -/
def shiftBpf (op : BPF.AluOp) (w : BPF.Width) : List BPF.MInsn :=
  save [.r6,.r7] ++ [rr .mov .w64 .r7 .r4,
    ri .and .w64 .r7 (if w = .w64 then 63 else 31), rr op w .r6 .r7] ++
    (if w = .w32 then [rr .mov .w32 .r6 .r6] else []) ++ restore [.r6,.r7]
/-- x86/bpf_x86_alu.c:emit_x86_alu, CL form. -/
abbrev shiftBad (bop : BPF.AluOp) (xop : X86.ShiftOp) (w : BPF.Width) : Prop :=
  result (shiftBpf bop w) [.shiftCLWidth (if w = .w64 then 64 else 32) xop .rbx]
    (state [(.r6, 2), (.r4, 1)]) .r6
theorem shll_mismatch : shiftBad .lsh .shl .w32 := by decide +kernel
theorem shlq_mismatch : shiftBad .lsh .shl .w64 := by decide +kernel
theorem shrl_mismatch : shiftBad .rsh .shr .w32 := by decide +kernel
theorem shrq_mismatch : shiftBad .rsh .shr .w64 := by decide +kernel
theorem sarl_mismatch : shiftBad .arsh .sar .w32 := by decide +kernel
theorem sarq_mismatch : shiftBad .arsh .sar .w64 := by decide +kernel

/-- x86/bpf_x86_alu.c:instantiate_x86_alu_narrow, dst=R6,src=R0.
    For shifts src is R4 as required by the decoder. -/
def narrowBpf (op : BPF.AluOp) (bits : Nat) (shift : Bool) : List BPF.MInsn :=
  let mask := Bits.lowMask 64 bits
  save [.r6,.r7,.r8] ++ [rr .mov .w64 .r7 .r6, ri .and .w64 .r7 (~~~mask),
    ri .and .w64 .r6 mask, rr .mov .w64 .r8 (if shift then .r4 else .r0),
    ri .and .w64 .r8 (if shift then 31 else mask), rr op .w64 .r6 .r8,
    ri .and .w64 .r6 mask, rr .or .w64 .r6 .r7] ++ restore [.r6,.r7,.r8]
/-- x86/bpf_x86_alu.c:emit_x86_alu_narrow. -/
abbrev narrowBad (bop : BPF.AluOp) (xop : X86.AluOp) (bits : Nat) : Prop :=
  result (narrowBpf bop bits false) [.aluNarrow xop bits .rbx .rax]
    (state [(.r6, 2), (.r0, 1)]) .r6
theorem addb_mismatch : narrowBad .add .add 8 := by decide +kernel
theorem subb_mismatch : narrowBad .sub .sub 8 := by decide +kernel
theorem andb_mismatch : narrowBad .and .and 8 := by decide +kernel
theorem orb_mismatch : narrowBad .or .or 8 := by decide +kernel
theorem orw_mismatch : narrowBad .or .or 16 := by decide +kernel
theorem shlb_mismatch : result (narrowBpf .lsh 8 true) [.shiftCLWidth 8 .shl .rbx]
    (state [(.r6, 2), (.r4, 1)]) .r6 := by decide +kernel
theorem shrb_mismatch : result (narrowBpf .rsh 8 true) [.shiftCLWidth 8 .shr .rbx]
    (state [(.r6, 2), (.r4, 1)]) .r6 := by decide +kernel

/-- x86/bpf_x86_alu.c:instantiate_xorb_imm, dst=R6,imm=1. -/
def xorbBpf : List BPF.MInsn :=
  save [.r6] ++ [ri .xor .w64 .r6 1] ++ restore [.r6]
/-- x86/bpf_x86_alu.c:emit_xorb_imm_x86. -/
theorem xorb_mismatch : result xorbBpf [.aluImmNarrow .xor 8 .rbx 1]
    (state []) .r6 := by decide +kernel

/-- x86/bpf_x86_alu.c:instantiate_x86_xorw_mem, dst=R6,base=R7.
    scratch_avoid exhausts its three candidates and returns R6 for high_reg. -/
def xorwBpf : List BPF.MInsn :=
  save [.r6,.r8] ++ [.load 2 .r8 .r7 0, rr .mov .w64 .r6 .r6,
    ri .and .w64 .r6 (-65536), rr .xor .w64 .r6 .r8,
    ri .and .w64 .r6 65535, rr .or .w64 .r6 .r6] ++ restore [.r6,.r8]
/-- x86/bpf_x86_alu.c:emit_xorw_x86. Native XOR word [R13], to BX. -/
theorem xorw_mismatch : result xorwBpf [.aluMemNarrow .xor 16 .rbx .r13 0]
    (state [(.r6, 2)] (fun a => if a = 0 then 1 else 0)) .r6 := by decide +kernel

/-- x86/bpf_x86_alu.c:instantiate_inc, ARCH_IMM dst=R6,imm=0. -/
def incBpf (w : BPF.Width) : List BPF.MInsn :=
  save [.r7] ++ [.load 8 .r7 .r10 (-40), ri .add w .r7 1,
    .store 8 .r10 (.reg .r7) (-40)] ++ restore [.r7]
/-- x86/bpf_x86_alu.c:emit_incl_x86/emit_incq_x86. -/
theorem incl_mismatch : result (incBpf .w32) [.inc 32 .rbx]
    (state [(.r6, 2)]) .r6 := by decide +kernel
theorem incq_mismatch : result (incBpf .w64) [.inc 64 .rbx]
    (state [(.r6, 2)]) .r6 := by decide +kernel

/-- x86/bpf_x86_mov.c:instantiate_movsxd, RR dst=R6,src=R0. -/
def movsxdBpf : List BPF.MInsn :=
  save [.r6] ++ [rr .mov .w64 .r6 .r0, ri .lsh .w64 .r6 32,
    ri .arsh .w64 .r6 32] ++ restore [.r6]
/-- x86/bpf_x86_mov.c:emit_movsxd_x86. -/
theorem movsxd_mismatch : result movsxdBpf [.core (.movsx 32 .rbx .rax)]
    (state [(.r0, 1)]) .r6 := by decide +kernel

/-- x86/bpf_x86_mov.c:instantiate_movq_value/instantiate_movl_reg,
    ARCH_RR dst=R0,src=R7. The source's slot is not initialized. -/
def movWideBpf (w32 : Bool) : List BPF.MInsn :=
  [.load 8 .r0 .r10 (-32)] ++ (if w32 then [rr .mov .w32 .r0 .r0] else [])
/-- x86/bpf_x86_mov.c:emit_mov_rr_x86. -/
theorem movl_mismatch : result (movWideBpf true) [.mov32 .rax .r13]
    (state [(.r7, 1)]) .r0 := by decide +kernel
theorem movq_mismatch : result (movWideBpf false) [.core (.movRR .rax .r13)]
    (state [(.r7, 1)]) .r0 := by decide +kernel

/-- x86/bpf_x86_mov.c:instantiate_movzx_rr, ARCH_RR dst=R0,src=R7. -/
def movzxBpf (mask : BitVec 64) : List BPF.MInsn :=
  [.load 8 .r0 .r10 (-32), ri .and .w32 .r0 mask]
/-- x86/bpf_x86_mov.c:emit_movzx_rr_x86. -/
theorem movzbl_mismatch : result (movzxBpf 255) [.movzx 8 .rax .r13]
    (state [(.r7, 1)]) .r0 := by decide +kernel
theorem movzwl_mismatch : result (movzxBpf 65535) [.movzx 16 .rax .r13]
    (state [(.r7, 1)]) .r0 := by decide +kernel
/-- x86/bpf_x86_mov.c:instantiate_movswl_rr/emit_movswl_x86. -/
theorem movswl_mismatch : result [.load 8 .r0 .r10 (-32),
    ri .lsh .w32 .r0 16, ri .arsh .w32 .r0 16] [.movswl .rax .r13]
    (state [(.r7, 1)]) .r0 := by decide +kernel

/-- x86/bpf_x86_mov.c:instantiate_mov_imm_store, ARCH_STORE_IMM base=R7,
    offset=0,imm=0x5a. Its source slot is not among the saved registers. -/
def movStoreBpf (bytes : Nat) : List BPF.MInsn :=
  save [.r6] ++ [.load 8 .r6 .r10 (-32), .store bytes .r6 (.imm 0x5a) 0] ++ restore [.r6]
/-- x86/bpf_x86_mov.c:emit_mov_imm_store_x86. Memory disagreement at address 0. -/
abbrev movStoreBad (bytes : Nat) : Prop :=
  let s := state [(.r7, 256)]
  (BPF.mexec (movStoreBpf bytes) s).mem 0 ≠
    (X86.mexec [.storeImm bytes .r13 0 0x5a] (liftX86 s)).mem 0
theorem movb_mismatch : movStoreBad 1 := by decide +kernel
theorem movw_mismatch : movStoreBad 2 := by decide +kernel

/-- x86/bpf_x86_movbe.c:instantiate_movbe_indexed, dst=R0,base=R6,index=R7,
    scale=0,offset=0. high_reg=R7 clobbers the index before address formation. -/
def movbe16Bpf : List BPF.MInsn :=
  save [.r6,.r7,.r8] ++ [rr .mov .w64 .r7 .r0, ri .rsh .w64 .r7 16,
    ri .lsh .w64 .r7 16, rr .mov .w64 .r8 .r6, rr .add .w64 .r8 .r7,
    ri .mov .w64 .r0 0, .load 1 .r6 .r8 0, ri .lsh .w64 .r6 8,
    rr .or .w64 .r0 .r6, .load 1 .r6 .r8 1, rr .or .w64 .r0 .r6,
    rr .or .w64 .r0 .r7] ++ restore [.r6,.r7,.r8]
/-- x86/bpf_x86_movbe.c:emit_movbe_indexed_x86, MOVBE AX,[RBX+R13]. -/
theorem movbe16_mismatch : result movbe16Bpf [.loadIndex 2 .rax .rbx .r13 0 0 true]
    (state [(.r7, 1)] (fun a => if a = 1 then 1 else 0)) .r0 := by decide +kernel

/-- x86/bpf_x86_movbe.c:instantiate_movbe_indexed, dst=R6,base=R7,index=R8.
    Both scratch_avoid and scratch_avoid4 exhaust candidates, returning R6. -/
def movbeWideBpf (bytes : Nat) : List BPF.MInsn :=
  save [.r6] ++ [rr .mov .w64 .r6 .r7, rr .add .w64 .r6 .r8, ri .mov .w64 .r6 0] ++
    (List.range bytes).flatMap (fun i => [.load 1 .r6 .r6 (BitVec.ofNat 64 i)] ++
      (if i = bytes - 1 then [] else [ri .lsh .w64 .r6 (BitVec.ofNat 64 ((bytes-1-i)*8))]) ++
      [rr .or .w64 .r6 .r6]) ++ restore [.r6]
/-- x86/bpf_x86_movbe.c:emit_movbe_indexed_x86. -/
theorem movbe32_mismatch : result (movbeWideBpf 4) [.loadIndex 4 .rbx .r13 .r14 0 0 true]
    (state [(.r7, 256)] (fun a => if a = 256 then 1 else 0)) .r6 := by decide +kernel
theorem movbe64_mismatch : result (movbeWideBpf 8) [.loadIndex 8 .rbx .r13 .r14 0 0 true]
    (state [(.r7, 256)] (fun a => if a = 256 then 1 else 0)) .r6 := by decide +kernel

/-- x86/bpf_x86_alu.c:instantiate_inc: this unconditional width check
    precedes every width=8 branch. instantiate_incb always passes 8. -/
def incWidthAccepted (width : Nat) : Bool := width == 32 || width == 64
theorem incb_rejected : incWidthAccepted 8 = false := rfl

/-- x86/bpf_x86_alu.c:instantiate_divl, IMM divisor=R1,imm=0.
    EDX:EAX is R3:R0. Both outputs use MOV32, truncating the quotient. -/
def divlBpf : List BPF.MInsn :=
  save [.r6,.r7,.r8] ++ [rr .mov .w32 .r6 .r3, ri .lsh .w64 .r6 32,
    rr .mov .w32 .r8 .r0, rr .mov .w32 .r8 .r8, rr .or .w64 .r6 .r8,
    rr .mov .w32 .r7 .r1, rr .mov .w32 .r7 .r7, rr .mov .w64 .r8 .r6,
    .divide true .r8 .r7, .divide false .r6 .r7,
    rr .mov .w32 .r0 .r6, rr .mov .w32 .r3 .r8] ++ restore [.r6,.r7,.r8]

/-- x86/bpf_x86_alu.c:emit_divl_x86, DIV r/m32. `none` is #DE, which
    has no normal fall-through result. Both zero and quotient overflow trap. -/
def nativeDiv32 (high low divisor : BitVec 32) : Option (BitVec 32 × BitVec 32) :=
  let dividend := high.toNat * 2^32 + low.toNat
  if divisor = 0 ∨ dividend / divisor.toNat ≥ 2^32 then none
  else some (BitVec.ofNat 32 (dividend / divisor.toNat),
    BitVec.ofNat 32 (dividend % divisor.toNat))

theorem divl_overflow_mismatch :
    (BPF.mexec divlBpf (state [(.r3, 1), (.r1, 1)])).regs .r0 = 0 ∧
    nativeDiv32 1 0 1 = none := by decide +kernel
theorem divl_zero_mismatch :
    (BPF.mexec divlBpf (state [(.r0, 7)])).regs .r0 = 0 ∧
    nativeDiv32 0 7 0 = none := by decide +kernel

end Kinsn.Counterexamples
