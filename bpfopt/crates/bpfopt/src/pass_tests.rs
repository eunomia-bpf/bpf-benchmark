use super::*;
use crate::insn::*;

// ── Test helpers ────────────────────────────────────────────────

/// Construct a minimal BPF program from instructions.
fn make_program(insns: Vec<BpfInsn>) -> BpfProgram {
    BpfProgram::new(insns)
}

fn pseudo_func_ref(dst: u8, imm: i32) -> [BpfInsn; 2] {
    [
        BpfInsn::new(
            BPF_LD | BPF_DW | BPF_IMM,
            BpfInsn::make_regs(dst, BPF_PSEUDO_FUNC),
            0,
            imm,
        ),
        BpfInsn::new(0, 0, 0, 0),
    ]
}

fn pass_test_btf_record(insn_off: u32, type_id: u32) -> Vec<u8> {
    [
        insn_off.to_le_bytes(),
        type_id.to_le_bytes(),
        0u32.to_le_bytes(),
        0u32.to_le_bytes(),
    ]
    .concat()
}

fn pass_test_func_btf_record(insn_off: u32, type_id: u32) -> Vec<u8> {
    [insn_off.to_le_bytes(), type_id.to_le_bytes()].concat()
}

fn pass_test_btf_offsets(records: &BtfInfoRecords) -> Vec<u32> {
    records
        .bytes
        .chunks(records.rec_size as usize)
        .map(|record| u32::from_le_bytes(record[..4].try_into().unwrap()))
        .collect()
}

fn pass_test_btf_type_ids(records: &BtfInfoRecords) -> Vec<u32> {
    records
        .bytes
        .chunks(records.rec_size as usize)
        .map(|record| u32::from_le_bytes(record[4..8].try_into().unwrap()))
        .collect()
}

fn branch_profile(taken_count: u64, not_taken_count: u64, branch_misses: u64) -> BranchProfile {
    let branch_count = taken_count + not_taken_count;
    assert!(branch_count > 0);
    assert!(branch_misses <= branch_count);
    BranchProfile {
        branch_count,
        branch_misses,
        miss_rate: branch_misses as f64 / branch_count as f64,
        taken_count,
        not_taken_count,
    }
}

fn ctx_for_pass_manager(pm: &PassManager) -> PassContext {
    let mut ctx = PassContext::baseline();
    ctx.policy.enabled_passes = pm.pass_names().into_iter().map(str::to_string).collect();
    ctx
}

/// A no-op pass that does not change the program.
struct NoOpPass;

impl BpfPass for NoOpPass {
    fn name(&self) -> &str {
        "noop"
    }
    fn category(&self) -> PassCategory {
        PassCategory::Optimization
    }
    fn run(
        &self,
        _program: &mut BpfProgram,
        _analyses: &mut AnalysisCache,
        _ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
        Ok(PassResult {
            sites_applied: 0,
            sites_skipped: vec![],
            diagnostics: vec![],
            ..Default::default()
        })
    }
}

/// A pass that unconditionally appends a NOP instruction.
struct AppendNopPass;

impl BpfPass for AppendNopPass {
    fn name(&self) -> &str {
        "append_nop"
    }
    fn category(&self) -> PassCategory {
        PassCategory::Optimization
    }
    fn run(
        &self,
        program: &mut BpfProgram,
        _analyses: &mut AnalysisCache,
        _ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
        program.insns.push(BpfInsn::nop());
        Ok(PassResult {
            sites_applied: 1,
            sites_skipped: vec![],
            diagnostics: vec![],
            ..Default::default()
        })
    }
}

/// A pass that inserts a NOP at the beginning of the program.
struct PrependNopPass;

