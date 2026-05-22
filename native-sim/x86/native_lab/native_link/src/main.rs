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
//!   3. The entry function's SysV callee-saved register save/restore is
//!      stripped for RBX/R13-R15 when it matches the compiler's ordinary
//!      prologue/epilogue shape. RBP is kept because the x86 BPF JIT
//!      epilogue uses it as the frame pointer for `leave; ret`; R12 is kept
//!      because the x86 BPF register allocator does not map a BPF callee-saved
//!      register to host R12.
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
use iced_x86::{
    BlockEncoder, BlockEncoderOptions, Code, Decoder, DecoderOptions, FlowControl, Instruction,
    InstructionBlock, Mnemonic, OpKind, Register,
};
use object::write::{
    Object as WriteObject, Relocation as WriteRelocation, StandardSection, Symbol as WriteSymbol,
    SymbolId as WriteSymbolId, SymbolSection as WriteSymbolSection,
};
use object::{
    BinaryFormat, Endianness, Object, ObjectSection, ObjectSymbol, RelocationFlags,
    RelocationTarget, SectionKind, SymbolFlags, SymbolKind, SymbolScope,
};
use std::collections::{HashMap, HashSet};
use std::fs;
use std::path::PathBuf;

const X86_CPU_NUMBER_HELPER_KEY: &str = "__native_x86_cpu_number";
const X86_THIS_CPU_OFF_HELPER_KEY: &str = "__native_x86_this_cpu_off";
const ARM64_THREAD_INFO_CPU_OFFSET_HELPER_KEY: &str = "__native_arm64_thread_info_cpu_offset";

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

    /// BPF helper to kernel-address mapping. Repeatable.
    /// Format: NAME=HEXADDR (e.g. bpf_ktime_get_ns=0xffffffff81234567).
    /// Helper call sites against listed names are rewritten into
    /// range-independent absolute-register calls.
    #[arg(long = "helper", value_name = "NAME=ADDR")]
    helpers: Vec<String>,

    /// BPF map symbol to kernel-pointer mapping. Repeatable.
    /// Format: NAME=HEXADDR. Each GOTPCREL/PC32 relocation against the
    /// listed name is satisfied by appending a u64 literal-pool entry to
    /// the blob and rewriting the mov disp32 to point at it.
    #[arg(long = "map", value_name = "NAME=ADDR")]
    maps: Vec<String>,

    /// Per-call-site spec for every `bpf_map_lookup_elem` site in the
    /// entry program, given in BPF-source order. The runner walks the
    /// companion `.bpf.o`'s bytecode to identify which map each call uses.
    ///
    /// Preferred format:
    /// INDEX=KIND,HEXADDR,KEY_OFFSET,MAP_ADDR,MAX_ENTRIES,ELEM_SIZE,INDEX_MASK,VALUE_OFFSET,PERCPU_BASE
    /// where KIND is call/hash/array/percpu_array. The legacy
    /// INDEX=HEXADDR,OFFSET form is still accepted for standalone tests.
    ///
    /// When zero `--lookup-site` flags are supplied, every
    /// `bpf_map_lookup_elem` call falls back to the shared
    /// `--helper bpf_map_lookup_elem=ADDR` pool with no inline (legacy
    /// behavior, used by the standalone `tests/run_micro_one.sh`
    /// driver that doesn't know about the bytecode oracle).
    #[arg(
        long = "lookup-site",
        value_name = "INDEX=KIND,ADDR,KEY_OFF,MAP,MAX,ELEM,MASK,VALUE_OFF,PERCPU"
    )]
    lookup_sites: Vec<String>,

    /// Per-call-site spec for every `bpf_map_update_elem` site in the
    /// entry program, given in BPF-source order. Only ARRAY/PERCPU_ARRAY
    /// sites with simple value widths are currently inlined; `call`
    /// entries keep the normal helper call.
    ///
    /// Format:
    /// INDEX=KIND,ADDR,MAX_ENTRIES,ELEM_SIZE,VALUE_SIZE,VALUE_OFFSET,PERCPU_BASE
    /// where KIND is call/array/percpu_array.
    #[arg(
        long = "update-site",
        value_name = "INDEX=KIND,ADDR,MAX,ELEM,VALUE_SIZE,VALUE_OFF,PERCPU"
    )]
    update_sites: Vec<String>,

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
    Array,
    PerCpuArray,
}

