use anyhow::{anyhow, bail, Result};
use iced_x86::{
    BlockEncoder, BlockEncoderOptions, BlockEncoderResult, Code, Decoder, DecoderOptions,
    FlowControl, Instruction, InstructionBlock, Mnemonic, OpKind, Register,
};
use object::{Object, ObjectSection, ObjectSymbol, RelocationFlags, RelocationTarget};
use std::collections::{HashMap, HashSet};

use crate::*;

const X86_CPU_NUMBER_HELPER_KEY: &str = "__native_x86_cpu_number";
const X86_THIS_CPU_OFF_HELPER_KEY: &str = "__native_x86_this_cpu_off";
const X86_BPF_MAP_MAX_ENTRIES_OFFSET_KEY: &str = "__native_x86_bpf_map_max_entries_offset";
const X86_BPF_ARRAY_PTRS_OFFSET_KEY: &str = "__native_x86_bpf_array_ptrs_offset";
const X86_BPF_PROG_BPF_FUNC_OFFSET_KEY: &str = "__native_x86_bpf_prog_bpf_func_offset";
const X86_TAIL_CALL_OFFSET_KEY: &str = "__native_x86_tail_call_offset";
const X86_JMP_END_PLACEHOLDER_TARGET: u64 = 0x4000_0000;
const NATIVE_LAB_RELOC_HELPER_CALL_REL32: u32 = 1;
const X86_HELPER_CALL_REL32_SLOT: [u8; 5] = [0xE8, 0, 0, 0, 0];
type SymbolKey = (object::SectionIndex, u64);
type LocalSiteKey = (object::SectionIndex, u64, u64);

fn symbol_key(sym: &SymInfo) -> SymbolKey {
    (sym.section_index, sym.address)
}

fn local_site_key(sym: &SymInfo, local_ip: u64) -> LocalSiteKey {
    (sym.section_index, sym.address, local_ip)
}

fn truncate_bpf_obj_name(name: &str) -> String {
    name.bytes().take(15).map(char::from).collect()
}

fn lookup_site_matches_native_map(spec: &LookupSiteSpec, native_map_name: &str) -> bool {
    let Some(source_map_name) = spec.map_name.as_deref() else {
        return false;
    };
    source_map_name == native_map_name
        || truncate_bpf_obj_name(source_map_name) == truncate_bpf_obj_name(native_map_name)
}

fn update_site_matches_native_map(spec: &UpdateSiteSpec, native_map_name: &str) -> bool {
    let Some(source_map_name) = spec.map_name.as_deref() else {
        return false;
    };
    source_map_name == native_map_name
        || truncate_bpf_obj_name(source_map_name) == truncate_bpf_obj_name(native_map_name)
}

fn tail_call_map_matches_native(tail_call_maps: &HashSet<String>, native_map_name: &str) -> bool {
    if tail_call_maps.contains(native_map_name) {
        return true;
    }
    let native_truncated = truncate_bpf_obj_name(native_map_name);
    tail_call_maps
        .iter()
        .any(|name| truncate_bpf_obj_name(name) == native_truncated)
}

fn lookup_map_spec(
    lookup_maps: &HashMap<String, LookupSiteSpec>,
    native_map_name: &str,
) -> Result<Option<LookupSiteSpec>> {
    if let Some(spec) = lookup_maps.get(native_map_name) {
        return Ok(Some(spec.clone()));
    }

    let native_truncated = truncate_bpf_obj_name(native_map_name);
    let mut match_spec: Option<LookupSiteSpec> = None;
    let mut match_name: Option<&str> = None;
    for (name, spec) in lookup_maps {
        if truncate_bpf_obj_name(name) != native_truncated {
            continue;
        }
        if let Some(existing) = match_name {
            bail!(
                "native map name {native_map_name:?} matches multiple link-plan lookup_maps entries: {existing:?} and {name:?}"
            );
        }
        match_name = Some(name.as_str());
        match_spec = Some(spec.clone());
    }
    Ok(match_spec)
}

fn generic_lookup_site(target_addr: u64, map_name: Option<&str>) -> Option<LookupSiteSpec> {
    if target_addr == 0 {
        return None;
    }
    Some(LookupSiteSpec {
        kind: LookupKind::Call,
        target_addr,
        key_offset: 0,
        max_entries: 0,
        elem_size: 0,
        index_mask: 0,
        value_offset: 0,
        percpu_base_addr: 0,
        map_name: map_name.map(ToOwned::to_owned),
    })
}

fn select_lookup_site(
    lookup_sites: &[LookupSiteSpec],
    lookup_maps: &HashMap<String, LookupSiteSpec>,
    used: &mut [bool],
    native_call_index: usize,
    native_map_name: Option<&str>,
    sym_name: &str,
    generic_target_addr: u64,
) -> Result<(String, Option<usize>, LookupSiteSpec)> {
    if let Some(map_name) = native_map_name {
        if let Some((idx, spec)) = lookup_sites
            .iter()
            .enumerate()
            .find(|(idx, spec)| !used[*idx] && lookup_site_matches_native_map(spec, map_name))
        {
            used[idx] = true;
            return Ok((idx.to_string(), Some(idx), spec.clone()));
        }

        if let Some(spec) = lookup_map_spec(lookup_maps, map_name)? {
            return Ok((format!("map:{map_name}"), None, spec));
        }

        if let Some(spec) = generic_lookup_site(generic_target_addr, Some(map_name)) {
            return Ok((format!("generic:{map_name}"), None, spec));
        }

        bail!(
            "x86 bpf_map_lookup_elem native call {native_call_index} in {sym_name} uses map {map_name:?} but no matching link-plan lookup_sites or lookup_maps metadata exists"
        );
    }

    if let Some((idx, spec)) = lookup_sites.iter().enumerate().find(|(idx, _)| !used[*idx]) {
        used[idx] = true;
        return Ok((idx.to_string(), Some(idx), spec.clone()));
    }

    if let Some(spec) = generic_lookup_site(generic_target_addr, None) {
        return Ok(("generic".to_string(), None, spec));
    }

    bail!(
        "x86 bpf_map_lookup_elem native call {native_call_index} in {sym_name} is missing link-plan lookup_sites metadata"
    );
}

fn select_update_site(
    update_sites: &[UpdateSiteSpec],
    used: &mut [bool],
    native_call_index: usize,
    native_map_name: Option<&str>,
) -> Option<(String, usize)> {
    if let Some(map_name) = native_map_name {
        if let Some((idx, _)) = update_sites
            .iter()
            .enumerate()
            .find(|(idx, spec)| !used[*idx] && update_site_matches_native_map(spec, map_name))
        {
            used[idx] = true;
            return Some((idx.to_string(), idx));
        }
    }

    if native_call_index < update_sites.len() && !used[native_call_index] {
        used[native_call_index] = true;
        return Some((native_call_index.to_string(), native_call_index));
    }

    update_sites
        .iter()
        .enumerate()
        .find(|(idx, _)| !used[*idx])
        .map(|(idx, _)| {
            used[idx] = true;
            (idx.to_string(), idx)
        })
}

pub(super) fn bpf_helper_name_from_id(helper_id: u64) -> Option<&'static str> {
    match helper_id {
        1 => Some("bpf_map_lookup_elem"),
        2 => Some("bpf_map_update_elem"),
        3 => Some("bpf_map_delete_elem"),
        4 => Some("bpf_probe_read_compat"),
        5 => Some("bpf_ktime_get_ns"),
        6 => Some("bpf_trace_printk"),
        7 => Some("bpf_get_prandom_u32"),
        8 => Some("bpf_get_smp_processor_id"),
        9 => Some("bpf_skb_store_bytes"),
        10 => Some("bpf_l3_csum_replace"),
        11 => Some("bpf_l4_csum_replace"),
        12 => Some("bpf_tail_call"),
        13 => Some("bpf_clone_redirect"),
        14 => Some("bpf_get_current_pid_tgid"),
        15 => Some("bpf_get_current_uid_gid"),
        16 => Some("bpf_get_current_comm"),
        17 => Some("bpf_get_cgroup_classid"),
        18 => Some("bpf_skb_vlan_push"),
        19 => Some("bpf_skb_vlan_pop"),
        20 => Some("bpf_skb_get_tunnel_key"),
        21 => Some("bpf_skb_set_tunnel_key"),
        23 => Some("bpf_redirect"),
        24 => Some("bpf_get_route_realm"),
        25 => Some("bpf_perf_event_output"),
        26 => Some("bpf_skb_load_bytes"),
        27 => Some("bpf_get_stackid"),
        28 => Some("bpf_csum_diff"),
        29 => Some("bpf_skb_get_tunnel_opt"),
        30 => Some("bpf_skb_set_tunnel_opt"),
        31 => Some("bpf_skb_change_proto"),
        32 => Some("bpf_skb_change_type"),
        33 => Some("bpf_skb_under_cgroup"),
        34 => Some("bpf_get_hash_recalc"),
        35 => Some("bpf_get_current_task"),
        36 => Some("bpf_probe_write_user"),
        37 => Some("bpf_current_task_under_cgroup"),
        38 => Some("bpf_skb_change_tail"),
        39 => Some("bpf_skb_pull_data"),
        40 => Some("bpf_csum_update"),
        41 => Some("bpf_set_hash_invalid"),
        42 => Some("bpf_get_numa_node_id"),
        43 => Some("bpf_skb_change_head"),
        44 => Some("bpf_xdp_adjust_head"),
        45 => Some("bpf_probe_read_compat_str"),
        46 => Some("bpf_get_socket_cookie"),
        47 => Some("bpf_get_socket_uid"),
        48 => Some("bpf_set_hash"),
        49 => Some("bpf_setsockopt"),
        50 => Some("bpf_skb_adjust_room"),
        51 => Some("bpf_redirect_map"),
        54 => Some("bpf_xdp_adjust_meta"),
        57 => Some("bpf_getsockopt"),
        58 => Some("bpf_override_return"),
        65 => Some("bpf_xdp_adjust_tail"),
        67 => Some("bpf_get_stack"),
        68 => Some("bpf_skb_load_bytes_relative"),
        69 => Some("bpf_fib_lookup"),
        80 => Some("bpf_get_current_cgroup_id"),
        84 => Some("bpf_sk_lookup_tcp"),
        85 => Some("bpf_sk_lookup_udp"),
        86 => Some("bpf_sk_release"),
        87 => Some("bpf_map_push_elem"),
        88 => Some("bpf_map_pop_elem"),
        95 => Some("bpf_sk_fullsock"),
        99 => Some("bpf_skc_lookup_tcp"),
        109 => Some("bpf_send_signal"),
        118 => Some("bpf_jiffies64"),
        122 => Some("bpf_get_netns_cookie"),
        124 => Some("bpf_sk_assign"),
        127 => Some("bpf_seq_write"),
        130 => Some("bpf_ringbuf_output"),
        133 => Some("bpf_ringbuf_discard"),
        134 => Some("bpf_ringbuf_query"),
        148 => Some("bpf_copy_from_user"),
        112 => Some("bpf_probe_read_user"),
        113 => Some("bpf_probe_read_kernel"),
        114 => Some("bpf_probe_read_user_str"),
        115 => Some("bpf_probe_read_kernel_str"),
        125 => Some("bpf_ktime_get_boot_ns"),
        131 => Some("bpf_ringbuf_reserve"),
        132 => Some("bpf_ringbuf_submit"),
        152 => Some("bpf_redirect_neigh"),
        155 => Some("bpf_redirect_peer"),
        158 => Some("bpf_get_current_task_btf"),
        161 => Some("bpf_ima_inode_hash"),
        164 => Some("bpf_for_each_map_elem"),
        173 => Some("bpf_get_func_ip"),
        174 => Some("bpf_get_attach_cookie"),
        175 => Some("bpf_task_pt_regs"),
        181 => Some("bpf_loop"),
        183 => Some("bpf_get_func_arg"),
        184 => Some("bpf_get_func_ret"),
        185 => Some("bpf_get_func_arg_cnt"),
        186 => Some("bpf_get_retval"),
        187 => Some("bpf_set_retval"),
        188 => Some("bpf_xdp_get_buff_len"),
        189 => Some("bpf_xdp_load_bytes"),
        190 => Some("bpf_xdp_store_bytes"),
        193 => Some("bpf_ima_file_hash"),
        195 => Some("bpf_map_lookup_percpu_elem"),
        _ => None,
    }
}

fn build_x86_get_smp_processor_id_inline(
    helper_addrs: &HashMap<String, u64>,
) -> Result<Option<Vec<Instruction>>> {
    let (Some(&cpu_number), Some(&this_cpu_off)) = (
        helper_addrs.get(X86_CPU_NUMBER_HELPER_KEY),
        helper_addrs.get(X86_THIS_CPU_OFF_HELPER_KEY),
    ) else {
        return Ok(None);
    };
    let mut bytes = Vec::new();
    bytes.extend_from_slice(&[0x48, 0xC7, 0xC0]); // mov rax, sign_extend32(&cpu_number)
    bytes.extend_from_slice(&(cpu_number as u32).to_le_bytes());
    bytes.extend_from_slice(&[0x65, 0x48, 0x03, 0x04, 0x25]); // add rax, gs:[this_cpu_off]
    bytes.extend_from_slice(&(this_cpu_off as u32).to_le_bytes());
    bytes.extend_from_slice(&[0x8B, 0x40, 0x00]); // mov eax, [rax]
    Ok(Some(declared_byte_chunks(&bytes)?))
}

fn find_symbol_in_section_at_address(
    elf: &object::File,
    section_index: object::SectionIndex,
    address: u64,
) -> Option<SymInfo> {
    let mut best: Option<SymInfo> = None;
    for sym in elf.symbols().chain(elf.dynamic_symbols()) {
        if matches!(
            sym.kind(),
            object::SymbolKind::Section | object::SymbolKind::File
        ) {
            continue;
        }
        if sym.section_index()? != section_index {
            continue;
        }
        let addr = sym.address();
        let size = sym.size();
        if size == 0 || address < addr || address >= addr + size {
            continue;
        }
        let candidate = SymInfo {
            name: sym.name().ok()?.to_string(),
            address: addr,
            size,
            section_index,
        };
        if candidate.address == address {
            return Some(candidate);
        }
        if best
            .as_ref()
            .map(|current| candidate.size < current.size)
            .unwrap_or(true)
        {
            best = Some(candidate);
        }
    }
    best
}

fn find_text_symbol_in_section_at_address(
    elf: &object::File,
    section_index: object::SectionIndex,
    address: u64,
) -> Option<SymInfo> {
    let mut best: Option<SymInfo> = None;
    for sym in elf.symbols().chain(elf.dynamic_symbols()) {
        if sym.kind() != object::SymbolKind::Text {
            continue;
        }
        if sym.section_index()? != section_index {
            continue;
        }
        let addr = sym.address();
        let size = sym.size();
        if size == 0 || address < addr || address >= addr + size {
            continue;
        }
        let candidate = SymInfo {
            name: sym.name().ok()?.to_string(),
            address: addr,
            size,
            section_index,
        };
        if candidate.address == address {
            return Some(candidate);
        }
        if best
            .as_ref()
            .map(|current| candidate.size < current.size)
            .unwrap_or(true)
        {
            best = Some(candidate);
        }
    }
    best
}

fn find_decoded_call_target(elf: &object::File, caller: &SymInfo, target: u64) -> Option<SymInfo> {
    find_text_symbol_in_section_at_address(elf, caller.section_index, target)
}

fn resolve_x86_plt32_defined_target_addr(
    elf: &object::File,
    reloc: &object::Relocation,
) -> Result<Option<(object::SectionIndex, u64)>> {
    let target_sym_idx = match reloc.target() {
        RelocationTarget::Symbol(idx) => idx,
        _ => return Ok(None),
    };
    let target_sym = elf
        .symbol_by_index(target_sym_idx)
        .with_context(|| format!("PLT32 target symbol {target_sym_idx:?}"))?;
    let Some(section_index) = target_sym.section_index() else {
        return Ok(None);
    };
    let target_addr = i128::from(target_sym.address())
        .checked_add(i128::from(reloc.addend()))
        .and_then(|v| v.checked_add(4))
        .ok_or_else(|| anyhow!("PLT32 target address overflow"))?;
    if target_addr < 0 || target_addr > i128::from(u64::MAX) {
        return Ok(None);
    }
    Ok(Some((section_index, target_addr as u64)))
}

fn resolve_x86_plt32_defined_target(
    elf: &object::File,
    reloc: &object::Relocation,
) -> Result<Option<SymInfo>> {
    let Some((section_index, target_addr)) = resolve_x86_plt32_defined_target_addr(elf, reloc)?
    else {
        return Ok(None);
    };
    Ok(find_symbol_in_section_at_address(
        elf,
        section_index,
        target_addr,
    ))
}

fn resolve_x86_pc32_defined_text_target(
    elf: &object::File,
    reloc: &object::Relocation,
) -> Result<Option<SymInfo>> {
    let target_sym_idx = match reloc.target() {
        RelocationTarget::Symbol(idx) => idx,
        _ => return Ok(None),
    };
    let target_sym = elf
        .symbol_by_index(target_sym_idx)
        .with_context(|| format!("PC32 target symbol {target_sym_idx:?}"))?;
    let Some(section_index) = target_sym.section_index() else {
        return Ok(None);
    };
    let target_section = elf
        .section_by_index(section_index)
        .with_context(|| format!("PC32 target section {section_index:?}"))?;
    let section_name = target_section
        .name()
        .map_err(|e| anyhow!("PC32 target section name: {e}"))?;
    if !section_name.starts_with(".text") {
        return Ok(None);
    }
    let target_addr = i128::from(target_sym.address())
        .checked_add(i128::from(reloc.addend()))
        .and_then(|v| v.checked_add(4))
        .ok_or_else(|| anyhow!("PC32 target address overflow"))?;
    if target_addr < 0 || target_addr > i128::from(u64::MAX) {
        return Ok(None);
    }
    Ok(find_text_symbol_in_section_at_address(
        elf,
        section_index,
        target_addr as u64,
    ))
}

fn discover_reloc_reachable(
    elf: &object::File,
    sym: &SymInfo,
    included: &mut Vec<SymInfo>,
    seen: &mut HashSet<SymbolKey>,
    queue: &mut Vec<SymInfo>,
) -> Result<()> {
    let section = elf
        .section_by_index(sym.section_index)
        .with_context(|| format!("section {:?}", sym.section_index))?;
    let bytes = read_symbol_bytes(elf, sym)?;
    for (reloc_offset, reloc) in section.relocations() {
        if reloc_offset < sym.address || reloc_offset >= sym.address + sym.size {
            continue;
        }
        let r_type = match reloc.flags() {
            RelocationFlags::Elf { r_type } => r_type,
            _ => continue,
        };
        let target = match r_type {
            4 => {
                let local_patch_off = reloc_offset - sym.address;
                let Some(opcode_local_off) = local_patch_off.checked_sub(1) else {
                    continue;
                };
                if bytes.get(opcode_local_off as usize) != Some(&0xE8) {
                    continue;
                }
                resolve_x86_plt32_defined_target(elf, &reloc)?
            }
            2 => resolve_x86_pc32_defined_text_target(elf, &reloc)?,
            _ => None,
        };
        let Some(target) = target else {
            continue;
        };
        let key = symbol_key(&target);
        if seen.insert(key) {
            included.push(target.clone());
            queue.push(target);
        }
    }
    Ok(())
}

fn x86_call_relocation_opcode_offsets(elf: &object::File, sym: &SymInfo) -> Result<HashSet<u64>> {
    let section = elf
        .section_by_index(sym.section_index)
        .with_context(|| format!("section {:?}", sym.section_index))?;
    let bytes = read_symbol_bytes(elf, sym)?;
    let mut out = HashSet::new();
    for (reloc_offset, reloc) in section.relocations() {
        if reloc_offset < sym.address || reloc_offset >= sym.address + sym.size {
            continue;
        }
        let RelocationFlags::Elf { r_type } = reloc.flags() else {
            continue;
        };
        if r_type != 4 {
            continue;
        }
        let local_patch_off = reloc_offset - sym.address;
        let Some(opcode_local_off) = local_patch_off.checked_sub(1) else {
            continue;
        };
        if bytes.get(opcode_local_off as usize) == Some(&0xE8) {
            out.insert(opcode_local_off);
        }
    }
    Ok(out)
}

