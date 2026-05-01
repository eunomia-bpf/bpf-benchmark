// SPDX-License-Identifier: MIT
//! bpfopt CLI entry point.

use std::collections::{HashMap, HashSet};
use std::fs;
use std::io::{self, Read, Write};
use std::path::{Path, PathBuf};
use std::process::ExitCode;
use std::sync::Arc;

use anyhow::{anyhow, bail, Context, Result};
use bpfopt::analysis::{BranchTargetAnalysis, CFGAnalysis, LivenessAnalysis};
use bpfopt::insn::BpfInsn;
use bpfopt::pass::{
    Arch, BpfProgram, BranchProfile, BtfInfoRecords, KinsnRegistry, MapMetadata, PassContext,
    PassManager, PassResult, PlatformCapabilities, ProfilingData, RegState, ScalarRange,
    StackState, StaticKinsnCallResolver, Tnum, VerifierInsn, VerifierInsnKind, VerifierValueWidth,
    DEFAULT_ENABLED_PASS_ORDER,
};
use bpfopt::passes::{MapInfoAnalysis, PASS_REGISTRY};
use clap::{Args, Parser, Subcommand};
use kernel_sys::{VerifierRegJson, VerifierStatesJson};
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
    "ccmp",
    "extract",
    "endian_fusion",
    "branch_flip",
    "prefetch",
];

const PASS_ALIASES: &[(&str, &str)] = &[
    ("wide-mem", "wide_mem"),
    ("wide_mem", "wide_mem"),
    ("rotate", "rotate"),
    ("const-prop", "const_prop"),
    ("const_prop", "const_prop"),
    ("cond-select", "cond_select"),
    ("cond_select", "cond_select"),
    ("ccmp", "ccmp"),
    ("extract", "extract"),
    ("endian", "endian_fusion"),
    ("endian-fusion", "endian_fusion"),
    ("endian_fusion", "endian_fusion"),
    ("branch-flip", "branch_flip"),
    ("branch_flip", "branch_flip"),
    ("prefetch", "prefetch"),
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
    ("bpf_ccmp64", "bpf_ccmp64"),
    ("ccmp64", "bpf_ccmp64"),
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
    ("bpf_prefetch", "bpf_prefetch"),
    ("prefetch", "bpf_prefetch"),
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
    /// BPF program type, such as xdp, sched_cls, tracing, or a numeric type.
    #[arg(long, global = true, value_name = "TYPE")]
    prog_type: Option<String>,
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
    /// Raw func_info records to remap in place when instruction offsets change.
    #[arg(long, global = true, value_name = "FILE")]
    func_info: Option<PathBuf>,
    /// Byte size of one func_info record.
    #[arg(long, global = true, value_name = "BYTES")]
    func_info_rec_size: Option<u32>,
    /// Raw line_info records to remap in place when instruction offsets change.
    #[arg(long, global = true, value_name = "FILE")]
    line_info: Option<PathBuf>,
    /// Byte size of one line_info record.
    #[arg(long, global = true, value_name = "BYTES")]
    line_info_rec_size: Option<u32>,
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
    /// Fold ARM64 zero-test compare chains with CCMP.
    Ccmp,
    /// Replace shift+mask with bit-field extract kinsn calls.
    Extract,
    /// Fuse endian load+swap sequences.
    Endian,
    /// Reorder if/else bodies using PGO profile data.
    #[command(name = "branch-flip")]
    BranchFlip,
    /// Insert packet and map-value prefetch kinsn calls.
    Prefetch,
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
    /// List available optimization passes.
    #[command(name = "list-passes")]
    ListPasses(ListPassesArgs),
}

#[derive(Args)]
struct OptimizeArgs {
    /// Comma-separated pass list. Defaults to the target architecture optimize order.
    #[arg(long, value_name = "LIST", value_delimiter = ',')]
    passes: Vec<String>,
}

