// SPDX-License-Identifier: MIT
//! bpfrejit CLI entry point.

use std::fs;
use std::io::{self, Read, Write};
use std::os::fd::AsFd;
use std::path::{Path, PathBuf};
use std::process::ExitCode;

use anyhow::{anyhow, bail, Context, Result};
use clap::Parser;
use serde::{Deserialize, Serialize};

const LOG_BUF_SIZE: usize = 1024 * 1024;

#[derive(Parser, Debug)]
#[command(name = "bpfrejit", version, about = "Submit replacement BPF bytecode")]
struct Cli {
    /// Live BPF program ID.
    #[arg(value_name = "PROG_ID")]
    prog_id: u32,
    /// Raw struct bpf_insn[] input file. Defaults to stdin.
    #[arg(value_name = "FILE")]
    file: Option<PathBuf>,
    /// kinsn fd_array JSON manifest.
    #[arg(long, value_name = "FILE")]
    fd_array: Option<PathBuf>,
    /// Verify the bytecode with BPF_PROG_LOAD and do not call BPF_PROG_REJIT.
    #[arg(long)]
    dry_run: bool,
    /// Optional summary JSON output file.
    #[arg(long, value_name = "FILE")]
    output: Option<PathBuf>,
}

#[derive(Debug, Deserialize)]
struct FdArrayEntry {
    slot: Option<usize>,
    name: Option<String>,
    btf_fd: Option<i32>,
    btf_id: Option<u32>,
    btf_obj_id: Option<u32>,
    btf_module: Option<String>,
}

#[derive(Debug, Serialize)]
struct Summary {
    status: String,
    prog_id: u32,
    insn_count_before: usize,
    insn_count_after: usize,
    dry_run: bool,
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

    let insns = read_bytecode(cli.file.as_deref())?;
    let fd_array = read_fd_array(cli.fd_array.as_deref())?;

    let prog_fd = kernel_sys::prog_get_fd_by_id(cli.prog_id)
        .with_context(|| format!("open BPF program id {}", cli.prog_id))?;
    let info = kernel_sys::obj_get_info_by_fd(prog_fd.as_fd())
        .with_context(|| format!("read info for BPF program id {}", cli.prog_id))?;
    let insn_count_before = current_insn_count(&info);

    let mut log_buf = vec![0u8; LOG_BUF_SIZE];
    if cli.dry_run {
        kernel_sys::prog_load_dryrun_with_fd_array(
            info.prog_type,
            &insns,
            Some(&fd_array),
            Some(&mut log_buf),
        )
        .context("dry-run verifier rejected bytecode")?;
        return write_summary(
            cli.output.as_deref(),
            &Summary {
                status: "dry-run pass".to_string(),
                prog_id: cli.prog_id,
                insn_count_before,
                insn_count_after: insns.len(),
                dry_run: true,
            },
        );
    }

