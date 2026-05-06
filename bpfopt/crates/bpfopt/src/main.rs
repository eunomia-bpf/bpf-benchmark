// SPDX-License-Identifier: MIT
//! bpfopt CLI entry point.

use std::collections::{BTreeMap, HashMap, HashSet};
use std::fs;
use std::io::{self, Read, Write};
use std::path::{Path, PathBuf};
use std::process::ExitCode;

use anyhow::{anyhow, bail, Context, Result};
use bpfopt::analysis::{BranchTargetAnalysis, CFGAnalysis, LivenessAnalysis};
use bpfopt::insn::BpfInsn;
use bpfopt::pass::{
    Arch, BpfProgram, BranchProfile, BtfInfoRecords, KinsnRegistry, MapMetadata, PassContext,
    PassManager, PassResult, PlatformCapabilities, ProfilingData, RegState, ScalarRange,
    StackState, Tnum, VerifierInsn, VerifierInsnKind, VerifierValueWidth,
};
use bpfopt::passes::{MapInfoAnalysis, PASS_REGISTRY};
use clap::{Args, Parser, Subcommand};
use kernel_sys::{VerifierRegJson, VerifierStackJson};
use serde::{Deserialize, Serialize};

const PASS_ALIASES: &[(&str, &str)] = &[
    ("noop", "noop"),
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
    ("bpf_rotate32", "bpf_rotate32"),
    ("rotate32", "bpf_rotate32"),
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
    /// Single pass to run. bpfopt intentionally has no built-in pass pipeline.
    #[arg(long, value_name = "NAME")]
    pass: Option<String>,
    #[command(subcommand)]
    command: Option<Command>,
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
    /// bpftool map snapshot directory.
    #[arg(long, global = true, value_name = "DIR")]
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
    /// List available optimization passes.
    #[command(name = "list-passes")]
    ListPasses(ListPassesArgs),
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
    sites_applied: usize,
    sites_matched: usize,
    sites_skipped: usize,
    skip_reasons: BTreeMap<String, usize>,
    diagnostics: Vec<String>,
    insn_count_before: usize,
    insn_count_after: usize,
    insn_delta: isize,
    #[serde(skip_serializing_if = "Vec::is_empty")]
    inlined_map_entries: Vec<InlinedMapEntryReport>,
}

#[derive(Clone, Debug, Serialize)]
struct InlinedMapEntryReport {
    map_id: u32,
    key_hex: String,
    value_hex: String,
}

