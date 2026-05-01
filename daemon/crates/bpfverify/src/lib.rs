// SPDX-License-Identifier: MIT
//! In-process verifier dry-run support for `bpfrejit-daemon`.

mod verifier_log;

use std::collections::BTreeMap;
use std::os::fd::{AsRawFd, OwnedFd};

use anyhow::{anyhow, bail, Context, Result};
use kernel_sys::{VerifierInsnJson, VerifierRegJson, VerifierStatesJson};
use serde::Serialize;

const DEFAULT_LOG_BUF_SIZE: usize = 16 * 1024 * 1024;
const MAX_LOG_BUF_SIZE: usize = 256 * 1024 * 1024;

#[derive(Clone, Copy, Debug)]
pub struct BtfRecords<'a> {
    pub rec_size: u32,
    pub bytes: &'a [u8],
}

#[derive(Clone, Copy, Debug)]
pub struct ProgramLoadContext<'a> {
    pub prog_type: kernel_sys::bpf_prog_type,
    pub expected_attach_type: Option<kernel_sys::bpf_attach_type>,
    pub prog_flags: u32,
    pub prog_btf_id: u32,
    pub attach_btf_id: u32,
    pub attach_btf_obj_id: u32,
    pub func_info: Option<BtfRecords<'a>>,
    pub line_info: Option<BtfRecords<'a>>,
}

#[derive(Clone, Copy, Debug)]
pub struct VerifyRequest<'a> {
    pub context: ProgramLoadContext<'a>,
    pub insns: &'a [kernel_sys::bpf_insn],
    pub fd_array: &'a [i32],
    pub log_level: u32,
}

#[derive(Clone, Debug, Serialize)]
pub struct VerifyReport {
    pub status: &'static str,
    pub verifier_log: String,
    pub verifier_states: VerifierStatesJson,
    pub insn_count: usize,
    pub log_level: u32,
    #[serde(skip_serializing_if = "Option::is_none")]
    pub errno: Option<i32>,
    #[serde(skip_serializing_if = "Option::is_none")]
    pub jited_size: Option<u32>,
    #[serde(skip_serializing_if = "is_zero")]
    pub log_true_size: u32,
}

pub fn verify(request: VerifyRequest<'_>) -> Result<VerifyReport> {
    if request.log_level > 2 {
        bail!("verifier log_level must be 0, 1, or 2");
    }
    validate_required_load_metadata(&request.context)?;
    let prog_btf_fd = resolve_optional_btf_fd(
        request.context.prog_btf_id,
        "prog BTF",
        prog_type_requires_prog_btf(request.context.prog_type),
    )?;
    let attach_btf_obj_fd = resolve_optional_btf_fd(
        request.context.attach_btf_obj_id,
        "attach BTF object",
        false,
    )?;

    let mut log_buf_size = DEFAULT_LOG_BUF_SIZE;
    let dryrun = loop {
        let mut log_buf = if request.log_level > 0 {
            vec![0u8; log_buf_size]
        } else {
            Vec::new()
        };
        let report = kernel_sys::prog_load_dryrun_report(kernel_sys::ProgLoadDryRunOptions {
            prog_type: request.context.prog_type,
            expected_attach_type: request.context.expected_attach_type,
            prog_flags: request.context.prog_flags,
            prog_btf_fd: prog_btf_fd.fd,
            attach_btf_id: nonzero_u32(request.context.attach_btf_id),
            attach_btf_obj_fd: attach_btf_obj_fd.fd,
            func_info: request
                .context
                .func_info
                .map(|records| kernel_sys::BtfInfoRecords {
                    rec_size: records.rec_size,
                    bytes: records.bytes,
                }),
            line_info: request
                .context
                .line_info
                .map(|records| kernel_sys::BtfInfoRecords {
                    rec_size: records.rec_size,
                    bytes: records.bytes,
                }),
            insns: request.insns,
            fd_array: (!request.fd_array.is_empty()).then_some(request.fd_array),
            log_level: request.log_level,
            log_buf: if request.log_level > 0 {
                Some(log_buf.as_mut_slice())
            } else {
                None
            },
        })
        .context("BPF_PROG_LOAD dry-run failed")?;

        if request.log_level > 0 && report.errno == Some(libc::ENOSPC) {
            if let Some(next_size) = next_log_buf_size(log_buf_size, report.log_true_size)? {
                log_buf_size = next_size;
                continue;
            }
        }
        break report;
    };

    let verifier_states = verifier_states_from_log(&dryrun.verifier_log)?;
    Ok(VerifyReport {
        status: if dryrun.accepted { "pass" } else { "fail" },
        verifier_log: dryrun.verifier_log,
        verifier_states,
        insn_count: request.insns.len(),
        log_level: request.log_level,
        errno: dryrun.errno,
        jited_size: dryrun.jited_size,
        log_true_size: dryrun.log_true_size,
    })
}

