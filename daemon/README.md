# bpfrejit-daemon

`bpfrejit-daemon` is the userspace front end for BpfReJIT v2, written in Rust.
It scans live kernel BPF programs for optimization sites and can apply
bytecode rewrites via `BPF_PROG_REJIT`.

**Zero libbpf dependency** -- all kernel interaction is via raw BPF syscalls.

## Build

```bash
cd daemon
cargo build --release
# run unit tests
cargo test
```

The binary is produced at `daemon/target/release/bpfrejit-daemon`.

## Subcommands

### `enumerate` -- list all live BPF programs with optimization sites

```bash
sudo bpfrejit-daemon enumerate
```

### `rewrite <prog_id>` -- dry-run rewrite (print result, do not apply)

```bash
sudo bpfrejit-daemon rewrite 42
```

### `apply <prog_id>` -- rewrite and apply via BPF_PROG_REJIT

```bash
sudo bpfrejit-daemon apply 42
```

### `apply-all` -- rewrite and apply all live programs

```bash
sudo bpfrejit-daemon apply-all
```

### `profile <prog_id>` -- poll runtime BPF stats

```bash
sudo sysctl kernel.bpf_stats_enabled=1
sudo bpfrejit-daemon profile 42 --interval-ms 1000 --samples 5
```

## Supported Transforms

| Pass | Family | Status | Description |
|------|--------|--------|-------------|
| `wide_mem` | WIDE_MEM | Applied | Merges byte-ladder loads (2/4/8-byte LE recompose) into a single wide `LDX_MEM`. No kinsn required. |
| `rotate` | ROTATE | Applied | Replaces shift+OR rotate patterns with `bpf_rotate64()` kfunc calls; JIT inlines as `RORX`. Requires kfunc BTF ID. |
| `cond_select` | COND_SELECT | Detection-only | Identifies JCC+MOV diamond patterns that could use `bpf_select64()` (CMOV). Reports sites in diagnostics; no bytecode change. |
| `branch_flip` | BRANCH_FLIP | Applied (PGO-gated) | Inverts a biased conditional branch and swaps then/else bodies so the hot path becomes fall-through. Requires `BranchProfile` annotation. |
| `spectre_mitigation` | SPECTRE_MITIGATION | Applied | Inserts load fences or masking sequences after indirect loads in security-sensitive programs. Category: Security. |

## Pass Framework

The daemon uses an LLVM-style pass pipeline defined in `pass.rs`:

- **`BpfProgram`** -- linear instruction stream (`Vec<BpfInsn>`) plus per-instruction `InsnAnnotation` (branch-target flags, PGO profile, verifier register state) and program metadata (`ProgMeta`).
- **`BpfPass` trait** -- each transform implements `name()`, `category()`, `required_analyses()`, and `run(&mut BpfProgram, &mut AnalysisCache, &PassContext)`. Returns a `PassResult` describing sites applied/skipped.
- **`Analysis` trait + `AnalysisCache`** -- read-only analyses produce typed, cached results indexed by `TypeId`. The cache is invalidated after any transform that sets `PassResult::changed = true`.
- **`PassManager`** -- executes passes in registration order, checks `PolicyConfig` (enabled/disabled pass lists), triggers required analyses, and accumulates a `PipelineResult`.
- **`PassContext`** -- invariant per-pipeline context: `KfuncRegistry` (BTF IDs for inline kfuncs), `PlatformCapabilities` (BMI1/2, CMOV, MOVBE, RORX), and `PolicyConfig`.

The default pipeline is built by `passes::build_default_pipeline()` and runs: `wide_mem` → `rotate` → `cond_select` → `branch_flip` → `spectre_mitigation`.

## Layout

```
daemon/
  Cargo.toml
  src/
    main.rs           # CLI entry point (clap); subcommand dispatch
    bpf.rs            # BPF syscall wrappers (zero libbpf)
    insn.rs           # BPF instruction encoding/decoding
    pass.rs           # Pass framework: BpfPass, Analysis, AnalysisCache, PassManager
    analysis.rs       # Concrete analyses: BranchTargetAnalysis, CFGAnalysis, LivenessAnalysis, PGOAnalysis
    passes.rs         # Concrete passes: WideMemPass, RotatePass, CondSelectPass, BranchFlipPass, SpectreMitigationPass
    matcher.rs        # Low-level pattern scanning (WIDE_MEM sites)
    rewriter.rs       # Bytecode rewrite + branch fixup (used by WideMemPass)
    emit.rs           # Per-transform instruction emission helpers
    verifier_log.rs   # Verifier log parser (for register state extraction)
    profiler.rs       # BPF runtime stats polling (bpf_stats_enabled)
```

## Dependencies

- `clap` -- CLI argument parsing
- `libc` -- raw syscall interface
- `anyhow` / `thiserror` -- error handling

No libbpf, no yaml-cpp, no C++ dependencies.
