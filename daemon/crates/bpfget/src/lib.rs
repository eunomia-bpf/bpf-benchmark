// SPDX-License-Identifier: MIT
//! In-process live BPF program discovery for `bpfrejit-daemon`.

use std::collections::{BTreeMap, HashMap};
use std::os::fd::{AsFd, AsRawFd, BorrowedFd, OwnedFd};

use anyhow::{anyhow, bail, Context, Result};
use serde::{Deserialize, Serialize};

const BPF_LD_IMM64: u8 = (kernel_sys::BPF_LD | kernel_sys::BPF_DW | kernel_sys::BPF_IMM) as u8;
const BPF_PSEUDO_MAP_FD: u8 = kernel_sys::BPF_PSEUDO_MAP_FD as u8;
const BPF_PSEUDO_MAP_VALUE: u8 = kernel_sys::BPF_PSEUDO_MAP_VALUE as u8;
const BPF_PSEUDO_MAP_IDX: u8 = kernel_sys::BPF_PSEUDO_MAP_IDX as u8;
const BPF_PSEUDO_MAP_IDX_VALUE: u8 = kernel_sys::BPF_PSEUDO_MAP_IDX_VALUE as u8;
const BPF_CALL_INSN: u8 = (kernel_sys::BPF_JMP | kernel_sys::BPF_CALL) as u8;
const BPF_REG_1: u8 = 1;
const BPF_REG_2: u8 = 2;
const MAP_POINTER_SCAN_LIMIT: usize = 16;

#[derive(Clone, Debug, Serialize, Deserialize, PartialEq, Eq)]
pub struct TypeInfo {
    pub name: String,
    pub numeric: u32,
}

#[derive(Clone, Debug, Serialize, Deserialize, PartialEq, Eq)]
pub struct ProgramInfo {
    pub id: u32,
    pub name: String,
    #[serde(rename = "type")]
    pub prog_type: TypeInfo,
    pub insn_cnt: u32,
    pub map_ids: Vec<u32>,
    pub load_time: u64,
    pub created_by_uid: u32,
    pub xlated_prog_len: u32,
    pub orig_prog_len: u32,
    pub jited_prog_len: u32,
    pub btf_id: u32,
    #[serde(default, skip_serializing_if = "is_zero_u32")]
    pub prog_flags: u32,
    #[serde(default, skip_serializing_if = "is_zero_u32")]
    pub func_info_rec_size: u32,
    #[serde(default, skip_serializing_if = "is_zero_u32")]
    pub nr_func_info: u32,
    #[serde(default, skip_serializing_if = "is_zero_u32")]
    pub line_info_rec_size: u32,
    #[serde(default, skip_serializing_if = "is_zero_u32")]
    pub nr_line_info: u32,
    pub attach_btf_obj_id: u32,
    pub attach_btf_id: u32,
    #[serde(skip_serializing_if = "Option::is_none")]
    pub expected_attach_type: Option<TypeInfo>,
}

#[derive(Clone, Debug, Serialize, Deserialize, PartialEq, Eq)]
pub struct MapInfo {
    #[serde(skip_serializing_if = "Option::is_none")]
    pub old_fd: Option<i32>,
    pub map_id: u32,
    pub map_type: u32,
    pub key_size: u32,
    pub value_size: u32,
    pub max_entries: u32,
    pub name: String,
    #[serde(default, skip_serializing_if = "is_zero_u32")]
    pub map_flags: u32,
    #[serde(default, skip_serializing_if = "is_zero_u32")]
    pub ifindex: u32,
    #[serde(default, skip_serializing_if = "is_zero_u32")]
    pub btf_id: u32,
    #[serde(default, skip_serializing_if = "is_zero_u32")]
    pub btf_key_type_id: u32,
    #[serde(default, skip_serializing_if = "is_zero_u32")]
    pub btf_value_type_id: u32,
    #[serde(default, skip_serializing_if = "is_zero_u32")]
    pub btf_vmlinux_value_type_id: u32,
    #[serde(default, skip_serializing_if = "is_zero_u32")]
    pub btf_vmlinux_id: u32,
    #[serde(default, skip_serializing_if = "is_zero_u64")]
    pub map_extra: u64,
}

#[derive(Clone, Debug, Default, PartialEq, Eq)]
pub struct ProgramBtfInfo {
    pub func_info_rec_size: u32,
    pub func_info: Vec<u8>,
    pub line_info_rec_size: u32,
    pub line_info: Vec<u8>,
}

#[derive(Clone, Debug)]
pub struct ProgramSnapshot {
    pub info: ProgramInfo,
    pub maps: Vec<MapInfo>,
    pub insns: Vec<kernel_sys::bpf_insn>,
    pub btf: ProgramBtfInfo,
}

#[derive(Debug)]
pub struct RelocatedProgram {
    insns: Vec<kernel_sys::bpf_insn>,
    _map_fds: Vec<OwnedFd>,
}

impl RelocatedProgram {
    pub fn insns(&self) -> &[kernel_sys::bpf_insn] {
        &self.insns
    }
}

impl ProgramSnapshot {
    pub fn relocate_for_load(&self, source: &[kernel_sys::bpf_insn]) -> Result<RelocatedProgram> {
        self.relocate_for_load_with(source, |map_id| {
            kernel_sys::map_get_fd_by_id(map_id)
                .with_context(|| format!("open BPF map id {map_id}"))
        })
    }

