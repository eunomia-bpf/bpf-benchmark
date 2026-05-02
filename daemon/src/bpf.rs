// SPDX-License-Identifier: MIT
//! Small BPF access adapter for daemon watch/invalidation paths.
//!
//! Standard BPF access is routed through `kernel-sys`/libbpf. The optimize path
//! uses `bpfget` for live program discovery and calls `kernel-sys` directly for
//! optional verifier-state capture and `BPF_PROG_REJIT`; this module only covers
//! map watch/invalidation helpers.

use std::collections::HashMap;
use std::os::fd::{BorrowedFd, OwnedFd, RawFd};
use std::sync::OnceLock;

use anyhow::{bail, Context, Result};

// BPF instruction encoding for `BPF_LD | BPF_IMM | BPF_DW` wide load.
const LD_IMM64_CODE: u8 = 0x18;
const BPF_PSEUDO_MAP_FD: u8 = 1;
const BPF_PSEUDO_MAP_VALUE: u8 = 2;

/// Rewrite `BPF_LD_IMM64` map references so the daemon's `BPF_PROG_REJIT` call
/// sees fds that exist in the daemon's process table.
///
/// The original bytecode (from `BPF_PROG_GET_ORIGINAL`) carries `imm` values
/// that were the loader process's map fds. The daemon's process has different
/// fds for the same maps, opened via `BPF_MAP_GET_FD_BY_ID`. This function
/// patches each `BPF_LD_IMM64` with `src_reg = BPF_PSEUDO_MAP_FD` or
/// `BPF_PSEUDO_MAP_VALUE` to use the daemon's fd, mapped by first-seen order
/// against `prog_info.used_maps` / `fd_array` (the kernel records `used_maps`
/// in the order the verifier first encountered each map).
pub(crate) fn relocate_map_fds_for_rejit(
    insns: &mut [kernel_sys::bpf_insn],
    map_ids: &[u32],
    fd_array: &[i32],
) -> Result<()> {
    if map_ids.len() != fd_array.len() {
        bail!(
            "relocate_map_fds_for_rejit: map_ids ({}) and fd_array ({}) length mismatch",
            map_ids.len(),
            fd_array.len()
        );
    }

    let mut unique_old_fds: Vec<i32> = Vec::new();
    let mut seen: HashMap<i32, ()> = HashMap::new();
    let mut i = 0;
    while i < insns.len() {
        if insns[i].code == LD_IMM64_CODE {
            let src_reg = insns[i].src_reg();
            if src_reg == BPF_PSEUDO_MAP_FD || src_reg == BPF_PSEUDO_MAP_VALUE {
                let old_fd = insns[i].imm;
                if let std::collections::hash_map::Entry::Vacant(e) = seen.entry(old_fd) {
                    unique_old_fds.push(old_fd);
                    e.insert(());
                }
            }
            i += 2;
            continue;
        }
        i += 1;
    }

    if unique_old_fds.is_empty() {
        return Ok(());
    }

    if unique_old_fds.len() > fd_array.len() {
        bail!(
            "relocate_map_fds_for_rejit: bytecode references {} maps but fd_array has {} entries",
            unique_old_fds.len(),
            fd_array.len()
        );
    }

    let mut fd_map: HashMap<i32, i32> = HashMap::with_capacity(unique_old_fds.len());
    for (idx, &old_fd) in unique_old_fds.iter().enumerate() {
        fd_map.insert(old_fd, fd_array[idx]);
    }

    i = 0;
    while i < insns.len() {
        if insns[i].code == LD_IMM64_CODE {
            let src_reg = insns[i].src_reg();
            if src_reg == BPF_PSEUDO_MAP_FD || src_reg == BPF_PSEUDO_MAP_VALUE {
                let old_fd = insns[i].imm;
                if let Some(&new_fd) = fd_map.get(&old_fd) {
                    insns[i].imm = new_fd;
                }
            }
            i += 2;
            continue;
        }
        i += 1;
    }

    Ok(())
}

pub(crate) type BpfMapInfo = kernel_sys::bpf_map_info;

pub(crate) fn bpf_map_get_info(fd: RawFd) -> Result<BpfMapInfo> {
    let borrowed = unsafe { BorrowedFd::borrow_raw(fd) };
    kernel_sys::map_obj_get_info_by_fd(borrowed)
        .with_context(|| format!("read info for BPF map fd {fd}"))
}

pub(crate) fn bpf_map_get_fd_by_id(id: u32) -> Result<OwnedFd> {
    kernel_sys::map_get_fd_by_id(id).with_context(|| format!("open BPF map id {id}"))
}

