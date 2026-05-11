// SPDX-License-Identifier: MIT
// Map metadata analysis for map inlining.

use std::collections::{BTreeMap, HashMap};

#[cfg(test)]
use crate::analysis::BlockId;
use crate::analysis::{BBProgram, InsnSite};
#[cfg(test)]
use crate::insn::insn_width;
#[cfg(test)]
use crate::insn::BpfInsn;
use crate::insn::MapPseudo;
#[cfg(test)]
use crate::pass::BpfProgram;
use crate::pass::PassContext;

const BPF_MAP_TYPE_HASH: u32 = libbpf_sys::BPF_MAP_TYPE_HASH;
const BPF_MAP_TYPE_ARRAY: u32 = libbpf_sys::BPF_MAP_TYPE_ARRAY;
const BPF_MAP_TYPE_ARRAY_OF_MAPS: u32 = libbpf_sys::BPF_MAP_TYPE_ARRAY_OF_MAPS;
#[cfg(test)]
const BPF_MAP_TYPE_PERCPU_HASH: u32 = libbpf_sys::BPF_MAP_TYPE_PERCPU_HASH;
const BPF_MAP_TYPE_PERCPU_ARRAY: u32 = libbpf_sys::BPF_MAP_TYPE_PERCPU_ARRAY;
const BPF_MAP_TYPE_HASH_OF_MAPS: u32 = libbpf_sys::BPF_MAP_TYPE_HASH_OF_MAPS;
const BPF_MAP_TYPE_LRU_HASH: u32 = libbpf_sys::BPF_MAP_TYPE_LRU_HASH;
#[cfg(test)]
const BPF_MAP_TYPE_LRU_PERCPU_HASH: u32 = libbpf_sys::BPF_MAP_TYPE_LRU_PERCPU_HASH;

/// Runtime metadata for a live kernel map referenced by the program.
///
/// `map_inline` uses this metadata for map layout and type checks. BPF-side
/// mutability is derived separately from writer helper calls and map type.
#[derive(Clone, Debug, PartialEq, Eq)]
pub struct MapInfo {
    pub map_type: u32,
    pub key_size: u32,
    pub value_size: u32,
    pub max_entries: u32,
    pub map_id: u32,
}

impl MapInfo {
    /// Returns whether this map type supports direct value access (i.e. the
    /// kernel allows reading element values by ID). Map types like
    /// `PERF_EVENT_ARRAY`, `PROG_ARRAY`, `RINGBUF`, `STACK_TRACE`, and
    /// `CGROUP_STORAGE` do NOT support direct value access and must never be
    /// inlined.
    ///
    /// `PERCPU_HASH`/`LRU_PERCPU_HASH` are deliberately excluded: the userspace
    /// lookup returns a concatenated per-CPU blob and the running program sees
    /// only the current CPU slot. `PERCPU_ARRAY` is handled as a special case:
    /// map_inline may inline it only after verifying that every per-CPU slot is
    /// byte-identical for the accessed key.
    pub fn supports_direct_value_access(&self) -> bool {
        matches!(
            self.map_type,
            BPF_MAP_TYPE_HASH
                | BPF_MAP_TYPE_ARRAY
                | BPF_MAP_TYPE_PERCPU_ARRAY
                | BPF_MAP_TYPE_LRU_HASH
        )
    }

    /// Returns whether this map stores inner map references as values.
    pub fn is_map_in_map(&self) -> bool {
        matches!(
            self.map_type,
            BPF_MAP_TYPE_ARRAY_OF_MAPS | BPF_MAP_TYPE_HASH_OF_MAPS
        )
    }

    /// Returns whether map_inline can eliminate the lookup/null-check sequence.
    pub fn has_removable_lookup_pattern(&self) -> bool {
        matches!(
            self.map_type,
            BPF_MAP_TYPE_ARRAY | BPF_MAP_TYPE_PERCPU_ARRAY
        )
    }

    /// Returns whether lookup removal must prove the snapshot key is present.
    pub fn requires_entry_presence_check(&self) -> bool {
        matches!(self.map_type, BPF_MAP_TYPE_HASH | BPF_MAP_TYPE_LRU_HASH)
    }
}

/// A single `LD_IMM64` map reference found in the program.
#[derive(Clone, Debug, PartialEq, Eq)]
pub struct MapReference {
    pub site: InsnSite,
    pub pc: usize,
    pub dst_reg: u8,
    pub imm: i32,
    pub map_index: usize,
    pub map_id: Option<u32>,
    pub info: Option<MapInfo>,
}

