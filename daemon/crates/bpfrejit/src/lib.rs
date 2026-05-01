// SPDX-License-Identifier: MIT
//! In-process `BPF_PROG_REJIT` support for `bpfrejit-daemon`.

use std::os::fd::AsFd;

use anyhow::{Context, Result};
use serde::Serialize;

const LOG_BUF_SIZE: usize = 16 * 1024 * 1024;

#[derive(Debug, Serialize, PartialEq, Eq)]
pub struct RejitSummary {
    pub status: String,
    pub prog_id: u32,
    pub insn_count_before: usize,
    pub insn_count_after: usize,
}

pub fn rejit_program(
    prog_id: u32,
    insns: &[kernel_sys::bpf_insn],
    fd_array: &[i32],
) -> Result<RejitSummary> {
    let prog_fd = kernel_sys::prog_get_fd_by_id(prog_id)
        .with_context(|| format!("open BPF program id {prog_id}"))?;
    let info = kernel_sys::obj_get_info_by_fd(prog_fd.as_fd())
        .with_context(|| format!("read info for BPF program id {prog_id}"))?;
    let insn_count_before = current_insn_count(&info);

    let mut log_buf = vec![0u8; LOG_BUF_SIZE];
    kernel_sys::prog_rejit(prog_fd.as_fd(), insns, fd_array, Some(&mut log_buf))
        .context("kernel rejected BPF_PROG_REJIT")?;

    Ok(RejitSummary {
        status: "ok".to_string(),
        prog_id,
        insn_count_before,
        insn_count_after: insns.len(),
    })
}

fn current_insn_count(info: &kernel_sys::BpfProgInfoFork) -> usize {
    let insn_size = std::mem::size_of::<kernel_sys::bpf_insn>();
    let byte_len = if info.orig_prog_len != 0 {
        info.orig_prog_len
    } else {
        info.xlated_prog_len
    };
    byte_len as usize / insn_size
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn current_insn_count_prefers_original_bytecode_length() {
        let info = kernel_sys::BpfProgInfoFork {
            orig_prog_len: 24,
            xlated_prog_len: 16,
            ..Default::default()
        };

        assert_eq!(current_insn_count(&info), 3);
    }

    #[test]
    fn current_insn_count_uses_xlated_len_when_original_is_absent() {
        let info = kernel_sys::BpfProgInfoFork {
            orig_prog_len: 0,
            xlated_prog_len: 16,
            ..Default::default()
        };

        assert_eq!(current_insn_count(&info), 2);
    }
}
