// SPDX-License-Identifier: MIT
//! bpfopt CLI entry point.

use std::collections::BTreeMap;
use std::fs;
use std::io::{self, Read, Write};
use std::path::{Path, PathBuf};
use std::process::ExitCode;

use anyhow::{anyhow, bail, Context, Result};
use bpfopt::analysis::{lift_with_pass_context, lower, BBProgram};
use bpfopt::insn::BpfInsn;
use bpfopt::pass::{
    hex_bytes, report_site_pc, run_pass_once, Arch, BtfInfoRecords, CommonArgs, KinsnRegistry,
    PassContext, PassResult, PlatformCapabilities, TargetJson,
};
use bpfopt::passes::PASS_REGISTRY;
use clap::Parser;
use serde::{Deserialize, Serialize};

#[derive(Parser)]
#[command(name = "bpfopt", version, about = "BPF bytecode optimizer")]
struct Cli {
    #[command(flatten)]
    common: CommonArgs,
    /// Single pass to run. bpfopt intentionally has no built-in pass pipeline.
    #[arg(long, value_name = "NAME")]
    pass: Option<String>,
    /// Canonicalize map references from loader FD form to stable map-index form.
    #[arg(long)]
    canonicalize_map_refs: bool,
    /// Program map IDs in kernel used_maps order, comma-separated.
    #[arg(long, value_name = "IDS", value_delimiter = ',')]
    map_ids: Vec<u32>,
    /// Output target platform JSON file after canonicalization-time rewrites.
    #[arg(long, value_name = "FILE")]
    target_output: Option<PathBuf>,
    /// Pass-local args. Must follow `--` and are parsed by the selected pass.
    #[arg(last = true, num_args = 0.., allow_hyphen_values = true)]
    pass_args: Vec<String>,
}

#[derive(Clone, Debug, Serialize)]
struct PassReport {
    pass: String,
    sites_applied: usize,
    sites_matched: usize,
    sites_skipped: usize,
    skip_reasons: BTreeMap<String, usize>,
    #[serde(skip_serializing_if = "Vec::is_empty")]
    skipped_sites: Vec<SkippedSiteReport>,
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
struct SkippedSiteReport {
    pc: u64,
    reason: String,
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

    if cli.canonicalize_map_refs {
        if cli.pass.is_some() {
            bail!("--canonicalize-map-refs cannot be combined with --pass");
        }
        if !cli.pass_args.is_empty() {
            bail!("pass-local args require --pass <name>");
        }
        return run_canonicalize_map_refs(&cli.common, &cli.map_ids, cli.target_output.as_deref());
    }
    if !cli.map_ids.is_empty() {
        bail!("--map-ids requires --canonicalize-map-refs or a pass-local use after --");
    }
    if cli.target_output.is_some() {
        bail!("--target-output requires --canonicalize-map-refs");
    }

