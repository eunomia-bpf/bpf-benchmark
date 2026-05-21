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
//!   3. Compiler alignment NOPs are dropped (iced re-encodes some
//!      multi-byte NOPs to shorter forms, which would break pre-computed
//!      offset arithmetic).
//!
//! We don't strip prologue push-callee-saved or epilogue pop-callee-saved.
//! Compilers emit balanced push/pop along every control-flow path, so each
//! rewritten `RET` site already sees a balanced stack. By the time the
//! rewritten `jmp end_label` fires, the function has popped whatever it
//! pushed, and the BPF JIT prologue's saved values are intact.
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
use clap::Parser;
use iced_x86::{
    BlockEncoder, BlockEncoderOptions, Code, Decoder, DecoderOptions, FlowControl, Instruction,
    InstructionBlock, OpKind, Register,
};
use object::{Object, ObjectSection, ObjectSymbol, RelocationFlags, RelocationTarget};
use std::collections::{HashMap, HashSet};
use std::fs;
use std::path::PathBuf;

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

    /// BPF helper to kernel-address mapping. Repeatable.
    /// Format: NAME=HEXADDR (e.g. bpf_ktime_get_ns=0xffffffff81234567).
    /// Each PLT32 relocation in the input ELF against a listed name is
    /// converted to a side-band CALL_REL32 reloc with the given target.
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
    #[arg(long = "lookup-site", value_name = "INDEX=KIND,ADDR,KEY_OFF,MAP,MAX,ELEM,MASK,VALUE_OFF,PERCPU")]
    lookup_sites: Vec<String>,

    /// Print a human-readable disassembly of the rewritten blob to stderr.
    #[arg(long)]
    show: bool,
}

