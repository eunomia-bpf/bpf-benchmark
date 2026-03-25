// SPDX-License-Identifier: MIT
//! Scan helpers for dynamic map inlining.
#![cfg_attr(not(test), allow(dead_code))]

use crate::insn::*;

const BPF_ADD: u8 = 0x00;
const BPF_PSEUDO_MAP_FD: u8 = 1;
const HELPER_MAP_LOOKUP_ELEM: i32 = 1;

/// A `bpf_map_lookup_elem()` helper call and its map argument load.
#[derive(Clone, Debug, PartialEq, Eq)]
pub struct MapLookupSite {
    pub call_pc: usize,
    pub map_load_pc: usize,
}

/// Constant key materialized on the stack for a map lookup.
#[derive(Clone, Debug, PartialEq, Eq)]
pub struct ConstantKey {
    pub stack_off: i16,
    pub width: u8,
    pub value: u64,
    pub store_pc: usize,
    pub source_imm_pc: Option<usize>,
    pub r2_mov_pc: usize,
    pub r2_add_pc: usize,
}

/// A fixed-offset scalar load from the map value pointer returned in `r0`.
#[derive(Clone, Debug, PartialEq, Eq)]
pub struct FixedLoadUse {
    pub pc: usize,
    pub dst_reg: u8,
    pub size: u8,
    pub offset: i16,
}

/// Classification of all uses that consume the lookup result in `r0`.
#[derive(Clone, Debug, Default, PartialEq, Eq)]
pub struct R0UseClassification {
    pub fixed_loads: Vec<FixedLoadUse>,
    pub other_uses: Vec<usize>,
}

impl R0UseClassification {
    /// Returns whether every `r0` use is a fixed-offset scalar load.
    pub fn all_fixed_loads(&self) -> bool {
        self.other_uses.is_empty()
    }
}

/// Find all `bpf_map_lookup_elem()` call sites in the instruction stream.
pub fn find_map_lookup_sites(insns: &[BpfInsn]) -> Vec<MapLookupSite> {
    let mut sites = Vec::new();
    let mut pc = 0usize;

    while pc < insns.len() {
        let insn = &insns[pc];
        if insn.is_call() && insn.src_reg() == 0 && insn.imm == HELPER_MAP_LOOKUP_ELEM {
            if let Some(map_load_pc) = find_map_load_for_call(insns, pc) {
                sites.push(MapLookupSite {
                    call_pc: pc,
                    map_load_pc,
                });
            }
        }

        pc += insn_width(insn);
    }

    sites
}

/// Recover a stack-materialized constant key for a lookup helper call.
pub fn extract_constant_key(insns: &[BpfInsn], call_pc: usize) -> Option<ConstantKey> {
    let (r2_mov_pc, r2_add_pc, stack_off) = find_r2_stack_pointer_setup(insns, call_pc)?;
    let (store_pc, source_imm_pc, width, value) =
        find_constant_stack_store(insns, r2_mov_pc, stack_off)?;

    Some(ConstantKey {
        stack_off,
        width,
        value,
        store_pc,
        source_imm_pc,
        r2_mov_pc,
        r2_add_pc,
    })
}

/// Classify all uses of the lookup result in `r0` until `r0` is overwritten.
pub fn classify_r0_uses(insns: &[BpfInsn], call_pc: usize) -> R0UseClassification {
    let mut classification = R0UseClassification::default();
    let mut pc = call_pc + 1;

    while pc < insns.len() {
        let insn = &insns[pc];

        if insn.is_ldx_mem() && insn.src_reg() == 0 {
            classification.fixed_loads.push(FixedLoadUse {
                pc,
                dst_reg: insn.dst_reg(),
                size: bpf_size(insn.code),
                offset: insn.off,
            });
        } else if insn_uses_reg(insn, 0) {
            classification.other_uses.push(pc);
        }

        if insn_defines_reg(insn, 0) {
            break;
        }

        pc += insn_width(insn);
    }

    classification
}

fn find_map_load_for_call(insns: &[BpfInsn], call_pc: usize) -> Option<usize> {
    let mut cursor = call_pc;
    while let Some(pc) = prev_real_pc(insns, cursor) {
        let insn = &insns[pc];
        if insn_defines_reg(insn, 1) {
            return (insn.is_ldimm64()
                && insn.dst_reg() == 1
                && insn.src_reg() == BPF_PSEUDO_MAP_FD)
                .then_some(pc);
        }
        cursor = pc;
    }
    None
}

fn find_r2_stack_pointer_setup(insns: &[BpfInsn], call_pc: usize) -> Option<(usize, usize, i16)> {
    let r2_add_pc = prev_real_pc(insns, call_pc)?;
    let r2_mov_pc = prev_real_pc(insns, r2_add_pc)?;
    let add = &insns[r2_add_pc];
    let mov = &insns[r2_mov_pc];

    if mov.code != (BPF_ALU64 | BPF_MOV | BPF_X) || mov.dst_reg() != 2 || mov.src_reg() != 10 {
        return None;
    }
    if add.code != (BPF_ALU64 | BPF_ADD | BPF_K) || add.dst_reg() != 2 || add.imm >= 0 {
        return None;
    }

    Some((r2_mov_pc, r2_add_pc, add.imm as i16))
}

