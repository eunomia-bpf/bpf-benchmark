// SPDX-License-Identifier: MIT
//! Runtime profiler helpers backed by `bpf_prog_info` and optional PMU counters.
//!
//! This is the PGO data source for the daemon:
//! - **Program-level**: poll `run_cnt` / `run_time_ns`, compute deltas, rank
//!   programs by hotness (run_cnt during observation window).
//! - **Program-level PMU**: use `perf_event_open` to collect branch miss and
//!   branch instruction counters during the same observation window.

use std::os::fd::{AsRawFd, OwnedFd};
use std::thread;
use std::time::{Duration, Instant};

use anyhow::{Context, Result};

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
    /// Returns 0.0 if no time elapsed. Used by HotnessRanking and watch mode.
    pub fn hotness_score(&self, elapsed: Duration) -> f64 {
        let secs = elapsed.as_secs_f64();
        if secs <= 0.0 {
            return 0.0;
        }
        self.delta_run_cnt as f64 / secs
    }
}

/// Program hotness ranking — sorts programs by activity level.
/// Used by the watch command and future multi-program PGO flows.
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
        });
        Self { ranked }
    }

    /// Return only programs that are actively running.
    #[allow(dead_code)]
    pub fn hot_programs(&self) -> Vec<&PgoAnalysis> {
        self.ranked.iter().filter(|a| a.is_hot()).collect()
    }
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
    let mut poller = ProgStatsPoller::open(prog_id)?;
    let pmu = pmu::PmuCounters::open();

    poller.poll_delta()?;

    if let Some(ref pmu) = pmu {
        pmu.reset_and_enable();
    }

    thread::sleep(interval);

    let branch_miss_rate = pmu.as_ref().and_then(|pmu| {
        let rate = pmu.read_branch_miss_rate();
        pmu.disable();
        rate
    });

    let delta = poller
        .poll_delta()?
        .context("failed to compute stats delta")?;
    let analysis = PgoAnalysis::from_delta(&delta);
    let profiling = ProfilingData {
        branch_profiles: std::collections::HashMap::new(),
        branch_miss_rate,
    };

    Ok((profiling, analysis))
}

pub struct ProgStatsPoller {
    prog_id: u32,
    prog_fd: OwnedFd,
    previous: Option<ProgStatsSnapshot>,
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
