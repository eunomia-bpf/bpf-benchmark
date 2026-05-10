// SPDX-License-Identifier: MIT
//! bpfopt CLI entry point.

use std::collections::{BTreeMap, HashMap};
use std::fs;
use std::io::{self, Read, Write};
use std::path::{Path, PathBuf};
use std::process::ExitCode;

use anyhow::{anyhow, bail, Context, Result};
use bpfopt::insn::{BpfInsn, MapPseudo};
use bpfopt::pass::{
    Arch, BpfProgram, BtfInfoRecords, KinsnDescriptor, KinsnRegistry, PassContext, PassManager,
    PassResult, PlatformCapabilities, RegState, ScalarRange, StackState, Tnum, VerifierInsn,
    VerifierInsnKind, VerifierValueWidth,
};
use bpfopt::passes::PASS_REGISTRY;
#[cfg(test)]
use bpfopt::verifier_log::VerifierInsnJson;
use bpfopt::verifier_log::{
    verifier_states_from_log, VerifierRegJson, VerifierStackJson, VerifierStatesJson,
};
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

    let mut program = BpfProgram::new(read_bytecode(common.input.as_deref())?);
    attach_program_inputs(&mut program, common)?;
    let mut ctx = build_pass_context(common)?;
    validate_required_kinsns(&ctx, &[pass_name])?;
    ctx.policy.enabled_passes = vec![pass_name.to_string()];
    let pipeline = build_pipeline(&[pass_name], pass_args)?;
    let result = pipeline.run(&mut program, &ctx)?;
    write_bytecode(common.output.as_deref(), &program.insns)?;
    write_btf_info_outputs(common, &program)?;

    if let Some(report_path) = common.report.as_deref() {
        if result.pass_results.len() != 1 {
            bail!(
                "requested pass {pass_name} returned {} pass reports",
                result.pass_results.len()
            );
        }
        let report = pass_report(pass_name, &result.pass_results[0]);
        write_json(Some(report_path), &report)?;
    }

    Ok(())
}

fn build_pipeline(pass_names: &[&str], pass_args: &[String]) -> Result<PassManager> {
    let mut pm = PassManager::new();

    for &name in pass_names {
        let entry = registry_entry(name)?;
        pm.add_pass_boxed((entry.make)(pass_args)?);
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
    Ok(bytes
        .chunks_exact(8)
        .map(|chunk| BpfInsn::from_raw_bytes(chunk.try_into().expect("chunk is 8 bytes")))
        .collect())
}

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

fn attach_program_inputs(program: &mut BpfProgram, common: &CommonArgs) -> Result<()> {
    if let Some(path) = common.verifier_states.as_deref() {
        program.set_verifier_states(read_verifier_states(path)?);
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
    let mut ctx = PassContext::baseline();
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
            _ => eprintln!("bpfopt: warning: ignoring unknown target feature: {feature}"),
        }
    }
    Ok(())
}

fn read_target(path: &Path) -> Result<TargetJson> {
    read_json_file(path, "target.json")
}

fn kinsn_registry_from_target(target: &TargetJson) -> Result<KinsnRegistry> {
    let mut registry = KinsnRegistry::unavailable();
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
    KinsnRegistry::unavailable()
        .canonical_name_for_target_name(input)
        .ok_or_else(|| anyhow!("unknown kinsn name: {input}"))
}

