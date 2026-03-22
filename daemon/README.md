# bpfrejit-daemon

`bpfrejit-daemon` is the userspace front end for BpfReJIT v2, written in Rust.
It scans live kernel BPF programs for optimization sites and can apply
bytecode rewrites via `BPF_PROG_REJIT`.

**Zero libbpf dependency** -- all kernel interaction is via raw BPF syscalls.

## Architecture Overview

The daemon implements an LLVM-style pass pipeline that:
1. Fetches original BPF bytecode from live kernel programs
2. Runs a sequence of analysis and transformation passes
3. Applies the rewritten bytecode via `BPF_PROG_REJIT` (re-verification + JIT)

Three key layers:
- **Analysis layer**: read-only analyses (branch targets, CFG, liveness) that produce typed, cached results
- **Transform layer**: optimization passes that rewrite the instruction stream
- **Syscall layer**: raw BPF syscall wrappers for program enumeration, info retrieval, and REJIT

## Build

```bash
cd daemon
cargo build --release
# run unit tests
cargo test
```

The binary is produced at `daemon/target/release/bpfrejit-daemon`.

## Runtime Modes

### One-shot: `enumerate`, `rewrite`, `apply`, `apply-all`

Single-invocation commands for scanning, dry-run rewriting, or applying optimizations.

```bash
sudo bpfrejit-daemon enumerate          # list programs + optimization sites
sudo bpfrejit-daemon rewrite 42         # dry-run rewrite (print result)
sudo bpfrejit-daemon apply 42           # rewrite + apply via REJIT
sudo bpfrejit-daemon apply-all          # apply to all live programs
```

### Daemon: `watch`

Polls for newly-loaded BPF programs at a configurable interval and applies
rewrites via the PassManager pipeline. Tracks already-optimized program IDs to
avoid redundant work. Exits cleanly on SIGTERM/SIGINT.

```bash
sudo bpfrejit-daemon watch                  # default 5-second polling
sudo bpfrejit-daemon watch --interval 10    # 10-second polling
sudo bpfrejit-daemon watch --once           # one scan round then exit
```

### Server: `serve`

Persistent Unix socket server mode. The daemon starts once, builds the
KfuncRegistry and PassManager, then listens for JSON requests. This avoids
the fork/exec overhead of one-shot invocations.

```bash
sudo bpfrejit-daemon serve                          # default /var/run/bpfrejit.sock
sudo bpfrejit-daemon serve --socket /tmp/rejit.sock # custom path
```

**JSON request/response protocol** (newline-delimited JSON over Unix socket):

```json
// Optimize a single program
{"cmd": "optimize", "prog_id": 42}
// Response: {"status": "ok", "applied": true}

// Optimize all live programs
{"cmd": "optimize-all"}
// Response: {"status": "ok", "total": 100, "applied": 5, "errors": 0}

// Health check
{"cmd": "status"}
// Response: {"status": "ok", "version": "0.1.0"}
```

### Profiling: `profile`

Polls runtime BPF stats (`run_cnt`, `run_time_ns`) for a single program.

```bash
sudo sysctl kernel.bpf_stats_enabled=1
sudo bpfrejit-daemon profile 42 --interval-ms 1000 --samples 5
```

## Pass Framework

The daemon uses an LLVM-style pass pipeline defined in `pass.rs`.

- **`BpfProgram`**: linear instruction stream (`Vec<BpfInsn>`) plus per-insn
  annotations (PGO branch profile) and program metadata.
- **`Analysis` trait + `AnalysisCache`**: read-only analyses produce typed,
  cached results indexed by `TypeId`. Cache is invalidated after any transform
  that sets `PassResult::changed = true`.
- **`BpfPass` trait**: each transform implements `name()`, `category()`,
  `required_analyses()`, and `run()`. Returns a `PassResult` with sites
  applied/skipped and diagnostics.
- **`PassManager`**: executes passes in registration order, checks policy
  (enabled/disabled pass lists), triggers required analyses, and accumulates
  a `PipelineResult`.
- **`PassContext`**: invariant per-pipeline context: `KfuncRegistry` (BTF IDs
  for inline kfuncs), `PlatformCapabilities`, and `PolicyConfig`.

Default pipeline: `wide_mem` -> `rotate` -> `cond_select` -> `branch_flip`.

## Supported Transforms

### `wide_mem` (WideMemPass)

Merges byte-ladder loads (2/4/8-byte LE recompose patterns) into a single
wide `LDX_MEM` instruction. No kinsn/kfunc required.

**Pattern**: sequence of `LDX_B` + `LSH` + `OR` forming a little-endian
multi-byte load. Supported widths: 2, 4, 8 bytes.

**Correctness**: branch target analysis ensures no external jumps into the
pattern interior. Liveness analysis ensures the scratch register is dead
after the site.

### `rotate` (RotatePass)

Replaces shift+OR rotate patterns with `bpf_rotate64()` kfunc calls.
JIT inlines the kfunc as a `RORX` instruction on x86.

**Pattern**: `MOV tmp, dst` ; `RSH dst, 64-S` ; `LSH tmp, S` ; `OR dst, tmp`
(or the LSH-first variant). Requires provenance verification: the matcher
scans backwards to confirm `tmp` is a copy of `dst`. Also checks that `tmp`
is dead after the site (live-out check).

