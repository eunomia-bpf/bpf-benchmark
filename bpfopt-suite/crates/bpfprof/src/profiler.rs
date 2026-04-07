// SPDX-License-Identifier: MIT
//! Runtime profiler helpers backed by `bpf_prog_info` and optional PMU counters.
//!
//! This is the PGO data source for the daemon:
//! - **Program-level**: poll `run_cnt` / `run_time_ns`, compute deltas, rank
//!   programs by hotness (run_cnt during observation window).
//! - **Program-level PMU**: use `perf_event_open` to collect branch miss and
//!   branch instruction counters during the same observation window.

use std::collections::{BTreeMap, HashMap};
use std::ffi::CStr;
use std::os::fd::{AsRawFd, OwnedFd};
use std::sync::{mpsc, Arc, Mutex};
use std::thread;
use std::time::{Duration, Instant, SystemTime, UNIX_EPOCH};

use anyhow::{Context, Result};
use serde::{Deserialize, Serialize};

use crate::bpf;
use crate::pass::ProfilingData;

#[derive(Clone, Debug, Default, PartialEq)]
pub struct ProgStats {
    pub run_cnt: u64,
    pub run_time_ns: u64,
    pub avg_ns: Option<f64>,
}

impl ProgStats {
    fn from_totals(run_cnt: u64, run_time_ns: u64) -> Self {
        Self {
            run_cnt,
            run_time_ns,
            avg_ns: avg_ns(run_time_ns, run_cnt),
        }
    }
}

#[derive(Clone, Debug)]
pub struct ProgStatsSnapshot {
    pub prog_id: u32,
    pub captured_at: Instant,
    pub stats: ProgStats,
}

#[derive(Clone, Debug)]
pub struct ProgStatsDelta {
    pub prog_id: u32,
    pub elapsed: Duration,
    /// Snapshot before the observation (used by tests and diagnostic tools).
    #[allow(dead_code)]
    pub before: ProgStats,
    pub after: ProgStats,
    pub run_cnt_delta: u64,
    pub run_time_ns_delta: u64,
    pub avg_ns: Option<f64>,
}

impl ProgStatsDelta {
    pub fn from_snapshots(before: &ProgStatsSnapshot, after: &ProgStatsSnapshot) -> Self {
        let run_cnt_delta = after.stats.run_cnt.saturating_sub(before.stats.run_cnt);
        let run_time_ns_delta = after
            .stats
            .run_time_ns
            .saturating_sub(before.stats.run_time_ns);

        Self {
            prog_id: after.prog_id,
            elapsed: after
                .captured_at
                .saturating_duration_since(before.captured_at),
            before: before.stats.clone(),
            after: after.stats.clone(),
            run_cnt_delta,
            run_time_ns_delta,
            avg_ns: avg_ns(run_time_ns_delta, run_cnt_delta),
        }
    }
}

/// Program-level PGO analysis — activity metrics from observation window.
#[derive(Clone, Debug)]
pub struct PgoAnalysis {
    pub prog_id: u32,
    #[allow(dead_code)]
    pub total: ProgStats,
    pub delta_run_cnt: u64,
    pub delta_run_time_ns: u64,
    pub delta_avg_ns: Option<f64>,
}

impl PgoAnalysis {
    pub fn from_delta(delta: &ProgStatsDelta) -> Self {
        Self {
            prog_id: delta.prog_id,
            total: delta.after.clone(),
            delta_run_cnt: delta.run_cnt_delta,
            delta_run_time_ns: delta.run_time_ns_delta,
            delta_avg_ns: delta.avg_ns,
        }
    }

    /// Whether this program is considered "hot" (actively running).
    /// A program is hot if it accumulated any runs during the observation window.
    pub fn is_hot(&self) -> bool {
        self.delta_run_cnt > 0
    }

    /// Hotness score: invocations per second during the observation window.
    /// Returns 0.0 if no time elapsed. Used by HotnessRanking.
    pub fn hotness_score(&self, elapsed: Duration) -> f64 {
        let secs = elapsed.as_secs_f64();
        if secs <= 0.0 {
            return 0.0;
        }
        self.delta_run_cnt as f64 / secs
    }
}

/// Program hotness ranking — sorts programs by activity level.
/// Kept for future multi-program PGO flows.
#[derive(Clone, Debug)]

