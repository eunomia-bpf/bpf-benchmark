use std::collections::{BTreeMap, HashMap};
use std::fs;
use std::path::{Path, PathBuf};

use anyhow::{Context, Result};
use serde::Serialize;

mod bpf;
mod passes;
mod profiler;

#[path = "../../../../../daemon/src/insn.rs"]
mod insn;
#[path = "../../../../../daemon/src/elf_parser.rs"]
mod elf_parser;
#[path = "../../../../../daemon/src/pass.rs"]
mod pass;
#[path = "../../../../../daemon/src/analysis/branch_target.rs"]
mod branch_target;
#[path = "../../../../../daemon/src/analysis/cfg.rs"]
mod cfg;
#[path = "../../../../../daemon/src/analysis/liveness.rs"]
mod liveness;
#[path = "../../../../../daemon/src/analysis/map_info.rs"]
mod map_info;

mod analysis {
    pub use crate::branch_target::{BranchTargetAnalysis, BranchTargetResult};
    pub use crate::cfg::{CFGAnalysis, CFGResult};
    pub use crate::liveness::{LivenessAnalysis, LivenessResult};
    pub use crate::map_info::{collect_map_references, MapInfo, MapInfoAnalysis, MapInfoResult};
}

const BPF_MAP_TYPE_HASH: u32 = 1;
const BPF_MAP_TYPE_ARRAY: u32 = 2;
const BPF_MAP_TYPE_PERCPU_HASH: u32 = 5;
const BPF_MAP_TYPE_PERCPU_ARRAY: u32 = 6;
const BPF_MAP_TYPE_LRU_HASH: u32 = 9;
const BPF_MAP_TYPE_LRU_PERCPU_HASH: u32 = 10;

const TARGET_PROJECTS: &[&str] = &[
    "katran",
    "tracee",
    "calico",
    "cilium",
    "tetragon",
    "bcc",
    "scx",
    "loxilb",
];

#[derive(Clone, Copy)]
enum SeedMode {
    Empty,
    Synthetic,
}

#[derive(Clone, Debug, Serialize, Default)]
struct ModeSummary {
    final_insn_count: usize,
    insn_delta: i64,
    program_changed: bool,
    total_sites_applied: usize,
    map_inline_sites_applied: usize,
    map_inline_sites_skipped: usize,
    const_prop_sites_applied: usize,
    dce_sites_applied: usize,
    map_inline_changed: bool,
    const_prop_changed: bool,
    dce_changed: bool,
    applied_map_type_sites: BTreeMap<String, usize>,
    map_inline_skip_reasons: BTreeMap<String, usize>,
}

#[derive(Clone, Debug, Serialize, Default)]
struct ProgramResult {
    project: String,
    object_path: String,
    section_name: String,
    symbol_name: Option<String>,
    prog_type: u32,
    orig_insn_count: usize,
    raw_map_lookup_calls: usize,
    recognized_map_lookup_sites: usize,
    lookup_map_type_sites: BTreeMap<String, usize>,
    empty_maps: ModeSummary,
    synthetic_maps: ModeSummary,
}

#[derive(Clone, Debug, Serialize, Default)]
struct ProjectSummary {
    object_count: usize,
    program_count: usize,
    programs_with_lookup: usize,
    programs_with_inline: usize,
    raw_map_lookup_calls: usize,
    recognized_map_lookup_sites: usize,
    map_inline_sites_applied: usize,
    orig_insn_count: usize,
    final_insn_count: usize,
    insn_delta: i64,
    lookup_map_type_sites: BTreeMap<String, usize>,
    applied_map_type_sites: BTreeMap<String, usize>,
    empty_map_inline_sites_applied: usize,
}

#[derive(Clone, Debug, Serialize, Default)]
struct CorpusSummary {
    object_count: usize,
    program_count: usize,
    raw_map_lookup_calls: usize,
    recognized_map_lookup_sites: usize,
    projects: BTreeMap<String, ProjectSummary>,
}

