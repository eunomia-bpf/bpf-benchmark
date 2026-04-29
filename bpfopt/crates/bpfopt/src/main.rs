// SPDX-License-Identifier: MIT
//! bpfopt — BPF bytecode optimizer CLI.
//!
//! Each optimization pass is a subcommand. Reads bytecode from stdin,
//! writes optimized bytecode to stdout. Side-inputs via flags.

use std::collections::HashMap;
use std::io::{self, Read, Write};
use std::path::PathBuf;

use anyhow::{Context, Result};
use clap::{Parser, Subcommand};
use serde::Deserialize;

use bpfopt_core::insn::BpfInsn;
use bpfopt_core::pass::{BpfProgram, MapMetadata, PassContext, PassManager};
use bpfopt_core::passes::{self, PASS_REGISTRY};

#[derive(Parser)]
#[command(name = "bpfopt", version, about = "BPF bytecode optimizer")]
struct Cli {
    #[command(subcommand)]
    command: Command,
}

#[derive(Subcommand)]
enum Command {
    /// Run one or more optimization passes.
    Optimize {
        /// Comma-separated list of pass names (default: all).
        #[arg(long)]
        passes: Option<String>,

        #[command(flatten)]
        io: IoArgs,
    },
    /// Run the wide-mem pass.
    WideMem {
        #[command(flatten)]
        io: IoArgs,
    },
    /// Run the rotate pass.
    Rotate {
        #[command(flatten)]
        io: IoArgs,
    },
    /// Run the const-prop pass.
    ConstProp {
        #[command(flatten)]
        io: IoArgs,
    },
    /// Run the cond-select pass.
    CondSelect {
        #[command(flatten)]
        io: IoArgs,
    },
    /// Run the extract pass.
    Extract {
        #[command(flatten)]
        io: IoArgs,
    },
    /// Run the endian-fusion pass.
    Endian {
        #[command(flatten)]
        io: IoArgs,
    },
    /// Run the branch-flip pass (needs --profile).
    BranchFlip {
        #[command(flatten)]
        io: IoArgs,
    },
    /// Run the DCE pass.
    Dce {
        #[command(flatten)]
        io: IoArgs,
    },
    /// Run the map-inline pass (needs --map-values).
    MapInline {
        #[command(flatten)]
        io: IoArgs,
    },
    /// Run the bulk-memory pass.
    BulkMemory {
        #[command(flatten)]
        io: IoArgs,
    },
    /// Run the bounds-check-merge pass.
    BoundsCheckMerge {
        #[command(flatten)]
        io: IoArgs,
    },
    /// Run the skb-load-bytes pass.
    SkbLoadBytes {
        #[command(flatten)]
        io: IoArgs,
    },
    /// Analyze a BPF program (report optimization opportunities).
    Analyze {
        #[command(flatten)]
        io: IoArgs,
    },
    /// List available passes.
    ListPasses {
        /// Output as JSON.
        #[arg(long)]
        json: bool,
    },
}

#[derive(clap::Args)]
struct IoArgs {
    /// Input file (default: stdin).
    #[arg(long)]
    input: Option<PathBuf>,

    /// Output file (default: stdout).
    #[arg(long)]
    output: Option<PathBuf>,

    /// Write pass report JSON to file.
    #[arg(long)]
    report: Option<PathBuf>,

    /// Target description JSON (arch, features, kinsn availability).
    #[arg(long)]
    target: Option<PathBuf>,

    /// PGO profile JSON (branch taken/not-taken counts).
    #[arg(long)]
    profile: Option<PathBuf>,

    /// Map values snapshot JSON (for map-inline pass).
    #[arg(long)]
    map_values: Option<PathBuf>,

    /// Map IDs (comma-separated, for map-related passes).
    #[arg(long)]
    map_ids: Option<String>,
}

// ── Side-input JSON schemas ─────────────────────────────────────────

#[derive(Deserialize)]
struct TargetJson {
    #[serde(default)]
    arch: Option<String>,
    #[serde(default)]
    features: Vec<String>,
    #[serde(default)]
    kinsns: HashMap<String, KinsnDesc>,
}

#[derive(Deserialize)]
struct KinsnDesc {
    btf_func_id: i32,
    #[serde(default)]
    call_off: Option<i16>,
    #[serde(default)]
    supported_encodings: Option<u32>,
}

#[derive(Deserialize)]
struct ProfileJson {
    #[serde(default)]
    branch_miss_rate: Option<f64>,
    #[serde(default)]
    per_insn: HashMap<String, BranchCounts>,
}

