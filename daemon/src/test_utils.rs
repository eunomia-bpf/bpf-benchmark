// SPDX-License-Identifier: MIT
//! Shared helpers for real `.bpf.o` unit tests.

use std::collections::HashMap;
use std::path::PathBuf;
use std::sync::atomic::{AtomicU32, Ordering};

use anyhow::{anyhow, Context, Result};

use crate::bpf::{install_mock_map, BpfMapInfo, MockMapState};
use crate::elf_parser::{parse_bpf_object, ElfBpfObject, ElfMapMetadata, ElfProgramInfo};
use crate::insn::{BpfInsn, BPF_PSEUDO_CALL};
use crate::pass::{BpfProgram, BranchProfile, PassContext, PipelineResult, ProfilingData};
use crate::passes::build_custom_pipeline;

const BPF_MAP_TYPE_HASH: u32 = 1;
const BPF_MAP_TYPE_ARRAY: u32 = 2;
const BPF_MAP_TYPE_LRU_HASH: u32 = 9;

static NEXT_TEST_MAP_ID: AtomicU32 = AtomicU32::new(10_000);

#[derive(Clone, Debug)]
pub struct LoadedFixtureProgram {
    pub object_path: PathBuf,
    pub section_name: String,
    pub symbol_name: Option<String>,
    pub prog_type: u32,
    pub insns: Vec<BpfInsn>,
    pub used_maps: Vec<ElfMapMetadata>,
}

impl LoadedFixtureProgram {
    pub fn into_program(&self) -> BpfProgram {
        BpfProgram::new(self.insns.clone())
    }

    pub fn into_program_with_synthetic_maps(&self) -> BpfProgram {
        let mut program = self.into_program();
        if self.used_maps.is_empty() {
            return program;
        }

        let mut map_ids = Vec::with_capacity(self.used_maps.len());
        for map in &self.used_maps {
            let map_id = NEXT_TEST_MAP_ID.fetch_add(1, Ordering::Relaxed);
            install_mock_map(
                map_id,
                MockMapState {
                    info: synthetic_map_info(map, map_id),
                    frozen: true,
                    values: synthetic_map_values(map),
                },
            );
            map_ids.push(map_id);
        }
        program.set_map_ids(map_ids);
        program
    }
}

pub fn fixture_path(rel_path: &str) -> PathBuf {
    PathBuf::from(env!("CARGO_MANIFEST_DIR"))
        .join("tests")
        .join("fixtures")
        .join(rel_path)
}

pub fn load_fixture_object(rel_path: &str) -> Result<ElfBpfObject> {
    let path = fixture_path(rel_path);
    parse_bpf_object(&path).with_context(|| format!("failed to load fixture {}", path.display()))
}

pub fn load_fixture_program(rel_path: &str, name: &str) -> Result<LoadedFixtureProgram> {
    let object = load_fixture_object(rel_path)?;
    let program = object
        .program_named(name)
        .or_else(|| object.program_named(&format!("{name}/")))
        .with_context(|| format!("fixture {} has no unique program named {}", rel_path, name))?;
    Ok(materialize_program_fixture(&object, program))
}

fn materialize_program_fixture(
    object: &ElfBpfObject,
    program: &ElfProgramInfo,
) -> LoadedFixtureProgram {
    let used_maps = program
        .used_map_indices
        .iter()
        .filter_map(|index| object.maps.get(*index).cloned())
        .collect::<Vec<_>>();

    LoadedFixtureProgram {
        object_path: object.path.clone(),
        section_name: program.section_name.clone(),
        symbol_name: program.symbol_name.clone(),
        prog_type: program.prog_type,
        insns: program.insns.clone(),
        used_maps,
    }
}

pub fn permissive_pass_ctx(prog_type: u32) -> PassContext {
    let mut ctx = PassContext::test_default();
    ctx.prog_type = prog_type;
    ctx.kinsn_registry.rotate64_btf_id = 1001;
    ctx.kinsn_registry.select64_btf_id = 1002;
    ctx.kinsn_registry.extract64_btf_id = 1003;
    ctx.kinsn_registry.memcpy_bulk_btf_id = 1004;
    ctx.kinsn_registry.memset_bulk_btf_id = 1005;
    ctx.kinsn_registry.endian_load16_btf_id = 1006;
    ctx.kinsn_registry.endian_load32_btf_id = 1007;
    ctx.kinsn_registry.endian_load64_btf_id = 1008;
    ctx.kinsn_registry.speculation_barrier_btf_id = 1009;
    ctx.platform.has_bmi1 = true;
    ctx.platform.has_bmi2 = true;
    ctx.platform.has_cmov = true;
    ctx.platform.has_movbe = true;
    ctx.platform.has_rorx = true;
    ctx
}

pub fn run_named_pipeline(
    program: &mut BpfProgram,
    ctx: &PassContext,
    pass_names: &[&str],
) -> Result<PipelineResult> {
    let pass_names = pass_names
        .iter()
        .map(|name| (*name).to_string())
        .collect::<Vec<_>>();
    let pipeline = build_custom_pipeline(&pass_names)?;
    pipeline.run(program, ctx)
}

