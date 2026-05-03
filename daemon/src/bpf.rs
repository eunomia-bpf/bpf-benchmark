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

/// Canonicalize original-loader map references into stable map-index form.
///
/// `BPF_PROG_GET_ORIGINAL` returns the loader-submitted bytecode. FD-form map
/// references still contain loader-process raw fds, which are meaningless in
/// the daemon. The kernel's `prog_info.map_ids` are ordered like verifier
/// `used_maps`, so the daemon canonicalizes the snapshot once:
///
/// * `PSEUDO_MAP_FD` -> `PSEUDO_MAP_IDX`
/// * `PSEUDO_MAP_VALUE` -> `PSEUDO_MAP_IDX_VALUE`
/// * IDX forms are range-checked and, when the original loader fd_array is
///   available, remapped through any fd-form bindings observed in the snapshot.
///
/// After this point every bpfopt pass operates on stable map indexes. ReJIT
/// submits the transformed bytecode directly with a maps-first fd_array.
pub(crate) fn canonicalize_map_refs_to_idx(
    insns: &mut [kernel_sys::bpf_insn],
    original_loader_fd_array: Option<&[i32]>,
    map_ids: &[u32],
) -> Result<()> {
    let fd_to_map_index = collect_fd_form_map_refs(insns)?;
    if fd_to_map_index.is_empty() && !contains_idx_form_map_ref(insns)? {
        return Ok(());
    }

    if fd_to_map_index.len() > map_ids.len() {
        bail!(
            "canonicalize_map_refs_to_idx: bytecode references {} unique loader map fds but prog_info has {} map ids",
            fd_to_map_index.len(),
            map_ids.len()
        );
    }

    let mut i = 0;
    while i < insns.len() {
        if is_ldimm64(&insns[i]) {
            let src_reg = insns[i].src_reg();
            if is_map_pseudo(src_reg) {
                if i + 1 >= insns.len() {
                    bail!(
                        "canonicalize_map_refs_to_idx: truncated LD_IMM64 map reference at pc {i}"
                    );
                }
            }
            if src_reg == map_fd_pseudo() || src_reg == map_value_pseudo() {
                let old_fd = insns[i].imm;
                let Some(&map_index) = fd_to_map_index.get(&old_fd) else {
                    bail!(
                        "canonicalize_map_refs_to_idx: loader map fd {} was not present in first-seen bindings",
                        old_fd
                    );
                };
                insns[i].imm = i32::try_from(map_index).with_context(|| {
                    format!("canonicalize_map_refs_to_idx: map index {map_index} exceeds i32")
                })?;
                insns[i].set_src_reg(if src_reg == map_fd_pseudo() {
                    map_idx_pseudo()
                } else {
                    map_idx_value_pseudo()
                });
            } else if src_reg == map_idx_pseudo() || src_reg == map_idx_value_pseudo() {
                let map_index = canonical_idx_map_index(
                    insns[i].imm,
                    original_loader_fd_array,
                    &fd_to_map_index,
                    map_ids.len(),
                )?;
                insns[i].imm = i32::try_from(map_index).with_context(|| {
                    format!("canonicalize_map_refs_to_idx: map index {map_index} exceeds i32")
                })?;
            }
            i += 2;
            continue;
        }
        i += 1;
    }

    Ok(())
}

fn collect_fd_form_map_refs(insns: &[kernel_sys::bpf_insn]) -> Result<HashMap<i32, usize>> {
    let mut fd_to_map_index = HashMap::new();
    let mut i = 0;
    while i < insns.len() {
        if is_ldimm64(&insns[i]) {
            let src_reg = insns[i].src_reg();
            if src_reg == map_fd_pseudo() || src_reg == map_value_pseudo() {
                if i + 1 >= insns.len() {
                    bail!(
                        "canonicalize_map_refs_to_idx: truncated LD_IMM64 map reference at pc {i}"
                    );
                }
                let old_fd = insns[i].imm;
                let next_index = fd_to_map_index.len();
                if let std::collections::hash_map::Entry::Vacant(e) = fd_to_map_index.entry(old_fd)
                {
                    e.insert(next_index);
                }
            }
            i += 2;
            continue;
        }
        i += 1;
    }
    Ok(fd_to_map_index)
}

fn contains_idx_form_map_ref(insns: &[kernel_sys::bpf_insn]) -> Result<bool> {
    let mut i = 0;
    while i < insns.len() {
        if is_ldimm64(&insns[i]) {
            let src_reg = insns[i].src_reg();
            if src_reg == map_idx_pseudo() || src_reg == map_idx_value_pseudo() {
                if i + 1 >= insns.len() {
                    bail!(
                        "canonicalize_map_refs_to_idx: truncated LD_IMM64 map reference at pc {i}"
                    );
                }
                return Ok(true);
            }
            i += 2;
            continue;
        }
        i += 1;
    }
    Ok(false)
}

