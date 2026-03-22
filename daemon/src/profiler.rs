// SPDX-License-Identifier: MIT
//! Runtime profiler helpers backed by `bpf_prog_info`.
//!
//! This is the PGO data source for the daemon:
//! - **Program-level**: poll `run_cnt` / `run_time_ns`, compute deltas, rank
//!   programs by hotness (run_cnt during observation window).
//! - **Branch-level**: design interface for per-branch taken/not-taken counts.
//!   In environments without hardware PMU (e.g., VMs), we use program-level
//!   hotness as a proxy and synthesize uniform branch profiles for hot programs.
//!
//! The profiler produces [`crate::pass::ProfilingData`] that gets injected into
//! the `BpfProgram` annotations before pass execution.

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
/// Fields are populated from runtime polling and consumed by ProfilingData,
/// HotnessRanking, and diagnostic output.
#[derive(Clone, Debug)]
pub struct PgoAnalysis {
    pub prog_id: u32,
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
    /// Total observation window duration.
    pub observation_window: Duration,
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
        Self {
            ranked,
            observation_window,
        }
    }

    /// Return only programs that are actively running.
    pub fn hot_programs(&self) -> Vec<&PgoAnalysis> {
        self.ranked.iter().filter(|a| a.is_hot()).collect()
    }
}

/// Collect program-level profiling data for a single program.
///
/// Polls `run_cnt`/`run_time_ns` twice with the given interval, computes the
/// delta, and produces a [`ProfilingData`] suitable for injection.
///
/// Currently, branch-level profiling is not available from `bpf_prog_info`,
/// so the returned `ProfilingData` will have an empty `branch_profiles` map.
/// The `program_hotness` field captures program-level activity.
pub fn collect_program_profiling(
    prog_id: u32,
    interval: Duration,
) -> Result<(ProfilingData, PgoAnalysis)> {
    let mut poller = ProgStatsPoller::open(prog_id)?;
    // Take initial snapshot.
    poller.poll_delta()?;
    thread::sleep(interval);
    let delta = poller
        .poll_delta()?
        .context("failed to compute stats delta")?;
    let analysis = PgoAnalysis::from_delta(&delta);

    let profiling = ProfilingData {
        program_hotness: Some(analysis.clone()),
        ..Default::default()
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

    #[test]
    fn profiling_data_from_pgo_analysis() {
        let start = Instant::now();
        let before = snapshot(5, start, 100, 20_000);
        let after = snapshot(5, start + Duration::from_secs(1), 200, 40_000);
        let delta = ProgStatsDelta::from_snapshots(&before, &after);
        let analysis = PgoAnalysis::from_delta(&delta);

        let profiling = ProfilingData {
            program_hotness: Some(analysis),
            ..Default::default()
        };

        assert!(profiling.program_hotness.is_some());
        assert_eq!(profiling.program_hotness.as_ref().unwrap().prog_id, 5);
        assert!(profiling.branch_profiles.is_empty());
    }
}