    pub fn relocate_for_load_with<F>(
        &self,
        source: &[kernel_sys::bpf_insn],
        mut open_map_fd: F,
    ) -> Result<RelocatedProgram>
    where
        F: FnMut(u32) -> Result<OwnedFd>,
    {
        let mut insns = source.to_vec();
        let mut owned = HashMap::<u32, OwnedFd>::new();
        let old_fd_to_map_id = build_old_fd_map(&self.maps, &pseudo_map_old_fds(&insns))?;
        let resolved_pointer_to_map_id =
            build_resolved_map_pointer_map(&self.info.map_ids, &insns)?;

        let mut pc = 0usize;
        while pc < insns.len() {
            if is_pseudo_map_fd_ldimm64(&insns[pc]) {
                let old_fd = insns[pc].imm;
                let map_id = *old_fd_to_map_id
                    .get(&old_fd)
                    .ok_or_else(|| anyhow!("no map binding for pseudo-map old fd {old_fd}"))?;
                let new_fd = open_map_fd_once(&mut owned, map_id, &mut open_map_fd)?.as_raw_fd();
                insns[pc].imm = new_fd;
                pc += 2;
            } else if is_pseudo_map_idx_ldimm64(&insns[pc]) {
                let raw_idx = insns[pc].imm;
                if raw_idx < 0 {
                    bail!("pseudo-map fd_array index {raw_idx} is negative");
                }
                let idx = raw_idx as usize;
                let Some(&map_id) = self.info.map_ids.get(idx) else {
                    bail!("program metadata does not provide a map_id for pseudo-map fd_array index {idx}");
                };
                let new_fd = open_map_fd_once(&mut owned, map_id, &mut open_map_fd)?.as_raw_fd();
                let src_reg = if insns[pc].src_reg() == BPF_PSEUDO_MAP_IDX {
                    BPF_PSEUDO_MAP_FD
                } else {
                    BPF_PSEUDO_MAP_VALUE
                };
                insns[pc].set_src_reg(src_reg);
                insns[pc].imm = new_fd;
                pc += 2;
            } else if let Some(value) = resolved_kernel_map_pointer_value(&insns, pc) {
                let map_id = *resolved_pointer_to_map_id.get(&value).ok_or_else(|| {
                    anyhow!("no map binding for resolved kernel map pointer at insn {pc}")
                })?;
                let new_fd = open_map_fd_once(&mut owned, map_id, &mut open_map_fd)?.as_raw_fd();
                insns[pc].set_src_reg(BPF_PSEUDO_MAP_FD);
                insns[pc].imm = new_fd;
                insns[pc + 1].imm = 0;
                pc += 2;
            } else {
                pc += insn_width(&insns[pc]);
            }
        }

        Ok(RelocatedProgram {
            insns,
            _map_fds: owned.into_values().collect(),
        })
    }
}

#[derive(Clone, Debug, Serialize, Deserialize, PartialEq, Eq)]
pub struct TargetJson {
    pub arch: String,
    pub features: Vec<String>,
    pub kinsns: BTreeMap<String, TargetKinsnJson>,
}

#[derive(Clone, Debug, Serialize, Deserialize, PartialEq, Eq)]
pub struct TargetKinsnJson {
    pub btf_func_id: i32,
    pub btf_id: u32,
}

struct KinsnProbeTarget {
    json_name: &'static str,
    probe_names: &'static [&'static str],
}

const KINSN_PROBE_TARGETS: &[KinsnProbeTarget] = &[
    KinsnProbeTarget {
        json_name: "bpf_rotate64",
        probe_names: &["bpf_rotate64"],
    },
    KinsnProbeTarget {
        json_name: "bpf_select64",
        probe_names: &["bpf_select64"],
    },
    KinsnProbeTarget {
        json_name: "bpf_ccmp64",
        probe_names: &["bpf_ccmp64"],
    },
    KinsnProbeTarget {
        json_name: "bpf_prefetch",
        probe_names: &["bpf_prefetch"],
    },
    KinsnProbeTarget {
        json_name: "bpf_extract64",
        probe_names: &["bpf_extract64"],
    },
    KinsnProbeTarget {
        json_name: "bpf_endian_load64",
        probe_names: &["bpf_endian_load64"],
    },
    KinsnProbeTarget {
        json_name: "bpf_bulk_memcpy",
        probe_names: &["bpf_bulk_memcpy", "bpf_memcpy_bulk"],
    },
    KinsnProbeTarget {
        json_name: "bpf_bulk_memset",
        probe_names: &["bpf_bulk_memset", "bpf_memset_bulk"],
    },
];

pub fn snapshot_program(prog_id: u32) -> Result<ProgramSnapshot> {
    let fd = kernel_sys::prog_get_fd_by_id(prog_id)
        .with_context(|| format!("open BPF program id {prog_id}"))?;
    let mut insns = kernel_sys::prog_get_original(fd.as_fd())
        .with_context(|| format!("read original bytecode for BPF program id {prog_id}"))?;
    ensure_original_bytecode(&insns)?;
    let (info, map_ids) = get_prog_info_with_map_ids_from_fd(fd.as_fd(), prog_id)?;
    let expected_attach_type = expected_attach_type_json(info.id, info.prog_type)?;
    let btf_info = kernel_sys::prog_btf_info(fd.as_fd())
        .with_context(|| format!("read BTF record metadata for BPF program id {prog_id}"))?;

    normalize_resolved_map_pointer_immediates(&mut insns, &map_ids)?;
    let pseudo_map_old_fds = pseudo_map_old_fds(&insns);
    let maps = get_map_infos(&map_ids, &pseudo_map_old_fds)?;

    let mut prog_info = ProgramInfo::from_info(info, map_ids, expected_attach_type)?;
    prog_info.nr_func_info = btf_record_count(&btf_info.func_info, btf_info.func_info_rec_size)?;
    prog_info.nr_line_info = btf_record_count(&btf_info.line_info, btf_info.line_info_rec_size)?;
    validate_btf_record_blob(
        "func_info",
        prog_info.nr_func_info,
        prog_info.func_info_rec_size,
        &btf_info.func_info,
    )?;
    validate_btf_record_blob(
        "line_info",
        prog_info.nr_line_info,
        prog_info.line_info_rec_size,
        &btf_info.line_info,
    )?;

    Ok(ProgramSnapshot {
        info: prog_info,
        maps,
        insns,
        btf: ProgramBtfInfo {
            func_info_rec_size: btf_info.func_info_rec_size,
            func_info: btf_info.func_info,
            line_info_rec_size: btf_info.line_info_rec_size,
            line_info: btf_info.line_info,
        },
    })
}

