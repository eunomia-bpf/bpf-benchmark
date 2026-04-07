// SPDX-License-Identifier: MIT
#![cfg_attr(not(test), allow(dead_code))]
//! ELF/BTF parsing helpers for real `.bpf.o` test fixtures.

use std::collections::{HashMap, HashSet, VecDeque};
use std::fs;
use std::path::{Path, PathBuf};

use anyhow::{bail, Context, Result};
use goblin::elf::header::EM_BPF;
use goblin::elf::section_header::{self, SHT_PROGBITS};
use goblin::elf::sym;
use goblin::elf::Elf;

use crate::insn::{BpfInsn, BPF_DW, BPF_IMM, BPF_LD};

pub const BPF_PSEUDO_MAP_FD: u8 = 1;
pub const BPF_PSEUDO_MAP_VALUE: u8 = 2;

const BPF_MAP_TYPE_ARRAY: u32 = 2;
const R_BPF_64_64: u32 = 1;
const R_BPF_64_NODYLD32: u32 = 4;

const BPF_PROG_TYPE_SOCKET_FILTER: u32 = 1;
const BPF_PROG_TYPE_KPROBE: u32 = 2;
const BPF_PROG_TYPE_SCHED_CLS: u32 = 3;
const BPF_PROG_TYPE_SCHED_ACT: u32 = 4;
const BPF_PROG_TYPE_TRACEPOINT: u32 = 5;
const BPF_PROG_TYPE_XDP: u32 = 6;
const BPF_PROG_TYPE_PERF_EVENT: u32 = 7;
const BPF_PROG_TYPE_CGROUP_SKB: u32 = 8;
const BPF_PROG_TYPE_SK_SKB: u32 = 14;
const BPF_PROG_TYPE_RAW_TRACEPOINT: u32 = 17;
const BPF_PROG_TYPE_LWT_IN: u32 = 18;
const BPF_PROG_TYPE_LWT_OUT: u32 = 19;
const BPF_PROG_TYPE_LWT_XMIT: u32 = 20;
const BPF_PROG_TYPE_TRACING: u32 = 26;
const BPF_PROG_TYPE_LSM: u32 = 29;
const BPF_PROG_TYPE_SYSCALL: u32 = 31;
const BPF_PROG_TYPE_NETFILTER: u32 = 32;

#[derive(Clone, Debug)]
pub struct ElfMapMetadata {
    pub index: usize,
    pub name: String,
    pub map_type: Option<u32>,
    pub key_size: Option<u32>,
    pub value_size: Option<u32>,
    pub max_entries: Option<u32>,
    pub map_flags: Option<u32>,
}

#[derive(Clone, Debug)]
pub struct ElfProgramMapRelocation {
    pub pc: usize,
    pub map_index: usize,
    pub map_name: String,
    pub pseudo_src: u8,
}

#[derive(Clone, Debug)]
pub struct ElfProgramInfo {
    pub section_name: String,
    pub symbol_name: Option<String>,
    pub prog_type: u32,
    pub insns: Vec<BpfInsn>,
    pub map_relocations: Vec<ElfProgramMapRelocation>,
    pub used_map_indices: Vec<usize>,
}

#[derive(Clone, Debug)]
pub struct ElfBpfObject {
    pub path: PathBuf,
    pub programs: Vec<ElfProgramInfo>,
    pub maps: Vec<ElfMapMetadata>,
}

impl ElfBpfObject {
    pub fn first_program(&self) -> Option<&ElfProgramInfo> {
        self.programs.first()
    }

    pub fn program_named(&self, name: &str) -> Option<&ElfProgramInfo> {
        let mut matches = self.programs.iter().filter(|program| {
            program.section_name == name || program.symbol_name.as_deref() == Some(name)
        });
        let first = matches.next()?;
        if matches.next().is_some() {
            return None;
        }
        Some(first)
    }
}

#[derive(Clone, Debug)]
struct ElfMapSymbol {
    sym_index: usize,
    name: String,
    section_offset: usize,
    symbol_size: usize,
}

#[derive(Clone, Debug)]
struct RelocationTarget {
    map_index: usize,
    force_pseudo_src: Option<u8>,
}

#[derive(Clone, Debug, Default)]
struct RawMapMetadata {
    map_type: Option<u32>,
    key_size: Option<u32>,
    value_size: Option<u32>,
    max_entries: Option<u32>,
    map_flags: Option<u32>,
}

#[derive(Clone, Debug, Default)]
struct BtfMapMetadata {
    name: Option<String>,
    map_type: Option<u32>,
    key_size: Option<u32>,
    value_size: Option<u32>,
    max_entries: Option<u32>,
    map_flags: Option<u32>,
}

#[derive(Clone, Debug)]
struct BtfMember {
    name: String,
    type_id: u32,
}

#[derive(Clone, Debug)]
struct BtfVarSecinfo {
    type_id: u32,
    _offset: u32,
    _size: u32,
}

