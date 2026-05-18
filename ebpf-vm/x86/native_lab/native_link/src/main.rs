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

    /// Print a human-readable disassembly of the rewritten blob to stderr.
    #[arg(long)]
    show: bool,
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

    let RewriteResult { blob, relocs } = rewrite(
        &elf, &entry, &included, &helper_addrs, &map_addrs, args.show,
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

fn rewrite(
    elf: &object::File,
    entry: &SymInfo,
    included: &[SymInfo],
    helper_addrs: &HashMap<String, u64>,
    map_addrs: &HashMap<String, u64>,
    show: bool,
) -> Result<RewriteResult> {
    let included_ranges: Vec<(u64, u64)> = included
        .iter()
        .map(|s| (s.address, s.address + s.size))
        .collect();

    let mut sym_global_offset: HashMap<u64, usize> = HashMap::new();
    let mut blob: Vec<u8> = Vec::new();
    let mut patches: Vec<PatchInfo> = Vec::new();
    let mut layouts: Vec<SymbolLayout> = Vec::new();

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
            // target IP is set to 0 just so iced has something legal to
            // encode; the disp32 gets overwritten after layout.
            if is_return(&insn) && is_entry {
                let mut jmp = Instruction::default();
                jmp.set_code(Code::Jmp_rel32_64);
                jmp.set_op0_kind(OpKind::NearBranch64);
                jmp.set_near_branch64(0);
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
        }

        // Encode this symbol's local stream at IP=0.
        let block = InstructionBlock::new(&local, 0);
        let encoded = BlockEncoder::encode(
            64,
            block,
            BlockEncoderOptions::DONT_FIX_BRANCHES
                | BlockEncoderOptions::RETURN_NEW_INSTRUCTION_OFFSETS,
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
    apply_elf_relocations(elf, &layouts, helper_addrs, map_addrs, &mut blob)?;

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

/// Helper trampoline body. Encoded as:
///
///     ff 25 00 00 00 00          jmp QWORD PTR [rip+0]   ; 6 bytes
///     <u64 absolute helper addr>                          ; 8 bytes
///
/// The `[rip+0]` operand resolves to the byte right after the jmp itself,
/// which holds the absolute kernel address of the helper. Total: 14 bytes
/// per unique helper. Multiple PLT32 call sites targeting the same
/// helper share a single trampoline.
const TRAMPOLINE_LEN: usize = 14;

/// Walk the ELF .text relocations attached to the bytes we just encoded.
/// For each PLT32 helper reloc, emit (or reuse) a tail trampoline and
/// rewrite the call disp32 in the body to point at it.
fn apply_elf_relocations(
    elf: &object::File,
    layouts: &[SymbolLayout],
    helper_addrs: &HashMap<String, u64>,
    map_addrs: &HashMap<String, u64>,
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

    for (section_index, layouts_in_sec) in &sections {
        let section = elf
            .section_by_index(*section_index)
            .with_context(|| format!("section {:?}", section_index))?;
        for (reloc_offset, reloc) in section.relocations() {
            let owning_layout = layouts_in_sec.iter().find(|l| {
                reloc_offset >= l.sym.address && reloc_offset < l.sym.address + l.sym.size
            });
            let Some(layout) = owning_layout else { continue };

            let target_name: String = match reloc.target() {
                RelocationTarget::Symbol(idx) => elf
                    .symbol_by_index(idx)
                    .with_context(|| format!("reloc target symbol {idx:?}"))?
                    .name()
                    .map_err(|e| anyhow!("reloc target symbol name: {e}"))?
                    .to_string(),
                _ => continue,
            };

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
                // GOT-relative map references (R_X86_64_GOTPCREL=9,
                // _GOTPCRELX=41, _REX_GOTPCRELX=42). clang emits these
                // as `mov reg, [rip+disp32]` -- a 7-byte instruction
                // whose disp32 field starts at reloc_offset. We append
                // an 8-byte literal-pool entry holding the map kernel
                // pointer at the end of the blob, then patch the disp32
                // to point at it.
                9 | 41 | 42 => {
                    let map_addr = *map_addrs.get(&target_name).ok_or_else(|| anyhow!(
                        "GOT-relative reloc against unknown map symbol {}: \
                         pass --map {}=0x... on the command line",
                        target_name, target_name
                    ))?;

                    // Find the decoded instruction that contains this
                    // reloc. The disp32 field starts at the reloc offset
                    // and is 4 bytes; the mov has an opcode prefix of
                    // variable length (REX + 0x8b/0x8d) so we locate
                    // the instruction whose byte range covers the disp.
                    let insn_idx = layout
                        .insn_local_ip
                        .iter()
                        .enumerate()
                        .find_map(|(idx, &ip)| {
                            // For GOTPCRELX/REX_GOTPCRELX the disp32 ends
                            // 4 bytes before the next instruction. iced
                            // gives us the original instruction length
                            // via its decoded form -- we approximate by
                            // selecting the insn whose local_ip is the
                            // largest value <= local_patch_off. That's
                            // the insn the patch lies inside.
                            if ip <= local_patch_off { Some(idx) } else { None }
                        })
                        .ok_or_else(|| anyhow!(
                            "GOTPCREL reloc at {:#x} does not align with any instruction in {}",
                            local_patch_off, layout.sym.name
                        ))?;
                    let new_insn_off =
                        layout.base_in_blob + layout.new_offset_in_sym[insn_idx] as usize;
                    let off_within_insn = (local_patch_off - layout.insn_local_ip[insn_idx]) as usize;
                    let disp32_off = new_insn_off + off_within_insn;

                    // Reserve / reuse a pool entry.
                    let pool_off = if let Some(&off) = map_pool_entry.get(&target_name) {
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
                _ => bail!(
                    "unsupported relocation r_type={} against symbol {} (offset {:#x})",
                    r_type, target_name, reloc_offset
                ),
            }
        }
    }

    let _ = TRAMPOLINE_LEN; // referenced by the design comment / future map path.
    Ok(())
}

/// Legacy: kept for cargo deadcode warning silence; superseded by
/// apply_elf_relocations. To be deleted in a follow-up.
#[allow(dead_code)]
fn collect_elf_relocations(
    elf: &object::File,
    layouts: &[SymbolLayout],
    helper_addrs: &HashMap<String, u64>,
    map_addrs: &HashMap<String, u64>,
) -> Result<Vec<RelocRecord>> {
    if layouts.is_empty() {
        return Ok(Vec::new());
    }
    // All included symbols live in the same section (.text in a typical
    // -c -o foo.o build). Group them by section to walk that section's
    // relocations once. In practice we only ever see one section.
    let mut sections: HashMap<object::SectionIndex, Vec<&SymbolLayout>> = HashMap::new();
    for layout in layouts {
        sections
            .entry(layout.sym.section_index)
            .or_default()
            .push(layout);
    }

    let mut out: Vec<RelocRecord> = Vec::new();
    for (section_index, layouts_in_sec) in &sections {
        let section = elf
            .section_by_index(*section_index)
            .with_context(|| format!("section {:?}", section_index))?;
        for (reloc_offset, reloc) in section.relocations() {
            // Find which included symbol's byte range this reloc falls in.
            let owning_layout = layouts_in_sec.iter().find(|l| {
                reloc_offset >= l.sym.address && reloc_offset < l.sym.address + l.sym.size
            });
            let Some(layout) = owning_layout else { continue };

            // Resolve target symbol name.
            let target_name: String = match reloc.target() {
                RelocationTarget::Symbol(idx) => {
                    let sym = elf
                        .symbol_by_index(idx)
                        .with_context(|| format!("reloc target symbol {idx:?}"))?;
                    sym.name()
                        .map_err(|e| anyhow!("reloc target symbol name: {e}"))?
                        .to_string()
                }
                _ => continue,
            };

            // Raw ELF r_type for precise matching.
            let r_type = match reloc.flags() {
                RelocationFlags::Elf { r_type } => r_type,
                _ => continue,
            };

            // Local offset of the patch site within the owning symbol.
            let local_patch_off = reloc_offset - layout.sym.address;

            match r_type {
                // R_X86_64_PLT32 = 4. clang emits this for `call helper`.
                // The reloc offset is the byte position of the 4-byte
                // disp32 field; the 0xE8 opcode sits at offset-1.
                4 => {
                    let helper_addr = match helper_addrs.get(&target_name) {
                        Some(a) => *a,
                        None => bail!(
                            "PLT32 relocation against unknown helper {}: \
                             pass --helper {}=0x... on the command line",
                            target_name,
                            target_name
                        ),
                    };
                    let opcode_local_off = local_patch_off
                        .checked_sub(1)
                        .ok_or_else(|| anyhow!("PLT32 reloc at offset 0?"))?;
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
                    let new_opcode_off = layout.base_in_blob
                        + layout.new_offset_in_sym[insn_idx] as usize;
                    out.push(RelocRecord {
                        offset: u32::try_from(new_opcode_off)
                            .context("new_opcode_off exceeds u32")?,
                        kind: RelocKind::CallRel32 as u32,
                        target: helper_addr,
                    });
                }
                // R_X86_64_REX_GOTPCRELX = 42, R_X86_64_GOTPCRELX = 41,
                // R_X86_64_GOTPCREL = 9. clang emits these for &my_map
                // accesses through GOT. Stage 2 will splice a literal
                // pool entry into the blob and rewrite the disp32; for
                // the first POC we only support helper PLT32 relocs.
                9 | 41 | 42 => {
                    if !map_addrs.contains_key(&target_name) {
                        bail!(
                            "GOT-relative relocation against unknown map symbol {}",
                            target_name
                        );
                    }
                    bail!(
                        "map relocations (GOTPCREL against {}) not yet implemented in this POC",
                        target_name
                    );
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
    let _ = map_addrs; // silence unused warning until maps are wired in
    Ok(out)
}

fn containing_symbol(included: &[SymInfo], address: u64) -> Option<u64> {
    for s in included {
        if address >= s.address && address < s.address + s.size {
            return Some(s.address);
        }
    }
    None
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
    if matches!(fc, FlowControl::IndirectCall | FlowControl::IndirectBranch) {
        bail!(
            "instruction at IP {:#x} is an indirect call/branch; rebuild with -fno-jump-tables",
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