#[derive(Deserialize)]
struct BranchCounts {
    taken: u64,
    not_taken: u64,
}

#[derive(Deserialize)]
struct MapValuesJson {
    maps: Vec<MapValuesEntry>,
}

#[derive(Deserialize)]
struct MapValuesEntry {
    map_id: u32,
    map_type: u32,
    key_size: u32,
    value_size: u32,
    max_entries: u32,
    #[serde(default)]
    frozen: bool,
    #[serde(default)]
    entries: Vec<MapEntry>,
}

#[derive(Deserialize)]
struct MapEntry {
    key: String,
    value: Option<String>,
}

fn read_bytecode(io_args: &IoArgs) -> Result<Vec<BpfInsn>> {
    let raw = match &io_args.input {
        Some(path) => {
            std::fs::read(path).with_context(|| format!("failed to read {}", path.display()))?
        }
        None => {
            let mut buf = Vec::new();
            io::stdin()
                .read_to_end(&mut buf)
                .context("failed to read stdin")?;
            buf
        }
    };

    if raw.len() % 8 != 0 {
        anyhow::bail!(
            "input size {} is not a multiple of 8 (struct bpf_insn)",
            raw.len()
        );
    }

    let insns: Vec<BpfInsn> = raw
        .chunks_exact(8)
        .map(|chunk| BpfInsn {
            code: chunk[0],
            regs: chunk[1],
            off: i16::from_le_bytes([chunk[2], chunk[3]]),
            imm: i32::from_le_bytes([chunk[4], chunk[5], chunk[6], chunk[7]]),
        })
        .collect();

    Ok(insns)
}

fn write_bytecode(io_args: &IoArgs, insns: &[BpfInsn]) -> Result<()> {
    let mut raw = Vec::with_capacity(insns.len() * 8);
    for insn in insns {
        raw.push(insn.code);
        raw.push(insn.regs);
        raw.extend_from_slice(&insn.off.to_le_bytes());
        raw.extend_from_slice(&insn.imm.to_le_bytes());
    }

    match &io_args.output {
        Some(path) => std::fs::write(path, &raw)
            .with_context(|| format!("failed to write {}", path.display()))?,
        None => io::stdout()
            .write_all(&raw)
            .context("failed to write stdout")?,
    }

    Ok(())
}

fn decode_hex(s: &str) -> Result<Vec<u8>> {
    let s = s.trim();
    if s.len() % 2 != 0 {
        anyhow::bail!("hex string must have even length");
    }
    (0..s.len())
        .step_by(2)
        .map(|i| {
            u8::from_str_radix(&s[i..i + 2], 16).map_err(|e| anyhow::anyhow!("bad hex: {}", e))
        })
        .collect()
}

fn apply_target(ctx: &mut PassContext, io_args: &IoArgs) -> Result<()> {
    let Some(path) = &io_args.target else {
        return Ok(());
    };
    let data = std::fs::read_to_string(path)
        .with_context(|| format!("failed to read target {}", path.display()))?;
    let target: TargetJson = serde_json::from_str(&data)
        .with_context(|| format!("failed to parse target {}", path.display()))?;

    if let Some(arch) = target.arch.as_deref() {
        match arch {
            "x86_64" | "x86-64" => ctx.platform.arch = bpfopt_core::pass::Arch::X86_64,
            "aarch64" | "arm64" => ctx.platform.arch = bpfopt_core::pass::Arch::Aarch64,
            _ => {}
        }
    }

    // CPU features
    for feat in &target.features {
        match feat.as_str() {
            "cmov" => ctx.platform.has_cmov = true,
            "movbe" => ctx.platform.has_movbe = true,
            "bmi1" => ctx.platform.has_bmi1 = true,
            "bmi2" => ctx.platform.has_bmi2 = true,
            "rorx" => ctx.platform.has_rorx = true,
            _ => {}
        }
    }

    // kinsn BTF IDs
    for (name, desc) in &target.kinsns {
        if let Some(call_off) = desc.call_off {
            ctx.kinsn_registry
                .target_call_offsets
                .insert(name.clone(), call_off);
        }
        if let Some(supported_encodings) = desc.supported_encodings {
            ctx.kinsn_registry
                .target_supported_encodings
                .insert(name.clone(), supported_encodings);
        }
        match name.as_str() {
            "bpf_rotate64" => ctx.kinsn_registry.rotate64_btf_id = desc.btf_func_id,
            "bpf_select64" => ctx.kinsn_registry.select64_btf_id = desc.btf_func_id,
            "bpf_extract64" => ctx.kinsn_registry.extract64_btf_id = desc.btf_func_id,
            "bpf_memcpy_bulk" | "bpf_bulk_memcpy" => {
                ctx.kinsn_registry.memcpy_bulk_btf_id = desc.btf_func_id
            }
            "bpf_memset_bulk" | "bpf_bulk_memset" => {
                ctx.kinsn_registry.memset_bulk_btf_id = desc.btf_func_id
            }
            "bpf_endian_load16" => ctx.kinsn_registry.endian_load16_btf_id = desc.btf_func_id,
            "bpf_endian_load32" => ctx.kinsn_registry.endian_load32_btf_id = desc.btf_func_id,
            "bpf_endian_load64" => ctx.kinsn_registry.endian_load64_btf_id = desc.btf_func_id,
            _ => {}
        }
    }

    Ok(())
}

