// SPDX-License-Identifier: MIT
//! Thin verifier-state capture used only by explicit const_prop requests.

use std::os::fd::{AsRawFd, OwnedFd};
use std::sync::mpsc;
use std::thread;
use std::time::Duration;

use anyhow::{anyhow, bail, Context, Result};

const LOG_BUF_SIZE: usize = 16 * 1024 * 1024;
const DRY_RUN_TIMEOUT: Duration = Duration::from_secs(5);

#[derive(Clone, Copy, Debug)]
struct ThinLoadContext {
    prog_type: kernel_sys::bpf_prog_type,
    expected_attach_type: Option<kernel_sys::bpf_attach_type>,
    prog_flags: u32,
    prog_btf_id: u32,
    attach_btf_id: u32,
    attach_btf_obj_id: u32,
}

struct BtfFd {
    raw_fd: Option<i32>,
    _owned: Option<OwnedFd>,
}

pub(crate) fn capture_verifier_states(
    snapshot: &bpfget::ProgramSnapshot,
    insns: &[kernel_sys::bpf_insn],
    fd_array: &[i32],
) -> Result<kernel_sys::VerifierStatesJson> {
    let context = ThinLoadContext {
        prog_type: snapshot.info.prog_type.numeric,
        expected_attach_type: snapshot
            .info
            .expected_attach_type
            .as_ref()
            .map(|attach_type| attach_type.numeric),
        prog_flags: snapshot.info.prog_flags,
        prog_btf_id: snapshot.info.btf_id,
        attach_btf_id: snapshot.info.attach_btf_id,
        attach_btf_obj_id: snapshot.info.attach_btf_obj_id,
    };
    let insns = insns.to_vec();
    let fd_array = fd_array.to_vec();
    run_with_timeout("thin verifier dry-run", DRY_RUN_TIMEOUT, move || {
        capture_verifier_states_inner(context, &insns, &fd_array)
    })
}

fn capture_verifier_states_inner(
    context: ThinLoadContext,
    insns: &[kernel_sys::bpf_insn],
    fd_array: &[i32],
) -> Result<kernel_sys::VerifierStatesJson> {
    let prog_btf_fd = open_optional_btf_fd(context.prog_btf_id, "program BTF")?;
    let attach_btf_obj_fd = open_optional_btf_fd(context.attach_btf_obj_id, "attach BTF object")?;
    let mut log_buf = vec![0u8; LOG_BUF_SIZE];
    let report = kernel_sys::prog_load_dryrun_report(kernel_sys::ProgLoadDryRunOptions {
        prog_type: context.prog_type,
        expected_attach_type: context.expected_attach_type,
        prog_flags: context.prog_flags,
        prog_btf_fd: prog_btf_fd.raw_fd,
        attach_btf_id: nonzero(context.attach_btf_id),
        attach_btf_obj_fd: attach_btf_obj_fd.raw_fd,
        func_info: None,
        line_info: None,
        insns,
        fd_array: (!fd_array.is_empty()).then_some(fd_array),
        log_level: 2,
        log_buf: Some(log_buf.as_mut_slice()),
    })
    .context("BPF_PROG_LOAD thin dry-run failed")?;

    if !report.accepted {
        let errno = report
            .errno
            .map(|errno| errno.to_string())
            .unwrap_or_else(|| "unknown".to_string());
        bail!(
            "thin verifier dry-run rejected original bytecode (errno {errno}): verifier log summary:\n{}",
            kernel_sys::verifier_log_summary(&report.verifier_log)
        );
    }
    let states = kernel_sys::verifier_states_from_log(&report.verifier_log);
    if !report.verifier_log.trim().is_empty() && states.insns.is_empty() {
        bail!("thin verifier dry-run log did not contain parseable state snapshots");
    }
    Ok(states)
}

fn open_optional_btf_fd(id: u32, label: &str) -> Result<BtfFd> {
    if id == 0 {
        return Ok(BtfFd {
            raw_fd: None,
            _owned: None,
        });
    }
    let fd = kernel_sys::btf_get_fd_by_id(id).with_context(|| format!("open {label} id {id}"))?;
    let raw_fd = fd.as_raw_fd();
    Ok(BtfFd {
        raw_fd: Some(raw_fd),
        _owned: Some(fd),
    })
}

fn nonzero(value: u32) -> Option<u32> {
    (value != 0).then_some(value)
}

fn run_with_timeout<T, F>(stage: &'static str, timeout: Duration, task: F) -> Result<T>
where
    T: Send + 'static,
    F: FnOnce() -> Result<T> + Send + 'static,
{
    let (sender, receiver) = mpsc::sync_channel(1);
    thread::Builder::new()
        .name(format!("bpfrejit-{stage}"))
        .spawn(move || {
            let result = std::panic::catch_unwind(std::panic::AssertUnwindSafe(task))
                .map_err(|payload| anyhow!("{stage} panicked: {}", panic_payload_message(payload)))
                .and_then(|result| result);
            if sender.send(result).is_err() {
                eprintln!("daemon: {stage} completed after caller timed out; dropping result");
            }
        })
        .with_context(|| format!("spawn timeout thread for {stage}"))?;

    match receiver.recv_timeout(timeout) {
        Ok(result) => result,
        Err(mpsc::RecvTimeoutError::Timeout) => bail!(
            "{stage} timed out after {}; verifier thread left detached",
            duration_label(timeout)
        ),
        Err(mpsc::RecvTimeoutError::Disconnected) => {
            bail!("{stage} worker exited without returning a result")
        }
    }
}

fn panic_payload_message(payload: Box<dyn std::any::Any + Send>) -> String {
    if let Some(message) = payload.downcast_ref::<String>() {
        return message.clone();
    }
    if let Some(message) = payload.downcast_ref::<&'static str>() {
        return (*message).to_string();
    }
    "non-string panic payload".to_string()
}

fn duration_label(duration: Duration) -> String {
    let millis = duration.as_millis();
    if millis < 1_000 {
        format!("{millis}ms")
    } else {
        format!("{}s", duration.as_secs())
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::time::Instant;

    #[test]
    fn timeout_returns_without_waiting_for_worker() {
        let (release_sender, release_receiver) = mpsc::channel();
        let started = Instant::now();
        let err = run_with_timeout("test dry-run", Duration::from_millis(20), move || {
            release_receiver
                .recv()
                .context("wait for test release signal")?;
            Ok(())
        })
        .unwrap_err();

        assert!(
            started.elapsed() < Duration::from_secs(1),
            "timeout waited too long before returning"
        );
        assert!(err.to_string().contains("timed out after 20ms"));
        release_sender.send(()).unwrap();
    }

    #[test]
    fn zero_ids_do_not_open_btf_fds() {
        let fd = open_optional_btf_fd(0, "test").unwrap();
        assert!(fd.raw_fd.is_none());
    }
}
