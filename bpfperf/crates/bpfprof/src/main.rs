// SPDX-License-Identifier: MIT
//! bpfprof CLI entry point.
//!
//! Per-site profiling maps PMU samples at JIT instruction addresses back to
//! BPF bytecode PCs. LBR samples provide path and tail-call observations;
//! precise retired-branch samples provide real taken/not-taken direction.
//! Missing JIT metadata, unavailable PMU events, or perf ring loss are hard
//! errors.

use std::collections::{BTreeMap, BTreeSet};
use std::fs::{self, File};
use std::io::Write;
use std::os::fd::{AsFd, AsRawFd, OwnedFd};
use std::path::{Path, PathBuf};
use std::process::ExitCode;
use std::ptr::{copy_nonoverlapping, NonNull};
use std::sync::atomic::{fence, Ordering};
use std::thread;
use std::time::{Duration, Instant};

use anyhow::{anyhow, bail, Context, Result};
use clap::{Parser, ValueEnum};
use serde::Serialize;

const POLL_SLICE: Duration = Duration::from_millis(10);
const PERF_RING_DATA_PAGES: usize = 1024;
/* BPF JIT execution is a small fraction of all kernel branches.  A million
 * branch period can therefore produce a valid global LBR stream while
 * yielding no BPF-mapped samples, even for programs that run millions of
 * times during the training window. */
const DEFAULT_PERF_SAMPLE_PERIOD: u64 = 200_000;
const PERF_EVENT_HEADER_SIZE: usize = 8;
const PERF_RECORD_LOST: u32 = 2;
const PERF_RECORD_THROTTLE: u32 = 5;
const PERF_RECORD_UNTHROTTLE: u32 = 6;
const PERF_RECORD_SAMPLE: u32 = 9;
const PERF_RECORD_MISC_EXACT_IP: u16 = 1 << 14;
const PERF_BRANCH_ENTRY_SIZE: usize = std::mem::size_of::<kernel_sys::perf_branch_entry>();
const PERF_BRANCH_ENTRY_TYPE_SHIFT: u64 = 20;
const PERF_BRANCH_ENTRY_TYPE_MASK: u64 = 0xf;
const PERF_BR_UNKNOWN: u64 = 0;
const PERF_BR_COND: u64 = 1;

#[derive(Clone, Copy, Debug, ValueEnum)]
enum PrecisePmuSource {
    CpuCore,
    Cpu,
}

#[derive(Parser, Debug)]
#[command(name = "bpfprof", version, about = "Profile live BPF programs")]
struct Cli {
    /// Profile one live BPF program ID.
    #[arg(long, conflicts_with_all = ["all", "prog_ids"], value_name = "N")]
    prog_id: Option<u32>,
    /// Profile a comma-separated set of live BPF program IDs.
    #[arg(long, conflicts_with_all = ["all", "prog_id"], value_name = "CSV")]
    prog_ids: Option<String>,
    /// Profile all live BPF programs.
    #[arg(long)]
    all: bool,
    /// Collect real per-site branch profile data using PMU branch-stack samples.
    #[arg(long)]
    per_site: bool,
    /// Leave BPF run-count/runtime accounting disabled during PMU sampling.
    #[arg(long)]
    no_run_stats: bool,
    /// Use precise taken/not-taken retired-branch events instead of LBR edges.
    #[arg(long, conflicts_with = "tail_target_key_map")]
    precise_branch_direction: bool,
    /// PMU event source for precise taken/not-taken sampling.
    #[arg(long, value_enum, default_value = "cpu-core")]
    precise_pmu_source: PrecisePmuSource,
    /// Sampling window, such as 500ms, 1s, or 250ms.
    #[arg(long, value_parser = parse_duration, value_name = "TIME")]
    duration: Duration,
    /// Hardware branch-instruction sample period.
    #[arg(long, default_value_t = DEFAULT_PERF_SAMPLE_PERIOD, value_name = "N")]
    sample_period: u64,
    /// Limit per-CPU PMU events to tasks in this cgroup.
    #[arg(long, value_name = "PATH")]
    cgroup: Option<PathBuf>,
    /// JSON object mapping live prog_id to shim-dumped source bytecode path.
    #[arg(long, value_name = "FILE")]
    source_bytecode_map: Option<PathBuf>,
    /// JSON object mapping tail-call target prog_id to its unique program-array key.
    #[arg(long, value_name = "FILE", requires = "source_bytecode_map")]
    tail_target_key_map: Option<PathBuf>,
    /// Collect tail-call edges without mapping unrelated conditional branch sites.
    #[arg(
        long,
        requires = "tail_target_key_map",
        conflicts_with = "precise_branch_direction"
    )]
    tail_only: bool,
    /// Discover live BPF programs from periodic bpfrejit shim state JSON files.
    #[arg(long, value_name = "DIR")]
    discover_shim_state_dir: Option<PathBuf>,
    /// Output profile JSON file for --prog-id, or JSON array for --all.
    #[arg(long, value_name = "FILE")]
    output: Option<PathBuf>,
    /// Output directory for --all; writes one <prog_id>.json per program.
    #[arg(long, value_name = "DIR")]
    output_dir: Option<PathBuf>,
    /// Create this file only after PMU rings are enabled and sampling is live.
    #[arg(long, value_name = "FILE")]
    ready_file: Option<PathBuf>,
}

#[derive(Debug)]
struct Target {
    prog_id: u32,
    fd: OwnedFd,
}

#[derive(Clone, Copy, Debug, Default, PartialEq, Eq)]
struct ProgStats {
    run_cnt: u64,
    run_time_ns: u64,
}

#[derive(Clone, Debug, Serialize, PartialEq)]
struct ProfileJson {
    prog_id: u32,
    duration_ms: u64,
    run_cnt_delta: u64,
    run_time_ns_delta: u64,
    branch_miss_rate: f64,
    branch_misses: u64,
    branch_instructions: u64,
    per_site: BTreeMap<String, PerSiteProfile>,
    #[serde(skip_serializing_if = "Option::is_none")]
    tail_call_sites: Option<BTreeMap<String, TailCallSiteProfile>>,
}

#[derive(Clone, Debug, Serialize, PartialEq)]
struct PerSiteProfile {
    branch_count: u64,
    branch_misses: u64,
    miss_rate: f64,
    taken: u64,
    not_taken: u64,
}

#[derive(Clone, Debug, Serialize, PartialEq, Eq)]
struct TailCallSiteProfile {
    observations: u64,
    key_counts: BTreeMap<u32, u64>,
    #[serde(skip_serializing_if = "BTreeMap::is_empty")]
    pid_key_counts: BTreeMap<u32, BTreeMap<u32, u64>>,
    #[serde(skip_serializing_if = "BTreeMap::is_empty")]
    tid_key_counts: BTreeMap<u32, BTreeMap<u32, u64>>,
}

#[derive(Clone, Debug, Default, PartialEq, Eq)]
struct SiteCounters {
    branch_count: u64,
    branch_misses: u64,
    taken: u64,
    not_taken: u64,
}

#[derive(Clone, Debug, Default, PartialEq, Eq)]
struct TargetSamples {
    sample_records: u64,
    sites: BTreeMap<usize, SiteCounters>,
    tail_call_sites: BTreeMap<usize, BTreeMap<u32, u64>>,
    tail_call_pid_key_counts: BTreeMap<usize, BTreeMap<u32, BTreeMap<u32, u64>>>,
    tail_call_tid_key_counts: BTreeMap<usize, BTreeMap<u32, BTreeMap<u32, u64>>>,
    precise_in_jit: u64,
    precise_nonconditional_pc: u64,
    precise_no_native_site: u64,
    precise_profile_pc_miss: u64,
}

#[derive(Clone, Debug)]
struct JitPcMap {
    ranges: Vec<JitFuncRange>,
    lines: Vec<kernel_sys::JitedLineInfo>,
    native_branch_sites: Vec<NativeBranchSite>,
}

#[derive(Clone, Copy, Debug)]
struct JitFuncRange {
    start_addr: u64,
    end_addr: u64,
}

#[derive(Clone, Copy, Debug)]
struct NativeBranchSite {
    pebs_start_addr: u64,
    start_addr: u64,
    end_addr: u64,
    fallthrough_addr: u64,
    jump_target_addr: u64,
    condition: u8,
    pc: usize,
    jump_is_bpf_target: bool,
}

struct TargetProfiler {
    target: Target,
    pc_map: JitPcMap,
    conditional_pcs: BTreeSet<usize>,
    profile_pcs: BTreeSet<usize>,
    tail_call_pcs: BTreeSet<usize>,
    profile_tail_call_pcs: BTreeSet<usize>,
    source_pc_by_xlated_pc: BTreeMap<usize, usize>,
}

#[derive(Clone, Debug, PartialEq, Eq)]
struct ShimStateProgram {
    prog_id: u32,
    bytecode_path: PathBuf,
}

#[derive(Clone, Copy, Debug)]
struct ResolvedIp {
    prog_id: u32,
    pc: usize,
}

#[derive(Clone, Copy, Debug)]
struct ResolvedBranchSource {
    prog_id: u32,
    target_idx: usize,
    pc: usize,
    native_branch_idx: Option<usize>,
}

#[derive(Clone, Copy, Debug)]
struct ResolvedBranch {
    prog_id: u32,
    target_idx: usize,
    pc: usize,
    taken: bool,
}

#[derive(Clone, Debug)]
struct JitIpResolver {
    ranges: Vec<JitIpRange>,
    tail_target_keys: BTreeMap<u32, u32>,
}

#[derive(Clone, Copy, Debug)]
struct JitIpRange {
    start_addr: u64,
    end_addr: u64,
    prog_id: u32,
    target_idx: usize,
}

struct LbrPerfEvents {
    rings: Vec<PerfSampleRing>,
    _cgroup: Option<File>,
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
enum PerfSampleKind {
    Lbr { sample_tid: bool },
    PreciseBranch {
        native_taken: bool,
        mispredicted: bool,
    },
}

struct ProfileBuildInput {
    prog_id: u32,
    run_cnt_delta: u64,
    run_time_ns_delta: u64,
    expected_sites: BTreeSet<usize>,
    sites: BTreeMap<usize, SiteCounters>,
    tail_collection_enabled: bool,
    tail_call_sites: BTreeMap<usize, BTreeMap<u32, u64>>,
}

#[repr(C)]
#[derive(Clone, Copy, Debug)]
struct PerfEventHeader {
    type_: u32,
    misc: u16,
    size: u16,
}

#[repr(C)]
struct PerfEventMmapPage {
    version: u32,
    compat_version: u32,
    lock: u32,
    index: u32,
    offset: i64,
    time_enabled: u64,
    time_running: u64,
    capabilities: u64,
    pmc_width: u16,
    time_shift: u16,
    time_mult: u32,
    time_offset: u64,
    time_zero: u64,
    size: u32,
    __reserved_1: u32,
    time_cycles: u64,
    time_mask: u64,
    __reserved: [u8; 116 * 8],
    data_head: u64,
    data_tail: u64,
    data_offset: u64,
    data_size: u64,
}

struct PerfSampleRing {
    fd: OwnedFd,
    kind: PerfSampleKind,
    mapping: NonNull<u8>,
    mapping_len: usize,
    data_offset: usize,
    data_size: usize,
}

fn main() -> ExitCode {
    match run() {
        Ok(()) => ExitCode::SUCCESS,
        Err(err) => {
            eprintln!("{err:#}");
            ExitCode::FAILURE
        }
    }
}

fn run() -> Result<()> {
    let cli = Cli::parse();
    validate_cli(&cli)?;

    let targets = collect_targets(&cli)?;
    if targets.is_empty() && cli.discover_shim_state_dir.is_none() {
        return write_empty_outputs(&cli);
    }
    let source_bytecode_paths = read_source_bytecode_map(cli.source_bytecode_map.as_deref())?;
    let tail_target_keys = read_tail_target_key_map(cli.tail_target_key_map.as_deref())?;

    let _stats_fd = if cli.no_run_stats {
        None
    } else {
        Some(
            kernel_sys::enable_stats(kernel_sys::BPF_STATS_RUN_TIME)
                .context("BPF_ENABLE_STATS(BPF_STATS_RUN_TIME)")?,
        )
    };
    let mut profilers = Vec::new();
    let mut before = BTreeMap::new();
    for target in targets {
        let source_bytecode = source_bytecode_paths
            .get(&target.prog_id)
            .map(PathBuf::as_path);
        add_target_profiler(
            &mut profilers,
            &mut before,
            target,
            source_bytecode,
            !tail_target_keys.is_empty(),
            cli.tail_only,
        )?;
    }
    let mut lbr_events = LbrPerfEvents::open(
        cli.sample_period,
        cli.cgroup.as_deref(),
        cli.precise_branch_direction,
        cli.precise_pmu_source,
    )?;
    lbr_events.reset_and_enable()?;
    if let Some(path) = &cli.ready_file {
        if path.exists() {
            bail!("--ready-file already exists: {}", path.display());
        }
        let mut ready =
            File::create(path).with_context(|| format!("create ready file {}", path.display()))?;
        ready
            .write_all(b"ready\n")
            .with_context(|| format!("write ready file {}", path.display()))?;
        ready
            .sync_all()
            .with_context(|| format!("sync ready file {}", path.display()))?;
    }
    let mut samples = BTreeMap::new();
    collect_lbr_samples(
        cli.duration,
        &cli,
        &mut lbr_events,
        &mut profilers,
        &mut before,
        &mut samples,
        &tail_target_keys,
    )?;
    lbr_events.disable()?;
    if cli.discover_shim_state_dir.is_some() {
        discover_new_shim_state_targets(&cli, &mut profilers, &mut before)?;
    }
    let resolver = JitIpResolver::from_profilers(&profilers, &tail_target_keys)?;
    lbr_events.drain(&resolver, &profilers, &mut samples)?;
    let after = read_snapshots(&profilers)?;

    let duration_ms = duration_ms(cli.duration)?;
    let profiles = build_profiles(&cli, profilers, samples, &before, &after, duration_ms)?;
    write_profiles(&cli, &profiles)?;
    Ok(())
}

fn validate_cli(cli: &Cli) -> Result<()> {
    if cli.prog_id.is_none()
        && cli.prog_ids.is_none()
        && !cli.all
        && cli.discover_shim_state_dir.is_none()
    {
        bail!("one of --prog-id N, --prog-ids CSV, --all, or --discover-shim-state-dir DIR is required");
    }
    if !cli.per_site {
        bail!("bpfprof requires --per-site; program-level-only PMU output has been removed");
    }
    if cli.duration.is_zero() {
        bail!("--duration must be greater than zero");
    }
    if cli.sample_period == 0 {
        bail!("--sample-period must be greater than zero");
    }
    if cli.output_dir.is_some()
        && !cli.all
        && cli.prog_ids.is_none()
        && cli.discover_shim_state_dir.is_none()
    {
        bail!("--output-dir is only valid with --all, --prog-ids, or --discover-shim-state-dir");
    }
    if (cli.all || cli.prog_ids.is_some()) && cli.output.is_some() && cli.output_dir.is_some() {
        bail!("choose only one of --output or --output-dir with --all/--prog-ids");
    }
    if cli.discover_shim_state_dir.is_some() && cli.output_dir.is_none() {
        bail!("--discover-shim-state-dir requires --output-dir");
    }
    if cli.output.is_none() && cli.output_dir.is_none() {
        bail!("profile JSON side-output requires --output FILE or --output-dir DIR");
    }
    Ok(())
}

fn collect_targets(cli: &Cli) -> Result<Vec<Target>> {
    if let Some(prog_id) = cli.prog_id {
        return Ok(vec![open_target(prog_id)?]);
    }
    if let Some(raw_ids) = &cli.prog_ids {
        let mut targets = Vec::new();
        for prog_id in parse_prog_ids(raw_ids)? {
            targets.push(open_target(prog_id)?);
        }
        return Ok(targets);
    }

    if !cli.all {
        return Ok(Vec::new());
    }

    let mut ids = Vec::new();
    let mut start_id = 0;
    loop {
        let Some(next) = kernel_sys::prog_get_next_id(start_id)
            .with_context(|| format!("enumerate BPF programs after id {start_id}"))?
        else {
            break;
        };
        ids.push(next);
        start_id = next;
    }

    let mut targets = Vec::new();
    for prog_id in ids {
        match open_target(prog_id) {
            Ok(target) => targets.push(target),
            Err(err) if error_is_enoent(&err) => continue,
            Err(err) => return Err(err),
        }
    }
    Ok(targets)
}

fn add_target_profiler(
    profilers: &mut Vec<TargetProfiler>,
    before: &mut BTreeMap<u32, ProgStats>,
    target: Target,
    source_bytecode: Option<&Path>,
    tail_collection_enabled: bool,
    tail_only: bool,
) -> Result<()> {
    let profiler =
        TargetProfiler::open(target, source_bytecode, tail_collection_enabled, tail_only)?;
    let stats = read_snapshot(&profiler)?;
    before.insert(profiler.target.prog_id, stats);
    profilers.push(profiler);
    Ok(())
}

fn discover_new_shim_state_targets(
    cli: &Cli,
    profilers: &mut Vec<TargetProfiler>,
    before: &mut BTreeMap<u32, ProgStats>,
) -> Result<()> {
    let Some(dir) = cli.discover_shim_state_dir.as_deref() else {
        return Ok(());
    };
    let mut known = BTreeSet::new();
    for profiler in profilers.iter() {
        known.insert(profiler.target.prog_id);
    }
    for program in discover_shim_state_programs(dir)? {
        if known.contains(&program.prog_id) {
            continue;
        }
        let target = open_target(program.prog_id).with_context(|| {
            format!(
                "open discovered BPF program id {} from shim state",
                program.prog_id
            )
        })?;
        add_target_profiler(
            profilers,
            before,
            target,
            Some(program.bytecode_path.as_path()),
            cli.tail_target_key_map.is_some(),
            cli.tail_only,
        )?;
        known.insert(program.prog_id);
    }
    Ok(())
}

fn parse_prog_ids(raw: &str) -> Result<Vec<u32>> {
    let mut ids = Vec::new();
    for part in raw.split(',') {
        let text = part.trim();
        if text.is_empty() {
            continue;
        }
        let id = text
            .parse::<u32>()
            .with_context(|| format!("parse --prog-ids entry {text:?}"))?;
        if id == 0 {
            bail!("--prog-ids entries must be positive BPF program IDs");
        }
        if !ids.contains(&id) {
            ids.push(id);
        }
    }
    if ids.is_empty() {
        bail!("--prog-ids must contain at least one BPF program ID");
    }
    Ok(ids)
}

fn open_target(prog_id: u32) -> Result<Target> {
    let fd = kernel_sys::prog_get_fd_by_id(prog_id)
        .with_context(|| format!("open BPF program id {prog_id}"))?;
    Ok(Target { prog_id, fd })
}

impl TargetProfiler {
    fn open(
        target: Target,
        source_bytecode: Option<&Path>,
        tail_collection_enabled: bool,
        tail_only: bool,
    ) -> Result<Self> {
        let xlated_insns = kernel_sys::prog_xlated_insns(target.fd.as_fd()).with_context(|| {
            format!(
                "read translated bytecode for BPF program id {}",
                target.prog_id
            )
        })?;
        if xlated_insns.is_empty() {
            bail!(
                "target BPF program id {} returned empty translated bytecode",
                target.prog_id
            );
        }
        let conditional_pcs = if tail_only {
            BTreeSet::new()
        } else {
            conditional_branch_pcs(&xlated_insns)
        };
        let tail_call_pcs = tail_call_helper_pcs(&xlated_insns);
        let pc_map = JitPcMap::from_prog(target.fd.as_fd(), &xlated_insns, &conditional_pcs)
            .with_context(|| format!("read JIT PC map for BPF program id {}", target.prog_id))?;
        if tail_collection_enabled && tail_call_pcs.len() > 1 && pc_map.lines.is_empty() {
            bail!(
                "BPF program id {} contains {} tail-call sites but has no JIT line info; exact BPF-PC attribution for tail-call LBR edges is unavailable",
                target.prog_id,
                tail_call_pcs.len(),
            );
        }
        let (profile_pcs, profile_tail_call_pcs, source_pc_by_xlated_pc) = match source_bytecode {
            Some(path) => {
                let source_insns = read_source_bytecode(path)
                    .with_context(|| format!("read source bytecode {}", path.display()))?;
                let profile_pcs = if tail_only {
                    BTreeSet::new()
                } else {
                    conditional_branch_pcs(&source_insns)
                };
                let profile_tail_call_pcs = tail_call_helper_pcs(&source_insns);
                let source_pc_by_xlated_pc =
                    build_xlated_to_source_pc_remap(&xlated_insns, &source_insns, !tail_only)
                        .with_context(|| {
                            format!(
                                "map translated PCs to source bytecode PCs for BPF program id {}",
                                target.prog_id
                            )
                        })?;
                (profile_pcs, profile_tail_call_pcs, source_pc_by_xlated_pc)
            }
            None => (
                conditional_pcs.clone(),
                tail_call_pcs.clone(),
                BTreeMap::new(),
            ),
        };
        Ok(Self {
            target,
            pc_map,
            conditional_pcs,
            profile_pcs,
            tail_call_pcs,
            profile_tail_call_pcs,
            source_pc_by_xlated_pc,
        })
    }

