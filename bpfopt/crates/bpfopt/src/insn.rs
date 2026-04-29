// SPDX-License-Identifier: MIT
//! BPF instruction encoding, decoding, and constructors.

use std::fmt;
use std::hash::{Hash, Hasher};
use std::ops::{Deref, DerefMut};

use serde::Serialize;

// ── Instruction classes ──────────────────────────────────────────────
pub const BPF_LD: u8 = kernel_sys::BPF_LD as u8;
pub const BPF_LDX: u8 = kernel_sys::BPF_LDX as u8;
pub const BPF_ST: u8 = kernel_sys::BPF_ST as u8;
pub const BPF_STX: u8 = kernel_sys::BPF_STX as u8;
pub const BPF_ALU: u8 = kernel_sys::BPF_ALU as u8;
pub const BPF_JMP: u8 = kernel_sys::BPF_JMP as u8;
pub const BPF_JMP32: u8 = kernel_sys::BPF_JMP32 as u8;
pub const BPF_ALU64: u8 = kernel_sys::BPF_ALU64 as u8;

// ── Size modifiers ───────────────────────────────────────────────────
pub const BPF_W: u8 = kernel_sys::BPF_W as u8; // 32-bit
pub const BPF_H: u8 = kernel_sys::BPF_H as u8; // 16-bit
pub const BPF_B: u8 = kernel_sys::BPF_B as u8; //  8-bit
pub const BPF_DW: u8 = kernel_sys::BPF_DW as u8; // 64-bit

// ── Mode modifiers ───────────────────────────────────────────────────
pub const BPF_IMM: u8 = kernel_sys::BPF_IMM as u8;
pub const BPF_MEM: u8 = kernel_sys::BPF_MEM as u8;
pub const BPF_MEMSX: u8 = kernel_sys::BPF_MEMSX as u8;

// ── ALU/JMP operations ──────────────────────────────────────────────
pub const BPF_ADD: u8 = kernel_sys::BPF_ADD as u8;
pub const BPF_SUB: u8 = kernel_sys::BPF_SUB as u8;
pub const BPF_MUL: u8 = kernel_sys::BPF_MUL as u8;
pub const BPF_DIV: u8 = kernel_sys::BPF_DIV as u8;
pub const BPF_OR: u8 = kernel_sys::BPF_OR as u8;
pub const BPF_AND: u8 = kernel_sys::BPF_AND as u8;
pub const BPF_LSH: u8 = kernel_sys::BPF_LSH as u8;
pub const BPF_RSH: u8 = kernel_sys::BPF_RSH as u8;
pub const BPF_NEG: u8 = kernel_sys::BPF_NEG as u8;
pub const BPF_MOD: u8 = kernel_sys::BPF_MOD as u8;
pub const BPF_XOR: u8 = kernel_sys::BPF_XOR as u8;
pub const BPF_MOV: u8 = kernel_sys::BPF_MOV as u8;
pub const BPF_ARSH: u8 = kernel_sys::BPF_ARSH as u8;
pub const BPF_END: u8 = kernel_sys::BPF_END as u8;
pub const BPF_TO_BE: u8 = kernel_sys::BPF_TO_BE as u8;

// ── Source modifiers ────────────────────────────────────────────────
pub const BPF_K: u8 = kernel_sys::BPF_K as u8;
pub const BPF_X: u8 = kernel_sys::BPF_X as u8;

// ── JMP opcodes ─────────────────────────────────────────────────────
pub const BPF_JA: u8 = kernel_sys::BPF_JA as u8;
pub const BPF_JEQ: u8 = kernel_sys::BPF_JEQ as u8;
pub const BPF_JGT: u8 = kernel_sys::BPF_JGT as u8;
pub const BPF_JGE: u8 = kernel_sys::BPF_JGE as u8;
pub const BPF_JSET: u8 = kernel_sys::BPF_JSET as u8;
pub const BPF_JNE: u8 = kernel_sys::BPF_JNE as u8;
pub const BPF_JLT: u8 = kernel_sys::BPF_JLT as u8;
pub const BPF_JLE: u8 = kernel_sys::BPF_JLE as u8;
pub const BPF_JSGT: u8 = kernel_sys::BPF_JSGT as u8;
pub const BPF_JSGE: u8 = kernel_sys::BPF_JSGE as u8;
pub const BPF_JSLT: u8 = kernel_sys::BPF_JSLT as u8;
pub const BPF_JSLE: u8 = kernel_sys::BPF_JSLE as u8;