impl BpfPass for PrependNopPass {
    fn name(&self) -> &str {
        "prepend_nop"
    }
    fn category(&self) -> PassCategory {
        PassCategory::Optimization
    }
    fn run(
        &self,
        program: &mut BpfProgram,
        _analyses: &mut AnalysisCache,
        _ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
        let old_len = program.insns.len();
        program.insns.insert(0, BpfInsn::nop());
        let addr_map = (0..=old_len).map(|pc| pc + 1).collect::<Vec<_>>();
        program.remap_annotations(&addr_map);
        Ok(PassResult {
            sites_applied: 1,
            sites_skipped: vec![],
            diagnostics: vec![],
            ..Default::default()
        })
    }
}

/// A pass that replaces all MOV64_IMM with a different immediate value.
struct RewriteMovImmPass {
    new_imm: i32,
}

impl BpfPass for RewriteMovImmPass {
    fn name(&self) -> &str {
        "rewrite_mov_imm"
    }
    fn category(&self) -> PassCategory {
        PassCategory::Optimization
    }
    fn run(
        &self,
        program: &mut BpfProgram,
        _analyses: &mut AnalysisCache,
        _ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
        let mut applied = 0;
        for insn in &mut program.insns {
            if insn.code == (BPF_ALU64 | BPF_MOV | BPF_K) {
                insn.imm = self.new_imm;
                applied += 1;
            }
        }
        Ok(PassResult {
            sites_applied: applied,
            sites_skipped: vec![],
            diagnostics: vec![],
            ..Default::default()
        })
    }
}

#[test]
fn test_prepend_nop_pass_shifts_annotations_forward() {
    let mut pm = PassManager::new();
    pm.add_pass(PrependNopPass);

    let mut program = make_program(vec![BpfInsn::mov64_imm(0, 1), BpfInsn::exit()]);
    program.annotations[1].branch_profile = Some(branch_profile(7, 3, 1));

    let ctx = ctx_for_pass_manager(&pm);
    let _result = pm.run(&mut program, &ctx).unwrap();
    assert_eq!(program.insns.len(), 3);
    assert!(program.annotations[0].branch_profile.is_none());
    assert!(program.annotations[1].branch_profile.is_none());
    assert_eq!(
        program.annotations[2]
            .branch_profile
            .as_ref()
            .expect("prepended program should remap existing annotation")
            .taken_count,
        7
    );
}

/// A trivial analysis that counts the number of instructions.
struct InsnCountAnalysis;

impl Analysis for InsnCountAnalysis {
    type Result = usize;

    fn run(program: &BpfProgram) -> usize {
        program.insns.len()
    }
}

/// A pass that reads the InsnCountAnalysis result and stores it in diagnostics.
struct CountReportingPass;

impl BpfPass for CountReportingPass {
    fn name(&self) -> &str {
        "count_reporter"
    }
    fn category(&self) -> PassCategory {
        PassCategory::Observability
    }

    fn run(
        &self,
        _program: &mut BpfProgram,
        analyses: &mut AnalysisCache,
        _ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
        let count = analyses.get::<InsnCountAnalysis>(_program);
        Ok(PassResult {
            sites_applied: 0,
            sites_skipped: vec![],
            diagnostics: vec![format!("insn_count={}", *count)],
            ..Default::default()
        })
    }
}

struct VerifierStateCountPass;

impl BpfPass for VerifierStateCountPass {
    fn name(&self) -> &str {
        "verifier_state_count"
    }

    fn run(
        &self,
        program: &mut BpfProgram,
        _analyses: &mut AnalysisCache,
        _ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
        Ok(PassResult {
            diagnostics: vec![format!("verifier_states={}", program.verifier_states.len())],
            ..Default::default()
        })
    }
}

// ── BpfProgram tests ────────────────────────────────────────────

