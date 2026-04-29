// SPDX-License-Identifier: MIT
//! bpfopt CLI entry point.

use std::collections::HashMap;
use std::fs;
use std::io::{self, Read, Write};
use std::path::{Path, PathBuf};
use std::process::ExitCode;
use std::sync::Arc;

use anyhow::{anyhow, bail, Context, Result};
use bpfopt::analysis::{BranchTargetAnalysis, CFGAnalysis, LivenessAnalysis, MapInfoAnalysis};
use bpfopt::insn::{
    bpf_op, BpfInsn, BPF_CALL, BPF_DW, BPF_EXIT, BPF_IMM, BPF_JA, BPF_LD, BPF_PSEUDO_KINSN_CALL,
    BPF_PSEUDO_MAP_FD,
};
use bpfopt::pass::{
    Analysis, BpfProgram, BranchProfile, KinsnRegistry, MapMetadata, PassContext, PassManager,
    PassResult, PlatformCapabilities, ProfilingData, RegState, ScalarRange, StackState,
    StaticKinsnCallResolver, Tnum, VerifierInsn, VerifierInsnKind, VerifierValueWidth,
};
use bpfopt::passes::PASS_REGISTRY;
use clap::{Args, Parser, Subcommand};
use serde::{Deserialize, Serialize};

const ALL_PASS_ORDER: &[&str] = &[
    "map_inline",
    "const_prop",
    "dce",
    "skb_load_bytes_spec",
    "bounds_check_merge",
    "wide_mem",
    "bulk_memory",
    "rotate",
    "cond_select",
    "extract",
    "endian_fusion",
    "branch_flip",
];

const DEFAULT_OPTIMIZE_PASS_ORDER: &[&str] = ALL_PASS_ORDER;

const PASS_ALIASES: &[(&str, &str)] = &[
    ("wide-mem", "wide_mem"),
    ("wide_mem", "wide_mem"),
    ("rotate", "rotate"),
    ("const-prop", "const_prop"),
    ("const_prop", "const_prop"),
    ("cond-select", "cond_select"),
    ("cond_select", "cond_select"),
    ("extract", "extract"),
    ("endian", "endian_fusion"),
    ("endian-fusion", "endian_fusion"),
    ("endian_fusion", "endian_fusion"),
    ("branch-flip", "branch_flip"),
    ("branch_flip", "branch_flip"),
    ("dce", "dce"),
    ("map-inline", "map_inline"),
    ("map_inline", "map_inline"),
    ("bulk-memory", "bulk_memory"),
    ("bulk_memory", "bulk_memory"),
    ("bounds-check-merge", "bounds_check_merge"),
    ("bounds_check_merge", "bounds_check_merge"),
    ("skb-load-bytes", "skb_load_bytes_spec"),
    ("skb_load_bytes", "skb_load_bytes_spec"),
    ("skb-load-bytes-spec", "skb_load_bytes_spec"),
    ("skb_load_bytes_spec", "skb_load_bytes_spec"),
];

const KINSN_ALIASES: &[(&str, &str)] = &[
    ("bpf_rotate64", "bpf_rotate64"),
    ("rotate64", "bpf_rotate64"),
    ("bpf_select64", "bpf_select64"),
    ("select64", "bpf_select64"),
    ("bpf_extract64", "bpf_extract64"),
    ("extract64", "bpf_extract64"),
    ("bpf_memcpy_bulk", "bpf_memcpy_bulk"),
    ("bpf_bulk_memcpy", "bpf_memcpy_bulk"),
    ("memcpy_bulk", "bpf_memcpy_bulk"),
    ("bulk_memcpy", "bpf_memcpy_bulk"),
    ("bpf_memset_bulk", "bpf_memset_bulk"),
    ("bpf_bulk_memset", "bpf_memset_bulk"),
    ("memset_bulk", "bpf_memset_bulk"),
    ("bulk_memset", "bpf_memset_bulk"),
    ("bpf_endian_load16", "bpf_endian_load16"),
    ("endian_load16", "bpf_endian_load16"),
    ("bpf_endian_load32", "bpf_endian_load32"),
    ("endian_load32", "bpf_endian_load32"),
    ("bpf_endian_load64", "bpf_endian_load64"),
    ("endian_load64", "bpf_endian_load64"),
];

#[derive(Parser)]
#[command(name = "bpfopt", version, about = "BPF bytecode optimizer")]
struct Cli {
    #[command(flatten)]
    common: CommonArgs,
    #[command(subcommand)]
    command: Command,
}

#[derive(Args, Clone, Debug, Default)]
struct CommonArgs {
    /// Input bytecode file. Defaults to stdin.
    #[arg(long, global = true, value_name = "FILE")]
    input: Option<PathBuf>,
    /// Output bytecode or JSON file. Defaults to stdout.
    #[arg(long, global = true, value_name = "FILE")]
    output: Option<PathBuf>,
    /// Pass report JSON output file.
    #[arg(long, global = true, value_name = "FILE")]
    report: Option<PathBuf>,
    /// Target architecture: x86_64 or aarch64.
    #[arg(long, global = true, value_name = "ARCH")]
    platform: Option<String>,
    /// Available kinsns, comma-separated. Entries may be name or name:btf_id.
    #[arg(long, global = true, value_name = "LIST", value_delimiter = ',')]
    kinsns: Vec<String>,
    /// Target platform JSON file.
    #[arg(long, global = true, value_name = "FILE")]
    target: Option<PathBuf>,
    /// PGO profile JSON file.
    #[arg(long, global = true, value_name = "FILE")]
    profile: Option<PathBuf>,
    /// Verifier states JSON file.
    #[arg(long, global = true, value_name = "FILE")]
    verifier_states: Option<PathBuf>,
    /// Map values JSON file.
    #[arg(long, global = true, value_name = "FILE")]
    map_values: Option<PathBuf>,
    /// Map IDs used by the program, comma-separated in kernel used_maps order.
    #[arg(long, global = true, value_name = "LIST", value_delimiter = ',')]
    map_ids: Vec<String>,
}