#[derive(Args)]
struct ListPassesArgs {
    /// Emit machine-readable pass metadata.
    #[arg(long)]
    json: bool,
    /// Show the default optimize order for an architecture instead of all passes.
    #[arg(long, value_name = "ARCH")]
    arch: Option<String>,
}

#[derive(Clone, Debug, Serialize)]
struct PassReport {
    pass: String,
    changed: bool,
    sites_applied: usize,
    insn_count_before: usize,
    insn_count_after: usize,
    insn_delta: isize,
    #[serde(skip_serializing_if = "Vec::is_empty")]
    map_inline_records: Vec<MapInlineRecordReport>,
}

#[derive(Clone, Debug, Serialize)]
struct MapInlineRecordReport {
    map_id: u32,
    key_hex: String,
    value_hex: String,
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
    cache_miss_rate: Option<f64>,
    #[serde(default)]
    per_site: HashMap<String, ProfileSiteJson>,
    #[serde(default)]
    prefetch_sites: HashMap<String, PrefetchSiteJson>,
}

#[derive(Debug, Deserialize)]
struct ProfileSiteJson {
    branch_count: u64,
    branch_misses: u64,
    miss_rate: f64,
    taken: u64,
    not_taken: u64,
}

#[derive(Debug, Deserialize)]
struct PrefetchSiteJson {
    execution_count: u64,
    cache_references: u64,
    cache_misses: u64,
    miss_rate: f64,
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
        Command::ListPasses(args) => list_passes(&cli.common, &args),
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
            Command::Ccmp => Some("ccmp"),
            Command::Extract => Some("extract"),
            Command::Endian => Some("endian_fusion"),
            Command::BranchFlip => Some("branch_flip"),
            Command::Prefetch => Some("prefetch"),
            Command::Dce => Some("dce"),
            Command::MapInline => Some("map_inline"),
            Command::BulkMemory => Some("bulk_memory"),
            Command::BoundsCheckMerge => Some("bounds_check_merge"),
            Command::SkbLoadBytes => Some("skb_load_bytes_spec"),
            Command::Optimize(_) | Command::ListPasses(_) => None,
        }
    }
}

fn list_passes(common: &CommonArgs, args: &ListPassesArgs) -> Result<()> {
    let names = match args.arch.as_deref() {
        Some(arch) => default_optimize_pass_order(parse_arch(arch)?).to_vec(),
        None => ALL_PASS_ORDER.to_vec(),
    };

    if args.json {
        let entries = names
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
        for &name in &names {
            writeln!(out, "{}", cli_name_for_pass(name))?;
        }
        Ok(())
    }
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
    write_btf_info_outputs(common, &program)?;

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
    let mut ctx = build_pass_context(common)?;
    let pass_names = if args.passes.is_empty() {
        default_optimize_pass_order(ctx.platform.arch).to_vec()
    } else {
        args.passes
            .iter()
            .map(|name| canonicalize_pass_name(name))
            .collect::<Result<Vec<_>>>()?
    };

    validate_required_side_inputs(common, &pass_names)?;
    let mut program = BpfProgram::new(read_bytecode(common.input.as_deref())?);
    attach_program_inputs(&mut program, common)?;
    validate_required_kinsns(&ctx, &pass_names)?;
    ctx.policy.enabled_passes = pass_names.iter().map(|name| (*name).to_string()).collect();
    let pipeline = build_pipeline(&pass_names)?;
    let profiling = read_profile(common.profile.as_deref())?;
    let result = run_pipeline_catching_panics(&pipeline, &mut program, &ctx, profiling.as_ref())?;
    write_bytecode(common.output.as_deref(), &program.insns)?;
    write_btf_info_outputs(common, &program)?;

    if let Some(report_path) = common.report.as_deref() {
        let report = OptimizeReport {
            passes: optimize_reports(&result.pass_results),
        };
        write_json(Some(report_path), &report)?;
    }

    Ok(())
}