#[test]
fn snapshot_provider_lookup_compressed_overlays() {
    let mut program = make_program(vec![]);
    for map_id in 1..=3 {
        program.map_metadata.insert(
            map_id,
            MapMetadata {
                map_type: libbpf_sys::BPF_MAP_TYPE_ARRAY,
                key_size: 4,
                value_size: 4,
                max_entries: 8,
                map_id,
                name: format!("map_{map_id}"),
            },
        );
    }

    program.map_value_overlays.insert(
        1,
        CompressedMapValues {
            value_size: 4,
            kind: CompressedMapValuesKind::Uniform(vec![1, 0, 0, 0]),
        },
    );
    program.map_value_overlays.insert(
        2,
        CompressedMapValues {
            value_size: 4,
            kind: CompressedMapValuesKind::Sparse {
                default: vec![0, 0, 0, 0],
                entries: HashMap::from([(vec![1, 0, 0, 0], vec![7, 0, 0, 0])]),
            },
        },
    );
    program.map_value_overlays.insert(
        3,
        CompressedMapValues {
            value_size: 4,
            kind: CompressedMapValuesKind::Enumerated {
                entries: HashMap::from([(vec![2, 0, 0, 0], vec![9, 0, 0, 0])]),
            },
        },
    );

    let provider = SnapshotMapProvider;
    let uniform_info = provider
        .map_info(&program, 1)
        .unwrap()
        .expect("uniform metadata should exist");
    assert_eq!(
        provider
            .lookup_elem(&program, 1, &[99, 0, 0, 0], 4)
            .unwrap(),
        vec![1, 0, 0, 0]
    );

    let sparse_info = provider
        .map_info(&program, 2)
        .unwrap()
        .expect("sparse metadata should exist");
    assert_eq!(
        provider.lookup_value_size(&program, &sparse_info).unwrap(),
        4
    );
    assert_eq!(
        provider.lookup_elem(&program, 2, &[1, 0, 0, 0], 4).unwrap(),
        vec![7, 0, 0, 0]
    );
    assert_eq!(
        provider.lookup_elem(&program, 2, &[3, 0, 0, 0], 4).unwrap(),
        vec![0, 0, 0, 0]
    );

    let enumerated_info = provider
        .map_info(&program, 3)
        .unwrap()
        .expect("enumerated metadata should exist");
    assert_eq!(
        provider
            .lookup_elem(
                &program,
                3,
                &[2, 0, 0, 0],
                enumerated_info.value_size as usize
            )
            .unwrap(),
        vec![9, 0, 0, 0]
    );
    assert!(matches!(
        provider.lookup_elem(&program, 3, &[4, 0, 0, 0], 4),
        Err(MapLookupError::MissingKey { map_id: 3, .. })
    ));

    assert_eq!(
        provider.lookup_value_size(&program, &uniform_info).unwrap(),
        4
    );
}

#[test]
fn sync_annotations_resizes_both_directions() {
    let cases: [(&str, BpfProgram, fn(&mut BpfProgram), usize); 2] = [
        (
            "grow",
            make_program(vec![BpfInsn::exit()]),
            |prog: &mut BpfProgram| {
                prog.insns.push(BpfInsn::nop());
                prog.insns.push(BpfInsn::nop());
            },
            3,
        ),
        (
            "shrink",
            make_program(vec![BpfInsn::nop(), BpfInsn::nop(), BpfInsn::exit()]),
            |prog: &mut BpfProgram| {
                prog.insns.truncate(1);
            },
            1,
        ),
    ];

    for (label, mut prog, edit, expected_len) in cases {
        edit(&mut prog);
        prog.sync_annotations();
        assert_eq!(prog.annotations.len(), expected_len, "{label}");
    }
}

// ── KinsnRegistry tests ─────────────────────────────────────────

