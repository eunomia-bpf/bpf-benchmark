// SPDX-License-Identifier: MIT
//! bpfopt CLI entry point.

use std::collections::{BTreeMap, HashMap, HashSet};
use std::fs;
use std::io::{self, Read, Write};
use std::path::{Path, PathBuf};
use std::process::ExitCode;

use anyhow::{anyhow, bail, Context, Result};
use bpfopt::analysis::{lift_with_pass_context, lower, BBProgram};
use bpfopt::insn::{BpfInsn, MapPseudo};
use bpfopt::pass::{
    run_pass_once, Arch, BpfPass, BtfInfoRecords, CompressedMapValues, CompressedMapValuesKind,
    KinsnDescriptor, KinsnRegistry, MapInlineHintAnchorSpec, MapInlineHintModeSpec,
    MapInlineHintSpec, MapMetadata, PassAction, PassContext, PassManager, PassReportSite,
    PassResult, PlatformCapabilities,
};
use bpfopt::passes::PASS_REGISTRY;
use bpfopt::verifier_log::{verifier_states_from_log, VerifierStatesJson};
use clap::{Args, Parser, Subcommand};
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
    /// Pass-local args. Must follow `--` and are parsed by the selected pass.
    #[arg(last = true, num_args = 0.., allow_hyphen_values = true)]
    pass_args: Vec<String>,
}

/// Framework-global CLI args shared by every pass invocation.
///
/// IMPORTANT: only put a flag here when *every* bpfopt run conceivably
/// needs it (input/output/report paths, target arch, prog type, BTF
/// remapping inputs, kinsn target metadata, verifier-states log).
/// Per-pass tuning (e.g. map_inline's `--inline-hint`, branch_flip's
/// `--profile`, prefetch's `--profile`) goes in the pass's own
/// `<Pass>CliArgs` struct and is parsed AFTER `--`. Adding a pass-specific
/// flag here pollutes the global namespace and breaks the pass-local
/// args trait — see `runner/229 [completed] [Refactor] bpfopt CLI Pass-local
/// args trait + --- passthrough`.
#[derive(Args, Clone, Debug, Default)]
struct CommonArgs {
    /// Input bytecode file. Defaults to stdin.
    #[arg(long, global = true, value_name = "FILE")]
    input: Option<PathBuf>,
    /// Output bytecode or JSON file. Defaults to stdout.
    #[arg(long, global = true, value_name = "FILE")]
    output: Option<PathBuf>,
    /// Canonicalize map references from loader FD form to stable map-index form.
    #[arg(long, global = true)]
    canonicalize_map_refs: bool,
    /// Program map IDs in kernel used_maps order, comma-separated.
    #[arg(long, global = true, value_name = "IDS", value_delimiter = ',')]
    map_ids: Vec<u32>,
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
    /// Output target platform JSON file after canonicalization-time rewrites.
    #[arg(long, global = true, value_name = "FILE")]
    target_output: Option<PathBuf>,
    /// Verifier states JSON file.
    #[arg(long, global = true, value_name = "FILE")]
    verifier_states: Option<PathBuf>,
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

#[derive(Clone, Debug, Serialize)]
struct ListPassEntry {
    name: &'static str,
    canonical_name: &'static str,
    description: &'static str,
    needs_target: bool,
    needs_verifier_states: bool,
    produces_verifier_states: bool,
    needs_map_values: bool,
    #[serde(rename = "kinsns_used")]
    kinsn_targets: &'static [KinsnDescriptor],
}

#[derive(Debug, Deserialize, Serialize)]
struct TargetJson {
    #[serde(skip_serializing_if = "Option::is_none")]
    arch: Option<String>,
    #[serde(default)]
    features: Vec<String>,
    #[serde(default)]
    kinsns: BTreeMap<String, KinsnJson>,
}

#[derive(Debug, Deserialize, Serialize)]
struct KinsnJson {
    btf_func_id: i32,
    #[serde(default)]
    btf_id: u32,
    call_offset: i16,
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

    if cli.common.canonicalize_map_refs {
        if cli.pass.is_some() || cli.command.is_some() {
            bail!("--canonicalize-map-refs cannot be combined with --pass or subcommands");
        }
        if !cli.pass_args.is_empty() {
            bail!("pass-local args require --pass <name>");
        }
        return run_canonicalize_map_refs(&cli.common);
    }
    if cli.common.target_output.is_some() {
        bail!("--target-output requires --canonicalize-map-refs");
    }

