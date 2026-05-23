use anyhow::{anyhow, bail, Result};
use iced_x86::{
    BlockEncoder, BlockEncoderOptions, Code, Decoder, DecoderOptions, FlowControl, Instruction,
    InstructionBlock, Mnemonic, OpKind, Register,
};
use object::{Object, ObjectSection, ObjectSymbol, RelocationFlags, RelocationTarget};
use std::collections::{HashMap, HashSet};

use crate::*;

const X86_CPU_NUMBER_HELPER_KEY: &str = "__native_x86_cpu_number";
const X86_THIS_CPU_OFF_HELPER_KEY: &str = "__native_x86_this_cpu_off";
const NATIVE_LAB_RELOC_HELPER_CALL_RAX: u32 = 1;
pub(super) fn decode_x86_external_call_targets(jited: &[u8], jit_base: u64) -> Result<Vec<u64>> {
    let mut targets = Vec::new();
    let mut decoder = Decoder::with_ip(64, jited, jit_base, DecoderOptions::NONE);
    while decoder.can_decode() {
        let insn = decoder.decode();
        if !insn.is_call_near() {
            continue;
        }
        let target = insn.near_branch_target();
        if !target_is_inside_jit_image(target, jit_base, jited.len()) {
            targets.push(target);
        }
    }
    Ok(targets)
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
pub(super) fn discover_reachable(elf: &object::File, entry: &SymInfo) -> Result<Vec<SymInfo>> {
    let mut included: Vec<SymInfo> = vec![entry.clone()];
    let mut seen: std::collections::HashSet<u64> = [entry.address].into_iter().collect();
    let mut queue: Vec<SymInfo> = vec![entry.clone()];

    while let Some(sym) = queue.pop() {
        let bytes = read_symbol_bytes(elf, &sym)?;
        let mut decoder = Decoder::with_ip(64, &bytes, sym.address, DecoderOptions::NONE);
        while decoder.can_decode() {
            let insn = decoder.decode();
            if insn.is_invalid() {
                bail!("iced bailed decoding {} at IP {:#x}", sym.name, insn.ip());
            }
            if matches!(insn.flow_control(), FlowControl::Call) {
                let target = insn.near_branch_target();
                if target == 0 || seen.contains(&target) {
                    continue;
                }
                let called = find_symbol_at_address(elf, target).ok_or_else(|| {
                    anyhow!(
                        "{} calls {:#x} but no symbol covers that address",
                        sym.name,
                        target
                    )
                })?;
                if !seen.contains(&called.address) {
                    seen.insert(called.address);
                    included.push(called.clone());
                    queue.push(called);
                }
            }
        }
    }
    Ok(included)
}

#[derive(Clone)]
enum PatchKind {
    /// Rewritten RET in the entry function: disp targets end-of-blob.
    JmpEnd,
    /// CALL rel32 to a discovered symbol: disp targets that symbol's new
    /// global offset in the blob.
    Call { target_symbol_address: u64 },
    /// `movabs rax, target; call *rax` slot for a kernel helper/map target.
    /// The module can rewrite it to `call rel32; nop...` after the blob lands
    /// in executable memory, but keeps the absolute call when rel32 is out of
    /// range.
    HelperCallRax { target_addr: u64 },
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

/// Pre-scan ELF .rela.text relocations to find the *byte offset* of each
/// helper call site inside each included symbol. Keyed by
/// `(symbol_address, local_call_opcode_offset)` so the decode loop can
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
) -> Result<HashMap<(u64, u64), String>> {
    let mut out: HashMap<(u64, u64), String> = HashMap::new();
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
            let target_name: String = match reloc.target() {
                RelocationTarget::Symbol(idx) => elf
                    .symbol_by_index(idx)?
                    .name()
                    .map_err(|e| anyhow!("reloc target symbol name: {e}"))?
                    .to_string(),
                _ => continue,
            };
            let r_type = match reloc.flags() {
                RelocationFlags::Elf { r_type } => r_type,
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
            let key = (sym.address, loc - sym.address);
            out.entry(key).or_insert(target_name);
        }
    }
    Ok(out)
}