    let pass = cli
        .pass
        .as_deref()
        .ok_or_else(|| anyhow!("bpfopt requires --pass <name>"))?;
    run_single_pass(&cli.common, lookup_pass_name(pass)?, &cli.pass_args)
}

fn run_canonicalize_map_refs(
    common: &CommonArgs,
    map_ids: &[u32],
    target_output: Option<&Path>,
) -> Result<()> {
    if common.report.is_some() {
        bail!("--canonicalize-map-refs does not produce --report");
    }
    match (common.target.as_deref(), target_output) {
        (Some(_), Some(_)) | (None, None) => {}
        (Some(_), None) => bail!("--canonicalize-map-refs --target requires --target-output"),
        (None, Some(_)) => bail!("--target-output requires --target"),
    }
    let mut insns = read_bytecode(common.input.as_deref())?;
    bpfopt::analysis::canonicalize_map_refs_to_idx(&mut insns, None, map_ids)?;
    if let (Some(target), Some(target_output)) = (common.target.as_deref(), target_output) {
        let mut target_json: TargetJson = read_json_file(target, "target.json")?;
        bpfopt::analysis::shift_target_module_call_offsets_for_map_prefix(
            &mut target_json,
            map_ids.len(),
        )?;
        write_json(Some(target_output), &target_json)?;
    }
    write_bytecode(common.output.as_deref(), &insns)
}

fn run_single_pass(
    common: &CommonArgs,
    pass_name: &'static str,
    pass_args: &[String],
) -> Result<()> {
    validate_required_side_inputs(common, &[pass_name])?;

    let input = read_bytecode(common.input.as_deref())?;
    let mut ctx = build_pass_context(common)?;
    let pass_constructor_args: &[String] = if pass_name == "map_inline" {
        bpfopt::passes::map_inline::attach_cli_side_input(&mut ctx, pass_args)?;
        &[]
    } else {
        pass_args
    };
    validate_required_kinsns(&ctx, &[pass_name])?;
    let mut program = lift_with_pass_context(&input, &ctx)?;
    let report_program = common.report.is_some().then(|| program.clone());
    let entry = registry_entry(pass_name)?;
    let pass = (entry.make)(pass_constructor_args)?;
    let result = run_pass_once(pass.as_ref(), &mut program, &ctx)?;
    let output = lower(&program)?;
    write_bytecode(common.output.as_deref(), &output)?;
    write_btf_info_outputs(common, &program)?;

    if let (Some(report_path), Some(snapshot)) = (common.report.as_deref(), report_program.as_ref())
    {
        let report = pass_report(pass_name, snapshot, &result)?;
        write_json(Some(report_path), &report)?;
    }

    Ok(())
}

fn registry_entry(name: &str) -> Result<&'static bpfopt::passes::PassRegistryEntry> {
    PASS_REGISTRY
        .iter()
        .find(|entry| entry.name == name)
        .ok_or_else(|| anyhow!("unknown pass name: {name}"))
}

fn lookup_pass_name(input: &str) -> Result<&'static str> {
    Ok(registry_entry(input.trim())?.name)
}

fn validate_required_side_inputs(common: &CommonArgs, pass_names: &[&str]) -> Result<()> {
    for &pass_name in pass_names {
        let entry = registry_entry(pass_name)?;
        if entry.requirements.needs_kinsns() && common.target.is_none() && common.kinsns.is_empty()
        {
            bail!("{pass_name} requires --target kinsn capabilities or --kinsns");
        }
        if entry.requirements.needs_verifier_states() && common.verifier_states.is_none() {
            bail!("{pass_name} requires --verifier-states");
        }
    }
    Ok(())
}

fn validate_required_kinsns(ctx: &PassContext, pass_names: &[&str]) -> Result<()> {
    for &pass_name in pass_names {
        let entry = registry_entry(pass_name)?;
        if !entry.requirements.needs_kinsns()
            || (pass_name == "ccmp" && ctx.platform.arch != Arch::Aarch64)
        {
            continue;
        }
        let target_names = entry.requirements.required_kinsns.iter().copied();
        require_all_kinsns(ctx, target_names, pass_name)?;
    }
    Ok(())
}