fn canonical_idx_map_index(
    old_index: i32,
    original_loader_fd_array: Option<&[i32]>,
    fd_to_map_index: &HashMap<i32, usize>,
    map_count: usize,
) -> Result<usize> {
    let old_index = usize::try_from(old_index).with_context(|| {
        format!("canonicalize_map_refs_to_idx: negative map fd_array index {old_index}")
    })?;
    let Some(loader_fd_array) = original_loader_fd_array else {
        if old_index >= map_count {
            bail!(
                "canonicalize_map_refs_to_idx: map index {} out of range for {} map ids",
                old_index,
                map_count
            );
        }
        return Ok(old_index);
    };
    let Some(&loader_fd) = loader_fd_array.get(old_index) else {
        bail!(
            "canonicalize_map_refs_to_idx: loader fd_array index {} out of range for {} fds",
            old_index,
            loader_fd_array.len()
        );
    };
    if let Some(&map_index) = fd_to_map_index.get(&loader_fd) {
        return Ok(map_index);
    }
    if loader_fd_array.len() != map_count {
        bail!(
            "canonicalize_map_refs_to_idx: cannot map loader fd_array index {} without fd-form binding; loader fd_array has {} entries but prog_info has {} map ids",
            old_index,
            loader_fd_array.len(),
            map_count
        );
    }
    if old_index >= map_count {
        bail!(
            "canonicalize_map_refs_to_idx: map index {} out of range for {} map ids",
            old_index,
            map_count
        );
    }
    Ok(old_index)
}

fn is_ldimm64(insn: &kernel_sys::bpf_insn) -> bool {
    insn.code == (kernel_sys::BPF_LD | kernel_sys::BPF_DW | kernel_sys::BPF_IMM) as u8
}

fn is_map_pseudo(src_reg: u8) -> bool {
    matches!(
        src_reg,
        value
            if value == map_fd_pseudo()
                || value == map_value_pseudo()
                || value == map_idx_pseudo()
                || value == map_idx_value_pseudo()
    )
}

fn map_fd_pseudo() -> u8 {
    kernel_sys::BPF_PSEUDO_MAP_FD as u8
}

fn map_value_pseudo() -> u8 {
    kernel_sys::BPF_PSEUDO_MAP_VALUE as u8
}

fn map_idx_pseudo() -> u8 {
    kernel_sys::BPF_PSEUDO_MAP_IDX as u8
}

