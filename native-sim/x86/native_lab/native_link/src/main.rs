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
use std::collections::{HashMap, HashSet};
use std::fs;
use std::path::PathBuf;

mod x86;

const ARM64_THREAD_INFO_CPU_OFFSET_HELPER_KEY: &str = "__native_arm64_thread_info_cpu_offset";
const ARM64_RETURN_TRAMPOLINE_SYMBOL: &str = "__native_link_arm64_ret_trampoline";
const A64_NOP: u32 = 0xd503_201f;

const BPF_JMP_CALL: u8 = 0x85;
const BPF_PSEUDO_CALL: u8 = 1;
const BPF_PSEUDO_KFUNC_CALL: u8 = 2;
const BPF_PSEUDO_KINSN_CALL: u8 = 4;
const BPF_FUNC_MAP_LOOKUP_ELEM: i32 = 1;
const BPF_FUNC_MAP_UPDATE_ELEM: i32 = 2;
const BPF_FUNC_MAP_DELETE_ELEM: i32 = 3;
const BPF_FUNC_GET_SMP_PROCESSOR_ID: i32 = 8;
const BPF_FUNC_TAIL_CALL: i32 = 12;
const BPF_FUNC_GET_CURRENT_TASK: i32 = 35;
const BPF_FUNC_GET_CURRENT_TASK_BTF: i32 = 158;
const BPF_LDX: u8 = 0x01;
const BPF_ST: u8 = 0x02;
const BPF_ALU: u8 = 0x04;
const BPF_JMP: u8 = 0x05;
const BPF_ALU64: u8 = 0x07;
const BPF_W: u8 = 0x00;
const BPF_B: u8 = 0x10;
const BPF_DW: u8 = 0x18;
const BPF_ADD: u8 = 0x00;
const BPF_MUL: u8 = 0x20;
const BPF_AND: u8 = 0x50;
const BPF_LSH: u8 = 0x60;
const BPF_MOV: u8 = 0xb0;
const BPF_K: u8 = 0x00;
const BPF_X: u8 = 0x08;
const BPF_MEM: u8 = 0x60;
const BPF_CALL: u8 = 0x80;
const BPF_JA: u8 = 0x00;
const BPF_JEQ: u8 = 0x10;
const BPF_JGE: u8 = 0x30;
const BPF_JNE: u8 = 0x50;
const BPF_ADDR_PERCPU: i16 = -1;

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
    /// Helper call sites against listed names are rewritten into relocatable
    /// helper-call slots. Ordinary BPF helper targets should come from
    /// --oracle-*; this option is for non-helper implementation details such
    /// as per-cpu symbols used by inline lowerings.
    #[arg(long = "helper", value_name = "NAME=ADDR")]
    helpers: Vec<String>,

    /// Companion program kernel JIT image used as the helper-call oracle.
    #[arg(long = "oracle-jited", value_name = "PATH")]
    oracle_jited: Option<PathBuf>,

    /// Base address reported in jited_ksyms[0] for --oracle-jited.
    #[arg(long = "oracle-jit-base", value_name = "ADDR")]
    oracle_jit_base: Option<String>,

    /// Companion program translated BPF image used to align helper call
    /// offsets with native call targets in --oracle-jited.
    #[arg(long = "oracle-xlated", value_name = "PATH")]
    oracle_xlated: Option<PathBuf>,

    /// Original BPF source helper call ids, in source order. native-loader
    /// passes this from the intercepted BPF_PROG_LOAD bytecode so JIT-decoded
    /// helper targets can be matched by helper id instead of by linker-local
    /// positional consumption.
    #[arg(long = "source-helper", value_name = "ID")]
    source_helpers: Vec<i32>,

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
    /// Format:
    /// INDEX=KIND,HEXADDR,RESERVED,MAX_ENTRIES,ELEM_SIZE,INDEX_MASK,VALUE_OFFSET,PERCPU_BASE
    /// where KIND is call/hash/lru_hash/percpu_hash/hash_of_maps/array/percpu_array.
    #[arg(
        long = "lookup-site",
        value_name = "INDEX=KIND,ADDR,RESERVED,MAX,ELEM,MASK,VALUE_OFF,PERCPU"
    )]
    lookup_sites: Vec<String>,

    /// Raw verifier map_gen_lookup() replacement sequence for a lookup-site.
    /// Format: INDEX=HEX where HEX is a concatenated little-endian
    /// `struct bpf_insn[]` byte stream returned by native_lab.
    #[arg(long = "lookup-gen", value_name = "INDEX=HEX")]
    lookup_gens: Vec<String>,

    /// Per-map fallback spec for native-only `bpf_map_lookup_elem` sites.
    /// Used only when the target-specific linker can trace the native
    /// callsite's map argument to a concrete map symbol.
    ///
    /// Format:
    /// NAME=KIND,HEXADDR,RESERVED,MAX_ENTRIES,ELEM_SIZE,INDEX_MASK,VALUE_OFFSET,PERCPU_BASE
    /// where KIND is call/hash/lru_hash/percpu_hash/hash_of_maps/array/percpu_array.
    #[arg(
        long = "lookup-map",
        value_name = "NAME=KIND,ADDR,RESERVED,MAX,ELEM,MASK,VALUE_OFF,PERCPU"
    )]
    lookup_maps: Vec<String>,

    /// Per-map `bpf_map_update_elem` target, keyed by native map symbol name.
    /// Used when source bytecode site tracking cannot bind a source update
    /// site to a concrete map, but native code still carries the map symbol.
    #[arg(long = "update-map", value_name = "NAME=ADDR")]
    update_maps: Vec<String>,

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
    HashOfMaps,
    Array,
    PerCpuArray,
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub(crate) struct BpfInsn {
    pub(crate) code: u8,
    pub(crate) dst_reg: u8,
    pub(crate) src_reg: u8,
    pub(crate) off: i16,
    pub(crate) imm: i32,
}