pub const BPF_CALL: u8 = kernel_sys::BPF_CALL as u8;
pub const BPF_EXIT: u8 = kernel_sys::BPF_EXIT as u8;

// ── Pseudo source-register tags ────────────────────────────────────
pub const BPF_PSEUDO_MAP_FD: u8 = kernel_sys::BPF_PSEUDO_MAP_FD as u8;
pub const BPF_PSEUDO_MAP_VALUE: u8 = kernel_sys::BPF_PSEUDO_MAP_VALUE as u8;
pub const BPF_PSEUDO_CALL: u8 = kernel_sys::BPF_PSEUDO_CALL as u8;
#[cfg(test)]
pub const BPF_PSEUDO_KFUNC_CALL: u8 = kernel_sys::BPF_PSEUDO_KFUNC_CALL as u8;
pub const BPF_PSEUDO_KINSN_SIDECAR: u8 = 3;
/// LD_IMM64 local-function reference used for helper callbacks.
pub const BPF_PSEUDO_FUNC: u8 = kernel_sys::BPF_PSEUDO_FUNC as u8;
pub const BPF_PSEUDO_KINSN_CALL: u8 = 4;

// ── Registers ───────────────────────────────────────────────────────
pub const BPF_REG_0: u8 = kernel_sys::BPF_REG_0 as u8;
pub const BPF_REG_1: u8 = kernel_sys::BPF_REG_1 as u8;
pub const BPF_REG_2: u8 = kernel_sys::BPF_REG_2 as u8;
pub const BPF_REG_3: u8 = kernel_sys::BPF_REG_3 as u8;
pub const BPF_REG_4: u8 = kernel_sys::BPF_REG_4 as u8;
pub const BPF_REG_5: u8 = kernel_sys::BPF_REG_5 as u8;
pub const BPF_REG_6: u8 = kernel_sys::BPF_REG_6 as u8;
pub const BPF_REG_7: u8 = kernel_sys::BPF_REG_7 as u8;
pub const BPF_REG_8: u8 = kernel_sys::BPF_REG_8 as u8;
pub const BPF_REG_9: u8 = kernel_sys::BPF_REG_9 as u8;
pub const BPF_REG_10: u8 = kernel_sys::BPF_REG_10 as u8;

// ── kinsn encoding constants (synced with include/linux/bpf.h) ────
pub const BPF_KINSN_ENC_PACKED_CALL: u32 = 1 << 1;

// ── Helper macros (as functions) ────────────────────────────────────
#[inline]
pub const fn bpf_class(code: u8) -> u8 {
    code & 0x07
}

#[inline]
pub const fn bpf_size(code: u8) -> u8 {
    code & 0x18
}

#[inline]
pub const fn bpf_mode(code: u8) -> u8 {
    code & 0xe0
}

#[inline]
pub const fn bpf_op(code: u8) -> u8 {
    code & 0xf0
}

#[inline]
pub const fn bpf_src(code: u8) -> u8 {
    code & 0x08
}

// ── BpfInsn ─────────────────────────────────────────────────────────

/// A single BPF instruction, ABI-compatible with `struct bpf_insn` in the kernel.
#[repr(transparent)]
#[derive(Clone, Copy)]
pub struct BpfInsn(kernel_sys::bpf_insn);

// Ensure the transparent wrapper keeps the kernel ABI object size.
const _: () =
    assert!(std::mem::size_of::<BpfInsn>() == std::mem::size_of::<kernel_sys::bpf_insn>());

impl Deref for BpfInsn {
    type Target = kernel_sys::bpf_insn;

    #[inline]
    fn deref(&self) -> &Self::Target {
        &self.0
    }
}

impl DerefMut for BpfInsn {
    #[inline]
    fn deref_mut(&mut self) -> &mut Self::Target {
        &mut self.0
    }
}

impl PartialEq for BpfInsn {
    #[inline]
    fn eq(&self, other: &Self) -> bool {
        self.raw_bytes() == other.raw_bytes()
    }
}

impl Eq for BpfInsn {}