fn apply_profile(program: &mut BpfProgram, io_args: &IoArgs) -> Result<()> {
    let Some(path) = &io_args.profile else {
        return Ok(());
    };
    let data = std::fs::read_to_string(path)
        .with_context(|| format!("failed to read profile {}", path.display()))?;
    let profile: ProfileJson = serde_json::from_str(&data)
        .with_context(|| format!("failed to parse profile {}", path.display()))?;

    program.branch_miss_rate = profile.branch_miss_rate;
    for (pc_str, counts) in &profile.per_insn {
        let pc: usize = pc_str
            .parse()
            .with_context(|| format!("invalid PC in profile: {}", pc_str))?;
        if pc < program.annotations.len() {
            program.annotations[pc].branch_profile = Some(bpfopt_core::pass::BranchProfile {
                taken_count: counts.taken,
                not_taken_count: counts.not_taken,
            });
        }
    }
    Ok(())
}

fn apply_map_values(program: &mut BpfProgram, io_args: &IoArgs) -> Result<()> {
    let Some(path) = &io_args.map_values else {
        return Ok(());
    };
    let data = std::fs::read_to_string(path)
        .with_context(|| format!("failed to read map-values {}", path.display()))?;
    let mv: MapValuesJson = serde_json::from_str(&data)
        .with_context(|| format!("failed to parse map-values {}", path.display()))?;

    for map in &mv.maps {
        program.map_metadata.insert(
            map.map_id,
            MapMetadata {
                map_type: map.map_type,
                key_size: map.key_size,
                value_size: map.value_size,
                max_entries: map.max_entries,
                frozen: map.frozen,
                map_id: map.map_id,
            },
        );
        for entry in &map.entries {
            let key = decode_hex(&entry.key)?;
            if let Some(ref val_hex) = entry.value {
                let value = decode_hex(val_hex)?;
                program.map_values.insert((map.map_id, key), value);
            }
        }
    }
    Ok(())
}

fn apply_map_ids(program: &mut BpfProgram, io_args: &IoArgs) -> Result<()> {
    let Some(ref ids_str) = io_args.map_ids else {
        return Ok(());
    };
    let map_ids: Vec<u32> = ids_str
        .split(',')
        .map(|s| s.trim().parse::<u32>().context("invalid map id"))
        .collect::<Result<_>>()?;
    program.set_map_ids(map_ids);
    Ok(())
}

fn apply_side_inputs(
    program: &mut BpfProgram,
    ctx: &mut PassContext,
    io_args: &IoArgs,
) -> Result<()> {
    apply_target(ctx, io_args)?;
    apply_map_ids(program, io_args)?;
    apply_map_values(program, io_args)?;
    apply_profile(program, io_args)?;
    Ok(())
}

fn run_single_pass(pass_name: &str, io_args: &IoArgs) -> Result<()> {
    let insns = read_bytecode(io_args)?;
    let mut program = BpfProgram::new(insns);
    let mut ctx = PassContext::default();
    apply_side_inputs(&mut program, &mut ctx, io_args)?;

    let entry = PASS_REGISTRY
        .iter()
        .find(|e| e.name == pass_name)
        .unwrap_or_else(|| panic!("unknown pass: {}", pass_name));

    let mut pm = PassManager::new();
    use bpfopt_core::analysis::{
        BranchTargetAnalysis, CFGAnalysis, LivenessAnalysis, MapInfoAnalysis,
    };
    pm.register_analysis(BranchTargetAnalysis);
    pm.register_analysis(CFGAnalysis);
    pm.register_analysis(LivenessAnalysis);
    pm.register_analysis(MapInfoAnalysis);
    pm.add_pass_boxed((entry.make)());

    let mut local_ctx = ctx;
    local_ctx.policy.enabled_passes = vec![pass_name.to_string()];
    let result = pm.run(&mut program, &local_ctx)?;

    if let Some(report_path) = &io_args.report {
        let report = serde_json::json!({
            "pass": pass_name,
            "changed": result.program_changed,
            "total_sites_applied": result.total_sites_applied,
            "insns_before": result.pass_results.first().map(|r| r.insns_before).unwrap_or(0),
            "insn_count_after": program.insns.len(),
        });
        std::fs::write(report_path, serde_json::to_string_pretty(&report)?)
            .with_context(|| format!("failed to write report {}", report_path.display()))?;
    }

    write_bytecode(io_args, &program.insns)?;
    Ok(())
}