pub fn verify_pass(request: VerifyRequest<'_>) -> Result<VerifyReport> {
    let report = verify(request)?;
    if report.status != "pass" {
        let errno = report
            .errno
            .map(|errno| errno.to_string())
            .unwrap_or_else(|| "unknown".to_string());
        bail!(
            "verifier rejected bytecode (errno {errno}): verifier log summary:\n{}",
            verifier_log_summary(&report.verifier_log)
        );
    }
    Ok(report)
}

pub fn verifier_states(request: VerifyRequest<'_>) -> Result<VerifierStatesJson> {
    let request = VerifyRequest {
        log_level: 2,
        ..request
    };
    let report = verify_pass(request)?;
    ensure_verifier_states_parseable(&report.verifier_log, &report.verifier_states)?;
    Ok(report.verifier_states)
}

pub fn verifier_states_from_log(log: &str) -> Result<VerifierStatesJson> {
    let parsed = verifier_log::parse_verifier_log(log);
    Ok(convert_verifier_states(&parsed))
}

fn ensure_verifier_states_parseable(log: &str, states: &VerifierStatesJson) -> Result<()> {
    if !log.trim().is_empty() && states.insns.is_empty() {
        bail!("verifier log did not contain parseable state snapshots");
    }
    Ok(())
}

struct AttachBtfObjFd {
    fd: Option<i32>,
    _owned_fd: Option<OwnedFd>,
}

fn resolve_optional_btf_fd(id: u32, label: &str, required: bool) -> Result<AttachBtfObjFd> {
    if id == 0 {
        if required {
            bail!("{label}: required BTF id is zero");
        }
        return Ok(AttachBtfObjFd {
            fd: None,
            _owned_fd: None,
        });
    }
    let owned_fd =
        kernel_sys::btf_get_fd_by_id(id).with_context(|| format!("open {label} id {id}"))?;
    let fd = owned_fd.as_raw_fd();
    Ok(AttachBtfObjFd {
        fd: Some(fd),
        _owned_fd: Some(owned_fd),
    })
}

fn next_log_buf_size(current: usize, log_true_size: u32) -> Result<Option<usize>> {
    if current == 0 {
        bail!("verifier log retry requires a non-zero current buffer size");
    }
    if current >= MAX_LOG_BUF_SIZE {
        return Ok(None);
    }

    let doubled = current.checked_mul(2).unwrap_or(MAX_LOG_BUF_SIZE);
    let requested_by_kernel = if log_true_size == 0 {
        current
    } else {
        usize::try_from(log_true_size)
            .map_err(|_| anyhow!("kernel verifier log_true_size does not fit usize"))?
            .checked_add(1)
            .ok_or_else(|| anyhow!("kernel verifier log_true_size overflow"))?
    };
    let next = doubled.max(requested_by_kernel).min(MAX_LOG_BUF_SIZE);
    Ok((next > current).then_some(next))
}

fn validate_required_load_metadata(context: &ProgramLoadContext<'_>) -> Result<()> {
    if prog_type_requires_prog_btf(context.prog_type) && context.prog_btf_id == 0 {
        bail!(
            "prog type {} requires replaying non-zero prog BTF metadata",
            context.prog_type
        );
    }
    if prog_type_requires_attach_btf(context.prog_type) && context.attach_btf_id == 0 {
        bail!(
            "prog type {} requires replaying non-zero attach_btf_id metadata",
            context.prog_type
        );
    }
    if prog_type_requires_expected_attach_type(context.prog_type)
        && context.expected_attach_type.is_none()
    {
        bail!(
            "prog type {} requires replaying expected_attach_type metadata",
            context.prog_type
        );
    }
    Ok(())
}

fn prog_type_requires_prog_btf(prog_type: kernel_sys::bpf_prog_type) -> bool {
    matches!(
        prog_type,
        kernel_sys::BPF_PROG_TYPE_KPROBE
            | kernel_sys::BPF_PROG_TYPE_TRACING
            | kernel_sys::BPF_PROG_TYPE_LSM
            | kernel_sys::BPF_PROG_TYPE_EXT
    )
}

fn prog_type_requires_attach_btf(prog_type: kernel_sys::bpf_prog_type) -> bool {
    matches!(
        prog_type,
        kernel_sys::BPF_PROG_TYPE_TRACING
            | kernel_sys::BPF_PROG_TYPE_LSM
            | kernel_sys::BPF_PROG_TYPE_STRUCT_OPS
            | kernel_sys::BPF_PROG_TYPE_EXT
    )
}

fn prog_type_requires_expected_attach_type(prog_type: kernel_sys::bpf_prog_type) -> bool {
    matches!(
        prog_type,
        kernel_sys::BPF_PROG_TYPE_TRACING | kernel_sys::BPF_PROG_TYPE_LSM
    )
}

fn nonzero_u32(value: u32) -> Option<u32> {
    (value != 0).then_some(value)
}