    fn profile_pc_for_xlated_pc(&self, xlated_pc: usize) -> Option<usize> {
        if self.source_pc_by_xlated_pc.is_empty() {
            return Some(xlated_pc);
        }
        self.source_pc_by_xlated_pc.get(&xlated_pc).copied()
    }

    fn tail_call_pc_for_native_ip(&self, ip: u64) -> Result<Option<usize>> {
        if self.pc_map.lines.is_empty() {
            if !self.pc_map.contains_ip(ip) {
                return Ok(None);
            }
            return match self.tail_call_pcs.len() {
                0 => Ok(None),
                1 => Ok(self.tail_call_pcs.first().copied()),
                count => bail!(
                    "native tail-call branch for program id {} has no JIT line info and {} candidate translated tail-call sites",
                    self.target.prog_id,
                    count,
                ),
            };
        }
        let Some((line_start, line_end)) =
            jited_line_pc_range_for_ip(&self.pc_map.ranges, &self.pc_map.lines, ip)
        else {
            return Ok(None);
        };
        let mut candidates = self.tail_call_pcs.range(line_start..line_end);
        let first = candidates.next().copied();
        if let Some(second) = candidates.next() {
            bail!(
                "native tail-call branch for program id {} maps to source-line PC range {}..{} containing multiple translated tail-call sites ({}, {})",
                self.target.prog_id,
                line_start,
                line_end,
                first.expect("second candidate requires a first candidate"),
                second,
            );
        }
        Ok(first)
    }
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
struct NormalizedInsn {
    code: u8,
    dst_reg: u8,
    src_reg: u8,
    off: i16,
    imm: i32,
}

fn read_source_bytecode_map(path: Option<&Path>) -> Result<BTreeMap<u32, PathBuf>> {
    let Some(path) = path else {
        return Ok(BTreeMap::new());
    };
    let value: serde_json::Value = serde_json::from_slice(
        &fs::read(path).with_context(|| format!("read {}", path.display()))?,
    )
    .with_context(|| format!("parse {}", path.display()))?;
    let object = value
        .as_object()
        .ok_or_else(|| anyhow!("{} root must be a JSON object", path.display()))?;
    let mut out = BTreeMap::new();
    for (key, value) in object {
        let prog_id = key
            .parse::<u32>()
            .with_context(|| format!("parse source bytecode map prog_id key {key:?}"))?;
        if prog_id == 0 {
            bail!("source bytecode map prog_id keys must be positive");
        }
        let path = value.as_str().ok_or_else(|| {
            anyhow!("source bytecode map value for prog_id {prog_id} is not a string")
        })?;
        if path.is_empty() {
            bail!("source bytecode map value for prog_id {prog_id} is empty");
        }
        out.insert(prog_id, PathBuf::from(path));
    }
    Ok(out)
}

fn read_tail_target_key_map(path: Option<&Path>) -> Result<BTreeMap<u32, u32>> {
    let Some(path) = path else {
        return Ok(BTreeMap::new());
    };
    let value: serde_json::Value = serde_json::from_slice(
        &fs::read(path).with_context(|| format!("read {}", path.display()))?,
    )
    .with_context(|| format!("parse {}", path.display()))?;
    let object = value
        .as_object()
        .ok_or_else(|| anyhow!("{} root must be a JSON object", path.display()))?;
    let mut out = BTreeMap::new();
    for (raw_prog_id, raw_key) in object {
        let prog_id = raw_prog_id
            .parse::<u32>()
            .with_context(|| format!("parse tail target prog_id key {raw_prog_id:?}"))?;
        if prog_id == 0 {
            bail!("tail target prog_id keys must be positive");
        }
        let key = raw_key
            .as_u64()
            .ok_or_else(|| anyhow!("tail target key for prog_id {prog_id} must be u32"))?;
        let key: u32 = key
            .try_into()
            .with_context(|| format!("tail target key for prog_id {prog_id} exceeds u32"))?;
        out.insert(prog_id, key);
    }
    Ok(out)
}

fn discover_shim_state_programs(dir: &Path) -> Result<Vec<ShimStateProgram>> {
    if !dir.is_dir() {
        bail!(
            "shim state discovery directory does not exist: {}",
            dir.display()
        );
    }
    let mut paths = Vec::new();
    for entry in fs::read_dir(dir).with_context(|| format!("read {}", dir.display()))? {
        let entry = entry.with_context(|| format!("read entry under {}", dir.display()))?;
        let path = entry.path();
        let Some(name) = path.file_name().and_then(|name| name.to_str()) else {
            continue;
        };
        if name.starts_with("state_") && name.ends_with(".json") {
            paths.push(path);
        }
    }
    paths.sort();

    let mut programs = BTreeMap::new();
    for path in paths {
        let value: serde_json::Value = serde_json::from_slice(
            &fs::read(&path).with_context(|| format!("read {}", path.display()))?,
        )
        .with_context(|| format!("parse {}", path.display()))?;
        let object = value
            .as_object()
            .ok_or_else(|| anyhow!("{} root must be a JSON object", path.display()))?;
        let progs = object
            .get("progs")
            .and_then(serde_json::Value::as_array)
            .ok_or_else(|| anyhow!("{} missing progs array", path.display()))?;
        for item in progs {
            let item = item
                .as_object()
                .ok_or_else(|| anyhow!("{} contains non-object prog entry", path.display()))?;
            let raw_id = item
                .get("kernel_prog_id")
                .and_then(serde_json::Value::as_u64)
                .ok_or_else(|| anyhow!("{} prog entry missing kernel_prog_id", path.display()))?;
            if raw_id == 0 {
                continue;
            }
            let prog_id: u32 = raw_id.try_into().with_context(|| {
                format!(
                    "{} kernel_prog_id {raw_id} does not fit u32",
                    path.display()
                )
            })?;
            let bytecode_path = item
                .get("bytecode_path")
                .and_then(serde_json::Value::as_str)
                .ok_or_else(|| {
                    anyhow!(
                        "{} prog entry for id {prog_id} missing bytecode_path",
                        path.display()
                    )
                })?;
            if bytecode_path.is_empty() {
                bail!(
                    "{} prog entry for id {prog_id} has empty bytecode_path",
                    path.display()
                );
            }
            let bytecode_path = PathBuf::from(bytecode_path);
            let source_insns = read_source_bytecode(&bytecode_path).with_context(|| {
                format!("read source bytecode for discovered BPF program id {prog_id}")
            })?;
            if conditional_branch_pcs(&source_insns).is_empty()
                && tail_call_helper_pcs(&source_insns).is_empty()
            {
                continue;
            }
            programs.insert(
                prog_id,
                ShimStateProgram {
                    prog_id,
                    bytecode_path,
                },
            );
        }
    }
    Ok(programs.into_values().collect())
}

fn read_source_bytecode(path: &Path) -> Result<Vec<kernel_sys::bpf_insn>> {
    let raw = fs::read(path).with_context(|| format!("read {}", path.display()))?;
    let stride = std::mem::size_of::<kernel_sys::bpf_insn>();
    if raw.is_empty() {
        bail!("{} is empty", path.display());
    }
    if !raw.len().is_multiple_of(stride) {
        bail!(
            "{} length {} is not a multiple of struct bpf_insn size {}",
            path.display(),
            raw.len(),
            stride
        );
    }
    let mut insns = vec![kernel_sys::bpf_insn::default(); raw.len() / stride];
    unsafe { copy_nonoverlapping(raw.as_ptr(), insns.as_mut_ptr().cast(), raw.len()) };
    Ok(insns)
}

fn build_xlated_to_source_pc_remap(
    xlated: &[kernel_sys::bpf_insn],
    source: &[kernel_sys::bpf_insn],
    include_conditional_sites: bool,
) -> Result<BTreeMap<usize, usize>> {
    if source.is_empty() {
        bail!("source bytecode is empty");
    }
    let xlated_keys = normalized_insns(xlated);
    let source_keys = normalized_insns(source);
    let lcs_map = lcs_pc_map(&xlated_keys, &source_keys);
    let source_conditional_pcs = if include_conditional_sites {
        conditional_branch_pcs(source)
    } else {
        BTreeSet::new()
    };
    let source_tail_call_pcs = tail_call_helper_pcs(source);
    let xlated_conditional_pcs = if include_conditional_sites {
        conditional_branch_pcs(xlated)
    } else {
        BTreeSet::new()
    };
    let xlated_tail_call_pcs = tail_call_helper_pcs(xlated);
    let mut xlated_profile_pcs = xlated_conditional_pcs.clone();
    xlated_profile_pcs.extend(xlated_tail_call_pcs.iter().copied());
    let mut out = BTreeMap::new();
    for pc in xlated_profile_pcs {
        let Some(source_pc) = lcs_map.get(&pc).copied() else {
            continue;
        };
        if xlated_conditional_pcs.contains(&pc) && !source_conditional_pcs.contains(&source_pc) {
            bail!("translated conditional pc {pc} maps to non-conditional source pc {source_pc}");
        }
        if xlated_tail_call_pcs.contains(&pc) && !source_tail_call_pcs.contains(&source_pc) {
            bail!("translated tail-call pc {pc} maps to non-tail-call source pc {source_pc}");
        }
        out.insert(pc, source_pc);
    }
    Ok(out)
}

fn normalized_insns(insns: &[kernel_sys::bpf_insn]) -> Vec<NormalizedInsn> {
    (0..insns.len())
        .map(|pc| normalized_insn(insns, pc))
        .collect()
}

fn normalized_insn(insns: &[kernel_sys::bpf_insn], pc: usize) -> NormalizedInsn {
    let insn = &insns[pc];
    let mut out = NormalizedInsn {
        code: insn.code,
        dst_reg: insn.dst_reg(),
        src_reg: insn.src_reg(),
        off: insn.off,
        imm: insn.imm,
    };
    if is_conditional_branch_opcode(insn.code) {
        out.off = 0;
        return out;
    }
    if is_ldimm64(insn) {
        let src = insn.src_reg();
        if matches!(
            src,
            x if x == kernel_sys::BPF_PSEUDO_MAP_FD as u8
                || x == kernel_sys::BPF_PSEUDO_MAP_VALUE as u8
                || x == kernel_sys::BPF_PSEUDO_MAP_IDX as u8
                || x == kernel_sys::BPF_PSEUDO_MAP_IDX_VALUE as u8
        ) {
            out.src_reg = 0;
            out.imm = 0;
        }
        return out;
    }
    if pc > 0 && is_ldimm64(&insns[pc - 1]) {
        let prev_src = insns[pc - 1].src_reg();
        if matches!(
            prev_src,
            x if x == kernel_sys::BPF_PSEUDO_MAP_FD as u8
                || x == kernel_sys::BPF_PSEUDO_MAP_VALUE as u8
                || x == kernel_sys::BPF_PSEUDO_MAP_IDX as u8
                || x == kernel_sys::BPF_PSEUDO_MAP_IDX_VALUE as u8
        ) {
            out.imm = 0;
        }
    }
    out
}

fn is_ldimm64(insn: &kernel_sys::bpf_insn) -> bool {
    insn.code == (kernel_sys::BPF_LD | kernel_sys::BPF_DW | kernel_sys::BPF_IMM) as u8
}

fn lcs_pc_map(xlated: &[NormalizedInsn], source: &[NormalizedInsn]) -> BTreeMap<usize, usize> {
    let rows = xlated.len() + 1;
    let cols = source.len() + 1;
    let mut prev = vec![0u16; cols];
    let mut curr = vec![0u16; cols];
    let mut dirs = vec![0u8; rows * cols];
    for i in 1..rows {
        std::mem::swap(&mut prev, &mut curr);
        curr[0] = 0;
        for j in 1..cols {
            let dir_idx = i * cols + j;
            if xlated[i - 1] == source[j - 1] {
                curr[j] = prev[j - 1].saturating_add(1);
                dirs[dir_idx] = 1;
            } else if prev[j] >= curr[j - 1] {
                curr[j] = prev[j];
                dirs[dir_idx] = 2;
            } else {
                curr[j] = curr[j - 1];
                dirs[dir_idx] = 3;
            }
        }
    }

    let mut i = xlated.len();
    let mut j = source.len();
    let mut out = BTreeMap::new();
    while i > 0 && j > 0 {
        match dirs[i * cols + j] {
            1 => {
                out.insert(i - 1, j - 1);
                i -= 1;
                j -= 1;
            }
            2 => i -= 1,
            3 => j -= 1,
            _ => break,
        }
    }
    out
}

fn conditional_branch_pcs(insns: &[kernel_sys::bpf_insn]) -> BTreeSet<usize> {
    insns
        .iter()
        .enumerate()
        .filter_map(|(pc, insn)| {
            (is_conditional_branch_opcode(insn.code) && insn.off != 0).then_some(pc)
        })
        .collect()
}

fn tail_call_helper_pcs(insns: &[kernel_sys::bpf_insn]) -> BTreeSet<usize> {
    insns
        .iter()
        .enumerate()
        .filter_map(|(pc, insn)| {
            (insn.code == 0x85
                && insn.src_reg() != kernel_sys::BPF_PSEUDO_CALL as u8
                && insn.imm == 12)
                .then_some(pc)
        })
        .collect()
}

fn is_conditional_branch_opcode(code: u8) -> bool {
    const BPF_CLASS_MASK: u8 = 0x07;
    const BPF_JMP_CLASS: u8 = 0x05;
    const BPF_JMP32_CLASS: u8 = 0x06;
    matches!(code & BPF_CLASS_MASK, BPF_JMP_CLASS | BPF_JMP32_CLASS)
        && !matches!(code, 0x05 | 0x06 | 0x85 | 0x8d | 0x95)
}

#[cfg(target_arch = "x86_64")]
fn native_branch_sites_from_jit(
    fd: std::os::fd::BorrowedFd<'_>,
    ranges: &[JitFuncRange],
    lines: Option<&[kernel_sys::JitedLineInfo]>,
    xlated_insns: &[kernel_sys::bpf_insn],
    conditional_pcs: &BTreeSet<usize>,
) -> Result<Vec<NativeBranchSite>> {
    let image = kernel_sys::prog_jited_insns(fd)?;
    if image.is_empty() {
        bail!("target BPF program has no line info and returned empty JIT image bytes");
    }
    let range_bytes = ranges.iter().try_fold(0usize, |acc, range| {
        let len = range
            .end_addr
            .checked_sub(range.start_addr)
            .ok_or_else(|| anyhow!("JIT function range end precedes start"))?;
        let len: usize = len
            .try_into()
            .map_err(|_| anyhow!("JIT function range length does not fit usize"))?;
        acc.checked_add(len)
            .ok_or_else(|| anyhow!("JIT function range byte length overflow"))
    })?;
    if image.len() != range_bytes {
        bail!(
            "target BPF program has no line info and JIT image length {} does not match function ranges {}",
            image.len(),
            range_bytes
        );
    }

    let mut sites = Vec::new();
    let mut offset = 0usize;
    for range in ranges {
        let len = (range.end_addr - range.start_addr) as usize;
        let func = &image[offset..offset + len];
        sites.extend(scan_x86_conditional_branches(
            func,
            range.start_addr,
            range.end_addr,
        )?);
        offset += len;
    }
    let mut mapped = BTreeMap::new();
    if let Some(lines) = lines {
        mapped = align_native_branch_sites_with_lines(
            sites,
            ranges,
            lines,
            xlated_insns,
            conditional_pcs,
            &image,
        )?;
    } else {
        if sites.len() != conditional_pcs.len() {
            bail!(
                "target BPF program has no line info and decoded {} native conditional branches, expected {} translated BPF conditional sites",
                sites.len(),
                conditional_pcs.len()
            );
        }
        for (mut site, pc) in sites.into_iter().zip(conditional_pcs) {
            site.pc = *pc;
            mapped.insert(*pc, site);
        }
    }

    let mut sites = Vec::with_capacity(mapped.len());
    for (pc, mut site) in mapped {
        let insn = xlated_insns
            .get(pc)
            .ok_or_else(|| anyhow!("translated BPF branch pc {pc} is outside bytecode"))?;
        let bpf_forward = insn.off > 0;
        let native_forward = site.jump_target_addr > site.fallthrough_addr;
        let fallthrough_is_jump = site.fallthrough_starts_unconditional_jump(func_addr_slice(
            &image,
            ranges,
            site.fallthrough_addr,
        )?);
        let raw_fallthrough_is_jump = xlated_insns
            .get(pc + 1)
            .is_some_and(|next| matches!(next.code, 0x05 | 0x06));
        let inverted_jcc = fallthrough_is_jump && !raw_fallthrough_is_jump;
        if !inverted_jcc && bpf_forward != native_forward {
            bail!(
                "native branch direction for BPF pc {pc} does not match BPF branch offset {} and has no inverted-Jcc jump sequence",
                insn.off
            );
        }
        /* The x86 JIT may invert the conditional and emit Jcc to the raw
         * fallthrough followed by an unconditional jump to the raw target.
         * Preserve that semantic mapping so native Jcc direction is not
         * mistaken for raw BPF taken/not-taken direction. */
        site.jump_is_bpf_target = !inverted_jcc;
        sites.push(site);
    }
    Ok(sites)
}

#[cfg(target_arch = "x86_64")]
#[derive(Clone, Copy)]
struct NativeBranchAlignmentCell {
    score: i64,
    ways: u8,
}

#[cfg(target_arch = "x86_64")]
fn align_native_branch_sites_with_lines(
    native_sites: Vec<NativeBranchSite>,
    ranges: &[JitFuncRange],
    lines: &[kernel_sys::JitedLineInfo],
    xlated_insns: &[kernel_sys::bpf_insn],
    conditional_pcs: &BTreeSet<usize>,
    image: &[u8],
) -> Result<BTreeMap<usize, NativeBranchSite>> {
    let raw_pcs = conditional_pcs.iter().copied().collect::<Vec<_>>();
    let line_ranges = native_sites
        .iter()
        .map(|site| {
            jited_line_pc_range_for_ip(ranges, lines, site.start_addr).ok_or_else(|| {
                anyhow!(
                    "native conditional branch at 0x{:x} has no JIT line mapping",
                    site.start_addr
                )
            })
        })
        .collect::<Result<Vec<_>>>()?;
    let raw_count = raw_pcs.len();
    let native_count = native_sites.len();
    let width = raw_count + 1;
    let action_len = (native_count + 1)
        .checked_mul(width)
        .ok_or_else(|| anyhow!("native branch alignment matrix size overflow"))?;
    let mut actions = vec![0u8; action_len];
    let unreachable = i64::MIN / 4;
    let mut previous = vec![
        NativeBranchAlignmentCell {
            score: unreachable,
            ways: 0,
        };
        width
    ];
    previous[0] = NativeBranchAlignmentCell { score: 0, ways: 1 };

    for native_idx in 1..=native_count {
        let mut current = vec![
            NativeBranchAlignmentCell {
                score: unreachable,
                ways: 0,
            };
            width
        ];
        for raw_matched in 0..=raw_count {
            let skip = previous[raw_matched];
            if skip.ways > 0 {
                current[raw_matched] = skip;
                actions[native_idx * width + raw_matched] = 1;
            }
            if raw_matched == 0 {
                continue;
            }
            let predecessor = previous[raw_matched - 1];
            if predecessor.ways == 0 {
                continue;
            }
            let raw_pc = raw_pcs[raw_matched - 1];
            let Some(branch_score) = native_branch_candidate_score(
                &native_sites[native_idx - 1],
                raw_pc,
                xlated_insns,
                ranges,
                lines,
                image,
            )?
            else {
                continue;
            };
            let (line_start, line_end) = line_ranges[native_idx - 1];
            let distance: i64 = raw_pc
                .abs_diff(line_start)
                .try_into()
                .map_err(|_| anyhow!("native branch alignment PC distance exceeds i64"))?;
            /* Kernel jited_line_info points at source-line transitions, and
             * the native Jcc can sit just outside the nominal raw-PC interval
             * at the end of the translated instruction. Treat line metadata
             * as a ranking signal rather than a false exact boundary. Exact
             * raw PCs dominate same-line matches, which dominate out-of-line
             * matches; the final full alignment must still be unique. */
            let match_score = if raw_pc == line_start {
                1_000_000
            } else if raw_pc >= line_start && raw_pc < line_end {
                100_000 - distance.min(99_999)
            } else {
                -distance
            };
            let score = predecessor
                .score
                .checked_add(match_score)
                .and_then(|score| score.checked_add(branch_score))
                .ok_or_else(|| anyhow!("native branch alignment score overflow"))?;
            let candidate = NativeBranchAlignmentCell {
                score,
                ways: predecessor.ways,
            };
            if candidate.score > current[raw_matched].score {
                current[raw_matched] = candidate;
                actions[native_idx * width + raw_matched] = 2;
            } else if candidate.score == current[raw_matched].score {
                current[raw_matched].ways = current[raw_matched]
                    .ways
                    .saturating_add(candidate.ways)
                    .min(2);
                actions[native_idx * width + raw_matched] = 3;
            }
        }
        previous = current;
    }

    let result = previous[raw_count];
    if result.ways == 0 {
        bail!(
            "no order-preserving JIT branch mapping covers all {} translated BPF conditional sites from {} native conditionals",
            raw_count,
            native_count
        );
    }
    if result.ways != 1 {
        bail!(
            "ambiguous JIT branch mapping for {} translated BPF conditional sites across {} native conditionals",
            raw_count,
            native_count
        );
    }

    let mut native_idx = native_count;
    let mut raw_matched = raw_count;
    let mut mapped = BTreeMap::new();
    while native_idx > 0 {
        match actions[native_idx * width + raw_matched] {
            1 => native_idx -= 1,
            2 => {
                let raw_pc = raw_pcs[raw_matched - 1];
                let mut site = native_sites[native_idx - 1];
                site.pc = raw_pc;
                mapped.insert(raw_pc, site);
                native_idx -= 1;
                raw_matched -= 1;
            }
            action => {
                bail!(
                    "invalid native branch alignment reconstruction action {action} at native index {native_idx} raw count {raw_matched}"
                );
            }
        }
    }
    if raw_matched != 0 || mapped.len() != raw_count {
        bail!("native branch alignment reconstruction did not cover every raw conditional");
    }
    Ok(mapped)
}

#[cfg(target_arch = "x86_64")]
fn native_branch_candidate_score(
    site: &NativeBranchSite,
    raw_pc: usize,
    xlated_insns: &[kernel_sys::bpf_insn],
    ranges: &[JitFuncRange],
    lines: &[kernel_sys::JitedLineInfo],
    image: &[u8],
) -> Result<Option<i64>> {
    let insn = xlated_insns
        .get(raw_pc)
        .ok_or_else(|| anyhow!("translated BPF branch pc {raw_pc} is outside bytecode"))?;
    if !is_conditional_branch_opcode(insn.code) || insn.off == 0 {
        bail!("translated BPF branch pc {raw_pc} is not a conditional site");
    }

    let fallthrough_bytes = func_addr_slice(image, ranges, site.fallthrough_addr)?;
    let fallthrough_is_jump = site.fallthrough_starts_unconditional_jump(fallthrough_bytes);
    let raw_fallthrough_is_jump = xlated_insns
        .get(raw_pc + 1)
        .is_some_and(|next| matches!(next.code, 0x05 | 0x06));
    let inverted_jcc = fallthrough_is_jump && !raw_fallthrough_is_jump;
    let expected_condition = bpf_x86_condition(insn.code)
        .ok_or_else(|| anyhow!("unsupported BPF conditional opcode 0x{:02x}", insn.code))?;
    let expected_condition = if inverted_jcc {
        expected_condition ^ 1
    } else {
        expected_condition
    };
    if site.condition != expected_condition {
        return Ok(None);
    }
    let bpf_forward = insn.off > 0;
    let native_forward = site.jump_target_addr > site.fallthrough_addr;
    if !inverted_jcc && bpf_forward != native_forward {
        return Ok(None);
    }

    let raw_fallthrough_pc = raw_pc
        .checked_add(1)
        .ok_or_else(|| anyhow!("translated BPF fallthrough pc overflow"))?;
    let raw_target_signed = (raw_fallthrough_pc as i128) + (insn.off as i128);
    if raw_target_signed < 0 || raw_target_signed > usize::MAX as i128 {
        bail!("translated BPF branch pc {raw_pc} has out-of-range target");
    }
    let raw_target_pc = raw_target_signed as usize;

    let (jump_expected, fallthrough_expected, fallthrough_successor) = if inverted_jcc {
        let Some(target) = x86_unconditional_jump_target(fallthrough_bytes, site.fallthrough_addr)?
        else {
            bail!(
                "native branch at 0x{:x} has inverted-Jcc shape without a decodable fallthrough jump",
                site.start_addr
            );
        };
        (raw_fallthrough_pc, raw_target_pc, target)
    } else {
        (raw_target_pc, raw_fallthrough_pc, site.fallthrough_addr)
    };

    let jump_score =
        native_successor_line_score(ranges, lines, site.jump_target_addr, jump_expected);
    let fallthrough_score =
        native_successor_line_score(ranges, lines, fallthrough_successor, fallthrough_expected);
    Ok(Some(jump_score + fallthrough_score))
}

#[cfg(target_arch = "x86_64")]
fn bpf_x86_condition(code: u8) -> Option<u8> {
    match code & 0xf0 {
        0x10 => Some(0x4), // JEQ -> E
        0x20 => Some(0x7), // JGT -> A
        0x30 => Some(0x3), // JGE -> AE
        0x40 => Some(0x5), // JSET -> NE
        0x50 => Some(0x5), // JNE -> NE
        0x60 => Some(0xf), // JSGT -> G
        0x70 => Some(0xd), // JSGE -> GE
        0xa0 => Some(0x2), // JLT -> B
        0xb0 => Some(0x6), // JLE -> BE
        0xc0 => Some(0xc), // JSLT -> L
        0xd0 => Some(0xe), // JSLE -> LE
        _ => None,
    }
}

#[cfg(target_arch = "x86_64")]
fn native_successor_line_score(
    ranges: &[JitFuncRange],
    lines: &[kernel_sys::JitedLineInfo],
    addr: u64,
    expected_pc: usize,
) -> i64 {
    let Some((line_start, line_end)) = jited_line_pc_range_for_ip(ranges, lines, addr) else {
        return 0;
    };
    if expected_pc == line_start {
        return 10_000;
    }
    if expected_pc >= line_start && expected_pc < line_end {
        return 1_000;
    }
    let distance = if expected_pc < line_start {
        line_start - expected_pc
    } else if line_end == usize::MAX {
        expected_pc - line_start
    } else {
        expected_pc - line_end.saturating_sub(1)
    };
    -(distance.min(999) as i64)
}

#[cfg(target_arch = "x86_64")]
fn x86_unconditional_jump_target(bytes: &[u8], addr: u64) -> Result<Option<u64>> {
    let (len, rel) = match bytes.first().copied() {
        Some(0xeb) => {
            require_x86_len(bytes, 2)?;
            (2u64, i8::from_ne_bytes([bytes[1]]) as i64)
        }
        Some(0xe9) => {
            require_x86_len(bytes, 5)?;
            (
                5u64,
                i32::from_ne_bytes([bytes[1], bytes[2], bytes[3], bytes[4]]) as i64,
            )
        }
        _ => return Ok(None),
    };
    let fallthrough = addr
        .checked_add(len)
        .ok_or_else(|| anyhow!("native unconditional jump fallthrough overflow"))?;
    let target = (fallthrough as i128) + (rel as i128);
    if target < 0 || target > u64::MAX as i128 {
        bail!("native unconditional jump target overflow");
    }
    Ok(Some(target as u64))
}

#[cfg(not(target_arch = "x86_64"))]
fn native_branch_sites_from_jit(
    _fd: std::os::fd::BorrowedFd<'_>,
    _ranges: &[JitFuncRange],
    _lines: Option<&[kernel_sys::JitedLineInfo]>,
    _xlated_insns: &[kernel_sys::bpf_insn],
    _conditional_pcs: &BTreeSet<usize>,
) -> Result<Vec<NativeBranchSite>> {
    bail!("target BPF program has no line info; native JIT branch decoding is only implemented on x86_64")
}

#[cfg(target_arch = "x86_64")]
fn func_addr_slice<'a>(image: &'a [u8], ranges: &[JitFuncRange], addr: u64) -> Result<&'a [u8]> {
    let mut offset = 0usize;
    for range in ranges {
        let len = (range.end_addr - range.start_addr) as usize;
        if range.contains(addr) {
            let rel = (addr - range.start_addr) as usize;
            return Ok(&image[offset + rel..offset + len]);
        }
        offset += len;
    }
    bail!("native branch fallthrough address 0x{addr:x} is outside JIT function ranges")
}

