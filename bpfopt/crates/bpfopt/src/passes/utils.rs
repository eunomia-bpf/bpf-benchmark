// SPDX-License-Identifier: MIT
// Shared utilities for BPF rewrite passes.
//
// Contains branch fixup, kinsn call emission, and instruction iteration
// helpers that are used by multiple passes.

use std::collections::HashSet;

use crate::analysis::{CFGAnalysis, CFGResult, LivenessAnalysis};
use crate::insn::*;
use crate::pass::{Analysis, BpfProgram, BtfInfoRecords, KinsnRegistry, PassContext};

const BPF_FUNC_TAIL_CALL: i32 = kernel_sys::BPF_FUNC_tail_call as i32;
const BPF_TAIL_CALL: u8 = 0xf0;

// ── Branch fixup ───────────────────────────────────────────────────

/// Fix up branch and pseudo-call offsets after rewriting using an address map.
///
/// For each instruction in the *original* stream that is a branch/jump,
/// compute where it ended up in the new stream and adjust its offset
/// so it still points to the correct target.
pub fn fixup_all_branches(new_insns: &mut [BpfInsn], old_insns: &[BpfInsn], addr_map: &[usize]) {
    let old_n = old_insns.len();
    let mut old_pc = 0;
    while old_pc < old_n {
        let insn = &old_insns[old_pc];
        let new_pc = addr_map[old_pc];
        let next_old_pc = old_pc + insn_width(insn);
        let survived_unchanged = new_pc < new_insns.len()
            && next_old_pc < addr_map.len()
            && addr_map[next_old_pc] > new_pc
            && new_insns.get(new_pc).copied() == Some(*insn);

        if insn.is_ldimm64_pseudo_func() {
            let old_target = (old_pc as i64 + 1 + insn.imm as i64) as usize;
            if old_target < old_n
                && survived_unchanged
                && new_pc < new_insns.len()
                && new_insns[new_pc].is_ldimm64_pseudo_func()
            {
                let new_target = addr_map[old_target];
                let new_imm = new_target as i64 - (new_pc as i64 + 1);
                new_insns[new_pc].imm = new_imm as i32;
            }
        } else if insn.is_call() && insn.src_reg() == 1 {
            // BPF pseudo-call: fix up imm (pc-relative offset to target subprog).
            let old_target = (old_pc as i64 + 1 + insn.imm as i64) as usize;
            if old_target < old_n {
                let new_target = addr_map[old_target];
                if survived_unchanged && new_insns[new_pc].is_call() {
                    let new_imm = new_target as i64 - (new_pc as i64 + 1);
                    new_insns[new_pc].imm = new_imm as i32;
                }
            }
        } else if insn.is_jmp_class() && !insn.is_call() && !insn.is_exit() {
            let old_target = (old_pc as i64 + 1 + insn.off as i64) as usize;
            if old_target <= old_n {
                let new_target = addr_map[old_target];
                if survived_unchanged
                    && new_insns[new_pc].is_jmp_class()
                    && !new_insns[new_pc].is_call()
                    && !new_insns[new_pc].is_exit()
                {
                    let new_off = new_target as i64 - (new_pc as i64 + 1);
                    new_insns[new_pc].off = new_off as i16;
                }
            }
        }
        old_pc = if insn.is_ldimm64() {
            old_pc + 2
        } else {
            old_pc + 1
        };
    }
}

/// Compose two address maps: `old -> mid` and `mid -> new`.
pub fn compose_addr_maps(first: &[usize], second: &[usize]) -> Vec<usize> {
    first.iter().map(|&pc| second[pc]).collect()
}

pub fn remap_btf_metadata(program: &mut BpfProgram, addr_map: &[usize]) -> anyhow::Result<()> {
    remap_btf_records(
        "func_info",
        BtfRecordKind::Func,
        program.func_info.as_mut(),
        addr_map,
        &program.insns,
    )?;
    remap_btf_records(
        "line_info",
        BtfRecordKind::Line,
        program.line_info.as_mut(),
        addr_map,
        &program.insns,
    )?;
    Ok(())
}

