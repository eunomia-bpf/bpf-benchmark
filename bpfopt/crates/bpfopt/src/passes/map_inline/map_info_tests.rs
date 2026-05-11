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
    assert!(result.unique_maps[0].supports_direct_value_access());
    assert!(result.unique_maps[1].supports_direct_value_access());
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
    assert!(result.unique_maps[0].supports_direct_value_access());
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

    let result = collect_map_references(&insns, &[101], |map_id| Ok(Some(array_map(map_id, 4))))
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
            !info.supports_direct_value_access(),
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
        percpu_array.supports_direct_value_access(),
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
        !percpu_hash.supports_direct_value_access(),
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
        !lru_percpu_hash.supports_direct_value_access(),
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
        assert!(!info.supports_direct_value_access());
    }
}
