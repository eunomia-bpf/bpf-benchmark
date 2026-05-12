// SPDX-License-Identifier: MIT
//! BPF subsystem access adapter for daemon-owned live discovery and map snapshot paths.
//!
//! Standard BPF access is routed through daemon-owned syscall helpers and
//! libbpf-sys. This module owns live program discovery, target probing, and map
//! helpers; per-pass `BPF_PROG_REJIT` is still called by commands.rs.

use std::collections::BTreeMap;
use std::os::fd::{AsFd, BorrowedFd, OwnedFd};

use anyhow::{bail, Context, Result};
use libbpf_sys::bpf_insn;
use serde::{Deserialize, Serialize};

use crate::syscall;

#[derive(Clone, Debug, Serialize, Deserialize, PartialEq, Eq)]
pub(crate) struct TypeInfo {
    pub(crate) name: String,
    pub(crate) numeric: u32,
}

#[derive(Clone, Debug, Serialize, Deserialize, PartialEq, Eq)]
pub(crate) struct ProgramInfo {
    pub(crate) id: u32,
    pub(crate) name: String,
    #[serde(rename = "type")]
    pub(crate) prog_type: TypeInfo,
    pub(crate) insn_cnt: u32,
    pub(crate) map_ids: Vec<u32>,
}

#[derive(Clone, Debug, Serialize, Deserialize, PartialEq, Eq)]
pub(crate) struct MapInfo {
    pub(crate) map_id: u32,
    pub(crate) name: String,
    pub(crate) map_type: u32,
    pub(crate) key_size: u32,
    pub(crate) value_size: u32,
    pub(crate) max_entries: u32,
}

#[derive(Clone, Debug)]
pub(crate) struct ProgramSnapshot {
    pub(crate) info: ProgramInfo,
    pub(crate) maps: Vec<MapInfo>,
    pub(crate) insns: Vec<bpf_insn>,
}

#[derive(Clone, Debug, Serialize, Deserialize, PartialEq, Eq)]
pub(crate) struct TargetJson {
    pub(crate) arch: String,
    pub(crate) features: Vec<String>,
    pub(crate) kinsns: BTreeMap<String, TargetKinsnJson>,
}

#[derive(Clone, Debug, Serialize, Deserialize, PartialEq, Eq)]
pub(crate) struct TargetKinsnJson {
    pub(crate) btf_func_id: i32,
    pub(crate) btf_id: u32,
    /// Non-zero REJIT fd_array index where this BTF module's fd lives.
    /// call_offset=0 means the function lives in vmlinux BTF (no fd needed).
    /// Assigned sequentially as kinsn-providing module BTF IDs are discovered.
    pub(crate) call_offset: u32,
}

#[derive(Clone, Debug, PartialEq, Eq)]
#[rustfmt::skip] pub(crate) struct KinsnProbeTarget { pub(crate) json_name: String, pub(crate) probe_names: Vec<String> }

pub(crate) fn snapshot_program(prog_id: u32) -> Result<ProgramSnapshot> {
    let fd = syscall::prog_get_fd_by_id(prog_id)
        .with_context(|| format!("open BPF program id {prog_id}"))?;
    let insns = syscall::prog_get_original(fd.as_fd())
        .with_context(|| format!("read original bytecode for BPF program id {prog_id}"))?;
    if insns.is_empty() {
        bail!("program has no original bytecode (not loaded by fork kernel?)");
    }
    let (info, map_ids) = get_prog_info_with_map_ids_from_fd(fd.as_fd(), prog_id)?;
    let maps = get_map_infos(&map_ids)?;
    Ok(ProgramSnapshot {
        info: ProgramInfo::from_info(info, map_ids),
        maps,
        insns,
    })
}

pub(crate) fn target_json_for_probes(targets: &[KinsnProbeTarget]) -> Result<TargetJson> {
    if targets.is_empty() {
        return Ok(TargetJson {
            arch: detect_arch(),
            features: detect_features(),
            kinsns: BTreeMap::new(),
        });
    }
    probe_target_json(targets)
}