#[cfg(target_arch = "x86_64")]
fn scan_x86_conditional_branches(
    bytes: &[u8],
    start_addr: u64,
    end_addr: u64,
) -> Result<Vec<NativeBranchSite>> {
    let mut sites = Vec::new();
    let mut idx = 0usize;
    let mut previous = None;
    while idx < bytes.len() {
        let decoded = decode_x86_instruction_at(&bytes[idx..]).with_context(|| {
            let window_start = idx.saturating_sub(64);
            let window_end = idx.saturating_add(32).min(bytes.len());
            let window = bytes[window_start..window_end]
                .iter()
                .map(|byte| format!("{byte:02x}"))
                .collect::<Vec<_>>()
                .join(" ");
            format!(
                "decode x86 JIT instruction at +0x{idx:x}; bytes +0x{window_start:x}..+0x{window_end:x}: {window}"
            )
        })?;
        let insn_addr = start_addr
            .checked_add(idx as u64)
            .ok_or_else(|| anyhow!("native instruction address overflow"))?;
        let Some((insn_len, rel, condition)) = decoded.branch else {
            let insn_end = insn_addr
                .checked_add(decoded.len as u64)
                .ok_or_else(|| anyhow!("native instruction end overflow"))?;
            previous = Some((insn_addr, insn_end));
            idx += decoded.len;
            continue;
        };
        let branch_addr = insn_addr;
        let fallthrough_addr = branch_addr
            .checked_add(insn_len as u64)
            .ok_or_else(|| anyhow!("native branch fallthrough overflow"))?;
        let target_addr = (fallthrough_addr as i128)
            .checked_add(rel as i128)
            .ok_or_else(|| anyhow!("native branch target overflow"))?;
        if target_addr < 0 || target_addr > u64::MAX as i128 {
            continue;
        }
        let target_addr = target_addr as u64;
        if start_addr <= target_addr && target_addr < end_addr && fallthrough_addr <= end_addr {
            let pebs_start_addr = previous
                .filter(|(_, previous_end)| *previous_end == branch_addr)
                .map(|(previous_start, _)| previous_start)
                .unwrap_or(branch_addr);
            sites.push(NativeBranchSite {
                pebs_start_addr,
                start_addr: branch_addr,
                end_addr: fallthrough_addr,
                fallthrough_addr,
                jump_target_addr: target_addr,
                condition,
                pc: 0,
                jump_is_bpf_target: true,
            });
        }
        previous = Some((branch_addr, fallthrough_addr));
        idx += decoded.len;
    }
    Ok(sites)
}

#[cfg(target_arch = "x86_64")]
#[derive(Clone, Copy, Debug)]
struct DecodedX86Insn {
    len: usize,
    branch: Option<(usize, i64, u8)>,
}

#[cfg(target_arch = "x86_64")]
fn decode_x86_instruction_at(bytes: &[u8]) -> Result<DecodedX86Insn> {
    if bytes.is_empty() {
        bail!("empty instruction stream");
    }
    let mut idx = 0usize;
    let mut rex_w = false;
    let mut operand_16 = false;
    while idx < bytes.len() {
        let byte = bytes[idx];
        if byte == 0x66 {
            operand_16 = true;
            idx += 1;
        } else if matches!(
            byte,
            0xf0 | 0xf2 | 0xf3 | 0x2e | 0x36 | 0x3e | 0x26 | 0x64 | 0x65 | 0x67
        ) {
            idx += 1;
        } else if (0x40..=0x4f).contains(&byte) {
            rex_w = byte & 0x08 != 0;
            idx += 1;
        } else {
            break;
        }
    }
    if idx >= bytes.len() {
        bail!("instruction contains only prefixes");
    }

    let prefix_len = idx;
    let op = bytes[idx];
    idx += 1;
    if (0x70..=0x7f).contains(&op) {
        require_x86_len(bytes, idx + 1)?;
        let len = idx + 1;
        return Ok(DecodedX86Insn {
            len,
            branch: Some((len, i8::from_ne_bytes([bytes[idx]]) as i64, op & 0x0f)),
        });
    }
    if op == 0xc4 {
        require_x86_len(bytes, idx + 3)?;
        let opcode_map = bytes[idx] & 0x1f;
        idx += 2;
        let vex_opcode = bytes[idx];
        idx += 1;
        if opcode_map == 2 && vex_opcode == 0xf7 {
            let len = idx + parse_x86_modrm_len(bytes, idx)?;
            return Ok(DecodedX86Insn { len, branch: None });
        }
        bail!("unsupported x86 VEX3 opcode map {opcode_map} opcode 0x{vex_opcode:02x}");
    }
    if op == 0x0f {
        require_x86_len(bytes, idx + 1)?;
        let op2 = bytes[idx];
        idx += 1;
        if (0x80..=0x8f).contains(&op2) {
            require_x86_len(bytes, idx + 4)?;
            let rel =
                i32::from_ne_bytes([bytes[idx], bytes[idx + 1], bytes[idx + 2], bytes[idx + 3]])
                    as i64;
            let len = idx + 4;
            return Ok(DecodedX86Insn {
                len,
                branch: Some((len, rel, op2 & 0x0f)),
            });
        }
        let modrm = match op2 {
            0x1f | 0x40..=0x4f | 0x90..=0x9f | 0xaf | 0xb6 | 0xb7 | 0xbe | 0xbf => {
                Some(parse_x86_modrm_len(bytes, idx)?)
            }
            0x05 | 0x0b | 0x31 | 0xc8..=0xcf => Some(0),
            _ => None,
        };
        if let Some(extra) = modrm {
            let len = idx + extra;
            require_x86_len(bytes, len)?;
            return Ok(DecodedX86Insn { len, branch: None });
        }
        bail!("unsupported x86 two-byte opcode 0x0f 0x{op2:02x}");
    }

    let imm_op_size = if operand_16 { 2 } else { 4 };
    let mut len = idx;
    match op {
        0x50..=0x5f | 0x90 | 0x98 | 0x99 | 0xc3 | 0xc9 | 0xcc | 0xf4 | 0xf5 | 0xf8..=0xfd => {}
        0x6a | 0xeb | 0xcd => len += 1,
        0x68 | 0xe8 | 0xe9 => len += 4,
        0xb0..=0xb7 => len += 1,
        0xb8..=0xbf => {
            len += if rex_w {
                8
            } else if operand_16 {
                2
            } else {
                4
            }
        }
        0x04 | 0x0c | 0x14 | 0x1c | 0x24 | 0x2c | 0x34 | 0x3c | 0xa8 => len += 1,
        0x05 | 0x0d | 0x15 | 0x1d | 0x25 | 0x2d | 0x35 | 0x3d | 0xa9 => len += imm_op_size,
        0x00..=0x03
        | 0x08..=0x0b
        | 0x10..=0x13
        | 0x18..=0x1b
        | 0x20..=0x23
        | 0x28..=0x2b
        | 0x30..=0x33
        | 0x38..=0x3b
        | 0x63
        | 0x84..=0x8f
        | 0xd0..=0xd3
        | 0xf6
        | 0xf7
        | 0xfe
        | 0xff => {
            let modrm_len = parse_x86_modrm_len(bytes, len)?;
            let modrm = bytes[len];
            len += modrm_len;
            if op == 0xf6 && ((modrm >> 3) & 7) <= 1 {
                len += 1;
            } else if op == 0xf7 && ((modrm >> 3) & 7) <= 1 {
                len += imm_op_size;
            }
        }
        0x69 => {
            len += parse_x86_modrm_len(bytes, len)? + imm_op_size;
        }
        0x6b => {
            len += parse_x86_modrm_len(bytes, len)? + 1;
        }
        0x80 | 0x82 | 0x83 | 0xc0 | 0xc1 | 0xc6 => {
            len += parse_x86_modrm_len(bytes, len)? + 1;
        }
        0x81 | 0xc7 => {
            len += parse_x86_modrm_len(bytes, len)? + imm_op_size;
        }
        _ => bail!("unsupported x86 opcode 0x{op:02x} after {prefix_len} prefix bytes"),
    }
    require_x86_len(bytes, len)?;
    Ok(DecodedX86Insn { len, branch: None })
}

#[cfg(target_arch = "x86_64")]
fn require_x86_len(bytes: &[u8], len: usize) -> Result<()> {
    if len > bytes.len() {
        bail!(
            "truncated x86 instruction: need {} bytes, have {}",
            len,
            bytes.len()
        );
    }
    Ok(())
}

#[cfg(target_arch = "x86_64")]
fn parse_x86_modrm_len(bytes: &[u8], offset: usize) -> Result<usize> {
    require_x86_len(bytes, offset + 1)?;
    let modrm = bytes[offset];
    let mode = modrm >> 6;
    let rm = modrm & 7;
    let mut len = 1usize;
    if mode != 3 && rm == 4 {
        require_x86_len(bytes, offset + len + 1)?;
        let sib = bytes[offset + len];
        len += 1;
        let base = sib & 7;
        if mode == 0 && base == 5 {
            len += 4;
        }
    } else if mode == 0 && rm == 5 {
        len += 4;
    }
    if mode == 1 {
        len += 1;
    } else if mode == 2 {
        len += 4;
    }
    require_x86_len(bytes, offset + len)?;
    Ok(len)
}

#[cfg(target_arch = "x86_64")]
impl NativeBranchSite {
    fn fallthrough_starts_unconditional_jump(&self, bytes: &[u8]) -> bool {
        matches!(bytes.first(), Some(0xe9 | 0xeb))
    }
}

