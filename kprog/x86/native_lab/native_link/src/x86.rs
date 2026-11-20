use anyhow::{anyhow, bail, Result};
use iced_x86::{
    BlockEncoder, BlockEncoderOptions, BlockEncoderResult, Code, Decoder, DecoderOptions,
    FlowControl, Instruction, InstructionBlock, InstructionInfoFactory, MemoryOperand, Mnemonic, OpAccess, OpKind,
    Register,
};
use object::{Object, ObjectSection, ObjectSymbol, RelocationFlags, RelocationTarget};
use std::collections::{BTreeMap, HashMap, HashSet};

use crate::*;

const MONO_FAST_HELPER_KEY: &str = "__native_x86_ktime_get_mono_fast_ns";
const CURRENT_TASK_KEY: &str = "__native_x86_current_task";
const CPU_NUMBER_KEY: &str = "__native_x86_cpu_number";
const JIFFIES_64_KEY: &str = "__native_x86_jiffies_64";

/// Helpers the kernel's verifier inlines for the JIT (do_misc_fixups) are one load of a per-CPU
/// variable or a kernel global; the same load, bound to the boot kernel's address, replaces the call.
fn x86_inline_load_helper(name: &str, helpers: &HashMap<String, u64>) -> Result<Option<Instruction>> {
    let (key, code, dst, segment) = match name {
        "bpf_get_current_task" | "bpf_get_current_task_btf" =>
            (CURRENT_TASK_KEY, Code::Mov_r64_rm64, Register::RAX, Register::GS),
        "bpf_get_smp_processor_id" => (CPU_NUMBER_KEY, Code::Mov_r32_rm32, Register::EAX, Register::GS),
        "bpf_jiffies64" => (JIFFIES_64_KEY, Code::Mov_r64_rm64, Register::RAX, Register::None),
        _ => return Ok(None),
    };
    let Some(&address) = helpers.get(key).filter(|address| **address != 0) else { return Ok(None) };
    let displacement = address as i64;
    if i32::try_from(displacement).is_err() {
        bail!("{name}: kernel address {address:#x} is outside the sign-extended 32-bit range");
    }
    // 64-bit addressing with a sign-extended disp32 (displ_size 4 would add a 0x67 prefix).
    let memory = MemoryOperand::new(Register::None, Register::None, 1, displacement, 8, false, segment);
    Ok(Some(Instruction::with2(code, dst, memory)?))
}

fn show_lto_range(show: bool, piece: &str, range: (usize, usize)) {
    if show {
        eprintln!("native-link-lto-range {}", serde_json::json!({
            "piece": piece, "start": range.0, "end": range.1,
            "bytes": range.1 - range.0,
        }));
    }
}

fn runtime_call_target(name: &str, helpers: &HashMap<String, u64>, context: &str) -> Result<u64> {
    if name == "bpf_ktime_get_ns" {
        // The one kernel's helper body returns this same NMI-safe monotonic
        // implementation. Change call linkage only, never observable IDs or
        // materialized helper addresses used by the original native program.
        require_call_target(resolve_helper_target(name, helpers, context)?, context)?;
        let target = resolve_helper_target(MONO_FAST_HELPER_KEY, helpers, context)?;
        return require_call_target(target, "x86 monotonic fast clock");
    }
    resolve_helper_target(name, helpers, context)
}

fn map_op_target(ops: &[MapOps], map: Option<&String>, helper: &str) -> Option<u64> {
    let ops = ops.iter().find(|ops| Some(&ops.name) == map)?;
    let target = match helper {
        "bpf_map_update_elem" => ops.update,
        "bpf_map_delete_elem" => ops.remove,
        _ => 0,
    };
    (target != 0).then_some(target)
}

#[path = "x86_writable_data.rs"]
mod writable_data;

#[path = "x86_memory.rs"]
mod memory;

#[path = "x86_known_maps.rs"]
mod known_maps;

#[path = "x86_non_pic.rs"]
mod non_pic;

#[path = "x86_readonly_relocs.rs"]
mod readonly_relocs;
#[path = "x86_helper_provenance.rs"]
mod helper_provenance;
#[path = "x86_code_provenance.rs"]
mod code_provenance;

#[path = "x86_effects.rs"]
mod effects;

pub(super) fn proof_effects(bytes: &[u8]) -> Result<serde_json::Value> {
    effects::describe(bytes)
}

const X86_BPF_MAP_MAX_ENTRIES_OFFSET_KEY: &str = "__native_x86_bpf_map_max_entries_offset";
const X86_BPF_ARRAY_PTRS_OFFSET_KEY: &str = "__native_x86_bpf_array_ptrs_offset";
const X86_BPF_PROG_BPF_FUNC_OFFSET_KEY: &str = "__native_x86_bpf_prog_bpf_func_offset";
const X86_TAIL_CALL_OFFSET_KEY: &str = "__native_x86_tail_call_offset";
const X86_JMP_END_PLACEHOLDER_TARGET: u64 = 0x4000_0000;
const NATIVE_LAB_RELOC_HELPER_CALL_REL32: u32 = 1;
const NATIVE_LAB_RELOC_X86_TAIL_COUNT: u32 = 10;
const NATIVE_LAB_RELOC_IMAGE_POINTER: u32 = 12;
const X86_HELPER_CALL_REL32_SLOT: [u8; 5] = [0xE8, 0, 0, 0, 0];
type SymbolKey = (object::SectionIndex, u64);
type LocalSiteKey = (object::SectionIndex, u64, u64);

fn symbol_key(sym: &SymInfo) -> SymbolKey {
    (sym.section_index, sym.address)
}

fn local_site_key(sym: &SymInfo, local_ip: u64) -> LocalSiteKey {
    (sym.section_index, sym.address, local_ip)
}

fn generic_lookup_site(target_addr: u64) -> Option<LookupSiteSpec> {
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
    })
}