pub(crate) fn bpf_map_lookup_elem_optional(
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

pub(crate) fn bpf_map_get_next_key(
    fd: RawFd,
    key: Option<&[u8]>,
    key_size: usize,
) -> Result<Option<Vec<u8>>> {
    if key_size == 0 {
        bail!("BPF_MAP_GET_NEXT_KEY fd {fd}: map key size is zero");
    }
    let mut next_key = vec![0u8; key_size];
    let borrowed = unsafe { BorrowedFd::borrow_raw(fd) };
    let found = kernel_sys::map_get_next_key(borrowed, key, &mut next_key)
        .with_context(|| format!("BPF_MAP_GET_NEXT_KEY fd {fd}"))?;
    Ok(found.then_some(next_key))
}

pub(crate) fn bpf_map_lookup_value_size(info: &BpfMapInfo) -> Result<usize> {
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

pub(crate) struct ProgIdIter {
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

pub(crate) fn iter_prog_ids() -> ProgIdIter {
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

    fn make_ld_imm64(dst: u8, src: u8, old_fd: i32) -> [kernel_sys::bpf_insn; 2] {
        let mut hi = kernel_sys::bpf_insn {
            code: LD_IMM64_CODE,
            ..Default::default()
        };
        hi.set_dst_reg(dst);
        hi.set_src_reg(src);
        hi.imm = old_fd;
        let lo = kernel_sys::bpf_insn::default();
        [hi, lo]
    }

    #[test]
    fn relocate_rewrites_pseudo_map_fd_imm_to_daemon_fd() {
        let pair = make_ld_imm64(0, BPF_PSEUDO_MAP_FD, 4);
        let mut insns = pair.to_vec();
        relocate_map_fds_for_rejit(&mut insns, &[42], &[7]).unwrap();
        assert_eq!(insns[0].imm, 7);
        assert_eq!(insns[0].src_reg(), BPF_PSEUDO_MAP_FD);
    }

    #[test]
    fn relocate_rewrites_pseudo_map_value_imm() {
        let pair = make_ld_imm64(3, BPF_PSEUDO_MAP_VALUE, 9);
        let mut insns = pair.to_vec();
        relocate_map_fds_for_rejit(&mut insns, &[55], &[12]).unwrap();
        assert_eq!(insns[0].imm, 12);
        assert_eq!(insns[0].src_reg(), BPF_PSEUDO_MAP_VALUE);
    }

    #[test]
    fn relocate_pairs_unique_old_fds_to_used_maps_in_first_seen_order() {
        let mut insns: Vec<kernel_sys::bpf_insn> = Vec::new();
        insns.extend(make_ld_imm64(0, BPF_PSEUDO_MAP_FD, 10));
        insns.extend(make_ld_imm64(1, BPF_PSEUDO_MAP_FD, 20));
        insns.extend(make_ld_imm64(2, BPF_PSEUDO_MAP_FD, 10));
        relocate_map_fds_for_rejit(&mut insns, &[111, 222], &[100, 200]).unwrap();
        assert_eq!(insns[0].imm, 100);
        assert_eq!(insns[2].imm, 200);
        assert_eq!(insns[4].imm, 100);
    }

    #[test]
    fn relocate_ignores_non_pseudo_imm() {
        let mut insns = make_ld_imm64(0, 0, 7).to_vec();
        relocate_map_fds_for_rejit(&mut insns, &[42], &[99]).unwrap();
        assert_eq!(insns[0].imm, 7);
    }

    #[test]
    fn relocate_fails_when_bytecode_uses_more_maps_than_fd_array() {
        let mut insns: Vec<kernel_sys::bpf_insn> = Vec::new();
        insns.extend(make_ld_imm64(0, BPF_PSEUDO_MAP_FD, 1));
        insns.extend(make_ld_imm64(1, BPF_PSEUDO_MAP_FD, 2));
        let err = relocate_map_fds_for_rejit(&mut insns, &[42], &[7]).unwrap_err();
        assert!(format!("{err:#}").contains("references 2 maps"));
    }

    #[test]
    fn relocate_with_no_pseudo_imm_is_noop() {
        let mut insns = vec![kernel_sys::bpf_insn {
            code: 0x07, // BPF_ALU64 | BPF_K | BPF_ADD
            ..Default::default()
        }];
        relocate_map_fds_for_rejit(&mut insns, &[], &[]).unwrap();
    }
}