pub fn probe_target_json() -> Result<TargetJson> {
    let kinsns = probe_target_kinsns().with_context(|| {
        "failed to probe target kinsn BTF; target probing requires readable kernel BTF"
    })?;
    if kinsns.is_empty() {
        bail!("target kinsn BTF probing found no kinsn functions; target.json would be incomplete");
    }
    Ok(TargetJson {
        arch: detect_arch(),
        features: detect_features(),
        kinsns,
    })
}

pub fn encode_insns(insns: &[kernel_sys::bpf_insn]) -> Vec<u8> {
    let mut bytes = Vec::with_capacity(std::mem::size_of_val(insns));
    for insn in insns {
        bytes.extend_from_slice(&insn_raw_bytes(insn));
    }
    bytes
}

impl ProgramInfo {
    fn from_info(
        info: kernel_sys::BpfProgInfoFork,
        map_ids: Vec<u32>,
        expected_attach_type: Option<TypeInfo>,
    ) -> Result<Self> {
        let insn_size = std::mem::size_of::<kernel_sys::bpf_insn>() as u32;
        let insn_bytes = if info.orig_prog_len != 0 {
            info.orig_prog_len
        } else {
            info.xlated_prog_len
        };

        let json = Self {
            id: info.id,
            name: c_name_u8(&info.name),
            prog_type: TypeInfo {
                name: prog_type_name(info.prog_type).to_string(),
                numeric: info.prog_type,
            },
            insn_cnt: insn_bytes / insn_size,
            map_ids,
            load_time: info.load_time,
            created_by_uid: info.created_by_uid,
            xlated_prog_len: info.xlated_prog_len,
            orig_prog_len: info.orig_prog_len,
            jited_prog_len: info.jited_prog_len,
            btf_id: info.btf_id,
            prog_flags: info.prog_flags,
            func_info_rec_size: info.func_info_rec_size,
            nr_func_info: info.nr_func_info,
            line_info_rec_size: info.line_info_rec_size,
            nr_line_info: info.nr_line_info,
            attach_btf_obj_id: info.attach_btf_obj_id,
            attach_btf_id: info.attach_btf_id,
            expected_attach_type,
        };
        validate_required_load_metadata(&json)?;
        Ok(json)
    }
}

fn validate_required_load_metadata(info: &ProgramInfo) -> Result<()> {
    let prog_type = info.prog_type.numeric;
    if prog_type_requires_prog_btf(prog_type) && info.btf_id == 0 {
        bail!(
            "prog type {} requires non-zero btf_id metadata",
            info.prog_type.name
        );
    }
    if prog_type_requires_attach_btf(prog_type) && info.attach_btf_id == 0 {
        bail!(
            "prog type {} requires non-zero attach_btf_id metadata",
            info.prog_type.name
        );
    }
    if prog_type_requires_expected_attach_type(prog_type) && info.expected_attach_type.is_none() {
        bail!(
            "prog type {} requires expected_attach_type metadata",
            info.prog_type.name
        );
    }
    validate_btf_record_metadata("func_info", info.nr_func_info, info.func_info_rec_size)?;
    validate_btf_record_metadata("line_info", info.nr_line_info, info.line_info_rec_size)?;
    Ok(())
}