#[test]
fn kinsn_registry_atomic_call_setter_allows_shared_btf_id_with_zero_call_offset() {
    let mut registry = KinsnRegistry::default();

    registry
        .set_kinsn_call_for_target_name("bpf_endian_load16", 128703, 0)
        .unwrap();
    registry
        .set_kinsn_call_for_target_name("bpf_rotate64", 128703, 2)
        .unwrap();

    assert_eq!(
        registry
            .lookup_by_kinsn_call(128703, 0)
            .unwrap()
            .canonical_name,
        "bpf_endian_load16"
    );
    assert_eq!(
        registry
            .lookup_by_kinsn_call(128703, 2)
            .unwrap()
            .canonical_name,
        "bpf_rotate64"
    );
    assert_eq!(
        registry.btf_id_for_target_name("bpf_rotate64").unwrap(),
        128703
    );
    assert_eq!(
        registry.call_off_for_target_name("bpf_rotate64").unwrap(),
        2
    );
}

#[test]
fn kinsn_registry_atomic_call_setter_rejects_duplicate_call_key() {
    let mut registry = KinsnRegistry::default();

    registry
        .set_kinsn_call_for_target_name("bpf_endian_load16", 128703, 0)
        .unwrap();
    let err = registry
        .set_kinsn_call_for_target_name("bpf_rotate64", 128703, 0)
        .unwrap_err();

    assert!(
        err.to_string().contains("btf_id 128703 call_off 0"),
        "err={err}"
    );
}

#[test]
fn kinsn_registry_reports_availability_separately_from_btf_id() {
    let mut registry = KinsnRegistry::default();

    assert!(!registry.is_target_available("bpf_rotate64"));
    let err = registry.btf_id_for_target_name("bpf_rotate64").unwrap_err();
    assert!(
        err.to_string()
            .contains("kinsn target bpf_rotate64 not registered"),
        "{err:#}"
    );

    registry
        .set_kinsn_call_for_target_name("bpf_rotate64", 128703, 2)
        .unwrap();

    assert!(registry.is_target_available("bpf_rotate64"));
    assert_eq!(
        registry.btf_id_for_target_name("bpf_rotate64").unwrap(),
        128703
    );
}

#[test]
fn kinsn_replacement_subprog_check_allows_site_inside_one_subprog() {
    let insns = vec![
        BpfInsn::alu64_imm(BPF_RSH, 2, 8),
        BpfInsn::alu64_imm(BPF_AND, 2, 0xff),
        BpfInsn::pseudo_call_to(2, 4),
        BpfInsn::exit(),
        BpfInsn::mov64_imm(0, 1),
        BpfInsn::exit(),
    ];

    let skip = kinsn_replacement_subprog_skip_reason(&insns, 0, 2, 2).unwrap();

    assert_eq!(skip, None);
}

#[test]
fn kinsn_replacement_subprog_check_rejects_pseudo_func_boundary_inside_site() {
    let func_ref = pseudo_func_ref(2, -4);
    let insns = vec![
        BpfInsn::alu64_imm(BPF_RSH, 2, 8),
        BpfInsn::alu64_imm(BPF_AND, 2, 0xff),
        BpfInsn::exit(),
        BpfInsn::mov64_imm(0, 0),
        func_ref[0],
        func_ref[1],
        BpfInsn::exit(),
    ];

    let skip = kinsn_replacement_subprog_skip_reason(&insns, 0, 2, 2).unwrap();

    assert!(skip
        .as_deref()
        .is_some_and(|reason| reason.contains("subprog boundary")));
}