fn default_optimize_pass_order(arch: Arch) -> &'static [&'static str] {
    match arch {
        Arch::Aarch64 | Arch::X86_64 => DEFAULT_ENABLED_PASS_ORDER,
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
        "ccmp" => "ccmp",
        "extract" => "extract",
        "endian_fusion" => "endian",
        "branch_flip" => "branch-flip",
        "prefetch" => "prefetch",
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
            "rotate" | "cond_select" | "extract" | "endian_fusion" | "bulk_memory" | "prefetch" => {
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
                if common.verifier_states.is_none()
                    || common.map_values.is_none()
                    || common.map_ids.is_empty()
                {
                    bail!("map-inline requires --verifier-states, --map-values, and --map-ids");
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
            "ccmp" if ctx.platform.arch == Arch::Aarch64 => require_kinsn(ctx, "bpf_ccmp64")?,
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
                require_all_kinsns(ctx, &["bpf_memcpy_bulk", "bpf_memset_bulk"], "bulk-memory")?
            }
            "prefetch" => require_kinsn(ctx, "bpf_prefetch")?,
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

fn require_all_kinsns(ctx: &PassContext, target_names: &[&str], pass_label: &str) -> Result<()> {
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
        return Ok(());
    }
    bail!(
        "{pass_label} requires target kinsns: {}",
        missing.join(", ")
    );
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
        program.map_value_nulls = snapshot.nulls;
    }
    program.func_info = read_btf_info_records(
        common.func_info.as_deref(),
        common.func_info_rec_size,
        "func-info",
    )?;
    program.line_info = read_btf_info_records(
        common.line_info.as_deref(),
        common.line_info_rec_size,
        "line-info",
    )?;
    Ok(())
}

fn read_btf_info_records(
    path: Option<&Path>,
    rec_size: Option<u32>,
    label: &str,
) -> Result<Option<BtfInfoRecords>> {
    let (path, rec_size) = match (path, rec_size) {
        (None, None) => return Ok(None),
        (Some(path), Some(rec_size)) => (path, rec_size),
        (Some(_), None) => bail!("--{label} requires --{label}-rec-size"),
        (None, Some(_)) => bail!("--{label}-rec-size requires --{label}"),
    };
    let bytes = fs::read(path).with_context(|| format!("failed to read {}", path.display()))?;
    Ok(Some(BtfInfoRecords::new(label, rec_size, bytes)?))
}

fn write_btf_info_outputs(common: &CommonArgs, program: &BpfProgram) -> Result<()> {
    if let Some(path) = common.func_info.as_deref() {
        let bytes = program
            .func_info
            .as_ref()
            .map(|records| records.bytes.as_slice())
            .unwrap_or(&[]);
        fs::write(path, bytes).with_context(|| format!("failed to write {}", path.display()))?;
    }
    if let Some(path) = common.line_info.as_deref() {
        let bytes = program
            .line_info
            .as_ref()
            .map(|records| records.bytes.as_slice())
            .unwrap_or(&[]);
        fs::write(path, bytes).with_context(|| format!("failed to write {}", path.display()))?;
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
    if let Some(prog_type) = common.prog_type.as_deref() {
        ctx.prog_type = parse_prog_type(prog_type)?;
    }

    if let Some(path) = common.target.as_deref() {
        let target = read_target(path)?;
        if let Some(arch) = target.arch.as_deref() {
            ctx.platform.arch = parse_arch(arch)?;
        }
        apply_features(&mut ctx.platform, &target.features)?;
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

fn parse_prog_type(input: &str) -> Result<u32> {
    if let Ok(value) = input.parse::<u32>() {
        return Ok(value);
    }
    let mut normalized = input.trim().to_ascii_lowercase();
    if let Some(stripped) = normalized.strip_prefix("bpf_prog_type_") {
        normalized = stripped.to_string();
    }
    let normalized = normalized.replace('-', "_");
    let value = match normalized.as_str() {
        "socket_filter" => kernel_sys::BPF_PROG_TYPE_SOCKET_FILTER,
        "kprobe" => kernel_sys::BPF_PROG_TYPE_KPROBE,
        "sched_cls" => kernel_sys::BPF_PROG_TYPE_SCHED_CLS,
        "sched_act" => kernel_sys::BPF_PROG_TYPE_SCHED_ACT,
        "tracepoint" => kernel_sys::BPF_PROG_TYPE_TRACEPOINT,
        "xdp" => kernel_sys::BPF_PROG_TYPE_XDP,
        "perf_event" => kernel_sys::BPF_PROG_TYPE_PERF_EVENT,
        "cgroup_skb" => kernel_sys::BPF_PROG_TYPE_CGROUP_SKB,
        "cgroup_sock" => kernel_sys::BPF_PROG_TYPE_CGROUP_SOCK,
        "lwt_in" => kernel_sys::BPF_PROG_TYPE_LWT_IN,
        "lwt_out" => kernel_sys::BPF_PROG_TYPE_LWT_OUT,
        "lwt_xmit" => kernel_sys::BPF_PROG_TYPE_LWT_XMIT,
        "sock_ops" => kernel_sys::BPF_PROG_TYPE_SOCK_OPS,
        "sk_skb" => kernel_sys::BPF_PROG_TYPE_SK_SKB,
        "cgroup_device" => kernel_sys::BPF_PROG_TYPE_CGROUP_DEVICE,
        "sk_msg" => kernel_sys::BPF_PROG_TYPE_SK_MSG,
        "raw_tracepoint" => kernel_sys::BPF_PROG_TYPE_RAW_TRACEPOINT,
        "cgroup_sock_addr" => kernel_sys::BPF_PROG_TYPE_CGROUP_SOCK_ADDR,
        "lwt_seg6local" => kernel_sys::BPF_PROG_TYPE_LWT_SEG6LOCAL,
        "lirc_mode2" => kernel_sys::BPF_PROG_TYPE_LIRC_MODE2,
        "sk_reuseport" => kernel_sys::BPF_PROG_TYPE_SK_REUSEPORT,
        "flow_dissector" => kernel_sys::BPF_PROG_TYPE_FLOW_DISSECTOR,
        "cgroup_sysctl" => kernel_sys::BPF_PROG_TYPE_CGROUP_SYSCTL,
        "raw_tracepoint_writable" => kernel_sys::BPF_PROG_TYPE_RAW_TRACEPOINT_WRITABLE,
        "cgroup_sockopt" => kernel_sys::BPF_PROG_TYPE_CGROUP_SOCKOPT,
        "tracing" => kernel_sys::BPF_PROG_TYPE_TRACING,
        "struct_ops" => kernel_sys::BPF_PROG_TYPE_STRUCT_OPS,
        "ext" => kernel_sys::BPF_PROG_TYPE_EXT,
        "lsm" => kernel_sys::BPF_PROG_TYPE_LSM,
        "sk_lookup" => kernel_sys::BPF_PROG_TYPE_SK_LOOKUP,
        "syscall" => kernel_sys::BPF_PROG_TYPE_SYSCALL,
        "netfilter" => kernel_sys::BPF_PROG_TYPE_NETFILTER,
        _ => bail!("unknown prog type '{input}'"),
    };
    Ok(value)
}

fn apply_features(platform: &mut PlatformCapabilities, features: &[String]) -> Result<()> {
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
            _ => bail!("unknown target feature: {feature}"),
        }
    }
    Ok(())
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
                .insert(canonical.to_string(), parse_supported_encodings(encodings)?);
        }
    }
    Ok(registry)
}