fn validate_btf_record_metadata(label: &str, count: u32, rec_size: u32) -> Result<()> {
    if count != 0 && rec_size == 0 {
        bail!("{label} count is {count} but rec_size is zero");
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

fn expected_attach_type_json(
    prog_id: u32,
    prog_type: kernel_sys::bpf_prog_type,
) -> Result<Option<TypeInfo>> {
    let Some(value) = kernel_sys::expected_attach_type_for_prog(prog_id, prog_type)
        .with_context(|| format!("recover expected attach type for BPF program id {prog_id}"))?
    else {
        return Ok(None);
    };
    Ok(Some(TypeInfo {
        name: attach_type_name(value).unwrap_or("").to_string(),
        numeric: value,
    }))
}

fn get_prog_info_with_map_ids_from_fd(
    fd: BorrowedFd<'_>,
    prog_id: u32,
) -> Result<(kernel_sys::BpfProgInfoFork, Vec<u32>)> {
    let info = kernel_sys::obj_get_info_by_fd(fd)
        .with_context(|| format!("read info for BPF program id {prog_id}"))?;
    let map_ids = kernel_sys::prog_map_ids(fd, info.nr_map_ids)
        .with_context(|| format!("read map ids for BPF program id {prog_id}"))?;
    Ok((info, map_ids))
}

fn get_map_infos(map_ids: &[u32], pseudo_map_old_fds: &[i32]) -> Result<Vec<MapInfo>> {
    if pseudo_map_old_fds.len() > map_ids.len() {
        bail!(
            "original bytecode references {} pseudo-map fd values but prog_info exposes only {} map ids",
            pseudo_map_old_fds.len(),
            map_ids.len()
        );
    }

    let mut maps = Vec::with_capacity(map_ids.len());
    for (idx, &map_id) in map_ids.iter().enumerate() {
        let fd = kernel_sys::map_get_fd_by_id(map_id)
            .with_context(|| format!("open BPF map id {map_id}"))?;
        let info = kernel_sys::map_obj_get_info_by_fd(fd.as_fd())
            .with_context(|| format!("read info for BPF map id {map_id}"))?;
        maps.push(MapInfo {
            old_fd: pseudo_map_old_fds.get(idx).copied(),
            map_id,
            map_type: info.type_,
            key_size: info.key_size,
            value_size: info.value_size,
            max_entries: info.max_entries,
            name: c_name_i8(&info.name),
            map_flags: info.map_flags,
            ifindex: info.ifindex,
            btf_id: info.btf_id,
            btf_key_type_id: info.btf_key_type_id,
            btf_value_type_id: info.btf_value_type_id,
            btf_vmlinux_value_type_id: info.btf_vmlinux_value_type_id,
            btf_vmlinux_id: info.btf_vmlinux_id,
            map_extra: info.map_extra,
        });
    }
    Ok(maps)
}

fn validate_btf_record_blob(label: &str, count: u32, rec_size: u32, bytes: &[u8]) -> Result<()> {
    let expected = (count as usize)
        .checked_mul(rec_size as usize)
        .ok_or_else(|| anyhow!("{label} byte length overflow"))?;
    if bytes.len() != expected {
        bail!(
            "{label} metadata expected {expected} bytes from {count} records of size {rec_size}, got {}",
            bytes.len()
        );
    }
    Ok(())
}

fn btf_record_count(bytes: &[u8], rec_size: u32) -> Result<u32> {
    if bytes.is_empty() {
        return Ok(0);
    }
    if rec_size == 0 {
        bail!("BTF record data is present but rec_size is zero");
    }
    let rec_size = rec_size as usize;
    if !bytes.len().is_multiple_of(rec_size) {
        bail!(
            "BTF record byte length {} is not a multiple of rec_size {rec_size}",
            bytes.len()
        );
    }
    (bytes.len() / rec_size)
        .try_into()
        .map_err(|_| anyhow!("BTF record count does not fit u32"))
}

fn normalize_resolved_map_pointer_immediates(
    insns: &mut [kernel_sys::bpf_insn],
    map_ids: &[u32],
) -> Result<()> {
    let pointer_to_map_idx = resolved_map_pointer_indices(insns, map_ids)?;
    let mut pc = 0usize;
    while pc < insns.len() {
        if let Some(value) = resolved_kernel_map_pointer_value(insns, pc) {
            let map_idx = pointer_to_map_idx
                .get(&value)
                .ok_or_else(|| anyhow!("missing map index for resolved kernel map pointer"))?;
            insns[pc].set_src_reg(BPF_PSEUDO_MAP_IDX);
            insns[pc].imm = i32::try_from(*map_idx)
                .with_context(|| format!("map index {map_idx} at insn {pc} does not fit i32"))?;
            insns[pc + 1].imm = 0;
            pc += 2;
        } else {
            pc += insn_width(&insns[pc]);
        }
    }
    Ok(())
}

fn resolved_map_pointer_indices(
    insns: &[kernel_sys::bpf_insn],
    map_ids: &[u32],
) -> Result<BTreeMap<u64, usize>> {
    let values = resolved_kernel_map_pointer_values(insns);
    if values.is_empty() {
        return Ok(BTreeMap::new());
    }
    if values.len() != map_ids.len() {
        bail!(
            "original bytecode contains {} resolved kernel map pointer values, but prog_info exposes {} map ids; cannot reconstruct BPF_PSEUDO_MAP_IDX relocations",
            values.len(),
            map_ids.len()
        );
    }
    Ok(values
        .into_iter()
        .enumerate()
        .map(|(idx, value)| (value, idx))
        .collect())
}

fn build_resolved_map_pointer_map(
    map_ids: &[u32],
    insns: &[kernel_sys::bpf_insn],
) -> Result<BTreeMap<u64, u32>> {
    let values = resolved_kernel_map_pointer_values(insns);
    if values.is_empty() {
        return Ok(BTreeMap::new());
    }
    if values.len() != map_ids.len() {
        bail!(
            "cannot reconstruct {} resolved kernel map pointer values from {} map bindings",
            values.len(),
            map_ids.len()
        );
    }
    Ok(values
        .into_iter()
        .zip(map_ids.iter().copied())
        .collect::<BTreeMap<_, _>>())
}

fn build_old_fd_map(bindings: &[MapInfo], old_fds: &[i32]) -> Result<HashMap<i32, u32>> {
    let mut old_fd_to_map_id = HashMap::new();
    for binding in bindings {
        let Some(old_fd) = binding.old_fd else {
            continue;
        };
        if let Some(previous) = old_fd_to_map_id.insert(old_fd, binding.map_id) {
            bail!(
                "pseudo-map old fd {old_fd} maps to both map {} and {}",
                previous,
                binding.map_id
            );
        }
    }

    let mut positional_map_ids = bindings
        .iter()
        .filter(|binding| binding.old_fd.is_none())
        .map(|binding| binding.map_id);
    for old_fd in old_fds.iter().copied() {
        if old_fd_to_map_id.contains_key(&old_fd) {
            continue;
        }
        let Some(map_id) = positional_map_ids.next() else {
            bail!("no map binding for pseudo-map old fd {old_fd}");
        };
        old_fd_to_map_id.insert(old_fd, map_id);
    }
    Ok(old_fd_to_map_id)
}

fn open_map_fd_once<'a, F>(
    opened: &'a mut HashMap<u32, OwnedFd>,
    map_id: u32,
    open_map_fd: &mut F,
) -> Result<&'a OwnedFd>
where
    F: FnMut(u32) -> Result<OwnedFd>,
{
    if !opened.contains_key(&map_id) {
        opened.insert(map_id, open_map_fd(map_id)?);
    }
    opened
        .get(&map_id)
        .ok_or_else(|| anyhow!("internal error opening map id {map_id}"))
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

fn resolved_kernel_map_pointer_values(insns: &[kernel_sys::bpf_insn]) -> Vec<u64> {
    let mut values = Vec::new();
    let mut pc = 0usize;
    while pc < insns.len() {
        if let Some(value) = resolved_kernel_map_pointer_value(insns, pc) {
            if !values.contains(&value) {
                values.push(value);
            }
            pc += 2;
        } else {
            pc += insn_width(&insns[pc]);
        }
    }
    values
}

fn resolved_kernel_map_pointer_value(insns: &[kernel_sys::bpf_insn], pc: usize) -> Option<u64> {
    if pc + 1 >= insns.len() {
        return None;
    }
    let first = &insns[pc];
    let second = &insns[pc + 1];
    if !(first.code == BPF_LD_IMM64
        && first.src_reg() == 0
        && first.off == 0
        && second.code == 0
        && second.dst_reg() == 0
        && second.src_reg() == 0
        && second.off == 0)
    {
        return None;
    }
    let value = ldimm64_u64(first, second);
    (looks_like_kernel_heap_pointer(value)
        && resolved_pointer_is_used_as_map_arg(insns, pc, first.dst_reg()))
    .then_some(value)
}

fn resolved_pointer_is_used_as_map_arg(insns: &[kernel_sys::bpf_insn], pc: usize, reg: u8) -> bool {
    let end = insns.len().min(pc + MAP_POINTER_SCAN_LIMIT);
    let mut scan_pc = pc + 2;
    while scan_pc < end {
        let insn = &insns[scan_pc];
        if is_helper_call(insn) {
            return helper_expects_map_arg(insn.imm, reg);
        }
        if writes_register(insn, reg) {
            return false;
        }
        scan_pc += insn_width(insn);
    }
    false
}

fn helper_expects_map_arg(helper: i32, reg: u8) -> bool {
    if reg == BPF_REG_2 && helper == kernel_sys::BPF_FUNC_tail_call as i32 {
        return true;
    }
    reg == BPF_REG_1
        && matches!(
            helper,
            value if value == kernel_sys::BPF_FUNC_map_lookup_elem as i32
                || value == kernel_sys::BPF_FUNC_map_update_elem as i32
                || value == kernel_sys::BPF_FUNC_map_delete_elem as i32
                || value == kernel_sys::BPF_FUNC_map_push_elem as i32
                || value == kernel_sys::BPF_FUNC_map_pop_elem as i32
                || value == kernel_sys::BPF_FUNC_map_peek_elem as i32
                || value == kernel_sys::BPF_FUNC_redirect_map as i32
                || value == kernel_sys::BPF_FUNC_map_lookup_percpu_elem as i32
        )
}

fn is_helper_call(insn: &kernel_sys::bpf_insn) -> bool {
    insn.code == BPF_CALL_INSN && insn.src_reg() == 0
}

fn writes_register(insn: &kernel_sys::bpf_insn, reg: u8) -> bool {
    if insn.dst_reg() != reg {
        return false;
    }
    matches!(
        u32::from(insn.code) & 0x07,
        kernel_sys::BPF_LD | kernel_sys::BPF_LDX | kernel_sys::BPF_ALU | kernel_sys::BPF_ALU64
    )
}

fn insn_width(insn: &kernel_sys::bpf_insn) -> usize {
    if insn.code == BPF_LD_IMM64 {
        2
    } else {
        1
    }
}

fn ldimm64_u64(first: &kernel_sys::bpf_insn, second: &kernel_sys::bpf_insn) -> u64 {
    ((second.imm as u32 as u64) << 32) | (first.imm as u32 as u64)
}

fn looks_like_kernel_heap_pointer(value: u64) -> bool {
    (value >> 48) == 0xffff && ((value >> 32) & 0xffff) != 0xffff && value.is_multiple_of(8)
}

fn probe_target_kinsns() -> Result<BTreeMap<String, TargetKinsnJson>> {
    let mut found = BTreeMap::new();
    let mut start_id = 0u32;
    let mut saw_btf = false;
    let vmlinux_btf =
        kernel_sys::KernelBtf::load_vmlinux().context("load vmlinux BTF for split BTF probing")?;

    loop {
        let btf_id = match kernel_sys::btf_get_next_id(start_id) {
            Ok(Some(id)) => id,
            Ok(None) => break,
            Err(err) => {
                return Err(err)
                    .with_context(|| format!("enumerate BTF objects after id {start_id}"));
            }
        };
        saw_btf = true;
        start_id = btf_id;

        match kernel_sys::KernelBtf::load_from_kernel_by_id(btf_id) {
            Ok(btf) => probe_kinsns_in_btf(btf_id, &btf, &mut found)?,
            Err(err) => {
                let btf = kernel_sys::KernelBtf::load_from_kernel_by_id_split(btf_id, &vmlinux_btf)
                    .with_context(|| {
                        format!("load split BTF id {btf_id}; direct BTF load failed: {err:#}")
                    })?;
                probe_kinsns_in_btf(btf_id, &btf, &mut found)?;
            }
        }

        if found.len() == KINSN_PROBE_TARGETS.len() {
            break;
        }
    }

    if !saw_btf {
        bail!("no kernel BTF objects are visible");
    }
    Ok(found)
}

fn probe_kinsns_in_btf(
    btf_id: u32,
    btf: &kernel_sys::KernelBtf,
    found: &mut BTreeMap<String, TargetKinsnJson>,
) -> Result<()> {
    for target in KINSN_PROBE_TARGETS {
        if found.contains_key(target.json_name) {
            continue;
        }
        for &probe_name in target.probe_names {
            if let Some(btf_func_id) = btf
                .find_func_by_name(probe_name)
                .with_context(|| format!("inspect BTF id {btf_id} for {probe_name}"))?
            {
                let Ok(btf_func_id) = i32::try_from(btf_func_id) else {
                    bail!(
                        "BTF id {btf_id} function {probe_name} type id {btf_func_id} exceeds target.json i32 range"
                    );
                };
                found.insert(
                    target.json_name.to_string(),
                    TargetKinsnJson {
                        btf_func_id,
                        btf_id,
                    },
                );
                break;
            }
        }
    }
    Ok(())
}

fn detect_arch() -> String {
    match std::env::consts::ARCH {
        "x86_64" => "x86_64".to_string(),
        "aarch64" => "aarch64".to_string(),
        other => other.to_string(),
    }
}

fn detect_features() -> Vec<String> {
    let mut features = Vec::new();

    #[cfg(target_arch = "x86_64")]
    {
        features.push("cmov".to_string());
        if std::is_x86_feature_detected!("bmi1") {
            features.push("bmi1".to_string());
        }
        if std::is_x86_feature_detected!("bmi2") {
            features.push("bmi2".to_string());
            features.push("rorx".to_string());
        }
        if std::is_x86_feature_detected!("movbe") {
            features.push("movbe".to_string());
        }
    }

    #[cfg(target_arch = "aarch64")]
    {
        let cpu_features = cpuinfo_feature_tokens();
        for feature in ["lse", "atomics", "crc32", "asimd"] {
            if cpu_features.iter().any(|token| token == feature) {
                features.push(feature.to_string());
            }
        }
    }

    #[cfg(not(any(target_arch = "x86_64", target_arch = "aarch64")))]
    {
        features.extend(cpuinfo_feature_tokens());
    }

    features
}

#[cfg(any(
    target_arch = "aarch64",
    not(any(target_arch = "x86_64", target_arch = "aarch64"))
))]
fn cpuinfo_feature_tokens() -> Vec<String> {
    let Ok(cpuinfo) = std::fs::read_to_string("/proc/cpuinfo") else {
        return Vec::new();
    };

    let mut tokens = Vec::new();
    for line in cpuinfo.lines() {
        let Some((key, value)) = line.split_once(':') else {
            continue;
        };
        let key = key.trim().to_ascii_lowercase();
        if key != "features" && key != "flags" {
            continue;
        }
        for token in value.split_whitespace() {
            let token = token.to_ascii_lowercase();
            if !tokens.contains(&token) {
                tokens.push(token);
            }
        }
    }
    tokens
}

