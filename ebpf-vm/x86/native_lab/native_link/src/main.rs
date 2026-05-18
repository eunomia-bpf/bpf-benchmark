//! native-link: minimal x86-64 ELF -> native-lab blob linker.
//!
//! Reads a userspace-compiled `.so` (typically produced by
//! `micro/programs/Makefile`'s `MICRO_NATIVE` build), extracts one function
//! by name, and emits a position-independent byte stream suitable for
//! splatting into a BPF JIT image via the `bpf_x86_native_lab` kinsn.
//!
//! Transformation rules — the bare minimum to bridge the SysV AMD64 ABI a
//! userspace compiler emits and the "fall through to BPF JIT epilogue"
//! contract the kinsn enforces:
//!
//!   1. Every `RET` (Retnq/Retfq, with or without imm16) becomes
//!      `JMP rel32 -> end_label`.
//!   2. An empty `end_label:` is appended at the tail; the BPF JIT
//!      continues to its own exit epilogue from there.
//!   3. Compilers emit balanced push/pop along every control-flow path,
//!      so each rewritten `RET` site already sees a stack that matches
//!      what the BPF JIT prologue set up. Callee-saved register usage in
//!      the function is preserved by the function's own push/pop pairs.
//!
//! `iced_x86::BlockEncoder` re-encodes the instruction stream with all
//! intra-function PC-relative displacements automatically fixed up, so
//! conditional jumps, short jmps, and RIP-relative loads inside the
//! function remain correct after rewriting.
//!
//! Any PC-relative reference whose target lies outside the function (e.g.
//! `.rodata` lookup tables, GOT entries, other functions) is rejected —
//! the kernel splat location won't match the userspace ELF layout, so
//! silently emitting the original displacement would point at garbage.

use anyhow::{anyhow, bail, Context, Result};
use clap::Parser;
use iced_x86::{
    BlockEncoder, BlockEncoderOptions, Code, Decoder, DecoderOptions, FlowControl,
    Instruction, InstructionBlock, OpKind, Register,
};
use object::{Object, ObjectSection, ObjectSymbol};
use std::fs;
use std::path::PathBuf;

#[derive(Parser, Debug)]
#[command(about = "Extract one function from a userspace x86-64 ELF and rewrite it for native_lab.")]
struct Args {
    /// Input ELF object/shared library (e.g. *.native.so from micro/programs).
    #[arg(long)]
    input: PathBuf,

    /// Symbol name of the function to extract.
    #[arg(long)]
    symbol: String,

    /// Output path for the raw native blob bytes.
    #[arg(long)]
    output: PathBuf,

    /// Print a human-readable disassembly of the rewritten blob to stderr.
    #[arg(long)]
    show: bool,
}

#[derive(Debug, Clone, Copy)]
struct SymInfo {
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

    let sym = find_symbol(&elf, &args.symbol)?;
    let section = elf
        .section_by_index(sym.section_index)
        .with_context(|| format!("section index {:?}", sym.section_index))?;
    let section_data = section.data().context("read section data")?;
    let section_addr = section.address();

    if sym.size == 0 {
        bail!("symbol {} has zero size", args.symbol);
    }
    let offset = sym
        .address
        .checked_sub(section_addr)
        .ok_or_else(|| anyhow!("symbol address below section base"))?;
    let end = offset
        .checked_add(sym.size)
        .ok_or_else(|| anyhow!("symbol size overflow"))?;
    let func_bytes = section_data
        .get(offset as usize..end as usize)
        .ok_or_else(|| anyhow!("symbol bytes out of section bounds"))?;

    eprintln!(
        "native-link: {} bytes for symbol {} (section {:?}, vaddr {:#x})",
        func_bytes.len(),
        args.symbol,
        section.name().unwrap_or("?"),
        sym.address
    );

    let _ = sym.address; /* decoded at IP=0 below, vaddr only used for logging */
    let rewritten = rewrite(func_bytes)?;
    if args.show {
        disasm(&rewritten);
    }
    fs::write(&args.output, &rewritten)
        .with_context(|| format!("write {}", args.output.display()))?;
    eprintln!(
        "native-link: wrote {} bytes -> {}",
        rewritten.len(),
        args.output.display()
    );
    Ok(())
}

