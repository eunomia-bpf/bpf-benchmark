// SPDX-License-Identifier: MIT
// Map metadata analysis for map inlining.

use std::collections::HashMap;

use crate::insn::{insn_width, BpfInsn, MapPseudo};
#[cfg(test)]
use crate::pass::BpfProgram;

use super::MapInlineView;

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

    /// Returns whether userspace can read this map's backing values correctly.
    pub fn supports_direct_value_inline(&self) -> bool {
        self.supports_direct_value_access()
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
    /// Returns the resolved map reference at `pc`, if any.
    pub fn reference_at_pc(&self, pc: usize) -> Option<&MapReference> {
        self.references.iter().find(|reference| reference.pc == pc)
    }
}

/// Analysis that resolves pseudo-map references back to live maps.
pub struct MapInfoAnalysis;

type MapInfoAnalysisResult<T> = std::result::Result<T, String>;

#[derive(Clone, Debug, PartialEq, Eq)]
struct MapBinding {
    pc_load: usize,
    kind: MapPseudo,
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
    program: &MapInlineView<'_>,
) -> MapInfoAnalysisResult<MapInfoResult> {
    let map_refs = collect_map_bindings(
        &program.linear.insns,
        &program.ctx.map_ids,
        &program.map_fd_bindings,
    );
    collect_map_references_from_bindings(
        &program.linear.insns,
        program.ctx.map_ids.len(),
        map_refs,
        |map_id| program.map_info(map_id),
    )
}