#[derive(Subcommand)]
enum Command {
    /// Fuse byte-by-byte loads into wider memory accesses.
    #[command(name = "wide-mem")]
    WideMem,
    /// Replace shift+or patterns with rotate kinsn calls.
    Rotate,
    /// Fold register constants.
    #[command(name = "const-prop")]
    ConstProp,
    /// Replace branch-over-mov with conditional select kinsn calls.
    #[command(name = "cond-select")]
    CondSelect,
    /// Replace shift+mask with bit-field extract kinsn calls.
    Extract,
    /// Fuse endian load+swap sequences.
    Endian,
    /// Reorder if/else bodies using PGO profile data.
    #[command(name = "branch-flip")]
    BranchFlip,
    /// Remove unreachable blocks, NOPs, and dead register definitions.
    Dce,
    /// Inline stable map lookup values.
    #[command(name = "map-inline")]
    MapInline,
    /// Lower large memcpy/memset runs into bulk-memory kinsn calls.
    #[command(name = "bulk-memory")]
    BulkMemory,
    /// Merge packet bounds-check ladders.
    #[command(name = "bounds-check-merge")]
    BoundsCheckMerge,
    /// Specialize skb_load_bytes helper sites.
    #[command(name = "skb-load-bytes")]
    SkbLoadBytes,
    /// Run a pass pipeline in-process.
    Optimize(OptimizeArgs),
    /// Emit a JSON analysis summary.
    Analyze,
    /// List available optimization passes.
    #[command(name = "list-passes")]
    ListPasses(ListPassesArgs),
}

#[derive(Args)]
struct OptimizeArgs {
    /// Comma-separated pass list. Defaults to the v3 12-pass order.
    #[arg(long, value_name = "LIST", value_delimiter = ',')]
    passes: Vec<String>,
}

#[derive(Args)]
struct ListPassesArgs {
    /// Emit machine-readable pass metadata.
    #[arg(long)]
    json: bool,
}

#[derive(Clone, Debug, Serialize)]
struct PassReport {
    pass: String,
    skipped: bool,
    #[serde(skip_serializing_if = "Option::is_none")]
    reason: Option<String>,
    changed: bool,
    sites_applied: usize,
    insn_count_before: usize,
    insn_count_after: usize,
    insn_delta: isize,
}

#[derive(Clone, Debug, Serialize)]
struct OptimizeReport {
    passes: Vec<PassReport>,
}

#[derive(Clone, Debug, Serialize)]
struct ListPassEntry {
    name: &'static str,
    canonical_name: &'static str,
    description: &'static str,
}

#[derive(Clone, Debug, Serialize)]
struct AnalyzeReport {
    insn_count: usize,
    subprog_count: usize,
    map_lookups: Vec<MapLookupReport>,
    kinsn_calls: Vec<KinsnCallReport>,
    ld_imm64_count: usize,
    branch_count: usize,
}

struct OptimizePassPlan {
    pass_name: &'static str,
    skip_reason: Option<String>,
}

#[derive(Clone, Debug, Serialize)]
struct MapLookupReport {
    pc: usize,
    map_load_pc: Option<usize>,
    map_id: Option<u32>,
    old_fd: Option<i32>,
}

#[derive(Clone, Debug, Serialize)]
struct KinsnCallReport {
    pc: usize,
    btf_func_id: i32,
    call_offset: i16,
}

#[derive(Debug, Deserialize)]
struct TargetJson {
    arch: Option<String>,
    #[serde(default)]
    features: Vec<String>,
    #[serde(default)]
    kinsns: HashMap<String, KinsnJson>,
}

#[derive(Debug, Deserialize)]
struct KinsnJson {
    btf_func_id: i32,
    #[serde(default, alias = "call_off")]
    call_offset: Option<i16>,
    #[serde(default)]
    supported_encodings: Option<SupportedEncodingsJson>,
}

#[derive(Debug, Deserialize)]
#[serde(untagged)]
enum SupportedEncodingsJson {
    Bits(u32),
    Names(Vec<String>),
}

#[derive(Debug, Deserialize)]
struct ProfileJson {
    #[serde(default)]
    branch_miss_rate: Option<f64>,
    #[serde(default)]
    per_insn: HashMap<String, ProfileInsnJson>,
}

#[derive(Debug, Deserialize)]
struct ProfileInsnJson {
    taken: u64,
    not_taken: u64,
}

#[derive(Debug, Deserialize)]
struct VerifierStatesJson {
    #[serde(default)]
    insns: Vec<VerifierInsnJson>,
}

#[derive(Debug, Deserialize)]
struct VerifierInsnJson {
    pc: usize,
    #[serde(default)]
    frame: usize,
    #[serde(default)]
    regs: HashMap<String, VerifierRegJson>,
}

#[derive(Debug, Deserialize)]
struct VerifierRegJson {
    #[serde(rename = "type", default = "default_reg_type")]
    reg_type: String,
    #[serde(default)]
    const_val: Option<i64>,
    #[serde(default)]
    min: Option<i64>,
    #[serde(default)]
    max: Option<i64>,
    #[serde(default)]
    tnum: Option<String>,
}

#[derive(Debug, Deserialize)]
struct MapValuesJson {
    #[serde(default)]
    maps: Vec<MapSnapshotJson>,
}

#[derive(Debug, Deserialize)]
struct MapSnapshotJson {
    map_id: u32,
    map_type: MapTypeJson,
    key_size: u32,
    value_size: u32,
    max_entries: u32,
    #[serde(default = "default_frozen")]
    frozen: bool,
    #[serde(default)]
    entries: Vec<MapEntryJson>,
}

#[derive(Debug, Deserialize)]
struct MapEntryJson {
    key: String,
    value: Option<String>,
}

#[derive(Debug, Deserialize)]
#[serde(untagged)]
enum MapTypeJson {
    Number(u32),
    Name(String),
}

fn main() -> ExitCode {
    let result = std::panic::catch_unwind(run_main);
    match result {
        Ok(Ok(())) => ExitCode::SUCCESS,
        Ok(Err(err)) => {
            eprintln!("error: {err:#}");
            ExitCode::from(1)
        }
        Err(_) => {
            eprintln!("error: internal bpfopt panic");
            ExitCode::from(1)
        }
    }
}