#[test]
fn remap_kinsn_btf_metadata_uses_proof_subprog_layout_for_func_info() {
    let memcpy_btf_id = 2000;
    let memcpy_payload = 1 | (2 << 4) | (2 << 40) | (3 << 48);
    let mut program = BpfProgram::new(vec![
        BpfInsn::kinsn_sidecar(memcpy_payload),
        BpfInsn::call_kinsn_with_off(memcpy_btf_id, 1),
        BpfInsn::new(
            BPF_JMP | BPF_CALL,
            BpfInsn::make_regs(0, BPF_PSEUDO_CALL),
            0,
            1,
        ),
        BpfInsn::exit(),
        BpfInsn::mov64_imm(0, 1),
        BpfInsn::exit(),
    ]);
    program.func_info = Some(BtfInfoRecords {
        rec_size: 8,
        bytes: [
            pass_test_func_btf_record(0, 10),
            pass_test_func_btf_record(999, 11),
        ]
        .concat(),
    });
    program.line_info = Some(BtfInfoRecords {
        rec_size: 16,
        bytes: [pass_test_btf_record(0, 100), pass_test_btf_record(999, 104)].concat(),
    });

    let mut registry = KinsnRegistry::default();
    registry
        .set_kinsn_call_for_target_name("bpf_bulk_memcpy", memcpy_btf_id, 1)
        .unwrap();

    remap_kinsn_btf_metadata(&mut program, &registry).unwrap();

    assert_eq!(
        pass_test_btf_offsets(program.func_info.as_ref().unwrap()),
        vec![0, 8]
    );
    assert_eq!(
        pass_test_btf_type_ids(program.func_info.as_ref().unwrap()),
        vec![10, 11]
    );
    assert!(program.line_info.as_ref().unwrap().bytes.is_empty());
}

#[test]
fn remap_kinsn_btf_metadata_disambiguates_duplicate_btf_ids_by_call_offset() {
    let shared_btf_id = 2000;
    let extract_payload = 2 | (16 << 8) | (12 << 16);
    let mut program = BpfProgram::new(vec![
        BpfInsn::kinsn_sidecar(extract_payload),
        BpfInsn::call_kinsn_with_off(shared_btf_id, 5),
        BpfInsn::new(
            BPF_JMP | BPF_CALL,
            BpfInsn::make_regs(0, BPF_PSEUDO_CALL),
            0,
            1,
        ),
        BpfInsn::exit(),
        BpfInsn::mov64_imm(0, 1),
        BpfInsn::exit(),
    ]);
    program.func_info = Some(BtfInfoRecords {
        rec_size: 8,
        bytes: [
            pass_test_func_btf_record(0, 10),
            pass_test_func_btf_record(999, 11),
        ]
        .concat(),
    });

    let mut registry = KinsnRegistry::default();
    registry
        .set_kinsn_call_for_target_name("bpf_rotate64", shared_btf_id, 3)
        .unwrap();
    registry
        .set_kinsn_call_for_target_name("bpf_extract64", shared_btf_id, 5)
        .unwrap();

    remap_kinsn_btf_metadata(&mut program, &registry).unwrap();

    assert_eq!(
        pass_test_btf_offsets(program.func_info.as_ref().unwrap()),
        vec![0, 4]
    );
}

#[test]
fn remap_btf_metadata_drops_deleted_entries_and_shifts_survivors() {
    let mut program = BpfProgram::new(vec![
        BpfInsn::mov64_imm(0, 0),
        BpfInsn::mov64_imm(9, 9),
        BpfInsn::mov64_imm(1, 1),
        BpfInsn::mov64_imm(2, 2),
    ]);
    program.func_info = Some(BtfInfoRecords {
        rec_size: 8,
        bytes: pass_test_func_btf_record(0, 10),
    });
    program.line_info = Some(BtfInfoRecords {
        rec_size: 16,
        bytes: [
            pass_test_btf_record(0, 100),
            pass_test_btf_record(1, 101),
            pass_test_btf_record(2, 102),
            pass_test_btf_record(3, 103),
        ]
        .concat(),
    });

    let addr_map = vec![0, 2, 2, 3, 4];

    remap_btf_metadata(&mut program, &addr_map).unwrap();

    assert_eq!(
        pass_test_btf_offsets(program.func_info.as_ref().unwrap()),
        vec![0]
    );
    assert_eq!(
        pass_test_btf_offsets(program.line_info.as_ref().unwrap()),
        vec![0, 2, 3]
    );
    assert_eq!(
        pass_test_btf_type_ids(program.line_info.as_ref().unwrap()),
        vec![100, 102, 103]
    );
}