#[cfg(test)]
fn analyze_map_info_from_bpf_program(program: &BpfProgram) -> MapInfoAnalysisResult<MapInfoResult> {
    let provider = program.map_provider.clone();
    let map_refs = collect_map_bindings(&program.insns, &program.map_ids, &program.map_fd_bindings);
    collect_map_references_from_bindings(
        &program.insns,
        program.map_ids.len(),
        map_refs,
        move |map_id| provider.map_info(program, map_id),
    )
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
    collect_map_references_from_bindings(insns, map_ids.len(), map_refs, resolver)
}

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
                pc_load: pc,
                kind,
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
    insns: &[BpfInsn],
    map_id_count: usize,
    map_refs: Vec<MapBinding>,
    mut resolver: F,
) -> MapInfoAnalysisResult<MapInfoResult>
where
    F: FnMut(u32) -> MapInfoAnalysisResult<Option<MapInfo>>,
{
    let mut references = Vec::new();
    let mut resolved_by_index: HashMap<usize, Option<MapInfo>> = HashMap::new();

    for binding in map_refs {
        let kind @ (MapPseudo::Fd | MapPseudo::Idx) = binding.kind else {
            continue;
        };
        if binding.pc_load + 1 >= insns.len() {
            continue;
        }
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
            pc: binding.pc_load,
            dst_reg: insns[binding.pc_load].dst_reg(),
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
mod tests {
    use super::*;
    use crate::insn::{BpfInsn, MapPseudo, BPF_DW, BPF_IMM, BPF_LD};
    use crate::pass::BpfProgram;

    fn make_ld_imm64(dst: u8, src: u8, imm_lo: i32) -> [BpfInsn; 2] {
        [
            BpfInsn::new(
                BPF_LD | BPF_DW | BPF_IMM,
                BpfInsn::make_regs(dst, src),
                0,
                imm_lo,
            ),
            BpfInsn::new(0, 0, 0, 0),
        ]
    }

    fn array_map(map_id: u32, max_entries: u32) -> MapInfo {
        MapInfo {
            map_type: BPF_MAP_TYPE_ARRAY,
            key_size: 4,
            value_size: 8,
            max_entries,
            map_id,
        }
    }

    fn hash_map(map_id: u32) -> MapInfo {
        MapInfo {
            map_type: BPF_MAP_TYPE_HASH,
            key_size: 4,
            value_size: 8,
            max_entries: 16,
            map_id,
        }
    }

    fn lru_hash_map(map_id: u32) -> MapInfo {
        MapInfo {
            map_type: BPF_MAP_TYPE_LRU_HASH,
            key_size: 4,
            value_size: 8,
            max_entries: 16,
            map_id,
        }
    }

    #[test]
    fn collect_map_references_tracks_unique_fd_order() {
        let ld0 = make_ld_imm64(1, MapPseudo::Fd.src_reg(), 10);
        let ld1 = make_ld_imm64(2, MapPseudo::Fd.src_reg(), 11);
        let ld2 = make_ld_imm64(3, MapPseudo::Fd.src_reg(), 10);
        let insns = vec![ld0[0], ld0[1], ld1[0], ld1[1], ld2[0], ld2[1]];

        let result = collect_map_references(&insns, &[101, 202], |map_id| {
            Ok(match map_id {
                101 => Some(array_map(101, 4)),
                202 => Some(hash_map(202)),
                _ => None,
            })
        })
        .expect("map reference collection should succeed");

        assert_eq!(result.references.len(), 3);
        assert_eq!(result.references[0].map_index, 0);
        assert_eq!(result.references[1].map_index, 1);
        assert_eq!(result.references[2].map_index, 0);
        assert_eq!(result.references[0].map_id, Some(101));
        assert_eq!(result.references[1].map_id, Some(202));
        assert_eq!(result.unique_maps.len(), 2);
        assert!(result.unique_maps[0].supports_direct_value_inline());
        assert!(result.unique_maps[1].supports_direct_value_inline());
        assert!(result.unique_maps[1].requires_entry_presence_check());
    }

    #[test]
    fn map_info_marks_lru_hash_as_entry_presence_checked() {
        let ld = make_ld_imm64(1, MapPseudo::Fd.src_reg(), 10);
        let insns = vec![ld[0], ld[1]];

        let result = collect_map_references(&insns, &[303], |map_id| {
            Ok(match map_id {
                303 => Some(lru_hash_map(303)),
                _ => None,
            })
        })
        .expect("map reference collection should succeed");

        assert_eq!(result.unique_maps.len(), 1);
        assert!(result.unique_maps[0].supports_direct_value_inline());
        assert!(result.unique_maps[0].requires_entry_presence_check());
        assert!(!result.unique_maps[0].has_removable_lookup_pattern());
    }

    #[test]
    fn collect_map_references_ignores_non_map_ldimm64() {
        let plain = make_ld_imm64(1, 0, 77);
        let result = collect_map_references(&plain, &[101], |_| Ok(Some(array_map(101, 4))))
            .expect("map reference collection should succeed");
        assert!(result.references.is_empty());
        assert!(result.unique_maps.is_empty());
    }

    #[test]
    fn collect_map_references_handles_missing_map_ids() {
        let ld0 = make_ld_imm64(1, MapPseudo::Fd.src_reg(), 10);
        let ld1 = make_ld_imm64(2, MapPseudo::Fd.src_reg(), 11);
        let insns = vec![ld0[0], ld0[1], ld1[0], ld1[1]];

        let result =
            collect_map_references(&insns, &[101], |map_id| Ok(Some(array_map(map_id, 4))))
                .expect("map reference collection should succeed");

        assert_eq!(result.references.len(), 2);
        assert_eq!(result.references[0].map_id, Some(101));
        assert_eq!(result.references[1].map_id, None);
        assert_eq!(result.references[1].info, None);
        assert_eq!(result.unique_maps.len(), 1);
    }

    #[test]
    fn map_info_analysis_runs_without_live_map_metadata() {
        let ld = make_ld_imm64(1, MapPseudo::Fd.src_reg(), 10);
        let program = BpfProgram::new(vec![ld[0], ld[1]]);
        let result = MapInfoAnalysis::run(&program).expect("map info analysis should succeed");

        assert_eq!(result.references.len(), 1);
        assert_eq!(result.references[0].map_id, None);
        assert_eq!(result.references[0].info, None);
    }

    #[test]
    fn map_info_analysis_propagates_live_map_lookup_errors() {
        #[derive(Debug)]
        struct ErrorMapProvider;

        impl crate::pass::MapProvider for ErrorMapProvider {
            fn map_info(
                &self,
                _program: &BpfProgram,
                map_id: u32,
            ) -> MapInfoAnalysisResult<Option<MapInfo>> {
                Err(format!(
                    "resolve live map info for map {map_id}: test error"
                ))
            }

            fn lookup_value_size(
                &self,
                _program: &BpfProgram,
                _info: &MapInfo,
            ) -> MapInfoAnalysisResult<usize> {
                unreachable!("map_info analysis only resolves metadata")
            }

            fn lookup_elem(
                &self,
                _program: &BpfProgram,
                _map_id: u32,
                _key: &[u8],
                _value_size: usize,
            ) -> std::result::Result<Vec<u8>, crate::pass::MapLookupError> {
                unreachable!("map_info analysis only resolves metadata")
            }
        }

        let ld = make_ld_imm64(1, MapPseudo::Fd.src_reg(), 10);
        let mut program = BpfProgram::new(vec![ld[0], ld[1]]);
        program.map_provider = std::sync::Arc::new(ErrorMapProvider);
        program.set_map_ids(vec![999_999]);

        let err =
            MapInfoAnalysis::run(&program).expect_err("missing live map metadata should propagate");

        assert!(err.contains("resolve live map info for map 999999"));
    }

    #[test]
    fn map_info_analysis_preserves_old_fd_binding_after_leading_map_is_deleted() {
        let ld0 = make_ld_imm64(1, MapPseudo::Fd.src_reg(), 10);
        let ld1 = make_ld_imm64(2, MapPseudo::Fd.src_reg(), 11);
        let mut program = BpfProgram::new(vec![ld0[0], ld0[1], ld1[0], ld1[1]]);
        program.set_map_ids(vec![101, 202]);

        program.insns = vec![ld1[0], ld1[1]];

        let result = collect_map_references_with_bindings(
            &program.insns,
            &program.map_ids,
            &program.map_fd_bindings,
            |map_id| Ok(Some(array_map(map_id, 4))),
        )
        .expect("map reference collection should succeed");

        assert_eq!(result.references.len(), 1);
        assert_eq!(result.references[0].imm, 11);
        assert_eq!(result.references[0].map_id, Some(202));
    }

    #[test]
    fn map_info_analysis_resolves_canonical_idx_refs_by_map_id_order() {
        let ld0 = make_ld_imm64(1, MapPseudo::Idx.src_reg(), 1);
        let ld1 = make_ld_imm64(2, MapPseudo::Idx.src_reg(), 0);
        let program = BpfProgram::new(vec![ld0[0], ld0[1], ld1[0], ld1[1]]);

        let result = collect_map_references(&program.insns, &[101, 202], |map_id| {
            Ok(Some(array_map(map_id, 4)))
        })
        .expect("canonical IDX references should resolve through map_ids");

        assert_eq!(result.references.len(), 2);
        assert_eq!(result.references[0].map_index, 1);
        assert_eq!(result.references[0].map_id, Some(202));
        assert_eq!(result.references[1].map_index, 0);
        assert_eq!(result.references[1].map_id, Some(101));
        assert_eq!(result.unique_maps.len(), 2);
    }

    #[test]
    fn unsupported_map_types_reject_direct_value_access() {
        const BPF_MAP_TYPE_PROG_ARRAY: u32 = libbpf_sys::BPF_MAP_TYPE_PROG_ARRAY;
        const BPF_MAP_TYPE_PERF_EVENT_ARRAY: u32 = libbpf_sys::BPF_MAP_TYPE_PERF_EVENT_ARRAY;
        const BPF_MAP_TYPE_STACK_TRACE: u32 = libbpf_sys::BPF_MAP_TYPE_STACK_TRACE;
        const BPF_MAP_TYPE_CGROUP_STORAGE: u32 = libbpf_sys::BPF_MAP_TYPE_CGROUP_STORAGE;
        const BPF_MAP_TYPE_RINGBUF: u32 = libbpf_sys::BPF_MAP_TYPE_RINGBUF;

        for map_type in [
            BPF_MAP_TYPE_PROG_ARRAY,
            BPF_MAP_TYPE_PERF_EVENT_ARRAY,
            BPF_MAP_TYPE_PERCPU_HASH,
            BPF_MAP_TYPE_STACK_TRACE,
            BPF_MAP_TYPE_LRU_PERCPU_HASH,
            BPF_MAP_TYPE_CGROUP_STORAGE,
            BPF_MAP_TYPE_RINGBUF,
        ] {
            let info = MapInfo {
                map_type,
                key_size: 4,
                value_size: 8,
                max_entries: 16,
                map_id: 999,
            };
            assert!(
                !info.supports_direct_value_access(),
                "map_type {} should NOT support direct value access",
                map_type
            );
            assert!(
                !info.supports_direct_value_inline(),
                "map_type {} should NOT be inlineable",
                map_type
            );
        }
    }

    /// PERCPU_ARRAY is only conditionally safe: map_inline must still prove
    /// that all per-CPU slots carry the same bytes for the accessed key.
    #[test]
    fn percpu_array_is_conditionally_inlineable_but_percpu_hashes_still_are_not() {
        let percpu_array = MapInfo {
            map_type: BPF_MAP_TYPE_PERCPU_ARRAY,
            key_size: 4,
            value_size: 8,
            max_entries: 16,
            map_id: 501,
        };
        assert!(
            percpu_array.supports_direct_value_access(),
            "PERCPU_ARRAY should allow site-level direct blob access"
        );
        assert!(
            percpu_array.supports_direct_value_inline(),
            "PERCPU_ARRAY should be conditionally inlineable"
        );
        assert!(
            percpu_array.has_removable_lookup_pattern(),
            "PERCPU_ARRAY should remove the lookup pattern when the key is in range"
        );
        assert!(
            !percpu_array.requires_entry_presence_check(),
            "PERCPU_ARRAY should not use HASH-style null handling"
        );

        let percpu_hash = MapInfo {
            map_type: BPF_MAP_TYPE_PERCPU_HASH,
            key_size: 4,
            value_size: 8,
            max_entries: 16,
            map_id: 502,
        };
        assert!(
            !percpu_hash.supports_direct_value_access(),
            "PERCPU_HASH must not support direct value access"
        );
        assert!(
            !percpu_hash.supports_direct_value_inline(),
            "PERCPU_HASH must not be inlineable"
        );
        assert!(
            !percpu_hash.requires_entry_presence_check(),
            "PERCPU_HASH must not use HASH/LRU_HASH lookup-removal handling"
        );

        let lru_percpu_hash = MapInfo {
            map_type: BPF_MAP_TYPE_LRU_PERCPU_HASH,
            key_size: 4,
            value_size: 8,
            max_entries: 16,
            map_id: 503,
        };
        assert!(
            !lru_percpu_hash.supports_direct_value_access(),
            "LRU_PERCPU_HASH must not support direct value access"
        );
        assert!(
            !lru_percpu_hash.supports_direct_value_inline(),
            "LRU_PERCPU_HASH must not be inlineable"
        );
        assert!(
            !lru_percpu_hash.requires_entry_presence_check(),
            "LRU_PERCPU_HASH must not use HASH/LRU_HASH lookup-removal handling"
        );
    }

    #[test]
    fn map_in_map_types_are_not_direct_value_inlineable() {
        for map_type in [BPF_MAP_TYPE_ARRAY_OF_MAPS, BPF_MAP_TYPE_HASH_OF_MAPS] {
            let info = MapInfo {
                map_type,
                key_size: 4,
                value_size: 4,
                max_entries: 16,
                map_id: 700,
            };
            assert!(info.is_map_in_map());
            assert!(!info.supports_direct_value_access());
            assert!(!info.supports_direct_value_inline());
        }
    }
}
