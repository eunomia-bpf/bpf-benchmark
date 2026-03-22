// SPDX-License-Identifier: MIT
//! Runtime profiler helpers backed by `bpf_prog_info`.
//!
//! This is the minimal PGO data source for the daemon today:
//! poll `run_cnt` / `run_time_ns`, compute deltas, and feed a pass-facing
//! analysis object.

use std::os::fd::{AsRawFd, OwnedFd};
use std::thread;
use std::time::{Duration, Instant};

use anyhow::{Context, Result};

use crate::bpf;

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
#[allow(dead_code)]
pub struct ProgStatsDelta {
    pub prog_id: u32,
    pub elapsed: Duration,
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

#[derive(Clone, Debug)]
#[allow(dead_code)]
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
    use super::{PgoAnalysis, ProgStats, ProgStatsDelta, ProgStatsSnapshot};
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
}
