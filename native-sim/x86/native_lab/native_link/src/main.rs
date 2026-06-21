//! native-link: minimal native ELF -> native-lab blob linker.
//!
//! Reads a userspace-compiled `.so` (typically produced by
//! `micro/programs/Makefile`'s `MICRO_NATIVE` build), discovers an entry
//! function plus every static subprogram reachable from it via direct
//! `call rel32` edges, and emits a single position-independent byte stream
//! suitable for splatting into a BPF JIT image via the
//! `bpf_x86_native_lab` kinsn.
//!
//! Transformation rules — the bare minimum to bridge the SysV AMD64 ABI a
//! userspace compiler emits and the "fall through to BPF JIT epilogue"
//! contract the kinsn enforces:
//!
//!   1. Every `RET` in the **entry** function becomes `JMP rel32 -> end_label`.
//!      Subprogram `RET`s are left alone — they pop the return address the
//!      entry's `CALL` pushed and resume execution in the entry's body.
//!   2. Every `CALL rel32` to a discovered subprogram has its `disp32`
//!      patched so it points at the subprogram's new offset within the
//!      blob (entry first, then subprograms in discovery order).
//!   3. The entry function's compiler ABI save/restore is trimmed when it
//!      matches ordinary x86 SysV or arm64 AAPCS callee-saved register
//!      patterns. The runner passes a sidecar mask so the BPF JIT prologue
//!      preserves the host registers used by the raw blob.
//!   4. Compiler alignment NOPs are dropped (iced re-encodes some
//!      multi-byte NOPs to shorter forms, which would break pre-computed
//!      offset arithmetic).
//!
//! We keep subprogram prologue/epilogue intact. Subprograms are still
//! reached by real native CALL instructions from the entry body and must
//! preserve the caller's callee-saved locals.
//!
//! Any PC-relative reference whose target lies outside the **union of**
//! discovered symbols (rodata constants, GOT entries, external functions)
//! is rejected — the kernel splat location won't match the userspace ELF
//! layout, so silently emitting the original disp would point at garbage.
//!
//! Layout strategy: each discovered symbol is decoded at its original
//! vaddr (so we can identify inter-symbol call targets), then its
//! instructions are re-anchored into an IP=0 local space before going to
//! `BlockEncoder`. iced encodes each symbol independently as if it were
//! the only function in the world; intra-symbol PC-relative branches are
//! resolved correctly. After encoding we concatenate the per-symbol byte
//! buffers; inter-symbol calls and the entry's rewritten RETs target
//! positions only known after concat, so their disp32 bytes are patched
//! in-place using the byte offsets iced reports.

use anyhow::{anyhow, bail, Context, Result};
use clap::{Parser, ValueEnum};
use object::write::{
    Object as WriteObject, Relocation as WriteRelocation, StandardSection, Symbol as WriteSymbol,
    SymbolId as WriteSymbolId, SymbolSection as WriteSymbolSection,
};
use object::{
    BinaryFormat, Endianness, Object, ObjectSection, ObjectSymbol, RelocationFlags,
    RelocationTarget, SectionKind, SymbolFlags, SymbolKind, SymbolScope,
};
use serde::Deserialize;
use std::collections::{HashMap, HashSet};
use std::fs;
use std::path::PathBuf;

mod x86;

const ARM64_THREAD_INFO_CPU_OFFSET_HELPER_KEY: &str = "__native_arm64_thread_info_cpu_offset";
const ARM64_BPF_MAP_MAX_ENTRIES_OFFSET_KEY: &str = "__native_arm64_bpf_map_max_entries_offset";
const ARM64_BPF_ARRAY_PTRS_OFFSET_KEY: &str = "__native_arm64_bpf_array_ptrs_offset";
const ARM64_BPF_PROG_BPF_FUNC_OFFSET_KEY: &str = "__native_arm64_bpf_prog_bpf_func_offset";
const ARM64_TAIL_CALL_OFFSET_KEY: &str = "__native_arm64_tail_call_offset";
const ARM64_RETURN_TRAMPOLINE_SYMBOL: &str = "__native_link_arm64_ret_trampoline";
const ARM64_NATIVE_LAB_STACK_RESERVE_BYTES: u32 = 512;
const NATIVE_LAB_RELOC_HELPER_CALL_ARM64: u32 = 2;
const NATIVE_LAB_RELOC_HELPER_CALL_ARM64_BL26: u32 = 3;
const NATIVE_LAB_RELOC_ARM64_PERCPU_MRS: u32 = 4;
const A64_NOP: u32 = 0xd503_201f;
const A64_BL_IMM26_PLACEHOLDER: u32 = 0x9400_0000;
const A64_BLR_X10: u32 = 0xd63f_0140;
const A64_MRS_X10_TPIDR_EL1: u32 = 0xd538_d08a;
const A64_MOV_X7_X0: u32 = 0xaa00_03e7;

#[derive(Parser, Debug)]
#[command(
    about = "Extract one function (plus reachable subprograms) from a userspace x86-64 ELF and rewrite it for native_lab."
)]
struct Args {
    /// Input ELF object/shared library (e.g. *.native.so from micro/programs).
    #[arg(long)]
    input: PathBuf,

    /// Symbol name of the entry function to extract.
    #[arg(long)]
    symbol: String,

    /// Output path for the raw native blob bytes.
    #[arg(long)]
    output: PathBuf,

    /// Output path for the side-band relocations table consumed by the
    /// kernel module at splat time. Omit if the input has no external
    /// helper or map references.
    #[arg(long)]
    output_relocs: Option<PathBuf>,

    /// Output path for map literal patch sites. Each line is
    /// NAME<TAB>OFFSET, where OFFSET points at an 8-byte literal-pool
    /// slot that the runner must fill with the current kernel map pointer.
    #[arg(long)]
    output_map_patches: Option<PathBuf>,

    /// Output path for native_lab ABI sideband metadata consumed by the runner.
    #[arg(long)]
    output_abi: Option<PathBuf>,

    /// Versioned structured link plan containing helper/map/callsite facts.
    /// This is the stable loader/native-link boundary for kernel mode.
    #[arg(long)]
    link_plan: Option<PathBuf>,

    /// Print a human-readable disassembly of the rewritten blob to stderr.
    #[arg(long)]
    show: bool,

    /// Link mode. `proof` applies canonical ABI/link edits but leaves
    /// verifier-after helper/map lowering symbolic and emits a relocatable
    /// proof object for the eBPF simulator generator.
    #[arg(long, value_enum, default_value_t = LinkMode::Kernel)]
    mode: LinkMode,
}

#[derive(Clone, Copy, Debug, PartialEq, Eq, ValueEnum)]
enum LinkMode {
    Kernel,
    Proof,
}

#[derive(Clone, Copy, Debug)]
enum LookupKind {
    Call,
    Hash,
    LruHash,
    PerCpuHash,
    HashOfMaps,
    Array,
    PerCpuArray,
}

#[derive(Clone, Debug)]
struct LookupSiteSpec {
    kind: LookupKind,
    /// Kernel address the call should route to when this site remains a call.
    target_addr: u64,
    key_offset: u32,
    max_entries: u32,
    elem_size: u32,
    index_mask: u32,
    value_offset: u32,
    percpu_base_addr: u64,
    /// Optional BPF map name observed at the source helper call. The kernel
    /// truncates map names to BPF_OBJ_NAME_LEN - 1, so target-specific
    /// linkers must compare this field using kernel-visible truncation.
    map_name: Option<String>,
}