#[derive(Clone, Debug)]
enum BtfType {
    Int {
        size: u32,
    },
    Ptr {
        target_type_id: u32,
    },
    Array {
        elem_type_id: u32,
        nelems: u32,
    },
    Struct {
        size: u32,
        members: Vec<BtfMember>,
    },
    Union {
        size: u32,
    },
    Enum {
        size: u32,
    },
    Fwd,
    Typedef {
        target_type_id: u32,
    },
    Volatile {
        target_type_id: u32,
    },
    Const {
        target_type_id: u32,
    },
    Restrict {
        target_type_id: u32,
    },
    Func,
    FuncProto,
    Var {
        name: String,
        type_id: u32,
    },
    DataSec {
        name: String,
        vars: Vec<BtfVarSecinfo>,
    },
    Float {
        size: u32,
    },
    DeclTag {
        target_type_id: u32,
    },
    TypeTag {
        target_type_id: u32,
    },
    Enum64 {
        size: u32,
    },
    Unknown,
}

#[derive(Clone, Debug)]
struct ParsedBtf {
    types: Vec<Option<BtfType>>,
}

impl ParsedBtf {
    fn type_at(&self, type_id: u32) -> Option<&BtfType> {
        self.types.get(type_id as usize)?.as_ref()
    }

    fn resolve_size(&self, type_id: u32) -> Option<u32> {
        self.resolve_size_inner(type_id, 0)
    }

    fn resolve_size_inner(&self, type_id: u32, depth: usize) -> Option<u32> {
        if depth > 32 {
            return None;
        }
        match self.type_at(type_id)? {
            BtfType::Int { size }
            | BtfType::Struct { size, .. }
            | BtfType::Union { size }
            | BtfType::Enum { size }
            | BtfType::Float { size }
            | BtfType::Enum64 { size } => Some(*size),
            BtfType::Ptr { .. } => Some(8),
            BtfType::Array {
                elem_type_id,
                nelems,
            } => self
                .resolve_size_inner(*elem_type_id, depth + 1)
                .and_then(|elem_size| elem_size.checked_mul(*nelems)),
            BtfType::Typedef { target_type_id }
            | BtfType::Volatile { target_type_id }
            | BtfType::Const { target_type_id }
            | BtfType::Restrict { target_type_id }
            | BtfType::DeclTag { target_type_id }
            | BtfType::TypeTag { target_type_id } => {
                self.resolve_size_inner(*target_type_id, depth + 1)
            }
            BtfType::Var { type_id, .. } => self.resolve_size_inner(*type_id, depth + 1),
            _ => None,
        }
    }

    fn unwrap_modifiers(&self, type_id: u32) -> Option<u32> {
        self.unwrap_modifiers_inner(type_id, 0)
    }

    fn unwrap_modifiers_inner(&self, type_id: u32, depth: usize) -> Option<u32> {
        if depth > 32 {
            return None;
        }
        match self.type_at(type_id)? {
            BtfType::Typedef { target_type_id }
            | BtfType::Volatile { target_type_id }
            | BtfType::Const { target_type_id }
            | BtfType::Restrict { target_type_id }
            | BtfType::DeclTag { target_type_id }
            | BtfType::TypeTag { target_type_id } => {
                self.unwrap_modifiers_inner(*target_type_id, depth + 1)
            }
            _ => Some(type_id),
        }
    }

    fn decode_uint_member(&self, type_id: u32) -> Option<u32> {
        let root = self.unwrap_modifiers(type_id)?;
        match self.type_at(root)? {
            BtfType::Ptr { target_type_id } => {
                let array_type_id = self.unwrap_modifiers(*target_type_id)?;
                match self.type_at(array_type_id)? {
                    BtfType::Array { nelems, .. } => Some(*nelems),
                    _ => None,
                }
            }
            BtfType::Array { nelems, .. } => Some(*nelems),
            _ => None,
        }
    }

    fn decode_pointee_size(&self, type_id: u32) -> Option<u32> {
        let root = self.unwrap_modifiers(type_id)?;
        match self.type_at(root)? {
            BtfType::Ptr { target_type_id } => {
                let pointee = self.unwrap_modifiers(*target_type_id)?;
                self.resolve_size(pointee)
            }
            _ => self.resolve_size(root),
        }
    }
}