fn read_verifier_states(path: &Path) -> Result<Vec<VerifierInsn>> {
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

fn read_json_file<T: for<'de> Deserialize<'de>>(path: &Path, label: &str) -> Result<T> {
    let data = fs::read(path).with_context(|| format!("failed to read {}", path.display()))?;
    serde_json::from_slice(&data)
        .with_context(|| format!("failed to parse {label} from {}", path.display()))
}

fn pass_report(pass_name: &str, result: &PassResult) -> PassReport {
    let mut skip_reasons = BTreeMap::new();
    for skip in &result.sites_skipped {
        *skip_reasons.entry(skip.reason.clone()).or_insert(0) += 1;
    }
    PassReport {
        pass: pass_name.to_string(),
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
    use bpfopt::insn::{MapPseudo, BPF_DW, BPF_IMM, BPF_LD};

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

    fn make_ld_imm64(dst: u8, src: u8, imm: i32) -> [BpfInsn; 2] {
        [
            BpfInsn::new(
                BPF_LD | BPF_DW | BPF_IMM,
                BpfInsn::make_regs(dst, src),
                0,
                imm,
            ),
            BpfInsn::new(0, 0, 0, 0),
        ]
    }

    fn pseudo_pairs(insns: &[BpfInsn]) -> Vec<(u8, i32, i32)> {
        insns
            .chunks_exact(2)
            .map(|pair| (pair[0].src_reg(), pair[0].imm, pair[1].imm))
            .collect()
    }

    fn kinsn_target(entries: &[(&str, i32, i16)]) -> TargetJson {
        TargetJson {
            arch: Some("x86_64".to_string()),
            features: Vec::new(),
            kinsns: entries
                .iter()
                .map(|(name, btf_func_id, call_offset)| {
                    (
                        (*name).to_string(),
                        KinsnJson {
                            btf_func_id: *btf_func_id,
                            btf_id: *btf_func_id as u32,
                            call_offset: *call_offset,
                        },
                    )
                })
                .collect(),
        }
    }

    fn registered_call_name(registry: &KinsnRegistry, btf_id: i32, call_off: i16) -> &'static str {
        registry
            .lookup_by_kinsn_call(btf_id, call_off)
            .unwrap()
            .canonical_name
    }

    #[test]
    fn canonicalize_map_refs_rewrites_fd_pseudos_in_first_seen_order() {
        let mut insns = Vec::new();
        insns.extend(make_ld_imm64(1, MapPseudo::Fd.src_reg(), 489));
        insns.extend(make_ld_imm64(1, MapPseudo::FdValue.src_reg(), 466));
        insns.extend(make_ld_imm64(1, MapPseudo::Fd.src_reg(), 489));

        canonicalize_map_refs_to_idx(&mut insns, None, &[101, 102]).unwrap();

        assert_eq!(
            pseudo_pairs(&insns),
            vec![
                (MapPseudo::Idx.src_reg(), 0, 0),
                (MapPseudo::IdxValue.src_reg(), 1, 0),
                (MapPseudo::Idx.src_reg(), 0, 0),
            ]
        );
    }

    #[test]
    fn canonicalize_map_refs_checks_idx_range_without_fd_array() {
        let mut insns = Vec::new();
        insns.extend(make_ld_imm64(1, MapPseudo::Idx.src_reg(), 2));

        let err = canonicalize_map_refs_to_idx(&mut insns, None, &[42]).unwrap_err();

        assert!(err.to_string().contains("out of range"), "err={err:#}");
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
    fn canonical_kinsn_names_accept_all_v3_aliases() {
        for (input, expected) in [
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
            ("bpf_endian_load16", "bpf_endian_load16"),
            ("endian_load16", "bpf_endian_load16"),
            ("bpf_endian_load32", "bpf_endian_load32"),
            ("endian_load32", "bpf_endian_load32"),
            ("bpf_endian_load64", "bpf_endian_load64"),
            ("endian_load64", "bpf_endian_load64"),
            ("bpf_bulk_memcpy", "bpf_bulk_memcpy"),
            ("bulk_memcpy", "bpf_bulk_memcpy"),
            ("bpf_memcpy_bulk", "bpf_bulk_memcpy"),
            ("memcpy_bulk", "bpf_bulk_memcpy"),
            ("bpf_bulk_memset", "bpf_bulk_memset"),
            ("bulk_memset", "bpf_bulk_memset"),
            ("bpf_memset_bulk", "bpf_bulk_memset"),
            ("memset_bulk", "bpf_bulk_memset"),
            ("bpf_prefetch", "bpf_prefetch"),
            ("prefetch", "bpf_prefetch"),
        ] {
            assert_eq!(canonicalize_kinsn_name(input).unwrap(), expected);
        }
    }

    #[test]
    fn target_json_maps_v3_kinsn_aliases_to_registry_fields() {
        let mut target = kinsn_target(&[
            ("rotate32", 10, 1),
            ("bpf_bulk_memcpy", 11, 2),
            ("bpf_endian_load64", 12, 0),
            ("bpf_ccmp64", 13, 0),
            ("bpf_prefetch", 14, 7),
        ]);
        target.features = vec!["cmov".to_string(), "movbe".to_string()];

        let registry = kinsn_registry_from_target(&target).unwrap();
        for (name, btf_id) in [
            ("bpf_rotate32", 10),
            ("bpf_bulk_memcpy", 11),
            ("bpf_endian_load64", 12),
            ("bpf_ccmp64", 13),
            ("bpf_prefetch", 14),
        ] {
            assert_eq!(registry.btf_id_for_target_name(name).unwrap(), btf_id);
        }
        for (name, call_off) in [
            ("bpf_rotate32", 1),
            ("bpf_bulk_memcpy", 2),
            ("bpf_prefetch", 7),
        ] {
            assert_eq!(registry.call_off_for_target_name(name).unwrap(), call_off);
        }
    }

    #[test]
    fn target_json_disambiguates_module_local_btf_ids_by_call_offset() {
        let target = kinsn_target(&[
            ("bpf_endian_load16", 128703, 1),
            ("bpf_rotate64", 128703, 2),
        ]);
        let registry = kinsn_registry_from_target(&target).unwrap();

        assert_eq!(
            registered_call_name(&registry, 128703, 1),
            "bpf_endian_load16"
        );
        assert_eq!(registered_call_name(&registry, 128703, 2), "bpf_rotate64");
    }

    #[test]
    fn target_json_allows_shared_btf_id_when_zero_call_offset_is_first() {
        let target = kinsn_target(&[
            ("bpf_endian_load16", 128703, 0),
            ("bpf_rotate64", 128703, 2),
        ]);
        let registry = kinsn_registry_from_target(&target).unwrap();

        assert_eq!(
            registered_call_name(&registry, 128703, 0),
            "bpf_endian_load16"
        );
        assert_eq!(registered_call_name(&registry, 128703, 2), "bpf_rotate64");
    }

    #[test]
    fn target_json_rejects_ambiguous_duplicate_kinsn_call_keys() {
        let target = kinsn_target(&[
            ("bpf_endian_load16", 128703, 1),
            ("bpf_rotate64", 128703, 1),
        ]);

        let err = kinsn_registry_from_target(&target).unwrap_err();

        assert!(
            err.to_string().contains("btf_id 128703 call_off 1"),
            "err={err}"
        );
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
    fn target_call_offsets_shift_after_map_prefix() {
        let mut target = TargetJson {
            arch: Some("x86_64".to_string()),
            features: Vec::new(),
            kinsns: BTreeMap::from([
                (
                    "bpf_rotate64".to_string(),
                    KinsnJson {
                        btf_func_id: 1,
                        btf_id: 100,
                        call_offset: 1,
                    },
                ),
                (
                    "bpf_extract64".to_string(),
                    KinsnJson {
                        btf_func_id: 2,
                        btf_id: 200,
                        call_offset: 2,
                    },
                ),
                (
                    "bpf_select64".to_string(),
                    KinsnJson {
                        btf_func_id: 3,
                        btf_id: 0,
                        call_offset: 0,
                    },
                ),
            ]),
        };

        shift_target_module_call_offsets_for_map_prefix(&mut target, 5).unwrap();

        assert_eq!(target.kinsns["bpf_rotate64"].call_offset, 5);
        assert_eq!(target.kinsns["bpf_extract64"].call_offset, 6);
        assert_eq!(target.kinsns["bpf_select64"].call_offset, 0);
    }

    #[test]
    fn pass_report_serializes_inlined_map_entries_as_hex() {
        let result = PassResult {
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

        let report = serde_json::to_value(pass_report("map_inline", &result)).unwrap();

        assert_eq!(report["inlined_map_entries"][0]["map_id"], 7);
        assert_eq!(report["inlined_map_entries"][0]["key_hex"], "01000000");
        assert_eq!(report["inlined_map_entries"][0]["value_hex"], "2a000000");
    }

    #[test]
    fn verifier_states_json_builds_const_prop_delta_states() {
        let state = VerifierInsnJson {
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
