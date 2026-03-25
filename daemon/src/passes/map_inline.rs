// SPDX-License-Identifier: MIT
//! Scan helpers for dynamic map inlining.
#![cfg_attr(not(test), allow(dead_code))]

use std::collections::{BTreeMap, HashSet};

use crate::analysis::{BranchTargetAnalysis, MapInfoAnalysis};
use crate::bpf;
use crate::insn::*;
use crate::pass::*;

const BPF_ADD: u8 = 0x00;
const BPF_PSEUDO_MAP_FD: u8 = 1;
const HELPER_MAP_LOOKUP_ELEM: i32 = 1;

/// Dynamic map inlining optimization pass.
pub struct MapInlinePass;

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

#[derive(Clone, Debug)]
struct SiteRewrite {
    skipped_pcs: HashSet<usize>,
    replacements: BTreeMap<usize, Vec<BpfInsn>>,
}

impl BpfPass for MapInlinePass {
    fn name(&self) -> &str {
        "map_inline"
    }

    fn required_analyses(&self) -> Vec<&str> {
        vec!["branch_targets", "map_info"]
    }

    fn run(
        &self,
        program: &mut BpfProgram,
        analyses: &mut AnalysisCache,
        _ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
        let bt = analyses.get(&BranchTargetAnalysis, program);
        let map_info = analyses.get(&MapInfoAnalysis, program);
        let mut skipped = Vec::new();
        let mut rewrites = Vec::new();

        for site in find_map_lookup_sites(&program.insns) {
            let Some(map_ref) = map_info.reference_at_pc(site.map_load_pc) else {
                skipped.push(SkipReason {
                    pc: site.call_pc,
                    reason: "map reference metadata unavailable".into(),
                });
                continue;
            };
            let Some(info) = map_ref.info.as_ref() else {
                skipped.push(SkipReason {
                    pc: site.call_pc,
                    reason: "map info unavailable".into(),
                });
                continue;
            };
            if !info.is_inlineable_v1() {
                skipped.push(SkipReason {
                    pc: site.call_pc,
                    reason: format!("map type {} not inlineable in v1", info.map_type),
                });
                continue;
            }

            let Some(key) = extract_constant_key(&program.insns, site.call_pc) else {
                skipped.push(SkipReason {
                    pc: site.call_pc,
                    reason: "lookup key is not a constant stack materialization".into(),
                });
                continue;
            };
            if key.width as u32 != info.key_size {
                skipped.push(SkipReason {
                    pc: site.call_pc,
                    reason: format!(
                        "key width {} does not match map key size {}",
                        key.width, info.key_size
                    ),
                });
                continue;
            }
            if key.value >= info.max_entries as u64 {
                skipped.push(SkipReason {
                    pc: site.call_pc,
                    reason: format!(
                        "constant key {} out of range for max_entries {}",
                        key.value, info.max_entries
                    ),
                });
                continue;
            }

            let uses = classify_r0_uses(&program.insns, site.call_pc);
            if uses.fixed_loads.is_empty() {
                skipped.push(SkipReason {
                    pc: site.call_pc,
                    reason: "lookup result is not consumed by fixed-offset scalar loads".into(),
                });
                continue;
            }
            if !uses.all_fixed_loads() {
                skipped.push(SkipReason {
                    pc: site.call_pc,
                    reason: "lookup result has non-load uses".into(),
                });
                continue;
            }

            let rewrite = match build_site_rewrite(program, &site, &key, &uses, info) {
                Ok(Some(rewrite)) => rewrite,
                Ok(None) => {
                    skipped.push(SkipReason {
                        pc: site.call_pc,
                        reason: "failed to materialize replacement constants".into(),
                    });
                    continue;
                }
                Err(err) => {
                    skipped.push(SkipReason {
                        pc: site.call_pc,
                        reason: format!("map lookup failed: {err:#}"),
                    });
                    continue;
                }
            };

            if rewrite
                .skipped_pcs
                .iter()
                .any(|&pc| pc < bt.is_target.len() && bt.is_target[pc])
            {
                skipped.push(SkipReason {
                    pc: site.call_pc,
                    reason: "lookup pattern contains a branch target".into(),
                });
                continue;
            }

            if rewrite
                .replacements
                .keys()
                .any(|pc| rewrite.skipped_pcs.contains(pc))
            {
                skipped.push(SkipReason {
                    pc: site.call_pc,
                    reason: "internal rewrite overlap".into(),
                });
                continue;
            }

            rewrites.push(rewrite);
        }

        if rewrites.is_empty() {
            return Ok(PassResult {
                pass_name: self.name().into(),
                changed: false,
                sites_applied: 0,
                sites_skipped: skipped,
                diagnostics: vec![],
                ..Default::default()
            });
        }

        let mut skip_pcs = HashSet::new();
        let mut replacements: BTreeMap<usize, Vec<BpfInsn>> = BTreeMap::new();
        let mut applied = 0usize;

        for rewrite in rewrites {
            let conflict = rewrite
                .skipped_pcs
                .iter()
                .any(|pc| replacements.contains_key(pc))
                || rewrite.replacements.keys().any(|pc| skip_pcs.contains(pc))
                || rewrite
                    .replacements
                    .keys()
                    .any(|pc| replacements.contains_key(pc))
                || rewrite.skipped_pcs.iter().any(|pc| skip_pcs.contains(pc));
            if conflict {
                skipped.push(SkipReason {
                    pc: rewrite.replacements.keys().next().copied().unwrap_or(0),
                    reason: "overlapping map inline rewrite".into(),
                });
                continue;
            }

            skip_pcs.extend(rewrite.skipped_pcs);
            replacements.extend(rewrite.replacements);
            applied += 1;
        }

        if applied == 0 {
            return Ok(PassResult {
                pass_name: self.name().into(),
                changed: false,
                sites_applied: 0,
                sites_skipped: skipped,
                diagnostics: vec![],
                ..Default::default()
            });
        }

        let orig_len = program.insns.len();
        let mut new_insns = Vec::with_capacity(orig_len);
        let mut addr_map = vec![0usize; orig_len + 1];
        let mut pc = 0usize;

        while pc < orig_len {
            addr_map[pc] = new_insns.len();

            if let Some(replacement) = replacements.get(&pc) {
                new_insns.extend_from_slice(replacement);
                pc += 1;
                continue;
            }

            if skip_pcs.contains(&pc) {
                pc += 1;
                continue;
            }

            let insn = program.insns[pc];
            new_insns.push(insn);
            if insn.is_ldimm64() && pc + 1 < orig_len {
                pc += 1;
                addr_map[pc] = new_insns.len();
                new_insns.push(program.insns[pc]);
            }
            pc += 1;
        }
        addr_map[orig_len] = new_insns.len();

        super::utils::fixup_all_branches(&mut new_insns, &program.insns, &addr_map);

        program.insns = new_insns;
        program.remap_annotations(&addr_map);
        program.log_transform(TransformEntry {
            sites_applied: applied,
        });

        Ok(PassResult {
            pass_name: self.name().into(),
            changed: true,
            sites_applied: applied,
            sites_skipped: skipped,
            diagnostics: vec![],
            ..Default::default()
        })
    }
}