fn run_main() -> Result<()> {
    let cli = Cli::parse();

    match cli.command {
        Command::ListPasses(args) => list_passes(&cli.common, args.json),
        Command::Analyze => run_analyze(&cli.common),
        Command::Optimize(args) => run_optimize(&cli.common, &args),
        command => run_single_pass(&cli.common, command.canonical_pass_name().unwrap()),
    }
}

impl Command {
    fn canonical_pass_name(&self) -> Option<&'static str> {
        match self {
            Command::WideMem => Some("wide_mem"),
            Command::Rotate => Some("rotate"),
            Command::ConstProp => Some("const_prop"),
            Command::CondSelect => Some("cond_select"),
            Command::Extract => Some("extract"),
            Command::Endian => Some("endian_fusion"),
            Command::BranchFlip => Some("branch_flip"),
            Command::Dce => Some("dce"),
            Command::MapInline => Some("map_inline"),
            Command::BulkMemory => Some("bulk_memory"),
            Command::BoundsCheckMerge => Some("bounds_check_merge"),
            Command::SkbLoadBytes => Some("skb_load_bytes_spec"),
            Command::Optimize(_) | Command::Analyze | Command::ListPasses(_) => None,
        }
    }
}

fn list_passes(common: &CommonArgs, json: bool) -> Result<()> {
    if json {
        let entries = ALL_PASS_ORDER
            .iter()
            .map(|&name| {
                let entry = registry_entry(name)?;
                Ok(ListPassEntry {
                    name: cli_name_for_pass(name),
                    canonical_name: name,
                    description: entry.description,
                })
            })
            .collect::<Result<Vec<_>>>()?;
        write_json(common.output.as_deref(), &entries)
    } else {
        let mut out = open_text_output(common.output.as_deref())?;
        for &name in ALL_PASS_ORDER {
            writeln!(out, "{}", cli_name_for_pass(name))?;
        }
        Ok(())
    }
}

fn run_analyze(common: &CommonArgs) -> Result<()> {
    let insns = read_bytecode(common.input.as_deref())?;
    let mut program = BpfProgram::new(insns);
    attach_program_inputs(&mut program, common)?;

    let cfg = CFGAnalysis.run(&program);
    let branch_targets = BranchTargetAnalysis.run(&program);
    let _liveness = LivenessAnalysis.run(&program);
    let map_info = MapInfoAnalysis
        .run(&program)
        .map_err(|err| anyhow!("map_info analysis failed: {err}"))?;

    let report = AnalyzeReport {
        insn_count: program.insns.len(),
        subprog_count: cfg.subprogs.len(),
        map_lookups: collect_map_lookups(&program, &map_info.references),
        kinsn_calls: collect_kinsn_calls(&program),
        ld_imm64_count: count_ldimm64(&program),
        branch_count: count_branches(&program, branch_targets.is_target.len()),
    };
    write_json(common.output.as_deref(), &report)
}

fn run_single_pass(common: &CommonArgs, pass_name: &'static str) -> Result<()> {
    validate_required_side_inputs(common, &[pass_name])?;

    let mut program = BpfProgram::new(read_bytecode(common.input.as_deref())?);
    attach_program_inputs(&mut program, common)?;
    let mut ctx = build_pass_context(common)?;
    validate_required_kinsns(&ctx, &[pass_name])?;
    ctx.policy.enabled_passes = vec![pass_name.to_string()];
    let pipeline = build_pipeline(&[pass_name])?;
    let profiling = read_profile(common.profile.as_deref())?;
    let result = run_pipeline_catching_panics(&pipeline, &mut program, &ctx, profiling.as_ref())?;
    write_bytecode(common.output.as_deref(), &program.insns)?;

    if let Some(report_path) = common.report.as_deref() {
        let report = result
            .pass_results
            .first()
            .map(pass_report)
            .unwrap_or_else(|| unchanged_report(pass_name, program.insns.len()));
        write_json(Some(report_path), &report)?;
    }

    Ok(())
}

fn run_optimize(common: &CommonArgs, args: &OptimizeArgs) -> Result<()> {
    let pass_names = if args.passes.is_empty() {
        DEFAULT_OPTIMIZE_PASS_ORDER.to_vec()
    } else {
        args.passes
            .iter()
            .map(|name| canonicalize_pass_name(name))
            .collect::<Result<Vec<_>>>()?
    };

    let mut program = BpfProgram::new(read_bytecode(common.input.as_deref())?);
    attach_program_inputs(&mut program, common)?;
    let mut ctx = build_pass_context(common)?;
    let plan = optimize_pass_plan(common, &ctx, &pass_names);
    for planned in plan.iter().filter(|planned| planned.skip_reason.is_some()) {
        eprintln!(
            "warning: skipping {}: {}",
            cli_name_for_pass(planned.pass_name),
            planned.skip_reason.as_deref().unwrap()
        );
    }

    let runnable_passes = plan
        .iter()
        .filter_map(|planned| planned.skip_reason.is_none().then_some(planned.pass_name))
        .collect::<Vec<_>>();
    ctx.policy.enabled_passes = runnable_passes
        .iter()
        .map(|name| (*name).to_string())
        .collect();
    let pipeline = build_pipeline(&runnable_passes)?;
    let profiling = read_profile(common.profile.as_deref())?;
    let result = run_pipeline_catching_panics(&pipeline, &mut program, &ctx, profiling.as_ref())?;
    write_bytecode(common.output.as_deref(), &program.insns)?;

    if let Some(report_path) = common.report.as_deref() {
        let report = OptimizeReport {
            passes: optimize_reports(&plan, &result.pass_results, &program),
        };
        write_json(Some(report_path), &report)?;
    }

    Ok(())
}