#[derive(Clone, Copy, Debug)]
struct LookupSiteSpec {
    kind: LookupKind,
    /// Kernel address the call should route to when this site remains a call.
    target_addr: u64,
    /// HASH post-call `add rax, OFFSET` immediate. Zero means no hash inline.
    key_offset: u32,
    max_entries: u32,
    elem_size: u32,
    index_mask: u32,
    value_offset: u32,
    percpu_base_addr: u64,
}

#[derive(Clone, Copy, Debug)]
enum UpdateKind {
    Call,
    Array,
    PerCpuArray,
}

#[derive(Clone, Copy, Debug)]
struct UpdateSiteSpec {
    kind: UpdateKind,
    target_addr: u64,
    max_entries: u32,
    elem_size: u32,
    value_size: u32,
    value_offset: u32,
    percpu_base_addr: u64,
}

fn parse_lookup_sites(args: &[String]) -> Result<Vec<LookupSiteSpec>> {
    let mut by_index: Vec<(usize, LookupSiteSpec)> = Vec::new();
    for a in args {
        let (idx_s, payload) = a
            .split_once('=')
            .ok_or_else(|| anyhow!("--lookup-site expects INDEX=HEXADDR,OFFSET; got {a:?}"))?;
        let idx: usize = idx_s
            .parse()
            .map_err(|e| anyhow!("--lookup-site INDEX parse: {e}"))?;
        let parts: Vec<&str> = payload.split(',').collect();
        let spec = if parts.len() == 2 {
            let target_addr = parse_u64_auto(parts[0], "--lookup-site ADDR")?;
            let key_offset = parse_u32_auto(parts[1], "--lookup-site OFFSET")?;
            LookupSiteSpec {
                kind: if key_offset == 0 {
                    LookupKind::Call
                } else {
                    LookupKind::Hash
                },
                target_addr,
                key_offset,
                max_entries: 0,
                elem_size: 0,
                index_mask: 0,
                value_offset: 0,
                percpu_base_addr: 0,
            }
        } else if parts.len() == 9 {
            let kind = parse_lookup_kind(parts[0])?;
            let target_addr = parse_u64_auto(parts[1], "--lookup-site ADDR")?;
            let key_offset = parse_u32_auto(parts[2], "--lookup-site KEY_OFFSET")?;
            parse_u64_auto(parts[3], "--lookup-site MAP_ADDR")?;
            let max_entries = parse_u32_auto(parts[4], "--lookup-site MAX_ENTRIES")?;
            let elem_size = parse_u32_auto(parts[5], "--lookup-site ELEM_SIZE")?;
            let index_mask = parse_u32_auto(parts[6], "--lookup-site INDEX_MASK")?;
            let value_offset = parse_u32_auto(parts[7], "--lookup-site VALUE_OFFSET")?;
            let percpu_base_addr = parse_u64_auto(parts[8], "--lookup-site PERCPU_BASE")?;
            LookupSiteSpec {
                kind,
                target_addr,
                key_offset,
                max_entries,
                elem_size,
                index_mask,
                value_offset,
                percpu_base_addr,
            }
        } else {
            bail!(
                "--lookup-site payload has {} comma-separated fields; expected 2 or 9: {payload:?}",
                parts.len()
            );
        };
        by_index.push((idx, spec));
    }
    by_index.sort_by_key(|(i, _)| *i);
    for (expected, (i, _)) in by_index.iter().enumerate() {
        if *i != expected {
            bail!(
                "--lookup-site indices must be contiguous 0..N-1; missing index {expected}, \
                 found {i} at position {expected}"
            );
        }
    }
    Ok(by_index.into_iter().map(|(_, s)| s).collect())
}

fn parse_lookup_kind(s: &str) -> Result<LookupKind> {
    match s {
        "call" => Ok(LookupKind::Call),
        "hash" => Ok(LookupKind::Hash),
        "lru_hash" => Ok(LookupKind::LruHash),
        "percpu_hash" => Ok(LookupKind::PerCpuHash),
        "array" => Ok(LookupKind::Array),
        "percpu_array" => Ok(LookupKind::PerCpuArray),
        _ => bail!("unknown --lookup-site KIND {s:?}"),
    }
}

