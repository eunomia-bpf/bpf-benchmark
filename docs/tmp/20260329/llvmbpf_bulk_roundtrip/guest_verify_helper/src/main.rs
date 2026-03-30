use std::collections::HashMap;
use std::ffi::CString;
use std::fs;
use std::os::unix::io::{AsRawFd, OwnedFd, RawFd};
use std::path::PathBuf;

use anyhow::{bail, Context, Result};
use serde::Serialize;

#[path = "../../../../../../daemon/src/bpf.rs"]
mod bpf;
#[path = "../../../../../../daemon/src/insn.rs"]
mod insn;

use insn::BpfInsn;

const BPF_PROG_LOAD: u32 = 5;
const BPF_OBJ_NAME_LEN: usize = 16;
const BPF_PSEUDO_MAP_FD: u8 = 1;
const BPF_PSEUDO_MAP_VALUE: u8 = 2;

#[cfg(target_arch = "x86_64")]
const SYS_BPF: libc::c_long = 321;

#[cfg(target_arch = "aarch64")]
const SYS_BPF: libc::c_long = 280;

#[repr(C)]
struct AttrProgLoad {
    prog_type: u32,
    insn_cnt: u32,
    insns: u64,
    license: u64,
    log_level: u32,
    log_size: u32,
    log_buf: u64,
    kern_version: u32,
    prog_flags: u32,
    prog_name: [u8; BPF_OBJ_NAME_LEN],
    prog_ifindex: u32,
    expected_attach_type: u32,
    prog_btf_fd: u32,
    func_info_rec_size: u32,
    func_info: u64,
    func_info_cnt: u32,
    line_info_rec_size: u32,
    line_info: u64,
    line_info_cnt: u32,
    attach_btf_id: u32,
    attach_fd: u32,
    core_relo_cnt: u32,
    fd_array: u64,
    core_relos: u64,
    core_relo_rec_size: u32,
    log_true_size: u32,
    prog_token_fd: i32,
    fd_array_cnt: u32,
    signature: u64,
    signature_size: u32,
    keyring_id: i32,
}

#[derive(Serialize)]
struct VerifyOutput {
    program_name: String,
    program_id: u32,
    program_type: u32,
    expected_attach_type: u32,
    map_id_count: usize,
    original_insn_count: usize,
    roundtrip_insn_count: usize,
    status: String,
    error: Option<String>,
    verifier_log: String,
    map_repair: MapRepairSummary,
}

#[derive(Clone, Default, Serialize)]
struct MapRepairSummary {
    explicit_fd_bindings: usize,
    original_helper_map_sites: usize,
    matched_helper_map_sites: usize,
    inserted_ldimm64_pairs: usize,
}

#[derive(Clone, Copy)]
struct HelperMapSite {
    helper_id: i32,
    ldimm64: [BpfInsn; 2],
}

#[derive(Clone, Copy)]
struct PlannedInsertion {
    before_old_pc: usize,
    ldimm64: [BpfInsn; 2],
}

fn parse_args() -> Result<(u32, PathBuf, Option<u32>)> {
    let mut prog_id: Option<u32> = None;
    let mut roundtrip_bin: Option<PathBuf> = None;
    let mut expected_attach_type: Option<u32> = None;

    let mut args = std::env::args().skip(1);
    while let Some(arg) = args.next() {
        match arg.as_str() {
            "--prog-id" => {
                let value = args.next().context("missing value after --prog-id")?;
                prog_id = Some(value.parse().context("invalid integer for --prog-id")?);
            }
            "--roundtrip-bin" => {
                let value = args.next().context("missing value after --roundtrip-bin")?;
                roundtrip_bin = Some(PathBuf::from(value));
            }
            "--expected-attach-type" => {
                let value = args
                    .next()
                    .context("missing value after --expected-attach-type")?;
                expected_attach_type = Some(
                    value
                        .parse()
                        .context("invalid integer for --expected-attach-type")?,
                );
            }
            other => bail!("unknown argument: {}", other),
        }
    }

    let prog_id = prog_id.context("--prog-id is required")?;
    let roundtrip_bin = roundtrip_bin.context("--roundtrip-bin is required")?;
    Ok((prog_id, roundtrip_bin, expected_attach_type))
}