impl JitPcMap {
    fn from_prog(
        fd: std::os::fd::BorrowedFd<'_>,
        xlated_insns: &[kernel_sys::bpf_insn],
        conditional_pcs: &BTreeSet<usize>,
    ) -> Result<Self> {
        let ranges = kernel_sys::prog_jited_func_ranges(fd)?
            .into_iter()
            .map(|range| {
                let end_addr = range
                    .start_addr
                    .checked_add(range.byte_len as u64)
                    .ok_or_else(|| anyhow!("JIT function range address overflow"))?;
                Ok(JitFuncRange {
                    start_addr: range.start_addr,
                    end_addr,
                })
            })
            .collect::<Result<Vec<_>>>()?;
        let info = kernel_sys::obj_get_info_by_fd(fd)?;
        if info.nr_line_info == 0 || info.nr_jited_line_info == 0 {
            /* A JIT image can contain internal conditional branches even when
             * the translated BPF program has no conditional sites (for
             * example, the stats/prologue paths in Tetragon's tiny helper
             * programs).  There is nothing to attribute in that case.  Keep
             * the function ranges for IP ownership and avoid treating those
             * JIT-only branches as missing BPF-PC evidence. */
            if conditional_pcs.is_empty() {
                return Ok(Self {
                    ranges,
                    lines: Vec::new(),
                    native_branch_sites: Vec::new(),
                });
            }
            let native_branch_sites =
                native_branch_sites_from_jit(fd, &ranges, None, xlated_insns, conditional_pcs)?;
            return Ok(Self {
                ranges,
                lines: Vec::new(),
                native_branch_sites,
            });
        }
        let mut lines = kernel_sys::prog_jited_line_info(fd)?;
        if lines.is_empty() {
            bail!("target BPF program returned empty jited_line_info metadata");
        }
        lines.sort_by_key(|line| line.jited_addr);
        for line in &lines {
            if !ranges.iter().any(|range| range.contains(line.jited_addr)) {
                bail!(
                    "jited_line_info address 0x{:x} is outside target JIT function ranges",
                    line.jited_addr
                );
            }
        }
        if conditional_pcs.is_empty() {
            return Ok(Self {
                ranges,
                lines,
                native_branch_sites: Vec::new(),
            });
        }
        /* jited_line_info is source-line metadata, not an exact native-IP to
         * BPF-successor map. It is still precise enough at the native branch
         * instruction to discard JIT-internal guards and associate each
         * remaining machine branch with its raw BPF conditional. Edge
         * direction itself comes from the decoded machine successors. */
        let native_branch_sites =
            native_branch_sites_from_jit(fd, &ranges, Some(&lines), xlated_insns, conditional_pcs)?;
        Ok(Self {
            ranges,
            lines,
            native_branch_sites,
        })
    }

    fn contains_ip(&self, ip: u64) -> bool {
        self.ranges.iter().any(|range| range.contains(ip))
    }

    fn pc_for_ip(&self, ip: u64) -> Option<usize> {
        jited_line_pc_for_ip(&self.ranges, &self.lines, ip)
    }

    fn is_function_entry_line_ip(&self, ip: u64) -> bool {
        let Some(range) = self.ranges.iter().find(|range| range.contains(ip)) else {
            return false;
        };
        let start = self
            .lines
            .partition_point(|line| line.jited_addr < range.start_addr);
        let end = self
            .lines
            .partition_point(|line| line.jited_addr < range.end_addr);
        let Some(first) = self.lines.get(start).filter(|_| start < end) else {
            return false;
        };
        self.pc_for_ip(ip) == Some(first.insn_off as usize)
    }

    fn native_branch_for_ip(&self, ip: u64) -> Option<(usize, NativeBranchSite)> {
        self.native_branch_sites
            .iter()
            .enumerate()
            .find_map(|(idx, site)| {
                (site.start_addr <= ip && ip < site.end_addr).then_some((idx, *site))
            })
    }

    fn native_branch_for_precise_ip(&self, ip: u64) -> Option<(usize, NativeBranchSite)> {
        self.native_branch_for_ip(ip).or_else(|| {
            self.native_branch_sites
                .iter()
                .enumerate()
                .find_map(|(idx, site)| (site.pebs_start_addr == ip).then_some((idx, *site)))
        })
    }
}

fn jited_line_pc_for_ip(
    ranges: &[JitFuncRange],
    lines: &[kernel_sys::JitedLineInfo],
    ip: u64,
) -> Option<usize> {
    jited_line_pc_range_for_ip(ranges, lines, ip).map(|(start, _)| start)
}

fn jited_line_pc_range_for_ip(
    ranges: &[JitFuncRange],
    lines: &[kernel_sys::JitedLineInfo],
    ip: u64,
) -> Option<(usize, usize)> {
    if lines.is_empty() {
        return None;
    }
    let range = ranges.iter().find(|range| range.contains(ip))?;
    let start = lines.partition_point(|line| line.jited_addr < range.start_addr);
    let end = lines.partition_point(|line| line.jited_addr < range.end_addr);
    let idx = lines[start..end].partition_point(|line| line.jited_addr <= ip);
    if idx == 0 {
        return None;
    }
    let line_idx = start + idx - 1;
    let line_start = lines[line_idx].insn_off as usize;
    let line_end = lines[line_idx + 1..end]
        .iter()
        .find_map(|line| {
            let pc = line.insn_off as usize;
            (pc > line_start).then_some(pc)
        })
        .unwrap_or(usize::MAX);
    Some((line_start, line_end))
}

impl JitFuncRange {
    fn contains(&self, ip: u64) -> bool {
        self.start_addr <= ip && ip < self.end_addr
    }
}

impl JitIpResolver {
    fn from_profilers(
        profilers: &[TargetProfiler],
        tail_target_keys: &BTreeMap<u32, u32>,
    ) -> Result<Self> {
        let mut ranges = Vec::new();
        for (target_idx, profiler) in profilers.iter().enumerate() {
            for range in &profiler.pc_map.ranges {
                ranges.push(JitIpRange {
                    start_addr: range.start_addr,
                    end_addr: range.end_addr,
                    prog_id: profiler.target.prog_id,
                    target_idx,
                });
            }
        }
        ranges.sort_by_key(|range| (range.start_addr, range.end_addr));
        for pair in ranges.windows(2) {
            if pair[0].end_addr > pair[1].start_addr {
                bail!(
                    "overlapping BPF JIT ranges for program ids {} and {}: 0x{:x}-0x{:x} overlaps 0x{:x}-0x{:x}",
                    pair[0].prog_id,
                    pair[1].prog_id,
                    pair[0].start_addr,
                    pair[0].end_addr,
                    pair[1].start_addr,
                    pair[1].end_addr
                );
            }
        }
        Ok(Self {
            ranges,
            tail_target_keys: tail_target_keys.clone(),
        })
    }

    fn range_for_ip(&self, ip: u64) -> Option<JitIpRange> {
        let idx = self.ranges.partition_point(|range| range.start_addr <= ip);
        if idx == 0 {
            return None;
        }
        let range = self.ranges[idx - 1];
        range.contains(ip).then_some(range)
    }

    fn pc_for_ip(&self, profilers: &[TargetProfiler], ip: u64) -> Option<ResolvedIp> {
        let range = self.range_for_ip(ip)?;
        let pc = profilers[range.target_idx].pc_map.pc_for_ip(ip)?;
        Some(ResolvedIp {
            prog_id: range.prog_id,
            pc,
        })
    }

    fn branch_source_for_ip(
        &self,
        profilers: &[TargetProfiler],
        ip: u64,
    ) -> Option<ResolvedBranchSource> {
        let range = self.range_for_ip(ip)?;
        let profiler = &profilers[range.target_idx];
        if let Some((native_branch_idx, site)) = profiler.pc_map.native_branch_for_ip(ip) {
            return Some(ResolvedBranchSource {
                prog_id: range.prog_id,
                target_idx: range.target_idx,
                pc: site.pc,
                native_branch_idx: Some(native_branch_idx),
            });
        }
        let pc = profiler.pc_map.pc_for_ip(ip)?;
        Some(ResolvedBranchSource {
            prog_id: range.prog_id,
            target_idx: range.target_idx,
            pc,
            native_branch_idx: None,
        })
    }

    fn precise_branch_source_for_ip(
        &self,
        profilers: &[TargetProfiler],
        ip: u64,
    ) -> Option<ResolvedBranchSource> {
        let range = self.range_for_ip(ip)?;
        let profiler = &profilers[range.target_idx];
        if let Some((native_branch_idx, site)) = profiler.pc_map.native_branch_for_precise_ip(ip) {
            return Some(ResolvedBranchSource {
                prog_id: range.prog_id,
                target_idx: range.target_idx,
                pc: site.pc,
                native_branch_idx: Some(native_branch_idx),
            });
        }
        let pc = profiler.pc_map.pc_for_ip(ip)?;
        Some(ResolvedBranchSource {
            prog_id: range.prog_id,
            target_idx: range.target_idx,
            pc,
            native_branch_idx: None,
        })
    }

    fn resolve_branch_direction(
        &self,
        profilers: &[TargetProfiler],
        source: ResolvedBranchSource,
        to_ip: u64,
    ) -> Result<ResolvedBranch> {
        let profiler = &profilers[source.target_idx];
        if let Some(native_branch_idx) = source.native_branch_idx {
            let site = profiler
                .pc_map
                .native_branch_sites
                .get(native_branch_idx)
                .ok_or_else(|| anyhow!("native branch index disappeared while processing LBR"))?;
            if !profiler.pc_map.contains_ip(to_ip) {
                bail!(
                    "conditional LBR target 0x{to_ip:x} for source pc {} is outside target JIT map",
                    source.pc
                );
            }
            let native_jump_taken = if to_ip == site.jump_target_addr {
                true
            } else if to_ip == site.fallthrough_addr {
                false
            } else {
                bail!(
                    "conditional LBR target 0x{to_ip:x} for source pc {} matches neither native jump target 0x{:x} nor fallthrough 0x{:x}",
                    source.pc,
                    site.jump_target_addr,
                    site.fallthrough_addr
                );
            };
            let taken = if site.jump_is_bpf_target {
                native_jump_taken
            } else {
                !native_jump_taken
            };
            return Ok(ResolvedBranch {
                prog_id: source.prog_id,
                target_idx: source.target_idx,
                pc: source.pc,
                taken,
            });
        }

        let Some(to) = self.pc_for_ip(profilers, to_ip) else {
            bail!(
                "conditional LBR target 0x{to_ip:x} for source pc {} is outside target JIT map",
                source.pc
            );
        };
        if to.prog_id != source.prog_id {
            bail!(
                "conditional LBR target 0x{to_ip:x} for program id {} pc {} maps to program id {}",
                source.prog_id,
                source.pc,
                to.prog_id
            );
        }
        Ok(ResolvedBranch {
            prog_id: source.prog_id,
            target_idx: source.target_idx,
            pc: source.pc,
            taken: to.pc != source.pc + 1,
        })
    }
}

impl JitIpRange {
    fn contains(&self, ip: u64) -> bool {
        self.start_addr <= ip && ip < self.end_addr
    }
}

impl LbrPerfEvents {
    fn open(
        sample_period: u64,
        cgroup: Option<&Path>,
        precise_branch_direction: bool,
        precise_pmu_source: PrecisePmuSource,
    ) -> Result<Self> {
        let cgroup_file = match cgroup {
            Some(path) => {
                Some(File::open(path).with_context(|| format!("open cgroup {}", path.display()))?)
            }
            None => None,
        };
        let pid = cgroup_file
            .as_ref()
            .map(|file| file.as_raw_fd())
            .unwrap_or(-1);
        let flags = if cgroup_file.is_some() {
            kernel_sys::PERF_FLAG_PID_CGROUP
        } else {
            0
        };
        let rings = if precise_branch_direction {
            open_precise_branch_rings(sample_period, pid, flags, precise_pmu_source)?
        } else {
            open_lbr_rings(sample_period, pid, flags)?
        };
        Ok(Self {
            rings,
            _cgroup: cgroup_file,
        })
    }

    fn reset_and_enable(&self) -> Result<()> {
        for ring in &self.rings {
            kernel_sys::perf_event_ioctl(ring.fd.as_fd(), kernel_sys::PerfEventCommand::Reset)
                .context("reset LBR perf event")?;
        }
        for ring in &self.rings {
            kernel_sys::perf_event_ioctl(ring.fd.as_fd(), kernel_sys::PerfEventCommand::Enable)
                .context("enable LBR perf event")?;
        }
        Ok(())
    }

    fn disable(&self) -> Result<()> {
        for ring in &self.rings {
            kernel_sys::perf_event_ioctl(ring.fd.as_fd(), kernel_sys::PerfEventCommand::Disable)
                .context("disable LBR perf event")?;
        }
        Ok(())
    }

    fn drain(
        &mut self,
        resolver: &JitIpResolver,
        profilers: &[TargetProfiler],
        samples: &mut BTreeMap<u32, TargetSamples>,
    ) -> Result<()> {
        for ring in &mut self.rings {
            ring.drain(resolver, profilers, samples)?;
        }
        Ok(())
    }
}

fn open_lbr_rings(
    sample_period: u64,
    pid: libc::pid_t,
    flags: libc::c_ulong,
) -> Result<Vec<PerfSampleRing>> {
    let cpus = online_cpus()?;
    let mut rings = Vec::with_capacity(cpus.len());
    for cpu in cpus {
        let mut attr = kernel_sys::perf_event_attr {
            type_: kernel_sys::PERF_TYPE_HARDWARE,
            size: std::mem::size_of::<kernel_sys::perf_event_attr>() as u32,
            config: kernel_sys::PERF_COUNT_HW_BRANCH_INSTRUCTIONS as u64,
            sample_type: (kernel_sys::PERF_SAMPLE_TID
                | kernel_sys::PERF_SAMPLE_BRANCH_STACK) as u64,
            branch_sample_type: (kernel_sys::PERF_SAMPLE_BRANCH_KERNEL
                | kernel_sys::PERF_SAMPLE_BRANCH_ANY
                | kernel_sys::PERF_SAMPLE_BRANCH_TYPE_SAVE) as u64,
            ..Default::default()
        };
        attr.set_disabled(1);
        attr.set_exclude_user(1);
        attr.set_exclude_hv(1);
        attr.__bindgen_anon_1.sample_period = sample_period;
        let fd = kernel_sys::perf_event_open(&mut attr, pid, cpu, -1, flags)
            .with_context(|| format!("open kernel LBR perf event on CPU {cpu}"))?;
        rings.push(
            PerfSampleRing::new(fd, PerfSampleKind::Lbr { sample_tid: true })
                .with_context(|| format!("mmap kernel LBR perf event on CPU {cpu}"))?,
        );
    }
    Ok(rings)
}

fn open_precise_branch_rings(
    sample_period: u64,
    pid: libc::pid_t,
    flags: libc::c_ulong,
    source: PrecisePmuSource,
) -> Result<Vec<PerfSampleRing>> {
    require_arrow_lake_core_pmu()?;
    let (pmu_name, cpus) = match source {
        PrecisePmuSource::CpuCore => {
            let cpus_raw = fs::read_to_string("/sys/bus/event_source/devices/cpu_core/cpus")
                .context("read cpu_core PMU CPU list")?;
            (
                "cpu_core",
                parse_cpu_list(&cpus_raw, "cpu_core PMU CPU list")?,
            )
        }
        PrecisePmuSource::Cpu => ("cpu", online_cpus()?),
    };
    let pmu_type = read_u32_file(&format!("/sys/bus/event_source/devices/{pmu_name}/type"))?;
    let events = [
        (0xc4, 0x101, true, false, "BR_INST_RETIRED.COND_TAKEN"),
        (0xc4, 0x010, false, false, "BR_INST_RETIRED.COND_NTAKEN"),
        (0xc5, 0x101, true, true, "BR_MISP_RETIRED.COND_TAKEN"),
        (0xc5, 0x010, false, true, "BR_MISP_RETIRED.COND_NTAKEN"),
    ];
    let capacity = cpus
        .len()
        .checked_mul(events.len())
        .ok_or_else(|| anyhow!("precise branch PMU ring capacity overflow"))?;
    let mut rings = Vec::with_capacity(capacity);
    for cpu in cpus {
        for (event, umask, native_taken, mispredicted, name) in events {
            let kind = PerfSampleKind::PreciseBranch {
                native_taken,
                mispredicted,
            };
            let mut attr = kernel_sys::perf_event_attr {
                type_: pmu_type,
                size: std::mem::size_of::<kernel_sys::perf_event_attr>() as u32,
                config: intel_hybrid_raw_config(event, umask),
                sample_type: kernel_sys::PERF_SAMPLE_IP as u64,
                ..Default::default()
            };
            attr.set_disabled(1);
            attr.set_exclude_user(1);
            attr.set_exclude_hv(1);
            attr.set_precise_ip(2);
            attr.__bindgen_anon_1.sample_period = sample_period;
            let fd =
                kernel_sys::perf_event_open(&mut attr, pid, cpu, -1, flags).with_context(|| {
                    format!("open precise {name} {pmu_name} perf event on CPU {cpu}")
                })?;
            rings.push(
                PerfSampleRing::new(fd, kind)
                    .with_context(|| format!("mmap precise {name} perf event on CPU {cpu}"))?,
            );
        }
    }
    Ok(rings)
}

fn intel_hybrid_raw_config(event: u16, umask: u16) -> u64 {
    u64::from(event & 0xff)
        | (u64::from(umask & 0xff) << 8)
        | (u64::from((umask >> 8) & 0xff) << 40)
}

fn require_arrow_lake_core_pmu() -> Result<()> {
    let cpuinfo = fs::read_to_string("/proc/cpuinfo").context("read /proc/cpuinfo")?;
    let first = cpuinfo.split("\n\n").next().unwrap_or_default();
    let field = |name: &str| {
        first.lines().find_map(|line| {
            let (key, value) = line.split_once(':')?;
            (key.trim() == name).then(|| value.trim())
        })
    };
    let vendor = field("vendor_id").ok_or_else(|| anyhow!("cpuinfo has no vendor_id"))?;
    let family = field("cpu family")
        .ok_or_else(|| anyhow!("cpuinfo has no cpu family"))?
        .parse::<u32>()
        .context("parse cpu family")?;
    let model = field("model")
        .ok_or_else(|| anyhow!("cpuinfo has no model"))?
        .parse::<u32>()
        .context("parse CPU model")?;
    if vendor != "GenuineIntel" || family != 6 || !matches!(model, 0xc5 | 0xc6) {
        bail!(
            "precise branch-direction PMU encoding requires Intel Arrow Lake family 6 model 0xc5/0xc6; found vendor={vendor} family={family} model=0x{model:x}"
        );
    }
    Ok(())
}

fn read_u32_file(path: &str) -> Result<u32> {
    fs::read_to_string(path)
        .with_context(|| format!("read {path}"))?
        .trim()
        .parse::<u32>()
        .with_context(|| format!("parse u32 from {path}"))
}