fn find_symbol(elf: &object::File, name: &str) -> Result<SymInfo> {
    // Prefer SYMTAB over DYNSYM when both exist.
    for sym in elf.symbols() {
        if sym.name().ok() == Some(name) && sym.size() > 0 {
            return Ok(SymInfo {
                address: sym.address(),
                size: sym.size(),
                section_index: sym
                    .section_index()
                    .ok_or_else(|| anyhow!("symbol {name} has no section"))?,
            });
        }
    }
    for sym in elf.dynamic_symbols() {
        if sym.name().ok() == Some(name) && sym.size() > 0 {
            return Ok(SymInfo {
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

fn rewrite(input: &[u8]) -> Result<Vec<u8>> {
    // Decode at IP=0 so the BlockEncoder can lay the rewritten stream at
    // IP=0 without translating every PC-relative target.
    let mut decoder = Decoder::with_ip(64, input, 0, DecoderOptions::NONE);
    let mut original: Vec<Instruction> = Vec::new();
    while decoder.can_decode() {
        let insn = decoder.decode();
        if insn.is_invalid() {
            bail!("iced decoder bailed at IP {:#x}", insn.ip());
        }
        original.push(insn);
    }

    let func_end = input.len() as u64;
    validate_no_external_refs(&original, 0, func_end)?;

    // Build the rewritten stream: drop compiler alignment NOPs, replace
    // each RET with a 5-byte Jmp_rel32_64 placeholder (disp=0 for now;
    // we patch it after we know the encoded layout). Track which output
    // index each placeholder lands at so we can find its disp bytes.
    let mut rewritten: Vec<Instruction> = Vec::with_capacity(original.len());
    let mut placeholder_indices: Vec<usize> = Vec::new();
    for insn in original.iter() {
        if is_alignment_nop(insn) {
            continue;
        }
        if is_return(insn) {
            let mut jmp = Instruction::default();
            jmp.set_code(Code::Jmp_rel32_64);
            jmp.set_op0_kind(OpKind::NearBranch64);
            // Provisional target: just point at the next IP so iced encodes
            // disp=0. We'll patch the 4 disp bytes after encoding.
            jmp.set_near_branch64(0);
            placeholder_indices.push(rewritten.len());
            rewritten.push(jmp);
        } else {
            rewritten.push(*insn);
        }
    }

    // Encode the block. RETURN_NEW_INSTRUCTION_OFFSETS asks iced to report
    // each instruction's final byte offset in the encoded buffer; we use
    // that to locate placeholder jmps so we can patch their disp32.
    let block = InstructionBlock::new(&rewritten, 0);
    let encoded = BlockEncoder::encode(
        64,
        block,
        BlockEncoderOptions::DONT_FIX_BRANCHES
            | BlockEncoderOptions::RETURN_NEW_INSTRUCTION_OFFSETS,
    )
    .map_err(|e| anyhow!("iced BlockEncoder failed: {e:?}"))?;
    let mut bytes = encoded.code_buffer;
    let new_offsets = &encoded.new_instruction_offsets;
    let end_offset = bytes.len() as i64;

    for &idx in &placeholder_indices {
        let off = new_offsets
            .get(idx)
            .copied()
            .ok_or_else(|| anyhow!("placeholder index {idx} missing from new_instruction_offsets"))?
            as usize;
        // Sanity: the placeholder must start with 0xE9 and be 5 bytes wide
        // in the encoded buffer.
        if off + 5 > bytes.len() || bytes[off] != 0xE9 {
            bail!(
                "placeholder jmp at index {idx} did not encode as Jmp_rel32_64 (offset {off})"
            );
        }
        let next_rip = (off + 5) as i64;
        let disp = end_offset - next_rip;
        let disp_i32 = i32::try_from(disp)
            .map_err(|_| anyhow!("end-of-blob displacement {disp} exceeds i32"))?;
        bytes[off + 1..off + 5].copy_from_slice(&disp_i32.to_le_bytes());
    }

    Ok(bytes)
}

/// Single-instruction NOPs of any encoding length are alignment padding
/// inserted by the compiler. We drop them because the BPF JIT image places
/// the blob inline without per-function alignment needs, and because iced
/// re-encodes some multi-byte NOP variants to shorter forms (breaking
/// pre-computed offset arithmetic).
fn is_alignment_nop(insn: &Instruction) -> bool {
    use iced_x86::Mnemonic;
    insn.mnemonic() == Mnemonic::Nop
}

fn is_return(insn: &Instruction) -> bool {
    matches!(
        insn.code(),
        Code::Retnq | Code::Retnq_imm16 | Code::Retfq | Code::Retfq_imm16
    )
}

/// Reject any PC-relative reference whose target sits outside the input
/// function's byte range. Such refs (rodata constants, GOT, other functions)
/// would silently point at unrelated memory once the blob is splatted into
/// a kernel JIT image at a different address.
fn validate_no_external_refs(insns: &[Instruction], lo: u64, hi: u64) -> Result<()> {
    for insn in insns {
        // PC-relative branches/calls.
        let fc = insn.flow_control();
        let target = insn.near_branch_target();
        if target != 0
            && matches!(
                fc,
                FlowControl::UnconditionalBranch
                    | FlowControl::ConditionalBranch
                    | FlowControl::Call
            )
            && (target < lo || target >= hi)
        {
            bail!(
                "instruction at IP {:#x} branches to {:#x} outside function [{:#x},{:#x})",
                insn.ip(),
                target,
                lo,
                hi
            );
        }
        // Indirect calls/branches (call rax etc.) are out of policy for
        // micro programs — but they can't carry an absolute address in
        // the encoding, so they don't break the splat per se. They WOULD
        // break execution if the register doesn't hold a sensible value.
        // We leave them as-is and warn.
        if matches!(fc, FlowControl::IndirectCall | FlowControl::IndirectBranch) {
            eprintln!(
                "warning: indirect call/branch at IP {:#x}; blob assumes register is valid at splat time",
                insn.ip()
            );
        }
        // RIP-relative memory operand.
        for op_i in 0..insn.op_count() {
            if insn.op_kind(op_i) == OpKind::Memory && insn.is_ip_rel_memory_operand() {
                let t = insn.ip_rel_memory_address();
                if t < lo || t >= hi {
                    bail!(
                        "instruction at IP {:#x} reads RIP-relative {:#x} outside function [{:#x},{:#x})",
                        insn.ip(),
                        t,
                        lo,
                        hi
                    );
                }
            }
        }
        // Absolute-displacement memory addressing (no base, no index, no
        // RIP-relative flag) would carry a hard-coded userspace address.
        for op_i in 0..insn.op_count() {
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