pub fn parse_bpf_object<P: AsRef<Path>>(path: P) -> Result<ElfBpfObject> {
    let path = path.as_ref();
    let data =
        fs::read(path).with_context(|| format!("failed to read BPF object {}", path.display()))?;
    let elf =
        Elf::parse(&data).with_context(|| format!("failed to parse ELF {}", path.display()))?;

    if !elf.is_64 {
        bail!("{} is not an ELF64 BPF object", path.display());
    }
    if !elf.little_endian {
        bail!("{} is not little-endian", path.display());
    }
    if elf.header.e_machine != EM_BPF {
        bail!("{} is not an ELF eBPF object", path.display());
    }

    let maps_section_index = find_section_index(&elf, ".maps");
    let map_symbols = collect_map_symbols(&elf, maps_section_index);
    let raw_maps = collect_raw_map_metadata(&data, maps_section_index, &map_symbols);
    let btf_maps = collect_btf_map_metadata(&data, &elf)
        .with_context(|| format!("failed to collect BTF map metadata for {}", path.display()))?;
    let mut maps = merge_map_metadata(&map_symbols, &raw_maps, &btf_maps);
    let mut relocation_targets = map_symbols
        .iter()
        .enumerate()
        .map(|(map_index, symbol)| {
            (
                symbol.sym_index,
                RelocationTarget {
                    map_index,
                    force_pseudo_src: None,
                },
            )
        })
        .collect::<HashMap<_, _>>();
    let global_data_maps = collect_global_data_maps(&elf, maps.len());
    for global_data_map in global_data_maps {
        let map_index = maps.len();
        maps.push(global_data_map.map);
        for sym_index in global_data_map.symbol_indices {
            relocation_targets.insert(
                sym_index,
                RelocationTarget {
                    map_index,
                    force_pseudo_src: Some(BPF_PSEUDO_MAP_VALUE),
                },
            );
        }
    }

    let mut relocations_by_section: HashMap<usize, Vec<(usize, RelocationTarget)>> = HashMap::new();
    for (reloc_section_index, relocations) in &elf.shdr_relocs {
        let target_section_index = elf.section_headers[*reloc_section_index].sh_info as usize;
        for relocation in relocations {
            if relocation.r_type != R_BPF_64_64 {
                continue;
            }
            let Some(target) = relocation_targets.get(&relocation.r_sym).cloned() else {
                continue;
            };
            relocations_by_section
                .entry(target_section_index)
                .or_default()
                .push((relocation.r_offset as usize, target));
        }
    }

    let mut programs = Vec::new();
    for (section_index, section) in elf.section_headers.iter().enumerate() {
        if section.sh_type != SHT_PROGBITS {
            continue;
        }
        if (section.sh_flags & u64::from(section_header::SHF_EXECINSTR)) == 0 {
            continue;
        }
        if section.sh_size < 8 {
            continue;
        }

        let Some(section_name) = section_name(&elf, section_index) else {
            continue;
        };
        if section_name.is_empty() || section_name.starts_with('.') {
            continue;
        }

        let mut insns = parse_bpf_insns(
            section_bytes(&data, section)
                .with_context(|| format!("failed to read section {}", section_name))?,
            &section_name,
        )?;

        let mut map_relocations = Vec::new();
        if let Some(relocations) = relocations_by_section.get_mut(&section_index) {
            relocations.sort_unstable_by_key(|(offset, _)| *offset);
            for (offset, target) in relocations.iter() {
                let pc = apply_map_relocation(
                    &mut insns,
                    *offset,
                    target.map_index,
                    target.force_pseudo_src,
                )
                .with_context(|| {
                    format!("failed to relocate {} at byte {}", section_name, offset)
                })?;
                let pseudo_src = insns[pc].src_reg();
                map_relocations.push(ElfProgramMapRelocation {
                    pc,
                    map_index: target.map_index,
                    map_name: maps[target.map_index].name.clone(),
                    pseudo_src,
                });
            }
        }

        map_relocations.sort_unstable_by_key(|reloc| reloc.pc);
        let mut used_map_indices = Vec::new();
        let mut seen_maps = HashSet::new();
        for relocation in &map_relocations {
            if seen_maps.insert(relocation.map_index) {
                used_map_indices.push(relocation.map_index);
            }
        }

        programs.push(ElfProgramInfo {
            section_name: section_name.clone(),
            symbol_name: primary_program_symbol_name(&elf, section_index),
            prog_type: infer_prog_type_from_section(&section_name),
            insns,
            map_relocations,
            used_map_indices,
        });
    }

    Ok(ElfBpfObject {
        path: path.to_path_buf(),
        programs,
        maps,
    })
}

fn find_section_index(elf: &Elf<'_>, name: &str) -> Option<usize> {
    elf.section_headers
        .iter()
        .enumerate()
        .find_map(|(idx, _)| (section_name(elf, idx).as_deref() == Some(name)).then_some(idx))
}

fn section_name(elf: &Elf<'_>, section_index: usize) -> Option<String> {
    let section = elf.section_headers.get(section_index)?;
    Some(elf.shdr_strtab.get_at(section.sh_name)?.to_string())
}

fn section_bytes<'a>(data: &'a [u8], section: &goblin::elf::SectionHeader) -> Result<&'a [u8]> {
    let start = section.sh_offset as usize;
    let end = start
        .checked_add(section.sh_size as usize)
        .context("section size overflow")?;
    data.get(start..end)
        .context("section range falls outside ELF image")
}

fn parse_bpf_insns(bytes: &[u8], section_name: &str) -> Result<Vec<BpfInsn>> {
    if bytes.len() % std::mem::size_of::<BpfInsn>() != 0 {
        bail!(
            "section {} size {} is not aligned to struct bpf_insn",
            section_name,
            bytes.len()
        );
    }

    let mut insns = Vec::with_capacity(bytes.len() / std::mem::size_of::<BpfInsn>());
    for chunk in bytes.chunks_exact(8) {
        insns.push(BpfInsn {
            code: chunk[0],
            regs: chunk[1],
            off: i16::from_le_bytes([chunk[2], chunk[3]]),
            imm: i32::from_le_bytes([chunk[4], chunk[5], chunk[6], chunk[7]]),
        });
    }
    Ok(insns)
}

