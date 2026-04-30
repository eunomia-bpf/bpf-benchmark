// SPDX-License-Identifier: MIT
//! bpfprof CLI entry point.
//!
//! Branch PMU data requires `perf_event_paranoid <= 2` and container permission
//! such as `SYS_ADMIN`. PMU counters are required: bpfprof exits with an error
//! when they cannot be collected.

use std::collections::BTreeMap;
use std::fs::{self, File};
use std::io::{self, Read, Write};
use std::os::fd::{AsFd, AsRawFd, FromRawFd};
use std::path::{Path, PathBuf};
use std::process::ExitCode;
use std::thread;
use std::time::Duration;

use anyhow::{anyhow, bail, Context, Result};
use clap::Parser;
use perf_event_open_sys::{bindings as perf, ioctls};
use serde::Serialize;

#[derive(Parser, Debug)]
#[command(name = "bpfprof", version, about = "Profile live BPF programs")]
struct Cli {
    /// Profile one live BPF program ID.
    #[arg(long, conflicts_with = "all", value_name = "N")]
    prog_id: Option<u32>,
    /// Profile all live BPF programs.
    #[arg(long)]
    all: bool,
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
    fd: std::os::fd::OwnedFd,
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
    branch_miss_rate: Option<f64>,
    branch_misses: Option<u64>,
    branch_instructions: Option<u64>,
    per_insn: BTreeMap<String, PerInsnProfile>,
}

#[derive(Clone, Debug, Serialize, PartialEq, Eq)]
struct PerInsnProfile {
    taken: u64,
    not_taken: u64,
}

struct BranchCounters {
    instructions: File,
    misses: File,
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
    let before = read_snapshots(&targets)?;
    collect_branch_pmu(cli.duration)?;
    let after = read_snapshots(&targets)?;

    let duration_ms = duration_ms(cli.duration);
    let profiles = build_profiles(&targets, &before, &after, duration_ms);
    write_profiles(&cli, &profiles)?;
    Ok(())
}