impl Hash for BpfInsn {
    #[inline]
    fn hash<H: Hasher>(&self, state: &mut H) {
        self.raw_bytes().hash(state);
    }
}

impl BpfInsn {
    // ── Field accessors ─────────────────────────────────────────────

    #[inline]
    pub fn new(code: u8, regs: u8, off: i16, imm: i32) -> Self {
        Self::new_raw(code, regs, off, imm)
    }

    #[inline]
    pub fn new_raw(code: u8, regs: u8, off: i16, imm: i32) -> Self {
        let mut inner = kernel_sys::bpf_insn {
            code,
            _bitfield_align_1: [],
            _bitfield_1: Default::default(),
            off,
            imm,
        };
        inner.set_dst_reg(regs & 0xf);
        inner.set_src_reg((regs >> 4) & 0xf);
        Self(inner)
    }

    #[inline]
    pub fn from_kernel(insn: kernel_sys::bpf_insn) -> Self {
        Self(insn)
    }

    #[inline]
    pub fn as_kernel(&self) -> &kernel_sys::bpf_insn {
        &self.0
    }

    #[inline]
    pub fn as_kernel_mut(&mut self) -> &mut kernel_sys::bpf_insn {
        &mut self.0
    }

    #[inline]
    pub fn into_kernel(self) -> kernel_sys::bpf_insn {
        self.0
    }

    #[inline]
    pub fn code(&self) -> u8 {
        self.code
    }

    #[inline]
    pub fn set_code(&mut self, code: u8) {
        self.code = code;
    }

    #[inline]
    pub fn regs(&self) -> u8 {
        Self::make_regs(self.dst_reg(), self.src_reg())
    }

    #[inline]
    pub fn set_regs(&mut self, regs: u8) {
        self.set_dst_reg(regs & 0xf);
        self.set_src_reg((regs >> 4) & 0xf);
    }

    #[inline]
    pub fn dst_reg(&self) -> u8 {
        kernel_sys::bpf_insn::dst_reg(&self.0)
    }

    #[inline]
    pub fn set_dst_reg(&mut self, dst: u8) {
        self.0.set_dst_reg(dst & 0xf);
    }

    #[inline]
    pub fn src_reg(&self) -> u8 {
        kernel_sys::bpf_insn::src_reg(&self.0)
    }

    #[inline]
    pub fn set_src_reg(&mut self, src: u8) {
        self.0.set_src_reg(src & 0xf);
    }

    #[inline]
    pub fn off(&self) -> i16 {
        self.off
    }

    #[inline]
    pub fn set_off(&mut self, off: i16) {
        self.off = off;
    }

    #[inline]
    pub fn imm(&self) -> i32 {
        self.imm
    }

    #[inline]
    pub fn set_imm(&mut self, imm: i32) {
        self.imm = imm;
    }

    #[inline]
    pub const fn make_regs(dst: u8, src: u8) -> u8 {
        (dst & 0xf) | ((src & 0xf) << 4)
    }

    #[inline]
    pub fn raw_bytes(&self) -> [u8; 8] {
        let mut bytes = [0u8; 8];
        bytes[0] = self.code;
        bytes[1] = self.regs();
        bytes[2..4].copy_from_slice(&self.off.to_le_bytes());
        bytes[4..8].copy_from_slice(&self.imm.to_le_bytes());
        bytes
    }

    #[inline]
    pub fn from_raw_bytes(bytes: [u8; 8]) -> Self {
        Self::new_raw(
            bytes[0],
            bytes[1],
            i16::from_le_bytes([bytes[2], bytes[3]]),
            i32::from_le_bytes([bytes[4], bytes[5], bytes[6], bytes[7]]),
        )
    }

    // ── Classification helpers ──────────────────────────────────────

    #[inline]
    pub fn class(&self) -> u8 {
        bpf_class(self.code)
    }

    /// True for JMP or JMP32 class (includes BPF_CALL, BPF_EXIT, BPF_JA).
    #[inline]
    pub fn is_jmp_class(&self) -> bool {
        let c = self.class();
        c == BPF_JMP || c == BPF_JMP32
    }