fn parse_bpf_insn_bytes(bytes: &[u8]) -> Result<Vec<BpfInsn>> {
    if bytes.len() % std::mem::size_of::<BpfInsn>() != 0 {
        bail!(
            "roundtrip bytecode length {} is not a multiple of {}",
            bytes.len(),
            std::mem::size_of::<BpfInsn>()
        );
    }

    let mut insns = Vec::with_capacity(bytes.len() / std::mem::size_of::<BpfInsn>());
    for chunk in bytes.chunks_exact(8) {
        let code = chunk[0];
        let regs = chunk[1];
        let off = i16::from_le_bytes([chunk[2], chunk[3]]);
        let imm = i32::from_le_bytes([chunk[4], chunk[5], chunk[6], chunk[7]]);
        insns.push(BpfInsn {
            code,
            regs,
            off,
            imm,
        });
    }
    Ok(insns)
}

fn is_pseudo_map_ldimm64(insn: &BpfInsn) -> bool {
    insn.is_ldimm64() && matches!(insn.src_reg(), BPF_PSEUDO_MAP_FD | BPF_PSEUDO_MAP_VALUE)
}

fn writes_reg(insn: &BpfInsn, reg: u8) -> bool {
    match insn.class() {
        insn::BPF_LD | insn::BPF_LDX | insn::BPF_ALU | insn::BPF_ALU64 => insn.dst_reg() == reg,
        insn::BPF_JMP | insn::BPF_JMP32 => insn.is_call() && reg == 0,
        _ => false,
    }
}

fn build_map_fd_bindings(orig_insns: &[BpfInsn], map_ids: &[u32]) -> HashMap<i32, u32> {
    let mut bindings = HashMap::new();
    let mut unique_old_fds = Vec::new();

    let mut pc = 0usize;
    while pc < orig_insns.len() {
        let insn = orig_insns[pc];
        if is_pseudo_map_ldimm64(&insn) && !unique_old_fds.contains(&insn.imm) {
            unique_old_fds.push(insn.imm);
        }
        pc += if insn.is_ldimm64() { 2 } else { 1 };
    }

    for (index, old_fd) in unique_old_fds.into_iter().enumerate() {
        if let Some(&map_id) = map_ids.get(index) {
            bindings.insert(old_fd, map_id);
        }
    }
    bindings
}

fn collect_helper_map_sites(orig_insns: &[BpfInsn]) -> Vec<HelperMapSite> {
    let mut sites = Vec::new();
    let mut pc = 0usize;

    while pc < orig_insns.len() {
        let insn = orig_insns[pc];
        if !is_pseudo_map_ldimm64(&insn) {
            pc += if insn.is_ldimm64() { 2 } else { 1 };
            continue;
        }
        if pc + 1 >= orig_insns.len() {
            break;
        }

        let tracked_reg = insn.dst_reg();
        let ldimm64 = [orig_insns[pc], orig_insns[pc + 1]];
        let mut scan = pc + 2;
        while scan < orig_insns.len() {
            let candidate = orig_insns[scan];
            if candidate.is_call() {
                if candidate.src_reg() == 0 {
                    sites.push(HelperMapSite {
                        helper_id: candidate.imm,
                        ldimm64,
                    });
                }
                break;
            }
            if candidate.is_cond_jmp() || candidate.is_ja() || candidate.is_exit() {
                break;
            }
            if writes_reg(&candidate, tracked_reg) {
                break;
            }
            scan += if candidate.is_ldimm64() { 2 } else { 1 };
        }
        pc += 2;
    }

    sites
}

fn collect_roundtrip_helper_calls(insns: &[BpfInsn]) -> Vec<(usize, i32)> {
    insns
        .iter()
        .enumerate()
        .filter_map(|(pc, insn)| {
            if insn.is_call() && insn.src_reg() == 0 {
                Some((pc, insn.imm))
            } else {
                None
            }
        })
        .collect()
}