pub(crate) fn probe_target_json(targets: &[KinsnProbeTarget]) -> Result<TargetJson> {
    if targets.is_empty() {
        bail!("target probing requested with no kinsn targets");
    }
    let kinsns = probe_target_kinsns(targets).with_context(|| {
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

pub(crate) fn encode_insns(insns: &[bpf_insn]) -> Vec<u8> {
    let mut bytes = Vec::with_capacity(std::mem::size_of_val(insns));
    for insn in insns {
        bytes.push(insn.code);
        bytes.push((insn.dst_reg() & 0x0f) | ((insn.src_reg() & 0x0f) << 4));
        bytes.extend_from_slice(&insn.off.to_le_bytes());
        bytes.extend_from_slice(&insn.imm.to_le_bytes());
    }
    bytes
}

impl ProgramInfo {
    fn from_info(info: syscall::BpfProgInfoFork, map_ids: Vec<u32>) -> Self {
        let insn_size = std::mem::size_of::<libbpf_sys::bpf_insn>() as u32;
        let insn_bytes = if info.orig_prog_len != 0 {
            info.orig_prog_len
        } else {
            info.xlated_prog_len
        };
        Self {
            id: info.id,
            name: c_name_u8(&info.name),
            prog_type: TypeInfo {
                name: prog_type_name(info.prog_type).to_string(),
                numeric: info.prog_type,
            },
            insn_cnt: insn_bytes / insn_size,
            map_ids,
        }
    }
}

fn get_prog_info_with_map_ids_from_fd(
    fd: BorrowedFd<'_>,
    prog_id: u32,
) -> Result<(syscall::BpfProgInfoFork, Vec<u32>)> {
    let info = syscall::obj_get_info_by_fd(fd)
        .with_context(|| format!("read info for BPF program id {prog_id}"))?;
    let map_ids = syscall::prog_map_ids(fd, info.nr_map_ids)
        .with_context(|| format!("read map ids for BPF program id {prog_id}"))?;
    Ok((info, map_ids))
}

fn get_map_infos(map_ids: &[u32]) -> Result<Vec<MapInfo>> {
    let mut maps = Vec::with_capacity(map_ids.len());
    for &map_id in map_ids {
        maps.push(bpf_map_info_by_id(map_id)?);
    }
    Ok(maps)
}

pub(crate) fn bpf_map_info_by_id(map_id: u32) -> Result<MapInfo> {
    let fd =
        syscall::map_get_fd_by_id(map_id).with_context(|| format!("open BPF map id {map_id}"))?;
    let info = syscall::map_obj_get_info_by_fd(fd.as_fd())
        .with_context(|| format!("read info for BPF map id {map_id}"))?;
    Ok(MapInfo {
        map_id,
        name: c_name_u8(unsafe {
            std::slice::from_raw_parts(info.name.as_ptr() as *const u8, info.name.len())
        }),
        map_type: info.type_,
        key_size: info.key_size,
        value_size: info.value_size,
        max_entries: info.max_entries,
    })
}

fn probe_target_kinsns(targets: &[KinsnProbeTarget]) -> Result<BTreeMap<String, TargetKinsnJson>> {
    let mut found = BTreeMap::new();
    let mut start_id = 0u32;
    let mut saw_btf = false;
    let vmlinux_btf =
        syscall::KernelBtf::load_vmlinux().context("load vmlinux BTF for split BTF probing")?;

    // Maps each distinct kinsn-providing BTF module object ID to its non-zero
    // fd_array index. vmlinux uses call_offset=0 and does not consume fd_array
    // space. Modules without target kinsns must not consume holes.
    let mut module_slot_map: BTreeMap<u32, u32> = BTreeMap::new();
    let mut next_slot: u32 = 1;

    loop {
        let Some(btf_id) = syscall::btf_get_next_id(start_id)
            .with_context(|| format!("enumerate BTF objects after id {start_id}"))?
        else {
            break;
        };
        saw_btf = true;
        start_id = btf_id;

        // Distinguish vmlinux (loads standalone) from module BTF (split BTF).
        // If load_from_kernel_by_id succeeds, it is a standalone (vmlinux) BTF
        // object, which uses call_offset=0. If it fails and split-BTF loading
        // succeeds, it is a kernel module BTF, which needs a fd_array slot.
        let (btf, is_module) = match syscall::KernelBtf::load_from_kernel_by_id(btf_id) {
            Ok(btf) => (btf, false),
            Err(err) => {
                let btf = syscall::KernelBtf::load_from_kernel_by_id_split(btf_id, &vmlinux_btf)
                    .with_context(|| {
                        format!("load split BTF id {btf_id}; direct BTF load failed: {err:#}")
                    })?;
                (btf, true)
            }
        };

        probe_kinsns_in_btf(
            btf_id,
            is_module,
            &btf,
            &mut module_slot_map,
            &mut next_slot,
            &mut found,
            targets,
        )?;

        if found.len() == targets.len() {
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
    is_module: bool,
    btf: &syscall::KernelBtf,
    module_slot_map: &mut BTreeMap<u32, u32>,
    next_slot: &mut u32,
    found: &mut BTreeMap<String, TargetKinsnJson>,
    targets: &[KinsnProbeTarget],
) -> Result<()> {
    for target in targets {
        if found.contains_key(&target.json_name) {
            continue;
        }
        for probe_name in &target.probe_names {
            if let Some(btf_func_id) = btf
                .find_func_by_name(probe_name)
                .with_context(|| format!("inspect BTF id {btf_id} for {probe_name}"))?
            {
                let Ok(btf_func_id) = i32::try_from(btf_func_id) else {
                    bail!(
                        "BTF id {btf_id} function {probe_name} type id {btf_func_id} exceeds target.json i32 range"
                    );
                };
                let call_offset = if is_module {
                    match module_slot_map.entry(btf_id) {
                        std::collections::btree_map::Entry::Occupied(entry) => *entry.get(),
                        std::collections::btree_map::Entry::Vacant(entry) => {
                            let slot = *next_slot;
                            *next_slot = next_slot.checked_add(1).ok_or_else(|| {
                                anyhow::anyhow!("BTF module call_offset overflow after slot {slot}")
                            })?;
                            entry.insert(slot);
                            slot
                        }
                    }
                } else {
                    0
                };
                found.insert(
                    target.json_name.clone(),
                    TargetKinsnJson {
                        btf_func_id,
                        btf_id,
                        call_offset,
                    },
                );
                break;
            }
        }
    }
    Ok(())
}

pub(crate) fn bpf_map_get_fd_by_id(id: u32) -> Result<OwnedFd> {
    syscall::map_get_fd_by_id(id).with_context(|| format!("open BPF map id {id}"))
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

    // ARM64: bpfopt does not consume per-CPU ARM64 features yet (passes branch
    // on PlatformCapabilities.arch == Aarch64). Emit nothing here; add features
    // back when bpfopt grows ARM64 fine-grained feature gating.

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

fn c_name_u8(bytes: &[u8]) -> String {
    let end = bytes.iter().position(|&b| b == 0).unwrap_or(bytes.len());
    String::from_utf8_lossy(&bytes[..end]).to_string()
}

fn prog_type_name(value: u32) -> &'static str {
    match value {
        v if v == libbpf_sys::BPF_PROG_TYPE_UNSPEC => "unspec",
        v if v == libbpf_sys::BPF_PROG_TYPE_SOCKET_FILTER => "socket_filter",
        v if v == libbpf_sys::BPF_PROG_TYPE_KPROBE => "kprobe",
        v if v == libbpf_sys::BPF_PROG_TYPE_SCHED_CLS => "sched_cls",
        v if v == libbpf_sys::BPF_PROG_TYPE_SCHED_ACT => "sched_act",
        v if v == libbpf_sys::BPF_PROG_TYPE_TRACEPOINT => "tracepoint",
        v if v == libbpf_sys::BPF_PROG_TYPE_XDP => "xdp",
        v if v == libbpf_sys::BPF_PROG_TYPE_PERF_EVENT => "perf_event",
        v if v == libbpf_sys::BPF_PROG_TYPE_CGROUP_SKB => "cgroup_skb",
        v if v == libbpf_sys::BPF_PROG_TYPE_CGROUP_SOCK => "cgroup_sock",
        v if v == libbpf_sys::BPF_PROG_TYPE_LWT_IN => "lwt_in",
        v if v == libbpf_sys::BPF_PROG_TYPE_LWT_OUT => "lwt_out",
        v if v == libbpf_sys::BPF_PROG_TYPE_LWT_XMIT => "lwt_xmit",
        v if v == libbpf_sys::BPF_PROG_TYPE_SOCK_OPS => "sock_ops",
        v if v == libbpf_sys::BPF_PROG_TYPE_SK_SKB => "sk_skb",
        v if v == libbpf_sys::BPF_PROG_TYPE_CGROUP_DEVICE => "cgroup_device",
        v if v == libbpf_sys::BPF_PROG_TYPE_SK_MSG => "sk_msg",
        v if v == libbpf_sys::BPF_PROG_TYPE_RAW_TRACEPOINT => "raw_tracepoint",
        v if v == libbpf_sys::BPF_PROG_TYPE_CGROUP_SOCK_ADDR => "cgroup_sock_addr",
        v if v == libbpf_sys::BPF_PROG_TYPE_LWT_SEG6LOCAL => "lwt_seg6local",
        v if v == libbpf_sys::BPF_PROG_TYPE_LIRC_MODE2 => "lirc_mode2",
        v if v == libbpf_sys::BPF_PROG_TYPE_SK_REUSEPORT => "sk_reuseport",
        v if v == libbpf_sys::BPF_PROG_TYPE_FLOW_DISSECTOR => "flow_dissector",
        v if v == libbpf_sys::BPF_PROG_TYPE_CGROUP_SYSCTL => "cgroup_sysctl",
        v if v == libbpf_sys::BPF_PROG_TYPE_RAW_TRACEPOINT_WRITABLE => "raw_tracepoint_writable",
        v if v == libbpf_sys::BPF_PROG_TYPE_CGROUP_SOCKOPT => "cgroup_sockopt",
        v if v == libbpf_sys::BPF_PROG_TYPE_TRACING => "tracing",
        v if v == libbpf_sys::BPF_PROG_TYPE_STRUCT_OPS => "struct_ops",
        v if v == libbpf_sys::BPF_PROG_TYPE_EXT => "ext",
        v if v == libbpf_sys::BPF_PROG_TYPE_LSM => "lsm",
        v if v == libbpf_sys::BPF_PROG_TYPE_SK_LOOKUP => "sk_lookup",
        v if v == libbpf_sys::BPF_PROG_TYPE_SYSCALL => "syscall",
        v if v == libbpf_sys::BPF_PROG_TYPE_NETFILTER => "netfilter",
        _ => "unknown",
    }
}
