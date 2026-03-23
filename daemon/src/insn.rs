// SPDX-License-Identifier: MIT
//! BPF instruction encoding, decoding, and constructors.

use std::fmt;

use serde::Serialize;

// ── Instruction classes ──────────────────────────────────────────────
pub const BPF_LD: u8 = 0x00;
pub const BPF_LDX: u8 = 0x01;
pub const BPF_ST: u8 = 0x02;
pub const BPF_STX: u8 = 0x03;
pub const BPF_ALU: u8 = 0x04;
pub const BPF_JMP: u8 = 0x05;
pub const BPF_JMP32: u8 = 0x06;
pub const BPF_ALU64: u8 = 0x07;

// ── Size modifiers ───────────────────────────────────────────────────
pub const BPF_W: u8 = 0x00; // 32-bit
pub const BPF_H: u8 = 0x08; // 16-bit
pub const BPF_B: u8 = 0x10; //  8-bit
pub const BPF_DW: u8 = 0x18; // 64-bit

// ── Mode modifiers ───────────────────────────────────────────────────
pub const BPF_IMM: u8 = 0x00;
pub const BPF_MEM: u8 = 0x60;

// ── ALU/JMP operations ──────────────────────────────────────────────
pub const BPF_AND: u8 = 0x50;
pub const BPF_OR: u8 = 0x40;
pub const BPF_LSH: u8 = 0x60;
pub const BPF_RSH: u8 = 0x70;
pub const BPF_MOV: u8 = 0xb0;

// ── Source modifiers ────────────────────────────────────────────────
pub const BPF_K: u8 = 0x00;
pub const BPF_X: u8 = 0x08;

// ── JMP opcodes ─────────────────────────────────────────────────────
pub const BPF_JA: u8 = 0x00;
pub const BPF_JEQ: u8 = 0x10;
pub const BPF_JGT: u8 = 0x20;
pub const BPF_JGE: u8 = 0x30;
pub const BPF_JSET: u8 = 0x40;
pub const BPF_JNE: u8 = 0x50;
pub const BPF_JLT: u8 = 0xa0;
pub const BPF_JLE: u8 = 0xb0;
pub const BPF_JSGT: u8 = 0x60;
pub const BPF_JSGE: u8 = 0x70;
pub const BPF_JSLT: u8 = 0xc0;
pub const BPF_JSLE: u8 = 0xd0;

pub const BPF_CALL: u8 = 0x80;
pub const BPF_EXIT: u8 = 0x90;

// ── Pseudo source-register tags ────────────────────────────────────
pub const BPF_PSEUDO_KFUNC_CALL: u8 = 2;
pub const BPF_PSEUDO_KINSN_SIDECAR: u8 = 3;

// ── kinsn encoding constants (synced with include/linux/bpf.h) ────
pub const BPF_KINSN_ENC_PACKED_CALL: u32 = 1 << 1;
#[allow(dead_code)]
pub const BPF_KINSN_SIDECAR_PAYLOAD_BITS: u32 = 52;

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
#[repr(C)]
#[derive(Clone, Copy, PartialEq, Eq)]
pub struct BpfInsn {
    pub code: u8,
    pub regs: u8, // dst_reg:4 | src_reg:4
    pub off: i16,
    pub imm: i32,
}

// Ensure the struct is 8 bytes, matching kernel ABI.
const _: () = assert!(std::mem::size_of::<BpfInsn>() == 8);

impl BpfInsn {
    // ── Field accessors ─────────────────────────────────────────────

    #[inline]
    pub const fn dst_reg(&self) -> u8 {
        self.regs & 0xf
    }

    #[inline]
    pub const fn src_reg(&self) -> u8 {
        (self.regs >> 4) & 0xf
    }

    #[inline]
    pub const fn make_regs(dst: u8, src: u8) -> u8 {
        (dst & 0xf) | ((src & 0xf) << 4)
    }

    #[inline]
    pub fn raw_bytes(&self) -> [u8; 8] {
        let mut bytes = [0u8; 8];
        bytes[0] = self.code;
        bytes[1] = self.regs;
        bytes[2..4].copy_from_slice(&self.off.to_le_bytes());
        bytes[4..8].copy_from_slice(&self.imm.to_le_bytes());
        bytes
    }

    // ── Classification helpers ──────────────────────────────────────