fn parse_update_sites(args: &[String]) -> Result<Vec<UpdateSiteSpec>> {
    let mut by_index: Vec<(usize, UpdateSiteSpec)> = Vec::new();
    for a in args {
        let (idx_s, payload) = a
            .split_once('=')
            .ok_or_else(|| anyhow!("--update-site expects INDEX=KIND,...; got {a:?}"))?;
        let idx: usize = idx_s
            .parse()
            .map_err(|e| anyhow!("--update-site INDEX parse: {e}"))?;
        let parts: Vec<&str> = payload.split(',').collect();
        if parts.len() != 7 {
            bail!(
                "--update-site payload has {} comma-separated fields; expected 7: {payload:?}",
                parts.len()
            );
        }
        let spec = UpdateSiteSpec {
            kind: parse_update_kind(parts[0])?,
            target_addr: parse_u64_auto(parts[1], "--update-site ADDR")?,
            max_entries: parse_u32_auto(parts[2], "--update-site MAX_ENTRIES")?,
            elem_size: parse_u32_auto(parts[3], "--update-site ELEM_SIZE")?,
            value_size: parse_u32_auto(parts[4], "--update-site VALUE_SIZE")?,
            value_offset: parse_u32_auto(parts[5], "--update-site VALUE_OFFSET")?,
            percpu_base_addr: parse_u64_auto(parts[6], "--update-site PERCPU_BASE")?,
        };
        by_index.push((idx, spec));
    }
    by_index.sort_by_key(|(i, _)| *i);
    for (expected, (i, _)) in by_index.iter().enumerate() {
        if *i != expected {
            bail!(
                "--update-site indices must be contiguous 0..N-1; missing index {expected}, \
                 found {i} at position {expected}"
            );
        }
    }
    Ok(by_index.into_iter().map(|(_, s)| s).collect())
}

fn parse_update_kind(s: &str) -> Result<UpdateKind> {
    match s {
        "call" => Ok(UpdateKind::Call),
        "array" => Ok(UpdateKind::Array),
        "percpu_array" => Ok(UpdateKind::PerCpuArray),
        _ => bail!("unknown --update-site KIND {s:?}"),
    }
}

fn parse_u64_auto(s: &str, label: &str) -> Result<u64> {
    let s = s.trim();
    if let Some(hex) = s.strip_prefix("0x") {
        u64::from_str_radix(hex, 16).map_err(|e| anyhow!("{label} parse: {e}"))
    } else {
        s.parse::<u64>().map_err(|e| anyhow!("{label} parse: {e}"))
    }
}