fn unavailable_kinsn_registry() -> KinsnRegistry {
    KinsnRegistry {
        rotate64_btf_id: -1,
        select64_btf_id: -1,
        ccmp64_btf_id: -1,
        extract64_btf_id: -1,
        memcpy_bulk_btf_id: -1,
        memset_bulk_btf_id: -1,
        endian_load16_btf_id: -1,
        endian_load32_btf_id: -1,
        endian_load64_btf_id: -1,
        prefetch_btf_id: -1,
        target_call_offsets: HashMap::new(),
        target_supported_encodings: HashMap::new(),
    }
}

fn parse_supported_encodings(encodings: &SupportedEncodingsJson) -> Result<u32> {
    match encodings {
        SupportedEncodingsJson::Bits(bits) => Ok(*bits),
        SupportedEncodingsJson::Names(names) => {
            let mut bits = 0u32;
            for name in names {
                match name.as_str() {
                    "packed" | "packed_call" => {
                        bits |= bpfopt::insn::BPF_KINSN_ENC_PACKED_CALL;
                    }
                    _ => bail!("unknown kinsn supported encoding: {name}"),
                }
            }
            Ok(bits)
        }
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
        "bpf_ccmp64" => registry.ccmp64_btf_id = btf_id,
        "bpf_extract64" => registry.extract64_btf_id = btf_id,
        "bpf_memcpy_bulk" => registry.memcpy_bulk_btf_id = btf_id,
        "bpf_memset_bulk" => registry.memset_bulk_btf_id = btf_id,
        "bpf_endian_load16" => registry.endian_load16_btf_id = btf_id,
        "bpf_endian_load32" => registry.endian_load32_btf_id = btf_id,
        "bpf_endian_load64" => registry.endian_load64_btf_id = btf_id,
        "bpf_prefetch" => registry.prefetch_btf_id = btf_id,
        _ => {}
    }
}