#[derive(Clone, Copy, Debug)]
enum UpdateKind {
    Call,
    Array,
    PerCpuArray,
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
enum Arm64HelperCallSlot {
    FarSafe,
    DirectOrFar,
    Bl26,
}

#[derive(Clone, Copy, Debug)]
struct Arm64HelperLiteralLoad {
    word_index: usize,
    target: u64,
}

#[derive(Clone, Debug)]
struct UpdateSiteSpec {
    kind: UpdateKind,
    target_addr: u64,
    max_entries: u32,
    elem_size: u32,
    value_size: u32,
    value_offset: u32,
    percpu_base_addr: u64,
    map_name: Option<String>,
}

#[derive(Debug)]
struct LinkSideInputs {
    helper_addrs: HashMap<String, u64>,
    map_addrs: HashMap<String, u64>,
    tail_call_maps: HashSet<String>,
    lookup_sites: Vec<LookupSiteSpec>,
    lookup_maps: HashMap<String, LookupSiteSpec>,
    update_sites: Vec<UpdateSiteSpec>,
    arm64_helper_call_slot: Arm64HelperCallSlot,
}

#[derive(Deserialize)]
struct LinkPlan {
    version: u32,
    #[serde(default)]
    arm64_helper_call_slot: Option<String>,
    #[serde(default)]
    helpers: Vec<LinkPlanNameAddr>,
    #[serde(default)]
    maps: Vec<LinkPlanNameAddr>,
    #[serde(default)]
    tail_call_maps: Vec<String>,
    #[serde(default)]
    lookup_sites: Vec<LinkPlanLookupSite>,
    #[serde(default)]
    lookup_maps: Vec<LinkPlanLookupMap>,
    #[serde(default)]
    update_sites: Vec<LinkPlanUpdateSite>,
}

#[derive(Deserialize)]
struct LinkPlanNameAddr {
    name: String,
    addr: u64,
}

#[derive(Deserialize)]
struct LinkPlanLookupSite {
    kind: String,
    target_addr: u64,
    key_offset: u32,
    max_entries: u32,
    elem_size: u32,
    index_mask: u32,
    value_offset: u32,
    percpu_base_addr: u64,
    map_name: Option<String>,
}

#[derive(Deserialize)]
struct LinkPlanLookupMap {
    name: String,
    kind: String,
    target_addr: u64,
    key_offset: u32,
    max_entries: u32,
    elem_size: u32,
    index_mask: u32,
    value_offset: u32,
    percpu_base_addr: u64,
}

#[derive(Deserialize)]
struct LinkPlanUpdateSite {
    kind: String,
    target_addr: u64,
    max_entries: u32,
    elem_size: u32,
    value_size: u32,
    value_offset: u32,
    percpu_base_addr: u64,
    map_name: Option<String>,
}

fn name_addr_vec_to_map(items: Vec<LinkPlanNameAddr>, label: &str) -> Result<HashMap<String, u64>> {
    let mut out = HashMap::new();
    for item in items {
        if item.name.is_empty() {
            bail!("link-plan {label} entry has empty name");
        }
        if out.insert(item.name.clone(), item.addr).is_some() {
            bail!("duplicate link-plan {label} entry {:?}", item.name);
        }
    }
    Ok(out)
}

fn string_vec_to_set(items: Vec<String>, label: &str) -> Result<HashSet<String>> {
    let mut out = HashSet::new();
    for item in items {
        if item.is_empty() {
            bail!("link-plan {label} entry has empty name");
        }
        if !out.insert(item.clone()) {
            bail!("duplicate link-plan {label} entry {item:?}");
        }
    }
    Ok(out)
}

fn lookup_site_from_plan(site: LinkPlanLookupSite) -> Result<LookupSiteSpec> {
    Ok(LookupSiteSpec {
        kind: parse_lookup_kind(&site.kind)?,
        target_addr: site.target_addr,
        key_offset: site.key_offset,
        max_entries: site.max_entries,
        elem_size: site.elem_size,
        index_mask: site.index_mask,
        value_offset: site.value_offset,
        percpu_base_addr: site.percpu_base_addr,
        map_name: site.map_name,
    })
}

fn lookup_map_from_plan(site: LinkPlanLookupMap) -> Result<(String, LookupSiteSpec)> {
    if site.name.is_empty() {
        bail!("link-plan lookup_maps entry has empty name");
    }
    let name = site.name;
    Ok((
        name.clone(),
        LookupSiteSpec {
            kind: parse_lookup_kind(&site.kind)?,
            target_addr: site.target_addr,
            key_offset: site.key_offset,
            max_entries: site.max_entries,
            elem_size: site.elem_size,
            index_mask: site.index_mask,
            value_offset: site.value_offset,
            percpu_base_addr: site.percpu_base_addr,
            map_name: Some(name),
        },
    ))
}

fn update_site_from_plan(site: LinkPlanUpdateSite) -> Result<UpdateSiteSpec> {
    Ok(UpdateSiteSpec {
        kind: parse_update_kind(&site.kind)?,
        target_addr: site.target_addr,
        max_entries: site.max_entries,
        elem_size: site.elem_size,
        value_size: site.value_size,
        value_offset: site.value_offset,
        percpu_base_addr: site.percpu_base_addr,
        map_name: site.map_name,
    })
}

fn load_link_plan(path: &PathBuf) -> Result<LinkSideInputs> {
    let bytes = fs::read(path).with_context(|| format!("read {}", path.display()))?;
    let plan: LinkPlan = serde_json::from_slice(&bytes)
        .with_context(|| format!("parse native-link plan {}", path.display()))?;
    if plan.version != 1 {
        bail!("unsupported native-link plan version {}", plan.version);
    }
    let mut lookup_maps = HashMap::new();
    for item in plan.lookup_maps {
        let (name, spec) = lookup_map_from_plan(item)?;
        if lookup_maps.insert(name.clone(), spec).is_some() {
            bail!("duplicate link-plan lookup_maps entry {name:?}");
        }
    }
    Ok(LinkSideInputs {
        helper_addrs: name_addr_vec_to_map(plan.helpers, "helpers")?,
        map_addrs: name_addr_vec_to_map(plan.maps, "maps")?,
        tail_call_maps: string_vec_to_set(plan.tail_call_maps, "tail_call_maps")?,
        lookup_sites: plan
            .lookup_sites
            .into_iter()
            .map(lookup_site_from_plan)
            .collect::<Result<Vec<_>>>()?,
        lookup_maps,
        update_sites: plan
            .update_sites
            .into_iter()
            .map(update_site_from_plan)
            .collect::<Result<Vec<_>>>()?,
        arm64_helper_call_slot: parse_arm64_helper_call_slot(plan.arm64_helper_call_slot)?,
    })
}

fn load_link_side_inputs(args: &Args) -> Result<LinkSideInputs> {
    if let Some(path) = &args.link_plan {
        return load_link_plan(path);
    }
    Ok(LinkSideInputs {
        helper_addrs: HashMap::new(),
        map_addrs: HashMap::new(),
        tail_call_maps: HashSet::new(),
        lookup_sites: Vec::new(),
        lookup_maps: HashMap::new(),
        update_sites: Vec::new(),
        arm64_helper_call_slot: Arm64HelperCallSlot::FarSafe,
    })
}

fn parse_lookup_kind(s: &str) -> Result<LookupKind> {
    match s {
        "call" => Ok(LookupKind::Call),
        "hash" => Ok(LookupKind::Hash),
        "lru_hash" => Ok(LookupKind::LruHash),
        "percpu_hash" => Ok(LookupKind::PerCpuHash),
        "hash_of_maps" => Ok(LookupKind::HashOfMaps),
        "array" => Ok(LookupKind::Array),
        "percpu_array" => Ok(LookupKind::PerCpuArray),
        _ => bail!("unknown lookup kind {s:?}"),
    }
}

fn parse_update_kind(s: &str) -> Result<UpdateKind> {
    match s {
        "call" => Ok(UpdateKind::Call),
        "array" => Ok(UpdateKind::Array),
        "percpu_array" => Ok(UpdateKind::PerCpuArray),
        _ => bail!("unknown update kind {s:?}"),
    }
}

fn parse_arm64_helper_call_slot(s: Option<String>) -> Result<Arm64HelperCallSlot> {
    match s.as_deref().unwrap_or("far_safe") {
        "far_safe" => Ok(Arm64HelperCallSlot::FarSafe),
        "direct_or_far" => Ok(Arm64HelperCallSlot::DirectOrFar),
        "bl26" => Ok(Arm64HelperCallSlot::Bl26),
        other => bail!("unknown arm64 helper call slot strategy {other:?}"),
    }
}

fn require_call_target(target: u64, context: &str) -> Result<u64> {
    if target == 0 {
        bail!("{context} has no target address");
    }
    Ok(target)
}

fn resolve_lookup_site_target(spec: &LookupSiteSpec, context: &str) -> Result<u64> {
    match spec.kind {
        LookupKind::Call => require_call_target(spec.target_addr, context),
        LookupKind::Hash
        | LookupKind::LruHash
        | LookupKind::PerCpuHash
        | LookupKind::HashOfMaps => require_call_target(spec.target_addr, context),
        LookupKind::Array | LookupKind::PerCpuArray => {
            bail!("{context} inline array lookup should not resolve a call target")
        }
    }
}

fn resolve_helper_target(
    helper_name: &str,
    helper_addrs: &HashMap<String, u64>,
    context: &str,
) -> Result<u64> {
    helper_addrs
        .get(helper_name)
        .copied()
        .ok_or_else(|| anyhow!("{context} has no helper address"))
}

/// A side-band relocation record. The on-disk layout must stay in sync
/// with `struct native_lab_reloc_record` in
/// module/x86/bpf_x86_native_lab.c (offset:u32, kind:u32, target:u64 —
/// 16 bytes, little-endian). We serialize byte-by-byte below rather than
/// transmuting from a `#[repr(C, packed)]` struct, so plain alignment is
/// fine.
#[derive(Clone, Copy, Debug)]
pub struct RelocRecord {
    offset: u32,
    kind: u32,
    target: u64,
}

#[derive(Clone, Debug)]
struct MapPatch {
    name: String,
    offset: usize,
}

#[derive(Debug, Clone)]
struct SymInfo {
    name: String,
    address: u64,
    size: u64,
    section_index: object::SectionIndex,
}

fn main() -> Result<()> {
    let args = Args::parse();
    let proof_mode = args.mode == LinkMode::Proof;
    let bytes = fs::read(&args.input).with_context(|| format!("read {}", args.input.display()))?;
    let elf = object::File::parse(&*bytes)
        .with_context(|| format!("parse ELF {}", args.input.display()))?;
    let proof_input = elf.section_by_name(".native_link_abi").is_some();
    if !proof_mode && !proof_input {
        bail!("--mode kernel requires a .proof.o produced by --mode proof");
    }
    let LinkSideInputs {
        helper_addrs,
        map_addrs,
        tail_call_maps,
        lookup_sites,
        lookup_maps,
        update_sites,
        arm64_helper_call_slot,
    } = load_link_side_inputs(&args)?;
    let RewriteResult {
        blob,
        relocs,
        map_patches,
        callee_saved_mask,
        proof_relocs,
        proof_symbols,
    } = match elf.architecture() {
        object::Architecture::X86_64 => {
            let entry = find_symbol_by_name(&elf, &args.symbol)?;
            let included = x86::discover_reachable(&elf, &entry)?;

            eprintln!(
                "native-link: entry={} ({} bytes), {} reachable symbol(s) total",
                entry.name,
                entry.size,
                included.len()
            );
            for sym in &included {
                eprintln!(
                    "  - {} (vaddr {:#x}, {} bytes){}",
                    sym.name,
                    sym.address,
                    sym.size,
                    if sym.address == entry.address {
                        " [entry]"
                    } else {
                        ""
                    }
                );
            }

            x86::rewrite_x86(
                &elf,
                &entry,
                &included,
                &helper_addrs,
                &map_addrs,
                &lookup_sites,
                &lookup_maps,
                &update_sites,
                proof_mode,
                args.show,
            )?
        }
        object::Architecture::Aarch64 => {
            let entry = find_symbol_by_name(&elf, &args.symbol)?;
            let included = discover_reachable_arm64(&elf, &entry)?;
            eprintln!(
                "native-link: arm64 entry={} ({} bytes), {} reachable symbol(s) total",
                entry.name,
                entry.size,
                included.len()
            );
            for sym in &included {
                eprintln!(
                    "  - {} (vaddr {:#x}, {} bytes){}",
                    sym.name,
                    sym.address,
                    sym.size,
                    if sym.address == entry.address {
                        " [entry]"
                    } else {
                        ""
                    }
                );
            }
            rewrite_arm64(
                &elf,
                &entry,
                &included,
                &helper_addrs,
                &map_addrs,
                &tail_call_maps,
                &lookup_sites,
                &lookup_maps,
                &update_sites,
                arm64_helper_call_slot,
                proof_mode,
                args.show,
            )?
        }
        arch => bail!("unsupported input ELF arch: {:?}", arch),
    };
    if proof_mode {
        if args.output_relocs.is_some()
            || args.output_map_patches.is_some()
            || args.output_abi.is_some()
        {
            bail!("proof mode writes a single .proof.o; do not pass kernel sideband outputs");
        }
        write_proof_object(
            &args.output,
            elf.architecture(),
            &args.symbol,
            &blob,
            &proof_symbols,
            &proof_relocs,
            callee_saved_mask,
        )?;
        eprintln!(
            "native-link: wrote proof object {} bytes, {} reloc(s) -> {}",
            blob.len(),
            proof_relocs.len(),
            args.output.display()
        );
        return Ok(());
    }
    let output_callee_saved_mask = read_proof_abi(&elf)?.unwrap_or(callee_saved_mask);

    fs::write(&args.output, &blob).with_context(|| format!("write {}", args.output.display()))?;
    eprintln!(
        "native-link: wrote {} bytes -> {} ({} relocs)",
        blob.len(),
        args.output.display(),
        relocs.len()
    );

    if let Some(path) = &args.output_relocs {
        let mut buf = Vec::with_capacity(relocs.len() * std::mem::size_of::<RelocRecord>());
        for r in &relocs {
            // Pack into 16 bytes: u32 offset | u32 kind | u64 target, LE.
            buf.extend_from_slice(&r.offset.to_le_bytes());
            buf.extend_from_slice(&r.kind.to_le_bytes());
            buf.extend_from_slice(&r.target.to_le_bytes());
        }
        fs::write(path, &buf).with_context(|| format!("write {}", path.display()))?;
        eprintln!(
            "native-link: wrote {} relocs -> {}",
            relocs.len(),
            path.display()
        );
    } else if !relocs.is_empty() {
        bail!(
            "{} relocations recorded but --output-relocs was not given",
            relocs.len()
        );
    }
    if let Some(path) = &args.output_map_patches {
        let mut text = String::new();
        for patch in &map_patches {
            if patch.name.contains('\t') || patch.name.contains('\n') {
                bail!("map patch name contains a tab/newline: {:?}", patch.name);
            }
            text.push_str(&patch.name);
            text.push('\t');
            text.push_str(&patch.offset.to_string());
            text.push('\n');
        }
        fs::write(path, text).with_context(|| format!("write {}", path.display()))?;
        eprintln!(
            "native-link: wrote {} map patch site(s) -> {}",
            map_patches.len(),
            path.display()
        );
    }
    if let Some(path) = &args.output_abi {
        let text = format!(
            "version\tnative-link-abi-v2\ncallee_saved_mask\t{}\n",
            output_callee_saved_mask
        );
        fs::write(path, text).with_context(|| format!("write {}", path.display()))?;
        eprintln!("native-link: wrote ABI metadata -> {}", path.display());
    }
    Ok(())
}

fn write_proof_object(
    path: &PathBuf,
    arch: object::Architecture,
    entry_symbol: &str,
    text: &[u8],
    proof_symbols: &[ProofSymbol],
    proof_relocs: &[ProofReloc],
    callee_saved_mask: u8,
) -> Result<()> {
    let mut object = WriteObject::new(BinaryFormat::Elf, arch, Endianness::Little);
    let text_section = object.section_id(StandardSection::Text);
    let text_align = match arch {
        object::Architecture::Aarch64 => 4,
        object::Architecture::X86_64 => 16,
        _ => 1,
    };
    object.append_section_data(text_section, text, text_align);

    let mut symbol_ids: HashMap<String, WriteSymbolId> = HashMap::new();
    let add_text_symbol = |object: &mut WriteObject<'_>,
                           symbol_ids: &mut HashMap<String, WriteSymbolId>,
                           name: &str,
                           offset: u64,
                           size: u64|
     -> Result<()> {
        if offset
            .checked_add(size)
            .is_none_or(|end| end > text.len() as u64)
        {
            bail!("proof symbol {name} range {offset:#x}+{size:#x} exceeds .text");
        }
        let id = object.add_symbol(WriteSymbol {
            name: name.as_bytes().to_vec(),
            value: offset,
            size,
            kind: SymbolKind::Text,
            scope: SymbolScope::Linkage,
            weak: false,
            section: WriteSymbolSection::Section(text_section),
            flags: SymbolFlags::None,
        });
        symbol_ids.insert(name.to_string(), id);
        Ok(())
    };

    let mut saw_entry = false;
    for sym in proof_symbols {
        if sym.name == entry_symbol {
            saw_entry = true;
        }
        add_text_symbol(
            &mut object,
            &mut symbol_ids,
            &sym.name,
            sym.offset,
            sym.size,
        )?;
    }
    if !saw_entry {
        add_text_symbol(
            &mut object,
            &mut symbol_ids,
            entry_symbol,
            0,
            text.len() as u64,
        )?;
    }

    let data_section = object.add_section(
        Vec::new(),
        b".native_link_rodata".to_vec(),
        SectionKind::ReadOnlyData,
    );
    let mut rodata_ids: HashMap<String, WriteSymbolId> = HashMap::new();
    for reloc in proof_relocs.iter().filter(|reloc| reloc.data.is_some()) {
        if rodata_ids.contains_key(&reloc.symbol) {
            continue;
        }
        let data = reloc.data.as_ref().expect("filtered proof rodata");
        let offset = object.append_section_data(data_section, data, 16);
        let id = object.add_symbol(WriteSymbol {
            name: reloc.symbol.as_bytes().to_vec(),
            value: offset,
            size: data.len() as u64,
            kind: SymbolKind::Data,
            scope: SymbolScope::Linkage,
            weak: false,
            section: WriteSymbolSection::Section(data_section),
            flags: SymbolFlags::None,
        });
        symbol_ids.insert(reloc.symbol.clone(), id);
        rodata_ids.insert(reloc.symbol.clone(), id);
    }

    for reloc in proof_relocs {
        if reloc.offset >= text.len() as u64 {
            bail!(
                "proof relocation against {} at {:#x} exceeds .text size {}",
                reloc.symbol,
                reloc.offset,
                text.len()
            );
        }
        let symbol = if let Some(id) = symbol_ids.get(&reloc.symbol) {
            *id
        } else {
            let id = object.add_symbol(WriteSymbol {
                name: reloc.symbol.as_bytes().to_vec(),
                value: 0,
                size: 0,
                kind: SymbolKind::Unknown,
                scope: SymbolScope::Linkage,
                weak: false,
                section: WriteSymbolSection::Undefined,
                flags: SymbolFlags::None,
            });
            symbol_ids.insert(reloc.symbol.clone(), id);
            id
        };
        object
            .add_relocation(
                text_section,
                WriteRelocation {
                    offset: reloc.offset,
                    symbol,
                    addend: reloc.addend,
                    flags: RelocationFlags::Elf {
                        r_type: reloc.r_type,
                    },
                },
            )
            .with_context(|| {
                format!(
                    "add proof relocation {:#x} r_type={} {}",
                    reloc.offset, reloc.r_type, reloc.symbol
                )
            })?;
    }

    let abi_section = object.add_section(
        Vec::new(),
        b".native_link_abi".to_vec(),
        SectionKind::ReadOnlyData,
    );
    let abi = format!(
        "version\tnative-link-abi-v2\ncallee_saved_mask\t{}\n",
        callee_saved_mask
    );
    object.append_section_data(abi_section, abi.as_bytes(), 1);

    let bytes = object.write().context("write proof ELF object")?;
    fs::write(path, bytes).with_context(|| format!("write {}", path.display()))
}

fn read_proof_abi(elf: &object::File) -> Result<Option<u8>> {
    let Some(section) = elf.section_by_name(".native_link_abi") else {
        return Ok(None);
    };
    let text = std::str::from_utf8(section.data().context("read .native_link_abi section")?)
        .context(".native_link_abi is not UTF-8")?;
    let mut seen_version = false;
    let mut mask: Option<u8> = None;
    for (line_no, line) in text.lines().enumerate() {
        if line.is_empty() {
            continue;
        }
        let (key, value) = line
            .split_once('\t')
            .ok_or_else(|| anyhow!("invalid .native_link_abi line {}", line_no + 1))?;
        if value.contains('\t') {
            bail!("invalid .native_link_abi line {}", line_no + 1);
        }
        match key {
            "version" => {
                if value != "native-link-abi-v2" {
                    bail!("unsupported .native_link_abi version {value:?}");
                }
                seen_version = true;
            }
            "callee_saved_mask" => {
                let parsed: u8 = value
                    .parse()
                    .with_context(|| format!("parse callee_saved_mask {value:?}"))?;
                if parsed > 0xf {
                    bail!("callee_saved_mask exceeds 4 bits: {parsed}");
                }
                mask = Some(parsed);
            }
            _ => bail!("unknown .native_link_abi key {key:?}"),
        }
    }
    if !seen_version || mask.is_none() {
        bail!(".native_link_abi missing required keys");
    }
    Ok(mask)
}

fn arm64_effective_callee_saved_mask(
    proof_callee_saved_mask: Option<u8>,
    entry_callee_saved_mask: u8,
) -> u8 {
    proof_callee_saved_mask.unwrap_or(entry_callee_saved_mask)
}

fn arm64_observed_bpf_callee_saved_mask(bytes: &[u8], nop_word_indices: &HashSet<usize>) -> u8 {
    let mut mask = 0u8;
    for (word_index, word) in bytes.chunks_exact(4).enumerate() {
        if nop_word_indices.contains(&word_index) {
            continue;
        }
        let insn = u32::from_le_bytes(word.try_into().unwrap());
        arm64_accumulate_bpf_callee_saved_regs(insn, &mut mask);
    }
    mask
}

fn arm64_accumulate_bpf_callee_saved_regs(insn: u32, mask: &mut u8) {
    if insn == A64_NOP || a64_is_ret(insn) {
        return;
    }
    if a64_is_bl(insn) || a64_is_uncond_b(insn) || a64_is_b_cond(insn) {
        return;
    }
    if a64_is_cbz_cbnz(insn) || a64_is_tbz_tbnz(insn) {
        arm64_mark_bpf_callee_saved_reg(mask, insn & 0x1f);
        return;
    }

    for shift in [0, 5, 10, 16] {
        arm64_mark_bpf_callee_saved_reg(mask, (insn >> shift) & 0x1f);
    }
}

fn arm64_mark_bpf_callee_saved_reg(mask: &mut u8, reg: u32) {
    if let Some(bit_index) = arm64_callee_saved_bit_index(reg) {
        *mask |= 1u8 << bit_index;
    }
}

fn find_symbol_by_name(elf: &object::File, name: &str) -> Result<SymInfo> {
    for sym in elf.symbols().chain(elf.dynamic_symbols()) {
        if sym.name().ok() == Some(name) && sym.size() > 0 {
            return Ok(SymInfo {
                name: name.to_string(),
                address: sym.address(),
                size: sym.size(),
                section_index: sym
                    .section_index()
                    .ok_or_else(|| anyhow!("symbol {name} has no section"))?,
            });
        }
    }
    bail!("symbol {name} not found in input ELF")
}

fn find_symbol_at_section_address(
    elf: &object::File,
    section_index: object::SectionIndex,
    address: u64,
) -> Option<SymInfo> {
    for sym in elf.symbols().chain(elf.dynamic_symbols()) {
        let addr = sym.address();
        let size = sym.size();
        if size == 0 || sym.section_index()? != section_index {
            continue;
        }
        if address >= addr && address < addr + size {
            let name = sym.name().ok()?.to_string();
            return Some(SymInfo {
                name,
                address: addr,
                size,
                section_index,
            });
        }
    }
    None
}

fn read_symbol_bytes(elf: &object::File, sym: &SymInfo) -> Result<Vec<u8>> {
    let section = elf
        .section_by_index(sym.section_index)
        .with_context(|| format!("section index {:?}", sym.section_index))?;
    let section_data = section.data().context("read section data")?;
    let section_addr = section.address();
    let offset = sym
        .address
        .checked_sub(section_addr)
        .ok_or_else(|| anyhow!("symbol address below section base"))?;
    let end = offset
        .checked_add(sym.size)
        .ok_or_else(|| anyhow!("symbol size overflow"))?;
    let slice = section_data
        .get(offset as usize..end as usize)
        .ok_or_else(|| anyhow!("symbol bytes out of section bounds"))?;
    Ok(slice.to_vec())
}

#[derive(Debug, Clone)]
struct RewriteResult {
    blob: Vec<u8>,
    relocs: Vec<RelocRecord>,
    map_patches: Vec<MapPatch>,
    callee_saved_mask: u8,
    proof_relocs: Vec<ProofReloc>,
    proof_symbols: Vec<ProofSymbol>,
}

#[derive(Clone, Debug)]
struct ProofReloc {
    offset: u64,
    r_type: u32,
    symbol: String,
    addend: i64,
    data: Option<Vec<u8>>,
}

#[derive(Clone, Debug)]
struct ProofSymbol {
    name: String,
    offset: u64,
    size: u64,
}

fn a64_sign_extend(value: u32, bits: u8) -> i64 {
    let shift = 64 - bits;
    ((value as i64) << shift) >> shift
}

fn a64_patch_b(word_index: usize, target_index: usize) -> Result<u32> {
    let disp = target_index as i64 - word_index as i64;
    if disp < -(1 << 25) || disp >= (1 << 25) {
        bail!("arm64 branch displacement out of range: {disp}");
    }
    Ok(0x1400_0000 | ((disp as u32) & 0x03ff_ffff))
}

fn a64_patch_bl(word_index: usize, target_index: usize) -> Result<u32> {
    let disp = target_index as i64 - word_index as i64;
    if disp < -(1 << 25) || disp >= (1 << 25) {
        bail!("arm64 BL displacement out of range: {disp}");
    }
    Ok(0x9400_0000 | ((disp as u32) & 0x03ff_ffff))
}

fn a64_patch_b_cond(insn: u32, word_index: usize, target_index: usize) -> Result<u32> {
    let disp = target_index as i64 - word_index as i64;
    if disp < -(1 << 18) || disp >= (1 << 18) {
        bail!("arm64 B.cond displacement out of range: {disp}");
    }
    Ok((insn & !(0x7ffff << 5)) | (((disp as u32) & 0x7ffff) << 5))
}

fn a64_patch_cbz_cbnz(insn: u32, word_index: usize, target_index: usize) -> Result<u32> {
    let disp = target_index as i64 - word_index as i64;
    if disp < -(1 << 18) || disp >= (1 << 18) {
        bail!("arm64 CBZ/CBNZ displacement out of range: {disp}");
    }
    Ok((insn & !(0x7ffff << 5)) | (((disp as u32) & 0x7ffff) << 5))
}

fn a64_patch_tbz_tbnz(insn: u32, word_index: usize, target_index: usize) -> Result<u32> {
    let disp = target_index as i64 - word_index as i64;
    if disp < -(1 << 13) || disp >= (1 << 13) {
        bail!("arm64 TBZ/TBNZ displacement out of range: {disp}");
    }
    Ok((insn & !(0x3fff << 5)) | (((disp as u32) & 0x3fff) << 5))
}

fn a64_invert_tbz_tbnz(insn: u32) -> u32 {
    insn ^ (1 << 24)
}

fn a64_patch_tbz_tbnz_or_long(
    blob: &mut [u8],
    insn: u32,
    word_index: usize,
    target_index: usize,
) -> Result<u32> {
    match a64_patch_tbz_tbnz(insn, word_index, target_index) {
        Ok(patched) => return Ok(patched),
        Err(short_err) => {
            let branch_word = word_index
                .checked_add(1)
                .ok_or_else(|| anyhow!("arm64 TBZ/TBNZ long branch slot index overflow"))?;
            let skip_word = word_index
                .checked_add(2)
                .ok_or_else(|| anyhow!("arm64 TBZ/TBNZ long branch skip index overflow"))?;
            let branch_off = branch_word
                .checked_mul(4)
                .ok_or_else(|| anyhow!("arm64 TBZ/TBNZ long branch byte offset overflow"))?;
            let branch_bytes = blob.get_mut(branch_off..branch_off + 4).ok_or_else(|| {
                anyhow!("arm64 TBZ/TBNZ long branch slot missing after word {word_index}")
            })?;
            let existing = u32::from_le_bytes(branch_bytes.try_into().unwrap());
            if existing != A64_NOP {
                return Err(short_err).with_context(|| {
                    format!(
                        "arm64 TBZ/TBNZ long branch slot after word {word_index} is occupied by {existing:#010x}"
                    )
                });
            }
            let inverted = a64_patch_tbz_tbnz(a64_invert_tbz_tbnz(insn), word_index, skip_word)
                .with_context(|| {
                    format!("arm64 TBZ/TBNZ long branch skip patch failed at word {word_index}")
                })?;
            let branch = a64_patch_b(branch_word, target_index).with_context(|| {
                format!("arm64 TBZ/TBNZ long branch target patch failed at word {word_index}")
            })?;
            branch_bytes.copy_from_slice(&branch.to_le_bytes());
            Ok(inverted)
        }
    }
}

fn a64_cbz64(rt: u32) -> Result<u32> {
    if rt >= 32 {
        bail!("arm64 CBZ register out of range: x{rt}");
    }
    Ok(0xb400_0000 | rt)
}

fn a64_cbnz64(rt: u32) -> Result<u32> {
    if rt >= 32 {
        bail!("arm64 CBNZ register out of range: x{rt}");
    }
    Ok(0xb500_0000 | rt)
}

fn a64_tbz64(rt: u32, bit: u32) -> Result<u32> {
    if rt >= 32 {
        bail!("arm64 TBZ register out of range: x{rt}");
    }
    if bit >= 64 {
        bail!("arm64 TBZ bit out of range: {bit}");
    }
    Ok(0x3600_0000 | ((bit & 0x20) << 26) | ((bit & 0x1f) << 19) | rt)
}

fn a64_is_tbz64_bit(insn: u32, rt: u32, bit: u32) -> bool {
    if rt >= 32 || bit >= 64 {
        return false;
    }
    let expected = 0x3600_0000 | ((bit & 0x20) << 26) | ((bit & 0x1f) << 19) | rt;
    (insn & 0xfff8_001f) == (expected & 0xfff8_001f)
}

fn a64_br(reg: u32) -> Result<u32> {
    if reg >= 32 {
        bail!("arm64 BR register out of range: x{reg}");
    }
    Ok(0xd61f_0000 | (reg << 5))
}

fn a64_adr(rd: u32, word_index: usize, target_byte_offset: usize) -> Result<u32> {
    if rd >= 32 {
        bail!("arm64 ADR target register out of range: x{rd}");
    }
    let source_byte_offset = word_index
        .checked_mul(4)
        .ok_or_else(|| anyhow!("arm64 source byte offset overflow"))?;
    let disp = target_byte_offset as i64 - source_byte_offset as i64;
    if disp < -(1 << 20) || disp >= (1 << 20) {
        bail!("arm64 ADR displacement out of range: {disp}");
    }
    let imm = (disp as u32) & 0x1f_ffff;
    let immlo = (imm & 0x3) << 29;
    let immhi = ((imm >> 2) & 0x7ffff) << 5;
    Ok(0x1000_0000 | immlo | immhi | rd)
}

fn a64_is_uncond_b(insn: u32) -> bool {
    (insn & 0x7c00_0000) == 0x1400_0000
}

fn a64_is_bl(insn: u32) -> bool {
    (insn & 0xfc00_0000) == 0x9400_0000
}

fn a64_is_adr_or_adrp(insn: u32) -> bool {
    (insn & 0x9f00_0000) == 0x1000_0000 || (insn & 0x9f00_0000) == 0x9000_0000
}

fn a64_is_ldr_literal(insn: u32) -> bool {
    (insn & 0x3b00_0000) == 0x1800_0000
}

fn a64_is_b_cond(insn: u32) -> bool {
    (insn & 0xff00_0010) == 0x5400_0000
}

fn a64_is_cbz_cbnz(insn: u32) -> bool {
    (insn & 0x7e00_0000) == 0x3400_0000
}

fn a64_is_tbz_tbnz(insn: u32) -> bool {
    (insn & 0x7e00_0000) == 0x3600_0000
}

fn a64_branch_target(entry_addr: u64, word_index: usize, insn: u32) -> Option<u64> {
    if a64_is_uncond_b(insn) {
        let imm26 = insn & 0x03ff_ffff;
        let disp = a64_sign_extend(imm26, 26) << 2;
        return Some(((entry_addr as i64) + (word_index as i64 * 4) + disp) as u64);
    }
    if a64_is_b_cond(insn) {
        let imm19 = (insn >> 5) & 0x7ffff;
        let disp = a64_sign_extend(imm19, 19) << 2;
        return Some(((entry_addr as i64) + (word_index as i64 * 4) + disp) as u64);
    }
    if a64_is_cbz_cbnz(insn) {
        let imm19 = (insn >> 5) & 0x7ffff;
        let disp = a64_sign_extend(imm19, 19) << 2;
        return Some(((entry_addr as i64) + (word_index as i64 * 4) + disp) as u64);
    }
    if a64_is_tbz_tbnz(insn) {
        let imm14 = (insn >> 5) & 0x3fff;
        let disp = a64_sign_extend(imm14, 14) << 2;
        return Some(((entry_addr as i64) + (word_index as i64 * 4) + disp) as u64);
    }
    None
}

fn a64_bl_target(entry_addr: u64, word_index: usize, insn: u32) -> Option<u64> {
    if !a64_is_bl(insn) {
        return None;
    }
    let imm26 = insn & 0x03ff_ffff;
    let disp = a64_sign_extend(imm26, 26) << 2;
    Some(((entry_addr as i64) + (word_index as i64 * 4) + disp) as u64)
}

fn a64_is_ret(insn: u32) -> bool {
    (insn & 0xffff_fc1f) == 0xd65f_0000
}

fn a64_ldr_lit64(rt: u32, word_index: usize, target_byte_offset: usize) -> Result<u32> {
    if rt >= 32 {
        bail!("arm64 literal load target register out of range: x{rt}");
    }
    let source_byte_offset = word_index
        .checked_mul(4)
        .ok_or_else(|| anyhow!("arm64 source byte offset overflow"))?;
    let disp = target_byte_offset as i64 - source_byte_offset as i64;
    if disp % 4 != 0 {
        bail!("arm64 literal load displacement is not 4-byte aligned: {disp}");
    }
    let imm19 = disp / 4;
    if imm19 < -(1 << 18) || imm19 >= (1 << 18) {
        bail!("arm64 literal load displacement out of range: {disp}");
    }
    Ok(0x5800_0000 | (((imm19 as u32) & 0x7ffff) << 5) | rt)
}

fn a64_ldr_lit64_target(blob: &[u8], word_index: usize, insn: u32, rt: u32) -> Option<u64> {
    if rt >= 32 || (insn & 0xff00_001f) != (0x5800_0000 | rt) {
        return None;
    }
    let imm19 = (insn >> 5) & 0x7ffff;
    let disp = a64_sign_extend(imm19, 19) << 2;
    let source = word_index.checked_mul(4)? as i64;
    let target = source.checked_add(disp)?;
    if target < 0 {
        return None;
    }
    let target = target as usize;
    if target.checked_add(8)? > blob.len() {
        return None;
    }
    Some(u64::from_le_bytes(
        blob[target..target + 8].try_into().ok()?,
    ))
}

fn a64_blr_reg(insn: u32) -> Option<usize> {
    if (insn & 0xffff_fc1f) != 0xd63f_0000 {
        return None;
    }
    Some(((insn >> 5) & 0x1f) as usize)
}

fn a64_br_reg(insn: u32) -> Option<usize> {
    if (insn & 0xffff_fc1f) != 0xd61f_0000 {
        return None;
    }
    Some(((insn >> 5) & 0x1f) as usize)
}

fn arm64_br_x10_has_kernel_guard(blob: &[u8], word_index: usize) -> bool {
    for prior_word_index in (0..word_index).rev() {
        let off = prior_word_index * 4;
        let insn = u32::from_le_bytes(blob[off..off + 4].try_into().unwrap());
        if a64_is_tbz64_bit(insn, 10, 63) {
            return true;
        }
        if a64_written_gprs(insn)
            .into_iter()
            .flatten()
            .any(|reg| reg == 10)
        {
            return false;
        }
        if a64_blr_reg(insn).is_some() || a64_br_reg(insn).is_some() || a64_is_ret(insn) {
            return false;
        }
    }
    false
}

fn validate_arm64_kernel_blob_control_flow(
    blob: &[u8],
    code_word_count: usize,
    ret_trampoline_word: usize,
) -> Result<()> {
    if blob.len() % 4 != 0 {
        bail!("arm64 kernel blob size is not 4-byte aligned");
    }
    let total_words = blob.len() / 4;
    if code_word_count > total_words {
        bail!(
            "arm64 kernel blob code range {code_word_count} words exceeds total {total_words} words"
        );
    }
    if ret_trampoline_word >= total_words {
        bail!(
            "arm64 kernel blob return trampoline word {ret_trampoline_word} exceeds total {total_words} words"
        );
    }

    for word_index in 0..total_words {
        if word_index >= code_word_count && word_index != ret_trampoline_word {
            continue;
        }
        let off = word_index * 4;
        let insn = u32::from_le_bytes(blob[off..off + 4].try_into().unwrap());
        if let Some(reg) = a64_blr_reg(insn) {
            if reg == 10 && arm64_blr_x10_has_kernel_literal(blob, word_index) {
                continue;
            }
            bail!(
                "arm64 kernel blob still contains unsupported register-indirect call blr x{reg} at word index {word_index}; helper calls must be rewritten"
            );
        }
        if let Some(reg) = a64_br_reg(insn) {
            if reg != 10 {
                bail!(
                    "arm64 kernel blob contains unsupported register-indirect branch br x{reg} at word index {word_index}"
                );
            }
            if !arm64_br_x10_has_kernel_guard(blob, word_index) {
                bail!(
                    "arm64 kernel blob contains tail-call branch br x10 at word index {word_index} without a dominating kernel-address guard"
                );
            }
        }
    }

    Ok(())
}

fn arm64_blr_x10_has_kernel_literal(blob: &[u8], word_index: usize) -> bool {
    if word_index == 0 {
        return false;
    }
    let ldr_word_index = word_index - 1;
    let off = ldr_word_index * 4;
    let ldr = u32::from_le_bytes(blob[off..off + 4].try_into().unwrap());
    let Some(target) = a64_ldr_lit64_target(blob, ldr_word_index, ldr, 10) else {
        return false;
    };
    target & (1u64 << 63) != 0
}

fn a64_movz_imm_to_reg(insn: u32) -> Option<(usize, u64)> {
    if (insn & 0x7f80_0000) != 0x5280_0000 {
        return None;
    }
    let sf = (insn >> 31) & 1;
    let hw = (insn >> 21) & 0x3;
    if sf == 0 && hw >= 2 {
        return None;
    }
    let shift = hw * 16;
    let imm = u64::from((insn >> 5) & 0xffff) << shift;
    Some(((insn & 0x1f) as usize, imm))
}

fn a64_known_helper_id_load(insn: u32) -> Option<(usize, u64)> {
    let (reg, helper_id) = a64_movz_imm_to_reg(insn)?;
    x86::bpf_helper_name_from_id(helper_id)?;
    Some((reg, helper_id))
}

fn a64_written_gprs_from(regs: &[u32]) -> [Option<usize>; 3] {
    let mut out = [None; 3];
    let mut out_idx = 0usize;
    for &reg in regs {
        if reg >= 31 {
            continue;
        }
        let reg = reg as usize;
        if out[..out_idx].contains(&Some(reg)) {
            continue;
        }
        out[out_idx] = Some(reg);
        out_idx += 1;
        if out_idx == out.len() {
            break;
        }
    }
    out
}

fn a64_one_written_gpr(reg: u32) -> [Option<usize>; 3] {
    a64_written_gprs_from(&[reg])
}

fn a64_written_gprs(insn: u32) -> [Option<usize>; 3] {
    if matches!(insn & 0x7f80_0000, 0x1280_0000 | 0x5280_0000 | 0x7280_0000) {
        return a64_one_written_gpr(insn & 0x1f);
    }
    if (insn & 0x1f00_0000) == 0x1100_0000 {
        return a64_one_written_gpr(insn & 0x1f);
    }
    if (insn & 0x1f80_0000) == 0x1200_0000 {
        return a64_one_written_gpr(insn & 0x1f);
    }
    if (insn & 0x1f80_0000) == 0x1300_0000 {
        return a64_one_written_gpr(insn & 0x1f);
    }
    if (insn & 0x1fa0_0000) == 0x1380_0000 {
        return a64_one_written_gpr(insn & 0x1f);
    }
    if (insn & 0x1f00_0000) == 0x0a00_0000 {
        return a64_one_written_gpr(insn & 0x1f);
    }
    if (insn & 0x1f00_0000) == 0x0b00_0000 {
        return a64_one_written_gpr(insn & 0x1f);
    }
    if (insn & 0x1fe0_0000) == 0x1a80_0000 {
        return a64_one_written_gpr(insn & 0x1f);
    }
    if (insn & 0x1fe0_0000) == 0x1ac0_0000 {
        return a64_one_written_gpr(insn & 0x1f);
    }
    if (insn & 0x1f00_0000) == 0x1b00_0000 {
        return a64_one_written_gpr(insn & 0x1f);
    }
    if let Some((dst, _)) = a64_mov_reg64(insn) {
        return a64_one_written_gpr(dst as u32);
    }
    if (insn & 0x3b00_0000) == 0x3800_0000 {
        let is_load = (insn & 0x0040_0000) != 0;
        let has_writeback = matches!((insn >> 10) & 0x3, 0x1 | 0x3);
        let rt = insn & 0x1f;
        let rn = (insn >> 5) & 0x1f;
        return match (is_load, has_writeback) {
            (true, true) => a64_written_gprs_from(&[rt, rn]),
            (true, false) => a64_one_written_gpr(rt),
            (false, true) => a64_one_written_gpr(rn),
            (false, false) => [None, None, None],
        };
    }
    if (insn & 0x3b00_0000) == 0x3900_0000 && (insn & 0x0040_0000) != 0 {
        return a64_one_written_gpr(insn & 0x1f);
    }
    if matches!(insn & 0x3a40_0000, 0x2800_0000 | 0x2840_0000) {
        let is_load = (insn & 0x0040_0000) != 0;
        let has_writeback = matches!((insn >> 23) & 0x3, 0x1 | 0x3);
        let rt = insn & 0x1f;
        let rt2 = (insn >> 10) & 0x1f;
        let rn = (insn >> 5) & 0x1f;
        return match (is_load, has_writeback) {
            (true, true) => a64_written_gprs_from(&[rt, rt2, rn]),
            (true, false) => a64_written_gprs_from(&[rt, rt2]),
            (false, true) => a64_one_written_gpr(rn),
            (false, false) => [None, None, None],
        };
    }
    if (insn & 0xfff0_0000) == 0xd530_0000 {
        return a64_one_written_gpr(insn & 0x1f);
    }
    [None, None, None]
}

fn a64_maybe_reads_gpr(insn: u32, reg: usize) -> bool {
    if reg >= 31 || a64_is_ret(insn) || a64_is_bl(insn) || a64_blr_reg(insn).is_some() {
        return false;
    }
    if a64_known_helper_id_load(insn).is_some_and(|(dst, _)| dst == reg) {
        return false;
    }

    if let Some((dst, src)) = a64_mov_reg64(insn) {
        return src == reg && dst != reg;
    }

    if (insn & 0x1f00_0000) == 0x1100_0000 {
        let rn = ((insn >> 5) & 0x1f) as usize;
        return rn == reg;
    }

    if (insn & 0x3b00_0000) == 0x3900_0000 {
        let rt = (insn & 0x1f) as usize;
        let rn = ((insn >> 5) & 0x1f) as usize;
        let is_load = (insn & 0x0040_0000) != 0;
        return rn == reg || (!is_load && rt == reg);
    }

    if (insn & 0x7e00_0000) == 0x3400_0000 || (insn & 0x7e00_0000) == 0x3600_0000 {
        return (insn & 0x1f) as usize == reg;
    }

    false
}

fn clear_arm64_helper_imm_register(
    helper_imm_registers: &mut [Option<u64>; 32],
    helper_imm_word_indices: &mut [Option<usize>; 32],
    helper_imm_read_since_load: &mut [bool; 32],
    reg: usize,
) {
    helper_imm_registers[reg] = None;
    helper_imm_word_indices[reg] = None;
    helper_imm_read_since_load[reg] = false;
}

fn clear_arm64_call_clobbered_helper_imm_registers(
    helper_imm_registers: &mut [Option<u64>; 32],
    helper_imm_word_indices: &mut [Option<usize>; 32],
    helper_imm_read_since_load: &mut [bool; 32],
) {
    for reg in 0..19 {
        clear_arm64_helper_imm_register(
            helper_imm_registers,
            helper_imm_word_indices,
            helper_imm_read_since_load,
            reg,
        );
    }
}

fn a64_add_imm64(rd: u32, rn: u32, imm: u32) -> Result<u32> {
    if rd >= 32 || rn >= 32 {
        bail!("arm64 ADD imm register out of range: x{rd}, x{rn}");
    }
    let (imm12, shift) = if imm <= 0xfff {
        (imm, 0)
    } else if imm & 0xfff == 0 && (imm >> 12) <= 0xfff {
        (imm >> 12, 1)
    } else {
        bail!("arm64 ADD imm out of range: {imm}");
    };
    Ok(0x9100_0000 | (shift << 22) | (imm12 << 10) | (rn << 5) | rd)
}

fn a64_add_shift64(rd: u32, rn: u32, rm: u32, shift: u32) -> Result<u32> {
    if rd >= 32 || rn >= 32 || rm >= 32 {
        bail!("arm64 ADD shifted register out of range: x{rd}, x{rn}, x{rm}");
    }
    if shift > 63 {
        bail!("arm64 ADD shifted amount out of range: {shift}");
    }
    Ok(0x8b00_0000 | (rm << 16) | (shift << 10) | (rn << 5) | rd)
}

fn a64_ldr_u32(rt: u32, rn: u32, byte_off: u32) -> Result<u32> {
    if rt >= 32 || rn >= 32 {
        bail!("arm64 LDR w register out of range: w{rt}, x{rn}");
    }
    if byte_off % 4 != 0 || byte_off / 4 > 0xfff {
        bail!("arm64 LDR w unsigned offset out of range: {byte_off}");
    }
    Ok(0xb940_0000 | ((byte_off / 4) << 10) | (rn << 5) | rt)
}

fn a64_mrs_sp_el0(rt: u32) -> Result<u32> {
    if rt >= 32 {
        bail!("arm64 MRS SP_EL0 target register out of range: x{rt}");
    }
    Ok(0xd538_4100 | rt)
}

fn a64_ldr_u64(rt: u32, rn: u32, byte_off: u32) -> Result<u32> {
    if rt >= 32 || rn >= 32 {
        bail!("arm64 LDR x register out of range: x{rt}, x{rn}");
    }
    if byte_off % 8 != 0 || byte_off / 8 > 0xfff {
        bail!("arm64 LDR x unsigned offset out of range: {byte_off}");
    }
    Ok(0xf940_0000 | ((byte_off / 8) << 10) | (rn << 5) | rt)
}

fn a64_str_u8(rt: u32, rn: u32, byte_off: u32) -> Result<u32> {
    if rt >= 32 || rn >= 32 {
        bail!("arm64 STR b register out of range: w{rt}, x{rn}");
    }
    if byte_off > 0xfff {
        bail!("arm64 STR b unsigned offset out of range: {byte_off}");
    }
    Ok(0x3900_0000 | (byte_off << 10) | (rn << 5) | rt)
}

fn a64_ldr_u8(rt: u32, rn: u32, byte_off: u32) -> Result<u32> {
    if rt >= 32 || rn >= 32 {
        bail!("arm64 LDR b register out of range: w{rt}, x{rn}");
    }
    if byte_off > 0xfff {
        bail!("arm64 LDR b unsigned offset out of range: {byte_off}");
    }
    Ok(0x3940_0000 | (byte_off << 10) | (rn << 5) | rt)
}

fn a64_str_u16(rt: u32, rn: u32, byte_off: u32) -> Result<u32> {
    if rt >= 32 || rn >= 32 {
        bail!("arm64 STR h register out of range: w{rt}, x{rn}");
    }
    if byte_off % 2 != 0 || byte_off / 2 > 0xfff {
        bail!("arm64 STR h unsigned offset out of range: {byte_off}");
    }
    Ok(0x7900_0000 | ((byte_off / 2) << 10) | (rn << 5) | rt)
}

fn a64_ldr_u16(rt: u32, rn: u32, byte_off: u32) -> Result<u32> {
    if rt >= 32 || rn >= 32 {
        bail!("arm64 LDR h register out of range: w{rt}, x{rn}");
    }
    if byte_off % 2 != 0 || byte_off / 2 > 0xfff {
        bail!("arm64 LDR h unsigned offset out of range: {byte_off}");
    }
    Ok(0x7940_0000 | ((byte_off / 2) << 10) | (rn << 5) | rt)
}

fn a64_str_u32(rt: u32, rn: u32, byte_off: u32) -> Result<u32> {
    if rt >= 32 || rn >= 32 {
        bail!("arm64 STR w register out of range: w{rt}, x{rn}");
    }
    if byte_off % 4 != 0 || byte_off / 4 > 0xfff {
        bail!("arm64 STR w unsigned offset out of range: {byte_off}");
    }
    Ok(0xb900_0000 | ((byte_off / 4) << 10) | (rn << 5) | rt)
}

fn a64_str_u64(rt: u32, rn: u32, byte_off: u32) -> Result<u32> {
    if rt >= 32 || rn >= 32 {
        bail!("arm64 STR x register out of range: x{rt}, x{rn}");
    }
    if byte_off % 8 != 0 || byte_off / 8 > 0xfff {
        bail!("arm64 STR x unsigned offset out of range: {byte_off}");
    }
    Ok(0xf900_0000 | ((byte_off / 8) << 10) | (rn << 5) | rt)
}

fn a64_cmp_imm64(rn: u32, imm: u32) -> Result<u32> {
    if rn >= 32 {
        bail!("arm64 CMP imm register out of range: x{rn}");
    }
    let (imm12, shift) = if imm <= 0xfff {
        (imm, 0)
    } else if imm & 0xfff == 0 && (imm >> 12) <= 0xfff {
        (imm >> 12, 1)
    } else {
        bail!("arm64 CMP imm out of range: {imm}");
    };
    Ok(0xf100_001f | (shift << 22) | (imm12 << 10) | (rn << 5))
}

fn a64_cmp_reg64(rn: u32, rm: u32) -> Result<u32> {
    if rn >= 32 || rm >= 32 {
        bail!("arm64 CMP reg register out of range: x{rn}, x{rm}");
    }
    Ok(0xeb00_001f | (rm << 16) | (rn << 5))
}

fn a64_cmp_reg32(rn: u32, rm: u32) -> Result<u32> {
    if rn >= 32 || rm >= 32 {
        bail!("arm64 CMP w register out of range: w{rn}, w{rm}");
    }
    Ok(0x6b00_001f | (rm << 16) | (rn << 5))
}

fn a64_mov_reg32(rd: u32, rn: u32) -> Result<u32> {
    if rd >= 32 || rn >= 32 {
        bail!("arm64 MOV w register out of range: w{rd}, w{rn}");
    }
    Ok(0x2a00_03e0 | (rn << 16) | rd)
}

fn a64_mov_reg64_word(rd: u32, rn: u32) -> Result<u32> {
    if rd >= 32 || rn >= 32 {
        bail!("arm64 MOV x register out of range: x{rd}, x{rn}");
    }
    Ok(0xaa00_03e0 | (rn << 16) | rd)
}

fn a64_ldp_post64(rt: u32, rt2: u32, byte_off: i32) -> Result<u32> {
    if rt >= 32 || rt2 >= 32 {
        bail!("arm64 LDP post register out of range: x{rt}, x{rt2}");
    }
    if byte_off % 8 != 0 {
        bail!("arm64 LDP post offset is not 8-byte aligned: {byte_off}");
    }
    let imm7 = byte_off / 8;
    if !(-64..=63).contains(&imm7) {
        bail!("arm64 LDP post offset out of range: {byte_off}");
    }
    Ok(0xa8c0_0000 | (((imm7 as u32) & 0x7f) << 15) | (rt2 << 10) | (31 << 5) | rt)
}

fn a64_madd64(rd: u32, rn: u32, rm: u32, ra: u32) -> Result<u32> {
    if rd >= 32 || rn >= 32 || rm >= 32 || ra >= 32 {
        bail!("arm64 MADD register out of range: x{rd}, x{rn}, x{rm}, x{ra}");
    }
    Ok(0x9b00_0000 | (rm << 16) | (ra << 10) | (rn << 5) | rd)
}

fn a64_movz(reg: u32, imm16: u16, shift: u32) -> Result<u32> {
    if reg >= 32 {
        bail!("arm64 MOVZ register out of range: x{reg}");
    }
    if shift % 16 != 0 || shift > 48 {
        bail!("arm64 MOVZ shift out of range: {shift}");
    }
    Ok(0xd280_0000 | ((shift / 16) << 21) | ((imm16 as u32) << 5) | reg)
}

fn a64_movn(reg: u32, imm16: u16, shift: u32) -> Result<u32> {
    if reg >= 32 {
        bail!("arm64 MOVN register out of range: x{reg}");
    }
    if shift % 16 != 0 || shift > 48 {
        bail!("arm64 MOVN shift out of range: {shift}");
    }
    Ok(0x9280_0000 | ((shift / 16) << 21) | ((imm16 as u32) << 5) | reg)
}

fn a64_movk(reg: u32, imm16: u16, shift: u32) -> Result<u32> {
    if reg >= 32 {
        bail!("arm64 MOVK register out of range: x{reg}");
    }
    if shift % 16 != 0 || shift > 48 {
        bail!("arm64 MOVK shift out of range: {shift}");
    }
    Ok(0xf280_0000 | ((shift / 16) << 21) | ((imm16 as u32) << 5) | reg)
}

fn arm64_mov_imm64_sequence(reg: u32, value: u64) -> Result<Vec<u32>> {
    let mut chunks = [0u16; 4];
    for (i, chunk) in chunks.iter_mut().enumerate() {
        *chunk = ((value >> (i * 16)) & 0xffff) as u16;
    }

    let mut best: Option<(bool, usize, usize)> = None;
    for use_movn in [false, true] {
        for lane in 0..4 {
            let mut cost = 1usize;
            for i in 0..4 {
                if i == lane {
                    continue;
                }
                let base_chunk = if use_movn { 0xffff } else { 0 };
                if chunks[i] != base_chunk {
                    cost += 1;
                }
            }
            if best.is_none_or(|(_, _, best_cost)| cost < best_cost) {
                best = Some((use_movn, lane, cost));
            }
        }
    }

    let (use_movn, lane, _) = best.ok_or_else(|| anyhow!("arm64 mov immediate sequence empty"))?;
    let mut words = Vec::with_capacity(4);
    let first = if use_movn {
        a64_movn(reg, !chunks[lane], (lane as u32) * 16)?
    } else {
        a64_movz(reg, chunks[lane], (lane as u32) * 16)?
    };
    words.push(first);
    for (i, chunk) in chunks.iter().copied().enumerate() {
        if i == lane {
            continue;
        }
        let base_chunk = if use_movn { 0xffff } else { 0 };
        if chunk != base_chunk {
            words.push(a64_movk(reg, chunk, (i as u32) * 16)?);
        }
    }
    Ok(words)
}

fn arm64_helper_call_sequence(slot: Arm64HelperCallSlot) -> Result<(Vec<u32>, usize)> {
    match slot {
        Arm64HelperCallSlot::FarSafe => {
            bail!("arm64 far_safe helper calls must use literal-pool loads")
        }
        Arm64HelperCallSlot::DirectOrFar => {
            Ok((vec![A64_BL_IMM26_PLACEHOLDER, A64_NOP, A64_NOP, A64_NOP], 0))
        }
        Arm64HelperCallSlot::Bl26 => Ok((vec![A64_BL_IMM26_PLACEHOLDER], 0)),
    }
}

fn arm64_helper_call_reloc_kind(slot: Arm64HelperCallSlot) -> Result<u32> {
    match slot {
        Arm64HelperCallSlot::FarSafe => {
            bail!("arm64 far_safe helper calls must not emit helper relocations")
        }
        Arm64HelperCallSlot::DirectOrFar => Ok(NATIVE_LAB_RELOC_HELPER_CALL_ARM64),
        Arm64HelperCallSlot::Bl26 => Ok(NATIVE_LAB_RELOC_HELPER_CALL_ARM64_BL26),
    }
}

fn record_arm64_percpu_mrs_relocs(
    words: &[u32],
    emit_byte_offset: usize,
    native_relocs: &mut Vec<RelocRecord>,
) -> Result<()> {
    for (word_index, word) in words.iter().copied().enumerate() {
        if word != A64_MRS_X10_TPIDR_EL1 {
            continue;
        }
        let reloc_offset = emit_byte_offset
            .checked_add(word_index * 4)
            .ok_or_else(|| anyhow!("arm64 percpu MRS reloc offset overflow"))?;
        let offset = u32::try_from(reloc_offset)
            .map_err(|_| anyhow!("arm64 percpu MRS reloc offset exceeds u32"))?;
        native_relocs.push(RelocRecord {
            offset,
            kind: NATIVE_LAB_RELOC_ARM64_PERCPU_MRS,
            target: 0,
        });
    }
    Ok(())
}

fn arm64_required_u32_helper_arg(
    helper_addrs: &HashMap<String, u64>,
    key: &str,
    label: &str,
) -> Result<u32> {
    let value = *helper_addrs
        .get(key)
        .ok_or_else(|| anyhow!("arm64 tail_call lowering missing link-plan helper {key}"))?;
    u32::try_from(value).map_err(|_| anyhow!("{label} does not fit u32: {value:#x}"))
}

fn build_arm64_get_smp_processor_id_inline(
    helper_addrs: &HashMap<String, u64>,
) -> Result<Option<Vec<u32>>> {
    const X0: u32 = 0;
    const X16: u32 = 16;

    let Some(&cpu_offset) = helper_addrs.get(ARM64_THREAD_INFO_CPU_OFFSET_HELPER_KEY) else {
        return Ok(None);
    };
    let cpu_offset = u32::try_from(cpu_offset)
        .map_err(|_| anyhow!("arm64 thread_info.cpu offset does not fit u32: {cpu_offset}"))?;
    Ok(Some(vec![
        a64_mrs_sp_el0(X16)?,
        a64_ldr_u32(X0, X16, cpu_offset)?,
    ]))
}

fn build_arm64_get_current_task_inline() -> Result<Vec<u32>> {
    const X0: u32 = 0;

    Ok(vec![a64_mrs_sp_el0(X0)?])
}

fn build_arm64_array_lookup(spec: &LookupSiteSpec) -> Result<Vec<u32>> {
    const X0: u32 = 0;
    const X1: u32 = 1;
    const X8: u32 = 8;
    const X9: u32 = 9;
    const X10: u32 = 10;
    const A64_MOV_X0_XZR: u32 = 0xaa1f_03e0;

    if spec.max_entries == 0 {
        bail!("arm64 array lookup max_entries must be non-zero");
    }
    if spec.elem_size == 0 {
        bail!("arm64 array lookup elem_size must be non-zero");
    }

    let mut words = Vec::new();
    words.push(a64_add_imm64(X8, X0, spec.value_offset)?);
    words.push(a64_ldr_u32(X9, X1, 0)?);
    if let Ok(cmp) = a64_cmp_imm64(X9, spec.max_entries) {
        words.push(cmp);
    } else {
        words.extend(arm64_mov_imm64_sequence(X10, u64::from(spec.max_entries))?);
        words.push(a64_cmp_reg64(X9, X10)?);
    }

    let null_branch = words.len();
    words.push(0);
    if spec.elem_size.is_power_of_two() {
        let shift = spec.elem_size.trailing_zeros();
        words.push(a64_add_shift64(X0, X8, X9, shift)?);
    } else {
        words.extend(arm64_mov_imm64_sequence(X10, u64::from(spec.elem_size))?);
        words.push(a64_madd64(X0, X9, X10, X8)?);
    }

    if matches!(spec.kind, LookupKind::PerCpuArray) {
        words.push(a64_ldr_u64(X0, X0, 0)?);
        words.push(A64_MRS_X10_TPIDR_EL1);
        words.push(a64_add_shift64(X0, X0, X10, 0)?);
    }

    let done_branch = words.len();
    words.push(0);
    let null_target = words.len();
    words.push(A64_MOV_X0_XZR);
    let done_target = words.len();

    words[null_branch] = a64_patch_b_cond(0x5400_0002, null_branch, null_target)?;
    words[done_branch] = a64_patch_b(done_branch, done_target)?;
    Ok(words)
}

fn build_arm64_lookup_call_postprocess(spec: &LookupSiteSpec) -> Result<Vec<u32>> {
    const X0: u32 = 0;
    const X8: u32 = 8;
    const X10: u32 = 10;

    if matches!(
        spec.kind,
        LookupKind::Call | LookupKind::Array | LookupKind::PerCpuArray
    ) {
        return Ok(Vec::new());
    }

    let mut words = Vec::new();
    let null_branch = words.len();
    words.push(a64_cbz64(X0)?);
    match spec.kind {
        LookupKind::Hash => {
            words.push(a64_add_imm64(X0, X0, spec.key_offset)?);
        }
        LookupKind::HashOfMaps => {
            words.push(a64_add_imm64(X0, X0, spec.key_offset)?);
            words.push(a64_ldr_u64(X0, X0, 0)?);
        }
        LookupKind::LruHash => {
            words.push(a64_ldr_u8(X8, X0, spec.value_offset)?);
            let skip_store = words.len();
            words.push(a64_cbnz64(X8)?);
            words.extend(arm64_mov_imm64_sequence(X8, 1)?);
            words.push(a64_str_u8(X8, X0, spec.value_offset)?);
            let after_store = words.len();
            words[skip_store] = a64_patch_cbz_cbnz(words[skip_store], skip_store, after_store)?;
            words.push(a64_add_imm64(X0, X0, spec.key_offset)?);
        }
        LookupKind::PerCpuHash => {
            words.push(a64_add_imm64(X0, X0, spec.key_offset)?);
            words.push(a64_ldr_u64(X0, X0, 0)?);
            words.push(A64_MRS_X10_TPIDR_EL1);
            words.push(a64_add_shift64(X0, X0, X10, 0)?);
        }
        LookupKind::Call | LookupKind::Array | LookupKind::PerCpuArray => {}
    }
    let done = words.len();
    words[null_branch] = a64_patch_cbz_cbnz(words[null_branch], null_branch, done)?;
    Ok(words)
}

fn append_arm64_stub_callee_pop(words: &mut Vec<u32>, callee_saved_mask: u8) -> Result<()> {
    if callee_saved_mask > 0xf {
        bail!("arm64 tail_call callee-saved mask exceeds 4 bits");
    }
    let mut regs: Vec<u32> = [19u32, 20, 21, 22]
        .iter()
        .enumerate()
        .filter_map(|(idx, reg)| {
            if callee_saved_mask & (1 << idx) != 0 {
                Some(*reg)
            } else {
                None
            }
        })
        .collect();
    // The native_lab proof emits a BPF_FP stack store to reserve 512 bytes, so
    // the arm64 BPF JIT saves x25 even though it is not encoded in the sidecar
    // ABI mask. Tail-call success must pop it before the sidecar-requested regs.
    regs.push(25);
    let mut idx = regs.len();
    if idx % 2 != 0 {
        idx -= 1;
        words.push(a64_ldp_post64(regs[idx], 31, 16)?);
    }
    while idx > 0 {
        idx -= 2;
        words.push(a64_ldp_post64(regs[idx], regs[idx + 1], 16)?);
    }
    Ok(())
}

fn build_arm64_tail_call_inline(
    helper_addrs: &HashMap<String, u64>,
    callee_saved_mask: u8,
    native_cleanup_words: &[u32],
    tail_call_cnt_ptr_stack_offset: Option<u32>,
) -> Result<Vec<u32>> {
    const MAX_TAIL_CALL_CNT: u32 = 33;
    const X1: u32 = 1;
    const X2: u32 = 2;
    const X8: u32 = 8;
    const X9: u32 = 9;
    const X10: u32 = 10;
    const X11: u32 = 11;
    const X12: u32 = 12;
    const X26: u32 = 26;

    let map_max_entries = arm64_required_u32_helper_arg(
        helper_addrs,
        ARM64_BPF_MAP_MAX_ENTRIES_OFFSET_KEY,
        "struct bpf_map.max_entries offset",
    )?;
    let array_ptrs = arm64_required_u32_helper_arg(
        helper_addrs,
        ARM64_BPF_ARRAY_PTRS_OFFSET_KEY,
        "struct bpf_array.ptrs offset",
    )?;
    let prog_bpf_func = arm64_required_u32_helper_arg(
        helper_addrs,
        ARM64_BPF_PROG_BPF_FUNC_OFFSET_KEY,
        "struct bpf_prog.bpf_func offset",
    )?;
    let tail_call_offset = arm64_required_u32_helper_arg(
        helper_addrs,
        ARM64_TAIL_CALL_OFFSET_KEY,
        "arm64 BPF tail-call entry offset",
    )?;
    if native_cleanup_words.is_empty() {
        bail!("arm64 bpf_tail_call lowering missing entry cleanup sequence");
    }

    let mut words = Vec::new();
    let map_kernel_branch = words.len();
    words.push(a64_tbz64(X1, 63)?);
    words.push(a64_ldr_u32(X8, X1, map_max_entries)?);
    words.push(a64_mov_reg32(X2, X2)?);
    words.push(a64_cmp_reg32(X2, X8)?);
    let bounds_branch = words.len();
    words.push(0);

    if let Some(offset) = tail_call_cnt_ptr_stack_offset {
        words.push(a64_ldr_u64(X9, 31, offset)?);
    } else {
        words.push(a64_mov_reg64_word(X9, X26)?);
    }
    words.push(a64_ldr_u64(X12, X9, 0)?);
    words.push(a64_cmp_imm64(X12, MAX_TAIL_CALL_CNT)?);
    let limit_branch = words.len();
    words.push(0);

    words.push(a64_add_imm64(X8, X1, array_ptrs)?);
    words.push(a64_add_shift64(X8, X8, X2, 3)?);
    words.push(a64_ldr_u64(X11, X8, 0)?);
    let null_branch = words.len();
    words.push(a64_cbz64(X11)?);
    let prog_kernel_branch = words.len();
    words.push(a64_tbz64(X11, 63)?);

    words.push(a64_ldr_u64(X10, X11, prog_bpf_func)?);
    words.push(a64_add_imm64(X10, X10, tail_call_offset)?);
    let target_kernel_branch = words.len();
    words.push(a64_tbz64(X10, 63)?);

    words.push(a64_add_imm64(X12, X12, 1)?);
    words.push(a64_str_u64(X12, X9, 0)?);
    words.extend_from_slice(native_cleanup_words);
    words.push(a64_add_imm64(31, 31, ARM64_NATIVE_LAB_STACK_RESERVE_BYTES)?);
    append_arm64_stub_callee_pop(&mut words, callee_saved_mask)?;
    words.push(a64_br(X10)?);

    let out = words.len();
    words[map_kernel_branch] =
        a64_patch_tbz_tbnz(words[map_kernel_branch], map_kernel_branch, out)?;
    words[bounds_branch] = a64_patch_b_cond(0x5400_0002, bounds_branch, out)?;
    words[limit_branch] = a64_patch_b_cond(0x5400_0002, limit_branch, out)?;
    words[null_branch] = a64_patch_cbz_cbnz(words[null_branch], null_branch, out)?;
    words[prog_kernel_branch] =
        a64_patch_tbz_tbnz(words[prog_kernel_branch], prog_kernel_branch, out)?;
    words[target_kernel_branch] =
        a64_patch_tbz_tbnz(words[target_kernel_branch], target_kernel_branch, out)?;
    if words.len() > 64 {
        bail!(
            "arm64 bpf_tail_call lowering produced {} instructions, exceeding native_lab per-chunk limit",
            words.len()
        );
    }
    Ok(words)
}

fn append_arm64_array_value_ptr(
    words: &mut Vec<u32>,
    dst_reg: u32,
    map_reg: u32,
    key_reg: u32,
    scratch_reg: u32,
    elem_size: u32,
    value_offset: u32,
) -> Result<()> {
    words.push(a64_add_imm64(dst_reg, map_reg, value_offset)?);
    if elem_size.is_power_of_two() {
        words.push(a64_add_shift64(
            dst_reg,
            dst_reg,
            key_reg,
            elem_size.trailing_zeros(),
        )?);
    } else {
        words.extend(arm64_mov_imm64_sequence(scratch_reg, u64::from(elem_size))?);
        words.push(a64_madd64(dst_reg, key_reg, scratch_reg, dst_reg)?);
    }
    Ok(())
}

fn append_arm64_copy_value(words: &mut Vec<u32>, dst_reg: u32, src_reg: u32) -> Result<()> {
    const X10: u32 = 10;

    words.push(a64_ldr_u64(X10, src_reg, 0)?);
    words.push(a64_str_u64(X10, dst_reg, 0)?);
    Ok(())
}

fn append_arm64_copy_value_size(
    words: &mut Vec<u32>,
    dst_reg: u32,
    src_reg: u32,
    value_size: u32,
) -> Result<()> {
    const X10: u32 = 10;

    match value_size {
        1 => {
            words.push(a64_ldr_u8(X10, src_reg, 0)?);
            words.push(a64_str_u8(X10, dst_reg, 0)?);
        }
        2 => {
            words.push(a64_ldr_u16(X10, src_reg, 0)?);
            words.push(a64_str_u16(X10, dst_reg, 0)?);
        }
        4 => {
            words.push(a64_ldr_u32(X10, src_reg, 0)?);
            words.push(a64_str_u32(X10, dst_reg, 0)?);
        }
        8 => append_arm64_copy_value(words, dst_reg, src_reg)?,
        _ => bail!("unsupported arm64 array update value size: {value_size}"),
    }
    Ok(())
}

fn append_arm64_mov_i64(words: &mut Vec<u32>, reg: u32, value: i64) -> Result<()> {
    words.extend(arm64_mov_imm64_sequence(reg, value as u64)?);
    Ok(())
}

fn build_arm64_array_update(spec: &UpdateSiteSpec) -> Result<Vec<u32>> {
    const X0: u32 = 0;
    const X1: u32 = 1;
    const X2: u32 = 2;
    const X3: u32 = 3;
    const X8: u32 = 8;
    const X9: u32 = 9;
    const X10: u32 = 10;
    const A64_MOV_X0_XZR: u32 = 0xaa1f_03e0;

    if !matches!(spec.kind, UpdateKind::Array | UpdateKind::PerCpuArray) {
        bail!(
            "update kind {:?} is not an arm64 array-style inline",
            spec.kind
        );
    }
    if spec.max_entries == 0 {
        bail!("arm64 array update max_entries must be non-zero");
    }
    if spec.elem_size == 0 {
        bail!("arm64 array update elem_size must be non-zero");
    }
    if !matches!(spec.value_size, 1 | 2 | 4 | 8) {
        bail!("arm64 array update value_size must be 1, 2, 4, or 8");
    }

    let mut words = Vec::new();
    words.push(a64_ldr_u32(X9, X1, 0)?);
    if let Ok(cmp) = a64_cmp_imm64(X9, spec.max_entries) {
        words.push(cmp);
    } else {
        words.extend(arm64_mov_imm64_sequence(X10, u64::from(spec.max_entries))?);
        words.push(a64_cmp_reg64(X9, X10)?);
    }
    let bounds_branch = words.len();
    words.push(0);

    words.push(a64_cmp_imm64(X3, 1)?);
    let eexist_branch = words.len();
    words.push(0);
    words.push(a64_cmp_imm64(X3, 2)?);
    let invalid_branch = words.len();
    words.push(0);

    append_arm64_array_value_ptr(
        &mut words,
        X8,
        X0,
        X9,
        X10,
        spec.elem_size,
        spec.value_offset,
    )?;
    if matches!(spec.kind, UpdateKind::PerCpuArray) {
        words.push(a64_ldr_u64(X8, X8, 0)?);
        words.push(A64_MRS_X10_TPIDR_EL1);
        words.push(a64_add_shift64(X8, X8, X10, 0)?);
    }
    append_arm64_copy_value_size(&mut words, X8, X2, spec.value_size)?;
    words.push(A64_MOV_X0_XZR);
    let success_end_branch = words.len();
    words.push(0);

    let bounds_target = words.len();
    append_arm64_mov_i64(&mut words, X0, -7)?;
    let bounds_end_branch = words.len();
    words.push(0);

    let eexist_target = words.len();
    append_arm64_mov_i64(&mut words, X0, -17)?;
    let eexist_end_branch = words.len();
    words.push(0);

    let invalid_target = words.len();
    append_arm64_mov_i64(&mut words, X0, -22)?;
    let end_target = words.len();

    words[bounds_branch] = a64_patch_b_cond(0x5400_0002, bounds_branch, bounds_target)?;
    words[eexist_branch] = a64_patch_b_cond(0x5400_0000, eexist_branch, eexist_target)?;
    words[invalid_branch] = a64_patch_b_cond(0x5400_0008, invalid_branch, invalid_target)?;
    words[success_end_branch] = a64_patch_b(success_end_branch, end_target)?;
    words[bounds_end_branch] = a64_patch_b(bounds_end_branch, end_target)?;
    words[eexist_end_branch] = a64_patch_b(eexist_end_branch, end_target)?;
    Ok(words)
}

fn append_u32(blob: &mut Vec<u8>, word: u32) {
    blob.extend_from_slice(&word.to_le_bytes());
}

fn append_u64(blob: &mut Vec<u8>, value: u64) {
    blob.extend_from_slice(&value.to_le_bytes());
}

fn align_arm64_blob_to_8(blob: &mut Vec<u8>) {
    let rem = blob.len() % 8;
    if rem == 0 {
        return;
    }
    if rem == 4 {
        append_u32(blob, A64_NOP);
    } else {
        blob.resize(blob.len() + (8 - rem), 0);
    }
}

fn arm64_append_literal(blob: &mut Vec<u8>, value: u64) -> usize {
    align_arm64_blob_to_8(blob);
    let offset = blob.len();
    append_u64(blob, value);
    offset
}

fn arm64_append_section_data(
    elf: &object::File,
    section_index: object::SectionIndex,
    blob: &mut Vec<u8>,
    local_data: &mut HashMap<object::SectionIndex, usize>,
) -> Result<usize> {
    if let Some(&offset) = local_data.get(&section_index) {
        return Ok(offset);
    }
    align_arm64_blob_to_8(blob);
    let offset = blob.len();
    let section = elf
        .section_by_index(section_index)
        .with_context(|| format!("arm64 local data section {section_index:?}"))?;
    let data = arm64_section_materialized_data(&section)
        .with_context(|| format!("read arm64 local data section {section_index:?}"))?;
    if data.is_empty() {
        bail!("arm64 local data section {section_index:?} is empty");
    }
    blob.extend_from_slice(&data);
    local_data.insert(section_index, offset);
    Ok(offset)
}

fn arm64_section_materialized_data(section: &object::Section) -> Result<Vec<u8>> {
    let data = section.data().context("read section data")?;
    let size = usize::try_from(section.size()).context("section size does not fit usize")?;
    if data.len() > size {
        bail!(
            "section data length {} exceeds memory size {}",
            data.len(),
            size
        );
    }
    if data.len() == size {
        return Ok(data.to_vec());
    }
    if !section.kind().is_bss() {
        bail!(
            "initialized section data length {} is shorter than memory size {}",
            data.len(),
            size
        );
    }
    let mut materialized = data.to_vec();
    materialized.resize(size, 0);
    Ok(materialized)
}

const R_AARCH64_ADR_PREL_PG_HI21: u32 = 275;
const R_AARCH64_ADD_ABS_LO12_NC: u32 = 277;
const R_AARCH64_CALL26: u32 = 283;
const R_AARCH64_ADR_GOT_PAGE: u32 = 311;
const R_AARCH64_LD64_GOT_LO12_NC: u32 = 312;

type Arm64AddressKey = (object::SectionIndex, u64);
type Arm64RelocKey = (Arm64AddressKey, u64);

#[derive(Clone, Debug)]
struct Arm64RelocInfo {
    r_type: u32,
    target_name: String,
    target_section_index: Option<object::SectionIndex>,
    target_address: Option<u64>,
    addend: i64,
}

fn arm64_text_relocations(
    elf: &object::File,
    included: &[SymInfo],
) -> Result<HashMap<Arm64RelocKey, Arm64RelocInfo>> {
    let mut out = HashMap::new();
    let mut sections: HashMap<object::SectionIndex, Vec<&SymInfo>> = HashMap::new();
    for sym in included {
        sections.entry(sym.section_index).or_default().push(sym);
    }
    for (section_index, syms) in sections {
        let section = elf
            .section_by_index(section_index)
            .with_context(|| format!("section {section_index:?}"))?;
        let section_addr = section.address();
        for (reloc_offset, reloc) in section.relocations() {
            let reloc_addr = section_addr + reloc_offset;
            let Some(sym) = syms
                .iter()
                .find(|s| reloc_addr >= s.address && reloc_addr < s.address + s.size)
            else {
                continue;
            };
            let r_type = match reloc.flags() {
                RelocationFlags::Elf { r_type } => r_type,
                _ => continue,
            };
            let addend = reloc.addend();
            let (target_name, target_section_index, target_address) = match reloc.target() {
                RelocationTarget::Symbol(idx) => {
                    let target_sym = elf.symbol_by_index(idx)?;
                    let target_section_index = target_sym.section_index();
                    let target_address = if target_section_index.is_some() && addend >= 0 {
                        Some(
                            target_sym
                                .address()
                                .checked_add(addend as u64)
                                .ok_or_else(|| {
                                    anyhow!(
                                        "arm64 relocation target address overflow for addend {addend}"
                                    )
                                })?,
                        )
                    } else {
                        None
                    };
                    let raw_name = target_sym
                        .name()
                        .map_err(|e| anyhow!("reloc target symbol name: {e}"))?;
                    let target_name = if raw_name.is_empty() {
                        format!(
                            "__arm64_section_{:?}_addend_{}",
                            target_section_index, addend
                        )
                    } else {
                        raw_name.to_string()
                    };
                    (target_name, target_section_index, target_address)
                }
                _ => continue,
            };
            out.insert(
                ((sym.section_index, sym.address), reloc_addr - sym.address),
                Arm64RelocInfo {
                    r_type,
                    target_name,
                    target_section_index,
                    target_address,
                    addend,
                },
            );
        }
    }
    Ok(out)
}

fn arm64_reloc_data(elf: &object::File, reloc: &Arm64RelocInfo, max_len: usize) -> Result<Vec<u8>> {
    let section_index = reloc.target_section_index.ok_or_else(|| {
        anyhow!(
            "arm64 proof data relocation {} has no target section",
            reloc.target_name
        )
    })?;
    if reloc.addend < 0 {
        bail!(
            "arm64 proof data relocation {} has negative addend {}",
            reloc.target_name,
            reloc.addend
        );
    }
    let section = elf
        .section_by_index(section_index)
        .with_context(|| format!("arm64 proof data section {section_index:?}"))?;
    let data = arm64_section_materialized_data(&section)
        .with_context(|| format!("read arm64 proof data section {section_index:?}"))?;
    let start = reloc.addend as usize;
    if start >= data.len() {
        bail!(
            "arm64 proof data relocation {} addend {} exceeds section size {}",
            reloc.target_name,
            reloc.addend,
            data.len()
        );
    }
    let end = data.len().min(start + max_len);
    Ok(data[start..end].to_vec())
}

fn arm64_local_call_target(reloc: &Arm64RelocInfo) -> Option<Arm64AddressKey> {
    if reloc.r_type != R_AARCH64_CALL26 {
        return None;
    }
    Some((reloc.target_section_index?, reloc.target_address?))
}

fn arm64_proof_reloc_addend(reloc: &Arm64RelocInfo) -> i64 {
    if reloc.target_name.starts_with("__arm64_section_") {
        0
    } else {
        reloc.addend
    }
}

fn discover_reachable_arm64(elf: &object::File, entry: &SymInfo) -> Result<Vec<SymInfo>> {
    let mut included: Vec<SymInfo> = vec![entry.clone()];
    let mut seen: std::collections::HashSet<Arm64AddressKey> =
        [(entry.section_index, entry.address)].into_iter().collect();
    let mut queue: Vec<SymInfo> = vec![entry.clone()];

    while let Some(sym) = queue.pop() {
        let bytes = read_symbol_bytes(elf, &sym)?;
        if bytes.len() % 4 != 0 {
            bail!("arm64 symbol {} size must be a multiple of 4", sym.name);
        }
        let relocs = arm64_text_relocations(elf, std::slice::from_ref(&sym))?;
        for (word_index, word) in bytes.chunks_exact(4).enumerate() {
            let insn = u32::from_le_bytes(word.try_into().unwrap());
            let reloc = relocs.get(&((sym.section_index, sym.address), (word_index * 4) as u64));
            let (target_section_index, target_address) =
                if let Some(reloc) = reloc.filter(|reloc| reloc.r_type == R_AARCH64_CALL26) {
                    let Some((section_index, address)) = arm64_local_call_target(reloc) else {
                        continue;
                    };
                    (section_index, address)
                } else {
                    let Some(target) = a64_bl_target(sym.address, word_index, insn) else {
                        continue;
                    };
                    (sym.section_index, target)
                };
            let target_key = (target_section_index, target_address);
            if seen.contains(&target_key) {
                continue;
            }
            let called =
                find_symbol_at_section_address(elf, target_section_index, target_address)
                    .ok_or_else(|| {
                        anyhow!(
                            "{} calls {target_address:#x} in section {:?} but no symbol covers that address",
                            sym.name,
                            target_section_index
                        )
                    })?;
            if called.address != target_address {
                bail!(
                    "{} calls {target_address:#x}, which lands inside {} at {:#x}",
                    sym.name,
                    called.name,
                    called.address
                );
            }
            if seen.insert((called.section_index, called.address)) {
                included.push(called.clone());
                queue.push(called);
            }
        }
    }
    Ok(included)
}

#[derive(Clone)]
enum Arm64PatchKind {
    ReturnToTrampoline,
    Bl {
        target_symbol: Arm64AddressKey,
    },
    B {
        source_symbol: Arm64AddressKey,
        target_is_symbol_end: bool,
        target_address: u64,
    },
    BCond {
        insn: u32,
        source_symbol: Arm64AddressKey,
        target_is_symbol_end: bool,
        target_address: u64,
    },
    CbzCbnz {
        insn: u32,
        source_symbol: Arm64AddressKey,
        target_is_symbol_end: bool,
        target_address: u64,
    },
    TbzTbnz {
        insn: u32,
        source_symbol: Arm64AddressKey,
        target_is_symbol_end: bool,
        target_address: u64,
    },
    MapLiteralLoad {
        target_name: String,
    },
    LocalDataAdr {
        target_name: String,
        section_index: object::SectionIndex,
        addend: i64,
    },
    Nop,
}

struct Arm64Patch {
    word_index: usize,
    kind: Arm64PatchKind,
}

#[derive(Default)]
struct Arm64EntryAbiStrip {
    nop_word_indices: HashSet<usize>,
    callee_saved_mask: u8,
    tail_call_cleanup_words: Vec<u32>,
    tail_call_cnt_ptr_stack_offset: Option<u32>,
}

fn plan_arm64_entry_abi_strip(bytes: &[u8]) -> Result<Arm64EntryAbiStrip> {
    let mut out = Arm64EntryAbiStrip::default();
    let mut save_offsets: [Option<i32>; 4] = [None; 4];
    let mut restore_counts = [0i32; 4];
    let mut lr_save_offset: Option<i32> = None;
    let mut lr_restore_count = 0i32;
    out.tail_call_cnt_ptr_stack_offset = arm64_saved_reg_stack_offset(bytes, 26);

    for (word_index, word) in bytes.chunks_exact(4).enumerate() {
        let insn = u32::from_le_bytes(word.try_into().unwrap());
        if word_index == 0 && arm64_is_sp_sub_imm(insn) {
            continue;
        }
        if let Some((is_load, offset, rt, rt2)) = arm64_stp_ldp_pair(insn) {
            if is_load {
                break;
            }
            if arm64_entry_pair_is_frame_record(rt, rt2) {
                continue;
            }
            if arm64_entry_pair_is_strippable(rt, rt2) {
                out.nop_word_indices.insert(word_index);
                for reg in [rt, rt2] {
                    arm64_record_entry_save(&mut save_offsets, &mut lr_save_offset, offset, reg)?;
                }
                continue;
            }
            arm64_reject_unsupported_entry_save(rt)?;
            arm64_reject_unsupported_entry_save(rt2)?;
            if arm64_entry_pair_is_preserved_by_native(rt, rt2) {
                continue;
            }
            if arm64_entry_pair_is_frame_record(rt, rt2) {
                continue;
            }
            break;
        }
        if let Some((is_load, offset, rt)) = arm64_ldr_str_unsigned64_sp(insn) {
            if is_load {
                break;
            }
            let offset = i32::try_from(offset).context("arm64 entry save offset exceeds i32")?;
            if arm64_entry_reg_is_strippable(rt) {
                out.nop_word_indices.insert(word_index);
                arm64_record_entry_save(&mut save_offsets, &mut lr_save_offset, offset, rt)?;
                continue;
            }
            arm64_reject_unsupported_entry_save(rt)?;
            if arm64_entry_reg_is_preserved_by_native(rt) {
                continue;
            }
        }
        break;
    }

    for (word_index, word) in bytes.chunks_exact(4).enumerate() {
        let insn = u32::from_le_bytes(word.try_into().unwrap());
        if let Some((is_load, offset, rt, rt2)) = arm64_stp_ldp_pair(insn) {
            if !is_load {
                continue;
            }
            if arm64_entry_pair_is_frame_record(rt, rt2) {
                continue;
            }
            if !arm64_entry_pair_is_strippable(rt, rt2) {
                continue;
            }

            let mut matches_saved_slot = false;
            for reg in [rt, rt2] {
                matches_saved_slot |= arm64_record_entry_restore(
                    &mut restore_counts,
                    &mut lr_restore_count,
                    &save_offsets,
                    lr_save_offset,
                    offset,
                    reg,
                );
            }
            if matches_saved_slot {
                out.nop_word_indices.insert(word_index);
            }
            continue;
        }

        if let Some((is_load, offset, rt)) = arm64_ldr_str_unsigned64_sp(insn) {
            if !is_load || !arm64_entry_reg_is_strippable(rt) {
                continue;
            }
            let offset = i32::try_from(offset).context("arm64 entry restore offset exceeds i32")?;
            if arm64_record_entry_restore(
                &mut restore_counts,
                &mut lr_restore_count,
                &save_offsets,
                lr_save_offset,
                offset,
                rt,
            ) {
                out.nop_word_indices.insert(word_index);
            }
        }
    }

    if lr_save_offset.is_some() && lr_restore_count == 0 {
        bail!(
            "arm64 entry ABI strip found unbalanced save/restore for x30: saves=1, restores={}",
            lr_restore_count
        );
    }
    for (idx, save_offset) in save_offsets.iter().enumerate() {
        let Some(_offset) = save_offset else {
            continue;
        };
        if restore_counts[idx] == 0 {
            bail!(
                "arm64 entry ABI strip found unbalanced save/restore for x{}: saves=1, restores={}",
                19 + idx,
                restore_counts[idx]
            );
        }
        out.callee_saved_mask |= 1u8 << idx;
    }

    Ok(out)
}

fn arm64_record_entry_save(
    save_offsets: &mut [Option<i32>; 4],
    lr_save_offset: &mut Option<i32>,
    offset: i32,
    reg: u32,
) -> Result<()> {
    if reg == 30 {
        if lr_save_offset.replace(offset).is_some() {
            bail!("arm64 entry ABI strip found multiple prologue save sites for x30");
        }
        return Ok(());
    }
    let Some(bit_index) = arm64_callee_saved_bit_index(reg) else {
        return Ok(());
    };
    if save_offsets[bit_index].replace(offset).is_some() {
        bail!(
            "arm64 entry ABI strip found multiple prologue save sites for x{}",
            19 + bit_index
        );
    }
    Ok(())
}

fn arm64_record_entry_restore(
    restore_counts: &mut [i32; 4],
    lr_restore_count: &mut i32,
    save_offsets: &[Option<i32>; 4],
    lr_save_offset: Option<i32>,
    offset: i32,
    reg: u32,
) -> bool {
    if reg == 30 {
        if lr_save_offset == Some(offset) {
            *lr_restore_count += 1;
            return true;
        }
        return false;
    }
    if let Some(bit_index) = arm64_callee_saved_bit_index(reg) {
        if save_offsets[bit_index] == Some(offset) {
            restore_counts[bit_index] += 1;
            return true;
        }
    }
    false
}

fn plan_arm64_tail_call_cleanup(
    elf: &object::File,
    sym: &SymInfo,
    bytes: &[u8],
    nop_word_indices: &HashSet<usize>,
) -> Result<Vec<u32>> {
    let mut terminators = Vec::new();
    for (word_index, word) in bytes.chunks_exact(4).enumerate() {
        let insn = u32::from_le_bytes(word.try_into().unwrap());
        if a64_is_ret(insn) {
            terminators.push(word_index);
            continue;
        }
        let Some(target) = a64_branch_target(sym.address, word_index, insn) else {
            continue;
        };
        if arm64_is_return_trampoline_target(elf, target)? {
            terminators.push(word_index);
        }
    }
    plan_arm64_tail_call_cleanup_from_terminators(bytes, &terminators, nop_word_indices)
}

fn arm64_symbol_has_tail_call(
    bytes: &[u8],
    sym: &SymInfo,
    relocs: &HashMap<Arm64RelocKey, Arm64RelocInfo>,
) -> bool {
    let sym_key = (sym.section_index, sym.address);
    let mut helper_imm_registers: [Option<u64>; 32] = std::array::from_fn(|_| None);
    for (word_index, word) in bytes.chunks_exact(4).enumerate() {
        let off = (word_index * 4) as u64;
        if relocs.get(&(sym_key, off)).is_some_and(|reloc| {
            reloc.r_type == R_AARCH64_CALL26 && reloc.target_name == "bpf_tail_call"
        }) {
            return true;
        }

        let insn = u32::from_le_bytes(word.try_into().unwrap());
        let helper_imm_load_reg = if let Some((reg, helper_id)) = a64_known_helper_id_load(insn) {
            helper_imm_registers[reg] = Some(helper_id);
            Some(reg)
        } else {
            None
        };
        if let Some(reg) = a64_blr_reg(insn) {
            if helper_imm_registers[reg] == Some(12) {
                return true;
            }
            for slot in helper_imm_registers.iter_mut().take(19) {
                *slot = None;
            }
        }
        for reg in a64_written_gprs(insn).into_iter().flatten() {
            if helper_imm_load_reg != Some(reg) {
                helper_imm_registers[reg] = None;
            }
        }
    }
    false
}

fn arm64_reloc_written_gpr(reloc: &Arm64RelocInfo, insn: u32) -> Option<usize> {
    match reloc.r_type {
        R_AARCH64_ADR_PREL_PG_HI21
        | R_AARCH64_ADD_ABS_LO12_NC
        | R_AARCH64_ADR_GOT_PAGE
        | R_AARCH64_LD64_GOT_LO12_NC => Some((insn & 0x1f) as usize),
        _ => None,
    }
}

fn arm64_word_at(bytes: &[u8], word_index: usize) -> Option<u32> {
    let start = word_index.checked_mul(4)?;
    Some(u32::from_le_bytes(
        bytes.get(start..start + 4)?.try_into().ok()?,
    ))
}

fn arm64_insn_writes_reg(insn: u32, reloc: Option<&Arm64RelocInfo>, reg: usize) -> bool {
    if a64_written_gprs(insn)
        .into_iter()
        .flatten()
        .any(|r| r == reg)
    {
        return true;
    }
    reloc.and_then(|reloc| arm64_reloc_written_gpr(reloc, insn)) == Some(reg)
}

fn arm64_branch_word_target(sym: &SymInfo, word_index: usize, insn: u32) -> Option<usize> {
    let target = a64_branch_target(sym.address, word_index, insn)?;
    if target < sym.address {
        return None;
    }
    let local = target.checked_sub(sym.address)?;
    if local % 4 != 0 || local > sym.size {
        return None;
    }
    Some((local / 4) as usize)
}

fn arm64_successors_for_helper_reachability(
    sym: &SymInfo,
    word_count: usize,
    word_index: usize,
    insn: u32,
    tracked_reg: usize,
) -> Vec<usize> {
    if a64_is_ret(insn) {
        return Vec::new();
    }
    if a64_is_bl(insn) || a64_blr_reg(insn).is_some() {
        return if tracked_reg < 19 && word_index + 1 < word_count {
            Vec::new()
        } else if word_index + 1 < word_count {
            vec![word_index + 1]
        } else {
            Vec::new()
        };
    }
    if a64_is_uncond_b(insn) {
        return arm64_branch_word_target(sym, word_index, insn)
            .filter(|&target| target < word_count)
            .into_iter()
            .collect();
    }
    if a64_is_b_cond(insn) || a64_is_cbz_cbnz(insn) || a64_is_tbz_tbnz(insn) {
        let mut out = Vec::new();
        if let Some(target) = arm64_branch_word_target(sym, word_index, insn) {
            if target < word_count {
                out.push(target);
            }
        }
        if word_index + 1 < word_count {
            out.push(word_index + 1);
        }
        out.sort_unstable();
        out.dedup();
        return out;
    }
    if word_index + 1 < word_count {
        vec![word_index + 1]
    } else {
        Vec::new()
    }
}

fn arm64_reachable_helper_id_for_blr(
    bytes: &[u8],
    sym: &SymInfo,
    relocs: &HashMap<Arm64RelocKey, Arm64RelocInfo>,
    call_word_index: usize,
    reg: usize,
) -> Option<u64> {
    let word_count = bytes.len() / 4;
    for candidate in (0..call_word_index).rev() {
        let insn = arm64_word_at(bytes, candidate)?;
        let Some((candidate_reg, helper_id)) = a64_known_helper_id_load(insn) else {
            continue;
        };
        if candidate_reg != reg {
            continue;
        }
        let mut stack = Vec::new();
        let mut seen = HashSet::new();
        if candidate + 1 < word_count {
            stack.push(candidate + 1);
        }
        while let Some(word_index) = stack.pop() {
            if word_index == call_word_index {
                return Some(helper_id);
            }
            if !seen.insert(word_index) {
                continue;
            }
            let insn = arm64_word_at(bytes, word_index)?;
            let reloc = relocs.get(&((sym.section_index, sym.address), (word_index * 4) as u64));
            if arm64_insn_writes_reg(insn, reloc, reg) {
                continue;
            }
            stack.extend(arm64_successors_for_helper_reachability(
                sym, word_count, word_index, insn, reg,
            ));
        }
    }
    None
}

fn plan_arm64_tail_call_cleanup_from_terminators(
    bytes: &[u8],
    terminators: &[usize],
    nop_word_indices: &HashSet<usize>,
) -> Result<Vec<u32>> {
    let mut selected: Option<Vec<u32>> = None;
    for &terminator in terminators {
        let mut start = terminator;
        let mut saw_cleanup = false;
        while start > 0 {
            let prev = start - 1;
            let word = u32::from_le_bytes(bytes[prev * 4..prev * 4 + 4].try_into().unwrap());
            if arm64_tail_cleanup_word(word, nop_word_indices.contains(&prev)) {
                saw_cleanup = true;
                start = prev;
                continue;
            }
            if !arm64_tail_cleanup_skip_word(word) {
                break;
            }
            start = prev;
        }
        if !saw_cleanup {
            continue;
        }
        let mut candidate = Vec::new();
        for idx in start..terminator {
            let word = u32::from_le_bytes(bytes[idx * 4..idx * 4 + 4].try_into().unwrap());
            if nop_word_indices.contains(&idx) {
                continue;
            }
            if arm64_tail_cleanup_skip_word(word) {
                continue;
            }
            if arm64_tail_cleanup_word(word, false) {
                candidate.push(word);
                continue;
            }
            bail!("arm64 tail-call cleanup scan crossed non-cleanup word {word:#010x}");
        }
        if let Some(previous) = &selected {
            if previous != &candidate {
                bail!("arm64 entry with bpf_tail_call has multiple incompatible return epilogues");
            }
        } else {
            selected = Some(candidate);
        }
    }
    Ok(selected.unwrap_or_default())
}

fn arm64_tail_cleanup_skip_word(insn: u32) -> bool {
    if insn == A64_NOP {
        return true;
    }
    if a64_mov_reg64(insn).is_some_and(|(dst, _)| dst == 0) {
        return true;
    }
    if a64_mov_reg32_word(insn).is_some_and(|(dst, _)| dst == 0) {
        return true;
    }
    a64_movz_imm_to_reg(insn).is_some_and(|(dst, _)| dst == 0)
}

fn arm64_tail_cleanup_word(insn: u32, is_stripped: bool) -> bool {
    if is_stripped {
        return true;
    }
    if let Some((is_load, _, _, _)) = arm64_stp_ldp_pair(insn) {
        return is_load;
    }
    arm64_ldr_str_unsigned64_sp(insn).is_some_and(|(is_load, _, _)| is_load)
        || arm64_ldr_str_post64_sp(insn).is_some_and(|(is_load, _, _)| is_load)
        || arm64_is_add_sp_imm(insn)
}

fn arm64_is_sp_sub_imm(insn: u32) -> bool {
    (insn & 0xffc0_03ff) == 0xd100_03ff
}

fn arm64_is_add_sp_imm(insn: u32) -> bool {
    (insn & 0xffc0_03ff) == 0x9100_03ff
}

fn arm64_stp_ldp_pair(insn: u32) -> Option<(bool, i32, u32, u32)> {
    let (is_load, has_writeback) = match insn & 0xffc0_0000 {
        0xa900_0000 => (false, false),
        0xa980_0000 | 0xa880_0000 => (false, true),
        0xa940_0000 => (true, false),
        0xa9c0_0000 | 0xa8c0_0000 => (true, true),
        _ => return None,
    };
    let rn = (insn >> 5) & 0x1f;
    if rn != 31 {
        return None;
    }
    let mut imm7 = ((insn >> 15) & 0x7f) as i32;
    if (imm7 & 0x40) != 0 {
        imm7 -= 0x80;
    }
    let offset = if has_writeback { 0 } else { imm7 * 8 };
    Some((is_load, offset, insn & 0x1f, (insn >> 10) & 0x1f))
}

fn arm64_ldr_str_unsigned64_sp(insn: u32) -> Option<(bool, u32, u32)> {
    let is_load = match insn & 0xffc0_0000 {
        0xf940_0000 => true,
        0xf900_0000 => false,
        _ => return None,
    };
    let rn = (insn >> 5) & 0x1f;
    if rn != 31 {
        return None;
    }
    let byte_off = ((insn >> 10) & 0xfff) * 8;
    Some((is_load, byte_off, insn & 0x1f))
}

fn arm64_ldr_str_post64_sp(insn: u32) -> Option<(bool, i32, u32)> {
    let is_load = match insn & 0xffe0_0c00 {
        0xf840_0400 => true,
        0xf800_0400 => false,
        _ => return None,
    };
    let rn = (insn >> 5) & 0x1f;
    if rn != 31 {
        return None;
    }
    let mut byte_off = ((insn >> 12) & 0x1ff) as i32;
    if (byte_off & 0x100) != 0 {
        byte_off -= 0x200;
    }
    Some((is_load, byte_off, insn & 0x1f))
}

fn arm64_saved_reg_stack_offset(bytes: &[u8], wanted_reg: u32) -> Option<u32> {
    for (word_index, word) in bytes.chunks_exact(4).enumerate() {
        let insn = u32::from_le_bytes(word.try_into().ok()?);
        if word_index == 0 && arm64_is_sp_sub_imm(insn) {
            continue;
        }
        if let Some((is_load, offset, rt, rt2)) = arm64_stp_ldp_pair(insn) {
            if is_load {
                return None;
            }
            if offset >= 0 && (rt == wanted_reg || rt2 == wanted_reg) {
                return Some(offset as u32);
            }
            continue;
        }
        if let Some((is_load, offset, rt)) = arm64_ldr_str_unsigned64_sp(insn) {
            if is_load {
                return None;
            }
            if rt == wanted_reg {
                return Some(offset);
            }
            continue;
        }
        break;
    }
    None
}

fn arm64_entry_pair_is_strippable(rt: u32, rt2: u32) -> bool {
    let mut has_bpf_callee_saved = false;
    [rt, rt2].iter().all(|reg| {
        if arm64_callee_saved_bit_index(*reg).is_some() {
            has_bpf_callee_saved = true;
        }
        arm64_entry_reg_is_strippable(*reg)
    }) && has_bpf_callee_saved
}

fn arm64_entry_reg_is_strippable(reg: u32) -> bool {
    reg == 30 || arm64_callee_saved_bit_index(reg).is_some()
}

fn arm64_entry_pair_is_frame_record(rt: u32, rt2: u32) -> bool {
    rt == 29 && rt2 == 30
}

fn arm64_entry_reg_is_preserved_by_native(reg: u32) -> bool {
    matches!(reg, 23..=25)
}

fn arm64_entry_pair_is_preserved_by_native(rt: u32, rt2: u32) -> bool {
    arm64_entry_reg_is_preserved_by_native(rt) && arm64_entry_reg_is_preserved_by_native(rt2)
}

fn arm64_reject_unsupported_entry_save(reg: u32) -> Result<()> {
    if matches!(reg, 26..=28) {
        bail!(
            "arm64 entry ABI uses unsupported callee-saved x{reg}; compile native objects with -ffixed-x26 through -ffixed-x28"
        );
    }
    Ok(())
}

fn arm64_callee_saved_bit_index(reg: u32) -> Option<usize> {
    match reg {
        19 => Some(0),
        20 => Some(1),
        21 => Some(2),
        22 => Some(3),
        _ => None,
    }
}

fn arm64_branch_target_word(
    addr_word_offset: &HashMap<Arm64AddressKey, usize>,
    sym_end_word_offset: &HashMap<Arm64AddressKey, usize>,
    source_symbol: Arm64AddressKey,
    target_is_symbol_end: bool,
    target_address: u64,
) -> Result<usize> {
    if target_is_symbol_end {
        return sym_end_word_offset
            .get(&source_symbol)
            .copied()
            .ok_or_else(|| anyhow!("arm64 branch target symbol end not in index map"));
    }
    addr_word_offset
        .get(&(source_symbol.0, target_address))
        .copied()
        .ok_or_else(|| anyhow!("arm64 branch target addr not in index map"))
}

fn a64_mov_reg64(insn: u32) -> Option<(usize, usize)> {
    if (insn & 0xffe0_ffe0) != 0xaa00_03e0 {
        return None;
    }
    let dst = (insn & 0x1f) as usize;
    let src = ((insn >> 16) & 0x1f) as usize;
    Some((dst, src))
}

fn a64_mov_reg32_word(insn: u32) -> Option<(usize, usize)> {
    if (insn & 0xffe0_ffe0) != 0x2a00_03e0 {
        return None;
    }
    let dst = (insn & 0x1f) as usize;
    let src = ((insn >> 16) & 0x1f) as usize;
    Some((dst, src))
}

fn arm64_call_clobber_map_regs(reg_map_names: &mut [Option<String>; 32]) {
    for slot in reg_map_names.iter_mut().take(19) {
        *slot = None;
    }
}

fn arm64_truncate_bpf_obj_name(name: &str) -> String {
    name.bytes().take(15).map(char::from).collect()
}

fn arm64_lookup_site_matches_native_map(spec: &LookupSiteSpec, native_map_name: &str) -> bool {
    let Some(source_map_name) = spec.map_name.as_deref() else {
        return false;
    };
    source_map_name == native_map_name
        || arm64_truncate_bpf_obj_name(source_map_name)
            == arm64_truncate_bpf_obj_name(native_map_name)
}

fn arm64_lookup_map_spec(
    lookup_maps: &HashMap<String, LookupSiteSpec>,
    native_map_name: &str,
) -> Result<Option<LookupSiteSpec>> {
    if let Some(spec) = lookup_maps.get(native_map_name) {
        return Ok(Some(spec.clone()));
    }

    let native_truncated = arm64_truncate_bpf_obj_name(native_map_name);
    let mut match_spec: Option<LookupSiteSpec> = None;
    let mut match_name: Option<&str> = None;
    for (name, spec) in lookup_maps {
        if arm64_truncate_bpf_obj_name(name) != native_truncated {
            continue;
        }
        if let Some(existing) = match_name {
            bail!(
                "arm64 native map name {native_map_name:?} matches multiple link-plan lookup_maps entries: {existing:?} and {name:?}"
            );
        }
        match_name = Some(name.as_str());
        match_spec = Some(spec.clone());
    }
    Ok(match_spec)
}

fn arm64_generic_lookup_site(target_addr: u64, map_name: Option<&str>) -> Option<LookupSiteSpec> {
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

fn arm64_select_lookup_site(
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
            .find(|(idx, spec)| !used[*idx] && arm64_lookup_site_matches_native_map(spec, map_name))
        {
            used[idx] = true;
            return Ok((idx.to_string(), Some(idx), spec.clone()));
        }

        if let Some(spec) = arm64_lookup_map_spec(lookup_maps, map_name)? {
            return Ok((format!("map:{map_name}"), None, spec));
        }

        if let Some(spec) = arm64_generic_lookup_site(generic_target_addr, Some(map_name)) {
            return Ok((format!("generic:{map_name}"), None, spec));
        }

        bail!(
            "arm64 bpf_map_lookup_elem native call {native_call_index} in {sym_name} uses map {map_name:?} but no matching link-plan lookup_sites or lookup_maps metadata exists"
        );
    }

    if let Some((idx, spec)) = lookup_sites.iter().enumerate().find(|(idx, _)| !used[*idx]) {
        used[idx] = true;
        return Ok((idx.to_string(), Some(idx), spec.clone()));
    }

    if let Some(spec) = arm64_generic_lookup_site(generic_target_addr, None) {
        return Ok(("generic".to_string(), None, spec));
    }

    bail!(
        "arm64 bpf_map_lookup_elem native call {native_call_index} in {sym_name} is missing link-plan lookup_sites metadata"
    );
}

fn arm64_select_map_call_site(
    sites_len: usize,
    ordinal: usize,
    map_name: Option<&String>,
    seen_by_map: &mut HashMap<String, usize>,
) -> Option<usize> {
    if ordinal < sites_len {
        if let Some(name) = map_name {
            seen_by_map.entry(name.clone()).or_insert(ordinal);
        }
        return Some(ordinal);
    }
    map_name.and_then(|name| seen_by_map.get(name).copied())
}

#[allow(clippy::too_many_arguments)]
fn build_arm64_helper_call(
    helper_name: &str,
    sym_name: &str,
    off: usize,
    emit_byte_offset: usize,
    is_entry: bool,
    helper_addrs: &HashMap<String, u64>,
    tail_call_maps: &HashSet<String>,
    lookup_sites: &[LookupSiteSpec],
    lookup_maps: &HashMap<String, LookupSiteSpec>,
    update_sites: &[UpdateSiteSpec],
    callee_saved_mask: u8,
    tail_call_cleanup_words: &[u32],
    tail_call_cnt_ptr_stack_offset: Option<u32>,
    lookup_call_counter: &mut usize,
    update_call_counter: &mut usize,
    reg_map_names: &mut [Option<String>; 32],
    lookup_site_used: &mut [bool],
    update_site_by_map: &mut HashMap<String, usize>,
    helper_literal_loads: &mut Vec<Arm64HelperLiteralLoad>,
    native_relocs: &mut Vec<RelocRecord>,
    helper_call_slot: Arm64HelperCallSlot,
) -> Result<Vec<u32>> {
    if helper_name == "bpf_tail_call" {
        if !is_entry {
            bail!("arm64 bpf_tail_call in non-entry symbol {sym_name} at byte offset {off:#x} is unsupported");
        }
        let map_name = reg_map_names[1].as_deref().ok_or_else(|| {
            anyhow!(
                "arm64 bpf_tail_call in {sym_name} at byte offset {off:#x} has no tracked x1 prog-array map"
            )
        })?;
        if !tail_call_maps.contains(map_name) {
            bail!(
                "arm64 bpf_tail_call in {sym_name} at byte offset {off:#x} uses map {map_name:?}, which is not a link-plan tail_call_maps entry"
            );
        }
        arm64_call_clobber_map_regs(reg_map_names);
        return build_arm64_tail_call_inline(
            helper_addrs,
            callee_saved_mask,
            tail_call_cleanup_words,
            tail_call_cnt_ptr_stack_offset,
        );
    }

    if helper_name == "bpf_get_smp_processor_id" {
        if let Some(inline) = build_arm64_get_smp_processor_id_inline(helper_addrs)? {
            return Ok(inline);
        }
    }
    if helper_name == "bpf_get_current_task" || helper_name == "bpf_get_current_task_btf" {
        return build_arm64_get_current_task_inline();
    }

    let mut helper_addr = helper_addrs.get(helper_name).copied();
    let mut helper_addr_from_site = false;
    let mut lookup_postprocess = None;
    if helper_name == "bpf_map_lookup_elem" && is_entry {
        let ordinal = *lookup_call_counter;
        let native_map_name = reg_map_names[0].as_deref();
        let (site_label, _site_index, spec) = arm64_select_lookup_site(
            lookup_sites,
            lookup_maps,
            lookup_site_used,
            ordinal,
            native_map_name,
            sym_name,
            helper_addr.unwrap_or(0),
        )?;
        *lookup_call_counter += 1;
        match spec.kind {
            LookupKind::Array | LookupKind::PerCpuArray => {
                let words = build_arm64_array_lookup(&spec)?;
                record_arm64_percpu_mrs_relocs(&words, emit_byte_offset, native_relocs)?;
                arm64_call_clobber_map_regs(reg_map_names);
                return Ok(words);
            }
            LookupKind::Call
            | LookupKind::Hash
            | LookupKind::LruHash
            | LookupKind::PerCpuHash
            | LookupKind::HashOfMaps => {
                helper_addr = Some(resolve_lookup_site_target(
                    &spec,
                    &format!("arm64 lookup-site {site_label} ({:?})", spec.kind),
                )?);
                helper_addr_from_site = true;
                lookup_postprocess = Some(spec);
            }
        }
    }
    if helper_name == "bpf_map_update_elem" && is_entry {
        let ordinal = *update_call_counter;
        let map_name = reg_map_names[0].as_ref();
        let site_index =
            arm64_select_map_call_site(update_sites.len(), ordinal, map_name, update_site_by_map);
        *update_call_counter += 1;
        if let Some(site_index) = site_index {
            let spec = &update_sites[site_index];
            match spec.kind {
                UpdateKind::Array | UpdateKind::PerCpuArray => {
                    let words = build_arm64_array_update(spec)?;
                    record_arm64_percpu_mrs_relocs(&words, emit_byte_offset, native_relocs)?;
                    arm64_call_clobber_map_regs(reg_map_names);
                    return Ok(words);
                }
                UpdateKind::Call => {
                    helper_addr = Some(require_call_target(
                        spec.target_addr,
                        &format!("arm64 update-site {ordinal}"),
                    )?);
                    helper_addr_from_site = true;
                }
            }
        }
    }
    let helper_addr = if helper_addr_from_site {
        helper_addr.ok_or_else(|| {
            anyhow!(
                "arm64 helper call in {sym_name} at byte offset {off:#x} has empty site target for {helper_name}"
            )
        })?
    } else {
        resolve_helper_target(
            helper_name,
            helper_addrs,
            &format!("arm64 helper call {helper_name}"),
        )?
    };
    if helper_call_slot == Arm64HelperCallSlot::FarSafe {
        if emit_byte_offset % 4 != 0 {
            bail!("arm64 helper call byte offset {emit_byte_offset:#x} is not word-aligned");
        }
        if helper_addr & (1u64 << 63) == 0 {
            bail!(
                "arm64 helper call {helper_name} in {sym_name} at byte offset {off:#x} resolved to non-kernel target {helper_addr:#x}"
            );
        }
        helper_literal_loads.push(Arm64HelperLiteralLoad {
            word_index: emit_byte_offset / 4,
            target: helper_addr,
        });
        let mut words = vec![A64_NOP, A64_BLR_X10];
        if let Some(spec) = lookup_postprocess {
            words.extend(build_arm64_lookup_call_postprocess(&spec)?);
        }
        record_arm64_percpu_mrs_relocs(&words, emit_byte_offset, native_relocs)?;
        arm64_call_clobber_map_regs(reg_map_names);
        return Ok(words);
    }

    let (mut words, call_word_offset) = arm64_helper_call_sequence(helper_call_slot)?;
    let reloc_offset = emit_byte_offset
        .checked_add(call_word_offset * 4)
        .ok_or_else(|| anyhow!("arm64 helper call reloc offset overflow"))?;
    let offset = u32::try_from(reloc_offset)
        .map_err(|_| anyhow!("arm64 helper call reloc offset exceeds u32"))?;
    native_relocs.push(RelocRecord {
        offset,
        kind: arm64_helper_call_reloc_kind(helper_call_slot)?,
        target: helper_addr,
    });
    if let Some(spec) = lookup_postprocess {
        words.extend(build_arm64_lookup_call_postprocess(&spec)?);
    }
    record_arm64_percpu_mrs_relocs(&words, emit_byte_offset, native_relocs)?;
    arm64_call_clobber_map_regs(reg_map_names);
    Ok(words)
}

fn rewrite_arm64(
    elf: &object::File,
    entry: &SymInfo,
    included: &[SymInfo],
    helper_addrs: &HashMap<String, u64>,
    map_addrs: &HashMap<String, u64>,
    tail_call_maps: &HashSet<String>,
    lookup_sites: &[LookupSiteSpec],
    lookup_maps: &HashMap<String, LookupSiteSpec>,
    update_sites: &[UpdateSiteSpec],
    helper_call_slot: Arm64HelperCallSlot,
    proof_mode: bool,
    show: bool,
) -> Result<RewriteResult> {
    let mut blob = Vec::new();
    let mut sym_start_word_offset: HashMap<Arm64AddressKey, usize> = HashMap::new();
    let mut sym_end_word_offset: HashMap<Arm64AddressKey, usize> = HashMap::new();
    let mut addr_word_offset: HashMap<Arm64AddressKey, usize> = HashMap::new();
    let mut patches: Vec<Arm64Patch> = Vec::new();
    let relocs = arm64_text_relocations(elf, included)?;
    let mut native_relocs: Vec<RelocRecord> = Vec::new();
    let mut helper_literal_loads: Vec<Arm64HelperLiteralLoad> = Vec::new();
    let mut lookup_call_counter: usize = 0;
    let mut update_call_counter: usize = 0;
    let mut proof_relocs: Vec<ProofReloc> = Vec::new();
    let proof_callee_saved_mask = if proof_mode {
        None
    } else {
        read_proof_abi(elf)?
    };
    let mut callee_saved_mask = arm64_effective_callee_saved_mask(proof_callee_saved_mask, 0);
    let mut reg_map_names: [Option<String>; 32] = std::array::from_fn(|_| None);
    let mut lookup_site_used = vec![false; lookup_sites.len()];
    let mut update_site_by_map: HashMap<String, usize> = HashMap::new();

    for sym in included {
        let is_entry = sym.section_index == entry.section_index && sym.address == entry.address;
        let sym_key = (sym.section_index, sym.address);
        let bytes = read_symbol_bytes(elf, sym)?;
        if bytes.is_empty() || bytes.len() % 4 != 0 {
            bail!(
                "arm64 symbol {} size must be a non-zero multiple of 4",
                sym.name
            );
        }
        let mut helper_imm_registers: [Option<u64>; 32] = std::array::from_fn(|_| None);
        let mut helper_imm_word_indices: [Option<usize>; 32] = std::array::from_fn(|_| None);
        let mut helper_imm_read_since_load: [bool; 32] = [false; 32];
        let mut entry_abi_strip = if is_entry {
            plan_arm64_entry_abi_strip(&bytes)?
        } else {
            Arm64EntryAbiStrip::default()
        };
        let entry_has_tail_call =
            is_entry && !proof_mode && arm64_symbol_has_tail_call(&bytes, sym, &relocs);
        if entry_has_tail_call {
            entry_abi_strip.tail_call_cleanup_words =
                plan_arm64_tail_call_cleanup(elf, sym, &bytes, &entry_abi_strip.nop_word_indices)?;
        }
        if proof_callee_saved_mask.is_none() {
            callee_saved_mask |= entry_abi_strip.callee_saved_mask;
            callee_saved_mask |=
                arm64_observed_bpf_callee_saved_mask(&bytes, &entry_abi_strip.nop_word_indices);
        } else if is_entry {
            callee_saved_mask = arm64_effective_callee_saved_mask(
                proof_callee_saved_mask,
                entry_abi_strip.callee_saved_mask,
            );
        }

        let end = sym.address + sym.size;
        sym_start_word_offset.insert(sym_key, blob.len() / 4);
        for (local_word_index, word) in bytes.chunks_exact(4).enumerate() {
            let off = local_word_index * 4;
            let mut insn = u32::from_le_bytes(word.try_into().unwrap());
            let emit_word_index = blob.len() / 4;
            addr_word_offset.insert(
                (sym.section_index, sym.address + off as u64),
                emit_word_index,
            );
            if is_entry && entry_abi_strip.nop_word_indices.contains(&local_word_index) {
                insn = A64_NOP;
                blob.extend_from_slice(&insn.to_le_bytes());
                continue;
            }
            let reloc = relocs.get(&((sym.section_index, sym.address), off as u64));
            for reg in 0..32 {
                if helper_imm_word_indices[reg].is_some() && a64_maybe_reads_gpr(insn, reg) {
                    helper_imm_read_since_load[reg] = true;
                }
            }
            let mut helper_imm_load_reg = None;
            if let Some((reg, helper_id)) = a64_known_helper_id_load(insn) {
                helper_imm_registers[reg] = Some(helper_id);
                helper_imm_word_indices[reg] = Some(emit_word_index);
                helper_imm_read_since_load[reg] = false;
                helper_imm_load_reg = Some(reg);
                let next_is_call = bytes.get(off + 4..off + 8).and_then(|next| {
                    let next = u32::from_le_bytes(next.try_into().ok()?);
                    a64_blr_reg(next)
                }) == Some(reg);
                if !proof_mode && next_is_call {
                    insn = A64_NOP;
                    helper_imm_word_indices[reg] = None;
                }
            }
            let mut map_name_write_handled = false;
            if !proof_mode {
                if let Some((dst, src)) = a64_mov_reg64(insn) {
                    reg_map_names[dst] = reg_map_names[src].clone();
                    map_name_write_handled = true;
                }
            }

            if let Some(reloc) = reloc {
                match reloc.r_type {
                    R_AARCH64_ADR_PREL_PG_HI21 => {
                        if proof_mode {
                            proof_relocs.push(ProofReloc {
                                offset: (emit_word_index * 4) as u64,
                                r_type: reloc.r_type,
                                symbol: reloc.target_name.clone(),
                                addend: arm64_proof_reloc_addend(reloc),
                                data: Some(arm64_reloc_data(elf, reloc, 16)?),
                            });
                            blob.extend_from_slice(&insn.to_le_bytes());
                            continue;
                        }
                        let section_index = reloc.target_section_index.ok_or_else(|| {
                            anyhow!(
                                "arm64 ADR_PREL in {} at byte offset {off:#x} targets {} without a section",
                                sym.name,
                                reloc.target_name
                            )
                        })?;
                        patches.push(Arm64Patch {
                            word_index: emit_word_index,
                            kind: Arm64PatchKind::LocalDataAdr {
                                target_name: reloc.target_name.clone(),
                                section_index,
                                addend: reloc.addend,
                            },
                        });
                        blob.extend_from_slice(&insn.to_le_bytes());
                        continue;
                    }
                    R_AARCH64_ADD_ABS_LO12_NC => {
                        if proof_mode {
                            proof_relocs.push(ProofReloc {
                                offset: (emit_word_index * 4) as u64,
                                r_type: reloc.r_type,
                                symbol: reloc.target_name.clone(),
                                addend: arm64_proof_reloc_addend(reloc),
                                data: None,
                            });
                            blob.extend_from_slice(&insn.to_le_bytes());
                            continue;
                        }
                        patches.push(Arm64Patch {
                            word_index: emit_word_index,
                            kind: Arm64PatchKind::Nop,
                        });
                        blob.extend_from_slice(&insn.to_le_bytes());
                        continue;
                    }
                    R_AARCH64_CALL26 => {
                        if let Some(target) = arm64_local_call_target(reloc) {
                            if !included
                                .iter()
                                .any(|s| (s.section_index, s.address) == target)
                            {
                                bail!(
                                    "arm64 local CALL26 in {} at byte offset {off:#x} targets section {:?} address {:#x}, outside included symbols",
                                    sym.name,
                                    target.0,
                                    target.1
                                );
                            }
                            patches.push(Arm64Patch {
                                word_index: emit_word_index,
                                kind: Arm64PatchKind::Bl {
                                    target_symbol: target,
                                },
                            });
                            blob.extend_from_slice(&insn.to_le_bytes());
                            continue;
                        }
                        if proof_mode {
                            proof_relocs.push(ProofReloc {
                                offset: (emit_word_index * 4) as u64,
                                r_type: reloc.r_type,
                                symbol: reloc.target_name.clone(),
                                addend: reloc.addend,
                                data: None,
                            });
                            blob.extend_from_slice(&insn.to_le_bytes());
                            continue;
                        }
                        for word in build_arm64_helper_call(
                            &reloc.target_name,
                            &sym.name,
                            off,
                            blob.len(),
                            is_entry,
                            helper_addrs,
                            tail_call_maps,
                            lookup_sites,
                            lookup_maps,
                            update_sites,
                            callee_saved_mask,
                            &entry_abi_strip.tail_call_cleanup_words,
                            entry_abi_strip.tail_call_cnt_ptr_stack_offset,
                            &mut lookup_call_counter,
                            &mut update_call_counter,
                            &mut reg_map_names,
                            &mut lookup_site_used,
                            &mut update_site_by_map,
                            &mut helper_literal_loads,
                            &mut native_relocs,
                            helper_call_slot,
                        )? {
                            append_u32(&mut blob, word);
                        }
                        continue;
                    }
                    R_AARCH64_ADR_GOT_PAGE => {
                        if proof_mode {
                            proof_relocs.push(ProofReloc {
                                offset: (emit_word_index * 4) as u64,
                                r_type: reloc.r_type,
                                symbol: reloc.target_name.clone(),
                                addend: reloc.addend,
                                data: None,
                            });
                            blob.extend_from_slice(&insn.to_le_bytes());
                            continue;
                        }
                        if !map_addrs.contains_key(&reloc.target_name) {
                            bail!(
                                "arm64 ADR_GOT in {} at byte offset {off:#x} targets unknown map {}",
                                sym.name,
                                reloc.target_name
                            );
                        }
                        patches.push(Arm64Patch {
                            word_index: emit_word_index,
                            kind: Arm64PatchKind::MapLiteralLoad {
                                target_name: reloc.target_name.clone(),
                            },
                        });
                        blob.extend_from_slice(&insn.to_le_bytes());
                        continue;
                    }
                    R_AARCH64_LD64_GOT_LO12_NC => {
                        if proof_mode {
                            proof_relocs.push(ProofReloc {
                                offset: (emit_word_index * 4) as u64,
                                r_type: reloc.r_type,
                                symbol: reloc.target_name.clone(),
                                addend: reloc.addend,
                                data: None,
                            });
                            blob.extend_from_slice(&insn.to_le_bytes());
                            continue;
                        }
                        if !map_addrs.contains_key(&reloc.target_name) {
                            bail!(
                                "arm64 LD64_GOT in {} at byte offset {off:#x} targets unknown map {}",
                                sym.name,
                                reloc.target_name
                            );
                        }
                        patches.push(Arm64Patch {
                            word_index: emit_word_index,
                            kind: Arm64PatchKind::Nop,
                        });
                        let rt = (insn & 0x1f) as usize;
                        reg_map_names[rt] = Some(reloc.target_name.clone());
                        clear_arm64_helper_imm_register(
                            &mut helper_imm_registers,
                            &mut helper_imm_word_indices,
                            &mut helper_imm_read_since_load,
                            rt,
                        );
                        blob.extend_from_slice(&insn.to_le_bytes());
                        continue;
                    }
                    _ => {}
                }
            }

            if let Some(reg) = a64_blr_reg(insn) {
                let direct_helper_id = helper_imm_registers[reg];
                let helper_id = direct_helper_id.or_else(|| {
                    arm64_reachable_helper_id_for_blr(&bytes, sym, &relocs, local_word_index, reg)
                });
                let Some(helper_id) = helper_id else {
                    if !proof_mode {
                        bail!(
                            "arm64 unresolved register-indirect call in {} at byte offset {off:#x} through x{reg}; helper calls must be rewritten before kernel load",
                            sym.name
                        );
                    }
                    blob.extend_from_slice(&insn.to_le_bytes());
                    continue;
                };
                let helper_name = x86::bpf_helper_name_from_id(helper_id).ok_or_else(|| {
                    anyhow!(
                        "arm64 immediate BPF helper id {} in {} at byte offset {off:#x} is unsupported",
                        helper_id,
                        sym.name
                    )
                })?;
                if proof_mode {
                    clear_arm64_call_clobbered_helper_imm_registers(
                        &mut helper_imm_registers,
                        &mut helper_imm_word_indices,
                        &mut helper_imm_read_since_load,
                    );
                    blob.extend_from_slice(&insn.to_le_bytes());
                    continue;
                }
                if direct_helper_id.is_some() && !helper_imm_read_since_load[reg] {
                    if let Some(word_index) = helper_imm_word_indices[reg] {
                        patches.push(Arm64Patch {
                            word_index,
                            kind: Arm64PatchKind::Nop,
                        });
                    }
                }
                clear_arm64_call_clobbered_helper_imm_registers(
                    &mut helper_imm_registers,
                    &mut helper_imm_word_indices,
                    &mut helper_imm_read_since_load,
                );
                for word in build_arm64_helper_call(
                    helper_name,
                    &sym.name,
                    off,
                    blob.len(),
                    is_entry,
                    helper_addrs,
                    tail_call_maps,
                    lookup_sites,
                    lookup_maps,
                    update_sites,
                    callee_saved_mask,
                    &entry_abi_strip.tail_call_cleanup_words,
                    entry_abi_strip.tail_call_cnt_ptr_stack_offset,
                    &mut lookup_call_counter,
                    &mut update_call_counter,
                    &mut reg_map_names,
                    &mut lookup_site_used,
                    &mut update_site_by_map,
                    &mut helper_literal_loads,
                    &mut native_relocs,
                    helper_call_slot,
                )? {
                    append_u32(&mut blob, word);
                }
                continue;
            }

            if a64_is_adr_or_adrp(insn) {
                bail!(
                    "arm64 native-link does not support ADR/ADRP yet in {} at byte offset {off:#x}",
                    sym.name
                );
            }
            if a64_is_ldr_literal(insn) {
                bail!(
                    "arm64 native-link does not support LDR literal yet in {} at byte offset {off:#x}",
                    sym.name
                );
            }

            if let Some(target) = a64_bl_target(sym.address, local_word_index, insn) {
                let target_symbol = (sym.section_index, target);
                if !included
                    .iter()
                    .any(|s| (s.section_index, s.address) == target_symbol)
                {
                    bail!(
                        "arm64 BL in {} at byte offset {off:#x} targets {target:#x}, outside included symbols",
                        sym.name
                    );
                }
                patches.push(Arm64Patch {
                    word_index: emit_word_index,
                    kind: Arm64PatchKind::Bl { target_symbol },
                });
                blob.extend_from_slice(&insn.to_le_bytes());
                continue;
            }

            let mut reserve_tbz_tbnz_long_slot = false;
            if let Some(target) = a64_branch_target(sym.address, local_word_index, insn) {
                if !proof_mode && is_entry && arm64_is_return_trampoline_target(elf, target)? {
                    if !a64_is_uncond_b(insn) {
                        bail!(
                            "arm64 branch in {} at byte offset {off:#x} conditionally targets return trampoline",
                            sym.name
                        );
                    }
                    patches.push(Arm64Patch {
                        word_index: emit_word_index,
                        kind: Arm64PatchKind::ReturnToTrampoline,
                    });
                    blob.extend_from_slice(&0u32.to_le_bytes());
                    continue;
                }
                if target < sym.address || target > end {
                    bail!(
                        "arm64 branch in {} at byte offset {off:#x} targets {target:#x}, outside symbol",
                        sym.name
                    );
                }
                let target_is_symbol_end = target == end;
                let kind = if a64_is_uncond_b(insn) {
                    Arm64PatchKind::B {
                        source_symbol: sym_key,
                        target_is_symbol_end,
                        target_address: target,
                    }
                } else if a64_is_b_cond(insn) {
                    Arm64PatchKind::BCond {
                        insn,
                        source_symbol: sym_key,
                        target_is_symbol_end,
                        target_address: target,
                    }
                } else if a64_is_cbz_cbnz(insn) {
                    Arm64PatchKind::CbzCbnz {
                        insn,
                        source_symbol: sym_key,
                        target_is_symbol_end,
                        target_address: target,
                    }
                } else if a64_is_tbz_tbnz(insn) {
                    Arm64PatchKind::TbzTbnz {
                        insn,
                        source_symbol: sym_key,
                        target_is_symbol_end,
                        target_address: target,
                    }
                } else {
                    bail!(
                        "arm64 unsupported branch rewrite in {} at byte offset {off:#x}: {insn:#010x}",
                        sym.name
                    );
                };
                reserve_tbz_tbnz_long_slot =
                    !proof_mode && matches!(kind, Arm64PatchKind::TbzTbnz { .. });
                patches.push(Arm64Patch {
                    word_index: emit_word_index,
                    kind,
                });
            }

            if is_entry && a64_is_ret(insn) {
                patches.push(Arm64Patch {
                    word_index: emit_word_index,
                    kind: Arm64PatchKind::ReturnToTrampoline,
                });
                blob.extend_from_slice(&0u32.to_le_bytes());
            } else {
                blob.extend_from_slice(&insn.to_le_bytes());
                if reserve_tbz_tbnz_long_slot {
                    append_u32(&mut blob, A64_NOP);
                }
            }
            for reg in a64_written_gprs(insn).into_iter().flatten() {
                if helper_imm_load_reg != Some(reg) {
                    clear_arm64_helper_imm_register(
                        &mut helper_imm_registers,
                        &mut helper_imm_word_indices,
                        &mut helper_imm_read_since_load,
                        reg,
                    );
                }
                if !proof_mode && !map_name_write_handled {
                    reg_map_names[reg] = None;
                }
            }
        }
        sym_end_word_offset.insert(sym_key, blob.len() / 4);
    }

    let code_word_count = blob.len() / 4;
    let mut map_literals: HashMap<String, usize> = HashMap::new();
    let mut map_patches = Vec::new();
    let mut local_data: HashMap<object::SectionIndex, usize> = HashMap::new();

    for patch in patches.iter().filter(|p| {
        matches!(
            p.kind,
            Arm64PatchKind::MapLiteralLoad { .. }
                | Arm64PatchKind::LocalDataAdr { .. }
                | Arm64PatchKind::Nop
        )
    }) {
        let off = patch.word_index * 4;
        let patched = match &patch.kind {
            Arm64PatchKind::MapLiteralLoad { target_name } => {
                let literal_offset = if let Some(&offset) = map_literals.get(target_name) {
                    offset
                } else {
                    let addr = *map_addrs
                        .get(target_name)
                        .ok_or_else(|| anyhow!("missing arm64 map address: {target_name}"))?;
                    let offset = arm64_append_literal(&mut blob, addr);
                    map_literals.insert(target_name.clone(), offset);
                    map_patches.push(MapPatch {
                        name: target_name.clone(),
                        offset,
                    });
                    offset
                };
                let rd = u32::from(blob[off] & 0x1f);
                a64_ldr_lit64(rd, patch.word_index, literal_offset)?
            }
            Arm64PatchKind::LocalDataAdr {
                target_name,
                section_index,
                addend,
            } => {
                if *addend < 0 {
                    bail!("arm64 local data relocation {target_name} has negative addend {addend}");
                }
                let section_offset =
                    arm64_append_section_data(elf, *section_index, &mut blob, &mut local_data)?;
                let target_offset = section_offset
                    .checked_add(*addend as usize)
                    .ok_or_else(|| anyhow!("arm64 local data offset overflow for {target_name}"))?;
                let section = elf
                    .section_by_index(*section_index)
                    .with_context(|| format!("arm64 local data section {section_index:?}"))?;
                let section_len = usize::try_from(section.size())
                    .context("arm64 local data section size does not fit usize")?;
                if *addend as usize > section_len {
                    bail!(
                        "arm64 local data relocation {target_name} addend {} exceeds section size {}",
                        addend,
                        section_len
                    );
                }
                let rd = u32::from(blob[off] & 0x1f);
                a64_adr(rd, patch.word_index, target_offset)?
            }
            Arm64PatchKind::Nop => 0xd503_201f,
            _ => continue,
        };
        blob[off..off + 4].copy_from_slice(&patched.to_le_bytes());
    }

    let mut helper_literals: HashMap<u64, usize> = HashMap::new();
    for patch in &helper_literal_loads {
        let literal_offset = if let Some(&offset) = helper_literals.get(&patch.target) {
            offset
        } else {
            let offset = arm64_append_literal(&mut blob, patch.target);
            helper_literals.insert(patch.target, offset);
            offset
        };
        let patched = a64_ldr_lit64(10, patch.word_index, literal_offset)?;
        let off = patch.word_index * 4;
        blob[off..off + 4].copy_from_slice(&patched.to_le_bytes());
    }

    align_arm64_blob_to_8(&mut blob);
    let ret_trampoline_word = blob.len() / 4;
    append_u32(&mut blob, A64_MOV_X7_X0);

    for patch in patches.iter().filter(|p| {
        matches!(
            p.kind,
            Arm64PatchKind::ReturnToTrampoline
                | Arm64PatchKind::Bl { .. }
                | Arm64PatchKind::B { .. }
                | Arm64PatchKind::BCond { .. }
                | Arm64PatchKind::CbzCbnz { .. }
                | Arm64PatchKind::TbzTbnz { .. }
        )
    }) {
        let patched = match patch.kind {
            Arm64PatchKind::ReturnToTrampoline => {
                a64_patch_b(patch.word_index, ret_trampoline_word)?
            }
            Arm64PatchKind::Bl { target_symbol } => {
                let target_word = *sym_start_word_offset
                    .get(&target_symbol)
                    .ok_or_else(|| anyhow!("arm64 BL target sym addr not in index map"))?;
                a64_patch_bl(patch.word_index, target_word)?
            }
            Arm64PatchKind::B {
                source_symbol,
                target_is_symbol_end,
                target_address,
            } => {
                let target_word = arm64_branch_target_word(
                    &addr_word_offset,
                    &sym_end_word_offset,
                    source_symbol,
                    target_is_symbol_end,
                    target_address,
                )?;
                a64_patch_b(patch.word_index, target_word)?
            }
            Arm64PatchKind::BCond {
                insn,
                source_symbol,
                target_is_symbol_end,
                target_address,
            } => {
                let target_word = arm64_branch_target_word(
                    &addr_word_offset,
                    &sym_end_word_offset,
                    source_symbol,
                    target_is_symbol_end,
                    target_address,
                )?;
                a64_patch_b_cond(insn, patch.word_index, target_word)?
            }
            Arm64PatchKind::CbzCbnz {
                insn,
                source_symbol,
                target_is_symbol_end,
                target_address,
            } => {
                let target_word = arm64_branch_target_word(
                    &addr_word_offset,
                    &sym_end_word_offset,
                    source_symbol,
                    target_is_symbol_end,
                    target_address,
                )?;
                a64_patch_cbz_cbnz(insn, patch.word_index, target_word)?
            }
            Arm64PatchKind::TbzTbnz {
                insn,
                source_symbol,
                target_is_symbol_end,
                target_address,
            } => {
                let target_word = arm64_branch_target_word(
                    &addr_word_offset,
                    &sym_end_word_offset,
                    source_symbol,
                    target_is_symbol_end,
                    target_address,
                )?;
                a64_patch_tbz_tbnz_or_long(&mut blob, insn, patch.word_index, target_word)?
            }
            _ => continue,
        };
        let off = patch.word_index * 4;
        blob[off..off + 4].copy_from_slice(&patched.to_le_bytes());
    }

    if !proof_mode {
        validate_arm64_kernel_blob_control_flow(&blob, code_word_count, ret_trampoline_word)?;
    }

    if show {
        disasm_arm64_words(&blob);
    }
    let proof_symbols = if proof_mode {
        arm64_proof_symbols(
            included,
            &sym_start_word_offset,
            &sym_end_word_offset,
            blob.len(),
        )?
    } else {
        Vec::new()
    };
    proof_relocs.sort_by_key(|reloc| reloc.offset);
    Ok(RewriteResult {
        blob,
        relocs: native_relocs,
        map_patches,
        callee_saved_mask,
        proof_relocs,
        proof_symbols,
    })
}

fn arm64_proof_symbols(
    included: &[SymInfo],
    start_words: &HashMap<Arm64AddressKey, usize>,
    end_words: &HashMap<Arm64AddressKey, usize>,
    blob_len: usize,
) -> Result<Vec<ProofSymbol>> {
    let mut out = Vec::new();
    for sym in included {
        let sym_key = (sym.section_index, sym.address);
        let start = *start_words
            .get(&sym_key)
            .ok_or_else(|| anyhow!("arm64 proof symbol {} has no start", sym.name))?
            * 4;
        let end = *end_words
            .get(&sym_key)
            .ok_or_else(|| anyhow!("arm64 proof symbol {} has no end", sym.name))?
            * 4;
        if end < start || end > blob_len {
            bail!(
                "arm64 proof symbol {} range {start:#x}..{end:#x} outside blob size {blob_len}",
                sym.name
            );
        }
        out.push(ProofSymbol {
            name: sym.name.clone(),
            offset: start as u64,
            size: (end - start) as u64,
        });
    }
    let trampoline_offset = blob_len
        .checked_sub(4)
        .ok_or_else(|| anyhow!("arm64 proof blob too small for return trampoline"))?;
    out.push(ProofSymbol {
        name: ARM64_RETURN_TRAMPOLINE_SYMBOL.to_string(),
        offset: trampoline_offset as u64,
        size: 4,
    });
    Ok(out)
}

fn arm64_is_return_trampoline_target(elf: &object::File, target: u64) -> Result<bool> {
    for sym in elf.symbols().chain(elf.dynamic_symbols()) {
        if sym.address() != target || sym.size() == 0 {
            continue;
        }
        let name = sym
            .name()
            .map_err(|e| anyhow!("arm64 return trampoline symbol name: {e}"))?;
        if name == ARM64_RETURN_TRAMPOLINE_SYMBOL {
            return Ok(true);
        }
    }
    Ok(false)
}

fn disasm_arm64_words(blob: &[u8]) {
    eprintln!("rewritten arm64 blob ({} bytes):", blob.len());
    for (i, word) in blob.chunks_exact(4).enumerate() {
        let insn = u32::from_le_bytes(word.try_into().unwrap());
        eprintln!("  {:#06x}: {:#010x}", i * 4, insn);
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn arm64_entry_abi_strip_allows_multiple_epilogues() {
        let mut bytes = Vec::new();
        for word in [
            0xa9024ff4, // stp x20, x19, [sp, #32]
            0xd503201f, // nop
            0xa9424ff4, // ldp x20, x19, [sp, #32]
            0xa9424ff4, // ldp x20, x19, [sp, #32]
        ] {
            bytes.extend_from_slice(&u32::to_le_bytes(word));
        }

        let strip = plan_arm64_entry_abi_strip(&bytes).unwrap();
        assert_eq!(strip.callee_saved_mask, 0x3);
        assert!(strip.nop_word_indices.contains(&0));
        assert!(strip.nop_word_indices.contains(&2));
        assert!(strip.nop_word_indices.contains(&3));
        assert_eq!(strip.nop_word_indices.len(), 3);
    }

    #[test]
    fn arm64_entry_abi_strip_strips_lr_callee_saved_pairs() {
        let mut bytes = Vec::new();
        for word in [
            0xa9024ffe, // stp x30, x19, [sp, #32]
            0xd503201f, // nop
            0xa9424ffe, // ldp x30, x19, [sp, #32]
        ] {
            bytes.extend_from_slice(&u32::to_le_bytes(word));
        }

        let strip = plan_arm64_entry_abi_strip(&bytes).unwrap();
        assert_eq!(strip.callee_saved_mask, 0x1);
        assert!(strip.nop_word_indices.contains(&0));
        assert!(strip.nop_word_indices.contains(&2));
        assert_eq!(strip.nop_word_indices.len(), 2);
    }

    #[test]
    fn arm64_entry_abi_strip_strips_standalone_lr_save_restore() {
        let mut bytes = Vec::new();
        for word in [
            0xd10183ff, // sub sp, sp, #0x60
            0xf90013fe, // str x30, [sp, #0x20]
            0xa90457f6, // stp x22, x21, [sp, #0x40]
            0xa9054ff4, // stp x20, x19, [sp, #0x50]
            0xd503201f, // body nop
            0xa9454ff4, // ldp x20, x19, [sp, #0x50]
            0xf94013fe, // ldr x30, [sp, #0x20]
            0xa94457f6, // ldp x22, x21, [sp, #0x40]
        ] {
            bytes.extend_from_slice(&u32::to_le_bytes(word));
        }

        let strip = plan_arm64_entry_abi_strip(&bytes).unwrap();
        assert_eq!(strip.callee_saved_mask, 0xf);
        for idx in [1, 2, 3, 5, 6, 7] {
            assert!(strip.nop_word_indices.contains(&idx));
        }
        assert_eq!(strip.nop_word_indices.len(), 6);
    }

    #[test]
    fn arm64_entry_abi_strip_preserves_native_saved_x23_x24() {
        let mut bytes = Vec::new();
        for word in [
            0xd10183ff, // sub sp, sp, #0x60
            0xa9035ff8, // stp x24, x23, [sp, #0x30]
            0xa9054ff4, // stp x20, x19, [sp, #0x50]
            0xd503201f, // body nop
            0xa9454ff4, // ldp x20, x19, [sp, #0x50]
            0xa9435ff8, // ldp x24, x23, [sp, #0x30]
        ] {
            bytes.extend_from_slice(&u32::to_le_bytes(word));
        }

        let strip = plan_arm64_entry_abi_strip(&bytes).unwrap();
        assert_eq!(strip.callee_saved_mask, 0x3);
        assert!(strip.nop_word_indices.contains(&2));
        assert!(strip.nop_word_indices.contains(&4));
        assert_eq!(strip.nop_word_indices.len(), 2);
    }

    #[test]
    fn arm64_entry_abi_strip_rejects_unsupported_native_callee_saved_regs() {
        let mut bytes = Vec::new();
        for word in [
            0xd10183ff, // sub sp, sp, #0x60
            0xa90367fa, // stp x26, x25, [sp, #0x30]
            0xd503201f, // body nop
            0xa94367fa, // ldp x26, x25, [sp, #0x30]
        ] {
            bytes.extend_from_slice(&u32::to_le_bytes(word));
        }

        let err = match plan_arm64_entry_abi_strip(&bytes) {
            Ok(_) => panic!("unsupported x26 entry save unexpectedly passed"),
            Err(err) => err,
        };
        assert!(err.to_string().contains("unsupported callee-saved x26"));
    }

    #[test]
    fn arm64_entry_abi_strip_preserves_frame_record_pairs() {
        let mut bytes = Vec::new();
        for word in [
            0xa9be7bfd, // stp x29, x30, [sp, #-32]!
            0xd503201f, // nop
            0xa8c27bfd, // ldp x29, x30, [sp], #32
        ] {
            bytes.extend_from_slice(&u32::to_le_bytes(word));
        }

        let strip = plan_arm64_entry_abi_strip(&bytes).unwrap();
        assert_eq!(strip.callee_saved_mask, 0);
        assert!(strip.nop_word_indices.is_empty());
    }

    #[test]
    fn arm64_entry_abi_strip_scans_past_frame_record_pairs() {
        let mut bytes = Vec::new();
        for word in [
            0xd10183ff, // sub sp, sp, #0x60
            0xa9037bfd, // stp x29, x30, [sp, #0x30]
            0xa90457f6, // stp x22, x21, [sp, #0x40]
            0xa9054ff4, // stp x20, x19, [sp, #0x50]
            0xd503201f, // body nop
            0xa9454ff4, // ldp x20, x19, [sp, #0x50]
            0xa94457f6, // ldp x22, x21, [sp, #0x40]
            0xa9437bfd, // ldp x29, x30, [sp, #0x30]
        ] {
            bytes.extend_from_slice(&u32::to_le_bytes(word));
        }

        let strip = plan_arm64_entry_abi_strip(&bytes).unwrap();
        assert_eq!(strip.callee_saved_mask, 0xf);
        for idx in [2, 3, 5, 6] {
            assert!(strip.nop_word_indices.contains(&idx));
        }
        assert_eq!(strip.nop_word_indices.len(), 4);
    }

    #[test]
    fn arm64_entry_abi_strip_ignores_body_spills() {
        let mut bytes = Vec::new();
        for word in [
            0xd104c3ff, // sub sp, sp, #0x130
            0xa91157f6, // stp x22, x21, [sp, #0x110]
            0xd503201f, // nop
            0xa9035bf5, // stp x21, x22, [sp, #0x30]
            0xa95157f6, // ldp x22, x21, [sp, #0x110]
        ] {
            bytes.extend_from_slice(&u32::to_le_bytes(word));
        }

        let strip = plan_arm64_entry_abi_strip(&bytes).unwrap();
        assert_eq!(strip.callee_saved_mask, 0xc);
        assert!(strip.nop_word_indices.contains(&1));
        assert!(!strip.nop_word_indices.contains(&3));
        assert!(strip.nop_word_indices.contains(&4));
        assert_eq!(strip.nop_word_indices.len(), 2);
    }

    #[test]
    fn arm64_stp_ldp_pair_rejects_non_pair_instructions() {
        assert!(arm64_stp_ldp_pair(0xaa00_03f3).is_none()); // mov x19, x0
        assert!(arm64_stp_ldp_pair(0xf900_1bfe).is_none()); // str x30, [sp, #0x30]
    }

    #[test]
    fn arm64_entry_abi_strip_matches_writeback_push_pop() {
        let mut bytes = Vec::new();
        for word in [
            0xa9bf4ff4, // stp x20, x19, [sp, #-0x10]!
            0xd503201f, // nop
            0xa8c14ff4, // ldp x20, x19, [sp], #0x10
        ] {
            bytes.extend_from_slice(&u32::to_le_bytes(word));
        }

        let strip = plan_arm64_entry_abi_strip(&bytes).unwrap();
        assert_eq!(strip.callee_saved_mask, 0x3);
        assert!(strip.nop_word_indices.contains(&0));
        assert!(strip.nop_word_indices.contains(&2));
        assert_eq!(strip.nop_word_indices.len(), 2);
    }

    #[test]
    fn arm64_immediate_helper_call_patterns_decode() {
        assert_eq!(a64_known_helper_id_load(0x5280_0028), Some((8, 1)));
        assert_eq!(a64_known_helper_id_load(0x5280_0e29), Some((9, 113)));
        assert_eq!(a64_known_helper_id_load(0x5280_1008), None);
        assert_eq!(a64_blr_reg(0xd63f_0100), Some(8));
        assert_eq!(a64_blr_reg(0xd63f_0120), Some(9));
        assert_eq!(a64_br_reg(0xd61f_0140), Some(10));
        assert_eq!(a64_blr_reg(A64_NOP), None);
        assert_eq!(a64_br_reg(A64_NOP), None);
    }

    #[test]
    fn arm64_kernel_blob_control_flow_allows_tail_call_br_x10_and_ignores_data() {
        let mut blob = Vec::new();
        for word in [
            a64_tbz64(10, 63).unwrap(),
            A64_NOP,
            a64_br(10).unwrap(),
            0xd63f_0100, // data word that decodes as blr x8
            A64_MOV_X7_X0,
        ] {
            blob.extend_from_slice(&word.to_le_bytes());
        }

        validate_arm64_kernel_blob_control_flow(&blob, 3, 4).unwrap();
    }

    #[test]
    fn arm64_kernel_blob_control_flow_rejects_unguarded_tail_call_br() {
        let mut blob = Vec::new();
        for word in [A64_NOP, a64_br(10).unwrap(), A64_MOV_X7_X0] {
            blob.extend_from_slice(&word.to_le_bytes());
        }

        let err = validate_arm64_kernel_blob_control_flow(&blob, 2, 2).unwrap_err();
        assert!(err
            .to_string()
            .contains("without a dominating kernel-address guard"));
    }

    #[test]
    fn arm64_kernel_blob_control_flow_rejects_residual_blr() {
        let mut blob = Vec::new();
        for word in [A64_NOP, 0xd63f_0100, A64_MOV_X7_X0] {
            blob.extend_from_slice(&word.to_le_bytes());
        }

        let err = validate_arm64_kernel_blob_control_flow(&blob, 2, 2).unwrap_err();
        assert!(err.to_string().contains("register-indirect call blr x8"));
    }

    #[test]
    fn arm64_kernel_blob_control_flow_allows_helper_blr_x10_literal() {
        let mut blob = Vec::new();
        append_u32(&mut blob, A64_NOP);
        append_u32(&mut blob, A64_BLR_X10);
        let literal_offset = arm64_append_literal(&mut blob, 0xffff_0000_1234_5000);
        let ret_trampoline_word = blob.len() / 4;
        append_u32(&mut blob, A64_MOV_X7_X0);
        let ldr = a64_ldr_lit64(10, 0, literal_offset).unwrap();
        blob[0..4].copy_from_slice(&ldr.to_le_bytes());

        validate_arm64_kernel_blob_control_flow(&blob, 2, ret_trampoline_word).unwrap();
    }

    #[test]
    fn arm64_kernel_blob_control_flow_rejects_helper_blr_x10_user_literal() {
        let mut blob = Vec::new();
        append_u32(&mut blob, A64_NOP);
        append_u32(&mut blob, A64_BLR_X10);
        let literal_offset = arm64_append_literal(&mut blob, 0x1234_5000);
        let ret_trampoline_word = blob.len() / 4;
        append_u32(&mut blob, A64_MOV_X7_X0);
        let ldr = a64_ldr_lit64(10, 0, literal_offset).unwrap();
        blob[0..4].copy_from_slice(&ldr.to_le_bytes());

        let err =
            validate_arm64_kernel_blob_control_flow(&blob, 2, ret_trampoline_word).unwrap_err();
        assert!(err.to_string().contains("register-indirect call blr x10"));
    }

    #[test]
    fn arm64_kernel_blob_control_flow_rejects_non_tail_br() {
        let mut blob = Vec::new();
        for word in [A64_NOP, a64_br(0).unwrap(), A64_MOV_X7_X0] {
            blob.extend_from_slice(&word.to_le_bytes());
        }

        let err = validate_arm64_kernel_blob_control_flow(&blob, 2, 2).unwrap_err();
        assert!(err.to_string().contains("branch br x0"));
    }

    #[test]
    fn arm64_helper_id_dead_load_read_tracking_is_conservative() {
        let helper_load = a64_movz(8, 1, 0).unwrap();
        assert_eq!(a64_known_helper_id_load(helper_load), Some((8, 1)));
        assert!(!a64_maybe_reads_gpr(helper_load, 8));
        assert!(!a64_maybe_reads_gpr(0xd63f_0100, 8));
        assert!(!a64_maybe_reads_gpr(a64_mov_reg64_word(8, 0).unwrap(), 8));
        assert!(a64_maybe_reads_gpr(a64_add_imm64(0, 8, 8).unwrap(), 8));
        assert!(a64_maybe_reads_gpr(a64_str_u64(8, 31, 0).unwrap(), 8));
    }

    #[test]
    fn arm64_written_gpr_covers_common_map_pointer_clobbers() {
        assert_eq!(a64_written_gprs(0xf940_27e8)[0], Some(8)); // ldr x8, [sp, #72]
        assert_eq!(a64_written_gprs(0xf85e_83a8)[0], Some(8)); // ldur x8, [x29, #-24]
        assert_eq!(a64_written_gprs(0xd538_4100)[0], Some(0)); // mrs x0, sp_el0
        assert_eq!(a64_written_gprs(0x9101_23e0)[0], Some(0)); // add x0, sp, #0x48
        assert_eq!(a64_written_gprs(0x8b16_0288)[0], Some(8)); // add x8, x20, x22
        assert_eq!(a64_written_gprs(0x5308_7ec8)[0], Some(8)); // lsr w8, w22, #8
        assert_eq!(a64_written_gprs(0x9240_3908)[0], Some(8)); // and x8, x8, #0x7fff
        assert_eq!(a64_written_gprs(0xaa00_03f7)[0], Some(23)); // mov x23, x0
        assert_eq!(a64_written_gprs(0xa97d_a7a8), [Some(8), Some(9), None]); // ldp x8, x9, [x29, #-48]
        assert_eq!(a64_written_gprs(0xb802_4d28)[0], Some(9)); // str w8, [x9, #0x24]!
        assert_eq!(a64_written_gprs(0xb843_4e69), [Some(9), Some(19), None]); // ldr w9, [x19, #0x34]!
        assert_eq!(a64_written_gprs(0x3848_8d2a), [Some(10), Some(9), None]); // ldrb w10, [x9, #0x88]!
        assert_eq!(a64_written_gprs(0xb81e_03bf), [None, None, None]); // stur wzr, [x29, #-0x20]
    }

    #[test]
    fn arm64_helper_call_uses_arm64_reloc_placeholder() {
        let mut helper_addrs = HashMap::new();
        helper_addrs.insert("bpf_ktime_get_ns".to_string(), 0xffff_0000_1234_5000);
        let mut lookup_call_counter = 0;
        let mut update_call_counter = 0;
        let mut reg_map_names: [Option<String>; 32] = std::array::from_fn(|_| None);
        let mut lookup_site_used = Vec::new();
        let mut update_site_by_map = HashMap::new();
        let mut helper_literal_loads = Vec::new();
        let mut native_relocs = Vec::new();

        let words = build_arm64_helper_call(
            "bpf_ktime_get_ns",
            "hot_path",
            0x20,
            0x40,
            true,
            &helper_addrs,
            &HashSet::new(),
            &[],
            &HashMap::new(),
            &[],
            0,
            &[],
            None,
            &mut lookup_call_counter,
            &mut update_call_counter,
            &mut reg_map_names,
            &mut lookup_site_used,
            &mut update_site_by_map,
            &mut helper_literal_loads,
            &mut native_relocs,
            Arm64HelperCallSlot::Bl26,
        )
        .unwrap();

        assert_eq!(words, vec![A64_BL_IMM26_PLACEHOLDER]);
        assert_eq!(native_relocs.len(), 1);
        assert_eq!(native_relocs[0].offset, 0x40);
        assert_eq!(
            native_relocs[0].kind,
            NATIVE_LAB_RELOC_HELPER_CALL_ARM64_BL26
        );
        assert_eq!(native_relocs[0].target, 0xffff_0000_1234_5000);
        assert!(helper_literal_loads.is_empty());
    }

    #[test]
    fn arm64_helper_call_uses_direct_or_far_reloc_placeholder() {
        let mut helper_addrs = HashMap::new();
        helper_addrs.insert("bpf_ktime_get_ns".to_string(), 0xffff_0000_1234_5000);
        let mut lookup_call_counter = 0;
        let mut update_call_counter = 0;
        let mut reg_map_names: [Option<String>; 32] = std::array::from_fn(|_| None);
        let mut lookup_site_used = Vec::new();
        let mut update_site_by_map = HashMap::new();
        let mut helper_literal_loads = Vec::new();
        let mut native_relocs = Vec::new();

        let words = build_arm64_helper_call(
            "bpf_ktime_get_ns",
            "hot_path",
            0x20,
            0x40,
            true,
            &helper_addrs,
            &HashSet::new(),
            &[],
            &HashMap::new(),
            &[],
            0,
            &[],
            None,
            &mut lookup_call_counter,
            &mut update_call_counter,
            &mut reg_map_names,
            &mut lookup_site_used,
            &mut update_site_by_map,
            &mut helper_literal_loads,
            &mut native_relocs,
            Arm64HelperCallSlot::DirectOrFar,
        )
        .unwrap();

        assert_eq!(
            words,
            vec![A64_BL_IMM26_PLACEHOLDER, A64_NOP, A64_NOP, A64_NOP]
        );
        assert_eq!(native_relocs.len(), 1);
        assert_eq!(native_relocs[0].offset, 0x40);
        assert_eq!(native_relocs[0].kind, NATIVE_LAB_RELOC_HELPER_CALL_ARM64);
        assert_eq!(native_relocs[0].target, 0xffff_0000_1234_5000);
        assert!(helper_literal_loads.is_empty());
    }

    #[test]
    fn arm64_helper_call_uses_literal_load_when_far_safe() {
        let mut helper_addrs = HashMap::new();
        helper_addrs.insert("bpf_ktime_get_ns".to_string(), 0xffff_0000_1234_5000);
        let mut lookup_call_counter = 0;
        let mut update_call_counter = 0;
        let mut reg_map_names: [Option<String>; 32] = std::array::from_fn(|_| None);
        let mut lookup_site_used = Vec::new();
        let mut update_site_by_map = HashMap::new();
        let mut helper_literal_loads = Vec::new();
        let mut native_relocs = Vec::new();

        let words = build_arm64_helper_call(
            "bpf_ktime_get_ns",
            "far_path",
            0x20,
            0x40,
            true,
            &helper_addrs,
            &HashSet::new(),
            &[],
            &HashMap::new(),
            &[],
            0,
            &[],
            None,
            &mut lookup_call_counter,
            &mut update_call_counter,
            &mut reg_map_names,
            &mut lookup_site_used,
            &mut update_site_by_map,
            &mut helper_literal_loads,
            &mut native_relocs,
            Arm64HelperCallSlot::FarSafe,
        )
        .unwrap();

        assert_eq!(words, vec![A64_NOP, A64_BLR_X10]);
        assert!(native_relocs.is_empty());
        assert_eq!(helper_literal_loads.len(), 1);
        assert_eq!(helper_literal_loads[0].word_index, 0x40 / 4);
        assert_eq!(helper_literal_loads[0].target, 0xffff_0000_1234_5000);
    }

    #[test]
    fn arm64_percpu_array_lookup_records_mrs_reloc() {
        let mut lookup_call_counter = 0;
        let mut update_call_counter = 0;
        let mut reg_map_names: [Option<String>; 32] = std::array::from_fn(|_| None);
        reg_map_names[0] = Some("signal_data_map".to_string());
        let mut lookup_site_used = Vec::new();
        let mut update_site_by_map = HashMap::new();
        let mut helper_literal_loads = Vec::new();
        let mut native_relocs = Vec::new();
        let lookup_maps = HashMap::from([(
            "signal_data_map".to_string(),
            LookupSiteSpec {
                kind: LookupKind::PerCpuArray,
                target_addr: 0,
                key_offset: 0,
                max_entries: 1,
                elem_size: 8,
                index_mask: 0,
                value_offset: 304,
                percpu_base_addr: 0,
                map_name: Some("signal_data_map".to_string()),
            },
        )]);

        let words = build_arm64_helper_call(
            "bpf_map_lookup_elem",
            "heartbeat_capture",
            0x20,
            0x80,
            true,
            &HashMap::new(),
            &HashSet::new(),
            &[],
            &lookup_maps,
            &[],
            0,
            &[],
            None,
            &mut lookup_call_counter,
            &mut update_call_counter,
            &mut reg_map_names,
            &mut lookup_site_used,
            &mut update_site_by_map,
            &mut helper_literal_loads,
            &mut native_relocs,
            Arm64HelperCallSlot::FarSafe,
        )
        .unwrap();

        let mrs_word = words
            .iter()
            .position(|word| *word == A64_MRS_X10_TPIDR_EL1)
            .expect("per-CPU array lookup should read current CPU offset");
        assert_eq!(native_relocs.len(), 1);
        assert_eq!(native_relocs[0].offset, 0x80 + (mrs_word as u32 * 4));
        assert_eq!(native_relocs[0].kind, NATIVE_LAB_RELOC_ARM64_PERCPU_MRS);
        assert_eq!(native_relocs[0].target, 0);
        assert!(helper_literal_loads.is_empty());
    }

    #[test]
    fn arm64_get_current_task_helpers_inline_without_reloc() {
        for helper_name in ["bpf_get_current_task", "bpf_get_current_task_btf"] {
            let mut lookup_call_counter = 0;
            let mut update_call_counter = 0;
            let mut reg_map_names: [Option<String>; 32] = std::array::from_fn(|_| None);
            let mut lookup_site_used = Vec::new();
            let mut update_site_by_map = HashMap::new();
            let mut helper_literal_loads = Vec::new();
            let mut native_relocs = Vec::new();

            let words = build_arm64_helper_call(
                helper_name,
                "hot_path",
                0x20,
                0x40,
                true,
                &HashMap::new(),
                &HashSet::new(),
                &[],
                &HashMap::new(),
                &[],
                0,
                &[],
                None,
                &mut lookup_call_counter,
                &mut update_call_counter,
                &mut reg_map_names,
                &mut lookup_site_used,
                &mut update_site_by_map,
                &mut helper_literal_loads,
                &mut native_relocs,
                Arm64HelperCallSlot::Bl26,
            )
            .unwrap();

            assert_eq!(words, vec![a64_mrs_sp_el0(0).unwrap()]);
            assert!(native_relocs.is_empty());
            assert!(helper_literal_loads.is_empty());
        }
    }

    #[test]
    fn arm64_reachable_helper_id_survives_branch_around_map_load() {
        let branch_to_call = a64_patch_b_cond(0x5400_0000, 1, 4).unwrap();
        let mut bytes = Vec::new();
        for word in [
            0x5280_0038,    // mov w24, #1
            branch_to_call, // b.eq call
            0x9000_0018,    // adrp x24, map
            0xf940_0318,    // ldr x24, [x24]
            0xd63f_0300,    // blr x24
        ] {
            bytes.extend_from_slice(&u32::to_le_bytes(word));
        }

        let section = object::SectionIndex(1);
        let sym = SymInfo {
            name: "branchy_helper".to_string(),
            address: 0,
            size: bytes.len() as u64,
            section_index: section,
        };
        let mut relocs = HashMap::new();
        for (off, r_type) in [
            (8u64, R_AARCH64_ADR_GOT_PAGE),
            (12u64, R_AARCH64_LD64_GOT_LO12_NC),
        ] {
            relocs.insert(
                ((section, 0), off),
                Arm64RelocInfo {
                    r_type,
                    target_name: "some_map".to_string(),
                    target_section_index: None,
                    target_address: None,
                    addend: 0,
                },
            );
        }

        assert_eq!(
            arm64_reachable_helper_id_for_blr(&bytes, &sym, &relocs, 4, 24),
            Some(1)
        );
    }

    #[test]
    fn arm64_tbz_tbnz_branches_decode_and_patch() {
        let tbnz_x24_bit41 = 0xb648_45f8;
        assert!(a64_is_tbz_tbnz(tbnz_x24_bit41));
        assert_eq!(a64_branch_target(0, 0x36, tbnz_x24_bit41), Some(0x994));

        let patched_forward = a64_patch_tbz_tbnz(tbnz_x24_bit41, 0x100, 0x120).unwrap();
        assert_eq!(a64_branch_target(0, 0x100, patched_forward), Some(0x480));
        assert_eq!(patched_forward & 0xff00_001f, tbnz_x24_bit41 & 0xff00_001f);

        let tbnz_w0_bit31 = 0x37ff_2720; // regression shape from Cilium tail_handle_ipv
        assert!(a64_is_tbz_tbnz(tbnz_w0_bit31));
        assert_eq!(a64_branch_target(0, 0x8b1, tbnz_w0_bit31), Some(0x7a8));

        let patched_backward = a64_patch_tbz_tbnz(tbnz_w0_bit31, 0x8b1, 0x900).unwrap();
        assert_eq!(a64_branch_target(0, 0x8b1, patched_backward), Some(0x2400));
        assert_eq!(patched_backward & 0xff00_001f, tbnz_w0_bit31 & 0xff00_001f);
    }

    #[test]
    fn arm64_tbz_tbnz_long_branch_uses_reserved_slot() {
        let tbnz_w0_bit0 = 0x3700_0000;
        assert!(a64_is_tbz_tbnz(tbnz_w0_bit0));
        assert!(a64_patch_tbz_tbnz(tbnz_w0_bit0, 0, 8263).is_err());

        let mut blob = vec![0u8; 8264 * 4];
        blob[4..8].copy_from_slice(&A64_NOP.to_le_bytes());
        let patched = a64_patch_tbz_tbnz_or_long(&mut blob, tbnz_w0_bit0, 0, 8263).unwrap();

        assert!(a64_is_tbz_tbnz(patched));
        assert_eq!(patched & (1 << 24), 0);
        assert_eq!(a64_branch_target(0, 0, patched), Some(8));

        let branch = u32::from_le_bytes(blob[4..8].try_into().unwrap());
        assert!(a64_is_uncond_b(branch));
        assert_eq!(a64_branch_target(0, 1, branch), Some(8263 * 4));
    }

    #[test]
    fn arm64_tail_call_cleanup_uses_rewritten_epilogue() {
        let add_sp = a64_add_imm64(31, 31, 0x20).unwrap();
        let mut bytes = Vec::new();
        for word in [
            0xa9024ffe, // stp x30, x19, [sp, #32]
            0xd503201f, // body nop
            0xa9424ffe, // ldp x30, x19, [sp, #32]
            add_sp,     // add sp, sp, #0x20
            0xd65f03c0, // ret
        ] {
            bytes.extend_from_slice(&u32::to_le_bytes(word));
        }

        let strip = plan_arm64_entry_abi_strip(&bytes).unwrap();
        let cleanup =
            plan_arm64_tail_call_cleanup_from_terminators(&bytes, &[4], &strip.nop_word_indices)
                .unwrap();

        assert_eq!(cleanup, vec![add_sp]);
    }

    #[test]
    fn arm64_tail_call_cleanup_drops_frame_record_across_return_value_move() {
        let restore_fp_lr = 0xa9417bfd; // ldp x29, x30, [sp, #16]
        let mov_w0_wzr = 0x2a1f03e0; // mov w0, wzr
        let add_sp = a64_add_imm64(31, 31, 0x30).unwrap();
        let mut bytes = Vec::new();
        for word in [
            0xd100c3ff, // sub sp, sp, #0x30
            0xa9017bfd, // stp x29, x30, [sp, #16]
            0x910003fd, // mov x29, sp
            restore_fp_lr,
            mov_w0_wzr,
            add_sp,
            0xd65f03c0, // ret
        ] {
            bytes.extend_from_slice(&u32::to_le_bytes(word));
        }

        let strip = plan_arm64_entry_abi_strip(&bytes).unwrap();
        let cleanup =
            plan_arm64_tail_call_cleanup_from_terminators(&bytes, &[6], &strip.nop_word_indices)
                .unwrap();

        assert_eq!(cleanup, vec![restore_fp_lr, add_sp]);
    }

    #[test]
    fn arm64_tail_call_cleanup_ignores_stripped_restore_padding() {
        let add_sp = a64_add_imm64(31, 31, 0x80).unwrap();
        let ldr_lr = 0xf9402bfe; // ldr x30, [sp, #80]
        let mut bytes = Vec::new();
        for word in [
            0xa9074ff4, // stp x20, x19, [sp, #112]
            0xa90657f6, // stp x22, x21, [sp, #96]
            0xa94657f6, // ldp x22, x21, [sp, #96]
            ldr_lr, add_sp, 0xd65f03c0, // ret
            0xa9474ff4, // ldp x20, x19, [sp, #112]
            0xaa0803e0, // mov x0, x8
            ldr_lr, 0xa94657f6, // ldp x22, x21, [sp, #96]
            add_sp, 0xd65f03c0, // ret
        ] {
            bytes.extend_from_slice(&u32::to_le_bytes(word));
        }

        let strip = plan_arm64_entry_abi_strip(&bytes).unwrap();
        let cleanup = plan_arm64_tail_call_cleanup_from_terminators(
            &bytes,
            &[5, 11],
            &strip.nop_word_indices,
        )
        .unwrap();

        assert_eq!(cleanup, vec![ldr_lr, add_sp]);
    }

    #[test]
    fn arm64_tail_call_cleanup_accepts_postindexed_frame_restore() {
        let mov_w0_wzr = 0x2a1f03e0; // mov w0, wzr
        let add_sp = a64_add_imm64(31, 31, 0x1c0).unwrap();
        let ldp_x20_x19 = 0xa9444ff4; // ldp x20, x19, [sp, #0x40]
        let ldp_x22_x21 = 0xa94357f6; // ldp x22, x21, [sp, #0x30]
        let ldp_x24_x23 = 0xa9425ff8; // ldp x24, x23, [sp, #0x20]
        let ldp_x30_x25 = 0xa94167fe; // ldp x30, x25, [sp, #0x10]
        let ldr_x29_post = 0xf84507fd; // ldr x29, [sp], #0x50
        let mut bytes = Vec::new();
        for word in [
            0xd503201f, // body nop
            mov_w0_wzr,
            add_sp,
            ldp_x20_x19,
            ldp_x22_x21,
            ldp_x24_x23,
            ldp_x30_x25,
            ldr_x29_post,
            0x14000021, // b __native_link_arm64_ret_trampoline
        ] {
            bytes.extend_from_slice(&u32::to_le_bytes(word));
        }

        let cleanup =
            plan_arm64_tail_call_cleanup_from_terminators(&bytes, &[8], &HashSet::new()).unwrap();

        assert_eq!(
            cleanup,
            vec![
                add_sp,
                ldp_x20_x19,
                ldp_x22_x21,
                ldp_x24_x23,
                ldp_x30_x25,
                ldr_x29_post
            ]
        );
    }

    #[test]
    fn arm64_tail_call_detection_requires_tail_helper() {
        let mut bytes = Vec::new();
        for word in [
            0x52800028, // mov w8, #1
            0xd63f0100, // blr x8
            0x52800189, // mov w9, #12
            0xd63f0120, // blr x9
        ] {
            bytes.extend_from_slice(&u32::to_le_bytes(word));
        }
        let sym = SymInfo {
            name: "entry".to_string(),
            address: 0,
            size: bytes.len() as u64,
            section_index: object::SectionIndex(1),
        };

        assert!(arm64_symbol_has_tail_call(&bytes, &sym, &HashMap::new()));

        let non_tail = &bytes[..8];
        let sym = SymInfo {
            size: non_tail.len() as u64,
            ..sym
        };
        assert!(!arm64_symbol_has_tail_call(non_tail, &sym, &HashMap::new()));
    }

    #[test]
    fn arm64_tail_call_inline_patches_all_failure_branches() {
        let helper_addrs = HashMap::from([
            (ARM64_BPF_MAP_MAX_ENTRIES_OFFSET_KEY.to_string(), 68),
            (ARM64_BPF_ARRAY_PTRS_OFFSET_KEY.to_string(), 272),
            (ARM64_BPF_PROG_BPF_FUNC_OFFSET_KEY.to_string(), 72),
            (ARM64_TAIL_CALL_OFFSET_KEY.to_string(), 28),
        ]);
        let words = build_arm64_tail_call_inline(
            &helper_addrs,
            0x3,
            &[a64_add_imm64(31, 31, 0x20).unwrap()],
            Some(0xb0),
        )
        .unwrap();
        let out_target = Some((words.len() * 4) as u64);

        assert_eq!(a64_branch_target(0, 0, words[0]), out_target);
        assert_eq!(a64_branch_target(0, 4, words[4]), out_target);
        assert_eq!(a64_branch_target(0, 8, words[8]), out_target);
        assert_eq!(a64_branch_target(0, 12, words[12]), out_target);
        assert_eq!(a64_branch_target(0, 13, words[13]), out_target);
        assert_eq!(a64_branch_target(0, 16, words[16]), out_target);
        assert_eq!(*words.last().unwrap(), a64_br(10).unwrap());
        assert!(words.len() <= 64);
    }

    #[test]
    fn arm64_tail_call_requires_tracked_prog_array_map() {
        let helper_addrs = HashMap::from([
            (ARM64_BPF_MAP_MAX_ENTRIES_OFFSET_KEY.to_string(), 68),
            (ARM64_BPF_ARRAY_PTRS_OFFSET_KEY.to_string(), 272),
            (ARM64_BPF_PROG_BPF_FUNC_OFFSET_KEY.to_string(), 72),
            (ARM64_TAIL_CALL_OFFSET_KEY.to_string(), 28),
        ]);
        let mut lookup_call_counter = 0;
        let mut update_call_counter = 0;
        let mut reg_map_names: [Option<String>; 32] = std::array::from_fn(|_| None);
        reg_map_names[1] = Some("events".to_string());
        let mut lookup_site_used = Vec::new();
        let mut update_site_by_map = HashMap::new();
        let mut helper_literal_loads = Vec::new();
        let mut native_relocs = Vec::new();
        let err = build_arm64_helper_call(
            "bpf_tail_call",
            "tracepoint__sched",
            0x20,
            0x80,
            true,
            &helper_addrs,
            &HashSet::from(["prog_array_tp".to_string()]),
            &[],
            &HashMap::new(),
            &[],
            0,
            &[A64_NOP],
            None,
            &mut lookup_call_counter,
            &mut update_call_counter,
            &mut reg_map_names,
            &mut lookup_site_used,
            &mut update_site_by_map,
            &mut helper_literal_loads,
            &mut native_relocs,
            Arm64HelperCallSlot::Bl26,
        )
        .unwrap_err();

        assert!(err
            .to_string()
            .contains("not a link-plan tail_call_maps entry"));
    }

    #[test]
    fn arm64_proof_callee_saved_mask_wins_for_kernel_rewrite() {
        assert_eq!(arm64_effective_callee_saved_mask(Some(0xf), 0), 0xf);
        assert_eq!(arm64_effective_callee_saved_mask(None, 0xc), 0xc);
    }

    #[test]
    fn arm64_observed_callee_saved_mask_detects_unsaved_bpf_regs() {
        let mut bytes = Vec::new();
        for word in [
            0xd104_43ff, // sub sp, sp, #0x110
            0xaa00_03f4, // mov x20, x0
            0x5280_0215, // mov w21, #0x10
            0xd63f_0100, // blr x8
            0x9104_43ff, // add sp, sp, #0x110
            0xd65f_03c0, // ret
        ] {
            bytes.extend_from_slice(&u32::to_le_bytes(word));
        }

        assert_eq!(
            arm64_observed_bpf_callee_saved_mask(&bytes, &HashSet::new()) & 0x6,
            0x6
        );
    }

    #[test]
    fn arm64_observed_callee_saved_mask_ignores_stripped_save_restore_only() {
        let mut bytes = Vec::new();
        for word in [
            0xa907_4ff4, // stp x20, x19, [sp, #112]
            0xd503_201f, // body nop
            0xa947_4ff4, // ldp x20, x19, [sp, #112]
        ] {
            bytes.extend_from_slice(&u32::to_le_bytes(word));
        }
        let strip = plan_arm64_entry_abi_strip(&bytes).unwrap();

        assert_eq!(strip.callee_saved_mask, 0x3);
        assert_eq!(
            arm64_observed_bpf_callee_saved_mask(&bytes, &strip.nop_word_indices),
            0
        );
    }

    #[test]
    fn arm64_tail_call_inline_pops_proof_sidecar_callee_saved_regs() {
        let helper_addrs = HashMap::from([
            (ARM64_BPF_MAP_MAX_ENTRIES_OFFSET_KEY.to_string(), 68),
            (ARM64_BPF_ARRAY_PTRS_OFFSET_KEY.to_string(), 272),
            (ARM64_BPF_PROG_BPF_FUNC_OFFSET_KEY.to_string(), 72),
            (ARM64_TAIL_CALL_OFFSET_KEY.to_string(), 28),
        ]);
        let words = build_arm64_tail_call_inline(
            &helper_addrs,
            0xf,
            &[a64_add_imm64(31, 31, 0x80).unwrap()],
            None,
        )
        .unwrap();
        let load_bpf_func = a64_ldr_u64(10, 11, 72).unwrap();
        let load_idx = words
            .iter()
            .position(|word| *word == load_bpf_func)
            .unwrap();
        assert_eq!(words[load_idx + 1], a64_add_imm64(10, 10, 28).unwrap());
        assert_eq!(
            a64_branch_target(0, load_idx + 2, words[load_idx + 2]),
            Some((words.len() * 4) as u64)
        );
        let restore_bpf_stack =
            a64_add_imm64(31, 31, ARM64_NATIVE_LAB_STACK_RESERVE_BYTES).unwrap();

        let restore_idx = words
            .iter()
            .position(|word| *word == restore_bpf_stack)
            .unwrap();
        assert_eq!(words[restore_idx + 1], a64_ldp_post64(25, 31, 16).unwrap());
        assert_eq!(words[restore_idx + 2], a64_ldp_post64(21, 22, 16).unwrap());
        assert_eq!(words[restore_idx + 3], a64_ldp_post64(19, 20, 16).unwrap());
        assert!(load_idx + 2 < restore_idx);

        let sparse_words = build_arm64_tail_call_inline(
            &helper_addrs,
            0x1,
            &[a64_add_imm64(31, 31, 0x20).unwrap()],
            None,
        )
        .unwrap();
        let sparse_restore_idx = sparse_words
            .iter()
            .position(|word| *word == restore_bpf_stack)
            .unwrap();
        assert_eq!(
            sparse_words[sparse_restore_idx + 1],
            a64_ldp_post64(19, 25, 16).unwrap()
        );
    }

    #[test]
    fn arm64_tail_call_counter_pointer_uses_saved_x26_slot() {
        let mut bytes = Vec::new();
        for word in [
            0xd103c3ff, // sub sp, sp, #0xf0
            0xf9004bfe, // str x30, [sp, #0x90]
            0xa90b67fa, // stp x26, x25, [sp, #0xb0]
            0xd503201f, // body nop
        ] {
            bytes.extend_from_slice(&u32::to_le_bytes(word));
        }

        assert_eq!(arm64_saved_reg_stack_offset(&bytes, 26), Some(0xb0));
    }

    fn arm64_test_lookup_spec(kind: LookupKind, map_name: &str) -> LookupSiteSpec {
        LookupSiteSpec {
            kind,
            target_addr: 0x1234,
            key_offset: 8,
            max_entries: 4,
            elem_size: 16,
            index_mask: 3,
            value_offset: 32,
            percpu_base_addr: 0,
            map_name: Some(map_name.to_string()),
        }
    }

    #[test]
    fn arm64_lookup_selection_prefers_native_map_over_ordinal_order() {
        let lookup_sites = vec![
            arm64_test_lookup_spec(LookupKind::Hash, "hash_map"),
            arm64_test_lookup_spec(LookupKind::Array, "scratch_map"),
        ];
        let lookup_maps = HashMap::new();
        let mut used = vec![false; lookup_sites.len()];

        let (_label, site_index, spec) = arm64_select_lookup_site(
            &lookup_sites,
            &lookup_maps,
            &mut used,
            0,
            Some("scratch_map"),
            "entry",
            0xfeed,
        )
        .unwrap();

        assert_eq!(site_index, Some(1));
        assert!(matches!(spec.kind, LookupKind::Array));
        assert_eq!(used, vec![false, true]);
    }

    #[test]
    fn arm64_lookup_selection_uses_lookup_maps_for_extra_native_map_calls() {
        let lookup_sites = Vec::new();
        let lookup_maps = HashMap::from([(
            "cilium_xdp_scratch".to_string(),
            arm64_test_lookup_spec(LookupKind::PerCpuArray, "cilium_xdp_scratch"),
        )]);
        let mut used = Vec::new();

        let (label, site_index, spec) = arm64_select_lookup_site(
            &lookup_sites,
            &lookup_maps,
            &mut used,
            7,
            Some("cilium_xdp_scratch"),
            "cil_xdp_entry",
            0xfeed,
        )
        .unwrap();

        assert_eq!(label, "map:cilium_xdp_scratch");
        assert_eq!(site_index, None);
        assert!(matches!(spec.kind, LookupKind::PerCpuArray));
        assert_eq!(spec.max_entries, 4);
    }

    #[test]
    fn arm64_literal_pool_alignment_handles_unaligned_data() {
        let mut blob = vec![0u8; 3683];
        let literal_offset = arm64_append_literal(&mut blob, 0x1122_3344_5566_7788);

        assert_eq!(literal_offset, 3688);
        assert_eq!(literal_offset % 8, 0);
        assert!(a64_ldr_lit64(0, 0, literal_offset).is_ok());
    }
}