#[derive(Clone, Debug, Serialize, Default)]
struct AnalysisOutput {
    generated_at: String,
    repo_root: String,
    corpus_root: String,
    total_objects: usize,
    total_programs: usize,
    total_raw_map_lookup_calls: usize,
    total_recognized_map_lookup_sites: usize,
    target_projects: Vec<String>,
    corpus: CorpusSummary,
    target_project_subset: BTreeMap<String, ProjectSummary>,
    programs: Vec<ProgramResult>,
}

#[derive(Clone)]
struct ProgramFixture {
    program: elf_parser::ElfProgramInfo,
    map_ids: Vec<u32>,
    map_info_by_id: HashMap<u32, bpf::BpfMapInfo>,
}

fn main() -> Result<()> {
    let repo_root = repo_root()?;
    let corpus_root = repo_root.join("corpus/build");
    let output_json = repo_root.join("docs/tmp/20260326/map_inline_coverage_analysis_20260326.json");

    let mut programs = Vec::new();
    let object_paths = collect_object_paths(&corpus_root)?;

    for object_path in &object_paths {
        let object = elf_parser::parse_bpf_object(object_path)
            .with_context(|| format!("failed to parse {}", object_path.display()))?;
        for (program_index, program) in object.programs.iter().enumerate() {
            let project = derive_project(&corpus_root, object_path);
            let fixture = build_program_fixture(program, &object.maps, program_index as u32);
            let raw_map_lookup_calls = count_raw_map_lookup_calls(&program.insns);
            let lookup_map_type_sites = collect_lookup_map_type_sites(&fixture)?;
            let recognized_map_lookup_sites = lookup_map_type_sites.values().sum();
            let empty_maps = run_mode(&fixture, SeedMode::Empty)?;
            let synthetic_maps = run_mode(&fixture, SeedMode::Synthetic)?;

            programs.push(ProgramResult {
                project,
                object_path: object_path
                    .strip_prefix(&repo_root)
                    .unwrap_or(object_path)
                    .display()
                    .to_string(),
                section_name: program.section_name.clone(),
                symbol_name: program.symbol_name.clone(),
                prog_type: program.prog_type,
                orig_insn_count: program.insns.len(),
                raw_map_lookup_calls,
                recognized_map_lookup_sites,
                lookup_map_type_sites,
                empty_maps,
                synthetic_maps,
            });
        }
    }

    let output = build_output(&repo_root, &corpus_root, object_paths.len(), programs);
    let json = serde_json::to_string_pretty(&output)?;
    fs::write(&output_json, json)
        .with_context(|| format!("failed to write {}", output_json.display()))?;
    println!("{}", output_json.display());
    Ok(())
}

fn repo_root() -> Result<PathBuf> {
    let manifest_dir = PathBuf::from(env!("CARGO_MANIFEST_DIR"));
    Ok(manifest_dir
        .join("../../../..")
        .canonicalize()
        .context("failed to resolve repo root")?)
}

fn collect_object_paths(corpus_root: &Path) -> Result<Vec<PathBuf>> {
    let mut paths = Vec::new();
    for entry in walkdir(corpus_root)? {
        if entry
            .extension()
            .and_then(|ext| ext.to_str())
            .is_some_and(|ext| ext == "o")
            && entry
                .file_name()
                .and_then(|name| name.to_str())
                .is_some_and(|name| name.ends_with(".bpf.o"))
        {
            paths.push(entry);
        }
    }
    paths.sort();
    Ok(paths)
}

fn walkdir(root: &Path) -> Result<Vec<PathBuf>> {
    let mut out = Vec::new();
    let mut stack = vec![root.to_path_buf()];
    while let Some(dir) = stack.pop() {
        for entry in fs::read_dir(&dir)
            .with_context(|| format!("failed to read {}", dir.display()))?
        {
            let entry = entry?;
            let path = entry.path();
            let file_type = entry.file_type()?;
            if file_type.is_dir() {
                stack.push(path);
            } else if file_type.is_file() {
                out.push(path);
            }
        }
    }
    Ok(out)
}

fn derive_project(corpus_root: &Path, object_path: &Path) -> String {
    object_path
        .strip_prefix(corpus_root)
        .ok()
        .and_then(|rel| rel.components().next())
        .map(|c| c.as_os_str().to_string_lossy().into_owned())
        .unwrap_or_else(|| "unknown".to_string())
}