fn collect_map_symbols(elf: &Elf<'_>, maps_section_index: Option<usize>) -> Vec<ElfMapSymbol> {
    let Some(maps_section_index) = maps_section_index else {
        return Vec::new();
    };

    let mut map_symbols = elf
        .syms
        .iter()
        .enumerate()
        .filter_map(|(sym_index, symbol)| {
            if symbol.st_shndx as usize != maps_section_index {
                return None;
            }
            if symbol.st_type() != sym::STT_OBJECT || symbol.st_size == 0 {
                return None;
            }
            let name = elf.strtab.get_at(symbol.st_name)?;
            Some(ElfMapSymbol {
                sym_index,
                name: name.to_string(),
                section_offset: symbol.st_value as usize,
                symbol_size: symbol.st_size as usize,
            })
        })
        .collect::<Vec<_>>();

    map_symbols.sort_unstable_by_key(|symbol| symbol.section_offset);
    map_symbols
}

#[derive(Clone, Debug)]
struct GlobalDataMap {
    map: ElfMapMetadata,
    symbol_indices: Vec<usize>,
}

fn collect_global_data_maps(elf: &Elf<'_>, base_index: usize) -> Vec<GlobalDataMap> {
    let mut global_data_maps = Vec::new();

    for (section_index, section) in elf.section_headers.iter().enumerate() {
        let Some(section_name) = section_name(elf, section_index) else {
            continue;
        };
        if !is_global_data_section_name(&section_name) {
            continue;
        }

        let symbol_indices = elf
            .syms
            .iter()
            .enumerate()
            .filter_map(|(sym_index, symbol)| {
                if symbol.st_shndx as usize != section_index {
                    return None;
                }
                if symbol.st_type() != sym::STT_OBJECT || symbol.st_size == 0 {
                    return None;
                }
                Some(sym_index)
            })
            .collect::<Vec<_>>();
        if symbol_indices.is_empty() {
            continue;
        }

        let value_size = u32::try_from(section.sh_size).ok().unwrap_or(u32::MAX);
        global_data_maps.push(GlobalDataMap {
            map: ElfMapMetadata {
                index: base_index + global_data_maps.len(),
                name: section_name,
                map_type: Some(BPF_MAP_TYPE_ARRAY),
                key_size: Some(4),
                value_size: Some(value_size),
                max_entries: Some(1),
                map_flags: None,
            },
            symbol_indices,
        });
    }

    global_data_maps
}

fn is_global_data_section_name(name: &str) -> bool {
    matches!(name, ".rodata" | ".data" | ".bss" | ".kconfig")
        || name.starts_with(".rodata.")
        || name.starts_with(".data.")
        || name.starts_with(".bss.")
        || name.starts_with(".kconfig.")
}

fn collect_raw_map_metadata(
    data: &[u8],
    maps_section_index: Option<usize>,
    map_symbols: &[ElfMapSymbol],
) -> Vec<RawMapMetadata> {
    let Some(maps_section_index) = maps_section_index else {
        return Vec::new();
    };

    let mut metadata = Vec::with_capacity(map_symbols.len());
    let Some(section) = Elf::parse(data)
        .ok()
        .and_then(|elf| elf.section_headers.get(maps_section_index).cloned())
    else {
        return Vec::new();
    };
    let Ok(section_bytes) = section_bytes(data, &section) else {
        return Vec::new();
    };

    for symbol in map_symbols {
        let raw = section_bytes
            .get(symbol.section_offset..symbol.section_offset.saturating_add(symbol.symbol_size))
            .unwrap_or(&[]);
        metadata.push(parse_raw_map_definition(raw));
    }

    metadata
}

fn parse_raw_map_definition(bytes: &[u8]) -> RawMapMetadata {
    let read_u32 = |offset: usize| -> Option<u32> {
        let end = offset.checked_add(4)?;
        let bytes = bytes.get(offset..end)?;
        Some(u32::from_le_bytes(bytes.try_into().ok()?))
    };

    let map_type = read_u32(0).filter(|value| *value != 0);
    let key_size = read_u32(4).filter(|value| *value != 0);
    let value_size = read_u32(8).filter(|value| *value != 0);
    let max_entries = read_u32(12).filter(|value| *value != 0);
    let map_flags = read_u32(16).filter(|value| *value != 0);

    RawMapMetadata {
        map_type,
        key_size,
        value_size,
        max_entries,
        map_flags,
    }
}