fn optimize_pass_plan(
    common: &CommonArgs,
    ctx: &PassContext,
    pass_names: &[&'static str],
) -> Vec<OptimizePassPlan> {
    pass_names
        .iter()
        .map(|&pass_name| OptimizePassPlan {
            pass_name,
            skip_reason: optimize_skip_reason(common, ctx, pass_name),
        })
        .collect()
}

fn optimize_skip_reason(
    common: &CommonArgs,
    ctx: &PassContext,
    pass_name: &'static str,
) -> Option<String> {
    match pass_name {
        "rotate" => missing_kinsn_reason(common, ctx, &["bpf_rotate64"]),
        "cond_select" => missing_kinsn_reason(common, ctx, &["bpf_select64"]),
        "extract" => missing_kinsn_reason(common, ctx, &["bpf_extract64"]),
        "endian_fusion" => {
            if has_any_kinsn(
                ctx,
                &[
                    "bpf_endian_load16",
                    "bpf_endian_load32",
                    "bpf_endian_load64",
                ],
            ) {
                None
            } else {
                missing_kinsn_reason(
                    common,
                    ctx,
                    &[
                        "bpf_endian_load16",
                        "bpf_endian_load32",
                        "bpf_endian_load64",
                    ],
                )
            }
        }
        "bulk_memory" => missing_kinsn_reason(common, ctx, &["bpf_memcpy_bulk", "bpf_memset_bulk"]),
        "branch_flip" => common
            .profile
            .is_none()
            .then(|| "missing --profile".to_string()),
        "const_prop" => common
            .verifier_states
            .is_none()
            .then(|| "missing --verifier-states".to_string()),
        "map_inline" => {
            let missing_map_values = common.map_values.is_none();
            let missing_map_ids = common.map_ids.is_empty();
            match (missing_map_values, missing_map_ids) {
                (true, true) => Some("missing --map-values and --map-ids".to_string()),
                (true, false) => Some("missing --map-values".to_string()),
                (false, true) => Some("missing --map-ids".to_string()),
                (false, false) => None,
            }
        }
        _ => None,
    }
}

fn has_any_kinsn(ctx: &PassContext, target_names: &[&str]) -> bool {
    target_names
        .iter()
        .any(|target_name| ctx.kinsn_registry.btf_id_for_target_name(target_name) >= 0)
}

fn missing_kinsn_reason(
    common: &CommonArgs,
    ctx: &PassContext,
    target_names: &[&str],
) -> Option<String> {
    let mut missing = Vec::new();
    for target_name in target_names {
        if ctx.kinsn_registry.btf_id_for_target_name(target_name) >= 0 {
            continue;
        }
        let public_name = public_kinsn_name(target_name);
        if !missing.contains(&public_name) {
            missing.push(public_name);
        }
    }
    if missing.is_empty() {
        return None;
    }

    if common.target.is_none() && common.kinsns.is_empty() {
        Some("missing --target kinsns".to_string())
    } else {
        Some(format!("missing --target kinsns: {}", missing.join(", ")))
    }
}

fn public_kinsn_name(target_name: &str) -> &str {
    match target_name {
        "bpf_memcpy_bulk" => "bpf_bulk_memcpy",
        "bpf_memset_bulk" => "bpf_bulk_memset",
        "bpf_endian_load16" | "bpf_endian_load32" | "bpf_endian_load64" => "bpf_endian_load64",
        _ => target_name,
    }
}

fn run_pipeline_catching_panics(
    pipeline: &PassManager,
    program: &mut BpfProgram,
    ctx: &PassContext,
    profiling: Option<&ProfilingData>,
) -> Result<bpfopt::pass::PipelineResult> {
    std::panic::catch_unwind(std::panic::AssertUnwindSafe(|| {
        pipeline.run_with_profiling(program, ctx, profiling)
    }))
    .map_err(|_| anyhow!("internal pass panic"))?
}

fn build_pipeline(pass_names: &[&str]) -> Result<PassManager> {
    let mut pm = PassManager::new();
    pm.register_analysis(BranchTargetAnalysis);
    pm.register_analysis(CFGAnalysis);
    pm.register_analysis(LivenessAnalysis);
    pm.register_analysis(MapInfoAnalysis);

    for &name in pass_names {
        let entry = registry_entry(name)?;
        pm.add_pass_boxed((entry.make)());
    }
    Ok(pm)
}

fn registry_entry(name: &str) -> Result<&'static bpfopt::passes::PassRegistryEntry> {
    PASS_REGISTRY
        .iter()
        .find(|entry| entry.name == name)
        .ok_or_else(|| anyhow!("unknown pass name: {name}"))
}

fn canonicalize_pass_name(input: &str) -> Result<&'static str> {
    let normalized = input.trim();
    PASS_ALIASES
        .iter()
        .find_map(|(alias, canonical)| (*alias == normalized).then_some(*canonical))
        .ok_or_else(|| anyhow!("unknown pass name: {input}"))
}

fn cli_name_for_pass(canonical: &str) -> &'static str {
    match canonical {
        "wide_mem" => "wide-mem",
        "rotate" => "rotate",
        "const_prop" => "const-prop",
        "cond_select" => "cond-select",
        "extract" => "extract",
        "endian_fusion" => "endian",
        "branch_flip" => "branch-flip",
        "dce" => "dce",
        "map_inline" => "map-inline",
        "bulk_memory" => "bulk-memory",
        "bounds_check_merge" => "bounds-check-merge",
        "skb_load_bytes_spec" => "skb-load-bytes",
        _ => "unknown",
    }
}

fn validate_required_side_inputs(common: &CommonArgs, pass_names: &[&str]) -> Result<()> {
    for &pass_name in pass_names {
        match pass_name {
            "rotate" | "cond_select" | "extract" | "endian_fusion" | "bulk_memory" => {
                if common.target.is_none() && common.kinsns.is_empty() {
                    bail!(
                        "{} requires --target or --kinsns",
                        cli_name_for_pass(pass_name)
                    );
                }
            }
            "branch_flip" => {
                if common.profile.is_none() {
                    bail!("branch-flip requires --profile");
                }
            }
            "const_prop" => {
                if common.verifier_states.is_none() {
                    bail!("const-prop requires --verifier-states");
                }
            }
            "map_inline" => {
                if common.map_values.is_none() || common.map_ids.is_empty() {
                    bail!("map-inline requires --map-values and --map-ids");
                }
            }
            _ => {}
        }
    }
    Ok(())
}