pub(super) fn discover_reachable(elf: &object::File, entry: &SymInfo) -> Result<Vec<SymInfo>> {
    let mut included: Vec<SymInfo> = vec![entry.clone()];
    let mut seen: HashSet<SymbolKey> = [symbol_key(entry)].into_iter().collect();
    let mut queue: Vec<SymInfo> = vec![entry.clone()];

    while let Some(sym) = queue.pop() {
        let bytes = read_symbol_bytes(elf, &sym)?;
        let call_relocation_opcode_offsets = x86_call_relocation_opcode_offsets(elf, &sym)?;
        let mut decoder = Decoder::with_ip(64, &bytes, sym.address, DecoderOptions::NONE);
        while decoder.can_decode() {
            let insn = decoder.decode();
            if insn.is_invalid() {
                bail!("iced bailed decoding {} at IP {:#x}", sym.name, insn.ip());
            }
            if matches!(insn.flow_control(), FlowControl::Call) {
                if call_relocation_opcode_offsets.contains(&(insn.ip() - sym.address)) {
                    continue;
                }
                let target = insn.near_branch_target();
                if target == 0 {
                    continue;
                }
                let called = find_decoded_call_target(elf, &sym, target).ok_or_else(|| {
                    anyhow!(
                        "{} calls {:#x} but no symbol covers that address",
                        sym.name,
                        target
                    )
                })?;
                let key = symbol_key(&called);
                if !seen.contains(&key) {
                    seen.insert(key);
                    included.push(called.clone());
                    queue.push(called);
                }
            }
        }
        discover_reloc_reachable(elf, &sym, &mut included, &mut seen, &mut queue)?;
    }
    Ok(included)
}

#[derive(Clone)]
enum PatchKind {
    /// Rewritten RET in the entry function: disp targets end-of-blob.
    JmpEnd,
    /// CALL rel32 to a discovered symbol: disp targets that symbol's new
    /// global offset in the blob.
    Call { target_symbol_key: SymbolKey },
    /// `call rel32` placeholder for a kernel helper/map target. The module
    /// must patch the rel32 displacement after the blob lands in executable
    /// memory.
    HelperCallRel32 { target_addr: u64 },
    /// Rewritten `mov reg, [rip+GOT]` against a map symbol. The runner
    /// patches the immediate field with the live kernel map pointer.
    MapImmediate { name: String, imm_offset: usize },
}

struct PatchInfo {
    global_offset: usize,
    kind: PatchKind,
}
struct SymbolLayout {
    sym: SymInfo,
    base_in_blob: usize,
    /// Local-IP-space (i.e. byte offset within the symbol's source bytes)
    /// of each decoded instruction that survived (alignment NOPs are
    /// dropped, RETs are replaced -- but the placeholder JMP keeps the
    /// original RET's local IP).
    insn_local_ip: Vec<u64>,
    /// Offset of each surviving instruction's first byte within this
    /// symbol's encoded slice, as reported by iced after encoding.
    new_offset_in_sym: Vec<u32>,
}
fn push_x86_synthetic(
    local: &mut Vec<Instruction>,
    kinds: &mut Vec<Option<PatchKind>>,
    insn_local_ip: &mut Vec<u64>,
    next_ip: &mut u64,
    mut insn: Instruction,
) -> Result<()> {
    let len = u64::try_from(insn.len()).map_err(|_| anyhow!("instruction length overflow"))?;
    insn.set_ip(*next_ip);
    *next_ip = next_ip
        .checked_add(len.max(1))
        .ok_or_else(|| anyhow!("synthetic x86 instruction IP overflow"))?;
    local.push(insn);
    kinds.push(None);
    insn_local_ip.push(u64::MAX);
    Ok(())
}

fn push_x86_replacement(
    local: &mut Vec<Instruction>,
    kinds: &mut Vec<Option<PatchKind>>,
    insn_local_ip: &mut Vec<u64>,
    local_ip: u64,
    mut insn: Instruction,
    kind: Option<PatchKind>,
) {
    insn.set_ip(local_ip);
    local.push(insn);
    kinds.push(kind);
    insn_local_ip.push(local_ip);
}

fn x86_new_offset_for_local_target(
    sym_name: &str,
    sym_size: u64,
    insn_local_ip: &[u64],
    new_offsets: &[u32],
    encoded_len: usize,
    target: u64,
) -> Result<usize> {
    if target == sym_size {
        return Ok(encoded_len);
    }
    if target > sym_size {
        bail!("x86 branch target {target:#x} in {sym_name} exceeds symbol size {sym_size:#x}");
    }
    let Some((idx, _)) = insn_local_ip
        .iter()
        .enumerate()
        .filter(|(_, &ip)| ip != u64::MAX && ip >= target)
        .min_by_key(|(_, &ip)| ip)
    else {
        bail!("x86 branch target {target:#x} in {sym_name} has no surviving instruction");
    };
    let off = *new_offsets
        .get(idx)
        .ok_or_else(|| anyhow!("missing encoded offset for branch target in {sym_name}"))?;
    if off == u32::MAX {
        bail!("rewritten branch target instruction in {sym_name} has no stable offset");
    }
    Ok(off as usize)
}

fn x86_local_branch_target_needs_remap(
    sym_size: u64,
    local: &[Instruction],
    insn_local_ip: &[u64],
) -> bool {
    let surviving_targets: HashSet<u64> = insn_local_ip
        .iter()
        .copied()
        .filter(|ip| *ip != u64::MAX)
        .collect();
    local.iter().any(|insn| {
        if !matches!(
            insn.flow_control(),
            FlowControl::UnconditionalBranch | FlowControl::ConditionalBranch
        ) {
            return false;
        }
        let target = insn.near_branch_target();
        target <= sym_size && target != sym_size && !surviving_targets.contains(&target)
    })
}

fn encode_x86_remapped_local_block(
    sym_name: &str,
    sym_size: u64,
    local: &[Instruction],
    insn_local_ip: &[u64],
    first_err: Option<anyhow::Error>,
) -> Result<BlockEncoderResult> {
    let mut widened = local.to_vec();
    for insn in &mut widened {
        if matches!(
            insn.flow_control(),
            FlowControl::UnconditionalBranch | FlowControl::ConditionalBranch
        ) {
            insn.as_near_branch();
        }
    }

    let no_fix_opts = BlockEncoderOptions::RETURN_NEW_INSTRUCTION_OFFSETS
        | BlockEncoderOptions::DONT_FIX_BRANCHES;
    let dry = BlockEncoder::encode(64, InstructionBlock::new(&widened, 0), no_fix_opts).map_err(
        |fallback_err| match &first_err {
            Some(first_err) => anyhow!(
                "iced BlockEncoder failed for {sym_name}: {first_err:?}; \
                 near-branch layout fallback also failed: {fallback_err:?}"
            ),
            None => anyhow!(
                "iced BlockEncoder near-branch layout pass failed for {sym_name}: {fallback_err:?}"
            ),
        },
    )?;

    for insn in &mut widened {
        if !matches!(
            insn.flow_control(),
            FlowControl::UnconditionalBranch | FlowControl::ConditionalBranch
        ) {
            continue;
        }
        let target = insn.near_branch_target();
        if target == X86_JMP_END_PLACEHOLDER_TARGET {
            continue;
        }
        if target <= sym_size {
            let new_target = x86_new_offset_for_local_target(
                sym_name,
                sym_size,
                insn_local_ip,
                &dry.new_instruction_offsets,
                dry.code_buffer.len(),
                target,
            )?;
            insn.set_near_branch64(new_target as u64);
        }
    }

    for (idx, insn) in widened.iter_mut().enumerate() {
        let off = *dry
            .new_instruction_offsets
            .get(idx)
            .ok_or_else(|| anyhow!("missing dry-run offset for instruction {idx} in {sym_name}"))?;
        if off == u32::MAX {
            bail!("dry-run instruction {idx} in {sym_name} has no stable offset");
        }
        insn.set_ip(u64::from(off));
    }

    BlockEncoder::encode(64, InstructionBlock::new(&widened, 0), no_fix_opts).map_err(
        |fallback_err| match &first_err {
            Some(first_err) => anyhow!(
                "iced BlockEncoder failed for {sym_name}: {first_err:?}; \
                 near-branch fallback also failed: {fallback_err:?}"
            ),
            None => anyhow!(
                "iced BlockEncoder near-branch encode failed for {sym_name}: {fallback_err:?}"
            ),
        },
    )
}

fn encode_x86_local_block(
    sym_name: &str,
    sym_size: u64,
    local: &[Instruction],
    insn_local_ip: &[u64],
) -> Result<BlockEncoderResult> {
    if x86_local_branch_target_needs_remap(sym_size, local, insn_local_ip) {
        return encode_x86_remapped_local_block(sym_name, sym_size, local, insn_local_ip, None);
    }

    let block = InstructionBlock::new(local, 0);
    let opts = BlockEncoderOptions::RETURN_NEW_INSTRUCTION_OFFSETS;
    match BlockEncoder::encode(64, block, opts) {
        Ok(encoded) => Ok(encoded),
        Err(first_err) => encode_x86_remapped_local_block(
            sym_name,
            sym_size,
            local,
            insn_local_ip,
            Some(anyhow!("{first_err:?}")),
        ),
    }
}

/// Pre-scan ELF .rela.text relocations to find the *byte offset* of each
/// helper call site inside each included symbol. Keyed by
/// `(section, symbol_address, local_call_opcode_offset)` so the decode loop can
/// look up "is the call I'm about to push a known helper?" in O(1).
///
/// For PLT32 (r_type=4, `e8 dd dd dd dd`) the opcode is `0xe8` at
/// `reloc_offset - 1`. For GOTPCREL/GOTPCRELX/REX_GOTPCRELX (9/41/42,
/// `ff 15 dd dd dd dd`) the call begins at `reloc_offset - 2`. We treat
/// the *call's first byte* as the canonical local key in both cases so
/// the lookup is uniform.
fn scan_helper_calls(
    elf: &object::File,
    included: &[SymInfo],
) -> Result<HashMap<LocalSiteKey, String>> {
    let mut out: HashMap<LocalSiteKey, String> = HashMap::new();
    let mut sections: HashMap<object::SectionIndex, Vec<&SymInfo>> = HashMap::new();
    for s in included {
        sections.entry(s.section_index).or_default().push(s);
    }
    for (section_index, syms) in &sections {
        let section = elf
            .section_by_index(*section_index)
            .with_context(|| format!("section {section_index:?}"))?;
        for (reloc_offset, reloc) in section.relocations() {
            let Some(sym) = syms
                .iter()
                .find(|s| reloc_offset >= s.address && reloc_offset < s.address + s.size)
            else {
                continue;
            };
            let r_type = match reloc.flags() {
                RelocationFlags::Elf { r_type } => r_type,
                _ => continue,
            };
            if r_type == 4 && resolve_x86_plt32_defined_target(elf, &reloc)?.is_some() {
                continue;
            }
            let target_name: String = match reloc.target() {
                RelocationTarget::Symbol(idx) => elf
                    .symbol_by_index(idx)?
                    .name()
                    .map_err(|e| anyhow!("reloc target symbol name: {e}"))?
                    .to_string(),
                _ => continue,
            };
            let local_opcode_off = match r_type {
                4 => reloc_offset.checked_sub(1),
                9 | 41 | 42 => reloc_offset.checked_sub(2),
                _ => None,
            };
            let Some(loc) = local_opcode_off else {
                continue;
            };
            // Only call-class relocs map to "call to helper"; mov-class
            // GOTPCREL refs against maps also use 9/41/42 but the byte
            // at reloc_offset-2 is the mov's REX (0x48/0x49), not
            // `ff 15`. Filter by that. We can read the section data to
            // check.
            // For our purpose we only need to flag bpf_map_lookup_elem,
            // which is always a call site; mov-class refs against the
            // *same* name would be unusual. Filter conservatively by
            // verifying the byte at `loc..=loc+1` matches a call
            // opcode -- but the section bytes aren't trivially
            // available here. Cheap alternative: trust the r_type
            // classification (`4`=PLT32 is always call; `9/41/42` is
            // call only for `-fno-plt` -emitted callsites where the
            // first two bytes are `ff 15`). We re-check at decode time
            // anyway.
            let key = local_site_key(sym, loc - sym.address);
            out.entry(key).or_insert(target_name);
        }
    }
    Ok(out)
}

fn x86_mov_imm_to_gpr64(insn: &Instruction) -> Option<(Register, u64)> {
    if insn.mnemonic() != Mnemonic::Mov
        || insn.op_count() < 2
        || insn.op0_kind() != OpKind::Register
    {
        return None;
    }
    let reg = x86_gpr64_family(insn.op0_register())?;
    let imm = insn.try_immediate(1).ok()?;
    Some((reg, imm))
}

fn x86_mov_gpr64_to_gpr64(insn: &Instruction) -> Option<(Register, Register)> {
    if insn.mnemonic() != Mnemonic::Mov
        || insn.op_count() < 2
        || insn.op0_kind() != OpKind::Register
        || insn.op1_kind() != OpKind::Register
    {
        return None;
    }
    let dst = x86_gpr64_family(insn.op0_register())?;
    let src = x86_gpr64_family(insn.op1_register())?;
    Some((dst, src))
}

fn clear_x86_call_clobbered_registers<V>(registers: &mut HashMap<Register, V>) {
    for reg in [
        Register::RAX,
        Register::RCX,
        Register::RDX,
        Register::RSI,
        Register::RDI,
        Register::R8,
        Register::R9,
        Register::R10,
        Register::R11,
    ] {
        registers.remove(&reg);
    }
}

fn x86_lookahead_indirect_call_uses_register(
    bytes: &[u8],
    next_ip: u64,
    sym_addr: u64,
    reg: Register,
) -> Option<Register> {
    let start = usize::try_from(next_ip.checked_sub(sym_addr)?).ok()?;
    if start >= bytes.len() {
        return None;
    }
    let mut decoder = Decoder::with_ip(64, &bytes[start..], next_ip, DecoderOptions::NONE);
    while decoder.can_decode() {
        let next = decoder.decode();
        if next.is_invalid() {
            return None;
        }
        if is_alignment_nop(&next) {
            continue;
        }
        if x86_indirect_call_register(&next) == Some(reg) {
            return Some(reg);
        }
        if matches!(
            next.flow_control(),
            FlowControl::Call
                | FlowControl::IndirectCall
                | FlowControl::Return
                | FlowControl::UnconditionalBranch
                | FlowControl::ConditionalBranch
                | FlowControl::IndirectBranch
                | FlowControl::Interrupt
                | FlowControl::XbeginXabortXend
                | FlowControl::Exception
        ) {
            return None;
        }
        if x86_written_gpr_family(&next) == Some(reg) {
            return None;
        }
    }
    None
}

fn x86_immediate_helper_load_before_call(
    bytes: &[u8],
    sym_addr: u64,
    local_ip: u64,
    insn: &Instruction,
) -> Option<(Register, u64)> {
    let (reg, helper_id) = x86_mov_imm_to_gpr64(insn)?;
    if helper_id > 255 {
        return None;
    }
    let insn_len = u64::try_from(insn.len()).ok()?;
    let next_ip = sym_addr.checked_add(local_ip)?.checked_add(insn_len)?;
    if x86_lookahead_indirect_call_uses_register(bytes, next_ip, sym_addr, reg) == Some(reg) {
        Some((reg, helper_id))
    } else {
        None
    }
}

fn x86_known_helper_id_load(insn: &Instruction) -> Option<(Register, u64)> {
    let (reg, helper_id) = x86_mov_imm_to_gpr64(insn)?;
    bpf_helper_name_from_id(helper_id)?;
    Some((reg, helper_id))
}

fn x86_symbol_has_immediate_helper_id(bytes: &[u8], sym_addr: u64, helper_id: u64) -> Result<bool> {
    let mut decoder = Decoder::with_ip(64, bytes, sym_addr, DecoderOptions::NONE);
    while decoder.can_decode() {
        let insn = decoder.decode();
        if insn.is_invalid() {
            bail!(
                "iced bailed while scanning x86 helper ids at IP {:#x}",
                insn.ip()
            );
        }
        if is_alignment_nop(&insn) {
            continue;
        }
        let local_ip = insn.ip() - sym_addr;
        if let Some((_, seen)) =
            x86_immediate_helper_load_before_call(bytes, sym_addr, local_ip, &insn)
        {
            if seen == helper_id {
                return Ok(true);
            }
        }
    }
    Ok(false)
}

fn scan_x86_got_relocations(
    elf: &object::File,
    included: &[SymInfo],
) -> Result<HashMap<LocalSiteKey, String>> {
    let mut out = HashMap::new();
    let mut sections: HashMap<object::SectionIndex, Vec<&SymInfo>> = HashMap::new();
    for sym in included {
        sections.entry(sym.section_index).or_default().push(sym);
    }
    for (section_index, syms) in sections {
        let section = elf
            .section_by_index(section_index)
            .with_context(|| format!("section {section_index:?}"))?;
        for (reloc_offset, reloc) in section.relocations() {
            let Some(sym) = syms
                .iter()
                .find(|s| reloc_offset >= s.address && reloc_offset < s.address + s.size)
            else {
                continue;
            };
            let r_type = match reloc.flags() {
                RelocationFlags::Elf { r_type } => r_type,
                _ => continue,
            };
            if !matches!(r_type, 9 | 41 | 42) {
                continue;
            }
            let target_name = match reloc.target() {
                RelocationTarget::Symbol(idx) => elf
                    .symbol_by_index(idx)?
                    .name()
                    .map_err(|e| anyhow!("reloc target symbol name: {e}"))?
                    .to_string(),
                _ => continue,
            };
            out.insert(local_site_key(sym, reloc_offset - sym.address), target_name);
        }
    }
    Ok(out)
}

fn scan_x86_pc_relative_relocations(
    elf: &object::File,
    included: &[SymInfo],
) -> Result<HashSet<LocalSiteKey>> {
    let mut out: HashSet<LocalSiteKey> = HashSet::new();
    let mut sections: HashMap<object::SectionIndex, Vec<&SymInfo>> = HashMap::new();
    for s in included {
        sections.entry(s.section_index).or_default().push(s);
    }
    for (section_index, syms) in &sections {
        let section = elf
            .section_by_index(*section_index)
            .with_context(|| format!("section {section_index:?}"))?;
        for (reloc_offset, reloc) in section.relocations() {
            let Some(sym) = syms
                .iter()
                .find(|s| reloc_offset >= s.address && reloc_offset < s.address + s.size)
            else {
                continue;
            };
            let r_type = match reloc.flags() {
                RelocationFlags::Elf { r_type } => r_type,
                _ => continue,
            };
            if matches!(r_type, 2 | 4 | 9 | 41 | 42) {
                out.insert(local_site_key(sym, reloc_offset - sym.address));
            }
        }
    }
    Ok(out)
}