fn collect_btf_map_metadata(data: &[u8], elf: &Elf<'_>) -> Result<Vec<BtfMapMetadata>> {
    let Some(btf_section_index) = find_section_index(elf, ".BTF") else {
        return Ok(Vec::new());
    };

    let btf_section = &elf.section_headers[btf_section_index];
    let mut btf_bytes = section_bytes(data, btf_section)
        .context("failed to read .BTF section")?
        .to_vec();
    apply_btf_symbol_relocations(&mut btf_bytes, elf, btf_section_index)?;
    let parsed_btf = parse_btf(&btf_bytes)?;

    let Some(maps_datasec) = parsed_btf.types.iter().flatten().find_map(|ty| match ty {
        BtfType::DataSec { name, vars } if name == ".maps" => Some(vars.clone()),
        _ => None,
    }) else {
        return Ok(Vec::new());
    };

    let mut map_metadata = Vec::with_capacity(maps_datasec.len());
    for var_info in maps_datasec {
        let Some(BtfType::Var { name, type_id }) = parsed_btf.type_at(var_info.type_id) else {
            continue;
        };
        let Some(struct_type_id) = parsed_btf.unwrap_modifiers(*type_id) else {
            continue;
        };
        let Some(BtfType::Struct { members, .. }) = parsed_btf.type_at(struct_type_id) else {
            continue;
        };

        let mut metadata = BtfMapMetadata {
            name: (!name.is_empty()).then_some(name.clone()),
            ..Default::default()
        };
        for member in members {
            match member.name.as_str() {
                "type" => metadata.map_type = parsed_btf.decode_uint_member(member.type_id),
                "key" | "key_size" => {
                    metadata.key_size = parsed_btf.decode_pointee_size(member.type_id)
                }
                "value" | "value_size" => {
                    metadata.value_size = parsed_btf.decode_pointee_size(member.type_id)
                }
                "max_entries" => {
                    metadata.max_entries = parsed_btf.decode_uint_member(member.type_id)
                }
                "map_flags" => metadata.map_flags = parsed_btf.decode_uint_member(member.type_id),
                _ => {}
            }
        }
        map_metadata.push(metadata);
    }

    Ok(map_metadata)
}

fn apply_btf_symbol_relocations(
    btf_bytes: &mut [u8],
    elf: &Elf<'_>,
    btf_section_index: usize,
) -> Result<()> {
    let header = parse_btf_header(btf_bytes)?;
    let strings = btf_string_bytes(btf_bytes, &header)?.to_vec();

    for (reloc_section_index, relocations) in &elf.shdr_relocs {
        let target_section_index = elf.section_headers[*reloc_section_index].sh_info as usize;
        if target_section_index != btf_section_index {
            continue;
        }

        for relocation in relocations {
            if relocation.r_type != R_BPF_64_NODYLD32 {
                continue;
            }
            let Some(symbol) = elf.syms.get(relocation.r_sym) else {
                continue;
            };
            let Some(symbol_name) = elf.strtab.get_at(symbol.st_name) else {
                continue;
            };
            let Some(string_offset) = find_btf_string_offset(&strings, symbol_name) else {
                continue;
            };
            let patch_offset = relocation.r_offset as usize;
            let patch_end = patch_offset
                .checked_add(4)
                .context("BTF relocation patch overflow")?;
            let patch = btf_bytes
                .get_mut(patch_offset..patch_end)
                .context("BTF relocation outside section")?;
            patch.copy_from_slice(&string_offset.to_le_bytes());
        }
    }

    Ok(())
}

#[derive(Clone, Copy, Debug)]
struct BtfHeader {
    hdr_len: usize,
    type_off: usize,
    type_len: usize,
    str_off: usize,
    str_len: usize,
}

fn parse_btf_header(bytes: &[u8]) -> Result<BtfHeader> {
    if bytes.len() < 24 {
        bail!("BTF section is too small");
    }
    let magic = u16::from_le_bytes([bytes[0], bytes[1]]);
    if magic != 0xeb9f {
        bail!("invalid BTF magic");
    }
    let hdr_len = u32::from_le_bytes(bytes[4..8].try_into().unwrap()) as usize;
    let type_off = u32::from_le_bytes(bytes[8..12].try_into().unwrap()) as usize;
    let type_len = u32::from_le_bytes(bytes[12..16].try_into().unwrap()) as usize;
    let str_off = u32::from_le_bytes(bytes[16..20].try_into().unwrap()) as usize;
    let str_len = u32::from_le_bytes(bytes[20..24].try_into().unwrap()) as usize;

    Ok(BtfHeader {
        hdr_len,
        type_off,
        type_len,
        str_off,
        str_len,
    })
}

fn btf_type_bytes<'a>(bytes: &'a [u8], header: &BtfHeader) -> Result<&'a [u8]> {
    let start = header
        .hdr_len
        .checked_add(header.type_off)
        .context("BTF type section overflow")?;
    let end = start
        .checked_add(header.type_len)
        .context("BTF type section overflow")?;
    bytes
        .get(start..end)
        .context("BTF type section outside .BTF bytes")
}

