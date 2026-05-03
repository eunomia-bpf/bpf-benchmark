// SPDX-License-Identifier: MIT
// Map metadata analysis for map inlining.

use std::collections::HashMap;

use crate::insn::BpfInsn;
use crate::pass::{Analysis, BpfProgram};

const BPF_MAP_TYPE_HASH: u32 = kernel_sys::BPF_MAP_TYPE_HASH;
const BPF_MAP_TYPE_ARRAY: u32 = kernel_sys::BPF_MAP_TYPE_ARRAY;
#[cfg(test)]
const BPF_MAP_TYPE_PERCPU_HASH: u32 = kernel_sys::BPF_MAP_TYPE_PERCPU_HASH;
const BPF_MAP_TYPE_PERCPU_ARRAY: u32 = kernel_sys::BPF_MAP_TYPE_PERCPU_ARRAY;
const BPF_MAP_TYPE_LRU_HASH: u32 = kernel_sys::BPF_MAP_TYPE_LRU_HASH;
#[cfg(test)]
const BPF_MAP_TYPE_LRU_PERCPU_HASH: u32 = kernel_sys::BPF_MAP_TYPE_LRU_PERCPU_HASH;
const BPF_PSEUDO_MAP_FD: u8 = kernel_sys::BPF_PSEUDO_MAP_FD as u8;
const BPF_PSEUDO_MAP_IDX: u8 = kernel_sys::BPF_PSEUDO_MAP_IDX as u8;

/// Runtime metadata for a live kernel map referenced by the program.
#[derive(Clone, Debug, PartialEq, Eq)]
pub struct MapInfo {
    pub map_type: u32,
    pub key_size: u32,
    pub value_size: u32,
    pub max_entries: u32,
    pub frozen: bool,
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

    /// Returns whether map_inline can eliminate the lookup/null-check sequence.
    pub fn has_removable_lookup_pattern(&self) -> bool {
        matches!(
            self.map_type,
            BPF_MAP_TYPE_ARRAY | BPF_MAP_TYPE_PERCPU_ARRAY
        )
    }

    /// Returns whether this inline is speculative and depends on runtime stability.
    pub fn has_speculative_invalidation(&self) -> bool {
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

impl Analysis for MapInfoAnalysis {
    type Result = MapInfoAnalysisResult<MapInfoResult>;

    fn name(&self) -> &str {
        "map_info"
    }

    fn run(&self, program: &BpfProgram) -> MapInfoAnalysisResult<MapInfoResult> {
        let provider = program.map_provider.clone();
        collect_map_references_with_bindings(
            &program.insns,
            &program.map_ids,
            &program.map_fd_bindings,
            move |map_id| provider.map_info(program, map_id),
        )
    }
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
pub fn collect_map_references_with_bindings<F>(
    insns: &[BpfInsn],
    map_ids: &[u32],
    map_fd_bindings: &HashMap<i32, u32>,
    mut resolver: F,
) -> MapInfoAnalysisResult<MapInfoResult>
where
    F: FnMut(u32) -> MapInfoAnalysisResult<Option<MapInfo>>,
{
    let mut references = Vec::new();
    let mut old_fd_to_index: HashMap<i32, usize> = HashMap::new();
    let mut unique_old_fds = Vec::new();
    let mut resolved_by_index: HashMap<usize, Option<MapInfo>> = HashMap::new();

    let mut pc = 0usize;
    while pc < insns.len() {
        let insn = &insns[pc];
        if insn.is_ldimm64() && pc + 1 < insns.len() && is_map_reference_src(insn.src_reg()) {
            let map_index = if insn.src_reg() == BPF_PSEUDO_MAP_IDX {
                usize::try_from(insn.imm)
                    .map_err(|_| format!("negative pseudo-map index {} at pc {}", insn.imm, pc))?
            } else {
                let old_fd = insn.imm;
                match old_fd_to_index.get(&old_fd) {
                    Some(&index) => index,
                    None => {
                        let index = unique_old_fds.len();
                        unique_old_fds.push(old_fd);
                        old_fd_to_index.insert(old_fd, index);
                        index
                    }
                }
            };
            let map_id = if insn.src_reg() == BPF_PSEUDO_MAP_IDX {
                Some(*map_ids.get(map_index).ok_or_else(|| {
                    format!(
                        "pseudo-map index {} at pc {} out of range for {} map ids",
                        map_index,
                        pc,
                        map_ids.len()
                    )
                })?)
            } else {
                map_fd_bindings
                    .get(&insn.imm)
                    .copied()
                    .or_else(|| map_ids.get(map_index).copied())
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
                pc,
                dst_reg: insn.dst_reg(),
                imm: insn.imm,
                map_index,
                map_id,
                info,
            });

            pc += 2;
            continue;
        }

        pc += if insn.is_ldimm64() { 2 } else { 1 };
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

fn is_map_reference_src(src_reg: u8) -> bool {
    src_reg == BPF_PSEUDO_MAP_FD || src_reg == BPF_PSEUDO_MAP_IDX
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::insn::{BpfInsn, BPF_DW, BPF_IMM, BPF_LD};
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
            frozen: true,
            map_id,
        }
    }

    fn hash_map(map_id: u32) -> MapInfo {
        MapInfo {
            map_type: BPF_MAP_TYPE_HASH,
            key_size: 4,
            value_size: 8,
            max_entries: 16,
            frozen: true,
            map_id,
        }
    }

    fn lru_hash_map(map_id: u32) -> MapInfo {
        MapInfo {
            map_type: BPF_MAP_TYPE_LRU_HASH,
            key_size: 4,
            value_size: 8,
            max_entries: 16,
            frozen: true,
            map_id,
        }
    }

    #[test]
    fn mutable_maps_are_still_inlineable_when_direct_access_is_supported() {
        let array = MapInfo {
            frozen: false,
            ..array_map(101, 4)
        };
        let hash = MapInfo {
            frozen: false,
            ..hash_map(202)
        };

        assert!(array.supports_direct_value_inline());
        assert!(hash.supports_direct_value_inline());
        assert!(hash.has_speculative_invalidation());
    }

    #[test]
    fn collect_map_references_tracks_unique_fd_order() {
        let ld0 = make_ld_imm64(1, BPF_PSEUDO_MAP_FD, 10);
        let ld1 = make_ld_imm64(2, BPF_PSEUDO_MAP_FD, 11);
        let ld2 = make_ld_imm64(3, BPF_PSEUDO_MAP_FD, 10);
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
        assert!(result.unique_maps[1].has_speculative_invalidation());
    }

    #[test]
    fn map_info_marks_lru_hash_as_speculative_inlineable() {
        let ld = make_ld_imm64(1, BPF_PSEUDO_MAP_FD, 10);
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
        assert!(result.unique_maps[0].has_speculative_invalidation());
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
        let ld0 = make_ld_imm64(1, BPF_PSEUDO_MAP_FD, 10);
        let ld1 = make_ld_imm64(2, BPF_PSEUDO_MAP_FD, 11);
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
        let ld = make_ld_imm64(1, BPF_PSEUDO_MAP_FD, 10);
        let program = BpfProgram::new(vec![ld[0], ld[1]]);
        let result = MapInfoAnalysis
            .run(&program)
            .expect("map info analysis should succeed");

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
            ) -> MapInfoAnalysisResult<Vec<u8>> {
                unreachable!("map_info analysis only resolves metadata")
            }
        }

        let ld = make_ld_imm64(1, BPF_PSEUDO_MAP_FD, 10);
        let mut program = BpfProgram::new(vec![ld[0], ld[1]]);
        program.map_provider = std::sync::Arc::new(ErrorMapProvider);
        program.set_map_ids(vec![999_999]);

        let err = MapInfoAnalysis
            .run(&program)
            .expect_err("missing live map metadata should propagate");

        assert!(err.contains("resolve live map info for map 999999"));
    }