fn plan_helper_map_insertions(
    roundtrip_insns: &[BpfInsn],
    helper_map_sites: &[HelperMapSite],
) -> Vec<PlannedInsertion> {
    let roundtrip_calls = collect_roundtrip_helper_calls(roundtrip_insns);
    let mut planned = Vec::new();
    let mut call_index = 0usize;

    for site in helper_map_sites {
        while call_index < roundtrip_calls.len() && roundtrip_calls[call_index].1 != site.helper_id
        {
            call_index += 1;
        }
        if call_index >= roundtrip_calls.len() {
            break;
        }
        planned.push(PlannedInsertion {
            before_old_pc: roundtrip_calls[call_index].0,
            ldimm64: site.ldimm64,
        });
        call_index += 1;
    }

    planned
}

fn apply_insertions_with_pc_fixups(
    insns: &[BpfInsn],
    insertions: &[PlannedInsertion],
) -> Result<Vec<BpfInsn>> {
    if insertions.is_empty() {
        return Ok(insns.to_vec());
    }

    let mut insert_before = HashMap::new();
    for insertion in insertions {
        if insert_before
            .insert(insertion.before_old_pc, insertion.ldimm64)
            .is_some()
        {
            bail!(
                "multiple pseudo-map repairs targeted the same instruction pc {}",
                insertion.before_old_pc
            );
        }
    }

    let mut entry_pc = vec![0usize; insns.len()];
    let mut orig_pc = vec![0usize; insns.len()];
    let mut new_insns = Vec::with_capacity(insns.len() + insertions.len() * 2);

    for old_pc in 0..insns.len() {
        entry_pc[old_pc] = new_insns.len();
        if let Some(ldimm64) = insert_before.get(&old_pc) {
            new_insns.extend_from_slice(ldimm64);
        }
        orig_pc[old_pc] = new_insns.len();
        new_insns.push(insns[old_pc]);
    }

    let end_pc = new_insns.len();
    for (old_pc, old_insn) in insns.iter().copied().enumerate() {
        let new_pc = orig_pc[old_pc];

        if old_insn.is_cond_jmp() || old_insn.is_ja() {
            let old_target = old_pc as isize + 1 + old_insn.off as isize;
            if old_target < 0 || old_target > insns.len() as isize {
                bail!(
                    "jump target {} from pc {} is out of range for {}-insn program",
                    old_target,
                    old_pc,
                    insns.len()
                );
            }
            let target_pc = if old_target == insns.len() as isize {
                end_pc
            } else {
                entry_pc[old_target as usize]
            };
            let new_off = target_pc as isize - new_pc as isize - 1;
            if !(i16::MIN as isize..=i16::MAX as isize).contains(&new_off) {
                bail!(
                    "rewritten jump offset {} from pc {} does not fit in i16",
                    new_off,
                    old_pc
                );
            }
            new_insns[new_pc].off = new_off as i16;
            continue;
        }

        if old_insn.is_call() && old_insn.src_reg() == insn::BPF_PSEUDO_CALL {
            let old_target = old_pc as isize + 1 + old_insn.imm as isize;
            if old_target < 0 || old_target > insns.len() as isize {
                bail!(
                    "pseudo-call target {} from pc {} is out of range for {}-insn program",
                    old_target,
                    old_pc,
                    insns.len()
                );
            }
            let target_pc = if old_target == insns.len() as isize {
                end_pc
            } else {
                entry_pc[old_target as usize]
            };
            let new_imm = target_pc as isize - new_pc as isize - 1;
            if !(i32::MIN as isize..=i32::MAX as isize).contains(&new_imm) {
                bail!(
                    "rewritten pseudo-call imm {} from pc {} does not fit in i32",
                    new_imm,
                    old_pc
                );
            }
            new_insns[new_pc].imm = new_imm as i32;
        }
    }

    Ok(new_insns)
}

