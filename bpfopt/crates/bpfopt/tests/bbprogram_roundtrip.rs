// SPDX-License-Identifier: MIT

use std::fs;
use std::path::{Path, PathBuf};

use anyhow::{Context, Result};
use bpfopt::analysis::{lift_with_pass_context, lower};
use bpfopt::insn::BpfInsn;
use bpfopt::pass::{run_pass_once, PassContext};
use bpfopt::passes::NoopPass;

#[test]
fn testbin_programs_roundtrip_and_noop_byte_identical() -> Result<()> {
    let paths = canonicalize_outputs()?;
    assert_eq!(paths.len(), 542, "unexpected testbin program count");

    for path in &paths {
        let bytes = fs::read(path).with_context(|| format!("read {}", path.display()))?;
        let insns = decode_insns(&bytes).with_context(|| format!("decode {}", path.display()))?;
        let ctx = PassContext::default();
        let mut prog = lift_with_pass_context(&insns, &ctx)
            .with_context(|| format!("lift {}", path.display()))?;
        let lowered = lower(&prog).with_context(|| format!("lower {}", path.display()))?;
        if lowered != insns {
            panic!("{}", roundtrip_diff(path, &insns, &lowered));
        }

        let result = run_pass_once(&NoopPass, &mut prog, &ctx)
            .with_context(|| format!("noop {}", path.display()))?;
        assert_eq!(
            result.sites_applied,
            0,
            "noop unexpectedly applied sites for {}",
            path.display()
        );
        let noop_lowered =
            lower(&prog).with_context(|| format!("lower noop {}", path.display()))?;
        if noop_lowered != insns {
            panic!("{}", roundtrip_diff(path, &insns, &noop_lowered));
        }
    }

    println!(
        "{}/{} programs roundtripped and noop-preserved byte-identical",
        paths.len(),
        paths.len()
    );
    Ok(())
}

fn canonicalize_outputs() -> Result<Vec<PathBuf>> {
    let root = Path::new(env!("CARGO_MANIFEST_DIR")).join("../../testbin");
    let mut out = Vec::new();
    collect_canonicalize_outputs(&root, &mut out)?;
    out.sort();
    Ok(out)
}

fn collect_canonicalize_outputs(dir: &Path, out: &mut Vec<PathBuf>) -> Result<()> {
    for entry in fs::read_dir(dir).with_context(|| format!("read_dir {}", dir.display()))? {
        let entry = entry.with_context(|| format!("read_dir entry {}", dir.display()))?;
        let path = entry.path();
        if path.is_dir() {
            collect_canonicalize_outputs(&path, out)?;
        } else if path.file_name().and_then(|name| name.to_str()) == Some("canonicalize_output.bin")
        {
            out.push(path);
        }
    }
    Ok(())
}

fn decode_insns(bytes: &[u8]) -> Result<Vec<BpfInsn>> {
    if !bytes.len().is_multiple_of(8) {
        anyhow::bail!("bytecode length {} is not a multiple of 8", bytes.len());
    }
    Ok(bytes
        .chunks_exact(8)
        .map(|chunk| BpfInsn::from_raw_bytes(chunk.try_into().expect("chunk is 8 bytes")))
        .collect())
}

fn roundtrip_diff(path: &Path, before: &[BpfInsn], after: &[BpfInsn]) -> String {
    let limit = before.len().min(after.len());
    for pc in 0..limit {
        if before[pc] != after[pc] {
            return format!(
                "{} first diverged at pc {}: before {:?}, after {:?}",
                path.display(),
                pc,
                before[pc],
                after[pc]
            );
        }
    }
    format!(
        "{} length diverged: before {} insns, after {} insns",
        path.display(),
        before.len(),
        after.len()
    )
}
