// SPDX-License-Identifier: MIT
//! BPF instruction encoding, decoding, and constructors.
use std::fmt;
use std::hash::{Hash, Hasher};
use std::ops::{Deref, DerefMut};
// ── Instruction classes ──────────────────────────────────────────────
pub const BPF_LD: u8 = libbpf_sys::BPF_LD as u8;
pub const BPF_LDX: u8 = libbpf_sys::BPF_LDX as u8;
pub const BPF_ST: u8 = libbpf_sys::BPF_ST as u8;
pub const BPF_STX: u8 = libbpf_sys::BPF_STX as u8;
pub const BPF_ALU: u8 = libbpf_sys::BPF_ALU as u8;
pub const BPF_JMP: u8 = libbpf_sys::BPF_JMP as u8;
pub const BPF_JMP32: u8 = libbpf_sys::BPF_JMP32 as u8;
pub const BPF_ALU64: u8 = libbpf_sys::BPF_ALU64 as u8;
// ── Size modifiers ───────────────────────────────────────────────────
pub const BPF_W: u8 = libbpf_sys::BPF_W as u8; // 32-bit
pub const BPF_H: u8 = libbpf_sys::BPF_H as u8; // 16-bit
pub const BPF_B: u8 = libbpf_sys::BPF_B as u8; //  8-bit
pub const BPF_DW: u8 = libbpf_sys::BPF_DW as u8; // 64-bit
                                                 // ── Mode modifiers ───────────────────────────────────────────────────