impl PerfSampleRing {
    fn new(fd: OwnedFd, kind: PerfSampleKind) -> Result<Self> {
        let page_size = page_size()?;
        let data_pages = PERF_RING_DATA_PAGES
            .checked_next_power_of_two()
            .ok_or_else(|| anyhow!("perf ring data page count overflow"))?;
        let mapping_pages = data_pages
            .checked_add(1)
            .ok_or_else(|| anyhow!("perf ring mapping page count overflow"))?;
        let mapping_len = page_size
            .checked_mul(mapping_pages)
            .ok_or_else(|| anyhow!("perf ring mapping length overflow"))?;
        let ptr = unsafe {
            libc::mmap(
                std::ptr::null_mut(),
                mapping_len,
                libc::PROT_READ | libc::PROT_WRITE,
                libc::MAP_SHARED,
                fd.as_raw_fd(),
                0,
            )
        };
        if ptr == libc::MAP_FAILED {
            return Err(anyhow!(
                "mmap perf sample ring: {}",
                std::io::Error::last_os_error()
            ));
        }
        let mapping = NonNull::new(ptr as *mut u8)
            .ok_or_else(|| anyhow!("mmap perf sample ring returned NULL"))?;
        let meta = unsafe { &*(mapping.as_ptr() as *const PerfEventMmapPage) };
        let data_offset: usize = meta
            .data_offset
            .try_into()
            .map_err(|_| anyhow!("perf ring data_offset does not fit usize"))?;
        let data_size: usize = meta
            .data_size
            .try_into()
            .map_err(|_| anyhow!("perf ring data_size does not fit usize"))?;
        if data_offset == 0 || data_size == 0 {
            bail!("perf ring metadata reported empty data buffer");
        }
        if !data_size.is_power_of_two() {
            bail!("perf ring data_size {data_size} is not a power of two");
        }
        let end = data_offset
            .checked_add(data_size)
            .ok_or_else(|| anyhow!("perf ring data buffer range overflow"))?;
        if end > mapping_len {
            bail!(
                "perf ring data buffer 0x{data_offset:x}+0x{data_size:x} exceeds mmap length 0x{mapping_len:x}"
            );
        }
        Ok(Self {
            fd,
            kind,
            mapping,
            mapping_len,
            data_offset,
            data_size,
        })
    }

    fn drain(
        &mut self,
        resolver: &JitIpResolver,
        profilers: &[TargetProfiler],
        samples: &mut BTreeMap<u32, TargetSamples>,
    ) -> Result<()> {
        let meta = self.meta_mut();
        let head = unsafe { std::ptr::read_volatile(&meta.data_head) };
        fence(Ordering::Acquire);
        let mut tail = unsafe { std::ptr::read_volatile(&meta.data_tail) };
        if head < tail {
            bail!("perf ring data_head moved behind data_tail: head={head} tail={tail}");
        }
        let available = head - tail;
        if available > self.data_size as u64 {
            bail!(
                "perf ring overrun: {} unread bytes exceed {} byte data buffer",
                available,
                self.data_size
            );
        }

        while tail < head {
            let header_bytes = self.read_ring_bytes(tail, PERF_EVENT_HEADER_SIZE)?;
            let header = parse_perf_event_header(&header_bytes)?;
            let record_size = usize::from(header.size);
            if record_size < PERF_EVENT_HEADER_SIZE {
                bail!("perf record size {} is smaller than header", record_size);
            }
            if record_size > self.data_size {
                bail!(
                    "perf record size {} exceeds ring data buffer {}",
                    record_size,
                    self.data_size
                );
            }
            let record = self.read_ring_bytes(tail, record_size)?;
            process_perf_record_for_kind(&record, self.kind, resolver, profilers, samples)?;
            tail = tail
                .checked_add(record_size as u64)
                .ok_or_else(|| anyhow!("perf ring tail overflow"))?;
        }

        fence(Ordering::Release);
        let meta = self.meta_mut();
        unsafe { std::ptr::write_volatile(&mut meta.data_tail, tail) };
        Ok(())
    }

    fn meta_mut(&mut self) -> &mut PerfEventMmapPage {
        unsafe { &mut *(self.mapping.as_ptr() as *mut PerfEventMmapPage) }
    }

    fn read_ring_bytes(&self, offset: u64, len: usize) -> Result<Vec<u8>> {
        if len > self.data_size {
            bail!(
                "perf ring read length {} exceeds data buffer {}",
                len,
                self.data_size
            );
        }
        let data_base = unsafe { self.mapping.as_ptr().add(self.data_offset) };
        let start = (offset & (self.data_size as u64 - 1)) as usize;
        if start + len <= self.data_size {
            let bytes = unsafe { std::slice::from_raw_parts(data_base.add(start), len) };
            return Ok(bytes.to_vec());
        }

        let first_len = self.data_size - start;
        let second_len = len - first_len;
        let mut out = Vec::with_capacity(len);
        let first = unsafe { std::slice::from_raw_parts(data_base.add(start), first_len) };
        let second = unsafe { std::slice::from_raw_parts(data_base, second_len) };
        out.extend_from_slice(first);
        out.extend_from_slice(second);
        Ok(out)
    }
}

impl Drop for PerfSampleRing {
    fn drop(&mut self) {
        let ret =
            unsafe { libc::munmap(self.mapping.as_ptr() as *mut libc::c_void, self.mapping_len) };
        if ret < 0 {
            eprintln!(
                "munmap perf sample ring: {}",
                std::io::Error::last_os_error()
            );
        }
    }
}

fn online_cpus() -> Result<Vec<i32>> {
    let raw = fs::read_to_string("/sys/devices/system/cpu/online")
        .context("read /sys/devices/system/cpu/online")?;
    parse_cpu_list(&raw, "online CPU list")
}

fn parse_cpu_list(raw: &str, label: &str) -> Result<Vec<i32>> {
    let mut cpus = Vec::new();
    for part in raw.trim().split(',') {
        if part.is_empty() {
            bail!("{label} contains an empty CPU entry");
        }
        if let Some((start, end)) = part.split_once('-') {
            let start = start
                .parse::<i32>()
                .with_context(|| format!("parse {label} range start: {part}"))?;
            let end = end
                .parse::<i32>()
                .with_context(|| format!("parse {label} range end: {part}"))?;
            if start > end {
                bail!("invalid {label} range: {part}");
            }
            cpus.extend(start..=end);
        } else {
            cpus.push(
                part.parse::<i32>()
                    .with_context(|| format!("parse {label} CPU id: {part}"))?,
            );
        }
    }
    if cpus.is_empty() {
        bail!("{label} is empty");
    }
    Ok(cpus)
}

fn read_snapshots(profilers: &[TargetProfiler]) -> Result<BTreeMap<u32, ProgStats>> {
    let mut snapshots = BTreeMap::new();
    for profiler in profilers {
        snapshots.insert(profiler.target.prog_id, read_snapshot(profiler)?);
    }
    Ok(snapshots)
}

fn read_snapshot(profiler: &TargetProfiler) -> Result<ProgStats> {
    let info = kernel_sys::obj_get_info_by_fd(profiler.target.fd.as_fd())
        .with_context(|| format!("read stats for BPF program id {}", profiler.target.prog_id))?;
    Ok(ProgStats {
        run_cnt: info.run_cnt,
        run_time_ns: info.run_time_ns,
    })
}

fn collect_lbr_samples(
    duration: Duration,
    cli: &Cli,
    lbr_events: &mut LbrPerfEvents,
    profilers: &mut Vec<TargetProfiler>,
    before: &mut BTreeMap<u32, ProgStats>,
    samples: &mut BTreeMap<u32, TargetSamples>,
    tail_target_keys: &BTreeMap<u32, u32>,
) -> Result<()> {
    let start = Instant::now();
    loop {
        if cli.discover_shim_state_dir.is_some() {
            discover_new_shim_state_targets(cli, profilers, before)?;
        }
        let resolver = JitIpResolver::from_profilers(profilers, tail_target_keys)?;
        lbr_events.drain(&resolver, profilers, samples)?;
        let elapsed = start.elapsed();
        if elapsed >= duration {
            break;
        }
        let remaining = duration - elapsed;
        thread::sleep(remaining.min(POLL_SLICE));
    }
    Ok(())
}

#[cfg(test)]
fn process_perf_record(
    record: &[u8],
    resolver: &JitIpResolver,
    profilers: &[TargetProfiler],
    samples: &mut BTreeMap<u32, TargetSamples>,
) -> Result<()> {
    process_perf_record_for_kind(
        record,
        PerfSampleKind::Lbr { sample_tid: false },
        resolver,
        profilers,
        samples,
    )
}

fn process_perf_record_for_kind(
    record: &[u8],
    kind: PerfSampleKind,
    resolver: &JitIpResolver,
    profilers: &[TargetProfiler],
    samples: &mut BTreeMap<u32, TargetSamples>,
) -> Result<()> {
    if record.len() < PERF_EVENT_HEADER_SIZE {
        bail!("truncated perf record: {} bytes", record.len());
    }
    let header = parse_perf_event_header(&record[..PERF_EVENT_HEADER_SIZE])?;
    if usize::from(header.size) != record.len() {
        bail!(
            "perf record header size {} does not match buffer length {}",
            header.size,
            record.len()
        );
    }
    match header.type_ {
        PERF_RECORD_SAMPLE => match kind {
            PerfSampleKind::Lbr { sample_tid } => process_perf_sample(
                &record[PERF_EVENT_HEADER_SIZE..],
                sample_tid,
                resolver,
                profilers,
                samples,
            ),
            PerfSampleKind::PreciseBranch {
                native_taken,
                mispredicted,
            } => process_precise_branch_sample(
                &header,
                &record[PERF_EVENT_HEADER_SIZE..],
                native_taken,
                mispredicted,
                resolver,
                profilers,
                samples,
            ),
        },
        PERF_RECORD_LOST => bail!("perf ring reported lost PMU branch-stack records"),
        PERF_RECORD_THROTTLE | PERF_RECORD_UNTHROTTLE => {
            bail!("perf branch-stack sampler was throttled by the kernel; raise PERF_SAMPLE_PERIOD")
        }
        other => bail!("unexpected perf record type {other} in branch profile stream"),
    }
}

fn process_precise_branch_sample(
    header: &PerfEventHeader,
    sample: &[u8],
    native_taken: bool,
    mispredicted: bool,
    resolver: &JitIpResolver,
    profilers: &[TargetProfiler],
    samples: &mut BTreeMap<u32, TargetSamples>,
) -> Result<()> {
    if header.misc & PERF_RECORD_MISC_EXACT_IP == 0 {
        bail!("precise branch PMU sample is missing PERF_RECORD_MISC_EXACT_IP");
    }
    if sample.len() != std::mem::size_of::<u64>() {
        bail!(
            "precise branch PMU sample has {} bytes, expected {}",
            sample.len(),
            std::mem::size_of::<u64>()
        );
    }
    let ip = read_u64(sample, 0, "sample.ip")?;
    let Some(range) = resolver.range_for_ip(ip) else {
        return Ok(());
    };
    let in_jit = &mut samples.entry(range.prog_id).or_default().precise_in_jit;
    *in_jit = in_jit
        .checked_add(1)
        .ok_or_else(|| anyhow!("precise in-JIT sample counter overflow"))?;
    let Some(source) = resolver.precise_branch_source_for_ip(profilers, ip) else {
        return Ok(());
    };
    let profiler = &profilers[source.target_idx];
    if !profiler.conditional_pcs.contains(&source.pc) {
        let count = &mut samples
            .entry(source.prog_id)
            .or_default()
            .precise_nonconditional_pc;
        *count = count
            .checked_add(1)
            .ok_or_else(|| anyhow!("precise non-conditional-PC sample counter overflow"))?;
        return Ok(());
    }
    let Some(native_branch_idx) = source.native_branch_idx else {
        /* A single BPF instruction can cover JIT-internal conditional
         * branches in its line interval.  They are real PMU samples but not
         * raw BPF branch sites, so they must not be attributed to source.pc. */
        let count = &mut samples
            .entry(source.prog_id)
            .or_default()
            .precise_no_native_site;
        *count = count
            .checked_add(1)
            .ok_or_else(|| anyhow!("precise no-native-site sample counter overflow"))?;
        return Ok(());
    };
    let site = profiler
        .pc_map
        .native_branch_sites
        .get(native_branch_idx)
        .ok_or_else(|| {
            anyhow!("native branch index disappeared while processing precise PMU sample")
        })?;
    let taken = if site.jump_is_bpf_target {
        native_taken
    } else {
        !native_taken
    };
    let Some(profile_pc) = profiler.profile_pc_for_xlated_pc(source.pc) else {
        let count = &mut samples
            .entry(source.prog_id)
            .or_default()
            .precise_profile_pc_miss;
        *count = count
            .checked_add(1)
            .ok_or_else(|| anyhow!("precise profile-PC-miss sample counter overflow"))?;
        return Ok(());
    };
    let target_samples = samples.entry(source.prog_id).or_default();
    let counter = target_samples.sites.entry(profile_pc).or_default();
    if mispredicted {
        counter.branch_misses = counter
            .branch_misses
            .checked_add(1)
            .ok_or_else(|| anyhow!("branch miss sample counter overflow"))?;
    } else {
        counter.branch_count = counter
            .branch_count
            .checked_add(1)
            .ok_or_else(|| anyhow!("branch sample counter overflow"))?;
        if taken {
            counter.taken = counter
                .taken
                .checked_add(1)
                .ok_or_else(|| anyhow!("taken branch sample counter overflow"))?;
        } else {
            counter.not_taken = counter
                .not_taken
                .checked_add(1)
                .ok_or_else(|| anyhow!("not-taken branch sample counter overflow"))?;
        }
    }
    target_samples.sample_records = target_samples
        .sample_records
        .checked_add(1)
        .ok_or_else(|| anyhow!("PMU sample record counter overflow"))?;
    Ok(())
}

fn process_perf_sample(
    sample: &[u8],
    sample_tid: bool,
    resolver: &JitIpResolver,
    profilers: &[TargetProfiler],
    samples: &mut BTreeMap<u32, TargetSamples>,
) -> Result<()> {
    let (pid, tid, branch_stack_offset) = if sample_tid {
        (
            read_u32(sample, 0, "sample.pid")?,
            read_u32(sample, 4, "sample.tid")?,
            8usize,
        )
    } else {
        (0, 0, 0usize)
    };
    let entry_count = read_u64(
        sample,
        branch_stack_offset,
        "sample.branch_stack.nr",
    )?;
    let entry_count: usize = entry_count
        .try_into()
        .map_err(|_| anyhow!("sample.branch_stack.nr does not fit usize"))?;
    let entries_bytes = entry_count
        .checked_mul(PERF_BRANCH_ENTRY_SIZE)
        .ok_or_else(|| anyhow!("sample branch stack byte length overflow"))?;
    let expected_bytes = branch_stack_offset
        .checked_add(8)
        .and_then(|size| size.checked_add(entries_bytes))
        .ok_or_else(|| anyhow!("perf branch-stack sample byte length overflow"))?;
    if sample.len() != expected_bytes {
        bail!(
            "perf branch-stack sample has {} bytes, expected {} for {} entries",
            sample.len(),
            expected_bytes,
            entry_count
        );
    }

    let mut touched_progs = Vec::new();
    for idx in 0..entry_count {
        let base = branch_stack_offset + 8 + idx * PERF_BRANCH_ENTRY_SIZE;
        let from_ip = read_u64(sample, base, "branch.from")?;
        let to_ip = read_u64(sample, base + 8, "branch.to")?;
        let flags = read_u64(sample, base + 16, "branch.flags")?;
        let Some(source_range) = resolver.range_for_ip(from_ip) else {
            continue;
        };
        let profiler = &profilers[source_range.target_idx];
        let source = resolver.branch_source_for_ip(profilers, from_ip);
        let keyed_target = resolver.range_for_ip(to_ip).and_then(|target_range| {
            if !resolver
                .tail_target_keys
                .contains_key(&target_range.prog_id)
            {
                return None;
            }
            let target_profiler = &profilers[target_range.target_idx];
            let is_tail_entry = if target_profiler.pc_map.lines.is_empty() {
                /* A cross-program BPF-to-BPF edge can only be a tail call.
                 * This remains exact without line info.  A same-program edge
                 * could instead be a local subprogram call and stays
                 * unclassified. */
                target_range.prog_id != source_range.prog_id
            } else {
                target_profiler.pc_map.is_function_entry_line_ip(to_ip)
            };
            is_tail_entry.then_some(target_range.prog_id)
        });
        let tail_call_pc = if branch_entry_type(flags) != PERF_BR_COND {
            keyed_target
        } else {
            None
        }
        .map(|_| profiler.tail_call_pc_for_native_ip(from_ip))
        .transpose()?
        .flatten();
        if let Some(tail_call_pc) = tail_call_pc {
            let Some(profile_pc) = profiler.profile_pc_for_xlated_pc(tail_call_pc) else {
                continue;
            };
            if profiler.profile_tail_call_pcs.contains(&profile_pc) {
                let Some(target_prog_id) = keyed_target else {
                    continue;
                };
                let key = resolver.tail_target_keys.get(&target_prog_id).ok_or_else(|| {
                    anyhow!(
                        "tail-call edge from program id {} pc {} reached untracked target program id {}",
                        source_range.prog_id,
                        profile_pc,
                        target_prog_id
                    )
                })?;
                let target_samples = samples.entry(source_range.prog_id).or_default();
                let count = target_samples
                    .tail_call_sites
                    .entry(profile_pc)
                    .or_default()
                    .entry(*key)
                    .or_default();
                *count = count.checked_add(1).ok_or_else(|| {
                    anyhow!(
                        "tail-call sample counter overflow for program id {} pc {} key {}",
                        source_range.prog_id,
                        profile_pc,
                        key
                    )
                })?;
                if sample_tid {
                    let pid_count = target_samples
                        .tail_call_pid_key_counts
                        .entry(profile_pc)
                        .or_default()
                        .entry(pid)
                        .or_default()
                        .entry(*key)
                        .or_default();
                    *pid_count = pid_count.checked_add(1).ok_or_else(|| {
                        anyhow!(
                            "tail-call PID sample counter overflow for program id {} pc {} pid {} key {}",
                            source_range.prog_id,
                            profile_pc,
                            pid,
                            key
                        )
                    })?;
                    let tid_count = target_samples
                        .tail_call_tid_key_counts
                        .entry(profile_pc)
                        .or_default()
                        .entry(tid)
                        .or_default()
                        .entry(*key)
                        .or_default();
                    *tid_count = tid_count.checked_add(1).ok_or_else(|| {
                        anyhow!(
                            "tail-call TID sample counter overflow for program id {} pc {} tid {} key {}",
                            source_range.prog_id,
                            profile_pc,
                            tid,
                            key
                        )
                    })?;
                }
                if !touched_progs.contains(&source_range.prog_id) {
                    touched_progs.push(source_range.prog_id);
                }
                continue;
            }
        }
        if !branch_entry_is_conditional(flags) {
            continue;
        }
        let Some(source) = source else {
            continue;
        };
        if !profilers[source.target_idx]
            .conditional_pcs
            .contains(&source.pc)
        {
            continue;
        }
        let branch = resolver.resolve_branch_direction(profilers, source, to_ip)?;
        let Some(profile_pc) = profilers[branch.target_idx].profile_pc_for_xlated_pc(branch.pc)
        else {
            continue;
        };
        let target_samples = samples.entry(branch.prog_id).or_default();
        let counter = target_samples.sites.entry(profile_pc).or_default();
        counter.branch_count += 1;
        if flags & 1 != 0 {
            counter.branch_misses += 1;
        }
        if branch.taken {
            counter.taken += 1;
        } else {
            counter.not_taken += 1;
        }
        if !touched_progs.contains(&branch.prog_id) {
            touched_progs.push(branch.prog_id);
        }
    }
    for prog_id in touched_progs {
        samples.entry(prog_id).or_default().sample_records += 1;
    }
    Ok(())
}

fn parse_perf_event_header(bytes: &[u8]) -> Result<PerfEventHeader> {
    if bytes.len() != PERF_EVENT_HEADER_SIZE {
        bail!(
            "perf event header has {} bytes, expected {}",
            bytes.len(),
            PERF_EVENT_HEADER_SIZE
        );
    }
    Ok(PerfEventHeader {
        type_: read_u32(bytes, 0, "perf.header.type")?,
        misc: read_u16(bytes, 4, "perf.header.misc")?,
        size: read_u16(bytes, 6, "perf.header.size")?,
    })
}

fn page_size() -> Result<usize> {
    let raw = unsafe { libc::sysconf(libc::_SC_PAGESIZE) };
    if raw <= 0 {
        bail!("sysconf(_SC_PAGESIZE) returned {raw}");
    }
    raw.try_into()
        .map_err(|_| anyhow!("page size does not fit usize"))
}