fn rebuild_helper_map_relocations(
    orig_insns: &[BpfInsn],
    roundtrip_insns: &[BpfInsn],
) -> Result<(Vec<BpfInsn>, MapRepairSummary)> {
    let helper_map_sites = collect_helper_map_sites(orig_insns);
    let insertions = plan_helper_map_insertions(roundtrip_insns, &helper_map_sites);
    let repaired = apply_insertions_with_pc_fixups(roundtrip_insns, &insertions)?;
    Ok((
        repaired,
        MapRepairSummary {
            explicit_fd_bindings: 0,
            original_helper_map_sites: helper_map_sites.len(),
            matched_helper_map_sites: insertions.len(),
            inserted_ldimm64_pairs: insertions.len(),
        },
    ))
}

fn print_json(output: &VerifyOutput) {
    println!(
        "{}",
        serde_json::to_string_pretty(output).expect("VerifyOutput is serializable")
    );
}

fn zeroed_attr<T>() -> T {
    unsafe { std::mem::zeroed() }
}

unsafe fn sys_bpf(cmd: u32, attr: *mut u8, size: u32) -> libc::c_long {
    unsafe { libc::syscall(SYS_BPF, cmd, attr, size) }
}

fn copy_prog_name(dst: &mut [u8; BPF_OBJ_NAME_LEN], name: &str) {
    let bytes = name.as_bytes();
    let len = bytes.len().min(BPF_OBJ_NAME_LEN.saturating_sub(1));
    dst[..len].copy_from_slice(&bytes[..len]);
}

fn extract_log_string(log_buf: &[u8]) -> String {
    let nul_pos = log_buf
        .iter()
        .position(|&b| b == 0)
        .unwrap_or(log_buf.len());
    String::from_utf8_lossy(&log_buf[..nul_pos]).into_owned()
}

fn run_prog_load_verify_without_debug_info(
    info: &bpf::BpfProgInfo,
    expected_attach_type: u32,
    insns: &[BpfInsn],
    fd_array: &[RawFd],
) -> Result<String> {
    if info.prog_type == 28 {
        bail!("BPF_PROG_TYPE_EXT verify requires attach_prog_fd reconstruction, which is not implemented");
    }

    let prog_btf_fd = if info.btf_id != 0 {
        Some(
            bpf::bpf_btf_get_fd_by_id(info.btf_id)
                .with_context(|| format!("open prog BTF object {}", info.btf_id))?,
        )
    } else {
        None
    };
    let attach_btf_obj_fd = if info.attach_btf_obj_id != 0 {
        Some(
            bpf::bpf_btf_get_fd_by_id(info.attach_btf_obj_id)
                .with_context(|| format!("open attach BTF object {}", info.attach_btf_obj_id))?,
        )
    } else {
        None
    };

    let license = CString::new(if info.gpl_compatible_pad & 1 != 0 {
        "GPL"
    } else {
        "MIT"
    })
    .expect("static license strings never contain NUL");

    let mut attr: AttrProgLoad = zeroed_attr();
    let mut log_buf = vec![0u8; 16 * 1024 * 1024];
    attr.prog_type = info.prog_type;
    attr.insn_cnt = insns.len() as u32;
    attr.insns = insns.as_ptr() as u64;
    attr.license = license.as_ptr() as u64;
    attr.log_level = 2;
    attr.log_size = log_buf.len() as u32;
    attr.log_buf = log_buf.as_mut_ptr() as u64;
    attr.prog_ifindex = info.ifindex;
    attr.expected_attach_type = expected_attach_type;
    if let Some(fd) = prog_btf_fd.as_ref().map(OwnedFd::as_raw_fd) {
        attr.prog_btf_fd = fd as u32;
    }
    attr.attach_btf_id = info.attach_btf_id;
    if let Some(fd) = attach_btf_obj_fd.as_ref().map(OwnedFd::as_raw_fd) {
        attr.attach_fd = fd as u32;
    }
    copy_prog_name(&mut attr.prog_name, info.name_str());
    if !fd_array.is_empty() {
        attr.fd_array = fd_array.as_ptr() as u64;
        attr.fd_array_cnt = fd_array.len() as u32;
    }

    let ret = unsafe {
        sys_bpf(
            BPF_PROG_LOAD,
            &mut attr as *mut _ as *mut u8,
            std::mem::size_of::<AttrProgLoad>() as u32,
        )
    };
    let verifier_log = extract_log_string(&log_buf);
    if ret < 0 {
        let os_err = std::io::Error::last_os_error();
        if verifier_log.is_empty() {
            bail!("BPF_PROG_LOAD: {}", os_err);
        }
        bail!("BPF_PROG_LOAD: {}\nverifier log:\n{}", os_err, verifier_log);
    }

    let fd = ret as RawFd;
    unsafe {
        libc::close(fd);
    }
    Ok(verifier_log)
}