pub struct HotnessRanking {
    /// Programs ranked by descending hotness (most active first).
    pub ranked: Vec<PgoAnalysis>,
}

impl HotnessRanking {
    /// Build a hotness ranking from a set of PGO analyses and their observation window.
    pub fn from_analyses(analyses: Vec<PgoAnalysis>, observation_window: Duration) -> Self {
        let mut ranked = analyses;
        ranked.sort_by(|a, b| {
            b.hotness_score(observation_window)
                .partial_cmp(&a.hotness_score(observation_window))
                .unwrap_or(std::cmp::Ordering::Equal)
                .then_with(|| b.delta_run_time_ns.cmp(&a.delta_run_time_ns))
                .then_with(|| {
                    b.delta_avg_ns
                        .partial_cmp(&a.delta_avg_ns)
                        .unwrap_or(std::cmp::Ordering::Equal)
                })
                .then_with(|| a.prog_id.cmp(&b.prog_id))
        });
        Self { ranked }
    }

    /// Return only programs that are actively running.
    #[allow(dead_code)]
    pub fn hot_programs(&self) -> Vec<&PgoAnalysis> {
        self.ranked.iter().filter(|a| a.is_hot()).collect()
    }
}

#[derive(Clone, Debug, Default, PartialEq, Serialize, Deserialize)]
pub struct ProgramProfile {
    pub run_cnt: u64,
    pub run_time_ns: u64,
    pub avg_ns: Option<f64>,
    pub branch_miss_rate: Option<f64>,
}

impl ProgramProfile {
    fn add_delta(&mut self, delta: &ProgStatsDelta) {
        self.run_cnt = self.run_cnt.saturating_add(delta.run_cnt_delta);
        self.run_time_ns = self.run_time_ns.saturating_add(delta.run_time_ns_delta);
        self.avg_ns = avg_ns(self.run_time_ns, self.run_cnt);
    }

    fn to_profiling_data(&self) -> ProfilingData {
        ProfilingData {
            branch_profiles: HashMap::new(),
            branch_miss_rate: self.branch_miss_rate,
        }
    }
}

#[derive(Clone, Debug, PartialEq, Serialize, Deserialize)]
pub struct ProfileSnapshot {
    pub version: u32,
    pub collected_at: String,
    pub duration_ms: u64,
    pub programs: BTreeMap<String, ProgramProfile>,
}

impl ProfileSnapshot {
    pub const VERSION: u32 = 1;

    pub fn programs_profiled(&self) -> usize {
        self.programs.len()
    }

    pub fn summary(&self) -> ProfileSummary {
        ProfileSummary {
            programs_profiled: self.programs_profiled(),
            duration_ms: self.duration_ms,
        }
    }

    pub fn program_profile(&self, prog_id: u32) -> Option<&ProgramProfile> {
        self.programs.get(&prog_id.to_string())
    }

    pub fn profiling_data_for(&self, prog_id: u32) -> Option<ProfilingData> {
        self.program_profile(prog_id)
            .map(ProgramProfile::to_profiling_data)
    }

    pub fn hotness_ranking(&self) -> Result<HotnessRanking> {
        let observation_window = Duration::from_millis(self.duration_ms.max(1));
        let mut analyses = Vec::with_capacity(self.programs.len());
        for (prog_id, profile) in &self.programs {
            let prog_id = prog_id
                .parse::<u32>()
                .with_context(|| format!("parse profiled program ID '{}'", prog_id))?;
            analyses.push(PgoAnalysis {
                prog_id,
                total: ProgStats {
                    run_cnt: profile.run_cnt,
                    run_time_ns: profile.run_time_ns,
                    avg_ns: profile.avg_ns,
                },
                delta_run_cnt: profile.run_cnt,
                delta_run_time_ns: profile.run_time_ns,
                delta_avg_ns: profile.avg_ns,
            });
        }
        Ok(HotnessRanking::from_analyses(analyses, observation_window))
    }

    pub fn save_to_path(&self, path: &std::path::Path) -> Result<()> {
        let json = serde_json::to_vec_pretty(self).context("serialize profile snapshot")?;
        std::fs::write(path, json)
            .with_context(|| format!("write profile snapshot to {}", path.display()))
    }