pub fn remap_kinsn_btf_metadata(
    program: &mut BpfProgram,
    registry: &KinsnRegistry,
) -> anyhow::Result<()> {
    let proof_subprog_starts = kinsn_proof_subprog_starts(&program.insns, registry)?;
    rewrite_func_info_to_subprog_layout(program.func_info.as_mut(), &proof_subprog_starts)?;

    if let Some(records) = program.line_info.as_mut() {
        records.bytes.clear();
    }
    Ok(())
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
enum BtfRecordKind {
    Func,
    Line,
}

fn remap_btf_records(
    label: &str,
    kind: BtfRecordKind,
    records: Option<&mut BtfInfoRecords>,
    addr_map: &[usize],
    new_insns: &[BpfInsn],
) -> anyhow::Result<()> {
    remap_btf_records_for_len(
        label,
        kind,
        records,
        addr_map,
        new_insns.len(),
        Some(new_insns),
    )
}

fn remap_btf_records_for_len(
    label: &str,
    kind: BtfRecordKind,
    records: Option<&mut BtfInfoRecords>,
    addr_map: &[usize],
    new_len: usize,
    new_insns: Option<&[BpfInsn]>,
) -> anyhow::Result<()> {
    let Some(records) = records else {
        return Ok(());
    };
    if records.bytes.is_empty() {
        return Ok(());
    }
    if records.rec_size < std::mem::size_of::<u32>() as u32 {
        anyhow::bail!(
            "{label} rec_size {} is too small to hold insn_off",
            records.rec_size
        );
    }
    let rec_size = records.rec_size as usize;
    if !records.bytes.len().is_multiple_of(rec_size) {
        anyhow::bail!(
            "{label} byte length {} is not a multiple of rec_size {}",
            records.bytes.len(),
            records.rec_size
        );
    }

    let mut remapped = Vec::with_capacity(records.bytes.len());
    let mut previous_new_pc = None;

    for record in records.bytes.chunks(rec_size) {
        let old_pc =
            u32::from_le_bytes(record[..4].try_into().expect("record has insn_off")) as usize;
        let Some(new_pc) = remapped_pc(label, kind, old_pc, addr_map, new_len)? else {
            continue;
        };
        if kind == BtfRecordKind::Line
            && new_insns.is_some_and(|insns| !valid_line_info_pc(insns, new_pc))
        {
            continue;
        };
        if let Some(previous) = previous_new_pc {
            if new_pc < previous {
                anyhow::bail!(
                    "{label} remap produced non-increasing insn_off {new_pc} after {previous}"
                );
            }
            if new_pc == previous {
                if kind == BtfRecordKind::Line {
                    continue;
                }
                anyhow::bail!(
                    "{label} remap produced non-increasing insn_off {new_pc} after {previous}"
                );
            }
        }

        let new_pc: u32 = new_pc
            .try_into()
            .map_err(|_| anyhow::anyhow!("{label} remapped insn_off does not fit u32"))?;
        remapped.extend_from_slice(record);
        let start = remapped.len() - rec_size;
        remapped[start..start + 4].copy_from_slice(&new_pc.to_le_bytes());
        previous_new_pc = Some(new_pc as usize);
    }

    records.bytes = remapped;
    Ok(())
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
struct KinsnProofRegion {
    sidecar_pc: usize,
    call_pc: usize,
    proof_len: usize,
}

fn kinsn_proof_subprog_starts(
    insns: &[BpfInsn],
    registry: &KinsnRegistry,
) -> anyhow::Result<Vec<usize>> {
    let mut starts = kinsn_candidate_subprog_starts(insns)?;
    let regions = collect_kinsn_proof_regions(insns, registry)?;

    for region in regions.iter().rev() {
        if starts.contains(&region.call_pc) {
            anyhow::bail!(
                "kinsn call at pc {} starts a subprogram and cannot use pc {} as sidecar",
                region.call_pc,
                region.sidecar_pc
            );
        }
        let delta = region.proof_len as isize - 2;
        if delta == 0 {
            continue;
        }
        for start in &mut starts {
            if *start <= region.sidecar_pc {
                continue;
            }
            *start = if delta > 0 {
                start.checked_add(delta as usize).ok_or_else(|| {
                    anyhow::anyhow!("kinsn proof subprog offset overflow at pc {start}")
                })?
            } else {
                start.checked_sub((-delta) as usize).ok_or_else(|| {
                    anyhow::anyhow!("kinsn proof subprog offset underflow at pc {start}")
                })?
            };
        }
    }

    Ok(starts)
}

fn collect_kinsn_proof_regions(
    insns: &[BpfInsn],
    registry: &KinsnRegistry,
) -> anyhow::Result<Vec<KinsnProofRegion>> {
    let mut regions = Vec::new();
    let mut pc = 0usize;
    while pc < insns.len() {
        if pc + 1 < insns.len()
            && is_kinsn_sidecar_insn(&insns[pc])
            && insns[pc + 1].is_call()
            && insns[pc + 1].src_reg() == BPF_PSEUDO_KINSN_CALL
        {
            let payload = kinsn_sidecar_payload(&insns[pc]);
            let btf_id = insns[pc + 1].imm;
            let call_off = insns[pc + 1].off;
            let proof_len = kinsn_proof_len(registry, btf_id, call_off, payload)?;
            regions.push(KinsnProofRegion {
                sidecar_pc: pc,
                call_pc: pc + 1,
                proof_len,
            });
            pc += 2;
            continue;
        }

        if is_kinsn_sidecar_insn(&insns[pc]) {
            anyhow::bail!("kinsn sidecar at pc {pc} is not followed by a kinsn call");
        }
        if insns[pc].is_call() && insns[pc].src_reg() == BPF_PSEUDO_KINSN_CALL {
            anyhow::bail!("kinsn call at pc {pc} is missing its packed sidecar");
        }

        pc += 1;
    }

    Ok(regions)
}

fn kinsn_proof_len(
    registry: &KinsnRegistry,
    btf_id: i32,
    call_off: i16,
    payload: u64,
) -> anyhow::Result<usize> {
    if kinsn_call_matches(
        registry,
        btf_id,
        call_off,
        "bpf_rotate64",
        registry.rotate64_btf_id,
    ) {
        return rotate_proof_len(payload);
    }
    if kinsn_call_matches(
        registry,
        btf_id,
        call_off,
        "bpf_select64",
        registry.select64_btf_id,
    ) {
        return select_proof_len(payload);
    }
    if kinsn_call_matches(
        registry,
        btf_id,
        call_off,
        "bpf_ccmp64",
        registry.ccmp64_btf_id,
    ) {
        return ccmp_proof_len(payload);
    }
    if kinsn_call_matches(
        registry,
        btf_id,
        call_off,
        "bpf_extract64",
        registry.extract64_btf_id,
    ) {
        return extract_proof_len(payload);
    }
    if kinsn_call_matches(
        registry,
        btf_id,
        call_off,
        "bpf_memcpy_bulk",
        registry.memcpy_bulk_btf_id,
    ) {
        return memcpy_bulk_proof_len(payload);
    }
    if kinsn_call_matches(
        registry,
        btf_id,
        call_off,
        "bpf_memset_bulk",
        registry.memset_bulk_btf_id,
    ) {
        return memset_bulk_proof_len(payload);
    }
    if kinsn_call_matches(
        registry,
        btf_id,
        call_off,
        "bpf_endian_load16",
        registry.endian_load16_btf_id,
    ) || kinsn_call_matches(
        registry,
        btf_id,
        call_off,
        "bpf_endian_load32",
        registry.endian_load32_btf_id,
    ) || kinsn_call_matches(
        registry,
        btf_id,
        call_off,
        "bpf_endian_load64",
        registry.endian_load64_btf_id,
    ) {
        return endian_proof_len(payload);
    }
    if kinsn_call_matches(
        registry,
        btf_id,
        call_off,
        "bpf_prefetch",
        registry.prefetch_btf_id,
    ) {
        return prefetch_proof_len(payload);
    }

    anyhow::bail!("kinsn call btf_id {btf_id} is not present in the kinsn registry")
}

fn kinsn_call_matches(
    registry: &KinsnRegistry,
    actual_btf_id: i32,
    actual_call_off: i16,
    target_name: &str,
    expected_btf_id: i32,
) -> bool {
    if expected_btf_id <= 0 || actual_btf_id != expected_btf_id {
        return false;
    }
    registry
        .target_call_offsets
        .get(target_name)
        .is_none_or(|&expected_off| actual_call_off == expected_off)
}

fn kinsn_sidecar_payload(insn: &BpfInsn) -> u64 {
    (u64::from(insn.dst_reg()) & 0xf)
        | (u64::from(insn.off as u16) << 4)
        | (u64::from(insn.imm as u32) << 20)
}

fn payload_reg(payload: u64, shift: u8) -> u8 {
    ((payload >> shift) & 0xf) as u8
}

fn payload_u8(payload: u64, shift: u8) -> u8 {
    ((payload >> shift) & 0xff) as u8
}

fn payload_s16(payload: u64, shift: u8) -> i16 {
    ((payload >> shift) & 0xffff) as u16 as i16
}

fn validate_bpf_reg(label: &str, reg: u8) -> anyhow::Result<()> {
    if reg > BPF_REG_10 {
        anyhow::bail!("{label} register {reg} is outside BPF_REG_0..BPF_REG_10");
    }
    Ok(())
}

fn rotate_proof_len(payload: u64) -> anyhow::Result<usize> {
    let dst_reg = payload_reg(payload, 0);
    let src_reg = payload_reg(payload, 4);
    let shift = payload_u8(payload, 8) & 63;
    let tmp_reg = payload_reg(payload, 16);

    validate_bpf_reg("rotate dst", dst_reg)?;
    validate_bpf_reg("rotate src", src_reg)?;
    validate_bpf_reg("rotate tmp", tmp_reg)?;
    if tmp_reg == dst_reg || tmp_reg == src_reg {
        anyhow::bail!("rotate tmp register aliases an operand");
    }
    if shift == 0 {
        Ok(1)
    } else if dst_reg == src_reg {
        Ok(4)
    } else {
        Ok(5)
    }
}

fn select_proof_len(payload: u64) -> anyhow::Result<usize> {
    validate_bpf_reg("select dst", payload_reg(payload, 0))?;
    validate_bpf_reg("select true", payload_reg(payload, 4))?;
    validate_bpf_reg("select false", payload_reg(payload, 8))?;
    validate_bpf_reg("select cond", payload_reg(payload, 12))?;
    if payload_reg(payload, 16) != 0 {
        anyhow::bail!("select condition mode is not KINSN_SELECT_COND_NEZ");
    }
    Ok(4)
}

fn ccmp_proof_len(payload: u64) -> anyhow::Result<usize> {
    let dst_reg = payload_reg(payload, 0);
    let count_bits = ((payload >> 4) & 0x3) as u8;
    let count = usize::from(count_bits) + 2;
    let mode = (payload >> 6) & 0x1;

    if payload >> 24 != 0 {
        anyhow::bail!("ccmp payload has non-zero reserved bits");
    }
    if count_bits > 2 {
        anyhow::bail!("ccmp count {} exceeds maximum 4", count);
    }
    if dst_reg > BPF_REG_9 {
        anyhow::bail!("ccmp dst register {dst_reg} is outside BPF_REG_0..BPF_REG_9");
    }
    if mode > 1 {
        anyhow::bail!("ccmp mode {mode} is invalid");
    }

    for idx in 0..4 {
        let reg = payload_reg(payload, (8 + idx * 4) as u8);
        if idx >= count {
            if reg != 0 {
                anyhow::bail!("ccmp unused register slot {idx} is non-zero");
            }
            continue;
        }
        validate_bpf_reg("ccmp compare", reg)?;
        if reg == dst_reg {
            anyhow::bail!("ccmp dst register aliases compare operand r{reg}");
        }
    }

    Ok(count + 2)
}

fn extract_proof_len(payload: u64) -> anyhow::Result<usize> {
    validate_bpf_reg("extract dst", payload_reg(payload, 0))?;
    let start = payload_u8(payload, 8);
    let bit_len = payload_u8(payload, 16);
    if start >= 64 || bit_len == 0 || bit_len > 32 || u16::from(start) + u16::from(bit_len) > 64 {
        anyhow::bail!("extract payload has invalid range start={start} bit_len={bit_len}");
    }
    Ok(usize::from(start != 0) + 1)
}

fn bulk_offset_range_valid(offset: i16, len: usize) -> bool {
    let end = i32::from(offset) + len as i32 - 1;
    end >= i32::from(i16::MIN) && end <= i32::from(i16::MAX)
}

fn memcpy_bulk_proof_len(payload: u64) -> anyhow::Result<usize> {
    let dst_base = payload_reg(payload, 0);
    let src_base = payload_reg(payload, 4);
    let dst_off = payload_s16(payload, 8);
    let src_off = payload_s16(payload, 24);
    let len = usize::from(payload_u8(payload, 40)) + 1;
    let tmp_reg = payload_reg(payload, 48);

    if payload >> 52 != 0 {
        anyhow::bail!("memcpy bulk payload has non-zero reserved bits");
    }
    if len == 0 || len > 128 {
        anyhow::bail!("memcpy bulk length {len} is outside 1..128");
    }
    validate_bpf_reg("memcpy bulk dst", dst_base)?;
    validate_bpf_reg("memcpy bulk src", src_base)?;
    validate_bpf_reg("memcpy bulk tmp", tmp_reg)?;
    if tmp_reg == BPF_REG_10 || tmp_reg == dst_base || tmp_reg == src_base {
        anyhow::bail!("memcpy bulk tmp register aliases an invalid operand");
    }
    if !bulk_offset_range_valid(dst_off, len) || !bulk_offset_range_valid(src_off, len) {
        anyhow::bail!("memcpy bulk offset range is outside s16");
    }
    Ok(len * 2)
}

fn memset_bulk_proof_len(payload: u64) -> anyhow::Result<usize> {
    let dst_base = payload_reg(payload, 0);
    let val_reg = payload_reg(payload, 4);
    let dst_off = payload_s16(payload, 8);
    let len = usize::from(payload_u8(payload, 24)) + 1;
    let width_class = (payload >> 32) & 0x3;
    let value_from_reg = ((payload >> 34) & 0x1) != 0;
    let zero_fill = ((payload >> 35) & 0x1) != 0;
    let fill_imm8 = payload_u8(payload, 36);
    let width_bytes = 1usize << width_class;

    if payload >> 44 != 0 {
        anyhow::bail!("memset bulk payload has non-zero reserved bits");
    }
    if len == 0 || len > 128 {
        anyhow::bail!("memset bulk length {len} is outside 1..128");
    }
    validate_bpf_reg("memset bulk dst", dst_base)?;
    if value_from_reg {
        validate_bpf_reg("memset bulk value", val_reg)?;
    }
    if len % width_bytes != 0 {
        anyhow::bail!("memset bulk length {len} is not a multiple of width {width_bytes}");
    }
    if !bulk_offset_range_valid(dst_off, len) {
        anyhow::bail!("memset bulk offset range is outside s16");
    }
    if zero_fill && fill_imm8 != 0 {
        anyhow::bail!("memset bulk zero-fill payload has non-zero fill immediate");
    }
    Ok(len)
}

fn endian_proof_len(payload: u64) -> anyhow::Result<usize> {
    validate_bpf_reg("endian dst", payload_reg(payload, 0))?;
    validate_bpf_reg("endian base", payload_reg(payload, 4))?;
    Ok(2)
}

fn prefetch_proof_len(payload: u64) -> anyhow::Result<usize> {
    validate_bpf_reg("prefetch ptr", payload_reg(payload, 0))?;
    if ((payload >> 4) & 0xf) != 0 {
        anyhow::bail!("prefetch payload has unsupported hint kind");
    }
    if payload >> 8 != 0 {
        anyhow::bail!("prefetch payload has non-zero reserved bits");
    }
    Ok(1)
}

fn kinsn_candidate_subprog_starts(insns: &[BpfInsn]) -> anyhow::Result<Vec<usize>> {
    let cfg = CFGAnalysis.run(&BpfProgram::new(insns.to_vec()));
    let mut starts = Vec::with_capacity(cfg.subprogs.len());

    for subprog in cfg.subprogs {
        if subprog.start >= insns.len() {
            anyhow::bail!(
                "subprog start {} is outside candidate instruction length {}",
                subprog.start,
                insns.len()
            );
        }
        starts.push(subprog.start);
    }

    if starts.is_empty() {
        starts.push(0);
    }
    if starts[0] != 0 {
        anyhow::bail!(
            "first subprog starts at candidate pc {}, expected 0",
            starts[0]
        );
    }
    for window in starts.windows(2) {
        if window[0] >= window[1] {
            anyhow::bail!(
                "candidate subprog starts are not strictly increasing: {} then {}",
                window[0],
                window[1]
            );
        }
    }
    Ok(starts)
}

fn is_kinsn_sidecar_insn(insn: &BpfInsn) -> bool {
    insn.code == (BPF_ALU64 | BPF_MOV | BPF_K) && insn.src_reg() == BPF_PSEUDO_KINSN_SIDECAR
}

fn rewrite_func_info_to_subprog_layout(
    records: Option<&mut BtfInfoRecords>,
    subprog_starts: &[usize],
) -> anyhow::Result<()> {
    let Some(records) = records else {
        return Ok(());
    };
    if records.bytes.is_empty() {
        return Ok(());
    }
    if records.rec_size < std::mem::size_of::<u32>() as u32 {
        anyhow::bail!(
            "func_info rec_size {} is too small to hold insn_off",
            records.rec_size
        );
    }
    let rec_size = records.rec_size as usize;
    if !records.bytes.len().is_multiple_of(rec_size) {
        anyhow::bail!(
            "func_info byte length {} is not a multiple of rec_size {}",
            records.bytes.len(),
            records.rec_size
        );
    }
    let record_count = records.bytes.len() / rec_size;
    if record_count != subprog_starts.len() {
        anyhow::bail!(
            "func_info record count {} does not match subprog count {}",
            record_count,
            subprog_starts.len()
        );
    }

    for (record, &pc) in records.bytes.chunks_mut(rec_size).zip(subprog_starts) {
        let pc: u32 = pc
            .try_into()
            .map_err(|_| anyhow::anyhow!("func_info subprog insn_off does not fit u32"))?;
        record[..4].copy_from_slice(&pc.to_le_bytes());
    }
    Ok(())
}

fn valid_line_info_pc(insns: &[BpfInsn], pc: usize) -> bool {
    insns.get(pc).is_some_and(|insn| insn.code != 0)
}

fn remapped_pc(
    label: &str,
    kind: BtfRecordKind,
    old_pc: usize,
    addr_map: &[usize],
    new_len: usize,
) -> anyhow::Result<Option<usize>> {
    let old_len = addr_map
        .len()
        .checked_sub(1)
        .ok_or_else(|| anyhow::anyhow!("{label} remap address map is empty"))?;
    if old_pc >= old_len {
        if kind == BtfRecordKind::Line {
            return Ok(None);
        }
        anyhow::bail!("{label} insn_off {old_pc} is outside old instruction length {old_len}");
    }
    let new_pc = addr_map[old_pc];
    if new_pc >= new_len {
        return Ok(None);
    }
    if kind == BtfRecordKind::Func {
        return Ok(Some(new_pc));
    }
    let next_pc = addr_map[old_pc + 1];
    if next_pc < new_pc {
        anyhow::bail!(
            "{label} remap address map is non-monotonic at old pc {old_pc}: {new_pc} -> {next_pc}"
        );
    }
    Ok((next_pc > new_pc).then_some(new_pc))
}

pub fn map_replacement_range(
    addr_map: &mut [usize],
    old_start: usize,
    old_len: usize,
    new_start: usize,
    new_len: usize,
) {
    debug_assert!(new_len > 0);
    for old_offset in 0..old_len {
        let new_offset = old_offset.min(new_len.saturating_sub(1));
        addr_map[old_start + old_offset] = new_start + new_offset;
    }
}

pub fn kinsn_replacement_subprog_skip_reason(
    insns: &[BpfInsn],
    start_pc: usize,
    old_len: usize,
    replacement_len: usize,
) -> anyhow::Result<Option<String>> {
    if old_len == 0 {
        anyhow::bail!("kinsn replacement site at pc {start_pc} has zero old length");
    }
    if replacement_len == 0 {
        anyhow::bail!("kinsn replacement site at pc {start_pc} has zero replacement length");
    }
    let old_end = start_pc
        .checked_add(old_len)
        .ok_or_else(|| anyhow::anyhow!("kinsn replacement site at pc {start_pc} overflows"))?;
    let replacement_end = start_pc.checked_add(replacement_len).ok_or_else(|| {
        anyhow::anyhow!("kinsn replacement at pc {start_pc} replacement length overflows")
    })?;
    if old_end > insns.len() {
        anyhow::bail!(
            "kinsn replacement site {start_pc}..{old_end} exceeds instruction length {}",
            insns.len()
        );
    }

    let starts = kinsn_candidate_subprog_starts(insns)?;
    let Some(subprog_idx) = starts.iter().rposition(|&start| start <= start_pc) else {
        anyhow::bail!("no subprogram contains kinsn replacement site at pc {start_pc}");
    };
    let subprog_start = starts[subprog_idx];
    let subprog_end = starts.get(subprog_idx + 1).copied().unwrap_or(insns.len());

    if old_end > subprog_end {
        return Ok(Some(format!(
            "kinsn site crosses subprog boundary (site {start_pc}..{old_end}, subprog {subprog_start}..{subprog_end})"
        )));
    }
    if replacement_end > subprog_end {
        return Ok(Some(format!(
            "kinsn replacement crosses subprog boundary (replacement {start_pc}..{replacement_end}, subprog {subprog_start}..{subprog_end})"
        )));
    }
    if starts
        .iter()
        .any(|&subprog| subprog > start_pc && subprog < old_end)
    {
        return Ok(Some(format!(
            "kinsn site contains subprog entry inside replacement range {start_pc}..{old_end}"
        )));
    }

    Ok(kinsn_replacement_tail_call_skip_reason(insns, start_pc))
}

fn kinsn_replacement_tail_call_skip_reason(insns: &[BpfInsn], start_pc: usize) -> Option<String> {
    let mut pc = 0usize;
    while pc < insns.len() {
        let insn = &insns[pc];
        if is_tail_call_insn(insn) {
            return Some(format!(
                "kinsn site in program with tail-call helper (tail call pc {pc}, site pc {start_pc})"
            ));
        }
        pc += insn_width(insn);
    }
    None
}

/// Return the exclusive prefix end before which instruction-count changes must
/// be avoided to preserve tail-call poke descriptor indices during REJIT.
pub fn tail_call_protected_prefix_end(insns: &[BpfInsn]) -> Option<usize> {
    last_tail_call_pc(insns).map(|pc| pc + insn_width(&insns[pc]))
}

fn last_tail_call_pc(insns: &[BpfInsn]) -> Option<usize> {
    let mut last = None;
    let mut pc = 0usize;
    while pc < insns.len() {
        if is_tail_call_insn(&insns[pc]) {
            last = Some(pc);
        }
        pc += insn_width(&insns[pc]);
    }
    last
}

fn is_tail_call_insn(insn: &BpfInsn) -> bool {
    insn.code == (BPF_JMP | BPF_TAIL_CALL)
        || (insn.is_call() && insn.src_reg() == 0 && insn.imm == BPF_FUNC_TAIL_CALL)
}

/// Remove all CFG-unreachable basic blocks from the instruction stream.
pub fn eliminate_unreachable_blocks(insns: &[BpfInsn]) -> Option<(Vec<BpfInsn>, Vec<usize>)> {
    if insns.is_empty() {
        return None;
    }

    let cfg = CFGAnalysis.run(&BpfProgram::new(insns.to_vec()));
    eliminate_unreachable_blocks_with_cfg(insns, &cfg)
}

/// Remove all CFG-unreachable basic blocks from the instruction stream using
/// a caller-provided CFG.
///
/// Subprog entries are only considered reachable if there exists a reachable
/// pseudo-call that targets them. This prevents orphaned subprogs (whose only
/// call site was in a dead block) from surviving and triggering verifier
/// "unreachable insn" errors.
pub fn eliminate_unreachable_blocks_with_cfg(
    insns: &[BpfInsn],
    cfg: &CFGResult,
) -> Option<(Vec<BpfInsn>, Vec<usize>)> {
    if insns.is_empty() || cfg.blocks.is_empty() {
        return None;
    }

    let mut reachable = vec![false; cfg.blocks.len()];
    let mut worklist = Vec::new();

    // Seed with main entry (the first subprog, which always starts at 0).
    if !cfg.subprogs.is_empty() {
        let main_entry_block = cfg.insn_to_block[cfg.subprogs[0].start];
        reachable[main_entry_block] = true;
        worklist.push(main_entry_block);
    }

    // Collect all subprog entry PCs for quick lookup.
    let subprog_entry_pcs: HashSet<usize> = cfg
        .subprogs
        .iter()
        .filter(|s| s.start < insns.len())
        .map(|s| s.start)
        .collect();

    // Iterative reachability: propagate through CFG edges, and when a
    // reachable block contains a pseudo-call, seed the target subprog entry.
    loop {
        // Drain the worklist, propagating through CFG successors.
        while let Some(block_idx) = worklist.pop() {
            for &succ in &cfg.blocks[block_idx].succs {
                if !reachable[succ] {
                    reachable[succ] = true;
                    worklist.push(succ);
                }
            }
        }

        // Find pseudo-calls in reachable blocks that target not-yet-reachable
        // subprog entries.
        let mut found_new = false;
        for (block_idx, block) in cfg.blocks.iter().enumerate() {
            if !reachable[block_idx] {
                continue;
            }
            let mut pc = block.start;
            while pc < block.end {
                let insn = &insns[pc];
                if insn.is_ldimm64_pseudo_func() {
                    let target = (pc as i64 + 1 + insn.imm as i64) as usize;
                    if target < insns.len() && subprog_entry_pcs.contains(&target) {
                        let target_block = cfg.insn_to_block[target];
                        if !reachable[target_block] {
                            reachable[target_block] = true;
                            worklist.push(target_block);
                            found_new = true;
                        }
                    }
                } else if insn.is_call() && insn.src_reg() == 1 {
                    // BPF pseudo-call: target = pc + 1 + imm
                    let target = (pc as i64 + 1 + insn.imm as i64) as usize;
                    if target < insns.len() && subprog_entry_pcs.contains(&target) {
                        let target_block = cfg.insn_to_block[target];
                        if !reachable[target_block] {
                            reachable[target_block] = true;
                            worklist.push(target_block);
                            found_new = true;
                        }
                    }
                }
                pc = if insn.is_ldimm64() { pc + 2 } else { pc + 1 };
            }
        }

        if !found_new {
            break;
        }
    }

    let mut deleted = vec![false; insns.len()];
    for (block_idx, block) in cfg.blocks.iter().enumerate() {
        if reachable[block_idx] {
            continue;
        }
        for slot in &mut deleted[block.start..block.end] {
            *slot = true;
        }
    }

    eliminate_marked_insns(insns, &deleted)
}

/// Remove all `ja +0` no-op instructions from the instruction stream.
pub fn eliminate_nops(insns: &[BpfInsn]) -> Option<(Vec<BpfInsn>, Vec<usize>)> {
    let mut deleted = vec![false; insns.len()];
    let mut pc = 0usize;

    while pc < insns.len() {
        let insn = &insns[pc];
        let width = insn_width(insn);
        if insn.is_ja() && insn.off == 0 {
            for slot in &mut deleted[pc..pc + width] {
                *slot = true;
            }
        }
        pc += width;
    }

    eliminate_marked_insns(insns, &deleted)
}

/// Remove side-effect-free register definitions whose result is dead.
///
/// This runs to a fixed point because deleting one dead definition can expose
/// earlier definitions that were only live through the removed instruction.
pub fn eliminate_dead_register_defs(insns: &[BpfInsn]) -> Option<(Vec<BpfInsn>, Vec<usize>)> {
    if insns.is_empty() {
        return None;
    }

    let mut final_insns = insns.to_vec();
    let mut final_addr_map: Option<Vec<usize>> = None;

    while let Some((cleaned_insns, cleanup_map)) = eliminate_dead_register_defs_once(&final_insns) {
        final_addr_map = Some(match final_addr_map.take() {
            Some(existing) => compose_addr_maps(&existing, &cleanup_map),
            None => cleanup_map,
        });
        final_insns = cleaned_insns;
    }

    final_addr_map.map(|addr_map| (final_insns, addr_map))
}

fn eliminate_dead_register_defs_once(insns: &[BpfInsn]) -> Option<(Vec<BpfInsn>, Vec<usize>)> {
    let liveness = LivenessAnalysis.run(&BpfProgram::new(insns.to_vec()));
    let mut deleted = vec![false; insns.len()];
    let mut pc = 0usize;

    while pc < insns.len() {
        let insn = &insns[pc];
        let width = insn_width(insn);

        if is_removable_dead_def(insn, liveness.live_out.get(pc)) {
            for slot in &mut deleted[pc..pc + width] {
                *slot = true;
            }
        }

        pc += width;
    }

    eliminate_marked_insns(insns, &deleted)
}

fn is_removable_dead_def(insn: &BpfInsn, live_out: Option<&HashSet<u8>>) -> bool {
    let Some(live_out) = live_out else {
        return false;
    };
    let is_self_move = matches!(insn.class(), BPF_ALU | BPF_ALU64)
        && bpf_op(insn.code) == BPF_MOV
        && bpf_src(insn.code) == BPF_X
        && insn.dst_reg() == insn.src_reg();
    if is_self_move {
        return false;
    }

    match insn.class() {
        BPF_ALU | BPF_ALU64 | BPF_LDX => !live_out.contains(&insn.dst_reg()),
        BPF_LD if insn.is_ldimm64() && !insn.is_ldimm64_pseudo_func() => {
            !live_out.contains(&insn.dst_reg())
        }
        _ => false,
    }
}

fn eliminate_marked_insns(
    insns: &[BpfInsn],
    deleted: &[bool],
) -> Option<(Vec<BpfInsn>, Vec<usize>)> {
    if insns.is_empty() || !deleted.iter().any(|&flag| flag) {
        return None;
    }
    debug_assert_eq!(insns.len(), deleted.len());

    let orig_len = insns.len();
    let deleted = normalize_ldimm64_deletions(insns, deleted);
    let mut new_insns = Vec::with_capacity(orig_len);
    let mut addr_map = vec![0usize; orig_len + 1];
    let mut pc = 0usize;

    while pc < orig_len {
        let insn = &insns[pc];
        let width = insn_width(insn);
        let new_pc = new_insns.len();

        if deleted[pc] {
            for j in 0..width {
                addr_map[pc + j] = new_pc;
            }
            pc += width;
            continue;
        }

        addr_map[pc] = new_pc;
        new_insns.push(*insn);
        if width == 2 && pc + 1 < orig_len {
            addr_map[pc + 1] = new_insns.len();
            new_insns.push(insns[pc + 1]);
        }
        pc += width;
    }
    addr_map[orig_len] = new_insns.len();

    fixup_surviving_branches(&mut new_insns, insns, &addr_map, &deleted);
    Some((new_insns, addr_map))
}

fn normalize_ldimm64_deletions(insns: &[BpfInsn], deleted: &[bool]) -> Vec<bool> {
    let mut normalized = deleted.to_vec();
    let mut pc = 0usize;

    while pc < insns.len() {
        let width = insn_width(&insns[pc]);
        let end = (pc + width).min(insns.len());
        if width == 2 && deleted[pc..end].iter().any(|&flag| flag) {
            for slot in &mut normalized[pc..end] {
                *slot = true;
            }
        }
        pc = end;
    }

    normalized
}

fn fixup_surviving_branches(
    new_insns: &mut [BpfInsn],
    old_insns: &[BpfInsn],
    addr_map: &[usize],
    deleted: &[bool],
) {
    let old_n = old_insns.len();
    let mut old_pc = 0usize;

    while old_pc < old_n {
        let insn = &old_insns[old_pc];
        if !deleted[old_pc] {
            if insn.is_ldimm64_pseudo_func() {
                let old_target = (old_pc as i64 + 1 + insn.imm as i64) as usize;
                if old_target < old_n {
                    let new_pc = addr_map[old_pc];
                    let new_target = addr_map[old_target];
                    if new_pc < new_insns.len() && new_insns[new_pc].is_ldimm64_pseudo_func() {
                        let new_imm = new_target as i64 - (new_pc as i64 + 1);
                        new_insns[new_pc].imm = new_imm as i32;
                    }
                }
            } else if insn.is_call() && insn.src_reg() == 1 {
                let old_target = (old_pc as i64 + 1 + insn.imm as i64) as usize;
                if old_target < old_n {
                    let new_pc = addr_map[old_pc];
                    let new_target = addr_map[old_target];
                    if new_pc < new_insns.len() && new_insns[new_pc].is_call() {
                        let new_imm = new_target as i64 - (new_pc as i64 + 1);
                        new_insns[new_pc].imm = new_imm as i32;
                    }
                }
            } else if insn.is_jmp_class() && !insn.is_call() && !insn.is_exit() {
                let old_target = (old_pc as i64 + 1 + insn.off as i64) as usize;
                if old_target <= old_n {
                    let new_pc = addr_map[old_pc];
                    let new_target = addr_map[old_target];
                    if new_pc < new_insns.len()
                        && new_insns[new_pc].is_jmp_class()
                        && !new_insns[new_pc].is_call()
                        && !new_insns[new_pc].is_exit()
                    {
                        let new_off = new_target as i64 - (new_pc as i64 + 1);
                        new_insns[new_pc].off = new_off as i16;
                    }
                }
            }
        }

        old_pc += insn_width(insn);
    }
}

/// Returns the instruction "width" (slot count): 2 for LD_IMM64, 1 for all others.
pub fn insn_width(insn: &BpfInsn) -> usize {
    if insn.is_ldimm64() {
        2
    } else {
        1
    }
}

// ── LD_IMM64 helpers ──────────────────────────────────────────────

/// Emit a two-instruction `LD_IMM64 dst, value` sequence (BPF_LD|BPF_DW|BPF_IMM).
pub fn emit_ldimm64(dst_reg: u8, value: u64) -> Vec<BpfInsn> {
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

// ── Kinsn call emission ────────────────────────────────────────────

/// Emit a packed-ABI kinsn call using a sidecar pseudo-insn immediately
/// before the kinsn CALL. The result register is part of `payload`, so no
/// extra `mov dst, r0` is emitted here.
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

pub fn resolve_kinsn_call_off_for_pass(ctx: &PassContext, pass_name: &str) -> anyhow::Result<i16> {
    ctx.kinsn_call_resolver
        .call_off_for_pass(&ctx.kinsn_registry, pass_name)
}

pub fn resolve_kinsn_call_off_for_target(
    ctx: &PassContext,
    target_name: &str,
) -> anyhow::Result<i16> {
    ctx.kinsn_call_resolver
        .call_off_for_target_name(&ctx.kinsn_registry, target_name)
}
// ── Tests ──────────────────────────────────────────────────────────

#[cfg(test)]
mod tests {
    use super::*;
    use crate::passes::test_helpers::{call_helper, exit_insn, pseudo_call_to};

    fn pseudo_func_ref(dst: u8, imm: i32) -> [BpfInsn; 2] {
        [
            BpfInsn::new(
                BPF_LD | BPF_DW | BPF_IMM,
                BpfInsn::make_regs(dst, BPF_PSEUDO_FUNC),
                0,
                imm,
            ),
            BpfInsn::new(0, 0, 0, 0),
        ]
    }

    fn pseudo_map_value(dst: u8, imm: i32) -> [BpfInsn; 2] {
        [
            BpfInsn::new(
                BPF_LD | BPF_DW | BPF_IMM,
                BpfInsn::make_regs(dst, BPF_PSEUDO_MAP_VALUE),
                0,
                imm,
            ),
            BpfInsn::new(0, 0, 0, 0x1234),
        ]
    }

    #[test]
    fn test_fixup_all_branches_forward_jump() {
        // Old: [0] JA +1  [1] nop  [2] exit
        // New (insert at 1): [0] JA +1  [1] new_insn  [2] nop  [3] exit
        // addr_map: 0->0, 1->2, 2->3, sentinel 3->4
        let old_insns = vec![BpfInsn::ja(1), BpfInsn::nop(), exit_insn()];
        let mut new_insns = vec![
            BpfInsn::ja(1), // will be fixed
            BpfInsn::nop(), // inserted
            BpfInsn::nop(),
            exit_insn(),
        ];
        let addr_map = vec![0, 2, 3, 4];
        fixup_all_branches(&mut new_insns, &old_insns, &addr_map);
        // JA at new_pc=0 should target new_pc=3 (old target was pc=2 -> addr_map[2]=3)
        assert_eq!(new_insns[0].off, 2); // 3 - (0+1) = 2
    }

    #[test]
    fn test_fixup_all_branches_does_not_write_branch_off_into_helper_call() {
        // Old pc 0 is a branch that gets deleted by a rewrite. addr_map[0] then
        // points at the next surviving insn, which happens to be a helper call.
        // Branch fixup must not treat that helper call like a jump and scribble
        // a non-zero off field into its reserved bits.
        let old_insns = vec![BpfInsn::ja(1), BpfInsn::nop(), call_helper(5), exit_insn()];
        let mut new_insns = vec![call_helper(5), exit_insn()];
        let addr_map = vec![0, 0, 0, 1, 2];

        fixup_all_branches(&mut new_insns, &old_insns, &addr_map);

        assert!(new_insns[0].is_call());
        assert_eq!(new_insns[0].src_reg(), 0);
        assert_eq!(new_insns[0].dst_reg(), 0);
        assert_eq!(new_insns[0].off, 0);
        assert_eq!(new_insns[0].imm, 5);
    }

    #[test]
    fn test_fixup_all_branches_does_not_write_deleted_branch_target_into_surviving_branch() {
        let old_insns = vec![
            BpfInsn::ja(1),
            BpfInsn::nop(),
            BpfInsn::ja(1),
            BpfInsn::nop(),
            exit_insn(),
        ];
        let mut new_insns = vec![BpfInsn::ja(1), BpfInsn::nop(), exit_insn()];
        let addr_map = vec![0, 0, 0, 1, 2, 3];

        fixup_all_branches(&mut new_insns, &old_insns, &addr_map);

        assert!(new_insns[0].is_ja());
        assert_eq!(new_insns[0].off, 1);
    }

    #[test]
    fn test_fixup_all_branches_rewrites_pseudo_func_target_after_growth() {
        let callback = pseudo_func_ref(2, 3);
        let old_insns = vec![
            callback[0],
            callback[1],
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
            BpfInsn::mov64_reg(0, 1),
            exit_insn(),
        ];
        let mut new_insns = vec![
            callback[0],
            callback[1],
            BpfInsn::mov64_imm(0, 0),
            exit_insn(),
            BpfInsn::nop(),
            BpfInsn::mov64_reg(0, 1),
            exit_insn(),
        ];
        let addr_map = vec![0, 1, 2, 3, 5, 6, 7];

        fixup_all_branches(&mut new_insns, &old_insns, &addr_map);

        assert!(new_insns[0].is_ldimm64_pseudo_func());
        assert_eq!(new_insns[0].imm, 4);
        assert_eq!(1 + new_insns[0].imm as usize, 5);
    }

    #[test]
    fn test_eliminate_nops_preserves_helper_call_reserved_fields() {
        let insns = vec![BpfInsn::ja(0), call_helper(5), exit_insn()];
        let (new_insns, _addr_map) = eliminate_nops(&insns).expect("nop should be removed");

        assert_eq!(new_insns.len(), 2);
        assert!(new_insns[0].is_call());
        assert_eq!(new_insns[0].src_reg(), 0);
        assert_eq!(new_insns[0].dst_reg(), 0);
        assert_eq!(new_insns[0].off, 0);
        assert_eq!(new_insns[0].imm, 5);
    }

    #[test]
    fn test_eliminate_marked_insns_deletes_ldimm64_when_second_slot_is_marked() {
        let map_value = pseudo_map_value(1, 9);
        let insns = vec![BpfInsn::ja(2), map_value[0], map_value[1], exit_insn()];
        let deleted = vec![false, false, true, false];

        let (new_insns, addr_map) =
            eliminate_marked_insns(&insns, &deleted).expect("LD_IMM64 pair should be deleted");

        assert_eq!(new_insns, vec![BpfInsn::ja(0), exit_insn()]);
        assert_eq!(addr_map[1], 1);
        assert_eq!(addr_map[2], 1);
        assert!(
            !new_insns
                .iter()
                .any(|insn| insn.is_ldimm64() || insn.src_reg() == BPF_PSEUDO_MAP_VALUE),
            "DCE must not leave either half of a PSEUDO_MAP_VALUE LD_IMM64"
        );
    }

    #[test]
    fn test_tail_call_protected_prefix_end_tracks_last_tail_call() {
        let insns = vec![
            BpfInsn::mov64_imm(1, 1),
            call_helper(12),
            BpfInsn::mov64_imm(2, 2),
            call_helper(12),
            exit_insn(),
        ];

        assert_eq!(tail_call_protected_prefix_end(&insns), Some(4));
    }

    #[test]
    fn kinsn_replacement_subprog_check_allows_site_inside_one_subprog() {
        let insns = vec![
            BpfInsn::alu64_imm(BPF_RSH, 2, 8),
            BpfInsn::alu64_imm(BPF_AND, 2, 0xff),
            pseudo_call_to(2, 4),
            exit_insn(),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ];

        let skip = kinsn_replacement_subprog_skip_reason(&insns, 0, 2, 2).unwrap();

        assert_eq!(skip, None);
    }

    #[test]
    fn kinsn_replacement_subprog_check_rejects_pseudo_func_boundary_inside_site() {
        let func_ref = pseudo_func_ref(2, -4);
        let insns = vec![
            BpfInsn::alu64_imm(BPF_RSH, 2, 8),
            BpfInsn::alu64_imm(BPF_AND, 2, 0xff),
            exit_insn(),
            BpfInsn::mov64_imm(0, 0),
            func_ref[0],
            func_ref[1],
            exit_insn(),
        ];

        let skip = kinsn_replacement_subprog_skip_reason(&insns, 0, 2, 2).unwrap();

        assert!(skip
            .as_deref()
            .is_some_and(|reason| reason.contains("subprog boundary")));
    }

    #[test]
    fn kinsn_replacement_subprog_check_rejects_site_before_tail_call() {
        let insns = vec![
            BpfInsn::alu64_imm(BPF_RSH, 2, 8),
            BpfInsn::alu64_imm(BPF_AND, 2, 0xff),
            call_helper(BPF_FUNC_TAIL_CALL),
            exit_insn(),
        ];

        let skip = kinsn_replacement_subprog_skip_reason(&insns, 0, 2, 2).unwrap();

        assert!(skip
            .as_deref()
            .is_some_and(|reason| reason.contains("tail-call helper")));
    }

    #[test]
    fn kinsn_replacement_subprog_check_rejects_site_after_tail_call() {
        let insns = vec![
            call_helper(BPF_FUNC_TAIL_CALL),
            BpfInsn::alu64_imm(BPF_RSH, 2, 8),
            BpfInsn::alu64_imm(BPF_AND, 2, 0xff),
            exit_insn(),
        ];

        let skip = kinsn_replacement_subprog_skip_reason(&insns, 1, 2, 2).unwrap();

        assert!(skip
            .as_deref()
            .is_some_and(|reason| reason.contains("tail-call helper")));
    }

    #[test]
    fn test_eliminate_dead_register_defs_cascades_across_overwrites() {
        let insns = vec![
            BpfInsn::mov64_imm(1, 1),
            BpfInsn::mov64_imm(1, 2),
            BpfInsn::mov64_imm(0, 7),
            exit_insn(),
        ];

        let (new_insns, _addr_map) =
            eliminate_dead_register_defs(&insns).expect("dead defs should be removed");

        assert_eq!(new_insns, vec![BpfInsn::mov64_imm(0, 7), exit_insn(),]);
    }

    #[test]
    fn remap_btf_metadata_drops_deleted_entries_and_shifts_survivors() {
        let mut program = BpfProgram::new(vec![
            BpfInsn::mov64_imm(0, 0),
            BpfInsn::mov64_imm(9, 9),
            BpfInsn::mov64_imm(1, 1),
            BpfInsn::mov64_imm(2, 2),
        ]);
        program.func_info = Some(BtfInfoRecords {
            rec_size: 8,
            bytes: func_btf_record(0, 10),
        });
        program.line_info = Some(BtfInfoRecords {
            rec_size: 16,
            bytes: [
                btf_record(0, 100),
                btf_record(1, 101),
                btf_record(2, 102),
                btf_record(3, 103),
            ]
            .concat(),
        });

        // Old pc 1 was deleted; a new instruction was inserted before old pc 2.
        let addr_map = vec![0, 2, 2, 3, 4];

        remap_btf_metadata(&mut program, &addr_map).unwrap();

        assert_eq!(btf_offsets(program.func_info.as_ref().unwrap()), vec![0]);
        assert_eq!(
            btf_offsets(program.line_info.as_ref().unwrap()),
            vec![0, 2, 3]
        );
        assert_eq!(
            btf_type_ids(program.line_info.as_ref().unwrap()),
            vec![100, 102, 103]
        );
    }

    #[test]
    fn remap_kinsn_btf_metadata_uses_proof_subprog_layout_for_func_info() {
        let memcpy_btf_id = 2000;
        let memcpy_payload = 1 | (2 << 4) | (2 << 40) | (3 << 48);
        let mut program = BpfProgram::new(vec![
            BpfInsn::kinsn_sidecar(memcpy_payload),
            BpfInsn::call_kinsn_with_off(memcpy_btf_id, 1),
            BpfInsn::new(
                BPF_JMP | BPF_CALL,
                BpfInsn::make_regs(0, BPF_PSEUDO_CALL),
                0,
                1,
            ),
            exit_insn(),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ]);
        program.func_info = Some(BtfInfoRecords {
            rec_size: 8,
            bytes: [func_btf_record(0, 10), func_btf_record(999, 11)].concat(),
        });
        program.line_info = Some(BtfInfoRecords {
            rec_size: 16,
            bytes: [btf_record(0, 100), btf_record(999, 104)].concat(),
        });

        let registry = KinsnRegistry {
            memcpy_bulk_btf_id: memcpy_btf_id,
            ..KinsnRegistry::default()
        };

        remap_kinsn_btf_metadata(&mut program, &registry).unwrap();

        assert_eq!(btf_offsets(program.func_info.as_ref().unwrap()), vec![0, 8]);
        assert_eq!(
            btf_type_ids(program.func_info.as_ref().unwrap()),
            vec![10, 11]
        );
        assert!(program.line_info.as_ref().unwrap().bytes.is_empty());
    }

    #[test]
    fn remap_kinsn_btf_metadata_disambiguates_duplicate_btf_ids_by_call_offset() {
        let shared_btf_id = 2000;
        let extract_payload = 2 | (16 << 8) | (12 << 16);
        let mut program = BpfProgram::new(vec![
            BpfInsn::kinsn_sidecar(extract_payload),
            BpfInsn::call_kinsn_with_off(shared_btf_id, 5),
            BpfInsn::new(
                BPF_JMP | BPF_CALL,
                BpfInsn::make_regs(0, BPF_PSEUDO_CALL),
                0,
                1,
            ),
            exit_insn(),
            BpfInsn::mov64_imm(0, 1),
            exit_insn(),
        ]);
        program.func_info = Some(BtfInfoRecords {
            rec_size: 8,
            bytes: [func_btf_record(0, 10), func_btf_record(999, 11)].concat(),
        });

        let mut registry = KinsnRegistry {
            rotate64_btf_id: shared_btf_id,
            extract64_btf_id: shared_btf_id,
            ..KinsnRegistry::default()
        };
        registry
            .target_call_offsets
            .insert("bpf_rotate64".to_string(), 3);
        registry
            .target_call_offsets
            .insert("bpf_extract64".to_string(), 5);

        remap_kinsn_btf_metadata(&mut program, &registry).unwrap();

        assert_eq!(btf_offsets(program.func_info.as_ref().unwrap()), vec![0, 4]);
    }

    #[test]
    fn remap_btf_metadata_rejects_out_of_range_func_info() {
        let mut program = BpfProgram::new(vec![BpfInsn::mov64_imm(0, 0), exit_insn()]);
        program.func_info = Some(BtfInfoRecords {
            rec_size: 8,
            bytes: func_btf_record(2, 10),
        });

        let err = remap_btf_metadata(&mut program, &[0, 1, 2]).unwrap_err();

        assert!(
            err.to_string()
                .contains("func_info insn_off 2 is outside old instruction length 2"),
            "{err:#}"
        );
    }

    fn btf_record(insn_off: u32, type_id: u32) -> Vec<u8> {
        [
            insn_off.to_le_bytes(),
            type_id.to_le_bytes(),
            0u32.to_le_bytes(),
            0u32.to_le_bytes(),
        ]
        .concat()
    }

    fn func_btf_record(insn_off: u32, type_id: u32) -> Vec<u8> {
        [insn_off.to_le_bytes(), type_id.to_le_bytes()].concat()
    }

    fn btf_offsets(records: &BtfInfoRecords) -> Vec<u32> {
        records
            .bytes
            .chunks(records.rec_size as usize)
            .map(|record| u32::from_le_bytes(record[..4].try_into().unwrap()))
            .collect()
    }

    fn btf_type_ids(records: &BtfInfoRecords) -> Vec<u32> {
        records
            .bytes
            .chunks(records.rec_size as usize)
            .map(|record| u32::from_le_bytes(record[4..8].try_into().unwrap()))
            .collect()
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