fn build_site_rewrite(
    program: &BpfProgram,
    site: &MapLookupSite,
    key: &ConstantKey,
    uses: &R0UseClassification,
    info: &crate::analysis::MapInfo,
) -> anyhow::Result<Option<SiteRewrite>> {
    let value = bpf::bpf_map_lookup_elem_by_id(
        info.map_id,
        &encode_key_bytes(key.value, info.key_size as usize),
        info.value_size as usize,
    )?;

    let mut skipped_pcs = HashSet::new();
    skipped_pcs.insert(site.call_pc);
    skipped_pcs.insert(site.map_load_pc);
    skipped_pcs.insert(site.map_load_pc + 1);
    skipped_pcs.insert(key.store_pc);
    skipped_pcs.insert(key.r2_mov_pc);
    skipped_pcs.insert(key.r2_add_pc);
    if let Some(source_imm_pc) = key.source_imm_pc {
        skipped_pcs.insert(source_imm_pc);
    }

    let mut replacements = BTreeMap::new();
    for load in &uses.fixed_loads {
        let scalar = read_scalar_from_value(&value, load.offset, load.size).ok_or_else(|| {
            anyhow::anyhow!(
                "map value read out of bounds for load pc {} (offset {}, size {})",
                load.pc,
                load.offset,
                load.size
            )
        })?;
        replacements.insert(load.pc, emit_constant_load(load.dst_reg, scalar, load.size));
    }

    if replacements.is_empty() {
        return Ok(None);
    }

    // The raw PCs we remove must be exactly the lookup pattern. If unrelated
    // instructions are interleaved, skip the site rather than deleting them.
    let min_removed_pc = skipped_pcs.iter().min().copied().unwrap_or(site.call_pc);
    let max_removed_pc = skipped_pcs.iter().max().copied().unwrap_or(site.call_pc);
    if skipped_pcs.len() != max_removed_pc - min_removed_pc + 1 {
        return Ok(None);
    }

    // Do not remove the instruction stream past the lookup call itself.
    if max_removed_pc != site.call_pc {
        return Ok(None);
    }

    // All removed PCs must be within bounds.
    if skipped_pcs.iter().any(|&pc| pc >= program.insns.len()) {
        return Ok(None);
    }

    Ok(Some(SiteRewrite {
        skipped_pcs,
        replacements,
    }))
}

fn encode_key_bytes(value: u64, key_size: usize) -> Vec<u8> {
    value.to_le_bytes()[..key_size].to_vec()
}

fn read_scalar_from_value(value: &[u8], offset: i16, size: u8) -> Option<u64> {
    if offset < 0 {
        return None;
    }
    let width = size_in_bytes(size)? as usize;
    let offset = offset as usize;
    if offset + width > value.len() {
        return None;
    }

    let mut buf = [0u8; 8];
    buf[..width].copy_from_slice(&value[offset..offset + width]);
    Some(u64::from_le_bytes(buf))
}