fn main() {
    if let Err(err) = run() {
        eprintln!("{:#}", err);
        std::process::exit(1);
    }
}

fn run() -> Result<()> {
    let (prog_id, roundtrip_bin, expected_attach_type_override) = parse_args()?;

    let prog_fd = bpf::bpf_prog_get_fd_by_id(prog_id)
        .with_context(|| format!("open prog fd for id {}", prog_id))?;
    let (info, orig_insns) = bpf::bpf_prog_get_info(prog_fd.as_raw_fd(), true)
        .with_context(|| format!("read prog info for id {}", prog_id))?;
    let map_ids = bpf::bpf_prog_get_map_ids(prog_fd.as_raw_fd())
        .with_context(|| format!("read map IDs for prog {}", prog_id))?;
    let raw_roundtrip_insns = parse_bpf_insn_bytes(
        &fs::read(&roundtrip_bin)
            .with_context(|| format!("read roundtrip bytecode {}", roundtrip_bin.display()))?,
    )?;
    let map_fd_bindings = build_map_fd_bindings(&orig_insns, &map_ids);
    let (mut verify_insns, mut map_repair) =
        rebuild_helper_map_relocations(&orig_insns, &raw_roundtrip_insns)
            .context("rebuild helper map relocations from original bytecode")?;
    map_repair.explicit_fd_bindings = map_fd_bindings.len();

    let relocation =
        bpf::relocate_map_fds_with_bindings(&mut verify_insns, &map_ids, &map_fd_bindings);
    let _map_fds_guard = match relocation {
        Ok(map_fds) => map_fds,
        Err(err) => {
            let output = VerifyOutput {
                program_name: info.name_str().to_string(),
                program_id: info.id,
                program_type: info.prog_type,
                expected_attach_type: expected_attach_type_override.unwrap_or(0),
                map_id_count: map_ids.len(),
                original_insn_count: (info.orig_prog_len as usize) / 8,
                roundtrip_insn_count: verify_insns.len(),
                status: "error".to_string(),
                error: Some(format!("{:#}", err)),
                verifier_log: String::new(),
                map_repair,
            };
            print_json(&output);
            return Ok(());
        }
    };

    let expected_attach_type = expected_attach_type_override.unwrap_or(0);

    match run_prog_load_verify_without_debug_info(&info, expected_attach_type, &verify_insns, &[]) {
        Ok(verifier_log) => {
            let output = VerifyOutput {
                program_name: info.name_str().to_string(),
                program_id: info.id,
                program_type: info.prog_type,
                expected_attach_type,
                map_id_count: map_ids.len(),
                original_insn_count: (info.orig_prog_len as usize) / 8,
                roundtrip_insn_count: verify_insns.len(),
                status: "ok".to_string(),
                error: None,
                verifier_log,
                map_repair,
            };
            print_json(&output);
        }
        Err(err) => {
            let output = VerifyOutput {
                program_name: info.name_str().to_string(),
                program_id: info.id,
                program_type: info.prog_type,
                expected_attach_type,
                map_id_count: map_ids.len(),
                original_insn_count: (info.orig_prog_len as usize) / 8,
                roundtrip_insn_count: verify_insns.len(),
                status: "error".to_string(),
                error: Some(format!("{:#}", err)),
                verifier_log: String::new(),
                map_repair,
            };
            print_json(&output);
        }
    }

    Ok(())
}