fn btf_string_bytes<'a>(bytes: &'a [u8], header: &BtfHeader) -> Result<&'a [u8]> {
    let start = header
        .hdr_len
        .checked_add(header.str_off)
        .context("BTF string section overflow")?;
    let end = start
        .checked_add(header.str_len)
        .context("BTF string section overflow")?;
    bytes
        .get(start..end)
        .context("BTF string section outside .BTF bytes")
}

fn parse_btf(bytes: &[u8]) -> Result<ParsedBtf> {
    let header = parse_btf_header(bytes)?;
    let type_bytes = btf_type_bytes(bytes, &header)?;
    let strings = btf_string_bytes(bytes, &header)?;

    let mut types = vec![None];
    let mut offset = 0usize;
    while offset < type_bytes.len() {
        let name_off = read_u32(type_bytes, &mut offset)?;
        let info = read_u32(type_bytes, &mut offset)?;
        let size_or_type = read_u32(type_bytes, &mut offset)?;
        let kind = (info >> 24) & 0x1f;
        let vlen = (info & 0xffff) as usize;
        // BTF permits anonymous types, and names are only used for optional metadata lookups.
        let name = btf_name_or_anonymous(strings, name_off);

        let ty = match kind {
            1 => {
                let _int_data = read_u32(type_bytes, &mut offset)?;
                BtfType::Int { size: size_or_type }
            }
            2 => BtfType::Ptr {
                target_type_id: size_or_type,
            },
            3 => {
                let elem_type_id = read_u32(type_bytes, &mut offset)?;
                let _index_type_id = read_u32(type_bytes, &mut offset)?;
                let nelems = read_u32(type_bytes, &mut offset)?;
                BtfType::Array {
                    elem_type_id,
                    nelems,
                }
            }
            4 => {
                let mut members = Vec::with_capacity(vlen);
                for _ in 0..vlen {
                    // Anonymous members are valid, so keep parsing even when the name is absent.
                    let member_name =
                        btf_name_or_anonymous(strings, read_u32(type_bytes, &mut offset)?);
                    let type_id = read_u32(type_bytes, &mut offset)?;
                    let _bit_offset = read_u32(type_bytes, &mut offset)?;
                    members.push(BtfMember {
                        name: member_name,
                        type_id,
                    });
                }
                BtfType::Struct {
                    size: size_or_type,
                    members,
                }
            }
            5 => {
                for _ in 0..vlen {
                    let _ = read_u32(type_bytes, &mut offset)?;
                    let _ = read_u32(type_bytes, &mut offset)?;
                    let _ = read_u32(type_bytes, &mut offset)?;
                }
                BtfType::Union { size: size_or_type }
            }
            6 => {
                for _ in 0..vlen {
                    let _ = read_u32(type_bytes, &mut offset)?;
                    let _ = read_u32(type_bytes, &mut offset)?;
                }
                BtfType::Enum { size: size_or_type }
            }
            7 => BtfType::Fwd,
            8 => BtfType::Typedef {
                target_type_id: size_or_type,
            },
            9 => BtfType::Volatile {
                target_type_id: size_or_type,
            },
            10 => BtfType::Const {
                target_type_id: size_or_type,
            },
            11 => BtfType::Restrict {
                target_type_id: size_or_type,
            },
            12 => BtfType::Func,
            13 => {
                for _ in 0..vlen {
                    let _ = read_u32(type_bytes, &mut offset)?;
                    let _ = read_u32(type_bytes, &mut offset)?;
                }
                BtfType::FuncProto
            }
            14 => {
                let _linkage = read_u32(type_bytes, &mut offset)?;
                BtfType::Var {
                    name,
                    type_id: size_or_type,
                }
            }
            15 => {
                let mut vars = Vec::with_capacity(vlen);
                for _ in 0..vlen {
                    vars.push(BtfVarSecinfo {
                        type_id: read_u32(type_bytes, &mut offset)?,
                        _offset: read_u32(type_bytes, &mut offset)?,
                        _size: read_u32(type_bytes, &mut offset)?,
                    });
                }
                BtfType::DataSec { name, vars }
            }
            16 => BtfType::Float { size: size_or_type },
            17 => {
                let _component_idx = read_u32(type_bytes, &mut offset)?;
                BtfType::DeclTag {
                    target_type_id: size_or_type,
                }
            }
            18 => BtfType::TypeTag {
                target_type_id: size_or_type,
            },
            19 => {
                for _ in 0..vlen {
                    let _ = read_u32(type_bytes, &mut offset)?;
                    let _ = read_u32(type_bytes, &mut offset)?;
                    let _ = read_u32(type_bytes, &mut offset)?;
                }
                BtfType::Enum64 { size: size_or_type }
            }
            _ => BtfType::Unknown,
        };
        types.push(Some(ty));
    }

    Ok(ParsedBtf { types })
}

fn read_u32(bytes: &[u8], offset: &mut usize) -> Result<u32> {
    let end = offset.checked_add(4).context("offset overflow")?;
    let value = bytes
        .get(*offset..end)
        .context("buffer underflow while parsing BTF")?;
    *offset = end;
    Ok(u32::from_le_bytes(value.try_into().unwrap()))
}