pub(super) fn rewrite_x86(
    elf: &object::File,
    entry: &SymInfo,
    included: &[SymInfo],
    helper_addrs: &HashMap<String, u64>,
    map_addrs: &HashMap<String, u64>,
    tail_call_maps: &HashSet<String>,
    tail_call_sites: &[TailCallSiteSpec],
    lookup_sites: &[LookupSiteSpec],
    lookup_maps: &HashMap<String, LookupSiteSpec>,
    update_sites: &[UpdateSiteSpec],
    proof_mode: bool,
    show: bool,
) -> Result<RewriteResult> {
    let included_ranges: Vec<(u64, u64)> = included
        .iter()
        .map(|s| (s.address, s.address + s.size))
        .collect();

    let helper_call_sites = scan_helper_calls(elf, included)?;
    let got_relocations = scan_x86_got_relocations(elf, included)?;
    let pc_relative_relocations = scan_x86_pc_relative_relocations(elf, included)?;
    let proof_input = elf.section_by_name(".native_link_abi").is_some();
    let proof_entry_end_target = if !proof_mode && proof_input {
        included.iter().map(|sym| sym.address + sym.size).max()
    } else {
        None
    };
    let proof_callee_saved_mask = if !proof_mode && proof_input {
        Some(read_x86_proof_callee_saved_mask(elf)?)
    } else {
        None
    };

    let mut sym_global_offset: HashMap<SymbolKey, usize> = HashMap::new();
    let mut blob: Vec<u8> = Vec::new();
    let mut patches: Vec<PatchInfo> = Vec::new();
    let mut layouts: Vec<SymbolLayout> = Vec::new();
    let mut callee_saved_mask: u8 = proof_callee_saved_mask.unwrap_or(0);
    // For each `bpf_map_lookup_elem` call site encountered in
    // reachable-symbol byte order, record (symbol_addr, local_call_offset)
    // -> selected spec. Filled during the decode loop; consumed by
    // apply_elf_relocations to route each call to its own dedicated
    // literal-pool entry holding the per-site target address.
    let mut lookup_call_specs: HashMap<LocalSiteKey, LookupSiteSpec> = HashMap::new();
    let mut lookup_call_counter: usize = 0;
    let mut lookup_site_used = vec![false; lookup_sites.len()];
    let map_lookup_helper_addr = helper_addrs
        .get("bpf_map_lookup_elem")
        .copied()
        .unwrap_or(0);
    let mut update_call_counter: usize = 0;
    let mut update_site_used = vec![false; update_sites.len()];
    let mut tail_call_counter: usize = 0;
    let mut resolved_helper_call_sites: HashSet<LocalSiteKey> = HashSet::new();
    let mut resolved_got_relocations: HashSet<LocalSiteKey> = HashSet::new();

    for sym in included {
        let is_entry = symbol_key(sym) == symbol_key(entry);
        let bytes = read_symbol_bytes(elf, sym)?;
        let entry_abi_strip = if is_entry {
            let entry_has_tail_call = x86_symbol_has_immediate_helper_id(&bytes, sym.address, 12)?
                || helper_call_sites.iter().any(|(key, name)| {
                    key.0 == sym.section_index && key.1 == sym.address && name == "bpf_tail_call"
                });
            let proof_return_jmp_target = if !proof_mode && proof_input {
                proof_entry_end_target
            } else {
                None
            };
            plan_x86_entry_abi_strip(
                &bytes,
                sym.address,
                entry_has_tail_call,
                proof_return_jmp_target,
                !proof_mode && proof_input,
            )?
        } else {
            X86EntryAbiStrip::default()
        };
        if is_entry && proof_callee_saved_mask.is_none() {
            callee_saved_mask = entry_abi_strip.callee_saved_mask;
        }
        // Decode at the symbol's original vaddr so insn.near_branch_target()
        // is meaningful in the ELF address space and we can identify
        // inter-symbol call targets. Below we re-anchor each instruction
        // to a per-symbol IP=0 layout before encoding.
        let mut decoder = Decoder::with_ip(64, &bytes, sym.address, DecoderOptions::NONE);
        let mut helper_got_registers: HashMap<Register, String> = HashMap::new();
        let mut helper_imm_registers: HashMap<Register, u64> = HashMap::new();
        let mut map_symbol_registers: HashMap<Register, String> = HashMap::new();
        let mut immediate_registers: HashMap<Register, u64> = HashMap::new();

        // Side table: per-entry patch kind, paired with each kept Instruction
        // in the symbol-local stream. `insn_local_ip` records the byte
        // offset (relative to the symbol start) where each kept
        // instruction originally lived; ELF relocations are recorded in
        // this same coordinate space.
        let mut local: Vec<Instruction> = Vec::new();
        let mut kinds: Vec<Option<PatchKind>> = Vec::new();
        let mut insn_local_ip: Vec<u64> = Vec::new();
        let mut next_synthetic_ip = sym
            .size
            .checked_add(0x1000)
            .ok_or_else(|| anyhow!("synthetic x86 IP base overflow for {}", sym.name))?;

        while decoder.can_decode() {
            let mut insn = decoder.decode();
            if insn.is_invalid() {
                bail!("iced bailed decoding {} at IP {:#x}", sym.name, insn.ip());
            }
            if is_alignment_nop(&insn) {
                continue;
            }
            let local_ip = insn.ip() - sym.address;
            let site_key = local_site_key(sym, local_ip);

            if is_entry && entry_abi_strip.drop_local_ips.contains(&local_ip) {
                continue;
            }
            if is_entry {
                remap_x86_entry_registers(&mut insn, &entry_abi_strip.register_renames)?;
            }

            let mut helper_imm_load_reg = None;
            if let Some((reg, helper_id)) =
                x86_immediate_helper_load_before_call(&bytes, sym.address, local_ip, &insn)
            {
                helper_imm_registers.insert(reg, helper_id);
                helper_imm_load_reg = Some(reg);
                if !proof_mode {
                    continue;
                }
            } else if let Some((reg, helper_id)) = x86_known_helper_id_load(&insn) {
                helper_imm_registers.insert(reg, helper_id);
                helper_imm_load_reg = Some(reg);
            }

            let mut helper_got_load_reg = None;
            if insn.mnemonic() == Mnemonic::Mov
                && insn.op_count() >= 2
                && insn.op0_kind() == OpKind::Register
                && insn.op1_kind() == OpKind::Memory
                && insn.is_ip_rel_memory_operand()
            {
                let insn_len = u64::try_from(insn.len())
                    .map_err(|_| anyhow!("x86 instruction length overflow"))?;
                if insn_len >= 4 {
                    let local_patch_off = local_ip + insn_len - 4;
                    let patch_key = local_site_key(sym, local_patch_off);
                    if let Some(target_name) = got_relocations.get(&patch_key) {
                        let dst = insn.op0_register();
                        if !proof_mode && map_addrs.contains_key(target_name) {
                            let dst_family = x86_gpr64_family(dst).ok_or_else(|| {
                                anyhow!(
                                    "x86 map GOT load for {} uses unsupported register {:?}",
                                    target_name,
                                    dst
                                )
                            })?;
                            let movabs = build_x86_movabs_reg(dst, 0)?;
                            push_x86_replacement(
                                &mut local,
                                &mut kinds,
                                &mut insn_local_ip,
                                local_ip,
                                movabs,
                                Some(PatchKind::MapImmediate {
                                    name: target_name.clone(),
                                    imm_offset: 2,
                                }),
                            );
                            map_symbol_registers.insert(dst_family, target_name.clone());
                            resolved_got_relocations.insert(patch_key);
                            continue;
                        }
                        if target_name.starts_with("bpf_") || helper_addrs.contains_key(target_name)
                        {
                            let dst_family = x86_gpr64_family(dst).ok_or_else(|| {
                                anyhow!(
                                    "x86 helper GOT load for {} uses unsupported register {:?}",
                                    target_name,
                                    dst
                                )
                            })?;
                            helper_got_registers.insert(dst_family, target_name.clone());
                            helper_got_load_reg = Some(dst_family);
                            map_symbol_registers.remove(&dst_family);
                            if !proof_mode {
                                resolved_got_relocations.insert(patch_key);
                                continue;
                            }
                        }
                    }
                }
            }

            if !proof_mode {
                validate_no_external_refs(&insn, &included_ranges, |off| {
                    pc_relative_relocations.contains(&local_site_key(sym, local_ip + off))
                })?;
            }

            // Re-anchor to symbol-local IP=0 space.
            insn.set_ip(local_ip);

            // Translate intra-symbol branch targets into the same local
            // space. Inter-symbol calls keep their vaddr-space target
            // because we'll patch the disp32 manually after concat; what
            // matters is that we identify "this is a call to symbol X" by
            // looking up the original vaddr target.
            let mut original_target = insn.near_branch_target();
            if is_entry
                && original_target >= sym.address
                && original_target < sym.address + sym.size
            {
                let target_local = original_target - sym.address;
                if let Some(remapped_local) =
                    entry_abi_strip.branch_target_remaps.get(&target_local)
                {
                    original_target = sym.address + remapped_local;
                    insn.set_near_branch64(original_target);
                }
            }
            let intra_symbol_branch = original_target != 0
                && original_target >= sym.address
                && original_target <= sym.address + sym.size
                && matches!(
                    insn.flow_control(),
                    FlowControl::UnconditionalBranch | FlowControl::ConditionalBranch
                );
            if intra_symbol_branch {
                insn.set_near_branch64(original_target - sym.address);
            }

            if !proof_mode
                && proof_input
                && is_entry
                && insn.mnemonic() == Mnemonic::Jmp
                && (original_target == sym.address + sym.size
                    || Some(original_target) == proof_entry_end_target)
            {
                let mut jmp = Instruction::default();
                jmp.set_code(Code::Jmp_rel32_64);
                jmp.set_op0_kind(OpKind::NearBranch64);
                jmp.set_near_branch64(X86_JMP_END_PLACEHOLDER_TARGET);
                jmp.set_ip(local_ip);
                local.push(jmp);
                kinds.push(Some(PatchKind::JmpEnd));
                insn_local_ip.push(local_ip);
                continue;
            }

            // RET in the entry function -> placeholder Jmp_rel32_64. The
            // target IP is set to a value far enough from the per-symbol
            // layout IP-space [0, sym.size) that iced -- which, with
            // branch-fixing enabled, will SHRINK rel32 to rel8 when the
            // disp fits in i8 -- has to keep the 5-byte rel32 form.
            // The post-encode patcher relies on every JmpEnd site being
            // `e9 dd dd dd dd` so it can rewrite the 4-byte disp; a
            // shrunken `eb rel8` would break that assumption.
            if is_return(&insn) && is_entry {
                let mut jmp = Instruction::default();
                jmp.set_code(Code::Jmp_rel32_64);
                jmp.set_op0_kind(OpKind::NearBranch64);
                jmp.set_near_branch64(X86_JMP_END_PLACEHOLDER_TARGET);
                jmp.set_ip(local_ip);
                local.push(jmp);
                kinds.push(Some(PatchKind::JmpEnd));
                insn_local_ip.push(local_ip);
                continue;
            }

            // Cross-symbol call: a real `call <subprog>` lands exactly at
            // that subprog's first byte (sym.address). Patched post-encode
            // against the symbol's global offset.
            //
            // A `call rel32` whose ELF reloc carries disp32=0 placeholder
            // (PLT32 against a helper) decodes as `call next_ip` -- target
            // falls *inside* the current symbol but is NOT a symbol entry.
            // We must NOT treat those as cross-symbol calls. Some proof
            // objects decode the placeholder as a call to the containing
            // symbol's first byte, so the relocation pre-scan is authoritative.
            if matches!(insn.flow_control(), FlowControl::Call)
                && original_target != 0
                && !helper_call_sites.contains_key(&site_key)
            {
                let target_symbol =
                    find_decoded_call_target(elf, sym, original_target).and_then(|called| {
                        included
                            .iter()
                            .find(|s| symbol_key(s) == symbol_key(&called))
                    });
                if let Some(target_symbol) = target_symbol {
                    let next = local_ip.wrapping_add(5);
                    insn.set_near_branch64(next);
                    local.push(insn);
                    kinds.push(Some(PatchKind::Call {
                        target_symbol_key: symbol_key(target_symbol),
                    }));
                    insn_local_ip.push(local_ip);
                    clear_x86_call_clobbered_registers(&mut map_symbol_registers);
                    continue;
                }
                // Else: keep verbatim. ELF reloc pass handles helpers; any
                // other intra-symbol "call" with non-entry target would be
                // a self-referential placeholder, which the assembler does
                // not normally emit.
            }

            if matches!(
                insn.flow_control(),
                FlowControl::Call | FlowControl::IndirectCall
            ) {
                let call_reg = x86_indirect_call_register(&insn);
                let mut helper_call_name = helper_call_sites.get(&site_key).cloned();
                if helper_call_name.is_none() {
                    if let Some(reg) = call_reg {
                        if let Some(helper_id) = helper_imm_registers.get(&reg).copied() {
                            let name = bpf_helper_name_from_id(helper_id).ok_or_else(|| {
                                anyhow!(
                                    "x86 immediate BPF helper id {} in {} at local offset {:#x} is unsupported",
                                    helper_id,
                                    sym.name,
                                    local_ip
                                )
                            })?;
                            helper_call_name = Some(name.to_string());
                        } else {
                            helper_call_name = helper_got_registers.get(&reg).cloned();
                        }
                    }
                }
                if let Some(name) = helper_call_name {
                    let x86_tail_call_index = immediate_registers
                        .get(&Register::RDX)
                        .copied()
                        .and_then(|v| u32::try_from(v).ok());
                    clear_x86_call_clobbered_registers(&mut helper_imm_registers);
                    clear_x86_call_clobbered_registers(&mut helper_got_registers);
                    clear_x86_call_clobbered_registers(&mut immediate_registers);
                    if proof_mode {
                        local.push(insn);
                        kinds.push(None);
                        insn_local_ip.push(local_ip);
                        clear_x86_call_clobbered_registers(&mut map_symbol_registers);
                        continue;
                    }
                    if name == "bpf_tail_call" {
                        if !is_entry {
                            bail!(
                                "x86 bpf_tail_call in non-entry symbol {} at local offset {:#x} is unsupported",
                                sym.name,
                                local_ip
                            );
                        }
                        let map_name = map_symbol_registers.get(&Register::RSI).ok_or_else(|| {
                            anyhow!(
                                "x86 bpf_tail_call in {} at local offset {:#x} has no tracked rsi prog-array map",
                                sym.name,
                                local_ip
                            )
                        })?;
                        let source_tail_call = tail_call_sites.get(tail_call_counter);
                        if let Some(site) = source_tail_call {
                            if let Some(source_map_name) = &site.map_name {
                                if truncate_bpf_obj_name(source_map_name)
                                    != truncate_bpf_obj_name(map_name)
                                {
                                    bail!(
                                        "x86 bpf_tail_call native call {} in {} at local offset {:#x} uses map {:?}, but source link-plan tail_call_sites map is {:?}",
                                        tail_call_counter,
                                        sym.name,
                                        local_ip,
                                        map_name,
                                        source_map_name
                                    );
                                }
                            }
                        }
                        if !tail_call_map_matches_native(tail_call_maps, map_name) {
                            bail!(
                                "x86 bpf_tail_call in {} at local offset {:#x} uses map {:?}, which is not a link-plan tail_call_maps entry",
                                sym.name,
                                local_ip,
                                map_name
                            );
                        }
                        let source_tail_call_index = source_tail_call.and_then(|site| site.key);
                        if x86_tail_call_index.is_some()
                            && source_tail_call_index.is_some()
                            && x86_tail_call_index != source_tail_call_index
                        {
                            bail!(
                                "x86 bpf_tail_call native call {} in {} at local offset {:#x} has mismatched constant key: native={:?} source={:?}",
                                tail_call_counter,
                                sym.name,
                                local_ip,
                                x86_tail_call_index,
                                source_tail_call_index
                            );
                        }
                        let tail_call_index = source_tail_call_index.or(x86_tail_call_index);
                        let tail_call_max_entries =
                            source_tail_call.and_then(|site| site.max_entries);
                        tail_call_counter += 1;
                        for ib in build_x86_tail_call_inline(
                            helper_addrs,
                            callee_saved_mask,
                            &entry_abi_strip.tail_call_cleanup_bytes,
                            entry_abi_strip.tail_call_bpf_rbp_rsp_offset,
                            entry_abi_strip.tail_call_bpf_rbp_is_live,
                            tail_call_index,
                            tail_call_max_entries,
                        )? {
                            push_x86_synthetic(
                                &mut local,
                                &mut kinds,
                                &mut insn_local_ip,
                                &mut next_synthetic_ip,
                                ib,
                            )?;
                        }
                        resolved_helper_call_sites.insert(site_key);
                        clear_x86_call_clobbered_registers(&mut map_symbol_registers);
                        continue;
                    }
                    if name == "bpf_get_smp_processor_id" {
                        if let Some(inline) = build_x86_get_smp_processor_id_inline(helper_addrs)? {
                            for ib in inline {
                                push_x86_synthetic(
                                    &mut local,
                                    &mut kinds,
                                    &mut insn_local_ip,
                                    &mut next_synthetic_ip,
                                    ib,
                                )?;
                            }
                            resolved_helper_call_sites.insert(site_key);
                            clear_x86_call_clobbered_registers(&mut map_symbol_registers);
                            continue;
                        }
                    }

                    if name == "bpf_map_lookup_elem" {
                        let native_call_index = lookup_call_counter;
                        lookup_call_counter += 1;
                        let native_map_name =
                            map_symbol_registers.get(&Register::RDI).map(String::as_str);
                        let (site_label, _site_index, spec) = select_lookup_site(
                            lookup_sites,
                            lookup_maps,
                            &mut lookup_site_used,
                            native_call_index,
                            native_map_name,
                            &sym.name,
                            map_lookup_helper_addr,
                        )?;
                        lookup_call_specs.insert(site_key, spec.clone());
                        match spec.kind {
                            LookupKind::Array | LookupKind::PerCpuArray => {
                                for ib in build_x86_array_lookup(&spec)? {
                                    push_x86_synthetic(
                                        &mut local,
                                        &mut kinds,
                                        &mut insn_local_ip,
                                        &mut next_synthetic_ip,
                                        ib,
                                    )?;
                                }
                                resolved_helper_call_sites.insert(site_key);
                                clear_x86_call_clobbered_registers(&mut map_symbol_registers);
                                continue;
                            }
                            LookupKind::Call
                            | LookupKind::Hash
                            | LookupKind::LruHash
                            | LookupKind::PerCpuHash
                            | LookupKind::HashOfMaps => {
                                let helper_addr = resolve_lookup_site_target(
                                    &spec,
                                    &format!("x86 lookup-site {site_label} ({:?})", spec.kind),
                                )?;
                                push_x86_helper_call_reloc(
                                    &mut local,
                                    &mut kinds,
                                    &mut insn_local_ip,
                                    local_ip,
                                    helper_addr,
                                )?;
                                for ib in build_x86_lookup_call_postprocess(&spec)? {
                                    push_x86_synthetic(
                                        &mut local,
                                        &mut kinds,
                                        &mut insn_local_ip,
                                        &mut next_synthetic_ip,
                                        ib,
                                    )?;
                                }
                                resolved_helper_call_sites.insert(site_key);
                                clear_x86_call_clobbered_registers(&mut map_symbol_registers);
                                continue;
                            }
                        }
                    }

                    if name == "bpf_map_update_elem" {
                        let ordinal = update_call_counter;
                        update_call_counter += 1;
                        let native_map_name =
                            map_symbol_registers.get(&Register::RDI).map(String::as_str);
                        if let Some((site_label, site_index)) = select_update_site(
                            update_sites,
                            &mut update_site_used,
                            ordinal,
                            native_map_name,
                        ) {
                            let spec = &update_sites[site_index];
                            match spec.kind {
                                UpdateKind::Array | UpdateKind::PerCpuArray => {
                                    for ib in build_x86_array_update(spec)? {
                                        push_x86_synthetic(
                                            &mut local,
                                            &mut kinds,
                                            &mut insn_local_ip,
                                            &mut next_synthetic_ip,
                                            ib,
                                        )?;
                                    }
                                    resolved_helper_call_sites.insert(site_key);
                                    clear_x86_call_clobbered_registers(&mut map_symbol_registers);
                                    continue;
                                }
                                UpdateKind::Call => {
                                    let helper_addr = require_call_target(
                                        spec.target_addr,
                                        &format!("x86 update-site {site_label}"),
                                    )?;
                                    push_x86_helper_call_reloc(
                                        &mut local,
                                        &mut kinds,
                                        &mut insn_local_ip,
                                        local_ip,
                                        helper_addr,
                                    )?;
                                    resolved_helper_call_sites.insert(site_key);
                                    clear_x86_call_clobbered_registers(&mut map_symbol_registers);
                                    continue;
                                }
                            }
                        }
                    }

                    let helper_addr = resolve_helper_target(
                        &name,
                        helper_addrs,
                        &format!("x86 helper call {name}"),
                    )?;
                    push_x86_helper_call_reloc(
                        &mut local,
                        &mut kinds,
                        &mut insn_local_ip,
                        local_ip,
                        helper_addr,
                    )?;
                    resolved_helper_call_sites.insert(site_key);
                    clear_x86_call_clobbered_registers(&mut map_symbol_registers);
                    continue;
                } else if let Some(reg) = call_reg {
                    bail!(
                        "x86 unresolved register-indirect call in {} at local offset {:#x} through {:?}; helper calls must be rewritten before kernel load",
                        sym.name,
                        local_ip,
                        reg
                    );
                }
            }

            // Helper PLT32/GOT placeholders should have been resolved in
            // the helper-call block above. Keep non-helper instructions as
            // decoded; the ELF relocation pass below handles map literals
            // and local data references.
            let call_clobbers = matches!(
                insn.flow_control(),
                FlowControl::Call | FlowControl::IndirectCall
            );
            let lookup_map_name_for_call = if helper_call_sites.get(&site_key).map(String::as_str)
                == Some("bpf_map_lookup_elem")
            {
                map_symbol_registers.get(&Register::RDI).cloned()
            } else {
                None
            };
            let map_reg_move = x86_mov_gpr64_to_gpr64(&insn).and_then(|(dst, src)| {
                map_symbol_registers
                    .get(&src)
                    .cloned()
                    .map(|name| (dst, name))
            });
            let imm_reg_move = x86_mov_gpr64_to_gpr64(&insn).and_then(|(dst, src)| {
                immediate_registers.get(&src).copied().map(|imm| (dst, imm))
            });
            let imm_reg_load = x86_mov_imm_to_gpr64(&insn);
            let written_reg = x86_written_gpr_family(&insn);
            local.push(insn);
            kinds.push(None);
            insn_local_ip.push(local_ip);

            // Track lookup callsite consumption after the call. The native C
            // and BPF backends do not always preserve global helper call order
            // across split subprograms, so prefer map-symbol matching when the
            // native callsite's rdi argument can be traced.
            if let Some(name) = helper_call_sites.get(&site_key) {
                if name == "bpf_map_lookup_elem" {
                    let native_call_index = lookup_call_counter;
                    lookup_call_counter += 1;
                    let (_site_label, _site_index, spec) = select_lookup_site(
                        lookup_sites,
                        lookup_maps,
                        &mut lookup_site_used,
                        native_call_index,
                        lookup_map_name_for_call.as_deref(),
                        &sym.name,
                        map_lookup_helper_addr,
                    )?;
                    lookup_call_specs.insert(site_key, spec.clone());
                }
            }
            if call_clobbers {
                clear_x86_call_clobbered_registers(&mut map_symbol_registers);
                clear_x86_call_clobbered_registers(&mut helper_got_registers);
                clear_x86_call_clobbered_registers(&mut helper_imm_registers);
                clear_x86_call_clobbered_registers(&mut immediate_registers);
            } else if let Some((dst, name)) = map_reg_move {
                map_symbol_registers.insert(dst, name);
            } else if let Some((dst, imm)) = imm_reg_move {
                immediate_registers.insert(dst, imm);
            } else if let Some((dst, imm)) = imm_reg_load {
                immediate_registers.insert(dst, imm);
            } else if let Some(reg) = written_reg {
                map_symbol_registers.remove(&reg);
                immediate_registers.remove(&reg);
            }
            if let Some(reg) = written_reg {
                if helper_got_load_reg != Some(reg) {
                    helper_got_registers.remove(&reg);
                }
                if helper_imm_load_reg != Some(reg) {
                    helper_imm_registers.remove(&reg);
                }
            }
        }

        // Encode this symbol's local stream at IP=0.
        // Normally iced fixes short intra-symbol branches after helper/map
        // rewrites change instruction sizes. If it hits an edge case at the
        // i8 distance boundary, fall back to a fixed near-branch layout with
        // manually remapped local targets.
        let encoded = encode_x86_local_block(&sym.name, sym.size, &local, &insn_local_ip)?;

        let sym_base = blob.len();
        sym_global_offset.insert(symbol_key(sym), sym_base);
        for (i, kind) in kinds.iter().enumerate() {
            let Some(kind) = kind else { continue };
            let off_in_sym = encoded
                .new_instruction_offsets
                .get(i)
                .copied()
                .ok_or_else(|| anyhow!("missing offset for instruction {i} in {}", sym.name))?
                as usize;
            patches.push(PatchInfo {
                global_offset: sym_base + off_in_sym,
                kind: kind.clone(),
            });
        }
        layouts.push(SymbolLayout {
            sym: sym.clone(),
            base_in_blob: sym_base,
            insn_local_ip,
            new_offset_in_sym: encoded.new_instruction_offsets.clone(),
        });
        blob.extend_from_slice(&encoded.code_buffer);
    }

    // Apply intra-blob Call patches first (cross-symbol direct calls);
    // those need only `sym_global_offset` which is already known.
    for p in &patches {
        if let PatchKind::Call { target_symbol_key } = &p.kind {
            let off = p.global_offset;
            if off + 5 > blob.len() || blob[off] != 0xE8 {
                bail!("CALL at off {off:#x} did not encode as Call_rel32_64");
            }
            let target_global = *sym_global_offset
                .get(target_symbol_key)
                .ok_or_else(|| anyhow!("call target sym key not in index map"))?;
            let disp = target_global as i64 - (off + 5) as i64;
            let d = i32::try_from(disp).map_err(|_| anyhow!("call disp {disp} exceeds i32"))?;
            blob[off + 1..off + 5].copy_from_slice(&d.to_le_bytes());
        }
    }

    let mut map_patches = Vec::new();
    let mut relocs = Vec::new();
    for p in &patches {
        match &p.kind {
            PatchKind::MapImmediate { name, imm_offset } => {
                let offset = p
                    .global_offset
                    .checked_add(*imm_offset)
                    .ok_or_else(|| anyhow!("map immediate patch offset overflow"))?;
                if offset + 8 > blob.len() {
                    bail!("map immediate patch at off {offset:#x} exceeds blob size");
                }
                map_patches.push(MapPatch {
                    name: name.clone(),
                    offset,
                });
            }
            PatchKind::HelperCallRel32 { target_addr } => {
                let offset = u32::try_from(p.global_offset)
                    .map_err(|_| anyhow!("helper call reloc offset exceeds u32"))?;
                let end = p
                    .global_offset
                    .checked_add(X86_HELPER_CALL_REL32_SLOT.len())
                    .ok_or_else(|| anyhow!("helper call slot offset overflow"))?;
                if end > blob.len() || blob[p.global_offset..end] != X86_HELPER_CALL_REL32_SLOT[..]
                {
                    bail!(
                        "helper call slot at off {:#x} did not encode as call rel32 placeholder",
                        p.global_offset
                    );
                }
                relocs.push(RelocRecord {
                    offset,
                    kind: NATIVE_LAB_RELOC_HELPER_CALL_REL32,
                    target: *target_addr,
                });
            }
            PatchKind::JmpEnd | PatchKind::Call { .. } => {}
        }
    }

    // Stage 2: resolve ELF relocations. GOT helper calls keep their original
    // RIP-relative indirect-call form and point at in-blob literal-pool entries;
    // PLT32 helper calls use in-blob absolute trampolines.
    let proof_relocs = if proof_mode {
        collect_x86_proof_relocs(elf, &layouts)?
    } else {
        relocs.extend(apply_elf_relocations(
            elf,
            &layouts,
            helper_addrs,
            map_addrs,
            &lookup_call_specs,
            &resolved_helper_call_sites,
            &resolved_got_relocations,
            &mut blob,
            &mut map_patches,
        )?);
        Vec::new()
    };

    // Patch JmpEnd disps LAST so they target the byte AFTER any
    // trampolines we just appended -- i.e., where the BPF JIT will emit
    // the next BPF insn's code (the `exit` epilogue in our stub). A
    // rewritten `ret` inside the function body lands at the BPF JIT
    // epilogue and skips the trampolines along the way. If the final
    // entry return already sits at the true blob end, delete that
    // redundant `jmp +0` and let it fall through into the BPF epilogue.
    let trailing_jmp_end = if proof_mode {
        None
    } else {
        patches.iter().find_map(|p| {
            if matches!(&p.kind, PatchKind::JmpEnd) && p.global_offset + 5 == blob.len() {
                Some(p.global_offset)
            } else {
                None
            }
        })
    };
    if let Some(off) = trailing_jmp_end {
        if off + 5 > blob.len() || blob[off] != 0xE9 {
            bail!("trailing JmpEnd placeholder at off {off:#x} did not encode as Jmp_rel32_64");
        }
    }
    let end_offset = trailing_jmp_end.unwrap_or(blob.len()) as i64;
    for p in &patches {
        if matches!(&p.kind, PatchKind::JmpEnd) {
            let off = p.global_offset;
            if Some(off) == trailing_jmp_end {
                continue;
            }
            if off + 5 > blob.len() || blob[off] != 0xE9 {
                bail!("JmpEnd placeholder at off {off:#x} did not encode as Jmp_rel32_64");
            }
            let disp = end_offset - (off + 5) as i64;
            let d = i32::try_from(disp).map_err(|_| anyhow!("jmp_end disp {disp} exceeds i32"))?;
            blob[off + 1..off + 5].copy_from_slice(&d.to_le_bytes());
        }
    }
    if let Some(off) = trailing_jmp_end {
        blob.truncate(off);
    }

    if show {
        disasm(&blob);
    }
    let proof_symbols = if proof_mode {
        proof_symbols_from_x86_layouts(&layouts, blob.len())?
    } else {
        Vec::new()
    };
    Ok(RewriteResult {
        blob,
        relocs,
        map_patches,
        callee_saved_mask,
        proof_relocs,
        proof_symbols,
    })
}
fn x86_layout_insn_global_offset(layout: &SymbolLayout, local_patch_off: u64) -> Result<usize> {
    let insn_idx = layout
        .insn_local_ip
        .iter()
        .enumerate()
        .filter(|(_, &ip)| ip != u64::MAX && ip <= local_patch_off)
        .max_by_key(|(_, &ip)| ip)
        .map(|(idx, _)| idx)
        .ok_or_else(|| {
            anyhow!(
                "reloc at local offset {:#x} does not align with any decoded instruction in {}",
                local_patch_off,
                layout.sym.name
            )
        })?;
    Ok(layout.base_in_blob + layout.new_offset_in_sym[insn_idx] as usize)
}