fn build_program_fixture(
    program: &elf_parser::ElfProgramInfo,
    all_maps: &[elf_parser::ElfMapMetadata],
    salt: u32,
) -> ProgramFixture {
    let mut map_ids = Vec::with_capacity(program.used_map_indices.len());
    let mut map_info_by_id = HashMap::new();
    for (used_idx, map_index) in program.used_map_indices.iter().enumerate() {
        let map = all_maps.get(*map_index).cloned().unwrap_or_else(|| elf_parser::ElfMapMetadata {
            index: *map_index,
            name: format!("missing_map_{}", map_index),
            map_type: None,
            key_size: None,
            value_size: None,
            max_entries: None,
            map_flags: None,
            numa_node: None,
            pinning: None,
            section_offset: 0,
            symbol_size: 0,
        });
        let map_id = 10_000_000 + salt * 1_000 + used_idx as u32 + 1;
        let info = bpf::BpfMapInfo {
            id: map_id,
            map_type: map.map_type.unwrap_or_default(),
            key_size: map.key_size.unwrap_or_default(),
            value_size: map.value_size.unwrap_or_default(),
            max_entries: map.max_entries.unwrap_or_default(),
            map_flags: map.map_flags.unwrap_or_default(),
        };
        map_ids.push(map_id);
        map_info_by_id.insert(map_id, info);
    }

    ProgramFixture {
        program: program.clone(),
        map_ids,
        map_info_by_id,
    }
}

fn collect_lookup_map_type_sites(fixture: &ProgramFixture) -> Result<BTreeMap<String, usize>> {
    install_maps(fixture, SeedMode::Empty)?;

    let mut program = pass::BpfProgram::new(fixture.program.insns.clone());
    program.set_map_ids(fixture.map_ids.clone());

    let refs = analysis::collect_map_references(&program.insns, &program.map_ids, |map_id| {
        let (info, frozen) = bpf::bpf_map_get_info_by_id(map_id).ok()?;
        Some(analysis::MapInfo {
            map_type: info.map_type,
            key_size: info.key_size,
            value_size: info.value_size,
            max_entries: info.max_entries,
            frozen,
            map_id: info.id,
        })
    });

    let refs_by_pc: HashMap<usize, analysis::MapInfo> = refs
        .references
        .iter()
        .filter_map(|reference| reference.info.clone().map(|info| (reference.pc, info)))
        .collect();

    let mut out = BTreeMap::new();
    for site in passes::find_map_lookup_sites(&program.insns) {
        let key = refs_by_pc
            .get(&site.map_load_pc)
            .map(|info| map_type_name(info.map_type))
            .unwrap_or_else(|| "unknown".to_string());
        *out.entry(key).or_insert(0) += 1;
    }

    bpf::clear_mock_maps();
    Ok(out)
}