**Requires**: `bpf_rotate64` kfunc available (module loaded).

### `cond_select` (CondSelectPass)

Replaces JCC+MOV diamond patterns with `bpf_select64()` kfunc calls
(lowered to CMOV by the JIT).

**Pattern A** (4-insn diamond only):
`Jcc +2` ; `MOV dst, false_val` ; `JA +1` ; `MOV dst, true_val`

Only handles simple zero-test conditions (`JNE reg, 0` / `JEQ reg, 0`).
Uses swap-safe parameter marshalling to avoid register aliasing when
source registers overlap with kfunc argument registers (r1/r2/r3).

**Requires**: `bpf_select64` kfunc available.

### `branch_flip` (BranchFlipPass)

PGO-guided reordering of if/else bodies so the hot path becomes
fall-through.

**Pattern**: true if/else diamond:
`Jcc +N` ; `[then: N-1 insns]` ; `JA +M` ; `[else: M insns]`

**PGO-only**: this pass only fires when `BranchProfile` annotation data
shows the taken path exceeds the bias threshold (default 70%). Without
profiler data, the pass skips all sites. No heuristic fallback.

### `spectre_mitigation` (SpectreMitigationPass)

Inserts NOP (`JA +0`) barriers after conditional branches as speculation
barrier placeholders. NOT in the default pipeline -- must be explicitly
enabled.

**Note**: current implementation inserts `JA +0` (NOP), which is a
placeholder. It does not provide actual speculation barrier semantics.
This pass is categorized as Security but should be treated as an
instrumentation/debug pass until real barrier lowering is implemented.

## kfunc Discovery

The daemon auto-discovers available kinsn kfuncs by scanning
`/sys/kernel/btf/<module>`. For each known kfunc (`bpf_rotate64`,
`bpf_select64`, `bpf_extract64`), it:

1. Checks if the module BTF file exists
2. Parses the BTF blob to find the `BTF_KIND_FUNC` type ID
3. Opens an FD to the module BTF for REJIT's `fd_array`

BTF kind constants are synced from `vendor/linux-framework/include/uapi/linux/btf.h`
and verified by a sync test (`test_btf_kind_constants_match_kernel`).

When a pass emits a kfunc call, it records the module FD in
`BpfProgram.required_module_fds`. The apply path constructs the appropriate
`fd_array` for `BPF_PROG_REJIT`.

## Profiler

The `profiler.rs` module provides BPF runtime stats polling backed by
`bpf_prog_info.run_cnt` / `run_time_ns`. The `profile` subcommand uses
this to compute delta statistics.

Branch-level PGO data is represented by `BranchProfile` (taken/not-taken
counts) in the per-instruction annotation. Currently, this data must be
injected programmatically (e.g., from instrumentation or sampling).
`branch_flip` reads this annotation to make flip decisions.

## CLI Reference

```
bpfrejit-daemon [--passes <pass1,pass2,...>] <COMMAND>

Commands:
  enumerate                List all live BPF programs with optimization sites
  rewrite <PROG_ID>        Dry-run rewrite (print result)
  apply <PROG_ID>          Rewrite and apply via BPF_PROG_REJIT
  apply-all                Apply to all live programs
  watch [--interval N] [--once]  Daemon mode: poll and apply
  serve [--socket PATH]    Unix socket server mode
  profile <PROG_ID> [--interval-ms N] [--samples N]  Poll runtime stats
```

## Layout

```
daemon/
  Cargo.toml
  src/
    main.rs              # CLI entry point (clap); all subcommands + serve server
    bpf.rs               # BPF syscall wrappers (zero libbpf)
    insn.rs              # BPF instruction encoding/decoding
    pass.rs              # Pass framework: BpfPass, Analysis, AnalysisCache, PassManager
    passes/
      mod.rs             # build_default_pipeline(); re-exports; fixup_branches_inline
      wide_mem.rs        # WideMemPass -- byte-ladder load merging
      rotate.rs          # RotatePass -- shift+OR -> bpf_rotate64() (with provenance check)
      cond_select.rs     # CondSelectPass -- JCC+MOV diamond -> bpf_select64() (swap-safe)
      branch_flip.rs     # BranchFlipPass -- PGO-only hot-path fall-through
      spectre.rs         # SpectreMitigationPass -- NOP placeholder barriers
    analysis/
      mod.rs             # re-exports
      branch_target.rs   # BranchTargetAnalysis
      cfg.rs             # CFGAnalysis
      liveness.rs        # LivenessAnalysis (r0-r5 clobbered on call)
    kfunc_discovery.rs   # Auto-discover kfuncs from /sys/kernel/btf/ (correct BTF kinds)
    verifier_log.rs      # Verifier log parser (not yet wired into pipeline)
    profiler.rs          # BPF runtime stats polling
```

## Dependencies

- `clap` -- CLI argument parsing
- `libc` -- raw syscall interface
- `anyhow` / `thiserror` -- error handling
- `serde` / `serde_json` -- JSON serialization (serve mode)

No libbpf, no yaml-cpp, no C++ dependencies.