fn validate_required_kinsns(ctx: &PassContext, pass_names: &[&str]) -> Result<()> {
    for &pass_name in pass_names {
        match pass_name {
            "rotate" => require_kinsn(ctx, "bpf_rotate64")?,
            "cond_select" => require_kinsn(ctx, "bpf_select64")?,
            "extract" => require_kinsn(ctx, "bpf_extract64")?,
            "endian_fusion" => require_any_kinsn(
                ctx,
                &[
                    "bpf_endian_load16",
                    "bpf_endian_load32",
                    "bpf_endian_load64",
                ],
                "endian",
            )?,
            "bulk_memory" => {
                require_kinsn(ctx, "bpf_memcpy_bulk")?;
                require_kinsn(ctx, "bpf_memset_bulk")?;
            }
            _ => {}
        }
    }
    Ok(())
}

fn require_kinsn(ctx: &PassContext, target_name: &str) -> Result<()> {
    if ctx.kinsn_registry.btf_id_for_target_name(target_name) < 0 {
        bail!("kinsn '{}' not in target", public_kinsn_name(target_name));
    }
    Ok(())
}

fn require_any_kinsn(ctx: &PassContext, target_names: &[&str], pass_label: &str) -> Result<()> {
    if target_names
        .iter()
        .any(|target_name| ctx.kinsn_registry.btf_id_for_target_name(target_name) >= 0)
    {
        return Ok(());
    }
    let mut public_names = Vec::new();
    for target_name in target_names {
        let public_name = public_kinsn_name(target_name);
        if !public_names.contains(&public_name) {
            public_names.push(public_name);
        }
    }
    bail!(
        "{pass_label} requires at least one target kinsn: {}",
        public_names.join(", ")
    );
}

fn read_bytecode(input: Option<&Path>) -> Result<Vec<BpfInsn>> {
    let mut bytes = Vec::new();
    match input {
        Some(path) => {
            bytes = fs::read(path).with_context(|| format!("failed to read {}", path.display()))?;
        }
        None => {
            io::stdin()
                .lock()
                .read_to_end(&mut bytes)
                .context("failed to read stdin")?;
        }
    }

    parse_bytecode(&bytes)
}

fn parse_bytecode(bytes: &[u8]) -> Result<Vec<BpfInsn>> {
    if !bytes.len().is_multiple_of(8) {
        bail!(
            "bytecode length {} is not a multiple of 8 bytes",
            bytes.len()
        );
    }
    Ok(bytes
        .chunks_exact(8)
        .map(|chunk| BpfInsn::from_raw_bytes(chunk.try_into().expect("chunk is 8 bytes")))
        .collect())
}

fn write_bytecode(output: Option<&Path>, insns: &[BpfInsn]) -> Result<()> {
    let mut out = open_binary_output(output)?;
    for insn in insns {
        out.write_all(&insn.raw_bytes())?;
    }
    out.flush()?;
    Ok(())
}

fn open_binary_output(output: Option<&Path>) -> Result<Box<dyn Write>> {
    match output {
        Some(path) => {
            Ok(Box::new(fs::File::create(path).with_context(|| {
                format!("failed to create {}", path.display())
            })?))
        }
        None => Ok(Box::new(io::stdout().lock())),
    }
}

fn open_text_output(output: Option<&Path>) -> Result<Box<dyn Write>> {
    open_binary_output(output)
}

fn write_json<T: Serialize>(output: Option<&Path>, value: &T) -> Result<()> {
    let mut out = open_text_output(output)?;
    serde_json::to_writer_pretty(&mut out, value)?;
    writeln!(out)?;
    Ok(())
}

fn attach_program_inputs(program: &mut BpfProgram, common: &CommonArgs) -> Result<()> {
    if !common.map_ids.is_empty() {
        program.set_map_ids(parse_u32_list(&common.map_ids, "--map-ids")?);
    }
    if let Some(path) = common.verifier_states.as_deref() {
        program.set_verifier_states(read_verifier_states(path)?);
    }
    if let Some(path) = common.map_values.as_deref() {
        let snapshot = read_map_values(path)?;
        program.map_metadata = snapshot.metadata;
        program.map_values = snapshot.values;
    }
    Ok(())
}

fn build_pass_context(common: &CommonArgs) -> Result<PassContext> {
    let mut ctx = PassContext::test_default();
    ctx.platform = detect_platform();
    ctx.kinsn_call_resolver = Arc::new(StaticKinsnCallResolver);

    if let Some(platform) = common.platform.as_deref() {
        ctx.platform.arch = parse_arch(platform)?;
    }

    if let Some(path) = common.target.as_deref() {
        let target = read_target(path)?;
        if let Some(arch) = target.arch.as_deref() {
            ctx.platform.arch = parse_arch(arch)?;
        }
        apply_features(&mut ctx.platform, &target.features);
        ctx.kinsn_registry = kinsn_registry_from_target(&target)?;
    }

    if !common.kinsns.is_empty() {
        apply_kinsn_list(&mut ctx.kinsn_registry, &common.kinsns)?;
    }

    Ok(ctx)
}

fn detect_platform() -> PlatformCapabilities {
    let mut platform = PlatformCapabilities::default();

    #[cfg(target_arch = "aarch64")]
    {
        platform.arch = bpfopt::pass::Arch::Aarch64;
    }
    #[cfg(target_arch = "x86_64")]
    {
        platform.arch = bpfopt::pass::Arch::X86_64;
        platform.has_cmov = true;
        platform.has_bmi1 = std::is_x86_feature_detected!("bmi1");
        platform.has_bmi2 = std::is_x86_feature_detected!("bmi2");
        platform.has_movbe = std::is_x86_feature_detected!("movbe");
        platform.has_rorx = std::is_x86_feature_detected!("bmi2");
    }

    platform
}

fn parse_arch(arch: &str) -> Result<bpfopt::pass::Arch> {
    match arch {
        "x86_64" | "amd64" => Ok(bpfopt::pass::Arch::X86_64),
        "aarch64" | "arm64" => Ok(bpfopt::pass::Arch::Aarch64),
        _ => bail!("unsupported platform arch: {arch}"),
    }
}

fn apply_features(platform: &mut PlatformCapabilities, features: &[String]) {
    platform.has_bmi1 = false;
    platform.has_bmi2 = false;
    platform.has_cmov = false;
    platform.has_movbe = false;
    platform.has_rorx = false;

    for feature in features {
        match feature.as_str() {
            "bmi1" => platform.has_bmi1 = true,
            "bmi2" => platform.has_bmi2 = true,
            "cmov" => platform.has_cmov = true,
            "movbe" => platform.has_movbe = true,
            "rorx" => platform.has_rorx = true,
            _ => {}
        }
    }
}