fn proof_symbols_from_x86_layouts(
    layouts: &[SymbolLayout],
    blob_len: usize,
) -> Result<Vec<ProofSymbol>> {
    let mut out = Vec::new();
    for (idx, layout) in layouts.iter().enumerate() {
        let start = layout.base_in_blob;
        let next_start = layouts
            .get(idx + 1)
            .map(|next| next.base_in_blob)
            .unwrap_or(blob_len);
        if next_start < start {
            bail!("x86 proof symbol layout is not sorted");
        }
        if start >= blob_len {
            continue;
        }
        let end = next_start.min(blob_len);
        out.push(ProofSymbol {
            name: layout.sym.name.clone(),
            offset: start as u64,
            size: (end - start) as u64,
        });
    }
    Ok(out)
}

fn collect_x86_proof_relocs(
    elf: &object::File,
    layouts: &[SymbolLayout],
) -> Result<Vec<ProofReloc>> {
    let mut relocs = Vec::new();
    let mut sections: HashMap<object::SectionIndex, Vec<&SymbolLayout>> = HashMap::new();
    for layout in layouts {
        sections
            .entry(layout.sym.section_index)
            .or_default()
            .push(layout);
    }

    for (section_index, layouts_in_sec) in sections {
        let section = elf
            .section_by_index(section_index)
            .with_context(|| format!("section {:?}", section_index))?;
        for (reloc_offset, reloc) in section.relocations() {
            let Some(layout) = layouts_in_sec.iter().find(|l| {
                reloc_offset >= l.sym.address && reloc_offset < l.sym.address + l.sym.size
            }) else {
                continue;
            };
            let target_sym_idx = match reloc.target() {
                RelocationTarget::Symbol(idx) => idx,
                _ => continue,
            };
            let target_sym = elf
                .symbol_by_index(target_sym_idx)
                .with_context(|| format!("proof reloc target symbol {target_sym_idx:?}"))?;
            let target_name = target_sym
                .name()
                .map_err(|e| anyhow!("proof reloc target symbol name: {e}"))?
                .to_string();
            let r_type = match reloc.flags() {
                RelocationFlags::Elf { r_type } => r_type,
                _ => continue,
            };
            let local_patch_off = reloc_offset - layout.sym.address;
            match r_type {
                4 => {
                    let opcode_local_off = local_patch_off
                        .checked_sub(1)
                        .ok_or_else(|| anyhow!("PLT32 proof reloc at offset 0?"))?;
                    let opcode_off = x86_layout_insn_global_offset(layout, opcode_local_off)?;
                    let mut proof_addend = reloc.addend();
                    let proof_symbol = if let Some((section_index, target_addr)) =
                        resolve_x86_plt32_defined_target_addr(elf, &reloc)?
                    {
                        let local_target =
                            find_symbol_in_section_at_address(elf, section_index, target_addr)
                                .ok_or_else(|| {
                                    anyhow!(
                                        "PLT32 proof reloc in {} at {:#x} targets {:#x}, \
                                 but no symbol covers that address",
                                        layout.sym.name,
                                        local_patch_off,
                                        target_addr
                                    )
                                })?;
                        let adjusted = i128::from(target_addr)
                            .checked_sub(i128::from(local_target.address))
                            .and_then(|v| v.checked_sub(4))
                            .ok_or_else(|| anyhow!("PLT32 proof addend overflow"))?;
                        proof_addend = i64::try_from(adjusted)
                            .map_err(|_| anyhow!("PLT32 proof addend {adjusted} exceeds i64"))?;
                        local_target.name
                    } else {
                        target_name.clone()
                    };
                    if proof_symbol.is_empty() {
                        bail!(
                            "PLT32 proof reloc in {} at {:#x} resolved to an empty symbol",
                            layout.sym.name,
                            local_patch_off
                        );
                    }
                    relocs.push(ProofReloc {
                        offset: (opcode_off + 1) as u64,
                        r_type,
                        symbol: proof_symbol,
                        addend: proof_addend,
                        data: None,
                    });
                }
                9 | 41 | 42 => {
                    let insn_idx = layout
                        .insn_local_ip
                        .iter()
                        .enumerate()
                        .filter(|(_, &ip)| ip != u64::MAX && ip <= local_patch_off)
                        .max_by_key(|(_, &ip)| ip)
                        .map(|(idx, _)| idx)
                        .ok_or_else(|| {
                            anyhow!(
                                "GOT proof reloc at {:#x} does not align with any instruction in {}",
                                local_patch_off,
                                layout.sym.name
                            )
                        })?;
                    let insn_off =
                        layout.base_in_blob + layout.new_offset_in_sym[insn_idx] as usize;
                    let off_within_insn =
                        (local_patch_off - layout.insn_local_ip[insn_idx]) as usize;
                    let disp32_off = insn_off + off_within_insn;
                    relocs.push(ProofReloc {
                        offset: disp32_off as u64,
                        r_type,
                        symbol: target_name,
                        addend: reloc.addend(),
                        data: None,
                    });
                }
                2 => {
                    let target_section_idx = target_sym.section_index().ok_or_else(|| {
                        anyhow!("PC32 proof reloc target {} has no section", target_name)
                    })?;
                    let target_section =
                        elf.section_by_index(target_section_idx).with_context(|| {
                            format!("PC32 proof target section {target_section_idx:?}")
                        })?;
                    let target_data = target_section.data().with_context(|| {
                        format!("read proof target section {target_section_idx:?} data")
                    })?;
                    let sec_base = target_section.address();
                    let section_name = target_section
                        .name()
                        .map_err(|e| anyhow!("PC32 proof target section name: {e}"))?;
                    if section_name.starts_with(".text") {
                        let target_addr = i128::from(target_sym.address())
                            .checked_add(i128::from(reloc.addend()))
                            .and_then(|v| v.checked_add(4))
                            .ok_or_else(|| anyhow!("PC32 proof text target address overflow"))?;
                        if target_addr < 0 || target_addr > i128::from(u64::MAX) {
                            bail!("PC32 proof text target address out of range: {target_addr}");
                        }
                        let target_addr = target_addr as u64;
                        let local_target =
                            find_symbol_in_section_at_address(elf, target_section_idx, target_addr)
                                .ok_or_else(|| {
                                    anyhow!(
                                        "PC32 proof text reloc in {} at {:#x} targets {:#x}, \
                                         but no symbol covers that address",
                                        layout.sym.name,
                                        local_patch_off,
                                        target_addr
                                    )
                                })?;
                        let adjusted = i128::from(target_addr)
                            .checked_sub(i128::from(local_target.address))
                            .and_then(|v| v.checked_sub(4))
                            .ok_or_else(|| anyhow!("PC32 proof text addend overflow"))?;
                        let proof_addend = i64::try_from(adjusted).map_err(|_| {
                            anyhow!("PC32 proof text addend {adjusted} exceeds i64")
                        })?;
                        let insn_idx = layout
                            .insn_local_ip
                            .iter()
                            .enumerate()
                            .filter(|(_, &ip)| ip != u64::MAX && ip <= local_patch_off)
                            .max_by_key(|(_, &ip)| ip)
                            .map(|(idx, _)| idx)
                            .ok_or_else(|| {
                                anyhow!(
                                    "PC32 proof text reloc at {:#x} does not align with any instruction in {}",
                                    local_patch_off,
                                    layout.sym.name
                                )
                            })?;
                        let new_insn_off =
                            layout.base_in_blob + layout.new_offset_in_sym[insn_idx] as usize;
                        let off_within_insn =
                            (local_patch_off - layout.insn_local_ip[insn_idx]) as usize;
                        relocs.push(ProofReloc {
                            offset: (new_insn_off + off_within_insn) as u64,
                            r_type,
                            symbol: local_target.name,
                            addend: proof_addend,
                            data: None,
                        });
                        continue;
                    }
                    let sym_off_in_sec =
                        target_sym.address().checked_sub(sec_base).ok_or_else(|| {
                            anyhow!("PC32 proof target {} below section base", target_name)
                        })?;
                    let sym_size = target_sym.size();
                    let (data_symbol_name, sym_bytes) = if sym_size == 0 {
                        if !target_name.is_empty() {
                            bail!("PC32 proof target {} has zero size", target_name);
                        }
                        let section_bytes = if section_name.starts_with(".rodata") {
                            target_data.to_vec()
                        } else if section_name == ".bss" {
                            let section_size = usize::try_from(target_section.size())
                                .map_err(|_| anyhow!("PC32 proof .bss section too large"))?;
                            vec![0; section_size]
                        } else {
                            bail!(
                                "PC32 proof section-symbol target {section_name} is not rodata/bss"
                            );
                        };
                        (
                            format!("section:{target_section_idx:?}:{section_name}"),
                            section_bytes,
                        )
                    } else {
                        let end = sym_off_in_sec
                            .checked_add(sym_size)
                            .ok_or_else(|| anyhow!("PC32 proof target size overflow"))?;
                        let bytes = target_data
                            .get(sym_off_in_sec as usize..end as usize)
                            .ok_or_else(|| {
                                anyhow!("PC32 proof target {} out of section bounds", target_name)
                            })?
                            .to_vec();
                        (target_name.clone(), bytes)
                    };
                    let insn_idx = layout
                        .insn_local_ip
                        .iter()
                        .enumerate()
                        .filter(|(_, &ip)| ip != u64::MAX && ip <= local_patch_off)
                        .max_by_key(|(_, &ip)| ip)
                        .map(|(idx, _)| idx)
                        .ok_or_else(|| {
                            anyhow!(
                                "PC32 proof reloc at {:#x} does not align with any instruction in {}",
                                local_patch_off,
                                layout.sym.name
                            )
                        })?;
                    let new_insn_off =
                        layout.base_in_blob + layout.new_offset_in_sym[insn_idx] as usize;
                    let off_within_insn =
                        (local_patch_off - layout.insn_local_ip[insn_idx]) as usize;
                    relocs.push(ProofReloc {
                        offset: (new_insn_off + off_within_insn) as u64,
                        r_type,
                        symbol: data_symbol_name,
                        addend: reloc.addend(),
                        data: Some(sym_bytes),
                    });
                }
                _ => bail!(
                    "unsupported proof relocation r_type={} against symbol {} (offset {:#x})",
                    r_type,
                    target_name,
                    reloc_offset
                ),
            }
        }
    }
    relocs.sort_by_key(|reloc| reloc.offset);
    Ok(relocs)
}