    pub fn load_from_path(path: &std::path::Path) -> Result<Self> {
        let raw = std::fs::read(path)
            .with_context(|| format!("read profile snapshot from {}", path.display()))?;
        let snapshot: Self = serde_json::from_slice(&raw).context("parse profile snapshot JSON")?;
        if snapshot.version != Self::VERSION {
            anyhow::bail!(
                "unsupported profile snapshot version {}; expected {}",
                snapshot.version,
                Self::VERSION
            );
        }
        Ok(snapshot)
    }
}

#[derive(Clone, Copy, Debug, Eq, PartialEq)]
pub struct ProfileSummary {
    pub programs_profiled: usize,
    pub duration_ms: u64,
}

#[derive(Debug)]
pub struct ProfilerSession {
    shared: Arc<Mutex<SessionState>>,
    stop_tx: Option<mpsc::Sender<()>>,
    handle: Option<thread::JoinHandle<Result<ProfileSnapshot>>>,
}

#[derive(Debug)]
struct SessionState {
    started_at: Instant,
    collected_at: SystemTime,
    programs: HashMap<u32, ProgramProfile>,
    last_snapshots: HashMap<u32, ProgStatsSnapshot>,
    current_branch_miss_rate: Option<f64>,
    fatal_error: Option<String>,
}

impl SessionState {
    fn new() -> Self {
        Self {
            started_at: Instant::now(),
            collected_at: SystemTime::now(),
            programs: HashMap::new(),
            last_snapshots: HashMap::new(),
            current_branch_miss_rate: None,
            fatal_error: None,
        }
    }

    fn snapshot(&self) -> Result<ProfileSnapshot> {
        if let Some(message) = &self.fatal_error {
            anyhow::bail!("{message}");
        }

        let mut programs = BTreeMap::new();
        for (prog_id, profile) in &self.programs {
            let mut program = profile.clone();
            if program.branch_miss_rate.is_none() {
                program.branch_miss_rate = self.current_branch_miss_rate;
            }
            programs.insert(prog_id.to_string(), program);
        }

        Ok(ProfileSnapshot {
            version: ProfileSnapshot::VERSION,
            collected_at: format_system_time_rfc3339(self.collected_at)?,
            duration_ms: self.started_at.elapsed().as_millis() as u64,
            programs,
        })
    }
}

impl ProfilerSession {
    pub fn start(interval: Duration) -> Result<Self> {
        if interval.is_zero() {
            anyhow::bail!("profile interval must be greater than zero");
        }
        if !bpf_stats_enabled()? {
            anyhow::bail!(
                "profile-start requires kernel.bpf_stats_enabled=1; enable it before starting profiling"
            );
        }

        let mut initial_state = SessionState::new();
        initial_state.last_snapshots = read_all_prog_stats()?;

        let shared = Arc::new(Mutex::new(initial_state));
        let (stop_tx, stop_rx) = mpsc::channel();
        let shared_for_thread = Arc::clone(&shared);
        let handle = thread::Builder::new()
            .name("bpfrejit-profiler".to_string())
            .spawn(move || run_profiler_thread(shared_for_thread, stop_rx, interval))
            .context("spawn profiling thread")?;

        Ok(Self {
            shared,
            stop_tx: Some(stop_tx),
            handle: Some(handle),
        })
    }

    pub fn snapshot(&self) -> Result<ProfileSnapshot> {
        let state = self
            .shared
            .lock()
            .map_err(|_| anyhow::anyhow!("profiling state lock poisoned"))?;
        state.snapshot()
    }

    pub fn stop(mut self) -> Result<ProfileSnapshot> {
        if let Some(stop_tx) = self.stop_tx.take() {
            stop_tx
                .send(())
                .context("signal profiling thread to stop")?;
        }

        let handle = self
            .handle
            .take()
            .ok_or_else(|| anyhow::anyhow!("profiling thread handle missing"))?;

        match handle.join() {
            Ok(result) => result,
            Err(payload) => anyhow::bail!(
                "profiling thread panicked: {}",
                panic_payload_message(payload.as_ref())
            ),
        }
    }
}

impl Drop for ProfilerSession {
    fn drop(&mut self) {
        if let Some(stop_tx) = self.stop_tx.take() {
            let _ = stop_tx.send(());
        }
        if let Some(handle) = self.handle.take() {
            let _ = handle.join();
        }
    }
}