    /// True for conditional jump instructions (not JA/CALL/EXIT).
    #[inline]
    pub fn is_cond_jmp(&self) -> bool {
        if !self.is_jmp_class() {
            return false;
        }
        let op = bpf_op(self.code);
        op != BPF_JA && op != BPF_CALL && op != BPF_EXIT
    }

    /// True for BPF_JA (unconditional jump).
    #[inline]
    pub fn is_ja(&self) -> bool {
        self.is_jmp_class() && bpf_op(self.code) == BPF_JA && self.code != (BPF_JMP | BPF_CALL)
    }

    /// True for BPF_CALL.
    #[inline]
    pub fn is_call(&self) -> bool {
        self.code == (BPF_JMP | BPF_CALL)
    }

    /// True for BPF_EXIT.
    #[inline]
    pub fn is_exit(&self) -> bool {
        self.code == (BPF_JMP | BPF_EXIT)
    }

    /// True for LD_IMM64 (two-slot instruction).
    #[inline]
    pub fn is_ldimm64(&self) -> bool {
        self.code == (BPF_LD | BPF_DW | BPF_IMM)
    }

    /// True for `LD_IMM64 dst, pseudo_func` callback references.
    #[inline]
    pub fn is_ldimm64_pseudo_func(&self) -> bool {
        self.is_ldimm64() && self.src_reg() == BPF_PSEUDO_FUNC
    }

    /// True for LDX_MEM of any size.
    #[inline]
    pub fn is_ldx_mem(&self) -> bool {
        bpf_class(self.code) == BPF_LDX && bpf_mode(self.code) == BPF_MEM
    }

    // ── Constructors ────────────────────────────────────────────────

    /// `mov64 dst, src` (register)
    pub fn mov64_reg(dst: u8, src: u8) -> Self {
        Self::new(BPF_ALU64 | BPF_MOV | BPF_X, Self::make_regs(dst, src), 0, 0)
    }

    /// `mov64 dst, imm`
    #[cfg_attr(not(test), allow(dead_code))]
    pub fn mov64_imm(dst: u8, imm: i32) -> Self {
        Self::new(BPF_ALU64 | BPF_MOV | BPF_K, Self::make_regs(dst, 0), 0, imm)
    }

    /// `mov32 dst, imm`
    #[cfg_attr(not(test), allow(dead_code))]
    pub fn mov32_imm(dst: u8, imm: i32) -> Self {
        Self::new(BPF_ALU | BPF_MOV | BPF_K, Self::make_regs(dst, 0), 0, imm)
    }

    /// `call kfunc` (src_reg = BPF_PSEUDO_KFUNC_CALL = 2)
    ///
    /// `off = 0` means vmlinux BTF. For module kfuncs, `off` is the 1-based
    /// slot in the load/REJIT `fd_array`.
    #[cfg(test)]
    pub fn call_kfunc_with_off(btf_id: i32, off: i16) -> Self {
        Self::new(
            BPF_JMP | BPF_CALL,
            Self::make_regs(0, BPF_PSEUDO_KFUNC_CALL),
            off,
            btf_id,
        )
    }

    /// `call kfunc` against vmlinux BTF.
    #[cfg(test)]
    pub fn call_kfunc(btf_id: i32) -> Self {
        Self::call_kfunc_with_off(btf_id, 0)
    }

    /// `call kinsn` (src_reg = BPF_PSEUDO_KINSN_CALL = 4)
    ///
    /// `imm` is the BTF FUNC id of the exported kinsn stub.
    /// `off` is the 1-based slot in the load/REJIT `fd_array` when module BTF
    /// is used, or 0 for vmlinux.
    pub fn call_kinsn_with_off(btf_id: i32, off: i16) -> Self {
        Self::new(
            BPF_JMP | BPF_CALL,
            Self::make_regs(0, BPF_PSEUDO_KINSN_CALL),
            off,
            btf_id,
        )
    }

    /// `ja +off` (unconditional jump, NOP when off=0)
    pub fn ja(off: i16) -> Self {
        Self::new(BPF_JMP | BPF_JA, 0, off, 0)
    }

    /// `ldx_mem size, dst, [src + off]`
    pub fn ldx_mem(size: u8, dst: u8, src: u8, off: i16) -> Self {
        Self::new(BPF_LDX | size | BPF_MEM, Self::make_regs(dst, src), off, 0)
    }