fn read_profile(path: Option<&Path>) -> Result<Option<ProfilingData>> {
    let Some(path) = path else {
        return Ok(None);
    };
    let profile: ProfileJson = read_json_file(path, "profile.json")?;
    let mut data = ProfilingData::default();
    if let Some(branch_miss_rate) = profile.branch_miss_rate {
        if !branch_miss_rate.is_finite() || !(0.0..=1.0).contains(&branch_miss_rate) {
            bail!(
                "profile branch_miss_rate must be finite and within [0, 1], got {}",
                branch_miss_rate
            );
        }
        data.branch_miss_rate = Some(branch_miss_rate);
    }
    if let Some(cache_miss_rate) = profile.cache_miss_rate {
        if !cache_miss_rate.is_finite() || !(0.0..=1.0).contains(&cache_miss_rate) {
            bail!(
                "profile cache_miss_rate must be finite and within [0, 1], got {}",
                cache_miss_rate
            );
        }
        data.cache_miss_rate = Some(cache_miss_rate);
    }
    for (pc, counts) in profile.per_site {
        let pc = pc
            .parse::<usize>()
            .with_context(|| format!("invalid per_site pc key: {pc}"))?;
        if counts.branch_count == 0 {
            bail!("profile per_site[{pc}] has zero branch_count");
        }
        if counts.branch_misses > counts.branch_count {
            bail!(
                "profile per_site[{pc}] branch_misses {} exceeds branch_count {}",
                counts.branch_misses,
                counts.branch_count
            );
        }
        if !counts.miss_rate.is_finite() || !(0.0..=1.0).contains(&counts.miss_rate) {
            bail!(
                "profile per_site[{pc}] miss_rate must be finite and within [0, 1], got {}",
                counts.miss_rate
            );
        }
        let direction_count = counts
            .taken
            .checked_add(counts.not_taken)
            .ok_or_else(|| anyhow!("profile per_site[{pc}] direction counters overflow"))?;
        if direction_count > counts.branch_count {
            bail!(
                "profile per_site[{pc}] direction count {direction_count} exceeds branch_count {}",
                counts.branch_count
            );
        }
        data.branch_profiles.insert(
            pc,
            BranchProfile {
                branch_count: counts.branch_count,
                branch_misses: counts.branch_misses,
                miss_rate: counts.miss_rate,
                taken_count: counts.taken,
                not_taken_count: counts.not_taken,
            },
        );
    }
    for (pc, counts) in profile.prefetch_sites {
        let pc = pc
            .parse::<usize>()
            .with_context(|| format!("invalid prefetch_sites pc key: {pc}"))?;
        if counts.cache_misses > counts.cache_references {
            bail!(
                "profile prefetch_sites[{pc}] cache_misses {} exceeds cache_references {}",
                counts.cache_misses,
                counts.cache_references
            );
        }
        if !counts.miss_rate.is_finite() || !(0.0..=1.0).contains(&counts.miss_rate) {
            bail!(
                "profile prefetch_sites[{pc}] miss_rate must be finite and within [0, 1], got {}",
                counts.miss_rate
            );
        }
        data.prefetch_profiles.insert(
            pc,
            bpfopt::pass::PrefetchProfile {
                execution_count: counts.execution_count,
                cache_references: counts.cache_references,
                cache_misses: counts.cache_misses,
                miss_rate: counts.miss_rate,
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
            umin: state.min.and_then(nonnegative_i64_to_u64),
            umax: state.max.and_then(nonnegative_i64_to_u64),
            ..ScalarRange::default()
        },
        offset: state.offset,
        id: None,
    })
}