fn convert_verifier_states(states: &[verifier_log::VerifierInsn]) -> VerifierStatesJson {
    let has_delta = states
        .iter()
        .any(|state| state.kind == verifier_log::VerifierInsnKind::InsnDeltaState);
    let insns = states
        .iter()
        .filter(|state| state.kind != verifier_log::VerifierInsnKind::BranchDeltaState)
        .filter(|state| !has_delta || state.kind == verifier_log::VerifierInsnKind::InsnDeltaState)
        .filter_map(convert_verifier_state)
        .collect();
    VerifierStatesJson { insns }
}

fn convert_verifier_state(state: &verifier_log::VerifierInsn) -> Option<VerifierInsnJson> {
    let regs = state
        .regs
        .iter()
        .filter_map(|(&regno, reg)| convert_reg_state(reg).map(|reg| (format!("r{regno}"), reg)))
        .collect::<BTreeMap<_, _>>();
    (!regs.is_empty()).then_some(VerifierInsnJson {
        pc: state.pc,
        frame: state.frame,
        regs,
    })
}

fn convert_reg_state(reg: &verifier_log::RegState) -> Option<VerifierRegJson> {
    let const_val = reg
        .exact_u64()
        .or_else(|| reg.exact_u32().map(u64::from))
        .map(|value| value as i64);
    let (min, max) = if let (Some(min), Some(max)) = (reg.range.umin, reg.range.umax) {
        if min <= i64::MAX as u64 && max <= i64::MAX as u64 {
            (Some(min as i64), Some(max as i64))
        } else {
            (reg.range.smin, reg.range.smax)
        }
    } else {
        (reg.range.smin, reg.range.smax)
    };
    let tnum = reg
        .tnum
        .map(|tnum| format!("0x{:x}/0x{:x}", tnum.value, tnum.mask));

    (reg.offset.is_some()
        || const_val.is_some()
        || min.is_some()
        || max.is_some()
        || tnum.is_some())
    .then_some(VerifierRegJson {
        reg_type: reg.reg_type.clone(),
        offset: reg.offset,
        const_val,
        min,
        max,
        tnum,
    })
}

fn verifier_log_summary(log: &str) -> String {
    let trimmed = log.trim();
    if trimmed.is_empty() {
        return "<empty verifier log>".to_string();
    }
    const MAX_SUMMARY_CHARS: usize = 4096;
    let mut chars = trimmed.chars();
    let summary: String = chars.by_ref().take(MAX_SUMMARY_CHARS).collect();
    if chars.next().is_some() {
        format!("{summary}\n... verifier log truncated ...")
    } else {
        summary
    }
}

fn is_zero(value: &u32) -> bool {
    *value == 0
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn verifier_states_capture_is_in_process_log_conversion() {
        let states = verifier_states_from_log(
            r#"
0: R1=ctx() R10=fp0
1: (b7) r2 = 42                       ; R2=42
2: (07) r2 += 1                       ; R2=scalar(umin=42,umax=43,var_off=(0x2a; 0x1))
"#,
        )
        .unwrap();

        assert_eq!(states.insns.len(), 2);
        assert_eq!(states.insns[0].pc, 1);
        let r2 = &states.insns[0].regs["r2"];
        assert_eq!(r2.reg_type, "scalar");
        assert_eq!(r2.const_val, Some(42));
        assert_eq!(states.insns[1].regs["r2"].tnum.as_deref(), Some("0x2a/0x1"));
    }

    #[test]
    fn verifier_state_conversion_drops_branch_delta_states() {
        let states = verifier_states_from_log(
            r#"
8: (85) call bpf_map_lookup_elem#1     ; R0=map_value_or_null(id=1)
9: (55) if r0 != 0x0 goto pc+1        ; R0=0 R2=0
from 9 to 11: R0=map_ptr(ks=4,vs=64) R10=fp0
11: (b7) r3 = 8                       ; R3=8
"#,
        )
        .unwrap();

        assert_eq!(
            states.insns.iter().map(|insn| insn.pc).collect::<Vec<_>>(),
            vec![11]
        );
        assert_eq!(states.insns[0].regs["r3"].const_val, Some(8));
    }

    #[test]
    fn verifier_log_retry_uses_kernel_true_size_when_available() {
        assert_eq!(next_log_buf_size(16, 100).unwrap(), Some(101));
    }

    #[test]
    fn verifier_log_retry_stops_at_configured_limit() {
        assert_eq!(next_log_buf_size(MAX_LOG_BUF_SIZE, 0).unwrap(), None);
        assert_eq!(
            next_log_buf_size(MAX_LOG_BUF_SIZE - 1, u32::MAX).unwrap(),
            Some(MAX_LOG_BUF_SIZE)
        );
    }

    #[test]
    fn required_load_metadata_rejects_missing_tracing_attach_context() {
        let context = ProgramLoadContext {
            prog_type: kernel_sys::BPF_PROG_TYPE_TRACING,
            expected_attach_type: None,
            prog_flags: 0,
            prog_btf_id: 10,
            attach_btf_id: 20,
            attach_btf_obj_id: 0,
            func_info: None,
            line_info: None,
        };

        let err = validate_required_load_metadata(&context).unwrap_err();

        assert!(
            err.to_string().contains("expected_attach_type"),
            "err={err:#}"
        );
    }
}