/// Result of resolving all pseudo-map references in the program.
#[derive(Clone, Debug, Default, PartialEq, Eq)]
pub struct MapInfoResult {
    pub references: Vec<MapReference>,
    pub unique_maps: Vec<MapInfo>,
}

impl MapInfoResult {
    /// Returns the resolved map reference at `site`, if any.
    pub fn reference_at_site(&self, site: InsnSite) -> Option<&MapReference> {
        self.references
            .iter()
            .find(|reference| reference.site == site)
    }
}

/// Analysis that resolves pseudo-map references back to live maps.
pub struct MapInfoAnalysis;

type MapInfoAnalysisResult<T> = std::result::Result<T, String>;

#[derive(Clone, Debug, PartialEq, Eq)]
struct MapBinding {
    site: InsnSite,
    pc_load: usize,
    kind: MapPseudo,
    dst_reg: u8,
    imm: i32,
    map_idx: Option<usize>,
    map_id: Option<u32>,
}

impl MapInfoAnalysis {
    #[cfg(test)]
    pub fn run(program: &BpfProgram) -> MapInfoAnalysisResult<MapInfoResult> {
        analyze_map_info_from_bpf_program(program)
    }
}

pub(super) fn analyze_map_info(
    program: &BBProgram,
    ctx: &PassContext,
) -> MapInfoAnalysisResult<MapInfoResult> {
    let fd_bindings = program
        .map_bindings()
        .iter()
        .map(|binding| (binding.old_fd, binding.map_id))
        .collect::<HashMap<_, _>>();
    let map_refs = collect_map_bindings_from_sites(program, &ctx.map_ids, &fd_bindings)?;
    collect_map_references_from_bindings(ctx.map_ids.len(), map_refs, |map_id| {
        let Some(metadata) = ctx.map_metadata.get(&map_id) else {
            return Err(format!(
                "map_values snapshot has no metadata for map {}",
                map_id
            ));
        };
        Ok(Some(MapInfo {
            map_type: metadata.map_type,
            key_size: metadata.key_size,
            value_size: metadata.value_size,
            max_entries: metadata.max_entries,
            map_id: metadata.map_id,
        }))
    })
}

#[cfg(test)]
fn analyze_map_info_from_bpf_program(program: &BpfProgram) -> MapInfoAnalysisResult<MapInfoResult> {
    let provider = program.map_provider.clone();
    let map_refs = collect_map_bindings(&program.insns, &program.map_ids, &program.map_fd_bindings);
    collect_map_references_from_bindings(program.map_ids.len(), map_refs, move |map_id| {
        provider.map_info(program, map_id)
    })
}

/// Scan the instruction stream and resolve each unique map reference.
#[cfg(test)]
pub fn collect_map_references<F>(
    insns: &[BpfInsn],
    map_ids: &[u32],
    resolver: F,
) -> MapInfoAnalysisResult<MapInfoResult>
where
    F: FnMut(u32) -> MapInfoAnalysisResult<Option<MapInfo>>,
{
    collect_map_references_with_bindings(insns, map_ids, &HashMap::new(), resolver)
}

/// Scan the instruction stream and resolve each unique map reference. FD-form
/// references use a stable `old_fd -> map_id` binding table when available;
/// IDX-form references already carry canonical map indexes.
#[cfg(test)]
pub fn collect_map_references_with_bindings<F>(
    insns: &[BpfInsn],
    map_ids: &[u32],
    map_fd_bindings: &HashMap<i32, u32>,
    resolver: F,
) -> MapInfoAnalysisResult<MapInfoResult>
where
    F: FnMut(u32) -> MapInfoAnalysisResult<Option<MapInfo>>,
{
    let mut program = BpfProgram::new(insns.to_vec());
    program.map_ids = map_ids.to_vec();
    program.map_fd_bindings = map_fd_bindings.clone();
    let map_refs = collect_map_bindings(&program.insns, &program.map_ids, &program.map_fd_bindings);
    collect_map_references_from_bindings(map_ids.len(), map_refs, resolver)
}