fn emit_constant_load(dst_reg: u8, value: u64, size: u8) -> Vec<BpfInsn> {
    if size == BPF_DW || value > i32::MAX as u64 {
        return emit_ldimm64(dst_reg, value);
    }

    vec![BpfInsn::mov64_imm(dst_reg, value as i32)]
}

fn emit_ldimm64(dst_reg: u8, value: u64) -> Vec<BpfInsn> {
    vec![
        BpfInsn {
            code: BPF_LD | BPF_DW | BPF_IMM,
            regs: BpfInsn::make_regs(dst_reg, 0),
            off: 0,
            imm: value as u32 as i32,
        },
        BpfInsn {
            code: 0,
            regs: 0,
            off: 0,
            imm: (value >> 32) as u32 as i32,
        },
    ]
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
    use std::collections::HashMap;

    use crate::analysis::{BranchTargetAnalysis, MapInfoAnalysis};
    use crate::bpf::{install_mock_map, BpfMapInfo, MockMapState};
    use crate::pass::{PassContext, PassManager};

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

    fn exit_insn() -> BpfInsn {
        BpfInsn {
            code: BPF_JMP | BPF_EXIT,
            regs: 0,
            off: 0,
            imm: 0,
        }
    }

    fn install_array_map(map_id: u32, value: Vec<u8>) {
        let mut info = BpfMapInfo::default();
        info.map_type = 2;
        info.id = map_id;
        info.key_size = 4;
        info.value_size = value.len() as u32;
        info.max_entries = 8;

        let mut values = HashMap::new();
        values.insert(1u32.to_le_bytes().to_vec(), value);
        install_mock_map(
            map_id,
            MockMapState {
                info,
                frozen: false,
                values,
            },
        );
    }

    fn run_map_inline_pass(program: &mut BpfProgram) -> PipelineResult {
        let mut pm = PassManager::new();
        pm.register_analysis(BranchTargetAnalysis);
        pm.register_analysis(MapInfoAnalysis);
        pm.add_pass(MapInlinePass);
        pm.run(program, &PassContext::test_default()).unwrap()
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

    #[test]
    fn map_inline_pass_rewrites_lookup_and_scalar_loads() {
        install_array_map(101, vec![7, 0, 0, 0, 0xaa, 0, 0, 0]);

        let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
        let mut program = BpfProgram::new(vec![
            map[0],
            map[1],
            st_mem(BPF_W, 10, -4, 1),
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -4),
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
            BpfInsn::ldx_mem(BPF_B, 7, 0, 4),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]);
        program.set_map_ids(vec![101]);

        let result = run_map_inline_pass(&mut program);

        assert!(
            result.program_changed,
            "skip reasons: {:?}",
            result.pass_results[0].sites_skipped
        );
        assert_eq!(result.total_sites_applied, 1);
        assert_eq!(
            program.insns,
            vec![
                BpfInsn::mov64_imm(6, 7),
                BpfInsn::mov64_imm(7, 0xaa),
                BpfInsn::mov64_imm(0, 0),
                exit_insn(),
            ]
        );
    }

    #[test]
    fn map_inline_pass_skips_null_checked_lookup_for_step3() {
        install_array_map(102, vec![7, 0, 0, 0, 0xaa, 0, 0, 0]);

        let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
        let original = vec![
            map[0],
            map[1],
            st_mem(BPF_W, 10, -4, 1),
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -4),
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            jeq_imm(0, 0, 1),
            BpfInsn::ldx_mem(BPF_W, 6, 0, 0),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ];
        let mut program = BpfProgram::new(original.clone());
        program.set_map_ids(vec![102]);

        let result = run_map_inline_pass(&mut program);

        assert!(!result.program_changed);
        assert_eq!(program.insns, original);
        assert_eq!(result.pass_results[0].sites_applied, 0);
        assert!(result.pass_results[0]
            .sites_skipped
            .iter()
            .any(|skip| skip.reason.contains("non-load uses")));
    }

    #[test]
    fn map_inline_pass_emits_ldimm64_for_wide_constants() {
        install_array_map(103, 0x1_0000_0000u64.to_le_bytes().to_vec());

        let map = ld_imm64(1, BPF_PSEUDO_MAP_FD, 42);
        let mut program = BpfProgram::new(vec![
            map[0],
            map[1],
            st_mem(BPF_W, 10, -4, 1),
            BpfInsn::mov64_reg(2, 10),
            add64_imm(2, -4),
            call_helper(HELPER_MAP_LOOKUP_ELEM),
            BpfInsn::ldx_mem(BPF_DW, 6, 0, 0),
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
        ]);
        program.set_map_ids(vec![103]);

        let result = run_map_inline_pass(&mut program);

        assert!(
            result.program_changed,
            "skip reasons: {:?}",
            result.pass_results[0].sites_skipped
        );
        assert_eq!(program.insns.len(), 4);
        assert!(program.insns[0].is_ldimm64());
        assert_eq!(program.insns[0].dst_reg(), 6);
        assert_eq!(program.insns[0].imm as u32 as u64, 0);
        assert_eq!(program.insns[1].imm as u32 as u64, 1);
    }
}
