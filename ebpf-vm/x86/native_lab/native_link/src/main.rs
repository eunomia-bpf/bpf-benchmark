//! native-link: minimal x86-64 ELF -> native-lab blob linker.
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
    BlockEncoder, BlockEncoderOptions, Code, Decoder, DecoderOptions, FlowControl,
    Instruction, InstructionBlock, OpKind, Register,
};
use object::{Object, ObjectSection, ObjectSymbol, RelocationFlags, RelocationTarget};
use std::collections::HashMap;
use std::fs;
use std::path::PathBuf;

#[derive(Parser, Debug)]
#[command(about = "Extract one function (plus reachable subprograms) from a userspace x86-64 ELF and rewrite it for native_lab.")]
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
    /// companion `.bpf.o`'s bytecode to identify which map each call
    /// uses, looks up that map's type, and produces one of these for
    /// each site:
    ///
    ///   - HASH map call: ADDR = `__htab_map_lookup_elem`'s kernel
    ///     address, OFFSET = `offsetof(struct htab_elem, key) +
    ///     roundup(map.key_size, 8)`. native-link allocates a
    ///     dedicated literal-pool entry, routes the `call *[rip+disp]`
    ///     to that entry, and inserts a 9- or 11-byte
    ///     `test rax,rax; je; add rax, OFFSET` chunk after the call.
    ///   - Non-HASH map call: ADDR = `bpf_map_lookup_elem`'s kernel
    ///     address, OFFSET = 0. Same routing, no inline.
    ///
    /// Format: INDEX=HEXADDR,OFFSET. INDEX is the zero-based BPF-source
    /// ordinal of this `bpf_map_lookup_elem` call. Repeatable.
    ///
    /// When zero `--lookup-site` flags are supplied, every
    /// `bpf_map_lookup_elem` call falls back to the shared
    /// `--helper bpf_map_lookup_elem=ADDR` pool with no inline (legacy
    /// behavior, used by the standalone `tests/run_micro_one.sh`
    /// driver that doesn't know about the bytecode oracle).
    #[arg(long = "lookup-site", value_name = "INDEX=HEXADDR,OFFSET")]
    lookup_sites: Vec<String>,

    /// Print a human-readable disassembly of the rewritten blob to stderr.
    #[arg(long)]
    show: bool,
}

#[derive(Clone, Copy, Debug)]
struct LookupSiteSpec {
    /// Kernel address the call should route to. For HASH this is
    /// `__htab_map_lookup_elem`; for non-HASH it's the public
    /// `bpf_map_lookup_elem`.
    target_addr: u64,
    /// Post-call `add rax, OFFSET` immediate. Zero means no inline.
    key_offset: u32,
}

