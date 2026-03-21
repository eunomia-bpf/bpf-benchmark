// SPDX-License-Identifier: MIT
//! bpfrejit-daemon — BpfReJIT userspace daemon (Rust POC).
//!
//! Scans live kernel BPF programs for optimization sites and can apply
//! bytecode rewrites via BPF_PROG_REJIT.

mod bpf;
mod emit;
mod insn;
mod matcher;
mod rewriter;

use std::os::unix::io::AsRawFd;

use anyhow::{Context, Result};
use clap::{Parser, Subcommand};

#[derive(Parser)]
#[command(name = "bpfrejit-daemon", version, about = "BpfReJIT userspace daemon")]
struct Cli {
    #[command(subcommand)]
    command: Command,
}

#[derive(Subcommand)]
enum Command {
    /// List all live BPF programs and scan for optimization sites.
    Enumerate,

    /// Fetch bytecode for a program, rewrite it, and print the result (dry-run).
    Rewrite {
        /// BPF program ID.
        #[arg(value_name = "PROG_ID")]
        prog_id: u32,
    },

    /// Fetch bytecode, rewrite, and apply via BPF_PROG_REJIT.
    Apply {
        /// BPF program ID.
        #[arg(value_name = "PROG_ID")]
        prog_id: u32,
    },

    /// Apply rewrites to all live BPF programs that have optimization sites.
    ApplyAll,
}

fn main() -> Result<()> {
    let cli = Cli::parse();
    match cli.command {
        Command::Enumerate => cmd_enumerate(),
        Command::Rewrite { prog_id } => cmd_rewrite(prog_id),
        Command::Apply { prog_id } => cmd_apply(prog_id),
        Command::ApplyAll => cmd_apply_all(),
    }
}

// ── Subcommand implementations ──────────────────────────────────────

fn cmd_enumerate() -> Result<()> {
    println!("{:>6}  {:>6}  {:>5}  {:<16}  sites", "ID", "type", "insns", "name");
    println!("{}", "-".repeat(60));

    for prog_id in bpf::iter_prog_ids() {
        match enumerate_one(prog_id) {
            Ok(()) => {}
            Err(e) => {
                eprintln!("  prog {}: {:#}", prog_id, e);
            }
        }
    }
    Ok(())
}

fn enumerate_one(prog_id: u32) -> Result<()> {
    let fd = bpf::bpf_prog_get_fd_by_id(prog_id)?;
    let (info, orig_insns) = bpf::bpf_prog_get_info(fd.as_raw_fd(), true)?;

    let name = info.name_str();
    let insn_count = if !orig_insns.is_empty() {
        orig_insns.len()
    } else {
        info.orig_prog_len as usize / 8 // orig_prog_len is in bytes
    };

    let sites = if !orig_insns.is_empty() {
        matcher::scan_all(&orig_insns)
    } else {
        Vec::new()
    };

    let site_summary = if sites.is_empty() {
        "-".to_string()
    } else {
        let wide_count = sites.iter().filter(|s| s.family == matcher::Family::WideMem).count();
        format!("wide_mem={}", wide_count)
    };

    println!(
        "{:>6}  {:>6}  {:>5}  {:<16}  {}",
        prog_id,
        info.prog_type,
        insn_count,
        name,
        site_summary,
    );

    Ok(())
}

fn cmd_rewrite(prog_id: u32) -> Result<()> {
    let (info, orig_insns) = bpf::get_orig_insns_by_id(prog_id)?;

    if orig_insns.is_empty() {
        println!("prog {}: no original instructions available (orig_prog_len={})",
                 prog_id, info.orig_prog_len);
        return Ok(());
    }

    println!("prog {} ({:?}): {} original instructions",
             prog_id, info.name_str(), orig_insns.len());

    let sites = matcher::scan_all(&orig_insns);
    println!("  found {} rewrite sites", sites.len());
    for site in &sites {
        println!("    pc={} len={} family={} bindings={:?}",
                 site.start_pc, site.old_len, site.family, site.bindings);
    }

    if sites.is_empty() {
        println!("  nothing to rewrite");
        return Ok(());
    }

    let result = rewriter::rewrite(&orig_insns, &sites)
        .context("rewrite failed")?;

    println!("  rewrite: {} insns -> {} insns ({} sites applied)",
             orig_insns.len(), result.new_insns.len(), result.sites_applied);

    // Print new instructions for inspection.
    for (i, insn) in result.new_insns.iter().enumerate() {
        println!("    [{:>4}] {}", i, insn);
    }

    Ok(())
}

fn cmd_apply(prog_id: u32) -> Result<()> {
    let fd = bpf::bpf_prog_get_fd_by_id(prog_id)
        .context("open program")?;
    let (info, orig_insns) = bpf::bpf_prog_get_info(fd.as_raw_fd(), true)
        .context("get program info")?;

    if orig_insns.is_empty() {
        println!("prog {}: no original instructions available", prog_id);
        return Ok(());
    }

    let sites = matcher::scan_all(&orig_insns);
    if sites.is_empty() {
        println!("prog {} ({}): no optimization sites found", prog_id, info.name_str());
        return Ok(());
    }

    let result = rewriter::rewrite(&orig_insns, &sites)?;
    if !result.has_transforms {
        println!("prog {} ({}): no transforms applied", prog_id, info.name_str());
        return Ok(());
    }

    println!(
        "prog {} ({}): applying {} sites ({} -> {} insns)",
        prog_id,
        info.name_str(),
        result.sites_applied,
        orig_insns.len(),
        result.new_insns.len(),
    );

    bpf::bpf_prog_rejit(fd.as_raw_fd(), &result.new_insns, &[])
        .context("BPF_PROG_REJIT failed")?;

    println!("  REJIT successful");
    Ok(())
}

fn cmd_apply_all() -> Result<()> {
    let mut total = 0u32;
    let mut applied = 0u32;
    let mut errors = 0u32;

    for prog_id in bpf::iter_prog_ids() {
        total += 1;
        match try_apply_one(prog_id) {
            Ok(true) => applied += 1,
            Ok(false) => {}
            Err(e) => {
                eprintln!("  prog {}: {:#}", prog_id, e);
                errors += 1;
            }
        }
    }

    println!(
        "\napply-all: scanned {} programs, applied {}, errors {}",
        total, applied, errors
    );
    Ok(())
}

/// Try to apply rewrites to a single program. Returns true if REJIT was called.
fn try_apply_one(prog_id: u32) -> Result<bool> {
    let fd = bpf::bpf_prog_get_fd_by_id(prog_id)?;
    let (info, orig_insns) = bpf::bpf_prog_get_info(fd.as_raw_fd(), true)?;

    if orig_insns.is_empty() {
        return Ok(false);
    }

    let sites = matcher::scan_all(&orig_insns);
    if sites.is_empty() {
        return Ok(false);
    }

    let result = rewriter::rewrite(&orig_insns, &sites)?;
    if !result.has_transforms {
        return Ok(false);
    }

    println!(
        "  prog {} ({}): {} sites, {} -> {} insns",
        prog_id,
        info.name_str(),
        result.sites_applied,
        orig_insns.len(),
        result.new_insns.len(),
    );

    bpf::bpf_prog_rejit(fd.as_raw_fd(), &result.new_insns, &[])?;
    println!("    REJIT ok");
    Ok(true)
}