fn ensure_original_bytecode(insns: &[kernel_sys::bpf_insn]) -> Result<()> {
    if insns.is_empty() {
        bail!("program has no original bytecode (not loaded by fork kernel?)");
    }
    Ok(())
}

fn insn_raw_bytes(insn: &kernel_sys::bpf_insn) -> [u8; 8] {
    let mut bytes = [0u8; 8];
    bytes[0] = insn.code;
    bytes[1] = (insn.dst_reg() & 0x0f) | ((insn.src_reg() & 0x0f) << 4);
    bytes[2..4].copy_from_slice(&insn.off.to_le_bytes());
    bytes[4..8].copy_from_slice(&insn.imm.to_le_bytes());
    bytes
}

fn c_name_u8(bytes: &[u8]) -> String {
    let end = bytes.iter().position(|&b| b == 0).unwrap_or(bytes.len());
    String::from_utf8_lossy(&bytes[..end]).to_string()
}

fn c_name_i8(bytes: &[std::os::raw::c_char]) -> String {
    let bytes = bytes.iter().map(|&b| b as u8).collect::<Vec<_>>();
    c_name_u8(&bytes)
}

fn prog_type_name(value: u32) -> &'static str {
    match value {
        v if v == kernel_sys::BPF_PROG_TYPE_UNSPEC => "unspec",
        v if v == kernel_sys::BPF_PROG_TYPE_SOCKET_FILTER => "socket_filter",
        v if v == kernel_sys::BPF_PROG_TYPE_KPROBE => "kprobe",
        v if v == kernel_sys::BPF_PROG_TYPE_SCHED_CLS => "sched_cls",
        v if v == kernel_sys::BPF_PROG_TYPE_SCHED_ACT => "sched_act",
        v if v == kernel_sys::BPF_PROG_TYPE_TRACEPOINT => "tracepoint",
        v if v == kernel_sys::BPF_PROG_TYPE_XDP => "xdp",
        v if v == kernel_sys::BPF_PROG_TYPE_PERF_EVENT => "perf_event",
        v if v == kernel_sys::BPF_PROG_TYPE_CGROUP_SKB => "cgroup_skb",
        v if v == kernel_sys::BPF_PROG_TYPE_CGROUP_SOCK => "cgroup_sock",
        v if v == kernel_sys::BPF_PROG_TYPE_LWT_IN => "lwt_in",
        v if v == kernel_sys::BPF_PROG_TYPE_LWT_OUT => "lwt_out",
        v if v == kernel_sys::BPF_PROG_TYPE_LWT_XMIT => "lwt_xmit",
        v if v == kernel_sys::BPF_PROG_TYPE_SOCK_OPS => "sock_ops",
        v if v == kernel_sys::BPF_PROG_TYPE_SK_SKB => "sk_skb",
        v if v == kernel_sys::BPF_PROG_TYPE_CGROUP_DEVICE => "cgroup_device",
        v if v == kernel_sys::BPF_PROG_TYPE_SK_MSG => "sk_msg",
        v if v == kernel_sys::BPF_PROG_TYPE_RAW_TRACEPOINT => "raw_tracepoint",
        v if v == kernel_sys::BPF_PROG_TYPE_CGROUP_SOCK_ADDR => "cgroup_sock_addr",
        v if v == kernel_sys::BPF_PROG_TYPE_LWT_SEG6LOCAL => "lwt_seg6local",
        v if v == kernel_sys::BPF_PROG_TYPE_LIRC_MODE2 => "lirc_mode2",
        v if v == kernel_sys::BPF_PROG_TYPE_SK_REUSEPORT => "sk_reuseport",
        v if v == kernel_sys::BPF_PROG_TYPE_FLOW_DISSECTOR => "flow_dissector",
        v if v == kernel_sys::BPF_PROG_TYPE_CGROUP_SYSCTL => "cgroup_sysctl",
        v if v == kernel_sys::BPF_PROG_TYPE_RAW_TRACEPOINT_WRITABLE => "raw_tracepoint_writable",
        v if v == kernel_sys::BPF_PROG_TYPE_CGROUP_SOCKOPT => "cgroup_sockopt",
        v if v == kernel_sys::BPF_PROG_TYPE_TRACING => "tracing",
        v if v == kernel_sys::BPF_PROG_TYPE_STRUCT_OPS => "struct_ops",
        v if v == kernel_sys::BPF_PROG_TYPE_EXT => "ext",
        v if v == kernel_sys::BPF_PROG_TYPE_LSM => "lsm",
        v if v == kernel_sys::BPF_PROG_TYPE_SK_LOOKUP => "sk_lookup",
        v if v == kernel_sys::BPF_PROG_TYPE_SYSCALL => "syscall",
        v if v == kernel_sys::BPF_PROG_TYPE_NETFILTER => "netfilter",
        _ => "unknown",
    }
}

