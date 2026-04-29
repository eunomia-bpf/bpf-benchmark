// SPDX-License-Identifier: MIT
//! Small BPF access adapter for daemon watch/invalidation paths.
//!
//! The daemon does not own verifier, optimization, profiling, or ReJIT logic in
//! v3. Standard BPF access is routed through `kernel-sys`/libbpf; only the CLI
//! tools invoke fork-specific commands such as `BPF_PROG_REJIT`.

use std::os::fd::{BorrowedFd, OwnedFd, RawFd};
use std::sync::OnceLock;

use anyhow::{bail, Context, Result};

pub type BpfMapInfo = kernel_sys::bpf_map_info;

pub fn bpf_map_get_info(fd: RawFd) -> Result<BpfMapInfo> {
    let borrowed = unsafe { BorrowedFd::borrow_raw(fd) };
    kernel_sys::map_obj_get_info_by_fd(borrowed)
        .with_context(|| format!("read info for BPF map fd {fd}"))
}

pub fn bpf_map_get_fd_by_id(id: u32) -> Result<OwnedFd> {
    kernel_sys::map_get_fd_by_id(id).with_context(|| format!("open BPF map id {id}"))
}

pub fn bpf_map_lookup_elem_optional(
    fd: RawFd,
    key: &[u8],
    value_size: usize,
) -> Result<Option<Vec<u8>>> {
    let mut value = vec![0u8; value_size];
    let ret = unsafe {
        kernel_sys::bpf_map_lookup_elem(
            fd,
            key.as_ptr() as *const libc::c_void,
            value.as_mut_ptr() as *mut libc::c_void,
        )
    };

    if ret < 0 {
        let errno = libbpf_errno(ret);
        if errno == libc::ENOENT {
            return Ok(None);
        }
        bail!(
            "BPF_MAP_LOOKUP_ELEM fd {fd}: {}",
            std::io::Error::from_raw_os_error(errno)
        );
    }

    Ok(Some(value))
}

pub fn bpf_map_lookup_value_size(info: &BpfMapInfo) -> Result<usize> {
    if is_percpu_map_type(info.type_) {
        Ok(round_up_8(info.value_size as usize).saturating_mul(possible_cpu_count()?))
    } else {
        Ok(info.value_size as usize)
    }
}

fn is_percpu_map_type(map_type: u32) -> bool {
    matches!(
        map_type,
        kernel_sys::BPF_MAP_TYPE_PERCPU_HASH
            | kernel_sys::BPF_MAP_TYPE_PERCPU_ARRAY
            | kernel_sys::BPF_MAP_TYPE_LRU_PERCPU_HASH
    )
}

fn libbpf_errno(ret: libc::c_int) -> i32 {
    if ret < 0 {
        -ret
    } else {
        std::io::Error::last_os_error()
            .raw_os_error()
            .unwrap_or(libc::EIO)
    }
}

fn round_up_8(value: usize) -> usize {
    (value + 7) & !7
}

fn possible_cpu_count() -> Result<usize> {
    static POSSIBLE_CPU_COUNT: OnceLock<Result<usize, String>> = OnceLock::new();
    match POSSIBLE_CPU_COUNT
        .get_or_init(|| read_possible_cpu_count().map_err(|err| format!("{err:#}")))
    {
        Ok(count) => Ok(*count),
        Err(message) => bail!("{message}"),
    }
}

fn read_possible_cpu_count() -> Result<usize> {
    const POSSIBLE_CPU_PATH: &str = "/sys/devices/system/cpu/possible";
    let text = std::fs::read_to_string(POSSIBLE_CPU_PATH)
        .with_context(|| format!("read {POSSIBLE_CPU_PATH}"))?;
    parse_possible_cpu_list(&text)
        .with_context(|| format!("parse {POSSIBLE_CPU_PATH} contents {:?}", text.trim()))
}

fn parse_possible_cpu_list(text: &str) -> Result<usize> {
    let trimmed = text.trim();
    if trimmed.is_empty() {
        bail!("possible CPU list is empty");
    }

    let mut count = 0usize;
    for segment in trimmed.split(',').filter(|segment| !segment.is_empty()) {
        let parsed = if let Some((start, end)) = segment.split_once('-') {
            let start = start
                .trim()
                .parse::<usize>()
                .with_context(|| format!("invalid CPU range start in segment {segment:?}"))?;
            let end = end
                .trim()
                .parse::<usize>()
                .with_context(|| format!("invalid CPU range end in segment {segment:?}"))?;
            if end < start {
                bail!("descending CPU range segment {segment:?}");
            }
            end.checked_sub(start)
                .and_then(|span| span.checked_add(1))
                .with_context(|| format!("CPU range overflow in segment {segment:?}"))?
        } else {
            segment
                .trim()
                .parse::<usize>()
                .with_context(|| format!("invalid CPU id segment {segment:?}"))?;
            1
        };
        count = count
            .checked_add(parsed)
            .with_context(|| format!("CPU count overflow while parsing segment {segment:?}"))?;
    }
    if count == 0 {
        bail!("possible CPU list resolved to zero CPUs");
    }
    Ok(count)
}

pub struct ProgIdIter {
    next_start_id: u32,
    done: bool,
}

impl Iterator for ProgIdIter {
    type Item = Result<u32>;

    fn next(&mut self) -> Option<Self::Item> {
        if self.done {
            return None;
        }

        match kernel_sys::prog_get_next_id(self.next_start_id) {
            Ok(Some(prog_id)) => {
                self.next_start_id = prog_id;
                Some(Ok(prog_id))
            }
            Ok(None) => {
                self.done = true;
                None
            }
            Err(err) => {
                self.done = true;
                Some(Err(err).with_context(|| {
                    format!("enumerate BPF programs after id {}", self.next_start_id)
                }))
            }
        }
    }
}

pub fn iter_prog_ids() -> ProgIdIter {
    ProgIdIter {
        next_start_id: 0,
        done: false,
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn possible_cpu_list_counts_singletons_and_ranges() {
        assert_eq!(parse_possible_cpu_list("0").unwrap(), 1);
        assert_eq!(parse_possible_cpu_list("0-3").unwrap(), 4);
        assert_eq!(parse_possible_cpu_list("0-1,4,6-7\n").unwrap(), 5);
    }

    #[test]
    fn possible_cpu_list_rejects_empty_and_descending_ranges() {
        assert!(parse_possible_cpu_list("").is_err());
        assert!(parse_possible_cpu_list("3-1").is_err());
    }
}