/// Resolve ELF .text relocations attached to the bytes we just encoded.
///
/// Helper calls must already have been rewritten to side-band `call rel32`
/// relocation slots by the decode pass. Remaining relocations are for map
/// literals and local data references; a call-class relocation that reaches
/// this pass is a linker bug and fails fast.
fn apply_elf_relocations(
    elf: &object::File,
    layouts: &[SymbolLayout],
    helper_addrs: &HashMap<String, u64>,
    map_addrs: &HashMap<String, u64>,
    lookup_call_specs: &HashMap<LocalSiteKey, LookupSiteSpec>,
    resolved_helper_call_sites: &HashSet<LocalSiteKey>,
    resolved_got_relocations: &HashSet<LocalSiteKey>,
    blob: &mut Vec<u8>,
    map_patches: &mut Vec<MapPatch>,
) -> Result<Vec<RelocRecord>> {
    if layouts.is_empty() {
        return Ok(Vec::new());
    }

    // Group symbols by ELF section so we walk each section's relocations
    // once (in practice always .text).
    let mut sections: HashMap<object::SectionIndex, Vec<&SymbolLayout>> = HashMap::new();
    for layout in layouts {
        sections
            .entry(layout.sym.section_index)
            .or_default()
            .push(layout);
    }
    let layout_base_by_symbol: HashMap<SymbolKey, usize> = layouts
        .iter()
        .map(|layout| (symbol_key(&layout.sym), layout.base_in_blob))
        .collect();

    // Cache: map symbol name -> literal-pool entry byte offset in blob.
    let mut map_pool_entry: HashMap<String, usize> = HashMap::new();
    // Cache: local rodata/data symbol name -> embedded copy offset.
    // R_X86_64_PC32 against a `.L__const.<fn>.<arr>` symbol (clang puts
    // small const initializers there for 16+ byte loads via SSE) is
    // satisfied by copying the symbol's bytes to the blob tail and
    // patching the rip-relative disp32 in the loading insn.
    let mut local_data_embed: HashMap<String, usize> = HashMap::new();
    let out_relocs = Vec::new();

    for (section_index, layouts_in_sec) in &sections {
        let section = elf
            .section_by_index(*section_index)
            .with_context(|| format!("section {:?}", section_index))?;
        for (reloc_offset, reloc) in section.relocations() {
            let owning_layout = layouts_in_sec.iter().find(|l| {
                reloc_offset >= l.sym.address && reloc_offset < l.sym.address + l.sym.size
            });
            let Some(layout) = owning_layout else {
                continue;
            };

            let target_sym_idx = match reloc.target() {
                RelocationTarget::Symbol(idx) => idx,
                _ => continue,
            };
            let target_sym = elf
                .symbol_by_index(target_sym_idx)
                .with_context(|| format!("reloc target symbol {target_sym_idx:?}"))?;
            let target_name: String = target_sym
                .name()
                .map_err(|e| anyhow!("reloc target symbol name: {e}"))?
                .to_string();

            let r_type = match reloc.flags() {
                RelocationFlags::Elf { r_type } => r_type,
                _ => continue,
            };

            // Local offset of the patch site within the owning symbol.
            let local_patch_off = reloc_offset - layout.sym.address;

            match r_type {
                // R_X86_64_PLT32 = 4: clang's `call helper`. Reloc offset
                // points at the 4-byte disp32 field; the 0xE8 opcode is
                // at offset-1.
                4 => {
                    let opcode_local_off = local_patch_off
                        .checked_sub(1)
                        .ok_or_else(|| anyhow!("PLT32 reloc at offset 0?"))?;
                    if resolved_helper_call_sites
                        .contains(&local_site_key(&layout.sym, opcode_local_off))
                    {
                        continue;
                    }
                    let insn_idx = layout
                        .insn_local_ip
                        .iter()
                        .position(|&ip| ip == opcode_local_off)
                        .ok_or_else(|| {
                            anyhow!(
                                "PLT32 reloc at {:#x} (opcode at {:#x}) does not align \
                             with any decoded instruction in symbol {}",
                                local_patch_off,
                                opcode_local_off,
                                layout.sym.name
                            )
                        })?;
                    let new_opcode_off =
                        layout.base_in_blob + layout.new_offset_in_sym[insn_idx] as usize;
                    if new_opcode_off + 5 > blob.len() || blob[new_opcode_off] != 0xE8 {
                        bail!(
                            "PLT32 reloc at {:#x} in {} did not encode as call rel32",
                            local_patch_off,
                            layout.sym.name
                        );
                    }
                    if let Some(target_sym) = resolve_x86_plt32_defined_target(elf, &reloc)? {
                        let target_global = *layout_base_by_symbol
                            .get(&symbol_key(&target_sym))
                            .ok_or_else(|| {
                                anyhow!(
                                    "PLT32 local call from {} to {} was not included as reachable",
                                    layout.sym.name,
                                    target_sym.name
                                )
                            })?;
                        let rip_after_call = (new_opcode_off + 5) as i64;
                        let disp = target_global as i64 - rip_after_call;
                        let d = i32::try_from(disp)
                            .map_err(|_| anyhow!("local call disp {disp} exceeds i32"))?;
                        blob[new_opcode_off + 1..new_opcode_off + 5]
                            .copy_from_slice(&d.to_le_bytes());
                        continue;
                    }
                    if helper_addrs.contains_key(&target_name) {
                        bail!(
                            "PLT32 helper call to {} in {} at {:#x} reached relocation pass; \
                             helper calls must be rewritten to direct rel32 slots",
                            target_name,
                            layout.sym.name,
                            opcode_local_off
                        );
                    }
                    bail!(
                        "unsupported PLT32 external call to {} in {} at {:#x}",
                        target_name,
                        layout.sym.name,
                        opcode_local_off
                    );
                }
                // GOT-relative references (R_X86_64_GOTPCREL=9,
                // _GOTPCRELX=41, _REX_GOTPCRELX=42). clang emits these
                // for both `&my_map` (mov reg, [rip+disp32] -- 7 byte)
                // and, with -fno-plt, for `call helper` (call *[rip+
                // disp32] -- 6 byte). The reloc offset points at the
                // 4-byte disp32 field for both. We append an 8-byte
                // literal-pool entry holding the symbol's kernel address
                // at the end of the blob and patch the disp32.
                //
                // We try helper_addrs first because helpers are more
                // common; map_addrs is consulted only if not found in
                // helpers.
                9 | 41 | 42 => {
                    if resolved_got_relocations
                        .contains(&local_site_key(&layout.sym, local_patch_off))
                    {
                        continue;
                    }
                    let got_call_local_off = local_patch_off.wrapping_sub(2);
                    if resolved_helper_call_sites
                        .contains(&local_site_key(&layout.sym, got_call_local_off))
                    {
                        continue;
                    }

                    // Per-call-site routing for `bpf_map_lookup_elem`.
                    // Route each `bpf_map_lookup_elem` call to the
                    // mandatory per-site target supplied by the runner.
                    // This avoids a single shared pool entry forcing all
                    // lookup sites to share one helper target.
                    let mut dedicated_pool_addr: Option<u64> = None;
                    if target_name == "bpf_map_lookup_elem" {
                        // The reloc offset points at the disp32 of the
                        // 6-byte indirect call (`ff 15 dd dd dd dd`);
                        // the call's opcode is 2 bytes earlier.
                        let spec = lookup_call_specs
                            .get(&local_site_key(&layout.sym, got_call_local_off))
                            .ok_or_else(|| {
                                anyhow!(
                                    "x86 bpf_map_lookup_elem GOT relocation in {} at {:#x} has no lookup-site spec",
                                    layout.sym.name,
                                    got_call_local_off
                                )
                            })?;
                        if spec.target_addr == 0 {
                            bail!(
                                "x86 lookup site for {} at {:#x} is {:?} but has no GOT-call target address",
                                layout.sym.name,
                                got_call_local_off,
                                spec.kind
                            );
                        }
                        dedicated_pool_addr = Some(spec.target_addr);
                    }
                    let kernel_addr = if let Some(a) = dedicated_pool_addr {
                        a
                    } else {
                        helper_addrs
                            .get(&target_name)
                            .copied()
                            .or_else(|| map_addrs.get(&target_name).copied())
                            .ok_or_else(|| {
                                anyhow!(
                                    "GOT-relative reloc against unknown symbol {}; add it to link-plan helpers or maps",
                                    target_name
                                )
                            })?
                    };
                    let is_map_literal = dedicated_pool_addr.is_none()
                        && !helper_addrs.contains_key(&target_name)
                        && map_addrs.contains_key(&target_name);
                    let map_addr = kernel_addr; /* used by code below */

                    // Find the decoded instruction that contains this
                    // reloc. The disp32 occupies bytes
                    // [local_patch_off, local_patch_off+4); we want the
                    // insn whose start address is the largest value
                    // <= local_patch_off (ignoring the u64::MAX sentinel
                    // used to mark inserted inline-hash bytes that have
                    // no source-byte counterpart).
                    let insn_idx = layout
                        .insn_local_ip
                        .iter()
                        .enumerate()
                        .filter(|(_, &ip)| ip != u64::MAX && ip <= local_patch_off)
                        .max_by_key(|(_, &ip)| ip)
                        .map(|(idx, _)| idx)
                        .ok_or_else(|| {
                            anyhow!(
                                "GOTPCREL reloc at {:#x} does not align with any instruction in {}",
                                local_patch_off,
                                layout.sym.name
                            )
                        })?;
                    let new_insn_off =
                        layout.base_in_blob + layout.new_offset_in_sym[insn_idx] as usize;
                    let off_within_insn =
                        (local_patch_off - layout.insn_local_ip[insn_idx]) as usize;
                    let disp32_off = new_insn_off + off_within_insn;
                    if x86_encoded_instruction_is_indirect_call(blob, new_insn_off)? {
                        bail!(
                            "GOT-relative indirect call to {} in {} at {:#x} reached relocation pass; \
                             call sites must be rewritten to direct rel32 slots",
                            target_name,
                            layout.sym.name,
                            layout.insn_local_ip[insn_idx]
                        );
                    }

                    // Reserve / reuse a pool entry. For
                    // per-call-site routed `bpf_map_lookup_elem` we
                    // always allocate a *fresh* entry (each call site
                    // can route to a different target), 8 bytes per
                    // site. For everything else (helpers shared across
                    // many call sites, map pointers shared across
                    // load/lookup sequences) one entry is sufficient.
                    let pool_off = if dedicated_pool_addr.is_some() {
                        let off = blob.len();
                        blob.extend_from_slice(&map_addr.to_le_bytes());
                        off
                    } else if let Some(&off) = map_pool_entry.get(&target_name) {
                        off
                    } else {
                        let off = blob.len();
                        blob.extend_from_slice(&map_addr.to_le_bytes());
                        map_pool_entry.insert(target_name.clone(), off);
                        if is_map_literal {
                            map_patches.push(MapPatch {
                                name: target_name.clone(),
                                offset: off,
                            });
                        }
                        off
                    };

                    // mov reg, [rip+disp32]: disp32 = pool_off - (disp32_off + 4)
                    let rip_after = (disp32_off + 4) as i64;
                    let disp = pool_off as i64 - rip_after;
                    let d =
                        i32::try_from(disp).map_err(|_| anyhow!("map disp {disp} exceeds i32"))?;
                    blob[disp32_off..disp32_off + 4].copy_from_slice(&d.to_le_bytes());
                }
                // R_X86_64_PC32 = 2: PC-relative reference to a local
                // symbol. clang emits this for `movups xmm0, [rip+disp]`
                // / `lea rax, [rip+disp]` against an anonymous rodata
                // constant (e.g. `.L__const.<fn>.<arr>` produced when a
                // function-local `const T x = { ... }` is 16+ bytes and
                // clang lowers it via SSE/AVX). We embed the symbol's
                // raw bytes at the tail of the blob and patch the
                // disp32 to point at the embedded copy.
                //
                // R_X86_64_32S = 11 falls into the same category for
                // absolute references; we accept it on the same
                // mechanism (PC-relative form here -- clang shouldn't
                // be emitting 32S in -fPIC code, but handle defensively).
                2 => {
                    let target_section_idx = target_sym.section_index().ok_or_else(|| {
                        anyhow!("PC32 reloc target {} has no section", target_name)
                    })?;
                    let target_section = elf
                        .section_by_index(target_section_idx)
                        .with_context(|| format!("PC32 target section {target_section_idx:?}"))?;
                    let target_data = target_section
                        .data()
                        .with_context(|| format!("read section {target_section_idx:?} data"))?;
                    let sec_base = target_section.address();
                    let section_name = target_section
                        .name()
                        .map_err(|e| anyhow!("PC32 target section name: {e}"))?;
                    if section_name.starts_with(".text") {
                        let target_addr = i128::from(target_sym.address())
                            .checked_add(i128::from(reloc.addend()))
                            .and_then(|v| v.checked_add(4))
                            .ok_or_else(|| anyhow!("PC32 text target address overflow"))?;
                        if target_addr < 0 || target_addr > i128::from(u64::MAX) {
                            bail!("PC32 text target address out of range: {target_addr}");
                        }
                        let target_addr = target_addr as u64;
                        let local_target =
                            find_symbol_in_section_at_address(elf, target_section_idx, target_addr)
                                .ok_or_else(|| {
                                    anyhow!(
                                        "PC32 text reloc in {} at {:#x} targets {:#x}, \
                                         but no symbol covers that address",
                                        layout.sym.name,
                                        local_patch_off,
                                        target_addr
                                    )
                                })?;
                        let target_global = *layout_base_by_symbol
                            .get(&symbol_key(&local_target))
                            .ok_or_else(|| {
                                anyhow!(
                                    "PC32 text target from {} to {} was not included as reachable",
                                    layout.sym.name,
                                    local_target.name
                                )
                            })?;
                        let rel_off = target_addr
                            .checked_sub(local_target.address)
                            .ok_or_else(|| anyhow!("PC32 text target below symbol base"))?;
                        let insn_idx = layout
                            .insn_local_ip
                            .iter()
                            .enumerate()
                            .filter(|(_, &ip)| ip != u64::MAX && ip <= local_patch_off)
                            .max_by_key(|(_, &ip)| ip)
                            .map(|(idx, _)| idx)
                            .ok_or_else(|| {
                                anyhow!(
                                    "PC32 text reloc at {:#x} does not align with any instruction in {}",
                                    local_patch_off,
                                    layout.sym.name
                                )
                            })?;
                        let new_insn_off =
                            layout.base_in_blob + layout.new_offset_in_sym[insn_idx] as usize;
                        let off_within_insn =
                            (local_patch_off - layout.insn_local_ip[insn_idx]) as usize;
                        let disp32_off = new_insn_off + off_within_insn;
                        let target = i128::try_from(target_global)
                            .map_err(|_| anyhow!("PC32 text target global offset overflow"))?
                            .checked_add(i128::from(rel_off))
                            .and_then(|v| v.checked_sub(4))
                            .ok_or_else(|| anyhow!("PC32 text target addend overflow"))?;
                        let disp = target
                            .checked_sub(
                                i128::try_from(disp32_off)
                                    .map_err(|_| anyhow!("PC32 text relocation offset overflow"))?,
                            )
                            .ok_or_else(|| anyhow!("PC32 text disp overflow"))?;
                        let d = i32::try_from(disp)
                            .map_err(|_| anyhow!("PC32 text disp {disp} exceeds i32"))?;
                        blob[disp32_off..disp32_off + 4].copy_from_slice(&d.to_le_bytes());
                        continue;
                    }
                    let sym_off_in_sec = target_sym
                        .address()
                        .checked_sub(sec_base)
                        .ok_or_else(|| anyhow!("PC32 target {} below section base", target_name))?;
                    let sym_size = target_sym.size();
                    let (data_symbol_name, sym_bytes) = if sym_size == 0 {
                        if !target_name.is_empty() {
                            bail!("PC32 target {} has zero size; cannot embed", target_name);
                        }
                        let section_bytes = if section_name.starts_with(".rodata") {
                            target_data.to_vec()
                        } else if section_name == ".bss" {
                            let section_size = usize::try_from(target_section.size())
                                .map_err(|_| anyhow!("PC32 .bss section too large"))?;
                            vec![0; section_size]
                        } else {
                            bail!("PC32 section-symbol target {section_name} is not rodata/bss");
                        };
                        (
                            format!("section:{target_section_idx:?}:{section_name}"),
                            section_bytes,
                        )
                    } else {
                        let end = sym_off_in_sec
                            .checked_add(sym_size)
                            .ok_or_else(|| anyhow!("PC32 target size overflow"))?;
                        let bytes = target_data
                            .get(sym_off_in_sec as usize..end as usize)
                            .ok_or_else(|| {
                                anyhow!("PC32 target {} bytes out of section bounds", target_name)
                            })?
                            .to_vec();
                        (target_name.clone(), bytes)
                    };

                    let embed_off = if let Some(&off) = local_data_embed.get(&data_symbol_name) {
                        off
                    } else {
                        let off = blob.len();
                        blob.extend_from_slice(&sym_bytes);
                        local_data_embed.insert(data_symbol_name, off);
                        off
                    };

                    // Find the decoded instruction whose byte range
                    // covers `local_patch_off`. Same scheme as the
                    // GOTPCREL handler.
                    let insn_idx = layout
                        .insn_local_ip
                        .iter()
                        .enumerate()
                        .filter(|(_, &ip)| ip != u64::MAX && ip <= local_patch_off)
                        .max_by_key(|(_, &ip)| ip)
                        .map(|(idx, _)| idx)
                        .ok_or_else(|| {
                            anyhow!(
                                "PC32 reloc at {:#x} does not align with any instruction in {}",
                                local_patch_off,
                                layout.sym.name
                            )
                        })?;
                    let new_insn_off =
                        layout.base_in_blob + layout.new_offset_in_sym[insn_idx] as usize;
                    let off_within_insn =
                        (local_patch_off - layout.insn_local_ip[insn_idx]) as usize;
                    let disp32_off = new_insn_off + off_within_insn;

                    // Standard PC32 patch: S + A - P, where S = embed_off,
                    // A = reloc.addend() (typically -4 for rip-relative
                    // loads since the CPU's rip is 4 bytes past the
                    // disp32 field), P = disp32_off.
                    let addend = reloc.addend();
                    let disp = embed_off as i64 + addend - disp32_off as i64;
                    let d =
                        i32::try_from(disp).map_err(|_| anyhow!("PC32 disp {disp} exceeds i32"))?;
                    blob[disp32_off..disp32_off + 4].copy_from_slice(&d.to_le_bytes());
                }
                _ => bail!(
                    "unsupported relocation r_type={} against symbol {} (offset {:#x})",
                    r_type,
                    target_name,
                    reloc_offset
                ),
            }
        }
    }

    Ok(out_relocs)
}

#[derive(Default)]
struct X86EntryAbiStrip {
    drop_local_ips: HashSet<u64>,
    callee_saved_mask: u8,
    register_renames: HashMap<Register, Register>,
    branch_target_remaps: HashMap<u64, u64>,
    tail_call_cleanup_bytes: Vec<u8>,
    tail_call_bpf_rbp_rsp_offset: Option<i32>,
    tail_call_bpf_rbp_is_live: bool,
}