#[test]
fn remap_btf_metadata_rejects_out_of_range_func_info() {
    let mut program = BpfProgram::new(vec![BpfInsn::mov64_imm(0, 0), BpfInsn::exit()]);
    program.func_info = Some(BtfInfoRecords {
        rec_size: 8,
        bytes: pass_test_func_btf_record(2, 10),
    });

    let err = remap_btf_metadata(&mut program, &[0, 1, 2]).unwrap_err();

    assert!(
        err.to_string()
            .contains("func_info insn_off 2 is outside old instruction length 2"),
        "{err:#}"
    );
}

// ── AnalysisCache tests ─────────────────────────────────────────

#[test]
fn test_analysis_cache_basic() {
    let mut cache = AnalysisCache::new();
    let prog = make_program(vec![BpfInsn::nop(), BpfInsn::exit()]);
    let count = cache.get::<InsnCountAnalysis>(&prog);
    assert_eq!(*count, 2);
}

// ── PassManager tests ───────────────────────────────────────────

#[test]
fn test_pass_manager_multiple_passes_sequential() {
    let mut pm = PassManager::new();
    pm.add_pass(RewriteMovImmPass { new_imm: 99 });
    pm.add_pass(AppendNopPass);

    let mut prog = make_program(vec![BpfInsn::mov64_imm(0, 42), BpfInsn::exit()]);
    let ctx = ctx_for_pass_manager(&pm);

    let result = pm.run(&mut prog, &ctx).unwrap();

    assert_eq!(result.pass_results.len(), 2);
    // First pass: rewrite_mov_imm rewrote the MOV IMM value.
    assert_eq!(result.pass_results[0].sites_applied, 1);
    // Second pass: append_nop added a NOP.
    assert_eq!(result.pass_results[1].sites_applied, 1);

    // Check the MOV IMM was rewritten.
    assert_eq!(prog.insns[0].imm, 99);
    // Check the NOP was appended.
    assert_eq!(prog.insns.len(), 3);
    assert!(prog.insns[2].is_ja() && prog.insns[2].off == 0);
}

#[test]
fn test_pass_manager_analysis_cache_invalidation() {
    // After a transform pass, the analysis cache should be invalidated.
    // A subsequent analysis read should see the updated program.
    let mut pm = PassManager::new();

    // First pass: report count (should see 2 insns)
    pm.add_pass(CountReportingPass);
    // Second pass: append a NOP (modifies program)
    pm.add_pass(AppendNopPass);
    // Third pass: report count again (should see 3 insns after invalidation)
    pm.add_pass(CountReportingPass);

    let mut prog = make_program(vec![BpfInsn::mov64_imm(0, 42), BpfInsn::exit()]);
    let ctx = ctx_for_pass_manager(&pm);

    let result = pm.run(&mut prog, &ctx).unwrap();

    assert_eq!(result.pass_results.len(), 3);
    // First count_reporter sees 2 instructions.
    assert_eq!(result.pass_results[0].diagnostics, vec!["insn_count=2"]);
    // append_nop runs.
    // Second count_reporter should see 3 instructions (cache was invalidated).
    assert_eq!(result.pass_results[2].diagnostics, vec!["insn_count=3"]);
}

#[test]
fn test_pass_manager_invalidates_verifier_states_after_transform() {
    let mut pm = PassManager::new();
    pm.add_pass(AppendNopPass);
    pm.add_pass(VerifierStateCountPass);

    let mut prog = make_program(vec![BpfInsn::mov64_imm(0, 42), BpfInsn::exit()]);
    prog.set_verifier_states(vec![VerifierInsn {
        pc: 0,
        frame: 0,
        from_pc: None,
        kind: VerifierInsnKind::InsnDeltaState,
        speculative: false,
        regs: HashMap::new(),
        stack: HashMap::new(),
    }]);
    let ctx = ctx_for_pass_manager(&pm);

    let result = pm.run(&mut prog, &ctx).unwrap();

    assert_eq!(result.pass_results.len(), 2);
    assert_eq!(
        result.pass_results[1].diagnostics,
        vec!["verifier_states=0"]
    );
}

