use std::collections::HashMap;
use std::ffi::OsString;
use std::fs;
use std::os::unix::io::AsRawFd;
use std::path::{Path, PathBuf};

use anyhow::{bail, Context, Result};
use serde::Serialize;

#[path = "../../../../../../daemon/src/bpf.rs"]
mod bpf;
#[path = "../../../../../../daemon/src/insn.rs"]
mod insn;

use insn::BpfInsn;

const BPF_PSEUDO_MAP_FD: u8 = 1;
const BPF_PSEUDO_MAP_VALUE: u8 = 2;

#[derive(Clone, Default, Serialize)]
struct MapRepairSummary {
    explicit_fd_bindings: usize,
    original_map_value_sites: usize,
    rewritten_map_value_calls: usize,
    original_helper_map_sites: usize,
    matched_helper_map_sites: usize,
    inserted_ldimm64_pairs: usize,
}

#[derive(Serialize)]
struct DumpOutput {
    program_name: String,
    program_id: u32,
    program_type: u32,
    map_ids: Vec<u32>,
    original_insn_count: usize,
    original_bin_path: String,
    metadata_path: String,
}

#[derive(Serialize)]
struct RejitOutput {
    program_name: String,
    program_id: u32,
    program_type: u32,
    status: String,
    error: Option<String>,
    verifier_log: String,
    map_ids: Vec<u32>,
    original_insn_count: usize,
    roundtrip_insn_count: usize,
    map_repair: MapRepairSummary,
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

enum Command {
    Dump { prog_id: u32, output_dir: PathBuf },
    Rejit { prog_id: u32, roundtrip_bin: PathBuf },
}

fn parse_args() -> Result<Command> {
    let mut args = std::env::args_os().skip(1);
    let command = args
        .next()
        .and_then(|value| value.into_string().ok())
        .context("missing subcommand (dump or rejit)")?;

    match command.as_str() {
        "dump" => {
            let mut prog_id: Option<u32> = None;
            let mut output_dir: Option<PathBuf> = None;
            while let Some(arg) = args.next() {
                match arg.to_string_lossy().as_ref() {
                    "--prog-id" => {
                        let value = next_string(&mut args, "--prog-id")?;
                        prog_id = Some(value.parse().context("invalid --prog-id")?);
                    }
                    "--output-dir" => {
                        output_dir = Some(PathBuf::from(next_os_string(
                            &mut args,
                            "--output-dir",
                        )?));
                    }
                    other => bail!("unknown dump argument: {}", other),
                }
            }
            Ok(Command::Dump {
                prog_id: prog_id.context("--prog-id is required")?,
                output_dir: output_dir.context("--output-dir is required")?,
            })
        }
        "rejit" => {
            let mut prog_id: Option<u32> = None;
            let mut roundtrip_bin: Option<PathBuf> = None;
            while let Some(arg) = args.next() {
                match arg.to_string_lossy().as_ref() {
                    "--prog-id" => {
                        let value = next_string(&mut args, "--prog-id")?;
                        prog_id = Some(value.parse().context("invalid --prog-id")?);
                    }
                    "--roundtrip-bin" => {
                        roundtrip_bin = Some(PathBuf::from(next_os_string(
                            &mut args,
                            "--roundtrip-bin",
                        )?));
                    }
                    other => bail!("unknown rejit argument: {}", other),
                }
            }
            Ok(Command::Rejit {
                prog_id: prog_id.context("--prog-id is required")?,
                roundtrip_bin: roundtrip_bin.context("--roundtrip-bin is required")?,
            })
        }
        other => bail!("unknown subcommand: {}", other),
    }
}

fn next_string(args: &mut impl Iterator<Item = OsString>, flag: &str) -> Result<String> {
    args.next()
        .and_then(|value| value.into_string().ok())
        .with_context(|| format!("missing value after {}", flag))
}

fn next_os_string(args: &mut impl Iterator<Item = OsString>, flag: &str) -> Result<OsString> {
    args.next()
        .with_context(|| format!("missing value after {}", flag))
}

fn write_insns_to_file(path: &Path, insns: &[BpfInsn]) -> Result<()> {
    let mut bytes = Vec::with_capacity(insns.len() * std::mem::size_of::<BpfInsn>());
    for insn in insns {
        bytes.push(insn.code);
        bytes.push(insn.regs);
        bytes.extend_from_slice(&insn.off.to_le_bytes());
        bytes.extend_from_slice(&insn.imm.to_le_bytes());
    }
    fs::write(path, bytes).with_context(|| format!("write {}", path.display()))
}

fn parse_bpf_insn_bytes(bytes: &[u8]) -> Result<Vec<BpfInsn>> {
    if bytes.len() % std::mem::size_of::<BpfInsn>() != 0 {
        bail!(
            "bytecode length {} is not a multiple of {}",
            bytes.len(),
            std::mem::size_of::<BpfInsn>()
        );
    }

    let mut insns = Vec::with_capacity(bytes.len() / std::mem::size_of::<BpfInsn>());
    for chunk in bytes.chunks_exact(8) {
        insns.push(BpfInsn {
            code: chunk[0],
            regs: chunk[1],
            off: i16::from_le_bytes([chunk[2], chunk[3]]),
            imm: i32::from_le_bytes([chunk[4], chunk[5], chunk[6], chunk[7]]),
        });
    }
    Ok(insns)
}

fn is_pseudo_map_ldimm64(insn: &BpfInsn) -> bool {
    insn.is_ldimm64() && matches!(insn.src_reg(), BPF_PSEUDO_MAP_FD | BPF_PSEUDO_MAP_VALUE)
}

fn contains_pseudo_map_ldimm64(insns: &[BpfInsn]) -> bool {
    insns.iter().any(is_pseudo_map_ldimm64)
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

fn collect_original_map_value_fds(orig_insns: &[BpfInsn]) -> Vec<i32> {
    let mut map_value_fds = Vec::new();
    let mut pc = 0usize;

    while pc < orig_insns.len() {
        let insn = orig_insns[pc];
        if insn.is_ldimm64() && insn.src_reg() == BPF_PSEUDO_MAP_VALUE {
            map_value_fds.push(insn.imm);
            pc += 2;
            continue;
        }
        pc += if insn.is_ldimm64() { 2 } else { 1 };
    }

    map_value_fds
}

fn collect_runtime_map_value_call_pcs(insns: &[BpfInsn]) -> Vec<usize> {
    insns
        .iter()
        .enumerate()
        .filter_map(|(pc, insn)| {
            if insn.is_call() && insn.src_reg() == insn::BPF_PSEUDO_CALL && insn.imm == -1 {
                Some(pc)
            } else {
                None
            }
        })
        .collect()
}

fn rewrite_runtime_map_value_calls(
    orig_insns: &[BpfInsn],
    roundtrip_insns: &[BpfInsn],
) -> Result<(Vec<BpfInsn>, usize, usize)> {
    let original_map_value_fds = collect_original_map_value_fds(orig_insns);
    let runtime_call_pcs = collect_runtime_map_value_call_pcs(roundtrip_insns);

    if runtime_call_pcs.len() > original_map_value_fds.len() {
        bail!(
            "found {} runtime map-value pseudo-calls but only {} original map-value loads",
            runtime_call_pcs.len(),
            original_map_value_fds.len()
        );
    }

    let mut rewritten = roundtrip_insns.to_vec();
    for (site_index, &call_pc) in runtime_call_pcs.iter().enumerate() {
        if call_pc == 0 {
            bail!("runtime map-value pseudo-call cannot appear at instruction 0");
        }

        let prev_pc = call_pc - 1;
        let old_fd = original_map_value_fds[site_index];
        rewritten[prev_pc] = BpfInsn {
            code: insn::BPF_LD | insn::BPF_DW | insn::BPF_IMM,
            regs: BpfInsn::make_regs(0, BPF_PSEUDO_MAP_VALUE),
            off: 0,
            imm: old_fd,
        };
        rewritten[call_pc] = BpfInsn {
            code: 0,
            regs: 0,
            off: 0,
            imm: 0,
        };
    }

    Ok((
        rewritten,
        original_map_value_fds.len(),
        runtime_call_pcs.len(),
    ))
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
    if contains_pseudo_map_ldimm64(roundtrip_insns) {
        return Ok((roundtrip_insns.to_vec(), MapRepairSummary::default()));
    }
    let (map_value_rewritten, original_map_value_sites, rewritten_map_value_calls) =
        rewrite_runtime_map_value_calls(orig_insns, roundtrip_insns)
            .context("rewrite runtime map-value helper calls back to ldimm64")?;
    let helper_map_sites = collect_helper_map_sites(orig_insns);
    let insertions = plan_helper_map_insertions(&map_value_rewritten, &helper_map_sites);
    let repaired = apply_insertions_with_pc_fixups(&map_value_rewritten, &insertions)?;
    Ok((
        repaired,
        MapRepairSummary {
            explicit_fd_bindings: 0,
            original_map_value_sites,
            rewritten_map_value_calls,
            original_helper_map_sites: helper_map_sites.len(),
            matched_helper_map_sites: insertions.len(),
            inserted_ldimm64_pairs: insertions.len(),
        },
    ))
}

fn print_json<T: Serialize>(payload: &T) {
    println!(
        "{}",
        serde_json::to_string_pretty(payload).expect("json serialization never fails")
    );
}

fn run_dump(prog_id: u32, output_dir: &Path) -> Result<()> {
    fs::create_dir_all(output_dir)
        .with_context(|| format!("create {}", output_dir.display()))?;

    let prog_fd = bpf::bpf_prog_get_fd_by_id(prog_id)
        .with_context(|| format!("open prog fd for id {}", prog_id))?;
    let (info, orig_insns) = bpf::bpf_prog_get_info(prog_fd.as_raw_fd(), true)
        .with_context(|| format!("read prog info for id {}", prog_id))?;
    let map_ids = bpf::bpf_prog_get_map_ids(prog_fd.as_raw_fd())
        .with_context(|| format!("read map IDs for prog {}", prog_id))?;

    let original_bin_path = output_dir.join("original.bin");
    write_insns_to_file(&original_bin_path, &orig_insns)?;

    let payload = DumpOutput {
        program_name: info.name_str().to_string(),
        program_id: info.id,
        program_type: info.prog_type,
        map_ids,
        original_insn_count: orig_insns.len(),
        original_bin_path: original_bin_path.display().to_string(),
        metadata_path: output_dir.join("metadata.json").display().to_string(),
    };

    fs::write(
        output_dir.join("metadata.json"),
        serde_json::to_vec_pretty(&payload)?,
    )
    .with_context(|| format!("write {}", output_dir.join("metadata.json").display()))?;

    print_json(&payload);
    Ok(())
}

fn run_rejit(prog_id: u32, roundtrip_bin: &Path) -> Result<()> {
    let prog_fd = bpf::bpf_prog_get_fd_by_id(prog_id)
        .with_context(|| format!("open prog fd for id {}", prog_id))?;
    let (info, orig_insns) = bpf::bpf_prog_get_info(prog_fd.as_raw_fd(), true)
        .with_context(|| format!("read prog info for id {}", prog_id))?;
    let map_ids = bpf::bpf_prog_get_map_ids(prog_fd.as_raw_fd())
        .with_context(|| format!("read map IDs for prog {}", prog_id))?;
    let raw_roundtrip_insns = parse_bpf_insn_bytes(
        &fs::read(roundtrip_bin)
            .with_context(|| format!("read {}", roundtrip_bin.display()))?,
    )?;
    let map_fd_bindings = build_map_fd_bindings(&orig_insns, &map_ids);
    let (mut rejit_insns, mut map_repair) =
        rebuild_helper_map_relocations(&orig_insns, &raw_roundtrip_insns)
            .context("rebuild helper map relocations from original bytecode")?;
    map_repair.explicit_fd_bindings = map_fd_bindings.len();

    let relocation =
        bpf::relocate_map_fds_with_bindings(&mut rejit_insns, &map_ids, &map_fd_bindings);
    let _map_fds_guard = match relocation {
        Ok(map_fds) => map_fds,
        Err(err) => {
            print_json(&RejitOutput {
                program_name: info.name_str().to_string(),
                program_id: info.id,
                program_type: info.prog_type,
                status: "error".to_string(),
                error: Some(format!("{:#}", err)),
                verifier_log: String::new(),
                map_ids,
                original_insn_count: orig_insns.len(),
                roundtrip_insn_count: rejit_insns.len(),
                map_repair,
            });
            return Ok(());
        }
    };

    match bpf::bpf_prog_rejit_capture_verifier_log(prog_fd.as_raw_fd(), &rejit_insns, &[]) {
        Ok(result) => print_json(&RejitOutput {
            program_name: info.name_str().to_string(),
            program_id: info.id,
            program_type: info.prog_type,
            status: "ok".to_string(),
            error: None,
            verifier_log: result.verifier_log,
            map_ids,
            original_insn_count: orig_insns.len(),
            roundtrip_insn_count: rejit_insns.len(),
            map_repair,
        }),
        Err(err) => print_json(&RejitOutput {
            program_name: info.name_str().to_string(),
            program_id: info.id,
            program_type: info.prog_type,
            status: "error".to_string(),
            error: Some(format!("{:#}", err)),
            verifier_log: String::new(),
            map_ids,
            original_insn_count: orig_insns.len(),
            roundtrip_insn_count: rejit_insns.len(),
            map_repair,
        }),
    }

    Ok(())
}

fn main() {
    if let Err(err) = run() {
        eprintln!("{:#}", err);
        std::process::exit(1);
    }
}

fn run() -> Result<()> {
    match parse_args()? {
        Command::Dump { prog_id, output_dir } => run_dump(prog_id, &output_dir),
        Command::Rejit {
            prog_id,
            roundtrip_bin,
        } => run_rejit(prog_id, &roundtrip_bin),
    }
}