fn read_target(path: &Path) -> Result<TargetJson> {
    read_json_file(path, "target.json")
}

fn kinsn_registry_from_target(target: &TargetJson) -> Result<KinsnRegistry> {
    let mut registry = unavailable_kinsn_registry();
    for (name, spec) in &target.kinsns {
        let canonical = canonicalize_kinsn_name(name)?;
        set_kinsn_btf_id(&mut registry, canonical, spec.btf_func_id);
        if let Some(call_offset) = spec.call_offset {
            registry
                .target_call_offsets
                .insert(canonical.to_string(), call_offset);
        }
        if let Some(encodings) = &spec.supported_encodings {
            registry
                .target_supported_encodings
                .insert(canonical.to_string(), parse_supported_encodings(encodings));
        }
    }
    Ok(registry)
}

fn unavailable_kinsn_registry() -> KinsnRegistry {
    KinsnRegistry {
        rotate64_btf_id: -1,
        select64_btf_id: -1,
        extract64_btf_id: -1,
        memcpy_bulk_btf_id: -1,
        memset_bulk_btf_id: -1,
        endian_load16_btf_id: -1,
        endian_load32_btf_id: -1,
        endian_load64_btf_id: -1,
        target_call_offsets: HashMap::new(),
        target_supported_encodings: HashMap::new(),
    }
}

fn parse_supported_encodings(encodings: &SupportedEncodingsJson) -> u32 {
    match encodings {
        SupportedEncodingsJson::Bits(bits) => *bits,
        SupportedEncodingsJson::Names(names) => names.iter().fold(0u32, |bits, name| {
            if name == "packed" || name == "packed_call" {
                bits | bpfopt::insn::BPF_KINSN_ENC_PACKED_CALL
            } else {
                bits
            }
        }),
    }
}

fn apply_kinsn_list(registry: &mut KinsnRegistry, kinsns: &[String]) -> Result<()> {
    for item in kinsns {
        let trimmed = item.trim();
        if trimmed.is_empty() {
            continue;
        }
        let (name, btf_id) = match trimmed.split_once(':') {
            Some((name, btf_id)) => (
                name,
                btf_id
                    .parse::<i32>()
                    .with_context(|| format!("invalid btf id in --kinsns entry {trimmed}"))?,
            ),
            None => (trimmed, 0),
        };
        let canonical = canonicalize_kinsn_name(name)?;
        set_kinsn_btf_id(registry, canonical, btf_id);
    }
    Ok(())
}

fn canonicalize_kinsn_name(input: &str) -> Result<&'static str> {
    KINSN_ALIASES
        .iter()
        .find_map(|(alias, canonical)| (*alias == input).then_some(*canonical))
        .ok_or_else(|| anyhow!("unknown kinsn name: {input}"))
}

fn set_kinsn_btf_id(registry: &mut KinsnRegistry, name: &str, btf_id: i32) {
    match name {
        "bpf_rotate64" => registry.rotate64_btf_id = btf_id,
        "bpf_select64" => registry.select64_btf_id = btf_id,
        "bpf_extract64" => registry.extract64_btf_id = btf_id,
        "bpf_memcpy_bulk" => registry.memcpy_bulk_btf_id = btf_id,
        "bpf_memset_bulk" => registry.memset_bulk_btf_id = btf_id,
        "bpf_endian_load16" => registry.endian_load16_btf_id = btf_id,
        "bpf_endian_load32" => registry.endian_load32_btf_id = btf_id,
        "bpf_endian_load64" => registry.endian_load64_btf_id = btf_id,
        _ => {}
    }
}

fn read_profile(path: Option<&Path>) -> Result<Option<ProfilingData>> {
    let Some(path) = path else {
        return Ok(None);
    };
    let profile: ProfileJson = read_json_file(path, "profile.json")?;
    let mut data = ProfilingData {
        branch_miss_rate: profile.branch_miss_rate,
        ..ProfilingData::default()
    };
    for (pc, counts) in profile.per_insn {
        let pc = pc
            .parse::<usize>()
            .with_context(|| format!("invalid per_insn pc key: {pc}"))?;
        data.branch_profiles.insert(
            pc,
            BranchProfile {
                taken_count: counts.taken,
                not_taken_count: counts.not_taken,
            },
        );
    }
    Ok(Some(data))
}

fn read_verifier_states(path: &Path) -> Result<Vec<VerifierInsn>> {
    let states: VerifierStatesJson = read_json_file(path, "verifier-states.json")?;
    states
        .insns
        .into_iter()
        .map(|insn| {
            let regs = insn
                .regs
                .into_iter()
                .map(|(reg, state)| Ok((parse_reg_name(&reg)?, verifier_reg_state(state)?)))
                .collect::<Result<HashMap<_, _>>>()?;
            Ok(VerifierInsn {
                pc: insn.pc,
                frame: insn.frame,
                from_pc: None,
                kind: VerifierInsnKind::InsnDeltaState,
                speculative: false,
                regs,
                stack: HashMap::<i16, StackState>::new(),
            })
        })
        .collect()
}

fn parse_reg_name(reg: &str) -> Result<u8> {
    let reg = reg
        .strip_prefix('r')
        .or_else(|| reg.strip_prefix('R'))
        .unwrap_or(reg);
    let value = reg
        .parse::<u8>()
        .with_context(|| format!("invalid register name: {reg}"))?;
    if value > 10 {
        bail!("invalid BPF register r{value}");
    }
    Ok(value)
}

fn verifier_reg_state(state: VerifierRegJson) -> Result<RegState> {
    let exact_value = state.const_val.map(|value| value as u64);
    let tnum = state.tnum.as_deref().map(parse_tnum).transpose()?;
    Ok(RegState {
        reg_type: state.reg_type,
        value_width: VerifierValueWidth::Unknown,
        precise: exact_value.is_some(),
        exact_value,
        tnum,
        range: ScalarRange {
            smin: state.min,
            smax: state.max,
            umin: state.min.and_then(|value| u64::try_from(value).ok()),
            umax: state.max.and_then(|value| u64::try_from(value).ok()),
            ..ScalarRange::default()
        },
        offset: None,
        id: None,
    })
}

