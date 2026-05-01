// SPDX-License-Identifier: MIT
//! bpfrejit CLI entry point.

use std::collections::HashMap;
use std::fs;
use std::io::{self, Read, Write};
use std::os::fd::{AsFd, AsRawFd, OwnedFd};
use std::path::{Path, PathBuf};
use std::process::ExitCode;

use anyhow::{anyhow, bail, Context, Result};
use clap::Parser;
use kernel_sys::FdArray;
use serde::Serialize;

const LOG_BUF_SIZE: usize = 16 * 1024 * 1024;
const BPF_LD_IMM64: u8 = (kernel_sys::BPF_LD | kernel_sys::BPF_DW | kernel_sys::BPF_IMM) as u8;
const BPF_PSEUDO_MAP_FD: u8 = kernel_sys::BPF_PSEUDO_MAP_FD as u8;
const BPF_PSEUDO_MAP_VALUE: u8 = kernel_sys::BPF_PSEUDO_MAP_VALUE as u8;
const BPF_PSEUDO_MAP_IDX: u8 = kernel_sys::BPF_PSEUDO_MAP_IDX as u8;
const BPF_PSEUDO_MAP_IDX_VALUE: u8 = kernel_sys::BPF_PSEUDO_MAP_IDX_VALUE as u8;

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
    /// Map FD manifest from bpfget --full.
    #[arg(long, value_name = "FILE")]
    map_fds: Option<PathBuf>,
    /// Optional summary JSON output file.
    #[arg(long, value_name = "FILE")]
    output: Option<PathBuf>,
}

#[derive(Debug)]
struct MapBinding {
    old_fd: Option<i32>,
    map_id: u32,
}

#[derive(Debug, Serialize)]
struct Summary {
    status: String,
    prog_id: u32,
    insn_count_before: usize,
    insn_count_after: usize,
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

    let mut insns = read_bytecode(cli.file.as_deref())?;
    let _map_fds = apply_map_fds(cli.map_fds.as_deref(), &mut insns)?;
    let fd_array = read_fd_array(cli.fd_array.as_deref())?;

    let prog_fd = kernel_sys::prog_get_fd_by_id(cli.prog_id)
        .with_context(|| format!("open BPF program id {}", cli.prog_id))?;
    let info = kernel_sys::obj_get_info_by_fd(prog_fd.as_fd())
        .with_context(|| format!("read info for BPF program id {}", cli.prog_id))?;
    let insn_count_before = current_insn_count(&info);