#[derive(Clone, Debug, Serialize)]
struct ListPassEntry {
    name: &'static str,
    canonical_name: &'static str,
    description: &'static str,
    needs_target: bool,
    needs_verifier_states: bool,
    produces_verifier_states: bool,
    needs_map_values: bool,
    kinsns_used: &'static [bpfopt::passes::KinsnRef],
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
    call_offset: i16,
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
struct BpftoolMapShowJson {
    id: u32,
    #[serde(default)]
    name: String,
    #[serde(rename = "type")]
    map_type: MapTypeJson,
    flags: BpftoolNumberJson,
    bytes_key: u32,
    bytes_value: u32,
    max_entries: u32,
}

#[derive(Debug, Deserialize)]
struct BpftoolMapEntryJson {
    key: Vec<String>,
    #[serde(default)]
    value: Option<BpftoolMapValueJson>,
    #[serde(default)]
    values: Vec<BpftoolPerCpuValueJson>,
    #[serde(default)]
    inner_map_id: Option<u32>,
}

#[derive(Debug, Deserialize)]
#[serde(deny_unknown_fields)]
struct BpftoolMapDumpSkipMarker {
    skipped: bool,
    reason: String,
    size_bytes: u64,
    limit_bytes: u64,
}

enum BpftoolMapDumpSnapshot {
    Entries(Vec<BpftoolMapEntryJson>),
    SkippedBySize,
}

#[derive(Debug, Deserialize)]
struct BpftoolPerCpuValueJson {
    value: Vec<String>,
}

#[derive(Debug, Deserialize)]
#[serde(untagged)]
enum BpftoolMapValueJson {
    Bytes(Vec<String>),
    Error { error: String },
}

#[derive(Debug, Deserialize)]
#[serde(untagged)]
enum BpftoolNumberJson {
    Number(u64),
    String(String),
}

#[derive(Debug, Deserialize)]
#[serde(untagged)]
enum MapTypeJson {
    Number(u32),
    Name(String),
}

fn main() -> ExitCode {
    match run_main() {
        Ok(()) => ExitCode::SUCCESS,
        Err(err) => {
            eprintln!("error: {err:#}");
            ExitCode::from(1)
        }
    }
}

fn run_main() -> Result<()> {
    let cli = Cli::parse();

    match cli.command {
        Some(Command::ListPasses(args)) => {
            if cli.pass.is_some() {
                bail!("--pass cannot be used with list-passes");
            }
            list_passes(&cli.common, &args)
        }
        None => {
            let pass = cli
                .pass
                .as_deref()
                .ok_or_else(|| anyhow!("bpfopt requires --pass <name> or list-passes"))?;
            run_single_pass(&cli.common, canonicalize_pass_name(pass)?)
        }
    }
}

fn list_passes(common: &CommonArgs, args: &ListPassesArgs) -> Result<()> {
    if args.json {
        let entries = PASS_REGISTRY
            .iter()
            .map(|entry| ListPassEntry {
                name: cli_name_for_pass(entry.name),
                canonical_name: entry.name,
                description: entry.description,
                needs_target: entry.metadata.needs_target(),
                needs_verifier_states: entry.metadata.needs_verifier_states(),
                produces_verifier_states: entry.metadata.produces_verifier_states(),
                needs_map_values: entry.metadata.needs_map_values(),
                kinsns_used: entry.metadata.kinsns_used,
            })
            .collect::<Vec<_>>();
        write_json(common.output.as_deref(), &entries)
    } else {
        let mut out = open_text_output(common.output.as_deref())?;
        for entry in PASS_REGISTRY {
            writeln!(out, "{}", cli_name_for_pass(entry.name))?;
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
    let result = pipeline.run_with_profiling(&mut program, &ctx, profiling.as_ref())?;
    write_bytecode(common.output.as_deref(), &program.insns)?;
    write_btf_info_outputs(common, &program)?;

    if let Some(report_path) = common.report.as_deref() {
        if result.pass_results.len() != 1 {
            bail!(
                "requested pass {pass_name} returned {} pass reports",
                result.pass_results.len()
            );
        }
        let report = pass_report(&result.pass_results[0]);
        write_json(Some(report_path), &report)?;
    }

    Ok(())
}

fn public_kinsn_name(target_name: &str) -> &str {
    match target_name {
        "bpf_memcpy_bulk" => "bpf_bulk_memcpy",
        "bpf_memset_bulk" => "bpf_bulk_memset",
        "bpf_endian_load16" | "bpf_endian_load32" | "bpf_endian_load64" => "bpf_endian_load64",
        _ => target_name,
    }
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
        "noop" => "noop",
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
        let entry = registry_entry(pass_name)?;
        let label = cli_name_for_pass(pass_name);
        if entry.metadata.needs_target() && common.target.is_none() && common.kinsns.is_empty() {
            bail!("{label} requires --target or --kinsns");
        }
        if pass_name == "branch_flip" && common.profile.is_none() {
            bail!("branch-flip requires --profile");
        }
        if entry.metadata.needs_map_values() {
            if common.verifier_states.is_none()
                || common.map_values.is_none()
                || common.map_ids.is_empty()
            {
                bail!("{label} requires --verifier-states, --map-values, and --map-ids");
            }
        } else if entry.metadata.needs_verifier_states() && common.verifier_states.is_none() {
            bail!("{label} requires --verifier-states");
        }
    }
    Ok(())
}

fn validate_required_kinsns(ctx: &PassContext, pass_names: &[&str]) -> Result<()> {
    for &pass_name in pass_names {
        match pass_name {
            "rotate" => require_all_kinsns(ctx, &["bpf_rotate64", "bpf_rotate32"], "rotate")?,
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
        let snapshot = read_map_values(path, &program.map_ids)?;
        program.map_metadata = snapshot.metadata;
        program.map_values = snapshot.values;
        program.map_inner_map_ids = snapshot.inner_map_ids;
        program.map_bpf_writable = snapshot.bpf_writable;
        program.map_snapshots_skipped_by_size = snapshot.maps_skipped_by_size;
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
            _ => eprintln!("bpfopt: warning: ignoring unknown target feature: {feature}"),
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
        registry
            .target_call_offsets
            .insert(canonical.to_string(), spec.call_offset);
    }
    Ok(registry)
}

fn unavailable_kinsn_registry() -> KinsnRegistry {
    KinsnRegistry {
        rotate64_btf_id: -1,
        rotate32_btf_id: -1,
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
        "bpf_rotate32" => registry.rotate32_btf_id = btf_id,
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
    let log = fs::read_to_string(path)
        .with_context(|| format!("failed to read verifier log from {}", path.display()))?;
    let states = kernel_sys::verifier_states_from_log(&log);
    if states.insns.is_empty() {
        bail!(
            "verifier log {} did not contain parseable state snapshots",
            path.display()
        );
    }
    states
        .insns
        .into_iter()
        .map(|insn| {
            let regs = insn
                .regs
                .into_iter()
                .map(|(reg, state)| Ok((parse_reg_name(&reg)?, verifier_reg_state(state)?)))
                .collect::<Result<HashMap<_, _>>>()?;
            let stack = insn
                .stack
                .into_iter()
                .map(|(off, state)| Ok((parse_stack_name(&off)?, verifier_stack_state(state)?)))
                .collect::<Result<HashMap<_, _>>>()?;
            Ok(VerifierInsn {
                pc: insn.pc,
                frame: insn.frame,
                from_pc: None,
                kind: verifier_insn_kind(insn.kind.as_deref())?,
                speculative: false,
                regs,
                stack,
            })
        })
        .collect()
}

fn verifier_insn_kind(kind: Option<&str>) -> Result<VerifierInsnKind> {
    match kind.unwrap_or("insn_delta_state") {
        "edge_full_state" => Ok(VerifierInsnKind::EdgeFullState),
        "pc_full_state" => Ok(VerifierInsnKind::PcFullState),
        "branch_delta_state" => Ok(VerifierInsnKind::BranchDeltaState),
        "insn_delta_state" => Ok(VerifierInsnKind::InsnDeltaState),
        other => bail!("invalid verifier state kind: {other}"),
    }
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

fn parse_stack_name(off: &str) -> Result<i16> {
    let off = off
        .strip_prefix("fp")
        .or_else(|| off.strip_prefix("FP"))
        .unwrap_or(off);
    let value = off
        .parse::<i16>()
        .with_context(|| format!("invalid stack slot name: {off}"))?;
    if value >= 0 || value % 8 != 0 {
        bail!("invalid BPF stack slot fp{value}");
    }
    Ok(value)
}

fn verifier_stack_state(state: VerifierStackJson) -> Result<StackState> {
    if let Some(slot_types) = &state.slot_types {
        if slot_types.is_empty()
            || slot_types.len() > 8
            || !slot_types
                .chars()
                .all(|ch| matches!(ch, '?' | 'r' | 'm' | '0' | 'd' | 'i' | 'f'))
        {
            bail!("invalid verifier stack slot type string: {slot_types}");
        }
    }
    Ok(StackState {
        slot_types: state.slot_types,
        value: state.value.map(verifier_reg_state).transpose()?,
    })
}

fn verifier_reg_state(state: VerifierRegJson) -> Result<RegState> {
    let exact_value = state.const_val.map(|value| value as u64);
    let tnum = state.tnum.as_deref().map(parse_tnum).transpose()?;
    Ok(RegState {
        reg_type: state.reg_type,
        value_width: VerifierValueWidth::Unknown,
        precise: state.precise.unwrap_or(false),
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
    inner_map_ids: HashMap<(u32, Vec<u8>), u32>,
    bpf_writable: HashMap<u32, bool>,
    maps_skipped_by_size: HashSet<u32>,
}

fn read_map_values(path: &Path, map_ids: &[u32]) -> Result<MapSnapshot> {
    if !path.is_dir() {
        bail!(
            "--map-values must point to a bpftool snapshot directory, got {}",
            path.display()
        );
    }
    let mut metadata = HashMap::new();
    let mut values = HashMap::new();
    let mut inner_map_ids = HashMap::new();
    let mut bpf_writable = HashMap::new();
    let mut maps_skipped_by_size = HashSet::new();

    for &map_id in map_ids.iter().filter(|&&map_id| map_id != 0) {
        let show = read_bpftool_map_show(path, map_id)?;
        let map_type = parse_map_type(&show.map_type)?;
        let flags = parse_bpftool_number(&show.flags)?;
        let map_metadata = MapMetadata {
            map_type,
            key_size: show.bytes_key,
            value_size: show.bytes_value,
            max_entries: show.max_entries,
            map_id: show.id,
            name: show.name,
        };
        bpf_writable.insert(show.id, flags & bpf_f_rdonly_prog() == 0);
        if needs_bpftool_map_dump(map_type) {
            match read_bpftool_map_dump(path, show.id)? {
                BpftoolMapDumpSnapshot::Entries(entries) => {
                    for entry in entries {
                        let key = decode_bpftool_hex_bytes(&entry.key)
                            .with_context(|| format!("invalid key bytes for map {}", show.id))?;
                        let value = decode_bpftool_entry_value(&entry, &map_metadata)
                            .with_context(|| format!("invalid value bytes for map {}", show.id))?;
                        values.insert((show.id, key.clone()), value);
                        if let Some(inner_map_id) = entry.inner_map_id {
                            inner_map_ids.insert((show.id, key), inner_map_id);
                        }
                    }
                }
                BpftoolMapDumpSnapshot::SkippedBySize => {
                    maps_skipped_by_size.insert(show.id);
                }
            }
        }
        metadata.insert(show.id, map_metadata);
    }

    Ok(MapSnapshot {
        metadata,
        values,
        inner_map_ids,
        bpf_writable,
        maps_skipped_by_size,
    })
}

fn read_bpftool_map_show(path: &Path, map_id: u32) -> Result<BpftoolMapShowJson> {
    let show_path = bpftool_map_show_path(path, map_id);
    let show: BpftoolMapShowJson = read_json_file(&show_path, "bpftool map show JSON")?;
    if show.id != map_id {
        bail!(
            "{} contains map id {}, expected {}",
            show_path.display(),
            show.id,
            map_id
        );
    }
    Ok(show)
}

fn read_bpftool_map_dump(path: &Path, map_id: u32) -> Result<BpftoolMapDumpSnapshot> {
    let dump_path = bpftool_map_dump_path(path, map_id);
    let data =
        fs::read(&dump_path).with_context(|| format!("failed to read {}", dump_path.display()))?;
    let Some(first) = data
        .iter()
        .copied()
        .find(|byte| !byte.is_ascii_whitespace())
    else {
        bail!("{} is empty", dump_path.display());
    };

    match first {
        b'[' => {
            let entries = serde_json::from_slice(&data).with_context(|| {
                format!(
                    "failed to parse bpftool map dump JSON from {}",
                    dump_path.display()
                )
            })?;
            Ok(BpftoolMapDumpSnapshot::Entries(entries))
        }
        b'{' => {
            let marker: BpftoolMapDumpSkipMarker =
                serde_json::from_slice(&data).with_context(|| {
                    format!(
                        "failed to parse bpftool map dump skip marker from {}",
                        dump_path.display()
                    )
                })?;
            if !marker.skipped
                || marker.reason != "size_limit"
                || marker.size_bytes <= marker.limit_bytes
            {
                bail!(
                    "unexpected bpftool map dump skip marker in {}",
                    dump_path.display()
                );
            }
            Ok(BpftoolMapDumpSnapshot::SkippedBySize)
        }
        _ => bail!(
            "{} is neither a bpftool map dump array nor a skip marker object",
            dump_path.display()
        ),
    }
}

fn bpftool_map_show_path(path: &Path, map_id: u32) -> PathBuf {
    path.join(format!("map-{map_id}.show.json"))
}

fn bpftool_map_dump_path(path: &Path, map_id: u32) -> PathBuf {
    path.join(format!("map-{map_id}.dump.json"))
}

fn parse_bpftool_number(value: &BpftoolNumberJson) -> Result<u64> {
    match value {
        BpftoolNumberJson::Number(number) => Ok(*number),
        BpftoolNumberJson::String(text) => parse_u64_auto_radix(text),
    }
}

fn decode_bpftool_entry_value(
    entry: &BpftoolMapEntryJson,
    metadata: &MapMetadata,
) -> Result<Vec<u8>> {
    if !entry.values.is_empty() {
        return decode_bpftool_percpu_values(&entry.values, metadata.value_size as usize);
    }
    let Some(value) = &entry.value else {
        bail!("bpftool entry has neither value nor per-CPU values");
    };
    match value {
        BpftoolMapValueJson::Bytes(bytes) => decode_bpftool_hex_bytes(bytes),
        BpftoolMapValueJson::Error { error } => {
            bail!("bpftool map dump returned lookup error: {error}")
        }
    }
}

fn decode_bpftool_percpu_values(
    values: &[BpftoolPerCpuValueJson],
    value_size: usize,
) -> Result<Vec<u8>> {
    let stride = round_up_8(value_size);
    let mut out = Vec::with_capacity(values.len().saturating_mul(stride));
    for value in values {
        let bytes = decode_bpftool_hex_bytes(&value.value)?;
        if bytes.len() != value_size {
            bail!(
                "per-CPU value has {} byte(s), expected {}",
                bytes.len(),
                value_size
            );
        }
        out.extend_from_slice(&bytes);
        out.resize(out.len() + (stride - value_size), 0);
    }
    Ok(out)
}

fn decode_bpftool_hex_bytes(input: &[String]) -> Result<Vec<u8>> {
    input
        .iter()
        .map(|byte| {
            let byte = byte.trim();
            let hex = byte.strip_prefix("0x").unwrap_or(byte);
            u8::from_str_radix(hex, 16).with_context(|| format!("invalid bpftool byte {byte:?}"))
        })
        .collect()
}

fn bpf_f_rdonly_prog() -> u64 {
    1 << 7
}

fn needs_bpftool_map_dump(map_type: u32) -> bool {
    matches!(
        map_type,
        kernel_sys::BPF_MAP_TYPE_HASH
            | kernel_sys::BPF_MAP_TYPE_ARRAY
            | kernel_sys::BPF_MAP_TYPE_PERCPU_ARRAY
            | kernel_sys::BPF_MAP_TYPE_LRU_HASH
            | kernel_sys::BPF_MAP_TYPE_ARRAY_OF_MAPS
            | kernel_sys::BPF_MAP_TYPE_HASH_OF_MAPS
    )
}

fn round_up_8(value: usize) -> usize {
    (value + 7) & !7
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
                "prog_array" => Ok(kernel_sys::BPF_MAP_TYPE_PROG_ARRAY),
                "perf_event_array" => Ok(kernel_sys::BPF_MAP_TYPE_PERF_EVENT_ARRAY),
                "percpu_hash" | "per_cpu_hash" => Ok(kernel_sys::BPF_MAP_TYPE_PERCPU_HASH),
                "percpu_array" | "per_cpu_array" => Ok(kernel_sys::BPF_MAP_TYPE_PERCPU_ARRAY),
                "stack_trace" => Ok(kernel_sys::BPF_MAP_TYPE_STACK_TRACE),
                "cgroup_array" => Ok(kernel_sys::BPF_MAP_TYPE_CGROUP_ARRAY),
                "lru_hash" => Ok(kernel_sys::BPF_MAP_TYPE_LRU_HASH),
                "lru_percpu_hash" | "lru_per_cpu_hash" => {
                    Ok(kernel_sys::BPF_MAP_TYPE_LRU_PERCPU_HASH)
                }
                "lpm_trie" => Ok(kernel_sys::BPF_MAP_TYPE_LPM_TRIE),
                "array_of_maps" => Ok(kernel_sys::BPF_MAP_TYPE_ARRAY_OF_MAPS),
                "hash_of_maps" => Ok(kernel_sys::BPF_MAP_TYPE_HASH_OF_MAPS),
                "devmap" => Ok(kernel_sys::BPF_MAP_TYPE_DEVMAP),
                "devmap_hash" => Ok(kernel_sys::BPF_MAP_TYPE_DEVMAP_HASH),
                "sockmap" => Ok(kernel_sys::BPF_MAP_TYPE_SOCKMAP),
                "cpumap" => Ok(kernel_sys::BPF_MAP_TYPE_CPUMAP),
                "xskmap" => Ok(kernel_sys::BPF_MAP_TYPE_XSKMAP),
                "sockhash" => Ok(kernel_sys::BPF_MAP_TYPE_SOCKHASH),
                "cgroup_storage" => Ok(kernel_sys::BPF_MAP_TYPE_CGROUP_STORAGE),
                "reuseport_sockarray" => Ok(kernel_sys::BPF_MAP_TYPE_REUSEPORT_SOCKARRAY),
                "percpu_cgroup_storage" | "per_cpu_cgroup_storage" => {
                    Ok(kernel_sys::BPF_MAP_TYPE_PERCPU_CGROUP_STORAGE)
                }
                "queue" => Ok(kernel_sys::BPF_MAP_TYPE_QUEUE),
                "stack" => Ok(kernel_sys::BPF_MAP_TYPE_STACK),
                "sk_storage" => Ok(kernel_sys::BPF_MAP_TYPE_SK_STORAGE),
                "struct_ops" => Ok(kernel_sys::BPF_MAP_TYPE_STRUCT_OPS),
                "ringbuf" => Ok(kernel_sys::BPF_MAP_TYPE_RINGBUF),
                "inode_storage" => Ok(kernel_sys::BPF_MAP_TYPE_INODE_STORAGE),
                "task_storage" => Ok(kernel_sys::BPF_MAP_TYPE_TASK_STORAGE),
                "bloom_filter" => Ok(kernel_sys::BPF_MAP_TYPE_BLOOM_FILTER),
                "user_ringbuf" => Ok(kernel_sys::BPF_MAP_TYPE_USER_RINGBUF),
                "cgrp_storage" => Ok(kernel_sys::BPF_MAP_TYPE_CGRP_STORAGE),
                "arena" => Ok(kernel_sys::BPF_MAP_TYPE_ARENA),
                "insn_array" => Ok(kernel_sys::BPF_MAP_TYPE_INSN_ARRAY),
                _ => bail!("unsupported map_type: {name}"),
            }
        }
    }
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
    let mut skip_reasons = BTreeMap::new();
    for skip in &result.sites_skipped {
        *skip_reasons.entry(skip.reason.clone()).or_insert(0) += 1;
    }
    PassReport {
        pass: result.pass_name.clone(),
        sites_applied: result.sites_applied,
        sites_matched: result.sites_applied + result.sites_skipped.len(),
        sites_skipped: result.sites_skipped.len(),
        skip_reasons,
        diagnostics: result.diagnostics.clone(),
        insn_count_before: result.insns_before,
        insn_count_after: result.insns_after,
        insn_delta: result.insns_after as isize - result.insns_before as isize,
        inlined_map_entries: result
            .map_inline_records
            .iter()
            .map(inlined_map_entry_report)
            .collect(),
    }
}

fn inlined_map_entry_report(record: &bpfopt::pass::MapInlineRecord) -> InlinedMapEntryReport {
    InlinedMapEntryReport {
        map_id: record.map_id,
        key_hex: hex_bytes(&record.key),
        value_hex: hex_bytes(&record.value),
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
    fn target_json_maps_v3_kinsn_aliases_to_registry_fields() {
        let target = TargetJson {
            arch: Some("x86_64".to_string()),
            features: vec!["cmov".to_string(), "movbe".to_string()],
            kinsns: HashMap::from([
                (
                    "rotate32".to_string(),
                    KinsnJson {
                        btf_func_id: 10,
                        call_offset: 1,
                    },
                ),
                (
                    "bpf_bulk_memcpy".to_string(),
                    KinsnJson {
                        btf_func_id: 11,
                        call_offset: 2,
                    },
                ),
                (
                    "bpf_endian_load64".to_string(),
                    KinsnJson {
                        btf_func_id: 12,
                        call_offset: 0,
                    },
                ),
                (
                    "bpf_ccmp64".to_string(),
                    KinsnJson {
                        btf_func_id: 13,
                        call_offset: 0,
                    },
                ),
                (
                    "bpf_prefetch".to_string(),
                    KinsnJson {
                        btf_func_id: 14,
                        call_offset: 7,
                    },
                ),
            ]),
        };

        let registry = kinsn_registry_from_target(&target).unwrap();
        assert_eq!(registry.rotate32_btf_id, 10);
        assert_eq!(registry.memcpy_bulk_btf_id, 11);
        assert_eq!(registry.endian_load64_btf_id, 12);
        assert_eq!(registry.ccmp64_btf_id, 13);
        assert_eq!(registry.prefetch_btf_id, 14);
        assert_eq!(registry.call_off_for_target_name("bpf_rotate32"), 1);
        assert_eq!(registry.call_off_for_target_name("bpf_memcpy_bulk"), 2);
        assert_eq!(registry.call_off_for_target_name("bpf_prefetch"), 7);
    }

    #[test]
    fn target_json_requires_call_offset_for_each_kinsn() {
        let err = serde_json::from_str::<TargetJson>(
            r#"{
              "arch": "x86_64",
              "kinsns": {
                "bpf_extract64": { "btf_func_id": 129876 }
              }
            }"#,
        )
        .unwrap_err();

        assert!(err.to_string().contains("call_offset"), "err={err}");
    }

    #[test]
    fn pass_report_serializes_inlined_map_entries_as_hex() {
        let result = PassResult {
            pass_name: "map_inline".to_string(),
            sites_applied: 1,
            map_inline_records: vec![bpfopt::pass::MapInlineRecord {
                map_id: 7,
                key: vec![1, 0, 0, 0],
                value: vec![42, 0, 0, 0],
            }],
            insns_before: 4,
            insns_after: 2,
            ..PassResult::default()
        };

        let report = serde_json::to_value(pass_report(&result)).unwrap();

        assert_eq!(report["inlined_map_entries"][0]["map_id"], 7);
        assert_eq!(report["inlined_map_entries"][0]["key_hex"], "01000000");
        assert_eq!(report["inlined_map_entries"][0]["value_hex"], "2a000000");
    }

    #[test]
    fn read_map_values_accepts_bpftool_map_in_map_snapshot() {
        let dir =
            std::env::temp_dir().join(format!("bpfopt-bpftool-map-values-{}", std::process::id()));
        let _ = std::fs::remove_dir_all(&dir);
        std::fs::create_dir(&dir).unwrap();
        std::fs::write(
            bpftool_map_show_path(&dir, 90),
            r#"{
              "id": 90,
              "type": "hash_of_maps",
              "name": "outer",
              "flags": 128,
              "bytes_key": 4,
              "bytes_value": 4,
              "max_entries": 8
            }"#,
        )
        .unwrap();
        std::fs::write(
            bpftool_map_dump_path(&dir, 90),
            r#"[{
              "key": ["0x01", "0x00", "0x00", "0x00"],
              "value": ["0x5b", "0x00", "0x00", "0x00"],
              "inner_map_id": 91
            }]"#,
        )
        .unwrap();

        let snapshot = read_map_values(&dir, &[90]).unwrap();
        let _ = std::fs::remove_dir_all(&dir);

        assert_eq!(
            snapshot.metadata[&90].map_type,
            kernel_sys::BPF_MAP_TYPE_HASH_OF_MAPS
        );
        assert_eq!(
            snapshot.inner_map_ids[&(90, 1u32.to_le_bytes().to_vec())],
            91
        );
        assert_eq!(snapshot.bpf_writable[&90], false);
        assert_eq!(
            snapshot.values[&(90, 1u32.to_le_bytes().to_vec())],
            91u32.to_le_bytes().to_vec()
        );
    }

    #[test]
    fn read_map_values_accepts_size_skip_marker() {
        let dir = std::env::temp_dir().join(format!(
            "bpfopt-bpftool-map-values-size-skip-{}",
            std::process::id()
        ));
        let _ = std::fs::remove_dir_all(&dir);
        std::fs::create_dir(&dir).unwrap();
        std::fs::write(
            bpftool_map_show_path(&dir, 91),
            r#"{
              "id": 91,
              "type": "array",
              "name": "oversized",
              "flags": 0,
              "bytes_key": 4,
              "bytes_value": 8,
              "max_entries": 4096
            }"#,
        )
        .unwrap();
        std::fs::write(
            bpftool_map_dump_path(&dir, 91),
            r#"{"skipped":true,"reason":"size_limit","size_bytes":65537,"limit_bytes":65536}"#,
        )
        .unwrap();

        let snapshot = read_map_values(&dir, &[91]).unwrap();
        let _ = std::fs::remove_dir_all(&dir);

        assert!(snapshot.maps_skipped_by_size.contains(&91));
        assert!(snapshot.values.is_empty());
        assert_eq!(
            snapshot.metadata[&91].map_type,
            kernel_sys::BPF_MAP_TYPE_ARRAY
        );
    }