    #[test]
    fn map_info_analysis_preserves_old_fd_binding_after_leading_map_is_deleted() {
        let ld0 = make_ld_imm64(1, BPF_PSEUDO_MAP_FD, 10);
        let ld1 = make_ld_imm64(2, BPF_PSEUDO_MAP_FD, 11);
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
        let ld0 = make_ld_imm64(1, BPF_PSEUDO_MAP_IDX, 1);
        let ld1 = make_ld_imm64(2, BPF_PSEUDO_MAP_IDX, 0);
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
        const BPF_MAP_TYPE_PROG_ARRAY: u32 = kernel_sys::BPF_MAP_TYPE_PROG_ARRAY;
        const BPF_MAP_TYPE_PERF_EVENT_ARRAY: u32 = kernel_sys::BPF_MAP_TYPE_PERF_EVENT_ARRAY;
        const BPF_MAP_TYPE_STACK_TRACE: u32 = kernel_sys::BPF_MAP_TYPE_STACK_TRACE;
        const BPF_MAP_TYPE_CGROUP_STORAGE: u32 = kernel_sys::BPF_MAP_TYPE_CGROUP_STORAGE;
        const BPF_MAP_TYPE_RINGBUF: u32 = kernel_sys::BPF_MAP_TYPE_RINGBUF;

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
                frozen: true,
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
            frozen: true,
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
            !percpu_array.has_speculative_invalidation(),
            "PERCPU_ARRAY should not use HASH-style speculative null handling"
        );

        let percpu_hash = MapInfo {
            map_type: BPF_MAP_TYPE_PERCPU_HASH,
            key_size: 4,
            value_size: 8,
            max_entries: 16,
            frozen: true,
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
            !percpu_hash.has_speculative_invalidation(),
            "PERCPU_HASH must not be speculative (not inlineable at all)"
        );

        let lru_percpu_hash = MapInfo {
            map_type: BPF_MAP_TYPE_LRU_PERCPU_HASH,
            key_size: 4,
            value_size: 8,
            max_entries: 16,
            frozen: true,
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
            !lru_percpu_hash.has_speculative_invalidation(),
            "LRU_PERCPU_HASH must not be speculative (not inlineable at all)"
        );
    }
}