fn require_all_kinsns<I>(ctx: &PassContext, target_names: I, pass_label: &str) -> Result<()>
where
    I: IntoIterator<Item = &'static str>,
{
    let missing = target_names
        .into_iter()
        .filter(|target_name| !ctx.kinsn_registry.is_target_available(target_name))
        .collect::<Vec<_>>();
    if missing.is_empty() {
        return Ok(());
    }
    bail!(
        "{pass_label} requires target kinsns: {}",
        missing.join(", ")
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
    bytes
        .chunks_exact(8)
        .map(|chunk| {
            let chunk_array: [u8; 8] = chunk.try_into()?;
            Ok(BpfInsn::from_raw_bytes(chunk_array))
        })
        .collect()
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

fn write_json<T: Serialize>(output: Option<&Path>, value: &T) -> Result<()> {
    let mut out = open_binary_output(output)?;
    serde_json::to_writer_pretty(&mut out, value)?;
    writeln!(out)?;
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

fn write_btf_info_outputs(common: &CommonArgs, program: &BBProgram) -> Result<()> {
    for (path_opt, records, label) in [
        (
            common.func_info.as_deref(),
            program.remapped_func_info_records()?,
            "func-info",
        ),
        (
            common.line_info.as_deref(),
            program.remapped_line_info_records()?,
            "line-info",
        ),
    ] {
        let Some(path) = path_opt else { continue };
        let bytes = records
            .map(|r| r.bytes)
            .ok_or_else(|| anyhow!("--{label} requested but remapped records are unavailable"))?;
        fs::write(path, bytes).with_context(|| format!("failed to write {}", path.display()))?;
    }
    Ok(())
}

fn build_pass_context(common: &CommonArgs) -> Result<PassContext> {
    let mut ctx = PassContext::try_baseline()?;
    ctx.platform = detect_platform();
    if let Some(path) = common.verifier_states.as_deref() {
        let log = fs::read_to_string(path)
            .with_context(|| format!("failed to read verifier states from {}", path.display()))?;
        ctx.set_verifier_states_from_log(&log)
            .with_context(|| format!("verifier states from {}", path.display()))?;
    }
    ctx.func_info = read_btf_info_records(
        common.func_info.as_deref(),
        common.func_info_rec_size,
        "func-info",
    )?;
    ctx.line_info = read_btf_info_records(
        common.line_info.as_deref(),
        common.line_info_rec_size,
        "line-info",
    )?;

    if let Some(platform) = common.platform.as_deref() {
        ctx.platform.arch = parse_arch(platform)?;
    }
    if let Some(prog_type) = common.prog_type.as_deref() {
        ctx.prog_type = parse_prog_type(prog_type)?;
    }

    if let Some(path) = common.target.as_deref() {
        let target: TargetJson = read_json_file(path, "target.json")?;
        if let Some(arch) = target.arch.as_deref() {
            ctx.platform.arch = parse_arch(arch)?;
        }
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
        "socket_filter" => libbpf_sys::BPF_PROG_TYPE_SOCKET_FILTER,
        "kprobe" => libbpf_sys::BPF_PROG_TYPE_KPROBE,
        "sched_cls" => libbpf_sys::BPF_PROG_TYPE_SCHED_CLS,
        "sched_act" => libbpf_sys::BPF_PROG_TYPE_SCHED_ACT,
        "tracepoint" => libbpf_sys::BPF_PROG_TYPE_TRACEPOINT,
        "xdp" => libbpf_sys::BPF_PROG_TYPE_XDP,
        "perf_event" => libbpf_sys::BPF_PROG_TYPE_PERF_EVENT,
        "cgroup_skb" => libbpf_sys::BPF_PROG_TYPE_CGROUP_SKB,
        "cgroup_sock" => libbpf_sys::BPF_PROG_TYPE_CGROUP_SOCK,
        "lwt_in" => libbpf_sys::BPF_PROG_TYPE_LWT_IN,
        "lwt_out" => libbpf_sys::BPF_PROG_TYPE_LWT_OUT,
        "lwt_xmit" => libbpf_sys::BPF_PROG_TYPE_LWT_XMIT,
        "sock_ops" => libbpf_sys::BPF_PROG_TYPE_SOCK_OPS,
        "sk_skb" => libbpf_sys::BPF_PROG_TYPE_SK_SKB,
        "cgroup_device" => libbpf_sys::BPF_PROG_TYPE_CGROUP_DEVICE,
        "sk_msg" => libbpf_sys::BPF_PROG_TYPE_SK_MSG,
        "raw_tracepoint" => libbpf_sys::BPF_PROG_TYPE_RAW_TRACEPOINT,
        "cgroup_sock_addr" => libbpf_sys::BPF_PROG_TYPE_CGROUP_SOCK_ADDR,
        "lwt_seg6local" => libbpf_sys::BPF_PROG_TYPE_LWT_SEG6LOCAL,
        "lirc_mode2" => libbpf_sys::BPF_PROG_TYPE_LIRC_MODE2,
        "sk_reuseport" => libbpf_sys::BPF_PROG_TYPE_SK_REUSEPORT,
        "flow_dissector" => libbpf_sys::BPF_PROG_TYPE_FLOW_DISSECTOR,
        "cgroup_sysctl" => libbpf_sys::BPF_PROG_TYPE_CGROUP_SYSCTL,
        "raw_tracepoint_writable" => libbpf_sys::BPF_PROG_TYPE_RAW_TRACEPOINT_WRITABLE,
        "cgroup_sockopt" => libbpf_sys::BPF_PROG_TYPE_CGROUP_SOCKOPT,
        "tracing" => libbpf_sys::BPF_PROG_TYPE_TRACING,
        "struct_ops" => libbpf_sys::BPF_PROG_TYPE_STRUCT_OPS,
        "ext" => libbpf_sys::BPF_PROG_TYPE_EXT,
        "lsm" => libbpf_sys::BPF_PROG_TYPE_LSM,
        "sk_lookup" => libbpf_sys::BPF_PROG_TYPE_SK_LOOKUP,
        "syscall" => libbpf_sys::BPF_PROG_TYPE_SYSCALL,
        "netfilter" => libbpf_sys::BPF_PROG_TYPE_NETFILTER,
        _ => bail!("unknown prog type '{input}'"),
    };
    Ok(value)
}

fn kinsn_registry_from_target(target: &TargetJson) -> Result<KinsnRegistry> {
    let mut registry = KinsnRegistry::new()?;
    for (name, spec) in &target.kinsns {
        registry.set_kinsn_call_for_target_name(name, spec.btf_func_id, spec.call_offset)?;
    }
    Ok(registry)
}

fn apply_kinsn_list(registry: &mut KinsnRegistry, kinsns: &[String]) -> Result<()> {
    for item in kinsns {
        let trimmed = item.trim();
        if trimmed.is_empty() {
            continue;
        }
        let (name, btf_id) = if let Some((name, btf)) = trimmed.split_once(':') {
            let id = btf
                .parse::<i32>()
                .with_context(|| format!("invalid btf id in --kinsns entry {trimmed}"))?;
            (name, id)
        } else {
            (trimmed, 0)
        };
        registry.set_kinsn_call_for_target_name(name, btf_id, 0)?;
    }
    Ok(())
}

fn read_json_file<T: for<'de> Deserialize<'de>>(path: &Path, label: &str) -> Result<T> {
    let data = fs::read(path).with_context(|| format!("failed to read {}", path.display()))?;
    serde_json::from_slice(&data)
        .with_context(|| format!("failed to parse {label} from {}", path.display()))
}

fn pass_report(pass_name: &str, program: &BBProgram, result: &PassResult) -> Result<PassReport> {
    let mut skip_reasons = BTreeMap::new();
    for skip in &result.site_skipped {
        *skip_reasons.entry(skip.reason.clone()).or_insert(0) += 1;
    }
    let mut diagnostics = result.diagnostics.clone();
    diagnostics.extend(site_diagnostic_reports(program, &result.site_diagnostics)?);
    let skipped_sites = site_skip_reports(program, &result.site_skipped)?;
    Ok(PassReport {
        pass: pass_name.to_string(),
        sites_applied: result.sites_applied,
        sites_matched: result.sites_applied + result.site_skipped.len(),
        sites_skipped: result.site_skipped.len(),
        skip_reasons,
        skipped_sites,
        diagnostics,
        insn_count_before: result.insns_before,
        insn_count_after: result.insns_after,
        insn_delta: result.insns_after as isize - result.insns_before as isize,
        inlined_map_entries: result
            .map_inline_records
            .iter()
            .map(inlined_map_entry_report)
            .collect(),
    })
}

fn site_skip_reports(
    program: &BBProgram,
    skips: &[bpfopt::pass::SiteSkipReason],
) -> Result<Vec<SkippedSiteReport>> {
    skips
        .iter()
        .map(|skip| {
            Ok(SkippedSiteReport {
                pc: report_site_pc(program, skip.site)?,
                reason: skip.reason.clone(),
            })
        })
        .collect()
}

fn site_diagnostic_reports(
    program: &BBProgram,
    diagnostics: &[bpfopt::pass::SiteDiagnostic],
) -> Result<Vec<String>> {
    diagnostics
        .iter()
        .map(|diagnostic| {
            Ok(format!(
                "site at PC={}: {}",
                report_site_pc(program, diagnostic.site)?,
                diagnostic.message
            ))
        })
        .collect()
}

fn inlined_map_entry_report(record: &bpfopt::pass::MapInlineRecord) -> InlinedMapEntryReport {
    InlinedMapEntryReport {
        map_id: record.map_id,
        key_hex: hex_bytes(&record.key),
        value_hex: hex_bytes(&record.value),
    }
}

#[cfg(test)]
#[path = "main_tests.rs"]
mod tests;