fn btf_string(strings: &[u8], name_off: u32) -> Option<&str> {
    let start = usize::try_from(name_off).ok()?;
    let tail = strings.get(start..)?;
    let end = tail.iter().position(|byte| *byte == 0)?;
    std::str::from_utf8(&tail[..end]).ok()
}

fn btf_name_or_anonymous(strings: &[u8], name_off: u32) -> String {
    match btf_string(strings, name_off) {
        Some(name) => name.to_string(),
        None => String::new(),
    }
}

fn find_btf_string_offset(strings: &[u8], needle: &str) -> Option<u32> {
    let mut offset = 0usize;
    while offset < strings.len() {
        let end = offset + strings[offset..].iter().position(|byte| *byte == 0)?;
        if strings.get(offset..end)? == needle.as_bytes() {
            return u32::try_from(offset).ok();
        }
        offset = end.saturating_add(1);
    }
    None
}

fn merge_map_metadata(
    map_symbols: &[ElfMapSymbol],
    raw_maps: &[RawMapMetadata],
    btf_maps: &[BtfMapMetadata],
) -> Vec<ElfMapMetadata> {
    let mut btf_by_name = btf_maps
        .iter()
        .filter_map(|meta| meta.name.clone().map(|name| (name, meta.clone())))
        .collect::<HashMap<_, _>>();
    let mut unnamed_btf = VecDeque::from(
        btf_maps
            .iter()
            .filter(|meta| meta.name.is_none())
            .cloned()
            .collect::<Vec<_>>(),
    );

    map_symbols
        .iter()
        .enumerate()
        .map(|(index, symbol)| {
            // Some objects provide only BTF-backed map metadata, so a missing raw entry is valid.
            let raw = match raw_maps.get(index).cloned() {
                Some(raw) => raw,
                None => RawMapMetadata::default(),
            };
            // Likewise, not every symbol has a matching named BTF record.
            let btf = match btf_by_name
                .remove(&symbol.name)
                .or_else(|| unnamed_btf.pop_front())
            {
                Some(btf) => btf,
                None => BtfMapMetadata::default(),
            };

            ElfMapMetadata {
                index,
                name: symbol.name.clone(),
                map_type: btf.map_type.or(raw.map_type),
                key_size: btf.key_size.or(raw.key_size),
                value_size: btf.value_size.or(raw.value_size),
                max_entries: btf.max_entries.or(raw.max_entries),
                map_flags: btf.map_flags.or(raw.map_flags),
            }
        })
        .collect()
}

fn apply_map_relocation(
    insns: &mut [BpfInsn],
    byte_offset: usize,
    map_index: usize,
    force_pseudo_src: Option<u8>,
) -> Result<usize> {
    if byte_offset % std::mem::size_of::<BpfInsn>() != 0 {
        bail!("map relocation offset {} is not insn-aligned", byte_offset);
    }
    let pc = byte_offset / std::mem::size_of::<BpfInsn>();
    if pc + 1 >= insns.len() {
        bail!("map relocation at pc {} falls off end of program", pc);
    }

    let pseudo_src = force_pseudo_src.unwrap_or_else(|| {
        if insns[pc + 1].imm != 0 {
            BPF_PSEUDO_MAP_VALUE
        } else {
            BPF_PSEUDO_MAP_FD
        }
    });

    let insn = insns
        .get_mut(pc)
        .context("map relocation primary insn missing")?;
    if insn.code != (BPF_LD | BPF_DW | BPF_IMM) {
        bail!("map relocation at pc {} does not target LD_IMM64", pc);
    }
    insn.regs = BpfInsn::make_regs(insn.dst_reg(), pseudo_src);
    insn.imm = i32::try_from(map_index + 1).context("map index does not fit in i32")?;
    Ok(pc)
}

fn primary_program_symbol_name(elf: &Elf<'_>, section_index: usize) -> Option<String> {
    let mut primary = None;
    for symbol in elf.syms.iter() {
        if symbol.st_shndx as usize != section_index {
            continue;
        }
        if symbol.st_type() != sym::STT_FUNC {
            continue;
        }
        let Some(name) = elf.strtab.get_at(symbol.st_name) else {
            continue;
        };
        if symbol.st_value == 0 {
            return Some(name.to_string());
        }
        if primary.is_none() {
            primary = Some(name.to_string());
        }
    }
    primary
}