fn find_constant_stack_store(
    insns: &[BpfInsn],
    before_pc: usize,
    stack_off: i16,
) -> Option<(usize, Option<usize>, u8, u64)> {
    let mut cursor = before_pc;
    while let Some(pc) = prev_real_pc(insns, cursor) {
        let insn = &insns[pc];
        if !is_stack_store_at(insn, stack_off) {
            cursor = pc;
            continue;
        }

        let width = size_in_bytes(bpf_size(insn.code))?;
        if bpf_class(insn.code) == BPF_ST {
            return Some((pc, None, width, truncate_imm(insn.imm, width)));
        }

        if bpf_class(insn.code) == BPF_STX {
            let (source_imm_pc, value) = find_constant_reg_value(insns, pc, insn.src_reg())?;
            return Some((pc, Some(source_imm_pc), width, truncate_value(value, width)));
        }
        cursor = pc;
    }
    None
}

fn find_constant_reg_value(insns: &[BpfInsn], before_pc: usize, reg: u8) -> Option<(usize, u64)> {
    let mut cursor = before_pc;
    while let Some(pc) = prev_real_pc(insns, cursor) {
        let insn = &insns[pc];
        if insn_defines_reg(insn, reg) {
            let is_mov_imm = (insn.class() == BPF_ALU64 || insn.class() == BPF_ALU)
                && bpf_op(insn.code) == BPF_MOV
                && bpf_src(insn.code) == BPF_K
                && insn.dst_reg() == reg;
            if !is_mov_imm {
                return None;
            }
            return Some((pc, insn.imm as i64 as u64));
        }
        cursor = pc;
    }
    None
}

fn is_stack_store_at(insn: &BpfInsn, stack_off: i16) -> bool {
    matches!(bpf_class(insn.code), BPF_ST | BPF_STX)
        && bpf_mode(insn.code) == BPF_MEM
        && insn.dst_reg() == 10
        && insn.off == stack_off
}

fn size_in_bytes(size: u8) -> Option<u8> {
    match size {
        BPF_B => Some(1),
        BPF_H => Some(2),
        BPF_W => Some(4),
        BPF_DW => Some(8),
        _ => None,
    }
}

fn truncate_imm(imm: i32, width: u8) -> u64 {
    truncate_value(imm as i64 as u64, width)
}

fn truncate_value(value: u64, width: u8) -> u64 {
    match width {
        1 => value & 0xff,
        2 => value & 0xffff,
        4 => value & 0xffff_ffff,
        8 => value,
        _ => value,
    }
}

fn prev_real_pc(insns: &[BpfInsn], pc: usize) -> Option<usize> {
    if pc == 0 {
        return None;
    }

    let mut cursor = 0usize;
    let mut prev = None;
    while cursor < pc {
        prev = Some(cursor);
        cursor += insn_width(&insns[cursor]);
    }
    if cursor == pc {
        prev
    } else {
        None
    }
}

fn insn_width(insn: &BpfInsn) -> usize {
    if insn.is_ldimm64() {
        2
    } else {
        1
    }
}

fn insn_uses_reg(insn: &BpfInsn, reg: u8) -> bool {
    match insn.class() {
        BPF_ALU64 | BPF_ALU => {
            if bpf_op(insn.code) == BPF_MOV {
                (bpf_src(insn.code) == BPF_X && insn.src_reg() == reg)
                    || (bpf_src(insn.code) != BPF_X && false)
            } else {
                insn.dst_reg() == reg || (bpf_src(insn.code) == BPF_X && insn.src_reg() == reg)
            }
        }
        BPF_LDX => insn.src_reg() == reg,
        BPF_ST => insn.dst_reg() == reg,
        BPF_STX => insn.dst_reg() == reg || insn.src_reg() == reg,
        BPF_JMP | BPF_JMP32 => {
            if insn.is_call() {
                (1..=5).contains(&reg)
            } else if insn.is_exit() {
                reg == 0
            } else if insn.is_ja() {
                false
            } else {
                insn.dst_reg() == reg || (bpf_src(insn.code) == BPF_X && insn.src_reg() == reg)
            }
        }
        _ => false,
    }
}