fn attach_type_name(value: u32) -> Option<&'static str> {
    let name = match value {
        v if v == kernel_sys::BPF_CGROUP_INET_INGRESS => "cgroup_inet_ingress",
        v if v == kernel_sys::BPF_CGROUP_INET_EGRESS => "cgroup_inet_egress",
        v if v == kernel_sys::BPF_CGROUP_INET_SOCK_CREATE => "cgroup_inet_sock_create",
        v if v == kernel_sys::BPF_CGROUP_SOCK_OPS => "cgroup_sock_ops",
        v if v == kernel_sys::BPF_SK_SKB_STREAM_PARSER => "sk_skb_stream_parser",
        v if v == kernel_sys::BPF_SK_SKB_STREAM_VERDICT => "sk_skb_stream_verdict",
        v if v == kernel_sys::BPF_CGROUP_DEVICE => "cgroup_device",
        v if v == kernel_sys::BPF_SK_MSG_VERDICT => "sk_msg_verdict",
        v if v == kernel_sys::BPF_CGROUP_INET4_BIND => "cgroup_inet4_bind",
        v if v == kernel_sys::BPF_CGROUP_INET6_BIND => "cgroup_inet6_bind",
        v if v == kernel_sys::BPF_CGROUP_INET4_CONNECT => "cgroup_inet4_connect",
        v if v == kernel_sys::BPF_CGROUP_INET6_CONNECT => "cgroup_inet6_connect",
        v if v == kernel_sys::BPF_CGROUP_INET4_POST_BIND => "cgroup_inet4_post_bind",
        v if v == kernel_sys::BPF_CGROUP_INET6_POST_BIND => "cgroup_inet6_post_bind",
        v if v == kernel_sys::BPF_CGROUP_UDP4_SENDMSG => "cgroup_udp4_sendmsg",
        v if v == kernel_sys::BPF_CGROUP_UDP6_SENDMSG => "cgroup_udp6_sendmsg",
        v if v == kernel_sys::BPF_CGROUP_SYSCTL => "cgroup_sysctl",
        v if v == kernel_sys::BPF_CGROUP_UDP4_RECVMSG => "cgroup_udp4_recvmsg",
        v if v == kernel_sys::BPF_CGROUP_UDP6_RECVMSG => "cgroup_udp6_recvmsg",
        v if v == kernel_sys::BPF_CGROUP_GETSOCKOPT => "cgroup_getsockopt",
        v if v == kernel_sys::BPF_CGROUP_SETSOCKOPT => "cgroup_setsockopt",
        v if v == kernel_sys::BPF_TRACE_RAW_TP => "trace_raw_tp",
        v if v == kernel_sys::BPF_TRACE_FENTRY => "trace_fentry",
        v if v == kernel_sys::BPF_TRACE_FEXIT => "trace_fexit",
        v if v == kernel_sys::BPF_MODIFY_RETURN => "modify_return",
        v if v == kernel_sys::BPF_LSM_MAC => "lsm_mac",
        v if v == kernel_sys::BPF_TRACE_ITER => "trace_iter",
        v if v == kernel_sys::BPF_CGROUP_INET4_GETPEERNAME => "cgroup_inet4_getpeername",
        v if v == kernel_sys::BPF_CGROUP_INET6_GETPEERNAME => "cgroup_inet6_getpeername",
        v if v == kernel_sys::BPF_CGROUP_INET4_GETSOCKNAME => "cgroup_inet4_getsockname",
        v if v == kernel_sys::BPF_CGROUP_INET6_GETSOCKNAME => "cgroup_inet6_getsockname",
        v if v == kernel_sys::BPF_XDP_DEVMAP => "xdp_devmap",
        v if v == kernel_sys::BPF_CGROUP_INET_SOCK_RELEASE => "cgroup_inet_sock_release",
        v if v == kernel_sys::BPF_XDP_CPUMAP => "xdp_cpumap",
        v if v == kernel_sys::BPF_SK_LOOKUP => "sk_lookup",
        v if v == kernel_sys::BPF_XDP => "xdp",
        v if v == kernel_sys::BPF_SK_SKB_VERDICT => "sk_skb_verdict",
        v if v == kernel_sys::BPF_SK_REUSEPORT_SELECT => "sk_reuseport_select",
        v if v == kernel_sys::BPF_SK_REUSEPORT_SELECT_OR_MIGRATE => {
            "sk_reuseport_select_or_migrate"
        }
        v if v == kernel_sys::BPF_TRACE_KPROBE_MULTI => "trace_kprobe_multi",
        v if v == kernel_sys::BPF_LSM_CGROUP => "lsm_cgroup",
        v if v == kernel_sys::BPF_NETFILTER => "netfilter",
        v if v == kernel_sys::BPF_TCX_INGRESS => "tcx_ingress",
        v if v == kernel_sys::BPF_TCX_EGRESS => "tcx_egress",
        v if v == kernel_sys::BPF_TRACE_UPROBE_MULTI => "trace_uprobe_multi",
        v if v == kernel_sys::BPF_CGROUP_UNIX_CONNECT => "cgroup_unix_connect",
        v if v == kernel_sys::BPF_CGROUP_UNIX_SENDMSG => "cgroup_unix_sendmsg",
        v if v == kernel_sys::BPF_CGROUP_UNIX_RECVMSG => "cgroup_unix_recvmsg",
        v if v == kernel_sys::BPF_CGROUP_UNIX_GETPEERNAME => "cgroup_unix_getpeername",
        v if v == kernel_sys::BPF_CGROUP_UNIX_GETSOCKNAME => "cgroup_unix_getsockname",
        v if v == kernel_sys::BPF_NETKIT_PRIMARY => "netkit_primary",
        v if v == kernel_sys::BPF_NETKIT_PEER => "netkit_peer",
        v if v == kernel_sys::BPF_TRACE_KPROBE_SESSION => "trace_kprobe_session",
        v if v == kernel_sys::BPF_TRACE_UPROBE_SESSION => "trace_uprobe_session",
        v if v == kernel_sys::BPF_TRACE_FSESSION => "trace_fsession",
        _ => return None,
    };
    Some(name)
}