impl BpfInsn {
    fn from_bytes(bytes: &[u8]) -> Result<Self> {
        if bytes.len() != 8 {
            bail!("BPF instruction must be 8 bytes, got {}", bytes.len());
        }
        Ok(Self {
            code: bytes[0],
            dst_reg: bytes[1] & 0x0f,
            src_reg: bytes[1] >> 4,
            off: i16::from_le_bytes([bytes[2], bytes[3]]),
            imm: i32::from_le_bytes([bytes[4], bytes[5], bytes[6], bytes[7]]),
        })
    }

    fn is_helper_call(self) -> bool {
        self.code == BPF_JMP_CALL && self.src_reg == 0
    }
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
    /// Raw verifier map_gen_lookup() sequence for this map lookup site.
    /// In kernel mode native-link uses this to suppress oracle calls emitted
    /// by verifier expansion and to lower the post-proof lookup using the
    /// same per-map sequence shape.
    gen_insns: Vec<BpfInsn>,
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
            .ok_or_else(|| anyhow!("--lookup-site expects INDEX=KIND,ADDR,KEY_OFFSET,MAX,ELEM,MASK,VALUE_OFF,PERCPU; got {a:?}"))?;
        let idx: usize = idx_s
            .parse()
            .map_err(|e| anyhow!("--lookup-site INDEX parse: {e}"))?;
        let parts: Vec<&str> = payload.split(',').collect();
        let spec = if parts.len() == 8 || parts.len() == 9 {
            let kind = parse_lookup_kind(parts[0])?;
            let target_addr = parse_u64_auto(parts[1], "--lookup-site ADDR")?;
            let key_offset = parse_u32_auto(parts[2], "--lookup-site KEY_OFFSET")?;
            let max_entries = parse_u32_auto(parts[3], "--lookup-site MAX_ENTRIES")?;
            let elem_size = parse_u32_auto(parts[4], "--lookup-site ELEM_SIZE")?;
            let index_mask = parse_u32_auto(parts[5], "--lookup-site INDEX_MASK")?;
            let value_offset = parse_u32_auto(parts[6], "--lookup-site VALUE_OFFSET")?;
            let percpu_base_addr = parse_u64_auto(parts[7], "--lookup-site PERCPU_BASE")?;
            let map_name = if parts.len() == 9 && !parts[8].is_empty() {
                Some(parts[8].to_string())
            } else {
                None
            };
            LookupSiteSpec {
                kind,
                target_addr,
                key_offset,
                max_entries,
                elem_size,
                index_mask,
                value_offset,
                percpu_base_addr,
                map_name,
                gen_insns: Vec::new(),
            }
        } else {
            bail!(
                "--lookup-site payload has {} comma-separated fields; expected 8 or 9: {payload:?}",
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

fn parse_hex_nibble(ch: u8, label: &str) -> Result<u8> {
    match ch {
        b'0'..=b'9' => Ok(ch - b'0'),
        b'a'..=b'f' => Ok(ch - b'a' + 10),
        b'A'..=b'F' => Ok(ch - b'A' + 10),
        _ => bail!("{label} contains non-hex byte {ch:#x}"),
    }
}

fn parse_hex_bytes(s: &str, label: &str) -> Result<Vec<u8>> {
    if s.len() % 2 != 0 {
        bail!("{label} has odd hex length {}", s.len());
    }
    let bytes = s.as_bytes();
    let mut out = Vec::with_capacity(s.len() / 2);
    for pair in bytes.chunks_exact(2) {
        let hi = parse_hex_nibble(pair[0], label)?;
        let lo = parse_hex_nibble(pair[1], label)?;
        out.push((hi << 4) | lo);
    }
    Ok(out)
}

fn parse_lookup_gens(args: &[String], sites: &mut [LookupSiteSpec]) -> Result<()> {
    let mut seen = HashSet::new();
    for a in args {
        let (idx_s, hex) = a
            .split_once('=')
            .ok_or_else(|| anyhow!("--lookup-gen expects INDEX=HEX; got {a:?}"))?;
        let idx: usize = idx_s
            .parse()
            .map_err(|e| anyhow!("--lookup-gen INDEX parse: {e}"))?;
        if idx >= sites.len() {
            bail!(
                "--lookup-gen index {idx} exceeds lookup-site count {}",
                sites.len()
            );
        }
        if !seen.insert(idx) {
            bail!("duplicate --lookup-gen entry for lookup-site {idx}");
        }
        let bytes = parse_hex_bytes(hex, "--lookup-gen HEX")?;
        if bytes.is_empty() || bytes.len() % 8 != 0 {
            bail!(
                "--lookup-gen index {idx} is {} bytes; expected non-empty struct bpf_insn[]",
                bytes.len()
            );
        }
        sites[idx].gen_insns = bytes
            .chunks_exact(8)
            .map(BpfInsn::from_bytes)
            .collect::<Result<Vec<_>>>()?;
    }
    Ok(())
}

fn parse_lookup_map_specs(args: &[String]) -> Result<HashMap<String, LookupSiteSpec>> {
    let mut out = HashMap::new();
    for a in args {
        let (name, payload) = a
            .split_once('=')
            .ok_or_else(|| anyhow!("--lookup-map expects NAME=KIND,ADDR,KEY_OFFSET,MAX,ELEM,MASK,VALUE_OFF,PERCPU; got {a:?}"))?;
        if name.is_empty() {
            bail!("--lookup-map name must not be empty");
        }
        let parts: Vec<&str> = payload.split(',').collect();
        if parts.len() != 8 {
            bail!(
                "--lookup-map payload has {} comma-separated fields; expected 8: {payload:?}",
                parts.len()
            );
        }
        let spec = LookupSiteSpec {
            kind: parse_lookup_kind(parts[0])?,
            target_addr: parse_u64_auto(parts[1], "--lookup-map ADDR")?,
            key_offset: parse_u32_auto(parts[2], "--lookup-map KEY_OFFSET")?,
            max_entries: parse_u32_auto(parts[3], "--lookup-map MAX_ENTRIES")?,
            elem_size: parse_u32_auto(parts[4], "--lookup-map ELEM_SIZE")?,
            index_mask: parse_u32_auto(parts[5], "--lookup-map INDEX_MASK")?,
            value_offset: parse_u32_auto(parts[6], "--lookup-map VALUE_OFFSET")?,
            percpu_base_addr: parse_u64_auto(parts[7], "--lookup-map PERCPU_BASE")?,
            map_name: Some(name.to_string()),
            gen_insns: Vec::new(),
        };
        if out.insert(name.to_string(), spec).is_some() {
            bail!("duplicate --lookup-map entry for {name:?}");
        }
    }
    Ok(out)
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

fn lookup_site_needs_oracle(site: Option<&LookupSiteSpec>) -> bool {
    if site.is_some_and(|s| !s.gen_insns.is_empty()) {
        return false;
    }
    match site.map(|s| s.kind) {
        Some(LookupKind::Array | LookupKind::PerCpuArray) => false,
        Some(_) => site.is_some_and(|s| s.target_addr == 0),
        None => true,
    }
}

fn update_site_needs_oracle(site: Option<&UpdateSiteSpec>) -> bool {
    match site.map(|s| s.kind) {
        Some(UpdateKind::Array | UpdateKind::PerCpuArray) => false,
        Some(UpdateKind::Call) => site.is_some_and(|s| s.target_addr == 0),
        None => true,
    }
}

fn collect_xlated_call_imms(
    xlated: &[u8],
    lookup_sites: &[LookupSiteSpec],
    update_sites: &[UpdateSiteSpec],
) -> Result<Vec<i32>> {
    if xlated.len() % 8 != 0 {
        bail!("--oracle-xlated has truncated BPF instructions");
    }
    let xlated_insns = xlated
        .chunks_exact(8)
        .map(BpfInsn::from_bytes)
        .collect::<Result<Vec<_>>>()?;
    let mut calls = Vec::new();
    let mut lookup_ordinal = 0usize;
    let mut update_ordinal = 0usize;
    let mut idx = 0usize;
    while idx < xlated_insns.len() {
        if let Some(site) = lookup_sites.get(lookup_ordinal) {
            let gen_len = site.gen_insns.len();
            if gen_len != 0 {
                let end = idx + gen_len;
                if end <= xlated_insns.len() && xlated_insns[idx..end] == site.gen_insns[..] {
                    lookup_ordinal += 1;
                    idx = end;
                    continue;
                }
            }
        }
        let insn = xlated_insns[idx];
        idx += 1;
        let code = insn.code;
        if code != BPF_JMP_CALL {
            continue;
        }
        let src_reg = insn.src_reg;
        if matches!(
            src_reg,
            BPF_PSEUDO_CALL | BPF_PSEUDO_KFUNC_CALL | BPF_PSEUDO_KINSN_CALL
        ) {
            continue;
        }
        if src_reg != 0 {
            bail!("--oracle-xlated has unsupported helper call src_reg={src_reg}");
        }
        let imm = insn.imm;
        match imm {
            BPF_FUNC_GET_SMP_PROCESSOR_ID
            | BPF_FUNC_TAIL_CALL
            | BPF_FUNC_GET_CURRENT_TASK
            | BPF_FUNC_GET_CURRENT_TASK_BTF => continue,
            BPF_FUNC_MAP_LOOKUP_ELEM => {
                let site = lookup_sites.get(lookup_ordinal);
                lookup_ordinal += 1;
                if !lookup_site_needs_oracle(site) {
                    continue;
                }
            }
            BPF_FUNC_MAP_UPDATE_ELEM => {
                let site = update_sites.get(update_ordinal);
                update_ordinal += 1;
                if !update_site_needs_oracle(site) {
                    continue;
                }
            }
            BPF_FUNC_MAP_DELETE_ELEM => continue,
            _ => {}
        }
        calls.push(imm);
    }
    Ok(calls)
}

fn helper_target_for_id(helper_addrs: &HashMap<String, u64>, helper_id: i32) -> Option<u64> {
    helper_addrs.iter().find_map(|(name, &target)| {
        if helper_id_for_name(name) == Some(helper_id) {
            Some(target)
        } else {
            None
        }
    })
}

fn maybe_consume_direct_source_order_target(
    xlated_calls: &[OracleCall],
    next_xlated_target: &mut usize,
    helper_id: i32,
    direct_target: u64,
) {
    if direct_target == 0 {
        return;
    }
    if xlated_calls
        .get(*next_xlated_target)
        .is_some_and(|call| call.helper_id == Some(helper_id) && call.target == direct_target)
    {
        *next_xlated_target += 1;
    }
}

fn try_record_source_order_oracle_target(
    out: &mut Vec<OracleCall>,
    xlated_calls: &[OracleCall],
    next_xlated_target: &mut usize,
    helper_id: i32,
    helper_target: Option<u64>,
) {
    if let Some(target) = helper_target.filter(|target| *target != 0) {
        maybe_consume_direct_source_order_target(
            xlated_calls,
            next_xlated_target,
            helper_id,
            target,
        );
        out.push(OracleCall {
            helper_id: Some(helper_id),
            target,
        });
        return;
    }
    if let Some(call) = xlated_calls
        .get(*next_xlated_target)
        .filter(|call| call.helper_id == Some(helper_id))
    {
        *next_xlated_target += 1;
        out.push(*call);
    }
}

fn maybe_record_source_order_oracle_target(
    out: &mut Vec<OracleCall>,
    xlated_calls: &[OracleCall],
    next_xlated_target: &mut usize,
    helper_id: i32,
    helper_target: Option<u64>,
) {
    let Some(target) = helper_target.filter(|target| *target != 0) else {
        return;
    };
    maybe_consume_direct_source_order_target(
        xlated_calls,
        next_xlated_target,
        helper_id,
        target,
    );
    out.push(OracleCall {
        helper_id: Some(helper_id),
        target,
    });
}

fn collect_typed_source_oracle_calls(
    xlated: &[u8],
    jit_targets: &[u64],
    source_helpers: &[i32],
    lookup_sites: &[LookupSiteSpec],
    update_sites: &[UpdateSiteSpec],
    helper_addrs: &HashMap<String, u64>,
) -> Result<Vec<OracleCall>> {
    let mut out = Vec::new();
    let xlated_calls = collect_xlated_call_imms(xlated, lookup_sites, update_sites)?;
    let matched_indices = match_jit_target_indices_to_xlated_calls(jit_targets, &xlated_calls)?;
    if xlated_calls.len() != matched_indices.len() {
        bail!(
            "typed xlated helper count {} does not match companion JIT oracle target count {}",
            xlated_calls.len(),
            matched_indices.len()
        );
    }
    let xlated_oracle_calls = matched_indices
        .iter()
        .enumerate()
        .map(|(idx, &jit_idx)| OracleCall {
            helper_id: Some(xlated_calls[idx]),
            target: jit_targets[jit_idx],
        })
        .collect::<Vec<_>>();
    let mut next_xlated_target = 0usize;
    let mut lookup_ordinal = 0usize;
    let mut update_ordinal = 0usize;

    for &helper_id in source_helpers {
        match helper_id {
            BPF_FUNC_MAP_LOOKUP_ELEM => {
                let site = lookup_sites.get(lookup_ordinal);
                lookup_ordinal += 1;
                match site.map(|s| s.kind) {
                    Some(LookupKind::Array | LookupKind::PerCpuArray) => {}
                    Some(_) if site.is_some_and(|s| !s.gen_insns.is_empty()) => {}
                    Some(_) if lookup_site_needs_oracle(site) => {
                        try_record_source_order_oracle_target(
                            &mut out,
                            &xlated_oracle_calls,
                            &mut next_xlated_target,
                            helper_id,
                            helper_target_for_id(helper_addrs, helper_id),
                        );
                    }
                    Some(_) => {
                        if let Some(spec) = site {
                            maybe_consume_direct_source_order_target(
                                &xlated_oracle_calls,
                                &mut next_xlated_target,
                                helper_id,
                                spec.target_addr,
                            );
                        }
                    }
                    None => {
                        try_record_source_order_oracle_target(
                            &mut out,
                            &xlated_oracle_calls,
                            &mut next_xlated_target,
                            helper_id,
                            helper_target_for_id(helper_addrs, helper_id),
                        );
                    }
                }
            }
            BPF_FUNC_MAP_UPDATE_ELEM => {
                let site = update_sites.get(update_ordinal);
                update_ordinal += 1;
                match site.map(|s| s.kind) {
                    Some(UpdateKind::Array | UpdateKind::PerCpuArray) => {}
                    Some(UpdateKind::Call) if update_site_needs_oracle(site) => {
                        try_record_source_order_oracle_target(
                            &mut out,
                            &xlated_oracle_calls,
                            &mut next_xlated_target,
                            helper_id,
                            helper_target_for_id(helper_addrs, helper_id),
                        );
                    }
                    Some(UpdateKind::Call) => {
                        if let Some(spec) = site {
                            maybe_consume_direct_source_order_target(
                                &xlated_oracle_calls,
                                &mut next_xlated_target,
                                helper_id,
                                spec.target_addr,
                            );
                        }
                    }
                    None => {
                        try_record_source_order_oracle_target(
                            &mut out,
                            &xlated_oracle_calls,
                            &mut next_xlated_target,
                            helper_id,
                            helper_target_for_id(helper_addrs, helper_id),
                        );
                    }
                }
            }
            BPF_FUNC_MAP_DELETE_ELEM => {
                if let Some(&target) = helper_addrs.get("bpf_map_delete_elem") {
                    maybe_consume_direct_source_order_target(
                        &xlated_oracle_calls,
                        &mut next_xlated_target,
                        helper_id,
                        target,
                    );
                }
            }
            BPF_FUNC_TAIL_CALL
            | BPF_FUNC_GET_SMP_PROCESSOR_ID
            | BPF_FUNC_GET_CURRENT_TASK
            | BPF_FUNC_GET_CURRENT_TASK_BTF => {}
            _ => {
                maybe_record_source_order_oracle_target(
                    &mut out,
                    &xlated_oracle_calls,
                    &mut next_xlated_target,
                    helper_id,
                    helper_target_for_id(helper_addrs, helper_id),
                );
            }
        }
    }
    Ok(out)
}

fn target_is_inside_jit_image(target: u64, base: u64, len: usize) -> bool {
    let Ok(len64) = u64::try_from(len) else {
        return false;
    };
    let Some(end) = base.checked_add(len64) else {
        return false;
    };
    target >= base && target < end
}

fn add_signed_u64(base: u64, delta: i64) -> Result<u64> {
    Ok(if delta >= 0 {
        base.wrapping_add(delta as u64)
    } else {
        base.wrapping_sub(delta.unsigned_abs())
    })
}

fn sign_extend_u64(value: u64, bits: u32) -> i64 {
    let sign = 1u64 << (bits - 1);
    let mask = (1u64 << bits) - 1;
    ((value & mask) ^ sign).wrapping_sub(sign) as i64
}

#[derive(Clone, Copy, Debug, Default)]
struct Arm64RegValue {
    valid: bool,
    value: u64,
}

fn arm64_decode_mov_wide(word: u32) -> Option<(usize, u64, bool)> {
    let kind = word & 0xff80_0000;
    if !matches!(kind, 0x9280_0000 | 0xd280_0000 | 0xf280_0000) {
        return None;
    }
    let rd = (word & 0x1f) as usize;
    let shift = ((word >> 21) & 0x3) * 16;
    let imm = u64::from((word >> 5) & 0xffff);
    let is_movk = kind == 0xf280_0000;
    let value = if kind == 0x9280_0000 {
        !(imm << shift)
    } else {
        imm << shift
    };
    Some((rd, value, is_movk))
}

fn decode_arm64_external_call_targets(jited: &[u8], jit_base: u64) -> Result<Vec<u64>> {
    if jited.len() % 4 != 0 {
        bail!("--oracle-jited arm64 image length is not 4-byte aligned");
    }
    let mut targets = Vec::new();
    let mut regs = [Arm64RegValue::default(); 32];
    for (idx, bytes) in jited.chunks_exact(4).enumerate() {
        let off = u64::try_from(idx)
            .context("arm64 JIT instruction index overflow")?
            .checked_mul(4)
            .ok_or_else(|| anyhow!("arm64 JIT offset overflow"))?;
        let word = u32::from_le_bytes([bytes[0], bytes[1], bytes[2], bytes[3]]);
        if let Some((rd, value, is_movk)) = arm64_decode_mov_wide(word) {
            let shift = ((word >> 21) & 0x3) * 16;
            if is_movk {
                if regs[rd].valid {
                    let mask = 0xffffu64 << shift;
                    regs[rd].value = (regs[rd].value & !mask) | value;
                }
            } else {
                regs[rd] = Arm64RegValue { valid: true, value };
            }
            continue;
        }
        if (word & 0xfc00_0000) == 0x9400_0000 {
            let disp = sign_extend_u64(u64::from(word & 0x03ff_ffff), 26) << 2;
            let pc = jit_base
                .checked_add(off)
                .ok_or_else(|| anyhow!("arm64 JIT call IP overflow"))?;
            let target = add_signed_u64(pc, disp)?;
            if !target_is_inside_jit_image(target, jit_base, jited.len()) {
                targets.push(target);
            }
            continue;
        }
        if (word & 0xffff_fc1f) == 0xd63f_0000 {
            let rn = ((word >> 5) & 0x1f) as usize;
            if regs[rn].valid && !target_is_inside_jit_image(regs[rn].value, jit_base, jited.len())
            {
                targets.push(regs[rn].value);
            }
            regs[rn].valid = false;
        }
    }
    Ok(targets)
}

fn decode_external_call_targets(
    arch: object::Architecture,
    jited: &[u8],
    jit_base: u64,
) -> Result<Vec<u64>> {
    match arch {
        object::Architecture::X86_64 => x86::decode_x86_external_call_targets(jited, jit_base),
        object::Architecture::Aarch64 => decode_arm64_external_call_targets(jited, jit_base),
        _ => bail!("unsupported oracle JIT arch: {arch:?}"),
    }
}

fn match_jit_target_indices_to_xlated_calls(
    jit_targets: &[u64],
    xlated_call_imms: &[i32],
) -> Result<Vec<usize>> {
    if xlated_call_imms.is_empty() {
        return Ok(Vec::new());
    }
    if jit_targets.len() < xlated_call_imms.len() {
        bail!("companion JIT oracle found fewer native calls than xlated BPF calls");
    }
    for start in 0..jit_targets.len() {
        let call_base = add_signed_u64(jit_targets[start], -i64::from(xlated_call_imms[0]))?;
        let mut matched = Vec::with_capacity(xlated_call_imms.len());
        matched.push(start);
        let mut next_jit = start + 1;
        let mut ok = true;
        for call_imm in xlated_call_imms.iter().skip(1) {
            let expected = add_signed_u64(call_base, i64::from(*call_imm))?;
            let mut found = false;
            while next_jit < jit_targets.len() {
                if jit_targets[next_jit] == expected {
                    matched.push(next_jit);
                    next_jit += 1;
                    found = true;
                    break;
                }
                next_jit += 1;
            }
            if !found {
                ok = false;
                break;
            }
        }
        if ok {
            return Ok(matched);
        }
    }
    bail!("companion JIT oracle could not align xlated BPF calls with native calls");
}

fn matched_targets_from_indices(jit_targets: &[u64], indices: &[usize]) -> Vec<u64> {
    indices.iter().map(|idx| jit_targets[*idx]).collect()
}

#[derive(Clone, Copy, Debug)]
struct OracleCall {
    helper_id: Option<i32>,
    target: u64,
}

struct OracleCursor<'a> {
    calls: &'a [OracleCall],
    consumed: Vec<bool>,
    next_positional: usize,
    typed: bool,
}

impl<'a> OracleCursor<'a> {
    fn new(calls: &'a [OracleCall]) -> Self {
        let typed = calls.iter().any(|call| call.helper_id.is_some());
        Self {
            calls,
            consumed: vec![false; calls.len()],
            next_positional: 0,
            typed,
        }
    }

    fn finish(&self, arch: &str, proof_mode: bool) -> Result<()> {
        if proof_mode {
            return Ok(());
        }
        if self.typed {
            let _ = arch;
        } else if self.next_positional != self.calls.len() {
            bail!(
                "companion JIT oracle has {} unused {arch} helper target(s)",
                self.calls.len() - self.next_positional
            );
        }
        Ok(())
    }
}

fn helper_id_for_name(helper_name: &str) -> Option<i32> {
    match helper_name {
        "bpf_map_lookup_elem" => Some(BPF_FUNC_MAP_LOOKUP_ELEM),
        "bpf_map_update_elem" => Some(BPF_FUNC_MAP_UPDATE_ELEM),
        "bpf_map_delete_elem" => Some(BPF_FUNC_MAP_DELETE_ELEM),
        "bpf_probe_read_compat" => Some(4),
        "bpf_ktime_get_ns" => Some(5),
        "bpf_trace_printk" => Some(6),
        "bpf_get_prandom_u32" => Some(7),
        "bpf_get_smp_processor_id" => Some(BPF_FUNC_GET_SMP_PROCESSOR_ID),
        "bpf_skb_store_bytes" => Some(9),
        "bpf_l3_csum_replace" => Some(10),
        "bpf_l4_csum_replace" => Some(11),
        "bpf_tail_call" => Some(BPF_FUNC_TAIL_CALL),
        "bpf_clone_redirect" => Some(13),
        "bpf_get_current_pid_tgid" => Some(14),
        "bpf_get_current_uid_gid" => Some(15),
        "bpf_get_current_comm" => Some(16),
        "bpf_get_cgroup_classid" => Some(17),
        "bpf_skb_vlan_push" => Some(18),
        "bpf_skb_vlan_pop" => Some(19),
        "bpf_skb_get_tunnel_key" => Some(20),
        "bpf_skb_set_tunnel_key" => Some(21),
        "bpf_redirect" => Some(23),
        "bpf_get_route_realm" => Some(24),
        "bpf_perf_event_output" => Some(25),
        "bpf_skb_load_bytes" => Some(26),
        "bpf_get_stackid" => Some(27),
        "bpf_csum_diff" => Some(28),
        "bpf_skb_get_tunnel_opt" => Some(29),
        "bpf_skb_set_tunnel_opt" => Some(30),
        "bpf_skb_change_proto" => Some(31),
        "bpf_skb_change_type" => Some(32),
        "bpf_skb_under_cgroup" => Some(33),
        "bpf_get_hash_recalc" => Some(34),
        "bpf_get_current_task" => Some(35),
        "bpf_probe_write_user" => Some(36),
        "bpf_current_task_under_cgroup" => Some(37),
        "bpf_skb_change_tail" => Some(38),
        "bpf_skb_pull_data" => Some(39),
        "bpf_csum_update" => Some(40),
        "bpf_set_hash_invalid" => Some(41),
        "bpf_get_numa_node_id" => Some(42),
        "bpf_skb_change_head" => Some(43),
        "bpf_xdp_adjust_head" => Some(44),
        "bpf_probe_read_compat_str" => Some(45),
        "bpf_get_socket_cookie" => Some(46),
        "bpf_get_socket_uid" => Some(47),
        "bpf_set_hash" => Some(48),
        "bpf_setsockopt" => Some(49),
        "bpf_skb_adjust_room" => Some(50),
        "bpf_redirect_map" => Some(51),
        "bpf_xdp_adjust_meta" => Some(54),
        "bpf_getsockopt" => Some(57),
        "bpf_override_return" => Some(58),
        "bpf_xdp_adjust_tail" => Some(65),
        "bpf_get_stack" => Some(67),
        "bpf_skb_load_bytes_relative" => Some(68),
        "bpf_fib_lookup" => Some(69),
        "bpf_get_current_cgroup_id" => Some(80),
        "bpf_sk_lookup_tcp" => Some(84),
        "bpf_sk_lookup_udp" => Some(85),
        "bpf_sk_release" => Some(86),
        "bpf_map_push_elem" => Some(87),
        "bpf_map_pop_elem" => Some(88),
        "bpf_sk_fullsock" => Some(95),
        "bpf_skc_lookup_tcp" => Some(99),
        "bpf_send_signal" => Some(109),
        "bpf_probe_read_user" => Some(112),
        "bpf_probe_read_kernel" => Some(113),
        "bpf_probe_read_user_str" => Some(114),
        "bpf_probe_read_kernel_str" => Some(115),
        "bpf_jiffies64" => Some(118),
        "bpf_sk_assign" => Some(124),
        "bpf_ktime_get_boot_ns" => Some(125),
        "bpf_seq_write" => Some(127),
        "bpf_ringbuf_output" => Some(130),
        "bpf_ringbuf_reserve" => Some(131),
        "bpf_ringbuf_submit" => Some(132),
        "bpf_ringbuf_discard" => Some(133),
        "bpf_ringbuf_query" => Some(134),
        "bpf_copy_from_user" => Some(148),
        "bpf_redirect_neigh" => Some(152),
        "bpf_redirect_peer" => Some(155),
        "bpf_get_current_task_btf" => Some(158),
        "bpf_ima_inode_hash" => Some(161),
        "bpf_get_func_ip" => Some(173),
        "bpf_get_attach_cookie" => Some(174),
        "bpf_task_pt_regs" => Some(175),
        "bpf_loop" => Some(181),
        "bpf_get_func_arg" => Some(183),
        "bpf_get_func_ret" => Some(184),
        "bpf_get_func_arg_cnt" => Some(185),
        "bpf_ima_file_hash" => Some(193),
        "bpf_xdp_get_buff_len" => Some(188),
        "bpf_xdp_load_bytes" => Some(189),
        "bpf_xdp_store_bytes" => Some(190),
        "bpf_map_lookup_percpu_elem" => Some(195),
        _ => None,
    }
}

fn load_helper_call_oracle(
    args: &Args,
    arch: object::Architecture,
    lookup_sites: &[LookupSiteSpec],
    update_sites: &[UpdateSiteSpec],
    helper_addrs: &HashMap<String, u64>,
) -> Result<Vec<OracleCall>> {
    match (
        &args.oracle_jited,
        &args.oracle_jit_base,
        &args.oracle_xlated,
    ) {
        (None, None, None) => Ok(Vec::new()),
        (Some(jited_path), Some(base_text), Some(xlated_path)) => {
            let jited =
                fs::read(jited_path).with_context(|| format!("read {}", jited_path.display()))?;
            let jit_base = parse_u64_auto(base_text, "--oracle-jit-base")?;
            let jit_targets = decode_external_call_targets(arch, &jited, jit_base)?;
            let xlated =
                fs::read(xlated_path).with_context(|| format!("read {}", xlated_path.display()))?;
            if !args.source_helpers.is_empty() {
                let typed_calls = collect_typed_source_oracle_calls(
                    &xlated,
                    &jit_targets,
                    &args.source_helpers,
                    lookup_sites,
                    update_sites,
                    helper_addrs,
                )?;
                return Ok(typed_calls);
            }
            let xlated_call_imms = collect_xlated_call_imms(&xlated, lookup_sites, update_sites)?;
            let matched_indices =
                match_jit_target_indices_to_xlated_calls(&jit_targets, &xlated_call_imms)?;
            let targets = matched_targets_from_indices(&jit_targets, &matched_indices);
            if targets.is_empty() {
                return Ok(Vec::new());
            }
            bail!("--source-helper is required when companion JIT oracle has helper targets")
        }
        _ => bail!(
            "--oracle-jited, --oracle-jit-base, and --oracle-xlated must be supplied together"
        ),
    }
}

fn consume_oracle_target(
    oracle: &mut OracleCursor<'_>,
    expected_helper_id: Option<i32>,
    context: &str,
) -> Result<Option<u64>> {
    let target = if oracle.typed {
        let helper_id = expected_helper_id
            .ok_or_else(|| anyhow!("{context} missing expected helper id for typed oracle"))?;
        let Some(idx) = oracle.calls.iter().enumerate().find_map(|(idx, call)| {
            if oracle.consumed[idx] || call.helper_id != Some(helper_id) {
                None
            } else {
                Some(idx)
            }
        }) else {
            let Some(call) = oracle
                .calls
                .iter()
                .find(|call| call.helper_id == Some(helper_id))
            else {
                return Ok(None);
            };
            return Ok(Some(call.target));
        };
        oracle.consumed[idx] = true;
        oracle.calls[idx].target
    } else {
        let Some(call) = oracle.calls.get(oracle.next_positional) else {
            return Ok(None);
        };
        oracle.next_positional += 1;
        call.target
    };
    if target == 0 {
        bail!("companion JIT oracle returned zero target for {context}");
    }
    Ok(Some(target))
}

fn resolve_oracle_preferred_site_target(
    encoded_target: u64,
    oracle: &mut OracleCursor<'_>,
    expected_helper_id: i32,
    context: &str,
) -> Result<u64> {
    if encoded_target != 0 {
        return Ok(encoded_target);
    }
    if let Some(oracle_target) = consume_oracle_target(oracle, Some(expected_helper_id), context)? {
        return Ok(oracle_target);
    }
    bail!("{context} has no target address and companion JIT oracle is exhausted")
}

fn resolve_lookup_site_target(
    spec: &LookupSiteSpec,
    oracle: &mut OracleCursor<'_>,
    context: &str,
) -> Result<u64> {
    match spec.kind {
        LookupKind::Call => resolve_oracle_preferred_site_target(
            spec.target_addr,
            oracle,
            BPF_FUNC_MAP_LOOKUP_ELEM,
            context,
        ),
        LookupKind::Hash
        | LookupKind::LruHash
        | LookupKind::PerCpuHash
        | LookupKind::HashOfMaps => {
            if spec.target_addr != 0 {
                return Ok(spec.target_addr);
            }
            if let Some(oracle_target) =
                consume_oracle_target(oracle, Some(BPF_FUNC_MAP_LOOKUP_ELEM), context)?
            {
                return Ok(oracle_target);
            }
            bail!("{context} lowered map lookup has no target address and companion JIT oracle is exhausted")
        }
        LookupKind::Array | LookupKind::PerCpuArray => {
            bail!("{context} inline array lookup should not resolve a call target")
        }
    }
}

fn resolve_helper_target(
    helper_name: &str,
    helper_addrs: &HashMap<String, u64>,
    oracle: &mut OracleCursor<'_>,
    context: &str,
) -> Result<u64> {
    let helper_id = helper_id_for_name(helper_name);
    if helper_name == "bpf_map_delete_elem" {
        return helper_addrs
            .get(helper_name)
            .copied()
            .filter(|target| *target != 0)
            .ok_or_else(|| anyhow!("{context} has no bpf_map_delete_elem target address"));
    }
    if oracle.typed {
        if let Some(&encoded_target) = helper_addrs.get(helper_name) {
            if encoded_target == 0 {
                bail!("{context} has zero helper target address");
            }
            return Ok(encoded_target);
        }
    }
    if let Some(oracle_target) = consume_oracle_target(oracle, helper_id, context)? {
        if let Some(&encoded_target) = helper_addrs.get(helper_name) {
            if encoded_target != oracle_target {
                bail!(
                    "helper {helper_name} target {encoded_target:#x} conflicts with companion JIT oracle target {oracle_target:#x}"
                );
            }
        }
        return Ok(oracle_target);
    }
    helper_addrs.get(helper_name).copied().ok_or_else(|| {
        anyhow!("{context} has no helper address and companion JIT oracle is exhausted")
    })
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
    let helper_addrs = parse_name_addr_args(&args.helpers, "helper")?;
    let map_addrs = parse_name_addr_args(&args.maps, "map")?;
    let mut lookup_sites = parse_lookup_sites(&args.lookup_sites)?;
    parse_lookup_gens(&args.lookup_gens, &mut lookup_sites)?;
    let lookup_maps = parse_lookup_map_specs(&args.lookup_maps)?;
    let update_maps = parse_name_addr_args(&args.update_maps, "update-map")?;
    let update_sites = parse_update_sites(&args.update_sites)?;
    let oracle_targets = if proof_mode {
        Vec::new()
    } else {
        load_helper_call_oracle(
            &args,
            elf.architecture(),
            &lookup_sites,
            &update_sites,
            &helper_addrs,
        )?
    };
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
                &update_maps,
                &update_sites,
                &oracle_targets,
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
                &update_maps,
                &update_sites,
                &oracle_targets,
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

fn build_arm64_lookup_call_postprocess(spec: &LookupSiteSpec) -> Result<Vec<u32>> {
    const X0: u32 = 0;
    const X8: u32 = 8;
    const X10: u32 = 10;
    const A64_MRS_X10_TPIDR_EL1: u32 = 0xd538_d08a;

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

fn validate_arm64_lookup_gen(spec: &LookupSiteSpec, context: &str) -> Result<()> {
    if spec.gen_insns.is_empty() {
        return Ok(());
    }
    let call_count = spec
        .gen_insns
        .iter()
        .filter(|insn| insn.is_helper_call())
        .count();
    match spec.kind {
        LookupKind::Array | LookupKind::PerCpuArray => {
            if call_count != 0 {
                bail!("{context} array map_gen_lookup unexpectedly contains {call_count} calls");
            }
        }
        LookupKind::Call
        | LookupKind::Hash
        | LookupKind::LruHash
        | LookupKind::PerCpuHash
        | LookupKind::HashOfMaps => {
            if call_count != 1 || !spec.gen_insns[0].is_helper_call() {
                bail!(
                    "{context} map_gen_lookup must contain exactly one leading helper call, found {call_count}"
                );
            }
            if spec.target_addr == 0 {
                bail!("{context} map_gen_lookup call is missing native_lab target address");
            }
        }
    }
    Ok(())
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

fn append_u32(blob: &mut Vec<u8>, word: u32) {
    blob.extend_from_slice(&word.to_le_bytes());
}

fn append_u64(blob: &mut Vec<u8>, value: u64) {
    blob.extend_from_slice(&value.to_le_bytes());
}

fn align_arm64_blob_to_8(blob: &mut Vec<u8>) {
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
        if *saves == 0 || *restores == 0 {
            bail!(
                "arm64 entry ABI strip found unbalanced save/restore for x{}: saves={}, restores={}",
                19 + idx,
                saves,
                restores
            );
        }
        if *saves > 1 {
            bail!(
                "arm64 entry ABI strip found multiple save sites for x{}: saves={}, restores={}",
                19 + idx,
                saves,
                restores
            );
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

fn rewrite_arm64(
    elf: &object::File,
    entry: &SymInfo,
    included: &[SymInfo],
    helper_addrs: &HashMap<String, u64>,
    map_addrs: &HashMap<String, u64>,
    lookup_sites: &[LookupSiteSpec],
    _update_maps: &HashMap<String, u64>,
    update_sites: &[UpdateSiteSpec],
    oracle_targets: &[OracleCall],
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
    let mut oracle = OracleCursor::new(oracle_targets);
    let mut proof_relocs: Vec<ProofReloc> = Vec::new();
    let mut callee_saved_mask: u8 = 0;
    const A64_MOV_X7_X0: u32 = 0xaa00_03e7;
    let mut reg_map_names: [Option<String>; 32] = std::array::from_fn(|_| None);
    let mut lookup_site_by_map: HashMap<String, usize> = HashMap::new();
    let mut update_site_by_map: HashMap<String, usize> = HashMap::new();

    for sym in included {
        let is_entry = sym.address == entry.address;
        let bytes = read_symbol_bytes(elf, sym)?;
        if bytes.is_empty() || bytes.len() % 4 != 0 {
            bail!(
                "arm64 symbol {} size must be a non-zero multiple of 4",
                sym.name
            );
        }
        let entry_abi_strip = if is_entry {
            plan_arm64_entry_abi_strip(&bytes)?
        } else {
            Arm64EntryAbiStrip::default()
        };
        if is_entry {
            callee_saved_mask = entry_abi_strip.callee_saved_mask;
        }

        let end = sym.address + sym.size;
        sym_start_word_offset.insert(sym.address, blob.len() / 4);
        for (local_word_index, word) in bytes.chunks_exact(4).enumerate() {
            let off = local_word_index * 4;
            let mut insn = u32::from_le_bytes(word.try_into().unwrap());
            let emit_word_index = blob.len() / 4;
            addr_word_offset.insert(sym.address + off as u64, emit_word_index);
            if is_entry && entry_abi_strip.nop_word_indices.contains(&local_word_index) {
                insn = A64_NOP;
                blob.extend_from_slice(&insn.to_le_bytes());
                continue;
            }
            let reloc = relocs.get(&(sym.address, off as u64));
            if !proof_mode {
                if let Some((dst, src)) = a64_mov_reg64(insn) {
                    reg_map_names[dst] = reg_map_names[src].clone();
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
                        let mut helper_addr_from_site = false;
                        let mut lookup_postprocess = None;
                        if reloc.target_name == "bpf_map_lookup_elem" && is_entry {
                            let ordinal = lookup_call_counter;
                            let map_name = reg_map_names[0].as_ref();
                            let site_index = arm64_select_map_call_site(
                                lookup_sites.len(),
                                ordinal,
                                map_name,
                                &mut lookup_site_by_map,
                            )
                            .ok_or_else(|| {
                                anyhow!(
                                    "arm64 bpf_map_lookup_elem call site {ordinal} in {} is missing --lookup-site metadata",
                                    sym.name
                                )
                            })?;
                            let spec = &lookup_sites[site_index];
                            lookup_call_counter += 1;
                            validate_arm64_lookup_gen(
                                spec,
                                &format!("arm64 lookup-site {ordinal} ({:?})", spec.kind),
                            )?;
                            match spec.kind {
                                LookupKind::Array | LookupKind::PerCpuArray => {
                                    for word in build_arm64_array_lookup(spec)? {
                                        append_u32(&mut blob, word);
                                    }
                                    arm64_call_clobber_map_regs(&mut reg_map_names);
                                    continue;
                                }
                                LookupKind::Call
                                | LookupKind::Hash
                                | LookupKind::LruHash
                                | LookupKind::PerCpuHash
                                | LookupKind::HashOfMaps => {
                                    helper_addr = Some(resolve_lookup_site_target(
                                        spec,
                                        &mut oracle,
                                        &format!("arm64 lookup-site {ordinal} ({:?})", spec.kind),
                                    )?);
                                    helper_addr_from_site = true;
                                    lookup_postprocess = Some(spec.clone());
                                }
                            }
                        }
                        if reloc.target_name == "bpf_map_update_elem" && is_entry {
                            let ordinal = update_call_counter;
                            let map_name = reg_map_names[0].as_ref();
                            let site_index = arm64_select_map_call_site(
                                update_sites.len(),
                                ordinal,
                                map_name,
                                &mut update_site_by_map,
                            );
                            update_call_counter += 1;
                            if let Some(site_index) = site_index {
                                let spec = &update_sites[site_index];
                                match spec.kind {
                                    UpdateKind::Array | UpdateKind::PerCpuArray => {
                                        for word in build_arm64_array_update(spec)? {
                                            append_u32(&mut blob, word);
                                        }
                                        arm64_call_clobber_map_regs(&mut reg_map_names);
                                        continue;
                                    }
                                    UpdateKind::Call => {
                                        helper_addr = Some(resolve_oracle_preferred_site_target(
                                            spec.target_addr,
                                            &mut oracle,
                                            BPF_FUNC_MAP_UPDATE_ELEM,
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
                                    "arm64 CALL26 in {} at byte offset {off:#x} has empty site target for {}",
                                    sym.name,
                                    reloc.target_name
                                )
                            })?
                        } else {
                            resolve_helper_target(
                                &reloc.target_name,
                                helper_addrs,
                                &mut oracle,
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
        sym_end_word_offset.insert(sym.address, blob.len() / 4);
    }

    oracle.finish("arm64", proof_mode)?;

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
        callee_saved_mask,
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