fn nonnegative_i64_to_u64(value: i64) -> Option<u64> {
    let Ok(value) = u64::try_from(value) else {
        return None;
    };
    Some(value)
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
    nulls: HashSet<(u32, Vec<u8>)>,
}

fn read_map_values(path: &Path) -> Result<MapSnapshot> {
    let raw: MapValuesJson = read_json_file(path, "map-values.json")?;
    let mut metadata = HashMap::new();
    let mut values = HashMap::new();
    let mut nulls = HashSet::new();

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
            } else {
                nulls.insert((map.map_id, key));
            }
        }
    }

    Ok(MapSnapshot {
        metadata,
        values,
        nulls,
    })
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
        changed: result.changed,
        sites_applied: result.sites_applied,
        insn_count_before: result.insns_before,
        insn_count_after: result.insns_after,
        insn_delta: result.insns_after as isize - result.insns_before as isize,
        map_inline_records: result
            .map_inline_records
            .iter()
            .map(map_inline_record_report)
            .collect(),
    }
}

fn unchanged_report(pass_name: &str, insn_count: usize) -> PassReport {
    PassReport {
        pass: pass_name.to_string(),
        changed: false,
        sites_applied: 0,
        insn_count_before: insn_count,
        insn_count_after: insn_count,
        insn_delta: 0,
        map_inline_records: Vec::new(),
    }
}

fn map_inline_record_report(record: &bpfopt::pass::MapInlineRecord) -> MapInlineRecordReport {
    MapInlineRecordReport {
        map_id: record.map_id,
        key_hex: hex_bytes(&record.key),
        value_hex: hex_bytes(&record.expected_value),
    }
}

fn hex_bytes(bytes: &[u8]) -> String {
    const HEX: &[u8; 16] = b"0123456789abcdef";
    let mut out = String::with_capacity(bytes.len() * 2);
    for byte in bytes {
        out.push(HEX[(byte >> 4) as usize] as char);
        out.push(HEX[(byte & 0x0f) as usize] as char);
    }
    out
}