fn run_mode(fixture: &ProgramFixture, mode: SeedMode) -> Result<ModeSummary> {
    install_maps(fixture, mode)?;

    let mut program = pass::BpfProgram::new(fixture.program.insns.clone());
    program.set_map_ids(fixture.map_ids.clone());

    let ctx = pass::PassContext {
        kinsn_registry: pass::KinsnRegistry::default(),
        platform: pass::PlatformCapabilities::default(),
        policy: pass::PolicyConfig::default(),
        prog_type: fixture.program.prog_type,
    };

    let mut pm = pass::PassManager::new();
    pm.register_analysis(analysis::BranchTargetAnalysis);
    pm.register_analysis(analysis::CFGAnalysis);
    pm.register_analysis(analysis::LivenessAnalysis);
    pm.register_analysis(analysis::MapInfoAnalysis);
    pm.add_pass(passes::MapInlinePass);
    pm.add_pass(passes::ConstPropPass);
    pm.add_pass(passes::DcePass);

    let pipeline = pm.run(&mut program, &ctx)?;
    let mut summary = ModeSummary {
        final_insn_count: program.insns.len(),
        insn_delta: program.insns.len() as i64 - fixture.program.insns.len() as i64,
        program_changed: pipeline.program_changed,
        total_sites_applied: pipeline.total_sites_applied,
        ..Default::default()
    };

    for result in &pipeline.pass_results {
        match result.pass_name.as_str() {
            "map_inline" => {
                summary.map_inline_sites_applied += result.sites_applied;
                summary.map_inline_sites_skipped += result.sites_skipped.len();
                summary.map_inline_changed |= result.changed;
                for skip in &result.sites_skipped {
                    *summary
                        .map_inline_skip_reasons
                        .entry(skip.reason.clone())
                        .or_insert(0) += 1;
                }
                for record in &result.map_inline_records {
                    if let Some(info) = fixture.map_info_by_id.get(&record.map_id) {
                        *summary
                            .applied_map_type_sites
                            .entry(map_type_name(info.map_type))
                            .or_insert(0) += 1;
                    }
                }
            }
            "const_prop" => {
                summary.const_prop_sites_applied += result.sites_applied;
                summary.const_prop_changed |= result.changed;
            }
            "dce" => {
                summary.dce_sites_applied += result.sites_applied;
                summary.dce_changed |= result.changed;
            }
            _ => {}
        }
    }

    bpf::clear_mock_maps();
    Ok(summary)
}

fn install_maps(fixture: &ProgramFixture, mode: SeedMode) -> Result<()> {
    bpf::clear_mock_maps();
    for (map_id, info) in &fixture.map_info_by_id {
        let values = match mode {
            SeedMode::Empty => HashMap::new(),
            SeedMode::Synthetic => synthetic_map_values(info),
        };
        bpf::install_mock_map(
            *map_id,
            bpf::MockMapState {
                info: info.clone(),
                frozen: false,
                values,
            },
        );
    }
    Ok(())
}