    match cli.command {
        Some(Command::ListPasses(args)) => {
            if cli.pass.is_some() {
                bail!("--pass cannot be used with list-passes");
            }
            if !cli.pass_args.is_empty() {
                bail!("pass-local args require --pass <name>");
            }
            list_passes(&cli.common, &args)
        }
        None => {
            let pass = cli
                .pass
                .as_deref()
                .ok_or_else(|| anyhow!("bpfopt requires --pass <name> or list-passes"))?;
            run_single_pass(&cli.common, canonicalize_pass_name(pass)?, &cli.pass_args)
        }
    }
}

fn run_canonicalize_map_refs(common: &CommonArgs) -> Result<()> {
    if common.report.is_some() {
        bail!("--canonicalize-map-refs does not produce --report");
    }
    match (common.target.as_deref(), common.target_output.as_deref()) {
        (Some(_), Some(_)) | (None, None) => {}
        (Some(_), None) => bail!("--canonicalize-map-refs --target requires --target-output"),
        (None, Some(_)) => bail!("--target-output requires --target"),
    }
    let mut insns = read_bytecode(common.input.as_deref())?;
    canonicalize_map_refs_to_idx(&mut insns, None, &common.map_ids)?;
    if let (Some(target), Some(target_output)) =
        (common.target.as_deref(), common.target_output.as_deref())
    {
        let mut target_json = read_target(target)?;
        shift_target_module_call_offsets_for_map_prefix(&mut target_json, common.map_ids.len())?;
        write_json(Some(target_output), &target_json)?;
    }
    write_bytecode(common.output.as_deref(), &insns)
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
                kinsn_targets: entry.metadata.kinsn_targets,
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

fn run_single_pass(
    common: &CommonArgs,
    pass_name: &'static str,
    pass_args: &[String],
) -> Result<()> {
    validate_required_side_inputs(common, &[pass_name])?;

    let input = read_bytecode(common.input.as_deref())?;
    let mut ctx = build_pass_context(common)?;
    let empty_pass_args = Vec::new();
    let pass_constructor_args = if pass_name == "map_inline" {
        attach_map_inline_cli_side_input(&mut ctx, common, pass_args)?;
        empty_pass_args.as_slice()
    } else {
        pass_args
    };
    validate_required_kinsns(&ctx, &[pass_name])?;
    let mut program = lift_with_pass_context(&input, &ctx)?;
    let report_program = if common.report.is_some() {
        Some(program.clone())
    } else {
        None
    };
    let pass = build_pass(pass_name, pass_constructor_args)?;
    let result = run_pass_once(pass.as_ref(), &mut program, &ctx)?;
    let output = lower(&program)?;
    write_bytecode(common.output.as_deref(), &output)?;
    write_btf_info_outputs(common, &program)?;

    if let Some(report_path) = common.report.as_deref() {
        let report = pass_report(
            pass_name,
            report_program
                .as_ref()
                .ok_or_else(|| anyhow!("report program snapshot is unavailable"))?,
            &result,
        )?;
        write_json(Some(report_path), &report)?;
    }

    Ok(())
}

fn build_pass(name: &str, pass_args: &[String]) -> Result<Box<dyn BpfPass>> {
    let entry = registry_entry(name)?;
    (entry.make)(pass_args)
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
        if entry.metadata.needs_verifier_states() && common.verifier_states.is_none() {
            bail!("{label} requires --verifier-states");
        }
    }
    Ok(())
}

fn validate_required_kinsns(ctx: &PassContext, pass_names: &[&str]) -> Result<()> {
    for &pass_name in pass_names {
        let entry = registry_entry(pass_name)?;
        if !entry.metadata.needs_target()
            || (pass_name == "ccmp" && ctx.platform.arch != Arch::Aarch64)
        {
            continue;
        }
        let target_names = entry.metadata.required_kinsns.iter().copied();
        let label = cli_name_for_pass(pass_name);
        require_all_kinsns(ctx, target_names, label)?;
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

// Snapshot initialization canonicalizes loader-owned map references before the
// daemon lifts bytecode into BBProgram. This is intentionally the only raw Vec
// mutation path in the CLI; optimization passes must operate through BBProgram.
fn canonicalize_map_refs_to_idx(
    insns: &mut [BpfInsn],
    original_loader_fd_array: Option<&[i32]>,
    map_ids: &[u32],
) -> Result<()> {
    let fd_to_map_index = collect_fd_form_map_refs(insns)?;
    if fd_to_map_index.is_empty() && !contains_idx_form_map_ref(insns)? {
        return Ok(());
    }

    if fd_to_map_index.len() > map_ids.len() {
        bail!(
            "canonicalize_map_refs_to_idx: bytecode references {} unique loader map fds but prog_info has {} map ids",
            fd_to_map_index.len(),
            map_ids.len()
        );
    }

    let mut i = 0;
    while i < insns.len() {
        if insns[i].is_ldimm64() {
            let map_pseudo = insns[i].map_pseudo();
            if map_pseudo.is_some() && i + 1 >= insns.len() {
                bail!("canonicalize_map_refs_to_idx: truncated LD_IMM64 map reference at pc {i}");
            }
            if matches!(map_pseudo, Some(MapPseudo::Fd | MapPseudo::FdValue)) {
                let old_fd = insns[i].imm;
                let Some(&map_index) = fd_to_map_index.get(&old_fd) else {
                    bail!(
                        "canonicalize_map_refs_to_idx: loader map fd {} was not present in first-seen bindings",
                        old_fd
                    );
                };
                insns[i].imm = i32::try_from(map_index).with_context(|| {
                    format!("canonicalize_map_refs_to_idx: map index {map_index} exceeds i32")
                })?;
                insns[i].set_src_reg(if map_pseudo == Some(MapPseudo::Fd) {
                    MapPseudo::Idx.src_reg()
                } else {
                    MapPseudo::IdxValue.src_reg()
                });
            } else if matches!(map_pseudo, Some(MapPseudo::Idx | MapPseudo::IdxValue)) {
                let map_index = canonical_idx_map_index(
                    insns[i].imm,
                    original_loader_fd_array,
                    &fd_to_map_index,
                    map_ids.len(),
                )?;
                insns[i].imm = i32::try_from(map_index).with_context(|| {
                    format!("canonicalize_map_refs_to_idx: map index {map_index} exceeds i32")
                })?;
            }
            i += 2;
            continue;
        }
        i += 1;
    }

    Ok(())
}

fn collect_fd_form_map_refs(insns: &[BpfInsn]) -> Result<HashMap<i32, usize>> {
    let mut fd_to_map_index = HashMap::new();
    let mut i = 0;
    while i < insns.len() {
        if insns[i].is_ldimm64() {
            if matches!(
                insns[i].map_pseudo(),
                Some(MapPseudo::Fd | MapPseudo::FdValue)
            ) {
                if i + 1 >= insns.len() {
                    bail!(
                        "canonicalize_map_refs_to_idx: truncated LD_IMM64 map reference at pc {i}"
                    );
                }
                let old_fd = insns[i].imm;
                let next_index = fd_to_map_index.len();
                if let std::collections::hash_map::Entry::Vacant(e) = fd_to_map_index.entry(old_fd)
                {
                    e.insert(next_index);
                }
            }
            i += 2;
            continue;
        }
        i += 1;
    }
    Ok(fd_to_map_index)
}

fn contains_idx_form_map_ref(insns: &[BpfInsn]) -> Result<bool> {
    let mut i = 0;
    while i < insns.len() {
        if insns[i].is_ldimm64() {
            if matches!(
                insns[i].map_pseudo(),
                Some(MapPseudo::Idx | MapPseudo::IdxValue)
            ) {
                if i + 1 >= insns.len() {
                    bail!(
                        "canonicalize_map_refs_to_idx: truncated LD_IMM64 map reference at pc {i}"
                    );
                }
                return Ok(true);
            }
            i += 2;
            continue;
        }
        i += 1;
    }
    Ok(false)
}

fn canonical_idx_map_index(
    old_index: i32,
    original_loader_fd_array: Option<&[i32]>,
    fd_to_map_index: &HashMap<i32, usize>,
    map_count: usize,
) -> Result<usize> {
    let old_index = usize::try_from(old_index).with_context(|| {
        format!("canonicalize_map_refs_to_idx: negative map fd_array index {old_index}")
    })?;
    let Some(loader_fd_array) = original_loader_fd_array else {
        if old_index >= map_count {
            bail!(
                "canonicalize_map_refs_to_idx: map index {} out of range for {} map ids",
                old_index,
                map_count
            );
        }
        return Ok(old_index);
    };
    let Some(&loader_fd) = loader_fd_array.get(old_index) else {
        bail!(
            "canonicalize_map_refs_to_idx: loader fd_array index {} out of range for {} fds",
            old_index,
            loader_fd_array.len()
        );
    };
    if let Some(&map_index) = fd_to_map_index.get(&loader_fd) {
        return Ok(map_index);
    }
    if loader_fd_array.len() != map_count {
        bail!(
            "canonicalize_map_refs_to_idx: cannot map loader fd_array index {} without fd-form binding; loader fd_array has {} entries but prog_info has {} map ids",
            old_index,
            loader_fd_array.len(),
            map_count
        );
    }
    if old_index >= map_count {
        bail!(
            "canonicalize_map_refs_to_idx: map index {} out of range for {} map ids",
            old_index,
            map_count
        );
    }
    Ok(old_index)
}

fn shift_target_module_call_offsets_for_map_prefix(
    target: &mut TargetJson,
    map_count: usize,
) -> Result<()> {
    let module_base = module_fd_array_base(map_count)?;
    for (name, kinsn) in &mut target.kinsns {
        if kinsn.call_offset == 0 {
            continue;
        }
        if kinsn.call_offset < 0 {
            bail!(
                "target kinsn {name} has negative call_offset {}",
                kinsn.call_offset
            );
        }
        if kinsn.btf_id == 0 {
            bail!(
                "target kinsn {name} has call_offset {} but no BTF object id",
                kinsn.call_offset
            );
        }
        let shifted = module_base
            .checked_add(i32::from(kinsn.call_offset) - 1)
            .with_context(|| format!("target kinsn {name} call_offset overflow"))?;
        if shifted > i32::from(i16::MAX) {
            bail!(
                "target kinsn {name} shifted call_offset {shifted} exceeds BPF instruction off field"
            );
        }
        kinsn.call_offset =
            i16::try_from(shifted).context("shifted call_offset exceeds i16 range")?;
    }
    Ok(())
}

fn module_fd_array_base(map_count: usize) -> Result<i32> {
    let map_count = i32::try_from(map_count).context("map count exceeds i32")?;
    Ok(map_count.max(1))
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
    if let Some(path) = common.func_info.as_deref() {
        let bytes = program
            .remapped_func_info_records()?
            .map(|records| records.bytes)
            .ok_or_else(|| {
                anyhow!("--func-info requested but remapped func_info records are unavailable")
            })?;
        fs::write(path, bytes).with_context(|| format!("failed to write {}", path.display()))?;
    }
    if let Some(path) = common.line_info.as_deref() {
        let bytes = program
            .remapped_line_info_records()?
            .map(|records| records.bytes)
            .ok_or_else(|| {
                anyhow!("--line-info requested but remapped line_info records are unavailable")
            })?;
        fs::write(path, bytes).with_context(|| format!("failed to write {}", path.display()))?;
    }
    Ok(())
}

fn build_pass_context(common: &CommonArgs) -> Result<PassContext> {
    let mut ctx = PassContext::try_baseline()?;
    ctx.platform = detect_platform();
    ctx.map_ids = common.map_ids.clone();
    if let Some(path) = common.verifier_states.as_deref() {
        ctx.set_verifier_states_json(read_verifier_states(path)?)?;
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

fn attach_map_inline_cli_side_input(
    ctx: &mut PassContext,
    common: &CommonArgs,
    pass_args: &[String],
) -> Result<()> {
    let cli = MapInlineCliArgs::parse(pass_args)?;
    let map_ids = cli.resolve_map_ids(common)?;
    let snapshot = read_map_values(&cli.map_values, &map_ids)?;
    ctx.map_ids = map_ids;
    ctx.map_metadata = snapshot.metadata;
    ctx.map_values = snapshot.values;
    ctx.map_value_overlays = snapshot.compressed_values;
    ctx.map_inner_map_ids = snapshot.inner_map_ids;
    ctx.map_snapshots_skipped_by_size = snapshot.maps_skipped_by_size;
    ctx.map_inline_hints = cli.inline_hints;
    Ok(())
}

struct MapInlineCliArgs {
    map_values: PathBuf,
    map_ids: Option<String>,
    inline_hints: Vec<MapInlineHintSpec>,
}

impl MapInlineCliArgs {
    fn parse(args: &[String]) -> Result<Self> {
        let mut map_values = None;
        let mut map_ids = None;
        let mut inline_hints = Vec::new();
        let mut iter = args.iter();
        while let Some(arg) = iter.next() {
            if let Some(value) = arg.strip_prefix("--inline-hint=") {
                inline_hints.push(parse_inline_hint(value)?);
                continue;
            }
            match arg.as_str() {
                "--map-values" => {
                    let value = iter
                        .next()
                        .ok_or_else(|| anyhow!("--map-values requires DIR"))?;
                    map_values = Some(PathBuf::from(value));
                }
                "--map-ids" => {
                    let value = iter
                        .next()
                        .ok_or_else(|| anyhow!("--map-ids requires LIST"))?;
                    map_ids = Some(value.clone());
                }
                "--inline-hint" => {
                    let value = iter.next().ok_or_else(|| {
                        anyhow!("--inline-hint requires <anchor>:[!]<hex_key_bytes>")
                    })?;
                    inline_hints.push(parse_inline_hint(value)?);
                }
                other => bail!("map_inline unknown pass-local arg: {other}"),
            }
        }
        validate_inline_hint_anchor_modes(&inline_hints)?;
        Ok(Self {
            map_values: map_values.ok_or_else(|| anyhow!("map_inline requires --map-values"))?,
            map_ids,
            inline_hints,
        })
    }

    fn resolve_map_ids(&self, common: &CommonArgs) -> Result<Vec<u32>> {
        let pass_local = match self.map_ids.as_deref() {
            Some(value) => Some(parse_map_ids_arg(value)?),
            None => None,
        };
        match (pass_local, common.map_ids.is_empty()) {
            (Some(map_ids), true) => Ok(map_ids),
            (Some(map_ids), false) => {
                if map_ids != common.map_ids {
                    bail!("map_inline pass-local --map-ids differs from global --map-ids");
                }
                Ok(map_ids)
            }
            (None, false) => Ok(common.map_ids.clone()),
            (None, true) => bail!("map_inline requires --map-ids"),
        }
    }
}

fn parse_inline_hint(input: &str) -> Result<MapInlineHintSpec> {
    let (anchor_str, key_str) = input.split_once(':').ok_or_else(|| {
        anyhow!("invalid --inline-hint '{input}': expected <anchor>:[!]<hex_key_bytes>")
    })?;
    let anchor = parse_inline_hint_anchor(anchor_str)
        .with_context(|| format!("invalid --inline-hint anchor in '{input}'"))?;
    let (mode, hex_str) = if let Some(hex) = key_str.strip_prefix('!') {
        (MapInlineHintModeSpec::Hard, hex)
    } else {
        (MapInlineHintModeSpec::Soft, key_str)
    };
    let key = parse_inline_hint_hex(hex_str)
        .with_context(|| format!("invalid --inline-hint key bytes in '{input}'"))?;
    Ok(MapInlineHintSpec { anchor, mode, key })
}

fn parse_inline_hint_anchor(input: &str) -> Result<MapInlineHintAnchorSpec> {
    if input.is_empty() {
        bail!("anchor is empty");
    }
    if input.bytes().all(|byte| byte.is_ascii_digit()) {
        let pc = input
            .parse::<usize>()
            .with_context(|| format!("invalid call_pc anchor {input:?}"))?;
        return Ok(MapInlineHintAnchorSpec::Pc(pc));
    }
    let first = input.as_bytes()[0];
    if !(first.is_ascii_alphabetic() || first == b'_') {
        bail!("map-name anchor must start with a letter or underscore");
    }
    if !input
        .bytes()
        .skip(1)
        .all(|byte| byte.is_ascii_alphanumeric() || byte == b'_')
    {
        bail!("map-name anchor must contain only ASCII letters, digits, and underscores");
    }
    Ok(MapInlineHintAnchorSpec::MapName(input.to_string()))
}

fn parse_inline_hint_hex(input: &str) -> Result<Vec<u8>> {
    if !input.len().is_multiple_of(2) {
        bail!("hex string must have an even number of digits");
    }
    input
        .as_bytes()
        .chunks_exact(2)
        .map(|pair| {
            let hi = hex_nibble(pair[0])
                .ok_or_else(|| anyhow!("invalid hex digit '{}'", char::from(pair[0])))?;
            let lo = hex_nibble(pair[1])
                .ok_or_else(|| anyhow!("invalid hex digit '{}'", char::from(pair[1])))?;
            Ok((hi << 4) | lo)
        })
        .collect()
}

fn hex_nibble(byte: u8) -> Option<u8> {
    match byte {
        b'0'..=b'9' => Some(byte - b'0'),
        b'a'..=b'f' => Some(byte - b'a' + 10),
        b'A'..=b'F' => Some(byte - b'A' + 10),
        _ => None,
    }
}

fn validate_inline_hint_anchor_modes(hints: &[MapInlineHintSpec]) -> Result<()> {
    let mut anchors = BTreeMap::<MapInlineHintAnchorSpec, (MapInlineHintModeSpec, usize)>::new();
    for hint in hints {
        match anchors.get_mut(&hint.anchor) {
            Some((mode, count)) => {
                if *mode != hint.mode {
                    bail!(
                        "inline hint anchor {} mixes soft and hard folds",
                        format_hint_anchor(&hint.anchor)
                    );
                }
                if hint.mode == MapInlineHintModeSpec::Hard {
                    bail!(
                        "inline hint anchor {} has multiple hard folds",
                        format_hint_anchor(&hint.anchor)
                    );
                }
                *count += 1;
            }
            None => {
                anchors.insert(hint.anchor.clone(), (hint.mode, 1));
            }
        }
    }
    Ok(())
}

fn format_hint_anchor(anchor: &MapInlineHintAnchorSpec) -> String {
    match anchor {
        MapInlineHintAnchorSpec::Pc(pc) => pc.to_string(),
        MapInlineHintAnchorSpec::MapName(name) => name.clone(),
    }
}

#[derive(Clone)]
struct MapSnapshot {
    metadata: HashMap<u32, MapMetadata>,
    values: HashMap<(u32, Vec<u8>), Vec<u8>>,
    compressed_values: HashMap<u32, CompressedMapValues>,
    inner_map_ids: HashMap<(u32, Vec<u8>), u32>,
    maps_skipped_by_size: HashSet<u32>,
}

#[derive(Debug, Deserialize)]
struct ProgInfoMapIdsJson {
    #[serde(default)]
    map_ids: Vec<u32>,
}

#[derive(Debug, Deserialize)]
struct BpftoolMapShowJson {
    id: u32,
    #[serde(default)]
    name: String,
    #[serde(rename = "type")]
    map_type: MapTypeJson,
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
#[serde(untagged)]
enum InnerMapIdJson {
    Number(u32),
    String(String),
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
    Compressed(CompressedMapValues),
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
#[serde(deny_unknown_fields)]
struct CompressedMapValuesJson {
    compression: String,
    value_size: usize,
    #[serde(default)]
    value_hex: Option<String>,
    #[serde(default)]
    default_hex: Option<String>,
    #[serde(default)]
    entries: Option<serde_json::Value>,
}

#[derive(Debug, Deserialize)]
#[serde(untagged)]
enum MapTypeJson {
    Number(u32),
    Name(String),
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
    let mut compressed_values = HashMap::new();
    let mut inner_map_ids = HashMap::new();
    let mut maps_skipped_by_size = HashSet::new();
    let mut empty_lpm_trie_maps = HashSet::new();
    for &map_id in map_ids.iter().filter(|&&map_id| map_id != 0) {
        let show = read_bpftool_map_show(path, map_id)?;
        let map_type = parse_map_type(&show.map_type)?;
        let map_metadata = MapMetadata {
            map_type,
            key_size: show.bytes_key,
            value_size: show.bytes_value,
            max_entries: show.max_entries,
            map_id: show.id,
            name: show.name,
        };
        if needs_bpftool_map_dump(map_type) {
            match read_bpftool_map_dump(path, show.id, &map_metadata)? {
                BpftoolMapDumpSnapshot::Entries(entries) => {
                    if entries.is_empty()
                        && map_metadata.map_type == libbpf_sys::BPF_MAP_TYPE_LPM_TRIE
                    {
                        empty_lpm_trie_maps.insert(show.id);
                    }
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
                BpftoolMapDumpSnapshot::Compressed(compressed) => {
                    if values.keys().any(|(map_id, _)| *map_id == show.id) {
                        bail!(
                            "map {} has both raw entries and compression overlay",
                            show.id
                        );
                    }
                    compressed_values.insert(show.id, compressed);
                }
                BpftoolMapDumpSnapshot::SkippedBySize => {
                    maps_skipped_by_size.insert(show.id);
                }
            }
            read_inner_map_ids_supplement(
                path,
                show.id,
                map_metadata.key_size as usize,
                &mut inner_map_ids,
            )?;
        }
        metadata.insert(show.id, map_metadata);
    }
    read_optional_compressed_overlay_file(path, &metadata, &values, &mut compressed_values)?;
    synthesize_empty_lpm_trie_overlays(&empty_lpm_trie_maps, &metadata, &mut compressed_values)?;
    Ok(MapSnapshot {
        metadata,
        values,
        compressed_values,
        inner_map_ids,
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

fn read_bpftool_map_dump(
    path: &Path,
    map_id: u32,
    metadata: &MapMetadata,
) -> Result<BpftoolMapDumpSnapshot> {
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
            let value: serde_json::Value = serde_json::from_slice(&data).with_context(|| {
                format!(
                    "failed to parse bpftool map dump object from {}",
                    dump_path.display()
                )
            })?;
            if value.get("compression").is_some() {
                let compressed = parse_compressed_map_values_json(map_id, metadata, value)
                    .with_context(|| {
                        format!(
                            "failed to parse compressed map overlay {}",
                            dump_path.display()
                        )
                    })?;
                return Ok(BpftoolMapDumpSnapshot::Compressed(compressed));
            }
            let marker: BpftoolMapDumpSkipMarker =
                serde_json::from_value(value).with_context(|| {
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

fn read_inner_map_ids_supplement(
    path: &Path,
    map_id: u32,
    key_size: usize,
    inner_map_ids: &mut HashMap<(u32, Vec<u8>), u32>,
) -> Result<()> {
    let supplement_path = bpftool_map_inner_map_ids_path(path, map_id);
    let data = match fs::read(&supplement_path) {
        Ok(data) => data,
        Err(err) if err.kind() == std::io::ErrorKind::NotFound => return Ok(()),
        Err(err) => {
            return Err(err)
                .with_context(|| format!("failed to read {}", supplement_path.display()))
        }
    };
    let supplement: HashMap<String, HashMap<String, InnerMapIdJson>> =
        serde_json::from_slice(&data).with_context(|| {
            format!(
                "failed to parse inner_map_id supplement from {}",
                supplement_path.display()
            )
        })?;
    let expected_map_id = map_id.to_string();
    for present_map_id in supplement.keys() {
        if present_map_id != &expected_map_id {
            bail!(
                "{} contains inner_map_id table for map {}, expected only {}",
                supplement_path.display(),
                present_map_id,
                expected_map_id
            );
        }
    }
    let entries = supplement.get(&expected_map_id).ok_or_else(|| {
        anyhow!(
            "{} does not contain inner_map_id table for map {}",
            supplement_path.display(),
            map_id
        )
    })?;
    for (key_hex, inner_map_id_json) in entries {
        let key = decode_inner_map_id_key_hex(map_id, key_hex, key_size)?;
        let inner_map_id = decode_inner_map_id_json(map_id, key_hex, inner_map_id_json)?;
        inner_map_ids.insert((map_id, key), inner_map_id);
    }
    Ok(())
}

fn decode_inner_map_id_key_hex(map_id: u32, hex: &str, key_size: usize) -> Result<Vec<u8>> {
    let expected = expected_hex_digits(key_size, "key_size")?;
    if hex.len() != expected {
        bail!(
            "map {map_id} inner_map_id supplement key has {} hex digit(s), expected {}",
            hex.len(),
            expected
        );
    }
    parse_inline_hint_hex(hex)
        .with_context(|| format!("map {map_id} inner_map_id supplement key has invalid hex"))
}

fn decode_inner_map_id_json(map_id: u32, key_hex: &str, value: &InnerMapIdJson) -> Result<u32> {
    let inner_map_id = match value {
        InnerMapIdJson::Number(number) => *number,
        InnerMapIdJson::String(text) => text.parse::<u32>().with_context(|| {
            format!("map {map_id} inner_map_id supplement entry {key_hex:?} is not a u32 id")
        })?,
    };
    if inner_map_id == 0 {
        bail!("map {map_id} inner_map_id supplement entry {key_hex:?} has id 0; omit NULL entries");
    }
    Ok(inner_map_id)
}

fn read_optional_compressed_overlay_file(
    path: &Path,
    metadata: &HashMap<u32, MapMetadata>,
    raw_values: &HashMap<(u32, Vec<u8>), Vec<u8>>,
    compressed_values: &mut HashMap<u32, CompressedMapValues>,
) -> Result<()> {
    let overlay_path = path.join("overlays.json");
    let data = match fs::read(&overlay_path) {
        Ok(data) => data,
        Err(err) if err.kind() == std::io::ErrorKind::NotFound => return Ok(()),
        Err(err) => {
            return Err(err).with_context(|| format!("failed to read {}", overlay_path.display()))
        }
    };
    let overlays: HashMap<String, serde_json::Value> =
        serde_json::from_slice(&data).with_context(|| {
            format!(
                "failed to parse compressed map overlays from {}",
                overlay_path.display()
            )
        })?;
    for (map_id_text, overlay) in overlays {
        let map_id = map_id_text
            .parse::<u32>()
            .with_context(|| format!("invalid compressed overlay map id {map_id_text:?}"))?;
        let map_metadata = metadata.get(&map_id).ok_or_else(|| {
            anyhow!(
                "compressed overlay references map {} not present in --map-ids metadata",
                map_id
            )
        })?;
        if raw_values
            .keys()
            .any(|(raw_map_id, _)| *raw_map_id == map_id)
        {
            bail!("map {map_id} has both raw entries and compression overlay");
        }
        let compressed = parse_compressed_map_values_json(map_id, map_metadata, overlay)
            .map_err(|err| anyhow!("invalid compressed overlay for map {map_id}: {err}"))?;
        if compressed_values.insert(map_id, compressed).is_some() {
            bail!("map {map_id} has duplicate compression overlays");
        }
    }
    Ok(())
}

fn synthesize_empty_lpm_trie_overlays(
    empty_lpm_trie_maps: &HashSet<u32>,
    metadata: &HashMap<u32, MapMetadata>,
    compressed_values: &mut HashMap<u32, CompressedMapValues>,
) -> Result<()> {
    for map_id in empty_lpm_trie_maps {
        if compressed_values.contains_key(map_id) {
            continue;
        }
        let map_metadata = metadata
            .get(map_id)
            .ok_or_else(|| anyhow!("empty LPM_TRIE map {} missing map_values metadata", map_id))?;
        compressed_values.insert(
            *map_id,
            CompressedMapValues {
                value_size: map_metadata.value_size as usize,
                kind: CompressedMapValuesKind::Enumerated {
                    entries: HashMap::new(),
                },
            },
        );
    }
    Ok(())
}

fn parse_compressed_map_values_json(
    map_id: u32,
    metadata: &MapMetadata,
    value: serde_json::Value,
) -> Result<CompressedMapValues> {
    let overlay: CompressedMapValuesJson = serde_json::from_value(value)
        .with_context(|| format!("invalid compressed map overlay schema for map {map_id}"))?;
    if overlay.value_size != metadata.value_size as usize {
        bail!(
            "map {map_id} compressed overlay value_size {} does not match map bytes_value {}",
            overlay.value_size,
            metadata.value_size
        );
    }
    let kind = match overlay.compression.as_str() {
        "uniform" => {
            if let Some(entries) = overlay.entries {
                if entries.is_array() {
                    bail!("map {map_id} has both raw entries and compression overlay");
                }
                bail!("map {map_id} uniform compression must not include entries");
            }
            if overlay.default_hex.is_some() {
                bail!("map {map_id} uniform compression must not include default_hex");
            }
            let value_hex = overlay
                .value_hex
                .ok_or_else(|| anyhow!("map {map_id} uniform compression requires value_hex"))?;
            let value =
                decode_compressed_value_hex(map_id, "value_hex", &value_hex, overlay.value_size)?;
            CompressedMapValuesKind::Uniform(value)
        }
        "sparse" => {
            if overlay.value_hex.is_some() {
                bail!("map {map_id} sparse compression must not include value_hex");
            }
            let default_hex = overlay
                .default_hex
                .ok_or_else(|| anyhow!("map {map_id} sparse compression requires default_hex"))?;
            let default = decode_compressed_value_hex(
                map_id,
                "default_hex",
                &default_hex,
                overlay.value_size,
            )?;
            let entries = overlay
                .entries
                .ok_or_else(|| anyhow!("map {map_id} sparse compression requires entries"))?;
            let entries = decode_compressed_entries(
                map_id,
                metadata.key_size as usize,
                overlay.value_size,
                entries,
            )?;
            CompressedMapValuesKind::Sparse { default, entries }
        }
        "enumerated" => {
            if overlay.value_hex.is_some() {
                bail!("map {map_id} enumerated compression must not include value_hex");
            }
            if overlay.default_hex.is_some() {
                bail!("map {map_id} enumerated compression must not include default_hex");
            }
            let entries = overlay
                .entries
                .ok_or_else(|| anyhow!("map {map_id} enumerated compression requires entries"))?;
            let entries = decode_compressed_entries(
                map_id,
                metadata.key_size as usize,
                overlay.value_size,
                entries,
            )?;
            CompressedMapValuesKind::Enumerated { entries }
        }
        other => bail!("map {map_id} unsupported compression {other:?}"),
    };
    Ok(CompressedMapValues {
        value_size: overlay.value_size,
        kind,
    })
}

fn decode_compressed_entries(
    map_id: u32,
    key_size: usize,
    value_size: usize,
    entries: serde_json::Value,
) -> Result<HashMap<Vec<u8>, Vec<u8>>> {
    let object = entries
        .as_object()
        .ok_or_else(|| anyhow!("map {map_id} compressed entries must be a JSON object"))?;
    let mut decoded = HashMap::new();
    for (key_hex, value_json) in object {
        let value_hex = value_json.as_str().ok_or_else(|| {
            anyhow!("map {map_id} compressed entry {key_hex:?} value must be a hex string")
        })?;
        let key = decode_compressed_key_hex(map_id, key_hex, key_size)?;
        let value = decode_compressed_value_hex(map_id, "entries value", value_hex, value_size)?;
        decoded.insert(key, value);
    }
    Ok(decoded)
}

fn decode_compressed_key_hex(map_id: u32, hex: &str, key_size: usize) -> Result<Vec<u8>> {
    let expected = expected_hex_digits(key_size, "key_size")?;
    if hex.len() != expected {
        bail!(
            "map {map_id} compressed entry key has {} hex digit(s), expected {}",
            hex.len(),
            expected
        );
    }
    parse_inline_hint_hex(hex)
        .with_context(|| format!("map {map_id} compressed entry key has invalid hex"))
}

fn decode_compressed_value_hex(
    map_id: u32,
    field: &str,
    hex: &str,
    value_size: usize,
) -> Result<Vec<u8>> {
    let expected = expected_hex_digits(value_size, "value_size")?;
    if hex.len() != expected {
        bail!(
            "map {map_id} compressed {field} has {} hex digit(s), expected {}",
            hex.len(),
            expected
        );
    }
    parse_inline_hint_hex(hex)
        .with_context(|| format!("map {map_id} compressed {field} has invalid hex"))
}

fn expected_hex_digits(byte_len: usize, label: &str) -> Result<usize> {
    byte_len
        .checked_mul(2)
        .ok_or_else(|| anyhow!("{label} {byte_len} overflows hex length"))
}

fn bpftool_map_show_path(path: &Path, map_id: u32) -> PathBuf {
    path.join(format!("map-{map_id}.show.json"))
}

fn bpftool_map_dump_path(path: &Path, map_id: u32) -> PathBuf {
    path.join(format!("map-{map_id}.dump.json"))
}

fn bpftool_map_inner_map_ids_path(path: &Path, map_id: u32) -> PathBuf {
    path.join(format!("map-{map_id}.inner_map_ids.json"))
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

fn round_up_8(value: usize) -> usize {
    (value + 7) & !7
}

fn decode_bpftool_hex_bytes(input: &[String]) -> Result<Vec<u8>> {
    input
        .iter()
        .map(|byte| {
            let byte = byte.trim();
            let hex = match byte.strip_prefix("0x") {
                Some(hex) => hex,
                None => byte,
            };
            u8::from_str_radix(hex, 16).with_context(|| format!("invalid bpftool byte {byte:?}"))
        })
        .collect()
}

fn needs_bpftool_map_dump(map_type: u32) -> bool {
    matches!(
        map_type,
        libbpf_sys::BPF_MAP_TYPE_HASH
            | libbpf_sys::BPF_MAP_TYPE_ARRAY
            | libbpf_sys::BPF_MAP_TYPE_PERCPU_ARRAY
            | libbpf_sys::BPF_MAP_TYPE_LRU_HASH
            | libbpf_sys::BPF_MAP_TYPE_LPM_TRIE
            | libbpf_sys::BPF_MAP_TYPE_ARRAY_OF_MAPS
            | libbpf_sys::BPF_MAP_TYPE_HASH_OF_MAPS
    )
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
                "hash" => Ok(libbpf_sys::BPF_MAP_TYPE_HASH),
                "array" => Ok(libbpf_sys::BPF_MAP_TYPE_ARRAY),
                "prog_array" => Ok(libbpf_sys::BPF_MAP_TYPE_PROG_ARRAY),
                "perf_event_array" => Ok(libbpf_sys::BPF_MAP_TYPE_PERF_EVENT_ARRAY),
                "percpu_hash" | "per_cpu_hash" => Ok(libbpf_sys::BPF_MAP_TYPE_PERCPU_HASH),
                "percpu_array" | "per_cpu_array" => Ok(libbpf_sys::BPF_MAP_TYPE_PERCPU_ARRAY),
                "stack_trace" => Ok(libbpf_sys::BPF_MAP_TYPE_STACK_TRACE),
                "cgroup_array" => Ok(libbpf_sys::BPF_MAP_TYPE_CGROUP_ARRAY),
                "lru_hash" => Ok(libbpf_sys::BPF_MAP_TYPE_LRU_HASH),
                "lru_percpu_hash" | "lru_per_cpu_hash" => {
                    Ok(libbpf_sys::BPF_MAP_TYPE_LRU_PERCPU_HASH)
                }
                "lpm_trie" => Ok(libbpf_sys::BPF_MAP_TYPE_LPM_TRIE),
                "array_of_maps" => Ok(libbpf_sys::BPF_MAP_TYPE_ARRAY_OF_MAPS),
                "hash_of_maps" => Ok(libbpf_sys::BPF_MAP_TYPE_HASH_OF_MAPS),
                "devmap" => Ok(libbpf_sys::BPF_MAP_TYPE_DEVMAP),
                "devmap_hash" => Ok(libbpf_sys::BPF_MAP_TYPE_DEVMAP_HASH),
                "sockmap" => Ok(libbpf_sys::BPF_MAP_TYPE_SOCKMAP),
                "cpumap" => Ok(libbpf_sys::BPF_MAP_TYPE_CPUMAP),
                "xskmap" => Ok(libbpf_sys::BPF_MAP_TYPE_XSKMAP),
                "sockhash" => Ok(libbpf_sys::BPF_MAP_TYPE_SOCKHASH),
                "cgroup_storage" => Ok(libbpf_sys::BPF_MAP_TYPE_CGROUP_STORAGE),
                "reuseport_sockarray" => Ok(libbpf_sys::BPF_MAP_TYPE_REUSEPORT_SOCKARRAY),
                "percpu_cgroup_storage" | "per_cpu_cgroup_storage" => {
                    Ok(libbpf_sys::BPF_MAP_TYPE_PERCPU_CGROUP_STORAGE)
                }
                "queue" => Ok(libbpf_sys::BPF_MAP_TYPE_QUEUE),
                "stack" => Ok(libbpf_sys::BPF_MAP_TYPE_STACK),
                "sk_storage" => Ok(libbpf_sys::BPF_MAP_TYPE_SK_STORAGE),
                "struct_ops" => Ok(libbpf_sys::BPF_MAP_TYPE_STRUCT_OPS),
                "ringbuf" => Ok(libbpf_sys::BPF_MAP_TYPE_RINGBUF),
                "inode_storage" => Ok(libbpf_sys::BPF_MAP_TYPE_INODE_STORAGE),
                "task_storage" => Ok(libbpf_sys::BPF_MAP_TYPE_TASK_STORAGE),
                "bloom_filter" => Ok(libbpf_sys::BPF_MAP_TYPE_BLOOM_FILTER),
                "user_ringbuf" => Ok(libbpf_sys::BPF_MAP_TYPE_USER_RINGBUF),
                "cgrp_storage" => Ok(libbpf_sys::BPF_MAP_TYPE_CGRP_STORAGE),
                "arena" => Ok(libbpf_sys::BPF_MAP_TYPE_ARENA),
                "insn_array" => Ok(libbpf_sys::BPF_MAP_TYPE_INSN_ARRAY),
                _ => bail!("unsupported map_type: {name}"),
            }
        }
    }
}

fn parse_map_ids_arg(value: &str) -> Result<Vec<u32>> {
    if value.contains('/') || value.ends_with(".json") {
        let prog_info: ProgInfoMapIdsJson = read_json_file(Path::new(value), "prog_info JSON")?;
        return Ok(prog_info.map_ids);
    }
    parse_u32_csv(value, "--map-ids")
}

fn parse_u32_csv(value: &str, flag: &str) -> Result<Vec<u32>> {
    value
        .split(',')
        .map(|entry| {
            entry
                .trim()
                .parse::<u32>()
                .with_context(|| format!("invalid {flag} value: {entry}"))
        })
        .collect()
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
    let mut registry = KinsnRegistry::unavailable()?;
    for (name, spec) in &target.kinsns {
        let canonical = canonicalize_kinsn_name(name)?;
        registry.set_kinsn_call_for_target_name(canonical, spec.btf_func_id, spec.call_offset)?;
    }
    Ok(registry)
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
        registry.set_kinsn_call_for_target_name(canonical, btf_id, 0)?;
    }
    Ok(())
}

fn canonicalize_kinsn_name(input: &str) -> Result<&'static str> {
    KinsnRegistry::unavailable()?
        .canonical_name_for_target_name(input)
        .ok_or_else(|| anyhow!("unknown kinsn name: {input}"))
}

fn read_verifier_states(path: &Path) -> Result<VerifierStatesJson> {
    let input = fs::read_to_string(path)
        .with_context(|| format!("failed to read verifier states from {}", path.display()))?;
    let states = if input.trim_start().starts_with('{') {
        serde_json::from_str::<VerifierStatesJson>(&input).with_context(|| {
            format!(
                "failed to parse verifier states JSON from {}",
                path.display()
            )
        })?
    } else {
        verifier_states_from_log(&input)
    };
    if states.insns.is_empty() {
        bail!(
            "verifier states {} did not contain parseable state snapshots",
            path.display()
        );
    }
    Ok(states)
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
    let reports = skips
        .iter()
        .map(|skip| PassReportSite {
            site: skip.site,
            action: PassAction::Skipped,
            message: skip.reason.clone(),
        })
        .collect::<Vec<_>>();
    PassManager::finalize_reports(reports, program)?
        .into_iter()
        .map(|report| {
            if report.action != PassAction::Skipped {
                bail!("internal report action mismatch for skipped site");
            }
            Ok(SkippedSiteReport {
                pc: report.pc,
                reason: report.message,
            })
        })
        .collect()
}

fn site_diagnostic_reports(
    program: &BBProgram,
    diagnostics: &[bpfopt::pass::SiteDiagnostic],
) -> Result<Vec<String>> {
    let reports = diagnostics
        .iter()
        .map(|diagnostic| PassReportSite {
            site: diagnostic.site,
            action: PassAction::Diagnostic,
            message: diagnostic.message.clone(),
        })
        .collect::<Vec<_>>();
    PassManager::finalize_reports(reports, program)?
        .into_iter()
        .map(|report| {
            if report.action != PassAction::Diagnostic {
                bail!("internal report action mismatch for diagnostic site");
            }
            Ok(format!("site at PC={}: {}", report.pc, report.message))
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
#[path = "main_tests.rs"]
mod tests;