fn branch_entry_type(flags: u64) -> u64 {
    (flags >> PERF_BRANCH_ENTRY_TYPE_SHIFT) & PERF_BRANCH_ENTRY_TYPE_MASK
}

fn branch_entry_is_conditional(flags: u64) -> bool {
    let branch_type = branch_entry_type(flags);
    branch_type == PERF_BR_UNKNOWN || branch_type == PERF_BR_COND
}

fn build_profiles(
    cli: &Cli,
    profilers: Vec<TargetProfiler>,
    samples_by_prog: BTreeMap<u32, TargetSamples>,
    before: &BTreeMap<u32, ProgStats>,
    after: &BTreeMap<u32, ProgStats>,
    duration_ms: u64,
) -> Result<Vec<ProfileJson>> {
    let mut inputs = Vec::new();
    for profiler in profilers {
        let before = before.get(&profiler.target.prog_id).ok_or_else(|| {
            anyhow!(
                "missing before stats for BPF program id {}",
                profiler.target.prog_id
            )
        })?;
        let after = after.get(&profiler.target.prog_id).ok_or_else(|| {
            anyhow!(
                "missing after stats for BPF program id {}",
                profiler.target.prog_id
            )
        })?;
        let delta = stats_delta(profiler.target.prog_id, before, after)?;
        let samples = samples_by_prog
            .get(&profiler.target.prog_id)
            .cloned()
            .unwrap_or_default();
        if cli.precise_branch_direction {
            eprintln!(
                "precise-debug prog_id={} in_jit={} attributed={} nonconditional_pc={} no_native_site={} profile_pc_miss={} native_sites={} conditional_sites={}",
                profiler.target.prog_id,
                samples.precise_in_jit,
                samples.sample_records,
                samples.precise_nonconditional_pc,
                samples.precise_no_native_site,
                samples.precise_profile_pc_miss,
                profiler.pc_map.native_branch_sites.len(),
                profiler.conditional_pcs.len(),
            );
            if !profiler.conditional_pcs.is_empty() {
                eprintln!(
                    "precise-remap-debug prog_id={} xlated_conditional_pcs={:?} source_conditional_pcs={:?} source_pc_by_xlated_pc={:?}",
                    profiler.target.prog_id,
                    profiler.conditional_pcs,
                    profiler.profile_pcs,
                    profiler.source_pc_by_xlated_pc,
                );
            }
        }
        if cli.all
            && cli.discover_shim_state_dir.is_none()
            && delta.run_cnt == 0
            && samples.sites.is_empty()
            && samples.tail_call_sites.is_empty()
        {
            continue;
        }
        inputs.push(ProfileBuildInput {
            prog_id: profiler.target.prog_id,
            run_cnt_delta: delta.run_cnt,
            run_time_ns_delta: delta.run_time_ns,
            expected_sites: profiler.profile_pcs,
            sites: samples.sites,
            tail_collection_enabled: cli.tail_target_key_map.is_some(),
            tail_call_sites: samples.tail_call_sites,
        });
    }
    let mut rows = build_profile_rows(inputs, duration_ms)?;
    for row in &mut rows {
        let Some(sampled) = samples_by_prog.get(&row.prog_id) else {
            continue;
        };
        let Some(sites) = row.tail_call_sites.as_mut() else {
            continue;
        };
        for (pc_text, site) in sites {
            let pc = pc_text.parse::<usize>().with_context(|| {
                format!("parse tail-call site PC {pc_text} for program {}", row.prog_id)
            })?;
            site.pid_key_counts = sampled
                .tail_call_pid_key_counts
                .get(&pc)
                .cloned()
                .unwrap_or_default();
            site.tid_key_counts = sampled
                .tail_call_tid_key_counts
                .get(&pc)
                .cloned()
                .unwrap_or_default();
        }
    }
    Ok(rows)
}

fn stats_delta(prog_id: u32, before: &ProgStats, after: &ProgStats) -> Result<ProgStats> {
    let run_cnt = after.run_cnt.checked_sub(before.run_cnt).ok_or_else(|| {
        anyhow!(
            "run_cnt for BPF program id {prog_id} decreased during profile window: {} -> {}",
            before.run_cnt,
            after.run_cnt
        )
    })?;
    let run_time_ns = after
        .run_time_ns
        .checked_sub(before.run_time_ns)
        .ok_or_else(|| {
            anyhow!(
            "run_time_ns for BPF program id {prog_id} decreased during profile window: {} -> {}",
            before.run_time_ns,
            after.run_time_ns
        )
        })?;
    Ok(ProgStats {
        run_cnt,
        run_time_ns,
    })
}

fn constrained_branch_miss_rate(branch_samples: u64, miss_samples: u64) -> f64 {
    if miss_samples == 0 {
        return 0.0;
    }
    if branch_samples == 0 || miss_samples >= branch_samples {
        return 1.0;
    }
    miss_samples as f64 / branch_samples as f64
}

fn build_profile_rows(
    inputs: Vec<ProfileBuildInput>,
    duration_ms: u64,
) -> Result<Vec<ProfileJson>> {
    let mut rows = Vec::with_capacity(inputs.len());
    for mut input in inputs {
        for pc in &input.expected_sites {
            input.sites.entry(*pc).or_default();
        }
        let branch_instructions = input
            .sites
            .values()
            .map(|site| site.branch_count)
            .sum::<u64>();
        let branch_misses = input
            .sites
            .values()
            .map(|site| site.branch_misses)
            .sum::<u64>();
        let mut per_site = BTreeMap::new();
        for (pc, site) in input.sites {
            let direction_total = site.taken.checked_add(site.not_taken).ok_or_else(|| {
                anyhow!(
                    "site {pc} in BPF program id {} direction counters overflow",
                    input.prog_id
                )
            })?;
            if direction_total != site.branch_count {
                bail!(
                    "site {pc} in BPF program id {} has branch_count {} but taken+not_taken {}",
                    input.prog_id,
                    site.branch_count,
                    direction_total
                );
            }
            /* Direction and mispredict events are independent fixed-period
             * PEBS streams, not nested exact counters.  Their low-frequency
             * sample totals can therefore cross.  The constrained Poisson
             * MLE preserves both raw PMU sample counts while keeping the
             * physical miss-rate estimate in [0, 1]. */
            let miss_rate = constrained_branch_miss_rate(site.branch_count, site.branch_misses);
            per_site.insert(
                pc.to_string(),
                PerSiteProfile {
                    branch_count: site.branch_count,
                    branch_misses: site.branch_misses,
                    miss_rate,
                    taken: site.taken,
                    not_taken: site.not_taken,
                },
            );
        }
        let tail_call_sites = if input.tail_collection_enabled {
            let mut sites = BTreeMap::new();
            for (pc, key_counts) in input.tail_call_sites {
                if key_counts.is_empty() {
                    bail!(
                        "tail-call site {pc} in BPF program id {} has no key samples",
                        input.prog_id
                    );
                }
                let observations = key_counts.values().try_fold(0u64, |sum, count| {
                    sum.checked_add(*count).ok_or_else(|| {
                        anyhow!(
                            "tail-call observation count overflow for program id {} pc {}",
                            input.prog_id,
                            pc
                        )
                    })
                })?;
                sites.insert(
                    pc.to_string(),
                    TailCallSiteProfile {
                        observations,
                        key_counts,
                        pid_key_counts: BTreeMap::new(),
                        tid_key_counts: BTreeMap::new(),
                    },
                );
            }
            Some(sites)
        } else {
            None
        };
        rows.push(ProfileJson {
            prog_id: input.prog_id,
            duration_ms,
            run_cnt_delta: input.run_cnt_delta,
            run_time_ns_delta: input.run_time_ns_delta,
            branch_miss_rate: constrained_branch_miss_rate(branch_instructions, branch_misses),
            branch_misses,
            branch_instructions,
            per_site,
            tail_call_sites,
        });
    }
    rows.sort_by(|a, b| {
        b.run_cnt_delta
            .cmp(&a.run_cnt_delta)
            .then_with(|| b.run_time_ns_delta.cmp(&a.run_time_ns_delta))
            .then_with(|| a.prog_id.cmp(&b.prog_id))
    });
    Ok(rows)
}

fn write_profiles(cli: &Cli, rows: &[ProfileJson]) -> Result<()> {
    if let Some(dir) = &cli.output_dir {
        fs::create_dir_all(dir).with_context(|| format!("create {}", dir.display()))?;
        for row in rows {
            let path = dir.join(format!("{}.json", row.prog_id));
            write_json_file(&path, row)?;
        }
        return Ok(());
    }

    let Some(path) = &cli.output else {
        bail!("profile JSON side-output requires --output FILE or --output-dir DIR");
    };
    if cli.all || cli.prog_ids.is_some() {
        return write_json_file(path, &rows);
    }
    let profile = rows
        .first()
        .ok_or_else(|| anyhow!("single-program profile unexpectedly empty"))?;
    write_json_file(path, profile)
}

fn write_empty_outputs(cli: &Cli) -> Result<()> {
    if let Some(dir) = &cli.output_dir {
        fs::create_dir_all(dir).with_context(|| format!("create {}", dir.display()))?;
    } else if let Some(path) = &cli.output {
        if cli.all {
            write_json_file(path, &Vec::<ProfileJson>::new())?;
        } else {
            bail!("no profile target found");
        }
    } else {
        bail!("no profile target found");
    }
    Ok(())
}

fn write_json_file<T: Serialize>(path: &Path, value: &T) -> Result<()> {
    let mut bytes = Vec::new();
    write_json(&mut bytes, value)?;
    fs::write(path, bytes).with_context(|| format!("write {}", path.display()))
}

fn write_json<T: Serialize, W: Write>(mut out: W, value: &T) -> Result<()> {
    serde_json::to_writer_pretty(&mut out, value)?;
    out.write_all(b"\n")?;
    out.flush()?;
    Ok(())
}

fn read_u32(bytes: &[u8], offset: usize, label: &str) -> Result<u32> {
    let end = offset
        .checked_add(std::mem::size_of::<u32>())
        .ok_or_else(|| anyhow!("{label} offset overflow"))?;
    let raw = bytes
        .get(offset..end)
        .ok_or_else(|| anyhow!("{label} is truncated at offset {offset}"))?;
    let raw: [u8; 4] = raw
        .try_into()
        .map_err(|_| anyhow!("{label} slice length changed after bounds check"))?;
    Ok(u32::from_ne_bytes(raw))
}

fn read_u16(bytes: &[u8], offset: usize, label: &str) -> Result<u16> {
    let end = offset
        .checked_add(std::mem::size_of::<u16>())
        .ok_or_else(|| anyhow!("{label} offset overflow"))?;
    let raw = bytes
        .get(offset..end)
        .ok_or_else(|| anyhow!("{label} is truncated at offset {offset}"))?;
    let raw: [u8; 2] = raw
        .try_into()
        .map_err(|_| anyhow!("{label} slice length changed after bounds check"))?;
    Ok(u16::from_ne_bytes(raw))
}

fn read_u64(bytes: &[u8], offset: usize, label: &str) -> Result<u64> {
    let end = offset
        .checked_add(std::mem::size_of::<u64>())
        .ok_or_else(|| anyhow!("{label} offset overflow"))?;
    let raw = bytes
        .get(offset..end)
        .ok_or_else(|| anyhow!("{label} is truncated at offset {offset}"))?;
    let raw: [u8; 8] = raw
        .try_into()
        .map_err(|_| anyhow!("{label} slice length changed after bounds check"))?;
    Ok(u64::from_ne_bytes(raw))
}

fn parse_duration(input: &str) -> Result<Duration, String> {
    humantime::parse_duration(input).map_err(|err| err.to_string())
}

fn duration_ms(duration: Duration) -> Result<u64> {
    duration
        .as_millis()
        .try_into()
        .map_err(|_| anyhow!("duration does not fit u64 milliseconds"))
}