fn synthetic_map_values(info: &bpf::BpfMapInfo) -> HashMap<Vec<u8>, Vec<u8>> {
    let mut values = HashMap::new();
    if info.key_size == 0 || info.value_size == 0 {
        return values;
    }

    let seed_entries = match info.map_type {
        BPF_MAP_TYPE_ARRAY => info.max_entries.min(32),
        BPF_MAP_TYPE_HASH | BPF_MAP_TYPE_LRU_HASH => 32,
        _ => 0,
    };

    for key in 0..seed_entries {
        values.insert(
            synthetic_key_bytes(key as u64, info.key_size as usize),
            synthetic_value_bytes((info.id as u64) + 7, info.value_size as usize),
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

fn count_raw_map_lookup_calls(insns: &[insn::BpfInsn]) -> usize {
    let mut count = 0usize;
    let mut pc = 0usize;
    while pc < insns.len() {
        let insn = insns[pc];
        if insn.is_call() && insn.src_reg() == 0 && insn.imm == 1 {
            count += 1;
        }
        pc += if insn.is_ldimm64() { 2 } else { 1 };
    }
    count
}

fn build_output(
    repo_root: &Path,
    corpus_root: &Path,
    total_objects: usize,
    programs: Vec<ProgramResult>,
) -> AnalysisOutput {
    let mut corpus = CorpusSummary {
        object_count: total_objects,
        program_count: programs.len(),
        ..Default::default()
    };

    let mut project_objects: BTreeMap<String, BTreeMap<String, ()>> = BTreeMap::new();

    for program in &programs {
        corpus.raw_map_lookup_calls += program.raw_map_lookup_calls;
        corpus.recognized_map_lookup_sites += program.recognized_map_lookup_sites;

        let project = corpus.projects.entry(program.project.clone()).or_default();
        project.program_count += 1;
        project.raw_map_lookup_calls += program.raw_map_lookup_calls;
        project.recognized_map_lookup_sites += program.recognized_map_lookup_sites;
        project.map_inline_sites_applied += program.synthetic_maps.map_inline_sites_applied;
        project.orig_insn_count += program.orig_insn_count;
        project.final_insn_count += program.synthetic_maps.final_insn_count;
        project.insn_delta += program.synthetic_maps.insn_delta;
        project.empty_map_inline_sites_applied += program.empty_maps.map_inline_sites_applied;
        if program.recognized_map_lookup_sites > 0 {
            project.programs_with_lookup += 1;
        }
        if program.synthetic_maps.map_inline_sites_applied > 0 {
            project.programs_with_inline += 1;
        }
        merge_counts(&mut project.lookup_map_type_sites, &program.lookup_map_type_sites);
        merge_counts(
            &mut project.applied_map_type_sites,
            &program.synthetic_maps.applied_map_type_sites,
        );
        project_objects
            .entry(program.project.clone())
            .or_default()
            .insert(program.object_path.clone(), ());
    }

    for (project_name, objects) in project_objects {
        if let Some(project) = corpus.projects.get_mut(&project_name) {
            project.object_count = objects.len();
        }
    }

    let mut target_project_subset = BTreeMap::new();
    for project in TARGET_PROJECTS {
        target_project_subset.insert(
            (*project).to_string(),
            corpus.projects.get(*project).cloned().unwrap_or_default(),
        );
    }

    AnalysisOutput {
        generated_at: chrono_like_now(),
        repo_root: repo_root.display().to_string(),
        corpus_root: corpus_root.display().to_string(),
        total_objects,
        total_programs: programs.len(),
        total_raw_map_lookup_calls: corpus.raw_map_lookup_calls,
        total_recognized_map_lookup_sites: corpus.recognized_map_lookup_sites,
        target_projects: TARGET_PROJECTS.iter().map(|s| (*s).to_string()).collect(),
        corpus,
        target_project_subset,
        programs,
    }
}

fn merge_counts(dst: &mut BTreeMap<String, usize>, src: &BTreeMap<String, usize>) {
    for (key, value) in src {
        *dst.entry(key.clone()).or_insert(0) += value;
    }
}

fn map_type_name(map_type: u32) -> String {
    match map_type {
        BPF_MAP_TYPE_HASH => "HASH".to_string(),
        BPF_MAP_TYPE_ARRAY => "ARRAY".to_string(),
        BPF_MAP_TYPE_PERCPU_HASH => "PERCPU_HASH".to_string(),
        BPF_MAP_TYPE_PERCPU_ARRAY => "PERCPU_ARRAY".to_string(),
        BPF_MAP_TYPE_LRU_HASH => "LRU_HASH".to_string(),
        BPF_MAP_TYPE_LRU_PERCPU_HASH => "LRU_PERCPU_HASH".to_string(),
        3 => "PROG_ARRAY".to_string(),
        4 => "PERF_EVENT_ARRAY".to_string(),
        7 => "STACK_TRACE".to_string(),
        8 => "CGROUP_ARRAY".to_string(),
        11 => "LPM_TRIE".to_string(),
        12 => "ARRAY_OF_MAPS".to_string(),
        13 => "HASH_OF_MAPS".to_string(),
        14 => "DEVMAP".to_string(),
        15 => "SOCKMAP".to_string(),
        16 => "CPUMAP".to_string(),
        17 => "XSKMAP".to_string(),
        18 => "SOCKHASH".to_string(),
        19 => "CGROUP_STORAGE".to_string(),
        20 => "REUSEPORT_SOCKARRAY".to_string(),
        21 => "PERCPU_CGROUP_STORAGE".to_string(),
        22 => "QUEUE".to_string(),
        23 => "STACK".to_string(),
        24 => "SK_STORAGE".to_string(),
        25 => "DEVMAP_HASH".to_string(),
        26 => "STRUCT_OPS".to_string(),
        27 => "RINGBUF".to_string(),
        28 => "INODE_STORAGE".to_string(),
        29 => "TASK_STORAGE".to_string(),
        30 => "BLOOM_FILTER".to_string(),
        31 => "USER_RINGBUF".to_string(),
        other => format!("MAP_TYPE_{}", other),
    }
}

fn chrono_like_now() -> String {
    use std::time::{SystemTime, UNIX_EPOCH};

    match SystemTime::now().duration_since(UNIX_EPOCH) {
        Ok(duration) => format!("unix:{}", duration.as_secs()),
        Err(_) => "unix:0".to_string(),
    }
}