pub const BPF_IMM: u8 = libbpf_sys::BPF_IMM as u8;
pub const BPF_MEM: u8 = libbpf_sys::BPF_MEM as u8;
// ── ALU/JMP operations ──────────────────────────────────────────────
pub const BPF_ADD: u8 = libbpf_sys::BPF_ADD as u8;
pub const BPF_SUB: u8 = libbpf_sys::BPF_SUB as u8;
pub const BPF_MUL: u8 = libbpf_sys::BPF_MUL as u8;
pub const BPF_DIV: u8 = libbpf_sys::BPF_DIV as u8;
pub const BPF_OR: u8 = libbpf_sys::BPF_OR as u8;
pub const BPF_AND: u8 = libbpf_sys::BPF_AND as u8;
pub const BPF_LSH: u8 = libbpf_sys::BPF_LSH as u8;
pub const BPF_RSH: u8 = libbpf_sys::BPF_RSH as u8;
pub const BPF_NEG: u8 = libbpf_sys::BPF_NEG as u8;
pub const BPF_MOD: u8 = libbpf_sys::BPF_MOD as u8;
pub const BPF_XOR: u8 = libbpf_sys::BPF_XOR as u8;
pub const BPF_MOV: u8 = libbpf_sys::BPF_MOV as u8;
pub const BPF_ARSH: u8 = libbpf_sys::BPF_ARSH as u8;
pub const BPF_END: u8 = libbpf_sys::BPF_END as u8;
pub const BPF_TO_BE: u8 = libbpf_sys::BPF_TO_BE as u8;
// ── Source modifiers ────────────────────────────────────────────────
pub const BPF_K: u8 = libbpf_sys::BPF_K as u8;
pub const BPF_X: u8 = libbpf_sys::BPF_X as u8;
// ── JMP opcodes ─────────────────────────────────────────────────────
pub const BPF_JA: u8 = libbpf_sys::BPF_JA as u8;
pub const BPF_JEQ: u8 = libbpf_sys::BPF_JEQ as u8;
pub const BPF_JGT: u8 = libbpf_sys::BPF_JGT as u8;
pub const BPF_JGE: u8 = libbpf_sys::BPF_JGE as u8;
pub const BPF_JSET: u8 = libbpf_sys::BPF_JSET as u8;
pub const BPF_JNE: u8 = libbpf_sys::BPF_JNE as u8;
pub const BPF_JLT: u8 = libbpf_sys::BPF_JLT as u8;
pub const BPF_JLE: u8 = libbpf_sys::BPF_JLE as u8;
pub const BPF_JSGT: u8 = libbpf_sys::BPF_JSGT as u8;
pub const BPF_JSGE: u8 = libbpf_sys::BPF_JSGE as u8;
pub const BPF_JSLT: u8 = libbpf_sys::BPF_JSLT as u8;
pub const BPF_JSLE: u8 = libbpf_sys::BPF_JSLE as u8;
pub const BPF_CALL: u8 = libbpf_sys::BPF_CALL as u8;
pub const BPF_EXIT: u8 = libbpf_sys::BPF_EXIT as u8;
// ── Pseudo source-register tags ────────────────────────────────────
pub const BPF_PSEUDO_MAP_FD: u8 = libbpf_sys::BPF_PSEUDO_MAP_FD as u8;
pub const BPF_PSEUDO_MAP_VALUE: u8 = libbpf_sys::BPF_PSEUDO_MAP_VALUE as u8;
pub const BPF_PSEUDO_MAP_IDX: u8 = 5;
pub const BPF_PSEUDO_MAP_IDX_VALUE: u8 = 6;
pub const BPF_PSEUDO_CALL: u8 = libbpf_sys::BPF_PSEUDO_CALL as u8;
pub const BPF_PSEUDO_KINSN_SIDECAR: u8 = 3;
/// LD_IMM64 local-function reference used for helper callbacks.
pub const BPF_PSEUDO_FUNC: u8 = libbpf_sys::BPF_PSEUDO_FUNC as u8;
pub const BPF_PSEUDO_KINSN_CALL: u8 = 4;
// ── Registers ───────────────────────────────────────────────────────
pub const BPF_REG_0: u8 = libbpf_sys::BPF_REG_0 as u8;
pub const BPF_REG_1: u8 = libbpf_sys::BPF_REG_1 as u8;
pub const BPF_REG_2: u8 = libbpf_sys::BPF_REG_2 as u8;
pub const BPF_REG_3: u8 = libbpf_sys::BPF_REG_3 as u8;
pub const BPF_REG_4: u8 = libbpf_sys::BPF_REG_4 as u8;
pub const BPF_REG_5: u8 = libbpf_sys::BPF_REG_5 as u8;
pub const BPF_REG_6: u8 = libbpf_sys::BPF_REG_6 as u8;
pub const BPF_REG_7: u8 = libbpf_sys::BPF_REG_7 as u8;
pub const BPF_REG_8: u8 = libbpf_sys::BPF_REG_8 as u8;
pub const BPF_REG_9: u8 = libbpf_sys::BPF_REG_9 as u8;
pub const BPF_REG_10: u8 = libbpf_sys::BPF_REG_10 as u8;
// ── Program context ABI offsets ─────────────────────────────────────
pub const XDP_PACKET_DATA_OFFSET: i16 = 0;
pub const XDP_PACKET_DATA_END_OFFSET: i16 = 4;
pub const SKB_PACKET_DATA_OFFSET: i16 = 76;
pub const SKB_PACKET_DATA_END_OFFSET: i16 = 80;
/// Single source of truth for BPF memory-access widths.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum BpfMemWidth {
    B = 0,
    H = 1,
    W = 2,
    DW = 3,
}

impl BpfMemWidth {
    pub fn from_size_opcode(size: u8) -> Option<Self> {
        match size {
            BPF_B => Some(Self::B),
            BPF_H => Some(Self::H),
            BPF_W => Some(Self::W),
            BPF_DW => Some(Self::DW),
            _ => None,
        }
    }

    pub fn from_bytes(bytes: usize) -> Option<Self> {
        match bytes {
            1 => Some(Self::B),
            2 => Some(Self::H),
            4 => Some(Self::W),
            8 => Some(Self::DW),
            _ => None,
        }
    }

    pub fn bytes(self) -> usize {
        1usize << self as u8
    }

    pub fn bits(self) -> u32 {
        (self.bytes() as u32) * 8
    }

