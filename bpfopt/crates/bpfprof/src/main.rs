// SPDX-License-Identifier: MIT
//! bpfprof CLI entry point.
//!
//! Per-site profiling uses a fexit sidecar BPF program that calls
//! `bpf_get_branch_snapshot()` and streams hardware LBR records through a
//! ringbuf. Missing helper support, missing JIT line metadata, missing LBR
//! events, or missing per-site data are hard errors.

use std::cell::RefCell;
use std::collections::BTreeMap;
use std::fs;
use std::io::{self, Write};
use std::os::fd::{AsFd, OwnedFd};
use std::path::{Path, PathBuf};
use std::process::ExitCode;
use std::rc::Rc;
use std::time::{Duration, Instant};

use anyhow::{anyhow, bail, Context, Result};
use clap::Parser;
use iced_x86::{Decoder, DecoderOptions, FlowControl};
use serde::Serialize;

const RINGBUF_BYTES: u32 = 1 << 20;
const POLL_SLICE: Duration = Duration::from_millis(50);
const EVENT_PROG_ID_OFFSET: usize = 0;
const EVENT_SNAPSHOT_RET_OFFSET: usize = 8;
const EVENT_BRANCHES_OFFSET: usize = kernel_sys::BRANCH_SNAPSHOT_EVENT_HEADER_SIZE;

#[derive(Parser, Debug)]
#[command(name = "bpfprof", version, about = "Profile live BPF programs")]
struct Cli {
    /// Profile one live BPF program ID.
    #[arg(long, conflicts_with = "all", value_name = "N")]
    prog_id: Option<u32>,
    /// Profile all live BPF programs.
    #[arg(long)]
    all: bool,
    /// Collect real per-site branch profile data using bpf_get_branch_snapshot LBR.
    #[arg(long)]
    per_site: bool,
    /// Sampling window, such as 500ms, 1s, or 250ms.
    #[arg(long, value_parser = parse_duration, value_name = "TIME")]
    duration: Duration,
    /// Output profile JSON file for --prog-id, or JSON array for --all.
    #[arg(long, value_name = "FILE")]
    output: Option<PathBuf>,
    /// Output directory for --all; writes one <prog_id>.json per program.
    #[arg(long, value_name = "DIR")]
    output_dir: Option<PathBuf>,
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
}

#[derive(Clone, Debug, Serialize, PartialEq)]
struct PerSiteProfile {
    branch_count: u64,
    branch_misses: u64,
    miss_rate: f64,
    taken: u64,
    not_taken: u64,
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
    snapshot_events: u64,
    branch_entries: u64,
    mapped_entries: u64,
    sites: BTreeMap<usize, SiteCounters>,
}

#[derive(Clone, Debug)]
struct JitPcMap {
    ranges: Vec<JitFuncRange>,
    lines: Vec<JitPcLineSpan>,
}

#[derive(Clone, Debug, PartialEq, Eq)]
struct JitPcLineSpan {
    insn_off: u32,
    jited_addr: u64,
    branches: Vec<BpfBranchSite>,
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
struct BpfBranchSite {
    pc: usize,
    native_ip: Option<u64>,
    fallthrough_pc: Option<usize>,
    taken_target_pc: Option<usize>,
}

#[derive(Clone, Copy, Debug)]
struct JitFuncRange {
    start_addr: u64,
    end_addr: u64,
    image_offset: usize,
}

struct TargetProfiler {
    target: Target,
    _ringbuf_fd: OwnedFd,
    _sidecar: kernel_sys::BranchSnapshotSidecar,
    ringbuf: kernel_sys::RingBuffer<'static>,
    samples: Rc<RefCell<TargetSamples>>,
    callback_error: Rc<RefCell<Option<String>>>,
}

struct LbrPerfEvents {
    fds: Vec<OwnedFd>,
}

struct ProfileBuildInput {
    prog_id: u32,
    run_cnt_delta: u64,
    run_time_ns_delta: u64,
    snapshot_events: u64,
    branch_entries: u64,
    mapped_entries: u64,
    sites: BTreeMap<usize, SiteCounters>,
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
    if targets.is_empty() {
        return write_empty_outputs(&cli);
    }

    let _stats_fd = kernel_sys::enable_stats(kernel_sys::BPF_STATS_RUN_TIME)
        .context("BPF_ENABLE_STATS(BPF_STATS_RUN_TIME)")?;
    let profilers = targets
        .into_iter()
        .map(TargetProfiler::attach)
        .collect::<Result<Vec<_>>>()?;
    let lbr_events = LbrPerfEvents::open()?;
    lbr_events.reset_and_enable()?;
    let before = read_snapshots(&profilers)?;
    collect_lbr_samples(cli.duration, &profilers)?;
    lbr_events.disable()?;
    drain_ring_buffers(&profilers)?;
    let after = read_snapshots(&profilers)?;