fn optimize_reports(pass_results: &[PassResult]) -> Vec<PassReport> {
    pass_results.iter().map(pass_report).collect()
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
        assert_eq!(canonicalize_pass_name("ccmp").unwrap(), "ccmp");
        assert_eq!(
            canonicalize_pass_name("skb-load-bytes").unwrap(),
            "skb_load_bytes_spec"
        );
        assert_eq!(canonicalize_pass_name("prefetch").unwrap(), "prefetch");
        assert!(canonicalize_pass_name("wide_mem2").is_err());
    }

    #[test]
    fn default_optimize_order_is_default_12_pass_policy_on_all_arches() {
        assert!(!default_optimize_pass_order(Arch::Aarch64).contains(&"ccmp"));
        assert!(!default_optimize_pass_order(Arch::X86_64).contains(&"ccmp"));
        assert!(default_optimize_pass_order(Arch::Aarch64).contains(&"const_prop"));
        assert!(default_optimize_pass_order(Arch::X86_64).contains(&"const_prop"));
        assert!(default_optimize_pass_order(Arch::Aarch64).contains(&"prefetch"));
        assert!(default_optimize_pass_order(Arch::X86_64).contains(&"prefetch"));
        assert_eq!(default_optimize_pass_order(Arch::Aarch64).len(), 12);
        assert_eq!(default_optimize_pass_order(Arch::X86_64).len(), 12);
        assert_eq!(
            default_optimize_pass_order(Arch::Aarch64).last(),
            Some(&"prefetch")
        );
        assert_eq!(
            default_optimize_pass_order(Arch::X86_64).last(),
            Some(&"prefetch")
        );
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
                (
                    "bpf_ccmp64".to_string(),
                    KinsnJson {
                        btf_func_id: 13,
                        call_offset: None,
                        supported_encodings: None,
                    },
                ),
                (
                    "bpf_prefetch".to_string(),
                    KinsnJson {
                        btf_func_id: 14,
                        call_offset: Some(7),
                        supported_encodings: None,
                    },
                ),
            ]),
        };

        let registry = kinsn_registry_from_target(&target).unwrap();
        assert_eq!(registry.memcpy_bulk_btf_id, 11);
        assert_eq!(registry.endian_load64_btf_id, 12);
        assert_eq!(registry.ccmp64_btf_id, 13);
        assert_eq!(registry.prefetch_btf_id, 14);
        assert_eq!(registry.call_off_for_target_name("bpf_memcpy_bulk"), 2);
        assert_eq!(registry.call_off_for_target_name("bpf_prefetch"), 7);
    }

    #[test]
    fn target_json_rejects_unknown_cpu_features() {
        let mut platform = PlatformCapabilities::test_default();

        let err = apply_features(&mut platform, &["cmovv".to_string()]).unwrap_err();

        assert!(
            err.to_string().contains("unknown target feature: cmovv"),
            "err={err:#}"
        );
    }

    #[test]
    fn target_json_rejects_unknown_kinsn_encoding_names() {
        let err = parse_supported_encodings(&SupportedEncodingsJson::Names(vec![
            "packed".to_string(),
            "legacy".to_string(),
        ]))
        .unwrap_err();

        assert!(
            err.to_string()
                .contains("unknown kinsn supported encoding: legacy"),
            "err={err:#}"
        );
    }

    #[test]
    fn pass_report_serializes_map_inline_records_as_hex() {
        let result = PassResult {
            pass_name: "map_inline".to_string(),
            changed: true,
            sites_applied: 1,
            map_inline_records: vec![bpfopt::pass::MapInlineRecord {
                map_id: 7,
                key: vec![1, 0, 0, 0],
                expected_value: vec![0xab, 0xcd],
            }],
            insns_before: 4,
            insns_after: 2,
            ..PassResult::default()
        };

        let report = serde_json::to_value(pass_report(&result)).unwrap();

        assert_eq!(report["map_inline_records"][0]["map_id"], 7);
        assert_eq!(report["map_inline_records"][0]["key_hex"], "01000000");
        assert_eq!(report["map_inline_records"][0]["value_hex"], "abcd");
    }

    #[test]
    fn verifier_states_json_builds_const_prop_delta_states() {
        let state = kernel_sys::VerifierInsnJson {
            pc: 5,
            frame: 0,
            regs: std::collections::BTreeMap::from([(
                "r1".to_string(),
                VerifierRegJson {
                    reg_type: "scalar".to_string(),
                    offset: None,
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