fn scan_x86_got_relocations(
    elf: &object::File,
    included: &[SymInfo],
) -> Result<HashMap<(u64, u64), String>> {
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
            out.insert((sym.address, reloc_offset - sym.address), target_name);
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
    lookup_sites: &[LookupSiteSpec],
    update_sites: &[UpdateSiteSpec],
    oracle_targets: &[u64],
    proof_mode: bool,
    show: bool,
) -> Result<RewriteResult> {
    let included_ranges: Vec<(u64, u64)> = included
        .iter()
        .map(|s| (s.address, s.address + s.size))
        .collect();

    let helper_call_sites = scan_helper_calls(elf, included)?;
    let got_relocations = scan_x86_got_relocations(elf, included)?;
    let proof_input = elf.section_by_name(".native_link_abi").is_some();

    let mut sym_global_offset: HashMap<u64, usize> = HashMap::new();
    let mut blob: Vec<u8> = Vec::new();
    let mut patches: Vec<PatchInfo> = Vec::new();
    let mut layouts: Vec<SymbolLayout> = Vec::new();
    let mut callee_saved_mask: u8 = 0;
    // For each `bpf_map_lookup_elem` call site encountered in
    // entry-symbol byte order, record (symbol_addr, local_call_offset)
    // -> spec_index. Filled during the decode loop; consumed by
    // apply_elf_relocations to route each call to its own dedicated
    // literal-pool entry holding the per-site target address.
    let mut lookup_call_ordinal: HashMap<(u64, u64), usize> = HashMap::new();
    let mut lookup_call_counter: usize = 0;
    let mut update_call_counter: usize = 0;
    let mut next_oracle_target: usize = 0;
    let mut resolved_helper_call_sites: HashSet<(u64, u64)> = HashSet::new();
    let mut resolved_got_relocations: HashSet<(u64, u64)> = HashSet::new();

    for sym in included {
        let is_entry = sym.address == entry.address;
        let bytes = read_symbol_bytes(elf, sym)?;
        let entry_abi_strip = if is_entry {
            plan_x86_entry_abi_strip(&bytes, sym.address)?
        } else {
            X86EntryAbiStrip::default()
        };
        if is_entry {
            callee_saved_mask = entry_abi_strip.callee_saved_mask;
        }
        // Decode at the symbol's original vaddr so insn.near_branch_target()
        // is meaningful in the ELF address space and we can identify
        // inter-symbol call targets. Below we re-anchor each instruction
        // to a per-symbol IP=0 layout before encoding.
        let mut decoder = Decoder::with_ip(64, &bytes, sym.address, DecoderOptions::NONE);
        let mut helper_got_registers: HashMap<Register, String> = HashMap::new();

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

            if is_entry && entry_abi_strip.drop_local_ips.contains(&local_ip) {
                continue;
            }
            if is_entry {
                remap_x86_entry_registers(&mut insn, &entry_abi_strip.register_renames)?;
            }

            if !proof_mode
                && insn.mnemonic() == Mnemonic::Mov
                && insn.op_count() >= 2
                && insn.op0_kind() == OpKind::Register
                && insn.op1_kind() == OpKind::Memory
                && insn.is_ip_rel_memory_operand()
            {
                let insn_len = u64::try_from(insn.len())
                    .map_err(|_| anyhow!("x86 instruction length overflow"))?;
                if insn_len >= 4 {
                    let local_patch_off = local_ip + insn_len - 4;
                    if let Some(target_name) = got_relocations.get(&(sym.address, local_patch_off))
                    {
                        let dst = insn.op0_register();
                        if matches!(
                            target_name.as_str(),
                            "bpf_map_lookup_elem" | "bpf_map_update_elem"
                        ) {
                            let dst_family = x86_gpr64_family(dst).ok_or_else(|| {
                                anyhow!(
                                    "x86 helper GOT load for {} uses unsupported register {:?}",
                                    target_name,
                                    dst
                                )
                            })?;
                            helper_got_registers.insert(dst_family, target_name.clone());
                            resolved_got_relocations.insert((sym.address, local_patch_off));
                            continue;
                        }
                        if let Some(&helper_addr) = helper_addrs.get(target_name) {
                            let movabs = build_x86_mov_reg_imm64(dst, helper_addr)?;
                            push_x86_replacement(
                                &mut local,
                                &mut kinds,
                                &mut insn_local_ip,
                                local_ip,
                                movabs,
                                None,
                            );
                            resolved_got_relocations.insert((sym.address, local_patch_off));
                            continue;
                        }
                        if map_addrs.contains_key(target_name) {
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
                            resolved_got_relocations.insert((sym.address, local_patch_off));
                            continue;
                        }
                    }
                }
            }

            if !proof_mode {
                validate_no_external_refs(&insn, &included_ranges)?;
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

            const JMP_END_PLACEHOLDER_TARGET: u64 = 0x4000_0000;
            if !proof_mode
                && proof_input
                && is_entry
                && insn.mnemonic() == Mnemonic::Jmp
                && original_target == sym.address + sym.size
            {
                let mut jmp = Instruction::default();
                jmp.set_code(Code::Jmp_rel32_64);
                jmp.set_op0_kind(OpKind::NearBranch64);
                jmp.set_near_branch64(JMP_END_PLACEHOLDER_TARGET);
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
                jmp.set_near_branch64(JMP_END_PLACEHOLDER_TARGET);
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
            // We must NOT treat those as cross-symbol calls; the ELF reloc
            // pass below picks them up instead.
            if matches!(insn.flow_control(), FlowControl::Call) && original_target != 0 {
                let target_is_symbol_entry = included.iter().any(|s| s.address == original_target);
                if target_is_symbol_entry {
                    let next = local_ip.wrapping_add(5);
                    insn.set_near_branch64(next);
                    local.push(insn);
                    kinds.push(Some(PatchKind::Call {
                        target_symbol_address: original_target,
                    }));
                    insn_local_ip.push(local_ip);
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
                let helper_call_name = helper_call_sites
                    .get(&(sym.address, local_ip))
                    .cloned()
                    .or_else(|| {
                        x86_indirect_call_register(&insn)
                            .and_then(|reg| helper_got_registers.get(&reg).cloned())
                    });
                if let Some(name) = helper_call_name {
                    if proof_mode {
                        local.push(insn);
                        kinds.push(None);
                        insn_local_ip.push(local_ip);
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
                            resolved_helper_call_sites.insert((sym.address, local_ip));
                            continue;
                        }
                    }

                    if name == "bpf_map_lookup_elem" && is_entry {
                        let ordinal = lookup_call_counter;
                        let spec = lookup_sites.get(ordinal).ok_or_else(|| {
                            anyhow!(
                                "x86 bpf_map_lookup_elem call site {ordinal} in {} is missing --lookup-site metadata",
                                sym.name
                            )
                        })?;
                        lookup_call_counter += 1;
                        lookup_call_ordinal.insert((sym.address, local_ip), ordinal);
                        match spec.kind {
                            LookupKind::Array | LookupKind::PerCpuArray => {
                                for ib in build_x86_array_lookup(spec)? {
                                    push_x86_synthetic(
                                        &mut local,
                                        &mut kinds,
                                        &mut insn_local_ip,
                                        &mut next_synthetic_ip,
                                        ib,
                                    )?;
                                }
                                resolved_helper_call_sites.insert((sym.address, local_ip));
                                continue;
                            }
                            LookupKind::Call
                            | LookupKind::Hash
                            | LookupKind::LruHash
                            | LookupKind::PerCpuHash => {
                                let helper_addr = resolve_site_target(
                                    spec.target_addr,
                                    oracle_targets,
                                    &mut next_oracle_target,
                                    &format!("x86 lookup-site {ordinal} ({:?})", spec.kind),
                                )?;
                                push_x86_helper_call_reloc(
                                    &mut local,
                                    &mut kinds,
                                    &mut insn_local_ip,
                                    local_ip,
                                    helper_addr,
                                )?;
                                if matches!(spec.kind, LookupKind::Hash) {
                                    for ib in build_x86_hash_lookup_postcall(spec)? {
                                        push_x86_synthetic(
                                            &mut local,
                                            &mut kinds,
                                            &mut insn_local_ip,
                                            &mut next_synthetic_ip,
                                            ib,
                                        )?;
                                    }
                                }
                                if matches!(spec.kind, LookupKind::LruHash) {
                                    for ib in build_x86_lru_hash_lookup_postcall(spec)? {
                                        push_x86_synthetic(
                                            &mut local,
                                            &mut kinds,
                                            &mut insn_local_ip,
                                            &mut next_synthetic_ip,
                                            ib,
                                        )?;
                                    }
                                }
                                if matches!(spec.kind, LookupKind::PerCpuHash) {
                                    for ib in build_x86_percpu_hash_lookup_postcall(spec)? {
                                        push_x86_synthetic(
                                            &mut local,
                                            &mut kinds,
                                            &mut insn_local_ip,
                                            &mut next_synthetic_ip,
                                            ib,
                                        )?;
                                    }
                                }
                                resolved_helper_call_sites.insert((sym.address, local_ip));
                                continue;
                            }
                        }
                    }

                    if name == "bpf_map_update_elem" && is_entry {
                        let ordinal = update_call_counter;
                        update_call_counter += 1;
                        if let Some(spec) = update_sites.get(ordinal) {
                            match spec.kind {
                                UpdateKind::Array | UpdateKind::PerCpuArray => {
                                    let _ = consume_oracle_target(
                                        oracle_targets,
                                        &mut next_oracle_target,
                                        &format!(
                                            "x86 update-site {ordinal} ({:?}) late inline",
                                            spec.kind
                                        ),
                                    )?;
                                    for ib in build_x86_array_update(spec)? {
                                        push_x86_synthetic(
                                            &mut local,
                                            &mut kinds,
                                            &mut insn_local_ip,
                                            &mut next_synthetic_ip,
                                            ib,
                                        )?;
                                    }
                                    resolved_helper_call_sites.insert((sym.address, local_ip));
                                    continue;
                                }
                                UpdateKind::Call => {
                                    let helper_addr = resolve_site_target(
                                        spec.target_addr,
                                        oracle_targets,
                                        &mut next_oracle_target,
                                        &format!("x86 update-site {ordinal}"),
                                    )?;
                                    push_x86_helper_call_reloc(
                                        &mut local,
                                        &mut kinds,
                                        &mut insn_local_ip,
                                        local_ip,
                                        helper_addr,
                                    )?;
                                    resolved_helper_call_sites.insert((sym.address, local_ip));
                                    continue;
                                }
                            }
                        }
                    }

                    let helper_addr = resolve_helper_target(
                        &name,
                        helper_addrs,
                        oracle_targets,
                        &mut next_oracle_target,
                        &format!("x86 helper call {name}"),
                    )?;
                    push_x86_helper_call_reloc(
                        &mut local,
                        &mut kinds,
                        &mut insn_local_ip,
                        local_ip,
                        helper_addr,
                    )?;
                    resolved_helper_call_sites.insert((sym.address, local_ip));
                    continue;
                }
            }

            // Helper PLT32/GOT placeholders should have been resolved in
            // the helper-call block above. Keep non-helper instructions as
            // decoded; the ELF relocation pass below handles map literals
            // and local data references.
            if let Some(reg) = x86_written_gpr_family(&insn) {
                helper_got_registers.remove(&reg);
            }
            local.push(insn);
            kinds.push(None);
            insn_local_ip.push(local_ip);

            // After pushing the call, decide per-call-site whether to
            // emit the inline (test+je+add) HASH-lookup sequence. We
            // index `lookup_sites` by the BPF-source ordinal of this
            // `bpf_map_lookup_elem` call (passed in by the runner; see
            // `--lookup-site` docs). Clang preserves call order between
            // BPF and native compilation paths, so the i-th
            // `bpf_map_lookup_elem` call in the native code corresponds
            // to the i-th `BPF_CALL bpf_map_lookup_elem` in the BPF
            // bytecode.
            if is_entry {
                if let Some(name) = helper_call_sites.get(&(sym.address, local_ip)) {
                    if name == "bpf_map_lookup_elem" {
                        let ordinal = lookup_call_counter;
                        let spec = lookup_sites.get(ordinal).ok_or_else(|| {
                            anyhow!(
                                "x86 bpf_map_lookup_elem call site {ordinal} in {} is missing --lookup-site metadata",
                                sym.name
                            )
                        })?;
                        lookup_call_counter += 1;
                        lookup_call_ordinal.insert((sym.address, local_ip), ordinal);
                        if matches!(spec.kind, LookupKind::Hash) {
                            for ib in build_x86_hash_lookup_postcall(spec)? {
                                push_x86_synthetic(
                                    &mut local,
                                    &mut kinds,
                                    &mut insn_local_ip,
                                    &mut next_synthetic_ip,
                                    ib,
                                )?;
                            }
                        }
                        if matches!(spec.kind, LookupKind::LruHash) {
                            for ib in build_x86_lru_hash_lookup_postcall(spec)? {
                                push_x86_synthetic(
                                    &mut local,
                                    &mut kinds,
                                    &mut insn_local_ip,
                                    &mut next_synthetic_ip,
                                    ib,
                                )?;
                            }
                        }
                        if matches!(spec.kind, LookupKind::PerCpuHash) {
                            for ib in build_x86_percpu_hash_lookup_postcall(spec)? {
                                push_x86_synthetic(
                                    &mut local,
                                    &mut kinds,
                                    &mut insn_local_ip,
                                    &mut next_synthetic_ip,
                                    ib,
                                )?;
                            }
                        }
                    }
                }
            }
        }

        // Encode this symbol's local stream at IP=0.
        let block = InstructionBlock::new(&local, 0);
        // We intentionally do NOT set DONT_FIX_BRANCHES: the inline-hash
        // declared-byte insertion can push subsequent intra-symbol
        // branches out of i8 range, and we want iced to legally grow
        // `Jcc_short` -> `Jcc_near` (rel8 -> rel32) when that happens.
        // Already-long forms (Jmp_rel32_64 used by our JmpEnd
        // placeholder, indirect calls/movs) are not affected by the
        // grow path -- iced only upgrades short branches, never
        // shrinks long ones. The byte offsets we patch later come from
        // `new_instruction_offsets`, which reflects the post-relayout
        // positions, so JmpEnd / cross-sym Call / GOTPCREL patches
        // stay correct.
        let encoded = BlockEncoder::encode(
            64,
            block,
            BlockEncoderOptions::RETURN_NEW_INSTRUCTION_OFFSETS,
        )
        .map_err(|e| anyhow!("iced BlockEncoder failed for {}: {e:?}", sym.name))?;

        let sym_base = blob.len();
        sym_global_offset.insert(sym.address, sym_base);
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

    if !proof_mode && next_oracle_target != oracle_targets.len() {
        bail!(
            "companion JIT oracle has {} unused x86 helper target(s)",
            oracle_targets.len() - next_oracle_target
        );
    }

    // Apply intra-blob Call patches first (cross-symbol direct calls);
    // those need only `sym_global_offset` which is already known.
    for p in &patches {
        if let PatchKind::Call {
            target_symbol_address,
        } = &p.kind
        {
            let off = p.global_offset;
            if off + 5 > blob.len() || blob[off] != 0xE8 {
                bail!("CALL at off {off:#x} did not encode as Call_rel32_64");
            }
            let target_global = *sym_global_offset
                .get(target_symbol_address)
                .ok_or_else(|| anyhow!("call target sym addr not in index map"))?;
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
            PatchKind::HelperCallRax { target_addr } => {
                let offset = u32::try_from(p.global_offset)
                    .map_err(|_| anyhow!("helper call reloc offset exceeds u32"))?;
                if p.global_offset + 12 > blob.len()
                    || blob[p.global_offset] != 0x48
                    || blob[p.global_offset + 1] != 0xB8
                    || blob[p.global_offset + 10] != 0xFF
                    || blob[p.global_offset + 11] != 0xD0
                {
                    bail!(
                        "helper call slot at off {:#x} did not encode as movabs rax; call rax",
                        p.global_offset
                    );
                }
                relocs.push(RelocRecord {
                    offset,
                    kind: NATIVE_LAB_RELOC_HELPER_CALL_RAX,
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
            lookup_sites,
            &lookup_call_ordinal,
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
                    relocs.push(ProofReloc {
                        offset: (opcode_off + 1) as u64,
                        r_type,
                        symbol: target_name,
                        addend: reloc.addend(),
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
                    let sym_off_in_sec =
                        target_sym.address().checked_sub(sec_base).ok_or_else(|| {
                            anyhow!("PC32 proof target {} below section base", target_name)
                        })?;
                    let sym_size = target_sym.size();
                    if sym_size == 0 {
                        bail!("PC32 proof target {} has zero size", target_name);
                    }
                    let end = sym_off_in_sec
                        .checked_add(sym_size)
                        .ok_or_else(|| anyhow!("PC32 proof target size overflow"))?;
                    let sym_bytes = target_data
                        .get(sym_off_in_sec as usize..end as usize)
                        .ok_or_else(|| {
                            anyhow!("PC32 proof target {} out of section bounds", target_name)
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
                        symbol: target_name,
                        addend: reloc.addend(),
                        data: Some(sym_bytes.to_vec()),
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
/// Helper calls keep a range-independent in-blob target: GOTPCREL calls point
/// at literal-pool entries containing helper addresses, and PLT32 calls route
/// through tail trampolines.
fn apply_elf_relocations(
    elf: &object::File,
    layouts: &[SymbolLayout],
    helper_addrs: &HashMap<String, u64>,
    map_addrs: &HashMap<String, u64>,
    lookup_sites: &[LookupSiteSpec],
    lookup_call_ordinal: &HashMap<(u64, u64), usize>,
    resolved_helper_call_sites: &HashSet<(u64, u64)>,
    resolved_got_relocations: &HashSet<(u64, u64)>,
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

    // Cache: map symbol name -> literal-pool entry byte offset in blob.
    let mut map_pool_entry: HashMap<String, usize> = HashMap::new();
    // Cache: helper symbol name -> tail trampoline byte offset in blob.
    let mut helper_trampoline: HashMap<String, usize> = HashMap::new();
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
                    let helper_addr = *helper_addrs.get(&target_name).ok_or_else(|| {
                        anyhow!(
                            "PLT32 reloc against unknown helper {}: \
                             pass --helper {}=0x... on the command line",
                            target_name,
                            target_name
                        )
                    })?;
                    let opcode_local_off = local_patch_off
                        .checked_sub(1)
                        .ok_or_else(|| anyhow!("PLT32 reloc at offset 0?"))?;
                    if resolved_helper_call_sites.contains(&(layout.sym.address, opcode_local_off))
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
                    let tramp_off = if let Some(&off) = helper_trampoline.get(&target_name) {
                        off
                    } else {
                        let off = blob.len();
                        blob.extend_from_slice(&[0xFF, 0x25, 0x00, 0x00, 0x00, 0x00]);
                        blob.extend_from_slice(&helper_addr.to_le_bytes());
                        helper_trampoline.insert(target_name.clone(), off);
                        off
                    };
                    let rip_after_call = (new_opcode_off + 5) as i64;
                    let disp = tramp_off as i64 - rip_after_call;
                    let d =
                        i32::try_from(disp).map_err(|_| anyhow!("call disp {disp} exceeds i32"))?;
                    blob[new_opcode_off + 1..new_opcode_off + 5].copy_from_slice(&d.to_le_bytes());
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
                    if resolved_got_relocations.contains(&(layout.sym.address, local_patch_off)) {
                        continue;
                    }
                    let got_call_local_off = local_patch_off.wrapping_sub(2);
                    if resolved_helper_call_sites
                        .contains(&(layout.sym.address, got_call_local_off))
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
                        let ord = *lookup_call_ordinal
                            .get(&(layout.sym.address, got_call_local_off))
                            .ok_or_else(|| {
                                anyhow!(
                                    "x86 bpf_map_lookup_elem GOT relocation in {} at {:#x} has no lookup-site ordinal",
                                    layout.sym.name,
                                    got_call_local_off
                                )
                            })?;
                        let spec = lookup_sites.get(ord).ok_or_else(|| {
                            anyhow!(
                                "x86 bpf_map_lookup_elem GOT relocation in {} references missing lookup-site {ord}",
                                layout.sym.name
                            )
                        })?;
                        if spec.target_addr == 0 {
                            bail!(
                                "x86 lookup-site {ord} is {:?} but has no GOT-call target address",
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
                                    "GOT-relative reloc against unknown symbol {}: \
                                 pass --helper {}=0x... or --map {}=0x... on the command line",
                                    target_name,
                                    target_name,
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
                    let sym_off_in_sec = target_sym
                        .address()
                        .checked_sub(sec_base)
                        .ok_or_else(|| anyhow!("PC32 target {} below section base", target_name))?;
                    let sym_size = target_sym.size();
                    if sym_size == 0 {
                        bail!("PC32 target {} has zero size; cannot embed", target_name);
                    }
                    let end = sym_off_in_sec
                        .checked_add(sym_size)
                        .ok_or_else(|| anyhow!("PC32 target size overflow"))?;
                    let sym_bytes = target_data
                        .get(sym_off_in_sec as usize..end as usize)
                        .ok_or_else(|| {
                            anyhow!("PC32 target {} bytes out of section bounds", target_name)
                        })?
                        .to_vec();

                    let embed_off = if let Some(&off) = local_data_embed.get(&target_name) {
                        off
                    } else {
                        let off = blob.len();
                        blob.extend_from_slice(&sym_bytes);
                        local_data_embed.insert(target_name.clone(), off);
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
}

fn plan_x86_entry_abi_strip(bytes: &[u8], base_ip: u64) -> Result<X86EntryAbiStrip> {
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
        return Ok(X86EntryAbiStrip::default());
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
        return Ok(X86EntryAbiStrip::default());
    }

    let mut drop_local_ips: HashSet<u64> = HashSet::new();
    let mut branch_target_remaps: HashMap<u64, u64> = HashMap::new();
    for (reg, local_ip) in prologue_regs.iter().zip(prologue_local_ips.iter()) {
        if strip_set.contains(reg) {
            drop_local_ips.insert(*local_ip);
        }
    }

    for (idx, insn) in insns.iter().enumerate() {
        if !is_return(insn) {
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
            return Ok(X86EntryAbiStrip::default());
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
    Ok(X86EntryAbiStrip {
        drop_local_ips,
        callee_saved_mask,
        register_renames,
        branch_target_remaps,
    })
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
fn validate_no_external_refs(insn: &Instruction, included_ranges: &[(u64, u64)]) -> Result<()> {
    let in_any = |a: u64| included_ranges.iter().any(|&(lo, hi)| a >= lo && a < hi);
    let in_any_or_end = |a: u64| included_ranges.iter().any(|&(lo, hi)| a >= lo && a <= hi);

    let fc = insn.flow_control();
    if matches!(
        fc,
        FlowControl::UnconditionalBranch | FlowControl::ConditionalBranch | FlowControl::Call
    ) {
        let target = insn.near_branch_target();
        if target != 0 && !in_any_or_end(target) {
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
            if !in_any(t) {
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

fn build_x86_helper_call_rax_slot(helper_addr: u64) -> Result<Instruction> {
    let mut bytes = Vec::with_capacity(12);
    bytes.extend_from_slice(&[0x48, 0xB8]);
    bytes.extend_from_slice(&helper_addr.to_le_bytes());
    bytes.extend_from_slice(&[0xFF, 0xD0]);
    declared_bytes(&bytes)
}

fn push_x86_helper_call_reloc(
    local: &mut Vec<Instruction>,
    kinds: &mut Vec<Option<PatchKind>>,
    insn_local_ip: &mut Vec<u64>,
    local_ip: u64,
    helper_addr: u64,
) -> Result<()> {
    let insn = build_x86_helper_call_rax_slot(helper_addr)?;
    push_x86_replacement(
        local,
        kinds,
        insn_local_ip,
        local_ip,
        insn,
        Some(PatchKind::HelperCallRax {
            target_addr: helper_addr,
        }),
    );
    Ok(())
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

fn build_x86_mov_reg_imm64(reg: Register, imm: u64) -> Result<Instruction> {
    let mut bytes = Vec::new();
    append_x86_mov_reg_imm64(&mut bytes, reg, imm)?;
    declared_bytes(&bytes)
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

/// Build the inline byte sequence that the x86 BPF JIT emits after an
/// inlined `__htab_map_lookup_elem` call. Regular HASH adjusts the
/// returned `struct htab_elem *` to the value.
fn build_x86_hash_lookup_postcall(spec: &LookupSiteSpec) -> Result<Vec<Instruction>> {
    if !matches!(spec.kind, LookupKind::Hash) {
        bail!(
            "lookup kind {:?} is not a hash-style post-call inline",
            spec.kind
        );
    }
    if spec.key_offset == 0 {
        bail!("hash lookup inline missing htab value offset");
    }

    let mut body = Vec::new();
    append_x86_add_rax_imm(&mut body, spec.key_offset);

    let body_len = u8::try_from(body.len())
        .map_err(|_| anyhow!("hash lookup inline body too large: {} bytes", body.len()))?;
    let mut bytes = Vec::new();
    bytes.extend_from_slice(&[0x48, 0x85, 0xC0]); // test rax, rax
    bytes.extend_from_slice(&[0x74, body_len]); // je over non-null body
    bytes.extend_from_slice(&body);
    declared_byte_chunks(&bytes)
}

fn build_x86_lru_hash_lookup_postcall(spec: &LookupSiteSpec) -> Result<Vec<Instruction>> {
    if !matches!(spec.kind, LookupKind::LruHash) {
        bail!(
            "lookup kind {:?} is not an lru-hash-style post-call inline",
            spec.kind
        );
    }
    if spec.key_offset == 0 {
        bail!("lru hash lookup inline missing htab value offset");
    }
    if spec.value_offset == 0 {
        bail!("lru hash lookup inline missing lru ref offset");
    }

    let mut body = Vec::new();
    if spec.value_offset <= 0x7f {
        body.extend_from_slice(&[0x80, 0x78, spec.value_offset as u8, 0x00]);
    } else {
        body.extend_from_slice(&[0x80, 0xB8]);
        body.extend_from_slice(&spec.value_offset.to_le_bytes());
        body.push(0x00);
    }
    let skip_set_jcc = body.len();
    body.extend_from_slice(&[0x75, 0x00]); // jne over the ref store
    let set_start = body.len();
    if spec.value_offset <= 0x7f {
        body.extend_from_slice(&[0xC6, 0x40, spec.value_offset as u8, 0x01]);
    } else {
        body.extend_from_slice(&[0xC6, 0x80]);
        body.extend_from_slice(&spec.value_offset.to_le_bytes());
        body.push(0x01);
    }
    let set_end = body.len();
    let skip_set_rel =
        u8::try_from(set_end - set_start).map_err(|_| anyhow!("lru hash ref store too large"))?;
    body[skip_set_jcc + 1] = skip_set_rel;
    append_x86_add_rax_imm(&mut body, spec.key_offset);

    let body_len = u8::try_from(body.len()).map_err(|_| {
        anyhow!(
            "lru hash lookup inline body too large: {} bytes",
            body.len()
        )
    })?;
    let mut bytes = Vec::new();
    bytes.extend_from_slice(&[0x48, 0x85, 0xC0]); // test rax, rax
    bytes.extend_from_slice(&[0x74, body_len]); // je over non-null body
    bytes.extend_from_slice(&body);
    declared_byte_chunks(&bytes)
}

fn build_x86_percpu_hash_lookup_postcall(spec: &LookupSiteSpec) -> Result<Vec<Instruction>> {
    if !matches!(spec.kind, LookupKind::PerCpuHash) {
        bail!(
            "lookup kind {:?} is not a percpu-hash-style post-call inline",
            spec.kind
        );
    }
    if spec.key_offset == 0 {
        bail!("percpu hash lookup inline missing htab value offset");
    }
    if spec.percpu_base_addr == 0 {
        bail!("percpu hash lookup inline missing this_cpu_off address");
    }

    let mut body = Vec::new();
    append_x86_add_rax_imm(&mut body, spec.key_offset);
    body.extend_from_slice(&[0x48, 0x8B, 0x00]); // mov rax, [rax]
    body.extend_from_slice(&[0x65, 0x48, 0x03, 0x04, 0x25]); // add rax, gs:[disp32]
    body.extend_from_slice(&(spec.percpu_base_addr as u32).to_le_bytes());

    let body_len = u8::try_from(body.len())
        .map_err(|_| anyhow!("percpu hash lookup inline body too large: {}", body.len()))?;
    let mut bytes = Vec::new();
    bytes.extend_from_slice(&[0x48, 0x85, 0xC0]); // test rax, rax
    bytes.extend_from_slice(&[0x74, body_len]); // je over non-null body
    bytes.extend_from_slice(&body);
    declared_byte_chunks(&bytes)
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