    /// kinsn sidecar metadata for the immediately following kinsn call.
    ///
    /// Payload layout matches `bpf_kinsn_sidecar_payload()` in the kernel:
    /// bits [3:0]   = dst_reg field
    /// bits [19:4]  = off field
    /// bits [51:20] = imm field
    pub fn kinsn_sidecar(payload: u64) -> Self {
        Self::new(
            BPF_ALU64 | BPF_MOV | BPF_K,
            Self::make_regs((payload & 0xf) as u8, BPF_PSEUDO_KINSN_SIDECAR),
            ((payload >> 4) & 0xffff) as u16 as i16,
            ((payload >> 20) & 0xffff_ffff) as u32 as i32,
        )
    }

    /// `stx_mem size, [dst + off], src`
    #[allow(dead_code)]
    pub fn stx_mem(size: u8, dst: u8, src: u8, off: i16) -> Self {
        Self::new(BPF_STX | size | BPF_MEM, Self::make_regs(dst, src), off, 0)
    }

    /// `alu64 op, dst, imm`  (e.g., LSH64_IMM, OR64_IMM)
    #[allow(dead_code)]
    pub fn alu64_imm(op: u8, dst: u8, imm: i32) -> Self {
        Self::new(BPF_ALU64 | op | BPF_K, Self::make_regs(dst, 0), 0, imm)
    }

    /// `alu64 op, dst, src` (e.g., OR64_REG)
    #[allow(dead_code)]
    pub fn alu64_reg(op: u8, dst: u8, src: u8) -> Self {
        Self::new(BPF_ALU64 | op | BPF_X, Self::make_regs(dst, src), 0, 0)
    }

    /// NOP — encoded as `ja +0`.
    #[cfg_attr(not(test), allow(dead_code))]
    pub fn nop() -> Self {
        Self::ja(0)
    }

    #[inline]
    #[cfg(test)]
    pub fn is_kinsn_sidecar(&self) -> bool {
        self.code == (BPF_ALU64 | BPF_MOV | BPF_K) && self.src_reg() == BPF_PSEUDO_KINSN_SIDECAR
    }
}

#[derive(Clone, Debug, PartialEq, Eq, Serialize)]
pub struct BpfInsnDump {
    pub pc: usize,
    pub raw_hex: String,
    pub code: u8,
    pub regs: u8,
    pub dst_reg: u8,
    pub src_reg: u8,
    pub off: i16,
    pub imm: i32,
}

#[derive(Clone, Debug, PartialEq, Eq, Serialize)]
pub struct BpfBytecodeDump {
    pub insn_count: usize,
    #[serde(skip_serializing_if = "Vec::is_empty", default)]
    pub insns: Vec<BpfInsnDump>,
    /// Compact representation: all instruction bytes as a single hex string.
    /// Used when full per-instruction dumps are too large.
    #[serde(skip_serializing_if = "Option::is_none")]
    pub raw_hex_blob: Option<String>,
}

#[cfg_attr(not(test), allow(dead_code))]
fn hex_bytes(bytes: &[u8]) -> String {
    let mut out = String::with_capacity(bytes.len().saturating_mul(3).saturating_sub(1));
    for (idx, byte) in bytes.iter().enumerate() {
        if idx > 0 {
            out.push(' ');
        }
        use std::fmt::Write as _;
        let _ = write!(out, "{:02x}", byte);
    }
    out
}

#[cfg_attr(not(test), allow(dead_code))]
pub fn dump_bytecode(insns: &[BpfInsn]) -> BpfBytecodeDump {
    BpfBytecodeDump {
        insn_count: insns.len(),
        insns: insns
            .iter()
            .enumerate()
            .map(|(pc, insn)| {
                let raw = insn.raw_bytes();
                BpfInsnDump {
                    pc,
                    raw_hex: hex_bytes(&raw),
                    code: insn.code,
                    regs: insn.regs(),
                    dst_reg: insn.dst_reg(),
                    src_reg: insn.src_reg(),
                    off: insn.off,
                    imm: insn.imm,
                }
            })
            .collect(),
        raw_hex_blob: None,
    }
}