    kernel_sys::prog_rejit(prog_fd.as_fd(), &insns, &fd_array, Some(&mut log_buf))
        .context("kernel rejected BPF_PROG_REJIT")?;
    write_summary(
        cli.output.as_deref(),
        &Summary {
            status: "ok".to_string(),
            prog_id: cli.prog_id,
            insn_count_before,
            insn_count_after: insns.len(),
            dry_run: false,
        },
    )
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

fn read_bytecode(input: Option<&Path>) -> Result<Vec<kernel_sys::bpf_insn>> {
    let mut bytes = Vec::new();
    match input {
        Some(path) => {
            bytes = fs::read(path).with_context(|| format!("failed to read {}", path.display()))?;
        }
        None => {
            io::stdin()
                .lock()
                .read_to_end(&mut bytes)
                .context("failed to read stdin")?;
        }
    }
    parse_bytecode(&bytes)
}

fn parse_bytecode(bytes: &[u8]) -> Result<Vec<kernel_sys::bpf_insn>> {
    if bytes.is_empty() {
        bail!("input bytecode is empty");
    }
    if !bytes
        .len()
        .is_multiple_of(std::mem::size_of::<kernel_sys::bpf_insn>())
    {
        bail!(
            "input bytecode length {} is not a multiple of 8",
            bytes.len()
        );
    }

    Ok(bytes
        .chunks_exact(8)
        .map(|chunk| {
            let mut insn = kernel_sys::bpf_insn {
                code: chunk[0],
                _bitfield_align_1: [],
                _bitfield_1: Default::default(),
                off: i16::from_le_bytes([chunk[2], chunk[3]]),
                imm: i32::from_le_bytes([chunk[4], chunk[5], chunk[6], chunk[7]]),
            };
            insn.set_dst_reg(chunk[1] & 0x0f);
            insn.set_src_reg((chunk[1] >> 4) & 0x0f);
            insn
        })
        .collect())
}

fn read_fd_array(path: Option<&Path>) -> Result<Vec<i32>> {
    let Some(path) = path else {
        return Ok(Vec::new());
    };
    let text =
        fs::read_to_string(path).with_context(|| format!("failed to read {}", path.display()))?;
    let entries: Vec<FdArrayEntry> = serde_json::from_str(&text)
        .with_context(|| format!("failed to parse fd_array JSON {}", path.display()))?;
    let required = required_btf_fds(&entries)?;
    Ok(build_rejit_fd_array(&required))
}

fn required_btf_fds(entries: &[FdArrayEntry]) -> Result<Vec<i32>> {
    if entries.is_empty() {
        return Ok(Vec::new());
    }

    let has_slots = entries.iter().any(|entry| entry.slot.is_some());
    let has_missing_slots = entries.iter().any(|entry| entry.slot.is_none());
    if has_slots && has_missing_slots {
        bail!("fd_array entries must either all specify slot or all omit slot");
    }

    let mut rows = Vec::with_capacity(entries.len());
    for (index, entry) in entries.iter().enumerate() {
        let label = entry
            .name
            .as_deref()
            .map(|name| format!(" ({name})"))
            .unwrap_or_default();
        if entry.btf_id.is_some() || entry.btf_obj_id.is_some() || entry.btf_module.is_some() {
            bail!(
                "fd_array entry {}{} uses btf_id/btf_obj_id/btf_module, but this CLI stage only supports inherited btf_fd",
                index,
                label
            );
        }
        let btf_fd = entry
            .btf_fd
            .ok_or_else(|| anyhow!("fd_array entry {index}{label} is missing btf_fd"))?;
        if btf_fd < 0 {
            bail!("fd_array entry {index}{label} has negative btf_fd {btf_fd}");
        }
        let slot = entry.slot.unwrap_or(index + 1);
        if slot == 0 {
            bail!("fd_array entry {index}{label} uses invalid slot 0");
        }
        rows.push((slot, btf_fd));
    }

    rows.sort_by_key(|(slot, _)| *slot);
    let mut out = Vec::with_capacity(rows.len());
    for (expected, (slot, btf_fd)) in (1usize..).zip(rows) {
        if slot != expected {
            bail!(
                "fd_array slots must be dense starting at 1; expected slot {expected}, got {slot}"
            );
        }
        out.push(btf_fd);
    }
    Ok(out)
}

fn build_rejit_fd_array(required_btf_fds: &[i32]) -> Vec<i32> {
    if required_btf_fds.is_empty() {
        return Vec::new();
    }

    let mut fd_array = Vec::with_capacity(required_btf_fds.len() + 1);
    fd_array.push(required_btf_fds[0]);
    fd_array.extend_from_slice(required_btf_fds);
    fd_array
}

fn write_summary(output: Option<&Path>, summary: &Summary) -> Result<()> {
    let stderr_line = serde_json::to_string(summary)?;
    eprintln!("{stderr_line}");

    if let Some(path) = output {
        let mut file = fs::File::create(path)
            .with_context(|| format!("failed to create {}", path.display()))?;
        serde_json::to_writer_pretty(&mut file, summary)?;
        writeln!(file)?;
        file.flush()?;
    }

    Ok(())
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn parse_bytecode_rejects_non_instruction_multiple() {
        let err = parse_bytecode(&[0u8; 9]).unwrap_err();
        assert!(err.to_string().contains("multiple of 8"), "err={err:#}");
    }

    #[test]
    fn fd_array_reserves_slot_zero_with_duplicate_valid_fd() {
        let entries = vec![
            FdArrayEntry {
                slot: Some(1),
                name: Some("bpf_rotate64".to_string()),
                btf_fd: Some(11),
                btf_id: None,
                btf_obj_id: None,
                btf_module: None,
            },
            FdArrayEntry {
                slot: Some(2),
                name: Some("bpf_select64".to_string()),
                btf_fd: Some(22),
                btf_id: None,
                btf_obj_id: None,
                btf_module: None,
            },
        ];

        let required = required_btf_fds(&entries).expect("required fds");
        assert_eq!(build_rejit_fd_array(&required), vec![11, 11, 22]);
    }

    #[test]
    fn fd_array_rejects_holes() {
        let entries = vec![FdArrayEntry {
            slot: Some(2),
            name: None,
            btf_fd: Some(11),
            btf_id: None,
            btf_obj_id: None,
            btf_module: None,
        }];

        let err = required_btf_fds(&entries).unwrap_err();
        assert!(err.to_string().contains("dense"), "err={err:#}");
    }
}