fn parse_tnum(input: &str) -> Result<Tnum> {
    let (value, mask) = input
        .split_once('/')
        .ok_or_else(|| anyhow!("invalid tnum {input}: expected value/mask"))?;
    Ok(Tnum {
        value: parse_u64_auto_radix(value)?,
        mask: parse_u64_auto_radix(mask)?,
    })
}

fn parse_u64_auto_radix(input: &str) -> Result<u64> {
    let input = input.trim();
    if let Some(hex) = input.strip_prefix("0x") {
        Ok(u64::from_str_radix(hex, 16)?)
    } else {
        Ok(input.parse::<u64>()?)
    }
}

struct MapSnapshot {
    metadata: HashMap<u32, MapMetadata>,
    values: HashMap<(u32, Vec<u8>), Vec<u8>>,
}

fn read_map_values(path: &Path) -> Result<MapSnapshot> {
    let raw: MapValuesJson = read_json_file(path, "map-values.json")?;
    let mut metadata = HashMap::new();
    let mut values = HashMap::new();

    for map in raw.maps {
        let map_type = parse_map_type(&map.map_type)?;
        metadata.insert(
            map.map_id,
            MapMetadata {
                map_type,
                key_size: map.key_size,
                value_size: map.value_size,
                max_entries: map.max_entries,
                frozen: map.frozen,
                map_id: map.map_id,
            },
        );
        for entry in map.entries {
            let key = decode_hex(&entry.key)
                .with_context(|| format!("invalid key hex for map {}", map.map_id))?;
            if let Some(value) = entry.value {
                values.insert(
                    (map.map_id, key),
                    decode_hex(&value)
                        .with_context(|| format!("invalid value hex for map {}", map.map_id))?,
                );
            }
        }
    }

    Ok(MapSnapshot { metadata, values })
}

fn parse_map_type(map_type: &MapTypeJson) -> Result<u32> {
    match map_type {
        MapTypeJson::Number(number) => Ok(*number),
        MapTypeJson::Name(name) => {
            let normalized = name
                .trim()
                .trim_start_matches("BPF_MAP_TYPE_")
                .trim_start_matches("bpf_map_type_")
                .replace(['-', ' '], "_")
                .to_ascii_lowercase();
            match normalized.as_str() {
                "hash" => Ok(kernel_sys::BPF_MAP_TYPE_HASH),
                "array" => Ok(kernel_sys::BPF_MAP_TYPE_ARRAY),
                "percpu_hash" | "per_cpu_hash" => Ok(kernel_sys::BPF_MAP_TYPE_PERCPU_HASH),
                "percpu_array" | "per_cpu_array" => Ok(kernel_sys::BPF_MAP_TYPE_PERCPU_ARRAY),
                "lru_hash" => Ok(kernel_sys::BPF_MAP_TYPE_LRU_HASH),
                "lru_percpu_hash" | "lru_per_cpu_hash" => {
                    Ok(kernel_sys::BPF_MAP_TYPE_LRU_PERCPU_HASH)
                }
                _ => bail!("unsupported map_type: {name}"),
            }
        }
    }
}

fn decode_hex(input: &str) -> Result<Vec<u8>> {
    let mut hex = input
        .chars()
        .filter(|ch| !ch.is_ascii_whitespace())
        .collect::<String>();
    if let Some(stripped) = hex.strip_prefix("0x") {
        hex = stripped.to_string();
    }
    if hex.len() % 2 != 0 {
        bail!("hex string has odd length");
    }
    let mut out = Vec::with_capacity(hex.len() / 2);
    for idx in (0..hex.len()).step_by(2) {
        out.push(u8::from_str_radix(&hex[idx..idx + 2], 16)?);
    }
    Ok(out)
}

fn parse_u32_list(values: &[String], flag: &str) -> Result<Vec<u32>> {
    values
        .iter()
        .map(|value| {
            value
                .trim()
                .parse::<u32>()
                .with_context(|| format!("invalid {flag} value: {value}"))
        })
        .collect()
}

fn read_json_file<T: for<'de> Deserialize<'de>>(path: &Path, label: &str) -> Result<T> {
    let data = fs::read(path).with_context(|| format!("failed to read {}", path.display()))?;
    serde_json::from_slice(&data)
        .with_context(|| format!("failed to parse {label} from {}", path.display()))
}

fn pass_report(result: &PassResult) -> PassReport {
    PassReport {
        pass: result.pass_name.clone(),
        skipped: false,
        reason: None,
        changed: result.changed,
        sites_applied: result.sites_applied,
        insn_count_before: result.insns_before,
        insn_count_after: result.insns_after,
        insn_delta: result.insns_after as isize - result.insns_before as isize,
    }
}

fn unchanged_report(pass_name: &str, insn_count: usize) -> PassReport {
    PassReport {
        pass: pass_name.to_string(),
        skipped: false,
        reason: None,
        changed: false,
        sites_applied: 0,
        insn_count_before: insn_count,
        insn_count_after: insn_count,
        insn_delta: 0,
    }
}

fn skipped_report(pass_name: &str, reason: &str, insn_count: usize) -> PassReport {
    PassReport {
        pass: pass_name.to_string(),
        skipped: true,
        reason: Some(reason.to_string()),
        changed: false,
        sites_applied: 0,
        insn_count_before: insn_count,
        insn_count_after: insn_count,
        insn_delta: 0,
    }
}

fn optimize_reports(
    plan: &[OptimizePassPlan],
    pass_results: &[PassResult],
    program: &BpfProgram,
) -> Vec<PassReport> {
    let mut reports = Vec::with_capacity(plan.len().max(pass_results.len()));
    let mut used_results = vec![false; pass_results.len()];

    for planned in plan {
        if let Some(reason) = planned.skip_reason.as_deref() {
            reports.push(skipped_report(
                planned.pass_name,
                reason,
                program.insns.len(),
            ));
            continue;
        }

        if let Some((idx, result)) = pass_results
            .iter()
            .enumerate()
            .find(|(idx, result)| !used_results[*idx] && result.pass_name == planned.pass_name)
        {
            used_results[idx] = true;
            reports.push(pass_report(result));
        } else {
            reports.push(unchanged_report(planned.pass_name, program.insns.len()));
        }
    }

    reports.extend(
        pass_results
            .iter()
            .enumerate()
            .filter(|(idx, _)| !used_results[*idx])
            .map(|(_, result)| pass_report(result)),
    );
    reports
}