fn run_optimize(pass_names: Option<&str>, io_args: &IoArgs) -> Result<()> {
    let insns = read_bytecode(io_args)?;
    let mut program = BpfProgram::new(insns);
    let mut ctx = PassContext::default();
    apply_side_inputs(&mut program, &mut ctx, io_args)?;

    let pm = match pass_names {
        Some(names) => {
            let names: Vec<String> = names.split(',').map(|s| s.trim().to_string()).collect();
            passes::validate_pass_names(&names)?;
            let mut pm = PassManager::new();
            use bpfopt_core::analysis::{
                BranchTargetAnalysis, CFGAnalysis, LivenessAnalysis, MapInfoAnalysis,
            };
            pm.register_analysis(BranchTargetAnalysis);
            pm.register_analysis(CFGAnalysis);
            pm.register_analysis(LivenessAnalysis);
            pm.register_analysis(MapInfoAnalysis);
            for entry in PASS_REGISTRY {
                if names.iter().any(|n| n == entry.name) {
                    pm.add_pass_boxed((entry.make)());
                }
            }
            pm
        }
        None => passes::build_full_pipeline(),
    };
    let result = pm.run(&mut program, &ctx)?;

    if let Some(report_path) = &io_args.report {
        let report = serde_json::json!({
            "changed": result.program_changed,
            "total_sites_applied": result.total_sites_applied,
            "passes": result.pass_results.iter().map(|pr| {
                serde_json::json!({
                    "pass": pr.pass_name,
                    "changed": pr.changed,
                    "sites_applied": pr.sites_applied,
                    "insns_before": pr.insns_before,
                })
            }).collect::<Vec<_>>(),
        });
        std::fs::write(report_path, serde_json::to_string_pretty(&report)?)
            .with_context(|| format!("failed to write report {}", report_path.display()))?;
    }

    write_bytecode(io_args, &program.insns)?;
    Ok(())
}

fn main() -> Result<()> {
    let cli = Cli::parse();

    match cli.command {
        Command::ListPasses { json } => {
            if json {
                let passes: Vec<_> = PASS_REGISTRY
                    .iter()
                    .map(|e| serde_json::json!({"name": e.name, "description": e.description}))
                    .collect();
                println!("{}", serde_json::to_string_pretty(&passes)?);
            } else {
                for entry in PASS_REGISTRY {
                    println!("  {:<24} {}", entry.name, entry.description);
                }
            }
        }
        Command::Optimize { passes, io } => run_optimize(passes.as_deref(), &io)?,
        Command::WideMem { io } => run_single_pass("wide_mem", &io)?,
        Command::Rotate { io } => run_single_pass("rotate", &io)?,
        Command::ConstProp { io } => run_single_pass("const_prop", &io)?,
        Command::CondSelect { io } => run_single_pass("cond_select", &io)?,
        Command::Extract { io } => run_single_pass("extract", &io)?,
        Command::Endian { io } => run_single_pass("endian_fusion", &io)?,
        Command::BranchFlip { io } => run_single_pass("branch_flip", &io)?,
        Command::Dce { io } => run_single_pass("dce", &io)?,
        Command::MapInline { io } => run_single_pass("map_inline", &io)?,
        Command::BulkMemory { io } => run_single_pass("bulk_memory", &io)?,
        Command::BoundsCheckMerge { io } => run_single_pass("bounds_check_merge", &io)?,
        Command::SkbLoadBytes { io } => run_single_pass("skb_load_bytes_spec", &io)?,
        Command::Analyze { io } => {
            let insns = read_bytecode(&io)?;
            let program = BpfProgram::new(insns);
            let report = serde_json::json!({
                "insn_count": program.insns.len(),
                "has_exit": program.insns.iter().any(|i| i.is_exit()),
            });
            println!("{}", serde_json::to_string_pretty(&report)?);
        }
    }

    Ok(())
}