fn run_profiler_thread(
    shared: Arc<Mutex<SessionState>>,
    stop_rx: mpsc::Receiver<()>,
    interval: Duration,
) -> Result<ProfileSnapshot> {
    let pmu = pmu::PmuCounters::open();
    if let Some(ref pmu) = pmu {
        pmu.reset_and_enable();
    }

    loop {
        match stop_rx.recv_timeout(interval) {
            Ok(()) | Err(mpsc::RecvTimeoutError::Disconnected) => {
                let poll_result = poll_all_programs(&shared, pmu.as_ref());
                if let Some(ref pmu) = pmu {
                    pmu.disable();
                }
                if let Err(err) = &poll_result {
                    record_fatal_error(&shared, err);
                }
                poll_result?;
                return snapshot_from_shared(&shared);
            }
            Err(mpsc::RecvTimeoutError::Timeout) => {
                if let Err(err) = poll_all_programs(&shared, pmu.as_ref()) {
                    record_fatal_error(&shared, &err);
                    if let Some(ref pmu) = pmu {
                        pmu.disable();
                    }
                    return Err(err);
                }
            }
        }
    }
}

fn record_fatal_error(shared: &Arc<Mutex<SessionState>>, err: &anyhow::Error) {
    if let Ok(mut state) = shared.lock() {
        state.fatal_error = Some(format!("profiling session failed: {err:#}"));
    }
}

fn snapshot_from_shared(shared: &Arc<Mutex<SessionState>>) -> Result<ProfileSnapshot> {
    let state = shared
        .lock()
        .map_err(|_| anyhow::anyhow!("profiling state lock poisoned"))?;
    state.snapshot()
}

fn poll_all_programs(
    shared: &Arc<Mutex<SessionState>>,
    pmu: Option<&pmu::PmuCounters>,
) -> Result<()> {
    let branch_miss_rate = pmu.and_then(|counter| counter.read_branch_miss_rate());
    let current = read_all_prog_stats()?;
    let mut state = shared
        .lock()
        .map_err(|_| anyhow::anyhow!("profiling state lock poisoned"))?;

    state.current_branch_miss_rate = branch_miss_rate;

    let current_ids: std::collections::HashSet<u32> = current.keys().copied().collect();
    state
        .last_snapshots
        .retain(|prog_id, _| current_ids.contains(prog_id));

    for (prog_id, snapshot) in current {
        if let Some(before) = state.last_snapshots.get(&prog_id) {
            let delta = ProgStatsDelta::from_snapshots(before, &snapshot);
            let entry = state.programs.entry(prog_id).or_default();
            entry.add_delta(&delta);
            entry.branch_miss_rate = branch_miss_rate;
        } else if let Some(entry) = state.programs.get_mut(&prog_id) {
            entry.branch_miss_rate = branch_miss_rate;
        }

        state.last_snapshots.insert(prog_id, snapshot);
    }

    Ok(())
}

fn read_all_prog_stats() -> Result<HashMap<u32, ProgStatsSnapshot>> {
    let captured_at = Instant::now();
    let mut snapshots = HashMap::new();

    for prog_id in bpf::iter_prog_ids() {
        let prog_id = prog_id.context("enumerate program IDs for profiling")?;
        let prog_fd = bpf::bpf_prog_get_fd_by_id(prog_id)
            .with_context(|| format!("open prog {} for profiling snapshot", prog_id))?;
        let (info, _) = bpf::bpf_prog_get_info(prog_fd.as_raw_fd(), false)
            .with_context(|| format!("read stats for prog {}", prog_id))?;
        snapshots.insert(
            prog_id,
            ProgStatsSnapshot {
                prog_id,
                captured_at,
                stats: ProgStats::from_totals(info.run_cnt, info.run_time_ns),
            },
        );
    }

    Ok(snapshots)
}

fn panic_payload_message(payload: &(dyn std::any::Any + Send)) -> String {
    if let Some(message) = payload.downcast_ref::<String>() {
        return message.clone();
    }
    if let Some(message) = payload.downcast_ref::<&'static str>() {
        return (*message).to_string();
    }
    "non-string panic payload".to_string()
}

