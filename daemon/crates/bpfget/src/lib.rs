// SPDX-License-Identifier: MIT
//! In-process live BPF program discovery for `bpfrejit-daemon`.

use std::collections::BTreeMap;
use std::os::fd::{AsFd, BorrowedFd};

use anyhow::{bail, Context, Result};
use serde::{Deserialize, Serialize};

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
    pub attach_btf_obj_id: u32,
    pub attach_btf_id: u32,
    #[serde(skip_serializing_if = "Option::is_none")]
    pub expected_attach_type: Option<TypeInfo>,
}

#[derive(Clone, Debug, Serialize, Deserialize, PartialEq, Eq)]
pub struct MapInfo {
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

#[derive(Clone, Debug)]
pub struct ProgramSnapshot {
    pub info: ProgramInfo,
    pub maps: Vec<MapInfo>,
    pub insns: Vec<kernel_sys::bpf_insn>,
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
    /// Non-zero REJIT fd_array index where this BTF module's fd lives.
    /// call_offset=0 means the function lives in vmlinux BTF (no fd needed).
    /// Assigned sequentially as kinsn-providing module BTF IDs are discovered.
    pub call_offset: u32,
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
    let insns = kernel_sys::prog_get_original(fd.as_fd())
        .with_context(|| format!("read original bytecode for BPF program id {prog_id}"))?;
    if insns.is_empty() {
        bail!("program has no original bytecode (not loaded by fork kernel?)");
    }
    let (info, map_ids) = get_prog_info_with_map_ids_from_fd(fd.as_fd(), prog_id)?;
    let expected_attach_type = expected_attach_type_json(info.id, info.prog_type)?;
    let maps = get_map_infos(&map_ids)?;
    Ok(ProgramSnapshot {
        info: ProgramInfo::from_info(info, map_ids, expected_attach_type),
        maps,
        insns,
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
    ) -> Self {
        let insn_size = std::mem::size_of::<kernel_sys::bpf_insn>() as u32;
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
            load_time: info.load_time,
            created_by_uid: info.created_by_uid,
            xlated_prog_len: info.xlated_prog_len,
            orig_prog_len: info.orig_prog_len,
            jited_prog_len: info.jited_prog_len,
            btf_id: info.btf_id,
            prog_flags: info.prog_flags,
            attach_btf_obj_id: info.attach_btf_obj_id,
            attach_btf_id: info.attach_btf_id,
            expected_attach_type,
        }
    }
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

fn get_map_infos(map_ids: &[u32]) -> Result<Vec<MapInfo>> {
    let mut maps = Vec::with_capacity(map_ids.len());
    for &map_id in map_ids {
        let fd = kernel_sys::map_get_fd_by_id(map_id)
            .with_context(|| format!("open BPF map id {map_id}"))?;
        let info = kernel_sys::map_obj_get_info_by_fd(fd.as_fd())
            .with_context(|| format!("read info for BPF map id {map_id}"))?;
        maps.push(MapInfo {
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

fn probe_target_kinsns() -> Result<BTreeMap<String, TargetKinsnJson>> {
    let mut found = BTreeMap::new();
    let mut start_id = 0u32;
    let mut saw_btf = false;
    let vmlinux_btf =
        kernel_sys::KernelBtf::load_vmlinux().context("load vmlinux BTF for split BTF probing")?;

    // Maps each distinct kinsn-providing BTF module object ID to its non-zero
    // fd_array index. vmlinux uses call_offset=0 and does not consume fd_array
    // space. Modules without target kinsns must not consume holes.
    let mut module_slot_map: BTreeMap<u32, u32> = BTreeMap::new();
    let mut next_slot: u32 = 1;

    loop {
        let Some(btf_id) = kernel_sys::btf_get_next_id(start_id)
            .with_context(|| format!("enumerate BTF objects after id {start_id}"))?
        else {
            break;
        };
        saw_btf = true;
        start_id = btf_id;

        // Distinguish vmlinux (loads standalone) from module BTF (split BTF).
        // If load_from_kernel_by_id succeeds, it is a standalone (vmlinux) BTF
        // object, which uses call_offset=0.  If it fails and split-BTF loading
        // succeeds, it is a kernel module BTF, which needs a fd_array slot.
        let (btf, is_module) = match kernel_sys::KernelBtf::load_from_kernel_by_id(btf_id) {
            Ok(btf) => (btf, false),
            Err(err) => {
                let btf = kernel_sys::KernelBtf::load_from_kernel_by_id_split(btf_id, &vmlinux_btf)
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
        )?;

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
    is_module: bool,
    btf: &kernel_sys::KernelBtf,
    module_slot_map: &mut BTreeMap<u32, u32>,
    next_slot: &mut u32,
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
                    target.json_name.to_string(),
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