fn plan_x86_entry_abi_strip(
    bytes: &[u8],
    base_ip: u64,
    require_tail_call_frame: bool,
    proof_return_jmp_target: Option<u64>,
    preserve_existing_abi: bool,
) -> Result<X86EntryAbiStrip> {
    let mut decoder = Decoder::with_ip(64, bytes, base_ip, DecoderOptions::NONE);
    let mut insns: Vec<Instruction> = Vec::new();
    while decoder.can_decode() {
        let insn = decoder.decode();
        if insn.is_invalid() {
            bail!(
                "iced bailed while planning x86 entry ABI strip at IP {:#x}",
                insn.ip()
            );
        }
        if !is_alignment_nop(&insn) {
            insns.push(insn);
        }
    }
    let symbol_end = base_ip
        .checked_add(
            u64::try_from(bytes.len()).map_err(|_| anyhow!("x86 symbol size exceeds u64"))?,
        )
        .ok_or_else(|| anyhow!("x86 symbol end address overflow"))?;

    let mut prologue_regs: Vec<Register> = Vec::new();
    let mut prologue_local_ips: Vec<u64> = Vec::new();
    for insn in &insns {
        if let Some(reg) = x86_saved_push_reg(insn) {
            prologue_regs.push(reg);
            prologue_local_ips.push(insn.ip() - base_ip);
            continue;
        }
        break;
    }
    if prologue_regs.is_empty() {
        return x86_tail_call_frame_or_default(
            bytes,
            base_ip,
            &insns,
            &prologue_regs,
            0,
            require_tail_call_frame,
            symbol_end,
            proof_return_jmp_target,
        );
    }

    let stack_alloc = insns
        .get(prologue_regs.len())
        .and_then(x86_sub_rsp_imm)
        .unwrap_or(0);
    if preserve_existing_abi {
        return x86_tail_call_frame_or_default(
            bytes,
            base_ip,
            &insns,
            &prologue_regs,
            stack_alloc,
            require_tail_call_frame,
            symbol_end,
            proof_return_jmp_target,
        );
    }
    let prologue_set: HashSet<Register> = prologue_regs.iter().copied().collect();
    let mut strip_set: HashSet<Register> = prologue_regs
        .iter()
        .copied()
        .filter(|reg| is_x86_entry_strippable_saved_reg(*reg))
        .collect();

    let used_families = collect_x86_register_families(&insns);
    let mut spare_regs: Vec<Register> =
        [Register::RBX, Register::R13, Register::R14, Register::R15]
            .iter()
            .copied()
            .filter(|reg| !used_families.contains(reg))
            .collect();
    let mut register_renames: HashMap<Register, Register> = HashMap::new();
    for src in [Register::R12, Register::RBP] {
        if !prologue_set.contains(&src) {
            continue;
        }
        let Some(spare_idx) = spare_regs
            .iter()
            .position(|dst| x86_entry_rename_is_safe(&insns, src, *dst))
        else {
            continue;
        };
        let dst = spare_regs.remove(spare_idx);
        register_renames.insert(src, dst);
        strip_set.insert(src);
    }

    if strip_set.is_empty() && register_renames.is_empty() {
        return x86_tail_call_frame_or_default(
            bytes,
            base_ip,
            &insns,
            &prologue_regs,
            stack_alloc,
            require_tail_call_frame,
            symbol_end,
            proof_return_jmp_target,
        );
    }

    let mut drop_local_ips: HashSet<u64> = HashSet::new();
    let mut branch_target_remaps: HashMap<u64, u64> = HashMap::new();
    let mut tail_call_cleanup_bytes: Option<Vec<u8>> = None;
    for (reg, local_ip) in prologue_regs.iter().zip(prologue_local_ips.iter()) {
        if strip_set.contains(reg) {
            drop_local_ips.insert(*local_ip);
        }
    }

    for (idx, insn) in insns.iter().enumerate() {
        if !x86_entry_return_terminator(insn, symbol_end, proof_return_jmp_target) {
            continue;
        }
        let mut seen: HashSet<Register> = HashSet::new();
        let mut cursor = idx;
        while cursor > 0 {
            let prev = &insns[cursor - 1];
            let Some(reg) = x86_saved_pop_reg(prev) else {
                break;
            };
            if !prologue_set.contains(&reg) {
                break;
            }
            seen.insert(reg);
            cursor -= 1;
        }
        if seen != prologue_set {
            return x86_tail_call_frame_or_default(
                bytes,
                base_ip,
                &insns,
                &prologue_regs,
                stack_alloc,
                require_tail_call_frame,
                symbol_end,
                proof_return_jmp_target,
            );
        }
        let cleanup_start = x86_epilogue_cleanup_start(&insns, cursor);
        let cleanup = build_x86_tail_call_cleanup_candidate(
            bytes,
            base_ip,
            &insns[cleanup_start..idx],
            &strip_set,
        )?;
        if let Some(previous) = &tail_call_cleanup_bytes {
            if previous != &cleanup {
                return x86_tail_call_frame_or_default(
                    bytes,
                    base_ip,
                    &insns,
                    &prologue_regs,
                    stack_alloc,
                    require_tail_call_frame,
                    symbol_end,
                    proof_return_jmp_target,
                );
            }
        } else {
            tail_call_cleanup_bytes = Some(cleanup);
        }
        for epilogue in &insns[cursor..idx] {
            if let Some(reg) = x86_saved_pop_reg(epilogue) {
                if strip_set.contains(&reg) {
                    drop_local_ips.insert(epilogue.ip() - base_ip);
                }
            }
        }
        let ret_local_ip = insn.ip() - base_ip;
        for ep_idx in cursor..idx {
            let epilogue = &insns[ep_idx];
            let Some(reg) = x86_saved_pop_reg(epilogue) else {
                continue;
            };
            if !strip_set.contains(&reg) {
                continue;
            }
            let dropped_local_ip = epilogue.ip() - base_ip;
            let mut target_local_ip = ret_local_ip;
            for next in &insns[ep_idx + 1..=idx] {
                let next_is_dropped_pop =
                    x86_saved_pop_reg(next).is_some_and(|next_reg| strip_set.contains(&next_reg));
                if !next_is_dropped_pop {
                    target_local_ip = next.ip() - base_ip;
                    break;
                }
            }
            branch_target_remaps.insert(dropped_local_ip, target_local_ip);
        }
    }

    // The runner encodes `callee_saved_mask` in the kinsn sidecar, and the
    // native_lab proof uses it to force the x86 BPF JIT prologue to save the
    // same host registers we strip here. The total stack movement before the
    // function body is therefore unchanged, so adding an extra alignment pad
    // would break compiler-emitted aligned stack accesses such as `movaps`.
    let mut preserved_regs: HashSet<Register> = strip_set
        .iter()
        .copied()
        .filter_map(|reg| {
            if register_renames.contains_key(&reg) {
                register_renames.get(&reg).copied()
            } else {
                Some(reg)
            }
        })
        .collect();
    preserved_regs.extend(register_renames.values().copied());
    let callee_saved_mask = preserved_regs.iter().try_fold(0u8, |mask, reg| {
        x86_entry_callee_saved_mask_bit(*reg)
            .map(|bit| mask | bit)
            .ok_or_else(|| anyhow!("x86 entry ABI rename picked unsupported register {reg:?}"))
    })?;
    if require_tail_call_frame && tail_call_cleanup_bytes.is_none() {
        return x86_tail_call_frame_or_default(
            bytes,
            base_ip,
            &insns,
            &prologue_regs,
            stack_alloc,
            require_tail_call_frame,
            symbol_end,
            proof_return_jmp_target,
        );
    }
    let (tail_call_bpf_rbp_rsp_offset, tail_call_bpf_rbp_is_live) =
        x86_bpf_rbp_location(&prologue_regs, &strip_set, stack_alloc)?;
    Ok(X86EntryAbiStrip {
        drop_local_ips,
        callee_saved_mask,
        register_renames,
        branch_target_remaps,
        tail_call_cleanup_bytes: tail_call_cleanup_bytes.unwrap_or_default(),
        tail_call_bpf_rbp_rsp_offset,
        tail_call_bpf_rbp_is_live,
    })
}

struct X86TailCallFrame {
    cleanup_bytes: Vec<u8>,
    bpf_rbp_rsp_offset: Option<i32>,
    bpf_rbp_is_live: bool,
}

fn x86_tail_call_frame_or_default(
    bytes: &[u8],
    base_ip: u64,
    insns: &[Instruction],
    prologue_regs: &[Register],
    stack_alloc: u64,
    require_tail_call_frame: bool,
    symbol_end: u64,
    proof_return_jmp_target: Option<u64>,
) -> Result<X86EntryAbiStrip> {
    if !require_tail_call_frame {
        return Ok(X86EntryAbiStrip::default());
    }
    let strip_set = HashSet::new();
    let frame = plan_x86_tail_call_frame(
        bytes,
        base_ip,
        insns,
        prologue_regs,
        stack_alloc,
        &strip_set,
        symbol_end,
        proof_return_jmp_target,
    )?;
    Ok(X86EntryAbiStrip {
        tail_call_cleanup_bytes: frame.cleanup_bytes,
        tail_call_bpf_rbp_rsp_offset: frame.bpf_rbp_rsp_offset,
        tail_call_bpf_rbp_is_live: frame.bpf_rbp_is_live,
        ..X86EntryAbiStrip::default()
    })
}

fn plan_x86_tail_call_frame(
    bytes: &[u8],
    base_ip: u64,
    insns: &[Instruction],
    prologue_regs: &[Register],
    stack_alloc: u64,
    strip_set: &HashSet<Register>,
    symbol_end: u64,
    proof_return_jmp_target: Option<u64>,
) -> Result<X86TailCallFrame> {
    let prologue_set: HashSet<Register> = prologue_regs.iter().copied().collect();
    let mut cleanup_bytes: Option<Vec<u8>> = None;
    let mut saw_return = false;
    for (idx, insn) in insns.iter().enumerate() {
        if !x86_entry_return_terminator(insn, symbol_end, proof_return_jmp_target) {
            continue;
        }
        saw_return = true;
        let mut seen: HashSet<Register> = HashSet::new();
        let mut cursor = idx;
        while cursor > 0 {
            let prev = &insns[cursor - 1];
            let Some(reg) = x86_saved_pop_reg(prev) else {
                break;
            };
            if !prologue_set.contains(&reg) {
                break;
            }
            seen.insert(reg);
            cursor -= 1;
        }
        if seen != prologue_set {
            bail!(
                "x86 entry with bpf_tail_call has non-canonical return epilogue at local offset {:#x}",
                insn.ip() - base_ip
            );
        }
        let cleanup_start = x86_epilogue_cleanup_start(insns, cursor);
        let cleanup = build_x86_tail_call_cleanup_candidate(
            bytes,
            base_ip,
            &insns[cleanup_start..idx],
            strip_set,
        )?;
        if let Some(previous) = &cleanup_bytes {
            if previous != &cleanup {
                bail!("x86 entry with bpf_tail_call has multiple incompatible return epilogues");
            }
        } else {
            cleanup_bytes = Some(cleanup);
        }
    }
    if !saw_return {
        bail!("x86 entry with bpf_tail_call has no return epilogue");
    }
    let (bpf_rbp_rsp_offset, bpf_rbp_is_live) =
        x86_bpf_rbp_location(prologue_regs, strip_set, stack_alloc)?;
    if bpf_rbp_rsp_offset.is_none() && !bpf_rbp_is_live {
        bail!("x86 entry with bpf_tail_call has no recoverable BPF rbp location");
    }
    Ok(X86TailCallFrame {
        cleanup_bytes: cleanup_bytes.unwrap_or_default(),
        bpf_rbp_rsp_offset,
        bpf_rbp_is_live,
    })
}

fn x86_entry_return_terminator(
    insn: &Instruction,
    symbol_end: u64,
    proof_return_jmp_target: Option<u64>,
) -> bool {
    if is_return(insn) {
        return true;
    }
    if proof_return_jmp_target.is_none() || insn.mnemonic() != Mnemonic::Jmp {
        return false;
    }
    let target = insn.near_branch_target();
    target == symbol_end || Some(target) == proof_return_jmp_target
}

fn read_x86_proof_callee_saved_mask(elf: &object::File) -> Result<u8> {
    let section = elf
        .section_by_name(".native_link_abi")
        .ok_or_else(|| anyhow!("x86 proof input missing .native_link_abi"))?;
    let data = section
        .data()
        .map_err(|err| anyhow!("read x86 .native_link_abi section: {err}"))?;
    let text = std::str::from_utf8(data)
        .map_err(|err| anyhow!("x86 .native_link_abi is not UTF-8: {err}"))?;
    let mut seen_version = false;
    let mut mask: Option<u8> = None;
    for (line_no, line) in text.lines().enumerate() {
        if line.is_empty() {
            continue;
        }
        let (key, value) = line
            .split_once('\t')
            .ok_or_else(|| anyhow!("invalid x86 .native_link_abi line {}", line_no + 1))?;
        if value.contains('\t') {
            bail!("invalid x86 .native_link_abi line {}", line_no + 1);
        }
        match key {
            "version" => {
                if value != "native-link-abi-v2" {
                    bail!("unsupported x86 .native_link_abi version {value:?}");
                }
                seen_version = true;
            }
            "callee_saved_mask" => {
                let parsed: u8 = value
                    .parse()
                    .map_err(|err| anyhow!("parse x86 callee_saved_mask {value:?}: {err}"))?;
                if parsed > 0xf {
                    bail!("x86 callee_saved_mask exceeds 4 bits: {parsed}");
                }
                mask = Some(parsed);
            }
            _ => bail!("unknown x86 .native_link_abi key {key:?}"),
        }
    }
    if !seen_version || mask.is_none() {
        bail!("x86 .native_link_abi missing required keys");
    }
    Ok(mask.unwrap())
}

fn x86_bpf_rbp_location(
    prologue_regs: &[Register],
    strip_set: &HashSet<Register>,
    stack_alloc: u64,
) -> Result<(Option<i32>, bool)> {
    let Some(rbp_idx) = prologue_regs.iter().position(|reg| *reg == Register::RBP) else {
        return Ok((None, true));
    };
    if strip_set.contains(&Register::RBP) {
        return Ok((None, true));
    }
    let kept_after_rbp = prologue_regs[rbp_idx + 1..]
        .iter()
        .filter(|reg| !strip_set.contains(reg))
        .count();
    let kept_after_bytes = u64::try_from(kept_after_rbp)
        .map_err(|_| anyhow!("x86 kept prologue register count overflow"))?
        .checked_mul(8)
        .ok_or_else(|| anyhow!("x86 kept prologue byte count overflow"))?;
    let offset = stack_alloc
        .checked_add(kept_after_bytes)
        .ok_or_else(|| anyhow!("x86 saved BPF rbp stack offset overflow"))?;
    let offset = i32::try_from(offset)
        .map_err(|_| anyhow!("x86 saved BPF rbp stack offset exceeds i32: {offset}"))?;
    Ok((Some(offset), false))
}

fn x86_epilogue_cleanup_start(insns: &[Instruction], first_pop_idx: usize) -> usize {
    if first_pop_idx == 0 {
        return first_pop_idx;
    }
    let prev = &insns[first_pop_idx - 1];
    if prev.mnemonic() == Mnemonic::Add
        && prev.op_count() >= 2
        && prev.op0_kind() == OpKind::Register
        && x86_gpr64_family(prev.op0_register()) == Some(Register::RSP)
        && matches!(
            prev.op1_kind(),
            OpKind::Immediate8
                | OpKind::Immediate8to16
                | OpKind::Immediate8to32
                | OpKind::Immediate8to64
                | OpKind::Immediate16
                | OpKind::Immediate32
                | OpKind::Immediate32to64
                | OpKind::Immediate64
        )
    {
        return first_pop_idx - 1;
    }
    first_pop_idx
}

fn x86_sub_rsp_imm(insn: &Instruction) -> Option<u64> {
    if insn.mnemonic() != Mnemonic::Sub
        || insn.op_count() < 2
        || insn.op0_kind() != OpKind::Register
        || x86_gpr64_family(insn.op0_register()) != Some(Register::RSP)
    {
        return None;
    }
    match insn.op1_kind() {
        OpKind::Immediate8
        | OpKind::Immediate8to16
        | OpKind::Immediate8to32
        | OpKind::Immediate8to64
        | OpKind::Immediate16
        | OpKind::Immediate32
        | OpKind::Immediate32to64
        | OpKind::Immediate64 => Some(insn.immediate64()),
        _ => None,
    }
}

fn build_x86_tail_call_cleanup_candidate(
    bytes: &[u8],
    base_ip: u64,
    epilogue: &[Instruction],
    strip_set: &HashSet<Register>,
) -> Result<Vec<u8>> {
    let mut out = Vec::new();
    for insn in epilogue {
        if let Some(reg) = x86_saved_pop_reg(insn) {
            if strip_set.contains(&reg) {
                continue;
            }
        }
        let local_ip = insn
            .ip()
            .checked_sub(base_ip)
            .ok_or_else(|| anyhow!("x86 epilogue instruction below entry base"))?;
        let len = insn.len();
        let start =
            usize::try_from(local_ip).map_err(|_| anyhow!("x86 epilogue offset exceeds usize"))?;
        let end = start
            .checked_add(len)
            .ok_or_else(|| anyhow!("x86 epilogue offset overflow"))?;
        let insn_bytes = bytes
            .get(start..end)
            .ok_or_else(|| anyhow!("x86 epilogue instruction bytes out of bounds"))?;
        out.extend_from_slice(insn_bytes);
    }
    Ok(out)
}

fn collect_x86_register_families(insns: &[Instruction]) -> HashSet<Register> {
    let mut out = HashSet::new();
    for insn in insns {
        for op_idx in 0..insn.op_count() {
            if insn.op_kind(op_idx) == OpKind::Register {
                if let Some(family) = x86_callee_saved_family(insn.op_register(op_idx)) {
                    out.insert(family);
                }
            }
        }
        if let Some(family) = x86_callee_saved_family(insn.memory_base()) {
            out.insert(family);
        }
        if let Some(family) = x86_callee_saved_family(insn.memory_index()) {
            out.insert(family);
        }
    }
    out
}

fn x86_entry_rename_is_safe(insns: &[Instruction], src: Register, dst: Register) -> bool {
    if !x86_family_needs_rex(dst) {
        return true;
    }
    for insn in insns {
        if x86_instruction_uses_family(insn, src) && x86_instruction_uses_high_byte_reg(insn) {
            return false;
        }
    }
    true
}

fn x86_family_needs_rex(reg: Register) -> bool {
    matches!(reg, Register::R13 | Register::R14 | Register::R15)
}

fn x86_instruction_uses_family(insn: &Instruction, family: Register) -> bool {
    for op_idx in 0..insn.op_count() {
        if insn.op_kind(op_idx) == OpKind::Register
            && x86_callee_saved_family(insn.op_register(op_idx)) == Some(family)
        {
            return true;
        }
    }
    x86_callee_saved_family(insn.memory_base()) == Some(family)
        || x86_callee_saved_family(insn.memory_index()) == Some(family)
}

fn x86_instruction_uses_high_byte_reg(insn: &Instruction) -> bool {
    for op_idx in 0..insn.op_count() {
        if insn.op_kind(op_idx) == OpKind::Register
            && matches!(
                insn.op_register(op_idx),
                Register::AH | Register::BH | Register::CH | Register::DH
            )
        {
            return true;
        }
    }
    false
}

fn remap_x86_entry_registers(
    insn: &mut Instruction,
    renames: &HashMap<Register, Register>,
) -> Result<()> {
    if renames.is_empty() {
        return Ok(());
    }
    for op_idx in 0..insn.op_count() {
        if insn.op_kind(op_idx) == OpKind::Register {
            let reg = insn.op_register(op_idx);
            if let Some(new_reg) = x86_remap_callee_saved_register(reg, renames)? {
                set_x86_op_register(insn, op_idx, new_reg)?;
            }
        }
    }
    if let Some(new_base) = x86_remap_callee_saved_register(insn.memory_base(), renames)? {
        insn.set_memory_base(new_base);
    }
    if let Some(new_index) = x86_remap_callee_saved_register(insn.memory_index(), renames)? {
        insn.set_memory_index(new_index);
    }
    Ok(())
}

fn set_x86_op_register(insn: &mut Instruction, op_idx: u32, reg: Register) -> Result<()> {
    match op_idx {
        0 => insn.set_op0_register(reg),
        1 => insn.set_op1_register(reg),
        2 => insn.set_op2_register(reg),
        3 => insn.set_op3_register(reg),
        4 => insn.set_op4_register(reg),
        _ => bail!("unsupported x86 operand index {op_idx}"),
    }
    Ok(())
}

fn x86_remap_callee_saved_register(
    reg: Register,
    renames: &HashMap<Register, Register>,
) -> Result<Option<Register>> {
    let Some(src_family) = x86_callee_saved_family(reg) else {
        return Ok(None);
    };
    let Some(&dst_family) = renames.get(&src_family) else {
        return Ok(None);
    };
    Ok(Some(x86_same_width_register(reg, dst_family)?))
}

fn x86_same_width_register(reg: Register, dst_family: Register) -> Result<Register> {
    let width = x86_callee_saved_width(reg)
        .ok_or_else(|| anyhow!("unsupported x86 callee-saved register variant {reg:?}"))?;
    match (dst_family, width) {
        (Register::RBX, X86RegWidth::Qword) => Ok(Register::RBX),
        (Register::RBX, X86RegWidth::Dword) => Ok(Register::EBX),
        (Register::RBX, X86RegWidth::Word) => Ok(Register::BX),
        (Register::RBX, X86RegWidth::Byte) => Ok(Register::BL),
        (Register::R13, X86RegWidth::Qword) => Ok(Register::R13),
        (Register::R13, X86RegWidth::Dword) => Ok(Register::R13D),
        (Register::R13, X86RegWidth::Word) => Ok(Register::R13W),
        (Register::R13, X86RegWidth::Byte) => Ok(Register::R13L),
        (Register::R14, X86RegWidth::Qword) => Ok(Register::R14),
        (Register::R14, X86RegWidth::Dword) => Ok(Register::R14D),
        (Register::R14, X86RegWidth::Word) => Ok(Register::R14W),
        (Register::R14, X86RegWidth::Byte) => Ok(Register::R14L),
        (Register::R15, X86RegWidth::Qword) => Ok(Register::R15),
        (Register::R15, X86RegWidth::Dword) => Ok(Register::R15D),
        (Register::R15, X86RegWidth::Word) => Ok(Register::R15W),
        (Register::R15, X86RegWidth::Byte) => Ok(Register::R15L),
        _ => bail!("unsupported x86 ABI rename target {dst_family:?}"),
    }
}