#[derive(Clone, Copy, Debug)]
enum LookupKind {
    Call,
    Hash,
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
    map_addr: u64,
    max_entries: u32,
    elem_size: u32,
    index_mask: u32,
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
                map_addr: 0,
                max_entries: 0,
                elem_size: 0,
                index_mask: 0,
                value_offset: 0,
                percpu_base_addr: 0,
            }
        } else if parts.len() == 9 {
            LookupSiteSpec {
                kind: parse_lookup_kind(parts[0])?,
                target_addr: parse_u64_auto(parts[1], "--lookup-site ADDR")?,
                key_offset: parse_u32_auto(parts[2], "--lookup-site KEY_OFFSET")?,
                map_addr: parse_u64_auto(parts[3], "--lookup-site MAP_ADDR")?,
                max_entries: parse_u32_auto(parts[4], "--lookup-site MAX_ENTRIES")?,
                elem_size: parse_u32_auto(parts[5], "--lookup-site ELEM_SIZE")?,
                index_mask: parse_u32_auto(parts[6], "--lookup-site INDEX_MASK")?,
                value_offset: parse_u32_auto(parts[7], "--lookup-site VALUE_OFFSET")?,
                percpu_base_addr: parse_u64_auto(parts[8], "--lookup-site PERCPU_BASE")?,
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
        "array" => Ok(LookupKind::Array),
        "percpu_array" => Ok(LookupKind::PerCpuArray),
        _ => bail!("unknown --lookup-site KIND {s:?}"),
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

fn build_x86_absolute_helper_call(target_addr: u64, local_ip: u64) -> Result<[Instruction; 2]> {
    let mut mov = Instruction::with2(Code::Mov_r64_imm64, Register::RAX, target_addr)
        .map_err(|e| anyhow!("encode movabs helper target: {e:?}"))?;
    mov.set_ip(local_ip);

    let mut call = Instruction::with1(Code::Call_rm64, Register::RAX)
        .map_err(|e| anyhow!("encode indirect helper call: {e:?}"))?;
    call.set_ip(local_ip + 10);

    Ok([mov, call])
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
    let bytes = fs::read(&args.input).with_context(|| format!("read {}", args.input.display()))?;
    let elf = object::File::parse(&*bytes)
        .with_context(|| format!("parse ELF {}", args.input.display()))?;
    let helper_addrs = parse_name_addr_args(&args.helpers, "helper")?;
    let map_addrs = parse_name_addr_args(&args.maps, "map")?;
    let lookup_sites = parse_lookup_sites(&args.lookup_sites)?;
    let RewriteResult { blob, relocs } = match elf.architecture() {
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
                args.show,
            )?
        }
        arch => bail!("unsupported input ELF arch: {:?}", arch),
    };
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
    Ok(())
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

#[derive(Debug, Clone, Copy)]
enum PatchKind {
    /// Rewritten RET in the entry function: disp targets end-of-blob.
    JmpEnd,
    /// CALL rel32 to a discovered symbol: disp targets that symbol's new
    /// global offset in the blob.
    Call { target_symbol_address: u64 },
}

struct PatchInfo {
    global_offset: usize,
    kind: PatchKind,
}

struct RewriteResult {
    blob: Vec<u8>,
    relocs: Vec<RelocRecord>,
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

fn rewrite_x86(
    elf: &object::File,
    entry: &SymInfo,
    included: &[SymInfo],
    helper_addrs: &HashMap<String, u64>,
    map_addrs: &HashMap<String, u64>,
    lookup_sites: &[LookupSiteSpec],
    show: bool,
) -> Result<RewriteResult> {
    let included_ranges: Vec<(u64, u64)> = included
        .iter()
        .map(|s| (s.address, s.address + s.size))
        .collect();

    let helper_call_sites = scan_helper_calls(elf, included)?;

    let mut sym_global_offset: HashMap<u64, usize> = HashMap::new();
    let mut blob: Vec<u8> = Vec::new();
    let mut patches: Vec<PatchInfo> = Vec::new();
    let mut layouts: Vec<SymbolLayout> = Vec::new();
    // For each `bpf_map_lookup_elem` call site encountered in
    // entry-symbol byte order, record (symbol_addr, local_call_offset)
    // -> spec_index. Filled during the decode loop; consumed by
    // apply_elf_relocations to route each call to its own dedicated
    // literal-pool entry holding the per-site target address.
    let mut lookup_call_ordinal: HashMap<(u64, u64), usize> = HashMap::new();
    let mut lookup_call_counter: usize = 0;
    let mut resolved_helper_call_sites: HashSet<(u64, u64)> = HashSet::new();

    for sym in included {
        let is_entry = sym.address == entry.address;
        let bytes = read_symbol_bytes(elf, sym)?;
        // Decode at the symbol's original vaddr so insn.near_branch_target()
        // is meaningful in the ELF address space and we can identify
        // inter-symbol call targets. Below we re-anchor each instruction
        // to a per-symbol IP=0 layout before encoding.
        let mut decoder = Decoder::with_ip(64, &bytes, sym.address, DecoderOptions::NONE);

        // Side table: per-entry patch kind, paired with each kept Instruction
        // in the symbol-local stream. `insn_local_ip` records the byte
        // offset (relative to the symbol start) where each kept
        // instruction originally lived; ELF relocations are recorded in
        // this same coordinate space.
        let mut local: Vec<Instruction> = Vec::new();
        let mut kinds: Vec<Option<PatchKind>> = Vec::new();
        let mut insn_local_ip: Vec<u64> = Vec::new();

        while decoder.can_decode() {
            let mut insn = decoder.decode();
            if insn.is_invalid() {
                bail!("iced bailed decoding {} at IP {:#x}", sym.name, insn.ip());
            }
            if is_alignment_nop(&insn) {
                continue;
            }
            validate_no_external_refs(&insn, &included_ranges)?;

            // Re-anchor to symbol-local IP=0 space.
            let local_ip = insn.ip() - sym.address;
            insn.set_ip(local_ip);

            // Translate intra-symbol branch targets into the same local
            // space. Inter-symbol calls keep their vaddr-space target
            // because we'll patch the disp32 manually after concat; what
            // matters is that we identify "this is a call to symbol X" by
            // looking up the original vaddr target.
            let original_target = insn.near_branch_target();
            let intra_symbol_branch = original_target != 0
                && original_target >= sym.address
                && original_target < sym.address + sym.size
                && matches!(
                    insn.flow_control(),
                    FlowControl::UnconditionalBranch | FlowControl::ConditionalBranch
                );
            if intra_symbol_branch {
                insn.set_near_branch64(original_target - sym.address);
            }

            // RET in the entry function -> placeholder Jmp_rel32_64. The
            // target IP is set to a value far enough from the per-symbol
            // layout IP-space [0, sym.size) that iced -- which, with
            // branch-fixing enabled, will SHRINK rel32 to rel8 when the
            // disp fits in i8 -- has to keep the 5-byte rel32 form.
            // The post-encode patcher relies on every JmpEnd site being
            // `e9 dd dd dd dd` so it can rewrite the 4-byte disp; a
            // shrunken `eb rel8` would break that assumption.
            const JMP_END_PLACEHOLDER_TARGET: u64 = 0x4000_0000;
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
                if let Some(name) = helper_call_sites.get(&(sym.address, local_ip)) {
                    let mut target_addr = helper_addrs.get(name).copied();
                    let mut inline_hash_key_offset = 0;
	                    if name == "bpf_map_lookup_elem" && is_entry {
	                        let ordinal = lookup_call_counter;
	                        lookup_call_counter += 1;
	                        lookup_call_ordinal.insert((sym.address, local_ip), ordinal);
	                        if let Some(spec) = lookup_sites.get(ordinal) {
	                            match spec.kind {
	                                LookupKind::Array | LookupKind::PerCpuArray => {
	                                    for ib in build_x86_array_lookup(spec)? {
	                                        local.push(ib);
	                                        kinds.push(None);
	                                        insn_local_ip.push(u64::MAX);
	                                    }
	                                    resolved_helper_call_sites.insert((sym.address, local_ip));
	                                    continue;
	                                }
	                                LookupKind::Call | LookupKind::Hash => {
	                                    target_addr = Some(spec.target_addr);
	                                    inline_hash_key_offset = spec.key_offset;
	                                }
	                            }
	                        }
	                    }
                    if let Some(target_addr) = target_addr {
                        let [mov, call] = build_x86_absolute_helper_call(target_addr, local_ip)?;
                        local.push(mov);
                        kinds.push(None);
                        insn_local_ip.push(local_ip);
                        local.push(call);
                        kinds.push(None);
                        insn_local_ip.push(u64::MAX);
                        resolved_helper_call_sites.insert((sym.address, local_ip));
                        if inline_hash_key_offset > 0 {
                            for ib in build_inline_hash_lookup(inline_hash_key_offset)? {
                                local.push(ib);
                                kinds.push(None);
                                insn_local_ip.push(u64::MAX);
                            }
                        }
                        continue;
                    }
                }
            }

            // Helper PLT32 placeholder: clang emits `call rel32` with the
            // 4 disp32 bytes left as 0 for the linker (us) to fill in.
            // iced sees disp=0 -> near_branch_target = next_ip, which IS
            // inside the symbol, so validate_no_external_refs passes. We
            // keep the instruction as-is; the ELF .rela.text pass below
            // emits a side-band reloc that the kernel module patches at
            // splat time.
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
                            if spec.key_offset > 0 {
                                for ib in build_inline_hash_lookup(spec.key_offset)? {
                                    local.push(ib);
                                    kinds.push(None);
                                    // The inserted bytes have no source-byte
                                    // counterpart in the symbol. Sentinel
                                    // u64::MAX excludes them from
                                    // local_ip-keyed lookups in reloc
                                    // handling.
                                    insn_local_ip.push(u64::MAX);
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
                kind: *kind,
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
        } = p.kind
        {
            let off = p.global_offset;
            if off + 5 > blob.len() || blob[off] != 0xE8 {
                bail!("CALL at off {off:#x} did not encode as Call_rel32_64");
            }
            let target_global = *sym_global_offset
                .get(&target_symbol_address)
                .ok_or_else(|| anyhow!("call target sym addr not in index map"))?;
            let disp = target_global as i64 - (off + 5) as i64;
            let d = i32::try_from(disp).map_err(|_| anyhow!("call disp {disp} exceeds i32"))?;
            blob[off + 1..off + 5].copy_from_slice(&d.to_le_bytes());
        }
    }

    // Stage 2: resolve ELF relocations. x86 helper calls become
    // side-band CALL_REL32 records because the final JIT address is only
    // known when the kernel module splats a blob chunk.
    let relocs = apply_elf_relocations(
        elf,
        &layouts,
        helper_addrs,
        map_addrs,
        lookup_sites,
        &lookup_call_ordinal,
        &resolved_helper_call_sites,
        &mut blob,
    )?;

    // Patch JmpEnd disps LAST so they target the byte AFTER any
    // trampolines we just appended -- i.e., where the BPF JIT will emit
    // the next BPF insn's code (the `exit` epilogue in our stub). A
    // rewritten `ret` inside the function body lands at the BPF JIT
    // epilogue and skips the trampolines along the way.
    let end_offset = blob.len() as i64;
    for p in &patches {
        if let PatchKind::JmpEnd = p.kind {
            let off = p.global_offset;
            if off + 5 > blob.len() || blob[off] != 0xE9 {
                bail!("JmpEnd placeholder at off {off:#x} did not encode as Jmp_rel32_64");
            }
            let disp = end_offset - (off + 5) as i64;
            let d = i32::try_from(disp).map_err(|_| anyhow!("jmp_end disp {disp} exceeds i32"))?;
            blob[off + 1..off + 5].copy_from_slice(&d.to_le_bytes());
        }
    }

    if show {
        disasm(&blob);
    }
    Ok(RewriteResult { blob, relocs })
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

fn arm64_helper_call_sequence(helper_addr: u64) -> Result<Vec<u32>> {
    const A64_X16: u32 = 16;

    let mut chunks = [0u16; 4];
    for (i, chunk) in chunks.iter_mut().enumerate() {
        *chunk = ((helper_addr >> (i * 16)) & 0xffff) as u16;
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

    let (use_movn, lane, _) = best.ok_or_else(|| anyhow!("arm64 helper call sequence empty"))?;
    let mut words = Vec::with_capacity(5);
    let first = if use_movn {
        a64_movn(A64_X16, !chunks[lane], (lane as u32) * 16)?
    } else {
        a64_movz(A64_X16, chunks[lane], (lane as u32) * 16)?
    };
    words.push(first);
    for (i, chunk) in chunks.iter().copied().enumerate() {
        if i == lane {
            continue;
        }
        let base_chunk = if use_movn { 0xffff } else { 0 };
        if chunk != base_chunk {
            words.push(a64_movk(A64_X16, chunk, (i as u32) * 16)?);
        }
    }
    words.push(a64_blr(A64_X16)?);
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
                    (
                        target_sym
                            .name()
                            .map_err(|e| anyhow!("reloc target symbol name: {e}"))?
                            .to_string(),
                        target_sym.section_index(),
                    )
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
        target_address: u64,
    },
    BCond {
        insn: u32,
        target_address: u64,
    },
    CbzCbnz {
        insn: u32,
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

fn rewrite_arm64(
    elf: &object::File,
    entry: &SymInfo,
    included: &[SymInfo],
    helper_addrs: &HashMap<String, u64>,
    map_addrs: &HashMap<String, u64>,
    show: bool,
) -> Result<RewriteResult> {
    let mut blob = Vec::new();
    let mut addr_word_offset: HashMap<u64, usize> = HashMap::new();
    let mut patches: Vec<Arm64Patch> = Vec::new();
    let relocs = arm64_text_relocations(elf, included)?;

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
        for (local_word_index, word) in bytes.chunks_exact(4).enumerate() {
            let off = local_word_index * 4;
            let insn = u32::from_le_bytes(word.try_into().unwrap());
            let emit_word_index = blob.len() / 4;
            addr_word_offset.insert(sym.address + off as u64, emit_word_index);
            let reloc = relocs.get(&(sym.address, off as u64));

            if let Some(reloc) = reloc {
                match reloc.r_type {
                    R_AARCH64_ADR_PREL_PG_HI21 => {
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
                        patches.push(Arm64Patch {
                            word_index: emit_word_index,
                            kind: Arm64PatchKind::Nop,
                        });
                        blob.extend_from_slice(&insn.to_le_bytes());
                        continue;
                    }
                    R_AARCH64_CALL26 => {
                        if !helper_addrs.contains_key(&reloc.target_name) {
                            bail!(
                                "arm64 CALL26 in {} at byte offset {off:#x} targets unknown helper {}",
                                sym.name,
                                reloc.target_name
                            );
                        }
                        let helper_addr = *helper_addrs.get(&reloc.target_name).ok_or_else(|| {
                            anyhow!("missing arm64 helper address: {}", reloc.target_name)
                        })?;
                        for word in arm64_helper_call_sequence(helper_addr)? {
                            append_u32(&mut blob, word);
                        }
                        continue;
                    }
                    R_AARCH64_ADR_GOT_PAGE => {
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
                let kind = if a64_is_uncond_b(insn) {
                    Arm64PatchKind::B {
                        target_address: target,
                    }
                } else if a64_is_b_cond(insn) {
                    Arm64PatchKind::BCond {
                        insn,
                        target_address: target,
                    }
                } else if a64_is_cbz_cbnz(insn) {
                    Arm64PatchKind::CbzCbnz {
                        insn,
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

            if is_entry && a64_is_ret(insn) {
                patches.push(Arm64Patch {
                    word_index: emit_word_index,
                    kind: Arm64PatchKind::ReturnToTrampoline,
                });
                blob.extend_from_slice(&0u32.to_le_bytes());
            } else {
                blob.extend_from_slice(&insn.to_le_bytes());
            }
        }
        addr_word_offset.insert(sym.address + sym.size, blob.len() / 4);
    }

    let mut map_literals: HashMap<String, usize> = HashMap::new();
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
    const A64_MOV_X7_X0: u32 = 0xaa00_03e7;
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
                let target_word = *addr_word_offset
                    .get(&target_symbol_address)
                    .ok_or_else(|| anyhow!("arm64 BL target sym addr not in index map"))?;
                a64_patch_bl(patch.word_index, target_word)?
            }
            Arm64PatchKind::B { target_address } => {
                let target_word = *addr_word_offset
                    .get(&target_address)
                    .ok_or_else(|| anyhow!("arm64 B target addr not in index map"))?;
                a64_patch_b(patch.word_index, target_word)?
            }
            Arm64PatchKind::BCond {
                insn,
                target_address,
            } => {
                let target_word = *addr_word_offset
                    .get(&target_address)
                    .ok_or_else(|| anyhow!("arm64 B.cond target addr not in index map"))?;
                a64_patch_b_cond(insn, patch.word_index, target_word)?
            }
            Arm64PatchKind::CbzCbnz {
                insn,
                target_address,
            } => {
                let target_word = *addr_word_offset
                    .get(&target_address)
                    .ok_or_else(|| anyhow!("arm64 CBZ/CBNZ target addr not in index map"))?;
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
    Ok(RewriteResult {
        blob,
        relocs: Vec::new(),
    })
}

fn disasm_arm64_words(blob: &[u8]) {
    eprintln!("rewritten arm64 blob ({} bytes):", blob.len());
    for (i, word) in blob.chunks_exact(4).enumerate() {
        let insn = u32::from_le_bytes(word.try_into().unwrap());
        eprintln!("  {:#06x}: {:#010x}", i * 4, insn);
    }
}

/// Resolve ELF .text relocations attached to the bytes we just encoded.
///
/// Helper calls are emitted as side-band CALL_REL32 relocations. The
/// native blob keeps a `call rel32` placeholder and the kernel module
/// patches its disp32 once the final JIT address is known.
fn apply_elf_relocations(
    elf: &object::File,
    layouts: &[SymbolLayout],
    helper_addrs: &HashMap<String, u64>,
    map_addrs: &HashMap<String, u64>,
    lookup_sites: &[LookupSiteSpec],
    lookup_call_ordinal: &HashMap<(u64, u64), usize>,
    resolved_helper_call_sites: &HashSet<(u64, u64)>,
    blob: &mut Vec<u8>,
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

    let fc = insn.flow_control();
    if matches!(
        fc,
        FlowControl::UnconditionalBranch | FlowControl::ConditionalBranch | FlowControl::Call
    ) {
        let target = insn.near_branch_target();
        if target != 0 && !in_any(target) {
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
    let value_base = spec
        .map_addr
        .checked_add(u64::from(spec.value_offset))
        .ok_or_else(|| anyhow!("array lookup value base address overflow"))?;

    let mut body = Vec::new();
    append_x86_scale_rax(&mut body, spec.elem_size)?;
    body.extend_from_slice(&[0x4C, 0x01, 0xD8]); // add rax, r11

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
    bytes.extend_from_slice(&[0x49, 0xBB]); // movabs r11, value/pptrs base
    bytes.extend_from_slice(&value_base.to_le_bytes());
    bytes.extend_from_slice(&[0x8B, 0x06]); // mov eax, [rsi]
    bytes.push(0x3D); // cmp eax, imm32
    bytes.extend_from_slice(&spec.max_entries.to_le_bytes());
    bytes.extend_from_slice(&[0x73, body_len]); // jae null
    bytes.extend_from_slice(&body);
    bytes.extend_from_slice(&[0x31, 0xC0]); // xor eax, eax

    Ok(vec![declared_bytes(&bytes)?])
}

/// Build the inline byte sequence that the BPF JIT emits after an
/// inlined `__htab_map_lookup_elem` call:
///
///     48 85 c0              test rax, rax
///     74 04                 je   2f                ; skip add on NULL
///     48 83 c0 KEY_OFFSET   add  rax, KEY_OFFSET   ; imm8 form
///   2:
///
/// 9 bytes total when `key_offset <= 127`; falls back to an 11-byte
/// `add rax, imm32` (`48 05 imm32`) when the offset exceeds imm8 range.
/// Returned as a one-instruction `iced` declared-byte chunk so the
/// encoder lays it out at the next sequential IP without trying to
/// interpret the bytes as real instructions (avoiding any chance of
/// iced rewriting the inner `je rel8` to a different size).
fn build_inline_hash_lookup(key_offset: u32) -> Result<Vec<Instruction>> {
    if key_offset <= 0x7f {
        let bytes = [
            0x48,
            0x85,
            0xC0, // test rax, rax
            0x74,
            0x04, // je +4
            0x48,
            0x83,
            0xC0,
            key_offset as u8, // add rax, imm8
        ];
        Ok(vec![declared_bytes(&bytes)?])
    } else {
        let imm = key_offset.to_le_bytes();
        // add rax, imm32 (rax-special opcode): 48 05 imm32  -> 6 bytes
        // total: 3 + 2 + 6 = 11
        let bytes = [
            0x48, 0x85, 0xC0, // test rax, rax
            0x74, 0x06, // je +6
            0x48, 0x05, imm[0], imm[1], imm[2], imm[3], // add rax, imm32
        ];
        Ok(vec![declared_bytes(&bytes)?])
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