/// Collect runtime profiling data for one program during an observation window.
///
/// This currently provides:
/// - program hotness via `run_cnt` / `run_time_ns` deltas
/// - program-level `branch_miss_rate` when PMU counters are available
///
/// Per-PC `branch_profiles` remain empty because the daemon does not yet have a
/// production source for branch-taken/not-taken counts.
pub fn collect_program_profiling(
    prog_id: u32,
    interval: Duration,
) -> Result<(ProfilingData, PgoAnalysis)> {
    if interval.is_zero() {
        anyhow::bail!("profile interval must be greater than zero");
    }
    if !bpf_stats_enabled()? {
        anyhow::bail!(
            "runtime profiling requires kernel.bpf_stats_enabled=1; enable it before collecting profiling data"
        );
    }

    let mut poller = ProgStatsPoller::open(prog_id)?;
    let pmu = pmu::PmuCounters::open();

    if let Some(ref pmu) = pmu {
        pmu.reset_and_enable();
    }

    let deltas = poller.collect_deltas(interval, 1);
    let branch_miss_rate = pmu.as_ref().and_then(|pmu| {
        let rate = pmu.read_branch_miss_rate();
        pmu.disable();
        rate
    });
    let delta = deltas?
        .into_iter()
        .next()
        .context("failed to compute stats delta")?;
    let analysis = PgoAnalysis::from_delta(&delta);
    let profiling = ProfilingData {
        branch_profiles: std::collections::HashMap::new(),
        branch_miss_rate,
    };

    Ok((profiling, analysis))
}

pub fn collect_hotness_ranking(
    prog_ids: &[u32],
    interval: Duration,
) -> Result<(HotnessRanking, Duration)> {
    if interval.is_zero() {
        anyhow::bail!("hotness ranking interval must be greater than zero");
    }
    if prog_ids.is_empty() {
        return Ok((HotnessRanking { ranked: Vec::new() }, interval));
    }
    if !bpf_stats_enabled()? {
        anyhow::bail!(
            "hotness ranking requires kernel.bpf_stats_enabled=1 or a loaded profile snapshot"
        );
    }

    let before = read_selected_prog_stats(prog_ids)?;
    thread::sleep(interval);
    let after = read_selected_prog_stats(prog_ids)?;

    let mut analyses = Vec::with_capacity(prog_ids.len());
    let mut observation_window = Duration::ZERO;

    for &prog_id in prog_ids {
        let before_snapshot = before
            .get(&prog_id)
            .with_context(|| format!("missing baseline stats snapshot for prog {}", prog_id))?;
        let after_snapshot = after
            .get(&prog_id)
            .with_context(|| format!("missing final stats snapshot for prog {}", prog_id))?;
        let delta = ProgStatsDelta::from_snapshots(before_snapshot, after_snapshot);
        if observation_window.is_zero() {
            observation_window = delta.elapsed;
        }
        analyses.push(PgoAnalysis::from_delta(&delta));
    }

    if observation_window.is_zero() {
        observation_window = interval;
    }

    Ok((
        HotnessRanking::from_analyses(analyses, observation_window),
        observation_window,
    ))
}

pub struct ProgStatsPoller {
    prog_id: u32,
    prog_fd: OwnedFd,
    previous: Option<ProgStatsSnapshot>,
}

fn read_selected_prog_stats(prog_ids: &[u32]) -> Result<HashMap<u32, ProgStatsSnapshot>> {
    let mut snapshots = HashMap::with_capacity(prog_ids.len());
    for &prog_id in prog_ids {
        let poller = ProgStatsPoller::open(prog_id)?;
        snapshots.insert(prog_id, poller.snapshot()?);
    }
    Ok(snapshots)
}

impl ProgStatsPoller {
    pub fn open(prog_id: u32) -> Result<Self> {
        let prog_fd = bpf::bpf_prog_get_fd_by_id(prog_id)
            .with_context(|| format!("open prog {} for stats polling", prog_id))?;

        Ok(Self {
            prog_id,
            prog_fd,
            previous: None,
        })
    }

    pub fn poll_stats(&self) -> Result<ProgStats> {
        let (info, _) = bpf::bpf_prog_get_info(self.prog_fd.as_raw_fd(), false)
            .with_context(|| format!("read stats for prog {}", self.prog_id))?;
        Ok(ProgStats::from_totals(info.run_cnt, info.run_time_ns))
    }