fn validate_cli(cli: &Cli) -> Result<()> {
    if cli.prog_id.is_none() && !cli.all {
        bail!("one of --prog-id N or --all is required");
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

fn read_snapshots(targets: &[Target]) -> Result<BTreeMap<u32, ProgStats>> {
    let mut snapshots = BTreeMap::new();
    for target in targets {
        let info = kernel_sys::obj_get_info_by_fd(target.fd.as_fd())
            .with_context(|| format!("read stats for BPF program id {}", target.prog_id))?;
        snapshots.insert(
            target.prog_id,
            ProgStats {
                run_cnt: info.run_cnt,
                run_time_ns: info.run_time_ns,
            },
        );
    }
    Ok(snapshots)
}

fn build_profiles(
    targets: &[Target],
    before: &BTreeMap<u32, ProgStats>,
    after: &BTreeMap<u32, ProgStats>,
    duration_ms: u64,
) -> Vec<ProfileJson> {
    let mut rows = targets
        .iter()
        .filter_map(|target| {
            let before = before.get(&target.prog_id)?;
            let after = after.get(&target.prog_id)?;
            // The current PMU sample covers the whole profiling window, not a
            // specific BPF program, so per-program branch fields stay null.
            Some(ProfileJson {
                prog_id: target.prog_id,
                duration_ms,
                run_cnt_delta: after.run_cnt.saturating_sub(before.run_cnt),
                run_time_ns_delta: after.run_time_ns.saturating_sub(before.run_time_ns),
                branch_miss_rate: None,
                branch_misses: None,
                branch_instructions: None,
                per_insn: BTreeMap::new(),
            })
        })
        .collect::<Vec<_>>();
    rows.sort_by(|a, b| {
        b.run_cnt_delta
            .cmp(&a.run_cnt_delta)
            .then_with(|| b.run_time_ns_delta.cmp(&a.run_time_ns_delta))
            .then_with(|| a.prog_id.cmp(&b.prog_id))
    });
    rows
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

fn collect_branch_pmu(duration: Duration) -> Result<()> {
    collect_branch_pmu_with(duration, try_open_pmu, thread::sleep)
}

fn collect_branch_pmu_with<OpenPmu, SleepFn>(
    duration: Duration,
    open_pmu: OpenPmu,
    sleep: SleepFn,
) -> Result<()>
where
    OpenPmu: FnOnce() -> Result<BranchCounters>,
    SleepFn: FnOnce(Duration),
{
    let pmu = open_pmu()?;
    pmu.reset_and_enable()?;
    sleep(duration);
    pmu.disable()?;
    pmu.read_counts()?;
    Ok(())
}

fn try_open_pmu() -> Result<BranchCounters> {
    BranchCounters::open().context("open PMU branch counters")
}

impl BranchCounters {
    fn open() -> Result<Self> {
        let instructions = open_perf_counter(perf::PERF_COUNT_HW_BRANCH_INSTRUCTIONS as u64)
            .context("open branch-instructions PMU counter")?;
        let misses = open_perf_counter(perf::PERF_COUNT_HW_BRANCH_MISSES as u64)
            .context("open branch-misses PMU counter")?;
        Ok(Self {
            instructions,
            misses,
        })
    }

    fn reset_and_enable(&self) -> Result<()> {
        self.ioctl_all("reset", |fd| unsafe { ioctls::RESET(fd, 0) })?;
        self.ioctl_all("enable", |fd| unsafe { ioctls::ENABLE(fd, 0) })
    }

    fn disable(&self) -> Result<()> {
        self.ioctl_all("disable", |fd| unsafe { ioctls::DISABLE(fd, 0) })
    }

    fn read_counts(mut self) -> Result<()> {
        let _branch_instructions =
            read_counter(&mut self.instructions).context("read branch-instructions PMU counter")?;
        let _branch_misses =
            read_counter(&mut self.misses).context("read branch-misses PMU counter")?;
        Ok(())
    }

    fn ioctl_all<F>(&self, action: &str, ioctl: F) -> Result<()>
    where
        F: Fn(i32) -> i32,
    {
        for file in [&self.instructions, &self.misses] {
            let ret = ioctl(file.as_raw_fd());
            if ret < 0 {
                return Err(anyhow!(
                    "perf_event_open {action}: {}",
                    io::Error::last_os_error()
                ));
            }
        }
        Ok(())
    }
}

fn open_perf_counter(config: u64) -> Result<File> {
    let mut attrs = perf::perf_event_attr {
        size: std::mem::size_of::<perf::perf_event_attr>() as u32,
        type_: perf::PERF_TYPE_HARDWARE,
        config,
        ..Default::default()
    };
    attrs.set_disabled(1);
    attrs.set_exclude_hv(1);

    let fd = unsafe { perf_event_open_sys::perf_event_open(&mut attrs, 0, -1, -1, 0) };
    if fd < 0 {
        return Err(anyhow!("perf_event_open: {}", io::Error::last_os_error()));
    }
    Ok(unsafe { File::from_raw_fd(fd) })
}

fn read_counter(file: &mut File) -> Result<u64> {
    let mut buf = [0u8; 8];
    file.read_exact(&mut buf)?;
    Ok(u64::from_ne_bytes(buf))
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

fn parse_duration(input: &str) -> Result<Duration, String> {
    humantime::parse_duration(input).map_err(|err| err.to_string())
}

fn duration_ms(duration: Duration) -> u64 {
    duration.as_millis().try_into().unwrap_or(u64::MAX)
}

fn error_is_enoent(err: &anyhow::Error) -> bool {
    format!("{err:#}").contains("No such file or directory")
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::cell::Cell;

    #[test]
    fn profile_json_serializes_nullable_branch_metrics() {
        let profile = ProfileJson {
            prog_id: 123,
            duration_ms: 500,
            run_cnt_delta: 10,
            run_time_ns_delta: 2_000,
            branch_miss_rate: None,
            branch_misses: None,
            branch_instructions: None,
            per_insn: BTreeMap::new(),
        };

        let value = serde_json::to_value(&profile).unwrap();

        assert_eq!(value["prog_id"], 123);
        assert_eq!(value["duration_ms"], 500);
        assert_eq!(value["run_cnt_delta"], 10);
        assert_eq!(value["run_time_ns_delta"], 2_000);
        assert!(value["branch_miss_rate"].is_null());
        assert!(value["branch_misses"].is_null());
        assert!(value["branch_instructions"].is_null());
        assert!(value["per_insn"].as_object().unwrap().is_empty());
    }

    #[test]
    fn build_profiles_sorts_by_run_count_delta() {
        let targets = vec![fake_target(2), fake_target(1)];
        let before = BTreeMap::from([
            (
                1,
                ProgStats {
                    run_cnt: 10,
                    run_time_ns: 10,
                },
            ),
            (
                2,
                ProgStats {
                    run_cnt: 5,
                    run_time_ns: 10,
                },
            ),
        ]);
        let after = BTreeMap::from([
            (
                1,
                ProgStats {
                    run_cnt: 30,
                    run_time_ns: 110,
                },
            ),
            (
                2,
                ProgStats {
                    run_cnt: 7,
                    run_time_ns: 30,
                },
            ),
        ]);

        let rows = build_profiles(&targets, &before, &after, 100);

        assert_eq!(rows[0].prog_id, 1);
        assert_eq!(rows[0].run_cnt_delta, 20);
    }

    #[test]
    fn build_profiles_does_not_attribute_shared_pmu_to_program() {
        let targets = vec![fake_target(7)];
        let before = BTreeMap::from([(
            7,
            ProgStats {
                run_cnt: 10,
                run_time_ns: 100,
            },
        )]);
        let after = BTreeMap::from([(
            7,
            ProgStats {
                run_cnt: 14,
                run_time_ns: 180,
            },
        )]);

        let rows = build_profiles(&targets, &before, &after, 250);

        assert_eq!(rows.len(), 1);
        assert_eq!(rows[0].run_cnt_delta, 4);
        assert_eq!(rows[0].run_time_ns_delta, 80);
        assert_eq!(rows[0].branch_miss_rate, None);
        assert_eq!(rows[0].branch_misses, None);
        assert_eq!(rows[0].branch_instructions, None);
    }

    #[test]
    fn pmu_open_failure_returns_error_without_sampling_window() {
        let slept = Cell::new(false);
        let duration = Duration::from_millis(25);

        let err = collect_branch_pmu_with(
            duration,
            || Err(anyhow!("perf_event_open: Operation not permitted")),
            |slept_duration| {
                assert_eq!(slept_duration, duration);
                slept.set(true);
            },
        )
        .expect_err("PMU open failure must fail fast");

        assert!(err.to_string().contains("perf_event_open"));
        assert!(!slept.get());
    }

    fn fake_target(prog_id: u32) -> Target {
        let fd = File::open("/dev/null").unwrap().into();
        Target { prog_id, fd }
    }
}