fn is_zero_u32(value: &u32) -> bool {
    *value == 0
}

fn is_zero_u64(value: &u64) -> bool {
    *value == 0
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn multi_map_relocation_uses_map_idx_order_in_process() {
        let snapshot = test_snapshot(vec![700, 800], vec![]);
        let mut insns = Vec::new();
        insns.extend(ldimm64(BPF_PSEUDO_MAP_IDX, 1));
        insns.push(exit_insn());
        let mut opened = Vec::new();

        let relocated = snapshot
            .relocate_for_load_with(&insns, |map_id| {
                opened.push(map_id);
                Ok(std::fs::File::open("/dev/null")?.into())
            })
            .unwrap();

        assert_eq!(opened, vec![800]);
        assert_eq!(relocated.insns()[0].src_reg(), BPF_PSEUDO_MAP_FD);
        assert!(relocated.insns()[0].imm >= 0);
    }

    #[test]
    fn multi_map_old_fd_relocation_uses_snapshot_bindings() {
        let snapshot = test_snapshot(
            vec![700, 800],
            vec![test_map_info(Some(31), 700), test_map_info(Some(41), 800)],
        );
        let mut insns = Vec::new();
        insns.extend(ldimm64(BPF_PSEUDO_MAP_FD, 41));
        insns.push(exit_insn());
        let mut opened = Vec::new();

        snapshot
            .relocate_for_load_with(&insns, |map_id| {
                opened.push(map_id);
                Ok(std::fs::File::open("/dev/null")?.into())
            })
            .unwrap();

        assert_eq!(opened, vec![800]);
    }

    #[test]
    fn btf_multi_subprog_records_are_preserved_in_memory() {
        let snapshot = ProgramSnapshot {
            info: ProgramInfo {
                id: 7,
                name: "prog".to_string(),
                prog_type: TypeInfo {
                    name: "xdp".to_string(),
                    numeric: kernel_sys::BPF_PROG_TYPE_XDP,
                },
                insn_cnt: 5,
                map_ids: Vec::new(),
                load_time: 0,
                created_by_uid: 0,
                xlated_prog_len: 40,
                orig_prog_len: 40,
                jited_prog_len: 0,
                btf_id: 10,
                prog_flags: 0,
                func_info_rec_size: 8,
                nr_func_info: 2,
                line_info_rec_size: 16,
                nr_line_info: 2,
                attach_btf_obj_id: 0,
                attach_btf_id: 0,
                expected_attach_type: None,
            },
            maps: Vec::new(),
            insns: vec![exit_insn(); 5],
            btf: ProgramBtfInfo {
                func_info_rec_size: 8,
                func_info: [record(0, 1, 8), record(4, 2, 8)].concat(),
                line_info_rec_size: 16,
                line_info: [record(0, 10, 16), record(4, 20, 16)].concat(),
            },
        };

        assert_eq!(snapshot.btf.func_info.len(), 16);
        assert_eq!(btf_offsets(&snapshot.btf.func_info, 8), vec![0, 4]);
        assert_eq!(btf_offsets(&snapshot.btf.line_info, 16), vec![0, 4]);
    }

    fn test_snapshot(map_ids: Vec<u32>, maps: Vec<MapInfo>) -> ProgramSnapshot {
        ProgramSnapshot {
            info: ProgramInfo {
                id: 1,
                name: "x".to_string(),
                prog_type: TypeInfo {
                    name: "xdp".to_string(),
                    numeric: kernel_sys::BPF_PROG_TYPE_XDP,
                },
                insn_cnt: 0,
                map_ids,
                load_time: 0,
                created_by_uid: 0,
                xlated_prog_len: 0,
                orig_prog_len: 0,
                jited_prog_len: 0,
                btf_id: 0,
                prog_flags: 0,
                func_info_rec_size: 0,
                nr_func_info: 0,
                line_info_rec_size: 0,
                nr_line_info: 0,
                attach_btf_obj_id: 0,
                attach_btf_id: 0,
                expected_attach_type: None,
            },
            maps,
            insns: Vec::new(),
            btf: ProgramBtfInfo::default(),
        }
    }

    fn test_map_info(old_fd: Option<i32>, map_id: u32) -> MapInfo {
        MapInfo {
            old_fd,
            map_id,
            map_type: kernel_sys::BPF_MAP_TYPE_ARRAY,
            key_size: 4,
            value_size: 4,
            max_entries: 1,
            name: String::new(),
            map_flags: 0,
            ifindex: 0,
            btf_id: 0,
            btf_key_type_id: 0,
            btf_value_type_id: 0,
            btf_vmlinux_value_type_id: 0,
            btf_vmlinux_id: 0,
            map_extra: 0,
        }
    }

    fn ldimm64(src_reg: u8, imm: i32) -> [kernel_sys::bpf_insn; 2] {
        let mut first = kernel_sys::bpf_insn {
            code: BPF_LD_IMM64,
            _bitfield_align_1: [],
            _bitfield_1: Default::default(),
            off: 0,
            imm,
        };
        first.set_src_reg(src_reg);
        let second = kernel_sys::bpf_insn {
            code: 0,
            _bitfield_align_1: [],
            _bitfield_1: Default::default(),
            off: 0,
            imm: 0,
        };
        [first, second]
    }

    fn exit_insn() -> kernel_sys::bpf_insn {
        kernel_sys::bpf_insn {
            code: (kernel_sys::BPF_JMP | kernel_sys::BPF_EXIT) as u8,
            _bitfield_align_1: [],
            _bitfield_1: Default::default(),
            off: 0,
            imm: 0,
        }
    }

    fn record(insn_off: u32, second_word: u32, rec_size: usize) -> Vec<u8> {
        let mut record = vec![0; rec_size];
        record[0..4].copy_from_slice(&insn_off.to_le_bytes());
        record[4..8].copy_from_slice(&second_word.to_le_bytes());
        record
    }

    fn btf_offsets(bytes: &[u8], rec_size: usize) -> Vec<u32> {
        bytes
            .chunks(rec_size)
            .map(|record| u32::from_le_bytes(record[0..4].try_into().unwrap()))
            .collect()
    }
}
