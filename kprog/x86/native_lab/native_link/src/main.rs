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
const A64_NOP: u32 = 0xd503_201f;

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

    /// Keep the compiler's entry-function saves in the verifier's proof input.
    #[arg(long)]
    preserve_entry_abi: bool,

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
    Lpm12,
    Hash,
    LruHash,
    PerCpuHash,
    HashOfMaps,
    Array,
    PerCpuArray,
    ArrayOfMaps,
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

#[derive(Debug)]
struct LinkSideInputs {
    helper_addrs: HashMap<String, u64>,
    map_addrs: HashMap<String, u64>,
    /// Bytes of data symbols whose map is read-only to programs and frozen (the loader reads them).
    const_values: HashMap<String, Vec<u8>>,
    lookup_sites: Vec<LookupSiteSpec>,
    lookup_maps: HashMap<String, LookupSiteSpec>,
}

#[derive(Deserialize)]
struct LinkPlan {
    version: u32,
    #[serde(default)]
    helpers: Vec<LinkPlanNameAddr>,
    #[serde(default)]
    maps: Vec<LinkPlanNameAddr>,
    #[serde(default)]
    lookup_sites: Vec<LinkPlanLookupSite>,
    #[serde(default)]
    lookup_maps: Vec<LinkPlanLookupMap>,
    #[serde(default)]
    const_values: Vec<LinkPlanConstValue>,
}

#[derive(Deserialize)]
struct LinkPlanConstValue {
    name: String,
    hex: String,
}

fn const_values_from_plan(items: Vec<LinkPlanConstValue>) -> Result<HashMap<String, Vec<u8>>> {
    let mut out = HashMap::new();
    for item in items {
        if item.hex.len() % 2 != 0 {
            bail!("link-plan const value {:?} has an odd hex length", item.name);
        }
        let bytes = (0..item.hex.len())
            .step_by(2)
            .map(|i| u8::from_str_radix(&item.hex[i..i + 2], 16))
            .collect::<std::result::Result<Vec<u8>, _>>()
            .with_context(|| format!("link-plan const value {:?}", item.name))?;
        out.insert(item.name, bytes);
    }
    Ok(out)
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
        const_values: const_values_from_plan(plan.const_values)?,
        lookup_sites: plan
            .lookup_sites
            .into_iter()
            .map(lookup_site_from_plan)
            .collect::<Result<Vec<_>>>()?,
        lookup_maps,
    })
}

fn load_link_side_inputs(args: &Args) -> Result<LinkSideInputs> {
    if let Some(path) = &args.link_plan {
        return load_link_plan(path);
    }
    Ok(LinkSideInputs {
        helper_addrs: HashMap::new(),
        map_addrs: HashMap::new(),
        const_values: HashMap::new(),
        lookup_sites: Vec::new(),
        lookup_maps: HashMap::new(),
    })
}