fn insn_defines_reg(insn: &BpfInsn, reg: u8) -> bool {
    match insn.class() {
        BPF_ALU64 | BPF_ALU | BPF_LDX | BPF_LD => insn.dst_reg() == reg,
        BPF_JMP | BPF_JMP32 => insn.is_call() && reg <= 5,
        _ => false,
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    fn ld_imm64(dst: u8, src: u8, imm: i32) -> [BpfInsn; 2] {
        [
            BpfInsn {
                code: BPF_LD | BPF_DW | BPF_IMM,
                regs: BpfInsn::make_regs(dst, src),
                off: 0,
                imm,
            },
            BpfInsn {
                code: 0,
                regs: 0,
                off: 0,
                imm: 0,
            },
        ]
    }

    fn st_mem(size: u8, dst: u8, off: i16, imm: i32) -> BpfInsn {
        BpfInsn {
            code: BPF_ST | size | BPF_MEM,
            regs: BpfInsn::make_regs(dst, 0),
            off,
            imm,
        }
    }

    fn add64_imm(dst: u8, imm: i32) -> BpfInsn {
        BpfInsn {
            code: BPF_ALU64 | BPF_ADD | BPF_K,
            regs: BpfInsn::make_regs(dst, 0),
            off: 0,
            imm,
        }
    }

    fn call_helper(imm: i32) -> BpfInsn {
        BpfInsn {
            code: BPF_JMP | BPF_CALL,
            regs: BpfInsn::make_regs(0, 0),
            off: 0,
            imm,
        }
    }

    fn jeq_imm(dst: u8, imm: i32, off: i16) -> BpfInsn {
        BpfInsn {
            code: BPF_JMP | BPF_JEQ | BPF_K,
            regs: BpfInsn::make_regs(dst, 0),
            off,
            imm,
        }
    }

    #[test]
    fn find_map_lookup_sites_matches_helper_one_with_map_arg() {
        let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
        let insns = vec![
            map[0],
            map[1],
            st_mem(BPF_W, 10, -4, 7),
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -4),
            call_helper(HELPER_MAP_LOOKUP_ELEM),
        ];

        let sites = find_map_lookup_sites(&insns);
        assert_eq!(
            sites,
            vec![MapLookupSite {
                call_pc: 5,
                map_load_pc: 0,
            }]
        );
    }

    #[test]
    fn find_map_lookup_sites_ignores_calls_without_map_load() {
        let insns = vec![
            BpfInsn::mov64_imm(1, 0),
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -4),
            call_helper(HELPER_MAP_LOOKUP_ELEM),
        ];

        assert!(find_map_lookup_sites(&insns).is_empty());
    }

    #[test]
    fn extract_constant_key_from_direct_stack_store() {
        let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
        let insns = vec![
            map[0],
            map[1],
            st_mem(BPF_W, 10, -4, 7),
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -4),
            call_helper(HELPER_MAP_LOOKUP_ELEM),
        ];

        let key = extract_constant_key(&insns, 5).unwrap();
        assert_eq!(key.stack_off, -4);
        assert_eq!(key.width, 4);
        assert_eq!(key.value, 7);
        assert_eq!(key.store_pc, 2);
        assert_eq!(key.source_imm_pc, None);
    }

    #[test]
    fn extract_constant_key_from_stx_stack_store() {
        let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
        let insns = vec![
            map[0],
            map[1],
            BpfInsn::mov64_imm(3, 9),
            BpfInsn::stx_mem(BPF_W, 10, 3, -4),
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -4),
            call_helper(HELPER_MAP_LOOKUP_ELEM),
        ];

        let key = extract_constant_key(&insns, 6).unwrap();
        assert_eq!(key.value, 9);
        assert_eq!(key.store_pc, 3);
        assert_eq!(key.source_imm_pc, Some(2));
    }

    #[test]
    fn classify_r0_uses_collects_fixed_loads_until_redefinition() {
        let insns = vec![
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            BpfInsn::ldx_mem(BPF_W, 3, 0, 0),
            BpfInsn::ldx_mem(BPF_B, 4, 0, 7),
            BpfInsn::mov64_imm(0, 1),
            BpfInsn::ldx_mem(BPF_W, 5, 0, 0),
        ];

        let uses = classify_r0_uses(&insns, 0);
        assert_eq!(
            uses.fixed_loads,
            vec![
                FixedLoadUse {
                    pc: 1,
                    dst_reg: 3,
                    size: BPF_W,
                    offset: 0,
                },
                FixedLoadUse {
                    pc: 2,
                    dst_reg: 4,
                    size: BPF_B,
                    offset: 7,
                },
            ]
        );
        assert!(uses.other_uses.is_empty());
    }

    #[test]
    fn classify_r0_uses_marks_pointer_escape_and_null_check_as_other() {
        let insns = vec![
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            jeq_imm(0, 0, 1),
            BpfInsn::mov64_reg(1, 0),
            BpfInsn::ldx_mem(BPF_W, 3, 0, 0),
        ];

        let uses = classify_r0_uses(&insns, 0);
        assert_eq!(uses.fixed_loads.len(), 1);
        assert_eq!(uses.other_uses, vec![1, 2]);
        assert!(!uses.all_fixed_loads());
    }
}