    pub fn snapshot(&self) -> Result<ProgStatsSnapshot> {
        Ok(ProgStatsSnapshot {
            prog_id: self.prog_id,
            captured_at: Instant::now(),
            stats: self.poll_stats()?,
        })
    }

    pub fn poll_delta(&mut self) -> Result<Option<ProgStatsDelta>> {
        let current = self.snapshot()?;
        let delta = self
            .previous
            .as_ref()
            .map(|before| ProgStatsDelta::from_snapshots(before, &current));
        self.previous = Some(current);
        Ok(delta)
    }

    pub fn collect_deltas(
        &mut self,
        interval: Duration,
        samples: usize,
    ) -> Result<Vec<ProgStatsDelta>> {
        let mut deltas = Vec::with_capacity(samples);
        self.poll_delta()?;

        for _ in 0..samples {
            thread::sleep(interval);
            if let Some(delta) = self.poll_delta()? {
                deltas.push(delta);
            }
        }

        Ok(deltas)
    }
}

pub fn bpf_stats_enabled() -> Result<bool> {
    let raw = std::fs::read_to_string("/proc/sys/kernel/bpf_stats_enabled")
        .context("read /proc/sys/kernel/bpf_stats_enabled")?;
    Ok(raw.trim() == "1")
}

fn format_system_time_rfc3339(timestamp: SystemTime) -> Result<String> {
    let unix = timestamp
        .duration_since(UNIX_EPOCH)
        .context("convert timestamp to unix epoch")?;
    let seconds = unix.as_secs() as libc::time_t;
    let mut tm: libc::tm = unsafe { std::mem::zeroed() };
    if unsafe { libc::gmtime_r(&seconds, &mut tm) }.is_null() {
        anyhow::bail!("format collected_at timestamp with gmtime_r");
    }

    let mut buffer = [0 as libc::c_char; 32];
    let format = b"%Y-%m-%dT%H:%M:%SZ\0";
    let written = unsafe {
        libc::strftime(
            buffer.as_mut_ptr(),
            buffer.len(),
            format.as_ptr() as *const libc::c_char,
            &tm,
        )
    };
    if written == 0 {
        anyhow::bail!("format collected_at timestamp with strftime");
    }

    Ok(CStr::from_bytes_until_nul(unsafe {
        std::slice::from_raw_parts(buffer.as_ptr() as *const u8, buffer.len())
    })
    .context("convert collected_at buffer to C string")?
    .to_str()
    .context("convert collected_at buffer to UTF-8")?
    .to_string())
}

fn avg_ns(run_time_ns: u64, run_cnt: u64) -> Option<f64> {
    if run_cnt == 0 {
        None
    } else {
        Some(run_time_ns as f64 / run_cnt as f64)
    }
}

pub(crate) mod pmu {
    use std::os::unix::io::RawFd;

    const PERF_TYPE_HARDWARE: u32 = 0;
    const PERF_COUNT_HW_BRANCH_INSTRUCTIONS: u64 = 4;
    const PERF_COUNT_HW_BRANCH_MISSES: u64 = 5;

    const PERF_EVENT_IOC_RESET: libc::c_ulong = 0x2403;
    const PERF_EVENT_IOC_ENABLE: libc::c_ulong = 0x2400;
    const PERF_EVENT_IOC_DISABLE: libc::c_ulong = 0x2401;

    #[repr(C)]
    struct PerfEventAttr {
        type_: u32,
        size: u32,
        config: u64,
        sample_period_or_freq: u64,
        sample_type: u64,
        read_format: u64,
        flags: u64,
        wakeup_events_or_watermark: u32,
        bp_type: u32,
        config1_or_bp_addr: u64,
        config2_or_bp_len: u64,
        branch_sample_type: u64,
        sample_regs_user: u64,
        sample_stack_user: u32,
        clockid: i32,
        sample_regs_intr: u64,
        aux_watermark: u32,
        sample_max_stack: u16,
        _reserved: u16,
    }

    impl PerfEventAttr {
        fn new(type_: u32, config: u64) -> Self {
            let mut attr: Self = unsafe { std::mem::zeroed() };
            attr.type_ = type_;
            attr.size = std::mem::size_of::<Self>() as u32;
            attr.config = config;
            // disabled=1, exclude_hv=1
            attr.flags = (1 << 0) | (1 << 5);
            attr
        }
    }