fn parse_lookup_kind(s: &str) -> Result<LookupKind> {
    match s {
        "call" => Ok(LookupKind::Call),
        "lpm12" => Ok(LookupKind::Lpm12),
        "hash" => Ok(LookupKind::Hash),
        "lru_hash" => Ok(LookupKind::LruHash),
        "percpu_hash" => Ok(LookupKind::PerCpuHash),
        "hash_of_maps" => Ok(LookupKind::HashOfMaps),
        "array" => Ok(LookupKind::Array),
        "percpu_array" => Ok(LookupKind::PerCpuArray),
        "array_of_maps" => Ok(LookupKind::ArrayOfMaps),
        _ => bail!("unknown lookup kind {s:?}"),
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
        LookupKind::Call | LookupKind::Lpm12 => require_call_target(spec.target_addr, context),
        LookupKind::Hash
        | LookupKind::LruHash
        | LookupKind::PerCpuHash
        | LookupKind::HashOfMaps => require_call_target(spec.target_addr, context),
        LookupKind::Array | LookupKind::PerCpuArray | LookupKind::ArrayOfMaps => {
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

/// A map update or delete on a map the plan names calls that map type's own function
/// (`<helper>@<map>`), as the verifier's fixup calls ops->map_update_elem; otherwise the helper.
fn resolve_map_call_target(
    helper_name: &str,
    map: Option<&str>,
    helper_addrs: &HashMap<String, u64>,
    context: &str,
) -> Result<u64> {
    if matches!(helper_name, "bpf_map_update_elem" | "bpf_map_delete_elem") {
        if let Some(&addr) = map.and_then(|m| helper_addrs.get(&format!("{helper_name}@{m}"))) {
            return Ok(addr);
        }
    }
    resolve_helper_target(helper_name, helper_addrs, context)
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
        const_values,
        lookup_sites,
        lookup_maps,
    } = load_link_side_inputs(&args)?;
    let RewriteResult {
        blob,
        relocs,
        map_patches,
        callee_saved_mask,
        proof_relocs,
        proof_data_relocs,
        proof_symbols,
        load_sites,
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
                &const_values,
                &lookup_sites,
                &lookup_maps,
                proof_mode,
                args.preserve_entry_abi,
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
                &const_values,
                &lookup_sites,
                &lookup_maps,
                proof_mode,
                args.preserve_entry_abi,
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
            &proof_data_relocs,
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
        let mut text = format!(
            "version\tnative-link-abi-v2\ncallee_saved_mask\t{}\n",
            output_callee_saved_mask
        );
        for site in &load_sites {
            text.push_str(&format!(
                "load_site\t{},{},{}\n",
                site.offset, site.insn_len, site.destination
            ));
        }
        fs::write(path, text).with_context(|| format!("write {}", path.display()))?;
        eprintln!("native-link: wrote ABI metadata, {} load site(s) -> {}", load_sites.len(), path.display());
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
    proof_data_relocs: &[ProofDataReloc],
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
    let mut rodata_offsets: HashMap<String, (u64, u64)> = HashMap::new();
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
        rodata_offsets.insert(reloc.symbol.clone(), (offset, data.len() as u64));
    }

    // Relocations inside an embedded table: the loader reads the table out of
    // the program's own readonly map, so each pointer slot needs its fixup.
    for reloc in proof_data_relocs {
        let &(base, size) = rodata_offsets.get(&reloc.owner).ok_or_else(|| {
            anyhow!(
                "nested proof relocation has no data owner {}",
                reloc.owner
            )
        })?;
        let width = match reloc.r_type {
            1 => 8,
            2 => 4,
            other => bail!("unsupported nested proof relocation type {other}"),
        };
        if reloc.offset.checked_add(width).is_none_or(|end| end > size) {
            bail!(
                "nested proof relocation exceeds {} or has unsupported type",
                reloc.owner
            );
        }
        let symbol = match symbol_ids.get(&reloc.symbol) {
            Some(&symbol) => symbol,
            None if reloc.r_type == 1 => {
                let symbol = object.add_symbol(WriteSymbol {
                    name: reloc.symbol.as_bytes().to_vec(),
                    value: 0,
                    size: 0,
                    kind: SymbolKind::Data,
                    scope: SymbolScope::Linkage,
                    weak: false,
                    section: WriteSymbolSection::Undefined,
                    flags: SymbolFlags::None,
                });
                symbol_ids.insert(reloc.symbol.clone(), symbol);
                symbol
            }
            None => bail!("nested proof relocation has no text target {}", reloc.symbol),
        };
        object.add_relocation(
            data_section,
            WriteRelocation {
                offset: base + reloc.offset,
                symbol,
                addend: reloc.addend,
                flags: RelocationFlags::Elf { r_type: reloc.r_type },
            },
        )?;
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

    if arch == object::Architecture::X86_64 {
        let section = object.add_section(Vec::new(), b".native_link_x86_effects".to_vec(), SectionKind::Other);
        object.append_section_data(section, &serde_json::to_vec(&x86::proof_effects(text)?)?, 1);
    }

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

fn find_symbol_at_address(elf: &object::File, address: u64) -> Option<SymInfo> {
    for sym in elf.symbols().chain(elf.dynamic_symbols()) {
        let addr = sym.address();
        let size = sym.size();
        if size == 0 {
            continue;
        }
        if address >= addr && address < addr + size {
            let name = sym.name().ok()?.to_string();
            let section_index = sym.section_index()?;
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
    proof_data_relocs: Vec<ProofDataReloc>,
    proof_symbols: Vec<ProofSymbol>,
    load_sites: Vec<LoadSite>,
}

/// A memory read of P: blob offset, instruction length, x86 GPR number (RAX = 0).
#[derive(Debug, Clone)]
struct LoadSite {
    offset: u32,
    insn_len: u16,
    destination: u16,
}

/// A relocation inside a block of embedded read-only data, resolved by the
/// linker so the loader can copy the table out of bpf_map__initial_value.
#[derive(Clone, Debug, PartialEq, Eq)]
struct ProofDataReloc {
    owner: String,
    offset: u64,
    r_type: u32,
    symbol: String,
    addend: i64,
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

fn a64_patch_tbz_tbnz(insn: u32, word_index: usize, target_index: usize) -> Result<u32> {
    let disp = target_index as i64 - word_index as i64;
    if disp < -(1 << 13) || disp >= (1 << 13) {
        bail!("arm64 TBZ/TBNZ displacement out of range: {disp}");
    }
    Ok((insn & !(0x3fff << 5)) | (((disp as u32) & 0x3fff) << 5))
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

fn a64_blr(reg: u32) -> Result<u32> {
    if reg >= 32 {
        bail!("arm64 BLR register out of range: x{reg}");
    }
    Ok(0xd63f_0000 | (reg << 5))
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

fn a64_madd64(rd: u32, rn: u32, rm: u32, ra: u32) -> Result<u32> {
    if rd >= 32 || rn >= 32 || rm >= 32 || ra >= 32 {
        bail!("arm64 MADD register out of range: x{rd}, x{rn}, x{rm}, x{ra}");
    }
    Ok(0x9b00_0000 | (rm << 16) | (ra << 10) | (rn << 5) | rd)
}

/// The general registers an instruction writes (Rd/Rt in bits 0-4, Rt2 of a load pair, Rn of a
/// pre/post-indexed access). Branches write only x30 (calls clear the call-clobbered registers).
fn a64_written_regs(insn: u32) -> Vec<usize> {
    let rd = (insn & 0x1f) as usize;
    let rn = ((insn >> 5) & 0x1f) as usize;
    let rt2 = ((insn >> 10) & 0x1f) as usize;
    if insn & 0xfff0_0000 == 0xd530_0000 {
        return vec![rd]; // MRS
    }
    if (insn >> 26) & 0x7 == 0b101 {
        return Vec::new();
    }
    if (insn >> 25) & 0b0101 == 0b0100 {
        let mut out = Vec::new();
        if (insn >> 27) & 0x7 == 0b101 {
            // load/store pair: L is bit 22; pre/post index in bits 23-24
            if insn & (1 << 22) != 0 {
                out.push(rd);
                out.push(rt2);
            }
            if matches!((insn >> 23) & 0x3, 0b01 | 0b11) {
                out.push(rn);
            }
            return out;
        }
        // single register: opc (bits 22-23) other than 00 loads
        if (insn >> 22) & 0x3 != 0 {
            out.push(rd);
        }
        if (insn >> 24) & 0x3 == 0 && insn & (1 << 21) == 0 && matches!((insn >> 10) & 0x3, 0b01 | 0b11) {
            out.push(rn);
        }
        return out;
    }
    vec![rd]
}

/// A load from a data symbol whose map is read-only to programs and frozen reads a constant (the
/// kernel's bpf_map_is_rdonly()); the unsigned-offset LDR/LDRB/LDRH/LDRSB/LDRSH/LDRSW from the
/// register holding the symbol's address becomes MOVZ/MOVK of that value.
fn a64_fold_frozen_load(
    insn: u32,
    reg_map_names: &[Option<String>; 32],
    const_values: &HashMap<String, Vec<u8>>,
) -> Result<Option<Vec<u32>>> {
    // (mask, value, access bytes, sign-extend, 64-bit destination)
    const FORMS: [(u32, u32, usize, bool, bool); 9] = [
        (0xffc0_0000, 0xb940_0000, 4, false, false), // LDR Wt
        (0xffc0_0000, 0xf940_0000, 8, false, true),  // LDR Xt
        (0xffc0_0000, 0x3940_0000, 1, false, false), // LDRB Wt
        (0xffc0_0000, 0x7940_0000, 2, false, false), // LDRH Wt
        (0xffc0_0000, 0x39c0_0000, 1, true, false),  // LDRSB Wt
        (0xffc0_0000, 0x3980_0000, 1, true, true),   // LDRSB Xt
        (0xffc0_0000, 0x79c0_0000, 2, true, false),  // LDRSH Wt
        (0xffc0_0000, 0x7980_0000, 2, true, true),   // LDRSH Xt
        (0xffc0_0000, 0xb980_0000, 4, true, true),   // LDRSW Xt
    ];
    let Some(&(_, _, width, signed, x_dest)) =
        FORMS.iter().find(|(mask, value, ..)| insn & mask == *value)
    else {
        return Ok(None);
    };
    let rt = insn & 0x1f;
    let rn = ((insn >> 5) & 0x1f) as usize;
    if rt == 31 || rn == 31 {
        return Ok(None);
    }
    let Some(value) = reg_map_names[rn].as_ref().and_then(|name| const_values.get(name)) else {
        return Ok(None);
    };
    let off = (((insn >> 10) & 0xfff) as usize) * width;
    let Some(bytes) = value.get(off..off + width) else {
        return Ok(None);
    };
    let mut raw = [0u8; 8];
    raw[..width].copy_from_slice(bytes);
    let mut v = u64::from_le_bytes(raw);
    if signed {
        let shift = 64 - 8 * width as u32;
        v = (((v << shift) as i64) >> shift) as u64;
    }
    if !x_dest {
        v &= 0xffff_ffff; // a W destination zero-extends, as the load does
    }
    let (movz, movk, chunks) = if x_dest {
        (0xd280_0000u32, 0xf280_0000u32, 4)
    } else {
        (0x5280_0000u32, 0x7280_0000u32, 2)
    };
    let mut words = vec![movz | (((v & 0xffff) as u32) << 5) | rt];
    for hw in 1..chunks {
        let part = ((v >> (16 * hw)) & 0xffff) as u32;
        if part != 0 {
            words.push(movk | ((hw as u32) << 21) | (part << 5) | rt);
        }
    }
    Ok(Some(words))
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

fn arm64_helper_call_sequence(helper_addr: u64) -> Result<Vec<u32>> {
    const A64_X10: u32 = 10;

    let mut words = arm64_mov_imm64_sequence(A64_X10, helper_addr)?;
    words.push(a64_blr(A64_X10)?);
    Ok(words)
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

/// bpf_tail_call(ctx = x0, map = x1, index = w2) as the arm64 JIT emits it in
/// the native frame: the tail-call count is at [x26] (x26 = frame record - 16;
/// P is built with -ffixed-x26), the frame's five callee-saved pairs lie below
/// it. A taken tail call leaves P's own frames behind; a refused one falls through.
fn build_arm64_tail_call_inline(helper_addrs: &HashMap<String, u64>) -> Result<Vec<u32>> {
    let key = |k: &str| -> Result<u32> {
        let v = *helper_addrs.get(k).ok_or_else(|| anyhow!("arm64 bpf_tail_call needs {k}"))?;
        u32::try_from(v).map_err(|_| anyhow!("{k} does not fit u32"))
    };
    let max_entries = key(ARM64_BPF_MAP_MAX_ENTRIES_OFFSET_KEY)?;
    let ptrs = key(ARM64_BPF_ARRAY_PTRS_OFFSET_KEY)?;
    let bpf_func = key(ARM64_BPF_PROG_BPF_FUNC_OFFSET_KEY)?;
    let entry = key(ARM64_TAIL_CALL_OFFSET_KEY)?;
    if max_entries % 4 != 0 || max_entries / 4 > 0xfff || ptrs > 0xfff
        || bpf_func % 8 != 0 || bpf_func / 8 > 0xfff || entry > 0xfff {
        bail!("arm64 bpf_tail_call offsets exceed their encodings");
    }
    let add_imm = |rd: u32, rn: u32, imm: u32| 0x9100_0000 | (imm << 10) | (rn << 5) | rd;
    let mut w = vec![
        0x2a02_03e2,                                             // mov w2, w2
        0xb940_0000 | ((max_entries / 4) << 10) | (1 << 5) | 16, // ldr w16, [x1, #max_entries]
        0x6b10_005f,                                             // cmp w2, w16
        0,                                                       // b.hs out
        0xf940_0350,                                             // ldr x16, [x26]
        0xf100_861f,                                             // cmp x16, #33 (MAX_TAIL_CALL_CNT)
        0,                                                       // b.hs out
        add_imm(15, 1, ptrs),                                    // add x15, x1, #ptrs
        0xf862_79ee,                                             // ldr x14, [x15, x2, lsl #3]
        0,                                                       // cbz x14, out
        0x9100_0610,                                             // add x16, x16, #1
        0xf900_0350,                                             // str x16, [x26]
        0xd101_435f,                                             // sub sp, x26, #80
        add_imm(29, 26, 16),                                     // add x29, x26, #16
        0xa8c1_73fb, 0xa8c1_6bf9, 0xa8c1_63f7, 0xa8c1_5bf5, 0xa8c1_53f3, // ldp x27,x28 ... x19,x20, [sp], #16
        0xf940_0000 | ((bpf_func / 8) << 10) | (14 << 5) | 16,   // ldr x16, [x14, #bpf_func]
        add_imm(16, 16, entry),                                  // add x16, x16, #entry
        0xd61f_0200,                                             // br x16
    ];
    let out = w.len() as u32;
    for (at, base) in [(3usize, 0x5400_0002u32), (6, 0x5400_0002), (9, 0xb400_000e)] {
        w[at] = base | ((out - at as u32) << 5);
    }
    Ok(w)
}

fn build_arm64_array_lookup(spec: &LookupSiteSpec) -> Result<Vec<u32>> {
    const X0: u32 = 0;
    const X1: u32 = 1;
    const X8: u32 = 8;
    const X9: u32 = 9;
    const X10: u32 = 10;
    const A64_MOV_X0_XZR: u32 = 0xaa1f_03e0;
    const A64_MRS_X10_TPIDR_EL1: u32 = 0xd538_d08a;

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

    if matches!(spec.kind, LookupKind::PerCpuArray | LookupKind::ArrayOfMaps) {
        words.push(a64_ldr_u64(X0, X0, 0)?);
    }
    if matches!(spec.kind, LookupKind::PerCpuArray) {
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
    const A64_MRS_X10_TPIDR_EL1: u32 = 0xd538_d08a;

    if matches!(
        spec.kind,
        LookupKind::Call
            | LookupKind::Lpm12
            | LookupKind::Array
            | LookupKind::PerCpuArray
            | LookupKind::ArrayOfMaps
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
        LookupKind::Call
        | LookupKind::Lpm12
        | LookupKind::Array
        | LookupKind::PerCpuArray
        | LookupKind::ArrayOfMaps => {}
    }
    let done = words.len();
    words[null_branch] = a64_patch_cbz_cbnz(words[null_branch], null_branch, done)?;
    Ok(words)
}

fn append_u32(blob: &mut Vec<u8>, word: u32) {
    blob.extend_from_slice(&word.to_le_bytes());
}

fn append_u64(blob: &mut Vec<u8>, value: u64) {
    blob.extend_from_slice(&value.to_le_bytes());
}

fn align_arm64_blob_to_8(blob: &mut Vec<u8>) {
    // Section data before this point can end at any byte.
    blob.resize(blob.len().next_multiple_of(4), 0);
    if blob.len() % 8 != 0 {
        append_u32(blob, A64_NOP);
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
    let data = section
        .data()
        .with_context(|| format!("read arm64 local data section {section_index:?}"))?;
    if data.is_empty() {
        bail!("arm64 local data section {section_index:?} is empty");
    }
    blob.extend_from_slice(data);
    local_data.insert(section_index, offset);
    Ok(offset)
}

const R_AARCH64_ADR_PREL_PG_HI21: u32 = 275;
const R_AARCH64_ADD_ABS_LO12_NC: u32 = 277;
const R_AARCH64_CALL26: u32 = 283;
const R_AARCH64_ADR_GOT_PAGE: u32 = 311;
const R_AARCH64_LD64_GOT_LO12_NC: u32 = 312;

#[derive(Clone, Debug)]
struct Arm64RelocInfo {
    r_type: u32,
    target_name: String,
    target_section_index: Option<object::SectionIndex>,
    addend: i64,
    /// A call into this object's own text: the callee's address.
    text_target: Option<u64>,
}

fn arm64_text_relocations(
    elf: &object::File,
    included: &[SymInfo],
) -> Result<HashMap<(object::SectionIndex, u64, u64), Arm64RelocInfo>> {
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
            let mut section_symbol_value: i64 = 0;
            let mut text_target = None;
            let (target_name, target_section_index) = match reloc.target() {
                RelocationTarget::Symbol(idx) => {
                    let target_sym = elf.symbol_by_index(idx)?;
                    let target_section_index = target_sym.section_index();
                    let raw_name = target_sym
                        .name()
                        .map_err(|e| anyhow!("reloc target symbol name: {e}"))?;
                    // Section-symbol data targets: one name per section (proof mode
                    // copies the whole section, as the x86 path does).
                    let target_text = target_section_index
                        .and_then(|i| elf.section_by_index(i).ok())
                        .is_some_and(|s| s.kind() == object::SectionKind::Text);
                    if target_text {
                        text_target = Some((target_sym.address() as i64 + reloc.addend()) as u64);
                    }
                    let target_name = if raw_name.is_empty() && !target_text {
                        format!("__arm64_section_{:?}", target_section_index)
                    } else if raw_name.is_empty() {
                        format!(
                            "__arm64_section_{:?}_addend_{}",
                            target_section_index,
                            reloc.addend()
                        )
                    } else {
                        raw_name.to_string()
                    };
                    // A proof object's copy of a section is a defined symbol: the target
                    // is its value plus the offset the relocation carries.
                    if raw_name.starts_with("__arm64_section_") && target_section_index.is_some() {
                        section_symbol_value = target_sym.address() as i64;
                    }
                    (target_name, target_section_index)
                }
                _ => continue,
            };
            // Section addresses are all 0 in an object file: the section
            // keeps functions of different sections apart.
            out.insert(
                (section_index, sym.address, reloc_addr - sym.address),
                Arm64RelocInfo {
                    r_type,
                    target_name,
                    target_section_index,
                    addend: section_symbol_value + reloc.addend(),
                    text_target,
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
    let data = section
        .data()
        .with_context(|| format!("read arm64 proof data section {section_index:?}"))?;
    // A section-symbol target carries the whole section (zeros for .bss); the
    // relocation keeps its offset into it.
    if reloc.target_name.starts_with("__arm64_section_") {
        return Ok(if data.is_empty() { vec![0; section.size() as usize] } else { data.to_vec() });
    }
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

fn discover_reachable_arm64(elf: &object::File, entry: &SymInfo) -> Result<Vec<SymInfo>> {
    let mut included: Vec<SymInfo> = vec![entry.clone()];
    let mut seen: std::collections::HashSet<u64> = [entry.address].into_iter().collect();
    let mut queue: Vec<SymInfo> = vec![entry.clone()];

    while let Some(sym) = queue.pop() {
        let bytes = read_symbol_bytes(elf, &sym)?;
        if bytes.len() % 4 != 0 {
            bail!("arm64 symbol {} size must be a multiple of 4", sym.name);
        }
        let relocs = arm64_text_relocations(elf, std::slice::from_ref(&sym))?;
        for (word_index, word) in bytes.chunks_exact(4).enumerate() {
            let insn = u32::from_le_bytes(word.try_into().unwrap());
            let call = relocs
                .get(&(sym.section_index, sym.address, (word_index * 4) as u64))
                .filter(|reloc| reloc.r_type == R_AARCH64_CALL26);
            let target = match call {
                Some(reloc) => match reloc.text_target {
                    Some(target) => target,
                    None => continue,
                },
                None => match a64_bl_target(sym.address, word_index, insn) {
                    Some(target) => target,
                    None => continue,
                },
            };
            if seen.contains(&target) {
                continue;
            }
            let called = find_symbol_at_address(elf, target).ok_or_else(|| {
                anyhow!(
                    "{} calls {target:#x} but no symbol covers that address",
                    sym.name
                )
            })?;
            if called.address != target {
                bail!(
                    "{} calls {target:#x}, which lands inside {} at {:#x}",
                    sym.name,
                    called.name,
                    called.address
                );
            }
            if seen.insert(called.address) {
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
        target_symbol_address: u64,
    },
    B {
        source_symbol_address: u64,
        target_is_symbol_end: bool,
        target_address: u64,
    },
    BCond {
        insn: u32,
        source_symbol_address: u64,
        target_is_symbol_end: bool,
        target_address: u64,
    },
    CbzCbnz {
        insn: u32,
        source_symbol_address: u64,
        target_is_symbol_end: bool,
        target_address: u64,
    },
    TbzTbnz {
        insn: u32,
        address: u64,
        source_symbol_address: u64,
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
}

fn plan_arm64_entry_abi_strip(bytes: &[u8]) -> Result<Arm64EntryAbiStrip> {
    let mut out = Arm64EntryAbiStrip::default();
    let mut save_counts = [0i32; 4];
    let mut restore_counts = [0i32; 4];

    for (word_index, word) in bytes.chunks_exact(4).enumerate() {
        let insn = u32::from_le_bytes(word.try_into().unwrap());
        let Some((is_load, rt, rt2)) = arm64_stp_ldp_pair_regs(insn) else {
            continue;
        };
        if !arm64_entry_pair_is_strippable(rt, rt2) {
            continue;
        }

        out.nop_word_indices.insert(word_index);
        for reg in [rt, rt2] {
            let Some(bit_index) = arm64_callee_saved_bit_index(reg) else {
                continue;
            };
            if is_load {
                restore_counts[bit_index] += 1;
            } else {
                save_counts[bit_index] += 1;
            }
        }
    }

    for (idx, (saves, restores)) in save_counts.iter().zip(restore_counts.iter()).enumerate() {
        if *saves == 0 && *restores == 0 {
            continue;
        }
        // Shrink-wrapped saves (several sites, or one side only): the entry keeps
        // its own AAPCS saves and the frame saves nothing for it.
        if *saves != 1 || *restores == 0 {
            return Ok(Arm64EntryAbiStrip::default());
        }
        out.callee_saved_mask |= 1u8 << idx;
    }

    Ok(out)
}

fn arm64_stp_ldp_pair_regs(insn: u32) -> Option<(bool, u32, u32)> {
    if (insn & 0x7c00_0000) != 0x2800_0000 {
        return None;
    }
    if (insn & 0xc000_0000) != 0x8000_0000 {
        return None;
    }
    let rn = (insn >> 5) & 0x1f;
    if rn != 31 {
        return None;
    }
    let is_load = ((insn >> 22) & 1) != 0;
    Some((is_load, insn & 0x1f, (insn >> 10) & 0x1f))
}

fn arm64_entry_pair_is_strippable(rt: u32, rt2: u32) -> bool {
    let regs = [rt, rt2];
    regs.iter()
        .all(|reg| arm64_callee_saved_bit_index(*reg).is_some() || *reg == 30)
        && regs
            .iter()
            .any(|reg| arm64_callee_saved_bit_index(*reg).is_some())
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
    addr_word_offset: &HashMap<u64, usize>,
    sym_end_word_offset: &HashMap<u64, usize>,
    source_symbol_address: u64,
    target_is_symbol_end: bool,
    target_address: u64,
) -> Result<usize> {
    if target_is_symbol_end {
        return sym_end_word_offset
            .get(&source_symbol_address)
            .copied()
            .ok_or_else(|| anyhow!("arm64 branch target symbol end not in index map"));
    }
    addr_word_offset
        .get(&target_address)
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

fn arm64_call_clobber_map_regs(reg_map_names: &mut [Option<String>; 32]) {
    for slot in reg_map_names.iter_mut().take(19) {
        *slot = None;
    }
}

/// The word indices a direct branch of the function lands on, and whether an indirect
/// branch (a jump table) may land anywhere.
fn arm64_branch_targets(bytes: &[u8]) -> (HashSet<usize>, bool) {
    let sext = |v: u32, bits: u32| -> i64 { ((v << (32 - bits)) as i32 >> (32 - bits)) as i64 };
    let mut out = HashSet::new();
    let mut indirect = false;
    for (i, w) in bytes.chunks_exact(4).enumerate() {
        let w = u32::from_le_bytes(w.try_into().unwrap());
        let off = if w & 0xffff_fc1f == 0xd61f_0000 {
            indirect = true; // br xN
            continue;
        } else if w & 0xfc00_0000 == 0x1400_0000 {
            sext(w & 0x03ff_ffff, 26) // b
        } else if w & 0xff00_0010 == 0x5400_0000 || w & 0x7e00_0000 == 0x3400_0000 {
            sext((w >> 5) & 0x7_ffff, 19) // b.cond, cbz, cbnz
        } else if w & 0x7e00_0000 == 0x3600_0000 {
            sext((w >> 5) & 0x3fff, 14) // tbz, tbnz
        } else {
            continue;
        };
        let t = i as i64 + off;
        if t >= 0 {
            out.insert(t as usize);
        }
    }
    (out, indirect)
}

// A64 load/store encoding groups follow arch/arm64/include/asm/insn.h.
// Final native code is decoded before the appended literal/data pool.
fn arm64_load_destination(word: u32) -> Option<u16> {
    let rt = (word & 31) as u16;
    let gpr = |reg: u16| if reg < 31 { reg } else { u16::MAX };
    let vector = word & (1 << 26) != 0;

    // CAS/CASP return the observed value through Rs, including acquire/release.
    if word & 0x3fa0_7c00 == 0x08a0_7c00 ||
       word & 0xbfa0_7c00 == 0x0820_7c00 {
        return Some(gpr(((word >> 16) & 31) as u16));
    }
    // Literal LDR/LDRSW; PRFM literal is an architectural hint.
    if word & 0x3b00_0000 == 0x1800_0000 {
        if !vector && word >> 30 == 3 { return None; }
        return Some(if vector { u16::MAX } else { gpr(rt) });
    }
    // LDP/LDNP/LDPSW, including offset and pre/post-index addressing.
    if word & 0x3a40_0000 == 0x2840_0000 {
        return Some(if vector { u16::MAX } else { gpr(rt) });
    }
    // Exclusive/acquire loads, including the two-result LDXP/LDAXP forms.
    if word & 0x3f40_0000 == 0x0840_0000 {
        return Some(gpr(rt));
    }
    // LSE atomic read/modify/write, including the XZR store aliases.
    if word & 0x3b20_0c00 == 0x3820_0000 {
        return Some(gpr(rt));
    }
    // Scalar/SIMD single loads: unsigned, signed, unscaled, register offset,
    // unprivileged and writeback forms share the same load/store opc field.
    if word & 0x3a00_0000 == 0x3800_0000 {
        let opc = (word >> 22) & 3;
        if vector {
            return if opc & 1 != 0 { Some(u16::MAX) } else { None };
        }
        if opc == 0 || (opc == 2 && word >> 30 == 3) { return None; }
        return Some(gpr(rt));
    }
    // Advanced SIMD load-structure groups use the saved-vector recovery scope.
    if word & 0xbe40_0000 == 0x0c40_0000 {
        return Some(u16::MAX);
    }
    None
}

fn arm64_decoded_load_sites(blob: &[u8], code_word_count: usize) -> Vec<LoadSite> {
    blob[..code_word_count * 4].chunks_exact(4).enumerate()
        .filter_map(|(index, bytes)| {
            let word = u32::from_le_bytes(bytes.try_into().unwrap());
            arm64_load_destination(word).map(|destination| LoadSite {
                offset: (index * 4) as u32,
                insn_len: 4,
                destination,
            })
        }).collect()
}

/// The TBZ/TBNZ instructions whose target ended up beyond their 14-bit reach.
#[derive(Debug)]
struct TbzOutOfRange(Vec<u64>);

impl std::fmt::Display for TbzOutOfRange {
    fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result {
        write!(f, "arm64 TBZ/TBNZ out of range at {:x?}", self.0)
    }
}

impl std::error::Error for TbzOutOfRange {}

/// A TBZ/TBNZ reaches 32 KiB; calls expanded in between can move its target farther.
/// Those become an inverted test over a B, and the layout is redone until every branch reaches.
fn rewrite_arm64(
    elf: &object::File,
    entry: &SymInfo,
    included: &[SymInfo],
    helper_addrs: &HashMap<String, u64>,
    map_addrs: &HashMap<String, u64>,
    const_values: &HashMap<String, Vec<u8>>,
    lookup_sites: &[LookupSiteSpec],
    lookup_maps: &HashMap<String, LookupSiteSpec>,
    proof_mode: bool,
    preserve_entry_abi: bool,
    show: bool,
) -> Result<RewriteResult> {
    let mut long_tbz: HashSet<u64> = HashSet::new();
    loop {
        let result = rewrite_arm64_pass(
            elf, entry, included, helper_addrs, map_addrs, const_values, lookup_sites,
            lookup_maps, proof_mode, preserve_entry_abi, show, &long_tbz,
        );
        let far = match &result {
            Err(e) => match e.downcast_ref::<TbzOutOfRange>() {
                Some(TbzOutOfRange(far)) => far.clone(),
                None => return result,
            },
            Ok(_) => return result,
        };
        let before = long_tbz.len();
        long_tbz.extend(far);
        if long_tbz.len() == before {
            return result;
        }
    }
}

fn rewrite_arm64_pass(
    elf: &object::File,
    entry: &SymInfo,
    included: &[SymInfo],
    helper_addrs: &HashMap<String, u64>,
    map_addrs: &HashMap<String, u64>,
    const_values: &HashMap<String, Vec<u8>>,
    lookup_sites: &[LookupSiteSpec],
    lookup_maps: &HashMap<String, LookupSiteSpec>,
    proof_mode: bool,
    preserve_entry_abi: bool,
    show: bool,
    long_tbz: &HashSet<u64>,
) -> Result<RewriteResult> {
    let mut blob = Vec::new();
    let mut sym_start_word_offset: HashMap<u64, usize> = HashMap::new();
    let mut sym_end_word_offset: HashMap<u64, usize> = HashMap::new();
    let mut addr_word_offset: HashMap<u64, usize> = HashMap::new();
    let mut patches: Vec<Arm64Patch> = Vec::new();
    let relocs = arm64_text_relocations(elf, included)?;
    let mut proof_relocs: Vec<ProofReloc> = Vec::new();
    let mut callee_saved_mask: u8 = 0;
    const A64_MOV_X7_X0: u32 = 0xaa00_03e7;
    for sym in included {
        let is_entry = sym.address == entry.address;
        let bytes = read_symbol_bytes(elf, sym)?;
        if bytes.is_empty() || bytes.len() % 4 != 0 {
            bail!(
                "arm64 symbol {} size must be a non-zero multiple of 4",
                sym.name
            );
        }
        let entry_abi_strip = if is_entry && !(proof_mode && preserve_entry_abi) {
            plan_arm64_entry_abi_strip(&bytes)?
        } else {
            Arm64EntryAbiStrip::default()
        };
        if is_entry {
            callee_saved_mask = entry_abi_strip.callee_saved_mask;
        }

        let end = sym.address + sym.size;
        sym_start_word_offset.insert(sym.address, blob.len() / 4);
        // The map a register holds is known only along straight-line code: at a branch
        // target another path may bring another map (a jump table may land anywhere).
        let (join_words, any_join) = arm64_branch_targets(&bytes);
        let mut reg_map_names: [Option<String>; 32] = std::array::from_fn(|_| None);
        for (local_word_index, word) in bytes.chunks_exact(4).enumerate() {
            if any_join || join_words.contains(&local_word_index) {
                reg_map_names = std::array::from_fn(|_| None);
            }
            let off = local_word_index * 4;
            let mut insn = u32::from_le_bytes(word.try_into().unwrap());
            let emit_word_index = blob.len() / 4;
            addr_word_offset.insert(sym.address + off as u64, emit_word_index);
            if is_entry && entry_abi_strip.nop_word_indices.contains(&local_word_index) {
                insn = A64_NOP;
                blob.extend_from_slice(&insn.to_le_bytes());
                continue;
            }
            let reloc = relocs.get(&(sym.section_index, sym.address, off as u64));
            if !proof_mode {
                let copied = a64_mov_reg64(insn).map(|(dst, src)| (dst, reg_map_names[src].clone()));
                for reg in a64_written_regs(insn) {
                    reg_map_names[reg] = None;
                }
                if let Some((dst, name)) = copied {
                    reg_map_names[dst] = name;
                }
                if reloc.is_none() {
                    if let Some(words) = a64_fold_frozen_load(insn, &reg_map_names, const_values)? {
                        for w in words {
                            blob.extend_from_slice(&w.to_le_bytes());
                        }
                        continue;
                    }
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
                                addend: reloc.addend,
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
                                addend: reloc.addend,
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
                        // A call into the object's own text is a call inside the blob.
                        if let Some(target) = reloc.text_target {
                            if !included.iter().any(|s| s.address == target) {
                                bail!(
                                    "arm64 call in {} at byte offset {off:#x} targets {target:#x}, outside included symbols",
                                    sym.name
                                );
                            }
                            patches.push(Arm64Patch {
                                word_index: emit_word_index,
                                kind: Arm64PatchKind::Bl {
                                    target_symbol_address: target,
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
                        if reloc.target_name == "bpf_tail_call" {
                            for word in build_arm64_tail_call_inline(helper_addrs)? {
                                append_u32(&mut blob, word);
                            }
                            arm64_call_clobber_map_regs(&mut reg_map_names);
                            continue;
                        }
                        if reloc.target_name == "bpf_get_smp_processor_id" {
                            if let Some(inline) =
                                build_arm64_get_smp_processor_id_inline(helper_addrs)?
                            {
                                for word in inline {
                                    append_u32(&mut blob, word);
                                }
                                continue;
                            }
                        }
                        // The arm64 JIT's bpf_get_current_task(_btf): current is sp_el0
                        // (arch/arm64/net/bpf_jit_comp.c, bpf_jit_inlines_helper_call).
                        if reloc.target_name == "bpf_get_current_task"
                            || reloc.target_name == "bpf_get_current_task_btf"
                        {
                            append_u32(&mut blob, a64_mrs_sp_el0(0)?);
                            continue;
                        }
                        let mut helper_addr = helper_addrs.get(&reloc.target_name).copied();
                        let mut helper_addr_from_site = false;
                        let mut lookup_postprocess = None;
                        // A map call takes the form of its own map, found by the map name in x0
                        // (lookups only); a call whose map is unknown, and every update, calls
                        // the helper, which dispatches on the map.
                        let lookup_site = if reloc.target_name == "bpf_map_lookup_elem" && is_entry {
                            reg_map_names[0].as_ref().and_then(|name| {
                                lookup_sites
                                    .iter()
                                    .find(|s| x86::lookup_site_matches_native_map(s, name))
                                    .or_else(|| name.ends_with("#inner").then(|| lookup_maps.get(name)).flatten())
                            })
                        } else {
                            None
                        };
                        // A map-in-map lookup returns an inner map, which takes the outer map's
                        // inner-template form (`<map>#inner` in the plan), as the verifier does.
                        let inner_name = if reloc.target_name == "bpf_map_lookup_elem" && is_entry {
                            reg_map_names[0]
                                .as_ref()
                                .map(|m| format!("{m}#inner"))
                                .filter(|n| lookup_maps.contains_key(n))
                        } else {
                            None
                        };
                        if let Some(spec) = lookup_site {
                            match spec.kind {
                                LookupKind::Array | LookupKind::PerCpuArray | LookupKind::ArrayOfMaps => {
                                    for word in build_arm64_array_lookup(spec)? {
                                        append_u32(&mut blob, word);
                                    }
                                    arm64_call_clobber_map_regs(&mut reg_map_names);
                                    reg_map_names[0] = inner_name;
                                    continue;
                                }
                                LookupKind::Call
                                | LookupKind::Lpm12
                                | LookupKind::Hash
                                | LookupKind::LruHash
                                | LookupKind::PerCpuHash
                                | LookupKind::HashOfMaps => {
                                    helper_addr = Some(resolve_lookup_site_target(
                                        spec,
                                        &format!("arm64 lookup-site ({:?})", spec.kind),
                                    )?);
                                    helper_addr_from_site = true;
                                    lookup_postprocess = Some(spec.clone());
                                }
                            }
                        }
                        let helper_addr = if helper_addr_from_site {
                            helper_addr.ok_or_else(|| {
                                anyhow!(
                                    "arm64 CALL26 in {} at byte offset {off:#x} has empty site target for {}",
                                    sym.name,
                                    reloc.target_name
                                )
                            })?
                        } else {
                            resolve_map_call_target(
                                &reloc.target_name,
                                reg_map_names[0].as_deref(),
                                helper_addrs,
                                &format!("arm64 helper call {}", reloc.target_name),
                            )?
                        };
                        for word in arm64_helper_call_sequence(helper_addr)? {
                            append_u32(&mut blob, word);
                        }
                        if let Some(spec) = lookup_postprocess {
                            for word in build_arm64_lookup_call_postprocess(&spec)? {
                                append_u32(&mut blob, word);
                            }
                        }
                        arm64_call_clobber_map_regs(&mut reg_map_names);
                        reg_map_names[0] = inner_name;
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
                        blob.extend_from_slice(&insn.to_le_bytes());
                        continue;
                    }
                    _ => {}
                }
            }

            // Common C lookup bodies call the kernel map operation through BLR.
            // Keep that AAPCS call and forget caller-saved map identities.
            if !proof_mode && insn & 0xffff_fc1f == 0xd63f_0000 {
                arm64_call_clobber_map_regs(&mut reg_map_names);
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
                if !included.iter().any(|s| s.address == target) {
                    bail!(
                        "arm64 BL in {} at byte offset {off:#x} targets {target:#x}, outside included symbols",
                        sym.name
                    );
                }
                patches.push(Arm64Patch {
                    word_index: emit_word_index,
                    kind: Arm64PatchKind::Bl {
                        target_symbol_address: target,
                    },
                });
                blob.extend_from_slice(&insn.to_le_bytes());
                continue;
            }

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
                if a64_is_tbz_tbnz(insn) && long_tbz.contains(&(sym.address + off as u64)) {
                    // Beyond TBZ reach after expansion: the inverted test skips a B to the target.
                    let skip_b = ((insn ^ (1 << 24)) & !(0x3fff << 5)) | (2 << 5);
                    blob.extend_from_slice(&skip_b.to_le_bytes());
                    patches.push(Arm64Patch {
                        word_index: blob.len() / 4,
                        kind: Arm64PatchKind::B {
                            source_symbol_address: sym.address,
                            target_is_symbol_end,
                            target_address: target,
                        },
                    });
                    blob.extend_from_slice(&0x1400_0000u32.to_le_bytes());
                    continue;
                }
                let kind = if a64_is_uncond_b(insn) {
                    Arm64PatchKind::B {
                        source_symbol_address: sym.address,
                        target_is_symbol_end,
                        target_address: target,
                    }
                } else if a64_is_b_cond(insn) {
                    Arm64PatchKind::BCond {
                        insn,
                        source_symbol_address: sym.address,
                        target_is_symbol_end,
                        target_address: target,
                    }
                } else if a64_is_cbz_cbnz(insn) {
                    Arm64PatchKind::CbzCbnz {
                        insn,
                        source_symbol_address: sym.address,
                        target_is_symbol_end,
                        target_address: target,
                    }
                } else if a64_is_tbz_tbnz(insn) {
                    // A call expanded between a TBZ/TBNZ and its target moves the landing
                    // point like any other branch (6e68d71a7, lost in 3aa496416).
                    Arm64PatchKind::TbzTbnz {
                        insn,
                        address: sym.address + off as u64,
                        source_symbol_address: sym.address,
                        target_is_symbol_end,
                        target_address: target,
                    }
                } else {
                    bail!(
                        "arm64 unsupported branch rewrite in {} at byte offset {off:#x}: {insn:#010x}",
                        sym.name
                    );
                };
                patches.push(Arm64Patch {
                    word_index: emit_word_index,
                    kind,
                });
            }

            if is_entry && a64_is_ret(insn) && !(proof_mode && preserve_entry_abi) {
                patches.push(Arm64Patch {
                    word_index: emit_word_index,
                    kind: Arm64PatchKind::ReturnToTrampoline,
                });
                blob.extend_from_slice(&0u32.to_le_bytes());
            } else {
                blob.extend_from_slice(&insn.to_le_bytes());
            }
        }
        sym_end_word_offset.insert(sym.address, blob.len() / 4);
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
                let section_len = section
                    .data()
                    .with_context(|| format!("read arm64 local data section {section_index:?}"))?
                    .len();
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

    align_arm64_blob_to_8(&mut blob);
    let ret_trampoline_word = blob.len() / 4;
    append_u32(&mut blob, A64_MOV_X7_X0);

    let mut far_tbz: Vec<u64> = Vec::new();
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
            Arm64PatchKind::Bl {
                target_symbol_address,
            } => {
                let target_word = *sym_start_word_offset
                    .get(&target_symbol_address)
                    .ok_or_else(|| anyhow!("arm64 BL target sym addr not in index map"))?;
                a64_patch_bl(patch.word_index, target_word)?
            }
            Arm64PatchKind::B {
                source_symbol_address,
                target_is_symbol_end,
                target_address,
            } => {
                let target_word = arm64_branch_target_word(
                    &addr_word_offset,
                    &sym_end_word_offset,
                    source_symbol_address,
                    target_is_symbol_end,
                    target_address,
                )?;
                a64_patch_b(patch.word_index, target_word)?
            }
            Arm64PatchKind::BCond {
                insn,
                source_symbol_address,
                target_is_symbol_end,
                target_address,
            } => {
                let target_word = arm64_branch_target_word(
                    &addr_word_offset,
                    &sym_end_word_offset,
                    source_symbol_address,
                    target_is_symbol_end,
                    target_address,
                )?;
                a64_patch_b_cond(insn, patch.word_index, target_word)?
            }
            Arm64PatchKind::CbzCbnz {
                insn,
                source_symbol_address,
                target_is_symbol_end,
                target_address,
            } => {
                let target_word = arm64_branch_target_word(
                    &addr_word_offset,
                    &sym_end_word_offset,
                    source_symbol_address,
                    target_is_symbol_end,
                    target_address,
                )?;
                a64_patch_cbz_cbnz(insn, patch.word_index, target_word)?
            }
            Arm64PatchKind::TbzTbnz {
                insn,
                address,
                source_symbol_address,
                target_is_symbol_end,
                target_address,
            } => {
                let target_word = arm64_branch_target_word(
                    &addr_word_offset,
                    &sym_end_word_offset,
                    source_symbol_address,
                    target_is_symbol_end,
                    target_address,
                )?;
                match a64_patch_tbz_tbnz(insn, patch.word_index, target_word) {
                    Ok(word) => word,
                    Err(_) => {
                        far_tbz.push(address);
                        continue;
                    }
                }
            }
            _ => continue,
        };
        let off = patch.word_index * 4;
        blob[off..off + 4].copy_from_slice(&patched.to_le_bytes());
    }
    if !far_tbz.is_empty() {
        return Err(TbzOutOfRange(far_tbz).into());
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
    let load_sites = if proof_mode {
        Vec::new()
    } else {
        arm64_decoded_load_sites(&blob, code_word_count)
    };
    Ok(RewriteResult {
        blob,
        relocs: Vec::new(),
        map_patches,
        callee_saved_mask,
        proof_relocs,
        proof_data_relocs: Vec::new(),
        proof_symbols,
        load_sites,
    })
}

fn arm64_proof_symbols(
    included: &[SymInfo],
    start_words: &HashMap<u64, usize>,
    end_words: &HashMap<u64, usize>,
    blob_len: usize,
) -> Result<Vec<ProofSymbol>> {
    let mut out = Vec::new();
    for sym in included {
        let start = *start_words
            .get(&sym.address)
            .ok_or_else(|| anyhow!("arm64 proof symbol {} has no start", sym.name))?
            * 4;
        let end = *end_words
            .get(&sym.address)
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
    #[test]
    fn tbz_tbnz_decode_and_retarget() {
        use super::*;
        // tbz x8, #63, +0x10c (imm14 = 67 words)
        let insn: u32 = 0xb6f8_0868;
        assert!(a64_is_tbz_tbnz(insn));
        assert!(!a64_is_cbz_cbnz(insn));
        assert_eq!(a64_branch_target(0x1000, 2, insn), Some(0x1000 + 8 + 67 * 4));
        let moved = a64_patch_tbz_tbnz(insn, 2, 2 + 83).unwrap();
        assert_eq!((moved >> 5) & 0x3fff, 83);
        assert_eq!(moved & !(0x3fff << 5), insn & !(0x3fff << 5));
        let back = a64_patch_tbz_tbnz(insn, 10, 4).unwrap();
        assert_eq!(a64_branch_target(0, 10, back), Some(16));
        assert!(a64_patch_tbz_tbnz(insn, 0, 1 << 13).is_err());
        // long form: tbnz x8, #63, +8 skips the B
        let skip_b = ((insn ^ (1 << 24)) & !(0x3fff << 5)) | (2 << 5);
        assert!(a64_is_tbz_tbnz(skip_b));
        assert_eq!(skip_b & (1 << 24), 1 << 24);
        assert_eq!(a64_branch_target(0x1000, 0, skip_b), Some(0x1008));
    }

    use super::*;

    #[test]
    fn arm64_entry_abi_strip_allows_multiple_epilogues() {
        let mut bytes = Vec::new();
        for word in [
            0xa9024ffe, // stp x30, x19, [sp, #32]
            0xd503201f, // nop
            0xa9424ffe, // ldp x30, x19, [sp, #32]
            0xa9424ffe, // ldp x30, x19, [sp, #32]
        ] {
            bytes.extend_from_slice(&u32::to_le_bytes(word));
        }

        let strip = plan_arm64_entry_abi_strip(&bytes).unwrap();
        assert_eq!(strip.callee_saved_mask, 0x1);
        assert!(strip.nop_word_indices.contains(&0));
        assert!(strip.nop_word_indices.contains(&2));
        assert!(strip.nop_word_indices.contains(&3));
        assert_eq!(strip.nop_word_indices.len(), 3);
    }
}