fn parse_lookup_sites(args: &[String]) -> Result<Vec<LookupSiteSpec>> {
    let mut by_index: Vec<(usize, LookupSiteSpec)> = Vec::new();
    for a in args {
        let (idx_s, payload) = a.split_once('=').ok_or_else(|| {
            anyhow!("--lookup-site expects INDEX=HEXADDR,OFFSET; got {a:?}")
        })?;
        let idx: usize = idx_s
            .parse()
            .map_err(|e| anyhow!("--lookup-site INDEX parse: {e}"))?;
        let (addr_s, off_s) = payload.split_once(',').ok_or_else(|| {
            anyhow!("--lookup-site payload missing offset; got {payload:?}")
        })?;
        let addr_s = addr_s.strip_prefix("0x").unwrap_or(addr_s);
        let target_addr = u64::from_str_radix(addr_s, 16)
            .map_err(|e| anyhow!("--lookup-site ADDR parse: {e}"))?;
        let key_offset: u32 = off_s
            .parse()
            .map_err(|e| anyhow!("--lookup-site OFFSET parse: {e}"))?;
        by_index.push((idx, LookupSiteSpec { target_addr, key_offset }));
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

#[derive(Clone, Copy, Debug)]
enum RelocKind {
    /// `call rel32` — patch disp32 at splat time using the target's
    /// kernel address (the kernel module computes the exact disp32 once
    /// it knows where the blob will sit in the JIT image).
    CallRel32 = 1,
}

/// A side-band relocation record. The on-disk layout must stay in sync
/// with `struct native_lab_reloc_record` in
/// module/x86/bpf_x86_native_lab.c (offset:u32, kind:u32, target:u64 —
/// 16 bytes, little-endian). We serialize byte-by-byte below rather than
/// transmuting from a `#[repr(C, packed)]` struct, so plain alignment is
/// fine.
#[derive(Clone, Copy, Debug)]
struct RelocRecord {
    offset: u32,
    kind: u32,
    target: u64,
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
    let bytes = fs::read(&args.input)
        .with_context(|| format!("read {}", args.input.display()))?;
    let elf = object::File::parse(&*bytes)
        .with_context(|| format!("parse ELF {}", args.input.display()))?;
    if elf.architecture() != object::Architecture::X86_64 {
        bail!("input ELF arch must be x86_64, got {:?}", elf.architecture());
    }

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
            if sym.address == entry.address { " [entry]" } else { "" }
        );
    }

    let helper_addrs = parse_name_addr_args(&args.helpers, "helper")?;
    let map_addrs = parse_name_addr_args(&args.maps, "map")?;
    let lookup_sites = parse_lookup_sites(&args.lookup_sites)?;

    let RewriteResult { blob, relocs } = rewrite(
        &elf, &entry, &included, &helper_addrs, &map_addrs, &lookup_sites, args.show,
    )?;
    fs::write(&args.output, &blob)
        .with_context(|| format!("write {}", args.output.display()))?;
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
        fs::write(path, &buf)
            .with_context(|| format!("write {}", path.display()))?;
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
        let addr = u64::from_str_radix(addr, 16)
            .map_err(|e| anyhow!("invalid --{kind} {a:?}: {e}"))?;
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
                    anyhow!("{} calls {:#x} but no symbol covers that address", sym.name, target)
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

pub struct RewriteResult {
    pub blob: Vec<u8>,
    pub relocs: Vec<RelocRecord>,
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
            let Some(loc) = local_opcode_off else { continue };
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

fn rewrite(
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
                let target_is_symbol_entry =
                    included.iter().any(|s| s.address == original_target);
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
        if let PatchKind::Call { target_symbol_address } = p.kind {
            let off = p.global_offset;
            if off + 5 > blob.len() || blob[off] != 0xE8 {
                bail!("CALL at off {off:#x} did not encode as Call_rel32_64");
            }
            let target_global = *sym_global_offset
                .get(&target_symbol_address)
                .ok_or_else(|| anyhow!("call target sym addr not in index map"))?;
            let disp = target_global as i64 - (off + 5) as i64;
            let d = i32::try_from(disp)
                .map_err(|_| anyhow!("call disp {disp} exceeds i32"))?;
            blob[off + 1..off + 5].copy_from_slice(&d.to_le_bytes());
        }
    }

    // Stage 2: append helper trampolines to the tail of the blob and
    // patch each in-body `call rel32` disp to point at the trampoline
    // it should reach. Trampolines are position-independent (they hold
    // the helper's absolute address inline and use `jmp [rip+0]`), so
    // the kernel module's emit_x86 can splat the blob verbatim.
    apply_elf_relocations(
        elf,
        &layouts,
        helper_addrs,
        map_addrs,
        lookup_sites,
        &lookup_call_ordinal,
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
                bail!(
                    "JmpEnd placeholder at off {off:#x} did not encode as Jmp_rel32_64"
                );
            }
            let disp = end_offset - (off + 5) as i64;
            let d = i32::try_from(disp)
                .map_err(|_| anyhow!("jmp_end disp {disp} exceeds i32"))?;
            blob[off + 1..off + 5].copy_from_slice(&d.to_le_bytes());
        }
    }

    if show {
        disasm(&blob);
    }
    Ok(RewriteResult { blob, relocs: Vec::new() })
}

