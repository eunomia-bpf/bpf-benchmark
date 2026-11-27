//! Consume the same frozen scalar facts before code generation, while the
//! selected P still carries its frontend IR. Machine-only proofs keep the
//! existing instruction-level folding; no application names select this pass.
use super::*;
use std::process::{Command, Stdio};

pub(super) fn specialize(
    args: &Args,
    elf: &object::File,
    values: &HashMap<String, Vec<u8>>,
    compiler: &std::path::Path,
    linker: &std::path::Path,
) -> Result<Option<Vec<u8>>> {
    if args.mode != LinkMode::Kernel || elf.architecture() != object::Architecture::X86_64
        || values.is_empty()
    {
        return Ok(None);
    }
    let Some(section) = elf.section_by_name(".llvmbc") else {
        return Ok(None);
    };
    let prefix = args.output.with_extension(format!("frozen-lto.{}", std::process::id()));
    fs::create_dir(&prefix).with_context(|| format!("create {}", prefix.display()))?;
    let ir = prefix.join("input.bc");
    fs::write(&ir, section.data().context("read embedded frontend IR")?)?;
    let facts = prefix.join("immutable.json");
    let hex: HashMap<_, _> = values.iter().map(|(name, bytes)| {
        (name, bytes.iter().map(|b| format!("{b:02x}")).collect::<String>())
    }).collect();
    fs::write(&facts, serde_json::to_vec(&hex)?)?;
    let native = prefix.join("native.o");
    // All concurrent native-link processes share one compiler slot. Other
    // project compilation can use the second slot. This runs during native
    // loading, before measurement, with the required 48 GiB address-space cap.
    let output = Command::new("flock")
        .args(["--exclusive", "/tmp/kprog-native-frozen-ir.compile"])
        .args(["prlimit", "--as=51539607552", "--"])
        .arg(compiler).arg("--x86-cmov-converter-force-all").arg(&ir)
        .arg("--symbol").arg(&args.symbol)
        .args(["--kernel-btf", "/sys/kernel/btf/vmlinux", "--prog-type", "0"])
        .arg("--immutable-globals").arg(&facts).arg("-o").arg(&native)
        .stdin(Stdio::null()).output().context("run frozen-scalar LTO")?;
    fs::write(prefix.join("compiler.stderr"), &output.stderr)?;
    if !output.status.success() {
        bail!("frozen-scalar LTO failed ({}): {} (inputs retained in {})",
            output.status, String::from_utf8_lossy(&output.stderr), prefix.display());
    }
    // Reapply the normal entry ABI rewrite to the re-emitted object. The
    // resulting proof and kernel stream therefore use the same saved-register
    // contract, rather than reusing the pre-optimization mask.
    let proof = prefix.join("native.proof.o");
    let mut command = Command::new(linker);
    command.arg("--input").arg(&native).arg("--symbol").arg(&args.symbol)
        .arg("--mode").arg("proof").arg("--output").arg(&proof);
    if args.preserve_entry_abi { command.arg("--preserve-entry-abi"); }
    let output = command.stdin(Stdio::null()).output().context("extract frozen-scalar proof")?;
    fs::write(prefix.join("proof.stderr"), &output.stderr)?;
    if !output.status.success() {
        bail!("frozen-scalar proof extraction failed ({}): {}", output.status,
            String::from_utf8_lossy(&output.stderr));
    }
    let bytes = fs::read(&proof)?;
    // Keep the exact optimized proof beside the original proof in the loader
    // cache for code/ABI attribution. Intermediate compiler files are rebuildable.
    fs::write(args.output.with_extension("frozen.proof.o"), &bytes)?;
    fs::remove_dir_all(&prefix).with_context(|| format!("remove {}", prefix.display()))?;
    Ok(Some(bytes))
}

#[cfg(test)]
mod tests {
    use super::*;

    // Detect loss of the frontend IR at proof extraction and frozen values
    // arriving too late to eliminate conditional external calls. Mutable
    // globals must keep their own executable reference in either case.
    #[test]
    fn frozen_scalar_reemission_keeps_live_globals_and_actual_proof_abi() -> Result<()> {
        let here = PathBuf::from(env!("CARGO_MANIFEST_DIR"));
        let root = here.join("../../../..");
        let dir = here.join(format!("target/frozen-ir-test-{}", std::process::id()));
        fs::create_dir_all(&dir)?;
        let source = dir.join("input.c");
        let native = dir.join("input.o");
        let proof = dir.join("input.proof.o");
        let linker = here.join("target/release/native-link");
        fs::write(&source, "const volatile int option=0; volatile long live; extern long selected(void); long entry(void *ctx) { return live + (option ? selected() : 23); }")?;
        let status = Command::new("clang-18").args(["-O3", "-fPIC", "-fembed-bitcode=all", "-c"])
            .arg(&source).arg("-o").arg(&native).status()?;
        assert!(status.success());
        let status = Command::new(&linker).arg("--input").arg(&native)
            .args(["--symbol", "entry", "--mode", "proof", "--output"]).arg(&proof).status()?;
        assert!(status.success());
        let original = fs::read(&native)?;
        let original = object::File::parse(&*original)?;
        let bytes = fs::read(&proof)?;
        let elf = object::File::parse(&*bytes)?;
        assert_eq!(elf.section_by_name(".llvmbc").unwrap().data()?,
            original.section_by_name(".llvmbc").unwrap().data()?);
        let mut args = Args { input: proof, symbol: "entry".into(), output: dir.join("out.bin"),
            output_relocs: None, output_map_patches: None, output_abi: None,
            link_plan: None, show: false, preserve_entry_abi: false, mode: LinkMode::Kernel };
        let compiler = root.join("vendor/build/native-bpf/x86/stage/kprog-perf-context-lto");
        assert!(specialize(&args, &elf, &HashMap::new(), &compiler, &linker)?.is_none());
        for value in [0u8, 1] {
            args.output = dir.join(format!("out-{value}.bin"));
            let values = HashMap::from([("option".to_string(), vec![value, 0, 0, 0])]);
            let bytes = specialize(&args, &elf, &values, &compiler, &linker)?.unwrap();
            let specialized = object::File::parse(&*bytes)?;
            let undefined: Vec<_> = specialized.symbols().filter(|s| s.is_undefined())
                .map(|s| s.name().map(str::to_string)).collect::<std::result::Result<_, _>>()?;
            assert_eq!(undefined.iter().any(|n| n == "selected"), value != 0);
            assert!(undefined.iter().any(|n| n == "live"));
            assert!(!undefined.iter().any(|n| n == "option"));
            assert!(read_proof_abi(&specialized)?.is_some());
            assert!(specialized.section_by_name(".llvmbc").is_none());
        }
        Ok(())
    }
}