#[test]
fn test_pass_manager_enabled_pass_policy() {
    let mut pm = PassManager::new();
    pm.add_pass(NoOpPass);
    pm.add_pass(AppendNopPass);

    let mut prog = make_program(vec![BpfInsn::exit()]);
    let mut ctx = PassContext::baseline();
    // Only enable append_nop — noop should be skipped.
    ctx.policy.enabled_passes = vec!["append_nop".into()];

    let result = pm.run(&mut prog, &ctx).unwrap();

    // Only append_nop should run.
    assert_eq!(result.pass_results.len(), 1);
    assert_eq!(result.pass_names[0], "append_nop");
    assert_eq!(prog.insns.len(), 2);
}

// ── Issue 5: Annotation remap tests ─────────────────────────

#[test]
fn test_remap_annotations_deleted_instruction() {
    let mut prog = make_program(vec![BpfInsn::nop(), BpfInsn::nop(), BpfInsn::exit()]);
    prog.annotations[0].branch_profile = Some(branch_profile(10, 5, 1));

    // Simulate a transform that removes instruction 0.
    // addr_map: old_pc 0->0 (maps to first new insn), 1->0, 2->1, sentinel 3->2
    // After rewrite, the program has 2 instructions.
    prog.insns = vec![BpfInsn::nop(), BpfInsn::exit()];
    // Both old pcs 0 and 1 map to new pc 0 — the annotation from old pc 0
    // ends up at new pc 0.
    let addr_map = vec![0, 0, 1, 2];
    prog.remap_annotations(&addr_map);

    assert!(prog.annotations[0].branch_profile.is_some());
    assert_eq!(prog.annotations.len(), 2);
}

// ── Issue 6: PGO closedloop tests ───────────────────────────

#[test]
fn test_profiling_data_injection() {
    let mut prog = make_program(vec![BpfInsn::nop(), BpfInsn::nop(), BpfInsn::exit()]);
    assert!(prog.annotations[1].branch_profile.is_none());

    let mut pdata = ProfilingData::default();
    pdata.branch_profiles.insert(1, branch_profile(80, 20, 2));
    prog.inject_profiling(&pdata);

    assert!(prog.annotations[0].branch_profile.is_none());
    assert!(prog.annotations[1].branch_profile.is_some());
    let bp = prog.annotations[1].branch_profile.as_ref().unwrap();
    assert_eq!(bp.taken_count, 80);
    assert_eq!(bp.not_taken_count, 20);
}

#[test]
fn test_invalid_policy_pass_name_is_rejected() {
    let mut pm = PassManager::new();
    pm.add_pass(AppendNopPass);

    let mut prog = make_program(vec![BpfInsn::exit()]);
    let mut ctx = ctx_for_pass_manager(&pm);
    ctx.policy.enabled_passes = vec!["bulk_mem".into()];

    let err = pm
        .run(&mut prog, &ctx)
        .expect_err("legacy aliases should be rejected");

    assert!(err.to_string().contains("invalid enabled_passes"));
    assert!(err.to_string().contains("unknown pass name(s): bulk_mem"));
}

#[test]
fn test_pass_result_insns_before_after_filled_by_pass_manager() {
    let mut pm = PassManager::new();
    pm.add_pass(AppendNopPass);

    let mut prog = make_program(vec![BpfInsn::exit()]);
    let ctx = ctx_for_pass_manager(&pm);
    let result = pm.run(&mut prog, &ctx).unwrap();

    assert_eq!(result.pass_results.len(), 1);
    let pr = &result.pass_results[0];
    // Before append_nop: 1 instruction (exit).
    assert_eq!(pr.insns_before, 1);
    // After append_nop: 2 instructions (exit + NOP).
    assert_eq!(pr.insns_after, 2);
}