    pub(crate) struct PmuCounters {
        branch_insns_fd: RawFd,
        branch_misses_fd: RawFd,
    }

    impl PmuCounters {
        pub(crate) fn open() -> Option<Self> {
            let branch_insns_fd = perf_event_open_hw(PERF_COUNT_HW_BRANCH_INSTRUCTIONS)?;
            let branch_misses_fd = match perf_event_open_hw(PERF_COUNT_HW_BRANCH_MISSES) {
                Some(fd) => fd,
                None => {
                    unsafe {
                        libc::close(branch_insns_fd);
                    }
                    return None;
                }
            };

            Some(Self {
                branch_insns_fd,
                branch_misses_fd,
            })
        }

        pub(crate) fn reset_and_enable(&self) {
            unsafe {
                libc::ioctl(self.branch_insns_fd, PERF_EVENT_IOC_RESET, 0);
                libc::ioctl(self.branch_misses_fd, PERF_EVENT_IOC_RESET, 0);
                libc::ioctl(self.branch_insns_fd, PERF_EVENT_IOC_ENABLE, 0);
                libc::ioctl(self.branch_misses_fd, PERF_EVENT_IOC_ENABLE, 0);
            }
        }

        pub(crate) fn disable(&self) {
            unsafe {
                libc::ioctl(self.branch_insns_fd, PERF_EVENT_IOC_DISABLE, 0);
                libc::ioctl(self.branch_misses_fd, PERF_EVENT_IOC_DISABLE, 0);
            }
        }

        pub(crate) fn read_branch_miss_rate(&self) -> Option<f64> {
            let insns = read_counter(self.branch_insns_fd)?;
            let misses = read_counter(self.branch_misses_fd)?;
            if insns == 0 {
                return None;
            }
            Some(misses as f64 / insns as f64)
        }
    }

    impl Drop for PmuCounters {
        fn drop(&mut self) {
            unsafe {
                libc::close(self.branch_insns_fd);
                libc::close(self.branch_misses_fd);
            }
        }
    }

    fn perf_event_open_hw(config: u64) -> Option<RawFd> {
        let attr = PerfEventAttr::new(PERF_TYPE_HARDWARE, config);
        let fd = unsafe {
            libc::syscall(
                libc::SYS_perf_event_open,
                &attr as *const PerfEventAttr as libc::c_long,
                0 as libc::c_long,
                -1 as libc::c_long,
                -1 as libc::c_long,
                0 as libc::c_long,
            )
        };
        if fd < 0 {
            return None;
        }
        Some(fd as RawFd)
    }

    fn read_counter(fd: RawFd) -> Option<u64> {
        let mut value: u64 = 0;
        let ret = unsafe {
            libc::read(
                fd,
                &mut value as *mut u64 as *mut libc::c_void,
                std::mem::size_of::<u64>(),
            )
        };
        if ret != std::mem::size_of::<u64>() as isize {
            return None;
        }
        Some(value)
    }

    #[cfg(test)]
    mod tests {
        use super::*;

        #[test]
        fn pmu_open_returns_some_or_none_gracefully() {
            let result = PmuCounters::open();
            if let Some(ref pmu) = result {
                pmu.reset_and_enable();
                let mut sum = 0u64;
                for i in 0..10000 {
                    sum = sum.wrapping_add(i);
                }
                let _ = std::hint::black_box(sum);
                let rate = pmu.read_branch_miss_rate();
                pmu.disable();
                if let Some(rate) = rate {
                    assert!((0.0..=1.0).contains(&rate));
                }
            }
        }