fn parse_u32_auto(s: &str, label: &str) -> Result<u32> {
    let value = parse_u64_auto(s, label)?;
    u32::try_from(value).map_err(|_| anyhow!("{label} does not fit u32: {value}"))
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
    let helper_addrs = parse_name_addr_args(&args.helpers, "helper")?;
    let map_addrs = parse_name_addr_args(&args.maps, "map")?;
    let lookup_sites = parse_lookup_sites(&args.lookup_sites)?;
    let update_sites = parse_update_sites(&args.update_sites)?;
    let RewriteResult {
        blob,
        relocs,
        map_patches,
        x86_callee_saved_mask,
        proof_relocs,
        proof_symbols,
    } = match elf.architecture() {
        object::Architecture::X86_64 => {
            let entry = find_symbol_by_name(&elf, &args.symbol)?;
            let included = discover_reachable(&elf, &entry)?;

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

            rewrite_x86(
                &elf,
                &entry,
                &included,
                &helper_addrs,
                &map_addrs,
                &lookup_sites,
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
                &lookup_sites,
                &update_sites,
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
            x86_callee_saved_mask,
        )?;
        eprintln!(
            "native-link: wrote proof object {} bytes, {} reloc(s) -> {}",
            blob.len(),
            proof_relocs.len(),
            args.output.display()
        );
        return Ok(());
    }
    let output_x86_callee_saved_mask = read_proof_abi(&elf)?.unwrap_or(x86_callee_saved_mask);

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
            "version\tnative-link-abi-v1\nx86_callee_saved_mask\t{}\n",
            output_x86_callee_saved_mask
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
    x86_callee_saved_mask: u8,
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
        "version\tnative-link-abi-v1\nx86_callee_saved_mask\t{}\n",
        x86_callee_saved_mask
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
                if value != "native-link-abi-v1" {
                    bail!("unsupported .native_link_abi version {value:?}");
                }
                seen_version = true;
            }
            "x86_callee_saved_mask" => {
                let parsed: u8 = value
                    .parse()
                    .with_context(|| format!("parse x86_callee_saved_mask {value:?}"))?;
                if parsed > 0xf {
                    bail!("x86_callee_saved_mask exceeds 4 bits: {parsed}");
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

fn parse_name_addr_args(args: &[String], kind: &str) -> Result<HashMap<String, u64>> {
    let mut out = HashMap::new();
    for a in args {
        let (name, addr) = a
            .split_once('=')
            .ok_or_else(|| anyhow!("invalid --{kind} {a:?}; expected NAME=HEXADDR"))?;
        let addr = addr.strip_prefix("0x").unwrap_or(addr);
        let addr =
            u64::from_str_radix(addr, 16).map_err(|e| anyhow!("invalid --{kind} {a:?}: {e}"))?;
        out.insert(name.to_string(), addr);
    }
    Ok(out)
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

/// Walk the call graph reachable from `entry` and return every symbol that
/// must be included in the blob. The entry is always at index 0; the
/// remainder are visited in discovery order so the byte layout is
/// deterministic.
fn discover_reachable(elf: &object::File, entry: &SymInfo) -> Result<Vec<SymInfo>> {
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

#[derive(Debug, Clone)]
enum PatchKind {
    /// Rewritten RET in the entry function: disp targets end-of-blob.
    JmpEnd,
    /// CALL rel32 to a discovered symbol: disp targets that symbol's new
    /// global offset in the blob.
    Call { target_symbol_address: u64 },
    /// Rewritten `mov reg, [rip+GOT]` against a map symbol. The runner
    /// patches the immediate field with the live kernel map pointer.
    MapImmediate { name: String, imm_offset: usize },
}

struct PatchInfo {
    global_offset: usize,
    kind: PatchKind,
}

struct RewriteResult {
    blob: Vec<u8>,
    relocs: Vec<RelocRecord>,
    map_patches: Vec<MapPatch>,
    x86_callee_saved_mask: u8,
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

/// Per-symbol record kept across the decode/encode phases so that ELF
/// relocations at original byte offsets can be remapped to the right
/// position in the final blob layout.
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

fn rewrite_x86(
    elf: &object::File,
    entry: &SymInfo,
    included: &[SymInfo],
    helper_addrs: &HashMap<String, u64>,
    map_addrs: &HashMap<String, u64>,
    lookup_sites: &[LookupSiteSpec],
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
    let proof_input = elf.section_by_name(".native_link_abi").is_some();

    let mut sym_global_offset: HashMap<u64, usize> = HashMap::new();
    let mut blob: Vec<u8> = Vec::new();
    let mut patches: Vec<PatchInfo> = Vec::new();
    let mut layouts: Vec<SymbolLayout> = Vec::new();
    let mut x86_callee_saved_mask: u8 = 0;
    // For each `bpf_map_lookup_elem` call site encountered in
    // entry-symbol byte order, record (symbol_addr, local_call_offset)
    // -> spec_index. Filled during the decode loop; consumed by
    // apply_elf_relocations to route each call to its own dedicated
    // literal-pool entry holding the per-site target address.
    let mut lookup_call_ordinal: HashMap<(u64, u64), usize> = HashMap::new();
    let mut lookup_call_counter: usize = 0;
    let mut update_call_counter: usize = 0;
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
            x86_callee_saved_mask = entry_abi_strip.callee_saved_mask;
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
                        if let Some(spec) = lookup_sites.get(ordinal) {
                            match spec.kind {
                                LookupKind::Array | LookupKind::PerCpuArray => {
                                    lookup_call_counter += 1;
                                    lookup_call_ordinal.insert((sym.address, local_ip), ordinal);
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
                                    if spec.target_addr == 0 {
                                        bail!(
                                            "x86 lookup-site {ordinal} is {:?} but has no target address",
                                            spec.kind
                                        );
                                    }
                                    lookup_call_counter += 1;
                                    lookup_call_ordinal.insert((sym.address, local_ip), ordinal);
                                    push_x86_absolute_helper_call(
                                        &mut local,
                                        &mut kinds,
                                        &mut insn_local_ip,
                                        local_ip,
                                        spec.target_addr,
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
                    }

                    if name == "bpf_map_update_elem" && is_entry {
                        let ordinal = update_call_counter;
                        update_call_counter += 1;
                        if let Some(spec) = update_sites.get(ordinal) {
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
                                    resolved_helper_call_sites.insert((sym.address, local_ip));
                                    continue;
                                }
                                UpdateKind::Call => {
                                    if spec.target_addr == 0 {
                                        bail!(
                                            "x86 update-site {ordinal} is call but has no target address"
                                        );
                                    }
                                    push_x86_absolute_helper_call(
                                        &mut local,
                                        &mut kinds,
                                        &mut insn_local_ip,
                                        local_ip,
                                        spec.target_addr,
                                    )?;
                                    resolved_helper_call_sites.insert((sym.address, local_ip));
                                    continue;
                                }
                            }
                        }
                    }

                    let helper_addr = *helper_addrs
                        .get(&name)
                        .ok_or_else(|| anyhow!("missing x86 helper address: {name}"))?;
                    push_x86_absolute_helper_call(
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
                        lookup_call_counter += 1;
                        lookup_call_ordinal.insert((sym.address, local_ip), ordinal);
                        if let Some(spec) = lookup_sites.get(ordinal) {
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
                        // No spec for this ordinal -> falls through to
                        // shared `bpf_map_lookup_elem` pool entry in
                        // apply_elf_relocations (legacy / standalone
                        // linker invocation).
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
        x86_callee_saved_mask,
        proof_relocs,
        proof_symbols,
    })
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

fn arm64_helper_call_sequence(helper_addr: u64) -> Result<Vec<u32>> {
    const A64_X16: u32 = 16;

    let mut words = arm64_mov_imm64_sequence(A64_X16, helper_addr)?;
    words.push(a64_blr(A64_X16)?);
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
    const A64_MRS_X10_TPIDR_EL1: u32 = 0xd538_d08a;

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

fn build_arm64_hash_lookup_postcall(spec: &LookupSiteSpec) -> Result<Vec<u32>> {
    const X0: u32 = 0;
    const A64_CBZ_X0: u32 = 0xb400_0000;

    if !matches!(spec.kind, LookupKind::Hash) {
        bail!(
            "lookup kind {:?} is not an arm64 hash post-call inline",
            spec.kind
        );
    }
    if spec.key_offset == 0 {
        bail!("arm64 hash lookup inline missing htab value offset");
    }

    let mut words = Vec::new();
    let null_branch = words.len();
    words.push(0);
    words.push(a64_add_imm64(X0, X0, spec.key_offset)?);
    let done_target = words.len();
    words[null_branch] = a64_patch_cbz_cbnz(A64_CBZ_X0, null_branch, done_target)?;
    Ok(words)
}

fn build_arm64_lru_hash_lookup_postcall(spec: &LookupSiteSpec) -> Result<Vec<u32>> {
    const X0: u32 = 0;
    const W10: u32 = 10;
    const A64_CBZ_X0: u32 = 0xb400_0000;
    const A64_CBNZ_W10: u32 = 0x3500_0000 | W10;

    if !matches!(spec.kind, LookupKind::LruHash) {
        bail!(
            "lookup kind {:?} is not an arm64 lru hash post-call inline",
            spec.kind
        );
    }
    if spec.key_offset == 0 {
        bail!("arm64 lru hash lookup inline missing htab value offset");
    }
    if spec.value_offset == 0 {
        bail!("arm64 lru hash lookup inline missing lru ref offset");
    }

    let mut words = Vec::new();
    let null_branch = words.len();
    words.push(0);
    words.push(a64_ldr_u8(W10, X0, spec.value_offset)?);
    let ref_set_branch = words.len();
    words.push(0);
    words.push(a64_movz(W10, 1, 0)?);
    words.push(a64_str_u8(W10, X0, spec.value_offset)?);
    let add_target = words.len();
    words.push(a64_add_imm64(X0, X0, spec.key_offset)?);
    let done_target = words.len();
    words[null_branch] = a64_patch_cbz_cbnz(A64_CBZ_X0, null_branch, done_target)?;
    words[ref_set_branch] = a64_patch_cbz_cbnz(A64_CBNZ_W10, ref_set_branch, add_target)?;
    Ok(words)
}

fn build_arm64_percpu_hash_lookup_postcall(spec: &LookupSiteSpec) -> Result<Vec<u32>> {
    const X0: u32 = 0;
    const X10: u32 = 10;
    const A64_CBZ_X0: u32 = 0xb400_0000;
    const A64_MRS_X10_TPIDR_EL1: u32 = 0xd538_d08a;

    if !matches!(spec.kind, LookupKind::PerCpuHash) {
        bail!(
            "lookup kind {:?} is not an arm64 percpu hash post-call inline",
            spec.kind
        );
    }
    if spec.key_offset == 0 {
        bail!("arm64 percpu hash lookup inline missing htab value offset");
    }

    let mut words = Vec::new();
    let null_branch = words.len();
    words.push(0);
    words.push(a64_add_imm64(X0, X0, spec.key_offset)?);
    words.push(a64_ldr_u64(X0, X0, 0)?);
    words.push(A64_MRS_X10_TPIDR_EL1);
    words.push(a64_add_shift64(X0, X0, X10, 0)?);
    let done_target = words.len();
    words[null_branch] = a64_patch_cbz_cbnz(A64_CBZ_X0, null_branch, done_target)?;
    Ok(words)
}

fn append_u32(blob: &mut Vec<u8>, word: u32) {
    blob.extend_from_slice(&word.to_le_bytes());
}

fn append_u64(blob: &mut Vec<u8>, value: u64) {
    blob.extend_from_slice(&value.to_le_bytes());
}

fn align_arm64_blob_to_8(blob: &mut Vec<u8>) {
    const A64_NOP: u32 = 0xd503_201f;
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
}

fn arm64_text_relocations(
    elf: &object::File,
    included: &[SymInfo],
) -> Result<HashMap<(u64, u64), Arm64RelocInfo>> {
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
            let (target_name, target_section_index) = match reloc.target() {
                RelocationTarget::Symbol(idx) => {
                    let target_sym = elf.symbol_by_index(idx)?;
                    let target_section_index = target_sym.section_index();
                    let raw_name = target_sym
                        .name()
                        .map_err(|e| anyhow!("reloc target symbol name: {e}"))?;
                    let target_name = if raw_name.is_empty() {
                        format!(
                            "__arm64_section_{:?}_addend_{}",
                            target_section_index,
                            reloc.addend()
                        )
                    } else {
                        raw_name.to_string()
                    };
                    (target_name, target_section_index)
                }
                _ => continue,
            };
            out.insert(
                (sym.address, reloc_addr - sym.address),
                Arm64RelocInfo {
                    r_type,
                    target_name,
                    target_section_index,
                    addend: reloc.addend(),
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
            if relocs
                .get(&(sym.address, (word_index * 4) as u64))
                .is_some_and(|reloc| reloc.r_type == R_AARCH64_CALL26)
            {
                continue;
            }
            let Some(target) = a64_bl_target(sym.address, word_index, insn) else {
                continue;
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

fn rewrite_arm64(
    elf: &object::File,
    entry: &SymInfo,
    included: &[SymInfo],
    helper_addrs: &HashMap<String, u64>,
    map_addrs: &HashMap<String, u64>,
    lookup_sites: &[LookupSiteSpec],
    update_sites: &[UpdateSiteSpec],
    proof_mode: bool,
    show: bool,
) -> Result<RewriteResult> {
    let mut blob = Vec::new();
    let mut sym_start_word_offset: HashMap<u64, usize> = HashMap::new();
    let mut sym_end_word_offset: HashMap<u64, usize> = HashMap::new();
    let mut addr_word_offset: HashMap<u64, usize> = HashMap::new();
    let mut patches: Vec<Arm64Patch> = Vec::new();
    let relocs = arm64_text_relocations(elf, included)?;
    let mut lookup_call_counter: usize = 0;
    let mut update_call_counter: usize = 0;
    let mut proof_relocs: Vec<ProofReloc> = Vec::new();
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

        let end = sym.address + sym.size;
        sym_start_word_offset.insert(sym.address, blob.len() / 4);
        for (local_word_index, word) in bytes.chunks_exact(4).enumerate() {
            let off = local_word_index * 4;
            let insn = u32::from_le_bytes(word.try_into().unwrap());
            let emit_word_index = blob.len() / 4;
            addr_word_offset.insert(sym.address + off as u64, emit_word_index);
            let reloc = relocs.get(&(sym.address, off as u64));

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
                        let mut helper_addr = helper_addrs.get(&reloc.target_name).copied();
                        if reloc.target_name == "bpf_map_lookup_elem" && is_entry {
                            let ordinal = lookup_call_counter;
                            lookup_call_counter += 1;
                            if let Some(spec) = lookup_sites.get(ordinal) {
                                match spec.kind {
                                    LookupKind::Array | LookupKind::PerCpuArray => {
                                        for word in build_arm64_array_lookup(spec)? {
                                            append_u32(&mut blob, word);
                                        }
                                        continue;
                                    }
                                    LookupKind::Call => {
                                        if spec.target_addr == 0 {
                                            bail!(
                                                "arm64 lookup-site {ordinal} is call but has no target address"
                                            );
                                        }
                                        helper_addr = Some(spec.target_addr);
                                    }
                                    LookupKind::Hash => {
                                        if spec.target_addr == 0 {
                                            bail!(
                                                "arm64 lookup-site {ordinal} is hash but has no target address"
                                            );
                                        }
                                        for word in arm64_helper_call_sequence(spec.target_addr)? {
                                            append_u32(&mut blob, word);
                                        }
                                        for word in build_arm64_hash_lookup_postcall(spec)? {
                                            append_u32(&mut blob, word);
                                        }
                                        continue;
                                    }
                                    LookupKind::LruHash => {
                                        if spec.target_addr == 0 {
                                            bail!(
                                                "arm64 lookup-site {ordinal} is lru_hash but has no target address"
                                            );
                                        }
                                        for word in arm64_helper_call_sequence(spec.target_addr)? {
                                            append_u32(&mut blob, word);
                                        }
                                        for word in build_arm64_lru_hash_lookup_postcall(spec)? {
                                            append_u32(&mut blob, word);
                                        }
                                        continue;
                                    }
                                    LookupKind::PerCpuHash => {
                                        if spec.target_addr == 0 {
                                            bail!(
                                                "arm64 lookup-site {ordinal} is percpu_hash but has no target address"
                                            );
                                        }
                                        for word in arm64_helper_call_sequence(spec.target_addr)? {
                                            append_u32(&mut blob, word);
                                        }
                                        for word in build_arm64_percpu_hash_lookup_postcall(spec)? {
                                            append_u32(&mut blob, word);
                                        }
                                        continue;
                                    }
                                }
                            }
                        }
                        if reloc.target_name == "bpf_map_update_elem" && is_entry {
                            let ordinal = update_call_counter;
                            update_call_counter += 1;
                            if let Some(spec) = update_sites.get(ordinal) {
                                match spec.kind {
                                    UpdateKind::Array | UpdateKind::PerCpuArray => {
                                        for word in build_arm64_array_update(spec)? {
                                            append_u32(&mut blob, word);
                                        }
                                        continue;
                                    }
                                    UpdateKind::Call => {
                                        if spec.target_addr == 0 {
                                            bail!(
                                                "arm64 update-site {ordinal} is call but has no target address"
                                            );
                                        }
                                        helper_addr = Some(spec.target_addr);
                                    }
                                }
                            }
                        }
                        let helper_addr = helper_addr.ok_or_else(|| {
                            anyhow!(
                                "arm64 CALL26 in {} at byte offset {off:#x} targets unknown helper {}",
                                sym.name,
                                reloc.target_name
                            )
                        })?;
                        for word in arm64_helper_call_sequence(helper_addr)? {
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
                        blob.extend_from_slice(&insn.to_le_bytes());
                        continue;
                    }
                    _ => {}
                }
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
                if target < sym.address || target > end {
                    bail!(
                        "arm64 branch in {} at byte offset {off:#x} targets {target:#x}, outside symbol",
                        sym.name
                    );
                }
                let target_is_symbol_end = target == end;
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

            let is_canonical_return_trampoline = !proof_mode
                && is_entry
                && insn == A64_MOV_X7_X0
                && sym.address + off as u64 + 4 == end;
            if is_entry && (a64_is_ret(insn) || is_canonical_return_trampoline) {
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

    for patch in patches.iter().filter(|p| {
        matches!(
            p.kind,
            Arm64PatchKind::ReturnToTrampoline
                | Arm64PatchKind::Bl { .. }
                | Arm64PatchKind::B { .. }
                | Arm64PatchKind::BCond { .. }
                | Arm64PatchKind::CbzCbnz { .. }
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
            _ => continue,
        };
        let off = patch.word_index * 4;
        blob[off..off + 4].copy_from_slice(&patched.to_le_bytes());
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
        relocs: Vec::new(),
        map_patches,
        x86_callee_saved_mask: 0,
        proof_relocs,
        proof_symbols,
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
        let mut end = *end_words
            .get(&sym.address)
            .ok_or_else(|| anyhow!("arm64 proof symbol {} has no end", sym.name))?
            * 4;
        if sym.address == included[0].address && end < blob_len {
            end = blob_len;
        }
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
    Ok(out)
}

fn disasm_arm64_words(blob: &[u8]) {
    eprintln!("rewritten arm64 blob ({} bytes):", blob.len());
    for (i, word) in blob.chunks_exact(4).enumerate() {
        let insn = u32::from_le_bytes(word.try_into().unwrap());
        eprintln!("  {:#06x}: {:#010x}", i * 4, insn);
    }
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
                    // If the runner supplied a `--lookup-site` for
                    // this call's BPF-source ordinal, route this site
                    // to a *dedicated* pool entry holding the
                    // per-site target (`__htab_map_lookup_elem` for
                    // HASH maps, plain `bpf_map_lookup_elem`
                    // otherwise). This avoids the old single-shared-
                    // pool-entry limitation that forced all
                    // `bpf_map_lookup_elem` calls to share one target,
                    // and lets multi-map programs get HASH-inline on
                    // their HASH lookups while keeping ARRAY/PERCPU
                    // lookups on the plain helper.
                    let mut dedicated_pool_addr: Option<u64> = None;
                    if target_name == "bpf_map_lookup_elem" {
                        // The reloc offset points at the disp32 of the
                        // 6-byte indirect call (`ff 15 dd dd dd dd`);
                        // the call's opcode is 2 bytes earlier.
                        if let Some(&ord) =
                            lookup_call_ordinal.get(&(layout.sym.address, got_call_local_off))
                        {
                            if let Some(spec) = lookup_sites.get(ord) {
                                dedicated_pool_addr = Some(spec.target_addr);
                            }
                        }
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

fn build_x86_absolute_helper_call(helper_addr: u64) -> Result<Instruction> {
    let mut bytes = Vec::new();
    append_x86_mov_reg_imm64(&mut bytes, Register::RAX, helper_addr)?;
    bytes.extend_from_slice(&[0xFF, 0xD0]); // call rax
    declared_bytes(&bytes)
}

fn push_x86_absolute_helper_call(
    local: &mut Vec<Instruction>,
    kinds: &mut Vec<Option<PatchKind>>,
    insn_local_ip: &mut Vec<u64>,
    local_ip: u64,
    helper_addr: u64,
) -> Result<()> {
    let insn = build_x86_absolute_helper_call(helper_addr)?;
    push_x86_replacement(local, kinds, insn_local_ip, local_ip, insn, None);
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