fn map_idx_value_pseudo() -> u8 {
    kernel_sys::BPF_PSEUDO_MAP_IDX_VALUE as u8
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

    fn make_ld_imm64(dst: u8, src: u8, imm: i32) -> [kernel_sys::bpf_insn; 2] {
        let mut hi = kernel_sys::bpf_insn {
            code: (kernel_sys::BPF_LD | kernel_sys::BPF_DW | kernel_sys::BPF_IMM) as u8,
            ..Default::default()
        };
        hi.set_dst_reg(dst);
        hi.set_src_reg(src);
        hi.imm = imm;
        let lo = kernel_sys::bpf_insn::default();
        [hi, lo]
    }

    fn make_ld_imm64_with_lo(dst: u8, src: u8, imm: i32, lo_imm: i32) -> [kernel_sys::bpf_insn; 2] {
        let mut pair = make_ld_imm64(dst, src, imm);
        pair[1].imm = lo_imm;
        pair
    }

    fn decode_fixture_insns(bytes: &[u8]) -> Vec<kernel_sys::bpf_insn> {
        assert_eq!(bytes.len() % 8, 0);
        bytes
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
            .collect()
    }

    fn pseudo_pairs(insns: &[kernel_sys::bpf_insn]) -> Vec<(u8, i32, i32)> {
        insns
            .chunks_exact(2)
            .map(|pair| (pair[0].src_reg(), pair[0].imm, pair[1].imm))
            .collect()
    }

    #[test]
    fn canonicalize_round129_real_ldimm64_pattern_to_idx_order() {
        // Extracted from corpus/results/failures/129/pass-00-wide_mem.in.bin:
        // pc 5 FD=41, pc 16 FD=25, pc 20 VALUE=42+off 40,
        // pc 485 FD=24, pc 502 FD=26.
        let mut insns = decode_fixture_insns(&[
            0x18, 0x11, 0x00, 0x00, 0x29, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x18, 0x11, 0x00, 0x00, 0x19, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x18, 0x21, 0x00, 0x00, 0x2a, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x18, 0x11, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x12, 0x00, 0x00, 0x1a, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        ]);

        canonicalize_map_refs_to_idx(&mut insns, None, &[489, 466, 490, 465, 471]).unwrap();

        assert_eq!(
            pseudo_pairs(&insns),
            vec![
                (map_idx_pseudo(), 0, 0),
                (map_idx_pseudo(), 1, 0),
                (map_idx_value_pseudo(), 2, 40),
                (map_idx_pseudo(), 3, 0),
                (map_idx_pseudo(), 4, 0),
            ]
        );
    }

    #[test]
    fn canonicalize_round102_real_pattern_keeps_duplicate_fd_binding() {
        // Extracted from corpus/results/failures/102/pass-00-wide_mem.in.bin:
        // pc 17 FD=14, pc 38/46/149/157/167 FD=16, pc 177 FD=14.
        let mut insns = decode_fixture_insns(&[
            0x18, 0x11, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x18, 0x11, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x18, 0x11, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x11, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x11, 0x00, 0x00, 0x10, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x11, 0x00, 0x00,
            0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x11,
            0x00, 0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        ]);

        canonicalize_map_refs_to_idx(&mut insns, None, &[354, 331, 397]).unwrap();

        let imms = pseudo_pairs(&insns)
            .into_iter()
            .map(|(_, imm, _)| imm)
            .collect::<Vec<_>>();
        assert_eq!(imms, vec![0, 1, 1, 1, 1, 1, 0]);
    }

    #[test]
    fn canonicalize_remaps_all_four_pseudo_modes_with_loader_fd_array() {
        let mut insns: Vec<kernel_sys::bpf_insn> = Vec::new();
        insns.extend(make_ld_imm64(1, map_fd_pseudo(), 41));
        insns.extend(make_ld_imm64(1, map_value_pseudo(), 25));
        insns.extend(make_ld_imm64(1, map_idx_pseudo(), 0));
        insns.extend(make_ld_imm64_with_lo(1, map_idx_value_pseudo(), 1, 7));

        canonicalize_map_refs_to_idx(&mut insns, Some(&[25, 41]), &[1001, 1002]).unwrap();

        assert_eq!(
            pseudo_pairs(&insns),
            vec![
                (map_idx_pseudo(), 0, 0),
                (map_idx_value_pseudo(), 1, 0),
                (map_idx_pseudo(), 1, 0),
                (map_idx_value_pseudo(), 0, 7),
            ]
        );
    }

    #[test]
    fn canonicalize_preserves_idx_without_loader_fd_array() {
        let mut insns: Vec<kernel_sys::bpf_insn> = Vec::new();
        insns.extend(make_ld_imm64(0, map_idx_pseudo(), 1));
        insns.extend(make_ld_imm64_with_lo(1, map_idx_value_pseudo(), 0, 12));

        canonicalize_map_refs_to_idx(&mut insns, None, &[11, 22]).unwrap();

        assert_eq!(
            pseudo_pairs(&insns),
            vec![(map_idx_pseudo(), 1, 0), (map_idx_value_pseudo(), 0, 12)]
        );
    }

    #[test]
    fn canonicalize_rejects_pseudo_map_idx_out_of_range() {
        let mut insns = make_ld_imm64(0, map_idx_pseudo(), 1).to_vec();
        let err = canonicalize_map_refs_to_idx(&mut insns, None, &[42]).unwrap_err();
        assert!(format!("{err:#}").contains("out of range"), "err={err:#}");
    }

    #[test]
    fn canonicalize_rejects_more_unique_loader_fds_than_map_ids() {
        let mut insns: Vec<kernel_sys::bpf_insn> = Vec::new();
        insns.extend(make_ld_imm64(0, map_fd_pseudo(), 1));
        insns.extend(make_ld_imm64(1, map_fd_pseudo(), 2));

        let err = canonicalize_map_refs_to_idx(&mut insns, None, &[42]).unwrap_err();
        assert!(format!("{err:#}").contains("2 unique loader map fds"));
    }

    #[test]
    fn canonicalize_with_no_pseudo_map_refs_is_noop() {
        let mut insns = vec![kernel_sys::bpf_insn {
            code: 0x07, // BPF_ALU64 | BPF_K | BPF_ADD
            ..Default::default()
        }];
        canonicalize_map_refs_to_idx(&mut insns, None, &[]).unwrap();
        assert_eq!(insns[0].code, 0x07);
    }
}