/// Walk the ELF .text relocations attached to the bytes we just encoded.
///
/// Helper trampoline layout emitted inline at each unique helper reloc:
///
///     ff 25 00 00 00 00          jmp QWORD PTR [rip+0]   ; 6 bytes
///     <u64 absolute helper addr>                          ; 8 bytes
///
/// The `[rip+0]` operand resolves to the byte right after the jmp itself,
/// which holds the absolute kernel address of the helper. Total: 14 bytes
/// per unique helper. Multiple PLT32 call sites targeting the same
/// helper share a single trampoline.
///
/// For each PLT32 helper reloc, emit (or reuse) a tail trampoline and
/// rewrite the call disp32 in the body to point at it.
fn apply_elf_relocations(
    elf: &object::File,
    layouts: &[SymbolLayout],
    helper_addrs: &HashMap<String, u64>,
    map_addrs: &HashMap<String, u64>,
    lookup_sites: &[LookupSiteSpec],
    lookup_call_ordinal: &HashMap<(u64, u64), usize>,
    blob: &mut Vec<u8>,
) -> Result<()> {
    if layouts.is_empty() {
        return Ok(());
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

    // Cache: helper symbol name -> trampoline byte offset in blob.
    let mut helper_trampoline: HashMap<String, usize> = HashMap::new();
    // Cache: map symbol name -> literal-pool entry byte offset in blob.
    let mut map_pool_entry: HashMap<String, usize> = HashMap::new();
    // Cache: local rodata/data symbol name -> embedded copy offset.
    // R_X86_64_PC32 against a `.L__const.<fn>.<arr>` symbol (clang puts
    // small const initializers there for 16+ byte loads via SSE) is
    // satisfied by copying the symbol's bytes to the blob tail and
    // patching the rip-relative disp32 in the loading insn.
    let mut local_data_embed: HashMap<String, usize> = HashMap::new();

    for (section_index, layouts_in_sec) in &sections {
        let section = elf
            .section_by_index(*section_index)
            .with_context(|| format!("section {:?}", section_index))?;
        for (reloc_offset, reloc) in section.relocations() {
            let owning_layout = layouts_in_sec.iter().find(|l| {
                reloc_offset >= l.sym.address && reloc_offset < l.sym.address + l.sym.size
            });
            let Some(layout) = owning_layout else { continue };

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
                    let helper_addr = *helper_addrs
                        .get(&target_name)
                        .ok_or_else(|| anyhow!(
                            "PLT32 reloc against unknown helper {}: \
                             pass --helper {}=0x... on the command line",
                            target_name, target_name
                        ))?;
                    let opcode_local_off = local_patch_off
                        .checked_sub(1)
                        .ok_or_else(|| anyhow!("PLT32 reloc at offset 0?"))?;
                    let insn_idx = layout
                        .insn_local_ip
                        .iter()
                        .position(|&ip| ip == opcode_local_off)
                        .ok_or_else(|| anyhow!(
                            "PLT32 reloc at {:#x} (opcode at {:#x}) does not align \
                             with any decoded instruction in symbol {}",
                            local_patch_off, opcode_local_off, layout.sym.name
                        ))?;
                    let new_opcode_off =
                        layout.base_in_blob + layout.new_offset_in_sym[insn_idx] as usize;

                    // Reserve / reuse a trampoline.
                    let tramp_off = if let Some(&off) = helper_trampoline.get(&target_name) {
                        off
                    } else {
                        let off = blob.len();
                        // jmp [rip+0] ; ff 25 00 00 00 00
                        blob.extend_from_slice(&[0xFF, 0x25, 0x00, 0x00, 0x00, 0x00]);
                        // .quad helper_addr (LE)
                        blob.extend_from_slice(&helper_addr.to_le_bytes());
                        helper_trampoline.insert(target_name.clone(), off);
                        off
                    };

                    // Patch the call's disp32 = tramp_off - (call_op + 5).
                    let rip_after_call = (new_opcode_off + 5) as i64;
                    let disp = tramp_off as i64 - rip_after_call;
                    let d = i32::try_from(disp)
                        .map_err(|_| anyhow!("call disp {disp} exceeds i32"))?;
                    let disp32_off = new_opcode_off + 1;
                    blob[disp32_off..disp32_off + 4]
                        .copy_from_slice(&d.to_le_bytes());
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
                        let call_local_off = local_patch_off.wrapping_sub(2);
                        if let Some(&ord) = lookup_call_ordinal
                            .get(&(layout.sym.address, call_local_off))
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
                                target_name, target_name, target_name
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
                        .ok_or_else(|| anyhow!(
                            "GOTPCREL reloc at {:#x} does not align with any instruction in {}",
                            local_patch_off, layout.sym.name
                        ))?;
                    let new_insn_off =
                        layout.base_in_blob + layout.new_offset_in_sym[insn_idx] as usize;
                    let off_within_insn = (local_patch_off - layout.insn_local_ip[insn_idx]) as usize;
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
                    let d = i32::try_from(disp)
                        .map_err(|_| anyhow!("map disp {disp} exceeds i32"))?;
                    blob[disp32_off..disp32_off + 4]
                        .copy_from_slice(&d.to_le_bytes());
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
                    let target_section_idx = target_sym
                        .section_index()
                        .ok_or_else(|| anyhow!(
                            "PC32 reloc target {} has no section",
                            target_name
                        ))?;
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
                        .ok_or_else(|| anyhow!(
                            "PC32 target {} below section base",
                            target_name
                        ))?;
                    let sym_size = target_sym.size();
                    if sym_size == 0 {
                        bail!(
                            "PC32 target {} has zero size; cannot embed",
                            target_name
                        );
                    }
                    let end = sym_off_in_sec
                        .checked_add(sym_size)
                        .ok_or_else(|| anyhow!("PC32 target size overflow"))?;
                    let sym_bytes = target_data
                        .get(sym_off_in_sec as usize..end as usize)
                        .ok_or_else(|| anyhow!(
                            "PC32 target {} bytes out of section bounds",
                            target_name
                        ))?
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
                        .ok_or_else(|| anyhow!(
                            "PC32 reloc at {:#x} does not align with any instruction in {}",
                            local_patch_off, layout.sym.name
                        ))?;
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
                    let d = i32::try_from(disp)
                        .map_err(|_| anyhow!("PC32 disp {disp} exceeds i32"))?;
                    blob[disp32_off..disp32_off + 4]
                        .copy_from_slice(&d.to_le_bytes());
                }
                _ => bail!(
                    "unsupported relocation r_type={} against symbol {} (offset {:#x})",
                    r_type, target_name, reloc_offset
                ),
            }
        }
    }

    Ok(())
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
fn validate_no_external_refs(
    insn: &Instruction,
    included_ranges: &[(u64, u64)],
) -> Result<()> {
    let in_any = |a: u64| included_ranges.iter().any(|&(lo, hi)| a >= lo && a < hi);

    let fc = insn.flow_control();
    if matches!(
        fc,
        FlowControl::UnconditionalBranch
            | FlowControl::ConditionalBranch
            | FlowControl::Call
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
            0x48, 0x85, 0xC0,           // test rax, rax
            0x74, 0x04,                 // je +4
            0x48, 0x83, 0xC0, key_offset as u8, // add rax, imm8
        ];
        Ok(vec![Instruction::with_declare_byte(&bytes)
            .map_err(|e| anyhow!("declare_byte: {e:?}"))?])
    } else {
        let imm = key_offset.to_le_bytes();
        // add rax, imm32 (rax-special opcode): 48 05 imm32  -> 6 bytes
        // total: 3 + 2 + 6 = 11
        let bytes = [
            0x48, 0x85, 0xC0,                       // test rax, rax
            0x74, 0x06,                             // je +6
            0x48, 0x05, imm[0], imm[1], imm[2], imm[3], // add rax, imm32
        ];
        Ok(vec![Instruction::with_declare_byte(&bytes)
            .map_err(|e| anyhow!("declare_byte: {e:?}"))?])
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
