// SPDX-License-Identifier: MIT
//! bpfopt CLI entry point.

use anyhow::Result;
use clap::{Parser, Subcommand};

#[derive(Parser)]
#[command(name = "bpfopt", version, about = "BPF bytecode optimizer")]
struct Cli {
    #[command(subcommand)]
    command: Command,
}

#[derive(Subcommand)]
enum Command {
    /// List available optimization passes.
    ListPasses,
    // TODO(Phase 1.3): add optimize and per-pass bytecode subcommands.
}

fn main() -> Result<()> {
    let cli = Cli::parse();

    match cli.command {
        Command::ListPasses => {
            for entry in bpfopt::passes::PASS_REGISTRY {
                println!("{}", entry.name);
            }
        }
    }

    Ok(())
}