fn error_is_enoent(err: &anyhow::Error) -> bool {
    format!("{err:#}").contains("No such file or directory")
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::fs::File;
    use std::mem::offset_of;

    fn sample_record(branches: &[(u64, u64, u64)]) -> Vec<u8> {
        let payload_len = 8 + branches.len() * PERF_BRANCH_ENTRY_SIZE;
        let record_len = PERF_EVENT_HEADER_SIZE + payload_len;
        let mut record = vec![0u8; record_len];
        record[0..4].copy_from_slice(&PERF_RECORD_SAMPLE.to_ne_bytes());
        record[6..8].copy_from_slice(&(record_len as u16).to_ne_bytes());
        let count = branches.len() as u64;
        record[PERF_EVENT_HEADER_SIZE..PERF_EVENT_HEADER_SIZE + 8]
            .copy_from_slice(&count.to_ne_bytes());
        for (idx, (from, to, flags)) in branches.iter().enumerate() {
            let base = PERF_EVENT_HEADER_SIZE + 8 + idx * PERF_BRANCH_ENTRY_SIZE;
            record[base..base + 8].copy_from_slice(&from.to_ne_bytes());
            record[base + 8..base + 16].copy_from_slice(&to.to_ne_bytes());
            record[base + 16..base + 24].copy_from_slice(&flags.to_ne_bytes());
        }
        record
    }

    fn sample_record_with_tid(pid: u32, tid: u32, branches: &[(u64, u64, u64)]) -> Vec<u8> {
        let payload_len = 8 + 8 + branches.len() * PERF_BRANCH_ENTRY_SIZE;
        let record_len = PERF_EVENT_HEADER_SIZE + payload_len;
        let mut record = vec![0u8; record_len];
        record[0..4].copy_from_slice(&PERF_RECORD_SAMPLE.to_ne_bytes());
        record[6..8].copy_from_slice(&(record_len as u16).to_ne_bytes());
        record[PERF_EVENT_HEADER_SIZE..PERF_EVENT_HEADER_SIZE + 4]
            .copy_from_slice(&pid.to_ne_bytes());
        record[PERF_EVENT_HEADER_SIZE + 4..PERF_EVENT_HEADER_SIZE + 8]
            .copy_from_slice(&tid.to_ne_bytes());
        let count = branches.len() as u64;
        record[PERF_EVENT_HEADER_SIZE + 8..PERF_EVENT_HEADER_SIZE + 16]
            .copy_from_slice(&count.to_ne_bytes());
        for (idx, (from, to, flags)) in branches.iter().enumerate() {
            let base = PERF_EVENT_HEADER_SIZE + 16 + idx * PERF_BRANCH_ENTRY_SIZE;
            record[base..base + 8].copy_from_slice(&from.to_ne_bytes());
            record[base + 8..base + 16].copy_from_slice(&to.to_ne_bytes());
            record[base + 16..base + 24].copy_from_slice(&flags.to_ne_bytes());
        }
        record
    }

    fn precise_sample_record(ip: u64, exact: bool) -> Vec<u8> {
        let record_len = PERF_EVENT_HEADER_SIZE + std::mem::size_of::<u64>();
        let mut record = vec![0u8; record_len];
        record[0..4].copy_from_slice(&PERF_RECORD_SAMPLE.to_ne_bytes());
        let misc = if exact { PERF_RECORD_MISC_EXACT_IP } else { 0 };
        record[4..6].copy_from_slice(&misc.to_ne_bytes());
        record[6..8].copy_from_slice(&(record_len as u16).to_ne_bytes());
        record[PERF_EVENT_HEADER_SIZE..].copy_from_slice(&ip.to_ne_bytes());
        record
    }

    fn lost_record() -> Vec<u8> {
        let mut record = vec![0u8; PERF_EVENT_HEADER_SIZE];
        record[0..4].copy_from_slice(&PERF_RECORD_LOST.to_ne_bytes());
        record[6..8].copy_from_slice(&(PERF_EVENT_HEADER_SIZE as u16).to_ne_bytes());
        record
    }

    fn throttle_record() -> Vec<u8> {
        let mut record = vec![0u8; PERF_EVENT_HEADER_SIZE];
        record[0..4].copy_from_slice(&PERF_RECORD_THROTTLE.to_ne_bytes());
        record[6..8].copy_from_slice(&(PERF_EVENT_HEADER_SIZE as u16).to_ne_bytes());
        record
    }

    fn branch_flags(branch_type: u64, mispred: bool) -> u64 {
        ((branch_type & PERF_BRANCH_ENTRY_TYPE_MASK) << PERF_BRANCH_ENTRY_TYPE_SHIFT)
            | u64::from(mispred)
    }

    fn fake_pc_map() -> JitPcMap {
        JitPcMap {
            ranges: vec![JitFuncRange {
                start_addr: 0x1000,
                end_addr: 0x1400,
            }],
            lines: vec![
                kernel_sys::JitedLineInfo {
                    insn_off: 10,
                    jited_addr: 0x1100,
                },
                kernel_sys::JitedLineInfo {
                    insn_off: 11,
                    jited_addr: 0x1110,
                },
                kernel_sys::JitedLineInfo {
                    insn_off: 20,
                    jited_addr: 0x1200,
                },
            ],
            native_branch_sites: Vec::new(),
        }
    }

    fn fake_profile_context() -> (Vec<TargetProfiler>, JitIpResolver) {
        let profilers = vec![TargetProfiler {
            target: Target {
                prog_id: 7,
                fd: File::open("/dev/null").unwrap().into(),
            },
            pc_map: fake_pc_map(),
            conditional_pcs: BTreeSet::from([10]),
            profile_pcs: BTreeSet::from([10]),
            tail_call_pcs: BTreeSet::new(),
            profile_tail_call_pcs: BTreeSet::new(),
            source_pc_by_xlated_pc: BTreeMap::new(),
        }];
        let resolver = JitIpResolver::from_profilers(&profilers, &BTreeMap::new()).unwrap();
        (profilers, resolver)
    }

    fn insn(code: u8, dst_reg: u8, src_reg: u8, off: i16, imm: i32) -> kernel_sys::bpf_insn {
        kernel_sys::bpf_insn {
            code,
            _bitfield_align_1: [],
            _bitfield_1: kernel_sys::bpf_insn::new_bitfield_1(dst_reg, src_reg),
            off,
            imm,
        }
    }

    fn temp_test_dir(name: &str) -> PathBuf {
        let stamp = std::time::SystemTime::now()
            .duration_since(std::time::UNIX_EPOCH)
            .unwrap()
            .as_nanos();
        let dir =
            std::env::temp_dir().join(format!("bpfprof-{name}-{}-{stamp}", std::process::id()));
        std::fs::create_dir(&dir).unwrap();
        dir
    }

    fn write_insns(path: &Path, insns: &[kernel_sys::bpf_insn]) {
        let bytes = unsafe {
            std::slice::from_raw_parts(insns.as_ptr().cast::<u8>(), std::mem::size_of_val(insns))
        };
        std::fs::write(path, bytes).unwrap();
    }

    #[test]
    fn remaps_translated_branch_pc_to_source_bytecode_pc() {
        let source = vec![
            insn(0xb7, 1, 0, 0, 0),
            insn(0x15, 1, 0, 2, 0),
            insn(0xb7, 0, 0, 0, 1),
            insn(0x05, 0, 0, 1, 0),
            insn(0xb7, 0, 0, 0, 0),
            insn(0x95, 0, 0, 0, 0),
        ];
        let xlated = vec![
            insn(0xb7, 1, 0, 0, 0),
            insn(0xbf, 9, 9, 0, 0),
            insn(0x15, 1, 0, 3, 0),
            insn(0xb7, 0, 0, 0, 1),
            insn(0x05, 0, 0, 1, 0),
            insn(0xb7, 0, 0, 0, 0),
            insn(0x95, 0, 0, 0, 0),
        ];

        let map = build_xlated_to_source_pc_remap(&xlated, &source, true).unwrap();

        assert_eq!(map.get(&2), Some(&1));
    }

    #[test]
    fn remaps_translated_tail_call_pc_to_source_bytecode_pc() {
        let source = vec![
            insn(0xb7, 3, 0, 0, 7),
            insn(0x85, 0, 0, 0, 12),
            insn(0x95, 0, 0, 0, 0),
        ];
        let xlated = vec![
            insn(0xbf, 9, 9, 0, 0),
            insn(0xb7, 3, 0, 0, 7),
            insn(0x85, 0, 0, 0, 12),
            insn(0x95, 0, 0, 0, 0),
        ];

        let map = build_xlated_to_source_pc_remap(&xlated, &source, true).unwrap();

        assert_eq!(map.get(&2), Some(&1));
    }

    #[test]
    fn tail_only_remap_excludes_conditional_sites_but_keeps_tail_call_sites() {
        let source = vec![
            insn(0x15, 1, 0, 1, 0),
            insn(0x85, 0, 0, 0, 12),
            insn(0x95, 0, 0, 0, 0),
        ];
        let xlated = vec![
            insn(0xbf, 9, 9, 0, 0),
            insn(0x15, 1, 0, 1, 0),
            insn(0x85, 0, 0, 0, 12),
            insn(0x95, 0, 0, 0, 0),
        ];

        let map = build_xlated_to_source_pc_remap(&xlated, &source, false).unwrap();

        assert_eq!(map, BTreeMap::from([(2, 1)]));
    }

    #[test]
    fn discovers_candidate_programs_from_shim_state_files() {
        let dir = temp_test_dir("discover-state");
        let candidate = dir.join("candidate.bpf");
        let no_branch = dir.join("no_branch.bpf");
        write_insns(
            &candidate,
            &[
                insn(0xb7, 1, 0, 0, 0),
                insn(0x15, 1, 0, 1, 0),
                insn(0x95, 0, 0, 0, 0),
            ],
        );
        write_insns(
            &no_branch,
            &[insn(0xb7, 1, 0, 0, 0), insn(0x95, 0, 0, 0, 0)],
        );
        std::fs::write(
            dir.join("state_123.json"),
            format!(
                r#"{{
  "pid": 123,
  "progs": [
    {{"kernel_prog_id": 42, "bytecode_path": "{}"}},
    {{"kernel_prog_id": 43, "bytecode_path": "{}"}},
    {{"kernel_prog_id": 0, "bytecode_path": "{}"}}
  ]
}}"#,
                candidate.display(),
                no_branch.display(),
                candidate.display()
            ),
        )
        .unwrap();

        let programs = discover_shim_state_programs(&dir).unwrap();

        assert_eq!(
            programs,
            vec![ShimStateProgram {
                prog_id: 42,
                bytecode_path: candidate,
            }]
        );
        std::fs::remove_dir_all(dir).unwrap();
    }

    #[test]
    fn jit_pc_map_respects_function_ranges_with_nonzero_starts() {
        let map = JitPcMap {
            ranges: vec![
                JitFuncRange {
                    start_addr: 0x1000,
                    end_addr: 0x1100,
                },
                JitFuncRange {
                    start_addr: 0x2000,
                    end_addr: 0x2100,
                },
            ],
            lines: vec![
                kernel_sys::JitedLineInfo {
                    insn_off: 20,
                    jited_addr: 0x1000,
                },
                kernel_sys::JitedLineInfo {
                    insn_off: 2296,
                    jited_addr: 0x2000,
                },
                kernel_sys::JitedLineInfo {
                    insn_off: 2297,
                    jited_addr: 0x2010,
                },
            ],
            native_branch_sites: Vec::new(),
        };

        assert_eq!(map.pc_for_ip(0x2004), Some(2296));
        assert_eq!(map.pc_for_ip(0x2014), Some(2297));
    }

    #[cfg(target_arch = "x86_64")]
    #[test]
    fn scans_x86_conditional_branches_with_in_range_targets() {
        let sites = scan_x86_conditional_branches(
            &[
                0x48, 0x85, 0xc0, // test %rax,%rax
                0x74, 0x03, // je +3
                0x90, 0x90, 0x90, 0xc3,
            ],
            0x1000,
            0x1009,
        )
        .unwrap();

        assert_eq!(sites.len(), 1);
        assert_eq!(sites[0].pebs_start_addr, 0x1000);
        assert_eq!(sites[0].start_addr, 0x1003);
        assert_eq!(sites[0].fallthrough_addr, 0x1005);
        assert_eq!(sites[0].jump_target_addr, 0x1008);
    }

    #[test]
    fn excludes_zero_offset_conditional_without_distinct_successors() {
        let pcs = conditional_branch_pcs(&[
            insn(0x15, 1, 0, 0, 7),
            insn(0x15, 1, 0, 1, 7),
            insn(0x55, 1, 0, -1, 9),
        ]);

        assert_eq!(pcs, BTreeSet::from([1, 2]));
    }

    #[cfg(target_arch = "x86_64")]
    #[test]
    fn decodes_x86_bswap_without_losing_instruction_alignment() {
        let bswap32 = decode_x86_instruction_at(&[0x0f, 0xce]).unwrap();
        assert_eq!(bswap32.len, 2);
        assert!(bswap32.branch.is_none());

        let bswap64 = decode_x86_instruction_at(&[0x48, 0x0f, 0xcf]).unwrap();
        assert_eq!(bswap64.len, 3);
        assert!(bswap64.branch.is_none());
    }

    #[cfg(target_arch = "x86_64")]
    #[test]
    fn decodes_x86_bmi2_shift_without_losing_instruction_alignment() {
        let sites = scan_x86_conditional_branches(
            &[
                0xc4, 0xe2, 0x89, 0xf7, 0xff, // shlx %r14,%rdi,%rdi
                0x75, 0x00, // jne +0
                0xc3,
            ],
            0x1000,
            0x1008,
        )
        .unwrap();

        assert_eq!(sites.len(), 1);
        assert_eq!(sites[0].start_addr, 0x1005);
        assert_eq!(sites[0].fallthrough_addr, 0x1007);
        assert_eq!(sites[0].jump_target_addr, 0x1007);
    }

    #[cfg(target_arch = "x86_64")]
    #[test]
    fn line_constrained_alignment_skips_jit_internal_branch() {
        let native = vec![
            NativeBranchSite {
                pebs_start_addr: 0x100f,
                start_addr: 0x1010,
                end_addr: 0x1012,
                fallthrough_addr: 0x1012,
                jump_target_addr: 0x1050,
                condition: 0x4,
                pc: 0,
                jump_is_bpf_target: true,
            },
            NativeBranchSite {
                pebs_start_addr: 0x101f,
                start_addr: 0x1020,
                end_addr: 0x1022,
                fallthrough_addr: 0x1022,
                jump_target_addr: 0x1060,
                condition: 0x4,
                pc: 0,
                jump_is_bpf_target: true,
            },
            NativeBranchSite {
                pebs_start_addr: 0x102f,
                start_addr: 0x1030,
                end_addr: 0x1032,
                fallthrough_addr: 0x1032,
                jump_target_addr: 0x1070,
                condition: 0x4,
                pc: 0,
                jump_is_bpf_target: true,
            },
        ];
        let ranges = vec![JitFuncRange {
            start_addr: 0x1000,
            end_addr: 0x1100,
        }];
        let lines = vec![
            kernel_sys::JitedLineInfo {
                insn_off: 1,
                jited_addr: 0x1010,
            },
            kernel_sys::JitedLineInfo {
                insn_off: 2,
                jited_addr: 0x1020,
            },
            kernel_sys::JitedLineInfo {
                insn_off: 3,
                jited_addr: 0x1030,
            },
            kernel_sys::JitedLineInfo {
                insn_off: 4,
                jited_addr: 0x1040,
            },
        ];

        let xlated = vec![
            insn(0xb7, 0, 0, 0, 0),
            insn(0x15, 1, 0, 1, 7),
            insn(0xb7, 0, 0, 0, 0),
            insn(0x15, 1, 0, 1, 9),
            insn(0xb7, 0, 0, 0, 0),
            insn(0x95, 0, 0, 0, 0),
        ];
        let image = vec![0u8; 0x100];
        let mapped = align_native_branch_sites_with_lines(
            native,
            &ranges,
            &lines,
            &xlated,
            &BTreeSet::from([1, 3]),
            &image,
        )
        .unwrap();

        assert_eq!(mapped.len(), 2);
        assert_eq!(mapped[&1].start_addr, 0x1010);
        assert_eq!(mapped[&3].start_addr, 0x1030);
    }

    #[cfg(target_arch = "x86_64")]
    #[test]
    fn branch_alignment_rejects_same_line_jit_guard_with_wrong_direction() {
        let native = vec![
            NativeBranchSite {
                pebs_start_addr: 0x100f,
                start_addr: 0x1010,
                end_addr: 0x1012,
                fallthrough_addr: 0x1012,
                jump_target_addr: 0x1008,
                condition: 0x4,
                pc: 0,
                jump_is_bpf_target: true,
            },
            NativeBranchSite {
                pebs_start_addr: 0x101f,
                start_addr: 0x1020,
                end_addr: 0x1022,
                fallthrough_addr: 0x1022,
                jump_target_addr: 0x1050,
                condition: 0x4,
                pc: 0,
                jump_is_bpf_target: true,
            },
        ];
        let ranges = vec![JitFuncRange {
            start_addr: 0x1000,
            end_addr: 0x1100,
        }];
        let lines = vec![
            kernel_sys::JitedLineInfo {
                insn_off: 1,
                jited_addr: 0x1000,
            },
            kernel_sys::JitedLineInfo {
                insn_off: 2,
                jited_addr: 0x1040,
            },
            kernel_sys::JitedLineInfo {
                insn_off: 3,
                jited_addr: 0x1050,
            },
        ];
        let xlated = vec![
            insn(0xb7, 0, 0, 0, 0),
            insn(0x15, 1, 0, 1, 7),
            insn(0xb7, 0, 0, 0, 0),
            insn(0x95, 0, 0, 0, 0),
        ];
        let image = vec![0u8; 0x100];

        let mapped = align_native_branch_sites_with_lines(
            native,
            &ranges,
            &lines,
            &xlated,
            &BTreeSet::from([1]),
            &image,
        )
        .unwrap();

        assert_eq!(mapped.len(), 1);
        assert_eq!(mapped[&1].start_addr, 0x1020);
    }

    #[test]
    fn lbr_sample_uses_native_branch_fallthrough_without_line_info() {
        let record = sample_record(&[
            (0x1100, 0x1102, branch_flags(PERF_BR_COND, false)),
            (0x1100, 0x1110, branch_flags(PERF_BR_COND, true)),
        ]);
        let profilers = vec![TargetProfiler {
            target: Target {
                prog_id: 7,
                fd: File::open("/dev/null").unwrap().into(),
            },
            pc_map: JitPcMap {
                ranges: vec![JitFuncRange {
                    start_addr: 0x10f0,
                    end_addr: 0x1120,
                }],
                lines: Vec::new(),
                native_branch_sites: vec![NativeBranchSite {
                    pebs_start_addr: 0x10fe,
                    start_addr: 0x1100,
                    end_addr: 0x1102,
                    fallthrough_addr: 0x1102,
                    jump_target_addr: 0x1110,
                    condition: 0x4,
                    pc: 10,
                    jump_is_bpf_target: true,
                }],
            },
            conditional_pcs: BTreeSet::from([10]),
            profile_pcs: BTreeSet::from([10]),
            tail_call_pcs: BTreeSet::new(),
            profile_tail_call_pcs: BTreeSet::new(),
            source_pc_by_xlated_pc: BTreeMap::new(),
        }];
        let resolver = JitIpResolver::from_profilers(&profilers, &BTreeMap::new()).unwrap();
        let mut samples = BTreeMap::new();

        process_perf_record(&record, &resolver, &profilers, &mut samples).unwrap();

        let site = samples.get(&7).unwrap().sites.get(&10).unwrap();
        assert_eq!(site.branch_count, 2);
        assert_eq!(site.branch_misses, 1);
        assert_eq!(site.not_taken, 1);
        assert_eq!(site.taken, 1);
    }

    #[test]
    fn lbr_sample_inverts_native_direction_for_inverted_jcc() {
        let record = sample_record(&[
            (0x1100, 0x1110, branch_flags(PERF_BR_COND, false)),
            (0x1100, 0x1110, branch_flags(PERF_BR_COND, false)),
            (0x1100, 0x1102, branch_flags(PERF_BR_COND, false)),
        ]);
        let profilers = vec![TargetProfiler {
            target: Target {
                prog_id: 7,
                fd: File::open("/dev/null").unwrap().into(),
            },
            pc_map: JitPcMap {
                ranges: vec![JitFuncRange {
                    start_addr: 0x1100,
                    end_addr: 0x1120,
                }],
                lines: Vec::new(),
                native_branch_sites: vec![NativeBranchSite {
                    pebs_start_addr: 0x10fe,
                    start_addr: 0x1100,
                    end_addr: 0x1102,
                    fallthrough_addr: 0x1102,
                    jump_target_addr: 0x1110,
                    condition: 0x4,
                    pc: 10,
                    jump_is_bpf_target: false,
                }],
            },
            conditional_pcs: BTreeSet::from([10]),
            profile_pcs: BTreeSet::from([10]),
            tail_call_pcs: BTreeSet::new(),
            profile_tail_call_pcs: BTreeSet::new(),
            source_pc_by_xlated_pc: BTreeMap::new(),
        }];
        let resolver = JitIpResolver::from_profilers(&profilers, &BTreeMap::new()).unwrap();
        let mut samples = BTreeMap::new();

        process_perf_record(&record, &resolver, &profilers, &mut samples).unwrap();

        let site = samples.get(&7).unwrap().sites.get(&10).unwrap();
        assert_eq!(site.branch_count, 3);
        assert_eq!(site.not_taken, 2);
        assert_eq!(site.taken, 1);
    }

    #[test]
    fn precise_branch_samples_record_real_direction_and_misses() {
        let profilers = vec![TargetProfiler {
            target: Target {
                prog_id: 7,
                fd: File::open("/dev/null").unwrap().into(),
            },
            pc_map: JitPcMap {
                ranges: vec![JitFuncRange {
                    start_addr: 0x10f0,
                    end_addr: 0x1120,
                }],
                lines: Vec::new(),
                native_branch_sites: vec![NativeBranchSite {
                    pebs_start_addr: 0x10fe,
                    start_addr: 0x1100,
                    end_addr: 0x1102,
                    fallthrough_addr: 0x1102,
                    jump_target_addr: 0x1110,
                    condition: 0x4,
                    pc: 10,
                    jump_is_bpf_target: true,
                }],
            },
            conditional_pcs: BTreeSet::from([10]),
            profile_pcs: BTreeSet::from([10]),
            tail_call_pcs: BTreeSet::new(),
            profile_tail_call_pcs: BTreeSet::new(),
            source_pc_by_xlated_pc: BTreeMap::new(),
        }];
        let resolver = JitIpResolver::from_profilers(&profilers, &BTreeMap::new()).unwrap();
        let taken_record = precise_sample_record(0x1100, true);
        let not_taken_record = precise_sample_record(0x10fe, true);
        let mut samples = BTreeMap::new();

        process_perf_record_for_kind(
            &taken_record,
            PerfSampleKind::PreciseBranch {
                native_taken: true,
                mispredicted: false,
            },
            &resolver,
            &profilers,
            &mut samples,
        )
        .unwrap();
        process_perf_record_for_kind(
            &not_taken_record,
            PerfSampleKind::PreciseBranch {
                native_taken: false,
                mispredicted: false,
            },
            &resolver,
            &profilers,
            &mut samples,
        )
        .unwrap();
        process_perf_record_for_kind(
            &not_taken_record,
            PerfSampleKind::PreciseBranch {
                native_taken: false,
                mispredicted: true,
            },
            &resolver,
            &profilers,
            &mut samples,
        )
        .unwrap();

        let site = &samples[&7].sites[&10];
        assert_eq!(site.branch_count, 2);
        assert_eq!(site.taken, 1);
        assert_eq!(site.not_taken, 1);
        assert_eq!(site.branch_misses, 1);
    }

    #[test]
    fn precise_branch_sample_requires_exact_ip() {
        let (profilers, resolver) = fake_profile_context();
        let record = precise_sample_record(0x1100, false);
        let mut samples = BTreeMap::new();

        let err = process_perf_record_for_kind(
            &record,
            PerfSampleKind::PreciseBranch {
                native_taken: true,
                mispredicted: false,
            },
            &resolver,
            &profilers,
            &mut samples,
        )
        .unwrap_err();

        assert!(err.to_string().contains("PERF_RECORD_MISC_EXACT_IP"));
    }

    #[test]
    fn precise_branch_sample_ignores_jit_internal_conditional() {
        let (profilers, resolver) = fake_profile_context();
        let record = precise_sample_record(0x1100, true);
        let mut samples = BTreeMap::new();

        process_perf_record_for_kind(
            &record,
            PerfSampleKind::PreciseBranch {
                native_taken: true,
                mispredicted: false,
            },
            &resolver,
            &profilers,
            &mut samples,
        )
        .unwrap();

        assert!(samples[&7].sites.is_empty());
        assert_eq!(samples[&7].precise_in_jit, 1);
        assert_eq!(samples[&7].precise_no_native_site, 1);
    }

    #[test]
    fn arrow_lake_extended_umask_uses_hybrid_config_bits() {
        assert_eq!(intel_hybrid_raw_config(0xc4, 0x101), 0x100000001c4);
        assert_eq!(intel_hybrid_raw_config(0xc4, 0x010), 0x10c4);
    }

    #[test]
    fn parses_hybrid_pmu_cpu_list() {
        assert_eq!(
            parse_cpu_list("0-3,6,8-9\n", "test").unwrap(),
            vec![0, 1, 2, 3, 6, 8, 9]
        );
        assert!(parse_cpu_list("3-1", "test").is_err());
    }

    #[test]
    fn lbr_sample_attributes_misses_and_direction_to_bpf_pc() {
        let record = sample_record(&[
            (0x1104, 0x1110, branch_flags(PERF_BR_COND, false)),
            (0x1108, 0x1200, branch_flags(PERF_BR_COND, true)),
            (0x1500, 0x1200, branch_flags(PERF_BR_COND, true)),
        ]);
        let (profilers, resolver) = fake_profile_context();
        let mut samples = BTreeMap::new();

        process_perf_record(&record, &resolver, &profilers, &mut samples).unwrap();

        let target_samples = samples.get(&7).unwrap();
        assert_eq!(target_samples.sample_records, 1);
        let site = target_samples.sites.get(&10).unwrap();
        assert_eq!(site.branch_count, 2);
        assert_eq!(site.branch_misses, 1);
        assert_eq!(site.not_taken, 1);
        assert_eq!(site.taken, 1);
    }

    #[test]
    fn lbr_sample_skips_unmapped_translated_source_pc() {
        let record = sample_record(&[(0x1104, 0x1110, branch_flags(PERF_BR_COND, false))]);
        let profilers = vec![TargetProfiler {
            target: Target {
                prog_id: 7,
                fd: File::open("/dev/null").unwrap().into(),
            },
            pc_map: fake_pc_map(),
            conditional_pcs: BTreeSet::from([10]),
            profile_pcs: BTreeSet::from([200]),
            tail_call_pcs: BTreeSet::new(),
            profile_tail_call_pcs: BTreeSet::new(),
            source_pc_by_xlated_pc: BTreeMap::from([(20, 200)]),
        }];
        let resolver = JitIpResolver::from_profilers(&profilers, &BTreeMap::new()).unwrap();
        let mut samples = BTreeMap::new();

        process_perf_record(&record, &resolver, &profilers, &mut samples).unwrap();

        assert!(samples.is_empty());
    }

    #[test]
    fn lbr_sample_ignores_non_conditional_branches() {
        const PERF_BR_CALL: u64 = 4;
        let record = sample_record(&[
            (0x1104, 0x1200, branch_flags(PERF_BR_CALL, false)),
            (0x1204, 0x1100, branch_flags(PERF_BR_COND, false)),
        ]);
        let (profilers, resolver) = fake_profile_context();
        let mut samples = BTreeMap::new();

        process_perf_record(&record, &resolver, &profilers, &mut samples).unwrap();

        assert!(samples.get(&7).is_none());
    }

    #[test]
    fn lbr_cross_program_tail_edge_records_program_array_key() {
        let record = sample_record(&[(0x1044, 0x2000, branch_flags(PERF_BR_UNKNOWN, false))]);
        let profilers = vec![
            TargetProfiler {
                target: Target {
                    prog_id: 7,
                    fd: File::open("/dev/null").unwrap().into(),
                },
                pc_map: JitPcMap {
                    ranges: vec![JitFuncRange {
                        start_addr: 0x1000,
                        end_addr: 0x1100,
                    }],
                    lines: vec![kernel_sys::JitedLineInfo {
                        insn_off: 4,
                        jited_addr: 0x1040,
                    }],
                    native_branch_sites: Vec::new(),
                },
                conditional_pcs: BTreeSet::new(),
                profile_pcs: BTreeSet::new(),
                tail_call_pcs: BTreeSet::from([4]),
                profile_tail_call_pcs: BTreeSet::from([4]),
                source_pc_by_xlated_pc: BTreeMap::new(),
            },
            TargetProfiler {
                target: Target {
                    prog_id: 8,
                    fd: File::open("/dev/null").unwrap().into(),
                },
                pc_map: JitPcMap {
                    ranges: vec![JitFuncRange {
                        start_addr: 0x2000,
                        end_addr: 0x2100,
                    }],
                    lines: vec![kernel_sys::JitedLineInfo {
                        insn_off: 0,
                        jited_addr: 0x2000,
                    }],
                    native_branch_sites: Vec::new(),
                },
                conditional_pcs: BTreeSet::new(),
                profile_pcs: BTreeSet::new(),
                tail_call_pcs: BTreeSet::new(),
                profile_tail_call_pcs: BTreeSet::new(),
                source_pc_by_xlated_pc: BTreeMap::new(),
            },
        ];
        let resolver =
            JitIpResolver::from_profilers(&profilers, &BTreeMap::from([(8, 7)])).unwrap();
        let mut samples = BTreeMap::new();

        process_perf_record(&record, &resolver, &profilers, &mut samples).unwrap();

        assert_eq!(samples[&7].tail_call_sites[&4][&7], 1);
        assert_eq!(samples[&7].sample_records, 1);
    }

    #[test]
    fn lbr_tid_sample_records_tail_key_for_exact_worker_pid_and_tid() {
        const WORKER_PID: u32 = 4242;
        const WORKER_TID: u32 = 4243;
        let record = sample_record_with_tid(
            WORKER_PID,
            WORKER_TID,
            &[(0x1044, 0x2000, branch_flags(PERF_BR_UNKNOWN, false))],
        );
        let profilers = vec![
            TargetProfiler {
                target: Target {
                    prog_id: 7,
                    fd: File::open("/dev/null").unwrap().into(),
                },
                pc_map: JitPcMap {
                    ranges: vec![JitFuncRange {
                        start_addr: 0x1000,
                        end_addr: 0x1100,
                    }],
                    lines: vec![kernel_sys::JitedLineInfo {
                        insn_off: 4,
                        jited_addr: 0x1040,
                    }],
                    native_branch_sites: Vec::new(),
                },
                conditional_pcs: BTreeSet::new(),
                profile_pcs: BTreeSet::new(),
                tail_call_pcs: BTreeSet::from([4]),
                profile_tail_call_pcs: BTreeSet::from([4]),
                source_pc_by_xlated_pc: BTreeMap::new(),
            },
            TargetProfiler {
                target: Target {
                    prog_id: 8,
                    fd: File::open("/dev/null").unwrap().into(),
                },
                pc_map: JitPcMap {
                    ranges: vec![JitFuncRange {
                        start_addr: 0x2000,
                        end_addr: 0x2100,
                    }],
                    lines: vec![kernel_sys::JitedLineInfo {
                        insn_off: 0,
                        jited_addr: 0x2000,
                    }],
                    native_branch_sites: Vec::new(),
                },
                conditional_pcs: BTreeSet::new(),
                profile_pcs: BTreeSet::new(),
                tail_call_pcs: BTreeSet::new(),
                profile_tail_call_pcs: BTreeSet::new(),
                source_pc_by_xlated_pc: BTreeMap::new(),
            },
        ];
        let resolver =
            JitIpResolver::from_profilers(&profilers, &BTreeMap::from([(8, 1)])).unwrap();
        let mut samples = BTreeMap::new();

        process_perf_record_for_kind(
            &record,
            PerfSampleKind::Lbr { sample_tid: true },
            &resolver,
            &profilers,
            &mut samples,
        )
        .unwrap();

        assert_eq!(samples[&7].tail_call_sites[&4][&1], 1);
        assert_eq!(
            samples[&7].tail_call_pid_key_counts[&4][&WORKER_PID][&1],
            1
        );
        assert_eq!(
            samples[&7].tail_call_tid_key_counts[&4][&WORKER_TID][&1],
            1
        );
        assert_eq!(samples[&7].sample_records, 1);
    }

    #[test]
    fn lbr_without_line_info_attributes_edge_to_only_tail_call_site() {
        let record = sample_record(&[(0x1044, 0x2000, branch_flags(PERF_BR_UNKNOWN, false))]);
        let profilers = vec![
            TargetProfiler {
                target: Target {
                    prog_id: 7,
                    fd: File::open("/dev/null").unwrap().into(),
                },
                pc_map: JitPcMap {
                    ranges: vec![JitFuncRange {
                        start_addr: 0x1000,
                        end_addr: 0x1100,
                    }],
                    lines: Vec::new(),
                    native_branch_sites: Vec::new(),
                },
                conditional_pcs: BTreeSet::new(),
                profile_pcs: BTreeSet::new(),
                tail_call_pcs: BTreeSet::from([4]),
                profile_tail_call_pcs: BTreeSet::from([4]),
                source_pc_by_xlated_pc: BTreeMap::new(),
            },
            TargetProfiler {
                target: Target {
                    prog_id: 8,
                    fd: File::open("/dev/null").unwrap().into(),
                },
                pc_map: JitPcMap {
                    ranges: vec![JitFuncRange {
                        start_addr: 0x2000,
                        end_addr: 0x2100,
                    }],
                    lines: Vec::new(),
                    native_branch_sites: Vec::new(),
                },
                conditional_pcs: BTreeSet::new(),
                profile_pcs: BTreeSet::new(),
                tail_call_pcs: BTreeSet::new(),
                profile_tail_call_pcs: BTreeSet::new(),
                source_pc_by_xlated_pc: BTreeMap::new(),
            },
        ];
        let resolver =
            JitIpResolver::from_profilers(&profilers, &BTreeMap::from([(8, 7)])).unwrap();
        let mut samples = BTreeMap::new();

        process_perf_record(&record, &resolver, &profilers, &mut samples).unwrap();

        assert_eq!(samples[&7].tail_call_sites[&4][&7], 1);
        assert_eq!(samples[&7].sample_records, 1);
    }

    #[test]
    fn lbr_self_tail_edge_records_program_array_key() {
        let record = sample_record(&[(0x1044, 0x1000, branch_flags(PERF_BR_UNKNOWN, false))]);
        let profilers = vec![TargetProfiler {
            target: Target {
                prog_id: 7,
                fd: File::open("/dev/null").unwrap().into(),
            },
            pc_map: JitPcMap {
                ranges: vec![JitFuncRange {
                    start_addr: 0x1000,
                    end_addr: 0x1100,
                }],
                lines: vec![
                    kernel_sys::JitedLineInfo {
                        insn_off: 0,
                        jited_addr: 0x1000,
                    },
                    kernel_sys::JitedLineInfo {
                        insn_off: 4,
                        jited_addr: 0x1040,
                    },
                ],
                native_branch_sites: Vec::new(),
            },
            conditional_pcs: BTreeSet::new(),
            profile_pcs: BTreeSet::new(),
            tail_call_pcs: BTreeSet::from([4]),
            profile_tail_call_pcs: BTreeSet::from([4]),
            source_pc_by_xlated_pc: BTreeMap::new(),
        }];
        let resolver =
            JitIpResolver::from_profilers(&profilers, &BTreeMap::from([(7, 0)])).unwrap();
        let mut samples = BTreeMap::new();

        process_perf_record(&record, &resolver, &profilers, &mut samples).unwrap();

        assert_eq!(samples[&7].tail_call_sites[&4][&0], 1);
        assert_eq!(samples[&7].sample_records, 1);
    }

    #[test]
    fn lbr_sparse_line_info_attributes_native_tail_edge_to_unique_helper_site() {
        let record = sample_record(&[(0x1044, 0x100c, branch_flags(PERF_BR_UNKNOWN, false))]);
        let profilers = vec![TargetProfiler {
            target: Target {
                prog_id: 7,
                fd: File::open("/dev/null").unwrap().into(),
            },
            pc_map: JitPcMap {
                ranges: vec![JitFuncRange {
                    start_addr: 0x1000,
                    end_addr: 0x1100,
                }],
                lines: vec![
                    kernel_sys::JitedLineInfo {
                        insn_off: 0,
                        jited_addr: 0x1000,
                    },
                    kernel_sys::JitedLineInfo {
                        insn_off: 4,
                        jited_addr: 0x1040,
                    },
                    kernel_sys::JitedLineInfo {
                        insn_off: 12,
                        jited_addr: 0x1080,
                    },
                ],
                native_branch_sites: Vec::new(),
            },
            conditional_pcs: BTreeSet::new(),
            profile_pcs: BTreeSet::new(),
            tail_call_pcs: BTreeSet::from([8]),
            profile_tail_call_pcs: BTreeSet::from([8]),
            source_pc_by_xlated_pc: BTreeMap::new(),
        }];
        let resolver =
            JitIpResolver::from_profilers(&profilers, &BTreeMap::from([(7, 0)])).unwrap();
        let mut samples = BTreeMap::new();

        process_perf_record(&record, &resolver, &profilers, &mut samples).unwrap();

        assert_eq!(samples[&7].tail_call_sites[&8][&0], 1);
        assert_eq!(samples[&7].sample_records, 1);
    }

    #[test]
    fn unknown_lbr_type_counts_when_bpf_opcode_is_conditional() {
        let record = sample_record(&[(0x1104, 0x1110, branch_flags(PERF_BR_UNKNOWN, false))]);
        let (profilers, resolver) = fake_profile_context();
        let mut samples = BTreeMap::new();

        process_perf_record(&record, &resolver, &profilers, &mut samples).unwrap();

        let site = samples.get(&7).unwrap().sites.get(&10).unwrap();
        assert_eq!(site.branch_count, 1);
        assert_eq!(site.not_taken, 1);
    }

    #[test]
    fn conditional_lbr_target_must_map_to_bpf_pc() {
        let record = sample_record(&[(0x1104, 0x1500, branch_flags(PERF_BR_COND, false))]);
        let (profilers, resolver) = fake_profile_context();
        let mut samples = BTreeMap::new();

        let err = process_perf_record(&record, &resolver, &profilers, &mut samples).unwrap_err();

        assert!(err.to_string().contains("outside target JIT map"));
    }

    #[test]
    fn lost_perf_record_is_a_hard_error() {
        let (profilers, resolver) = fake_profile_context();
        let mut samples = BTreeMap::new();

        let err =
            process_perf_record(&lost_record(), &resolver, &profilers, &mut samples).unwrap_err();

        assert!(err.to_string().contains("lost PMU branch-stack records"));
    }

    #[test]
    fn throttled_perf_record_is_a_hard_error() {
        let (profilers, resolver) = fake_profile_context();
        let mut samples = BTreeMap::new();

        let err = process_perf_record(&throttle_record(), &resolver, &profilers, &mut samples)
            .unwrap_err();

        assert!(err.to_string().contains("sampler was throttled"));
    }

    #[test]
    fn perf_mmap_page_offsets_match_linux_uapi_prefix() {
        assert_eq!(offset_of!(PerfEventMmapPage, data_head), 1024);
        assert_eq!(offset_of!(PerfEventMmapPage, data_tail), 1032);
        assert_eq!(offset_of!(PerfEventMmapPage, data_offset), 1040);
        assert_eq!(offset_of!(PerfEventMmapPage, data_size), 1048);
    }

    #[test]
    fn profile_json_serializes_required_branch_metrics() {
        let rows = build_profile_rows(
            vec![ProfileBuildInput {
                prog_id: 123,
                run_cnt_delta: 10,
                run_time_ns_delta: 2_000,
                expected_sites: BTreeSet::from([42]),
                sites: BTreeMap::from([(
                    42,
                    SiteCounters {
                        branch_count: 10,
                        branch_misses: 2,
                        taken: 7,
                        not_taken: 3,
                    },
                )]),
                tail_collection_enabled: false,
                tail_call_sites: BTreeMap::new(),
            }],
            500,
        )
        .unwrap();

        let value = serde_json::to_value(&rows[0]).unwrap();

        assert_eq!(value["prog_id"], 123);
        assert_eq!(value["duration_ms"], 500);
        assert_eq!(value["branch_miss_rate"], 0.2);
        assert_eq!(value["branch_misses"], 2);
        assert_eq!(value["branch_instructions"], 10);
        assert_eq!(value["per_site"]["42"]["branch_count"], 10);
        assert_eq!(value["per_site"]["42"]["miss_rate"], 0.2);
        assert!(value.get("per_insn").is_none());
    }

    #[test]
    fn profile_json_preserves_crossing_independent_pmu_samples() {
        let rows = build_profile_rows(
            vec![ProfileBuildInput {
                prog_id: 123,
                run_cnt_delta: 10,
                run_time_ns_delta: 2_000,
                expected_sites: BTreeSet::from([42]),
                sites: BTreeMap::from([(
                    42,
                    SiteCounters {
                        branch_count: 0,
                        branch_misses: 1,
                        taken: 0,
                        not_taken: 0,
                    },
                )]),
                tail_collection_enabled: false,
                tail_call_sites: BTreeMap::new(),
            }],
            500,
        )
        .unwrap();

        let site = rows[0].per_site.get("42").unwrap();
        assert_eq!(site.branch_count, 0);
        assert_eq!(site.branch_misses, 1);
        assert_eq!(site.miss_rate, 1.0);
        assert_eq!(rows[0].branch_miss_rate, 1.0);
    }

    #[test]
    fn profile_json_serializes_tail_key_histogram_when_collected() {
        let rows = build_profile_rows(
            vec![ProfileBuildInput {
                prog_id: 7,
                run_cnt_delta: 100,
                run_time_ns_delta: 1_000,
                expected_sites: BTreeSet::new(),
                sites: BTreeMap::new(),
                tail_collection_enabled: true,
                tail_call_sites: BTreeMap::from([(4, BTreeMap::from([(7, 90), (9, 10)]))]),
            }],
            500,
        )
        .unwrap();

        let mut rows = rows;
        let site = rows[0]
            .tail_call_sites
            .as_mut()
            .unwrap()
            .get_mut("4")
            .unwrap();
        site.pid_key_counts = BTreeMap::from([(4242, BTreeMap::from([(7, 3)]))]);
        site.tid_key_counts = BTreeMap::from([(4243, BTreeMap::from([(7, 2)]))]);

        let value = serde_json::to_value(&rows[0]).unwrap();
        assert_eq!(value["tail_call_sites"]["4"]["observations"], 100);
        assert_eq!(value["tail_call_sites"]["4"]["key_counts"]["7"], 90);
        assert_eq!(
            value["tail_call_sites"]["4"]["pid_key_counts"]["4242"]["7"],
            3
        );
        assert_eq!(
            value["tail_call_sites"]["4"]["tid_key_counts"]["4243"]["7"],
            2
        );
    }

    #[test]
    fn build_profiles_sorts_by_run_count_delta() {
        let rows = build_profile_rows(
            vec![
                ProfileBuildInput {
                    prog_id: 2,
                    run_cnt_delta: 2,
                    run_time_ns_delta: 20,
                    expected_sites: BTreeSet::from([1]),
                    sites: BTreeMap::from([(
                        1,
                        SiteCounters {
                            branch_count: 1,
                            not_taken: 1,
                            ..SiteCounters::default()
                        },
                    )]),
                    tail_collection_enabled: false,
                    tail_call_sites: BTreeMap::new(),
                },
                ProfileBuildInput {
                    prog_id: 1,
                    run_cnt_delta: 20,
                    run_time_ns_delta: 100,
                    expected_sites: BTreeSet::from([1]),
                    sites: BTreeMap::from([(
                        1,
                        SiteCounters {
                            branch_count: 1,
                            not_taken: 1,
                            ..SiteCounters::default()
                        },
                    )]),
                    tail_collection_enabled: false,
                    tail_call_sites: BTreeMap::new(),
                },
            ],
            100,
        )
        .unwrap();

        assert_eq!(rows[0].prog_id, 1);
        assert_eq!(rows[0].run_cnt_delta, 20);
    }

    #[test]
    fn build_profiles_requires_direction_for_every_branch_sample() {
        let err = build_profile_rows(
            vec![ProfileBuildInput {
                prog_id: 7,
                run_cnt_delta: 4,
                run_time_ns_delta: 80,
                expected_sites: BTreeSet::from([2]),
                sites: BTreeMap::from([(
                    2,
                    SiteCounters {
                        branch_count: 3,
                        taken: 1,
                        not_taken: 1,
                        ..SiteCounters::default()
                    },
                )]),
                tail_collection_enabled: false,
                tail_call_sites: BTreeMap::new(),
            }],
            250,
        )
        .unwrap_err();

        assert!(err.to_string().contains("taken+not_taken"));
    }

    #[test]
    fn build_profiles_allows_empty_profile_for_no_observed_branches() {
        let rows = build_profile_rows(
            vec![ProfileBuildInput {
                prog_id: 7,
                run_cnt_delta: 4,
                run_time_ns_delta: 80,
                expected_sites: BTreeSet::new(),
                sites: BTreeMap::new(),
                tail_collection_enabled: false,
                tail_call_sites: BTreeMap::new(),
            }],
            250,
        )
        .unwrap();

        assert_eq!(rows[0].prog_id, 7);
        assert_eq!(rows[0].branch_instructions, 0);
        assert_eq!(rows[0].branch_miss_rate, 0.0);
        assert!(rows[0].per_site.is_empty());
    }

    #[test]
    fn build_profiles_serializes_zero_for_unobserved_candidate_site() {
        let rows = build_profile_rows(
            vec![ProfileBuildInput {
                prog_id: 7,
                run_cnt_delta: 4,
                run_time_ns_delta: 80,
                expected_sites: BTreeSet::from([42]),
                sites: BTreeMap::new(),
                tail_collection_enabled: false,
                tail_call_sites: BTreeMap::new(),
            }],
            250,
        )
        .unwrap();

        let site = rows[0].per_site.get("42").unwrap();
        assert_eq!(site.branch_count, 0);
        assert_eq!(site.branch_misses, 0);
        assert_eq!(site.miss_rate, 0.0);
        assert_eq!(site.taken, 0);
        assert_eq!(site.not_taken, 0);
    }

    #[test]
    fn parse_prog_ids_deduplicates_and_rejects_empty() {
        assert_eq!(parse_prog_ids("7, 8,7").unwrap(), vec![7, 8]);
        assert!(parse_prog_ids(" , ").is_err());
        assert!(parse_prog_ids("0").is_err());
    }

    #[test]
    fn stats_delta_rejects_counter_regression() {
        let before = ProgStats {
            run_cnt: 10,
            run_time_ns: 100,
        };
        let after = ProgStats {
            run_cnt: 9,
            run_time_ns: 110,
        };

        let err = stats_delta(3, &before, &after).unwrap_err();

        assert!(err.to_string().contains("run_cnt"));
    }
}