fn infer_prog_type_from_section(section_name: &str) -> u32 {
    if section_name == "xdp" || section_name.starts_with("xdp/") {
        return BPF_PROG_TYPE_XDP;
    }
    if section_name == "tc"
        || section_name.starts_with("tc/")
        || section_name == "classifier"
        || section_name.starts_with("classifier/")
    {
        return BPF_PROG_TYPE_SCHED_CLS;
    }
    if section_name == "action" || section_name.starts_with("action/") {
        return BPF_PROG_TYPE_SCHED_ACT;
    }
    if section_name.starts_with("tracepoint/") {
        return BPF_PROG_TYPE_TRACEPOINT;
    }
    if section_name == "perf_event" || section_name.starts_with("perf_event/") {
        return BPF_PROG_TYPE_PERF_EVENT;
    }
    if section_name.starts_with("raw_tracepoint/") || section_name.starts_with("raw_tp/") {
        return BPF_PROG_TYPE_RAW_TRACEPOINT;
    }
    if section_name.starts_with("kprobe/")
        || section_name.starts_with("kretprobe/")
        || section_name.starts_with("uprobe/")
        || section_name.starts_with("uretprobe/")
    {
        return BPF_PROG_TYPE_KPROBE;
    }
    if section_name.starts_with("fentry/")
        || section_name.starts_with("fexit/")
        || section_name.starts_with("fmod_ret/")
        || section_name.starts_with("iter/")
        || section_name.starts_with("struct_ops/")
    {
        return BPF_PROG_TYPE_TRACING;
    }
    if section_name.starts_with("lsm/") {
        return BPF_PROG_TYPE_LSM;
    }
    if section_name.starts_with("syscall/") {
        return BPF_PROG_TYPE_SYSCALL;
    }
    if section_name.starts_with("cgroup_skb/") {
        return BPF_PROG_TYPE_CGROUP_SKB;
    }
    if section_name.starts_with("sk_skb/") {
        return BPF_PROG_TYPE_SK_SKB;
    }
    if section_name == "lwt_in" || section_name.starts_with("lwt_in/") {
        return BPF_PROG_TYPE_LWT_IN;
    }
    if section_name == "lwt_out" || section_name.starts_with("lwt_out/") {
        return BPF_PROG_TYPE_LWT_OUT;
    }
    if section_name == "lwt_xmit" || section_name.starts_with("lwt_xmit/") {
        return BPF_PROG_TYPE_LWT_XMIT;
    }
    if section_name.starts_with("netfilter/") {
        return BPF_PROG_TYPE_NETFILTER;
    }
    if section_name == "socket" || section_name.starts_with("socket/") {
        return BPF_PROG_TYPE_SOCKET_FILTER;
    }

    0
}

#[cfg(test)]
mod tests {
    use super::*;

    fn fixture(path: &str) -> String {
        format!("{}/tests/fixtures/{}", env!("CARGO_MANIFEST_DIR"), path)
    }

    #[test]
    fn parse_katran_xdp_pktcntr_programs_and_maps() {
        let object = parse_bpf_object(fixture("katran/xdp_pktcntr.bpf.o")).unwrap();
        let program = object.program_named("pktcntr").unwrap();

        assert_eq!(program.section_name, "xdp");
        assert_eq!(program.symbol_name.as_deref(), Some("pktcntr"));
        assert_eq!(program.prog_type, BPF_PROG_TYPE_XDP);
        assert_eq!(program.map_relocations.len(), 2);
        assert_eq!(object.maps.len(), 2);
        assert_eq!(object.maps[0].name, "ctl_array");
        assert_eq!(object.maps[0].map_type, Some(2));
        assert_eq!(object.maps[0].key_size, Some(4));
        assert_eq!(object.maps[0].value_size, Some(4));
        assert_eq!(object.maps[0].max_entries, Some(2));
        assert_eq!(object.maps[1].name, "cntrs_array");
        assert_eq!(object.maps[1].map_type, Some(6));
        assert_eq!(object.maps[1].value_size, Some(8));

        let first_map_ld = &program.insns[program.map_relocations[0].pc];
        assert!(first_map_ld.is_ldimm64());
        assert_eq!(first_map_ld.src_reg(), BPF_PSEUDO_MAP_FD);
        assert_eq!(first_map_ld.imm, 1);
    }

    #[test]
    fn load_first_program_still_returns_real_insns() {
        let path = fixture("xdp-tools/xdp_load_bytes.bpf.o");
        let object = parse_bpf_object(&path).unwrap();
        let first = object.first_program().unwrap();

        assert!(!first.insns.is_empty());
        assert!(first.insns.last().unwrap().is_exit());
    }

    #[test]
    fn parse_bindsnoop_global_rodata_relocations_as_pseudo_map_value() {
        let object = parse_bpf_object(fixture("bcc/libbpf-tools/bindsnoop.bpf.o")).unwrap();
        let program = object.program_named("kprobe/inet_bind").unwrap();

        let rodata_map = object
            .maps
            .iter()
            .find(|map| map.name == ".rodata")
            .expect("expected synthetic .rodata map");
        assert_eq!(rodata_map.map_type, Some(BPF_MAP_TYPE_ARRAY));
        assert_eq!(rodata_map.key_size, Some(4));
        assert_eq!(rodata_map.max_entries, Some(1));
        assert_eq!(rodata_map.value_size, Some(10));

        let rodata_relocs = program
            .map_relocations
            .iter()
            .filter(|reloc| reloc.map_name == ".rodata")
            .collect::<Vec<_>>();
        assert_eq!(rodata_relocs.len(), 2);
        assert!(rodata_relocs
            .iter()
            .all(|reloc| reloc.pseudo_src == BPF_PSEUDO_MAP_VALUE));
    }
}