    let duration_ms = duration_ms(cli.duration)?;
    let profiles = build_profiles(&cli, profilers, &before, &after, duration_ms)?;
    write_profiles(&cli, &profiles)?;
    Ok(())
}

fn validate_cli(cli: &Cli) -> Result<()> {
    if cli.prog_id.is_none() && !cli.all {
        bail!("one of --prog-id N or --all is required");
    }
    if !cli.per_site {
        bail!("bpfprof requires --per-site; program-level-only PMU output has been removed");
    }
    if cli.duration.is_zero() {
        bail!("--duration must be greater than zero");
    }
    if cli.output_dir.is_some() && !cli.all {
        bail!("--output-dir is only valid with --all");
    }
    if cli.all && cli.output.is_some() && cli.output_dir.is_some() {
        bail!("choose only one of --output or --output-dir with --all");
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

fn open_target(prog_id: u32) -> Result<Target> {
    let fd = kernel_sys::prog_get_fd_by_id(prog_id)
        .with_context(|| format!("open BPF program id {prog_id}"))?;
    Ok(Target { prog_id, fd })
}

impl TargetProfiler {
    fn attach(target: Target) -> Result<Self> {
        let target_func_btf_id = kernel_sys::prog_main_func_btf_id(target.fd.as_fd())
            .with_context(|| format!("read func_info for BPF program id {}", target.prog_id))?;
        let pc_map = JitPcMap::from_prog(target.fd.as_fd())
            .with_context(|| format!("read JIT PC map for BPF program id {}", target.prog_id))?;
        let ringbuf_fd = kernel_sys::create_ringbuf_map("bpfprof_lbr_rb", RINGBUF_BYTES)
            .with_context(|| format!("create LBR ringbuf for BPF program id {}", target.prog_id))?;
        let mut log_buf = vec![0u8; 1 << 20];
        let sidecar = kernel_sys::attach_branch_snapshot_sidecar(
            target.fd.as_fd(),
            target_func_btf_id,
            ringbuf_fd.as_fd(),
            target.prog_id,
            Some(&mut log_buf),
        )
        .with_context(|| {
            format!(
                "attach bpf_get_branch_snapshot sidecar to BPF program id {}",
                target.prog_id
            )
        })?;

        let samples = Rc::new(RefCell::new(TargetSamples::default()));
        let callback_error = Rc::new(RefCell::new(None));
        let samples_for_cb = Rc::clone(&samples);
        let error_for_cb = Rc::clone(&callback_error);
        let map_for_cb = pc_map.clone();
        let prog_id = target.prog_id;
        let ringbuf = kernel_sys::RingBuffer::new(ringbuf_fd.as_fd(), move |sample| {
            match process_branch_snapshot_sample(
                sample,
                prog_id,
                &map_for_cb,
                &mut samples_for_cb.borrow_mut(),
            ) {
                Ok(()) => 0,
                Err(err) => {
                    *error_for_cb.borrow_mut() = Some(format!("{err:#}"));
                    -libc::EINVAL
                }
            }
        })
        .with_context(|| {
            format!(
                "open ringbuf consumer for BPF program id {}",
                target.prog_id
            )
        })?;

        Ok(Self {
            target,
            _ringbuf_fd: ringbuf_fd,
            _sidecar: sidecar,
            ringbuf,
            samples,
            callback_error,
        })
    }

    fn check_callback_error(&self) -> Result<()> {
        if let Some(err) = self.callback_error.borrow().as_ref() {
            bail!(
                "parse LBR sample for BPF program id {}: {err}",
                self.target.prog_id
            );
        }
        Ok(())
    }
}

impl JitPcMap {
    fn from_prog(fd: std::os::fd::BorrowedFd<'_>) -> Result<Self> {
        let mut image_offset = 0usize;
        let ranges = kernel_sys::prog_jited_func_ranges(fd)?
            .into_iter()
            .map(|range| {
                let end_addr = range
                    .start_addr
                    .checked_add(range.byte_len as u64)
                    .ok_or_else(|| anyhow!("JIT function range address overflow"))?;
                let current_offset = image_offset;
                image_offset = image_offset
                    .checked_add(range.byte_len as usize)
                    .ok_or_else(|| anyhow!("JIT image offset overflow"))?;
                Ok(JitFuncRange {
                    start_addr: range.start_addr,
                    end_addr,
                    image_offset: current_offset,
                })
            })
            .collect::<Result<Vec<_>>>()?;
        let mut lines = kernel_sys::prog_jited_line_info(fd)?;
        let insns = kernel_sys::prog_xlated_insns(fd)?;
        let jited_image = kernel_sys::prog_jited_insns(fd)?;
        if image_offset != jited_image.len() {
            bail!(
                "JIT function lens total {} bytes but JIT image has {} bytes",
                image_offset,
                jited_image.len()
            );
        }
        if lines.is_empty() {
            bail!("target BPF program returned empty jited_line_info metadata");
        }
        lines.sort_by_key(|line| line.jited_addr);
        if lines[0].insn_off != 0 {
            bail!(
                "target BPF program jited_line_info starts at insn {}, expected 0",
                lines[0].insn_off
            );
        }
        for line in &lines {
            if !ranges.iter().any(|range| range.contains(line.jited_addr)) {
                bail!(
                    "jited_line_info address 0x{:x} is outside target JIT function ranges",
                    line.jited_addr
                );
            }
        }
        let lines = build_line_spans(lines, &insns, &ranges, &jited_image)?;
        Ok(Self { ranges, lines })
    }

    fn pc_for_ip(&self, ip: u64) -> Option<usize> {
        if !self.ranges.iter().any(|range| range.contains(ip)) {
            return None;
        }
        let idx = self.lines.partition_point(|line| line.jited_addr <= ip);
        if idx == 0 {
            return None;
        }
        Some(self.lines[idx - 1].insn_off as usize)
    }

    fn branch_pc_for_ip(&self, ip: u64, to_ip: u64) -> Result<Option<usize>> {
        if !self.ranges.iter().any(|range| range.contains(ip)) {
            return Ok(None);
        }
        let idx = self.lines.partition_point(|line| line.jited_addr <= ip);
        if idx == 0 {
            return Ok(None);
        }
        let span = &self.lines[idx - 1];
        match span.branches.as_slice() {
            [branch] => Ok(Some(branch.pc)),
            [] => Err(anyhow!(
                "LBR branch address 0x{:x} maps to BPF line span at pc {} without a BPF branch instruction",
                ip,
                span.insn_off
            )),
            branches => {
                let native_matches = branches
                    .iter()
                    .filter(|branch| branch.native_ip == Some(ip))
                    .collect::<Vec<_>>();
                if let [branch] = native_matches.as_slice() {
                    return Ok(Some(branch.pc));
                }
                let to_pc = self.pc_for_ip(to_ip);
                let matches = branches
                    .iter()
                    .filter(|branch| branch.matches_target(to_pc))
                    .collect::<Vec<_>>();
                match matches.as_slice() {
                    [branch] => Ok(Some(branch.pc)),
                    [] => Err(anyhow!(
                        "LBR branch address 0x{:x} maps to BPF line span at pc {} but no branch target matches to_ip 0x{:x}",
                        ip,
                        span.insn_off,
                        to_ip
                    )),
                    _ => Err(anyhow!(
                        "LBR branch address 0x{:x} maps to BPF line span at pc {} but to_ip 0x{:x} does not select a unique BPF branch instruction",
                        ip,
                        span.insn_off,
                        to_ip
                    )),
                }
            }
        }
    }
}

impl BpfBranchSite {
    fn matches_target(&self, to_pc: Option<usize>) -> bool {
        self.fallthrough_pc == to_pc || self.taken_target_pc == to_pc
    }
}

fn build_line_spans(
    lines: Vec<kernel_sys::JitedLineInfo>,
    insns: &[kernel_sys::bpf_insn],
    ranges: &[JitFuncRange],
    jited_image: &[u8],
) -> Result<Vec<JitPcLineSpan>> {
    if insns.is_empty() {
        bail!("target BPF program returned empty translated bytecode");
    }

    let mut spans = Vec::with_capacity(lines.len());
    for (idx, line) in lines.iter().enumerate() {
        let start = line.insn_off as usize;
        if start >= insns.len() {
            bail!(
                "jited_line_info pc {} exceeds translated instruction count {}",
                start,
                insns.len()
            );
        }
        let end = lines
            .get(idx + 1)
            .map(|next| next.insn_off as usize)
            .unwrap_or(insns.len());
        if end <= start {
            bail!(
                "jited_line_info pc range is not strictly increasing: start={} end={}",
                start,
                end
            );
        }
        let mut branches = (start..end)
            .filter_map(|pc| bpf_branch_site(pc, &insns[pc]))
            .collect::<Vec<_>>();
        let native_branch_ips =
            native_branch_ips_for_span(line.jited_addr, lines.get(idx + 1), ranges, jited_image)?;
        if branches.len() == native_branch_ips.len() {
            for (branch, native_ip) in branches.iter_mut().zip(native_branch_ips) {
                branch.native_ip = Some(native_ip);
            }
        }
        spans.push(JitPcLineSpan {
            insn_off: line.insn_off,
            jited_addr: line.jited_addr,
            branches,
        });
    }
    Ok(spans)
}

fn native_branch_ips_for_span(
    start_addr: u64,
    next_line: Option<&kernel_sys::JitedLineInfo>,
    ranges: &[JitFuncRange],
    jited_image: &[u8],
) -> Result<Vec<u64>> {
    let range = ranges
        .iter()
        .find(|range| range.contains(start_addr))
        .ok_or_else(|| anyhow!("jited_line_info address 0x{start_addr:x} has no JIT range"))?;
    let end_addr = match next_line {
        Some(next) if range.contains(next.jited_addr) => next.jited_addr,
        _ => range.end_addr,
    };
    if end_addr <= start_addr {
        bail!(
            "native JIT span is not strictly increasing: start=0x{:x} end=0x{:x}",
            start_addr,
            end_addr
        );
    }

    let start_offset = range
        .image_offset
        .checked_add((start_addr - range.start_addr) as usize)
        .ok_or_else(|| anyhow!("native JIT span start offset overflow"))?;
    let end_offset = range
        .image_offset
        .checked_add((end_addr - range.start_addr) as usize)
        .ok_or_else(|| anyhow!("native JIT span end offset overflow"))?;
    let bytes = jited_image
        .get(start_offset..end_offset)
        .ok_or_else(|| anyhow!("native JIT span is outside JIT image bytes"))?;

    let mut decoder = Decoder::with_ip(64, bytes, start_addr, DecoderOptions::NONE);
    let mut ips = Vec::new();
    while decoder.can_decode() {
        let instr = decoder.decode();
        if is_native_branch_flow(instr.flow_control()) {
            ips.push(instr.ip());
        }
    }
    Ok(ips)
}

fn is_native_branch_flow(flow: FlowControl) -> bool {
    matches!(
        flow,
        FlowControl::ConditionalBranch
            | FlowControl::UnconditionalBranch
            | FlowControl::IndirectBranch
            | FlowControl::Call
            | FlowControl::IndirectCall
            | FlowControl::Return
    )
}

fn bpf_branch_site(pc: usize, insn: &kernel_sys::bpf_insn) -> Option<BpfBranchSite> {
    let class = insn.code & 0x07;
    if class != kernel_sys::BPF_JMP as u8 && class != kernel_sys::BPF_JMP32 as u8 {
        return None;
    }
    let op = insn.code & 0xf0;
    if op == kernel_sys::BPF_JA as u8 {
        return Some(BpfBranchSite {
            pc,
            native_ip: None,
            fallthrough_pc: None,
            taken_target_pc: relative_branch_target(pc, insn.off),
        });
    }
    if op == kernel_sys::BPF_CALL as u8 || op == kernel_sys::BPF_EXIT as u8 {
        return Some(BpfBranchSite {
            pc,
            native_ip: None,
            fallthrough_pc: None,
            taken_target_pc: None,
        });
    }
    if is_conditional_bpf_branch_op(op) {
        return Some(BpfBranchSite {
            pc,
            native_ip: None,
            fallthrough_pc: pc.checked_add(1),
            taken_target_pc: relative_branch_target(pc, insn.off),
        });
    }
    None
}

fn relative_branch_target(pc: usize, off: i16) -> Option<usize> {
    let pc = i64::try_from(pc).ok()?;
    let target = pc.checked_add(1)?.checked_add(i64::from(off))?;
    usize::try_from(target).ok()
}

fn is_conditional_bpf_branch_op(op: u8) -> bool {
    op == kernel_sys::BPF_JEQ as u8
        || op == kernel_sys::BPF_JGT as u8
        || op == kernel_sys::BPF_JGE as u8
        || op == kernel_sys::BPF_JSET as u8
        || op == kernel_sys::BPF_JNE as u8
        || op == kernel_sys::BPF_JSGT as u8
        || op == kernel_sys::BPF_JSGE as u8
        || op == kernel_sys::BPF_JLT as u8
        || op == kernel_sys::BPF_JLE as u8
        || op == kernel_sys::BPF_JSLT as u8
        || op == kernel_sys::BPF_JSLE as u8
}

impl JitFuncRange {
    fn contains(&self, ip: u64) -> bool {
        self.start_addr <= ip && ip < self.end_addr
    }
}

impl LbrPerfEvents {
    fn open() -> Result<Self> {
        let cpus = online_cpus()?;
        let mut fds = Vec::with_capacity(cpus.len());
        for cpu in cpus {
            let mut attr = kernel_sys::perf_event_attr {
                type_: kernel_sys::PERF_TYPE_HARDWARE,
                size: std::mem::size_of::<kernel_sys::perf_event_attr>() as u32,
                config: kernel_sys::PERF_COUNT_HW_CPU_CYCLES as u64,
                sample_type: kernel_sys::PERF_SAMPLE_BRANCH_STACK as u64,
                branch_sample_type: (kernel_sys::PERF_SAMPLE_BRANCH_KERNEL
                    | kernel_sys::PERF_SAMPLE_BRANCH_ANY)
                    as u64,
                ..Default::default()
            };
            attr.set_disabled(1);
            attr.set_exclude_user(1);
            attr.set_exclude_hv(1);
            attr.__bindgen_anon_1.sample_period = 1;
            let fd = kernel_sys::perf_event_open(&mut attr, -1, cpu, -1, 0)
                .with_context(|| format!("open kernel LBR perf event on CPU {cpu}"))?;
            fds.push(fd);
        }
        Ok(Self { fds })
    }

    fn reset_and_enable(&self) -> Result<()> {
        for fd in &self.fds {
            kernel_sys::perf_event_ioctl(fd.as_fd(), kernel_sys::PerfEventCommand::Reset)
                .context("reset LBR perf event")?;
        }
        for fd in &self.fds {
            kernel_sys::perf_event_ioctl(fd.as_fd(), kernel_sys::PerfEventCommand::Enable)
                .context("enable LBR perf event")?;
        }
        Ok(())
    }

    fn disable(&self) -> Result<()> {
        for fd in &self.fds {
            kernel_sys::perf_event_ioctl(fd.as_fd(), kernel_sys::PerfEventCommand::Disable)
                .context("disable LBR perf event")?;
        }
        Ok(())
    }
}

fn online_cpus() -> Result<Vec<i32>> {
    let raw = fs::read_to_string("/sys/devices/system/cpu/online")
        .context("read /sys/devices/system/cpu/online")?;
    let mut cpus = Vec::new();
    for part in raw.trim().split(',') {
        if let Some((start, end)) = part.split_once('-') {
            let start = start
                .parse::<i32>()
                .with_context(|| format!("parse online CPU range start: {part}"))?;
            let end = end
                .parse::<i32>()
                .with_context(|| format!("parse online CPU range end: {part}"))?;
            if start > end {
                bail!("invalid online CPU range: {part}");
            }
            cpus.extend(start..=end);
        } else {
            cpus.push(
                part.parse::<i32>()
                    .with_context(|| format!("parse online CPU id: {part}"))?,
            );
        }
    }
    if cpus.is_empty() {
        bail!("no online CPUs found in /sys/devices/system/cpu/online");
    }
    Ok(cpus)
}

fn read_snapshots(profilers: &[TargetProfiler]) -> Result<BTreeMap<u32, ProgStats>> {
    let mut snapshots = BTreeMap::new();
    for profiler in profilers {
        let info =
            kernel_sys::obj_get_info_by_fd(profiler.target.fd.as_fd()).with_context(|| {
                format!("read stats for BPF program id {}", profiler.target.prog_id)
            })?;
        snapshots.insert(
            profiler.target.prog_id,
            ProgStats {
                run_cnt: info.run_cnt,
                run_time_ns: info.run_time_ns,
            },
        );
    }
    Ok(snapshots)
}

fn collect_lbr_samples(duration: Duration, profilers: &[TargetProfiler]) -> Result<()> {
    let start = Instant::now();
    loop {
        let elapsed = start.elapsed();
        if elapsed >= duration {
            break;
        }
        let remaining = duration - elapsed;
        let timeout = remaining.min(POLL_SLICE);
        poll_ring_buffers(profilers, timeout)?;
    }
    Ok(())
}

fn drain_ring_buffers(profilers: &[TargetProfiler]) -> Result<()> {
    for _ in 0..8 {
        poll_ring_buffers(profilers, Duration::from_millis(0))?;
    }
    Ok(())
}

fn poll_ring_buffers(profilers: &[TargetProfiler], timeout: Duration) -> Result<()> {
    for profiler in profilers {
        if let Err(err) = profiler.ringbuf.poll(timeout) {
            profiler.check_callback_error()?;
            return Err(err);
        }
        profiler.check_callback_error()?;
    }
    Ok(())
}

fn process_branch_snapshot_sample(
    sample: &[u8],
    expected_prog_id: u32,
    pc_map: &JitPcMap,
    samples: &mut TargetSamples,
) -> Result<()> {
    if sample.len() != kernel_sys::BRANCH_SNAPSHOT_EVENT_SIZE {
        bail!(
            "unexpected branch snapshot event size {}, expected {}",
            sample.len(),
            kernel_sys::BRANCH_SNAPSHOT_EVENT_SIZE
        );
    }
    let prog_id = read_u32(sample, EVENT_PROG_ID_OFFSET, "event.prog_id")?;
    if prog_id != expected_prog_id {
        bail!("branch snapshot prog_id {prog_id} does not match target {expected_prog_id}");
    }
    let snapshot_ret = read_i64(sample, EVENT_SNAPSHOT_RET_OFFSET, "event.snapshot_ret")?;
    if snapshot_ret < 0 {
        let errno = (-snapshot_ret)
            .try_into()
            .map_err(|_| anyhow!("bpf_get_branch_snapshot errno does not fit i32"))?;
        bail!(
            "bpf_get_branch_snapshot failed: {}",
            io::Error::from_raw_os_error(errno)
        );
    }
    let snapshot_bytes: usize = snapshot_ret
        .try_into()
        .map_err(|_| anyhow!("bpf_get_branch_snapshot byte count does not fit usize"))?;
    let max_branch_bytes =
        kernel_sys::BRANCH_SNAPSHOT_MAX_ENTRIES * kernel_sys::BRANCH_SNAPSHOT_ENTRY_SIZE;
    if snapshot_bytes > max_branch_bytes {
        bail!(
            "bpf_get_branch_snapshot returned {} bytes, ringbuf event holds {}",
            snapshot_bytes,
            max_branch_bytes
        );
    }
    if !snapshot_bytes.is_multiple_of(kernel_sys::BRANCH_SNAPSHOT_ENTRY_SIZE) {
        bail!(
            "bpf_get_branch_snapshot returned non-entry-aligned byte count {}",
            snapshot_bytes
        );
    }

    samples.snapshot_events += 1;
    let entry_count = snapshot_bytes / kernel_sys::BRANCH_SNAPSHOT_ENTRY_SIZE;
    samples.branch_entries += entry_count as u64;
    for idx in 0..entry_count {
        let base = EVENT_BRANCHES_OFFSET + idx * kernel_sys::BRANCH_SNAPSHOT_ENTRY_SIZE;
        let from_ip = read_u64(sample, base, "branch.from")?;
        let to_ip = read_u64(sample, base + 8, "branch.to")?;
        let flags = read_u64(sample, base + 16, "branch.flags")?;
        let Some(from_pc) = pc_map.branch_pc_for_ip(from_ip, to_ip)? else {
            continue;
        };
        samples.mapped_entries += 1;
        let counter = samples.sites.entry(from_pc).or_default();
        counter.branch_count += 1;
        if flags & 1 != 0 {
            counter.branch_misses += 1;
        }
        if let Some(to_pc) = pc_map.pc_for_ip(to_ip) {
            if to_pc == from_pc + 1 {
                counter.not_taken += 1;
            } else {
                counter.taken += 1;
            }
        }
    }
    Ok(())
}

fn build_profiles(
    cli: &Cli,
    profilers: Vec<TargetProfiler>,
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
        let samples = profiler.samples.borrow();
        if cli.all && delta.run_cnt == 0 && samples.sites.is_empty() {
            continue;
        }
        inputs.push(ProfileBuildInput {
            prog_id: profiler.target.prog_id,
            run_cnt_delta: delta.run_cnt,
            run_time_ns_delta: delta.run_time_ns,
            snapshot_events: samples.snapshot_events,
            branch_entries: samples.branch_entries,
            mapped_entries: samples.mapped_entries,
            sites: samples.sites.clone(),
        });
    }
    build_profile_rows(inputs, duration_ms)
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

fn build_profile_rows(
    inputs: Vec<ProfileBuildInput>,
    duration_ms: u64,
) -> Result<Vec<ProfileJson>> {
    let mut rows = Vec::with_capacity(inputs.len());
    for input in inputs {
        let branch_instructions = input
            .sites
            .values()
            .map(|site| site.branch_count)
            .sum::<u64>();
        if branch_instructions == 0 {
            bail!(
                "no real per-site branch profile data captured for BPF program id {} (snapshot_events={}, branch_entries={}, mapped_entries={})",
                input.prog_id,
                input.snapshot_events,
                input.branch_entries,
                input.mapped_entries
            );
        }
        let branch_misses = input
            .sites
            .values()
            .map(|site| site.branch_misses)
            .sum::<u64>();
        let mut per_site = BTreeMap::new();
        for (pc, site) in input.sites {
            if site.branch_count == 0 {
                bail!(
                    "site {pc} in BPF program id {} has zero branch_count",
                    input.prog_id
                );
            }
            let miss_rate = site.branch_misses as f64 / site.branch_count as f64;
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
        rows.push(ProfileJson {
            prog_id: input.prog_id,
            duration_ms,
            run_cnt_delta: input.run_cnt_delta,
            run_time_ns_delta: input.run_time_ns_delta,
            branch_miss_rate: branch_misses as f64 / branch_instructions as f64,
            branch_misses,
            branch_instructions,
            per_site,
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
    if cli.all {
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

fn read_i64(bytes: &[u8], offset: usize, label: &str) -> Result<i64> {
    let end = offset
        .checked_add(std::mem::size_of::<i64>())
        .ok_or_else(|| anyhow!("{label} offset overflow"))?;
    let raw = bytes
        .get(offset..end)
        .ok_or_else(|| anyhow!("{label} is truncated at offset {offset}"))?;
    let raw: [u8; 8] = raw
        .try_into()
        .map_err(|_| anyhow!("{label} slice length changed after bounds check"))?;
    Ok(i64::from_ne_bytes(raw))
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

    fn test_insn(code: u32) -> kernel_sys::bpf_insn {
        kernel_sys::bpf_insn {
            code: code as u8,
            ..Default::default()
        }
    }

    fn sample_event(prog_id: u32, branches: &[(u64, u64, u64)]) -> Vec<u8> {
        let mut sample = vec![0u8; kernel_sys::BRANCH_SNAPSHOT_EVENT_SIZE];
        sample[EVENT_PROG_ID_OFFSET..EVENT_PROG_ID_OFFSET + 4]
            .copy_from_slice(&prog_id.to_ne_bytes());
        let snapshot_ret = (branches.len() * kernel_sys::BRANCH_SNAPSHOT_ENTRY_SIZE) as i64;
        sample[EVENT_SNAPSHOT_RET_OFFSET..EVENT_SNAPSHOT_RET_OFFSET + 8]
            .copy_from_slice(&snapshot_ret.to_ne_bytes());
        for (idx, (from, to, flags)) in branches.iter().enumerate() {
            let base = EVENT_BRANCHES_OFFSET + idx * kernel_sys::BRANCH_SNAPSHOT_ENTRY_SIZE;
            sample[base..base + 8].copy_from_slice(&from.to_ne_bytes());
            sample[base + 8..base + 16].copy_from_slice(&to.to_ne_bytes());
            sample[base + 16..base + 24].copy_from_slice(&flags.to_ne_bytes());
        }
        sample
    }

    fn fake_pc_map() -> JitPcMap {
        JitPcMap {
            ranges: vec![JitFuncRange {
                start_addr: 0x1000,
                end_addr: 0x1400,
                image_offset: 0,
            }],
            lines: vec![
                JitPcLineSpan {
                    insn_off: 10,
                    jited_addr: 0x1100,
                    branches: vec![BpfBranchSite {
                        pc: 10,
                        native_ip: Some(0x1104),
                        fallthrough_pc: Some(11),
                        taken_target_pc: Some(20),
                    }],
                },
                JitPcLineSpan {
                    insn_off: 11,
                    jited_addr: 0x1110,
                    branches: vec![BpfBranchSite {
                        pc: 11,
                        native_ip: Some(0x1110),
                        fallthrough_pc: Some(12),
                        taken_target_pc: Some(20),
                    }],
                },
                JitPcLineSpan {
                    insn_off: 20,
                    jited_addr: 0x1200,
                    branches: vec![BpfBranchSite {
                        pc: 20,
                        native_ip: Some(0x1200),
                        fallthrough_pc: None,
                        taken_target_pc: None,
                    }],
                },
            ],
        }
    }

    #[test]
    fn lbr_sample_attributes_misses_and_direction_to_bpf_pc() {
        let sample = sample_event(
            7,
            &[
                (0x1104, 0x1110, 0),
                (0x1108, 0x1200, 1),
                (0x1500, 0x1200, 1),
            ],
        );
        let mut samples = TargetSamples::default();

        process_branch_snapshot_sample(&sample, 7, &fake_pc_map(), &mut samples).unwrap();

        assert_eq!(samples.snapshot_events, 1);
        let site = samples.sites.get(&10).unwrap();
        assert_eq!(site.branch_count, 2);
        assert_eq!(site.branch_misses, 1);
        assert_eq!(site.not_taken, 1);
        assert_eq!(site.taken, 1);
    }

    #[test]
    fn jit_span_maps_native_branch_to_unique_bpf_branch_pc() {
        let lines = vec![
            kernel_sys::JitedLineInfo {
                insn_off: 0,
                jited_addr: 0x1000,
            },
            kernel_sys::JitedLineInfo {
                insn_off: 4,
                jited_addr: 0x1004,
            },
        ];
        let ranges = vec![JitFuncRange {
            start_addr: 0x1000,
            end_addr: 0x1005,
            image_offset: 0,
        }];
        let jited_image = vec![0x90, 0x90, 0xeb, 0x00, 0xc3];
        let insns = vec![
            test_insn(kernel_sys::BPF_ALU64 | kernel_sys::BPF_MOV | kernel_sys::BPF_K),
            test_insn(kernel_sys::BPF_ALU64 | kernel_sys::BPF_ADD | kernel_sys::BPF_K),
            test_insn(kernel_sys::BPF_JMP | kernel_sys::BPF_JA),
            test_insn(kernel_sys::BPF_ALU64 | kernel_sys::BPF_MOV | kernel_sys::BPF_K),
            test_insn(kernel_sys::BPF_JMP | kernel_sys::BPF_EXIT),
        ];

        let spans = build_line_spans(lines, &insns, &ranges, &jited_image).unwrap();

        assert_eq!(spans[0].branches[0].pc, 2);
        assert_eq!(spans[0].branches[0].native_ip, Some(0x1002));
        assert_eq!(spans[1].branches[0].pc, 4);
        assert_eq!(spans[1].branches[0].native_ip, Some(0x1004));
    }

    #[test]
    fn lbr_sample_reports_helper_failure() {
        let mut sample = vec![0u8; kernel_sys::BRANCH_SNAPSHOT_EVENT_SIZE];
        sample[EVENT_PROG_ID_OFFSET..EVENT_PROG_ID_OFFSET + 4].copy_from_slice(&7u32.to_ne_bytes());
        sample[EVENT_SNAPSHOT_RET_OFFSET..EVENT_SNAPSHOT_RET_OFFSET + 8]
            .copy_from_slice(&(-libc::ENOENT as i64).to_ne_bytes());
        let mut samples = TargetSamples::default();

        let err =
            process_branch_snapshot_sample(&sample, 7, &fake_pc_map(), &mut samples).unwrap_err();

        assert!(err.to_string().contains("bpf_get_branch_snapshot failed"));
    }

    #[test]
    fn profile_json_serializes_required_branch_metrics() {
        let rows = build_profile_rows(
            vec![ProfileBuildInput {
                prog_id: 123,
                run_cnt_delta: 10,
                run_time_ns_delta: 2_000,
                snapshot_events: 1,
                branch_entries: 1,
                mapped_entries: 1,
                sites: BTreeMap::from([(
                    42,
                    SiteCounters {
                        branch_count: 10,
                        branch_misses: 2,
                        taken: 7,
                        not_taken: 3,
                    },
                )]),
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
    fn build_profiles_sorts_by_run_count_delta() {
        let rows = build_profile_rows(
            vec![
                ProfileBuildInput {
                    prog_id: 2,
                    run_cnt_delta: 2,
                    run_time_ns_delta: 20,
                    snapshot_events: 1,
                    branch_entries: 1,
                    mapped_entries: 1,
                    sites: BTreeMap::from([(
                        1,
                        SiteCounters {
                            branch_count: 1,
                            ..SiteCounters::default()
                        },
                    )]),
                },
                ProfileBuildInput {
                    prog_id: 1,
                    run_cnt_delta: 20,
                    run_time_ns_delta: 100,
                    snapshot_events: 1,
                    branch_entries: 1,
                    mapped_entries: 1,
                    sites: BTreeMap::from([(
                        1,
                        SiteCounters {
                            branch_count: 1,
                            ..SiteCounters::default()
                        },
                    )]),
                },
            ],
            100,
        )
        .unwrap();

        assert_eq!(rows[0].prog_id, 1);
        assert_eq!(rows[0].run_cnt_delta, 20);
    }

    #[test]
    fn build_profiles_requires_real_per_site_data() {
        let err = build_profile_rows(
            vec![ProfileBuildInput {
                prog_id: 7,
                run_cnt_delta: 4,
                run_time_ns_delta: 80,
                snapshot_events: 1,
                branch_entries: 1,
                mapped_entries: 0,
                sites: BTreeMap::new(),
            }],
            250,
        )
        .unwrap_err();

        assert!(err
            .to_string()
            .contains("no real per-site branch profile data"));
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