#[derive(Clone, Copy)]
enum X86RegWidth {
    Qword,
    Dword,
    Word,
    Byte,
}

fn x86_callee_saved_width(reg: Register) -> Option<X86RegWidth> {
    match reg {
        Register::RBX
        | Register::RBP
        | Register::R12
        | Register::R13
        | Register::R14
        | Register::R15 => Some(X86RegWidth::Qword),
        Register::EBX
        | Register::EBP
        | Register::R12D
        | Register::R13D
        | Register::R14D
        | Register::R15D => Some(X86RegWidth::Dword),
        Register::BX
        | Register::BP
        | Register::R12W
        | Register::R13W
        | Register::R14W
        | Register::R15W => Some(X86RegWidth::Word),
        Register::BL
        | Register::BPL
        | Register::R12L
        | Register::R13L
        | Register::R14L
        | Register::R15L => Some(X86RegWidth::Byte),
        _ => None,
    }
}

fn x86_callee_saved_family(reg: Register) -> Option<Register> {
    match reg {
        Register::RBX | Register::EBX | Register::BX | Register::BL => Some(Register::RBX),
        Register::RBP | Register::EBP | Register::BP | Register::BPL => Some(Register::RBP),
        Register::R12 | Register::R12D | Register::R12W | Register::R12L => Some(Register::R12),
        Register::R13 | Register::R13D | Register::R13W | Register::R13L => Some(Register::R13),
        Register::R14 | Register::R14D | Register::R14W | Register::R14L => Some(Register::R14),
        Register::R15 | Register::R15D | Register::R15W | Register::R15L => Some(Register::R15),
        _ => None,
    }
}

fn x86_gpr64_family(reg: Register) -> Option<Register> {
    match reg {
        Register::RAX | Register::EAX | Register::AX | Register::AL | Register::AH => {
            Some(Register::RAX)
        }
        Register::RCX | Register::ECX | Register::CX | Register::CL | Register::CH => {
            Some(Register::RCX)
        }
        Register::RDX | Register::EDX | Register::DX | Register::DL | Register::DH => {
            Some(Register::RDX)
        }
        Register::RBX | Register::EBX | Register::BX | Register::BL | Register::BH => {
            Some(Register::RBX)
        }
        Register::RSP | Register::ESP | Register::SP | Register::SPL => Some(Register::RSP),
        Register::RBP | Register::EBP | Register::BP | Register::BPL => Some(Register::RBP),
        Register::RSI | Register::ESI | Register::SI | Register::SIL => Some(Register::RSI),
        Register::RDI | Register::EDI | Register::DI | Register::DIL => Some(Register::RDI),
        Register::R8 | Register::R8D | Register::R8W | Register::R8L => Some(Register::R8),
        Register::R9 | Register::R9D | Register::R9W | Register::R9L => Some(Register::R9),
        Register::R10 | Register::R10D | Register::R10W | Register::R10L => Some(Register::R10),
        Register::R11 | Register::R11D | Register::R11W | Register::R11L => Some(Register::R11),
        Register::R12 | Register::R12D | Register::R12W | Register::R12L => Some(Register::R12),
        Register::R13 | Register::R13D | Register::R13W | Register::R13L => Some(Register::R13),
        Register::R14 | Register::R14D | Register::R14W | Register::R14L => Some(Register::R14),
        Register::R15 | Register::R15D | Register::R15W | Register::R15L => Some(Register::R15),
        _ => None,
    }
}

fn x86_indirect_call_register(insn: &Instruction) -> Option<Register> {
    if !matches!(insn.flow_control(), FlowControl::IndirectCall) {
        return None;
    }
    if insn.op_count() == 0 || insn.op0_kind() != OpKind::Register {
        return None;
    }
    x86_gpr64_family(insn.op0_register())
}

fn x86_encoded_instruction_is_indirect_call(blob: &[u8], off: usize) -> Result<bool> {
    if off >= blob.len() {
        bail!("x86 instruction offset {off:#x} exceeds encoded blob size");
    }
    let mut decoder = Decoder::with_ip(64, &blob[off..], off as u64, DecoderOptions::NONE);
    let insn = decoder.decode();
    if insn.is_invalid() {
        bail!("invalid encoded x86 instruction at blob offset {off:#x}");
    }
    Ok(matches!(insn.flow_control(), FlowControl::IndirectCall))
}

fn x86_written_gpr_family(insn: &Instruction) -> Option<Register> {
    if matches!(
        insn.flow_control(),
        FlowControl::Call | FlowControl::IndirectCall
    ) {
        return None;
    }
    if insn.op_count() == 0 || insn.op0_kind() != OpKind::Register {
        return None;
    }
    match insn.mnemonic() {
        Mnemonic::Cmp | Mnemonic::Test | Mnemonic::Push => None,
        _ => x86_gpr64_family(insn.op0_register()),
    }
}

fn x86_saved_push_reg(insn: &Instruction) -> Option<Register> {
    if insn.mnemonic() != Mnemonic::Push {
        return None;
    }
    let reg = insn.op0_register();
    if is_x86_saved_reg(reg) {
        Some(reg)
    } else {
        None
    }
}

fn x86_saved_pop_reg(insn: &Instruction) -> Option<Register> {
    if insn.mnemonic() != Mnemonic::Pop {
        return None;
    }
    let reg = insn.op0_register();
    if is_x86_saved_reg(reg) {
        Some(reg)
    } else {
        None
    }
}

fn is_x86_saved_reg(reg: Register) -> bool {
    matches!(
        reg,
        Register::RBX
            | Register::RBP
            | Register::R12
            | Register::R13
            | Register::R14
            | Register::R15
    )
}

fn is_x86_entry_strippable_saved_reg(reg: Register) -> bool {
    matches!(
        reg,
        Register::RBX | Register::R13 | Register::R14 | Register::R15
    )
}

fn x86_entry_callee_saved_mask_bit(reg: Register) -> Option<u8> {
    match reg {
        Register::RBX => Some(1 << 0),
        Register::R13 => Some(1 << 1),
        Register::R14 => Some(1 << 2),
        Register::R15 => Some(1 << 3),
        _ => None,
    }
}

fn is_return(insn: &Instruction) -> bool {
    matches!(
        insn.code(),
        Code::Retnq | Code::Retnq_imm16 | Code::Retfq | Code::Retfq_imm16
    )
}

fn is_alignment_nop(insn: &Instruction) -> bool {
    use iced_x86::Mnemonic;
    insn.mnemonic() == Mnemonic::Nop
}

/// Reject any PC-relative reference whose target sits outside the union
/// of `included` symbols' byte ranges.
fn validate_no_external_refs<F>(
    insn: &Instruction,
    included_ranges: &[(u64, u64)],
    mut has_pc_relative_relocation: F,
) -> Result<()>
where
    F: FnMut(u64) -> bool,
{
    let in_any = |a: u64| included_ranges.iter().any(|&(lo, hi)| a >= lo && a < hi);
    let in_any_or_end = |a: u64| included_ranges.iter().any(|&(lo, hi)| a >= lo && a <= hi);

    let fc = insn.flow_control();
    if matches!(
        fc,
        FlowControl::UnconditionalBranch | FlowControl::ConditionalBranch | FlowControl::Call
    ) {
        let target = insn.near_branch_target();
        let relocated_call = matches!(fc, FlowControl::Call)
            && (0..insn.len() as u64).any(&mut has_pc_relative_relocation);
        if target != 0 && !in_any_or_end(target) && !relocated_call {
            bail!(
                "instruction at IP {:#x} branches to {:#x} outside the included symbols",
                insn.ip(),
                target
            );
        }
    }
    /* Indirect branches (jump tables) are still rejected: clang's
     * `-fno-jump-tables` flag eliminates them, so any that show up
     * here are something else and likely unsafe to splat.
     *
     * Indirect calls are ALLOWED -- with `-fno-plt`, clang emits
     * `call *[rip+disp32]` against a R_X86_64_GOTPCREL reloc for every
     * external function call. The relocation handler points the disp32
     * at an in-blob literal pool entry holding the kernel address. */
    if matches!(fc, FlowControl::IndirectBranch) {
        bail!(
            "instruction at IP {:#x} is an indirect branch; rebuild with -fno-jump-tables",
            insn.ip()
        );
    }
    for op_i in 0..insn.op_count() {
        if insn.op_kind(op_i) == OpKind::Memory && insn.is_ip_rel_memory_operand() {
            let t = insn.ip_rel_memory_address();
            let relocated = (0..insn.len() as u64).any(&mut has_pc_relative_relocation);
            if !in_any(t) && !relocated {
                bail!(
                    "instruction at IP {:#x} reads RIP-relative {:#x} outside the included symbols",
                    insn.ip(),
                    t
                );
            }
        }
        if insn.op_kind(op_i) == OpKind::Memory
            && insn.memory_base() == Register::None
            && insn.memory_index() == Register::None
            && insn.memory_displ_size() != 0
            && !insn.is_ip_rel_memory_operand()
        {
            let disp = insn.memory_displacement64();
            if disp != 0 {
                bail!(
                    "instruction at IP {:#x} uses absolute memory address {:#x}; \
                     userspace constants don't map into kernel",
                    insn.ip(),
                    disp
                );
            }
        }
    }
    Ok(())
}

fn declared_bytes(bytes: &[u8]) -> Result<Instruction> {
    Instruction::with_declare_byte(bytes).map_err(|e| anyhow!("declare_byte: {e:?}"))
}

fn declared_byte_chunks(bytes: &[u8]) -> Result<Vec<Instruction>> {
    bytes.chunks(16).map(declared_bytes).collect()
}

fn build_x86_helper_call_rel32_slot() -> Result<Instruction> {
    declared_bytes(&X86_HELPER_CALL_REL32_SLOT)
}

fn push_x86_helper_call_reloc(
    local: &mut Vec<Instruction>,
    kinds: &mut Vec<Option<PatchKind>>,
    insn_local_ip: &mut Vec<u64>,
    local_ip: u64,
    helper_addr: u64,
) -> Result<()> {
    let insn = build_x86_helper_call_rel32_slot()?;
    push_x86_replacement(
        local,
        kinds,
        insn_local_ip,
        local_ip,
        insn,
        Some(PatchKind::HelperCallRel32 {
            target_addr: helper_addr,
        }),
    );
    Ok(())
}

fn x86_required_u32_helper_arg(
    helper_addrs: &HashMap<String, u64>,
    key: &str,
    label: &str,
) -> Result<u32> {
    let value = *helper_addrs
        .get(key)
        .ok_or_else(|| anyhow!("x86 tail_call lowering missing link-plan helper {key}"))?;
    u32::try_from(value).map_err(|_| anyhow!("{label} does not fit u32: {value:#x}"))
}

fn append_x86_jcc_rel32(bytes: &mut Vec<u8>, opcode: u8) -> usize {
    bytes.extend_from_slice(&[0x0F, opcode]);
    let disp_offset = bytes.len();
    bytes.extend_from_slice(&0i32.to_le_bytes());
    disp_offset
}

fn patch_x86_rel32(bytes: &mut [u8], disp_offset: usize, target: usize) -> Result<()> {
    let next = disp_offset
        .checked_add(4)
        .ok_or_else(|| anyhow!("x86 rel32 offset overflow"))?;
    let disp = target as isize - next as isize;
    let disp_i32 = i32::try_from(disp).map_err(|_| {
        anyhow!("x86 rel32 target out of range: offset {disp_offset}, target {target}")
    })?;
    bytes[disp_offset..disp_offset + 4].copy_from_slice(&disp_i32.to_le_bytes());
    Ok(())
}

fn append_x86_stub_callee_pop(bytes: &mut Vec<u8>, callee_saved_mask: u8) {
    if callee_saved_mask & (1 << 3) != 0 {
        bytes.extend_from_slice(&[0x41, 0x5F]); // pop r15
    }
    if callee_saved_mask & (1 << 2) != 0 {
        bytes.extend_from_slice(&[0x41, 0x5E]); // pop r14
    }
    if callee_saved_mask & (1 << 1) != 0 {
        bytes.extend_from_slice(&[0x41, 0x5D]); // pop r13
    }
    if callee_saved_mask & (1 << 0) != 0 {
        bytes.push(0x5B); // pop rbx
    }
}

fn append_x86_add_rcx_imm(bytes: &mut Vec<u8>, imm: u32) {
    if imm <= 0x7f {
        bytes.extend_from_slice(&[0x48, 0x83, 0xC1, imm as u8]);
    } else {
        bytes.extend_from_slice(&[0x48, 0x81, 0xC1]);
        bytes.extend_from_slice(&imm.to_le_bytes());
    }
}

fn build_x86_tail_call_inline(
    helper_addrs: &HashMap<String, u64>,
    callee_saved_mask: u8,
    native_cleanup: &[u8],
    saved_bpf_rbp_rsp_offset: Option<i32>,
    bpf_rbp_is_live: bool,
    constant_index: Option<u32>,
    constant_index_max_entries: Option<u32>,
) -> Result<Vec<Instruction>> {
    const MAX_TAIL_CALL_CNT: u8 = 33;
    let map_max_entries = x86_required_u32_helper_arg(
        helper_addrs,
        X86_BPF_MAP_MAX_ENTRIES_OFFSET_KEY,
        "struct bpf_map.max_entries offset",
    )?;
    let array_ptrs = x86_required_u32_helper_arg(
        helper_addrs,
        X86_BPF_ARRAY_PTRS_OFFSET_KEY,
        "struct bpf_array.ptrs offset",
    )?;
    let prog_bpf_func = x86_required_u32_helper_arg(
        helper_addrs,
        X86_BPF_PROG_BPF_FUNC_OFFSET_KEY,
        "struct bpf_prog.bpf_func offset",
    )?;
    let tail_call_offset = x86_required_u32_helper_arg(
        helper_addrs,
        X86_TAIL_CALL_OFFSET_KEY,
        "x86 BPF tail-call entry offset",
    )?;
    if callee_saved_mask > 0xf {
        bail!("x86 tail_call callee-saved mask exceeds 4 bits");
    }

    let mut bytes = Vec::new();
    let constant_index_in_bounds = match (constant_index, constant_index_max_entries) {
        (Some(index), Some(max_entries)) if index >= max_entries => return Ok(Vec::new()),
        (Some(_), Some(_)) => true,
        _ => false,
    };
    let jbe_out = if constant_index_in_bounds {
        None
    } else if let Some(index) = constant_index {
        bytes.extend_from_slice(&[0x81, 0xBE]); // cmp dword ptr [rsi + disp32], imm32
        bytes.extend_from_slice(&map_max_entries.to_le_bytes());
        bytes.extend_from_slice(&index.to_le_bytes());
        Some(append_x86_jcc_rel32(&mut bytes, 0x86))
    } else {
        bytes.extend_from_slice(&[0x89, 0xD2]); // mov edx, edx
        bytes.extend_from_slice(&[0x39, 0x96]); // cmp dword ptr [rsi + disp32], edx
        bytes.extend_from_slice(&map_max_entries.to_le_bytes());
        Some(append_x86_jcc_rel32(&mut bytes, 0x86))
    };

    if let Some(offset) = saved_bpf_rbp_rsp_offset {
        bytes.extend_from_slice(&[0x48, 0x8B, 0x84, 0x24]); // mov rax, [rsp + disp32]
        bytes.extend_from_slice(&offset.to_le_bytes());
        bytes.extend_from_slice(&[0x48, 0x8B, 0x80]); // mov rax, [rax - 16]
    } else if bpf_rbp_is_live {
        bytes.extend_from_slice(&[0x48, 0x8B, 0x85]); // mov rax, [rbp - 16]
    } else {
        bail!("x86 bpf_tail_call lowering missing BPF rbp location");
    }
    bytes.extend_from_slice(&(-16i32).to_le_bytes());
    bytes.extend_from_slice(&[0x48, 0x83, 0x38, MAX_TAIL_CALL_CNT]); // cmp qword [rax], 33
    let jae_out = append_x86_jcc_rel32(&mut bytes, 0x83);

    if let Some(index) = constant_index {
        let ptr_disp = array_ptrs
            .checked_add(index.checked_mul(8).ok_or_else(|| {
                anyhow!("x86 tail_call constant index byte offset overflow: {index}")
            })?)
            .ok_or_else(|| anyhow!("x86 tail_call array ptr displacement overflow"))?;
        bytes.extend_from_slice(&[0x48, 0x8B, 0x8E]); // mov rcx, [rsi + disp32]
        bytes.extend_from_slice(&ptr_disp.to_le_bytes());
    } else {
        bytes.extend_from_slice(&[0x48, 0x8B, 0x8C, 0xD6]); // mov rcx, [rsi + rdx*8 + disp32]
        bytes.extend_from_slice(&array_ptrs.to_le_bytes());
    }
    bytes.extend_from_slice(&[0x48, 0x85, 0xC9]); // test rcx, rcx
    let je_out = append_x86_jcc_rel32(&mut bytes, 0x84);

    bytes.extend_from_slice(&[0x48, 0x83, 0x00, 0x01]); // add qword ptr [rax], 1
    bytes.extend_from_slice(native_cleanup);
    append_x86_stub_callee_pop(&mut bytes, callee_saved_mask);
    bytes.extend_from_slice(&[0x48, 0x83, 0xC4, 0x10]); // drop tail_call_cnt_ptr/tail_call_cnt
    bytes.extend_from_slice(&[0x48, 0x8B, 0x89]); // mov rcx, [rcx + disp32]
    bytes.extend_from_slice(&prog_bpf_func.to_le_bytes());
    append_x86_add_rcx_imm(&mut bytes, tail_call_offset);
    bytes.extend_from_slice(&[0xFF, 0xE1]); // jmp rcx

    let out = bytes.len();
    if let Some(jbe_out) = jbe_out {
        patch_x86_rel32(&mut bytes, jbe_out, out)?;
    }
    patch_x86_rel32(&mut bytes, jae_out, out)?;
    patch_x86_rel32(&mut bytes, je_out, out)?;
    declared_byte_chunks(&bytes)
}

fn x86_gpr64_encoding(reg: Register) -> Result<(u8, bool)> {
    match reg {
        Register::RAX => Ok((0, false)),
        Register::RCX => Ok((1, false)),
        Register::RDX => Ok((2, false)),
        Register::RBX => Ok((3, false)),
        Register::RSP => Ok((4, false)),
        Register::RBP => Ok((5, false)),
        Register::RSI => Ok((6, false)),
        Register::RDI => Ok((7, false)),
        Register::R8 => Ok((0, true)),
        Register::R9 => Ok((1, true)),
        Register::R10 => Ok((2, true)),
        Register::R11 => Ok((3, true)),
        Register::R12 => Ok((4, true)),
        Register::R13 => Ok((5, true)),
        Register::R14 => Ok((6, true)),
        Register::R15 => Ok((7, true)),
        _ => bail!("unsupported x86 movabs destination register: {reg:?}"),
    }
}

fn build_x86_movabs_reg(reg: Register, imm: u64) -> Result<Instruction> {
    let (low, high) = x86_gpr64_encoding(reg)?;
    let rex = 0x48 | if high { 0x01 } else { 0x00 };
    let mut bytes = Vec::with_capacity(10);
    bytes.push(rex);
    bytes.push(0xB8 + low);
    bytes.extend_from_slice(&imm.to_le_bytes());
    declared_bytes(&bytes)
}

fn x86_sign_extended_imm32(imm: u64) -> Option<i32> {
    let v = imm as i32;
    if (v as i64) as u64 == imm {
        Some(v)
    } else {
        None
    }
}