    let mut log_buf = vec![0u8; LOG_BUF_SIZE];
    kernel_sys::prog_rejit(
        prog_fd.as_fd(),
        &insns,
        fd_array.as_slice(),
        Some(&mut log_buf),
    )
    .context("kernel rejected BPF_PROG_REJIT")?;
    write_summary(
        cli.output.as_deref(),
        &Summary {
            status: "ok".to_string(),
            prog_id: cli.prog_id,
            insn_count_before,
            insn_count_after: insns.len(),
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

fn apply_map_fds(path: Option<&Path>, insns: &mut [kernel_sys::bpf_insn]) -> Result<Vec<OwnedFd>> {
    let Some(path) = path else {
        return Ok(Vec::new());
    };
    let bindings = read_map_bindings(path)?;
    let old_fds = pseudo_map_old_fds(insns);
    let mut old_fd_to_map_id = HashMap::new();

    for binding in bindings.iter().filter(|binding| binding.old_fd.is_some()) {
        old_fd_to_map_id.insert(binding.old_fd.unwrap(), binding.map_id);
    }
    let positional_old_fd_map_ids = bindings
        .iter()
        .filter(|binding| binding.old_fd.is_none())
        .map(|binding| binding.map_id)
        .collect::<Vec<_>>();
    let indexed_map_ids = bindings
        .iter()
        .map(|binding| binding.map_id)
        .collect::<Vec<_>>();
    for (idx, old_fd) in old_fds.iter().copied().enumerate() {
        if old_fd_to_map_id.contains_key(&old_fd) {
            continue;
        }
        let Some(&map_id) = positional_old_fd_map_ids.get(idx) else {
            bail!(
                "{} does not provide a map_id for pseudo-map old fd {}",
                path.display(),
                old_fd
            );
        };
        old_fd_to_map_id.insert(old_fd, map_id);
    }

    let mut opened = HashMap::<u32, OwnedFd>::new();
    let mut pc = 0usize;
    while pc < insns.len() {
        if is_pseudo_map_fd_ldimm64(&insns[pc]) {
            let old_fd = insns[pc].imm;
            let map_id = *old_fd_to_map_id
                .get(&old_fd)
                .ok_or_else(|| anyhow!("no map binding for pseudo-map old fd {old_fd}"))?;
            let new_fd = open_map_fd(&mut opened, map_id, path)?.as_raw_fd();
            insns[pc].imm = new_fd;
            pc += 2;
        } else if is_pseudo_map_idx_ldimm64(&insns[pc]) {
            let raw_idx = insns[pc].imm;
            if raw_idx < 0 {
                bail!("pseudo-map fd_array index {raw_idx} is negative");
            }
            let idx = raw_idx as usize;
            let Some(&map_id) = indexed_map_ids.get(idx) else {
                bail!(
                    "{} does not provide a map_id for pseudo-map fd_array index {}",
                    path.display(),
                    idx
                );
            };
            let new_fd = open_map_fd(&mut opened, map_id, path)?.as_raw_fd();
            let src_reg = if insns[pc].src_reg() == BPF_PSEUDO_MAP_IDX {
                BPF_PSEUDO_MAP_FD
            } else {
                BPF_PSEUDO_MAP_VALUE
            };
            insns[pc].set_src_reg(src_reg);
            insns[pc].imm = new_fd;
            pc += 2;
        } else {
            pc += 1;
        }
    }

    Ok(opened.into_values().collect())
}

fn open_map_fd<'a>(
    opened: &'a mut HashMap<u32, OwnedFd>,
    map_id: u32,
    path: &Path,
) -> Result<&'a OwnedFd> {
    match opened.entry(map_id) {
        std::collections::hash_map::Entry::Occupied(entry) => Ok(entry.into_mut()),
        std::collections::hash_map::Entry::Vacant(entry) => {
            Ok(entry
                .insert(kernel_sys::map_get_fd_by_id(map_id).with_context(|| {
                    format!("open BPF map id {map_id} from {}", path.display())
                })?))
        }
    }
}

fn pseudo_map_old_fds(insns: &[kernel_sys::bpf_insn]) -> Vec<i32> {
    let mut old_fds = Vec::new();
    let mut pc = 0usize;
    while pc < insns.len() {
        if is_pseudo_map_fd_ldimm64(&insns[pc]) {
            let old_fd = insns[pc].imm;
            if !old_fds.contains(&old_fd) {
                old_fds.push(old_fd);
            }
            pc += 2;
        } else {
            pc += 1;
        }
    }
    old_fds
}

fn is_pseudo_map_fd_ldimm64(insn: &kernel_sys::bpf_insn) -> bool {
    insn.code == BPF_LD_IMM64 && matches!(insn.src_reg(), BPF_PSEUDO_MAP_FD | BPF_PSEUDO_MAP_VALUE)
}

fn is_pseudo_map_idx_ldimm64(insn: &kernel_sys::bpf_insn) -> bool {
    insn.code == BPF_LD_IMM64
        && matches!(
            insn.src_reg(),
            BPF_PSEUDO_MAP_IDX | BPF_PSEUDO_MAP_IDX_VALUE
        )
}

fn read_map_bindings(path: &Path) -> Result<Vec<MapBinding>> {
    let text =
        fs::read_to_string(path).with_context(|| format!("failed to read {}", path.display()))?;
    let value: serde_json::Value = serde_json::from_str(&text)
        .with_context(|| format!("failed to parse map_fds JSON {}", path.display()))?;
    let rows = if let Some(array) = value.as_array() {
        array.clone()
    } else if let Some(array) = value.get("maps").and_then(|v| v.as_array()) {
        array.clone()
    } else if let Some(array) = value.get("map_ids").and_then(|v| v.as_array()) {
        array
            .iter()
            .map(|map_id| serde_json::json!({ "map_id": map_id }))
            .collect()
    } else {
        bail!(
            "{} must be an array or contain maps/map_ids",
            path.display()
        );
    };

    rows.into_iter()
        .enumerate()
        .map(|(idx, row)| {
            let map_id = row
                .get("map_id")
                .and_then(|v| v.as_u64())
                .ok_or_else(|| anyhow!("map_fds entry {idx} is missing map_id"))?;
            let old_fd = row.get("old_fd").and_then(|v| v.as_i64());
            Ok(MapBinding {
                old_fd: old_fd.map(|fd| fd as i32),
                map_id: u32::try_from(map_id)
                    .with_context(|| format!("map_fds entry {idx} map_id out of range"))?,
            })
        })
        .collect()
}

fn read_fd_array(path: Option<&Path>) -> Result<FdArray> {
    let Some(path) = path else {
        return Ok(FdArray::empty());
    };
    FdArray::from_json_file(path)
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
}