fn select_lookup_site(
    lookup_maps: &HashMap<String, LookupSiteSpec>,
    native_call_index: usize,
    native_map_name: Option<&str>,
    sym_name: &str,
    generic_target_addr: u64,
) -> Result<(String, LookupSiteSpec)> {
    // A layout belongs only to the exact map whose pointer was proven to
    // reach RDI. Native/BPF call order and truncated names are not identities.
    if let Some(name) = native_map_name {
        if let Some(spec) = lookup_maps.get(name) {
            return Ok((format!("runtime-map:{name}"), spec.clone()));
        }
    }
    // A dynamic map retains its actual pointer and generic helper semantics;
    // the shared runtime routines dispatch on the real map's type.
    let spec = generic_lookup_site(generic_target_addr)
        .ok_or_else(|| anyhow!(
            "x86 runtime map lookup {native_call_index} in {sym_name} requires the bpf_map_lookup_elem helper target"
        ))?;
    Ok((format!("runtime:{native_call_index}"), spec))
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
        if sym.section_index() != Some(section_index) {
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
        if sym.section_index() != Some(section_index) {
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
    // A PLT32 relocation names code: a function symbol, or the section symbol
    // of a code section plus the callee's offset (the assembler's form for a
    // static function in another section). A data symbol is never a code target.
    let Some(section_index) = target_sym.section_index().filter(|index| {
        target_sym.kind() == object::SymbolKind::Text
            || (target_sym.kind() == object::SymbolKind::Section
                && elf.section_by_index(*index).is_ok_and(|s| s.kind() == object::SectionKind::Text))
    }) else {
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

struct DirectTailTransfer {
    symbol: String,
    addend: i64,
    defined: Option<SymInfo>,
    relocation_offset: Option<u64>,
}

fn x86_direct_tail_transfers(
    elf: &object::File,
    sym: &SymInfo,
) -> Result<BTreeMap<u64, DirectTailTransfer>> {
    let section = elf.section_by_index(sym.section_index)?;
    let bytes = read_symbol_bytes(elf, sym)?;
    let relocations: HashMap<_, _> = section.relocations().collect();
    let mut transfers = BTreeMap::new();
    let mut decoder = Decoder::with_ip(64, &bytes, sym.address, DecoderOptions::NONE);
    while decoder.can_decode() {
        let insn = decoder.decode();
        if !(insn.flow_control() == FlowControl::UnconditionalBranch || insn.is_jcc_short_or_near())
            || !matches!(insn.op0_kind(), OpKind::NearBranch64) { continue; }
        let local_ip = insn.ip() - sym.address;
        let displacement = insn.ip() + decoder.get_constant_offsets(&insn).immediate_offset() as u64;
        // Relocation targets are authoritative for both JMP and Jcc.
        if let Some(reloc) = relocations.get(&displacement) {
            if matches!(reloc.flags(), RelocationFlags::Elf { r_type: 2 | 4 }) {
                let target_index = match reloc.target() {
                    RelocationTarget::Symbol(index) => index,
                    _ => continue,
                };
                let target = elf.symbol_by_index(target_index)?;
                let defined = resolve_x86_plt32_defined_target_addr(elf, reloc)?;
                let (symbol, addend, callee) = if let Some((section, address)) = defined {
                    if section == sym.section_index && address >= sym.address && address < sym.address + sym.size {
                        continue; // A branch to a block in the same function.
                    }
                    let callee = find_text_symbol_in_section_at_address(elf, section, address)
                        .ok_or_else(|| anyhow!("tail branch from {} has no function at {address:#x}", sym.name))?;
                    // Cold fragments reached in the middle of another symbol
                    // share a frame; they are not SysV function tail calls.
                    if address != callee.address { continue; }
                    let addend = i64::try_from(address - callee.address)? - 4;
                    (callee.name.clone(), addend, Some(callee))
                } else {
                    (target.name()?.to_owned(), reloc.addend(), None)
                };
                transfers.insert(local_ip, DirectTailTransfer {
                    symbol, addend, defined: callee, relocation_offset: Some(displacement - sym.address),
                });
                continue;
            }
        }
        let address = insn.near_branch_target();
        if address >= sym.address && address < sym.address + sym.size { continue; }
        if let Some(callee) = find_decoded_call_target(elf, sym, address) {
            if address != callee.address { continue; }
            let addend = i64::try_from(address - callee.address)? - 4;
            transfers.insert(local_ip, DirectTailTransfer {
                symbol: callee.name.clone(), addend, defined: Some(callee), relocation_offset: None,
            });
        }
    }
    Ok(transfers)
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
        for tail in x86_direct_tail_transfers(elf, &sym)?.into_values() {
            if let Some(callee) = tail.defined {
                if seen.insert(symbol_key(&callee)) {
                    included.push(callee.clone());
                    queue.push(callee);
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
    /// A direct call or function tail jump to a discovered symbol.
    DirectBranch { target_symbol_key: SymbolKey, opcode: u8 },
    /// `call rel32` placeholder for a kernel helper/map target. The module
    /// must patch the rel32 displacement after the blob lands in executable
    /// memory.
    HelperBranchRel32 { target_addr: u64, opcode: u8 },
    LocalMemory { routine: memory::Routine },
    LocalArray { bytes: Vec<u8> },
    /// Rewritten `mov reg, [rip+GOT]` against a map symbol. The runner
    /// patches the immediate field with the live kernel map pointer.
    MapImmediate { name: String, imm_offset: usize },
    /// A non-PIC map address normalized to the existing proof GOT-load ABI.
    ProofMapAddress { name: String },
    /// Canonical address of a live writable DATASEC variable in the proof.
    WritableAddress { name: String },
    /// The tail-call stub's `add rcx, imm32` that forms the callee's entry
    /// address. The module rewrites the field with `-16 - depth`, which steps
    /// over the prologue that increments `bpf_prog->stats.cnt`; without it a
    /// tail-called program reports no runs at all.
    TailCount { field_delta: u32 },
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

fn x86_decoded_load_sites(blob: &[u8], ranges: &[(usize, usize)]) -> Vec<LoadSite> {
    let mut result = Vec::new();
    let mut factory = InstructionInfoFactory::new();
    for &(start, end) in ranges {
        for insn in Decoder::with_ip(64, &blob[start..end.min(blob.len())],
                                    start as u64, DecoderOptions::NONE) {
            let info = factory.info(&insn);
            if !info.used_memory().iter().any(|m| matches!(m.access(),
                OpAccess::Read | OpAccess::CondRead | OpAccess::ReadWrite |
                OpAccess::ReadCondWrite)) { continue; }
            // An explicit written GPR is the stock fixup destination.
            // Implicit stack movement remains owned by the instruction.
            let destination = (0..insn.op_count()).find_map(|i| {
                if insn.op_kind(i) != OpKind::Register ||
                    !matches!(info.op_access(i), OpAccess::Write | OpAccess::CondWrite |
                              OpAccess::ReadWrite | OpAccess::ReadCondWrite) { return None; }
                x86_gpr64_family(insn.op_register(i))
            }).or_else(|| {
                info.used_registers().iter().find_map(|r| {
                    if !matches!(r.access(), OpAccess::Write | OpAccess::CondWrite |
                                 OpAccess::ReadWrite | OpAccess::ReadCondWrite) { return None; }
                    x86_gpr64_family(r.register()).filter(|&r| r != Register::RSP)
                })
            }).map(|r| (r as u32 - Register::RAX as u32) as u16).unwrap_or(u16::MAX);
            result.push(LoadSite { offset: insn.ip() as u32,
                insn_len: insn.len() as u16, destination });
        }
    }
    result.sort_by_key(|s| s.offset);
    result
}

pub(super) fn rewrite_x86(
    elf: &object::File,
    entry: &SymInfo,
    included: &[SymInfo],
    helper_addrs: &HashMap<String, u64>,
    map_addrs: &HashMap<String, u64>,
    lookup_maps: &HashMap<String, LookupSiteSpec>,
    map_ops: &[MapOps],
    proof_mode: bool,
    preserve_entry_abi: bool,
    show: bool,
) -> Result<RewriteResult> {
    let included_ranges: Vec<(u64, u64)> = included
        .iter()
        .map(|s| (s.address, s.address + s.size))
        .collect();

    let helper_call_sites = scan_helper_calls(elf, included)?;
    let got_relocations = scan_x86_got_relocations(elf, included)?;
    let absolute_maps = non_pic::references(elf, included, map_addrs)?;
    let pc_relative_relocations = scan_x86_pc_relative_relocations(elf, included)?;
    let writable_references = writable_data::references(elf, included)?;
    let table_indirect_sites = if proof_mode { HashSet::new() } else {
        readonly_relocs::indirect_sites(elf, included)?
    };
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

    let entry_helpers = helper_provenance::calls(elf, entry, &got_relocations, helper_addrs)?;
    let wrap_entry = !entry_helpers.tails.is_empty()
        || (!proof_input && !x86_direct_tail_transfers(elf, entry)?.is_empty());
    let entry_body_name = if wrap_entry {
        let names = elf.symbols().map(|s| s.name().map(str::to_owned))
            .collect::<std::result::Result<HashSet<_>, _>>()?;
        let mut name = format!("__native_tail_body_{}", entry.name);
        while names.contains(&name) { name.push('_'); }
        Some(name)
    } else { None };
    let mut sym_global_offset: HashMap<SymbolKey, usize> = HashMap::new();
    let mut blob: Vec<u8> = Vec::new();
    let mut patches: Vec<PatchInfo> = Vec::new();
    let mut layouts: Vec<SymbolLayout> = Vec::new();
    let mut code_ranges = Vec::new();
    let mut callee_saved_mask: u8 = proof_callee_saved_mask.unwrap_or(0);
    if wrap_entry {
        // The BPF entry ABI has one context argument. Call its unchanged
        // SysV body once, with normal alignment, then exit the inline image.
        // Subprogram tail jumps keep their original stack arguments and RETs.
        blob.extend_from_slice(&[0x48,0x83,0xec,8, 0xe8,9,0,0,0,
            0x48,0x83,0xc4,8, 0xe9,0,0,0,0]);
        patches.push(PatchInfo { global_offset: 13, kind: PatchKind::JmpEnd });
        code_ranges.push((0, 18));
    }
    let mut lookup_call_counter: usize = 0;
    let map_lookup_helper_addr = helper_addrs
        .get("bpf_map_lookup_elem")
        .copied()
        .unwrap_or(0);
    let mut resolved_helper_call_sites: HashSet<LocalSiteKey> = HashSet::new();
    let mut resolved_got_relocations: HashSet<LocalSiteKey> = HashSet::new();
    let mut canonicalized_relocations: HashSet<LocalSiteKey> = HashSet::new();
    let mut tail_proof_relocs = Vec::new();

    for sym in included {
        let is_entry = symbol_key(sym) == symbol_key(entry) && !wrap_entry;
        let bytes = read_symbol_bytes(elf, sym)?;
        let mut tail_transfers = x86_direct_tail_transfers(elf, sym)?;
        let mut tail_calls = Vec::new();
        let helper_calls = if symbol_key(sym) == symbol_key(entry) { entry_helpers.clone() }
            else { helper_provenance::calls(elf, sym, &got_relocations, helper_addrs)? };
        let helper_tails=helper_calls.tails.iter().map(|ip| sym.address+ip).collect();
        let memory_constants = memory::constants(&bytes, sym.address, &helper_calls.branch_targets,&helper_tails)?;
        for ip in &helper_calls.tails {
            if let Some(name) = helper_calls.single.get(ip) {
                tail_transfers.insert(*ip, DirectTailTransfer { symbol: name.clone(), addend: -4,
                    defined: None, relocation_offset: None });
            }
        }
        let proven_helpers = &helper_calls.single;
        let defined_code_calls = code_provenance::calls(elf, sym, included)?;
        let entry_abi_strip = if is_entry {
            let entry_has_tail_call = proven_helpers.values().any(|name| name == "bpf_tail_call")
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
                (!proof_mode && proof_input) || (proof_mode && preserve_entry_abi),
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
        let proven_maps = if !proof_mode {
            known_maps::arguments(&bytes, sym, &got_relocations, &absolute_maps, map_addrs,
                                  &helper_calls.branch_targets)?
        } else { HashMap::new() };

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

            if let Some(tail) = tail_transfers.remove(&local_ip) {
                let conditional = insn.is_jcc_short_or_near();
                if conditional {
                    // Preserve the original decision around the existing tail rewrite.
                    let mut guard = insn;
                    guard.negate_condition_code();
                    guard.set_near_branch64(insn.next_ip() - sym.address);
                    push_x86_replacement(&mut local, &mut kinds, &mut insn_local_ip,
                        local_ip, guard, None);
                }
                let mut jump = Instruction::default();
                jump.set_code(Code::Jmp_rel32_64);
                jump.set_op0_kind(OpKind::NearBranch64);
                // Prevent branch relaxation from discarding its disp32 slot.
                jump.set_near_branch64(X86_JMP_END_PLACEHOLDER_TARGET);
                let kind = if let Some(callee) = &tail.defined {
                    Some(PatchKind::DirectBranch { target_symbol_key: symbol_key(callee), opcode: 0xe9 })
                } else if !proof_mode {
                    let target_addr = match map_op_target(map_ops, proven_maps.get(&local_ip), &tail.symbol) {
                        Some(target) => target,
                        None => runtime_call_target(&tail.symbol, helper_addrs,
                            &format!("x86 helper tail branch {}", tail.symbol))?,
                    };
                    Some(PatchKind::HelperBranchRel32 { target_addr, opcode: 0xe9 })
                } else { None };
                let index = local.len();
                if conditional {
                    push_x86_synthetic(&mut local, &mut kinds, &mut insn_local_ip,
                        &mut next_synthetic_ip, jump)?;
                    kinds[index] = kind;
                } else {
                    push_x86_replacement(&mut local, &mut kinds, &mut insn_local_ip,
                        local_ip, jump, kind);
                }
                if let Some(offset) = tail.relocation_offset {
                    let key=local_site_key(sym,offset);
                    canonicalized_relocations.insert(key);
                    resolved_got_relocations.insert(key); // Native emission consumed this field too.
                }
                if proof_mode { tail_calls.push((index, tail)); }
                else { resolved_helper_call_sites.insert(site_key); }
                continue;
            }

            if let Some(reference) = absolute_maps.get(&site_key) {
                let (replacement, kind) = non_pic::address(reference, proof_mode)?;
                push_x86_replacement(&mut local, &mut kinds, &mut insn_local_ip,
                    local_ip, replacement, Some(kind));
                let key = local_site_key(sym, reference.relocation_offset);
                canonicalized_relocations.insert(key);
                resolved_got_relocations.insert(key);
                continue;
            }

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
                            resolved_got_relocations.insert(patch_key);
                            continue;
                        }
                        let local_memory = matches!(target_name.as_str(), "memset" | "memcpy");
                        if target_name.starts_with("bpf_") || helper_addrs.contains_key(target_name) || local_memory
                        {
                            if !proof_mode || local_memory {
                                // Preserve helper-address observations as well as calls.
                                // Local memory routines retain their existing private binding.
                                if !local_memory {
                                    let address = resolve_helper_target(target_name, helper_addrs,
                                        "x86 helper address")?;
                                    push_x86_replacement(&mut local, &mut kinds, &mut insn_local_ip,
                                        local_ip, build_x86_movabs_reg(dst, address)?, None);
                                }
                                resolved_got_relocations.insert(patch_key);
                                if local_memory { canonicalized_relocations.insert(patch_key); }
                                continue;
                            }
                        }
                    }
                }
            }

            if insn.is_ip_rel_memory_operand() {
                let at=local_ip+u64::from(decoder.get_constant_offsets(&insn).displacement_offset() as u32);
                if let Some(reference)=writable_references.get(&local_site_key(sym,at)).filter(|r|
                    !proof_mode || insn.mnemonic()!=Mnemonic::Lea || r.offset!=0 ||
                    Some(insn.op0_register())!=x86_gpr64_family(insn.op0_register())) {
                    for (index,(instruction,kind)) in writable_data::instructions(insn,reference,proof_mode)?.into_iter().enumerate() {
                        if index==0 {
                            push_x86_replacement(&mut local,&mut kinds,&mut insn_local_ip,local_ip,instruction,kind);
                        } else {
                            push_x86_synthetic(&mut local,&mut kinds,&mut insn_local_ip,&mut next_synthetic_ip,instruction)?;
                            *kinds.last_mut().unwrap()=kind;
                        }
                    }
                    canonicalized_relocations.insert(local_site_key(sym,at));
                    resolved_got_relocations.insert(local_site_key(sym,at));
                    continue;
                }
            }

            if !proof_mode && !(insn.flow_control() == FlowControl::IndirectBranch &&
                table_indirect_sites.contains(&site_key)) {
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
                    kinds.push(Some(PatchKind::DirectBranch {
                        target_symbol_key: symbol_key(target_symbol),
                        opcode: 0xe8,
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
                let call_reg = x86_indirect_call_register(&insn);
                let helper_call_name = helper_call_sites.get(&site_key).cloned()
                    .or_else(|| proven_helpers.get(&local_ip).cloned());
                if let Some(name) = helper_call_name {
                    if show {
                        eprintln!("native-link-helper-site {}", serde_json::json!({
                            "symbol": sym.name, "input_offset": sym.address+local_ip,
                            "helper": name, "map": proven_maps.get(&local_ip),
                            "proof_mode": proof_mode,
                        }));
                    }
                    if let Some(routine) = memory::Routine::at_call(&name, memory_constants.get(&local_ip))
                    {
                        push_x86_replacement(&mut local, &mut kinds, &mut insn_local_ip,
                            local_ip, build_x86_helper_call_rel32_slot()?,
                            Some(PatchKind::LocalMemory { routine }));
                        resolved_helper_call_sites.insert(site_key);
                        if helper_call_sites.contains_key(&site_key) {
                            canonicalized_relocations.insert(local_site_key(sym, local_ip + insn.len() as u64 - 4));
                        }
                        continue;
                    }
                    if proof_mode {
                        local.push(insn);
                        kinds.push(None);
                        insn_local_ip.push(local_ip);
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
                        let (tail_stub, tail_count_field) = build_x86_tail_call_inline(
                            helper_addrs,
                            callee_saved_mask,
                            &entry_abi_strip.tail_call_cleanup_bytes,
                            entry_abi_strip.tail_call_bpf_rbp_rsp_offset,
                            entry_abi_strip.tail_call_bpf_rbp_is_live,
                        )?;
                        // The stub is emitted as 16-byte chunks. A synthetic
                        // advances next_synthetic_ip by one whatever its width, so
                        // the chunk holding the field is field/16 and the field sits
                        // field%16 bytes into that chunk.
                        let field_chunk = tail_count_field / 16;
                        let field_delta = (tail_count_field % 16) as u32;
                        for (chunk_index, ib) in tail_stub.into_iter().enumerate() {
                            if chunk_index == 0 {
                                push_x86_replacement(&mut local,&mut kinds,&mut insn_local_ip,local_ip,ib,None);
                            } else {
                                push_x86_synthetic(&mut local,&mut kinds,&mut insn_local_ip,&mut next_synthetic_ip,ib)?;
                            }
                            if chunk_index == field_chunk {
                                if let Some(last) = kinds.last_mut() {
                                    *last = Some(PatchKind::TailCount { field_delta });
                                }
                            }
                        }
                        resolved_helper_call_sites.insert(site_key);
                        continue;
                    }
                    if name == "bpf_map_lookup_elem" {
                        let native_call_index = lookup_call_counter;
                        lookup_call_counter += 1;
                        let (site_label, spec) = select_lookup_site(
                            lookup_maps, native_call_index,
                            proven_maps.get(&local_ip).map(String::as_str),
                            &sym.name, map_lookup_helper_addr,
                        )?;
                        match spec.kind {
                            LookupKind::Array | LookupKind::PerCpuArray => {
                                push_x86_replacement(&mut local, &mut kinds, &mut insn_local_ip,
                                    local_ip, build_x86_helper_call_rel32_slot()?,
                                    Some(PatchKind::LocalArray {
                                        bytes: build_x86_array_lookup_routine(&spec)?,
                                    }));
                                resolved_helper_call_sites.insert(site_key);
                                continue;
                            }
                            LookupKind::Call
                            | LookupKind::Lpm12
                            | LookupKind::Hash
                            | LookupKind::LruHash
                            | LookupKind::PerCpuHash
                            | LookupKind::HashOfMaps => {
                                let helper_addr = resolve_lookup_site_target(&spec,
                                    &format!("x86 lookup-site {site_label} ({:?})",spec.kind))?;
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
                                continue;
                            }
                        }
                    }

                    if !proof_mode {
                        if let Some(load) = x86_inline_load_helper(&name, helper_addrs)? {
                            push_x86_replacement(&mut local, &mut kinds, &mut insn_local_ip, local_ip, load, None);
                            resolved_helper_call_sites.insert(site_key);
                            continue;
                        }
                    }

                    // Use the actual native RDI provenance, never source call order.
                    if let Some(target) = map_op_target(map_ops, proven_maps.get(&local_ip), &name) {
                        push_x86_helper_call_reloc(&mut local, &mut kinds,
                            &mut insn_local_ip, local_ip, target)?;
                        resolved_helper_call_sites.insert(site_key);
                        continue;
                    }

                    let helper_addr = runtime_call_target(
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
                    continue;
                } else if let Some(reg) = call_reg.filter(|_| !defined_code_calls.contains(&local_ip)) {
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
            local.push(insn);
            kinds.push(None);
            insn_local_ip.push(local_ip);
        }

        // Encode this symbol's local stream at IP=0.
        // Normally iced fixes short intra-symbol branches after helper/map
        // rewrites change instruction sizes. If it hits an edge case at the
        // i8 distance boundary, fall back to a fixed near-branch layout with
        // manually remapped local targets.
        let encoded = encode_x86_local_block(&sym.name, sym.size, &local, &insn_local_ip)?;

        let sym_base = blob.len();
        sym_global_offset.insert(symbol_key(sym), sym_base);
        for (index, tail) in tail_calls {
            tail_proof_relocs.push(ProofReloc {
                offset: (sym_base + encoded.new_instruction_offsets[index] as usize + 1) as u64,
                r_type: 4, symbol: tail.symbol, addend: tail.addend, data: None,
            });
        }
        for (i, kind) in kinds.iter().enumerate() {
            let Some(kind) = kind else { continue };
            let off_in_sym = encoded
                .new_instruction_offsets
                .get(i)
                .copied()
                .ok_or_else(|| anyhow!("missing offset for instruction {i} in {}", sym.name))?
                as usize;
            // A kind may name a field inside its instruction rather than the
            // instruction's first byte; the tail-count field follows a
            // three-byte opcode.
            let field_delta = match kind {
                PatchKind::TailCount { field_delta } => *field_delta as usize,
                _ => 0,
            };
            patches.push(PatchInfo {
                global_offset: sym_base + off_in_sym + field_delta,
                kind: kind.clone(),
            });
        }
        layouts.push(SymbolLayout {
            sym: sym.clone(),
            base_in_blob: sym_base,
            insn_local_ip,
            new_offset_in_sym: encoded.new_instruction_offsets.clone(),
        });
        code_ranges.push((sym_base, sym_base + encoded.code_buffer.len()));
        blob.extend_from_slice(&encoded.code_buffer);
    }

    // Add each selected routine once, in call-site order, before all data pools.
    // Proof symbols make the same bodies reachable during kernel relinking.
    let original_code_end = blob.len();
    let mut memory_offsets = HashMap::new();
    let mut memory_symbols = Vec::new();
    for patch in &patches {
        if let PatchKind::LocalMemory { routine } = patch.kind {
            if memory_offsets.contains_key(&routine) { continue; }
            let bytes = routine.bytes()?;
            let start = blob.len();
            let name = routine.name();
            for symbol in elf.symbols() {
                if symbol.name()? == name {
                    bail!("input symbol conflicts with linker memory routine {name}");
                }
            }
            memory_offsets.insert(routine, start);
            memory_symbols.push(ProofSymbol { name, offset: start as u64, size: bytes.len() as u64 });
            code_ranges.push((start, start + bytes.len()));
            blob.extend_from_slice(&bytes);
        }
    }
    share_x86_array_routines(&mut blob, &patches, &mut code_ranges, show)?;

    // Apply intra-blob direct call and tail-jump patches first;
    // those need only `sym_global_offset` which is already known.
    for p in &patches {
        if let PatchKind::DirectBranch { target_symbol_key, opcode } = &p.kind {
            let off = p.global_offset;
            if off + 5 > blob.len() || blob[off] != *opcode {
                bail!("direct branch at off {off:#x} lost its rel32 opcode");
            }
            let target_global = *sym_global_offset
                .get(target_symbol_key)
                .ok_or_else(|| anyhow!("branch target sym key not in index map"))?;
            let disp = target_global as i64 - (off + 5) as i64;
            let d = i32::try_from(disp).map_err(|_| anyhow!("branch disp {disp} exceeds i32"))?;
            blob[off + 1..off + 5].copy_from_slice(&d.to_le_bytes());
        }
        if let PatchKind::LocalMemory { routine } = &p.kind {
            let off = p.global_offset;
            let target = memory_offsets[routine];
            let disp = i32::try_from(target as i64 - (off + 5) as i64)?;
            blob[off + 1..off + 5].copy_from_slice(&disp.to_le_bytes());
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
            PatchKind::HelperBranchRel32 { target_addr, opcode } => {
                let offset = u32::try_from(p.global_offset)
                    .map_err(|_| anyhow!("helper call reloc offset exceeds u32"))?;
                let end = p
                    .global_offset
                    .checked_add(X86_HELPER_CALL_REL32_SLOT.len())
                    .ok_or_else(|| anyhow!("helper call slot offset overflow"))?;
                if end > blob.len() || blob[p.global_offset] != *opcode
                    || (*opcode == 0xe8 && blob[p.global_offset..end] != X86_HELPER_CALL_REL32_SLOT[..])
                {
                    bail!(
                        "helper branch slot at off {:#x} lost its rel32 opcode",
                        p.global_offset
                    );
                }
                blob[p.global_offset + 1..end].fill(0);
                relocs.push(RelocRecord {
                    offset,
                    kind: NATIVE_LAB_RELOC_HELPER_CALL_REL32,
                    target: *target_addr,
                });
            }
            PatchKind::TailCount { .. } => {
                // Counter-pointer displacement within the physical BPF frame.
                // This is independent of the target program's entry offset.
                relocs.push(RelocRecord {
                    offset: u32::try_from(p.global_offset)
                        .map_err(|_| anyhow!("tail-count reloc offset exceeds u32"))?,
                    kind: NATIVE_LAB_RELOC_X86_TAIL_COUNT,
                    target: 0,
                });
            }
            PatchKind::WritableAddress { name } => {
                tail_proof_relocs.push(ProofReloc{offset:(p.global_offset+3) as u64,r_type:2,
                    symbol:name.clone(),addend:-4,data:None});
            }
            PatchKind::ProofMapAddress { name } => {
                tail_proof_relocs.push(ProofReloc { offset: (p.global_offset + 3) as u64,
                    r_type: 9, symbol: name.clone(), addend: -4, data: None });
            }
            PatchKind::JmpEnd | PatchKind::DirectBranch { .. } | PatchKind::LocalMemory { .. }
            | PatchKind::LocalArray { .. } => {}
        }
    }

    // Stage 2: resolve ELF relocations. GOT helper calls keep their original
    // RIP-relative indirect-call form and point at in-blob literal-pool entries;
    // PLT32 helper calls use in-blob absolute trampolines.
    let mut proof_data_relocs = Vec::new();
    let mut proof_relocs = if proof_mode {
        let (mut collected, nested) = collect_x86_proof_relocs(elf, &layouts, &canonicalized_relocations, &writable_references, map_addrs)?;
        proof_data_relocs = nested;
        collected.extend(tail_proof_relocs);
        collected
    } else {
        relocs.extend(apply_elf_relocations(
            elf,
            &layouts,
            helper_addrs,
            map_addrs,
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
        // Map only retained source instructions with a real encoder offset.
        // Synthetic, dropped, or expanded instructions have no such row;
        // never attribute their bytes to a nearby source instruction.
        for layout in &layouts {
            for (&source, &encoded) in layout.insn_local_ip.iter().zip(&layout.new_offset_in_sym) {
                if source == u64::MAX || encoded == u32::MAX { continue; }
                let output = layout.base_in_blob + encoded as usize;
                if output >= blob.len() { continue; }
                let mut decoder = Decoder::with_ip(64, &blob[output..], output as u64, DecoderOptions::NONE);
                let instruction = decoder.decode();
                if instruction.is_invalid() { continue; }
                eprintln!("native-link-source-map {}", serde_json::json!({
                    "symbol": layout.sym.name, "section": layout.sym.section_index.0,
                    "input_offset": layout.sym.address + source, "symbol_offset": source,
                    "output_offset": output, "length": instruction.len(),
                }));
            }
        }
        disasm(&blob);
    }
    let proof_symbols = if proof_mode {
        let mut symbols = proof_symbols_from_x86_layouts(&layouts, original_code_end)?;
        if let Some(body) = entry_body_name {
            for symbol in &mut symbols {
                if symbol.name == entry.name { symbol.name = body.clone(); }
            }
            for reloc in &mut proof_relocs {
                if reloc.symbol == entry.name { reloc.symbol = body.clone(); }
            }
            proof_relocs.push(ProofReloc {
                offset: 5, r_type: 4, symbol: body, addend: -4, data: None,
            });
            symbols.insert(0, ProofSymbol { name: entry.name.clone(), offset: 0, size: 18 });
        }
        symbols.extend(memory_symbols);
        symbols
    } else {
        Vec::new()
    };
    let load_sites = x86_decoded_load_sites(&blob, &code_ranges);
    Ok(RewriteResult {
        blob,
        relocs,
        map_patches,
        callee_saved_mask,
        proof_relocs,
        proof_data_relocs,
        proof_symbols,
        load_sites,
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
    resolved_relocations: &HashSet<LocalSiteKey>,
    writable_references: &HashMap<LocalSiteKey,writable_data::Reference>,
    map_addrs: &HashMap<String, u64>,
) -> Result<(Vec<ProofReloc>, Vec<ProofDataReloc>)> {
    let mut relocs = Vec::new();
    let mut nested = BTreeMap::new();
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
            if resolved_relocations.contains(&local_site_key(&layout.sym, local_patch_off)) {
                continue;
            }
            if let Some(reference)=writable_references.get(&local_site_key(&layout.sym,local_patch_off)) {
                let index=layout.insn_local_ip.iter().enumerate()
                    .filter(|(_,ip)|**ip!=u64::MAX && **ip<=local_patch_off)
                    .max_by_key(|(_,ip)|**ip).map(|(i,_)|i)
                    .ok_or_else(||anyhow!("mutable PC32 relocation has no instruction"))?;
                let offset=layout.base_in_blob+layout.new_offset_in_sym[index] as usize+
                    (local_patch_off-layout.insn_local_ip[index]) as usize;
                relocs.push(ProofReloc{offset:offset as u64,r_type,symbol:reference.name.clone(),
                    addend:reference.addend,data:None});
                continue;
            }
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
                    let table = if sym_size == 0 && target_name.is_empty() {
                        readonly_relocs::table_span(elf, layouts, target_section_idx,
                            i128::from(sym_off_in_sec)+i128::from(reloc.addend())+4)?
                    } else { None };
                    let copy_start = table.map(|(start, _)| start)
                        .unwrap_or(if sym_size == 0 { 0 } else { sym_off_in_sec });
                    let data_addend = reloc.addend().checked_sub(i64::try_from(table.map(|(start, _)| start).unwrap_or(0))?)
                        .ok_or_else(|| anyhow!("sliced code-table addend overflow"))?;
                    let (data_symbol_name, sym_bytes) = if let Some((start, size)) = table {
                        let bytes = target_data.get(usize::try_from(start)?..usize::try_from(start+size)?)
                            .ok_or_else(|| anyhow!("referenced code-table slice exceeds section"))?.to_vec();
                        (format!("section:{target_section_idx:?}:{section_name}:table_{start:x}"), bytes)
                    } else if sym_size == 0 {
                        if !target_name.is_empty() {
                            bail!("PC32 proof target {} has zero size", target_name);
                        }
                        let section_bytes = if readonly_relocs::immutable_section(target_section.kind(), &section_name) {
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
                    for reloc in readonly_relocs::data_relocations(elf, layouts,
                        target_section_idx, copy_start,
                        sym_bytes.len() as u64, &data_symbol_name, map_addrs)? {
                        let reloc = reloc.proof();
                        let key = (reloc.owner.clone(), reloc.offset);
                        if let Some(previous) = nested.insert(key, reloc.clone()) {
                            if previous != reloc { bail!("conflicting nested read-only relocations"); }
                        }
                    }
                    relocs.push(ProofReloc {
                        offset: (new_insn_off + off_within_insn) as u64,
                        r_type,
                        symbol: data_symbol_name,
                        addend: data_addend,
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
    Ok((relocs, nested.into_values().collect()))
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
    let mut out_relocs = Vec::new();

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

            if matches!(r_type, 1 | 2 | 4 | 10 | 11) && resolved_got_relocations
                .contains(&local_site_key(&layout.sym, local_patch_off)) {
                continue;
            }

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

                    let kernel_addr = helper_addrs.get(&target_name).copied()
                        .or_else(|| map_addrs.get(&target_name).copied())
                        .ok_or_else(|| anyhow!(
                            "GOT-relative reloc against unknown symbol {}; add it to link-plan helpers or maps",
                            target_name
                        ))?;
                    let is_map_literal = !helper_addrs.contains_key(&target_name)
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

                    // Calls already use direct helper slots. Remaining data
                    // references share one pool entry per exact symbol.
                    let pool_off = if let Some(&off) = map_pool_entry.get(&target_name) {
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
                    if resolved_got_relocations.contains(&local_site_key(&layout.sym,local_patch_off)) {continue;}

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
                    let table = if sym_size == 0 && target_name.is_empty() {
                        readonly_relocs::table_span(elf, layouts, target_section_idx,
                            i128::from(sym_off_in_sec)+i128::from(reloc.addend())+4)?
                    } else { None };
                    let copy_start = table.map(|(start, _)| start)
                        .unwrap_or(if sym_size == 0 { 0 } else { sym_off_in_sec });
                    let data_addend = reloc.addend().checked_sub(i64::try_from(table.map(|(start, _)| start).unwrap_or(0))?)
                        .ok_or_else(|| anyhow!("sliced code-table addend overflow"))?;
                    let (data_symbol_name, sym_bytes) = if let Some((start, size)) = table {
                        let bytes = target_data.get(usize::try_from(start)?..usize::try_from(start+size)?)
                            .ok_or_else(|| anyhow!("referenced code-table slice exceeds section"))?.to_vec();
                        (format!("section:{target_section_idx:?}:{section_name}:table_{start:x}"), bytes)
                    } else if sym_size == 0 {
                        if !target_name.is_empty() {
                            bail!("PC32 target {} has zero size; cannot embed", target_name);
                        }
                        let section_bytes = if readonly_relocs::immutable_section(target_section.kind(), &section_name) {
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
                        for relocation in readonly_relocs::data_relocations(elf, layouts,
                            target_section_idx, copy_start,
                            sym_bytes.len() as u64, &data_symbol_name, map_addrs)? {
                            match relocation {
                                readonly_relocs::DataReloc::RelativeCode { proof, target_offset, table_offset } => {
                                    let displacement = i128::from(target_offset) - i128::try_from(off)? - i128::from(table_offset);
                                    let displacement = i32::try_from(displacement)
                                        .map_err(|_| anyhow!("relative jump-table displacement exceeds i32"))?;
                                    let field = off.checked_add(usize::try_from(proof.offset)?)
                                        .ok_or_else(|| anyhow!("relative jump-table patch offset overflow"))?;
                                    blob[field..field + 4].copy_from_slice(&displacement.to_le_bytes());
                                }
                                readonly_relocs::DataReloc::MapPointer(proof) => {
                                    if !map_addrs.contains_key(&proof.symbol) {
                                        bail!("immutable table references unknown live map/data capability {}", proof.symbol);
                                    }
                                    let field = off.checked_add(usize::try_from(proof.offset)?)
                                        .ok_or_else(|| anyhow!("immutable map-pointer patch offset overflow"))?;
                                    blob[field..field + 8].fill(0);
                                    map_patches.push(MapPatch { name: proof.symbol, offset: field });
                                }
                                readonly_relocs::DataReloc::AbsoluteCode { proof, target_offset } => {
                                    let field = off.checked_add(usize::try_from(proof.offset)?)
                                        .ok_or_else(|| anyhow!("absolute code-pointer patch offset overflow"))?;
                                    blob[field..field + 8].fill(0);
                                    out_relocs.push(RelocRecord { offset: u32::try_from(field)?,
                                        kind: NATIVE_LAB_RELOC_IMAGE_POINTER, target: target_offset });
                                }
                            }
                        }
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
                    let disp = embed_off as i64 + data_addend - disp32_off as i64;
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

fn x86_frame_pointer_prologue(insns: &[Instruction]) -> Option<(Vec<Register>, u64)> {
    let mut saved = Vec::new();
    let mut frame_pointer = false;
    let mut cursor = 0;
    for insn in insns {
        if let Some(reg) = x86_saved_push_reg(insn) {
            saved.push(reg);
        } else if x86_mov_gpr64_to_gpr64(insn) == Some((Register::RBP, Register::RSP))
            && saved.contains(&Register::RBP) {
            frame_pointer = true;
        } else if insn.mnemonic() != Mnemonic::Endbr64 {
            break;
        }
        cursor += 1;
    }
    frame_pointer.then(|| (saved, insns.get(cursor).and_then(x86_sub_rsp_imm).unwrap_or(0)))
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

    if let Some((saved, stack_alloc)) = x86_frame_pointer_prologue(&insns) {
        // Keep frame-pointer saves in their native frame. Removing/renaming
        // them would move rbp-relative locals. The tail helper must recover
        // the original BPF RBP below every later save and the local allocation.
        return x86_tail_call_frame_or_default(bytes, base_ip, &insns, &saved,
            stack_alloc, require_tail_call_frame, symbol_end, proof_return_jmp_target);
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

    // Clang also allocates fixed local slots with PUSH of a caller-saved
    // register (Tracee sys_exit uses PUSH RAX). These bytes lie below the
    // saved BPF RBP just like SUB RSP storage, even though they are not saves.
    let mut stack_alloc = 0u64;
    for insn in &insns[prologue_regs.len()..] {
        let amount = if let Some(bytes) = x86_sub_rsp_imm(insn) {
            bytes
        } else if insn.mnemonic() == Mnemonic::Push && x86_saved_push_reg(insn).is_none() {
            u64::try_from(-insn.stack_pointer_increment())
                .map_err(|_| anyhow!("invalid native entry stack push"))?
        } else {
            break;
        };
        stack_alloc = stack_alloc.checked_add(amount)
            .ok_or_else(|| anyhow!("native entry stack allocation overflow"))?;
    }
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

    // The image carries `callee_saved_mask` to the x86 BPF JIT prologue,
    // which saves the same host registers we strip here. Stack movement before the
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
            if prev.mnemonic() == Mnemonic::Leave && prologue_set.contains(&Register::RBP) {
                seen.insert(Register::RBP);
                cursor -= 1;
                continue;
            }
            if x86_mov_gpr64_to_gpr64(prev) == Some((Register::RSP, Register::RBP)) {
                cursor -= 1;
                continue;
            }
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
    // Resolved relative code-table sites bypass this generic check. An
    // unmatched indirect branch still has no image-bound target description.
    if matches!(fc, FlowControl::IndirectBranch) {
        bail!(
            "indirect branch at IP {:#x} has no resolved code-table relocation",
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
        Some(PatchKind::HelperBranchRel32 {
            target_addr: helper_addr,
            opcode: 0xe8,
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

/// Re-encode a raw instruction stream so its branches take the shortest form,
/// remapping the recorded reloc offsets onto the compacted bytes.
fn compact_branches(bytes: &[u8], relocs: &mut [&mut RelocRecord]) -> Result<Vec<u8>> {
    let instructions: Vec<_> = Decoder::new(64, bytes, DecoderOptions::NONE).iter().collect();
    let indices: HashMap<_,_> = instructions.iter().enumerate()
        .map(|(i,insn)| (insn.ip() as u32,i)).collect();
    let encoded = BlockEncoder::encode(64, InstructionBlock::new(&instructions,0),
        BlockEncoderOptions::RETURN_NEW_INSTRUCTION_OFFSETS)?;
    for reloc in relocs.iter_mut() {
        reloc.offset = encoded.new_instruction_offsets[indices[&reloc.offset]];
    }
    Ok(encoded.code_buffer)
}

fn build_x86_tail_call_inline(
    helper_addrs: &HashMap<String, u64>,
    callee_saved_mask: u8,
    native_cleanup: &[u8],
    saved_bpf_rbp_rsp_offset: Option<i32>,
    bpf_rbp_is_live: bool,
) -> Result<(Vec<Instruction>, usize)> {
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
    bytes.extend_from_slice(&[0x89, 0xD2]); // mov edx, edx
    memory::Routine::operand(&mut bytes, &[0x39, 0x96], map_max_entries); // cmp [rsi+bound], edx
    let jbe_out = append_x86_jcc_rel32(&mut bytes, 0x86);

    if let Some(offset) = saved_bpf_rbp_rsp_offset {
        bytes.extend_from_slice(&[0x48, 0x8B, 0x84, 0x24]); // mov rax, [rsp + disp32]
        bytes.extend_from_slice(&offset.to_le_bytes());
        bytes.extend_from_slice(&[0x48, 0x8B, 0x80]); // mov rax, [rax - 16]
    } else if bpf_rbp_is_live {
        bytes.extend_from_slice(&[0x48, 0x8B, 0x85]); // mov rax, [rbp - 16]
    } else {
        bail!("x86 bpf_tail_call lowering missing BPF rbp location");
    }
    let tail_count_field = bytes.len();
    bytes.extend_from_slice(&(-16i32).to_le_bytes());
    bytes.extend_from_slice(&[0x48, 0x83, 0x38, MAX_TAIL_CALL_CNT]); // cmp qword [rax], 33
    let jae_out = append_x86_jcc_rel32(&mut bytes, 0x83);

    bytes.extend_from_slice(&[0x48, 0x8B, 0x8C, 0xD6]); // mov rcx, [rsi + rdx*8 + disp32]
    bytes.extend_from_slice(&array_ptrs.to_le_bytes());
    bytes.extend_from_slice(&[0x48, 0x85, 0xC9]); // test rcx, rcx
    let je_out = append_x86_jcc_rel32(&mut bytes, 0x84);

    bytes.extend_from_slice(&[0x48, 0x83, 0x00, 0x01]); // add qword ptr [rax], 1
    bytes.extend_from_slice(native_cleanup);
    append_x86_stub_callee_pop(&mut bytes, callee_saved_mask);
    bytes.extend_from_slice(&[0x58, 0x58]); // pop tail_call_cnt_ptr; pop tail_call_cnt
    memory::Routine::operand(&mut bytes, &[0x48, 0x8b, 0x89], prog_bpf_func); // rcx=prog->bpf_func
    if let Ok(offset)=i8::try_from(tail_call_offset as i32) {
        bytes.extend_from_slice(&[0x48,0x83,0xc1,offset as u8]);
    } else {
        bytes.extend_from_slice(&[0x48,0x81,0xc1]);
        bytes.extend_from_slice(&tail_call_offset.to_le_bytes());
    }
    bytes.extend_from_slice(&[0xFF, 0xE1]); // jmp rcx

    let out = bytes.len();
    patch_x86_rel32(&mut bytes, jbe_out, out)?;
    patch_x86_rel32(&mut bytes, jae_out, out)?;
    patch_x86_rel32(&mut bytes, je_out, out)?;
    // Make the common miss label an instruction for the branch compactor.
    // The raw counter load keeps disp32: kind10 is a four-byte kernel patch.
    bytes.push(0x90);
    let mut marker=RelocRecord {offset:u32::try_from(tail_count_field-3)?,
        kind:NATIVE_LAB_RELOC_X86_TAIL_COUNT,target:0};
    let mut bytes=compact_branches(&bytes,&mut [&mut marker])?;
    bytes.truncate(bytes.len()-1); // The label remains the byte immediately after the stub.
    Ok((declared_byte_chunks(&bytes)?, marker.offset as usize+3))
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
        if let Ok(short) = i8::try_from(imm) {
            bytes.extend_from_slice(&[0x48, 0x6B, 0xC0, short as u8]); // imul rax, rax, imm8
        } else {
            bytes.extend_from_slice(&[0x48, 0x69, 0xC0]); // imul rax, rax, imm32
            bytes.extend_from_slice(&imm.to_le_bytes());
        }
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
    if value_offset == 0 {
        bytes.extend_from_slice(&[0x48, 0x01, 0xF8]); // add rax, rdi
    } else if let Ok(short) = i8::try_from(value_offset as i32) {
        bytes.extend_from_slice(&[0x48, 0x8D, 0x44, 0x07, short as u8]);
    } else {
        bytes.extend_from_slice(&[0x48, 0x8D, 0x84, 0x07]); // lea rax, [rdi + rax + disp32]
        bytes.extend_from_slice(&value_offset.to_le_bytes());
    }
    Ok(())
}

fn build_x86_array_lookup_routine(spec: &LookupSiteSpec) -> Result<Vec<u8>> {
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

    body.push(0xc3); // Successful lookup returns without a shared-return jump.
    let body_len = u8::try_from(body.len())
        .map_err(|_| anyhow!("array lookup inline body too large: {} bytes", body.len()))?;

    let mut bytes = Vec::new();
    bytes.extend_from_slice(&[0x8B, 0x06]); // mov eax, [rsi]
    append_x86_cmp_eax_imm(&mut bytes, spec.max_entries);
    bytes.extend_from_slice(&[0x73, body_len]); // jae null
    bytes.extend_from_slice(&body);
    bytes.extend_from_slice(&[0x31, 0xC0]); // xor eax, eax
    bytes.push(0xc3);
    Ok(bytes)
}

fn share_x86_array_routines(blob: &mut Vec<u8>, patches: &[PatchInfo],
                            code_ranges: &mut Vec<(usize, usize)>, show: bool) -> Result<()> {
    // Machine bytes include every bound constant and the per-CPU offset.
    // Different shapes cannot merge; identical bodies serve every such call
    // in this image without repeating the map-type dispatch.
    let mut offsets = HashMap::new();
    for patch in patches {
        let PatchKind::LocalArray { bytes } = &patch.kind else { continue; };
        let target = *offsets.entry(bytes).or_insert_with(|| {
            let start = blob.len();
            blob.extend_from_slice(bytes);
            let range = (start, blob.len());
            code_ranges.push(range);
            show_lto_range(show, "known_array", range);
            start
        });
        patch_x86_rel32(blob, patch.global_offset + 1, target)?;
    }
    Ok(())
}

fn append_x86_byte_rax_imm(bytes: &mut Vec<u8>, opcode: u8, reg_bits: u8, disp: u32, imm: u8) {
    bytes.push(opcode);
    if disp == 0 {
        bytes.push(reg_bits);
    } else if let Ok(short) = i8::try_from(disp as i32) {
        bytes.extend_from_slice(&[0x40 | reg_bits, short as u8]);
    } else {
        bytes.push(0x80 | reg_bits);
        bytes.extend_from_slice(&disp.to_le_bytes());
    }
    bytes.push(imm);
}

fn build_x86_lookup_call_postprocess(spec: &LookupSiteSpec) -> Result<Vec<Instruction>> {
    let mut body = Vec::new();
    match spec.kind {
        LookupKind::Call | LookupKind::Lpm12 | LookupKind::Array | LookupKind::PerCpuArray => {}
        LookupKind::Hash => {
            append_x86_add_rax_imm(&mut body, spec.key_offset);
        }
        LookupKind::HashOfMaps => {
            append_x86_add_rax_imm(&mut body, spec.key_offset);
            body.extend_from_slice(&[0x48, 0x8B, 0x00]); // mov rax, [rax]
        }
        LookupKind::LruHash => {
            append_x86_byte_rax_imm(&mut body, 0x80, 0x38, spec.value_offset, 0); // cmp ref,0
            let skip_store = append_x86_jcc_rel8(&mut body, 0x75); // jne skip ref update
            append_x86_byte_rax_imm(&mut body, 0xc6, 0, spec.value_offset, 1); // mov ref,1
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

fn append_x86_cmp_eax_imm(bytes: &mut Vec<u8>, imm: u32) {
    if imm <= 0x7f {
        bytes.extend_from_slice(&[0x83, 0xF8, imm as u8]);
    } else {
        bytes.push(0x3D);
        bytes.extend_from_slice(&imm.to_le_bytes());
    }
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

#[cfg(test)]
mod tests {
    #[test]
    fn kernel_inlined_helpers_become_one_load() {
        let helpers = HashMap::from([(CURRENT_TASK_KEY.to_string(), 0xffff_ffff_842b_0018u64),
            (CPU_NUMBER_KEY.to_string(), 0xffff_ffff_842b_0034), (JIFFIES_64_KEY.to_string(), 0xffff_ffff_8300_9a00)]);
        for (name, want) in [
            ("bpf_get_current_task", vec![0x65, 0x48, 0x8b, 0x04, 0x25, 0x18, 0x00, 0x2b, 0x84]),
            ("bpf_get_current_task_btf", vec![0x65, 0x48, 0x8b, 0x04, 0x25, 0x18, 0x00, 0x2b, 0x84]),
            ("bpf_get_smp_processor_id", vec![0x65, 0x8b, 0x04, 0x25, 0x34, 0x00, 0x2b, 0x84]),
            ("bpf_jiffies64", vec![0x48, 0x8b, 0x04, 0x25, 0x00, 0x9a, 0x00, 0x83]),
        ] {
            let load = x86_inline_load_helper(name, &helpers).unwrap().unwrap();
            let mut encoder = iced_x86::Encoder::new(64);
            encoder.encode(&load, 0).unwrap();
            assert_eq!(encoder.take_buffer(), want, "{name}");
        }
        assert!(x86_inline_load_helper("bpf_get_current_task", &HashMap::new()).unwrap().is_none());
        assert!(x86_inline_load_helper("bpf_ktime_get_ns", &helpers).unwrap().is_none());
    }

    use super::*;

    #[test]
    #[ignore = "uses retained application load plans"]
    fn retained_lto_diagnostics_preserve_payload_bytes() -> Result<()> {
        let report = std::env::var("NATIVE_LINK_LTO_AUDIT_REPORT")?;
        let report: serde_json::Value = serde_json::from_slice(&fs::read(report)?)?;
        let baseline = std::env::var("NATIVE_LINK_LTO_AUDIT_BASELINE")?;
        let baseline: serde_json::Value = serde_json::from_slice(&fs::read(baseline)?)?;
        for (app, symbol) in [("bcc", "sys_enter"), ("bcc", "sys_exit"),
            ("otelcol-ebpf-profiler", "native_tracer_entry"),
            ("otelcol-ebpf-profiler", "perf_unwind_v8")] {
            let row = report["entries"].as_array().unwrap().iter().find(|r|
                r["app"] == app && r["symbol"] == symbol).unwrap();
            let command = row["kernel_replays"][0]["command"].as_array().unwrap();
            let argument = |name: &str| -> &str {
                let index = command.iter().position(|v| v == name).unwrap();
                command[index+1].as_str().unwrap()
            };
            let bytes = fs::read(argument("--input"))?;
            let elf = object::File::parse(bytes.as_slice())?;
            let entry = find_symbol_by_name(&elf, symbol)?;
            let included = discover_reachable(&elf, &entry)?;
            let facts = load_link_plan(&PathBuf::from(argument("--link-plan")))?;
            let rewrite = |show| rewrite_x86(&elf, &entry, &included,
                &facts.helper_addrs, &facts.map_addrs, &facts.lookup_maps, &facts.map_ops,
                false, false, show);
            let normal = rewrite(false)?;
            let previous = fs::read(argument("--output"))?;
            let old = baseline["programs"].as_array().unwrap().iter().find(|p|
                p["app"] == app && p["symbol"] == symbol).unwrap();
            let removed_hash_bytes = match old["appended_bytes_by_piece"].get("hash_lookup") {
                Some(bytes) => bytes.as_u64().unwrap() as usize,
                None => 0,
            };
            assert_eq!(normal.blob.len()+removed_hash_bytes, previous.len(),
                       "shared hash payload size for {app}/{symbol}");
            if removed_hash_bytes == 0 { assert_eq!(normal.blob,previous); }
            let targets: HashSet<_> = facts.lookup_maps.values().filter(|spec|
                matches!(spec.kind,LookupKind::Hash|LookupKind::LruHash|
                    LookupKind::PerCpuHash|LookupKind::HashOfMaps)).map(|spec|spec.target_addr).collect();
            let shared_calls: Vec<_> = normal.relocs.iter().filter(|r|
                r.kind==NATIVE_LAB_RELOC_HELPER_CALL_REL32 && targets.contains(&r.target))
                .map(|r|serde_json::json!({"offset":r.offset,"target":r.target})).collect();
            if removed_hash_bytes > 0 { assert!(!shared_calls.is_empty()); }
            eprintln!("native-link-lto-audit {}", serde_json::json!({
                "app": app, "symbol": symbol, "payload_bytes": normal.blob.len(),
                "reference": argument("--output"), "previous_payload_bytes":previous.len(),
                "removed_hash_bytes":removed_hash_bytes,"shared_hash_calls":shared_calls,
            }));
            let shown = rewrite(true)?;
            assert_eq!(normal.blob, shown.blob, "--show changed {app}/{symbol}");
            let relocations = |result: &RewriteResult| result.relocs.iter()
                .map(|r| (r.offset, r.kind, r.target)).collect::<Vec<_>>();
            assert_eq!(relocations(&normal), relocations(&shown));
        }
        Ok(())
    }

    #[test]
    fn clock_calls_bind_fast_target_without_changing_observed_helper_identity() -> Result<()> {
        // Cover ELF PLT/GOT calls, a hoisted GOT pointer and
        // a sibling tail jump. Address/ID observations must keep their value.
        for form in [4, 9, 41, 42, 100, 102] {
            let mut object = WriteObject::new(BinaryFormat::Elf, object::Architecture::X86_64, Endianness::Little);
            let text = object.add_section(Vec::new(), b".text".to_vec(), SectionKind::Text);
            let (mut bytes, relocation, observed) = match form {
                4 => (vec![0xe8,0,0,0,0,0xc3], Some((1,4)), None),
                102 => (vec![0xe9,0,0,0,0], Some((1,4)), None),
                100 => (vec![0x48,0x8b,0x05,0,0,0,0,0x48,0x89,0x07,0xff,0xd0,0xc3], Some((3,9)), Some(0x1234u64)),
                r => (vec![0xff,0x15,0,0,0,0,0xc3], Some((2,r)), None),
            };
            object.append_section_data(text, &bytes, 1);
            object.add_symbol(WriteSymbol { name:b"entry".to_vec(), value:0, size:bytes.len() as u64,
                kind:SymbolKind::Text, scope:SymbolScope::Linkage, weak:false,
                section:WriteSymbolSection::Section(text), flags:SymbolFlags::None });
            if let Some((offset,r_type)) = relocation {
                let symbol = object.add_symbol(WriteSymbol { name:b"bpf_ktime_get_ns".to_vec(), value:0, size:0,
                    kind:SymbolKind::Text, scope:SymbolScope::Linkage, weak:false,
                    section:WriteSymbolSection::Undefined, flags:SymbolFlags::None });
                object.add_relocation(text, WriteRelocation { offset, symbol, addend:-4,
                    flags:RelocationFlags::Elf { r_type } })?;
            }
            bytes = object.write()?;
            let elf = object::File::parse(bytes.as_slice())?;
            let entry = find_symbol_by_name(&elf, "entry")?;
            let helpers = HashMap::from([("bpf_ktime_get_ns".into(),0x1234),
                (MONO_FAST_HELPER_KEY.into(),0x5678)]);
            let rewrite = |facts: &HashMap<String,u64>| rewrite_x86(&elf,&entry,&[entry.clone()],facts,&HashMap::new(),
                &HashMap::new(),&[],false,true,false);
            let missing = HashMap::from([("bpf_ktime_get_ns".into(),0x1234)]);
            assert!(rewrite(&missing).is_err(),
                "missing clock fact cannot silently use the old wrapper");
            let mut zero = helpers.clone();zero.insert(MONO_FAST_HELPER_KEY.into(),0);
            assert!(rewrite(&zero).is_err());
            let mut unavailable = helpers.clone();unavailable.insert("bpf_ktime_get_ns".into(),0);
            assert!(rewrite(&unavailable).is_err(),"fast linkage must preserve original helper availability");
            unavailable.remove("bpf_ktime_get_ns");
            assert!(rewrite(&unavailable).is_err());
            let result = rewrite(&helpers)?;
            assert_eq!(result.relocs.len(),1,"form={form}");
            assert_eq!(result.relocs[0].target,0x5678,"form={form}");
            #[cfg(all(target_arch = "x86_64", target_os = "linux"))]
            {
                let mut code = result.blob;
                code.push(0xc3); // BPF's native-image return epilogue.
                let fast = code.len();code.extend_from_slice(&[0xb8,99,0,0,0,0xc3]);
                for relocation in result.relocs {
                    let at=relocation.offset as usize;
                    assert!(matches!(code[at],0xe8|0xe9));
                    let displacement=i32::try_from(fast as i64-at as i64-5)?;
                    code[at+1..at+5].copy_from_slice(&displacement.to_le_bytes());
                }
                let mut identity=[0u8;8];
                assert_eq!(memory::call_blob(&code,identity.as_mut_ptr(),0,0) as usize,99,"form={form}");
                if let Some(expected) = observed {
                    assert_eq!(u64::from_ne_bytes(identity),expected,"helper identity form={form}");
                }
            }
        }
        Ok(())
    }

    #[test]
    fn memory_relocations_roundtrip_proof_kernel_and_deduplicate_lengths() -> Result<()> {
        for name in ["memset", "memcpy"] {
            // Direct PLT, GOT call (all supported relaxation tags), and a
            // function pointer loaded from the GOT into r11.
            for form in [4, 9, 41, 42, 100] {
                let mut object = WriteObject::new(BinaryFormat::Elf, object::Architecture::X86_64, Endianness::Little);
                let text = object.add_section(Vec::new(), b".text".to_vec(), SectionKind::Text);
                let mut bytes = vec![0xba, 5, 0, 0, 0];
                let (call, delta, rtype) = match form {
                    4 => (vec![0xe8,0,0,0,0], 1, 4),
                    100 => (vec![0x4c,0x8b,0x1d,0,0,0,0, 0x41,0xff,0xd3], 3, 9),
                    r => (vec![0xff,0x15,0,0,0,0], 2, r),
                };
                let first = bytes.len();
                bytes.extend_from_slice(&call);
                bytes.extend_from_slice(&[0xba,5,0,0,0]);
                let second = bytes.len();
                bytes.extend_from_slice(&call);
                bytes.push(0xc3);
                object.append_section_data(text, &bytes, 1);
                object.add_symbol(WriteSymbol { name: b"entry".to_vec(), value: 0, size: bytes.len() as u64,
                    kind: SymbolKind::Text, scope: SymbolScope::Linkage, weak: false,
                    section: WriteSymbolSection::Section(text), flags: SymbolFlags::None });
                let symbol = object.add_symbol(WriteSymbol { name: name.as_bytes().to_vec(), value: 0, size: 0,
                    kind: SymbolKind::Text, scope: SymbolScope::Linkage, weak: false,
                    section: WriteSymbolSection::Undefined, flags: SymbolFlags::None });
                for start in [first, second] {
                    object.add_relocation(text, WriteRelocation { offset: (start + delta) as u64,
                        symbol, addend: -4, flags: RelocationFlags::Elf { r_type: rtype } })?;
                }
                let data = object.write()?;
                let elf = object::File::parse(data.as_slice())?;
                let entry = find_symbol_by_name(&elf, "entry")?;
                let empty = HashMap::new();
                let proof = rewrite_x86(&elf, &entry, &[entry.clone()], &empty, &empty,
                    &HashMap::new(), &[], true, true, false,)?;
                assert!(proof.proof_relocs.is_empty(), "{name}, form={form}");
                assert_eq!(proof.proof_symbols.len(), 2, "same length shares one routine");
                assert!(proof.proof_symbols[1].name.starts_with("__native_link_local_"));
                let path = std::env::temp_dir().join(format!("native-link-memory-{}-{name}-{form}.proof.o", std::process::id()));
                write_proof_object(&path, object::Architecture::X86_64, "entry", &proof.blob,
                    &proof.proof_symbols, &proof.proof_relocs, &proof.proof_data_relocs, proof.callee_saved_mask)?;
                let roundtrip = fs::read(&path)?;
                let elf = object::File::parse(roundtrip.as_slice())?;
                let entry = find_symbol_by_name(&elf, "entry")?;
                let included = discover_reachable(&elf, &entry)?;
                assert_eq!(included.len(), 2);
                let result = rewrite_x86(&elf, &entry, &included, &empty, &empty,
                    &HashMap::new(), &[], false, true, false,)?;
                assert!(result.relocs.is_empty());
                #[cfg(all(target_arch = "x86_64", target_os = "linux"))]
                {
                    let mut code = result.blob;
                    code.push(0xc3); // The kernel normally supplies this epilogue.
                    let mut dest = [0xa5; 13];
                    let source = [1u8,2,3,4,5,6,7,8,9];
                    let arg = if name == "memcpy" { source.as_ptr() as usize } else { 0x1234 };
                    let ptr = unsafe { dest.as_mut_ptr().add(4) };
                    assert_eq!(memory::call_blob(&code, ptr, arg, 99), ptr);
                    assert_eq!(&dest[..4], &[0xa5;4]);
                    assert_eq!(&dest[9..], &[0xa5;4]);
                    assert_eq!(&dest[4..9], if name == "memcpy" { &source[..5] } else { &[0x34;5] });
                }
            }
        }
        Ok(())
    }

    #[test]
    fn map_operations_follow_native_arguments_across_reordered_calls() -> Result<()> {
        // Facts are deliberately in A,B order while machine code uses B,A.
        let ops = [MapOps { name: "map_a".into(), update: 0x1000, remove: 0x2000 },
                   MapOps { name: "map_b".into(), update: 0x3000, remove: 0x4000 }];
        for form in 1..3 {
            for tail in [false, true].into_iter().filter(|tail| !tail || form == 1) {
                let mut object = WriteObject::new(BinaryFormat::Elf,
                    object::Architecture::X86_64, Endianness::Little);
                let text = object.add_section(Vec::new(), b".text".to_vec(), SectionKind::Text);
                let mut bytes = Vec::new();
                for (map, helper, id) in [("map_b", "bpf_map_update_elem", 2),
                                          ("map_a", "bpf_map_delete_elem", 3)] {
                    let symbol = object.add_symbol(WriteSymbol {
                        name: map.as_bytes().to_vec(), value: 0, size: 0,
                        kind: SymbolKind::Data, scope: SymbolScope::Linkage, weak: false,
                        section: WriteSymbolSection::Undefined, flags: SymbolFlags::None,
                    });
                    let offset = bytes.len() as u64;
                    bytes.extend_from_slice(&[0x48,0x8b,0x3d,0,0,0,0]);
                    object.add_relocation(text, WriteRelocation { offset: offset + 3,
                        symbol, addend: -4, flags: RelocationFlags::Elf { r_type: 9 } })?;
                    let jump = tail && id == 3;
                    if form == 0 {
                        bytes.extend_from_slice(&[0xb8,id,0,0,0,0xff,if jump {0xe0} else {0xd0}]);
                    } else {
                        let symbol = object.add_symbol(WriteSymbol {
                            name: helper.as_bytes().to_vec(), value: 0, size: 0,
                            kind: SymbolKind::Text, scope: SymbolScope::Linkage, weak: false,
                            section: WriteSymbolSection::Undefined, flags: SymbolFlags::None,
                        });
                        let offset = bytes.len() as u64;
                        if form == 1 { bytes.extend_from_slice(&[if jump {0xe9} else {0xe8},0,0,0,0]); }
                        else { bytes.extend_from_slice(&[0xff,if jump {0x25} else {0x15},0,0,0,0]); }
                        object.add_relocation(text, WriteRelocation {
                            offset: offset + if form == 1 {1} else {2}, symbol, addend: -4,
                            flags: RelocationFlags::Elf { r_type: if form == 1 {4} else {9} },
                        })?;
                    }
                }
                bytes.push(0xc3);
                object.append_section_data(text, &bytes, 1);
                object.add_symbol(WriteSymbol { name: b"entry".to_vec(), value: 0,
                    size: bytes.len() as u64, kind: SymbolKind::Text, scope: SymbolScope::Linkage,
                    weak: false, section: WriteSymbolSection::Section(text), flags: SymbolFlags::None });
                let encoded = object.write()?;
                let elf = object::File::parse(encoded.as_slice())?;
                let entry = find_symbol_by_name(&elf, "entry")?;
                let maps = HashMap::from([("map_a".into(),0), ("map_b".into(),0)]);
                let helpers = HashMap::from([("bpf_map_update_elem".into(),0x5000),
                    ("bpf_map_delete_elem".into(),0x6000)]);
                let output = rewrite_x86(&elf, &entry, &[entry.clone()], &helpers, &maps,
                    &HashMap::new(), &ops, false, true, false)?;
                let targets: Vec<_> = output.relocs.iter().filter(|r|
                    r.kind == NATIVE_LAB_RELOC_HELPER_CALL_REL32).map(|r| r.target).collect();
                assert_eq!(targets, vec![0x3000,0x2000], "form={form}, tail={tail}");
                let unknown = rewrite_x86(&elf, &entry, &[entry.clone()], &helpers, &maps,
                    &HashMap::new(), &[], false, true, false)?;
                let generic: Vec<_> = unknown.relocs.iter().filter(|r|
                    r.kind == NATIVE_LAB_RELOC_HELPER_CALL_REL32).map(|r| r.target).collect();
                assert_eq!(generic, vec![0x5000,0x6000], "missing facts retain generic calls");
                assert_eq!(map_op_target(&ops, Some(&"map_a_suffix".into()),
                    "bpf_map_delete_elem"), None, "a name prefix is not identity");
            }
        }
        Ok(())
    }

    #[test]
    fn runtime_map_lookup_rewrites_immediate_got_and_plt_calls() -> Result<()> {
        for form in 1..3 {
            let mut object = WriteObject::new(BinaryFormat::Elf, object::Architecture::X86_64, Endianness::Little);
            let text = object.add_section(Vec::new(), b".text".to_vec(), SectionKind::Text);
            let bytes = match form {
                // A branch enters the rewritten call: the label must stay on
                // the helper slot's first byte so the branch keeps calling it.
                1 => vec![0xeb, 2, 0x90, 0x90, 0xff, 0x15, 0, 0, 0, 0, 0xc3],
                _ => vec![0xe8, 0, 0, 0, 0, 0xc3],
            };
            object.append_section_data(text, &bytes, 1);
            object.add_symbol(WriteSymbol {
                name: b"entry".to_vec(), value: 0, size: bytes.len() as u64,
                kind: SymbolKind::Text, scope: SymbolScope::Linkage, weak: false,
                section: WriteSymbolSection::Section(text), flags: SymbolFlags::None,
            });
            if form != 0 {
                let helper = object.add_symbol(WriteSymbol {
                    name: b"bpf_map_lookup_elem".to_vec(), value: 0, size: 0,
                    kind: SymbolKind::Text, scope: SymbolScope::Linkage, weak: false,
                    section: WriteSymbolSection::Undefined, flags: SymbolFlags::None,
                });
                object.add_relocation(text, WriteRelocation {
                    offset: if form == 1 { 6 } else { 1 }, symbol: helper, addend: -4,
                    flags: RelocationFlags::Elf { r_type: if form == 1 { 9 } else { 4 } },
                })?;
            }
            let encoded = object.write()?;
            let elf = object::File::parse(encoded.as_slice())?;
            let entry = find_symbol_by_name(&elf, "entry")?;
            let helpers = HashMap::from([("bpf_map_lookup_elem".to_owned(), 0x1234)]);
            let result = rewrite_x86(&elf, &entry, &[entry.clone()], &helpers,
                &HashMap::new(), &HashMap::new(), &[], false, false, false)?;
            let targets: Vec<_> = result.relocs.iter().filter(|r|
                r.kind == NATIVE_LAB_RELOC_HELPER_CALL_REL32).map(|r| r.target).collect();
            assert_eq!(targets, vec![0x1234], "form={form}: actual helper target");
        }
        Ok(())
    }

    #[test]
    fn dynamic_map_lookup_requires_the_actual_helper() -> Result<()> {
        for name in [None, Some("outer")] {
            let (_, spec) = select_lookup_site(&HashMap::new(), 0, name, "entry", 0x1234)?;
            assert_eq!(spec.kind, LookupKind::Call);
            assert_eq!(spec.target_addr, 0x1234);
            assert_eq!(spec.key_offset, 0);
            assert!(select_lookup_site(&HashMap::new(), 0, name, "entry", 0).is_err(),
                "a missing helper must not produce a guessed map type");
        }
        Ok(())
    }

    #[test]
    fn runtime_known_maps_use_only_exact_named_map_facts() -> Result<()> {
        let array = LookupSiteSpec {
            kind: LookupKind::Array, target_addr: 0, key_offset: 0,
            max_entries: 8, elem_size: 8, index_mask: 7, value_offset: 32,
            percpu_base_addr: 0,
        };
        let mut maps = HashMap::from([("known_map".into(), array.clone())]);
        for kind in [LookupKind::Array, LookupKind::PerCpuArray, LookupKind::Hash,
                     LookupKind::LruHash, LookupKind::PerCpuHash,
                     LookupKind::Call, LookupKind::HashOfMaps] {
            maps.get_mut("known_map").unwrap().kind = kind;
            maps.get_mut("known_map").unwrap().target_addr = 0x5678;
            for name in [None, Some("unknown"), Some("known_map")] {
                let (_, spec) = select_lookup_site(&maps, 0, name, "entry", 0x1234)?;
                let specialized = name == Some("known_map");
                assert_eq!(spec.kind, if specialized { kind } else { LookupKind::Call });
                assert_eq!(spec.target_addr, if specialized { 0x5678 } else { 0x1234 });
            }
        }
        maps.clear();
        maps.insert("0123456789abcde_A".into(), array);
        let (_, spec) = select_lookup_site(&maps, 0,
            Some("0123456789abcde_B"), "entry", 0x1234)?;
        assert_eq!(spec.kind, LookupKind::Call, "truncation is not map identity");
        Ok(())
    }

    #[test]
    #[cfg(all(target_arch = "x86_64", target_os = "linux"))]
    fn compact_lru_operands_preserve_signed_offsets_flags_and_live_reference() -> Result<()> {
        // Compare actual addressing/flag semantics with the original disp32 form.
        for disp in [0u32,1,35,127,128,0x7fff_ffff,0x8000_0000,
                     0xffff_ff7f,0xffff_ff80,u32::MAX] {
            for (opcode,reg_bits) in [(0x80,0x38),(0xc6,0)] {
                for imm in [0u8,1,0xff] {
                    let mut wide=vec![opcode,0x80|reg_bits];
                    wide.extend_from_slice(&disp.to_le_bytes());wide.push(imm);
                    let mut compact=Vec::new();
                    append_x86_byte_rax_imm(&mut compact,opcode,reg_bits,disp,imm);
                    let mut a=Decoder::new(64,&wide,DecoderOptions::NONE);
                    let mut b=Decoder::new(64,&compact,DecoderOptions::NONE);
                    let before=a.decode();let after=b.decode();
                    assert!(!after.is_invalid());
                    assert_eq!((before.code(),before.memory_base(),before.memory_displacement64(),before.immediate8()),
                               (after.code(),after.memory_base(),after.memory_displacement64(),after.immediate8()));
                    assert_eq!((before.rflags_read(),before.rflags_written(),before.rflags_undefined()),
                               (after.rflags_read(),after.rflags_written(),after.rflags_undefined()));
                    let expected=if disp==0 {3}else if i8::try_from(disp as i32).is_ok() {4}else{7};
                    assert_eq!(compact.len(),expected);assert_eq!(after.len(),compact.len());
                }
            }
        }
        for offset in [-128i32,-1,0,1,35,127,128,255] {
            let spec=LookupSiteSpec{kind:LookupKind::LruHash,target_addr:0x5678,key_offset:24,
                max_entries:0,elem_size:0,index_mask:0,value_offset:offset as u32,percpu_base_addr:0};
            let instructions=build_x86_lookup_call_postprocess(&spec)?;
            let post=BlockEncoder::encode(64,InstructionBlock::new(&instructions,0),BlockEncoderOptions::NONE)?.code_buffer;
            if offset==35 {assert_eq!(post.len(),19,"prior same-shape postprocess was25B");}
            if let Some(out)=std::env::var_os("NATIVE_LINK_PROBE_TEST_OUTPUT") {
                fs::write(std::path::Path::new(&out).join(format!("lru-ref{offset}.post.bin")),&post)?;
            }
            let mut code=vec![0x48,0x89,0xf8];code.extend_from_slice(&post);code.push(0xc3);
            for reference in [0u8,1,2,0xff] {
                assert!(memory::call_blob(&code,std::ptr::null_mut(),0,0).is_null());
                let mut node=vec![0xa5u8;768];let index=(256+offset) as usize;
                node[index]=reference;
                let mut expected=node.clone();expected[index]=if reference==0 {1}else{reference};
                let ptr=node.as_mut_ptr().wrapping_add(256);
                assert_eq!(memory::call_blob(&code,ptr,0,0),ptr.wrapping_add(24));
                assert_eq!(node,expected,"offset={offset} initial ref={reference}");
                assert_eq!(memory::call_blob(&code,ptr,0,0),ptr.wrapping_add(24));
                assert_eq!(node,expected,"existing ref must stay unchanged");
            }
        }
        println!("LRU ref:60 operand decodes and32 null/state/idempotence cases PASS");
        Ok(())
    }

    #[test]
    #[cfg(all(target_arch = "x86_64", target_os = "linux"))]
    fn typed_hash_postprocess_preserves_null_value_pointer_and_lru_reference() -> Result<()> {
        unsafe extern "C" {
            fn mmap(address: *mut std::ffi::c_void, length: usize, protection: i32,
                    flags: i32, fd: i32, offset: i64) -> *mut std::ffi::c_void;
            fn mprotect(address: *mut std::ffi::c_void, length: usize, protection: i32) -> i32;
            fn munmap(address: *mut std::ffi::c_void, length: usize) -> i32;
        }
        for kind in [LookupKind::Hash, LookupKind::LruHash, LookupKind::HashOfMaps] {
            let spec = LookupSiteSpec { kind, target_addr: 0x5678, key_offset: 24,
                max_entries: 0, elem_size: 0, index_mask: 0, value_offset: 8,
                percpu_base_addr: 0 };
            let instructions = build_x86_lookup_call_postprocess(&spec)?;
            let post = BlockEncoder::encode(64, InstructionBlock::new(&instructions, 0),
                                             BlockEncoderOptions::NONE)?.code_buffer;
            let mut code = vec![0x48,0x89,0xf8]; // Actual helper return pointer -> RAX.
            code.extend_from_slice(&post);
            code.push(0xc3);
            let inner = [0u64; 2];
            let mut node = [0u64; 8];
            node[3] = inner.as_ptr() as u64;
            unsafe {
                let memory = mmap(std::ptr::null_mut(), 4096, 3, 0x22, -1, 0);
                assert_ne!(memory as isize, -1);
                std::ptr::copy_nonoverlapping(code.as_ptr(), memory.cast(), code.len());
                assert_eq!(mprotect(memory, 4096, 5), 0);
                let postprocess: unsafe extern "C" fn(*mut u64) -> u64 = std::mem::transmute(memory);
                assert_eq!(postprocess(std::ptr::null_mut()), 0, "{kind:?} miss must remain null");
                let pointer = postprocess(node.as_mut_ptr());
                let expected = if kind == LookupKind::HashOfMaps { inner.as_ptr() as u64 }
                               else { node.as_ptr() as u64 + 24 };
                assert_eq!(pointer, expected, "{kind:?} must return value, not hash node/key");
                let mut expected_node = [0u64; 8];
                expected_node[3] = inner.as_ptr() as u64;
                if kind == LookupKind::LruHash { expected_node[1] = 1; }
                assert_eq!(node, expected_node, "only LRU ref byte may change");
                assert_eq!(postprocess(node.as_mut_ptr()), expected);
                assert_eq!(node, expected_node, "existing LRU ref stays set");
                if kind == LookupKind::LruHash {
                    // A nonzero ref requires no store, even of the same value.
                    let readonly = mmap(std::ptr::null_mut(),4096,3,0x22,-1,0);
                    assert_ne!(readonly as isize,-1);
                    std::ptr::copy_nonoverlapping(expected_node.as_ptr(),readonly.cast(),expected_node.len());
                    assert_eq!(mprotect(readonly,4096,1),0);
                    assert_eq!(postprocess(readonly.cast()),readonly as u64+24);
                    assert_eq!(munmap(readonly,4096),0);
                }
                assert_eq!(munmap(memory, 4096), 0);
            }
        }
        Ok(())
    }

    #[test]
    #[cfg(all(target_arch = "x86_64", target_os = "linux"))]
    fn known_array_arithmetic_preserves_wide_products_and_displacement_signs() -> Result<()> {
        // Catch an accidental EAX multiply, sign-extended imm8 at stride 128,
        // or a changed displacement when ADDs become one LEA.
        for stride in [1, 2, 4, 8, 16, 24, 63, 127, 128, 129, 255, 256,
                       4096, 0x7fff_ffff, 0x4000_0000] {
            for offset in [0, 1, 127, 128, 304, 0x7fff_ffff, 0x8000_0000, u32::MAX] {
                let mut code = vec![0x48, 0x89, 0xf0]; // mov rax, rsi
                append_x86_array_value_ptr(&mut code, stride, offset)?;
                code.push(0xc3);
                for index in [0u32, 1, 3, 0x7fff_ffff, u32::MAX] {
                    let base = 0x1234_5678_9000usize;
                    let expected = (base as u64)
                        .wrapping_add(u64::from(index) * u64::from(stride))
                        .wrapping_add(offset as i32 as i64 as u64);
                    assert_eq!(memory::call_blob(&code, base as *mut u8, index as usize, 0) as u64,
                        expected, "stride={stride} offset={offset} index={index}");
                }
            }
        }
        for (stride, offset, expected_len) in [(24, 304, 12), (24, 127, 9),
                (24, 0, 7), (127, 304, 12), (129, 304, 15), (16, 304, 12)] {
            let mut code = Vec::new();
            append_x86_array_value_ptr(&mut code, stride, offset)?;
            assert_eq!(code.len(), expected_len, "stride={stride} offset={offset}");
            let mut decoder = Decoder::new(64, &code, DecoderOptions::NONE);
            let mut instructions = Vec::new();
            while decoder.can_decode() {
                let insn = decoder.decode();
                assert!(!insn.is_invalid());
                assert_eq!(insn.op0_register(), Register::RAX);
                instructions.push(insn);
            }
            assert_eq!(instructions.len(), 2);
            if stride == 24 && offset == 304 {
                assert_eq!(code, [0x48, 0x6b, 0xc0, 24, 0x48, 0x8d, 0x84, 0x07, 0x30, 1, 0, 0]);
                if let Some(out) = std::env::var_os("NATIVE_LINK_PROBE_TEST_OUTPUT") {
                    fs::write(std::path::Path::new(&out).join("array-stride24-offset304.bin"), &code)?;
                }
            }
        }
        // Exercise the complete lookup around its existing unsigned bounds.
        for max_entries in [3, 4096] {
            let spec = LookupSiteSpec { kind: LookupKind::Array, target_addr: 0,
                key_offset: 0, max_entries, elem_size: 24, index_mask: max_entries.next_power_of_two()-1,
                value_offset: 304, percpu_base_addr: 0 };
            let code = build_x86_array_lookup_routine(&spec)?;
            let instructions:Vec<_>=Decoder::new(64,&code,DecoderOptions::NONE).into_iter().collect();
            assert!(instructions.iter().all(|i|!i.is_invalid()
                && i.flow_control()!=FlowControl::UnconditionalBranch),"no shared-return jump");
            assert_eq!(instructions.iter().filter(|i|i.mnemonic()==Mnemonic::Ret).count(),2);
            if let Some(out)=std::env::var_os("NATIVE_LINK_PROBE_TEST_OUTPUT") {
                std::fs::write(std::path::Path::new(&out).join(format!("known-array-max{max_entries}.bin")),&code)?;
            }
            let mut map = vec![0u8; 304 + max_entries as usize * 24];
            for key in [0, 1, max_entries-1, max_entries, u32::MAX] {
                let actual = memory::call_blob(&code, map.as_mut_ptr(), &key as *const _ as usize, 0);
                let expected = if key < max_entries { map.as_mut_ptr().wrapping_add(304 + key as usize*24) }
                    else { std::ptr::null_mut() };
                assert_eq!(actual, expected, "stride24 bounds max={max_entries} key={key}");
            }
        }
        Ok(())
    }

    #[test]
    #[cfg(all(target_arch = "x86_64", target_os = "linux"))]
    fn shared_known_arrays_preserve_shapes_keys_bounds_and_call_returns() -> Result<()> {
        let spec = LookupSiteSpec { kind: LookupKind::Array, target_addr: 0,
            key_offset: 0, max_entries: 3, elem_size: 8, index_mask: 3,
            value_offset: 32, percpu_base_addr: 0 };
        let first = build_x86_array_lookup_routine(&spec)?;
        let mut other = spec.clone();
        other.value_offset = 64;
        let last = build_x86_array_lookup_routine(&other)?;
        let mut blob = X86_HELPER_CALL_REL32_SLOT.repeat(3);
        blob.push(0xc3);
        let patches = vec![
            PatchInfo { global_offset: 0, kind: PatchKind::LocalArray { bytes: first.clone() } },
            PatchInfo { global_offset: 5, kind: PatchKind::LocalArray { bytes: first } },
            PatchInfo { global_offset: 10, kind: PatchKind::LocalArray { bytes: last } },
        ];
        let mut ranges = Vec::new();
        share_x86_array_routines(&mut blob, &patches, &mut ranges, false)?;
        let targets: Vec<_> = [0,5,10].into_iter().map(|at| at + 5 +
            i32::from_le_bytes(blob[at as usize+1..at as usize+5].try_into().unwrap())).collect();
        assert_eq!(ranges.len(), 2, "equal bodies share once; value offsets cannot merge");
        assert_eq!(targets[0], targets[1]);
        assert_ne!(targets[0], targets[2]);
        assert_eq!(targets[0] as usize, ranges[0].0);
        assert_eq!(targets[2] as usize, ranges[1].0);
        let mut map = [0u8;128];
        for key in [0u32,1,2,3,u32::MAX] {
            let actual = memory::call_blob(&blob, map.as_mut_ptr(), &key as *const _ as usize, 0);
            let expected = if key < 3 { map.as_mut_ptr().wrapping_add(64 + key as usize*8) }
                           else { std::ptr::null_mut() };
            assert_eq!(actual, expected, "shared call/return and last shape for key {key}");
        }
        let mut per_cpu = spec;
        per_cpu.kind = LookupKind::PerCpuArray;
        per_cpu.percpu_base_addr = 0x1000;
        let a = build_x86_array_lookup_routine(&per_cpu)?;
        per_cpu.percpu_base_addr = 0x2000;
        assert_ne!(a, build_x86_array_lookup_routine(&per_cpu)?,
                   "different CPU offsets cannot share a body");
        Ok(())
    }

    #[test]
    #[cfg(all(target_arch = "x86_64", target_os = "linux"))]
    fn runtime_known_array_executes_real_keys_and_bounds() -> Result<()> {
        use object::write::{Object as WriteObject, Relocation as WriteRelocation,
            Symbol as WriteSymbol, SymbolSection as WriteSymbolSection};
        use object::{BinaryFormat, Endianness, SectionKind, SymbolFlags, SymbolKind, SymbolScope};
        let mut object = WriteObject::new(BinaryFormat::Elf, object::Architecture::X86_64, Endianness::Little);
        let text = object.add_section(Vec::new(), b".text".to_vec(), SectionKind::Text);
        // Native entry takes the key pointer; RDI then gets the actual named map.
        let bytes = [0x48,0x89,0xfe, 0x48,0x8b,0x3d,0,0,0,0,
                     0xe8,0,0,0,0, 0xc3];
        object.append_section_data(text, &bytes, 1);
        object.add_symbol(WriteSymbol { name: b"entry".to_vec(), value: 0, size: bytes.len() as u64,
            kind: SymbolKind::Text, scope: SymbolScope::Linkage, weak: false,
            section: WriteSymbolSection::Section(text), flags: SymbolFlags::None });
        let map = object.add_symbol(WriteSymbol { name: b"known_map".to_vec(), value: 0, size: 0,
            kind: SymbolKind::Data, scope: SymbolScope::Linkage, weak: false,
            section: WriteSymbolSection::Undefined, flags: SymbolFlags::None });
        object.add_relocation(text, WriteRelocation { offset: 6, symbol: map, addend: -4,
            flags: RelocationFlags::Elf { r_type: 9 } })?;
        let lookup = object.add_symbol(WriteSymbol { name: b"bpf_map_lookup_elem".to_vec(), value: 0, size: 0,
            kind: SymbolKind::Text, scope: SymbolScope::Linkage, weak: false,
            section: WriteSymbolSection::Undefined, flags: SymbolFlags::None });
        object.add_relocation(text, WriteRelocation { offset: 11, symbol: lookup, addend: -4,
            flags: RelocationFlags::Elf { r_type: 4 } })?;
        let encoded = object.write()?;
        let elf = object::File::parse(encoded.as_slice())?;
        let entry = find_symbol_by_name(&elf, "entry")?;
        let array = [0u64; 16];
        let maps = HashMap::from([("known_map".into(), array.as_ptr() as u64)]);
        let helpers = HashMap::from([("bpf_map_lookup_elem".into(), 0x1234)]);
        let facts = HashMap::from([("known_map".into(), LookupSiteSpec {
            kind: LookupKind::Array, target_addr: 0, key_offset: 0, max_entries: 3,
            elem_size: 8, index_mask: 3, value_offset: 32, percpu_base_addr: 0,
        })]);
        {
            let output = rewrite_x86(&elf, &entry, &[entry.clone()], &helpers, &maps, &facts, &[], false, false, false)?;
            assert!(output.relocs.is_empty(), "known array must avoid generic helper");
            assert_eq!(output.map_patches.len(), 1);
            let mut code = output.blob;
            for patch in output.map_patches {
                code[patch.offset..patch.offset + 8].copy_from_slice(&maps[&patch.name].to_le_bytes());
            }
            code.push(0xc3); // Stand in for the kernel's return epilogue.
            unsafe extern "C" {
                fn mmap(address: *mut std::ffi::c_void, length: usize, protection: i32,
                        flags: i32, fd: i32, offset: i64) -> *mut std::ffi::c_void;
                fn mprotect(address: *mut std::ffi::c_void, length: usize, protection: i32) -> i32;
                fn munmap(address: *mut std::ffi::c_void, length: usize) -> i32;
            }
            unsafe {
                let memory = mmap(std::ptr::null_mut(), 4096, 3, 0x22, -1, 0);
                assert_ne!(memory as isize, -1);
                std::ptr::copy_nonoverlapping(code.as_ptr(), memory.cast(), code.len());
                assert_eq!(mprotect(memory, 4096, 5), 0);
                let lookup: unsafe extern "C" fn(*const u32) -> u64 = std::mem::transmute(memory);
                for key in [0u32, 1, 2, 3, u32::MAX] {
                    let expected = if key < 3 { array.as_ptr() as u64 + 32 + u64::from(key) * 8 } else { 0 };
                    assert_eq!(lookup(&key), expected, "key={key}");
                }
                assert_eq!(munmap(memory, 4096), 0);
            }
        }
        // A complete map-ops call is also a named binding: the named
        // target must replace the generic lookup helper, not the reverse.
        let mut facts = facts;
        let spec = facts.get_mut("known_map").unwrap();
        spec.kind = LookupKind::Call;
        spec.target_addr = 0x5678;
        let output = rewrite_x86(&elf, &entry, &[entry.clone()], &helpers, &maps,
            &facts, &[], false, false, false)?;
        assert_eq!(output.relocs.len(), 1);
        assert_eq!(output.relocs[0].target, 0x5678,
                   "named operation must bypass the generic lookup helper");
        Ok(())
    }

    #[test]
    fn tail_count_patch_preserves_target_entry() -> Result<()> {
        let mut cases=0;
        for (bound,function,entry_offset) in [(68u64,72u64,12u64),(4096,4096,4096),(0,0,0)] {
            let helpers = HashMap::from([
                (X86_BPF_MAP_MAX_ENTRIES_OFFSET_KEY.to_owned(), bound),
                (X86_BPF_ARRAY_PTRS_OFFSET_KEY.to_owned(), 304),
                (X86_BPF_PROG_BPF_FUNC_OFFSET_KEY.to_owned(), function),
                (X86_TAIL_CALL_OFFSET_KEY.to_owned(), entry_offset),
            ]);
            for (saved_frame,live_rbp) in [(Some(64),false),(None,true)] {
                for cleanup in [Vec::new(),vec![0x90;192]] {for mask in [0,15] {
                    let (stub,field)=build_x86_tail_call_inline(&helpers,mask,&cleanup,saved_frame,live_rbp)?;
                    let mut bytes=BlockEncoder::encode(64,InstructionBlock::new(&stub,0),BlockEncoderOptions::NONE)?.code_buffer;
                    assert_eq!(&bytes[field..field+4],&(-16i32).to_le_bytes(),"counter slot before kernel patch");
                    bytes[field..field+4].copy_from_slice(&(-32i32).to_le_bytes());
                    let decoded=decode_x86(&bytes)?;
                    let branches:Vec<_>=decoded.iter().filter(|i|i.is_jcc_short_or_near()).collect();
                    assert_eq!(branches.len(),3,"all live bounds/count/null tests retained");
                    assert!(branches.iter().all(|i|i.near_branch_target()==bytes.len() as u64),"common miss target");
                    if cleanup.is_empty() {assert!(branches.iter().all(|i|i.len()==2),"opaque tail branches should fit rel8");}
                    else {assert!(branches.iter().any(|i|i.len()==6),"long cleanup must keep a near branch");}
                    let entry=decoded.iter().find(|i|i.mnemonic()==Mnemonic::Add && i.op0_register()==Register::RCX).expect("tail entry add");
                    let value=if entry.op1_kind()==OpKind::Immediate8to64 {entry.immediate8to64()}else{entry.immediate32to64()};
                    assert_eq!(value,entry_offset as i64,"counter patch must not redirect the tail jump");
                    let load=decoded.iter().find(|i|i.mnemonic()==Mnemonic::Mov && i.op0_register()==Register::RAX
                        && i.memory_base()==if live_rbp {Register::RBP}else{Register::RAX}).expect("counter pointer load");
                    assert_eq!(load.memory_displacement64() as i64,-32);
                    let mut decoder=Decoder::new(64,&bytes[load.ip() as usize..],DecoderOptions::NONE);
                    let instruction=decoder.decode();
                    let offsets=decoder.get_constant_offsets(&instruction);
                    assert_eq!(offsets.displacement_size(),4,"kind10 always patches four bytes");
                    assert_eq!(load.ip() as usize+offsets.displacement_offset(),field,"counter offset follows branch sizing");
                    cases+=1;
                }}
            }
        }
        println!("tail encodings: {cases} narrow/wide/zero layouts, saved/live frames, masks and short/long cleanup cases PASS");
        Ok(())
    }

    #[test]
    #[cfg(all(target_arch="x86_64",target_os="linux"))]
    fn branches_enter_direct_loads_and_tail_stubs_at_the_original_call_label() -> Result<()> {
        let helpers=HashMap::from([("bpf_jiffies64".into(),0x2000),
            (X86_BPF_MAP_MAX_ENTRIES_OFFSET_KEY.into(),68),
            (X86_BPF_ARRAY_PTRS_OFFSET_KEY.into(),304),
            (X86_BPF_PROG_BPF_FUNC_OFFSET_KEY.into(),72),
            (X86_TAIL_CALL_OFFSET_KEY.into(),12)]);
        let mut cases=0;
        for (name,tail) in [("bpf_jiffies64",false),("bpf_tail_call",true)] {
            for named in [true] { for base in [0usize,32] { for skip_nop in [0u8,1] {
                let mut bytes=vec![];
                bytes.extend_from_slice(&[0x85,0xff,0x74,skip_nop,0x90]);
                let call=bytes.len();
                bytes.extend_from_slice(if named {&[0xe8,0,0,0,0][..]} else {&[0xff,0xd0][..]});
                if tail {bytes.extend_from_slice(&[0x48,0x89,0xd0]);}
                bytes.push(0xc3);
                let mut object=WriteObject::new(BinaryFormat::Elf,object::Architecture::X86_64,Endianness::Little);
                let text=object.add_section(Vec::new(),b".text".to_vec(),SectionKind::Text);
                object.append_section_data(text,&vec![0x90;base],1);
                object.append_section_data(text,&bytes,1);
                object.add_symbol(WriteSymbol{name:b"entry".to_vec(),value:base as u64,size:bytes.len() as u64,
                    kind:SymbolKind::Text,scope:SymbolScope::Linkage,weak:false,
                    section:WriteSymbolSection::Section(text),flags:SymbolFlags::None});
                if named {
                    let helper=object.add_symbol(WriteSymbol{name:name.as_bytes().to_vec(),value:0,size:0,
                        kind:SymbolKind::Text,scope:SymbolScope::Linkage,weak:false,
                        section:WriteSymbolSection::Undefined,flags:SymbolFlags::None});
                    object.add_relocation(text,WriteRelocation{offset:(base+call+1) as u64,symbol:helper,addend:-4,
                        flags:RelocationFlags::Elf{r_type:4}})?;
                }
                let encoded=object.write()?;let elf=object::File::parse(encoded.as_slice())?;
                let entry=find_symbol_by_name(&elf,"entry")?;
                let output=rewrite_x86(&elf,&entry,&[entry.clone()],&helpers,&HashMap::new(),&HashMap::new(),
                    &[],false,false,false)?;
                let branch=decode_x86(&output.blob)?.into_iter().find(|i|i.is_jcc_short_or_near()).unwrap();
                let target=branch.near_branch_target() as usize;
                // A miss path keeps the original call label: the rewritten
                // helper slot, or the inline tail stub's first instruction.
                let marker=if tail {&[0x89,0xd2][..]} else {&[0xe8,0,0,0,0][..]};
                assert_eq!(output.blob.get(target..target+marker.len()),Some(marker),
                    "branch skipped {name}: named={named} base={base} nop={skip_nop}");
                assert_eq!(output.relocs.len(),1);
                assert_eq!(output.relocs[0].kind,if tail {NATIVE_LAB_RELOC_X86_TAIL_COUNT}
                    else {NATIVE_LAB_RELOC_HELPER_CALL_REL32});
                if tail {
                    let mut blob=output.blob;blob.push(0xc3);
                    let mut map=[0u8;72];
                    for selector in [0usize,1] {
                        let actual=memory::call_blob(&blob,selector as *mut u8,map.as_mut_ptr() as usize,
                            0x100000001) as u64;
                        assert_eq!(actual,1,"{name} selector={selector}");cases+=1;
                    }
                }
            } } }
        }
        println!("inline helper labels: {cases} branch/fallthrough/tail-miss executions PASS");
        Ok(())
    }

    #[test]
    fn kernel_tail_calls_always_relocate_the_counter_frame() -> Result<()> {
        // An omitted kind-10 relocation leaves the frozen frame displacement
        // in an otherwise valid tail stub. Check production ELF rewriting,
        // including the final offset after chunk emission and branch encoding.
        for immediate in [false] {
            let mut object = WriteObject::new(BinaryFormat::Elf,
                object::Architecture::X86_64, Endianness::Little);
            let text = object.add_section(Vec::new(), b".text".to_vec(), SectionKind::Text);
            let bytes = if immediate {
                vec![0xb8, 12, 0, 0, 0, 0xff, 0xd0, 0xc3]
            } else {
                vec![0xe8, 0, 0, 0, 0, 0xc3]
            };
            object.append_section_data(text, &bytes, 1);
            object.add_symbol(WriteSymbol {
                name: b"entry".to_vec(), value: 0, size: bytes.len() as u64,
                kind: SymbolKind::Text, scope: SymbolScope::Linkage, weak: false,
                section: WriteSymbolSection::Section(text), flags: SymbolFlags::None,
            });
            if !immediate {
                let helper = object.add_symbol(WriteSymbol {
                    name: b"bpf_tail_call".to_vec(), value: 0, size: 0,
                    kind: SymbolKind::Text, scope: SymbolScope::Linkage, weak: false,
                    section: WriteSymbolSection::Undefined, flags: SymbolFlags::None,
                });
                object.add_relocation(text, WriteRelocation {
                    offset: 1, symbol: helper, addend: -4,
                    flags: RelocationFlags::Elf { r_type: 4 },
                })?;
            }
            let encoded = object.write()?;
            let elf = object::File::parse(encoded.as_slice())?;
            let entry = find_symbol_by_name(&elf, "entry")?;
            let helpers = HashMap::from([
                (X86_BPF_MAP_MAX_ENTRIES_OFFSET_KEY.to_owned(), 68),
                (X86_BPF_ARRAY_PTRS_OFFSET_KEY.to_owned(), 304),
                (X86_BPF_PROG_BPF_FUNC_OFFSET_KEY.to_owned(), 72),
                (X86_TAIL_CALL_OFFSET_KEY.to_owned(), 12),
            ]);
            let output = rewrite_x86(&elf, &entry, &[entry.clone()], &helpers,
                &HashMap::new(), &HashMap::new(), &[], false, false, false,)?;
            assert_eq!(output.relocs.len(), 1, "immediate={immediate}");
            assert_eq!(output.callee_saved_mask, 0);
            let relocation = output.relocs[0];
            assert_eq!(relocation.kind, NATIVE_LAB_RELOC_X86_TAIL_COUNT);
            assert_eq!(relocation.target, 0);
            let offset = relocation.offset as usize;
            assert_eq!(&output.blob[offset - 3..offset], &[0x48, 0x8b, 0x85]);
            assert_eq!(&output.blob[offset..offset + 4], &(-16i32).to_le_bytes());
            let mut patched = output.blob;
            patched[offset..offset + 4].copy_from_slice(&(-32i32).to_le_bytes());
            let decoded = decode_x86(&patched)?;
            assert!(!decoded.iter().any(|i| i.mnemonic() == Mnemonic::Pop
                && matches!(i.op0_register(), Register::RBX | Register::R13 |
                    Register::R14 | Register::R15)), "tail pops must match the image mask");
            assert!(decoded.iter().any(|i| i.mnemonic() == Mnemonic::Mov
                && i.op0_register() == Register::RAX && i.memory_base() == Register::RBP
                && i.memory_displacement64() as i64 == -32));
            assert!(decoded.iter().any(|i| i.mnemonic() == Mnemonic::Add
                && i.op0_register() == Register::RCX
                && (if i.op1_kind()==OpKind::Immediate8to64 {i.immediate8to64()}else{i.immediate32to64()}) == 12));
        }
        Ok(())
    }

    /// The tail-count field has to be found inside the chunked stub, and the
    /// chunk a synthetic reports cannot be used for that: a synthetic advances
    /// its IP by one whatever its width. This pins the arithmetic the emission
    /// relies on, against the stub's own layout.
    #[test]
    fn tail_count_field_maps_to_its_chunk_in_the_stub() {
        let bytes: Vec<u8> = (0..40u8).collect();
        let chunks = declared_byte_chunks(&bytes).expect("chunk");
        assert_eq!(chunks.len(), 3, "40 bytes is three 16-byte chunks");
        for field in [0usize, 3, 15, 16, 17, 31, 32, 39] {
            let chunk = field / 16;
            let delta = field % 16;
            assert!(chunk < chunks.len(), "field {field} must have a chunk");
            // The byte the module would write is the field's own byte.
            assert_eq!(chunk * 16 + delta, field);
            // And that byte is inside the chunk it names.
            let width = bytes.len().saturating_sub(chunk * 16).min(16);
            assert!(delta < width, "field {field} delta {delta} outside {width}");
        }
    }

    #[test]
    fn load_sites_exclude_stores_and_literal_pool_bytes() {
        let bytes = [0x48, 0x8b, 0x07, 0x48, 0x89, 0x07, 0xc3, 0x48, 0x8b, 0x1f];
        let sites = x86_decoded_load_sites(&bytes, &[(0, 7)]);
        let rows: Vec<_> = sites.iter().map(|s| (s.offset, s.insn_len, s.destination)).collect();
        assert_eq!(rows, vec![(0, 3, 0), (6, 1, u16::MAX)]);
    }

    #[test]
    fn proof_entry_abi_preserves_native_saves_only_when_requested() -> Result<()> {
        let mut object = WriteObject::new(BinaryFormat::Elf, object::Architecture::X86_64, Endianness::Little);
        let section = object.add_section(Vec::new(), b".text".to_vec(), SectionKind::Text);
        let bytes = [0x53, 0x31, 0xc0, 0x5b, 0xc3]; // push rbx; xor eax,eax; pop rbx; ret
        object.append_section_data(section, &bytes, 1);
        object.add_symbol(WriteSymbol {
            name: b"entry".to_vec(), value: 0, size: bytes.len() as u64,
            kind: SymbolKind::Text, scope: SymbolScope::Linkage, weak: false,
            section: WriteSymbolSection::Section(section), flags: SymbolFlags::None,
        });
        let encoded = object.write()?;
        let elf = object::File::parse(encoded.as_slice())?;
        let entry = find_symbol_by_name(&elf, "entry")?;
        for preserve in [false, true] {
            let output = rewrite_x86(&elf, &entry, &[entry.clone()], &HashMap::new(),
                &HashMap::new(), &HashMap::new(), &[], true, preserve, false,)?;
            let mut expected = if preserve { vec![0x53, 0x31, 0xc0, 0x5b] } else { vec![0x31, 0xc0] };
            expected.extend_from_slice(&[0xe9, 0, 0, 0, 0]); // Canonical entry exit in proof mode.
            assert_eq!(output.blob, expected);
            assert_eq!(output.callee_saved_mask, if preserve { 0 } else { 1 });
        }
        Ok(())
    }

    #[test]
    #[cfg(target_arch = "x86_64")]
    fn frame_pointer_tail_cleanup_recovers_original_bpf_frame_and_restores_stack() -> Result<()> {
        // Regression for push rbp; mov rbp,rsp; more saves; sub rsp,216.
        // The old prefix scan stopped at MOV and read [rsp+0] as BPF RBP.
        // Exercise the production slot and cleanup in executable code, with
        // a sentinel at the same negative offset used by tail-count recovery.
        unsafe extern "C" {
            fn mmap(address: *mut std::ffi::c_void, length: usize, protection: i32,
                flags: i32, fd: i32, offset: i64) -> *mut std::ffi::c_void;
            fn mprotect(address: *mut std::ffi::c_void, length: usize, protection: i32) -> i32;
            fn munmap(address: *mut std::ffi::c_void, length: usize) -> i32;
        }
        for cet in [false, true] {
            for more_saves in [false, true] {
                for allocation in [0u32, 216, 408] {
                    for epilogue in 0..3 {
                        let mut prefix = Vec::new();
                        if cet { prefix.extend_from_slice(&[0xf3,0x0f,0x1e,0xfa]); }
                        prefix.extend_from_slice(&[0x55,0x48,0x89,0xe5]);
                        if more_saves { prefix.extend_from_slice(&[0x41,0x57,0x41,0x56,0x41,0x55,0x41,0x54,0x53]); }
                        if allocation != 0 {
                            prefix.extend_from_slice(&[0x48,0x81,0xec]);
                            prefix.extend_from_slice(&allocation.to_le_bytes());
                        }
                        let mut cleanup = Vec::new();
                        if allocation != 0 {
                            cleanup.extend_from_slice(&[0x48,0x81,0xc4]);
                            cleanup.extend_from_slice(&allocation.to_le_bytes());
                        }
                        if more_saves { cleanup.extend_from_slice(&[0x5b,0x41,0x5c,0x41,0x5d,0x41,0x5e,0x41,0x5f]); }
                        match epilogue {
                            0 => cleanup.push(0x5d),
                            1 => cleanup.push(0xc9), // leave
                            _ => cleanup.extend_from_slice(&[0x48,0x89,0xec,0x5d]),
                        }
                        let mut source = prefix.clone();
                        source.extend_from_slice(&cleanup);
                        source.push(0xc3);
                        for preserve in [false, true] {
                            let plan = plan_x86_entry_abi_strip(&source, 0, true, None, preserve)?;
                            assert!(plan.drop_local_ips.is_empty() && plan.register_renames.is_empty());
                            assert_eq!(plan.callee_saved_mask, 0);
                            assert!(!plan.tail_call_bpf_rbp_is_live);
                            let offset = allocation as i32 + if more_saves { 40 } else { 0 };
                            assert_eq!(plan.tail_call_bpf_rbp_rsp_offset, Some(offset));
                            assert_eq!(plan.tail_call_cleanup_bytes, cleanup);

                            // Save the host RBP, install the incoming BPF frame
                            // in RBP, run the real native prologue and planned
                            // recovery/cleanup, then restore the host RBP.
                            let mut code = vec![0x55,0x48,0x89,0xfd];
                            code.extend_from_slice(&prefix);
                            code.extend_from_slice(&[0x48,0x8b,0x84,0x24]);
                            code.extend_from_slice(&offset.to_le_bytes());
                            code.extend_from_slice(&[0x48,0x8b,0x40,0xf0]);
                            code.extend_from_slice(&plan.tail_call_cleanup_bytes);
                            code.extend_from_slice(&[0x5d,0xc3]);
                            let frame = [0x1357_9bdf_2468_ace0u64, 0, 0];
                            unsafe {
                                let memory = mmap(std::ptr::null_mut(), 4096, 3, 0x22, -1, 0);
                                assert_ne!(memory as isize, -1, "allocate native frame probe");
                                std::ptr::copy_nonoverlapping(code.as_ptr(), memory.cast(), code.len());
                                assert_eq!(mprotect(memory, 4096, 5), 0);
                                let function: unsafe extern "C" fn(*const u64) -> u64 = std::mem::transmute(memory);
                                assert_eq!(function(frame.as_ptr().add(2)), frame[0]);
                                assert_eq!(munmap(memory, 4096), 0);
                            }
                        }
                    }
                }
            }
        }
        Ok(())
    }

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

    #[test]
    fn helper_call_reloc_slot_encodes_only_call_rel32() -> Result<()> {
        let insn = build_x86_helper_call_rel32_slot()?;
        let encoded = encode_x86_local_block("helper_slot", 5, &[insn], &[0])?;

        assert_eq!(encoded.code_buffer, [0xE8, 0, 0, 0, 0]);
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

    #[test]
    fn tail_call_frame_counts_caller_saved_push_allocation() -> Result<()> {
        for (allocation, cleanup, expected) in [
            (vec![0x50], vec![0x48, 0x83, 0xc4, 8], 16),
            (vec![0x50, 0x51, 0x48, 0x83, 0xec, 24], vec![0x48, 0x83, 0xc4, 40], 48),
        ] {
            // Actual Tracee prologue: PUSH RBP; PUSH RBX; PUSH RAX.
            let bytes = [vec![0x55, 0x53], allocation, vec![0x31, 0xc0],
                cleanup.clone(), vec![0x5b, 0x5d, 0xc3]].concat();
            let frame = plan_x86_entry_abi_strip(&bytes, 0, true, None, true)?;
            assert_eq!(frame.tail_call_bpf_rbp_rsp_offset, Some(expected));
            assert!(!frame.tail_call_bpf_rbp_is_live);
            assert_eq!(frame.tail_call_cleanup_bytes, [cleanup, vec![0x5b, 0x5d]].concat());
        }
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