fn collect_map_lookups(
    program: &BpfProgram,
    map_refs: &[bpfopt::analysis::MapReference],
) -> Vec<MapLookupReport> {
    let refs_by_pc = map_refs
        .iter()
        .map(|reference| (reference.pc, reference))
        .collect::<HashMap<_, _>>();
    let mut out = Vec::new();

    for (pc, insn) in program.insns.iter().enumerate() {
        if insn.is_call() && insn.src_reg() == 0 && insn.imm == 1 {
            let map_load_pc = find_nearest_map_load(&program.insns, pc);
            let map_ref = map_load_pc.and_then(|load_pc| refs_by_pc.get(&load_pc).copied());
            out.push(MapLookupReport {
                pc,
                map_load_pc,
                map_id: map_ref.and_then(|reference| reference.map_id),
                old_fd: map_ref.map(|reference| reference.old_fd),
            });
        }
    }

    out
}

fn find_nearest_map_load(insns: &[BpfInsn], call_pc: usize) -> Option<usize> {
    let mut pc = 0usize;
    let mut last = None;
    while pc < call_pc && pc < insns.len() {
        let insn = insns[pc];
        if insn.is_ldimm64() && insn.dst_reg() == 1 && insn.src_reg() == BPF_PSEUDO_MAP_FD {
            last = Some(pc);
        }
        pc += if insn.is_ldimm64() { 2 } else { 1 };
    }
    last
}

fn collect_kinsn_calls(program: &BpfProgram) -> Vec<KinsnCallReport> {
    program
        .insns
        .iter()
        .enumerate()
        .filter_map(|(pc, insn)| {
            (insn.is_call() && insn.src_reg() == BPF_PSEUDO_KINSN_CALL).then_some(KinsnCallReport {
                pc,
                btf_func_id: insn.imm,
                call_offset: insn.off,
            })
        })
        .collect()
}

fn count_ldimm64(program: &BpfProgram) -> usize {
    program
        .insns
        .iter()
        .filter(|insn| insn.code() == (BPF_LD | BPF_DW | BPF_IMM))
        .count()
}

fn count_branches(program: &BpfProgram, _branch_target_slots: usize) -> usize {
    program
        .insns
        .iter()
        .filter(|insn| {
            insn.is_jmp_class()
                && !insn.is_call()
                && !insn.is_exit()
                && bpf_op(insn.code()) != BPF_CALL
                && bpf_op(insn.code()) != BPF_EXIT
                && (bpf_op(insn.code()) == BPF_JA || insn.is_cond_jmp())
        })
        .count()
}

fn default_reg_type() -> String {
    "scalar".to_string()
}

fn default_frozen() -> bool {
    true
}

#[cfg(test)]
mod tests {
    use super::*;

    fn minimal_program_bytes() -> Vec<u8> {
        vec![
            0xb7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x95, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00,
        ]
    }

    #[test]
    fn parse_bytecode_rejects_non_instruction_multiple() {
        let err = parse_bytecode(&[0u8; 9]).unwrap_err().to_string();
        assert!(err.contains("multiple of 8"));
    }

    #[test]
    fn parse_bytecode_round_trips_raw_instruction_bytes() {
        let raw = minimal_program_bytes();
        let insns = parse_bytecode(&raw).unwrap();
        let encoded = insns
            .iter()
            .flat_map(|insn| insn.raw_bytes())
            .collect::<Vec<_>>();
        assert_eq!(encoded, raw);
    }

    #[test]
    fn canonical_pass_names_accept_v3_cli_names() {
        assert_eq!(canonicalize_pass_name("wide-mem").unwrap(), "wide_mem");
        assert_eq!(
            canonicalize_pass_name("skb-load-bytes").unwrap(),
            "skb_load_bytes_spec"
        );
        assert!(canonicalize_pass_name("wide_mem2").is_err());
    }

    #[test]
    fn target_json_maps_v3_kinsn_aliases_to_registry_fields() {
        let target = TargetJson {
            arch: Some("x86_64".to_string()),
            features: vec!["cmov".to_string(), "movbe".to_string()],
            kinsns: HashMap::from([
                (
                    "bpf_bulk_memcpy".to_string(),
                    KinsnJson {
                        btf_func_id: 11,
                        call_offset: Some(2),
                        supported_encodings: None,
                    },
                ),
                (
                    "bpf_endian_load64".to_string(),
                    KinsnJson {
                        btf_func_id: 12,
                        call_offset: None,
                        supported_encodings: None,
                    },
                ),
            ]),
        };

        let registry = kinsn_registry_from_target(&target).unwrap();
        assert_eq!(registry.memcpy_bulk_btf_id, 11);
        assert_eq!(registry.endian_load64_btf_id, 12);
        assert_eq!(registry.call_off_for_target_name("bpf_memcpy_bulk"), 2);
        assert!(registry.packed_supported_for_target_name("bpf_memcpy_bulk"));
    }

    #[test]
    fn verifier_states_json_builds_const_prop_delta_states() {
        let state = VerifierInsnJson {
            pc: 5,
            frame: 0,
            regs: HashMap::from([(
                "r1".to_string(),
                VerifierRegJson {
                    reg_type: "scalar".to_string(),
                    const_val: Some(42),
                    min: None,
                    max: None,
                    tnum: Some("0x2a/0x0".to_string()),
                },
            )]),
        };

        let regs = state
            .regs
            .into_iter()
            .map(|(reg, state)| Ok((parse_reg_name(&reg)?, verifier_reg_state(state)?)))
            .collect::<Result<HashMap<_, _>>>()
            .unwrap();

        assert_eq!(regs[&1].exact_value, Some(42));
        assert_eq!(regs[&1].tnum.unwrap().value, 42);
    }
}
