// SPDX-License-Identifier: MIT

use std::collections::{HashMap, HashSet};
use std::sync::Arc;

use crate::analysis::{lift_with_kinsn_registry, lower, BBProgram};
use crate::insn::{BpfInsn, MapPseudo};
use crate::pass::{
    BpfPass, CompressedMapValues, InsnAnnotation, MapInlineHint, MapLookupError, MapMetadata,
    PassContext, PassResult, RegState, ScalarRange, StackState, Tnum, VerifierInsn,
    VerifierInsnKind, VerifierValueWidth,
};
use crate::passes::MapInfo;

#[derive(Clone)]
pub struct BpfProgram {
    pub insns: Vec<BpfInsn>,
    pub map_ids: Vec<u32>,
    pub map_fd_bindings: HashMap<i32, u32>,
    pub verifier_states: Arc<[VerifierInsn]>,
    pub map_values: HashMap<(u32, Vec<u8>), Vec<u8>>,
    pub map_value_overlays: HashMap<u32, CompressedMapValues>,
    pub map_inner_map_ids: HashMap<(u32, Vec<u8>), u32>,
    pub map_snapshots_skipped_by_size: HashSet<u32>,
    pub map_inline_hints: Vec<MapInlineHint>,
    pub map_metadata: HashMap<u32, MapMetadata>,
    pub map_provider: Arc<dyn MapProvider>,
}

pub trait MapProvider: Send + Sync + std::fmt::Debug {
    fn map_info(
        &self,
        program: &BpfProgram,
        map_id: u32,
    ) -> std::result::Result<Option<MapInfo>, String>;

    fn lookup_value_size(
        &self,
        program: &BpfProgram,
        info: &MapInfo,
    ) -> std::result::Result<usize, String>;

    fn lookup_elem(
        &self,
        program: &BpfProgram,
        map_id: u32,
        key: &[u8],
        value_size: usize,
    ) -> std::result::Result<Vec<u8>, MapLookupError>;
}

#[derive(Clone, Debug, Default)]
pub struct SnapshotMapProvider;

impl MapProvider for SnapshotMapProvider {
    fn map_info(
        &self,
        program: &BpfProgram,
        map_id: u32,
    ) -> std::result::Result<Option<MapInfo>, String> {
        let Some(metadata) = program.map_metadata.get(&map_id) else {
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
    }

    fn lookup_value_size(
        &self,
        program: &BpfProgram,
        info: &MapInfo,
    ) -> std::result::Result<usize, String> {
        if let Some(overlay) = program.map_value_overlays.get(&info.map_id) {
            return Ok(overlay.value_size);
        }
        if let Some(value_size) = program
            .map_values
            .iter()
            .find_map(|((map_id, _), value)| (*map_id == info.map_id).then_some(value.len()))
        {
            return Ok(value_size);
        }

        Ok(info.value_size as usize)
    }

    fn lookup_elem(
        &self,
        program: &BpfProgram,
        map_id: u32,
        key: &[u8],
        value_size: usize,
    ) -> std::result::Result<Vec<u8>, MapLookupError> {
        if let Some(overlay) = program.map_value_overlays.get(&map_id) {
            return match overlay.lookup(key) {
                Some(value) => {
                    if value.len() != value_size {
                        Err(MapLookupError::Failed(format!(
                            "compressed map {} returned value size {}, expected {}",
                            map_id,
                            value.len(),
                            value_size
                        )))
                    } else {
                        Ok(value)
                    }
                }
                None => Err(MapLookupError::MissingKey {
                    map_id,
                    key: key.to_vec(),
                }),
            };
        }
        if program.map_snapshots_skipped_by_size.contains(&map_id) {
            return Err(MapLookupError::SkippedBySize { map_id });
        }
        if let Some(value) = program.map_values.get(&(map_id, key.to_vec())) {
            if value.len() != value_size {
                return Err(MapLookupError::Failed(format!(
                    "snapshot map {} returned value size {}, expected {}",
                    map_id,
                    value.len(),
                    value_size
                )));
            }
            return Ok(value.clone());
        }

        if !program.map_metadata.contains_key(&map_id) {
            return Err(MapLookupError::Failed(format!(
                "map_values snapshot has no metadata for map {}",
                map_id
            )));
        }
        Err(MapLookupError::MissingKey {
            map_id,
            key: key.to_vec(),
        })
    }
}

impl BpfProgram {
    pub fn new(insns: Vec<BpfInsn>) -> Self {
        Self {
            insns,
            map_ids: Vec::new(),
            map_fd_bindings: HashMap::new(),
            verifier_states: Arc::from([]),
            map_values: HashMap::new(),
            map_value_overlays: HashMap::new(),
            map_inner_map_ids: HashMap::new(),
            map_snapshots_skipped_by_size: HashSet::new(),
            map_inline_hints: Vec::new(),
            map_metadata: HashMap::new(),
            map_provider: Arc::new(SnapshotMapProvider),
        }
    }