        #[test]
        fn perf_event_attr_layout_is_correct() {
            let attr = PerfEventAttr::new(PERF_TYPE_HARDWARE, PERF_COUNT_HW_BRANCH_MISSES);
            assert_eq!(attr.type_, 0);
            assert_eq!(attr.config, 5);
            assert_eq!(attr.size, std::mem::size_of::<PerfEventAttr>() as u32);
            assert_eq!(attr.flags, 33);
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::time::{Duration, Instant};

    fn snapshot(prog_id: u32, at: Instant, run_cnt: u64, run_time_ns: u64) -> ProgStatsSnapshot {
        ProgStatsSnapshot {
            prog_id,
            captured_at: at,
            stats: ProgStats {
                run_cnt,
                run_time_ns,
                avg_ns: if run_cnt == 0 {
                    None
                } else {
                    Some(run_time_ns as f64 / run_cnt as f64)
                },
            },
        }
    }

    #[test]
    fn delta_uses_monotonic_counter_difference() {
        let start = Instant::now();
        let before = snapshot(7, start, 10, 2_000);
        let after = snapshot(7, start + Duration::from_millis(250), 25, 5_750);

        let delta = ProgStatsDelta::from_snapshots(&before, &after);

        assert_eq!(delta.prog_id, 7);
        assert_eq!(delta.elapsed, Duration::from_millis(250));
        assert_eq!(delta.run_cnt_delta, 15);
        assert_eq!(delta.run_time_ns_delta, 3_750);
        assert_eq!(delta.avg_ns, Some(250.0));
    }

    #[test]
    fn delta_saturates_if_counters_go_backwards() {
        let start = Instant::now();
        let before = snapshot(7, start, 25, 5_750);
        let after = snapshot(7, start + Duration::from_millis(10), 10, 2_000);

        let delta = ProgStatsDelta::from_snapshots(&before, &after);

        assert_eq!(delta.run_cnt_delta, 0);
        assert_eq!(delta.run_time_ns_delta, 0);
        assert_eq!(delta.avg_ns, None);
    }

    #[test]
    fn pgo_analysis_from_delta() {
        let start = Instant::now();
        let before = snapshot(9, start, 100, 20_000);
        let after = snapshot(9, start + Duration::from_secs(1), 160, 44_000);
        let delta = ProgStatsDelta::from_snapshots(&before, &after);
        let analysis = PgoAnalysis::from_delta(&delta);

        assert_eq!(analysis.prog_id, 9);
        assert_eq!(analysis.delta_run_cnt, 60);
        assert_eq!(analysis.delta_run_time_ns, 24_000);
        assert_eq!(analysis.delta_avg_ns, Some(400.0));
    }

    #[test]
    fn pgo_analysis_hotness() {
        let start = Instant::now();
        let before = snapshot(1, start, 100, 10_000);
        let after = snapshot(1, start + Duration::from_secs(2), 200, 20_000);
        let delta = ProgStatsDelta::from_snapshots(&before, &after);
        let analysis = PgoAnalysis::from_delta(&delta);

        assert!(analysis.is_hot());
        assert!((analysis.hotness_score(Duration::from_secs(2)) - 50.0).abs() < 0.01);
    }

    #[test]
    fn pgo_analysis_cold_program() {
        let start = Instant::now();
        let before = snapshot(2, start, 100, 10_000);
        let after = snapshot(2, start + Duration::from_secs(1), 100, 10_000);
        let delta = ProgStatsDelta::from_snapshots(&before, &after);
        let analysis = PgoAnalysis::from_delta(&delta);

        assert!(!analysis.is_hot());
        assert_eq!(analysis.hotness_score(Duration::from_secs(1)), 0.0);
    }

    #[test]
    fn hotness_ranking_orders_by_activity() {
        let start = Instant::now();
        let window = Duration::from_secs(1);

        let hot = PgoAnalysis::from_delta(&ProgStatsDelta::from_snapshots(
            &snapshot(1, start, 0, 0),
            &snapshot(1, start + window, 1000, 100_000),
        ));
        let warm = PgoAnalysis::from_delta(&ProgStatsDelta::from_snapshots(
            &snapshot(2, start, 0, 0),
            &snapshot(2, start + window, 100, 10_000),
        ));
        let cold = PgoAnalysis::from_delta(&ProgStatsDelta::from_snapshots(
            &snapshot(3, start, 50, 5_000),
            &snapshot(3, start + window, 50, 5_000),
        ));

        let ranking = HotnessRanking::from_analyses(vec![cold, hot.clone(), warm], window);

        assert_eq!(ranking.ranked[0].prog_id, 1); // hot
        assert_eq!(ranking.ranked[1].prog_id, 2); // warm
        assert_eq!(ranking.ranked[2].prog_id, 3); // cold

        let hot_progs = ranking.hot_programs();
        assert_eq!(hot_progs.len(), 2);
        assert_eq!(hot_progs[0].prog_id, 1);
        assert_eq!(hot_progs[1].prog_id, 2);
    }
}