    #[test]
    fn read_map_values_rejects_unexpected_size_skip_marker() {
        let dir = std::env::temp_dir().join(format!(
            "bpfopt-bpftool-map-values-bad-skip-{}",
            std::process::id()
        ));
        let _ = std::fs::remove_dir_all(&dir);
        std::fs::create_dir(&dir).unwrap();
        std::fs::write(
            bpftool_map_show_path(&dir, 92),
            r#"{
              "id": 92,
              "type": "array",
              "name": "bad_marker",
              "flags": 0,
              "bytes_key": 4,
              "bytes_value": 8,
              "max_entries": 4096
            }"#,
        )
        .unwrap();
        std::fs::write(
            bpftool_map_dump_path(&dir, 92),
            r#"{"skipped":true,"reason":"unknown","size_bytes":65537,"limit_bytes":65536}"#,
        )
        .unwrap();

        let err = match read_map_values(&dir, &[92]) {
            Ok(_) => panic!("unexpectedly accepted malformed size-skip marker"),
            Err(err) => err,
        };
        let _ = std::fs::remove_dir_all(&dir);

        assert!(
            err.to_string()
                .contains("unexpected bpftool map dump skip marker"),
            "err={err:#}"
        );
    }

    #[test]
    fn verifier_states_json_builds_const_prop_delta_states() {
        let state = kernel_sys::VerifierInsnJson {
            pc: 5,
            frame: 0,
            kind: None,
            stack: BTreeMap::new(),
            regs: std::collections::BTreeMap::from([(
                "r1".to_string(),
                VerifierRegJson {
                    reg_type: "scalar".to_string(),
                    precise: Some(false),
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
        assert!(!regs[&1].precise);
        assert_eq!(regs[&1].tnum.unwrap().value, 42);
    }

    #[test]
    fn verifier_states_log_builds_stack_states() {
        let path = std::env::temp_dir().join(format!(
            "bpfopt-verifier-states-{}-{}.log",
            std::process::id(),
            std::time::SystemTime::now()
                .duration_since(std::time::UNIX_EPOCH)
                .unwrap()
                .as_nanos()
        ));
        fs::write(&path, "9: R2=fp-16 fp-16=rrrrrrrr P42\n").unwrap();

        let states = read_verifier_states(&path).unwrap();
        assert_eq!(states.len(), 1);
        assert_eq!(states[0].regs[&2].offset, Some(-16));
        let stack = states[0].stack.get(&-16).unwrap();
        assert_eq!(stack.slot_types.as_deref(), Some("rrrrrrrr"));
        let value = stack.value.as_ref().unwrap();
        assert_eq!(value.exact_value, Some(42));
        assert!(value.precise);
        fs::remove_file(path).unwrap();
    }

    #[test]
    fn verifier_states_log_preserves_full_state_kind() {
        let path = std::env::temp_dir().join(format!(
            "bpfopt-verifier-kind-{}-{}.log",
            std::process::id(),
            std::time::SystemTime::now()
                .duration_since(std::time::UNIX_EPOCH)
                .unwrap()
                .as_nanos()
        ));
        fs::write(&path, "from 8 to 11: R2=fp-4 fp-8=rrrr???? P4294967296\n").unwrap();

        let states = read_verifier_states(&path).unwrap();
        assert_eq!(states.len(), 1);
        assert_eq!(states[0].kind, VerifierInsnKind::EdgeFullState);
        assert_eq!(states[0].regs[&2].reg_type, "fp");
        assert!(states[0].stack.contains_key(&-8));
        fs::remove_file(path).unwrap();
    }
}