pub fn run_named_pipeline_with_profiling(
    program: &mut BpfProgram,
    ctx: &PassContext,
    pass_names: &[&str],
    profiling: Option<&ProfilingData>,
) -> Result<PipelineResult> {
    let pass_names = pass_names
        .iter()
        .map(|name| (*name).to_string())
        .collect::<Vec<_>>();
    let pipeline = build_custom_pipeline(&pass_names)?;
    pipeline.run_with_profiling(program, ctx, profiling)
}

pub fn hot_branch_profiling(insns: &[BpfInsn]) -> ProfilingData {
    let mut profiling = ProfilingData {
        branch_miss_rate: Some(0.01),
        ..Default::default()
    };

    let mut pc = 0usize;
    while pc < insns.len() {
        let insn = insns[pc];
        if insn.is_cond_jmp() {
            profiling.branch_profiles.insert(
                pc,
                BranchProfile {
                    taken_count: 90,
                    not_taken_count: 10,
                },
            );
        }
        pc += if insn.is_ldimm64() { 2 } else { 1 };
    }

    profiling
}

pub fn assert_valid_bpf(program: &BpfProgram) {
    assert!(!program.insns.is_empty(), "program must not be empty");

    let mut ldimm64_continuations = HashMap::new();
    let mut pc = 0usize;
    while pc < program.insns.len() {
        let insn = program.insns[pc];
        if insn.is_ldimm64() {
            assert!(
                pc + 1 < program.insns.len(),
                "LD_IMM64 at pc {} is truncated",
                pc
            );
            ldimm64_continuations.insert(pc + 1, pc);
            pc += 2;
            continue;
        }

        pc += 1;
    }

    assert!(
        program.insns.iter().any(BpfInsn::is_exit),
        "program must contain at least one EXIT"
    );

    let mut pc = 0usize;
    while pc < program.insns.len() {
        let insn = program.insns[pc];
        if insn.is_jmp_class() && !insn.is_call() && !insn.is_exit() {
            let target = pc as i64 + 1 + insn.off as i64;
            assert!(
                (0..program.insns.len() as i64).contains(&target),
                "branch at pc {} targets out of bounds pc {}",
                pc,
                target
            );
            assert!(
                !ldimm64_continuations.contains_key(&(target as usize)),
                "branch at pc {} targets LD_IMM64 continuation pc {}",
                pc,
                target
            );
        }

        if insn.is_call() && insn.src_reg() == BPF_PSEUDO_CALL {
            let target = pc as i64 + 1 + insn.imm as i64;
            assert!(
                (0..program.insns.len() as i64).contains(&target),
                "pseudo call at pc {} targets out of bounds pc {}",
                pc,
                target
            );
            assert!(
                !ldimm64_continuations.contains_key(&(target as usize)),
                "pseudo call at pc {} targets LD_IMM64 continuation pc {}",
                pc,
                target
            );
        }

        pc += if insn.is_ldimm64() { 2 } else { 1 };
    }
}

pub fn pass_result<'a>(
    pipeline: &'a PipelineResult,
    pass_name: &str,
) -> Result<&'a crate::pass::PassResult> {
    pipeline
        .pass_results
        .iter()
        .find(|result| result.pass_name == pass_name)
        .ok_or_else(|| anyhow!("missing pass result for {}", pass_name))
}

fn synthetic_map_info(map: &ElfMapMetadata, map_id: u32) -> BpfMapInfo {
    let mut info = BpfMapInfo::default();
    info.id = map_id;
    info.map_type = map.map_type.unwrap_or_default();
    info.key_size = map.key_size.unwrap_or_default();
    info.value_size = map.value_size.unwrap_or_default();
    info.max_entries = map.max_entries.unwrap_or_default();
    info.map_flags = map.map_flags.unwrap_or_default();
    info
}

fn synthetic_map_values(map: &ElfMapMetadata) -> HashMap<Vec<u8>, Vec<u8>> {
    let mut values = HashMap::new();

    let Some(map_type) = map.map_type else {
        return values;
    };
    let Some(key_size) = map.key_size else {
        return values;
    };
    let Some(value_size) = map.value_size else {
        return values;
    };
    if key_size == 0 || value_size == 0 {
        return values;
    }

    let max_seed = match map_type {
        BPF_MAP_TYPE_ARRAY => map.max_entries.unwrap_or(0).min(32),
        BPF_MAP_TYPE_HASH | BPF_MAP_TYPE_LRU_HASH => 32,
        _ => 0,
    };
    if max_seed == 0 {
        return values;
    }

    for key in 0..max_seed {
        values.insert(
            synthetic_key_bytes(key as u64, key_size as usize),
            synthetic_value_bytes(map.index as u64 + 7, value_size as usize),
        );
    }

    values
}

fn synthetic_key_bytes(value: u64, key_size: usize) -> Vec<u8> {
    let mut key = vec![0u8; key_size];
    let raw = value.to_le_bytes();
    let copy_len = key_size.min(raw.len());
    key[..copy_len].copy_from_slice(&raw[..copy_len]);
    key
}

fn synthetic_value_bytes(seed: u64, value_size: usize) -> Vec<u8> {
    let mut value = vec![0u8; value_size];
    let raw = seed.to_le_bytes();
    let copy_len = value_size.min(raw.len());
    value[..copy_len].copy_from_slice(&raw[..copy_len]);
    if value_size > copy_len {
        for byte in &mut value[copy_len..] {
            *byte = (seed as u8).wrapping_add(1);
        }
    }
    value
}