fn append_x86_mov_reg_imm64(bytes: &mut Vec<u8>, reg: Register, imm: u64) -> Result<()> {
    let (low, high) = x86_gpr64_encoding(reg)?;
    let rex = 0x48 | if high { 0x01 } else { 0x00 };
    if let Some(imm32) = x86_sign_extended_imm32(imm) {
        bytes.extend_from_slice(&[rex, 0xC7, 0xC0 | low]);
        bytes.extend_from_slice(&imm32.to_le_bytes());
    } else {
        bytes.push(rex);
        bytes.push(0xB8 + low);
        bytes.extend_from_slice(&imm.to_le_bytes());
    }
    Ok(())
}

fn append_x86_scale_rax(bytes: &mut Vec<u8>, elem_size: u32) -> Result<()> {
    if elem_size == 0 {
        bail!("array lookup elem_size must be non-zero");
    }
    if elem_size.is_power_of_two() {
        let shift = elem_size.trailing_zeros();
        if shift != 0 {
            bytes.extend_from_slice(&[0x48, 0xC1, 0xE0, shift as u8]); // shl rax, shift
        }
    } else {
        let imm = i32::try_from(elem_size)
            .map_err(|_| anyhow!("array elem_size too large for x86 imul imm32: {elem_size}"))?;
        bytes.extend_from_slice(&[0x48, 0x69, 0xC0]); // imul rax, rax, imm32
        bytes.extend_from_slice(&imm.to_le_bytes());
    }
    Ok(())
}

fn x86_sib_scale(elem_size: u32) -> Option<u8> {
    match elem_size {
        1 => Some(0),
        2 => Some(1),
        4 => Some(2),
        8 => Some(3),
        _ => None,
    }
}

fn append_x86_array_value_ptr(
    bytes: &mut Vec<u8>,
    elem_size: u32,
    value_offset: u32,
) -> Result<()> {
    if let Some(scale) = x86_sib_scale(elem_size) {
        bytes.extend_from_slice(&[0x48, 0x8D, 0x84, (scale << 6) | 0x07]);
        bytes.extend_from_slice(&value_offset.to_le_bytes());
        return Ok(());
    }

    append_x86_scale_rax(bytes, elem_size)?;
    bytes.extend_from_slice(&[0x48, 0x01, 0xF8]); // add rax, rdi
    if value_offset != 0 {
        append_x86_add_rax_imm(bytes, value_offset);
    }
    Ok(())
}

fn build_x86_array_lookup(spec: &LookupSiteSpec) -> Result<Vec<Instruction>> {
    if spec.max_entries == 0 {
        bail!("array lookup max_entries must be non-zero");
    }
    if u64::from(spec.index_mask) + 1 < u64::from(spec.max_entries) {
        bail!(
            "array lookup index_mask {} is smaller than max_entries {}",
            spec.index_mask,
            spec.max_entries
        );
    }

    let mut body = Vec::new();
    append_x86_array_value_ptr(&mut body, spec.elem_size, spec.value_offset)?;

    if matches!(spec.kind, LookupKind::PerCpuArray) {
        if spec.percpu_base_addr == 0 {
            bail!("percpu array lookup missing this_cpu_off address");
        }
        body.extend_from_slice(&[0x48, 0x8B, 0x00]); // mov rax, [rax]
        body.extend_from_slice(&[0x65, 0x48, 0x03, 0x04, 0x25]); // add rax, gs:[disp32]
        body.extend_from_slice(&(spec.percpu_base_addr as u32).to_le_bytes());
    }

    body.extend_from_slice(&[0xEB, 0x02]); // jmp over null return
    let body_len = u8::try_from(body.len())
        .map_err(|_| anyhow!("array lookup inline body too large: {} bytes", body.len()))?;

    let mut bytes = Vec::new();
    bytes.extend_from_slice(&[0x8B, 0x06]); // mov eax, [rsi]
    append_x86_cmp_eax_imm(&mut bytes, spec.max_entries);
    bytes.extend_from_slice(&[0x73, body_len]); // jae null
    bytes.extend_from_slice(&body);
    bytes.extend_from_slice(&[0x31, 0xC0]); // xor eax, eax

    declared_byte_chunks(&bytes)
}

fn append_x86_cmp_byte_rax_disp32_imm(bytes: &mut Vec<u8>, disp: u32, imm: u8) {
    bytes.extend_from_slice(&[0x80, 0xB8]); // cmp byte ptr [rax+disp32], imm8
    bytes.extend_from_slice(&disp.to_le_bytes());
    bytes.push(imm);
}

fn append_x86_mov_byte_rax_disp32_imm(bytes: &mut Vec<u8>, disp: u32, imm: u8) {
    bytes.extend_from_slice(&[0xC6, 0x80]); // mov byte ptr [rax+disp32], imm8
    bytes.extend_from_slice(&disp.to_le_bytes());
    bytes.push(imm);
}

fn build_x86_lookup_call_postprocess(spec: &LookupSiteSpec) -> Result<Vec<Instruction>> {
    let mut body = Vec::new();
    match spec.kind {
        LookupKind::Call | LookupKind::Array | LookupKind::PerCpuArray => {}
        LookupKind::Hash => {
            append_x86_add_rax_imm(&mut body, spec.key_offset);
        }
        LookupKind::HashOfMaps => {
            append_x86_add_rax_imm(&mut body, spec.key_offset);
            body.extend_from_slice(&[0x48, 0x8B, 0x00]); // mov rax, [rax]
        }
        LookupKind::LruHash => {
            append_x86_cmp_byte_rax_disp32_imm(&mut body, spec.value_offset, 0);
            let skip_store = append_x86_jcc_rel8(&mut body, 0x75); // jne skip ref update
            append_x86_mov_byte_rax_disp32_imm(&mut body, spec.value_offset, 1);
            let after_store = body.len();
            patch_x86_rel8(&mut body, skip_store, after_store)?;
            append_x86_add_rax_imm(&mut body, spec.key_offset);
        }
        LookupKind::PerCpuHash => {
            if spec.percpu_base_addr == 0 {
                bail!("percpu hash lookup missing this_cpu_off address");
            }
            append_x86_add_rax_imm(&mut body, spec.key_offset);
            body.extend_from_slice(&[0x48, 0x8B, 0x00]); // mov rax, [rax]
            body.extend_from_slice(&[0x65, 0x48, 0x03, 0x04, 0x25]); // add rax, gs:[disp32]
            body.extend_from_slice(&(spec.percpu_base_addr as u32).to_le_bytes());
        }
    }
    if body.is_empty() {
        return Ok(Vec::new());
    }
    let body_len = u8::try_from(body.len())
        .map_err(|_| anyhow!("lookup call postprocess too large: {} bytes", body.len()))?;

    let mut bytes = Vec::new();
    bytes.extend_from_slice(&[0x48, 0x85, 0xC0]); // test rax, rax
    bytes.extend_from_slice(&[0x74, body_len]); // je done
    bytes.extend_from_slice(&body);
    declared_byte_chunks(&bytes)
}

fn append_x86_add_rax_imm(bytes: &mut Vec<u8>, key_offset: u32) {
    if key_offset <= 0x7f {
        bytes.extend_from_slice(&[0x48, 0x83, 0xC0, key_offset as u8]);
    } else {
        bytes.extend_from_slice(&[0x48, 0x05]);
        bytes.extend_from_slice(&key_offset.to_le_bytes());
    }
}

fn append_x86_add_rdi_imm(bytes: &mut Vec<u8>, offset: u32) {
    if offset == 0 {
        return;
    }
    if offset <= 0x7f {
        bytes.extend_from_slice(&[0x48, 0x83, 0xC7, offset as u8]);
    } else {
        bytes.extend_from_slice(&[0x48, 0x81, 0xC7]);
        bytes.extend_from_slice(&offset.to_le_bytes());
    }
}

fn append_x86_cmp_eax_imm(bytes: &mut Vec<u8>, imm: u32) {
    if imm <= 0x7f {
        bytes.extend_from_slice(&[0x83, 0xF8, imm as u8]);
    } else {
        bytes.push(0x3D);
        bytes.extend_from_slice(&imm.to_le_bytes());
    }
}

fn append_x86_array_value_ptr_rdi(
    bytes: &mut Vec<u8>,
    elem_size: u32,
    value_offset: u32,
) -> Result<()> {
    if let Some(scale) = x86_sib_scale(elem_size) {
        bytes.extend_from_slice(&[0x48, 0x8D, 0xBC, (scale << 6) | 0x07]);
        bytes.extend_from_slice(&value_offset.to_le_bytes());
        return Ok(());
    }

    append_x86_scale_rax(bytes, elem_size)?;
    bytes.extend_from_slice(&[0x48, 0x01, 0xC7]); // add rdi, rax
    append_x86_add_rdi_imm(bytes, value_offset);
    Ok(())
}

fn append_x86_copy_value_to_rdi(bytes: &mut Vec<u8>, value_size: u32) -> Result<()> {
    match value_size {
        1 => bytes.extend_from_slice(&[0x8A, 0x02, 0x88, 0x07]), // mov al,[rdx]; mov [rdi],al
        2 => bytes.extend_from_slice(&[0x66, 0x8B, 0x02, 0x66, 0x89, 0x07]),
        4 => bytes.extend_from_slice(&[0x8B, 0x02, 0x89, 0x07]),
        8 => bytes.extend_from_slice(&[0x48, 0x8B, 0x02, 0x48, 0x89, 0x07]),
        _ => bail!("unsupported x86 array update value size: {value_size}"),
    }
    Ok(())
}

fn append_x86_jcc_rel8(bytes: &mut Vec<u8>, opcode: u8) -> usize {
    bytes.push(opcode);
    bytes.push(0);
    bytes.len() - 1
}

fn patch_x86_rel8(bytes: &mut [u8], disp_offset: usize, target: usize) -> Result<()> {
    let next = disp_offset
        .checked_add(1)
        .ok_or_else(|| anyhow!("x86 rel8 offset overflow"))?;
    let disp = target as isize - next as isize;
    let disp_i8 = i8::try_from(disp).map_err(|_| {
        anyhow!("x86 rel8 target out of range: offset {disp_offset}, target {target}")
    })?;
    bytes[disp_offset] = disp_i8 as u8;
    Ok(())
}

fn append_x86_mov_rax_i32(bytes: &mut Vec<u8>, value: i32) -> Result<()> {
    append_x86_mov_reg_imm64(bytes, Register::RAX, value as i64 as u64)
}

fn build_x86_array_update(spec: &UpdateSiteSpec) -> Result<Vec<Instruction>> {
    if !matches!(spec.kind, UpdateKind::Array | UpdateKind::PerCpuArray) {
        bail!("update kind {:?} is not an array-style inline", spec.kind);
    }
    if spec.max_entries == 0 {
        bail!("array update max_entries must be non-zero");
    }
    if spec.elem_size == 0 {
        bail!("array update elem_size must be non-zero");
    }
    if !matches!(spec.value_size, 1 | 2 | 4 | 8) {
        bail!("array update value_size must be 1, 2, 4, or 8");
    }
    if matches!(spec.kind, UpdateKind::PerCpuArray) && spec.percpu_base_addr == 0 {
        bail!("percpu array update missing this_cpu_off address");
    }

    let mut body = Vec::new();
    append_x86_array_value_ptr_rdi(&mut body, spec.elem_size, spec.value_offset)?;
    if matches!(spec.kind, UpdateKind::PerCpuArray) {
        body.extend_from_slice(&[0x48, 0x8B, 0x3F]); // mov rdi, [rdi]
        body.extend_from_slice(&[0x65, 0x48, 0x03, 0x3C, 0x25]); // add rdi, gs:[disp32]
        body.extend_from_slice(&(spec.percpu_base_addr as u32).to_le_bytes());
    }
    append_x86_copy_value_to_rdi(&mut body, spec.value_size)?;
    body.extend_from_slice(&[0x31, 0xC0]); // xor eax, eax

    let mut bytes = Vec::new();
    bytes.extend_from_slice(&[0x8B, 0x06]); // mov eax, [rsi]
    append_x86_cmp_eax_imm(&mut bytes, spec.max_entries);
    let bounds_jmp = append_x86_jcc_rel8(&mut bytes, 0x73); // jae bounds
    bytes.extend_from_slice(&[0x83, 0xF9, 0x01]); // cmp ecx, BPF_NOEXIST
    let eexist_jmp = append_x86_jcc_rel8(&mut bytes, 0x74); // je eexist
    bytes.extend_from_slice(&[0x83, 0xF9, 0x02]); // cmp ecx, BPF_EXIST
    let invalid_jmp = append_x86_jcc_rel8(&mut bytes, 0x77); // ja invalid
    bytes.extend_from_slice(&body);
    let success_end_jmp = append_x86_jcc_rel8(&mut bytes, 0xEB);

    let bounds_off = bytes.len();
    append_x86_mov_rax_i32(&mut bytes, -7)?; // -E2BIG
    let bounds_end_jmp = append_x86_jcc_rel8(&mut bytes, 0xEB);

    let eexist_off = bytes.len();
    append_x86_mov_rax_i32(&mut bytes, -17)?; // -EEXIST
    let eexist_end_jmp = append_x86_jcc_rel8(&mut bytes, 0xEB);

    let invalid_off = bytes.len();
    append_x86_mov_rax_i32(&mut bytes, -22)?; // -EINVAL

    let end_off = bytes.len();
    patch_x86_rel8(&mut bytes, bounds_jmp, bounds_off)?;
    patch_x86_rel8(&mut bytes, eexist_jmp, eexist_off)?;
    patch_x86_rel8(&mut bytes, invalid_jmp, invalid_off)?;
    patch_x86_rel8(&mut bytes, success_end_jmp, end_off)?;
    patch_x86_rel8(&mut bytes, bounds_end_jmp, end_off)?;
    patch_x86_rel8(&mut bytes, eexist_end_jmp, end_off)?;

    declared_byte_chunks(&bytes)
}

#[cfg(test)]
mod tests {
    use super::*;

    fn decode_x86(bytes: &[u8]) -> Result<Vec<Instruction>> {
        let mut decoder = Decoder::with_ip(64, bytes, 0, DecoderOptions::NONE);
        let mut out = Vec::new();
        while decoder.can_decode() {
            let insn = decoder.decode();
            if insn.is_invalid() {
                bail!("invalid test instruction at {:#x}", insn.ip());
            }
            out.push(insn);
        }
        Ok(out)
    }

    fn test_update_site(map_name: &str, target_addr: u64) -> UpdateSiteSpec {
        UpdateSiteSpec {
            kind: UpdateKind::Call,
            target_addr,
            max_entries: 0,
            elem_size: 0,
            value_size: 0,
            value_offset: 0,
            percpu_base_addr: 0,
            map_name: Some(map_name.to_string()),
        }
    }

    #[test]
    fn update_selection_prefers_native_map_over_ordinal_order() {
        let sites = vec![
            test_update_site("wrong_map", 0x1000),
            test_update_site("target_map", 0x2000),
        ];
        let mut used = vec![false; sites.len()];

        let selected = select_update_site(&sites, &mut used, 0, Some("target_map"));

        assert_eq!(selected, Some(("1".to_string(), 1)));
        assert_eq!(used, vec![false, true]);
    }

    #[test]
    fn helper_call_reloc_slot_encodes_only_call_rel32() -> Result<()> {
        let insn = build_x86_helper_call_rel32_slot()?;
        let encoded = encode_x86_local_block("helper_slot", 5, &[insn], &[0])?;

        assert_eq!(encoded.code_buffer, [0xE8, 0, 0, 0, 0]);
        Ok(())
    }

    #[test]
    fn tail_call_constant_index_uses_fixed_array_slot() -> Result<()> {
        let helper_addrs = HashMap::from([
            (X86_BPF_MAP_MAX_ENTRIES_OFFSET_KEY.to_string(), 0x10),
            (X86_BPF_ARRAY_PTRS_OFFSET_KEY.to_string(), 0x20),
            (X86_BPF_PROG_BPF_FUNC_OFFSET_KEY.to_string(), 0x30),
            (X86_TAIL_CALL_OFFSET_KEY.to_string(), 0x0c),
        ]);
        let insns = build_x86_tail_call_inline(&helper_addrs, 0, &[], None, true, Some(3), None)?;
        let local_ips: Vec<u64> = (0..insns.len() as u64).collect();
        let encoded = encode_x86_local_block("tail_call_constant_index", 4096, &insns, &local_ips)?;
        let bytes = encoded.code_buffer;

        assert!(bytes
            .windows(10)
            .any(|w| w == [0x81, 0xbe, 0x10, 0, 0, 0, 3, 0, 0, 0]));
        assert!(bytes
            .windows(7)
            .any(|w| w == [0x48, 0x8b, 0x8e, 0x38, 0, 0, 0]));
        assert!(!bytes.windows(4).any(|w| w == [0x48, 0x8b, 0x8c, 0xd6]));
        Ok(())
    }

    #[test]
    fn tail_call_constant_index_with_known_bounds_omits_bounds_check() -> Result<()> {
        let helper_addrs = HashMap::from([
            (X86_BPF_MAP_MAX_ENTRIES_OFFSET_KEY.to_string(), 0x10),
            (X86_BPF_ARRAY_PTRS_OFFSET_KEY.to_string(), 0x20),
            (X86_BPF_PROG_BPF_FUNC_OFFSET_KEY.to_string(), 0x30),
            (X86_TAIL_CALL_OFFSET_KEY.to_string(), 0x0c),
        ]);
        let insns =
            build_x86_tail_call_inline(&helper_addrs, 0, &[], None, true, Some(3), Some(8))?;
        let local_ips: Vec<u64> = (0..insns.len() as u64).collect();
        let encoded = encode_x86_local_block("tail_call_known_bounds", 4096, &insns, &local_ips)?;
        let bytes = encoded.code_buffer;

        assert!(!bytes
            .windows(10)
            .any(|w| w == [0x81, 0xbe, 0x10, 0, 0, 0, 3, 0, 0, 0]));
        assert!(bytes
            .windows(7)
            .any(|w| w == [0x48, 0x8b, 0x8e, 0x38, 0, 0, 0]));
        Ok(())
    }

    #[test]
    fn tail_call_constant_index_known_out_of_bounds_is_noop() -> Result<()> {
        let helper_addrs = HashMap::from([
            (X86_BPF_MAP_MAX_ENTRIES_OFFSET_KEY.to_string(), 0x10),
            (X86_BPF_ARRAY_PTRS_OFFSET_KEY.to_string(), 0x20),
            (X86_BPF_PROG_BPF_FUNC_OFFSET_KEY.to_string(), 0x30),
            (X86_TAIL_CALL_OFFSET_KEY.to_string(), 0x0c),
        ]);
        let insns =
            build_x86_tail_call_inline(&helper_addrs, 0, &[], None, true, Some(8), Some(8))?;

        assert!(insns.is_empty());
        Ok(())
    }

    #[test]
    fn tail_call_frame_keeps_imm8_stack_adjust() -> Result<()> {
        let bytes = [
            0x55, // push rbp
            0x41, 0x54, // push r12
            0x48, 0x83, 0xec, 0x48, // sub rsp, 0x48
            0x48, 0x83, 0xc4, 0x48, // add rsp, 0x48
            0x41, 0x5c, // pop r12
            0x5d, // pop rbp
            0xc3, // ret
        ];
        let insns = decode_x86(&bytes)?;
        let frame = plan_x86_tail_call_frame(
            &bytes,
            0,
            &insns,
            &[Register::RBP, Register::R12],
            0x48,
            &HashSet::new(),
            bytes.len() as u64,
            None,
        )?;

        assert_eq!(frame.bpf_rbp_rsp_offset, Some(0x50));
        assert!(!frame.bpf_rbp_is_live);
        assert_eq!(
            frame.cleanup_bytes,
            vec![0x48, 0x83, 0xc4, 0x48, 0x41, 0x5c, 0x5d]
        );
        Ok(())
    }
}

fn disasm(bytes: &[u8]) {
    use iced_x86::Formatter;
    let mut decoder = Decoder::with_ip(64, bytes, 0, DecoderOptions::NONE);
    let mut insn = Instruction::default();
    let mut formatter = iced_x86::NasmFormatter::new();
    let mut out = String::new();
    while decoder.can_decode() {
        decoder.decode_out(&mut insn);
        out.clear();
        formatter.format(&insn, &mut out);
        eprintln!("{:04x}: {}", insn.ip(), out);
    }
}