    pub fn set_map_ids(&mut self, map_ids: Vec<u32>) {
        self.map_fd_bindings = build_map_fd_bindings(&self.insns, &map_ids);
        self.map_ids = map_ids;
    }
}

pub fn build_map_fd_bindings(insns: &[BpfInsn], map_ids: &[u32]) -> HashMap<i32, u32> {
    let mut old_fd_to_map_id = HashMap::new();
    let mut unique_old_fds = Vec::new();

    let mut pc = 0usize;
    while pc < insns.len() {
        let insn = insns[pc];
        if insn.is_ldimm64() {
            if insn.map_pseudo().is_some_and(MapPseudo::uses_fd)
                && !unique_old_fds.contains(&insn.imm)
            {
                unique_old_fds.push(insn.imm);
            }
            pc += 2;
            continue;
        }
        pc += 1;
    }

    for (index, old_fd) in unique_old_fds.into_iter().enumerate() {
        if let Some(&map_id) = map_ids.get(index) {
            old_fd_to_map_id.insert(old_fd, map_id);
        }
    }

    old_fd_to_map_id
}

pub struct PassRun {
    pub result: PassResult,
    pub lowered: Vec<BpfInsn>,
    pub prog: BBProgram,
}

pub fn lift_test_program(insns: &[BpfInsn], ctx: &PassContext) -> BBProgram {
    let oracle = (!ctx.verifier_states.is_empty()).then(|| Arc::clone(&ctx.verifier_states));
    let mut prog = lift_with_kinsn_registry(insns, oracle, Arc::new(ctx.kinsn_registry.clone()))
        .expect("test bytecode should lift into BBProgram");
    prog.attach_side_inputs(
        insns,
        ctx.map_ids.clone(),
        ctx.func_info.clone(),
        ctx.line_info.clone(),
    )
    .expect("test side inputs should attach to BBProgram");
    prog
}

pub fn lower_test_program(prog: &BBProgram) -> Vec<BpfInsn> {
    lower(prog).expect("test BBProgram should lower")
}

pub fn run_pass_on_insns<P: BpfPass>(pass: P, insns: Vec<BpfInsn>, ctx: &PassContext) -> PassRun {
    let mut prog = lift_test_program(&insns, ctx);
    // Test helpers run passes through the production BBProgram API.
    let result = pass
        .run(&mut prog, ctx)
        .expect("future BBProgram-native pass should run");
    let lowered = lower_test_program(&prog);
    PassRun {
        result,
        lowered,
        prog,
    }
}

pub fn pass_error_on_insns<P: BpfPass>(pass: P, insns: Vec<BpfInsn>, ctx: &PassContext) -> String {
    let mut prog = lift_test_program(&insns, ctx);
    // Test helpers run passes through the production BBProgram API.
    pass.run(&mut prog, ctx)
        .expect_err("future BBProgram-native pass should reject this fixture")
        .to_string()
}

pub fn run_pipeline_on_insns(
    passes: Vec<Box<dyn BpfPass>>,
    insns: Vec<BpfInsn>,
    ctx: &PassContext,
) -> (Vec<PassResult>, Vec<BpfInsn>, BBProgram) {
    let mut prog = lift_test_program(&insns, ctx);
    let mut results = Vec::new();
    for pass in passes {
        // Test helpers run passes through the production BBProgram API.
        results.push(
            pass.run(&mut prog, ctx)
                .expect("future BBProgram-native pipeline pass should run"),
        );
    }
    let lowered = lower_test_program(&prog);
    (results, lowered, prog)
}

pub fn pass_ctx() -> PassContext {
    PassContext::baseline()
}

pub fn ctx_with_kinsn(target: &str, btf_id: i32) -> PassContext {
    let mut ctx = pass_ctx();
    ctx.kinsn_registry
        .set_kinsn_call_for_target_name(target, btf_id, 0)
        .expect("test kinsn target should register");
    ctx
}

pub fn ctx_with_verifier_states(states: Vec<VerifierInsn>) -> PassContext {
    let mut ctx = pass_ctx();
    // Raw daemon verifier states stay on PassContext and are consumed once at lift.
    ctx.verifier_states = Arc::from(states);
    ctx
}

pub fn ctx_with_annotations(annotations: Vec<InsnAnnotation>) -> PassContext {
    let mut ctx = pass_ctx();
    // PassContext carries per-PC annotations for profile-guided passes.
    ctx.annotations = annotations;
    ctx
}

pub fn set_branch_miss_rate(ctx: &mut PassContext, miss_rate: f64) {
    // BranchFlip program-level PMU side input lives on PassContext.
    ctx.branch_miss_rate = Some(miss_rate);
}

pub fn add_inner_map(ctx: &mut PassContext, outer_map_id: u32, key: Vec<u8>, inner_map_id: u32) {
    // Map-in-map side inputs live on PassContext.
    ctx.map_inner_map_ids
        .insert((outer_map_id, key), inner_map_id);
}

pub fn skip_map_snapshot(ctx: &mut PassContext, map_id: u32) {
    // Skipped snapshot markers live on PassContext.
    ctx.map_snapshots_skipped_by_size.insert(map_id);
}

pub fn set_map_ids(ctx: &mut PassContext, map_ids: Vec<u32>) {
    // Canonical map-id binding side input lives on PassContext.
    ctx.map_ids = map_ids;
}

pub fn set_map_inline_hints(ctx: &mut PassContext, hints: Vec<MapInlineHint>) {
    // map_inline hints live on PassContext.
    ctx.map_inline_hints = hints;
}

pub fn set_btf_records(
    ctx: &mut PassContext,
    func_info: Option<crate::pass::BtfInfoRecords>,
    line_info: Option<crate::pass::BtfInfoRecords>,
) {
    // BTF metadata side inputs live on PassContext.
    ctx.func_info = func_info;
    ctx.line_info = line_info;
}

pub fn scalar_reg(value: u64) -> RegState {
    scalar_reg_with_width(value, VerifierValueWidth::Bits64)
}

pub fn scalar32_reg(value: u64) -> RegState {
    scalar_reg_with_width(value, VerifierValueWidth::Bits32)
}

pub fn scalar_reg_with_width(value: u64, value_width: VerifierValueWidth) -> RegState {
    let mut reg = RegState::new("scalar", value_width);
    reg.precise = true;
    reg.exact_value = Some(value);
    reg.tnum = Some(Tnum { value, mask: 0 });
    reg.range = ScalarRange {
        smin: Some(value as i64),
        smax: Some(value as i64),
        umin: Some(value),
        umax: Some(value),
        smin32: Some(value as u32 as i32),
        smax32: Some(value as u32 as i32),
        umin32: Some(value as u32),
        umax32: Some(value as u32),
    };
    reg
}

pub fn fp_reg(offset: i32) -> RegState {
    let mut reg = RegState::new("fp", VerifierValueWidth::Bits64);
    reg.offset = Some(offset);
    reg
}

pub fn pkt_reg() -> RegState {
    RegState::new("pkt", VerifierValueWidth::Bits64)
}

pub fn verifier_delta_state(pc: usize, regs: HashMap<u8, RegState>) -> VerifierInsn {
    verifier_delta_state_with_stack(pc, regs, HashMap::new())
}

pub fn verifier_delta_state_with_stack(
    pc: usize,
    regs: HashMap<u8, RegState>,
    stack: HashMap<i16, StackState>,
) -> VerifierInsn {
    verifier_state(pc, 0, VerifierInsnKind::InsnDeltaState, regs, stack)
}

pub fn verifier_delta_state_in_frame(
    pc: usize,
    frame: usize,
    regs: HashMap<u8, RegState>,
) -> VerifierInsn {
    verifier_state(
        pc,
        frame,
        VerifierInsnKind::InsnDeltaState,
        regs,
        HashMap::new(),
    )
}

pub fn verifier_full_state(pc: usize, regs: HashMap<u8, RegState>) -> VerifierInsn {
    verifier_state(pc, 0, VerifierInsnKind::PcFullState, regs, HashMap::new())
}

pub fn verifier_edge_state(pc: usize, regs: HashMap<u8, RegState>) -> VerifierInsn {
    verifier_state(pc, 0, VerifierInsnKind::EdgeFullState, regs, HashMap::new())
}

pub fn verifier_state(
    pc: usize,
    frame: usize,
    kind: VerifierInsnKind,
    regs: HashMap<u8, RegState>,
    stack: HashMap<i16, StackState>,
) -> VerifierInsn {
    VerifierInsn {
        pc,
        frame,
        from_pc: None,
        kind,
        speculative: false,
        regs,
        stack,
    }
}

pub fn stack_snapshot_from_key(stack_off: i16, key: &[u8]) -> HashMap<i16, StackState> {
    let mut slots = HashMap::<i16, ([u8; 8], [u8; 8])>::new();
    for (idx, byte) in key.iter().enumerate() {
        let absolute_off = i32::from(stack_off) + idx as i32;
        let slot_index = ((-absolute_off - 1) / 8) + 1;
        let slot_start_i32 = -slot_index * 8;
        let slot_start = i16::try_from(slot_start_i32).expect("stack slot start fits i16");
        let byte_index =
            usize::try_from(absolute_off - slot_start_i32).expect("byte index fits usize");
        let type_index = 7 - byte_index;
        let entry = slots.entry(slot_start).or_insert(([0u8; 8], [b'?'; 8]));
        entry.0[byte_index] = *byte;
        entry.1[type_index] = b'r';
    }

    slots
        .into_iter()
        .map(|(off, (bytes, types))| {
            (
                off,
                StackState {
                    slot_types: Some(String::from_utf8(types.to_vec()).expect("slot types utf8")),
                    value: Some(scalar_reg(u64::from_le_bytes(bytes))),
                },
            )
        })
        .collect()
}

pub fn map_metadata(map_id: u32, map_type: u32, key_size: u32, value_size: u32) -> MapMetadata {
    MapMetadata {
        map_type,
        key_size,
        value_size,
        max_entries: 8,
        map_id,
        name: format!("map_{map_id}"),
    }
}

pub fn branch_profile(taken: u64, not_taken: u64, miss_rate: f64) -> crate::pass::BranchProfile {
    crate::pass::BranchProfile {
        branch_count: taken + not_taken,
        branch_misses: ((taken + not_taken) as f64 * miss_rate) as u64,
        miss_rate,
        taken_count: taken,
        not_taken_count: not_taken,
    }
}

pub fn prefetch_profile(execution_count: u64, miss_rate: f64) -> crate::pass::PrefetchProfile {
    crate::pass::PrefetchProfile {
        execution_count,
        cache_references: execution_count,
        cache_misses: (execution_count as f64 * miss_rate) as u64,
        miss_rate,
    }
}

pub fn assert_skip_reason(result: &PassResult, pc: usize, reason: &str) {
    assert!(
        result
            .sites_skipped
            .iter()
            .any(|skip| skip.pc == pc && skip.reason.contains(reason)),
        "missing skip pc={pc} reason containing {reason:?}; got {:?}",
        result.sites_skipped
    );
}

pub fn assert_diagnostic(result: &PassResult, needle: &str) {
    assert!(
        result.diagnostics.iter().any(|diag| diag.contains(needle)),
        "missing diagnostic containing {needle:?}; got {:?}",
        result.diagnostics
    );
}