    pub fn size_opcode(self) -> u8 {
        match self {
            Self::B => BPF_B,
            Self::H => BPF_H,
            Self::W => BPF_W,
            Self::DW => BPF_DW,
        }
    }

    pub fn aarch64_shift(self) -> i16 {
        self as i16
    }
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub(crate) struct PacketCtxLayout {
    pub data_off: i16,
    pub data_end_off: i16,
}
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub(crate) enum PacketCtxLayoutScope {
    SkbHelper,
    PacketAccess,
}
pub(crate) fn packet_ctx_layout(
    prog_type: u32,
    scope: PacketCtxLayoutScope,
) -> Option<PacketCtxLayout> {
    match (scope, prog_type) {
        (PacketCtxLayoutScope::PacketAccess, libbpf_sys::BPF_PROG_TYPE_XDP) => {
            Some(PacketCtxLayout {
                data_off: XDP_PACKET_DATA_OFFSET,
                data_end_off: XDP_PACKET_DATA_END_OFFSET,
            })
        }
        (
            PacketCtxLayoutScope::PacketAccess,
            libbpf_sys::BPF_PROG_TYPE_SCHED_CLS
            | libbpf_sys::BPF_PROG_TYPE_SCHED_ACT
            | libbpf_sys::BPF_PROG_TYPE_SK_SKB
            | libbpf_sys::BPF_PROG_TYPE_LWT_IN
            | libbpf_sys::BPF_PROG_TYPE_LWT_OUT
            | libbpf_sys::BPF_PROG_TYPE_LWT_XMIT,
        )
        | (
            PacketCtxLayoutScope::SkbHelper,
            libbpf_sys::BPF_PROG_TYPE_SCHED_CLS | libbpf_sys::BPF_PROG_TYPE_SCHED_ACT,
        ) => Some(PacketCtxLayout {
            data_off: SKB_PACKET_DATA_OFFSET,
            data_end_off: SKB_PACKET_DATA_END_OFFSET,
        }),
        _ => None,
    }
}
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
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum MapPseudo {
    Fd,
    FdValue,
    Idx,
    IdxValue,
}
impl MapPseudo {
    pub fn from_src_reg(src_reg: u8) -> Option<Self> {
        match src_reg {
            BPF_PSEUDO_MAP_FD => Some(Self::Fd),
            BPF_PSEUDO_MAP_VALUE => Some(Self::FdValue),
            BPF_PSEUDO_MAP_IDX => Some(Self::Idx),
            BPF_PSEUDO_MAP_IDX_VALUE => Some(Self::IdxValue),
            _ => None,
        }
    }
    pub fn src_reg(self) -> u8 {
        match self {
            Self::Fd => BPF_PSEUDO_MAP_FD,
            Self::FdValue => BPF_PSEUDO_MAP_VALUE,
            Self::Idx => BPF_PSEUDO_MAP_IDX,
            Self::IdxValue => BPF_PSEUDO_MAP_IDX_VALUE,
        }
    }
    pub fn uses_index(self) -> bool {
        matches!(self, Self::Idx | Self::IdxValue)
    }
}
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum BranchOff {
    Off16(i16),
    Imm32(i32),
    None,
}
#[inline]
pub fn relative_branch_target_pc(pc: usize, delta: i64) -> Option<usize> {
    let target = pc as i128 + 1 + delta as i128;
    (0..=usize::MAX as i128)
        .contains(&target)
        .then_some(target as usize)
}
// ── BpfInsn ─────────────────────────────────────────────────────────
/// A single BPF instruction, ABI-compatible with `struct bpf_insn` in the kernel.
#[repr(transparent)]
#[derive(Clone, Copy)]
pub struct BpfInsn(libbpf_sys::bpf_insn);
// Ensure the transparent wrapper keeps the kernel ABI object size.
const _: () =
    assert!(std::mem::size_of::<BpfInsn>() == std::mem::size_of::<libbpf_sys::bpf_insn>());
impl Deref for BpfInsn {
    type Target = libbpf_sys::bpf_insn;
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
        let mut inner = libbpf_sys::bpf_insn {
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
    #[cfg(test)]
    #[inline]
    pub fn as_kernel(&self) -> &libbpf_sys::bpf_insn {
        &self.0
    }
    #[inline]
    pub fn dst_reg(&self) -> u8 {
        libbpf_sys::bpf_insn::dst_reg(&self.0)
    }
    #[inline]
    pub fn set_dst_reg(&mut self, dst: u8) {
        self.0.set_dst_reg(dst & 0xf);
    }
    #[inline]
    pub fn src_reg(&self) -> u8 {
        libbpf_sys::bpf_insn::src_reg(&self.0)
    }
    #[inline]
    pub fn set_src_reg(&mut self, src: u8) {
        self.0.set_src_reg(src & 0xf);
    }
    #[inline]
    pub const fn make_regs(dst: u8, src: u8) -> u8 {
        (dst & 0xf) | ((src & 0xf) << 4)
    }
    #[inline]
    pub fn raw_bytes(&self) -> [u8; 8] {
        let mut bytes = [0u8; 8];
        bytes[0] = self.code;
        bytes[1] = Self::make_regs(self.dst_reg(), self.src_reg());
        bytes[2..4].copy_from_slice(&self.off.to_le_bytes());
        bytes[4..8].copy_from_slice(&self.imm.to_le_bytes());
        bytes
    }
    #[inline]
    pub fn from_raw_bytes(bytes: [u8; 8]) -> Self {
        Self::new(
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
    #[inline]
    pub fn branch_target_offset(&self) -> Option<BranchOff> {
        if !self.is_jmp_class() {
            return None;
        }
        if self.is_call() || self.is_exit() {
            return Some(BranchOff::None);
        }
        if self.class() == BPF_JMP32 && bpf_op(self.code) == BPF_JA {
            Some(BranchOff::Imm32(self.imm))
        } else {
            Some(BranchOff::Off16(self.off))
        }
    }
    #[inline]
    pub fn branch_target_pc(&self, pc: usize) -> Option<usize> {
        let delta = match self.branch_target_offset()? {
            BranchOff::Off16(off) => i64::from(off),
            BranchOff::Imm32(imm) => i64::from(imm),
            BranchOff::None => return None,
        };
        relative_branch_target_pc(pc, delta)
    }
    pub fn set_branch_target_delta(&mut self, delta: i64) -> anyhow::Result<()> {
        match self.branch_target_offset() {
            Some(BranchOff::Off16(_)) => {
                self.off = i16::try_from(delta)
                    .map_err(|_| anyhow::anyhow!("branch offset {delta} exceeds i16"))?;
                Ok(())
            }
            Some(BranchOff::Imm32(_)) => {
                self.imm = i32::try_from(delta)
                    .map_err(|_| anyhow::anyhow!("JA32 offset {delta} exceeds i32"))?;
                Ok(())
            }
            Some(BranchOff::None) | None => {
                anyhow::bail!("instruction is not a pc-relative branch")
            }
        }
    }
    pub fn set_pc_relative_imm_delta(&mut self, delta: i64) -> anyhow::Result<()> {
        self.imm = i32::try_from(delta)
            .map_err(|_| anyhow::anyhow!("pc-relative imm offset {delta} exceeds i32"))?;
        Ok(())
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
    #[inline]
    pub fn map_pseudo(&self) -> Option<MapPseudo> {
        self.is_ldimm64()
            .then(|| MapPseudo::from_src_reg(self.src_reg()))
            .flatten()
    }
    /// True for LDX_MEM of any size.
    #[inline]
    pub fn is_ldx_mem(&self) -> bool {
        bpf_class(self.code) == BPF_LDX && bpf_mode(self.code) == BPF_MEM
    }
    #[inline]
    pub fn is_mov64_reg(&self) -> bool {
        self.code == (BPF_ALU64 | BPF_MOV | BPF_X)
    }
    // ── Constructors ────────────────────────────────────────────────
    /// `mov64 dst, src` (register)
    pub fn mov64_reg(dst: u8, src: u8) -> Self {
        Self::new(BPF_ALU64 | BPF_MOV | BPF_X, Self::make_regs(dst, src), 0, 0)
    }
    /// `mov32 dst, src` (register)
    pub fn mov32_reg(dst: u8, src: u8) -> Self {
        Self::new(BPF_ALU | BPF_MOV | BPF_X, Self::make_regs(dst, src), 0, 0)
    }
    /// `mov64 dst, imm`
    pub fn mov64_imm(dst: u8, imm: i32) -> Self {
        Self::new(BPF_ALU64 | BPF_MOV | BPF_K, Self::make_regs(dst, 0), 0, imm)
    }
    /// `mov32 dst, imm`
    pub fn mov32_imm(dst: u8, imm: i32) -> Self {
        Self::new(BPF_ALU | BPF_MOV | BPF_K, Self::make_regs(dst, 0), 0, imm)
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
    #[inline]
    pub fn is_call_kinsn(&self) -> bool {
        self.is_call() && self.src_reg() == BPF_PSEUDO_KINSN_CALL
    }
    /// `call pc-relative subprogram` (src_reg = BPF_PSEUDO_CALL). Test-only:
    /// production code constructs pseudo calls through the lifter, not this
    /// truncating `imm as i32` shortcut.
    #[cfg(test)]
    pub fn pseudo_call_to(call_pc: usize, target_pc: usize) -> Self {
        let imm = target_pc as i64 - (call_pc as i64 + 1);
        let regs = Self::make_regs(0, BPF_PSEUDO_CALL);
        Self::new(BPF_JMP | BPF_CALL, regs, 0, imm as i32)
    }
    /// `ja +off` (unconditional jump, NOP when off=0)
    pub fn ja(off: i16) -> Self {
        Self::new(BPF_JMP | BPF_JA, 0, off, 0)
    }
    /// `j<op> dst, imm, +off`
    pub fn jump_imm(op: u8, dst: u8, imm: i32, off: i16) -> Self {
        Self::new(BPF_JMP | op | BPF_K, Self::make_regs(dst, 0), off, imm)
    }
    pub fn jeq_imm(dst: u8, imm: i32, off: i16) -> Self {
        Self::jump_imm(BPF_JEQ, dst, imm, off)
    }
    /// `j<op> dst, src, +off`
    pub fn jump_reg(op: u8, dst: u8, src: u8, off: i16) -> Self {
        Self::new(BPF_JMP | op | BPF_X, Self::make_regs(dst, src), off, 0)
    }
    /// `exit`
    pub fn exit() -> Self {
        Self::new(BPF_JMP | BPF_EXIT, 0, 0, 0)
    }
    pub fn ld_imm64(dst: u8, src: u8, imm: i64) -> [Self; 2] {
        let regs = Self::make_regs(dst, src);
        [
            Self::new(BPF_LD | BPF_DW | BPF_IMM, regs, 0, imm as i32),
            Self::new(0, 0, 0, (imm >> 32) as i32),
        ]
    }
    /// `ldx_mem size, dst, [src + off]`
    pub fn ldx_mem(size: u8, dst: u8, src: u8, off: i16) -> Self {
        Self::new(BPF_LDX | size | BPF_MEM, Self::make_regs(dst, src), off, 0)
    }
    #[inline]
    pub const fn pack_u4(value: u8, shift: u8) -> u64 {
        ((value as u64) & 0xf) << shift
    }
    #[inline]
    pub const fn pack_u8(value: u8, shift: u8) -> u64 {
        (value as u64) << shift
    }
    #[inline]
    pub const fn pack_u16(value: u16, shift: u8) -> u64 {
        (value as u64) << shift
    }
    #[inline]
    pub const fn pack_u32(value: u32, shift: u8) -> u64 {
        (value as u64) << shift
    }
    #[inline]
    pub const fn unpack_u4(payload: u64, shift: u8) -> u8 {
        ((payload >> shift) & 0xf) as u8
    }
    #[inline]
    pub const fn unpack_u8(payload: u64, shift: u8) -> u8 {
        ((payload >> shift) & 0xff) as u8
    }
    #[inline]
    pub const fn unpack_u16(payload: u64, shift: u8) -> u16 {
        ((payload >> shift) & 0xffff) as u16
    }
    #[inline]
    pub const fn unpack_u32(payload: u64, shift: u8) -> u32 {
        ((payload >> shift) & 0xffff_ffff) as u32
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
            Self::make_regs(Self::unpack_u4(payload, 0), BPF_PSEUDO_KINSN_SIDECAR),
            Self::unpack_u16(payload, 4) as i16,
            Self::unpack_u32(payload, 20) as i32,
        )
    }
    pub fn sidecar_payload(&self) -> u64 {
        Self::pack_u4(self.dst_reg(), 0)
            | Self::pack_u16(self.off as u16, 4)
            | Self::pack_u32(self.imm as u32, 20)
    }
    /// `stx_mem size, [dst + off], src`
    pub fn stx_mem(size: u8, dst: u8, src: u8, off: i16) -> Self {
        Self::new(BPF_STX | size | BPF_MEM, Self::make_regs(dst, src), off, 0)
    }
    /// `alu64 op, dst, imm`  (e.g., LSH64_IMM, OR64_IMM)
    pub fn alu64_imm(op: u8, dst: u8, imm: i32) -> Self {
        Self::new(BPF_ALU64 | op | BPF_K, Self::make_regs(dst, 0), 0, imm)
    }
    #[cfg(test)]
    pub fn add64_imm(dst: u8, imm: i32) -> Self {
        Self::alu64_imm(BPF_ADD, dst, imm)
    }
    /// `alu64 op, dst, src` (e.g., OR64_REG)
    #[cfg(test)]
    pub fn alu64_reg(op: u8, dst: u8, src: u8) -> Self {
        Self::new(BPF_ALU64 | op | BPF_X, Self::make_regs(dst, src), 0, 0)
    }
    #[cfg(test)]
    pub fn alu32_imm(op: u8, dst: u8, imm: i32) -> Self {
        Self::new(BPF_ALU | op | BPF_K, Self::make_regs(dst, 0), 0, imm)
    }
    #[cfg(test)]
    pub fn alu32_reg(op: u8, dst: u8, src: u8) -> Self {
        Self::new(BPF_ALU | op | BPF_X, Self::make_regs(dst, src), 0, 0)
    }
    /// NOP — encoded as `ja +0`.
    pub fn nop() -> Self {
        Self::ja(0)
    }
    #[inline]
    pub fn is_kinsn_sidecar(&self) -> bool {
        self.code == (BPF_ALU64 | BPF_MOV | BPF_K) && self.src_reg() == BPF_PSEUDO_KINSN_SIDECAR
    }
    #[inline]
    pub fn is_alu_imm(&self, class: u8, op: u8) -> bool {
        matches!(class, BPF_ALU | BPF_ALU64)
            && bpf_class(self.code) == class
            && bpf_op(self.code) == op
            && bpf_src(self.code) == BPF_K
    }
    #[inline]
    pub fn is_alu_reg(&self, class: u8, op: u8) -> bool {
        matches!(class, BPF_ALU | BPF_ALU64)
            && bpf_class(self.code) == class
            && bpf_op(self.code) == op
            && bpf_src(self.code) == BPF_X
    }
    #[inline]
    pub fn is_ldx_mem_size(&self, size: u8) -> bool {
        self.is_ldx_mem() && bpf_size(self.code) == size
    }
}
/// Returns the instruction width in slots: 2 for LD_IMM64, 1 for all others.
pub fn insn_width(insn: &BpfInsn) -> usize {
    if insn.is_ldimm64() {
        2
    } else {
        1
    }
}
pub fn decode_ldimm64_value(lo: &BpfInsn, hi: &BpfInsn) -> u64 {
    (lo.imm as u32 as u64) | ((hi.imm as u32 as u64) << 32)
}
pub fn emit_scalar_const_load(dst_reg: u8, value: u64, is_32: bool) -> Vec<BpfInsn> {
    if is_32 {
        return vec![BpfInsn::mov32_imm(dst_reg, value as u32 as i32)];
    }
    let imm = value as i64 as i32;
    if (imm as i64) as u64 == value {
        vec![BpfInsn::mov64_imm(dst_reg, imm)]
    } else {
        vec![
            BpfInsn::new(
                BPF_LD | BPF_DW | BPF_IMM,
                BpfInsn::make_regs(dst_reg, 0),
                0,
                value as u32 as i32,
            ),
            BpfInsn::new(0, 0, 0, (value >> 32) as u32 as i32),
        ]
    }
}
/// Emit a packed-ABI kinsn call using a sidecar pseudo-insn immediately before
/// the kinsn CALL. The result register is part of `payload`, so no extra
/// `mov dst, r0` is emitted here.
pub fn emit_packed_kinsn_call_with_off(
    payload: u64,
    kinsn_btf_id: i32,
    kinsn_off: i16,
) -> Vec<BpfInsn> {
    vec![
        BpfInsn::kinsn_sidecar(payload),
        BpfInsn::call_kinsn_with_off(kinsn_btf_id, kinsn_off),
    ]
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
#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn bpf_insn_abi_offsets_and_raw_bytes_match_uapi() {
        assert_eq!(std::mem::offset_of!(libbpf_sys::bpf_insn, code), 0);
        assert_eq!(std::mem::offset_of!(libbpf_sys::bpf_insn, off), 2);
        assert_eq!(std::mem::offset_of!(libbpf_sys::bpf_insn, imm), 4);

        let insn = BpfInsn::new(0xbf, BpfInsn::make_regs(3, 5), -2, 0x1234_5678);
        assert_eq!(
            &insn as *const BpfInsn as usize,
            insn.as_kernel() as *const libbpf_sys::bpf_insn as usize
        );
        assert_eq!(
            insn.raw_bytes(),
            [0xbf, 0x53, 0xfe, 0xff, 0x78, 0x56, 0x34, 0x12]
        );
        assert_eq!(BpfInsn::from_raw_bytes(insn.raw_bytes()), insn);
    }

    #[test]
    fn test_cond_jmp_classification() {
        let insn = BpfInsn::new(BPF_JMP | BPF_JEQ | BPF_K, BpfInsn::make_regs(1, 0), 5, 42);
        assert!(insn.is_cond_jmp());
        assert!(insn.is_jmp_class());
        assert!(!insn.is_ja());
        assert!(!insn.is_call());

        let insn = BpfInsn::new(BPF_JMP32 | BPF_JNE | BPF_X, BpfInsn::make_regs(2, 3), 3, 0);
        assert!(insn.is_cond_jmp());
        assert!(insn.is_jmp_class());
    }

    #[test]
    fn test_emit_packed_kinsn_call_with_module_off() {
        let payload = 0x12345;
        let insns = emit_packed_kinsn_call_with_off(payload, 1234, 2);

        assert_eq!(insns.len(), 2);
        assert!(insns[0].is_kinsn_sidecar());
        assert_eq!(insns[0].dst_reg(), 0x5);
        assert_eq!(insns[0].off, 0x1234);
        assert_eq!(insns[0].imm, 0);
        assert!(insns[1].is_call());
        assert_eq!(insns[1].imm, 1234);
        assert_eq!(insns[1].off, 2);
    }

    #[test]
    fn test_emit_packed_kinsn_call_wide_payload() {
        let payload = 0xabcde12345;
        let insns = emit_packed_kinsn_call_with_off(payload, 5555, 0);

        assert_eq!(insns.len(), 2);
        assert!(insns[0].is_kinsn_sidecar());
        assert_eq!(insns[0].dst_reg(), 0x5);
        assert_eq!(insns[0].off, 0x1234);
        assert_eq!(insns[0].imm, 0xabcde);
        assert!(insns[1].is_call());
        assert_eq!(insns[1].imm, 5555);
    }
}