    #[inline]
    pub const fn class(&self) -> u8 {
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

    /// True for LDX_MEM of any size.
    #[inline]
    pub fn is_ldx_mem(&self) -> bool {
        bpf_class(self.code) == BPF_LDX && bpf_mode(self.code) == BPF_MEM
    }

    // ── Constructors ────────────────────────────────────────────────

    /// `mov64 dst, src` (register)
    pub const fn mov64_reg(dst: u8, src: u8) -> Self {
        Self {
            code: BPF_ALU64 | BPF_MOV | BPF_X,
            regs: Self::make_regs(dst, src),
            off: 0,
            imm: 0,
        }
    }

    /// `mov64 dst, imm`
    #[cfg_attr(not(test), allow(dead_code))]
    pub const fn mov64_imm(dst: u8, imm: i32) -> Self {
        Self {
            code: BPF_ALU64 | BPF_MOV | BPF_K,
            regs: Self::make_regs(dst, 0),
            off: 0,
            imm,
        }
    }

    /// `call kfunc` (src_reg = BPF_PSEUDO_KFUNC_CALL = 2)
    ///
    /// `off = 0` means vmlinux BTF. For module kfuncs, `off` is the 1-based
    /// slot in the load/REJIT `fd_array`.
    pub const fn call_kfunc_with_off(btf_id: i32, off: i16) -> Self {
        Self {
            code: BPF_JMP | BPF_CALL,
            regs: Self::make_regs(0, BPF_PSEUDO_KFUNC_CALL),
            off,
            imm: btf_id,
        }
    }

    /// `call kfunc` against vmlinux BTF.
    pub const fn call_kfunc(btf_id: i32) -> Self {
        Self::call_kfunc_with_off(btf_id, 0)
    }

    /// `ja +off` (unconditional jump, NOP when off=0)
    pub const fn ja(off: i16) -> Self {
        Self {
            code: BPF_JMP | BPF_JA,
            regs: 0,
            off,
            imm: 0,
        }
    }

    /// `ldx_mem size, dst, [src + off]`
    pub const fn ldx_mem(size: u8, dst: u8, src: u8, off: i16) -> Self {
        Self {
            code: BPF_LDX | size | BPF_MEM,
            regs: Self::make_regs(dst, src),
            off,
            imm: 0,
        }
    }

    /// kinsn sidecar metadata for the immediately following kfunc call.
    ///
    /// Payload layout matches `bpf_kinsn_sidecar_payload()` in the kernel:
    /// bits [3:0]   = dst_reg field
    /// bits [19:4]  = off field
    /// bits [51:20] = imm field
    pub const fn kinsn_sidecar(payload: u64) -> Self {
        Self {
            code: BPF_ALU64 | BPF_MOV | BPF_K,
            regs: Self::make_regs((payload & 0xf) as u8, BPF_PSEUDO_KINSN_SIDECAR),
            off: ((payload >> 4) & 0xffff) as u16 as i16,
            imm: ((payload >> 20) & 0xffff_ffff) as u32 as i32,
        }
    }

    /// `stx_mem size, [dst + off], src`
    #[allow(dead_code)]
    pub const fn stx_mem(size: u8, dst: u8, src: u8, off: i16) -> Self {
        Self {
            code: BPF_STX | size | BPF_MEM,
            regs: Self::make_regs(dst, src),
            off,
            imm: 0,
        }
    }

    /// `alu64 op, dst, imm`  (e.g., LSH64_IMM, OR64_IMM)
    #[allow(dead_code)]
    pub const fn alu64_imm(op: u8, dst: u8, imm: i32) -> Self {
        Self {
            code: BPF_ALU64 | op | BPF_K,
            regs: Self::make_regs(dst, 0),
            off: 0,
            imm,
        }
    }

    /// `alu64 op, dst, src` (e.g., OR64_REG)
    #[allow(dead_code)]
    pub const fn alu64_reg(op: u8, dst: u8, src: u8) -> Self {
        Self {
            code: BPF_ALU64 | op | BPF_X,
            regs: Self::make_regs(dst, src),
            off: 0,
            imm: 0,
        }
    }

    /// NOP — encoded as `ja +0`.
    #[cfg_attr(not(test), allow(dead_code))]
    pub const fn nop() -> Self {
        Self::ja(0)
    }

    #[inline]
    pub const fn is_kinsn_sidecar(&self) -> bool {
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
                    regs: insn.regs,
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
    let data = std::fs::read(path).ok()?;
    if data.len() < 64 || &data[..4] != b"\x7fELF" {
        return None;
    }
    // ELF64 little-endian
    if data[4] != 2 {
        return None;
    }

    let e_shoff = u64::from_le_bytes(data[40..48].try_into().ok()?) as usize;
    let e_shentsize = u16::from_le_bytes(data[58..60].try_into().ok()?) as usize;
    let e_shnum = u16::from_le_bytes(data[60..62].try_into().ok()?) as usize;
    let e_shstrndx = u16::from_le_bytes(data[62..64].try_into().ok()?) as usize;

    // Section header string table
    let shstr_off = e_shoff + e_shstrndx * e_shentsize;
    let shstr_sh_offset =
        u64::from_le_bytes(data[shstr_off + 24..shstr_off + 32].try_into().ok()?) as usize;
    let shstr_sh_size =
        u64::from_le_bytes(data[shstr_off + 32..shstr_off + 40].try_into().ok()?) as usize;
    let shstrtab = &data[shstr_sh_offset..shstr_sh_offset + shstr_sh_size];

    // Find the first executable PROGBITS section with content
    for i in 0..e_shnum {
        let sh_off = e_shoff + i * e_shentsize;
        let sh_name_idx = u32::from_le_bytes(data[sh_off..sh_off + 4].try_into().ok()?) as usize;
        let sh_type = u32::from_le_bytes(data[sh_off + 4..sh_off + 8].try_into().ok()?);
        let sh_flags = u64::from_le_bytes(data[sh_off + 8..sh_off + 16].try_into().ok()?);
        let sh_offset =
            u64::from_le_bytes(data[sh_off + 24..sh_off + 32].try_into().ok()?) as usize;
        let sh_size = u64::from_le_bytes(data[sh_off + 32..sh_off + 40].try_into().ok()?) as usize;

        // SHT_PROGBITS(1) + SHF_EXECINSTR(0x4) + has content
        if sh_type == 1 && (sh_flags & 0x4) != 0 && sh_size >= 8 {
            // Verify section name is not .text (which is empty for BPF ELFs)
            let name_end = shstrtab[sh_name_idx..].iter().position(|&b| b == 0)?;
            let _name = std::str::from_utf8(&shstrtab[sh_name_idx..sh_name_idx + name_end]).ok()?;

            let insn_data = &data[sh_offset..sh_offset + sh_size];
            let n_insns = insn_data.len() / 8;
            let mut insns = Vec::with_capacity(n_insns);
            for j in 0..n_insns {
                let off = j * 8;
                let code = insn_data[off];
                let regs = insn_data[off + 1];
                let ioff = i16::from_le_bytes(insn_data[off + 2..off + 4].try_into().ok()?);
                let imm = i32::from_le_bytes(insn_data[off + 4..off + 8].try_into().ok()?);
                insns.push(BpfInsn {
                    code,
                    regs,
                    off: ioff,
                    imm,
                });
            }
            return Some(insns);
        }
    }
    None
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
        let insn = BpfInsn {
            code: BPF_JMP | BPF_EXIT,
            regs: 0,
            off: 0,
            imm: 0,
        };
        assert!(insn.is_exit());
        assert!(!insn.is_call());

        // is_ldimm64
        let insn = BpfInsn {
            code: BPF_LD | BPF_DW | BPF_IMM,
            regs: 0,
            off: 0,
            imm: 0,
        };
        assert!(insn.is_ldimm64());
    }

    #[test]
    fn test_struct_size() {
        assert_eq!(std::mem::size_of::<BpfInsn>(), 8);
    }

    #[test]
    fn test_make_regs_roundtrip() {
        for dst in 0..=15 {
            for src in 0..=15 {
                let regs = BpfInsn::make_regs(dst, src);
                let insn = BpfInsn {
                    code: 0,
                    regs,
                    off: 0,
                    imm: 0,
                };
                assert_eq!(insn.dst_reg(), dst & 0xf);
                assert_eq!(insn.src_reg(), src & 0xf);
            }
        }
    }

    #[test]
    fn test_cond_jmp_classification() {
        // JEQ_IMM
        let insn = BpfInsn {
            code: BPF_JMP | BPF_JEQ | BPF_K,
            regs: BpfInsn::make_regs(1, 0),
            off: 5,
            imm: 42,
        };
        assert!(insn.is_cond_jmp());
        assert!(insn.is_jmp_class());
        assert!(!insn.is_ja());
        assert!(!insn.is_call());

        // JMP32 JNE_REG
        let insn = BpfInsn {
            code: BPF_JMP32 | BPF_JNE | BPF_X,
            regs: BpfInsn::make_regs(2, 3),
            off: 3,
            imm: 0,
        };
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
