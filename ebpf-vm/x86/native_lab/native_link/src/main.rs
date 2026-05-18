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
use object::{Object, ObjectSection, ObjectSymbol};
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

    /// Print a human-readable disassembly of the rewritten blob to stderr.
    #[arg(long)]
    show: bool,
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

    let out = rewrite(&elf, &entry, &included, args.show)?;
    fs::write(&args.output, &out)
        .with_context(|| format!("write {}", args.output.display()))?;
    eprintln!(
        "native-link: wrote {} bytes -> {}",
        out.len(),
        args.output.display()
    );
    Ok(())
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

fn rewrite(
    elf: &object::File,
    entry: &SymInfo,
    included: &[SymInfo],
    show: bool,
) -> Result<Vec<u8>> {
    let included_ranges: Vec<(u64, u64)> = included
        .iter()
        .map(|s| (s.address, s.address + s.size))
        .collect();

    let mut sym_global_offset: HashMap<u64, usize> = HashMap::new();
    let mut blob: Vec<u8> = Vec::new();
    let mut patches: Vec<PatchInfo> = Vec::new();

    for sym in included {
        let is_entry = sym.address == entry.address;
        let bytes = read_symbol_bytes(elf, sym)?;
        // Decode at the symbol's original vaddr so insn.near_branch_target()
        // is meaningful in the ELF address space and we can identify
        // inter-symbol call targets. Below we re-anchor each instruction
        // to a per-symbol IP=0 layout before encoding.
        let mut decoder = Decoder::with_ip(64, &bytes, sym.address, DecoderOptions::NONE);

        // Side table: per-entry patch kind, paired with each kept Instruction
        // in the symbol-local stream.
        let mut local: Vec<Instruction> = Vec::new();
        let mut kinds: Vec<Option<PatchKind>> = Vec::new();

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
                continue;
            }

            // Cross-symbol call: keep the instruction encoded as-is (iced
            // emits e8 dd dd dd dd with whatever disp it computes); we
            // overwrite the 4 disp bytes after concat using the original
            // target's containing symbol.
            if matches!(insn.flow_control(), FlowControl::Call) && original_target != 0 {
                // Set near_branch64 to local_ip so iced encodes disp=0
                // (within rel32 range). The patch step rewrites it.
                let next = local_ip.wrapping_add(5);
                insn.set_near_branch64(next);
                let target_sym = containing_symbol(included, original_target).ok_or_else(|| {
                    anyhow!(
                        "call from {} to {:#x} has no containing included symbol",
                        sym.name,
                        original_target
                    )
                })?;
                local.push(insn);
                kinds.push(Some(PatchKind::Call {
                    target_symbol_address: target_sym,
                }));
                continue;
            }

            local.push(insn);
            kinds.push(None);
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
        blob.extend_from_slice(&encoded.code_buffer);
    }

    let end_offset = blob.len() as i64;
    for p in &patches {
        let off = p.global_offset;
        match p.kind {
            PatchKind::JmpEnd => {
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
            PatchKind::Call { target_symbol_address } => {
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
    }

    if show {
        disasm(&blob);
    }
    Ok(blob)
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