/// Compact bytecode dump — only insn_count + raw hex blob.
/// Used in socket responses to keep JSON size manageable.
pub fn dump_bytecode_compact(insns: &[BpfInsn]) -> BpfBytecodeDump {
    let mut blob = String::with_capacity(insns.len() * 16);
    for insn in insns {
        let raw = insn.raw_bytes();
        for byte in &raw {
            use std::fmt::Write as _;
            let _ = write!(blob, "{:02x}", byte);
        }
    }
    BpfBytecodeDump {
        insn_count: insns.len(),
        insns: Vec::new(),
        raw_hex_blob: Some(blob),
    }
}

impl fmt::Debug for BpfInsn {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(
            f,
            "BpfInsn {{ code: {:#04x}, dst: {}, src: {}, off: {}, imm: {} }}",
            self.code,
            self.dst_reg(),
            self.src_reg(),
            self.off,
            self.imm
        )
    }
}

impl fmt::Display for BpfInsn {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        fmt::Debug::fmt(self, f)
    }
}

// ── Test helpers (available to all test modules) ────────────────────

/// Load BPF instructions from a .bpf.o ELF file by parsing the ELF header
/// and extracting the first executable PROGBITS section (typically "xdp", "tc",
/// or "cgroup_skb"). Returns None if the file doesn't exist or isn't a valid
/// BPF ELF.
///
/// This is available to all `#[cfg(test)]` modules in the crate for testing
/// with real compiled BPF programs.
#[cfg(test)]
pub fn load_bpf_insns_from_elf(path: &str) -> Option<Vec<BpfInsn>> {
    crate::elf_parser::parse_bpf_object(path)
        .ok()?
        .first_program()
        .map(|program| program.insns.clone())
}