fn collect_map_bindings_from_sites(
    program: &BBProgram,
    map_ids: &[u32],
    fd_bindings: &HashMap<i32, u32>,
) -> MapInfoAnalysisResult<Vec<MapBinding>> {
    let mut bindings = Vec::new();
    let mut fd_order = Vec::<i32>::new();
    let site_pcs = program.current_site_pcs().map_err(|err| err.to_string())?;

    for site in program.current_sites().map_err(|err| err.to_string())? {
        let Some(insn) = program.insn_at(site) else {
            continue;
        };
        if let Some(kind) = insn.map_pseudo_kind() {
            let pc = site_pcs
                .get(&site)
                .copied()
                .ok_or_else(|| format!("current pc missing for map reference site {:?}", site))?;
            let (map_idx, map_id) =
                resolve_map_ref(kind, insn.imm, map_ids, fd_bindings, &mut fd_order);
            bindings.push(MapBinding {
                site,
                pc_load: pc,
                kind,
                dst_reg: insn.dst_reg(),
                imm: insn.imm,
                map_idx,
                map_id,
            });
        }
    }

    Ok(bindings)
}

#[cfg(test)]
fn collect_map_bindings(
    insns: &[BpfInsn],
    map_ids: &[u32],
    fd_bindings: &HashMap<i32, u32>,
) -> Vec<MapBinding> {
    let mut bindings = Vec::new();
    let mut fd_order = Vec::<i32>::new();
    let mut pc = 0usize;

    while pc < insns.len() {
        let insn = insns[pc];
        if let Some(kind) = insn.map_pseudo_kind() {
            let (map_idx, map_id) =
                resolve_map_ref(kind, insn.imm, map_ids, fd_bindings, &mut fd_order);
            bindings.push(MapBinding {
                site: InsnSite {
                    block: BlockId(0),
                    idx: bindings.len(),
                },
                pc_load: pc,
                kind,
                dst_reg: insn.dst_reg(),
                imm: insn.imm,
                map_idx,
                map_id,
            });
        }
        pc += insn_width(&insn);
    }

    bindings
}

fn resolve_map_ref(
    kind: MapPseudo,
    imm: i32,
    map_ids: &[u32],
    fd_bindings: &HashMap<i32, u32>,
    fd_order: &mut Vec<i32>,
) -> (Option<usize>, Option<u32>) {
    if kind.uses_index() {
        let Ok(index) = usize::try_from(imm) else {
            return (None, None);
        };
        return (Some(index), map_ids.get(index).copied());
    }

    if !fd_order.contains(&imm) {
        fd_order.push(imm);
    }
    let index = fd_order.iter().position(|fd| *fd == imm);
    let map_id = fd_bindings
        .get(&imm)
        .copied()
        .or_else(|| index.and_then(|idx| map_ids.get(idx).copied()));
    (index, map_id)
}

fn collect_map_references_from_bindings<F>(
    map_id_count: usize,
    map_refs: Vec<MapBinding>,
    mut resolver: F,
) -> MapInfoAnalysisResult<MapInfoResult>
where
    F: FnMut(u32) -> MapInfoAnalysisResult<Option<MapInfo>>,
{
    let mut references = Vec::new();
    let mut resolved_by_index: BTreeMap<usize, Option<MapInfo>> = BTreeMap::new();

    for binding in map_refs {
        let kind @ (MapPseudo::Fd | MapPseudo::Idx) = binding.kind else {
            continue;
        };
        let map_index = binding.map_idx.ok_or_else(|| {
            format!(
                "negative pseudo-map index {} at pc {}",
                binding.imm, binding.pc_load
            )
        })?;
        let map_id = if kind == MapPseudo::Idx {
            Some(binding.map_id.ok_or_else(|| {
                format!(
                    "pseudo-map index {} at pc {} out of range for {} map ids",
                    map_index, binding.pc_load, map_id_count
                )
            })?)
        } else {
            binding.map_id
        };
        let info = match resolved_by_index.get(&map_index) {
            Some(info) => info.clone(),
            None => {
                let resolved = match map_id {
                    Some(map_id) => resolver(map_id)?,
                    None => None,
                };
                resolved_by_index.insert(map_index, resolved.clone());
                resolved
            }
        };

        references.push(MapReference {
            site: binding.site,
            pc: binding.pc_load,
            dst_reg: binding.dst_reg,
            imm: binding.imm,
            map_index,
            map_id,
            info,
        });
    }

    let mut resolved_indexes = resolved_by_index.keys().copied().collect::<Vec<_>>();
    resolved_indexes.sort_unstable();
    let unique_maps = resolved_indexes
        .into_iter()
        .filter_map(|index| resolved_by_index.get(&index).cloned().flatten())
        .collect();

    Ok(MapInfoResult {
        references,
        unique_maps,
    })
}

#[cfg(test)]
#[path = "map_info_tests.rs"]
mod tests;