/// Return the path to a micro benchmark .bpf.o file relative to the daemon crate.
/// Returns the absolute path. Tests should check if the file exists before using it.
#[cfg(test)]
pub fn micro_program_path(filename: &str) -> String {
    format!(
        "{}/../micro/programs/{}",
        env!("CARGO_MANIFEST_DIR"),
        filename
    )
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn bpf_insn_abi_offsets_and_raw_bytes_match_uapi() {
        assert_eq!(std::mem::offset_of!(kernel_sys::bpf_insn, code), 0);
        assert_eq!(std::mem::offset_of!(kernel_sys::bpf_insn, off), 2);
        assert_eq!(std::mem::offset_of!(kernel_sys::bpf_insn, imm), 4);

        let insn = BpfInsn::new(0xbf, BpfInsn::make_regs(3, 5), -2, 0x1234_5678);
        assert_eq!(
            &insn as *const BpfInsn as usize,
            insn.as_kernel() as *const kernel_sys::bpf_insn as usize
        );
        assert_eq!(
            insn.raw_bytes(),
            [0xbf, 0x53, 0xfe, 0xff, 0x78, 0x56, 0x34, 0x12]
        );
        assert_eq!(BpfInsn::from_raw_bytes(insn.raw_bytes()), insn);
    }

    #[test]
    fn test_bpf_insn_encoding() {
        // mov64_reg r1, r2
        let insn = BpfInsn::mov64_reg(1, 2);
        assert_eq!(insn.code, BPF_ALU64 | BPF_MOV | BPF_X);
        assert_eq!(insn.dst_reg(), 1);
        assert_eq!(insn.src_reg(), 2);
        assert_eq!(insn.off, 0);
        assert_eq!(insn.imm, 0);

        // mov64_imm r3, 42
        let insn = BpfInsn::mov64_imm(3, 42);
        assert_eq!(insn.code, BPF_ALU64 | BPF_MOV | BPF_K);
        assert_eq!(insn.dst_reg(), 3);
        assert_eq!(insn.src_reg(), 0);
        assert_eq!(insn.imm, 42);

        // mov32_imm r4, -1
        let insn = BpfInsn::mov32_imm(4, -1);
        assert_eq!(insn.code, BPF_ALU | BPF_MOV | BPF_K);
        assert_eq!(insn.dst_reg(), 4);
        assert_eq!(insn.src_reg(), 0);
        assert_eq!(insn.imm, -1);

        // ldx_mem(W, r0, r6, 4)
        let insn = BpfInsn::ldx_mem(BPF_W, 0, 6, 4);
        assert_eq!(insn.code, BPF_LDX | BPF_W | BPF_MEM);
        assert_eq!(insn.dst_reg(), 0);
        assert_eq!(insn.src_reg(), 6);
        assert_eq!(insn.off, 4);
        assert!(insn.is_ldx_mem());

        // ldx_mem(B, r1, r6, 0) — byte load
        let insn = BpfInsn::ldx_mem(BPF_B, 1, 6, 0);
        assert_eq!(bpf_size(insn.code), BPF_B);
        assert!(insn.is_ldx_mem());

        // ja +10
        let insn = BpfInsn::ja(10);
        assert!(insn.is_ja());
        assert!(!insn.is_call());
        assert!(!insn.is_exit());
        assert!(insn.is_jmp_class());

        // call kfunc
        let insn = BpfInsn::call_kfunc(123);
        assert!(insn.is_call());
        assert!(!insn.is_ja());
        assert_eq!(insn.imm, 123);
        assert_eq!(insn.src_reg(), 2);

        // nop
        let insn = BpfInsn::nop();
        assert!(insn.is_ja());
        assert_eq!(insn.off, 0);

        // alu64_imm(LSH, r1, 8)
        let insn = BpfInsn::alu64_imm(BPF_LSH, 1, 8);
        assert_eq!(insn.code, BPF_ALU64 | BPF_LSH | BPF_K);
        assert_eq!(insn.dst_reg(), 1);
        assert_eq!(insn.imm, 8);

        // alu64_reg(OR, r0, r1)
        let insn = BpfInsn::alu64_reg(BPF_OR, 0, 1);
        assert_eq!(insn.code, BPF_ALU64 | BPF_OR | BPF_X);
        assert_eq!(insn.dst_reg(), 0);
        assert_eq!(insn.src_reg(), 1);

        // exit
        let insn = BpfInsn::new(BPF_JMP | BPF_EXIT, 0, 0, 0);
        assert!(insn.is_exit());
        assert!(!insn.is_call());

        // is_ldimm64
        let insn = BpfInsn::new(BPF_LD | BPF_DW | BPF_IMM, 0, 0, 0);
        assert!(insn.is_ldimm64());
    }

    #[test]
    fn test_make_regs_roundtrip() {
        for dst in 0..=15 {
            for src in 0..=15 {
                let regs = BpfInsn::make_regs(dst, src);
                let insn = BpfInsn::new(0, regs, 0, 0);
                assert_eq!(insn.dst_reg(), dst & 0xf);
                assert_eq!(insn.src_reg(), src & 0xf);
            }
        }
    }

    #[test]
    fn test_cond_jmp_classification() {
        // JEQ_IMM
        let insn = BpfInsn::new(BPF_JMP | BPF_JEQ | BPF_K, BpfInsn::make_regs(1, 0), 5, 42);
        assert!(insn.is_cond_jmp());
        assert!(insn.is_jmp_class());
        assert!(!insn.is_ja());
        assert!(!insn.is_call());

        // JMP32 JNE_REG
        let insn = BpfInsn::new(BPF_JMP32 | BPF_JNE | BPF_X, BpfInsn::make_regs(2, 3), 3, 0);
        assert!(insn.is_cond_jmp());
        assert!(insn.is_jmp_class());
    }

    #[test]
    fn test_dump_bytecode_formats_full_insn_dump() {
        let dump = dump_bytecode(&[BpfInsn::mov64_imm(3, 42), BpfInsn::ja(5)]);

        assert_eq!(dump.insn_count, 2);
        assert_eq!(dump.insns[0].pc, 0);
        assert_eq!(dump.insns[0].raw_hex, "b7 03 00 00 2a 00 00 00");
        assert_eq!(dump.insns[0].code, BPF_ALU64 | BPF_MOV | BPF_K);
        assert_eq!(dump.insns[0].regs, BpfInsn::make_regs(3, 0));
        assert_eq!(dump.insns[0].dst_reg, 3);
        assert_eq!(dump.insns[0].src_reg, 0);
        assert_eq!(dump.insns[0].off, 0);
        assert_eq!(dump.insns[0].imm, 42);

        assert_eq!(dump.insns[1].pc, 1);
        assert_eq!(dump.insns[1].raw_hex, "05 00 05 00 00 00 00 00");
        assert_eq!(dump.insns[1].off, 5);
    }
}
